/*
 * Decompiled from: ETHGTIS45Resources_en.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001000 at 10001000

undefined4 FUN_10001000(void)

{
  return 1;
}



// Function: __CRT_INIT@12 at 10001008

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __CRT_INIT@12
   
   Library: Visual Studio 2010 Release */

undefined4 __CRT_INIT_12(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  _ptiddata _Ptd;
  code *pcVar2;
  DWORD DVar3;
  undefined4 uVar4;
  _ptiddata p_Var5;
  
  if (param_2 == 1) {
    iVar1 = __heap_init();
    if (iVar1 != 0) {
      iVar1 = __mtinit();
      if (iVar1 != 0) {
        __RTC_Initialize();
        DAT_100098d8 = GetCommandLineA();
        DAT_10008b24 = ___crtGetEnvironmentStringsA();
        iVar1 = __ioinit();
        if (-1 < iVar1) {
          iVar1 = __setargv();
          if (((-1 < iVar1) && (iVar1 = __setenvp(), -1 < iVar1)) &&
             (iVar1 = __cinit(0), iVar1 == 0)) {
            DAT_10008b20 = DAT_10008b20 + 1;
            return 1;
          }
          __ioterm();
        }
        __mtterm();
      }
      __heap_term();
    }
  }
  else if (param_2 == 0) {
    if (0 < DAT_10008b20) {
      DAT_10008b20 = DAT_10008b20 + -1;
      if (DAT_10008b74 == 0) {
        __cexit();
      }
      if (param_3 == 0) {
        __ioterm();
        __mtterm();
        __heap_term();
      }
      FUN_100010e1();
      return 1;
    }
  }
  else {
    if (param_2 != 2) {
      if (param_2 != 3) {
        return 1;
      }
      __freeptd((_ptiddata)0x0);
      return 1;
    }
    ___set_flsgetvalue();
    _Ptd = (_ptiddata)__calloc_crt(1,0x214);
    if (_Ptd != (_ptiddata)0x0) {
      uVar4 = DAT_10008000;
      p_Var5 = _Ptd;
      pcVar2 = (code *)DecodePointer(DAT_10008b3c);
      iVar1 = (*pcVar2)(uVar4,p_Var5);
      if (iVar1 != 0) {
        __initptd(_Ptd,(pthreadlocinfo)0x0);
        DVar3 = GetCurrentThreadId();
        _Ptd->_tid = DVar3;
        _Ptd->_thandle = 0xffffffff;
        return 1;
      }
      _free(_Ptd);
    }
  }
  return 0;
}



// Function: FUN_100010e1 at 100010e1

void FUN_100010e1(void)

{
  int unaff_EBP;
  int unaff_EDI;
  
  if ((*(int *)(unaff_EBP + 0x10) == unaff_EDI) && (DAT_10008000 != -1)) {
    __mtterm();
  }
  return;
}



