/*
 * Decompiled from: UserManager.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001000 at 10001000

short * __cdecl FUN_10001000(short *param_1,short param_2,int param_3)

{
  if (param_3 != 0) {
    do {
      if (*param_1 == param_2) {
        return param_1;
      }
      param_1 = param_1 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return (short *)0x0;
}



// Function: FUN_10001021 at 10001021

int __cdecl FUN_10001021(ushort *param_1,ushort *param_2,int param_3)

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



// Function: AfxCrtErrorCheck at 10001055

/* Library Function - Single Match
    int __cdecl AfxCrtErrorCheck(int)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release,
   Visual Studio 2015 Release */

int __cdecl AfxCrtErrorCheck(int param_1)

{
  int extraout_EAX;
  int extraout_EAX_00;
  
  if (param_1 != 0) {
    if (param_1 == 0xc) {
      AfxThrowMemoryException();
      return extraout_EAX_00;
    }
    if (((param_1 == 0x16) || (param_1 == 0x22)) || (param_1 != 0x50)) {
      AfxThrowInvalidArgException();
      return extraout_EAX;
    }
  }
  return param_1;
}



// Function: AtlMultiply<unsigned_long> at 1000107f

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



// Function: AtlW2AHelper at 100010a1

/* Library Function - Multiple Matches With Same Base Name
    char * __stdcall AtlW2AHelper(char *,unsigned short const *,int,unsigned int)
    char * __stdcall AtlW2AHelper(char *,wchar_t const *,int,unsigned int)
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release,
   Visual Studio 2010 Release */

uint AtlW2AHelper(LPSTR param_1,LPCWSTR param_2,int param_3,UINT param_4)

{
  int iVar1;
  uint uVar2;
  
  if ((param_1 == (LPSTR)0x0) || (param_2 == (LPCWSTR)0x0)) {
    uVar2 = 0;
  }
  else {
    *param_1 = '\0';
    iVar1 = WideCharToMultiByte(param_4,0,param_2,-1,param_1,param_3,(LPCSTR)0x0,(LPBOOL)0x0);
    uVar2 = -(uint)(iVar1 != 0) & (uint)param_1;
  }
  return uVar2;
}



// Function: FUN_100010d9 at 100010d9

void FUN_100010d9(int param_1)

{
  code *pcVar1;
  
  if (param_1 == -0x7ff8fff2) {
    AfxThrowMemoryException();
  }
  AfxThrowOleException(param_1);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



// Function: FUN_100010f3 at 100010f3

void __cdecl FUN_100010f3(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  AfxCrtErrorCheck(eVar1);
  return;
}



// Function: FUN_10001113 at 10001113

int * FUN_10001113(int *param_1,int *param_2)

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



// Function: FUN_10001146 at 10001146

int __thiscall FUN_10001146(void *this,undefined4 param_1)

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



// Function: FUN_10001188 at 10001188

void __cdecl FUN_10001188(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  if (param_3 == 0) {
    param_3 = param_2;
  }
  Ordinal_147(param_3,param_2,param_4,0,param_1);
  return;
}



// Function: operator== at 100011a9

/* Library Function - Single Match
    public: bool __thiscall ATL::CComBSTR::operator==(class ATL::CComBSTR const &)const 
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release,
   Visual Studio 2015 Release */

bool __thiscall ATL::CComBSTR::operator==(CComBSTR *this,CComBSTR *param_1)

{
  int iVar1;
  
  iVar1 = Ordinal_314(*(undefined4 *)this,*(undefined4 *)param_1,0x400,0);
  return (bool)('\x01' - (iVar1 != 1));
}



// Function: FUN_100011c9 at 100011c9

void __fastcall FUN_100011c9(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FID_conflict:RegOpenKeyExA at 100011d2

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
                    /* WARNING: Could not recover jumptable at 0x1000121b. Too many branches */
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



// Function: FUN_10001229 at 10001229

void __thiscall FUN_10001229(void *this,LPCOLESTR param_1,LPUNKNOWN param_2,DWORD param_3)

{
  HRESULT HVar1;
  CLSID local_18;
  uint local_8;
  
  local_8 = DAT_10028e44 ^ (uint)&stack0xfffffffc;
  HVar1 = CLSIDFromProgID(param_1,&local_18);
  if (-1 < HVar1) {
    CoCreateInstance(&local_18,param_2,param_3,(IID *)&DAT_1001d9a4,(LPVOID *)this);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10001276 at 10001276

uint FUN_10001276(byte param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((param_1 & 1) == 0) {
    uVar1 = 4;
  }
  if ((param_1 & 2) == 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 0x10;
  }
  return uVar1;
}



// Function: FUN_100012a2 at 100012a2

void __fastcall FUN_100012a2(undefined4 *param_1)

{
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  return;
}



// Function: FUN_100012a9 at 100012a9

undefined4 * __thiscall FUN_100012a9(void *this,byte param_1)

{
  FUN_100012a2((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100012c8 at 100012c8

void __fastcall FUN_100012c8(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  
  puVar1 = (undefined4 *)*param_1;
  if (*(char *)((int)puVar1 + 0x49) != '\0') {
    *param_1 = puVar1[2];
    return;
  }
  piVar2 = (int *)*puVar1;
  if (*(char *)((int)*puVar1 + 0x49) == '\0') {
    do {
      piVar3 = piVar2;
      piVar2 = (int *)piVar3[2];
    } while (*(char *)(piVar3[2] + 0x49) == '\0');
  }
  else {
    for (piVar3 = (int *)puVar1[1]; (*(char *)((int)piVar3 + 0x49) == '\0' && (*param_1 == *piVar3))
        ; piVar3 = (int *)piVar3[1]) {
      *param_1 = (int)piVar3;
    }
    if (*(char *)(*param_1 + 0x49) != '\0') {
      return;
    }
  }
  *param_1 = (int)piVar3;
  return;
}



// Function: FUN_1000130e at 1000130e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_1000130e(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
  }
  return &LAB_100181a1;
}



// Function: Close at 1000133a

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



// Function: Open at 10001355

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



// Function: FUN_100013a4 at 100013a4

LSTATUS __thiscall FUN_100013a4(void *this,LPBYTE param_1,LPCWSTR param_2,LPDWORD param_3)

{
  short sVar1;
  LPDWORD lpcbData;
  LSTATUS LVar2;
  uint uVar3;
  
  lpcbData = param_3;
  if (param_3 == (LPDWORD)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_100010d9(-0x7fffbffb);
  }
  param_3 = (LPDWORD)0x0;
                    /* WARNING: Load size is inaccurate */
  LVar2 = RegQueryValueExW(*this,param_2,(LPDWORD)0x0,(LPDWORD)&param_3,param_1,lpcbData);
  if (param_1 == (LPBYTE)0x0) {
    return LVar2;
  }
  uVar3 = *lpcbData;
  if (uVar3 == 0) {
    param_1[0] = '\0';
    param_1[1] = '\0';
    return LVar2;
  }
  if (param_3 != (LPDWORD)0x0) {
    if (param_3 < (LPDWORD)0x3) {
      if ((uVar3 & 1) != 0) goto LAB_1000141d;
      sVar1 = *(short *)(param_1 + ((uVar3 & 0xfffffffe) - 2));
    }
    else {
      if ((((param_3 != (LPDWORD)0x7) || ((uVar3 & 1) != 0)) || (uVar3 = uVar3 >> 1, uVar3 == 0)) ||
         (*(short *)(param_1 + uVar3 * 2 + -2) != 0)) goto LAB_1000141d;
      if (uVar3 < 2) {
        return LVar2;
      }
      sVar1 = *(short *)(param_1 + uVar3 * 2 + -4);
    }
    if (sVar1 == 0) {
      return LVar2;
    }
  }
LAB_1000141d:
  param_1[0] = '\0';
  param_1[1] = '\0';
  return 0xd;
}



// Function: FUN_10001479 at 10001479

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

exception * __thiscall FUN_10001479(void *this,byte param_1)

{
  *(undefined ***)this = std::bad_alloc::vftable;
  std::exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (exception *)this;
}



// Function: FUN_100014b1 at 100014b1

void __fastcall FUN_100014b1(int *param_1)

{
  int *_Memory;
  
  while (*param_1 != 0) {
    _Memory = (int *)*param_1;
    *param_1 = *_Memory;
    free(_Memory);
  }
  return;
}



// Function: _Inside at 100014cb

/* Library Function - Single Match
    public: bool __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::_Inside(char const *)
   
   Library: Visual Studio 2010 Release */

bool __thiscall
std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Inside
          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this,
          char *param_1)

{
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar1;
  
  if (param_1 != (char *)0x0) {
    pbVar1 = this;
    if (0xf < *(uint *)(this + 0x14)) {
      pbVar1 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                this;
    }
    if (pbVar1 <= param_1) {
      pbVar1 = this;
      if (0xf < *(uint *)(this + 0x14)) {
        pbVar1 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  this;
      }
      if (param_1 < pbVar1 + *(int *)(this + 0x10)) {
        return true;
      }
    }
  }
  return false;
}



// Function: FID_conflict:_Inside at 10001506

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



// Function: AtlAdd<> at 10001542

/* Library Function - Multiple Matches With Same Base Name
    long __cdecl ATL::AtlAdd<unsigned int>(unsigned int *,unsigned int,unsigned int)
    long __cdecl ATL::AtlAdd<unsigned long>(unsigned long *,unsigned long,unsigned long)
   
   Library: Visual Studio 2010 Release */

undefined4 __cdecl AtlAdd<>(int *param_1,int param_2,uint param_3)

{
  if (-param_2 - 1U < param_3) {
    return 0x80070216;
  }
  *param_1 = param_2 + param_3;
  return 0;
}



// Function: FUN_10001566 at 10001566

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_10001566(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10001572;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10021060);
}



// Function: FUN_100015c5 at 100015c5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __cdecl FUN_100015c5(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x100015d1;
  if ((param_1 != (char *)0x0) && (pvVar1 = operator_new((uint)param_1), pvVar1 == (void *)0x0)) {
    param_1 = (char *)0x0;
    std::exception::exception((exception *)local_1c,&param_1);
    local_1c[0] = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10021060);
  }
  return;
}



// Function: FUN_10001651 at 10001651

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

LPWSTR __cdecl FUN_10001651(LPCSTR param_1,int param_2)

{
  int cchWideChar;
  LPWSTR lpWideCharStr;
  int iVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  if ((param_1 == (LPCSTR)0x0) || (param_2 == 0)) {
LAB_100016c2:
    lpWideCharStr = (LPWSTR)0x0;
  }
  else {
    local_14[0] = 0;
    local_8 = 0;
    cchWideChar = MultiByteToWideChar(3,0,param_1,param_2,(LPWSTR)0x0,0);
    iVar1 = cchWideChar;
    if (param_2 == -1) {
      iVar1 = cchWideChar + -1;
    }
    lpWideCharStr = (LPWSTR)Ordinal_4(0,iVar1);
    if (lpWideCharStr != (LPWSTR)0x0) {
      iVar1 = MultiByteToWideChar(3,0,param_1,param_2,lpWideCharStr,cchWideChar);
      if (iVar1 != cchWideChar) {
        Ordinal_6(lpWideCharStr);
        local_8 = 0xffffffff;
        FUN_100014b1(local_14);
        goto LAB_100016c2;
      }
    }
    local_8 = 0xffffffff;
    FUN_100014b1(local_14);
  }
  return lpWideCharStr;
}



// Function: FUN_100016db at 100016db

int * __thiscall FUN_100016db(void *this,int param_1)

{
  int iVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (param_1 != *this) {
    Ordinal_6(*this);
    if (param_1 == 0) {
      *(undefined4 *)this = 0;
    }
    else {
      iVar1 = Ordinal_2(param_1);
      *(int *)this = iVar1;
      if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_100010d9(-0x7ff8fff2);
      }
    }
  }
  return (int *)this;
}



// Function: FUN_10001718 at 10001718

void __fastcall FUN_10001718(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == 0) {
    return;
  }
  uVar1 = Ordinal_149(*param_1);
  Ordinal_150(*param_1,uVar1);
  return;
}



// Function: FUN_10001735 at 10001735

long __thiscall FUN_10001735(void *this,void *param_1,uint param_2)

{
  ulong uVar1;
  int iVar2;
  long lVar3;
  void *pvVar4;
  ulong local_10;
  ulong local_c;
  ulong local_8;
  
                    /* WARNING: Load size is inaccurate */
  if ((param_1 != (void *)0x0) && ((*this == 0 || (param_2 != 0)))) {
    if ((int)param_2 < 0) {
      return -0x7ff8ffa9;
    }
    uVar1 = Ordinal_7(*this);
    local_c = 0;
    local_8 = 0;
    local_10 = 0;
    iVar2 = AtlAdd<>((int *)&local_8,uVar1,param_2);
    if (iVar2 < 0) {
      return iVar2;
    }
    lVar3 = ATL::AtlMultiply<unsigned_long>(&local_10,local_8,2);
    if (lVar3 < 0) {
      return lVar3;
    }
    lVar3 = ATL::AtlMultiply<unsigned_long>(&local_c,uVar1,2);
    if (lVar3 < 0) {
      return lVar3;
    }
    pvVar4 = (void *)Ordinal_4(0,local_8);
    if (pvVar4 == (void *)0x0) {
      return -0x7ff8fff2;
    }
                    /* WARNING: Load size is inaccurate */
    iVar2 = Ordinal_7(*this);
    if (iVar2 != 0) {
                    /* WARNING: Load size is inaccurate */
      FUN_100010f3(pvVar4,local_10,*this,local_c);
    }
    FUN_100010f3((void *)((int)pvVar4 + uVar1 * 2),param_2 * 2,param_1,param_2 * 2);
    *(undefined2 *)((int)pvVar4 + local_8 * 2) = 0;
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this);
    *(void **)this = pvVar4;
  }
  return 0;
}



// Function: FUN_10001821 at 10001821

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

bool __thiscall FUN_10001821(void *this,int param_1)

{
  bool bVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined4 uStack_28;
  int iStack_24;
  undefined1 auStack_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0;
  local_8 = 0x1000182d;
  puVar3 = (undefined4 *)auStack_20;
  if (param_1 == 0) {
    param_1 = 0;
  }
  else {
    iStack_24 = param_1;
    puVar3 = &uStack_28;
    uStack_28 = 0x1000186a;
    param_1 = Ordinal_2();
    if (param_1 == 0) {
      puVar3[-1] = 0x8007000e;
                    /* WARNING: Subroutine does not return */
      puVar3[-2] = &UNK_1000187b;
      FUN_100010d9(puVar3[-1]);
    }
  }
  local_8 = 0;
  *(int **)((int)puVar3 + -4) = &param_1;
  *(undefined4 *)((int)puVar3 + -8) = 0x10001848;
  bVar1 = ATL::CComBSTR::operator==((CComBSTR *)this,*(CComBSTR **)((int)puVar3 + -4));
  local_8 = 0xffffffff;
  *(int *)((int)puVar3 + -4) = param_1;
  puVar2 = (undefined1 *)((int)puVar3 + -8);
  *(undefined4 *)((int)puVar3 + -8) = 0x10001857;
  Ordinal_6();
  *(undefined4 *)(puVar2 + -4) = 0x1000185e;
  return bVar1;
}



// Function: FUN_1000187c at 1000187c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000187c(undefined4 param_1,undefined4 *param_2)

{
  AFX_MODULE_STATE *pAVar1;
  AFX_MAINTAIN_STATE2 local_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x10001888;
  pAVar1 = (AFX_MODULE_STATE *)FUN_10014bb5();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_20,pAVar1);
  *param_2 = DAT_10028e78;
  local_8 = 0xffffffff;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_20);
  return 0;
}



// Function: CComBSTR at 100018bb

/* Library Function - Single Match
    public: __thiscall ATL::CComBSTR::CComBSTR(char const *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

CComBSTR * __thiscall ATL::CComBSTR::CComBSTR(CComBSTR *this,char *param_1)

{
  LPWSTR pWVar1;
  
  if (param_1 == (char *)0x0) {
    *(undefined4 *)this = 0;
  }
  else {
    pWVar1 = FUN_10001651(param_1,-1);
    *(LPWSTR *)this = pWVar1;
    if (pWVar1 == (LPWSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_100010d9(-0x7ff8fff2);
    }
  }
  return this;
}



// Function: FUN_100018ed at 100018ed

void __fastcall FUN_100018ed(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: FUN_100018f5 at 100018f5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100018f5(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000191a at 1000191a

undefined2 * __thiscall FUN_1000191a(void *this,int *param_1)

{
  int iVar1;
  
  iVar1 = Ordinal_9(this);
  if (-1 < iVar1) {
    *(undefined2 *)this = 8;
    iVar1 = FUN_10001718(param_1);
    *(int *)((int)this + 8) = iVar1;
    if ((iVar1 != 0) || (*param_1 == 0)) {
      return (undefined2 *)this;
    }
    *(undefined2 *)this = 10;
    iVar1 = -0x7ff8fff2;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
  }
                    /* WARNING: Subroutine does not return */
  FUN_100010d9(iVar1);
}



// Function: FUN_10001965 at 10001965

undefined2 * __thiscall FUN_10001965(void *this,int param_1)

{
  int iVar1;
  
  iVar1 = Ordinal_9(this);
  if (-1 < iVar1) {
    *(undefined2 *)this = 8;
    iVar1 = Ordinal_2(param_1);
    *(int *)((int)this + 8) = iVar1;
    if ((iVar1 != 0) || (param_1 == 0)) {
      return (undefined2 *)this;
    }
    *(undefined2 *)this = 10;
    iVar1 = -0x7ff8fff2;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
  }
                    /* WARNING: Subroutine does not return */
  FUN_100010d9(iVar1);
}



// Function: FUN_100019ae at 100019ae

/* Library Function - Multiple Matches With Same Base Name
    public: class std::_String_iterator<char,struct std::char_traits<char>,class
   std::allocator<char> > __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::end(void)
    public: class std::_String_iterator<class std::_String_val<struct std::_Simple_types<char> > >
   __thiscall std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>
   >::end(void)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall FUN_100019ae(void *this,int *param_1)

{
  void *pvVar1;
  
  pvVar1 = this;
  if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    pvVar1 = *this;
  }
  *param_1 = *(int *)((int)this + 0x10) + (int)pvVar1;
  return;
}



// Function: FUN_100019cb at 100019cb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100019cb(void *this,int *param_1)

{
  *(int **)this = param_1;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 4))(param_1);
  }
  return (undefined4 *)this;
}



// Function: FUN_100019f9 at 100019f9

uint __thiscall FUN_100019f9(void *this,ushort *param_1,uint param_2,uint param_3)

{
  ushort uVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  ushort *puVar5;
  ushort *puVar6;
  
  if (param_3 == 0) {
    if (*(uint *)((int)this + 0x10) <= param_2) {
      param_2 = *(uint *)((int)this + 0x10);
    }
  }
  else {
    if (param_3 <= *(uint *)((int)this + 0x10)) {
      uVar2 = *(uint *)((int)this + 0x10) - param_3;
      if (uVar2 <= param_2) {
        param_2 = uVar2;
      }
      pvVar3 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        pvVar3 = *this;
      }
      puVar6 = (ushort *)((int)pvVar3 + param_2 * 2);
      uVar1 = *param_1;
      while( true ) {
        if ((*puVar6 == uVar1) && (iVar4 = FUN_10001021(puVar6,param_1,param_3), iVar4 == 0)) {
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
            this = *this;
          }
          return (int)puVar6 - (int)this >> 1;
        }
        puVar5 = (ushort *)this;
        if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
          puVar5 = *this;
        }
        if (puVar6 == puVar5) break;
        puVar6 = puVar6 + -1;
      }
    }
    param_2 = 0xffffffff;
  }
  return param_2;
}



// Function: FUN_10001a85 at 10001a85

uint __thiscall FUN_10001a85(void *this,uint param_1,uint param_2,ushort *param_3,uint param_4)

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
  uVar1 = FUN_10001021((ushort *)((int)this + param_1 * 2),param_3,uVar1);
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



// Function: FUN_10001ae9 at 10001ae9

void __fastcall FUN_10001ae9(int param_1)

{
  operator_delete(*(void **)(param_1 + 4));
  return;
}



// Function: FUN_10001af3 at 10001af3

void __fastcall
FUN_10001af3(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *param_1)

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



// Function: FUN_10001b36 at 10001b36

uint __thiscall FUN_10001b36(void *this,uint param_1)

{
  uint uVar1;
  
                    /* WARNING: Load size is inaccurate */
  uVar1 = (*(int *)((int)this + 8) - *this) / 0x1c;
  if (0x9249249 - (uVar1 >> 1) < uVar1) {
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 + (uVar1 >> 1);
  }
  if (uVar1 < param_1) {
    uVar1 = param_1;
  }
  return uVar1;
}



// Function: FUN_10001b65 at 10001b65

void __fastcall FUN_10001b65(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if (*(char *)(iVar3 + 0x49) == '\0') {
    piVar1 = *(int **)(iVar3 + 8);
    if (*(char *)((int)*(int **)(iVar3 + 8) + 0x49) == '\0') {
      do {
        piVar2 = piVar1;
        piVar1 = (int *)*piVar2;
      } while (*(char *)((int)piVar1 + 0x49) == '\0');
      *param_1 = (int)piVar2;
      return;
    }
    for (iVar3 = *(int *)(iVar3 + 4);
        (*(char *)(iVar3 + 0x49) == '\0' && (*param_1 == *(int *)(iVar3 + 8)));
        iVar3 = *(int *)(iVar3 + 4)) {
      *param_1 = iVar3;
    }
    *param_1 = iVar3;
  }
  return;
}



// Function: FUN_10001ba0 at 10001ba0

void __thiscall FUN_10001ba0(void *this,int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x49) == '\0') {
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



// Function: FUN_10001be5 at 10001be5

void __thiscall FUN_10001be5(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x49) == '\0') {
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



// Function: FUN_10001c2c at 10001c2c

void __fastcall FUN_10001c2c(undefined4 *param_1)

{
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  param_1[3] = 0x80004005;
  return;
}



// Function: FUN_10001c46 at 10001c46

void __fastcall FUN_10001c46(undefined4 *param_1)

{
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  param_1[3] = 0x80004005;
  return;
}



// Function: FUN_10001c5e at 10001c5e

void __cdecl FUN_10001c5e(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  FUN_1000130e(param_2,param_3);
  return;
}



// Function: FUN_10001c71 at 10001c71

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_10001c71(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10001c7d;
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  if ((param_1 < (char *)0x924924a) &&
     (pvVar1 = operator_new((int)param_1 * 0x1c), pvVar1 != (void *)0x0)) {
    return pvVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_1c,&param_1);
  local_1c[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10021060);
}



// Function: FUN_10001cd0 at 10001cd0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_10001cd0(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10001cdc;
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  if ((param_1 < (char *)0x35e50d8) &&
     (pvVar1 = operator_new((int)param_1 * 0x4c), pvVar1 != (void *)0x0)) {
    return pvVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_1c,&param_1);
  local_1c[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10021060);
}



// Function: FUN_10001d2f at 10001d2f

LSTATUS __fastcall FUN_10001d2f(undefined4 *param_1)

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



// Function: FUN_10001d34 at 10001d34

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_10001d34(void *this,byte param_1)

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
    _eh_vector_destructor_iterator_(this,0xc,*piVar1,(_func_void_void_ptr *)&LAB_10001433);
    if ((param_1 & 1) != 0) {
      operator_delete__(piVar1);
    }
  }
  return piVar1;
}



// Function: FUN_10001d91 at 10001d91

int __thiscall FUN_10001d91(void *this,short *param_1,uint param_2,int param_3)

{
  uint uVar1;
  void *pvVar2;
  short *psVar3;
  int iVar4;
  short *psVar5;
  
  if ((param_3 == 0) || (uVar1 = *(uint *)((int)this + 0x10), uVar1 == 0)) {
LAB_10001dfa:
    iVar4 = -1;
  }
  else {
    if (uVar1 <= param_2) {
      param_2 = uVar1 - 1;
    }
    uVar1 = *(uint *)((int)this + 0x14);
    pvVar2 = this;
    if (7 < uVar1) {
                    /* WARNING: Load size is inaccurate */
      pvVar2 = *this;
    }
    psVar5 = (short *)((int)pvVar2 + param_2 * 2);
    while (psVar3 = FUN_10001000(param_1,*psVar5,param_3), psVar3 == (short *)0x0) {
      psVar3 = (short *)this;
      if (7 < uVar1) {
                    /* WARNING: Load size is inaccurate */
        psVar3 = *this;
      }
      if (psVar5 == psVar3) goto LAB_10001dfa;
      psVar5 = psVar5 + -1;
    }
    if (7 < uVar1) {
                    /* WARNING: Load size is inaccurate */
      this = *this;
    }
    iVar4 = (int)psVar5 - (int)this >> 1;
  }
  return iVar4;
}



// Function: FID_conflict:_Tidy at 10001e04

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



// Function: FUN_10001e4d at 10001e4d

undefined4 * __thiscall FUN_10001e4d(void *this,uint param_1,uint param_2)

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
    if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      pvVar4 = *this;
      pvVar3 = *this;
    }
    memmove((void *)((int)pvVar4 + param_1),(void *)((int)pvVar3 + param_2 + param_1),
            uVar1 - param_2);
    iVar2 = *(int *)((int)this + 0x10) - param_2;
    *(int *)((int)this + 0x10) = iVar2;
    pvVar3 = this;
    if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar3 = *this;
    }
    *(undefined1 *)((int)pvVar3 + iVar2) = 0;
  }
  return (undefined4 *)this;
}



// Function: FUN_10001ec7 at 10001ec7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __cdecl FUN_10001ec7(undefined4 *param_1,char param_2)

{
  LPCOLESTR pOVar1;
  
  *param_1 = 0;
  if (param_2 == '\0') {
    pOVar1 = (LPCOLESTR)Ordinal_2(L"Msxml2.DOMDocument.3.0");
  }
  else {
    pOVar1 = (LPCOLESTR)Ordinal_2(L"Microsoft.FreeThreadedXMLDOM");
  }
  if (pOVar1 == (LPCOLESTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_100010d9(-0x7ff8fff2);
  }
  FUN_10001229(param_1,pOVar1,(LPUNKNOWN)0x0,0x17);
  Ordinal_6(pOVar1);
  return param_1;
}



// Function: FUN_10001f4e at 10001f4e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __cdecl FUN_10001f4e(int *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (7 < (uint)param_2[5]) {
    param_2 = (undefined4 *)*param_2;
  }
  if (param_2 == (undefined4 *)0x0) {
    *param_1 = 0;
  }
  else {
    iVar1 = Ordinal_2(param_2);
    *param_1 = iVar1;
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_100010d9(-0x7ff8fff2);
    }
  }
  return param_1;
}



// Function: FUN_10001fa0 at 10001fa0

void __cdecl FUN_10001fa0(wchar_t *param_1)

{
  if (7 < *(uint *)(param_1 + 10)) {
    param_1 = *(wchar_t **)param_1;
  }
  _wtol(param_1);
  return;
}



// Function: FUN_10001fb8 at 10001fb8

void __fastcall FUN_10001fb8(int param_1)

{
  int *piVar1;
  
  if ((*(int *)(param_1 + 8) != 0) && (piVar1 = *(int **)(param_1 + 8), piVar1 != (int *)0x0)) {
    *(undefined4 *)(param_1 + 8) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10001fd0 at 10001fd0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __thiscall FUN_10001fd0(void *this,undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined1 *puVar5;
  uint uVar6;
  int iVar7;
  uint local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int local_28;
  int local_24;
  int *local_20;
  int *local_1c;
  int local_18;
  int *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  puVar5 = &LAB_10016076;
  local_8._0_1_ = 0xdc;
  local_8._1_3_ = 0x10001f;
  if (*(int *)((int)this + 8) != 0) {
    local_18 = Ordinal_2(L"/user_manager/users/user[@group=\"");
    if (local_18 == 0) {
LAB_10001ffb:
                    /* WARNING: Subroutine does not return */
      FUN_100010d9(-0x7ff8fff2);
    }
    local_8 = 0;
    FUN_10001146(&local_18,*param_1);
    uVar6 = lstrlenW(L"\"]");
    FUN_10001735(&local_18,&DAT_1001daac,uVar6);
    local_14[0] = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,2);
    iVar7 = (**(code **)(**(int **)((int)this + 8) + 0x90))
                      (*(int **)((int)this + 8),local_18,local_14);
    if (-1 < iVar7) {
      local_24 = 0;
      (**(code **)(*local_14[0] + 0x20))(local_14[0],&local_24);
      param_1 = (undefined4 *)0x0;
      if (0 < local_24) {
        do {
          local_20 = (int *)0x0;
          local_8._0_1_ = 4;
          (**(code **)(*local_14[0] + 0x1c))(local_14[0],param_1,&local_20);
          local_1c = (int *)0x0;
          local_8._0_1_ = 6;
          (**(code **)*local_20)(local_20,&DAT_1001da9c,&local_1c);
          local_38 = local_38 & 0xffff0000;
          FUN_1000191a(&local_38,param_2);
          piVar4 = local_1c;
          uVar3 = uStack_2c;
          uVar2 = uStack_30;
          uVar1 = uStack_34;
          uVar6 = local_38;
          local_8._0_1_ = 7;
          local_28 = Ordinal_2(L"group");
          if (local_28 == 0) goto LAB_10001ffb;
          local_8._0_1_ = 8;
          (**(code **)(*piVar4 + 0xb4))(piVar4,local_28,uVar6,uVar1,uVar2,uVar3);
          local_8._0_1_ = 7;
          Ordinal_6(local_28);
          local_8._0_1_ = 6;
          Ordinal_9(&local_38);
          local_8._0_1_ = 4;
          if (local_1c != (int *)0x0) {
            (**(code **)(*local_1c + 8))(local_1c);
          }
          local_8 = CONCAT31(local_8._1_3_,2);
          if (local_20 != (int *)0x0) {
            (**(code **)(*local_20 + 8))(local_20);
          }
          param_1 = (undefined4 *)((int)param_1 + 1);
        } while ((int)param_1 < local_24);
      }
    }
    local_8 = local_8 & 0xffffff00;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
    local_8 = 0xffffffff;
    puVar5 = (undefined1 *)Ordinal_6(local_18);
  }
  return puVar5;
}



// Function: FUN_1000215e at 1000215e

void __thiscall FUN_1000215e(void *this,ushort *param_1)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 + 8);
  if (7 < *(uint *)(param_1 + 10)) {
    param_1 = *(ushort **)param_1;
  }
  FUN_10001a85(this,0,*(uint *)((int)this + 0x10),param_1,*puVar1);
  return;
}



// Function: FUN_1000217f at 1000217f

void __thiscall FUN_1000217f(void *this,wchar_t *param_1)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_1);
  FUN_10001a85(this,0,*(uint *)((int)this + 0x10),(ushort *)param_1,sVar1);
  return;
}



// Function: FUN_100021a4 at 100021a4

int __thiscall FUN_100021a4(void *this,int *param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != (int *)*param_1) {
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(int *)this = *param_1;
    *param_1 = 0;
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_100021cd at 100021cd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall
FUN_100021cd(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *param_1)

{
  *(undefined ***)param_1 =
       std::
       basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  FUN_10001af3(param_1);
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>(param_1);
  return;
}



// Function: FUN_100021ff at 100021ff

ushort __fastcall
FUN_100021ff(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *param_1)

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
  iVar1 = **(int **)(param_1 + 0x20);
  iVar2 = **(int **)(param_1 + 0x30);
  puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                     (param_1);
  if ((ushort *)(iVar1 + iVar2 * 2) <= puVar4) {
    if ((((byte)param_1[0x40] & 4) == 0) &&
       (puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                           (param_1), puVar4 != (ushort *)0x0)) {
      puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                         (param_1);
      puVar5 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                         (param_1);
      if ((puVar5 < puVar4) ||
         (puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   gptr(param_1), puVar4 < *(ushort **)(param_1 + 0x3c))) {
        puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                           (param_1);
        if (*(ushort **)(param_1 + 0x3c) < puVar4) {
          puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   pptr(param_1);
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
    }
    return 0xffff;
  }
  puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                     (param_1);
  return *puVar4;
}



// Function: FUN_100022c4 at 100022c4

void __thiscall
FUN_100022c4(void *this,uint *param_1,uint param_2,uint param_3,int param_4,uint param_5)

{
  undefined4 uVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  
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
      if (param_2 == 0 && param_3 == 0) goto LAB_100024c0;
    }
    else {
      if (param_4 == 2) {
        iVar3 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
LAB_10002441:
        bVar6 = CARRY4(param_2,iVar3 >> 1);
        param_2 = param_2 + (iVar3 >> 1);
        param_3 = param_3 + (iVar3 >> 0x1f) + (uint)bVar6;
      }
      else {
        if (param_4 == 1) {
          iVar3 = **(int **)((int)this + 0x10);
          puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   pptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
          iVar3 = (int)puVar2 - iVar3;
          goto LAB_10002441;
        }
        if (param_4 != 0) {
          param_2 = *(uint *)_BADOFF_exref;
          param_3 = *(uint *)(_BADOFF_exref + 4);
        }
      }
      if (-1 < (int)param_3) {
        iVar3 = **(int **)((int)this + 0x10);
        iVar4 = *(int *)((int)this + 0x3c) - iVar3;
        iVar5 = iVar4 >> 0x1f;
        if (((int)param_3 <= iVar5) && (((int)param_3 < iVar5 || (param_2 <= (uint)(iVar4 >> 1)))))
        {
          puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   pptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
          std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pbump
                    ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                     this,(iVar3 - (int)puVar2 >> 1) + param_2);
          goto LAB_100024c0;
        }
      }
    }
  }
  else {
    if (param_4 == 2) {
      iVar3 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
LAB_10002333:
      bVar6 = CARRY4(param_2,iVar3 >> 1);
      param_2 = param_2 + (iVar3 >> 1);
      param_3 = param_3 + (iVar3 >> 0x1f) + (uint)bVar6;
    }
    else if (param_4 == 1) {
      if ((param_5 & 2) == 0) {
        iVar3 = **(int **)((int)this + 0x10);
        puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                           ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                             *)this);
        iVar3 = (int)puVar2 - iVar3;
        goto LAB_10002333;
      }
LAB_10002348:
      param_2 = *(uint *)_BADOFF_exref;
      param_3 = *(uint *)(_BADOFF_exref + 4);
    }
    else if (param_4 != 0) goto LAB_10002348;
    if (-1 < (int)param_3) {
      iVar3 = **(int **)((int)this + 0x10);
      iVar4 = *(int *)((int)this + 0x3c) - iVar3;
      iVar5 = iVar4 >> 0x1f;
      if (((int)param_3 <= iVar5) && (((int)param_3 < iVar5 || (param_2 <= (uint)(iVar4 >> 1))))) {
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
          iVar4 = **(int **)((int)this + 0x24);
          uVar1 = **(undefined4 **)((int)this + 0x14);
          puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   gptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
          **(undefined4 **)((int)this + 0x14) = uVar1;
          **(undefined4 **)((int)this + 0x24) = puVar2;
          **(int **)((int)this + 0x34) = (iVar4 + iVar3 * 2) - (int)puVar2 >> 1;
        }
        goto LAB_100024c0;
      }
    }
  }
  param_2 = *(uint *)_BADOFF_exref;
  param_3 = *(uint *)(_BADOFF_exref + 4);
LAB_100024c0:
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_100024da at 100024da

void __thiscall FUN_100024da(void *this,uint *param_1,uint param_2,int param_3,uint param_4)

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
      if ((((in_stack_00000020 & 2) != 0) &&
          (puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                    pptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *
                         )this), puVar3 != (ushort *)0x0)) && (-1 < (int)local_8)) {
        iVar1 = **(int **)((int)this + 0x10);
        iVar4 = *(int *)((int)this + 0x3c) - iVar1;
        iVar5 = iVar4 >> 0x1f;
        if (((int)local_8 <= iVar5) && (((int)local_8 < iVar5 || (uVar6 <= (uint)(iVar4 >> 1))))) {
          puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   pptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
          std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pbump
                    ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                     this,(iVar1 - (int)puVar3 >> 1) + uVar6);
          goto LAB_1000263a;
        }
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
        goto LAB_1000263a;
      }
    }
    uVar6 = *(uint *)_BADOFF_exref;
    local_8 = *(uint *)(_BADOFF_exref + 4);
  }
LAB_1000263a:
  *param_1 = uVar6;
  param_1[1] = local_8;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_10002657 at 10002657

ushort __thiscall FUN_10002657(void *this,ushort param_1)

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
  undefined4 *puVar10;
  uint uVar11;
  
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
      uVar11 = **(uint **)((int)this + 0x24);
      **(uint **)((int)this + 0x24) = (uint)puVar5;
      **(int **)((int)this + 0x34) = (int)((uVar11 + iVar3 * 2) - (int)puVar5) >> 1;
    }
  }
  if (param_1 == 0xffff) {
    return 0;
  }
  puVar5 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                     ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      this);
  if ((puVar5 != (ushort *)0x0) &&
     (iVar3 = **(int **)((int)this + 0x24), iVar4 = **(int **)((int)this + 0x34),
     puVar5 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                        ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *
                         )this), puVar5 < (ushort *)(iVar3 + iVar4 * 2))) {
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
    uVar11 = 0;
  }
  else {
    uVar11 = (**(int **)((int)this + 0x34) * 2 - **(int **)((int)this + 0x10)) +
             **(int **)((int)this + 0x24) >> 1;
  }
  uVar7 = uVar11 >> 1;
  if (uVar7 < 0x20) {
    uVar7 = 0x20;
  }
  else if (uVar7 == 0) {
    return 0xffff;
  }
  do {
    if (uVar11 <= 0x7fffffff - uVar7) break;
    uVar7 = uVar7 >> 1;
  } while (uVar7 != 0);
  if (uVar7 == 0) {
    return 0xffff;
  }
  pcVar8 = (char *)(uVar7 + uVar11);
  pvVar9 = FUN_10001566(pcVar8);
  _Src = (void *)**(undefined4 **)((int)this + 0x10);
  if ((uVar11 == 0) || (memcpy(pvVar9,_Src,uVar11 * 2), uVar11 == 0)) {
    *(void **)((int)this + 0x3c) = pvVar9;
    **(undefined4 **)((int)this + 0x14) = pvVar9;
    **(undefined4 **)((int)this + 0x24) = pvVar9;
    **(int **)((int)this + 0x34) = (int)pcVar8 * 2 >> 1;
    bVar2 = *(byte *)((int)this + 0x40);
    **(undefined4 **)((int)this + 0x10) = pvVar9;
    puVar10 = *(undefined4 **)((int)this + 0x20);
    if ((bVar2 & 4) == 0) {
      *puVar10 = pvVar9;
      **(undefined4 **)((int)this + 0x30) = 1;
      goto LAB_10002830;
    }
  }
  else {
    *(void **)((int)this + 0x3c) =
         (void *)((int)pvVar9 + (*(int *)((int)this + 0x3c) - (int)_Src >> 1) * 2);
    iVar3 = **(int **)((int)this + 0x14);
    puVar5 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
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
      goto LAB_10002830;
    }
    **(undefined4 **)((int)this + 0x10) = pvVar9;
    puVar10 = *(undefined4 **)((int)this + 0x20);
  }
  *puVar10 = 0;
  **(int **)((int)this + 0x30) = (int)pvVar9 >> 1;
LAB_10002830:
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



// Function: FUN_1000285c at 1000285c

ushort __thiscall FUN_1000285c(void *this,ushort param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  
  puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                     ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      this);
  if (((puVar1 != (ushort *)0x0) &&
      (puVar1 = (ushort *)**(uint **)((int)this + 0x10),
      puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this), puVar1 < puVar2)) &&
     ((param_1 == 0xffff ||
      ((puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                           ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                             *)this), param_1 == puVar1[-1] ||
       ((*(byte *)((int)this + 0x40) & 2) == 0)))))) {
    std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gbump
              ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this,-1);
    if (param_1 != 0xffff) {
      puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this);
      *puVar1 = param_1;
      return param_1;
    }
    return 0;
  }
  return 0xffff;
}



// Function: FUN_100028cf at 100028cf

basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> * __thiscall
FUN_100028cf(void *this,byte param_1)

{
  FUN_100021cd((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this;
}



// Function: FUN_100028ee at 100028ee

void __cdecl
FUN_100028ee(undefined4 *param_1,byte *param_2,byte *param_3,byte *param_4,byte param_5)

{
  for (; param_2 != param_3; param_2 = param_2 + 1) {
    *param_4 = *param_2 ^ param_5;
    param_4 = param_4 + 1;
  }
  *param_1 = param_4;
  return;
}



// Function: FUN_10002913 at 10002913

void __fastcall FUN_10002913(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_10001cd0((char *)0x1);
  *puVar1 = *(undefined4 *)(param_1 + 4);
  puVar1[1] = *(undefined4 *)(param_1 + 4);
  puVar1[2] = *(undefined4 *)(param_1 + 4);
  *(undefined2 *)(puVar1 + 0x12) = 0;
  return;
}



// Function: ~basic_string<> at 1000293a

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



// Function: FUN_10002944 at 10002944

undefined4 * __thiscall FUN_10002944(void *this,uint param_1,uint param_2)

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



// Function: _Tidy at 100029c5

/* Library Function - Single Match
    public: void __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::_Tidy(bool,unsigned int)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2019 Release */

void __thiscall
std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this,
          bool param_1,uint param_2)

{
  void *_Src;
  
  if ((param_1) && (0xf < *(uint *)(this + 0x14))) {
    _Src = *(void **)this;
    if (param_2 != 0) {
      memcpy(this,_Src,param_2);
    }
    operator_delete(_Src);
  }
  *(uint *)(this + 0x10) = param_2;
  *(undefined4 *)(this + 0x14) = 0xf;
  this[param_2] = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
  return;
}



// Function: FUN_10002a09 at 10002a09

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void __thiscall FUN_10002a09(void *this,uint param_1)

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
  FUN_10001566((char *)(param_1 + 1));
  FUN_10002a9e();
  return;
}



// Function: Catch@10002a70 at 10002a70

undefined * Catch_10002a70(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_10001566((char *)(iVar1 + 1));
  *(void **)(unaff_EBP + -0x18) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10002a98;
}



// Function: FUN_10002a9e at 10002a9e

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10002a9e(void)

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



// Function: Catch@10002aec at 10002aec

void Catch_10002aec(void)

{
  int unaff_EBP;
  
  FID_conflict__Tidy(*(void **)(unaff_EBP + -0x1c),'\x01',0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10002b01 at 10002b01

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void __thiscall FUN_10002b01(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 | 0xf;
  if (uVar3 != 0xffffffff) {
    uVar1 = *(uint *)((int)this + 0x14);
    uVar2 = uVar1 >> 1;
    param_1 = uVar3;
    if ((uVar3 / 3 < uVar2) && (param_1 = 0xfffffffe, uVar1 <= -uVar2 - 2)) {
      param_1 = uVar2 + uVar1;
    }
  }
  FUN_100015c5((char *)(param_1 + 1));
  FUN_10002b91();
  return;
}



// Function: Catch@10002b63 at 10002b63

undefined * Catch_10002b63(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar2 = FUN_100015c5((char *)(iVar1 + 1));
  *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10002b8b;
}



// Function: FUN_10002b91 at 10002b91

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10002b91(void)

{
  size_t _Size;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar1;
  int unaff_EBP;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *unaff_ESI;
  uint unaff_EDI;
  
  _Size = *(size_t *)(unaff_EBP + 0xc);
  if (_Size != 0) {
    pbVar1 = unaff_ESI;
    if (0xf < *(uint *)(unaff_ESI + 0x14)) {
      pbVar1 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                unaff_ESI;
    }
    memcpy(*(void **)(unaff_EBP + -0x18),pbVar1,_Size);
  }
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (unaff_ESI,true,0);
  pbVar1 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
            (unaff_EBP + -0x18);
  *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)unaff_ESI =
       pbVar1;
  *(uint *)(unaff_ESI + 0x14) = unaff_EDI;
  *(size_t *)(unaff_ESI + 0x10) = _Size;
  if (unaff_EDI < 0x10) {
    pbVar1 = unaff_ESI;
  }
  pbVar1[_Size] = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
  return;
}



// Function: Catch@10002bda at 10002bda

void Catch_10002bda(void)

{
  int unaff_EBP;
  
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
              (unaff_EBP + -0x1c),true,0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10002bef at 10002bef

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10002bef(undefined4 *param_1)

{
  *param_1 = CComErrorHandlerException::vftable;
  FID_conflict__Tidy(param_1 + 4,'\x01',0);
  return;
}



// Function: FUN_10002c1a at 10002c1a

undefined4 * __thiscall FUN_10002c1a(void *this,byte param_1)

{
  FUN_10002bef((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002c39 at 10002c39

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

float10 __cdecl FUN_10002c39(undefined4 *param_1)

{
  undefined2 local_28 [4];
  double local_20;
  double local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x10002c45;
  if (7 < (uint)param_1[5]) {
    param_1 = (undefined4 *)*param_1;
  }
  local_28[0] = 0;
  FUN_10001965(local_28,(int)param_1);
  local_8 = 0;
  FUN_10001188(5,(int)local_28,0,0x409);
  local_18 = local_20;
  local_8 = 0xffffffff;
  Ordinal_9(local_28);
  return (float10)local_18;
}



// Function: FUN_10002c95 at 10002c95

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10002c95(undefined2 *param_1)

{
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  *(undefined4 *)(param_1 + 0x18) = 7;
  *(undefined4 *)(param_1 + 0x16) = 0;
  param_1[0xe] = 0;
  return;
}



// Function: FUN_10002ccf at 10002ccf

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10002ccf(void *param_1)

{
  FID_conflict__Tidy((void *)((int)param_1 + 0x1c),'\x01',0);
  FID_conflict__Tidy(param_1,'\x01',0);
  return;
}



// Function: FUN_10002d05 at 10002d05

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10002d05(int param_1)

{
  FUN_10002ccf((void *)(param_1 + 4));
  return;
}



// Function: FUN_10002d26 at 10002d26

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10002d26(int param_1)

{
  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x60) + 4) + -0x60 + param_1) =
       std::
       basic_stringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  FUN_100021cd((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (param_1 + -0x48));
  std::basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (param_1 + -0x48));
  return;
}



// Function: FUN_10002d63 at 10002d63

undefined4 __thiscall FUN_10002d63(void *this,char *param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  if (param_1 == (char *)0x0) {
    uVar1 = 0;
  }
  else {
    if ((char *)0x9249249 < param_1) {
      std::_Xlength_error("vector<T> too long");
    }
    pvVar2 = FUN_10001c71(param_1);
    *(void **)this = pvVar2;
    *(void **)((int)this + 4) = pvVar2;
    *(void **)((int)this + 8) = (void *)((int)param_1 * 0x1c + (int)pvVar2);
    uVar1 = CONCAT31((int3)((uint)pvVar2 >> 8),1);
  }
  return uVar1;
}



// Function: FUN_10002db0 at 10002db0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> * __thiscall
FUN_10002db0(void *this,byte param_1)

{
  uint uVar1;
  
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this);
  *(undefined ***)this =
       std::
       basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  uVar1 = FUN_10001276(param_1);
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(uint *)((int)this + 0x40) = uVar1;
  return (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this;
}



// Function: FUN_10002df0 at 10002df0

int __fastcall FUN_10002df0(int param_1)

{
  void *pvVar1;
  
  *(undefined4 *)(param_1 + 8) = 0;
  pvVar1 = FUN_10001cd0((char *)0x1);
  *(void **)(param_1 + 4) = pvVar1;
  *(void **)pvVar1 = pvVar1;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x48) = 1;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x49) = 1;
  return param_1;
}



// Function: FUN_10002e27 at 10002e27

undefined4 * __cdecl
FUN_10002e27(undefined4 *param_1,byte *param_2,byte *param_3,byte *param_4,byte param_5)

{
  if (param_2 != param_3) {
    FUN_100028ee(param_1,param_2,param_3,param_4,param_5);
    return param_1;
  }
  *param_1 = param_4;
  return param_1;
}



// Function: FUN_10002e56 at 10002e56

void __fastcall
FUN_10002e56(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (param_1,true,0);
  return;
}



// Function: FUN_10002e60 at 10002e60

bool __thiscall FUN_10002e60(void *this,uint param_1,char param_2)

{
  uint uVar1;
  undefined4 *extraout_ECX;
  
  if (0x7ffffffe < param_1) {
    std::_Xlength_error("string too long");
    this = extraout_ECX;
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_10002a09(this,param_1);
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



// Function: FUN_10002eca at 10002eca

bool __thiscall FUN_10002eca(void *this,uint param_1,char param_2)

{
  uint uVar1;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *extraout_ECX;
  
  if (param_1 == 0xffffffff) {
    std::_Xlength_error("string too long");
    this = extraout_ECX;
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_10002b01(this,param_1);
  }
  else if ((param_2 == '\0') || (0xf < param_1)) {
    if (param_1 == 0) {
      *(undefined4 *)((int)this + 0x10) = 0;
      if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        this = *this;
      }
      *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this =
           (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
    }
  }
  else {
    uVar1 = *(uint *)((int)this + 0x10);
    if (param_1 < *(uint *)((int)this + 0x10)) {
      uVar1 = param_1;
    }
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this,
               true,uVar1);
  }
  return param_1 != 0;
}



// Function: FUN_10002f2f at 10002f2f

undefined4 * __thiscall FUN_10002f2f(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    bVar1 = FUN_10002e60(this,uVar2,'\0');
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



// Function: FUN_10002fd4 at 10002fd4

void __fastcall FUN_10002fd4(int param_1)

{
  FUN_10002d26(param_1 + 0x60);
                    /* WARNING: Could not recover jumptable at 0x10002fe2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)(param_1 + 0x60))
  ;
  return;
}



// Function: FUN_10002fe8 at 10002fe8

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10002fe8(byte *param_1,undefined4 param_2,byte *param_3)

{
  undefined4 *puVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  pbVar3 = param_3;
  if (0xf < *(uint *)(param_3 + 0x14)) {
    pbVar3 = *(byte **)param_3;
  }
  pbVar2 = param_1;
  if (0xf < *(uint *)(param_1 + 0x14)) {
    pbVar2 = *(byte **)param_1;
  }
  puVar1 = (undefined4 *)FUN_100019ae(param_1,(int *)&param_3);
  puVar1 = FUN_10002e27(&param_1,pbVar2,(byte *)*puVar1,pbVar3,(byte)param_2);
  return CONCAT31((int3)((uint)puVar1 >> 8),1);
}



// Function: Catch@10003045 at 10003045

undefined4 Catch_10003045(void)

{
  int unaff_EBP;
  
  *(undefined1 *)(unaff_EBP + -0x11) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000303a;
}



// Function: FUN_10003053 at 10003053

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003053(int param_1)

{
  FUN_10002ccf((void *)(param_1 + 4));
  return;
}



// Function: FUN_10003074 at 10003074

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_> * __thiscall
FUN_10003074(void *this,byte param_1,int param_2)

{
  if (param_2 != 0) {
    *(undefined **)this = &DAT_1001db58;
    *(undefined ***)((int)this + 0x10) = &PTR_1001db50;
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               ((int)this + 0x60));
  }
  std::basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             ((int)this + 0x18));
                    /* WARNING: Load size is inaccurate */
  *(undefined ***)((int)this + *(int *)(*this + 4)) =
       std::
       basic_stringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  FUN_10002db0((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               ((int)this + 0x18),param_1);
  return (basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this;
}



// Function: FUN_100030e3 at 100030e3

void * __thiscall FUN_100030e3(void *this,byte param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)((int)this + -0x60);
  FUN_10002fd4((int)pvVar1);
  if ((param_1 & 1) != 0) {
    operator_delete(pvVar1);
  }
  return pvVar1;
}



// Function: FUN_10003105 at 10003105

undefined4 * __thiscall FUN_10003105(void *this,undefined4 *param_1,uint param_2)

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
      bVar1 = FUN_10002e60(this,uVar2,'\0');
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
    this = FUN_10002f2f(this,(undefined4 *)this,(int)param_1 - (int)pvVar4 >> 1,param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_100031a7 at 100031a7

undefined4 * __thiscall FUN_100031a7(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    FUN_10002944(pvVar3,uVar4 + uVar2,0xffffffff);
    FUN_10002944(this,0,param_2);
  }
  else {
    bVar1 = FUN_10002e60(pvVar3,uVar4,'\0');
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



// Function: FUN_10003243 at 10003243

undefined4 * __thiscall
FUN_10003243(void *this,uint param_1,undefined4 *param_2,undefined4 *param_3,uint param_4,
            uint param_5)

{
  code *pcVar1;
  int iVar2;
  undefined4 *extraout_EAX;
  void *pvVar3;
  void *pvVar4;
  void *pvVar5;
  undefined4 *puVar6;
  void *pvVar7;
  uint uVar8;
  uint extraout_EDX;
  undefined4 *puVar9;
  
  uVar8 = *(uint *)((int)this + 0x10);
  if ((uVar8 < param_1) || ((uint)param_3[4] < param_4)) {
    std::_Xout_of_range("invalid string position");
    pcVar1 = (code *)swi(3);
    puVar9 = (undefined4 *)(*pcVar1)();
    return puVar9;
  }
  puVar9 = (undefined4 *)(uVar8 - param_1);
  if (puVar9 < param_2) {
    param_2 = puVar9;
  }
  puVar6 = (undefined4 *)(param_3[4] - param_4);
  if (puVar6 < param_5) {
    param_5 = (uint)puVar6;
  }
  uVar8 = uVar8 - (int)param_2;
  puVar6 = param_2;
  if (-param_5 - 1 <= uVar8) {
    std::_Xlength_error("string too long");
    puVar6 = extraout_EAX;
    uVar8 = extraout_EDX;
  }
  puVar9 = (undefined4 *)((int)puVar9 - (int)puVar6);
  uVar8 = uVar8 + param_5;
  if (*(uint *)((int)this + 0x10) < uVar8) {
    FUN_10002e60(this,uVar8,'\0');
    puVar6 = param_2;
  }
  if ((undefined4 *)this != param_3) {
    pvVar5 = this;
    param_2 = (undefined4 *)this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      param_2 = *this;
                    /* WARNING: Load size is inaccurate */
      pvVar5 = *this;
    }
    memmove((void *)((int)pvVar5 + (param_1 + param_5) * 2),
            (void *)((int)param_2 + ((int)puVar6 + param_1) * 2),(int)puVar9 * 2);
    if (7 < (uint)param_3[5]) {
      param_3 = (undefined4 *)*param_3;
    }
    pvVar5 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar5 = *this;
    }
    memcpy((void *)((int)pvVar5 + param_1 * 2),(void *)((int)param_3 + param_4 * 2),param_5 * 2);
    goto LAB_10003516;
  }
  pvVar4 = this;
  pvVar5 = this;
  if (puVar6 < param_5) {
    if (param_4 <= param_1) {
      pvVar7 = this;
      param_2 = (undefined4 *)this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        param_2 = *this;
                    /* WARNING: Load size is inaccurate */
        pvVar7 = *this;
      }
      memmove((void *)((int)pvVar7 + (param_1 + param_5) * 2),
              (void *)((int)param_2 + ((int)puVar6 + param_1) * 2),(int)puVar9 * 2);
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
        pvVar4 = *this;
        pvVar5 = *this;
      }
      goto LAB_1000338a;
    }
    if (param_4 < param_1 + (int)puVar6) {
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
        pvVar4 = *this;
        pvVar5 = *this;
      }
      memmove((void *)((int)pvVar4 + param_1 * 2),(void *)((int)pvVar5 + param_4 * 2),
              (int)puVar6 * 2);
      pvVar5 = this;
      param_3 = (undefined4 *)this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        param_3 = *this;
                    /* WARNING: Load size is inaccurate */
        pvVar5 = *this;
      }
      iVar2 = ((int)param_2 + param_1) * 2;
      memmove((void *)((int)pvVar5 + (param_1 + param_5) * 2),(void *)(iVar2 + (int)param_3),
              (int)puVar9 * 2);
      pvVar4 = this;
      pvVar5 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
        pvVar4 = *this;
        pvVar5 = *this;
      }
      memmove((void *)(iVar2 + (int)pvVar4),(void *)((int)pvVar5 + (param_4 + param_5) * 2),
              (param_5 - (int)param_2) * 2);
      goto LAB_10003516;
    }
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      pvVar4 = *this;
      pvVar5 = *this;
    }
    memmove((void *)((int)pvVar4 + (param_1 + param_5) * 2),
            (void *)((int)pvVar5 + (param_1 + (int)puVar6) * 2),(int)puVar9 * 2);
    pvVar4 = this;
    pvVar5 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      pvVar4 = *this;
      pvVar5 = *this;
    }
    pvVar5 = (void *)((int)pvVar5 + ((param_4 - (int)param_2) + param_5) * 2);
    pvVar4 = (void *)((int)pvVar4 + param_1 * 2);
  }
  else {
    pvVar3 = this;
    pvVar7 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      pvVar3 = *this;
      pvVar7 = *this;
    }
    memmove((void *)((int)pvVar3 + param_1 * 2),(void *)((int)pvVar7 + param_4 * 2),param_5 * 2);
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      pvVar4 = *this;
      pvVar5 = *this;
    }
    param_4 = (int)param_2 + param_1;
    param_1 = param_1 + param_5;
    param_5 = (uint)puVar9;
LAB_1000338a:
    pvVar5 = (void *)((int)pvVar5 + param_4 * 2);
    pvVar4 = (void *)((int)pvVar4 + param_1 * 2);
  }
  memmove(pvVar4,pvVar5,param_5 * 2);
LAB_10003516:
  *(uint *)((int)this + 0x10) = uVar8;
  pvVar5 = this;
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    pvVar5 = *this;
  }
  *(undefined2 *)((int)pvVar5 + uVar8 * 2) = 0;
  return (undefined4 *)this;
}



// Function: FID_conflict:assign at 10003546

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
    bVar1 = FUN_10002e60(this,param_2,'\0');
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
    this = FUN_100031a7(this,(undefined4 *)this,(int)param_1 - (int)pvVar3 >> 1,param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_100035c4 at 100035c4

undefined4 * __thiscall FUN_100035c4(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    bVar1 = FUN_10002eca(this,uVar2,'\0');
    if (bVar1) {
      if (0xf < (uint)param_1[5]) {
        param_1 = (undefined4 *)*param_1;
      }
      pvVar4 = this;
      if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        pvVar4 = *this;
      }
      memcpy((void *)(*(int *)((int)this + 0x10) + (int)pvVar4),(void *)((int)param_1 + param_2),
             param_3);
      *(uint *)((int)this + 0x10) = uVar2;
      pvVar4 = this;
      if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        pvVar4 = *this;
      }
      *(undefined1 *)((int)pvVar4 + uVar2) = 0;
    }
  }
  return (undefined4 *)this;
}



// Function: FUN_10003660 at 10003660

undefined4 * __thiscall FUN_10003660(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  uint extraout_EAX;
  uint uVar2;
  void *pvVar3;
  uint extraout_ECX;
  uint uVar4;
  uint _Size;
  
  uVar2 = param_1[4];
  uVar4 = param_2;
  if (uVar2 < param_2) {
    std::_Xout_of_range("invalid string position");
    uVar2 = extraout_EAX;
    uVar4 = extraout_ECX;
  }
  _Size = uVar2 - uVar4;
  if (param_3 < uVar2 - uVar4) {
    _Size = param_3;
  }
  if ((undefined4 *)this == param_1) {
    FUN_10001e4d(this,_Size + uVar4,0xffffffff);
    FUN_10001e4d(this,0,param_2);
  }
  else {
    bVar1 = FUN_10002eca(this,_Size,'\0');
    if (bVar1) {
      if (0xf < (uint)param_1[5]) {
        param_1 = (undefined4 *)*param_1;
      }
      pvVar3 = this;
      if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        pvVar3 = *this;
      }
      memcpy(pvVar3,(void *)((int)param_1 + param_2),_Size);
      *(uint *)((int)this + 0x10) = _Size;
      pvVar3 = this;
      if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        pvVar3 = *this;
      }
      *(undefined1 *)((int)pvVar3 + _Size) = 0;
    }
  }
  return (undefined4 *)this;
}



// Function: basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> at 100036fa

/* Library Function - Single Match
    public: __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >(class std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> > const &)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this,
          basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1)

{
  *(undefined4 *)(this + 0x14) = 0xf;
  *(undefined4 *)(this + 0x10) = 0;
  *this = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
  FUN_10003660(this,(undefined4 *)param_1,0,0xffffffff);
  return this;
}



// Function: FUN_10003720 at 10003720

undefined2 * __thiscall FUN_10003720(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)this = 0;
  FUN_100031a7(this,param_1,param_2,param_3);
  return (undefined2 *)this;
}



// Function: FUN_1000374b at 1000374b

undefined4 * __thiscall
FUN_1000374b(void *this,uint param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *extraout_EAX;
  void *pvVar4;
  void *pvVar5;
  uint extraout_ECX;
  
  uVar2 = FID_conflict__Inside(this,param_3);
  if ((char)uVar2 == '\0') {
    uVar2 = *(uint *)((int)this + 0x10);
    if (uVar2 < param_1) {
      std::_Xout_of_range("invalid string position");
      uVar2 = extraout_ECX;
    }
    puVar3 = (undefined4 *)(uVar2 - param_1);
    if (puVar3 < param_2) {
      param_2 = puVar3;
    }
    if (-(int)param_4 - 1U <= uVar2 - (int)param_2) {
      std::_Xlength_error("string too long");
      puVar3 = extraout_EAX;
    }
    if (param_4 < param_2) {
      pvVar4 = this;
      pvVar5 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
        pvVar4 = *this;
        pvVar5 = *this;
      }
      memmove((void *)((int)pvVar4 + ((int)param_4 + param_1) * 2),
              (void *)((int)pvVar5 + (param_1 + (int)param_2) * 2),((int)puVar3 - (int)param_2) * 2)
      ;
    }
    if ((param_4 != (undefined4 *)0x0) || (param_2 != (undefined4 *)0x0)) {
      uVar2 = (*(int *)((int)this + 0x10) - (int)param_2) + (int)param_4;
      bVar1 = FUN_10002e60(this,uVar2,'\0');
      if (bVar1) {
        if (param_2 < param_4) {
          pvVar4 = this;
          pvVar5 = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
            pvVar4 = *this;
            pvVar5 = *this;
          }
          memmove((void *)((int)pvVar4 + ((int)param_4 + param_1) * 2),
                  (void *)((int)pvVar5 + ((int)param_2 + param_1) * 2),
                  ((int)puVar3 - (int)param_2) * 2);
        }
        pvVar5 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
          pvVar5 = *this;
        }
        memcpy((void *)((int)pvVar5 + param_1 * 2),param_3,(int)param_4 * 2);
        *(uint *)((int)this + 0x10) = uVar2;
        pvVar5 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
          pvVar5 = *this;
        }
        *(undefined2 *)((int)pvVar5 + uVar2 * 2) = 0;
      }
    }
  }
  else {
    pvVar5 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar5 = *this;
    }
    this = FUN_10003243(this,param_1,param_2,(undefined4 *)this,(int)param_3 - (int)pvVar5 >> 1,
                        (uint)param_4);
  }
  return (undefined4 *)this;
}



// Function: basic_string<> at 100038aa

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >(unsigned short const
   *,unsigned int)
    public: __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >(wchar_t const *,unsigned int)
   
   Library: Visual Studio 2010 Release */

undefined2 * __thiscall basic_string<>(void *this,undefined4 *param_1,uint param_2)

{
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)this = 0;
  FID_conflict_assign(this,param_1,param_2);
  return (undefined2 *)this;
}



// Function: FUN_100038d2 at 100038d2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_100038d2(void *this,byte param_1)

{
  FUN_10002ccf((void *)((int)this + 4));
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: basic_string<> at 10003906

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
  FUN_100031a7(this,param_1,0,0xffffffff);
  return (undefined2 *)this;
}



// Function: FUN_1000392e at 1000392e

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
FUN_1000392e(void *this,char *param_1,uint param_2)

{
  uint uVar1;
  bool bVar2;
  int extraout_EAX;
  int iVar3;
  void *pvVar4;
  
  bVar2 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Inside
                    ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )this,param_1);
  if (bVar2) {
    pvVar4 = this;
    if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar4 = *this;
    }
    this = FUN_100035c4(this,(undefined4 *)this,(int)param_1 - (int)pvVar4,param_2);
  }
  else {
    iVar3 = *(int *)((int)this + 0x10);
    if (-iVar3 - 1U <= param_2) {
      std::_Xlength_error("string too long");
      iVar3 = extraout_EAX;
    }
    if (param_2 != 0) {
      uVar1 = iVar3 + param_2;
      bVar2 = FUN_10002eca(this,uVar1,'\0');
      if (bVar2) {
        pvVar4 = this;
        if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
          pvVar4 = *this;
        }
        memcpy((void *)(*(int *)((int)this + 0x10) + (int)pvVar4),param_1,param_2);
        *(uint *)((int)this + 0x10) = uVar1;
        pvVar4 = this;
        if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
          pvVar4 = *this;
        }
        *(undefined1 *)((int)pvVar4 + uVar1) = 0;
      }
    }
  }
  return (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this;
}



// Function: assign at 100039c8

/* Library Function - Single Match
    public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
   & __thiscall std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>
   >::assign(char const *,unsigned int)
   
   Library: Visual Studio 2010 Release */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this,
          char *param_1,uint param_2)

{
  bool bVar1;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar2;
  
  bVar1 = _Inside(this,param_1);
  if (bVar1) {
    pbVar2 = this;
    if (0xf < *(uint *)(this + 0x14)) {
      pbVar2 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                this;
    }
    this = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
           FUN_10003660(this,(undefined4 *)this,(int)param_1 - (int)pbVar2,param_2);
  }
  else {
    bVar1 = FUN_10002eca(this,param_2,'\0');
    if (bVar1) {
      pbVar2 = this;
      if (0xf < *(uint *)(this + 0x14)) {
        pbVar2 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  this;
      }
      memcpy(pbVar2,param_1,param_2);
      *(uint *)(this + 0x10) = param_2;
      pbVar2 = this;
      if (0xf < *(uint *)(this + 0x14)) {
        pbVar2 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  this;
      }
      pbVar2[param_2] =
           (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
    }
  }
  return this;
}



// Function: FUN_10003a3d at 10003a3d

void __thiscall FUN_10003a3d(void *this,uint param_1,undefined4 *param_2,wchar_t *param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)wcslen(param_3);
  FUN_1000374b(this,param_1,param_2,(undefined4 *)param_3,puVar1);
  return;
}



// Function: FUN_10003a63 at 10003a63

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10003a63(void *this,void *param_1,uint param_2,uint param_3)

{
  FUN_10003720(param_1,(undefined4 *)this,param_2,param_3);
  return param_1;
}



// Function: FUN_10003a9c at 10003a9c

void __thiscall FUN_10003a9c(void *this,undefined4 *param_1,undefined4 *param_2)

{
  FUN_100117c4(param_2 + 3,*(undefined4 **)((int)this + 4),param_2);
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + -0xc;
  *param_1 = param_2;
  return;
}



// Function: FUN_10003ac9 at 10003ac9

void __thiscall FUN_10003ac9(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  
  if (param_2 != param_3) {
    puVar1 = FUN_100117c4(param_3,*(undefined4 **)((int)this + 4),param_2);
    *(undefined4 **)((int)this + 4) = puVar1;
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_10003af9 at 10003af9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10003af9(void *this,int param_1)

{
  *(undefined ***)this = CComErrorHandlerException::vftable;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  basic_string<>((void *)((int)this + 0x10),(undefined4 *)(param_1 + 0x10));
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  return (undefined4 *)this;
}



// Function: FUN_10003b49 at 10003b49

void * __cdecl FUN_10003b49(undefined4 *param_1,undefined4 *param_2,void *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 7) {
    FUN_100031a7(param_3,param_1,0,0xffffffff);
    param_3 = (void *)((int)param_3 + 0x1c);
  }
  return param_3;
}



// Function: FUN_10003b71 at 10003b71

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 * FUN_10003b71(void *param_1,undefined4 *param_2)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)&LAB_100181a1;
  if (param_1 != (void *)0x0) {
    puVar1 = basic_string<>(param_1,param_2);
  }
  return puVar1;
}



// Function: FUN_10003b9f at 10003b9f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 * __cdecl FUN_10003b9f(void *param_1,undefined4 *param_2)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)&LAB_100181a1;
  if (param_1 != (void *)0x0) {
    puVar1 = basic_string<>(param_1,param_2);
  }
  return puVar1;
}



// Function: FUN_10003bce at 10003bce

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10003bce(void *this,undefined4 *param_1)

{
  basic_string<>(this,param_1);
  basic_string<>((void *)((int)this + 0x1c),param_1 + 7);
  return this;
}



// Function: FUN_10003c06 at 10003c06

void __cdecl FUN_10003c06(undefined4 param_1,void *param_2)

{
  FID_conflict__Tidy(param_2,'\x01',0);
  return;
}



// Function: FUN_10003c17 at 10003c17

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10003c17(void *this,undefined4 *param_1,undefined4 *param_2)

{
  *(undefined4 *)this = *param_1;
  FUN_10003bce((void *)((int)this + 4),param_2);
  return (undefined4 *)this;
}



// Function: FUN_10003c48 at 10003c48

undefined2 * __thiscall FUN_10003c48(void *this,wchar_t *param_1)

{
  size_t sVar1;
  
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)this = 0;
  sVar1 = wcslen(param_1);
  FID_conflict_assign(this,(undefined4 *)param_1,sVar1);
  return (undefined2 *)this;
}



// Function: FUN_10003c7a at 10003c7a

undefined4 * __thiscall FUN_10003c7a(void *this,undefined4 *param_1)

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



// Function: FUN_10003cd7 at 10003cd7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall
FUN_10003cd7(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4,
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



// Function: FUN_10003d3e at 10003d3e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 * __cdecl FUN_10003d3e(undefined2 *param_1,wchar_t *param_2)

{
  if (param_2 == (wchar_t *)0x0) {
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
  }
  else {
    FUN_10003c48(param_1,param_2);
  }
  return param_1;
}



// Function: FUN_10003d90 at 10003d90

void __cdecl FUN_10003d90(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  FUN_10003b71(param_2,param_3);
  return;
}



// Function: FUN_10003da3 at 10003da3

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10003da3(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_74 [48];
  undefined1 local_44 [60];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 100;
  local_8 = 0x10003daf;
  FUN_10003cd7(local_44,param_1,0,param_2,L"",0);
  local_8 = 0;
  FUN_10003af9(local_74,(int)local_44);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_74,(ThrowInfo *)&DAT_10021550);
}



// Function: FUN_10003de5 at 10003de5

void __cdecl FUN_10003de5(void *param_1,void *param_2,undefined4 param_3)

{
  for (; param_1 != param_2; param_1 = (void *)((int)param_1 + 0x1c)) {
    FUN_10003c06(param_3,param_1);
  }
  return;
}



// Function: FUN_10003e04 at 10003e04

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl
FUN_10003e04(undefined4 *param_1,undefined4 *param_2,void *param_3,undefined4 param_4)

{
  for (; param_1 != param_2; param_1 = param_1 + 7) {
    FUN_10003d90(param_4,param_3,param_1);
    param_3 = (void *)((int)param_3 + 0x1c);
  }
  return param_3;
}



// Function: Catch@10003e48 at 10003e48

void Catch_10003e48(void)

{
  int unaff_EBP;
  void *pvVar1;
  
  for (pvVar1 = *(void **)(unaff_EBP + -0x14); pvVar1 != *(void **)(unaff_EBP + 0x10);
      pvVar1 = (void *)((int)pvVar1 + 0x1c)) {
    FUN_10003c06(*(undefined4 *)(unaff_EBP + 0x14),pvVar1);
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10003e6a at 10003e6a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10003e6a(void *this,undefined4 *param_1)

{
  FUN_10003c17(this,param_1,param_1 + 1);
  return this;
}



// Function: basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> at 10003e98

/* Library Function - Single Match
    public: __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >(char const *)
   
   Library: Visual Studio 2010 Release */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this,
          char *param_1)

{
  size_t sVar1;
  
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0xf;
  *this = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
  sVar1 = strlen(param_1);
  assign(this,param_1,sVar1);
  return this;
}



// Function: basic_string<> at 10003ec7

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
  FUN_10003c7a(this,param_1);
  return (undefined2 *)this;
}



// Function: FUN_10003eec at 10003eec

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __cdecl
FUN_10003eec(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,
            LPCWSTR param_2)

{
  int iVar1;
  char *pcVar2;
  CHAR local_28 [16];
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x10003ef8;
  local_18 = 0;
  if (param_2 == (LPCWSTR)0x0) {
    *(undefined4 *)(param_1 + 0x14) = 0xf;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *param_1 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
  }
  else {
    iVar1 = lstrlenW(param_2);
    if (iVar1 + 1 < 0x40000000) {
      pcVar2 = (char *)AtlW2AHelper(local_28,param_2,(iVar1 + 1) * 2,3);
    }
    else {
      pcVar2 = (char *)0x0;
    }
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(param_1,pcVar2);
  }
  local_8 = 0;
  local_18 = 1;
  FUN_10014f84();
  return;
}



// Function: FUN_10003f69 at 10003f69

undefined4 FUN_10003f69(void)

{
  undefined4 *puVar1;
  undefined4 local_8;
  
  for (puVar1 = DAT_10029320; puVar1 != DAT_10029324; puVar1 = puVar1 + 3) {
    Ordinal_6(*puVar1);
    (**(code **)(*(int *)puVar1[2] + 8))((int *)puVar1[2]);
  }
  FUN_10003ac9(&DAT_10029320,&local_8,DAT_10029320,DAT_10029324);
  DAT_10028e78 = 0;
  return 0;
}



// Function: FUN_10003fba at 10003fba

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10003fba(void *this,void *param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  undefined4 local_30 [4];
  undefined4 local_20;
  undefined4 local_1c;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x10003fc6;
  if (((*(byte *)((int)this + 0x40) & 2) == 0) &&
     (puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this), puVar1 != (ushort *)0x0)) {
    puVar1 = *(ushort **)((int)this + 0x3c);
    puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    if (puVar1 < puVar2) {
      puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this);
    }
    basic_string<>(local_30,(undefined4 *)**(undefined4 **)((int)this + 0x14),
                   (int)puVar1 - (int)**(undefined4 **)((int)this + 0x14) >> 1);
    local_8 = 1;
    basic_string<>(param_1,local_30);
  }
  else {
    if (((*(byte *)((int)this + 0x40) & 4) == 0) &&
       (puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                           ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                             *)this), puVar1 != (ushort *)0x0)) {
      basic_string<>(local_30,(undefined4 *)**(undefined4 **)((int)this + 0x10),
                     (**(int **)((int)this + 0x20) + **(int **)((int)this + 0x30) * 2) -
                     (int)**(undefined4 **)((int)this + 0x10) >> 1);
      local_8 = 2;
    }
    else {
      local_1c = 7;
      local_20 = 0;
      local_30[0]._0_2_ = 0;
      local_8 = 3;
    }
    basic_string<>(param_1,local_30);
  }
  local_8 = local_8 & 0xffffff00;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_10014f84();
  return;
}



// Function: FUN_100040a3 at 100040a3

void __cdecl FUN_100040a3(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  FUN_10003b9f(param_2,param_3);
  return;
}



// Function: FUN_100040b5 at 100040b5

void __cdecl FUN_100040b5(undefined4 param_1,void *param_2)

{
  FUN_100038d2(param_2,0);
  return;
}



// Function: FUN_100040c4 at 100040c4

void __thiscall FUN_100040c4(void *this,int param_1)

{
                    /* WARNING: Load size is inaccurate */
  if ((*this == '\0') && (param_1 < 0)) {
    *(undefined1 *)this = 1;
    FUN_10003da3(param_1,*(undefined4 *)((int)this + 4));
  }
  return;
}



// Function: FUN_100040e4 at 100040e4

void __thiscall
FUN_100040e4(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  uint extraout_EAX;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  uVar3 = *(uint *)((int)this + 8);
  if (0x4444442 < uVar3) {
    this = (void *)((int)this + 0xd);
    FUN_100040b5(this,param_4 + 3);
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
    if (*(char *)(iVar4 + 0x48) != '\0') {
      *(undefined1 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x48) = 1;
      *param_1 = param_4;
      return;
    }
    piVar1 = (int *)piVar5[1];
    piVar2 = (int *)piVar1[1];
    if (piVar1 == (int *)*piVar2) {
      iVar4 = piVar2[2];
      if (*(char *)(iVar4 + 0x48) == '\0') {
LAB_100041b3:
        *(undefined1 *)(piVar1 + 0x12) = 1;
        *(undefined1 *)(iVar4 + 0x48) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x48) = 0;
        piVar5 = *(int **)(piVar5[1] + 4);
      }
      else {
        if (piVar5 == (int *)piVar1[2]) {
          FUN_10001ba0(this,(int)piVar1);
          piVar5 = piVar1;
        }
        *(undefined1 *)(piVar5[1] + 0x48) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x48) = 0;
        FUN_10001be5(this,*(int **)(piVar5[1] + 4));
      }
    }
    else {
      iVar4 = *piVar2;
      if (*(char *)(iVar4 + 0x48) == '\0') goto LAB_100041b3;
      if (piVar5 == (int *)*piVar1) {
        FUN_10001be5(this,piVar1);
        piVar5 = piVar1;
      }
      *(undefined1 *)(piVar5[1] + 0x48) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x48) = 0;
      FUN_10001ba0(this,*(int *)(piVar5[1] + 4));
    }
    iVar4 = piVar5[1];
  } while( true );
}



// Function: FUN_1000421c at 1000421c

void * __cdecl FUN_1000421c(undefined4 *param_1,undefined4 *param_2,void *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 7) {
    FUN_10003c7a(param_3,param_1);
    param_3 = (void *)((int)param_3 + 0x1c);
  }
  return param_3;
}



// Function: FUN_10004240 at 10004240

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_10004240(void *param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = &LAB_100181a1;
  if (param_1 != (void *)0x0) {
    puVar1 = (undefined1 *)FUN_10003e6a(param_1,param_2);
  }
  return puVar1;
}



// Function: FUN_1000426e at 1000426e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 * FUN_1000426e(void *param_1,undefined4 *param_2)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)&LAB_100181a1;
  if (param_1 != (void *)0x0) {
    puVar1 = basic_string<>(param_1,param_2);
  }
  return puVar1;
}



// Function: FUN_1000429c at 1000429c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __cdecl
FUN_1000429c(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,
            undefined4 *param_2)

{
  int *piVar1;
  int local_18 [4];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x100042a8;
  local_18[1] = 0;
  piVar1 = FUN_10001f4e(local_18,param_2);
  local_8 = 1;
  FUN_10003eec(param_1,(LPCWSTR)*piVar1);
  local_18[1] = 1;
  local_8 = local_8 & 0xffffff00;
  Ordinal_6(local_18[0]);
  return param_1;
}



// Function: FUN_100042e4 at 100042e4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_100042e4(void *this,void *param_1)

{
  FUN_10003fba((void *)((int)this + 0x18),param_1);
  return param_1;
}



// Function: FUN_10004315 at 10004315

void __fastcall FUN_10004315(_Container_base0 *param_1)

{
  if (*(int *)param_1 != 0) {
    std::_Container_base0::_Orphan_all(param_1);
    FUN_10003de5(*(void **)param_1,*(void **)(param_1 + 4),param_1 + 0xc);
    operator_delete(*(void **)param_1);
  }
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: FUN_10004350 at 10004350

void __thiscall FUN_10004350(void *this,int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x49);
  while (cVar1 == '\0') {
    FUN_10004350(this,(int *)param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_100040b5((int)this + 0xd,param_1 + 3);
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x49);
  }
  return;
}



// Function: FUN_10004394 at 10004394

void __thiscall FUN_10004394(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  piVar2 = param_2;
  if (*(char *)((int)param_2 + 0x49) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  FUN_10001b65((int *)&param_2);
  piVar5 = (int *)*piVar2;
  if (*(char *)((int)piVar5 + 0x49) == '\0') {
    piVar7 = piVar5;
    if ((*(char *)(piVar2[2] + 0x49) != '\0') || (piVar7 = (int *)param_2[2], param_2 == piVar2))
    goto LAB_100043de;
    piVar5[1] = (int)param_2;
    *param_2 = *piVar2;
    piVar5 = param_2;
    if (param_2 != (int *)piVar2[2]) {
      piVar5 = (int *)param_2[1];
      if (*(char *)((int)piVar7 + 0x49) == '\0') {
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
    iVar1 = param_2[0x12];
    *(char *)(param_2 + 0x12) = (char)piVar2[0x12];
    *(char *)(piVar2 + 0x12) = (char)iVar1;
  }
  else {
    piVar7 = (int *)piVar2[2];
LAB_100043de:
    piVar5 = (int *)piVar2[1];
    if (*(char *)((int)piVar7 + 0x49) == '\0') {
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
      if (*(char *)((int)piVar7 + 0x49) == '\0') {
        piVar3 = (int *)*piVar7;
        piVar6 = piVar7;
        while (piVar4 = piVar3, *(char *)((int)piVar4 + 0x49) == '\0') {
          piVar6 = piVar4;
          piVar3 = (int *)*piVar4;
        }
      }
      **(int **)((int)this + 4) = (int)piVar6;
    }
    if (*(int **)(*(int *)((int)this + 4) + 8) == piVar2) {
      piVar6 = piVar5;
      if (*(char *)((int)piVar7 + 0x49) == '\0') {
        piVar3 = (int *)piVar7[2];
        piVar6 = piVar7;
        while (piVar4 = piVar3, *(char *)((int)piVar4 + 0x49) == '\0') {
          piVar6 = piVar4;
          piVar3 = (int *)piVar4[2];
        }
      }
      *(int **)(*(int *)((int)this + 4) + 8) = piVar6;
    }
  }
  if ((char)piVar2[0x12] != '\x01') {
LAB_100045bb:
    FUN_100040b5((int)this + 0xd,piVar2 + 3);
    operator_delete(piVar2);
    if (*(int *)((int)this + 8) != 0) {
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
    }
    *param_1 = param_2;
    return;
  }
LAB_1000456f:
  piVar6 = piVar5;
  if ((piVar7 == *(int **)(*(int *)((int)this + 4) + 4)) || ((char)piVar7[0x12] != '\x01'))
  goto LAB_100045b7;
  piVar5 = (int *)*piVar6;
  if (piVar7 == piVar5) {
    piVar5 = (int *)piVar6[2];
    if ((char)piVar5[0x12] == '\0') {
      *(undefined1 *)(piVar5 + 0x12) = 1;
      *(undefined1 *)(piVar6 + 0x12) = 0;
      FUN_10001ba0(this,(int)piVar6);
      piVar5 = (int *)piVar6[2];
    }
    if (*(char *)((int)piVar5 + 0x49) == '\0') {
      if ((*(char *)(*piVar5 + 0x48) != '\x01') || (*(char *)(piVar5[2] + 0x48) != '\x01')) {
        if (*(char *)(piVar5[2] + 0x48) == '\x01') {
          *(undefined1 *)(*piVar5 + 0x48) = 1;
          *(undefined1 *)(piVar5 + 0x12) = 0;
          FUN_10001be5(this,piVar5);
          piVar5 = (int *)piVar6[2];
        }
        *(char *)(piVar5 + 0x12) = (char)piVar6[0x12];
        *(undefined1 *)(piVar6 + 0x12) = 1;
        *(undefined1 *)(piVar5[2] + 0x48) = 1;
        FUN_10001ba0(this,(int)piVar6);
        goto LAB_100045b7;
      }
LAB_10004566:
      *(undefined1 *)(piVar5 + 0x12) = 0;
    }
  }
  else {
    if ((char)piVar5[0x12] == '\0') {
      *(undefined1 *)(piVar5 + 0x12) = 1;
      *(undefined1 *)(piVar6 + 0x12) = 0;
      FUN_10001be5(this,piVar6);
      piVar5 = (int *)*piVar6;
    }
    if (*(char *)((int)piVar5 + 0x49) == '\0') {
      if ((*(char *)(piVar5[2] + 0x48) == '\x01') && (*(char *)(*piVar5 + 0x48) == '\x01'))
      goto LAB_10004566;
      if (*(char *)(*piVar5 + 0x48) == '\x01') {
        *(undefined1 *)(piVar5[2] + 0x48) = 1;
        *(undefined1 *)(piVar5 + 0x12) = 0;
        FUN_10001ba0(this,(int)piVar5);
        piVar5 = (int *)*piVar6;
      }
      *(char *)(piVar5 + 0x12) = (char)piVar6[0x12];
      *(undefined1 *)(piVar6 + 0x12) = 1;
      *(undefined1 *)(*piVar5 + 0x48) = 1;
      FUN_10001be5(this,piVar6);
LAB_100045b7:
      *(undefined1 *)(piVar7 + 0x12) = 1;
      goto LAB_100045bb;
    }
  }
  piVar5 = (int *)piVar6[1];
  piVar7 = piVar6;
  goto LAB_1000456f;
}



// Function: FUN_100045f1 at 100045f1

int __thiscall FUN_100045f1(void *this,int param_1)

{
  *(int *)((int)this + 0xc) = param_1;
  FUN_100040c4((void *)((int)this + 4),param_1);
  return (int)this;
}



// Function: FUN_1000460d at 1000460d

void __thiscall FUN_1000460d(void *this,undefined4 *param_1,int *param_2,char param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *local_c;
  bool local_8;
  
  piVar2 = *(int **)((int)this + 4);
  piVar1 = param_2 + 3;
  local_8 = true;
  local_c = piVar2;
  if (*(char *)(piVar2[1] + 0x49) == '\0') {
    piVar3 = (int *)piVar2[1];
    do {
      local_c = piVar3;
      if (param_3 == '\0') {
        local_8 = *piVar1 < local_c[3];
      }
      else {
        local_8 = *piVar1 <= local_c[3];
      }
      if (local_8 == false) {
        piVar3 = (int *)local_c[2];
      }
      else {
        piVar3 = (int *)*local_c;
      }
    } while (*(char *)((int)piVar3 + 0x49) == '\0');
  }
  _param_3 = local_c;
  if (local_8 != false) {
    if (local_c == (int *)*piVar2) {
      local_8 = true;
      goto LAB_10004672;
    }
    FUN_100012c8((int *)&param_3);
  }
  piVar2 = _param_3;
  if (*piVar1 <= _param_3[3]) {
    FUN_100040b5((int)this + 0xd,piVar1);
    operator_delete(param_2);
    *param_1 = piVar2;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_10004672:
  puVar4 = (undefined4 *)FUN_100040e4(this,(undefined4 *)&param_3,local_8,local_c,param_2);
  *param_1 = *puVar4;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}



// Function: FUN_100046cc at 100046cc

void __cdecl FUN_100046cc(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  FUN_10004240(param_2,param_3);
  return;
}



// Function: FUN_100046df at 100046df

void __cdecl FUN_100046df(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  FUN_1000426e(param_2,param_3);
  return;
}



// Function: FUN_100046f2 at 100046f2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_100046f2(void *param_1,long param_2)

{
  undefined1 local_bc [16];
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> local_ac [80];
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_5c [72];
  undefined4 local_14;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xac;
  local_8 = 0x10004701;
  local_14 = 0;
  FUN_10003074(local_bc,3,1);
  local_8 = 1;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
            (local_ac,param_2);
  FUN_100042e4(local_bc,param_1);
  local_14 = 1;
  local_8 = local_8 & 0xffffff00;
  FUN_10002d26((int)local_5c);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_5c);
  return param_1;
}



// Function: FUN_10004757 at 10004757

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10004757(wchar_t *param_1)

{
  int *piVar1;
  ushort uVar2;
  size_t sVar3;
  int iVar4;
  undefined4 *puVar5;
  FILE *_File;
  FILE *_File_00;
  int iVar6;
  HRESULT HVar7;
  wchar_t *pwVar8;
  undefined4 local_90 [4];
  undefined4 local_80;
  int local_7c;
  int *local_78;
  int *local_74;
  int local_70;
  undefined1 local_6c [28];
  undefined1 local_50 [12];
  uint local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 local_24;
  uint local_20;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x80;
  local_8 = 0x10004766;
  FUN_10001c46(local_90);
  local_8 = 0;
  FUN_100045f1(local_90,0);
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_20 = 7;
  local_24 = 0;
  local_34 = (wchar_t *)((uint)local_34._2_2_ << 0x10);
  local_8._0_1_ = 2;
  FUN_10003c48(local_6c,param_1);
  local_8._0_1_ = 3;
  sVar3 = wcslen(L"\\");
  iVar4 = FUN_10001d91(local_6c,(short *)&DAT_1001dc40,0xffffffff,sVar3);
  if (iVar4 != -1) {
    puVar5 = (undefined4 *)FUN_10003a63(local_6c,local_50,0,iVar4 + 1);
    local_8._0_1_ = 4;
    FUN_10003c7a(&local_34,puVar5);
    local_8._0_1_ = 3;
    FID_conflict__Tidy(local_50,'\x01',0);
    sVar3 = wcslen(L"temp.xml");
    FUN_10003105(&local_34,(undefined4 *)L"temp.xml",sVar3);
  }
  _File = _wfopen(param_1,L"r");
  if (_File != (FILE *)0x0) {
    pwVar8 = local_34;
    if (local_20 < 8) {
      pwVar8 = (wchar_t *)&local_34;
    }
    _File_00 = _wfopen(pwVar8,L"w");
    if (_File_00 != (FILE *)0x0) {
      uVar2 = fgetwc(_File);
      while( true ) {
        if (uVar2 == 0xffff) break;
        fputwc(uVar2 ^ 0xd,_File_00);
        uVar2 = fgetwc(_File);
      }
      fclose(_File_00);
    }
    fclose(_File);
  }
  iVar4 = local_70;
  local_80 = 0;
  iVar6 = (**(code **)(**(int **)(local_70 + 8) + 0x110))(*(int **)(local_70 + 8),0);
  FUN_100045f1(local_90,iVar6);
  pwVar8 = local_34;
  if (local_20 < 8) {
    pwVar8 = (wchar_t *)&local_34;
  }
  if (pwVar8 == (wchar_t *)0x0) {
    local_7c = 0;
  }
  else {
    local_7c = Ordinal_2(pwVar8);
    if (local_7c == 0) goto LAB_10004974;
  }
  local_8._0_1_ = 5;
  local_44 = local_44 & 0xffff0000;
  FUN_1000191a(&local_44,&local_7c);
  local_8._0_1_ = 6;
  iVar4 = (**(code **)(**(int **)(iVar4 + 8) + 0xe8))
                    (*(int **)(iVar4 + 8),local_44,uStack_40,uStack_3c,uStack_38,&local_80);
  FUN_100045f1(local_90,iVar4);
  local_8._0_1_ = 5;
  Ordinal_9(&local_44);
  local_8._0_1_ = 3;
  Ordinal_6(local_7c);
  local_74 = (int *)0x0;
  local_8._0_1_ = 8;
  HVar7 = CoCreateInstance((IID *)&DAT_1001d8f0,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_1001d9b4,&local_74);
  FUN_100045f1(local_90,HVar7);
  piVar1 = local_74;
  local_78 = (int *)0x0;
  local_8._0_1_ = 10;
  pwVar8 = local_34;
  if (local_20 < 8) {
    pwVar8 = (wchar_t *)&local_34;
  }
  if (pwVar8 == (wchar_t *)0x0) {
    local_70 = 0;
  }
  else {
    local_70 = Ordinal_2(pwVar8);
    if (local_70 == 0) {
LAB_10004974:
                    /* WARNING: Subroutine does not return */
      FUN_100010d9(-0x7ff8fff2);
    }
  }
  local_8._0_1_ = 0xb;
  iVar4 = (**(code **)(*piVar1 + 0x50))(piVar1,local_70,&local_78);
  FUN_100045f1(local_90,iVar4);
  local_8 = CONCAT31(local_8._1_3_,10);
  Ordinal_6(local_70);
  iVar4 = (**(code **)(*local_78 + 0x54))(local_78,0xffffffff);
  FUN_100045f1(local_90,iVar4);
  piVar1 = local_78;
  if (local_78 != (int *)0x0) {
    local_78 = (int *)0x0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = local_74;
  if (local_74 != (int *)0x0) {
    local_74 = (int *)0x0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 8;
  if (local_78 != (int *)0x0) {
    (**(code **)(*local_78 + 8))(local_78);
  }
  local_8._0_1_ = 3;
  if (local_74 != (int *)0x0) {
    (**(code **)(*local_74 + 8))(local_74);
  }
  local_8._0_1_ = 2;
  FID_conflict__Tidy(local_6c,'\x01',0);
  local_8 = CONCAT31(local_8._1_3_,1);
  FID_conflict__Tidy(&local_34,'\x01',0);
  local_8 = 0xffffffff;
  FUN_10014f93();
  return;
}



// Function: Catch@10004a40 at 10004a40

undefined4 Catch_10004a40(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10004a34;
}



// Function: FUN_10004a4a at 10004a4a

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10004a4a(wchar_t *param_1)

{
  int *piVar1;
  ushort uVar2;
  size_t sVar3;
  int iVar4;
  undefined4 *puVar5;
  FILE *_File;
  HRESULT HVar6;
  wchar_t *pwVar7;
  undefined4 local_90 [4];
  wchar_t *local_80;
  int local_7c;
  int *local_78;
  int *local_74;
  FILE *local_70;
  undefined1 local_6c [28];
  undefined1 local_50 [12];
  uint local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 local_24;
  uint local_20;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x80;
  local_8 = 0x10004a59;
  local_80 = param_1;
  FUN_10001c46(local_90);
  local_8 = 0;
  FUN_100045f1(local_90,0);
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_20 = 7;
  local_24 = 0;
  local_34 = (wchar_t *)((uint)local_34._2_2_ << 0x10);
  local_8._0_1_ = 2;
  FUN_10003c48(local_6c,param_1);
  local_8._0_1_ = 3;
  sVar3 = wcslen(L"\\");
  iVar4 = FUN_10001d91(local_6c,(short *)&DAT_1001dc40,0xffffffff,sVar3);
  if (iVar4 != -1) {
    puVar5 = (undefined4 *)FUN_10003a63(local_6c,local_50,0,iVar4 + 1);
    local_8._0_1_ = 4;
    FUN_10003c7a(&local_34,puVar5);
    local_8._0_1_ = 3;
    FID_conflict__Tidy(local_50,'\x01',0);
    sVar3 = wcslen(L"temp.xml");
    FUN_10003105(&local_34,(undefined4 *)L"temp.xml",sVar3);
  }
  pwVar7 = local_34;
  if (local_20 < 8) {
    pwVar7 = (wchar_t *)&local_34;
  }
  if (pwVar7 == (wchar_t *)0x0) {
    local_7c = 0;
  }
  else {
    local_7c = Ordinal_2(pwVar7);
    if (local_7c == 0) goto LAB_10004be9;
  }
  local_8._0_1_ = 5;
  local_44 = local_44 & 0xffff0000;
  FUN_1000191a(&local_44,&local_7c);
  local_8._0_1_ = 6;
  iVar4 = (**(code **)(*(int *)local_70->_base + 0x108))
                    (local_70->_base,local_44,uStack_40,uStack_3c,uStack_38);
  FUN_100045f1(local_90,iVar4);
  local_8._0_1_ = 5;
  Ordinal_9(&local_44);
  local_8 = CONCAT31(local_8._1_3_,3);
  Ordinal_6(local_7c);
  pwVar7 = local_34;
  if (local_20 < 8) {
    pwVar7 = (wchar_t *)&local_34;
  }
  _File = _wfopen(pwVar7,L"r");
  if (_File != (FILE *)0x0) {
    local_70 = _wfopen(local_80,L"w");
    if (local_70 != (FILE *)0x0) {
      uVar2 = fgetwc(_File);
      while( true ) {
        if (uVar2 == 0xffff) break;
        fputwc(uVar2 ^ 0xd,local_70);
        uVar2 = fgetwc(_File);
      }
      fclose(local_70);
    }
    fclose(_File);
  }
  local_74 = (int *)0x0;
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 8;
  HVar6 = CoCreateInstance((IID *)&DAT_1001d8f0,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_1001d9b4,&local_74);
  FUN_100045f1(local_90,HVar6);
  piVar1 = local_74;
  local_78 = (int *)0x0;
  local_8._0_1_ = 10;
  pwVar7 = local_34;
  if (local_20 < 8) {
    pwVar7 = (wchar_t *)&local_34;
  }
  if (pwVar7 == (wchar_t *)0x0) {
    local_70 = (FILE *)0x0;
  }
  else {
    local_70 = (FILE *)Ordinal_2(pwVar7);
    if (local_70 == (FILE *)0x0) {
LAB_10004be9:
                    /* WARNING: Subroutine does not return */
      FUN_100010d9(-0x7ff8fff2);
    }
  }
  local_8._0_1_ = 0xb;
  iVar4 = (**(code **)(*piVar1 + 0x50))(piVar1,local_70,&local_78);
  FUN_100045f1(local_90,iVar4);
  local_8 = CONCAT31(local_8._1_3_,10);
  Ordinal_6(local_70);
  iVar4 = (**(code **)(*local_78 + 0x54))(local_78,0xffffffff);
  FUN_100045f1(local_90,iVar4);
  piVar1 = local_78;
  if (local_78 != (int *)0x0) {
    local_78 = (int *)0x0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = local_74;
  if (local_74 != (int *)0x0) {
    local_74 = (int *)0x0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 8;
  if (local_78 != (int *)0x0) {
    (**(code **)(*local_78 + 8))(local_78);
  }
  local_8._0_1_ = 3;
  if (local_74 != (int *)0x0) {
    (**(code **)(*local_74 + 8))(local_74);
  }
  local_8._0_1_ = 2;
  FID_conflict__Tidy(local_6c,'\x01',0);
  local_8 = CONCAT31(local_8._1_3_,1);
  FID_conflict__Tidy(&local_34,'\x01',0);
  local_8 = 0xffffffff;
  FUN_10014f93();
  return;
}



// Function: Catch@10004d19 at 10004d19

undefined4 Catch_10004d19(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10004d0d;
}



// Function: FUN_10004d23 at 10004d23

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_10004d23(undefined4 param_1,short param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined4 *param_6)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 local_30 [3];
  undefined4 local_24;
  int *local_20;
  int *local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x10004d2f;
  FUN_10001c46(local_30);
  local_8 = 0;
  FUN_100045f1(local_30,0);
  local_8._0_1_ = 1;
  local_18 = 0;
  piVar4 = DAT_10029320;
  do {
    if (piVar4 == DAT_10029324) {
LAB_10004dc6:
      if (local_18 == DAT_10028e78) {
        local_24 = 0x80004005;
      }
      return local_24;
    }
    local_20 = piVar4;
    if (param_2 != 3) {
      if (*piVar4 == 0) {
        local_1c = (int *)0x0;
      }
      else {
        local_1c = (int *)Ordinal_2(*piVar4);
        if (local_1c == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_100010d9(-0x7ff8fff2);
        }
      }
      local_8._0_1_ = 4;
      bVar1 = FUN_10001821(&local_1c,param_4);
      local_8._0_1_ = 1;
      Ordinal_6(local_1c);
      if (!bVar1) goto LAB_10004e74;
      uVar2 = Ordinal_2(*piVar4);
      *param_6 = uVar2;
      FUN_100019cb(&local_1c,(int *)piVar4[2]);
      local_8._0_1_ = 5;
      iVar3 = (**(code **)*local_1c)(local_1c,&DAT_1001d9e0,param_6 + 2);
      FUN_100045f1(local_30,iVar3);
      param_6[1] = piVar4[1];
LAB_10004dbe:
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 8))(local_1c);
      }
      goto LAB_10004dc6;
    }
    if (local_18 == param_4) {
      uVar2 = Ordinal_2(*piVar4);
      *param_6 = uVar2;
      FUN_100019cb(&local_1c,(int *)piVar4[2]);
      local_8._0_1_ = 2;
      iVar3 = (**(code **)*local_1c)(local_1c,&DAT_1001d9e0,param_6 + 2);
      FUN_100045f1(local_30,iVar3);
      param_6[1] = piVar4[1];
      goto LAB_10004dbe;
    }
LAB_10004e74:
    piVar4 = piVar4 + 3;
    local_18 = local_18 + 1;
  } while( true );
}



// Function: Catch@10004e84 at 10004e84

undefined4 Catch_10004e84(void)

{
  int unaff_EBP;
  
  FUN_100045f1((void *)(unaff_EBP + -0x2c),-0x7fffbffb);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10004ddc;
}



// Function: FUN_10004e9b at 10004e9b

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10004e9b(undefined4 param_1,int param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  undefined4 local_34 [3];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0x10004ea7;
  FUN_10001c2c(local_34);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  if (param_4 == (int *)0x0) {
    local_8 = 0xffffffff;
    FUN_100012a2(local_34);
    local_28 = 0x80070057;
  }
  else {
    FUN_100019cb(local_18,param_4);
    local_8._0_1_ = 2;
    local_24 = 0;
    local_20 = 4;
    local_1c = 0;
    if (param_2 == 0) {
      param_4 = (int *)0x0;
    }
    else {
      param_4 = (int *)Ordinal_2(param_2);
      if (param_4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_100010d9(-0x7ff8fff2);
      }
    }
    local_8._0_1_ = 3;
    local_24 = FUN_10001718((int *)&param_4);
    local_8._0_1_ = 2;
    Ordinal_6(param_4);
    local_1c = 0;
    iVar1 = (**(code **)*local_18[0])(local_18[0],&DAT_1001d9e0,&local_1c);
    FUN_100045f1(local_34,iVar1);
    local_20 = param_3;
    FUN_1000e1a0(&DAT_10029320,&local_24);
    DAT_10028e78 = DAT_10028e78 + 1;
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_18[0] != (int *)0x0) {
      (**(code **)(*local_18[0] + 8))(local_18[0]);
    }
  }
  return local_28;
}



// Function: Catch@10004f90 at 10004f90

undefined4 Catch_10004f90(void)

{
  int unaff_EBP;
  
  FUN_100045f1((void *)(unaff_EBP + -0x30),-0x7fffbffb);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10004f63;
}



// Function: FUN_10004fa7 at 10004fa7

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10004fa7(undefined4 *param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  size_t sVar8;
  wchar_t *pwVar9;
  undefined4 ***pppuVar10;
  uint local_2c0;
  undefined4 uStack_2bc;
  undefined4 uStack_2b8;
  undefined4 uStack_2b4;
  undefined4 local_2b0 [4];
  int local_2a0;
  int local_29c;
  int local_298;
  int local_294;
  undefined4 local_290;
  int local_28c;
  int *local_288;
  int local_284;
  int *local_280;
  int local_27c;
  int *local_278;
  undefined1 local_274 [28];
  undefined4 **local_258 [5];
  uint local_244;
  undefined4 **local_23c [5];
  uint local_228;
  wchar_t local_220 [268];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c0;
  local_290 = 0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  FUN_10001c46(local_2b0);
  local_8 = CONCAT31(local_8._1_3_,4);
  iVar6 = (**(code **)*param_1)(param_1,&DAT_1001da9c,&local_290);
  FUN_100045f1(local_2b0,iVar6);
  local_28c = param_2;
  do {
    if (DAT_10028e78 < local_28c) {
      local_8 = 3;
      FUN_1000531e();
      return;
    }
    param_2 = param_2 + 1;
    local_29c = param_2;
    FUN_10003c48(local_23c,L"/user_manager/groups/group[@ID=");
    local_8._0_1_ = 5;
    puVar7 = (undefined4 *)FUN_100046f2(local_274,param_2);
    local_8._0_1_ = 6;
    FUN_10002f2f(local_23c,puVar7,0,0xffffffff);
    local_8._0_1_ = 5;
    FID_conflict__Tidy(local_274,'\x01',0);
    sVar8 = wcslen(L"]");
    FUN_10003105(local_23c,(undefined4 *)&DAT_1001dc4c,sVar8);
    local_278 = (int *)0x0;
    local_8._0_1_ = 8;
    piVar1 = *(int **)(local_2a0 + 8);
    pppuVar10 = (undefined4 ***)local_23c[0];
    if (local_228 < 8) {
      pppuVar10 = local_23c;
    }
    if (pppuVar10 == (undefined4 ***)0x0) {
      local_284 = 0;
    }
    else {
      local_284 = Ordinal_2(pppuVar10);
      if (local_284 == 0) {
LAB_100052bd:
                    /* WARNING: Subroutine does not return */
        FUN_100010d9(-0x7ff8fff2);
      }
    }
    local_8._0_1_ = 9;
    iVar6 = (**(code **)(*piVar1 + 0x90))(piVar1,local_284,&local_278);
    FUN_100045f1(local_2b0,iVar6);
    local_8 = CONCAT31(local_8._1_3_,8);
    Ordinal_6(local_284);
    local_298 = 0;
    (**(code **)(*local_278 + 0x20))(local_278,&local_298);
    for (local_27c = 0; local_27c < local_298; local_27c = local_27c + 1) {
      local_280 = (int *)0x0;
      local_8._0_1_ = 0xb;
      iVar6 = (**(code **)(*local_278 + 0x1c))(local_278,local_27c,&local_280);
      FUN_100045f1(local_2b0,iVar6);
      local_288 = (int *)0x0;
      local_8._0_1_ = 0xd;
      iVar6 = (**(code **)*local_280)(local_280,&DAT_1001da9c,&local_288);
      FUN_100045f1(local_2b0,iVar6);
      pwVar9 = _ltow(param_2 + -1,local_220,10);
      FUN_10003c48(local_258,pwVar9);
      local_8._0_1_ = 0xe;
      pppuVar10 = (undefined4 ***)local_258[0];
      if (local_244 < 8) {
        pppuVar10 = local_258;
      }
      local_2c0 = local_2c0 & 0xffff0000;
      FUN_10001965(&local_2c0,(int)pppuVar10);
      piVar1 = local_288;
      uVar5 = uStack_2b4;
      uVar4 = uStack_2b8;
      uVar3 = uStack_2bc;
      uVar2 = local_2c0;
      local_8._0_1_ = 0xf;
      local_294 = Ordinal_2(&DAT_1001dc44);
      if (local_294 == 0) goto LAB_100052bd;
      local_8._0_1_ = 0x10;
      iVar6 = (**(code **)(*piVar1 + 0xb4))(piVar1,local_294,uVar2,uVar3,uVar4,uVar5);
      FUN_100045f1(local_2b0,iVar6);
      local_8._0_1_ = 0xf;
      Ordinal_6(local_294);
      local_8._0_1_ = 0xe;
      Ordinal_9(&local_2c0);
      local_8._0_1_ = 0xd;
      FID_conflict__Tidy(local_258,'\x01',0);
      local_8._0_1_ = 0xb;
      if (local_288 != (int *)0x0) {
        (**(code **)(*local_288 + 8))(local_288);
      }
      local_8 = CONCAT31(local_8._1_3_,8);
      if (local_280 != (int *)0x0) {
        (**(code **)(*local_280 + 8))(local_280);
      }
      param_2 = local_29c;
    }
    local_8._0_1_ = 5;
    if (local_278 != (int *)0x0) {
      (**(code **)(*local_278 + 8))(local_278);
    }
    local_8 = CONCAT31(local_8._1_3_,4);
    FID_conflict__Tidy(local_23c,'\x01',0);
    local_28c = local_28c + 1;
  } while( true );
}



// Function: Catch@10005305 at 10005305

undefined * Catch_10005305(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x2a0) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 3;
  return &DAT_1000531c;
}



// Function: FUN_1000531e at 1000531e

void FUN_1000531e(void)

{
  int *piVar1;
  int unaff_EBP;
  int *unaff_EDI;
  
  *(undefined1 *)(unaff_EBP + -4) = 0;
  piVar1 = *(int **)(unaff_EBP + -0x28c);
  if (piVar1 != unaff_EDI) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  piVar1 = *(int **)(unaff_EBP + 8);
  if (piVar1 != unaff_EDI) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_10014f93();
  return;
}



// Function: FUN_1000534d at 1000534d

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */
/* WARNING: Type propagation algorithm not settling */

void FUN_1000534d(void)

{
  int *piVar1;
  size_t sVar2;
  uint uVar3;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *_Filename;
  FILE *_File;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  wchar_t *pwVar7;
  undefined4 local_1a4 [4];
  ushort local_194 [2];
  int local_190 [2];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_188 [16];
  undefined4 local_178;
  undefined4 local_174;
  char *******local_16c [5];
  uint local_158;
  undefined4 local_150;
  undefined4 local_140;
  uint local_13c;
  undefined4 local_134 [4];
  int local_124;
  undefined4 local_120;
  char local_118 [272];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x194;
  local_8 = 0;
  FUN_10001c46(local_1a4);
  local_190[1] = 0;
  local_120 = 7;
  local_124 = 0;
  local_134[0]._0_2_ = 0;
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_13c = 7;
  local_140 = 0;
  local_150 = (wchar_t *)((uint)local_150._2_2_ << 0x10);
  local_8._0_1_ = 4;
  FUN_100031a7(local_134,(undefined4 *)&stack0x00000004,0,0xffffffff);
  sVar2 = wcslen(L".dat");
  FID_conflict_assign(&local_150,(undefined4 *)L".dat",sVar2);
  local_194[0] = 0x5f;
  local_194[1] = 0;
  uVar3 = FUN_100019f9(local_134,local_194,0xffffffff,1);
  if (uVar3 == 0xffffffff) {
    local_190[1] = 0;
  }
  else {
    pwVar7 = local_150;
    if (local_13c < 8) {
      pwVar7 = (wchar_t *)&local_150;
    }
    FUN_10003a3d(local_134,uVar3,(undefined4 *)(local_124 - uVar3),pwVar7);
    _Filename = FUN_1000429c((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                              *)local_16c,local_134);
    local_8._0_1_ = 5;
    if (0xf < *(uint *)(_Filename + 0x14)) {
      _Filename = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                   _Filename;
    }
    _File = fopen((char *)_Filename,"r");
    local_8._0_1_ = 4;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_16c,true,0);
    local_174 = 0xf;
    local_178 = 0;
    local_188[0] = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0
    ;
    local_8._0_1_ = 6;
    if (_File == (FILE *)0x0) {
      local_190[1] = 0;
    }
    else {
      while( true ) {
        iVar4 = feof(_File);
        if (iVar4 != 0) break;
        sVar2 = fread(local_118,1,0x100,_File);
        iVar4 = ferror(_File);
        if (iVar4 != 0) {
          local_190[1] = 0;
        }
        FUN_1000392e(local_188,local_118,sVar2);
      }
      fclose(_File);
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 local_16c,local_188);
      iVar4 = local_190[0];
      local_8._0_1_ = 7;
      uVar5 = FUN_10002fe8((byte *)local_188,0x25,(byte *)local_16c);
      if ((char)uVar5 == '\0') {
        local_190[1] = 0;
      }
      else {
        piVar1 = *(int **)(iVar4 + 0xc);
        if (local_158 < 0x10) {
          local_16c[0] = (char *******)local_16c;
        }
        puVar6 = (undefined4 *)ATL::CComBSTR::CComBSTR((CComBSTR *)local_190,(char *)local_16c[0]);
        local_8._0_1_ = 8;
        iVar4 = (**(code **)(*piVar1 + 0x104))(piVar1,*puVar6,local_190 + 1);
        FUN_100045f1(local_1a4,iVar4);
        local_8._0_1_ = 7;
        Ordinal_6(local_190[0]);
      }
      local_8._0_1_ = 6;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 local_16c,true,0);
    }
    local_8._0_1_ = 4;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
              (local_188,true,0);
  }
  local_8._0_1_ = 3;
  FID_conflict__Tidy(&local_150,'\x01',0);
  local_8 = CONCAT31(local_8._1_3_,2);
  FID_conflict__Tidy(local_134,'\x01',0);
  local_8 = 1;
  FUN_100055f8();
  return;
}



// Function: Catch@100055df at 100055df

undefined * Catch_100055df(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x188) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_100055f3;
}



// Function: FUN_100055f8 at 100055f8

void FUN_100055f8(void)

{
  int unaff_EBX;
  int unaff_EBP;
  char unaff_DI;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FID_conflict__Tidy((void *)(unaff_EBP + 8),unaff_DI,unaff_EBX);
  FUN_10014f93();
  return;
}



// Function: FUN_1000561d at 1000561d

void __fastcall FUN_1000561d(void *param_1)

{
  FUN_10004350(param_1,*(int **)(*(int *)((int)param_1 + 4) + 4));
  *(int *)(*(int *)((int)param_1 + 4) + 4) = *(int *)((int)param_1 + 4);
  *(undefined4 *)*(undefined4 *)((int)param_1 + 4) = *(undefined4 *)((int)param_1 + 4);
  *(int *)(*(int *)((int)param_1 + 4) + 8) = *(int *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 8) = 0;
  return;
}



// Function: FUN_10005644 at 10005644

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005644(int param_1)

{
  FUN_10004315((_Container_base0 *)(param_1 + 4));
  return;
}



// Function: FUN_10005665 at 10005665

void __thiscall FUN_10005665(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *pvVar1;
  
  if (param_2 != param_3) {
    pvVar1 = FUN_1000421c(param_3,*(undefined4 **)((int)this + 4),param_2);
    FUN_10003de5(pvVar1,*(void **)((int)this + 4),(int)this + 0xc);
    *(void **)((int)this + 4) = pvVar1;
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_100056a9 at 100056a9

void __thiscall FUN_100056a9(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  void *local_8;
  
  local_8 = this;
  if ((param_2 == (int *)**(int **)((int)this + 4)) && (param_3 == *(int **)((int)this + 4))) {
    FUN_1000561d(this);
    param_2 = (int *)**(undefined4 **)((int)this + 4);
  }
  else if (param_2 != param_3) {
    do {
      piVar1 = param_2;
      FUN_10001b65((int *)&param_2);
      FUN_10004394(this,&local_8,piVar1);
    } while (param_2 != param_3);
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_100056fc at 100056fc

void __fastcall FUN_100056fc(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10005709 at 10005709

undefined4 FUN_10005709(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10005733 at 10005733

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005733(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10005762 at 10005762

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005762(int param_1)

{
  FUN_10005733(param_1);
  return;
}



// Function: FUN_10005780 at 10005780

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __cdecl FUN_10005780(int *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (7 < (uint)param_2[5]) {
    param_2 = (undefined4 *)*param_2;
  }
  if (param_2 == (undefined4 *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = Ordinal_2(param_2);
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_100010d9(-0x7ff8fff2);
    }
  }
  *param_1 = iVar1;
  Ordinal_6(0);
  return 0;
}



// Function: Catch@100057e3 at 100057e3

undefined4 Catch_100057e3(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x18) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100057c2;
}



// Function: FUN_100057f4 at 100057f4

undefined4 __thiscall FUN_100057f4(void *this,int *param_1,undefined4 *param_2)

{
  if (*(int **)((int)this + 4) != param_1) {
    FUN_10001113((int *)((int)this + 4),param_1);
  }
  *(undefined4 **)((int)this + 8) = param_2;
  *(undefined4 *)((int)this + 0xc) = *param_2;
  return 0;
}



// Function: FUN_1000581d at 1000581d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000581d(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}



// Function: FUN_10005856 at 10005856

undefined4 FUN_10005856(int param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_3 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else if (param_2 < 1) {
    uVar1 = 0x80070057;
  }
  else {
    puVar2 = *(undefined4 **)(param_1 + 4);
    uVar1 = 0x80004005;
    while ((param_2 = param_2 + -1, puVar2 != *(undefined4 **)(param_1 + 8) && (0 < param_2))) {
      puVar2 = puVar2 + 7;
    }
    if (puVar2 != *(undefined4 **)(param_1 + 8)) {
      uVar1 = FUN_10005780(param_3,puVar2);
    }
  }
  return uVar1;
}



// Function: FUN_100058a6 at 100058a6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_100058a6(undefined4 *param_1)

{
  FUN_1000581d((int)param_1);
  *param_1 = ATL::
             CComObject<class_ATL::CComEnumOnSTL<struct_IEnumVARIANT,&struct__GUID_const_IID_IEnumVARIANT,struct_tagVARIANT,class__CopyStringToVARIANT,class_std::vector<class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>,class_std::allocator<class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_>_>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  (**(code **)(*DAT_10029388 + 4))();
  return param_1;
}



// Function: _InlineIsEqualGUID at 100058df

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



// Function: FUN_1000590f at 1000590f

int __thiscall FUN_1000590f(void *this,void *param_1)

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
      AfxCrtErrorCheck(eVar2);
      iVar1 = 0;
      *(undefined2 *)this = 0;
    }
  }
  return iVar1;
}



// Function: InlineIsEqualUnknown at 10005950

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



// Function: AtlInternalQueryInterface at 1000597e

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
          if (pcVar1 == (code *)0x1) goto LAB_100059b2;
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
LAB_100059b2:
      piVar4 = (int *)(*(int *)(param_2 + 4) + (int)param_1);
      (**(code **)(*piVar4 + 4))(piVar4);
      *param_4 = piVar4;
      lVar2 = 0;
    }
  }
  return lVar2;
}



// Function: FUN_10005a1f at 10005a1f

undefined4 FUN_10005a1f(int param_1)

{
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  return *(undefined4 *)(param_1 + 0x10);
}



// Function: Release at 10005a2f

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



// Function: QueryInterface at 10005a50

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1001dce4,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10005a6a at 10005a6a

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __cdecl FUN_10005a6a(void *param_1,undefined4 *param_2)

{
  undefined2 local_28 [8];
  undefined4 local_18;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0;
  if (7 < (uint)param_2[5]) {
    param_2 = (undefined4 *)*param_2;
  }
  local_28[0] = 0;
  FUN_10001965(local_28,(int)param_2);
  local_8._0_1_ = 1;
  FUN_1000590f(local_28,param_1);
  local_18 = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_9(local_28);
  return local_18;
}



// Function: Catch@10005ac1 at 10005ac1

undefined4 Catch_10005ac1(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10005ab8;
}



// Function: FUN_10005ad2 at 10005ad2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005ad2(undefined4 *param_1)

{
  *param_1 = ATL::
             CComObject<class_ATL::CComEnumOnSTL<struct_IEnumVARIANT,&struct__GUID_const_IID_IEnumVARIANT,struct_tagVARIANT,class__CopyStringToVARIANT,class_std::vector<class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>,class_std::allocator<class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_>_>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  param_1[4] = 0xc0000001;
  (**(code **)(*DAT_10029388 + 8))();
  FUN_10005733((int)param_1);
  return;
}



// Function: FUN_10005b10 at 10005b10

undefined4 FUN_10005b10(int param_1)

{
  undefined4 uVar1;
  
  if (*(undefined4 **)(param_1 + 8) == (undefined4 *)0x0) {
    uVar1 = 0x80004005;
  }
  else {
    *(undefined4 *)(param_1 + 0xc) = **(undefined4 **)(param_1 + 8);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10005b2f at 10005b2f

undefined4 * __thiscall FUN_10005b2f(void *this,byte param_1)

{
  FUN_10005ad2((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10005b4e at 10005b4e

int FUN_10005b4e(int param_1,uint param_2,void *param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  
  iVar1 = param_1;
  uVar2 = 0;
  if ((param_3 == (void *)0x0) || ((1 < param_2 && (param_4 == (uint *)0x0)))) {
    param_1 = -0x7fffbffd;
  }
  else {
    if (param_4 != (uint *)0x0) {
      *param_4 = 0;
    }
    if (*(int *)(param_1 + 8) == 0) {
      param_1 = -0x7fffbffb;
    }
    else {
      param_1 = 0;
      pvVar3 = param_3;
      do {
        if ((*(undefined4 **)(iVar1 + 0xc) == *(undefined4 **)(*(int *)(iVar1 + 8) + 4)) ||
           (param_2 <= uVar2)) break;
        param_1 = FUN_10005a6a(pvVar3,*(undefined4 **)(iVar1 + 0xc));
        if (param_1 < 0) {
          for (; param_3 < pvVar3; param_3 = (void *)((int)param_3 + 0x10)) {
            Ordinal_9(param_3);
          }
          uVar2 = 0;
        }
        else {
          *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + 0x1c;
          pvVar3 = (void *)((int)pvVar3 + 0x10);
          uVar2 = uVar2 + 1;
        }
      } while (-1 < param_1);
      if (-1 < param_1) {
        if (param_4 != (uint *)0x0) {
          *param_4 = uVar2;
        }
        if (uVar2 < param_2) {
          param_1 = 1;
        }
      }
    }
  }
  return param_1;
}



// Function: FUN_10005bf7 at 10005bf7

undefined4 FUN_10005bf7(int param_1,int param_2)

{
  if (param_2 != 0) {
    do {
      param_2 = param_2 + -1;
      if (*(int *)(param_1 + 0xc) == *(int *)(*(int *)(param_1 + 8) + 4)) {
        return 1;
      }
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 0x1c;
    } while (param_2 != 0);
  }
  return 0;
}



// Function: FUN_10005c26 at 10005c26

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10005c26(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_100058a6(puVar1);
    }
    uVar2 = FUN_10005c89();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@10005c72 at 10005c72

undefined * Catch_10005c72(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x1c));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10005c84;
}



// Function: FUN_10005c89 at 10005c89

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10005c89(void)

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



// Function: FUN_10005ca0 at 10005ca0

int FUN_10005ca0(int *param_1,int *param_2)

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
  iVar3 = FUN_10005c26(&param_2);
  piVar2 = param_2;
  if (-1 < iVar3) {
    iVar3 = FUN_100057f4(param_2,param_1,param_1 + 1);
    if (iVar3 != 0) goto LAB_10005cef;
    iVar3 = (**(code **)*piVar2)(piVar2,&DAT_1001dcfc,piVar1);
  }
  if (iVar3 == 0) {
    return unaff_EDI;
  }
LAB_10005cef:
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x1c))(1);
  }
  return unaff_EDI;
}



// Function: FUN_10005d05 at 10005d05

int FUN_10005d05(int param_1,void **param_2)

{
  int iVar1;
  int *local_8;
  
  iVar1 = -0x7fffbffd;
  if (param_2 != (void **)0x0) {
    *param_2 = (void *)0x0;
    iVar1 = FUN_10005c26(&local_8);
    if (-1 < iVar1) {
      iVar1 = FUN_100057f4(local_8,*(int **)(param_1 + 4),*(undefined4 **)(param_1 + 8));
      if (-1 < iVar1) {
        local_8[3] = *(int *)(param_1 + 0xc);
        iVar1 = ATL::AtlInternalQueryInterface
                          (local_8,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1001dce4,(_GUID *)&DAT_1001f5bc,
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



// Function: FUN_10005d79 at 10005d79

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_10005d79(void *this,undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_10002913((int)this);
  FUN_100046cc((int)this + 0xd,(void *)(iVar1 + 0xc),param_1);
  return iVar1;
}



// Function: Catch@10005db6 at 10005db6

void Catch_10005db6(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10005dc9 at 10005dc9

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl
FUN_10005dc9(undefined4 *param_1,undefined4 *param_2,void *param_3,undefined4 param_4)

{
  for (; param_1 != param_2; param_1 = param_1 + 7) {
    FUN_100046df(param_4,param_3,param_1);
    param_3 = (void *)((int)param_3 + 0x1c);
  }
  return param_3;
}



// Function: Catch@10005e0d at 10005e0d

void Catch_10005e0d(void)

{
  int unaff_EBP;
  void *pvVar1;
  
  for (pvVar1 = *(void **)(unaff_EBP + -0x14); pvVar1 != *(void **)(unaff_EBP + 0x10);
      pvVar1 = (void *)((int)pvVar1 + 0x1c)) {
    FUN_10003c06(*(undefined4 *)(unaff_EBP + 0x14),pvVar1);
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10005e2f at 10005e2f

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10005e2f(int *param_1,wchar_t *param_2,int *param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  LPCWSTR *ppWVar3;
  wchar_t *pwVar4;
  undefined4 ***pppuVar5;
  size_t sVar6;
  undefined4 *puVar7;
  undefined4 local_53c;
  undefined4 uStack_538;
  undefined4 uStack_534;
  undefined4 uStack_530;
  uint local_52c;
  undefined4 uStack_528;
  undefined4 local_524;
  undefined4 uStack_520;
  uint local_51c;
  undefined4 uStack_518;
  undefined4 local_514;
  undefined4 uStack_510;
  undefined4 local_50c;
  undefined4 uStack_508;
  undefined4 uStack_504;
  undefined4 uStack_500;
  undefined4 local_4fc;
  undefined4 uStack_4f8;
  undefined4 uStack_4f4;
  undefined4 uStack_4f0;
  DWORD local_4ec;
  undefined4 local_4e8;
  undefined4 local_4e4;
  undefined4 local_4e0;
  int local_4dc;
  int local_4d8;
  undefined4 *local_4d4;
  int local_4d0;
  uint local_4cc;
  undefined4 uStack_4c8;
  undefined4 uStack_4c4;
  undefined4 uStack_4c0;
  undefined4 local_4bc;
  int local_4b8;
  int local_4b4;
  int local_4b0;
  int local_4ac;
  int *local_4a8;
  int *local_4a4;
  undefined4 local_4a0 [4];
  int local_490;
  int local_48c;
  int *local_488;
  int *local_484;
  int *local_480;
  int *local_47c;
  int *local_478;
  int *local_474;
  int *local_470;
  int *local_46c;
  wchar_t *local_468;
  undefined4 local_464 [7];
  undefined4 **local_448 [5];
  uint local_434;
  wchar_t local_42c [260];
  wchar_t local_224 [270];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x52c;
  local_8 = 0x10005e3e;
  local_4a8 = param_1;
  local_468 = param_2;
  local_46c = param_3;
  local_4a4 = param_4;
  FUN_10001c46(local_4a0);
  local_8 = 0;
  FUN_100045f1(local_4a0,0);
  local_8._0_1_ = 1;
  if (param_4 == (int *)0x0) {
    local_8 = 0xffffffff;
    FUN_100012a2(local_4a0);
  }
  else {
    local_4dc = 0;
    for (puVar7 = DAT_10029320; local_4d4 = puVar7, puVar7 != DAT_10029324; puVar7 = puVar7 + 3) {
      iVar2 = _wcsicmp((wchar_t *)*puVar7,local_468);
      if (iVar2 == 0) {
        local_8 = 0xffffffff;
        FUN_100012a2(local_4a0);
        goto LAB_100067f5;
      }
      local_4dc = local_4dc + 1;
    }
    iVar2 = (**(code **)(*param_1 + 0x40))(param_1,local_468,local_46c,local_4a4);
    FUN_100045f1(local_4a0,iVar2);
    local_4e8 = 0;
    local_4e4 = 0;
    local_4e0 = 0;
    local_8._0_1_ = 2;
    ppWVar3 = (LPCWSTR *)DAT_10029330;
    if (DAT_10029344 < 8) {
      ppWVar3 = &DAT_10029330;
    }
    iVar2 = Open(&local_4e8,(HKEY)0x80000002,(LPCWSTR)ppWVar3,0x2001f);
    if (iVar2 == 0) {
      local_4ec = 0x20a;
      ppWVar3 = (LPCWSTR *)DAT_1002934c;
      if (DAT_10029360 < 8) {
        ppWVar3 = &DAT_1002934c;
      }
      FUN_100013a4(&local_4e8,(LPBYTE)local_224,(LPCWSTR)ppWVar3,&local_4ec);
      ATL::CRegKey::Close((CRegKey *)&local_4e8);
      FUN_10004757(local_224);
      if (param_1[2] != 0) {
        FUN_100147e9(&local_4bc);
        local_47c = (int *)0x0;
        local_8._0_1_ = 5;
        FUN_10003c48(local_464,L"/user_manager/groups");
        local_8._0_1_ = 6;
        FUN_10014818(param_1 + 2,local_464,(int *)&local_47c);
        if (local_47c != (int *)0x0) {
          local_488 = (int *)0x0;
          local_480 = (int *)0x0;
          local_52c = CONCAT22(local_52c._2_2_,3);
          local_524 = 1;
          local_8._0_1_ = 0xb;
          local_4cc = local_52c;
          uStack_4c8 = uStack_528;
          uStack_4c4 = 1;
          uStack_4c0 = uStack_520;
          piVar1 = (int *)local_4a8[2];
          local_4d0 = Ordinal_2(&DAT_1001dbfc);
          if (local_4d0 == 0) {
LAB_1000607f:
                    /* WARNING: Subroutine does not return */
            FUN_100010d9(-0x7ff8fff2);
          }
          local_8._0_1_ = 0xc;
          local_4d8 = Ordinal_2(L"group");
          if (local_4d8 == 0) goto LAB_1000607f;
          local_8._0_1_ = 0xd;
          iVar2 = (**(code **)(*piVar1 + 0xe0))
                            (piVar1,local_4cc,uStack_4c8,uStack_4c4,uStack_4c0,local_4d8,local_4d0,
                             &local_488);
          FUN_100045f1(local_4a0,iVar2);
          local_8._0_1_ = 0xc;
          Ordinal_6(local_4d8);
          local_8._0_1_ = 0xb;
          Ordinal_6(local_4d0);
          local_8._0_1_ = 10;
          Ordinal_9(&local_52c);
          iVar2 = (**(code **)(*local_47c + 0x54))(local_47c,local_488,&local_480);
          FUN_100045f1(local_4a0,iVar2);
          local_474 = (int *)0x0;
          local_8._0_1_ = 0xf;
          iVar2 = (**(code **)*local_480)(local_480,&DAT_1001da9c,&local_474);
          FUN_100045f1(local_4a0,iVar2);
          pwVar4 = _ltow(DAT_10028e78 + -1,local_42c,10);
          FUN_10003c48(local_448,pwVar4);
          local_8._0_1_ = 0x10;
          pppuVar5 = (undefined4 ***)local_448[0];
          if (local_434 < 8) {
            pppuVar5 = local_448;
          }
          local_53c = (uint)local_53c._2_2_ << 0x10;
          FUN_10001965(&local_53c,(int)pppuVar5);
          local_8._0_1_ = 0x11;
          local_4cc = local_53c;
          uStack_4c8 = uStack_538;
          uStack_4c4 = uStack_534;
          uStack_4c0 = uStack_530;
          local_470 = local_474;
          local_4b0 = Ordinal_2(&DAT_1001dc44);
          if (local_4b0 == 0) goto LAB_1000607f;
          local_8._0_1_ = 0x12;
          iVar2 = (**(code **)(*local_470 + 0xb4))
                            (local_470,local_4b0,local_4cc,uStack_4c8,uStack_4c4,uStack_4c0);
          FUN_100045f1(local_4a0,iVar2);
          local_8._0_1_ = 0x11;
          Ordinal_6(local_4b0);
          local_4fc = (uint)local_4fc._2_2_ << 0x10;
          FUN_10001965(&local_4fc,(int)local_468);
          local_8._0_1_ = 0x13;
          local_4cc = local_4fc;
          uStack_4c8 = uStack_4f8;
          uStack_4c4 = uStack_4f4;
          uStack_4c0 = uStack_4f0;
          local_470 = local_474;
          local_490 = Ordinal_2(L"name");
          if (local_490 == 0) goto LAB_1000607f;
          local_8._0_1_ = 0x14;
          iVar2 = (**(code **)(*local_470 + 0xb4))
                            (local_470,local_490,local_4cc,uStack_4c8,uStack_4c4,uStack_4c0);
          FUN_100045f1(local_4a0,iVar2);
          local_8._0_1_ = 0x13;
          Ordinal_6(local_490);
          local_8._0_1_ = 0x11;
          Ordinal_9(&local_4fc);
          pwVar4 = _ltow((long)local_46c,local_42c,10);
          sVar6 = wcslen(pwVar4);
          FID_conflict_assign(local_448,(undefined4 *)pwVar4,sVar6);
          if (local_434 < 8) {
            local_448[0] = local_448;
          }
          local_50c = (uint)local_50c._2_2_ << 0x10;
          FUN_10001965(&local_50c,(int)local_448[0]);
          local_8._0_1_ = 0x15;
          local_4cc = local_50c;
          uStack_4c8 = uStack_508;
          uStack_4c4 = uStack_504;
          uStack_4c0 = uStack_500;
          local_470 = local_474;
          local_484 = (int *)Ordinal_2(L"groupType");
          if (local_484 == (int *)0x0) goto LAB_1000607f;
          local_8._0_1_ = 0x16;
          iVar2 = (**(code **)(*local_470 + 0xb4))
                            (local_470,local_484,local_4cc,uStack_4c8,uStack_4c4,uStack_4c0);
          FUN_100045f1(local_4a0,iVar2);
          local_8._0_1_ = 0x15;
          Ordinal_6(local_484);
          local_8 = CONCAT31(local_8._1_3_,0x11);
          Ordinal_9(&local_50c);
          local_4ac = 0;
          (**(code **)(*local_4a4 + 0x20))(local_4a4,&local_4ac);
          for (local_48c = 1; local_48c <= local_4ac; local_48c = local_48c + 1) {
            local_468 = (wchar_t *)0x0;
            local_46c = (int *)0x0;
            local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
            local_51c = CONCAT22(local_51c._2_2_,3);
            local_514 = 1;
            local_8._0_1_ = 0x1b;
            local_50c = local_51c;
            uStack_508 = uStack_518;
            uStack_504 = 1;
            uStack_500 = uStack_510;
            local_484 = (int *)local_4a8[2];
            local_4b8 = Ordinal_2(&DAT_1001dbfc);
            if (local_4b8 == 0) goto LAB_1000607f;
            local_8._0_1_ = 0x1c;
            local_4b4 = Ordinal_2(L"Right");
            if (local_4b4 == 0) goto LAB_1000607f;
            local_8._0_1_ = 0x1d;
            iVar2 = (**(code **)(*local_484 + 0xe0))
                              (local_484,local_50c,uStack_508,uStack_504,uStack_500,local_4b4,
                               local_4b8,&local_468);
            FUN_100045f1(local_4a0,iVar2);
            local_8._0_1_ = 0x1c;
            Ordinal_6(local_4b4);
            local_8._0_1_ = 0x1b;
            Ordinal_6(local_4b8);
            local_8._0_1_ = 0x1a;
            Ordinal_9(&local_51c);
            iVar2 = (**(code **)(*local_480 + 0x54))(local_480,local_468,&local_46c);
            FUN_100045f1(local_4a0,iVar2);
            local_478 = (int *)0x0;
            local_8._0_1_ = 0x1f;
            iVar2 = (**(code **)*local_46c)(local_46c,&DAT_1001da9c,&local_478);
            FUN_100045f1(local_4a0,iVar2);
            (**(code **)(*local_4a4 + 0x1c))(local_4a4,local_48c,&local_490);
            local_4cc = local_4cc & 0xffff0000;
            FUN_10001965(&local_4cc,local_490);
            local_8._0_1_ = 0x20;
            local_4fc = local_4cc;
            uStack_4f8 = uStack_4c8;
            uStack_4f4 = uStack_4c4;
            uStack_4f0 = uStack_4c0;
            local_484 = local_478;
            local_470 = (int *)Ordinal_2(&DAT_1001dc44);
            if (local_470 == (int *)0x0) goto LAB_1000607f;
            local_8._0_1_ = 0x21;
            iVar2 = (**(code **)(*local_484 + 0xb4))
                              (local_484,local_470,local_4fc,uStack_4f8,uStack_4f4,uStack_4f0);
            FUN_100045f1(local_4a0,iVar2);
            local_8._0_1_ = 0x20;
            Ordinal_6(local_470);
            local_8 = CONCAT31(local_8._1_3_,0x1f);
            Ordinal_9(&local_4cc);
            pwVar4 = local_468;
            if (local_468 != (wchar_t *)0x0) {
              local_468 = (wchar_t *)0x0;
              (**(code **)(*(int *)pwVar4 + 8))(pwVar4);
              if (local_468 != (wchar_t *)0x0) {
                FUN_10001113((int *)&local_468,(int *)0x0);
              }
            }
            piVar1 = local_46c;
            if (local_46c != (int *)0x0) {
              local_46c = (int *)0x0;
              (**(code **)(*piVar1 + 8))(piVar1);
              if (local_46c != (int *)0x0) {
                FUN_10001113((int *)&local_46c,(int *)0x0);
              }
            }
            piVar1 = local_478;
            if (local_478 != (int *)0x0) {
              local_478 = (int *)0x0;
              (**(code **)(*piVar1 + 8))(piVar1);
              if (local_478 != (int *)0x0) {
                FUN_10001113((int *)&local_478,(int *)0x0);
              }
            }
            local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
            local_8._0_1_ = 0x1a;
            if (local_478 != (int *)0x0) {
              (**(code **)(*local_478 + 8))(local_478);
            }
            local_8._0_1_ = 0x18;
            if (local_46c != (int *)0x0) {
              (**(code **)(*local_46c + 8))(local_46c);
            }
            local_8 = CONCAT31(local_8._1_3_,0x11);
            if (local_468 != (wchar_t *)0x0) {
              (**(code **)(*(int *)local_468 + 8))(local_468);
            }
          }
          FUN_10004a4a(local_224);
          piVar1 = local_474;
          if (local_474 != (int *)0x0) {
            local_474 = (int *)0x0;
            (**(code **)(*piVar1 + 8))(piVar1);
          }
          piVar1 = local_488;
          if (local_488 != (int *)0x0) {
            local_488 = (int *)0x0;
            (**(code **)(*piVar1 + 8))(piVar1);
          }
          piVar1 = local_480;
          if (local_480 != (int *)0x0) {
            local_480 = (int *)0x0;
            (**(code **)(*piVar1 + 8))(piVar1);
          }
          piVar1 = local_47c;
          if (local_47c != (int *)0x0) {
            local_47c = (int *)0x0;
            (**(code **)(*piVar1 + 8))(piVar1);
          }
          local_8._0_1_ = 0x10;
          Ordinal_9(&local_53c);
          local_8._0_1_ = 0xf;
          FID_conflict__Tidy(local_448,'\x01',0);
          local_8._0_1_ = 10;
          if (local_474 != (int *)0x0) {
            (**(code **)(*local_474 + 8))(local_474);
          }
          local_8._0_1_ = 8;
          if (local_480 != (int *)0x0) {
            (**(code **)(*local_480 + 8))(local_480);
          }
          local_8._0_1_ = 6;
          if (local_488 != (int *)0x0) {
            (**(code **)(*local_488 + 8))(local_488);
          }
        }
        local_8._0_1_ = 5;
        FID_conflict__Tidy(local_464,'\x01',0);
        local_8._0_1_ = 3;
        if (local_47c != (int *)0x0) {
          (**(code **)(*local_47c + 8))(local_47c);
        }
        local_8._0_1_ = 2;
        FUN_100147f2(&local_4bc);
      }
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    ATL::CRegKey::Close((CRegKey *)&local_4e8);
    local_8 = 0xffffffff;
  }
LAB_100067f5:
  FUN_10014f93();
  return;
}



// Function: Catch@100067fd at 100067fd

undefined4 Catch_100067fd(void)

{
  int unaff_EBP;
  
  FUN_100045f1((void *)(unaff_EBP + -0x49c),-0x7fffbffb);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x100067eb;
}



// Function: FUN_10006817 at 10006817

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10006817(void *param_1,int *param_2,wchar_t *param_3,int param_4,int *param_5)

{
  void *pvVar1;
  int iVar2;
  LPCWSTR *ppWVar3;
  undefined4 *puVar4;
  size_t sVar5;
  wchar_t *_Str;
  undefined4 ***pppuVar6;
  code *pcVar7;
  int *piVar8;
  uint local_520;
  undefined4 uStack_51c;
  undefined4 local_518;
  undefined4 uStack_514;
  undefined4 local_510;
  undefined4 uStack_50c;
  undefined4 uStack_508;
  undefined4 uStack_504;
  uint local_500;
  undefined4 uStack_4fc;
  undefined4 uStack_4f8;
  undefined4 uStack_4f4;
  DWORD local_4f0;
  uint local_4ec;
  undefined4 uStack_4e8;
  undefined4 uStack_4e4;
  undefined4 uStack_4e0;
  undefined4 local_4dc;
  undefined4 local_4d8;
  undefined4 local_4d4;
  int local_4d0;
  int local_4cc;
  int local_4c8;
  undefined4 local_4c4 [3];
  int local_4b8;
  undefined4 local_4b4;
  int *local_4b0;
  int local_4ac;
  int *local_4a8;
  int local_4a4;
  int local_4a0;
  void *local_49c;
  int local_498;
  int local_494;
  int *local_490;
  int *local_48c;
  int *local_488;
  int *local_484;
  int *local_480;
  int *local_47c;
  int *local_478;
  wchar_t *local_474;
  int *local_470;
  int *local_46c;
  int *local_468;
  undefined4 local_464 [7];
  undefined4 **local_448 [4];
  undefined4 local_438;
  uint local_434;
  wchar_t local_42c [260];
  wchar_t local_224 [270];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x510;
  local_8 = 0x10006826;
  local_49c = param_1;
  local_46c = param_2;
  local_474 = param_3;
  local_4a4 = param_4;
  local_4b0 = param_5;
  FUN_10001c46(local_4c4);
  local_8 = 0;
  FUN_100045f1(local_4c4,0);
  local_8._0_1_ = 1;
  if (param_5 == (int *)0x0) {
    local_8 = 0xffffffff;
    FUN_100012a2(local_4c4);
  }
  else {
    local_484 = (int *)0x0;
    for (piVar8 = DAT_10029320; piVar8 != DAT_10029324; piVar8 = piVar8 + 3) {
      if ((local_484 != local_46c) &&
         (local_4a8 = piVar8, iVar2 = _wcsicmp((wchar_t *)*piVar8,param_3), iVar2 == 0)) {
        local_8 = 0xffffffff;
        FUN_100012a2(local_4c4);
        goto LAB_10007222;
      }
      local_484 = (int *)((int)local_484 + 1);
    }
    local_484 = (int *)0x0;
    local_4b4 = 0;
    local_8._0_1_ = 2;
    for (piVar8 = DAT_10029320; pcVar7 = Ordinal_6_exref, local_4a8 = piVar8, piVar8 != DAT_10029324
        ; piVar8 = piVar8 + 3) {
      if (local_484 == local_46c) {
        FUN_100016db(&local_4b4,*piVar8);
        if (param_3 == (wchar_t *)0x0) {
          local_494 = 0;
        }
        else {
          local_494 = Ordinal_2(param_3);
          if (local_494 == 0) goto LAB_100069c5;
        }
        local_8._0_1_ = 3;
        iVar2 = FUN_10001718(&local_494);
        *piVar8 = iVar2;
        pcVar7 = Ordinal_6_exref;
        local_8._0_1_ = 2;
        Ordinal_6(local_494);
        piVar8[1] = param_4;
        FUN_100019cb(&local_470,local_4b0);
        local_8._0_1_ = 4;
        (**(code **)*local_470)(local_470,&DAT_1001d9e0,piVar8 + 2);
        local_8._0_1_ = 2;
        if (local_470 != (int *)0x0) {
          (**(code **)(*local_470 + 8))(local_470);
        }
        break;
      }
      local_484 = (int *)((int)local_484 + 1);
    }
    local_4dc = 0;
    local_4d8 = 0;
    local_4d4 = 0;
    local_8._0_1_ = 6;
    ppWVar3 = (LPCWSTR *)DAT_10029330;
    if (DAT_10029344 < 8) {
      ppWVar3 = &DAT_10029330;
    }
    iVar2 = Open(&local_4dc,(HKEY)0x80000002,(LPCWSTR)ppWVar3,0x2001f);
    if (iVar2 == 0) {
      local_4f0 = 0x20a;
      ppWVar3 = (LPCWSTR *)DAT_1002934c;
      if (DAT_10029360 < 8) {
        ppWVar3 = &DAT_1002934c;
      }
      FUN_100013a4(&local_4dc,(LPBYTE)local_224,(LPCWSTR)ppWVar3,&local_4f0);
      ATL::CRegKey::Close((CRegKey *)&local_4dc);
      pvVar1 = local_49c;
      FUN_10004757(local_224);
      if (*(int *)((int)pvVar1 + 8) != 0) {
        FUN_100147e9(&local_494);
        local_488 = (int *)0x0;
        local_8._0_1_ = 9;
        FUN_10003c48(local_464,L"/user_manager/groups/group[@ID=");
        local_8._0_1_ = 10;
        puVar4 = (undefined4 *)FUN_100046f2(local_448,(long)local_46c);
        local_8._0_1_ = 0xb;
        FUN_10002f2f(local_464,puVar4,0,0xffffffff);
        local_8._0_1_ = 10;
        FID_conflict__Tidy(local_448,'\x01',0);
        sVar5 = wcslen(L"]");
        FUN_10003105(local_464,(undefined4 *)&DAT_1001dc4c,sVar5);
        FUN_10014818((int *)((int)pvVar1 + 8),local_464,(int *)&local_488);
        if (local_488 != (int *)0x0) {
          local_468 = (int *)0x0;
          local_8._0_1_ = 0xd;
          iVar2 = (**(code **)*local_488)(local_488,&DAT_1001da9c,&local_468);
          FUN_100045f1(local_4c4,iVar2);
          local_46c = (int *)0x0;
          local_8 = CONCAT31(local_8._1_3_,0xf);
          (**(code **)(*local_468 + 0x30))(local_468,&local_46c);
          local_4c8 = 0;
          (**(code **)(*local_46c + 0x20))(local_46c,&local_4c8);
          for (local_4ac = 0; local_4ac < local_4c8; local_4ac = local_4ac + 1) {
            local_470 = (int *)0x0;
            local_8 = CONCAT31(local_8._1_3_,0x11);
            (**(code **)(*local_46c + 0x24))(local_46c,&local_470);
            if ((-1 < local_4b8) &&
               ((**(code **)(*local_468 + 0x50))(local_468,local_470,0), piVar8 = local_470,
               local_470 != (int *)0x0)) {
              local_470 = (int *)0x0;
              (**(code **)(*piVar8 + 8))(piVar8);
            }
            local_8 = CONCAT31((int3)((uint)local_8 >> 8),0xf);
            if (local_470 != (int *)0x0) {
              (**(code **)(*local_470 + 8))(local_470);
            }
          }
          local_434 = 7;
          local_438 = 0;
          local_448[0] = (undefined4 **)((uint)local_448[0] & 0xffff0000);
          local_8._0_1_ = 0x13;
          local_500 = local_500 & 0xffff0000;
          FUN_10001965(&local_500,(int)local_474);
          local_8._0_1_ = 0x14;
          local_4ec = local_500;
          uStack_4e8 = uStack_4fc;
          uStack_4e4 = uStack_4f8;
          uStack_4e0 = uStack_4f4;
          local_48c = local_468;
          local_4a0 = Ordinal_2(L"name");
          if (local_4a0 == 0) {
LAB_100069c5:
                    /* WARNING: Subroutine does not return */
            FUN_100010d9(-0x7ff8fff2);
          }
          local_8._0_1_ = 0x15;
          iVar2 = (**(code **)(*local_48c + 0xb4))
                            (local_48c,local_4a0,local_4ec,uStack_4e8,uStack_4e4,uStack_4e0);
          FUN_100045f1(local_4c4,iVar2);
          local_8._0_1_ = 0x14;
          (*pcVar7)(local_4a0);
          local_8._0_1_ = 0x13;
          Ordinal_9(&local_500);
          _Str = _ltow(local_4a4,local_42c,10);
          sVar5 = wcslen(_Str);
          FID_conflict_assign(local_448,(undefined4 *)_Str,sVar5);
          pppuVar6 = (undefined4 ***)local_448[0];
          if (local_434 < 8) {
            pppuVar6 = local_448;
          }
          local_510 = (uint)local_510._2_2_ << 0x10;
          FUN_10001965(&local_510,(int)pppuVar6);
          local_8._0_1_ = 0x16;
          local_4ec = local_510;
          uStack_4e8 = uStack_50c;
          uStack_4e4 = uStack_508;
          uStack_4e0 = uStack_504;
          local_48c = local_468;
          local_490 = (int *)Ordinal_2(L"groupType");
          if (local_490 == (int *)0x0) goto LAB_100069c5;
          local_8._0_1_ = 0x17;
          iVar2 = (**(code **)(*local_48c + 0xb4))
                            (local_48c,local_490,local_4ec,uStack_4e8,uStack_4e4,uStack_4e0);
          FUN_100045f1(local_4c4,iVar2);
          local_8._0_1_ = 0x16;
          (*pcVar7)(local_490);
          local_8._0_1_ = 0x13;
          Ordinal_9(&local_510);
          local_4d0 = 0;
          (**(code **)(*local_4b0 + 0x20))(local_4b0,&local_4d0);
          for (local_498 = 1; local_498 <= local_4d0; local_498 = local_498 + 1) {
            local_480 = (int *)0x0;
            local_478 = (int *)0x0;
            local_520 = CONCAT22(local_520._2_2_,3);
            local_518 = 1;
            local_8._0_1_ = 0x1c;
            local_510 = local_520;
            uStack_50c = uStack_51c;
            uStack_508 = 1;
            uStack_504 = uStack_514;
            local_490 = *(int **)((int)local_49c + 8);
            local_4a4 = Ordinal_2(&DAT_1001dbfc);
            if (local_4a4 == 0) goto LAB_100069c5;
            local_8._0_1_ = 0x1d;
            local_4cc = Ordinal_2(L"Right");
            if (local_4cc == 0) goto LAB_100069c5;
            local_8._0_1_ = 0x1e;
            iVar2 = (**(code **)(*local_490 + 0xe0))
                              (local_490,local_510,uStack_50c,uStack_508,uStack_504,local_4cc,
                               local_4a4,&local_480);
            FUN_100045f1(local_4c4,iVar2);
            local_8._0_1_ = 0x1d;
            (*pcVar7)(local_4cc);
            local_8._0_1_ = 0x1c;
            (*pcVar7)(local_4a4);
            local_8._0_1_ = 0x1b;
            Ordinal_9(&local_520);
            iVar2 = (**(code **)(*local_468 + 0x54))(local_468,local_480,&local_478);
            FUN_100045f1(local_4c4,iVar2);
            local_47c = (int *)0x0;
            local_8._0_1_ = 0x20;
            iVar2 = (**(code **)*local_478)(local_478,&DAT_1001da9c,&local_47c);
            FUN_100045f1(local_4c4,iVar2);
            (**(code **)(*local_4b0 + 0x1c))(local_4b0,local_498,&local_4a0);
            local_4ec = local_4ec & 0xffff0000;
            FUN_10001965(&local_4ec,local_4a0);
            local_8._0_1_ = 0x21;
            local_500 = local_4ec;
            uStack_4fc = uStack_4e8;
            uStack_4f8 = uStack_4e4;
            uStack_4f4 = uStack_4e0;
            local_490 = local_47c;
            local_48c = (int *)Ordinal_2(&DAT_1001dc44);
            if (local_48c == (int *)0x0) goto LAB_100069c5;
            local_8._0_1_ = 0x22;
            iVar2 = (**(code **)(*local_490 + 0xb4))
                              (local_490,local_48c,local_500,uStack_4fc,uStack_4f8,uStack_4f4);
            FUN_100045f1(local_4c4,iVar2);
            local_8._0_1_ = 0x21;
            (*pcVar7)(local_48c);
            local_8 = CONCAT31(local_8._1_3_,0x20);
            Ordinal_9(&local_4ec);
            piVar8 = local_480;
            if (local_480 != (int *)0x0) {
              local_480 = (int *)0x0;
              (**(code **)(*piVar8 + 8))(piVar8);
              if (local_480 != (int *)0x0) {
                FUN_10001113((int *)&local_480,(int *)0x0);
              }
            }
            piVar8 = local_478;
            if (local_478 != (int *)0x0) {
              local_478 = (int *)0x0;
              (**(code **)(*piVar8 + 8))(piVar8);
              if (local_478 != (int *)0x0) {
                FUN_10001113((int *)&local_478,(int *)0x0);
              }
            }
            piVar8 = local_47c;
            if (local_47c != (int *)0x0) {
              local_47c = (int *)0x0;
              (**(code **)(*piVar8 + 8))(piVar8);
              if (local_47c != (int *)0x0) {
                FUN_10001113((int *)&local_47c,(int *)0x0);
              }
            }
            local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
            local_8._0_1_ = 0x1b;
            if (local_47c != (int *)0x0) {
              (**(code **)(*local_47c + 8))(local_47c);
            }
            local_8._0_1_ = 0x19;
            if (local_478 != (int *)0x0) {
              (**(code **)(*local_478 + 8))(local_478);
            }
            local_8._0_1_ = 0x13;
            if (local_480 != (int *)0x0) {
              (**(code **)(*local_480 + 8))(local_480);
            }
          }
          if (local_474 == (wchar_t *)0x0) {
            local_474 = (wchar_t *)0x0;
          }
          else {
            local_474 = (wchar_t *)Ordinal_2(local_474);
            if (local_474 == (wchar_t *)0x0) goto LAB_100069c5;
          }
          local_8._0_1_ = 0x26;
          FUN_10001fd0(local_49c,&local_4b4,(int *)&local_474);
          local_8 = CONCAT31(local_8._1_3_,0x13);
          (*pcVar7)(local_474);
          FUN_10004a4a(local_224);
          piVar8 = local_468;
          if (local_468 != (int *)0x0) {
            local_468 = (int *)0x0;
            (**(code **)(*piVar8 + 8))(piVar8);
          }
          piVar8 = local_488;
          if (local_488 != (int *)0x0) {
            local_488 = (int *)0x0;
            (**(code **)(*piVar8 + 8))(piVar8);
          }
          local_8._0_1_ = 0xf;
          FID_conflict__Tidy(local_448,'\x01',0);
          local_8._0_1_ = 0xd;
          if (local_46c != (int *)0x0) {
            (**(code **)(*local_46c + 8))(local_46c);
          }
          local_8._0_1_ = 10;
          if (local_468 != (int *)0x0) {
            (**(code **)(*local_468 + 8))(local_468);
          }
        }
        local_8._0_1_ = 9;
        FID_conflict__Tidy(local_464,'\x01',0);
        local_8._0_1_ = 7;
        if (local_488 != (int *)0x0) {
          (**(code **)(*local_488 + 8))(local_488);
        }
        local_8._0_1_ = 6;
        FUN_100147f2(&local_494);
      }
    }
    local_8._0_1_ = 2;
    ATL::CRegKey::Close((CRegKey *)&local_4dc);
    local_8 = CONCAT31(local_8._1_3_,1);
    (*pcVar7)(local_4b4);
    local_8 = 0xffffffff;
  }
LAB_10007222:
  FUN_10014f93();
  return;
}



// Function: Catch@1000722a at 1000722a

undefined4 Catch_1000722a(void)

{
  int unaff_EBP;
  
  FUN_100045f1((void *)(unaff_EBP + -0x4c0),-0x7fffbffb);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10007218;
}



// Function: FUN_10007244 at 10007244

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10007244(undefined1 *param_1,undefined4 param_2,undefined4 param_3,int param_4,
                 undefined4 param_5)

{
  undefined1 *puVar1;
  int iVar2;
  LPCWSTR *ppWVar3;
  size_t sVar4;
  undefined4 *extraout_ECX;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 local_284 [3];
  int local_278;
  undefined4 local_274;
  undefined4 local_270;
  int local_26c;
  undefined4 local_268;
  int *local_264;
  DWORD local_260;
  int *local_25c;
  int *local_258;
  int local_254;
  int local_250;
  undefined1 *local_24c;
  char local_245;
  int *local_244;
  undefined4 **local_240 [5];
  uint local_22c;
  wchar_t local_224 [270];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x274;
  local_8 = 0x10007253;
  local_24c = param_1;
  local_274 = param_2;
  local_270 = param_3;
  local_26c = param_4;
  local_268 = param_5;
  FUN_10001c46(local_284);
  local_8 = 0;
  FUN_100045f1(local_284,0);
  local_8._0_1_ = 1;
  local_250 = 0;
  piVar5 = DAT_10029320;
  do {
    local_264 = piVar5;
    if (piVar5 == DAT_10029324) {
LAB_100072e8:
      if (local_250 == DAT_10028e78) {
        local_278 = -0x7fffbffb;
      }
      else {
        DAT_10028e78 = DAT_10028e78 + -1;
      }
      local_270 = 0;
      local_26c = 0;
      local_268 = 0;
      local_8._0_1_ = 3;
      ppWVar3 = (LPCWSTR *)DAT_10029330;
      if (DAT_10029344 < 8) {
        ppWVar3 = &DAT_10029330;
      }
      iVar2 = Open(&local_270,(HKEY)0x80000002,(LPCWSTR)ppWVar3,0x2001f);
      if (iVar2 == 0) {
        local_260 = 0x20a;
        ppWVar3 = (LPCWSTR *)DAT_1002934c;
        if (DAT_10029360 < 8) {
          ppWVar3 = &DAT_1002934c;
        }
        FUN_100013a4(&local_270,(LPBYTE)local_224,(LPCWSTR)ppWVar3,&local_260);
        ATL::CRegKey::Close((CRegKey *)&local_270);
        puVar1 = local_24c;
        FUN_10004757(local_224);
        if (*(int *)(puVar1 + 8) != 0) {
          FUN_100147e9(&local_254);
          local_244 = (int *)0x0;
          local_8._0_1_ = 6;
          FUN_10003c48(local_240,L"/user_manager/groups");
          local_8._0_1_ = 7;
          FUN_10014818((int *)(puVar1 + 8),local_240,(int *)&local_244);
          if (local_244 != (int *)0x0) {
            sVar4 = wcslen(L"./group");
            FID_conflict_assign(local_240,(undefined4 *)L"./group",sVar4);
            piVar5 = local_244;
            local_258 = (int *)0x0;
            local_8._0_1_ = 9;
            if (local_22c < 8) {
              local_240[0] = local_240;
            }
            if ((undefined4 ***)local_240[0] == (undefined4 ***)0x0) {
              local_24c = (undefined1 *)0x0;
            }
            else {
              local_24c = (undefined1 *)Ordinal_2();
              if (local_24c == (undefined1 *)0x0) {
LAB_1000735e:
                    /* WARNING: Subroutine does not return */
                FUN_100010d9(-0x7ff8fff2);
              }
            }
            local_8._0_1_ = 10;
            iVar2 = (**(code **)(*piVar5 + 0x90))(piVar5);
            FUN_100045f1(local_284,iVar2);
            local_8._0_1_ = 9;
            Ordinal_6(local_24c);
            if (local_258 != (int *)0x0) {
              local_25c = (int *)0x0;
              local_8._0_1_ = 0xc;
              iVar2 = (**(code **)(*local_258 + 0x1c))(local_258);
              FUN_100045f1(local_284,iVar2);
              if (-1 < local_278) {
                (**(code **)(*local_244 + 0x50))(local_244);
                local_24c = &stack0xfffffd64;
                puVar6 = extraout_ECX;
                iVar2 = local_250;
                FUN_1000d6aa(&stack0xfffffd64,(int *)&local_244);
                local_8._0_1_ = 0xc;
                FUN_10004fa7(puVar6,iVar2);
                FUN_10004a4a(local_224);
                piVar5 = local_25c;
                if (local_25c != (int *)0x0) {
                  local_25c = (int *)0x0;
                  (**(code **)(*piVar5 + 8))();
                }
              }
              piVar5 = local_258;
              if (local_258 != (int *)0x0) {
                local_258 = (int *)0x0;
                (**(code **)(*piVar5 + 8))();
              }
              local_8._0_1_ = 9;
              if (local_25c != (int *)0x0) {
                (**(code **)(*local_25c + 8))();
              }
            }
            piVar5 = local_244;
            if (local_244 != (int *)0x0) {
              local_244 = (int *)0x0;
              (**(code **)(*piVar5 + 8))();
            }
            local_8._0_1_ = 7;
            if (local_258 != (int *)0x0) {
              (**(code **)(*local_258 + 8))();
            }
          }
          local_8._0_1_ = 6;
          FID_conflict__Tidy(local_240,'\x01',0);
          local_8._0_1_ = 4;
          if (local_244 != (int *)0x0) {
            (**(code **)(*local_244 + 8))();
          }
          local_8._0_1_ = 3;
          FUN_100147f2(&local_254);
        }
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      ATL::CRegKey::Close((CRegKey *)&local_270);
      local_8 = 0xffffffff;
      FUN_10014f93();
      return;
    }
    if ((short)local_274 != 3) {
      if (*piVar5 == 0) {
        local_254 = 0;
      }
      else {
        local_254 = Ordinal_2();
        if (local_254 == 0) goto LAB_1000735e;
      }
      local_8._0_1_ = 2;
      local_245 = FUN_10001821(&local_254,local_26c);
      local_8._0_1_ = 1;
      Ordinal_6();
      if (local_245 == '\0') goto LAB_10007368;
      Ordinal_6();
LAB_100072cd:
      (**(code **)(*(int *)piVar5[2] + 8))();
      FUN_10003a9c(&DAT_10029320,&local_260,piVar5);
      goto LAB_100072e8;
    }
    if (local_250 == local_26c) {
      Ordinal_6();
      goto LAB_100072cd;
    }
LAB_10007368:
    piVar5 = piVar5 + 3;
    local_250 = local_250 + 1;
  } while( true );
}



// Function: Catch@1000767c at 1000767c

undefined4 Catch_1000767c(void)

{
  int unaff_EBP;
  
  FUN_100045f1((void *)(unaff_EBP + -0x280),-0x7fffbffb);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000766a;
}



// Function: FUN_10007696 at 10007696

void __fastcall FUN_10007696(undefined4 *param_1)

{
  undefined4 *local_8;
  
  local_8 = param_1;
  FUN_10005665(param_1,&local_8,(undefined4 *)*param_1,(undefined4 *)param_1[1]);
  return;
}



// Function: FUN_100076ac at 100076ac

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100076ac(int param_1)

{
  FUN_10004315((_Container_base0 *)(param_1 + 4));
  return;
}



// Function: _Uninitialized_move<> at 100076cd

/* Library Function - Multiple Matches With Same Base Name
    class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > * __cdecl
   std::_Uninitialized_move<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned
   char> > *,class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > *,struct
   std::_Wrap_alloc<class std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > > > >(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > *,struct std::_Wrap_alloc<class
   std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > > >
   &)
    class std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned
   char,class Concurrency::details::_CancellationTokenState *> > > * __cdecl
   std::_Uninitialized_move<class std::shared_ptr<struct Concurrency::details::_Task_impl<struct
   std::pair<unsigned char,class Concurrency::details::_CancellationTokenState *> > > *,class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,struct std::_Wrap_alloc<class
   std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<struct
   std::pair<unsigned char,class Concurrency::details::_CancellationTokenState *> > > > > >(class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,struct std::_Wrap_alloc<class
   std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<struct
   std::pair<unsigned char,class Concurrency::details::_CancellationTokenState *> > > > > &)
   
   Library: Visual Studio 2012 Release */

void __cdecl
_Uninitialized_move<>(undefined4 *param_1,undefined4 *param_2,void *param_3,undefined4 param_4)

{
  FUN_10005dc9(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_100076ec at 100076ec

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_100076ec(int param_1)

{
  short sVar1;
  LPCWSTR pWVar2;
  int iVar3;
  LSTATUS LVar4;
  int *piVar5;
  undefined4 *puVar6;
  int *piVar7;
  char cVar8;
  int aiStack_330 [4];
  undefined4 local_320;
  undefined4 uStack_31c;
  int local_314;
  undefined4 local_310;
  undefined4 local_30c;
  undefined4 local_308;
  DWORD local_300;
  undefined4 local_2fc;
  undefined4 local_2f8;
  undefined4 local_2f4;
  undefined4 local_2f0;
  int local_2ec;
  int *local_2e8;
  int local_2e4;
  undefined4 local_2e0;
  int *local_2dc;
  int *local_2d8;
  int *local_2d4;
  int local_2d0;
  undefined1 local_2cc [56];
  undefined4 local_294 [7];
  undefined1 local_278 [28];
  undefined2 local_25c [8];
  undefined4 local_24c;
  undefined4 local_248;
  wchar_t local_240 [8];
  undefined4 local_230;
  undefined4 local_22c;
  wchar_t local_224 [270];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x310;
  local_8 = 0x100076fb;
  FUN_10001c46(&local_320);
  local_8 = 0;
  FUN_100045f1(&local_320,0);
  local_8._0_1_ = 1;
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_1000561d((void *)(param_1 + 0x10));
    local_2fc = 0;
    local_2f8 = 0;
    local_2f4 = 0;
    local_8._0_1_ = 2;
    pWVar2 = DAT_10029330;
    if (DAT_10029344 < 8) {
      pWVar2 = (LPCWSTR)&DAT_10029330;
    }
    iVar3 = Open(&local_2fc,(HKEY)0x80000002,pWVar2,0x2001f);
    if (iVar3 == 0) {
      local_300 = 0x20a;
      pWVar2 = DAT_10029368;
      if (DAT_1002937c < 8) {
        pWVar2 = (LPCWSTR)&DAT_10029368;
      }
      LVar4 = FUN_100013a4(&local_2fc,(LPBYTE)local_224,pWVar2,&local_300);
      if (LVar4 == 0) {
        piVar5 = FUN_10001ec7(&local_2dc,'\0');
        local_8._0_1_ = 3;
        piVar7 = (int *)(param_1 + 0xc);
        FUN_100021a4(piVar7,piVar5);
        local_8._0_1_ = 2;
        if (local_2dc != (int *)0x0) {
          (**(code **)(*local_2dc + 8))(local_2dc);
        }
        iVar3 = (**(code **)(*(int *)*piVar7 + 0x110))((int *)*piVar7,0);
        uStack_31c = 0x10007802;
        FUN_100045f1(&local_320,iVar3);
        local_2dc = aiStack_330;
        FUN_10003c48(aiStack_330,local_224);
        local_8._0_1_ = 2;
        sVar1 = FUN_1000534d();
        if (sVar1 == -1) {
          FUN_100147e9(&local_2e0);
          local_2d8 = (int *)0x0;
          local_8._0_1_ = 8;
          FUN_10014818(piVar7,(undefined4 *)&DAT_10028e7c,(int *)&local_2d8);
          piVar7 = local_2d8;
          if (local_2d8 != (int *)0x0) {
            local_2d4 = (int *)0x0;
            local_8._0_1_ = 10;
            puVar6 = DAT_10029020;
            if (DAT_10029034 < 8) {
              puVar6 = &DAT_10029020;
            }
            if (puVar6 == (undefined4 *)0x0) {
              local_2ec = 0;
            }
            else {
              local_2ec = Ordinal_2(puVar6);
              if (local_2ec == 0) {
                    /* WARNING: Subroutine does not return */
                FUN_100010d9(-0x7ff8fff2);
              }
            }
            local_8._0_1_ = 0xb;
            iVar3 = (**(code **)(*piVar7 + 0x90))(piVar7,local_2ec,&local_2d4);
            FUN_100045f1(&local_320,iVar3);
            local_8._0_1_ = 10;
            Ordinal_6(local_2ec);
            if (local_2d4 != (int *)0x0) {
              local_2dc = (int *)0x0;
              iVar3 = (**(code **)(*local_2d4 + 0x20))(local_2d4,&local_2dc);
              FUN_100045f1(&local_320,iVar3);
              local_310 = 0;
              local_30c = 0;
              local_308 = 0;
              local_8 = CONCAT31(local_8._1_3_,0xc);
              FUN_10005665(&local_310,&local_2ec,(undefined4 *)0x0,(undefined4 *)0x0);
              for (local_2e4 = 0; piVar7 = local_2d4, local_2e4 < (int)local_2dc;
                  local_2e4 = local_2e4 + 1) {
                local_2e8 = (int *)0x0;
                local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
                local_8._0_1_ = 0xe;
                iVar3 = (**(code **)(*local_2d4 + 0x1c))(local_2d4,local_2e4,&local_2e8);
                FUN_100045f1(&local_320,iVar3);
                if (-1 < local_314) {
                  local_248 = 7;
                  local_24c = 0;
                  local_25c[0] = 0;
                  local_8._0_1_ = 0xf;
                  FUN_10014899((int *)&local_2e8,(undefined4 *)&DAT_1002903c,local_25c);
                  local_22c = 7;
                  local_230 = 0;
                  local_240[0] = L'\0';
                  local_8._0_1_ = 0x10;
                  FUN_10014899((int *)&local_2e8,(undefined4 *)&DAT_10029058,local_240);
                  iVar3 = FUN_10001fa0(local_240);
                  FUN_10002c95((undefined2 *)local_294);
                  local_8._0_1_ = 0x11;
                  FUN_100031a7(local_278,(undefined4 *)local_25c,0,0xffffffff);
                  FUN_100031a7(local_294,(undefined4 *)(&DAT_10028e7c + iVar3 * 0x1c),0,0xffffffff);
                  local_2d0 = iVar3;
                  FUN_10003bce(local_2cc,local_294);
                  local_8._0_1_ = 0x14;
                  cVar8 = '\0';
                  piVar7 = (int *)FUN_10005d79((void *)(param_1 + 0x10),&local_2d0);
                  FUN_1000460d((void *)(param_1 + 0x10),&local_2f0,piVar7,cVar8);
                  local_8._0_1_ = 0x11;
                  FUN_10002ccf(local_2cc);
                  local_8._0_1_ = 0x10;
                  FUN_10002ccf(local_294);
                  local_8._0_1_ = 0xf;
                  FID_conflict__Tidy(local_240,'\x01',0);
                  local_8._0_1_ = 0xe;
                  FID_conflict__Tidy(local_25c,'\x01',0);
                }
                local_8 = CONCAT31(local_8._1_3_,0xc);
                if (local_2e8 != (int *)0x0) {
                  (**(code **)(*local_2e8 + 8))(local_2e8);
                }
              }
              if (local_2d4 != (int *)0x0) {
                local_2d4 = (int *)0x0;
                (**(code **)(*piVar7 + 8))(piVar7);
              }
              local_8._0_1_ = 10;
              FUN_10004315((_Container_base0 *)&local_310);
            }
            piVar7 = local_2d8;
            if (local_2d8 != (int *)0x0) {
              local_2d8 = (int *)0x0;
              (**(code **)(*piVar7 + 8))(piVar7);
            }
            local_8._0_1_ = 8;
            if (local_2d4 != (int *)0x0) {
              (**(code **)(*local_2d4 + 8))(local_2d4);
            }
          }
          local_8._0_1_ = 6;
          if (local_2d8 != (int *)0x0) {
            (**(code **)(*local_2d8 + 8))(local_2d8);
          }
          local_8._0_1_ = 2;
          FUN_100147f2(&local_2e0);
        }
      }
      ATL::CRegKey::Close((CRegKey *)&local_2fc);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    ATL::CRegKey::Close((CRegKey *)&local_2fc);
  }
  local_8 = 0xffffffff;
  FUN_10014f93();
  return;
}



// Function: Catch@10007bc8 at 10007bc8

undefined4 Catch_10007bc8(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10007bbe;
}



// Function: FUN_10007bd2 at 10007bd2

_Container_base0 * __thiscall FUN_10007bd2(void *this,_Container_base0 *param_1)

{
  undefined4 *puVar1;
  _Container_base0 *p_Var2;
  _Container_base0 *p_Var3;
  void *pvVar4;
  undefined4 uVar5;
  
  p_Var2 = param_1;
  if ((_Container_base0 *)this != param_1) {
    std::_Container_base0::_Orphan_all((_Container_base0 *)this);
    param_1 = (_Container_base0 *)((*(int *)(p_Var2 + 4) - *(int *)p_Var2) / 0x1c);
    if (param_1 == (_Container_base0 *)0x0) {
                    /* WARNING: Load size is inaccurate */
      FUN_10005665(this,&param_1,*this,*(undefined4 **)((int)this + 4));
    }
    else {
                    /* WARNING: Load size is inaccurate */
      pvVar4 = *this;
      p_Var3 = (_Container_base0 *)(((int)*(undefined4 **)((int)this + 4) - (int)pvVar4) / 0x1c);
      if (p_Var3 < param_1) {
        if ((_Container_base0 *)((*(int *)((int)this + 8) - (int)pvVar4) / 0x1c) < param_1) {
                    /* WARNING: Load size is inaccurate */
          if (*this != (void *)0x0) {
            FUN_10003de5(*this,*(void **)((int)this + 4),(int)this + 0xc);
                    /* WARNING: Load size is inaccurate */
            operator_delete(*this);
          }
          uVar5 = FUN_10002d63(this,(char *)((*(int *)(p_Var2 + 4) - *(int *)p_Var2) / 0x1c));
          if ((char)uVar5 == '\0') {
            return (_Container_base0 *)this;
          }
                    /* WARNING: Load size is inaccurate */
          pvVar4 = FUN_10003e04(*(undefined4 **)p_Var2,*(undefined4 **)(p_Var2 + 4),*this,
                                (int)this + 0xc);
        }
        else {
                    /* WARNING: Load size is inaccurate */
          puVar1 = *(undefined4 **)p_Var2 + (int)p_Var3 * 7;
          FUN_10003b49(*(undefined4 **)p_Var2,puVar1,*this);
          pvVar4 = FUN_10003e04(puVar1,*(undefined4 **)(p_Var2 + 4),*(void **)((int)this + 4),
                                (int)this + 0xc);
        }
      }
      else {
        pvVar4 = FUN_10003b49(*(undefined4 **)p_Var2,*(undefined4 **)(p_Var2 + 4),pvVar4);
        FUN_10003de5(pvVar4,*(void **)((int)this + 4),(int)this + 0xc);
                    /* WARNING: Load size is inaccurate */
        pvVar4 = (void *)(((*(int *)(p_Var2 + 4) - *(int *)p_Var2) / 0x1c) * 0x1c + *this);
      }
      *(void **)((int)this + 4) = pvVar4;
    }
  }
  return (_Container_base0 *)this;
}



// Function: FUN_10007cf5 at 10007cf5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10007cf5(void *param_1)

{
  undefined4 local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  local_14 = param_1;
  FUN_100056a9(param_1,&local_18,(int *)**(int **)((int)param_1 + 4),*(int **)((int)param_1 + 4));
  local_8 = 0xffffffff;
  operator_delete(*(void **)((int)param_1 + 4));
  return;
}



// Function: FUN_10007d2f at 10007d2f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10007d2f(int param_1)

{
  FUN_10004315((_Container_base0 *)(param_1 + 8));
  return;
}



// Function: FUN_10007d5a at 10007d5a

void __thiscall FUN_10007d5a(void *this,undefined4 *param_1,undefined4 *param_2,void *param_3)

{
  _Uninitialized_move<>(param_1,param_2,param_3,(int)this + 0xc);
  return;
}



// Function: FUN_10007d76 at 10007d76

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10007d76(int param_1)

{
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined ***)(param_1 + 4) =
       ATL::
       ICollectionOnSTLImpl<struct_IBSTRCollection,class_std::vector<class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>,class_std::allocator<class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_>_>,unsigned_short*,class__CopyStringToBSTR,class_ATL::CComEnumOnSTL<struct_IEnumVARIANT,&struct__GUID_const_IID_IEnumVARIANT,struct_tagVARIANT,class__CopyStringToVARIANT,class_std::vector<class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>,class_std::allocator<class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_>_>,class_ATL::CComSingleThreadModel>_>
       ::vftable;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}



// Function: FUN_10007dab at 10007dab

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10007dab(void *param_1)

{
  FUN_10007cf5(param_1);
  return;
}



// Function: FUN_10007dc9 at 10007dc9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10007dc9(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 0xc);
  if ((*piVar1 != 0) && (piVar2 = (int *)*piVar1, piVar2 != (int *)0x0)) {
    *piVar1 = 0;
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  FUN_1000561d((void *)(param_1 + 0x10));
  FUN_10007cf5((void *)(param_1 + 0x10));
  piVar1 = (int *)*piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10007e4b at 10007e4b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_10007e4b(int param_1)

{
  int aiStack_30 [5];
  undefined1 *local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10007e57;
  local_1c = (undefined1 *)aiStack_30;
  aiStack_30[0] = param_1;
  local_18 = param_1;
  FUN_10002df0(param_1);
  return local_18;
}



// Function: FUN_10007e77 at 10007e77

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_10007e77(void *this,char *param_1)

{
  int iVar1;
  void *pvVar2;
  void *pvVar3;
  
  if ((char *)0x9249249 < param_1) {
    std::_Xlength_error("vector<T> too long");
  }
                    /* WARNING: Load size is inaccurate */
  if ((char *)((*(int *)((int)this + 8) - *this) / 0x1c) < param_1) {
    pvVar3 = FUN_10001c71(param_1);
                    /* WARNING: Load size is inaccurate */
    FUN_10007d5a(this,*this,*(undefined4 **)((int)this + 4),pvVar3);
    iVar1 = *(int *)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
    pvVar2 = *this;
    if (pvVar2 != (void *)0x0) {
      FUN_10003de5(pvVar2,*(void **)((int)this + 4),(int)this + 0xc);
                    /* WARNING: Load size is inaccurate */
      operator_delete(*this);
    }
    std::_Container_base0::_Orphan_all((_Container_base0 *)this);
    *(void **)((int)this + 8) = (void *)((int)param_1 * 0x1c + (int)pvVar3);
    *(void **)((int)this + 4) = (void *)(((iVar1 - (int)pvVar2) / 0x1c) * 0x1c + (int)pvVar3);
    *(void **)this = pvVar3;
  }
  return;
}



// Function: Catch@10007f1e at 10007f1e

void Catch_10007f1e(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 8));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10007f31 at 10007f31

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10007f31(undefined4 *param_1)

{
  FUN_10007d76((int)param_1);
  *param_1 = ATL::
             CComObject<class_CComCollection<class_COMCollectionTraits<class_ATL::ICollectionOnSTLImpl<struct_IBSTRCollection,class_std::vector<class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>,class_std::allocator<class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_>_>,unsigned_short*,class__CopyStringToBSTR,class_ATL::CComEnumOnSTL<struct_IEnumVARIANT,&struct__GUID_const_IID_IEnumVARIANT,struct_tagVARIANT,class__CopyStringToVARIANT,class_std::vector<class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>,class_std::allocator<class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_>_>,class_ATL::CComSingleThreadModel>_>,struct_IBSTRCollection,&struct__GUID_const_IID_IBSTRCollection,&struct__GUID_const_LIBID_COLLECTIONLib>,&struct__GUID_const_IID_IBSTRCollection,&struct__GUID_const_LIBID_COLLECTIONLib,&struct__GUID_const_GUID_NULL>_>
             ::vftable;
  param_1[1] = ATL::
               CComObject<class_CComCollection<class_COMCollectionTraits<class_ATL::ICollectionOnSTLImpl<struct_IBSTRCollection,class_std::vector<class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>,class_std::allocator<class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_>_>,unsigned_short*,class__CopyStringToBSTR,class_ATL::CComEnumOnSTL<struct_IEnumVARIANT,&struct__GUID_const_IID_IEnumVARIANT,struct_tagVARIANT,class__CopyStringToVARIANT,class_std::vector<class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>,class_std::allocator<class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_>_>,class_ATL::CComSingleThreadModel>_>,struct_IBSTRCollection,&struct__GUID_const_IID_IBSTRCollection,&struct__GUID_const_LIBID_COLLECTIONLib>,&struct__GUID_const_IID_IBSTRCollection,&struct__GUID_const_LIBID_COLLECTIONLib,&struct__GUID_const_GUID_NULL>_>
               ::vftable;
  (**(code **)(*DAT_10029388 + 4))();
  return param_1;
}



// Function: AtlComQIPtrAssign at 10007f71

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



// Function: Attach at 10007fa8

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



// Function: FUN_10007fc7 at 10007fc7

undefined4 FUN_10007fc7(void)

{
  return 0;
}



// Function: FUN_10007fcc at 10007fcc

undefined4 FUN_10007fcc(undefined4 param_1,undefined4 *param_2)

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



// Function: FUN_10008012 at 10008012

undefined4 FUN_10008012(int param_1)

{
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  return *(undefined4 *)(param_1 + 0x18);
}



// Function: Release at 10008022

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



// Function: FUN_10008043 at 10008043

void FUN_10008043(void)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::Release();
  return;
}



// Function: FUN_1000804d at 1000804d

void FUN_1000804d(int param_1)

{
  FUN_10008012(param_1 + -4);
  return;
}



// Function: FUN_10008057 at 10008057

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10008057(void *this,wchar_t *param_1)

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
  uStack_4 = 0x18;
  local_8 = 0x10008063;
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
                  (puVar6,0xc,uVar2,(_func_void_void_ptr *)&LAB_10007fe9,
                   (_func_void_void_ptr *)&LAB_10001433);
      }
      local_8 = 0xffffffff;
      local_1c = puVar6;
      uVar7 = FUN_1000810f();
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



// Function: Catch@100080f7 at 100080f7

undefined * Catch_100080f7(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x24));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10008109;
}



// Function: FUN_1000810f at 1000810f

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000810f(void)

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



// Function: FUN_100081c7 at 100081c7

void FUN_100081c7(int param_1)

{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0xc);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (*(void **)(param_1 + 0x14) != (void *)0x0) {
      FUN_10001d34(*(void **)(param_1 + 0x14),3);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_100081fa at 100081fa

void __fastcall FUN_100081fa(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_10008211 at 10008211

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool __thiscall FUN_10008211(void *this,undefined4 *param_1)

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
    (**(code **)**this)(*this,&DAT_1001dcfc,&local_18);
    (**(code **)*param_1)(param_1,&DAT_1001dcfc,local_14);
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



// Function: QueryInterface at 1000829c

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1001ddb8,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_100082b6 at 100082b6

void FUN_100082b6(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_100082c0 at 100082c0

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100082c0(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 0x80070057;
  }
  operator_new(0xc);
  uVar1 = FUN_10008310();
  return uVar1;
}



// Function: Catch@100082f8 at 100082f8

undefined * Catch_100082f8(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x18));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000830a;
}



// Function: FUN_10008310 at 10008310

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10008310(void)

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
    *(LPCRITICAL_SECTION *)(unaff_EBP + -0x20) = lpCriticalSection;
    *(undefined1 *)(unaff_EBP + -0x1c) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    EnterCriticalSection(lpCriticalSection);
    *(undefined1 *)(unaff_EBP + -0x1c) = 1;
    *(undefined4 *)(unaff_EBP + 8) = 0;
    unaff_ESI[2] = *(undefined4 *)(unaff_EDI + 8);
    *(undefined4 **)(unaff_EDI + 8) = unaff_ESI;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    LeaveCriticalSection(lpCriticalSection);
    *(undefined1 *)(unaff_EBP + -0x1c) = 0;
  }
  return *(undefined4 *)(unaff_EBP + 8);
}



// Function: FUN_1000836b at 1000836b

IUnknown * __thiscall FUN_1000836b(void *this,undefined4 *param_1)

{
  bool bVar1;
  IUnknown *pIVar2;
  
  bVar1 = FUN_10008211(this,(undefined4 *)*param_1);
  if (bVar1) {
                    /* WARNING: Load size is inaccurate */
    pIVar2 = *this;
  }
  else {
    pIVar2 = ATL::AtlComQIPtrAssign((IUnknown **)this,(IUnknown *)*param_1,(_GUID *)&DAT_1001de18);
  }
  return pIVar2;
}



// Function: FUN_10008398 at 10008398

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10008398(void *this,undefined4 param_1)

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
  local_8 = 0x100083a7;
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) goto LAB_100085dd;
  lpCriticalSection = (LPCRITICAL_SECTION)(DAT_10029388 + 0x10);
  local_8 = 0;
  EnterCriticalSection(lpCriticalSection);
  local_220 = -0x7fffbffb;
  if (*(int *)((int)this + 0xc) == 0) {
    piVar1 = *(int **)((int)this + 4);
    local_230 = (int *)0x0;
    iVar2 = _InlineIsEqualGUID(&DAT_1002938c,piVar1);
    if (((iVar2 == 0) || (*(short *)((int)this + 8) != -1)) || (*(short *)((int)this + 10) != -1)) {
      local_220 = Ordinal_162(piVar1,*(undefined2 *)((int)this + 8),*(undefined2 *)((int)this + 10),
                              param_1,&local_230);
    }
    else {
      DVar3 = GetModuleFileNameW(DAT_1002afd8,local_21c,0x104);
      if ((DVar3 == 0) || (DVar3 == 0x104)) goto LAB_100085a7;
      local_224 = (int *)0x0;
      local_8._0_1_ = 1;
      local_220 = Ordinal_161(local_21c,&local_230);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_100014b1((int *)&local_224);
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
        iVar2 = (**(code **)*local_228)(local_228,&DAT_1001de08,&local_224);
        if (-1 < iVar2) {
          FUN_1000836b(&local_22c,&local_224);
        }
        *(int **)((int)this + 0xc) = local_22c;
        local_22c = (int *)0x0;
        if (DAT_10029388 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = DAT_10029388 + 4;
        }
        pcVar4 = FUN_100081c7;
        pvVar5 = this;
        FUN_100082c0(iVar2);
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
LAB_100085a7:
  if ((*(wchar_t **)((int)this + 0xc) != (wchar_t *)0x0) && (*(int *)((int)this + 0x14) == 0)) {
    local_220 = FUN_10008057(this,*(wchar_t **)((int)this + 0xc));
  }
  local_8 = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
LAB_100085dd:
  FUN_10014f84();
  return;
}



// Function: FUN_100085e5 at 100085e5

undefined4 __thiscall FUN_100085e5(void *this,undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = 0;
    if (*(int *)((int)this + 0xc) == 0) {
      uVar1 = FUN_10008398(this,param_1);
    }
    *param_2 = *(undefined4 *)((int)this + 0xc);
    if (*(int *)((int)this + 0xc) != 0) {
      (**(code **)(**(int **)((int)this + 0xc) + 4))(*(int **)((int)this + 0xc));
      uVar1 = 0;
    }
  }
  return uVar1;
}



// Function: FUN_10008625 at 10008625

undefined4 __thiscall
FUN_10008625(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    uVar1 = FUN_10008398(this,param_4);
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



// Function: FUN_100086c6 at 100086c6

void __thiscall
FUN_100086c6(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    FUN_10008398(this,param_4);
  }
  if (*(int *)((int)this + 0xc) != 0) {
    (**(code **)(**(int **)((int)this + 0xc) + 0x2c))
              (*(int **)((int)this + 0xc),param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_10008709 at 10008709

undefined4 FUN_10008709(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_100085e5(&PTR_DAT_10028524,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_1000872d at 1000872d

void FUN_1000872d(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10008625(&PTR_DAT_10028524,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_1000874d at 1000874d

void FUN_1000874d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_100086c6(&PTR_DAT_10028524,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_1000875b at 1000875b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000875b(undefined4 *param_1)

{
  *param_1 = ATL::
             CComObject<class_CComCollection<class_COMCollectionTraits<class_ATL::ICollectionOnSTLImpl<struct_IBSTRCollection,class_std::vector<class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>,class_std::allocator<class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_>_>,unsigned_short*,class__CopyStringToBSTR,class_ATL::CComEnumOnSTL<struct_IEnumVARIANT,&struct__GUID_const_IID_IEnumVARIANT,struct_tagVARIANT,class__CopyStringToVARIANT,class_std::vector<class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>,class_std::allocator<class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_>_>,class_ATL::CComSingleThreadModel>_>,struct_IBSTRCollection,&struct__GUID_const_IID_IBSTRCollection,&struct__GUID_const_LIBID_COLLECTIONLib>,&struct__GUID_const_IID_IBSTRCollection,&struct__GUID_const_LIBID_COLLECTIONLib,&struct__GUID_const_GUID_NULL>_>
             ::vftable;
  param_1[1] = ATL::
               CComObject<class_CComCollection<class_COMCollectionTraits<class_ATL::ICollectionOnSTLImpl<struct_IBSTRCollection,class_std::vector<class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>,class_std::allocator<class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_>_>,unsigned_short*,class__CopyStringToBSTR,class_ATL::CComEnumOnSTL<struct_IEnumVARIANT,&struct__GUID_const_IID_IEnumVARIANT,struct_tagVARIANT,class__CopyStringToVARIANT,class_std::vector<class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>,class_std::allocator<class_std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_>_>,class_ATL::CComSingleThreadModel>_>,struct_IBSTRCollection,&struct__GUID_const_IID_IBSTRCollection,&struct__GUID_const_LIBID_COLLECTIONLib>,&struct__GUID_const_IID_IBSTRCollection,&struct__GUID_const_LIBID_COLLECTIONLib,&struct__GUID_const_GUID_NULL>_>
               ::vftable;
  param_1[6] = 0xc0000001;
  (**(code **)(*DAT_10029388 + 8))();
  FUN_10007d2f((int)param_1);
  return;
}



// Function: FUN_100087a0 at 100087a0

undefined4 * __thiscall FUN_100087a0(void *this,byte param_1)

{
  FUN_1000875b((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100087bf at 100087bf

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_100087bf(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  FUN_10007e4b(param_1 + 0x10);
  FUN_100076ec(param_1);
  return param_1;
}



// Function: FUN_1000880f at 1000880f

void __thiscall FUN_1000880f(void *this,int param_1)

{
  uint uVar1;
  char *pcVar2;
  int extraout_ECX;
  int iVar3;
  
                    /* WARNING: Load size is inaccurate */
  iVar3 = *this;
  uVar1 = (*(int *)((int)this + 4) - iVar3) / 0x1c;
  if (0x9249249U - param_1 < uVar1) {
    std::_Xlength_error("vector<T> too long");
    iVar3 = extraout_ECX;
  }
  uVar1 = uVar1 + param_1;
  if ((uint)((*(int *)((int)this + 8) - iVar3) / 0x1c) < uVar1) {
    pcVar2 = (char *)FUN_10001b36(this,uVar1);
    FUN_10007e77(this,pcVar2);
  }
  return;
}



// Function: FUN_10008864 at 10008864

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10008864(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0x1c);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10007f31(puVar1);
    }
    uVar2 = FUN_100088ca();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@100088b0 at 100088b0

undefined * Catch_100088b0(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x1c));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100088c2;
}



// Function: FUN_100088ca at 100088ca

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100088ca(void)

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



// Function: FUN_100088e4 at 100088e4

void __thiscall FUN_100088e4(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < puVar1) && (puVar2 = *this, puVar2 <= param_1)) {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_1000880f(this,1);
    }
                    /* WARNING: Load size is inaccurate */
    FUN_10003d90((int)this + 0xc,*(void **)((int)this + 4),
                 (undefined4 *)((((int)param_1 - (int)puVar2) / 0x1c) * 0x1c + *this));
  }
  else {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_1000880f(this,1);
    }
    FUN_100040a3((int)this + 0xc,*(void **)((int)this + 4),param_1);
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x1c;
  return;
}



// Function: FUN_10008951 at 10008951

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10008951(wchar_t *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  char cVar1;
  undefined4 local_74 [4];
  undefined4 *local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  int *local_48;
  int local_44;
  int *local_40;
  int local_3c;
  wchar_t *local_38;
  undefined4 local_34 [11];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x68;
  local_8 = 0x1000895d;
  local_38 = param_1;
  local_64 = param_6;
  FUN_10001c46(local_74);
  local_8 = 0;
  FUN_100045f1(local_74,0);
  local_8._0_1_ = 1;
  if (param_6 == (undefined4 *)0x0) {
    FUN_100045f1(local_74,-0x7fffbffd);
  }
  local_50 = 0;
  local_4c = 4;
  local_48 = (int *)0x0;
  (**(code **)(*(int *)param_1 + 0x2c))(local_38,param_2,param_3,param_4,param_5,&local_50);
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_10005665(&local_60,&local_38,(undefined4 *)0x0,(undefined4 *)0x0);
  local_44 = 0;
  (**(code **)(*local_48 + 0x20))(local_48,&local_44);
  for (local_3c = 1; local_3c <= local_44; local_3c = local_3c + 1) {
    local_8._0_1_ = 3;
    (**(code **)(*local_48 + 0x1c))(local_48,local_3c,&local_38);
    FUN_10003c48(local_34,local_38);
    local_8._0_1_ = 4;
    FUN_100088e4(&local_60,local_34);
    local_8._0_1_ = 3;
    FID_conflict__Tidy(local_34,'\x01',0);
    local_8 = CONCAT31(local_8._1_3_,2);
    Ordinal_6(0);
  }
  local_40 = (int *)0x0;
  local_8._0_1_ = 6;
  cVar1 = FUN_1000f5eb((_Container_base0 *)&local_60,&local_40);
  FUN_100045f1(local_74,(-(uint)(cVar1 != '\0') & 0x7fffbffb) + 0x80004005);
  *local_64 = local_40;
  Ordinal_6(local_50);
  (**(code **)(*local_48 + 8))(local_48);
  local_8._0_1_ = 2;
  if (local_40 != (int *)0x0) {
    (**(code **)(*local_40 + 8))(local_40);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10004315((_Container_base0 *)&local_60);
  local_8 = 0xffffffff;
  FUN_10014f93();
  return;
}



// Function: Catch@10008ac5 at 10008ac5

undefined4 Catch_10008ac5(void)

{
  int unaff_EBP;
  
  FUN_100045f1((void *)(unaff_EBP + -0x70),-0x7fffbffb);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10008ab6;
}



// Function: FUN_10008adc at 10008adc

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10008adc(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 local_38 [3];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x10008ae8;
  FUN_10001c46(local_38);
  local_8 = 0;
  FUN_100045f1(local_38,0);
  puVar1 = param_2;
  local_8._0_1_ = 1;
  if (param_2 == (undefined4 *)0x0) {
    FUN_100045f1(local_38,-0x7fffbffd);
  }
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_10005665(&local_28,&param_2,(undefined4 *)0x0,(undefined4 *)0x0);
  param_2 = (undefined4 *)**(undefined4 **)(param_1 + 0x14);
  while (param_2 != *(undefined4 **)(param_1 + 0x14)) {
    FUN_100088e4(&local_28,param_2 + 4);
    FUN_10001b65((int *)&param_2);
  }
  local_18[0] = (int *)0x0;
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 4;
  cVar2 = FUN_1000f5eb((_Container_base0 *)&local_28,local_18);
  FUN_100045f1(local_38,(-(uint)(cVar2 != '\0') & 0x7fffbffb) + 0x80004005);
  *puVar1 = local_18[0];
  local_8._0_1_ = 2;
  if (local_18[0] != (int *)0x0) {
    (**(code **)(*local_18[0] + 8))(local_18[0]);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10004315((_Container_base0 *)&local_28);
  return local_2c;
}



// Function: Catch@10008bcd at 10008bcd

undefined4 Catch_10008bcd(void)

{
  int unaff_EBP;
  
  FUN_100045f1((void *)(unaff_EBP + -0x34),-0x7fffbffb);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10008bbe;
}



// Function: FUN_10008be4 at 10008be4

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10008be4(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 local_7c [4];
  undefined4 *local_6c;
  wchar_t *local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_54;
  undefined4 local_50;
  int *local_4c;
  int local_48;
  undefined4 local_44;
  int local_40;
  int *local_3c;
  int local_38;
  undefined1 local_34 [16];
  int local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x6c;
  local_8 = 0x10008bf0;
  local_6c = param_6;
  FUN_10001c46(local_7c);
  local_8 = 0;
  FUN_100045f1(local_7c,0);
  local_8._0_1_ = 1;
  if (param_6 == (undefined4 *)0x0) {
    FUN_100045f1(local_7c,-0x7fffbffd);
  }
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_10005665(&local_64,&local_44,(undefined4 *)0x0,(undefined4 *)0x0);
  local_54 = 0;
  local_50 = 4;
  local_4c = (int *)0x0;
  (**(code **)(*param_1 + 0x2c))(param_1,param_2,param_3,param_4,param_5,&local_54);
  local_48 = 0;
  (**(code **)(*local_4c + 0x20))(local_4c,&local_48);
  for (local_38 = 1; local_38 <= local_48; local_38 = local_38 + 1) {
    local_44 = 0;
    local_8 = CONCAT31(local_8._1_3_,3);
    (**(code **)(*local_4c + 0x1c))(local_4c,local_38,&local_68);
    local_40 = *(int *)param_1[5];
    while (iVar1 = local_40, local_40 != param_1[5]) {
      iVar3 = FUN_1000217f((void *)(local_40 + 0x10),local_68);
      if (iVar3 == 0) {
        basic_string<>(local_34,(undefined4 *)(iVar1 + 0x2c));
        local_8._0_1_ = 4;
        if (local_24 != 0) {
          FUN_100088e4(&local_64,(undefined4 *)(iVar1 + 0x2c));
        }
        local_8 = CONCAT31(local_8._1_3_,3);
        FID_conflict__Tidy(local_34,'\x01',0);
      }
      FUN_10001b65(&local_40);
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    Ordinal_6(local_44);
  }
  local_3c = (int *)0x0;
  local_8._0_1_ = 6;
  cVar2 = FUN_1000f5eb((_Container_base0 *)&local_64,&local_3c);
  FUN_100045f1(local_7c,(-(uint)(cVar2 != '\0') & 0x7fffbffb) + 0x80004005);
  *local_6c = local_3c;
  Ordinal_6(local_54);
  (**(code **)(*local_4c + 8))(local_4c);
  local_8._0_1_ = 2;
  if (local_3c != (int *)0x0) {
    (**(code **)(*local_3c + 8))(local_3c);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10004315((_Container_base0 *)&local_64);
  local_8 = 0xffffffff;
  FUN_10014f93();
  return;
}



// Function: Catch@10008d92 at 10008d92

undefined4 Catch_10008d92(void)

{
  int unaff_EBP;
  
  FUN_100045f1((void *)(unaff_EBP + -0x78),-0x7fffbffb);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10008d83;
}



// Function: FUN_10008da9 at 10008da9

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10008da9(int param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 local_5c [4];
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_3c;
  int *local_38;
  undefined4 local_34 [4];
  int local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x4c;
  local_8 = 0x10008db5;
  FUN_10001c46(local_5c);
  local_8 = 0;
  FUN_100045f1(local_5c,0);
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_8._0_1_ = 1;
  FUN_10005665(&local_4c,&local_38,(undefined4 *)0x0,(undefined4 *)0x0);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_2 == (undefined4 *)0x0) {
    FUN_100045f1(local_5c,-0x7fffbffd);
  }
  local_3c = **(int **)(param_1 + 0x14);
  while (local_3c != *(int *)(param_1 + 0x14)) {
    basic_string<>(local_34,(undefined4 *)(local_3c + 0x2c));
    local_8._0_1_ = 3;
    if (local_24 != 0) {
      FUN_100088e4(&local_4c,local_34);
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FID_conflict__Tidy(local_34,'\x01',0);
    FUN_10001b65(&local_3c);
  }
  local_38 = (int *)0x0;
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 5;
  cVar1 = FUN_1000f5eb((_Container_base0 *)&local_4c,&local_38);
  FUN_100045f1(local_5c,(-(uint)(cVar1 != '\0') & 0x7fffbffb) + 0x80004005);
  *param_2 = local_38;
  local_8 = CONCAT31(local_8._1_3_,2);
  if (local_38 != (int *)0x0) {
    (**(code **)(*local_38 + 8))(local_38);
  }
  local_8 = 1;
  FUN_10008ec5();
  return;
}



// Function: Catch@10008ea9 at 10008ea9

undefined * Catch_10008ea9(void)

{
  int unaff_EBP;
  
  FUN_100045f1((void *)(unaff_EBP + -0x58),-0x7fffbffb);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10008ec3;
}



// Function: FUN_10008ec5 at 10008ec5

void FUN_10008ec5(void)

{
  undefined1 unaff_BL;
  int unaff_EBP;
  
  *(undefined1 *)(unaff_EBP + -4) = unaff_BL;
  FUN_10004315((_Container_base0 *)(unaff_EBP + -0x48));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10014f93();
  return;
}



// Function: FUN_10008edf at 10008edf

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10008edf(int param_1,undefined4 *param_2)

{
  int iVar1;
  char cVar2;
  undefined4 local_60 [4];
  undefined4 *local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_3c;
  int *local_38;
  undefined1 local_34 [16];
  int local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x50;
  local_8 = 0x10008eeb;
  local_50 = param_2;
  FUN_10001c46(local_60);
  local_8 = 0;
  FUN_100045f1(local_60,0);
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_8._0_1_ = 1;
  FUN_10005665(&local_4c,&local_38,(undefined4 *)0x0,(undefined4 *)0x0);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_2 == (undefined4 *)0x0) {
    FUN_100045f1(local_60,-0x7fffbffd);
  }
  local_3c = **(int **)(param_1 + 0x14);
  while (iVar1 = local_3c, local_3c != *(int *)(param_1 + 0x14)) {
    basic_string<>(local_34,(undefined4 *)(local_3c + 0x2c));
    local_8._0_1_ = 3;
    if (local_24 != 0) {
      FUN_100088e4(&local_4c,(undefined4 *)(iVar1 + 0x10));
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FID_conflict__Tidy(local_34,'\x01',0);
    FUN_10001b65(&local_3c);
  }
  local_38 = (int *)0x0;
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 5;
  cVar2 = FUN_1000f5eb((_Container_base0 *)&local_4c,&local_38);
  FUN_100045f1(local_60,(-(uint)(cVar2 != '\0') & 0x7fffbffb) + 0x80004005);
  *local_50 = local_38;
  local_8 = CONCAT31(local_8._1_3_,2);
  if (local_38 != (int *)0x0) {
    (**(code **)(*local_38 + 8))(local_38);
  }
  local_8 = 1;
  FUN_10009001();
  return;
}



// Function: Catch@10008fe5 at 10008fe5

undefined * Catch_10008fe5(void)

{
  int unaff_EBP;
  
  FUN_100045f1((void *)(unaff_EBP + -0x5c),-0x7fffbffb);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10008fff;
}



// Function: FUN_10009001 at 10009001

void FUN_10009001(void)

{
  undefined1 unaff_BL;
  int unaff_EBP;
  
  *(undefined1 *)(unaff_EBP + -4) = unaff_BL;
  FUN_10004315((_Container_base0 *)(unaff_EBP + -0x48));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10014f93();
  return;
}



// Function: FUN_1000901b at 1000901b

bool __cdecl FUN_1000901b(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,0x10);
  return (bool)('\x01' - (iVar1 != 0));
}



// Function: AtlCoTaskMemCAlloc at 10009035

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



// Function: FUN_10009062 at 10009062

LPVOID __cdecl FUN_10009062(LPVOID param_1,ulong param_2,ulong param_3)

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



// Function: FUN_10009092 at 10009092

bool __cdecl FUN_10009092(void *param_1,int param_2,LPCWSTR param_3)

{
  int iVar1;
  errno_t eVar2;
  
  iVar1 = lstrlenW(param_3);
  eVar2 = memcpy_s(param_1,param_2 * 2,param_3,iVar1 * 2 + 2);
  return (bool)('\x01' - (eVar2 != 0));
}



// Function: FUN_100090bf at 100090bf

void __cdecl FUN_100090bf(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscpy_s(param_1,param_2,param_3);
  AfxCrtErrorCheck(eVar1);
  return;
}



// Function: Init at 100090dc

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



// Function: FUN_10009105 at 10009105

void __fastcall FUN_10009105(LPCRITICAL_SECTION param_1)

{
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  return;
}



// Function: FUN_10009117 at 10009117

undefined ** FUN_10009117(void)

{
  return &PTR_LAB_1001ebd0;
}



// Function: FUN_1000911d at 1000911d

DWORD FUN_1000911d(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}



// Function: FUN_10009132 at 10009132

uint __cdecl FUN_10009132(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FUN_10009148 at 10009148

void __fastcall FUN_10009148(int param_1)

{
  long lVar1;
  
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (-1 < lVar1) {
    *(undefined1 *)(param_1 + 0x1c) = 1;
  }
  return;
}



// Function: FUN_1000915d at 1000915d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __fastcall FUN_1000915d(void *param_1)

{
  memset(param_1,0,0x18);
  *(undefined1 *)((int)param_1 + 0x18) = 0;
  return param_1;
}



// Function: FUN_1000918b at 1000918b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000918b(undefined4 *param_1)

{
  FUN_1000f4df((int)param_1);
  *param_1 = ATL::CComObject<class_CUserManagerImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CUserManagerImpl>::vftable;
  (**(code **)(*DAT_10029388 + 4))();
  return param_1;
}



// Function: FUN_100091cb at 100091cb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100091cb(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CUserManagerImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CUserManagerImpl>::vftable;
  param_1[2] = 0xc0000001;
  FUN_1000d87f((int)param_1);
  (**(code **)(*DAT_10029388 + 8))();
  FUN_1000f3c4((int)param_1);
  return;
}



// Function: FUN_10009215 at 10009215

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10009215(undefined4 *param_1)

{
  FUN_1001187a((int)param_1);
  *param_1 = ATL::CComObject<class_CUsersImpl>::vftable;
  (**(code **)(*DAT_10029388 + 4))();
  return param_1;
}



// Function: FUN_1000924e at 1000924e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000924e(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CUsersImpl>::vftable;
  param_1[1] = 0xc0000001;
  FUN_100117ec((int)param_1);
  (**(code **)(*DAT_10029388 + 8))();
  FUN_1001171d((int)param_1);
  return;
}



// Function: FUN_10009291 at 10009291

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10009291(undefined4 *param_1)

{
  FUN_100087bf((int)param_1);
  *param_1 = ATL::CComObject<class_CGroupsImpl>::vftable;
  (**(code **)(*DAT_10029388 + 4))();
  return param_1;
}



// Function: FUN_100092ca at 100092ca

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100092ca(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CGroupsImpl>::vftable;
  param_1[1] = 0xc0000001;
  FUN_10001fb8((int)param_1);
  (**(code **)(*DAT_10029388 + 8))();
  FUN_10007dc9((int)param_1);
  return;
}



// Function: FUN_1000930d at 1000930d

undefined4 * __thiscall FUN_1000930d(void *this,byte param_1)

{
  FUN_100091cb((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000932c at 1000932c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000932c(int param_1)

{
  FUN_1000f3c4(param_1);
  return;
}



// Function: FUN_1000934a at 1000934a

undefined4 * __thiscall FUN_1000934a(void *this,byte param_1)

{
  FUN_1000924e((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10009369 at 10009369

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10009369(int param_1)

{
  FUN_1001171d(param_1);
  return;
}



// Function: FUN_10009387 at 10009387

undefined4 * __thiscall FUN_10009387(void *this,byte param_1)

{
  FUN_100092ca((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100093a6 at 100093a6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100093a6(int param_1)

{
  FUN_10007dc9(param_1);
  return;
}



// Function: FUN_100093c4 at 100093c4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100093c4(void *this,undefined4 param_1)

{
  FUN_1000f4df((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CUserManagerImpl>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CUserManagerImpl>::vftable;
  *(undefined4 *)((int)this + 8) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_100093ff at 100093ff

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100093ff(void *this,undefined4 param_1)

{
  FUN_1001187a((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CUsersImpl>::vftable;
  *(undefined4 *)((int)this + 4) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_10009433 at 10009433

undefined4 __fastcall FUN_10009433(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_10009437 at 10009437

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10009437(void *this,undefined4 param_1)

{
  FUN_100087bf((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CGroupsImpl>::vftable;
  *(undefined4 *)((int)this + 4) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_1000946b at 1000946b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000946b(void *this,byte param_1)

{
  FUN_1000f3c4((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_1000949c at 1000949c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000949c(void *this,byte param_1)

{
  FUN_1001171d((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_100094cd at 100094cd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_100094cd(void *this,byte param_1)

{
  FUN_10007dc9((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FID_conflict:RegCreateKeyExW at 100094fe

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
                    /* WARNING: Could not recover jumptable at 0x10009553. Too many branches */
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



// Function: FID_conflict:RegDeleteKeyA at 10009561

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
                    /* WARNING: Could not recover jumptable at 0x100095a4. Too many branches */
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



// Function: FUN_100095b3 at 100095b3

void FUN_100095b3(void *param_1)

{
  operator_delete(param_1);
  return;
}



// Function: FUN_100095c3 at 100095c3

void FUN_100095c3(void)

{
  return;
}



// Function: FUN_100095c4 at 100095c4

void FUN_100095c4(void)

{
  return;
}



// Function: FUN_100095c7 at 100095c7

undefined4 __fastcall FUN_100095c7(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_100095cb at 100095cb

void __cdecl FUN_100095cb(short *param_1,int param_2,short *param_3)

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



// Function: FUN_10009619 at 10009619

int __fastcall FUN_10009619(int param_1)

{
  memset((void *)(param_1 + 0xc),0,0x18);
  return param_1;
}



// Function: DeleteSubKey at 10009630

/* Library Function - Multiple Matches With Same Base Name
    public: long __thiscall ATL::CRegKey::DeleteSubKey(char const *)
    public: long __thiscall ATL::CRegKey::DeleteSubKey(wchar_t const *)
   
   Library: Visual Studio 2010 Release */

void __thiscall DeleteSubKey(void *this,LPCWSTR param_1)

{
  HMODULE hModule;
  
  if (*(int *)((int)this + 8) == 0) {
    if (DAT_10029ed8 == '\0') {
      hModule = GetModuleHandleW(L"Advapi32.dll");
      if (hModule != (HMODULE)0x0) {
        DAT_10029ed4 = GetProcAddress(hModule,"RegDeleteKeyExW");
      }
      DAT_10029ed8 = '\x01';
    }
    if (DAT_10029ed4 == (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      RegDeleteKeyW(*this,param_1);
    }
    else {
                    /* WARNING: Load size is inaccurate */
      (*DAT_10029ed4)(*this,param_1,*(undefined4 *)((int)this + 4),0);
    }
  }
  else {
                    /* WARNING: Load size is inaccurate */
    FID_conflict_RegDeleteKeyA(*this,(LPCSTR)param_1);
  }
  return;
}



// Function: Create at 100096a0

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



// Function: SetStringValue at 10009708

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



// Function: FUN_1000973f at 1000973f

LSTATUS __thiscall FUN_1000973f(void *this,LPCWSTR param_1,LPCWSTR param_2)

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



// Function: FUN_10009782 at 10009782

undefined4 __fastcall FUN_10009782(undefined4 *param_1)

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



// Function: FUN_100097a2 at 100097a2

undefined4 * __thiscall FUN_100097a2(void *this,ulong param_1)

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



// Function: FUN_100097d8 at 100097d8

void __fastcall FUN_100097d8(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_100097e2 at 100097e2

undefined4 __thiscall FUN_100097e2(void *this,void *param_1,int param_2)

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
      pvVar4 = FUN_10009062(*(LPVOID *)((int)this + 8),uVar3,2);
      if (pvVar4 == (LPVOID)0x0) {
        return 0;
      }
      *(LPVOID *)((int)this + 8) = pvVar4;
    }
                    /* WARNING: Load size is inaccurate */
    iVar1 = *this;
    if (((-1 < iVar1) && (iVar2 = *(int *)((int)this + 4), iVar1 < iVar2)) &&
       (iVar2 - iVar1 <= iVar2)) {
      FUN_100010f3((void *)(*(int *)((int)this + 8) + iVar1 * 2),(iVar2 - iVar1) * 2,param_1,
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



// Function: FUN_10009870 at 10009870

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10009870(undefined4 param_1,undefined2 *param_2)

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
  local_8 = 0x1000987c;
  uVar5 = 0;
  puVar3 = auStack_20;
  if ((DAT_10029efc & 1) == 0) {
    DAT_10029efc = DAT_10029efc | 1;
    DAT_10029ee0 = 8;
    _DAT_10029ee8 = 0x4008;
    _DAT_10029ef0 = 0x13;
    DAT_10029edc = &DAT_1001d8ec;
    DAT_10029ee4 = &DAT_1001d8e8;
    _DAT_10029eec = &DAT_1001d8e4;
    _DAT_10029ef4 = &DAT_1001d8e0;
    _DAT_10029ef8 = 0x11;
    local_8 = 0xffffffff;
  }
  do {
    *(undefined **)(puVar3 + -4) = (&DAT_10029edc)[uVar5 * 2];
    *(undefined4 *)(puVar3 + -8) = param_1;
    puVar4 = puVar3 + -0xc;
    *(undefined4 *)(puVar3 + -0xc) = 0x100098f3;
    iVar1 = lstrcmpiW(*(LPCWSTR *)(puVar3 + -8),*(LPCWSTR *)(puVar3 + -4));
    if (iVar1 == 0) {
      *param_2 = (&DAT_10029ee0)[uVar5 * 4];
      uVar2 = 1;
      goto LAB_100098ff;
    }
    uVar5 = uVar5 + 1;
    puVar3 = puVar4;
  } while (uVar5 < 4);
  uVar2 = 0;
LAB_100098ff:
  *(undefined4 *)(puVar4 + -4) = 0x10009904;
  return uVar2;
}



// Function: FUN_10009918 at 10009918

int __cdecl FUN_10009918(ushort param_1)

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



// Function: FUN_1000994e at 1000994e

undefined4 __cdecl FUN_1000994e(LPCWSTR param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_HKCR_1001f010)[uVar2 * 2]);
    if (iVar1 == 0) {
      return (&DAT_1001f014)[uVar2 * 2];
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xe);
  return 0;
}



// Function: FUN_1000997c at 1000997c

LPCWSTR __cdecl FUN_1000997c(LPCWSTR param_1,WCHAR param_2)

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



// Function: FUN_100099a9 at 100099a9

undefined4 FUN_100099a9(ushort param_1)

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



// Function: FUN_100099cf at 100099cf

void __fastcall FUN_100099cf(undefined4 *param_1)

{
  LPWSTR pWVar1;
  int iVar2;
  
  while( true ) {
    iVar2 = FUN_100099a9(*(ushort *)*param_1);
    if (iVar2 == 0) break;
    pWVar1 = CharNextW((LPCWSTR)*param_1);
    *param_1 = pWVar1;
  }
  return;
}



// Function: FUN_100099f1 at 100099f1

undefined4 __thiscall FUN_100099f1(void *this,undefined2 *param_1)

{
  WCHAR WVar1;
  LPCWSTR pWVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  
  FUN_100099cf((undefined4 *)this);
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
      while ((*pWVar4 != L'\0' && (iVar5 = FUN_10009782((undefined4 *)this), iVar5 == 0))) {
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
        iVar5 = FUN_100099a9(*pWVar2);
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



// Function: FUN_10009b07 at 10009b07

undefined4 FUN_10009b07(LPCWSTR param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_u_AppID_1001d940;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar2);
    if (iVar1 == 0) {
      return 0;
    }
    ppuVar2 = ppuVar2 + 1;
  } while ((int)ppuVar2 < 0x1001d970);
  return 1;
}



// Function: FUN_10009b36 at 10009b36

bool FUN_10009b36(HKEY param_1)

{
  LSTATUS LVar1;
  DWORD local_8;
  
  local_8 = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_8,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  return LVar1 == 0 && local_8 != 0;
}



// Function: FUN_10009b6b at 10009b6b

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10009b6b(void *this,short *param_1)

{
  int iVar1;
  undefined2 local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_10028e44 ^ (uint)&stack0xfffffffc;
  if ((*param_1 == 0x3d) && (iVar1 = FUN_100099f1(this,param_1), -1 < iVar1)) {
    FUN_100099cf((undefined4 *)this);
    iVar1 = FUN_100099f1(this,local_2008);
    if (-1 < iVar1) {
      FUN_100099f1(this,param_1);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10009bd0 at 10009bd0

undefined4 FUN_10009bd0(undefined1 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_1 = DAT_10029384;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10009bef at 10009bef

undefined4 __thiscall FUN_10009bef(void *this,int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    DAT_1002938c = *param_3;
    DAT_10029390 = param_3[1];
    DAT_10029394 = param_3[2];
    DAT_10029398 = param_3[3];
  }
  piVar2 = DAT_1002b014;
  if ((param_1 != (int *)0xffffffff) &&
     (*(int **)((int)this + 0x2c) = param_1, piVar2 = DAT_1002b014, param_1 != (int *)0x0)) {
    iVar1 = *param_1;
    while (DAT_1002b014 = piVar2, iVar1 != 0) {
      (*(code *)param_1[8])(1);
      param_1 = param_1 + 9;
      piVar2 = DAT_1002b014;
      iVar1 = *param_1;
    }
  }
  for (; piVar2 < DAT_1002b018; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(1);
    }
  }
  return 0;
}



// Function: FUN_10009c4d at 10009c4d

void FUN_10009c4d(int param_1)

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



// Function: FUN_10009c90 at 10009c90

uint __fastcall FUN_10009c90(int param_1)

{
  return *(uint *)(param_1 + 0xac) & 1;
}



// Function: FUN_10009c9a at 10009c9a

uint __fastcall FUN_10009c9a(int param_1)

{
  return *(uint *)(param_1 + 0xac) & 2;
}



// Function: FUN_10009ca4 at 10009ca4

uint __fastcall FUN_10009ca4(int param_1)

{
  return *(uint *)(param_1 + 0xac) & 4;
}



// Function: FUN_10009cae at 10009cae

uint __fastcall FUN_10009cae(int param_1)

{
  return *(uint *)(param_1 + 0xac) & 8;
}



// Function: FUN_10009cb8 at 10009cb8

uint __fastcall FUN_10009cb8(int param_1)

{
  return *(uint *)(param_1 + 0xac) & 0x10;
}



// Function: FUN_10009cc2 at 10009cc2

uint __fastcall FUN_10009cc2(int param_1)

{
  return *(uint *)(param_1 + 0xac) & 0x20;
}



// Function: FUN_10009ccc at 10009ccc

undefined4 FUN_10009ccc(void)

{
  return 0;
}



// Function: FUN_10009ccf at 10009ccf

undefined4 FUN_10009ccf(void)

{
  return 5000;
}



// Function: FUN_10009cd5 at 10009cd5

void __fastcall FUN_10009cd5(undefined4 *param_1)

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



// Function: FUN_10009d02 at 10009d02

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_10009d02(LPCRITICAL_SECTION param_1)

{
  undefined1 *puVar1;
  undefined1 *extraout_EAX;
  
  puVar1 = &LAB_10017437;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
    puVar1 = extraout_EAX;
  }
  return puVar1;
}



// Function: FUN_10009d2c at 10009d2c

int __thiscall FUN_10009d2c(void *this,undefined4 *param_1)

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



// Function: FUN_10009d63 at 10009d63

void __fastcall FUN_10009d63(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_10009d6d at 10009d6d

void __thiscall FUN_10009d6d(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_100010d9(-0x7ff8fff2);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: AtlMultiplyThrow<unsigned_int> at 10009d92

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
    FUN_100010d9(lVar1);
  }
  return local_8;
}



// Function: FUN_10009dbc at 10009dbc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

CWinApp * __thiscall FUN_10009dbc(void *this,byte param_1)

{
  CWinApp::~CWinApp((CWinApp *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (CWinApp *)this;
}



// Function: FUN_10009ded at 10009ded

void __fastcall FUN_10009ded(CWinApp *param_1)

{
  FUN_10009bef(&DAT_10029f00,(int *)&PTR_DAT_10028540,*(undefined4 *)(param_1 + 0x44),
               (undefined4 *)&DAT_1001eb40);
  CWinApp::InitInstance(param_1);
  return;
}



// Function: DllCanUnloadNow at 10009e0f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

HRESULT DllCanUnloadNow(void)

{
  AFX_MODULE_STATE *pAVar1;
  long lVar2;
  HRESULT HVar3;
  AFX_MAINTAIN_STATE2 local_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
                    /* 0x9e0f  1  DllCanUnloadNow */
  uStack_4 = 0x10;
  local_8 = 0x10009e1b;
  pAVar1 = (AFX_MODULE_STATE *)FUN_10014bb5();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_20,pAVar1);
  HVar3 = 0;
  local_8 = 0;
  lVar2 = AfxDllCanUnloadNow();
  if ((lVar2 != 0) || (DAT_10029f08 != 0)) {
    HVar3 = 1;
  }
  local_8 = 0xffffffff;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_20);
  return HVar3;
}



// Function: FUN_10009e56 at 10009e56

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10009e56(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x58);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_1000918b(puVar1);
    }
    iVar2 = FUN_10009ec2();
    return iVar2;
  }
  return -0x7fffbffd;
}



// Function: Catch@10009eaa at 10009eaa

undefined * Catch_10009eaa(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x1c));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10009ebc;
}



// Function: FUN_10009ec2 at 10009ec2

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10009ec2(void)

{
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_ESI[2] = unaff_ESI[2] + 1;
    unaff_EDI = FUN_1000d4b9((int)unaff_ESI);
    if (-1 < unaff_EDI) {
      unaff_EDI = 0;
    }
    unaff_ESI[2] = unaff_ESI[2] + -1;
    if ((unaff_EDI == 0) && (unaff_EDI = (**(code **)*unaff_ESI)(), unaff_EDI == 0)) {
      return 0;
    }
    (**(code **)(*unaff_ESI + 0x44))(1);
  }
  return unaff_EDI;
}



// Function: FUN_10009f03 at 10009f03

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10009f03(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10009215(puVar1);
    }
    iVar2 = FUN_10009f6f();
    return iVar2;
  }
  return -0x7fffbffd;
}



// Function: Catch@10009f57 at 10009f57

undefined * Catch_10009f57(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x1c));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10009f69;
}



// Function: FUN_10009f6f at 10009f6f

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10009f6f(void)

{
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_ESI[1] = unaff_ESI[1] + 1;
    unaff_EDI = FUN_10011834((int)unaff_ESI);
    if (-1 < unaff_EDI) {
      unaff_EDI = 0;
    }
    unaff_ESI[1] = unaff_ESI[1] + -1;
    if ((unaff_EDI == 0) && (unaff_EDI = (**(code **)*unaff_ESI)(), unaff_EDI == 0)) {
      return 0;
    }
    (**(code **)(*unaff_ESI + 0x3c))(1);
  }
  return unaff_EDI;
}



// Function: FUN_10009fb0 at 10009fb0

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10009fb0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x20);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10009291(puVar1);
    }
    iVar2 = FUN_1000a01c();
    return iVar2;
  }
  return -0x7fffbffd;
}



// Function: Catch@1000a004 at 1000a004

undefined * Catch_1000a004(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x1c));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000a016;
}



// Function: FUN_1000a01c at 1000a01c

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_1000a01c(void)

{
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_ESI[1] = unaff_ESI[1] + 1;
    unaff_EDI = FUN_10011834((int)unaff_ESI);
    if (-1 < unaff_EDI) {
      unaff_EDI = 0;
    }
    unaff_ESI[1] = unaff_ESI[1] + -1;
    if ((unaff_EDI == 0) && (unaff_EDI = (**(code **)*unaff_ESI)(), unaff_EDI == 0)) {
      return 0;
    }
    (**(code **)(*unaff_ESI + 0x4c))(1);
  }
  return unaff_EDI;
}



// Function: FUN_1000a05d at 1000a05d

undefined4 FUN_1000a05d(int param_1)

{
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  return *(undefined4 *)(param_1 + 8);
}



// Function: Release at 1000a06d

/* Library Function - Single Match
    public: virtual unsigned long __stdcall CMFCComObject<class
   ATL::CAccessibleProxy>::Release(void)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

ulong CMFCComObject<class_ATL::CAccessibleProxy>::Release(void)

{
  int *piVar1;
  ulong uVar2;
  int *in_stack_00000004;
  
  piVar1 = in_stack_00000004 + 2;
  *piVar1 = *piVar1 + -1;
  uVar2 = in_stack_00000004[2];
  if ((*piVar1 == 0) && (in_stack_00000004 != (int *)0x0)) {
    (**(code **)(*in_stack_00000004 + 0x44))(1);
  }
  return uVar2;
}



// Function: QueryInterface at 1000a08e

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1001ed74,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_1000a0a8 at 1000a0a8

void FUN_1000a0a8(int param_1)

{
  (**(code **)(**(int **)(param_1 + 8) + 4))(*(int **)(param_1 + 8));
  return;
}



// Function: FUN_1000a0bb at 1000a0bb

void FUN_1000a0bb(int param_1)

{
  (**(code **)(**(int **)(param_1 + 8) + 8))(*(int **)(param_1 + 8));
  return;
}



// Function: FUN_1000a0ce at 1000a0ce

void FUN_1000a0ce(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 8))(*(undefined4 **)(param_1 + 8),param_2,param_3);
  return;
}



// Function: FUN_1000a0e6 at 1000a0e6

undefined4 FUN_1000a0e6(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return *(undefined4 *)(param_1 + 4);
}



// Function: Release at 1000a0f6

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
    (**(code **)(*in_stack_00000004 + 0x3c))(1);
  }
  return uVar2;
}



// Function: QueryInterface at 1000a117

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1001ee00,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_1000a131 at 1000a131

void FUN_1000a131(int param_1)

{
  (**(code **)(**(int **)(param_1 + 4) + 4))(*(int **)(param_1 + 4));
  return;
}



// Function: FUN_1000a144 at 1000a144

void FUN_1000a144(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 4))(*(undefined4 **)(param_1 + 4),param_2,param_3);
  return;
}



// Function: Release at 1000a15c

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
    (**(code **)(*in_stack_00000004 + 0x4c))(1);
  }
  return uVar2;
}



// Function: QueryInterface at 1000a17d

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1001ee90,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_1000a197 at 1000a197

void FUN_1000a197(int param_1)

{
  (**(code **)(**(int **)(param_1 + 4) + 8))(*(int **)(param_1 + 4));
  return;
}



// Function: FUN_1000a1aa at 1000a1aa

void FUN_1000a1aa(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_1000a1b4 at 1000a1b4

void FUN_1000a1b4(int param_1)

{
  FUN_1000a0bb(param_1 + -4);
  return;
}



// Function: FUN_1000a1be at 1000a1be

void FUN_1000a1be(int param_1)

{
  FUN_1000a0a8(param_1 + -4);
  return;
}



// Function: FUN_1000a1c8 at 1000a1c8

void FUN_1000a1c8(void)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::Release();
  return;
}



// Function: FUN_1000a1d2 at 1000a1d2

void FUN_1000a1d2(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000a0ce(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_1000a1dc at 1000a1dc

void FUN_1000a1dc(int param_1)

{
  FUN_1000a05d(param_1 + -4);
  return;
}



// Function: FUN_1000a1e6 at 1000a1e6

int __fastcall FUN_1000a1e6(int param_1)

{
  long lVar1;
  
  FUN_10009619(param_1 + 4);
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_10029388 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 0x10));
  if (lVar1 < 0) {
    DAT_1002939c = 1;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x24;
  }
  return param_1;
}



// Function: FUN_1000a227 at 1000a227

void __fastcall FUN_1000a227(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10009c4d((int)piVar1);
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



// Function: FUN_1000a260 at 1000a260

void __fastcall FUN_1000a260(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10009c4d((int)piVar1);
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



// Function: FUN_1000a265 at 1000a265

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000a265(int param_1)

{
  FUN_1000a227(param_1);
  return;
}



// Function: FUN_1000a283 at 1000a283

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000a283(void *this,LPCWSTR param_1)

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
      iVar1 = FUN_1000a283(&local_224,local_214);
    } while (iVar1 == 0);
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_224);
  }
  else {
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_224);
  }
  FUN_10014f84();
  return;
}



// Function: FUN_1000a368 at 1000a368

undefined4 __fastcall FUN_1000a368(int *param_1)

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
LAB_1000a3ad:
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pcVar1 = (code *)swi(3);
        uVar3 = (*pcVar1)();
        return uVar3;
      }
      operator_delete__(*(void **)(*param_1 + iVar4 * 4));
      if (param_1[2] <= iVar4) goto LAB_1000a3ad;
      operator_delete__(*(void **)(param_1[1] + iVar4 * 4));
      iVar2 = param_1[2];
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  FUN_10009cd5(param_1);
  return 0;
}



// Function: FUN_1000a3bf at 1000a3bf

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_1000a3bf(void *this,LPCWSTR param_1)

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
    uVar1 = FUN_100097e2(this,param_1,iVar2);
    local_8 = 0xffffffff;
    FUN_100014b1(local_14);
  }
  return uVar1;
}



// Function: FUN_1000a406 at 1000a406

void FUN_1000a406(int param_1)

{
  FUN_1000a368((int *)(param_1 + 4));
  return;
}



// Function: FUN_1000a418 at 1000a418

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000a418(HMODULE param_1,LPCWSTR param_2,undefined4 *param_3,undefined4 *param_4)

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
  local_8 = 0x1000a427;
  local_244 = param_2;
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined4 *)0x0)) goto LAB_1000a5f2;
  *param_3 = 0;
  *param_4 = 0;
  local_248 = 0;
  local_8 = 0;
  DVar2 = GetModuleFileNameW(param_1,local_23c,0x104);
  if (DVar2 == 0) {
    FUN_1000911d();
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
      if (((uVar1 < DVar2) || (uVar1 < uVar3)) || (0x10d < uVar1)) goto LAB_1000a485;
      FUN_100090bf(local_23c + DVar2,0x10e - DVar2,local_244);
    }
    iVar4 = Ordinal_161(local_23c,param_4);
    if (iVar4 < 0) {
      builtin_wcsncpy(local_20,L".tlb",5);
      iVar4 = (int)local_240 - (int)local_23c >> 1;
      if (iVar4 + 5U < 0x105) {
        eVar5 = wcscpy_s(local_240,0x10e - iVar4,local_20);
        AfxCrtErrorCheck(eVar5);
        iVar4 = Ordinal_161(local_23c,param_4);
        if (-1 < iVar4) goto LAB_1000a5c2;
      }
    }
    else {
LAB_1000a5c2:
      uVar6 = Ordinal_2(local_23c);
      *param_3 = uVar6;
    }
  }
LAB_1000a485:
  local_8 = 0xffffffff;
  FUN_100014b1(&local_248);
LAB_1000a5f2:
  FUN_10014f84();
  return;
}



// Function: FUN_1000a5fa at 1000a5fa

void __fastcall FUN_1000a5fa(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  piVar2 = DAT_1002b014;
  if (piVar1 != (int *)0x0) {
    for (; piVar2 = DAT_1002b014, *piVar1 != 0; piVar1 = piVar1 + 9) {
      piVar2 = (int *)piVar1[4];
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      piVar1[4] = 0;
      (*(code *)piVar1[8])(0);
    }
  }
  for (; piVar2 < DAT_1002b018; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(0);
    }
  }
  FUN_1000a227(param_1);
  return;
}



// Function: FUN_1000a651 at 1000a651

void __fastcall FUN_1000a651(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_1000a661 at 1000a661

void __fastcall FUN_1000a661(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FUN_10009d63(param_1);
    return;
  }
  return;
}



// Function: FUN_1000a66e at 1000a66e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000a66e(int param_1)

{
  FUN_10009d02((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FUN_1000a68f at 1000a68f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_1000a68f(void *this,int param_1,undefined4 *param_2,undefined4 *param_3)

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



// Function: FUN_1000a6e3 at 1000a6e3

undefined4 __fastcall FUN_1000a6e3(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1000a6e6 at 1000a6e6

void __fastcall FUN_1000a6e6(CWinApp *param_1)

{
  FUN_1000a5fa(0x10029f00);
  CWinApp::ExitInstance(param_1);
  return;
}



// Function: FUN_1000a6fb at 1000a6fb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000a6fb(undefined4 *param_1)

{
  param_1[1] = 0;
  FUN_1000915d(param_1 + 2);
  *param_1 = ATL::CComClassFactory::vftable;
  return param_1;
}



// Function: FUN_1000a736 at 1000a736

undefined4 FUN_1000a736(int param_1,int param_2,_GUID *param_3,undefined4 *param_4)

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



// Function: FUN_1000a774 at 1000a774

undefined4 FUN_1000a774(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    (**(code **)(*DAT_10029388 + 8))();
  }
  else {
    (**(code **)(*DAT_10029388 + 4))();
  }
  return 0;
}



// Function: FUN_1000a793 at 1000a793

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000a793(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CUserManagerImpl>::vftable;
  FUN_100093c4((void *)((int)this + 8),param_1);
  (**(code **)(*DAT_10029388 + 4))();
  return (undefined4 *)this;
}



// Function: FUN_1000a7d6 at 1000a7d6

long FUN_1000a7d6(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 2,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1001ed74,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_1000a822 at 1000a822

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000a822(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CUserManagerImpl>::vftable;
  param_1[1] = 0xc0000001;
  FUN_1000d87f((int)(param_1 + 2));
  (**(code **)(*DAT_10029388 + 8))();
  FUN_1000f3c4((int)(param_1 + 2));
  return;
}



// Function: FUN_1000a86f at 1000a86f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000a86f(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CUsersImpl>::vftable;
  FUN_100093ff((void *)((int)this + 8),param_1);
  (**(code **)(*DAT_10029388 + 4))();
  return (undefined4 *)this;
}



// Function: Release at 1000a8b2

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



// Function: FUN_1000a8d3 at 1000a8d3

long FUN_1000a8d3(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 2,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1001ee00,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_1000a91f at 1000a91f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000a91f(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CUsersImpl>::vftable;
  param_1[1] = 0xc0000001;
  FUN_100117ec((int)(param_1 + 2));
  (**(code **)(*DAT_10029388 + 8))();
  FUN_1001171d((int)(param_1 + 2));
  return;
}



// Function: FUN_1000a96c at 1000a96c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000a96c(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CGroupsImpl>::vftable;
  FUN_10009437((void *)((int)this + 8),param_1);
  (**(code **)(*DAT_10029388 + 4))();
  return (undefined4 *)this;
}



// Function: FUN_1000a9af at 1000a9af

long FUN_1000a9af(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 2,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1001ee90,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_1000a9fb at 1000a9fb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000a9fb(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CGroupsImpl>::vftable;
  param_1[1] = 0xc0000001;
  FUN_10001fb8((int)(param_1 + 2));
  (**(code **)(*DAT_10029388 + 8))();
  FUN_10007dc9((int)(param_1 + 2));
  return;
}



// Function: FUN_1000aa48 at 1000aa48

undefined4 * __thiscall FUN_1000aa48(void *this,byte param_1)

{
  FUN_1000a822((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000aa67 at 1000aa67

undefined4 * __thiscall FUN_1000aa67(void *this,byte param_1)

{
  FUN_1000a91f((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000aa86 at 1000aa86

undefined4 * __thiscall FUN_1000aa86(void *this,byte param_1)

{
  FUN_1000a9fb((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000aaa5 at 1000aaa5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_1000aaa5(undefined4 *param_1)

{
  FUN_1000a1e6((int)param_1);
  *param_1 = ATL::CComModule::vftable;
  _DAT_100293a8 = param_1;
  return param_1;
}



// Function: FUN_1000aada at 1000aada

void __fastcall FUN_1000aada(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_1000aae5 at 1000aae5

void __fastcall FUN_1000aae5(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_1000aaf0 at 1000aaf0

HRESULT __thiscall FUN_1000aaf0(void *this,undefined4 *param_1)

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
       (HVar1 = CoCreateInstance((IID *)&DAT_1001f5dc,(LPUNKNOWN)0x0,1,(IID *)&DAT_1001f258,ppv),
       -1 < HVar1)) {
      *param_1 = *ppv;
                    /* WARNING: Load size is inaccurate */
      (**(code **)(**ppv + 4))(*ppv);
    }
  }
  return HVar1;
}



// Function: FUN_1000ab3c at 1000ab3c

undefined4 FUN_1000ab3c(void)

{
  return 0x80004005;
}



// Function: FUN_1000ab44 at 1000ab44

void FUN_1000ab44(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",&DAT_1001dbfc);
  return;
}



// Function: FUN_1000ab5e at 1000ab5e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000ab5e(void *this,byte param_1)

{
  *(undefined ***)this = ATL::CComModule::vftable;
  FUN_1000a227((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000ab95 at 1000ab95

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000ab95(int *param_1)

{
  FUN_1000a368(param_1);
  FUN_10009cd5(param_1);
  return;
}



// Function: FUN_1000abbf at 1000abbf

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000abbf(undefined4 *param_1)

{
  *param_1 = ATL::CRegObject::vftable;
  FUN_1000a368(param_1 + 1);
  FUN_1000ab95(param_1 + 1);
  return;
}



// Function: FUN_1000abf3 at 1000abf3

undefined4 FUN_1000abf3(void)

{
  return 0x80004001;
}



// Function: FUN_1000abfb at 1000abfb

undefined4 FUN_1000abfb(void)

{
  return 1;
}



// Function: FUN_1000ac01 at 1000ac01

undefined4 FUN_1000ac01(void)

{
  return 0;
}



// Function: FUN_1000ac06 at 1000ac06

undefined4 * __thiscall FUN_1000ac06(void *this,byte param_1)

{
  FUN_1000abbf((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000ac25 at 1000ac25

undefined4 __fastcall FUN_1000ac25(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_10009d2c((void *)(param_1 + 4),(undefined4 *)&stack0x00000004);
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



// Function: FUN_1000ac66 at 1000ac66

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000ac66(void *this,LPCWSTR param_1,int *param_2)

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
  local_8 = 0x1000ac72;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != (int *)0x0)) {
    *param_2 = 0;
    iVar3 = lstrlenW(param_1);
    FUN_100097a2(&local_70,iVar3 * 2);
    local_8 = 0;
    if (local_68 == (LPVOID)0x0) {
      local_8 = 0xffffffff;
      CoTaskMemFree((LPVOID)0x0);
    }
    else {
      *(LPCWSTR *)this = param_1;
      local_5d = '\0';
      local_5c = FUN_10009bd0(&local_5d);
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
LAB_1000ad5b:
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x27) {
                if (local_55 == '\0') {
                  local_55 = '\x01';
                  goto LAB_1000adcf;
                }
                iVar3 = FUN_10009782((undefined4 *)this);
                if (iVar3 == 0) {
                    /* WARNING: Load size is inaccurate */
                  pWVar5 = CharNextW(*this);
                  *(LPWSTR *)this = pWVar5;
                  iVar3 = FUN_100097e2(&local_70,pWVar5,1);
                  if (iVar3 == 0) goto LAB_1000adf5;
                  goto LAB_1000ad97;
                }
                local_55 = '\0';
              }
              else {
LAB_1000ad97:
                if (local_55 != '\0') goto LAB_1000adcf;
              }
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x7b) {
                local_64 = local_64 + 1;
              }
              if (((**this == 0x7d) && (local_64 = local_64 + -1, local_64 == 0)) &&
                 (local_56 == '\x01')) {
                iVar3 = FUN_1000a3bf(&local_70,L"\r\n\t}\r\n}\r\n");
                if (iVar3 == 0) goto LAB_1000adf5;
                local_56 = '\0';
              }
              goto LAB_1000adcf;
            }
            pWVar5 = CharNextW(*this);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            iVar3 = FUN_1000a3bf(&local_70,L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses");
            if (iVar3 != 0) {
              local_56 = '\x01';
              goto LAB_1000ad5b;
            }
LAB_1000adf5:
            local_5c = -0x7ff8fff2;
            goto LAB_1000acd6;
          }
LAB_1000adcf:
                    /* WARNING: Load size is inaccurate */
          pWVar6 = *this;
          if (*pWVar6 == L'%') {
            pWVar5 = CharNextW(pWVar6);
            *(LPWSTR *)this = pWVar5;
            if (*pWVar5 != L'%') {
              pWVar6 = FUN_1000997c(pWVar5,L'%');
              if (pWVar6 != (LPCWSTR)0x0) {
                    /* WARNING: Load size is inaccurate */
                _MaxCount = (int)pWVar6 - (int)*this >> 1;
                if (0x1f < (int)_MaxCount) {
                  local_5c = -0x7fffbffb;
                  goto LAB_1000acd6;
                }
                eVar7 = wcsncpy_s(local_54,0x20,*this,_MaxCount);
                AfxCrtErrorCheck(eVar7);
                pWVar8 = (LPCWSTR)FUN_1000ac25(*(int *)((int)this + 4));
                if (pWVar8 != (LPCWSTR)0x0) {
                  iVar3 = FUN_1000a3bf(&local_70,pWVar8);
                  if (iVar3 == 0) goto LAB_1000adf5;
                    /* WARNING: Load size is inaccurate */
                  pWVar8 = *this;
                  while (pWVar8 != pWVar6) {
                    /* WARNING: Load size is inaccurate */
                    pWVar8 = CharNextW(*this);
                    *(LPCWSTR *)this = pWVar8;
                  }
                  goto LAB_1000ae68;
                }
              }
              local_5c = -0x7ffdfff7;
              goto LAB_1000acd6;
            }
            iVar3 = FUN_100097e2(&local_70,pWVar5,1);
            if (iVar3 == 0) goto LAB_1000adf5;
          }
          else {
            iVar3 = FUN_100097e2(&local_70,pWVar6,1);
            if (iVar3 == 0) {
              local_5c = -0x7ff8fff2;
              break;
            }
          }
LAB_1000ae68:
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
LAB_1000acd6:
      local_8 = 0xffffffff;
      CoTaskMemFree(local_68);
    }
  }
  FUN_10014f84();
  return;
}



// Function: FUN_1000aed3 at 1000aed3

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000aed3(GUID *param_1,int *param_2,int param_3)

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
      (iVar2 = _InlineIsEqualGUID((int *)param_1,(int *)&DAT_1001f5cc), iVar2 == 0)) &&
     (HVar3 = CoCreateInstance((IID *)&DAT_1001f5ec,(LPUNKNOWN)0x0,1,(IID *)&DAT_1001f354,&local_1a8
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
          goto LAB_1000b15e;
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
      AfxCrtErrorCheck(eVar4);
      eVar4 = wcscat_s(local_114,0x80,local_194);
      AfxCrtErrorCheck(eVar4);
      eVar4 = wcscat_s(local_114,0x80,L"\\Required Categories");
      AfxCrtErrorCheck(eVar4);
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
      AfxCrtErrorCheck(eVar4);
      eVar4 = wcscat_s(local_114,0x80,local_194);
      AfxCrtErrorCheck(eVar4);
      eVar4 = wcscat_s(local_114,0x80,L"\\Implemented Categories");
      AfxCrtErrorCheck(eVar4);
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
      FUN_100014b1(&local_1cc);
    }
  }
  local_8 = 0xffffffff;
  if (local_1a8 != (int *)0x0) {
    (**(code **)(*local_1a8 + 8))(local_1a8);
  }
LAB_1000b15e:
  FUN_10014f84();
  return;
}



// Function: FUN_1000b1f1 at 1000b1f1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_1000b1f1(HMODULE param_1,LPCWSTR param_2)

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
  iVar1 = FUN_1000a418(param_1,param_2,&local_18,local_14);
  if ((-1 < iVar1) && (iVar1 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],&param_1), -1 < iVar1)
     ) {
    param_2 = (LPCWSTR)((uint)param_2 & 0xffffff);
    iVar1 = FUN_10009bd0((undefined1 *)((int)&param_2 + 3));
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



// Function: FUN_1000b2c1 at 1000b2c1

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000b2c1(HMODULE param_1,LPCWSTR param_2)

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
  iVar2 = FUN_1000a418(param_1,param_2,&local_22c,&local_228);
  if (-1 < iVar2) {
    pWVar6 = (WCHAR *)0x0;
    local_224 = (wchar_t *)0x0;
    local_8 = CONCAT31(local_8._1_3_,3);
    iVar2 = (**(code **)(*local_228 + 0x24))(local_228,0xffffffff,0,0,0,&local_224);
    if ((-1 < iVar2) && (local_224 != (wchar_t *)0x0)) {
      _MaxCount = Ordinal_7(local_224);
      eVar3 = wcsncpy_s(local_21c,0x104,local_224,_MaxCount);
      AfxCrtErrorCheck(eVar3);
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
    iVar2 = FUN_10009bd0(&local_21d);
    if (iVar2 < 0) {
      local_8._0_1_ = 2;
      Ordinal_6(local_224);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_228 != (int *)0x0) {
        (**(code **)(*local_228 + 8))(local_228);
      }
      local_8 = 0xffffffff;
      Ordinal_6(local_22c);
      goto LAB_1000b483;
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
LAB_1000b483:
  FUN_10014f84();
  return;
}



// Function: FUN_1000b48b at 1000b48b

int FUN_1000b48b(int param_1,int param_2,void *param_3)

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
            (bVar3 = FUN_1000901b(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          iVar7 = 1;
          iVar4 = (*(code *)puVar1[1])();
          if (iVar4 < 0) {
            return iVar4;
          }
          piVar5 = (int *)(*(code *)puVar1[7])(1);
          param_1 = FUN_1000aed3((GUID *)*puVar1,piVar5,iVar7);
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
      param_1 = FUN_1000b2c1(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_1000b511 at 1000b511

int FUN_1000b511(int param_1,int param_2,void *param_3)

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
            (bVar3 = FUN_1000901b(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          iVar6 = 0;
          piVar4 = (int *)(*(code *)puVar1[7])();
          iVar6 = FUN_1000aed3((GUID *)*puVar1,piVar4,iVar6);
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
      param_1 = FUN_1000b1f1(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_1000b598 at 1000b598

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_1000b598(int *param_1,int *param_2,undefined4 param_3,int *param_4)

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
              param_1 = (int *)(*(code *)puVar1[2])(puVar1[3],&DAT_1001dcfc,piVar3);
            }
            LeaveCriticalSection(lpCriticalSection);
            if (*piVar3 != 0) goto LAB_1000b653;
          }
          else {
LAB_1000b653:
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



// Function: FUN_1000b683 at 1000b683

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000b683(undefined4 *param_1)

{
  *param_1 = ATL::CComClassFactory::vftable;
  FUN_10009d02((LPCRITICAL_SECTION)(param_1 + 2));
  return;
}



// Function: FUN_1000b6b4 at 1000b6b4

undefined4 * __thiscall FUN_1000b6b4(void *this,byte param_1)

{
  FUN_1000b683((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000b6d3 at 1000b6d3

undefined4 __thiscall FUN_1000b6d3(void *this,undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  
                    /* WARNING: Load size is inaccurate */
  pvVar1 = _recalloc(*this,*(int *)((int)this + 8) + 1,4);
  if (pvVar1 != (void *)0x0) {
    *(void **)this = pvVar1;
    pvVar1 = _recalloc(*(void **)((int)this + 4),*(int *)((int)this + 8) + 1,4);
    if (pvVar1 != (void *)0x0) {
      *(void **)((int)this + 4) = pvVar1;
      FUN_1000a68f(this,*(int *)((int)this + 8),param_1,param_2);
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      return 1;
    }
  }
  return 0;
}



// Function: Allocate at 1000b72a

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
    FUN_10009d6d(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 1000b759

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
    FUN_10009d6d(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 1000b788

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
    FUN_10009d6d(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_1000b7b7 at 1000b7b7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000b7b7(undefined4 *param_1)

{
  FUN_1000a6fb(param_1);
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  return param_1;
}



// Function: FUN_1000b7e5 at 1000b7e5

LONG FUN_1000b7e5(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_10029388 + 4))();
  }
  return LVar1;
}



// Function: FUN_1000b80f at 1000b80f

LONG FUN_1000b80f(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (LVar1 == 1) {
    (**(code **)(*DAT_10029388 + 8))();
  }
  return LVar1;
}



// Function: QueryInterface at 1000b84e

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1001f3d0,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_1000b868 at 1000b868

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000b868(undefined4 *param_1)

{
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  param_1[1] = 0xc0000001;
  FUN_1000b683(param_1);
  return;
}



// Function: FUN_1000b897 at 1000b897

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint FUN_1000b897(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  uint uVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x60);
    if (this != (void *)0x0) {
      FUN_1000a793(this,param_1);
    }
    uVar1 = FUN_1000b90d();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@1000b8f5 at 1000b8f5

undefined * Catch_1000b8f5(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x20));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000b907;
}



// Function: FUN_1000b90d at 1000b90d

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint FUN_1000b90d(void)

{
  uint uVar1;
  int *unaff_ESI;
  uint unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    uVar1 = FUN_1000d4b9((int)(unaff_ESI + 2));
    unaff_EDI = uVar1;
    if (-1 < (int)uVar1) {
      unaff_EDI = 0;
    }
    if ((uVar1 < 0x80000000) && (unaff_EDI = (**(code **)*unaff_ESI)(), unaff_EDI == 0)) {
      return 0;
    }
    (**(code **)(*unaff_ESI + 0xc))(1);
  }
  return unaff_EDI;
}



// Function: FUN_1000b949 at 1000b949

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint FUN_1000b949(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  uint uVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x1c);
    if (this != (void *)0x0) {
      FUN_1000a86f(this,param_1);
    }
    uVar1 = FUN_1000b9bf();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@1000b9a7 at 1000b9a7

undefined * Catch_1000b9a7(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x20));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000b9b9;
}



// Function: FUN_1000b9bf at 1000b9bf

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint FUN_1000b9bf(void)

{
  uint uVar1;
  int *unaff_ESI;
  uint unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    uVar1 = FUN_10011834((int)(unaff_ESI + 2));
    unaff_EDI = uVar1;
    if (-1 < (int)uVar1) {
      unaff_EDI = 0;
    }
    if ((uVar1 < 0x80000000) && (unaff_EDI = (**(code **)*unaff_ESI)(), unaff_EDI == 0)) {
      return 0;
    }
    (**(code **)(*unaff_ESI + 0xc))(1);
  }
  return unaff_EDI;
}



// Function: FUN_1000b9fb at 1000b9fb

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint FUN_1000b9fb(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  uint uVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x28);
    if (this != (void *)0x0) {
      FUN_1000a96c(this,param_1);
    }
    uVar1 = FUN_1000ba71();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@1000ba59 at 1000ba59

undefined * Catch_1000ba59(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x20));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000ba6b;
}



// Function: FUN_1000ba71 at 1000ba71

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint FUN_1000ba71(void)

{
  uint uVar1;
  int *unaff_ESI;
  uint unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    uVar1 = FUN_10011834((int)(unaff_ESI + 2));
    unaff_EDI = uVar1;
    if (-1 < (int)uVar1) {
      unaff_EDI = 0;
    }
    if ((uVar1 < 0x80000000) && (unaff_EDI = (**(code **)*unaff_ESI)(), unaff_EDI == 0)) {
      return 0;
    }
    (**(code **)(*unaff_ESI + 0xc))(1);
  }
  return unaff_EDI;
}



// Function: FUN_1000baad at 1000baad

undefined4 * __thiscall FUN_1000baad(void *this,byte param_1)

{
  FUN_1000b868((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000bacc at 1000bacc

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000bacc(LPCWSTR param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != 0)) {
    iVar2 = lstrlenW(param_1);
    lVar1 = (ulonglong)(iVar2 * 2 + 2) * 2;
    operator_new__(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    uVar3 = FUN_1000bb3a();
    return uVar3;
  }
  return 0;
}



// Function: Catch@1000bb26 at 1000bb26

undefined * Catch_1000bb26(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x34));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000bb38;
}



// Function: FUN_1000bb3a at 1000bb3a

void FUN_1000bb3a(void)

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
  FUN_1000bb93();
  return;
}



// Function: Catch@1000bb7c at 1000bb7c

undefined * Catch_1000bb7c(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x38));
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return &DAT_1000bb91;
}



// Function: FUN_1000bb93 at 1000bb93

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_1000bb93(void)

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
    FUN_100010f3(*(void **)(unaff_EBP + -0x14),*(rsize_t *)(unaff_EBP + -0x28),
                 *(void **)(unaff_EBP + 8),*(rsize_t *)(unaff_EBP + -0x28));
    FUN_100010f3(pvVar1,*(rsize_t *)(unaff_EBP + -0x2c),*(void **)(unaff_EBP + 0xc),
                 *(rsize_t *)(unaff_EBP + -0x2c));
    iVar2 = FUN_1000b6d3(*(void **)(unaff_EBP + -0x30),(undefined4 *)(unaff_EBP + -0x14),
                         (undefined4 *)(unaff_EBP + -0x20));
    if (iVar2 != 0) {
      *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
      *(void **)(unaff_EBP + -0x18) = unaff_ESI;
      goto LAB_1000bbef;
    }
  }
  *(undefined4 *)(unaff_EBP + -0x24) = 0x8007000e;
LAB_1000bbef:
  iVar2 = *(int *)(unaff_EBP + -0x24);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  operator_delete__(*(void **)(unaff_EBP + -0x18));
  *(void **)(unaff_EBP + -0x18) = unaff_ESI;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  operator_delete__(*(void **)(unaff_EBP + -0x1c));
  *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
  return (int)unaff_ESI <= iVar2;
}



// Function: FUN_1000bc27 at 1000bc27

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_1000bc27(undefined4 param_1,LPCWSTR param_2,int param_3)

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
    iVar1 = FUN_1000bacc(param_2,param_3);
    iVar1 = (-(uint)(iVar1 != 0) & 0x7ff8fff2) + 0x8007000e;
    local_8 = 0xffffffff;
    FUN_100014b1(local_14);
  }
  return iVar1;
}



// Function: FUN_1000bc82 at 1000bc82

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_1000bc82(void *this,CRegKey *param_1,wchar_t *param_2,undefined2 *param_3)

{
  int iVar1;
  uint uVar2;
  uint uStack_214c;
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
  puStack_c = &LAB_10017ae2;
  local_10 = ExceptionList;
  uStack_214c = DAT_10028e44 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_214c;
  ExceptionList = &local_10;
  local_2124 = param_1;
  local_2128 = param_2;
  local_2120 = (wchar_t *)0x0;
  local_18 = uStack_214c;
  iVar1 = FUN_100099f1(this,local_2018);
  if ((iVar1 < 0) || (iVar1 = FUN_10009870(local_2018,(undefined2 *)&local_2120), iVar1 == 0))
  goto LAB_1000c014;
  FUN_100099cf((undefined4 *)this);
  iVar1 = FUN_100099f1(this,local_2018);
  if (iVar1 < 0) goto LAB_1000c014;
  uVar2 = (uint)local_2120 & 0xffff;
  if (uVar2 == 8) {
    uVar2 = ATL::CRegKey::SetStringValue(param_1,param_2,local_2018,1);
LAB_1000bff0:
    if (uVar2 != 0) {
      FUN_10009132(uVar2);
      goto LAB_1000c014;
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
        FUN_1000bf20();
        return;
      }
      goto LAB_1000c014;
    }
    if (uVar2 == 0x13) {
      local_2124 = (CRegKey *)0x0;
      local_8 = 3;
      Ordinal_277(local_2018,0,0,&local_2128);
      local_2120 = local_2128;
      uVar2 = RegSetValueExW(*(HKEY *)param_1,param_2,0,4,(BYTE *)&local_2120,4);
      local_8 = 0xffffffff;
      FUN_100014b1((int *)&local_2124);
      goto LAB_1000bff0;
    }
    if (uVar2 == 0x4008) {
      iVar1 = lstrlenW(local_2018);
      local_211c[0] = 0;
      local_8 = 1;
      Allocate(local_211c,iVar1 + 2);
      local_8 = 0;
      FUN_1000bdae();
      return;
    }
  }
  FUN_100099f1(this,param_3);
LAB_1000c014:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000bd97 at 1000bd97

undefined * Catch_1000bd97(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x2138));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_1000bdac;
}



// Function: FUN_1000bdae at 1000bdae

void FUN_1000bdae(void)

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
    pWVar2 = (WCHAR *)FUN_1000973f(*(void **)(unaff_EBP - 0x2120),*(LPCWSTR *)(unaff_EBP - 0x2124),
                                   *(LPCWSTR *)(unaff_EBP - 0x2118));
    unaff_EDI = (WCHAR *)0x0;
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  if (*(int *)(unaff_EBP - 0x2118) != unaff_EBP - 0x2114) {
    FUN_10009d63((undefined4 *)(unaff_EBP - 0x2118));
  }
  if (pWVar2 == unaff_EDI) {
    FUN_100099f1(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x2130));
  }
  else {
    FUN_10009132((uint)pWVar2);
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1000c02c;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@1000befa at 1000befa

undefined * Catch_1000befa(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x2134));
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return &DAT_1000bf12;
}



// Function: FUN_1000bf20 at 1000bf20

void FUN_1000bf20(void)

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
      FUN_10009d63((undefined4 *)(unaff_EBP - 0x2118));
    }
  }
  else {
    memset(*(void **)(unaff_EBP - 0x2118),unaff_EDI,unaff_EBX);
    if ((int)unaff_EDI < *(int *)(unaff_EBP - 0x211c)) {
      do {
        pbVar1 = (byte *)((int)unaff_EDI / 2 + *(int *)(unaff_EBP - 0x2118));
        iVar2 = FUN_10009918(*(ushort *)((unaff_EBP - 0x2014) + unaff_EDI * 2));
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
      FUN_10009d63((undefined4 *)(unaff_EBP - 0x2118));
    }
    if (uVar3 == unaff_EDI) {
      FUN_100099f1(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x2130));
    }
    else {
      FUN_10009132(uVar3);
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1000c02c;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_1000c030 at 1000c030

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_1000c030(void *this,LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

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
  puStack_c = &LAB_10017b41;
  local_10 = ExceptionList;
  local_14 = DAT_10028e44 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2228 = param_2;
  local_2234 = (HKEY)0x0;
  local_2230 = 0;
  local_222c = 0;
  local_8 = 0;
  local_2220 = this;
LAB_1000c094:
  iVar3 = FUN_100099f1(local_2220,param_1);
  do {
    if (iVar3 < 0) {
LAB_1000c0a4:
      local_8 = 0xffffffff;
      ATL::CRegKey::Close((CRegKey *)&local_2234);
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
LAB_1000c501:
    if (*param_1 == L'}') goto LAB_1000c0a4;
    local_2238 = 1;
    iVar3 = lstrcmpiW(param_1,L"Delete");
    local_2224 = (uint)(iVar3 == 0);
    iVar4 = lstrcmpiW(param_1,L"ForceRemove");
    if ((iVar4 == 0) || ((iVar3 == 0) != 0)) {
      iVar3 = FUN_100099f1(local_2220,param_1);
      if (iVar3 < 0) goto LAB_1000c0a4;
      if (param_3 == 0) goto LAB_1000c1e3;
      local_2244 = (HKEY)0x0;
      local_2240 = 0;
      local_223c = 0;
      local_8._0_1_ = 1;
      pWVar5 = FUN_1000997c(param_1,L'\\');
      if (pWVar5 == (LPCWSTR)0x0) {
        iVar3 = FUN_10009b07(param_1);
        if (iVar3 != 0) {
          local_2244 = local_2228;
          local_2240 = 0;
          local_223c = 0;
          FUN_1000a283(&local_2244,param_1);
          local_2244 = (HKEY)0x0;
          local_2240 = 0;
          local_223c = 0;
        }
        if (local_2224 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_2244);
          goto LAB_1000c1e3;
        }
        iVar3 = FUN_100099f1(local_2220,param_1);
        if ((-1 < iVar3) && (iVar3 = FUN_10009b6b(local_2220,param_1), -1 < iVar3)) {
          local_8 = (uint)local_8._1_3_ << 8;
          pCVar8 = (CRegKey *)&local_2244;
          goto LAB_1000c600;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_2244;
        goto LAB_1000c67f;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2244);
      goto LAB_1000c0a4;
    }
LAB_1000c1e3:
    iVar3 = lstrcmpiW(param_1,L"NoRemove");
    if (iVar3 == 0) {
      local_2238 = 0;
      iVar3 = FUN_100099f1(local_2220,param_1);
      if (iVar3 < 0) goto LAB_1000c0a4;
    }
    iVar3 = lstrcmpiW(param_1,L"Val");
    if (iVar3 != 0) {
      pWVar5 = FUN_1000997c(param_1,L'\\');
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
          AfxCrtErrorCheck(eVar7);
          iVar3 = FUN_100099f1(local_2220,param_1);
          if (((-1 < iVar3) && (iVar3 = FUN_10009b6b(local_2220,param_1), -1 < iVar3)) &&
             (((*param_1 != L'{' || (iVar3 = lstrlenW(param_1), iVar3 != 1)) ||
              (((iVar3 = FUN_1000c030(local_2220,param_1,local_2234,0,param_4), -1 < iVar3 ||
                (param_4 != 0)) && (iVar3 = FUN_100099f1(local_2220,param_1), -1 < iVar3))))))
          break;
        }
        else {
          iVar3 = Open(&local_2234,local_2228,param_1,0x2001f);
          if (((iVar3 != 0) && (iVar3 = Open(&local_2234,local_2228,param_1,0x20019), iVar3 != 0))
             && (uVar6 = Create(&local_2234,local_2228,param_1,(LPWSTR)0x0,0,0x2001f,
                                (LPSECURITY_ATTRIBUTES)0x0,(undefined4 *)0x0), uVar6 != 0))
          goto LAB_1000c69e;
          iVar3 = FUN_100099f1(local_2220,param_1);
          if ((-1 < iVar3) &&
             ((*param_1 != L'=' ||
              (iVar3 = FUN_1000bc82(local_2220,(CRegKey *)&local_2234,(wchar_t *)0x0,param_1),
              -1 < iVar3)))) goto LAB_1000c605;
        }
      }
      goto LAB_1000c0a4;
    }
    iVar3 = FUN_100099f1(local_2220,local_221c);
    if (((iVar3 < 0) || (iVar3 = FUN_100099f1(local_2220,param_1), iVar3 < 0)) || (*param_1 != L'=')
       ) goto LAB_1000c0a4;
    if (param_3 != 0) {
      local_8._0_1_ = 2;
      local_225c = local_2228;
      local_2258 = 0;
      local_2254 = 0;
      iVar3 = FUN_1000bc82(local_2220,(CRegKey *)&local_225c,local_221c,param_1);
      local_225c = (HKEY)0x0;
      local_2258 = 0;
      local_2254 = 0;
      if (-1 < iVar3) {
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_225c;
        goto LAB_1000c600;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      pCVar8 = (CRegKey *)&local_225c;
      goto LAB_1000c67f;
    }
    if ((iVar1 == 0) && (local_2238 != 0)) {
      local_2268 = (HKEY)0x0;
      local_2264 = 0;
      local_2260 = 0;
      local_8._0_1_ = 3;
      uVar6 = Open(&local_2268,local_2228,(LPCWSTR)0x0,0x20006);
      if ((uVar6 != 0) ||
         ((uVar6 = RegDeleteValueW(local_2268,local_221c), uVar6 != 0 && (uVar6 != 2)))) {
        FUN_10009132(uVar6);
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_2268;
LAB_1000c67f:
        ATL::CRegKey::Close(pCVar8);
        goto LAB_1000c0a4;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2268);
    }
    iVar3 = FUN_10009b6b(local_2220,param_1);
  } while( true );
  if (local_2224 != 2) {
    if (local_2224 == 0) {
      if ((iVar1 != 0) && (bVar2 = FUN_10009b36(local_2234), CONCAT31(extraout_var,bVar2) != 0)) {
        iVar3 = FUN_10009b07(local_21c);
        if ((iVar3 != 0) && (local_2238 != 0)) {
          FUN_1000a283(&local_2234,local_21c);
        }
        goto LAB_1000c501;
      }
      bVar2 = FUN_10009b36(local_2234);
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
            FUN_10009132(uVar6);
            local_8 = (uint)local_8._1_3_ << 8;
            pCVar8 = (CRegKey *)&local_2250;
            goto LAB_1000c67f;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          pCVar8 = (CRegKey *)&local_2250;
LAB_1000c600:
          ATL::CRegKey::Close(pCVar8);
LAB_1000c605:
          if (((param_3 != 0) && (*param_1 == L'{')) && (iVar3 = lstrlenW(param_1), iVar3 == 1)) {
            iVar3 = FUN_1000c030(local_2220,param_1,local_2234,param_3,0);
            if (-1 < iVar3) goto LAB_1000c094;
            goto LAB_1000c0a4;
          }
        }
        goto LAB_1000c501;
      }
    }
    else {
      uVar6 = local_2224;
      if (iVar1 != 0) goto LAB_1000c501;
    }
LAB_1000c69e:
    FUN_10009132(uVar6);
    goto LAB_1000c0a4;
  }
  goto LAB_1000c501;
}



// Function: FUN_1000c6c7 at 1000c6c7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_1000c6c7(void *this,int *param_1,undefined4 param_2,int *param_3)

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
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1002b01c);
          local_14 = (int *)0x0;
          if (*piVar2 == 0) {
            local_14 = (int *)(*(code *)puVar3[2])(puVar3[3],&DAT_1001dcfc,piVar2);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1002b01c);
          if (*piVar2 != 0) goto LAB_1000c75b;
        }
        else {
LAB_1000c75b:
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
  piVar2 = FUN_1000b598((int *)&DAT_1002b00c,param_1,param_2,param_3);
  return piVar2;
}



// Function: FUN_1000c793 at 1000c793

void FUN_1000c793(int param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = FUN_1000b48b(0x1002b00c,param_1,param_2);
  if ((-1 < iVar1) && (DAT_100293a0 != (code *)0x0)) {
    (*DAT_100293a0)(DAT_1002afd8);
  }
  return;
}



// Function: FUN_1000c7c1 at 1000c7c1

void FUN_1000c7c1(int param_1,void *param_2)

{
  int iVar1;
  
  if ((DAT_100293a4 != (code *)0x0) && (iVar1 = (*DAT_100293a4)(), iVar1 < 0)) {
    return;
  }
  FUN_1000b511(0x1002b00c,param_1,param_2);
  return;
}



// Function: DllGetClassObject at 1000c7e7

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int *piVar1;
  
                    /* 0xc7e7  2  DllGetClassObject */
  piVar1 = FUN_1000c6c7(&DAT_10029f00,(int *)rclsid,riid,(int *)ppv);
  return (HRESULT)piVar1;
}



// Function: Catch@1000c853 at 1000c853

undefined1 * Catch_1000c853(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x20));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_1000c865;
}



// Function: FUN_1000c8ad at 1000c8ad

void FUN_1000c8ad(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_10009e56(0,param_2,param_3);
    return;
  }
  FUN_1000b897(param_1,param_2,param_3);
  return;
}



// Function: FUN_1000c8cd at 1000c8cd

void FUN_1000c8cd(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_10009f03(0,param_2,param_3);
    return;
  }
  FUN_1000b949(param_1,param_2,param_3);
  return;
}



// Function: FUN_1000c8ed at 1000c8ed

void FUN_1000c8ed(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_10009fb0(0,param_2,param_3);
    return;
  }
  FUN_1000b9fb(param_1,param_2,param_3);
  return;
}



// Function: FUN_1000c90d at 1000c90d

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_1000c90d(void *this,LPCWSTR param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  HKEY pHVar4;
  short *local_200c;
  WCHAR local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_10028e44 ^ (uint)&stack0xfffffffc;
  local_200c = (short *)0x0;
  iVar3 = FUN_1000ac66(this,param_1,(int *)&local_200c);
  if (iVar3 < 0) {
LAB_1000ca03:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(short **)this = local_200c;
  sVar1 = *local_200c;
joined_r0x1000c958:
  if ((((sVar1 == 0) || (iVar3 = FUN_100099f1(this,local_2008), iVar3 < 0)) ||
      (pHVar4 = (HKEY)FUN_1000994e(local_2008), pHVar4 == (HKEY)0x0)) ||
     ((iVar3 = FUN_100099f1(this,local_2008), iVar3 < 0 || (local_2008[0] != L'{'))))
  goto LAB_1000c9f5;
  if (param_2 == 0) {
    iVar3 = FUN_1000c030(this,local_2008,pHVar4,0,0);
    if (iVar3 < 0) goto LAB_1000c9f5;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar2 = *this;
    iVar3 = FUN_1000c030(this,local_2008,pHVar4,param_2,0);
    if (iVar3 < 0) {
      *(undefined4 *)this = uVar2;
      FUN_1000c030(this,local_2008,pHVar4,0,0);
LAB_1000c9f5:
      CoTaskMemFree(local_200c);
      goto LAB_1000ca03;
    }
  }
  FUN_100099cf((undefined4 *)this);
                    /* WARNING: Load size is inaccurate */
  sVar1 = **this;
  goto joined_r0x1000c958;
}



// Function: FUN_1000ca44 at 1000ca44

int __thiscall FUN_1000ca44(void *this,int param_1,void *param_2)

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
         (bVar1 = FUN_1000901b(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar6 = 1;
        iVar5 = (*(code *)piVar4[1])();
        if (iVar5 < 0) {
          return iVar5;
        }
        piVar3 = (int *)(*(code *)piVar4[7])(1);
        iVar5 = FUN_1000aed3((GUID *)*piVar4,piVar3,iVar6);
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
  iVar5 = FUN_1000c793(param_1,param_2);
  return iVar5;
}



// Function: FUN_1000cab3 at 1000cab3

int __thiscall FUN_1000cab3(void *this,int param_1,void *param_2)

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
         (bVar1 = FUN_1000901b(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar5 = 0;
        piVar3 = (int *)(*(code *)piVar4[7])();
        iVar5 = FUN_1000aed3((GUID *)*piVar4,piVar3,iVar5);
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
  iVar5 = FUN_1000c7c1(param_1,param_2);
  return iVar5;
}



// Function: DllRegisterServer at 1000cb22

void DllRegisterServer(void)

{
                    /* 0xcb22  3  DllRegisterServer */
  FUN_1000ca44(&DAT_10029f00,1,(void *)0x0);
  return;
}



// Function: DllUnregisterServer at 1000cb31

void DllUnregisterServer(void)

{
                    /* 0xcb31  4  DllUnregisterServer */
  FUN_1000cab3(&DAT_10029f00,1,(void *)0x0);
  return;
}



// Function: FUN_1000cb40 at 1000cb40

undefined4 FUN_1000cb40(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_100085e5(&PTR_DAT_10028d34,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_1000cb64 at 1000cb64

void FUN_1000cb64(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10008625(&PTR_DAT_10028d34,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_1000cb84 at 1000cb84

void FUN_1000cb84(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_100086c6(&PTR_DAT_10028d34,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_1000cb92 at 1000cb92

undefined4 FUN_1000cb92(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_100085e5(&PTR_DAT_10028d50,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_1000cbb6 at 1000cbb6

void FUN_1000cbb6(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10008625(&PTR_DAT_10028d50,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_1000cbd6 at 1000cbd6

void FUN_1000cbd6(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_100086c6(&PTR_DAT_10028d50,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_1000cbe4 at 1000cbe4

undefined4 FUN_1000cbe4(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_100085e5(&PTR_DAT_10028d6c,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_1000cc08 at 1000cc08

void FUN_1000cc08(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10008625(&PTR_DAT_10028d6c,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_1000cc28 at 1000cc28

void FUN_1000cc28(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_100086c6(&PTR_DAT_10028d6c,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_1000cc36 at 1000cc36

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000cc36(LPCWSTR param_1,LPCWSTR param_2,LPCWSTR param_3)

{
  HRSRC hResInfo;
  HGLOBAL pvVar1;
  DWORD DVar2;
  int local_424;
  HMODULE local_420;
  undefined1 *local_41c;
  undefined1 auStack_418 [1040];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x428;
  local_424 = 0;
  local_41c = (undefined1 *)0x0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_420 = LoadLibraryExW(param_1,(HANDLE)0x0,2);
  if (local_420 == (HMODULE)0x0) {
    FUN_1000911d();
  }
  else {
    hResInfo = FindResourceW(local_420,param_2,param_3);
    if ((hResInfo == (HRSRC)0x0) ||
       (pvVar1 = LoadResource(local_420,hResInfo), pvVar1 == (HGLOBAL)0x0)) {
      FUN_1000911d();
    }
    else {
      DVar2 = SizeofResource(local_420,hResInfo);
      if (DVar2 <= DVar2 + 1) {
        local_8 = CONCAT31(local_8._1_3_,2);
        Allocate(&local_41c,DVar2 + 1);
        local_8 = 1;
        FUN_1000cd1e();
        return;
      }
    }
    FreeLibrary(local_420);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_41c != auStack_418) {
    FUN_10009d63(&local_41c);
  }
  local_8 = 0xffffffff;
  FUN_100014b1(&local_424);
  FUN_10014f93();
  return;
}



// Function: Catch@1000ccfe at 1000ccfe

undefined * Catch_1000ccfe(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x434));
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000cd16;
}



// Function: FUN_1000cd1e at 1000cd1e

void FUN_1000cd1e(void)

{
  DWORD DVar1;
  DWORD unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  if (*(DWORD *)(unaff_EBP + -0x418) != unaff_EBX) {
    DVar1 = MultiByteToWideChar(3,unaff_EBX,*(LPCSTR *)(unaff_EBP + -0x428),unaff_ESI,
                                *(LPWSTR *)(unaff_EBP + -0x418),unaff_ESI);
    if (DVar1 == unaff_EBX) {
      FUN_1000911d();
    }
    else {
      *(undefined2 *)(*(int *)(unaff_EBP + -0x418) + DVar1 * 2) = 0;
      FUN_1000c90d((void *)(unaff_EBP + -0x430),*(LPCWSTR *)(unaff_EBP + -0x418),
                   *(int *)(unaff_EBP + 0x14));
    }
  }
  FreeLibrary(*(HMODULE *)(unaff_EBP + -0x41c));
  *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
  if (*(int *)(unaff_EBP + -0x418) != unaff_EBP + -0x414) {
    FUN_10009d63((undefined4 *)(unaff_EBP + -0x418));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_100014b1((int *)(unaff_EBP + -0x420));
  FUN_10014f93();
  return;
}



// Function: FUN_1000cda8 at 1000cda8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000cda8(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_1000cc36(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_100014b1(local_14);
  return uVar1;
}



// Function: FUN_1000cde9 at 1000cde9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000cde9(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

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
    FUN_100014b1(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_1000cc36(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_100014b1(local_14);
  }
  return uVar1;
}



// Function: FUN_1000ce45 at 1000ce45

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000ce45(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_1000cc36(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_100014b1(local_14);
  return uVar1;
}



// Function: FUN_1000ce85 at 1000ce85

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000ce85(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

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
    FUN_100014b1(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_1000cc36(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_100014b1(local_14);
  }
  return uVar1;
}



// Function: FUN_1000cee0 at 1000cee0

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000cee0(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

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
      FUN_1000bc27(&local_a60,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a60);
  pHVar1 = DAT_1002afd8;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_1002afd8,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_1000911d();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_100014b1((int *)&local_a48);
        goto LAB_1000cf62;
      }
      FUN_100095cb(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_10009092(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_100014b1((int *)&local_a48);
          goto LAB_1000cf62;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_1000bc27(&local_a60,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_1000bc27(&local_a60,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_1000ce85(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
        else {
          FUN_1000cde9(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_100014b1((int *)&local_a48);
  }
LAB_1000cf62:
  local_8 = 0xffffffff;
  FUN_1000abbf(&local_a60);
  FUN_10014f84();
  return;
}



// Function: FUN_1000d0e3 at 1000d0e3

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000d0e3(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

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
      FUN_1000bc27(&local_a5c,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a5c);
  pHVar1 = DAT_1002afd8;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_1002afd8,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_1000911d();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_100014b1((int *)&local_a48);
        goto LAB_1000d15c;
      }
      FUN_100095cb(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_10009092(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_100014b1((int *)&local_a48);
          goto LAB_1000d15c;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_1000bc27(&local_a5c,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_1000bc27(&local_a5c,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_1000ce45(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
        else {
          FUN_1000cda8(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_100014b1((int *)&local_a48);
  }
LAB_1000d15c:
  local_8 = 0xffffffff;
  FUN_1000abbf(&local_a5c);
  FUN_10014f84();
  return;
}



// Function: FUN_1000d2da at 1000d2da

void FUN_1000d2da(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

{
  FUN_1000cee0(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000d2e3 at 1000d2e3

void FUN_1000d2e3(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

{
  FUN_1000d0e3(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000d2ec at 1000d2ec

void FUN_1000d2ec(int param_1)

{
  FUN_1000d0e3((int *)&DAT_10029f00,0x66,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_1000d304 at 1000d304

void FUN_1000d304(int param_1)

{
  FUN_1000d0e3((int *)&DAT_10029f00,0x67,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_1000d31c at 1000d31c

void FUN_1000d31c(int param_1)

{
  FUN_1000d0e3((int *)&DAT_10029f00,0x68,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_1000d334 at 1000d334

int * __thiscall FUN_1000d334(void *this,int *param_1)

{
                    /* WARNING: Load size is inaccurate */
  if (*this != *param_1) {
    Ordinal_6(*this);
    *(int *)this = *param_1;
    *param_1 = 0;
  }
  return (int *)this;
}



// Function: FUN_1000d35a at 1000d35a

undefined4 FUN_1000d35a(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = _InlineIsEqualGUID(*(int **)((int)&PTR_DAT_10028d88 + uVar2),param_2);
    if (iVar1 != 0) {
      return 0;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 4);
  return 1;
}



// Function: FUN_1000d386 at 1000d386

undefined4 __thiscall FUN_1000d386(void *this,int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_1 == (int *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    *param_1 = *this;
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_1000d3ad at 1000d3ad

void __fastcall FUN_1000d3ad(int *param_1)

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



// Function: FUN_1000d3e8 at 1000d3e8

void __fastcall FUN_1000d3e8(int *param_1)

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



// Function: FUN_1000d42e at 1000d42e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __cdecl FUN_1000d42e(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
  }
  return &LAB_100181a1;
}



// Function: FUN_1000d45b at 1000d45b

LSTATUS __thiscall FUN_1000d45b(void *this,LPCWSTR param_1,LPCWSTR param_2,char param_3,int param_4)

{
  int iVar1;
  LSTATUS LVar2;
  
  if (param_1 == (LPCWSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_100010d9(-0x7fffbffb);
  }
  if (param_3 == '\0') {
    if (param_4 == -1) {
      iVar1 = lstrlenW(param_1);
      param_4 = iVar1 + 1;
    }
  }
  else if (param_4 == -1) {
    return 0x57;
  }
                    /* WARNING: Load size is inaccurate */
  LVar2 = RegSetValueExW(*this,param_2,0,((param_3 == '\0') - 1 & 6) + 1,(BYTE *)param_1,param_4 * 2
                        );
  return LVar2;
}



// Function: FUN_1000d4b9 at 1000d4b9

undefined4 __fastcall FUN_1000d4b9(int param_1)

{
  if (*(LPVOID *)(param_1 + 0x14) == (LPVOID)0x0) {
    CoCreateInstance((IID *)&DAT_1001eb80,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_1001eeb4,
                     (LPVOID *)(param_1 + 0x14));
  }
  if (*(LPVOID *)(param_1 + 0x10) == (LPVOID)0x0) {
    CoCreateInstance((IID *)&DAT_1001eb60,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_1001ee24,
                     (LPVOID *)(param_1 + 0x10));
  }
  return 0;
}



// Function: FUN_1000d4fa at 1000d4fa

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000d4fa(undefined4 param_1,short param_2)

{
  AFX_MODULE_STATE *pAVar1;
  AFX_MAINTAIN_STATE2 local_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x1000d506;
  pAVar1 = (AFX_MODULE_STATE *)FUN_10014bb5();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_20,pAVar1);
  DAT_10029fea = param_2 == -1;
  local_8 = 0xffffffff;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_20);
  return 0;
}



// Function: FUN_1000d53b at 1000d53b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000d53b(undefined4 param_1,short param_2)

{
  AFX_MODULE_STATE *pAVar1;
  AFX_MAINTAIN_STATE2 local_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x1000d547;
  pAVar1 = (AFX_MODULE_STATE *)FUN_10014bb5();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_20,pAVar1);
  DAT_10029fe9 = param_2 == -1;
  local_8 = 0xffffffff;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_20);
  return 0;
}



// Function: FUN_1000d57c at 1000d57c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000d57c(int param_1,int *param_2)

{
  AFX_MODULE_STATE *pAVar1;
  AFX_MAINTAIN_STATE2 local_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x1000d588;
  pAVar1 = (AFX_MODULE_STATE *)FUN_10014bb5();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_20,pAVar1);
  local_8 = 0;
  FUN_1000d386((void *)(param_1 + 0xc),param_2);
  local_8 = 0xffffffff;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_20);
  return 0;
}



// Function: FUN_1000d5be at 1000d5be

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000d5be(int param_1,int *param_2)

{
  AFX_MODULE_STATE *pAVar1;
  AFX_MAINTAIN_STATE2 local_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x1000d5ca;
  pAVar1 = (AFX_MODULE_STATE *)FUN_10014bb5();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_20,pAVar1);
  local_8 = 0;
  FUN_1000d386((void *)(param_1 + 0x14),param_2);
  local_8 = 0xffffffff;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_20);
  return 0;
}



// Function: FUN_1000d600 at 1000d600

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000d600(int param_1,int *param_2)

{
  AFX_MODULE_STATE *pAVar1;
  AFX_MAINTAIN_STATE2 local_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x1000d60c;
  pAVar1 = (AFX_MODULE_STATE *)FUN_10014bb5();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_20,pAVar1);
  local_8 = 0;
  FUN_1000d386((void *)(param_1 + 0x10),param_2);
  local_8 = 0xffffffff;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_20);
  return 0;
}



// Function: FUN_1000d642 at 1000d642

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000d642(undefined4 param_1,undefined4 *param_2)

{
  AFX_MODULE_STATE *pAVar1;
  undefined4 uVar2;
  AFX_MAINTAIN_STATE2 local_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x1000d64e;
  pAVar1 = (AFX_MODULE_STATE *)FUN_10014bb5();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_20,pAVar1);
  local_8 = 0;
  uVar2 = FUN_10001718(&DAT_1002a494);
  *param_2 = uVar2;
  local_8 = 0xffffffff;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_20);
  return 0;
}



// Function: FUN_1000d685 at 1000d685

int __thiscall FUN_1000d685(void *this,uint param_1)

{
  uint extraout_EAX;
  undefined4 *extraout_ECX;
  
  if (*(uint *)((int)this + 0x10) <= param_1) {
    std::_Xout_of_range("invalid string position");
    param_1 = extraout_EAX;
    this = extraout_ECX;
  }
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    this = *this;
  }
  return (int)this + param_1 * 2;
}



// Function: FUN_1000d6aa at 1000d6aa

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_1000d6aa(void *this,int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  *(int **)this = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return (int *)this;
}



// Function: FUN_1000d6da at 1000d6da

undefined4 * __thiscall FUN_1000d6da(void *this,int *param_1)

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
      if ((int)puVar2[3] < *param_1) {
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



// Function: FUN_1000d706 at 1000d706

uint __thiscall FUN_1000d706(void *this,uint param_1)

{
  uint uVar1;
  
                    /* WARNING: Load size is inaccurate */
  uVar1 = (*(int *)((int)this + 8) - *this) / 0xc;
  if (0x15555555 - (uVar1 >> 1) < uVar1) {
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 + (uVar1 >> 1);
  }
  if (uVar1 < param_1) {
    uVar1 = param_1;
  }
  return uVar1;
}



// Function: FUN_1000d735 at 1000d735

void __thiscall FUN_1000d735(void *this,int param_1)

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



// Function: FUN_1000d77a at 1000d77a

void __thiscall FUN_1000d77a(void *this,int *param_1)

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



// Function: FUN_1000d7c1 at 1000d7c1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_1000d7c1(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000d7cd;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10021060);
}



// Function: FUN_1000d820 at 1000d820

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_1000d820(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000d82c;
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  if ((param_1 < (char *)0x15555556) &&
     (pvVar1 = operator_new((int)param_1 * 0xc), pvVar1 != (void *)0x0)) {
    return pvVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_1c,&param_1);
  local_1c[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10021060);
}



// Function: FUN_1000d87f at 1000d87f

void __fastcall FUN_1000d87f(int param_1)

{
  int *piVar1;
  
  if ((*(int *)(param_1 + 0xc) != 0) && (piVar1 = *(int **)(param_1 + 0xc), piVar1 != (int *)0x0)) {
    *(undefined4 *)(param_1 + 0xc) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if ((*(int *)(param_1 + 0x10) != 0) && (piVar1 = *(int **)(param_1 + 0x10), piVar1 != (int *)0x0))
  {
    *(undefined4 *)(param_1 + 0x10) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if ((*(int *)(param_1 + 0x14) != 0) && (piVar1 = *(int **)(param_1 + 0x14), piVar1 != (int *)0x0))
  {
    *(undefined4 *)(param_1 + 0x14) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000d8c7 at 1000d8c7

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000d8c7(void)

{
  int iVar1;
  LPCWSTR *ppWVar2;
  LSTATUS LVar3;
  undefined4 **_Str2;
  DWORD local_22c;
  undefined4 local_228;
  undefined4 local_224;
  undefined4 local_220;
  wchar_t local_21c [266];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x21c;
  local_228 = 0;
  local_224 = 0;
  local_220 = 0;
  local_8 = 0;
  ppWVar2 = (LPCWSTR *)DAT_1002a498;
  if (DAT_1002a4ac < 8) {
    ppWVar2 = &DAT_1002a498;
  }
  iVar1 = Open(&local_228,(HKEY)0x80000002,(LPCWSTR)ppWVar2,0x2001f);
  if (iVar1 == 0) {
    local_22c = 0x208;
    ppWVar2 = (LPCWSTR *)DAT_1002a4b4;
    if (DAT_1002a4c8 < 8) {
      ppWVar2 = &DAT_1002a4b4;
    }
    LVar3 = FUN_100013a4(&local_228,(LPBYTE)local_21c,(LPCWSTR)ppWVar2,&local_22c);
    if (LVar3 == 0) {
      _Str2 = (undefined4 **)DAT_1002a4d0;
      if (DAT_1002a4e4 < 8) {
        _Str2 = &DAT_1002a4d0;
      }
      iVar1 = wcscmp(local_21c,(wchar_t *)_Str2);
      DAT_10029fe9 = iVar1 != 0;
    }
    ATL::CRegKey::Close((CRegKey *)&local_228);
  }
  local_8 = 0xffffffff;
  ATL::CRegKey::Close((CRegKey *)&local_228);
  FUN_10014f84();
  return;
}



// Function: FUN_1000d9a4 at 1000d9a4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000d9a4(undefined4 param_1,LPCWSTR param_2)

{
  AFX_MODULE_STATE *pAVar1;
  LPCWSTR pWVar2;
  int iVar3;
  LSTATUS LVar4;
  AFX_MAINTAIN_STATE2 local_2c [16];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x1000d9b0;
  pAVar1 = (AFX_MODULE_STATE *)FUN_10014bb5();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_2c,pAVar1);
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_8 = 1;
  pWVar2 = DAT_1002a4ec;
  if (DAT_1002a500 < 8) {
    pWVar2 = (LPCWSTR)&DAT_1002a4ec;
  }
  iVar3 = Open(&local_1c,(HKEY)0x80000002,pWVar2,0x2001f);
  if (iVar3 == 0) {
    pWVar2 = DAT_1002a508;
    if (DAT_1002a51c < 8) {
      pWVar2 = (LPCWSTR)&DAT_1002a508;
    }
    LVar4 = FUN_1000d45b(&local_1c,param_2,pWVar2,'\0',-1);
    if (LVar4 == 0) {
      if (param_2 == (LPCWSTR)0x0) {
        param_2 = (LPCWSTR)0x0;
      }
      else {
        param_2 = (LPCWSTR)Ordinal_2(param_2);
        if (param_2 == (LPCWSTR)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_100010d9(-0x7ff8fff2);
        }
      }
      local_8._0_1_ = 2;
      FUN_1000d334(&DAT_1002a490,(int *)&param_2);
      local_8 = CONCAT31(local_8._1_3_,1);
      Ordinal_6(param_2);
    }
    ATL::CRegKey::Close((CRegKey *)&local_1c);
  }
  local_8 = local_8 & 0xffffff00;
  ATL::CRegKey::Close((CRegKey *)&local_1c);
  local_8 = 0xffffffff;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_2c);
  return 0;
}



// Function: FUN_1000da8b at 1000da8b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000da8b(undefined4 param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  AFX_MODULE_STATE *pAVar2;
  AFX_MAINTAIN_STATE2 local_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x1000da97;
  pAVar2 = (AFX_MODULE_STATE *)FUN_10014bb5();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_20,pAVar2);
  local_8 = 0;
  if (param_2 != (undefined2 *)0x0) {
    FUN_1000d8c7();
    if (DAT_10029fe9 == '\0') {
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffff;
    }
    *param_2 = uVar1;
  }
  local_8 = 0xffffffff;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_20);
  return 0;
}



// Function: FUN_1000dae1 at 1000dae1

void __cdecl FUN_1000dae1(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  FUN_1000d42e(param_2,param_3);
  return;
}



// Function: FUN_1000daf3 at 1000daf3

void __fastcall FUN_1000daf3(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_1000d7c1((char *)0x1);
  *puVar1 = *(undefined4 *)(param_1 + 4);
  puVar1[1] = *(undefined4 *)(param_1 + 4);
  puVar1[2] = *(undefined4 *)(param_1 + 4);
  *(undefined2 *)(puVar1 + 0xb) = 0;
  return;
}



// Function: FUN_1000db1a at 1000db1a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000db1a(int param_1)

{
  FID_conflict__Tidy((void *)(param_1 + 4),'\x01',0);
  return;
}



// Function: FUN_1000db3f at 1000db3f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000db3f(int param_1)

{
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  uint local_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  int *local_18;
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0x1000db4b;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_3c = local_3c & 0xffff0000;
  local_14 = param_1;
  FUN_1000191a(&local_3c,&DAT_1002a490);
  local_8 = 0;
  (**(code **)(**(int **)(param_1 + 0x10) + 0x30))
            (*(int **)(param_1 + 0x10),local_3c,uStack_38,uStack_34,uStack_30,&local_2c);
  local_8 = 0xffffffff;
  Ordinal_9(&local_3c);
  local_20 = 0;
  local_18 = (int *)0x0;
  local_1c = 4;
  local_4c = (uint)local_4c._2_2_ << 0x10;
  FUN_10001965(&local_4c,local_24);
  local_8 = 1;
  (**(code **)(**(int **)(local_14 + 0x14) + 0x2c))
            (*(int **)(local_14 + 0x14),local_4c,uStack_48,uStack_44,uStack_40,&local_20);
  local_8 = 0xffffffff;
  Ordinal_9(&local_4c);
  if ((local_1c == 0) || (DAT_10029fea = 0, local_1c == 2)) {
    DAT_10029fea = 1;
  }
  Ordinal_6(local_20);
  (**(code **)(*local_18 + 8))(local_18);
  Ordinal_6(local_24);
  Ordinal_6(local_28);
  Ordinal_6(local_2c);
  return;
}



// Function: FUN_1000dc2a at 1000dc2a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000dc2a(int param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  AFX_MODULE_STATE *pAVar2;
  AFX_MAINTAIN_STATE2 local_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x1000dc36;
  pAVar2 = (AFX_MODULE_STATE *)FUN_10014bb5();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_20,pAVar2);
  local_8 = 0;
  if (param_2 != (undefined2 *)0x0) {
    FUN_1000db3f(param_1);
    if (DAT_10029fea == '\0') {
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffff;
    }
    *param_2 = uVar1;
  }
  local_8 = 0xffffffff;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_20);
  return 0;
}



// Function: FUN_1000dc80 at 1000dc80

int __fastcall FUN_1000dc80(int param_1)

{
  void *pvVar1;
  
  *(undefined4 *)(param_1 + 8) = 0;
  pvVar1 = FUN_1000d7c1((char *)0x1);
  *(void **)(param_1 + 4) = pvVar1;
  *(void **)pvVar1 = pvVar1;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x2c) = 1;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x2d) = 1;
  return param_1;
}



// Function: FUN_1000dcb7 at 1000dcb7

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __cdecl
FUN_1000dcb7(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  for (; param_1 != param_2; param_1 = param_1 + 3) {
    FUN_10001c5e(param_4,param_3,param_1);
    param_3 = param_3 + 3;
  }
  return param_3;
}



// Function: Catch@1000dcf5 at 1000dcf5

void Catch_1000dcf5(void)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000dcff at 1000dcff

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000dcff(int param_1)

{
  FID_conflict__Tidy((void *)(param_1 + 4),'\x01',0);
  return;
}



// Function: _Uninitialized_move<> at 1000dd24

/* Library Function - Multiple Matches With Same Base Name
    class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > * __cdecl
   std::_Uninitialized_move<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned
   char> > *,class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > *,struct
   std::_Wrap_alloc<class std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > > > >(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > *,struct std::_Wrap_alloc<class
   std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > > >
   &)
    class std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned
   char,class Concurrency::details::_CancellationTokenState *> > > * __cdecl
   std::_Uninitialized_move<class std::shared_ptr<struct Concurrency::details::_Task_impl<struct
   std::pair<unsigned char,class Concurrency::details::_CancellationTokenState *> > > *,class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,struct std::_Wrap_alloc<class
   std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<struct
   std::pair<unsigned char,class Concurrency::details::_CancellationTokenState *> > > > > >(class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,struct std::_Wrap_alloc<class
   std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<struct
   std::pair<unsigned char,class Concurrency::details::_CancellationTokenState *> > > > > &)
   
   Library: Visual Studio 2012 Release */

void __cdecl
_Uninitialized_move<>
          (undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  FUN_1000dcb7(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000dd43 at 1000dd43

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000dd43(void *this,byte param_1)

{
  FID_conflict__Tidy((void *)((int)this + 4),'\x01',0);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_1000dd7b at 1000dd7b

void __thiscall FUN_1000dd7b(void *this,undefined4 *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int **ppiVar3;
  int *local_8;
  
  piVar1 = param_2;
  local_8 = (int *)this;
  piVar2 = FUN_1000d6da(this,param_2);
  if ((piVar2 == *(int **)((int)this + 4)) || (*piVar1 < piVar2[3])) {
    local_8 = *(int **)((int)this + 4);
    ppiVar3 = &local_8;
  }
  else {
    ppiVar3 = &param_2;
  }
  *param_1 = *ppiVar3;
  return;
}



// Function: FUN_1000ddb5 at 1000ddb5

void __thiscall FUN_1000ddb5(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  _Uninitialized_move<>(param_1,param_2,param_3,(int)this + 0xc);
  return;
}



// Function: FUN_1000ddd1 at 1000ddd1

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000ddd1(void)

{
  int iVar1;
  LPCWSTR *ppWVar2;
  LSTATUS LVar3;
  undefined1 auStack_268 [16];
  undefined4 uStack_258;
  DWORD local_234;
  wchar_t *local_230;
  undefined4 local_22c;
  undefined4 local_228;
  undefined4 local_224;
  wchar_t local_220 [268];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x228;
  local_22c = 0;
  local_228 = 0;
  local_224 = 0;
  local_8 = 0;
  ppWVar2 = (LPCWSTR *)DAT_1002a4ec;
  if (DAT_1002a500 < 8) {
    ppWVar2 = &DAT_1002a4ec;
  }
  uStack_258 = 0x1000de20;
  iVar1 = Open(&local_22c,(HKEY)0x80000002,(LPCWSTR)ppWVar2,0x2001f);
  if (iVar1 == 0) {
    local_234 = 0x20a;
    ppWVar2 = (LPCWSTR *)DAT_1002a508;
    if (DAT_1002a51c < 8) {
      ppWVar2 = &DAT_1002a508;
    }
    uStack_258 = 0x1000de5f;
    LVar3 = FUN_100013a4(&local_22c,(LPBYTE)local_220,(LPCWSTR)ppWVar2,&local_234);
    if (LVar3 == 0) {
      iVar1 = wcscmp(local_220,L"System Administrator");
      if (iVar1 == 0) {
        basic_string<>(auStack_268,&DAT_1002a524);
        local_8 = local_8 & 0xffffff00;
        FUN_100138f3();
      }
      else {
        local_230 = local_220;
      }
      FUN_100016db(&DAT_1002a490,(int)local_230);
    }
    ATL::CRegKey::Close((CRegKey *)&local_22c);
  }
  local_8 = 0xffffffff;
  ATL::CRegKey::Close((CRegKey *)&local_22c);
  FUN_10014f84();
  return;
}



// Function: FUN_1000dedf at 1000dedf

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000dedf(undefined4 param_1,undefined4 *param_2)

{
  AFX_MODULE_STATE *pAVar1;
  undefined4 uVar2;
  AFX_MAINTAIN_STATE2 local_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x1000deeb;
  pAVar1 = (AFX_MODULE_STATE *)FUN_10014bb5();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_20,pAVar1);
  local_8 = 0;
  FUN_1000ddd1();
  uVar2 = FUN_10001718(&DAT_1002a490);
  *param_2 = uVar2;
  local_8 = 0xffffffff;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_20);
  return 0;
}



// Function: FUN_1000df2a at 1000df2a

void __fastcall FUN_1000df2a(_Container_base0 *param_1)

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



// Function: FUN_1000df4d at 1000df4d

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_1000df4d(void *this,char *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  if ((char *)0x15555555 < param_1) {
    std::_Xlength_error("vector<T> too long");
  }
                    /* WARNING: Load size is inaccurate */
  if ((char *)((*(int *)((int)this + 8) - *this) / 0xc) < param_1) {
    puVar1 = (undefined4 *)FUN_1000d820(param_1);
                    /* WARNING: Load size is inaccurate */
    FUN_1000ddb5(this,*this,*(undefined4 **)((int)this + 4),puVar1);
                    /* WARNING: Load size is inaccurate */
    iVar3 = *this;
    iVar2 = *(int *)((int)this + 4) - iVar3;
    if (iVar3 != 0) {
      for (; iVar3 != *(int *)((int)this + 4); iVar3 = iVar3 + 0xc) {
      }
                    /* WARNING: Load size is inaccurate */
      operator_delete(*this);
    }
    std::_Container_base0::_Orphan_all((_Container_base0 *)this);
    *(undefined4 **)((int)this + 8) = puVar1 + (int)param_1 * 3;
    *(undefined4 **)((int)this + 4) = puVar1 + (iVar2 / 0xc) * 3;
    *(undefined4 **)this = puVar1;
  }
  return;
}



// Function: Catch@1000dfec at 1000dfec

void Catch_1000dfec(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 8));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000e004 at 1000e004

void __thiscall FUN_1000e004(void *this,int param_1)

{
  uint uVar1;
  char *pcVar2;
  int extraout_ECX;
  int iVar3;
  
                    /* WARNING: Load size is inaccurate */
  iVar3 = *this;
  uVar1 = (*(int *)((int)this + 4) - iVar3) / 0xc;
  if (0x15555555U - param_1 < uVar1) {
    std::_Xlength_error("vector<T> too long");
    iVar3 = extraout_ECX;
  }
  uVar1 = uVar1 + param_1;
  if ((uint)((*(int *)((int)this + 8) - iVar3) / 0xc) < uVar1) {
    pcVar2 = (char *)FUN_1000d706(this,uVar1);
    FUN_1000df4d(this,pcVar2);
  }
  return;
}



// Function: FUN_1000e059 at 1000e059

void __cdecl FUN_1000e059(undefined4 param_1,void *param_2)

{
  FUN_1000dd43(param_2,0);
  return;
}



// Function: FUN_1000e068 at 1000e068

void __thiscall
FUN_1000e068(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

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
    FUN_1000e059(this,param_4 + 3);
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
LAB_1000e137:
        *(undefined1 *)(piVar1 + 0xb) = 1;
        *(undefined1 *)(iVar4 + 0x2c) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
        piVar5 = *(int **)(piVar5[1] + 4);
      }
      else {
        if (piVar5 == (int *)piVar1[2]) {
          FUN_1000d735(this,(int)piVar1);
          piVar5 = piVar1;
        }
        *(undefined1 *)(piVar5[1] + 0x2c) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
        FUN_1000d77a(this,*(int **)(piVar5[1] + 4));
      }
    }
    else {
      iVar4 = *piVar2;
      if (*(char *)(iVar4 + 0x2c) == '\0') goto LAB_1000e137;
      if (piVar5 == (int *)*piVar1) {
        FUN_1000d77a(this,piVar1);
        piVar5 = piVar1;
      }
      *(undefined1 *)(piVar5[1] + 0x2c) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
      FUN_1000d735(this,*(int *)(piVar5[1] + 4));
    }
    iVar4 = piVar5[1];
  } while( true );
}



// Function: FUN_1000e1a0 at 1000e1a0

void __thiscall FUN_1000e1a0(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < puVar1) && (puVar2 = *this, puVar2 <= param_1)) {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_1000e004(this,1);
    }
                    /* WARNING: Load size is inaccurate */
    FUN_10001c5e((int)this + 0xc,*(undefined4 **)((int)this + 4),
                 (undefined4 *)((((int)param_1 - (int)puVar2) / 0xc) * 0xc + *this));
  }
  else {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_1000e004(this,1);
    }
    FUN_1000dae1((int)this + 0xc,*(undefined4 **)((int)this + 4),param_1);
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0xc;
  return;
}



// Function: FUN_1000e20d at 1000e20d

void __thiscall FUN_1000e20d(void *this,int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x2d);
  while (cVar1 == '\0') {
    FUN_1000e20d(this,(int *)param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_1000e059((int)this + 0xd,param_1 + 3);
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x2d);
  }
  return;
}



// Function: FUN_1000e251 at 1000e251

void __thiscall FUN_1000e251(void *this,undefined4 *param_1,int *param_2)

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
  FUN_1000d3ad((int *)&param_2);
  piVar5 = (int *)*piVar2;
  if (*(char *)((int)piVar5 + 0x2d) == '\0') {
    piVar7 = piVar5;
    if ((*(char *)(piVar2[2] + 0x2d) != '\0') || (piVar7 = (int *)param_2[2], param_2 == piVar2))
    goto LAB_1000e29b;
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
LAB_1000e29b:
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
LAB_1000e478:
    FUN_1000e059((int)this + 0xd,piVar2 + 3);
    operator_delete(piVar2);
    if (*(int *)((int)this + 8) != 0) {
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
    }
    *param_1 = param_2;
    return;
  }
LAB_1000e42c:
  piVar6 = piVar5;
  if ((piVar7 == *(int **)(*(int *)((int)this + 4) + 4)) || ((char)piVar7[0xb] != '\x01'))
  goto LAB_1000e474;
  piVar5 = (int *)*piVar6;
  if (piVar7 == piVar5) {
    piVar5 = (int *)piVar6[2];
    if ((char)piVar5[0xb] == '\0') {
      *(undefined1 *)(piVar5 + 0xb) = 1;
      *(undefined1 *)(piVar6 + 0xb) = 0;
      FUN_1000d735(this,(int)piVar6);
      piVar5 = (int *)piVar6[2];
    }
    if (*(char *)((int)piVar5 + 0x2d) == '\0') {
      if ((*(char *)(*piVar5 + 0x2c) != '\x01') || (*(char *)(piVar5[2] + 0x2c) != '\x01')) {
        if (*(char *)(piVar5[2] + 0x2c) == '\x01') {
          *(undefined1 *)(*piVar5 + 0x2c) = 1;
          *(undefined1 *)(piVar5 + 0xb) = 0;
          FUN_1000d77a(this,piVar5);
          piVar5 = (int *)piVar6[2];
        }
        *(char *)(piVar5 + 0xb) = (char)piVar6[0xb];
        *(undefined1 *)(piVar6 + 0xb) = 1;
        *(undefined1 *)(piVar5[2] + 0x2c) = 1;
        FUN_1000d735(this,(int)piVar6);
        goto LAB_1000e474;
      }
LAB_1000e423:
      *(undefined1 *)(piVar5 + 0xb) = 0;
    }
  }
  else {
    if ((char)piVar5[0xb] == '\0') {
      *(undefined1 *)(piVar5 + 0xb) = 1;
      *(undefined1 *)(piVar6 + 0xb) = 0;
      FUN_1000d77a(this,piVar6);
      piVar5 = (int *)*piVar6;
    }
    if (*(char *)((int)piVar5 + 0x2d) == '\0') {
      if ((*(char *)(piVar5[2] + 0x2c) == '\x01') && (*(char *)(*piVar5 + 0x2c) == '\x01'))
      goto LAB_1000e423;
      if (*(char *)(*piVar5 + 0x2c) == '\x01') {
        *(undefined1 *)(piVar5[2] + 0x2c) = 1;
        *(undefined1 *)(piVar5 + 0xb) = 0;
        FUN_1000d735(this,(int)piVar5);
        piVar5 = (int *)*piVar6;
      }
      *(char *)(piVar5 + 0xb) = (char)piVar6[0xb];
      *(undefined1 *)(piVar6 + 0xb) = 1;
      *(undefined1 *)(*piVar5 + 0x2c) = 1;
      FUN_1000d77a(this,piVar6);
LAB_1000e474:
      *(undefined1 *)(piVar7 + 0xb) = 1;
      goto LAB_1000e478;
    }
  }
  piVar5 = (int *)piVar6[1];
  piVar7 = piVar6;
  goto LAB_1000e42c;
}



// Function: FUN_1000e4ae at 1000e4ae

void __thiscall FUN_1000e4ae(void *this,undefined4 *param_1,int *param_2,char param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *local_c;
  bool local_8;
  
  piVar2 = *(int **)((int)this + 4);
  piVar1 = param_2 + 3;
  local_8 = true;
  local_c = piVar2;
  if (*(char *)(piVar2[1] + 0x2d) == '\0') {
    piVar3 = (int *)piVar2[1];
    do {
      local_c = piVar3;
      if (param_3 == '\0') {
        local_8 = *piVar1 < local_c[3];
      }
      else {
        local_8 = *piVar1 <= local_c[3];
      }
      if (local_8 == false) {
        piVar3 = (int *)local_c[2];
      }
      else {
        piVar3 = (int *)*local_c;
      }
    } while (*(char *)((int)piVar3 + 0x2d) == '\0');
  }
  _param_3 = local_c;
  if (local_8 != false) {
    if (local_c == (int *)*piVar2) {
      local_8 = true;
      goto LAB_1000e513;
    }
    FUN_1000d3e8((int *)&param_3);
  }
  piVar2 = _param_3;
  if (*piVar1 <= _param_3[3]) {
    FUN_1000e059((int)this + 0xd,piVar1);
    operator_delete(param_2);
    *param_1 = piVar2;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_1000e513:
  puVar4 = (undefined4 *)FUN_1000e068(this,(undefined4 *)&param_3,local_8,local_c,param_2);
  *param_1 = *puVar4;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}



// Function: FUN_1000e56d at 1000e56d

undefined4 * __thiscall FUN_1000e56d(void *this,undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_1000e068(this,param_1,'\x01',*(undefined4 **)((int)this + 4),param_3);
    return param_1;
  }
  piVar1 = *(int **)((int)this + 4);
  piVar5 = param_2;
  if (param_2 == (int *)*piVar1) {
    if (param_2[3] <= param_3[3]) goto LAB_1000e637;
    cVar4 = '\x01';
    goto LAB_1000e62a;
  }
  if (param_2 == piVar1) {
    param_2 = (int *)piVar1[2];
    if (param_3[3] <= param_2[3]) goto LAB_1000e637;
  }
  else {
    if (param_3[3] < param_2[3]) {
      param_3 = param_2;
      FUN_1000d3e8((int *)&param_3);
      if (piVar2[3] <= param_3[3]) goto LAB_1000e5f3;
      cVar4 = *(char *)(param_3[2] + 0x2d);
      param_2 = param_3;
    }
    else {
LAB_1000e5f3:
      if (piVar2[3] <= param_2[3]) {
LAB_1000e637:
        puVar3 = (undefined4 *)FUN_1000e4ae(this,&local_c,piVar2,'\0');
        *param_1 = *puVar3;
        return param_1;
      }
      param_3 = param_2;
      FUN_1000d3ad((int *)&param_3);
      if ((param_3 != *(int **)((int)this + 4)) && (param_3[3] <= piVar2[3])) goto LAB_1000e637;
      cVar4 = *(char *)(param_2[2] + 0x2d);
      piVar5 = param_3;
    }
    if (cVar4 == '\0') {
      cVar4 = '\x01';
      goto LAB_1000e62a;
    }
  }
  cVar4 = '\0';
  piVar5 = param_2;
LAB_1000e62a:
  FUN_1000e068(this,param_1,cVar4,piVar5,piVar2);
  return param_1;
}



// Function: FUN_1000e653 at 1000e653

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000e653(void *this,undefined4 *param_1,undefined4 *param_2)

{
  *(undefined4 *)this = *param_1;
  basic_string<>((void *)((int)this + 4),param_2);
  return (undefined4 *)this;
}



// Function: FUN_1000e684 at 1000e684

void __fastcall FUN_1000e684(void *param_1)

{
  FUN_1000e20d(param_1,*(int **)(*(int *)((int)param_1 + 4) + 4));
  *(int *)(*(int *)((int)param_1 + 4) + 4) = *(int *)((int)param_1 + 4);
  *(undefined4 *)*(undefined4 *)((int)param_1 + 4) = *(undefined4 *)((int)param_1 + 4);
  *(int *)(*(int *)((int)param_1 + 4) + 8) = *(int *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 8) = 0;
  return;
}



// Function: FUN_1000e6ab at 1000e6ab

void __thiscall FUN_1000e6ab(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  void *local_8;
  
  local_8 = this;
  if ((param_2 == (int *)**(int **)((int)this + 4)) && (param_3 == *(int **)((int)this + 4))) {
    FUN_1000e684(this);
    param_2 = (int *)**(undefined4 **)((int)this + 4);
  }
  else if (param_2 != param_3) {
    do {
      piVar1 = param_2;
      FUN_1000d3ad((int *)&param_2);
      FUN_1000e251(this,&local_8,piVar1);
    } while (param_2 != param_3);
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_1000e6fe at 1000e6fe

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000e6fe(void *this,undefined4 *param_1)

{
  FUN_1000e653(this,param_1,param_1 + 1);
  return this;
}



// Function: FUN_1000e72c at 1000e72c

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000e72c(int param_1,int param_2)

{
  int *piVar1;
  HRESULT HVar2;
  int iVar3;
  undefined4 local_34 [4];
  int local_24;
  int *local_20;
  int *local_1c;
  int *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0x1000e738;
  FUN_10001c46(local_34);
  local_8 = 0;
  FUN_100045f1(local_34,0);
  local_18[0] = (int *)0x0;
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 3;
  HVar2 = CoCreateInstance((IID *)&DAT_1001d8f0,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_1001d9b4,local_18);
  FUN_100045f1(local_34,HVar2);
  piVar1 = local_18[0];
  local_20 = (int *)0x0;
  local_8._0_1_ = 5;
  if (param_1 == 0) {
    param_1 = 0;
  }
  else {
    param_1 = Ordinal_2(param_1);
    if (param_1 == 0) goto LAB_1000e7d9;
  }
  local_8._0_1_ = 6;
  iVar3 = (**(code **)(*piVar1 + 0x50))(piVar1,param_1,&local_20);
  FUN_100045f1(local_34,iVar3);
  local_8._0_1_ = 5;
  Ordinal_6(param_1);
  piVar1 = local_20;
  if (param_2 == 0) {
    local_24 = 0;
  }
  else {
    local_24 = Ordinal_2(param_2);
    if (local_24 == 0) goto LAB_1000e7d9;
  }
  local_8._0_1_ = 7;
  iVar3 = (**(code **)(*piVar1 + 0x58))(piVar1,local_24,0xffffffff);
  FUN_100045f1(local_34,iVar3);
  local_8 = CONCAT31(local_8._1_3_,5);
  Ordinal_6(local_24);
  piVar1 = local_20;
  if (local_20 != (int *)0x0) {
    local_20 = (int *)0x0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = local_18[0];
  local_1c = (int *)0x0;
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 9;
  if (param_2 == 0) {
    param_2 = 0;
  }
  else {
    param_2 = Ordinal_2(param_2);
    if (param_2 == 0) {
LAB_1000e7d9:
                    /* WARNING: Subroutine does not return */
      FUN_100010d9(-0x7ff8fff2);
    }
  }
  local_8._0_1_ = 10;
  iVar3 = (**(code **)(*piVar1 + 0x50))(piVar1,param_2,&local_1c);
  FUN_100045f1(local_34,iVar3);
  local_8 = CONCAT31(local_8._1_3_,9);
  Ordinal_6(param_2);
  iVar3 = (**(code **)(*local_1c + 0x3c))(local_1c,0);
  FUN_100045f1(local_34,iVar3);
  piVar1 = local_1c;
  if (local_1c != (int *)0x0) {
    local_1c = (int *)0x0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = local_18[0];
  if (local_18[0] != (int *)0x0) {
    local_18[0] = (int *)0x0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 5;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  local_8._0_1_ = 3;
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_18[0] != (int *)0x0) {
    (**(code **)(*local_18[0] + 8))(local_18[0]);
  }
  return;
}



// Function: Catch@1000e8f0 at 1000e8f0

undefined4 Catch_1000e8f0(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000e8e4;
}



// Function: FUN_1000e8fa at 1000e8fa

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000e8fa(void *this,int *param_1,FILE *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  size_t sVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 ***pppuVar7;
  undefined4 **ppuVar8;
  int iVar9;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *extraout_ECX_06;
  int *extraout_ECX_07;
  int *piVar10;
  int *extraout_ECX_08;
  int *extraout_ECX_09;
  int *extraout_ECX_10;
  uint uVar11;
  uint local_170;
  undefined4 uStack_16c;
  undefined4 uStack_168;
  uint local_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  int local_150;
  FILE *local_14c;
  int *local_148;
  int local_144;
  int *local_140;
  int local_13c;
  int local_138;
  int local_134;
  undefined4 local_130 [3];
  int local_124;
  int local_120;
  int *local_11c;
  int *local_118;
  int *local_114;
  undefined4 local_110;
  char local_109;
  int local_108;
  int local_104;
  int *local_100;
  int *local_fc;
  int *local_f8;
  undefined1 local_f4 [28];
  undefined1 local_d8 [28];
  undefined1 local_bc [28];
  undefined2 local_a0 [8];
  undefined4 local_90;
  uint local_8c;
  wchar_t local_84 [8];
  undefined4 local_74;
  uint local_70;
  undefined4 **local_68 [5];
  uint local_54;
  undefined4 **local_4c [5];
  uint local_38;
  undefined4 **local_30 [4];
  undefined4 local_20;
  uint local_1c;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x180;
  local_8 = 0x1000e909;
  local_148 = param_1;
  local_14c = param_2;
  FUN_10001c2c(local_130);
  local_114 = (int *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  FUN_10003c48(local_68,L"/user_manager/users");
  local_8._0_1_ = 3;
  FUN_100147e9(&local_110);
  local_8._0_1_ = 4;
  local_140 = (int *)((int)this + 0xc);
  FUN_10014818(local_140,local_68,(int *)&local_114);
  if (local_114 != (int *)0x0) {
    sVar4 = wcslen(L"./user");
    FID_conflict_assign(local_68,(undefined4 *)L"./user",sVar4);
    piVar10 = local_114;
    local_fc = (int *)0x0;
    local_8._0_1_ = 6;
    if (local_54 < 8) {
      local_68[0] = local_68;
    }
    if ((undefined4 ***)local_68[0] == (undefined4 ***)0x0) {
      local_108 = 0;
    }
    else {
      local_108 = Ordinal_2();
      if (local_108 == 0) goto LAB_1000ebd6;
    }
    local_8._0_1_ = 7;
    iVar5 = (**(code **)(*piVar10 + 0x90))(piVar10,local_108);
    FUN_100045f1(local_130,iVar5);
    local_8 = CONCAT31(local_8._1_3_,6);
    Ordinal_6(local_108);
    if (local_fc != (int *)0x0) {
      local_104 = 0;
      iVar5 = (**(code **)(*local_fc + 0x20))(local_fc);
      FUN_100045f1(local_130,iVar5);
      local_108 = 0;
      if (0 < local_104) {
        do {
          uVar11 = 7;
          local_f8 = (int *)0x0;
          local_8._0_1_ = 9;
          iVar5 = (**(code **)(*local_fc + 0x1c))(local_fc,local_108);
          FUN_100045f1(local_130,iVar5);
          if (-1 < local_124) {
            local_74 = 0;
            local_84[0] = L'\0';
            local_20 = 0;
            local_30[0] = (undefined4 **)((uint)local_30[0] & 0xffff0000);
            local_90 = 0;
            local_a0[0] = 0;
            local_8._0_1_ = 0xc;
            local_8c = uVar11;
            local_70 = uVar11;
            local_1c = uVar11;
            puVar6 = (undefined4 *)FUN_10003c48(local_f4,L"ID");
            local_8._0_1_ = 0xd;
            iVar5 = FUN_10014899((int *)&local_f8,puVar6,local_84);
            FUN_100045f1(local_130,iVar5);
            local_8._0_1_ = 0xc;
            FID_conflict__Tidy(local_f4,'\x01',0);
            puVar6 = (undefined4 *)FUN_10003c48(local_d8,L"group");
            local_8._0_1_ = 0xe;
            iVar5 = FUN_10014899((int *)&local_f8,puVar6,local_30);
            FUN_100045f1(local_130,iVar5);
            local_8._0_1_ = 0xc;
            FID_conflict__Tidy(local_d8,'\x01',0);
            puVar6 = (undefined4 *)FUN_10003c48(local_bc,L"groupID");
            local_8._0_1_ = 0xf;
            iVar5 = FUN_10014899((int *)&local_f8,puVar6,local_a0);
            FUN_100045f1(local_130,iVar5);
            local_8._0_1_ = 0xc;
            FID_conflict__Tidy(local_bc,'\x01',0);
            if (local_124 == 1) {
              piVar10 = (int *)*local_148;
              if (piVar10 != (int *)local_148[1]) {
                do {
                  if (piVar10[2] == 0) {
                    local_13c = 0;
                  }
                  else {
                    local_13c = Ordinal_2();
                    if (local_13c == 0) goto LAB_1000ebd6;
                  }
                  local_8._0_1_ = 0x10;
                  pppuVar7 = (undefined4 ***)local_30[0];
                  if (local_1c < 8) {
                    pppuVar7 = local_30;
                  }
                  if (pppuVar7 == (undefined4 ***)0x0) {
                    local_134 = 0;
                  }
                  else {
                    local_134 = Ordinal_2();
                    if (local_134 == 0) goto LAB_1000ebd6;
                  }
                  local_8._0_1_ = 0x11;
                  local_109 = ATL::CComBSTR::operator==
                                        ((CComBSTR *)&local_134,(CComBSTR *)&local_13c);
                  local_8._0_1_ = 0x10;
                  Ordinal_6();
                  local_8._0_1_ = 0xc;
                  Ordinal_6(local_13c);
                  if (local_109 != '\0') {
                    if (*piVar10 == 0) {
                      local_138 = 0;
                    }
                    else {
                      local_138 = Ordinal_2();
                      if (local_138 == 0) goto LAB_1000ebd6;
                    }
                    local_8._0_1_ = 0x12;
                    local_150 = FUN_10001718(&local_138);
                    local_8._0_1_ = 0xc;
                    Ordinal_6();
                    break;
                  }
                  piVar10 = piVar10 + 3;
                } while (piVar10 != (int *)local_148[1]);
              }
              local_100 = (int *)0x0;
              local_8._0_1_ = 0x14;
              iVar5 = (**(code **)*local_f8)(local_f8,&DAT_1001da9c);
              FUN_100045f1(local_130,iVar5);
              local_170 = local_170 & 0xffff0000;
              FUN_10001965(&local_170,local_150);
              uVar2 = uStack_168;
              uVar1 = uStack_16c;
              uVar11 = local_170;
              local_8._0_1_ = 0x15;
              local_11c = local_100;
              local_144 = Ordinal_2(L"groupID");
              if (local_144 == 0) goto LAB_1000ebd6;
              local_8._0_1_ = 0x16;
              iVar5 = (**(code **)(*local_11c + 0xb4))(local_11c,local_144,uVar11,uVar1,uVar2);
              FUN_100045f1(local_130,iVar5);
              local_8._0_1_ = 0x15;
              Ordinal_6(local_144);
              local_8._0_1_ = 0x14;
              Ordinal_9(&local_170);
              iVar5 = FUN_10001fa0(local_84);
              if (iVar5 == 0) {
                ppuVar8 = (undefined4 **)DAT_1002a524;
                if (DAT_1002a538 < 8) {
                  ppuVar8 = &DAT_1002a524;
                }
                local_160 = local_160 & 0xffff0000;
                FUN_10001965(&local_160,(int)ppuVar8);
                uVar2 = uStack_158;
                uVar1 = uStack_15c;
                uVar11 = local_160;
                local_8._0_1_ = 0x17;
                local_11c = local_100;
                local_120 = Ordinal_2();
                if (local_120 == 0) goto LAB_1000ebd6;
                local_8._0_1_ = 0x18;
                iVar5 = (**(code **)(*local_11c + 0xb4))(local_11c,local_120,uVar11,uVar1,uVar2);
                FUN_100045f1(local_130,iVar5);
                local_8._0_1_ = 0x17;
                Ordinal_6(local_120);
                local_8._0_1_ = 0x14;
                Ordinal_9(&local_160);
              }
              piVar10 = local_100;
              if (local_100 != (int *)0x0) {
                local_100 = (int *)0x0;
                (**(code **)(*piVar10 + 8))();
              }
              local_8._0_1_ = 0xc;
              if (local_100 != (int *)0x0) {
                (**(code **)(*local_100 + 8))();
              }
            }
            piVar10 = local_f8;
            if (local_f8 != (int *)0x0) {
              local_f8 = (int *)0x0;
              (**(code **)(*piVar10 + 8))();
            }
            local_8._0_1_ = 0xb;
            FID_conflict__Tidy(local_a0,'\x01',0);
            local_8._0_1_ = 10;
            FID_conflict__Tidy(local_30,'\x01',0);
            local_8._0_1_ = 9;
            FID_conflict__Tidy(local_84,'\x01',0);
          }
          local_8 = CONCAT31(local_8._1_3_,6);
          if (local_f8 != (int *)0x0) {
            (**(code **)(*local_f8 + 8))();
          }
          local_108 = local_108 + 1;
        } while (local_108 < local_104);
      }
      piVar10 = local_fc;
      if (local_fc != (int *)0x0) {
        local_fc = (int *)0x0;
        (**(code **)(*piVar10 + 8))();
      }
    }
    piVar10 = local_114;
    if (local_114 != (int *)0x0) {
      local_114 = (int *)0x0;
      (**(code **)(*piVar10 + 8))();
    }
    local_8._0_1_ = 4;
    if (local_fc != (int *)0x0) {
      (**(code **)(*local_fc + 8))();
    }
  }
  local_118 = (int *)0x0;
  local_8._0_1_ = 0x1d;
  FUN_10003c48(local_4c,L"/user_manager/groups");
  local_8._0_1_ = 0x1e;
  FUN_10014818(local_140,local_4c,(int *)&local_118);
  piVar10 = extraout_ECX;
  if (local_118 != (int *)0x0) {
    sVar4 = wcslen(L"./group");
    FID_conflict_assign(local_4c,(undefined4 *)L"./group",sVar4);
    piVar10 = local_118;
    local_100 = (int *)0x0;
    local_8._0_1_ = 0x20;
    if (local_38 < 8) {
      local_4c[0] = local_4c;
    }
    if ((undefined4 ***)local_4c[0] == (undefined4 ***)0x0) {
      local_104 = 0;
    }
    else {
      local_104 = Ordinal_2();
      if (local_104 == 0) {
LAB_1000ebd6:
                    /* WARNING: Subroutine does not return */
        FUN_100010d9(-0x7ff8fff2);
      }
    }
    local_8._0_1_ = 0x21;
    iVar5 = (**(code **)(*piVar10 + 0x90))(piVar10,local_104);
    FUN_100045f1(local_130,iVar5);
    local_8 = CONCAT31(local_8._1_3_,0x20);
    Ordinal_6(local_104);
    piVar10 = extraout_ECX_00;
    if (local_100 != (int *)0x0) {
      local_104 = 0;
      iVar5 = (**(code **)(*local_100 + 0x20))(local_100);
      FUN_100045f1(local_130,iVar5);
      iVar5 = 0;
      piVar10 = extraout_ECX_01;
      if (0 < local_104) {
        do {
          local_f8 = (int *)0x0;
          local_8._0_1_ = 0x23;
          iVar9 = (**(code **)(*local_100 + 0x1c))(local_100,iVar5);
          FUN_100045f1(local_130,iVar9);
          piVar10 = extraout_ECX_02;
          if (-1 < local_124) {
            local_1c = 7;
            local_20 = 0;
            local_30[0] = (undefined4 **)((uint)local_30[0] & 0xffff0000);
            local_8._0_1_ = 0x24;
            puVar6 = (undefined4 *)FUN_10003c48(local_bc,L"ID");
            local_8._0_1_ = 0x25;
            iVar9 = FUN_10014899((int *)&local_f8,puVar6,local_30);
            FUN_100045f1(local_130,iVar9);
            local_8._0_1_ = 0x24;
            FID_conflict__Tidy(local_bc,'\x01',0);
            local_fc = (int *)0x0;
            local_8._0_1_ = 0x27;
            iVar9 = (**(code **)*local_f8)(local_f8,&DAT_1001da9c);
            FUN_100045f1(local_130,iVar9);
            iVar9 = FUN_10001fa0((wchar_t *)local_30);
            if (iVar9 == 0) {
              ppuVar8 = (undefined4 **)DAT_1002a474;
              if (DAT_1002a488 < 8) {
                ppuVar8 = &DAT_1002a474;
              }
              local_160 = local_160 & 0xffff0000;
              FUN_10001965(&local_160,(int)ppuVar8);
              uVar11 = local_160;
              local_8._0_1_ = 0x28;
              local_11c = local_fc;
              local_120 = Ordinal_2();
              if (local_120 == 0) goto LAB_1000ebd6;
              local_8._0_1_ = 0x29;
              iVar5 = (**(code **)(*local_11c + 0xb4))
                                (local_11c,local_120,uVar11,uStack_15c,uStack_158);
              FUN_100045f1(local_130,iVar5);
              local_8._0_1_ = 0x28;
              Ordinal_6(local_120);
              local_8 = CONCAT31(local_8._1_3_,0x27);
              Ordinal_9(&local_160);
              piVar10 = local_fc;
              if (local_fc != (int *)0x0) {
                local_fc = (int *)0x0;
                (**(code **)(*piVar10 + 8))();
              }
              local_8._0_1_ = 0x24;
              if (local_fc != (int *)0x0) {
                (**(code **)(*local_fc + 8))();
              }
              local_8._0_1_ = 0x23;
              FID_conflict__Tidy(local_30,'\x01',0);
              local_8 = CONCAT31(local_8._1_3_,0x20);
              piVar10 = extraout_ECX_06;
              if (local_f8 != (int *)0x0) {
                (**(code **)(*local_f8 + 8))();
                piVar10 = extraout_ECX_07;
              }
              break;
            }
            local_8._0_1_ = 0x24;
            if (local_fc != (int *)0x0) {
              (**(code **)(*local_fc + 8))();
            }
            local_8._0_1_ = 0x23;
            FID_conflict__Tidy(local_30,'\x01',0);
            piVar10 = extraout_ECX_03;
          }
          piVar3 = local_f8;
          if (local_f8 != (int *)0x0) {
            local_f8 = (int *)0x0;
            (**(code **)(*piVar3 + 8))();
            piVar10 = extraout_ECX_04;
          }
          local_8 = CONCAT31(local_8._1_3_,0x20);
          if (local_f8 != (int *)0x0) {
            (**(code **)(*local_f8 + 8))();
            piVar10 = extraout_ECX_05;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < local_104);
      }
    }
    piVar3 = local_100;
    if (local_100 != (int *)0x0) {
      local_100 = (int *)0x0;
      (**(code **)(*piVar3 + 8))();
      piVar10 = extraout_ECX_08;
    }
    local_8._0_1_ = 0x1e;
    if (local_100 != (int *)0x0) {
      (**(code **)(*local_100 + 8))();
      piVar10 = extraout_ECX_09;
    }
  }
  piVar3 = local_118;
  if (local_118 != (int *)0x0) {
    local_118 = (int *)0x0;
    (**(code **)(*piVar3 + 8))();
    piVar10 = extraout_ECX_10;
  }
  local_11c = (int *)&stack0xfffffe5c;
  FUN_1000d6aa(&stack0xfffffe5c,local_140);
  local_8._0_1_ = 0x1e;
  FUN_10014502(local_14c,piVar10);
  local_8._0_1_ = 0x1d;
  FID_conflict__Tidy(local_4c,'\x01',0);
  local_8._0_1_ = 4;
  if (local_118 != (int *)0x0) {
    (**(code **)(*local_118 + 8))();
  }
  local_8._0_1_ = 3;
  FUN_100147f2(&local_110);
  local_8._0_1_ = 2;
  FID_conflict__Tidy(local_68,'\x01',0);
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_114 != (int *)0x0) {
    (**(code **)(*local_114 + 8))();
  }
  local_8 = 0xffffffff;
  FUN_10014f84();
  return;
}



// Function: FUN_1000f32b at 1000f32b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_1000f32b(void *param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = &LAB_100181a1;
  if (param_1 != (void *)0x0) {
    puVar1 = (undefined1 *)FUN_1000e6fe(param_1,param_2);
  }
  return puVar1;
}



// Function: FUN_1000f359 at 1000f359

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000f359(void *param_1)

{
  undefined4 local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  local_14 = param_1;
  FUN_1000e6ab(param_1,&local_18,(int *)**(int **)((int)param_1 + 4),*(int **)((int)param_1 + 4));
  local_8 = 0xffffffff;
  operator_delete(*(void **)((int)param_1 + 4));
  return;
}



// Function: FUN_1000f393 at 1000f393

void __cdecl FUN_1000f393(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  FUN_1000f32b(param_2,param_3);
  return;
}



// Function: FUN_1000f3a6 at 1000f3a6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000f3a6(void *param_1)

{
  FUN_1000f359(param_1);
  return;
}



// Function: FUN_1000f3c4 at 1000f3c4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000f3c4(int param_1)

{
  int *piVar1;
  
  FUN_1000df2a((_Container_base0 *)(param_1 + 0x48));
  FUN_1000df2a((_Container_base0 *)(param_1 + 0x38));
  FUN_10004315((_Container_base0 *)(param_1 + 0x28));
  FUN_1000f359((void *)(param_1 + 0x18));
  piVar1 = *(int **)(param_1 + 0x14);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x10);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000f463 at 1000f463

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000f463(int param_1)

{
  int aiStack_30 [5];
  undefined1 *local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000f46f;
  local_1c = (undefined1 *)aiStack_30;
  aiStack_30[0] = param_1;
  local_18 = param_1;
  FUN_1000dc80(param_1);
  return local_18;
}



// Function: FUN_1000f48f at 1000f48f

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_1000f48f(void *this,undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_1000daf3((int)this);
  FUN_1000f393((int)this + 0xd,(void *)(iVar1 + 0xc),param_1);
  return iVar1;
}



// Function: Catch@1000f4cc at 1000f4cc

void Catch_1000f4cc(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000f4df at 1000f4df

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000f4df(int param_1)

{
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  FUN_1000f463(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  return param_1;
}



// Function: FUN_1000f557 at 1000f557

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000f557(void *this,int *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 local_54;
  int local_50;
  undefined1 local_4c [28];
  undefined2 local_30 [8];
  undefined4 local_20;
  undefined4 local_1c;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x44;
  local_8 = 0x1000f563;
  piVar1 = FUN_1000d6da(this,param_1);
  if ((piVar1 == *(int **)((int)this + 4)) || (*param_1 < piVar1[3])) {
    local_20 = 0;
    local_1c = 7;
    local_30[0] = 0;
    local_8 = 0;
    local_50 = *param_1;
    basic_string<>(local_4c,(undefined4 *)local_30);
    local_8._0_1_ = 3;
    piVar2 = (int *)FUN_1000f48f(this,&local_50);
    FUN_1000e56d(this,&local_54,piVar1,piVar2);
    local_8 = (uint)local_8._1_3_ << 8;
    FID_conflict__Tidy(local_4c,'\x01',0);
    local_8 = 0xffffffff;
    FID_conflict__Tidy(local_30,'\x01',0);
  }
  FUN_10014f84();
  return;
}



// Function: FUN_1000f5eb at 1000f5eb

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 __cdecl FUN_1000f5eb(_Container_base0 *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 local_2c [4];
  int *local_1c;
  undefined1 local_15;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x1000f5f7;
  local_15 = 1;
  FUN_10001c46(local_2c);
  local_8 = 1;
  local_1c = (int *)0x0;
  iVar2 = FUN_10008864(&local_1c);
  FUN_100045f1(local_2c,iVar2);
  piVar1 = local_1c;
  (**(code **)(*local_1c + 4))(local_1c);
  FUN_10007696(piVar1 + 2);
  FUN_10007bd2(piVar1 + 2,param_1);
  iVar2 = (**(code **)*piVar1)(piVar1,&DAT_1001d9e0,param_2);
  FUN_100045f1(local_2c,iVar2);
  return local_15;
}



// Function: Catch@1000f663 at 1000f663

undefined4 Catch_1000f663(void)

{
  int unaff_EBP;
  
  *(undefined1 *)(unaff_EBP + -0x11) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000f656;
}



// Function: FUN_1000f671 at 1000f671

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000f671(void *this,void *param_1,void *param_2,undefined4 *param_3)

{
  char cVar1;
  short *psVar2;
  int *piVar3;
  void *pvVar4;
  int iVar5;
  undefined4 *puVar6;
  wchar_t *pwVar7;
  void *this_00;
  wchar_t *pwVar8;
  undefined4 local_90 [4];
  void *local_80;
  undefined4 *local_7c;
  wchar_t *local_78;
  wchar_t *local_74;
  undefined4 local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  int local_58;
  int *local_54;
  int *local_50;
  int local_4c;
  wchar_t *local_48;
  uint local_44;
  int local_40;
  void *local_3c;
  wchar_t *local_38;
  undefined4 local_34 [11];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x80;
  local_8 = 0x1000f680;
  local_80 = param_2;
  local_7c = param_3;
  local_3c = this;
  FUN_10001c46(local_90);
  local_8 = 0;
  FUN_100045f1(local_90,0);
  local_8._0_1_ = 1;
  if (*(int *)((int)param_1 + 0x10) == 0) {
    FUN_100045f1(local_90,-0x7fffbffb);
  }
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_8._0_1_ = 2;
  FUN_10005665(&local_68,&local_40,(undefined4 *)0x0,(undefined4 *)0x0);
  local_78 = (wchar_t *)0x0;
  local_74 = (wchar_t *)0x0;
  local_70 = 0;
  local_48 = (wchar_t *)0x0;
  local_58 = 0;
  local_50 = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,5);
  (**(code **)(**(int **)((int)this + 0x14) + 0x48))(*(int **)((int)this + 0x14),&local_50);
  (**(code **)(*local_50 + 0x20))(local_50,&local_58);
  for (local_4c = 1; local_4c <= local_58; local_4c = local_4c + 1) {
    (**(code **)(*local_50 + 0x1c))(local_50,local_4c,&local_38);
    if (local_38 == (wchar_t *)0x0) {
      local_40 = 0;
    }
    else {
      local_40 = Ordinal_2(local_38);
      if (local_40 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_100010d9(-0x7ff8fff2);
      }
    }
    local_8._0_1_ = 6;
    FUN_10003c48(local_34,local_38);
    local_8._0_1_ = 7;
    FUN_100088e4(&local_78,local_34);
    local_8._0_1_ = 6;
    FID_conflict__Tidy(local_34,'\x01',0);
    local_8 = CONCAT31(local_8._1_3_,5);
    Ordinal_6(local_40);
  }
  local_44 = *(uint *)((int)param_1 + 0x10);
LAB_1000f7a8:
  local_44 = local_44 - 1;
  if (-1 < (int)local_44) {
    local_40 = *(int *)((int)param_1 + 0x10) - local_44;
    psVar2 = (short *)FUN_1000d685(param_1,local_44);
    if ((*psVar2 == 0x31) &&
       (iVar5 = *(int *)((int)this + 0x1c),
       piVar3 = (int *)FUN_1000dd7b((void *)((int)this + 0x18),&local_38,&local_40),
       pwVar7 = local_78, *piVar3 != iVar5)) {
      for (; local_48 = pwVar7, pwVar7 != local_74; pwVar7 = pwVar7 + 0xe) {
        pwVar8 = pwVar7;
        if (7 < *(uint *)(pwVar7 + 10)) {
          pwVar8 = *(wchar_t **)pwVar7;
        }
        pvVar4 = (void *)FUN_1000f557((void *)((int)local_3c + 0x18),&local_40);
        iVar5 = FUN_1000217f(pvVar4,pwVar8);
        if (iVar5 == 0) {
          puVar6 = (undefined4 *)FUN_1000f557((void *)((int)local_3c + 0x18),&local_40);
          FUN_100088e4(&local_68,puVar6);
          this = local_3c;
          break;
        }
        this = local_3c;
      }
    }
    goto LAB_1000f7a8;
  }
  iVar5 = FUN_1000215e(local_80,(ushort *)&DAT_1002a420);
  pwVar7 = *(wchar_t **)((int)param_1 + 0x10);
  if (iVar5 == 0) {
    pwVar7 = (wchar_t *)((int)pwVar7 - 5);
  }
  if (pwVar7 < *(wchar_t **)((int)this + 0x20)) {
LAB_1000f85c:
    local_38 = (wchar_t *)((int)pwVar7 + 1);
    pwVar8 = local_78;
    if (local_38 <= *(wchar_t **)((int)this + 0x20)) {
      for (; pvVar4 = local_3c, pwVar7 = local_38, local_48 = pwVar8, pwVar8 != local_74;
          pwVar8 = pwVar8 + 0xe) {
        pwVar7 = pwVar8;
        if (7 < *(uint *)(pwVar8 + 10)) {
          pwVar7 = *(wchar_t **)pwVar8;
        }
        this_00 = (void *)FUN_1000f557((void *)((int)local_3c + 0x18),(int *)&local_38);
        iVar5 = FUN_1000217f(this_00,pwVar7);
        this = pvVar4;
        if (iVar5 == 0) {
          puVar6 = (undefined4 *)FUN_1000f557((void *)((int)pvVar4 + 0x18),(int *)&local_38);
          FUN_100088e4(&local_68,puVar6);
          pwVar7 = local_38;
          break;
        }
      }
      goto LAB_1000f85c;
    }
  }
  local_54 = (int *)0x0;
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 9;
  cVar1 = FUN_1000f5eb((_Container_base0 *)&local_68,&local_54);
  FUN_100045f1(local_90,(-(uint)(cVar1 != '\0') & 0x7fffbffb) + 0x80004005);
  *local_7c = local_54;
  local_8._0_1_ = 5;
  if (local_54 != (int *)0x0) {
    (**(code **)(*local_54 + 8))(local_54);
  }
  local_8._0_1_ = 3;
  if (local_50 != (int *)0x0) {
    (**(code **)(*local_50 + 8))(local_50);
  }
  local_8._0_1_ = 2;
  FUN_10004315((_Container_base0 *)&local_78);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10004315((_Container_base0 *)&local_68);
  local_8 = 0xffffffff;
  FUN_10014f93();
  return;
}



// Function: Catch@1000f94e at 1000f94e

undefined4 Catch_1000f94e(void)

{
  int unaff_EBP;
  
  FUN_100045f1((void *)(unaff_EBP + -0x8c),-0x7fffbffb);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000f942;
}



// Function: FUN_1000f968 at 1000f968

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000f968(void *this,ushort *param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  int local_a0;
  int local_9c;
  int local_98;
  int *local_94;
  int *local_90;
  int local_8c;
  int local_88;
  int *local_84;
  int *local_80;
  int *local_7c;
  int local_78;
  undefined4 local_74;
  int *local_70;
  undefined1 local_6c [28];
  undefined2 local_50 [8];
  undefined4 local_40;
  undefined4 local_3c;
  undefined2 local_34 [8];
  undefined4 local_24;
  undefined4 local_20;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xa8;
  local_b0 = 0;
  local_ac = 0;
  local_a8 = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_10005665(&local_b0,&local_98,(undefined4 *)0x0,(undefined4 *)0x0);
  FUN_100147e9(&local_74);
  local_7c = (int *)0x0;
  local_8._0_1_ = 4;
  FUN_10014818((int *)((int)this + 0xc),(undefined4 *)&DAT_1002a3cc,(int *)&local_7c);
  piVar1 = local_7c;
  if (local_7c != (int *)0x0) {
    local_70 = (int *)0x0;
    local_8._0_1_ = 6;
    puVar2 = DAT_1002a3e8;
    if (DAT_1002a3fc < 8) {
      puVar2 = &DAT_1002a3e8;
    }
    if (puVar2 == (undefined4 *)0x0) {
      local_9c = 0;
    }
    else {
      local_9c = Ordinal_2(puVar2);
      if (local_9c == 0) {
LAB_1000fb2b:
                    /* WARNING: Subroutine does not return */
        FUN_100010d9(-0x7ff8fff2);
      }
    }
    local_8._0_1_ = 7;
    (**(code **)(*piVar1 + 0x90))(piVar1,local_9c,&local_70);
    local_8 = CONCAT31(local_8._1_3_,6);
    Ordinal_6(local_9c);
    if (local_70 != (int *)0x0) {
      local_98 = 0;
      (**(code **)(*local_70 + 0x20))(local_70,&local_98);
      for (local_88 = 0; local_88 < local_98; local_88 = local_88 + 1) {
        local_80 = (int *)0x0;
        local_8._1_3_ = (uint3)((uint)local_8 >> 8);
        local_8._0_1_ = 9;
        iVar3 = (**(code **)(*local_70 + 0x1c))(local_70,local_88,&local_80);
        if (-1 < iVar3) {
          local_3c = 7;
          local_40 = 0;
          local_50[0] = 0;
          local_8._0_1_ = 10;
          FUN_10014899((int *)&local_80,(undefined4 *)&DAT_1002a458,local_50);
          iVar3 = FUN_1000215e(local_50,param_1);
          piVar1 = local_80;
          if (iVar3 == 0) {
            local_84 = (int *)0x0;
            local_8._0_1_ = 0xc;
            puVar2 = DAT_1002a43c;
            if (DAT_1002a450 < 8) {
              puVar2 = &DAT_1002a43c;
            }
            if (puVar2 == (undefined4 *)0x0) {
              local_a0 = 0;
            }
            else {
              local_a0 = Ordinal_2(puVar2);
              if (local_a0 == 0) goto LAB_1000fb2b;
            }
            local_8._0_1_ = 0xd;
            (**(code **)(*piVar1 + 0x90))(piVar1,local_a0,&local_84);
            local_8._0_1_ = 0xc;
            Ordinal_6(local_a0);
            if (local_84 != (int *)0x0) {
              local_8c = 0;
              (**(code **)(*local_84 + 0x20))(local_84,&local_8c);
              if (local_8c != 0) {
                for (local_78 = 0; local_78 < local_8c; local_78 = local_78 + 1) {
                  local_94 = (int *)0x0;
                  local_8._0_1_ = 0xf;
                  (**(code **)(*local_84 + 0x1c))(local_84,local_78,&local_94);
                  local_20 = 7;
                  local_24 = 0;
                  local_34[0] = 0;
                  local_8._0_1_ = 0x10;
                  puVar2 = (undefined4 *)FUN_10003c48(local_6c,L"ID");
                  local_8._0_1_ = 0x11;
                  FUN_10014899((int *)&local_94,puVar2,local_34);
                  local_8._0_1_ = 0x10;
                  FID_conflict__Tidy(local_6c,'\x01',0);
                  FUN_100088e4(&local_b0,(undefined4 *)local_34);
                  local_8._0_1_ = 0xf;
                  FID_conflict__Tidy(local_34,'\x01',0);
                  local_8._0_1_ = 0xc;
                  if (local_94 != (int *)0x0) {
                    (**(code **)(*local_94 + 8))(local_94);
                  }
                }
                local_90 = (int *)0x0;
                local_8._0_1_ = 0x14;
                FUN_1000f5eb((_Container_base0 *)&local_b0,&local_90);
                *param_2 = local_90;
                local_8._0_1_ = 0xc;
                if (local_90 != (int *)0x0) {
                  (**(code **)(*local_90 + 8))(local_90);
                }
              }
            }
            local_8._0_1_ = 10;
            if (local_84 != (int *)0x0) {
              (**(code **)(*local_84 + 8))(local_84);
            }
          }
          local_8._0_1_ = 9;
          FID_conflict__Tidy(local_50,'\x01',0);
        }
        local_8 = CONCAT31(local_8._1_3_,6);
        if (local_80 != (int *)0x0) {
          (**(code **)(*local_80 + 8))(local_80);
        }
      }
    }
    local_8._1_3_ = (uint3)((uint)local_8 >> 8);
    local_8._0_1_ = 4;
    if (local_70 != (int *)0x0) {
      (**(code **)(*local_70 + 8))(local_70);
    }
  }
  local_8._0_1_ = 2;
  if (local_7c != (int *)0x0) {
    (**(code **)(*local_7c + 8))(local_7c);
  }
  local_8._0_1_ = 1;
  FUN_100147f2(&local_74);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10004315((_Container_base0 *)&local_b0);
  local_8 = 0xffffffff;
  FUN_10014f93();
  return;
}



// Function: Catch@1000fd29 at 1000fd29

undefined4 Catch_1000fd29(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000fd21;
}



// Function: FUN_1000fd33 at 1000fd33

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000fd33(void *this,FILE *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *piVar7;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *piVar8;
  uint local_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 local_ac;
  undefined4 uStack_a8;
  undefined4 local_a4;
  undefined4 uStack_a0;
  FILE *local_9c;
  int local_98;
  int local_94;
  void *local_90;
  int local_8c;
  int local_88;
  undefined1 *local_84;
  int local_80;
  int *local_7c;
  undefined4 local_78;
  int local_74;
  int *local_70;
  int *local_6c;
  int local_68;
  int *local_64;
  int *local_60;
  int *local_5c;
  int *local_58;
  int *local_54;
  undefined2 local_50 [8];
  undefined4 local_40;
  undefined4 local_3c;
  undefined2 local_34 [8];
  undefined4 local_24;
  undefined4 local_20;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xcc;
  local_9c = param_1;
  local_8 = 0;
  local_90 = this;
  FUN_100147e9(&local_78);
  local_70 = (int *)0x0;
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_8._0_1_ = 3;
  FUN_10014818((int *)((int)this + 0xc),(undefined4 *)&DAT_1002a3cc,(int *)&local_70);
  piVar8 = local_70;
  piVar7 = extraout_ECX;
  if (local_70 != (int *)0x0) {
    local_7c = (int *)0x0;
    local_8._0_1_ = 5;
    puVar5 = DAT_1002a3e8;
    if (DAT_1002a3fc < 8) {
      puVar5 = &DAT_1002a3e8;
    }
    if (puVar5 == (undefined4 *)0x0) {
      local_60 = (int *)0x0;
    }
    else {
      local_60 = (int *)Ordinal_2();
      if (local_60 == (int *)0x0) {
LAB_10010120:
                    /* WARNING: Subroutine does not return */
        FUN_100010d9(-0x7ff8fff2);
      }
    }
    local_8._0_1_ = 6;
    (**(code **)(*piVar8 + 0x90))(piVar8,local_60);
    local_8 = CONCAT31(local_8._1_3_,5);
    Ordinal_6(local_60);
    piVar7 = extraout_ECX_00;
    if (local_7c != (int *)0x0) {
      local_94 = 0;
      (**(code **)(*local_7c + 0x20))(local_7c);
      piVar7 = extraout_ECX_01;
      for (local_68 = 0; local_68 < local_94; local_68 = local_68 + 1) {
        local_64 = (int *)0x0;
        local_8._1_3_ = (uint3)((uint)local_8 >> 8);
        local_8._0_1_ = 8;
        iVar6 = (**(code **)(*local_7c + 0x1c))(local_7c,local_68);
        piVar7 = extraout_ECX_02;
        if (-1 < iVar6) {
          local_20 = 7;
          local_24 = 0;
          local_34[0] = 0;
          local_3c = 7;
          local_40 = 0;
          local_50[0] = 0;
          local_8._0_1_ = 10;
          FUN_10014899((int *)&local_64,(undefined4 *)&DAT_1002a404,local_34);
          FUN_10014899((int *)&local_64,(undefined4 *)&DAT_1002a458,local_50);
          local_6c = (int *)0x0;
          local_8 = CONCAT31(local_8._1_3_,0xc);
          FUN_1000f671(this,local_34,local_50,&local_6c);
          piVar8 = local_6c;
          local_80 = 0;
          (**(code **)(*local_6c + 0x20))(local_6c);
          for (local_74 = 1; uVar3 = uStack_a0, uVar2 = uStack_a8, local_74 <= local_80;
              local_74 = local_74 + 1) {
            local_54 = (int *)0x0;
            local_5c = (int *)0x0;
            local_ac = CONCAT22(local_ac._2_2_,3);
            uVar4 = local_ac;
            local_a4 = 1;
            local_8._0_1_ = 0x11;
            piVar8 = *(int **)((int)local_90 + 0xc);
            local_60 = piVar8;
            local_98 = Ordinal_2(&DAT_1001dbfc);
            if (local_98 == 0) goto LAB_10010120;
            local_8._0_1_ = 0x12;
            local_88 = Ordinal_2();
            if (local_88 == 0) goto LAB_10010120;
            local_8._0_1_ = 0x13;
            (**(code **)(*piVar8 + 0xe0))(local_60,uVar4,uVar2,1,uVar3,local_88,local_98);
            local_8._0_1_ = 0x12;
            Ordinal_6(local_88);
            local_8._0_1_ = 0x11;
            Ordinal_6(local_98);
            local_8._0_1_ = 0x10;
            Ordinal_9(&local_ac);
            (**(code **)(*local_64 + 0x54))(local_64,local_54,&local_5c);
            local_58 = (int *)0x0;
            local_8._0_1_ = 0x15;
            (**(code **)*local_5c)(local_5c,&DAT_1001da9c,&local_58);
            (**(code **)(*local_6c + 0x1c))(local_6c,local_74,&local_84);
            local_bc = local_bc & 0xffff0000;
            FUN_10001965(&local_bc,(int)local_84);
            piVar8 = local_58;
            uVar3 = uStack_b4;
            uVar2 = uStack_b8;
            uVar1 = local_bc;
            local_8._0_1_ = 0x16;
            local_60 = local_58;
            local_8c = Ordinal_2(&DAT_1001dc44);
            if (local_8c == 0) goto LAB_10010120;
            local_8._0_1_ = 0x17;
            (**(code **)(*piVar8 + 0xb4))(local_60,local_8c,uVar1,uVar2,uVar3);
            local_8._0_1_ = 0x16;
            Ordinal_6(local_8c);
            local_8 = CONCAT31(local_8._1_3_,0x15);
            Ordinal_9(&local_bc);
            piVar8 = local_54;
            if (local_54 != (int *)0x0) {
              local_54 = (int *)0x0;
              (**(code **)(*piVar8 + 8))(piVar8);
              if (local_54 != (int *)0x0) {
                FUN_10001113((int *)&local_54,(int *)0x0);
              }
            }
            piVar8 = local_5c;
            if (local_5c != (int *)0x0) {
              local_5c = (int *)0x0;
              (**(code **)(*piVar8 + 8))(piVar8);
              if (local_5c != (int *)0x0) {
                FUN_10001113((int *)&local_5c,(int *)0x0);
              }
            }
            piVar8 = local_58;
            if (local_58 != (int *)0x0) {
              local_58 = (int *)0x0;
              (**(code **)(*piVar8 + 8))(piVar8);
              if (local_58 != (int *)0x0) {
                FUN_10001113((int *)&local_58,(int *)0x0);
              }
            }
            local_8._1_3_ = (uint3)((uint)local_8 >> 8);
            local_8._0_1_ = 0x10;
            if (local_58 != (int *)0x0) {
              (**(code **)(*local_58 + 8))(local_58);
            }
            local_8._0_1_ = 0xe;
            if (local_5c != (int *)0x0) {
              (**(code **)(*local_5c + 8))(local_5c);
            }
            local_8 = CONCAT31(local_8._1_3_,0xc);
            if (local_54 != (int *)0x0) {
              (**(code **)(*local_54 + 8))(local_54);
            }
            piVar8 = local_6c;
            this = local_90;
          }
          local_8._0_1_ = 10;
          (**(code **)(*piVar8 + 8))(piVar8);
          local_8._0_1_ = 9;
          FID_conflict__Tidy(local_50,'\x01',0);
          local_8._0_1_ = 8;
          FID_conflict__Tidy(local_34,'\x01',0);
          piVar7 = extraout_ECX_03;
        }
        local_8 = CONCAT31(local_8._1_3_,5);
        if (local_64 != (int *)0x0) {
          (**(code **)(*local_64 + 8))();
          piVar7 = extraout_ECX_04;
        }
      }
    }
    local_8._1_3_ = (uint3)((uint)local_8 >> 8);
    local_8._0_1_ = 3;
    if (local_7c != (int *)0x0) {
      (**(code **)(*local_7c + 8))();
      piVar7 = extraout_ECX_05;
    }
  }
  local_84 = &stack0xffffff10;
  FUN_1000d6aa(&stack0xffffff10,(int *)((int)this + 0xc));
  local_8._0_1_ = 3;
  FUN_10014502(local_9c,piVar7);
  local_8._0_1_ = 1;
  if (local_70 != (int *)0x0) {
    (**(code **)(*local_70 + 8))();
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_100147f2(&local_78);
  local_8 = 0xffffffff;
  FUN_10014f93();
  return;
}



// Function: Catch@100101d8 at 100101d8

undefined4 Catch_100101d8(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100101d0;
}



// Function: FUN_100101e2 at 100101e2

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_100101e2(void *param_1)

{
  int *piVar1;
  void *pvVar2;
  char cVar3;
  int *piVar4;
  LPCWSTR ****pppppWVar5;
  int iVar6;
  HRESULT HVar7;
  LPCWSTR *ppWVar8;
  undefined4 *puVar9;
  size_t sVar10;
  wchar_t *****_Str;
  wchar_t *pwVar11;
  undefined4 *****pppppuVar12;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  code *pcVar13;
  float10 fVar14;
  undefined4 uStack_714;
  int iStack_710;
  int local_6dc [4];
  int *local_6cc;
  int *local_6c8;
  undefined4 local_6c4;
  int local_6bc [3];
  int *local_6b0;
  DWORD local_6ac;
  undefined4 local_6a8;
  undefined4 local_6a4;
  undefined4 local_6a0;
  undefined4 local_69c;
  undefined4 local_698;
  undefined4 local_694;
  int local_690;
  undefined8 local_68c;
  int *local_684;
  int *local_680;
  int local_67c;
  int local_678;
  undefined1 *local_674;
  int *local_670;
  int local_66c;
  int local_668;
  int *local_664;
  int local_660;
  undefined1 *local_65c;
  int local_658;
  int *local_654;
  int *local_650;
  int *local_64c;
  int *local_648;
  int local_644;
  int *local_640;
  undefined4 local_63c [3];
  int local_630;
  wchar_t *local_62c;
  wchar_t *local_628;
  int *local_624;
  char local_61d;
  int *local_61c;
  void *local_618;
  int *local_614;
  int local_610;
  undefined2 local_60c [14];
  undefined1 local_5f0 [28];
  undefined2 local_5d4 [8];
  undefined4 local_5c4;
  undefined4 local_5c0;
  undefined2 local_5b8 [8];
  undefined4 local_5a8;
  undefined4 local_5a4;
  undefined2 local_59c [8];
  undefined4 local_58c;
  undefined4 local_588;
  undefined2 local_580 [8];
  undefined4 local_570;
  undefined4 local_56c;
  LPCWSTR ***local_564 [5];
  uint local_550;
  undefined4 ****local_548 [4];
  undefined4 local_538;
  uint local_534;
  undefined4 ****local_52c [4];
  undefined4 local_51c;
  uint local_518;
  wchar_t ****local_510 [4];
  undefined4 local_500;
  uint local_4fc;
  undefined2 local_4f4 [6];
  undefined4 local_4e8;
  undefined4 local_4e4;
  undefined4 local_4e0;
  undefined4 ****local_4d8 [4];
  undefined4 local_4c8;
  uint local_4c4;
  undefined4 ****local_4bc [4];
  undefined4 local_4ac;
  uint local_4a8;
  undefined2 local_4a0 [8];
  undefined4 local_490;
  undefined4 local_48c;
  undefined4 ****local_484 [4];
  undefined4 local_474;
  uint local_470;
  undefined4 ****local_468 [4];
  undefined4 local_458;
  uint local_454;
  undefined4 ****local_44c [5];
  uint local_438;
  BYTE local_430 [524];
  FILE local_224 [16];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x6cc;
  local_6cc = (int *)0x0;
  local_6c8 = (int *)0x0;
  local_6c4 = 0;
  local_6dc[0] = 0;
  local_6dc[1] = 0;
  local_6dc[2] = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_618 = param_1;
  FUN_10001c46(local_63c);
  local_8._0_1_ = 2;
  FUN_100045f1(local_63c,0);
  local_8._0_1_ = 3;
  (**(code **)(**(int **)((int)param_1 + 0x10) + 0x38))();
  (**(code **)(**(int **)((int)param_1 + 0x14) + 0x44))();
  piVar4 = FUN_10001ec7(&local_624,'\0');
  local_8._0_1_ = 4;
  FUN_100021a4((void *)((int)param_1 + 0xc),piVar4);
  local_8._0_1_ = 3;
  if (local_624 != (int *)0x0) {
    (**(code **)(*local_624 + 8))();
  }
  local_69c = 0;
  local_698 = 0;
  local_694 = 0;
  local_8._0_1_ = 6;
  basic_string<>(local_564,&DAT_1002a4ec);
  local_8._0_1_ = 7;
  pppppWVar5 = (LPCWSTR ****)local_564[0];
  if (local_550 < 8) {
    pppppWVar5 = local_564;
  }
  iVar6 = Open(&local_69c,(HKEY)0x80000002,(LPCWSTR)pppppWVar5,0x2001f);
  if (iVar6 == 0) {
    local_224[0]._ptr._0_2_ = 0;
    memset((void *)((int)&local_224[0]._ptr + 2),0,0x208);
    local_6ac = 0x20a;
    ppWVar8 = (LPCWSTR *)DAT_1002a540;
    if (DAT_1002a554 < 8) {
      ppWVar8 = &DAT_1002a540;
    }
    FUN_100013a4(&local_69c,(LPBYTE)local_224,(LPCWSTR)ppWVar8,&local_6ac);
    ATL::CRegKey::Close((CRegKey *)&local_69c);
    local_664 = (int *)0x0;
    local_8._0_1_ = 9;
    HVar7 = CoCreateInstance((IID *)&DAT_1001d8f0,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_1001d9b4,
                             &local_664);
    FUN_100045f1(local_63c,HVar7);
    piVar4 = local_664;
    local_680 = (int *)0x0;
    local_8._0_1_ = 0xb;
    local_610 = Ordinal_2();
    if (local_610 == 0) {
LAB_100103a9:
                    /* WARNING: Subroutine does not return */
      FUN_100010d9(-0x7ff8fff2);
    }
    local_8._0_1_ = 0xc;
    (**(code **)(*piVar4 + 0x50))();
    local_8._0_1_ = 0xb;
    Ordinal_6();
    piVar4 = extraout_ECX;
    if (local_680 == (int *)0x0) {
      local_6a8 = 0;
      local_6a4 = 0;
      local_6a0 = 0;
      local_8._0_1_ = 0xd;
      if (local_550 < 8) {
        local_564[0] = (LPCWSTR ***)local_564;
      }
      iStack_710 = 0x10010423;
      iVar6 = Open(&local_6a8,(HKEY)0x80000002,(LPCWSTR)local_564[0],0x2001f);
      if (iVar6 == 0) {
        local_430[0] = '\0';
        local_430[1] = '\0';
        iStack_710 = 0x10010446;
        memset(local_430 + 2,0,0x208);
        local_62c = (wchar_t *)0x20a;
        ppWVar8 = (LPCWSTR *)DAT_1002a55c;
        if (DAT_1002a570 < 8) {
          ppWVar8 = &DAT_1002a55c;
        }
        iStack_710 = 0x10010480;
        FUN_100013a4(&local_6a8,local_430,(LPCWSTR)ppWVar8,(LPDWORD)&local_62c);
        ATL::CRegKey::Close((CRegKey *)&local_6a8);
        pvVar2 = local_618;
        FUN_1000e72c((int)local_430,(int)local_224);
        local_624 = (int *)&stack0xfffff8fc;
        piVar4 = extraout_ECX_00;
        FUN_1000d6aa(&stack0xfffff8fc,(int *)((int)pvVar2 + 0xc));
        local_8._0_1_ = 0xd;
        FUN_100141fe((wchar_t *)local_224,piVar4);
        FUN_1000fd33(pvVar2,local_224);
      }
      local_8._0_1_ = 0xb;
      ATL::CRegKey::Close((CRegKey *)&local_6a8);
      piVar4 = extraout_ECX_01;
    }
    pvVar2 = local_618;
    local_62c = (wchar_t *)&stack0xfffff8fc;
    piVar1 = (int *)((int)local_618 + 0xc);
    FUN_1000d6aa(&stack0xfffff8fc,piVar1);
    local_8._0_1_ = 0xb;
    FUN_100141fe((wchar_t *)local_224,piVar4);
    if (*piVar1 != 0) {
      FUN_100147e9(&local_610);
      local_5c0 = 7;
      local_5c4 = 0;
      local_5d4[0] = 0;
      local_670 = (int *)0x0;
      local_8._0_1_ = 0x13;
      FUN_10003c48(local_44c,L"/user_manager");
      local_8._0_1_ = 0x14;
      FUN_10014818(piVar1,local_44c,(int *)&local_670);
      puVar9 = (undefined4 *)FUN_10003c48(local_4a0,L"INSITE");
      local_8._0_1_ = 0x15;
      iVar6 = FUN_10014899((int *)&local_670,puVar9,local_5d4);
      FUN_100045f1(local_63c,iVar6);
      local_8._0_1_ = 0x14;
      FID_conflict__Tidy(local_4a0,'\x01',0);
      puVar9 = (undefined4 *)FUN_10003a63(local_5d4,local_4a0,0,3);
      local_8._0_1_ = 0x16;
      fVar14 = FUN_10002c39(puVar9);
      local_68c = (double)fVar14;
      local_8._0_1_ = 0x14;
      FID_conflict__Tidy(local_4a0,'\x01',0);
      if (local_68c < 7.1) {
        local_62c = (wchar_t *)&stack0xfffff904;
        FUN_1000d6aa(&stack0xfffff904,piVar1);
        local_8._0_1_ = 0x14;
        FUN_10013c60(local_6dc);
        FUN_1000e8fa(pvVar2,local_6dc,local_224);
      }
      sVar10 = wcslen(L"/user_manager/groups");
      FID_conflict_assign(local_44c,(undefined4 *)L"/user_manager/groups",sVar10);
      local_650 = (int *)0x0;
      local_8._0_1_ = 0x19;
      FUN_10014818((int *)((int)local_618 + 0xc),local_44c,(int *)&local_650);
      pcVar13 = Ordinal_6_exref;
      if (local_650 != (int *)0x0) {
        sVar10 = wcslen(L"./group");
        FID_conflict_assign(local_44c,(undefined4 *)L"./group",sVar10);
        piVar4 = local_650;
        local_64c = (int *)0x0;
        local_8._0_1_ = 0x1b;
        pppppuVar12 = (undefined4 *****)local_44c[0];
        if (local_438 < 8) {
          pppppuVar12 = local_44c;
        }
        if (pppppuVar12 == (undefined4 *****)0x0) {
          local_628 = (wchar_t *)0x0;
        }
        else {
          local_628 = (wchar_t *)Ordinal_2();
          if (local_628 == (wchar_t *)0x0) goto LAB_100103a9;
        }
        local_8._0_1_ = 0x1c;
        iVar6 = (**(code **)(*piVar4 + 0x90))();
        FUN_100045f1(local_63c,iVar6);
        pcVar13 = Ordinal_6_exref;
        local_8 = CONCAT31(local_8._1_3_,0x1b);
        Ordinal_6();
        if (local_64c != (int *)0x0) {
          local_690 = 0;
          iVar6 = (**(code **)(*local_64c + 0x20))();
          FUN_100045f1(local_63c,iVar6);
          for (local_678 = 0; piVar4 = local_64c, local_678 < local_690; local_678 = local_678 + 1)
          {
            local_61c = (int *)0x0;
            local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
            local_8._0_1_ = 0x1e;
            iVar6 = (**(code **)(*local_64c + 0x1c))();
            FUN_100045f1(local_63c,iVar6);
            if (-1 < local_630) {
              local_470 = 7;
              local_474 = 0;
              local_484[0] = (undefined4 ****)((uint)local_484[0] & 0xffff0000);
              local_454 = 7;
              local_458 = 0;
              local_468[0] = (undefined4 ****)((uint)local_468[0] & 0xffff0000);
              local_4fc = 7;
              local_500 = 0;
              local_510[0] = (wchar_t ****)((uint)local_510[0] & 0xffff0000);
              local_588 = 7;
              local_58c = 0;
              local_59c[0] = 0;
              local_56c = 7;
              local_570 = 0;
              local_580[0] = 0;
              local_8._0_1_ = 0x23;
              puVar9 = (undefined4 *)FUN_10003c48(local_5b8,L"ID");
              local_8._0_1_ = 0x24;
              iVar6 = FUN_10014899((int *)&local_61c,puVar9,local_484);
              FUN_100045f1(local_63c,iVar6);
              local_8._0_1_ = 0x23;
              FID_conflict__Tidy(local_5b8,'\x01',0);
              puVar9 = (undefined4 *)FUN_10003c48(local_52c,L"name");
              local_8._0_1_ = 0x25;
              iVar6 = FUN_10014899((int *)&local_61c,puVar9,local_468);
              FUN_100045f1(local_63c,iVar6);
              local_8._0_1_ = 0x23;
              FID_conflict__Tidy(local_52c,'\x01',0);
              puVar9 = (undefined4 *)FUN_10003c48(local_548,L"groupType");
              local_8._0_1_ = 0x26;
              iVar6 = FUN_10014899((int *)&local_61c,puVar9,local_510);
              FUN_100045f1(local_63c,iVar6);
              local_8._0_1_ = 0x23;
              FID_conflict__Tidy(local_548,'\x01',0);
              _Str = (wchar_t *****)local_510[0];
              if (local_4fc < 8) {
                _Str = local_510;
              }
              local_624 = (int *)_wtol((wchar_t *)_Str);
              puVar9 = (undefined4 *)FUN_10003c48(local_4bc,L"resGroupId");
              local_8._0_1_ = 0x27;
              iVar6 = FUN_10014899((int *)&local_61c,puVar9,local_580);
              FUN_100045f1(local_63c,iVar6);
              local_8._0_1_ = 0x23;
              FID_conflict__Tidy(local_4bc,'\x01',0);
              if (local_630 == 0) {
                local_65c = (undefined1 *)&uStack_714;
                basic_string<>(&uStack_714,(undefined4 *)local_580);
                local_8._0_1_ = 0x23;
                FUN_100138f3();
                pwVar11 = FUN_10003d3e((undefined2 *)local_4d8,local_62c);
                local_8._0_1_ = 0x29;
                if (7 < *(uint *)(pwVar11 + 10)) {
                  pwVar11 = *(wchar_t **)pwVar11;
                }
                sVar10 = wcslen(pwVar11);
                FID_conflict_assign(local_468,(undefined4 *)pwVar11,sVar10);
                local_8._0_1_ = 0x23;
                FID_conflict__Tidy(local_4d8,'\x01',0);
                local_6bc[0] = 0;
                local_6bc[1] = 0;
                local_6bc[2] = 0;
                pppppuVar12 = (undefined4 *****)local_484[0];
                if (local_470 < 8) {
                  pppppuVar12 = local_484;
                }
                FUN_1001388c(local_6bc,pppppuVar12);
                pppppuVar12 = (undefined4 *****)local_468[0];
                if (local_454 < 8) {
                  pppppuVar12 = local_468;
                }
                FUN_1001388c(local_6bc + 2,pppppuVar12);
                FUN_1000e1a0(&local_6cc,local_6bc);
              }
              local_648 = (int *)0x0;
              local_8._0_1_ = 0x2b;
              if (7.5 <= local_68c) {
                FUN_1000f968(local_618,(ushort *)local_484,&local_648);
              }
              else {
                puVar9 = (undefined4 *)FUN_10003c48(local_5f0,L"rights");
                local_8._0_1_ = 0x2c;
                iVar6 = FUN_10014899((int *)&local_61c,puVar9,local_59c);
                FUN_100045f1(local_63c,iVar6);
                local_8._0_1_ = 0x2b;
                FID_conflict__Tidy(local_5f0,'\x01',0);
                FUN_1000f968(local_618,(ushort *)local_484,&local_648);
                if (local_648 == (int *)0x0) {
                  FUN_1000f671(local_618,local_59c,local_484,&local_648);
                }
              }
              piVar4 = local_648;
              local_4e8 = 0;
              local_4e4 = 0;
              local_4e0 = 0;
              local_8._0_1_ = 0x2d;
              FUN_10005665(&local_4e8,&local_658,(undefined4 *)0x0,(undefined4 *)0x0);
              if (piVar4 != (int *)0x0) {
                local_674 = (undefined1 *)0x0;
                (**(code **)(*piVar4 + 0x20))();
                for (local_660 = 1; local_660 <= (int)local_674; local_660 = local_660 + 1) {
                  (**(code **)(*piVar4 + 0x1c))();
                  if (local_628 == (wchar_t *)0x0) {
                    local_644 = 0;
                  }
                  else {
                    local_644 = Ordinal_2();
                    if (local_644 == 0) goto LAB_100103a9;
                  }
                  local_8._0_1_ = 0x2e;
                  FUN_10003c48(local_4a0,local_628);
                  local_8._0_1_ = 0x2f;
                  FUN_100088e4(&local_4e8,(undefined4 *)local_4a0);
                  local_8._0_1_ = 0x2e;
                  FID_conflict__Tidy(local_4a0,'\x01',0);
                  local_8._0_1_ = 0x2d;
                  Ordinal_6();
                }
              }
              local_684 = (int *)0x0;
              local_8._0_1_ = 0x31;
              cVar3 = FUN_1000f5eb((_Container_base0 *)&local_4e8,&local_684);
              FUN_100045f1(local_63c,(-(uint)(cVar3 != '\0') & 0x7fffbffb) + 0x80004005);
              piVar1 = *(int **)((int)local_618 + 0x14);
              pppppuVar12 = (undefined4 *****)local_468[0];
              if (local_454 < 8) {
                pppppuVar12 = local_468;
              }
              if (pppppuVar12 == (undefined4 *****)0x0) {
                local_67c = 0;
              }
              else {
                local_67c = Ordinal_2();
                if (local_67c == 0) goto LAB_100103a9;
              }
              local_8._0_1_ = 0x32;
              iVar6 = (**(code **)(*piVar1 + 0x40))();
              FUN_100045f1(local_63c,iVar6);
              local_8 = CONCAT31(local_8._1_3_,0x31);
              Ordinal_6();
              piVar1 = local_61c;
              if (local_61c != (int *)0x0) {
                local_61c = (int *)0x0;
                (**(code **)(*piVar1 + 8))();
              }
              local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
              local_8._0_1_ = 0x2d;
              if (local_684 != (int *)0x0) {
                (**(code **)(*local_684 + 8))();
              }
              local_8._0_1_ = 0x2b;
              FUN_10004315((_Container_base0 *)&local_4e8);
              local_8._0_1_ = 0x23;
              if (piVar4 != (int *)0x0) {
                (**(code **)(*piVar4 + 8))();
              }
              local_8._0_1_ = 0x22;
              FID_conflict__Tidy(local_580,'\x01',0);
              local_8._0_1_ = 0x21;
              FID_conflict__Tidy(local_59c,'\x01',0);
              local_8._0_1_ = 0x20;
              FID_conflict__Tidy(local_510,'\x01',0);
              local_8._0_1_ = 0x1f;
              FID_conflict__Tidy(local_468,'\x01',0);
              local_8._0_1_ = 0x1e;
              FID_conflict__Tidy(local_484,'\x01',0);
            }
            local_8 = CONCAT31(local_8._1_3_,0x1b);
            if (local_61c != (int *)0x0) {
              (**(code **)(*local_61c + 8))();
            }
            pcVar13 = Ordinal_6_exref;
          }
          if (local_64c != (int *)0x0) {
            local_64c = (int *)0x0;
            (**(code **)(*piVar4 + 8))();
          }
        }
        piVar4 = local_650;
        if (local_650 != (int *)0x0) {
          local_650 = (int *)0x0;
          (**(code **)(*piVar4 + 8))();
        }
        local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
        local_8._0_1_ = 0x19;
        if (local_64c != (int *)0x0) {
          (**(code **)(*local_64c + 8))();
        }
      }
      local_654 = (int *)0x0;
      local_8._0_1_ = 0x38;
      sVar10 = wcslen(L"/user_manager/users");
      FID_conflict_assign(local_44c,(undefined4 *)L"/user_manager/users",sVar10);
      FUN_10014818((int *)((int)local_618 + 0xc),local_44c,(int *)&local_654);
      if (local_654 != (int *)0x0) {
        sVar10 = wcslen(L"./user");
        FID_conflict_assign(local_44c,(undefined4 *)L"./user",sVar10);
        piVar4 = local_654;
        local_640 = (int *)0x0;
        local_8._0_1_ = 0x3a;
        if (local_438 < 8) {
          local_44c[0] = local_44c;
        }
        if ((undefined4 *****)local_44c[0] == (undefined4 *****)0x0) {
          local_668 = 0;
        }
        else {
          local_668 = Ordinal_2();
          if (local_668 == 0) goto LAB_100103a9;
        }
        local_8._0_1_ = 0x3b;
        iVar6 = (**(code **)(*piVar4 + 0x90))();
        FUN_100045f1(local_63c,iVar6);
        local_8 = CONCAT31(local_8._1_3_,0x3a);
        (*pcVar13)();
        if (local_640 != (int *)0x0) {
          local_624 = (int *)0x0;
          iVar6 = (**(code **)(*local_640 + 0x20))();
          FUN_100045f1(local_63c,iVar6);
          for (local_66c = 0; piVar4 = local_640, local_66c < (int)local_624;
              local_66c = local_66c + 1) {
            local_614 = (int *)0x0;
            local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
            local_8._0_1_ = 0x3d;
            iVar6 = (**(code **)(*local_640 + 0x1c))();
            FUN_100045f1(local_63c,iVar6);
            if (-1 < local_630) {
              local_48c = 7;
              local_490 = 0;
              local_4a0[0] = 0;
              local_4a8 = 7;
              local_4ac = 0;
              local_4bc[0] = (undefined4 ****)((uint)local_4bc[0] & 0xffff0000);
              local_518 = 7;
              local_51c = 0;
              local_52c[0] = (undefined4 ****)((uint)local_52c[0] & 0xffff0000);
              local_4c4 = 7;
              local_4c8 = 0;
              local_4d8[0] = (undefined4 ****)((uint)local_4d8[0] & 0xffff0000);
              local_5a4 = 7;
              local_5a8 = 0;
              local_5b8[0] = 0;
              local_534 = 7;
              local_538 = 0;
              local_548[0] = (undefined4 ****)((uint)local_548[0] & 0xffff0000);
              local_8._0_1_ = 0x43;
              puVar9 = (undefined4 *)FUN_10003c48(local_5f0,L"ID");
              local_8._0_1_ = 0x44;
              iVar6 = FUN_10014899((int *)&local_614,puVar9,local_4a0);
              FUN_100045f1(local_63c,iVar6);
              local_8._0_1_ = 0x43;
              FID_conflict__Tidy(local_5f0,'\x01',0);
              puVar9 = (undefined4 *)FUN_10003c48(local_59c,L"name");
              local_8._0_1_ = 0x45;
              iVar6 = FUN_10014899((int *)&local_614,puVar9,local_4bc);
              FUN_100045f1(local_63c,iVar6);
              local_8._0_1_ = 0x43;
              FID_conflict__Tidy(local_59c,'\x01',0);
              puVar9 = (undefined4 *)FUN_10003c48(local_580,L"password");
              local_8._0_1_ = 0x46;
              iVar6 = FUN_10014899((int *)&local_614,puVar9,local_52c);
              FUN_100045f1(local_63c,iVar6);
              local_8._0_1_ = 0x43;
              FID_conflict__Tidy(local_580,'\x01',0);
              puVar9 = (undefined4 *)FUN_10003c48(local_510,L"group");
              local_8._0_1_ = 0x47;
              iVar6 = FUN_10014899((int *)&local_614,puVar9,local_4d8);
              FUN_100045f1(local_63c,iVar6);
              local_8._0_1_ = 0x43;
              FID_conflict__Tidy(local_510,'\x01',0);
              puVar9 = (undefined4 *)FUN_10003c48(local_484,L"groupID");
              local_8._0_1_ = 0x48;
              iVar6 = FUN_10014899((int *)&local_614,puVar9,local_548);
              FUN_100045f1(local_63c,iVar6);
              local_8._0_1_ = 0x43;
              FID_conflict__Tidy(local_484,'\x01',0);
              puVar9 = (undefined4 *)FUN_10003c48(local_468,L"resUserId");
              local_8._0_1_ = 0x49;
              iVar6 = FUN_10014899((int *)&local_614,puVar9,local_5b8);
              FUN_100045f1(local_63c,iVar6);
              local_8._0_1_ = 0x43;
              FID_conflict__Tidy(local_468,'\x01',0);
              piVar4 = local_6cc;
              if (local_630 == 0) {
                local_674 = (undefined1 *)&uStack_714;
                basic_string<>(&uStack_714,(undefined4 *)local_5b8);
                local_8._0_1_ = 0x43;
                FUN_100138f3();
                pwVar11 = FUN_10003d3e(local_4f4,local_62c);
                local_8._0_1_ = 0x4b;
                if (7 < *(uint *)(pwVar11 + 10)) {
                  pwVar11 = *(wchar_t **)pwVar11;
                }
                sVar10 = wcslen(pwVar11);
                FID_conflict_assign(local_4bc,(undefined4 *)pwVar11,sVar10);
                local_8._0_1_ = 0x43;
                FID_conflict__Tidy(local_4f4,'\x01',0);
                piVar4 = local_6cc;
              }
              for (; local_6b0 = piVar4, piVar4 != local_6c8; piVar4 = piVar4 + 3) {
                pppppuVar12 = (undefined4 *****)local_548[0];
                if (local_534 < 8) {
                  pppppuVar12 = local_548;
                }
                if (pppppuVar12 == (undefined4 *****)0x0) {
                  local_68c = (double)((ulonglong)local_68c & 0xffffffff);
                }
                else {
                  iVar6 = Ordinal_2();
                  local_68c = (double)CONCAT44(iVar6,(undefined4)local_68c);
                  if (iVar6 == 0) goto LAB_100103a9;
                }
                local_8._0_1_ = 0x4c;
                local_61d = FUN_10001821((void *)((int)&local_68c + 4),*piVar4);
                local_8._0_1_ = 0x43;
                (*pcVar13)();
                if (local_61d != '\0') {
                  pwVar11 = FUN_10003d3e(local_60c,(wchar_t *)piVar4[2]);
                  local_8._0_1_ = 0x4d;
                  if (7 < *(uint *)(pwVar11 + 10)) {
                    pwVar11 = *(wchar_t **)pwVar11;
                  }
                  sVar10 = wcslen(pwVar11);
                  FID_conflict_assign(local_4d8,(undefined4 *)pwVar11,sVar10);
                  local_8._0_1_ = 0x43;
                  FID_conflict__Tidy(local_60c,'\x01',0);
                  break;
                }
              }
              piVar4 = *(int **)((int)local_618 + 0x10);
              pppppuVar12 = (undefined4 *****)local_4d8[0];
              if (local_4c4 < 8) {
                pppppuVar12 = local_4d8;
              }
              if (pppppuVar12 == (undefined4 *****)0x0) {
                local_644 = 0;
              }
              else {
                local_644 = Ordinal_2();
                if (local_644 == 0) goto LAB_100103a9;
              }
              local_8._0_1_ = 0x4e;
              pppppuVar12 = (undefined4 *****)local_52c[0];
              if (local_518 < 8) {
                pppppuVar12 = local_52c;
              }
              if (pppppuVar12 == (undefined4 *****)0x0) {
                local_65c = (undefined1 *)0x0;
              }
              else {
                local_65c = (undefined1 *)Ordinal_2();
                if (local_65c == (undefined1 *)0x0) goto LAB_100103a9;
              }
              local_8._0_1_ = 0x4f;
              pppppuVar12 = (undefined4 *****)local_4bc[0];
              if (local_4a8 < 8) {
                pppppuVar12 = local_4bc;
              }
              if (pppppuVar12 == (undefined4 *****)0x0) {
                local_658 = 0;
              }
              else {
                local_658 = Ordinal_2();
                if (local_658 == 0) goto LAB_100103a9;
              }
              local_8._0_1_ = 0x50;
              iVar6 = (**(code **)(*piVar4 + 0x34))();
              FUN_100045f1(local_63c,iVar6);
              local_8._0_1_ = 0x4f;
              (*pcVar13)();
              local_8._0_1_ = 0x4e;
              iStack_710 = 0x10011417;
              (*pcVar13)();
              local_8 = CONCAT31(local_8._1_3_,0x43);
              iStack_710 = local_644;
              uStack_714 = 0x10011423;
              (*pcVar13)();
              piVar4 = local_614;
              if (local_614 != (int *)0x0) {
                local_614 = (int *)0x0;
                (**(code **)(*piVar4 + 8))();
              }
              local_8._0_1_ = 0x42;
              FID_conflict__Tidy(local_548,'\x01',0);
              local_8._0_1_ = 0x41;
              FID_conflict__Tidy(local_5b8,'\x01',0);
              local_8._0_1_ = 0x40;
              FID_conflict__Tidy(local_4d8,'\x01',0);
              local_8._0_1_ = 0x3f;
              FID_conflict__Tidy(local_52c,'\x01',0);
              local_8._0_1_ = 0x3e;
              FID_conflict__Tidy(local_4bc,'\x01',0);
              local_8._0_1_ = 0x3d;
              FID_conflict__Tidy(local_4a0,'\x01',0);
            }
            local_8 = CONCAT31(local_8._1_3_,0x3a);
            if (local_614 != (int *)0x0) {
              (**(code **)(*local_614 + 8))();
            }
          }
          if (local_640 != (int *)0x0) {
            local_640 = (int *)0x0;
            (**(code **)(*piVar4 + 8))();
          }
        }
        piVar4 = local_654;
        if (local_654 != (int *)0x0) {
          local_654 = (int *)0x0;
          (**(code **)(*piVar4 + 8))();
        }
        local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
        local_8._0_1_ = 0x38;
        if (local_640 != (int *)0x0) {
          (**(code **)(*local_640 + 8))();
        }
      }
      local_8._0_1_ = 0x19;
      if (local_654 != (int *)0x0) {
        (**(code **)(*local_654 + 8))();
      }
      local_8._0_1_ = 0x14;
      if (local_650 != (int *)0x0) {
        (**(code **)(*local_650 + 8))();
      }
      local_8._0_1_ = 0x13;
      FID_conflict__Tidy(local_44c,'\x01',0);
      local_8._0_1_ = 0x11;
      if (local_670 != (int *)0x0) {
        (**(code **)(*local_670 + 8))();
      }
      local_8._0_1_ = 0x10;
      FID_conflict__Tidy(local_5d4,'\x01',0);
      local_8._0_1_ = 0xb;
      FUN_100147f2(&local_610);
    }
    local_8._0_1_ = 9;
    if (local_680 != (int *)0x0) {
      (**(code **)(*local_680 + 8))();
    }
    local_8._0_1_ = 7;
    if (local_664 != (int *)0x0) {
      (**(code **)(*local_664 + 8))();
    }
  }
  local_8._0_1_ = 6;
  FID_conflict__Tidy(local_564,'\x01',0);
  local_8 = CONCAT31(local_8._1_3_,3);
  ATL::CRegKey::Close((CRegKey *)&local_69c);
  local_8 = 2;
  FUN_100115fe();
  return;
}



// Function: Catch@100115df at 100115df

undefined * Catch_100115df(void)

{
  int unaff_EBP;
  
  FUN_100045f1((void *)(unaff_EBP + -0x638),-0x7fffbffb);
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return &DAT_100115fc;
}



// Function: FUN_100115fe at 100115fe

void FUN_100115fe(void)

{
  undefined1 unaff_BL;
  int unaff_EBP;
  
  *(undefined1 *)(unaff_EBP + -4) = unaff_BL;
  FUN_1000df2a((_Container_base0 *)(unaff_EBP + -0x6d8));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1000df2a((_Container_base0 *)(unaff_EBP + -0x6c8));
  FUN_10014f93();
  return;
}



// Function: FUN_10011627 at 10011627

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10011627(void *param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined4 local_4c [2];
  int local_44;
  wchar_t *local_40;
  int local_3c;
  int *local_38;
  int local_34;
  undefined1 local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0x10011633;
  FUN_1000e684((void *)((int)param_1 + 0x18));
  local_38 = (int *)0x0;
  iVar2 = 1;
  local_8 = 1;
  (**(code **)(**(int **)((int)param_1 + 0x14) + 0x34))(*(int **)((int)param_1 + 0x14),&local_38);
  local_3c = 0;
  (**(code **)(*local_38 + 0x20))(local_38,&local_3c);
  if (0 < local_3c) {
    do {
      (**(code **)(*local_38 + 0x1c))(local_38,iVar2,&local_44);
      if (local_44 == 0) {
        local_40 = (wchar_t *)0x0;
      }
      else {
        local_40 = (wchar_t *)Ordinal_2(local_44);
        if (local_40 == (wchar_t *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_100010d9(-0x7ff8fff2);
        }
      }
      local_8._0_1_ = 2;
      local_34 = iVar2;
      FUN_10003c48(local_30,local_40);
      local_8._0_1_ = 5;
      cVar3 = '\0';
      piVar1 = (int *)FUN_1000f48f((void *)((int)param_1 + 0x18),&local_34);
      FUN_1000e4ae((void *)((int)param_1 + 0x18),local_4c,piVar1,cVar3);
      local_8._0_1_ = 2;
      FID_conflict__Tidy(local_30,'\x01',0);
      local_8 = CONCAT31(local_8._1_3_,1);
      Ordinal_6(local_40);
      iVar2 = iVar2 + 1;
    } while (iVar2 <= local_3c);
  }
  FUN_100101e2(param_1);
  FUN_1000ddd1();
  local_8 = 0xffffffff;
  if (local_38 != (int *)0x0) {
    (**(code **)(*local_38 + 8))(local_38);
  }
  FUN_10014f84();
  return;
}



// Function: FUN_1001171d at 1001171d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1001171d(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x10);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10011785 at 10011785

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10011785(undefined4 param_1,undefined4 *param_2)

{
  AFX_MODULE_STATE *pAVar1;
  AFX_MAINTAIN_STATE2 local_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x10011791;
  pAVar1 = (AFX_MODULE_STATE *)FUN_10014bb5();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_20,pAVar1);
  *param_2 = DAT_1002a57c;
  local_8 = 0xffffffff;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_20);
  return 0;
}



// Function: FUN_100117c4 at 100117c4

undefined4 * __cdecl FUN_100117c4(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_1 != param_2) {
    do {
      puVar1 = param_3 + 3;
      *param_3 = *param_1;
      puVar2 = param_1 + 2;
      param_3[1] = param_1[1];
      param_1 = param_1 + 3;
      param_3[2] = *puVar2;
      param_3 = puVar1;
    } while (param_1 != param_2);
  }
  return param_3;
}



// Function: FUN_100117ec at 100117ec

void __fastcall FUN_100117ec(int param_1)

{
  int *piVar1;
  
  if ((*(int *)(param_1 + 8) != 0) && (piVar1 = *(int **)(param_1 + 8), piVar1 != (int *)0x0)) {
    *(undefined4 *)(param_1 + 8) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if ((*(int *)(param_1 + 0xc) != 0) && (piVar1 = *(int **)(param_1 + 0xc), piVar1 != (int *)0x0)) {
    *(undefined4 *)(param_1 + 0xc) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if ((*(int *)(param_1 + 0x10) != 0) && (piVar1 = *(int **)(param_1 + 0x10), piVar1 != (int *)0x0))
  {
    *(undefined4 *)(param_1 + 0x10) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10011834 at 10011834

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __fastcall FUN_10011834(int param_1)

{
  int *piVar1;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x10011840;
  if (*(int *)(param_1 + 8) == 0) {
    piVar1 = FUN_10001ec7(local_14,'\0');
    local_8 = 0;
    FUN_100021a4((int *)(param_1 + 8),piVar1);
    local_8 = 0xffffffff;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
  }
  return 0;
}



// Function: FUN_1001187a at 1001187a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1001187a(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}



// Function: FUN_100118bd at 100118bd

undefined4 FUN_100118bd(void)

{
  undefined4 *puVar1;
  undefined4 local_8;
  
  puVar1 = DAT_1002a768;
  if (DAT_1002a768 != DAT_1002a76c) {
    do {
      Ordinal_6(puVar1[2]);
      Ordinal_6(puVar1[1]);
      Ordinal_6(*puVar1);
      puVar1 = puVar1 + 3;
    } while (puVar1 != DAT_1002a76c);
  }
  FUN_10003ac9(&DAT_1002a768,&local_8,DAT_1002a768,DAT_1002a76c);
  DAT_1002a57c = 0;
  return 0;
}



// Function: FUN_10011919 at 10011919

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10011919(undefined4 param_1,int param_2,int param_3,int param_4)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10011925;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  if (param_2 == 0) {
    param_2 = 0;
  }
  else {
    param_2 = Ordinal_2(param_2);
    if (param_2 == 0) goto LAB_10011971;
  }
  local_8 = 0;
  local_1c = FUN_10001718(&param_2);
  local_8 = 0xffffffff;
  Ordinal_6(param_2);
  if (param_3 == 0) {
    param_2 = 0;
  }
  else {
    param_2 = Ordinal_2(param_3);
    if (param_2 == 0) goto LAB_10011971;
  }
  local_8 = 1;
  local_18 = FUN_10001718(&param_2);
  local_8 = 0xffffffff;
  Ordinal_6(param_2);
  if (param_4 == 0) {
    param_2 = 0;
  }
  else {
    param_2 = Ordinal_2(param_4);
    if (param_2 == 0) {
LAB_10011971:
                    /* WARNING: Subroutine does not return */
      FUN_100010d9(-0x7ff8fff2);
    }
  }
  local_8 = 2;
  local_14 = FUN_10001718(&param_2);
  local_8 = 0xffffffff;
  Ordinal_6(param_2);
  FUN_1000e1a0(&DAT_1002a768,&local_1c);
  DAT_1002a57c = DAT_1002a57c + 1;
  return 0;
}



// Function: FUN_100119f1 at 100119f1

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_100119f1(undefined1 *param_1,undefined4 param_2,undefined4 param_3,int param_4,
                 undefined4 param_5)

{
  int iVar1;
  LPCWSTR *ppWVar2;
  size_t sVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *piVar4;
  int *piVar5;
  undefined4 local_288 [3];
  int local_27c;
  DWORD local_278;
  undefined4 local_274;
  undefined4 local_270;
  int local_26c;
  undefined4 local_268;
  int *local_264;
  int *local_260;
  int *local_25c;
  int local_258;
  int local_254;
  int *local_250;
  int *local_24c;
  char local_245;
  undefined1 *local_244;
  undefined4 **local_240 [5];
  uint local_22c;
  FILE local_224 [16];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x278;
  local_8 = 0x10011a00;
  local_244 = param_1;
  local_274 = param_2;
  local_270 = param_3;
  local_26c = param_4;
  local_268 = param_5;
  FUN_10001c46(local_288);
  local_8 = 0;
  FUN_100045f1(local_288,0);
  local_8._0_1_ = 1;
  local_258 = 0;
  piVar4 = DAT_1002a768;
  do {
    local_264 = piVar4;
    if (piVar4 == DAT_1002a76c) {
LAB_10011a94:
      if (local_258 == DAT_1002a57c) {
        local_27c = -0x7fffbffb;
      }
      else {
        DAT_1002a57c = DAT_1002a57c + -1;
      }
      local_270 = 0;
      local_26c = 0;
      local_268 = 0;
      local_8._0_1_ = 3;
      ppWVar2 = (LPCWSTR *)DAT_1002a778;
      if (DAT_1002a78c < 8) {
        ppWVar2 = &DAT_1002a778;
      }
      iVar1 = Open(&local_270,(HKEY)0x80000002,(LPCWSTR)ppWVar2,0x2001f);
      if (iVar1 == 0) {
        local_278 = 0x20a;
        ppWVar2 = (LPCWSTR *)DAT_1002a794;
        if (DAT_1002a7a8 < 8) {
          ppWVar2 = &DAT_1002a794;
        }
        FUN_100013a4(&local_270,(LPBYTE)local_224,(LPCWSTR)ppWVar2,&local_278);
        ATL::CRegKey::Close((CRegKey *)&local_270);
        piVar5 = (int *)(local_244 + 8);
        local_244 = &stack0xfffffd64;
        piVar4 = extraout_ECX;
        local_260 = piVar5;
        FUN_1000d6aa(&stack0xfffffd64,piVar5);
        local_8._0_1_ = 3;
        FUN_100141fe((wchar_t *)local_224,piVar4);
        if (*piVar5 != 0) {
          FUN_100147e9(&local_254);
          local_24c = (int *)0x0;
          local_8._0_1_ = 7;
          FUN_10003c48(local_240,L"/user_manager/users");
          local_8._0_1_ = 8;
          FUN_10014818(piVar5,local_240,(int *)&local_24c);
          if (local_24c != (int *)0x0) {
            sVar3 = wcslen(L"./user");
            FID_conflict_assign(local_240,(undefined4 *)L"./user",sVar3);
            piVar4 = local_24c;
            local_250 = (int *)0x0;
            local_8._0_1_ = 10;
            if (local_22c < 8) {
              local_240[0] = local_240;
            }
            if ((undefined4 ***)local_240[0] == (undefined4 ***)0x0) {
              local_244 = (undefined1 *)0x0;
            }
            else {
              local_244 = (undefined1 *)Ordinal_2();
              if (local_244 == (undefined1 *)0x0) {
LAB_10011b0e:
                    /* WARNING: Subroutine does not return */
                FUN_100010d9(-0x7ff8fff2);
              }
            }
            local_8._0_1_ = 0xb;
            iVar1 = (**(code **)(*piVar4 + 0x90))();
            FUN_100045f1(local_288,iVar1);
            local_8._0_1_ = 10;
            Ordinal_6(local_244);
            if (local_250 != (int *)0x0) {
              local_25c = (int *)0x0;
              local_8._0_1_ = 0xd;
              iVar1 = (**(code **)(*local_250 + 0x1c))();
              FUN_100045f1(local_288,iVar1);
              if (-1 < local_27c) {
                (**(code **)(*local_24c + 0x50))();
                local_244 = &stack0xfffffd5c;
                piVar4 = extraout_ECX_00;
                FUN_1000d6aa(&stack0xfffffd5c,local_260);
                local_8._0_1_ = 0xd;
                FUN_10014502(local_224,piVar4);
                piVar4 = local_25c;
                if (local_25c != (int *)0x0) {
                  local_25c = (int *)0x0;
                  (**(code **)(*piVar4 + 8))();
                }
              }
              piVar4 = local_250;
              if (local_250 != (int *)0x0) {
                local_250 = (int *)0x0;
                (**(code **)(*piVar4 + 8))();
              }
              local_8._0_1_ = 10;
              if (local_25c != (int *)0x0) {
                (**(code **)(*local_25c + 8))();
              }
            }
            piVar4 = local_24c;
            if (local_24c != (int *)0x0) {
              local_24c = (int *)0x0;
              (**(code **)(*piVar4 + 8))();
            }
            local_8._0_1_ = 8;
            if (local_250 != (int *)0x0) {
              (**(code **)(*local_250 + 8))();
            }
          }
          local_8._0_1_ = 7;
          FID_conflict__Tidy(local_240,'\x01',0);
          local_8._0_1_ = 5;
          if (local_24c != (int *)0x0) {
            (**(code **)(*local_24c + 8))();
          }
          local_8._0_1_ = 3;
          FUN_100147f2(&local_254);
        }
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      ATL::CRegKey::Close((CRegKey *)&local_270);
      local_8 = 0xffffffff;
      FUN_10014f93();
      return;
    }
    if ((short)local_274 != 3) {
      if (*piVar4 == 0) {
        local_254 = 0;
      }
      else {
        local_254 = Ordinal_2();
        if (local_254 == 0) goto LAB_10011b0e;
      }
      local_8._0_1_ = 2;
      local_245 = FUN_10001821(&local_254,local_26c);
      local_8._0_1_ = 1;
      Ordinal_6();
      if (local_245 == '\0') goto LAB_10011ae9;
LAB_10011a74:
      Ordinal_6();
      Ordinal_6();
      Ordinal_6();
      FUN_10003a9c(&DAT_1002a768,&local_260,piVar4);
      goto LAB_10011a94;
    }
    if (local_258 == local_26c) goto LAB_10011a74;
LAB_10011ae9:
    piVar4 = piVar4 + 3;
    local_258 = local_258 + 1;
  } while( true );
}



// Function: Catch@10011e23 at 10011e23

undefined4 Catch_10011e23(void)

{
  int unaff_EBP;
  
  FUN_100045f1((void *)(unaff_EBP + -0x284),-0x7fffbffb);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10011e11;
}



// Function: FUN_10011e3d at 10011e3d

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10011e3d(undefined4 param_1,int param_2,wchar_t *param_3,undefined2 *param_4)

{
  bool bVar1;
  undefined2 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 local_30 [3];
  undefined4 local_24;
  int *local_20;
  int local_1c;
  int local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x10011e49;
  FUN_10001c46(local_30);
  local_8 = 0;
  FUN_100045f1(local_30,0);
  local_8._0_1_ = 1;
  piVar4 = DAT_1002a768;
  do {
    if (piVar4 == DAT_1002a76c) {
      return 0x80004005;
    }
    local_20 = piVar4;
    if (param_2 == 0) {
      local_1c = 0;
    }
    else {
      local_1c = Ordinal_2(param_2);
      if (local_1c == 0) goto LAB_10011eaa;
    }
    local_8._0_1_ = 2;
    if (*piVar4 == 0) {
      local_18[0] = 0;
    }
    else {
      local_18[0] = Ordinal_2(*piVar4);
      if (local_18[0] == 0) {
LAB_10011eaa:
                    /* WARNING: Subroutine does not return */
        FUN_100010d9(-0x7ff8fff2);
      }
    }
    local_8._0_1_ = 3;
    bVar1 = ATL::CComBSTR::operator==((CComBSTR *)local_18,(CComBSTR *)&local_1c);
    local_8._0_1_ = 2;
    Ordinal_6(local_18[0]);
    local_8._0_1_ = 1;
    Ordinal_6(local_1c);
    if (bVar1) {
      iVar3 = _wcsicmp((wchar_t *)piVar4[1],param_3);
      if (iVar3 == 0) {
        uVar2 = 0xffff;
      }
      else {
        uVar2 = 0;
      }
      *param_4 = uVar2;
      if (piVar4 == DAT_1002a76c) {
        return 0x80004005;
      }
      return local_24;
    }
    piVar4 = piVar4 + 3;
  } while( true );
}



// Function: Catch@10011f37 at 10011f37

undefined4 Catch_10011f37(void)

{
  int unaff_EBP;
  
  FUN_100045f1((void *)(unaff_EBP + -0x2c),-0x7fffbffb);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10011f1d;
}



// Function: FUN_10011f4e at 10011f4e

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_10011f4e(undefined4 param_1,short param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined4 *param_6)

{
  bool bVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 local_30 [3];
  undefined4 local_24;
  int *local_20;
  int local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x10011f5a;
  FUN_10001c46(local_30);
  local_8 = 0;
  FUN_100045f1(local_30,0);
  local_8 = CONCAT31(local_8._1_3_,1);
  local_18 = 0;
  piVar3 = DAT_1002a768;
  do {
    if (piVar3 == DAT_1002a76c) {
LAB_10011fb9:
      if (local_18 == DAT_1002a57c) {
        local_24 = 0x80004005;
      }
      return local_24;
    }
    local_20 = piVar3;
    if (param_2 != 3) {
      if (*piVar3 == 0) {
        local_1c = 0;
      }
      else {
        local_1c = Ordinal_2(*piVar3);
        if (local_1c == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_100010d9(-0x7ff8fff2);
        }
      }
      local_8._0_1_ = 2;
      bVar1 = FUN_10001821(&local_1c,param_4);
      local_8 = CONCAT31(local_8._1_3_,1);
      Ordinal_6(local_1c);
      if (!bVar1) goto LAB_10012009;
LAB_10011fa0:
      uVar2 = Ordinal_2(piVar3[2]);
      param_6[2] = uVar2;
      uVar2 = Ordinal_2(piVar3[1]);
      param_6[1] = uVar2;
      uVar2 = Ordinal_2(*piVar3);
      *param_6 = uVar2;
      goto LAB_10011fb9;
    }
    if (local_18 == param_4) goto LAB_10011fa0;
LAB_10012009:
    piVar3 = piVar3 + 3;
    local_18 = local_18 + 1;
  } while( true );
}



// Function: Catch@1001202d at 1001202d

undefined4 Catch_1001202d(void)

{
  int unaff_EBP;
  
  FUN_100045f1((void *)(unaff_EBP + -0x2c),-0x7fffbffb);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10011fcf;
}



// Function: FUN_10012044 at 10012044

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10012044(void *param_1)

{
  int *piVar1;
  int iVar2;
  LPCWSTR *ppWVar3;
  size_t sVar4;
  undefined4 *puVar5;
  undefined4 *****pppppuVar6;
  int *extraout_ECX;
  DWORD local_334;
  undefined4 local_330 [3];
  int local_324;
  undefined4 local_320;
  undefined4 local_31c;
  undefined4 local_318;
  int local_314;
  int local_310 [5];
  int local_2fc;
  int *local_2f8;
  int *local_2f4;
  int *local_2f0;
  int *local_2ec;
  undefined1 local_2e8 [28];
  undefined1 local_2cc [28];
  undefined2 local_2b0 [8];
  undefined4 local_2a0;
  undefined4 local_29c;
  LPCWSTR ***local_294 [5];
  uint local_280;
  undefined4 ****local_278 [5];
  uint local_264;
  undefined4 ****local_25c [4];
  undefined4 local_24c;
  uint local_248;
  undefined4 ****local_240 [4];
  undefined4 local_230;
  uint local_22c;
  wchar_t local_224;
  undefined1 local_222 [538];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x328;
  local_8 = 0x10012053;
  FUN_10001c2c(local_330);
  local_320 = 0;
  local_31c = 0;
  local_318 = 0;
  local_2fc = 0;
  local_2ec = (int *)0x0;
  local_2f4 = (int *)0x0;
  local_2f0 = (int *)0x0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 10;
  piVar1 = FUN_10001ec7(&local_2f8,'\0');
  local_8._0_1_ = 0xb;
  FUN_100021a4(&local_2fc,piVar1);
  local_8._0_1_ = 10;
  if (local_2f8 != (int *)0x0) {
    (**(code **)(*local_2f8 + 8))();
  }
  basic_string<>(local_294,&DAT_1002a778);
  local_8._0_1_ = 0xd;
  if (local_280 < 8) {
    local_294[0] = (LPCWSTR ***)local_294;
  }
  iVar2 = Open(&local_320,(HKEY)0x80000002,(LPCWSTR)local_294[0],0x2001f);
  if (iVar2 == 0) {
    local_224 = L'\0';
    memset(local_222,0,0x208);
    local_334 = 0x20a;
    ppWVar3 = (LPCWSTR *)DAT_1002a7b0;
    if (DAT_1002a7c4 < 8) {
      ppWVar3 = &DAT_1002a7b0;
    }
    FUN_100013a4(&local_320,(LPBYTE)&local_224,(LPCWSTR)ppWVar3,&local_334);
    ATL::CRegKey::Close((CRegKey *)&local_320);
    local_2f8 = (int *)&stack0xfffffcb4;
    piVar1 = extraout_ECX;
    FUN_1000d6aa(&stack0xfffffcb4,&local_2fc);
    local_8._0_1_ = 0xd;
    FUN_100141fe(&local_224,piVar1);
    if (local_2fc != 0) {
      FUN_100147e9(local_310 + 4);
      local_8._0_1_ = 0xf;
      FUN_10003c48(local_278,L"/user_manager/users");
      local_8 = CONCAT31(local_8._1_3_,0x10);
      iVar2 = FUN_10014818(&local_2fc,local_278,(int *)&local_2ec);
      FUN_100045f1(local_330,iVar2);
      if ((local_2ec != (int *)0x0) && (-1 < local_324)) {
        sVar4 = wcslen(L"./user");
        FID_conflict_assign(local_278,(undefined4 *)L"./user",sVar4);
        piVar1 = local_2ec;
        if (local_264 < 8) {
          local_278[0] = local_278;
        }
        if ((undefined4 *****)local_278[0] == (undefined4 *****)0x0) {
          local_310[2] = 0;
        }
        else {
          local_310[2] = Ordinal_2();
          if (local_310[2] == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_100010d9(-0x7ff8fff2);
          }
        }
        local_8._0_1_ = 0x11;
        iVar2 = (**(code **)(*piVar1 + 0x90))();
        FUN_100045f1(local_330,iVar2);
        local_8 = CONCAT31(local_8._1_3_,0x10);
        Ordinal_6(local_310[2]);
        if ((local_2f0 != (int *)0x0) && (-1 < local_324)) {
          local_2f8 = (int *)0x0;
          iVar2 = (**(code **)(*local_2f0 + 0x20))(local_2f0);
          FUN_100045f1(local_330,iVar2);
          if ((-1 < local_324) && (local_2f8 != (int *)0x0)) {
            local_314 = 0;
            local_310[0] = 0;
            local_310[1] = 0;
            for (local_310[3] = 0; local_310[3] < (int)local_2f8; local_310[3] = local_310[3] + 1) {
              iVar2 = (**(code **)(*local_2f0 + 0x1c))(local_2f0,local_310[3]);
              FUN_100045f1(local_330,iVar2);
              if (-1 < local_324) {
                local_248 = 7;
                local_24c = 0;
                local_25c[0] = (undefined4 ****)((uint)local_25c[0] & 0xffff0000);
                local_22c = 7;
                local_230 = 0;
                local_240[0] = (undefined4 ****)((uint)local_240[0] & 0xffff0000);
                local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
                local_29c = 7;
                local_2a0 = 0;
                local_2b0[0] = 0;
                local_8._0_1_ = 0x14;
                puVar5 = (undefined4 *)FUN_10003c48(local_2cc,L"ID");
                local_8._0_1_ = 0x15;
                FUN_10014899((int *)&local_2f4,puVar5,local_25c);
                local_8._0_1_ = 0x14;
                FID_conflict__Tidy(local_2cc,'\x01',0);
                puVar5 = (undefined4 *)FUN_10003c48(local_2e8,L"resUserId");
                local_8._0_1_ = 0x16;
                FUN_10014899((int *)&local_2f4,puVar5,local_240);
                local_8 = CONCAT31(local_8._1_3_,0x14);
                FID_conflict__Tidy(local_2e8,'\x01',0);
                pppppuVar6 = (undefined4 *****)local_25c[0];
                if (local_248 < 8) {
                  pppppuVar6 = local_25c;
                }
                FUN_1001388c(&local_314,pppppuVar6);
                pppppuVar6 = (undefined4 *****)local_240[0];
                if (local_22c < 8) {
                  pppppuVar6 = local_240;
                }
                FUN_1001388c(local_310,pppppuVar6);
                if ((local_314 != 0) && (local_310[0] != 0)) {
                  FUN_1000e1a0(param_1,&local_314);
                }
                piVar1 = local_2f4;
                if (local_2f4 != (int *)0x0) {
                  local_2f4 = (int *)0x0;
                  (**(code **)(*piVar1 + 8))();
                }
                local_8._0_1_ = 0x13;
                FID_conflict__Tidy(local_2b0,'\x01',0);
                local_8._0_1_ = 0x12;
                FID_conflict__Tidy(local_240,'\x01',0);
                local_8 = CONCAT31(local_8._1_3_,0x10);
                FID_conflict__Tidy(local_25c,'\x01',0);
              }
            }
          }
          piVar1 = local_2f0;
          if (local_2f0 != (int *)0x0) {
            local_2f0 = (int *)0x0;
            (**(code **)(*piVar1 + 8))();
          }
        }
        piVar1 = local_2ec;
        if (local_2ec != (int *)0x0) {
          local_2ec = (int *)0x0;
          (**(code **)(*piVar1 + 8))();
        }
      }
      local_8._0_1_ = 0xf;
      FID_conflict__Tidy(local_278,'\x01',0);
      local_8._0_1_ = 0xd;
      FUN_100147f2(local_310 + 4);
    }
  }
  local_8 = CONCAT31(local_8._1_3_,10);
  FID_conflict__Tidy(local_294,'\x01',0);
  local_8 = 9;
  FUN_100125b7();
  return;
}



// Function: Catch@10012564 at 10012564

undefined * Catch_10012564(void)

{
  int *piVar1;
  int unaff_EBP;
  
  piVar1 = *(int **)(unaff_EBP + -0x2f0);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)(unaff_EBP + -0x2f0) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(unaff_EBP + -0x2ec);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)(unaff_EBP + -0x2ec) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(unaff_EBP + -0x2e8);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)(unaff_EBP + -0x2e8) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined4 *)(unaff_EBP + -4) = 9;
  return &DAT_100125b5;
}



// Function: FUN_100125b7 at 100125b7

void FUN_100125b7(void)

{
  int *piVar1;
  int *unaff_EBX;
  int unaff_EBP;
  
  *(undefined1 *)(unaff_EBP + -4) = 7;
  piVar1 = *(int **)(unaff_EBP + -0x2ec);
  if (piVar1 != unaff_EBX) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined1 *)(unaff_EBP + -4) = 5;
  piVar1 = *(int **)(unaff_EBP + -0x2f0);
  if (piVar1 != unaff_EBX) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined1 *)(unaff_EBP + -4) = 3;
  piVar1 = *(int **)(unaff_EBP + -0x2e8);
  if (piVar1 != unaff_EBX) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  piVar1 = *(int **)(unaff_EBP + -0x2f8);
  if (piVar1 != unaff_EBX) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x31c));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10014f93();
  return;
}



// Function: FUN_10012621 at 10012621

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_10012621(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  LPCWSTR *ppWVar6;
  size_t sVar7;
  wchar_t *pwVar8;
  undefined4 ****ppppuVar9;
  undefined2 *this;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar10;
  int *extraout_ECX_05;
  code *pcVar11;
  int *piVar12;
  uint local_5f8 [4];
  uint local_5e8 [4];
  uint local_5d8 [4];
  undefined4 local_5c8;
  undefined4 uStack_5c4;
  undefined4 local_5c0;
  undefined4 uStack_5bc;
  uint local_5b8 [4];
  uint local_5a8 [4];
  uint local_598 [4];
  uint local_588 [2];
  int local_580;
  int *local_578;
  int *local_574;
  undefined4 local_570;
  int *local_568;
  int *local_564;
  undefined4 local_560;
  DWORD local_558;
  undefined1 *local_554;
  int *local_550;
  undefined4 local_54c;
  undefined4 local_548;
  undefined4 local_544;
  wchar_t *local_540;
  int local_53c;
  int local_538;
  int local_534;
  int local_530;
  int local_52c;
  int local_528;
  int local_524;
  int local_520;
  int local_51c;
  int local_518;
  undefined4 local_514 [3];
  int local_508;
  int local_504;
  int local_500;
  int local_4fc;
  int local_4f8;
  int local_4f4;
  int local_4f0;
  undefined1 *local_4ec;
  undefined1 *local_4e8;
  int *local_4e4;
  int local_4e0;
  int *local_4dc;
  int *local_4d8;
  int *local_4d4;
  int local_4d0;
  int *local_4cc;
  int *local_4c8;
  int *local_4c4;
  int *local_4c0;
  char local_4b9;
  undefined1 local_4b8 [28];
  undefined2 local_49c [14];
  undefined4 local_480 [7];
  undefined4 ***local_464 [5];
  uint local_450;
  undefined4 ***local_448 [5];
  uint local_434;
  wchar_t local_42c [260];
  FILE local_224 [16];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x668;
  local_8 = 0x10012630;
  local_4fc = param_1;
  FUN_10001c46(local_514);
  local_8 = 0;
  FUN_100045f1(local_514,0);
  local_578 = (int *)0x0;
  local_574 = (int *)0x0;
  local_570 = 0;
  local_568 = (int *)0x0;
  local_564 = (int *)0x0;
  local_560 = 0;
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_54c = 0;
  local_548 = 0;
  local_544 = 0;
  local_8._0_1_ = 4;
  ppWVar6 = (LPCWSTR *)DAT_1002a778;
  if (DAT_1002a78c < 8) {
    ppWVar6 = &DAT_1002a778;
  }
  iVar5 = Open(&local_54c,(HKEY)0x80000002,(LPCWSTR)ppWVar6,0x2001f);
  if (iVar5 == 0) {
    local_558 = 0x20a;
    ppWVar6 = (LPCWSTR *)DAT_1002a794;
    if (DAT_1002a7a8 < 8) {
      ppWVar6 = &DAT_1002a794;
    }
    FUN_100013a4(&local_54c,(LPBYTE)local_224,(LPCWSTR)ppWVar6,&local_558);
    ATL::CRegKey::Close((CRegKey *)&local_54c);
    piVar12 = (int *)(param_1 + 8);
    local_4e8 = &stack0xfffff974;
    piVar10 = extraout_ECX;
    FUN_1000d6aa(&stack0xfffff974,piVar12);
    local_8._0_1_ = 4;
    FUN_100141fe((wchar_t *)local_224,piVar10);
    if (*piVar12 != 0) {
      FUN_100147e9(&local_4e8);
      local_4c4 = (int *)0x0;
      local_8._0_1_ = 8;
      FUN_10003c48(local_448,L"/user_manager/users");
      local_8._0_1_ = 9;
      FUN_10014818(piVar12,local_448,(int *)&local_4c4);
      if (local_4c4 != (int *)0x0) {
        sVar7 = wcslen(L"./user");
        FID_conflict_assign(local_448,(undefined4 *)L"./user",sVar7);
        piVar10 = local_4c4;
        local_4d4 = (int *)0x0;
        local_8._0_1_ = 0xb;
        if (local_434 < 8) {
          local_448[0] = local_448;
        }
        if ((undefined4 ****)local_448[0] == (undefined4 ****)0x0) {
          local_4d0 = 0;
        }
        else {
          local_4d0 = Ordinal_2();
          if (local_4d0 == 0) {
LAB_100128f2:
                    /* WARNING: Subroutine does not return */
            FUN_100010d9(-0x7ff8fff2);
          }
        }
        local_8._0_1_ = 0xc;
        iVar5 = (**(code **)(*piVar10 + 0x90))();
        FUN_100045f1(local_514,iVar5);
        local_8 = CONCAT31(local_8._1_3_,0xb);
        Ordinal_6(local_4d0);
        if (local_4d4 != (int *)0x0) {
          local_520 = 0;
          (**(code **)(*local_4d4 + 0x20))();
          for (local_4e0 = 0; piVar10 = local_4d4, local_4e0 < local_520; local_4e0 = local_4e0 + 1)
          {
            local_4c0 = (int *)0x0;
            local_8 = CONCAT31((int3)((uint)local_8 >> 8),0xe);
            iVar5 = (**(code **)(*local_4d4 + 0x1c))(local_4d4);
            FUN_100045f1(local_514,iVar5);
            if ((-1 < local_508) &&
               ((**(code **)(*local_4c4 + 0x50))(local_4c4), piVar10 = local_4c0,
               local_4c0 != (int *)0x0)) {
              local_4c0 = (int *)0x0;
              (**(code **)(*piVar10 + 8))();
            }
            local_8 = CONCAT31((int3)((uint)local_8 >> 8),0xb);
            if (local_4c0 != (int *)0x0) {
              (**(code **)(*local_4c0 + 8))();
            }
          }
          if (local_4d4 != (int *)0x0) {
            local_4d4 = (int *)0x0;
            (**(code **)(*piVar10 + 8))();
          }
          piVar10 = local_4c4;
          if (local_4c4 != (int *)0x0) {
            local_4c4 = (int *)0x0;
            (**(code **)(*piVar10 + 8))();
          }
          iVar5 = local_4fc;
          FUN_10012044(&local_568);
          local_4ec = &stack0xfffff978;
          FUN_1000d6aa(&stack0xfffff978,(int *)(iVar5 + 8));
          local_8._1_3_ = (uint3)((uint)local_8 >> 8);
          local_8._0_1_ = 0xb;
          FUN_10013c60(&local_578);
          FUN_100147e9(&local_4d0);
          local_8._0_1_ = 0x11;
          FUN_10003c48(local_480,L"/user_manager/users");
          local_8 = CONCAT31(local_8._1_3_,0x12);
          FUN_10014818((int *)(iVar5 + 8),local_480,(int *)&local_4c4);
          if (local_4c4 != (int *)0x0) {
            local_500 = 0;
            local_4cc = DAT_1002a768;
            piVar10 = extraout_ECX_00;
LAB_100129c4:
            piVar12 = local_4c4;
            uVar4 = uStack_5bc;
            uVar3 = uStack_5c4;
            if (local_4cc != DAT_1002a76c) {
              local_4d8 = (int *)0x0;
              local_4dc = (int *)0x0;
              local_8._1_3_ = (uint3)((uint)local_8 >> 8);
              local_5c8 = CONCAT22(local_5c8._2_2_,3);
              uVar2 = local_5c8;
              local_5c0 = 1;
              local_8._0_1_ = 0x17;
              local_4c0 = *(int **)(local_4fc + 8);
              local_51c = Ordinal_2();
              if (local_51c != 0) {
                local_8._0_1_ = 0x18;
                local_528 = Ordinal_2();
                if (local_528 != 0) {
                  local_8._0_1_ = 0x19;
                  iVar5 = (**(code **)(*local_4c0 + 0xe0))(local_4c0,uVar2,uVar3,1,uVar4);
                  FUN_100045f1(local_514,iVar5);
                  local_8._0_1_ = 0x18;
                  Ordinal_6(local_528);
                  local_8._0_1_ = 0x17;
                  Ordinal_6(local_51c);
                  local_8._0_1_ = 0x16;
                  Ordinal_9(&local_5c8);
                  iVar5 = (**(code **)(*local_4c4 + 0x54))(local_4c4,local_4d8,&local_4dc);
                  FUN_100045f1(local_514,iVar5);
                  local_4c8 = (int *)0x0;
                  local_8._0_1_ = 0x1b;
                  iVar5 = (**(code **)*local_4dc)(local_4dc,&DAT_1001da9c,&local_4c8);
                  FUN_100045f1(local_514,iVar5);
                  pwVar8 = _ltow(local_500,local_42c,10);
                  FUN_10003c48(local_464,pwVar8);
                  local_8._0_1_ = 0x1c;
                  ppppuVar9 = (undefined4 ****)local_464[0];
                  if (local_450 < 8) {
                    ppppuVar9 = local_464;
                  }
                  local_588[0] = local_588[0] & 0xffff0000;
                  FUN_10001965(local_588,(int)ppppuVar9);
                  uVar1 = local_588[0];
                  local_8._0_1_ = 0x1d;
                  local_4c0 = local_4c8;
                  local_518 = Ordinal_2(&DAT_1001dc44);
                  if (local_518 != 0) {
                    local_8._0_1_ = 0x1e;
                    iVar5 = (**(code **)(*local_4c0 + 0xb4))(local_4c0,local_518,uVar1);
                    FUN_100045f1(local_514,iVar5);
                    local_8._0_1_ = 0x1d;
                    Ordinal_6(local_518);
                    local_598[0] = local_598[0] & 0xffff0000;
                    FUN_10001965(local_598,*local_4cc);
                    uVar1 = local_598[0];
                    local_8._0_1_ = 0x1f;
                    local_4c0 = local_4c8;
                    local_538 = Ordinal_2(L"name");
                    if (local_538 != 0) {
                      local_8._0_1_ = 0x20;
                      iVar5 = (**(code **)(*local_4c0 + 0xb4))(local_4c0,local_538,uVar1);
                      FUN_100045f1(local_514,iVar5);
                      local_8._0_1_ = 0x1f;
                      Ordinal_6(local_538);
                      local_8._0_1_ = 0x1d;
                      Ordinal_9(local_598);
                      local_5a8[0] = local_5a8[0] & 0xffff0000;
                      FUN_10001965(local_5a8,local_4cc[1]);
                      uVar1 = local_5a8[0];
                      local_8._0_1_ = 0x21;
                      local_4c0 = local_4c8;
                      local_530 = Ordinal_2(L"password");
                      if (local_530 != 0) {
                        local_8._0_1_ = 0x22;
                        iVar5 = (**(code **)(*local_4c0 + 0xb4))(local_4c0,local_530,uVar1);
                        FUN_100045f1(local_514,iVar5);
                        local_8._0_1_ = 0x21;
                        Ordinal_6(local_530);
                        local_8._0_1_ = 0x1d;
                        Ordinal_9(local_5a8);
                        local_5b8[0] = local_5b8[0] & 0xffff0000;
                        FUN_10001965(local_5b8,local_4cc[2]);
                        uVar1 = local_5b8[0];
                        local_8._0_1_ = 0x23;
                        local_4c0 = local_4c8;
                        local_524 = Ordinal_2(L"group");
                        if (local_524 != 0) {
                          local_8._0_1_ = 0x24;
                          iVar5 = (**(code **)(*local_4c0 + 0xb4))(local_4c0,local_524,uVar1);
                          FUN_100045f1(local_514,iVar5);
                          local_8._0_1_ = 0x23;
                          Ordinal_6(local_524);
                          local_8._0_1_ = 0x1d;
                          Ordinal_9(local_5b8);
                          pcVar11 = Ordinal_2_exref;
                          for (piVar10 = local_568; piVar12 = local_578, local_4e4 = piVar10,
                              piVar10 != local_564; piVar10 = piVar10 + 3) {
                            if (local_580 == 0) {
                              local_4f0 = 0;
                            }
                            else {
                              local_4f0 = Ordinal_2();
                              if (local_4f0 == 0) goto LAB_100128f2;
                            }
                            local_8._0_1_ = 0x25;
                            local_4b9 = FUN_10001821(&local_4f0,*piVar10);
                            local_8._0_1_ = 0x1d;
                            Ordinal_6();
                            if (local_4b9 != '\0') {
                              local_5d8[0] = local_5d8[0] & 0xffff0000;
                              FUN_10001965(local_5d8,local_4e4[1]);
                              uVar1 = local_5d8[0];
                              local_8._0_1_ = 0x26;
                              local_4c0 = local_4c8;
                              local_52c = Ordinal_2();
                              if (local_52c == 0) goto LAB_100128f2;
                              local_8._0_1_ = 0x27;
                              iVar5 = (**(code **)(*local_4c0 + 0xb4))(local_4c0,local_52c,uVar1);
                              FUN_100045f1(local_514,iVar5);
                              local_8._0_1_ = 0x26;
                              Ordinal_6(local_52c);
                              local_8._0_1_ = 0x1d;
                              Ordinal_9(local_5d8);
                              FUN_10003a9c(&local_568,&local_554,local_4e4);
                              piVar12 = local_578;
                              pcVar11 = Ordinal_2_exref;
                              break;
                            }
                          }
                          do {
                            local_550 = piVar12;
                            if (piVar12 == local_574) goto LAB_10013011;
                            if (piVar12[2] == 0) {
                              local_4f8 = 0;
                            }
                            else {
                              local_4f8 = (*pcVar11)();
                              if (local_4f8 == 0) break;
                            }
                            local_8._0_1_ = 0x28;
                            if (local_4cc[2] == 0) {
                              local_4f4 = 0;
                            }
                            else {
                              local_4f4 = (*pcVar11)();
                              if (local_4f4 == 0) break;
                            }
                            local_8._0_1_ = 0x29;
                            local_4b9 = ATL::CComBSTR::operator==
                                                  ((CComBSTR *)&local_4f4,(CComBSTR *)&local_4f8);
                            local_8._0_1_ = 0x28;
                            Ordinal_6();
                            local_8._0_1_ = 0x1d;
                            Ordinal_6();
                            if (local_4b9 != '\0') {
                              if (*piVar12 == 0) {
                                local_504 = 0;
                              }
                              else {
                                local_504 = (*pcVar11)();
                                if (local_504 == 0) break;
                              }
                              local_8._0_1_ = 0x2a;
                              local_540 = (wchar_t *)FUN_10001718(&local_504);
                              local_8._0_1_ = 0x1d;
                              Ordinal_6();
                              goto LAB_10013011;
                            }
                            piVar12 = piVar12 + 3;
                          } while( true );
                        }
                      }
                    }
                  }
                }
              }
              goto LAB_100128f2;
            }
            if (local_4c4 != (int *)0x0) {
              local_4c4 = (int *)0x0;
              (**(code **)(*piVar12 + 8))();
              piVar10 = extraout_ECX_05;
            }
            local_554 = &stack0xfffff974;
            FUN_1000d6aa(&stack0xfffff974,(int *)(local_4fc + 8));
            local_8 = CONCAT31((int3)((uint)local_8 >> 8),0x12);
            FUN_10014502(local_224,piVar10);
          }
          local_8._0_1_ = 0x11;
          FID_conflict__Tidy(local_480,'\x01',0);
          local_8 = CONCAT31(local_8._1_3_,0xb);
          FUN_100147f2(&local_4d0);
        }
        local_8._1_3_ = (uint3)((uint)local_8 >> 8);
        local_8._0_1_ = 9;
        if (local_4d4 != (int *)0x0) {
          (**(code **)(*local_4d4 + 8))();
        }
      }
      local_8._0_1_ = 8;
      FID_conflict__Tidy(local_448,'\x01',0);
      local_8._0_1_ = 6;
      if (local_4c4 != (int *)0x0) {
        (**(code **)(*local_4c4 + 8))();
      }
      local_8._0_1_ = 4;
      FUN_100147f2(&local_4e8);
    }
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  ATL::CRegKey::Close((CRegKey *)&local_54c);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_1000df2a((_Container_base0 *)&local_568);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1000df2a((_Container_base0 *)&local_578);
  local_8 = 0xffffffff;
  FUN_10014f93();
  return;
LAB_10013011:
  local_5f8[0] = local_5f8[0] & 0xffff0000;
  FUN_10001965(local_5f8,(int)local_540);
  uVar1 = local_5f8[0];
  local_8._0_1_ = 0x2b;
  local_4c0 = local_4c8;
  local_534 = Ordinal_2();
  if (local_534 == 0) goto LAB_100128f2;
  local_8._0_1_ = 0x2c;
  iVar5 = (**(code **)(*local_4c0 + 0xb4))(local_4c0,local_534,uVar1);
  FUN_100045f1(local_514,iVar5);
  local_8._0_1_ = 0x2b;
  Ordinal_6(local_534);
  local_8._0_1_ = 0x1d;
  Ordinal_9(local_5f8);
  this = FUN_10003c48(local_4b8,L"0");
  local_8._0_1_ = 0x2d;
  pwVar8 = FUN_10003d3e(local_49c,local_540);
  local_8._0_1_ = 0x2e;
  if (7 < *(uint *)(pwVar8 + 10)) {
    pwVar8 = *(wchar_t **)pwVar8;
  }
  iVar5 = FUN_1000217f(this,pwVar8);
  local_4b9 = '\x01' - (iVar5 != 0);
  local_8._0_1_ = 0x2d;
  FID_conflict__Tidy(local_49c,'\x01',0);
  local_8._0_1_ = 0x1d;
  FID_conflict__Tidy(local_4b8,'\x01',0);
  if (local_4b9 != '\0') {
    local_4ec = (undefined1 *)Ordinal_2(L"System Administrators");
    if (local_4ec == (undefined1 *)0x0) goto LAB_100128f2;
    local_8._0_1_ = 0x2f;
    local_5e8[0] = local_5e8[0] & 0xffff0000;
    FUN_1000191a(local_5e8,(int *)&local_4ec);
    uVar1 = local_5e8[0];
    local_8._0_1_ = 0x30;
    local_4c0 = local_4c8;
    local_53c = Ordinal_2();
    if (local_53c == 0) goto LAB_100128f2;
    local_8._0_1_ = 0x31;
    (**(code **)(*local_4c0 + 0xb4))(local_4c0,local_53c,uVar1);
    local_8._0_1_ = 0x30;
    Ordinal_6(local_53c);
    local_8._0_1_ = 0x2f;
    Ordinal_9(local_5e8);
    local_8._0_1_ = 0x1d;
    Ordinal_6(local_4ec);
  }
  piVar10 = local_4c8;
  if (local_4c8 != (int *)0x0) {
    local_4c8 = (int *)0x0;
    (**(code **)(*piVar10 + 8))(piVar10);
  }
  piVar10 = local_4dc;
  if (local_4dc != (int *)0x0) {
    local_4dc = (int *)0x0;
    (**(code **)(*piVar10 + 8))(piVar10);
  }
  piVar10 = local_4d8;
  if (local_4d8 != (int *)0x0) {
    local_4d8 = (int *)0x0;
    (**(code **)(*piVar10 + 8))(piVar10);
  }
  local_8._0_1_ = 0x1c;
  Ordinal_9(local_588);
  local_8._0_1_ = 0x1b;
  FID_conflict__Tidy(local_464,'\x01',0);
  local_8._0_1_ = 0x16;
  piVar10 = extraout_ECX_01;
  if (local_4c8 != (int *)0x0) {
    (**(code **)(*local_4c8 + 8))();
    piVar10 = extraout_ECX_02;
  }
  local_8._0_1_ = 0x14;
  if (local_4dc != (int *)0x0) {
    (**(code **)(*local_4dc + 8))();
    piVar10 = extraout_ECX_03;
  }
  local_8 = CONCAT31(local_8._1_3_,0x12);
  if (local_4d8 != (int *)0x0) {
    (**(code **)(*local_4d8 + 8))();
    piVar10 = extraout_ECX_04;
  }
  local_4cc = local_4cc + 3;
  local_500 = local_500 + 1;
  goto LAB_100129c4;
}



// Function: Catch@100133b3 at 100133b3

undefined4 Catch_100133b3(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return 0x1001338b;
}



// Function: FUN_100133c0 at 100133c0

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100133c0(int *param_1,wchar_t *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_2c [3];
  undefined4 local_20;
  int local_1c;
  undefined4 *local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x100133cc;
  FUN_10001c46(local_2c);
  local_8 = 0;
  FUN_100045f1(local_2c,0);
  local_8 = CONCAT31(local_8._1_3_,1);
  local_1c = 0;
  puVar2 = DAT_1002a768;
  while( true ) {
    local_18 = puVar2;
    if (puVar2 == DAT_1002a76c) {
      iVar1 = (**(code **)(*param_1 + 0x34))(param_1,param_2,param_3,param_4);
      FUN_100045f1(local_2c,iVar1);
      FUN_10012621((int)param_1);
      return local_20;
    }
    iVar1 = _wcsicmp((wchar_t *)*puVar2,param_2);
    if (iVar1 == 0) break;
    puVar2 = puVar2 + 3;
    local_1c = local_1c + 1;
  }
  local_8 = 0xffffffff;
  FUN_100012a2(local_2c);
  return 1;
}



// Function: Catch@1001345f at 1001345f

undefined4 Catch_1001345f(void)

{
  int unaff_EBP;
  
  FUN_100045f1((void *)(unaff_EBP + -0x28),-0x7fffbffb);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10013450;
}



// Function: FUN_10013476 at 10013476

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10013476(int param_1,int param_2,wchar_t *param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 local_2c [3];
  undefined4 local_20;
  int local_1c;
  undefined4 *local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x10013482;
  FUN_10001c46(local_2c);
  local_8 = 0;
  FUN_100045f1(local_2c,0);
  local_8 = CONCAT31(local_8._1_3_,1);
  local_1c = 0;
  for (local_18 = DAT_1002a768; local_18 != DAT_1002a76c; local_18 = local_18 + 3) {
    if ((local_1c != param_2) && (iVar1 = _wcsicmp((wchar_t *)*local_18,param_3), iVar1 == 0)) {
      local_8 = 0xffffffff;
      FUN_100012a2(local_2c);
      return 1;
    }
    local_1c = local_1c + 1;
  }
  local_1c = 0;
  puVar3 = DAT_1002a768;
  do {
    local_18 = puVar3;
    if (puVar3 == DAT_1002a76c) {
LAB_100135b1:
      FUN_10012621(param_1);
      return local_20;
    }
    if (local_1c == param_2) {
      if (param_3 == (wchar_t *)0x0) {
        param_3 = (wchar_t *)0x0;
      }
      else {
        param_3 = (wchar_t *)Ordinal_2(param_3);
        if (param_3 == (wchar_t *)0x0) goto LAB_1001354d;
      }
      local_8._0_1_ = 2;
      uVar2 = FUN_10001718((int *)&param_3);
      *puVar3 = uVar2;
      local_8 = CONCAT31(local_8._1_3_,1);
      Ordinal_6(param_3);
      if (param_4 == 0) {
        param_2 = 0;
      }
      else {
        param_2 = Ordinal_2(param_4);
        if (param_2 == 0) goto LAB_1001354d;
      }
      local_8._0_1_ = 3;
      uVar2 = FUN_10001718(&param_2);
      puVar3[1] = uVar2;
      local_8 = CONCAT31(local_8._1_3_,1);
      Ordinal_6(param_2);
      if (param_5 == 0) {
        param_4 = 0;
      }
      else {
        param_4 = Ordinal_2(param_5);
        if (param_4 == 0) {
LAB_1001354d:
                    /* WARNING: Subroutine does not return */
          FUN_100010d9(-0x7ff8fff2);
        }
      }
      local_8._0_1_ = 4;
      uVar2 = FUN_10001718(&param_4);
      puVar3[2] = uVar2;
      local_8 = CONCAT31(local_8._1_3_,1);
      Ordinal_6(param_4);
      goto LAB_100135b1;
    }
    puVar3 = puVar3 + 3;
    local_1c = local_1c + 1;
  } while( true );
}



// Function: Catch@100135d9 at 100135d9

undefined4 Catch_100135d9(void)

{
  int unaff_EBP;
  
  FUN_100045f1((void *)(unaff_EBP + -0x28),-0x7fffbffb);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x100135bc;
}



// Function: FUN_100135f0 at 100135f0

int * __thiscall FUN_100135f0(void *this,int param_1)

{
  int iVar1;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 1;
  iVar1 = Ordinal_2(param_1);
  *(int *)this = iVar1;
  if ((iVar1 == 0) && (param_1 != 0)) {
    FUN_10015cd0(0x8007000e);
  }
  return (int *)this;
}



// Function: FUN_10013626 at 10013626

int __fastcall FUN_10013626(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*param_1 != 0) {
    uVar1 = Ordinal_149(*param_1);
    iVar2 = Ordinal_150(*param_1,uVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
    FUN_10015cd0(0x8007000e);
  }
  return 0;
}



// Function: FUN_10013651 at 10013651

void __fastcall FUN_10013651(int *param_1)

{
  if (*param_1 != 0) {
    Ordinal_6(*param_1);
  }
  if ((void *)param_1[1] != (void *)0x0) {
    operator_delete__((void *)param_1[1]);
  }
  return;
}



// Function: _AtlGetStringResourceImage at 10013671

/* Library Function - Single Match
    struct ATL::ATLSTRINGRESOURCEIMAGE const * __cdecl ATL::_AtlGetStringResourceImage(struct
   HINSTANCE__ *,struct HRSRC__ *,unsigned int)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

ATLSTRINGRESOURCEIMAGE * __cdecl
ATL::_AtlGetStringResourceImage(HINSTANCE__ *param_1,HRSRC__ *param_2,uint param_3)

{
  HGLOBAL hResData;
  ushort *puVar1;
  DWORD DVar2;
  ushort *puVar3;
  uint uVar4;
  
  hResData = LoadResource(param_1,param_2);
  if (hResData == (HGLOBAL)0x0) {
    return (ATLSTRINGRESOURCEIMAGE *)0x0;
  }
  puVar1 = (ushort *)LockResource(hResData);
  if (puVar1 != (ushort *)0x0) {
    DVar2 = SizeofResource(param_1,param_2);
    puVar3 = (ushort *)(DVar2 + (int)puVar1);
    for (uVar4 = param_3 & 0xf; uVar4 != 0; uVar4 = uVar4 - 1) {
      if (puVar3 <= puVar1) {
        return (ATLSTRINGRESOURCEIMAGE *)0x0;
      }
      puVar1 = puVar1 + *puVar1 + 1;
    }
    if (puVar1 < puVar3) {
      return (ATLSTRINGRESOURCEIMAGE *)(-(uint)(*puVar1 != 0) & (uint)puVar1);
    }
  }
  return (ATLSTRINGRESOURCEIMAGE *)0x0;
}



// Function: AtlGetStringResourceImage at 100136cc

/* Library Function - Single Match
    struct ATL::ATLSTRINGRESOURCEIMAGE const * __cdecl ATL::AtlGetStringResourceImage(struct
   HINSTANCE__ *,unsigned int)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release */

ATLSTRINGRESOURCEIMAGE * __cdecl ATL::AtlGetStringResourceImage(HINSTANCE__ *param_1,uint param_2)

{
  HRSRC pHVar1;
  ATLSTRINGRESOURCEIMAGE *pAVar2;
  
  pHVar1 = FindResourceW(param_1,(LPCWSTR)((param_2 >> 4) + 1 & 0xffff),(LPCWSTR)0x6);
  if (pHVar1 == (HRSRC)0x0) {
    return (ATLSTRINGRESOURCEIMAGE *)0x0;
  }
  pAVar2 = _AtlGetStringResourceImage(param_1,pHVar1,param_2);
  return pAVar2;
}



// Function: FUN_100136fc at 100136fc

ATLSTRINGRESOURCEIMAGE * __cdecl FUN_100136fc(uint param_1)

{
  HINSTANCE__ *pHVar1;
  ATLSTRINGRESOURCEIMAGE *pAVar2;
  int iVar3;
  
  pAVar2 = (ATLSTRINGRESOURCEIMAGE *)0x0;
  pHVar1 = ATL::CAtlBaseModule::GetHInstanceAt((CAtlBaseModule *)&DAT_1002afd4,0);
  iVar3 = 1;
  while ((pHVar1 != (HINSTANCE__ *)0x0 && (pAVar2 == (ATLSTRINGRESOURCEIMAGE *)0x0))) {
    pAVar2 = ATL::AtlGetStringResourceImage(pHVar1,param_1);
    pHVar1 = ATL::CAtlBaseModule::GetHInstanceAt((CAtlBaseModule *)&DAT_1002afd4,iVar3);
    iVar3 = iVar3 + 1;
  }
  return pAVar2;
}



// Function: FUN_1001373b at 1001373b

bool __cdecl FUN_1001373b(uint param_1,int *param_2)

{
  ATLSTRINGRESOURCEIMAGE *pAVar1;
  int iVar2;
  
  pAVar1 = FUN_100136fc(param_1);
  if (pAVar1 == (ATLSTRINGRESOURCEIMAGE *)0x0) {
    *param_2 = 0;
  }
  else {
    iVar2 = Ordinal_4(pAVar1 + 2,*(undefined2 *)pAVar1);
    *param_2 = iVar2;
  }
  return *param_2 != 0;
}



// Function: FUN_1001376e at 1001376e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1001376e(void *this,int param_1)

{
  void *this_00;
  int *piVar1;
  
  this_00 = operator_new(0xc);
  if (this_00 == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = FUN_100135f0(this_00,param_1);
  }
  *(int **)this = piVar1;
  if (piVar1 == (int *)0x0) {
    FUN_10015cd0(0x8007000e);
  }
  return (undefined4 *)this;
}



// Function: FUN_100137bb at 100137bb

void __thiscall FUN_100137bb(void *this,uint param_1)

{
                    /* WARNING: Load size is inaccurate */
  Ordinal_6(*this);
  *(undefined4 *)this = 0;
  FUN_1001373b(param_1,(int *)this);
  return;
}



// Function: FUN_100137dc at 100137dc

LONG __fastcall FUN_100137dc(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 2);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    FUN_10013651(param_1);
    operator_delete(param_1);
  }
  return LVar1;
}



// Function: FUN_10013807 at 10013807

void __fastcall FUN_10013807(undefined4 *param_1)

{
  if ((int *)*param_1 != (int *)0x0) {
    FUN_100137dc((int *)*param_1);
    *param_1 = 0;
  }
  return;
}



// Function: FUN_1001381a at 1001381a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_1001381a(void *this,int param_1)

{
  int iVar1;
  void *this_00;
  int *piVar2;
  
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
    FUN_100137dc(*this);
    *(undefined4 *)this = 0;
  }
  this_00 = operator_new(0xc);
  if (this_00 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_100135f0(this_00,param_1);
  }
  *(int **)this = piVar2;
  if (piVar2 == (int *)0x0) {
    FUN_10015cd0(0x8007000e);
  }
  return (int *)this;
}



// Function: FUN_1001388c at 1001388c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __cdecl FUN_1001388c(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  iVar2 = Ordinal_2(param_2);
  FUN_1001381a(local_14,iVar2);
  piVar1 = local_14[0];
  if (local_14[0] == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_10013626(local_14[0]);
  }
  *param_1 = iVar2;
  if (piVar1 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *piVar1;
  }
  Ordinal_6(iVar2);
  local_8 = 0xffffffff;
  if (piVar1 != (int *)0x0) {
    FUN_100137dc(piVar1);
  }
  return;
}



// Function: FUN_100138f3 at 100138f3

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_100138f3(void)

{
  undefined4 uVar1;
  int iVar2;
  LPCWSTR *ppWVar3;
  LSTATUS LVar4;
  size_t sVar5;
  uint uVar6;
  uint uVar7;
  wchar_t *****pppppwVar8;
  LPCWSTR lpLibFileName;
  HMODULE Value;
  undefined4 *in_stack_00000020;
  undefined4 local_4bc [4];
  undefined4 *local_4ac;
  ushort local_4a8 [4];
  undefined4 local_4a0;
  undefined4 local_49c;
  undefined4 local_498;
  undefined4 local_494;
  undefined4 local_490;
  undefined4 local_48c;
  undefined4 local_488;
  DWORD local_484;
  LPCWSTR ***local_480 [5];
  uint local_46c;
  wchar_t ****local_464 [4];
  undefined4 *local_454;
  uint local_450;
  undefined4 local_448;
  undefined4 local_438;
  uint local_434;
  wchar_t local_42c [260];
  wchar_t local_224;
  undefined1 local_222 [538];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x4ac;
  local_4ac = in_stack_00000020;
  local_8 = 0;
  FUN_10001c2c(local_4bc);
  local_494 = 0;
  local_490 = 0;
  local_48c = 0;
  local_434 = 7;
  local_438 = 0;
  local_448 = (LPCWSTR)((uint)local_448._2_2_ << 0x10);
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 4;
  basic_string<>(local_480,(undefined4 *)&DAT_1002a9b4);
  local_8._0_1_ = 5;
  if (local_46c < 8) {
    local_480[0] = (LPCWSTR ***)local_480;
  }
  iVar2 = Open(&local_494,(HKEY)0x80000002,(LPCWSTR)local_480[0],0x2001f);
  if (iVar2 == 0) {
    local_224 = L'\0';
    memset(local_222,0,0x208);
    local_484 = 0x20a;
    ppWVar3 = (LPCWSTR *)DAT_1002a9d0;
    if (DAT_1002a9e4 < 8) {
      ppWVar3 = &DAT_1002a9d0;
    }
    LVar4 = FUN_100013a4(&local_494,(LPBYTE)&local_224,(LPCWSTR)ppWVar3,&local_484);
    if (LVar4 == 0) {
      local_4a0 = 0;
      local_49c = 0;
      local_498 = 0;
      local_8._0_1_ = 6;
      iVar2 = Open(&local_4a0,(HKEY)0x80000002,
                   L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\CS\\Locale",0x2001f);
      if (iVar2 == 0) {
        local_450 = 7;
        local_454 = (undefined4 *)0x0;
        local_464[0] = (wchar_t ****)((uint)local_464[0] & 0xffff0000);
        local_8 = CONCAT31(local_8._1_3_,7);
        local_484 = 0x208;
        LVar4 = FUN_100013a4(&local_4a0,(LPBYTE)local_42c,L"LanguageExt",&local_484);
        if (LVar4 == 0) {
          sVar5 = wcslen(&local_224);
          FID_conflict_assign(&local_448,(undefined4 *)&local_224,sVar5);
          sVar5 = wcslen(local_42c);
          FID_conflict_assign(local_464,(undefined4 *)local_42c,sVar5);
          local_4a8[0] = 0x5f;
          local_4a8[1] = 0;
          uVar6 = FUN_100019f9(&local_448,local_4a8,0xffffffff,1);
          local_4a8[2] = 0x2e;
          local_4a8[3] = 0;
          uVar7 = FUN_100019f9(&local_448,local_4a8 + 2,0xffffffff,1);
          if ((uVar6 != 0xffffffff) && ((undefined4 *)((uVar7 - uVar6) + -1) == local_454)) {
            pppppwVar8 = (wchar_t *****)local_464[0];
            if (local_450 < 8) {
              pppppwVar8 = local_464;
            }
            FUN_10003a3d(&local_448,uVar6 + 1,local_454,(wchar_t *)pppppwVar8);
          }
        }
        ATL::CRegKey::Close((CRegKey *)&local_4a0);
        local_8._0_1_ = 6;
        FID_conflict__Tidy(local_464,'\x01',0);
      }
      ATL::CRegKey::Close((CRegKey *)&local_494);
      lpLibFileName = local_448;
      if (local_434 < 8) {
        lpLibFileName = (LPCWSTR)&local_448;
      }
      Value = LoadLibraryW(lpLibFileName);
      if (Value != (HMODULE)0x0) {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1002b038);
        InterlockedExchange((LONG *)&DAT_1002afdc,(LONG)Value);
        DAT_1002afd8 = Value;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1002b038);
      }
      local_8._0_1_ = 5;
      ATL::CRegKey::Close((CRegKey *)&local_4a0);
    }
    local_488 = 0;
    local_8 = CONCAT31(local_8._1_3_,8);
    uVar6 = FUN_10001fa0((wchar_t *)&stack0x00000004);
    FUN_100137bb(&local_488,uVar6);
    uVar1 = local_488;
    *local_4ac = local_488;
    if (DAT_1002afdc != (HMODULE)0x0) {
      FreeLibrary(DAT_1002afdc);
    }
    local_8._0_1_ = 5;
    Ordinal_6(uVar1);
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  FID_conflict__Tidy(local_480,'\x01',0);
  local_8 = 3;
  FUN_10013c2a();
  return;
}



// Function: Catch@10013c1b at 10013c1b

undefined * Catch_10013c1b(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 3;
  return &DAT_10013c28;
}



// Function: FUN_10013c2a at 10013c2a

void FUN_10013c2a(void)

{
  int unaff_EBX;
  int unaff_EBP;
  
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FID_conflict__Tidy((void *)(unaff_EBP + -0x444),'\x01',unaff_EBX);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x490));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FID_conflict__Tidy((void *)(unaff_EBP + 8),'\x01',unaff_EBX);
  FUN_10014f93();
  return;
}



// Function: FUN_10013c60 at 10013c60

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10013c60(void *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  size_t sVar4;
  undefined4 *puVar5;
  wchar_t *_Str;
  undefined1 auStack_16c [12];
  undefined4 uStack_160;
  int local_138;
  undefined4 local_134;
  int local_130;
  undefined4 local_12c [3];
  int local_120;
  int local_11c;
  undefined1 *local_118;
  wchar_t *local_114;
  int local_110;
  undefined4 local_10c;
  int *local_108;
  int *local_104;
  int *local_100;
  int *local_fc;
  undefined1 local_f8 [28];
  undefined2 local_dc [14];
  undefined1 local_c0 [28];
  undefined1 local_a4 [28];
  undefined4 local_88 [4];
  undefined4 local_78;
  undefined4 local_74;
  undefined4 ***local_6c [5];
  uint local_58;
  uint local_50 [4];
  undefined4 local_40;
  undefined4 local_3c;
  uint local_34 [4];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 300;
  local_8 = 0;
  FUN_10001c2c(local_12c);
  local_104 = (int *)0x0;
  local_100 = (int *)0x0;
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_fc = (int *)0x0;
  local_8._0_1_ = 7;
  FUN_100147e9(&local_10c);
  local_8._0_1_ = 8;
  local_114 = (wchar_t *)0x0;
  FUN_10003c48(local_6c,L"/user_manager/groups");
  local_8 = CONCAT31(local_8._1_3_,10);
  iVar3 = FUN_10014818((int *)&stack0x00000008,local_6c,(int *)&local_104);
  FUN_100045f1(local_12c,iVar3);
  if ((local_104 != (int *)0x0) && (-1 < local_120)) {
    sVar4 = wcslen(L"./group");
    FID_conflict_assign(local_6c,(undefined4 *)L"./group",sVar4);
    piVar1 = local_104;
    if (local_58 < 8) {
      local_6c[0] = local_6c;
    }
    if ((undefined4 ****)local_6c[0] == (undefined4 ****)0x0) {
      local_118 = (undefined1 *)0x0;
    }
    else {
      local_118 = (undefined1 *)Ordinal_2();
      if (local_118 == (undefined1 *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_100010d9(-0x7ff8fff2);
      }
    }
    local_8._0_1_ = 0xb;
    iVar3 = (**(code **)(*piVar1 + 0x90))();
    uStack_160 = 0x10013d74;
    FUN_100045f1(local_12c,iVar3);
    local_8 = CONCAT31(local_8._1_3_,10);
    uStack_160 = 0x10013d86;
    Ordinal_6();
    if ((local_100 != (int *)0x0) && (-1 < local_120)) {
      local_11c = 0;
      iVar3 = (**(code **)(*local_100 + 0x20))();
      FUN_100045f1(local_12c,iVar3);
      if ((-1 < local_120) && (local_11c != 0)) {
        local_138 = 0;
        local_134 = 0;
        local_130 = 0;
        for (local_110 = 0; local_110 < local_11c; local_110 = local_110 + 1) {
          iVar3 = (**(code **)(*local_100 + 0x1c))();
          FUN_100045f1(local_12c,iVar3);
          if (-1 < local_120) {
            local_3c = 7;
            local_40 = 0;
            local_50[0] = local_50[0] & 0xffff0000;
            local_74 = 7;
            local_78 = 0;
            local_88[0]._0_2_ = 0;
            local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
            local_20 = 7;
            local_24 = 0;
            local_34[0] = local_34[0] & 0xffff0000;
            local_8._0_1_ = 0xe;
            puVar5 = (undefined4 *)FUN_10003c48(local_c0,L"ID");
            local_8._0_1_ = 0xf;
            FUN_10014899((int *)&local_fc,puVar5,local_50);
            local_8._0_1_ = 0xe;
            FID_conflict__Tidy(local_c0,'\x01',0);
            puVar5 = (undefined4 *)FUN_10003c48(local_f8,L"name");
            local_8._0_1_ = 0x10;
            FUN_10014899((int *)&local_fc,puVar5,local_34);
            local_8._0_1_ = 0xe;
            FID_conflict__Tidy(local_f8,'\x01',0);
            puVar5 = (undefined4 *)FUN_10003c48(local_a4,L"resGroupId");
            local_8._0_1_ = 0x11;
            iVar3 = FUN_10014899((int *)&local_fc,puVar5,local_88);
            FUN_100045f1(local_12c,iVar3);
            local_8._0_1_ = 0xe;
            FID_conflict__Tidy(local_a4,'\x01',0);
            if (local_120 == 0) {
              local_118 = auStack_16c;
              basic_string<>(auStack_16c,local_88);
              local_8._0_1_ = 0xe;
              FUN_100138f3();
              _Str = FUN_10003d3e(local_dc,local_114);
              local_8._0_1_ = 0x13;
              if (7 < *(uint *)(_Str + 10)) {
                _Str = *(wchar_t **)_Str;
              }
              sVar4 = wcslen(_Str);
              FID_conflict_assign(local_34,(undefined4 *)_Str,sVar4);
              local_8._0_1_ = 0xe;
              FID_conflict__Tidy(local_dc,'\x01',0);
            }
            FUN_1001376e(&local_108,0);
            local_8 = CONCAT31(local_8._1_3_,0x14);
            iVar3 = Ordinal_2();
            FUN_1001381a(&local_108,iVar3);
            if (local_108 == (int *)0x0) {
              local_138 = 0;
            }
            else {
              local_138 = FUN_10013626(local_108);
            }
            Ordinal_6();
            iVar3 = Ordinal_2();
            uStack_160 = 0x10014041;
            FUN_1001381a(&local_108,iVar3);
            piVar1 = local_108;
            if (local_108 == (int *)0x0) {
              local_130 = 0;
            }
            else {
              local_130 = FUN_10013626(local_108);
            }
            uStack_160 = 0x10014069;
            Ordinal_6();
            if ((local_138 != 0) && (local_130 != 0)) {
              FUN_1000e1a0(param_1,&local_138);
            }
            piVar2 = local_fc;
            if (local_fc != (int *)0x0) {
              local_fc = (int *)0x0;
              (**(code **)(*piVar2 + 8))();
            }
            local_8._0_1_ = 0xe;
            if (piVar1 != (int *)0x0) {
              FUN_100137dc(piVar1);
              local_108 = (int *)0x0;
            }
            local_8._0_1_ = 0xd;
            FID_conflict__Tidy(local_34,'\x01',0);
            local_8._0_1_ = 0xc;
            FID_conflict__Tidy(local_88,'\x01',0);
            local_8 = CONCAT31(local_8._1_3_,10);
            FID_conflict__Tidy(local_50,'\x01',0);
          }
        }
      }
      piVar1 = local_100;
      if (local_100 != (int *)0x0) {
        local_100 = (int *)0x0;
        (**(code **)(*piVar1 + 8))();
      }
    }
    piVar1 = local_104;
    if (local_104 != (int *)0x0) {
      local_104 = (int *)0x0;
      (**(code **)(*piVar1 + 8))();
    }
  }
  local_8 = 9;
  FUN_1001418d();
  return;
}



// Function: Catch@10014126 at 10014126

undefined * Catch_10014126(void)

{
  int *piVar1;
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x110) != 0) {
    operator_delete__(*(void **)(unaff_EBP + -0x110));
  }
  piVar1 = *(int **)(unaff_EBP + -0xf8);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)(unaff_EBP + -0xf8) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(unaff_EBP + -0xfc);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)(unaff_EBP + -0xfc) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(unaff_EBP + -0x100);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)(unaff_EBP + -0x100) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined4 *)(unaff_EBP + -4) = 9;
  return &DAT_1001418b;
}



// Function: FUN_1001418d at 1001418d

void FUN_1001418d(void)

{
  int *piVar1;
  int unaff_EBP;
  int *unaff_ESI;
  
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FID_conflict__Tidy((void *)(unaff_EBP + -0x68),'\x01',(int)unaff_ESI);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_100147f2((undefined4 *)(unaff_EBP + -0x108));
  *(undefined1 *)(unaff_EBP + -4) = 5;
  piVar1 = *(int **)(unaff_EBP + -0xf8);
  if (piVar1 != unaff_ESI) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined1 *)(unaff_EBP + -4) = 3;
  piVar1 = *(int **)(unaff_EBP + -0xfc);
  if (piVar1 != unaff_ESI) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  piVar1 = *(int **)(unaff_EBP + -0x100);
  if (piVar1 != unaff_ESI) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  piVar1 = *(int **)(unaff_EBP + 0xc);
  if (piVar1 != unaff_ESI) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_10014f93();
  return;
}



// Function: FUN_100141fe at 100141fe

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_100141fe(wchar_t *param_1,int *param_2)

{
  int *piVar1;
  ushort uVar2;
  size_t sVar3;
  int iVar4;
  undefined4 *puVar5;
  FILE *_File;
  FILE *_File_00;
  HRESULT HVar6;
  wchar_t *pwVar7;
  undefined4 local_90 [4];
  undefined4 local_80;
  int local_7c;
  int local_78;
  int *local_74;
  int *local_70;
  undefined1 local_6c [28];
  undefined1 local_50 [12];
  uint local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 local_24;
  uint local_20;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x80;
  local_8 = 0;
  FUN_10001c46(local_90);
  local_8._0_1_ = 1;
  FUN_100045f1(local_90,0);
  local_20 = 7;
  local_24 = 0;
  local_34 = (wchar_t *)((uint)local_34._2_2_ << 0x10);
  local_8._0_1_ = 3;
  FUN_10003c48(local_6c,param_1);
  local_8._0_1_ = 4;
  sVar3 = wcslen(L"\\");
  iVar4 = FUN_10001d91(local_6c,(short *)&DAT_1001dc40,0xffffffff,sVar3);
  if (iVar4 != -1) {
    puVar5 = (undefined4 *)FUN_10003a63(local_6c,local_50,0,iVar4 + 1);
    local_8._0_1_ = 5;
    FUN_10003c7a(&local_34,puVar5);
    local_8._0_1_ = 4;
    FID_conflict__Tidy(local_50,'\x01',0);
    sVar3 = wcslen(L"temp.xml");
    FUN_10003105(&local_34,(undefined4 *)L"temp.xml",sVar3);
  }
  _File = _wfopen(param_1,L"r");
  if (_File != (FILE *)0x0) {
    pwVar7 = local_34;
    if (local_20 < 8) {
      pwVar7 = (wchar_t *)&local_34;
    }
    _File_00 = _wfopen(pwVar7,L"w");
    if (_File_00 != (FILE *)0x0) {
      uVar2 = fgetwc(_File);
      while( true ) {
        if (uVar2 == 0xffff) break;
        fputwc(uVar2 ^ 0xd,_File_00);
        uVar2 = fgetwc(_File);
      }
      fclose(_File_00);
    }
    fclose(_File);
  }
  local_80 = 0;
  iVar4 = (**(code **)(*param_2 + 0x110))(param_2,0);
  FUN_100045f1(local_90,iVar4);
  pwVar7 = local_34;
  if (local_20 < 8) {
    pwVar7 = (wchar_t *)&local_34;
  }
  if (pwVar7 == (wchar_t *)0x0) {
    local_7c = 0;
  }
  else {
    local_7c = Ordinal_2(pwVar7);
    if (local_7c == 0) goto LAB_10014419;
  }
  local_8._0_1_ = 6;
  local_44 = local_44 & 0xffff0000;
  FUN_1000191a(&local_44,&local_7c);
  local_8._0_1_ = 7;
  iVar4 = (**(code **)(*param_2 + 0xe8))(param_2,local_44,uStack_40,uStack_3c,uStack_38,&local_80);
  FUN_100045f1(local_90,iVar4);
  local_8._0_1_ = 6;
  Ordinal_9(&local_44);
  local_8._0_1_ = 4;
  Ordinal_6(local_7c);
  local_74 = (int *)0x0;
  local_8._0_1_ = 9;
  HVar6 = CoCreateInstance((IID *)&DAT_1001d8f0,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_1001d9b4,&local_74);
  FUN_100045f1(local_90,HVar6);
  piVar1 = local_74;
  local_70 = (int *)0x0;
  local_8._0_1_ = 0xb;
  pwVar7 = local_34;
  if (local_20 < 8) {
    pwVar7 = (wchar_t *)&local_34;
  }
  if (pwVar7 == (wchar_t *)0x0) {
    local_78 = 0;
  }
  else {
    local_78 = Ordinal_2(pwVar7);
    if (local_78 == 0) {
LAB_10014419:
                    /* WARNING: Subroutine does not return */
      FUN_100010d9(-0x7ff8fff2);
    }
  }
  local_8._0_1_ = 0xc;
  iVar4 = (**(code **)(*piVar1 + 0x50))(piVar1,local_78,&local_70);
  FUN_100045f1(local_90,iVar4);
  local_8 = CONCAT31(local_8._1_3_,0xb);
  Ordinal_6(local_78);
  iVar4 = (**(code **)(*local_70 + 0x54))(local_70,0xffffffff);
  FUN_100045f1(local_90,iVar4);
  piVar1 = local_70;
  if (local_70 != (int *)0x0) {
    local_70 = (int *)0x0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = local_74;
  if (local_74 != (int *)0x0) {
    local_74 = (int *)0x0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 9;
  if (local_70 != (int *)0x0) {
    (**(code **)(*local_70 + 8))(local_70);
  }
  local_8._0_1_ = 4;
  if (local_74 != (int *)0x0) {
    (**(code **)(*local_74 + 8))(local_74);
  }
  local_8._0_1_ = 3;
  FID_conflict__Tidy(local_6c,'\x01',0);
  local_8 = CONCAT31(local_8._1_3_,2);
  FID_conflict__Tidy(&local_34,'\x01',0);
  local_8 = 1;
  FUN_100144eb();
  return;
}



// Function: Catch@100144dc at 100144dc

undefined * Catch_100144dc(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_100144e9;
}



// Function: FUN_100144eb at 100144eb

void FUN_100144eb(void)

{
  int *piVar1;
  int *unaff_EBX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  piVar1 = *(int **)(unaff_EBP + 0xc);
  if (piVar1 != unaff_EBX) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_10014f93();
  return;
}



// Function: FUN_10014502 at 10014502

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10014502(FILE *param_1,int *param_2)

{
  int *piVar1;
  ushort uVar2;
  size_t sVar3;
  int iVar4;
  undefined4 *puVar5;
  FILE *_File;
  HRESULT HVar6;
  wchar_t *pwVar7;
  undefined4 local_8c [4];
  int local_7c;
  int *local_78;
  int *local_74;
  FILE *local_70;
  undefined1 local_6c [28];
  undefined1 local_50 [12];
  uint local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 local_24;
  uint local_20;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x7c;
  local_70 = param_1;
  local_8 = 0;
  FUN_10001c46(local_8c);
  local_8._0_1_ = 1;
  FUN_100045f1(local_8c,0);
  local_20 = 7;
  local_24 = 0;
  local_34 = (wchar_t *)((uint)local_34._2_2_ << 0x10);
  local_8._0_1_ = 3;
  FUN_10003c48(local_6c,(wchar_t *)param_1);
  local_8._0_1_ = 4;
  sVar3 = wcslen(L"\\");
  iVar4 = FUN_10001d91(local_6c,(short *)&DAT_1001dc40,0xffffffff,sVar3);
  if (iVar4 != -1) {
    puVar5 = (undefined4 *)FUN_10003a63(local_6c,local_50,0,iVar4 + 1);
    local_8._0_1_ = 5;
    FUN_10003c7a(&local_34,puVar5);
    local_8._0_1_ = 4;
    FID_conflict__Tidy(local_50,'\x01',0);
    sVar3 = wcslen(L"temp.xml");
    FUN_10003105(&local_34,(undefined4 *)L"temp.xml",sVar3);
  }
  pwVar7 = local_34;
  if (local_20 < 8) {
    pwVar7 = (wchar_t *)&local_34;
  }
  if (pwVar7 == (wchar_t *)0x0) {
    local_7c = 0;
  }
  else {
    local_7c = Ordinal_2(pwVar7);
    if (local_7c == 0) goto LAB_1001469c;
  }
  local_8._0_1_ = 6;
  local_44 = local_44 & 0xffff0000;
  FUN_1000191a(&local_44,&local_7c);
  local_8._0_1_ = 7;
  iVar4 = (**(code **)(*param_2 + 0x108))(param_2,local_44,uStack_40,uStack_3c,uStack_38);
  FUN_100045f1(local_8c,iVar4);
  local_8._0_1_ = 6;
  Ordinal_9(&local_44);
  local_8 = CONCAT31(local_8._1_3_,4);
  Ordinal_6(local_7c);
  pwVar7 = local_34;
  if (local_20 < 8) {
    pwVar7 = (wchar_t *)&local_34;
  }
  _File = _wfopen(pwVar7,L"r");
  if (_File != (FILE *)0x0) {
    local_70 = _wfopen((wchar_t *)local_70,L"w");
    if (local_70 != (FILE *)0x0) {
      uVar2 = fgetwc(_File);
      while( true ) {
        if (uVar2 == 0xffff) break;
        fputwc(uVar2 ^ 0xd,local_70);
        uVar2 = fgetwc(_File);
      }
      fclose(local_70);
    }
    fclose(_File);
  }
  local_74 = (int *)0x0;
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 9;
  HVar6 = CoCreateInstance((IID *)&DAT_1001d8f0,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_1001d9b4,&local_74);
  FUN_100045f1(local_8c,HVar6);
  piVar1 = local_74;
  local_78 = (int *)0x0;
  local_8._0_1_ = 0xb;
  pwVar7 = local_34;
  if (local_20 < 8) {
    pwVar7 = (wchar_t *)&local_34;
  }
  if (pwVar7 == (wchar_t *)0x0) {
    local_70 = (FILE *)0x0;
  }
  else {
    local_70 = (FILE *)Ordinal_2(pwVar7);
    if (local_70 == (FILE *)0x0) {
LAB_1001469c:
                    /* WARNING: Subroutine does not return */
      FUN_100010d9(-0x7ff8fff2);
    }
  }
  local_8._0_1_ = 0xc;
  iVar4 = (**(code **)(*piVar1 + 0x50))(piVar1,local_70,&local_78);
  FUN_100045f1(local_8c,iVar4);
  local_8 = CONCAT31(local_8._1_3_,0xb);
  Ordinal_6(local_70);
  iVar4 = (**(code **)(*local_78 + 0x54))(local_78,0xffffffff);
  FUN_100045f1(local_8c,iVar4);
  piVar1 = local_78;
  if (local_78 != (int *)0x0) {
    local_78 = (int *)0x0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = local_74;
  if (local_74 != (int *)0x0) {
    local_74 = (int *)0x0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 9;
  if (local_78 != (int *)0x0) {
    (**(code **)(*local_78 + 8))(local_78);
  }
  local_8._0_1_ = 4;
  if (local_74 != (int *)0x0) {
    (**(code **)(*local_74 + 8))(local_74);
  }
  local_8._0_1_ = 3;
  FID_conflict__Tidy(local_6c,'\x01',0);
  local_8 = CONCAT31(local_8._1_3_,2);
  FID_conflict__Tidy(&local_34,'\x01',0);
  local_8 = 1;
  FUN_100147d2();
  return;
}



// Function: Catch@100147c3 at 100147c3

undefined * Catch_100147c3(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_100147d0;
}



// Function: FUN_100147d2 at 100147d2

void FUN_100147d2(void)

{
  int *piVar1;
  int unaff_EBP;
  int *unaff_EDI;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  piVar1 = *(int **)(unaff_EBP + 0xc);
  if (piVar1 != unaff_EDI) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_10014f93();
  return;
}



// Function: FUN_100147e9 at 100147e9

void __fastcall FUN_100147e9(undefined4 *param_1)

{
  *param_1 = CXMLParser::vftable;
  return;
}



// Function: FUN_100147f2 at 100147f2

void __fastcall FUN_100147f2(undefined4 *param_1)

{
  *param_1 = CXMLParser::vftable;
  return;
}



// Function: FUN_100147f9 at 100147f9

undefined4 * __thiscall FUN_100147f9(void *this,byte param_1)

{
  FUN_100147f2((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10014818 at 10014818

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10014818(int *param_1,undefined4 *param_2,int *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80004005;
  if (*param_3 != 0) {
    FUN_10001113(param_3,(int *)0x0);
  }
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    if (7 < (uint)param_2[5]) {
      param_2 = (undefined4 *)*param_2;
    }
    if (param_2 == (undefined4 *)0x0) {
      param_1 = (int *)0x0;
    }
    else {
      param_1 = (int *)Ordinal_2(param_2);
      if (param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_100010d9(-0x7ff8fff2);
      }
    }
    uVar2 = (**(code **)(*piVar1 + 0x94))(piVar1,param_1,param_3);
    Ordinal_6(param_1);
  }
  return uVar2;
}



// Function: FUN_10014899 at 10014899

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10014899(int *param_1,undefined4 *param_2,void *param_3)

{
  int *piVar1;
  undefined3 uVar2;
  size_t sVar3;
  undefined4 uVar4;
  undefined1 local_28 [8];
  wchar_t *local_20;
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  uVar4 = 0x80004005;
  local_18 = (int *)0x0;
  local_14[0] = (int *)0x0;
  local_8._1_3_ = 0;
  uVar2 = local_8._1_3_;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    uVar4 = (**(code **)(*piVar1 + 0x44))(piVar1,local_14);
    piVar1 = local_14[0];
    uVar2 = local_8._1_3_;
    if (local_14[0] != (int *)0x0) {
      if (7 < (uint)param_2[5]) {
        param_2 = (undefined4 *)*param_2;
      }
      if (param_2 == (undefined4 *)0x0) {
        param_1 = (int *)0x0;
      }
      else {
        param_1 = (int *)Ordinal_2(param_2);
        if (param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_100010d9(-0x7ff8fff2);
        }
      }
      local_8._0_1_ = 4;
      uVar4 = (**(code **)(*piVar1 + 0x1c))(piVar1,param_1,&local_18);
      local_8._0_1_ = 3;
      Ordinal_6(param_1);
      uVar2 = local_8._1_3_;
      if (local_18 != (int *)0x0) {
        Ordinal_8(local_28);
        local_8._0_1_ = 5;
        uVar4 = (**(code **)(*local_18 + 0x20))(local_18,local_28);
        FUN_10001188(8,(int)local_28,0,0x409);
        sVar3 = wcslen(local_20);
        FID_conflict_assign(param_3,(undefined4 *)local_20,sVar3);
        local_8._0_1_ = 3;
        Ordinal_9(local_28);
        uVar2 = local_8._1_3_;
      }
    }
  }
  local_8._1_3_ = uVar2;
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  return uVar4;
}



// Function: FUN_10014b6a at 10014b6a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

long FUN_10014b6a(HWND__ *param_1,uint param_2,uint param_3,long param_4)

{
  long lVar1;
  AFX_MAINTAIN_STATE2 local_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x10014b76;
  FUN_10009ccc();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_20,(AFX_MODULE_STATE *)&DAT_1002abf8);
  local_8 = 0;
  lVar1 = AfxWndProc(param_1,param_2,param_3,param_4);
  local_8 = 0xffffffff;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_20);
  return lVar1;
}



// Function: FUN_10014bb5 at 10014bb5

undefined * FUN_10014bb5(void)

{
  return &DAT_1002abf8;
}



// Function: FUN_10014bbb at 10014bbb

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10014bbb(HINSTANCE__ *param_1,int param_2)

{
  _AFX_THREAD_STATE *p_Var1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  CDynLinkLibrary *this;
  AFX_MODULE_STATE *pAVar5;
  AFX_MAINTAIN_STATE2 local_34 [20];
  undefined4 local_20;
  _AFX_THREAD_STATE *local_1c;
  int *local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0x10014bc7;
  if (param_2 != 1) {
    if (param_2 == 0) {
      pAVar5 = AfxSetModuleState((AFX_MODULE_STATE *)&DAT_1002abf8);
      p_Var1 = AfxGetThreadState();
      *(AFX_MODULE_STATE **)(p_Var1 + 8) = pAVar5;
      piVar4 = (int *)FUN_10014e1a();
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0x70))();
      }
      AfxLockTempMaps();
      AfxUnlockTempMaps(-1);
      AfxWinTerm();
      AfxTermExtensionModule((AFX_EXTENSION_MODULE *)&DAT_1002abe4,1);
      if (DAT_1002abd8 != 0) {
        p_Var1 = AfxGetThreadState();
        AfxSetModuleState(*(AFX_MODULE_STATE **)(p_Var1 + 8));
      }
    }
    else if (param_2 == 3) {
      AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_34,(AFX_MODULE_STATE *)&DAT_1002abf8);
      local_8 = 3;
      AfxLockTempMaps();
      AfxUnlockTempMaps(-1);
      AfxTermThread(param_1);
      local_8 = 0xffffffff;
      AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_34);
    }
    return 1;
  }
  AfxCoreInitModule();
  p_Var1 = AfxGetThreadState();
  uVar3 = *(undefined4 *)(p_Var1 + 8);
  local_20 = uVar3;
  local_1c = p_Var1;
  iVar2 = AfxWinInit(param_1,(HINSTANCE__ *)0x0,L"",0);
  if (iVar2 == 0) {
LAB_10014bfe:
    AfxWinTerm();
    uVar3 = FUN_10014c91();
    return uVar3;
  }
  piVar4 = (int *)FUN_10014e1a();
  local_18 = piVar4;
  if (piVar4 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar4 + 0x58))();
    if (iVar2 == 0) {
      (**(code **)(*piVar4 + 0x70))();
      goto LAB_10014bfe;
    }
  }
  *(undefined4 *)(p_Var1 + 8) = uVar3;
  AfxInitExtensionModule((AFX_EXTENSION_MODULE *)&DAT_1002abe4,param_1);
  local_8 = 0;
  this = (CDynLinkLibrary *)FUN_10014e08(0x40);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (this != (CDynLinkLibrary *)0x0) {
    CDynLinkLibrary::CDynLinkLibrary(this,(AFX_EXTENSION_MODULE *)&DAT_1002abe4,0);
  }
  local_8 = 0xffffffff;
  uVar3 = FUN_10014c91();
  return uVar3;
}



// Function: Catch@10014c68 at 10014c68

undefined * Catch_10014c68(void)

{
  int unaff_EBP;
  
  if (*(CException **)(unaff_EBP + -0x20) != (CException *)0x0) {
    CException::Delete(*(CException **)(unaff_EBP + -0x20));
  }
  (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x70))();
  AfxWinTerm();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10014c8b;
}



// Function: FUN_10014c91 at 10014c91

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10014c91(void)

{
  _AFX_THREAD_STATE *p_Var1;
  undefined4 unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 8) = unaff_EBX;
  p_Var1 = AfxGetThreadState();
  AfxSetModuleState(*(AFX_MODULE_STATE **)(p_Var1 + 8));
  return *(undefined4 *)(unaff_EBP + 0xc);
}



// Function: _RawDllMain@12 at 10014d4b

/* Library Function - Single Match
    _RawDllMain@12
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

undefined4 _RawDllMain_12(undefined4 param_1,int param_2)

{
  HLOCAL hMem;
  _AFX_THREAD_STATE *p_Var1;
  AFX_MODULE_STATE *pAVar2;
  
  if (param_2 == 1) {
    hMem = LocalAlloc(0,0x2000);
    if (hMem == (HLOCAL)0x0) {
      return 0;
    }
    LocalFree(hMem);
    p_Var1 = AfxGetThreadState();
    pAVar2 = AfxSetModuleState((AFX_MODULE_STATE *)&DAT_1002abf8);
    *(AFX_MODULE_STATE **)(p_Var1 + 8) = pAVar2;
  }
  else if ((param_2 == 0) && (DAT_1002abd8 == 0)) {
    p_Var1 = AfxGetThreadState();
    AfxSetModuleState(*(AFX_MODULE_STATE **)(p_Var1 + 8));
  }
  return 1;
}



// Function: _DllMain@12 at 10014da9

/* Library Function - Single Match
    _DllMain@12
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

undefined4 _DllMain_12(HINSTANCE__ *param_1,int param_2)

{
  AFX_MODULE_STATE *pAVar1;
  _AFX_THREAD_STATE *p_Var2;
  undefined4 uVar3;
  
  if (DAT_1002abd8 != 0) {
    if (param_2 == 1) {
      pAVar1 = AfxGetModuleState();
      *(HINSTANCE__ **)(pAVar1 + 8) = param_1;
      p_Var2 = AfxGetThreadState();
      AfxSetModuleState(*(AFX_MODULE_STATE **)(p_Var2 + 8));
    }
    else if (param_2 != 0) goto LAB_10014de2;
    return 1;
  }
LAB_10014de2:
  uVar3 = FUN_10014bbb(param_1,param_2);
  return uVar3;
}



// Function: FUN_10014de8 at 10014de8

AFX_MODULE_STATE * __thiscall FUN_10014de8(void *this,byte param_1)

{
  AFX_MODULE_STATE::~AFX_MODULE_STATE((AFX_MODULE_STATE *)this);
  if ((param_1 & 1) != 0) {
    CNoTrackObject::operator_delete(this);
  }
  return (AFX_MODULE_STATE *)this;
}



// Function: FUN_10014e08 at 10014e08

void FUN_10014e08(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: FUN_10014e1a at 10014e1a

undefined4 FUN_10014e1a(void)

{
  AFX_MODULE_STATE *pAVar1;
  
  pAVar1 = AfxGetModuleState();
  return *(undefined4 *)(pAVar1 + 4);
}



// Function: FID_conflict:`vector_deleting_destructor' at 10014e36

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



// Function: __security_check_cookie at 10014e82

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_10028e44) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: __EH_prolog3 at 10014e98

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10028e44 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch at 10014ecb

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10028e44 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_GS at 10014f01

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10028e44 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch_GS at 10014f37

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10028e44 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_epilog3 at 10014f70

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



// Function: FUN_10014f84 at 10014f84

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10014f84(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x10) ^ unaff_EBP);
  return;
}



// Function: FUN_10014f93 at 10014f93

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10014f93(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_10015017 at 10015017

void __cdecl
FUN_10015017(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_10028e44,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: __alloca_probe_16 at 10015040

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



// Function: __alloca_probe_8 at 10015056

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



// Function: __ArrayUnwind at 1001506c

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



// Function: `eh_vector_destructor_iterator' at 100150ca

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
  FUN_10015115();
  return;
}



// Function: FUN_10015115 at 10015115

void FUN_10015115(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: `eh_vector_constructor_iterator' at 1001513c

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
  FUN_10015189();
  return;
}



// Function: FUN_10015189 at 10015189

void FUN_10015189(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __onexit at 100151a8

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
  
  local_8 = &DAT_10025118;
  uStack_c = 0x100151b4;
  local_20[0] = DecodePointer(DAT_1002b070);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_1002b070);
    local_24 = DecodePointer(DAT_1002b06c);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_1002b070 = EncodePointer(local_20[0]);
    DAT_1002b06c = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_10015240();
  }
  return p_Var1;
}



// Function: FUN_10015240 at 10015240

void FUN_10015240(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 10015249

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: __alloca_probe at 10015260

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



// Function: __CRT_INIT@12 at 100152d9

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
    if (DAT_1002aca4 < 1) {
      return 0;
    }
    DAT_1002aca4 = DAT_1002aca4 + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_1002b064,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_1002b060 == 2) {
      param_2 = (int *)DecodePointer(DAT_1002b070);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_1002b06c);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_1002b070);
            piVar8 = (int *)DecodePointer(DAT_1002b06c);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_1002b06c = (PVOID)encoded_null();
        DAT_1002b070 = DAT_1002b06c;
      }
      DAT_1002b060 = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_1002b064,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_1002b064,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_1002b060 == 0) {
      DAT_1002b060 = 1;
      iVar5 = initterm_e(&DAT_1001d7b4,&DAT_1001d7bc);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_1001d3bc,&DAT_1001d7b0);
      DAT_1002b060 = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_1002b064,0);
    }
    if ((DAT_1002b068 != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_1002b068), BVar2 != 0)) {
      (*DAT_1002b068)(param_1,2,param_3);
    }
    DAT_1002aca4 = DAT_1002aca4 + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 100154e3

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HINSTANCE__ *param_3)

{
  int iVar1;
  undefined4 local_20;
  
  _DAT_10028e50 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_1002aca4 == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          ((local_20 = __RawDllMainProxy_12(param_3,(int)param_2), local_20 != 0 &&
           (local_20 = __CRT_INIT_12(&param_3->unused,param_2,param_1), local_20 != 0)))) {
    local_20 = _DllMain_12(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      _DllMain_12(param_3,0);
      __CRT_INIT_12(&param_3->unused,(int *)0x0,param_1);
      __RawDllMainProxy_12(param_3,0);
    }
    if ((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) {
      iVar1 = __CRT_INIT_12(&param_3->unused,param_2,param_1);
      if (iVar1 == 0) {
        local_20 = 0;
      }
      if (local_20 != 0) {
        local_20 = __RawDllMainProxy_12(param_3,(int)param_2);
      }
    }
  }
  FUN_100155ee();
  return local_20;
}



// Function: FUN_100155ee at 100155ee

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100155ee(void)

{
  _DAT_10028e50 = 0xffffffff;
  return;
}



// Function: entry at 100155f9

void entry(HINSTANCE__ *param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: ___report_gsfailure at 1001561c

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
  
  _DAT_1002adc0 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_1002adc4 = &stack0x00000004;
  _DAT_1002ad00 = 0x10001;
  _DAT_1002aca8 = 0xc0000409;
  _DAT_1002acac = 1;
  local_32c = DAT_10028e44;
  local_328 = DAT_10028e48;
  _DAT_1002acb4 = unaff_retaddr;
  _DAT_1002ad8c = in_GS;
  _DAT_1002ad90 = in_FS;
  _DAT_1002ad94 = in_ES;
  _DAT_1002ad98 = in_DS;
  _DAT_1002ad9c = unaff_EDI;
  _DAT_1002ada0 = unaff_ESI;
  _DAT_1002ada4 = unaff_EBX;
  _DAT_1002ada8 = in_EDX;
  _DAT_1002adac = in_ECX;
  _DAT_1002adb0 = in_EAX;
  _DAT_1002adb4 = unaff_EBP;
  DAT_1002adb8 = unaff_retaddr;
  _DAT_1002adbc = in_CS;
  _DAT_1002adc8 = in_SS;
  DAT_1002acf8 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_1001f694);
  if (DAT_1002acf8 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __SEH_prolog4 at 10015730

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10028e44 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 10015775

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



// Function: __ValidateImageBase at 10015800

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



// Function: __FindPESection at 10015840

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



// Function: __IsNonwritableInCurrentImage at 10015890

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
  
  pcStack_10 = FUN_10015017;
  local_14 = ExceptionList;
  local_c = DAT_10028e44 ^ 0x10025160;
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



// Function: ___security_init_cookie at 10015964

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
  if ((DAT_10028e44 == 0xbb40e64e) || ((DAT_10028e44 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_10028e44 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_10028e44 == 0xbb40e64e) {
      DAT_10028e44 = 0xbb40e64f;
    }
    else if ((DAT_10028e44 & 0xffff0000) == 0) {
      DAT_10028e44 = DAT_10028e44 | (DAT_10028e44 | 0x4711) << 0x10;
    }
    DAT_10028e48 = ~DAT_10028e44;
  }
  else {
    DAT_10028e48 = ~DAT_10028e44;
  }
  return;
}



// Function: RemoveAll at 10015a12

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall ATL::CSimpleArray<unsigned short,class
   ATL::CSimpleArrayEqualHelper<unsigned short> >::RemoveAll(void)
    public: void __thiscall ATL::CSimpleArray<unsigned long,class
   ATL::CSimpleArrayEqualHelper<unsigned long> >::RemoveAll(void)
    public: void __thiscall ATL::CSimpleArray<struct HINSTANCE__ *,class
   ATL::CSimpleArrayEqualHelper<struct HINSTANCE__ *> >::RemoveAll(void)
    public: void __thiscall ATL::CSimpleArray<class CDHtmlControlSink *,class
   ATL::CSimpleArrayEqualHelper<class CDHtmlControlSink *> >::RemoveAll(void)
     6 names - too many to list
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release,
   Visual Studio 2010 Release */

void __fastcall RemoveAll(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_10015a31 at 10015a31

int __fastcall FUN_10015a31(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_10015a56 at 10015a56

void __fastcall FUN_10015a56(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  RemoveAll((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: GetHInstanceAt at 10015a6e

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
LAB_10015abc:
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
        goto LAB_10015abc;
      }
      pHVar2 = *(HINSTANCE__ **)(*(int *)(this + 0x2c) + param_1 * 4);
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return pHVar2;
}



// Function: FUN_10015acb at 10015acb

undefined4 * __fastcall FUN_10015acb(undefined4 *param_1)

{
  long lVar1;
  
  FUN_10015a31((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_1001f6bc;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 5));
  if (lVar1 < 0) {
    DAT_1002939c = 1;
  }
  return param_1;
}



// Function: FUN_10015b0b at 10015b0b

void __fastcall FUN_10015b0b(int *param_1)

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



// Function: FUN_10015b4f at 10015b4f

int __fastcall FUN_10015b4f(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_10015b68 at 10015b68

undefined4 * __fastcall FUN_10015b68(undefined4 *param_1)

{
  long lVar1;
  
  FUN_10015b4f((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &DAT_100251d0;
  param_1[3] = &DAT_100251d0;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (lVar1 < 0) {
    DAT_1002939c = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: AtlWinModuleInit at 10015ba9

/* Library Function - Single Match
    long __stdcall ATL::AtlWinModuleInit(struct ATL::_ATL_WIN_MODULE70 *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

long ATL::AtlWinModuleInit(_ATL_WIN_MODULE70 *param_1)

{
  long lVar1;
  
  if ((param_1 == (_ATL_WIN_MODULE70 *)0x0) || (*(int *)param_1 != 0x2c)) {
    lVar1 = -0x7ff8ffa9;
  }
  else {
    *(undefined4 *)(param_1 + 0x1c) = 0;
    lVar1 = CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  }
  return lVar1;
}



// Function: FUN_10015bd1 at 10015bd1

int __fastcall FUN_10015bd1(int param_1)

{
  memset((void *)(param_1 + 4),0,0x18);
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  return param_1;
}



// Function: AtlWinModuleTerm at 10015bf6

/* Library Function - Single Match
    long __stdcall ATL::AtlWinModuleTerm(struct ATL::_ATL_WIN_MODULE70 *,struct HINSTANCE__ *)
   
   Library: Visual Studio 2010 Release */

long ATL::AtlWinModuleTerm(_ATL_WIN_MODULE70 *param_1,HINSTANCE__ *param_2)

{
  code *pcVar1;
  long lVar2;
  int iVar3;
  
  if (param_1 == (_ATL_WIN_MODULE70 *)0x0) {
LAB_10015c03:
    lVar2 = -0x7ff8ffa9;
  }
  else {
    if (*(int *)param_1 != 0) {
      if (*(int *)param_1 != 0x2c) goto LAB_10015c03;
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
      RemoveAll((undefined4 *)(param_1 + 0x20));
      DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
      *(undefined4 *)param_1 = 0;
    }
    lVar2 = 0;
  }
  return lVar2;
}



// Function: FUN_10015c6c at 10015c6c

_ATL_WIN_MODULE70 * __fastcall FUN_10015c6c(_ATL_WIN_MODULE70 *param_1)

{
  long lVar1;
  
  FUN_10015bd1((int)param_1);
  *(undefined4 *)param_1 = 0x2c;
  lVar1 = ATL::AtlWinModuleInit(param_1);
  if (lVar1 < 0) {
    DAT_1002939c = 1;
    *(undefined4 *)param_1 = 0;
  }
  return param_1;
}



// Function: FUN_10015cd0 at 10015cd0

void FUN_10015cd0(undefined4 param_1)

{
  (*(code *)PTR_FUN_10028e58)(param_1,0);
  return;
}



// Function: FUN_10015d20 at 10015d20

void FUN_10015d20(undefined4 param_1,undefined4 param_2)

{
  undefined **local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_14 = &PTR__scalar_deleting_destructor__1001f6cc;
  local_10 = param_1;
  local_c = param_2;
  local_8 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_1002517c);
}



// Function: _com_error at 10015d60

/* Library Function - Single Match
    public: __thiscall _com_error::_com_error(class _com_error const &)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

_com_error * __thiscall _com_error::_com_error(_com_error *this,_com_error *param_1)

{
  int *piVar1;
  
  *(undefined ***)this = &PTR__scalar_deleting_destructor__1001f6cc;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  piVar1 = *(int **)(param_1 + 8);
  *(int **)(this + 8) = piVar1;
  *(undefined4 *)(this + 0xc) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return this;
}



// Function: `scalar_deleting_destructor' at 10015da0

/* Library Function - Single Match
    public: virtual void * __thiscall _com_error::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2010 Release */

void * __thiscall _com_error::_scalar_deleting_destructor_(_com_error *this,uint param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 8);
  *(undefined ***)this = &PTR__scalar_deleting_destructor__1001f6cc;
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



// Function: __IsNonwritableInCurrentImage at 10015e42

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Enum "SectionFlags": Some values do not have unique names */
/* Library Function - Single Match
    __IsNonwritableInCurrentImage
   
   Library: Visual Studio 2010 Release */

BOOL __cdecl __IsNonwritableInCurrentImage(PBYTE pTarget)

{
  uint uVar1;
  int in_ECX;
  IMAGE_SECTION_HEADER *pIVar2;
  uint local_20;
  
  pIVar2 = &IMAGE_SECTION_HEADER_10000208;
  for (local_20 = 0; local_20 < 5; local_20 = local_20 + 1) {
    if (((uint)pIVar2->VirtualAddress <= in_ECX + 0xf0000000U) &&
       (in_ECX + 0xf0000000U < (pIVar2->Misc).PhysicalAddress + pIVar2->VirtualAddress))
    goto LAB_10015ec4;
    pIVar2 = pIVar2 + 1;
  }
  pIVar2 = (IMAGE_SECTION_HEADER *)0x0;
LAB_10015ec4:
  if (pIVar2 == (IMAGE_SECTION_HEADER *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = ~(pIVar2->Characteristics >> 0x1f) & 1;
  }
  return uVar1;
}



// Function: __RawDllMainProxy@12 at 10015f02

/* WARNING: Removing unreachable block (ram,0x10015f25) */
/* Library Function - Single Match
    __RawDllMainProxy@12
   
   Library: Visual Studio 2010 Release */

undefined4 __RawDllMainProxy_12(undefined4 param_1,int param_2)

{
  HLOCAL hMem;
  _AFX_THREAD_STATE *p_Var1;
  AFX_MODULE_STATE *pAVar2;
  BOOL BVar3;
  PBYTE unaff_EBP;
  
  BVar3 = __IsNonwritableInCurrentImage(unaff_EBP);
  if (BVar3 == 0) {
    return 0;
  }
  if (param_2 == 1) {
    hMem = LocalAlloc(0,0x2000);
    if (hMem == (HLOCAL)0x0) {
      return 0;
    }
    LocalFree(hMem);
    p_Var1 = AfxGetThreadState();
    pAVar2 = AfxSetModuleState((AFX_MODULE_STATE *)&DAT_1002abf8);
    *(AFX_MODULE_STATE **)(p_Var1 + 8) = pAVar2;
  }
  else if ((param_2 == 0) && (DAT_1002abd8 == 0)) {
    p_Var1 = AfxGetThreadState();
    AfxSetModuleState(*(AFX_MODULE_STATE **)(p_Var1 + 8));
  }
  return 1;
}



// Function: Unwind@10015f2c at 10015f2c

void Unwind_10015f2c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10015f2f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10015f50 at 10015f50

void Unwind_10015f50(void)

{
  int unaff_EBP;
  
  FUN_100014b1((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10015f73 at 10015f73

void Unwind_10015f73(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10015f96 at 10015f96

void Unwind_10015f96(void)

{
  int unaff_EBP;
  
  FUN_100056fc(*(int **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10015f9e at 10015f9e

void Unwind_10015f9e(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_100018f5(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10015fb7 at 10015fb7

void Unwind_10015fb7(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10015fbf at 10015fbf

void Unwind_10015fbf(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10015fe2 at 10015fe2

void Unwind_10015fe2(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_100011c9(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10016016 at 10016016

void Unwind_10016016(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001601e at 1001601e

void Unwind_1001601e(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10016026 at 10016026

void Unwind_10016026(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001602e at 1001602e

void Unwind_1001602e(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10016036 at 10016036

void Unwind_10016036(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001603e at 1001603e

void Unwind_1001603e(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10016046 at 10016046

void Unwind_10016046(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001604e at 1001604e

void Unwind_1001604e(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x34);
  return;
}



// Function: Unwind@10016056 at 10016056

void Unwind_10016056(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001605e at 1001605e

void Unwind_1001605e(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10016066 at 10016066

void Unwind_10016066(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001606e at 1001606e

void Unwind_1001606e(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10016091 at 10016091

void Unwind_10016091(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10016094. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100160eb at 100160eb

void Unwind_100160eb(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x24);
  return;
}



// Function: Unwind@1001610e at 1001610e

void Unwind_1001610e(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10016116 at 10016116

void Unwind_10016116(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@1001613c at 1001613c

void Unwind_1001613c(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10016142. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@10016148 at 10016148

void Unwind_10016148(void)

{
  int unaff_EBP;
  
  FUN_100021cd((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@10016189 at 10016189

void Unwind_10016189(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x1001619f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0x60));
    return;
  }
  return;
}



// Function: Unwind@100161a6 at 100161a6

void Unwind_100161a6(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100161ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_iostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x14) + 0x18));
  return;
}



// Function: Unwind@100161b2 at 100161b2

void Unwind_100161b2(void)

{
  int unaff_EBP;
  
  FUN_100021cd((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0x18));
  return;
}



// Function: Unwind@100161d8 at 100161d8

void Unwind_100161d8(void)

{
  int unaff_EBP;
  
  FUN_10002d05(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100161e0 at 100161e0

void Unwind_100161e0(void)

{
  int unaff_EBP;
  
  FUN_10002ccf((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10016206 at 10016206

void Unwind_10016206(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001623a at 1001623a

void Unwind_1001623a(void)

{
  int unaff_EBP;
  
  FUN_10002ccf((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10016260 at 10016260

void Unwind_10016260(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10016286 at 10016286

void Unwind_10016286(void)

{
  int unaff_EBP;
  
  FUN_10002bef((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100162ce at 100162ce

void Unwind_100162ce(void)

{
  int unaff_EBP;
  
  FUN_10002d05(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100162f1 at 100162f1

void Unwind_100162f1(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10002e56(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  (unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001632f at 1001632f

void Unwind_1001632f(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10016337 at 10016337

void Unwind_10016337(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x30) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x30) = *(uint *)(unaff_EBP + -0x30) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + -0x38));
    return;
  }
  return;
}



// Function: Unwind@10016350 at 10016350

void Unwind_10016350(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10016358 at 10016358

void Unwind_10016358(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10016385 at 10016385

void Unwind_10016385(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001638d at 1001638d

void Unwind_1001638d(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10002e56(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  (unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100163c1 at 100163c1

void Unwind_100163c1(void)

{
  int unaff_EBP;
  
  FUN_10002fd4(unaff_EBP + -0xb8);
  return;
}



// Function: Unwind@100163cc at 100163cc

void Unwind_100163cc(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10016403 at 10016403

void Unwind_10016403(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@1001640e at 1001640e

void Unwind_1001640e(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10016416 at 10016416

void Unwind_10016416(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001641e at 1001641e

void Unwind_1001641e(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10016426 at 10016426

void Unwind_10016426(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@1001642e at 1001642e

void Unwind_1001642e(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x40);
  return;
}



// Function: Unwind@10016436 at 10016436

void Unwind_10016436(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001643e at 1001643e

void Unwind_1001643e(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10016446 at 10016446

void Unwind_10016446(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@1001644e at 1001644e

void Unwind_1001644e(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10016456 at 10016456

void Unwind_10016456(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@1001645e at 1001645e

void Unwind_1001645e(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10016466 at 10016466

void Unwind_10016466(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10016496 at 10016496

void Unwind_10016496(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@100164a1 at 100164a1

void Unwind_100164a1(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100164a9 at 100164a9

void Unwind_100164a9(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@100164b1 at 100164b1

void Unwind_100164b1(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100164b9 at 100164b9

void Unwind_100164b9(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@100164c1 at 100164c1

void Unwind_100164c1(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x40);
  return;
}



// Function: Unwind@100164c9 at 100164c9

void Unwind_100164c9(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100164d1 at 100164d1

void Unwind_100164d1(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100164d9 at 100164d9

void Unwind_100164d9(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@100164e1 at 100164e1

void Unwind_100164e1(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@100164e9 at 100164e9

void Unwind_100164e9(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@100164f1 at 100164f1

void Unwind_100164f1(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@100164f9 at 100164f9

void Unwind_100164f9(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10016529 at 10016529

void Unwind_10016529(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10016531 at 10016531

void Unwind_10016531(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10016539 at 10016539

void Unwind_10016539(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10016541 at 10016541

void Unwind_10016541(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10016549 at 10016549

void Unwind_10016549(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10016551 at 10016551

void Unwind_10016551(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10016574 at 10016574

void Unwind_10016574(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001657c at 1001657c

void Unwind_1001657c(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10016584 at 10016584

void Unwind_10016584(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + 0x14));
  return;
}



// Function: Unwind@1001658c at 1001658c

void Unwind_1001658c(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100165af at 100165af

void Unwind_100165af(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100165b7 at 100165b7

void Unwind_100165b7(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x28c));
  return;
}



// Function: Unwind@100165c2 at 100165c2

void Unwind_100165c2(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x28c));
  return;
}



// Function: Unwind@100165cd at 100165cd

void Unwind_100165cd(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x2ac));
  return;
}



// Function: Unwind@100165d8 at 100165d8

void Unwind_100165d8(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x238));
  return;
}



// Function: Unwind@100165e3 at 100165e3

void Unwind_100165e3(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x270));
  return;
}



// Function: Unwind@100165ee at 100165ee

void Unwind_100165ee(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x274));
  return;
}



// Function: Unwind@100165f9 at 100165f9

void Unwind_100165f9(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x274));
  return;
}



// Function: Unwind@10016604 at 10016604

void Unwind_10016604(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x280));
  return;
}



// Function: Unwind@1001660f at 1001660f

void Unwind_1001660f(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x27c));
  return;
}



// Function: Unwind@1001661a at 1001661a

void Unwind_1001661a(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x27c));
  return;
}



// Function: Unwind@10016625 at 10016625

void Unwind_10016625(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x284));
  return;
}



// Function: Unwind@10016630 at 10016630

void Unwind_10016630(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x284));
  return;
}



// Function: Unwind@1001663b at 1001663b

void Unwind_1001663b(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x254));
  return;
}



// Function: Unwind@10016646 at 10016646

void Unwind_10016646(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -700);
  return;
}



// Function: Unwind@10016651 at 10016651

void Unwind_10016651(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x290));
  return;
}



// Function: Unwind@1001665c at 1001665c

void Unwind_1001665c(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x284));
  return;
}



// Function: Unwind@10016667 at 10016667

void Unwind_10016667(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x27c));
  return;
}



// Function: Unwind@10016672 at 10016672

void Unwind_10016672(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x274));
  return;
}



// Function: Unwind@1001667d at 1001667d

void Unwind_1001667d(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x28c));
  return;
}



// Function: Unwind@10016688 at 10016688

void Unwind_10016688(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100166b8 at 100166b8

void Unwind_100166b8(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100166c0 at 100166c0

void Unwind_100166c0(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x1a0));
  return;
}



// Function: Unwind@100166cb at 100166cb

void Unwind_100166cb(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x130));
  return;
}



// Function: Unwind@100166d6 at 100166d6

void Unwind_100166d6(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x14c));
  return;
}



// Function: Unwind@100166e1 at 100166e1

void Unwind_100166e1(void)

{
  int unaff_EBP;
  
  FUN_10002e56((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x168));
  return;
}



// Function: Unwind@100166ec at 100166ec

void Unwind_100166ec(void)

{
  int unaff_EBP;
  
  FUN_10002e56((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x184));
  return;
}



// Function: Unwind@100166f7 at 100166f7

void Unwind_100166f7(void)

{
  int unaff_EBP;
  
  FUN_10002e56((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x168));
  return;
}



// Function: Unwind@10016702 at 10016702

void Unwind_10016702(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x18c));
  return;
}



// Function: Unwind@10016735 at 10016735

void Unwind_10016735(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004315((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001675b at 1001675b

void Unwind_1001675b(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10016766 at 10016766

void Unwind_10016766(void)

{
  int unaff_EBP;
  
  FUN_100056fc(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10016789 at 10016789

void Unwind_10016789(void)

{
  int unaff_EBP;
  
  FUN_10005733(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100167ac at 100167ac

void Unwind_100167ac(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100167cf at 100167cf

void Unwind_100167cf(void)

{
  int unaff_EBP;
  
  FUN_100056fc(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100167d7 at 100167d7

void Unwind_100167d7(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100167e2 at 100167e2

void Unwind_100167e2(void)

{
  int unaff_EBP;
  
  FUN_10005733(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10016805 at 10016805

void Unwind_10016805(void)

{
  int unaff_EBP;
  
  FUN_10005762(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10016828 at 10016828

void Unwind_10016828(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x24);
  return;
}



// Function: Unwind@1001684b at 1001684b

void Unwind_1001684b(void)

{
  int unaff_EBP;
  
  FUN_10005762(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10016853 at 10016853

void Unwind_10016853(void)

{
  int unaff_EBP;
  
  FUN_10005733(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100168c7 at 100168c7

void Unwind_100168c7(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x49c));
  return;
}



// Function: Unwind@100168d2 at 100168d2

void Unwind_100168d2(void)

{
  int unaff_EBP;
  
  FUN_10001d2f((undefined4 *)(unaff_EBP + -0x4e4));
  return;
}



// Function: Unwind@100168dd at 100168dd

void Unwind_100168dd(void)

{
  int unaff_EBP;
  
  FUN_100147f2((undefined4 *)(unaff_EBP + -0x4b8));
  return;
}



// Function: Unwind@100168e8 at 100168e8

void Unwind_100168e8(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x478));
  return;
}



// Function: Unwind@100168f3 at 100168f3

void Unwind_100168f3(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x478));
  return;
}



// Function: Unwind@100168fe at 100168fe

void Unwind_100168fe(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x460));
  return;
}



// Function: Unwind@10016909 at 10016909

void Unwind_10016909(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x484));
  return;
}



// Function: Unwind@10016914 at 10016914

void Unwind_10016914(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x484));
  return;
}



// Function: Unwind@1001691f at 1001691f

void Unwind_1001691f(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x47c));
  return;
}



// Function: Unwind@1001692a at 1001692a

void Unwind_1001692a(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x47c));
  return;
}



// Function: Unwind@10016935 at 10016935

void Unwind_10016935(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x528);
  return;
}



// Function: Unwind@10016940 at 10016940

void Unwind_10016940(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x4cc));
  return;
}



// Function: Unwind@1001694b at 1001694b

void Unwind_1001694b(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x4d4));
  return;
}



// Function: Unwind@10016956 at 10016956

void Unwind_10016956(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x470));
  return;
}



// Function: Unwind@10016961 at 10016961

void Unwind_10016961(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x470));
  return;
}



// Function: Unwind@1001696c at 1001696c

void Unwind_1001696c(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x444));
  return;
}



// Function: Unwind@10016977 at 10016977

void Unwind_10016977(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x538);
  return;
}



// Function: Unwind@10016982 at 10016982

void Unwind_10016982(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x4ac));
  return;
}



// Function: Unwind@1001698d at 1001698d

void Unwind_1001698d(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x4f8);
  return;
}



// Function: Unwind@10016998 at 10016998

void Unwind_10016998(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x48c));
  return;
}



// Function: Unwind@100169a3 at 100169a3

void Unwind_100169a3(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x508);
  return;
}



// Function: Unwind@100169ae at 100169ae

void Unwind_100169ae(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x480));
  return;
}



// Function: Unwind@100169b9 at 100169b9

void Unwind_100169b9(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x464));
  return;
}



// Function: Unwind@100169c4 at 100169c4

void Unwind_100169c4(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x464));
  return;
}



// Function: Unwind@100169cf at 100169cf

void Unwind_100169cf(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x468));
  return;
}



// Function: Unwind@100169da at 100169da

void Unwind_100169da(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x468));
  return;
}



// Function: Unwind@100169e5 at 100169e5

void Unwind_100169e5(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x518);
  return;
}



// Function: Unwind@100169f0 at 100169f0

void Unwind_100169f0(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x4b4));
  return;
}



// Function: Unwind@100169fb at 100169fb

void Unwind_100169fb(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x4b0));
  return;
}



// Function: Unwind@10016a06 at 10016a06

void Unwind_10016a06(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x474));
  return;
}



// Function: Unwind@10016a11 at 10016a11

void Unwind_10016a11(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x474));
  return;
}



// Function: Unwind@10016a1c at 10016a1c

void Unwind_10016a1c(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x4c8);
  return;
}



// Function: Unwind@10016a27 at 10016a27

void Unwind_10016a27(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x46c));
  return;
}



// Function: Unwind@10016a32 at 10016a32

void Unwind_10016a32(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x474));
  return;
}



// Function: Unwind@10016a3d at 10016a3d

void Unwind_10016a3d(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x468));
  return;
}



// Function: Unwind@10016a48 at 10016a48

void Unwind_10016a48(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x464));
  return;
}



// Function: Unwind@10016a53 at 10016a53

void Unwind_10016a53(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x470));
  return;
}



// Function: Unwind@10016a5e at 10016a5e

void Unwind_10016a5e(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x47c));
  return;
}



// Function: Unwind@10016a69 at 10016a69

void Unwind_10016a69(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x484));
  return;
}



// Function: Unwind@10016a74 at 10016a74

void Unwind_10016a74(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x478));
  return;
}



// Function: Unwind@10016aa7 at 10016aa7

void Unwind_10016aa7(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x4c0));
  return;
}



// Function: Unwind@10016ab2 at 10016ab2

void Unwind_10016ab2(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x4b0));
  return;
}



// Function: Unwind@10016abd at 10016abd

void Unwind_10016abd(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x490));
  return;
}



// Function: Unwind@10016ac8 at 10016ac8

void Unwind_10016ac8(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x46c));
  return;
}



// Function: Unwind@10016ad3 at 10016ad3

void Unwind_10016ad3(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x46c));
  return;
}



// Function: Unwind@10016ade at 10016ade

void Unwind_10016ade(void)

{
  int unaff_EBP;
  
  FUN_10001d2f((undefined4 *)(unaff_EBP + -0x4d8));
  return;
}



// Function: Unwind@10016ae9 at 10016ae9

void Unwind_10016ae9(void)

{
  int unaff_EBP;
  
  FUN_100147f2((undefined4 *)(unaff_EBP + -0x490));
  return;
}



// Function: Unwind@10016af4 at 10016af4

void Unwind_10016af4(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x484));
  return;
}



// Function: Unwind@10016aff at 10016aff

void Unwind_10016aff(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x484));
  return;
}



// Function: Unwind@10016b0a at 10016b0a

void Unwind_10016b0a(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x460));
  return;
}



// Function: Unwind@10016b15 at 10016b15

void Unwind_10016b15(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x444));
  return;
}



// Function: Unwind@10016b20 at 10016b20

void Unwind_10016b20(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x464));
  return;
}



// Function: Unwind@10016b2b at 10016b2b

void Unwind_10016b2b(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x464));
  return;
}



// Function: Unwind@10016b36 at 10016b36

void Unwind_10016b36(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x468));
  return;
}



// Function: Unwind@10016b41 at 10016b41

void Unwind_10016b41(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x468));
  return;
}



// Function: Unwind@10016b4c at 10016b4c

void Unwind_10016b4c(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x46c));
  return;
}



// Function: Unwind@10016b57 at 10016b57

void Unwind_10016b57(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x46c));
  return;
}



// Function: Unwind@10016b62 at 10016b62

void Unwind_10016b62(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x46c));
  return;
}



// Function: Unwind@10016b6d at 10016b6d

void Unwind_10016b6d(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x444));
  return;
}



// Function: Unwind@10016b78 at 10016b78

void Unwind_10016b78(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x4fc);
  return;
}



// Function: Unwind@10016b83 at 10016b83

void Unwind_10016b83(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x49c));
  return;
}



// Function: Unwind@10016b8e at 10016b8e

void Unwind_10016b8e(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x50c);
  return;
}



// Function: Unwind@10016b99 at 10016b99

void Unwind_10016b99(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x48c));
  return;
}



// Function: Unwind@10016ba4 at 10016ba4

void Unwind_10016ba4(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x47c));
  return;
}



// Function: Unwind@10016baf at 10016baf

void Unwind_10016baf(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x47c));
  return;
}



// Function: Unwind@10016bba at 10016bba

void Unwind_10016bba(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x474));
  return;
}



// Function: Unwind@10016bc5 at 10016bc5

void Unwind_10016bc5(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x474));
  return;
}



// Function: Unwind@10016bd0 at 10016bd0

void Unwind_10016bd0(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x51c);
  return;
}



// Function: Unwind@10016bdb at 10016bdb

void Unwind_10016bdb(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x4a0));
  return;
}



// Function: Unwind@10016be6 at 10016be6

void Unwind_10016be6(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x4c8));
  return;
}



// Function: Unwind@10016bf1 at 10016bf1

void Unwind_10016bf1(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x478));
  return;
}



// Function: Unwind@10016bfc at 10016bfc

void Unwind_10016bfc(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x478));
  return;
}



// Function: Unwind@10016c07 at 10016c07

void Unwind_10016c07(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x4e8);
  return;
}



// Function: Unwind@10016c12 at 10016c12

void Unwind_10016c12(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x488));
  return;
}



// Function: Unwind@10016c1d at 10016c1d

void Unwind_10016c1d(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x478));
  return;
}



// Function: Unwind@10016c28 at 10016c28

void Unwind_10016c28(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x474));
  return;
}



// Function: Unwind@10016c33 at 10016c33

void Unwind_10016c33(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x47c));
  return;
}



// Function: Unwind@10016c3e at 10016c3e

void Unwind_10016c3e(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x470));
  return;
}



// Function: Unwind@10016c49 at 10016c49

void Unwind_10016c49(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x468));
  return;
}



// Function: Unwind@10016c54 at 10016c54

void Unwind_10016c54(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x464));
  return;
}



// Function: Unwind@10016c5f at 10016c5f

void Unwind_10016c5f(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x484));
  return;
}



// Function: Unwind@10016c92 at 10016c92

void Unwind_10016c92(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x280));
  return;
}



// Function: Unwind@10016c9d at 10016c9d

void Unwind_10016c9d(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x250));
  return;
}



// Function: Unwind@10016ca8 at 10016ca8

void Unwind_10016ca8(void)

{
  int unaff_EBP;
  
  FUN_10001d2f((undefined4 *)(unaff_EBP + -0x26c));
  return;
}



// Function: Unwind@10016cb3 at 10016cb3

void Unwind_10016cb3(void)

{
  int unaff_EBP;
  
  FUN_100147f2((undefined4 *)(unaff_EBP + -0x250));
  return;
}



// Function: Unwind@10016cbe at 10016cbe

void Unwind_10016cbe(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x240));
  return;
}



// Function: Unwind@10016cc9 at 10016cc9

void Unwind_10016cc9(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x240));
  return;
}



// Function: Unwind@10016cd4 at 10016cd4

void Unwind_10016cd4(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x23c));
  return;
}



// Function: Unwind@10016cdf at 10016cdf

void Unwind_10016cdf(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x254));
  return;
}



// Function: Unwind@10016cea at 10016cea

void Unwind_10016cea(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x254));
  return;
}



// Function: Unwind@10016cf5 at 10016cf5

void Unwind_10016cf5(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x248));
  return;
}



// Function: Unwind@10016d00 at 10016d00

void Unwind_10016d00(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -600));
  return;
}



// Function: Unwind@10016d0b at 10016d0b

void Unwind_10016d0b(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -600));
  return;
}



// Function: Unwind@10016d16 at 10016d16

void Unwind_10016d16(void)

{
  int unaff_EBP;
  
  FUN_100018f5(*(int **)(unaff_EBP + -0x248));
  return;
}



// Function: Unwind@10016d21 at 10016d21

void Unwind_10016d21(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -600));
  return;
}



// Function: Unwind@10016d2c at 10016d2c

void Unwind_10016d2c(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x254));
  return;
}



// Function: Unwind@10016d37 at 10016d37

void Unwind_10016d37(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x240));
  return;
}



// Function: Unwind@10016d6a at 10016d6a

void Unwind_10016d6a(void)

{
  int unaff_EBP;
  
  FUN_10005644(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10016d72 at 10016d72

void Unwind_10016d72(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004315((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10016d98 at 10016d98

void Unwind_10016d98(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x31c));
  return;
}



// Function: Unwind@10016da3 at 10016da3

void Unwind_10016da3(void)

{
  int unaff_EBP;
  
  FUN_10001d2f((undefined4 *)(unaff_EBP + -0x2f8));
  return;
}



// Function: Unwind@10016dae at 10016dae

void Unwind_10016dae(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x2d8));
  return;
}



// Function: Unwind@10016db9 at 10016db9

void Unwind_10016db9(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x2d8));
  return;
}



// Function: Unwind@10016dc4 at 10016dc4

void Unwind_10016dc4(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x2d8));
  return;
}



// Function: Unwind@10016dcf at 10016dcf

void Unwind_10016dcf(void)

{
  int unaff_EBP;
  
  FUN_100147f2((undefined4 *)(unaff_EBP + -0x2dc));
  return;
}



// Function: Unwind@10016dda at 10016dda

void Unwind_10016dda(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x2d4));
  return;
}



// Function: Unwind@10016de5 at 10016de5

void Unwind_10016de5(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x2d4));
  return;
}



// Function: Unwind@10016df0 at 10016df0

void Unwind_10016df0(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x2d0));
  return;
}



// Function: Unwind@10016dfb at 10016dfb

void Unwind_10016dfb(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x2d0));
  return;
}



// Function: Unwind@10016e06 at 10016e06

void Unwind_10016e06(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x2e8));
  return;
}



// Function: Unwind@10016e11 at 10016e11

void Unwind_10016e11(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004315((_Container_base0 *)(unaff_EBP + -0x30c));
  return;
}



// Function: Unwind@10016e1c at 10016e1c

void Unwind_10016e1c(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x2e4));
  return;
}



// Function: Unwind@10016e27 at 10016e27

void Unwind_10016e27(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x2e4));
  return;
}



// Function: Unwind@10016e32 at 10016e32

void Unwind_10016e32(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -600));
  return;
}



// Function: Unwind@10016e3d at 10016e3d

void Unwind_10016e3d(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x23c));
  return;
}



// Function: Unwind@10016e48 at 10016e48

void Unwind_10016e48(void)

{
  int unaff_EBP;
  
  FUN_10002ccf((void *)(unaff_EBP + -0x290));
  return;
}



// Function: Unwind@10016e53 at 10016e53

void Unwind_10016e53(void)

{
  int unaff_EBP;
  
  FUN_10002ccf((void *)(unaff_EBP + -0x2c8));
  return;
}



// Function: Unwind@10016e5e at 10016e5e

void Unwind_10016e5e(void)

{
  int unaff_EBP;
  
  FUN_10002d05(unaff_EBP + -0x2cc);
  return;
}



// Function: Unwind@10016e69 at 10016e69

void Unwind_10016e69(void)

{
  int unaff_EBP;
  
  FUN_10003053(unaff_EBP + -0x2cc);
  return;
}



// Function: Unwind@10016e74 at 10016e74

void Unwind_10016e74(void)

{
  int unaff_EBP;
  
  FUN_10002d05(unaff_EBP + -0x2cc);
  return;
}



// Function: Unwind@10016e7f at 10016e7f

void Unwind_10016e7f(void)

{
  int unaff_EBP;
  
  FUN_10002ccf((void *)(unaff_EBP + -0x2c8));
  return;
}



// Function: Unwind@10016e8a at 10016e8a

void Unwind_10016e8a(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x2e4));
  return;
}



// Function: Unwind@10016e95 at 10016e95

void Unwind_10016e95(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x2d0));
  return;
}



// Function: Unwind@10016ea0 at 10016ea0

void Unwind_10016ea0(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x2d4));
  return;
}



// Function: Unwind@10016ed3 at 10016ed3

void Unwind_10016ed3(void)

{
  int unaff_EBP;
  
  FUN_100076ac(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10016ede at 10016ede

void Unwind_10016ede(void)

{
  int unaff_EBP;
  
  FUN_10005644(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10016ee6 at 10016ee6

void Unwind_10016ee6(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004315((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10016f0c at 10016f0c

void Unwind_10016f0c(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004315((_Container_base0 *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10016f17 at 10016f17

void Unwind_10016f17(void)

{
  int unaff_EBP;
  
  FUN_10005644(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10016f1f at 10016f1f

void Unwind_10016f1f(void)

{
  int unaff_EBP;
  
  FUN_100076ac(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10016f45 at 10016f45

void Unwind_10016f45(void)

{
  int unaff_EBP;
  
  FUN_10007cf5(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10016f68 at 10016f68

void Unwind_10016f68(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@10016f73 at 10016f73

void Unwind_10016f73(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@10016f7e at 10016f7e

void Unwind_10016f7e(void)

{
  int unaff_EBP;
  
  FUN_10007dab((void *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10016f89 at 10016f89

void Unwind_10016f89(void)

{
  int unaff_EBP;
  
  FUN_10007cf5(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10016f91 at 10016f91

void Unwind_10016f91(void)

{
  int unaff_EBP;
  
  FUN_100056fc(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10016f99 at 10016f99

void Unwind_10016f99(void)

{
  int unaff_EBP;
  
  FUN_100056fc(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10016fbc at 10016fbc

void Unwind_10016fbc(void)

{
  int unaff_EBP;
  
  FUN_10001ae9(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10016fc4 at 10016fc4

void Unwind_10016fc4(void)

{
  int unaff_EBP;
  
  FUN_10007cf5(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10017002 at 10017002

void Unwind_10017002(void)

{
  int unaff_EBP;
  
  FUN_100011c9(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10017025 at 10017025

void Unwind_10017025(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001702f at 1001702f

void Unwind_1001702f(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10017052 at 10017052

void Unwind_10017052(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001705a at 1001705a

void Unwind_1001705a(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10017062 at 10017062

void Unwind_10017062(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001706a at 1001706a

void Unwind_1001706a(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10017072 at 10017072

void Unwind_10017072(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001707a at 1001707a

void Unwind_1001707a(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001709d at 1001709d

void Unwind_1001709d(void)

{
  int unaff_EBP;
  
  FUN_100081fa((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100170c0 at 100170c0

void Unwind_100170c0(void)

{
  int unaff_EBP;
  
  FUN_100081fa((undefined4 *)(unaff_EBP + -0x238));
  return;
}



// Function: Unwind@100170cb at 100170cb

void Unwind_100170cb(void)

{
  int unaff_EBP;
  
  FUN_100014b1((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@100170d6 at 100170d6

void Unwind_100170d6(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@100170e1 at 100170e1

void Unwind_100170e1(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@100170ec at 100170ec

void Unwind_100170ec(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@100170f7 at 100170f7

void Unwind_100170f7(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10017102 at 10017102

void Unwind_10017102(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001710d at 1001710d

void Unwind_1001710d(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10017118 at 10017118

void Unwind_10017118(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10017123 at 10017123

void Unwind_10017123(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1001712e at 1001712e

void Unwind_1001712e(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10017161 at 10017161

void Unwind_10017161(void)

{
  int unaff_EBP;
  
  FUN_10007d2f(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10017184 at 10017184

void Unwind_10017184(void)

{
  int unaff_EBP;
  
  FUN_100056fc(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001718c at 1001718c

void Unwind_1001718c(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@10017197 at 10017197

void Unwind_10017197(void)

{
  int unaff_EBP;
  
  FUN_100056fc(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001719f at 1001719f

void Unwind_1001719f(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@100171aa at 100171aa

void Unwind_100171aa(void)

{
  int unaff_EBP;
  
  FUN_10007dab((void *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@100171eb at 100171eb

void Unwind_100171eb(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100171f3 at 100171f3

void Unwind_100171f3(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004315((_Container_base0 *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@100171fb at 100171fb

void Unwind_100171fb(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10017203 at 10017203

void Unwind_10017203(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001720b at 1001720b

void Unwind_1001720b(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10017213 at 10017213

void Unwind_10017213(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001721b at 1001721b

void Unwind_1001721b(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10017248 at 10017248

void Unwind_10017248(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10017250 at 10017250

void Unwind_10017250(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004315((_Container_base0 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10017258 at 10017258

void Unwind_10017258(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10017260 at 10017260

void Unwind_10017260(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10017268 at 10017268

void Unwind_10017268(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001728b at 1001728b

void Unwind_1001728b(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@10017293 at 10017293

void Unwind_10017293(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004315((_Container_base0 *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001729b at 1001729b

void Unwind_1001729b(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100172a3 at 100172a3

void Unwind_100172a3(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100172ab at 100172ab

void Unwind_100172ab(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@100172b3 at 100172b3

void Unwind_100172b3(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@100172bb at 100172bb

void Unwind_100172bb(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@100172e8 at 100172e8

void Unwind_100172e8(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@100172f0 at 100172f0

void Unwind_100172f0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004315((_Container_base0 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@100172f8 at 100172f8

void Unwind_100172f8(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10017300 at 10017300

void Unwind_10017300(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10017308 at 10017308

void Unwind_10017308(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10017310 at 10017310

void Unwind_10017310(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001733d at 1001733d

void Unwind_1001733d(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@10017345 at 10017345

void Unwind_10017345(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004315((_Container_base0 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001734d at 1001734d

void Unwind_1001734d(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10017355 at 10017355

void Unwind_10017355(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001735d at 1001735d

void Unwind_1001735d(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10017365 at 10017365

void Unwind_10017365(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10017392 at 10017392

void Unwind_10017392(void)

{
  ~basic_string<>(&DAT_10028e98);
  return;
}



// Function: Unwind@1001739c at 1001739c

void Unwind_1001739c(void)

{
  ~basic_string<>(&DAT_10028eb4);
  return;
}



// Function: Unwind@100173a6 at 100173a6

void Unwind_100173a6(void)

{
  ~basic_string<>(&DAT_10028ed0);
  return;
}



// Function: Unwind@100173b0 at 100173b0

void Unwind_100173b0(void)

{
  ~basic_string<>(&DAT_10028eec);
  return;
}



// Function: Unwind@100173ba at 100173ba

void Unwind_100173ba(void)

{
  ~basic_string<>(&DAT_10028f08);
  return;
}



// Function: Unwind@100173c4 at 100173c4

void Unwind_100173c4(void)

{
  ~basic_string<>(&DAT_10028f24);
  return;
}



// Function: Unwind@100173ce at 100173ce

void Unwind_100173ce(void)

{
  ~basic_string<>(&DAT_10028f40);
  return;
}



// Function: Unwind@100173d8 at 100173d8

void Unwind_100173d8(void)

{
  ~basic_string<>(&DAT_10028f5c);
  return;
}



// Function: Unwind@100173e2 at 100173e2

void Unwind_100173e2(void)

{
  ~basic_string<>(&DAT_10028f78);
  return;
}



// Function: Unwind@100173ec at 100173ec

void Unwind_100173ec(void)

{
  ~basic_string<>(&DAT_10028f94);
  return;
}



// Function: Unwind@100173f6 at 100173f6

void Unwind_100173f6(void)

{
  ~basic_string<>(&DAT_10028fb0);
  return;
}



// Function: Unwind@10017400 at 10017400

void Unwind_10017400(void)

{
  ~basic_string<>(&DAT_10028fcc);
  return;
}



// Function: Unwind@1001740a at 1001740a

void Unwind_1001740a(void)

{
  ~basic_string<>(&DAT_10028fe8);
  return;
}



// Function: Unwind@1001742f at 1001742f

void Unwind_1001742f(void)

{
  int unaff_EBP;
  
  FUN_10009105(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10017452 at 10017452

void Unwind_10017452(void)

{
  int unaff_EBP;
  
  FUN_1000f3c4(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10017475 at 10017475

void Unwind_10017475(void)

{
  int unaff_EBP;
  
  FUN_1001171d(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10017498 at 10017498

void Unwind_10017498(void)

{
  int unaff_EBP;
  
  FUN_10007dc9(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100174bb at 100174bb

void Unwind_100174bb(void)

{
  DAT_10029efc = DAT_10029efc & 0xfffffffe;
  return;
}



// Function: Unwind@100174e4 at 100174e4

void Unwind_100174e4(void)

{
  int unaff_EBP;
  
  CWinApp::~CWinApp(*(CWinApp **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10017507 at 10017507

void Unwind_10017507(void)

{
  int unaff_EBP;
  
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001757b at 1001757b

void Unwind_1001757b(void)

{
  int unaff_EBP;
  
  FUN_1000a260(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001759e at 1001759e

void Unwind_1001759e(void)

{
  int unaff_EBP;
  
  FUN_10001d2f((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@100175d1 at 100175d1

void Unwind_100175d1(void)

{
  int unaff_EBP;
  
  FUN_100014b1((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@10017604 at 10017604

void Unwind_10017604(void)

{
  int unaff_EBP;
  
  FUN_10009d02((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001762a at 1001762a

void Unwind_1001762a(void)

{
  FUN_100095c3();
  return;
}



// Function: Unwind@10017641 at 10017641

void Unwind_10017641(void)

{
  FUN_100095c3();
  return;
}



// Function: Unwind@10017674 at 10017674

void Unwind_10017674(void)

{
  int unaff_EBP;
  
  FUN_10009d02((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001767f at 1001767f

void Unwind_1001767f(void)

{
  int unaff_EBP;
  
  FUN_1000a66e(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@100176a5 at 100176a5

void Unwind_100176a5(void)

{
  int unaff_EBP;
  
  FUN_1000932c(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@100176cb at 100176cb

void Unwind_100176cb(void)

{
  int unaff_EBP;
  
  FUN_1000932c(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@100176d6 at 100176d6

void Unwind_100176d6(void)

{
  int unaff_EBP;
  
  FUN_1000f3c4(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100176f9 at 100176f9

void Unwind_100176f9(void)

{
  int unaff_EBP;
  
  FUN_10009369(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001771f at 1001771f

void Unwind_1001771f(void)

{
  int unaff_EBP;
  
  FUN_10009369(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001772a at 1001772a

void Unwind_1001772a(void)

{
  int unaff_EBP;
  
  FUN_1001171d(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001774d at 1001774d

void Unwind_1001774d(void)

{
  int unaff_EBP;
  
  FUN_100093a6(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10017773 at 10017773

void Unwind_10017773(void)

{
  int unaff_EBP;
  
  FUN_100093a6(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001777e at 1001777e

void Unwind_1001777e(void)

{
  int unaff_EBP;
  
  FUN_10007dc9(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100177a1 at 100177a1

void Unwind_100177a1(void)

{
  int unaff_EBP;
  
  FUN_1000a260(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100177a9 at 100177a9

void Unwind_100177a9(void)

{
  int unaff_EBP;
  
  FUN_1000a265(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100177cc at 100177cc

void Unwind_100177cc(void)

{
  int unaff_EBP;
  
  FUN_1000a265(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100177d4 at 100177d4

void Unwind_100177d4(void)

{
  int unaff_EBP;
  
  FUN_1000a260(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100177f7 at 100177f7

void Unwind_100177f7(void)

{
  int unaff_EBP;
  
  thunk_FUN_10009cd5(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001781a at 1001781a

void Unwind_1001781a(void)

{
  int unaff_EBP;
  
  FUN_1000ab95((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10017840 at 10017840

void Unwind_10017840(void)

{
  int unaff_EBP;
  
  FUN_100097d8(unaff_EBP + -0x6c);
  return;
}



// Function: Unwind@1001786d at 1001786d

void Unwind_1001786d(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10017878 at 10017878

void Unwind_10017878(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10017883 at 10017883

void Unwind_10017883(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001788e at 1001788e

void Unwind_1001788e(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10017899 at 10017899

void Unwind_10017899(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@100178a4 at 100178a4

void Unwind_100178a4(void)

{
  int unaff_EBP;
  
  FUN_100014b1((int *)(unaff_EBP + -0x1c8));
  return;
}



// Function: Unwind@100178af at 100178af

void Unwind_100178af(void)

{
  int unaff_EBP;
  
  FUN_10001d2f((undefined4 *)(unaff_EBP + -0x1c4));
  return;
}



// Function: Unwind@100178ba at 100178ba

void Unwind_100178ba(void)

{
  int unaff_EBP;
  
  FUN_10001d2f((undefined4 *)(unaff_EBP + -0x1b8));
  return;
}



// Function: Unwind@100178c5 at 100178c5

void Unwind_100178c5(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@100178d0 at 100178d0

void Unwind_100178d0(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10017903 at 10017903

void Unwind_10017903(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001790b at 1001790b

void Unwind_1001790b(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10017913 at 10017913

void Unwind_10017913(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001791b at 1001791b

void Unwind_1001791b(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10017923 at 10017923

void Unwind_10017923(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10017946 at 10017946

void Unwind_10017946(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10017951 at 10017951

void Unwind_10017951(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1001795c at 1001795c

void Unwind_1001795c(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10017967 at 10017967

void Unwind_10017967(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10017972 at 10017972

void Unwind_10017972(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1001797d at 1001797d

void Unwind_1001797d(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@100179b0 at 100179b0

void Unwind_100179b0(void)

{
  int unaff_EBP;
  
  FUN_100081fa((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100179d3 at 100179d3

void Unwind_100179d3(void)

{
  int unaff_EBP;
  
  FUN_1000a66e(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@100179de at 100179de

void Unwind_100179de(void)

{
  int unaff_EBP;
  
  FUN_10009d02((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10017a04 at 10017a04

void Unwind_10017a04(void)

{
  int unaff_EBP;
  
  FUN_1000b683(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10017a27 at 10017a27

void Unwind_10017a27(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10017a4c at 10017a4c

void Unwind_10017a4c(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10017a71 at 10017a71

void Unwind_10017a71(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10017a96 at 10017a96

void Unwind_10017a96(void)

{
  int unaff_EBP;
  
  FUN_1000a651((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10017a9e at 10017a9e

void Unwind_10017a9e(void)

{
  int unaff_EBP;
  
  FUN_1000a651((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10017ac1 at 10017ac1

void Unwind_10017ac1(void)

{
  int unaff_EBP;
  
  FUN_1000a661((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@10017acc at 10017acc

void Unwind_10017acc(void)

{
  int unaff_EBP;
  
  FUN_100014b1((int *)(unaff_EBP + -0x2120));
  return;
}



// Function: Unwind@10017ad7 at 10017ad7

void Unwind_10017ad7(void)

{
  int unaff_EBP;
  
  FUN_1000a661((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@10017b0a at 10017b0a

void Unwind_10017b0a(void)

{
  int unaff_EBP;
  
  FUN_10001d2f((undefined4 *)(unaff_EBP + -0x2230));
  return;
}



// Function: Unwind@10017b15 at 10017b15

void Unwind_10017b15(void)

{
  int unaff_EBP;
  
  FUN_10001d2f((undefined4 *)(unaff_EBP + -0x2240));
  return;
}



// Function: Unwind@10017b20 at 10017b20

void Unwind_10017b20(void)

{
  int unaff_EBP;
  
  FUN_10001d2f((undefined4 *)(unaff_EBP + -0x2258));
  return;
}



// Function: Unwind@10017b2b at 10017b2b

void Unwind_10017b2b(void)

{
  int unaff_EBP;
  
  FUN_10001d2f((undefined4 *)(unaff_EBP + -0x2264));
  return;
}



// Function: Unwind@10017b36 at 10017b36

void Unwind_10017b36(void)

{
  int unaff_EBP;
  
  FUN_10001d2f((undefined4 *)(unaff_EBP + -0x224c));
  return;
}



// Function: Unwind@10017b69 at 10017b69

void Unwind_10017b69(void)

{
  int unaff_EBP;
  
  FUN_100081fa((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10017b8c at 10017b8c

void Unwind_10017b8c(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10017bb1 at 10017bb1

void Unwind_10017bb1(void)

{
  int unaff_EBP;
  
  FUN_100014b1((int *)(unaff_EBP + -0x420));
  return;
}



// Function: Unwind@10017bbc at 10017bbc

void Unwind_10017bbc(void)

{
  int unaff_EBP;
  
  FUN_1000a661((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@10017bef at 10017bef

void Unwind_10017bef(void)

{
  int unaff_EBP;
  
  FUN_100014b1((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10017c12 at 10017c12

void Unwind_10017c12(void)

{
  int unaff_EBP;
  
  thunk_FUN_10009cd5(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@10017c1d at 10017c1d

void Unwind_10017c1d(void)

{
  int unaff_EBP;
  
  FUN_1000ab95((int *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@10017c28 at 10017c28

void Unwind_10017c28(void)

{
  int unaff_EBP;
  
  FUN_1000abbf((undefined4 *)(unaff_EBP + -0xa5c));
  return;
}



// Function: Unwind@10017c33 at 10017c33

void Unwind_10017c33(void)

{
  int unaff_EBP;
  
  FUN_100014b1((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@10017c66 at 10017c66

void Unwind_10017c66(void)

{
  int unaff_EBP;
  
  thunk_FUN_10009cd5(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@10017c71 at 10017c71

void Unwind_10017c71(void)

{
  int unaff_EBP;
  
  FUN_1000ab95((int *)(unaff_EBP + -0xa54));
  return;
}



// Function: Unwind@10017c7c at 10017c7c

void Unwind_10017c7c(void)

{
  int unaff_EBP;
  
  FUN_1000abbf((undefined4 *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@10017c87 at 10017c87

void Unwind_10017c87(void)

{
  int unaff_EBP;
  
  FUN_100014b1((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@10017cba at 10017cba

void Unwind_10017cba(void)

{
  CWinApp::~CWinApp((CWinApp *)&DAT_10029f30);
  return;
}



// Function: Unwind@10017cdf at 10017cdf

void Unwind_10017cdf(void)

{
  FUN_1000a265(0x10029f00);
  return;
}



// Function: Unwind@10017ce9 at 10017ce9

void Unwind_10017ce9(void)

{
  FUN_1000a260(0x10029f00);
  return;
}



// Function: Unwind@10017d0e at 10017d0e

void Unwind_10017d0e(void)

{
  int unaff_EBP;
  
  FUN_100056fc(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10017d31 at 10017d31

void Unwind_10017d31(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10017d34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10017d55 at 10017d55

void Unwind_10017d55(void)

{
  int unaff_EBP;
  
  FUN_10001d2f((undefined4 *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10017d88 at 10017d88

void Unwind_10017d88(void)

{
  int unaff_EBP;
  
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10017d90 at 10017d90

void Unwind_10017d90(void)

{
  int unaff_EBP;
  
  FUN_10001d2f((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10017d98 at 10017d98

void Unwind_10017d98(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10017dbb at 10017dbb

void Unwind_10017dbb(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x38);
  return;
}



// Function: Unwind@10017dc3 at 10017dc3

void Unwind_10017dc3(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x48);
  return;
}



// Function: Unwind@10017e01 at 10017e01

void Unwind_10017e01(void)

{
  int unaff_EBP;
  
  FUN_1000db1a(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10017e09 at 10017e09

void Unwind_10017e09(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10017e2f at 10017e2f

void Unwind_10017e2f(void)

{
  int unaff_EBP;
  
  FUN_10001d2f((undefined4 *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10017e3a at 10017e3a

void Unwind_10017e3a(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x234));
  return;
}



// Function: Unwind@10017e88 at 10017e88

void Unwind_10017e88(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10017eae at 10017eae

void Unwind_10017eae(void)

{
  int unaff_EBP;
  
  FUN_1000db1a(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10017ed1 at 10017ed1

void Unwind_10017ed1(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10017ed9 at 10017ed9

void Unwind_10017ed9(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10017ee1 at 10017ee1

void Unwind_10017ee1(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10017ee9 at 10017ee9

void Unwind_10017ee9(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10017ef1 at 10017ef1

void Unwind_10017ef1(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10017ef9 at 10017ef9

void Unwind_10017ef9(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10017f01 at 10017f01

void Unwind_10017f01(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10017f09 at 10017f09

void Unwind_10017f09(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10017f11 at 10017f11

void Unwind_10017f11(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10017f19 at 10017f19

void Unwind_10017f19(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10017f21 at 10017f21

void Unwind_10017f21(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10017f29 at 10017f29

void Unwind_10017f29(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10017f31 at 10017f31

void Unwind_10017f31(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10017f54 at 10017f54

void Unwind_10017f54(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -300));
  return;
}



// Function: Unwind@10017f5f at 10017f5f

void Unwind_10017f5f(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x110));
  return;
}



// Function: Unwind@10017f6a at 10017f6a

void Unwind_10017f6a(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x110));
  return;
}



// Function: Unwind@10017f75 at 10017f75

void Unwind_10017f75(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@10017f7d at 10017f7d

void Unwind_10017f7d(void)

{
  int unaff_EBP;
  
  FUN_100147f2((undefined4 *)(unaff_EBP + -0x10c));
  return;
}



// Function: Unwind@10017f88 at 10017f88

void Unwind_10017f88(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0xf8));
  return;
}



// Function: Unwind@10017f93 at 10017f93

void Unwind_10017f93(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0xf8));
  return;
}



// Function: Unwind@10017f9e at 10017f9e

void Unwind_10017f9e(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x104));
  return;
}



// Function: Unwind@10017fa9 at 10017fa9

void Unwind_10017fa9(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0xf4));
  return;
}



// Function: Unwind@10017fb4 at 10017fb4

void Unwind_10017fb4(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0xf4));
  return;
}



// Function: Unwind@10017fbf at 10017fbf

void Unwind_10017fbf(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10017fc7 at 10017fc7

void Unwind_10017fc7(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10017fcf at 10017fcf

void Unwind_10017fcf(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@10017fda at 10017fda

void Unwind_10017fda(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0xf0));
  return;
}



// Function: Unwind@10017fe5 at 10017fe5

void Unwind_10017fe5(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@10017ff0 at 10017ff0

void Unwind_10017ff0(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0xb8));
  return;
}



// Function: Unwind@10017ffb at 10017ffb

void Unwind_10017ffb(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x138));
  return;
}



// Function: Unwind@10018006 at 10018006

void Unwind_10018006(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x130));
  return;
}



// Function: Unwind@10018011 at 10018011

void Unwind_10018011(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x134));
  return;
}



// Function: Unwind@1001801c at 1001801c

void Unwind_1001801c(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0xfc));
  return;
}



// Function: Unwind@10018027 at 10018027

void Unwind_10018027(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0xfc));
  return;
}



// Function: Unwind@10018032 at 10018032

void Unwind_10018032(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x16c);
  return;
}



// Function: Unwind@1001803d at 1001803d

void Unwind_1001803d(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x140));
  return;
}



// Function: Unwind@10018048 at 10018048

void Unwind_10018048(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x15c);
  return;
}



// Function: Unwind@10018053 at 10018053

void Unwind_10018053(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x11c));
  return;
}



// Function: Unwind@1001805e at 1001805e

void Unwind_1001805e(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0xfc));
  return;
}



// Function: Unwind@10018069 at 10018069

void Unwind_10018069(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0xf4));
  return;
}



// Function: Unwind@10018074 at 10018074

void Unwind_10018074(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0xf8));
  return;
}



// Function: Unwind@1001807f at 1001807f

void Unwind_1001807f(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x114));
  return;
}



// Function: Unwind@1001808a at 1001808a

void Unwind_1001808a(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x114));
  return;
}



// Function: Unwind@10018095 at 10018095

void Unwind_10018095(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001809d at 1001809d

void Unwind_1001809d(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0xfc));
  return;
}



// Function: Unwind@100180a8 at 100180a8

void Unwind_100180a8(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0xfc));
  return;
}



// Function: Unwind@100180b3 at 100180b3

void Unwind_100180b3(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x100));
  return;
}



// Function: Unwind@100180be at 100180be

void Unwind_100180be(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0xf4));
  return;
}



// Function: Unwind@100180c9 at 100180c9

void Unwind_100180c9(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0xf4));
  return;
}



// Function: Unwind@100180d4 at 100180d4

void Unwind_100180d4(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@100180dc at 100180dc

void Unwind_100180dc(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0xb8));
  return;
}



// Function: Unwind@100180e7 at 100180e7

void Unwind_100180e7(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0xf8));
  return;
}



// Function: Unwind@100180f2 at 100180f2

void Unwind_100180f2(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0xf8));
  return;
}



// Function: Unwind@100180fd at 100180fd

void Unwind_100180fd(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0xf8));
  return;
}



// Function: Unwind@10018108 at 10018108

void Unwind_10018108(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0xf4));
  return;
}



// Function: Unwind@10018113 at 10018113

void Unwind_10018113(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x15c);
  return;
}



// Function: Unwind@1001811e at 1001811e

void Unwind_1001811e(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x11c));
  return;
}



// Function: Unwind@10018129 at 10018129

void Unwind_10018129(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0xf8));
  return;
}



// Function: Unwind@10018134 at 10018134

void Unwind_10018134(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0xf4));
  return;
}



// Function: Unwind@1001813f at 1001813f

void Unwind_1001813f(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0xfc));
  return;
}



// Function: Unwind@1001814a at 1001814a

void Unwind_1001814a(void)

{
  int unaff_EBP;
  
  FUN_100018f5(*(int **)(unaff_EBP + -0x118));
  return;
}



// Function: Unwind@10018155 at 10018155

void Unwind_10018155(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x114));
  return;
}



// Function: Unwind@10018160 at 10018160

void Unwind_10018160(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x110));
  return;
}



// Function: Unwind@10018193 at 10018193

void Unwind_10018193(void)

{
  FUN_100095c3();
  return;
}



// Function: Unwind@100181bc at 100181bc

void Unwind_100181bc(void)

{
  int unaff_EBP;
  
  FUN_10001ae9(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100181df at 100181df

void Unwind_100181df(void)

{
  int unaff_EBP;
  
  FUN_1000f359(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018202 at 10018202

void Unwind_10018202(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001820d at 1001820d

void Unwind_1001820d(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10018218 at 10018218

void Unwind_10018218(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(*(int *)(unaff_EBP + -0x10) + 0x14));
  return;
}



// Function: Unwind@10018223 at 10018223

void Unwind_10018223(void)

{
  int unaff_EBP;
  
  FUN_1000f3a6((void *)(*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@1001822e at 1001822e

void Unwind_1001822e(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004315((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@10018239 at 10018239

void Unwind_10018239(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000df2a((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@10018244 at 10018244

void Unwind_10018244(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000df2a((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x48));
  return;
}



// Function: Unwind@1001824f at 1001824f

void Unwind_1001824f(void)

{
  int unaff_EBP;
  
  FUN_1000f359(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018257 at 10018257

void Unwind_10018257(void)

{
  int unaff_EBP;
  
  FUN_100056fc(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001825f at 1001825f

void Unwind_1001825f(void)

{
  int unaff_EBP;
  
  FUN_100056fc(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018267 at 10018267

void Unwind_10018267(void)

{
  int unaff_EBP;
  
  FUN_100056fc(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001828a at 1001828a

void Unwind_1001828a(void)

{
  int unaff_EBP;
  
  FUN_10001ae9(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018292 at 10018292

void Unwind_10018292(void)

{
  int unaff_EBP;
  
  FUN_1000f359(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100182d0 at 100182d0

void Unwind_100182d0(void)

{
  int unaff_EBP;
  
  FUN_100056fc(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100182d8 at 100182d8

void Unwind_100182d8(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@100182e3 at 100182e3

void Unwind_100182e3(void)

{
  int unaff_EBP;
  
  FUN_100056fc(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100182eb at 100182eb

void Unwind_100182eb(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@100182f6 at 100182f6

void Unwind_100182f6(void)

{
  int unaff_EBP;
  
  FUN_100056fc(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100182fe at 100182fe

void Unwind_100182fe(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(*(int *)(unaff_EBP + -0x10) + 0x14));
  return;
}



// Function: Unwind@10018309 at 10018309

void Unwind_10018309(void)

{
  int unaff_EBP;
  
  FUN_1000f3a6((void *)(*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@10018314 at 10018314

void Unwind_10018314(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004315((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@1001831f at 1001831f

void Unwind_1001831f(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000df2a((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@1001832a at 1001832a

void Unwind_1001832a(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000df2a((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x48));
  return;
}



// Function: Unwind@10018350 at 10018350

void Unwind_10018350(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10018358 at 10018358

void Unwind_10018358(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10018360 at 10018360

void Unwind_10018360(void)

{
  int unaff_EBP;
  
  FUN_1000db1a(unaff_EBP + -0x4c);
  return;
}



// Function: Unwind@10018368 at 10018368

void Unwind_10018368(void)

{
  int unaff_EBP;
  
  FUN_1000dcff(unaff_EBP + -0x4c);
  return;
}



// Function: Unwind@10018370 at 10018370

void Unwind_10018370(void)

{
  int unaff_EBP;
  
  FUN_1000db1a(unaff_EBP + -0x4c);
  return;
}



// Function: Unwind@10018378 at 10018378

void Unwind_10018378(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@100183a5 at 100183a5

void Unwind_100183a5(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100183c8 at 100183c8

void Unwind_100183c8(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@100183d3 at 100183d3

void Unwind_100183d3(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004315((_Container_base0 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@100183db at 100183db

void Unwind_100183db(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004315((_Container_base0 *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@100183e3 at 100183e3

void Unwind_100183e3(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100183eb at 100183eb

void Unwind_100183eb(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100183f3 at 100183f3

void Unwind_100183f3(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@100183fb at 100183fb

void Unwind_100183fb(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10018403 at 10018403

void Unwind_10018403(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1001840b at 1001840b

void Unwind_1001840b(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10018413 at 10018413

void Unwind_10018413(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1001841b at 1001841b

void Unwind_1001841b(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001844b at 1001844b

void Unwind_1001844b(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004315((_Container_base0 *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@10018456 at 10018456

void Unwind_10018456(void)

{
  int unaff_EBP;
  
  FUN_100147f2((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001845e at 1001845e

void Unwind_1001845e(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@10018466 at 10018466

void Unwind_10018466(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@1001846e at 1001846e

void Unwind_1001846e(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10018476 at 10018476

void Unwind_10018476(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@1001847e at 1001847e

void Unwind_1001847e(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x98));
  return;
}



// Function: Unwind@10018489 at 10018489

void Unwind_10018489(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@10018491 at 10018491

void Unwind_10018491(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@10018499 at 10018499

void Unwind_10018499(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100184a1 at 100184a1

void Unwind_100184a1(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@100184a9 at 100184a9

void Unwind_100184a9(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@100184b1 at 100184b1

void Unwind_100184b1(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@100184bc at 100184bc

void Unwind_100184bc(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@100184c7 at 100184c7

void Unwind_100184c7(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@100184d2 at 100184d2

void Unwind_100184d2(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100184da at 100184da

void Unwind_100184da(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@100184e2 at 100184e2

void Unwind_100184e2(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@100184ed at 100184ed

void Unwind_100184ed(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@100184f8 at 100184f8

void Unwind_100184f8(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@10018503 at 10018503

void Unwind_10018503(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@1001850e at 1001850e

void Unwind_1001850e(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10018516 at 10018516

void Unwind_10018516(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@1001851e at 1001851e

void Unwind_1001851e(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10018526 at 10018526

void Unwind_10018526(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@10018556 at 10018556

void Unwind_10018556(void)

{
  int unaff_EBP;
  
  FUN_100147f2((undefined4 *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@1001855e at 1001855e

void Unwind_1001855e(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10018566 at 10018566

void Unwind_10018566(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@1001856e at 1001856e

void Unwind_1001856e(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@10018576 at 10018576

void Unwind_10018576(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@1001857e at 1001857e

void Unwind_1001857e(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@10018586 at 10018586

void Unwind_10018586(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001858e at 1001858e

void Unwind_1001858e(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@10018596 at 10018596

void Unwind_10018596(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001859e at 1001859e

void Unwind_1001859e(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100185a6 at 100185a6

void Unwind_100185a6(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@100185ae at 100185ae

void Unwind_100185ae(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@100185b6 at 100185b6

void Unwind_100185b6(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@100185be at 100185be

void Unwind_100185be(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@100185c6 at 100185c6

void Unwind_100185c6(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@100185ce at 100185ce

void Unwind_100185ce(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@100185d6 at 100185d6

void Unwind_100185d6(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0xa8);
  return;
}



// Function: Unwind@100185e1 at 100185e1

void Unwind_100185e1(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x94));
  return;
}



// Function: Unwind@100185ec at 100185ec

void Unwind_100185ec(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@100185f7 at 100185f7

void Unwind_100185f7(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@100185ff at 100185ff

void Unwind_100185ff(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10018607 at 10018607

void Unwind_10018607(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0xb8);
  return;
}



// Function: Unwind@10018612 at 10018612

void Unwind_10018612(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1001861d at 1001861d

void Unwind_1001861d(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10018625 at 10018625

void Unwind_10018625(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001862d at 1001862d

void Unwind_1001862d(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10018635 at 10018635

void Unwind_10018635(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001863d at 1001863d

void Unwind_1001863d(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@10018645 at 10018645

void Unwind_10018645(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@1001864d at 1001864d

void Unwind_1001864d(void)

{
  int unaff_EBP;
  
  FUN_100018f5(*(int **)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10018655 at 10018655

void Unwind_10018655(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10018685 at 10018685

void Unwind_10018685(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000df2a((_Container_base0 *)(unaff_EBP + -0x6c8));
  return;
}



// Function: Unwind@10018690 at 10018690

void Unwind_10018690(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000df2a((_Container_base0 *)(unaff_EBP + -0x6d8));
  return;
}



// Function: Unwind@1001869b at 1001869b

void Unwind_1001869b(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x638));
  return;
}



// Function: Unwind@100186a6 at 100186a6

void Unwind_100186a6(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x620));
  return;
}



// Function: Unwind@100186b1 at 100186b1

void Unwind_100186b1(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x620));
  return;
}



// Function: Unwind@100186bc at 100186bc

void Unwind_100186bc(void)

{
  int unaff_EBP;
  
  FUN_10001d2f((undefined4 *)(unaff_EBP + -0x698));
  return;
}



// Function: Unwind@100186c7 at 100186c7

void Unwind_100186c7(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x560));
  return;
}



// Function: Unwind@100186d2 at 100186d2

void Unwind_100186d2(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x660));
  return;
}



// Function: Unwind@100186dd at 100186dd

void Unwind_100186dd(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x660));
  return;
}



// Function: Unwind@100186e8 at 100186e8

void Unwind_100186e8(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x67c));
  return;
}



// Function: Unwind@100186f3 at 100186f3

void Unwind_100186f3(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x67c));
  return;
}



// Function: Unwind@100186fe at 100186fe

void Unwind_100186fe(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x60c));
  return;
}



// Function: Unwind@10018709 at 10018709

void Unwind_10018709(void)

{
  int unaff_EBP;
  
  FUN_10001d2f((undefined4 *)(unaff_EBP + -0x6a4));
  return;
}



// Function: Unwind@10018714 at 10018714

void Unwind_10018714(void)

{
  int unaff_EBP;
  
  FUN_100018f5(*(int **)(unaff_EBP + -0x620));
  return;
}



// Function: Unwind@1001871f at 1001871f

void Unwind_1001871f(void)

{
  int unaff_EBP;
  
  FUN_100018f5(*(int **)(unaff_EBP + -0x628));
  return;
}



// Function: Unwind@1001872a at 1001872a

void Unwind_1001872a(void)

{
  int unaff_EBP;
  
  FUN_100147f2((undefined4 *)(unaff_EBP + -0x60c));
  return;
}



// Function: Unwind@10018735 at 10018735

void Unwind_10018735(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x5d0));
  return;
}



// Function: Unwind@10018740 at 10018740

void Unwind_10018740(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x66c));
  return;
}



// Function: Unwind@1001874b at 1001874b

void Unwind_1001874b(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x66c));
  return;
}



// Function: Unwind@10018756 at 10018756

void Unwind_10018756(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x448));
  return;
}



// Function: Unwind@10018761 at 10018761

void Unwind_10018761(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x49c));
  return;
}



// Function: Unwind@1001876c at 1001876c

void Unwind_1001876c(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x49c));
  return;
}



// Function: Unwind@10018777 at 10018777

void Unwind_10018777(void)

{
  int unaff_EBP;
  
  FUN_100018f5(*(int **)(unaff_EBP + -0x628));
  return;
}



// Function: Unwind@10018782 at 10018782

void Unwind_10018782(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x64c));
  return;
}



// Function: Unwind@1001878d at 1001878d

void Unwind_1001878d(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x64c));
  return;
}



// Function: Unwind@10018798 at 10018798

void Unwind_10018798(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x648));
  return;
}



// Function: Unwind@100187a3 at 100187a3

void Unwind_100187a3(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x648));
  return;
}



// Function: Unwind@100187ae at 100187ae

void Unwind_100187ae(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x624));
  return;
}



// Function: Unwind@100187b9 at 100187b9

void Unwind_100187b9(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x618));
  return;
}



// Function: Unwind@100187c4 at 100187c4

void Unwind_100187c4(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x618));
  return;
}



// Function: Unwind@100187cf at 100187cf

void Unwind_100187cf(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x480));
  return;
}



// Function: Unwind@100187da at 100187da

void Unwind_100187da(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x464));
  return;
}



// Function: Unwind@100187e5 at 100187e5

void Unwind_100187e5(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x50c));
  return;
}



// Function: Unwind@100187f0 at 100187f0

void Unwind_100187f0(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x598));
  return;
}



// Function: Unwind@100187fb at 100187fb

void Unwind_100187fb(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x57c));
  return;
}



// Function: Unwind@10018806 at 10018806

void Unwind_10018806(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x5b4));
  return;
}



// Function: Unwind@10018811 at 10018811

void Unwind_10018811(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x528));
  return;
}



// Function: Unwind@1001881c at 1001881c

void Unwind_1001881c(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x544));
  return;
}



// Function: Unwind@10018827 at 10018827

void Unwind_10018827(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4b8));
  return;
}



// Function: Unwind@10018832 at 10018832

void Unwind_10018832(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x658));
  return;
}



// Function: Unwind@1001883d at 1001883d

void Unwind_1001883d(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4d4));
  return;
}



// Function: Unwind@10018848 at 10018848

void Unwind_10018848(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x644));
  return;
}



// Function: Unwind@10018853 at 10018853

void Unwind_10018853(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x644));
  return;
}



// Function: Unwind@1001885e at 1001885e

void Unwind_1001885e(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x5ec));
  return;
}



// Function: Unwind@10018869 at 10018869

void Unwind_10018869(void)

{
  int unaff_EBP;
  
  thunk_FUN_10004315((_Container_base0 *)(unaff_EBP + -0x4e4));
  return;
}



// Function: Unwind@10018874 at 10018874

void Unwind_10018874(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x640));
  return;
}



// Function: Unwind@1001887f at 1001887f

void Unwind_1001887f(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x49c));
  return;
}



// Function: Unwind@1001888a at 1001888a

void Unwind_1001888a(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x680));
  return;
}



// Function: Unwind@10018895 at 10018895

void Unwind_10018895(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x680));
  return;
}



// Function: Unwind@100188a0 at 100188a0

void Unwind_100188a0(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x678));
  return;
}



// Function: Unwind@100188ab at 100188ab

void Unwind_100188ab(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x680));
  return;
}



// Function: Unwind@100188b6 at 100188b6

void Unwind_100188b6(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x644));
  return;
}



// Function: Unwind@100188c1 at 100188c1

void Unwind_100188c1(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x618));
  return;
}



// Function: Unwind@100188cc at 100188cc

void Unwind_100188cc(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x648));
  return;
}



// Function: Unwind@100188d7 at 100188d7

void Unwind_100188d7(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x650));
  return;
}



// Function: Unwind@100188e2 at 100188e2

void Unwind_100188e2(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x650));
  return;
}



// Function: Unwind@100188ed at 100188ed

void Unwind_100188ed(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x63c));
  return;
}



// Function: Unwind@100188f8 at 100188f8

void Unwind_100188f8(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x63c));
  return;
}



// Function: Unwind@10018903 at 10018903

void Unwind_10018903(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x664));
  return;
}



// Function: Unwind@1001890e at 1001890e

void Unwind_1001890e(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x610));
  return;
}



// Function: Unwind@10018919 at 10018919

void Unwind_10018919(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x610));
  return;
}



// Function: Unwind@10018924 at 10018924

void Unwind_10018924(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x49c));
  return;
}



// Function: Unwind@1001892f at 1001892f

void Unwind_1001892f(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4b8));
  return;
}



// Function: Unwind@1001893a at 1001893a

void Unwind_1001893a(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x528));
  return;
}



// Function: Unwind@10018945 at 10018945

void Unwind_10018945(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4d4));
  return;
}



// Function: Unwind@10018950 at 10018950

void Unwind_10018950(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x5b4));
  return;
}



// Function: Unwind@1001895b at 1001895b

void Unwind_1001895b(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x544));
  return;
}



// Function: Unwind@10018966 at 10018966

void Unwind_10018966(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x5ec));
  return;
}



// Function: Unwind@10018971 at 10018971

void Unwind_10018971(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x598));
  return;
}



// Function: Unwind@1001897c at 1001897c

void Unwind_1001897c(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x57c));
  return;
}



// Function: Unwind@10018987 at 10018987

void Unwind_10018987(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x50c));
  return;
}



// Function: Unwind@10018992 at 10018992

void Unwind_10018992(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x480));
  return;
}



// Function: Unwind@1001899d at 1001899d

void Unwind_1001899d(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x464));
  return;
}



// Function: Unwind@100189a8 at 100189a8

void Unwind_100189a8(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x670));
  return;
}



// Function: Unwind@100189b3 at 100189b3

void Unwind_100189b3(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4f0));
  return;
}



// Function: Unwind@100189be at 100189be

void Unwind_100189be(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x684));
  return;
}



// Function: Unwind@100189c9 at 100189c9

void Unwind_100189c9(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x608));
  return;
}



// Function: Unwind@100189d4 at 100189d4

void Unwind_100189d4(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x640));
  return;
}



// Function: Unwind@100189df at 100189df

void Unwind_100189df(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x658));
  return;
}



// Function: Unwind@100189ea at 100189ea

void Unwind_100189ea(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x654));
  return;
}



// Function: Unwind@100189f5 at 100189f5

void Unwind_100189f5(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x610));
  return;
}



// Function: Unwind@10018a00 at 10018a00

void Unwind_10018a00(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x63c));
  return;
}



// Function: Unwind@10018a0b at 10018a0b

void Unwind_10018a0b(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x650));
  return;
}



// Function: Unwind@10018a16 at 10018a16

void Unwind_10018a16(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x64c));
  return;
}



// Function: Unwind@10018a21 at 10018a21

void Unwind_10018a21(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x66c));
  return;
}



// Function: Unwind@10018a2c at 10018a2c

void Unwind_10018a2c(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x67c));
  return;
}



// Function: Unwind@10018a37 at 10018a37

void Unwind_10018a37(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x660));
  return;
}



// Function: Unwind@10018a6a at 10018a6a

void Unwind_10018a6a(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10018a72 at 10018a72

void Unwind_10018a72(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10018a7a at 10018a7a

void Unwind_10018a7a(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10018a82 at 10018a82

void Unwind_10018a82(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10018a8a at 10018a8a

void Unwind_10018a8a(void)

{
  int unaff_EBP;
  
  FUN_1000db1a(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@10018a92 at 10018a92

void Unwind_10018a92(void)

{
  int unaff_EBP;
  
  FUN_1000dcff(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@10018a9a at 10018a9a

void Unwind_10018a9a(void)

{
  int unaff_EBP;
  
  FUN_1000db1a(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@10018aa2 at 10018aa2

void Unwind_10018aa2(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10018aaa at 10018aaa

void Unwind_10018aaa(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10018ad7 at 10018ad7

void Unwind_10018ad7(void)

{
  ~basic_string<>(&DAT_1002a1f0);
  return;
}



// Function: Unwind@10018ae1 at 10018ae1

void Unwind_10018ae1(void)

{
  ~basic_string<>(&DAT_1002a20c);
  return;
}



// Function: Unwind@10018aeb at 10018aeb

void Unwind_10018aeb(void)

{
  ~basic_string<>(&DAT_1002a228);
  return;
}



// Function: Unwind@10018af5 at 10018af5

void Unwind_10018af5(void)

{
  ~basic_string<>(&DAT_1002a244);
  return;
}



// Function: Unwind@10018aff at 10018aff

void Unwind_10018aff(void)

{
  ~basic_string<>(&DAT_1002a260);
  return;
}



// Function: Unwind@10018b09 at 10018b09

void Unwind_10018b09(void)

{
  ~basic_string<>(&DAT_1002a27c);
  return;
}



// Function: Unwind@10018b13 at 10018b13

void Unwind_10018b13(void)

{
  ~basic_string<>(&DAT_1002a298);
  return;
}



// Function: Unwind@10018b1d at 10018b1d

void Unwind_10018b1d(void)

{
  ~basic_string<>(&DAT_1002a2b4);
  return;
}



// Function: Unwind@10018b27 at 10018b27

void Unwind_10018b27(void)

{
  ~basic_string<>(&DAT_1002a2d0);
  return;
}



// Function: Unwind@10018b31 at 10018b31

void Unwind_10018b31(void)

{
  ~basic_string<>(&DAT_1002a2ec);
  return;
}



// Function: Unwind@10018b3b at 10018b3b

void Unwind_10018b3b(void)

{
  ~basic_string<>(&DAT_1002a308);
  return;
}



// Function: Unwind@10018b45 at 10018b45

void Unwind_10018b45(void)

{
  ~basic_string<>(&DAT_1002a324);
  return;
}



// Function: Unwind@10018b4f at 10018b4f

void Unwind_10018b4f(void)

{
  ~basic_string<>(&DAT_1002a340);
  return;
}



// Function: Unwind@10018b74 at 10018b74

void Unwind_10018b74(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@10018b7f at 10018b7f

void Unwind_10018b7f(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@10018b8a at 10018b8a

void Unwind_10018b8a(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10018b95 at 10018b95

void Unwind_10018b95(void)

{
  int unaff_EBP;
  
  FUN_100056fc(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018b9d at 10018b9d

void Unwind_10018b9d(void)

{
  int unaff_EBP;
  
  FUN_100056fc(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018ba5 at 10018ba5

void Unwind_10018ba5(void)

{
  int unaff_EBP;
  
  FUN_100056fc(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018bc8 at 10018bc8

void Unwind_10018bc8(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018bd0 at 10018bd0

void Unwind_10018bd0(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018bf3 at 10018bf3

void Unwind_10018bf3(void)

{
  int unaff_EBP;
  
  FUN_100056fc(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018bfb at 10018bfb

void Unwind_10018bfb(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@10018c06 at 10018c06

void Unwind_10018c06(void)

{
  int unaff_EBP;
  
  FUN_100056fc(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018c0e at 10018c0e

void Unwind_10018c0e(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@10018c19 at 10018c19

void Unwind_10018c19(void)

{
  int unaff_EBP;
  
  FUN_100056fc(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018c21 at 10018c21

void Unwind_10018c21(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10018c47 at 10018c47

void Unwind_10018c47(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10018c4f at 10018c4f

void Unwind_10018c4f(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10018c57 at 10018c57

void Unwind_10018c57(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10018c7a at 10018c7a

void Unwind_10018c7a(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x284));
  return;
}



// Function: Unwind@10018c85 at 10018c85

void Unwind_10018c85(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x250));
  return;
}



// Function: Unwind@10018c90 at 10018c90

void Unwind_10018c90(void)

{
  int unaff_EBP;
  
  FUN_10001d2f((undefined4 *)(unaff_EBP + -0x26c));
  return;
}



// Function: Unwind@10018c9b at 10018c9b

void Unwind_10018c9b(void)

{
  int unaff_EBP;
  
  FUN_100018f5(*(int **)(unaff_EBP + -0x240));
  return;
}



// Function: Unwind@10018ca6 at 10018ca6

void Unwind_10018ca6(void)

{
  int unaff_EBP;
  
  FUN_100147f2((undefined4 *)(unaff_EBP + -0x250));
  return;
}



// Function: Unwind@10018cb1 at 10018cb1

void Unwind_10018cb1(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x248));
  return;
}



// Function: Unwind@10018cbc at 10018cbc

void Unwind_10018cbc(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x248));
  return;
}



// Function: Unwind@10018cc7 at 10018cc7

void Unwind_10018cc7(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x23c));
  return;
}



// Function: Unwind@10018cd2 at 10018cd2

void Unwind_10018cd2(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x24c));
  return;
}



// Function: Unwind@10018cdd at 10018cdd

void Unwind_10018cdd(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x24c));
  return;
}



// Function: Unwind@10018ce8 at 10018ce8

void Unwind_10018ce8(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x240));
  return;
}



// Function: Unwind@10018cf3 at 10018cf3

void Unwind_10018cf3(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -600));
  return;
}



// Function: Unwind@10018cfe at 10018cfe

void Unwind_10018cfe(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -600));
  return;
}



// Function: Unwind@10018d09 at 10018d09

void Unwind_10018d09(void)

{
  int unaff_EBP;
  
  FUN_100018f5(*(int **)(unaff_EBP + -0x240));
  return;
}



// Function: Unwind@10018d14 at 10018d14

void Unwind_10018d14(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -600));
  return;
}



// Function: Unwind@10018d1f at 10018d1f

void Unwind_10018d1f(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x24c));
  return;
}



// Function: Unwind@10018d2a at 10018d2a

void Unwind_10018d2a(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x248));
  return;
}



// Function: Unwind@10018d5d at 10018d5d

void Unwind_10018d5d(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10018d65 at 10018d65

void Unwind_10018d65(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10018d6d at 10018d6d

void Unwind_10018d6d(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018d90 at 10018d90

void Unwind_10018d90(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10018d98 at 10018d98

void Unwind_10018d98(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10018dbb at 10018dbb

void Unwind_10018dbb(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x32c));
  return;
}



// Function: Unwind@10018dc6 at 10018dc6

void Unwind_10018dc6(void)

{
  int unaff_EBP;
  
  FUN_10001d2f((undefined4 *)(unaff_EBP + -0x31c));
  return;
}



// Function: Unwind@10018dd1 at 10018dd1

void Unwind_10018dd1(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x2f8));
  return;
}



// Function: Unwind@10018ddc at 10018ddc

void Unwind_10018ddc(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x2f8));
  return;
}



// Function: Unwind@10018de7 at 10018de7

void Unwind_10018de7(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x2e8));
  return;
}



// Function: Unwind@10018df2 at 10018df2

void Unwind_10018df2(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x2e8));
  return;
}



// Function: Unwind@10018dfd at 10018dfd

void Unwind_10018dfd(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x2f0));
  return;
}



// Function: Unwind@10018e08 at 10018e08

void Unwind_10018e08(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x2f0));
  return;
}



// Function: Unwind@10018e13 at 10018e13

void Unwind_10018e13(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x2ec));
  return;
}



// Function: Unwind@10018e1e at 10018e1e

void Unwind_10018e1e(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x2ec));
  return;
}



// Function: Unwind@10018e29 at 10018e29

void Unwind_10018e29(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x2f4));
  return;
}



// Function: Unwind@10018e34 at 10018e34

void Unwind_10018e34(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x2f4));
  return;
}



// Function: Unwind@10018e3f at 10018e3f

void Unwind_10018e3f(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x290));
  return;
}



// Function: Unwind@10018e4a at 10018e4a

void Unwind_10018e4a(void)

{
  int unaff_EBP;
  
  FUN_100018f5(*(int **)(unaff_EBP + -0x2f4));
  return;
}



// Function: Unwind@10018e55 at 10018e55

void Unwind_10018e55(void)

{
  int unaff_EBP;
  
  FUN_100147f2((undefined4 *)(unaff_EBP + -0x2fc));
  return;
}



// Function: Unwind@10018e60 at 10018e60

void Unwind_10018e60(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x274));
  return;
}



// Function: Unwind@10018e6b at 10018e6b

void Unwind_10018e6b(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x304));
  return;
}



// Function: Unwind@10018e76 at 10018e76

void Unwind_10018e76(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -600));
  return;
}



// Function: Unwind@10018e81 at 10018e81

void Unwind_10018e81(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x23c));
  return;
}



// Function: Unwind@10018e8c at 10018e8c

void Unwind_10018e8c(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2ac));
  return;
}



// Function: Unwind@10018e97 at 10018e97

void Unwind_10018e97(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c8));
  return;
}



// Function: Unwind@10018ea2 at 10018ea2

void Unwind_10018ea2(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2e4));
  return;
}



// Function: Unwind@10018ead at 10018ead

void Unwind_10018ead(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x2ec));
  return;
}



// Function: Unwind@10018eb8 at 10018eb8

void Unwind_10018eb8(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x2f0));
  return;
}



// Function: Unwind@10018ec3 at 10018ec3

void Unwind_10018ec3(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x2e8));
  return;
}



// Function: Unwind@10018ece at 10018ece

void Unwind_10018ece(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x2f8));
  return;
}



// Function: Unwind@10018f01 at 10018f01

void Unwind_10018f01(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x510));
  return;
}



// Function: Unwind@10018f0c at 10018f0c

void Unwind_10018f0c(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000df2a((_Container_base0 *)(unaff_EBP + -0x574));
  return;
}



// Function: Unwind@10018f17 at 10018f17

void Unwind_10018f17(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000df2a((_Container_base0 *)(unaff_EBP + -0x564));
  return;
}



// Function: Unwind@10018f22 at 10018f22

void Unwind_10018f22(void)

{
  int unaff_EBP;
  
  FUN_10001d2f((undefined4 *)(unaff_EBP + -0x548));
  return;
}



// Function: Unwind@10018f2d at 10018f2d

void Unwind_10018f2d(void)

{
  int unaff_EBP;
  
  FUN_100018f5(*(int **)(unaff_EBP + -0x4e4));
  return;
}



// Function: Unwind@10018f38 at 10018f38

void Unwind_10018f38(void)

{
  int unaff_EBP;
  
  FUN_100147f2((undefined4 *)(unaff_EBP + -0x4e4));
  return;
}



// Function: Unwind@10018f43 at 10018f43

void Unwind_10018f43(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x4c0));
  return;
}



// Function: Unwind@10018f4e at 10018f4e

void Unwind_10018f4e(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x4c0));
  return;
}



// Function: Unwind@10018f59 at 10018f59

void Unwind_10018f59(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x444));
  return;
}



// Function: Unwind@10018f64 at 10018f64

void Unwind_10018f64(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x4d0));
  return;
}



// Function: Unwind@10018f6f at 10018f6f

void Unwind_10018f6f(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x4d0));
  return;
}



// Function: Unwind@10018f7a at 10018f7a

void Unwind_10018f7a(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x4cc));
  return;
}



// Function: Unwind@10018f85 at 10018f85

void Unwind_10018f85(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x4bc));
  return;
}



// Function: Unwind@10018f90 at 10018f90

void Unwind_10018f90(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x4bc));
  return;
}



// Function: Unwind@10018f9b at 10018f9b

void Unwind_10018f9b(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x4bc));
  return;
}



// Function: Unwind@10018fa6 at 10018fa6

void Unwind_10018fa6(void)

{
  int unaff_EBP;
  
  FUN_100018f5(*(int **)(unaff_EBP + -0x4e8));
  return;
}



// Function: Unwind@10018fb1 at 10018fb1

void Unwind_10018fb1(void)

{
  int unaff_EBP;
  
  FUN_100147f2((undefined4 *)(unaff_EBP + -0x4cc));
  return;
}



// Function: Unwind@10018fbc at 10018fbc

void Unwind_10018fbc(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x47c));
  return;
}



// Function: Unwind@10018fc7 at 10018fc7

void Unwind_10018fc7(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x4d4));
  return;
}



// Function: Unwind@10018fd2 at 10018fd2

void Unwind_10018fd2(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x4d4));
  return;
}



// Function: Unwind@10018fdd at 10018fdd

void Unwind_10018fdd(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x4d8));
  return;
}



// Function: Unwind@10018fe8 at 10018fe8

void Unwind_10018fe8(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x4d8));
  return;
}



// Function: Unwind@10018ff3 at 10018ff3

void Unwind_10018ff3(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x5c4);
  return;
}



// Function: Unwind@10018ffe at 10018ffe

void Unwind_10018ffe(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x518));
  return;
}



// Function: Unwind@10019009 at 10019009

void Unwind_10019009(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x524));
  return;
}



// Function: Unwind@10019014 at 10019014

void Unwind_10019014(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x4c4));
  return;
}



// Function: Unwind@1001901f at 1001901f

void Unwind_1001901f(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x4c4));
  return;
}



// Function: Unwind@1001902a at 1001902a

void Unwind_1001902a(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x460));
  return;
}



// Function: Unwind@10019035 at 10019035

void Unwind_10019035(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x584);
  return;
}



// Function: Unwind@10019040 at 10019040

void Unwind_10019040(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x514));
  return;
}



// Function: Unwind@1001904b at 1001904b

void Unwind_1001904b(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x594);
  return;
}



// Function: Unwind@10019056 at 10019056

void Unwind_10019056(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x534));
  return;
}



// Function: Unwind@10019061 at 10019061

void Unwind_10019061(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x5a4);
  return;
}



// Function: Unwind@1001906c at 1001906c

void Unwind_1001906c(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x52c));
  return;
}



// Function: Unwind@10019077 at 10019077

void Unwind_10019077(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x5b4);
  return;
}



// Function: Unwind@10019082 at 10019082

void Unwind_10019082(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x520));
  return;
}



// Function: Unwind@1001908d at 1001908d

void Unwind_1001908d(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x4ec));
  return;
}



// Function: Unwind@10019098 at 10019098

void Unwind_10019098(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x5d4);
  return;
}



// Function: Unwind@100190a3 at 100190a3

void Unwind_100190a3(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x528));
  return;
}



// Function: Unwind@100190ae at 100190ae

void Unwind_100190ae(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x4f4));
  return;
}



// Function: Unwind@100190b9 at 100190b9

void Unwind_100190b9(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x4f0));
  return;
}



// Function: Unwind@100190c4 at 100190c4

void Unwind_100190c4(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x500));
  return;
}



// Function: Unwind@100190cf at 100190cf

void Unwind_100190cf(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x5f4);
  return;
}



// Function: Unwind@100190da at 100190da

void Unwind_100190da(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x530));
  return;
}



// Function: Unwind@100190e5 at 100190e5

void Unwind_100190e5(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4b4));
  return;
}



// Function: Unwind@100190f0 at 100190f0

void Unwind_100190f0(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x498));
  return;
}



// Function: Unwind@100190fb at 100190fb

void Unwind_100190fb(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x4e8));
  return;
}



// Function: Unwind@10019106 at 10019106

void Unwind_10019106(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x5e4);
  return;
}



// Function: Unwind@10019111 at 10019111

void Unwind_10019111(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x538));
  return;
}



// Function: Unwind@1001911c at 1001911c

void Unwind_1001911c(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x4c4));
  return;
}



// Function: Unwind@10019127 at 10019127

void Unwind_10019127(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x4d8));
  return;
}



// Function: Unwind@10019132 at 10019132

void Unwind_10019132(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x4d4));
  return;
}



// Function: Unwind@1001913d at 1001913d

void Unwind_1001913d(void)

{
  int unaff_EBP;
  
  FUN_100018f5(*(int **)(unaff_EBP + -0x550));
  return;
}



// Function: Unwind@10019148 at 10019148

void Unwind_10019148(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x4d0));
  return;
}



// Function: Unwind@10019153 at 10019153

void Unwind_10019153(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x4c0));
  return;
}



// Function: Unwind@10019186 at 10019186

void Unwind_10019186(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100191a9 at 100191a9

void Unwind_100191a9(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100191b1 at 100191b1

void Unwind_100191b1(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@100191b9 at 100191b9

void Unwind_100191b9(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@100191c1 at 100191c1

void Unwind_100191c1(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + 0x14));
  return;
}



// Function: Unwind@100191e4 at 100191e4

void Unwind_100191e4(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019209 at 10019209

void Unwind_10019209(void)

{
  int unaff_EBP;
  
  FUN_10013807((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001922c at 1001922c

void Unwind_1001922c(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10019234 at 10019234

void Unwind_10019234(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x4b8));
  return;
}



// Function: Unwind@1001923f at 1001923f

void Unwind_1001923f(void)

{
  int unaff_EBP;
  
  FUN_10001d2f((undefined4 *)(unaff_EBP + -0x490));
  return;
}



// Function: Unwind@1001924a at 1001924a

void Unwind_1001924a(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x444));
  return;
}



// Function: Unwind@10019255 at 10019255

void Unwind_10019255(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x47c));
  return;
}



// Function: Unwind@10019260 at 10019260

void Unwind_10019260(void)

{
  int unaff_EBP;
  
  FUN_10001d2f((undefined4 *)(unaff_EBP + -0x49c));
  return;
}



// Function: Unwind@1001926b at 1001926b

void Unwind_1001926b(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x460));
  return;
}



// Function: Unwind@10019276 at 10019276

void Unwind_10019276(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x484));
  return;
}



// Function: Unwind@100192a9 at 100192a9

void Unwind_100192a9(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@100192b1 at 100192b1

void Unwind_100192b1(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x128));
  return;
}



// Function: Unwind@100192bc at 100192bc

void Unwind_100192bc(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x100));
  return;
}



// Function: Unwind@100192c7 at 100192c7

void Unwind_100192c7(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x100));
  return;
}



// Function: Unwind@100192d2 at 100192d2

void Unwind_100192d2(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0xfc));
  return;
}



// Function: Unwind@100192dd at 100192dd

void Unwind_100192dd(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0xfc));
  return;
}



// Function: Unwind@100192e8 at 100192e8

void Unwind_100192e8(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0xf8));
  return;
}



// Function: Unwind@100192f3 at 100192f3

void Unwind_100192f3(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0xf8));
  return;
}



// Function: Unwind@100192fe at 100192fe

void Unwind_100192fe(void)

{
  int unaff_EBP;
  
  FUN_100147f2((undefined4 *)(unaff_EBP + -0x108));
  return;
}



// Function: Unwind@10019309 at 10019309

void Unwind_10019309(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10019311 at 10019311

void Unwind_10019311(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x114));
  return;
}



// Function: Unwind@1001931c at 1001931c

void Unwind_1001931c(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10019324 at 10019324

void Unwind_10019324(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@1001932f at 1001932f

void Unwind_1001932f(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019337 at 10019337

void Unwind_10019337(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0xbc));
  return;
}



// Function: Unwind@10019342 at 10019342

void Unwind_10019342(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0xf4));
  return;
}



// Function: Unwind@1001934d at 1001934d

void Unwind_1001934d(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@10019358 at 10019358

void Unwind_10019358(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x114));
  return;
}



// Function: Unwind@10019363 at 10019363

void Unwind_10019363(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@1001936e at 1001936e

void Unwind_1001936e(void)

{
  int unaff_EBP;
  
  FUN_10013807((undefined4 *)(unaff_EBP + -0x104));
  return;
}



// Function: Unwind@10019379 at 10019379

void Unwind_10019379(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0xf8));
  return;
}



// Function: Unwind@10019384 at 10019384

void Unwind_10019384(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0xfc));
  return;
}



// Function: Unwind@1001938f at 1001938f

void Unwind_1001938f(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x100));
  return;
}



// Function: Unwind@1001939a at 1001939a

void Unwind_1001939a(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@100193ca at 100193ca

void Unwind_100193ca(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@100193d2 at 100193d2

void Unwind_100193d2(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@100193dd at 100193dd

void Unwind_100193dd(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100193e5 at 100193e5

void Unwind_100193e5(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@100193ed at 100193ed

void Unwind_100193ed(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100193f5 at 100193f5

void Unwind_100193f5(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@100193fd at 100193fd

void Unwind_100193fd(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x40);
  return;
}



// Function: Unwind@10019405 at 10019405

void Unwind_10019405(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001940d at 1001940d

void Unwind_1001940d(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019415 at 10019415

void Unwind_10019415(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@1001941d at 1001941d

void Unwind_1001941d(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10019425 at 10019425

void Unwind_10019425(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@1001942d at 1001942d

void Unwind_1001942d(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10019435 at 10019435

void Unwind_10019435(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001943d at 1001943d

void Unwind_1001943d(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001946d at 1001946d

void Unwind_1001946d(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019475 at 10019475

void Unwind_10019475(void)

{
  int unaff_EBP;
  
  FUN_100012a2((undefined4 *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@10019480 at 10019480

void Unwind_10019480(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019488 at 10019488

void Unwind_10019488(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10019490 at 10019490

void Unwind_10019490(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10019498 at 10019498

void Unwind_10019498(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@100194a0 at 100194a0

void Unwind_100194a0(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x40);
  return;
}



// Function: Unwind@100194a8 at 100194a8

void Unwind_100194a8(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100194b0 at 100194b0

void Unwind_100194b0(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100194b8 at 100194b8

void Unwind_100194b8(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@100194c0 at 100194c0

void Unwind_100194c0(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@100194c8 at 100194c8

void Unwind_100194c8(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@100194d0 at 100194d0

void Unwind_100194d0(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@100194d8 at 100194d8

void Unwind_100194d8(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100194e0 at 100194e0

void Unwind_100194e0(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019510 at 10019510

void Unwind_10019510(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019518 at 10019518

void Unwind_10019518(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019520 at 10019520

void Unwind_10019520(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019528 at 10019528

void Unwind_10019528(void)

{
  int unaff_EBP;
  
  FUN_100018f5((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019530 at 10019530

void Unwind_10019530(void)

{
  int unaff_EBP;
  
  FUN_100011c9((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10019538 at 10019538

void Unwind_10019538(void)

{
  int unaff_EBP;
  
  FUN_100018ed(unaff_EBP + -0x24);
  return;
}



// Function: Unwind@10019540 at 10019540

void Unwind_10019540(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019548 at 10019548

void Unwind_10019548(void)

{
  int unaff_EBP;
  
  FUN_100056fc((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001956b at 1001956b

void Unwind_1001956b(void)

{
  int unaff_EBP;
  
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001958e at 1001958e

void Unwind_1001958e(void)

{
  int unaff_EBP;
  
  FUN_100095b3(*(void **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10019597 at 10019597

void Unwind_10019597(void)

{
  int unaff_EBP;
  
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)(unaff_EBP + -0x30));
  return;
}



// Function: FUN_1001b32b at 1001b32b

void FUN_1001b32b(void)

{
  Ordinal_6(DAT_10029314);
  return;
}



// Function: FUN_1001b338 at 1001b338

void FUN_1001b338(void)

{
  Ordinal_6(DAT_10029318);
  return;
}



// Function: FUN_1001b345 at 1001b345

void FUN_1001b345(void)

{
  Ordinal_6(DAT_1002931c);
  return;
}



// Function: FUN_1001b352 at 1001b352

void FUN_1001b352(void)

{
  _eh_vector_destructor_iterator_(&DAT_10028e98,0x1c,0xe,~basic_string<>);
  return;
}



// Function: FUN_1001b366 at 1001b366

void FUN_1001b366(void)

{
  FID_conflict__Tidy(&DAT_10028e7c,'\x01',0);
  return;
}



// Function: FUN_1001b375 at 1001b375

void FUN_1001b375(void)

{
  FID_conflict__Tidy(&DAT_10029020,'\x01',0);
  return;
}



// Function: FUN_1001b384 at 1001b384

void FUN_1001b384(void)

{
  FID_conflict__Tidy(&DAT_1002903c,'\x01',0);
  return;
}



// Function: FUN_1001b393 at 1001b393

void FUN_1001b393(void)

{
  FID_conflict__Tidy(&DAT_10029058,'\x01',0);
  return;
}



// Function: FUN_1001b3a2 at 1001b3a2

void FUN_1001b3a2(void)

{
  FID_conflict__Tidy(&DAT_10029074,'\x01',0);
  return;
}



// Function: FUN_1001b3b1 at 1001b3b1

void FUN_1001b3b1(void)

{
  FID_conflict__Tidy(&DAT_10029090,'\x01',0);
  return;
}



// Function: FUN_1001b3c0 at 1001b3c0

void FUN_1001b3c0(void)

{
  FID_conflict__Tidy(&DAT_100290ac,'\x01',0);
  return;
}



// Function: FUN_1001b3cf at 1001b3cf

void FUN_1001b3cf(void)

{
  FID_conflict__Tidy(&DAT_100290c8,'\x01',0);
  return;
}



// Function: FUN_1001b3de at 1001b3de

void FUN_1001b3de(void)

{
  FID_conflict__Tidy(&DAT_100290e4,'\x01',0);
  return;
}



// Function: FUN_1001b3ed at 1001b3ed

void FUN_1001b3ed(void)

{
  FID_conflict__Tidy(&DAT_10029100,'\x01',0);
  return;
}



// Function: FUN_1001b3fc at 1001b3fc

void FUN_1001b3fc(void)

{
  FID_conflict__Tidy(&DAT_1002911c,'\x01',0);
  return;
}



// Function: FUN_1001b40b at 1001b40b

void FUN_1001b40b(void)

{
  FID_conflict__Tidy(&DAT_10029138,'\x01',0);
  return;
}



// Function: FUN_1001b41a at 1001b41a

void FUN_1001b41a(void)

{
  FID_conflict__Tidy(&DAT_10029154,'\x01',0);
  return;
}



// Function: FUN_1001b429 at 1001b429

void FUN_1001b429(void)

{
  FID_conflict__Tidy(&DAT_10029170,'\x01',0);
  return;
}



// Function: FUN_1001b438 at 1001b438

void FUN_1001b438(void)

{
  FID_conflict__Tidy(&DAT_1002918c,'\x01',0);
  return;
}



// Function: FUN_1001b447 at 1001b447

void FUN_1001b447(void)

{
  FID_conflict__Tidy(&DAT_100291a8,'\x01',0);
  return;
}



// Function: FUN_1001b456 at 1001b456

void FUN_1001b456(void)

{
  FID_conflict__Tidy(&DAT_100291c4,'\x01',0);
  return;
}



// Function: FUN_1001b465 at 1001b465

void FUN_1001b465(void)

{
  FID_conflict__Tidy(&DAT_100291e0,'\x01',0);
  return;
}



// Function: FUN_1001b474 at 1001b474

void FUN_1001b474(void)

{
  FID_conflict__Tidy(&DAT_100291fc,'\x01',0);
  return;
}



// Function: FUN_1001b483 at 1001b483

void FUN_1001b483(void)

{
  FID_conflict__Tidy(&DAT_10029218,'\x01',0);
  return;
}



// Function: FUN_1001b492 at 1001b492

void FUN_1001b492(void)

{
  FID_conflict__Tidy(&DAT_10029234,'\x01',0);
  return;
}



// Function: FUN_1001b4a1 at 1001b4a1

void FUN_1001b4a1(void)

{
  FID_conflict__Tidy(&DAT_10029250,'\x01',0);
  return;
}



// Function: FUN_1001b4b0 at 1001b4b0

void FUN_1001b4b0(void)

{
  FID_conflict__Tidy(&DAT_1002926c,'\x01',0);
  return;
}



// Function: FUN_1001b4bf at 1001b4bf

void FUN_1001b4bf(void)

{
  FID_conflict__Tidy(&DAT_10029288,'\x01',0);
  return;
}



// Function: FUN_1001b4ce at 1001b4ce

void FUN_1001b4ce(void)

{
  FID_conflict__Tidy(&DAT_100292a4,'\x01',0);
  return;
}



// Function: FUN_1001b4dd at 1001b4dd

void FUN_1001b4dd(void)

{
  FID_conflict__Tidy(&DAT_100292c0,'\x01',0);
  return;
}



// Function: FUN_1001b4ec at 1001b4ec

void FUN_1001b4ec(void)

{
  FID_conflict__Tidy(&DAT_100292dc,'\x01',0);
  return;
}



// Function: FUN_1001b4fb at 1001b4fb

void FUN_1001b4fb(void)

{
  FID_conflict__Tidy(&DAT_100292f8,'\x01',0);
  return;
}



// Function: FUN_1001b50a at 1001b50a

void FUN_1001b50a(void)

{
  FID_conflict__Tidy(&DAT_10029330,'\x01',0);
  return;
}



// Function: FUN_1001b519 at 1001b519

void FUN_1001b519(void)

{
  FID_conflict__Tidy(&DAT_1002934c,'\x01',0);
  return;
}



// Function: FUN_1001b528 at 1001b528

void FUN_1001b528(void)

{
  FID_conflict__Tidy(&DAT_10029368,'\x01',0);
  return;
}



// Function: FUN_1001b537 at 1001b537

void FUN_1001b537(void)

{
  FUN_1000df2a((_Container_base0 *)&DAT_10029320);
  return;
}



// Function: FUN_1001b541 at 1001b541

void FUN_1001b541(void)

{
  FID_conflict__Tidy(&DAT_10029898,'\x01',0);
  return;
}



// Function: FUN_1001b550 at 1001b550

void FUN_1001b550(void)

{
  FID_conflict__Tidy(&DAT_1002987c,'\x01',0);
  return;
}



// Function: FUN_1001b55f at 1001b55f

void FUN_1001b55f(void)

{
  FID_conflict__Tidy(&DAT_100293ac,'\x01',0);
  return;
}



// Function: FUN_1001b56e at 1001b56e

void FUN_1001b56e(void)

{
  FID_conflict__Tidy(&DAT_10029c6c,'\x01',0);
  return;
}



// Function: FUN_1001b57d at 1001b57d

void FUN_1001b57d(void)

{
  FID_conflict__Tidy(&DAT_10029828,'\x01',0);
  return;
}



// Function: FUN_1001b58c at 1001b58c

void FUN_1001b58c(void)

{
  FID_conflict__Tidy(&DAT_10029844,'\x01',0);
  return;
}



// Function: FUN_1001b59b at 1001b59b

void FUN_1001b59b(void)

{
  FID_conflict__Tidy(&DAT_10029c50,'\x01',0);
  return;
}



// Function: FUN_1001b5aa at 1001b5aa

void FUN_1001b5aa(void)

{
  FID_conflict__Tidy(&DAT_10029cc0,'\x01',0);
  return;
}



// Function: FUN_1001b5b9 at 1001b5b9

void FUN_1001b5b9(void)

{
  FID_conflict__Tidy(&DAT_100299e8,'\x01',0);
  return;
}



// Function: FUN_1001b5c8 at 1001b5c8

void FUN_1001b5c8(void)

{
  FID_conflict__Tidy(&DAT_10029d4c,'\x01',0);
  return;
}



// Function: FUN_1001b5d7 at 1001b5d7

void FUN_1001b5d7(void)

{
  FID_conflict__Tidy(&DAT_1002964c,'\x01',0);
  return;
}



// Function: FUN_1001b5e6 at 1001b5e6

void FUN_1001b5e6(void)

{
  FID_conflict__Tidy(&DAT_10029668,'\x01',0);
  return;
}



// Function: FUN_1001b5f5 at 1001b5f5

void FUN_1001b5f5(void)

{
  FID_conflict__Tidy(&DAT_10029e10,'\x01',0);
  return;
}



// Function: FUN_1001b604 at 1001b604

void FUN_1001b604(void)

{
  FID_conflict__Tidy(&DAT_1002956c,'\x01',0);
  return;
}



// Function: FUN_1001b613 at 1001b613

void FUN_1001b613(void)

{
  FID_conflict__Tidy(&DAT_100298b4,'\x01',0);
  return;
}



// Function: FUN_1001b622 at 1001b622

void FUN_1001b622(void)

{
  FID_conflict__Tidy(&DAT_10029588,'\x01',0);
  return;
}



// Function: FUN_1001b631 at 1001b631

void FUN_1001b631(void)

{
  FID_conflict__Tidy(&DAT_1002995c,'\x01',0);
  return;
}



// Function: FUN_1001b640 at 1001b640

void FUN_1001b640(void)

{
  FID_conflict__Tidy(&DAT_10029d14,'\x01',0);
  return;
}



// Function: FUN_1001b64f at 1001b64f

void FUN_1001b64f(void)

{
  FID_conflict__Tidy(&DAT_10029da0,'\x01',0);
  return;
}



// Function: FUN_1001b65e at 1001b65e

void FUN_1001b65e(void)

{
  FID_conflict__Tidy(&DAT_10029a04,'\x01',0);
  return;
}



// Function: FUN_1001b66d at 1001b66d

void FUN_1001b66d(void)

{
  FID_conflict__Tidy(&DAT_10029ac8,'\x01',0);
  return;
}



// Function: FUN_1001b67c at 1001b67c

void FUN_1001b67c(void)

{
  FID_conflict__Tidy(&DAT_10029aac,'\x01',0);
  return;
}



// Function: FUN_1001b68b at 1001b68b

void FUN_1001b68b(void)

{
  FID_conflict__Tidy(&DAT_10029748,'\x01',0);
  return;
}



// Function: FUN_1001b69a at 1001b69a

void FUN_1001b69a(void)

{
  FID_conflict__Tidy(&DAT_10029ae4,'\x01',0);
  return;
}



// Function: FUN_1001b6a9 at 1001b6a9

void FUN_1001b6a9(void)

{
  FID_conflict__Tidy(&DAT_10029a90,'\x01',0);
  return;
}



// Function: FUN_1001b6b8 at 1001b6b8

void FUN_1001b6b8(void)

{
  FID_conflict__Tidy(&DAT_100297d4,'\x01',0);
  return;
}



// Function: FUN_1001b6c7 at 1001b6c7

void FUN_1001b6c7(void)

{
  FID_conflict__Tidy(&DAT_10029b38,'\x01',0);
  return;
}



// Function: FUN_1001b6d6 at 1001b6d6

void FUN_1001b6d6(void)

{
  FID_conflict__Tidy(&DAT_100297f0,'\x01',0);
  return;
}



// Function: FUN_1001b6e5 at 1001b6e5

void FUN_1001b6e5(void)

{
  FID_conflict__Tidy(&DAT_10029d68,'\x01',0);
  return;
}



// Function: FUN_1001b6f4 at 1001b6f4

void FUN_1001b6f4(void)

{
  FID_conflict__Tidy(&DAT_10029c18,'\x01',0);
  return;
}



// Function: FUN_1001b703 at 1001b703

void FUN_1001b703(void)

{
  FID_conflict__Tidy(&DAT_10029764,'\x01',0);
  return;
}



// Function: FUN_1001b712 at 1001b712

void FUN_1001b712(void)

{
  FID_conflict__Tidy(&DAT_10029bc4,'\x01',0);
  return;
}



// Function: FUN_1001b721 at 1001b721

void FUN_1001b721(void)

{
  FID_conflict__Tidy(&DAT_10029e2c,'\x01',0);
  return;
}



// Function: FUN_1001b730 at 1001b730

void FUN_1001b730(void)

{
  FID_conflict__Tidy(&DAT_100297b8,'\x01',0);
  return;
}



// Function: FUN_1001b73f at 1001b73f

void FUN_1001b73f(void)

{
  FID_conflict__Tidy(&DAT_10029c88,'\x01',0);
  return;
}



// Function: FUN_1001b74e at 1001b74e

void FUN_1001b74e(void)

{
  FID_conflict__Tidy(&DAT_10029780,'\x01',0);
  return;
}



// Function: FUN_1001b75d at 1001b75d

void FUN_1001b75d(void)

{
  FID_conflict__Tidy(&DAT_1002979c,'\x01',0);
  return;
}



// Function: FUN_1001b76c at 1001b76c

void FUN_1001b76c(void)

{
  FID_conflict__Tidy(&DAT_10029dd8,'\x01',0);
  return;
}



// Function: FUN_1001b77b at 1001b77b

void FUN_1001b77b(void)

{
  FID_conflict__Tidy(&DAT_10029df4,'\x01',0);
  return;
}



// Function: FUN_1001b78a at 1001b78a

void FUN_1001b78a(void)

{
  FID_conflict__Tidy(&DAT_10029eb8,'\x01',0);
  return;
}



// Function: FUN_1001b799 at 1001b799

void FUN_1001b799(void)

{
  FID_conflict__Tidy(&DAT_1002972c,'\x01',0);
  return;
}



// Function: FUN_1001b7a8 at 1001b7a8

void FUN_1001b7a8(void)

{
  FID_conflict__Tidy(&DAT_10029710,'\x01',0);
  return;
}



// Function: FUN_1001b7b7 at 1001b7b7

void FUN_1001b7b7(void)

{
  FID_conflict__Tidy(&DAT_10029be0,'\x01',0);
  return;
}



// Function: FUN_1001b7c6 at 1001b7c6

void FUN_1001b7c6(void)

{
  FID_conflict__Tidy(&DAT_100296f4,'\x01',0);
  return;
}



// Function: FUN_1001b7d5 at 1001b7d5

void FUN_1001b7d5(void)

{
  FID_conflict__Tidy(&DAT_10029e48,'\x01',0);
  return;
}



// Function: FUN_1001b7e4 at 1001b7e4

void FUN_1001b7e4(void)

{
  FID_conflict__Tidy(&DAT_10029860,'\x01',0);
  return;
}



// Function: FUN_1001b7f3 at 1001b7f3

void FUN_1001b7f3(void)

{
  FID_conflict__Tidy(&DAT_10029d84,'\x01',0);
  return;
}



// Function: FUN_1001b802 at 1001b802

void FUN_1001b802(void)

{
  FID_conflict__Tidy(&DAT_10029c34,'\x01',0);
  return;
}



// Function: FUN_1001b811 at 1001b811

void FUN_1001b811(void)

{
  FID_conflict__Tidy(&DAT_100296d8,'\x01',0);
  return;
}



// Function: FUN_1001b820 at 1001b820

void FUN_1001b820(void)

{
  FID_conflict__Tidy(&DAT_10029bfc,'\x01',0);
  return;
}



// Function: FUN_1001b82f at 1001b82f

void FUN_1001b82f(void)

{
  FID_conflict__Tidy(&DAT_10029684,'\x01',0);
  return;
}



// Function: FUN_1001b83e at 1001b83e

void FUN_1001b83e(void)

{
  FID_conflict__Tidy(&DAT_100296bc,'\x01',0);
  return;
}



// Function: FUN_1001b84d at 1001b84d

void FUN_1001b84d(void)

{
  FID_conflict__Tidy(&DAT_100296a0,'\x01',0);
  return;
}



// Function: FUN_1001b85c at 1001b85c

void FUN_1001b85c(void)

{
  FID_conflict__Tidy(&DAT_1002980c,'\x01',0);
  return;
}



// Function: FUN_1001b86b at 1001b86b

void FUN_1001b86b(void)

{
  FID_conflict__Tidy(&DAT_10029b54,'\x01',0);
  return;
}



// Function: FUN_1001b87a at 1001b87a

void FUN_1001b87a(void)

{
  FID_conflict__Tidy(&DAT_10029978,'\x01',0);
  return;
}



// Function: FUN_1001b889 at 1001b889

void FUN_1001b889(void)

{
  FID_conflict__Tidy(&DAT_10029b00,'\x01',0);
  return;
}



// Function: FUN_1001b898 at 1001b898

void FUN_1001b898(void)

{
  FID_conflict__Tidy(&DAT_100294fc,'\x01',0);
  return;
}



// Function: FUN_1001b8a7 at 1001b8a7

void FUN_1001b8a7(void)

{
  FID_conflict__Tidy(&DAT_10029518,'\x01',0);
  return;
}



// Function: FUN_1001b8b6 at 1001b8b6

void FUN_1001b8b6(void)

{
  FID_conflict__Tidy(&DAT_10029a20,'\x01',0);
  return;
}



// Function: FUN_1001b8c5 at 1001b8c5

void FUN_1001b8c5(void)

{
  FID_conflict__Tidy(&DAT_100294c4,'\x01',0);
  return;
}



// Function: FUN_1001b8d4 at 1001b8d4

void FUN_1001b8d4(void)

{
  FID_conflict__Tidy(&DAT_100294a8,'\x01',0);
  return;
}



// Function: FUN_1001b8e3 at 1001b8e3

void FUN_1001b8e3(void)

{
  FID_conflict__Tidy(&DAT_10029908,'\x01',0);
  return;
}



// Function: FUN_1001b8f2 at 1001b8f2

void FUN_1001b8f2(void)

{
  FID_conflict__Tidy(&DAT_10029470,'\x01',0);
  return;
}



// Function: FUN_1001b901 at 1001b901

void FUN_1001b901(void)

{
  FID_conflict__Tidy(&DAT_10029cf8,'\x01',0);
  return;
}



// Function: FUN_1001b910 at 1001b910

void FUN_1001b910(void)

{
  FID_conflict__Tidy(&DAT_10029454,'\x01',0);
  return;
}



// Function: FUN_1001b91f at 1001b91f

void FUN_1001b91f(void)

{
  FID_conflict__Tidy(&DAT_1002948c,'\x01',0);
  return;
}



// Function: FUN_1001b92e at 1001b92e

void FUN_1001b92e(void)

{
  FID_conflict__Tidy(&DAT_100298d0,'\x01',0);
  return;
}



// Function: FUN_1001b93d at 1001b93d

void FUN_1001b93d(void)

{
  FID_conflict__Tidy(&DAT_10029a3c,'\x01',0);
  return;
}



// Function: FUN_1001b94c at 1001b94c

void FUN_1001b94c(void)

{
  FID_conflict__Tidy(&DAT_10029550,'\x01',0);
  return;
}



// Function: FUN_1001b95b at 1001b95b

void FUN_1001b95b(void)

{
  FID_conflict__Tidy(&DAT_10029534,'\x01',0);
  return;
}



// Function: FUN_1001b96a at 1001b96a

void FUN_1001b96a(void)

{
  FID_conflict__Tidy(&DAT_100294e0,'\x01',0);
  return;
}



// Function: FUN_1001b979 at 1001b979

void FUN_1001b979(void)

{
  FID_conflict__Tidy(&DAT_10029e80,'\x01',0);
  return;
}



// Function: FUN_1001b988 at 1001b988

void FUN_1001b988(void)

{
  FID_conflict__Tidy(&DAT_10029ba8,'\x01',0);
  return;
}



// Function: FUN_1001b997 at 1001b997

void FUN_1001b997(void)

{
  FID_conflict__Tidy(&DAT_10029d30,'\x01',0);
  return;
}



// Function: FUN_1001b9a6 at 1001b9a6

void FUN_1001b9a6(void)

{
  FID_conflict__Tidy(&DAT_10029a74,'\x01',0);
  return;
}



// Function: FUN_1001b9b5 at 1001b9b5

void FUN_1001b9b5(void)

{
  FID_conflict__Tidy(&DAT_100299cc,'\x01',0);
  return;
}



// Function: FUN_1001b9c4 at 1001b9c4

void FUN_1001b9c4(void)

{
  FID_conflict__Tidy(&DAT_100299b0,'\x01',0);
  return;
}



// Function: FUN_1001b9d3 at 1001b9d3

void FUN_1001b9d3(void)

{
  FID_conflict__Tidy(&DAT_100295dc,'\x01',0);
  return;
}



// Function: FUN_1001b9e2 at 1001b9e2

void FUN_1001b9e2(void)

{
  FID_conflict__Tidy(&DAT_10029dbc,'\x01',0);
  return;
}



// Function: FUN_1001b9f1 at 1001b9f1

void FUN_1001b9f1(void)

{
  FID_conflict__Tidy(&DAT_100295a4,'\x01',0);
  return;
}



// Function: FUN_1001ba00 at 1001ba00

void FUN_1001ba00(void)

{
  FID_conflict__Tidy(&DAT_10029e9c,'\x01',0);
  return;
}



// Function: FUN_1001ba0f at 1001ba0f

void FUN_1001ba0f(void)

{
  FID_conflict__Tidy(&DAT_100295c0,'\x01',0);
  return;
}



// Function: FUN_1001ba1e at 1001ba1e

void FUN_1001ba1e(void)

{
  FID_conflict__Tidy(&DAT_10029940,'\x01',0);
  return;
}



// Function: FUN_1001ba2d at 1001ba2d

void FUN_1001ba2d(void)

{
  FID_conflict__Tidy(&DAT_10029994,'\x01',0);
  return;
}



// Function: FUN_1001ba3c at 1001ba3c

void FUN_1001ba3c(void)

{
  FID_conflict__Tidy(&DAT_10029b1c,'\x01',0);
  return;
}



// Function: FUN_1001ba4b at 1001ba4b

void FUN_1001ba4b(void)

{
  FID_conflict__Tidy(&DAT_10029b70,'\x01',0);
  return;
}



// Function: FUN_1001ba5a at 1001ba5a

void FUN_1001ba5a(void)

{
  FID_conflict__Tidy(&DAT_10029a58,'\x01',0);
  return;
}



// Function: FUN_1001ba69 at 1001ba69

void FUN_1001ba69(void)

{
  FID_conflict__Tidy(&DAT_10029630,'\x01',0);
  return;
}



// Function: FUN_1001ba78 at 1001ba78

void FUN_1001ba78(void)

{
  FID_conflict__Tidy(&DAT_10029614,'\x01',0);
  return;
}



// Function: FUN_1001ba87 at 1001ba87

void FUN_1001ba87(void)

{
  FID_conflict__Tidy(&DAT_10029b8c,'\x01',0);
  return;
}



// Function: FUN_1001ba96 at 1001ba96

void FUN_1001ba96(void)

{
  FID_conflict__Tidy(&DAT_100295f8,'\x01',0);
  return;
}



// Function: FUN_1001baa5 at 1001baa5

void FUN_1001baa5(void)

{
  FID_conflict__Tidy(&DAT_10029ca4,'\x01',0);
  return;
}



// Function: FUN_1001bab4 at 1001bab4

void FUN_1001bab4(void)

{
  FID_conflict__Tidy(&DAT_10029cdc,'\x01',0);
  return;
}



// Function: FUN_1001bac3 at 1001bac3

void FUN_1001bac3(void)

{
  FID_conflict__Tidy(&DAT_10029438,'\x01',0);
  return;
}



// Function: FUN_1001bad2 at 1001bad2

void FUN_1001bad2(void)

{
  FID_conflict__Tidy(&DAT_10029924,'\x01',0);
  return;
}



// Function: FUN_1001bae1 at 1001bae1

void FUN_1001bae1(void)

{
  FID_conflict__Tidy(&DAT_100293e4,'\x01',0);
  return;
}



// Function: FUN_1001baf0 at 1001baf0

void FUN_1001baf0(void)

{
  FID_conflict__Tidy(&DAT_1002941c,'\x01',0);
  return;
}



// Function: FUN_1001baff at 1001baff

void FUN_1001baff(void)

{
  FID_conflict__Tidy(&DAT_10029400,'\x01',0);
  return;
}



// Function: FUN_1001bb0e at 1001bb0e

void FUN_1001bb0e(void)

{
  FID_conflict__Tidy(&DAT_10029e64,'\x01',0);
  return;
}



// Function: FUN_1001bb1d at 1001bb1d

void FUN_1001bb1d(void)

{
  FID_conflict__Tidy(&DAT_100298ec,'\x01',0);
  return;
}



// Function: FUN_1001bb2c at 1001bb2c

void FUN_1001bb2c(void)

{
  FID_conflict__Tidy(&DAT_100293c8,'\x01',0);
  return;
}



// Function: FUN_1001bb3b at 1001bb3b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001bb3b(void)

{
  CWinApp::~CWinApp((CWinApp *)&DAT_10029f30);
  return;
}



// Function: FUN_1001bb5b at 1001bb5b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001bb5b(void)

{
  _DAT_10029f00 = ATL::CComModule::vftable;
  FUN_1000a227(0x10029f00);
  return;
}



// Function: FUN_1001bb85 at 1001bb85

void FUN_1001bb85(void)

{
  Ordinal_6(DAT_1002a1c8);
  return;
}



// Function: FUN_1001bb92 at 1001bb92

void FUN_1001bb92(void)

{
  Ordinal_6(DAT_1002a1cc);
  return;
}



// Function: FUN_1001bb9f at 1001bb9f

void FUN_1001bb9f(void)

{
  Ordinal_6(DAT_1002a1d0);
  return;
}



// Function: FUN_1001bbac at 1001bbac

void FUN_1001bbac(void)

{
  Ordinal_6(DAT_1002a490);
  return;
}



// Function: FUN_1001bbb9 at 1001bbb9

void FUN_1001bbb9(void)

{
  Ordinal_6(DAT_1002a494);
  return;
}



// Function: FUN_1001bbc6 at 1001bbc6

void FUN_1001bbc6(void)

{
  FID_conflict__Tidy(&DAT_10029fec,'\x01',0);
  return;
}



// Function: FUN_1001bbd5 at 1001bbd5

void FUN_1001bbd5(void)

{
  FID_conflict__Tidy(&DAT_1002a008,'\x01',0);
  return;
}



// Function: FUN_1001bbe4 at 1001bbe4

void FUN_1001bbe4(void)

{
  FID_conflict__Tidy(&DAT_1002a024,'\x01',0);
  return;
}



// Function: FUN_1001bbf3 at 1001bbf3

void FUN_1001bbf3(void)

{
  FID_conflict__Tidy(&DAT_1002a040,'\x01',0);
  return;
}



// Function: FUN_1001bc02 at 1001bc02

void FUN_1001bc02(void)

{
  FID_conflict__Tidy(&DAT_1002a05c,'\x01',0);
  return;
}



// Function: FUN_1001bc11 at 1001bc11

void FUN_1001bc11(void)

{
  FID_conflict__Tidy(&DAT_1002a078,'\x01',0);
  return;
}



// Function: FUN_1001bc20 at 1001bc20

void FUN_1001bc20(void)

{
  FID_conflict__Tidy(&DAT_1002a094,'\x01',0);
  return;
}



// Function: FUN_1001bc2f at 1001bc2f

void FUN_1001bc2f(void)

{
  FID_conflict__Tidy(&DAT_1002a0b0,'\x01',0);
  return;
}



// Function: FUN_1001bc3e at 1001bc3e

void FUN_1001bc3e(void)

{
  FID_conflict__Tidy(&DAT_1002a0cc,'\x01',0);
  return;
}



// Function: FUN_1001bc4d at 1001bc4d

void FUN_1001bc4d(void)

{
  FID_conflict__Tidy(&DAT_1002a0e8,'\x01',0);
  return;
}



// Function: FUN_1001bc5c at 1001bc5c

void FUN_1001bc5c(void)

{
  FID_conflict__Tidy(&DAT_1002a104,'\x01',0);
  return;
}



// Function: FUN_1001bc6b at 1001bc6b

void FUN_1001bc6b(void)

{
  FID_conflict__Tidy(&DAT_1002a120,'\x01',0);
  return;
}



// Function: FUN_1001bc7a at 1001bc7a

void FUN_1001bc7a(void)

{
  FID_conflict__Tidy(&DAT_1002a13c,'\x01',0);
  return;
}



// Function: FUN_1001bc89 at 1001bc89

void FUN_1001bc89(void)

{
  FID_conflict__Tidy(&DAT_1002a158,'\x01',0);
  return;
}



// Function: FUN_1001bc98 at 1001bc98

void FUN_1001bc98(void)

{
  FID_conflict__Tidy(&DAT_1002a174,'\x01',0);
  return;
}



// Function: FUN_1001bca7 at 1001bca7

void FUN_1001bca7(void)

{
  FID_conflict__Tidy(&DAT_1002a190,'\x01',0);
  return;
}



// Function: FUN_1001bcb6 at 1001bcb6

void FUN_1001bcb6(void)

{
  FID_conflict__Tidy(&DAT_1002a1ac,'\x01',0);
  return;
}



// Function: FUN_1001bcc5 at 1001bcc5

void FUN_1001bcc5(void)

{
  _eh_vector_destructor_iterator_(&DAT_1002a1f0,0x1c,0xe,~basic_string<>);
  return;
}



// Function: FUN_1001bcd9 at 1001bcd9

void FUN_1001bcd9(void)

{
  FID_conflict__Tidy(&DAT_1002a1d4,'\x01',0);
  return;
}



// Function: FUN_1001bce8 at 1001bce8

void FUN_1001bce8(void)

{
  FID_conflict__Tidy(&DAT_1002a378,'\x01',0);
  return;
}



// Function: FUN_1001bcf7 at 1001bcf7

void FUN_1001bcf7(void)

{
  FID_conflict__Tidy(&DAT_1002a394,'\x01',0);
  return;
}



// Function: FUN_1001bd06 at 1001bd06

void FUN_1001bd06(void)

{
  FID_conflict__Tidy(&DAT_1002a3b0,'\x01',0);
  return;
}



// Function: FUN_1001bd15 at 1001bd15

void FUN_1001bd15(void)

{
  FID_conflict__Tidy(&DAT_1002a3cc,'\x01',0);
  return;
}



// Function: FUN_1001bd24 at 1001bd24

void FUN_1001bd24(void)

{
  FID_conflict__Tidy(&DAT_1002a3e8,'\x01',0);
  return;
}



// Function: FUN_1001bd33 at 1001bd33

void FUN_1001bd33(void)

{
  FID_conflict__Tidy(&DAT_1002a404,'\x01',0);
  return;
}



// Function: FUN_1001bd42 at 1001bd42

void FUN_1001bd42(void)

{
  FID_conflict__Tidy(&DAT_1002a420,'\x01',0);
  return;
}



// Function: FUN_1001bd51 at 1001bd51

void FUN_1001bd51(void)

{
  FID_conflict__Tidy(&DAT_1002a43c,'\x01',0);
  return;
}



// Function: FUN_1001bd60 at 1001bd60

void FUN_1001bd60(void)

{
  FID_conflict__Tidy(&DAT_1002a458,'\x01',0);
  return;
}



// Function: FUN_1001bd6f at 1001bd6f

void FUN_1001bd6f(void)

{
  FID_conflict__Tidy(&DAT_1002a474,'\x01',0);
  return;
}



// Function: FUN_1001bd7e at 1001bd7e

void FUN_1001bd7e(void)

{
  FID_conflict__Tidy(&DAT_1002a4ec,'\x01',0);
  return;
}



// Function: FUN_1001bd8d at 1001bd8d

void FUN_1001bd8d(void)

{
  FID_conflict__Tidy(&DAT_1002a498,'\x01',0);
  return;
}



// Function: FUN_1001bd9c at 1001bd9c

void FUN_1001bd9c(void)

{
  FID_conflict__Tidy(&DAT_1002a4b4,'\x01',0);
  return;
}



// Function: FUN_1001bdab at 1001bdab

void FUN_1001bdab(void)

{
  FID_conflict__Tidy(&DAT_1002a4d0,'\x01',0);
  return;
}



// Function: FUN_1001bdba at 1001bdba

void FUN_1001bdba(void)

{
  FID_conflict__Tidy(&DAT_1002a540,'\x01',0);
  return;
}



// Function: FUN_1001bdc9 at 1001bdc9

void FUN_1001bdc9(void)

{
  FID_conflict__Tidy(&DAT_1002a55c,'\x01',0);
  return;
}



// Function: FUN_1001bdd8 at 1001bdd8

void FUN_1001bdd8(void)

{
  FID_conflict__Tidy(&DAT_1002a508,'\x01',0);
  return;
}



// Function: FUN_1001bde7 at 1001bde7

void FUN_1001bde7(void)

{
  FID_conflict__Tidy(&DAT_1002a524,'\x01',0);
  return;
}



// Function: FUN_1001bdf6 at 1001bdf6

void FUN_1001bdf6(void)

{
  Ordinal_6(DAT_1002a75c);
  return;
}



// Function: FUN_1001be03 at 1001be03

void FUN_1001be03(void)

{
  Ordinal_6(DAT_1002a760);
  return;
}



// Function: FUN_1001be10 at 1001be10

void FUN_1001be10(void)

{
  Ordinal_6(DAT_1002a764);
  return;
}



// Function: FUN_1001be1d at 1001be1d

void FUN_1001be1d(void)

{
  FID_conflict__Tidy(&DAT_1002a580,'\x01',0);
  return;
}



// Function: FUN_1001be2c at 1001be2c

void FUN_1001be2c(void)

{
  FID_conflict__Tidy(&DAT_1002a59c,'\x01',0);
  return;
}



// Function: FUN_1001be3b at 1001be3b

void FUN_1001be3b(void)

{
  FID_conflict__Tidy(&DAT_1002a5b8,'\x01',0);
  return;
}



// Function: FUN_1001be4a at 1001be4a

void FUN_1001be4a(void)

{
  FID_conflict__Tidy(&DAT_1002a5d4,'\x01',0);
  return;
}



// Function: FUN_1001be59 at 1001be59

void FUN_1001be59(void)

{
  FID_conflict__Tidy(&DAT_1002a5f0,'\x01',0);
  return;
}



// Function: FUN_1001be68 at 1001be68

void FUN_1001be68(void)

{
  FID_conflict__Tidy(&DAT_1002a60c,'\x01',0);
  return;
}



// Function: FUN_1001be77 at 1001be77

void FUN_1001be77(void)

{
  FID_conflict__Tidy(&DAT_1002a628,'\x01',0);
  return;
}



// Function: FUN_1001be86 at 1001be86

void FUN_1001be86(void)

{
  FID_conflict__Tidy(&DAT_1002a644,'\x01',0);
  return;
}



// Function: FUN_1001be95 at 1001be95

void FUN_1001be95(void)

{
  FID_conflict__Tidy(&DAT_1002a660,'\x01',0);
  return;
}



// Function: FUN_1001bea4 at 1001bea4

void FUN_1001bea4(void)

{
  FID_conflict__Tidy(&DAT_1002a67c,'\x01',0);
  return;
}



// Function: FUN_1001beb3 at 1001beb3

void FUN_1001beb3(void)

{
  FID_conflict__Tidy(&DAT_1002a698,'\x01',0);
  return;
}



// Function: FUN_1001bec2 at 1001bec2

void FUN_1001bec2(void)

{
  FID_conflict__Tidy(&DAT_1002a6b4,'\x01',0);
  return;
}



// Function: FUN_1001bed1 at 1001bed1

void FUN_1001bed1(void)

{
  FID_conflict__Tidy(&DAT_1002a6d0,'\x01',0);
  return;
}



// Function: FUN_1001bee0 at 1001bee0

void FUN_1001bee0(void)

{
  FID_conflict__Tidy(&DAT_1002a6ec,'\x01',0);
  return;
}



// Function: FUN_1001beef at 1001beef

void FUN_1001beef(void)

{
  FID_conflict__Tidy(&DAT_1002a708,'\x01',0);
  return;
}



// Function: FUN_1001befe at 1001befe

void FUN_1001befe(void)

{
  FID_conflict__Tidy(&DAT_1002a724,'\x01',0);
  return;
}



// Function: FUN_1001bf0d at 1001bf0d

void FUN_1001bf0d(void)

{
  FID_conflict__Tidy(&DAT_1002a740,'\x01',0);
  return;
}



// Function: FUN_1001bf1c at 1001bf1c

void FUN_1001bf1c(void)

{
  FID_conflict__Tidy(&DAT_1002a778,'\x01',0);
  return;
}



// Function: FUN_1001bf2b at 1001bf2b

void FUN_1001bf2b(void)

{
  FID_conflict__Tidy(&DAT_1002a794,'\x01',0);
  return;
}



// Function: FUN_1001bf3a at 1001bf3a

void FUN_1001bf3a(void)

{
  FID_conflict__Tidy(&DAT_1002a7b0,'\x01',0);
  return;
}



// Function: FUN_1001bf49 at 1001bf49

void FUN_1001bf49(void)

{
  FUN_1000df2a((_Container_base0 *)&DAT_1002a768);
  return;
}



// Function: FUN_1001bf53 at 1001bf53

void FUN_1001bf53(void)

{
  Ordinal_6(DAT_1002a9a8);
  return;
}



// Function: FUN_1001bf60 at 1001bf60

void FUN_1001bf60(void)

{
  Ordinal_6(DAT_1002a9ac);
  return;
}



// Function: FUN_1001bf6d at 1001bf6d

void FUN_1001bf6d(void)

{
  Ordinal_6(DAT_1002a9b0);
  return;
}



// Function: FUN_1001bf7a at 1001bf7a

void FUN_1001bf7a(void)

{
  FID_conflict__Tidy(&DAT_1002a7cc,'\x01',0);
  return;
}



// Function: FUN_1001bf89 at 1001bf89

void FUN_1001bf89(void)

{
  FID_conflict__Tidy(&DAT_1002a7e8,'\x01',0);
  return;
}



// Function: FUN_1001bf98 at 1001bf98

void FUN_1001bf98(void)

{
  FID_conflict__Tidy(&DAT_1002a804,'\x01',0);
  return;
}



// Function: FUN_1001bfa7 at 1001bfa7

void FUN_1001bfa7(void)

{
  FID_conflict__Tidy(&DAT_1002a820,'\x01',0);
  return;
}



// Function: FUN_1001bfb6 at 1001bfb6

void FUN_1001bfb6(void)

{
  FID_conflict__Tidy(&DAT_1002a83c,'\x01',0);
  return;
}



// Function: FUN_1001bfc5 at 1001bfc5

void FUN_1001bfc5(void)

{
  FID_conflict__Tidy(&DAT_1002a858,'\x01',0);
  return;
}



// Function: FUN_1001bfd4 at 1001bfd4

void FUN_1001bfd4(void)

{
  FID_conflict__Tidy(&DAT_1002a874,'\x01',0);
  return;
}



// Function: FUN_1001bfe3 at 1001bfe3

void FUN_1001bfe3(void)

{
  FID_conflict__Tidy(&DAT_1002a890,'\x01',0);
  return;
}



// Function: FUN_1001bff2 at 1001bff2

void FUN_1001bff2(void)

{
  FID_conflict__Tidy(&DAT_1002a8ac,'\x01',0);
  return;
}



// Function: FUN_1001c001 at 1001c001

void FUN_1001c001(void)

{
  FID_conflict__Tidy(&DAT_1002a8c8,'\x01',0);
  return;
}



// Function: FUN_1001c010 at 1001c010

void FUN_1001c010(void)

{
  FID_conflict__Tidy(&DAT_1002a8e4,'\x01',0);
  return;
}



// Function: FUN_1001c01f at 1001c01f

void FUN_1001c01f(void)

{
  FID_conflict__Tidy(&DAT_1002a900,'\x01',0);
  return;
}



// Function: FUN_1001c02e at 1001c02e

void FUN_1001c02e(void)

{
  FID_conflict__Tidy(&DAT_1002a91c,'\x01',0);
  return;
}



// Function: FUN_1001c03d at 1001c03d

void FUN_1001c03d(void)

{
  FID_conflict__Tidy(&DAT_1002a938,'\x01',0);
  return;
}



// Function: FUN_1001c04c at 1001c04c

void FUN_1001c04c(void)

{
  FID_conflict__Tidy(&DAT_1002a954,'\x01',0);
  return;
}



// Function: FUN_1001c05b at 1001c05b

void FUN_1001c05b(void)

{
  FID_conflict__Tidy(&DAT_1002a970,'\x01',0);
  return;
}



// Function: FUN_1001c06a at 1001c06a

void FUN_1001c06a(void)

{
  FID_conflict__Tidy(&DAT_1002a98c,'\x01',0);
  return;
}



// Function: FUN_1001c079 at 1001c079

void FUN_1001c079(void)

{
  FID_conflict__Tidy(&DAT_1002a9b4,'\x01',0);
  return;
}



// Function: FUN_1001c088 at 1001c088

void FUN_1001c088(void)

{
  FID_conflict__Tidy(&DAT_1002a9d0,'\x01',0);
  return;
}



// Function: FUN_1001c097 at 1001c097

void FUN_1001c097(void)

{
  Ordinal_6(DAT_1002abc8);
  return;
}



// Function: FUN_1001c0a4 at 1001c0a4

void FUN_1001c0a4(void)

{
  Ordinal_6(DAT_1002abcc);
  return;
}



// Function: FUN_1001c0b1 at 1001c0b1

void FUN_1001c0b1(void)

{
  Ordinal_6(DAT_1002abd0);
  return;
}



// Function: FUN_1001c0be at 1001c0be

void FUN_1001c0be(void)

{
  FID_conflict__Tidy(&DAT_1002a9ec,'\x01',0);
  return;
}



// Function: FUN_1001c0cd at 1001c0cd

void FUN_1001c0cd(void)

{
  FID_conflict__Tidy(&DAT_1002aa08,'\x01',0);
  return;
}



// Function: FUN_1001c0dc at 1001c0dc

void FUN_1001c0dc(void)

{
  FID_conflict__Tidy(&DAT_1002aa24,'\x01',0);
  return;
}



// Function: FUN_1001c0eb at 1001c0eb

void FUN_1001c0eb(void)

{
  FID_conflict__Tidy(&DAT_1002aa40,'\x01',0);
  return;
}



// Function: FUN_1001c0fa at 1001c0fa

void FUN_1001c0fa(void)

{
  FID_conflict__Tidy(&DAT_1002aa5c,'\x01',0);
  return;
}



// Function: FUN_1001c109 at 1001c109

void FUN_1001c109(void)

{
  FID_conflict__Tidy(&DAT_1002aa78,'\x01',0);
  return;
}



// Function: FUN_1001c118 at 1001c118

void FUN_1001c118(void)

{
  FID_conflict__Tidy(&DAT_1002aa94,'\x01',0);
  return;
}



// Function: FUN_1001c127 at 1001c127

void FUN_1001c127(void)

{
  FID_conflict__Tidy(&DAT_1002aab0,'\x01',0);
  return;
}



// Function: FUN_1001c136 at 1001c136

void FUN_1001c136(void)

{
  FID_conflict__Tidy(&DAT_1002aacc,'\x01',0);
  return;
}



// Function: FUN_1001c145 at 1001c145

void FUN_1001c145(void)

{
  FID_conflict__Tidy(&DAT_1002aae8,'\x01',0);
  return;
}



// Function: FUN_1001c154 at 1001c154

void FUN_1001c154(void)

{
  FID_conflict__Tidy(&DAT_1002ab04,'\x01',0);
  return;
}



// Function: FUN_1001c163 at 1001c163

void FUN_1001c163(void)

{
  FID_conflict__Tidy(&DAT_1002ab20,'\x01',0);
  return;
}



// Function: FUN_1001c172 at 1001c172

void FUN_1001c172(void)

{
  FID_conflict__Tidy(&DAT_1002ab3c,'\x01',0);
  return;
}



// Function: FUN_1001c181 at 1001c181

void FUN_1001c181(void)

{
  FID_conflict__Tidy(&DAT_1002ab58,'\x01',0);
  return;
}



// Function: FUN_1001c190 at 1001c190

void FUN_1001c190(void)

{
  FID_conflict__Tidy(&DAT_1002ab74,'\x01',0);
  return;
}



// Function: FUN_1001c19f at 1001c19f

void FUN_1001c19f(void)

{
  FID_conflict__Tidy(&DAT_1002ab90,'\x01',0);
  return;
}



// Function: FUN_1001c1ae at 1001c1ae

void FUN_1001c1ae(void)

{
  FID_conflict__Tidy(&DAT_1002abac,'\x01',0);
  return;
}



// Function: FUN_1001c1bd at 1001c1bd

void FUN_1001c1bd(void)

{
  AFX_MODULE_STATE::~AFX_MODULE_STATE((AFX_MODULE_STATE *)&DAT_1002abf8);
  return;
}



// Function: FUN_1001c1c7 at 1001c1c7

void FUN_1001c1c7(void)

{
  FUN_10015a56(0x1002afd4);
  return;
}



// Function: FUN_1001c1d1 at 1001c1d1

void FUN_1001c1d1(void)

{
  FUN_10015b0b((int *)&DAT_1002b00c);
  return;
}



// Function: FUN_1001c1db at 1001c1db

void FUN_1001c1db(void)

{
  ATL::AtlWinModuleTerm((_ATL_WIN_MODULE70 *)&DAT_1002b034,DAT_1002afd8);
  RemoveAll((undefined4 *)&DAT_1002b054);
  return;
}



