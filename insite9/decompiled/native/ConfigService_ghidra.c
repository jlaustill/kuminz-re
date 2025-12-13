/*
 * Decompiled from: ConfigService.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001000 at 10001000

void __cdecl FUN_10001000(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar3 = *param_1;
  uVar4 = param_1[1];
  uVar1 = 0;
  iVar5 = 8;
  do {
    uVar3 = uVar3 + ((uVar4 >> 5 ^ uVar4 << 4) + uVar4 ^ uVar1 + 0x8775b);
    uVar2 = uVar1 + 0x9e3779b9;
    uVar4 = uVar4 + ((uVar3 >> 5 ^ uVar3 * 0x10) + uVar3 ^ (&DAT_1001ff10)[uVar2 >> 0xb & 3] + uVar2
                    );
    uVar3 = uVar3 + ((uVar4 >> 5 ^ uVar4 * 0x10) + uVar4 ^ (&DAT_1001ff10)[uVar2 & 3] + uVar2);
    uVar2 = uVar1 + 0x3c6ef372;
    uVar4 = uVar4 + ((uVar3 >> 5 ^ uVar3 * 0x10) + uVar3 ^ (&DAT_1001ff10)[uVar2 >> 0xb & 3] + uVar2
                    );
    uVar3 = uVar3 + ((uVar4 >> 5 ^ uVar4 * 0x10) + uVar4 ^ (&DAT_1001ff10)[uVar2 & 3] + uVar2);
    uVar2 = uVar1 + 0xdaa66d2b;
    uVar4 = uVar4 + ((uVar3 >> 5 ^ uVar3 * 0x10) + uVar3 ^ (&DAT_1001ff10)[uVar2 >> 0xb & 3] + uVar2
                    );
    uVar3 = uVar3 + ((uVar4 >> 5 ^ uVar4 * 0x10) + uVar4 ^ (&DAT_1001ff10)[uVar2 & 3] + uVar2);
    uVar1 = uVar1 + 0x78dde6e4;
    uVar4 = uVar4 + ((uVar3 >> 5 ^ uVar3 * 0x10) + uVar3 ^ (&DAT_1001ff10)[uVar1 >> 0xb & 3] + uVar1
                    );
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *param_1 = uVar3;
  param_1[1] = uVar4;
  return;
}



// Function: FUN_10001150 at 10001150

void __cdecl FUN_10001150(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = *param_1;
  uVar3 = param_1[1];
  iVar5 = 8;
  uVar1 = 0xc6ef3720;
  do {
    uVar3 = uVar3 - ((uVar4 >> 5 ^ uVar4 << 4) + uVar4 ^ (&DAT_1001ff10)[uVar1 >> 0xb & 3] + uVar1);
    uVar2 = uVar1 + 0x61c88647;
    uVar4 = uVar4 - ((uVar3 >> 5 ^ uVar3 * 0x10) + uVar3 ^ (&DAT_1001ff10)[uVar2 & 3] + uVar2);
    uVar3 = uVar3 - ((uVar4 >> 5 ^ uVar4 * 0x10) + uVar4 ^ (&DAT_1001ff10)[uVar2 >> 0xb & 3] + uVar2
                    );
    uVar2 = uVar1 + 0xc3910c8e;
    uVar4 = uVar4 - ((uVar3 >> 5 ^ uVar3 * 0x10) + uVar3 ^ (&DAT_1001ff10)[uVar2 & 3] + uVar2);
    uVar3 = uVar3 - ((uVar4 >> 5 ^ uVar4 * 0x10) + uVar4 ^ (&DAT_1001ff10)[uVar2 >> 0xb & 3] + uVar2
                    );
    uVar2 = uVar1 + 0x255992d5;
    uVar4 = uVar4 - ((uVar3 >> 5 ^ uVar3 * 0x10) + uVar3 ^ (&DAT_1001ff10)[uVar2 & 3] + uVar2);
    uVar3 = uVar3 - ((uVar4 >> 5 ^ uVar4 * 0x10) + uVar4 ^ (&DAT_1001ff10)[uVar2 >> 0xb & 3] + uVar2
                    );
    uVar4 = uVar4 - ((uVar3 >> 5 ^ uVar3 * 0x10) + uVar3 ^ uVar1 + 0x872a9077);
    iVar5 = iVar5 + -1;
    uVar1 = uVar1 + 0x8722191c;
  } while (iVar5 != 0);
  *param_1 = uVar4;
  param_1[1] = uVar3;
  return;
}



// Function: FUN_100012a0 at 100012a0

uint __cdecl FUN_100012a0(void *param_1,uint param_2,undefined4 *param_3)

{
  void *_Dst;
  int iVar1;
  uint _Size;
  undefined1 *puVar2;
  undefined1 *puVar3;
  uint local_18;
  undefined4 local_14;
  void *local_10;
  uint local_c;
  int local_8;
  
  iVar1 = 8 - (param_2 & 7);
  if (iVar1 == 8) {
    iVar1 = 0;
  }
  _Size = iVar1 + param_2;
  local_c = _Size;
  _Dst = malloc(_Size);
  memcpy(_Dst,param_1,param_2);
  if (param_2 < _Size) {
    memset((void *)((int)_Dst + param_2),0,_Size - param_2);
  }
  local_10 = malloc(_Size);
  if (_Size != 0) {
    local_8 = (int)_Dst - (int)local_10;
    puVar3 = (undefined1 *)((int)_Dst + 3);
    puVar2 = (undefined1 *)((int)local_10 + 2);
    iVar1 = (_Size - 1 >> 3) + 1;
    do {
      local_18 = CONCAT31(CONCAT21(CONCAT11(*puVar3,puVar2[local_8]),puVar3[-2]),puVar3[-3]);
      local_14 = *(undefined4 *)(puVar3 + 1);
      FUN_10001000(&local_18);
      puVar2[-2] = (char)local_18;
      puVar2[1] = (char)(local_18 >> 0x18);
      puVar2[-1] = (char)(local_18 >> 8);
      *puVar2 = (char)(local_18 >> 0x10);
      puVar2[2] = (char)local_14;
      puVar2[3] = (char)((uint)local_14 >> 8);
      puVar2[4] = (char)((uint)local_14 >> 0x10);
      puVar2[5] = (char)((uint)local_14 >> 0x18);
      puVar3 = puVar3 + 8;
      puVar2 = puVar2 + 8;
      iVar1 = iVar1 + -1;
      _Size = local_c;
    } while (iVar1 != 0);
  }
  free(_Dst);
  *param_3 = local_10;
  return _Size;
}



// Function: FUN_100013e0 at 100013e0

uint __cdecl FUN_100013e0(void *param_1,uint param_2,undefined4 *param_3)

{
  void *_Dst;
  int iVar1;
  uint _Size;
  undefined1 *puVar2;
  undefined1 *puVar3;
  uint local_18;
  undefined4 local_14;
  void *local_10;
  uint local_c;
  int local_8;
  
  iVar1 = 8 - (param_2 & 7);
  if (iVar1 == 8) {
    iVar1 = 0;
  }
  _Size = iVar1 + param_2;
  local_c = _Size;
  _Dst = malloc(_Size);
  memcpy(_Dst,param_1,param_2);
  if (param_2 < _Size) {
    memset((void *)((int)_Dst + param_2),0,_Size - param_2);
  }
  local_10 = malloc(_Size);
  if (_Size != 0) {
    local_8 = (int)_Dst - (int)local_10;
    puVar3 = (undefined1 *)((int)_Dst + 3);
    puVar2 = (undefined1 *)((int)local_10 + 2);
    iVar1 = (_Size - 1 >> 3) + 1;
    do {
      local_18 = CONCAT31(CONCAT21(CONCAT11(*puVar3,puVar2[local_8]),puVar3[-2]),puVar3[-3]);
      local_14 = *(undefined4 *)(puVar3 + 1);
      FUN_10001150(&local_18);
      puVar2[-2] = (char)local_18;
      puVar2[1] = (char)(local_18 >> 0x18);
      puVar2[-1] = (char)(local_18 >> 8);
      *puVar2 = (char)(local_18 >> 0x10);
      puVar2[2] = (char)local_14;
      puVar2[3] = (char)((uint)local_14 >> 8);
      puVar2[4] = (char)((uint)local_14 >> 0x10);
      puVar2[5] = (char)((uint)local_14 >> 0x18);
      puVar3 = puVar3 + 8;
      puVar2 = puVar2 + 8;
      iVar1 = iVar1 + -1;
      _Size = local_c;
    } while (iVar1 != 0);
  }
  free(_Dst);
  *param_3 = local_10;
  return _Size;
}



// Function: AtlW2AHelper at 10001517

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



// Function: FUN_1000154f at 1000154f

void FUN_1000154f(undefined4 param_1)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&param_1,(ThrowInfo *)&DAT_10020da0);
}



// Function: FUN_10001567 at 10001567

void __fastcall FUN_10001567(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FID_conflict:RegOpenKeyExA at 10001570

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
                    /* WARNING: Could not recover jumptable at 0x100015b9. Too many branches */
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



// Function: Close at 100015c7

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



// Function: Open at 100015e2

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



// Function: FUN_10001656 at 10001656

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

exception * __thiscall FUN_10001656(void *this,byte param_1)

{
  *(undefined ***)this = std::bad_alloc::vftable;
  std::exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (exception *)this;
}



// Function: FUN_1000168e at 1000168e

void __cdecl FUN_1000168e(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  if (param_3 == 0) {
    param_3 = param_2;
  }
  Ordinal_147(param_3,param_2,param_4,0,param_1);
  return;
}



// Function: FUN_100016af at 100016af

void __fastcall FUN_100016af(int *param_1)

{
  int *_Memory;
  
  while (*param_1 != 0) {
    _Memory = (int *)*param_1;
    *param_1 = *_Memory;
    free(_Memory);
  }
  return;
}



// Function: FID_conflict:_Inside at 100016c9

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



// Function: _Inside at 10001705

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



// Function: FUN_10001740 at 10001740

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __cdecl FUN_10001740(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000174c;
  if ((param_1 != (char *)0x0) && (pvVar1 = operator_new((uint)param_1), pvVar1 == (void *)0x0)) {
    param_1 = (char *)0x0;
    std::exception::exception((exception *)local_1c,&param_1);
    local_1c[0] = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10020dd4);
  }
  return;
}



// Function: FUN_1000179a at 1000179a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_1000179a(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x100017a6;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10020dd4);
}



// Function: FUN_1000182b at 1000182b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

LPWSTR __cdecl FUN_1000182b(LPCSTR param_1,int param_2)

{
  int cchWideChar;
  LPWSTR lpWideCharStr;
  int iVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  if ((param_1 == (LPCSTR)0x0) || (param_2 == 0)) {
LAB_1000189c:
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
        FUN_100016af(local_14);
        goto LAB_1000189c;
      }
    }
    local_8 = 0xffffffff;
    FUN_100016af(local_14);
  }
  return lpWideCharStr;
}



// Function: CComBSTR at 100018b5

/* Library Function - Single Match
    public: __thiscall ATL::CComBSTR::CComBSTR(char const *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

CComBSTR * __thiscall ATL::CComBSTR::CComBSTR(CComBSTR *this,char *param_1)

{
  LPWSTR pWVar1;
  
  if (param_1 != (char *)0x0) {
    pWVar1 = FUN_1000182b(param_1,-1);
    *(LPWSTR *)this = pWVar1;
    if (pWVar1 != (LPWSTR)0x0) {
      return this;
    }
    FUN_1000154f(0x8007000e);
  }
  *(undefined4 *)this = 0;
  return this;
}



// Function: FUN_100018e7 at 100018e7

void __fastcall FUN_100018e7(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: FUN_100018ef at 100018ef

undefined2 * __thiscall FUN_100018ef(void *this,int param_1)

{
  int iVar1;
  
  iVar1 = Ordinal_9(this);
  if (-1 < iVar1) goto LAB_10001906;
  while( true ) {
    FUN_1000154f(iVar1);
LAB_10001906:
    *(undefined2 *)this = 8;
    iVar1 = Ordinal_2(param_1);
    *(int *)((int)this + 8) = iVar1;
    if ((iVar1 != 0) || (param_1 == 0)) break;
    *(undefined2 *)this = 10;
    iVar1 = -0x7ff8fff2;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
  }
  return (undefined2 *)this;
}



// Function: FUN_10001938 at 10001938

LSTATUS __fastcall FUN_10001938(undefined4 *param_1)

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



// Function: FID_conflict:_Tidy at 1000193d

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



// Function: FUN_10001986 at 10001986

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void __thiscall FUN_10001986(void *this,uint param_1)

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
  FUN_1000179a((char *)(param_1 + 1));
  FUN_10001a1b();
  return;
}



// Function: Catch@100019ed at 100019ed

undefined * Catch_100019ed(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_1000179a((char *)(iVar1 + 1));
  *(void **)(unaff_EBP + -0x18) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10001a15;
}



// Function: FUN_10001a1b at 10001a1b

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10001a1b(void)

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



// Function: Catch@10001a69 at 10001a69

void Catch_10001a69(void)

{
  int unaff_EBP;
  
  FID_conflict__Tidy(*(void **)(unaff_EBP + -0x1c),'\x01',0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10001a7e at 10001a7e

undefined4 * __thiscall FUN_10001a7e(void *this,uint param_1,uint param_2)

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



// Function: FUN_10001af8 at 10001af8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

float10 __cdecl FUN_10001af8(int param_1)

{
  undefined2 local_24 [4];
  float local_1c;
  float local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x10001b04;
  local_24[0] = 0;
  FUN_100018ef(local_24,param_1);
  local_8 = 0;
  FUN_1000168e(4,(int)local_24,0,0x409);
  local_14 = local_1c;
  local_8 = 0xffffffff;
  Ordinal_9(local_24);
  return (float10)local_14;
}



// Function: ~basic_string<> at 10001b4b

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



// Function: FUN_10001b55 at 10001b55

undefined4 * __thiscall FUN_10001b55(void *this,uint param_1,uint param_2)

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



// Function: _Tidy at 10001bd6

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



// Function: FUN_10001c1a at 10001c1a

bool __thiscall FUN_10001c1a(void *this,uint param_1,char param_2)

{
  uint uVar1;
  undefined4 *extraout_ECX;
  
  if (0x7ffffffe < param_1) {
    std::_Xlength_error("string too long");
    this = extraout_ECX;
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_10001986(this,param_1);
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



// Function: FUN_10001c84 at 10001c84

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void __thiscall FUN_10001c84(void *this,uint param_1)

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
  FUN_10001740((char *)(param_1 + 1));
  FUN_10001d14();
  return;
}



// Function: Catch@10001ce6 at 10001ce6

undefined * Catch_10001ce6(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar2 = FUN_10001740((char *)(iVar1 + 1));
  *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10001d0e;
}



// Function: FUN_10001d14 at 10001d14

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10001d14(void)

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



// Function: Catch@10001d5d at 10001d5d

void Catch_10001d5d(void)

{
  int unaff_EBP;
  
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
              (unaff_EBP + -0x1c),true,0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10001d72 at 10001d72

void __fastcall
FUN_10001d72(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (param_1,true,0);
  return;
}



// Function: FUN_10001d7c at 10001d7c

undefined4 * __thiscall FUN_10001d7c(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    FUN_10001b55(pvVar3,uVar4 + uVar2,0xffffffff);
    FUN_10001b55(this,0,param_2);
  }
  else {
    bVar1 = FUN_10001c1a(pvVar3,uVar4,'\0');
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



// Function: FID_conflict:assign at 10001e18

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
    bVar1 = FUN_10001c1a(this,param_2,'\0');
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
    this = FUN_10001d7c(this,(undefined4 *)this,(int)param_1 - (int)pvVar3 >> 1,param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_10001e96 at 10001e96

bool __thiscall FUN_10001e96(void *this,uint param_1,char param_2)

{
  uint uVar1;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *extraout_ECX;
  
  if (param_1 == 0xffffffff) {
    std::_Xlength_error("string too long");
    this = extraout_ECX;
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_10001c84(this,param_1);
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



// Function: basic_string<> at 10001efb

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
  FUN_10001d7c(this,param_1,0,0xffffffff);
  return (undefined2 *)this;
}



// Function: basic_string<> at 10001f23

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



// Function: FUN_10001f4b at 10001f4b

undefined4 * __thiscall FUN_10001f4b(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    FUN_10001a7e(this,_Size + uVar4,0xffffffff);
    FUN_10001a7e(this,0,param_2);
  }
  else {
    bVar1 = FUN_10001e96(this,_Size,'\0');
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



// Function: FUN_10001fe5 at 10001fe5

undefined2 * __thiscall FUN_10001fe5(void *this,wchar_t *param_1)

{
  size_t sVar1;
  
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)this = 0;
  sVar1 = wcslen(param_1);
  FID_conflict_assign(this,(undefined4 *)param_1,sVar1);
  return (undefined2 *)this;
}



// Function: FUN_10002017 at 10002017

undefined4 * __thiscall FUN_10002017(void *this,undefined4 *param_1)

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



// Function: assign at 10002074

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
           FUN_10001f4b(this,(undefined4 *)this,(int)param_1 - (int)pbVar2,param_2);
  }
  else {
    bVar1 = FUN_10001e96(this,param_2,'\0');
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



// Function: basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> at 100020e9

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



// Function: FUN_10002118 at 10002118

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
FUN_10002118(void *this,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1)

{
  if ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this !=
      param_1) {
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this,
               true,0);
    if (*(uint *)(param_1 + 0x14) < 0x10) {
      memmove(this,param_1,*(int *)(param_1 + 0x10) + 1);
    }
    else {
      *(undefined4 *)this = *(undefined4 *)param_1;
      *(undefined4 *)param_1 = 0;
    }
    *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)((int)this + 0x14) = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0xf;
    *param_1 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
  }
  return (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this;
}



// Function: FUN_10002170 at 10002170

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __cdecl
FUN_10002170(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,
            LPCWSTR param_2)

{
  int iVar1;
  char *pcVar2;
  CHAR local_28 [16];
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x1000217c;
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
  FUN_1001739f();
  return;
}



// Function: FUN_100021ed at 100021ed

void __fastcall FUN_100021ed(undefined4 *param_1)

{
  *param_1 = CGenericException::vftable;
  return;
}



// Function: FUN_100021f4 at 100021f4

undefined4 * __thiscall FUN_100021f4(void *this,byte param_1)

{
  *(undefined ***)this = CGenericException::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002214 at 10002214

void __thiscall FUN_10002214(void *this,int param_1)

{
  *(undefined ***)this = CGenericException::vftable;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  return;
}



// Function: AtlCrtErrorCheck at 10002238

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
  else {
    if (param_1 == 0x16) goto LAB_10002260;
    if (param_1 == 0x22) goto LAB_10002260;
    if (param_1 == 0x50) {
      return param_1;
    }
    uVar1 = 0x80004005;
  }
  do {
    FUN_1000154f(uVar1);
LAB_10002260:
    uVar1 = 0x80070057;
  } while( true );
}



// Function: FUN_10002270 at 10002270

void __cdecl FUN_10002270(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: AtlComQIPtrAssign at 10002290

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



// Function: Attach at 100022c7

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



// Function: FUN_100022e6 at 100022e6

undefined4 __thiscall FUN_100022e6(void *this,int *param_1)

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



// Function: FUN_1000230d at 1000230d

void __fastcall FUN_1000230d(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: AtlAdd<> at 1000231a

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



// Function: FUN_1000233e at 1000233e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000233e(undefined4 *param_1)

{
  *param_1 = CGenericExceptionEx::vftable;
  Ordinal_6(param_1[4]);
  *param_1 = CGenericException::vftable;
  return;
}



// Function: FUN_10002372 at 10002372

undefined4 * __thiscall FUN_10002372(void *this,byte param_1)

{
  FUN_1000233e((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002391 at 10002391

int * __thiscall FUN_10002391(void *this,int param_1)

{
  int iVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (param_1 != *this) {
    Ordinal_6(*this);
    if (param_1 != 0) {
      iVar1 = Ordinal_2(param_1);
      *(int *)this = iVar1;
      if (iVar1 != 0) {
        return (int *)this;
      }
      FUN_1000154f(0x8007000e);
    }
    *(undefined4 *)this = 0;
  }
  return (int *)this;
}



// Function: Copy at 100023ce

/* Library Function - Single Match
    public: wchar_t * __thiscall ATL::CComBSTR::Copy(void)const 
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

wchar_t * __thiscall ATL::CComBSTR::Copy(CComBSTR *this)

{
  undefined4 uVar1;
  wchar_t *pwVar2;
  
  pwVar2 = *(wchar_t **)this;
  if (pwVar2 == (wchar_t *)0x0) {
    return pwVar2;
  }
  uVar1 = Ordinal_149(pwVar2);
  pwVar2 = (wchar_t *)Ordinal_150(*(undefined4 *)this,uVar1);
  return pwVar2;
}



// Function: FUN_100023eb at 100023eb

long __thiscall FUN_100023eb(void *this,void *param_1,uint param_2)

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
      FUN_10002270(pvVar4,local_10,*this,local_c);
    }
    FUN_10002270((void *)((int)pvVar4 + uVar1 * 2),param_2 * 2,param_1,param_2 * 2);
    *(undefined2 *)((int)pvVar4 + local_8 * 2) = 0;
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this);
    *(void **)this = pvVar4;
  }
  return 0;
}



// Function: FUN_100024d7 at 100024d7

undefined4 __fastcall FUN_100024d7(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    *param_1 = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
    param_1[1] = 0;
    return 0;
  }
  return 0x80004003;
}



// Function: CComBSTR at 100024f8

/* Library Function - Single Match
    public: __thiscall ATL::CComBSTR::CComBSTR(class ATL::CComBSTR const &)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

CComBSTR * __thiscall ATL::CComBSTR::CComBSTR(CComBSTR *this,CComBSTR *param_1)

{
  wchar_t *pwVar1;
  
  pwVar1 = Copy(param_1);
  *(wchar_t **)this = pwVar1;
  if ((*(int *)param_1 != 0) && (pwVar1 == (wchar_t *)0x0)) {
    FUN_1000154f(0x8007000e);
  }
  return this;
}



// Function: FUN_10002526 at 10002526

int * __thiscall FUN_10002526(void *this,CComBSTR *param_1)

{
  wchar_t *pwVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != *(int *)param_1) {
    Ordinal_6(*this);
    pwVar1 = ATL::CComBSTR::Copy(param_1);
    *(wchar_t **)this = pwVar1;
    if ((*(int *)param_1 != 0) && (pwVar1 == (wchar_t *)0x0)) {
      FUN_1000154f(0x8007000e);
    }
  }
  return (int *)this;
}



// Function: FUN_10002561 at 10002561

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10002561(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 1;
  return;
}



// Function: FUN_1000258e at 1000258e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_1000258e(int *param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  
  puVar2 = &LAB_1001803d;
  if (param_1[1] != 0) {
    puVar2 = (undefined1 *)FUN_100024d7(param_1);
  }
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    puVar2 = (undefined1 *)(**(code **)(*piVar1 + 8))(piVar1);
  }
  return puVar2;
}



// Function: FUN_100025c4 at 100025c4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 __thiscall FUN_100025c4(void *this,int *param_1)

{
  int iVar1;
  code *pcVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uStack_28;
  int *piStack_24;
  undefined1 auStack_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar3 = param_1;
  uStack_4 = 0;
  local_8 = 0x100025d0;
  puVar5 = (undefined4 *)auStack_20;
  if (param_1 == (int *)0x0) {
    *(undefined4 *)((int)this + 4) = 0;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if (*this == 0) {
      piStack_24 = param_1;
      puVar4 = &uStack_28;
      uStack_28 = 0x100025e7;
      (**(code **)(*param_1 + 4))();
      local_8 = 1;
      puVar4[-1] = this;
      puVar4[-2] = 0x100025f6;
      FUN_100022e6(&param_1,(int *)puVar4[-1]);
      *(undefined4 *)((int)this + 4) = 1;
      uVar6 = 0;
      local_8 = 0xffffffff;
      iVar1 = *piVar3;
      puVar4[-1] = piVar3;
      pcVar2 = *(code **)(iVar1 + 8);
      puVar5 = puVar4 + -2;
      puVar4[-2] = 0x10002605;
      (*pcVar2)();
      goto LAB_10002610;
    }
  }
  uVar6 = 0x80004003;
LAB_10002610:
  *(undefined4 *)((int)puVar5 + -4) = 0x10002617;
  return uVar6;
}



// Function: FUN_1000261a at 1000261a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000261a(void *this,int param_1)

{
  *(undefined ***)this = CGenericException::vftable;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined ***)this = CGenericExceptionEx::vftable;
  ATL::CComBSTR::CComBSTR((CComBSTR *)((int)this + 0x10),(CComBSTR *)(param_1 + 0x10));
  return (undefined4 *)this;
}



// Function: FUN_1000266a at 1000266a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall
FUN_1000266a(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)((int)this + 4) = param_3;
  *(undefined4 *)((int)this + 8) = param_2;
  *(undefined ***)this = CGenericException::vftable;
  *(undefined4 *)((int)this + 0xc) = param_1;
  *(undefined ***)this = CGenericExceptionEx::vftable;
  *(undefined4 *)((int)this + 0x10) = 0;
  FUN_10002526((undefined4 *)((int)this + 0x10),(CComBSTR *)&param_4);
  Ordinal_6(param_4);
  return (undefined4 *)this;
}



// Function: FUN_100026cb at 100026cb

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_100026cb(void *this,undefined4 param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined1 *pExceptionObject;
  undefined1 local_8c [20];
  undefined1 local_78 [20];
  undefined1 local_64 [20];
  undefined1 local_50 [20];
  undefined1 local_3c [24];
  undefined1 *local_24;
  int *local_20;
  int *local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x7c;
  local_20 = (int *)0x0;
  local_1c = (int *)0x0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 5;
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 == (int *)0x0) {
    local_24 = &stack0xffffff60;
    local_8._1_3_ = 0;
    local_8._0_1_ = 5;
    puVar2 = FUN_1000266a(local_8c,0x80004003,0,0,0);
    local_8 = CONCAT31(local_8._1_3_,7);
    FUN_1000261a(local_3c,(int)puVar2);
    pExceptionObject = local_3c;
  }
  else {
    local_18 = (**(code **)(*piVar1 + 0x44))(piVar1);
    if (local_18 < 0) {
      local_24 = &stack0xffffff60;
      local_8._0_1_ = 5;
      puVar2 = FUN_1000266a(local_8c,local_18,0,0,0);
      local_8 = CONCAT31(local_8._1_3_,9);
      FUN_1000261a(local_50,(int)puVar2);
      pExceptionObject = local_50;
    }
    else {
      if (local_20 != (int *)0x0) {
        local_18 = (**(code **)(*local_20 + 0x1c))(local_20,param_1);
        if (local_18 == 0) {
          local_18 = (**(code **)(*local_1c + 0x20))(local_1c);
          if (local_18 < 0) {
            local_24 = &stack0xffffff60;
            local_8._0_1_ = 5;
            puVar2 = FUN_1000266a(local_8c,local_18,0,0,0);
            local_8 = CONCAT31(local_8._1_3_,0xd);
            FUN_1000261a(local_78,(int)puVar2);
            pExceptionObject = local_78;
            goto LAB_10002733;
          }
        }
        else {
          local_18 = -0x7fffbffb;
        }
        local_8._0_1_ = 3;
        if (local_1c != (int *)0x0) {
          (**(code **)(*local_1c + 8))();
        }
        local_8 = CONCAT31(local_8._1_3_,1);
        if (local_20 != (int *)0x0) {
          (**(code **)(*local_20 + 8))();
        }
        local_8 = 0xffffffff;
        Ordinal_6();
        return local_18;
      }
      local_24 = &stack0xffffff60;
      local_8._0_1_ = 5;
      puVar2 = FUN_1000266a(local_8c,0x80004003,0,0,0);
      local_8 = CONCAT31(local_8._1_3_,0xb);
      FUN_1000261a(local_64,(int)puVar2);
      pExceptionObject = local_64;
    }
  }
LAB_10002733:
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(pExceptionObject,(ThrowInfo *)&DAT_10021130);
}



// Function: Catch@10002871 at 10002871

undefined * Catch_10002871(void)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  int unaff_EBP;
  
  uVar1 = *(undefined4 *)(*(int *)(unaff_EBP + -0x24) + 0xc);
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  puVar2 = *(undefined2 **)(unaff_EBP + 0xc);
  *puVar2 = 10;
  *(undefined4 *)(puVar2 + 4) = uVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10002890;
}



// Function: Catch@10002892 at 10002892

undefined4 Catch_10002892(void)

{
  undefined2 *puVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x8000ffff;
  puVar1 = *(undefined2 **)(unaff_EBP + 0xc);
  *puVar1 = 10;
  *(undefined4 *)(puVar1 + 4) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10002859;
}



// Function: FUN_100028b0 at 100028b0

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void __thiscall FUN_100028b0(void *this,undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 *pExceptionObject;
  undefined4 extraout_ECX;
  undefined4 uVar4;
  undefined1 local_70 [20];
  undefined1 local_5c [20];
  undefined1 local_48 [20];
  short local_34;
  int local_2c;
  undefined1 *local_20;
  int local_1c;
  int local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x60;
  local_18[0] = 0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
  Ordinal_8();
  local_8._0_1_ = 3;
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    param_2 = (int *)&stack0xffffff78;
    local_8._0_1_ = 3;
    puVar3 = FUN_1000266a(local_70,0x80004003,0,0,0);
    local_8 = CONCAT31(local_8._1_3_,5);
    FUN_1000261a(local_48,(int)puVar3);
    pExceptionObject = local_48;
LAB_10002914:
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(pExceptionObject,(ThrowInfo *)&DAT_10021130);
  }
  local_20 = &stack0xffffff74;
  uVar4 = extraout_ECX;
  ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xffffff74,(CComBSTR *)&param_1);
  local_8._0_1_ = 3;
  local_1c = FUN_100026cb(this,uVar4);
  piVar1 = param_2;
  if (local_1c == 0) {
    if (local_34 != 8) {
      param_2 = (int *)&stack0xffffff78;
      local_8._0_1_ = 3;
      puVar3 = FUN_1000266a(local_70,0x80004005,0,0,0);
      local_8 = CONCAT31(local_8._1_3_,8);
      FUN_1000261a(local_5c,(int)puVar3);
      pExceptionObject = local_5c;
      goto LAB_10002914;
    }
    if ((*param_2 != 0) && (*param_2 != -0x33333334)) {
      Ordinal_6();
    }
    FUN_10002391(local_18,local_2c);
    iVar2 = local_18[0];
    local_18[0] = 0;
    *piVar1 = iVar2;
  }
  else {
    local_1c = -0x7fffbffb;
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  Ordinal_9();
  local_8 = 1;
  FUN_100029e5();
  return;
}



// Function: Catch@100029cd at 100029cd

undefined * Catch_100029cd(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(*(int *)(unaff_EBP + -0x20) + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_100029e3;
}



// Function: FUN_100029e5 at 100029e5

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100029e5(void)

{
  undefined1 unaff_BL;
  int unaff_EBP;
  
  *(undefined1 *)(unaff_EBP + -4) = unaff_BL;
  Ordinal_6(*(undefined4 *)(unaff_EBP + -0x14));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  Ordinal_6(*(undefined4 *)(unaff_EBP + 8));
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: Catch@10002a07 at 10002a07

undefined * Catch_10002a07(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x18) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_100029e3;
}



// Function: _InlineIsEqualGUID at 10002a1b

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



// Function: FUN_10002a4b at 10002a4b

bool __cdecl FUN_10002a4b(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,0x10);
  return (bool)('\x01' - (iVar1 != 0));
}



// Function: AtlMultiply<unsigned_long> at 10002a65

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



// Function: AtlCoTaskMemCAlloc at 10002a87

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



// Function: FUN_10002ab4 at 10002ab4

LPVOID __cdecl FUN_10002ab4(LPVOID param_1,ulong param_2,ulong param_3)

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



// Function: FUN_10002ae4 at 10002ae4

bool __cdecl FUN_10002ae4(void *param_1,int param_2,LPCWSTR param_3)

{
  int iVar1;
  errno_t eVar2;
  
  iVar1 = lstrlenW(param_3);
  eVar2 = memcpy_s(param_1,param_2 * 2,param_3,iVar1 * 2 + 2);
  return (bool)('\x01' - (eVar2 != 0));
}



// Function: FUN_10002b11 at 10002b11

void __cdecl FUN_10002b11(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscpy_s(param_1,param_2,param_3);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: Init at 10002b2e

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



// Function: FUN_10002b57 at 10002b57

void __fastcall FUN_10002b57(LPCRITICAL_SECTION param_1)

{
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  return;
}



// Function: FUN_10002b69 at 10002b69

DWORD FUN_10002b69(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}



// Function: FUN_10002b7e at 10002b7e

uint __cdecl FUN_10002b7e(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FID_conflict:RegCreateKeyExW at 10002b94

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
                    /* WARNING: Could not recover jumptable at 0x10002be9. Too many branches */
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



// Function: FID_conflict:RegDeleteKeyA at 10002bf7

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
                    /* WARNING: Could not recover jumptable at 0x10002c3a. Too many branches */
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



// Function: FUN_10002c49 at 10002c49

undefined4 __fastcall FUN_10002c49(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10002c4d at 10002c4d

void __cdecl FUN_10002c4d(short *param_1,int param_2,short *param_3)

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



// Function: FUN_10002c9b at 10002c9b

int __fastcall FUN_10002c9b(int param_1)

{
  memset((void *)(param_1 + 0xc),0,0x18);
  return param_1;
}



// Function: DeleteSubKey at 10002cb2

/* Library Function - Multiple Matches With Same Base Name
    public: long __thiscall ATL::CRegKey::DeleteSubKey(char const *)
    public: long __thiscall ATL::CRegKey::DeleteSubKey(wchar_t const *)
   
   Library: Visual Studio 2010 Release */

void __thiscall DeleteSubKey(void *this,LPCWSTR param_1)

{
  HMODULE hModule;
  
  if (*(int *)((int)this + 8) == 0) {
    if (DAT_10027014 == '\0') {
      hModule = GetModuleHandleW(L"Advapi32.dll");
      if (hModule != (HMODULE)0x0) {
        DAT_10027010 = GetProcAddress(hModule,"RegDeleteKeyExW");
      }
      DAT_10027014 = '\x01';
    }
    if (DAT_10027010 == (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      RegDeleteKeyW(*this,param_1);
    }
    else {
                    /* WARNING: Load size is inaccurate */
      (*DAT_10027010)(*this,param_1,*(undefined4 *)((int)this + 4),0);
    }
  }
  else {
                    /* WARNING: Load size is inaccurate */
    FID_conflict_RegDeleteKeyA(*this,(LPCSTR)param_1);
  }
  return;
}



// Function: Create at 10002d22

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



// Function: SetStringValue at 10002d8a

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



// Function: FUN_10002dc1 at 10002dc1

LSTATUS __thiscall FUN_10002dc1(void *this,LPCWSTR param_1,LPCWSTR param_2)

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



// Function: DllCanUnloadNow at 10002e04

HRESULT DllCanUnloadNow(void)

{
                    /* 0x2e04  1  DllCanUnloadNow */
  return (uint)(DAT_10027044 != 0);
}



// Function: FUN_10002e10 at 10002e10

undefined4 __fastcall FUN_10002e10(undefined4 *param_1)

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



// Function: FUN_10002e30 at 10002e30

undefined4 * __thiscall FUN_10002e30(void *this,ulong param_1)

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



// Function: FUN_10002e66 at 10002e66

void __fastcall FUN_10002e66(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_10002e70 at 10002e70

undefined4 __thiscall FUN_10002e70(void *this,void *param_1,int param_2)

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
      pvVar4 = FUN_10002ab4(*(LPVOID *)((int)this + 8),uVar3,2);
      if (pvVar4 == (LPVOID)0x0) {
        return 0;
      }
      *(LPVOID *)((int)this + 8) = pvVar4;
    }
                    /* WARNING: Load size is inaccurate */
    iVar1 = *this;
    if (((-1 < iVar1) && (iVar2 = *(int *)((int)this + 4), iVar1 < iVar2)) &&
       (iVar2 - iVar1 <= iVar2)) {
      FUN_10002270((void *)(*(int *)((int)this + 8) + iVar1 * 2),(iVar2 - iVar1) * 2,param_1,
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



// Function: FUN_10002efe at 10002efe

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10002efe(undefined4 param_1,undefined2 *param_2)

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
  local_8 = 0x10002f0a;
  uVar5 = 0;
  puVar3 = auStack_20;
  if ((DAT_10027038 & 1) == 0) {
    DAT_10027038 = DAT_10027038 | 1;
    DAT_1002701c = 8;
    _DAT_10027024 = 0x4008;
    _DAT_1002702c = 0x13;
    DAT_10027018 = &DAT_1001e56c;
    DAT_10027020 = &DAT_1001e568;
    _DAT_10027028 = &DAT_1001e564;
    _DAT_10027030 = &DAT_1001e560;
    _DAT_10027034 = 0x11;
    local_8 = 0xffffffff;
  }
  do {
    *(undefined **)(puVar3 + -4) = (&DAT_10027018)[uVar5 * 2];
    *(undefined4 *)(puVar3 + -8) = param_1;
    puVar4 = puVar3 + -0xc;
    *(undefined4 *)(puVar3 + -0xc) = 0x10002f81;
    iVar1 = lstrcmpiW(*(LPCWSTR *)(puVar3 + -8),*(LPCWSTR *)(puVar3 + -4));
    if (iVar1 == 0) {
      *param_2 = (&DAT_1002701c)[uVar5 * 4];
      uVar2 = 1;
      goto LAB_10002f8d;
    }
    uVar5 = uVar5 + 1;
    puVar3 = puVar4;
  } while (uVar5 < 4);
  uVar2 = 0;
LAB_10002f8d:
  *(undefined4 *)(puVar4 + -4) = 0x10002f92;
  return uVar2;
}



// Function: FUN_10002fa6 at 10002fa6

int __cdecl FUN_10002fa6(ushort param_1)

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



// Function: FUN_10002fdc at 10002fdc

undefined4 __cdecl FUN_10002fdc(LPCWSTR param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_HKCR_1001e858)[uVar2 * 2]);
    if (iVar1 == 0) {
      return (&DAT_1001e85c)[uVar2 * 2];
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xe);
  return 0;
}



// Function: FUN_1000300a at 1000300a

LPCWSTR __cdecl FUN_1000300a(LPCWSTR param_1,WCHAR param_2)

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



// Function: FUN_10003037 at 10003037

undefined4 FUN_10003037(ushort param_1)

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



// Function: FUN_1000305d at 1000305d

void __fastcall FUN_1000305d(undefined4 *param_1)

{
  LPWSTR pWVar1;
  int iVar2;
  
  while( true ) {
    iVar2 = FUN_10003037(*(ushort *)*param_1);
    if (iVar2 == 0) break;
    pWVar1 = CharNextW((LPCWSTR)*param_1);
    *param_1 = pWVar1;
  }
  return;
}



// Function: FUN_1000307f at 1000307f

undefined4 __thiscall FUN_1000307f(void *this,undefined2 *param_1)

{
  WCHAR WVar1;
  LPCWSTR pWVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  
  FUN_1000305d((undefined4 *)this);
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
      while ((*pWVar4 != L'\0' && (iVar5 = FUN_10002e10((undefined4 *)this), iVar5 == 0))) {
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
        iVar5 = FUN_10003037(*pWVar2);
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



// Function: FUN_10003195 at 10003195

undefined4 FUN_10003195(LPCWSTR param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_u_AppID_1001e590;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar2);
    if (iVar1 == 0) {
      return 0;
    }
    ppuVar2 = ppuVar2 + 1;
  } while ((int)ppuVar2 < 0x1001e5c0);
  return 1;
}



// Function: FUN_100031c4 at 100031c4

bool FUN_100031c4(HKEY param_1)

{
  LSTATUS LVar1;
  DWORD local_8;
  
  local_8 = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_8,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  return LVar1 == 0 && local_8 != 0;
}



// Function: FUN_100031f9 at 100031f9

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_100031f9(void *this,short *param_1)

{
  int iVar1;
  undefined2 local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  if ((*param_1 == 0x3d) && (iVar1 = FUN_1000307f(this,param_1), -1 < iVar1)) {
    FUN_1000305d((undefined4 *)this);
    iVar1 = FUN_1000307f(this,local_2008);
    if (-1 < iVar1) {
      FUN_1000307f(this,param_1);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000325e at 1000325e

undefined4 FUN_1000325e(undefined1 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_1 = DAT_10026b44;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_1000327d at 1000327d

undefined4 __thiscall FUN_1000327d(void *this,int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    DAT_10026b4c = *param_3;
    DAT_10026b50 = param_3[1];
    DAT_10026b54 = param_3[2];
    DAT_10026b58 = param_3[3];
  }
  piVar2 = DAT_100272d4;
  if ((param_1 != (int *)0xffffffff) &&
     (*(int **)((int)this + 0x2c) = param_1, piVar2 = DAT_100272d4, param_1 != (int *)0x0)) {
    iVar1 = *param_1;
    while (DAT_100272d4 = piVar2, iVar1 != 0) {
      (*(code *)param_1[8])(1);
      param_1 = param_1 + 9;
      piVar2 = DAT_100272d4;
      iVar1 = *param_1;
    }
  }
  for (; piVar2 < DAT_100272d8; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(1);
    }
  }
  return 0;
}



// Function: FUN_100032de at 100032de

void __fastcall FUN_100032de(int param_1)

{
  long lVar1;
  
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (-1 < lVar1) {
    *(undefined1 *)(param_1 + 0x1c) = 1;
  }
  return;
}



// Function: FUN_100032f3 at 100032f3

void FUN_100032f3(int param_1)

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



// Function: FUN_1000335a at 1000335a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __fastcall FUN_1000335a(void *param_1)

{
  memset(param_1,0,0x18);
  *(undefined1 *)((int)param_1 + 0x18) = 0;
  return param_1;
}



// Function: FUN_10003388 at 10003388

void __fastcall FUN_10003388(undefined4 *param_1)

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



// Function: FUN_100033b5 at 100033b5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_100033b5(undefined4 *param_1)

{
  FUN_1000b41b((int)param_1);
  *param_1 = ATL::CComObject<class_CConfigServiceImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CConfigServiceImpl>::vftable;
  (**(code **)(*DAT_10026b48 + 4))();
  return param_1;
}



// Function: InlineIsEqualUnknown at 100033f5

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



// Function: FUN_10003423 at 10003423

undefined4 FUN_10003423(undefined4 param_1,undefined4 *param_2)

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



// Function: AtlInternalQueryInterface at 10003440

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
          if (pcVar1 == (code *)0x1) goto LAB_10003474;
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
LAB_10003474:
      piVar4 = (int *)(*(int *)(param_2 + 4) + (int)param_1);
      (**(code **)(*piVar4 + 4))(piVar4);
      *param_4 = piVar4;
      lVar2 = 0;
    }
  }
  return lVar2;
}



// Function: FUN_1000350a at 1000350a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000350a(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CConfigServiceImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CConfigServiceImpl>::vftable;
  param_1[2] = 0xc0000001;
  FUN_10007904((int)param_1);
  (**(code **)(*DAT_10026b48 + 8))();
  FUN_10007177((int)param_1);
  return;
}



// Function: FUN_10003554 at 10003554

void FUN_10003554(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: Release at 10003568

/* Library Function - Multiple Matches With Same Base Name
    public: virtual unsigned long __stdcall CEnumMediaTypes::Release(void)
    public: virtual unsigned long __stdcall CEnumPins::Release(void)
   
   Library: Visual Studio 2019 Release */

LONG Release(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 2);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x54))(1);
  }
  return LVar1;
}



// Function: FUN_10003595 at 10003595

undefined4 * __thiscall FUN_10003595(void *this,byte param_1)

{
  FUN_1000350a((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100035b4 at 100035b4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100035b4(int param_1)

{
  FUN_10007177(param_1);
  return;
}



// Function: FUN_100035d2 at 100035d2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_100035d2(LPCRITICAL_SECTION param_1)

{
  undefined1 *puVar1;
  undefined1 *extraout_EAX;
  
  puVar1 = &LAB_10018240;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
    puVar1 = extraout_EAX;
  }
  return puVar1;
}



// Function: FUN_100035fc at 100035fc

int __thiscall FUN_100035fc(void *this,undefined4 *param_1)

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



// Function: FUN_10003633 at 10003633

void __fastcall FUN_10003633(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_1000363d at 1000363d

void __thiscall FUN_1000363d(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)FUN_1000154f(0x8007000e);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: AtlMultiplyThrow<unsigned_int> at 10003662

/* Library Function - Single Match
    unsigned int __cdecl ATL::AtlMultiplyThrow<unsigned int>(unsigned int,unsigned int)
   
   Library: Visual Studio 2010 Release */

uint __cdecl ATL::AtlMultiplyThrow<unsigned_int>(uint param_1,uint param_2)

{
  long lVar1;
  uint local_8;
  
  lVar1 = AtlMultiply<unsigned_long>(&local_8,param_1,param_2);
  if (lVar1 < 0) {
    FUN_1000154f(lVar1);
  }
  return local_8;
}



// Function: FUN_10003687 at 10003687

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10003687(void *this,undefined4 param_1)

{
  FUN_1000b41b((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CConfigServiceImpl>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CConfigServiceImpl>::vftable;
  *(undefined4 *)((int)this + 8) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_100036c2 at 100036c2

void FUN_100036c2(int param_1)

{
  (**(code **)(**(int **)(param_1 + 8) + 4))(*(int **)(param_1 + 8));
  return;
}



// Function: FUN_100036d5 at 100036d5

void FUN_100036d5(int param_1)

{
  (**(code **)(**(int **)(param_1 + 8) + 8))(*(int **)(param_1 + 8));
  return;
}



// Function: FUN_100036e8 at 100036e8

void FUN_100036e8(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 8))(*(undefined4 **)(param_1 + 8),param_2,param_3);
  return;
}



// Function: FUN_10003700 at 10003700

void FUN_10003700(void)

{
  return;
}



// Function: FUN_10003701 at 10003701

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10003701(void *this,byte param_1)

{
  FUN_10007177((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_10003732 at 10003732

void FUN_10003732(int param_1)

{
  FUN_100036d5(param_1 + -4);
  return;
}



// Function: FUN_1000373c at 1000373c

void FUN_1000373c(int param_1)

{
  Release((int *)(param_1 + -4));
  return;
}



// Function: FUN_10003746 at 10003746

void FUN_10003746(int param_1)

{
  FUN_100036c2(param_1 + -4);
  return;
}



// Function: FUN_10003750 at 10003750

void FUN_10003750(int param_1)

{
  FUN_10003554(param_1 + -4);
  return;
}



// Function: FUN_1000375a at 1000375a

void FUN_1000375a(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100036e8(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10003764 at 10003764

int __fastcall FUN_10003764(int param_1)

{
  long lVar1;
  
  FUN_10002c9b(param_1 + 4);
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_10026b48 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 0x10));
  if (lVar1 < 0) {
    DAT_10026b38 = 1;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x24;
  }
  return param_1;
}



// Function: FUN_100037a5 at 100037a5

void __fastcall FUN_100037a5(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_100032f3((int)piVar1);
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



// Function: FUN_100037de at 100037de

void __fastcall FUN_100037de(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_100032f3((int)piVar1);
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



// Function: FUN_100037e3 at 100037e3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100037e3(int param_1)

{
  FUN_100037a5(param_1);
  return;
}



// Function: FUN_10003801 at 10003801

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10003801(void *this,LPCWSTR param_1)

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
      iVar1 = FUN_10003801(&local_224,local_214);
    } while (iVar1 == 0);
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_224);
  }
  else {
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_224);
  }
  FUN_1001739f();
  return;
}



// Function: FUN_100038e6 at 100038e6

undefined4 __fastcall FUN_100038e6(int *param_1)

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
LAB_1000392b:
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pcVar1 = (code *)swi(3);
        uVar3 = (*pcVar1)();
        return uVar3;
      }
      operator_delete__(*(void **)(*param_1 + iVar4 * 4));
      if (param_1[2] <= iVar4) goto LAB_1000392b;
      operator_delete__(*(void **)(param_1[1] + iVar4 * 4));
      iVar2 = param_1[2];
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  FUN_10003388(param_1);
  return 0;
}



// Function: FUN_1000393d at 1000393d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_1000393d(void *this,LPCWSTR param_1)

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
    uVar1 = FUN_10002e70(this,param_1,iVar2);
    local_8 = 0xffffffff;
    FUN_100016af(local_14);
  }
  return uVar1;
}



// Function: FUN_10003984 at 10003984

void FUN_10003984(int param_1)

{
  FUN_100038e6((int *)(param_1 + 4));
  return;
}



// Function: FUN_10003996 at 10003996

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10003996(HMODULE param_1,LPCWSTR param_2,undefined4 *param_3,undefined4 *param_4)

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
  local_8 = 0x100039a5;
  local_244 = param_2;
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined4 *)0x0)) goto LAB_10003b70;
  *param_3 = 0;
  *param_4 = 0;
  local_248 = 0;
  local_8 = 0;
  DVar2 = GetModuleFileNameW(param_1,local_23c,0x104);
  if (DVar2 == 0) {
    FUN_10002b69();
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
      if (((uVar1 < DVar2) || (uVar1 < uVar3)) || (0x10d < uVar1)) goto LAB_10003a03;
      FUN_10002b11(local_23c + DVar2,0x10e - DVar2,local_244);
    }
    iVar4 = Ordinal_161(local_23c,param_4);
    if (iVar4 < 0) {
      builtin_wcsncpy(local_20,L".tlb",5);
      iVar4 = (int)local_240 - (int)local_23c >> 1;
      if (iVar4 + 5U < 0x105) {
        eVar5 = wcscpy_s(local_240,0x10e - iVar4,local_20);
        ATL::AtlCrtErrorCheck(eVar5);
        iVar4 = Ordinal_161(local_23c,param_4);
        if (-1 < iVar4) goto LAB_10003b40;
      }
    }
    else {
LAB_10003b40:
      uVar6 = Ordinal_2(local_23c);
      *param_3 = uVar6;
    }
  }
LAB_10003a03:
  local_8 = 0xffffffff;
  FUN_100016af(&local_248);
LAB_10003b70:
  FUN_1001739f();
  return;
}



// Function: FUN_10003b78 at 10003b78

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003b78(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10003b9d at 10003b9d

void __fastcall FUN_10003b9d(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  piVar2 = DAT_100272d4;
  if (piVar1 != (int *)0x0) {
    for (; piVar2 = DAT_100272d4, *piVar1 != 0; piVar1 = piVar1 + 9) {
      piVar2 = (int *)piVar1[4];
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      piVar1[4] = 0;
      (*(code *)piVar1[8])(0);
    }
  }
  for (; piVar2 < DAT_100272d8; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(0);
    }
  }
  FUN_100037a5(param_1);
  return;
}



// Function: FUN_10003bef at 10003bef

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10003bef(void *this,wchar_t *param_1)

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
  local_8 = 0x10003bfb;
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
      local_18 = (uint *)FUN_100171c8(-(uint)(0xfffffffb < uVar8) | uVar8 + 4);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_18 == (uint *)0x0) {
        puVar6 = (uint *)0x0;
      }
      else {
        *local_18 = uVar2;
        puVar6 = local_18 + 1;
        _eh_vector_constructor_iterator_
                  (puVar6,0xc,uVar2,(_func_void_void_ptr *)&LAB_100034e1,
                   (_func_void_void_ptr *)&LAB_10003339);
      }
      local_8 = 0xffffffff;
      local_1c = puVar6;
      uVar7 = FUN_10003c9f();
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



// Function: Catch@10003c8f at 10003c8f

undefined * Catch_10003c8f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10003c99;
}



// Function: FUN_10003c9f at 10003c9f

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10003c9f(void)

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



// Function: FUN_10003d57 at 10003d57

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_10003d57(void *this,byte param_1)

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
    _eh_vector_destructor_iterator_(this,0xc,*piVar1,(_func_void_void_ptr *)&LAB_10003339);
    if ((param_1 & 1) != 0) {
      operator_delete__(piVar1);
    }
  }
  return piVar1;
}



// Function: FUN_10003db4 at 10003db4

void FUN_10003db4(int param_1)

{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0xc);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (*(void **)(param_1 + 0x14) != (void *)0x0) {
      FUN_10003d57(*(void **)(param_1 + 0x14),3);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_10003de7 at 10003de7

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10003de7(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x30);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_100033b5(puVar1);
    }
    iVar2 = FUN_10003e4b();
    return iVar2;
  }
  return -0x7fffbffd;
}



// Function: Catch@10003e3b at 10003e3b

undefined * Catch_10003e3b(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10003e45;
}



// Function: FUN_10003e4b at 10003e4b

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10003e4b(void)

{
  LONG *lpAddend;
  int unaff_EBX;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    lpAddend = unaff_ESI + 2;
    InterlockedIncrement(lpAddend);
    unaff_EBX = FUN_100032de((int)lpAddend);
    if (-1 < unaff_EBX) {
      unaff_EBX = 0;
    }
    InterlockedDecrement(lpAddend);
    if ((unaff_EBX == 0) && (unaff_EBX = (**(code **)*unaff_ESI)(), unaff_EBX == 0)) {
      return 0;
    }
    (**(code **)(*unaff_ESI + 0x54))(1);
  }
  return unaff_EBX;
}



// Function: FUN_10003e9c at 10003e9c

void __fastcall FUN_10003e9c(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_10003eac at 10003eac

void __fastcall FUN_10003eac(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FUN_10003633(param_1);
    return;
  }
  return;
}



// Function: QueryInterface at 10003eb9

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1001ea84,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10003ed3 at 10003ed3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10003ed3(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CConfigServiceImpl>::vftable;
  FUN_10003687((void *)((int)this + 0xc),param_1);
  (**(code **)(*DAT_10026b48 + 4))();
  return (undefined4 *)this;
}



// Function: FUN_10003f16 at 10003f16

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003f16(int param_1)

{
  FUN_100035d2((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FUN_10003f37 at 10003f37

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003f37(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CConfigServiceImpl>::vftable;
  param_1[1] = 0xc0000001;
  FUN_10007904((int)(param_1 + 3));
  (**(code **)(*DAT_10026b48 + 8))();
  FUN_10007177((int)(param_1 + 3));
  return;
}



// Function: FUN_10003f84 at 10003f84

void FUN_10003f84(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



// Function: Release at 10003f98

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



// Function: FUN_10003fc8 at 10003fc8

long FUN_10003fc8(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 3,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1001ea84,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_10004014 at 10004014

undefined4 * __thiscall FUN_10004014(void *this,byte param_1)

{
  FUN_10003f37((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10004033 at 10004033

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_10004033(void *this,int param_1,undefined4 *param_2,undefined4 *param_3)

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



// Function: FUN_10004087 at 10004087

void __fastcall FUN_10004087(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_1000409e at 1000409e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool __thiscall FUN_1000409e(void *this,undefined4 *param_1)

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
    (**(code **)**this)(*this,&PTR_1001eb84,&local_18);
    (**(code **)*param_1)(param_1,&PTR_1001eb84,local_14);
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



// Function: FUN_10004129 at 10004129

void FUN_10004129(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_10004133 at 10004133

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_10004133(undefined4 *param_1)

{
  FUN_10003764((int)param_1);
  *param_1 = ATL::CComModule::vftable;
  _DAT_10026b5c = param_1;
  return param_1;
}



// Function: FUN_10004168 at 10004168

void __fastcall FUN_10004168(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10004173 at 10004173

void __fastcall FUN_10004173(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_1000417e at 1000417e

HRESULT __thiscall FUN_1000417e(void *this,undefined4 *param_1)

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
       (HVar1 = CoCreateInstance((IID *)&DAT_1001feac,(LPUNKNOWN)0x0,1,(IID *)&DAT_1001ebc0,ppv),
       -1 < HVar1)) {
      *param_1 = *ppv;
                    /* WARNING: Load size is inaccurate */
      (**(code **)(**ppv + 4))(*ppv);
    }
  }
  return HVar1;
}



// Function: FUN_100041ca at 100041ca

undefined4 FUN_100041ca(void)

{
  return 0x80004005;
}



// Function: FUN_100041d2 at 100041d2

void FUN_100041d2(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",&PTR_1001e6f0);
  return;
}



// Function: FUN_100041ec at 100041ec

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100041ec(void *this,byte param_1)

{
  *(undefined ***)this = ATL::CComModule::vftable;
  FUN_100037a5((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10004223 at 10004223

undefined4 FUN_10004223(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_1000327d(&DAT_1002703c,(int *)&PTR_DAT_100260b0,param_1,(undefined4 *)&DAT_1001e7c4);
    DisableThreadLibraryCalls(param_1);
  }
  else if (param_2 == 0) {
    FUN_10003b9d(0x1002703c);
  }
  return 1;
}



// Function: FUN_10004265 at 10004265

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10004265(int *param_1)

{
  FUN_100038e6(param_1);
  FUN_10003388(param_1);
  return;
}



// Function: FUN_1000428f at 1000428f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000428f(undefined4 *param_1)

{
  *param_1 = ATL::CRegObject::vftable;
  FUN_100038e6(param_1 + 1);
  FUN_10004265(param_1 + 1);
  return;
}



// Function: FUN_100042c3 at 100042c3

undefined4 FUN_100042c3(void)

{
  return 0x80004001;
}



// Function: FUN_100042cb at 100042cb

undefined4 FUN_100042cb(void)

{
  return 1;
}



// Function: FUN_100042d1 at 100042d1

undefined4 FUN_100042d1(void)

{
  return 0;
}



// Function: FUN_100042d6 at 100042d6

undefined4 * __thiscall FUN_100042d6(void *this,byte param_1)

{
  FUN_1000428f((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100042f5 at 100042f5

undefined4 __fastcall FUN_100042f5(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_100035fc((void *)(param_1 + 4),(undefined4 *)&stack0x00000004);
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



// Function: FUN_10004336 at 10004336

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10004336(void *this,LPCWSTR param_1,int *param_2)

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
  local_8 = 0x10004342;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != (int *)0x0)) {
    *param_2 = 0;
    iVar3 = lstrlenW(param_1);
    FUN_10002e30(&local_70,iVar3 * 2);
    local_8 = 0;
    if (local_68 == (LPVOID)0x0) {
      local_8 = 0xffffffff;
      CoTaskMemFree((LPVOID)0x0);
    }
    else {
      *(LPCWSTR *)this = param_1;
      local_5d = '\0';
      local_5c = FUN_1000325e(&local_5d);
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
LAB_1000442b:
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x27) {
                if (local_55 == '\0') {
                  local_55 = '\x01';
                  goto LAB_1000449f;
                }
                iVar3 = FUN_10002e10((undefined4 *)this);
                if (iVar3 == 0) {
                    /* WARNING: Load size is inaccurate */
                  pWVar5 = CharNextW(*this);
                  *(LPWSTR *)this = pWVar5;
                  iVar3 = FUN_10002e70(&local_70,pWVar5,1);
                  if (iVar3 == 0) goto LAB_100044c5;
                  goto LAB_10004467;
                }
                local_55 = '\0';
              }
              else {
LAB_10004467:
                if (local_55 != '\0') goto LAB_1000449f;
              }
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x7b) {
                local_64 = local_64 + 1;
              }
              if (((**this == 0x7d) && (local_64 = local_64 + -1, local_64 == 0)) &&
                 (local_56 == '\x01')) {
                iVar3 = FUN_1000393d(&local_70,L"\r\n\t}\r\n}\r\n");
                if (iVar3 == 0) goto LAB_100044c5;
                local_56 = '\0';
              }
              goto LAB_1000449f;
            }
            pWVar5 = CharNextW(*this);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            iVar3 = FUN_1000393d(&local_70,L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses");
            if (iVar3 != 0) {
              local_56 = '\x01';
              goto LAB_1000442b;
            }
LAB_100044c5:
            local_5c = -0x7ff8fff2;
            goto LAB_100043a6;
          }
LAB_1000449f:
                    /* WARNING: Load size is inaccurate */
          pWVar6 = *this;
          if (*pWVar6 == L'%') {
            pWVar5 = CharNextW(pWVar6);
            *(LPWSTR *)this = pWVar5;
            if (*pWVar5 != L'%') {
              pWVar6 = FUN_1000300a(pWVar5,L'%');
              if (pWVar6 != (LPCWSTR)0x0) {
                    /* WARNING: Load size is inaccurate */
                _MaxCount = (int)pWVar6 - (int)*this >> 1;
                if (0x1f < (int)_MaxCount) {
                  local_5c = -0x7fffbffb;
                  goto LAB_100043a6;
                }
                eVar7 = wcsncpy_s(local_54,0x20,*this,_MaxCount);
                ATL::AtlCrtErrorCheck(eVar7);
                pWVar8 = (LPCWSTR)FUN_100042f5(*(int *)((int)this + 4));
                if (pWVar8 != (LPCWSTR)0x0) {
                  iVar3 = FUN_1000393d(&local_70,pWVar8);
                  if (iVar3 == 0) goto LAB_100044c5;
                    /* WARNING: Load size is inaccurate */
                  pWVar8 = *this;
                  while (pWVar8 != pWVar6) {
                    /* WARNING: Load size is inaccurate */
                    pWVar8 = CharNextW(*this);
                    *(LPCWSTR *)this = pWVar8;
                  }
                  goto LAB_10004538;
                }
              }
              local_5c = -0x7ffdfff7;
              goto LAB_100043a6;
            }
            iVar3 = FUN_10002e70(&local_70,pWVar5,1);
            if (iVar3 == 0) goto LAB_100044c5;
          }
          else {
            iVar3 = FUN_10002e70(&local_70,pWVar6,1);
            if (iVar3 == 0) {
              local_5c = -0x7ff8fff2;
              break;
            }
          }
LAB_10004538:
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
LAB_100043a6:
      local_8 = 0xffffffff;
      CoTaskMemFree(local_68);
    }
  }
  FUN_1001739f();
  return;
}



// Function: FUN_100045a3 at 100045a3

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_100045a3(GUID *param_1,int *param_2,int param_3)

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
      (iVar2 = _InlineIsEqualGUID((int *)param_1,(int *)&DAT_1001fe9c), iVar2 == 0)) &&
     (HVar3 = CoCreateInstance((IID *)&DAT_1001febc,(LPUNKNOWN)0x0,1,(IID *)&DAT_1001ecbc,&local_1a8
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
          goto LAB_1000482e;
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
      FUN_100016af(&local_1cc);
    }
  }
  local_8 = 0xffffffff;
  if (local_1a8 != (int *)0x0) {
    (**(code **)(*local_1a8 + 8))(local_1a8);
  }
LAB_1000482e:
  FUN_1001739f();
  return;
}



// Function: FUN_100048c1 at 100048c1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_100048c1(HMODULE param_1,LPCWSTR param_2)

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
  iVar1 = FUN_10003996(param_1,param_2,&local_18,local_14);
  if ((-1 < iVar1) && (iVar1 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],&param_1), -1 < iVar1)
     ) {
    param_2 = (LPCWSTR)((uint)param_2 & 0xffffff);
    iVar1 = FUN_1000325e((undefined1 *)((int)&param_2 + 3));
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



// Function: FUN_10004991 at 10004991

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10004991(HMODULE param_1,LPCWSTR param_2)

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
  iVar2 = FUN_10003996(param_1,param_2,&local_22c,&local_228);
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
    iVar2 = FUN_1000325e(&local_21d);
    if (iVar2 < 0) {
      local_8._0_1_ = 2;
      Ordinal_6(local_224);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_228 != (int *)0x0) {
        (**(code **)(*local_228 + 8))(local_228);
      }
      local_8 = 0xffffffff;
      Ordinal_6(local_22c);
      goto LAB_10004b53;
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
LAB_10004b53:
  FUN_1001739f();
  return;
}



// Function: FUN_10004b5b at 10004b5b

int FUN_10004b5b(int param_1,int param_2,void *param_3)

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
            (bVar3 = FUN_10002a4b(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          iVar7 = 1;
          iVar4 = (*(code *)puVar1[1])();
          if (iVar4 < 0) {
            return iVar4;
          }
          piVar5 = (int *)(*(code *)puVar1[7])(1);
          param_1 = FUN_100045a3((GUID *)*puVar1,piVar5,iVar7);
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
      param_1 = FUN_10004991(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_10004be1 at 10004be1

int FUN_10004be1(int param_1,int param_2,void *param_3)

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
            (bVar3 = FUN_10002a4b(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          iVar6 = 0;
          piVar4 = (int *)(*(code *)puVar1[7])();
          iVar6 = FUN_100045a3((GUID *)*puVar1,piVar4,iVar6);
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
      param_1 = FUN_100048c1(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_10004c68 at 10004c68

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_10004c68(int *param_1,int *param_2,undefined4 param_3,int *param_4)

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
              param_1 = (int *)(*(code *)puVar1[2])(puVar1[3],&PTR_1001eb84,piVar3);
            }
            LeaveCriticalSection(lpCriticalSection);
            if (*piVar3 != 0) goto LAB_10004d23;
          }
          else {
LAB_10004d23:
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



// Function: FUN_10004d53 at 10004d53

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10004d53(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 0x80070057;
  }
  operator_new(0xc);
  uVar1 = FUN_10004d98();
  return uVar1;
}



// Function: Catch@10004d88 at 10004d88

undefined * Catch_10004d88(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10004d92;
}



// Function: FUN_10004d98 at 10004d98

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10004d98(void)

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



// Function: FUN_10004df3 at 10004df3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10004df3(undefined4 *param_1)

{
  *param_1 = ATL::CComClassFactory::vftable;
  FUN_100035d2((LPCRITICAL_SECTION)(param_1 + 2));
  return;
}



// Function: FUN_10004e24 at 10004e24

undefined4 FUN_10004e24(int param_1,int param_2,_GUID *param_3,undefined4 *param_4)

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



// Function: FUN_10004e62 at 10004e62

undefined4 FUN_10004e62(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    (**(code **)(*DAT_10026b48 + 8))();
  }
  else {
    (**(code **)(*DAT_10026b48 + 4))();
  }
  return 0;
}



// Function: FUN_10004e81 at 10004e81

undefined4 * __thiscall FUN_10004e81(void *this,byte param_1)

{
  FUN_10004df3((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10004ea0 at 10004ea0

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10004ea0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int iVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x3c);
    if (this != (void *)0x0) {
      FUN_10003ed3(this,param_1);
    }
    iVar1 = FUN_10004f0e();
    return iVar1;
  }
  return -0x7fffbffd;
}



// Function: Catch@10004efe at 10004efe

undefined * Catch_10004efe(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10004f08;
}



// Function: FUN_10004f0e at 10004f0e

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10004f0e(void)

{
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_EDI = FUN_100032de((int)(unaff_ESI + 5));
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



// Function: FUN_10004f50 at 10004f50

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10004f50(undefined4 *param_1)

{
  param_1[1] = 0;
  FUN_1000335a(param_1 + 2);
  *param_1 = ATL::CComClassFactory::vftable;
  return param_1;
}



// Function: FUN_10004f8b at 10004f8b

undefined4 __thiscall FUN_10004f8b(void *this,undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  
                    /* WARNING: Load size is inaccurate */
  pvVar1 = _recalloc(*this,*(int *)((int)this + 8) + 1,4);
  if (pvVar1 != (void *)0x0) {
    *(void **)this = pvVar1;
    pvVar1 = _recalloc(*(void **)((int)this + 4),*(int *)((int)this + 8) + 1,4);
    if (pvVar1 != (void *)0x0) {
      *(void **)((int)this + 4) = pvVar1;
      FUN_10004033(this,*(int *)((int)this + 8),param_1,param_2);
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      return 1;
    }
  }
  return 0;
}



// Function: Allocate at 10004fe2

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
    FUN_1000363d(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 10005011

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
    FUN_1000363d(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 10005040

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
    FUN_1000363d(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_1000506f at 1000506f

IUnknown * __thiscall FUN_1000506f(void *this,undefined4 *param_1)

{
  bool bVar1;
  IUnknown *pIVar2;
  
  bVar1 = FUN_1000409e(this,(undefined4 *)*param_1);
  if (bVar1) {
                    /* WARNING: Load size is inaccurate */
    pIVar2 = *this;
  }
  else {
    pIVar2 = ATL::AtlComQIPtrAssign((IUnknown **)this,(IUnknown *)*param_1,(_GUID *)&DAT_1001ed38);
  }
  return pIVar2;
}



// Function: FUN_1000509c at 1000509c

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000509c(LPCWSTR param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != 0)) {
    iVar2 = lstrlenW(param_1);
    lVar1 = (ulonglong)(iVar2 * 2 + 2) * 2;
    FUN_100171c8(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    uVar3 = FUN_10005102();
    return uVar3;
  }
  return 0;
}



// Function: Catch@100050f6 at 100050f6

undefined * Catch_100050f6(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10005100;
}



// Function: FUN_10005102 at 10005102

void FUN_10005102(void)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  undefined4 uVar4;
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
  uVar4 = FUN_100171c8(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
  *(undefined4 *)(unaff_EBP + -0x20) = uVar4;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_10005153();
  return;
}



// Function: Catch@10005144 at 10005144

undefined * Catch_10005144(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return &DAT_10005151;
}



// Function: FUN_10005153 at 10005153

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_10005153(void)

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
    FUN_10002270(*(void **)(unaff_EBP + -0x14),*(rsize_t *)(unaff_EBP + -0x28),
                 *(void **)(unaff_EBP + 8),*(rsize_t *)(unaff_EBP + -0x28));
    FUN_10002270(pvVar1,*(rsize_t *)(unaff_EBP + -0x2c),*(void **)(unaff_EBP + 0xc),
                 *(rsize_t *)(unaff_EBP + -0x2c));
    iVar2 = FUN_10004f8b(*(void **)(unaff_EBP + -0x30),(undefined4 *)(unaff_EBP + -0x14),
                         (undefined4 *)(unaff_EBP + -0x20));
    if (iVar2 != 0) {
      *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
      *(void **)(unaff_EBP + -0x18) = unaff_ESI;
      goto LAB_100051af;
    }
  }
  *(undefined4 *)(unaff_EBP + -0x24) = 0x8007000e;
LAB_100051af:
  iVar2 = *(int *)(unaff_EBP + -0x24);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  operator_delete__(*(void **)(unaff_EBP + -0x18));
  *(void **)(unaff_EBP + -0x18) = unaff_ESI;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  operator_delete__(*(void **)(unaff_EBP + -0x1c));
  *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
  return (int)unaff_ESI <= iVar2;
}



// Function: FUN_100051e7 at 100051e7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_100051e7(undefined4 param_1,LPCWSTR param_2,int param_3)

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
    iVar1 = FUN_1000509c(param_2,param_3);
    iVar1 = (-(uint)(iVar1 != 0) & 0x7ff8fff2) + 0x8007000e;
    local_8 = 0xffffffff;
    FUN_100016af(local_14);
  }
  return iVar1;
}



// Function: FUN_10005242 at 10005242

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10005242(void *this,CRegKey *param_1,wchar_t *param_2,undefined2 *param_3)

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
  puStack_c = &LAB_100187a9;
  local_10 = ExceptionList;
  uStack_2144 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2144;
  ExceptionList = &local_10;
  local_2124 = param_1;
  local_2128 = param_2;
  local_2120 = (wchar_t *)0x0;
  local_18 = uStack_2144;
  iVar1 = FUN_1000307f(this,local_2018);
  if ((iVar1 < 0) || (iVar1 = FUN_10002efe(local_2018,(undefined2 *)&local_2120), iVar1 == 0))
  goto LAB_100055bb;
  FUN_1000305d((undefined4 *)this);
  iVar1 = FUN_1000307f(this,local_2018);
  if (iVar1 < 0) goto LAB_100055bb;
  uVar2 = (uint)local_2120 & 0xffff;
  if (uVar2 == 8) {
    uVar2 = ATL::CRegKey::SetStringValue(param_1,param_2,local_2018,1);
LAB_10005597:
    if (uVar2 != 0) {
      FUN_10002b7e(uVar2);
      goto LAB_100055bb;
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
        FUN_100054ca();
        return;
      }
      goto LAB_100055bb;
    }
    if (uVar2 == 0x13) {
      local_2124 = (CRegKey *)0x0;
      local_8 = 3;
      Ordinal_277(local_2018,0,0,&local_2128);
      local_2120 = local_2128;
      uVar2 = RegSetValueExW(*(HKEY *)param_1,param_2,0,4,(BYTE *)&local_2120,4);
      local_8 = 0xffffffff;
      FUN_100016af((int *)&local_2124);
      goto LAB_10005597;
    }
    if (uVar2 == 0x4008) {
      iVar1 = lstrlenW(local_2018);
      local_211c[0] = 0;
      local_8 = 1;
      Allocate(local_211c,iVar1 + 2);
      local_8 = 0;
      FUN_10005363();
      return;
    }
  }
  FUN_1000307f(this,param_3);
LAB_100055bb:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10005357 at 10005357

undefined * Catch_10005357(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10005361;
}



// Function: FUN_10005363 at 10005363

void FUN_10005363(void)

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
    pWVar2 = (WCHAR *)FUN_10002dc1(*(void **)(unaff_EBP - 0x2120),*(LPCWSTR *)(unaff_EBP - 0x2124),
                                   *(LPCWSTR *)(unaff_EBP - 0x2118));
    unaff_EDI = (WCHAR *)0x0;
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  if (*(int *)(unaff_EBP - 0x2118) != unaff_EBP - 0x2114) {
    FUN_10003633((undefined4 *)(unaff_EBP - 0x2118));
  }
  if (pWVar2 == unaff_EDI) {
    FUN_1000307f(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x212c));
  }
  else {
    FUN_10002b7e((uint)pWVar2);
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x100055d3;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@100054af at 100054af

undefined * Catch_100054af(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return &DAT_100054bc;
}



// Function: FUN_100054ca at 100054ca

void FUN_100054ca(void)

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
      FUN_10003633((undefined4 *)(unaff_EBP - 0x2118));
    }
  }
  else {
    memset(*(void **)(unaff_EBP - 0x2118),unaff_EDI,unaff_EBX);
    if ((int)unaff_EDI < *(int *)(unaff_EBP - 0x211c)) {
      do {
        pbVar1 = (byte *)((int)unaff_EDI / 2 + *(int *)(unaff_EBP - 0x2118));
        iVar2 = FUN_10002fa6(*(ushort *)((unaff_EBP - 0x2014) + unaff_EDI * 2));
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
      FUN_10003633((undefined4 *)(unaff_EBP - 0x2118));
    }
    if (uVar3 == unaff_EDI) {
      FUN_1000307f(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x212c));
    }
    else {
      FUN_10002b7e(uVar3);
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x100055d3;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_100055d7 at 100055d7

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_100055d7(void *this,LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

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
  puStack_c = &LAB_10018808;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2228 = param_2;
  local_2234 = (HKEY)0x0;
  local_2230 = 0;
  local_222c = 0;
  local_8 = 0;
  local_2220 = this;
LAB_1000563b:
  iVar3 = FUN_1000307f(local_2220,param_1);
  do {
    if (iVar3 < 0) {
LAB_1000564b:
      local_8 = 0xffffffff;
      ATL::CRegKey::Close((CRegKey *)&local_2234);
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
LAB_10005aa8:
    if (*param_1 == L'}') goto LAB_1000564b;
    local_2238 = 1;
    iVar3 = lstrcmpiW(param_1,L"Delete");
    local_2224 = (uint)(iVar3 == 0);
    iVar4 = lstrcmpiW(param_1,L"ForceRemove");
    if ((iVar4 == 0) || ((iVar3 == 0) != 0)) {
      iVar3 = FUN_1000307f(local_2220,param_1);
      if (iVar3 < 0) goto LAB_1000564b;
      if (param_3 == 0) goto LAB_1000578a;
      local_2244 = (HKEY)0x0;
      local_2240 = 0;
      local_223c = 0;
      local_8._0_1_ = 1;
      pWVar5 = FUN_1000300a(param_1,L'\\');
      if (pWVar5 == (LPCWSTR)0x0) {
        iVar3 = FUN_10003195(param_1);
        if (iVar3 != 0) {
          local_2244 = local_2228;
          local_2240 = 0;
          local_223c = 0;
          FUN_10003801(&local_2244,param_1);
          local_2244 = (HKEY)0x0;
          local_2240 = 0;
          local_223c = 0;
        }
        if (local_2224 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_2244);
          goto LAB_1000578a;
        }
        iVar3 = FUN_1000307f(local_2220,param_1);
        if ((-1 < iVar3) && (iVar3 = FUN_100031f9(local_2220,param_1), -1 < iVar3)) {
          local_8 = (uint)local_8._1_3_ << 8;
          pCVar8 = (CRegKey *)&local_2244;
          goto LAB_10005ba7;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_2244;
        goto LAB_10005c26;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2244);
      goto LAB_1000564b;
    }
LAB_1000578a:
    iVar3 = lstrcmpiW(param_1,L"NoRemove");
    if (iVar3 == 0) {
      local_2238 = 0;
      iVar3 = FUN_1000307f(local_2220,param_1);
      if (iVar3 < 0) goto LAB_1000564b;
    }
    iVar3 = lstrcmpiW(param_1,L"Val");
    if (iVar3 != 0) {
      pWVar5 = FUN_1000300a(param_1,L'\\');
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
          iVar3 = FUN_1000307f(local_2220,param_1);
          if (((-1 < iVar3) && (iVar3 = FUN_100031f9(local_2220,param_1), -1 < iVar3)) &&
             (((*param_1 != L'{' || (iVar3 = lstrlenW(param_1), iVar3 != 1)) ||
              (((iVar3 = FUN_100055d7(local_2220,param_1,local_2234,0,param_4), -1 < iVar3 ||
                (param_4 != 0)) && (iVar3 = FUN_1000307f(local_2220,param_1), -1 < iVar3))))))
          break;
        }
        else {
          iVar3 = Open(&local_2234,local_2228,param_1,0x2001f);
          if (((iVar3 != 0) && (iVar3 = Open(&local_2234,local_2228,param_1,0x20019), iVar3 != 0))
             && (uVar6 = Create(&local_2234,local_2228,param_1,(LPWSTR)0x0,0,0x2001f,
                                (LPSECURITY_ATTRIBUTES)0x0,(undefined4 *)0x0), uVar6 != 0))
          goto LAB_10005c45;
          iVar3 = FUN_1000307f(local_2220,param_1);
          if ((-1 < iVar3) &&
             ((*param_1 != L'=' ||
              (iVar3 = FUN_10005242(local_2220,(CRegKey *)&local_2234,(wchar_t *)0x0,param_1),
              -1 < iVar3)))) goto LAB_10005bac;
        }
      }
      goto LAB_1000564b;
    }
    iVar3 = FUN_1000307f(local_2220,local_221c);
    if (((iVar3 < 0) || (iVar3 = FUN_1000307f(local_2220,param_1), iVar3 < 0)) || (*param_1 != L'=')
       ) goto LAB_1000564b;
    if (param_3 != 0) {
      local_8._0_1_ = 2;
      local_225c = local_2228;
      local_2258 = 0;
      local_2254 = 0;
      iVar3 = FUN_10005242(local_2220,(CRegKey *)&local_225c,local_221c,param_1);
      local_225c = (HKEY)0x0;
      local_2258 = 0;
      local_2254 = 0;
      if (-1 < iVar3) {
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_225c;
        goto LAB_10005ba7;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      pCVar8 = (CRegKey *)&local_225c;
      goto LAB_10005c26;
    }
    if ((iVar1 == 0) && (local_2238 != 0)) {
      local_2268 = (HKEY)0x0;
      local_2264 = 0;
      local_2260 = 0;
      local_8._0_1_ = 3;
      uVar6 = Open(&local_2268,local_2228,(LPCWSTR)0x0,0x20006);
      if ((uVar6 != 0) ||
         ((uVar6 = RegDeleteValueW(local_2268,local_221c), uVar6 != 0 && (uVar6 != 2)))) {
        FUN_10002b7e(uVar6);
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_2268;
LAB_10005c26:
        ATL::CRegKey::Close(pCVar8);
        goto LAB_1000564b;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2268);
    }
    iVar3 = FUN_100031f9(local_2220,param_1);
  } while( true );
  if (local_2224 != 2) {
    if (local_2224 == 0) {
      if ((iVar1 != 0) && (bVar2 = FUN_100031c4(local_2234), CONCAT31(extraout_var,bVar2) != 0)) {
        iVar3 = FUN_10003195(local_21c);
        if ((iVar3 != 0) && (local_2238 != 0)) {
          FUN_10003801(&local_2234,local_21c);
        }
        goto LAB_10005aa8;
      }
      bVar2 = FUN_100031c4(local_2234);
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
            FUN_10002b7e(uVar6);
            local_8 = (uint)local_8._1_3_ << 8;
            pCVar8 = (CRegKey *)&local_2250;
            goto LAB_10005c26;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          pCVar8 = (CRegKey *)&local_2250;
LAB_10005ba7:
          ATL::CRegKey::Close(pCVar8);
LAB_10005bac:
          if (((param_3 != 0) && (*param_1 == L'{')) && (iVar3 = lstrlenW(param_1), iVar3 == 1)) {
            iVar3 = FUN_100055d7(local_2220,param_1,local_2234,param_3,0);
            if (-1 < iVar3) goto LAB_1000563b;
            goto LAB_1000564b;
          }
        }
        goto LAB_10005aa8;
      }
    }
    else {
      uVar6 = local_2224;
      if (iVar1 != 0) goto LAB_10005aa8;
    }
LAB_10005c45:
    FUN_10002b7e(uVar6);
    goto LAB_1000564b;
  }
  goto LAB_10005aa8;
}



// Function: FUN_10005c6e at 10005c6e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_10005c6e(void *this,int *param_1,undefined4 param_2,int *param_3)

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
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_100272dc);
          local_14 = (int *)0x0;
          if (*piVar2 == 0) {
            local_14 = (int *)(*(code *)puVar3[2])(puVar3[3],&PTR_1001eb84,piVar2);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_100272dc);
          if (*piVar2 != 0) goto LAB_10005d02;
        }
        else {
LAB_10005d02:
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
  piVar2 = FUN_10004c68((int *)&DAT_100272cc,param_1,param_2,param_3);
  return piVar2;
}



// Function: FUN_10005d3a at 10005d3a

void FUN_10005d3a(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_10003de7(0,param_2,param_3);
    return;
  }
  FUN_10004ea0(param_1,param_2,param_3);
  return;
}



// Function: FUN_10005d5a at 10005d5a

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10005d5a(void *this,undefined4 param_1)

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
  local_8 = 0x10005d69;
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) goto LAB_10005f9f;
  lpCriticalSection = (LPCRITICAL_SECTION)(DAT_10026b48 + 0x10);
  local_8 = 0;
  EnterCriticalSection(lpCriticalSection);
  local_220 = -0x7fffbffb;
  if (*(int *)((int)this + 0xc) == 0) {
    piVar1 = *(int **)((int)this + 4);
    local_230 = (int *)0x0;
    iVar2 = _InlineIsEqualGUID(&DAT_10026b4c,piVar1);
    if (((iVar2 == 0) || (*(short *)((int)this + 8) != -1)) || (*(short *)((int)this + 10) != -1)) {
      local_220 = Ordinal_162(piVar1,*(undefined2 *)((int)this + 8),*(undefined2 *)((int)this + 10),
                              param_1,&local_230);
    }
    else {
      DVar3 = GetModuleFileNameW(DAT_100272f8,local_21c,0x104);
      if ((DVar3 == 0) || (DVar3 == 0x104)) goto LAB_10005f69;
      local_224 = (int *)0x0;
      local_8._0_1_ = 1;
      local_220 = Ordinal_161(local_21c,&local_230);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_100016af((int *)&local_224);
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
        iVar2 = (**(code **)*local_228)(local_228,&DAT_1001eae4,&local_224);
        if (-1 < iVar2) {
          FUN_1000506f(&local_22c,&local_224);
        }
        *(int **)((int)this + 0xc) = local_22c;
        local_22c = (int *)0x0;
        if (DAT_10026b48 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = DAT_10026b48 + 4;
        }
        pcVar4 = FUN_10003db4;
        pvVar5 = this;
        FUN_10004d53(iVar2);
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
LAB_10005f69:
  if ((*(wchar_t **)((int)this + 0xc) != (wchar_t *)0x0) && (*(int *)((int)this + 0x14) == 0)) {
    local_220 = FUN_10003bef(this,*(wchar_t **)((int)this + 0xc));
  }
  local_8 = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
LAB_10005f9f:
  FUN_1001739f();
  return;
}



// Function: FUN_10005fa7 at 10005fa7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10005fa7(undefined4 *param_1)

{
  FUN_10004f50(param_1);
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  return param_1;
}



// Function: FUN_10005fd5 at 10005fd5

LONG FUN_10005fd5(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_10026b48 + 4))();
  }
  return LVar1;
}



// Function: FUN_10005fff at 10005fff

LONG FUN_10005fff(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (LVar1 == 1) {
    (**(code **)(*DAT_10026b48 + 8))();
  }
  return LVar1;
}



// Function: QueryInterface at 1000603e

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1001ed64,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10006058 at 10006058

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006058(undefined4 *param_1)

{
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  param_1[1] = 0xc0000001;
  FUN_10004df3(param_1);
  return;
}



// Function: FUN_10006087 at 10006087

undefined4 * __thiscall FUN_10006087(void *this,byte param_1)

{
  FUN_10006058((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100060a6 at 100060a6

void FUN_100060a6(int param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = FUN_10004b5b(0x100272cc,param_1,param_2);
  if ((-1 < iVar1) && (DAT_10026b3c != (code *)0x0)) {
    (*DAT_10026b3c)(DAT_100272f8);
  }
  return;
}



// Function: FUN_100060d4 at 100060d4

void FUN_100060d4(int param_1,void *param_2)

{
  int iVar1;
  
  if ((DAT_10026b40 != (code *)0x0) && (iVar1 = (*DAT_10026b40)(), iVar1 < 0)) {
    return;
  }
  FUN_10004be1(0x100272cc,param_1,param_2);
  return;
}



// Function: FUN_100060fa at 100060fa

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall
FUN_100060fa(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (param_1,true,0);
  return;
}



// Function: DllGetClassObject at 1000611c

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int *piVar1;
  
                    /* 0x611c  2  DllGetClassObject */
  piVar1 = FUN_10005c6e(&DAT_1002703c,(int *)rclsid,riid,(int *)ppv);
  return (HRESULT)piVar1;
}



// Function: FUN_1000612a at 1000612a

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_1000612a(void *this,LPCWSTR param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  HKEY pHVar4;
  short *local_200c;
  WCHAR local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  local_200c = (short *)0x0;
  iVar3 = FUN_10004336(this,param_1,(int *)&local_200c);
  if (iVar3 < 0) {
LAB_10006220:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(short **)this = local_200c;
  sVar1 = *local_200c;
joined_r0x10006175:
  if ((((sVar1 == 0) || (iVar3 = FUN_1000307f(this,local_2008), iVar3 < 0)) ||
      (pHVar4 = (HKEY)FUN_10002fdc(local_2008), pHVar4 == (HKEY)0x0)) ||
     ((iVar3 = FUN_1000307f(this,local_2008), iVar3 < 0 || (local_2008[0] != L'{'))))
  goto LAB_10006212;
  if (param_2 == 0) {
    iVar3 = FUN_100055d7(this,local_2008,pHVar4,0,0);
    if (iVar3 < 0) goto LAB_10006212;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar2 = *this;
    iVar3 = FUN_100055d7(this,local_2008,pHVar4,param_2,0);
    if (iVar3 < 0) {
      *(undefined4 *)this = uVar2;
      FUN_100055d7(this,local_2008,pHVar4,0,0);
LAB_10006212:
      CoTaskMemFree(local_200c);
      goto LAB_10006220;
    }
  }
  FUN_1000305d((undefined4 *)this);
                    /* WARNING: Load size is inaccurate */
  sVar1 = **this;
  goto joined_r0x10006175;
}



// Function: Catch@100062bf at 100062bf

undefined1 * Catch_100062bf(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_100062c9;
}



// Function: FUN_10006311 at 10006311

int __thiscall FUN_10006311(void *this,int param_1,void *param_2)

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
         (bVar1 = FUN_10002a4b(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar6 = 1;
        iVar5 = (*(code *)piVar4[1])();
        if (iVar5 < 0) {
          return iVar5;
        }
        piVar3 = (int *)(*(code *)piVar4[7])(1);
        iVar5 = FUN_100045a3((GUID *)*piVar4,piVar3,iVar6);
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
  iVar5 = FUN_100060a6(param_1,param_2);
  return iVar5;
}



// Function: FUN_10006380 at 10006380

int __thiscall FUN_10006380(void *this,int param_1,void *param_2)

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
         (bVar1 = FUN_10002a4b(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar5 = 0;
        piVar3 = (int *)(*(code *)piVar4[7])();
        iVar5 = FUN_100045a3((GUID *)*piVar4,piVar3,iVar5);
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
  iVar5 = FUN_100060d4(param_1,param_2);
  return iVar5;
}



// Function: FUN_100063ef at 100063ef

undefined4 __thiscall FUN_100063ef(void *this,undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = 0;
    if (*(int *)((int)this + 0xc) == 0) {
      uVar1 = FUN_10005d5a(this,param_1);
    }
    *param_2 = *(undefined4 *)((int)this + 0xc);
    if (*(int *)((int)this + 0xc) != 0) {
      (**(code **)(**(int **)((int)this + 0xc) + 4))(*(int **)((int)this + 0xc));
      uVar1 = 0;
    }
  }
  return uVar1;
}



// Function: FUN_1000642f at 1000642f

undefined4 __thiscall
FUN_1000642f(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    uVar1 = FUN_10005d5a(this,param_4);
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



// Function: FUN_100064d0 at 100064d0

void __thiscall
FUN_100064d0(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    FUN_10005d5a(this,param_4);
  }
  if (*(int *)((int)this + 0xc) != 0) {
    (**(code **)(**(int **)((int)this + 0xc) + 0x2c))
              (*(int **)((int)this + 0xc),param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: DllRegisterServer at 10006513

void DllRegisterServer(void)

{
                    /* 0x6513  3  DllRegisterServer */
  FUN_10006311(&DAT_1002703c,1,(void *)0x0);
  return;
}



// Function: DllUnregisterServer at 10006522

void DllUnregisterServer(void)

{
                    /* 0x6522  4  DllUnregisterServer */
  FUN_10006380(&DAT_1002703c,1,(void *)0x0);
  return;
}



// Function: FUN_10006531 at 10006531

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10006531(LPCWSTR param_1,LPCWSTR param_2,LPCWSTR param_3)

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
    FUN_10002b69();
  }
  else {
    hResInfo = FindResourceW(local_420,param_2,param_3);
    if ((hResInfo == (HRSRC)0x0) ||
       (local_424 = LoadResource(local_420,hResInfo), local_424 == (HGLOBAL)0x0)) {
      FUN_10002b69();
    }
    else {
      local_428 = SizeofResource(local_420,hResInfo);
      if (local_428 <= local_428 + 1) {
        local_8 = CONCAT31(local_8._1_3_,2);
        Allocate(&local_41c,local_428 + 1);
        local_8 = 1;
        FUN_1000660b();
        return;
      }
    }
    FreeLibrary(local_420);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_41c != auStack_418) {
    FUN_10003633(&local_41c);
  }
  local_8 = 0xffffffff;
  FUN_100016af(&local_42c);
  FUN_100173ae();
  return;
}



// Function: Catch@100065f6 at 100065f6

undefined * Catch_100065f6(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10006603;
}



// Function: FUN_1000660b at 1000660b

void FUN_1000660b(void)

{
  DWORD DVar1;
  DWORD unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  if (*(DWORD *)(unaff_EBP + -0x418) != unaff_EBX) {
    DVar1 = MultiByteToWideChar(3,unaff_EBX,*(LPCSTR *)(unaff_EBP + -0x420),unaff_ESI,
                                *(LPWSTR *)(unaff_EBP + -0x418),unaff_ESI);
    if (DVar1 == unaff_EBX) {
      FUN_10002b69();
    }
    else {
      *(undefined2 *)(*(int *)(unaff_EBP + -0x418) + DVar1 * 2) = 0;
      FUN_1000612a((void *)(unaff_EBP + -0x430),*(LPCWSTR *)(unaff_EBP + -0x418),
                   *(int *)(unaff_EBP + 0x14));
    }
  }
  FreeLibrary(*(HMODULE *)(unaff_EBP + -0x41c));
  *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
  if (*(int *)(unaff_EBP + -0x418) != unaff_EBP + -0x414) {
    FUN_10003633((undefined4 *)(unaff_EBP + -0x418));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_100016af((int *)(unaff_EBP + -0x428));
  FUN_100173ae();
  return;
}



// Function: FUN_10006695 at 10006695

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10006695(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_10006531(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_100016af(local_14);
  return uVar1;
}



// Function: FUN_100066d6 at 100066d6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100066d6(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

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
    FUN_100016af(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_10006531(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_100016af(local_14);
  }
  return uVar1;
}



// Function: FUN_10006732 at 10006732

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10006732(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_10006531(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_100016af(local_14);
  return uVar1;
}



// Function: FUN_10006772 at 10006772

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10006772(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

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
    FUN_100016af(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_10006531(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_100016af(local_14);
  }
  return uVar1;
}



// Function: FUN_100067cd at 100067cd

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_100067cd(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

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
      FUN_100051e7(&local_a60,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a60);
  pHVar1 = DAT_100272f8;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_100272f8,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_10002b69();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_100016af((int *)&local_a48);
        goto LAB_1000684f;
      }
      FUN_10002c4d(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_10002ae4(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_100016af((int *)&local_a48);
          goto LAB_1000684f;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_100051e7(&local_a60,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_100051e7(&local_a60,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_10006772(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
        else {
          FUN_100066d6(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_100016af((int *)&local_a48);
  }
LAB_1000684f:
  local_8 = 0xffffffff;
  FUN_1000428f(&local_a60);
  FUN_1001739f();
  return;
}



// Function: FUN_100069d0 at 100069d0

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_100069d0(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

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
      FUN_100051e7(&local_a5c,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a5c);
  pHVar1 = DAT_100272f8;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_100272f8,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_10002b69();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_100016af((int *)&local_a48);
        goto LAB_10006a49;
      }
      FUN_10002c4d(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_10002ae4(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_100016af((int *)&local_a48);
          goto LAB_10006a49;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_100051e7(&local_a5c,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_100051e7(&local_a5c,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_10006732(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
        else {
          FUN_10006695(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_100016af((int *)&local_a48);
  }
LAB_10006a49:
  local_8 = 0xffffffff;
  FUN_1000428f(&local_a5c);
  FUN_1001739f();
  return;
}



// Function: FUN_10006bc7 at 10006bc7

undefined4 FUN_10006bc7(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_100063ef(&PTR_DAT_10026714,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10006beb at 10006beb

void FUN_10006beb(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_1000642f(&PTR_DAT_10026714,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10006c0b at 10006c0b

void FUN_10006c0b(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_100064d0(&PTR_DAT_10026714,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10006c19 at 10006c19

void FUN_10006c19(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

{
  FUN_100067cd(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10006c22 at 10006c22

void FUN_10006c22(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

{
  FUN_100069d0(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10006c2b at 10006c2b

void FUN_10006c2b(int param_1)

{
  FUN_100069d0((int *)&DAT_1002703c,0x65,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_10006c43 at 10006c43

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
FUN_10006c43(void *this,char *param_1)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this,
             param_1);
  return (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this;
}



// Function: FUN_10006c69 at 10006c69

void FUN_10006c69(void *param_1,void *param_2,size_t param_3)

{
  memcmp(param_1,param_2,param_3);
  return;
}



// Function: FUN_10006c72 at 10006c72

void __cdecl FUN_10006c72(int param_1,short *param_2)

{
  int iVar1;
  
  iVar1 = Ordinal_77(param_1,param_2);
  if ((((-1 < iVar1) && (param_2 != (short *)0x0)) && (*param_2 == 0xd)) &&
     (((param_1 != 0 && ((*(ushort *)(param_1 + 2) & 0x40) != 0)) &&
      ((*(ushort *)(param_1 + 2) & 0x400) != 0)))) {
    *param_2 = 9;
  }
  return;
}



// Function: FUN_10006cb2 at 10006cb2

void __fastcall FUN_10006cb2(int *param_1)

{
  undefined4 *puVar1;
  
  if (*param_1 == 0) {
    puVar1 = (undefined4 *)operator_new(4);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = 1;
    }
    *param_1 = (int)puVar1;
  }
  *(int *)*param_1 = *(int *)*param_1 + 1;
  return;
}



// Function: FUN_10006cdb at 10006cdb

undefined4 __fastcall FUN_10006cdb(undefined4 *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + -1;
    if (*piVar1 != 0) {
      return *(undefined4 *)*param_1;
    }
    operator_delete((void *)*param_1);
    *param_1 = 0;
  }
  return 0;
}



// Function: FUN_10006cfd at 10006cfd

void __fastcall FUN_10006cfd(int *param_1)

{
  int iVar1;
  
  if (*param_1 != 0) {
    iVar1 = FUN_10006cdb(param_1 + 1);
    if (iVar1 == 0) {
      RegCloseKey((HKEY)*param_1);
    }
  }
  *param_1 = 0;
  return;
}



// Function: FUN_10006d1e at 10006d1e

int * __thiscall FUN_10006d1e(void *this,int *param_1)

{
  *(int *)this = *param_1;
  *(undefined4 *)((int)this + 4) = 0;
                    /* WARNING: Load size is inaccurate */
  if (*this != 0) {
    FUN_10006cb2(param_1 + 1);
  }
  *(int *)((int)this + 4) = param_1[1];
  return (int *)this;
}



// Function: FUN_10006d4b at 10006d4b

void __fastcall FUN_10006d4b(int *param_1)

{
  int iVar1;
  
  if (*param_1 != 0) {
    iVar1 = FUN_10006cdb(param_1 + 1);
    if (iVar1 == 0) {
      RegCloseKey((HKEY)*param_1);
    }
  }
  *param_1 = 0;
  return;
}



// Function: FUN_10006d50 at 10006d50

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006d50(int *param_1)

{
  FUN_10006cfd(param_1);
  return;
}



// Function: FUN_10006d6e at 10006d6e

int FUN_10006d6e(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 1;
  uVar2 = 0;
  do {
    if (3 < uVar2) {
      return iVar3;
    }
    iVar1 = _InlineIsEqualGUID(*(int **)((int)&PTR_DAT_10026918 + uVar2),param_2);
    if (iVar1 != 0) {
      iVar3 = 0;
    }
    uVar2 = uVar2 + 4;
  } while (iVar3 != 0);
  return 0;
}



// Function: FUN_10006da2 at 10006da2

undefined4 __thiscall FUN_10006da2(void *this,int param_1)

{
  int iVar1;
  undefined4 local_8;
  
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  iVar1 = Ordinal_19(*this,param_1 + 1,&local_8);
  if (iVar1 < 0) {
    FUN_1000154f(iVar1);
  }
  return local_8;
}



// Function: FUN_10006dcc at 10006dcc

undefined4 __thiscall FUN_10006dcc(void *this,int param_1)

{
  int iVar1;
  undefined4 local_8;
  
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  iVar1 = Ordinal_20(*this,param_1 + 1,&local_8);
  if (iVar1 < 0) {
    FUN_1000154f(iVar1);
  }
  return local_8;
}



// Function: FUN_10006df6 at 10006df6

int __thiscall FUN_10006df6(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  void *local_8;
  
  iVar2 = param_1 + 1;
                    /* WARNING: Load size is inaccurate */
  local_8 = this;
  iVar1 = Ordinal_20(*this,iVar2,&local_8);
  if (-1 < iVar1) goto LAB_10006e19;
  do {
    FUN_1000154f(iVar1);
LAB_10006e19:
                    /* WARNING: Load size is inaccurate */
    iVar1 = *this;
    this = &param_1;
    iVar1 = Ordinal_19(iVar1,iVar2);
  } while (iVar1 < 0);
  return (param_1 - (int)local_8) + 1;
}



// Function: FUN_10006e37 at 10006e37

int __thiscall FUN_10006e37(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  void *extraout_ECX;
  void *this_00;
  undefined4 uVar3;
  
                    /* WARNING: Load size is inaccurate */
  this_00 = this;
  if (*this != 0) goto LAB_10006e4d;
  uVar3 = 0x80004005;
  do {
    FUN_1000154f(uVar3);
    this_00 = extraout_ECX;
LAB_10006e4d:
    iVar1 = FUN_10006dcc(this_00,0);
    if (iVar1 <= param_1) {
      iVar2 = FUN_10006da2(this,0);
      if (param_1 <= iVar2) {
                    /* WARNING: Load size is inaccurate */
        return (param_1 - iVar1) * 0x10 + *(int *)(*this + 0xc);
      }
    }
    uVar3 = 0x80070057;
  } while( true );
}



// Function: FUN_10006e83 at 10006e83

void __thiscall FUN_10006e83(void *this,LPCOLESTR param_1,LPUNKNOWN param_2,DWORD param_3)

{
  HRESULT HVar1;
  CLSID local_18;
  uint local_8;
  
  local_8 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  HVar1 = CLSIDFromProgID(param_1,&local_18);
  if (-1 < HVar1) {
    CoCreateInstance(&local_18,param_2,param_3,(IID *)&DAT_1001eef8,(LPVOID *)this);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10006ed0 at 10006ed0

int __thiscall FUN_10006ed0(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  void *extraout_ECX;
  void *this_00;
  undefined4 uVar3;
  
                    /* WARNING: Load size is inaccurate */
  this_00 = this;
  if (*this != 0) goto LAB_10006ee7;
  uVar3 = 0x80004005;
  do {
    FUN_1000154f(uVar3);
    this_00 = extraout_ECX;
LAB_10006ee7:
    iVar1 = FUN_10006dcc(this_00,0);
    if (iVar1 <= param_1) {
      iVar2 = FUN_10006da2(this,0);
      if (param_1 <= iVar2) {
                    /* WARNING: Load size is inaccurate */
        return *(int *)(*this + 0xc) + (param_1 - iVar1) * 4;
      }
    }
    uVar3 = 0x80070057;
  } while( true );
}



// Function: FUN_10006f1d at 10006f1d

undefined2 * __thiscall FUN_10006f1d(void *this,CComBSTR *param_1)

{
  int iVar1;
  wchar_t *pwVar2;
  
  iVar1 = Ordinal_9(this);
  if (-1 < iVar1) goto LAB_10006f35;
  while( true ) {
    FUN_1000154f(iVar1);
LAB_10006f35:
    *(undefined2 *)this = 8;
    pwVar2 = ATL::CComBSTR::Copy(param_1);
    *(wchar_t **)((int)this + 8) = pwVar2;
    if ((pwVar2 != (wchar_t *)0x0) || (*(int *)param_1 == 0)) break;
    *(undefined2 *)this = 10;
    iVar1 = -0x7ff8fff2;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
  }
  return (undefined2 *)this;
}



// Function: FUN_10006f68 at 10006f68

void * __thiscall FUN_10006f68(void *this,char *param_1,void *param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  size_t _MaxCount;
  
  if ((param_3 != 0) || (*(void **)((int)this + 0x10) < param_2)) {
    if ((param_2 < *(void **)((int)this + 0x10)) &&
       (uVar4 = (int)*(void **)((int)this + 0x10) - (int)param_2, param_3 <= uVar4)) {
      _MaxCount = uVar4 + (1 - param_3);
      pvVar3 = this;
      if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        pvVar3 = *this;
      }
      param_2 = (void *)((int)param_2 + (int)pvVar3);
      cVar1 = *param_1;
      while (pvVar3 = memchr(param_2,(int)cVar1,_MaxCount), pvVar3 != (void *)0x0) {
        iVar2 = memcmp(pvVar3,param_1,param_3);
        if (iVar2 == 0) {
          if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
            this = *this;
          }
          return (void *)((int)pvVar3 - (int)this);
        }
        _MaxCount = (int)param_2 + ((_MaxCount - 1) - (int)pvVar3);
        cVar1 = *param_1;
        param_2 = (void *)((int)pvVar3 + 1);
      }
    }
    param_2 = (void *)0xffffffff;
  }
  return param_2;
}



// Function: FUN_10007007 at 10007007

uint __thiscall FUN_10007007(void *this,char *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  char *pcVar4;
  char *_Buf1;
  
  if (param_3 == 0) {
    if (*(uint *)((int)this + 0x10) <= param_2) {
      param_2 = *(uint *)((int)this + 0x10);
    }
  }
  else {
    if (param_3 <= *(uint *)((int)this + 0x10)) {
      uVar1 = *(uint *)((int)this + 0x10) - param_3;
      if (uVar1 <= param_2) {
        param_2 = uVar1;
      }
      pvVar2 = this;
      if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        pvVar2 = *this;
      }
      _Buf1 = (char *)((int)pvVar2 + param_2);
      while( true ) {
        if ((*_Buf1 == *param_1) && (iVar3 = memcmp(_Buf1,param_1,param_3), iVar3 == 0)) {
          if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
            this = *this;
          }
          return (int)_Buf1 - (int)this;
        }
        pcVar4 = (char *)this;
        if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
          pcVar4 = *this;
        }
        if (_Buf1 == pcVar4) break;
        _Buf1 = _Buf1 + -1;
      }
    }
    param_2 = 0xffffffff;
  }
  return param_2;
}



// Function: FUN_1000708b at 1000708b

undefined4 __thiscall FUN_1000708b(void *this,int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if ((param_1 == 0) || (param_2 == 0)) {
      uVar1 = 0x80070057;
    }
    else {
      iVar2 = Ordinal_15(0xc,param_2,param_1);
      *(int *)this = iVar2;
      if (iVar2 == 0) {
        uVar1 = 0x8007000e;
      }
      else {
        uVar1 = Ordinal_21(iVar2);
      }
    }
  }
  else {
    uVar1 = 0x80004005;
  }
  return uVar1;
}



// Function: FUN_100070d7 at 100070d7

int __fastcall FUN_100070d7(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (*param_1 != 0) {
    iVar1 = Ordinal_22(*param_1);
    if (-1 < iVar1) {
      iVar1 = Ordinal_16(*param_1);
      if (-1 < iVar1) {
        *param_1 = 0;
      }
    }
  }
  return iVar1;
}



// Function: FUN_100070fe at 100070fe

void __thiscall FUN_100070fe(void *this,LPDWORD param_1,LPBYTE param_2,LPDWORD param_3)

{
  LPCWSTR lpValueName;
  
  lpValueName = (LPCWSTR)((int)this + 8);
  if (7 < *(uint *)((int)this + 0x1c)) {
    lpValueName = *(LPCWSTR *)lpValueName;
  }
                    /* WARNING: Load size is inaccurate */
  RegQueryValueExW(*this,lpValueName,(LPDWORD)0x0,param_1,param_2,param_3);
  return;
}



// Function: FUN_10007125 at 10007125

bool __thiscall FUN_10007125(void *this,undefined4 *param_1)

{
  char *_Str2;
  int iVar1;
  
  if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    this = *this;
  }
  _Str2 = (char *)FUN_1000b4e0(param_1);
  iVar1 = strcmp((char *)this,_Str2);
  return (bool)('\x01' - (iVar1 != 0));
}



// Function: FUN_10007150 at 10007150

void __thiscall FUN_10007150(void *this,LPCWSTR param_1,REGSAM param_2,PHKEY param_3)

{
  *param_3 = (HKEY)0x0;
  if (7 < *(uint *)(param_1 + 10)) {
    param_1 = *(LPCWSTR *)param_1;
  }
                    /* WARNING: Load size is inaccurate */
  RegOpenKeyExW(*this,param_1,0,param_2,param_3);
  return;
}



// Function: FUN_10007177 at 10007177

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10007177(int param_1)

{
  FUN_100035d2((LPCRITICAL_SECTION)(param_1 + 0xc));
  return;
}



// Function: FUN_100071a2 at 100071a2

void __thiscall FUN_100071a2(void *this,char *param_1,void *param_2)

{
  size_t sVar1;
  
  sVar1 = strlen(param_1);
  FUN_10006f68(this,param_1,param_2,sVar1);
  return;
}



// Function: FUN_100071c4 at 100071c4

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_100071c4(IID *param_1,WCHAR *param_2,int param_3,int param_4,undefined4 param_5,int param_6
                 ,HINSTANCE param_7)

{
  int iVar1;
  errno_t eVar2;
  int local_828;
  int local_824;
  int *local_820;
  LPOLESTR local_81c;
  int *local_818;
  WCHAR local_814 [1030];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x81c;
  local_824 = param_4;
  local_828 = 0;
  local_8 = 0;
  local_814[0] = L'\0';
  if (((uint)param_2 & 0xffff0000) == 0) {
    iVar1 = LoadStringW(param_7,(uint)param_2 & 0xffff,local_814,0x400);
    if (iVar1 == 0) {
      eVar2 = wcscpy_s(local_814,0x400,L"Unknown Error");
      ATL::AtlCrtErrorCheck(eVar2);
    }
    param_2 = local_814;
  }
  local_818 = (int *)0x0;
  local_8._0_1_ = 2;
  iVar1 = Ordinal_202(&local_818);
  if (-1 < iVar1) {
    local_820 = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,4);
    (**(code **)(*local_818 + 0xc))(local_818,param_5);
    ProgIDFromCLSID(param_1,&local_81c);
    if (local_81c != (LPOLESTR)0x0) {
      (**(code **)(*local_818 + 0x10))(local_818,local_81c);
    }
    if ((param_3 != 0) && (local_824 != 0)) {
      (**(code **)(*local_818 + 0x1c))(local_818,param_3);
      (**(code **)(*local_818 + 0x18))(local_818,local_824);
    }
    CoTaskMemFree(local_81c);
    (**(code **)(*local_818 + 0x14))(local_818,param_2);
    iVar1 = (**(code **)*local_818)(local_818,&DAT_1001ef08,&local_820);
    if (-1 < iVar1) {
      Ordinal_201(0,local_820);
    }
    local_8._0_1_ = 2;
    if (local_820 != (int *)0x0) {
      (**(code **)(*local_820 + 8))(local_820);
    }
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_818 != (int *)0x0) {
    (**(code **)(*local_818 + 8))(local_818);
  }
  local_8 = 0xffffffff;
  FUN_100016af(&local_828);
  FUN_1001739f();
  return;
}



// Function: FUN_10007378 at 10007378

int __fastcall FUN_10007378(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (*param_1 != 0) {
    iVar1 = Ordinal_22(*param_1);
    if (-1 < iVar1) {
      iVar1 = Ordinal_16(*param_1);
      if (-1 < iVar1) {
        *param_1 = 0;
      }
    }
  }
  return iVar1;
}



// Function: FUN_1000737d at 1000737d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_1000737d(void *this,undefined4 *param_1,LPCWSTR param_2,REGSAM param_3)

{
  HKEY local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x10007389;
  local_14[0] = (HKEY)0x0;
  FUN_10007150(this,param_2,param_3,local_14);
  *param_1 = local_14[0];
  param_1[1] = 0;
  return;
}



// Function: FUN_100073bf at 100073bf

bool __fastcall FUN_100073bf(undefined4 *param_1)

{
  LPCWSTR lpValueName;
  LSTATUS LVar1;
  
  lpValueName = (LPCWSTR)(param_1 + 2);
  if (7 < (uint)param_1[7]) {
    lpValueName = *(LPCWSTR *)lpValueName;
  }
  LVar1 = RegQueryValueExW((HKEY)*param_1,lpValueName,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)0x0,
                           (LPDWORD)0x0);
  return (bool)('\x01' - (LVar1 != 0));
}



// Function: FUN_100073e0 at 100073e0

void __thiscall FUN_100073e0(void *this,int param_1)

{
  int iVar1;
  void *local_8;
  
  local_8 = this;
  if (param_1 != 0) goto LAB_100073f7;
  do {
    iVar1 = -0x7ff8ffa9;
    while( true ) {
      do {
        FUN_1000154f(iVar1);
LAB_100073f7:
        iVar1 = FUN_10006c72(param_1,(short *)&local_8);
      } while (iVar1 < 0);
      if ((short)local_8 != 8) break;
      iVar1 = FUN_100070d7((int *)this);
      if ((-1 < iVar1) && (iVar1 = Ordinal_27(param_1,this), -1 < iVar1)) {
                    /* WARNING: Load size is inaccurate */
        if (*this != 0) {
          Ordinal_21(*this);
        }
        return;
      }
    }
  } while( true );
}



// Function: FUN_1000743e at 1000743e

void __thiscall FUN_1000743e(void *this,int param_1)

{
  int iVar1;
  void *local_8;
  
  local_8 = this;
  if (param_1 != 0) goto LAB_10007455;
  do {
    iVar1 = -0x7ff8ffa9;
    while( true ) {
      do {
        FUN_1000154f(iVar1);
LAB_10007455:
        iVar1 = FUN_10006c72(param_1,(short *)&local_8);
      } while (iVar1 < 0);
      if ((short)local_8 != 0xc) break;
      iVar1 = FUN_100070d7((int *)this);
      if ((-1 < iVar1) && (iVar1 = Ordinal_27(param_1,this), -1 < iVar1)) {
                    /* WARNING: Load size is inaccurate */
        if (*this != 0) {
          Ordinal_21(*this);
        }
        return;
      }
    }
  } while( true );
}



// Function: FUN_1000749c at 1000749c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000749c(int *param_1)

{
  FID_conflict__Tidy(param_1 + 2,'\x01',0);
  FUN_10006cfd(param_1);
  return;
}



// Function: FUN_100074ce at 100074ce

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100074ce(int param_1)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (param_1 + 8),true,0);
  return;
}



// Function: FUN_100074fa at 100074fa

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100074fa(undefined1 *param_1)

{
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  *(undefined4 *)(param_1 + 0x34) = 0xf;
  *(undefined4 *)(param_1 + 0x30) = 0;
  param_1[0x20] = 0;
  *(undefined4 *)(param_1 + 0x50) = 0xf;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  param_1[0x3c] = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0xf;
  *(undefined4 *)(param_1 + 0x68) = 0;
  param_1[0x58] = 0;
  return;
}



// Function: FUN_1000755b at 1000755b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall
FUN_1000755b(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (param_1 + 0x58,true,0);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (param_1 + 0x3c,true,0);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (param_1 + 0x20,true,0);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (param_1,true,0);
  return;
}



// Function: FUN_100075c5 at 100075c5

undefined4 * __thiscall FUN_100075c5(void *this,int param_1)

{
  int iVar1;
  
  *(undefined4 *)this = 0;
  iVar1 = FUN_100073e0(this,param_1);
  if (iVar1 < 0) {
    FUN_1000154f(iVar1);
  }
  return (undefined4 *)this;
}



// Function: FUN_100075e7 at 100075e7

undefined4 * __thiscall FUN_100075e7(void *this,int param_1)

{
  int iVar1;
  
  *(undefined4 *)this = 0;
  iVar1 = FUN_1000743e(this,param_1);
  if (iVar1 < 0) {
    FUN_1000154f(iVar1);
  }
  return (undefined4 *)this;
}



// Function: FUN_10007609 at 10007609

void FUN_10007609(ushort param_1,undefined4 param_2,undefined4 param_3,HINSTANCE param_4)

{
  FUN_100071c4((IID *)&DAT_1001e7e4,(WCHAR *)(uint)param_1,0,0,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000762c at 1000762c

void FUN_1000762c(ushort param_1,undefined4 param_2)

{
  FUN_10007609(param_1,&DAT_1001e7d4,param_2,DAT_100272fc);
  return;
}



// Function: FUN_10007649 at 10007649

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 FUN_10007649(int param_1,undefined4 param_2)

{
  char *pcVar1;
  CComBSTR *this;
  wchar_t *pwVar2;
  undefined1 uVar3;
  undefined2 *in_stack_00000028;
  undefined4 local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  uVar3 = 0;
  local_8 = 0;
  if (param_1 == 1) {
    *in_stack_00000028 = 3;
    *(undefined4 *)(in_stack_00000028 + 4) = param_2;
  }
  else if (param_1 == 2) {
    *in_stack_00000028 = 0xb;
    in_stack_00000028[4] = (ushort)(byte)param_2;
  }
  else {
    if (param_1 != 3) {
      if (param_1 == 4) {
        *(undefined4 *)(in_stack_00000028 + 4) = param_2;
        *in_stack_00000028 = 4;
        goto LAB_100076f3;
      }
      if (param_1 != 5) {
        *in_stack_00000028 = 10;
        *(undefined ***)(in_stack_00000028 + 4) = &PTR_1001e6f0;
        goto LAB_10007680;
      }
    }
    *in_stack_00000028 = 8;
    pcVar1 = (char *)FUN_1000b4e0((undefined4 *)&stack0x0000000c);
    this = (CComBSTR *)ATL::CComBSTR::CComBSTR((CComBSTR *)local_14,pcVar1);
    local_8._0_1_ = 1;
    pwVar2 = ATL::CComBSTR::Copy(this);
    *(wchar_t **)(in_stack_00000028 + 4) = pwVar2;
    local_8 = (uint)local_8._1_3_ << 8;
    Ordinal_6(local_14[0]);
  }
LAB_100076f3:
  uVar3 = 1;
LAB_10007680:
  local_8 = 0xffffffff;
  FUN_100074ce((int)&param_1);
  return uVar3;
}



// Function: basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> at 100076f7

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
  FUN_10001f4b(this,(undefined4 *)param_1,0,0xffffffff);
  return this;
}



// Function: FUN_1000771d at 1000771d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000771d(void *this,int *param_1,undefined4 *param_2)

{
  FUN_10006d1e(this,param_1);
  basic_string<>((void *)((int)this + 8),param_2);
  return this;
}



// Function: FUN_10007753 at 10007753

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
FUN_10007753(void *this,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this,
             param_1);
  return (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this;
}



// Function: FUN_10007779 at 10007779

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10007779(int param_1)

{
  int iVar1;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_44 [44];
  undefined1 *local_18;
  undefined1 *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x10007785;
  local_14 = abStack_44;
  local_18 = abStack_44;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            (abStack_44,
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_1002673c);
  local_8 = 0xffffffff;
  iVar1 = (**(code **)(**(int **)(param_1 + 0x28) + 4))();
  if (iVar1 != 0) {
    if (*(undefined4 **)(param_1 + 0x2c) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x2c))(1);
    }
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  FUN_1000b750();
  *(undefined4 *)(param_1 + 0x28) = 0;
  return;
}



// Function: FUN_100077d3 at 100077d3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100077d3(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  *(undefined4 *)((int)this + 4) = param_1[1];
  *(undefined1 *)((int)this + 4) = *(undefined1 *)(param_1 + 1);
  *(undefined4 *)((int)this + 4) = param_1[1];
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             ((int)this + 8),
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (param_1 + 2));
  return (undefined4 *)this;
}



// Function: FUN_1000781a at 1000781a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __thiscall FUN_1000781a(void *this,undefined1 *param_1,uint param_2,uint param_3)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *param_1 = 0;
  FUN_10001f4b(param_1,(undefined4 *)this,param_2,param_3);
  return param_1;
}



// Function: FUN_1000785e at 1000785e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000785e(void *this,void *param_1,undefined4 *param_2)

{
  FUN_1000771d(param_1,(int *)this,param_2);
  return param_1;
}



// Function: FUN_10007890 at 10007890

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __thiscall FUN_10007890(void *this,void *param_1)

{
  int iVar1;
  LPCWSTR lpValueName;
  undefined1 local_30 [16];
  DWORD local_20 [2];
  DWORD local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x1000789c;
  local_20[1] = 0;
  lpValueName = (LPCWSTR)((int)this + 8);
  local_18[0] = 0;
  if (7 < *(uint *)((int)this + 0x1c)) {
    lpValueName = *(LPCWSTR *)lpValueName;
  }
                    /* WARNING: Load size is inaccurate */
  RegQueryValueExW(*this,lpValueName,(LPDWORD)0x0,local_20,(LPBYTE)0x0,local_18);
  iVar1 = -local_18[0];
  *(DWORD **)((int)local_18 + iVar1 + -0x1c) = local_18;
  *(undefined1 **)((int)local_18 + iVar1 + -0x20) = local_30 + iVar1;
  *(undefined4 *)(&stack0xffffffc4 + iVar1) = 0;
  *(undefined4 *)((int)local_20 + iVar1 + -0x20) = 0x100078dc;
  FUN_100070fe(this,*(LPDWORD *)(&stack0xffffffc4 + iVar1),
               *(LPBYTE *)((int)local_18 + iVar1 + -0x20),
               *(LPDWORD *)((int)local_18 + iVar1 + -0x1c));
  *(DWORD *)((int)local_18 + iVar1 + -0x1c) = (local_18[0] >> 1) - 1;
  *(undefined1 **)((int)local_18 + iVar1 + -0x20) = local_30 + iVar1;
  *(undefined4 *)(&stack0xffffffc4 + iVar1) = 0x100078ec;
  basic_string<>(param_1,*(undefined4 **)((int)local_18 + iVar1 + -0x20),
                 *(uint *)((int)local_18 + iVar1 + -0x1c));
  local_8 = 0;
  local_20[1] = 1;
  FUN_1001739f();
  return;
}



// Function: FUN_10007904 at 10007904

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10007904(int param_1)

{
  FUN_10007779(param_1);
  return;
}



// Function: Catch@10007923 at 10007923

undefined4 Catch_10007923(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000791d;
}



// Function: FUN_1000792d at 1000792d

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000792d(void *param_1)

{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  void *pvVar4;
  uint uVar5;
  wchar_t *_Str;
  void *pvVar6;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 *local_ec;
  size_t local_e8;
  wchar_t *local_e4;
  int local_e0;
  undefined4 local_dc;
  char *local_d8;
  char *local_d4;
  void *local_d0;
  char *local_cc;
  char ***local_c8 [4];
  uint local_b8;
  uint local_b4;
  char ***local_ac [4];
  uint local_9c;
  uint local_98;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_90 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_74 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_58 [28];
  undefined4 local_3c;
  wchar_t *local_38;
  undefined4 local_30;
  wchar_t *local_2c;
  undefined4 local_24;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xec;
  local_d0 = param_1;
  local_cc = (char *)0x0;
  local_8 = 0;
  local_dc = 0x14;
  local_3c = 2;
  local_30 = 3;
  local_24 = 1;
  local_fc = 0x14;
  local_f8 = 0;
  local_f4 = 3;
  local_f0 = 0;
  local_ec = &local_3c;
  iVar1 = InternetQueryOptionW(0,0x4b,&local_fc,&local_dc);
  if (iVar1 == 0) {
    GetLastError();
    goto LAB_100079b1;
  }
  sVar2 = wcslen(local_38);
  uVar5 = sVar2 + 1;
  pcVar3 = (char *)FUN_100171c8(uVar5);
  local_d8 = pcVar3;
  local_cc = pcVar3;
  memset(pcVar3,0,uVar5);
  wcstombs_s(&local_e8,pcVar3,uVar5,local_38,uVar5);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_58,pcVar3);
  local_8._0_1_ = 1;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_c8,"http=");
  local_8._0_1_ = 2;
  if (local_b4 < 0x10) {
    local_c8[0] = (char ***)local_c8;
  }
  pvVar4 = FUN_10006f68(local_58,(char *)local_c8[0],(void *)0x0,local_b8);
  pvVar6 = (void *)(local_b8 + (int)pvVar4);
  if (pvVar4 == (void *)0xffffffff) {
    sVar2 = strlen(":");
    uVar5 = FUN_10007007(local_58,":",0xffffffff,sVar2);
    pcVar3 = FUN_1000781a(local_58,local_90,0,uVar5);
    local_8._0_1_ = 3;
    if (0xf < *(uint *)(pcVar3 + 0x14)) {
      pcVar3 = *(char **)pcVar3;
    }
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_74,pcVar3);
    local_8._0_1_ = 5;
    FUN_10001f4b(local_d0,(undefined4 *)local_74,0,0xffffffff);
    local_8._0_1_ = 3;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
              (local_74,true,0);
    local_8._0_1_ = 2;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
              (local_90,true,0);
    sVar2 = strlen(":");
    uVar5 = FUN_10007007(local_58,":",0xffffffff,sVar2);
    pcVar3 = FUN_1000781a(local_58,local_90,uVar5 + 1,0xffffffff);
    local_8._0_1_ = 7;
  }
  else {
    sVar2 = strlen("http://");
    local_e4 = (wchar_t *)FUN_10006f68(local_58,"http://",pvVar6,sVar2);
    if (local_e4 == (wchar_t *)0xffffffff) {
      sVar2 = strlen(":");
      pvVar4 = FUN_10006f68(local_58,":",pvVar6,sVar2);
      pcVar3 = FUN_1000781a(local_58,local_90,(uint)pvVar6,(int)pvVar4 - (int)pvVar6);
      local_8._0_1_ = 8;
      if (0xf < *(uint *)(pcVar3 + 0x14)) {
        pcVar3 = *(char **)pcVar3;
      }
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_74,pcVar3);
      local_8._0_1_ = 10;
      FUN_10001f4b(local_d0,(undefined4 *)local_74,0,0xffffffff);
      local_8._0_1_ = 8;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_74,true,0);
      local_8._0_1_ = 2;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_90,true,0);
      sVar2 = strlen(":");
      pvVar4 = FUN_10006f68(local_58,":",pvVar6,sVar2);
      pcVar3 = FUN_1000781a(local_58,local_90,(int)pvVar4 + 1,0xffffffff);
      local_8._0_1_ = 0xc;
    }
    else {
      sVar2 = strlen("http://");
      pvVar6 = (void *)(sVar2 + (int)local_e4);
      sVar2 = strlen(":");
      pvVar4 = FUN_10006f68(local_58,":",pvVar6,sVar2);
      pcVar3 = FUN_1000781a(local_58,local_90,(uint)pvVar6,(int)pvVar4 - (int)pvVar6);
      local_8._0_1_ = 0xd;
      if (0xf < *(uint *)(pcVar3 + 0x14)) {
        pcVar3 = *(char **)pcVar3;
      }
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_74,pcVar3);
      local_8._0_1_ = 0xf;
      FUN_10001f4b(local_d0,(undefined4 *)local_74,0,0xffffffff);
      local_8._0_1_ = 0xd;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_74,true,0);
      local_8._0_1_ = 2;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_90,true,0);
      sVar2 = strlen(":");
      pvVar4 = FUN_10006f68(local_58,":",pvVar6,sVar2);
      pcVar3 = FUN_1000781a(local_58,local_90,(int)pvVar4 + 1,0xffffffff);
      local_8._0_1_ = 0x11;
    }
  }
  if (0xf < *(uint *)(pcVar3 + 0x14)) {
    pcVar3 = *(char **)pcVar3;
  }
  iVar1 = atoi(pcVar3);
  *(int *)((int)local_d0 + 0x1c) = iVar1;
  local_8._0_1_ = 2;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (local_90,true,0);
  operator_delete__(local_d8);
  local_cc = (char *)0x0;
  sVar2 = wcslen(local_2c);
  uVar5 = sVar2 + 1;
  pcVar3 = (char *)FUN_100171c8(uVar5);
  local_cc = pcVar3;
  memset(pcVar3,0,uVar5);
  wcstombs_s(&local_e8,pcVar3,uVar5,local_2c,uVar5);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_ac,pcVar3);
  local_8 = CONCAT31(local_8._1_3_,0x12);
  sVar2 = strlen("<local>");
  pvVar4 = FUN_10006f68(local_ac,"<local>",(void *)0x0,sVar2);
  if (pvVar4 != (void *)0xffffffff) {
    FUN_10001a7e(local_ac,(uint)pvVar4,local_9c);
  }
  if (local_98 < 0x10) {
    local_ac[0] = (char ***)local_ac;
  }
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            (local_74,(char *)local_ac[0]);
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_8._0_1_ = 0x14;
  FUN_10001f4b((void *)((int)local_d0 + 0x58),(undefined4 *)local_74,0,0xffffffff);
  local_8._0_1_ = 0x12;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (local_74,true,0);
  operator_delete__(pcVar3);
  local_cc = (char *)0x0;
  local_d8 = (char *)InternetOpenW(L"INSITE",0,0,0,0);
  if (local_d8 != (char *)0x0) {
    local_e0 = InternetConnectW(local_d8,L"http://www.cummins.com",0x50,0,0,3,0,0);
    if (local_e0 != 0) {
      _Str = (wchar_t *)FUN_100171c8(0x400);
      local_e4 = _Str;
      memset(_Str,0,0x200);
      local_dc = 0x200;
      iVar1 = InternetQueryOptionW(local_e0,0x2b,_Str,&local_dc);
      if (iVar1 != 0) {
        sVar2 = wcslen(_Str);
        uVar5 = sVar2 + 1;
        local_d4 = (char *)FUN_100171c8(uVar5);
        local_cc = local_d4;
        memset(local_d4,0,uVar5);
        wcstombs_s(&local_e8,local_d4,uVar5,local_e4,uVar5);
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (local_74,local_d4);
        local_8._0_1_ = 0x17;
        FUN_10001f4b((void *)((int)local_d0 + 0x20),(undefined4 *)local_74,0,0xffffffff);
        local_8._0_1_ = 0x12;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  (local_74,true,0);
        operator_delete__(local_e4);
        operator_delete__(local_d4);
        local_cc = (char *)0x0;
        _Str = (wchar_t *)FUN_100171c8(0x400);
        memset(_Str,0,0x200);
        local_dc = 0x200;
        iVar1 = InternetQueryOptionW(local_e0,0x2c,_Str,&local_dc);
        if (iVar1 != 0) {
          sVar2 = wcslen(_Str);
          uVar5 = sVar2 + 1;
          local_d4 = (char *)FUN_100171c8(uVar5);
          local_cc = local_d4;
          memset(local_d4,0,uVar5);
          wcstombs_s(&local_e8,local_d4,uVar5,_Str,uVar5);
          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
          basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                    (local_74,local_d4);
          local_8._0_1_ = 0x1a;
          FUN_10001f4b((void *)((int)local_d0 + 0x3c),(undefined4 *)local_74,0,0xffffffff);
          local_8._0_1_ = 0x12;
          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                    (local_74,true,0);
          operator_delete__(_Str);
          operator_delete__(local_d4);
          local_cc = (char *)0x0;
          InternetCloseHandle(local_e0);
          goto LAB_10007fe3;
        }
      }
      GetLastError();
      operator_delete__(_Str);
      InternetCloseHandle(local_e0);
      InternetCloseHandle(local_d8);
      local_8._0_1_ = 2;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 local_ac,true,0);
      local_8._0_1_ = 1;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 local_c8,true,0);
      local_8 = (uint)local_8._1_3_ << 8;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_58,true,0);
      goto LAB_100079b1;
    }
LAB_10007fe3:
    InternetCloseHandle(local_d8);
  }
  local_8._0_1_ = 2;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_ac,true,0);
  local_8._0_1_ = 1;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_c8,true,0);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (local_58,true,0);
  local_8 = -1;
LAB_100079b1:
  FUN_100173ae();
  return;
}



// Function: Catch@1000802c at 1000802c

undefined4 Catch_1000802c(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -200) != 0) {
    operator_delete__(*(void **)(unaff_EBP + -200));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100079af;
}



// Function: FUN_1000804b at 1000804b

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000804b(int param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  char cVar1;
  LPCWSTR pWVar2;
  int iVar3;
  char *pcVar4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar5;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_11c [20];
  undefined4 uStack_108;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_100 [12];
  undefined4 uStack_f4;
  int in_stack_ffffff14;
  undefined4 uVar6;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_e0 [16];
  undefined4 uStack_d0;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_90 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_74 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_58 [28];
  undefined4 local_3c [2];
  undefined1 local_34;
  undefined4 local_24;
  undefined4 local_20;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x9c;
  local_8 = 0x1000805a;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xc);
  EnterCriticalSection(lpCriticalSection);
  local_8 = 0;
  if ((param_2 == 0) || (param_3 == 0)) {
    FUN_1000762c(0x76,0x80070057);
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    pWVar2 = (LPCWSTR)Ordinal_2();
    if (pWVar2 == (LPCWSTR)0x0) {
      FUN_1000154f(0x8007000e);
    }
    local_8._0_1_ = 1;
    iVar3 = Ordinal_7();
    if (iVar3 == 0) {
      uStack_d0 = 0x10008303;
      FUN_1000762c(0x76,0x80070057);
      LeaveCriticalSection(lpCriticalSection);
    }
    else {
      uStack_d0 = 0x100080d5;
      pcVar4 = (char *)FUN_10002170(local_90,pWVar2);
      local_8._0_1_ = 2;
      if (0xf < *(uint *)(pcVar4 + 0x14)) {
        pcVar4 = *(char **)pcVar4;
      }
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_58,pcVar4);
      local_8._0_1_ = 5;
      uStack_d0 = 0x10008102;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_90,true,0);
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_e0,local_58);
      local_8._0_1_ = 5;
      cVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x18))();
      pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_1002673c;
      if (cVar1 == '\0') {
        pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &DAT_10026758;
      }
      uVar6 = 0x10008147;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_74,pbVar5);
      local_20 = 0xf;
      local_24 = 0;
      local_34 = 0;
      local_8._0_1_ = 0xc;
      uStack_108 = 0x1000818f;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_100,local_58);
      local_8._0_1_ = 0xe;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_11c,local_74);
      local_8._0_1_ = 0xc;
      iVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 8))();
      if ((iVar3 == 0) || (iVar3 == 0xe)) {
        uStack_f4 = 0x1000822a;
        FUN_100077d3(&stack0xffffff14,local_3c);
        local_8._0_1_ = 0xc;
        cVar1 = FUN_10007649(in_stack_ffffff14,uVar6);
        if (cVar1 != '\0') {
          local_8._0_1_ = 9;
          FUN_100074ce((int)local_3c);
          local_8._0_1_ = 5;
          uStack_d0 = 0x100082c0;
          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                    (local_74,true,0);
          local_8._0_1_ = 1;
          uStack_d0 = 0x100082d3;
          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                    (local_58,true,0);
          local_8 = (uint)local_8._1_3_ << 8;
          Ordinal_6();
          local_8 = 0xffffffff;
          uStack_d0 = 0x100082ed;
          LeaveCriticalSection(lpCriticalSection);
          FUN_10008375();
          return;
        }
        uStack_d0 = 0x1000824f;
        FUN_1000762c(0x85,0x80004005);
        LeaveCriticalSection(lpCriticalSection);
        local_8._0_1_ = 9;
        FUN_100074ce((int)local_3c);
        local_8._0_1_ = 5;
        uStack_d0 = 0x1000827a;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  (local_74,true,0);
      }
      else {
        uStack_d0 = 0x100081df;
        FUN_1000762c((short)iVar3 + 0x77,0x80004005);
        LeaveCriticalSection(lpCriticalSection);
        local_8._0_1_ = 9;
        FUN_100074ce((int)local_3c);
        local_8._0_1_ = 5;
        uStack_d0 = 0x1000820a;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  (local_74,true,0);
      }
      local_8._0_1_ = 1;
      uStack_d0 = 0x1000828d;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_58,true,0);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    Ordinal_6();
  }
  FUN_10008375();
  return;
}



// Function: Catch@10008333 at 10008333

undefined * Catch_10008333(void)

{
  int unaff_EBP;
  
  FUN_100071c4((IID *)&DAT_1001e7e4,(WCHAR *)0x86,0,0,&DAT_1001e7d4,0x8000ffff,DAT_100272fc);
  LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0xa4) + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10008370;
}



// Function: FUN_10008375 at 10008375

void FUN_10008375(void)

{
  FUN_100173ae();
  return;
}



// Function: FUN_1000837d at 1000837d

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000837d(int param_1,int param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  char cVar1;
  LPCWSTR pWVar2;
  int iVar3;
  char *pcVar4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar5;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_f0 [20];
  undefined4 uStack_dc;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_d4 [20];
  undefined4 uStack_c0;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_b8 [16];
  undefined4 uStack_a8;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_6c [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_34 [44];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x74;
  local_8 = 0x10008389;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xc);
  EnterCriticalSection(lpCriticalSection);
  local_8 = 0;
  if (param_2 == 0) {
    FUN_1000762c(0x76,0x80070057);
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    pWVar2 = (LPCWSTR)Ordinal_2();
    if (pWVar2 == (LPCWSTR)0x0) {
      FUN_1000154f(0x8007000e);
    }
    local_8._0_1_ = 1;
    iVar3 = Ordinal_7();
    if (iVar3 == 0) {
      uStack_c0 = 0x10008564;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_b8,"");
      local_8._0_1_ = 0x13;
      uStack_dc = 0x1000857d;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_d4,"");
      local_8 = CONCAT31(local_8._1_3_,1);
      iVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 0x14))();
      if (iVar3 == 0) goto LAB_1000852e;
      FUN_1000762c((short)iVar3 + 0x77,0x80004005);
      LeaveCriticalSection(lpCriticalSection);
    }
    else {
      uStack_a8 = 0x100083fe;
      pcVar4 = (char *)FUN_10002170(local_6c,pWVar2);
      local_8._0_1_ = 2;
      if (0xf < *(uint *)(pcVar4 + 0x14)) {
        pcVar4 = *(char **)pcVar4;
      }
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_34,pcVar4);
      local_8._0_1_ = 5;
      uStack_a8 = 0x10008428;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_6c,true,0);
      uStack_c0 = 0x1000843c;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_b8,local_34);
      local_8._0_1_ = 5;
      cVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x18))();
      pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_1002673c;
      if (cVar1 == '\0') {
        pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &DAT_10026758;
      }
      uStack_c0 = 0x10008467;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_50,pbVar5);
      local_8._0_1_ = 9;
      uStack_dc = 0x10008483;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_d4,local_34);
      local_8._0_1_ = 0xb;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_f0,local_50);
      local_8._0_1_ = 9;
      iVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 0x14))();
      if (iVar3 == 0) {
        local_8._0_1_ = 5;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  (local_50,true,0);
        local_8 = CONCAT31(local_8._1_3_,1);
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  (local_34,true,0);
LAB_1000852e:
        local_8 = local_8 & 0xffffff00;
        Ordinal_6(pWVar2);
        local_8 = 0xffffffff;
        LeaveCriticalSection(lpCriticalSection);
        FUN_100085f3();
        return;
      }
      FUN_1000762c((short)iVar3 + 0x77,0x80004005);
      LeaveCriticalSection(lpCriticalSection);
      local_8._0_1_ = 5;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_50,true,0);
      local_8 = CONCAT31(local_8._1_3_,1);
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_34,true,0);
    }
    local_8 = local_8 & 0xffffff00;
    Ordinal_6(pWVar2);
  }
  FUN_100085f3();
  return;
}



// Function: Catch@100085b4 at 100085b4

undefined * Catch_100085b4(void)

{
  int unaff_EBP;
  
  FUN_100071c4((IID *)&DAT_1001e7e4,(WCHAR *)0x86,0,0,&DAT_1001e7d4,0x8000ffff,DAT_100272fc);
  LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x7c) + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100085ee;
}



// Function: FUN_100085f3 at 100085f3

void FUN_100085f3(void)

{
  FUN_100173ae();
  return;
}



// Function: FUN_100085fb at 100085fb

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_100085fb(int param_1,int param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  char cVar1;
  LPCWSTR pWVar2;
  int iVar3;
  char *pcVar4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar5;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_f0 [20];
  undefined4 uStack_dc;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_d4 [20];
  undefined4 uStack_c0;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_b8 [16];
  undefined4 uStack_a8;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_6c [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_34 [44];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x74;
  local_8 = 0x10008607;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xc);
  EnterCriticalSection(lpCriticalSection);
  local_8 = 0;
  if (param_2 == 0) {
    FUN_1000762c(0x76,0x80070057);
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    pWVar2 = (LPCWSTR)Ordinal_2();
    if (pWVar2 == (LPCWSTR)0x0) {
      FUN_1000154f(0x8007000e);
    }
    local_8._0_1_ = 1;
    iVar3 = Ordinal_7();
    if (iVar3 == 0) {
      uStack_c0 = 0x100087e2;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_b8,"");
      local_8._0_1_ = 0x13;
      uStack_dc = 0x100087fb;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_d4,"");
      local_8 = CONCAT31(local_8._1_3_,1);
      iVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 0x10))();
      if (iVar3 == 0) goto LAB_100087ac;
      FUN_1000762c((short)iVar3 + 0x77,0x80004005);
      LeaveCriticalSection(lpCriticalSection);
    }
    else {
      uStack_a8 = 0x1000867c;
      pcVar4 = (char *)FUN_10002170(local_6c,pWVar2);
      local_8._0_1_ = 2;
      if (0xf < *(uint *)(pcVar4 + 0x14)) {
        pcVar4 = *(char **)pcVar4;
      }
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_34,pcVar4);
      local_8._0_1_ = 5;
      uStack_a8 = 0x100086a6;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_6c,true,0);
      uStack_c0 = 0x100086ba;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_b8,local_34);
      local_8._0_1_ = 5;
      cVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x18))();
      pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_1002673c;
      if (cVar1 == '\0') {
        pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &DAT_10026758;
      }
      uStack_c0 = 0x100086e5;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_50,pbVar5);
      local_8._0_1_ = 9;
      uStack_dc = 0x10008701;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_d4,local_34);
      local_8._0_1_ = 0xb;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_f0,local_50);
      local_8._0_1_ = 9;
      iVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 0x10))();
      if (iVar3 == 0) {
        local_8._0_1_ = 5;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  (local_50,true,0);
        local_8 = CONCAT31(local_8._1_3_,1);
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  (local_34,true,0);
LAB_100087ac:
        local_8 = local_8 & 0xffffff00;
        Ordinal_6(pWVar2);
        local_8 = 0xffffffff;
        LeaveCriticalSection(lpCriticalSection);
        FUN_10008871();
        return;
      }
      FUN_1000762c((short)iVar3 + 0x77,0x80004005);
      LeaveCriticalSection(lpCriticalSection);
      local_8._0_1_ = 5;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_50,true,0);
      local_8 = CONCAT31(local_8._1_3_,1);
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_34,true,0);
    }
    local_8 = local_8 & 0xffffff00;
    Ordinal_6(pWVar2);
  }
  FUN_10008871();
  return;
}



// Function: Catch@10008832 at 10008832

undefined * Catch_10008832(void)

{
  int unaff_EBP;
  
  FUN_100071c4((IID *)&DAT_1001e7e4,(WCHAR *)0x86,0,0,&DAT_1001e7d4,0x8000ffff,DAT_100272fc);
  LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x7c) + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000886c;
}



// Function: FUN_10008871 at 10008871

void FUN_10008871(void)

{
  FUN_100173ae();
  return;
}



// Function: FUN_10008879 at 10008879

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10008879(int param_1,int param_2,undefined2 *param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  char cVar1;
  LPCWSTR pWVar2;
  int iVar3;
  char *pcVar4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar5;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_f4 [20];
  undefined4 uStack_e0;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_d8 [20];
  undefined4 uStack_c4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_bc [16];
  undefined4 uStack_ac;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_6c [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_34 [44];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x78;
  local_8 = 0x10008885;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xc);
  EnterCriticalSection(lpCriticalSection);
  local_8 = 0;
  if (param_2 == 0) {
    FUN_1000762c(0x76,0x80070057);
    LeaveCriticalSection(lpCriticalSection);
    FUN_10008a9e();
    return;
  }
  pWVar2 = (LPCWSTR)Ordinal_2();
  if (pWVar2 == (LPCWSTR)0x0) {
    FUN_1000154f(0x8007000e);
  }
  local_8._0_1_ = 1;
  iVar3 = Ordinal_7();
  if (iVar3 == 0) {
    *param_3 = 0xb;
    uStack_c4 = 0x10008a09;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_bc,"");
    local_8._0_1_ = 0x11;
    uStack_e0 = 0x10008a22;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_d8,"");
    local_8 = CONCAT31(local_8._1_3_,1);
    cVar1 = (**(code **)(**(int **)(param_1 + 0x28) + 0x18))();
    param_3[4] = (cVar1 == '\0') - 1;
  }
  else {
    uStack_ac = 0x100088fe;
    pcVar4 = (char *)FUN_10002170(local_6c,pWVar2);
    local_8._0_1_ = 2;
    if (0xf < *(uint *)(pcVar4 + 0x14)) {
      pcVar4 = *(char **)pcVar4;
    }
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_34,pcVar4);
    local_8._0_1_ = 5;
    uStack_ac = 0x10008928;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
              (local_6c,true,0);
    uStack_c4 = 0x1000893c;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
              (abStack_bc,local_34);
    local_8._0_1_ = 5;
    cVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x18))();
    pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_1002673c;
    if (cVar1 == '\0') {
      pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_10026758;
    }
    uStack_c4 = 0x10008967;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_50,pbVar5);
    local_8._0_1_ = 9;
    *param_3 = 0xb;
    uStack_e0 = 0x10008989;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
              (abStack_d8,local_34);
    local_8._0_1_ = 0xb;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
              (abStack_f4,local_50);
    local_8._0_1_ = 9;
    cVar1 = (**(code **)(**(int **)(param_1 + 0x28) + 0x18))();
    param_3[4] = (cVar1 == '\0') - 1;
    local_8._0_1_ = 5;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
              (local_50,true,0);
    local_8 = CONCAT31(local_8._1_3_,1);
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
              (local_34,true,0);
  }
  local_8 = local_8 & 0xffffff00;
  Ordinal_6(pWVar2);
  local_8 = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
  FUN_10008a9e();
  return;
}



// Function: Catch@10008a60 at 10008a60

undefined * Catch_10008a60(void)

{
  int unaff_EBP;
  
  FUN_10007609((short)*(undefined4 *)(*(int *)(unaff_EBP + -0x84) + 0x48) + 0x77,&DAT_1001e7d4,
               0x8000ffff,DAT_100272fc);
  LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x7c) + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10008a99;
}



// Function: FUN_10008a9e at 10008a9e

void FUN_10008a9e(void)

{
  FUN_100173ae();
  return;
}



// Function: Catch@10008aa6 at 10008aa6

undefined * Catch_10008aa6(void)

{
  int unaff_EBP;
  
  FUN_100071c4((IID *)&DAT_1001e7e4,(WCHAR *)0x86,0,0,&DAT_1001e7d4,0x8000ffff,DAT_100272fc);
  LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x7c) + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10008a99;
}



// Function: FUN_10008ae0 at 10008ae0

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10008ae0(int param_1,int param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  char cVar1;
  LPCWSTR pWVar2;
  int iVar3;
  char *pcVar4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar5;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_f0 [20];
  undefined4 uStack_dc;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_d4 [20];
  undefined4 uStack_c0;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_b8 [16];
  undefined4 uStack_a8;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_6c [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_34 [44];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x74;
  local_8 = 0x10008aec;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xc);
  EnterCriticalSection(lpCriticalSection);
  local_8 = 0;
  if (param_2 == 0) {
    FUN_1000762c(0x76,0x80070057);
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    pWVar2 = (LPCWSTR)Ordinal_2();
    if (pWVar2 == (LPCWSTR)0x0) {
      FUN_1000154f(0x8007000e);
    }
    local_8._0_1_ = 1;
    iVar3 = Ordinal_7();
    if (iVar3 == 0) {
      uStack_c0 = 0x10008cc7;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_b8,"");
      local_8._0_1_ = 0x13;
      uStack_dc = 0x10008ce0;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_d4,"");
      local_8 = CONCAT31(local_8._1_3_,1);
      iVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 0x1c))();
      if (iVar3 == 0) goto LAB_10008c91;
      FUN_1000762c((short)iVar3 + 0x77,0x80004005);
      LeaveCriticalSection(lpCriticalSection);
    }
    else {
      uStack_a8 = 0x10008b61;
      pcVar4 = (char *)FUN_10002170(local_6c,pWVar2);
      local_8._0_1_ = 2;
      if (0xf < *(uint *)(pcVar4 + 0x14)) {
        pcVar4 = *(char **)pcVar4;
      }
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_34,pcVar4);
      local_8._0_1_ = 5;
      uStack_a8 = 0x10008b8b;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_6c,true,0);
      uStack_c0 = 0x10008b9f;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_b8,local_34);
      local_8._0_1_ = 5;
      cVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x18))();
      pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_1002673c;
      if (cVar1 == '\0') {
        pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &DAT_10026758;
      }
      uStack_c0 = 0x10008bca;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_50,pbVar5);
      local_8._0_1_ = 9;
      uStack_dc = 0x10008be6;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_d4,local_34);
      local_8._0_1_ = 0xb;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_f0,local_50);
      local_8._0_1_ = 9;
      iVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 0x1c))();
      if (iVar3 == 0) {
        local_8._0_1_ = 5;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  (local_50,true,0);
        local_8 = CONCAT31(local_8._1_3_,1);
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  (local_34,true,0);
LAB_10008c91:
        local_8 = local_8 & 0xffffff00;
        Ordinal_6(pWVar2);
        local_8 = 0xffffffff;
        LeaveCriticalSection(lpCriticalSection);
        FUN_10008d56();
        return;
      }
      FUN_1000762c((short)iVar3 + 0x77,0x80004005);
      LeaveCriticalSection(lpCriticalSection);
      local_8._0_1_ = 5;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_50,true,0);
      local_8 = CONCAT31(local_8._1_3_,1);
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_34,true,0);
    }
    local_8 = local_8 & 0xffffff00;
    Ordinal_6(pWVar2);
  }
  FUN_10008d56();
  return;
}



// Function: Catch@10008d17 at 10008d17

undefined * Catch_10008d17(void)

{
  int unaff_EBP;
  
  FUN_100071c4((IID *)&DAT_1001e7e4,(WCHAR *)0x86,0,0,&DAT_1001e7d4,0x8000ffff,DAT_100272fc);
  LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x7c) + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10008d51;
}



// Function: FUN_10008d56 at 10008d56

void FUN_10008d56(void)

{
  FUN_100173ae();
  return;
}



// Function: FUN_10008d5e at 10008d5e

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */
/* WARNING: Type propagation algorithm not settling */

void FUN_10008d5e(int param_1,int param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  CComBSTR *pCVar3;
  char *pcVar4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar5;
  int in_stack_fffffeb8;
  undefined4 in_stack_fffffebc;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_120 [20];
  undefined4 uStack_10c;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_104 [24];
  undefined4 uStack_ec;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_e4 [12];
  undefined4 uStack_d8;
  int local_b4;
  undefined1 *local_b0;
  undefined1 *local_ac;
  int *local_a8;
  undefined1 *local_a4;
  int local_a0;
  LPCRITICAL_SECTION local_9c;
  int local_98 [2];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_90 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_74 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_58 [28];
  undefined4 local_3c [2];
  undefined1 local_34;
  undefined4 local_24;
  undefined4 local_20;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xa8;
  local_8 = 0x10008d6d;
  local_a8 = param_3;
  local_9c = (LPCRITICAL_SECTION)(param_1 + 0xc);
  EnterCriticalSection(local_9c);
  local_8 = 0;
  if ((param_2 == 0) || (local_a8 == (int *)0x0)) {
    FUN_1000762c(0x76,0x80070057);
    LeaveCriticalSection(local_9c);
  }
  else {
    FUN_100075c5(local_98 + 1,param_2);
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar2 = FUN_10006df6(local_98 + 1,0);
    if (iVar2 == 0) {
      FUN_1000762c(0x76,0x80070057);
      LeaveCriticalSection(local_9c);
    }
    else {
      local_b4 = FUN_10006df6(local_98 + 1,0);
      local_98[0] = 0;
      local_b0 = (undefined1 *)0x0;
      iVar2 = FUN_1000708b(local_98,(int)&local_b4,1);
      if (iVar2 < 0) {
        FUN_1000154f(iVar2);
      }
      local_8._0_1_ = 2;
      local_a0 = 0;
      while( true ) {
        iVar2 = FUN_10006df6(local_98 + 1,0);
        if (iVar2 <= local_a0) {
          Ordinal_22();
          iVar2 = local_98[0];
          local_98[0] = 0;
          *local_a8 = iVar2;
          local_8._0_1_ = 1;
          FUN_100070d7(local_98);
          Ordinal_22();
          local_98[1] = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_100070d7(local_98 + 1);
          local_8 = 0xffffffff;
          uStack_d8 = 0x100090fd;
          LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
          FUN_10009185();
          return;
        }
        pCVar3 = (CComBSTR *)FUN_10006ed0(local_98 + 1,local_a0);
        ATL::CComBSTR::CComBSTR((CComBSTR *)&local_9c,pCVar3);
        local_8._0_1_ = 3;
        pcVar4 = (char *)FUN_10002170(local_90,(LPCWSTR)local_9c);
        local_8._0_1_ = 4;
        if (0xf < *(uint *)(pcVar4 + 0x14)) {
          pcVar4 = *(char **)pcVar4;
        }
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (local_58,pcVar4);
        local_8._0_1_ = 7;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  (local_90,true,0);
        local_a4 = abStack_e4;
        local_ac = abStack_e4;
        uStack_ec = 0x10008ea8;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (abStack_e4,local_58);
        local_8._0_1_ = 7;
        cVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x18))();
        pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &DAT_1002673c;
        if (cVar1 == '\0') {
          pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &DAT_10026758;
        }
        uStack_ec = 0x10008ed3;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (local_74,pbVar5);
        local_20 = 0xf;
        local_24 = 0;
        local_34 = 0;
        local_8._0_1_ = 0xe;
        local_ac = abStack_104;
        local_a4 = abStack_104;
        uStack_10c = 0x10008f1b;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (abStack_104,local_58);
        local_8._0_1_ = 0x10;
        local_a4 = abStack_120;
        local_b0 = abStack_120;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (abStack_120,local_74);
        local_8._0_1_ = 0xe;
        iVar2 = (**(code **)(**(int **)(param_1 + 0x28) + 8))();
        if ((iVar2 != 0) && (iVar2 != 0xe)) break;
        FUN_10006e37(local_98,local_a0);
        local_b0 = &stack0xfffffeb8;
        FUN_100077d3(&stack0xfffffeb8,local_3c);
        local_8._0_1_ = 0xe;
        cVar1 = FUN_10007649(in_stack_fffffeb8,in_stack_fffffebc);
        if (cVar1 == '\0') {
          FUN_1000762c(0x85,0x80004005);
          LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
          local_8._0_1_ = 0xb;
          FUN_100074ce((int)local_3c);
          local_8._0_1_ = 7;
          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                    (local_74,true,0);
          goto LAB_10009016;
        }
        local_8._0_1_ = 0xb;
        FUN_100074ce((int)local_3c);
        local_8._0_1_ = 7;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  (local_74,true,0);
        local_8._0_1_ = 3;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  (local_58,true,0);
        local_8._0_1_ = 2;
        Ordinal_6();
        local_a0 = local_a0 + 1;
      }
      FUN_1000762c((short)iVar2 + 0x77,0x80004005);
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
      local_8._0_1_ = 0xb;
      FUN_100074ce((int)local_3c);
      local_8._0_1_ = 7;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_74,true,0);
LAB_10009016:
      local_8._0_1_ = 3;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_58,true,0);
      local_8._0_1_ = 2;
      Ordinal_6();
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_100070d7(local_98);
    }
    local_8 = local_8 & 0xffffff00;
    FUN_100070d7(local_98 + 1);
  }
  FUN_10009185();
  return;
}



// Function: Catch@10009143 at 10009143

undefined * Catch_10009143(void)

{
  int unaff_EBP;
  
  FUN_100071c4((IID *)&DAT_1001e7e4,(WCHAR *)0x86,0,0,&DAT_1001e7d4,0x8000ffff,DAT_100272fc);
  LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0xb4) + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10009180;
}



// Function: FUN_10009185 at 10009185

void FUN_10009185(void)

{
  FUN_100173ae();
  return;
}



// Function: FUN_1000918d at 1000918d

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000918d(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  CComBSTR *pCVar3;
  char *pcVar4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar5;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_ec [20];
  undefined4 uStack_d8;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_d0 [20];
  undefined4 uStack_bc;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_b4 [16];
  undefined4 uStack_a4;
  int local_78;
  LPCRITICAL_SECTION local_74;
  int local_70;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_6c [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_34 [44];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x78;
  local_8 = 0x10009199;
  local_74 = (LPCRITICAL_SECTION)(param_1 + 0xc);
  EnterCriticalSection(local_74);
  local_8 = 0;
  if (param_2 == 0) {
    uStack_a4 = 0x100091c7;
    FUN_1000762c(0x76,0x80070057);
    LeaveCriticalSection(local_74);
LAB_100091d0:
    FUN_10009454();
    return;
  }
  FUN_100075c5(&local_70,param_2);
  local_8._0_1_ = 1;
  iVar2 = FUN_10006df6(&local_70,0);
  if (iVar2 == 0) {
    uStack_bc = 0x1000939c;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_b4,"");
    local_8._0_1_ = 0x14;
    uStack_d8 = 0x100093b5;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_d0,"");
    local_8._0_1_ = 1;
    iVar2 = (**(code **)(**(int **)(param_1 + 0x28) + 0x14))();
    if (iVar2 != 0) {
      uStack_a4 = 0x100093de;
      FUN_1000762c((short)iVar2 + 0x77,0x80004005);
      LeaveCriticalSection(local_74);
LAB_10009338:
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_100070d7(&local_70);
      goto LAB_100091d0;
    }
  }
  else {
    local_78 = 0;
    while( true ) {
      iVar2 = FUN_10006df6(&local_70,0);
      if (iVar2 <= local_78) break;
      pCVar3 = (CComBSTR *)FUN_10006ed0(&local_70,local_78);
      ATL::CComBSTR::CComBSTR((CComBSTR *)&local_74,pCVar3);
      local_8._0_1_ = 2;
      uStack_a4 = 0x1000922e;
      pcVar4 = (char *)FUN_10002170(local_6c,(LPCWSTR)local_74);
      local_8._0_1_ = 3;
      if (0xf < *(uint *)(pcVar4 + 0x14)) {
        pcVar4 = *(char **)pcVar4;
      }
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_34,pcVar4);
      local_8._0_1_ = 6;
      uStack_a4 = 0x10009258;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_6c,true,0);
      uStack_bc = 0x1000926c;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_b4,local_34);
      local_8._0_1_ = 6;
      cVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x18))();
      pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_1002673c;
      if (cVar1 == '\0') {
        pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &DAT_10026758;
      }
      uStack_bc = 0x10009297;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_50,pbVar5);
      local_8._0_1_ = 10;
      uStack_d8 = 0x100092b3;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_d0,local_34);
      local_8._0_1_ = 0xc;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_ec,local_50);
      local_8._0_1_ = 10;
      iVar2 = (**(code **)(**(int **)(param_1 + 0x28) + 0x14))();
      if (iVar2 != 0) {
        FUN_1000762c((short)iVar2 + 0x77,0x80004005);
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
        local_8._0_1_ = 6;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  (local_50,true,0);
        local_8._0_1_ = 2;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  (local_34,true,0);
        local_8._0_1_ = 1;
        Ordinal_6(local_74);
        goto LAB_10009338;
      }
      local_8._0_1_ = 6;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_50,true,0);
      local_8._0_1_ = 2;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_34,true,0);
      local_8._0_1_ = 1;
      Ordinal_6(local_74);
      local_78 = local_78 + 1;
    }
  }
  Ordinal_22();
  local_70 = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_100070d7(&local_70);
  local_8 = 0xffffffff;
  uStack_a4 = 0x10009411;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  FUN_10009454();
  return;
}



// Function: Catch@10009415 at 10009415

undefined * Catch_10009415(void)

{
  int unaff_EBP;
  
  FUN_100071c4((IID *)&DAT_1001e7e4,(WCHAR *)0x86,0,0,&DAT_1001e7d4,0x8000ffff,DAT_100272fc);
  LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x80) + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000944f;
}



// Function: FUN_10009454 at 10009454

void FUN_10009454(void)

{
  FUN_100173ae();
  return;
}



// Function: FUN_1000945c at 1000945c

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000945c(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  CComBSTR *pCVar3;
  char *pcVar4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar5;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_ec [20];
  undefined4 uStack_d8;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_d0 [20];
  undefined4 uStack_bc;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_b4 [16];
  undefined4 uStack_a4;
  int local_78;
  LPCRITICAL_SECTION local_74;
  int local_70;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_6c [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_34 [44];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x78;
  local_8 = 0x10009468;
  local_74 = (LPCRITICAL_SECTION)(param_1 + 0xc);
  EnterCriticalSection(local_74);
  local_8 = 0;
  if (param_2 == 0) {
    uStack_a4 = 0x10009496;
    FUN_1000762c(0x76,0x80070057);
    LeaveCriticalSection(local_74);
LAB_1000949f:
    FUN_10009723();
    return;
  }
  FUN_100075c5(&local_70,param_2);
  local_8._0_1_ = 1;
  iVar2 = FUN_10006df6(&local_70,0);
  if (iVar2 == 0) {
    uStack_bc = 0x1000966b;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_b4,"");
    local_8._0_1_ = 0x14;
    uStack_d8 = 0x10009684;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_d0,"");
    local_8._0_1_ = 1;
    iVar2 = (**(code **)(**(int **)(param_1 + 0x28) + 0x10))();
    if (iVar2 != 0) {
      uStack_a4 = 0x100096ad;
      FUN_1000762c((short)iVar2 + 0x77,0x80004005);
      LeaveCriticalSection(local_74);
LAB_10009607:
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_100070d7(&local_70);
      goto LAB_1000949f;
    }
  }
  else {
    local_78 = 0;
    while( true ) {
      iVar2 = FUN_10006df6(&local_70,0);
      if (iVar2 <= local_78) break;
      pCVar3 = (CComBSTR *)FUN_10006ed0(&local_70,local_78);
      ATL::CComBSTR::CComBSTR((CComBSTR *)&local_74,pCVar3);
      local_8._0_1_ = 2;
      uStack_a4 = 0x100094fd;
      pcVar4 = (char *)FUN_10002170(local_6c,(LPCWSTR)local_74);
      local_8._0_1_ = 3;
      if (0xf < *(uint *)(pcVar4 + 0x14)) {
        pcVar4 = *(char **)pcVar4;
      }
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_34,pcVar4);
      local_8._0_1_ = 6;
      uStack_a4 = 0x10009527;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_6c,true,0);
      uStack_bc = 0x1000953b;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_b4,local_34);
      local_8._0_1_ = 6;
      cVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x18))();
      pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_1002673c;
      if (cVar1 == '\0') {
        pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &DAT_10026758;
      }
      uStack_bc = 0x10009566;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_50,pbVar5);
      local_8._0_1_ = 10;
      uStack_d8 = 0x10009582;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_d0,local_34);
      local_8._0_1_ = 0xc;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_ec,local_50);
      local_8._0_1_ = 10;
      iVar2 = (**(code **)(**(int **)(param_1 + 0x28) + 0x10))();
      if (iVar2 != 0) {
        FUN_1000762c((short)iVar2 + 0x77,0x80004005);
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
        local_8._0_1_ = 6;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  (local_50,true,0);
        local_8._0_1_ = 2;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  (local_34,true,0);
        local_8._0_1_ = 1;
        Ordinal_6(local_74);
        goto LAB_10009607;
      }
      local_8._0_1_ = 6;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_50,true,0);
      local_8._0_1_ = 2;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_34,true,0);
      local_8._0_1_ = 1;
      Ordinal_6(local_74);
      local_78 = local_78 + 1;
    }
  }
  Ordinal_22();
  local_70 = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_100070d7(&local_70);
  local_8 = 0xffffffff;
  uStack_a4 = 0x100096e0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  FUN_10009723();
  return;
}



// Function: Catch@100096e4 at 100096e4

undefined * Catch_100096e4(void)

{
  int unaff_EBP;
  
  FUN_100071c4((IID *)&DAT_1001e7e4,(WCHAR *)0x86,0,0,&DAT_1001e7d4,0x8000ffff,DAT_100272fc);
  LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x80) + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000971e;
}



// Function: FUN_10009723 at 10009723

void FUN_10009723(void)

{
  FUN_100173ae();
  return;
}



// Function: FUN_1000972b at 1000972b

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000972b(int param_1,int param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  CComBSTR *pCVar3;
  char *pcVar4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar5;
  undefined2 *puVar6;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_104 [20];
  undefined4 uStack_f0;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_e8 [20];
  undefined4 uStack_d4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_cc [12];
  undefined4 uStack_c0;
  int local_9c;
  undefined1 *local_98;
  LPCWSTR local_94;
  int *local_90;
  int local_8c;
  undefined4 local_88;
  undefined1 *local_84;
  int local_80;
  int local_7c;
  LPCRITICAL_SECTION local_78;
  int local_74;
  char local_6d;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_6c [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_34 [44];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x90;
  local_8 = 0x1000973a;
  local_8c = param_1;
  local_90 = param_3;
  local_78 = (LPCRITICAL_SECTION)(param_1 + 0xc);
  EnterCriticalSection(local_78);
  local_8 = 0;
  if ((param_2 != 0) && (local_90 != (int *)0x0)) {
    FUN_100075c5(&local_7c,param_2);
    local_8._1_3_ = (uint3)((uint)local_8 >> 8);
    local_74 = 0;
    local_8._0_1_ = 2;
    iVar2 = FUN_10006df6(&local_7c,0);
    if (iVar2 == 0) {
      local_88 = 1;
      local_84 = (undefined1 *)0x0;
      FUN_1000708b(&local_74,(int)&local_88,1);
      local_98 = abStack_cc;
      local_84 = abStack_cc;
      uStack_d4 = 0x1000995c;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_cc,"");
      local_8._0_1_ = 0x13;
      local_84 = abStack_e8;
      local_78 = (LPCRITICAL_SECTION)abStack_e8;
      uStack_f0 = 0x10009975;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_e8,"");
      local_8._0_1_ = 2;
      local_6d = (**(code **)(**(int **)(param_1 + 0x28) + 0x18))();
      puVar6 = (undefined2 *)FUN_10006e37(&local_74,0);
      *puVar6 = 0xb;
      local_78 = (LPCRITICAL_SECTION)((local_6d == '\0') - 1);
      iVar2 = FUN_10006e37(&local_74,0);
      *(short *)(iVar2 + 8) = (short)local_78;
    }
    else {
      local_9c = FUN_10006df6(&local_7c,0);
      local_98 = (undefined1 *)0x0;
      FUN_1000708b(&local_74,(int)&local_9c,1);
      local_80 = 0;
      while( true ) {
        iVar2 = FUN_10006df6(&local_7c,0);
        if (iVar2 <= local_80) break;
        pCVar3 = (CComBSTR *)FUN_10006ed0(&local_7c,local_80);
        ATL::CComBSTR::CComBSTR((CComBSTR *)&local_94,pCVar3);
        local_8._0_1_ = 3;
        pcVar4 = (char *)FUN_10002170(local_6c,local_94);
        local_8._0_1_ = 4;
        if (0xf < *(uint *)(pcVar4 + 0x14)) {
          pcVar4 = *(char **)pcVar4;
        }
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (local_34,pcVar4);
        local_8._0_1_ = 7;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  (local_6c,true,0);
        local_78 = (LPCRITICAL_SECTION)abStack_cc;
        local_84 = abStack_cc;
        uStack_d4 = 0x1000983d;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (abStack_cc,local_34);
        local_8._0_1_ = 7;
        cVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x18))();
        pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &DAT_1002673c;
        if (cVar1 == '\0') {
          pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &DAT_10026758;
        }
        uStack_d4 = 0x10009868;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (local_50,pbVar5);
        local_8._0_1_ = 0xb;
        local_84 = abStack_e8;
        local_78 = (LPCRITICAL_SECTION)abStack_e8;
        uStack_f0 = 0x10009884;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (abStack_e8,local_34);
        local_8._0_1_ = 0xd;
        local_78 = (LPCRITICAL_SECTION)abStack_104;
        local_98 = abStack_104;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (abStack_104,local_50);
        local_8._0_1_ = 0xb;
        local_6d = (**(code **)(**(int **)(param_1 + 0x28) + 0x18))();
        puVar6 = (undefined2 *)FUN_10006e37(&local_74,local_80);
        *puVar6 = 0xb;
        local_78 = (LPCRITICAL_SECTION)((local_6d == '\0') - 1);
        iVar2 = FUN_10006e37(&local_74,local_80);
        *(short *)(iVar2 + 8) = (short)local_78;
        local_8._0_1_ = 7;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  (local_50,true,0);
        local_8._0_1_ = 3;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  (local_34,true,0);
        local_8._0_1_ = 2;
        Ordinal_6(local_94);
        local_80 = local_80 + 1;
      }
    }
    Ordinal_22();
    iVar2 = local_74;
    local_74 = 0;
    *local_90 = iVar2;
    Ordinal_22();
    local_7c = 0;
    local_8._0_1_ = 1;
    FUN_100070d7(&local_74);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_100070d7(&local_7c);
    local_8 = 0xffffffff;
    uStack_c0 = 0x100099fd;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    FUN_10009a5e();
    return;
  }
  FUN_1000762c(0x76,0x80070057);
  LeaveCriticalSection(local_78);
  FUN_10009a5e();
  return;
}



// Function: Catch@10009a1d at 10009a1d

undefined * Catch_10009a1d(void)

{
  int unaff_EBP;
  
  FUN_10007609((short)*(undefined4 *)(*(int *)(unaff_EBP + -0x9c) + 0x48) + 0x77,&DAT_1001e7d4,
               0x8000ffff,DAT_100272fc);
  LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x88) + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10009a59;
}



// Function: FUN_10009a5e at 10009a5e

void FUN_10009a5e(void)

{
  FUN_100173ae();
  return;
}



// Function: Catch@10009a66 at 10009a66

undefined * Catch_10009a66(void)

{
  int unaff_EBP;
  
  FUN_100071c4((IID *)&DAT_1001e7e4,(WCHAR *)0x86,0,0,&DAT_1001e7d4,0x8000ffff,DAT_100272fc);
  LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x88) + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10009a59;
}



// Function: FUN_10009aa3 at 10009aa3

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10009aa3(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  CComBSTR *pCVar3;
  char *pcVar4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar5;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_ec [20];
  undefined4 uStack_d8;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_d0 [20];
  undefined4 uStack_bc;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_b4 [16];
  undefined4 uStack_a4;
  int local_78;
  LPCRITICAL_SECTION local_74;
  int local_70;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_6c [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_34 [44];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x78;
  local_8 = 0x10009aaf;
  local_74 = (LPCRITICAL_SECTION)(param_1 + 0xc);
  EnterCriticalSection(local_74);
  local_8 = 0;
  if (param_2 == 0) {
    uStack_a4 = 0x10009add;
    FUN_1000762c(0x76,0x80070057);
    LeaveCriticalSection(local_74);
LAB_10009ae6:
    FUN_10009d6a();
    return;
  }
  FUN_100075c5(&local_70,param_2);
  local_8._0_1_ = 1;
  iVar2 = FUN_10006df6(&local_70,0);
  if (iVar2 == 0) {
    uStack_bc = 0x10009cb2;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_b4,"");
    local_8._0_1_ = 0x14;
    uStack_d8 = 0x10009ccb;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_d0,"");
    local_8._0_1_ = 1;
    iVar2 = (**(code **)(**(int **)(param_1 + 0x28) + 0x1c))();
    if (iVar2 != 0) {
      uStack_a4 = 0x10009cf4;
      FUN_1000762c((short)iVar2 + 0x77,0x80004005);
      LeaveCriticalSection(local_74);
LAB_10009c4e:
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_100070d7(&local_70);
      goto LAB_10009ae6;
    }
  }
  else {
    local_78 = 0;
    while( true ) {
      iVar2 = FUN_10006df6(&local_70,0);
      if (iVar2 <= local_78) break;
      pCVar3 = (CComBSTR *)FUN_10006ed0(&local_70,local_78);
      ATL::CComBSTR::CComBSTR((CComBSTR *)&local_74,pCVar3);
      local_8._0_1_ = 2;
      uStack_a4 = 0x10009b44;
      pcVar4 = (char *)FUN_10002170(local_6c,(LPCWSTR)local_74);
      local_8._0_1_ = 3;
      if (0xf < *(uint *)(pcVar4 + 0x14)) {
        pcVar4 = *(char **)pcVar4;
      }
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_34,pcVar4);
      local_8._0_1_ = 6;
      uStack_a4 = 0x10009b6e;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_6c,true,0);
      uStack_bc = 0x10009b82;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_b4,local_34);
      local_8._0_1_ = 6;
      cVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x18))();
      pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_1002673c;
      if (cVar1 == '\0') {
        pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &DAT_10026758;
      }
      uStack_bc = 0x10009bad;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_50,pbVar5);
      local_8._0_1_ = 10;
      uStack_d8 = 0x10009bc9;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_d0,local_34);
      local_8._0_1_ = 0xc;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_ec,local_50);
      local_8._0_1_ = 10;
      iVar2 = (**(code **)(**(int **)(param_1 + 0x28) + 0x1c))();
      if (iVar2 != 0) {
        FUN_1000762c((short)iVar2 + 0x77,0x80004005);
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
        local_8._0_1_ = 6;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  (local_50,true,0);
        local_8._0_1_ = 2;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  (local_34,true,0);
        local_8._0_1_ = 1;
        Ordinal_6(local_74);
        goto LAB_10009c4e;
      }
      local_8._0_1_ = 6;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_50,true,0);
      local_8._0_1_ = 2;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_34,true,0);
      local_8._0_1_ = 1;
      Ordinal_6(local_74);
      local_78 = local_78 + 1;
    }
  }
  Ordinal_22();
  local_70 = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_100070d7(&local_70);
  local_8 = 0xffffffff;
  uStack_a4 = 0x10009d27;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  FUN_10009d6a();
  return;
}



// Function: Catch@10009d2b at 10009d2b

undefined * Catch_10009d2b(void)

{
  int unaff_EBP;
  
  FUN_100071c4((IID *)&DAT_1001e7e4,(WCHAR *)0x86,0,0,&DAT_1001e7d4,0x8000ffff,DAT_100272fc);
  LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x80) + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10009d65;
}



// Function: FUN_10009d6a at 10009d6a

void FUN_10009d6a(void)

{
  FUN_100173ae();
  return;
}



// Function: FUN_10009d72 at 10009d72

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10009d72(int param_1)

{
  int iVar1;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_68 [20];
  undefined4 uStack_54;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_4c [44];
  undefined1 *local_20;
  undefined1 *local_1c;
  undefined1 *local_18;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0;
  local_18 = abStack_4c;
  local_1c = abStack_4c;
  uStack_54 = 0x10009d97;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_4c,"");
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_8._0_1_ = 2;
  local_1c = abStack_68;
  local_20 = abStack_68;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_68,"INSITE");
  local_8 = (uint)local_8._1_3_ << 8;
  iVar1 = (**(code **)(**(int **)(param_1 + 0x28) + 0x10))();
  if (iVar1 != 0) {
    FUN_1000762c((short)iVar1 + 0x77,0x80004005);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  }
  return 0;
}



// Function: Catch@10009df7 at 10009df7

undefined4 Catch_10009df7(void)

{
  int unaff_EBP;
  
  FUN_100071c4((IID *)&DAT_1001e7e4,(WCHAR *)0x86,0,0,&DAT_1001e7d4,0x8000ffff,DAT_100272fc);
  LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + 8) + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10009ded;
}



// Function: FUN_10009e31 at 10009e31

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10009e31(int param_1)

{
  int iVar1;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_68 [20];
  undefined4 uStack_54;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_4c [44];
  undefined1 *local_20;
  undefined1 *local_1c;
  undefined1 *local_18;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0;
  local_18 = abStack_4c;
  local_1c = abStack_4c;
  uStack_54 = 0x10009e56;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_4c,"");
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_8._0_1_ = 2;
  local_1c = abStack_68;
  local_20 = abStack_68;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_68,"COMMON");
  local_8 = (uint)local_8._1_3_ << 8;
  iVar1 = (**(code **)(**(int **)(param_1 + 0x28) + 0x10))();
  if (iVar1 != 0) {
    FUN_1000762c((short)iVar1 + 0x77,0x80004005);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  }
  return 0;
}



// Function: Catch@10009eb6 at 10009eb6

undefined4 Catch_10009eb6(void)

{
  int unaff_EBP;
  
  FUN_100071c4((IID *)&DAT_1001e7e4,(WCHAR *)0x86,0,0,&DAT_1001e7d4,0x8000ffff,DAT_100272fc);
  LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + 8) + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10009eac;
}



// Function: FUN_10009ef0 at 10009ef0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10009ef0(void *this,void *param_1,undefined4 *param_2)

{
  FUN_1000785e(this,param_1,param_2);
  return param_1;
}



// Function: FUN_10009f21 at 10009f21

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10009f21(void *this,void *param_1)

{
  FUN_10007890(this,param_1);
  return param_1;
}



// Function: FUN_10009f4f at 10009f4f

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10009f4f(undefined2 *param_1,LPCWSTR param_2,undefined4 *param_3,int param_4)

{
  undefined4 *puVar1;
  void *this;
  int local_78 [2];
  undefined2 *local_70;
  int local_6c [2];
  char local_61;
  int local_60 [9];
  int local_3c [2];
  undefined4 local_34 [11];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x6c;
  local_70 = param_1;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  local_6c[0] = param_4;
  local_6c[1] = 0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 3;
  FUN_1000737d(local_6c,local_78,param_2,0xf003f);
  local_8._0_1_ = 5;
  FUN_10006cfd(local_6c);
  puVar1 = (undefined4 *)FUN_10009ef0(local_78,local_3c,param_3);
  local_8._0_1_ = 7;
  local_61 = FUN_100073bf(puVar1);
  local_8._0_1_ = 5;
  FUN_1000749c(local_3c);
  if (local_61 != '\0') {
    this = FUN_10009ef0(local_78,local_60,param_3);
    local_8._0_1_ = 8;
    FUN_10009f21(this,local_34);
    local_8._0_1_ = 9;
    FUN_10002017(param_1,local_34);
    local_8._0_1_ = 8;
    FID_conflict__Tidy(local_34,'\x01',0);
    local_8._0_1_ = 5;
    FUN_1000749c(local_60);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10006cfd(local_78);
  local_8 = 0;
  FUN_1000a04f();
  return;
}



// Function: Catch@1000a042 at 1000a042

undefined * Catch_1000a042(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_1000a04c;
}



// Function: FUN_1000a04f at 1000a04f

void FUN_1000a04f(void)

{
  FUN_100173ae();
  return;
}



// Function: FUN_1000a057 at 1000a057

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000a057(uint param_1,undefined4 param_2,LPCWSTR param_3,undefined4 param_4,int *param_5,
                 short param_6)

{
  uint uVar1;
  char *pcVar2;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_68 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_4c [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_30 [12];
  uint local_24;
  undefined4 uStack_20;
  LPCWSTR local_1c;
  undefined4 uStack_18;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x58;
  local_8 = 0x1000a063;
  local_24 = param_1;
  uStack_20 = param_2;
  local_1c = param_3;
  uStack_18 = param_4;
  uVar1 = param_1 & 0xffff;
  if (uVar1 == 3) {
    *param_5 = 1;
    param_5[1] = (int)param_3;
  }
  else if (uVar1 == 4) {
    *param_5 = 4;
    param_5[1] = (int)param_3;
  }
  else if (uVar1 == 8) {
    pcVar2 = (char *)FUN_10002170(local_68,param_3);
    local_8 = 0;
    if (0xf < *(uint *)(pcVar2 + 0x14)) {
      pcVar2 = *(char **)pcVar2;
    }
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_4c,pcVar2);
    local_8._0_1_ = 2;
    FUN_10001f4b(param_5 + 2,(undefined4 *)local_4c,0,0xffffffff);
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
              (local_4c,true,0);
    local_8 = 0xffffffff;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
              (local_68,true,0);
    *param_5 = (uint)(param_6 != 0) * 2 + 3;
  }
  else if (uVar1 == 0xb) {
    local_1c._0_1_ = SUB41(param_3,0);
    *param_5 = 2;
    *(undefined1 *)(param_5 + 1) = local_1c._0_1_;
  }
  else {
    param_5[1] = -1;
    *param_5 = 0;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_30,"");
    local_8 = 5;
    FUN_10001f4b(param_5 + 2,(undefined4 *)local_30,0,0xffffffff);
    local_8 = 0xffffffff;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
              (local_30,true,0);
  }
  FUN_1001739f();
  return;
}



// Function: FUN_1000a166 at 1000a166

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000a166(int param_1,int param_2,uint param_3,undefined4 param_4,LPCWSTR param_5,
                 undefined4 param_6)

{
  LPCRITICAL_SECTION lpCriticalSection;
  char cVar1;
  LPCWSTR pWVar2;
  int iVar3;
  char *pcVar4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar5;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_120 [20];
  undefined4 uStack_10c;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_104 [20];
  undefined4 uStack_f0;
  undefined4 uStack_e8;
  undefined4 uStack_e0;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_90 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_74 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_58 [28];
  int local_3c [2];
  undefined1 local_34;
  undefined4 local_24;
  undefined4 local_20;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x9c;
  local_8 = 0x1000a175;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xc);
  EnterCriticalSection(lpCriticalSection);
  local_8 = 0;
  if (param_2 == 0) {
    FUN_1000762c(0x76,0x80070057);
    LeaveCriticalSection(lpCriticalSection);
    goto LAB_1000a1af;
  }
  pWVar2 = (LPCWSTR)Ordinal_2();
  if (pWVar2 == (LPCWSTR)0x0) {
    FUN_1000154f(0x8007000e);
  }
  local_8._0_1_ = 1;
  iVar3 = Ordinal_7();
  if (iVar3 == 0) {
    FUN_1000762c(0x76,0x80070057);
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    pcVar4 = (char *)FUN_10002170(local_90,pWVar2);
    local_8._0_1_ = 2;
    if (0xf < *(uint *)(pcVar4 + 0x14)) {
      pcVar4 = *(char **)pcVar4;
    }
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_58,pcVar4);
    local_8._0_1_ = 5;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
              (local_90,true,0);
    uStack_e8 = 0x1000a23c;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &uStack_e0,local_58);
    local_8._0_1_ = 5;
    cVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x18))();
    pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_1002673c;
    if (cVar1 == '\0') {
      pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_10026758;
    }
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_74,pbVar5);
    local_20 = 0xf;
    local_24 = 0;
    local_34 = 0;
    local_8._0_1_ = 0xc;
    uStack_e0 = 0x1000a2aa;
    cVar1 = FUN_1000a057(param_3,param_4,param_5,param_6,local_3c,0);
    if (cVar1 == '\0') {
      FUN_1000762c(0x85,0x80004005);
      LeaveCriticalSection(lpCriticalSection);
      local_8._0_1_ = 9;
      FUN_100074ce((int)local_3c);
      local_8._0_1_ = 5;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_74,true,0);
    }
    else {
      uStack_f0 = 0x1000a2c6;
      FUN_100077d3(&uStack_e8,local_3c);
      local_8._0_1_ = 0xd;
      uStack_10c = 0x1000a2e4;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_104,local_58);
      local_8._0_1_ = 0xf;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_120,local_74);
      local_8._0_1_ = 0xc;
      iVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 0xc))();
      if (iVar3 == 0) {
LAB_1000a47e:
        local_8._0_1_ = 9;
        FUN_100074ce((int)local_3c);
        local_8._0_1_ = 5;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  (local_74,true,0);
        local_8._0_1_ = 1;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  (local_58,true,0);
        local_8 = (uint)local_8._1_3_ << 8;
        Ordinal_6();
        local_8 = 0xffffffff;
        LeaveCriticalSection(lpCriticalSection);
        FUN_1000a587();
        return;
      }
      if ((iVar3 == 3) && ((short)param_3 == 8)) {
        uStack_e0 = 0x1000a357;
        cVar1 = FUN_1000a057(param_3,param_4,param_5,param_6,local_3c,1);
        if (cVar1 != '\0') {
          uStack_f0 = 0x1000a373;
          FUN_100077d3(&uStack_e8,local_3c);
          local_8._0_1_ = 0x12;
          uStack_10c = 0x1000a391;
          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
          basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                    (abStack_104,local_58);
          local_8._0_1_ = 0x14;
          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
          basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                    (abStack_120,local_74);
          local_8._0_1_ = 0xc;
          iVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 0xc))();
          if (iVar3 == 0) goto LAB_1000a47e;
          FUN_1000762c((short)iVar3 + 0x77,0x80004005);
          LeaveCriticalSection(lpCriticalSection);
          local_8._0_1_ = 9;
          FUN_100074ce((int)local_3c);
          local_8._0_1_ = 5;
          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                    (local_74,true,0);
          goto LAB_1000a410;
        }
      }
      FUN_1000762c((short)iVar3 + 0x77,0x80004005);
      LeaveCriticalSection(lpCriticalSection);
      local_8._0_1_ = 9;
      FUN_100074ce((int)local_3c);
      local_8._0_1_ = 5;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_74,true,0);
    }
LAB_1000a410:
    local_8._0_1_ = 1;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
              (local_58,true,0);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6();
LAB_1000a1af:
  FUN_1000a587();
  return;
}



// Function: Catch@1000a545 at 1000a545

undefined * Catch_1000a545(void)

{
  int unaff_EBP;
  
  FUN_100071c4((IID *)&DAT_1001e7e4,(WCHAR *)0x86,0,0,&DAT_1001e7d4,0x8000ffff,DAT_100272fc);
  LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0xa4) + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000a582;
}



// Function: FUN_1000a587 at 1000a587

void FUN_1000a587(void)

{
  FUN_100173ae();
  return;
}



// Function: FUN_1000a58f at 1000a58f

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */
/* WARNING: Type propagation algorithm not settling */

void FUN_1000a58f(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  CComBSTR *pCVar4;
  char *pcVar5;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar6;
  uint *puVar7;
  short *psVar8;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_13c [20];
  undefined4 uStack_128;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_120 [20];
  undefined4 uStack_10c;
  undefined1 auStack_104 [8];
  undefined4 uStack_fc;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_e0 [12];
  undefined4 uStack_d4;
  int local_a0;
  LPCRITICAL_SECTION local_9c;
  int local_98 [2];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_90 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_74 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_58 [28];
  int local_3c [2];
  undefined1 local_34;
  undefined4 local_24;
  undefined4 local_20;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xa4;
  local_8 = 0x1000a59e;
  local_9c = (LPCRITICAL_SECTION)(param_1 + 0xc);
  EnterCriticalSection(local_9c);
  local_8 = 0;
  if ((param_2 == 0) || (param_3 == 0)) {
    FUN_1000762c(0x76,0x80070057);
    LeaveCriticalSection(local_9c);
    goto LAB_1000aa73;
  }
  FUN_100075c5(local_98,param_2);
  local_8._0_1_ = 1;
  FUN_100075e7(local_98 + 1,param_3);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar2 = FUN_10006df6(local_98,0);
  if (iVar2 == 0) {
LAB_1000aa38:
    FUN_1000762c(0x76,0x80070057);
    LeaveCriticalSection(local_9c);
  }
  else {
    iVar2 = FUN_10006df6(local_98 + 1,0);
    iVar3 = FUN_10006df6(local_98,0);
    if (iVar3 != iVar2) goto LAB_1000aa38;
    local_a0 = 0;
    while( true ) {
      iVar2 = FUN_10006df6(local_98,0);
      if (iVar2 <= local_a0) {
        Ordinal_22();
        local_98[1] = 0;
        Ordinal_22();
        local_98[0] = 0;
        local_8._0_1_ = 1;
        FUN_100070d7(local_98 + 1);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_100070d7(local_98);
        local_8 = 0xffffffff;
        uStack_d4 = 0x1000aa31;
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
        FUN_1000aab9();
        return;
      }
      pCVar4 = (CComBSTR *)FUN_10006ed0(local_98,local_a0);
      ATL::CComBSTR::CComBSTR((CComBSTR *)&local_9c,pCVar4);
      local_8._0_1_ = 3;
      pcVar5 = (char *)FUN_10002170(local_90,(LPCWSTR)local_9c);
      local_8._0_1_ = 4;
      if (0xf < *(uint *)(pcVar5 + 0x14)) {
        pcVar5 = *(char **)pcVar5;
      }
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_58,pcVar5);
      local_8._0_1_ = 7;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_90,true,0);
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_e0,local_58);
      local_8._0_1_ = 7;
      cVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x18))();
      pbVar6 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_1002673c;
      if (cVar1 == '\0') {
        pbVar6 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &DAT_10026758;
      }
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_74,pbVar6);
      local_20 = 0xf;
      local_24 = 0;
      local_34 = 0;
      local_8._0_1_ = 0xe;
      puVar7 = (uint *)FUN_10006e37(local_98 + 1,local_a0);
      uStack_fc = 0x1000a73f;
      cVar1 = FUN_1000a057(*puVar7,puVar7[1],(LPCWSTR)puVar7[2],puVar7[3],local_3c,0);
      if (cVar1 == '\0') break;
      uStack_10c = 0x1000a75b;
      FUN_100077d3(auStack_104,local_3c);
      local_8._0_1_ = 0xf;
      uStack_128 = 0x1000a779;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_120,local_58);
      local_8._0_1_ = 0x11;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                (abStack_13c,local_74);
      local_8._0_1_ = 0xe;
      iVar2 = (**(code **)(**(int **)(param_1 + 0x28) + 0xc))();
      if (iVar2 != 0) {
        if (iVar2 == 3) {
          psVar8 = (short *)FUN_10006e37(local_98 + 1,local_a0);
          if (*psVar8 == 8) {
            puVar7 = (uint *)FUN_10006e37(local_98 + 1,local_a0);
            uStack_fc = 0x1000a80c;
            cVar1 = FUN_1000a057(*puVar7,puVar7[1],(LPCWSTR)puVar7[2],puVar7[3],local_3c,1);
            if (cVar1 != '\0') {
              uStack_10c = 0x1000a828;
              FUN_100077d3(auStack_104,local_3c);
              local_8._0_1_ = 0x14;
              uStack_128 = 0x1000a846;
              std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
              basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        (abStack_120,local_58);
              local_8._0_1_ = 0x16;
              std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
              basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        (abStack_13c,local_74);
              local_8._0_1_ = 0xe;
              iVar2 = (**(code **)(**(int **)(param_1 + 0x28) + 0xc))();
              if (iVar2 != 0) {
                FUN_1000762c((short)iVar2 + 0x77,0x80004005);
                LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
                local_8._0_1_ = 0xb;
                FUN_100074ce((int)local_3c);
                local_8._0_1_ = 7;
                std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
                _Tidy(local_74,true,0);
                goto LAB_1000a8c3;
              }
              goto LAB_1000a950;
            }
          }
        }
        FUN_1000762c((short)iVar2 + 0x77,0x80004005);
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
        local_8._0_1_ = 0xb;
        FUN_100074ce((int)local_3c);
        local_8._0_1_ = 7;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  (local_74,true,0);
        goto LAB_1000a8c3;
      }
LAB_1000a950:
      local_8._0_1_ = 0xb;
      FUN_100074ce((int)local_3c);
      local_8._0_1_ = 7;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_74,true,0);
      local_8._0_1_ = 3;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                (local_58,true,0);
      local_8 = CONCAT31(local_8._1_3_,2);
      Ordinal_6();
      local_a0 = local_a0 + 1;
    }
    FUN_1000762c(0x77,0x80004005);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    local_8._0_1_ = 0xb;
    FUN_100074ce((int)local_3c);
    local_8._0_1_ = 7;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
              (local_74,true,0);
LAB_1000a8c3:
    local_8._0_1_ = 3;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
              (local_58,true,0);
    local_8 = CONCAT31(local_8._1_3_,2);
    Ordinal_6();
  }
  local_8._0_1_ = 1;
  FUN_100070d7(local_98 + 1);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_100070d7(local_98);
LAB_1000aa73:
  FUN_1000aab9();
  return;
}



// Function: Catch@1000aa77 at 1000aa77

undefined * Catch_1000aa77(void)

{
  int unaff_EBP;
  
  FUN_100071c4((IID *)&DAT_1001e7e4,(WCHAR *)0x86,0,0,&DAT_1001e7d4,0x8000ffff,DAT_100272fc);
  LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0xac) + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000aab4;
}



// Function: FUN_1000aab9 at 1000aab9

void FUN_1000aab9(void)

{
  FUN_100173ae();
  return;
}



// Function: FUN_1000aac1 at 1000aac1

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Removing unreachable block (ram,0x1000ad05) */
/* WARNING: Removing unreachable block (ram,0x1000ad26) */
/* WARNING: Removing unreachable block (ram,0x1000ad62) */
/* WARNING: Removing unreachable block (ram,0x1000ada0) */
/* WARNING: Removing unreachable block (ram,0x1000adde) */
/* WARNING: Removing unreachable block (ram,0x1000ae1c) */
/* WARNING: Removing unreachable block (ram,0x1000ae3a) */
/* WARNING: Removing unreachable block (ram,0x1000ae58) */
/* WARNING: Removing unreachable block (ram,0x1000ae5a) */
/* WARNING: Removing unreachable block (ram,0x1000ac90) */
/* WARNING: Removing unreachable block (ram,0x1000acb1) */
/* WARNING: Removing unreachable block (ram,0x1000aeed) */
/* WARNING: Removing unreachable block (ram,0x1000af76) */
/* WARNING: Removing unreachable block (ram,0x1000af8a) */

void FUN_1000aac1(void)

{
  code *pcVar1;
  uint uVar2;
  int local_ac;
  int *local_a8;
  LPCOLESTR local_a4;
  LPCWSTR *local_84 [5];
  uint local_70;
  undefined4 **local_68 [5];
  uint local_54;
  undefined4 local_4c [7];
  WCHAR local_30 [6];
  uint local_24 [7];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xd0;
  local_a8 = (int *)0x0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 5;
  FUN_10002561((undefined4 *)&stack0xffffff24);
  local_8._0_1_ = 10;
  FUN_10001fe5(local_4c,(wchar_t *)PTR_u_XMLResources_10026738);
  local_8._0_1_ = 0xb;
  FUN_10001fe5(local_30,(wchar_t *)PTR_u_Software_Cummins_Intelect_Insite_10026734);
  local_8._0_1_ = 0xc;
  FUN_10009f4f((undefined2 *)local_68,local_30,local_4c,-0x7ffffffe);
  local_8._0_1_ = 0xe;
  FID_conflict__Tidy(local_30,'\x01',0);
  local_8._0_1_ = 0xf;
  FID_conflict__Tidy(local_4c,'\x01',0);
  if (local_54 < 8) {
    local_68[0] = local_68;
  }
  if ((undefined4 ***)local_68[0] == (undefined4 ***)0x0) {
    local_ac = 0;
  }
  else {
    local_ac = Ordinal_2();
    if (local_ac == 0) goto LAB_1000afbf;
  }
  local_8._0_1_ = 0x10;
  FUN_10001fe5(local_84,(wchar_t *)PTR_u_InsitePersistenceSettings_xml_10026730);
  local_8._0_1_ = 0x11;
  if (local_70 < 8) {
    local_84[0] = (LPCWSTR *)local_84;
  }
  uVar2 = lstrlenW((LPCWSTR)local_84[0]);
  FUN_100023eb(&local_ac,local_84[0],uVar2);
  local_a4 = (LPCOLESTR)Ordinal_2();
  if (local_a4 != (LPCOLESTR)0x0) {
    local_8._0_1_ = 0x12;
    FUN_10006e83(&local_a8,local_a4,(LPUNKNOWN)0x0,0x17);
    local_8._0_1_ = 0x11;
    Ordinal_6();
    if (local_a8 != (int *)0x0) {
      (**(code **)(*local_a8 + 0x110))();
      local_24[0] = local_24[0] & 0xffff0000;
      FUN_10006f1d(local_24,(CComBSTR *)&local_ac);
      local_8._0_1_ = 0x13;
      (**(code **)(*local_a8 + 0xe8))(local_a8);
      local_8._0_1_ = 0x11;
      Ordinal_9(local_24);
    }
    local_8._0_1_ = 0x10;
    FID_conflict__Tidy(local_84,'\x01',0);
    local_8._0_1_ = 0xf;
    Ordinal_6();
    local_8._0_1_ = 10;
    FID_conflict__Tidy(local_68,'\x01',0);
    local_8._0_1_ = 9;
    Ordinal_6();
    local_8._0_1_ = 8;
    Ordinal_6();
    local_8._0_1_ = 7;
    Ordinal_6();
    local_8._0_1_ = 6;
    Ordinal_6();
    local_8._0_1_ = 5;
    FUN_1000258e((int *)&stack0xffffff24);
    local_8 = 0xffffffff;
    if (local_a8 != (int *)0x0) {
      (**(code **)(*local_a8 + 8))();
    }
    FUN_1001739f();
    return;
  }
LAB_1000afbf:
  FUN_1000154f(0x8007000e);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



// Function: FUN_1000afca at 1000afca

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_1000afca(int param_1)

{
  bool bVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined3 extraout_var;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_338 [20];
  undefined4 uStack_324;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_31c [20];
  undefined4 uStack_308;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_300 [20];
  undefined4 uStack_2ec;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_2e4 [20];
  undefined4 uStack_2d0;
  void *in_stack_fffffd38;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_2a4 [20];
  undefined4 uStack_290;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_288 [20];
  undefined4 uStack_274;
  void *in_stack_fffffd94;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_248 [20];
  undefined4 uStack_234;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_22c [20];
  undefined4 uStack_218;
  void *in_stack_fffffdf0;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_1ec [20];
  undefined4 uStack_1d8;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_1d0 [20];
  undefined4 uStack_1bc;
  undefined1 auStack_1b4 [24];
  undefined4 uStack_19c;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_190 [20];
  undefined4 uStack_17c;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_174 [20];
  undefined4 uStack_160;
  void *in_stack_fffffea8;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_134 [20];
  undefined4 uStack_120;
  undefined4 uStack_118;
  byte *in_stack_fffffef0;
  undefined1 local_e1;
  undefined1 *local_e0;
  undefined1 *local_dc;
  undefined1 *local_d8;
  undefined1 *local_d4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_d0 [28];
  undefined4 local_b4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_b0 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_94 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_78 [28];
  undefined1 local_5c [8];
  undefined1 local_54 [16];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_38 [2];
  undefined1 local_30;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xd4;
  local_8 = 0x1000afd9;
  local_e0 = &stack0xfffffef0;
  local_d4 = &stack0xfffffef0;
  uStack_118 = 0x1000aff6;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xfffffef0,
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_1002673c);
  local_8 = 1;
  FUN_1000dc30(&local_e1);
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),3);
  puVar3 = FUN_1000dc50(in_stack_fffffef0);
  *(undefined4 **)(param_1 + 0x2c) = puVar3;
  local_8 = 0xffffffff;
  FUN_1000dc40();
  FUN_1000b750();
  iVar4 = FUN_1000d910();
  *(int *)(param_1 + 0x28) = iVar4;
  FUN_1000aac1();
  (**(code **)**(undefined4 **)(param_1 + 0x28))();
  local_40 = 0xf;
  local_44 = 0;
  local_54[0] = 0;
  local_8 = 6;
  local_d4 = (undefined1 *)&uStack_118;
  local_e0 = (undefined1 *)&uStack_118;
  uStack_120 = 0x1000b085;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &uStack_118,
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_10026800);
  local_8._0_1_ = 8;
  local_e0 = abStack_134;
  local_d8 = abStack_134;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            (abStack_134,
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_10026758);
  local_8._0_1_ = 6;
  iVar4 = (**(code **)(**(int **)(param_1 + 0x28) + 8))();
  if ((iVar4 == 0) || (iVar4 == 0xe)) {
    bVar1 = FUN_10007125(local_54,(undefined4 *)&DAT_1002681c);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      FUN_100074fa(local_d0);
      local_8._0_1_ = 0xb;
      cVar2 = FUN_1000792d(local_d0);
      if (cVar2 != '\0') {
        local_1c = 0xf;
        local_20 = 0;
        local_30 = 0;
        local_8._0_1_ = 0xe;
        local_d8 = &stack0xfffffea8;
        local_d4 = &stack0xfffffea8;
        uStack_160 = 0x1000b138;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &stack0xfffffea8,local_d0);
        local_8._0_1_ = 0xe;
        FUN_1000c810(in_stack_fffffea8);
        uStack_160 = 0x1000b156;
        local_d8 = &stack0xfffffea8;
        FUN_100077d3(&stack0xfffffea8,local_38);
        local_8._0_1_ = 0x11;
        local_d4 = abStack_174;
        local_e0 = abStack_174;
        uStack_17c = 0x1000b175;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (abStack_174,
                   (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &DAT_10026774);
        local_8._0_1_ = 0x13;
        local_e0 = abStack_190;
        local_dc = abStack_190;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (abStack_190,
                   (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &DAT_10026758);
        local_8._0_1_ = 0xe;
        (**(code **)(**(int **)(param_1 + 0x28) + 0xc))();
        uStack_19c = 0x1000b1af;
        FUN_1000b770(local_b4,local_38);
        local_dc = auStack_1b4;
        uStack_1bc = 0x1000b1c3;
        FUN_100077d3(auStack_1b4,local_38);
        local_8._0_1_ = 0x16;
        local_d8 = abStack_1d0;
        local_d4 = abStack_1d0;
        uStack_1d8 = 0x1000b1e2;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (abStack_1d0,
                   (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &DAT_10026790);
        local_8._0_1_ = 0x18;
        local_d4 = abStack_1ec;
        local_e0 = abStack_1ec;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (abStack_1ec,
                   (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &DAT_10026758);
        local_8._0_1_ = 0xe;
        (**(code **)(**(int **)(param_1 + 0x28) + 0xc))();
        local_dc = &stack0xfffffdf0;
        local_d8 = &stack0xfffffdf0;
        uStack_218 = 0x1000b22f;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &stack0xfffffdf0,local_b0);
        local_8._0_1_ = 0xe;
        FUN_1000c810(in_stack_fffffdf0);
        uStack_218 = 0x1000b24d;
        local_dc = &stack0xfffffdf0;
        FUN_100077d3(&stack0xfffffdf0,local_38);
        local_8._0_1_ = 0x1d;
        local_d8 = abStack_22c;
        local_d4 = abStack_22c;
        uStack_234 = 0x1000b26c;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (abStack_22c,
                   (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &DAT_100267ac);
        local_8._0_1_ = 0x1f;
        local_d4 = abStack_248;
        local_e0 = abStack_248;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (abStack_248,
                   (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &DAT_10026758);
        local_8._0_1_ = 0xe;
        (**(code **)(**(int **)(param_1 + 0x28) + 0xc))();
        local_dc = &stack0xfffffd94;
        local_d8 = &stack0xfffffd94;
        uStack_274 = 0x1000b2b9;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &stack0xfffffd94,local_94);
        local_8._0_1_ = 0xe;
        FUN_1000c810(in_stack_fffffd94);
        uStack_274 = 0x1000b2d7;
        local_dc = &stack0xfffffd94;
        FUN_100077d3(&stack0xfffffd94,local_38);
        local_8._0_1_ = 0x24;
        local_d8 = abStack_288;
        local_d4 = abStack_288;
        uStack_290 = 0x1000b2f6;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (abStack_288,
                   (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &DAT_100267c8);
        local_8._0_1_ = 0x26;
        local_d4 = abStack_2a4;
        local_e0 = abStack_2a4;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (abStack_2a4,
                   (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &DAT_10026758);
        local_8._0_1_ = 0xe;
        (**(code **)(**(int **)(param_1 + 0x28) + 0xc))();
        local_dc = &stack0xfffffd38;
        local_d8 = &stack0xfffffd38;
        uStack_2d0 = 0x1000b340;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &stack0xfffffd38,local_78);
        local_8._0_1_ = 0xe;
        FUN_1000c810(in_stack_fffffd38);
        uStack_2d0 = 0x1000b35e;
        local_dc = &stack0xfffffd38;
        FUN_100077d3(&stack0xfffffd38,local_38);
        local_8._0_1_ = 0x2b;
        local_d8 = abStack_2e4;
        local_d4 = abStack_2e4;
        uStack_2ec = 0x1000b37d;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (abStack_2e4,
                   (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &DAT_100267e4);
        local_8._0_1_ = 0x2d;
        local_d4 = abStack_300;
        local_e0 = abStack_300;
        uStack_308 = 0x1000b398;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (abStack_300,
                   (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &DAT_10026758);
        local_8._0_1_ = 0xe;
        (**(code **)(**(int **)(param_1 + 0x28) + 0xc))();
        local_dc = abStack_31c;
        local_d8 = abStack_31c;
        uStack_324 = 0x1000b3c3;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_31c,"")
        ;
        local_8._0_1_ = 0x31;
        local_d8 = abStack_338;
        local_d4 = abStack_338;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (abStack_338,
                   (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &DAT_10026758);
        local_8._0_1_ = 0xe;
        (**(code **)(**(int **)(param_1 + 0x28) + 0x1c))();
        local_8._0_1_ = 0xb;
        FUN_100074ce((int)local_38);
      }
      local_8 = CONCAT31(local_8._1_3_,6);
      FUN_1000755b(local_d0);
    }
  }
  local_8 = 0xffffffff;
  FUN_100074ce((int)local_5c);
  FUN_1001739f();
  return;
}



// Function: FUN_1000b41b at 1000b41b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000b41b(int param_1)

{
  *(undefined4 *)(param_1 + 8) = 0;
  FUN_1000335a((void *)(param_1 + 0xc));
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  FUN_1000afca(param_1);
  return param_1;
}



// Function: FUN_1000b460 at 1000b460

undefined4 __fastcall FUN_1000b460(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}



// Function: FUN_1000b470 at 1000b470

uint __thiscall FUN_1000b470(void *this,uint param_1,uint param_2,void *param_3,uint param_4)

{
  uint extraout_EAX;
  uint uVar1;
  undefined4 *extraout_ECX;
  
  uVar1 = *(uint *)((int)this + 0x10);
  if (uVar1 < param_1) {
    std::_Xout_of_range("invalid string position");
    uVar1 = extraout_EAX;
    this = extraout_ECX;
  }
  if (uVar1 - param_1 < param_2) {
    param_2 = uVar1 - param_1;
  }
  uVar1 = param_2;
  if (param_4 <= param_2) {
    uVar1 = param_4;
  }
  if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    this = *this;
  }
  uVar1 = FUN_10006c69((void *)((int)this + param_1),param_3,uVar1);
  if (uVar1 == 0) {
    if (param_2 < param_4) {
      return 0xffffffff;
    }
    uVar1 = (uint)(param_2 != param_4);
  }
  return uVar1;
}



// Function: FUN_1000b4e0 at 1000b4e0

undefined4 * __fastcall FUN_1000b4e0(undefined4 *param_1)

{
  if (0xf < (uint)param_1[5]) {
    param_1 = (undefined4 *)*param_1;
  }
  return param_1;
}



// Function: FUN_1000b4f0 at 1000b4f0

int * __thiscall FUN_1000b4f0(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    if (uVar1 == 0xffffffff) {
      std::_Xlength_error("string too long");
      puVar5 = extraout_EDX_01;
    }
    if (*(uint *)((int)this + 0x14) < uVar1) {
      FUN_10001c84(this,uVar1);
      puVar5 = param_1;
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
    if (0xf < (uint)puVar5[5]) {
      puVar5 = (undefined4 *)*puVar5;
    }
    pvVar3 = this;
    if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar3 = *this;
    }
    memcpy((void *)(*(int *)((int)this + 0x10) + (int)pvVar3),(void *)((int)puVar5 + param_2),
           param_3);
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



// Function: FUN_1000b5e0 at 1000b5e0

int * __thiscall FUN_1000b5e0(void *this,int *param_1,uint param_2)

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
    if (0xf < uVar1) {
                    /* WARNING: Load size is inaccurate */
      piVar2 = *this;
    }
    if (piVar2 <= param_1) {
      pvVar4 = this;
      if (0xf < uVar1) {
                    /* WARNING: Load size is inaccurate */
        pvVar4 = *this;
      }
      if (param_1 < (int *)(*(int *)((int)this + 0x10) + (int)pvVar4)) {
        if (0xf < uVar1) {
                    /* WARNING: Load size is inaccurate */
          piVar2 = FUN_1000b4f0(this,(undefined4 *)this,(int)param_1 - *this,param_2);
          return piVar2;
        }
        piVar2 = FUN_1000b4f0(this,(undefined4 *)this,(int)param_1 - (int)this,param_2);
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
    if (uVar1 == 0xffffffff) {
      std::_Xlength_error("string too long");
      piVar2 = extraout_EDX_00;
    }
    if (*(uint *)((int)this + 0x14) < uVar1) {
      FUN_10001c84(this,uVar1);
      piVar2 = param_1;
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
    pvVar4 = this;
    if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar4 = *this;
    }
    memcpy((void *)(*(int *)((int)this + 0x10) + (int)pvVar4),piVar2,param_2);
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



// Function: FUN_1000b700 at 1000b700

void __thiscall FUN_1000b700(void *this,undefined4 *param_1)

{
  FUN_1000b4f0(this,param_1,0,0xffffffff);
  return;
}



// Function: FUN_1000b720 at 1000b720

void __thiscall FUN_1000b720(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_1;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 1);
  } while ((char)iVar1 != '\0');
  FUN_1000b5e0(this,param_1,(int)piVar2 - ((int)param_1 + 1));
  return;
}



// Function: FUN_1000b750 at 1000b750

void FUN_1000b750(void)

{
  if (DAT_100272c4 != (int *)0x0) {
    (**(code **)(*DAT_100272c4 + 0x20))(1);
    DAT_100272c4 = (int *)0x0;
  }
  return;
}



// Function: FUN_1000b770 at 1000b770

undefined4 __cdecl FUN_1000b770(undefined4 param_1,undefined4 *param_2)

{
  *param_2 = 1;
  param_2[1] = param_1;
  return 0;
}



// Function: FUN_1000b790 at 1000b790

void __fastcall FUN_1000b790(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  iVar2 = *param_1;
  if (*(char *)(iVar2 + 0x2d) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x2d) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x2d);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x2d);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *param_1 = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x2d);
    while ((cVar1 == '\0' && (*param_1 == *(int *)(iVar2 + 8)))) {
      *param_1 = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x2d);
    }
    *param_1 = iVar2;
  }
  return;
}



// Function: FUN_1000b7e0 at 1000b7e0

bool __thiscall FUN_1000b7e0(void *this,byte *param_1)

{
  byte bVar1;
  bool bVar2;
  
  if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    this = *this;
  }
  while( true ) {
                    /* WARNING: Load size is inaccurate */
    bVar1 = *this;
    bVar2 = bVar1 < *param_1;
    if (bVar1 != *param_1) break;
    if (bVar1 == 0) {
      return true;
    }
    bVar1 = *(byte *)((int)this + 1);
    bVar2 = bVar1 < param_1[1];
    if (bVar1 != param_1[1]) break;
    this = (void *)((int)this + 2);
    param_1 = param_1 + 2;
    if (bVar1 == 0) {
      return true;
    }
  }
  return 1 - bVar2 == (uint)(bVar2 != 0);
}



// Function: FUN_1000b830 at 1000b830

bool FUN_1000b830(void *param_1,undefined4 *param_2)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = param_2 + 4;
  if (0xf < (uint)param_2[5]) {
    param_2 = (undefined4 *)*param_2;
  }
  uVar2 = FUN_1000b470(param_1,0,*(uint *)((int)param_1 + 0x10),param_2,*puVar1);
  return (int)uVar2 < 0;
}



// Function: FUN_1000b860 at 1000b860

/* WARNING: Removing unreachable block (ram,0x1000b9b8) */

void __thiscall FUN_1000b860(void *this,int *param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *local_18;
  undefined4 *local_10;
  undefined4 *local_8;
  
  local_18 = *(undefined4 **)((int)this + 4);
  local_8 = (undefined4 *)local_18[1];
  local_10 = local_18;
  if (*(char *)((int)local_8 + 0x2d) == '\0') {
    uVar1 = param_2[4];
    uVar2 = param_2[5];
    do {
      puVar8 = local_8 + 3;
      puVar6 = param_2;
      if (0xf < uVar2) {
        puVar6 = (undefined4 *)*param_2;
      }
      uVar3 = local_8[7];
      uVar5 = uVar1;
      if (uVar3 < uVar1) {
        uVar5 = uVar3;
      }
      uVar7 = local_8[8];
      puVar4 = puVar8;
      if (0xf < uVar7) {
        puVar4 = (undefined4 *)*puVar8;
      }
      uVar5 = FUN_10006c69(puVar4,puVar6,uVar5);
      if (uVar5 == 0) {
        if (uVar1 <= uVar3) {
          uVar5 = (uint)(uVar3 != uVar1);
          goto LAB_1000b8f1;
        }
LAB_1000b8f3:
        local_8 = (undefined4 *)local_8[2];
      }
      else {
LAB_1000b8f1:
        if ((int)uVar5 < 0) goto LAB_1000b8f3;
        if (*(char *)((int)local_10 + 0x2d) != '\0') {
          if (0xf < uVar7) {
            puVar8 = (undefined4 *)*puVar8;
          }
          uVar5 = param_2[4];
          if (uVar1 < (uint)param_2[4]) {
            uVar5 = uVar1;
          }
          uVar7 = uVar5;
          if (uVar3 <= uVar5) {
            uVar7 = uVar3;
          }
          puVar6 = param_2;
          if (0xf < uVar2) {
            puVar6 = (undefined4 *)*param_2;
          }
          uVar7 = FUN_10006c69(puVar6,puVar8,uVar7);
          if (uVar7 == 0) {
            if (uVar3 <= uVar5) {
              uVar7 = (uint)(uVar5 != uVar3);
              goto LAB_1000b947;
            }
          }
          else {
LAB_1000b947:
            if (-1 < (int)uVar7) goto LAB_1000b954;
          }
          local_10 = local_8;
        }
LAB_1000b954:
        local_18 = local_8;
        local_8 = (undefined4 *)*local_8;
      }
    } while (*(char *)((int)local_8 + 0x2d) == '\0');
  }
  if (*(char *)((int)local_10 + 0x2d) == '\0') {
    puVar6 = (undefined4 *)*local_10;
  }
  else {
    puVar6 = *(undefined4 **)(*(int *)((int)this + 4) + 4);
  }
  if (*(char *)((int)puVar6 + 0x2d) == '\0') {
    uVar1 = param_2[4];
    uVar2 = param_2[5];
    do {
      uVar3 = puVar6[7];
      puVar8 = puVar6 + 3;
      if (0xf < (uint)puVar6[8]) {
        puVar8 = (undefined4 *)*puVar8;
      }
      uVar5 = uVar1;
      if (uVar3 <= uVar1) {
        uVar5 = uVar3;
      }
      puVar4 = param_2;
      if (0xf < uVar2) {
        puVar4 = (undefined4 *)*param_2;
      }
      uVar5 = FUN_10006c69(puVar4,puVar8,uVar5);
      if (uVar5 == 0) {
        if (uVar3 <= uVar1) {
          uVar5 = (uint)(uVar1 != uVar3);
          goto LAB_1000b9e7;
        }
LAB_1000b9e9:
        puVar8 = (undefined4 *)*puVar6;
        local_10 = puVar6;
      }
      else {
LAB_1000b9e7:
        if ((int)uVar5 < 0) goto LAB_1000b9e9;
        puVar8 = (undefined4 *)puVar6[2];
      }
      puVar6 = puVar8;
    } while (*(char *)((int)puVar8 + 0x2d) == '\0');
  }
  *param_1 = (int)local_18;
  param_1[1] = (int)local_10;
  return;
}



// Function: FUN_1000ba10 at 1000ba10

void __fastcall FUN_1000ba10(undefined4 *param_1)

{
  if (0xf < (uint)param_1[5]) {
    operator_delete((void *)*param_1);
  }
  param_1[5] = 0xf;
  param_1[4] = 0;
  *(undefined1 *)param_1 = 0;
  return;
}



// Function: FUN_1000ba40 at 1000ba40

exception * __thiscall FUN_1000ba40(void *this,byte param_1)

{
  *(undefined ***)this = pcl_os::Exception::vftable;
  if (0xf < *(uint *)((int)this + 0x3c)) {
    operator_delete(*(void **)((int)this + 0x28));
  }
  *(undefined4 *)((int)this + 0x3c) = 0xf;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined1 *)((int)this + 0x28) = 0;
  if (0xf < *(uint *)((int)this + 0x20)) {
    operator_delete(*(void **)((int)this + 0xc));
  }
  *(undefined4 *)((int)this + 0x20) = 0xf;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined1 *)((int)this + 0xc) = 0;
  std::exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (exception *)this;
}



// Function: FUN_1000bab0 at 1000bab0

undefined4 * __thiscall FUN_1000bab0(void *this,int *param_1,undefined4 param_2)

{
  FUN_1000dd70(this,param_1,param_2);
  *(undefined ***)this = SharedConfigurationLibrary::SCLException::vftable;
  return (undefined4 *)this;
}



// Function: FUN_1000bae0 at 1000bae0

void __fastcall FUN_1000bae0(exception *param_1)

{
  *(undefined ***)param_1 = pcl_os::Exception::vftable;
  if (0xf < *(uint *)(param_1 + 0x3c)) {
    operator_delete(*(void **)(param_1 + 0x28));
  }
  *(undefined4 *)(param_1 + 0x3c) = 0xf;
  *(undefined4 *)(param_1 + 0x38) = 0;
  param_1[0x28] = (exception)0x0;
  if (0xf < *(uint *)(param_1 + 0x20)) {
    operator_delete(*(void **)(param_1 + 0xc));
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0xf;
  param_1[0xc] = (exception)0x0;
                    /* WARNING: Could not recover jumptable at 0x1000bb2e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(param_1);
  return;
}



// Function: FUN_1000bb40 at 1000bb40

undefined1 * __thiscall FUN_1000bb40(void *this,undefined1 *param_1)

{
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  FUN_10001f4b(param_1,(undefined4 *)((int)this + 4),0,0xffffffff);
  return param_1;
}



// Function: FUN_1000bb70 at 1000bb70

undefined4 __thiscall FUN_1000bb70(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 **ppuVar5;
  undefined4 **extraout_EAX;
  undefined4 **extraout_EAX_00;
  uint in_stack_00000014;
  uint in_stack_00000018;
  undefined4 *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a498;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = FUN_1000e100(this,&param_1);
  puVar1 = *(undefined4 **)((int)this + 4);
  if (local_14 != puVar1) {
    uVar2 = local_14[7];
    puVar3 = local_14 + 3;
    if (0xf < (uint)local_14[8]) {
      puVar3 = (undefined4 *)*puVar3;
    }
    uVar4 = in_stack_00000014;
    if (uVar2 <= in_stack_00000014) {
      uVar4 = uVar2;
    }
    ppuVar5 = (undefined4 **)param_1;
    if (in_stack_00000018 < 0x10) {
      ppuVar5 = &param_1;
    }
    uVar4 = FUN_10006c69(ppuVar5,puVar3,uVar4);
    if (uVar4 == 0) {
      if (in_stack_00000014 < uVar2) goto LAB_1000bbfa;
      uVar4 = (uint)(in_stack_00000014 != uVar2);
    }
    if (-1 < (int)uVar4) {
      ppuVar5 = &local_14;
      goto LAB_1000bc00;
    }
  }
LAB_1000bbfa:
  local_18 = puVar1;
  ppuVar5 = &local_18;
LAB_1000bc00:
  if (*ppuVar5 != puVar1) {
    if (0xf < in_stack_00000018) {
      operator_delete(param_1);
      ppuVar5 = extraout_EAX;
    }
    ExceptionList = local_10;
    return CONCAT31((int3)((uint)ppuVar5 >> 8),1);
  }
  if (0xf < in_stack_00000018) {
    operator_delete(param_1);
    ppuVar5 = extraout_EAX_00;
  }
  ExceptionList = local_10;
  return (uint)ppuVar5 & 0xffffff00;
}



// Function: FUN_1000bc60 at 1000bc60

undefined4 __thiscall FUN_1000bc60(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 **ppuVar6;
  uint in_stack_00000014;
  uint in_stack_00000018;
  undefined4 *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a498;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = FUN_1000e100(this,&param_1);
  puVar1 = *(undefined4 **)((int)this + 4);
  if (local_14 != puVar1) {
    uVar2 = local_14[7];
    puVar4 = local_14 + 3;
    if (0xf < (uint)local_14[8]) {
      puVar4 = (undefined4 *)*puVar4;
    }
    uVar5 = in_stack_00000014;
    if (uVar2 <= in_stack_00000014) {
      uVar5 = uVar2;
    }
    ppuVar6 = (undefined4 **)param_1;
    if (in_stack_00000018 < 0x10) {
      ppuVar6 = &param_1;
    }
    uVar5 = FUN_10006c69(ppuVar6,puVar4,uVar5);
    if (uVar5 == 0) {
      if (in_stack_00000014 < uVar2) goto LAB_1000bcea;
      uVar5 = (uint)(in_stack_00000014 != uVar2);
    }
    if (-1 < (int)uVar5) {
      ppuVar6 = &local_14;
      goto LAB_1000bcf0;
    }
  }
LAB_1000bcea:
  local_18 = puVar1;
  ppuVar6 = &local_18;
LAB_1000bcf0:
  if (*ppuVar6 != puVar1) {
    uVar3 = (*ppuVar6)[10];
    if (0xf < in_stack_00000018) {
      operator_delete(param_1);
    }
    ExceptionList = local_10;
    return uVar3;
  }
  if (0xf < in_stack_00000018) {
    operator_delete(param_1);
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_1000bd50 at 1000bd50

undefined4 __thiscall FUN_1000bd50(void *this,void *param_1)

{
  char cVar1;
  char *pcVar2;
  void *this_00;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 uStack00000014;
  uint in_stack_00000018;
  void *in_stack_00000020;
  uint in_stack_00000034;
  undefined4 *in_stack_0000003c;
  uint uVar5;
  void *pvVar6;
  uint in_stack_ffffffbc;
  undefined4 *puVar7;
  undefined4 local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a4d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_1000de70(&local_18,(undefined4 *)((int)this + 4));
  local_8._0_1_ = 2;
  pcVar2 = (char *)FUN_1000b4e0(&param_1);
  local_14 = pcVar2 + 1;
  puVar7 = (undefined4 *)(in_stack_ffffffbc & 0xffffff00);
  pcVar4 = pcVar2;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xffffffbc,pcVar2,(int)pcVar4 - (int)local_14);
  uVar5 = 0x1000bdd9;
  this_00 = (void *)FUN_1000bc60((void *)((int)this + 8),puVar7);
  if (this_00 != (void *)0x0) {
    local_14 = &stack0xffffffb8;
    pvVar6 = (void *)(uVar5 & 0xffffff00);
    FUN_10001f4b(&stack0xffffffb8,&stack0x00000020,0,0xffffffff);
    uVar3 = FUN_1000e5a0(this_00,pvVar6);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_1000de90(&local_18);
    if (0xf < in_stack_00000018) {
      operator_delete(param_1);
    }
    in_stack_00000018 = 0xf;
    uStack00000014 = 0;
    param_1 = (void *)((uint)param_1 & 0xffffff00);
    if (0xf < in_stack_00000034) {
      operator_delete(in_stack_00000020);
    }
    ExceptionList = local_10;
    return uVar3;
  }
  *in_stack_0000003c = 0;
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_1000de90(&local_18);
  if (0xf < in_stack_00000018) {
    operator_delete(param_1);
  }
  in_stack_00000018 = 0xf;
  uStack00000014 = 0;
  param_1 = (void *)((uint)param_1 & 0xffffff00);
  if (0xf < in_stack_00000034) {
    operator_delete(in_stack_00000020);
  }
  ExceptionList = local_10;
  return 9;
}



// Function: FUN_1000bed0 at 1000bed0

undefined4 __thiscall FUN_1000bed0(void *this,void *param_1)

{
  char cVar1;
  char *pcVar2;
  void *this_00;
  char *pcVar3;
  undefined4 uStack00000014;
  uint in_stack_00000018;
  void *in_stack_00000020;
  undefined4 uStack00000030;
  uint in_stack_00000034;
  void *in_stack_00000044;
  uint in_stack_00000058;
  uint in_stack_ffffff94;
  void *pvVar4;
  uint in_stack_ffffffb8;
  undefined4 *puVar5;
  undefined4 local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a528;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
  FUN_1000de70(&local_18,(undefined4 *)((int)this + 4));
  local_8._0_1_ = 3;
  pcVar2 = (char *)FUN_1000b4e0(&param_1);
  local_14 = pcVar2 + 1;
  puVar5 = (undefined4 *)(in_stack_ffffffb8 & 0xffffff00);
  pcVar3 = pcVar2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xffffffb8,pcVar2,(int)pcVar3 - (int)local_14);
  this_00 = (void *)FUN_1000bc60((void *)((int)this + 8),puVar5);
  if (this_00 != (void *)0x0) {
    local_14 = &stack0xffffffb0;
    FUN_10001f4b(&stack0xffffffb8,&stack0x00000044,0,0xffffffff);
    local_8._0_1_ = 4;
    pvVar4 = (void *)(in_stack_ffffff94 & 0xffffff00);
    FUN_10001f4b(&stack0xffffff94,&stack0x00000020,0,0xffffffff);
    local_8._0_1_ = 3;
    local_14 = (char *)FUN_10010190(this_00,pvVar4);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_1000de90(&local_18);
    if (0xf < in_stack_00000018) {
      operator_delete(param_1);
    }
    in_stack_00000018 = 0xf;
    uStack00000014 = 0;
    param_1 = (void *)((uint)param_1 & 0xffffff00);
    if (0xf < in_stack_00000034) {
      operator_delete(in_stack_00000020);
    }
    in_stack_00000034 = 0xf;
    uStack00000030 = 0;
    in_stack_00000020 = (void *)((uint)in_stack_00000020 & 0xffffff00);
    if (0xf < in_stack_00000058) {
      operator_delete(in_stack_00000044);
    }
    ExceptionList = local_10;
    return local_14;
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_1000de90(&local_18);
  if (0xf < in_stack_00000018) {
    operator_delete(param_1);
  }
  in_stack_00000018 = 0xf;
  uStack00000014 = 0;
  param_1 = (void *)((uint)param_1 & 0xffffff00);
  if (0xf < in_stack_00000034) {
    operator_delete(in_stack_00000020);
  }
  in_stack_00000034 = 0xf;
  uStack00000030 = 0;
  in_stack_00000020 = (void *)((uint)in_stack_00000020 & 0xffffff00);
  if (0xf < in_stack_00000058) {
    operator_delete(in_stack_00000044);
  }
  ExceptionList = local_10;
  return 9;
}



// Function: FUN_1000c0b0 at 1000c0b0

int __thiscall FUN_1000c0b0(void *this,void *param_1)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  void *pvVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  undefined4 uStack00000014;
  uint in_stack_00000018;
  void *in_stack_00000020;
  uint in_stack_00000034;
  uint in_stack_ffffffb0;
  undefined4 *puVar8;
  void *pvVar9;
  undefined4 local_24;
  void *local_20;
  undefined1 *local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a5a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_1000de70(&local_24,(undefined4 *)((int)this + 4));
  local_8 = CONCAT31(local_8._1_3_,2);
  local_14 = 0;
  pcVar3 = (char *)FUN_1000b4e0(&param_1);
  local_1c = &stack0xffffffb0;
  puVar8 = (undefined4 *)(in_stack_ffffffb0 & 0xffffff00);
  pcVar6 = pcVar3;
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xffffffb0,pcVar3,(int)pcVar6 - (int)(pcVar3 + 1));
  local_20 = (void *)((int)this + 8);
  pvVar4 = (void *)FUN_1000bc60(local_20,puVar8);
  iVar7 = 0;
  if (pvVar4 == (void *)0x0) {
    iVar5 = FUN_1000b460((int)&param_1);
    if (iVar5 == 0) {
      local_1c = *(undefined1 **)((int)this + 0x10);
      if (0 < (int)local_1c) {
        do {
          if ((-1 < iVar7) && (iVar7 < *(int *)((int)local_20 + 8))) {
            piVar2 = *(int **)((int)local_20 + 4);
            local_18 = (int *)*piVar2;
            iVar5 = 0;
            while (local_18 != piVar2) {
              if (iVar5 == iVar7) {
                pvVar4 = (void *)local_18[10];
                if (pvVar4 != (void *)0x0) {
                  local_18 = (int *)&stack0xffffffb0;
                  puVar8 = (undefined4 *)((uint)puVar8 & 0xffffff00);
                  FUN_10001f4b(&stack0xffffffb0,&stack0x00000020,0,0xffffffff);
                  iVar5 = FUN_1000e680(pvVar4,puVar8);
                  if (iVar5 != 0) {
                    local_14 = iVar5;
                  }
                }
                break;
              }
              FUN_1000b790((int *)&local_18);
              iVar5 = iVar5 + 1;
            }
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < (int)local_1c);
      }
    }
    else {
      local_14 = 9;
    }
  }
  else {
    local_1c = &stack0xffffffb0;
    pvVar9 = (void *)((uint)puVar8 & 0xffffff00);
    FUN_10001f4b(&stack0xffffffb0,&stack0x00000020,0,0xffffffff);
    local_14 = FUN_1000e680(pvVar4,pvVar9);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_1000de90(&local_24);
  if (0xf < in_stack_00000018) {
    operator_delete(param_1);
  }
  in_stack_00000018 = 0xf;
  uStack00000014 = 0;
  param_1 = (void *)((uint)param_1 & 0xffffff00);
  if (0xf < in_stack_00000034) {
    operator_delete(in_stack_00000020);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_1000c260 at 1000c260

int __thiscall FUN_1000c260(void *this,void *param_1)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  int *piVar6;
  undefined4 uStack00000014;
  uint in_stack_00000018;
  void *in_stack_00000020;
  uint in_stack_00000034;
  uint in_stack_ffffffac;
  undefined4 *puVar7;
  undefined4 local_28;
  void *local_24;
  int local_20;
  undefined4 *local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a573;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_1000de70(&local_28,(undefined4 *)((int)this + 4));
  local_8._0_1_ = 2;
  local_18 = 0;
  local_1c = (undefined4 *)operator_new(8);
  local_8._0_1_ = 3;
  if (local_1c == (undefined4 *)0x0) {
    local_14 = (int *)0x0;
  }
  else {
    local_14 = FUN_10010960(local_1c);
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  pcVar3 = (char *)FUN_1000b4e0(&param_1);
  local_1c = (undefined4 *)&stack0xffffffac;
  puVar7 = (undefined4 *)(in_stack_ffffffac & 0xffffff00);
  pcVar5 = pcVar3;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xffffffac,pcVar3,(int)pcVar5 - (int)(pcVar3 + 1));
  local_24 = (void *)((int)this + 8);
  iVar4 = FUN_1000bc60(local_24,puVar7);
  if (iVar4 == 0) {
    iVar4 = FUN_1000b460((int)&param_1);
    piVar6 = local_14;
    if (iVar4 == 0) {
      local_1c = *(undefined4 **)((int)this + 0x10);
      local_20 = 0;
      if (0 < (int)local_1c) {
        do {
          if ((-1 < local_20) && (local_20 < *(int *)((int)local_24 + 8))) {
            piVar2 = *(int **)((int)local_24 + 4);
            local_14 = (int *)*piVar2;
            iVar4 = 0;
            while (local_14 != piVar2) {
              if (iVar4 == local_20) {
                iVar4 = local_14[10];
                if (iVar4 != 0) {
                  local_14 = (int *)&stack0xffffffac;
                  FUN_10001f4b(&stack0xffffffac,&stack0x00000020,0,0xffffffff);
                  iVar4 = (**(code **)(*piVar6 + 4))(iVar4);
                  if (iVar4 != 0) {
                    local_18 = iVar4;
                  }
                }
                break;
              }
              FUN_1000b790((int *)&local_14);
              iVar4 = iVar4 + 1;
            }
          }
          local_20 = local_20 + 1;
        } while (local_20 < (int)local_1c);
      }
    }
    else {
      local_18 = 9;
    }
  }
  else {
    local_1c = (undefined4 *)&stack0xffffffac;
    FUN_10001f4b(&stack0xffffffac,&stack0x00000020,0,0xffffffff);
    piVar6 = local_14;
    local_18 = (**(code **)(*local_14 + 4))(iVar4);
  }
  if (piVar6 != (int *)0x0) {
    (**(code **)*piVar6)();
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_1000de90(&local_28);
  if (0xf < in_stack_00000018) {
    operator_delete(param_1);
  }
  in_stack_00000018 = 0xf;
  uStack00000014 = 0;
  param_1 = (void *)((uint)param_1 & 0xffffff00);
  if (0xf < in_stack_00000034) {
    operator_delete(in_stack_00000020);
  }
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_1000c460 at 1000c460

byte __thiscall FUN_1000c460(void *this,void *param_1)

{
  char cVar1;
  int *piVar2;
  byte bVar3;
  char *pcVar4;
  void *pvVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  undefined4 uStack00000014;
  uint in_stack_00000018;
  void *in_stack_00000020;
  uint in_stack_00000034;
  uint in_stack_ffffffb0;
  undefined4 *puVar9;
  void *pvVar10;
  undefined4 local_24;
  void *local_20;
  undefined1 *local_1c;
  int *local_18;
  byte local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a5a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_1000de70(&local_24,(undefined4 *)((int)this + 4));
  local_8 = CONCAT31(local_8._1_3_,2);
  local_11 = 0;
  pcVar4 = (char *)FUN_1000b4e0(&param_1);
  local_1c = &stack0xffffffb0;
  puVar9 = (undefined4 *)(in_stack_ffffffb0 & 0xffffff00);
  pcVar7 = pcVar4;
  do {
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xffffffb0,pcVar4,(int)pcVar7 - (int)(pcVar4 + 1));
  local_20 = (void *)((int)this + 8);
  pvVar5 = (void *)FUN_1000bc60(local_20,puVar9);
  iVar8 = 0;
  if (pvVar5 == (void *)0x0) {
    iVar6 = FUN_1000b460((int)&param_1);
    if (iVar6 == 0) {
      local_1c = *(undefined1 **)((int)this + 0x10);
      if (0 < (int)local_1c) {
        do {
          if ((-1 < iVar8) && (iVar8 < *(int *)((int)local_20 + 8))) {
            piVar2 = *(int **)((int)local_20 + 4);
            local_18 = (int *)*piVar2;
            iVar6 = 0;
            while (local_18 != piVar2) {
              if (iVar6 == iVar8) {
                pvVar5 = (void *)local_18[10];
                if (pvVar5 != (void *)0x0) {
                  local_18 = (int *)&stack0xffffffb0;
                  puVar9 = (undefined4 *)((uint)puVar9 & 0xffffff00);
                  FUN_10001f4b(&stack0xffffffb0,&stack0x00000020,0,0xffffffff);
                  bVar3 = FUN_1000e7a0(pvVar5,puVar9);
                  local_11 = local_11 | bVar3;
                }
                break;
              }
              FUN_1000b790((int *)&local_18);
              iVar6 = iVar6 + 1;
            }
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < (int)local_1c);
      }
    }
    else {
      local_11 = 0;
    }
  }
  else {
    local_1c = &stack0xffffffb0;
    pvVar10 = (void *)((uint)puVar9 & 0xffffff00);
    FUN_10001f4b(&stack0xffffffb0,&stack0x00000020,0,0xffffffff);
    local_11 = FUN_1000e7a0(pvVar5,pvVar10);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_1000de90(&local_24);
  if (0xf < in_stack_00000018) {
    operator_delete(param_1);
  }
  in_stack_00000018 = 0xf;
  uStack00000014 = 0;
  param_1 = (void *)((uint)param_1 & 0xffffff00);
  if (0xf < in_stack_00000034) {
    operator_delete(in_stack_00000020);
  }
  ExceptionList = local_10;
  return local_11;
}



// Function: FUN_1000c610 at 1000c610

int __thiscall FUN_1000c610(void *this,void *param_1)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  int *piVar6;
  undefined4 uStack00000014;
  uint in_stack_00000018;
  void *in_stack_00000020;
  uint in_stack_00000034;
  uint in_stack_ffffffac;
  undefined4 *puVar7;
  undefined4 local_28;
  void *local_24;
  int local_20;
  undefined4 *local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a573;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_1000de70(&local_28,(undefined4 *)((int)this + 4));
  local_8._0_1_ = 2;
  local_18 = 0;
  local_1c = (undefined4 *)operator_new(8);
  local_8._0_1_ = 3;
  if (local_1c == (undefined4 *)0x0) {
    local_14 = (int *)0x0;
  }
  else {
    local_14 = FUN_10010960(local_1c);
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  pcVar3 = (char *)FUN_1000b4e0(&param_1);
  local_1c = (undefined4 *)&stack0xffffffac;
  puVar7 = (undefined4 *)(in_stack_ffffffac & 0xffffff00);
  pcVar5 = pcVar3;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xffffffac,pcVar3,(int)pcVar5 - (int)(pcVar3 + 1));
  local_24 = (void *)((int)this + 8);
  iVar4 = FUN_1000bc60(local_24,puVar7);
  if (iVar4 == 0) {
    iVar4 = FUN_1000b460((int)&param_1);
    piVar6 = local_14;
    if (iVar4 == 0) {
      local_1c = *(undefined4 **)((int)this + 0x10);
      local_20 = 0;
      if (0 < (int)local_1c) {
        do {
          if ((-1 < local_20) && (local_20 < *(int *)((int)local_24 + 8))) {
            piVar2 = *(int **)((int)local_24 + 4);
            local_14 = (int *)*piVar2;
            iVar4 = 0;
            while (local_14 != piVar2) {
              if (iVar4 == local_20) {
                iVar4 = local_14[10];
                if (iVar4 != 0) {
                  local_14 = (int *)&stack0xffffffac;
                  FUN_10001f4b(&stack0xffffffac,&stack0x00000020,0,0xffffffff);
                  iVar4 = (**(code **)(*piVar6 + 8))(iVar4);
                  if (iVar4 != 0) {
                    local_18 = iVar4;
                  }
                }
                break;
              }
              FUN_1000b790((int *)&local_14);
              iVar4 = iVar4 + 1;
            }
          }
          local_20 = local_20 + 1;
        } while (local_20 < (int)local_1c);
      }
    }
    else {
      local_18 = 9;
    }
  }
  else {
    local_1c = (undefined4 *)&stack0xffffffac;
    FUN_10001f4b(&stack0xffffffac,&stack0x00000020,0,0xffffffff);
    piVar6 = local_14;
    local_18 = (**(code **)(*local_14 + 8))(iVar4);
  }
  if (piVar6 != (int *)0x0) {
    (**(code **)*piVar6)();
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_1000de90(&local_28);
  if (0xf < in_stack_00000018) {
    operator_delete(param_1);
  }
  in_stack_00000018 = 0xf;
  uStack00000014 = 0;
  param_1 = (void *)((uint)param_1 & 0xffffff00);
  if (0xf < in_stack_00000034) {
    operator_delete(in_stack_00000020);
  }
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_1000c810 at 1000c810

undefined4 __cdecl FUN_1000c810(void *param_1)

{
  uint in_stack_00000018;
  int *in_stack_00000020;
  char in_stack_00000024;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a5d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  *in_stack_00000020 = (uint)(in_stack_00000024 != '\0') * 2 + 3;
  FUN_10001f4b(in_stack_00000020 + 2,&param_1,0,0xffffffff);
  if (0xf < in_stack_00000018) {
    operator_delete(param_1);
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_1000c880 at 1000c880

void __thiscall
FUN_1000c880(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  uint extraout_EAX;
  uint uVar4;
  int *piVar5;
  void *extraout_ECX;
  int *piVar6;
  int *piVar7;
  
  uVar4 = *(uint *)((int)this + 8);
  if (0x7fffffd < uVar4) {
    if (0xf < (uint)param_4[8]) {
      operator_delete((void *)param_4[3]);
    }
    param_4[8] = 0xf;
    param_4[7] = 0;
    *(undefined1 *)(param_4 + 3) = 0;
    operator_delete(param_4);
    std::_Xlength_error("map/set<T> too long");
    uVar4 = extraout_EAX;
    this = extraout_ECX;
  }
  *(uint *)((int)this + 8) = uVar4 + 1;
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
  cVar1 = *(char *)(param_4[1] + 0x2c);
  piVar5 = param_4;
  do {
    if (cVar1 != '\0') {
      iVar2 = *(int *)(*(int *)((int)this + 4) + 4);
      *param_1 = param_4;
      *(undefined1 *)(iVar2 + 0x2c) = 1;
      return;
    }
    piVar6 = (int *)piVar5[1];
    piVar7 = (int *)piVar6[1];
    if (piVar6 == (int *)*piVar7) {
      iVar2 = piVar7[2];
      if (*(char *)(iVar2 + 0x2c) == '\0') {
        *(undefined1 *)(piVar6 + 0xb) = 1;
        *(undefined1 *)(iVar2 + 0x2c) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
        piVar5 = *(int **)(piVar5[1] + 4);
      }
      else {
        if (piVar5 == (int *)piVar6[2]) {
          piVar5 = (int *)piVar6[2];
          piVar6[2] = *piVar5;
          if (*(char *)(*piVar5 + 0x2d) == '\0') {
            *(int **)(*piVar5 + 4) = piVar6;
          }
          piVar5[1] = piVar6[1];
          if (piVar6 == *(int **)(*(int *)((int)this + 4) + 4)) {
            *(int **)(*(int *)((int)this + 4) + 4) = piVar5;
          }
          else {
            piVar7 = (int *)piVar6[1];
            if (piVar6 == (int *)*piVar7) {
              *piVar7 = (int)piVar5;
            }
            else {
              piVar7[2] = (int)piVar5;
            }
          }
          *piVar5 = (int)piVar6;
          piVar6[1] = (int)piVar5;
          piVar5 = piVar6;
        }
        *(undefined1 *)(piVar5[1] + 0x2c) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
        piVar6 = *(int **)(piVar5[1] + 4);
        piVar7 = (int *)*piVar6;
        *piVar6 = piVar7[2];
        if (*(char *)(piVar7[2] + 0x2d) == '\0') {
          *(int **)(piVar7[2] + 4) = piVar6;
        }
        piVar7[1] = piVar6[1];
        if (piVar6 == *(int **)(*(int *)((int)this + 4) + 4)) {
          *(int **)(*(int *)((int)this + 4) + 4) = piVar7;
          piVar7[2] = (int)piVar6;
        }
        else {
          piVar3 = (int *)piVar6[1];
          if (piVar6 == (int *)piVar3[2]) {
            piVar3[2] = (int)piVar7;
            piVar7[2] = (int)piVar6;
          }
          else {
            *piVar3 = (int)piVar7;
            piVar7[2] = (int)piVar6;
          }
        }
LAB_1000ca9d:
        piVar6[1] = (int)piVar7;
      }
    }
    else {
      iVar2 = *piVar7;
      if (*(char *)(iVar2 + 0x2c) != '\0') {
        if (piVar5 == (int *)*piVar6) {
          iVar2 = *piVar6;
          *piVar6 = *(int *)(iVar2 + 8);
          if (*(char *)(*(int *)(iVar2 + 8) + 0x2d) == '\0') {
            *(int **)(*(int *)(iVar2 + 8) + 4) = piVar6;
          }
          *(int *)(iVar2 + 4) = piVar6[1];
          if (piVar6 == *(int **)(*(int *)((int)this + 4) + 4)) {
            *(int *)(*(int *)((int)this + 4) + 4) = iVar2;
          }
          else {
            piVar5 = (int *)piVar6[1];
            if (piVar6 == (int *)piVar5[2]) {
              piVar5[2] = iVar2;
            }
            else {
              *piVar5 = iVar2;
            }
          }
          *(int **)(iVar2 + 8) = piVar6;
          piVar6[1] = iVar2;
          piVar5 = piVar6;
        }
        *(undefined1 *)(piVar5[1] + 0x2c) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
        piVar6 = *(int **)(piVar5[1] + 4);
        piVar7 = (int *)piVar6[2];
        piVar6[2] = *piVar7;
        if (*(char *)(*piVar7 + 0x2d) == '\0') {
          *(int **)(*piVar7 + 4) = piVar6;
        }
        piVar7[1] = piVar6[1];
        if (piVar6 == *(int **)(*(int *)((int)this + 4) + 4)) {
          *(int **)(*(int *)((int)this + 4) + 4) = piVar7;
        }
        else {
          piVar3 = (int *)piVar6[1];
          if (piVar6 == (int *)*piVar3) {
            *piVar3 = (int)piVar7;
          }
          else {
            piVar3[2] = (int)piVar7;
          }
        }
        *piVar7 = (int)piVar6;
        goto LAB_1000ca9d;
      }
      *(undefined1 *)(piVar6 + 0xb) = 1;
      *(undefined1 *)(iVar2 + 0x2c) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
      piVar5 = *(int **)(piVar5[1] + 4);
    }
    cVar1 = *(char *)(piVar5[1] + 0x2c);
  } while( true );
}



// Function: FUN_1000cad0 at 1000cad0

void FUN_1000cad0(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x2d);
  while (cVar1 == '\0') {
    FUN_1000cad0((int *)param_1[2]);
    piVar2 = (int *)*param_1;
    if (0xf < (uint)param_1[8]) {
      operator_delete((void *)param_1[3]);
    }
    param_1[8] = 0xf;
    param_1[7] = 0;
    *(undefined1 *)(param_1 + 3) = 0;
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x2d);
  }
  return;
}



// Function: FUN_1000cb30 at 1000cb30

void __thiscall FUN_1000cb30(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  
  piVar2 = param_2;
  if (*(char *)((int)param_2 + 0x2d) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  FUN_1000b790((int *)&param_2);
  piVar5 = (int *)*piVar2;
  if (*(char *)((int)piVar5 + 0x2d) == '\0') {
    piVar6 = piVar5;
    if ((*(char *)(piVar2[2] + 0x2d) == '\0') && (piVar6 = (int *)param_2[2], param_2 != piVar2)) {
      piVar5[1] = (int)param_2;
      *param_2 = *piVar2;
      piVar5 = param_2;
      if (param_2 != (int *)piVar2[2]) {
        piVar5 = (int *)param_2[1];
        if (*(char *)((int)piVar6 + 0x2d) == '\0') {
          piVar6[1] = (int)piVar5;
        }
        *piVar5 = (int)piVar6;
        param_2[2] = piVar2[2];
        *(int **)(piVar2[2] + 4) = param_2;
      }
      if (*(int **)(*(int *)((int)this + 4) + 4) == piVar2) {
        *(int **)(*(int *)((int)this + 4) + 4) = param_2;
      }
      else {
        piVar3 = (int *)piVar2[1];
        if ((int *)*piVar3 == piVar2) {
          *piVar3 = (int)param_2;
        }
        else {
          piVar3[2] = (int)param_2;
        }
      }
      param_2[1] = piVar2[1];
      iVar1 = param_2[0xb];
      *(char *)(param_2 + 0xb) = (char)piVar2[0xb];
      *(char *)(piVar2 + 0xb) = (char)iVar1;
      goto LAB_1000cc4b;
    }
  }
  else {
    piVar6 = (int *)piVar2[2];
  }
  piVar5 = (int *)piVar2[1];
  if (*(char *)((int)piVar6 + 0x2d) == '\0') {
    piVar6[1] = (int)piVar5;
  }
  if (*(int **)(*(int *)((int)this + 4) + 4) == piVar2) {
    *(int **)(*(int *)((int)this + 4) + 4) = piVar6;
  }
  else if ((int *)*piVar5 == piVar2) {
    *piVar5 = (int)piVar6;
  }
  else {
    piVar5[2] = (int)piVar6;
  }
  if ((int *)**(int **)((int)this + 4) == piVar2) {
    piVar3 = piVar5;
    if (*(char *)((int)piVar6 + 0x2d) == '\0') {
      piVar3 = (int *)FUN_1000df10(piVar6);
    }
    **(undefined4 **)((int)this + 4) = piVar3;
  }
  iVar1 = *(int *)((int)this + 4);
  if (*(int **)(iVar1 + 8) == piVar2) {
    if (*(char *)((int)piVar6 + 0x2d) == '\0') {
      uVar4 = FUN_1000def0((int)piVar6);
      *(undefined4 *)(iVar1 + 8) = uVar4;
    }
    else {
      *(int **)(iVar1 + 8) = piVar5;
    }
  }
LAB_1000cc4b:
  if ((char)piVar2[0xb] == '\x01') {
    if (piVar6 != *(int **)(*(int *)((int)this + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0xb] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0xb] == '\0') {
            *(undefined1 *)(piVar5 + 0xb) = 1;
            *(undefined1 *)(piVar3 + 0xb) = 0;
            FUN_1000dfa0(this,(int)piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x2d) == '\0') {
            if ((*(char *)(*piVar5 + 0x2c) != '\x01') || (*(char *)(piVar5[2] + 0x2c) != '\x01')) {
              if (*(char *)(piVar5[2] + 0x2c) == '\x01') {
                *(undefined1 *)(*piVar5 + 0x2c) = 1;
                *(undefined1 *)(piVar5 + 0xb) = 0;
                FUN_1000e000(this,piVar5);
                piVar5 = (int *)piVar3[2];
              }
              *(char *)(piVar5 + 0xb) = (char)piVar3[0xb];
              *(undefined1 *)(piVar3 + 0xb) = 1;
              *(undefined1 *)(piVar5[2] + 0x2c) = 1;
              FUN_1000dfa0(this,(int)piVar3);
              break;
            }
LAB_1000cd11:
            *(undefined1 *)(piVar5 + 0xb) = 0;
          }
        }
        else {
          if ((char)piVar5[0xb] == '\0') {
            *(undefined1 *)(piVar5 + 0xb) = 1;
            *(undefined1 *)(piVar3 + 0xb) = 0;
            FUN_1000e000(this,piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x2d) == '\0') {
            if ((*(char *)(piVar5[2] + 0x2c) == '\x01') && (*(char *)(*piVar5 + 0x2c) == '\x01'))
            goto LAB_1000cd11;
            if (*(char *)(*piVar5 + 0x2c) == '\x01') {
              *(undefined1 *)(piVar5[2] + 0x2c) = 1;
              *(undefined1 *)(piVar5 + 0xb) = 0;
              FUN_1000dfa0(this,(int)piVar5);
              piVar5 = (int *)*piVar3;
            }
            *(char *)(piVar5 + 0xb) = (char)piVar3[0xb];
            *(undefined1 *)(piVar3 + 0xb) = 1;
            *(undefined1 *)(*piVar5 + 0x2c) = 1;
            FUN_1000e000(this,piVar3);
            break;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)((int)this + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xb) = 1;
  }
  if (0xf < (uint)piVar2[8]) {
    operator_delete((void *)piVar2[3]);
  }
  piVar2[8] = 0xf;
  piVar2[7] = 0;
  *(undefined1 *)(piVar2 + 3) = 0;
  operator_delete(piVar2);
  if (*(int *)((int)this + 8) != 0) {
    *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_1000cdb0 at 1000cdb0

void __thiscall FUN_1000cdb0(void *this,undefined4 *param_1,int *param_2,undefined4 *param_3)

{
  char cVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  int *piVar6;
  uint uVar7;
  undefined4 *puVar8;
  int *piVar9;
  bool local_c;
  
  puVar5 = (undefined4 *)(*(undefined4 **)((int)this + 4))[1];
  piVar9 = param_2 + 3;
  cVar1 = *(char *)((int)puVar5 + 0x2d);
  local_c = true;
  puVar3 = *(undefined4 **)((int)this + 4);
  while (cVar1 == '\0') {
    puVar3 = puVar5 + 3;
    if ((char)param_3 == '\0') {
      uVar7 = puVar5[7];
      if (0xf < (uint)puVar5[8]) {
        puVar3 = (undefined4 *)*puVar3;
      }
      uVar2 = param_2[7];
      uVar4 = uVar2;
      if (uVar7 <= uVar2) {
        uVar4 = uVar7;
      }
      piVar6 = piVar9;
      if (0xf < (uint)param_2[8]) {
        piVar6 = (int *)*piVar9;
      }
      uVar4 = FUN_10006c69(piVar6,puVar3,uVar4);
      if (uVar4 == 0) {
        if (uVar2 < uVar7) {
          uVar4 = 0xffffffff;
        }
        else {
          uVar4 = (uint)(uVar2 != uVar7);
        }
      }
      local_c = (int)uVar4 < 0;
    }
    else {
      piVar6 = piVar9;
      if (0xf < (uint)param_2[8]) {
        piVar6 = (int *)*piVar9;
      }
      uVar7 = puVar5[7];
      uVar2 = param_2[7];
      uVar4 = uVar7;
      if (uVar2 <= uVar7) {
        uVar4 = uVar2;
      }
      if (0xf < (uint)puVar5[8]) {
        puVar3 = (undefined4 *)*puVar3;
      }
      uVar4 = FUN_10006c69(puVar3,piVar6,uVar4);
      if (uVar4 == 0) {
        if (uVar7 < uVar2) {
          local_c = false;
          goto LAB_1000ce8a;
        }
        uVar4 = (uint)(uVar7 != uVar2);
      }
      local_c = -1 < (int)uVar4;
    }
LAB_1000ce8a:
    if (local_c == false) {
      puVar8 = (undefined4 *)puVar5[2];
    }
    else {
      puVar8 = (undefined4 *)*puVar5;
    }
    puVar3 = puVar5;
    puVar5 = puVar8;
    cVar1 = *(char *)((int)puVar8 + 0x2d);
  }
  param_3 = puVar3;
  if (local_c != false) {
    if (puVar3 == (undefined4 *)**(int **)((int)this + 4)) {
      local_c = true;
      goto LAB_1000cecd;
    }
    FUN_1000df30((int *)&param_3);
  }
  puVar5 = param_3;
  piVar6 = piVar9;
  if (0xf < (uint)param_2[8]) {
    piVar6 = (int *)*piVar9;
  }
  uVar7 = FUN_1000b470(param_3 + 3,0,param_3[7],piVar6,param_2[7]);
  if (-1 < (int)uVar7) {
    if (0xf < (uint)param_2[8]) {
      operator_delete((void *)*piVar9);
    }
    param_2[8] = 0xf;
    param_2[7] = 0;
    *(undefined1 *)piVar9 = 0;
    operator_delete(param_2);
    *param_1 = puVar5;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_1000cecd:
  puVar5 = (undefined4 *)FUN_1000c880(this,&param_3,local_c,puVar3,param_2);
  *param_1 = *puVar5;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}



// Function: FUN_1000cf70 at 1000cf70

void __thiscall FUN_1000cf70(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  void *local_8;
  
  piVar2 = *(int **)((int)this + 4);
  local_8 = this;
  if ((param_2 == (int *)*piVar2) && (param_3 == piVar2)) {
    FUN_1000cad0((int *)piVar2[1]);
    *(int *)(*(int *)((int)this + 4) + 4) = *(int *)((int)this + 4);
    *(undefined4 *)*(undefined4 *)((int)this + 4) = *(undefined4 *)((int)this + 4);
    *(int *)(*(int *)((int)this + 4) + 8) = *(int *)((int)this + 4);
    *(undefined4 *)((int)this + 8) = 0;
    *param_1 = **(undefined4 **)((int)this + 4);
    return;
  }
  if (param_2 != param_3) {
    do {
      piVar2 = param_2;
      if (*(char *)((int)param_2 + 0x2d) == '\0') {
        piVar3 = (int *)param_2[2];
        if (*(char *)((int)piVar3 + 0x2d) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x2d);
          param_2 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x2d);
            param_2 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(param_2[1] + 0x2d);
          piVar4 = (int *)param_2[1];
          piVar3 = param_2;
          while ((param_2 = piVar4, cVar1 == '\0' && (piVar3 == (int *)param_2[2]))) {
            cVar1 = *(char *)(param_2[1] + 0x2d);
            piVar4 = (int *)param_2[1];
            piVar3 = param_2;
          }
        }
      }
      FUN_1000cb30(this,&local_8,piVar2);
    } while (param_2 != param_3);
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_1000d030 at 1000d030

undefined4 __thiscall FUN_1000d030(void *this,byte *param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  byte **ppbVar4;
  char *pcVar5;
  undefined4 *puVar6;
  char *pcVar7;
  void *this_00;
  bool bVar8;
  uint in_stack_00000018;
  uint in_stack_ffffff98;
  void *local_3c [4];
  undefined4 local_2c;
  uint local_28;
  void *local_20;
  int *local_1c;
  int *local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001a618;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_20 = this;
  FUN_1000de70(&local_14,(undefined4 *)((int)this + 4));
  local_8._0_1_ = 1;
  iVar3 = FUN_1000b460((int)&param_1);
  if (iVar3 != 0) {
    ppbVar4 = (byte **)param_1;
    if (in_stack_00000018 < 0x10) {
      ppbVar4 = &param_1;
    }
    pcVar7 = "COMMON";
    do {
      bVar1 = *(byte *)ppbVar4;
      bVar8 = bVar1 < (byte)*pcVar7;
      if (bVar1 != *pcVar7) {
LAB_1000d0b1:
        iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_1000d0b6;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppbVar4 + 1);
      bVar8 = bVar1 < ((byte *)pcVar7)[1];
      if (bVar1 != ((byte *)pcVar7)[1]) goto LAB_1000d0b1;
      ppbVar4 = (byte **)((int)ppbVar4 + 2);
      pcVar7 = (char *)((byte *)pcVar7 + 2);
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_1000d0b6:
    if (iVar3 == 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_1000de90(&local_14);
      if (0xf < in_stack_00000018) {
        operator_delete(param_1);
      }
      ExceptionList = local_10;
      return 1;
    }
  }
  pcVar5 = (char *)FUN_1000b4e0(&param_1);
  local_18 = (int *)&stack0xffffff98;
  puVar6 = (undefined4 *)(in_stack_ffffff98 & 0xffffff00);
  pcVar7 = pcVar5;
  do {
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xffffff98,pcVar5,(int)pcVar7 - (int)(pcVar5 + 1));
  this_00 = (void *)((int)local_20 + 8);
  puVar6 = (undefined4 *)FUN_1000bc60(this_00,puVar6);
  if (puVar6 != (undefined4 *)0x0) {
    (**(code **)*puVar6)();
    pcVar5 = (char *)FUN_1000b4e0(&param_1);
    local_28 = 0xf;
    local_2c = 0;
    local_3c[0] = (void *)((uint)local_3c[0] & 0xffffff00);
    pcVar7 = pcVar5;
    do {
      cVar2 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar2 != '\0');
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_3c,pcVar5,(int)pcVar7 - (int)(pcVar5 + 1));
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_1000b860(this_00,(int *)&local_1c,local_3c);
    FUN_1000cf70(this_00,&local_18,local_1c,local_18);
    if (0xf < local_28) {
      operator_delete(local_3c[0]);
    }
    local_8 = local_8 & 0xffffff00;
    FUN_1000de90(&local_14);
    if (0xf < in_stack_00000018) {
      operator_delete(param_1);
    }
    ExceptionList = local_10;
    return 0;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1000de90(&local_14);
  if (0xf < in_stack_00000018) {
    operator_delete(param_1);
  }
  ExceptionList = local_10;
  return 9;
}



// Function: FUN_1000d220 at 1000d220

void __fastcall FUN_1000d220(void *param_1)

{
  undefined4 local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a650;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = param_1;
  FUN_1000cad0(*(int **)(*(int *)((int)param_1 + 4) + 4));
  *(int *)(*(int *)((int)param_1 + 4) + 4) = *(int *)((int)param_1 + 4);
  *(undefined4 *)*(undefined4 *)((int)param_1 + 4) = *(undefined4 *)((int)param_1 + 4);
  *(int *)(*(int *)((int)param_1 + 4) + 8) = *(int *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 8) = 0;
  local_8 = 1;
  FUN_1000cf70(param_1,&local_18,(int *)**(int **)((int)param_1 + 4),*(int **)((int)param_1 + 4));
  operator_delete(*(void **)((int)param_1 + 4));
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000d2b0 at 1000d2b0

void __fastcall FUN_1000d2b0(undefined4 *param_1)

{
  void *pvVar1;
  int *piVar2;
  undefined4 *puVar3;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_254 [4];
  undefined4 uStack_250;
  undefined4 uStack_244;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_238 [16];
  undefined4 uStack_228;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_21c [16];
  undefined4 uStack_20c;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_200 [16];
  undefined4 uStack_1f0;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_1e4 [16];
  undefined4 uStack_1d4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_1c8 [16];
  undefined4 uStack_1b8;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_1ac [16];
  undefined4 uStack_19c;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_190 [16];
  undefined4 uStack_180;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_174 [16];
  undefined4 uStack_164;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_158 [16];
  undefined4 uStack_148;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_13c [16];
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_120;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_114 [16];
  undefined4 uStack_104;
  undefined4 uStack_100;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_f4 [16];
  undefined4 local_e4;
  uint in_stack_ffffff28;
  void *pvVar4;
  uint uStack_bc;
  void *local_ac [4];
  undefined4 local_9c;
  uint local_98;
  undefined **local_90 [3];
  char *local_84;
  undefined4 local_80;
  undefined1 *local_7c;
  int *local_78;
  undefined4 *local_74;
  int *local_70;
  undefined1 *local_6c;
  undefined1 *local_68;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a6df;
  local_10 = ExceptionList;
  uStack_bc = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_bc;
  ExceptionList = &local_10;
  *param_1 = SharedConfigurationLibrary::SCLServices::vftable;
  local_74 = param_1;
  local_18 = uStack_bc;
  FUN_100132f0(param_1 + 1);
  local_8 = 0;
  param_1[4] = 0;
  pvVar1 = operator_new(0x30);
  if (pvVar1 != (void *)0x0) {
    param_1[3] = pvVar1;
    *(void **)pvVar1 = pvVar1;
    *(undefined4 *)(param_1[3] + 4) = param_1[3];
    *(undefined4 *)(param_1[3] + 8) = param_1[3];
    *(undefined1 *)(param_1[3] + 0x2c) = 1;
    *(undefined1 *)(param_1[3] + 0x2d) = 1;
    local_8._0_1_ = 1;
    FUN_1000de70(&local_80,param_1 + 1);
    local_78 = (int *)0x0;
    local_8._0_1_ = 3;
    local_70 = (int *)operator_new(8);
    local_8._0_1_ = 4;
    if (local_70 == (undefined4 *)0x0) {
      local_70 = (int *)0x0;
    }
    else {
      local_70 = FUN_10010960(local_70);
    }
    local_8._0_1_ = 3;
    local_78 = local_70;
    pvVar1 = operator_new(0x34);
    local_8._0_1_ = 5;
    local_6c = (undefined1 *)pvVar1;
    if (pvVar1 == (void *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      local_68 = &stack0xffffff28;
      pvVar4 = (void *)(in_stack_ffffff28 & 0xffffff00);
      local_e4 = 0x1000d3a9;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &stack0xffffff28,"COMMON",6);
      piVar2 = FUN_10010440(pvVar1,pvVar4);
    }
    local_68 = &stack0xffffff28;
    local_8._0_1_ = 3;
    local_e4 = 0x1000d3d5;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &stack0xffffff28,"",0);
    local_6c = local_f4;
    local_e4 = 0;
    local_8._0_1_ = 6;
    local_f4[0] = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
    uStack_100 = 0x1000d3f5;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              (local_f4,"HTTPProxyAddress",0x10);
    local_8._0_1_ = 3;
    (**(code **)(*piVar2 + 0x14))();
    local_68 = abStack_114;
    uStack_100 = 0xf;
    uStack_104 = 0;
    abStack_114[0] =
         (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
    uStack_120 = 0x1000d420;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              (abStack_114,"HTTPProxyPort",0xd);
    (**(code **)(*piVar2 + 8))();
    uStack_120 = 0x50;
    local_68 = abStack_13c;
    uStack_128 = 0xf;
    uStack_12c = 0;
    abStack_13c[0] =
         (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
    uStack_148 = 0x1000d44d;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              (abStack_13c,"HTTPProxyPort",0xd);
    (**(code **)(*piVar2 + 0x10))();
    local_68 = abStack_158;
    uStack_148 = 0;
    abStack_158[0] =
         (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
    uStack_164 = 0x1000d471;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              (abStack_158,"",0);
    local_6c = abStack_174;
    uStack_164 = 0;
    local_8._0_1_ = 7;
    abStack_174[0] =
         (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
    uStack_180 = 0x1000d491;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              (abStack_174,"HTTPProxyUsername",0x11);
    local_8._0_1_ = 3;
    (**(code **)(*piVar2 + 0x14))();
    local_68 = abStack_190;
    uStack_180 = 0;
    abStack_190[0] =
         (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
    uStack_19c = 0x1000d4b9;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              (abStack_190,"",0);
    local_6c = abStack_1ac;
    uStack_19c = 0;
    local_8._0_1_ = 8;
    abStack_1ac[0] =
         (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
    uStack_1b8 = 0x1000d4d9;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              (abStack_1ac,"HTTPProxyPassword",0x11);
    local_8._0_1_ = 3;
    (**(code **)(*piVar2 + 0x14))();
    local_68 = abStack_1c8;
    uStack_1b8 = 0;
    abStack_1c8[0] =
         (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
    uStack_1d4 = 0x1000d501;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              (abStack_1c8,"",0);
    local_6c = abStack_1e4;
    uStack_1d4 = 0;
    local_8._0_1_ = 9;
    abStack_1e4[0] =
         (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
    uStack_1f0 = 0x1000d521;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              (abStack_1e4,"HTTPProxyByPassList",0x13);
    local_8._0_1_ = 3;
    (**(code **)(*piVar2 + 0x14))();
    local_68 = abStack_200;
    uStack_1f0 = 0;
    abStack_200[0] =
         (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
    uStack_20c = 0x1000d54a;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              (abStack_200,"Disabled, 0, System Default, 1, Manual, 2",0x29);
    local_6c = abStack_21c;
    uStack_20c = 0;
    local_8._0_1_ = 10;
    abStack_21c[0] =
         (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
    uStack_228 = 0x1000d56a;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              (abStack_21c,"System Default",0xe);
    local_7c = abStack_238;
    uStack_228 = 0;
    local_8._0_1_ = 0xb;
    abStack_238[0] =
         (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
    uStack_244 = 0x1000d58a;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              (abStack_238,"HTTPProxySettingType",0x14);
    local_8._0_1_ = 3;
    (**(code **)(*piVar2 + 4))();
    local_7c = abStack_254;
    uStack_244 = 0;
    abStack_254[0] =
         (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              (abStack_254,"",0);
    (**(code **)(*local_70 + 4))(piVar2);
    local_98 = 0xf;
    local_9c = 0;
    local_ac[0] = (void *)((uint)local_ac[0] & 0xffffff00);
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_ac,"COMMON",6);
    local_8._0_1_ = 0xc;
    puVar3 = (undefined4 *)FUN_1000ec40(local_74 + 2,local_ac);
    *puVar3 = piVar2;
    local_8 = CONCAT31(local_8._1_3_,3);
    if (0xf < local_98) {
      operator_delete(local_ac[0]);
    }
    (**(code **)*local_70)(1);
    local_8 = 1;
    FUN_1000de90(&local_80);
    ExceptionList = local_10;
    uStack_250 = 0x1000d64a;
    __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_84 = (char *)0x0;
  std::exception::exception((exception *)local_90,&local_84);
  local_90[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_90,(ThrowInfo *)&DAT_10020dd4);
}



// Function: Catch_All@1000d64e at 1000d64e

void Catch_All_1000d64e(void)

{
  int unaff_EBP;
  
  if (*(undefined4 **)(unaff_EBP + -0x74) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_EBP + -0x74))(1);
  }
  FUN_1000dd70((void *)(unaff_EBP + -0x60),(int *)"Initialization of COMMON schema failed",4);
  *(undefined ***)(unaff_EBP + -0x60) = SharedConfigurationLibrary::SCLException::vftable;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)(unaff_EBP + -0x60),(ThrowInfo *)&DAT_10023ca4);
}



// Function: FUN_1000d6b0 at 1000d6b0

exception * __thiscall FUN_1000d6b0(void *this,exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a724;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = pcl_os::Exception::vftable;
  *(undefined4 *)((int)this + 0x20) = 0xf;
  *(undefined4 *)((int)this + 0x1c) = 0;
  local_8 = 0;
  *(undefined1 *)((int)this + 0xc) = 0;
  FUN_10001f4b((undefined1 *)((int)this + 0xc),(undefined4 *)(param_1 + 0xc),0,0xffffffff);
  *(undefined4 *)((int)this + 0x3c) = 0xf;
  *(undefined4 *)((int)this + 0x38) = 0;
  local_8 = CONCAT31(local_8._1_3_,1);
  *(undefined1 *)((int)this + 0x28) = 0;
  FUN_10001f4b((undefined1 *)((int)this + 0x28),(undefined4 *)(param_1 + 0x28),0,0xffffffff);
  *(undefined4 *)((int)this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)((int)this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  ExceptionList = local_10;
  return (exception *)this;
}



// Function: FUN_1000d760 at 1000d760

undefined4 * __thiscall FUN_1000d760(void *this,exception *param_1)

{
  FUN_1000d6b0(this,param_1);
  *(undefined ***)this = SharedConfigurationLibrary::SCLException::vftable;
  return (undefined4 *)this;
}



// Function: FUN_1000d780 at 1000d780

void __fastcall FUN_1000d780(undefined4 *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a76e;
  local_10 = ExceptionList;
  uVar4 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = SharedConfigurationLibrary::SCLServices::vftable;
  local_8 = 1;
  FUN_1000de70(&local_1c,param_1 + 1);
  local_18 = param_1[4];
  local_8._0_1_ = 2;
  local_14 = 0;
  if (0 < local_18) {
    do {
      if ((-1 < local_14) && (local_14 < (int)param_1[4])) {
        puVar5 = *(undefined4 **)param_1[3];
        iVar6 = 0;
        while (puVar5 != (undefined4 *)param_1[3]) {
          if (iVar6 == local_14) {
            if ((undefined4 *)puVar5[10] != (undefined4 *)0x0) {
              (*(code *)**(undefined4 **)puVar5[10])(1,uVar4);
            }
            break;
          }
          if (*(char *)((int)puVar5 + 0x2d) == '\0') {
            puVar2 = (undefined4 *)puVar5[2];
            if (*(char *)((int)puVar2 + 0x2d) == '\0') {
              cVar1 = *(char *)((int)*puVar2 + 0x2d);
              puVar5 = puVar2;
              puVar2 = (undefined4 *)*puVar2;
              while (cVar1 == '\0') {
                cVar1 = *(char *)((int)*puVar2 + 0x2d);
                puVar5 = puVar2;
                puVar2 = (undefined4 *)*puVar2;
              }
            }
            else {
              cVar1 = *(char *)((int)puVar5[1] + 0x2d);
              puVar3 = (undefined4 *)puVar5[1];
              puVar2 = puVar5;
              while ((puVar5 = puVar3, cVar1 == '\0' && (puVar2 == (undefined4 *)puVar5[2]))) {
                cVar1 = *(char *)((int)puVar5[1] + 0x2d);
                puVar3 = (undefined4 *)puVar5[1];
                puVar2 = puVar5;
              }
            }
          }
          iVar6 = iVar6 + 1;
        }
      }
      local_14 = local_14 + 1;
    } while (local_14 < local_18);
  }
  FUN_1000cad0(*(int **)(param_1[3] + 4));
  *(undefined4 *)(param_1[3] + 4) = param_1[3];
  *(undefined4 *)param_1[3] = param_1[3];
  *(undefined4 *)(param_1[3] + 8) = param_1[3];
  param_1[4] = 0;
  local_8._0_1_ = 1;
  FUN_1000de90(&local_1c);
  local_8._0_1_ = 3;
  local_1c = param_1 + 2;
  FUN_1000cad0(*(int **)(param_1[3] + 4));
  *(undefined4 *)(param_1[3] + 4) = param_1[3];
  *(undefined4 *)param_1[3] = param_1[3];
  *(undefined4 *)(param_1[3] + 8) = param_1[3];
  param_1[4] = 0;
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_1000cf70(param_1 + 2,&local_18,*(int **)param_1[3],(int *)param_1[3]);
  operator_delete((void *)param_1[3]);
  local_8 = 0xffffffff;
  FUN_10013310(param_1 + 1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000d910 at 1000d910

int FUN_1000d910(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a79b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_100272c8 == '\0') {
    DAT_100272c8 = 1;
    local_8 = 0;
    if (DAT_100272c4 == 0) {
      puVar1 = (undefined4 *)operator_new(0x18);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (puVar1 == (undefined4 *)0x0) {
        DAT_100272c4 = 0;
      }
      else {
        DAT_100272c4 = FUN_1000d2b0(puVar1);
      }
    }
  }
  DAT_100272c8 = 0;
  ExceptionList = local_10;
  return DAT_100272c4;
}



// Function: Catch_All@1000d99e at 1000d99e

undefined4 Catch_All_1000d99e(void)

{
  DAT_100272c4 = 0;
  return 0x1000d980;
}



// Function: FUN_1000d9b0 at 1000d9b0

void __thiscall FUN_1000d9b0(void *this,int param_1)

{
  char cVar1;
  int *piVar2;
  void *this_00;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  char *pcVar6;
  uint in_stack_ffffff5c;
  void *local_78 [4];
  undefined4 local_68;
  uint local_64;
  void *local_5c;
  undefined4 local_58;
  undefined4 *local_54;
  int *local_50;
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
  puStack_c = &LAB_1001a7eb;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_5c = this;
  FUN_1000de70(&local_58,(undefined4 *)((int)this + 4));
  local_8 = 0;
  if (param_1 == 0) {
    local_8 = 0xffffffff;
    FUN_1000de90(&local_58);
  }
  else {
    this_00 = (void *)__RTDynamicCast();
    FUN_1000bb40(this_00,(undefined1 *)local_30);
    local_8._0_1_ = 1;
    pcVar3 = (char *)FUN_1000b4e0(local_30);
    local_54 = (undefined4 *)&stack0xffffff5c;
    local_50 = (int *)(pcVar3 + 1);
    puVar5 = (undefined4 *)(in_stack_ffffff5c & 0xffffff00);
    pcVar6 = pcVar3;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &stack0xffffff5c,pcVar3,(int)pcVar6 - (int)local_50);
    local_5c = (void *)((int)local_5c + 8);
    uVar4 = FUN_1000bb70(local_5c,puVar5);
    if ((char)uVar4 == '\0') {
      local_54 = (undefined4 *)operator_new(8);
      local_8._0_1_ = 2;
      if (local_54 == (undefined4 *)0x0) {
        local_50 = (int *)0x0;
      }
      else {
        local_50 = FUN_10010960(local_54);
      }
      piVar2 = local_50;
      local_54 = (undefined4 *)&stack0xffffff5c;
      local_8._0_1_ = 1;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &stack0xffffff5c,"",0);
      local_54 = (undefined4 *)(**(code **)(*piVar2 + 4))(this_00);
      puVar5 = (undefined4 *)FUN_1000bb40(this_00,(undefined1 *)local_4c);
      local_8._0_1_ = 3;
      pcVar3 = (char *)FUN_1000b4e0(puVar5);
      local_64 = 0xf;
      local_68 = 0;
      local_78[0] = (void *)((uint)local_78[0] & 0xffffff00);
      pcVar6 = pcVar3;
      do {
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 local_78,pcVar3,(int)pcVar6 - (int)(pcVar3 + 1));
      local_8 = CONCAT31(local_8._1_3_,4);
      puVar5 = (undefined4 *)FUN_1000ec40(local_5c,local_78);
      *puVar5 = this_00;
      if (0xf < local_64) {
        operator_delete(local_78[0]);
      }
      local_64 = 0xf;
      local_68 = 0;
      local_78[0] = (void *)((uint)local_78[0] & 0xffffff00);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (0xf < local_38) {
        operator_delete(local_4c[0]);
      }
      local_38 = 0xf;
      local_3c = 0;
      local_4c[0] = (void *)((uint)local_4c[0] & 0xffffff00);
      (**(code **)*local_50)(1);
      if (0xf < local_1c) {
        operator_delete(local_30[0]);
      }
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
      local_8 = 0xffffffff;
      FUN_1000de90(&local_58);
    }
    else {
      if (0xf < local_1c) {
        operator_delete(local_30[0]);
      }
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
      local_8 = 0xffffffff;
      FUN_1000de90(&local_58);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000dc00 at 1000dc00

undefined4 * __thiscall FUN_1000dc00(void *this,byte param_1)

{
  FUN_1000d780((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000dc30 at 1000dc30

undefined4 __fastcall FUN_1000dc30(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1000dc40 at 1000dc40

void FUN_1000dc40(void)

{
  return;
}



// Function: FUN_1000dc50 at 1000dc50

undefined4 * FUN_1000dc50(byte *param_1)

{
  byte bVar1;
  int iVar2;
  byte **ppbVar3;
  void *this;
  undefined4 *puVar4;
  char *pcVar5;
  bool bVar6;
  uint in_stack_00000018;
  uint in_stack_ffffffc0;
  void *pvVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a823;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  iVar2 = FUN_1000b460((int)&param_1);
  if (iVar2 != 0) {
    ppbVar3 = (byte **)param_1;
    if (in_stack_00000018 < 0x10) {
      ppbVar3 = &param_1;
    }
    pcVar5 = "COMMON";
    do {
      bVar1 = *(byte *)ppbVar3;
      bVar6 = bVar1 < (byte)*pcVar5;
      if (bVar1 != *pcVar5) {
LAB_1000dcc3:
        iVar2 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_1000dcc8;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppbVar3 + 1);
      bVar6 = bVar1 < ((byte *)pcVar5)[1];
      if (bVar1 != ((byte *)pcVar5)[1]) goto LAB_1000dcc3;
      ppbVar3 = (byte **)((int)ppbVar3 + 2);
      pcVar5 = (char *)((byte *)pcVar5 + 2);
    } while (bVar1 != 0);
    iVar2 = 0;
LAB_1000dcc8:
    if (iVar2 != 0) {
      this = operator_new(0x34);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (this == (void *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        pvVar7 = (void *)(in_stack_ffffffc0 & 0xffffff00);
        FUN_10001f4b(&stack0xffffffc0,&param_1,0,0xffffffff);
        puVar4 = FUN_10010440(this,pvVar7);
      }
      if (0xf < in_stack_00000018) {
        operator_delete(param_1);
      }
      ExceptionList = local_10;
      return puVar4;
    }
  }
  if (0xf < in_stack_00000018) {
    operator_delete(param_1);
  }
  ExceptionList = local_10;
  return (undefined4 *)0x0;
}



// Function: FUN_1000dd60 at 1000dd60

void __fastcall FUN_1000dd60(int param_1)

{
  FUN_1000b4e0((undefined4 *)(param_1 + 0xc));
  return;
}



// Function: FUN_1000dd70 at 1000dd70

void __thiscall FUN_1000dd70(void *this,int *param_1,undefined4 param_2)

{
  uint uVar1;
  int local_34 [8];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a86f;
  local_10 = ExceptionList;
  uVar1 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  std::exception::exception((exception *)this);
  local_8 = 0;
  *(undefined ***)this = pcl_os::Exception::vftable;
  *(undefined4 *)((int)this + 0x20) = 0xf;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)((int)this + 0xc)
       = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             ((int)this + 0xc),"",0);
  *(undefined4 *)((int)this + 0x3c) = 0xf;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined1 *)((int)this + 0x28) = 0;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),4);
  *(undefined4 *)((int)this + 0x44) = 0;
  *(undefined4 *)((int)this + 0x48) = param_2;
  FUN_1000b720((void *)((int)this + 0xc),(int *)&DAT_1001f11c);
  sprintf((char *)local_34,"%u",param_2,uVar1);
  FUN_1000b720((void *)((int)this + 0xc),local_34);
  FUN_1000b720((void *)((int)this + 0xc),(int *)&DAT_1001f118);
  FUN_1000b720((void *)((int)this + 0xc),param_1);
  local_8 = 0xffffffff;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000de70 at 1000de70

undefined4 * __thiscall FUN_1000de70(void *this,undefined4 *param_1)

{
  *(undefined4 **)this = param_1;
  if (param_1 != (undefined4 *)0x0) {
    FUN_10013320(param_1);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000de90 at 1000de90

void __fastcall FUN_1000de90(undefined4 *param_1)

{
  if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
    FUN_10013330((undefined4 *)*param_1);
    *param_1 = 0;
  }
  return;
}



// Function: FUN_1000deb0 at 1000deb0

void __fastcall FUN_1000deb0(undefined4 *param_1)

{
  *param_1 = SharedConfigurationLibrary::SCLSchema::vftable;
  return;
}



// Function: FUN_1000dec0 at 1000dec0

undefined4 * __thiscall FUN_1000dec0(void *this,byte param_1)

{
  *(undefined ***)this = SharedConfigurationLibrary::SCLSchema::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000def0 at 1000def0

void __cdecl FUN_1000def0(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  cVar1 = *(char *)(iVar2 + 0x2d);
  while (cVar1 == '\0') {
    iVar2 = *(int *)(iVar2 + 8);
    cVar1 = *(char *)(iVar2 + 0x2d);
  }
  return;
}



// Function: FUN_1000df10 at 1000df10

void __cdecl FUN_1000df10(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  cVar1 = *(char *)((int)piVar2 + 0x2d);
  while (cVar1 == '\0') {
    piVar2 = (int *)*piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x2d);
  }
  return;
}



// Function: FUN_1000df30 at 1000df30

void __fastcall FUN_1000df30(int *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  puVar2 = (undefined4 *)*param_1;
  if (*(char *)((int)puVar2 + 0x2d) != '\0') {
    *param_1 = puVar2[2];
    return;
  }
  piVar5 = (int *)*puVar2;
  if (*(char *)((int)piVar5 + 0x2d) == '\0') {
    iVar3 = piVar5[2];
    if (*(char *)(piVar5[2] + 0x2d) == '\0') {
      do {
        iVar4 = iVar3;
        iVar3 = *(int *)(iVar4 + 8);
      } while (*(char *)(iVar3 + 0x2d) == '\0');
      *param_1 = iVar4;
      return;
    }
  }
  else {
    piVar5 = (int *)puVar2[1];
    cVar1 = *(char *)((int)piVar5 + 0x2d);
    while ((cVar1 == '\0' && (*param_1 == *piVar5))) {
      *param_1 = (int)piVar5;
      piVar5 = (int *)piVar5[1];
      cVar1 = *(char *)((int)piVar5 + 0x2d);
    }
    if (*(char *)(*param_1 + 0x2d) != '\0') {
      return;
    }
  }
  *param_1 = (int)piVar5;
  return;
}



// Function: FUN_1000df90 at 1000df90

void __fastcall FUN_1000df90(int param_1)

{
  operator_delete(*(void **)(param_1 + 4));
  return;
}



// Function: FUN_1000dfa0 at 1000dfa0

void __thiscall FUN_1000dfa0(void *this,int param_1)

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
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2 = *(int **)(param_1 + 4);
  if (param_1 == *piVar2) {
    *piVar2 = (int)piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2[2] = (int)piVar1;
  *piVar1 = param_1;
  *(int **)(param_1 + 4) = piVar1;
  return;
}



// Function: FUN_1000e000 at 1000e000

void __thiscall FUN_1000e000(void *this,int *param_1)

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
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  piVar2 = (int *)param_1[1];
  if (param_1 == (int *)piVar2[2]) {
    piVar2[2] = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  *piVar2 = iVar1;
  *(int **)(iVar1 + 8) = param_1;
  param_1[1] = iVar1;
  return;
}



// Function: FUN_1000e060 at 1000e060

undefined4 __fastcall FUN_1000e060(int param_1)

{
  return *(undefined4 *)(param_1 + 0x2c);
}



// Function: FUN_1000e070 at 1000e070

undefined4 * __thiscall FUN_1000e070(void *this,undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *local_8;
  
  local_8 = *(undefined4 **)((int)this + 4);
  if (*(char *)((int)local_8[1] + 0x45) == '\0') {
    uVar1 = param_1[5];
    uVar2 = param_1[4];
    puVar7 = (undefined4 *)local_8[1];
    do {
      puVar4 = puVar7 + 3;
      puVar6 = param_1;
      if (0xf < uVar1) {
        puVar6 = (undefined4 *)*param_1;
      }
      uVar3 = puVar7[7];
      uVar5 = uVar3;
      if (uVar2 <= uVar3) {
        uVar5 = uVar2;
      }
      if (0xf < (uint)puVar7[8]) {
        puVar4 = (undefined4 *)*puVar4;
      }
      uVar5 = FUN_10006c69(puVar4,puVar6,uVar5);
      if (uVar5 == 0) {
        if (uVar2 <= uVar3) {
          uVar5 = (uint)(uVar3 != uVar2);
          goto LAB_1000e0d7;
        }
LAB_1000e0d9:
        puVar4 = (undefined4 *)puVar7[2];
      }
      else {
LAB_1000e0d7:
        if ((int)uVar5 < 0) goto LAB_1000e0d9;
        puVar4 = (undefined4 *)*puVar7;
        local_8 = puVar7;
      }
      puVar7 = puVar4;
    } while (*(char *)((int)puVar4 + 0x45) == '\0');
  }
  return local_8;
}



// Function: FUN_1000e100 at 1000e100

undefined4 * __thiscall FUN_1000e100(void *this,undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *local_8;
  
  local_8 = *(undefined4 **)((int)this + 4);
  if (*(char *)((int)local_8[1] + 0x2d) == '\0') {
    uVar1 = param_1[5];
    uVar2 = param_1[4];
    puVar7 = (undefined4 *)local_8[1];
    do {
      puVar4 = puVar7 + 3;
      puVar6 = param_1;
      if (0xf < uVar1) {
        puVar6 = (undefined4 *)*param_1;
      }
      uVar3 = puVar7[7];
      uVar5 = uVar3;
      if (uVar2 <= uVar3) {
        uVar5 = uVar2;
      }
      if (0xf < (uint)puVar7[8]) {
        puVar4 = (undefined4 *)*puVar4;
      }
      uVar5 = FUN_10006c69(puVar4,puVar6,uVar5);
      if (uVar5 == 0) {
        if (uVar2 <= uVar3) {
          uVar5 = (uint)(uVar3 != uVar2);
          goto LAB_1000e167;
        }
LAB_1000e169:
        puVar4 = (undefined4 *)puVar7[2];
      }
      else {
LAB_1000e167:
        if ((int)uVar5 < 0) goto LAB_1000e169;
        puVar4 = (undefined4 *)*puVar7;
        local_8 = puVar7;
      }
      puVar7 = puVar4;
    } while (*(char *)((int)puVar4 + 0x2d) == '\0');
  }
  return local_8;
}



// Function: FUN_1000e190 at 1000e190

undefined4 __thiscall FUN_1000e190(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = param_1;
  if ((-1 < (int)param_1) && ((int)param_1 < *(int *)((int)this + 0x2c))) {
    puVar1 = *(undefined4 **)((int)this + 0x28);
    param_1 = (undefined4 *)*puVar1;
    puVar3 = (undefined4 *)0x0;
    while (param_1 != puVar1) {
      if (puVar3 == puVar2) {
        return param_1[10];
      }
      FUN_1000b790((int *)&param_1);
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
  }
  return 0;
}



// Function: FUN_1000e1e0 at 1000e1e0

void __thiscall FUN_1000e1e0(void *this,undefined1 param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = *(int *)((int)this + 0x2c);
  iVar6 = 0;
  if (0 < iVar2) {
    do {
      if ((-1 < iVar6) && (iVar6 < *(int *)((int)this + 0x2c))) {
        puVar5 = (undefined4 *)**(undefined4 **)((int)this + 0x28);
        iVar7 = 0;
        while (puVar5 != *(undefined4 **)((int)this + 0x28)) {
          if (iVar7 == iVar6) {
            if (puVar5[10] != 0) {
              *(undefined1 *)(puVar5[10] + 0x14) = param_1;
            }
            break;
          }
          if (*(char *)((int)puVar5 + 0x2d) == '\0') {
            puVar3 = (undefined4 *)puVar5[2];
            if (*(char *)((int)puVar3 + 0x2d) == '\0') {
              cVar1 = *(char *)((int)*puVar3 + 0x2d);
              puVar5 = puVar3;
              puVar3 = (undefined4 *)*puVar3;
              while (cVar1 == '\0') {
                cVar1 = *(char *)((int)*puVar3 + 0x2d);
                puVar5 = puVar3;
                puVar3 = (undefined4 *)*puVar3;
              }
            }
            else {
              cVar1 = *(char *)((int)puVar5[1] + 0x2d);
              puVar4 = (undefined4 *)puVar5[1];
              puVar3 = puVar5;
              while ((puVar5 = puVar4, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar5[2]))) {
                cVar1 = *(char *)((int)puVar5[1] + 0x2d);
                puVar4 = (undefined4 *)puVar5[1];
                puVar3 = puVar5;
              }
            }
          }
          iVar7 = iVar7 + 1;
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar2);
  }
  return;
}



// Function: FUN_1000e280 at 1000e280

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
FUN_1000e280(void *this,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,
            undefined4 *param_2)

{
  uint uVar1;
  char *pcVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 **ppuVar5;
  char *pcVar6;
  uint in_stack_00000018;
  uint in_stack_0000001c;
  undefined4 *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a8a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = (undefined4 *)0x0;
  local_8 = 0;
  local_18 = FUN_1000e070(this,&param_2);
  local_14 = *(undefined4 **)((int)this + 4);
  if (local_18 != local_14) {
    uVar1 = local_18[7];
    puVar3 = local_18 + 3;
    if (0xf < (uint)local_18[8]) {
      puVar3 = (undefined4 *)*puVar3;
    }
    uVar4 = in_stack_00000018;
    if (uVar1 <= in_stack_00000018) {
      uVar4 = uVar1;
    }
    ppuVar5 = (undefined4 **)param_2;
    if (in_stack_0000001c < 0x10) {
      ppuVar5 = &param_2;
    }
    uVar4 = FUN_10006c69(ppuVar5,puVar3,uVar4);
    if (uVar4 == 0) {
      if (in_stack_00000018 < uVar1) goto LAB_1000e31e;
      uVar4 = (uint)(in_stack_00000018 != uVar1);
    }
    if (-1 < (int)uVar4) {
      ppuVar5 = &local_18;
      goto LAB_1000e324;
    }
  }
LAB_1000e31e:
  ppuVar5 = &local_14;
LAB_1000e324:
  puVar3 = *ppuVar5;
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
  if (puVar3 == local_14) {
    pcVar2 = (char *)0x0;
    do {
      pcVar6 = pcVar2;
      pcVar2 = pcVar6 + 1;
    } while (*pcVar6 != '\0');
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              (param_1,(char *)0x0,(uint)pcVar6);
  }
  else {
    FUN_10001f4b(param_1,puVar3 + 10,0,0xffffffff);
  }
  if (0xf < in_stack_0000001c) {
    operator_delete(param_2);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000e390 at 1000e390

void __thiscall
FUN_1000e390(void *this,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1)

{
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> bVar1;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar2;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar3;
  uint in_stack_ffffffa0;
  undefined4 *puVar4;
  void *local_30 [5];
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a8d8;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar4 = (undefined4 *)(in_stack_ffffffa0 & 0xffffff00);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xffffffa0,"name",4);
  pbVar2 = FUN_1000e280((void *)((int)this + 4),
                        (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                         *)local_30,puVar4);
  local_8 = 0;
  if (0xf < *(uint *)(pbVar2 + 0x14)) {
    pbVar2 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
              pbVar2;
  }
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
  pbVar3 = pbVar2;
  do {
    bVar1 = *pbVar3;
    pbVar3 = pbVar3 + 1;
  } while (bVar1 != (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)
                    0x0);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            (param_1,(char *)pbVar2,(int)pbVar3 - (int)(pbVar2 + 1));
  if (0xf < local_1c) {
    operator_delete(local_30[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000e460 at 1000e460

uint __thiscall FUN_1000e460(void *this,void *param_1)

{
  char cVar1;
  undefined1 uVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  char *pcVar5;
  uint in_stack_00000018;
  uint in_stack_ffffffc0;
  undefined4 *puVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a998;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  pcVar3 = (char *)FUN_1000b4e0(&param_1);
  puVar6 = (undefined4 *)(in_stack_ffffffc0 & 0xffffff00);
  pcVar5 = pcVar3;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xffffffc0,pcVar3,(int)pcVar5 - (int)(pcVar3 + 1));
  uVar4 = FUN_1000bb70((void *)((int)this + 0x24),puVar6);
  uVar2 = (undefined1)uVar4;
  if (0xf < in_stack_00000018) {
    operator_delete(param_1);
    uVar4 = extraout_EAX;
  }
  ExceptionList = local_10;
  return CONCAT31((int3)((uint)uVar4 >> 8),uVar2);
}



// Function: FUN_1000e500 at 1000e500

undefined4 __thiscall FUN_1000e500(void *this,void *param_1)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  char *pcVar4;
  uint in_stack_00000018;
  uint in_stack_ffffffc0;
  undefined4 *puVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a998;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  pcVar2 = (char *)FUN_1000b4e0(&param_1);
  puVar5 = (undefined4 *)(in_stack_ffffffc0 & 0xffffff00);
  pcVar4 = pcVar2;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xffffffc0,pcVar2,(int)pcVar4 - (int)(pcVar2 + 1));
  uVar3 = FUN_1000bc60((void *)((int)this + 0x24),puVar5);
  if (0xf < in_stack_00000018) {
    operator_delete(param_1);
  }
  ExceptionList = local_10;
  return uVar3;
}



// Function: FUN_1000e5a0 at 1000e5a0

undefined4 __thiscall FUN_1000e5a0(void *this,void *param_1)

{
  char cVar1;
  char *pcVar2;
  void *this_00;
  undefined4 uVar3;
  char *pcVar4;
  uint in_stack_00000018;
  undefined4 *in_stack_00000020;
  uint in_stack_ffffffbc;
  undefined4 *puVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a908;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  pcVar2 = (char *)FUN_1000b4e0(&param_1);
  puVar5 = (undefined4 *)(in_stack_ffffffbc & 0xffffff00);
  pcVar4 = pcVar2;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xffffffbc,pcVar2,(int)pcVar4 - (int)(pcVar2 + 1));
  this_00 = (void *)FUN_1000bc60((void *)((int)this + 0x24),puVar5);
  if (this_00 != (void *)0x0) {
    uVar3 = FUN_10013900(this_00,in_stack_00000020);
    if (0xf < in_stack_00000018) {
      operator_delete(param_1);
    }
    ExceptionList = local_10;
    return uVar3;
  }
  *in_stack_00000020 = 0;
  if (0xf < in_stack_00000018) {
    operator_delete(param_1);
  }
  ExceptionList = local_10;
  return 6;
}



// Function: FUN_1000e680 at 1000e680

int __thiscall FUN_1000e680(void *this,void *param_1)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  void *pvVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  uint in_stack_00000018;
  uint in_stack_ffffffb4;
  undefined4 *puVar9;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a938;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = 0;
  pcVar3 = (char *)FUN_1000b4e0(&param_1);
  puVar9 = (undefined4 *)(in_stack_ffffffb4 & 0xffffff00);
  pcVar6 = pcVar3;
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xffffffb4,pcVar3,(int)pcVar6 - (int)(pcVar3 + 1));
  pvVar4 = (void *)FUN_1000bc60((void *)((int)this + 0x24),puVar9);
  if (pvVar4 == (void *)0x0) {
    iVar5 = FUN_1000b460((int)&param_1);
    if (iVar5 == 0) {
      iVar5 = *(int *)((int)this + 0x2c);
      iVar7 = 0;
      if (0 < iVar5) {
        do {
          if ((-1 < iVar7) && (iVar7 < *(int *)((int)this + 0x2c))) {
            piVar2 = *(int **)((int)this + 0x28);
            local_18 = (int *)*piVar2;
            iVar8 = 0;
            while (local_18 != piVar2) {
              if (iVar8 == iVar7) {
                if (((void *)local_18[10] != (void *)0x0) &&
                   (iVar8 = FUN_100166c0((void *)local_18[10]), iVar8 != 0)) {
                  local_14 = iVar8;
                }
                break;
              }
              FUN_1000b790((int *)&local_18);
              iVar8 = iVar8 + 1;
            }
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < iVar5);
      }
    }
    else {
      local_14 = 6;
    }
  }
  else {
    local_14 = FUN_100166c0(pvVar4);
  }
  if (0xf < in_stack_00000018) {
    operator_delete(param_1);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_1000e7a0 at 1000e7a0

void __thiscall FUN_1000e7a0(void *this,void *param_1)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  uint in_stack_00000018;
  uint in_stack_ffffff64;
  undefined4 *puVar8;
  int *local_68;
  byte local_61;
  undefined1 local_60 [76];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a968;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  pcVar3 = (char *)FUN_1000b4e0(&param_1);
  puVar8 = (undefined4 *)(in_stack_ffffff64 & 0xffffff00);
  pcVar5 = pcVar3;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xffffff64,pcVar3,(int)pcVar5 - (int)(pcVar3 + 1));
  iVar4 = FUN_1000bc60((void *)((int)this + 0x24),puVar8);
  if (iVar4 == 0) {
    iVar4 = FUN_1000b460((int)&param_1);
    if (iVar4 != 0) {
      FUN_1000bab0(local_60,(int *)"Entry Not Found.",6);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_60,(ThrowInfo *)&DAT_10023ca4);
    }
    iVar4 = *(int *)((int)this + 0x2c);
    iVar6 = 0;
    local_61 = 0;
    if (0 < iVar4) {
      do {
        if ((-1 < iVar6) && (iVar6 < *(int *)((int)this + 0x2c))) {
          piVar2 = *(int **)((int)this + 0x28);
          local_68 = (int *)*piVar2;
          iVar7 = 0;
          while (local_68 != piVar2) {
            if (iVar7 == iVar6) {
              if (local_68[10] != 0) {
                local_61 = local_61 | *(byte *)(local_68[10] + 0x14);
              }
              break;
            }
            FUN_1000b790((int *)&local_68);
            iVar7 = iVar7 + 1;
          }
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar4);
    }
    if (0xf < in_stack_00000018) {
      operator_delete(param_1);
    }
  }
  else if (0xf < in_stack_00000018) {
    operator_delete(param_1);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000e8f0 at 1000e8f0

void __thiscall FUN_1000e8f0(void *this,void *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  uint in_stack_00000018;
  undefined1 in_stack_00000020;
  uint in_stack_ffffffc0;
  undefined4 *puVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a998;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  pcVar2 = (char *)FUN_1000b4e0(&param_1);
  puVar5 = (undefined4 *)(in_stack_ffffffc0 & 0xffffff00);
  pcVar4 = pcVar2;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xffffffc0,pcVar2,(int)pcVar4 - (int)(pcVar2 + 1));
  iVar3 = FUN_1000bc60((void *)((int)this + 0x24),puVar5);
  if (iVar3 != 0) {
    *(undefined1 *)(iVar3 + 0x14) = in_stack_00000020;
  }
  if (0xf < in_stack_00000018) {
    operator_delete(param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000e9a0 at 1000e9a0

undefined4 * __thiscall FUN_1000e9a0(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *this_00;
  int *piVar1;
  bool bVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 local_c [2];
  
  piVar1 = param_3;
  piVar3 = *(int **)((int)this + 4);
  this_00 = param_3 + 3;
  if (*(int *)((int)this + 8) == 0) {
    FUN_1000c880(this,param_1,'\x01',piVar3,param_3);
    return param_1;
  }
  if (param_2 == (int *)*piVar3) {
    piVar3 = param_2 + 3;
    if (0xf < (uint)param_2[8]) {
      piVar3 = (int *)*piVar3;
    }
    uVar4 = FUN_1000b470(this_00,0,param_3[7],piVar3,param_2[7]);
    if ((int)uVar4 < 0) {
      FUN_1000c880(this,param_1,'\x01',param_2,piVar1);
      return param_1;
    }
  }
  else if (param_2 == piVar3) {
    bVar2 = FUN_1000b830((void *)(piVar3[2] + 0xc),this_00);
    if (bVar2) {
      FUN_1000c880(this,param_1,'\0',*(undefined4 **)(*(int *)((int)this + 4) + 8),piVar1);
      return param_1;
    }
  }
  else {
    bVar2 = FUN_1000b830(this_00,param_2 + 3);
    if (bVar2) {
      param_3 = param_2;
      FUN_1000df30((int *)&param_3);
      bVar2 = FUN_1000b830(param_3 + 3,this_00);
      if (bVar2) {
        if (*(char *)(param_3[2] + 0x2d) == '\0') {
          FUN_1000c880(this,param_1,'\x01',param_2,piVar1);
          return param_1;
        }
        FUN_1000c880(this,param_1,'\0',param_3,piVar1);
        return param_1;
      }
    }
    bVar2 = FUN_1000b830(param_2 + 3,this_00);
    if (bVar2) {
      param_3 = param_2;
      FUN_1000b790((int *)&param_3);
      if ((param_3 == *(int **)((int)this + 4)) ||
         (bVar2 = FUN_1000b830(this_00,param_3 + 3), bVar2)) {
        if (*(char *)(param_2[2] + 0x2d) == '\0') {
          FUN_1000c880(this,param_1,'\x01',param_3,piVar1);
          return param_1;
        }
        FUN_1000c880(this,param_1,'\0',param_2,piVar1);
        return param_1;
      }
    }
  }
  puVar5 = (undefined4 *)FUN_1000cdb0(this,local_c,piVar1,(undefined4 *)0x0);
  *param_1 = *puVar5;
  return param_1;
}



// Function: FUN_1000eb60 at 1000eb60

undefined4 * __thiscall FUN_1000eb60(void *this,char *param_1)

{
  char *pcVar1;
  undefined4 *puVar2;
  uint uStack_3c;
  undefined **local_2c [3];
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a9d1;
  local_10 = ExceptionList;
  uStack_3c = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_3c;
  ExceptionList = &local_10;
  puVar2 = (undefined4 *)operator_new(0x30);
  pcVar1 = param_1;
  local_18 = puVar2;
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = *(undefined4 *)((int)this + 4);
    puVar2[1] = *(undefined4 *)((int)this + 4);
    local_20 = puVar2 + 3;
    puVar2[2] = *(undefined4 *)((int)this + 4);
    *(undefined2 *)(puVar2 + 0xb) = 0;
    local_8 = 1;
    if (local_20 != (undefined4 *)0x0) {
      puVar2[8] = 0xf;
      puVar2[7] = 0;
      *(undefined1 *)local_20 = 0;
      local_1c = local_20;
      FUN_10001f4b(local_20,(undefined4 *)param_1,0,0xffffffff);
      puVar2[10] = *(undefined4 *)(pcVar1 + 0x1c);
    }
    ExceptionList = local_10;
    return puVar2;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_2c,&param_1);
  local_2c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_2c,(ThrowInfo *)&DAT_10020dd4);
}



// Function: Catch_All@1000ec01 at 1000ec01

void Catch_All_1000ec01(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000ec40 at 1000ec40

void __thiscall FUN_1000ec40(void *this,undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  undefined4 local_38;
  void *local_34 [4];
  undefined4 local_24;
  uint local_20;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a9f8;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = FUN_1000e100(this,param_1);
  if (piVar1 != *(int **)((int)this + 4)) {
    piVar3 = piVar1 + 3;
    if (0xf < (uint)piVar1[8]) {
      piVar3 = (int *)*piVar3;
    }
    uVar2 = FUN_1000b470(param_1,0,param_1[4],piVar3,piVar1[7]);
    if (-1 < (int)uVar2) goto LAB_1000ecfa;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34[0] = (void *)((uint)local_34[0] & 0xffffff00);
  FUN_10001f4b(local_34,param_1,0,0xffffffff);
  local_18 = 0;
  local_8 = 0;
  piVar3 = FUN_1000eb60(this,(char *)local_34);
  FUN_1000e9a0(this,&local_38,piVar1,piVar3);
  if (0xf < local_20) {
    operator_delete(local_34[0]);
  }
LAB_1000ecfa:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000ed20 at 1000ed20

void __fastcall FUN_1000ed20(void *param_1)

{
  undefined4 local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b1d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = param_1;
  FUN_1000cf70(param_1,&local_18,(int *)**(int **)((int)param_1 + 4),*(int **)((int)param_1 + 4));
  operator_delete(*(void **)((int)param_1 + 4));
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000ed80 at 1000ed80

undefined4 __thiscall FUN_1000ed80(void *this,void *param_1)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  void *this_00;
  undefined4 *puVar6;
  char *pcVar7;
  undefined4 uStack00000014;
  uint in_stack_00000018;
  void *in_stack_00000020;
  uint in_stack_00000034;
  uint in_stack_ffffff3c;
  void *pvVar8;
  undefined1 local_a8 [16];
  undefined4 local_98;
  undefined4 local_94;
  undefined4 uStack_90;
  undefined1 auStack_88 [16];
  undefined4 uStack_78;
  uint in_stack_ffffff94;
  void *local_40 [5];
  uint local_2c;
  undefined1 *local_24;
  undefined1 *local_20;
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001aa5b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  local_14 = (undefined1 *)this;
  if (*(char *)((int)this + 0x20) != '\0') {
    if (0xf < in_stack_00000018) {
      operator_delete(param_1);
    }
    in_stack_00000018 = 0xf;
    uStack00000014 = 0;
    param_1 = (void *)((uint)param_1 & 0xffffff00);
    if (0xf < in_stack_00000034) {
      operator_delete(in_stack_00000020);
    }
    ExceptionList = local_10;
    return 5;
  }
  iVar3 = FUN_1000b460((int)&param_1);
  if (iVar3 == 0) {
    if (0xf < in_stack_00000018) {
      operator_delete(param_1);
    }
    in_stack_00000018 = 0xf;
    uStack00000014 = 0;
    param_1 = (void *)((uint)param_1 & 0xffffff00);
    if (0xf < in_stack_00000034) {
      operator_delete(in_stack_00000020);
    }
    ExceptionList = local_10;
    return 2;
  }
  pcVar4 = (char *)FUN_1000b4e0(&param_1);
  local_18 = &stack0xffffff94;
  puVar6 = (undefined4 *)(in_stack_ffffff94 & 0xffffff00);
  pcVar7 = pcVar4;
  do {
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  uStack_78 = 0x1000ee92;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xffffff94,pcVar4,(int)pcVar7 - (int)(pcVar4 + 1));
  puVar2 = local_14;
  uVar5 = FUN_1000bb70(local_14 + 0x24,puVar6);
  if ((char)uVar5 != '\0') {
    if (0xf < in_stack_00000018) {
      operator_delete(param_1);
    }
    in_stack_00000018 = 0xf;
    uStack00000014 = 0;
    param_1 = (void *)((uint)param_1 & 0xffffff00);
    if (0xf < in_stack_00000034) {
      operator_delete(in_stack_00000020);
    }
    ExceptionList = local_10;
    return 7;
  }
  this_00 = operator_new(0x18);
  local_8._0_1_ = 2;
  local_18 = (undefined1 *)this_00;
  if (this_00 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    local_14 = &stack0xffffff94;
    FUN_10006c43(&stack0xffffff94,"");
    local_1c = auStack_88;
    local_8._0_1_ = 3;
    uStack_90 = 0x1000ef31;
    FUN_10006c43(auStack_88,"");
    local_24 = local_a8;
    local_94 = 0xf;
    local_98 = 0;
    local_8._0_1_ = 4;
    local_a8[0] = 0;
    FUN_10001f4b(local_a8,&stack0x00000020,0,0xffffffff);
    local_20 = &stack0xffffff3c;
    local_8._0_1_ = 5;
    pvVar8 = (void *)(in_stack_ffffff3c & 0xffffff00);
    FUN_10001f4b(&stack0xffffff3c,&param_1,0,0xffffffff);
    local_8._0_1_ = 2;
    uVar5 = FUN_100152a0(this_00,pvVar8);
  }
  local_8._0_1_ = 1;
  pcVar7 = (char *)FUN_1000b4e0(&param_1);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_40,pcVar7);
  local_8 = CONCAT31(local_8._1_3_,6);
  puVar6 = (undefined4 *)FUN_1000ec40(puVar2 + 0x24,local_40);
  *puVar6 = uVar5;
  if (0xf < local_2c) {
    operator_delete(local_40[0]);
  }
  if (0xf < in_stack_00000018) {
    operator_delete(param_1);
  }
  in_stack_00000018 = 0xf;
  uStack00000014 = 0;
  param_1 = (void *)((uint)param_1 & 0xffffff00);
  if (0xf < in_stack_00000034) {
    operator_delete(in_stack_00000020);
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_1000f010 at 1000f010

void __thiscall FUN_1000f010(void *this,void *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  void *this_00;
  undefined4 *puVar5;
  undefined4 *puVar6;
  char *pcVar7;
  uint in_stack_00000018;
  uint in_stack_fffffe60;
  void *pvVar8;
  undefined1 local_184 [16];
  undefined4 local_174;
  undefined1 local_164 [12];
  undefined4 uStack_158;
  uint in_stack_fffffeb8;
  void *local_104 [4];
  undefined4 local_f4;
  uint local_f0;
  void *local_e8 [4];
  undefined4 local_d8;
  uint local_d4;
  void *local_cc [4];
  undefined4 local_bc;
  uint local_b8;
  void *local_b0 [4];
  undefined4 local_a0;
  uint local_9c;
  char local_94 [128];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_1001ab04;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  uStack_7 = 0;
  if (*(char *)((int)this + 0x20) == '\0') {
    iVar2 = FUN_1000b460((int)&param_1);
    if (iVar2 == 0) {
      if (0xf < in_stack_00000018) {
        operator_delete(param_1);
      }
    }
    else {
      pcVar3 = (char *)FUN_1000b4e0(&param_1);
      puVar5 = (undefined4 *)(in_stack_fffffeb8 & 0xffffff00);
      pcVar7 = pcVar3;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &stack0xfffffeb8,pcVar3,(int)pcVar7 - (int)(pcVar3 + 1));
      uVar4 = FUN_1000bb70((void *)((int)this + 0x24),puVar5);
      if ((char)uVar4 == '\0') {
        local_94[0] = '\0';
        memset(local_94 + 1,0,0x7f);
        local_f0 = 0xf;
        local_f4 = 0;
        local_104[0] = (void *)((uint)local_104[0] & 0xffffff00);
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_104,"",0);
        local_8 = 1;
        sprintf_s(local_94,0x80,"%i");
        pcVar7 = local_94;
        local_9c = 0xf;
        local_a0 = 0;
        local_b0[0] = (void *)((uint)local_b0[0] & 0xffffff00);
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_b0,local_94,(int)pcVar7 - (int)(local_94 + 1));
        local_8 = 2;
        FUN_10001f4b(local_104,local_b0,0,0xffffffff);
        local_8 = 1;
        if (0xf < local_9c) {
          operator_delete(local_b0[0]);
        }
        memset(local_94,0,0x80);
        local_d4 = 0xf;
        local_d8 = 0;
        local_e8[0] = (void *)((uint)local_e8[0] & 0xffffff00);
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_e8,"",0);
        local_8 = 3;
        sprintf_s(local_94,0x80,"%i");
        pcVar7 = local_94;
        local_9c = 0xf;
        local_a0 = 0;
        local_b0[0] = (void *)((uint)local_b0[0] & 0xffffff00);
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_b0,local_94,(int)pcVar7 - (int)(local_94 + 1));
        local_8 = 4;
        FUN_10001f4b(local_e8,local_b0,0,0xffffffff);
        local_8 = 3;
        if (0xf < local_9c) {
          operator_delete(local_b0[0]);
        }
        memset(local_94,0,0x80);
        local_b8 = 0xf;
        local_bc = 0;
        local_cc[0] = (void *)((uint)local_cc[0] & 0xffffff00);
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_cc,"",0);
        local_8 = 5;
        sprintf_s(local_94,0x80,"%i");
        pcVar7 = local_94;
        local_9c = 0xf;
        local_a0 = 0;
        local_b0[0] = (void *)((uint)local_b0[0] & 0xffffff00);
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_b0,local_94,(int)pcVar7 - (int)(local_94 + 1));
        local_8 = 6;
        FUN_10001f4b(local_cc,local_b0,0,0xffffffff);
        local_8 = 5;
        if (0xf < local_9c) {
          operator_delete(local_b0[0]);
        }
        this_00 = operator_new(0x18);
        local_8 = 7;
        if (this_00 == (void *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          uStack_158 = 0x1000f399;
          FUN_10001f4b(&stack0xfffffeb8,local_cc,0,0xffffffff);
          local_8 = 8;
          local_164[0] = 0;
          local_174 = 0x1000f3bf;
          FUN_10001f4b(local_164,local_e8,0,0xffffffff);
          local_174 = 0;
          local_8 = 9;
          local_184[0] = 0;
          FUN_10001f4b(local_184,local_104,0,0xffffffff);
          local_8 = 10;
          pvVar8 = (void *)(in_stack_fffffe60 & 0xffffff00);
          FUN_10001f4b(&stack0xfffffe60,&param_1,0,0xffffffff);
          local_8 = 7;
          puVar5 = (undefined4 *)FUN_100152a0(this_00,pvVar8);
        }
        local_8 = 5;
        if ((puVar5 == (undefined4 *)0x0) || (iVar2 = FUN_100166c0(puVar5), iVar2 == 0)) {
          *(undefined1 *)(puVar5 + 5) = 0;
          pcVar7 = (char *)FUN_1000b4e0(&param_1);
          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
          basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                    ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )local_b0,pcVar7);
          local_8 = 0xb;
          puVar6 = (undefined4 *)FUN_1000ec40((void *)((int)this + 0x24),local_b0);
          *puVar6 = puVar5;
          if (0xf < local_9c) {
            operator_delete(local_b0[0]);
          }
          if (0xf < local_b8) {
            operator_delete(local_cc[0]);
          }
          local_b8 = 0xf;
          local_bc = 0;
          local_cc[0] = (void *)((uint)local_cc[0] & 0xffffff00);
          if (0xf < local_d4) {
            operator_delete(local_e8[0]);
          }
          local_d4 = 0xf;
          local_d8 = 0;
          local_e8[0] = (void *)((uint)local_e8[0] & 0xffffff00);
          if (0xf < local_f0) {
            operator_delete(local_104[0]);
          }
          local_f0 = 0xf;
          local_f4 = 0;
          local_104[0] = (void *)((uint)local_104[0] & 0xffffff00);
          if (0xf < in_stack_00000018) {
            operator_delete(param_1);
          }
        }
        else {
          (**(code **)*puVar5)();
          FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)local_cc);
          FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)local_e8);
          FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)local_104);
          FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)&param_1);
        }
      }
      else if (0xf < in_stack_00000018) {
        operator_delete(param_1);
      }
    }
  }
  else if (0xf < in_stack_00000018) {
    operator_delete(param_1);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000f570 at 1000f570

void __thiscall FUN_1000f570(void *this,void *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  void *this_00;
  undefined4 *puVar5;
  undefined4 *puVar6;
  char *pcVar7;
  uint in_stack_00000018;
  uint in_stack_fffffe60;
  void *pvVar8;
  undefined1 auStack_184 [16];
  undefined4 uStack_174;
  undefined1 auStack_164 [12];
  undefined4 uStack_158;
  uint in_stack_fffffeb8;
  void *local_104 [4];
  undefined4 local_f4;
  uint local_f0;
  void *local_e8 [4];
  undefined4 local_d8;
  uint local_d4;
  void *local_cc [4];
  undefined4 local_bc;
  uint local_b8;
  void *local_b0 [4];
  undefined4 local_a0;
  uint local_9c;
  char local_94 [128];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_1001ab04;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  uStack_7 = 0;
  if (*(char *)((int)this + 0x20) == '\0') {
    iVar2 = FUN_1000b460((int)&param_1);
    if (iVar2 == 0) {
      if (0xf < in_stack_00000018) {
        operator_delete(param_1);
      }
    }
    else {
      pcVar3 = (char *)FUN_1000b4e0(&param_1);
      puVar5 = (undefined4 *)(in_stack_fffffeb8 & 0xffffff00);
      pcVar7 = pcVar3;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &stack0xfffffeb8,pcVar3,(int)pcVar7 - (int)(pcVar3 + 1));
      uVar4 = FUN_1000bb70((void *)((int)this + 0x24),puVar5);
      if ((char)uVar4 == '\0') {
        local_94[0] = '\0';
        memset(local_94 + 1,0,0x7f);
        local_f0 = 0xf;
        local_f4 = 0;
        local_104[0] = (void *)((uint)local_104[0] & 0xffffff00);
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_104,"",0);
        local_8 = 1;
        sprintf_s(local_94,0x80,"%f");
        pcVar7 = local_94;
        local_9c = 0xf;
        local_a0 = 0;
        local_b0[0] = (void *)((uint)local_b0[0] & 0xffffff00);
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_b0,local_94,(int)pcVar7 - (int)(local_94 + 1));
        local_8 = 2;
        FUN_10001f4b(local_104,local_b0,0,0xffffffff);
        local_8 = 1;
        if (0xf < local_9c) {
          operator_delete(local_b0[0]);
        }
        memset(local_94,0,0x80);
        local_d4 = 0xf;
        local_d8 = 0;
        local_e8[0] = (void *)((uint)local_e8[0] & 0xffffff00);
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_e8,"",0);
        local_8 = 3;
        sprintf_s(local_94,0x80,"%f");
        pcVar7 = local_94;
        local_9c = 0xf;
        local_a0 = 0;
        local_b0[0] = (void *)((uint)local_b0[0] & 0xffffff00);
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_b0,local_94,(int)pcVar7 - (int)(local_94 + 1));
        local_8 = 4;
        FUN_10001f4b(local_e8,local_b0,0,0xffffffff);
        local_8 = 3;
        if (0xf < local_9c) {
          operator_delete(local_b0[0]);
        }
        memset(local_94,0,0x80);
        local_b8 = 0xf;
        local_bc = 0;
        local_cc[0] = (void *)((uint)local_cc[0] & 0xffffff00);
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_cc,"",0);
        local_8 = 5;
        sprintf_s(local_94,0x80,"%f");
        pcVar7 = local_94;
        local_9c = 0xf;
        local_a0 = 0;
        local_b0[0] = (void *)((uint)local_b0[0] & 0xffffff00);
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_b0,local_94,(int)pcVar7 - (int)(local_94 + 1));
        local_8 = 6;
        FUN_10001f4b(local_cc,local_b0,0,0xffffffff);
        local_8 = 5;
        if (0xf < local_9c) {
          operator_delete(local_b0[0]);
        }
        this_00 = operator_new(0x18);
        local_8 = 7;
        if (this_00 == (void *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          uStack_158 = 0x1000f911;
          FUN_10001f4b(&stack0xfffffeb8,local_cc,0,0xffffffff);
          local_8 = 8;
          auStack_164[0] = 0;
          uStack_174 = 0x1000f937;
          FUN_10001f4b(auStack_164,local_e8,0,0xffffffff);
          uStack_174 = 0;
          local_8 = 9;
          auStack_184[0] = 0;
          FUN_10001f4b(auStack_184,local_104,0,0xffffffff);
          local_8 = 10;
          pvVar8 = (void *)(in_stack_fffffe60 & 0xffffff00);
          FUN_10001f4b(&stack0xfffffe60,&param_1,0,0xffffffff);
          local_8 = 7;
          puVar5 = (undefined4 *)FUN_100152a0(this_00,pvVar8);
        }
        local_8 = 5;
        if ((puVar5 == (undefined4 *)0x0) || (iVar2 = FUN_100166c0(puVar5), iVar2 == 0)) {
          *(undefined1 *)(puVar5 + 5) = 0;
          pcVar7 = (char *)FUN_1000b4e0(&param_1);
          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
          basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                    ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )local_b0,pcVar7);
          local_8 = 0xb;
          puVar6 = (undefined4 *)FUN_1000ec40((void *)((int)this + 0x24),local_b0);
          *puVar6 = puVar5;
          if (0xf < local_9c) {
            operator_delete(local_b0[0]);
          }
          if (0xf < local_b8) {
            operator_delete(local_cc[0]);
          }
          local_b8 = 0xf;
          local_bc = 0;
          local_cc[0] = (void *)((uint)local_cc[0] & 0xffffff00);
          if (0xf < local_d4) {
            operator_delete(local_e8[0]);
          }
          local_d4 = 0xf;
          local_d8 = 0;
          local_e8[0] = (void *)((uint)local_e8[0] & 0xffffff00);
          if (0xf < local_f0) {
            operator_delete(local_104[0]);
          }
          local_f0 = 0xf;
          local_f4 = 0;
          local_104[0] = (void *)((uint)local_104[0] & 0xffffff00);
          if (0xf < in_stack_00000018) {
            operator_delete(param_1);
          }
        }
        else {
          (**(code **)*puVar5)();
          FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)local_cc);
          FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)local_e8);
          FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)local_104);
          FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)&param_1);
        }
      }
      else if (0xf < in_stack_00000018) {
        operator_delete(param_1);
      }
    }
  }
  else if (0xf < in_stack_00000018) {
    operator_delete(param_1);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000fae0 at 1000fae0

void __thiscall FUN_1000fae0(void *this,void *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  void *this_00;
  undefined4 *puVar5;
  undefined4 *puVar6;
  char *pcVar7;
  uint in_stack_00000018;
  uint in_stack_fffffe9c;
  void *pvVar8;
  undefined1 auStack_148 [16];
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined1 auStack_128 [16];
  undefined4 uStack_118;
  uint in_stack_fffffef4;
  void *local_cc [4];
  undefined4 local_bc;
  uint local_b8;
  void *local_b0 [4];
  undefined4 local_a0;
  uint local_9c;
  char local_94 [128];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_1001ab88;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  uStack_7 = 0;
  if (*(char *)((int)this + 0x20) == '\0') {
    iVar2 = FUN_1000b460((int)&param_1);
    if (iVar2 == 0) {
      if (0xf < in_stack_00000018) {
        operator_delete(param_1);
      }
    }
    else {
      pcVar3 = (char *)FUN_1000b4e0(&param_1);
      puVar5 = (undefined4 *)(in_stack_fffffef4 & 0xffffff00);
      pcVar7 = pcVar3;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      uStack_118 = 0x1000fb9a;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &stack0xfffffef4,pcVar3,(int)pcVar7 - (int)(pcVar3 + 1));
      uVar4 = FUN_1000bb70((void *)((int)this + 0x24),puVar5);
      if ((char)uVar4 == '\0') {
        local_94[0] = '\0';
        memset(local_94 + 1,0,0x7f);
        local_9c = 0xf;
        local_a0 = 0;
        local_b0[0] = (void *)((uint)local_b0[0] & 0xffffff00);
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_b0,"",0);
        local_8 = 1;
        sprintf_s(local_94,0x80,"%i");
        pcVar7 = local_94;
        local_b8 = 0xf;
        local_bc = 0;
        local_cc[0] = (void *)((uint)local_cc[0] & 0xffffff00);
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_cc,local_94,(int)pcVar7 - (int)(local_94 + 1));
        local_8 = 2;
        FUN_10001f4b(local_b0,local_cc,0,0xffffffff);
        local_8 = 1;
        if (0xf < local_b8) {
          operator_delete(local_cc[0]);
        }
        this_00 = operator_new(0x18);
        local_8 = 3;
        if (this_00 == (void *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          FUN_10006c43(&stack0xfffffef4,"1");
          local_8 = 4;
          uStack_130 = 0x1000fce3;
          FUN_10006c43(auStack_128,"0");
          uStack_134 = 0xf;
          uStack_138 = 0;
          local_8 = 5;
          auStack_148[0] = 0;
          FUN_10001f4b(auStack_148,local_b0,0,0xffffffff);
          local_8 = 6;
          pvVar8 = (void *)(in_stack_fffffe9c & 0xffffff00);
          FUN_10001f4b(&stack0xfffffe9c,&param_1,0,0xffffffff);
          local_8 = 3;
          puVar5 = (undefined4 *)FUN_100152a0(this_00,pvVar8);
        }
        local_8 = 1;
        if ((puVar5 == (undefined4 *)0x0) || (iVar2 = FUN_100166c0(puVar5), iVar2 == 0)) {
          *(undefined1 *)(puVar5 + 5) = 0;
          pcVar7 = (char *)FUN_1000b4e0(&param_1);
          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
          basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                    ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )local_cc,pcVar7);
          local_8 = 7;
          puVar6 = (undefined4 *)FUN_1000ec40((void *)((int)this + 0x24),local_cc);
          *puVar6 = puVar5;
          if (0xf < local_b8) {
            operator_delete(local_cc[0]);
          }
          if (0xf < local_9c) {
            operator_delete(local_b0[0]);
          }
          local_9c = 0xf;
          local_a0 = 0;
          local_b0[0] = (void *)((uint)local_b0[0] & 0xffffff00);
          if (0xf < in_stack_00000018) {
            operator_delete(param_1);
          }
        }
        else {
          (**(code **)*puVar5)();
          FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)local_b0);
          FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)&param_1);
        }
      }
      else if (0xf < in_stack_00000018) {
        operator_delete(param_1);
      }
    }
  }
  else if (0xf < in_stack_00000018) {
    operator_delete(param_1);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000fe30 at 1000fe30

undefined4 __thiscall FUN_1000fe30(void *this,void *param_1)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  void *this_00;
  undefined4 *puVar6;
  undefined4 *puVar7;
  char *pcVar8;
  undefined4 uStack00000014;
  uint in_stack_00000018;
  void *in_stack_00000020;
  undefined4 uStack00000030;
  uint in_stack_00000034;
  void *in_stack_0000003c;
  uint in_stack_00000050;
  uint in_stack_ffffff3c;
  void *pvVar9;
  undefined1 local_a8 [16];
  undefined4 local_98;
  undefined1 local_88 [16];
  undefined4 local_78;
  uint in_stack_ffffff94;
  void *local_40 [5];
  uint local_2c;
  undefined1 *local_24;
  undefined1 *local_20;
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001abf3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
  local_14 = (undefined1 *)this;
  if (*(char *)((int)this + 0x20) != '\0') {
    if (0xf < in_stack_00000018) {
      operator_delete(param_1);
    }
    in_stack_00000018 = 0xf;
    uStack00000014 = 0;
    param_1 = (void *)((uint)param_1 & 0xffffff00);
    if (0xf < in_stack_00000034) {
      operator_delete(in_stack_00000020);
    }
    in_stack_00000034 = 0xf;
    uStack00000030 = 0;
    in_stack_00000020 = (void *)((uint)in_stack_00000020 & 0xffffff00);
    if (0xf < in_stack_00000050) {
      operator_delete(in_stack_0000003c);
    }
    ExceptionList = local_10;
    return 5;
  }
  iVar3 = FUN_1000b460((int)&param_1);
  if (iVar3 == 0) {
    if (0xf < in_stack_00000018) {
      operator_delete(param_1);
    }
    in_stack_00000018 = 0xf;
    uStack00000014 = 0;
    param_1 = (void *)((uint)param_1 & 0xffffff00);
    if (0xf < in_stack_00000034) {
      operator_delete(in_stack_00000020);
    }
    in_stack_00000034 = 0xf;
    uStack00000030 = 0;
    in_stack_00000020 = (void *)((uint)in_stack_00000020 & 0xffffff00);
    if (0xf < in_stack_00000050) {
      operator_delete(in_stack_0000003c);
    }
    ExceptionList = local_10;
    return 2;
  }
  pcVar4 = (char *)FUN_1000b4e0(&param_1);
  local_18 = &stack0xffffff94;
  puVar6 = (undefined4 *)(in_stack_ffffff94 & 0xffffff00);
  pcVar8 = pcVar4;
  do {
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  local_78 = 0x1000ff7a;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xffffff94,pcVar4,(int)pcVar8 - (int)(pcVar4 + 1));
  puVar2 = local_14;
  uVar5 = FUN_1000bb70(local_14 + 0x24,puVar6);
  if ((char)uVar5 != '\0') {
    if (0xf < in_stack_00000018) {
      operator_delete(param_1);
    }
    in_stack_00000018 = 0xf;
    uStack00000014 = 0;
    param_1 = (void *)((uint)param_1 & 0xffffff00);
    if (0xf < in_stack_00000034) {
      operator_delete(in_stack_00000020);
    }
    in_stack_00000034 = 0xf;
    uStack00000030 = 0;
    in_stack_00000020 = (void *)((uint)in_stack_00000020 & 0xffffff00);
    if (0xf < in_stack_00000050) {
      operator_delete(in_stack_0000003c);
    }
    ExceptionList = local_10;
    return 7;
  }
  this_00 = operator_new(0x18);
  local_8._0_1_ = 3;
  local_18 = (undefined1 *)this_00;
  if (this_00 == (void *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    local_14 = &stack0xffffff94;
    FUN_10006c43(&stack0xffffff94,"");
    local_1c = local_88;
    local_78 = 0;
    local_8._0_1_ = 4;
    local_88[0] = 0;
    local_98 = 0x10010042;
    FUN_10001f4b(local_88,&stack0x0000003c,0,0xffffffff);
    local_24 = local_a8;
    local_98 = 0;
    local_8._0_1_ = 5;
    local_a8[0] = 0;
    FUN_10001f4b(local_a8,&stack0x00000020,0,0xffffffff);
    local_20 = &stack0xffffff3c;
    local_8._0_1_ = 6;
    pvVar9 = (void *)(in_stack_ffffff3c & 0xffffff00);
    FUN_10001f4b(&stack0xffffff3c,&param_1,0,0xffffffff);
    local_8._0_1_ = 3;
    puVar6 = (undefined4 *)FUN_100152a0(this_00,pvVar9);
  }
  local_8._0_1_ = 2;
  if (puVar6 != (undefined4 *)0x0) {
    iVar3 = FUN_100166c0(puVar6);
    if (iVar3 != 0) {
      (**(code **)*puVar6)();
      FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &param_1);
      FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &stack0x00000020);
      FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &stack0x0000003c);
      ExceptionList = local_10;
      return 8;
    }
  }
  *(undefined1 *)(puVar6 + 5) = 0;
  pcVar8 = (char *)FUN_1000b4e0(&param_1);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_40,pcVar8);
  local_8 = CONCAT31(local_8._1_3_,7);
  puVar7 = (undefined4 *)FUN_1000ec40(puVar2 + 0x24,local_40);
  *puVar7 = puVar6;
  if (0xf < local_2c) {
    operator_delete(local_40[0]);
  }
  if (0xf < in_stack_00000018) {
    operator_delete(param_1);
  }
  in_stack_00000018 = 0xf;
  uStack00000014 = 0;
  param_1 = (void *)((uint)param_1 & 0xffffff00);
  if (0xf < in_stack_00000034) {
    operator_delete(in_stack_00000020);
  }
  in_stack_00000034 = 0xf;
  uStack00000030 = 0;
  in_stack_00000020 = (void *)((uint)in_stack_00000020 & 0xffffff00);
  if (0xf < in_stack_00000050) {
    operator_delete(in_stack_0000003c);
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_10010190 at 10010190

void __thiscall FUN_10010190(void *this,void *param_1)

{
  char cVar1;
  char *pcVar2;
  void *pvVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 uStack00000014;
  uint in_stack_00000018;
  int in_stack_00000020;
  float in_stack_00000024;
  void *in_stack_00000028;
  uint in_stack_0000003c;
  uint in_stack_ffffff54;
  void *pvVar6;
  int iVar7;
  float fVar8;
  uint uVar9;
  uint in_stack_ffffff74;
  void *local_60 [4];
  undefined4 local_50;
  uint local_4c;
  undefined1 *local_44;
  undefined1 *local_40;
  undefined1 *local_3c;
  undefined4 local_38;
  char *local_34;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ac43;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  local_38 = 0;
  pcVar2 = (char *)FUN_1000b4e0(&param_1);
  local_34 = pcVar2 + 1;
  puVar4 = (undefined4 *)(in_stack_ffffff74 & 0xffffff00);
  pcVar5 = pcVar2;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xffffff74,pcVar2,(int)pcVar5 - (int)local_34);
  local_34 = (char *)((int)this + 0x24);
  uVar9 = 0x1001020c;
  pvVar3 = (void *)FUN_1000bc60(local_34,puVar4);
  if (pvVar3 == (void *)0x0) {
    if (*(char *)((int)this + 0x20) == '\0') {
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 local_30,"",0);
      local_3c = &stack0xffffff68;
      local_8._0_1_ = 2;
      pvVar3 = (void *)(uVar9 & 0xffffff00);
      iVar7 = in_stack_00000020;
      fVar8 = in_stack_00000024;
      FUN_10001f4b(&stack0xffffff70,&stack0x00000028,0,0xffffffff);
      FUN_10013750(iVar7,fVar8,pvVar3);
      pvVar3 = operator_new(0x18);
      local_8._0_1_ = 3;
      local_3c = (undefined1 *)pvVar3;
      if (pvVar3 == (void *)0x0) {
        pvVar3 = (void *)0x0;
      }
      else {
        local_44 = &stack0xffffff70;
        FUN_10001f4b(&stack0xffffff70,local_30,0,0xffffffff);
        local_40 = &stack0xffffff54;
        local_8._0_1_ = 4;
        pvVar6 = (void *)(in_stack_ffffff54 & 0xffffff00);
        FUN_10001f4b(&stack0xffffff54,&param_1,0,0xffffffff);
        local_8._0_1_ = 3;
        pvVar3 = (void *)FUN_100157d0(pvVar3,pvVar6);
      }
      local_40 = &stack0xffffff6c;
      local_8._0_1_ = 2;
      pvVar6 = (void *)((uint)puVar4 & 0xffffff00);
      FUN_10001f4b(&stack0xffffff74,&stack0x00000028,0,0xffffffff);
      FUN_10015d80(pvVar3,in_stack_00000020,in_stack_00000024,pvVar6);
      pcVar2 = (char *)FUN_1000b4e0(&param_1);
      local_4c = 0xf;
      local_50 = 0;
      local_60[0] = (void *)((uint)local_60[0] & 0xffffff00);
      pcVar5 = pcVar2;
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 local_60,pcVar2,(int)pcVar5 - (int)(pcVar2 + 1));
      local_8 = CONCAT31(local_8._1_3_,5);
      puVar4 = (undefined4 *)FUN_1000ec40(local_34,local_60);
      *puVar4 = pvVar3;
      if (0xf < local_4c) {
        operator_delete(local_60[0]);
      }
      if (0xf < local_1c) {
        operator_delete(local_30[0]);
      }
    }
    else {
      local_38 = 6;
    }
  }
  else {
    local_34 = &stack0xffffff6c;
    pvVar6 = (void *)((uint)puVar4 & 0xffffff00);
    FUN_10001f4b(&stack0xffffff74,&stack0x00000028,0,0xffffffff);
    local_38 = FUN_10015d80(pvVar3,in_stack_00000020,in_stack_00000024,pvVar6);
  }
  if (0xf < in_stack_00000018) {
    operator_delete(param_1);
  }
  in_stack_00000018 = 0xf;
  uStack00000014 = 0;
  param_1 = (void *)((uint)param_1 & 0xffffff00);
  if (0xf < in_stack_0000003c) {
    operator_delete(in_stack_00000028);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10010440 at 10010440

undefined4 * __thiscall FUN_10010440(void *this,void *param_1)

{
  void *pvVar1;
  uint in_stack_00000018;
  undefined **local_24 [3];
  void *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ac8b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = SharedConfigurationLibrary_Internal::ConfigSetting::vftable;
  *(undefined4 *)((int)this + 0x18) = 0xf;
  *(undefined4 *)((int)this + 0x14) = 0;
  local_8 = 1;
  *(undefined1 *)((int)this + 4) = 0;
  local_18 = this;
  FUN_10001f4b((undefined1 *)((int)this + 4),&param_1,0,0xffffffff);
  *(undefined1 *)((int)this + 0x20) = 0;
  local_8 = CONCAT31(local_8._1_3_,2);
  *(undefined4 *)((int)this + 0x2c) = 0;
  pvVar1 = operator_new(0x30);
  if (pvVar1 != (void *)0x0) {
    *(void **)((int)this + 0x28) = pvVar1;
    *(void **)pvVar1 = pvVar1;
    *(int *)(*(int *)((int)this + 0x28) + 4) = *(int *)((int)this + 0x28);
    *(int *)(*(int *)((int)this + 0x28) + 8) = *(int *)((int)this + 0x28);
    *(undefined1 *)(*(int *)((int)this + 0x28) + 0x2c) = 1;
    *(undefined1 *)(*(int *)((int)this + 0x28) + 0x2d) = 1;
    if (0xf < in_stack_00000018) {
      operator_delete(param_1);
    }
    ExceptionList = local_10;
    return (undefined4 *)this;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_24,(ThrowInfo *)&DAT_10020dd4);
}



// Function: FUN_10010520 at 10010520

void __thiscall FUN_10010520(void *this,int param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  void *pvVar4;
  void *this_00;
  undefined4 *puVar5;
  undefined4 *puVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  undefined **local_6c [3];
  void *local_60 [4];
  undefined4 local_50;
  uint local_4c;
  int local_44;
  char *local_40;
  void *local_3c;
  int local_38;
  int local_34;
  void *local_30 [5];
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ace9;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = param_1;
  *(undefined ***)this = SharedConfigurationLibrary_Internal::ConfigSetting::vftable;
  *(undefined4 *)((int)this + 0x18) = 0xf;
  *(undefined4 *)((int)this + 0x14) = 0;
  local_8 = 0;
  *(undefined1 *)((int)this + 4) = 0;
  local_3c = this;
  FUN_10001f4b((undefined1 *)((int)this + 4),(undefined4 *)(param_1 + 4),0,0xffffffff);
  *(undefined1 *)((int)this + 0x20) = *(undefined1 *)(param_1 + 0x20);
  local_8._0_1_ = 1;
  *(undefined4 *)((int)this + 0x2c) = 0;
  pvVar4 = operator_new(0x30);
  if (pvVar4 == (void *)0x0) {
    local_40 = (char *)0x0;
    std::exception::exception((exception *)local_6c,&local_40);
    local_6c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_6c,(ThrowInfo *)&DAT_10020dd4);
  }
  *(void **)((int)this + 0x28) = pvVar4;
  *(void **)pvVar4 = pvVar4;
  *(int *)(*(int *)((int)this + 0x28) + 4) = *(int *)((int)this + 0x28);
  *(int *)(*(int *)((int)this + 0x28) + 8) = *(int *)((int)this + 0x28);
  *(undefined1 *)(*(int *)((int)this + 0x28) + 0x2c) = 1;
  *(undefined1 *)(*(int *)((int)this + 0x28) + 0x2d) = 1;
  local_44 = *(int *)(param_1 + 0x2c);
  local_8._0_1_ = 2;
  uVar2 = (undefined1)local_8;
  local_8._0_1_ = 2;
  local_34 = 0;
  if (0 < local_44) {
    do {
      if ((-1 < local_34) && (local_34 < *(int *)(param_1 + 0x2c))) {
        puVar5 = (undefined4 *)**(undefined4 **)(param_1 + 0x28);
        iVar9 = 0;
        while (puVar5 != *(undefined4 **)(param_1 + 0x28)) {
          if (iVar9 == local_34) {
            pvVar4 = (void *)puVar5[10];
            if (pvVar4 != (void *)0x0) {
              this_00 = operator_new(0x18);
              local_8._0_1_ = 3;
              if (this_00 == (void *)0x0) {
                puVar5 = (undefined4 *)0x0;
              }
              else {
                puVar5 = FUN_10015ca0(this_00,(int)pvVar4);
              }
              local_8._0_1_ = 2;
              puVar6 = (undefined4 *)
                       FUN_1000e390(pvVar4,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                                            *)local_30);
              local_8._0_1_ = 4;
              pcVar7 = (char *)FUN_1000b4e0(puVar6);
              local_4c = 0xf;
              local_50 = 0;
              local_60[0] = (void *)((uint)local_60[0] & 0xffffff00);
              pcVar8 = pcVar7;
              do {
                cVar1 = *pcVar8;
                pcVar8 = pcVar8 + 1;
              } while (cVar1 != '\0');
              std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
              assign((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )local_60,pcVar7,(int)pcVar8 - (int)(pcVar7 + 1));
              local_8 = CONCAT31(local_8._1_3_,5);
              puVar6 = (undefined4 *)FUN_1000ec40((void *)((int)local_3c + 0x24),local_60);
              *puVar6 = puVar5;
              if (0xf < local_4c) {
                operator_delete(local_60[0]);
              }
              local_4c = 0xf;
              local_50 = 0;
              local_60[0] = (void *)((uint)local_60[0] & 0xffffff00);
              local_8._0_1_ = 2;
              param_1 = local_38;
              if (0xf < local_1c) {
                operator_delete(local_30[0]);
                param_1 = local_38;
              }
            }
            break;
          }
          if (*(char *)((int)puVar5 + 0x2d) == '\0') {
            puVar6 = (undefined4 *)puVar5[2];
            if (*(char *)((int)puVar6 + 0x2d) == '\0') {
              cVar1 = *(char *)((int)*puVar6 + 0x2d);
              puVar5 = puVar6;
              puVar6 = (undefined4 *)*puVar6;
              while (cVar1 == '\0') {
                cVar1 = *(char *)((int)*puVar6 + 0x2d);
                puVar5 = puVar6;
                puVar6 = (undefined4 *)*puVar6;
              }
            }
            else {
              cVar1 = *(char *)((int)puVar5[1] + 0x2d);
              puVar3 = (undefined4 *)puVar5[1];
              puVar6 = puVar5;
              while ((puVar5 = puVar3, cVar1 == '\0' && (puVar6 == (undefined4 *)puVar5[2]))) {
                cVar1 = *(char *)((int)puVar5[1] + 0x2d);
                puVar3 = (undefined4 *)puVar5[1];
                puVar6 = puVar5;
              }
            }
          }
          iVar9 = iVar9 + 1;
        }
      }
      local_34 = local_34 + 1;
      uVar2 = (undefined1)local_8;
    } while (local_34 < local_44);
  }
  local_8._0_1_ = uVar2;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10010760 at 10010760

void __fastcall FUN_10010760(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ad3e;
  local_10 = ExceptionList;
  uVar5 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = SharedConfigurationLibrary_Internal::ConfigSetting::vftable;
  iVar2 = param_1[0xb];
  iVar7 = 0;
  local_8 = 2;
  if (0 < iVar2) {
    do {
      if ((-1 < iVar7) && (iVar7 < (int)param_1[0xb])) {
        puVar6 = *(undefined4 **)param_1[10];
        local_14 = 0;
        while (puVar6 != (undefined4 *)param_1[10]) {
          if (local_14 == iVar7) {
            if ((undefined4 *)puVar6[10] != (undefined4 *)0x0) {
              (*(code *)**(undefined4 **)puVar6[10])(1,uVar5);
            }
            break;
          }
          if (*(char *)((int)puVar6 + 0x2d) == '\0') {
            puVar3 = (undefined4 *)puVar6[2];
            if (*(char *)((int)puVar3 + 0x2d) == '\0') {
              cVar1 = *(char *)((int)*puVar3 + 0x2d);
              puVar6 = puVar3;
              puVar3 = (undefined4 *)*puVar3;
              while (cVar1 == '\0') {
                cVar1 = *(char *)((int)*puVar3 + 0x2d);
                puVar6 = puVar3;
                puVar3 = (undefined4 *)*puVar3;
              }
            }
            else {
              cVar1 = *(char *)((int)puVar6[1] + 0x2d);
              puVar4 = (undefined4 *)puVar6[1];
              puVar3 = puVar6;
              while ((puVar6 = puVar4, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar6[2]))) {
                cVar1 = *(char *)((int)puVar6[1] + 0x2d);
                puVar4 = (undefined4 *)puVar6[1];
                puVar3 = puVar6;
              }
            }
          }
          local_14 = local_14 + 1;
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar2);
  }
  FUN_1000cad0(*(int **)(param_1[10] + 4));
  *(undefined4 *)(param_1[10] + 4) = param_1[10];
  *(undefined4 *)param_1[10] = param_1[10];
  *(undefined4 *)(param_1[10] + 8) = param_1[10];
  param_1[0xb] = 0;
  local_8._0_1_ = 3;
  FUN_1000cad0(*(int **)(param_1[10] + 4));
  *(undefined4 *)(param_1[10] + 4) = param_1[10];
  *(undefined4 *)param_1[10] = param_1[10];
  *(undefined4 *)(param_1[10] + 8) = param_1[10];
  param_1[0xb] = 0;
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_1000cf70(param_1 + 9,&local_14,*(int **)param_1[10],(int *)param_1[10]);
  operator_delete((void *)param_1[10]);
  if (0xf < (uint)param_1[6]) {
    operator_delete((void *)param_1[1]);
  }
  param_1[6] = 0xf;
  param_1[5] = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = SharedConfigurationLibrary::SCLSchema::vftable;
  ExceptionList = local_10;
  return;
}



// Function: FUN_100108d0 at 100108d0

undefined4 * __thiscall FUN_100108d0(void *this,byte param_1)

{
  FUN_10010760((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10010900 at 10010900

void __fastcall FUN_10010900(undefined4 *param_1)

{
  *param_1 = SharedConfigurationLibrary_Internal::DataStore::vftable;
  return;
}



// Function: FUN_10010910 at 10010910

undefined4 * __thiscall FUN_10010910(void *this,byte param_1)

{
  *(undefined ***)this = SharedConfigurationLibrary_Internal::DataStore::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10010940 at 10010940

undefined4 __fastcall FUN_10010940(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}



// Function: FUN_10010960 at 10010960

undefined4 * __fastcall FUN_10010960(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ad68;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  *param_1 = SharedConfigurationLibrary_Internal::XMLDataStore::vftable;
  FUN_100132f0(param_1 + 1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100109b0 at 100109b0

uint __cdecl FUN_100109b0(byte *param_1,int param_2,byte *param_3,int param_4,char param_5)

{
  uint in_EAX;
  byte *pbVar1;
  int iVar2;
  
  if (param_2 != param_4) {
    return in_EAX & 0xffffff00;
  }
  if (param_5 == '\0') {
    pbVar1 = param_1 + param_2;
    if (param_1 < pbVar1) {
      while ((&DAT_1001f1c0)[*param_1] == (&DAT_1001f1c0)[*param_3]) {
        param_1 = param_1 + 1;
        param_3 = param_3 + 1;
        if (pbVar1 <= param_1) {
          return CONCAT31((int3)((uint)param_1 >> 8),1);
        }
      }
LAB_10010a11:
      return (uint)param_1 & 0xffffff00;
    }
  }
  else {
    pbVar1 = param_1 + param_2;
    if (param_1 < pbVar1) {
      iVar2 = (int)param_3 - (int)param_1;
      do {
        if (*param_1 != param_1[iVar2]) goto LAB_10010a11;
        param_1 = param_1 + 1;
      } while (param_1 < pbVar1);
    }
  }
  return CONCAT31((int3)((uint)param_1 >> 8),1);
}



// Function: FUN_10010a20 at 10010a20

void __cdecl FUN_10010a20(int *param_1,uint param_2)

{
  int iVar1;
  byte bVar2;
  undefined **local_18 [3];
  char *local_c;
  int local_8;
  
  bVar2 = (byte)param_2;
  if (param_2 < 0x80) {
    *(byte *)*param_1 = bVar2;
    *param_1 = *param_1 + 1;
    return;
  }
  if (param_2 < 0x800) {
    *(byte *)(*param_1 + 1) = bVar2 & 0x3f | 0x80;
    *(byte *)*param_1 = (byte)(param_2 >> 6) | 0xc0;
    *param_1 = *param_1 + 2;
    return;
  }
  if (param_2 < 0x10000) {
    *(byte *)(*param_1 + 2) = bVar2 & 0x3f | 0x80;
    *(byte *)(*param_1 + 1) = (byte)(param_2 >> 6) & 0x3f | 0x80;
    *(byte *)*param_1 = (byte)(param_2 >> 0xc) | 0xe0;
    *param_1 = *param_1 + 3;
    return;
  }
  if (param_2 < 0x110000) {
    *(byte *)(*param_1 + 3) = bVar2 & 0x3f | 0x80;
    *(byte *)(*param_1 + 2) = (byte)(param_2 >> 6) & 0x3f | 0x80;
    *(byte *)(*param_1 + 1) = (byte)(param_2 >> 0xc) & 0x3f | 0x80;
    *(byte *)*param_1 = (byte)(param_2 >> 0x12) | 0xf0;
    *param_1 = *param_1 + 4;
    return;
  }
  iVar1 = *param_1;
  std::exception::exception((exception *)local_18);
  local_18[0] = rapidxml::parse_error::vftable;
  local_c = "invalid numeric character entity";
  local_8 = iVar1;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_18,(ThrowInfo *)&DAT_100243cc);
}



// Function: FUN_10010b20 at 10010b20

exception * __thiscall FUN_10010b20(void *this,exception *param_1)

{
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = rapidxml::parse_error::vftable;
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  return (exception *)this;
}



// Function: FUN_10010b50 at 10010b50

exception * __thiscall FUN_10010b50(void *this,byte param_1)

{
  std::exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (exception *)this;
}



// Function: FUN_10010b80 at 10010b80

undefined4 * __thiscall FUN_10010b80(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ad68;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = SharedConfigurationLibrary_Internal::XMLDataStore::vftable;
  local_8 = 0;
  FUN_10013310((undefined4 *)((int)this + 4));
  *(undefined ***)this = SharedConfigurationLibrary_Internal::DataStore::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10010bf0 at 10010bf0

void __thiscall FUN_10010bf0(void *this,uint param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  iVar1 = (-*(int *)((int)this + 4) & 3U) + *(int *)((int)this + 4);
  if (*(uint *)((int)this + 8) < iVar1 + param_1) {
    uVar2 = 0x10000;
    if (0x10000 < param_1) {
      uVar2 = param_1;
    }
    if (*(code **)((int)this + 0x1000c) == (code *)0x0) {
      iVar1 = FUN_100171c8(uVar2 + 10);
    }
    else {
      iVar1 = (**(code **)((int)this + 0x1000c))();
    }
                    /* WARNING: Load size is inaccurate */
    puVar3 = (undefined4 *)((-iVar1 & 3U) + iVar1);
    *puVar3 = *this;
    *(int *)this = iVar1;
    puVar3 = puVar3 + 1;
    *(uint *)((int)this + 8) = iVar1 + uVar2 + 10;
    *(undefined4 **)((int)this + 4) = puVar3;
    iVar1 = (-(int)puVar3 & 3U) + (int)puVar3;
  }
  *(uint *)((int)this + 4) = iVar1 + param_1;
  return;
}



// Function: FUN_10010c70 at 10010c70

int * __thiscall FUN_10010c70(void *this,byte *param_1,int param_2,char param_3)

{
  byte bVar1;
  int *piVar2;
  byte *pbVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (param_1 == (byte *)0x0) {
    return *(int **)((int)this + 0x20);
  }
  if (param_2 == 0) {
    bVar1 = *param_1;
    pbVar3 = param_1;
    while (bVar1 != 0) {
      pbVar3 = pbVar3 + 1;
      bVar1 = *pbVar3;
    }
    param_2 = (int)pbVar3 - (int)param_1;
  }
  piVar2 = *(int **)((int)this + 0x20);
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return (int *)0x0;
    }
    pbVar3 = (byte *)*piVar2;
    if (pbVar3 == (byte *)0x0) {
      iVar5 = 0;
      pbVar3 = &DAT_100272c9;
    }
    else {
      iVar5 = piVar2[2];
    }
    uVar4 = FUN_100109b0(pbVar3,iVar5,param_1,param_2,param_3);
    if ((char)uVar4 != '\0') break;
    piVar2 = (int *)piVar2[6];
  }
  return piVar2;
}



// Function: FUN_10010cf0 at 10010cf0

void __fastcall FUN_10010cf0(int *param_1)

{
  int *piVar1;
  int *piVar2;
  void *pvVar3;
  
  piVar1 = param_1 + 3;
  piVar2 = (int *)*param_1;
  while (piVar2 != piVar1) {
    pvVar3 = (void *)*param_1;
    piVar2 = *(int **)((-(int)pvVar3 & 3U) + (int)pvVar3);
    if ((code *)param_1[0x4004] == (code *)0x0) {
      operator_delete__(pvVar3);
    }
    else {
      (*(code *)param_1[0x4004])();
    }
    *param_1 = (int)piVar2;
  }
  *param_1 = (int)piVar1;
  param_1[1] = (-(int)piVar1 & 3U) + (int)piVar1;
  param_1[2] = (int)(param_1 + 0x4003);
  return;
}



// Function: FUN_10010d50 at 10010d50

undefined4 FUN_10010d50(int *param_1)

{
  char *pcVar1;
  undefined **local_18 [3];
  char *local_c;
  char *local_8;
  
  while( true ) {
    pcVar1 = (char *)*param_1;
    if (((*pcVar1 == '-') && (pcVar1[1] == '-')) && (pcVar1[2] == '>')) break;
    if (*pcVar1 == '\0') {
      std::exception::exception((exception *)local_18);
      local_18[0] = rapidxml::parse_error::vftable;
      local_c = "unexpected end of data";
      local_8 = pcVar1;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_18,(ThrowInfo *)&DAT_100243cc);
    }
    *param_1 = (int)(pcVar1 + 1);
  }
  *param_1 = *param_1 + 3;
  return 0;
}



// Function: FUN_10010dc0 at 10010dc0

void __thiscall FUN_10010dc0(void *this,int *param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined **local_18 [3];
  char *local_c;
  char *local_8;
  
  iVar1 = *param_1;
  while( true ) {
    pcVar2 = (char *)*param_1;
    if (((*pcVar2 == ']') && (pcVar2[1] == ']')) && (pcVar2[2] == '>')) break;
    if (*pcVar2 == '\0') {
      std::exception::exception((exception *)local_18);
      local_18[0] = rapidxml::parse_error::vftable;
      local_c = "unexpected end of data";
      local_8 = pcVar2;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_18,(ThrowInfo *)&DAT_100243cc);
    }
    *param_1 = (int)(pcVar2 + 1);
  }
  puVar3 = (undefined4 *)((-*(int *)((int)this + 0x34) & 3U) + *(int *)((int)this + 0x34));
  if (*(undefined4 **)((int)this + 0x38) < puVar3 + 0xc) {
    if (*(code **)((int)this + 0x1003c) == (code *)0x0) {
      iVar4 = FUN_100171c8(0x1000a);
    }
    else {
      iVar4 = (**(code **)((int)this + 0x1003c))();
    }
    puVar3 = (undefined4 *)((-iVar4 & 3U) + iVar4);
    *puVar3 = *(undefined4 *)((int)this + 0x30);
    *(int *)((int)this + 0x30) = iVar4;
    puVar3 = puVar3 + 1;
    *(int *)((int)this + 0x38) = iVar4 + 0x1000a;
    *(undefined4 **)((int)this + 0x34) = puVar3;
    puVar3 = (undefined4 *)((-(int)puVar3 & 3U) + (int)puVar3);
  }
  *(undefined4 **)((int)this + 0x34) = puVar3 + 0xc;
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[4] = 0;
    puVar3[5] = 3;
    puVar3[6] = 0;
    puVar3[8] = 0;
  }
  iVar4 = *param_1;
  puVar3[1] = iVar1;
  puVar3[3] = iVar4 - iVar1;
  *(undefined1 *)*param_1 = 0;
  *param_1 = *param_1 + 3;
  return;
}



// Function: FUN_10010ec0 at 10010ec0

undefined4 FUN_10010ec0(int *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined **local_2c [3];
  char *local_20;
  char *local_1c;
  undefined **local_18 [3];
  char *local_c;
  int local_8;
  
  cVar1 = *(char *)*param_1;
  while( true ) {
    if (cVar1 == '>') {
      *param_1 = *param_1 + 1;
      return 0;
    }
    pcVar2 = (char *)*param_1;
    cVar1 = *pcVar2;
    if (cVar1 == '\0') break;
    pcVar2 = pcVar2 + 1;
    *param_1 = (int)pcVar2;
    if (cVar1 == '[') {
      iVar3 = 1;
      do {
        cVar1 = *pcVar2;
        if (cVar1 == '\0') {
          iVar3 = *param_1;
          std::exception::exception((exception *)local_18);
          local_18[0] = rapidxml::parse_error::vftable;
          local_c = "unexpected end of data";
          local_8 = iVar3;
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_18,(ThrowInfo *)&DAT_100243cc);
        }
        if (cVar1 == '[') {
          iVar3 = iVar3 + 1;
        }
        else if (cVar1 == ']') {
          iVar3 = iVar3 + -1;
        }
        pcVar2 = pcVar2 + 1;
        *param_1 = (int)pcVar2;
      } while (0 < iVar3);
    }
    cVar1 = *(char *)*param_1;
  }
  std::exception::exception((exception *)local_2c);
  local_2c[0] = rapidxml::parse_error::vftable;
  local_20 = "unexpected end of data";
  local_1c = pcVar2;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_2c,(ThrowInfo *)&DAT_100243cc);
}



// Function: FUN_10010f70 at 10010f70

void __cdecl FUN_10010f70(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  byte *pbVar5;
  undefined **local_18 [3];
  char *local_c;
  byte *local_8;
  
  pbVar2 = param_1;
  pbVar3 = *(byte **)param_1;
  while ((&DAT_1001f7e8)[*pbVar3] != '\0') {
    pbVar3 = pbVar3 + 1;
  }
  *(byte **)param_1 = pbVar3;
  param_1 = pbVar3;
LAB_10010fa0:
  bVar1 = *pbVar3;
  if ((&DAT_1001f5c0)[bVar1] == '\0') {
    *(byte **)pbVar2 = pbVar3;
    return;
  }
  if (bVar1 != 0x26) goto switchD_10010fd2_caseD_24;
  switch(pbVar3[1]) {
  case 0x23:
    uVar4 = 0;
    if (pbVar3[2] == 0x78) {
      pbVar5 = pbVar3 + 3;
      bVar1 = (&DAT_1001fc10)[pbVar3[3]];
      while (bVar1 != 0xff) {
        pbVar3 = pbVar5 + 1;
        pbVar5 = pbVar5 + 1;
        uVar4 = uVar4 * 0x10 + (uint)bVar1;
        bVar1 = (&DAT_1001fc10)[*pbVar3];
      }
    }
    else {
      pbVar5 = pbVar3 + 2;
      bVar1 = (&DAT_1001fc10)[pbVar3[2]];
      while (bVar1 != 0xff) {
        pbVar3 = pbVar5 + 1;
        pbVar5 = pbVar5 + 1;
        uVar4 = (uint)bVar1 + uVar4 * 10;
        bVar1 = (&DAT_1001fc10)[*pbVar3];
      }
    }
    FUN_10010a20((int *)&param_1,uVar4);
    if (*pbVar5 != 0x3b) {
      std::exception::exception((exception *)local_18);
      local_18[0] = rapidxml::parse_error::vftable;
      local_c = "expected ;";
      local_8 = pbVar5;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_18,(ThrowInfo *)&DAT_100243cc);
    }
    pbVar3 = pbVar5 + 1;
    goto LAB_10010fa0;
  case 0x61:
    if (((pbVar3[2] == 0x6d) && (pbVar3[3] == 0x70)) && (pbVar3[4] == 0x3b)) {
      *param_1 = 0x26;
      param_1 = param_1 + 1;
      pbVar3 = pbVar3 + 5;
      goto LAB_10010fa0;
    }
    if (((pbVar3[2] == 0x70) && (pbVar3[3] == 0x6f)) && ((pbVar3[4] == 0x73 && (pbVar3[5] == 0x3b)))
       ) {
      *param_1 = 0x27;
      param_1 = param_1 + 1;
      pbVar3 = pbVar3 + 6;
      goto LAB_10010fa0;
    }
    break;
  case 0x67:
    if ((pbVar3[2] == 0x74) && (pbVar3[3] == 0x3b)) {
      *param_1 = 0x3e;
      param_1 = param_1 + 1;
      pbVar3 = pbVar3 + 4;
      goto LAB_10010fa0;
    }
    break;
  case 0x6c:
    if ((pbVar3[2] == 0x74) && (pbVar3[3] == 0x3b)) {
      *param_1 = 0x3c;
      param_1 = param_1 + 1;
      pbVar3 = pbVar3 + 4;
      goto LAB_10010fa0;
    }
    break;
  case 0x71:
    if ((((pbVar3[2] != 0x75) || (pbVar3[3] != 0x6f)) || (pbVar3[4] != 0x74)) || (pbVar3[5] != 0x3b)
       ) break;
    *param_1 = 0x22;
    param_1 = param_1 + 1;
    pbVar3 = pbVar3 + 6;
    goto LAB_10010fa0;
  }
switchD_10010fd2_caseD_24:
  *param_1 = bVar1;
  param_1 = param_1 + 1;
  pbVar3 = pbVar3 + 1;
  goto LAB_10010fa0;
}



// Function: FUN_100111c0 at 100111c0

void __cdecl FUN_100111c0(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  byte *pbVar5;
  undefined **local_18 [3];
  char *local_c;
  byte *local_8;
  
  pbVar2 = param_1;
  pbVar3 = *(byte **)param_1;
  while ((&DAT_1001f8e8)[*pbVar3] != '\0') {
    pbVar3 = pbVar3 + 1;
  }
  *(byte **)param_1 = pbVar3;
  param_1 = pbVar3;
LAB_100111f0:
  bVar1 = *pbVar3;
  if ((&DAT_1001f6c0)[bVar1] == '\0') {
    *(byte **)pbVar2 = pbVar3;
    return;
  }
  if (bVar1 != 0x26) goto switchD_10011222_caseD_24;
  switch(pbVar3[1]) {
  case 0x23:
    uVar4 = 0;
    if (pbVar3[2] == 0x78) {
      pbVar5 = pbVar3 + 3;
      bVar1 = (&DAT_1001fc10)[pbVar3[3]];
      while (bVar1 != 0xff) {
        pbVar3 = pbVar5 + 1;
        pbVar5 = pbVar5 + 1;
        uVar4 = uVar4 * 0x10 + (uint)bVar1;
        bVar1 = (&DAT_1001fc10)[*pbVar3];
      }
    }
    else {
      pbVar5 = pbVar3 + 2;
      bVar1 = (&DAT_1001fc10)[pbVar3[2]];
      while (bVar1 != 0xff) {
        pbVar3 = pbVar5 + 1;
        pbVar5 = pbVar5 + 1;
        uVar4 = (uint)bVar1 + uVar4 * 10;
        bVar1 = (&DAT_1001fc10)[*pbVar3];
      }
    }
    FUN_10010a20((int *)&param_1,uVar4);
    if (*pbVar5 != 0x3b) {
      std::exception::exception((exception *)local_18);
      local_18[0] = rapidxml::parse_error::vftable;
      local_c = "expected ;";
      local_8 = pbVar5;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_18,(ThrowInfo *)&DAT_100243cc);
    }
    pbVar3 = pbVar5 + 1;
    goto LAB_100111f0;
  case 0x61:
    if (((pbVar3[2] == 0x6d) && (pbVar3[3] == 0x70)) && (pbVar3[4] == 0x3b)) {
      *param_1 = 0x26;
      param_1 = param_1 + 1;
      pbVar3 = pbVar3 + 5;
      goto LAB_100111f0;
    }
    if (((pbVar3[2] == 0x70) && (pbVar3[3] == 0x6f)) && ((pbVar3[4] == 0x73 && (pbVar3[5] == 0x3b)))
       ) {
      *param_1 = 0x27;
      param_1 = param_1 + 1;
      pbVar3 = pbVar3 + 6;
      goto LAB_100111f0;
    }
    break;
  case 0x67:
    if ((pbVar3[2] == 0x74) && (pbVar3[3] == 0x3b)) {
      *param_1 = 0x3e;
      param_1 = param_1 + 1;
      pbVar3 = pbVar3 + 4;
      goto LAB_100111f0;
    }
    break;
  case 0x6c:
    if ((pbVar3[2] == 0x74) && (pbVar3[3] == 0x3b)) {
      *param_1 = 0x3c;
      param_1 = param_1 + 1;
      pbVar3 = pbVar3 + 4;
      goto LAB_100111f0;
    }
    break;
  case 0x71:
    if ((((pbVar3[2] != 0x75) || (pbVar3[3] != 0x6f)) || (pbVar3[4] != 0x74)) || (pbVar3[5] != 0x3b)
       ) break;
    *param_1 = 0x22;
    param_1 = param_1 + 1;
    pbVar3 = pbVar3 + 6;
    goto LAB_100111f0;
  }
switchD_10011222_caseD_24:
  *param_1 = bVar1;
  param_1 = param_1 + 1;
  pbVar3 = pbVar3 + 1;
  goto LAB_100111f0;
}



// Function: FUN_10011410 at 10011410

void __cdecl FUN_10011410(byte *param_1)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  undefined **local_18 [3];
  char *local_c;
  byte *local_8;
  
  pbVar3 = param_1;
  pbVar4 = *(byte **)param_1;
  cVar1 = (&DAT_1001fae8)[*pbVar4];
  while (cVar1 != '\0') {
    pbVar6 = pbVar4 + 1;
    pbVar4 = pbVar4 + 1;
    cVar1 = (&DAT_1001fae8)[*pbVar6];
  }
  *(byte **)param_1 = pbVar4;
  cVar1 = (&DAT_1001f9e8)[*pbVar4];
  param_1 = pbVar4;
  do {
    if (cVar1 == '\0') {
      *(byte **)pbVar3 = pbVar4;
      return;
    }
    if (*pbVar4 != 0x26) {
switchD_10011482_caseD_24:
      *param_1 = *pbVar4;
      pbVar4 = pbVar4 + 1;
      goto LAB_100115c3;
    }
    switch(pbVar4[1]) {
    case 0x23:
      uVar5 = 0;
      if (pbVar4[2] == 0x78) {
        pbVar6 = pbVar4 + 3;
        bVar2 = (&DAT_1001fc10)[pbVar4[3]];
        while (bVar2 != 0xff) {
          pbVar4 = pbVar6 + 1;
          pbVar6 = pbVar6 + 1;
          uVar5 = uVar5 * 0x10 + (uint)bVar2;
          bVar2 = (&DAT_1001fc10)[*pbVar4];
        }
      }
      else {
        pbVar6 = pbVar4 + 2;
        bVar2 = (&DAT_1001fc10)[pbVar4[2]];
        while (bVar2 != 0xff) {
          pbVar4 = pbVar6 + 1;
          pbVar6 = pbVar6 + 1;
          uVar5 = (uint)bVar2 + uVar5 * 10;
          bVar2 = (&DAT_1001fc10)[*pbVar4];
        }
      }
      FUN_10010a20((int *)&param_1,uVar5);
      if (*pbVar6 != 0x3b) {
        std::exception::exception((exception *)local_18);
        local_18[0] = rapidxml::parse_error::vftable;
        local_c = "expected ;";
        local_8 = pbVar6;
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_18,(ThrowInfo *)&DAT_100243cc);
      }
      pbVar4 = pbVar6 + 1;
      goto LAB_100115c6;
    default:
      goto switchD_10011482_caseD_24;
    case 0x61:
      if (((pbVar4[2] == 0x6d) && (pbVar4[3] == 0x70)) && (pbVar4[4] == 0x3b)) {
        *param_1 = 0x26;
        pbVar4 = pbVar4 + 5;
      }
      else {
        if (((pbVar4[2] != 0x70) || (pbVar4[3] != 0x6f)) ||
           ((pbVar4[4] != 0x73 || (pbVar4[5] != 0x3b)))) goto switchD_10011482_caseD_24;
        *param_1 = 0x27;
        pbVar4 = pbVar4 + 6;
      }
      break;
    case 0x67:
      if ((pbVar4[2] != 0x74) || (pbVar4[3] != 0x3b)) goto switchD_10011482_caseD_24;
      *param_1 = 0x3e;
      pbVar4 = pbVar4 + 4;
      break;
    case 0x6c:
      if ((pbVar4[2] != 0x74) || (pbVar4[3] != 0x3b)) goto switchD_10011482_caseD_24;
      *param_1 = 0x3c;
      pbVar4 = pbVar4 + 4;
      break;
    case 0x71:
      if ((((pbVar4[2] != 0x75) || (pbVar4[3] != 0x6f)) || (pbVar4[4] != 0x74)) ||
         (pbVar4[5] != 0x3b)) goto switchD_10011482_caseD_24;
      *param_1 = 0x22;
      pbVar4 = pbVar4 + 6;
    }
LAB_100115c3:
    param_1 = param_1 + 1;
LAB_100115c6:
    cVar1 = (&DAT_1001f9e8)[*pbVar4];
  } while( true );
}



// Function: FUN_10011670 at 10011670

int * __thiscall FUN_10011670(void *this,byte *param_1,int param_2,char param_3)

{
  byte bVar1;
  int *piVar2;
  byte *pbVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (param_1 == (byte *)0x0) {
    return *(int **)((int)this + 0x18);
  }
  if (param_2 == 0) {
    bVar1 = *param_1;
    pbVar3 = param_1;
    while (bVar1 != 0) {
      pbVar3 = pbVar3 + 1;
      bVar1 = *pbVar3;
    }
    param_2 = (int)pbVar3 - (int)param_1;
  }
  piVar2 = *(int **)((int)this + 0x18);
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return (int *)0x0;
    }
    pbVar3 = (byte *)*piVar2;
    if (pbVar3 == (byte *)0x0) {
      iVar5 = 0;
      pbVar3 = &DAT_100272c9;
    }
    else {
      iVar5 = piVar2[2];
    }
    uVar4 = FUN_100109b0(pbVar3,iVar5,param_1,param_2,param_3);
    if ((char)uVar4 != '\0') break;
    piVar2 = (int *)piVar2[0xb];
  }
  return piVar2;
}



// Function: FUN_100116f0 at 100116f0

void __thiscall FUN_100116f0(void *this,byte *param_1,int param_2)

{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined **local_1c [3];
  char *local_10;
  byte *local_c;
  void *local_8;
  
  cVar2 = (&DAT_1001f4c0)[**(byte **)param_1];
  while( true ) {
    if (cVar2 == '\0') {
      return;
    }
    pbVar4 = *(byte **)param_1;
    pbVar5 = pbVar4 + 1;
    *(byte **)param_1 = pbVar5;
    cVar2 = (&DAT_1001f4c0)[*pbVar5];
    while (cVar2 != '\0') {
      pbVar1 = pbVar5 + 1;
      pbVar5 = pbVar5 + 1;
      cVar2 = (&DAT_1001f4c0)[*pbVar1];
    }
    *(byte **)param_1 = pbVar5;
    local_8 = this;
    if (pbVar5 == pbVar4) {
      std::exception::exception((exception *)local_1c);
      local_1c[0] = rapidxml::parse_error::vftable;
      local_10 = "expected attribute name";
      local_c = pbVar4;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_1c,(ThrowInfo *)&DAT_100243cc);
    }
    puVar6 = (undefined4 *)((-*(int *)((int)this + 0x34) & 3U) + *(int *)((int)this + 0x34));
    if (*(undefined4 **)((int)this + 0x38) < puVar6 + 7) {
      if (*(code **)((int)this + 0x1003c) == (code *)0x0) {
        iVar7 = FUN_100171c8(0x1000a);
      }
      else {
        iVar7 = (**(code **)((int)this + 0x1003c))();
      }
      puVar6 = (undefined4 *)((-iVar7 & 3U) + iVar7);
      *puVar6 = *(undefined4 *)((int)this + 0x30);
      *(int *)((int)this + 0x30) = iVar7;
      puVar6 = puVar6 + 1;
      *(int *)((int)this + 0x38) = iVar7 + 0x1000a;
      *(undefined4 **)((int)this + 0x34) = puVar6;
      puVar6 = (undefined4 *)((-(int)puVar6 & 3U) + (int)puVar6);
    }
    *(undefined4 **)((int)this + 0x34) = puVar6 + 7;
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      *puVar6 = 0;
      puVar6[1] = 0;
      puVar6[4] = 0;
    }
    puVar6[2] = *(int *)param_1 - (int)pbVar4;
    *puVar6 = pbVar4;
    if (*(int *)(param_2 + 0x20) == 0) {
      puVar6[5] = 0;
      *(undefined4 **)(param_2 + 0x20) = puVar6;
    }
    else {
      puVar6[5] = *(undefined4 *)(param_2 + 0x24);
      *(undefined4 **)(*(int *)(param_2 + 0x24) + 0x18) = puVar6;
    }
    *(undefined4 **)(param_2 + 0x24) = puVar6;
    puVar6[4] = param_2;
    puVar6[6] = 0;
    pbVar5 = *(byte **)param_1;
    cVar2 = (&DAT_1001f2c0)[*pbVar5];
    while (cVar2 != '\0') {
      pbVar4 = pbVar5 + 1;
      pbVar5 = pbVar5 + 1;
      cVar2 = (&DAT_1001f2c0)[*pbVar4];
    }
    *(byte **)param_1 = pbVar5;
    if (*pbVar5 != 0x3d) {
      std::exception::exception((exception *)local_1c);
      local_1c[0] = rapidxml::parse_error::vftable;
      local_10 = "expected =";
      local_c = pbVar5;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_1c,(ThrowInfo *)&DAT_100243cc);
    }
    *(byte **)param_1 = pbVar5 + 1;
    puVar8 = (undefined1 *)*puVar6;
    if (puVar8 == (undefined1 *)0x0) {
      puVar8 = &DAT_100272c9;
      iVar7 = 0;
    }
    else {
      iVar7 = puVar6[2];
    }
    puVar8[iVar7] = 0;
    pbVar5 = *(byte **)param_1;
    cVar2 = (&DAT_1001f2c0)[*pbVar5];
    while (cVar2 != '\0') {
      pbVar4 = pbVar5 + 1;
      pbVar5 = pbVar5 + 1;
      cVar2 = (&DAT_1001f2c0)[*pbVar4];
    }
    *(byte **)param_1 = pbVar5;
    bVar3 = *pbVar5;
    if ((bVar3 != 0x27) && (bVar3 != 0x22)) {
      std::exception::exception((exception *)local_1c);
      local_1c[0] = rapidxml::parse_error::vftable;
      local_10 = "expected \' or \"";
      local_c = pbVar5;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_1c,(ThrowInfo *)&DAT_100243cc);
    }
    pbVar5 = pbVar5 + 1;
    *(byte **)param_1 = pbVar5;
    if (bVar3 == 0x27) {
      iVar7 = FUN_10010f70(param_1);
    }
    else {
      iVar7 = FUN_100111c0(param_1);
    }
    puVar6[1] = pbVar5;
    puVar6[3] = iVar7 - (int)pbVar5;
    pbVar5 = *(byte **)param_1;
    if (*pbVar5 != bVar3) break;
    *(byte **)param_1 = pbVar5 + 1;
    puVar8 = (undefined1 *)puVar6[1];
    if (puVar8 == (undefined1 *)0x0) {
      puVar8 = &DAT_100272c9;
      iVar7 = 0;
    }
    else {
      iVar7 = puVar6[3];
    }
    puVar8[iVar7] = 0;
    pbVar5 = *(byte **)param_1;
    cVar2 = (&DAT_1001f2c0)[*pbVar5];
    while (cVar2 != '\0') {
      pbVar4 = pbVar5 + 1;
      pbVar5 = pbVar5 + 1;
      cVar2 = (&DAT_1001f2c0)[*pbVar4];
    }
    *(byte **)param_1 = pbVar5;
    cVar2 = (&DAT_1001f4c0)[*pbVar5];
    this = local_8;
  }
  std::exception::exception((exception *)local_1c);
  local_1c[0] = rapidxml::parse_error::vftable;
  local_10 = "expected \' or \"";
  local_c = pbVar5;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_100243cc);
}



// Function: FUN_10011990 at 10011990

undefined4 __thiscall FUN_10011990(void *this,int param_1,byte *param_2,int param_3)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  char *pcVar6;
  
  *(int *)param_2 = param_3;
  puVar3 = (undefined1 *)FUN_10011410(param_2);
  puVar4 = (undefined4 *)((-*(int *)((int)this + 0x34) & 3U) + *(int *)((int)this + 0x34));
  if (*(undefined4 **)((int)this + 0x38) < puVar4 + 0xc) {
    if (*(code **)((int)this + 0x1003c) == (code *)0x0) {
      iVar5 = FUN_100171c8(0x1000a);
    }
    else {
      iVar5 = (**(code **)((int)this + 0x1003c))();
    }
    puVar4 = (undefined4 *)((-iVar5 & 3U) + iVar5);
    *puVar4 = *(undefined4 *)((int)this + 0x30);
    *(int *)((int)this + 0x30) = iVar5;
    puVar4 = puVar4 + 1;
    *(int *)((int)this + 0x38) = iVar5 + 0x1000a;
    *(undefined4 **)((int)this + 0x34) = puVar4;
    puVar4 = (undefined4 *)((-(int)puVar4 & 3U) + (int)puVar4);
  }
  *(undefined4 **)((int)this + 0x34) = puVar4 + 0xc;
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[4] = 0;
    puVar4[5] = 2;
    puVar4[6] = 0;
    puVar4[8] = 0;
  }
  puVar4[1] = param_3;
  puVar4[3] = (int)puVar3 - param_3;
  if (*(int *)(param_1 + 0x18) == 0) {
    puVar4[10] = 0;
    *(undefined4 **)(param_1 + 0x18) = puVar4;
  }
  else {
    puVar4[10] = *(undefined4 *)(param_1 + 0x1c);
    *(undefined4 **)(*(int *)(param_1 + 0x1c) + 0x2c) = puVar4;
  }
  *(undefined4 **)(param_1 + 0x1c) = puVar4;
  puVar4[4] = param_1;
  puVar4[0xb] = 0;
  pcVar6 = *(char **)(param_1 + 4);
  if (pcVar6 == (char *)0x0) {
    pcVar6 = &DAT_100272c9;
  }
  if (*pcVar6 == '\0') {
    *(int *)(param_1 + 4) = param_3;
    *(int *)(param_1 + 0xc) = (int)puVar3 - param_3;
  }
  puVar2 = *(undefined1 **)param_2;
  uVar1 = *puVar2;
  *puVar3 = 0;
  return CONCAT31((int3)((uint)puVar2 >> 8),uVar1);
}



// Function: FUN_10011a90 at 10011a90

void __fastcall FUN_10011a90(int param_1)

{
  FUN_10010cf0((int *)(param_1 + 0x30));
  return;
}



// Function: FUN_10011aa0 at 10011aa0

void __fastcall FUN_10011aa0(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[8] = 0;
  param_1[0x400f] = 0;
  param_1[0x4010] = 0;
  puVar1 = param_1 + 0xf;
  param_1[0xd] = (-(int)puVar1 & 3U) + (int)puVar1;
  param_1[0xc] = puVar1;
  param_1[0xe] = param_1 + 0x400f;
  return;
}



// Function: FUN_10011ae0 at 10011ae0

int * __thiscall FUN_10011ae0(void *this,byte *param_1)

{
  byte *pbVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  byte *pbVar6;
  byte *pbVar7;
  char *pcVar8;
  undefined **local_1c [3];
  char *local_10;
  byte *local_c;
  int *local_8;
  
  local_8 = (int *)((-*(int *)((int)this + 0x34) & 3U) + *(int *)((int)this + 0x34));
  if (*(int **)((int)this + 0x38) < local_8 + 0xc) {
    if (*(code **)((int)this + 0x1003c) == (code *)0x0) {
      iVar4 = FUN_100171c8(0x1000a);
    }
    else {
      iVar4 = (**(code **)((int)this + 0x1003c))();
    }
    puVar5 = (undefined4 *)((-iVar4 & 3U) + iVar4);
    *puVar5 = *(undefined4 *)((int)this + 0x30);
    *(int *)((int)this + 0x30) = iVar4;
    puVar5 = puVar5 + 1;
    *(int *)((int)this + 0x38) = iVar4 + 0x1000a;
    *(undefined4 **)((int)this + 0x34) = puVar5;
    local_8 = (int *)((-(int)puVar5 & 3U) + (int)puVar5);
  }
  *(int **)((int)this + 0x34) = local_8 + 0xc;
  if (local_8 == (int *)0x0) {
    local_8 = (int *)0x0;
  }
  else {
    *local_8 = 0;
    local_8[1] = 0;
    local_8[4] = 0;
    local_8[5] = 1;
    local_8[6] = 0;
    local_8[8] = 0;
  }
  pbVar6 = *(byte **)param_1;
  cVar2 = (&DAT_1001f3c0)[*pbVar6];
  pbVar7 = pbVar6;
  while (cVar2 != '\0') {
    pbVar1 = pbVar7 + 1;
    pbVar7 = pbVar7 + 1;
    cVar2 = (&DAT_1001f3c0)[*pbVar1];
  }
  *(byte **)param_1 = pbVar7;
  if (pbVar7 == pbVar6) {
    std::exception::exception((exception *)local_1c);
    local_1c[0] = rapidxml::parse_error::vftable;
    local_10 = "expected element name";
    local_c = pbVar7;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_1c,(ThrowInfo *)&DAT_100243cc);
  }
  *local_8 = (int)pbVar6;
  local_8[2] = (int)pbVar7 - (int)pbVar6;
  pbVar6 = *(byte **)param_1;
  cVar2 = (&DAT_1001f2c0)[*pbVar6];
  while (cVar2 != '\0') {
    pbVar7 = pbVar6 + 1;
    pbVar6 = pbVar6 + 1;
    cVar2 = (&DAT_1001f2c0)[*pbVar7];
  }
  *(byte **)param_1 = pbVar6;
  FUN_100116f0(this,param_1,(int)local_8);
  piVar3 = local_8;
  local_c = *(byte **)param_1;
  if (*local_c == '>') {
    *(char **)param_1 = (char *)local_c + 1;
    FUN_10011ef0(this,param_1,(int)local_8);
  }
  else {
    if (*local_c != '/') {
      std::exception::exception((exception *)local_1c);
      local_1c[0] = rapidxml::parse_error::vftable;
      local_10 = "expected >";
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_1c,(ThrowInfo *)&DAT_100243cc);
    }
    pcVar8 = (char *)local_c + 1;
    *(char **)param_1 = pcVar8;
    if (*pcVar8 != '>') {
      std::exception::exception((exception *)local_1c);
      local_1c[0] = rapidxml::parse_error::vftable;
      local_10 = "expected >";
      local_c = (byte *)pcVar8;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_1c,(ThrowInfo *)&DAT_100243cc);
    }
    *(char **)param_1 = (char *)local_c + 2;
  }
  if (*piVar3 != 0) {
    *(undefined1 *)(piVar3[2] + *piVar3) = 0;
    return piVar3;
  }
  DAT_100272c9 = 0;
  return piVar3;
}



// Function: FUN_10011ca0 at 10011ca0

undefined4 FUN_10011ca0(int *param_1)

{
  char *pcVar1;
  undefined **local_18 [3];
  char *local_c;
  char *local_8;
  
  while( true ) {
    pcVar1 = (char *)*param_1;
    if ((*pcVar1 == '?') && (pcVar1[1] == '>')) break;
    if (*pcVar1 == '\0') {
      std::exception::exception((exception *)local_18);
      local_18[0] = rapidxml::parse_error::vftable;
      local_c = "unexpected end of data";
      local_8 = pcVar1;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_18,(ThrowInfo *)&DAT_100243cc);
    }
    *param_1 = (int)(pcVar1 + 1);
  }
  *param_1 = *param_1 + 2;
  return 0;
}



// Function: FUN_10011d00 at 10011d00

int * __thiscall FUN_10011d00(void *this,byte *param_1)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  int *piVar4;
  char *pcVar5;
  undefined **local_2c [3];
  char *local_20;
  undefined4 local_1c;
  undefined **local_18 [3];
  char *local_c;
  char *local_8;
  
  pcVar2 = *(char **)param_1;
  if (*pcVar2 == '!') {
    cVar1 = pcVar2[1];
    pcVar5 = pcVar2 + 1;
    if (cVar1 == '-') {
      if (pcVar2[2] == '-') {
        *(char **)param_1 = pcVar2 + 3;
        piVar4 = (int *)FUN_10010d50((int *)param_1);
        return piVar4;
      }
    }
    else if (cVar1 == 'D') {
      if (((((pcVar2[2] == 'O') && (pcVar2[3] == 'C')) && (pcVar2[4] == 'T')) &&
          ((pcVar2[5] == 'Y' && (pcVar2[6] == 'P')))) &&
         ((pcVar2[7] == 'E' && ((&DAT_1001f2c0)[(byte)pcVar2[8]] != '\0')))) {
        *(char **)param_1 = pcVar2 + 9;
        piVar4 = (int *)FUN_10010ec0((int *)param_1);
        return piVar4;
      }
    }
    else if ((((cVar1 == '[') && (pcVar2[2] == 'C')) &&
             ((pcVar2[3] == 'D' &&
              (((pcVar2[4] == 'A' && (pcVar2[5] == 'T')) && (pcVar2[6] == 'A')))))) &&
            (pcVar2[7] == '[')) {
      *(char **)param_1 = pcVar2 + 8;
      piVar4 = (int *)FUN_10010dc0(this,(int *)param_1);
      return piVar4;
    }
    *(char **)param_1 = pcVar5;
    cVar1 = *pcVar5;
    while( true ) {
      if (cVar1 == '>') {
        *(char **)param_1 = pcVar5 + 1;
        return (int *)0x0;
      }
      if (*pcVar5 == '\0') break;
      pcVar5 = pcVar5 + 1;
      *(char **)param_1 = pcVar5;
      cVar1 = *pcVar5;
    }
    uVar3 = *(undefined4 *)param_1;
    std::exception::exception((exception *)local_2c);
    local_2c[0] = rapidxml::parse_error::vftable;
    local_20 = "unexpected end of data";
    local_1c = uVar3;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_2c,(ThrowInfo *)&DAT_100243cc);
  }
  if (*pcVar2 != '?') {
    piVar4 = FUN_10011ae0(this,param_1);
    return piVar4;
  }
  *(char **)param_1 = pcVar2 + 1;
  cVar1 = pcVar2[1];
  if (((cVar1 == 'x') || (cVar1 == 'X')) &&
     (((pcVar2[2] == 'm' || (pcVar2[2] == 'M')) &&
      (((pcVar2[3] == 'l' || (pcVar2[3] == 'L')) && ((&DAT_1001f2c0)[(byte)pcVar2[4]] != '\0'))))))
  {
    *(char **)param_1 = pcVar2 + 5;
    piVar4 = (int *)FUN_10011ca0((int *)param_1);
    return piVar4;
  }
  while( true ) {
    pcVar2 = *(char **)param_1;
    if ((*pcVar2 == '?') && (pcVar2[1] == '>')) break;
    if (*pcVar2 == '\0') {
      std::exception::exception((exception *)local_18);
      local_18[0] = rapidxml::parse_error::vftable;
      local_c = "unexpected end of data";
      local_8 = pcVar2;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_18,(ThrowInfo *)&DAT_100243cc);
    }
    *(char **)param_1 = pcVar2 + 1;
  }
  *(int *)param_1 = *(int *)param_1 + 2;
  return (int *)0x0;
}



// Function: FUN_10011ef0 at 10011ef0

void __thiscall FUN_10011ef0(void *this,byte *param_1,int param_2)

{
  byte *pbVar1;
  char cVar2;
  undefined4 uVar3;
  byte *pbVar4;
  uint uVar5;
  int *piVar6;
  byte *pbVar7;
  undefined **local_30 [3];
  char *local_24;
  undefined4 local_20;
  undefined **local_1c [3];
  char *local_10;
  byte *local_c;
  void *local_8;
  
  local_8 = this;
  while( true ) {
    pbVar7 = *(byte **)param_1;
    cVar2 = (&DAT_1001f2c0)[*pbVar7];
    pbVar4 = pbVar7;
    while (cVar2 != '\0') {
      pbVar1 = pbVar4 + 1;
      pbVar4 = pbVar4 + 1;
      cVar2 = (&DAT_1001f2c0)[*pbVar1];
    }
    *(byte **)param_1 = pbVar4;
    uVar5 = (uint)*pbVar4;
    while( true ) {
      if ((char)uVar5 == '\0') {
        uVar3 = *(undefined4 *)param_1;
        std::exception::exception((exception *)local_30);
        local_30[0] = rapidxml::parse_error::vftable;
        local_24 = "unexpected end of data";
        local_20 = uVar3;
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_30,(ThrowInfo *)&DAT_100243cc);
      }
      if ((char)uVar5 == '<') break;
      uVar5 = FUN_10011990(local_8,param_2,param_1,(int)pbVar7);
    }
    if (*(char *)(*(int *)param_1 + 1) == '/') break;
    *(char **)param_1 = (char *)(*(int *)param_1 + 1);
    piVar6 = FUN_10011d00(local_8,param_1);
    if (piVar6 != (int *)0x0) {
      if (*(int *)(param_2 + 0x18) == 0) {
        piVar6[10] = 0;
        *(int **)(param_2 + 0x18) = piVar6;
        *(int **)(param_2 + 0x1c) = piVar6;
        piVar6[4] = param_2;
        piVar6[0xb] = 0;
      }
      else {
        piVar6[10] = *(int *)(param_2 + 0x1c);
        *(int **)(*(int *)(param_2 + 0x1c) + 0x2c) = piVar6;
        *(int **)(param_2 + 0x1c) = piVar6;
        piVar6[4] = param_2;
        piVar6[0xb] = 0;
      }
    }
  }
  *(int *)param_1 = *(int *)param_1 + 2;
  pbVar7 = *(byte **)param_1;
  cVar2 = (&DAT_1001f3c0)[*pbVar7];
  while (cVar2 != '\0') {
    pbVar4 = pbVar7 + 1;
    pbVar7 = pbVar7 + 1;
    cVar2 = (&DAT_1001f3c0)[*pbVar4];
  }
  *(byte **)param_1 = pbVar7;
  cVar2 = (&DAT_1001f2c0)[*pbVar7];
  while (cVar2 != '\0') {
    pbVar4 = pbVar7 + 1;
    pbVar7 = pbVar7 + 1;
    cVar2 = (&DAT_1001f2c0)[*pbVar4];
  }
  *(byte **)param_1 = pbVar7;
  if (*pbVar7 == 0x3e) {
    *(byte **)param_1 = pbVar7 + 1;
    return;
  }
  std::exception::exception((exception *)local_1c);
  local_1c[0] = rapidxml::parse_error::vftable;
  local_10 = "expected >";
  local_c = pbVar7;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_100243cc);
}



// Function: FUN_10012040 at 10012040

void __thiscall FUN_10012040(void *this,byte *param_1)

{
  byte *pbVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  byte *pbVar5;
  undefined **local_18 [3];
  char *local_c;
  byte *local_8;
  
  for (iVar3 = *(int *)((int)this + 0x18); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x2c)) {
    *(undefined4 *)(iVar3 + 0x10) = 0;
  }
  iVar3 = *(int *)((int)this + 0x20);
  *(undefined4 *)((int)this + 0x18) = 0;
  for (; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x18)) {
    *(undefined4 *)(iVar3 + 0x10) = 0;
  }
  *(undefined4 *)((int)this + 0x20) = 0;
  if (((*param_1 == 0xef) && (param_1[1] == 0xbb)) && (param_1[2] == 0xbf)) {
    param_1 = param_1 + 3;
  }
  while( true ) {
    cVar2 = (&DAT_1001f2c0)[*param_1];
    pbVar5 = param_1;
    while (cVar2 != '\0') {
      pbVar1 = pbVar5 + 1;
      pbVar5 = pbVar5 + 1;
      cVar2 = (&DAT_1001f2c0)[*pbVar1];
    }
    if (*pbVar5 == 0) break;
    if (*pbVar5 != 0x3c) {
      param_1 = pbVar5;
      std::exception::exception((exception *)local_18);
      local_18[0] = rapidxml::parse_error::vftable;
      local_c = "expected <";
      local_8 = pbVar5;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_18,(ThrowInfo *)&DAT_100243cc);
    }
    param_1 = pbVar5 + 1;
    piVar4 = FUN_10011d00(this,(byte *)&param_1);
    if (piVar4 != (int *)0x0) {
      if (*(int *)((int)this + 0x18) == 0) {
        piVar4[10] = 0;
        *(int **)((int)this + 0x18) = piVar4;
        *(int **)((int)this + 0x1c) = piVar4;
        piVar4[4] = (int)this;
        piVar4[0xb] = 0;
      }
      else {
        piVar4[10] = *(int *)((int)this + 0x1c);
        *(int **)(*(int *)((int)this + 0x1c) + 0x2c) = piVar4;
        *(int **)((int)this + 0x1c) = piVar4;
        piVar4[4] = (int)this;
        piVar4[0xb] = 0;
      }
    }
  }
  return;
}



// Function: FUN_10012130 at 10012130

void FUN_10012130(void *param_1,void *param_2,void *param_3)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  undefined1 *this;
  undefined3 extraout_var;
  int *piVar5;
  char *pcVar6;
  undefined3 extraout_var_00;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  byte *pbVar10;
  void *this_00;
  uint in_stack_00000020;
  void *pvVar11;
  void *in_stack_ffffff60;
  void *in_stack_ffffff7c;
  byte *local_4c;
  undefined4 local_38 [2];
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_1001adb8;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  uStack_7 = 0;
  iVar3 = FUN_1000b460((int)&param_3);
  if ((param_1 == (void *)0x0) || (param_2 == (void *)0x0)) {
    if (0xf < in_stack_00000020) {
      operator_delete(param_3);
    }
  }
  else {
    piVar4 = FUN_10010c70(param_1,&DAT_1001f144,0,'\x01');
    if (piVar4 != (int *)0x0) {
      pbVar10 = (byte *)piVar4[1];
      if (pbVar10 == (byte *)0x0) {
        pbVar10 = &DAT_100272c9;
      }
      this = FUN_1000bb40(param_2,(undefined1 *)local_30);
      bVar2 = FUN_1000b7e0(this,pbVar10);
      if (0xf < local_1c) {
        operator_delete(local_30[0]);
      }
      if (CONCAT31(extraout_var,bVar2) == 0) {
        FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )&param_3);
        goto LAB_10012440;
      }
    }
    this_00 = *(void **)((int)param_1 + 0x18);
    if (this_00 == (void *)0x0) {
      FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &param_3);
    }
    else {
      do {
        piVar4 = FUN_10010c70(this_00,&DAT_1001f144,0,'\x01');
        if (piVar4 != (int *)0x0) {
          local_4c = (byte *)piVar4[1];
          if (local_4c == (byte *)0x0) {
            local_4c = &DAT_100272c9;
          }
          piVar4 = FUN_10011670(this_00,(byte *)"value",0,'\x01');
          piVar5 = FUN_10011670(this_00,(byte *)"val_type",0,'\x01');
          if ((piVar4 != (int *)0x0) && (piVar5 != (int *)0x0)) {
            pcVar8 = (char *)piVar4[1];
            if (pcVar8 == (char *)0x0) {
              pcVar8 = &DAT_100272c9;
            }
            pcVar9 = (char *)piVar5[1];
            if (pcVar9 == (char *)0x0) {
              pcVar9 = &DAT_100272c9;
            }
            local_1c = 0xf;
            local_20 = 0;
            local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
            local_8 = 1;
            in_stack_ffffff7c = (void *)((uint)in_stack_ffffff7c & 0xffffff00);
            pcVar6 = pcVar9;
            do {
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
            assign((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &stack0xffffff7c,pcVar9,(int)pcVar6 - (int)(pcVar9 + 1));
            local_8 = 2;
            in_stack_ffffff60 = (void *)((uint)in_stack_ffffff60 & 0xffffff00);
            pcVar9 = pcVar8;
            do {
              cVar1 = *pcVar9;
              pcVar9 = pcVar9 + 1;
            } while (cVar1 != '\0');
            std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
            assign((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &stack0xffffff60,pcVar8,(int)pcVar9 - (int)(pcVar8 + 1));
            local_8 = 1;
            pvVar11 = (void *)0x100122fb;
            FUN_100142f0(in_stack_ffffff60);
            if (iVar3 == 0) {
              FUN_100077d3(&stack0xffffff78,local_38);
              local_8 = 4;
              FUN_10006c43(&stack0xffffff5c,(char *)local_4c);
              local_8 = 1;
              iVar7 = FUN_10010190(param_2,pvVar11);
              if (iVar7 == 0) {
                FUN_10006c43(&stack0xffffff7c,(char *)local_4c);
                FUN_1000e8f0(param_2,in_stack_ffffff7c);
              }
            }
            else {
              bVar2 = FUN_1000b7e0(&param_3,local_4c);
              if (CONCAT31(extraout_var_00,bVar2) != 0) {
                FUN_100077d3(&stack0xffffff78,local_38);
                local_8 = 3;
                FUN_10006c43(&stack0xffffff5c,(char *)local_4c);
                local_8 = 1;
                iVar3 = FUN_10010190(param_2,pvVar11);
                if (iVar3 == 0) {
                  FUN_10006c43(&stack0xffffff7c,(char *)local_4c);
                  FUN_1000e8f0(param_2,in_stack_ffffff7c);
                }
                FUN_100074ce((int)local_38);
                FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                              *)&param_3);
                goto LAB_10012440;
              }
              if (*(int *)((int)this_00 + 0x2c) == 0) {
                FUN_100074ce((int)local_38);
                FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                              *)&param_3);
                goto LAB_10012440;
              }
            }
            local_8 = 0;
            if (0xf < local_1c) {
              operator_delete(local_30[0]);
            }
          }
        }
        this_00 = *(void **)((int)this_00 + 0x2c);
      } while (this_00 != (void *)0x0);
      FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &param_3);
    }
  }
LAB_10012440:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10012460 at 10012460

void FUN_10012460(undefined1 *param_1,void *param_2,void *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  void *this;
  uint in_stack_00000020;
  undefined4 uVar3;
  float fVar4;
  void *in_stack_ffffff14;
  undefined4 *local_b0;
  undefined4 local_a8;
  float local_a4;
  void *local_a0 [4];
  undefined4 local_90;
  uint local_8c;
  void *local_84 [4];
  undefined4 local_74;
  uint local_70;
  void *local_68 [5];
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
  undefined4 local_8;
  
  puStack_c = &LAB_1001ae1b;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_30,"",0);
  local_8._0_1_ = 1;
  if (param_2 == (void *)0x0) {
    *(undefined4 *)(param_1 + 0x14) = 0xf;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *param_1 = 0;
    FUN_10001f4b(param_1,local_30,0,0xffffffff);
    if (0xf < local_1c) {
      operator_delete(local_30[0]);
    }
  }
  else {
    FUN_1000b720(local_30,(int *)"<?xml version=\"1.0\" encoding=\"utf-8\" ?><SCLSettings name=\"");
    puVar1 = (undefined4 *)FUN_1000bb40(param_2,(undefined1 *)local_68);
    local_8._0_1_ = 2;
    FUN_1000b700(local_30,puVar1);
    local_8._0_1_ = 1;
    if (0xf < local_54) {
      operator_delete(local_68[0]);
    }
    FUN_1000b720(local_30,(int *)&DAT_1001fde4);
    iVar2 = FUN_1000e060((int)param_2);
    local_b0 = (undefined4 *)0x0;
    if (0 < iVar2) {
      do {
        this = (void *)FUN_1000e190(param_2,local_b0);
        if (this != (void *)0x0) {
          FUN_1000e390(this,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                             *)local_68);
          local_8c = 0xf;
          local_90 = 0;
          local_a0[0] = (void *)((uint)local_a0[0] & 0xffffff00);
          local_8._0_1_ = 4;
          FUN_10013900(this,&local_a8);
          local_38 = 0xf;
          local_3c = 0;
          local_4c[0] = (void *)((uint)local_4c[0] & 0xffffff00);
          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                    ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )local_4c,"",0);
          local_8._0_1_ = 5;
          in_stack_ffffff14 = (void *)((uint)in_stack_ffffff14 & 0xffffff00);
          uVar3 = local_a8;
          fVar4 = local_a4;
          FUN_10001f4b(&stack0xffffff14,local_a0,0,0xffffffff);
          FUN_10013750(uVar3,fVar4,in_stack_ffffff14);
          FUN_10013670((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)local_84,local_a8);
          local_8 = CONCAT31(local_8._1_3_,6);
          FUN_1000b720(local_30,(int *)"<SCLEntry name=\"");
          FUN_1000b700(local_30,local_68);
          FUN_1000b720(local_30,(int *)&DAT_1001fde4);
          FUN_1000b720(local_30,(int *)"<value>");
          FUN_1000b700(local_30,local_4c);
          FUN_1000b720(local_30,(int *)"</value>");
          FUN_1000b720(local_30,(int *)"<val_type>");
          FUN_1000b700(local_30,local_84);
          FUN_1000b720(local_30,(int *)"</val_type>");
          FUN_1000b720(local_30,(int *)"</SCLEntry>");
          if (0xf < local_70) {
            operator_delete(local_84[0]);
          }
          local_70 = 0xf;
          local_74 = 0;
          local_84[0] = (void *)((uint)local_84[0] & 0xffffff00);
          if (0xf < local_38) {
            operator_delete(local_4c[0]);
          }
          local_38 = 0xf;
          local_3c = 0;
          local_4c[0] = (void *)((uint)local_4c[0] & 0xffffff00);
          if (0xf < local_8c) {
            operator_delete(local_a0[0]);
          }
          local_8c = 0xf;
          local_90 = 0;
          local_a0[0] = (void *)((uint)local_a0[0] & 0xffffff00);
          local_8._0_1_ = 1;
          if (0xf < local_54) {
            operator_delete(local_68[0]);
          }
        }
        local_b0 = (undefined4 *)((int)local_b0 + 1);
      } while ((int)local_b0 < iVar2);
    }
    FUN_1000b720(local_30,(int *)"</SCLSettings>");
    *(undefined4 *)(param_1 + 0x14) = 0xf;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *param_1 = 0;
    FUN_10001f4b(param_1,local_30,0,0xffffffff);
    if (0xf < local_1c) {
      operator_delete(local_30[0]);
    }
  }
  local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
  local_20 = 0;
  local_1c = 0xf;
  if (0xf < in_stack_00000020) {
    local_1c = 0xf;
    local_20 = 0;
    operator_delete(param_3);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100127e0 at 100127e0

void __thiscall FUN_100127e0(void *this,void *param_1,void *param_2)

{
  void **ppvVar1;
  int iVar2;
  uint in_stack_0000001c;
  uint in_stack_ffffff38;
  void *pvVar3;
  undefined4 *puVar4;
  uint in_stack_ffffff5c;
  undefined4 local_6c [13];
  undefined4 local_38 [2];
  void *local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001ae70;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  local_8 = 0;
  ppvVar1 = &local_10;
  if ((param_1 != (void *)0x0) &&
     (ExceptionList = &local_10, iVar2 = FUN_1000b460((int)&param_2),
     ppvVar1 = (void **)ExceptionList, iVar2 != 0)) {
    pvVar3 = (void *)(in_stack_ffffff5c & 0xffffff00);
    FUN_10001f4b(&stack0xffffff5c,&param_2,0,0xffffffff);
    iVar2 = FUN_1000e500(param_1,pvVar3);
    ppvVar1 = (void **)ExceptionList;
    if (iVar2 != 0) {
      FUN_10010520(local_6c,(int)param_1);
      local_8._0_1_ = 1;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &stack0xffffff5c,"",0);
                    /* WARNING: Load size is inaccurate */
      puVar4 = local_6c;
      (**(code **)(*this + 4))();
      local_1c = 0xf;
      local_20 = 0;
      local_30 = (void *)((uint)local_30 & 0xffffff00);
      local_8._0_1_ = 2;
      pvVar3 = (void *)((uint)puVar4 & 0xffffff00);
      FUN_10001f4b(&stack0xffffff58,&param_2,0,0xffffffff);
      iVar2 = FUN_1000e5a0(param_1,pvVar3);
      if (iVar2 == 0) {
        FUN_100077d3(&stack0xffffff54,local_38);
        local_8._0_1_ = 3;
        pvVar3 = (void *)(in_stack_ffffff38 & 0xffffff00);
        FUN_10001f4b(&stack0xffffff38,&param_2,0,0xffffffff);
        local_8._0_1_ = 2;
        iVar2 = FUN_10010190(local_6c,pvVar3);
        if (iVar2 == 0) {
          FUN_10006c43(&stack0xffffff5c,"");
                    /* WARNING: Load size is inaccurate */
          puVar4 = local_6c;
          iVar2 = (**(code **)(*this + 8))();
          if (iVar2 == 0) {
            FUN_10007753(&stack0xffffff58,
                         (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                          *)&param_2);
            FUN_1000e8f0(param_1,puVar4);
          }
        }
      }
      if (0xf < local_1c) {
        operator_delete(local_30);
      }
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10010760(local_6c);
      if (0xf < in_stack_0000001c) {
        operator_delete(param_2);
      }
      goto LAB_100129bd;
    }
  }
  ExceptionList = ppvVar1;
  if (0xf < in_stack_0000001c) {
    operator_delete(param_2);
  }
LAB_100129bd:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100129e0 at 100129e0

void FUN_100129e0(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  *param_1)

{
  char cVar1;
  BOOL BVar2;
  char *_Dst;
  char *pcVar3;
  size_t local_240 [2];
  void *local_238 [4];
  undefined4 local_228;
  uint local_224;
  WCHAR local_21c;
  undefined1 local_21a [518];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001aecd;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_240[1] = 0;
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  local_8 = 0;
  *param_1 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            (param_1,"",0);
  local_8 = 0;
  local_240[1] = 1;
  local_21c = L'\0';
  memset(local_21a,0,0x206);
  BVar2 = SHGetSpecialFolderPathW((HWND)0x0,&local_21c,0x23,0);
  if (BVar2 != 0) {
    _Dst = (char *)FUN_100171c8(0x104);
    wcstombs_s(local_240,_Dst,0x104,&local_21c,0x104);
    local_224 = 0xf;
    local_228 = 0;
    local_238[0] = (void *)((uint)local_238[0] & 0xffffff00);
    pcVar3 = _Dst;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_238,_Dst,(int)pcVar3 - (int)(_Dst + 1));
    local_8 = 1;
    FUN_10001f4b(param_1,local_238,0,0xffffffff);
    operator_delete__(_Dst);
    if (0xf < local_224) {
      operator_delete(local_238[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10012b40 at 10012b40

void FUN_10012b40(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  *param_1,void *param_2)

{
  char cVar1;
  char ****ppppcVar2;
  char ****ppppcVar3;
  uint in_stack_0000001c;
  char ***local_4c [4];
  undefined4 local_3c;
  uint local_38;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001af31;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  local_8 = 1;
  *param_1 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            (param_1,"",0);
  FUN_100129e0((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_4c);
  local_8._0_1_ = 2;
  ppppcVar3 = (char ****)local_4c[0];
  if (local_38 < 0x10) {
    ppppcVar3 = local_4c;
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
  ppppcVar2 = ppppcVar3;
  do {
    cVar1 = *(char *)ppppcVar2;
    ppppcVar2 = (char ****)((int)ppppcVar2 + 1);
  } while (cVar1 != '\0');
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_30,(char *)ppppcVar3,(int)ppppcVar2 - (int)((int)ppppcVar3 + 1));
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_1000b720(local_30,(int *)"\\Cummins_Inc\\SCL");
  cVar1 = FUN_10016be0(local_30);
  if (cVar1 == '\0') {
    cVar1 = FUN_10016d00(local_30);
    if (cVar1 == '\0') goto LAB_10012c3e;
  }
  FUN_10001f4b(param_1,local_30,0,0xffffffff);
  FUN_1000b720(param_1,(int *)&DAT_1001fe24);
  FUN_1000b700(param_1,&param_2);
LAB_10012c3e:
  if (0xf < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
  if (0xf < local_38) {
    operator_delete(local_4c[0]);
  }
  local_38 = 0xf;
  local_3c = 0;
  local_4c[0] = (char ***)((uint)local_4c[0] & 0xffffff00);
  if (0xf < in_stack_0000001c) {
    operator_delete(param_2);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10012cb0 at 10012cb0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10012cb0(void *this,void *param_1,void *param_2)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  uint _Size;
  void *pvVar4;
  char *pcVar5;
  byte *pbVar6;
  char *pcVar7;
  uint in_stack_0000001c;
  void *in_stack_fffeff20;
  uint uVar8;
  undefined1 *puStack_100ac;
  void *pvStack_100a8;
  FILE *pFStack_100a4;
  void *pvStack_100a0;
  char *pcStack_1009c;
  undefined1 *puStack_10098;
  undefined4 auStack_10094 [6];
  void *pvStack_1007c;
  int aiStack_10064 [16389];
  void *local_50 [4];
  undefined4 local_40;
  uint local_3c;
  void *local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001af8e;
  local_10 = ExceptionList;
  local_18 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  local_14 = &stack0xfffeff3c;
  ExceptionList = &local_10;
  pvStack_100a0 = param_1;
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  puStack_10098 = (undefined1 *)0x0;
  if (param_1 == (void *)0x0) {
    local_14 = &stack0xfffeff3c;
    if (0xf < in_stack_0000001c) {
      local_14 = &stack0xfffeff3c;
      operator_delete(param_2);
    }
  }
  else {
    puStack_100ac = &stack0xfffeff20;
    *(undefined1 *)((int)param_1 + 0x20) = 0;
    FUN_1000bb40(param_1,&stack0xfffeff20);
    FUN_10012b40((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 local_34,in_stack_fffeff20);
    local_8._0_1_ = 1;
    iVar3 = FUN_1000b460((int)local_34);
    if (iVar3 != 0) {
      FUN_1000de70(&puStack_100ac,(undefined4 *)((int)this + 4));
      local_8._0_1_ = 2;
      local_3c = 0xf;
      local_40 = 0;
      local_50[0] = (void *)((uint)local_50[0] & 0xffffff00);
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 local_50,"rb",2);
      local_8._0_1_ = 3;
      cVar2 = FUN_10016a00(local_34,local_50,&pFStack_100a4);
      local_8 = CONCAT31(local_8._1_3_,2);
      if (0xf < local_3c) {
        operator_delete(local_50[0]);
      }
      if (cVar2 == '\0') {
        puStack_10098 = (undefined1 *)0xa;
      }
      else {
        fseek(pFStack_100a4,0,2);
        _Size = ftell(pFStack_100a4);
        fseek(pFStack_100a4,0,0);
        if (_Size != 0) {
          pvVar4 = (void *)FUN_100171c8(_Size);
          pvStack_100a8 = pvVar4;
          memset(pvVar4,0,_Size);
          uVar8 = 0;
          fread(pvVar4,1,_Size,pFStack_100a4);
          fclose(pFStack_100a4);
          pcStack_1009c = (char *)0x0;
          FUN_100013e0(pvVar4,_Size,&pcStack_1009c);
          if (pvVar4 != (void *)0x0) {
            operator_delete__(pvVar4);
            pvStack_100a8 = (void *)0x0;
          }
          FUN_10011aa0(auStack_10094);
          pcVar1 = pcStack_1009c;
          local_8 = CONCAT31(local_8._1_3_,5);
          for (pcVar5 = pcStack_1009c; *pcVar5 != '\0'; pcVar5 = pcVar5 + 1) {
          }
          iVar3 = 1 - (int)pcStack_1009c;
          pbVar6 = (byte *)FUN_10010bf0(aiStack_10064,(uint)(pcVar5 + iVar3));
          if (pcVar1 != (char *)0x0) {
            for (pcVar7 = (char *)0x0; pcVar7 < pcVar5 + iVar3; pcVar7 = pcVar7 + 1) {
              pbVar6[(int)pcVar7] = pcVar1[(int)pcVar7];
            }
          }
          if (pcStack_1009c != (char *)0x0) {
            operator_delete__(pcStack_1009c);
            pcStack_1009c = (char *)0x0;
          }
          FUN_10012040(auStack_10094,pbVar6);
          puStack_10098 = &stack0xfffeff24;
          pvVar4 = (void *)(uVar8 & 0xffffff00);
          FUN_10001f4b(&stack0xfffeff24,&param_2,0,0xffffffff);
          puStack_10098 = (undefined1 *)FUN_10012130(pvStack_1007c,pvStack_100a0,pvVar4);
          local_8 = CONCAT31(local_8._1_3_,4);
          FUN_10010cf0(aiStack_10064);
          local_8 = 0;
          param_1 = pvStack_100a0;
        }
      }
      local_8._0_1_ = 1;
      FUN_1000de90(&puStack_100ac);
    }
    *(undefined1 *)((int)param_1 + 0x20) = 1;
    if (0xf < local_20) {
      operator_delete(local_34[0]);
    }
    local_20 = 0xf;
    local_24 = 0;
    local_34[0] = (void *)((uint)local_34[0] & 0xffffff00);
    if (0xf < in_stack_0000001c) {
      operator_delete(param_2);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10012f33 at 10012f33

undefined4 Catch_10012f33(void)

{
  void *pvVar1;
  int unaff_EBP;
  
  (**(code **)(**(int **)(unaff_EBP + -0x100b0) + 4))();
  pvVar1 = *(void **)(unaff_EBP + -0x100a4);
  *(undefined1 *)(*(int *)(unaff_EBP + -0x1009c) + 0x20) = 1;
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  if (*(void **)(unaff_EBP + -0x10098) != (void *)0x0) {
    operator_delete__(*(void **)(unaff_EBP + -0x10098));
  }
  *(undefined4 *)(unaff_EBP + -0x10094) = 0xb;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return 0x10012f28;
}



// Function: Catch_All@10012f87 at 10012f87

undefined4 Catch_All_10012f87(void)

{
  void *pvVar1;
  int unaff_EBP;
  
  pvVar1 = *(void **)(unaff_EBP + -0x100a4);
  *(undefined1 *)(*(int *)(unaff_EBP + -0x1009c) + 0x20) = 1;
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  if (*(void **)(unaff_EBP + -0x10098) != (void *)0x0) {
    operator_delete__(*(void **)(unaff_EBP + -0x10098));
  }
  *(undefined4 *)(unaff_EBP + -0x10094) = 1;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return 0x10012f28;
}



// Function: FUN_10013050 at 10013050

void __thiscall FUN_10013050(void *this,void *param_1,void *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint in_stack_0000001c;
  uint in_stack_ffffff50;
  void *pvVar4;
  void **ppvVar5;
  undefined1 *local_78;
  FILE *local_74;
  void *local_70;
  char local_69;
  void *local_68 [4];
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
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_1001aff0;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  uStack_7 = 0;
  if (param_1 == (void *)0x0) {
    if (0xf < in_stack_0000001c) {
      operator_delete(param_2);
    }
  }
  else {
    iVar1 = FUN_1000b460((int)&param_2);
    local_78 = &stack0xffffff50;
    pvVar4 = (void *)(in_stack_ffffff50 & 0xffffff00);
    if (iVar1 == 0) {
      FUN_10001f4b(&stack0xffffff50,&param_2,0,0xffffffff);
      FUN_10012460((undefined1 *)local_4c,param_1,pvVar4);
      local_8 = 1;
      iVar1 = FUN_1000b460((int)local_4c);
      if (iVar1 != 0) {
        ppvVar5 = &local_70;
        local_70 = (void *)0x0;
        iVar1 = FUN_1000b460((int)local_4c);
        uVar2 = iVar1 + 1;
        puVar3 = FUN_1000b4e0(local_4c);
        uVar2 = FUN_100012a0(puVar3,uVar2,ppvVar5);
        FUN_1000de70(&local_78,(undefined4 *)((int)this + 4));
        local_8 = 2;
        FUN_1000bb40(param_1,&stack0xffffff50);
        FUN_10012b40((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )local_68,pvVar4);
        local_8 = 3;
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_30,"a",1);
        local_8 = 4;
        local_69 = FUN_10016a00(local_68,local_30,&local_74);
        _local_8 = CONCAT31(uStack_7,3);
        if (0xf < local_1c) {
          operator_delete(local_30[0]);
        }
        if (local_69 != '\0') {
          fclose(local_74);
        }
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_30,"wb",2);
        local_8 = 5;
        local_69 = FUN_10016a00(local_68,local_30,&local_74);
        _local_8 = CONCAT31(uStack_7,3);
        if (0xf < local_1c) {
          operator_delete(local_30[0]);
        }
        if (local_69 != '\0') {
          fwrite(local_70,1,uVar2,local_74);
          FUN_1000e1e0(param_1,0);
          fclose(local_74);
        }
        if (local_70 != (void *)0x0) {
          operator_delete__(local_70);
          local_70 = (void *)0x0;
        }
        if (0xf < local_54) {
          operator_delete(local_68[0]);
        }
        local_54 = 0xf;
        local_58 = 0;
        local_68[0] = (void *)((uint)local_68[0] & 0xffffff00);
        local_8 = 1;
        FUN_1000de90(&local_78);
      }
      if (0xf < local_38) {
        operator_delete(local_4c[0]);
      }
      local_38 = 0xf;
      local_3c = 0;
      local_4c[0] = (void *)((uint)local_4c[0] & 0xffffff00);
      if (0xf < in_stack_0000001c) {
        operator_delete(param_2);
      }
    }
    else {
      local_78 = &stack0xffffff50;
      FUN_10001f4b(&stack0xffffff50,&param_2,0,0xffffffff);
      FUN_100127e0(this,param_1,pvVar4);
      if (0xf < in_stack_0000001c) {
        operator_delete(param_2);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100132f0 at 100132f0

undefined4 * __fastcall FUN_100132f0(undefined4 *param_1)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,(LPCWSTR)0x0);
  *param_1 = pvVar1;
  return param_1;
}



// Function: FUN_10013310 at 10013310

void __fastcall FUN_10013310(undefined4 *param_1)

{
  CloseHandle((HANDLE)*param_1);
  return;
}



// Function: FUN_10013320 at 10013320

void __fastcall FUN_10013320(undefined4 *param_1)

{
  WaitForSingleObject((HANDLE)*param_1,0xffffffff);
  return;
}



// Function: FUN_10013330 at 10013330

void __fastcall FUN_10013330(undefined4 *param_1)

{
  ReleaseMutex((HANDLE)*param_1);
  return;
}



// Function: FUN_10013340 at 10013340

void __cdecl FUN_10013340(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  cVar1 = *(char *)(iVar2 + 0x45);
  while (cVar1 == '\0') {
    iVar2 = *(int *)(iVar2 + 8);
    cVar1 = *(char *)(iVar2 + 0x45);
  }
  return;
}



// Function: FUN_10013360 at 10013360

void __cdecl FUN_10013360(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  cVar1 = *(char *)((int)piVar2 + 0x45);
  while (cVar1 == '\0') {
    piVar2 = (int *)*piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x45);
  }
  return;
}



// Function: FUN_10013380 at 10013380

void __fastcall FUN_10013380(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  iVar2 = *param_1;
  if (*(char *)(iVar2 + 0x45) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x45) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x45);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x45);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *param_1 = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x45);
    while ((cVar1 == '\0' && (*param_1 == *(int *)(iVar2 + 8)))) {
      *param_1 = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x45);
    }
    *param_1 = iVar2;
  }
  return;
}



// Function: FUN_100133d0 at 100133d0

void __fastcall FUN_100133d0(int *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  puVar2 = (undefined4 *)*param_1;
  if (*(char *)((int)puVar2 + 0x45) != '\0') {
    *param_1 = puVar2[2];
    return;
  }
  piVar5 = (int *)*puVar2;
  if (*(char *)((int)piVar5 + 0x45) == '\0') {
    iVar3 = piVar5[2];
    if (*(char *)(piVar5[2] + 0x45) == '\0') {
      do {
        iVar4 = iVar3;
        iVar3 = *(int *)(iVar4 + 8);
      } while (*(char *)(iVar3 + 0x45) == '\0');
      *param_1 = iVar4;
      return;
    }
  }
  else {
    piVar5 = (int *)puVar2[1];
    cVar1 = *(char *)((int)piVar5 + 0x45);
    while ((cVar1 == '\0' && (*param_1 == *piVar5))) {
      *param_1 = (int)piVar5;
      piVar5 = (int *)piVar5[1];
      cVar1 = *(char *)((int)piVar5 + 0x45);
    }
    if (*(char *)(*param_1 + 0x45) != '\0') {
      return;
    }
  }
  *param_1 = (int)piVar5;
  return;
}



// Function: FUN_10013430 at 10013430

void __thiscall FUN_10013430(void *this,int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x45) == '\0') {
    *(int *)(*piVar1 + 4) = param_1;
  }
  piVar1[1] = *(int *)(param_1 + 4);
  if (param_1 == *(int *)(*(int *)((int)this + 4) + 4)) {
    *(int **)(*(int *)((int)this + 4) + 4) = piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2 = *(int **)(param_1 + 4);
  if (param_1 == *piVar2) {
    *piVar2 = (int)piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2[2] = (int)piVar1;
  *piVar1 = param_1;
  *(int **)(param_1 + 4) = piVar1;
  return;
}



// Function: FUN_10013490 at 10013490

void __thiscall FUN_10013490(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x45) == '\0') {
    *(int **)(*(int *)(iVar1 + 8) + 4) = param_1;
  }
  *(int *)(iVar1 + 4) = param_1[1];
  if (param_1 == *(int **)(*(int *)((int)this + 4) + 4)) {
    *(int *)(*(int *)((int)this + 4) + 4) = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  piVar2 = (int *)param_1[1];
  if (param_1 == (int *)piVar2[2]) {
    piVar2[2] = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  *piVar2 = iVar1;
  *(int **)(iVar1 + 8) = param_1;
  param_1[1] = iVar1;
  return;
}



// Function: FUN_100134f0 at 100134f0

undefined4 __cdecl FUN_100134f0(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  byte **ppbVar3;
  int iVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  char *pcVar5;
  bool bVar6;
  uint in_stack_00000018;
  
  pbVar2 = param_1;
  ppbVar3 = (byte **)param_1;
  if (in_stack_00000018 < 0x10) {
    ppbVar3 = &param_1;
  }
  pcVar5 = "Integer";
  do {
    bVar1 = *(byte *)ppbVar3;
    bVar6 = bVar1 < (byte)*pcVar5;
    if (bVar1 != *pcVar5) {
LAB_10013530:
      iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
      goto LAB_10013535;
    }
    if (bVar1 == 0) break;
    bVar1 = *(byte *)((int)ppbVar3 + 1);
    bVar6 = bVar1 < ((byte *)pcVar5)[1];
    if (bVar1 != ((byte *)pcVar5)[1]) goto LAB_10013530;
    ppbVar3 = (byte **)((int)ppbVar3 + 2);
    pcVar5 = (char *)((byte *)pcVar5 + 2);
  } while (bVar1 != 0);
  iVar4 = 0;
LAB_10013535:
  if (iVar4 == 0) {
    if (0xf < in_stack_00000018) {
      operator_delete(param_1);
    }
    return 1;
  }
  ppbVar3 = (byte **)param_1;
  if (in_stack_00000018 < 0x10) {
    ppbVar3 = &param_1;
  }
  pcVar5 = "String";
  do {
    bVar1 = *(byte *)ppbVar3;
    bVar6 = bVar1 < (byte)*pcVar5;
    if (bVar1 != *pcVar5) {
LAB_10013580:
      iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
      goto LAB_10013585;
    }
    if (bVar1 == 0) break;
    bVar1 = *(byte *)((int)ppbVar3 + 1);
    bVar6 = bVar1 < ((byte *)pcVar5)[1];
    if (bVar1 != ((byte *)pcVar5)[1]) goto LAB_10013580;
    ppbVar3 = (byte **)((int)ppbVar3 + 2);
    pcVar5 = (char *)((byte *)pcVar5 + 2);
  } while (bVar1 != 0);
  iVar4 = 0;
LAB_10013585:
  if (iVar4 == 0) {
    if (0xf < in_stack_00000018) {
      operator_delete(param_1);
    }
    return 3;
  }
  bVar6 = FUN_1000b7e0(&param_1,(byte *)"Boolean");
  if (CONCAT31(extraout_var,bVar6) != 0) {
    if (0xf < in_stack_00000018) {
      operator_delete(pbVar2);
    }
    return 2;
  }
  bVar6 = FUN_1000b7e0(&param_1,(byte *)"Float");
  if (CONCAT31(extraout_var_00,bVar6) != 0) {
    FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &param_1);
    return 4;
  }
  bVar6 = FUN_1000b7e0((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)&param_1,(byte *)"Enumeration");
  if (CONCAT31(extraout_var_01,bVar6) != 0) {
    FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &param_1);
    return 5;
  }
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &param_1);
  return 0;
}



// Function: FUN_10013620 at 10013620

void __fastcall FUN_10013620(undefined4 *param_1)

{
  if (0xf < (uint)param_1[0xc]) {
    operator_delete((void *)param_1[7]);
  }
  param_1[0xc] = 0xf;
  param_1[0xb] = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  if (0xf < (uint)param_1[5]) {
    operator_delete((void *)*param_1);
  }
  param_1[5] = 0xf;
  param_1[4] = 0;
  *(undefined1 *)param_1 = 0;
  return;
}



// Function: FUN_10013670 at 10013670

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __cdecl
FUN_10013670(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,
            undefined4 param_2)

{
  switch(param_2) {
  case 0:
    FUN_10006c43(param_1,"");
    return param_1;
  case 1:
    FUN_10006c43(param_1,"Integer");
    return param_1;
  case 2:
    FUN_10006c43(param_1,"Boolean");
    return param_1;
  case 3:
    FUN_10006c43(param_1,"String");
    return param_1;
  case 4:
    FUN_10006c43(param_1,"Float");
    return param_1;
  case 5:
    FUN_10006c43(param_1,"Enumeration");
    return param_1;
  default:
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0xf;
    *param_1 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              (param_1,"",0);
    return param_1;
  }
}



// Function: FUN_10013750 at 10013750

void __cdecl FUN_10013750(undefined4 param_1,float param_2,void *param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  uint in_stack_00000020;
  void *in_stack_00000028;
  void *local_e8 [5];
  uint local_d4;
  void *local_cc [5];
  uint local_b8;
  void *local_b0 [5];
  uint local_9c;
  char local_94;
  undefined1 local_93 [127];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b049;
  local_10 = ExceptionList;
  uVar1 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_94 = '\0';
  local_14 = uVar1;
  memset(local_93,0,0x7f);
  switch(param_1) {
  case 1:
    puVar2 = (undefined4 *)
             FUN_10016f60((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                           *)local_cc,(int)param_2,0);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_10001f4b(in_stack_00000028,puVar2,0,0xffffffff);
    if (0xf < local_b8) {
      operator_delete(local_cc[0]);
    }
    break;
  case 2:
    puVar2 = (undefined4 *)
             FUN_10016f60((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                           *)local_e8,(uint)param_2 & 0xff,0);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10001f4b(in_stack_00000028,puVar2,0,0xffffffff);
    if (0xf < local_d4) {
      operator_delete(local_e8[0]);
    }
    break;
  case 3:
  case 5:
    FUN_10001f4b(in_stack_00000028,&param_3,0,0xffffffff);
    break;
  case 4:
    sprintf_s(&local_94,0x80,"%f",(double)param_2,uVar1);
    FUN_10006c43(local_b0,&local_94);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_10001f4b(in_stack_00000028,local_b0,0,0xffffffff);
    if (0xf < local_9c) {
      operator_delete(local_b0[0]);
    }
  }
  if (0xf < in_stack_00000020) {
    operator_delete(param_3);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10013900 at 10013900

void __thiscall FUN_10013900(void *this,undefined4 *param_1)

{
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> bVar1;
  byte bVar2;
  float fVar3;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar5;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar6;
  byte ****ppppbVar7;
  int iVar8;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  void *pvVar9;
  char *pcVar10;
  bool bVar11;
  double dVar12;
  double dVar13;
  uint in_stack_fffffee4;
  undefined4 *puVar14;
  char **ppcVar15;
  char *local_e4;
  undefined1 *local_e0;
  undefined4 *local_dc;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_d8 [28];
  void *local_bc [4];
  undefined4 local_ac;
  uint local_a8;
  void *local_a0 [4];
  undefined4 local_90;
  uint local_8c;
  void *local_84 [4];
  undefined4 local_74;
  uint local_70;
  void *local_68 [4];
  undefined4 local_58;
  uint local_54;
  void *local_4c [4];
  undefined4 local_3c;
  uint local_38;
  byte ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b0d7;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_e0 = &stack0xfffffee4;
  local_dc = param_1;
  puVar14 = (undefined4 *)(in_stack_fffffee4 & 0xffffff00);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xfffffee4,"value",5);
  pvVar9 = (void *)((int)this + 4);
  pbVar4 = FUN_1000e280(pvVar9,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                                *)local_a0,puVar14);
  local_8 = 0;
  if (0xf < *(uint *)(pbVar4 + 0x14)) {
    pbVar4 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
              pbVar4;
  }
  local_70 = 0xf;
  local_74 = 0;
  local_84[0] = (void *)((uint)local_84[0] & 0xffffff00);
  pbVar5 = pbVar4;
  do {
    bVar1 = *pbVar5;
    pbVar5 = pbVar5 + 1;
  } while (bVar1 != (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)
                    0x0);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_84,(char *)pbVar4,(int)pbVar5 - (int)(pbVar4 + 1));
  local_8._0_1_ = 2;
  if (0xf < local_8c) {
    operator_delete(local_a0[0]);
  }
  local_e0 = &stack0xfffffee4;
  local_8c = 0xf;
  local_90 = 0;
  local_a0[0] = (void *)((uint)local_a0[0] & 0xffffff00);
  puVar14 = (undefined4 *)((uint)puVar14 & 0xffffff00);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xfffffee4,"val_type",8);
  pbVar4 = FUN_1000e280(pvVar9,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                                *)local_bc,puVar14);
  local_8._0_1_ = 3;
  if (0xf < *(uint *)(pbVar4 + 0x14)) {
    pbVar4 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
              pbVar4;
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (byte ***)((uint)local_30[0] & 0xffffff00);
  pbVar5 = pbVar4;
  do {
    bVar1 = *pbVar5;
    pbVar5 = pbVar5 + 1;
  } while (bVar1 != (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)
                    0x0);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_30,(char *)pbVar4,(int)pbVar5 - (int)(pbVar4 + 1));
  local_8._0_1_ = 5;
  if (0xf < local_a8) {
    operator_delete(local_bc[0]);
  }
  local_e0 = &stack0xfffffee4;
  local_a8 = 0xf;
  local_ac = 0;
  local_bc[0] = (void *)((uint)local_bc[0] & 0xffffff00);
  puVar14 = (undefined4 *)((uint)puVar14 & 0xffffff00);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xfffffee4,"range_min",9);
  pbVar4 = FUN_1000e280(pvVar9,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                                *)local_a0,puVar14);
  local_8._0_1_ = 6;
  if (0xf < *(uint *)(pbVar4 + 0x14)) {
    pbVar4 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
              pbVar4;
  }
  local_38 = 0xf;
  local_3c = 0;
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffffff00);
  pbVar5 = pbVar4;
  do {
    bVar1 = *pbVar5;
    pbVar5 = pbVar5 + 1;
  } while (bVar1 != (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)
                    0x0);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_4c,(char *)pbVar4,(int)pbVar5 - (int)(pbVar4 + 1));
  local_8._0_1_ = 8;
  if (0xf < local_8c) {
    operator_delete(local_a0[0]);
  }
  local_e0 = &stack0xfffffee4;
  local_8c = 0xf;
  local_90 = 0;
  local_a0[0] = (void *)((uint)local_a0[0] & 0xffffff00);
  puVar14 = (undefined4 *)((uint)puVar14 & 0xffffff00);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xfffffee4,"range_max",9);
  pbVar4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)local_bc;
  pbVar5 = FUN_1000e280(pvVar9,pbVar4,puVar14);
  local_8._0_1_ = 9;
  if (0xf < *(uint *)(pbVar5 + 0x14)) {
    pbVar5 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
              pbVar5;
  }
  local_54 = 0xf;
  local_58 = 0;
  local_68[0] = (void *)((uint)local_68[0] & 0xffffff00);
  pbVar6 = pbVar5;
  do {
    bVar1 = *pbVar6;
    pbVar6 = pbVar6 + 1;
  } while (bVar1 != (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)
                    0x0);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_68,(char *)pbVar5,(int)pbVar6 - (int)(pbVar5 + 1));
  local_8._0_1_ = 0xb;
  if (0xf < local_a8) {
    operator_delete(local_bc[0]);
  }
  local_a8 = 0xf;
  local_ac = 0;
  local_bc[0] = (void *)((uint)local_bc[0] & 0xffffff00);
  ppppbVar7 = (byte ****)local_30[0];
  if (local_1c < 0x10) {
    ppppbVar7 = local_30;
  }
  pcVar10 = "Integer";
  do {
    bVar2 = *(byte *)ppppbVar7;
    bVar11 = bVar2 < (byte)*pcVar10;
    if (bVar2 != *pcVar10) {
LAB_10013bd0:
      iVar8 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
      goto LAB_10013bd5;
    }
    if (bVar2 == 0) break;
    bVar2 = *(byte *)((int)ppppbVar7 + 1);
    bVar11 = bVar2 < ((byte *)pcVar10)[1];
    if (bVar2 != ((byte *)pcVar10)[1]) goto LAB_10013bd0;
    ppppbVar7 = (byte ****)((int)ppppbVar7 + 2);
    pcVar10 = (char *)((byte *)pcVar10 + 2);
  } while (bVar2 != 0);
  iVar8 = 0;
LAB_10013bd5:
  if (iVar8 == 0) {
LAB_10013e44:
    local_e0 = &stack0xfffffee0;
    local_e4 = (char *)0x0;
    pvVar9 = (void *)((uint)pbVar4 & 0xffffff00);
    FUN_10001f4b(&stack0xfffffee0,local_4c,0,0xffffffff);
    FUN_10016e20(pvVar9);
    local_e0 = &stack0xfffffee0;
    pvVar9 = (void *)((uint)pvVar9 & 0xffffff00);
    FUN_10001f4b(&stack0xfffffee0,local_68,0,0xffffffff);
    FUN_10016e20(pvVar9);
    local_e0 = &stack0xfffffee0;
    pvVar9 = (void *)((uint)pvVar9 & 0xffffff00);
    FUN_10001f4b(&stack0xfffffee0,local_84,0,0xffffffff);
    FUN_10016e20(pvVar9);
    pcVar10 = local_e4;
    if ((-1 < (int)local_e4) && ((int)local_e4 < 1)) {
      bVar11 = FUN_1000b7e0(local_30,(byte *)"Boolean");
      if (CONCAT31(extraout_var_02,bVar11) == 0) {
        local_dc[1] = pcVar10;
        *local_dc = 1;
      }
      else {
        *(bool *)(local_dc + 1) = pcVar10 != (char *)0x0;
        *local_dc = 2;
      }
      if (0xf < local_54) {
        operator_delete(local_68[0]);
      }
      local_54 = 0xf;
      local_58 = 0;
      local_68[0] = (void *)((uint)local_68[0] & 0xffffff00);
      if (0xf < local_38) {
        operator_delete(local_4c[0]);
      }
      local_38 = 0xf;
      local_3c = 0;
      local_4c[0] = (void *)((uint)local_4c[0] & 0xffffff00);
      if (0xf < local_1c) {
        operator_delete(local_30[0]);
      }
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = (byte ***)((uint)local_30[0] & 0xffffff00);
      if (0xf < local_70) {
        operator_delete(local_84[0]);
      }
      goto LAB_1001401c;
    }
    *local_dc = 0;
    if (0xf < local_54) {
      operator_delete(local_68[0]);
    }
  }
  else {
    ppppbVar7 = (byte ****)local_30[0];
    if (local_1c < 0x10) {
      ppppbVar7 = local_30;
    }
    pcVar10 = "Boolean";
    do {
      bVar2 = *(byte *)ppppbVar7;
      bVar11 = bVar2 < (byte)*pcVar10;
      if (bVar2 != *pcVar10) {
LAB_10013c10:
        iVar8 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        goto LAB_10013c15;
      }
      if (bVar2 == 0) break;
      bVar2 = *(byte *)((int)ppppbVar7 + 1);
      bVar11 = bVar2 < ((byte *)pcVar10)[1];
      if (bVar2 != ((byte *)pcVar10)[1]) goto LAB_10013c10;
      ppppbVar7 = (byte ****)((int)ppppbVar7 + 2);
      pcVar10 = (char *)((byte *)pcVar10 + 2);
    } while (bVar2 != 0);
    iVar8 = 0;
LAB_10013c15:
    if (iVar8 == 0) goto LAB_10013e44;
    bVar11 = FUN_1000b7e0(local_30,(byte *)"Float");
    if (CONCAT31(extraout_var,bVar11) == 0) {
      bVar11 = FUN_1000b7e0(local_30,(byte *)"String");
      if (CONCAT31(extraout_var_00,bVar11) == 0) {
        bVar11 = FUN_1000b7e0(local_30,(byte *)"Enumeration");
        if (CONCAT31(extraout_var_01,bVar11) == 0) {
          FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)local_68);
          FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)local_4c);
          FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)local_30);
          FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)local_84);
          goto LAB_1001401c;
        }
        pcVar10 = (char *)FUN_1000b4e0(local_4c);
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (local_d8,pcVar10);
        pvVar9 = (void *)0x0;
        local_8._0_1_ = 0xc;
        pcVar10 = (char *)FUN_1000b4e0(local_84);
        iVar8 = FUN_100071a2(local_d8,pcVar10,pvVar9);
        if (iVar8 == -1) {
          *local_dc = 0;
          FUN_10001d72(local_d8);
          FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)local_68);
          FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)local_4c);
          FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)local_30);
          FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)local_84);
          goto LAB_1001401c;
        }
        *local_dc = 5;
        FUN_10001f4b(local_dc + 2,local_84,0,0xffffffff);
        FUN_10001d72(local_d8);
      }
      else {
        *local_dc = 3;
        FUN_10001f4b(local_dc + 2,local_84,0,0xffffffff);
      }
LAB_10013cd9:
      FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_68);
      FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_4c);
      FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_30);
      FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_84);
      goto LAB_1001401c;
    }
    ppcVar15 = &local_e4;
    local_e4 = (char *)0x0;
    pcVar10 = (char *)FUN_1000b4e0(local_84);
    dVar12 = strtod(pcVar10,ppcVar15);
    fVar3 = (float)dVar12;
    ppcVar15 = &local_e4;
    pcVar10 = (char *)FUN_1000b4e0(local_4c);
    dVar12 = strtod(pcVar10,ppcVar15);
    ppcVar15 = &local_e4;
    pcVar10 = (char *)FUN_1000b4e0(local_68);
    dVar13 = strtod(pcVar10,ppcVar15);
    local_e0 = (undefined1 *)(float)dVar13;
    if (((float)dVar12 < fVar3 != ((float)dVar12 == fVar3)) && (fVar3 <= (float)local_e0)) {
      local_dc[1] = fVar3;
      *local_dc = 4;
      goto LAB_10013cd9;
    }
    *local_dc = 0;
    if (0xf < local_54) {
      operator_delete(local_68[0]);
    }
  }
  local_68[0] = (void *)((uint)local_68[0] & 0xffffff00);
  local_58 = 0;
  local_54 = 0xf;
  if (0xf < local_38) {
    operator_delete(local_4c[0]);
  }
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffffff00);
  local_3c = 0;
  local_38 = 0xf;
  if (0xf < local_1c) {
    operator_delete(local_30[0]);
  }
  local_30[0] = (byte ***)((uint)local_30[0] & 0xffffff00);
  local_20 = 0;
  local_1c = 0xf;
  if (0xf < local_70) {
    operator_delete(local_84[0]);
  }
LAB_1001401c:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10014040 at 10014040

void __cdecl FUN_10014040(undefined4 param_1,undefined4 *param_2)

{
  if (0xf < (uint)param_2[0xc]) {
    operator_delete((void *)param_2[7]);
  }
  param_2[0xc] = 0xf;
  param_2[0xb] = 0;
  *(undefined1 *)(param_2 + 7) = 0;
  if (0xf < (uint)param_2[5]) {
    operator_delete((void *)*param_2);
  }
  param_2[5] = 0xf;
  param_2[4] = 0;
  *(undefined1 *)param_2 = 0;
  return;
}



// Function: FUN_10014090 at 10014090

void __thiscall
FUN_10014090(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

{
  char cVar1;
  int *piVar2;
  uint extraout_EAX;
  uint uVar3;
  int *piVar4;
  void *extraout_ECX;
  int *piVar5;
  int iVar6;
  int *piVar7;
  
  uVar3 = *(uint *)((int)this + 8);
  if (0x4924922 < uVar3) {
    if (0xf < (uint)param_4[0xf]) {
      operator_delete((void *)param_4[10]);
    }
    param_4[0xf] = 0xf;
    param_4[0xe] = 0;
    *(undefined1 *)(param_4 + 10) = 0;
    if (0xf < (uint)param_4[8]) {
      operator_delete((void *)param_4[3]);
    }
    param_4[8] = 0xf;
    param_4[7] = 0;
    *(undefined1 *)(param_4 + 3) = 0;
    operator_delete(param_4);
    std::_Xlength_error("map/set<T> too long");
    uVar3 = extraout_EAX;
    this = extraout_ECX;
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
  cVar1 = *(char *)(param_4[1] + 0x44);
  piVar4 = param_4;
  do {
    if (cVar1 != '\0') {
      iVar6 = *(int *)(*(int *)((int)this + 4) + 4);
      *param_1 = param_4;
      *(undefined1 *)(iVar6 + 0x44) = 1;
      return;
    }
    piVar5 = (int *)piVar4[1];
    piVar7 = (int *)piVar5[1];
    if (piVar5 == (int *)*piVar7) {
      iVar6 = piVar7[2];
      if (*(char *)(iVar6 + 0x44) == '\0') goto LAB_10014217;
      if (piVar4 == (int *)piVar5[2]) {
        piVar4 = (int *)piVar5[2];
        piVar5[2] = *piVar4;
        if (*(char *)(*piVar4 + 0x45) == '\0') {
          *(int **)(*piVar4 + 4) = piVar5;
        }
        piVar4[1] = piVar5[1];
        if (piVar5 == *(int **)(*(int *)((int)this + 4) + 4)) {
          *(int **)(*(int *)((int)this + 4) + 4) = piVar4;
        }
        else {
          piVar7 = (int *)piVar5[1];
          if (piVar5 == (int *)*piVar7) {
            *piVar7 = (int)piVar4;
          }
          else {
            piVar7[2] = (int)piVar4;
          }
        }
        *piVar4 = (int)piVar5;
        piVar5[1] = (int)piVar4;
        piVar4 = piVar5;
      }
      *(undefined1 *)(piVar4[1] + 0x44) = 1;
      *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0x44) = 0;
      piVar5 = *(int **)(piVar4[1] + 4);
      piVar7 = (int *)*piVar5;
      *piVar5 = piVar7[2];
      if (*(char *)(piVar7[2] + 0x45) == '\0') {
        *(int **)(piVar7[2] + 4) = piVar5;
      }
      piVar7[1] = piVar5[1];
      if (piVar5 == *(int **)(*(int *)((int)this + 4) + 4)) {
        *(int **)(*(int *)((int)this + 4) + 4) = piVar7;
        piVar7[2] = (int)piVar5;
      }
      else {
        piVar2 = (int *)piVar5[1];
        if (piVar5 == (int *)piVar2[2]) {
          piVar2[2] = (int)piVar7;
          piVar7[2] = (int)piVar5;
        }
        else {
          *piVar2 = (int)piVar7;
          piVar7[2] = (int)piVar5;
        }
      }
LAB_100142bf:
      piVar5[1] = (int)piVar7;
    }
    else {
      iVar6 = *piVar7;
      if (*(char *)(iVar6 + 0x44) != '\0') {
        if (piVar4 == (int *)*piVar5) {
          iVar6 = *piVar5;
          *piVar5 = *(int *)(iVar6 + 8);
          if (*(char *)(*(int *)(iVar6 + 8) + 0x45) == '\0') {
            *(int **)(*(int *)(iVar6 + 8) + 4) = piVar5;
          }
          *(int *)(iVar6 + 4) = piVar5[1];
          if (piVar5 == *(int **)(*(int *)((int)this + 4) + 4)) {
            *(int *)(*(int *)((int)this + 4) + 4) = iVar6;
          }
          else {
            piVar4 = (int *)piVar5[1];
            if (piVar5 == (int *)piVar4[2]) {
              piVar4[2] = iVar6;
            }
            else {
              *piVar4 = iVar6;
            }
          }
          *(int **)(iVar6 + 8) = piVar5;
          piVar5[1] = iVar6;
          piVar4 = piVar5;
        }
        *(undefined1 *)(piVar4[1] + 0x44) = 1;
        *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0x44) = 0;
        piVar5 = *(int **)(piVar4[1] + 4);
        piVar7 = (int *)piVar5[2];
        piVar5[2] = *piVar7;
        if (*(char *)(*piVar7 + 0x45) == '\0') {
          *(int **)(*piVar7 + 4) = piVar5;
        }
        piVar7[1] = piVar5[1];
        if (piVar5 == *(int **)(*(int *)((int)this + 4) + 4)) {
          *(int **)(*(int *)((int)this + 4) + 4) = piVar7;
        }
        else {
          piVar2 = (int *)piVar5[1];
          if (piVar5 == (int *)*piVar2) {
            *piVar2 = (int)piVar7;
          }
          else {
            piVar2[2] = (int)piVar7;
          }
        }
        *piVar7 = (int)piVar5;
        goto LAB_100142bf;
      }
LAB_10014217:
      *(undefined1 *)(piVar5 + 0x11) = 1;
      *(undefined1 *)(iVar6 + 0x44) = 1;
      *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0x44) = 0;
      piVar4 = *(int **)(piVar4[1] + 4);
    }
    cVar1 = *(char *)(piVar4[1] + 0x44);
  } while( true );
}



// Function: FUN_100142f0 at 100142f0

undefined4 __cdecl FUN_100142f0(void *param_1)

{
  undefined4 uVar1;
  char *_Str;
  double dVar2;
  undefined4 uStack00000014;
  uint in_stack_00000018;
  void *in_stack_00000020;
  uint in_stack_00000034;
  undefined4 *in_stack_0000003c;
  undefined4 uVar3;
  uint3 uVar5;
  void *pvVar4;
  uint in_stack_ffffffb8;
  byte *pbVar6;
  char **_EndPtr;
  char *local_1c;
  undefined1 *local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b110;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = &stack0xffffffb8;
  local_14 = 0;
  local_1c = (char *)0x0;
  local_8 = 1;
  pbVar6 = (byte *)(in_stack_ffffffb8 & 0xffffff00);
  FUN_10001f4b(&stack0xffffffb8,&stack0x00000020,0,0xffffffff);
  uVar3 = 0x10014350;
  uVar1 = FUN_100134f0(pbVar6);
  uVar5 = (uint3)((uint)uVar3 >> 8);
  switch(uVar1) {
  case 1:
    local_18 = &stack0xffffffb4;
    pvVar4 = (void *)((uint)uVar5 << 8);
    FUN_10001f4b(&stack0xffffffb4,&param_1,0,0xffffffff);
    FUN_10016e20(pvVar4);
    in_stack_0000003c[1] = local_14;
    *in_stack_0000003c = 1;
    break;
  case 2:
    local_18 = &stack0xffffffb4;
    pvVar4 = (void *)((uint)uVar5 << 8);
    FUN_10001f4b(&stack0xffffffb4,&param_1,0,0xffffffff);
    FUN_10016e20(pvVar4);
    *(undefined1 *)(in_stack_0000003c + 1) = (undefined1)local_14;
    *in_stack_0000003c = 2;
    break;
  case 3:
    FUN_10001f4b(in_stack_0000003c + 2,&param_1,0,0xffffffff);
    *in_stack_0000003c = 3;
    break;
  case 4:
    _EndPtr = &local_1c;
    _Str = (char *)FUN_1000b4e0(&param_1);
    dVar2 = strtod(_Str,_EndPtr);
    in_stack_0000003c[1] = (float)dVar2;
    *in_stack_0000003c = 4;
    break;
  case 5:
    FUN_10001f4b(in_stack_0000003c + 2,&param_1,0,0xffffffff);
    *in_stack_0000003c = 5;
    break;
  default:
    *in_stack_0000003c = 0;
  }
  if (0xf < in_stack_00000018) {
    operator_delete(param_1);
  }
  in_stack_00000018 = 0xf;
  uStack00000014 = 0;
  param_1 = (void *)((uint)param_1 & 0xffffff00);
  if (0xf < in_stack_00000034) {
    operator_delete(in_stack_00000020);
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_10014480 at 10014480

void FUN_10014480(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x45);
  while (cVar1 == '\0') {
    FUN_10014480((int *)param_1[2]);
    piVar2 = (int *)*param_1;
    if (0xf < (uint)param_1[0xf]) {
      operator_delete((void *)param_1[10]);
    }
    param_1[0xf] = 0xf;
    param_1[0xe] = 0;
    *(undefined1 *)(param_1 + 10) = 0;
    if (0xf < (uint)param_1[8]) {
      operator_delete((void *)param_1[3]);
    }
    param_1[8] = 0xf;
    param_1[7] = 0;
    *(undefined1 *)(param_1 + 3) = 0;
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x45);
  }
  return;
}



// Function: FUN_10014500 at 10014500

void __thiscall FUN_10014500(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  bool bVar7;
  
  piVar2 = param_2;
  if (*(char *)((int)param_2 + 0x45) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  FUN_10013380((int *)&param_2);
  piVar6 = (int *)*piVar2;
  if (*(char *)((int)piVar6 + 0x45) == '\0') {
    piVar5 = piVar6;
    if ((*(char *)(piVar2[2] + 0x45) == '\0') && (piVar5 = (int *)param_2[2], param_2 != piVar2)) {
      piVar6[1] = (int)param_2;
      *param_2 = *piVar2;
      piVar6 = param_2;
      if (param_2 != (int *)piVar2[2]) {
        piVar6 = (int *)param_2[1];
        if (*(char *)((int)piVar5 + 0x45) == '\0') {
          piVar5[1] = (int)piVar6;
        }
        *piVar6 = (int)piVar5;
        param_2[2] = piVar2[2];
        *(int **)(piVar2[2] + 4) = param_2;
      }
      if (*(int **)(*(int *)((int)this + 4) + 4) == piVar2) {
        *(int **)(*(int *)((int)this + 4) + 4) = param_2;
      }
      else {
        piVar3 = (int *)piVar2[1];
        if ((int *)*piVar3 == piVar2) {
          *piVar3 = (int)param_2;
        }
        else {
          piVar3[2] = (int)param_2;
        }
      }
      param_2[1] = piVar2[1];
      iVar1 = param_2[0x11];
      *(char *)(param_2 + 0x11) = (char)piVar2[0x11];
      *(char *)(piVar2 + 0x11) = (char)iVar1;
      goto LAB_10014620;
    }
  }
  else {
    piVar5 = (int *)piVar2[2];
  }
  piVar6 = (int *)piVar2[1];
  if (*(char *)((int)piVar5 + 0x45) == '\0') {
    piVar5[1] = (int)piVar6;
  }
  if (*(int **)(*(int *)((int)this + 4) + 4) == piVar2) {
    *(int **)(*(int *)((int)this + 4) + 4) = piVar5;
  }
  else if ((int *)*piVar6 == piVar2) {
    *piVar6 = (int)piVar5;
  }
  else {
    piVar6[2] = (int)piVar5;
  }
  if ((int *)**(int **)((int)this + 4) == piVar2) {
    piVar3 = piVar6;
    if (*(char *)((int)piVar5 + 0x45) == '\0') {
      piVar3 = (int *)FUN_10013360(piVar5);
    }
    **(undefined4 **)((int)this + 4) = piVar3;
  }
  if (*(int **)(*(int *)((int)this + 4) + 8) == piVar2) {
    if (*(char *)((int)piVar5 + 0x45) == '\0') {
      uVar4 = FUN_10013340((int)piVar5);
      *(undefined4 *)(*(int *)((int)this + 4) + 8) = uVar4;
    }
    else {
      *(int **)(*(int *)((int)this + 4) + 8) = piVar6;
    }
  }
LAB_10014620:
  if ((char)piVar2[0x11] == '\x01') {
    if (piVar5 != *(int **)(*(int *)((int)this + 4) + 4)) {
      do {
        if ((char)piVar5[0x11] != '\x01') break;
        piVar3 = (int *)*piVar6;
        if (piVar5 == piVar3) {
          piVar3 = (int *)piVar6[2];
          if ((char)piVar3[0x11] == '\0') {
            *(undefined1 *)(piVar3 + 0x11) = 1;
            *(undefined1 *)(piVar6 + 0x11) = 0;
            FUN_10013430(this,(int)piVar6);
            piVar3 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar3 + 0x45) == '\0') {
            if ((*(char *)(*piVar3 + 0x44) != '\x01') || (*(char *)(piVar3[2] + 0x44) != '\x01')) {
              if (*(char *)(piVar3[2] + 0x44) == '\x01') {
                *(undefined1 *)(*piVar3 + 0x44) = 1;
                *(undefined1 *)(piVar3 + 0x11) = 0;
                FUN_10013490(this,piVar3);
                piVar3 = (int *)piVar6[2];
              }
              *(char *)(piVar3 + 0x11) = (char)piVar6[0x11];
              *(undefined1 *)(piVar6 + 0x11) = 1;
              *(undefined1 *)(piVar3[2] + 0x44) = 1;
              FUN_10013430(this,(int)piVar6);
              break;
            }
LAB_100146e6:
            *(undefined1 *)(piVar3 + 0x11) = 0;
          }
        }
        else {
          if ((char)piVar3[0x11] == '\0') {
            *(undefined1 *)(piVar3 + 0x11) = 1;
            *(undefined1 *)(piVar6 + 0x11) = 0;
            FUN_10013490(this,piVar6);
            piVar3 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar3 + 0x45) == '\0') {
            if ((*(char *)(piVar3[2] + 0x44) == '\x01') && (*(char *)(*piVar3 + 0x44) == '\x01'))
            goto LAB_100146e6;
            if (*(char *)(*piVar3 + 0x44) == '\x01') {
              *(undefined1 *)(piVar3[2] + 0x44) = 1;
              *(undefined1 *)(piVar3 + 0x11) = 0;
              FUN_10013430(this,(int)piVar3);
              piVar3 = (int *)*piVar6;
            }
            *(char *)(piVar3 + 0x11) = (char)piVar6[0x11];
            *(undefined1 *)(piVar6 + 0x11) = 1;
            *(undefined1 *)(*piVar3 + 0x44) = 1;
            FUN_10013490(this,piVar6);
            break;
          }
        }
        bVar7 = piVar6 != *(int **)(*(int *)((int)this + 4) + 4);
        piVar5 = piVar6;
        piVar6 = (int *)piVar6[1];
      } while (bVar7);
    }
    *(undefined1 *)(piVar5 + 0x11) = 1;
  }
  if (0xf < (uint)piVar2[0xf]) {
    operator_delete((void *)piVar2[10]);
  }
  piVar2[0xf] = 0xf;
  piVar2[0xe] = 0;
  *(undefined1 *)(piVar2 + 10) = 0;
  if (0xf < (uint)piVar2[8]) {
    operator_delete((void *)piVar2[3]);
  }
  piVar2[8] = 0xf;
  piVar2[7] = 0;
  *(undefined1 *)(piVar2 + 3) = 0;
  operator_delete(piVar2);
  if (*(int *)((int)this + 8) != 0) {
    *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_100147a0 at 100147a0

void __thiscall FUN_100147a0(void *this,undefined4 *param_1,int *param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int *piVar7;
  uint uVar8;
  int *piVar9;
  bool local_8;
  
  puVar6 = *(undefined4 **)((int)this + 4);
  local_8 = true;
  if (*(char *)((int)puVar6[1] + 0x45) == '\0') {
    uVar8 = param_2[7];
    uVar1 = param_2[8];
    puVar3 = (undefined4 *)puVar6[1];
    do {
      puVar6 = puVar3;
      puVar3 = puVar6 + 3;
      if ((char)param_3 == '\0') {
        uVar2 = puVar6[7];
        if (0xf < (uint)puVar6[8]) {
          puVar3 = (undefined4 *)*puVar3;
        }
        uVar4 = param_2[7];
        if (uVar8 < (uint)param_2[7]) {
          uVar4 = uVar8;
        }
        uVar5 = uVar4;
        if (uVar2 <= uVar4) {
          uVar5 = uVar2;
        }
        if (uVar1 < 0x10) {
          piVar9 = param_2 + 3;
        }
        else {
          piVar9 = (int *)param_2[3];
        }
        uVar5 = FUN_10006c69(piVar9,puVar3,uVar5);
        if (uVar5 == 0) {
          if (uVar4 < uVar2) {
            uVar5 = 0xffffffff;
          }
          else {
            uVar5 = (uint)(uVar4 != uVar2);
          }
        }
        local_8 = (int)uVar5 < 0;
      }
      else {
        if (uVar1 < 0x10) {
          piVar9 = param_2 + 3;
        }
        else {
          piVar9 = (int *)param_2[3];
        }
        uVar2 = puVar6[7];
        uVar4 = uVar2;
        if (uVar8 <= uVar2) {
          uVar4 = uVar8;
        }
        if (0xf < (uint)puVar6[8]) {
          puVar3 = (undefined4 *)*puVar3;
        }
        uVar4 = FUN_10006c69(puVar3,piVar9,uVar4);
        if (uVar4 == 0) {
          if (uVar2 < uVar8) {
            local_8 = false;
            goto LAB_1001488c;
          }
          uVar4 = (uint)(uVar2 != uVar8);
        }
        local_8 = -1 < (int)uVar4;
      }
LAB_1001488c:
      if (local_8 == false) {
        puVar3 = (undefined4 *)puVar6[2];
      }
      else {
        puVar3 = (undefined4 *)*puVar6;
      }
    } while (*(char *)((int)puVar3 + 0x45) == '\0');
  }
  param_3 = puVar6;
  if (local_8 != false) {
    if (puVar6 == (undefined4 *)**(int **)((int)this + 4)) {
      local_8 = true;
      goto LAB_100148c1;
    }
    FUN_100133d0((int *)&param_3);
  }
  puVar3 = param_3;
  piVar9 = param_2 + 3;
  piVar7 = piVar9;
  if (0xf < (uint)param_2[8]) {
    piVar7 = (int *)*piVar9;
  }
  uVar8 = FUN_1000b470(param_3 + 3,0,param_3[7],piVar7,param_2[7]);
  if (-1 < (int)uVar8) {
    FUN_10014040((int)this + 0xd,piVar9);
    operator_delete(param_2);
    *param_1 = puVar3;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_100148c1:
  puVar6 = (undefined4 *)FUN_10014090(this,&param_3,local_8,puVar6,param_2);
  *param_1 = *puVar6;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}



// Function: FUN_10014950 at 10014950

void __thiscall FUN_10014950(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  void *local_8;
  
  piVar2 = *(int **)((int)this + 4);
  local_8 = this;
  if ((param_2 == (int *)*piVar2) && (param_3 == piVar2)) {
    FUN_10014480((int *)piVar2[1]);
    *(int *)(*(int *)((int)this + 4) + 4) = *(int *)((int)this + 4);
    *(undefined4 *)*(undefined4 *)((int)this + 4) = *(undefined4 *)((int)this + 4);
    *(int *)(*(int *)((int)this + 4) + 8) = *(int *)((int)this + 4);
    *(undefined4 *)((int)this + 8) = 0;
    *param_1 = **(undefined4 **)((int)this + 4);
    return;
  }
  if (param_2 != param_3) {
    do {
      piVar2 = param_2;
      if (*(char *)((int)param_2 + 0x45) == '\0') {
        piVar3 = (int *)param_2[2];
        if (*(char *)((int)piVar3 + 0x45) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x45);
          param_2 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x45);
            param_2 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(param_2[1] + 0x45);
          piVar4 = (int *)param_2[1];
          piVar3 = param_2;
          while ((param_2 = piVar4, cVar1 == '\0' && (piVar3 == (int *)param_2[2]))) {
            cVar1 = *(char *)(param_2[1] + 0x45);
            piVar4 = (int *)param_2[1];
            piVar3 = param_2;
          }
        }
      }
      FUN_10014500(this,&local_8,piVar2);
    } while (param_2 != param_3);
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_10014a10 at 10014a10

undefined4 * __thiscall FUN_10014a10(void *this,char *param_1)

{
  char *pcVar1;
  undefined4 *puVar2;
  uint uStack_3c;
  undefined **local_2c [3];
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b149;
  local_10 = ExceptionList;
  uStack_3c = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_3c;
  ExceptionList = &local_10;
  puVar2 = (undefined4 *)operator_new(0x48);
  pcVar1 = param_1;
  local_18 = puVar2;
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = *(undefined4 *)((int)this + 4);
    puVar2[1] = *(undefined4 *)((int)this + 4);
    local_20 = puVar2 + 3;
    puVar2[2] = *(undefined4 *)((int)this + 4);
    *(undefined2 *)(puVar2 + 0x11) = 0;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    if (local_20 != (undefined4 *)0x0) {
      puVar2[8] = 0xf;
      puVar2[7] = 0;
      *(undefined1 *)local_20 = 0;
      local_1c = local_20;
      FUN_10001f4b(local_20,(undefined4 *)param_1,0,0xffffffff);
      puVar2[0xf] = 0xf;
      puVar2[0xe] = 0;
      local_8 = CONCAT31(local_8._1_3_,2);
      *(undefined1 *)(puVar2 + 10) = 0;
      FUN_10001f4b(puVar2 + 10,(undefined4 *)(pcVar1 + 0x1c),0,0xffffffff);
    }
    ExceptionList = local_10;
    return puVar2;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_2c,&param_1);
  local_2c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_2c,(ThrowInfo *)&DAT_10020dd4);
}



// Function: Catch_All@10014ad4 at 10014ad4

void Catch_All_10014ad4(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10014b10 at 10014b10

undefined4 * __thiscall FUN_10014b10(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *this_00;
  int *piVar1;
  bool bVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 local_c [2];
  
  piVar1 = param_3;
  piVar3 = *(int **)((int)this + 4);
  this_00 = param_3 + 3;
  if (*(int *)((int)this + 8) == 0) {
    FUN_10014090(this,param_1,'\x01',piVar3,param_3);
    return param_1;
  }
  if (param_2 == (int *)*piVar3) {
    piVar3 = param_2 + 3;
    if (0xf < (uint)param_2[8]) {
      piVar3 = (int *)*piVar3;
    }
    uVar4 = FUN_1000b470(this_00,0,param_3[7],piVar3,param_2[7]);
    if ((int)uVar4 < 0) {
      FUN_10014090(this,param_1,'\x01',param_2,piVar1);
      return param_1;
    }
  }
  else if (param_2 == piVar3) {
    bVar2 = FUN_1000b830((void *)(piVar3[2] + 0xc),this_00);
    if (bVar2) {
      FUN_10014090(this,param_1,'\0',*(undefined4 **)(*(int *)((int)this + 4) + 8),piVar1);
      return param_1;
    }
  }
  else {
    bVar2 = FUN_1000b830(this_00,param_2 + 3);
    if (bVar2) {
      param_3 = param_2;
      FUN_100133d0((int *)&param_3);
      bVar2 = FUN_1000b830(param_3 + 3,this_00);
      if (bVar2) {
        if (*(char *)(param_3[2] + 0x45) == '\0') {
          FUN_10014090(this,param_1,'\x01',param_2,piVar1);
          return param_1;
        }
        FUN_10014090(this,param_1,'\0',param_3,piVar1);
        return param_1;
      }
    }
    bVar2 = FUN_1000b830(param_2 + 3,this_00);
    if (bVar2) {
      param_3 = param_2;
      FUN_10013380((int *)&param_3);
      if ((param_3 == *(int **)((int)this + 4)) ||
         (bVar2 = FUN_1000b830(this_00,param_3 + 3), bVar2)) {
        if (*(char *)(param_2[2] + 0x45) == '\0') {
          FUN_10014090(this,param_1,'\x01',param_3,piVar1);
          return param_1;
        }
        FUN_10014090(this,param_1,'\0',param_2,piVar1);
        return param_1;
      }
    }
  }
  puVar5 = (undefined4 *)FUN_100147a0(this,local_c,piVar1,(undefined4 *)0x0);
  *param_1 = *puVar5;
  return param_1;
}



// Function: FUN_10014cd0 at 10014cd0

undefined4 * __thiscall FUN_10014cd0(void *this,undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b170;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = *(undefined4 **)((int)this + 4);
  if (*(char *)((int)param_1 + 0x45) == '\0') {
    puVar1 = FUN_10014a10(this,(char *)(param_1 + 3));
    puVar1[1] = param_2;
    *(undefined1 *)(puVar1 + 0x11) = *(undefined1 *)(param_1 + 0x11);
    if (*(char *)((int)local_18 + 0x45) != '\0') {
      local_18 = puVar1;
    }
    local_8 = 0;
    puVar2 = FUN_10014cd0(this,(undefined4 *)*param_1,puVar1);
    *puVar1 = puVar2;
    puVar2 = FUN_10014cd0(this,(undefined4 *)param_1[2],puVar1);
    puVar1[2] = puVar2;
  }
  ExceptionList = local_10;
  return local_18;
}



// Function: Catch_All@10014d6e at 10014d6e

void Catch_All_10014d6e(void)

{
  int unaff_EBP;
  
  FUN_10014480(*(int **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10014d90 at 10014d90

void __thiscall FUN_10014d90(void *this,int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  
  iVar2 = *(int *)((int)this + 4);
  puVar7 = FUN_10014cd0(this,*(undefined4 **)(*(int *)(param_1 + 4) + 4),iVar2);
  *(undefined4 **)(iVar2 + 4) = puVar7;
  piVar3 = *(int **)((int)this + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  piVar4 = (int *)piVar3[1];
  if (*(char *)((int)piVar4 + 0x45) != '\0') {
    *piVar3 = (int)piVar3;
    *(int *)(*(int *)((int)this + 4) + 8) = *(int *)((int)this + 4);
    return;
  }
  cVar1 = *(char *)(*piVar4 + 0x45);
  piVar6 = (int *)*piVar4;
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*piVar6 + 0x45);
    piVar4 = piVar6;
    piVar6 = (int *)*piVar6;
  }
  *piVar3 = (int)piVar4;
  iVar2 = *(int *)(*(int *)((int)this + 4) + 4);
  iVar5 = *(int *)(iVar2 + 8);
  cVar1 = *(char *)(iVar5 + 0x45);
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*(int *)(iVar5 + 8) + 0x45);
    iVar2 = iVar5;
    iVar5 = *(int *)(iVar5 + 8);
  }
  *(int *)(*(int *)((int)this + 4) + 8) = iVar2;
  return;
}



// Function: FUN_10014e10 at 10014e10

undefined4 * __thiscall FUN_10014e10(void *this,char *param_1)

{
  undefined4 *puVar1;
  uint uStack_3c;
  undefined **local_2c [3];
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b1a9;
  local_10 = ExceptionList;
  uStack_3c = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_3c;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)operator_new(0x48);
  local_18 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *(undefined4 *)((int)this + 4);
    puVar1[1] = *(undefined4 *)((int)this + 4);
    local_20 = puVar1 + 3;
    puVar1[2] = *(undefined4 *)((int)this + 4);
    *(undefined2 *)(puVar1 + 0x11) = 0;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    if (local_20 != (undefined4 *)0x0) {
      puVar1[8] = 0xf;
      puVar1[7] = 0;
      *(undefined1 *)local_20 = 0;
      local_1c = local_20;
      FUN_10001f4b(local_20,(undefined4 *)param_1,0,0xffffffff);
      puVar1[0xf] = 0xf;
      puVar1[0xe] = 0;
      local_8 = CONCAT31(local_8._1_3_,2);
      *(undefined1 *)(puVar1 + 10) = 0;
      FUN_10002118(puVar1 + 10,
                   (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   (param_1 + 0x1c));
    }
    ExceptionList = local_10;
    return puVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_2c,&param_1);
  local_2c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_2c,(ThrowInfo *)&DAT_10020dd4);
}



// Function: Catch_All@10014ece at 10014ece

void Catch_All_10014ece(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10014f10 at 10014f10

void __fastcall FUN_10014f10(void *param_1)

{
  undefined4 local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b1d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = param_1;
  FUN_10014950(param_1,&local_18,(int *)**(int **)((int)param_1 + 4),*(int **)((int)param_1 + 4));
  operator_delete(*(void **)((int)param_1 + 4));
  ExceptionList = local_10;
  return;
}



// Function: FUN_10014f70 at 10014f70

void __fastcall FUN_10014f70(void *param_1)

{
  undefined4 local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b210;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = param_1;
  FUN_10014480(*(int **)(*(int *)((int)param_1 + 4) + 4));
  *(int *)(*(int *)((int)param_1 + 4) + 4) = *(int *)((int)param_1 + 4);
  *(undefined4 *)*(undefined4 *)((int)param_1 + 4) = *(undefined4 *)((int)param_1 + 4);
  *(int *)(*(int *)((int)param_1 + 4) + 8) = *(int *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 8) = 0;
  local_8 = 1;
  FUN_10014950(param_1,&local_18,(int *)**(int **)((int)param_1 + 4),*(int **)((int)param_1 + 4));
  operator_delete(*(void **)((int)param_1 + 4));
  ExceptionList = local_10;
  return;
}



// Function: FUN_10015000 at 10015000

void __thiscall FUN_10015000(void *this,undefined4 *param_1)

{
  uint uVar1;
  int *piVar2;
  int *local_6c;
  void *local_68 [4];
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
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b248;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_6c = FUN_1000e070(this,param_1);
  if (local_6c != *(int **)((int)this + 4)) {
    piVar2 = local_6c + 3;
    if (0xf < (uint)local_6c[8]) {
      piVar2 = (int *)*piVar2;
    }
    uVar1 = FUN_1000b470(param_1,0,param_1[4],piVar2,local_6c[7]);
    if (-1 < (int)uVar1) goto LAB_10015111;
  }
  local_54 = 0xf;
  local_58 = 0;
  local_68[0] = (void *)((uint)local_68[0] & 0xffffff00);
  local_8 = 0;
  local_38 = 0xf;
  local_3c = 0;
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffffff00);
  FUN_10001f4b(local_4c,param_1,0,0xffffffff);
  local_8._0_1_ = 1;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
  FUN_10002118(local_30,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                         *)local_68);
  local_8 = CONCAT31(local_8._1_3_,2);
  piVar2 = FUN_10014e10(this,(char *)local_4c);
  FUN_10014b10(this,&local_6c,local_6c,piVar2);
  if (0xf < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
  if (0xf < local_38) {
    operator_delete(local_4c[0]);
  }
  local_38 = 0xf;
  local_3c = 0;
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffffff00);
  if (0xf < local_54) {
    operator_delete(local_68[0]);
  }
LAB_10015111:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10015140 at 10015140

void __fastcall FUN_10015140(undefined4 *param_1)

{
  undefined4 local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b28b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = SharedConfigurationLibrary_Internal::ConfigEntry::vftable;
  local_8 = 0;
  local_14 = param_1;
  FUN_10014480(*(int **)(param_1[2] + 4));
  *(undefined4 *)(param_1[2] + 4) = param_1[2];
  *(undefined4 *)param_1[2] = param_1[2];
  *(undefined4 *)(param_1[2] + 8) = param_1[2];
  param_1[3] = 0;
  local_8 = 1;
  local_14 = param_1 + 1;
  FUN_10014480(*(int **)(param_1[2] + 4));
  *(undefined4 *)(param_1[2] + 4) = param_1[2];
  *(undefined4 *)param_1[2] = param_1[2];
  *(undefined4 *)(param_1[2] + 8) = param_1[2];
  param_1[3] = 0;
  local_8 = 2;
  FUN_10014950(param_1 + 1,&local_18,*(int **)param_1[2],(int *)param_1[2]);
  operator_delete((void *)param_1[2]);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10015210 at 10015210

void __thiscall FUN_10015210(void *this,void *param_1)

{
  void *this_00;
  undefined4 uStack00000014;
  uint in_stack_00000018;
  void *in_stack_00000020;
  uint in_stack_00000034;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b2c0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  this_00 = (void *)FUN_10015000(this,&param_1);
  FUN_10001f4b(this_00,&stack0x00000020,0,0xffffffff);
  if (0xf < in_stack_00000018) {
    operator_delete(param_1);
  }
  in_stack_00000018 = 0xf;
  uStack00000014 = 0;
  param_1 = (void *)((uint)param_1 & 0xffffff00);
  if (0xf < in_stack_00000034) {
    operator_delete(in_stack_00000020);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100152a0 at 100152a0

void __thiscall FUN_100152a0(void *this,void *param_1)

{
  char cVar1;
  void *pvVar2;
  char *pcVar3;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar4;
  void *pvVar5;
  char *pcVar6;
  undefined4 uStack00000014;
  uint in_stack_00000018;
  void *in_stack_00000020;
  undefined4 uStack00000030;
  uint in_stack_00000034;
  undefined4 in_stack_0000003c;
  void *in_stack_00000040;
  undefined4 uStack00000050;
  uint in_stack_00000054;
  void *in_stack_0000005c;
  uint in_stack_00000070;
  undefined **local_84 [3];
  void *local_78;
  char *local_74;
  char *local_70;
  void *local_6c [4];
  undefined4 local_5c;
  uint local_58;
  void *local_50 [4];
  undefined4 local_40;
  uint local_3c;
  char *local_34;
  void *local_30 [5];
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b3a3;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_34 = (char *)in_stack_0000003c;
  *(undefined ***)this = SharedConfigurationLibrary_Internal::ConfigEntry::vftable;
  pvVar5 = (void *)((int)this + 4);
  local_8 = 3;
  *(undefined4 *)((int)this + 0xc) = 0;
  local_78 = this;
  pvVar2 = operator_new(0x48);
  if (pvVar2 != (void *)0x0) {
    *(void **)((int)this + 8) = pvVar2;
    *(void **)pvVar2 = pvVar2;
    *(int *)(*(int *)((int)this + 8) + 4) = *(int *)((int)this + 8);
    *(int *)(*(int *)((int)this + 8) + 8) = *(int *)((int)this + 8);
    *(undefined1 *)(*(int *)((int)this + 8) + 0x44) = 1;
    *(undefined1 *)(*(int *)((int)this + 8) + 0x45) = 1;
    local_8._0_1_ = 4;
    *(undefined2 *)((int)this + 0x14) = 0x100;
    pcVar3 = (char *)FUN_1000b4e0(&param_1);
    local_70 = pcVar3 + 1;
    local_58 = 0xf;
    local_5c = 0;
    local_6c[0] = (void *)((uint)local_6c[0] & 0xffffff00);
    pcVar6 = pcVar3;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_6c,pcVar3,(int)pcVar6 - (int)local_70);
    local_8._0_1_ = 5;
    local_3c = 0xf;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffffff00);
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_50,"name",4);
    local_8 = CONCAT31(local_8._1_3_,7);
    pvVar2 = (void *)FUN_10015000(pvVar5,local_50);
    FUN_10001f4b(pvVar2,local_6c,0,0xffffffff);
    if (0xf < local_3c) {
      operator_delete(local_50[0]);
    }
    local_3c = 0xf;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffffff00);
    local_8._0_1_ = 4;
    if (0xf < local_58) {
      operator_delete(local_6c[0]);
    }
    pcVar3 = (char *)FUN_1000b4e0(&stack0x00000020);
    local_70 = pcVar3 + 1;
    local_58 = 0xf;
    local_5c = 0;
    local_6c[0] = (void *)((uint)local_6c[0] & 0xffffff00);
    pcVar6 = pcVar3;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_6c,pcVar3,(int)pcVar6 - (int)local_70);
    local_8._0_1_ = 8;
    local_3c = 0xf;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffffff00);
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_50,"value",5);
    local_8 = CONCAT31(local_8._1_3_,10);
    pvVar2 = (void *)FUN_10015000(pvVar5,local_50);
    FUN_10001f4b(pvVar2,local_6c,0,0xffffffff);
    if (0xf < local_3c) {
      operator_delete(local_50[0]);
    }
    local_3c = 0xf;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffffff00);
    local_8._0_1_ = 4;
    if (0xf < local_58) {
      operator_delete(local_6c[0]);
    }
    pcVar3 = (char *)FUN_1000b4e0(&stack0x00000020);
    local_70 = pcVar3 + 1;
    local_58 = 0xf;
    local_5c = 0;
    local_6c[0] = (void *)((uint)local_6c[0] & 0xffffff00);
    pcVar6 = pcVar3;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_6c,pcVar3,(int)pcVar6 - (int)local_70);
    local_8._0_1_ = 0xb;
    local_3c = 0xf;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffffff00);
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_50,"def_val",7);
    local_8 = CONCAT31(local_8._1_3_,0xd);
    pvVar2 = (void *)FUN_10015000(pvVar5,local_50);
    FUN_10001f4b(pvVar2,local_6c,0,0xffffffff);
    if (0xf < local_3c) {
      operator_delete(local_50[0]);
    }
    local_3c = 0xf;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffffff00);
    local_8._0_1_ = 4;
    if (0xf < local_58) {
      operator_delete(local_6c[0]);
    }
    pbVar4 = FUN_10013670((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                           *)local_30,local_34);
    local_8._0_1_ = 0xe;
    pcVar3 = (char *)FUN_1000b4e0((undefined4 *)pbVar4);
    local_34 = pcVar3 + 1;
    local_58 = 0xf;
    local_5c = 0;
    local_6c[0] = (void *)((uint)local_6c[0] & 0xffffff00);
    pcVar6 = pcVar3;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_6c,pcVar3,(int)pcVar6 - (int)local_34);
    local_8._0_1_ = 0xf;
    local_3c = 0xf;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffffff00);
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_50,"val_type",8);
    local_8 = CONCAT31(local_8._1_3_,0x11);
    pvVar2 = (void *)FUN_10015000(pvVar5,local_50);
    FUN_10001f4b(pvVar2,local_6c,0,0xffffffff);
    if (0xf < local_3c) {
      operator_delete(local_50[0]);
    }
    local_3c = 0xf;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffffff00);
    if (0xf < local_58) {
      operator_delete(local_6c[0]);
    }
    local_58 = 0xf;
    local_5c = 0;
    local_6c[0] = (void *)((uint)local_6c[0] & 0xffffff00);
    local_8._0_1_ = 4;
    if (0xf < local_1c) {
      operator_delete(local_30[0]);
    }
    pcVar3 = (char *)FUN_1000b4e0(&stack0x00000040);
    local_34 = pcVar3 + 1;
    local_3c = 0xf;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffffff00);
    pcVar6 = pcVar3;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_50,pcVar3,(int)pcVar6 - (int)local_34);
    local_8._0_1_ = 0x12;
    local_58 = 0xf;
    local_5c = 0;
    local_6c[0] = (void *)((uint)local_6c[0] & 0xffffff00);
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_6c,"range_min",9);
    local_8 = CONCAT31(local_8._1_3_,0x14);
    pvVar2 = (void *)FUN_10015000(pvVar5,local_6c);
    FUN_10001f4b(pvVar2,local_50,0,0xffffffff);
    if (0xf < local_58) {
      operator_delete(local_6c[0]);
    }
    local_58 = 0xf;
    local_5c = 0;
    local_6c[0] = (void *)((uint)local_6c[0] & 0xffffff00);
    local_8._0_1_ = 4;
    if (0xf < local_3c) {
      operator_delete(local_50[0]);
    }
    pcVar3 = (char *)FUN_1000b4e0(&stack0x0000005c);
    local_34 = pcVar3 + 1;
    local_3c = 0xf;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffffff00);
    pcVar6 = pcVar3;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_50,pcVar3,(int)pcVar6 - (int)local_34);
    local_8._0_1_ = 0x15;
    local_58 = 0xf;
    local_5c = 0;
    local_6c[0] = (void *)((uint)local_6c[0] & 0xffffff00);
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_6c,"range_max",9);
    local_8 = CONCAT31(local_8._1_3_,0x17);
    pvVar5 = (void *)FUN_10015000(pvVar5,local_6c);
    FUN_10001f4b(pvVar5,local_50,0,0xffffffff);
    if (0xf < local_58) {
      operator_delete(local_6c[0]);
    }
    local_58 = 0xf;
    local_5c = 0;
    local_6c[0] = (void *)((uint)local_6c[0] & 0xffffff00);
    if (0xf < local_3c) {
      operator_delete(local_50[0]);
    }
    if (0xf < in_stack_00000018) {
      operator_delete(param_1);
    }
    in_stack_00000018 = 0xf;
    uStack00000014 = 0;
    param_1 = (void *)((uint)param_1 & 0xffffff00);
    if (0xf < in_stack_00000034) {
      operator_delete(in_stack_00000020);
    }
    in_stack_00000034 = 0xf;
    uStack00000030 = 0;
    in_stack_00000020 = (void *)((uint)in_stack_00000020 & 0xffffff00);
    if (0xf < in_stack_00000054) {
      operator_delete(in_stack_00000040);
    }
    in_stack_00000054 = 0xf;
    uStack00000050 = 0;
    in_stack_00000040 = (void *)((uint)in_stack_00000040 & 0xffffff00);
    if (0xf < in_stack_00000070) {
      operator_delete(in_stack_0000005c);
    }
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_74 = (char *)0x0;
  std::exception::exception((exception *)local_84,&local_74);
  local_84[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_84,(ThrowInfo *)&DAT_10020dd4);
}



// Function: FUN_100157a0 at 100157a0

undefined4 * __thiscall FUN_100157a0(void *this,byte param_1)

{
  FUN_10015140((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100157d0 at 100157d0

void __thiscall FUN_100157d0(void *this,void *param_1)

{
  char cVar1;
  void *pvVar2;
  char *pcVar3;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar4;
  char *pcVar5;
  void *this_00;
  undefined4 uStack00000014;
  uint in_stack_00000018;
  void *in_stack_00000020;
  uint in_stack_00000034;
  undefined4 in_stack_0000003c;
  undefined **local_84 [3];
  char *local_78;
  void *local_74;
  char *local_70;
  void *local_6c [4];
  undefined4 local_5c;
  uint local_58;
  void *local_50 [4];
  undefined4 local_40;
  uint local_3c;
  char *local_34;
  void *local_30 [5];
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b483;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_34 = (char *)in_stack_0000003c;
  *(undefined ***)this = SharedConfigurationLibrary_Internal::ConfigEntry::vftable;
  this_00 = (void *)((int)this + 4);
  local_8 = 1;
  *(undefined4 *)((int)this + 0xc) = 0;
  local_74 = this;
  pvVar2 = operator_new(0x48);
  if (pvVar2 != (void *)0x0) {
    *(void **)((int)this + 8) = pvVar2;
    *(void **)pvVar2 = pvVar2;
    *(int *)(*(int *)((int)this + 8) + 4) = *(int *)((int)this + 8);
    *(int *)(*(int *)((int)this + 8) + 8) = *(int *)((int)this + 8);
    *(undefined1 *)(*(int *)((int)this + 8) + 0x44) = 1;
    *(undefined1 *)(*(int *)((int)this + 8) + 0x45) = 1;
    local_8._0_1_ = 2;
    pcVar3 = (char *)FUN_1000b4e0(&param_1);
    local_70 = pcVar3 + 1;
    local_58 = 0xf;
    local_5c = 0;
    local_6c[0] = (void *)((uint)local_6c[0] & 0xffffff00);
    pcVar5 = pcVar3;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_6c,pcVar3,(int)pcVar5 - (int)local_70);
    local_8._0_1_ = 3;
    local_3c = 0xf;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffffff00);
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_50,"name",4);
    local_8 = CONCAT31(local_8._1_3_,5);
    pvVar2 = (void *)FUN_10015000(this_00,local_50);
    FUN_10001f4b(pvVar2,local_6c,0,0xffffffff);
    if (0xf < local_3c) {
      operator_delete(local_50[0]);
    }
    local_3c = 0xf;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffffff00);
    local_8._0_1_ = 2;
    if (0xf < local_58) {
      operator_delete(local_6c[0]);
    }
    pcVar3 = (char *)FUN_1000b4e0(&stack0x00000020);
    local_70 = pcVar3 + 1;
    local_58 = 0xf;
    local_5c = 0;
    local_6c[0] = (void *)((uint)local_6c[0] & 0xffffff00);
    pcVar5 = pcVar3;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_6c,pcVar3,(int)pcVar5 - (int)local_70);
    local_8._0_1_ = 6;
    local_3c = 0xf;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffffff00);
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_50,"value",5);
    local_8 = CONCAT31(local_8._1_3_,8);
    pvVar2 = (void *)FUN_10015000(this_00,local_50);
    FUN_10001f4b(pvVar2,local_6c,0,0xffffffff);
    if (0xf < local_3c) {
      operator_delete(local_50[0]);
    }
    local_3c = 0xf;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffffff00);
    local_8._0_1_ = 2;
    if (0xf < local_58) {
      operator_delete(local_6c[0]);
    }
    pcVar3 = (char *)FUN_1000b4e0(&stack0x00000020);
    local_70 = pcVar3 + 1;
    local_58 = 0xf;
    local_5c = 0;
    local_6c[0] = (void *)((uint)local_6c[0] & 0xffffff00);
    pcVar5 = pcVar3;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_6c,pcVar3,(int)pcVar5 - (int)local_70);
    local_8._0_1_ = 9;
    local_3c = 0xf;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffffff00);
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_50,"def_val",7);
    local_8 = CONCAT31(local_8._1_3_,0xb);
    pvVar2 = (void *)FUN_10015000(this_00,local_50);
    FUN_10001f4b(pvVar2,local_6c,0,0xffffffff);
    if (0xf < local_3c) {
      operator_delete(local_50[0]);
    }
    local_3c = 0xf;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffffff00);
    local_8._0_1_ = 2;
    if (0xf < local_58) {
      operator_delete(local_6c[0]);
    }
    pbVar4 = FUN_10013670((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                           *)local_30,local_34);
    local_8._0_1_ = 0xc;
    pcVar3 = (char *)FUN_1000b4e0((undefined4 *)pbVar4);
    local_34 = pcVar3 + 1;
    local_58 = 0xf;
    local_5c = 0;
    local_6c[0] = (void *)((uint)local_6c[0] & 0xffffff00);
    pcVar5 = pcVar3;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_6c,pcVar3,(int)pcVar5 - (int)local_34);
    local_8._0_1_ = 0xd;
    local_3c = 0xf;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffffff00);
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_50,"val_type",8);
    local_8 = CONCAT31(local_8._1_3_,0xf);
    pvVar2 = (void *)FUN_10015000(this_00,local_50);
    FUN_10001f4b(pvVar2,local_6c,0,0xffffffff);
    if (0xf < local_3c) {
      operator_delete(local_50[0]);
    }
    local_3c = 0xf;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffffff00);
    if (0xf < local_58) {
      operator_delete(local_6c[0]);
    }
    local_58 = 0xf;
    local_5c = 0;
    local_6c[0] = (void *)((uint)local_6c[0] & 0xffffff00);
    local_8._0_1_ = 2;
    if (0xf < local_1c) {
      operator_delete(local_30[0]);
    }
    pcVar3 = (char *)FUN_1000b4e0(&stack0x00000020);
    local_34 = pcVar3 + 1;
    local_3c = 0xf;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffffff00);
    pcVar5 = pcVar3;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_50,pcVar3,(int)pcVar5 - (int)local_34);
    local_8._0_1_ = 0x10;
    local_58 = 0xf;
    local_5c = 0;
    local_6c[0] = (void *)((uint)local_6c[0] & 0xffffff00);
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_6c,"range_min",9);
    local_8 = CONCAT31(local_8._1_3_,0x12);
    pvVar2 = (void *)FUN_10015000(this_00,local_6c);
    FUN_10001f4b(pvVar2,local_50,0,0xffffffff);
    if (0xf < local_58) {
      operator_delete(local_6c[0]);
    }
    local_58 = 0xf;
    local_5c = 0;
    local_6c[0] = (void *)((uint)local_6c[0] & 0xffffff00);
    local_8._0_1_ = 2;
    if (0xf < local_3c) {
      operator_delete(local_50[0]);
    }
    pcVar3 = (char *)FUN_1000b4e0(&stack0x00000020);
    local_34 = pcVar3 + 1;
    local_3c = 0xf;
    local_40 = 0;
    local_50[0] = (void *)((uint)local_50[0] & 0xffffff00);
    pcVar5 = pcVar3;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_50,pcVar3,(int)pcVar5 - (int)local_34);
    local_8._0_1_ = 0x13;
    local_58 = 0xf;
    local_5c = 0;
    local_6c[0] = (void *)((uint)local_6c[0] & 0xffffff00);
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_6c,"range_max",9);
    local_8 = CONCAT31(local_8._1_3_,0x15);
    pvVar2 = (void *)FUN_10015000(this_00,local_6c);
    FUN_10001f4b(pvVar2,local_50,0,0xffffffff);
    if (0xf < local_58) {
      operator_delete(local_6c[0]);
    }
    local_58 = 0xf;
    local_5c = 0;
    local_6c[0] = (void *)((uint)local_6c[0] & 0xffffff00);
    if (0xf < local_3c) {
      operator_delete(local_50[0]);
    }
    *(undefined2 *)((int)local_74 + 0x14) = 0x100;
    if (0xf < in_stack_00000018) {
      operator_delete(param_1);
    }
    in_stack_00000018 = 0xf;
    uStack00000014 = 0;
    param_1 = (void *)((uint)param_1 & 0xffffff00);
    if (0xf < in_stack_00000034) {
      operator_delete(in_stack_00000020);
    }
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_78 = (char *)0x0;
  std::exception::exception((exception *)local_84,&local_78);
  local_84[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_84,(ThrowInfo *)&DAT_10020dd4);
}



// Function: FUN_10015ca0 at 10015ca0

undefined4 * __thiscall FUN_10015ca0(void *this,int param_1)

{
  void *this_00;
  void *pvVar1;
  undefined **local_28 [3];
  undefined4 local_1c;
  void *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b4bb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = SharedConfigurationLibrary_Internal::ConfigEntry::vftable;
  this_00 = (void *)((int)this + 4);
  *(undefined4 *)((int)this + 0xc) = 0;
  local_18 = this;
  pvVar1 = operator_new(0x48);
  if (pvVar1 != (void *)0x0) {
    *(void **)((int)this + 8) = pvVar1;
    *(void **)pvVar1 = pvVar1;
    *(int *)(*(int *)((int)this + 8) + 4) = *(int *)((int)this + 8);
    *(int *)(*(int *)((int)this + 8) + 8) = *(int *)((int)this + 8);
    *(undefined1 *)(*(int *)((int)this + 8) + 0x44) = 1;
    *(undefined1 *)(*(int *)((int)this + 8) + 0x45) = 1;
    local_8 = 0;
    if ((void *)(param_1 + 4) != this_00) {
      FUN_10014950(this_00,&local_1c,(int *)**(int **)((int)this + 8),*(int **)((int)this + 8));
      FUN_10014d90(this_00,param_1 + 4);
    }
    *(undefined1 *)((int)this + 0x14) = *(undefined1 *)(param_1 + 0x14);
    *(undefined1 *)((int)this + 0x15) = *(undefined1 *)(param_1 + 0x15);
    ExceptionList = local_10;
    return (undefined4 *)this;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_28,&local_14);
  local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_10020dd4);
}



// Function: FUN_10015d80 at 10015d80

void __thiscall FUN_10015d80(void *this,int param_1,float param_2,void *param_3)

{
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> bVar1;
  byte bVar2;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar3;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar4;
  byte *pbVar5;
  int iVar6;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar7;
  char *pcVar8;
  float fVar9;
  byte ****ppppbVar10;
  bool bVar11;
  double dVar12;
  uint in_stack_00000020;
  void *in_stack_fffffe4c;
  void *pvVar13;
  uint in_stack_fffffe68;
  undefined4 *puVar14;
  char **ppcVar15;
  char *local_168;
  undefined1 *local_164;
  undefined1 *local_160;
  void *local_15c;
  void *local_158 [4];
  undefined4 local_148;
  uint local_144;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_13c [28];
  void *local_120 [4];
  undefined4 local_110;
  uint local_10c;
  void *local_104 [4];
  undefined4 local_f4;
  uint local_f0;
  void *local_e8 [4];
  undefined4 local_d8;
  uint local_d4;
  void *local_cc [4];
  undefined4 local_bc;
  uint local_b8;
  byte ***local_b0 [4];
  undefined4 local_a0;
  uint local_9c;
  char local_94;
  undefined1 local_93 [127];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b598;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_160 = &stack0xfffffe68;
  local_8 = 0;
  puVar14 = (undefined4 *)(in_stack_fffffe68 & 0xffffff00);
  local_15c = this;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xfffffe68,"val_type",8);
  pbVar3 = FUN_1000e280((void *)((int)this + 4),
                        (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                         *)local_cc,puVar14);
  local_8._0_1_ = 1;
  if (0xf < *(uint *)(pbVar3 + 0x14)) {
    pbVar3 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
              pbVar3;
  }
  local_9c = 0xf;
  local_a0 = 0;
  local_b0[0] = (byte ***)((uint)local_b0[0] & 0xffffff00);
  pbVar4 = pbVar3;
  do {
    bVar1 = *pbVar4;
    pbVar4 = pbVar4 + 1;
  } while (bVar1 != (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)
                    0x0);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_b0,(char *)pbVar3,(int)pbVar4 - (int)(pbVar3 + 1));
  local_8._0_1_ = 3;
  if (0xf < local_b8) {
    operator_delete(local_cc[0]);
  }
  local_b8 = 0xf;
  local_bc = 0;
  local_cc[0] = (void *)((uint)local_cc[0] & 0xffffff00);
  FUN_10013670((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_104,param_1);
  local_8._0_1_ = 4;
  ppppbVar10 = (byte ****)local_b0[0];
  if (local_9c < 0x10) {
    ppppbVar10 = local_b0;
  }
  pbVar5 = (byte *)FUN_1000b4e0(local_104);
  do {
    bVar2 = *(byte *)ppppbVar10;
    bVar11 = bVar2 < *pbVar5;
    if (bVar2 != *pbVar5) {
LAB_10015eb7:
      iVar6 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
      goto LAB_10015ebc;
    }
    if (bVar2 == 0) break;
    bVar2 = *(byte *)((int)ppppbVar10 + 1);
    bVar11 = bVar2 < pbVar5[1];
    if (bVar2 != pbVar5[1]) goto LAB_10015eb7;
    ppppbVar10 = (byte ****)((int)ppppbVar10 + 2);
    pbVar5 = pbVar5 + 2;
  } while (bVar2 != 0);
  iVar6 = 0;
LAB_10015ebc:
  if (iVar6 != 0) {
    if (0xf < local_f0) {
      operator_delete(local_104[0]);
    }
    local_f0 = 0xf;
    local_f4 = 0;
    local_104[0] = (void *)((uint)local_104[0] & 0xffffff00);
    if (0xf < local_9c) {
      operator_delete(local_b0[0]);
    }
    local_9c = 0xf;
    local_a0 = 0;
    local_b0[0] = (byte ***)((uint)local_b0[0] & 0xffffff00);
    if (0xf < in_stack_00000020) {
      operator_delete(param_3);
    }
    goto LAB_100166a0;
  }
  local_160 = &stack0xfffffe68;
  puVar14 = (undefined4 *)((uint)puVar14 & 0xffffff00);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xfffffe68,"range_min",9);
  pbVar3 = FUN_1000e280((void *)((int)local_15c + 4),
                        (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                         *)local_cc,puVar14);
  local_8._0_1_ = 5;
  if (0xf < *(uint *)(pbVar3 + 0x14)) {
    pbVar3 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
              pbVar3;
  }
  local_d4 = 0xf;
  local_d8 = 0;
  local_e8[0] = (void *)((uint)local_e8[0] & 0xffffff00);
  pbVar4 = pbVar3;
  do {
    bVar1 = *pbVar4;
    pbVar4 = pbVar4 + 1;
  } while (bVar1 != (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)
                    0x0);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_e8,(char *)pbVar3,(int)pbVar4 - (int)(pbVar3 + 1));
  local_8._0_1_ = 7;
  if (0xf < local_b8) {
    operator_delete(local_cc[0]);
  }
  local_160 = &stack0xfffffe68;
  local_b8 = 0xf;
  local_bc = 0;
  local_cc[0] = (void *)((uint)local_cc[0] & 0xffffff00);
  puVar14 = (undefined4 *)((uint)puVar14 & 0xffffff00);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xfffffe68,"range_max",9);
  pbVar3 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)local_158
  ;
  pbVar4 = FUN_1000e280((void *)((int)local_15c + 4),pbVar3,puVar14);
  local_8._0_1_ = 8;
  if (0xf < *(uint *)(pbVar4 + 0x14)) {
    pbVar4 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
              pbVar4;
  }
  local_10c = 0xf;
  local_110 = 0;
  local_120[0] = (void *)((uint)local_120[0] & 0xffffff00);
  pbVar7 = pbVar4;
  do {
    bVar1 = *pbVar7;
    pbVar7 = pbVar7 + 1;
  } while (bVar1 != (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)
                    0x0);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_120,(char *)pbVar4,(int)pbVar7 - (int)(pbVar4 + 1));
  local_8._0_1_ = 10;
  if (0xf < local_144) {
    operator_delete(local_158[0]);
  }
  local_144 = 0xf;
  local_148 = 0;
  local_158[0] = (void *)((uint)local_158[0] & 0xffffff00);
  if ((param_1 == 1) || (param_1 == 2)) {
    local_160 = &stack0xfffffe64;
    local_168 = (char *)0x0;
    local_164 = (undefined1 *)0x0;
    pvVar13 = (void *)((uint)pbVar3 & 0xffffff00);
    FUN_10001f4b(&stack0xfffffe64,local_e8,0,0xffffffff);
    FUN_10016e20(pvVar13);
    local_160 = &stack0xfffffe64;
    pvVar13 = (void *)((uint)pvVar13 & 0xffffff00);
    FUN_10001f4b(&stack0xfffffe64,local_120,0,0xffffffff);
    FUN_10016e20(pvVar13);
    fVar9 = param_2;
    if (param_1 != 1) {
      fVar9 = (float)((uint)param_2 & 0xff);
    }
    if (((int)fVar9 < (int)local_168) || ((int)local_164 < (int)fVar9)) {
      if (0xf < local_10c) {
        operator_delete(local_120[0]);
      }
      local_10c = 0xf;
      local_110 = 0;
      local_120[0] = (void *)((uint)local_120[0] & 0xffffff00);
      if (0xf < local_d4) {
        operator_delete(local_e8[0]);
      }
      local_d4 = 0xf;
      local_d8 = 0;
      local_e8[0] = (void *)((uint)local_e8[0] & 0xffffff00);
      if (0xf < local_f0) {
        operator_delete(local_104[0]);
      }
      local_f0 = 0xf;
      local_f4 = 0;
      local_104[0] = (void *)((uint)local_104[0] & 0xffffff00);
      if (0xf < local_9c) {
        operator_delete(local_b0[0]);
      }
      local_9c = 0xf;
      local_a0 = 0;
      local_b0[0] = (byte ***)((uint)local_b0[0] & 0xffffff00);
      if (0xf < in_stack_00000020) {
        operator_delete(param_3);
      }
    }
    else {
      FUN_10016f60((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_cc,(int)fVar9,(int)fVar9 >> 0x1f);
      local_8._0_1_ = 0xb;
      pcVar8 = (char *)FUN_1000b4e0(local_cc);
      local_160 = &stack0xfffffe68;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &stack0xfffffe68,pcVar8);
      local_8._0_1_ = 0xc;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &stack0xfffffe4c,"value");
      local_8._0_1_ = 0xb;
      FUN_10015210((void *)((int)local_15c + 4),in_stack_fffffe4c);
      *(undefined2 *)((int)local_15c + 0x14) = 1;
      if (0xf < local_b8) {
        operator_delete(local_cc[0]);
      }
      local_b8 = 0xf;
      local_bc = 0;
      local_cc[0] = (void *)((uint)local_cc[0] & 0xffffff00);
      if (0xf < local_10c) {
        operator_delete(local_120[0]);
      }
      local_10c = 0xf;
      local_110 = 0;
      local_120[0] = (void *)((uint)local_120[0] & 0xffffff00);
      if (0xf < local_d4) {
        operator_delete(local_e8[0]);
      }
      local_d4 = 0xf;
      local_d8 = 0;
      local_e8[0] = (void *)((uint)local_e8[0] & 0xffffff00);
      if (0xf < local_f0) {
        operator_delete(local_104[0]);
      }
      local_f0 = 0xf;
      local_f4 = 0;
      local_104[0] = (void *)((uint)local_104[0] & 0xffffff00);
      if (0xf < local_9c) {
        operator_delete(local_b0[0]);
      }
      local_9c = 0xf;
      local_a0 = 0;
      local_b0[0] = (byte ***)((uint)local_b0[0] & 0xffffff00);
      if (0xf < in_stack_00000020) {
        operator_delete(param_3);
      }
    }
    goto LAB_100166a0;
  }
  if (param_1 == 4) {
    ppcVar15 = &local_168;
    local_168 = (char *)0x0;
    pcVar8 = (char *)FUN_1000b4e0(local_e8);
    dVar12 = strtod(pcVar8,ppcVar15);
    local_164 = (undefined1 *)(float)dVar12;
    ppcVar15 = &local_168;
    pcVar8 = (char *)FUN_1000b4e0(local_120);
    dVar12 = strtod(pcVar8,ppcVar15);
    local_160 = (undefined1 *)(float)dVar12;
    if (((float)local_164 < param_2 != ((float)local_164 == param_2)) &&
       (param_2 <= (float)local_160)) {
      local_94 = '\0';
      memset(local_93,0,0x7f);
      sprintf_s(&local_94,0x80,"%f");
      FUN_10006c43(local_13c,&local_94);
      local_8._0_1_ = 0xd;
      pcVar8 = (char *)FUN_1000b4e0((undefined4 *)local_13c);
      local_160 = &stack0xfffffe68;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &stack0xfffffe68,pcVar8);
      local_164 = &stack0xfffffe4c;
      local_8._0_1_ = 0xe;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &stack0xfffffe4c,"value");
      local_8._0_1_ = 0xd;
      FUN_10015210((void *)((int)local_15c + 4),in_stack_fffffe4c);
      *(undefined2 *)((int)local_15c + 0x14) = 1;
      pbVar3 = local_13c;
LAB_100161c0:
      FUN_100060fa(pbVar3);
      FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_120);
      FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_e8);
      FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_104);
      FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_b0);
      FUN_100074ce((int)&param_1);
      goto LAB_100166a0;
    }
  }
  else {
    if (param_1 == 3) {
      FUN_10007753(local_13c,
                   (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &param_3);
      local_8._0_1_ = 0xf;
      pcVar8 = (char *)FUN_1000b4e0((undefined4 *)local_13c);
      local_160 = &stack0xfffffe68;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &stack0xfffffe68,pcVar8);
      local_164 = &stack0xfffffe4c;
      local_8._0_1_ = 0x10;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &stack0xfffffe4c,"value");
      local_8._0_1_ = 0xf;
      FUN_10015210((void *)((int)local_15c + 4),in_stack_fffffe4c);
      *(undefined2 *)((int)local_15c + 0x14) = 1;
      FUN_100060fa(local_13c);
      FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_120);
      FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_e8);
      FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_104);
      FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_b0);
      FUN_100074ce((int)&param_1);
      goto LAB_100166a0;
    }
    if (param_1 != 5) {
      FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_120);
      FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_e8);
      FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_104);
      FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_b0);
      FUN_100074ce((int)&param_1);
      goto LAB_100166a0;
    }
    FUN_10007753(local_cc,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                           *)&param_3);
    local_8._0_1_ = 0x11;
    pcVar8 = (char *)FUN_1000b4e0(local_e8);
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_13c,pcVar8);
    local_8._0_1_ = 0x12;
    pvVar13 = (void *)0x0;
    pcVar8 = (char *)FUN_1000b4e0(local_cc);
    iVar6 = FUN_100071a2(local_13c,pcVar8,pvVar13);
    if (iVar6 != -1) {
      pcVar8 = (char *)FUN_1000b4e0(local_cc);
      local_160 = &stack0xfffffe68;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &stack0xfffffe68,pcVar8);
      local_164 = &stack0xfffffe4c;
      local_8._0_1_ = 0x13;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &stack0xfffffe4c,"value");
      local_8._0_1_ = 0x12;
      FUN_10015210((void *)((int)local_15c + 4),in_stack_fffffe4c);
      *(undefined2 *)((int)local_15c + 0x14) = 1;
      FUN_10001d72(local_13c);
      pbVar3 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_cc;
      goto LAB_100161c0;
    }
    FUN_10001d72(local_13c);
    FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 local_cc);
  }
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_120);
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_e8);
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_104);
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_b0);
  FUN_100074ce((int)&param_1);
LAB_100166a0:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100166c0 at 100166c0

void __fastcall FUN_100166c0(void *param_1)

{
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> bVar1;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar2;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar3;
  int iVar4;
  uint in_stack_ffffff00;
  void *pvVar5;
  uint in_stack_ffffff20;
  undefined4 *puVar6;
  void *local_a8 [5];
  uint local_94;
  void *local_8c [4];
  undefined4 local_7c;
  uint local_78;
  void *local_70 [4];
  undefined4 local_60;
  uint local_5c;
  void *local_54 [4];
  undefined4 local_44;
  uint local_40;
  int local_38;
  float local_34;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b5f9;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar6 = (undefined4 *)(in_stack_ffffff20 & 0xffffff00);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xffffff20,"val_type",8);
  pbVar2 = FUN_1000e280((void *)((int)param_1 + 4),
                        (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                         *)local_8c,puVar6);
  local_8 = 0;
  if (0xf < *(uint *)(pbVar2 + 0x14)) {
    pbVar2 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
              pbVar2;
  }
  local_5c = 0xf;
  local_60 = 0;
  local_70[0] = (void *)((uint)local_70[0] & 0xffffff00);
  pbVar3 = pbVar2;
  do {
    bVar1 = *pbVar3;
    pbVar3 = pbVar3 + 1;
  } while (bVar1 != (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)
                    0x0);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_70,(char *)pbVar2,(int)pbVar3 - (int)(pbVar2 + 1));
  local_8._0_1_ = 2;
  if (0xf < local_78) {
    operator_delete(local_8c[0]);
  }
  local_78 = 0xf;
  local_7c = 0;
  local_8c[0] = (void *)((uint)local_8c[0] & 0xffffff00);
  puVar6 = (undefined4 *)((uint)puVar6 & 0xffffff00);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0xffffff20,"def_val",7);
  pbVar2 = FUN_1000e280((void *)((int)param_1 + 4),
                        (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                         *)local_a8,puVar6);
  local_8 = CONCAT31(local_8._1_3_,3);
  if (0xf < *(uint *)(pbVar2 + 0x14)) {
    pbVar2 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
              pbVar2;
  }
  local_40 = 0xf;
  local_44 = 0;
  local_54[0] = (void *)((uint)local_54[0] & 0xffffff00);
  pbVar3 = pbVar2;
  do {
    bVar1 = *pbVar3;
    pbVar3 = pbVar3 + 1;
  } while (bVar1 != (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)
                    0x0);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_54,(char *)pbVar2,(int)pbVar3 - (int)(pbVar2 + 1));
  if (0xf < local_94) {
    operator_delete(local_a8[0]);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
  local_8._0_1_ = 6;
  FUN_10001f4b(&stack0xffffff1c,local_70,0,0xffffffff);
  local_8._0_1_ = 7;
  pvVar5 = (void *)(in_stack_ffffff00 & 0xffffff00);
  FUN_10001f4b(&stack0xffffff00,local_54,0,0xffffffff);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_100142f0(pvVar5);
  pvVar5 = (void *)((uint)puVar6 & 0xffffff00);
  FUN_10001f4b(&stack0xffffff20,local_30,0,0xffffffff);
  iVar4 = FUN_10015d80(param_1,local_38,local_34,pvVar5);
  if (iVar4 == 0) {
    *(undefined1 *)((int)param_1 + 0x15) = 1;
  }
  if (0xf < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
  if (0xf < local_40) {
    operator_delete(local_54[0]);
  }
  local_40 = 0xf;
  local_44 = 0;
  local_54[0] = (void *)((uint)local_54[0] & 0xffffff00);
  if (0xf < local_5c) {
    operator_delete(local_70[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10016920 at 10016920

undefined2 * __cdecl FUN_10016920(undefined2 *param_1,LPCSTR param_2)

{
  WCHAR WVar1;
  LPCSTR lpMultiByteStr;
  int cchWideChar;
  LPWSTR lpWideCharStr;
  LPWSTR pWVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b649;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  lpMultiByteStr = param_2;
  if (0xf < *(uint *)(param_2 + 0x14)) {
    lpMultiByteStr = *(LPCSTR *)param_2;
  }
  cchWideChar = MultiByteToWideChar(0xfde9,0,lpMultiByteStr,-1,(LPWSTR)0x0,0);
  lpWideCharStr = (LPWSTR)malloc(cchWideChar * 2);
  if (0xf < *(uint *)(param_2 + 0x14)) {
    param_2 = *(LPCSTR *)param_2;
  }
  MultiByteToWideChar(0xfde9,0,param_2,-1,lpWideCharStr,cchWideChar);
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  pWVar2 = lpWideCharStr;
  do {
    WVar1 = *pWVar2;
    pWVar2 = pWVar2 + 1;
  } while (WVar1 != L'\0');
  FID_conflict_assign(param_1,(undefined4 *)lpWideCharStr,
                      (int)pWVar2 - (int)(lpWideCharStr + 1) >> 1);
  local_8 = 0;
  free(lpWideCharStr);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10016a00 at 10016a00

void __cdecl FUN_10016a00(undefined4 *param_1,undefined4 *param_2,FILE **param_3)

{
  char cVar1;
  char *pcVar2;
  wchar_t ***_Filename;
  errno_t eVar3;
  char *pcVar4;
  wchar_t ***_Mode;
  wchar_t **local_68 [4];
  undefined4 local_58;
  uint local_54;
  wchar_t **local_4c [4];
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
  puStack_c = &LAB_1001b690;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pcVar2 = (char *)FUN_1000b4e0(param_1);
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
  pcVar4 = pcVar2;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_30,pcVar2,(int)pcVar4 - (int)(pcVar2 + 1));
  local_8 = 0;
  FUN_10016920((undefined2 *)local_68,(LPCSTR)local_30);
  local_8._0_1_ = 2;
  if (0xf < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
  pcVar2 = (char *)FUN_1000b4e0(param_2);
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
  pcVar4 = pcVar2;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_30,pcVar2,(int)pcVar4 - (int)(pcVar2 + 1));
  local_8._0_1_ = 3;
  FUN_10016920((undefined2 *)local_4c,(LPCSTR)local_30);
  local_8._0_1_ = 5;
  if (0xf < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
  _Mode = (wchar_t ***)local_4c[0];
  if (local_38 < 8) {
    _Mode = local_4c;
  }
  _Filename = (wchar_t ***)local_68[0];
  if (local_54 < 8) {
    _Filename = local_68;
  }
  eVar3 = _wfopen_s(param_3,(wchar_t *)_Filename,(wchar_t *)_Mode);
  if (eVar3 == 0) {
    local_8 = CONCAT31(local_8._1_3_,2);
    if (7 < local_38) {
      operator_delete(local_4c[0]);
    }
    local_38 = 7;
    local_3c = 0;
    local_4c[0] = (wchar_t **)((uint)local_4c[0] & 0xffff0000);
    local_8 = 0xffffffff;
    if (7 < local_54) {
      operator_delete(local_68[0]);
    }
  }
  else {
    local_8 = CONCAT31(local_8._1_3_,2);
    if (7 < local_38) {
      operator_delete(local_4c[0]);
    }
    local_38 = 7;
    local_3c = 0;
    local_4c[0] = (wchar_t **)((uint)local_4c[0] & 0xffff0000);
    local_8 = 0xffffffff;
    if (7 < local_54) {
      operator_delete(local_68[0]);
    }
  }
  local_68[0] = (wchar_t **)((uint)local_68[0] & 0xffff0000);
  local_58 = 0;
  local_54 = 7;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10016be0 at 10016be0

void __cdecl FUN_10016be0(undefined4 *param_1)

{
  char cVar1;
  char *pcVar2;
  wchar_t ***_Name;
  int iVar3;
  char *pcVar4;
  _stat64 local_84;
  void *local_4c [4];
  undefined4 local_3c;
  uint local_38;
  wchar_t **local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b6d0;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pcVar2 = (char *)FUN_1000b4e0(param_1);
  local_38 = 0xf;
  local_3c = 0;
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffffff00);
  pcVar4 = pcVar2;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_4c,pcVar2,(int)pcVar4 - (int)(pcVar2 + 1));
  local_8 = 0;
  FUN_10016920((undefined2 *)local_30,(LPCSTR)local_4c);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (0xf < local_38) {
    operator_delete(local_4c[0]);
  }
  local_38 = 0xf;
  local_3c = 0;
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffffff00);
  _Name = (wchar_t ***)local_30[0];
  if (local_1c < 8) {
    _Name = local_30;
  }
  iVar3 = _wstat64((wchar_t *)_Name,&local_84);
  if (iVar3 == 0) {
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      operator_delete(local_30[0]);
    }
  }
  else {
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      operator_delete(local_30[0]);
    }
  }
  local_30[0] = (wchar_t **)((uint)local_30[0] & 0xffff0000);
  local_20 = 0;
  local_1c = 7;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10016d00 at 10016d00

void __cdecl FUN_10016d00(undefined4 *param_1)

{
  char cVar1;
  char *pcVar2;
  wchar_t ***_Path;
  int iVar3;
  char *pcVar4;
  void *local_4c [4];
  undefined4 local_3c;
  uint local_38;
  wchar_t **local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b710;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pcVar2 = (char *)FUN_1000b4e0(param_1);
  local_38 = 0xf;
  local_3c = 0;
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffffff00);
  pcVar4 = pcVar2;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_4c,pcVar2,(int)pcVar4 - (int)(pcVar2 + 1));
  local_8 = 0;
  FUN_10016920((undefined2 *)local_30,(LPCSTR)local_4c);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (0xf < local_38) {
    operator_delete(local_4c[0]);
  }
  local_38 = 0xf;
  local_3c = 0;
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffffff00);
  _Path = (wchar_t ***)local_30[0];
  if (local_1c < 8) {
    _Path = local_30;
  }
  iVar3 = _wmkdir((wchar_t *)_Path);
  if (iVar3 == 0) {
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      operator_delete(local_30[0]);
    }
  }
  else {
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      operator_delete(local_30[0]);
    }
  }
  local_30[0] = (wchar_t **)((uint)local_30[0] & 0xffff0000);
  local_20 = 0;
  local_1c = 7;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10016e20 at 10016e20

uint __cdecl FUN_10016e20(void *param_1)

{
  int iVar1;
  char *pcVar2;
  char *extraout_EAX;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  char *extraout_EAX_02;
  char cVar3;
  char cVar4;
  int iVar5;
  uint in_stack_00000018;
  int *in_stack_00000020;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b748;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  *in_stack_00000020 = 0;
  pcVar2 = (char *)FUN_1000b4e0(&param_1);
  if (*pcVar2 == ' ') {
    cVar3 = ' ';
    do {
      if (cVar3 == '0') break;
      cVar3 = pcVar2[1];
      pcVar2 = pcVar2 + 1;
    } while (cVar3 == ' ');
  }
  iVar5 = 0;
  cVar3 = *pcVar2;
  if (cVar3 == '-') {
    pcVar2 = pcVar2 + 1;
  }
  cVar4 = *pcVar2;
  if ('/' < cVar4) {
    while (cVar4 < ':') {
      if (cVar3 != '-') {
        iVar1 = cVar4 + -0x30 + *in_stack_00000020 * 10;
        *in_stack_00000020 = iVar1;
        if (iVar1 < iVar5) {
          if (0xf < in_stack_00000018) {
            operator_delete(param_1);
            ExceptionList = local_10;
            return extraout_EAX_01 & 0xffffff00;
          }
          goto LAB_10016eb0;
        }
      }
      else {
        iVar1 = (*in_stack_00000020 * 10 - (int)cVar4) + 0x30;
        *in_stack_00000020 = iVar1;
        if (iVar5 < iVar1) {
          if (0xf < in_stack_00000018) {
            operator_delete(param_1);
            pcVar2 = extraout_EAX;
          }
          goto LAB_10016eb0;
        }
      }
      cVar4 = pcVar2[1];
      iVar5 = *in_stack_00000020;
      pcVar2 = pcVar2 + 1;
      if (cVar4 < '0') break;
    }
  }
  cVar3 = *pcVar2;
  while (cVar3 == ' ') {
    pcVar2 = pcVar2 + 1;
    cVar3 = *pcVar2;
  }
  if (*pcVar2 == '\0') {
    if (0xf < in_stack_00000018) {
      operator_delete(param_1);
      pcVar2 = extraout_EAX_02;
    }
    ExceptionList = local_10;
    return CONCAT31((int3)((uint)pcVar2 >> 8),1);
  }
  if (0xf < in_stack_00000018) {
    operator_delete(param_1);
    ExceptionList = local_10;
    return extraout_EAX_00 & 0xffffff00;
  }
LAB_10016eb0:
  ExceptionList = local_10;
  return (uint)pcVar2 & 0xffffff00;
}



// Function: FUN_10016f60 at 10016f60

void __cdecl
FUN_10016f60(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,
            int param_2,int param_3)

{
  char cVar1;
  void *_Memory;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  longlong lVar6;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b778;
  local_10 = ExceptionList;
  local_14 = DAT_10026b20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_2 == 0 && param_3 == 0) {
    *(undefined4 *)(param_1 + 0x14) = 0xf;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *param_1 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              (param_1,"0",1);
  }
  else {
    _Memory = malloc(0x32);
    lVar6 = CONCAT44(param_3,param_2);
    *(char *)((int)_Memory + 0x31) = '\0';
    pcVar5 = (char *)((int)_Memory + 0x31);
    do {
      pcVar2 = pcVar5;
      uVar3 = (uint)lVar6;
      pcVar5 = pcVar2 + -1;
      lVar6 = __alldiv(uVar3,(uint)((ulonglong)lVar6 >> 0x20),10,0);
      iVar4 = uVar3 + (int)lVar6 * -10;
      if (iVar4 < 0) {
        iVar4 = -iVar4;
      }
      *pcVar5 = (char)iVar4 + '0';
    } while (lVar6 != 0);
    if ((param_3 < 1) && (param_3 < 0)) {
      pcVar5 = pcVar2 + -2;
      *pcVar5 = '-';
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    pcVar2 = pcVar5;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_30,pcVar5,(int)pcVar2 - (int)(pcVar5 + 1));
    local_8 = 0;
    free(_Memory);
    *(undefined4 *)(param_1 + 0x14) = 0xf;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *param_1 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
    FUN_10001f4b(param_1,local_30,0,0xffffffff);
    if (0xf < local_1c) {
      operator_delete(local_30[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001708e at 1001708e

void __fastcall FUN_1001708e(int *param_1)

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



// Function: FUN_100170d2 at 100170d2

int __fastcall FUN_100170d2(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_100170eb at 100170eb

undefined4 * __fastcall FUN_100170eb(undefined4 *param_1)

{
  long lVar1;
  
  FUN_100170d2((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &DAT_10024f00;
  param_1[3] = &DAT_10024f00;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (lVar1 < 0) {
    DAT_10026b38 = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: FUN_1001712c at 1001712c

void __fastcall FUN_1001712c(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_1001714b at 1001714b

int __fastcall FUN_1001714b(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_10017170 at 10017170

void __fastcall FUN_10017170(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  FUN_1001712c((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: FUN_10017188 at 10017188

undefined4 * __fastcall FUN_10017188(undefined4 *param_1)

{
  long lVar1;
  
  FUN_1001714b((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_1001feec;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 5));
  if (lVar1 < 0) {
    DAT_10026b38 = 1;
  }
  return param_1;
}



// Function: FUN_100171c8 at 100171c8

void FUN_100171c8(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: FUN_100171d3 at 100171d3

void __fastcall FUN_100171d3(int param_1)

{
  facet *pfVar1;
  
  pfVar1 = std::locale::facet::_Decref(*(facet **)(param_1 + 4));
  if (pfVar1 != (facet *)0x0) {
    (*(code *)**(undefined4 **)pfVar1)(1);
  }
  return;
}



// Function: FUN_100171e9 at 100171e9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_100171e9(void)

{
  undefined4 *puVar1;
  _Lockit local_14 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x100171f5;
  std::_Lockit::_Lockit(local_14,0);
  local_8 = 0;
  while (puVar1 = DAT_1002732c, DAT_1002732c != (undefined4 *)0x0) {
    DAT_1002732c = (undefined4 *)*DAT_1002732c;
    FUN_100171d3((int)puVar1);
    operator_delete(puVar1);
  }
  local_8 = 0xffffffff;
  std::_Lockit::~_Lockit(local_14);
  return;
}



// Function: FID_conflict:`vector_deleting_destructor' at 10017240

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



// Function: __security_check_cookie at 100172a4

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_10026b20) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: __EH_prolog3 at 100172b3

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10026b20 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch at 100172e6

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10026b20 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_GS at 1001731c

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10026b20 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch_GS at 10017352

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10026b20 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_epilog3 at 1001738b

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



// Function: FUN_1001739f at 1001739f

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001739f(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x10) ^ unaff_EBP);
  return;
}



// Function: FUN_100173ae at 100173ae

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_100173ae(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_10017437 at 10017437

void __cdecl
FUN_10017437(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_10026b20,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: __alloca_probe_16 at 10017460

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



// Function: __alloca_probe_8 at 10017476

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



// Function: __onexit at 10017496

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
  
  local_8 = &DAT_10024e38;
  uStack_c = 0x100174a2;
  local_20[0] = DecodePointer(DAT_10027674);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_10027674);
    local_24 = DecodePointer(DAT_10027670);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_10027674 = EncodePointer(local_20[0]);
    DAT_10027670 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_1001752e();
  }
  return p_Var1;
}



// Function: FUN_1001752e at 1001752e

void FUN_1001752e(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 10017537

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: __alloca_probe at 10017560

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



// Function: `eh_vector_constructor_iterator' at 10017592

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
  FUN_100175df();
  return;
}



// Function: FUN_100175df at 100175df

void FUN_100175df(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __ArrayUnwind at 100175f7

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



// Function: `eh_vector_destructor_iterator' at 10017655

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
  FUN_100176a0();
  return;
}



// Function: FUN_100176a0 at 100176a0

void FUN_100176a0(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: __CRT_INIT@12 at 10017712

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
    if (DAT_10027334 < 1) {
      return 0;
    }
    DAT_10027334 = DAT_10027334 + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10027668,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10027664 == 2) {
      param_2 = (int *)DecodePointer(DAT_10027674);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_10027670);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_10027674);
            piVar8 = (int *)DecodePointer(DAT_10027670);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_10027670 = (PVOID)encoded_null();
        DAT_10027674 = DAT_10027670;
      }
      DAT_10027664 = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_10027668,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10027668,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10027664 == 0) {
      DAT_10027664 = 1;
      iVar5 = initterm_e(&DAT_1001e434,&DAT_1001e43c);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_1001e274,&DAT_1001e430);
      DAT_10027664 = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_10027668,0);
    }
    if ((DAT_1002766c != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_1002766c), BVar2 != 0)) {
      (*DAT_1002766c)(param_1,2,param_3);
    }
    DAT_10027334 = DAT_10027334 + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 1001791c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x100179bc) */
/* WARNING: Removing unreachable block (ram,0x10017969) */
/* WARNING: Removing unreachable block (ram,0x100179e9) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HMODULE param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_10026b30 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_10027334 == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(&param_3->unused,param_2,param_1), local_20 != 0)) {
    local_20 = FUN_10004223(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      FUN_10004223(param_3,0);
      __CRT_INIT_12(&param_3->unused,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(&param_3->unused,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_10017a27();
  return local_20;
}



// Function: FUN_10017a27 at 10017a27

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10017a27(void)

{
  _DAT_10026b30 = 0xffffffff;
  return;
}



// Function: entry at 10017a32

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: __alldiv at 10017a60

/* Library Function - Single Match
    __alldiv
   
   Library: Visual Studio */

undefined8 __alldiv(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar10;
  char cVar11;
  uint uVar9;
  
  cVar11 = (int)param_2 < 0;
  if ((bool)cVar11) {
    bVar10 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(uint)bVar10 - param_2;
  }
  if ((int)param_4 < 0) {
    cVar11 = cVar11 + '\x01';
    bVar10 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -(uint)bVar10 - param_4;
  }
  uVar3 = param_1;
  uVar5 = param_3;
  uVar6 = param_2;
  uVar9 = param_4;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    do {
      uVar8 = uVar9 >> 1;
      uVar5 = uVar5 >> 1 | (uint)((uVar9 & 1) != 0) << 0x1f;
      uVar7 = uVar6 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar6 & 1) != 0) << 0x1f;
      uVar6 = uVar7;
      uVar9 = uVar8;
    } while (uVar8 != 0);
    uVar1 = CONCAT44(uVar7,uVar3) / (ulonglong)uVar5;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar5 = uVar3 + iVar4 * param_4;
    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar5)) ||
       ((param_2 <= uVar5 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  if (cVar11 == '\x01') {
    bVar10 = iVar4 != 0;
    iVar4 = -iVar4;
    uVar3 = -(uint)bVar10 - uVar3;
  }
  return CONCAT44(uVar3,iVar4);
}



// Function: ___report_gsfailure at 10017b0a

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
  
  _DAT_10027450 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_10027454 = &stack0x00000004;
  _DAT_10027390 = 0x10001;
  _DAT_10027338 = 0xc0000409;
  _DAT_1002733c = 1;
  local_32c = DAT_10026b20;
  local_328 = DAT_10026b24;
  _DAT_10027344 = unaff_retaddr;
  _DAT_1002741c = in_GS;
  _DAT_10027420 = in_FS;
  _DAT_10027424 = in_ES;
  _DAT_10027428 = in_DS;
  _DAT_1002742c = unaff_EDI;
  _DAT_10027430 = unaff_ESI;
  _DAT_10027434 = unaff_EBX;
  _DAT_10027438 = in_EDX;
  _DAT_1002743c = in_ECX;
  _DAT_10027440 = in_EAX;
  _DAT_10027444 = unaff_EBP;
  DAT_10027448 = unaff_retaddr;
  _DAT_1002744c = in_CS;
  _DAT_10027458 = in_SS;
  DAT_10027388 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_1001ff08);
  if (DAT_10027388 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __SEH_prolog4 at 10017c10

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10026b20 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 10017c55

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



// Function: __ValidateImageBase at 10017ce0

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



// Function: __FindPESection at 10017d20

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



// Function: __IsNonwritableInCurrentImage at 10017d70

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
  
  pcStack_10 = FUN_10017437;
  local_14 = ExceptionList;
  local_c = DAT_10026b20 ^ 0x10024ee0;
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



// Function: ___security_init_cookie at 10017e44

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
  if ((DAT_10026b20 == 0xbb40e64e) || ((DAT_10026b20 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_10026b20 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_10026b20 == 0xbb40e64e) {
      DAT_10026b20 = 0xbb40e64f;
    }
    else if ((DAT_10026b20 & 0xffff0000) == 0) {
      DAT_10026b20 = DAT_10026b20 | (DAT_10026b20 | 0x4711) << 0x10;
    }
    DAT_10026b24 = ~DAT_10026b20;
  }
  else {
    DAT_10026b24 = ~DAT_10026b20;
  }
  return;
}



// Function: Unwind@10017f00 at 10017f00

void Unwind_10017f00(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10017f03. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10017f24 at 10017f24

void Unwind_10017f24(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10017f27. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10017f48 at 10017f48

void Unwind_10017f48(void)

{
  int unaff_EBP;
  
  FUN_100016af((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10017f86 at 10017f86

void Unwind_10017f86(void)

{
  int unaff_EBP;
  
  FUN_100018e7(unaff_EBP + -0x20);
  return;
}



// Function: Unwind@10017fc4 at 10017fc4

void Unwind_10017fc4(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  (unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10018002 at 10018002

void Unwind_10018002(void)

{
  int unaff_EBP;
  
  FUN_1000230d(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001800a at 1001800a

void Unwind_1001800a(void)

{
  int unaff_EBP;
  
  FUN_10003b78(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001802d at 1001802d

void Unwind_1001802d(void)

{
  int unaff_EBP;
  
  FUN_10003b78(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018035 at 10018035

void Unwind_10018035(void)

{
  int unaff_EBP;
  
  FUN_1000230d(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018058 at 10018058

void Unwind_10018058(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10018060 at 10018060

void Unwind_10018060(void)

{
  int unaff_EBP;
  
  FUN_10003b78((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10018068 at 10018068

void Unwind_10018068(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001808b at 1001808b

void Unwind_1001808b(void)

{
  int unaff_EBP;
  
  FUN_100021ed(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018093 at 10018093

void Unwind_10018093(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@100180b9 at 100180b9

void Unwind_100180b9(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + 0x14));
  return;
}



// Function: Unwind@100180c1 at 100180c1

void Unwind_100180c1(void)

{
  int unaff_EBP;
  
  FUN_100021ed(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100180c9 at 100180c9

void Unwind_100180c9(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@100180ef at 100180ef

void Unwind_100180ef(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100180f7 at 100180f7

void Unwind_100180f7(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100180ff at 100180ff

void Unwind_100180ff(void)

{
  int unaff_EBP;
  
  FUN_10003b78((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10018107 at 10018107

void Unwind_10018107(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001810f at 1001810f

void Unwind_1001810f(void)

{
  int unaff_EBP;
  
  FUN_10003b78((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10018117 at 10018117

void Unwind_10018117(void)

{
  int unaff_EBP;
  
  FUN_10001567(*(undefined4 **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001811f at 1001811f

void Unwind_1001811f(void)

{
  int unaff_EBP;
  
  FUN_1000233e((undefined4 *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1001812a at 1001812a

void Unwind_1001812a(void)

{
  int unaff_EBP;
  
  FUN_10001567(*(undefined4 **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10018132 at 10018132

void Unwind_10018132(void)

{
  int unaff_EBP;
  
  FUN_1000233e((undefined4 *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1001813d at 1001813d

void Unwind_1001813d(void)

{
  int unaff_EBP;
  
  FUN_10001567(*(undefined4 **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10018145 at 10018145

void Unwind_10018145(void)

{
  int unaff_EBP;
  
  FUN_1000233e((undefined4 *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@10018150 at 10018150

void Unwind_10018150(void)

{
  int unaff_EBP;
  
  FUN_10001567(*(undefined4 **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10018158 at 10018158

void Unwind_10018158(void)

{
  int unaff_EBP;
  
  FUN_1000233e((undefined4 *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@10018163 at 10018163

void Unwind_10018163(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001816b at 1001816b

void Unwind_1001816b(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10018191 at 10018191

void Unwind_10018191(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10018199 at 10018199

void Unwind_10018199(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100181a1 at 100181a1

void Unwind_100181a1(void)

{
  int unaff_EBP;
  
  FUN_100018e7(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@100181a9 at 100181a9

void Unwind_100181a9(void)

{
  int unaff_EBP;
  
  FUN_10001567(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@100181b1 at 100181b1

void Unwind_100181b1(void)

{
  int unaff_EBP;
  
  FUN_1000233e((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@100181b9 at 100181b9

void Unwind_100181b9(void)

{
  int unaff_EBP;
  
  FUN_10001567(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100181c1 at 100181c1

void Unwind_100181c1(void)

{
  int unaff_EBP;
  
  FUN_10001567(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@100181c9 at 100181c9

void Unwind_100181c9(void)

{
  int unaff_EBP;
  
  FUN_1000233e((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@100181ec at 100181ec

void Unwind_100181ec(void)

{
  DAT_10027038 = DAT_10027038 & 0xfffffffe;
  return;
}



// Function: Unwind@10018215 at 10018215

void Unwind_10018215(void)

{
  int unaff_EBP;
  
  FUN_10007177(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018238 at 10018238

void Unwind_10018238(void)

{
  int unaff_EBP;
  
  FUN_10002b57(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001825b at 1001825b

void Unwind_1001825b(void)

{
  int unaff_EBP;
  
  FUN_100037de(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001827e at 1001827e

void Unwind_1001827e(void)

{
  int unaff_EBP;
  
  FUN_10001938((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@100182b1 at 100182b1

void Unwind_100182b1(void)

{
  int unaff_EBP;
  
  FUN_100016af((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@100182e4 at 100182e4

void Unwind_100182e4(void)

{
  int unaff_EBP;
  
  FUN_1000230d(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018307 at 10018307

void Unwind_10018307(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018311 at 10018311

void Unwind_10018311(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10018334 at 10018334

void Unwind_10018334(void)

{
  int unaff_EBP;
  
  FUN_10001567(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018372 at 10018372

void Unwind_10018372(void)

{
  int unaff_EBP;
  
  FUN_100035b4(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@10018398 at 10018398

void Unwind_10018398(void)

{
  int unaff_EBP;
  
  FUN_100035d2((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100183be at 100183be

void Unwind_100183be(void)

{
  int unaff_EBP;
  
  FUN_100035b4(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@100183c9 at 100183c9

void Unwind_100183c9(void)

{
  int unaff_EBP;
  
  FUN_10007177(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100183ec at 100183ec

void Unwind_100183ec(void)

{
  FUN_10003700();
  return;
}



// Function: Unwind@10018403 at 10018403

void Unwind_10018403(void)

{
  FUN_10003700();
  return;
}



// Function: Unwind@10018436 at 10018436

void Unwind_10018436(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001843e at 1001843e

void Unwind_1001843e(void)

{
  int unaff_EBP;
  
  FUN_10003b78((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018446 at 10018446

void Unwind_10018446(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001844e at 1001844e

void Unwind_1001844e(void)

{
  int unaff_EBP;
  
  FUN_10003b78((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018456 at 10018456

void Unwind_10018456(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001845e at 1001845e

void Unwind_1001845e(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018481 at 10018481

void Unwind_10018481(void)

{
  int unaff_EBP;
  
  FUN_100037de(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018489 at 10018489

void Unwind_10018489(void)

{
  int unaff_EBP;
  
  FUN_100037e3(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100184ac at 100184ac

void Unwind_100184ac(void)

{
  int unaff_EBP;
  
  FUN_100037e3(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100184b4 at 100184b4

void Unwind_100184b4(void)

{
  int unaff_EBP;
  
  FUN_100037de(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100184d7 at 100184d7

void Unwind_100184d7(void)

{
  int unaff_EBP;
  
  thunk_FUN_10003388(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100184fa at 100184fa

void Unwind_100184fa(void)

{
  int unaff_EBP;
  
  FUN_10004265((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10018520 at 10018520

void Unwind_10018520(void)

{
  int unaff_EBP;
  
  FUN_10002e66(unaff_EBP + -0x6c);
  return;
}



// Function: Unwind@1001854d at 1001854d

void Unwind_1001854d(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10018558 at 10018558

void Unwind_10018558(void)

{
  int unaff_EBP;
  
  FUN_10003b78((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10018563 at 10018563

void Unwind_10018563(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001856e at 1001856e

void Unwind_1001856e(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10018579 at 10018579

void Unwind_10018579(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10018584 at 10018584

void Unwind_10018584(void)

{
  int unaff_EBP;
  
  FUN_100016af((int *)(unaff_EBP + -0x1c8));
  return;
}



// Function: Unwind@1001858f at 1001858f

void Unwind_1001858f(void)

{
  int unaff_EBP;
  
  FUN_10001938((undefined4 *)(unaff_EBP + -0x1c4));
  return;
}



// Function: Unwind@1001859a at 1001859a

void Unwind_1001859a(void)

{
  int unaff_EBP;
  
  FUN_10001938((undefined4 *)(unaff_EBP + -0x1b8));
  return;
}



// Function: Unwind@100185a5 at 100185a5

void Unwind_100185a5(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@100185b0 at 100185b0

void Unwind_100185b0(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@100185e3 at 100185e3

void Unwind_100185e3(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100185eb at 100185eb

void Unwind_100185eb(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100185f3 at 100185f3

void Unwind_100185f3(void)

{
  int unaff_EBP;
  
  FUN_10003b78((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100185fb at 100185fb

void Unwind_100185fb(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018603 at 10018603

void Unwind_10018603(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018626 at 10018626

void Unwind_10018626(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10018631 at 10018631

void Unwind_10018631(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1001863c at 1001863c

void Unwind_1001863c(void)

{
  int unaff_EBP;
  
  FUN_10003b78((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10018647 at 10018647

void Unwind_10018647(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10018652 at 10018652

void Unwind_10018652(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1001865d at 1001865d

void Unwind_1001865d(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10018690 at 10018690

void Unwind_10018690(void)

{
  int unaff_EBP;
  
  FUN_10004087((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100186b3 at 100186b3

void Unwind_100186b3(void)

{
  int unaff_EBP;
  
  FUN_10004087((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100186d6 at 100186d6

void Unwind_100186d6(void)

{
  int unaff_EBP;
  
  FUN_10003f16(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@100186e1 at 100186e1

void Unwind_100186e1(void)

{
  int unaff_EBP;
  
  FUN_100035d2((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10018707 at 10018707

void Unwind_10018707(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001872c at 1001872c

void Unwind_1001872c(void)

{
  int unaff_EBP;
  
  FUN_100035d2((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10018737 at 10018737

void Unwind_10018737(void)

{
  int unaff_EBP;
  
  FUN_10003f16(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001875d at 1001875d

void Unwind_1001875d(void)

{
  int unaff_EBP;
  
  FUN_10003e9c((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10018765 at 10018765

void Unwind_10018765(void)

{
  int unaff_EBP;
  
  FUN_10003e9c((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10018788 at 10018788

void Unwind_10018788(void)

{
  int unaff_EBP;
  
  FUN_10003eac((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@10018793 at 10018793

void Unwind_10018793(void)

{
  int unaff_EBP;
  
  FUN_100016af((int *)(unaff_EBP + -0x2120));
  return;
}



// Function: Unwind@1001879e at 1001879e

void Unwind_1001879e(void)

{
  int unaff_EBP;
  
  FUN_10003eac((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@100187d1 at 100187d1

void Unwind_100187d1(void)

{
  int unaff_EBP;
  
  FUN_10001938((undefined4 *)(unaff_EBP + -0x2230));
  return;
}



// Function: Unwind@100187dc at 100187dc

void Unwind_100187dc(void)

{
  int unaff_EBP;
  
  FUN_10001938((undefined4 *)(unaff_EBP + -0x2240));
  return;
}



// Function: Unwind@100187e7 at 100187e7

void Unwind_100187e7(void)

{
  int unaff_EBP;
  
  FUN_10001938((undefined4 *)(unaff_EBP + -0x2258));
  return;
}



// Function: Unwind@100187f2 at 100187f2

void Unwind_100187f2(void)

{
  int unaff_EBP;
  
  FUN_10001938((undefined4 *)(unaff_EBP + -0x2264));
  return;
}



// Function: Unwind@100187fd at 100187fd

void Unwind_100187fd(void)

{
  int unaff_EBP;
  
  FUN_10001938((undefined4 *)(unaff_EBP + -0x224c));
  return;
}



// Function: Unwind@10018830 at 10018830

void Unwind_10018830(void)

{
  int unaff_EBP;
  
  FUN_10004087((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10018853 at 10018853

void Unwind_10018853(void)

{
  int unaff_EBP;
  
  FUN_10004087((undefined4 *)(unaff_EBP + -0x238));
  return;
}



// Function: Unwind@1001885e at 1001885e

void Unwind_1001885e(void)

{
  int unaff_EBP;
  
  FUN_100016af((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10018869 at 10018869

void Unwind_10018869(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10018874 at 10018874

void Unwind_10018874(void)

{
  int unaff_EBP;
  
  FUN_10003b78((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1001887f at 1001887f

void Unwind_1001887f(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1001888a at 1001888a

void Unwind_1001888a(void)

{
  int unaff_EBP;
  
  FUN_10003b78((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10018895 at 10018895

void Unwind_10018895(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@100188a0 at 100188a0

void Unwind_100188a0(void)

{
  int unaff_EBP;
  
  FUN_10003b78((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@100188ab at 100188ab

void Unwind_100188ab(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@100188b6 at 100188b6

void Unwind_100188b6(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@100188c1 at 100188c1

void Unwind_100188c1(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@100188f4 at 100188f4

void Unwind_100188f4(void)

{
  int unaff_EBP;
  
  FUN_10004df3(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018917 at 10018917

void Unwind_10018917(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001893c at 1001893c

void Unwind_1001893c(void)

{
  int unaff_EBP;
  
  FUN_100016af((int *)(unaff_EBP + -0x428));
  return;
}



// Function: Unwind@10018947 at 10018947

void Unwind_10018947(void)

{
  int unaff_EBP;
  
  FUN_10003eac((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@1001897a at 1001897a

void Unwind_1001897a(void)

{
  int unaff_EBP;
  
  FUN_100016af((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001899d at 1001899d

void Unwind_1001899d(void)

{
  int unaff_EBP;
  
  thunk_FUN_10003388(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@100189a8 at 100189a8

void Unwind_100189a8(void)

{
  int unaff_EBP;
  
  FUN_10004265((int *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@100189b3 at 100189b3

void Unwind_100189b3(void)

{
  int unaff_EBP;
  
  FUN_1000428f((undefined4 *)(unaff_EBP + -0xa5c));
  return;
}



// Function: Unwind@100189be at 100189be

void Unwind_100189be(void)

{
  int unaff_EBP;
  
  FUN_100016af((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@100189f1 at 100189f1

void Unwind_100189f1(void)

{
  int unaff_EBP;
  
  thunk_FUN_10003388(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@100189fc at 100189fc

void Unwind_100189fc(void)

{
  int unaff_EBP;
  
  FUN_10004265((int *)(unaff_EBP + -0xa54));
  return;
}



// Function: Unwind@10018a07 at 10018a07

void Unwind_10018a07(void)

{
  int unaff_EBP;
  
  FUN_1000428f((undefined4 *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@10018a12 at 10018a12

void Unwind_10018a12(void)

{
  int unaff_EBP;
  
  FUN_100016af((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@10018a45 at 10018a45

void Unwind_10018a45(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018a68 at 10018a68

void Unwind_10018a68(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_10026114);
  return;
}



// Function: Unwind@10018a8d at 10018a8d

void Unwind_10018a8d(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_10026130);
  return;
}



// Function: Unwind@10018ab2 at 10018ab2

void Unwind_10018ab2(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_1002614c);
  return;
}



// Function: Unwind@10018ad7 at 10018ad7

void Unwind_10018ad7(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_10026184);
  return;
}



// Function: Unwind@10018afc at 10018afc

void Unwind_10018afc(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_100261a0);
  return;
}



// Function: Unwind@10018b21 at 10018b21

void Unwind_10018b21(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_100261bc);
  return;
}



// Function: Unwind@10018b46 at 10018b46

void Unwind_10018b46(void)

{
  FUN_100037e3(0x1002703c);
  return;
}



// Function: Unwind@10018b50 at 10018b50

void Unwind_10018b50(void)

{
  FUN_100037de(0x1002703c);
  return;
}



// Function: Unwind@10018b75 at 10018b75

void Unwind_10018b75(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_100260f8);
  return;
}



// Function: Unwind@10018b9a at 10018b9a

void Unwind_10018b9a(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_10026168);
  return;
}



// Function: Unwind@10018bbf at 10018bbf

void Unwind_10018bbf(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_100261d8);
  return;
}



// Function: Unwind@10018be4 at 10018be4

void Unwind_10018be4(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_100261f4);
  return;
}



// Function: Unwind@10018c09 at 10018c09

void Unwind_10018c09(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_10026210);
  return;
}



// Function: Unwind@10018c2e at 10018c2e

void Unwind_10018c2e(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_1002622c);
  return;
}



// Function: Unwind@10018c53 at 10018c53

void Unwind_10018c53(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_10026248);
  return;
}



// Function: Unwind@10018c78 at 10018c78

void Unwind_10018c78(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_10026264);
  return;
}



// Function: Unwind@10018c9d at 10018c9d

void Unwind_10018c9d(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_10026280);
  return;
}



// Function: Unwind@10018cc2 at 10018cc2

void Unwind_10018cc2(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_1002629c);
  return;
}



// Function: Unwind@10018ce7 at 10018ce7

void Unwind_10018ce7(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_100262b8);
  return;
}



// Function: Unwind@10018d0c at 10018d0c

void Unwind_10018d0c(void)

{
  int unaff_EBP;
  
  FUN_10006d4b(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018d2f at 10018d2f

void Unwind_10018d2f(void)

{
  int unaff_EBP;
  
  FUN_10003f16(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10018d3a at 10018d3a

void Unwind_10018d3a(void)

{
  int unaff_EBP;
  
  FUN_100035d2((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10018d60 at 10018d60

void Unwind_10018d60(void)

{
  int unaff_EBP;
  
  FUN_100016af((int *)(unaff_EBP + -0x824));
  return;
}



// Function: Unwind@10018d6b at 10018d6b

void Unwind_10018d6b(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x814));
  return;
}



// Function: Unwind@10018d76 at 10018d76

void Unwind_10018d76(void)

{
  int unaff_EBP;
  
  FUN_10003b78((int *)(unaff_EBP + -0x814));
  return;
}



// Function: Unwind@10018d81 at 10018d81

void Unwind_10018d81(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x81c));
  return;
}



// Function: Unwind@10018d8c at 10018d8c

void Unwind_10018d8c(void)

{
  int unaff_EBP;
  
  FUN_10003b78((int *)(unaff_EBP + -0x81c));
  return;
}



// Function: Unwind@10018d97 at 10018d97

void Unwind_10018d97(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x81c));
  return;
}



// Function: Unwind@10018da2 at 10018da2

void Unwind_10018da2(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0x814));
  return;
}



// Function: Unwind@10018dd5 at 10018dd5

void Unwind_10018dd5(void)

{
  int unaff_EBP;
  
  FUN_10006d4b(*(int **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10018ddd at 10018ddd

void Unwind_10018ddd(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10006d50(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10018e11 at 10018e11

void Unwind_10018e11(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@10018e1c at 10018e1c

void Unwind_10018e1c(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018e3f at 10018e3f

void Unwind_10018e3f(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018e47 at 10018e47

void Unwind_10018e47(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018e4f at 10018e4f

void Unwind_10018e4f(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018e57 at 10018e57

void Unwind_10018e57(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (*(int *)(unaff_EBP + -0x10) + 0x20));
  return;
}



// Function: Unwind@10018e62 at 10018e62

void Unwind_10018e62(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018e6a at 10018e6a

void Unwind_10018e6a(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}



// Function: Unwind@10018e75 at 10018e75

void Unwind_10018e75(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018e7d at 10018e7d

void Unwind_10018e7d(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (*(int *)(unaff_EBP + -0x10) + 0x58));
  return;
}



// Function: Unwind@10018ea3 at 10018ea3

void Unwind_10018ea3(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018eab at 10018eab

void Unwind_10018eab(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (*(int *)(unaff_EBP + -0x10) + 0x20));
  return;
}



// Function: Unwind@10018eb6 at 10018eb6

void Unwind_10018eb6(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}



// Function: Unwind@10018ec1 at 10018ec1

void Unwind_10018ec1(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (*(int *)(unaff_EBP + -0x10) + 0x58));
  return;
}



// Function: Unwind@10018ecc at 10018ecc

void Unwind_10018ecc(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018ed4 at 10018ed4

void Unwind_10018ed4(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018edc at 10018edc

void Unwind_10018edc(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018ee4 at 10018ee4

void Unwind_10018ee4(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018f07 at 10018f07

void Unwind_10018f07(void)

{
  int unaff_EBP;
  
  FUN_100074ce(unaff_EBP + 8);
  return;
}



// Function: Unwind@10018f0f at 10018f0f

void Unwind_10018f0f(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018f32 at 10018f32

void Unwind_10018f32(void)

{
  int unaff_EBP;
  
  FUN_10006d4b(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018f3a at 10018f3a

void Unwind_10018f3a(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@10018f60 at 10018f60

void Unwind_10018f60(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018f68 at 10018f68

void Unwind_10018f68(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018f8b at 10018f8b

void Unwind_10018f8b(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + 8));
  return;
}



// Function: Unwind@10018f93 at 10018f93

void Unwind_10018f93(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@10018fb9 at 10018fb9

void Unwind_10018fb9(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  (unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10018fed at 10018fed

void Unwind_10018fed(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_1000749c(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10019021 at 10019021

void Unwind_10019021(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x18) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001907a at 1001907a

void Unwind_1001907a(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10019082 at 10019082

void Unwind_10019082(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0xc4));
  return;
}



// Function: Unwind@1001908d at 1001908d

void Unwind_1001908d(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@10019098 at 10019098

void Unwind_10019098(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100190a0 at 100190a0

void Unwind_100190a0(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100190a8 at 100190a8

void Unwind_100190a8(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100190b0 at 100190b0

void Unwind_100190b0(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@100190bb at 100190bb

void Unwind_100190bb(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@100190c6 at 100190c6

void Unwind_100190c6(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100190ce at 100190ce

void Unwind_100190ce(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100190d6 at 100190d6

void Unwind_100190d6(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100190de at 100190de

void Unwind_100190de(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@100190e9 at 100190e9

void Unwind_100190e9(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@100190f4 at 100190f4

void Unwind_100190f4(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100190fc at 100190fc

void Unwind_100190fc(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019104 at 10019104

void Unwind_10019104(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001910c at 1001910c

void Unwind_1001910c(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@10019117 at 10019117

void Unwind_10019117(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@10019122 at 10019122

void Unwind_10019122(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001912a at 1001912a

void Unwind_1001912a(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019132 at 10019132

void Unwind_10019132(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001913a at 1001913a

void Unwind_1001913a(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019142 at 10019142

void Unwind_10019142(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001914a at 1001914a

void Unwind_1001914a(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019152 at 10019152

void Unwind_10019152(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001915a at 1001915a

void Unwind_1001915a(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019162 at 10019162

void Unwind_10019162(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019192 at 10019192

void Unwind_10019192(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + -0x94));
  return;
}



// Function: Unwind@1001919d at 1001919d

void Unwind_1001919d(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@100191a8 at 100191a8

void Unwind_100191a8(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x54));
  return;
}



// Function: Unwind@100191b0 at 100191b0

void Unwind_100191b0(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x54));
  return;
}



// Function: Unwind@100191b8 at 100191b8

void Unwind_100191b8(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x98));
  return;
}



// Function: Unwind@100191c3 at 100191c3

void Unwind_100191c3(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@100191ce at 100191ce

void Unwind_100191ce(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100191d6 at 100191d6

void Unwind_100191d6(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100191de at 100191de

void Unwind_100191de(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x98));
  return;
}



// Function: Unwind@100191e9 at 100191e9

void Unwind_100191e9(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100191f1 at 100191f1

void Unwind_100191f1(void)

{
  int unaff_EBP;
  
  FUN_100074ce(unaff_EBP + -0x38);
  return;
}



// Function: Unwind@100191f9 at 100191f9

void Unwind_100191f9(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@10019204 at 10019204

void Unwind_10019204(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x98));
  return;
}



// Function: Unwind@1001920f at 1001920f

void Unwind_1001920f(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1001921a at 1001921a

void Unwind_1001921a(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@10019225 at 10019225

void Unwind_10019225(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001922d at 1001922d

void Unwind_1001922d(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10019235 at 10019235

void Unwind_10019235(void)

{
  int unaff_EBP;
  
  FUN_100074ce(*(int *)(unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@10019240 at 10019240

void Unwind_10019240(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019248 at 10019248

void Unwind_10019248(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10019250 at 10019250

void Unwind_10019250(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019258 at 10019258

void Unwind_10019258(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10019288 at 10019288

void Unwind_10019288(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10019290 at 10019290

void Unwind_10019290(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10019298 at 10019298

void Unwind_10019298(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100192a0 at 100192a0

void Unwind_100192a0(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100192a8 at 100192a8

void Unwind_100192a8(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100192b0 at 100192b0

void Unwind_100192b0(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x78));
  return;
}



// Function: Unwind@100192b8 at 100192b8

void Unwind_100192b8(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100192c0 at 100192c0

void Unwind_100192c0(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100192c8 at 100192c8

void Unwind_100192c8(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x78));
  return;
}



// Function: Unwind@100192d0 at 100192d0

void Unwind_100192d0(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100192d8 at 100192d8

void Unwind_100192d8(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x80));
  return;
}



// Function: Unwind@100192e0 at 100192e0

void Unwind_100192e0(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x78));
  return;
}



// Function: Unwind@100192e8 at 100192e8

void Unwind_100192e8(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100192f0 at 100192f0

void Unwind_100192f0(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100192f8 at 100192f8

void Unwind_100192f8(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10019300 at 10019300

void Unwind_10019300(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019308 at 10019308

void Unwind_10019308(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019310 at 10019310

void Unwind_10019310(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10019318 at 10019318

void Unwind_10019318(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x78));
  return;
}



// Function: Unwind@10019320 at 10019320

void Unwind_10019320(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019350 at 10019350

void Unwind_10019350(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10019358 at 10019358

void Unwind_10019358(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10019360 at 10019360

void Unwind_10019360(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019368 at 10019368

void Unwind_10019368(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019370 at 10019370

void Unwind_10019370(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019378 at 10019378

void Unwind_10019378(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x78));
  return;
}



// Function: Unwind@10019380 at 10019380

void Unwind_10019380(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10019388 at 10019388

void Unwind_10019388(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10019390 at 10019390

void Unwind_10019390(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x78));
  return;
}



// Function: Unwind@10019398 at 10019398

void Unwind_10019398(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100193a0 at 100193a0

void Unwind_100193a0(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x80));
  return;
}



// Function: Unwind@100193a8 at 100193a8

void Unwind_100193a8(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x78));
  return;
}



// Function: Unwind@100193b0 at 100193b0

void Unwind_100193b0(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100193b8 at 100193b8

void Unwind_100193b8(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100193c0 at 100193c0

void Unwind_100193c0(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100193c8 at 100193c8

void Unwind_100193c8(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100193d0 at 100193d0

void Unwind_100193d0(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100193d8 at 100193d8

void Unwind_100193d8(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x80));
  return;
}



// Function: Unwind@100193e0 at 100193e0

void Unwind_100193e0(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x78));
  return;
}



// Function: Unwind@100193e8 at 100193e8

void Unwind_100193e8(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019418 at 10019418

void Unwind_10019418(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10019420 at 10019420

void Unwind_10019420(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10019428 at 10019428

void Unwind_10019428(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019430 at 10019430

void Unwind_10019430(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019438 at 10019438

void Unwind_10019438(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10019440 at 10019440

void Unwind_10019440(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019448 at 10019448

void Unwind_10019448(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10019450 at 10019450

void Unwind_10019450(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10019458 at 10019458

void Unwind_10019458(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019460 at 10019460

void Unwind_10019460(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10019468 at 10019468

void Unwind_10019468(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10019470 at 10019470

void Unwind_10019470(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019478 at 10019478

void Unwind_10019478(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10019480 at 10019480

void Unwind_10019480(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019488 at 10019488

void Unwind_10019488(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10019490 at 10019490

void Unwind_10019490(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10019498 at 10019498

void Unwind_10019498(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100194a0 at 100194a0

void Unwind_100194a0(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@100194d0 at 100194d0

void Unwind_100194d0(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@100194d8 at 100194d8

void Unwind_100194d8(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@100194e0 at 100194e0

void Unwind_100194e0(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100194e8 at 100194e8

void Unwind_100194e8(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100194f0 at 100194f0

void Unwind_100194f0(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100194f8 at 100194f8

void Unwind_100194f8(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x78));
  return;
}



// Function: Unwind@10019500 at 10019500

void Unwind_10019500(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10019508 at 10019508

void Unwind_10019508(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10019510 at 10019510

void Unwind_10019510(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x78));
  return;
}



// Function: Unwind@10019518 at 10019518

void Unwind_10019518(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019520 at 10019520

void Unwind_10019520(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10019528 at 10019528

void Unwind_10019528(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x78));
  return;
}



// Function: Unwind@10019530 at 10019530

void Unwind_10019530(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10019538 at 10019538

void Unwind_10019538(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019540 at 10019540

void Unwind_10019540(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10019548 at 10019548

void Unwind_10019548(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019550 at 10019550

void Unwind_10019550(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019558 at 10019558

void Unwind_10019558(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10019560 at 10019560

void Unwind_10019560(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x78));
  return;
}



// Function: Unwind@10019568 at 10019568

void Unwind_10019568(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019598 at 10019598

void Unwind_10019598(void)

{
  int unaff_EBP;
  
  FUN_10007378((int *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@100195a3 at 100195a3

void Unwind_100195a3(void)

{
  int unaff_EBP;
  
  FUN_10007378((int *)(unaff_EBP + -0x94));
  return;
}



// Function: Unwind@100195ae at 100195ae

void Unwind_100195ae(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + -0x98));
  return;
}



// Function: Unwind@100195b9 at 100195b9

void Unwind_100195b9(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@100195c4 at 100195c4

void Unwind_100195c4(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x54));
  return;
}



// Function: Unwind@100195cc at 100195cc

void Unwind_100195cc(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x54));
  return;
}



// Function: Unwind@100195d4 at 100195d4

void Unwind_100195d4(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@100195df at 100195df

void Unwind_100195df(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@100195ea at 100195ea

void Unwind_100195ea(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100195f2 at 100195f2

void Unwind_100195f2(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100195fa at 100195fa

void Unwind_100195fa(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@10019605 at 10019605

void Unwind_10019605(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001960d at 1001960d

void Unwind_1001960d(void)

{
  int unaff_EBP;
  
  FUN_100074ce(unaff_EBP + -0x38);
  return;
}



// Function: Unwind@10019615 at 10019615

void Unwind_10019615(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@10019620 at 10019620

void Unwind_10019620(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1001962b at 1001962b

void Unwind_1001962b(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xac));
  return;
}



// Function: Unwind@10019636 at 10019636

void Unwind_10019636(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@10019641 at 10019641

void Unwind_10019641(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019649 at 10019649

void Unwind_10019649(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10019651 at 10019651

void Unwind_10019651(void)

{
  int unaff_EBP;
  
  FUN_100074ce(*(int *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1001965c at 1001965c

void Unwind_1001965c(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019664 at 10019664

void Unwind_10019664(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001966c at 1001966c

void Unwind_1001966c(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019674 at 10019674

void Unwind_10019674(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x54));
  return;
}



// Function: Unwind@100196a4 at 100196a4

void Unwind_100196a4(void)

{
  int unaff_EBP;
  
  FUN_10007378((int *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@100196ac at 100196ac

void Unwind_100196ac(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100196b4 at 100196b4

void Unwind_100196b4(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@100196bc at 100196bc

void Unwind_100196bc(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100196c4 at 100196c4

void Unwind_100196c4(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100196cc at 100196cc

void Unwind_100196cc(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@100196d4 at 100196d4

void Unwind_100196d4(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x78));
  return;
}



// Function: Unwind@100196dc at 100196dc

void Unwind_100196dc(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100196e4 at 100196e4

void Unwind_100196e4(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100196ec at 100196ec

void Unwind_100196ec(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x78));
  return;
}



// Function: Unwind@100196f4 at 100196f4

void Unwind_100196f4(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@100196fc at 100196fc

void Unwind_100196fc(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x84));
  return;
}



// Function: Unwind@10019707 at 10019707

void Unwind_10019707(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x78));
  return;
}



// Function: Unwind@1001970f at 1001970f

void Unwind_1001970f(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10019717 at 10019717

void Unwind_10019717(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001971f at 1001971f

void Unwind_1001971f(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10019727 at 10019727

void Unwind_10019727(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001972f at 1001972f

void Unwind_1001972f(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@10019737 at 10019737

void Unwind_10019737(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x84));
  return;
}



// Function: Unwind@10019742 at 10019742

void Unwind_10019742(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x78));
  return;
}



// Function: Unwind@1001974a at 1001974a

void Unwind_1001974a(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@1001977a at 1001977a

void Unwind_1001977a(void)

{
  int unaff_EBP;
  
  FUN_10007378((int *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10019782 at 10019782

void Unwind_10019782(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001978a at 1001978a

void Unwind_1001978a(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10019792 at 10019792

void Unwind_10019792(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001979a at 1001979a

void Unwind_1001979a(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100197a2 at 100197a2

void Unwind_100197a2(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@100197aa at 100197aa

void Unwind_100197aa(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x78));
  return;
}



// Function: Unwind@100197b2 at 100197b2

void Unwind_100197b2(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100197ba at 100197ba

void Unwind_100197ba(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100197c2 at 100197c2

void Unwind_100197c2(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x78));
  return;
}



// Function: Unwind@100197ca at 100197ca

void Unwind_100197ca(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@100197d2 at 100197d2

void Unwind_100197d2(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x84));
  return;
}



// Function: Unwind@100197dd at 100197dd

void Unwind_100197dd(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x78));
  return;
}



// Function: Unwind@100197e5 at 100197e5

void Unwind_100197e5(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100197ed at 100197ed

void Unwind_100197ed(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100197f5 at 100197f5

void Unwind_100197f5(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100197fd at 100197fd

void Unwind_100197fd(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019805 at 10019805

void Unwind_10019805(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@1001980d at 1001980d

void Unwind_1001980d(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x84));
  return;
}



// Function: Unwind@10019818 at 10019818

void Unwind_10019818(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x78));
  return;
}



// Function: Unwind@10019820 at 10019820

void Unwind_10019820(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@10019850 at 10019850

void Unwind_10019850(void)

{
  int unaff_EBP;
  
  FUN_10007378((int *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@10019858 at 10019858

void Unwind_10019858(void)

{
  int unaff_EBP;
  
  FUN_10007378((int *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019860 at 10019860

void Unwind_10019860(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@1001986b at 1001986b

void Unwind_1001986b(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10019873 at 10019873

void Unwind_10019873(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001987b at 1001987b

void Unwind_1001987b(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019883 at 10019883

void Unwind_10019883(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x80));
  return;
}



// Function: Unwind@1001988b at 1001988b

void Unwind_1001988b(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10019893 at 10019893

void Unwind_10019893(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001989b at 1001989b

void Unwind_1001989b(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100198a3 at 100198a3

void Unwind_100198a3(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x74));
  return;
}



// Function: Unwind@100198ab at 100198ab

void Unwind_100198ab(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x80));
  return;
}



// Function: Unwind@100198b3 at 100198b3

void Unwind_100198b3(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x94));
  return;
}



// Function: Unwind@100198be at 100198be

void Unwind_100198be(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x74));
  return;
}



// Function: Unwind@100198c6 at 100198c6

void Unwind_100198c6(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100198ce at 100198ce

void Unwind_100198ce(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100198d6 at 100198d6

void Unwind_100198d6(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x80));
  return;
}



// Function: Unwind@100198de at 100198de

void Unwind_100198de(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x94));
  return;
}



// Function: Unwind@100198e9 at 100198e9

void Unwind_100198e9(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x74));
  return;
}



// Function: Unwind@100198f1 at 100198f1

void Unwind_100198f1(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10019921 at 10019921

void Unwind_10019921(void)

{
  int unaff_EBP;
  
  FUN_10007378((int *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10019929 at 10019929

void Unwind_10019929(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019931 at 10019931

void Unwind_10019931(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10019939 at 10019939

void Unwind_10019939(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019941 at 10019941

void Unwind_10019941(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019949 at 10019949

void Unwind_10019949(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@10019951 at 10019951

void Unwind_10019951(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x78));
  return;
}



// Function: Unwind@10019959 at 10019959

void Unwind_10019959(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10019961 at 10019961

void Unwind_10019961(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10019969 at 10019969

void Unwind_10019969(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x78));
  return;
}



// Function: Unwind@10019971 at 10019971

void Unwind_10019971(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@10019979 at 10019979

void Unwind_10019979(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x84));
  return;
}



// Function: Unwind@10019984 at 10019984

void Unwind_10019984(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x78));
  return;
}



// Function: Unwind@1001998c at 1001998c

void Unwind_1001998c(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10019994 at 10019994

void Unwind_10019994(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001999c at 1001999c

void Unwind_1001999c(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100199a4 at 100199a4

void Unwind_100199a4(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100199ac at 100199ac

void Unwind_100199ac(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@100199b4 at 100199b4

void Unwind_100199b4(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x84));
  return;
}



// Function: Unwind@100199bf at 100199bf

void Unwind_100199bf(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x78));
  return;
}



// Function: Unwind@100199c7 at 100199c7

void Unwind_100199c7(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@100199f7 at 100199f7

void Unwind_100199f7(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100199ff at 100199ff

void Unwind_100199ff(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019a07 at 10019a07

void Unwind_10019a07(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10019a0f at 10019a0f

void Unwind_10019a0f(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019a32 at 10019a32

void Unwind_10019a32(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019a3a at 10019a3a

void Unwind_10019a3a(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019a42 at 10019a42

void Unwind_10019a42(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10019a4a at 10019a4a

void Unwind_10019a4a(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019a6d at 10019a6d

void Unwind_10019a6d(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10019aa1 at 10019aa1

void Unwind_10019aa1(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x78) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x78) = *(uint *)(unaff_EBP + -0x78) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + -0x6c));
    return;
  }
  return;
}



// Function: Unwind@10019aba at 10019aba

void Unwind_10019aba(void)

{
  int unaff_EBP;
  
  FUN_10006d4b((int *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10019ac2 at 10019ac2

void Unwind_10019ac2(void)

{
  int unaff_EBP;
  
  FUN_10006d50((int *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10019aca at 10019aca

void Unwind_10019aca(void)

{
  int unaff_EBP;
  
  FUN_10006d50((int *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10019ad2 at 10019ad2

void Unwind_10019ad2(void)

{
  int unaff_EBP;
  
  FUN_10006d4b((int *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10019ada at 10019ada

void Unwind_10019ada(void)

{
  int unaff_EBP;
  
  FUN_1000749c((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10019ae2 at 10019ae2

void Unwind_10019ae2(void)

{
  int unaff_EBP;
  
  FUN_1000749c((int *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@10019aea at 10019aea

void Unwind_10019aea(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019af2 at 10019af2

void Unwind_10019af2(void)

{
  int unaff_EBP;
  
  FUN_10006d4b((int *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10019b1f at 10019b1f

void Unwind_10019b1f(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019b27 at 10019b27

void Unwind_10019b27(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019b2f at 10019b2f

void Unwind_10019b2f(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019b37 at 10019b37

void Unwind_10019b37(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -100));
  return;
}



// Function: Unwind@10019b3f at 10019b3f

void Unwind_10019b3f(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10019b47 at 10019b47

void Unwind_10019b47(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10019b4f at 10019b4f

void Unwind_10019b4f(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10019b7c at 10019b7c

void Unwind_10019b7c(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@10019b87 at 10019b87

void Unwind_10019b87(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@10019b92 at 10019b92

void Unwind_10019b92(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10019b9a at 10019b9a

void Unwind_10019b9a(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10019ba2 at 10019ba2

void Unwind_10019ba2(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x94));
  return;
}



// Function: Unwind@10019bad at 10019bad

void Unwind_10019bad(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x98));
  return;
}



// Function: Unwind@10019bb8 at 10019bb8

void Unwind_10019bb8(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019bc0 at 10019bc0

void Unwind_10019bc0(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019bc8 at 10019bc8

void Unwind_10019bc8(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x94));
  return;
}



// Function: Unwind@10019bd3 at 10019bd3

void Unwind_10019bd3(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019bdb at 10019bdb

void Unwind_10019bdb(void)

{
  int unaff_EBP;
  
  FUN_100074ce(unaff_EBP + -0x38);
  return;
}



// Function: Unwind@10019be3 at 10019be3

void Unwind_10019be3(void)

{
  int unaff_EBP;
  
  FUN_100074ce(*(int *)(unaff_EBP + -0x94));
  return;
}



// Function: Unwind@10019bee at 10019bee

void Unwind_10019bee(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@10019bf9 at 10019bf9

void Unwind_10019bf9(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x98));
  return;
}



// Function: Unwind@10019c04 at 10019c04

void Unwind_10019c04(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@10019c0f at 10019c0f

void Unwind_10019c0f(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@10019c1a at 10019c1a

void Unwind_10019c1a(void)

{
  int unaff_EBP;
  
  FUN_100074ce(*(int *)(unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@10019c25 at 10019c25

void Unwind_10019c25(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x94));
  return;
}



// Function: Unwind@10019c30 at 10019c30

void Unwind_10019c30(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@10019c3b at 10019c3b

void Unwind_10019c3b(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x98));
  return;
}



// Function: Unwind@10019c46 at 10019c46

void Unwind_10019c46(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x94));
  return;
}



// Function: Unwind@10019c51 at 10019c51

void Unwind_10019c51(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019c59 at 10019c59

void Unwind_10019c59(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10019c61 at 10019c61

void Unwind_10019c61(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019c69 at 10019c69

void Unwind_10019c69(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10019c71 at 10019c71

void Unwind_10019c71(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019c79 at 10019c79

void Unwind_10019c79(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10019c81 at 10019c81

void Unwind_10019c81(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019c89 at 10019c89

void Unwind_10019c89(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10019cb9 at 10019cb9

void Unwind_10019cb9(void)

{
  int unaff_EBP;
  
  FUN_10007378((int *)(unaff_EBP + -0x94));
  return;
}



// Function: Unwind@10019cc4 at 10019cc4

void Unwind_10019cc4(void)

{
  int unaff_EBP;
  
  FUN_10007378((int *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@10019ccf at 10019ccf

void Unwind_10019ccf(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + -0x98));
  return;
}



// Function: Unwind@10019cda at 10019cda

void Unwind_10019cda(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@10019ce5 at 10019ce5

void Unwind_10019ce5(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10019ced at 10019ced

void Unwind_10019ced(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10019cf5 at 10019cf5

void Unwind_10019cf5(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@10019d00 at 10019d00

void Unwind_10019d00(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xa4));
  return;
}



// Function: Unwind@10019d0b at 10019d0b

void Unwind_10019d0b(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019d13 at 10019d13

void Unwind_10019d13(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019d1b at 10019d1b

void Unwind_10019d1b(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@10019d26 at 10019d26

void Unwind_10019d26(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019d2e at 10019d2e

void Unwind_10019d2e(void)

{
  int unaff_EBP;
  
  FUN_100074ce(unaff_EBP + -0x38);
  return;
}



// Function: Unwind@10019d36 at 10019d36

void Unwind_10019d36(void)

{
  int unaff_EBP;
  
  FUN_100074ce(*(int *)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@10019d41 at 10019d41

void Unwind_10019d41(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@10019d4c at 10019d4c

void Unwind_10019d4c(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xa4));
  return;
}



// Function: Unwind@10019d57 at 10019d57

void Unwind_10019d57(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xb0));
  return;
}



// Function: Unwind@10019d62 at 10019d62

void Unwind_10019d62(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@10019d6d at 10019d6d

void Unwind_10019d6d(void)

{
  int unaff_EBP;
  
  FUN_100074ce(*(int *)(unaff_EBP + -0xb0));
  return;
}



// Function: Unwind@10019d78 at 10019d78

void Unwind_10019d78(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@10019d83 at 10019d83

void Unwind_10019d83(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@10019d8e at 10019d8e

void Unwind_10019d8e(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xa4));
  return;
}



// Function: Unwind@10019d99 at 10019d99

void Unwind_10019d99(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@10019da4 at 10019da4

void Unwind_10019da4(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019dac at 10019dac

void Unwind_10019dac(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10019db4 at 10019db4

void Unwind_10019db4(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019dbc at 10019dbc

void Unwind_10019dbc(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10019dc4 at 10019dc4

void Unwind_10019dc4(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019dcc at 10019dcc

void Unwind_10019dcc(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10019dd4 at 10019dd4

void Unwind_10019dd4(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019ddc at 10019ddc

void Unwind_10019ddc(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10019e0c at 10019e0c

void Unwind_10019e0c(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0xa4));
  return;
}



// Function: Unwind@10019e17 at 10019e17

void Unwind_10019e17(void)

{
  int unaff_EBP;
  
  FUN_10003b78((int *)(unaff_EBP + -0xa4));
  return;
}



// Function: Unwind@10019e22 at 10019e22

void Unwind_10019e22(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0xb4));
  return;
}



// Function: Unwind@10019e2d at 10019e2d

void Unwind_10019e2d(void)

{
  int unaff_EBP;
  
  FUN_10003b78((int *)(unaff_EBP + -0xb4));
  return;
}



// Function: Unwind@10019e38 at 10019e38

void Unwind_10019e38(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@10019e43 at 10019e43

void Unwind_10019e43(void)

{
  int unaff_EBP;
  
  FUN_10003b78((int *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@10019e4e at 10019e4e

void Unwind_10019e4e(void)

{
  int unaff_EBP;
  
  FUN_1000258e((int *)(unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@10019e59 at 10019e59

void Unwind_10019e59(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + -0xc4));
  return;
}



// Function: Unwind@10019e64 at 10019e64

void Unwind_10019e64(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + -0xb8));
  return;
}



// Function: Unwind@10019e6f at 10019e6f

void Unwind_10019e6f(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + -0xc0));
  return;
}



// Function: Unwind@10019e7a at 10019e7a

void Unwind_10019e7a(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + -0xbc));
  return;
}



// Function: Unwind@10019e85 at 10019e85

void Unwind_10019e85(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10019e8d at 10019e8d

void Unwind_10019e8d(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019e95 at 10019e95

void Unwind_10019e95(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@10019e9d at 10019e9d

void Unwind_10019e9d(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@10019ea8 at 10019ea8

void Unwind_10019ea8(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10019eb0 at 10019eb0

void Unwind_10019eb0(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@10019ebb at 10019ebb

void Unwind_10019ebb(void)

{
  int unaff_EBP;
  
  FUN_100018e7(unaff_EBP + -0x20);
  return;
}



// Function: Unwind@10019ec3 at 10019ec3

void Unwind_10019ec3(void)

{
  int unaff_EBP;
  
  FUN_10001567((undefined4 *)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@10019ece at 10019ece

void Unwind_10019ece(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019ed6 at 10019ed6

void Unwind_10019ed6(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019ede at 10019ede

void Unwind_10019ede(void)

{
  int unaff_EBP;
  
  FUN_10001567(*(undefined4 **)(unaff_EBP + -0xb0));
  return;
}



// Function: Unwind@10019ee9 at 10019ee9

void Unwind_10019ee9(void)

{
  int unaff_EBP;
  
  FUN_10001567(*(undefined4 **)(unaff_EBP + -0xb0));
  return;
}



// Function: Unwind@10019ef4 at 10019ef4

void Unwind_10019ef4(void)

{
  int unaff_EBP;
  
  FUN_10001567(*(undefined4 **)(unaff_EBP + -0xb0));
  return;
}



// Function: Unwind@10019eff at 10019eff

void Unwind_10019eff(void)

{
  int unaff_EBP;
  
  FUN_10001567(*(undefined4 **)(unaff_EBP + -0xb0));
  return;
}



// Function: Unwind@10019f0a at 10019f0a

void Unwind_10019f0a(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@10019f15 at 10019f15

void Unwind_10019f15(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10019f1d at 10019f1d

void Unwind_10019f1d(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10019f25 at 10019f25

void Unwind_10019f25(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@10019f30 at 10019f30

void Unwind_10019f30(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xb0));
  return;
}



// Function: Unwind@10019f3b at 10019f3b

void Unwind_10019f3b(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10019f43 at 10019f43

void Unwind_10019f43(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019f4b at 10019f4b

void Unwind_10019f4b(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@10019f56 at 10019f56

void Unwind_10019f56(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0xb4));
  return;
}



// Function: Unwind@10019f61 at 10019f61

void Unwind_10019f61(void)

{
  int unaff_EBP;
  
  FUN_1000230d((int *)(unaff_EBP + -0xa4));
  return;
}



// Function: Unwind@10019f94 at 10019f94

void Unwind_10019f94(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@10019f9f at 10019f9f

void Unwind_10019f9f(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xdc));
  return;
}



// Function: Unwind@10019faa at 10019faa

void Unwind_10019faa(void)

{
  FUN_1000dc40();
  return;
}



// Function: Unwind@10019fb5 at 10019fb5

void Unwind_10019fb5(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@10019fc0 at 10019fc0

void Unwind_10019fc0(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10019fc8 at 10019fc8

void Unwind_10019fc8(void)

{
  int unaff_EBP;
  
  FUN_100074ce(unaff_EBP + -0x58);
  return;
}



// Function: Unwind@10019fd0 at 10019fd0

void Unwind_10019fd0(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xdc));
  return;
}



// Function: Unwind@10019fdb at 10019fdb

void Unwind_10019fdb(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@10019fe6 at 10019fe6

void Unwind_10019fe6(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@10019ff1 at 10019ff1

void Unwind_10019ff1(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xdc));
  return;
}



// Function: Unwind@10019ffc at 10019ffc

void Unwind_10019ffc(void)

{
  int unaff_EBP;
  
  FUN_1000755b((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0xcc));
  return;
}



// Function: Unwind@1001a007 at 1001a007

void Unwind_1001a007(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@1001a012 at 1001a012

void Unwind_1001a012(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a01a at 1001a01a

void Unwind_1001a01a(void)

{
  int unaff_EBP;
  
  FUN_100074ce(unaff_EBP + -0x34);
  return;
}



// Function: Unwind@1001a022 at 1001a022

void Unwind_1001a022(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@1001a02d at 1001a02d

void Unwind_1001a02d(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@1001a038 at 1001a038

void Unwind_1001a038(void)

{
  int unaff_EBP;
  
  FUN_100074ce(*(int *)(unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@1001a043 at 1001a043

void Unwind_1001a043(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xdc));
  return;
}



// Function: Unwind@1001a04e at 1001a04e

void Unwind_1001a04e(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@1001a059 at 1001a059

void Unwind_1001a059(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@1001a064 at 1001a064

void Unwind_1001a064(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xdc));
  return;
}



// Function: Unwind@1001a06f at 1001a06f

void Unwind_1001a06f(void)

{
  int unaff_EBP;
  
  FUN_100074ce(*(int *)(unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@1001a07a at 1001a07a

void Unwind_1001a07a(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@1001a085 at 1001a085

void Unwind_1001a085(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@1001a090 at 1001a090

void Unwind_1001a090(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xdc));
  return;
}



// Function: Unwind@1001a09b at 1001a09b

void Unwind_1001a09b(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@1001a0a6 at 1001a0a6

void Unwind_1001a0a6(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@1001a0b1 at 1001a0b1

void Unwind_1001a0b1(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@1001a0bc at 1001a0bc

void Unwind_1001a0bc(void)

{
  int unaff_EBP;
  
  FUN_100074ce(*(int *)(unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@1001a0c7 at 1001a0c7

void Unwind_1001a0c7(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@1001a0d2 at 1001a0d2

void Unwind_1001a0d2(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@1001a0dd at 1001a0dd

void Unwind_1001a0dd(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xdc));
  return;
}



// Function: Unwind@1001a0e8 at 1001a0e8

void Unwind_1001a0e8(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@1001a0f3 at 1001a0f3

void Unwind_1001a0f3(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@1001a0fe at 1001a0fe

void Unwind_1001a0fe(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@1001a109 at 1001a109

void Unwind_1001a109(void)

{
  int unaff_EBP;
  
  FUN_100074ce(*(int *)(unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@1001a114 at 1001a114

void Unwind_1001a114(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@1001a11f at 1001a11f

void Unwind_1001a11f(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@1001a12a at 1001a12a

void Unwind_1001a12a(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xdc));
  return;
}



// Function: Unwind@1001a135 at 1001a135

void Unwind_1001a135(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@1001a140 at 1001a140

void Unwind_1001a140(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@1001a14b at 1001a14b

void Unwind_1001a14b(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@1001a156 at 1001a156

void Unwind_1001a156(void)

{
  int unaff_EBP;
  
  FUN_100074ce(*(int *)(unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@1001a161 at 1001a161

void Unwind_1001a161(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@1001a16c at 1001a16c

void Unwind_1001a16c(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@1001a177 at 1001a177

void Unwind_1001a177(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xdc));
  return;
}



// Function: Unwind@1001a182 at 1001a182

void Unwind_1001a182(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@1001a18d at 1001a18d

void Unwind_1001a18d(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@1001a198 at 1001a198

void Unwind_1001a198(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@1001a1a3 at 1001a1a3

void Unwind_1001a1a3(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@1001a1ae at 1001a1ae

void Unwind_1001a1ae(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@1001a1e1 at 1001a1e1

void Unwind_1001a1e1(void)

{
  int unaff_EBP;
  
  FUN_100035d2((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001a1ec at 1001a1ec

void Unwind_1001a1ec(void)

{
  int unaff_EBP;
  
  FUN_10003f16(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001a212 at 1001a212

void Unwind_1001a212(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_1002673c);
  return;
}



// Function: Unwind@1001a237 at 1001a237

void Unwind_1001a237(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_10026758);
  return;
}



// Function: Unwind@1001a25c at 1001a25c

void Unwind_1001a25c(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_10026774);
  return;
}



// Function: Unwind@1001a281 at 1001a281

void Unwind_1001a281(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_10026790);
  return;
}



// Function: Unwind@1001a2a6 at 1001a2a6

void Unwind_1001a2a6(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_100267ac);
  return;
}



// Function: Unwind@1001a2cb at 1001a2cb

void Unwind_1001a2cb(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_100267c8);
  return;
}



// Function: Unwind@1001a2f0 at 1001a2f0

void Unwind_1001a2f0(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_100268a8);
  return;
}



// Function: Unwind@1001a315 at 1001a315

void Unwind_1001a315(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_100267e4);
  return;
}



// Function: Unwind@1001a33a at 1001a33a

void Unwind_1001a33a(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_10026800);
  return;
}



// Function: Unwind@1001a35f at 1001a35f

void Unwind_1001a35f(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_1002681c);
  return;
}



// Function: Unwind@1001a384 at 1001a384

void Unwind_1001a384(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_10026838);
  return;
}



// Function: Unwind@1001a3a9 at 1001a3a9

void Unwind_1001a3a9(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_10026854);
  return;
}



// Function: Unwind@1001a3ce at 1001a3ce

void Unwind_1001a3ce(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_10026870);
  return;
}



// Function: Unwind@1001a3f3 at 1001a3f3

void Unwind_1001a3f3(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_1002688c);
  return;
}



// Function: Unwind@1001a418 at 1001a418

void Unwind_1001a418(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_100268c4);
  return;
}



// Function: Unwind@1001a43d at 1001a43d

void Unwind_1001a43d(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_100268e0);
  return;
}



// Function: Unwind@1001a462 at 1001a462

void Unwind_1001a462(void)

{
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_100268fc);
  return;
}



// Function: Unwind@1001a490 at 1001a490

void Unwind_1001a490(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a4c0 at 1001a4c0

void Unwind_1001a4c0(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 0x24));
  return;
}



// Function: Unwind@1001a4c8 at 1001a4c8

void Unwind_1001a4c8(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a4d0 at 1001a4d0

void Unwind_1001a4d0(void)

{
  int unaff_EBP;
  
  FUN_1000de90((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a500 at 1001a500

void Unwind_1001a500(void)

{
  int unaff_EBP;
  
  FUN_100074ce(unaff_EBP + 0x40);
  return;
}



// Function: Unwind@1001a508 at 1001a508

void Unwind_1001a508(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 0x24));
  return;
}



// Function: Unwind@1001a510 at 1001a510

void Unwind_1001a510(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a518 at 1001a518

void Unwind_1001a518(void)

{
  int unaff_EBP;
  
  FUN_1000de90((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a520 at 1001a520

void Unwind_1001a520(void)

{
  int unaff_EBP;
  
  FUN_100074ce(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a550 at 1001a550

void Unwind_1001a550(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 0x24));
  return;
}



// Function: Unwind@1001a558 at 1001a558

void Unwind_1001a558(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a560 at 1001a560

void Unwind_1001a560(void)

{
  int unaff_EBP;
  
  FUN_1000de90((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001a568 at 1001a568

void Unwind_1001a568(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a590 at 1001a590

void Unwind_1001a590(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 0x24));
  return;
}



// Function: Unwind@1001a598 at 1001a598

void Unwind_1001a598(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a5a0 at 1001a5a0

void Unwind_1001a5a0(void)

{
  int unaff_EBP;
  
  FUN_1000de90((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a5d0 at 1001a5d0

void Unwind_1001a5d0(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a600 at 1001a600

void Unwind_1001a600(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a608 at 1001a608

void Unwind_1001a608(void)

{
  int unaff_EBP;
  
  FUN_1000de90((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a610 at 1001a610

void Unwind_1001a610(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001a640 at 1001a640

void Unwind_1001a640(void)

{
  int unaff_EBP;
  
  FUN_1000ed20(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a648 at 1001a648

void Unwind_1001a648(void)

{
  int unaff_EBP;
  
  FUN_1000df90(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a670 at 1001a670

void Unwind_1001a670(void)

{
  int unaff_EBP;
  
  FUN_10013310((undefined4 *)(*(int *)(unaff_EBP + -0x70) + 4));
  return;
}



// Function: Unwind@1001a67b at 1001a67b

void Unwind_1001a67b(void)

{
  int unaff_EBP;
  
  FUN_1000d220((void *)(*(int *)(unaff_EBP + -0x70) + 8));
  return;
}



// Function: Unwind@1001a686 at 1001a686

void Unwind_1001a686(void)

{
  int unaff_EBP;
  
  FUN_1000de90((undefined4 *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@1001a68e at 1001a68e

void Unwind_1001a68e(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@1001a699 at 1001a699

void Unwind_1001a699(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001a6a4 at 1001a6a4

void Unwind_1001a6a4(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -100));
  return;
}



// Function: Unwind@1001a6ac at 1001a6ac

void Unwind_1001a6ac(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -100));
  return;
}



// Function: Unwind@1001a6b4 at 1001a6b4

void Unwind_1001a6b4(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -100));
  return;
}



// Function: Unwind@1001a6bc at 1001a6bc

void Unwind_1001a6bc(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -100));
  return;
}



// Function: Unwind@1001a6c4 at 1001a6c4

void Unwind_1001a6c4(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -100));
  return;
}



// Function: Unwind@1001a6cc at 1001a6cc

void Unwind_1001a6cc(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001a6d4 at 1001a6d4

void Unwind_1001a6d4(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1001a710 at 1001a710

void Unwind_1001a710(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a713. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a719 at 1001a719

void Unwind_1001a719(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001a740 at 1001a740

void Unwind_1001a740(void)

{
  int unaff_EBP;
  
  FUN_10013310((undefined4 *)(*(int *)(unaff_EBP + -0x20) + 4));
  return;
}



// Function: Unwind@1001a74b at 1001a74b

void Unwind_1001a74b(void)

{
  int unaff_EBP;
  
  FUN_1000d220((void *)(*(int *)(unaff_EBP + -0x20) + 8));
  return;
}



// Function: Unwind@1001a756 at 1001a756

void Unwind_1001a756(void)

{
  int unaff_EBP;
  
  FUN_1000de90((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a75e at 1001a75e

void Unwind_1001a75e(void)

{
  int unaff_EBP;
  
  FUN_1000ed20(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a766 at 1001a766

void Unwind_1001a766(void)

{
  int unaff_EBP;
  
  FUN_1000df90(*(int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a790 at 1001a790

void Unwind_1001a790(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a7c0 at 1001a7c0

void Unwind_1001a7c0(void)

{
  int unaff_EBP;
  
  FUN_1000de90((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001a7c8 at 1001a7c8

void Unwind_1001a7c8(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a7d0 at 1001a7d0

void Unwind_1001a7d0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1001a7db at 1001a7db

void Unwind_1001a7db(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001a7e3 at 1001a7e3

void Unwind_1001a7e3(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x74));
  return;
}



// Function: Unwind@1001a810 at 1001a810

void Unwind_1001a810(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a818 at 1001a818

void Unwind_1001a818(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a840 at 1001a840

void Unwind_1001a840(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a843. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001a849 at 1001a849

void Unwind_1001a849(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001a851 at 1001a851

void Unwind_1001a851(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (*(int *)(unaff_EBP + -0x38) + 0xc));
  return;
}



// Function: Unwind@1001a85c at 1001a85c

void Unwind_1001a85c(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001a864 at 1001a864

void Unwind_1001a864(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (*(int *)(unaff_EBP + -0x38) + 0x28));
  return;
}



// Function: Unwind@1001a8a0 at 1001a8a0

void Unwind_1001a8a0(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a8d0 at 1001a8d0

void Unwind_1001a8d0(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a900 at 1001a900

void Unwind_1001a900(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a930 at 1001a930

void Unwind_1001a930(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a960 at 1001a960

void Unwind_1001a960(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a990 at 1001a990

void Unwind_1001a990(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a9c0 at 1001a9c0

void Unwind_1001a9c0(void)

{
  FUN_1000dc40();
  return;
}



// Function: Unwind@1001a9f0 at 1001a9f0

void Unwind_1001a9f0(void)

{
  int unaff_EBP;
  
  FUN_1000ba10((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001aa20 at 1001aa20

void Unwind_1001aa20(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 0x24));
  return;
}



// Function: Unwind@1001aa28 at 1001aa28

void Unwind_1001aa28(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 8));
  return;
}



// Function: Unwind@1001aa30 at 1001aa30

void Unwind_1001aa30(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001aa3b at 1001aa3b

void Unwind_1001aa3b(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001aa43 at 1001aa43

void Unwind_1001aa43(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001aa4b at 1001aa4b

void Unwind_1001aa4b(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001aa53 at 1001aa53

void Unwind_1001aa53(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001aa80 at 1001aa80

void Unwind_1001aa80(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 8));
  return;
}



// Function: Unwind@1001aa88 at 1001aa88

void Unwind_1001aa88(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x100));
  return;
}



// Function: Unwind@1001aa93 at 1001aa93

void Unwind_1001aa93(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1001aa9e at 1001aa9e

void Unwind_1001aa9e(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0xe4));
  return;
}



// Function: Unwind@1001aaa9 at 1001aaa9

void Unwind_1001aaa9(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1001aab4 at 1001aab4

void Unwind_1001aab4(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -200));
  return;
}



// Function: Unwind@1001aabf at 1001aabf

void Unwind_1001aabf(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1001aaca at 1001aaca

void Unwind_1001aaca(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x108));
  return;
}



// Function: Unwind@1001aad8 at 1001aad8

void Unwind_1001aad8(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x114));
  return;
}



// Function: Unwind@1001aae3 at 1001aae3

void Unwind_1001aae3(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x110));
  return;
}



// Function: Unwind@1001aaee at 1001aaee

void Unwind_1001aaee(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x118));
  return;
}



// Function: Unwind@1001aaf9 at 1001aaf9

void Unwind_1001aaf9(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1001ab30 at 1001ab30

void Unwind_1001ab30(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 8));
  return;
}



// Function: Unwind@1001ab38 at 1001ab38

void Unwind_1001ab38(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1001ab43 at 1001ab43

void Unwind_1001ab43(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -200));
  return;
}



// Function: Unwind@1001ab4e at 1001ab4e

void Unwind_1001ab4e(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@1001ab5c at 1001ab5c

void Unwind_1001ab5c(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xcc));
  return;
}



// Function: Unwind@1001ab67 at 1001ab67

void Unwind_1001ab67(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xdc));
  return;
}



// Function: Unwind@1001ab72 at 1001ab72

void Unwind_1001ab72(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@1001ab7d at 1001ab7d

void Unwind_1001ab7d(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -200));
  return;
}



// Function: Unwind@1001abb0 at 1001abb0

void Unwind_1001abb0(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 0x40));
  return;
}



// Function: Unwind@1001abb8 at 1001abb8

void Unwind_1001abb8(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 0x24));
  return;
}



// Function: Unwind@1001abc0 at 1001abc0

void Unwind_1001abc0(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 8));
  return;
}



// Function: Unwind@1001abc8 at 1001abc8

void Unwind_1001abc8(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001abd3 at 1001abd3

void Unwind_1001abd3(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001abdb at 1001abdb

void Unwind_1001abdb(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001abe3 at 1001abe3

void Unwind_1001abe3(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001abeb at 1001abeb

void Unwind_1001abeb(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001ac10 at 1001ac10

void Unwind_1001ac10(void)

{
  int unaff_EBP;
  
  FUN_100074ce(unaff_EBP + 0x24);
  return;
}



// Function: Unwind@1001ac18 at 1001ac18

void Unwind_1001ac18(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 8));
  return;
}



// Function: Unwind@1001ac20 at 1001ac20

void Unwind_1001ac20(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001ac28 at 1001ac28

void Unwind_1001ac28(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001ac33 at 1001ac33

void Unwind_1001ac33(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001ac3b at 1001ac3b

void Unwind_1001ac3b(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1001ac70 at 1001ac70

void Unwind_1001ac70(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 8));
  return;
}



// Function: Unwind@1001ac78 at 1001ac78

void Unwind_1001ac78(void)

{
  int unaff_EBP;
  
  FUN_1000deb0(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ac80 at 1001ac80

void Unwind_1001ac80(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001acb0 at 1001acb0

void Unwind_1001acb0(void)

{
  int unaff_EBP;
  
  FUN_1000deb0(*(undefined4 **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001acb8 at 1001acb8

void Unwind_1001acb8(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (*(int *)(unaff_EBP + -0x38) + 4));
  return;
}



// Function: Unwind@1001acc3 at 1001acc3

void Unwind_1001acc3(void)

{
  int unaff_EBP;
  
  FUN_1000d220((void *)(*(int *)(unaff_EBP + -0x38) + 0x24));
  return;
}



// Function: Unwind@1001acce at 1001acce

void Unwind_1001acce(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@1001acd9 at 1001acd9

void Unwind_1001acd9(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001ace1 at 1001ace1

void Unwind_1001ace1(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1001ad10 at 1001ad10

void Unwind_1001ad10(void)

{
  int unaff_EBP;
  
  FUN_1000deb0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001ad18 at 1001ad18

void Unwind_1001ad18(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1001ad23 at 1001ad23

void Unwind_1001ad23(void)

{
  int unaff_EBP;
  
  FUN_1000d220((void *)(*(int *)(unaff_EBP + -0x18) + 0x24));
  return;
}



// Function: Unwind@1001ad2e at 1001ad2e

void Unwind_1001ad2e(void)

{
  int unaff_EBP;
  
  FUN_1000ed20(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ad36 at 1001ad36

void Unwind_1001ad36(void)

{
  int unaff_EBP;
  
  FUN_1000df90(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ad60 at 1001ad60

void Unwind_1001ad60(void)

{
  int unaff_EBP;
  
  FUN_10010900(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ad90 at 1001ad90

void Unwind_1001ad90(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001ad98 at 1001ad98

void Unwind_1001ad98(void)

{
  int unaff_EBP;
  
  FUN_100074ce(unaff_EBP + -0x34);
  return;
}



// Function: Unwind@1001ada0 at 1001ada0

void Unwind_1001ada0(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001ada8 at 1001ada8

void Unwind_1001ada8(void)

{
  int unaff_EBP;
  
  FUN_100074ce(*(int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001adb0 at 1001adb0

void Unwind_1001adb0(void)

{
  int unaff_EBP;
  
  FUN_100074ce(*(int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001ade0 at 1001ade0

void Unwind_1001ade0(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001ade8 at 1001ade8

void Unwind_1001ade8(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001adf0 at 1001adf0

void Unwind_1001adf0(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -100));
  return;
}



// Function: Unwind@1001adf8 at 1001adf8

void Unwind_1001adf8(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -100));
  return;
}



// Function: Unwind@1001ae00 at 1001ae00

void Unwind_1001ae00(void)

{
  int unaff_EBP;
  
  FUN_100074ce(unaff_EBP + -0xa4);
  return;
}



// Function: Unwind@1001ae0b at 1001ae0b

void Unwind_1001ae0b(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001ae13 at 1001ae13

void Unwind_1001ae13(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x80));
  return;
}



// Function: Unwind@1001ae50 at 1001ae50

void Unwind_1001ae50(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001ae58 at 1001ae58

void Unwind_1001ae58(void)

{
  int unaff_EBP;
  
  FUN_10010760((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001ae60 at 1001ae60

void Unwind_1001ae60(void)

{
  int unaff_EBP;
  
  FUN_100074ce(unaff_EBP + -0x34);
  return;
}



// Function: Unwind@1001ae68 at 1001ae68

void Unwind_1001ae68(void)

{
  int unaff_EBP;
  
  FUN_100074ce(*(int *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@1001aea0 at 1001aea0

void Unwind_1001aea0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x238) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x238) = *(uint *)(unaff_EBP + -0x238) & 0xfffffffe;
    FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  (unaff_EBP + -0x240));
    return;
  }
  return;
}



// Function: Unwind@1001aec2 at 1001aec2

void Unwind_1001aec2(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x234));
  return;
}



// Function: Unwind@1001af00 at 1001af00

void Unwind_1001af00(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001af08 at 1001af08

void Unwind_1001af08(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x4c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x4c) = *(uint *)(unaff_EBP + -0x4c) & 0xfffffffe;
    FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  (unaff_EBP + -0x50));
    return;
  }
  return;
}



// Function: Unwind@1001af21 at 1001af21

void Unwind_1001af21(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001af29 at 1001af29

void Unwind_1001af29(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001af60 at 1001af60

void Unwind_1001af60(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001af68 at 1001af68

void Unwind_1001af68(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001af70 at 1001af70

void Unwind_1001af70(void)

{
  int unaff_EBP;
  
  FUN_1000de90((undefined4 *)(unaff_EBP + -0x100a8));
  return;
}



// Function: Unwind@1001af7b at 1001af7b

void Unwind_1001af7b(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001af83 at 1001af83

void Unwind_1001af83(void)

{
  int unaff_EBP;
  
  FUN_10011a90(unaff_EBP + -0x10090);
  return;
}



// Function: Unwind@1001afc0 at 1001afc0

void Unwind_1001afc0(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001afc8 at 1001afc8

void Unwind_1001afc8(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001afd0 at 1001afd0

void Unwind_1001afd0(void)

{
  int unaff_EBP;
  
  FUN_1000de90((undefined4 *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@1001afd8 at 1001afd8

void Unwind_1001afd8(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -100));
  return;
}



// Function: Unwind@1001afe0 at 1001afe0

void Unwind_1001afe0(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001afe8 at 1001afe8

void Unwind_1001afe8(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b020 at 1001b020

void Unwind_1001b020(void)

{
  int unaff_EBP;
  
  FUN_100074ce(unaff_EBP + 8);
  return;
}



// Function: Unwind@1001b028 at 1001b028

void Unwind_1001b028(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -200));
  return;
}



// Function: Unwind@1001b033 at 1001b033

void Unwind_1001b033(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0xe4));
  return;
}



// Function: Unwind@1001b03e at 1001b03e

void Unwind_1001b03e(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1001b080 at 1001b080

void Unwind_1001b080(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@1001b08b at 1001b08b

void Unwind_1001b08b(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x80));
  return;
}



// Function: Unwind@1001b093 at 1001b093

void Unwind_1001b093(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0xb8));
  return;
}



// Function: Unwind@1001b09e at 1001b09e

void Unwind_1001b09e(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b0a6 at 1001b0a6

void Unwind_1001b0a6(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@1001b0b1 at 1001b0b1

void Unwind_1001b0b1(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001b0b9 at 1001b0b9

void Unwind_1001b0b9(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0xb8));
  return;
}



// Function: Unwind@1001b0c4 at 1001b0c4

void Unwind_1001b0c4(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -100));
  return;
}



// Function: Unwind@1001b0cc at 1001b0cc

void Unwind_1001b0cc(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@1001b100 at 1001b100

void Unwind_1001b100(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 0x24));
  return;
}



// Function: Unwind@1001b108 at 1001b108

void Unwind_1001b108(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b130 at 1001b130

void Unwind_1001b130(void)

{
  FUN_1000dc40();
  return;
}



// Function: Unwind@1001b141 at 1001b141

void Unwind_1001b141(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001b190 at 1001b190

void Unwind_1001b190(void)

{
  FUN_1000dc40();
  return;
}



// Function: Unwind@1001b1a1 at 1001b1a1

void Unwind_1001b1a1(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001b1d0 at 1001b1d0

void Unwind_1001b1d0(void)

{
  int unaff_EBP;
  
  FUN_1000df90(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b200 at 1001b200

void Unwind_1001b200(void)

{
  int unaff_EBP;
  
  FUN_10014f10(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b208 at 1001b208

void Unwind_1001b208(void)

{
  int unaff_EBP;
  
  FUN_1000df90(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b230 at 1001b230

void Unwind_1001b230(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -100));
  return;
}



// Function: Unwind@1001b238 at 1001b238

void Unwind_1001b238(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001b240 at 1001b240

void Unwind_1001b240(void)

{
  int unaff_EBP;
  
  FUN_10013620((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001b270 at 1001b270

void Unwind_1001b270(void)

{
  int unaff_EBP;
  
  FUN_10014f70((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001b27b at 1001b27b

void Unwind_1001b27b(void)

{
  int unaff_EBP;
  
  FUN_10014f10(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b283 at 1001b283

void Unwind_1001b283(void)

{
  int unaff_EBP;
  
  FUN_1000df90(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b2b0 at 1001b2b0

void Unwind_1001b2b0(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 0x24));
  return;
}



// Function: Unwind@1001b2b8 at 1001b2b8

void Unwind_1001b2b8(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b2e0 at 1001b2e0

void Unwind_1001b2e0(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 0x60));
  return;
}



// Function: Unwind@1001b2e8 at 1001b2e8

void Unwind_1001b2e8(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 0x44));
  return;
}



// Function: Unwind@1001b2f0 at 1001b2f0

void Unwind_1001b2f0(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 0x24));
  return;
}



// Function: Unwind@1001b2f8 at 1001b2f8

void Unwind_1001b2f8(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b300 at 1001b300

void Unwind_1001b300(void)

{
  int unaff_EBP;
  
  FUN_10014f70((void *)(*(int *)(unaff_EBP + -0x74) + 4));
  return;
}



// Function: Unwind@1001b30b at 1001b30b

void Unwind_1001b30b(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001b313 at 1001b313

void Unwind_1001b313(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001b31b at 1001b31b

void Unwind_1001b31b(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b323 at 1001b323

void Unwind_1001b323(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001b32b at 1001b32b

void Unwind_1001b32b(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001b333 at 1001b333

void Unwind_1001b333(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b33b at 1001b33b

void Unwind_1001b33b(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001b343 at 1001b343

void Unwind_1001b343(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001b34b at 1001b34b

void Unwind_1001b34b(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b353 at 1001b353

void Unwind_1001b353(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b35b at 1001b35b

void Unwind_1001b35b(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001b363 at 1001b363

void Unwind_1001b363(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001b36b at 1001b36b

void Unwind_1001b36b(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b373 at 1001b373

void Unwind_1001b373(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b37b at 1001b37b

void Unwind_1001b37b(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b383 at 1001b383

void Unwind_1001b383(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001b38b at 1001b38b

void Unwind_1001b38b(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b393 at 1001b393

void Unwind_1001b393(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b39b at 1001b39b

void Unwind_1001b39b(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001b3d0 at 1001b3d0

void Unwind_1001b3d0(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 0x24));
  return;
}



// Function: Unwind@1001b3d8 at 1001b3d8

void Unwind_1001b3d8(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b3e0 at 1001b3e0

void Unwind_1001b3e0(void)

{
  int unaff_EBP;
  
  FUN_10014f70((void *)(*(int *)(unaff_EBP + -0x70) + 4));
  return;
}



// Function: Unwind@1001b3eb at 1001b3eb

void Unwind_1001b3eb(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001b3f3 at 1001b3f3

void Unwind_1001b3f3(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001b3fb at 1001b3fb

void Unwind_1001b3fb(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b403 at 1001b403

void Unwind_1001b403(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001b40b at 1001b40b

void Unwind_1001b40b(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001b413 at 1001b413

void Unwind_1001b413(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b41b at 1001b41b

void Unwind_1001b41b(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001b423 at 1001b423

void Unwind_1001b423(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001b42b at 1001b42b

void Unwind_1001b42b(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b433 at 1001b433

void Unwind_1001b433(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b43b at 1001b43b

void Unwind_1001b43b(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001b443 at 1001b443

void Unwind_1001b443(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001b44b at 1001b44b

void Unwind_1001b44b(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b453 at 1001b453

void Unwind_1001b453(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b45b at 1001b45b

void Unwind_1001b45b(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b463 at 1001b463

void Unwind_1001b463(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001b46b at 1001b46b

void Unwind_1001b46b(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b473 at 1001b473

void Unwind_1001b473(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b47b at 1001b47b

void Unwind_1001b47b(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001b4b0 at 1001b4b0

void Unwind_1001b4b0(void)

{
  int unaff_EBP;
  
  FUN_10014f70((void *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001b4e0 at 1001b4e0

void Unwind_1001b4e0(void)

{
  int unaff_EBP;
  
  FUN_100074ce(unaff_EBP + 8);
  return;
}



// Function: Unwind@1001b4e8 at 1001b4e8

void Unwind_1001b4e8(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -200));
  return;
}



// Function: Unwind@1001b4f3 at 1001b4f3

void Unwind_1001b4f3(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1001b4fe at 1001b4fe

void Unwind_1001b4fe(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x100));
  return;
}



// Function: Unwind@1001b509 at 1001b509

void Unwind_1001b509(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -200));
  return;
}



// Function: Unwind@1001b514 at 1001b514

void Unwind_1001b514(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0xe4));
  return;
}



// Function: Unwind@1001b51f at 1001b51f

void Unwind_1001b51f(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x154));
  return;
}



// Function: Unwind@1001b52a at 1001b52a

void Unwind_1001b52a(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x11c));
  return;
}



// Function: Unwind@1001b535 at 1001b535

void Unwind_1001b535(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x138));
  return;
}



// Function: Unwind@1001b540 at 1001b540

void Unwind_1001b540(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x15c));
  return;
}



// Function: Unwind@1001b54b at 1001b54b

void Unwind_1001b54b(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x138));
  return;
}



// Function: Unwind@1001b556 at 1001b556

void Unwind_1001b556(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x15c));
  return;
}



// Function: Unwind@1001b561 at 1001b561

void Unwind_1001b561(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -200));
  return;
}



// Function: Unwind@1001b56c at 1001b56c

void Unwind_1001b56c(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x138));
  return;
}



// Function: Unwind@1001b577 at 1001b577

void Unwind_1001b577(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x15c));
  return;
}



// Function: Unwind@1001b582 at 1001b582

void Unwind_1001b582(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -200));
  return;
}



// Function: Unwind@1001b58d at 1001b58d

void Unwind_1001b58d(void)

{
  int unaff_EBP;
  
  FUN_10001d72(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x15c));
  return;
}



// Function: Unwind@1001b5c0 at 1001b5c0

void Unwind_1001b5c0(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1001b5cb at 1001b5cb

void Unwind_1001b5cb(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@1001b5d3 at 1001b5d3

void Unwind_1001b5d3(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0xa4));
  return;
}



// Function: Unwind@1001b5de at 1001b5de

void Unwind_1001b5de(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1001b5e6 at 1001b5e6

void Unwind_1001b5e6(void)

{
  int unaff_EBP;
  
  FUN_100074ce(unaff_EBP + -0x34);
  return;
}



// Function: Unwind@1001b5ee at 1001b5ee

void Unwind_1001b5ee(void)

{
  int unaff_EBP;
  
  FUN_100060fa(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1001b630 at 1001b630

void Unwind_1001b630(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001b670 at 1001b670

void Unwind_1001b670(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b678 at 1001b678

void Unwind_1001b678(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1001b680 at 1001b680

void Unwind_1001b680(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b688 at 1001b688

void Unwind_1001b688(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001b6c0 at 1001b6c0

void Unwind_1001b6c0(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001b6c8 at 1001b6c8

void Unwind_1001b6c8(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b700 at 1001b700

void Unwind_1001b700(void)

{
  int unaff_EBP;
  
  FUN_10001d72((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001b708 at 1001b708

void Unwind_1001b708(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b740 at 1001b740

void Unwind_1001b740(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b770 at 1001b770

void Unwind_1001b770(void)

{
  int unaff_EBP;
  
  FUN_100060fa((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b79d at 1001b79d

void Unwind_1001b79d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001b7a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::_Lockit::~_Lockit((_Lockit *)(unaff_EBP + -0x10));
  return;
}



// Function: FUN_1001c7c0 at 1001c7c0

void FUN_1001c7c0(void)

{
  Ordinal_6(DAT_10026c94);
  return;
}



// Function: FUN_1001c7cd at 1001c7cd

void FUN_1001c7cd(void)

{
  Ordinal_6(DAT_10026db0);
  return;
}



// Function: FUN_1001c7da at 1001c7da

void FUN_1001c7da(void)

{
  Ordinal_6(DAT_10026db4);
  return;
}



// Function: FUN_1001c7e7 at 1001c7e7

void FUN_1001c7e7(void)

{
  FID_conflict__Tidy(&DAT_10026b98,'\x01',0);
  return;
}



// Function: FUN_1001c7f6 at 1001c7f6

void FUN_1001c7f6(void)

{
  FID_conflict__Tidy(&DAT_10026b7c,'\x01',0);
  return;
}



// Function: FUN_1001c805 at 1001c805

void FUN_1001c805(void)

{
  FID_conflict__Tidy(&DAT_10026b60,'\x01',0);
  return;
}



// Function: FUN_1001c814 at 1001c814

void FUN_1001c814(void)

{
  FID_conflict__Tidy(&DAT_10026d24,'\x01',0);
  return;
}



// Function: FUN_1001c823 at 1001c823

void FUN_1001c823(void)

{
  FID_conflict__Tidy(&DAT_10026c78,'\x01',0);
  return;
}



// Function: FUN_1001c832 at 1001c832

void FUN_1001c832(void)

{
  FID_conflict__Tidy(&DAT_10026d78,'\x01',0);
  return;
}



// Function: FUN_1001c841 at 1001c841

void FUN_1001c841(void)

{
  FID_conflict__Tidy(&DAT_10026bb4,'\x01',0);
  return;
}



// Function: FUN_1001c850 at 1001c850

void FUN_1001c850(void)

{
  FID_conflict__Tidy(&DAT_10026cd0,'\x01',0);
  return;
}



// Function: FUN_1001c85f at 1001c85f

void FUN_1001c85f(void)

{
  FID_conflict__Tidy(&DAT_10026d40,'\x01',0);
  return;
}



// Function: FUN_1001c86e at 1001c86e

void FUN_1001c86e(void)

{
  FID_conflict__Tidy(&DAT_10026d08,'\x01',0);
  return;
}



// Function: FUN_1001c87d at 1001c87d

void FUN_1001c87d(void)

{
  FID_conflict__Tidy(&DAT_10026d5c,'\x01',0);
  return;
}



// Function: FUN_1001c88c at 1001c88c

void FUN_1001c88c(void)

{
  FID_conflict__Tidy(&DAT_10026c98,'\x01',0);
  return;
}



// Function: FUN_1001c89b at 1001c89b

void FUN_1001c89b(void)

{
  FID_conflict__Tidy(&DAT_10026c5c,'\x01',0);
  return;
}



// Function: FUN_1001c8aa at 1001c8aa

void FUN_1001c8aa(void)

{
  FID_conflict__Tidy(&DAT_10026bd0,'\x01',0);
  return;
}



// Function: FUN_1001c8b9 at 1001c8b9

void FUN_1001c8b9(void)

{
  FID_conflict__Tidy(&DAT_10026cb4,'\x01',0);
  return;
}



// Function: FUN_1001c8c8 at 1001c8c8

void FUN_1001c8c8(void)

{
  FID_conflict__Tidy(&DAT_10026bec,'\x01',0);
  return;
}



// Function: FUN_1001c8d7 at 1001c8d7

void FUN_1001c8d7(void)

{
  FID_conflict__Tidy(&DAT_10026c24,'\x01',0);
  return;
}



// Function: FUN_1001c8e6 at 1001c8e6

void FUN_1001c8e6(void)

{
  FID_conflict__Tidy(&DAT_10026cec,'\x01',0);
  return;
}



// Function: FUN_1001c8f5 at 1001c8f5

void FUN_1001c8f5(void)

{
  FID_conflict__Tidy(&DAT_10026d94,'\x01',0);
  return;
}



// Function: FUN_1001c904 at 1001c904

void FUN_1001c904(void)

{
  FID_conflict__Tidy(&DAT_10026c08,'\x01',0);
  return;
}



// Function: FUN_1001c913 at 1001c913

void FUN_1001c913(void)

{
  FID_conflict__Tidy(&DAT_10026c40,'\x01',0);
  return;
}



// Function: FUN_1001c922 at 1001c922

void FUN_1001c922(void)

{
  Ordinal_6(DAT_10027004);
  return;
}



// Function: FUN_1001c92f at 1001c92f

void FUN_1001c92f(void)

{
  Ordinal_6(DAT_10027008);
  return;
}



// Function: FUN_1001c93c at 1001c93c

void FUN_1001c93c(void)

{
  Ordinal_6(DAT_1002700c);
  return;
}



// Function: FUN_1001c949 at 1001c949

void FUN_1001c949(void)

{
  FID_conflict__Tidy(&DAT_10026db8,'\x01',0);
  return;
}



// Function: FUN_1001c958 at 1001c958

void FUN_1001c958(void)

{
  FID_conflict__Tidy(&DAT_10026dd4,'\x01',0);
  return;
}



// Function: FUN_1001c967 at 1001c967

void FUN_1001c967(void)

{
  FID_conflict__Tidy(&DAT_10026df0,'\x01',0);
  return;
}



// Function: FUN_1001c976 at 1001c976

void FUN_1001c976(void)

{
  FID_conflict__Tidy(&DAT_10026e0c,'\x01',0);
  return;
}



// Function: FUN_1001c985 at 1001c985

void FUN_1001c985(void)

{
  FID_conflict__Tidy(&DAT_10026e28,'\x01',0);
  return;
}



// Function: FUN_1001c994 at 1001c994

void FUN_1001c994(void)

{
  FID_conflict__Tidy(&DAT_10026e44,'\x01',0);
  return;
}



// Function: FUN_1001c9a3 at 1001c9a3

void FUN_1001c9a3(void)

{
  FID_conflict__Tidy(&DAT_10026e60,'\x01',0);
  return;
}



// Function: FUN_1001c9b2 at 1001c9b2

void FUN_1001c9b2(void)

{
  FID_conflict__Tidy(&DAT_10026e7c,'\x01',0);
  return;
}



// Function: FUN_1001c9c1 at 1001c9c1

void FUN_1001c9c1(void)

{
  FID_conflict__Tidy(&DAT_10026e98,'\x01',0);
  return;
}



// Function: FUN_1001c9d0 at 1001c9d0

void FUN_1001c9d0(void)

{
  FID_conflict__Tidy(&DAT_10026eb4,'\x01',0);
  return;
}



// Function: FUN_1001c9df at 1001c9df

void FUN_1001c9df(void)

{
  FID_conflict__Tidy(&DAT_10026ed0,'\x01',0);
  return;
}



// Function: FUN_1001c9ee at 1001c9ee

void FUN_1001c9ee(void)

{
  FID_conflict__Tidy(&DAT_10026eec,'\x01',0);
  return;
}



// Function: FUN_1001c9fd at 1001c9fd

void FUN_1001c9fd(void)

{
  FID_conflict__Tidy(&DAT_10026f08,'\x01',0);
  return;
}



// Function: FUN_1001ca0c at 1001ca0c

void FUN_1001ca0c(void)

{
  FID_conflict__Tidy(&DAT_10026f24,'\x01',0);
  return;
}



// Function: FUN_1001ca1b at 1001ca1b

void FUN_1001ca1b(void)

{
  FID_conflict__Tidy(&DAT_10026f40,'\x01',0);
  return;
}



// Function: FUN_1001ca2a at 1001ca2a

void FUN_1001ca2a(void)

{
  FID_conflict__Tidy(&DAT_10026f5c,'\x01',0);
  return;
}



// Function: FUN_1001ca39 at 1001ca39

void FUN_1001ca39(void)

{
  FID_conflict__Tidy(&DAT_10026f78,'\x01',0);
  return;
}



// Function: FUN_1001ca48 at 1001ca48

void FUN_1001ca48(void)

{
  FID_conflict__Tidy(&DAT_10026f94,'\x01',0);
  return;
}



// Function: FUN_1001ca57 at 1001ca57

void FUN_1001ca57(void)

{
  FID_conflict__Tidy(&DAT_10026fb0,'\x01',0);
  return;
}



// Function: FUN_1001ca66 at 1001ca66

void FUN_1001ca66(void)

{
  FID_conflict__Tidy(&DAT_10026fcc,'\x01',0);
  return;
}



// Function: FUN_1001ca75 at 1001ca75

void FUN_1001ca75(void)

{
  FID_conflict__Tidy(&DAT_10026fe8,'\x01',0);
  return;
}



// Function: FUN_1001ca84 at 1001ca84

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ca84(void)

{
  _DAT_1002703c = ATL::CComModule::vftable;
  FUN_100037a5(0x1002703c);
  return;
}



// Function: FUN_1001caae at 1001caae

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001caae(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_100260f8,true,0);
  return;
}



// Function: FUN_1001cad2 at 1001cad2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cad2(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_10026114,true,0);
  return;
}



// Function: FUN_1001caf6 at 1001caf6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001caf6(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_10026130,true,0);
  return;
}



// Function: FUN_1001cb1a at 1001cb1a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cb1a(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_1002614c,true,0);
  return;
}



// Function: FUN_1001cb3e at 1001cb3e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cb3e(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_10026168,true,0);
  return;
}



// Function: FUN_1001cb62 at 1001cb62

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cb62(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_10026184,true,0);
  return;
}



// Function: FUN_1001cb86 at 1001cb86

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cb86(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_100261a0,true,0);
  return;
}



// Function: FUN_1001cbaa at 1001cbaa

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cbaa(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_100261bc,true,0);
  return;
}



// Function: FUN_1001cbce at 1001cbce

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cbce(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_100261d8,true,0);
  return;
}



// Function: FUN_1001cbf2 at 1001cbf2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cbf2(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_100261f4,true,0);
  return;
}



// Function: FUN_1001cc16 at 1001cc16

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cc16(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_10026210,true,0);
  return;
}



// Function: FUN_1001cc3a at 1001cc3a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cc3a(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_1002622c,true,0);
  return;
}



// Function: FUN_1001cc5e at 1001cc5e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cc5e(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_10026248,true,0);
  return;
}



// Function: FUN_1001cc82 at 1001cc82

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cc82(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_10026264,true,0);
  return;
}



// Function: FUN_1001cca6 at 1001cca6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cca6(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_10026280,true,0);
  return;
}



// Function: FUN_1001ccca at 1001ccca

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001ccca(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_1002629c,true,0);
  return;
}



// Function: FUN_1001ccee at 1001ccee

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001ccee(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_100262b8,true,0);
  return;
}



// Function: FUN_1001cd12 at 1001cd12

void FUN_1001cd12(void)

{
  Ordinal_6(DAT_100272b8);
  return;
}



// Function: FUN_1001cd1f at 1001cd1f

void FUN_1001cd1f(void)

{
  Ordinal_6(DAT_100272bc);
  return;
}



// Function: FUN_1001cd2c at 1001cd2c

void FUN_1001cd2c(void)

{
  Ordinal_6(DAT_100272c0);
  return;
}



// Function: FUN_1001cd39 at 1001cd39

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cd39(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_1002673c,true,0);
  return;
}



// Function: FUN_1001cd5d at 1001cd5d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cd5d(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_10026758,true,0);
  return;
}



// Function: FUN_1001cd81 at 1001cd81

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cd81(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_10026774,true,0);
  return;
}



// Function: FUN_1001cda5 at 1001cda5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cda5(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_10026790,true,0);
  return;
}



// Function: FUN_1001cdc9 at 1001cdc9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cdc9(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_100267ac,true,0);
  return;
}



// Function: FUN_1001cded at 1001cded

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cded(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_100267c8,true,0);
  return;
}



// Function: FUN_1001ce11 at 1001ce11

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001ce11(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_100267e4,true,0);
  return;
}



// Function: FUN_1001ce35 at 1001ce35

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001ce35(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_10026800,true,0);
  return;
}



// Function: FUN_1001ce59 at 1001ce59

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001ce59(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_1002681c,true,0);
  return;
}



// Function: FUN_1001ce7d at 1001ce7d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001ce7d(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_10026838,true,0);
  return;
}



// Function: FUN_1001cea1 at 1001cea1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cea1(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_10026854,true,0);
  return;
}



// Function: FUN_1001cec5 at 1001cec5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cec5(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_10026870,true,0);
  return;
}



// Function: FUN_1001cee9 at 1001cee9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cee9(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_1002688c,true,0);
  return;
}



// Function: FUN_1001cf0d at 1001cf0d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cf0d(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_100268a8,true,0);
  return;
}



// Function: FUN_1001cf31 at 1001cf31

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cf31(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_100268c4,true,0);
  return;
}



// Function: FUN_1001cf55 at 1001cf55

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cf55(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_100268e0,true,0);
  return;
}



// Function: FUN_1001cf79 at 1001cf79

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001cf79(void)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &DAT_100268fc,true,0);
  return;
}



// Function: FUN_1001cf9d at 1001cf9d

void FUN_1001cf9d(void)

{
  FID_conflict__Tidy(&DAT_1002706c,'\x01',0);
  return;
}



// Function: FUN_1001cfac at 1001cfac

void FUN_1001cfac(void)

{
  FID_conflict__Tidy(&DAT_10027088,'\x01',0);
  return;
}



// Function: FUN_1001cfbb at 1001cfbb

void FUN_1001cfbb(void)

{
  FID_conflict__Tidy(&DAT_100270a4,'\x01',0);
  return;
}



// Function: FUN_1001cfca at 1001cfca

void FUN_1001cfca(void)

{
  FID_conflict__Tidy(&DAT_100270c0,'\x01',0);
  return;
}



// Function: FUN_1001cfd9 at 1001cfd9

void FUN_1001cfd9(void)

{
  FID_conflict__Tidy(&DAT_100270dc,'\x01',0);
  return;
}



// Function: FUN_1001cfe8 at 1001cfe8

void FUN_1001cfe8(void)

{
  FID_conflict__Tidy(&DAT_100270f8,'\x01',0);
  return;
}



// Function: FUN_1001cff7 at 1001cff7

void FUN_1001cff7(void)

{
  FID_conflict__Tidy(&DAT_10027114,'\x01',0);
  return;
}



// Function: FUN_1001d006 at 1001d006

void FUN_1001d006(void)

{
  FID_conflict__Tidy(&DAT_10027130,'\x01',0);
  return;
}



// Function: FUN_1001d015 at 1001d015

void FUN_1001d015(void)

{
  FID_conflict__Tidy(&DAT_1002714c,'\x01',0);
  return;
}



// Function: FUN_1001d024 at 1001d024

void FUN_1001d024(void)

{
  FID_conflict__Tidy(&DAT_10027168,'\x01',0);
  return;
}



// Function: FUN_1001d033 at 1001d033

void FUN_1001d033(void)

{
  FID_conflict__Tidy(&DAT_10027184,'\x01',0);
  return;
}



// Function: FUN_1001d042 at 1001d042

void FUN_1001d042(void)

{
  FID_conflict__Tidy(&DAT_100271a0,'\x01',0);
  return;
}



// Function: FUN_1001d051 at 1001d051

void FUN_1001d051(void)

{
  FID_conflict__Tidy(&DAT_100271bc,'\x01',0);
  return;
}



// Function: FUN_1001d060 at 1001d060

void FUN_1001d060(void)

{
  FID_conflict__Tidy(&DAT_100271d8,'\x01',0);
  return;
}



// Function: FUN_1001d06f at 1001d06f

void FUN_1001d06f(void)

{
  FID_conflict__Tidy(&DAT_100271f4,'\x01',0);
  return;
}



// Function: FUN_1001d07e at 1001d07e

void FUN_1001d07e(void)

{
  FID_conflict__Tidy(&DAT_10027210,'\x01',0);
  return;
}



// Function: FUN_1001d08d at 1001d08d

void FUN_1001d08d(void)

{
  FID_conflict__Tidy(&DAT_1002722c,'\x01',0);
  return;
}



// Function: FUN_1001d09c at 1001d09c

void FUN_1001d09c(void)

{
  FID_conflict__Tidy(&DAT_10027248,'\x01',0);
  return;
}



// Function: FUN_1001d0ab at 1001d0ab

void FUN_1001d0ab(void)

{
  FID_conflict__Tidy(&DAT_10027264,'\x01',0);
  return;
}



// Function: FUN_1001d0ba at 1001d0ba

void FUN_1001d0ba(void)

{
  FID_conflict__Tidy(&DAT_10027280,'\x01',0);
  return;
}



// Function: FUN_1001d0c9 at 1001d0c9

void FUN_1001d0c9(void)

{
  FID_conflict__Tidy(&DAT_1002729c,'\x01',0);
  return;
}



// Function: FUN_1001d0d8 at 1001d0d8

void FUN_1001d0d8(void)

{
  FUN_1001708e((int *)&DAT_100272cc);
  return;
}



// Function: FUN_1001d0e2 at 1001d0e2

void FUN_1001d0e2(void)

{
  FUN_10017170(0x100272f4);
  return;
}



// Function: FUN_1001d0ec at 1001d0ec

void FUN_1001d0ec(void)

{
  FUN_100171e9();
  return;
}