// Function: ___DllMainCRTStartup at 1000116c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x100011fe) */
/* WARNING: Removing unreachable block (ram,0x100011ab) */
/* WARNING: Removing unreachable block (ram,0x1000122b) */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int local_20;
  
  if (((param_2 == 0) && (DAT_10008b20 == 0)) ||
     (((param_2 == 1 || (param_2 == 2)) &&
      (iVar1 = __CRT_INIT_12(param_3,param_2,param_1), iVar1 == 0)))) {
    local_20 = 0;
  }
  else {
    local_20 = FUN_10001000();
    if ((param_2 == 1) && (local_20 == 0)) {
      FUN_10001000();
      __CRT_INIT_12(param_3,0,param_1);
    }
    if (((param_2 == 0) || (param_2 == 3)) &&
       (iVar1 = __CRT_INIT_12(param_3,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  return local_20;
}



// Function: entry at 10001262

void entry(undefined4 param_1,int param_2,int param_3)

{
  if (param_2 == 1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: FUN_10001285 at 10001285

void FUN_10001285(void)

{
  EncodePointer((PVOID)0x0);
  return;
}



// Function: ___set_flsgetvalue at 10001297

/* Library Function - Single Match
    ___set_flsgetvalue
   
   Library: Visual Studio 2010 Release */

LPVOID ___set_flsgetvalue(void)

{
  LPVOID lpTlsValue;
  
  lpTlsValue = TlsGetValue(DAT_10008004);
  if (lpTlsValue == (LPVOID)0x0) {
    lpTlsValue = DecodePointer(DAT_10008b38);
    TlsSetValue(DAT_10008004,lpTlsValue);
  }
  return lpTlsValue;
}



// Function: __mtterm at 100012cb

/* Library Function - Single Match
    __mtterm
   
   Library: Visual Studio 2010 Release */

void __cdecl __mtterm(void)

{
  code *pcVar1;
  int iVar2;
  
  if (DAT_10008000 != -1) {
    iVar2 = DAT_10008000;
    pcVar1 = (code *)DecodePointer(DAT_10008b40);
    (*pcVar1)(iVar2);
    DAT_10008000 = -1;
  }
  if (DAT_10008004 != 0xffffffff) {
    TlsFree(DAT_10008004);
    DAT_10008004 = 0xffffffff;
  }
  __mtdeletelocks();
  return;
}



// Function: __initptd at 10001308

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __initptd
   
   Library: Visual Studio 2010 Release */

void __cdecl __initptd(_ptiddata _Ptd,pthreadlocinfo _Locale)

{
  GetModuleHandleW(L"KERNEL32.DLL");
  _Ptd->_pxcptacttab = &DAT_10006188;
  _Ptd->_terrno = 0;
  _Ptd->_holdrand = 1;
  _Ptd->_ownlocale = 1;
  *(undefined1 *)((_Ptd->_setloc_data)._cachein + 8) = 0x43;
  *(undefined1 *)((int)(_Ptd->_setloc_data)._cachein + 0x93) = 0x43;
  _Ptd->ptmbcinfo = (pthreadmbcinfo)&DAT_100083c0;
  __lock(0xd);
  InterlockedIncrement(&_Ptd->ptmbcinfo->refcount);
  FUN_100013aa();
  __lock(0xc);
  _Ptd->ptlocinfo = _Locale;
  if (_Locale == (pthreadlocinfo)0x0) {
    _Ptd->ptlocinfo = (pthreadlocinfo)PTR_DAT_100083b8;
  }
  ___addlocaleref(&_Ptd->ptlocinfo->refcount);
  FUN_100013b3();
  return;
}



// Function: FUN_100013aa at 100013aa

void FUN_100013aa(void)

{
  FUN_100026c5(0xd);
  return;
}



// Function: FUN_100013b3 at 100013b3

void FUN_100013b3(void)

{
  FUN_100026c5(0xc);
  return;
}



// Function: __getptd_noexit at 100013bc

/* Library Function - Single Match
    __getptd_noexit
   
   Library: Visual Studio 2010 Release */

_ptiddata __cdecl __getptd_noexit(void)

{
  DWORD dwErrCode;
  code *pcVar1;
  _ptiddata _Ptd;
  int iVar2;
  DWORD DVar3;
  undefined4 uVar4;
  _ptiddata p_Var5;
  
  dwErrCode = GetLastError();
  uVar4 = DAT_10008000;
  pcVar1 = (code *)___set_flsgetvalue();
  _Ptd = (_ptiddata)(*pcVar1)(uVar4);
  if (_Ptd == (_ptiddata)0x0) {
    _Ptd = (_ptiddata)__calloc_crt(1,0x214);
    if (_Ptd != (_ptiddata)0x0) {
      uVar4 = DAT_10008000;
      p_Var5 = _Ptd;
      pcVar1 = (code *)DecodePointer(DAT_10008b3c);
      iVar2 = (*pcVar1)(uVar4,p_Var5);
      if (iVar2 == 0) {
        _free(_Ptd);
        _Ptd = (_ptiddata)0x0;
      }
      else {
        __initptd(_Ptd,(pthreadlocinfo)0x0);
        DVar3 = GetCurrentThreadId();
        _Ptd->_thandle = 0xffffffff;
        _Ptd->_tid = DVar3;
      }
    }
  }
  SetLastError(dwErrCode);
  return _Ptd;
}



// Function: __getptd at 10001435

/* Library Function - Single Match
    __getptd
   
   Library: Visual Studio 2010 Release */

_ptiddata __cdecl __getptd(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd_noexit();
  if (p_Var1 == (_ptiddata)0x0) {
    __amsg_exit(0x10);
  }
  return p_Var1;
}



// Function: __freefls@4 at 1000144f

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __freefls@4
   
   Library: Visual Studio 2010 Release */

void __freefls_4(void *param_1)

{
  LONG *pLVar1;
  LONG LVar2;
  
  if (param_1 != (void *)0x0) {
    if (*(void **)((int)param_1 + 0x24) != (void *)0x0) {
      _free(*(void **)((int)param_1 + 0x24));
    }
    if (*(void **)((int)param_1 + 0x2c) != (void *)0x0) {
      _free(*(void **)((int)param_1 + 0x2c));
    }
    if (*(void **)((int)param_1 + 0x34) != (void *)0x0) {
      _free(*(void **)((int)param_1 + 0x34));
    }
    if (*(void **)((int)param_1 + 0x3c) != (void *)0x0) {
      _free(*(void **)((int)param_1 + 0x3c));
    }
    if (*(void **)((int)param_1 + 0x40) != (void *)0x0) {
      _free(*(void **)((int)param_1 + 0x40));
    }
    if (*(void **)((int)param_1 + 0x44) != (void *)0x0) {
      _free(*(void **)((int)param_1 + 0x44));
    }
    if (*(void **)((int)param_1 + 0x48) != (void *)0x0) {
      _free(*(void **)((int)param_1 + 0x48));
    }
    if (*(undefined **)((int)param_1 + 0x5c) != &DAT_10006188) {
      _free(*(undefined **)((int)param_1 + 0x5c));
    }
    __lock(0xd);
    pLVar1 = *(LONG **)((int)param_1 + 0x68);
    if (pLVar1 != (LONG *)0x0) {
      LVar2 = InterlockedDecrement(pLVar1);
      if ((LVar2 == 0) && (pLVar1 != (LONG *)&DAT_100083c0)) {
        _free(pLVar1);
      }
    }
    FUN_10001569();
    __lock(0xc);
    pLVar1 = *(LONG **)((int)param_1 + 0x6c);
    if (pLVar1 != (LONG *)0x0) {
      ___removelocaleref(pLVar1);
      if (((pLVar1 != (LONG *)PTR_DAT_100083b8) && (pLVar1 != (LONG *)&DAT_100082e0)) &&
         (*pLVar1 == 0)) {
        ___freetlocinfo(pLVar1);
      }
    }
    FUN_10001575();
    _free(param_1);
  }
  return;
}



// Function: FUN_10001569 at 10001569

void FUN_10001569(void)

{
  FUN_100026c5(0xd);
  return;
}



// Function: FUN_10001575 at 10001575

void FUN_10001575(void)

{
  FUN_100026c5(0xc);
  return;
}



// Function: __freeptd at 1000157e

/* Library Function - Single Match
    __freeptd
   
   Library: Visual Studio 2010 Release */

void __cdecl __freeptd(_ptiddata _Ptd)

{
  LPVOID pvVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (DAT_10008000 != -1) {
    if ((_Ptd == (_ptiddata)0x0) && (pvVar1 = TlsGetValue(DAT_10008004), pvVar1 != (LPVOID)0x0)) {
      iVar3 = DAT_10008000;
      pcVar2 = (code *)TlsGetValue(DAT_10008004);
      _Ptd = (_ptiddata)(*pcVar2)(iVar3);
    }
    uVar4 = 0;
    iVar3 = DAT_10008000;
    pcVar2 = (code *)DecodePointer(DAT_10008b3c);
    (*pcVar2)(iVar3,uVar4);
    __freefls_4(_Ptd);
  }
  if (DAT_10008004 != 0xffffffff) {
    TlsSetValue(DAT_10008004,(LPVOID)0x0);
  }
  return;
}



// Function: __mtinit at 100015ec

/* Library Function - Single Match
    __mtinit
   
   Library: Visual Studio 2010 Release */

int __cdecl __mtinit(void)

{
  HMODULE hModule;
  BOOL BVar1;
  int iVar2;
  code *pcVar3;
  _ptiddata _Ptd;
  DWORD DVar4;
  code *pcVar5;
  _ptiddata p_Var6;
  
  hModule = GetModuleHandleW(L"KERNEL32.DLL");
  if (hModule == (HMODULE)0x0) {
    __mtterm();
    return 0;
  }
  DAT_10008b34 = GetProcAddress(hModule,"FlsAlloc");
  DAT_10008b38 = GetProcAddress(hModule,"FlsGetValue");
  DAT_10008b3c = GetProcAddress(hModule,"FlsSetValue");
  DAT_10008b40 = GetProcAddress(hModule,"FlsFree");
  if ((((DAT_10008b34 == (FARPROC)0x0) || (DAT_10008b38 == (FARPROC)0x0)) ||
      (DAT_10008b3c == (FARPROC)0x0)) || (DAT_10008b40 == (FARPROC)0x0)) {
    DAT_10008b38 = TlsGetValue_exref;
    DAT_10008b34 = (FARPROC)&LAB_1000128e;
    DAT_10008b3c = TlsSetValue_exref;
    DAT_10008b40 = TlsFree_exref;
  }
  DAT_10008004 = TlsAlloc();
  if ((DAT_10008004 != 0xffffffff) && (BVar1 = TlsSetValue(DAT_10008004,DAT_10008b38), BVar1 != 0))
  {
    __init_pointers();
    DAT_10008b34 = (FARPROC)EncodePointer(DAT_10008b34);
    DAT_10008b38 = (FARPROC)EncodePointer(DAT_10008b38);
    DAT_10008b3c = (FARPROC)EncodePointer(DAT_10008b3c);
    DAT_10008b40 = (FARPROC)EncodePointer(DAT_10008b40);
    iVar2 = __mtinitlocks();
    if (iVar2 != 0) {
      pcVar5 = __freefls_4;
      pcVar3 = (code *)DecodePointer(DAT_10008b34);
      DAT_10008000 = (*pcVar3)(pcVar5);
      if ((DAT_10008000 != -1) && (_Ptd = (_ptiddata)__calloc_crt(1,0x214), _Ptd != (_ptiddata)0x0))
      {
        iVar2 = DAT_10008000;
        p_Var6 = _Ptd;
        pcVar3 = (code *)DecodePointer(DAT_10008b3c);
        iVar2 = (*pcVar3)(iVar2,p_Var6);
        if (iVar2 != 0) {
          __initptd(_Ptd,(pthreadlocinfo)0x0);
          DVar4 = GetCurrentThreadId();
          _Ptd->_thandle = 0xffffffff;
          _Ptd->_tid = DVar4;
          return 1;
        }
      }
    }
    __mtterm();
  }
  return 0;
}



// Function: _free at 10001767

/* Library Function - Single Match
    _free
   
   Library: Visual Studio 2010 Release */

void __cdecl _free(void *_Memory)

{
  BOOL BVar1;
  int *piVar2;
  DWORD DVar3;
  int iVar4;
  
  if (_Memory != (void *)0x0) {
    BVar1 = HeapFree(DAT_10008c88,0,_Memory);
    if (BVar1 == 0) {
      piVar2 = __errno();
      DVar3 = GetLastError();
      iVar4 = __get_errno_from_oserr(DVar3);
      *piVar2 = iVar4;
    }
  }
  return;
}



// Function: __malloc_crt at 100017a1

/* Library Function - Single Match
    __malloc_crt
   
   Library: Visual Studio 2010 Release */

void * __cdecl __malloc_crt(size_t _Size)

{
  void *pvVar1;
  uint dwMilliseconds;
  
  dwMilliseconds = 0;
  while( true ) {
    pvVar1 = _malloc(_Size);
    if (pvVar1 != (void *)0x0) {
      return pvVar1;
    }
    if (DAT_10008b44 == 0) break;
    Sleep(dwMilliseconds);
    dwMilliseconds = dwMilliseconds + 1000;
    if (DAT_10008b44 < dwMilliseconds) {
      dwMilliseconds = 0xffffffff;
    }
    if (dwMilliseconds == 0xffffffff) {
      return (void *)0x0;
    }
  }
  return (void *)0x0;
}



// Function: __calloc_crt at 100017e6

/* Library Function - Single Match
    __calloc_crt
   
   Library: Visual Studio 2010 Release */

void * __cdecl __calloc_crt(size_t _Count,size_t _Size)

{
  LPVOID pvVar1;
  uint dwMilliseconds;
  
  dwMilliseconds = 0;
  while( true ) {
    pvVar1 = __calloc_impl(_Count,_Size,(undefined4 *)0x0);
    if (pvVar1 != (LPVOID)0x0) {
      return pvVar1;
    }
    if (DAT_10008b44 == 0) break;
    Sleep(dwMilliseconds);
    dwMilliseconds = dwMilliseconds + 1000;
    if (DAT_10008b44 < dwMilliseconds) {
      dwMilliseconds = 0xffffffff;
    }
    if (dwMilliseconds == 0xffffffff) {
      return (void *)0x0;
    }
  }
  return (void *)0x0;
}



// Function: __realloc_crt at 10001832

/* Library Function - Single Match
    __realloc_crt
   
   Library: Visual Studio 2010 Release */

void * __cdecl __realloc_crt(void *_Ptr,size_t _NewSize)

{
  void *pvVar1;
  uint dwMilliseconds;
  
  dwMilliseconds = 0;
  do {
    pvVar1 = _realloc(_Ptr,_NewSize);
    if (pvVar1 != (void *)0x0) {
      return pvVar1;
    }
    if (_NewSize == 0) {
      return (void *)0x0;
    }
    if (DAT_10008b44 == 0) {
      return (void *)0x0;
    }
    Sleep(dwMilliseconds);
    dwMilliseconds = dwMilliseconds + 1000;
    if (DAT_10008b44 < dwMilliseconds) {
      dwMilliseconds = 0xffffffff;
    }
  } while (dwMilliseconds != 0xffffffff);
  return (void *)0x0;
}



// Function: ___crtCorExitProcess at 10001880

/* Library Function - Single Match
    ___crtCorExitProcess
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

void __cdecl ___crtCorExitProcess(int param_1)

{
  HMODULE hModule;
  FARPROC pFVar1;
  
  hModule = GetModuleHandleW(L"mscoree.dll");
  if (hModule != (HMODULE)0x0) {
    pFVar1 = GetProcAddress(hModule,"CorExitProcess");
    if (pFVar1 != (FARPROC)0x0) {
      (*pFVar1)(param_1);
    }
  }
  return;
}



// Function: ___crtExitProcess at 100018ab

/* Library Function - Single Match
    ___crtExitProcess
   
   Library: Visual Studio 2010 Release */

void __cdecl ___crtExitProcess(int param_1)

{
  ___crtCorExitProcess(param_1);
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}



// Function: FUN_100018c3 at 100018c3

void FUN_100018c3(void)

{
  __lock(8);
  return;
}



// Function: FUN_100018cc at 100018cc

void FUN_100018cc(void)

{
  FUN_100026c5(8);
  return;
}



// Function: __init_pointers at 100018d5

/* Library Function - Single Match
    __init_pointers
   
   Library: Visual Studio 2010 Release */

void __cdecl __init_pointers(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_10001285();
  FUN_10003894(uVar1);
  FUN_100036fa(uVar1);
  FUN_100036eb(uVar1);
  FUN_100036dc(uVar1);
  __initp_misc_winsig(uVar1);
  FUN_100034c6();
  return;
}



// Function: __initterm_e at 10001908

/* Library Function - Single Match
    __initterm_e
   
   Library: Visual Studio 2010 Release */

void __cdecl __initterm_e(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  while ((param_1 < param_2 && (iVar1 == 0))) {
    if ((code *)*param_1 != (code *)0x0) {
      iVar1 = (*(code *)*param_1)();
    }
    param_1 = param_1 + 1;
  }
  return;
}



// Function: __cinit at 1000192c

/* Library Function - Single Match
    __cinit
   
   Library: Visual Studio 2010 Release */

int __cdecl __cinit(int param_1)

{
  BOOL BVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((DAT_100098d0 != (code *)0x0) &&
     (BVar1 = __IsNonwritableInCurrentImage((PBYTE)&DAT_100098d0), BVar1 != 0)) {
    (*DAT_100098d0)(param_1);
  }
  __initp_misc_cfltcvt_tab();
  iVar2 = __initterm_e((undefined4 *)&DAT_100060e8,(undefined4 *)&DAT_100060f8);
  if (iVar2 == 0) {
    _atexit((_func_4879 *)&LAB_100021cc);
    puVar3 = &DAT_100060e0;
    do {
      if ((code *)*puVar3 != (code *)0x0) {
        (*(code *)*puVar3)();
      }
      puVar3 = puVar3 + 1;
    } while (puVar3 < &DAT_100060e4);
    if ((DAT_100098d4 != (code *)0x0) &&
       (BVar1 = __IsNonwritableInCurrentImage((PBYTE)&DAT_100098d4), BVar1 != 0)) {
      (*DAT_100098d4)(0,2,0);
    }
    iVar2 = 0;
  }
  return iVar2;
}



// Function: doexit at 100019c3

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x10001af4) */
/* Library Function - Single Match
    _doexit
   
   Library: Visual Studio 2010 Release */

void __cdecl doexit(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  int *piVar5;
  int *piVar6;
  int *local_34;
  int *local_2c;
  int *local_28;
  undefined4 *local_24;
  undefined4 *local_20;
  
  __lock(8);
  if (DAT_10008b78 != 1) {
    DAT_10008b74 = 1;
    DAT_10008b70 = (undefined1)param_3;
    if (param_2 == 0) {
      piVar1 = (int *)DecodePointer(DAT_100098c8);
      if (piVar1 != (int *)0x0) {
        piVar2 = (int *)DecodePointer(DAT_100098c4);
        local_34 = piVar1;
        local_2c = piVar2;
        local_28 = piVar1;
        while (piVar2 = piVar2 + -1, piVar1 <= piVar2) {
          iVar3 = FUN_10001285();
          if (*piVar2 != iVar3) {
            if (piVar2 < piVar1) break;
            pcVar4 = (code *)DecodePointer((PVOID)*piVar2);
            iVar3 = FUN_10001285();
            *piVar2 = iVar3;
            (*pcVar4)();
            piVar5 = (int *)DecodePointer(DAT_100098c8);
            piVar6 = (int *)DecodePointer(DAT_100098c4);
            if ((local_28 != piVar5) || (piVar1 = local_34, local_2c != piVar6)) {
              piVar1 = piVar5;
              piVar2 = piVar6;
              local_34 = piVar5;
              local_2c = piVar6;
              local_28 = piVar5;
            }
          }
        }
      }
      for (local_20 = &DAT_100060fc; local_20 < &DAT_10006100; local_20 = local_20 + 1) {
        if ((code *)*local_20 != (code *)0x0) {
          (*(code *)*local_20)();
        }
      }
    }
    for (local_24 = &DAT_10006104; local_24 < &DAT_10006108; local_24 = local_24 + 1) {
      if ((code *)*local_24 != (code *)0x0) {
        (*(code *)*local_24)();
      }
    }
  }
  FUN_10001aee();
  if (param_3 == 0) {
    DAT_10008b78 = 1;
    FUN_100026c5(8);
    ___crtExitProcess(param_1);
    return;
  }
  return;
}



// Function: FUN_10001aee at 10001aee

void FUN_10001aee(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + 0x10) != 0) {
    FUN_100026c5(8);
  }
  return;
}



// Function: __exit at 10001b03

/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 2010 Release */

void __cdecl __exit(int _Code)

{
  doexit(_Code,1,0);
  return;
}



// Function: __cexit at 10001b19

/* Library Function - Single Match
    __cexit
   
   Library: Visual Studio 2010 Release */

void __cdecl __cexit(void)

{
  doexit(0,0,1);
  return;
}



// Function: __amsg_exit at 10001b28

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 2010 Release */

void __cdecl __amsg_exit(int param_1)

{
  __FF_MSGBANNER();
  __NMSG_WRITE(param_1);
                    /* WARNING: Subroutine does not return */
  __exit(0xff);
}



// Function: __ioinit at 10001b46

/* Library Function - Single Match
    __ioinit
   
   Library: Visual Studio 2010 Release */

int __cdecl __ioinit(void)

{
  void *pvVar1;
  int iVar2;
  DWORD DVar3;
  BOOL BVar4;
  HANDLE pvVar5;
  UINT UVar6;
  UINT UVar7;
  undefined4 *puVar8;
  int *piVar9;
  uint uVar10;
  _STARTUPINFOW local_50;
  byte *local_c;
  UINT *local_8;
  
  GetStartupInfoW(&local_50);
  pvVar1 = __calloc_crt(0x20,0x40);
  if (pvVar1 == (void *)0x0) {
    iVar2 = -1;
  }
  else {
    DAT_100097a0 = 0x20;
    DAT_100097c0 = pvVar1;
    if (pvVar1 < (void *)((int)pvVar1 + 0x800U)) {
      iVar2 = (int)pvVar1 + 5;
      do {
        *(undefined4 *)(iVar2 + -5) = 0xffffffff;
        *(undefined2 *)(iVar2 + -1) = 0xa00;
        *(undefined4 *)(iVar2 + 3) = 0;
        *(undefined2 *)(iVar2 + 0x1f) = 0xa00;
        *(undefined1 *)(iVar2 + 0x21) = 10;
        *(undefined4 *)(iVar2 + 0x33) = 0;
        *(undefined1 *)(iVar2 + 0x2f) = 0;
        uVar10 = iVar2 + 0x3b;
        iVar2 = iVar2 + 0x40;
      } while (uVar10 < (int)DAT_100097c0 + 0x800U);
    }
    if ((local_50.cbReserved2 != 0) && ((UINT *)local_50.lpReserved2 != (UINT *)0x0)) {
      UVar6 = *(UINT *)local_50.lpReserved2;
      local_8 = (UINT *)((int)local_50.lpReserved2 + 4);
      local_c = (byte *)((int)local_8 + UVar6);
      if (0x7ff < (int)UVar6) {
        UVar6 = 0x800;
      }
      UVar7 = UVar6;
      if ((int)DAT_100097a0 < (int)UVar6) {
        piVar9 = &DAT_100097c4;
        do {
          pvVar1 = __calloc_crt(0x20,0x40);
          UVar7 = DAT_100097a0;
          if (pvVar1 == (void *)0x0) break;
          DAT_100097a0 = DAT_100097a0 + 0x20;
          *piVar9 = (int)pvVar1;
          if (pvVar1 < (void *)((int)pvVar1 + 0x800U)) {
            iVar2 = (int)pvVar1 + 5;
            do {
              *(undefined4 *)(iVar2 + -5) = 0xffffffff;
              *(undefined4 *)(iVar2 + 3) = 0;
              *(byte *)(iVar2 + 0x1f) = *(byte *)(iVar2 + 0x1f) & 0x80;
              *(undefined4 *)(iVar2 + 0x33) = 0;
              *(undefined2 *)(iVar2 + -1) = 0xa00;
              *(undefined2 *)(iVar2 + 0x20) = 0xa0a;
              *(undefined1 *)(iVar2 + 0x2f) = 0;
              uVar10 = iVar2 + 0x3b;
              iVar2 = iVar2 + 0x40;
            } while (uVar10 < *piVar9 + 0x800U);
          }
          piVar9 = piVar9 + 1;
          UVar7 = UVar6;
        } while ((int)DAT_100097a0 < (int)UVar6);
      }
      uVar10 = 0;
      if (0 < (int)UVar7) {
        do {
          pvVar5 = *(HANDLE *)local_c;
          if ((((pvVar5 != (HANDLE)0xffffffff) && (pvVar5 != (HANDLE)0xfffffffe)) &&
              ((*local_8 & 1) != 0)) &&
             (((*local_8 & 8) != 0 || (DVar3 = GetFileType(pvVar5), DVar3 != 0)))) {
            puVar8 = (undefined4 *)((uVar10 & 0x1f) * 0x40 + (int)(&DAT_100097c0)[(int)uVar10 >> 5])
            ;
            *puVar8 = *(undefined4 *)local_c;
            *(byte *)(puVar8 + 1) = (byte)*local_8;
            BVar4 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(puVar8 + 3),4000);
            if (BVar4 == 0) {
              return -1;
            }
            puVar8[2] = puVar8[2] + 1;
          }
          local_c = local_c + 4;
          uVar10 = uVar10 + 1;
          local_8 = (UINT *)((int)local_8 + 1);
        } while ((int)uVar10 < (int)UVar7);
      }
    }
    iVar2 = 0;
    do {
      piVar9 = (int *)(iVar2 * 0x40 + (int)DAT_100097c0);
      if ((*piVar9 == -1) || (*piVar9 == -2)) {
        *(undefined1 *)(piVar9 + 1) = 0x81;
        if (iVar2 == 0) {
          DVar3 = 0xfffffff6;
        }
        else {
          DVar3 = 0xfffffff5 - (iVar2 != 1);
        }
        pvVar5 = GetStdHandle(DVar3);
        if (((pvVar5 == (HANDLE)0xffffffff) || (pvVar5 == (HANDLE)0x0)) ||
           (DVar3 = GetFileType(pvVar5), DVar3 == 0)) {
          *(byte *)(piVar9 + 1) = *(byte *)(piVar9 + 1) | 0x40;
          *piVar9 = -2;
        }
        else {
          *piVar9 = (int)pvVar5;
          if ((DVar3 & 0xff) == 2) {
            *(byte *)(piVar9 + 1) = *(byte *)(piVar9 + 1) | 0x40;
          }
          else if ((DVar3 & 0xff) == 3) {
            *(byte *)(piVar9 + 1) = *(byte *)(piVar9 + 1) | 8;
          }
          BVar4 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(piVar9 + 3),4000);
          if (BVar4 == 0) {
            return -1;
          }
          piVar9[2] = piVar9[2] + 1;
        }
      }
      else {
        *(byte *)(piVar9 + 1) = *(byte *)(piVar9 + 1) | 0x80;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
    SetHandleCount(DAT_100097a0);
    iVar2 = 0;
  }
  return iVar2;
}



// Function: __ioterm at 10001d8b

/* Library Function - Single Match
    __ioterm
   
   Library: Visual Studio 2010 Release */

void __cdecl __ioterm(void)

{
  uint uVar1;
  LPCRITICAL_SECTION p_Var2;
  LPCRITICAL_SECTION lpCriticalSection;
  uint *puVar3;
  
  puVar3 = &DAT_100097c0;
  do {
    uVar1 = *puVar3;
    if (uVar1 != 0) {
      if (uVar1 < uVar1 + 0x800) {
        lpCriticalSection = (LPCRITICAL_SECTION)(uVar1 + 0xc);
        do {
          if (lpCriticalSection[-1].SpinCount != 0) {
            DeleteCriticalSection(lpCriticalSection);
          }
          p_Var2 = lpCriticalSection + 2;
          lpCriticalSection = (LPCRITICAL_SECTION)&lpCriticalSection[2].LockSemaphore;
        } while (&p_Var2->LockCount < (undefined1 *)(*puVar3 + 0x800));
      }
      _free((void *)*puVar3);
      *puVar3 = 0;
    }
    puVar3 = puVar3 + 1;
  } while ((int)puVar3 < 0x100098c0);
  return;
}



// Function: __setenvp at 10001dde

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __setenvp
   
   Library: Visual Studio 2010 Release */

int __cdecl __setenvp(void)

{
  undefined4 *puVar1;
  size_t sVar2;
  char *_Dst;
  errno_t eVar3;
  char *pcVar4;
  int iVar5;
  
  if (DAT_100098cc == 0) {
    ___initmbctable();
  }
  iVar5 = 0;
  pcVar4 = DAT_10008b24;
  if (DAT_10008b24 != (char *)0x0) {
    for (; *pcVar4 != '\0'; pcVar4 = pcVar4 + sVar2 + 1) {
      if (*pcVar4 != '=') {
        iVar5 = iVar5 + 1;
      }
      sVar2 = _strlen(pcVar4);
    }
    puVar1 = (undefined4 *)__calloc_crt(iVar5 + 1,4);
    pcVar4 = DAT_10008b24;
    DAT_10008b58 = puVar1;
    if (puVar1 != (undefined4 *)0x0) {
      do {
        if (*pcVar4 == '\0') {
          _free(DAT_10008b24);
          DAT_10008b24 = (char *)0x0;
          *puVar1 = 0;
          _DAT_100098c0 = 1;
          return 0;
        }
        sVar2 = _strlen(pcVar4);
        sVar2 = sVar2 + 1;
        if (*pcVar4 != '=') {
          _Dst = (char *)__calloc_crt(sVar2,1);
          *puVar1 = _Dst;
          if (_Dst == (char *)0x0) {
            _free(DAT_10008b58);
            DAT_10008b58 = (undefined4 *)0x0;
            return -1;
          }
          eVar3 = _strcpy_s(_Dst,sVar2,pcVar4);
          if (eVar3 != 0) {
                    /* WARNING: Subroutine does not return */
            __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
          }
          puVar1 = puVar1 + 1;
        }
        pcVar4 = pcVar4 + sVar2;
      } while( true );
    }
  }
  return -1;
}



// Function: parse_cmdline at 10001eba

/* Library Function - Single Match
    _parse_cmdline
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

void __cdecl parse_cmdline(undefined4 *param_1,byte *param_2,int *param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  byte *in_EDX;
  byte *pbVar5;
  byte bVar6;
  byte *pbVar7;
  byte *pbVar8;
  int *unaff_EDI;
  
  *unaff_EDI = 0;
  *param_3 = 1;
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = param_2;
    param_1 = param_1 + 1;
  }
  bVar2 = false;
  pbVar5 = param_2;
  do {
    if (*in_EDX == 0x22) {
      bVar2 = !bVar2;
      bVar6 = 0x22;
      pbVar7 = in_EDX + 1;
    }
    else {
      *unaff_EDI = *unaff_EDI + 1;
      if (pbVar5 != (byte *)0x0) {
        *pbVar5 = *in_EDX;
        param_2 = pbVar5 + 1;
      }
      bVar6 = *in_EDX;
      pbVar7 = in_EDX + 1;
      iVar3 = __ismbblead((uint)bVar6);
      if (iVar3 != 0) {
        *unaff_EDI = *unaff_EDI + 1;
        if (param_2 != (byte *)0x0) {
          *param_2 = *pbVar7;
          param_2 = param_2 + 1;
        }
        pbVar7 = in_EDX + 2;
      }
      pbVar5 = param_2;
      if (bVar6 == 0) {
        pbVar7 = pbVar7 + -1;
        goto LAB_10001f4e;
      }
    }
    in_EDX = pbVar7;
  } while ((bVar2) || ((bVar6 != 0x20 && (bVar6 != 9))));
  if (pbVar5 != (byte *)0x0) {
    pbVar5[-1] = 0;
  }
LAB_10001f4e:
  bVar2 = false;
  while (*pbVar7 != 0) {
    for (; (*pbVar7 == 0x20 || (*pbVar7 == 9)); pbVar7 = pbVar7 + 1) {
    }
    if (*pbVar7 == 0) break;
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = pbVar5;
      param_1 = param_1 + 1;
    }
    *param_3 = *param_3 + 1;
    while( true ) {
      bVar1 = true;
      uVar4 = 0;
      for (; *pbVar7 == 0x5c; pbVar7 = pbVar7 + 1) {
        uVar4 = uVar4 + 1;
      }
      if (*pbVar7 == 0x22) {
        pbVar8 = pbVar7;
        if (((uVar4 & 1) == 0) && ((!bVar2 || (pbVar8 = pbVar7 + 1, *pbVar8 != 0x22)))) {
          bVar1 = false;
          bVar2 = !bVar2;
          pbVar8 = pbVar7;
        }
        uVar4 = uVar4 >> 1;
        pbVar7 = pbVar8;
      }
      while (uVar4 != 0) {
        uVar4 = uVar4 - 1;
        if (pbVar5 != (byte *)0x0) {
          *pbVar5 = 0x5c;
          pbVar5 = pbVar5 + 1;
        }
        *unaff_EDI = *unaff_EDI + 1;
        param_2 = pbVar5;
      }
      bVar6 = *pbVar7;
      if ((bVar6 == 0) || ((!bVar2 && ((bVar6 == 0x20 || (bVar6 == 9)))))) break;
      if (bVar1) {
        if (pbVar5 == (byte *)0x0) {
          iVar3 = __ismbblead((int)(char)bVar6);
          if (iVar3 != 0) {
            pbVar7 = pbVar7 + 1;
            *unaff_EDI = *unaff_EDI + 1;
          }
        }
        else {
          iVar3 = __ismbblead((int)(char)bVar6);
          if (iVar3 != 0) {
            *param_2 = *pbVar7;
            pbVar7 = pbVar7 + 1;
            *unaff_EDI = *unaff_EDI + 1;
            param_2 = param_2 + 1;
          }
          *param_2 = *pbVar7;
          param_2 = param_2 + 1;
        }
        *unaff_EDI = *unaff_EDI + 1;
        pbVar5 = param_2;
      }
      pbVar7 = pbVar7 + 1;
    }
    if (pbVar5 != (byte *)0x0) {
      *pbVar5 = 0;
      pbVar5 = pbVar5 + 1;
      param_2 = pbVar5;
    }
    *unaff_EDI = *unaff_EDI + 1;
  }
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
  }
  *param_3 = *param_3 + 1;
  return;
}



// Function: __setargv at 10002054

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __setargv
   
   Library: Visual Studio 2010 Release */

int __cdecl __setargv(void)

{
  uint _Size;
  uint uVar1;
  undefined4 *puVar2;
  uint local_10;
  uint local_c;
  char *local_8;
  
  if (DAT_100098cc == 0) {
    ___initmbctable();
  }
  DAT_10008c84 = 0;
  GetModuleFileNameA((HMODULE)0x0,&DAT_10008b80,0x104);
  _DAT_10008b68 = &DAT_10008b80;
  if ((DAT_100098d8 == (char *)0x0) || (local_8 = DAT_100098d8, *DAT_100098d8 == '\0')) {
    local_8 = &DAT_10008b80;
  }
  parse_cmdline((undefined4 *)0x0,(byte *)0x0,(int *)&local_c);
  uVar1 = local_c;
  if ((local_c < 0x3fffffff) && (local_10 != 0xffffffff)) {
    _Size = local_c * 4 + local_10;
    if ((local_10 <= _Size) &&
       (puVar2 = (undefined4 *)__malloc_crt(_Size), puVar2 != (undefined4 *)0x0)) {
      parse_cmdline(puVar2,(byte *)(puVar2 + uVar1),(int *)&local_c);
      _DAT_10008b4c = local_c - 1;
      _DAT_10008b50 = puVar2;
      return 0;
    }
  }
  return -1;
}



// Function: ___crtGetEnvironmentStringsA at 1000210f

/* Library Function - Single Match
    ___crtGetEnvironmentStringsA
   
   Library: Visual Studio 2010 Release */

LPVOID __cdecl ___crtGetEnvironmentStringsA(void)

{
  WCHAR WVar1;
  LPWCH lpWideCharStr;
  WCHAR *pWVar2;
  int iVar4;
  size_t _Size;
  LPSTR local_8;
  WCHAR *pWVar3;
  
  lpWideCharStr = GetEnvironmentStringsW();
  if (lpWideCharStr == (LPWCH)0x0) {
    local_8 = (LPSTR)0x0;
  }
  else {
    WVar1 = *lpWideCharStr;
    pWVar2 = lpWideCharStr;
    while (WVar1 != L'\0') {
      do {
        pWVar3 = pWVar2;
        pWVar2 = pWVar3 + 1;
      } while (*pWVar2 != L'\0');
      pWVar2 = pWVar3 + 2;
      WVar1 = *pWVar2;
    }
    iVar4 = ((int)pWVar2 - (int)lpWideCharStr >> 1) + 1;
    _Size = WideCharToMultiByte(0,0,lpWideCharStr,iVar4,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if ((_Size == 0) || (local_8 = (LPSTR)__malloc_crt(_Size), local_8 == (LPSTR)0x0)) {
      FreeEnvironmentStringsW(lpWideCharStr);
      local_8 = (LPSTR)0x0;
    }
    else {
      iVar4 = WideCharToMultiByte(0,0,lpWideCharStr,iVar4,local_8,_Size,(LPCSTR)0x0,(LPBOOL)0x0);
      if (iVar4 == 0) {
        _free(local_8);
        local_8 = (LPSTR)0x0;
      }
      FreeEnvironmentStringsW(lpWideCharStr);
    }
  }
  return local_8;
}



// Function: __RTC_Initialize at 100021a6

/* WARNING: Removing unreachable block (ram,0x100021ba) */
/* WARNING: Removing unreachable block (ram,0x100021c0) */
/* WARNING: Removing unreachable block (ram,0x100021c2) */
/* Library Function - Single Match
    __RTC_Initialize
   
   Library: Visual Studio 2010 Release */

void __RTC_Initialize(void)

{
  return;
}



// Function: __heap_init at 100021f2

/* Library Function - Single Match
    __heap_init
   
   Library: Visual Studio 2010 Release */

int __cdecl __heap_init(void)

{
  DAT_10008c88 = HeapCreate(0,0x1000,0);
  return (uint)(DAT_10008c88 != (HANDLE)0x0);
}



// Function: __heap_term at 10002210

/* Library Function - Single Match
    __heap_term
   
   Library: Visual Studio 2010 Release */

void __cdecl __heap_term(void)

{
  HeapDestroy(DAT_10008c88);
  DAT_10008c88 = (HANDLE)0x0;
  return;
}



// Function: __SEH_prolog4 at 10002230

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10008a80 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 10002275

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



// Function: __except_handler4 at 10002290

/* Library Function - Single Match
    __except_handler4
   
   Library: Visual Studio 2010 Release */

undefined4 __cdecl __except_handler4(PEXCEPTION_RECORD param_1,PVOID param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  BOOL BVar3;
  PVOID pvVar4;
  int *piVar5;
  PEXCEPTION_RECORD local_1c;
  undefined4 local_18;
  uint *local_14;
  undefined4 local_10;
  PVOID local_c;
  char local_5;
  
  piVar5 = (int *)(*(uint *)((int)param_2 + 8) ^ DAT_10008a80);
  local_5 = '\0';
  local_10 = 1;
  iVar1 = (int)param_2 + 0x10;
  if (*piVar5 != -2) {
    __security_check_cookie(piVar5[1] + iVar1 ^ *(uint *)(*piVar5 + iVar1));
  }
  __security_check_cookie(piVar5[3] + iVar1 ^ *(uint *)(piVar5[2] + iVar1));
  pvVar4 = param_2;
  if ((param_1->ExceptionFlags & 0x66) == 0) {
    *(PEXCEPTION_RECORD **)((int)param_2 + -4) = &local_1c;
    pvVar4 = *(PVOID *)((int)param_2 + 0xc);
    local_1c = param_1;
    local_18 = param_3;
    if (pvVar4 == (PVOID)0xfffffffe) {
      return local_10;
    }
    do {
      local_14 = (uint *)(piVar5 + (int)pvVar4 * 3 + 4);
      local_c = (PVOID)*local_14;
      if ((undefined *)piVar5[(int)pvVar4 * 3 + 5] != (undefined *)0x0) {
        iVar2 = _EH4_CallFilterFunc((undefined *)piVar5[(int)pvVar4 * 3 + 5]);
        local_5 = '\x01';
        if (iVar2 < 0) {
          local_10 = 0;
          goto LAB_10002338;
        }
        if (0 < iVar2) {
          if (((param_1->ExceptionCode == 0xe06d7363) && (DAT_1000979c != (code *)0x0)) &&
             (BVar3 = __IsNonwritableInCurrentImage((PBYTE)&DAT_1000979c), BVar3 != 0)) {
            (*DAT_1000979c)(param_1,1);
          }
          _EH4_GlobalUnwind2(param_2,param_1);
          if (*(PVOID *)((int)param_2 + 0xc) != pvVar4) {
            _EH4_LocalUnwind((int)param_2,(uint)pvVar4,iVar1,&DAT_10008a80);
          }
          *(PVOID *)((int)param_2 + 0xc) = local_c;
          if (*piVar5 != -2) {
            __security_check_cookie(piVar5[1] + iVar1 ^ *(uint *)(*piVar5 + iVar1));
          }
          __security_check_cookie(piVar5[3] + iVar1 ^ *(uint *)(piVar5[2] + iVar1));
          _EH4_TransferToHandler((undefined *)local_14[2]);
          goto LAB_100023ff;
        }
      }
      pvVar4 = local_c;
    } while (local_c != (PVOID)0xfffffffe);
    if (local_5 == '\0') {
      return local_10;
    }
  }
  else {
LAB_100023ff:
    if (*(int *)((int)pvVar4 + 0xc) == -2) {
      return local_10;
    }
    _EH4_LocalUnwind((int)pvVar4,0xfffffffe,iVar1,&DAT_10008a80);
  }
LAB_10002338:
  if (*piVar5 != -2) {
    __security_check_cookie(piVar5[1] + iVar1 ^ *(uint *)(*piVar5 + iVar1));
  }
  __security_check_cookie(piVar5[3] + iVar1 ^ *(uint *)(piVar5[2] + iVar1));
  return local_10;
}



// Function: __XcptFilter at 1000241f

/* Library Function - Single Match
    __XcptFilter
   
   Library: Visual Studio 2010 Release */

int __cdecl __XcptFilter(ulong _ExceptionNum,_EXCEPTION_POINTERS *_ExceptionPtr)

{
  ulong *puVar1;
  code *pcVar2;
  void *pvVar3;
  ulong uVar4;
  _ptiddata p_Var5;
  ulong *puVar6;
  int iVar7;
  
  p_Var5 = __getptd_noexit();
  if (p_Var5 != (_ptiddata)0x0) {
    puVar1 = (ulong *)p_Var5->_pxcptacttab;
    puVar6 = puVar1;
    do {
      if (*puVar6 == _ExceptionNum) break;
      puVar6 = puVar6 + 3;
    } while (puVar6 < puVar1 + 0x24);
    if ((puVar1 + 0x24 <= puVar6) || (*puVar6 != _ExceptionNum)) {
      puVar6 = (ulong *)0x0;
    }
    if ((puVar6 == (ulong *)0x0) || (pcVar2 = (code *)puVar6[2], pcVar2 == (code *)0x0)) {
      p_Var5 = (_ptiddata)0x0;
    }
    else if (pcVar2 == (code *)0x5) {
      puVar6[2] = 0;
      p_Var5 = (_ptiddata)0x1;
    }
    else {
      if (pcVar2 != (code *)0x1) {
        pvVar3 = p_Var5->_tpxcptinfoptrs;
        p_Var5->_tpxcptinfoptrs = _ExceptionPtr;
        if (puVar6[1] == 8) {
          iVar7 = 0x24;
          do {
            *(undefined4 *)(iVar7 + 8 + (int)p_Var5->_pxcptacttab) = 0;
            iVar7 = iVar7 + 0xc;
          } while (iVar7 < 0x90);
          uVar4 = *puVar6;
          iVar7 = p_Var5->_tfpecode;
          if (uVar4 == 0xc000008e) {
            p_Var5->_tfpecode = 0x83;
          }
          else if (uVar4 == 0xc0000090) {
            p_Var5->_tfpecode = 0x81;
          }
          else if (uVar4 == 0xc0000091) {
            p_Var5->_tfpecode = 0x84;
          }
          else if (uVar4 == 0xc0000093) {
            p_Var5->_tfpecode = 0x85;
          }
          else if (uVar4 == 0xc000008d) {
            p_Var5->_tfpecode = 0x82;
          }
          else if (uVar4 == 0xc000008f) {
            p_Var5->_tfpecode = 0x86;
          }
          else if (uVar4 == 0xc0000092) {
            p_Var5->_tfpecode = 0x8a;
          }
          else if (uVar4 == 0xc00002b5) {
            p_Var5->_tfpecode = 0x8d;
          }
          else if (uVar4 == 0xc00002b4) {
            p_Var5->_tfpecode = 0x8e;
          }
          (*pcVar2)(8,p_Var5->_tfpecode);
          p_Var5->_tfpecode = iVar7;
        }
        else {
          puVar6[2] = 0;
          (*pcVar2)(puVar6[1]);
        }
        p_Var5->_tpxcptinfoptrs = pvVar3;
      }
      p_Var5 = (_ptiddata)0xffffffff;
    }
  }
  return (int)p_Var5;
}



// Function: ___CppXcptFilter at 10002569

/* Library Function - Single Match
    ___CppXcptFilter
   
   Library: Visual Studio 2010 Release */

int __cdecl ___CppXcptFilter(ulong _ExceptionNum,_EXCEPTION_POINTERS *_ExceptionPtr)

{
  int iVar1;
  
  if (_ExceptionNum == 0xe06d7363) {
    iVar1 = __XcptFilter(0xe06d7363,_ExceptionPtr);
    return iVar1;
  }
  return 0;
}



// Function: ___security_init_cookie at 10002589

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
  if ((DAT_10008a80 == 0xbb40e64e) || ((DAT_10008a80 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_10008a80 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_10008a80 == 0xbb40e64e) {
      DAT_10008a80 = 0xbb40e64f;
    }
    else if ((DAT_10008a80 & 0xffff0000) == 0) {
      DAT_10008a80 = DAT_10008a80 | (DAT_10008a80 | 0x4711) << 0x10;
    }
    DAT_10008a84 = ~DAT_10008a80;
  }
  else {
    DAT_10008a84 = ~DAT_10008a80;
  }
  return;
}



// Function: __mtinitlocks at 10002624

/* Library Function - Single Match
    __mtinitlocks
   
   Library: Visual Studio 2010 Release */

int __cdecl __mtinitlocks(void)

{
  BOOL BVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar2 = 0;
  puVar3 = &DAT_10008c90;
  do {
    if ((&DAT_10008054)[iVar2 * 2] == 1) {
      (&DAT_10008050)[iVar2 * 2] = puVar3;
      puVar3 = puVar3 + 0x18;
      BVar1 = InitializeCriticalSectionAndSpinCount
                        ((LPCRITICAL_SECTION)(&DAT_10008050)[iVar2 * 2],4000);
      if (BVar1 == 0) {
        (&DAT_10008050)[iVar2 * 2] = 0;
        return 0;
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x24);
  return 1;
}



// Function: __mtdeletelocks at 1000266e

/* Library Function - Single Match
    __mtdeletelocks
   
   Library: Visual Studio 2010 Release */

void __cdecl __mtdeletelocks(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *puVar1;
  
  puVar1 = &DAT_10008050;
  do {
    lpCriticalSection = (LPCRITICAL_SECTION)*puVar1;
    if ((lpCriticalSection != (LPCRITICAL_SECTION)0x0) && (puVar1[1] != 1)) {
      DeleteCriticalSection(lpCriticalSection);
      _free(lpCriticalSection);
      *puVar1 = 0;
    }
    puVar1 = puVar1 + 2;
  } while ((int)puVar1 < 0x10008170);
  puVar1 = &DAT_10008050;
  do {
    if (((LPCRITICAL_SECTION)*puVar1 != (LPCRITICAL_SECTION)0x0) && (puVar1[1] == 1)) {
      DeleteCriticalSection((LPCRITICAL_SECTION)*puVar1);
    }
    puVar1 = puVar1 + 2;
  } while ((int)puVar1 < 0x10008170);
  return;
}



// Function: FUN_100026c5 at 100026c5

void __cdecl FUN_100026c5(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(&DAT_10008050)[param_1 * 2]);
  return;
}



// Function: __mtinitlocknum at 100026dc

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __mtinitlocknum
   
   Library: Visual Studio 2010 Release */

int __cdecl __mtinitlocknum(int _LockNum)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  BOOL BVar2;
  int iVar3;
  int local_20;
  
  iVar3 = 1;
  local_20 = 1;
  if (DAT_10008c88 == 0) {
    __FF_MSGBANNER();
    __NMSG_WRITE(0x1e);
    ___crtExitProcess(0xff);
  }
  piVar1 = &DAT_10008050 + _LockNum * 2;
  if (*piVar1 == 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)__malloc_crt(0x18);
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      piVar1 = __errno();
      *piVar1 = 0xc;
      iVar3 = 0;
    }
    else {
      __lock(10);
      if (*piVar1 == 0) {
        BVar2 = InitializeCriticalSectionAndSpinCount(lpCriticalSection,4000);
        if (BVar2 == 0) {
          _free(lpCriticalSection);
          piVar1 = __errno();
          *piVar1 = 0xc;
          local_20 = 0;
        }
        else {
          *piVar1 = (int)lpCriticalSection;
        }
      }
      else {
        _free(lpCriticalSection);
      }
      FUN_10002795();
      iVar3 = local_20;
    }
  }
  return iVar3;
}



// Function: FUN_10002795 at 10002795

void FUN_10002795(void)

{
  FUN_100026c5(10);
  return;
}



// Function: __lock at 1000279e

/* Library Function - Single Match
    __lock
   
   Library: Visual Studio 2010 Release */

void __cdecl __lock(int _File)

{
  int iVar1;
  
  if ((&DAT_10008050)[_File * 2] == 0) {
    iVar1 = __mtinitlocknum(_File);
    if (iVar1 == 0) {
      __amsg_exit(0x11);
    }
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(&DAT_10008050)[_File * 2]);
  return;
}



// Function: ___addlocaleref at 100027d1

/* Library Function - Single Match
    ___addlocaleref
   
   Library: Visual Studio 2010 Release */

void __cdecl ___addlocaleref(LONG *param_1)

{
  LONG *pLVar1;
  LONG *pLVar2;
  
  pLVar1 = param_1;
  InterlockedIncrement(param_1);
  if ((LONG *)param_1[0x2c] != (LONG *)0x0) {
    InterlockedIncrement((LONG *)param_1[0x2c]);
  }
  if ((LONG *)param_1[0x2e] != (LONG *)0x0) {
    InterlockedIncrement((LONG *)param_1[0x2e]);
  }
  if ((LONG *)param_1[0x2d] != (LONG *)0x0) {
    InterlockedIncrement((LONG *)param_1[0x2d]);
  }
  if ((LONG *)param_1[0x30] != (LONG *)0x0) {
    InterlockedIncrement((LONG *)param_1[0x30]);
  }
  pLVar2 = param_1 + 0x14;
  param_1 = (LONG *)0x6;
  do {
    if (((undefined *)pLVar2[-2] != &DAT_10008170) && ((LONG *)*pLVar2 != (LONG *)0x0)) {
      InterlockedIncrement((LONG *)*pLVar2);
    }
    if ((pLVar2[-1] != 0) && ((LONG *)pLVar2[1] != (LONG *)0x0)) {
      InterlockedIncrement((LONG *)pLVar2[1]);
    }
    pLVar2 = pLVar2 + 4;
    param_1 = (LONG *)((int)param_1 + -1);
  } while (param_1 != (LONG *)0x0);
  InterlockedIncrement((LONG *)(pLVar1[0x35] + 0xb4));
  return;
}



// Function: ___removelocaleref at 10002860

/* Library Function - Single Match
    ___removelocaleref
   
   Library: Visual Studio 2010 Release */

LONG * __cdecl ___removelocaleref(LONG *param_1)

{
  LONG *pLVar1;
  LONG *pLVar2;
  
  pLVar1 = param_1;
  if (param_1 != (LONG *)0x0) {
    InterlockedDecrement(param_1);
    if ((LONG *)param_1[0x2c] != (LONG *)0x0) {
      InterlockedDecrement((LONG *)param_1[0x2c]);
    }
    if ((LONG *)param_1[0x2e] != (LONG *)0x0) {
      InterlockedDecrement((LONG *)param_1[0x2e]);
    }
    if ((LONG *)param_1[0x2d] != (LONG *)0x0) {
      InterlockedDecrement((LONG *)param_1[0x2d]);
    }
    if ((LONG *)param_1[0x30] != (LONG *)0x0) {
      InterlockedDecrement((LONG *)param_1[0x30]);
    }
    pLVar2 = param_1 + 0x14;
    param_1 = (LONG *)0x6;
    do {
      if (((undefined *)pLVar2[-2] != &DAT_10008170) && ((LONG *)*pLVar2 != (LONG *)0x0)) {
        InterlockedDecrement((LONG *)*pLVar2);
      }
      if ((pLVar2[-1] != 0) && ((LONG *)pLVar2[1] != (LONG *)0x0)) {
        InterlockedDecrement((LONG *)pLVar2[1]);
      }
      pLVar2 = pLVar2 + 4;
      param_1 = (LONG *)((int)param_1 + -1);
    } while (param_1 != (LONG *)0x0);
    InterlockedDecrement((LONG *)(pLVar1[0x35] + 0xb4));
  }
  return pLVar1;
}



// Function: ___freetlocinfo at 100028f9

/* Library Function - Single Match
    ___freetlocinfo
   
   Library: Visual Studio 2010 Release */

void __cdecl ___freetlocinfo(void *param_1)

{
  int *piVar1;
  undefined **ppuVar2;
  void *_Memory;
  undefined4 *puVar3;
  
  _Memory = param_1;
  if ((((*(undefined ***)((int)param_1 + 0xbc) != (undefined **)0x0) &&
       (*(undefined ***)((int)param_1 + 0xbc) != &PTR_DAT_10008a98)) &&
      (*(int **)((int)param_1 + 0xb0) != (int *)0x0)) && (**(int **)((int)param_1 + 0xb0) == 0)) {
    piVar1 = *(int **)((int)param_1 + 0xb8);
    if ((piVar1 != (int *)0x0) && (*piVar1 == 0)) {
      _free(piVar1);
      ___free_lconv_mon(*(int *)((int)param_1 + 0xbc));
    }
    piVar1 = *(int **)((int)param_1 + 0xb4);
    if ((piVar1 != (int *)0x0) && (*piVar1 == 0)) {
      _free(piVar1);
      ___free_lconv_num(*(undefined4 **)((int)param_1 + 0xbc));
    }
    _free(*(void **)((int)param_1 + 0xb0));
    _free(*(void **)((int)param_1 + 0xbc));
  }
  if ((*(int **)((int)param_1 + 0xc0) != (int *)0x0) && (**(int **)((int)param_1 + 0xc0) == 0)) {
    _free((void *)(*(int *)((int)param_1 + 0xc4) + -0xfe));
    _free((void *)(*(int *)((int)param_1 + 0xcc) + -0x80));
    _free((void *)(*(int *)((int)param_1 + 0xd0) + -0x80));
    _free(*(void **)((int)param_1 + 0xc0));
  }
  ppuVar2 = *(undefined ***)((int)param_1 + 0xd4);
  if ((ppuVar2 != &PTR_DAT_10008178) && (ppuVar2[0x2d] == (undefined *)0x0)) {
    ___free_lc_time(ppuVar2);
    _free(*(void **)((int)param_1 + 0xd4));
  }
  puVar3 = (undefined4 *)((int)param_1 + 0x50);
  param_1 = (void *)0x6;
  do {
    if ((((undefined *)puVar3[-2] != &DAT_10008170) &&
        (piVar1 = (int *)*puVar3, piVar1 != (int *)0x0)) && (*piVar1 == 0)) {
      _free(piVar1);
    }
    if (((puVar3[-1] != 0) && (piVar1 = (int *)puVar3[1], piVar1 != (int *)0x0)) && (*piVar1 == 0))
    {
      _free(piVar1);
    }
    puVar3 = puVar3 + 4;
    param_1 = (void *)((int)param_1 + -1);
  } while (param_1 != (void *)0x0);
  _free(_Memory);
  return;
}



// Function: __updatetlocinfoEx_nolock at 10002a44

/* Library Function - Single Match
    __updatetlocinfoEx_nolock
   
   Library: Visual Studio 2010 Release */

LONG * __cdecl __updatetlocinfoEx_nolock(undefined4 *param_1,LONG *param_2)

{
  LONG *pLVar1;
  
  if ((param_2 == (LONG *)0x0) || (param_1 == (undefined4 *)0x0)) {
    param_2 = (LONG *)0x0;
  }
  else {
    pLVar1 = (LONG *)*param_1;
    if (pLVar1 != param_2) {
      *param_1 = param_2;
      ___addlocaleref(param_2);
      if (((pLVar1 != (LONG *)0x0) && (___removelocaleref(pLVar1), *pLVar1 == 0)) &&
         (pLVar1 != (LONG *)&DAT_100082e0)) {
        ___freetlocinfo(pLVar1);
      }
    }
  }
  return param_2;
}



// Function: ___updatetlocinfo at 10002a91

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___updatetlocinfo
   
   Library: Visual Studio 2010 Release */

pthreadlocinfo __cdecl ___updatetlocinfo(void)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  
  p_Var1 = __getptd();
  if (((p_Var1->_ownlocale & DAT_10008aec) == 0) || (p_Var1->ptlocinfo == (pthreadlocinfo)0x0)) {
    __lock(0xc);
    ptVar2 = (pthreadlocinfo)&p_Var1->ptlocinfo;
    __updatetlocinfoEx_nolock((undefined4 *)ptVar2,(LONG *)PTR_DAT_100083b8);
    FUN_10002afe();
  }
  else {
    p_Var1 = __getptd();
    ptVar2 = p_Var1->ptlocinfo;
  }
  if (ptVar2 == (pthreadlocinfo)0x0) {
    __amsg_exit(0x20);
  }
  return ptVar2;
}



// Function: FUN_10002afe at 10002afe

void FUN_10002afe(void)

{
  FUN_100026c5(0xc);
  return;
}



// Function: CPtoLCID at 10002b0a

/* Library Function - Single Match
    int __cdecl CPtoLCID(int)
   
   Library: Visual Studio 2010 Release */

int __cdecl CPtoLCID(int param_1)

{
  int in_EAX;
  
  if (in_EAX == 0x3a4) {
    return 0x411;
  }
  if (in_EAX == 0x3a8) {
    return 0x804;
  }
  if (in_EAX == 0x3b5) {
    return 0x412;
  }
  if (in_EAX != 0x3b6) {
    return 0;
  }
  return 0x404;
}



// Function: setSBCS at 10002b39

/* Library Function - Single Match
    void __cdecl setSBCS(struct threadmbcinfostruct *)
   
   Library: Visual Studio 2010 Release */

void __cdecl setSBCS(threadmbcinfostruct *param_1)

{
  int in_EAX;
  undefined1 *puVar1;
  int iVar2;
  
  _memset((void *)(in_EAX + 0x1c),0,0x101);
  *(undefined4 *)(in_EAX + 4) = 0;
  *(undefined4 *)(in_EAX + 8) = 0;
  *(undefined4 *)(in_EAX + 0xc) = 0;
  *(undefined4 *)(in_EAX + 0x10) = 0;
  *(undefined4 *)(in_EAX + 0x14) = 0;
  *(undefined4 *)(in_EAX + 0x18) = 0;
  puVar1 = (undefined1 *)(in_EAX + 0x1c);
  iVar2 = 0x101;
  do {
    *puVar1 = puVar1[(int)&DAT_100083c0 - in_EAX];
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (undefined1 *)(in_EAX + 0x11d);
  iVar2 = 0x100;
  do {
    *puVar1 = puVar1[(int)&DAT_100083c0 - in_EAX];
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}



// Function: setSBUpLow at 10002b9d

/* Library Function - Single Match
    void __cdecl setSBUpLow(struct threadmbcinfostruct *)
   
   Library: Visual Studio 2010 Release */

void __cdecl setSBUpLow(threadmbcinfostruct *param_1)

{
  byte *pbVar1;
  char *pcVar2;
  BOOL BVar3;
  uint uVar4;
  CHAR CVar5;
  char cVar6;
  BYTE *pBVar7;
  int unaff_ESI;
  _cpinfo local_51c;
  WORD local_508 [256];
  CHAR local_308 [256];
  CHAR local_208 [256];
  CHAR local_108 [256];
  uint local_8;
  
  local_8 = DAT_10008a80 ^ (uint)&stack0xfffffffc;
  BVar3 = GetCPInfo(*(UINT *)(unaff_ESI + 4),&local_51c);
  if (BVar3 == 0) {
    uVar4 = 0;
    do {
      pcVar2 = (char *)(unaff_ESI + 0x11d + uVar4);
      if (pcVar2 + (-0x61 - (unaff_ESI + 0x11d)) + 0x20 < (char *)0x1a) {
        pbVar1 = (byte *)(unaff_ESI + 0x1d + uVar4);
        *pbVar1 = *pbVar1 | 0x10;
        cVar6 = (char)uVar4 + ' ';
LAB_10002d13:
        *pcVar2 = cVar6;
      }
      else {
        if (pcVar2 + (-0x61 - (unaff_ESI + 0x11d)) < (char *)0x1a) {
          pbVar1 = (byte *)(unaff_ESI + 0x1d + uVar4);
          *pbVar1 = *pbVar1 | 0x20;
          cVar6 = (char)uVar4 + -0x20;
          goto LAB_10002d13;
        }
        *pcVar2 = '\0';
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x100);
  }
  else {
    uVar4 = 0;
    do {
      local_108[uVar4] = (CHAR)uVar4;
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x100);
    local_108[0] = ' ';
    if (local_51c.LeadByte[0] != 0) {
      pBVar7 = local_51c.LeadByte + 1;
      do {
        uVar4 = (uint)local_51c.LeadByte[0];
        if (uVar4 <= *pBVar7) {
          _memset(local_108 + uVar4,0x20,(*pBVar7 - uVar4) + 1);
        }
        local_51c.LeadByte[0] = pBVar7[1];
        pBVar7 = pBVar7 + 2;
      } while (local_51c.LeadByte[0] != 0);
    }
    ___crtGetStringTypeA
              ((_locale_t)0x0,1,local_108,0x100,local_508,*(int *)(unaff_ESI + 4),
               *(BOOL *)(unaff_ESI + 0xc));
    ___crtLCMapStringA((_locale_t)0x0,*(LPCWSTR *)(unaff_ESI + 0xc),0x100,local_108,0x100,local_208,
                       0x100,*(int *)(unaff_ESI + 4),0);
    ___crtLCMapStringA((_locale_t)0x0,*(LPCWSTR *)(unaff_ESI + 0xc),0x200,local_108,0x100,local_308,
                       0x100,*(int *)(unaff_ESI + 4),0);
    uVar4 = 0;
    do {
      if ((local_508[uVar4] & 1) == 0) {
        if ((local_508[uVar4] & 2) != 0) {
          pbVar1 = (byte *)(unaff_ESI + 0x1d + uVar4);
          *pbVar1 = *pbVar1 | 0x20;
          CVar5 = local_308[uVar4];
          goto LAB_10002cb6;
        }
        *(undefined1 *)(unaff_ESI + 0x11d + uVar4) = 0;
      }
      else {
        pbVar1 = (byte *)(unaff_ESI + 0x1d + uVar4);
        *pbVar1 = *pbVar1 | 0x10;
        CVar5 = local_208[uVar4];
LAB_10002cb6:
        *(CHAR *)(unaff_ESI + 0x11d + uVar4) = CVar5;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x100);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: ___updatetmbcinfo at 10002d2d

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___updatetmbcinfo
   
   Library: Visual Studio 2010 Release */

pthreadmbcinfo __cdecl ___updatetmbcinfo(void)

{
  _ptiddata p_Var1;
  LONG LVar2;
  pthreadmbcinfo lpAddend;
  
  p_Var1 = __getptd();
  if (((p_Var1->_ownlocale & DAT_10008aec) == 0) || (p_Var1->ptlocinfo == (pthreadlocinfo)0x0)) {
    __lock(0xd);
    lpAddend = p_Var1->ptmbcinfo;
    if (lpAddend != (pthreadmbcinfo)PTR_DAT_100087e8) {
      if (lpAddend != (pthreadmbcinfo)0x0) {
        LVar2 = InterlockedDecrement(&lpAddend->refcount);
        if ((LVar2 == 0) && (lpAddend != (pthreadmbcinfo)&DAT_100083c0)) {
          _free(lpAddend);
        }
      }
      p_Var1->ptmbcinfo = (pthreadmbcinfo)PTR_DAT_100087e8;
      lpAddend = (pthreadmbcinfo)PTR_DAT_100087e8;
      InterlockedIncrement((LONG *)PTR_DAT_100087e8);
    }
    FUN_10002dc8();
  }
  else {
    lpAddend = p_Var1->ptmbcinfo;
  }
  if (lpAddend == (pthreadmbcinfo)0x0) {
    __amsg_exit(0x20);
  }
  return lpAddend;
}



// Function: FUN_10002dc8 at 10002dc8

void FUN_10002dc8(void)

{
  FUN_100026c5(0xd);
  return;
}



// Function: _LocaleUpdate at 10002dd1

/* Library Function - Single Match
    public: __thiscall _LocaleUpdate::_LocaleUpdate(struct localeinfo_struct *)
   
   Library: Visual Studio 2010 Release */

_LocaleUpdate * __thiscall
_LocaleUpdate::_LocaleUpdate(_LocaleUpdate *this,localeinfo_struct *param_1)

{
  uint *puVar1;
  _ptiddata p_Var2;
  pthreadlocinfo ptVar3;
  pthreadmbcinfo ptVar4;
  
  this[0xc] = (_LocaleUpdate)0x0;
  if (param_1 == (localeinfo_struct *)0x0) {
    p_Var2 = __getptd();
    *(_ptiddata *)(this + 8) = p_Var2;
    *(pthreadlocinfo *)this = p_Var2->ptlocinfo;
    *(pthreadmbcinfo *)(this + 4) = p_Var2->ptmbcinfo;
    if ((*(undefined **)this != PTR_DAT_100083b8) && ((p_Var2->_ownlocale & DAT_10008aec) == 0)) {
      ptVar3 = ___updatetlocinfo();
      *(pthreadlocinfo *)this = ptVar3;
    }
    if ((*(undefined **)(this + 4) != PTR_DAT_100087e8) &&
       ((*(uint *)(*(int *)(this + 8) + 0x70) & DAT_10008aec) == 0)) {
      ptVar4 = ___updatetmbcinfo();
      *(pthreadmbcinfo *)(this + 4) = ptVar4;
    }
    if ((*(byte *)(*(int *)(this + 8) + 0x70) & 2) == 0) {
      puVar1 = (uint *)(*(int *)(this + 8) + 0x70);
      *puVar1 = *puVar1 | 2;
      this[0xc] = (_LocaleUpdate)0x1;
    }
  }
  else {
    *(pthreadlocinfo *)this = param_1->locinfo;
    *(pthreadmbcinfo *)(this + 4) = param_1->mbcinfo;
  }
  return this;
}



// Function: getSystemCP at 10002e58

/* Library Function - Single Match
    int __cdecl getSystemCP(int)
   
   Library: Visual Studio 2010 Release */

int __cdecl getSystemCP(int param_1)

{
  UINT UVar1;
  int unaff_ESI;
  int local_14 [2];
  int local_c;
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)local_14,(localeinfo_struct *)0x0);
  DAT_10008de0 = 0;
  if (unaff_ESI == -2) {
    DAT_10008de0 = 1;
    UVar1 = GetOEMCP();
  }
  else if (unaff_ESI == -3) {
    DAT_10008de0 = 1;
    UVar1 = GetACP();
  }
  else {
    if (unaff_ESI != -4) {
      if (local_8 == '\0') {
        DAT_10008de0 = 0;
        return unaff_ESI;
      }
      *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
      return unaff_ESI;
    }
    UVar1 = *(UINT *)(local_14[0] + 4);
    DAT_10008de0 = 1;
  }
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return UVar1;
}



// Function: __setmbcp_nolock at 10002ed4

/* Library Function - Single Match
    __setmbcp_nolock
   
   Library: Visual Studio 2010 Release */

void __cdecl __setmbcp_nolock(undefined4 param_1,int param_2)

{
  BYTE *pBVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  BOOL BVar6;
  undefined2 *puVar7;
  byte *pbVar8;
  int extraout_ECX;
  undefined2 *puVar9;
  int iVar10;
  undefined4 extraout_EDX;
  BYTE *pBVar11;
  threadmbcinfostruct *unaff_EDI;
  uint local_24;
  byte *local_20;
  _cpinfo local_1c;
  uint local_8;
  
  local_8 = DAT_10008a80 ^ (uint)&stack0xfffffffc;
  uVar4 = getSystemCP((int)unaff_EDI);
  if (uVar4 != 0) {
    local_20 = (byte *)0x0;
    uVar5 = 0;
LAB_10002f12:
    if (*(uint *)((int)&DAT_100087f0 + uVar5) != uVar4) goto code_r0x10002f1e;
    _memset((void *)(param_2 + 0x1c),0,0x101);
    local_24 = 0;
    pbVar8 = &DAT_10008800 + (int)local_20 * 0x30;
    local_20 = pbVar8;
    do {
      for (; (*pbVar8 != 0 && (bVar3 = pbVar8[1], bVar3 != 0)); pbVar8 = pbVar8 + 2) {
        for (uVar5 = (uint)*pbVar8; uVar5 <= bVar3; uVar5 = uVar5 + 1) {
          pbVar2 = (byte *)(param_2 + 0x1d + uVar5);
          *pbVar2 = *pbVar2 | *(byte *)(local_24 + 0x100087ec);
          bVar3 = pbVar8[1];
        }
      }
      local_24 = local_24 + 1;
      pbVar8 = local_20 + 8;
      local_20 = pbVar8;
    } while (local_24 < 4);
    *(uint *)(param_2 + 4) = uVar4;
    *(undefined4 *)(param_2 + 8) = 1;
    iVar10 = CPtoLCID((int)unaff_EDI);
    *(int *)(param_2 + 0xc) = iVar10;
    puVar7 = (undefined2 *)(param_2 + 0x10);
    puVar9 = (undefined2 *)(&DAT_100087f4 + extraout_ECX);
    iVar10 = 6;
    do {
      *puVar7 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar7 = puVar7 + 1;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
    goto LAB_10003046;
  }
LAB_10002eff:
  setSBCS(unaff_EDI);
LAB_100030ae:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
code_r0x10002f1e:
  local_20 = (byte *)((int)local_20 + 1);
  uVar5 = uVar5 + 0x30;
  if (0xef < uVar5) goto code_r0x10002f2b;
  goto LAB_10002f12;
code_r0x10002f2b:
  if (((uVar4 == 65000) || (uVar4 == 0xfde9)) ||
     (BVar6 = IsValidCodePage(uVar4 & 0xffff), BVar6 == 0)) goto LAB_100030ae;
  BVar6 = GetCPInfo(uVar4,&local_1c);
  if (BVar6 != 0) {
    _memset((void *)(param_2 + 0x1c),0,0x101);
    *(uint *)(param_2 + 4) = uVar4;
    *(undefined4 *)(param_2 + 0xc) = 0;
    if (local_1c.MaxCharSize < 2) {
      *(undefined4 *)(param_2 + 8) = 0;
    }
    else {
      if (local_1c.LeadByte[0] != '\0') {
        pBVar11 = local_1c.LeadByte + 1;
        do {
          bVar3 = *pBVar11;
          if (bVar3 == 0) break;
          for (uVar4 = (uint)pBVar11[-1]; uVar4 <= bVar3; uVar4 = uVar4 + 1) {
            pbVar8 = (byte *)(param_2 + 0x1d + uVar4);
            *pbVar8 = *pbVar8 | 4;
          }
          pBVar1 = pBVar11 + 1;
          pBVar11 = pBVar11 + 2;
        } while (*pBVar1 != 0);
      }
      pbVar8 = (byte *)(param_2 + 0x1e);
      iVar10 = 0xfe;
      do {
        *pbVar8 = *pbVar8 | 8;
        pbVar8 = pbVar8 + 1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
      iVar10 = CPtoLCID((int)unaff_EDI);
      *(int *)(param_2 + 0xc) = iVar10;
      *(undefined4 *)(param_2 + 8) = extraout_EDX;
    }
    *(undefined4 *)(param_2 + 0x10) = 0;
    *(undefined4 *)(param_2 + 0x14) = 0;
    *(undefined4 *)(param_2 + 0x18) = 0;
LAB_10003046:
    setSBUpLow(unaff_EDI);
    goto LAB_100030ae;
  }
  if (DAT_10008de0 == 0) goto LAB_100030ae;
  goto LAB_10002eff;
}



// Function: __setmbcp at 100030bd

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __setmbcp
   
   Library: Visual Studio 2010 Release */

int __cdecl __setmbcp(int _CodePage)

{
  _ptiddata p_Var1;
  int iVar2;
  pthreadmbcinfo ptVar3;
  LONG LVar4;
  int *piVar5;
  int iVar6;
  pthreadmbcinfo ptVar7;
  pthreadmbcinfo ptVar8;
  int in_stack_ffffffc8;
  int local_24;
  
  local_24 = -1;
  p_Var1 = __getptd();
  ___updatetmbcinfo();
  ptVar3 = p_Var1->ptmbcinfo;
  iVar2 = getSystemCP(in_stack_ffffffc8);
  if (iVar2 == ptVar3->mbcodepage) {
    local_24 = 0;
  }
  else {
    ptVar3 = (pthreadmbcinfo)__malloc_crt(0x220);
    if (ptVar3 != (pthreadmbcinfo)0x0) {
      ptVar7 = p_Var1->ptmbcinfo;
      ptVar8 = ptVar3;
      for (iVar6 = 0x88; iVar6 != 0; iVar6 = iVar6 + -1) {
        ptVar8->refcount = ptVar7->refcount;
        ptVar7 = (pthreadmbcinfo)&ptVar7->mbcodepage;
        ptVar8 = (pthreadmbcinfo)&ptVar8->mbcodepage;
      }
      ptVar3->refcount = 0;
      local_24 = __setmbcp_nolock(iVar2,(int)ptVar3);
      if (local_24 == 0) {
        LVar4 = InterlockedDecrement(&p_Var1->ptmbcinfo->refcount);
        if ((LVar4 == 0) && (p_Var1->ptmbcinfo != (pthreadmbcinfo)&DAT_100083c0)) {
          _free(p_Var1->ptmbcinfo);
        }
        p_Var1->ptmbcinfo = ptVar3;
        InterlockedIncrement((LONG *)ptVar3);
        if (((p_Var1->_ownlocale & 2) == 0) && (((byte)DAT_10008aec & 1) == 0)) {
          __lock(0xd);
          _DAT_10008df0 = ptVar3->mbcodepage;
          _DAT_10008df4 = ptVar3->ismbcodepage;
          _DAT_10008df8 = *(undefined4 *)ptVar3->mbulinfo;
          for (iVar2 = 0; iVar2 < 5; iVar2 = iVar2 + 1) {
            (&DAT_10008de4)[iVar2] = ptVar3->mbulinfo[iVar2 + 2];
          }
          for (iVar2 = 0; iVar2 < 0x101; iVar2 = iVar2 + 1) {
            (&DAT_100085e0)[iVar2] = ptVar3->mbctype[iVar2 + 4];
          }
          for (iVar2 = 0; iVar2 < 0x100; iVar2 = iVar2 + 1) {
            (&DAT_100086e8)[iVar2] = ptVar3->mbcasemap[iVar2 + 4];
          }
          LVar4 = InterlockedDecrement((LONG *)PTR_DAT_100087e8);
          if ((LVar4 == 0) && (PTR_DAT_100087e8 != &DAT_100083c0)) {
            _free(PTR_DAT_100087e8);
          }
          PTR_DAT_100087e8 = (undefined *)ptVar3;
          InterlockedIncrement((LONG *)ptVar3);
          FUN_1000321e();
        }
      }
      else if (local_24 == -1) {
        if (ptVar3 != (pthreadmbcinfo)&DAT_100083c0) {
          _free(ptVar3);
        }
        piVar5 = __errno();
        *piVar5 = 0x16;
      }
    }
  }
  return local_24;
}



// Function: FUN_1000321e at 1000321e

void FUN_1000321e(void)

{
  FUN_100026c5(0xd);
  return;
}



// Function: ___initmbctable at 10003257

/* Library Function - Single Match
    ___initmbctable
   
   Library: Visual Studio 2010 Release */

undefined4 ___initmbctable(void)

{
  if (DAT_100098cc == 0) {
    __setmbcp(-3);
    DAT_100098cc = 1;
  }
  return 0;
}



// Function: __get_errno_from_oserr at 10003275

/* Library Function - Single Match
    __get_errno_from_oserr
   
   Library: Visual Studio 2010 Release */

int __cdecl __get_errno_from_oserr(ulong param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (param_1 == (&DAT_100088e0)[uVar1 * 2]) {
      return *(int *)(uVar1 * 8 + 0x100088e4);
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x2d);
  if (param_1 - 0x13 < 0x12) {
    return 0xd;
  }
  return (-(uint)(0xe < param_1 - 0xbc) & 0xe) + 8;
}



// Function: __errno at 100032b7

/* Library Function - Single Match
    __errno
   
   Library: Visual Studio 2010 Release */

int * __cdecl __errno(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd_noexit();
  if (p_Var1 == (_ptiddata)0x0) {
    return (int *)&DAT_10008a48;
  }
  return &p_Var1->_terrno;
}



// Function: _malloc at 100032ca

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 2010 Release */

void * __cdecl _malloc(size_t _Size)

{
  SIZE_T dwBytes;
  LPVOID pvVar1;
  int iVar2;
  int *piVar3;
  
  if (_Size < 0xffffffe1) {
    do {
      if (DAT_10008c88 == (HANDLE)0x0) {
        __FF_MSGBANNER();
        __NMSG_WRITE(0x1e);
        ___crtExitProcess(0xff);
      }
      dwBytes = _Size;
      if (_Size == 0) {
        dwBytes = 1;
      }
      pvVar1 = HeapAlloc(DAT_10008c88,0,dwBytes);
      if (pvVar1 != (LPVOID)0x0) {
        return pvVar1;
      }
      if (DAT_10009458 == 0) {
        piVar3 = __errno();
        *piVar3 = 0xc;
        break;
      }
      iVar2 = __callnewh(_Size);
    } while (iVar2 != 0);
    piVar3 = __errno();
    *piVar3 = 0xc;
  }
  else {
    __callnewh(_Size);
    piVar3 = __errno();
    *piVar3 = 0xc;
  }
  return (void *)0x0;
}



// Function: __calloc_impl at 1000335e

/* Library Function - Single Match
    __calloc_impl
   
   Library: Visual Studio 2010 Release */

LPVOID __cdecl __calloc_impl(uint param_1,uint param_2,undefined4 *param_3)

{
  int *piVar1;
  LPVOID pvVar2;
  int iVar3;
  uint dwBytes;
  
  if ((param_1 != 0) && (0xffffffe0 / param_1 < param_2)) {
    piVar1 = __errno();
    *piVar1 = 0xc;
    return (LPVOID)0x0;
  }
  dwBytes = param_1 * param_2;
  if (dwBytes == 0) {
    dwBytes = 1;
  }
  do {
    pvVar2 = (LPVOID)0x0;
    if ((dwBytes < 0xffffffe1) &&
       (pvVar2 = HeapAlloc(DAT_10008c88,8,dwBytes), pvVar2 != (LPVOID)0x0)) {
      return pvVar2;
    }
    if (DAT_10009458 == 0) {
      if (param_3 == (undefined4 *)0x0) {
        return pvVar2;
      }
      *param_3 = 0xc;
      return pvVar2;
    }
    iVar3 = __callnewh(dwBytes);
  } while (iVar3 != 0);
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0xc;
  }
  return (LPVOID)0x0;
}



// Function: _realloc at 100033e0

/* Library Function - Single Match
    _realloc
   
   Library: Visual Studio 2010 Release */

void * __cdecl _realloc(void *_Memory,size_t _NewSize)

{
  void *pvVar1;
  LPVOID pvVar2;
  int iVar3;
  int *piVar4;
  DWORD DVar5;
  
  if (_Memory == (void *)0x0) {
    pvVar1 = _malloc(_NewSize);
    return pvVar1;
  }
  if (_NewSize == 0) {
    _free(_Memory);
  }
  else {
    do {
      if (0xffffffe0 < _NewSize) {
        __callnewh(_NewSize);
        piVar4 = __errno();
        *piVar4 = 0xc;
        return (void *)0x0;
      }
      if (_NewSize == 0) {
        _NewSize = 1;
      }
      pvVar2 = HeapReAlloc(DAT_10008c88,0,_Memory,_NewSize);
      if (pvVar2 != (LPVOID)0x0) {
        return pvVar2;
      }
      if (DAT_10009458 == 0) {
        piVar4 = __errno();
        DVar5 = GetLastError();
        iVar3 = __get_errno_from_oserr(DVar5);
        *piVar4 = iVar3;
        return (void *)0x0;
      }
      iVar3 = __callnewh(_NewSize);
    } while (iVar3 != 0);
    piVar4 = __errno();
    DVar5 = GetLastError();
    iVar3 = __get_errno_from_oserr(DVar5);
    *piVar4 = iVar3;
  }
  return (void *)0x0;
}



// Function: FUN_100034c6 at 100034c6

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100034c6(void)

{
  _DAT_10008dfc = EncodePointer(&LAB_1000348d);
  return;
}



// Function: __initp_misc_winsig at 100034d7

/* Library Function - Single Match
    __initp_misc_winsig
   
   Library: Visual Studio 2010 Release */

void __cdecl __initp_misc_winsig(undefined4 param_1)

{
  DAT_10008e00 = param_1;
  DAT_10008e04 = param_1;
  DAT_10008e08 = param_1;
  DAT_10008e0c = param_1;
  return;
}



// Function: siglookup at 100034f5

/* Library Function - Single Match
    _siglookup
   
   Library: Visual Studio 2010 Release */

uint __cdecl siglookup(uint param_1)

{
  uint uVar1;
  int in_EDX;
  
  uVar1 = param_1;
  do {
    if (*(int *)(uVar1 + 4) == in_EDX) break;
    uVar1 = uVar1 + 0xc;
  } while (uVar1 < param_1 + 0x90);
  if ((param_1 + 0x90 <= uVar1) || (*(int *)(uVar1 + 4) != in_EDX)) {
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_1000352c at 1000352c

void FUN_1000352c(void)

{
  DecodePointer(DAT_10008e08);
  return;
}



// Function: _raise at 10003539

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _raise
   
   Library: Visual Studio 2010 Release */

int __cdecl _raise(int _SigNum)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  PVOID Ptr;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  _ptiddata p_Var7;
  int local_34;
  void *local_30;
  int local_28;
  
  p_Var7 = (_ptiddata)0x0;
  bVar1 = false;
  if (_SigNum < 0xc) {
    if (_SigNum != 0xb) {
      if (_SigNum == 2) {
        puVar6 = &DAT_10008e00;
        Ptr = DAT_10008e00;
        goto LAB_100035e3;
      }
      if (_SigNum != 4) {
        if (_SigNum == 6) goto LAB_100035c1;
        if (_SigNum != 8) goto LAB_100035af;
      }
    }
    p_Var7 = __getptd_noexit();
    if (p_Var7 == (_ptiddata)0x0) {
      return -1;
    }
    uVar2 = siglookup((uint)p_Var7->_pxcptacttab);
    puVar6 = (undefined4 *)(uVar2 + 8);
    pcVar4 = (code *)*puVar6;
  }
  else {
    if (_SigNum == 0xf) {
      puVar6 = &DAT_10008e0c;
      Ptr = DAT_10008e0c;
    }
    else if (_SigNum == 0x15) {
      puVar6 = &DAT_10008e04;
      Ptr = DAT_10008e04;
    }
    else {
      if (_SigNum != 0x16) {
LAB_100035af:
        piVar3 = __errno();
        *piVar3 = 0x16;
        FUN_10003884();
        return -1;
      }
LAB_100035c1:
      puVar6 = &DAT_10008e08;
      Ptr = DAT_10008e08;
    }
LAB_100035e3:
    bVar1 = true;
    pcVar4 = (code *)DecodePointer(Ptr);
  }
  if (pcVar4 == (code *)0x1) {
    return 0;
  }
  if (pcVar4 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
    __exit(3);
  }
  if (bVar1) {
    __lock(0);
  }
  if (((_SigNum == 8) || (_SigNum == 0xb)) || (_SigNum == 4)) {
    local_30 = p_Var7->_tpxcptinfoptrs;
    p_Var7->_tpxcptinfoptrs = (void *)0x0;
    if (_SigNum == 8) {
      local_34 = p_Var7->_tfpecode;
      p_Var7->_tfpecode = 0x8c;
      goto LAB_10003647;
    }
  }
  else {
LAB_10003647:
    if (_SigNum == 8) {
      for (local_28 = 3; local_28 < 0xc; local_28 = local_28 + 1) {
        *(undefined4 *)(local_28 * 0xc + 8 + (int)p_Var7->_pxcptacttab) = 0;
      }
      goto LAB_1000367f;
    }
  }
  uVar5 = FUN_10001285();
  *puVar6 = uVar5;
LAB_1000367f:
  FUN_100036a0();
  if (_SigNum == 8) {
    (*pcVar4)(8,p_Var7->_tfpecode);
  }
  else {
    (*pcVar4)(_SigNum);
    if ((_SigNum != 0xb) && (_SigNum != 4)) {
      return 0;
    }
  }
  p_Var7->_tpxcptinfoptrs = local_30;
  if (_SigNum == 8) {
    p_Var7->_tfpecode = local_34;
  }
  return 0;
}



// Function: FUN_100036a0 at 100036a0

void FUN_100036a0(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) != 0) {
    FUN_100026c5(0);
  }
  return;
}



// Function: FUN_100036dc at 100036dc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100036dc(undefined4 param_1)

{
  _DAT_10008e14 = param_1;
  return;
}



// Function: FUN_100036eb at 100036eb

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100036eb(undefined4 param_1)

{
  _DAT_10008e18 = param_1;
  return;
}



// Function: FUN_100036fa at 100036fa

void __cdecl FUN_100036fa(undefined4 param_1)

{
  DAT_10008e1c = param_1;
  return;
}



// Function: __call_reportfault at 10003709

/* Library Function - Single Match
    __call_reportfault
   
   Library: Visual Studio 2010 Release */

void __cdecl __call_reportfault(int nDbgHookCode,DWORD dwExceptionCode,DWORD dwExceptionFlags)

{
  uint uVar1;
  BOOL BVar2;
  LONG LVar3;
  _EXCEPTION_POINTERS local_32c;
  EXCEPTION_RECORD local_324;
  undefined4 local_2d4;
  
  uVar1 = DAT_10008a80 ^ (uint)&stack0xfffffffc;
  if (nDbgHookCode != -1) {
    FUN_10004cf1();
  }
  local_324.ExceptionCode = 0;
  _memset(&local_324.ExceptionFlags,0,0x4c);
  local_32c.ExceptionRecord = &local_324;
  local_32c.ContextRecord = (PCONTEXT)&local_2d4;
  local_2d4 = 0x10001;
  local_324.ExceptionCode = dwExceptionCode;
  local_324.ExceptionFlags = dwExceptionFlags;
  BVar2 = IsDebuggerPresent();
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  LVar3 = UnhandledExceptionFilter(&local_32c);
  if (((LVar3 == 0) && (BVar2 == 0)) && (nDbgHookCode != -1)) {
    FUN_10004cf1();
  }
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: __invoke_watson at 10003832

/* Library Function - Single Match
    __invoke_watson
   
   Library: Visual Studio 2010 Release */

void __cdecl
__invoke_watson(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,uint param_4,uintptr_t param_5)

{
  HANDLE hProcess;
  UINT uExitCode;
  
  __call_reportfault(2,0xc0000417,1);
  uExitCode = 0xc0000417;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __invalid_parameter at 10003857

/* Library Function - Single Match
    __invalid_parameter
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

void __invalid_parameter(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,uint param_4,
                        uintptr_t param_5)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)DecodePointer(DAT_10008e1c);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x1000386d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
                    /* WARNING: Subroutine does not return */
  __invoke_watson(param_1,param_2,param_3,param_4,param_5);
}



// Function: FUN_10003884 at 10003884

void FUN_10003884(void)

{
  __invalid_parameter((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  return;
}



// Function: FUN_10003894 at 10003894

void __cdecl FUN_10003894(undefined4 param_1)

{
  DAT_10008e20 = param_1;
  return;
}



// Function: __callnewh at 100038a3

/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 2010 Release */

int __cdecl __callnewh(size_t _Size)

{
  code *pcVar1;
  int iVar2;
  
  pcVar1 = (code *)DecodePointer(DAT_10008e20);
  if (pcVar1 != (code *)0x0) {
    iVar2 = (*pcVar1)(_Size);
    if (iVar2 != 0) {
      return 1;
    }
  }
  return 0;
}



// Function: __onexit_nolock at 100038cb

/* Library Function - Single Match
    __onexit_nolock
   
   Library: Visual Studio 2010 Release */

PVOID __cdecl __onexit_nolock(PVOID param_1)

{
  undefined4 *_Memory;
  undefined4 *puVar1;
  size_t sVar2;
  size_t sVar3;
  PVOID pvVar4;
  int iVar5;
  
  _Memory = (undefined4 *)DecodePointer(DAT_100098c8);
  puVar1 = (undefined4 *)DecodePointer(DAT_100098c4);
  if ((puVar1 < _Memory) || (iVar5 = (int)puVar1 - (int)_Memory, iVar5 + 4U < 4)) {
    return (PVOID)0x0;
  }
  sVar2 = __msize(_Memory);
  if (sVar2 < iVar5 + 4U) {
    sVar3 = 0x800;
    if (sVar2 < 0x800) {
      sVar3 = sVar2;
    }
    if ((sVar3 + sVar2 < sVar2) ||
       (pvVar4 = __realloc_crt(_Memory,sVar3 + sVar2), pvVar4 == (void *)0x0)) {
      if (sVar2 + 0x10 < sVar2) {
        return (PVOID)0x0;
      }
      pvVar4 = __realloc_crt(_Memory,sVar2 + 0x10);
      if (pvVar4 == (void *)0x0) {
        return (PVOID)0x0;
      }
    }
    puVar1 = (undefined4 *)((int)pvVar4 + (iVar5 >> 2) * 4);
    DAT_100098c8 = EncodePointer(pvVar4);
  }
  pvVar4 = EncodePointer(param_1);
  *puVar1 = pvVar4;
  DAT_100098c4 = EncodePointer(puVar1 + 1);
  return param_1;
}



// Function: __onexit at 100039b2

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __onexit
   
   Library: Visual Studio 2010 Release */

_onexit_t __cdecl __onexit(_onexit_t _Func)

{
  _onexit_t p_Var1;
  
  FUN_100018c3();
  p_Var1 = (_onexit_t)__onexit_nolock(_Func);
  FUN_100039e8();
  return p_Var1;
}



// Function: FUN_100039e8 at 100039e8

void FUN_100039e8(void)

{
  FUN_100018cc();
  return;
}



// Function: _atexit at 100039ee

/* Library Function - Single Match
    _atexit
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: __initp_misc_cfltcvt_tab at 10003a05

/* Library Function - Single Match
    __initp_misc_cfltcvt_tab
   
   Library: Visual Studio 2010 Release */

void __initp_misc_cfltcvt_tab(void)

{
  PVOID pvVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    pvVar1 = EncodePointer(*(PVOID *)((int)&PTR_LAB_10008a50 + uVar2));
    *(PVOID *)((int)&PTR_LAB_10008a50 + uVar2) = pvVar1;
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x28);
  return;
}



// Function: __ValidateImageBase at 10003a30

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



// Function: __FindPESection at 10003a70

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



// Function: __IsNonwritableInCurrentImage at 10003ac0

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
  
  pcStack_10 = __except_handler4;
  local_14 = ExceptionList;
  local_c = DAT_10008a80 ^ 0x100079f0;
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



// Function: __GET_RTERRMSG at 10003b7c

/* Library Function - Single Match
    __GET_RTERRMSG
   
   Library: Visual Studio 2010 Release */

wchar_t * __cdecl __GET_RTERRMSG(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (param_1 == (&DAT_10006df8)[uVar1 * 2]) {
      return *(wchar_t **)(&UNK_10006dfc + uVar1 * 8);
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x16);
  return (wchar_t *)0x0;
}



// Function: __NMSG_WRITE at 10003ba2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __NMSG_WRITE
   
   Library: Visual Studio 2010 Release */

void __cdecl __NMSG_WRITE(int param_1)

{
  wchar_t *pwVar1;
  int iVar2;
  errno_t eVar3;
  DWORD DVar4;
  size_t sVar5;
  HANDLE hFile;
  uint uVar6;
  wchar_t **lpNumberOfBytesWritten;
  LPOVERLAPPED lpOverlapped;
  wchar_t *local_200;
  char local_1fc [500];
  uint local_8;
  
  local_8 = DAT_10008a80 ^ (uint)&stack0xfffffffc;
  pwVar1 = __GET_RTERRMSG(param_1);
  local_200 = pwVar1;
  if (pwVar1 != (wchar_t *)0x0) {
    iVar2 = __set_error_mode(3);
    if ((iVar2 == 1) || ((iVar2 = __set_error_mode(3), iVar2 == 0 && (DAT_10008b30 == 1)))) {
      hFile = GetStdHandle(0xfffffff4);
      if ((hFile != (HANDLE)0x0) && (hFile != (HANDLE)0xffffffff)) {
        uVar6 = 0;
        do {
          local_1fc[uVar6] = (char)pwVar1[uVar6];
          if (pwVar1[uVar6] == L'\0') break;
          uVar6 = uVar6 + 1;
        } while (uVar6 < 500);
        lpOverlapped = (LPOVERLAPPED)0x0;
        lpNumberOfBytesWritten = &local_200;
        local_1fc[499] = 0;
        sVar5 = _strlen(local_1fc);
        WriteFile(hFile,local_1fc,sVar5,(LPDWORD)lpNumberOfBytesWritten,lpOverlapped);
      }
    }
    else if (param_1 != 0xfc) {
      eVar3 = _wcscpy_s((wchar_t *)&DAT_10008e28,0x314,L"Runtime Error!\n\nProgram: ");
      if (eVar3 == 0) {
        _DAT_10009062 = 0;
        DVar4 = GetModuleFileNameW((HMODULE)0x0,(LPWSTR)&DAT_10008e5a,0x104);
        if ((DVar4 != 0) ||
           (eVar3 = _wcscpy_s((wchar_t *)&DAT_10008e5a,0x2fb,L"<program name unknown>"), eVar3 == 0)
           ) {
          sVar5 = _wcslen((wchar_t *)&DAT_10008e5a);
          if (0x3c < sVar5 + 1) {
            sVar5 = _wcslen((wchar_t *)&DAT_10008e5a);
            eVar3 = _wcsncpy_s(&DAT_10008de4 + sVar5,0x2fb - ((int)(sVar5 * 2 + -0x76) >> 1),L"...",
                               3);
            if (eVar3 != 0) goto LAB_10003c67;
          }
          eVar3 = _wcscat_s((wchar_t *)&DAT_10008e28,0x314,L"\n\n");
          if ((eVar3 == 0) &&
             (eVar3 = _wcscat_s((wchar_t *)&DAT_10008e28,0x314,local_200), eVar3 == 0)) {
            ___crtMessageBoxW((LPCWSTR)&DAT_10008e28,L"Microsoft Visual C++ Runtime Library",0x12010
                             );
            goto LAB_10003d42;
          }
        }
      }
LAB_10003c67:
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
  }
LAB_10003d42:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: __FF_MSGBANNER at 10003d51

/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 2010 Release */

void __cdecl __FF_MSGBANNER(void)

{
  int iVar1;
  
  iVar1 = __set_error_mode(3);
  if (iVar1 != 1) {
    iVar1 = __set_error_mode(3);
    if (iVar1 != 0) {
      return;
    }
    if (DAT_10008b30 != 1) {
      return;
    }
  }
  __NMSG_WRITE(0xfc);
  __NMSG_WRITE(0xff);
  return;
}



// Function: _strcpy_s at 10003d8a

/* Library Function - Single Match
    _strcpy_s
   
   Library: Visual Studio 2010 Release */

errno_t __cdecl _strcpy_s(char *_Dst,rsize_t _SizeInBytes,char *_Src)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  errno_t eStack_10;
  
  if ((_Dst != (char *)0x0) && (_SizeInBytes != 0)) {
    if (_Src != (char *)0x0) {
      iVar3 = (int)_Dst - (int)_Src;
      do {
        cVar1 = *_Src;
        _Src[iVar3] = cVar1;
        _Src = _Src + 1;
        if (cVar1 == '\0') break;
        _SizeInBytes = _SizeInBytes - 1;
      } while (_SizeInBytes != 0);
      if (_SizeInBytes != 0) {
        return 0;
      }
      *_Dst = '\0';
      piVar2 = __errno();
      eStack_10 = 0x22;
      *piVar2 = 0x22;
      goto LAB_10003da9;
    }
    *_Dst = '\0';
  }
  piVar2 = __errno();
  eStack_10 = 0x16;
  *piVar2 = 0x16;
LAB_10003da9:
  FUN_10003884();
  return eStack_10;
}



// Function: _strlen at 10003df0

/* Library Function - Single Match
    _strlen
   
   Library: Visual Studio */

size_t __cdecl _strlen(char *_Str)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  
  uVar1 = (uint)_Str & 3;
  puVar2 = (uint *)_Str;
  while (uVar1 != 0) {
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
    if ((char)uVar1 == '\0') goto LAB_10003e53;
    uVar1 = (uint)puVar2 & 3;
  }
  do {
    do {
      puVar3 = puVar2;
      puVar2 = puVar3 + 1;
    } while (((*puVar3 ^ 0xffffffff ^ *puVar3 + 0x7efefeff) & 0x81010100) == 0);
    uVar1 = *puVar3;
    if ((char)uVar1 == '\0') {
      return (int)puVar3 - (int)_Str;
    }
    if ((char)(uVar1 >> 8) == '\0') {
      return (size_t)((int)puVar3 + (1 - (int)_Str));
    }
    if ((uVar1 & 0xff0000) == 0) {
      return (size_t)((int)puVar3 + (2 - (int)_Str));
    }
  } while ((uVar1 & 0xff000000) != 0);
LAB_10003e53:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
}



// Function: x_ismbbtype_l at 10003e7b

/* Library Function - Single Match
    int __cdecl x_ismbbtype_l(struct localeinfo_struct *,unsigned int,int,int)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

int __cdecl x_ismbbtype_l(localeinfo_struct *param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  int local_14;
  int local_10;
  int local_c;
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_14,param_1);
  if ((*(byte *)(local_10 + 0x1d + (param_2 & 0xff)) & (byte)param_4) == 0) {
    if (param_3 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (uint)*(ushort *)(*(int *)(local_14 + 200) + (param_2 & 0xff) * 2) & param_3;
    }
    if (uVar1 == 0) goto LAB_10003ebf;
  }
  uVar1 = 1;
LAB_10003ebf:
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return uVar1;
}



// Function: __ismbblead at 10003ece

/* Library Function - Single Match
    __ismbblead
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

int __cdecl __ismbblead(uint _C)

{
  int iVar1;
  
  iVar1 = x_ismbbtype_l((localeinfo_struct *)0x0,_C,0,4);
  return iVar1;
}



// Function: __security_check_cookie at 10003ee6

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_10008a80) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: __local_unwind4 at 10003f00

/* Library Function - Single Match
    __local_unwind4
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __cdecl __local_unwind4(uint *param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  void *pvStack_28;
  undefined1 *puStack_24;
  uint local_20;
  uint uStack_1c;
  int iStack_18;
  uint *puStack_14;
  
  puStack_14 = param_1;
  iStack_18 = param_2;
  uStack_1c = param_3;
  puStack_24 = &LAB_10003f90;
  pvStack_28 = ExceptionList;
  local_20 = DAT_10008a80 ^ (uint)&pvStack_28;
  ExceptionList = &pvStack_28;
  while( true ) {
    uVar2 = *(uint *)(param_2 + 0xc);
    if ((uVar2 == 0xfffffffe) || ((param_3 != 0xfffffffe && (uVar2 <= param_3)))) break;
    puVar1 = (undefined4 *)((*(uint *)(param_2 + 8) ^ *param_1) + 0x10 + uVar2 * 0xc);
    *(undefined4 *)(param_2 + 0xc) = *puVar1;
    if (puVar1[1] == 0) {
      __NLG_Notify(0x101);
      FUN_100052b4();
    }
  }
  ExceptionList = pvStack_28;
  return;
}



// Function: FUN_10003fd6 at 10003fd6

void FUN_10003fd6(int param_1)

{
  __local_unwind4(*(uint **)(param_1 + 0x28),*(int *)(param_1 + 0x18),*(uint *)(param_1 + 0x1c));
  return;
}



// Function: _EH4_CallFilterFunc at 10003ff2

/* Library Function - Single Match
    @_EH4_CallFilterFunc@8
   
   Library: Visual Studio 2010 Release
   __fastcall _EH4_CallFilterFunc,8 */

void __fastcall _EH4_CallFilterFunc(undefined *param_1)

{
  (*(code *)param_1)();
  return;
}



// Function: _EH4_TransferToHandler at 10004009

/* Library Function - Single Match
    @_EH4_TransferToHandler@8
   
   Library: Visual Studio 2010 Release
   __fastcall _EH4_TransferToHandler,8 */

void __fastcall _EH4_TransferToHandler(undefined *UNRECOVERED_JUMPTABLE)

{
  __NLG_Notify(1);
                    /* WARNING: Could not recover jumptable at 0x10004020. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}



// Function: _EH4_GlobalUnwind2 at 10004022

/* Library Function - Single Match
    @_EH4_GlobalUnwind2@8
   
   Library: Visual Studio 2010 Release
   __fastcall _EH4_GlobalUnwind2,8 */

void __fastcall _EH4_GlobalUnwind2(PVOID param_1,PEXCEPTION_RECORD param_2)

{
  RtlUnwind(param_1,(PVOID)0x10004036,param_2,(PVOID)0x0);
  return;
}



// Function: _EH4_LocalUnwind at 1000403b

/* Library Function - Single Match
    @_EH4_LocalUnwind@16
   
   Library: Visual Studio 2010 Release
   __fastcall _EH4_LocalUnwind,16 */

void __fastcall _EH4_LocalUnwind(int param_1,uint param_2,undefined4 param_3,uint *param_4)

{
  __local_unwind4(param_4,param_1,param_2);
  return;
}



// Function: ___free_lc_time at 10004052

/* Library Function - Single Match
    ___free_lc_time
   
   Library: Visual Studio 2010 Release */

void __cdecl ___free_lc_time(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    _free((void *)param_1[1]);
    _free((void *)param_1[2]);
    _free((void *)param_1[3]);
    _free((void *)param_1[4]);
    _free((void *)param_1[5]);
    _free((void *)param_1[6]);
    _free((void *)*param_1);
    _free((void *)param_1[8]);
    _free((void *)param_1[9]);
    _free((void *)param_1[10]);
    _free((void *)param_1[0xb]);
    _free((void *)param_1[0xc]);
    _free((void *)param_1[0xd]);
    _free((void *)param_1[7]);
    _free((void *)param_1[0xe]);
    _free((void *)param_1[0xf]);
    _free((void *)param_1[0x10]);
    _free((void *)param_1[0x11]);
    _free((void *)param_1[0x12]);
    _free((void *)param_1[0x13]);
    _free((void *)param_1[0x14]);
    _free((void *)param_1[0x15]);
    _free((void *)param_1[0x16]);
    _free((void *)param_1[0x17]);
    _free((void *)param_1[0x18]);
    _free((void *)param_1[0x19]);
    _free((void *)param_1[0x1a]);
    _free((void *)param_1[0x1b]);
    _free((void *)param_1[0x1c]);
    _free((void *)param_1[0x1d]);
    _free((void *)param_1[0x1e]);
    _free((void *)param_1[0x1f]);
    _free((void *)param_1[0x20]);
    _free((void *)param_1[0x21]);
    _free((void *)param_1[0x22]);
    _free((void *)param_1[0x23]);
    _free((void *)param_1[0x24]);
    _free((void *)param_1[0x25]);
    _free((void *)param_1[0x26]);
    _free((void *)param_1[0x27]);
    _free((void *)param_1[0x28]);
    _free((void *)param_1[0x29]);
    _free((void *)param_1[0x2a]);
    _free((void *)param_1[0x2f]);
    _free((void *)param_1[0x30]);
    _free((void *)param_1[0x31]);
    _free((void *)param_1[0x32]);
    _free((void *)param_1[0x33]);
    _free((void *)param_1[0x34]);
    _free((void *)param_1[0x2e]);
    _free((void *)param_1[0x36]);
    _free((void *)param_1[0x37]);
    _free((void *)param_1[0x38]);
    _free((void *)param_1[0x39]);
    _free((void *)param_1[0x3a]);
    _free((void *)param_1[0x3b]);
    _free((void *)param_1[0x35]);
    _free((void *)param_1[0x3c]);
    _free((void *)param_1[0x3d]);
    _free((void *)param_1[0x3e]);
    _free((void *)param_1[0x3f]);
    _free((void *)param_1[0x40]);
    _free((void *)param_1[0x41]);
    _free((void *)param_1[0x42]);
    _free((void *)param_1[0x43]);
    _free((void *)param_1[0x44]);
    _free((void *)param_1[0x45]);
    _free((void *)param_1[0x46]);
    _free((void *)param_1[0x47]);
    _free((void *)param_1[0x48]);
    _free((void *)param_1[0x49]);
    _free((void *)param_1[0x4a]);
    _free((void *)param_1[0x4b]);
    _free((void *)param_1[0x4c]);
    _free((void *)param_1[0x4d]);
    _free((void *)param_1[0x4e]);
    _free((void *)param_1[0x4f]);
    _free((void *)param_1[0x50]);
    _free((void *)param_1[0x51]);
    _free((void *)param_1[0x52]);
    _free((void *)param_1[0x53]);
    _free((void *)param_1[0x54]);
    _free((void *)param_1[0x55]);
    _free((void *)param_1[0x56]);
    _free((void *)param_1[0x57]);
    _free((void *)param_1[0x58]);
  }
  return;
}



// Function: ___free_lconv_num at 100043c9

/* Library Function - Single Match
    ___free_lconv_num
   
   Library: Visual Studio 2010 Release */

void __cdecl ___free_lconv_num(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((undefined *)*param_1 != PTR_DAT_10008a98) {
      _free((undefined *)*param_1);
    }
    if ((undefined *)param_1[1] != PTR_DAT_10008a9c) {
      _free((undefined *)param_1[1]);
    }
    if ((undefined *)param_1[2] != PTR_DAT_10008aa0) {
      _free((undefined *)param_1[2]);
    }
    if ((undefined *)param_1[0xc] != PTR_DAT_10008ac8) {
      _free((undefined *)param_1[0xc]);
    }
    if ((undefined *)param_1[0xd] != PTR_DAT_10008acc) {
      _free((undefined *)param_1[0xd]);
    }
  }
  return;
}



// Function: ___free_lconv_mon at 10004432

/* Library Function - Single Match
    ___free_lconv_mon
   
   Library: Visual Studio 2010 Release */

void __cdecl ___free_lconv_mon(int param_1)

{
  if (param_1 != 0) {
    if (*(undefined **)(param_1 + 0xc) != PTR_DAT_10008aa4) {
      _free(*(undefined **)(param_1 + 0xc));
    }
    if (*(undefined **)(param_1 + 0x10) != PTR_DAT_10008aa8) {
      _free(*(undefined **)(param_1 + 0x10));
    }
    if (*(undefined **)(param_1 + 0x14) != PTR_DAT_10008aac) {
      _free(*(undefined **)(param_1 + 0x14));
    }
    if (*(undefined **)(param_1 + 0x18) != PTR_DAT_10008ab0) {
      _free(*(undefined **)(param_1 + 0x18));
    }
    if (*(undefined **)(param_1 + 0x1c) != PTR_DAT_10008ab4) {
      _free(*(undefined **)(param_1 + 0x1c));
    }
    if (*(undefined **)(param_1 + 0x20) != PTR_DAT_10008ab8) {
      _free(*(undefined **)(param_1 + 0x20));
    }
    if (*(undefined **)(param_1 + 0x24) != PTR_DAT_10008abc) {
      _free(*(undefined **)(param_1 + 0x24));
    }
    if (*(undefined **)(param_1 + 0x38) != PTR_DAT_10008ad0) {
      _free(*(undefined **)(param_1 + 0x38));
    }
    if (*(undefined **)(param_1 + 0x3c) != PTR_DAT_10008ad4) {
      _free(*(undefined **)(param_1 + 0x3c));
    }
    if (*(undefined **)(param_1 + 0x40) != PTR_DAT_10008ad8) {
      _free(*(undefined **)(param_1 + 0x40));
    }
    if (*(undefined **)(param_1 + 0x44) != PTR_DAT_10008adc) {
      _free(*(undefined **)(param_1 + 0x44));
    }
    if (*(undefined **)(param_1 + 0x48) != PTR_DAT_10008ae0) {
      _free(*(undefined **)(param_1 + 0x48));
    }
    if (*(undefined **)(param_1 + 0x4c) != PTR_DAT_10008ae4) {
      _free(*(undefined **)(param_1 + 0x4c));
    }
  }
  return;
}



// Function: _memset at 10004530

/* Library Function - Single Match
    _memset
   
   Libraries: Visual Studio 2010 Debug, Visual Studio 2010 Release */

void * __cdecl _memset(void *_Dst,int _Val,size_t _Size)

{
  uint uVar1;
  undefined1 (*pauVar2) [16];
  uint uVar3;
  size_t sVar4;
  uint *puVar5;
  
  if (_Size == 0) {
    return _Dst;
  }
  uVar1 = _Val & 0xff;
  if ((((char)_Val == '\0') && (0x7f < _Size)) && (DAT_10009794 != 0)) {
    pauVar2 = __VEC_memzero((undefined1 (*) [16])_Dst,_Size);
    return pauVar2;
  }
  puVar5 = (uint *)_Dst;
  if (3 < _Size) {
    uVar3 = -(int)_Dst & 3;
    sVar4 = _Size;
    if (uVar3 != 0) {
      sVar4 = _Size - uVar3;
      do {
        *(char *)puVar5 = (char)_Val;
        puVar5 = (uint *)((int)puVar5 + 1);
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    uVar1 = uVar1 * 0x1010101;
    _Size = sVar4 & 3;
    uVar3 = sVar4 >> 2;
    if (uVar3 != 0) {
      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar5 = uVar1;
        puVar5 = puVar5 + 1;
      }
      if (_Size == 0) {
        return _Dst;
      }
    }
  }
  do {
    *(char *)puVar5 = (char)uVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
    _Size = _Size - 1;
  } while (_Size != 0);
  return _Dst;
}



// Function: __freea at 100045aa

/* Library Function - Single Match
    __freea
   
   Library: Visual Studio 2010 Release */

void __cdecl __freea(void *_Memory)

{
  if ((_Memory != (void *)0x0) && (*(int *)((int)_Memory + -8) == 0xdddd)) {
    _free((int *)((int)_Memory + -8));
  }
  return;
}



// Function: __crtLCMapStringA_stat at 100045ca

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* Library Function - Single Match
    int __cdecl __crtLCMapStringA_stat(struct localeinfo_struct *,unsigned long,unsigned long,char
   const *,int,char *,int,int,int)
   
   Library: Visual Studio 2010 Release */

int __cdecl
__crtLCMapStringA_stat
          (localeinfo_struct *param_1,ulong param_2,ulong param_3,char *param_4,int param_5,
          char *param_6,int param_7,int param_8,int param_9)

{
  uint _Size;
  bool bVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  uint cchWideChar;
  uint uVar5;
  LPCWSTR pWVar6;
  int iVar7;
  LPCWSTR local_10;
  
  uVar2 = DAT_10008a80 ^ (uint)&stack0xfffffffc;
  pcVar3 = param_4;
  iVar7 = param_5;
  if (0 < param_5) {
    do {
      iVar7 = iVar7 + -1;
      if (*pcVar3 == '\0') goto LAB_100045fa;
      pcVar3 = pcVar3 + 1;
    } while (iVar7 != 0);
    iVar7 = -1;
LAB_100045fa:
    iVar7 = param_5 - iVar7;
    iVar4 = iVar7 + -1;
    bVar1 = iVar4 < param_5;
    param_5 = iVar4;
    if (bVar1) {
      param_5 = iVar7;
    }
  }
  if (param_8 == 0) {
    param_8 = param_1->locinfo->lc_codepage;
  }
  cchWideChar = MultiByteToWideChar(param_8,(uint)(param_9 != 0) * 8 + 1,param_4,param_5,(LPWSTR)0x0
                                    ,0);
  if (cchWideChar == 0) goto LAB_1000479f;
  if (((int)cchWideChar < 1) || (0xffffffe0 / cchWideChar < 2)) {
    local_10 = (LPCWSTR)0x0;
  }
  else {
    uVar5 = cchWideChar * 2 + 8;
    if (uVar5 < 0x401) {
      pWVar6 = (LPCWSTR)&stack0xffffffe0;
      local_10 = (LPCWSTR)&stack0xffffffe0;
      if (&stack0x00000000 != (undefined1 *)0x20) {
LAB_1000468a:
        local_10 = pWVar6 + 4;
      }
    }
    else {
      pWVar6 = (LPCWSTR)_malloc(uVar5);
      local_10 = pWVar6;
      if (pWVar6 != (LPCWSTR)0x0) {
        pWVar6[0] = L'\xdddd';
        pWVar6[1] = L'\0';
        goto LAB_1000468a;
      }
    }
  }
  if (local_10 == (LPCWSTR)0x0) goto LAB_1000479f;
  iVar7 = MultiByteToWideChar(param_8,1,param_4,param_5,local_10,cchWideChar);
  if ((iVar7 != 0) &&
     (uVar5 = LCMapStringW(param_2,param_3,local_10,cchWideChar,(LPWSTR)0x0,0), uVar5 != 0)) {
    if ((param_3 & 0x400) == 0) {
      if (((int)uVar5 < 1) || (0xffffffe0 / uVar5 < 2)) {
        pWVar6 = (LPCWSTR)0x0;
      }
      else {
        _Size = uVar5 * 2 + 8;
        if (_Size < 0x401) {
          if (&stack0x00000000 == (undefined1 *)0x20) goto LAB_10004793;
          pWVar6 = (LPCWSTR)&stack0xffffffe8;
        }
        else {
          pWVar6 = (LPCWSTR)_malloc(_Size);
          if (pWVar6 != (LPCWSTR)0x0) {
            pWVar6[0] = L'\xdddd';
            pWVar6[1] = L'\0';
            pWVar6 = pWVar6 + 4;
          }
        }
      }
      if (pWVar6 != (LPCWSTR)0x0) {
        iVar7 = LCMapStringW(param_2,param_3,local_10,cchWideChar,pWVar6,uVar5);
        if (iVar7 != 0) {
          if (param_7 == 0) {
            param_7 = 0;
            param_6 = (LPSTR)0x0;
          }
          WideCharToMultiByte(param_8,0,pWVar6,uVar5,param_6,param_7,(LPCSTR)0x0,(LPBOOL)0x0);
        }
        __freea(pWVar6);
      }
    }
    else if ((param_7 != 0) && ((int)uVar5 <= param_7)) {
      LCMapStringW(param_2,param_3,local_10,cchWideChar,(LPWSTR)param_6,param_7);
    }
  }
LAB_10004793:
  __freea(local_10);
LAB_1000479f:
  iVar7 = __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return iVar7;
}



// Function: ___crtLCMapStringA at 100047b1

/* Library Function - Single Match
    ___crtLCMapStringA
   
   Library: Visual Studio 2010 Release */

int __cdecl
___crtLCMapStringA(_locale_t _Plocinfo,LPCWSTR _LocaleName,DWORD _DwMapFlag,LPCSTR _LpSrcStr,
                  int _CchSrc,LPSTR _LpDestStr,int _CchDest,int _Code_page,BOOL _BError)

{
  int iVar1;
  localeinfo_struct local_14;
  int local_c;
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_14,_Plocinfo);
  iVar1 = __crtLCMapStringA_stat
                    (&local_14,(ulong)_LocaleName,_DwMapFlag,_LpSrcStr,_CchSrc,_LpDestStr,_CchDest,
                     _Code_page,_BError);
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return iVar1;
}



// Function: __crtGetStringTypeA_stat at 100047f7

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* Library Function - Single Match
    int __cdecl __crtGetStringTypeA_stat(struct localeinfo_struct *,unsigned long,char const
   *,int,unsigned short *,int,int,int)
   
   Library: Visual Studio 2010 Release */

int __cdecl
__crtGetStringTypeA_stat
          (localeinfo_struct *param_1,ulong param_2,char *param_3,int param_4,ushort *param_5,
          int param_6,int param_7,int param_8)

{
  uint _Size;
  uint uVar1;
  uint cchWideChar;
  LPCWSTR pWVar2;
  int iVar3;
  LPCWSTR lpWideCharStr;
  
  uVar1 = DAT_10008a80 ^ (uint)&stack0xfffffffc;
  if (param_6 == 0) {
    param_6 = param_1->locinfo->lc_codepage;
  }
  cchWideChar = MultiByteToWideChar(param_6,(uint)(param_7 != 0) * 8 + 1,param_3,param_4,(LPWSTR)0x0
                                    ,0);
  if (cchWideChar == 0) goto LAB_100048cc;
  lpWideCharStr = (LPCWSTR)0x0;
  if ((0 < (int)cchWideChar) && (cchWideChar < 0x7ffffff1)) {
    _Size = cchWideChar * 2 + 8;
    if (_Size < 0x401) {
      pWVar2 = (LPCWSTR)&stack0xffffffe8;
      lpWideCharStr = (LPCWSTR)&stack0xffffffe8;
      if (&stack0x00000000 != (undefined1 *)0x18) {
LAB_10004886:
        lpWideCharStr = pWVar2 + 4;
      }
    }
    else {
      pWVar2 = (LPCWSTR)_malloc(_Size);
      lpWideCharStr = pWVar2;
      if (pWVar2 != (LPCWSTR)0x0) {
        pWVar2[0] = L'\xdddd';
        pWVar2[1] = L'\0';
        goto LAB_10004886;
      }
    }
  }
  if (lpWideCharStr != (LPCWSTR)0x0) {
    _memset(lpWideCharStr,0,cchWideChar * 2);
    iVar3 = MultiByteToWideChar(param_6,1,param_3,param_4,lpWideCharStr,cchWideChar);
    if (iVar3 != 0) {
      GetStringTypeW(param_2,lpWideCharStr,iVar3,param_5);
    }
    __freea(lpWideCharStr);
  }
LAB_100048cc:
  iVar3 = __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return iVar3;
}



// Function: ___crtGetStringTypeA at 100048de

/* Library Function - Single Match
    ___crtGetStringTypeA
   
   Library: Visual Studio 2010 Release */

BOOL __cdecl
___crtGetStringTypeA
          (_locale_t _Plocinfo,DWORD _DWInfoType,LPCSTR _LpSrcStr,int _CchSrc,LPWORD _LpCharType,
          int _Code_page,BOOL _BError)

{
  int iVar1;
  int in_stack_00000020;
  pthreadlocinfo in_stack_ffffffec;
  int local_c;
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&stack0xffffffec,_Plocinfo);
  iVar1 = __crtGetStringTypeA_stat
                    ((localeinfo_struct *)&stack0xffffffec,_DWInfoType,_LpSrcStr,_CchSrc,_LpCharType
                     ,_Code_page,in_stack_00000020,(int)in_stack_ffffffec);
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return iVar1;
}



// Function: __msize at 1000491e

/* Library Function - Single Match
    __msize
   
   Library: Visual Studio 2010 Release */

size_t __cdecl __msize(void *_Memory)

{
  int *piVar1;
  SIZE_T SVar2;
  
  if (_Memory == (void *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_10003884();
    return 0xffffffff;
  }
  SVar2 = HeapSize(DAT_10008c88,0,_Memory);
  return SVar2;
}



// Function: _abort at 10004951

/* Library Function - Single Match
    _abort
   
   Library: Visual Studio 2010 Release */

void __cdecl _abort(void)

{
  int iVar1;
  
  iVar1 = FUN_1000352c();
  if (iVar1 != 0) {
    _raise(0x16);
  }
  if ((DAT_10008b00 & 2) != 0) {
    __call_reportfault(3,0x40000015,1);
  }
                    /* WARNING: Subroutine does not return */
  __exit(3);
}



// Function: FID_conflict:_memcpy at 10004990

/* Library Function - Multiple Matches With Different Base Names
    _memcpy
    _memmove
   
   Libraries: Visual Studio 2010 Debug, Visual Studio 2010 Release */

void * __cdecl FID_conflict__memcpy(void *_Dst,void *_Src,size_t _Size)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  if ((_Src < _Dst) && (_Dst < (void *)(_Size + (int)_Src))) {
    puVar1 = (undefined4 *)((_Size - 4) + (int)_Src);
    puVar4 = (undefined4 *)((_Size - 4) + (int)_Dst);
    if (((uint)puVar4 & 3) == 0) {
      uVar2 = _Size >> 2;
      uVar3 = _Size & 3;
      if (7 < uVar2) {
        for (; uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar4 = *puVar1;
          puVar1 = puVar1 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar3) {
        case 0:
          return _Dst;
        case 2:
          goto switchD_10004b6f_caseD_2;
        case 3:
          goto switchD_10004b6f_caseD_3;
        }
        goto switchD_10004b6f_caseD_1;
      }
    }
    else {
      switch(_Size) {
      case 0:
        goto switchD_10004b6f_caseD_0;
      case 1:
        goto switchD_10004b6f_caseD_1;
      case 2:
        goto switchD_10004b6f_caseD_2;
      case 3:
        goto switchD_10004b6f_caseD_3;
      default:
        uVar2 = _Size - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar3 = uVar2 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar1 + 3);
          puVar1 = (undefined4 *)((int)puVar1 + -1);
          uVar2 = uVar2 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar2) {
            for (; uVar2 != 0; uVar2 = uVar2 - 1) {
              *puVar4 = *puVar1;
              puVar1 = puVar1 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar3) {
            case 0:
              return _Dst;
            case 2:
              goto switchD_10004b6f_caseD_2;
            case 3:
              goto switchD_10004b6f_caseD_3;
            }
            goto switchD_10004b6f_caseD_1;
          }
          break;
        case 2:
          uVar3 = uVar2 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar1 + 3);
          uVar2 = uVar2 >> 2;
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar1 + 2);
          puVar1 = (undefined4 *)((int)puVar1 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar2) {
            for (; uVar2 != 0; uVar2 = uVar2 - 1) {
              *puVar4 = *puVar1;
              puVar1 = puVar1 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar3) {
            case 0:
              return _Dst;
            case 2:
              goto switchD_10004b6f_caseD_2;
            case 3:
              goto switchD_10004b6f_caseD_3;
            }
            goto switchD_10004b6f_caseD_1;
          }
          break;
        case 3:
          uVar3 = uVar2 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar1 + 3);
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar1 + 2);
          uVar2 = uVar2 >> 2;
          *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar1 + 1);
          puVar1 = (undefined4 *)((int)puVar1 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar2) {
            for (; uVar2 != 0; uVar2 = uVar2 - 1) {
              *puVar4 = *puVar1;
              puVar1 = puVar1 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar3) {
            case 0:
              return _Dst;
            case 2:
              goto switchD_10004b6f_caseD_2;
            case 3:
              goto switchD_10004b6f_caseD_3;
            }
            goto switchD_10004b6f_caseD_1;
          }
        }
      }
    }
    switch(uVar2) {
    case 7:
      puVar4[7 - uVar2] = puVar1[7 - uVar2];
    case 6:
      puVar4[6 - uVar2] = puVar1[6 - uVar2];
    case 5:
      puVar4[5 - uVar2] = puVar1[5 - uVar2];
    case 4:
      puVar4[4 - uVar2] = puVar1[4 - uVar2];
    case 3:
      puVar4[3 - uVar2] = puVar1[3 - uVar2];
    case 2:
      puVar4[2 - uVar2] = puVar1[2 - uVar2];
    case 1:
      puVar4[1 - uVar2] = puVar1[1 - uVar2];
      puVar1 = puVar1 + -uVar2;
      puVar4 = puVar4 + -uVar2;
    }
    switch(uVar3) {
    case 1:
switchD_10004b6f_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar1 + 3);
      return _Dst;
    case 2:
switchD_10004b6f_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar1 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar1 + 2);
      return _Dst;
    case 3:
switchD_10004b6f_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar1 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar1 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar1 + 1);
      return _Dst;
    }
switchD_10004b6f_caseD_0:
    return _Dst;
  }
  if (((0x7f < _Size) && (DAT_10009794 != 0)) && (((uint)_Dst & 0xf) == ((uint)_Src & 0xf))) {
    puVar1 = FUN_100053bc(_Size);
    return puVar1;
  }
  puVar1 = (undefined4 *)_Dst;
  if (((uint)_Dst & 3) == 0) {
    uVar2 = _Size >> 2;
    uVar3 = _Size & 3;
    if (7 < uVar2) {
                    /* WARNING: Load size is inaccurate */
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar1 = *_Src;
        _Src = (undefined4 *)((int)_Src + 4);
        puVar1 = puVar1 + 1;
      }
      switch(uVar3) {
      case 0:
        return _Dst;
      case 2:
        goto switchD_100049e9_caseD_2;
      case 3:
        goto switchD_100049e9_caseD_3;
      }
      goto switchD_100049e9_caseD_1;
    }
  }
  else {
    switch(_Size) {
    case 0:
      goto switchD_100049e9_caseD_0;
    case 1:
      goto switchD_100049e9_caseD_1;
    case 2:
      goto switchD_100049e9_caseD_2;
    case 3:
      goto switchD_100049e9_caseD_3;
    default:
      uVar2 = (_Size - 4) + ((uint)_Dst & 3);
      switch((uint)_Dst & 3) {
      case 1:
        uVar3 = uVar2 & 3;
                    /* WARNING: Load size is inaccurate */
        *(undefined1 *)_Dst = *_Src;
        *(undefined1 *)((int)_Dst + 1) = *(undefined1 *)((int)_Src + 1);
        uVar2 = uVar2 >> 2;
        *(undefined1 *)((int)_Dst + 2) = *(undefined1 *)((int)_Src + 2);
        _Src = (void *)((int)_Src + 3);
        puVar1 = (undefined4 *)((int)_Dst + 3);
        if (7 < uVar2) {
                    /* WARNING: Load size is inaccurate */
          for (; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar1 = *_Src;
            _Src = (undefined4 *)((int)_Src + 4);
            puVar1 = puVar1 + 1;
          }
          switch(uVar3) {
          case 0:
            return _Dst;
          case 2:
            goto switchD_100049e9_caseD_2;
          case 3:
            goto switchD_100049e9_caseD_3;
          }
          goto switchD_100049e9_caseD_1;
        }
        break;
      case 2:
        uVar3 = uVar2 & 3;
                    /* WARNING: Load size is inaccurate */
        *(undefined1 *)_Dst = *_Src;
        uVar2 = uVar2 >> 2;
        *(undefined1 *)((int)_Dst + 1) = *(undefined1 *)((int)_Src + 1);
        _Src = (void *)((int)_Src + 2);
        puVar1 = (undefined4 *)((int)_Dst + 2);
        if (7 < uVar2) {
                    /* WARNING: Load size is inaccurate */
          for (; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar1 = *_Src;
            _Src = (undefined4 *)((int)_Src + 4);
            puVar1 = puVar1 + 1;
          }
          switch(uVar3) {
          case 0:
            return _Dst;
          case 2:
            goto switchD_100049e9_caseD_2;
          case 3:
            goto switchD_100049e9_caseD_3;
          }
          goto switchD_100049e9_caseD_1;
        }
        break;
      case 3:
        uVar3 = uVar2 & 3;
                    /* WARNING: Load size is inaccurate */
        *(undefined1 *)_Dst = *_Src;
        _Src = (void *)((int)_Src + 1);
        uVar2 = uVar2 >> 2;
        puVar1 = (undefined4 *)((int)_Dst + 1);
        if (7 < uVar2) {
                    /* WARNING: Load size is inaccurate */
          for (; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar1 = *_Src;
            _Src = (undefined4 *)((int)_Src + 4);
            puVar1 = puVar1 + 1;
          }
          switch(uVar3) {
          case 0:
            return _Dst;
          case 2:
            goto switchD_100049e9_caseD_2;
          case 3:
            goto switchD_100049e9_caseD_3;
          }
          goto switchD_100049e9_caseD_1;
        }
      }
    }
  }
  switch(uVar2) {
  case 7:
    puVar1[uVar2 - 7] = *(undefined4 *)((int)_Src + (uVar2 - 7) * 4);
  case 6:
    puVar1[uVar2 - 6] = *(undefined4 *)((int)_Src + (uVar2 - 6) * 4);
  case 5:
    puVar1[uVar2 - 5] = *(undefined4 *)((int)_Src + (uVar2 - 5) * 4);
  case 4:
    puVar1[uVar2 - 4] = *(undefined4 *)((int)_Src + (uVar2 - 4) * 4);
  case 3:
    puVar1[uVar2 - 3] = *(undefined4 *)((int)_Src + (uVar2 - 3) * 4);
  case 2:
    puVar1[uVar2 - 2] = *(undefined4 *)((int)_Src + (uVar2 - 2) * 4);
  case 1:
    puVar1[uVar2 - 1] = *(undefined4 *)((int)_Src + (uVar2 - 1) * 4);
    _Src = (void *)((int)_Src + uVar2 * 4);
    puVar1 = puVar1 + uVar2;
  }
  switch(uVar3) {
  case 1:
switchD_100049e9_caseD_1:
                    /* WARNING: Load size is inaccurate */
    *(undefined1 *)puVar1 = *_Src;
    return _Dst;
  case 2:
switchD_100049e9_caseD_2:
                    /* WARNING: Load size is inaccurate */
    *(undefined1 *)puVar1 = *_Src;
    *(undefined1 *)((int)puVar1 + 1) = *(undefined1 *)((int)_Src + 1);
    return _Dst;
  case 3:
switchD_100049e9_caseD_3:
                    /* WARNING: Load size is inaccurate */
    *(undefined1 *)puVar1 = *_Src;
    *(undefined1 *)((int)puVar1 + 1) = *(undefined1 *)((int)_Src + 1);
    *(undefined1 *)((int)puVar1 + 2) = *(undefined1 *)((int)_Src + 2);
    return _Dst;
  }
switchD_100049e9_caseD_0:
  return _Dst;
}



// Function: FUN_10004cf1 at 10004cf1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10004cf1(void)

{
  _DAT_10009798 = 0;
  return;
}



// Function: ___crtMessageBoxW at 10004d02

/* Library Function - Single Match
    ___crtMessageBoxW
   
   Library: Visual Studio 2010 Release */

int __cdecl ___crtMessageBoxW(LPCWSTR _LpText,LPCWSTR _LpCaption,UINT _UType)

{
  HMODULE hModule;
  FARPROC pFVar1;
  code *pcVar2;
  code *pcVar3;
  int iVar4;
  undefined1 local_28 [4];
  LPCWSTR local_24;
  LPCWSTR local_20;
  PVOID local_1c;
  int local_18;
  undefined1 local_14 [8];
  byte local_c;
  uint local_8;
  
  local_8 = DAT_10008a80 ^ (uint)&stack0xfffffffc;
  local_24 = _LpText;
  local_20 = _LpCaption;
  local_1c = (PVOID)FUN_10001285();
  local_18 = 0;
  if (DAT_1000945c == (PVOID)0x0) {
    hModule = LoadLibraryW(L"USER32.DLL");
    if ((hModule == (HMODULE)0x0) ||
       (pFVar1 = GetProcAddress(hModule,"MessageBoxW"), pFVar1 == (FARPROC)0x0)) goto LAB_10004e5f;
    DAT_1000945c = EncodePointer(pFVar1);
    pFVar1 = GetProcAddress(hModule,"GetActiveWindow");
    DAT_10009460 = EncodePointer(pFVar1);
    pFVar1 = GetProcAddress(hModule,"GetLastActivePopup");
    DAT_10009464 = EncodePointer(pFVar1);
    pFVar1 = GetProcAddress(hModule,"GetUserObjectInformationW");
    DAT_1000946c = EncodePointer(pFVar1);
    if (DAT_1000946c != (PVOID)0x0) {
      pFVar1 = GetProcAddress(hModule,"GetProcessWindowStation");
      DAT_10009468 = EncodePointer(pFVar1);
    }
  }
  if ((DAT_10009468 == local_1c) || (DAT_1000946c == local_1c)) {
LAB_10004e0e:
    if ((((DAT_10009460 != local_1c) &&
         (pcVar2 = (code *)DecodePointer(DAT_10009460), pcVar2 != (code *)0x0)) &&
        (local_18 = (*pcVar2)(), local_18 != 0)) &&
       ((DAT_10009464 != local_1c &&
        (pcVar2 = (code *)DecodePointer(DAT_10009464), pcVar2 != (code *)0x0)))) {
      local_18 = (*pcVar2)(local_18);
    }
  }
  else {
    pcVar2 = (code *)DecodePointer(DAT_10009468);
    pcVar3 = (code *)DecodePointer(DAT_1000946c);
    if (((pcVar2 == (code *)0x0) || (pcVar3 == (code *)0x0)) ||
       (((iVar4 = (*pcVar2)(), iVar4 != 0 &&
         (iVar4 = (*pcVar3)(iVar4,1,local_14,0xc,local_28), iVar4 != 0)) && ((local_c & 1) != 0))))
    goto LAB_10004e0e;
    _UType = _UType | 0x200000;
  }
  pcVar2 = (code *)DecodePointer(DAT_1000945c);
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)(local_18,local_24,local_20,_UType);
  }
LAB_10004e5f:
  iVar4 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar4;
}



// Function: _wcscat_s at 10004e6e

/* Library Function - Single Match
    _wcscat_s
   
   Library: Visual Studio 2010 Release */

errno_t __cdecl _wcscat_s(wchar_t *_Dst,rsize_t _SizeInWords,wchar_t *_Src)

{
  wchar_t wVar1;
  int *piVar2;
  wchar_t *pwVar3;
  int iVar4;
  errno_t eStack_10;
  
  if ((_Dst != (wchar_t *)0x0) && (_SizeInWords != 0)) {
    pwVar3 = _Dst;
    if (_Src != (wchar_t *)0x0) {
      do {
        if (*pwVar3 == L'\0') break;
        pwVar3 = pwVar3 + 1;
        _SizeInWords = _SizeInWords - 1;
      } while (_SizeInWords != 0);
      if (_SizeInWords != 0) {
        iVar4 = (int)pwVar3 - (int)_Src;
        do {
          wVar1 = *_Src;
          *(wchar_t *)(iVar4 + (int)_Src) = wVar1;
          _Src = _Src + 1;
          if (wVar1 == L'\0') break;
          _SizeInWords = _SizeInWords - 1;
        } while (_SizeInWords != 0);
        if (_SizeInWords != 0) {
          return 0;
        }
        *_Dst = L'\0';
        piVar2 = __errno();
        eStack_10 = 0x22;
        *piVar2 = 0x22;
        goto LAB_10004e8d;
      }
    }
    *_Dst = L'\0';
  }
  piVar2 = __errno();
  eStack_10 = 0x16;
  *piVar2 = 0x16;
LAB_10004e8d:
  FUN_10003884();
  return eStack_10;
}



// Function: _wcsncpy_s at 10004ee3

/* Library Function - Single Match
    _wcsncpy_s
   
   Library: Visual Studio 2010 Release */

errno_t __cdecl _wcsncpy_s(wchar_t *_Dst,rsize_t _SizeInWords,wchar_t *_Src,rsize_t _MaxCount)

{
  wchar_t wVar1;
  int *piVar2;
  wchar_t *pwVar3;
  int iVar4;
  rsize_t rVar5;
  errno_t eStack_14;
  
  if (_MaxCount == 0) {
    if (_Dst == (wchar_t *)0x0) {
      if (_SizeInWords == 0) {
        return 0;
      }
    }
    else {
LAB_10004f09:
      if (_SizeInWords != 0) {
        if (_MaxCount == 0) {
          *_Dst = L'\0';
          return 0;
        }
        if (_Src != (wchar_t *)0x0) {
          rVar5 = _SizeInWords;
          if (_MaxCount == 0xffffffff) {
            iVar4 = (int)_Dst - (int)_Src;
            do {
              wVar1 = *_Src;
              *(wchar_t *)(iVar4 + (int)_Src) = wVar1;
              _Src = _Src + 1;
              if (wVar1 == L'\0') break;
              rVar5 = rVar5 - 1;
            } while (rVar5 != 0);
          }
          else {
            pwVar3 = _Dst;
            do {
              wVar1 = *(wchar_t *)(((int)_Src - (int)_Dst) + (int)pwVar3);
              *pwVar3 = wVar1;
              pwVar3 = pwVar3 + 1;
              if ((wVar1 == L'\0') || (rVar5 = rVar5 - 1, rVar5 == 0)) break;
              _MaxCount = _MaxCount - 1;
            } while (_MaxCount != 0);
            if (_MaxCount == 0) {
              *pwVar3 = L'\0';
            }
          }
          if (rVar5 != 0) {
            return 0;
          }
          if (_MaxCount == 0xffffffff) {
            _Dst[_SizeInWords - 1] = L'\0';
            return 0x50;
          }
          *_Dst = L'\0';
          piVar2 = __errno();
          eStack_14 = 0x22;
          *piVar2 = 0x22;
          goto LAB_10004f1a;
        }
        *_Dst = L'\0';
      }
    }
  }
  else if (_Dst != (wchar_t *)0x0) goto LAB_10004f09;
  piVar2 = __errno();
  eStack_14 = 0x16;
  *piVar2 = 0x16;
LAB_10004f1a:
  FUN_10003884();
  return eStack_14;
}



// Function: _wcslen at 10004fb0

/* Library Function - Single Match
    _wcslen
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release,
   Visual Studio 2019 Release */

size_t __cdecl _wcslen(wchar_t *_Str)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  
  pwVar2 = _Str;
  do {
    wVar1 = *pwVar2;
    pwVar2 = pwVar2 + 1;
  } while (wVar1 != L'\0');
  return ((int)pwVar2 - (int)_Str >> 1) - 1;
}



// Function: _wcscpy_s at 10004fcb

/* Library Function - Single Match
    _wcscpy_s
   
   Library: Visual Studio 2010 Release */

errno_t __cdecl _wcscpy_s(wchar_t *_Dst,rsize_t _SizeInWords,wchar_t *_Src)

{
  wchar_t wVar1;
  int *piVar2;
  int iVar3;
  errno_t eStack_10;
  
  if ((_Dst != (wchar_t *)0x0) && (_SizeInWords != 0)) {
    if (_Src != (wchar_t *)0x0) {
      iVar3 = (int)_Dst - (int)_Src;
      do {
        wVar1 = *_Src;
        *(wchar_t *)(iVar3 + (int)_Src) = wVar1;
        _Src = _Src + 1;
        if (wVar1 == L'\0') break;
        _SizeInWords = _SizeInWords - 1;
      } while (_SizeInWords != 0);
      if (_SizeInWords != 0) {
        return 0;
      }
      *_Dst = L'\0';
      piVar2 = __errno();
      eStack_10 = 0x22;
      *piVar2 = 0x22;
      goto LAB_10004fea;
    }
    *_Dst = L'\0';
  }
  piVar2 = __errno();
  eStack_10 = 0x16;
  *piVar2 = 0x16;
LAB_10004fea:
  FUN_10003884();
  return eStack_10;
}



// Function: __set_error_mode at 1000502e

/* Library Function - Single Match
    __set_error_mode
   
   Library: Visual Studio 2010 Release */

int __cdecl __set_error_mode(int _Mode)

{
  int iVar1;
  int *piVar2;
  
  if (-1 < _Mode) {
    if (_Mode < 3) {
      iVar1 = DAT_10008b2c;
      DAT_10008b2c = _Mode;
      return iVar1;
    }
    if (_Mode == 3) {
      return DAT_10008b2c;
    }
  }
  piVar2 = __errno();
  *piVar2 = 0x16;
  FUN_10003884();
  return -1;
}



// Function: ___report_gsfailure at 1000506d

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
  
  _DAT_10009588 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_1000958c = &stack0x00000004;
  _DAT_100094c8 = 0x10001;
  _DAT_10009470 = 0xc0000409;
  _DAT_10009474 = 1;
  local_32c = DAT_10008a80;
  local_328 = DAT_10008a84;
  _DAT_1000947c = unaff_retaddr;
  _DAT_10009554 = in_GS;
  _DAT_10009558 = in_FS;
  _DAT_1000955c = in_ES;
  _DAT_10009560 = in_DS;
  _DAT_10009564 = unaff_EDI;
  _DAT_10009568 = unaff_ESI;
  _DAT_1000956c = unaff_EBX;
  _DAT_10009570 = in_EDX;
  _DAT_10009574 = in_ECX;
  _DAT_10009578 = in_EAX;
  _DAT_1000957c = unaff_EBP;
  DAT_10009580 = unaff_retaddr;
  _DAT_10009584 = in_CS;
  _DAT_10009590 = in_SS;
  DAT_100094c0 = IsDebuggerPresent();
  FUN_10004cf1();
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_100077ec);
  if (DAT_100094c0 == 0) {
    FUN_10004cf1();
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __global_unwind2 at 10005180

/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x10005198,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}



// Function: __local_unwind2 at 100051e5

/* Library Function - Single Match
    __local_unwind2
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __cdecl __local_unwind2(int param_1,uint param_2)

{
  uint uVar1;
  void *local_20;
  undefined1 *puStack_1c;
  undefined4 local_18;
  int iStack_14;
  
  iStack_14 = param_1;
  puStack_1c = &LAB_100051a0;
  local_20 = ExceptionList;
  ExceptionList = &local_20;
  while( true ) {
    uVar1 = *(uint *)(param_1 + 0xc);
    if ((uVar1 == 0xffffffff) || ((param_2 != 0xffffffff && (uVar1 <= param_2)))) break;
    local_18 = *(undefined4 *)(*(int *)(param_1 + 8) + uVar1 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_18;
    if (*(int *)(*(int *)(param_1 + 8) + 4 + uVar1 * 0xc) == 0) {
      __NLG_Notify(0x101);
      FUN_100052b4();
    }
  }
  ExceptionList = local_20;
  return;
}



// Function: __NLG_Notify at 10005295

/* Library Function - Single Match
    __NLG_Notify
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __NLG_Notify(ulong param_1)

{
  undefined4 in_EAX;
  undefined4 unaff_EBP;
  
  DAT_10008b18 = param_1;
  DAT_10008b14 = in_EAX;
  DAT_10008b1c = unaff_EBP;
  return;
}



// Function: FUN_100052b4 at 100052b4

void FUN_100052b4(void)

{
  code *in_EAX;
  
  (*in_EAX)();
  return;
}



// Function: __VEC_memzero at 100052b7

/* Library Function - Single Match
    __VEC_memzero
   
   Libraries: Visual Studio 2010 Debug, Visual Studio 2010 Release */

undefined1 (*) [16] __fastcall __VEC_memzero(undefined1 (*param_1) [16],uint param_2)

{
  uint uVar1;
  undefined1 (*pauVar2) [16];
  uint uVar3;
  
  pauVar2 = param_1;
  if (((uint)param_1 & 0xf) != 0) {
    uVar3 = 0x10 - ((uint)param_1 & 0xf);
    param_2 = param_2 - uVar3;
    for (uVar1 = uVar3 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
      (*pauVar2)[0] = 0;
      pauVar2 = (undefined1 (*) [16])(*pauVar2 + 1);
    }
    for (uVar3 = uVar3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)*pauVar2 = 0;
      pauVar2 = (undefined1 (*) [16])(*pauVar2 + 4);
    }
  }
  for (uVar1 = param_2 >> 7; uVar1 != 0; uVar1 = uVar1 - 1) {
    *pauVar2 = (undefined1  [16])0x0;
    pauVar2[1] = (undefined1  [16])0x0;
    pauVar2[2] = (undefined1  [16])0x0;
    pauVar2[3] = (undefined1  [16])0x0;
    pauVar2[4] = (undefined1  [16])0x0;
    pauVar2[5] = (undefined1  [16])0x0;
    pauVar2[6] = (undefined1  [16])0x0;
    pauVar2[7] = (undefined1  [16])0x0;
    pauVar2 = pauVar2 + 8;
  }
  if ((param_2 & 0x7f) != 0) {
    for (uVar1 = (param_2 & 0x7f) >> 4; uVar1 != 0; uVar1 = uVar1 - 1) {
      *pauVar2 = (undefined1  [16])0x0;
      pauVar2 = pauVar2 + 1;
    }
    if ((param_2 & 0xf) != 0) {
      for (uVar1 = (param_2 & 0xf) >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
        *(undefined4 *)*pauVar2 = 0;
        pauVar2 = (undefined1 (*) [16])(*pauVar2 + 4);
      }
      for (uVar1 = param_2 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
        (*pauVar2)[0] = 0;
        pauVar2 = (undefined1 (*) [16])(*pauVar2 + 1);
      }
    }
  }
  return param_1;
}



// Function: __alloca_probe_16 at 10005390

/* WARNING: This is an inlined function */
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* Library Function - Single Match
    __alloca_probe_16
   
   Library: Visual Studio 2010 Release */

uint __alloca_probe_16(void)

{
  uint in_EAX;
  uint uVar1;
  
  uVar1 = 4 - in_EAX & 0xf;
  return in_EAX + uVar1 | -(uint)CARRY4(in_EAX,uVar1);
}



// Function: __alloca_probe_8 at 100053a6

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



// Function: FUN_100053bc at 100053bc

undefined4 * __fastcall FUN_100053bc(uint param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  uint uVar16;
  uint uVar17;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  undefined4 *puVar18;
  
  puVar18 = unaff_EDI;
  if (((uint)unaff_ESI & 0xf) != 0) {
    uVar17 = 0x10 - ((uint)unaff_ESI & 0xf);
    param_1 = param_1 - uVar17;
    for (uVar16 = uVar17 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
      *(undefined1 *)puVar18 = *(undefined1 *)unaff_ESI;
      unaff_ESI = (undefined4 *)((int)unaff_ESI + 1);
      puVar18 = (undefined4 *)((int)puVar18 + 1);
    }
    for (uVar17 = uVar17 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
      *puVar18 = *unaff_ESI;
      unaff_ESI = unaff_ESI + 1;
      puVar18 = puVar18 + 1;
    }
  }
  for (uVar16 = param_1 >> 7; uVar16 != 0; uVar16 = uVar16 - 1) {
    uVar1 = unaff_ESI[1];
    uVar2 = unaff_ESI[2];
    uVar3 = unaff_ESI[3];
    uVar4 = unaff_ESI[4];
    uVar5 = unaff_ESI[5];
    uVar6 = unaff_ESI[6];
    uVar7 = unaff_ESI[7];
    uVar8 = unaff_ESI[8];
    uVar9 = unaff_ESI[9];
    uVar10 = unaff_ESI[10];
    uVar11 = unaff_ESI[0xb];
    uVar12 = unaff_ESI[0xc];
    uVar13 = unaff_ESI[0xd];
    uVar14 = unaff_ESI[0xe];
    uVar15 = unaff_ESI[0xf];
    *puVar18 = *unaff_ESI;
    puVar18[1] = uVar1;
    puVar18[2] = uVar2;
    puVar18[3] = uVar3;
    puVar18[4] = uVar4;
    puVar18[5] = uVar5;
    puVar18[6] = uVar6;
    puVar18[7] = uVar7;
    puVar18[8] = uVar8;
    puVar18[9] = uVar9;
    puVar18[10] = uVar10;
    puVar18[0xb] = uVar11;
    puVar18[0xc] = uVar12;
    puVar18[0xd] = uVar13;
    puVar18[0xe] = uVar14;
    puVar18[0xf] = uVar15;
    uVar1 = unaff_ESI[0x11];
    uVar2 = unaff_ESI[0x12];
    uVar3 = unaff_ESI[0x13];
    uVar4 = unaff_ESI[0x14];
    uVar5 = unaff_ESI[0x15];
    uVar6 = unaff_ESI[0x16];
    uVar7 = unaff_ESI[0x17];
    uVar8 = unaff_ESI[0x18];
    uVar9 = unaff_ESI[0x19];
    uVar10 = unaff_ESI[0x1a];
    uVar11 = unaff_ESI[0x1b];
    uVar12 = unaff_ESI[0x1c];
    uVar13 = unaff_ESI[0x1d];
    uVar14 = unaff_ESI[0x1e];
    uVar15 = unaff_ESI[0x1f];
    puVar18[0x10] = unaff_ESI[0x10];
    puVar18[0x11] = uVar1;
    puVar18[0x12] = uVar2;
    puVar18[0x13] = uVar3;
    puVar18[0x14] = uVar4;
    puVar18[0x15] = uVar5;
    puVar18[0x16] = uVar6;
    puVar18[0x17] = uVar7;
    puVar18[0x18] = uVar8;
    puVar18[0x19] = uVar9;
    puVar18[0x1a] = uVar10;
    puVar18[0x1b] = uVar11;
    puVar18[0x1c] = uVar12;
    puVar18[0x1d] = uVar13;
    puVar18[0x1e] = uVar14;
    puVar18[0x1f] = uVar15;
    unaff_ESI = unaff_ESI + 0x20;
    puVar18 = puVar18 + 0x20;
  }
  if ((param_1 & 0x7f) != 0) {
    for (uVar16 = (param_1 & 0x7f) >> 4; uVar16 != 0; uVar16 = uVar16 - 1) {
      uVar1 = unaff_ESI[1];
      uVar2 = unaff_ESI[2];
      uVar3 = unaff_ESI[3];
      *puVar18 = *unaff_ESI;
      puVar18[1] = uVar1;
      puVar18[2] = uVar2;
      puVar18[3] = uVar3;
      unaff_ESI = unaff_ESI + 4;
      puVar18 = puVar18 + 4;
    }
    if ((param_1 & 0xf) != 0) {
      for (uVar16 = (param_1 & 0xf) >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
        *puVar18 = *unaff_ESI;
        unaff_ESI = unaff_ESI + 1;
        puVar18 = puVar18 + 1;
      }
      for (uVar16 = param_1 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
        *(undefined1 *)puVar18 = *(undefined1 *)unaff_ESI;
        unaff_ESI = (undefined4 *)((int)unaff_ESI + 1);
        puVar18 = (undefined4 *)((int)puVar18 + 1);
      }
    }
  }
  return unaff_EDI;
}



// Function: __alloca_probe at 100054c0

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



