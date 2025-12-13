/*
 * Decompiled from: AddInFactory.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001000 at 10001000

undefined4 __fastcall FUN_10001000(int param_1)

{
  return *(undefined4 *)(param_1 + 0x24);
}



// Function: FUN_10001004 at 10001004

int __cdecl FUN_10001004(ushort *param_1,ushort *param_2,int param_3)

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



// Function: FUN_10001038 at 10001038

void FUN_10001038(undefined4 param_1)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&param_1,(ThrowInfo *)&DAT_100133e8);
}



// Function: FUN_10001050 at 10001050

void __fastcall FUN_10001050(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  
  puVar1 = (undefined4 *)*param_1;
  if (*(char *)((int)puVar1 + 0x45) != '\0') {
    *param_1 = puVar1[2];
    return;
  }
  piVar2 = (int *)*puVar1;
  if (*(char *)((int)*puVar1 + 0x45) == '\0') {
    do {
      piVar3 = piVar2;
      piVar2 = (int *)piVar3[2];
    } while (*(char *)(piVar3[2] + 0x45) == '\0');
  }
  else {
    for (piVar3 = (int *)puVar1[1]; (*(char *)((int)piVar3 + 0x45) == '\0' && (*param_1 == *piVar3))
        ; piVar3 = (int *)piVar3[1]) {
      *param_1 = (int)piVar3;
    }
    if (*(char *)(*param_1 + 0x45) != '\0') {
      return;
    }
  }
  *param_1 = (int)piVar3;
  return;
}



// Function: FID_conflict:RegOpenKeyExA at 10001096

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
                    /* WARNING: Could not recover jumptable at 0x100010df. Too many branches */
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



// Function: Close at 100010ed

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



// Function: Open at 10001108

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



// Function: FUN_1000117c at 1000117c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

exception * __thiscall FUN_1000117c(void *this,byte param_1)

{
  *(undefined ***)this = std::bad_alloc::vftable;
  std::exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (exception *)this;
}



// Function: FUN_100011b4 at 100011b4

void FUN_100011b4(void)

{
  return;
}



// Function: FID_conflict:_Inside at 100011b5

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



// Function: FUN_100011f1 at 100011f1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_100011f1(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x100011fd;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10013448);
}



// Function: FUN_10001282 at 10001282

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001282(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_100012a7 at 100012a7

void __thiscall FUN_100012a7(void *this,undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)((int)this + 4);
  piVar2 = (int *)*piVar1;
  if (piVar2 != (int *)0x0) {
    *piVar1 = 0;
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  (**(code **)*param_1)(param_1,&DAT_10011210,piVar1);
  return;
}



// Function: FUN_100012d0 at 100012d0

void __fastcall FUN_100012d0(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if (*(char *)(iVar3 + 0x45) == '\0') {
    piVar1 = *(int **)(iVar3 + 8);
    if (*(char *)((int)*(int **)(iVar3 + 8) + 0x45) == '\0') {
      do {
        piVar2 = piVar1;
        piVar1 = (int *)*piVar2;
      } while (*(char *)((int)piVar1 + 0x45) == '\0');
      *param_1 = (int)piVar2;
      return;
    }
    for (iVar3 = *(int *)(iVar3 + 4);
        (*(char *)(iVar3 + 0x45) == '\0' && (*param_1 == *(int *)(iVar3 + 8)));
        iVar3 = *(int *)(iVar3 + 4)) {
      *param_1 = iVar3;
    }
    *param_1 = iVar3;
  }
  return;
}



// Function: FUN_1000130b at 1000130b

void __thiscall FUN_1000130b(void *this,int param_1)

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



// Function: FUN_10001350 at 10001350

void __thiscall FUN_10001350(void *this,int *param_1)

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



// Function: FUN_10001397 at 10001397

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_10001397(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x100013a3;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10013448);
}



// Function: FUN_100013f6 at 100013f6

uint __thiscall FUN_100013f6(void *this,uint param_1,uint param_2,ushort *param_3,uint param_4)

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
  uVar1 = FUN_10001004((ushort *)((int)this + param_1 * 2),param_3,uVar1);
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



// Function: FUN_1000145a at 1000145a

LSTATUS __fastcall FUN_1000145a(undefined4 *param_1)

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



// Function: FID_conflict:_Tidy at 1000145f

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



// Function: FUN_100014a8 at 100014a8

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_100014a8(void *this,undefined4 param_1)

{
  LPCOLESTR lpsz;
  HRESULT HVar1;
  int *local_28;
  CLSID local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x100014b4;
  if (*(int *)((int)this + 0x24) == 1) {
    local_28 = (int *)0x0;
    local_8 = 1;
    lpsz = (LPCOLESTR)((int)this + 8);
    if (7 < *(uint *)((int)this + 0x1c)) {
      lpsz = *(LPCOLESTR *)lpsz;
    }
    HVar1 = CLSIDFromString(lpsz,&local_24);
    if (-1 < HVar1) {
      HVar1 = CoCreateInstance(&local_24,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10011200,&local_28);
      if (-1 < HVar1) {
        HVar1 = FUN_100012a7(this,local_28);
        if (-1 < HVar1) {
          HVar1 = (**(code **)(**(int **)((int)this + 4) + 0xc))(*(int **)((int)this + 4),param_1);
        }
      }
    }
    local_8 = 0xffffffff;
    if (local_28 != (int *)0x0) {
      (**(code **)(*local_28 + 8))(local_28);
    }
  }
  else {
    HVar1 = -0x7fffbffb;
  }
  if (-1 < HVar1) {
    *(undefined4 *)((int)this + 0x24) = 2;
  }
  FUN_1000dc87();
  return;
}



// Function: FUN_10001549 at 10001549

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10001549(void *this,undefined4 *param_1)

{
  *param_1 = 0;
  (**(code **)**(undefined4 **)((int)this + 4))
            (*(undefined4 **)((int)this + 4),&DAT_10011200,param_1);
  return param_1;
}



// Function: FUN_10001584 at 10001584

void __thiscall FUN_10001584(void *this,ushort *param_1)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 + 8);
  if (7 < *(uint *)(param_1 + 10)) {
    param_1 = *(ushort **)param_1;
  }
  FUN_100013f6(this,0,*(uint *)((int)this + 0x10),param_1,*puVar1);
  return;
}



// Function: FUN_100015a5 at 100015a5

void __thiscall FUN_100015a5(void *this,wchar_t *param_1)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_1);
  FUN_100013f6(this,0,*(uint *)((int)this + 0x10),(ushort *)param_1,sVar1);
  return;
}



// Function: FUN_100015ca at 100015ca

void __fastcall FUN_100015ca(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_10001397((char *)0x1);
  *puVar1 = *(undefined4 *)(param_1 + 4);
  puVar1[1] = *(undefined4 *)(param_1 + 4);
  puVar1[2] = *(undefined4 *)(param_1 + 4);
  *(undefined2 *)(puVar1 + 0x11) = 0;
  return;
}



// Function: ~basic_string<> at 100015f1

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



// Function: FUN_100015fb at 100015fb

undefined4 * __thiscall FUN_100015fb(void *this,uint param_1,uint param_2)

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



// Function: FUN_1000167c at 1000167c

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void __thiscall FUN_1000167c(void *this,uint param_1)

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
  FUN_100011f1((char *)(param_1 + 1));
  FUN_10001711();
  return;
}



// Function: Catch@100016e3 at 100016e3

undefined * Catch_100016e3(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_100011f1((char *)(iVar1 + 1));
  *(void **)(unaff_EBP + -0x18) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000170b;
}



// Function: FUN_10001711 at 10001711

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10001711(void)

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



// Function: Catch@1000175f at 1000175f

void Catch_1000175f(void)

{
  int unaff_EBP;
  
  FID_conflict__Tidy(*(void **)(unaff_EBP + -0x1c),'\x01',0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10001774 at 10001774

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001774(void *param_1)

{
  FID_conflict__Tidy((void *)((int)param_1 + 0x1c),'\x01',0);
  FID_conflict__Tidy(param_1,'\x01',0);
  return;
}



// Function: FUN_100017aa at 100017aa

int __fastcall FUN_100017aa(int param_1)

{
  void *pvVar1;
  
  *(undefined4 *)(param_1 + 8) = 0;
  pvVar1 = FUN_10001397((char *)0x1);
  *(void **)(param_1 + 4) = pvVar1;
  *(void **)pvVar1 = pvVar1;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x44) = 1;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x45) = 1;
  return param_1;
}



// Function: FUN_100017e1 at 100017e1

bool __thiscall FUN_100017e1(void *this,uint param_1,char param_2)

{
  uint uVar1;
  undefined4 *extraout_ECX;
  
  if (0x7ffffffe < param_1) {
    std::_Xlength_error("string too long");
    this = extraout_ECX;
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_1000167c(this,param_1);
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



// Function: FUN_1000184b at 1000184b

undefined4 * __thiscall FUN_1000184b(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    bVar1 = FUN_100017e1(this,uVar2,'\0');
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



// Function: FUN_100018f0 at 100018f0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100018f0(void *param_1)

{
  FUN_10001774(param_1);
  return;
}



// Function: FUN_1000190e at 1000190e

undefined4 * __thiscall FUN_1000190e(void *this,undefined4 *param_1,uint param_2)

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
      bVar1 = FUN_100017e1(this,uVar2,'\0');
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
    this = FUN_1000184b(this,(undefined4 *)this,(int)param_1 - (int)pvVar4 >> 1,param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_100019b0 at 100019b0

undefined4 * __thiscall FUN_100019b0(void *this,ushort *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)(*(undefined4 **)((int)this + 4))[1];
  puVar4 = *(undefined4 **)((int)this + 4);
  while (puVar3 = puVar1, *(char *)((int)puVar3 + 0x45) == '\0') {
    iVar2 = FUN_10001584(puVar3 + 3,param_1);
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



// Function: FUN_100019e5 at 100019e5

undefined4 * __thiscall FUN_100019e5(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    FUN_100015fb(pvVar3,uVar4 + uVar2,0xffffffff);
    FUN_100015fb(this,0,param_2);
  }
  else {
    bVar1 = FUN_100017e1(pvVar3,uVar4,'\0');
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



// Function: FID_conflict:assign at 10001a81

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
    bVar1 = FUN_100017e1(this,param_2,'\0');
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
    this = FUN_100019e5(this,(undefined4 *)this,(int)param_1 - (int)pvVar3 >> 1,param_2);
  }
  return (undefined4 *)this;
}



// Function: basic_string<> at 10001aff

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
  FUN_100019e5(this,param_1,0,0xffffffff);
  return (undefined2 *)this;
}



// Function: FUN_10001b27 at 10001b27

void __thiscall FUN_10001b27(void *this,undefined4 *param_1)

{
  FUN_100019e5((void *)((int)this + 8),param_1,0,0xffffffff);
  return;
}



// Function: FUN_10001b3d at 10001b3d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10001b3d(void *this,void *param_1)

{
  basic_string<>(param_1,(undefined4 *)((int)this + 8));
  return param_1;
}



// Function: FUN_10001b6f at 10001b6f

void __thiscall FUN_10001b6f(void *this,undefined4 *param_1,ushort *param_2)

{
  int iVar1;
  ushort **ppuVar2;
  ushort *local_8;
  
  local_8 = (ushort *)this;
  local_8 = (ushort *)FUN_100019b0(this,param_2);
  if (local_8 != *(ushort **)((int)this + 4)) {
    iVar1 = FUN_10001584(param_2,local_8 + 6);
    if (-1 < iVar1) {
      ppuVar2 = &local_8;
      goto LAB_10001ba4;
    }
  }
  ppuVar2 = &param_2;
LAB_10001ba4:
  *param_1 = *ppuVar2;
  return;
}



// Function: FUN_10001bb0 at 10001bb0

undefined2 * __thiscall FUN_10001bb0(void *this,wchar_t *param_1)

{
  size_t sVar1;
  
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)this = 0;
  sVar1 = wcslen(param_1);
  FID_conflict_assign(this,(undefined4 *)param_1,sVar1);
  return (undefined2 *)this;
}



// Function: FUN_10001be2 at 10001be2

undefined4 * __thiscall FUN_10001be2(void *this,undefined4 *param_1)

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



// Function: FUN_10001c3f at 10001c3f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10001c3f(void *this,void *param_1,ushort *param_2)

{
  FUN_10001b6f((void *)((int)this + 0x28),&param_2,param_2);
  if (param_2 == *(ushort **)((int)this + 0x2c)) {
    FUN_10001bb0(param_1,L"");
  }
  else {
    basic_string<>(param_1,(undefined4 *)(param_2 + 0x14));
  }
  return param_1;
}



// Function: FUN_10001c98 at 10001c98

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_10001c98(void *param_1)

{
  wchar_t *_Str;
  undefined1 local_4c [28];
  ushort local_30 [20];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0x10001ca4;
  FUN_10001bb0(local_30,L"LoadPriority");
  local_8 = 0;
  _Str = (wchar_t *)FUN_10001c3f(param_1,local_4c,local_30);
  local_8._0_1_ = 1;
  if (7 < *(uint *)(_Str + 10)) {
    _Str = *(wchar_t **)_Str;
  }
  _wtoi(_Str);
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__Tidy(local_4c,'\x01',0);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_1000dc87();
  return;
}



// Function: FUN_10001d04 at 10001d04

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __cdecl FUN_10001d04(undefined4 param_1,void *param_2)

{
  FUN_10001774(param_2);
  return;
}



// Function: FUN_10001d22 at 10001d22

void __thiscall
FUN_10001d22(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  uint extraout_EAX;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  uVar3 = *(uint *)((int)this + 8);
  if (0x4924922 < uVar3) {
    this = (void *)((int)this + 0xd);
    FUN_10001d04(this,param_4 + 3);
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
    if (*(char *)(iVar4 + 0x44) != '\0') {
      *(undefined1 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x44) = 1;
      *param_1 = param_4;
      return;
    }
    piVar1 = (int *)piVar5[1];
    piVar2 = (int *)piVar1[1];
    if (piVar1 == (int *)*piVar2) {
      iVar4 = piVar2[2];
      if (*(char *)(iVar4 + 0x44) == '\0') {
LAB_10001df1:
        *(undefined1 *)(piVar1 + 0x11) = 1;
        *(undefined1 *)(iVar4 + 0x44) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x44) = 0;
        piVar5 = *(int **)(piVar5[1] + 4);
      }
      else {
        if (piVar5 == (int *)piVar1[2]) {
          FUN_1000130b(this,(int)piVar1);
          piVar5 = piVar1;
        }
        *(undefined1 *)(piVar5[1] + 0x44) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x44) = 0;
        FUN_10001350(this,*(int **)(piVar5[1] + 4));
      }
    }
    else {
      iVar4 = *piVar2;
      if (*(char *)(iVar4 + 0x44) == '\0') goto LAB_10001df1;
      if (piVar5 == (int *)*piVar1) {
        FUN_10001350(this,piVar1);
        piVar5 = piVar1;
      }
      *(undefined1 *)(piVar5[1] + 0x44) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x44) = 0;
      FUN_1000130b(this,*(int *)(piVar5[1] + 4));
    }
    iVar4 = piVar5[1];
  } while( true );
}



// Function: basic_string<> at 10001e5a

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
  FUN_10001be2(this,param_1);
  return (undefined2 *)this;
}



// Function: FUN_10001e7f at 10001e7f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_10001e7f(void *param_1)

{
  void *this;
  undefined1 local_4c [28];
  ushort local_30 [20];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0x10001e8b;
  FUN_10001bb0(local_30,L"IsActive");
  local_8 = 0;
  this = FUN_10001c3f(param_1,local_4c,local_30);
  local_8._0_1_ = 1;
  FUN_100015a5(this,L"TRUE");
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__Tidy(local_4c,'\x01',0);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_1000dc87();
  return;
}



// Function: FUN_10001eed at 10001eed

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_10001eed(void *param_1)

{
  void *this;
  undefined1 local_4c [28];
  ushort local_30 [20];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0x10001ef9;
  FUN_10001bb0(local_30,L"IsRequired");
  local_8 = 0;
  this = FUN_10001c3f(param_1,local_4c,local_30);
  local_8._0_1_ = 1;
  FUN_100015a5(this,L"TRUE");
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__Tidy(local_4c,'\x01',0);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_1000dc87();
  return;
}



// Function: FUN_10001f5b at 10001f5b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10001f5b(void *this,undefined4 *param_1,undefined4 *param_2)

{
  basic_string<>(this,param_1);
  basic_string<>((void *)((int)this + 0x1c),param_2);
  return this;
}



// Function: FUN_10001f91 at 10001f91

void __thiscall FUN_10001f91(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  piVar2 = param_2;
  if (*(char *)((int)param_2 + 0x45) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  FUN_100012d0((int *)&param_2);
  piVar5 = (int *)*piVar2;
  if (*(char *)((int)piVar5 + 0x45) == '\0') {
    piVar7 = piVar5;
    if ((*(char *)(piVar2[2] + 0x45) != '\0') || (piVar7 = (int *)param_2[2], param_2 == piVar2))
    goto LAB_10001fdb;
    piVar5[1] = (int)param_2;
    *param_2 = *piVar2;
    piVar5 = param_2;
    if (param_2 != (int *)piVar2[2]) {
      piVar5 = (int *)param_2[1];
      if (*(char *)((int)piVar7 + 0x45) == '\0') {
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
    iVar1 = param_2[0x11];
    *(char *)(param_2 + 0x11) = (char)piVar2[0x11];
    *(char *)(piVar2 + 0x11) = (char)iVar1;
  }
  else {
    piVar7 = (int *)piVar2[2];
LAB_10001fdb:
    piVar5 = (int *)piVar2[1];
    if (*(char *)((int)piVar7 + 0x45) == '\0') {
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
      if (*(char *)((int)piVar7 + 0x45) == '\0') {
        piVar3 = (int *)*piVar7;
        piVar6 = piVar7;
        while (piVar4 = piVar3, *(char *)((int)piVar4 + 0x45) == '\0') {
          piVar6 = piVar4;
          piVar3 = (int *)*piVar4;
        }
      }
      **(int **)((int)this + 4) = (int)piVar6;
    }
    if (*(int **)(*(int *)((int)this + 4) + 8) == piVar2) {
      piVar6 = piVar5;
      if (*(char *)((int)piVar7 + 0x45) == '\0') {
        piVar3 = (int *)piVar7[2];
        piVar6 = piVar7;
        while (piVar4 = piVar3, *(char *)((int)piVar4 + 0x45) == '\0') {
          piVar6 = piVar4;
          piVar3 = (int *)piVar4[2];
        }
      }
      *(int **)(*(int *)((int)this + 4) + 8) = piVar6;
    }
  }
  if ((char)piVar2[0x11] != '\x01') {
LAB_100021b8:
    FUN_10001d04((int)this + 0xd,piVar2 + 3);
    operator_delete(piVar2);
    if (*(int *)((int)this + 8) != 0) {
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
    }
    *param_1 = param_2;
    return;
  }
LAB_1000216c:
  piVar6 = piVar5;
  if ((piVar7 == *(int **)(*(int *)((int)this + 4) + 4)) || ((char)piVar7[0x11] != '\x01'))
  goto LAB_100021b4;
  piVar5 = (int *)*piVar6;
  if (piVar7 == piVar5) {
    piVar5 = (int *)piVar6[2];
    if ((char)piVar5[0x11] == '\0') {
      *(undefined1 *)(piVar5 + 0x11) = 1;
      *(undefined1 *)(piVar6 + 0x11) = 0;
      FUN_1000130b(this,(int)piVar6);
      piVar5 = (int *)piVar6[2];
    }
    if (*(char *)((int)piVar5 + 0x45) == '\0') {
      if ((*(char *)(*piVar5 + 0x44) != '\x01') || (*(char *)(piVar5[2] + 0x44) != '\x01')) {
        if (*(char *)(piVar5[2] + 0x44) == '\x01') {
          *(undefined1 *)(*piVar5 + 0x44) = 1;
          *(undefined1 *)(piVar5 + 0x11) = 0;
          FUN_10001350(this,piVar5);
          piVar5 = (int *)piVar6[2];
        }
        *(char *)(piVar5 + 0x11) = (char)piVar6[0x11];
        *(undefined1 *)(piVar6 + 0x11) = 1;
        *(undefined1 *)(piVar5[2] + 0x44) = 1;
        FUN_1000130b(this,(int)piVar6);
        goto LAB_100021b4;
      }
LAB_10002163:
      *(undefined1 *)(piVar5 + 0x11) = 0;
    }
  }
  else {
    if ((char)piVar5[0x11] == '\0') {
      *(undefined1 *)(piVar5 + 0x11) = 1;
      *(undefined1 *)(piVar6 + 0x11) = 0;
      FUN_10001350(this,piVar6);
      piVar5 = (int *)*piVar6;
    }
    if (*(char *)((int)piVar5 + 0x45) == '\0') {
      if ((*(char *)(piVar5[2] + 0x44) == '\x01') && (*(char *)(*piVar5 + 0x44) == '\x01'))
      goto LAB_10002163;
      if (*(char *)(*piVar5 + 0x44) == '\x01') {
        *(undefined1 *)(piVar5[2] + 0x44) = 1;
        *(undefined1 *)(piVar5 + 0x11) = 0;
        FUN_1000130b(this,(int)piVar5);
        piVar5 = (int *)*piVar6;
      }
      *(char *)(piVar5 + 0x11) = (char)piVar6[0x11];
      *(undefined1 *)(piVar6 + 0x11) = 1;
      *(undefined1 *)(*piVar5 + 0x44) = 1;
      FUN_10001350(this,piVar6);
LAB_100021b4:
      *(undefined1 *)(piVar7 + 0x11) = 1;
      goto LAB_100021b8;
    }
  }
  piVar5 = (int *)piVar6[1];
  piVar7 = piVar6;
  goto LAB_1000216c;
}



// Function: FUN_100021ee at 100021ee

void __thiscall FUN_100021ee(void *this,int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x45);
  while (cVar1 == '\0') {
    FUN_100021ee(this,(int *)param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_10001d04((int)this + 0xd,param_1 + 3);
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x45);
  }
  return;
}



// Function: FUN_10002232 at 10002232

void __thiscall FUN_10002232(void *this,int *param_1,int *param_2,undefined4 *param_3)

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
  while (*(char *)((int)puVar3 + 0x45) == '\0') {
    if ((char)param_3 == '\0') {
      iVar2 = FUN_10001584(this_00,(ushort *)(puVar3 + 3));
      local_8 = iVar2 < 0;
    }
    else {
      iVar2 = FUN_10001584(puVar3 + 3,this_00);
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
      goto LAB_100022a8;
    }
    FUN_10001050((int *)&param_3);
  }
  puVar3 = param_3;
  iVar2 = FUN_10001584(param_3 + 3,this_00);
  if (-1 < iVar2) {
    FUN_10001d04((int)this + 0xd,this_00);
    operator_delete(param_2);
    *param_1 = (int)puVar3;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_100022a8:
  piVar1 = (int *)FUN_10001d22(this,&param_3,local_8,local_c,param_2);
  *param_1 = *piVar1;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}



// Function: FUN_10002308 at 10002308

void __fastcall FUN_10002308(void *param_1)

{
  FUN_100021ee(param_1,*(int **)(*(int *)((int)param_1 + 4) + 4));
  *(int *)(*(int *)((int)param_1 + 4) + 4) = *(int *)((int)param_1 + 4);
  *(undefined4 *)*(undefined4 *)((int)param_1 + 4) = *(undefined4 *)((int)param_1 + 4);
  *(int *)(*(int *)((int)param_1 + 4) + 8) = *(int *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 8) = 0;
  return;
}



// Function: FUN_1000232f at 1000232f

/* WARNING: Variable defined which should be unmapped: param_2 */

undefined4 * __thiscall FUN_1000232f(void *param_1,undefined4 *param_2,int *param_3,int *param_4)

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
      iVar3 = FUN_10001584(this,(ushort *)(param_3 + 3));
      if (-1 < iVar3) goto LAB_1000243f;
      cVar5 = '\x01';
      goto LAB_1000234b;
    }
    if (param_3 == piVar1) {
      iVar3 = FUN_10001584((void *)(piVar1[2] + 0xc),this);
      if (-1 < iVar3) goto LAB_1000243f;
      param_3 = *(int **)(*(int *)((int)param_1 + 4) + 8);
      cVar5 = '\0';
      goto LAB_1000234b;
    }
    iVar3 = FUN_10001584(this,(ushort *)(param_3 + 3));
    if (iVar3 < 0) {
      param_4 = param_3;
      FUN_10001050((int *)&param_4);
      piVar1 = param_4;
      iVar3 = FUN_10001584(param_4 + 3,this);
      if (-1 < iVar3) goto LAB_100023ee;
      cVar5 = *(char *)(piVar1[2] + 0x45);
      piVar6 = param_3;
    }
    else {
LAB_100023ee:
      iVar3 = FUN_10001584(param_3 + 3,(ushort *)(piVar2 + 3));
      if (-1 < iVar3) {
LAB_1000243f:
        puVar4 = (undefined4 *)FUN_10002232(param_1,(int *)&local_c,piVar2,(undefined4 *)0x0);
        *param_2 = *puVar4;
        return param_2;
      }
      param_4 = param_3;
      FUN_100012d0((int *)&param_4);
      if ((param_4 != *(int **)((int)param_1 + 4)) &&
         (iVar3 = FUN_10001584(piVar2 + 3,(ushort *)(param_4 + 3)), -1 < iVar3)) goto LAB_1000243f;
      cVar5 = *(char *)(param_3[2] + 0x45);
      piVar1 = param_3;
      piVar6 = param_4;
    }
    param_3 = piVar1;
    if (cVar5 != '\0') {
      cVar5 = '\0';
      goto LAB_1000234b;
    }
  }
  cVar5 = '\x01';
  param_3 = piVar6;
LAB_1000234b:
  FUN_10001d22(param_1,param_2,cVar5,param_3,piVar2);
  return param_2;
}



// Function: FUN_1000245b at 1000245b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000245b(void *this,undefined4 *param_1)

{
  FUN_10001f5b(this,param_1,param_1 + 7);
  return this;
}



// Function: FUN_10002489 at 10002489

void __thiscall FUN_10002489(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  void *local_8;
  
  local_8 = this;
  if ((param_2 == (int *)**(int **)((int)this + 4)) && (param_3 == *(int **)((int)this + 4))) {
    FUN_10002308(this);
    param_2 = (int *)**(undefined4 **)((int)this + 4);
  }
  else if (param_2 != param_3) {
    do {
      piVar1 = param_2;
      FUN_100012d0((int *)&param_2);
      FUN_10001f91(this,&local_8,piVar1);
    } while (param_2 != param_3);
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_100024dc at 100024dc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_100024dc(void *param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = &LAB_1000ff82;
  if (param_1 != (void *)0x0) {
    puVar1 = (undefined1 *)FUN_1000245b(param_1,param_2);
  }
  return puVar1;
}



// Function: FUN_1000250a at 1000250a

void __cdecl FUN_1000250a(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  FUN_100024dc(param_2,param_3);
  return;
}



// Function: FUN_1000251d at 1000251d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000251d(void *param_1)

{
  undefined4 local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  local_14 = param_1;
  FUN_10002489(param_1,&local_18,(int *)**(int **)((int)param_1 + 4),*(int **)((int)param_1 + 4));
  local_8 = 0xffffffff;
  operator_delete(*(void **)((int)param_1 + 4));
  return;
}



// Function: FUN_10002557 at 10002557

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_10002557(void *this,undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_100015ca((int)this);
  FUN_1000250a((int)this + 0xd,(void *)(iVar1 + 0xc),param_1);
  return iVar1;
}



// Function: Catch@10002594 at 10002594

void Catch_10002594(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100025a7 at 100025a7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100025a7(void *param_1)

{
  FUN_1000251d(param_1);
  return;
}



// Function: FUN_100025c5 at 100025c5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100025c5(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  
  *param_1 = CAddIn::vftable;
  piVar2 = param_1 + 1;
  piVar1 = (int *)*piVar2;
  if (piVar1 != (int *)0x0) {
    *piVar2 = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_1000251d(param_1 + 10);
  FID_conflict__Tidy(param_1 + 2,'\x01',0);
  piVar2 = (int *)*piVar2;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  return;
}



// Function: FUN_10002635 at 10002635

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_10002635(int param_1)

{
  int aiStack_30 [5];
  undefined1 *local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10002641;
  local_1c = (undefined1 *)aiStack_30;
  aiStack_30[0] = param_1;
  local_18 = param_1;
  FUN_100017aa(param_1);
  return local_18;
}



// Function: FUN_10002661 at 10002661

undefined4 * __thiscall FUN_10002661(void *this,byte param_1)

{
  FUN_100025c5((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002680 at 10002680

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10002680(void *this,ushort *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_6c;
  undefined4 local_68 [14];
  undefined2 local_30 [8];
  undefined4 local_20;
  undefined4 local_1c;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x5c;
  local_8 = 0x1000268c;
  piVar1 = FUN_100019b0(this,param_1);
  if (piVar1 != *(int **)((int)this + 4)) {
    iVar2 = FUN_10001584(param_1,(ushort *)(piVar1 + 3));
    if (-1 < iVar2) goto LAB_10002709;
  }
  local_20 = 0;
  local_1c = 7;
  local_30[0] = 0;
  local_8 = 0;
  FUN_10001f5b(local_68,(undefined4 *)param_1,(undefined4 *)local_30);
  local_8._0_1_ = 2;
  piVar3 = (int *)FUN_10002557(this,local_68);
  FUN_1000232f(this,&local_6c,piVar1,piVar3);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10001774(local_68);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
LAB_10002709:
  FUN_1000dc87();
  return;
}



// Function: FUN_10002714 at 10002714

void __thiscall FUN_10002714(void *this,ushort *param_1,undefined4 *param_2)

{
  void *this_00;
  
  this_00 = (void *)FUN_10002680((void *)((int)this + 0x28),param_1);
  FUN_100019e5(this_00,param_2,0,0xffffffff);
  return;
}



// Function: FUN_10002734 at 10002734

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 __thiscall FUN_10002734(void *this,LPCWSTR param_1)

{
  LPCWSTR pWVar1;
  int iVar2;
  void *this_00;
  undefined1 uVar3;
  undefined1 local_30 [4];
  LPCWSTR local_2c;
  undefined4 local_20;
  undefined1 local_1c [20];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x10002740;
  FUN_1000ceda(&local_20);
  local_8 = 0;
  pWVar1 = param_1;
  if (7 < *(uint *)(param_1 + 10)) {
    pWVar1 = *(LPCWSTR *)param_1;
  }
  iVar2 = Open(local_1c,(HKEY)0x80000002,pWVar1,0x2001f);
  if (iVar2 == 0) {
    FUN_10002635((int)local_30);
    local_8._0_1_ = 1;
    iVar2 = FUN_1000d5fb(&local_20,(LPCWSTR)((int)this + 8),local_30);
    if (iVar2 == 0) {
      param_1 = *(LPCWSTR *)local_2c;
      if (param_1 != local_2c) {
        do {
          pWVar1 = param_1;
          this_00 = (void *)FUN_10002680((void *)((int)this + 0x28),(ushort *)(param_1 + 6));
          FUN_100019e5(this_00,(undefined4 *)(pWVar1 + 0x14),0,0xffffffff);
          FUN_100012d0((int *)&param_1);
        } while (param_1 != local_2c);
      }
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_1000251d(local_30);
    local_8 = 0xffffffff;
    FUN_1000cf09(&local_20);
  }
  else {
    local_8 = 0xffffffff;
    FUN_1000cf09(&local_20);
    uVar3 = 0;
  }
  return uVar3;
}



// Function: FUN_10002809 at 10002809

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10002809(void *this,undefined4 *param_1,LPCWSTR param_2)

{
  char cVar1;
  
  *(undefined ***)this = CAddIn::vftable;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 7;
  *(undefined2 *)((int)this + 8) = 0;
  FUN_10002635((int)this + 0x28);
  FUN_10001b27(this,param_1);
  cVar1 = FUN_10002734(this,param_2);
  *(uint *)((int)this + 0x24) = (uint)(cVar1 != '\0');
  return (undefined4 *)this;
}



// Function: FUN_1000287d at 1000287d

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000287d(void *this,char param_1)

{
  int iVar1;
  undefined4 local_4c [7];
  ushort local_30 [20];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0x10002889;
  if (*(int *)((int)this + 0x24) == 2) {
    iVar1 = (**(code **)(**(int **)((int)this + 4) + 0x10))(*(int **)((int)this + 4));
    if (param_1 != '\0') {
      FUN_10001bb0(local_4c,L"TRUE");
      local_8 = 0;
      FUN_10001bb0(local_30,L"IsActive");
      local_8._0_1_ = 1;
      FUN_10002714(this,local_30,local_4c);
      local_8 = (uint)local_8._1_3_ << 8;
      FID_conflict__Tidy(local_30,'\x01',0);
      local_8 = 0xffffffff;
      FID_conflict__Tidy(local_4c,'\x01',0);
    }
  }
  else {
    iVar1 = -0x7fffbffb;
  }
  if (-1 < iVar1) {
    *(undefined4 *)((int)this + 0x24) = 3;
  }
  FUN_1000dc87();
  return;
}



// Function: FUN_1000290c at 1000290c

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000290c(void *this,char param_1)

{
  undefined4 local_4c [7];
  ushort local_30 [20];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0x10002918;
  if (((*(int *)((int)this + 0x24) == 2) || (*(int *)((int)this + 0x24) == 3)) &&
     ((**(code **)(**(int **)((int)this + 4) + 0x14))(*(int **)((int)this + 4)), param_1 != '\0')) {
    FUN_10001bb0(local_4c,L"FALSE");
    local_8 = 0;
    FUN_10001bb0(local_30,L"IsActive");
    local_8._0_1_ = 1;
    FUN_10002714(this,local_30,local_4c);
    local_8 = (uint)local_8._1_3_ << 8;
    FID_conflict__Tidy(local_30,'\x01',0);
    local_8 = 0xffffffff;
    FID_conflict__Tidy(local_4c,'\x01',0);
  }
  *(undefined4 *)((int)this + 0x24) = 1;
  FUN_1000dc87();
  return;
}



// Function: _InlineIsEqualGUID at 1000299e

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



// Function: FUN_100029ce at 100029ce

bool __cdecl FUN_100029ce(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,0x10);
  return (bool)('\x01' - (iVar1 != 0));
}



// Function: AtlMultiply<unsigned_long> at 100029e8

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



// Function: AtlCoTaskMemCAlloc at 10002a0a

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



// Function: FUN_10002a37 at 10002a37

LPVOID __cdecl FUN_10002a37(LPVOID param_1,ulong param_2,ulong param_3)

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



// Function: FUN_10002a67 at 10002a67

bool __cdecl FUN_10002a67(void *param_1,int param_2,LPCWSTR param_3)

{
  int iVar1;
  errno_t eVar2;
  
  iVar1 = lstrlenW(param_3);
  eVar2 = memcpy_s(param_1,param_2 * 2,param_3,iVar1 * 2 + 2);
  return (bool)('\x01' - (eVar2 != 0));
}



// Function: AtlCrtErrorCheck at 10002a94

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
  FUN_10001038(uVar1);
}



// Function: FUN_10002acc at 10002acc

void __cdecl FUN_10002acc(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: FUN_10002aec at 10002aec

void __cdecl FUN_10002aec(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscpy_s(param_1,param_2,param_3);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: Init at 10002b09

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



// Function: FUN_10002b32 at 10002b32

void __fastcall FUN_10002b32(LPCRITICAL_SECTION param_1)

{
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  return;
}



// Function: FUN_10002b44 at 10002b44

DWORD FUN_10002b44(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}



// Function: FUN_10002b59 at 10002b59

uint __cdecl FUN_10002b59(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FUN_10002b72 at 10002b72

void __fastcall FUN_10002b72(int param_1)

{
  long lVar1;
  
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (-1 < lVar1) {
    *(undefined1 *)(param_1 + 0x1c) = 1;
  }
  return;
}



// Function: FUN_10002b87 at 10002b87

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __fastcall FUN_10002b87(void *param_1)

{
  memset(param_1,0,0x18);
  *(undefined1 *)((int)param_1 + 0x18) = 0;
  return param_1;
}



// Function: FUN_10002bb5 at 10002bb5

void __fastcall FUN_10002bb5(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FUN_10002bbe at 10002bbe

void __fastcall FUN_10002bbe(int *param_1)

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



// Function: FID_conflict:RegCreateKeyExW at 10002bf9

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
                    /* WARNING: Could not recover jumptable at 0x10002c4e. Too many branches */
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



// Function: FID_conflict:RegDeleteKeyA at 10002c5c

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
                    /* WARNING: Could not recover jumptable at 0x10002c9f. Too many branches */
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



// Function: FUN_10002cae at 10002cae

undefined4 __fastcall FUN_10002cae(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10002cb2 at 10002cb2

void __cdecl FUN_10002cb2(short *param_1,int param_2,short *param_3)

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



// Function: FUN_10002d00 at 10002d00

int __fastcall FUN_10002d00(int param_1)

{
  memset((void *)(param_1 + 0xc),0,0x18);
  return param_1;
}



// Function: DeleteSubKey at 10002d17

/* Library Function - Multiple Matches With Same Base Name
    public: long __thiscall ATL::CRegKey::DeleteSubKey(char const *)
    public: long __thiscall ATL::CRegKey::DeleteSubKey(wchar_t const *)
   
   Library: Visual Studio 2010 Release */

void __thiscall DeleteSubKey(void *this,LPCWSTR param_1)

{
  HMODULE hModule;
  
  if (*(int *)((int)this + 8) == 0) {
    if (DAT_10017c54 == '\0') {
      hModule = GetModuleHandleW(L"Advapi32.dll");
      if (hModule != (HMODULE)0x0) {
        DAT_10017c50 = GetProcAddress(hModule,"RegDeleteKeyExW");
      }
      DAT_10017c54 = '\x01';
    }
    if (DAT_10017c50 == (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      RegDeleteKeyW(*this,param_1);
    }
    else {
                    /* WARNING: Load size is inaccurate */
      (*DAT_10017c50)(*this,param_1,*(undefined4 *)((int)this + 4),0);
    }
  }
  else {
                    /* WARNING: Load size is inaccurate */
    FID_conflict_RegDeleteKeyA(*this,(LPCSTR)param_1);
  }
  return;
}



// Function: Create at 10002d87

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



// Function: SetStringValue at 10002def

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



// Function: FUN_10002e26 at 10002e26

LSTATUS __thiscall FUN_10002e26(void *this,LPCWSTR param_1,LPCWSTR param_2)

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



// Function: FUN_10002e69 at 10002e69

undefined4 __fastcall FUN_10002e69(undefined4 *param_1)

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



// Function: FUN_10002e89 at 10002e89

undefined4 * __thiscall FUN_10002e89(void *this,ulong param_1)

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



// Function: FUN_10002ebf at 10002ebf

void __fastcall FUN_10002ebf(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_10002ec9 at 10002ec9

undefined4 __thiscall FUN_10002ec9(void *this,void *param_1,int param_2)

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
      pvVar4 = FUN_10002a37(*(LPVOID *)((int)this + 8),uVar3,2);
      if (pvVar4 == (LPVOID)0x0) {
        return 0;
      }
      *(LPVOID *)((int)this + 8) = pvVar4;
    }
                    /* WARNING: Load size is inaccurate */
    iVar1 = *this;
    if (((-1 < iVar1) && (iVar2 = *(int *)((int)this + 4), iVar1 < iVar2)) &&
       (iVar2 - iVar1 <= iVar2)) {
      FUN_10002acc((void *)(*(int *)((int)this + 8) + iVar1 * 2),(iVar2 - iVar1) * 2,param_1,
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



// Function: FUN_10002f57 at 10002f57

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10002f57(undefined4 param_1,undefined2 *param_2)

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
  local_8 = 0x10002f63;
  uVar5 = 0;
  puVar3 = auStack_20;
  if ((DAT_10017c78 & 1) == 0) {
    DAT_10017c78 = DAT_10017c78 | 1;
    DAT_10017c5c = 8;
    _DAT_10017c64 = 0x4008;
    _DAT_10017c6c = 0x13;
    DAT_10017c58 = &DAT_10011450;
    DAT_10017c60 = &DAT_1001144c;
    _DAT_10017c68 = &DAT_10011448;
    _DAT_10017c70 = &DAT_10011444;
    _DAT_10017c74 = 0x11;
    local_8 = 0xffffffff;
  }
  do {
    *(undefined **)(puVar3 + -4) = (&DAT_10017c58)[uVar5 * 2];
    *(undefined4 *)(puVar3 + -8) = param_1;
    puVar4 = puVar3 + -0xc;
    *(undefined4 *)(puVar3 + -0xc) = 0x10002fda;
    iVar1 = lstrcmpiW(*(LPCWSTR *)(puVar3 + -8),*(LPCWSTR *)(puVar3 + -4));
    if (iVar1 == 0) {
      *param_2 = (&DAT_10017c5c)[uVar5 * 4];
      uVar2 = 1;
      goto LAB_10002fe6;
    }
    uVar5 = uVar5 + 1;
    puVar3 = puVar4;
  } while (uVar5 < 4);
  uVar2 = 0;
LAB_10002fe6:
  *(undefined4 *)(puVar4 + -4) = 0x10002feb;
  return uVar2;
}



// Function: FUN_10002fff at 10002fff

int __cdecl FUN_10002fff(ushort param_1)

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



// Function: FUN_10003035 at 10003035

undefined4 __cdecl FUN_10003035(LPCWSTR param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_HKCR_10011508)[uVar2 * 2]);
    if (iVar1 == 0) {
      return (&DAT_1001150c)[uVar2 * 2];
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xe);
  return 0;
}



// Function: FUN_10003063 at 10003063

LPCWSTR __cdecl FUN_10003063(LPCWSTR param_1,WCHAR param_2)

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



// Function: FUN_10003090 at 10003090

undefined4 FUN_10003090(ushort param_1)

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



// Function: FUN_100030b6 at 100030b6

void __fastcall FUN_100030b6(undefined4 *param_1)

{
  LPWSTR pWVar1;
  int iVar2;
  
  while( true ) {
    iVar2 = FUN_10003090(*(ushort *)*param_1);
    if (iVar2 == 0) break;
    pWVar1 = CharNextW((LPCWSTR)*param_1);
    *param_1 = pWVar1;
  }
  return;
}



// Function: FUN_100030d8 at 100030d8

undefined4 __thiscall FUN_100030d8(void *this,undefined2 *param_1)

{
  WCHAR WVar1;
  LPCWSTR pWVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  
  FUN_100030b6((undefined4 *)this);
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
      while ((*pWVar4 != L'\0' && (iVar5 = FUN_10002e69((undefined4 *)this), iVar5 == 0))) {
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
        iVar5 = FUN_10003090(*pWVar2);
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



// Function: FUN_100031ee at 100031ee

undefined4 FUN_100031ee(LPCWSTR param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_u_AppID_10011494;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar2);
    if (iVar1 == 0) {
      return 0;
    }
    ppuVar2 = ppuVar2 + 1;
  } while ((int)ppuVar2 < 0x100114c4);
  return 1;
}



// Function: FUN_1000321d at 1000321d

bool FUN_1000321d(HKEY param_1)

{
  LSTATUS LVar1;
  DWORD local_8;
  
  local_8 = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_8,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  return LVar1 == 0 && local_8 != 0;
}



// Function: FUN_10003252 at 10003252

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10003252(void *this,short *param_1)

{
  int iVar1;
  undefined2 local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_10017c0c ^ (uint)&stack0xfffffffc;
  if ((*param_1 == 0x3d) && (iVar1 = FUN_100030d8(this,param_1), -1 < iVar1)) {
    FUN_100030b6((undefined4 *)this);
    iVar1 = FUN_100030d8(this,local_2008);
    if (-1 < iVar1) {
      FUN_100030d8(this,param_1);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100032b7 at 100032b7

undefined4 FUN_100032b7(undefined1 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_1 = DAT_10017c34;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_100032d6 at 100032d6

undefined4 __thiscall FUN_100032d6(void *this,int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    DAT_10017c3c = *param_3;
    DAT_10017c40 = param_3[1];
    DAT_10017c44 = param_3[2];
    DAT_10017c48 = param_3[3];
  }
  piVar2 = DAT_10017d44;
  if ((param_1 != (int *)0xffffffff) &&
     (*(int **)((int)this + 0x2c) = param_1, piVar2 = DAT_10017d44, param_1 != (int *)0x0)) {
    iVar1 = *param_1;
    while (DAT_10017d44 = piVar2, iVar1 != 0) {
      (*(code *)param_1[8])(1);
      param_1 = param_1 + 9;
      piVar2 = DAT_10017d44;
      iVar1 = *param_1;
    }
  }
  for (; piVar2 < DAT_10017d48; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(1);
    }
  }
  return 0;
}



// Function: FUN_10003334 at 10003334

void FUN_10003334(int param_1)

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



// Function: FUN_1000339b at 1000339b

void __fastcall FUN_1000339b(int *param_1)

{
  int *_Memory;
  
  while (*param_1 != 0) {
    _Memory = (int *)*param_1;
    *param_1 = *_Memory;
    free(_Memory);
  }
  return;
}



// Function: FUN_100033b5 at 100033b5

void __fastcall FUN_100033b5(undefined4 *param_1)

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



// Function: FUN_100033e2 at 100033e2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_100033e2(LPCRITICAL_SECTION param_1)

{
  undefined1 *puVar1;
  undefined1 *extraout_EAX;
  
  puVar1 = &LAB_1000ea52;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
    puVar1 = extraout_EAX;
  }
  return puVar1;
}



// Function: FUN_1000340c at 1000340c

int __thiscall FUN_1000340c(void *this,undefined4 *param_1)

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



// Function: FUN_10003443 at 10003443

void __fastcall FUN_10003443(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_1000344d at 1000344d

void __thiscall FUN_1000344d(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001038(0x8007000e);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: AtlMultiplyThrow<unsigned_int> at 10003472

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
    FUN_10001038(lVar1);
  }
  return local_8;
}



// Function: DllCanUnloadNow at 10003497

HRESULT DllCanUnloadNow(void)

{
                    /* 0x3497  1  DllCanUnloadNow */
  return (uint)(DAT_10017c84 != 0);
}



// Function: FUN_100034a3 at 100034a3

void __fastcall FUN_100034a3(int param_1)

{
  operator_delete(*(void **)(param_1 + 4));
  return;
}



// Function: FUN_100034ad at 100034ad

void __fastcall FUN_100034ad(int *param_1)

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



// Function: FUN_100034e8 at 100034e8

void __thiscall FUN_100034e8(void *this,int param_1)

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



// Function: FUN_1000352d at 1000352d

void __thiscall FUN_1000352d(void *this,int *param_1)

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



// Function: FUN_10003574 at 10003574

void __thiscall FUN_10003574(void *this,int *param_1)

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



// Function: FUN_100035bb at 100035bb

int __fastcall FUN_100035bb(int param_1)

{
  long lVar1;
  
  FUN_10002d00(param_1 + 4);
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_10017c38 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 0x10));
  if (lVar1 < 0) {
    DAT_10017c28 = 1;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x24;
  }
  return param_1;
}



// Function: FUN_100035fc at 100035fc

void __fastcall FUN_100035fc(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10003334((int)piVar1);
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



// Function: FUN_10003635 at 10003635

void __fastcall FUN_10003635(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10003334((int)piVar1);
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



// Function: FUN_1000363a at 1000363a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000363a(int param_1)

{
  FUN_100035fc(param_1);
  return;
}



// Function: FUN_10003658 at 10003658

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10003658(void *this,LPCWSTR param_1)

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
      iVar1 = FUN_10003658(&local_224,local_214);
    } while (iVar1 == 0);
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_224);
  }
  else {
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_224);
  }
  FUN_1000dc87();
  return;
}



// Function: FUN_1000373d at 1000373d

undefined4 __fastcall FUN_1000373d(int *param_1)

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
LAB_10003782:
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pcVar1 = (code *)swi(3);
        uVar3 = (*pcVar1)();
        return uVar3;
      }
      operator_delete__(*(void **)(*param_1 + iVar4 * 4));
      if (param_1[2] <= iVar4) goto LAB_10003782;
      operator_delete__(*(void **)(param_1[1] + iVar4 * 4));
      iVar2 = param_1[2];
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  FUN_100033b5(param_1);
  return 0;
}



// Function: FUN_10003794 at 10003794

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10003794(void *this,LPCWSTR param_1)

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
    uVar1 = FUN_10002ec9(this,param_1,iVar2);
    local_8 = 0xffffffff;
    FUN_1000339b(local_14);
  }
  return uVar1;
}



// Function: FUN_100037db at 100037db

void FUN_100037db(int param_1)

{
  FUN_1000373d((int *)(param_1 + 4));
  return;
}



// Function: FUN_100037ed at 100037ed

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_100037ed(HMODULE param_1,LPCWSTR param_2,undefined4 *param_3,undefined4 *param_4)

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
  local_8 = 0x100037fc;
  local_244 = param_2;
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined4 *)0x0)) goto LAB_100039c7;
  *param_3 = 0;
  *param_4 = 0;
  local_248 = 0;
  local_8 = 0;
  DVar2 = GetModuleFileNameW(param_1,local_23c,0x104);
  if (DVar2 == 0) {
    FUN_10002b44();
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
      if (((uVar1 < DVar2) || (uVar1 < uVar3)) || (0x10d < uVar1)) goto LAB_1000385a;
      FUN_10002aec(local_23c + DVar2,0x10e - DVar2,local_244);
    }
    iVar4 = Ordinal_161(local_23c,param_4);
    if (iVar4 < 0) {
      builtin_wcsncpy(local_20,L".tlb",5);
      iVar4 = (int)local_240 - (int)local_23c >> 1;
      if (iVar4 + 5U < 0x105) {
        eVar5 = wcscpy_s(local_240,0x10e - iVar4,local_20);
        ATL::AtlCrtErrorCheck(eVar5);
        iVar4 = Ordinal_161(local_23c,param_4);
        if (-1 < iVar4) goto LAB_10003997;
      }
    }
    else {
LAB_10003997:
      uVar6 = Ordinal_2(local_23c);
      *param_3 = uVar6;
    }
  }
LAB_1000385a:
  local_8 = 0xffffffff;
  FUN_1000339b(&local_248);
LAB_100039c7:
  FUN_1000dc87();
  return;
}



// Function: FUN_100039cf at 100039cf

void __fastcall FUN_100039cf(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  piVar2 = DAT_10017d44;
  if (piVar1 != (int *)0x0) {
    for (; piVar2 = DAT_10017d44, *piVar1 != 0; piVar1 = piVar1 + 9) {
      piVar2 = (int *)piVar1[4];
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      piVar1[4] = 0;
      (*(code *)piVar1[8])(0);
    }
  }
  for (; piVar2 < DAT_10017d48; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(0);
    }
  }
  FUN_100035fc(param_1);
  return;
}



// Function: FUN_10003a21 at 10003a21

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_10003a21(void *this,byte param_1)

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
    _eh_vector_destructor_iterator_(this,0xc,*piVar1,(_func_void_void_ptr *)&LAB_1000337a);
    if ((param_1 & 1) != 0) {
      operator_delete__(piVar1);
    }
  }
  return piVar1;
}



// Function: FUN_10003a7e at 10003a7e

void __fastcall FUN_10003a7e(undefined4 *param_1)

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



// Function: FUN_10003a83 at 10003a83

void __fastcall FUN_10003a83(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_10003a93 at 10003a93

void __fastcall FUN_10003a93(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FUN_10003443(param_1);
    return;
  }
  return;
}



// Function: FUN_10003aa0 at 10003aa0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003aa0(int param_1)

{
  FUN_100033e2((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FUN_10003ac1 at 10003ac1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_10003ac1(void *this,int param_1,undefined4 *param_2,undefined4 *param_3)

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



// Function: FUN_10003b15 at 10003b15

void __fastcall FUN_10003b15(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_10003b2c at 10003b2c

undefined4 FUN_10003b2c(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_100032d6(&DAT_10017c7c,(int *)&PTR_DAT_10017070,param_1,(undefined4 *)&DAT_10011454);
    DisableThreadLibraryCalls(param_1);
  }
  else if (param_2 == 0) {
    FUN_100039cf(0x10017c7c);
  }
  return 1;
}



// Function: FUN_10003b6e at 10003b6e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10003b6e(undefined4 *param_1)

{
  param_1[1] = 0;
  FUN_10002b87(param_1 + 2);
  *param_1 = ATL::CComClassFactory::vftable;
  return param_1;
}



// Function: InlineIsEqualUnknown at 10003ba9

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



// Function: FUN_10003bd7 at 10003bd7

undefined4 FUN_10003bd7(int param_1,int param_2,_GUID *param_3,undefined4 *param_4)

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



// Function: FUN_10003c15 at 10003c15

undefined4 FUN_10003c15(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    (**(code **)(*DAT_10017c38 + 8))();
  }
  else {
    (**(code **)(*DAT_10017c38 + 4))();
  }
  return 0;
}



// Function: FUN_10003c34 at 10003c34

void __thiscall FUN_10003c34(void *this,int param_1)

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



// Function: FUN_10003c79 at 10003c79

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_10003c79(undefined4 *param_1)

{
  FUN_100035bb((int)param_1);
  *param_1 = ATL::CComModule::vftable;
  _DAT_10017c4c = param_1;
  return param_1;
}



// Function: FUN_10003cae at 10003cae

void __fastcall FUN_10003cae(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10003cb9 at 10003cb9

void __fastcall FUN_10003cb9(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10003cc4 at 10003cc4

HRESULT __thiscall FUN_10003cc4(void *this,undefined4 *param_1)

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
       (HVar1 = CoCreateInstance((IID *)&DAT_100120d8,(LPUNKNOWN)0x0,1,(IID *)&DAT_10011714,ppv),
       -1 < HVar1)) {
      *param_1 = *ppv;
                    /* WARNING: Load size is inaccurate */
      (**(code **)(**ppv + 4))(*ppv);
    }
  }
  return HVar1;
}



// Function: FUN_10003d10 at 10003d10

undefined4 FUN_10003d10(void)

{
  return 0x80004005;
}



// Function: FUN_10003d18 at 10003d18

void FUN_10003d18(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",&DAT_10011288);
  return;
}



// Function: FUN_10003d32 at 10003d32

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10003d32(void *this,byte param_1)

{
  *(undefined ***)this = ATL::CComModule::vftable;
  FUN_100035fc((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003d69 at 10003d69

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003d69(int *param_1)

{
  FUN_1000373d(param_1);
  FUN_100033b5(param_1);
  return;
}



// Function: FUN_10003d93 at 10003d93

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003d93(undefined4 *param_1)

{
  *param_1 = ATL::CRegObject::vftable;
  FUN_1000373d(param_1 + 1);
  FUN_10003d69(param_1 + 1);
  return;
}



// Function: FUN_10003dc7 at 10003dc7

undefined4 FUN_10003dc7(void)

{
  return 0x80004001;
}



// Function: FUN_10003dcf at 10003dcf

undefined4 FUN_10003dcf(void)

{
  return 1;
}



// Function: FUN_10003dd5 at 10003dd5

undefined4 FUN_10003dd5(void)

{
  return 0;
}



// Function: FUN_10003dda at 10003dda

undefined4 * __thiscall FUN_10003dda(void *this,byte param_1)

{
  FUN_10003d93((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003df9 at 10003df9

undefined4 __fastcall FUN_10003df9(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_1000340c((void *)(param_1 + 4),(undefined4 *)&stack0x00000004);
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



// Function: FUN_10003e3a at 10003e3a

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10003e3a(void *this,LPCWSTR param_1,int *param_2)

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
  local_8 = 0x10003e46;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != (int *)0x0)) {
    *param_2 = 0;
    iVar3 = lstrlenW(param_1);
    FUN_10002e89(&local_70,iVar3 * 2);
    local_8 = 0;
    if (local_68 == (LPVOID)0x0) {
      local_8 = 0xffffffff;
      CoTaskMemFree((LPVOID)0x0);
    }
    else {
      *(LPCWSTR *)this = param_1;
      local_5d = '\0';
      local_5c = FUN_100032b7(&local_5d);
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
LAB_10003f2f:
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x27) {
                if (local_55 == '\0') {
                  local_55 = '\x01';
                  goto LAB_10003fa3;
                }
                iVar3 = FUN_10002e69((undefined4 *)this);
                if (iVar3 == 0) {
                    /* WARNING: Load size is inaccurate */
                  pWVar5 = CharNextW(*this);
                  *(LPWSTR *)this = pWVar5;
                  iVar3 = FUN_10002ec9(&local_70,pWVar5,1);
                  if (iVar3 == 0) goto LAB_10003fc9;
                  goto LAB_10003f6b;
                }
                local_55 = '\0';
              }
              else {
LAB_10003f6b:
                if (local_55 != '\0') goto LAB_10003fa3;
              }
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x7b) {
                local_64 = local_64 + 1;
              }
              if (((**this == 0x7d) && (local_64 = local_64 + -1, local_64 == 0)) &&
                 (local_56 == '\x01')) {
                iVar3 = FUN_10003794(&local_70,L"\r\n\t}\r\n}\r\n");
                if (iVar3 == 0) goto LAB_10003fc9;
                local_56 = '\0';
              }
              goto LAB_10003fa3;
            }
            pWVar5 = CharNextW(*this);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            iVar3 = FUN_10003794(&local_70,L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses");
            if (iVar3 != 0) {
              local_56 = '\x01';
              goto LAB_10003f2f;
            }
LAB_10003fc9:
            local_5c = -0x7ff8fff2;
            goto LAB_10003eaa;
          }
LAB_10003fa3:
                    /* WARNING: Load size is inaccurate */
          pWVar6 = *this;
          if (*pWVar6 == L'%') {
            pWVar5 = CharNextW(pWVar6);
            *(LPWSTR *)this = pWVar5;
            if (*pWVar5 != L'%') {
              pWVar6 = FUN_10003063(pWVar5,L'%');
              if (pWVar6 != (LPCWSTR)0x0) {
                    /* WARNING: Load size is inaccurate */
                _MaxCount = (int)pWVar6 - (int)*this >> 1;
                if (0x1f < (int)_MaxCount) {
                  local_5c = -0x7fffbffb;
                  goto LAB_10003eaa;
                }
                eVar7 = wcsncpy_s(local_54,0x20,*this,_MaxCount);
                ATL::AtlCrtErrorCheck(eVar7);
                pWVar8 = (LPCWSTR)FUN_10003df9(*(int *)((int)this + 4));
                if (pWVar8 != (LPCWSTR)0x0) {
                  iVar3 = FUN_10003794(&local_70,pWVar8);
                  if (iVar3 == 0) goto LAB_10003fc9;
                    /* WARNING: Load size is inaccurate */
                  pWVar8 = *this;
                  while (pWVar8 != pWVar6) {
                    /* WARNING: Load size is inaccurate */
                    pWVar8 = CharNextW(*this);
                    *(LPCWSTR *)this = pWVar8;
                  }
                  goto LAB_1000403c;
                }
              }
              local_5c = -0x7ffdfff7;
              goto LAB_10003eaa;
            }
            iVar3 = FUN_10002ec9(&local_70,pWVar5,1);
            if (iVar3 == 0) goto LAB_10003fc9;
          }
          else {
            iVar3 = FUN_10002ec9(&local_70,pWVar6,1);
            if (iVar3 == 0) {
              local_5c = -0x7ff8fff2;
              break;
            }
          }
LAB_1000403c:
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
LAB_10003eaa:
      local_8 = 0xffffffff;
      CoTaskMemFree(local_68);
    }
  }
  FUN_1000dc87();
  return;
}



// Function: FUN_100040a7 at 100040a7

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_100040a7(GUID *param_1,int *param_2,int param_3)

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
      (iVar2 = _InlineIsEqualGUID((int *)param_1,(int *)&PTR_100120c8), iVar2 == 0)) &&
     (HVar3 = CoCreateInstance((IID *)&DAT_100120e8,(LPUNKNOWN)0x0,1,(IID *)&DAT_1001180c,&local_1a8
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
          goto LAB_10004332;
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
      FUN_1000339b(&local_1cc);
    }
  }
  local_8 = 0xffffffff;
  if (local_1a8 != (int *)0x0) {
    (**(code **)(*local_1a8 + 8))(local_1a8);
  }
LAB_10004332:
  FUN_1000dc87();
  return;
}



// Function: FUN_100043c5 at 100043c5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_100043c5(HMODULE param_1,LPCWSTR param_2)

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
  iVar1 = FUN_100037ed(param_1,param_2,&local_18,local_14);
  if ((-1 < iVar1) && (iVar1 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],&param_1), -1 < iVar1)
     ) {
    param_2 = (LPCWSTR)((uint)param_2 & 0xffffff);
    iVar1 = FUN_100032b7((undefined1 *)((int)&param_2 + 3));
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



// Function: FUN_10004495 at 10004495

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10004495(HMODULE param_1,LPCWSTR param_2)

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
  iVar2 = FUN_100037ed(param_1,param_2,&local_22c,&local_228);
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
    iVar2 = FUN_100032b7(&local_21d);
    if (iVar2 < 0) {
      local_8._0_1_ = 2;
      Ordinal_6(local_224);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_228 != (int *)0x0) {
        (**(code **)(*local_228 + 8))(local_228);
      }
      local_8 = 0xffffffff;
      Ordinal_6(local_22c);
      goto LAB_10004657;
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
LAB_10004657:
  FUN_1000dc87();
  return;
}



// Function: FUN_1000465f at 1000465f

int FUN_1000465f(int param_1,int param_2,void *param_3)

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
            (bVar3 = FUN_100029ce(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          iVar7 = 1;
          iVar4 = (*(code *)puVar1[1])();
          if (iVar4 < 0) {
            return iVar4;
          }
          piVar5 = (int *)(*(code *)puVar1[7])(1);
          param_1 = FUN_100040a7((GUID *)*puVar1,piVar5,iVar7);
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
      param_1 = FUN_10004495(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_100046e5 at 100046e5

int FUN_100046e5(int param_1,int param_2,void *param_3)

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
            (bVar3 = FUN_100029ce(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          iVar6 = 0;
          piVar4 = (int *)(*(code *)puVar1[7])();
          iVar6 = FUN_100040a7((GUID *)*puVar1,piVar4,iVar6);
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
      param_1 = FUN_100043c5(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_1000476c at 1000476c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_1000476c(int *param_1,int *param_2,undefined4 param_3,int *param_4)

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
              param_1 = (int *)(*(code *)puVar1[2])(puVar1[3],&DAT_10011200,piVar3);
            }
            LeaveCriticalSection(lpCriticalSection);
            if (*piVar3 != 0) goto LAB_10004827;
          }
          else {
LAB_10004827:
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



// Function: FUN_10004857 at 10004857

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10004857(undefined4 *param_1)

{
  *param_1 = ATL::CComClassFactory::vftable;
  FUN_100033e2((LPCRITICAL_SECTION)(param_1 + 2));
  return;
}



// Function: FUN_10004888 at 10004888

undefined4 * __thiscall FUN_10004888(void *this,byte param_1)

{
  FUN_10004857((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100048a7 at 100048a7

undefined4 __thiscall FUN_100048a7(void *this,undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  
                    /* WARNING: Load size is inaccurate */
  pvVar1 = _recalloc(*this,*(int *)((int)this + 8) + 1,4);
  if (pvVar1 != (void *)0x0) {
    *(void **)this = pvVar1;
    pvVar1 = _recalloc(*(void **)((int)this + 4),*(int *)((int)this + 8) + 1,4);
    if (pvVar1 != (void *)0x0) {
      *(void **)((int)this + 4) = pvVar1;
      FUN_10003ac1(this,*(int *)((int)this + 8),param_1,param_2);
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      return 1;
    }
  }
  return 0;
}



// Function: Allocate at 100048fe

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
    FUN_1000344d(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 1000492d

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
    FUN_1000344d(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 1000495c

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
    FUN_1000344d(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_1000498b at 1000498b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000498b(undefined4 *param_1)

{
  FUN_10003b6e(param_1);
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  return param_1;
}



// Function: AtlInternalQueryInterface at 100049b9

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
          if (pcVar1 == (code *)0x1) goto LAB_100049ed;
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
LAB_100049ed:
      piVar4 = (int *)(*(int *)(param_2 + 4) + (int)param_1);
      (**(code **)(*piVar4 + 4))(piVar4);
      *param_4 = piVar4;
      lVar2 = 0;
    }
  }
  return lVar2;
}



// Function: FUN_10004a5a at 10004a5a

LONG FUN_10004a5a(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_10017c38 + 4))();
  }
  return LVar1;
}



// Function: FUN_10004a84 at 10004a84

LONG FUN_10004a84(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (LVar1 == 1) {
    (**(code **)(*DAT_10017c38 + 8))();
  }
  return LVar1;
}



// Function: QueryInterface at 10004ac3

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10011888,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10004add at 10004add

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10004add(undefined4 *param_1)

{
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  param_1[1] = 0xc0000001;
  FUN_10004857(param_1);
  return;
}



// Function: FUN_10004b0c at 10004b0c

undefined4 * __thiscall FUN_10004b0c(void *this,byte param_1)

{
  FUN_10004add((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10004b2b at 10004b2b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10004b2b(void *param_1)

{
  FID_conflict__Tidy(param_1,'\x01',0);
  return;
}



// Function: FUN_10004b4d at 10004b4d

void FUN_10004b4d(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x15);
  while (cVar1 == '\0') {
    FUN_10004b4d((int *)param_1[2]);
    piVar2 = (int *)*param_1;
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x15);
  }
  return;
}



// Function: FUN_10004b82 at 10004b82

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10004b82(LPCWSTR param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != 0)) {
    iVar2 = lstrlenW(param_1);
    lVar1 = (ulonglong)(iVar2 * 2 + 2) * 2;
    FUN_1000db1c(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    uVar3 = FUN_10004be8();
    return uVar3;
  }
  return 0;
}



// Function: Catch@10004bdc at 10004bdc

undefined * Catch_10004bdc(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10004be6;
}



// Function: FUN_10004be8 at 10004be8

void FUN_10004be8(void)

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
  uVar4 = FUN_1000db1c(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
  *(undefined4 *)(unaff_EBP + -0x20) = uVar4;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_10004c39();
  return;
}



// Function: Catch@10004c2a at 10004c2a

undefined * Catch_10004c2a(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return &DAT_10004c37;
}



// Function: FUN_10004c39 at 10004c39

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_10004c39(void)

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
    FUN_10002acc(*(void **)(unaff_EBP + -0x14),*(rsize_t *)(unaff_EBP + -0x28),
                 *(void **)(unaff_EBP + 8),*(rsize_t *)(unaff_EBP + -0x28));
    FUN_10002acc(pvVar1,*(rsize_t *)(unaff_EBP + -0x2c),*(void **)(unaff_EBP + 0xc),
                 *(rsize_t *)(unaff_EBP + -0x2c));
    iVar2 = FUN_100048a7(*(void **)(unaff_EBP + -0x30),(undefined4 *)(unaff_EBP + -0x14),
                         (undefined4 *)(unaff_EBP + -0x20));
    if (iVar2 != 0) {
      *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
      *(void **)(unaff_EBP + -0x18) = unaff_ESI;
      goto LAB_10004c95;
    }
  }
  *(undefined4 *)(unaff_EBP + -0x24) = 0x8007000e;
LAB_10004c95:
  iVar2 = *(int *)(unaff_EBP + -0x24);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  operator_delete__(*(void **)(unaff_EBP + -0x18));
  *(void **)(unaff_EBP + -0x18) = unaff_ESI;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  operator_delete__(*(void **)(unaff_EBP + -0x1c));
  *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
  return (int)unaff_ESI <= iVar2;
}



// Function: FUN_10004ccd at 10004ccd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10004ccd(undefined4 param_1,LPCWSTR param_2,int param_3)

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
    iVar1 = FUN_10004b82(param_2,param_3);
    iVar1 = (-(uint)(iVar1 != 0) & 0x7ff8fff2) + 0x8007000e;
    local_8 = 0xffffffff;
    FUN_1000339b(local_14);
  }
  return iVar1;
}



// Function: FUN_10004d28 at 10004d28

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10004d28(void *this,CRegKey *param_1,wchar_t *param_2,undefined2 *param_3)

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
  puStack_c = &LAB_1000ee69;
  local_10 = ExceptionList;
  uStack_2144 = DAT_10017c0c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2144;
  ExceptionList = &local_10;
  local_2124 = param_1;
  local_2128 = param_2;
  local_2120 = (wchar_t *)0x0;
  local_18 = uStack_2144;
  iVar1 = FUN_100030d8(this,local_2018);
  if ((iVar1 < 0) || (iVar1 = FUN_10002f57(local_2018,(undefined2 *)&local_2120), iVar1 == 0))
  goto LAB_100050a1;
  FUN_100030b6((undefined4 *)this);
  iVar1 = FUN_100030d8(this,local_2018);
  if (iVar1 < 0) goto LAB_100050a1;
  uVar2 = (uint)local_2120 & 0xffff;
  if (uVar2 == 8) {
    uVar2 = ATL::CRegKey::SetStringValue(param_1,param_2,local_2018,1);
LAB_1000507d:
    if (uVar2 != 0) {
      FUN_10002b59(uVar2);
      goto LAB_100050a1;
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
        FUN_10004fb0();
        return;
      }
      goto LAB_100050a1;
    }
    if (uVar2 == 0x13) {
      local_2124 = (CRegKey *)0x0;
      local_8 = 3;
      Ordinal_277(local_2018,0,0,&local_2128);
      local_2120 = local_2128;
      uVar2 = RegSetValueExW(*(HKEY *)param_1,param_2,0,4,(BYTE *)&local_2120,4);
      local_8 = 0xffffffff;
      FUN_1000339b((int *)&local_2124);
      goto LAB_1000507d;
    }
    if (uVar2 == 0x4008) {
      iVar1 = lstrlenW(local_2018);
      local_211c[0] = 0;
      local_8 = 1;
      Allocate(local_211c,iVar1 + 2);
      local_8 = 0;
      FUN_10004e49();
      return;
    }
  }
  FUN_100030d8(this,param_3);
LAB_100050a1:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10004e3d at 10004e3d

undefined * Catch_10004e3d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10004e47;
}



// Function: FUN_10004e49 at 10004e49

void FUN_10004e49(void)

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
    pWVar2 = (WCHAR *)FUN_10002e26(*(void **)(unaff_EBP - 0x2120),*(LPCWSTR *)(unaff_EBP - 0x2124),
                                   *(LPCWSTR *)(unaff_EBP - 0x2118));
    unaff_EDI = (WCHAR *)0x0;
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  if (*(int *)(unaff_EBP - 0x2118) != unaff_EBP - 0x2114) {
    FUN_10003443((undefined4 *)(unaff_EBP - 0x2118));
  }
  if (pWVar2 == unaff_EDI) {
    FUN_100030d8(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x212c));
  }
  else {
    FUN_10002b59((uint)pWVar2);
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x100050b9;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@10004f95 at 10004f95

undefined * Catch_10004f95(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return &DAT_10004fa2;
}



// Function: FUN_10004fb0 at 10004fb0

void FUN_10004fb0(void)

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
      FUN_10003443((undefined4 *)(unaff_EBP - 0x2118));
    }
  }
  else {
    memset(*(void **)(unaff_EBP - 0x2118),unaff_EDI,unaff_EBX);
    if ((int)unaff_EDI < *(int *)(unaff_EBP - 0x211c)) {
      do {
        pbVar1 = (byte *)((int)unaff_EDI / 2 + *(int *)(unaff_EBP - 0x2118));
        iVar2 = FUN_10002fff(*(ushort *)((unaff_EBP - 0x2014) + unaff_EDI * 2));
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
      FUN_10003443((undefined4 *)(unaff_EBP - 0x2118));
    }
    if (uVar3 == unaff_EDI) {
      FUN_100030d8(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x212c));
    }
    else {
      FUN_10002b59(uVar3);
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x100050b9;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_100050bd at 100050bd

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_100050bd(void *this,LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

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
  puStack_c = &LAB_1000eec8;
  local_10 = ExceptionList;
  local_14 = DAT_10017c0c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2228 = param_2;
  local_2234 = (HKEY)0x0;
  local_2230 = 0;
  local_222c = 0;
  local_8 = 0;
  local_2220 = this;
LAB_10005121:
  iVar3 = FUN_100030d8(local_2220,param_1);
  do {
    if (iVar3 < 0) {
LAB_10005131:
      local_8 = 0xffffffff;
      ATL::CRegKey::Close((CRegKey *)&local_2234);
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
LAB_1000558e:
    if (*param_1 == L'}') goto LAB_10005131;
    local_2238 = 1;
    iVar3 = lstrcmpiW(param_1,L"Delete");
    local_2224 = (uint)(iVar3 == 0);
    iVar4 = lstrcmpiW(param_1,L"ForceRemove");
    if ((iVar4 == 0) || ((iVar3 == 0) != 0)) {
      iVar3 = FUN_100030d8(local_2220,param_1);
      if (iVar3 < 0) goto LAB_10005131;
      if (param_3 == 0) goto LAB_10005270;
      local_2244 = (HKEY)0x0;
      local_2240 = 0;
      local_223c = 0;
      local_8._0_1_ = 1;
      pWVar5 = FUN_10003063(param_1,L'\\');
      if (pWVar5 == (LPCWSTR)0x0) {
        iVar3 = FUN_100031ee(param_1);
        if (iVar3 != 0) {
          local_2244 = local_2228;
          local_2240 = 0;
          local_223c = 0;
          FUN_10003658(&local_2244,param_1);
          local_2244 = (HKEY)0x0;
          local_2240 = 0;
          local_223c = 0;
        }
        if (local_2224 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_2244);
          goto LAB_10005270;
        }
        iVar3 = FUN_100030d8(local_2220,param_1);
        if ((-1 < iVar3) && (iVar3 = FUN_10003252(local_2220,param_1), -1 < iVar3)) {
          local_8 = (uint)local_8._1_3_ << 8;
          pCVar8 = (CRegKey *)&local_2244;
          goto LAB_1000568d;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_2244;
        goto LAB_1000570c;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2244);
      goto LAB_10005131;
    }
LAB_10005270:
    iVar3 = lstrcmpiW(param_1,L"NoRemove");
    if (iVar3 == 0) {
      local_2238 = 0;
      iVar3 = FUN_100030d8(local_2220,param_1);
      if (iVar3 < 0) goto LAB_10005131;
    }
    iVar3 = lstrcmpiW(param_1,L"Val");
    if (iVar3 != 0) {
      pWVar5 = FUN_10003063(param_1,L'\\');
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
          iVar3 = FUN_100030d8(local_2220,param_1);
          if (((-1 < iVar3) && (iVar3 = FUN_10003252(local_2220,param_1), -1 < iVar3)) &&
             (((*param_1 != L'{' || (iVar3 = lstrlenW(param_1), iVar3 != 1)) ||
              (((iVar3 = FUN_100050bd(local_2220,param_1,local_2234,0,param_4), -1 < iVar3 ||
                (param_4 != 0)) && (iVar3 = FUN_100030d8(local_2220,param_1), -1 < iVar3))))))
          break;
        }
        else {
          iVar3 = Open(&local_2234,local_2228,param_1,0x2001f);
          if (((iVar3 != 0) && (iVar3 = Open(&local_2234,local_2228,param_1,0x20019), iVar3 != 0))
             && (uVar6 = Create(&local_2234,local_2228,param_1,(LPWSTR)0x0,0,0x2001f,
                                (LPSECURITY_ATTRIBUTES)0x0,(undefined4 *)0x0), uVar6 != 0))
          goto LAB_1000572b;
          iVar3 = FUN_100030d8(local_2220,param_1);
          if ((-1 < iVar3) &&
             ((*param_1 != L'=' ||
              (iVar3 = FUN_10004d28(local_2220,(CRegKey *)&local_2234,(wchar_t *)0x0,param_1),
              -1 < iVar3)))) goto LAB_10005692;
        }
      }
      goto LAB_10005131;
    }
    iVar3 = FUN_100030d8(local_2220,local_221c);
    if (((iVar3 < 0) || (iVar3 = FUN_100030d8(local_2220,param_1), iVar3 < 0)) || (*param_1 != L'=')
       ) goto LAB_10005131;
    if (param_3 != 0) {
      local_8._0_1_ = 2;
      local_225c = local_2228;
      local_2258 = 0;
      local_2254 = 0;
      iVar3 = FUN_10004d28(local_2220,(CRegKey *)&local_225c,local_221c,param_1);
      local_225c = (HKEY)0x0;
      local_2258 = 0;
      local_2254 = 0;
      if (-1 < iVar3) {
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_225c;
        goto LAB_1000568d;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      pCVar8 = (CRegKey *)&local_225c;
      goto LAB_1000570c;
    }
    if ((iVar1 == 0) && (local_2238 != 0)) {
      local_2268 = (HKEY)0x0;
      local_2264 = 0;
      local_2260 = 0;
      local_8._0_1_ = 3;
      uVar6 = Open(&local_2268,local_2228,(LPCWSTR)0x0,0x20006);
      if ((uVar6 != 0) ||
         ((uVar6 = RegDeleteValueW(local_2268,local_221c), uVar6 != 0 && (uVar6 != 2)))) {
        FUN_10002b59(uVar6);
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_2268;
LAB_1000570c:
        ATL::CRegKey::Close(pCVar8);
        goto LAB_10005131;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2268);
    }
    iVar3 = FUN_10003252(local_2220,param_1);
  } while( true );
  if (local_2224 != 2) {
    if (local_2224 == 0) {
      if ((iVar1 != 0) && (bVar2 = FUN_1000321d(local_2234), CONCAT31(extraout_var,bVar2) != 0)) {
        iVar3 = FUN_100031ee(local_21c);
        if ((iVar3 != 0) && (local_2238 != 0)) {
          FUN_10003658(&local_2234,local_21c);
        }
        goto LAB_1000558e;
      }
      bVar2 = FUN_1000321d(local_2234);
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
            FUN_10002b59(uVar6);
            local_8 = (uint)local_8._1_3_ << 8;
            pCVar8 = (CRegKey *)&local_2250;
            goto LAB_1000570c;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          pCVar8 = (CRegKey *)&local_2250;
LAB_1000568d:
          ATL::CRegKey::Close(pCVar8);
LAB_10005692:
          if (((param_3 != 0) && (*param_1 == L'{')) && (iVar3 = lstrlenW(param_1), iVar3 == 1)) {
            iVar3 = FUN_100050bd(local_2220,param_1,local_2234,param_3,0);
            if (-1 < iVar3) goto LAB_10005121;
            goto LAB_10005131;
          }
        }
        goto LAB_1000558e;
      }
    }
    else {
      uVar6 = local_2224;
      if (iVar1 != 0) goto LAB_1000558e;
    }
LAB_1000572b:
    FUN_10002b59(uVar6);
    goto LAB_10005131;
  }
  goto LAB_1000558e;
}



// Function: FUN_10005754 at 10005754

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_10005754(void *this,int *param_1,undefined4 param_2,int *param_3)

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
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_10017d4c);
          local_14 = (int *)0x0;
          if (*piVar2 == 0) {
            local_14 = (int *)(*(code *)puVar3[2])(puVar3[3],&DAT_10011200,piVar2);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_10017d4c);
          if (*piVar2 != 0) goto LAB_100057e8;
        }
        else {
LAB_100057e8:
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
  piVar2 = FUN_1000476c((int *)&DAT_10017d3c,param_1,param_2,param_3);
  return piVar2;
}



// Function: FUN_10005820 at 10005820

void FUN_10005820(int param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = FUN_1000465f(0x10017d3c,param_1,param_2);
  if ((-1 < iVar1) && (DAT_10017c2c != (code *)0x0)) {
    (*DAT_10017c2c)(DAT_10017d68);
  }
  return;
}



// Function: FUN_1000584e at 1000584e

void FUN_1000584e(int param_1,void *param_2)

{
  int iVar1;
  
  if ((DAT_10017c30 != (code *)0x0) && (iVar1 = (*DAT_10017c30)(), iVar1 < 0)) {
    return;
  }
  FUN_100046e5(0x10017d3c,param_1,param_2);
  return;
}



// Function: DllGetClassObject at 10005874

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int *piVar1;
  
                    /* 0x5874  2  DllGetClassObject */
  piVar1 = FUN_10005754(&DAT_10017c7c,(int *)rclsid,riid,(int *)ppv);
  return (HRESULT)piVar1;
}



// Function: Catch@100058e0 at 100058e0

undefined1 * Catch_100058e0(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_100058ea;
}



// Function: FUN_10005932 at 10005932

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005932(void *param_1)

{
  FID_conflict__Tidy(param_1,'\x01',0);
  return;
}



// Function: FUN_10005954 at 10005954

void __thiscall FUN_10005954(void *this,undefined4 *param_1,int *param_2)

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
  FUN_10002bbe((int *)&param_2);
  piVar5 = (int *)*piVar2;
  if (*(char *)((int)piVar5 + 0x15) == '\0') {
    piVar7 = piVar5;
    if ((*(char *)(piVar2[2] + 0x15) != '\0') || (piVar7 = (int *)param_2[2], param_2 == piVar2))
    goto LAB_1000599e;
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
LAB_1000599e:
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
LAB_10005b7b:
    operator_delete(piVar2);
    if (*(int *)((int)this + 8) != 0) {
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
    }
    *param_1 = param_2;
    return;
  }
LAB_10005b2f:
  piVar6 = piVar5;
  if ((piVar7 == *(int **)(*(int *)((int)this + 4) + 4)) || ((char)piVar7[5] != '\x01'))
  goto LAB_10005b77;
  piVar5 = (int *)*piVar6;
  if (piVar7 == piVar5) {
    piVar5 = (int *)piVar6[2];
    if ((char)piVar5[5] == '\0') {
      *(undefined1 *)(piVar5 + 5) = 1;
      *(undefined1 *)(piVar6 + 5) = 0;
      FUN_10003c34(this,(int)piVar6);
      piVar5 = (int *)piVar6[2];
    }
    if (*(char *)((int)piVar5 + 0x15) == '\0') {
      if ((*(char *)(*piVar5 + 0x14) != '\x01') || (*(char *)(piVar5[2] + 0x14) != '\x01')) {
        if (*(char *)(piVar5[2] + 0x14) == '\x01') {
          *(undefined1 *)(*piVar5 + 0x14) = 1;
          *(undefined1 *)(piVar5 + 5) = 0;
          FUN_10003574(this,piVar5);
          piVar5 = (int *)piVar6[2];
        }
        *(char *)(piVar5 + 5) = (char)piVar6[5];
        *(undefined1 *)(piVar6 + 5) = 1;
        *(undefined1 *)(piVar5[2] + 0x14) = 1;
        FUN_10003c34(this,(int)piVar6);
        goto LAB_10005b77;
      }
LAB_10005b26:
      *(undefined1 *)(piVar5 + 5) = 0;
    }
  }
  else {
    if ((char)piVar5[5] == '\0') {
      *(undefined1 *)(piVar5 + 5) = 1;
      *(undefined1 *)(piVar6 + 5) = 0;
      FUN_10003574(this,piVar6);
      piVar5 = (int *)*piVar6;
    }
    if (*(char *)((int)piVar5 + 0x15) == '\0') {
      if ((*(char *)(piVar5[2] + 0x14) == '\x01') && (*(char *)(*piVar5 + 0x14) == '\x01'))
      goto LAB_10005b26;
      if (*(char *)(*piVar5 + 0x14) == '\x01') {
        *(undefined1 *)(piVar5[2] + 0x14) = 1;
        *(undefined1 *)(piVar5 + 5) = 0;
        FUN_10003c34(this,(int)piVar5);
        piVar5 = (int *)*piVar6;
      }
      *(char *)(piVar5 + 5) = (char)piVar6[5];
      *(undefined1 *)(piVar6 + 5) = 1;
      *(undefined1 *)(*piVar5 + 0x14) = 1;
      FUN_10003574(this,piVar6);
LAB_10005b77:
      *(undefined1 *)(piVar7 + 5) = 1;
      goto LAB_10005b7b;
    }
  }
  piVar5 = (int *)piVar6[1];
  piVar7 = piVar6;
  goto LAB_10005b2f;
}



// Function: FUN_10005b9f at 10005b9f

void __fastcall FUN_10005b9f(int param_1)

{
  FUN_10004b4d(*(int **)(*(int *)(param_1 + 4) + 4));
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(undefined4 *)*(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: FUN_10005bc6 at 10005bc6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10005bc6(void *this,byte param_1)

{
  FID_conflict__Tidy(this,'\x01',0);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_10005bfb at 10005bfb

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10005bfb(void *this,LPCWSTR param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  HKEY pHVar4;
  short *local_200c;
  WCHAR local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_10017c0c ^ (uint)&stack0xfffffffc;
  local_200c = (short *)0x0;
  iVar3 = FUN_10003e3a(this,param_1,(int *)&local_200c);
  if (iVar3 < 0) {
LAB_10005cf1:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(short **)this = local_200c;
  sVar1 = *local_200c;
joined_r0x10005c46:
  if ((((sVar1 == 0) || (iVar3 = FUN_100030d8(this,local_2008), iVar3 < 0)) ||
      (pHVar4 = (HKEY)FUN_10003035(local_2008), pHVar4 == (HKEY)0x0)) ||
     ((iVar3 = FUN_100030d8(this,local_2008), iVar3 < 0 || (local_2008[0] != L'{'))))
  goto LAB_10005ce3;
  if (param_2 == 0) {
    iVar3 = FUN_100050bd(this,local_2008,pHVar4,0,0);
    if (iVar3 < 0) goto LAB_10005ce3;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar2 = *this;
    iVar3 = FUN_100050bd(this,local_2008,pHVar4,param_2,0);
    if (iVar3 < 0) {
      *(undefined4 *)this = uVar2;
      FUN_100050bd(this,local_2008,pHVar4,0,0);
LAB_10005ce3:
      CoTaskMemFree(local_200c);
      goto LAB_10005cf1;
    }
  }
  FUN_100030b6((undefined4 *)this);
                    /* WARNING: Load size is inaccurate */
  sVar1 = **this;
  goto joined_r0x10005c46;
}



// Function: FUN_10005d32 at 10005d32

int __thiscall FUN_10005d32(void *this,int param_1,void *param_2)

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
         (bVar1 = FUN_100029ce(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar6 = 1;
        iVar5 = (*(code *)piVar4[1])();
        if (iVar5 < 0) {
          return iVar5;
        }
        piVar3 = (int *)(*(code *)piVar4[7])(1);
        iVar5 = FUN_100040a7((GUID *)*piVar4,piVar3,iVar6);
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
  iVar5 = FUN_10005820(param_1,param_2);
  return iVar5;
}



// Function: FUN_10005da1 at 10005da1

int __thiscall FUN_10005da1(void *this,int param_1,void *param_2)

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
         (bVar1 = FUN_100029ce(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar5 = 0;
        piVar3 = (int *)(*(code *)piVar4[7])();
        iVar5 = FUN_100040a7((GUID *)*piVar4,piVar3,iVar5);
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
  iVar5 = FUN_1000584e(param_1,param_2);
  return iVar5;
}



// Function: DllRegisterServer at 10005e10

void DllRegisterServer(void)

{
                    /* 0x5e10  3  DllRegisterServer */
  FUN_10005d32(&DAT_10017c7c,1,(void *)0x0);
  return;
}



// Function: DllUnregisterServer at 10005e1f

void DllUnregisterServer(void)

{
                    /* 0x5e1f  4  DllUnregisterServer */
  FUN_10005da1(&DAT_10017c7c,1,(void *)0x0);
  return;
}



// Function: FUN_10005e2e at 10005e2e

void __thiscall FUN_10005e2e(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  void *local_8;
  
  local_8 = this;
  if ((param_2 == (int *)**(int **)((int)this + 4)) && (param_3 == *(int **)((int)this + 4))) {
    FUN_10005b9f((int)this);
    param_2 = (int *)**(undefined4 **)((int)this + 4);
  }
  else if (param_2 != param_3) {
    do {
      piVar1 = param_2;
      FUN_10002bbe((int *)&param_2);
      FUN_10005954(this,&local_8,piVar1);
    } while (param_2 != param_3);
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_10005e81 at 10005e81

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10005e81(LPCWSTR param_1,LPCWSTR param_2,LPCWSTR param_3)

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
    FUN_10002b44();
  }
  else {
    hResInfo = FindResourceW(local_420,param_2,param_3);
    if ((hResInfo == (HRSRC)0x0) ||
       (local_424 = LoadResource(local_420,hResInfo), local_424 == (HGLOBAL)0x0)) {
      FUN_10002b44();
    }
    else {
      local_428 = SizeofResource(local_420,hResInfo);
      if (local_428 <= local_428 + 1) {
        local_8 = CONCAT31(local_8._1_3_,2);
        Allocate(&local_41c,local_428 + 1);
        local_8 = 1;
        FUN_10005f5b();
        return;
      }
    }
    FreeLibrary(local_420);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_41c != auStack_418) {
    FUN_10003443(&local_41c);
  }
  local_8 = 0xffffffff;
  FUN_1000339b(&local_42c);
  FUN_1000dc96();
  return;
}



// Function: Catch@10005f46 at 10005f46

undefined * Catch_10005f46(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10005f53;
}



// Function: FUN_10005f5b at 10005f5b

void FUN_10005f5b(void)

{
  DWORD DVar1;
  DWORD unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  if (*(DWORD *)(unaff_EBP + -0x418) != unaff_EBX) {
    DVar1 = MultiByteToWideChar(3,unaff_EBX,*(LPCSTR *)(unaff_EBP + -0x420),unaff_ESI,
                                *(LPWSTR *)(unaff_EBP + -0x418),unaff_ESI);
    if (DVar1 == unaff_EBX) {
      FUN_10002b44();
    }
    else {
      *(undefined2 *)(*(int *)(unaff_EBP + -0x418) + DVar1 * 2) = 0;
      FUN_10005bfb((void *)(unaff_EBP + -0x430),*(LPCWSTR *)(unaff_EBP + -0x418),
                   *(int *)(unaff_EBP + 0x14));
    }
  }
  FreeLibrary(*(HMODULE *)(unaff_EBP + -0x41c));
  *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
  if (*(int *)(unaff_EBP + -0x418) != unaff_EBP + -0x414) {
    FUN_10003443((undefined4 *)(unaff_EBP + -0x418));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1000339b((int *)(unaff_EBP + -0x428));
  FUN_1000dc96();
  return;
}



// Function: FUN_10005fe5 at 10005fe5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10005fe5(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_10005e81(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_1000339b(local_14);
  return uVar1;
}



// Function: FUN_10006026 at 10006026

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10006026(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

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
    FUN_1000339b(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_10005e81(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_1000339b(local_14);
  }
  return uVar1;
}



// Function: FUN_10006082 at 10006082

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10006082(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_10005e81(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_1000339b(local_14);
  return uVar1;
}



// Function: FUN_100060c2 at 100060c2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100060c2(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

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
    FUN_1000339b(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_10005e81(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_1000339b(local_14);
  }
  return uVar1;
}



// Function: FUN_1000611d at 1000611d

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000611d(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

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
      FUN_10004ccd(&local_a60,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a60);
  pHVar1 = DAT_10017d68;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_10017d68,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_10002b44();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_1000339b((int *)&local_a48);
        goto LAB_1000619f;
      }
      FUN_10002cb2(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_10002a67(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_1000339b((int *)&local_a48);
          goto LAB_1000619f;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_10004ccd(&local_a60,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_10004ccd(&local_a60,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_100060c2(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
        else {
          FUN_10006026(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_1000339b((int *)&local_a48);
  }
LAB_1000619f:
  local_8 = 0xffffffff;
  FUN_10003d93(&local_a60);
  FUN_1000dc87();
  return;
}



// Function: FUN_10006320 at 10006320

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10006320(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

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
      FUN_10004ccd(&local_a5c,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a5c);
  pHVar1 = DAT_10017d68;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_10017d68,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_10002b44();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_1000339b((int *)&local_a48);
        goto LAB_10006399;
      }
      FUN_10002cb2(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_10002a67(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_1000339b((int *)&local_a48);
          goto LAB_10006399;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_10004ccd(&local_a5c,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_10004ccd(&local_a5c,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_10006082(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
        else {
          FUN_10005fe5(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_1000339b((int *)&local_a48);
  }
LAB_10006399:
  local_8 = 0xffffffff;
  FUN_10003d93(&local_a5c);
  FUN_1000dc87();
  return;
}



// Function: FUN_10006517 at 10006517

void __fastcall FUN_10006517(_Container_base0 *param_1)

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



// Function: FUN_1000653a at 1000653a

void FUN_1000653a(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

{
  FUN_1000611d(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10006543 at 10006543

void FUN_10006543(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

{
  FUN_10006320(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000654c at 1000654c

void FUN_1000654c(int param_1)

{
  FUN_10006320((int *)&DAT_10017c7c,0x65,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_10006564 at 10006564

void __fastcall FUN_10006564(_Container_base0 *param_1)

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



// Function: FUN_10006569 at 10006569

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006569(void *param_1)

{
  undefined4 local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  local_14 = param_1;
  FUN_10005e2e(param_1,&local_18,(int *)**(int **)((int)param_1 + 4),*(int **)((int)param_1 + 4));
  local_8 = 0xffffffff;
  operator_delete(*(void **)((int)param_1 + 4));
  return;
}



// Function: FUN_100065a3 at 100065a3

void __cdecl FUN_100065a3(undefined4 param_1,void *param_2)

{
  FUN_10005bc6(param_2,0);
  return;
}



// Function: FUN_100065b2 at 100065b2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100065b2(void *param_1)

{
  FUN_10006569(param_1);
  return;
}



// Function: FUN_100065d0 at 100065d0

void __thiscall FUN_100065d0(void *this,undefined4 *param_1,int *param_2)

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
  FUN_100034ad((int *)&param_2);
  piVar5 = (int *)*piVar2;
  if (*(char *)((int)piVar5 + 0x2d) == '\0') {
    piVar7 = piVar5;
    if ((*(char *)(piVar2[2] + 0x2d) != '\0') || (piVar7 = (int *)param_2[2], param_2 == piVar2))
    goto LAB_1000661a;
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
LAB_1000661a:
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
LAB_100067f7:
    FUN_100065a3((int)this + 0xd,piVar2 + 3);
    operator_delete(piVar2);
    if (*(int *)((int)this + 8) != 0) {
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
    }
    *param_1 = param_2;
    return;
  }
LAB_100067ab:
  piVar6 = piVar5;
  if ((piVar7 == *(int **)(*(int *)((int)this + 4) + 4)) || ((char)piVar7[0xb] != '\x01'))
  goto LAB_100067f3;
  piVar5 = (int *)*piVar6;
  if (piVar7 == piVar5) {
    piVar5 = (int *)piVar6[2];
    if ((char)piVar5[0xb] == '\0') {
      *(undefined1 *)(piVar5 + 0xb) = 1;
      *(undefined1 *)(piVar6 + 0xb) = 0;
      FUN_100034e8(this,(int)piVar6);
      piVar5 = (int *)piVar6[2];
    }
    if (*(char *)((int)piVar5 + 0x2d) == '\0') {
      if ((*(char *)(*piVar5 + 0x2c) != '\x01') || (*(char *)(piVar5[2] + 0x2c) != '\x01')) {
        if (*(char *)(piVar5[2] + 0x2c) == '\x01') {
          *(undefined1 *)(*piVar5 + 0x2c) = 1;
          *(undefined1 *)(piVar5 + 0xb) = 0;
          FUN_1000352d(this,piVar5);
          piVar5 = (int *)piVar6[2];
        }
        *(char *)(piVar5 + 0xb) = (char)piVar6[0xb];
        *(undefined1 *)(piVar6 + 0xb) = 1;
        *(undefined1 *)(piVar5[2] + 0x2c) = 1;
        FUN_100034e8(this,(int)piVar6);
        goto LAB_100067f3;
      }
LAB_100067a2:
      *(undefined1 *)(piVar5 + 0xb) = 0;
    }
  }
  else {
    if ((char)piVar5[0xb] == '\0') {
      *(undefined1 *)(piVar5 + 0xb) = 1;
      *(undefined1 *)(piVar6 + 0xb) = 0;
      FUN_1000352d(this,piVar6);
      piVar5 = (int *)*piVar6;
    }
    if (*(char *)((int)piVar5 + 0x2d) == '\0') {
      if ((*(char *)(piVar5[2] + 0x2c) == '\x01') && (*(char *)(*piVar5 + 0x2c) == '\x01'))
      goto LAB_100067a2;
      if (*(char *)(*piVar5 + 0x2c) == '\x01') {
        *(undefined1 *)(piVar5[2] + 0x2c) = 1;
        *(undefined1 *)(piVar5 + 0xb) = 0;
        FUN_100034e8(this,(int)piVar5);
        piVar5 = (int *)*piVar6;
      }
      *(char *)(piVar5 + 0xb) = (char)piVar6[0xb];
      *(undefined1 *)(piVar6 + 0xb) = 1;
      *(undefined1 *)(*piVar5 + 0x2c) = 1;
      FUN_1000352d(this,piVar6);
LAB_100067f3:
      *(undefined1 *)(piVar7 + 0xb) = 1;
      goto LAB_100067f7;
    }
  }
  piVar5 = (int *)piVar6[1];
  piVar7 = piVar6;
  goto LAB_100067ab;
}



// Function: FUN_1000682d at 1000682d

void __thiscall FUN_1000682d(void *this,int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x2d);
  while (cVar1 == '\0') {
    FUN_1000682d(this,(int *)param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_100065a3((int)this + 0xd,param_1 + 3);
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x2d);
  }
  return;
}



// Function: FUN_10006871 at 10006871

void __fastcall FUN_10006871(void *param_1)

{
  FUN_1000682d(param_1,*(int **)(*(int *)((int)param_1 + 4) + 4));
  *(int *)(*(int *)((int)param_1 + 4) + 4) = *(int *)((int)param_1 + 4);
  *(undefined4 *)*(undefined4 *)((int)param_1 + 4) = *(undefined4 *)((int)param_1 + 4);
  *(int *)(*(int *)((int)param_1 + 4) + 8) = *(int *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 8) = 0;
  return;
}



// Function: FUN_10006898 at 10006898

void __thiscall FUN_10006898(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  void *local_8;
  
  local_8 = this;
  if ((param_2 == (int *)**(int **)((int)this + 4)) && (param_3 == *(int **)((int)this + 4))) {
    FUN_10006871(this);
    param_2 = (int *)**(undefined4 **)((int)this + 4);
  }
  else if (param_2 != param_3) {
    do {
      piVar1 = param_2;
      FUN_100034ad((int *)&param_2);
      FUN_100065d0(this,&local_8,piVar1);
    } while (param_2 != param_3);
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_100068eb at 100068eb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100068eb(void *param_1)

{
  undefined4 local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  local_14 = param_1;
  FUN_10006898(param_1,&local_18,(int *)**(int **)((int)param_1 + 4),*(int **)((int)param_1 + 4));
  local_8 = 0xffffffff;
  operator_delete(*(void **)((int)param_1 + 4));
  return;
}



// Function: FUN_10006925 at 10006925

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006925(void *param_1)

{
  FUN_100068eb(param_1);
  return;
}



// Function: FUN_10006943 at 10006943

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006943(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x18);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_100068eb((void *)(param_1 + 4));
  return;
}



// Function: FUN_10006987 at 10006987

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006987(int param_1)

{
  FUN_10006569((void *)(param_1 + 0xb8));
  FID_conflict__Tidy((void *)(param_1 + 0x9c),'\x01',0);
  FUN_10006517((_Container_base0 *)(param_1 + 0x8c));
  FUN_10006517((_Container_base0 *)(param_1 + 0x7c));
  FUN_10006517((_Container_base0 *)(param_1 + 0x6c));
  FUN_1000c50c((undefined4 *)(param_1 + 0x4c));
  FUN_10006943(param_1 + 4);
  FUN_100033e2((LPCRITICAL_SECTION)(param_1 + 0x2c));
  return;
}



// Function: FUN_10006a1f at 10006a1f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006a1f(int param_1)

{
  FUN_10006987(param_1);
  return;
}



// Function: FUN_10006a3d at 10006a3d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10006a3d(void *this,undefined4 param_1)

{
  FUN_1000aa12((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CAddInFactory>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CAddInFactory>::vftable;
  *(undefined ***)((int)this + 0x20) = ATL::CComContainedObject<class_CAddInFactory>::vftable;
  *(undefined ***)((int)this + 0x24) = ATL::CComContainedObject<class_CAddInFactory>::vftable;
  *(undefined4 *)((int)this + 0x28) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_10006a86 at 10006a86

void __fastcall FUN_10006a86(undefined4 *param_1)

{
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  return;
}



// Function: FUN_10006a8d at 10006a8d

undefined4 * __thiscall FUN_10006a8d(void *this,byte param_1)

{
  FUN_10006a86((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10006aac at 10006aac

void __fastcall FUN_10006aac(int *param_1)

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



// Function: FUN_10006af2 at 10006af2

void __thiscall FUN_10006af2(void *this,byte param_1)

{
  FUN_1000847b((void *)((int)this + -4),param_1);
  return;
}



// Function: FUN_10006afa at 10006afa

void __thiscall FUN_10006afa(void *this,undefined4 param_1,undefined4 param_2)

{
  if (*(char *)((int)this + 0x14) == '\0') {
                    /* WARNING: Load size is inaccurate */
    (**(code **)(*this + 0x2c))(param_1);
  }
                    /* WARNING: Load size is inaccurate */
  (**(code **)(*this + 0x28))(param_2);
  return;
}



// Function: FUN_10006b1d at 10006b1d

void FUN_10006b1d(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x28) + 4))(*(int **)(param_1 + 0x28));
  return;
}



// Function: FUN_10006b30 at 10006b30

void FUN_10006b30(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x28) + 8))(*(int **)(param_1 + 0x28));
  return;
}



// Function: FUN_10006b43 at 10006b43

void FUN_10006b43(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0x28))(*(undefined4 **)(param_1 + 0x28),param_2,param_3);
  return;
}



// Function: FUN_10006b5b at 10006b5b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_10006b5b(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10006b67;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10013448);
}



// Function: FUN_10006bba at 10006bba

void FUN_10006bba(int param_1)

{
  FUN_10006b1d(param_1 + -0x24);
  return;
}



// Function: FUN_10006bc4 at 10006bc4

void FUN_10006bc4(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10006b43(param_1 + -0x20,param_2,param_3);
  return;
}



// Function: FUN_10006bce at 10006bce

void FUN_10006bce(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10006b43(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10006bd8 at 10006bd8

void FUN_10006bd8(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10006b43(param_1 + -0x24,param_2,param_3);
  return;
}



// Function: FUN_10006be2 at 10006be2

void FUN_10006be2(int param_1)

{
  FUN_10006b30(param_1 + -0x20);
  return;
}



// Function: FUN_10006bec at 10006bec

void FUN_10006bec(int param_1)

{
  FUN_10006b30(param_1 + -4);
  return;
}



// Function: FUN_10006bf6 at 10006bf6

void FUN_10006bf6(int param_1)

{
  FUN_10006b30(param_1 + -0x24);
  return;
}



// Function: FUN_10006c00 at 10006c00

void FUN_10006c00(int param_1)

{
  FUN_10006b1d(param_1 + -0x20);
  return;
}



// Function: FUN_10006c0a at 10006c0a

void FUN_10006c0a(int param_1)

{
  FUN_10006b1d(param_1 + -4);
  return;
}



// Function: FUN_10006c14 at 10006c14

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10006c14(void *this,undefined4 *param_1)

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
  (**(code **)*param_1)(param_1,&DAT_10011994,local_14);
                    /* WARNING: Load size is inaccurate */
  (**(code **)(*this + 0x20))(param_1);
  piVar1 = local_14[0];
  ppuVar2 = FUN_10009ab7();
  if (ppuVar2 == (undefined4 **)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = (undefined4 *)Ordinal_2(ppuVar2);
    if (param_1 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_10001038(0x8007000e);
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



// Function: FUN_10006ca5 at 10006ca5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10006ca5(undefined4 param_1,int *param_2)

{
  undefined4 **ppuVar1;
  int iVar2;
  
  ppuVar1 = FUN_10009ab7();
  if (ppuVar1 == (undefined4 **)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = Ordinal_2(ppuVar1);
    if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_10001038(0x8007000e);
    }
  }
  *param_2 = iVar2;
  Ordinal_6(0);
  return 0;
}



// Function: FUN_10006cf9 at 10006cf9

void __fastcall FUN_10006cf9(undefined4 *param_1)

{
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  param_1[3] = 0x80004005;
  return;
}



// Function: FUN_10006d11 at 10006d11

void __fastcall FUN_10006d11(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_10006b5b((char *)0x1);
  *puVar1 = *(undefined4 *)(param_1 + 4);
  puVar1[1] = *(undefined4 *)(param_1 + 4);
  puVar1[2] = *(undefined4 *)(param_1 + 4);
  *(undefined2 *)(puVar1 + 0xb) = 0;
  return;
}



// Function: FUN_10006d38 at 10006d38

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006d38(undefined4 *param_1)

{
  *param_1 = CComErrorHandlerException::vftable;
  FID_conflict__Tidy(param_1 + 4,'\x01',0);
  return;
}



// Function: FUN_10006d63 at 10006d63

undefined4 * __thiscall FUN_10006d63(void *this,byte param_1)

{
  FUN_10006d38((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10006d82 at 10006d82

undefined4 * __thiscall FUN_10006d82(void *this,ushort *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)(*(undefined4 **)((int)this + 4))[1];
  puVar4 = *(undefined4 **)((int)this + 4);
  while (puVar3 = puVar1, *(char *)((int)puVar3 + 0x2d) == '\0') {
    iVar2 = FUN_10001584(puVar3 + 3,param_1);
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



// Function: FUN_10006db7 at 10006db7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10006db7(void *this,int *param_1)

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
  local_1c = (**(code **)*param_1)(param_1,&DAT_10011994,&local_18);
  ppuVar2 = FUN_100089b0();
  if (*ppuVar2 != (undefined *)0x0) {
    iVar5 = 0;
    do {
      ppuVar2 = FUN_100089b0();
      piVar1 = local_18;
      if (*(int *)((int)ppuVar2 + iVar5) == 0) {
        local_14 = 0;
      }
      else {
        local_14 = Ordinal_2(*(int *)((int)ppuVar2 + iVar5));
        if (local_14 == 0) goto LAB_10006ebd;
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      ppuVar3 = FUN_10009ab7();
      if (ppuVar3 == (undefined4 **)0x0) {
        param_1 = (int *)0x0;
      }
      else {
        param_1 = (int *)Ordinal_2(ppuVar3);
        if (param_1 == (int *)0x0) {
LAB_10006ebd:
                    /* WARNING: Subroutine does not return */
          FUN_10001038(0x8007000e);
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
      ppuVar2 = FUN_100089b0();
    } while (ppuVar2[iVar4] != (undefined *)0x0);
  }
  param_1 = (int *)**(int **)((int)this + 8);
  if (param_1 != *(int **)((int)this + 8)) {
    do {
      (**(code **)(*(int *)param_1[10] + 8))((int *)param_1[10]);
      FUN_100034ad((int *)&param_1);
    } while (param_1 != *(int **)((int)this + 8));
  }
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  return local_1c;
}



// Function: FUN_10006ec8 at 10006ec8

undefined4 * __fastcall FUN_10006ec8(undefined4 *param_1)

{
  param_1[1] = 0;
  *param_1 = ATL::CComObject<class_CComEventPublisher<class_CAddInFactory>::CPublisherEventsImpl>::
             vftable;
  (**(code **)(*DAT_10017c38 + 4))();
  return param_1;
}



// Function: FUN_10006ee6 at 10006ee6

undefined4 FUN_10006ee6(undefined4 param_1,undefined4 *param_2)

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



// Function: AtlComQIPtrAssign at 10006f03

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



// Function: FUN_10006f3a at 10006f3a

undefined4 FUN_10006f3a(undefined4 param_1,int *param_2)

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
    ppuVar3 = FUN_100089b0();
    puVar1 = *ppuVar3;
    while (puVar1 != (undefined *)0x0) {
      iVar4 = iVar4 + 1;
      ppuVar3 = FUN_100089b0();
      puVar1 = ppuVar3[iVar4];
    }
    *param_2 = iVar4;
    uVar2 = 0;
  }
  return uVar2;
}



// Function: Attach at 10006f6e

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



// Function: FUN_10006fb6 at 10006fb6

void __fastcall FUN_10006fb6(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10006fc3 at 10006fc3

undefined4 FUN_10006fc3(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return *(undefined4 *)(param_1 + 4);
}



// Function: Release at 10006fd3

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



// Function: FUN_10006ff4 at 10006ff4

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10006ff4(void *this,wchar_t *param_1)

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
  local_8 = 0x10007000;
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
      local_18 = (uint *)FUN_1000db1c(-(uint)(0xfffffffb < uVar8) | uVar8 + 4);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_18 == (uint *)0x0) {
        puVar6 = (uint *)0x0;
      }
      else {
        *local_18 = uVar2;
        puVar6 = local_18 + 1;
        _eh_vector_constructor_iterator_
                  (puVar6,0xc,uVar2,(_func_void_void_ptr *)&LAB_10006f8d,
                   (_func_void_void_ptr *)&LAB_1000337a);
      }
      local_8 = 0xffffffff;
      local_1c = puVar6;
      uVar7 = FUN_100070a4();
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



// Function: Catch@10007094 at 10007094

undefined * Catch_10007094(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000709e;
}



// Function: FUN_100070a4 at 100070a4

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100070a4(void)

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



// Function: FUN_1000715c at 1000715c

void FUN_1000715c(int param_1)

{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0xc);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (*(void **)(param_1 + 0x14) != (void *)0x0) {
      FUN_10003a21(*(void **)(param_1 + 0x14),3);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_1000718f at 1000718f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool __thiscall FUN_1000718f(void *this,undefined4 *param_1)

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
    (**(code **)**this)(*this,&DAT_10011200,&local_18);
    (**(code **)*param_1)(param_1,&DAT_10011200,local_14);
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



// Function: FUN_1000721a at 1000721a

void __fastcall FUN_1000721a(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CComEventPublisher<class_CAddInFactory>::CPublisherEventsImpl>::
             vftable;
  param_1[1] = 0xc0000001;
                    /* WARNING: Could not recover jumptable at 0x1000722f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_10017c38 + 8))();
  return;
}



// Function: QueryInterface at 10007232

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_100119e8,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_1000724c at 1000724c

undefined4 * __thiscall FUN_1000724c(void *this,byte param_1)

{
  FUN_1000721a((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000726b at 1000726b

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000726b(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 0x80070057;
  }
  operator_new(0xc);
  uVar1 = FUN_100072b0();
  return uVar1;
}



// Function: Catch@100072a0 at 100072a0

undefined * Catch_100072a0(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100072aa;
}



// Function: FUN_100072b0 at 100072b0

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100072b0(void)

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



// Function: FUN_1000730b at 1000730b

IUnknown * __thiscall FUN_1000730b(void *this,undefined4 *param_1)

{
  bool bVar1;
  IUnknown *pIVar2;
  
  bVar1 = FUN_1000718f(this,(undefined4 *)*param_1);
  if (bVar1) {
                    /* WARNING: Load size is inaccurate */
    pIVar2 = *this;
  }
  else {
    pIVar2 = ATL::AtlComQIPtrAssign((IUnknown **)this,(IUnknown *)*param_1,(_GUID *)&DAT_10011a20);
  }
  return pIVar2;
}



// Function: FUN_10007338 at 10007338

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10007338(void *this,undefined4 param_1)

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
  local_8 = 0x10007347;
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) goto LAB_1000757d;
  lpCriticalSection = (LPCRITICAL_SECTION)(DAT_10017c38 + 0x10);
  local_8 = 0;
  EnterCriticalSection(lpCriticalSection);
  local_220 = -0x7fffbffb;
  if (*(int *)((int)this + 0xc) == 0) {
    piVar1 = *(int **)((int)this + 4);
    local_230 = (int *)0x0;
    iVar2 = _InlineIsEqualGUID(&DAT_10017c3c,piVar1);
    if (((iVar2 == 0) || (*(short *)((int)this + 8) != -1)) || (*(short *)((int)this + 10) != -1)) {
      local_220 = Ordinal_162(piVar1,*(undefined2 *)((int)this + 8),*(undefined2 *)((int)this + 10),
                              param_1,&local_230);
    }
    else {
      DVar3 = GetModuleFileNameW(DAT_10017d68,local_21c,0x104);
      if ((DVar3 == 0) || (DVar3 == 0x104)) goto LAB_10007547;
      local_224 = (int *)0x0;
      local_8._0_1_ = 1;
      local_220 = Ordinal_161(local_21c,&local_230);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_1000339b((int *)&local_224);
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
        iVar2 = (**(code **)*local_228)(local_228,&DAT_10011a10,&local_224);
        if (-1 < iVar2) {
          FUN_1000730b(&local_22c,&local_224);
        }
        *(int **)((int)this + 0xc) = local_22c;
        local_22c = (int *)0x0;
        if (DAT_10017c38 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = DAT_10017c38 + 4;
        }
        pcVar4 = FUN_1000715c;
        pvVar5 = this;
        FUN_1000726b(iVar2);
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
LAB_10007547:
  if ((*(wchar_t **)((int)this + 0xc) != (wchar_t *)0x0) && (*(int *)((int)this + 0x14) == 0)) {
    local_220 = FUN_10006ff4(this,*(wchar_t **)((int)this + 0xc));
  }
  local_8 = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
LAB_1000757d:
  FUN_1000dc87();
  return;
}



// Function: FUN_10007585 at 10007585

undefined4 __thiscall FUN_10007585(void *this,undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = 0;
    if (*(int *)((int)this + 0xc) == 0) {
      uVar1 = FUN_10007338(this,param_1);
    }
    *param_2 = *(undefined4 *)((int)this + 0xc);
    if (*(int *)((int)this + 0xc) != 0) {
      (**(code **)(**(int **)((int)this + 0xc) + 4))(*(int **)((int)this + 0xc));
      uVar1 = 0;
    }
  }
  return uVar1;
}



// Function: FUN_100075c5 at 100075c5

undefined4 __thiscall
FUN_100075c5(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    uVar1 = FUN_10007338(this,param_4);
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



// Function: FUN_10007666 at 10007666

void __thiscall
FUN_10007666(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    FUN_10007338(this,param_4);
  }
  if (*(int *)((int)this + 0xc) != 0) {
    (**(code **)(**(int **)((int)this + 0xc) + 0x2c))
              (*(int **)((int)this + 0xc),param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_100076a9 at 100076a9

undefined4 FUN_100076a9(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10007585(&PTR_DAT_100176a0,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_100076cd at 100076cd

void FUN_100076cd(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_100075c5(&PTR_DAT_100176a0,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_100076ed at 100076ed

void FUN_100076ed(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10007666(&PTR_DAT_100176a0,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_100076fb at 100076fb

undefined4 * __fastcall FUN_100076fb(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = ATL::CComObject<class_CComEventPublisher<class_CAddInFactory>::CPublisherEventImpl>::
             vftable;
  (**(code **)(*DAT_10017c38 + 4))();
  return param_1;
}



// Function: Release at 1000771d

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



// Function: FUN_1000773e at 1000773e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_1000773e(int param_1,int *param_2)

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
  local_8 = 0x1000774a;
  puVar5 = (undefined4 *)auStack_20;
  if (param_2 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    puStack_24 = (undefined *)0x1000775d;
    ppuVar2 = FUN_100089b0();
    if (ppuVar2[*(int *)(param_1 + 8)] == (undefined *)0x0) {
      iVar3 = 0;
    }
    else {
      puVar5 = &uStack_28;
      uStack_28 = 0x10007794;
      puStack_24 = ppuVar2[*(int *)(param_1 + 8)];
      iVar3 = Ordinal_2();
      if (iVar3 == 0) {
        puVar5[-1] = 0x8007000e;
                    /* WARNING: Subroutine does not return */
        puVar5[-2] = &UNK_100077a5;
        FUN_10001038(puVar5[-1]);
      }
    }
    *param_2 = iVar3;
    local_8 = 0xffffffff;
    *(undefined4 *)((int)puVar5 + -4) = 0;
    puVar4 = (undefined4 *)((int)puVar5 + -8);
    puVar5 = (undefined4 *)((int)puVar5 + -8);
    *puVar4 = 0x10007783;
    Ordinal_6();
    uVar1 = 0;
  }
  *(undefined4 *)((int)puVar5 + -4) = 0x1000778a;
  return uVar1;
}



// Function: FUN_100077a6 at 100077a6

void __fastcall FUN_100077a6(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CComEventPublisher<class_CAddInFactory>::CPublisherEventImpl>::
             vftable;
  param_1[1] = 0xc0000001;
                    /* WARNING: Could not recover jumptable at 0x100077bb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_10017c38 + 8))();
  return;
}



// Function: QueryInterface at 100077be

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10011a60,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_100077d8 at 100077d8

undefined4 * __thiscall FUN_100077d8(void *this,byte param_1)

{
  FUN_100077a6((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100077f7 at 100077f7

undefined4 FUN_100077f7(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10007585(&PTR_DAT_10017840,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_1000781b at 1000781b

void FUN_1000781b(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_100075c5(&PTR_DAT_10017840,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_1000783b at 1000783b

void FUN_1000783b(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10007666(&PTR_DAT_10017840,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10007849 at 10007849

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10007849(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0xc);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10006ec8(puVar1);
    }
    uVar2 = FUN_100078a4();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@10007895 at 10007895

undefined * Catch_10007895(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000789f;
}



// Function: FUN_100078a4 at 100078a4

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100078a4(void)

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



// Function: FUN_100078bb at 100078bb

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100078bb(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0x10);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_100076fb(puVar1);
    }
    uVar2 = FUN_10007916();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@10007907 at 10007907

undefined * Catch_10007907(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10007911;
}



// Function: FUN_10007916 at 10007916

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10007916(void)

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



// Function: FUN_1000792d at 1000792d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000792d(void *this,int param_1)

{
  *(undefined ***)this = CComErrorHandlerException::vftable;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  basic_string<>((void *)((int)this + 0x10),(undefined4 *)(param_1 + 0x10));
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  return (undefined4 *)this;
}



// Function: FUN_1000797d at 1000797d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000797d(void *this,undefined4 *param_1,undefined4 *param_2)

{
  basic_string<>(this,param_1);
  *(undefined4 *)((int)this + 0x1c) = *param_2;
  return this;
}



// Function: FUN_100079b0 at 100079b0

void __thiscall FUN_100079b0(void *this,wchar_t *param_1)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_1);
  FID_conflict_assign(this,(undefined4 *)param_1,sVar1);
  return;
}



// Function: FUN_100079d0 at 100079d0

undefined4
FUN_100079d0(int *param_1,ushort param_2,undefined4 param_3,int param_4,undefined4 param_5,
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
    FUN_100078bb(&param_1);
    iVar1 = piVar2[2];
    param_1[2] = iVar4;
    param_1[3] = iVar1;
    uVar3 = (**(code **)*param_1)(param_1,&DAT_10011a00,param_6);
  }
  return uVar3;
}



// Function: FUN_10007a3c at 10007a3c

void __thiscall
FUN_10007a3c(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

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
    FUN_100065a3(this,param_4 + 3);
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
LAB_10007b0b:
        *(undefined1 *)(piVar1 + 0xb) = 1;
        *(undefined1 *)(iVar4 + 0x2c) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
        piVar5 = *(int **)(piVar5[1] + 4);
      }
      else {
        if (piVar5 == (int *)piVar1[2]) {
          FUN_100034e8(this,(int)piVar1);
          piVar5 = piVar1;
        }
        *(undefined1 *)(piVar5[1] + 0x2c) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
        FUN_1000352d(this,*(int **)(piVar5[1] + 4));
      }
    }
    else {
      iVar4 = *piVar2;
      if (*(char *)(iVar4 + 0x2c) == '\0') goto LAB_10007b0b;
      if (piVar5 == (int *)*piVar1) {
        FUN_1000352d(this,piVar1);
        piVar5 = piVar1;
      }
      *(undefined1 *)(piVar5[1] + 0x2c) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
      FUN_100034e8(this,*(int *)(piVar5[1] + 4));
    }
    iVar4 = piVar5[1];
  } while( true );
}



// Function: FUN_10007b74 at 10007b74

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10007b74(void *this,undefined4 *param_1)

{
  FUN_1000797d(this,param_1,param_1 + 7);
  return this;
}



// Function: FUN_10007ba2 at 10007ba2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall
FUN_10007ba2(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4,
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



// Function: FUN_10007c09 at 10007c09

void __thiscall FUN_10007c09(void *this,int *param_1,int *param_2,undefined4 *param_3)

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
      iVar2 = FUN_10001584(this_00,(ushort *)(puVar3 + 3));
      local_8 = iVar2 < 0;
    }
    else {
      iVar2 = FUN_10001584(puVar3 + 3,this_00);
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
      goto LAB_10007c7f;
    }
    FUN_10006aac((int *)&param_3);
  }
  puVar3 = param_3;
  iVar2 = FUN_10001584(param_3 + 3,this_00);
  if (-1 < iVar2) {
    FUN_100065a3((int)this + 0xd,this_00);
    operator_delete(param_2);
    *param_1 = (int)puVar3;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_10007c7f:
  piVar1 = (int *)FUN_10007a3c(this,&param_3,local_8,local_c,param_2);
  *param_1 = *piVar1;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}



// Function: FUN_10007cdf at 10007cdf

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10007cdf(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_74 [48];
  undefined1 local_44 [60];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 100;
  local_8 = 0x10007ceb;
  FUN_10007ba2(local_44,param_1,0,param_2,L"",0);
  local_8 = 0;
  FUN_1000792d(local_74,(int)local_44);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_74,(ThrowInfo *)&DAT_10014534);
}



// Function: FUN_10007d21 at 10007d21

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_10007d21(void *param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = &LAB_1000ff82;
  if (param_1 != (void *)0x0) {
    puVar1 = (undefined1 *)FUN_10007b74(param_1,param_2);
  }
  return puVar1;
}



// Function: FUN_10007d4f at 10007d4f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10007d4f(void *this,undefined4 *param_1,undefined4 *param_2)

{
  basic_string<>(this,param_1);
  *(undefined4 *)((int)this + 0x1c) = *param_2;
  return this;
}



// Function: FUN_10007d82 at 10007d82

/* WARNING: Variable defined which should be unmapped: param_2 */

undefined4 * __thiscall FUN_10007d82(void *param_1,undefined4 *param_2,int *param_3,int *param_4)

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
      iVar3 = FUN_10001584(this,(ushort *)(param_3 + 3));
      if (-1 < iVar3) goto LAB_10007e92;
      cVar5 = '\x01';
      goto LAB_10007d9e;
    }
    if (param_3 == piVar1) {
      iVar3 = FUN_10001584((void *)(piVar1[2] + 0xc),this);
      if (-1 < iVar3) goto LAB_10007e92;
      param_3 = *(int **)(*(int *)((int)param_1 + 4) + 8);
      cVar5 = '\0';
      goto LAB_10007d9e;
    }
    iVar3 = FUN_10001584(this,(ushort *)(param_3 + 3));
    if (iVar3 < 0) {
      param_4 = param_3;
      FUN_10006aac((int *)&param_4);
      piVar1 = param_4;
      iVar3 = FUN_10001584(param_4 + 3,this);
      if (-1 < iVar3) goto LAB_10007e41;
      cVar5 = *(char *)(piVar1[2] + 0x2d);
      piVar6 = param_3;
    }
    else {
LAB_10007e41:
      iVar3 = FUN_10001584(param_3 + 3,(ushort *)(piVar2 + 3));
      if (-1 < iVar3) {
LAB_10007e92:
        puVar4 = (undefined4 *)FUN_10007c09(param_1,(int *)&local_c,piVar2,(undefined4 *)0x0);
        *param_2 = *puVar4;
        return param_2;
      }
      param_4 = param_3;
      FUN_100034ad((int *)&param_4);
      if ((param_4 != *(int **)((int)param_1 + 4)) &&
         (iVar3 = FUN_10001584(piVar2 + 3,(ushort *)(param_4 + 3)), -1 < iVar3)) goto LAB_10007e92;
      cVar5 = *(char *)(param_3[2] + 0x2d);
      piVar1 = param_3;
      piVar6 = param_4;
    }
    param_3 = piVar1;
    if (cVar5 != '\0') {
      cVar5 = '\0';
      goto LAB_10007d9e;
    }
  }
  cVar5 = '\x01';
  param_3 = piVar6;
LAB_10007d9e:
  FUN_10007a3c(param_1,param_2,cVar5,param_3,piVar2);
  return param_2;
}



// Function: FUN_10007eae at 10007eae

void __thiscall FUN_10007eae(void *this,int param_1)

{
                    /* WARNING: Load size is inaccurate */
  if ((*this == '\0') && (param_1 < 0)) {
    *(undefined1 *)this = 1;
    FUN_10007cdf(param_1,*(undefined4 *)((int)this + 4));
  }
  return;
}



// Function: FUN_10007ece at 10007ece

void __cdecl FUN_10007ece(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  FUN_10007d21(param_2,param_3);
  return;
}



// Function: FUN_10007ee1 at 10007ee1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10007ee1(void *this,undefined4 *param_1)

{
  FUN_10007d4f(this,param_1,param_1 + 7);
  return this;
}



// Function: FUN_10007f0f at 10007f0f

int __thiscall FUN_10007f0f(void *this,int param_1)

{
  *(int *)((int)this + 0xc) = param_1;
  FUN_10007eae((void *)((int)this + 4),param_1);
  return (int)this;
}



// Function: FUN_10007f2b at 10007f2b

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_10007f2b(void *this,undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_10006d11((int)this);
  FUN_10007ece((int)this + 0xd,(void *)(iVar1 + 0xc),param_1);
  return iVar1;
}



// Function: Catch@10007f68 at 10007f68

void Catch_10007f68(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10007f7b at 10007f7b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_10007f7b(void *param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = &LAB_1000ff82;
  if (param_1 != (void *)0x0) {
    puVar1 = (undefined1 *)FUN_10007ee1(param_1,param_2);
  }
  return puVar1;
}



// Function: FUN_10007fa9 at 10007fa9

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10007fa9(void *this,undefined *param_1)

{
  int iVar1;
  undefined **ppuVar2;
  undefined4 local_28 [3];
  undefined4 local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x10007fb5;
  FUN_10006cf9(local_28);
  local_8 = 1;
  if (*(char *)((int)this + 0x14) == '\0') {
                    /* WARNING: Load size is inaccurate */
    iVar1 = (**(code **)(*this + 0x2c))(param_1);
    FUN_10007f0f(local_28,iVar1);
  }
  local_18 = 0;
  while( true ) {
    iVar1 = local_18;
    ppuVar2 = FUN_100089b0();
    if (ppuVar2[iVar1] == (undefined *)0x0) break;
    ppuVar2 = FUN_100089b0();
    param_1 = ppuVar2[iVar1];
                    /* WARNING: Load size is inaccurate */
    iVar1 = (**(code **)(*this + 0x28))(&param_1);
    FUN_10007f0f(local_28,iVar1);
    local_18 = local_18 + 1;
  }
  return local_1c;
}



// Function: Catch@10008026 at 10008026

undefined4 Catch_10008026(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10008017;
}



// Function: FUN_10008030 at 10008030

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10008030(void *this,undefined4 *param_1)

{
  int *piVar1;
  undefined4 **ppuVar2;
  int iVar3;
  undefined4 local_24 [3];
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x1000803c;
  FUN_10006cf9(local_24);
  local_8 = 1;
  if (*(char *)((int)this + 0x14) == '\0') {
    if (param_1 != (undefined4 *)0x0) {
      iVar3 = (**(code **)*param_1)(param_1,&DAT_10011994,(undefined4 *)((int)this + 0x18));
      FUN_10007f0f(local_24,iVar3);
      piVar1 = *(int **)((int)this + 0x18);
      ppuVar2 = FUN_10009ab7();
      if (ppuVar2 == (undefined4 **)0x0) {
        param_1 = (undefined4 *)0x0;
      }
      else {
        param_1 = (undefined4 *)Ordinal_2(ppuVar2);
        if (param_1 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_10001038(0x8007000e);
        }
      }
      local_8._0_1_ = 2;
      iVar3 = (**(code **)(*piVar1 + 0x1c))(piVar1,param_1);
      FUN_10007f0f(local_24,iVar3);
      local_8 = CONCAT31(local_8._1_3_,1);
      Ordinal_6(param_1);
      goto LAB_100080b5;
    }
    iVar3 = -0x7fffbffd;
  }
  else {
    iVar3 = 0;
  }
  FUN_10007f0f(local_24,iVar3);
LAB_100080b5:
  *(undefined1 *)((int)this + 0x14) = 1;
  return local_18;
}



// Function: Catch@100080e3 at 100080e3

undefined4 Catch_100080e3(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x100080bc;
}



// Function: FUN_100080ed at 100080ed

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100080ed(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_28 [3];
  undefined4 local_1c;
  undefined4 *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x100080f9;
  FUN_10006cf9(local_28);
  local_8 = 1;
  iVar1 = FUN_10007849(local_18);
  FUN_10007f0f(local_28,iVar1);
  local_18[0][2] = param_1;
  iVar1 = (**(code **)*local_18[0])(local_18[0],&DAT_100119a4,param_2);
  FUN_10007f0f(local_28,iVar1);
  return local_1c;
}



// Function: Catch@1000814d at 1000814d

undefined4 Catch_1000814d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000813e;
}



// Function: FUN_10008157 at 10008157

void __cdecl FUN_10008157(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  FUN_10007f7b(param_2,param_3);
  return;
}



// Function: FUN_1000816a at 1000816a

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000816a(void *this,ushort *param_1)

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
  local_8 = 0x10008176;
  piVar1 = FUN_10006d82(this,param_1);
  if (piVar1 != *(int **)((int)this + 4)) {
    iVar2 = FUN_10001584(param_1,(ushort *)(piVar1 + 3));
    if (-1 < iVar2) goto LAB_100081d9;
  }
  basic_string<>(local_34,(undefined4 *)param_1);
  local_18 = 0;
  local_8 = 2;
  piVar3 = (int *)FUN_10007f2b(this,local_34);
  FUN_10007d82(this,&local_38,piVar1,piVar3);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_34,'\x01',0);
LAB_100081d9:
  FUN_1000dc87();
  return;
}



// Function: FUN_100081e4 at 100081e4

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_100081e4(void *this,undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_10006d11((int)this);
  FUN_10008157((int)this + 0xd,(void *)(iVar1 + 0xc),param_1);
  return iVar1;
}



// Function: Catch@10008221 at 10008221

void Catch_10008221(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10008234 at 10008234

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10008234(int param_1,undefined4 param_2)

{
  undefined **ppuVar1;
  undefined4 *puVar2;
  ushort local_30 [20];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x10008240;
  ppuVar1 = FUN_100089b0();
  FUN_10001bb0(local_30,(wchar_t *)ppuVar1[*(int *)(param_1 + 8)]);
  local_8 = 0;
  puVar2 = (undefined4 *)FUN_1000816a((void *)(*(int *)(param_1 + 0xc) + 4),local_30);
  (*(code *)**(undefined4 **)*puVar2)((undefined4 *)*puVar2,&DAT_10011a78,param_2);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_1000dc87();
  return;
}



// Function: FUN_10008295 at 10008295

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10008295(int param_1,int *param_2)

{
  int iVar1;
  undefined **ppuVar2;
  int *piVar3;
  undefined4 *puVar4;
  ushort local_30 [20];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x100082a1;
  ppuVar2 = FUN_100089b0();
  FUN_10001bb0(local_30,(wchar_t *)ppuVar2[*(int *)(param_1 + 8)]);
  local_8 = 0;
  piVar3 = (int *)FUN_1000816a((void *)(*(int *)(param_1 + 0xc) + 4),local_30);
  iVar1 = *piVar3;
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  if (iVar1 != 0) {
    ppuVar2 = FUN_100089b0();
    FUN_10001bb0(local_30,(wchar_t *)ppuVar2[*(int *)(param_1 + 8)]);
    local_8 = 1;
    puVar4 = (undefined4 *)FUN_1000816a((void *)(*(int *)(param_1 + 0xc) + 4),local_30);
    (**(code **)(*(int *)*puVar4 + 8))((int *)*puVar4);
    local_8 = 0xffffffff;
    FID_conflict__Tidy(local_30,'\x01',0);
    ppuVar2 = FUN_100089b0();
    FUN_10001bb0(local_30,(wchar_t *)ppuVar2[*(int *)(param_1 + 8)]);
    local_8 = 2;
    puVar4 = (undefined4 *)FUN_1000816a((void *)(*(int *)(param_1 + 0xc) + 4),local_30);
    *puVar4 = 0;
    local_8 = 0xffffffff;
    FID_conflict__Tidy(local_30,'\x01',0);
  }
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 4))(param_2);
  }
  local_8 = 4;
  ppuVar2 = FUN_100089b0();
  FUN_10001bb0(local_30,(wchar_t *)ppuVar2[*(int *)(param_1 + 8)]);
  local_8._0_1_ = 5;
  puVar4 = (undefined4 *)FUN_1000816a((void *)(*(int *)(param_1 + 0xc) + 4),local_30);
  *puVar4 = param_2;
  local_8._0_1_ = 4;
  FID_conflict__Tidy(local_30,'\x01',0);
  ppuVar2 = FUN_100089b0();
  FUN_10001bb0(local_30,(wchar_t *)ppuVar2[*(int *)(param_1 + 8)]);
  local_8._0_1_ = 6;
  puVar4 = (undefined4 *)FUN_1000816a((void *)(*(int *)(param_1 + 0xc) + 4),local_30);
  (**(code **)(*(int *)*puVar4 + 4))((int *)*puVar4);
  local_8 = CONCAT31(local_8._1_3_,4);
  FID_conflict__Tidy(local_30,'\x01',0);
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  FUN_1000dc87();
  return;
}



// Function: FUN_10008401 at 10008401

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10008401(void *this,ushort *param_1)

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
  local_8 = 0x1000840d;
  piVar1 = FUN_10006d82(this,param_1);
  if (piVar1 != *(int **)((int)this + 4)) {
    iVar2 = FUN_10001584(param_1,(ushort *)(piVar1 + 3));
    if (-1 < iVar2) goto LAB_10008470;
  }
  basic_string<>(local_34,(undefined4 *)param_1);
  local_18 = 0;
  local_8 = 2;
  piVar3 = (int *)FUN_100081e4(this,local_34);
  FUN_10007d82(this,&local_38,piVar1,piVar3);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_34,'\x01',0);
LAB_10008470:
  FUN_1000dc87();
  return;
}



// Function: FUN_1000847b at 1000847b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000847b(void *this,byte param_1)

{
  FUN_10006987((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_100084ac at 100084ac

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_100084ac(void *this,int *param_1)

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
  local_8 = 0x100084b8;
  piVar1 = *(int **)((int)this + 0x18);
  if (*param_1 == 0) {
    local_34 = 0;
  }
  else {
    local_34 = Ordinal_2(*param_1);
    if (local_34 == 0) goto LAB_100084e9;
  }
  local_8 = 0;
  ppuVar2 = FUN_10009ab7();
  if (ppuVar2 == (undefined4 **)0x0) {
    local_38 = 0;
  }
  else {
    local_38 = Ordinal_2(ppuVar2);
    if (local_38 == 0) {
LAB_100084e9:
                    /* WARNING: Subroutine does not return */
      FUN_10001038(0x8007000e);
    }
  }
  local_8._0_1_ = 1;
  (**(code **)(*piVar1 + 0x24))(piVar1,local_38,local_34,&local_3c);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(local_38);
  local_8 = 0xffffffff;
  Ordinal_6(local_34);
  puVar3 = FUN_10001bb0(local_30,(wchar_t *)*param_1);
  local_8 = 2;
  puVar4 = (undefined4 *)FUN_10008401((void *)((int)this + 4),puVar3);
  *puVar4 = local_3c;
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_1000dc87();
  return;
}



// Function: FUN_1000856a at 1000856a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000856a(undefined4 *param_1)

{
  FUN_1000aa12((int)param_1);
  *param_1 = ATL::CComObject<class_CAddInFactory>::vftable;
  param_1[1] = ATL::CComObject<class_CAddInFactory>::vftable;
  param_1[8] = ATL::CComObject<class_CAddInFactory>::vftable;
  param_1[9] = ATL::CComObject<class_CAddInFactory>::vftable;
  (**(code **)(*DAT_10017c38 + 4))();
  return param_1;
}



// Function: FUN_100085b8 at 100085b8

void __thiscall FUN_100085b8(void *this,byte param_1)

{
  FUN_100087eb((void *)((int)this + -4),param_1);
  return;
}



// Function: FUN_100085c0 at 100085c0

void FUN_100085c0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x28));
  return;
}



// Function: FUN_100085d4 at 100085d4

LONG FUN_100085d4(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement((LONG *)(param_1 + 0x28));
  if ((LVar1 == 0) && (param_1 != 0)) {
    (**(code **)(*(int *)(param_1 + 4) + 0x14))(1);
  }
  return LVar1;
}



// Function: QueryInterface at 10008602

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10011b28,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_1000861c at 1000861c

void FUN_1000861c(int param_1)

{
  FUN_100085c0(param_1 + -0x24);
  return;
}



// Function: FUN_10008626 at 10008626

void FUN_10008626(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -0x20),param_2);
  return;
}



// Function: FUN_10008630 at 10008630

void FUN_10008630(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_1000863a at 1000863a

void FUN_1000863a(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -0x24),param_2);
  return;
}



// Function: FUN_10008644 at 10008644

void FUN_10008644(int param_1)

{
  FUN_100085d4(param_1 + -0x20);
  return;
}



// Function: FUN_1000864e at 1000864e

void FUN_1000864e(int param_1)

{
  FUN_100085d4(param_1 + -4);
  return;
}



// Function: FUN_10008658 at 10008658

void FUN_10008658(int param_1)

{
  FUN_100085d4(param_1 + -0x24);
  return;
}



// Function: FUN_10008662 at 10008662

void FUN_10008662(int param_1)

{
  FUN_100085c0(param_1 + -0x20);
  return;
}



// Function: FUN_1000866c at 1000866c

void FUN_1000866c(int param_1)

{
  FUN_100085c0(param_1 + -4);
  return;
}



// Function: FUN_10008676 at 10008676

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10008676(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CAddInFactory>::vftable;
  param_1[1] = ATL::CComObject<class_CAddInFactory>::vftable;
  param_1[8] = ATL::CComObject<class_CAddInFactory>::vftable;
  param_1[9] = ATL::CComObject<class_CAddInFactory>::vftable;
  param_1[10] = 0xc0000001;
  FUN_100096e1((int)param_1);
  (**(code **)(*DAT_10017c38 + 8))();
  FUN_10006987((int)param_1);
  return;
}



// Function: FUN_100086ce at 100086ce

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100086ce(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CAddInFactory>::vftable;
  FUN_10006a3d((void *)((int)this + 0x10),param_1);
  (**(code **)(*DAT_10017c38 + 4))();
  return (undefined4 *)this;
}



// Function: FUN_10008711 at 10008711

long FUN_10008711(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 4,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10011b28,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_1000875d at 1000875d

void FUN_1000875d(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



// Function: Release at 10008771

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



// Function: FUN_1000879e at 1000879e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000879e(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CAddInFactory>::vftable;
  param_1[1] = 0xc0000001;
  FUN_100096e1((int)(param_1 + 4));
  (**(code **)(*DAT_10017c38 + 8))();
  FUN_10006987((int)(param_1 + 4));
  return;
}



// Function: FUN_100087eb at 100087eb

undefined4 * __thiscall FUN_100087eb(void *this,byte param_1)

{
  FUN_10008676((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000880a at 1000880a

undefined4 * __thiscall FUN_1000880a(void *this,byte param_1)

{
  FUN_1000879e((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10008829 at 10008829

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10008829(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0xe8);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_1000856a(puVar1);
    }
    iVar2 = FUN_10008890();
    return iVar2;
  }
  return -0x7fffbffd;
}



// Function: Catch@10008880 at 10008880

undefined * Catch_10008880(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000888a;
}



// Function: FUN_10008890 at 10008890

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10008890(void)

{
  LONG *lpAddend;
  int unaff_EBX;
  undefined4 *unaff_ESI;
  
  if (unaff_ESI != (undefined4 *)0x0) {
    lpAddend = unaff_ESI + 10;
    InterlockedIncrement(lpAddend);
    unaff_EBX = FUN_10002b72((int)lpAddend);
    if (-1 < unaff_EBX) {
      unaff_EBX = 0;
    }
    InterlockedDecrement(lpAddend);
    if ((unaff_EBX == 0) && (unaff_EBX = (**(code **)*unaff_ESI)(), unaff_EBX == 0)) {
      return 0;
    }
    (**(code **)(unaff_ESI[1] + 0x14))(1);
  }
  return unaff_EBX;
}



// Function: FUN_100088dd at 100088dd

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_100088dd(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int iVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0xf8);
    if (this != (void *)0x0) {
      FUN_100086ce(this,param_1);
    }
    iVar1 = FUN_1000894e();
    return iVar1;
  }
  return -0x7fffbffd;
}



// Function: Catch@1000893e at 1000893e

undefined * Catch_1000893e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10008948;
}



// Function: FUN_1000894e at 1000894e

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_1000894e(void)

{
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_EDI = FUN_10002b72((int)(unaff_ESI + 0xe));
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



// Function: FUN_10008990 at 10008990

void FUN_10008990(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_10008829(0,param_2,param_3);
    return;
  }
  FUN_100088dd(param_1,param_2,param_3);
  return;
}



// Function: FUN_100089b0 at 100089b0

undefined ** FUN_100089b0(void)

{
  return &PTR_u__FB0FF818_0FF9_43AB_BFAE_22CB56E_10011bfc;
}



// Function: FUN_100089b6 at 100089b6

int * FUN_100089b6(int *param_1,int *param_2)

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



// Function: FUN_100089e9 at 100089e9

void __thiscall FUN_100089e9(void *this,undefined4 param_1,undefined4 param_2)

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
  (**(code **)(**this + 0x18))(*this,param_1,&PTR_100120c8,0x400,1,&local_14,param_2,0,0);
  return;
}



// Function: FUN_10008a21 at 10008a21

void __thiscall FUN_10008a21(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

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
  (**(code **)(**this + 0x18))(*this,param_1,&PTR_100120c8,0x400,1,&local_14,param_3,0,0);
  return;
}



// Function: FUN_10008a60 at 10008a60

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10008a60(void *this,undefined4 param_1)

{
  undefined4 *puVar1;
  
  *(undefined4 *)this = param_1;
  puVar1 = (undefined4 *)operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 1;
  }
  *(undefined4 **)((int)this + 4) = puVar1;
  return (undefined4 *)this;
}



// Function: Catch@10008a9e at 10008a9e

void Catch_10008a9e(void)

{
  int unaff_EBP;
  
  if (*(undefined4 **)(unaff_EBP + 8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_EBP + 8))(1);
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10008ab5 at 10008ab5

void __fastcall FUN_10008ab5(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[1];
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*param_1)(1);
    }
    operator_delete((void *)param_1[1]);
  }
  return;
}



// Function: FUN_10008ad6 at 10008ad6

void __fastcall FUN_10008ad6(int *param_1)

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



// Function: FUN_10008b1c at 10008b1c

undefined4 __thiscall FUN_10008b1c(void *this,undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)((int)this + 8))(param_1);
  return CONCAT31((int3)((uint)uVar1 >> 8),1);
}



// Function: FUN_10008b33 at 10008b33

void __fastcall FUN_10008b33(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == 0) {
    return;
  }
  uVar1 = Ordinal_149(*param_1);
  Ordinal_150(*param_1,uVar1);
  return;
}



// Function: FUN_10008b50 at 10008b50

void __fastcall FUN_10008b50(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: FUN_10008b58 at 10008b58

undefined2 * __thiscall FUN_10008b58(void *this,int *param_1)

{
  int iVar1;
  
  iVar1 = Ordinal_9(this);
  if (-1 < iVar1) {
    *(undefined2 *)this = 8;
    iVar1 = FUN_10008b33(param_1);
    *(int *)((int)this + 8) = iVar1;
    if ((iVar1 != 0) || (*param_1 == 0)) {
      return (undefined2 *)this;
    }
    *(undefined2 *)this = 10;
    iVar1 = -0x7ff8fff2;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
  }
                    /* WARNING: Subroutine does not return */
  FUN_10001038(iVar1);
}



// Function: FUN_10008ba3 at 10008ba3

undefined2 * __thiscall FUN_10008ba3(void *this,int param_1)

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
  FUN_10001038(iVar1);
}



// Function: FUN_10008bf1 at 10008bf1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10008bf1(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10008c20 at 10008c20

uint __thiscall FUN_10008c20(void *this,uint param_1)

{
  uint uVar1;
  
                    /* WARNING: Load size is inaccurate */
  uVar1 = *(int *)((int)this + 8) - *this >> 4;
  if (0xfffffff - (uVar1 >> 1) < uVar1) {
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



// Function: FUN_10008c4c at 10008c4c

undefined4 * __thiscall FUN_10008c4c(void *this,int *param_1)

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
      if ((int)puVar2[3] < *param_1) {
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



// Function: FUN_10008c78 at 10008c78

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_10008c78(IMAGE_DOS_HEADER *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10008c84;
  if (param_1 == (IMAGE_DOS_HEADER *)0x0) {
    return (void *)0x0;
  }
  if ((param_1 < &IMAGE_DOS_HEADER_10000000) &&
     (pvVar1 = operator_new((int)param_1 << 4), pvVar1 != (void *)0x0)) {
    return pvVar1;
  }
  param_1 = (IMAGE_DOS_HEADER *)0x0;
  std::exception::exception((exception *)local_1c,(char **)&param_1);
  local_1c[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10013448);
}



// Function: FUN_10008cd7 at 10008cd7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_10008cd7(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10008ce3;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10013448);
}



// Function: FUN_10008d36 at 10008d36

undefined4 * __cdecl FUN_10008d36(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_1 != param_2) {
    do {
      puVar1 = param_3 + 4;
      *param_3 = *param_1;
      param_3[1] = param_1[1];
      puVar2 = param_1 + 3;
      param_3[2] = param_1[2];
      param_1 = param_1 + 4;
      param_3[3] = *puVar2;
      param_3 = puVar1;
    } while (param_1 != param_2);
  }
  return param_3;
}



// Function: FUN_10008d5f at 10008d5f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __cdecl FUN_10008d5f(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
  }
  return &LAB_1000ff82;
}



// Function: FUN_10008d8d at 10008d8d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_10008d8d(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
  }
  return &LAB_1000ff82;
}



// Function: FUN_10008dba at 10008dba

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10008dba(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10008ddf at 10008ddf

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10008ddf(int param_1)

{
  FUN_10008bf1(param_1);
  return;
}



// Function: FUN_10008dfd at 10008dfd

void __fastcall FUN_10008dfd(undefined4 *param_1)

{
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  param_1[3] = 0x80004005;
  return;
}



// Function: FUN_10008e17 at 10008e17

void __cdecl
FUN_10008e17(int *param_1,undefined2 *param_2,undefined2 *param_3,undefined2 *param_4,
            undefined *param_5)

{
  undefined2 uVar1;
  
  if (param_2 != param_3) {
    do {
      uVar1 = (*(code *)param_5)(*param_2);
      *param_4 = uVar1;
      param_4 = param_4 + 1;
      param_2 = param_2 + 1;
    } while (param_2 != param_3);
  }
  *param_1 = (int)param_4;
  return;
}



// Function: FUN_10008e4a at 10008e4a

void __fastcall FUN_10008e4a(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_10008cd7((char *)0x1);
  *puVar1 = *(undefined4 *)(param_1 + 4);
  puVar1[1] = *(undefined4 *)(param_1 + 4);
  puVar1[2] = *(undefined4 *)(param_1 + 4);
  *(undefined2 *)(puVar1 + 5) = 0;
  return;
}



// Function: FUN_10008e71 at 10008e71

void __cdecl FUN_10008e71(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  FUN_10008d8d(param_2,param_3);
  return;
}



// Function: FUN_10008e84 at 10008e84

void __thiscall FUN_10008e84(void *this,int *param_1)

{
  void *pvVar1;
  
  pvVar1 = this;
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    pvVar1 = *this;
  }
  *param_1 = (int)((int)pvVar1 + *(int *)((int)this + 0x10) * 2);
  return;
}



// Function: FUN_10008ea2 at 10008ea2

int __fastcall FUN_10008ea2(int param_1)

{
  void *pvVar1;
  
  *(undefined4 *)(param_1 + 8) = 0;
  pvVar1 = FUN_10008cd7((char *)0x1);
  *(void **)(param_1 + 4) = pvVar1;
  *(void **)pvVar1 = pvVar1;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x14) = 1;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x15) = 1;
  return param_1;
}



// Function: FUN_10008ed9 at 10008ed9

int __fastcall FUN_10008ed9(int param_1)

{
  void *pvVar1;
  
  *(undefined4 *)(param_1 + 8) = 0;
  pvVar1 = FUN_10006b5b((char *)0x1);
  *(void **)(param_1 + 4) = pvVar1;
  *(void **)pvVar1 = pvVar1;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x2c) = 1;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x2d) = 1;
  return param_1;
}



// Function: FUN_10008f10 at 10008f10

int * __cdecl
FUN_10008f10(int *param_1,undefined2 *param_2,undefined2 *param_3,undefined2 *param_4,
            undefined *param_5)

{
  if (param_2 != param_3) {
    FUN_10008e17(param_1,param_2,param_3,param_4,param_5);
    return param_1;
  }
  *param_1 = (int)param_4;
  return param_1;
}



// Function: FUN_10008f3f at 10008f3f

void __cdecl FUN_10008f3f(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  FUN_10008d5f(param_2,param_3);
  return;
}



// Function: FUN_10008f51 at 10008f51

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10008f51(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}



// Function: FUN_10008f8a at 10008f8a

void __thiscall
FUN_10008f8a(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

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
LAB_1000904a:
        *(undefined1 *)(piVar1 + 5) = 1;
        *(undefined1 *)(iVar4 + 0x14) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x14) = 0;
        piVar5 = *(int **)(piVar5[1] + 4);
      }
      else {
        if (piVar5 == (int *)piVar1[2]) {
          FUN_10003c34(this,(int)piVar1);
          piVar5 = piVar1;
        }
        *(undefined1 *)(piVar5[1] + 0x14) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x14) = 0;
        FUN_10003574(this,*(int **)(piVar5[1] + 4));
      }
    }
    else {
      iVar4 = *piVar2;
      if (*(char *)(iVar4 + 0x14) == '\0') goto LAB_1000904a;
      if (piVar5 == (int *)*piVar1) {
        FUN_10003574(this,piVar1);
        piVar5 = piVar1;
      }
      *(undefined1 *)(piVar5[1] + 0x14) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x14) = 0;
      FUN_10003c34(this,*(int *)(piVar5[1] + 4));
    }
    iVar4 = piVar5[1];
  } while( true );
}



// Function: FUN_100090b3 at 100090b3

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __cdecl
FUN_100090b3(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  for (; param_1 != param_2; param_1 = param_1 + 4) {
    FUN_10008e71(param_4,param_3,param_1);
    param_3 = param_3 + 4;
  }
  return param_3;
}



// Function: Catch@100090f1 at 100090f1

void Catch_100090f1(void)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100090fb at 100090fb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_100090fb(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
  }
  return;
}



// Function: FUN_1000912e at 1000912e

undefined4 __thiscall FUN_1000912e(void *this,int *param_1,undefined4 *param_2)

{
  if (*(int **)((int)this + 4) != param_1) {
    FUN_100089b6((int *)((int)this + 4),param_1);
  }
  *(undefined4 **)((int)this + 8) = param_2;
  *(undefined4 *)((int)this + 0xc) = *param_2;
  return 0;
}



// Function: FUN_10009157 at 10009157

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10009157(undefined4 *param_1)

{
  FUN_10008f51((int)param_1);
  *param_1 = ATL::
             CComObject<class_ATL::CComEnumOnSTL<struct_IEnumAddIns,&struct__GUID_const_IID_IEnumAddIns,struct__GUID,class_ATL::_Copy<struct__GUID>,class_std::vector<struct__GUID,class_std::allocator<struct__GUID>_>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  (**(code **)(*DAT_10017c38 + 4))();
  return param_1;
}



// Function: FUN_10009190 at 10009190

undefined4 FUN_10009190(int param_1)

{
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  return *(undefined4 *)(param_1 + 0x10);
}



// Function: Release at 100091a0

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



// Function: QueryInterface at 100091c1

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10011ca8,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_100091db at 100091db

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100091db(undefined4 *param_1)

{
  *param_1 = ATL::
             CComObject<class_ATL::CComEnumOnSTL<struct_IEnumAddIns,&struct__GUID_const_IID_IEnumAddIns,struct__GUID,class_ATL::_Copy<struct__GUID>,class_std::vector<struct__GUID,class_std::allocator<struct__GUID>_>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  param_1[4] = 0xc0000001;
  (**(code **)(*DAT_10017c38 + 8))();
  FUN_10008bf1((int)param_1);
  return;
}



// Function: FUN_10009219 at 10009219

undefined4 * __thiscall FUN_10009219(void *this,byte param_1)

{
  FUN_100091db((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10009238 at 10009238

uint FUN_10009238(int param_1,uint param_2,undefined4 *param_3,uint *param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  
  if ((param_3 == (undefined4 *)0x0) || ((1 < param_2 && (param_4 == (uint *)0x0)))) {
    uVar2 = 0x80004003;
  }
  else {
    if (param_4 != (uint *)0x0) {
      *param_4 = 0;
    }
    if (*(int *)(param_1 + 8) == 0) {
      uVar2 = 0x80004005;
    }
    else {
      for (uVar2 = 0;
          (puVar1 = *(undefined4 **)(param_1 + 0xc),
          puVar1 != *(undefined4 **)(*(int *)(param_1 + 8) + 4) && (uVar2 < param_2));
          uVar2 = uVar2 + 1) {
        *param_3 = *puVar1;
        param_3[1] = puVar1[1];
        param_3[2] = puVar1[2];
        param_3[3] = puVar1[3];
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 0x10;
        param_3 = param_3 + 4;
      }
      if (param_4 != (uint *)0x0) {
        *param_4 = uVar2;
      }
      uVar2 = (uint)(uVar2 < param_2);
    }
  }
  return uVar2;
}



// Function: FUN_100092ae at 100092ae

undefined4 FUN_100092ae(int param_1,int param_2)

{
  if (param_2 != 0) {
    do {
      param_2 = param_2 + -1;
      if (*(int *)(param_1 + 0xc) == *(int *)(*(int *)(param_1 + 8) + 4)) {
        return 1;
      }
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 0x10;
    } while (param_2 != 0);
  }
  return 0;
}



// Function: FUN_100092dd at 100092dd

undefined4 FUN_100092dd(int param_1)

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



// Function: FUN_100092fc at 100092fc

void __thiscall FUN_100092fc(void *this,undefined4 *param_1,int *param_2,char param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  bool local_8;
  
  puVar2 = *(undefined4 **)((int)this + 4);
  local_8 = true;
  if (*(char *)((int)puVar2[1] + 0x15) == '\0') {
    puVar1 = (undefined4 *)puVar2[1];
    do {
      puVar2 = puVar1;
      if (param_3 == '\0') {
        local_8 = param_2[3] < (int)puVar2[3];
      }
      else {
        local_8 = param_2[3] <= (int)puVar2[3];
      }
      if (local_8 == false) {
        puVar1 = (undefined4 *)puVar2[2];
      }
      else {
        puVar1 = (undefined4 *)*puVar2;
      }
    } while (*(char *)((int)puVar1 + 0x15) == '\0');
  }
  _param_3 = puVar2;
  if (local_8 != false) {
    if (puVar2 == (undefined4 *)**(int **)((int)this + 4)) {
      local_8 = true;
      goto LAB_10009360;
    }
    FUN_10008ad6((int *)&param_3);
  }
  puVar1 = _param_3;
  if (param_2[3] <= (int)_param_3[3]) {
    operator_delete(param_2);
    *param_1 = puVar1;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_10009360:
  puVar2 = (undefined4 *)FUN_10008f8a(this,(undefined4 *)&param_3,local_8,puVar2,param_2);
  *param_1 = *puVar2;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}



// Function: _Uninitialized_move<> at 100093ab

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
  FUN_100090b3(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_100093ca at 100093ca

void __cdecl FUN_100093ca(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  FUN_100090fb(param_2,param_3);
  return;
}



// Function: FUN_100093dd at 100093dd

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100093dd(int param_1)

{
  int *piVar1;
  int local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  local_18[0] = **(int **)(param_1 + 0xbc);
  while (local_18[0] != *(int *)(param_1 + 0xbc)) {
    piVar1 = *(int **)(local_18[0] + 0x10);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x14))(piVar1,*(undefined4 *)(local_18[0] + 0xc));
    }
    FUN_10002bbe(local_18);
  }
  return;
}



// Function: Catch@10009429 at 10009429

undefined4 Catch_10009429(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10009423;
}



// Function: FUN_10009433 at 10009433

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10009433(int *param_1)

{
  int *piVar1;
  undefined4 local_28 [4];
  int local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x1000943f;
  FUN_10006cf9(local_28);
  local_8 = 1;
  local_18[0] = *(int *)param_1[0x2f];
  while (local_18[0] != param_1[0x2f]) {
    piVar1 = *(int **)(local_18[0] + 0x10);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x18))(piVar1,*(undefined4 *)(local_18[0] + 0xc));
    }
    FUN_10002bbe(local_18);
  }
  (**(code **)(*param_1 + 0x10))(param_1);
  return;
}



// Function: Catch@10009498 at 10009498

undefined4 Catch_10009498(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000948e;
}



// Function: Catch@1000953a at 1000953a

undefined1 * Catch_1000953a(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_10009532;
}



// Function: Catch@10009612 at 10009612

undefined1 * Catch_10009612(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_1000960a;
}



// Function: FUN_1000961c at 1000961c

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000961c(int param_1)

{
  int *piVar1;
  int local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  local_18[0] = **(int **)(param_1 + 0xbc);
  while (local_18[0] != *(int *)(param_1 + 0xbc)) {
    piVar1 = *(int **)(local_18[0] + 0x10);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x1c))(piVar1,*(undefined4 *)(local_18[0] + 0xc));
    }
    FUN_10002bbe(local_18);
  }
  return;
}



// Function: Catch@10009668 at 10009668

undefined4 Catch_10009668(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10009662;
}



// Function: FUN_10009672 at 10009672

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10009672(int *param_1)

{
  int *piVar1;
  undefined4 local_28 [4];
  int local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x1000967e;
  FUN_10006cf9(local_28);
  local_8 = 1;
  local_18[0] = *(int *)param_1[0x2f];
  while (local_18[0] != param_1[0x2f]) {
    piVar1 = *(int **)(local_18[0] + 0x10);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x20))(piVar1,*(undefined4 *)(local_18[0] + 0xc));
    }
    FUN_10002bbe(local_18);
  }
  (**(code **)(*param_1 + 0x18))(param_1);
  return;
}



// Function: Catch@100096d7 at 100096d7

undefined4 Catch_100096d7(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x100096cd;
}



// Function: FUN_100096e1 at 100096e1

void __fastcall FUN_100096e1(int param_1)

{
  int local_8;
  
  local_8 = **(int **)(param_1 + 0xbc);
  if ((int *)local_8 != *(int **)(param_1 + 0xbc)) {
    do {
      (**(code **)(*(int *)(param_1 + 0x24) + 0x10))
                ((int *)(param_1 + 0x24),*(undefined4 *)(local_8 + 0xc));
      FUN_10002bbe(&local_8);
    } while (local_8 != *(int *)(param_1 + 0xbc));
  }
  return;
}



// Function: FUN_1000971b at 1000971b

void __thiscall FUN_1000971b(void *this,undefined4 *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int **ppiVar3;
  int *local_8;
  
  piVar1 = param_2;
  local_8 = (int *)this;
  piVar2 = FUN_10008c4c(this,param_2);
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



// Function: FUN_10009755 at 10009755

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10009755(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10009157(puVar1);
    }
    uVar2 = FUN_100097b0();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@100097a1 at 100097a1

undefined * Catch_100097a1(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100097ab;
}



// Function: FUN_100097b0 at 100097b0

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100097b0(void)

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



// Function: FUN_100097c7 at 100097c7

void __thiscall FUN_100097c7(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  _Uninitialized_move<>(param_1,param_2,param_3,(int)this + 0xc);
  return;
}



// Function: FUN_100097e3 at 100097e3

undefined4 * __thiscall FUN_100097e3(void *this,undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_10008f8a(this,param_1,'\x01',*(undefined4 **)((int)this + 4),param_3);
    return param_1;
  }
  piVar1 = *(int **)((int)this + 4);
  piVar5 = param_2;
  if (param_2 == (int *)*piVar1) {
    if (param_2[3] <= param_3[3]) goto LAB_100098ad;
    cVar4 = '\x01';
    goto LAB_100098a0;
  }
  if (param_2 == piVar1) {
    param_2 = (int *)piVar1[2];
    if (param_3[3] <= param_2[3]) goto LAB_100098ad;
  }
  else {
    if (param_3[3] < param_2[3]) {
      param_3 = param_2;
      FUN_10008ad6((int *)&param_3);
      if (piVar2[3] <= param_3[3]) goto LAB_10009869;
      cVar4 = *(char *)(param_3[2] + 0x15);
      param_2 = param_3;
    }
    else {
LAB_10009869:
      if (piVar2[3] <= param_2[3]) {
LAB_100098ad:
        puVar3 = (undefined4 *)FUN_100092fc(this,&local_c,piVar2,'\0');
        *param_1 = *puVar3;
        return param_1;
      }
      param_3 = param_2;
      FUN_10002bbe((int *)&param_3);
      if ((param_3 != *(int **)((int)this + 4)) && (param_3[3] <= piVar2[3])) goto LAB_100098ad;
      cVar4 = *(char *)(param_2[2] + 0x15);
      piVar5 = param_3;
    }
    if (cVar4 == '\0') {
      cVar4 = '\x01';
      goto LAB_100098a0;
    }
  }
  cVar4 = '\0';
  piVar5 = param_2;
LAB_100098a0:
  FUN_10008f8a(this,param_1,cVar4,piVar5,piVar2);
  return param_1;
}



// Function: FUN_100098c9 at 100098c9

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_100098c9(void *this,undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_10008e4a((int)this);
  FUN_100093ca((int)this + 0xd,(undefined4 *)(iVar1 + 0xc),param_1);
  return iVar1;
}



// Function: Catch@10009906 at 10009906

void Catch_10009906(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10009919 at 10009919

void __thiscall FUN_10009919(void *this,undefined4 *param_1,ushort *param_2)

{
  int iVar1;
  ushort **ppuVar2;
  ushort *local_8;
  
  local_8 = (ushort *)this;
  local_8 = (ushort *)FUN_10006d82(this,param_2);
  if (local_8 != *(ushort **)((int)this + 4)) {
    iVar1 = FUN_10001584(param_2,local_8 + 6);
    if (-1 < iVar1) {
      ppuVar2 = &local_8;
      goto LAB_1000994e;
    }
  }
  ppuVar2 = &param_2;
LAB_1000994e:
  *param_1 = *ppuVar2;
  return;
}



// Function: FUN_1000995a at 1000995a

void __thiscall FUN_1000995a(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  
  if (param_2 != param_3) {
    puVar1 = FUN_10008d36(param_3,*(undefined4 **)((int)this + 4),param_2);
    *(undefined4 **)((int)this + 4) = puVar1;
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_1000998a at 1000998a

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_1000998a(void *this,IMAGE_DOS_HEADER *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  
  if ((IMAGE_DOS_HEADER *)0xfffffff < param_1) {
    std::_Xlength_error("vector<T> too long");
  }
                    /* WARNING: Load size is inaccurate */
  if ((IMAGE_DOS_HEADER *)(*(int *)((int)this + 8) - *this >> 4) < param_1) {
    puVar1 = (undefined4 *)FUN_10008c78(param_1);
                    /* WARNING: Load size is inaccurate */
    FUN_100097c7(this,*this,*(undefined4 **)((int)this + 4),puVar1);
                    /* WARNING: Load size is inaccurate */
    iVar2 = *this;
    uVar3 = *(int *)((int)this + 4) - iVar2;
    if (iVar2 != 0) {
      for (; iVar2 != *(int *)((int)this + 4); iVar2 = iVar2 + 0x10) {
      }
                    /* WARNING: Load size is inaccurate */
      operator_delete(*this);
    }
    std::_Container_base0::_Orphan_all((_Container_base0 *)this);
    *(undefined4 **)((int)this + 8) = puVar1 + (int)param_1 * 4;
    *(uint *)((int)this + 4) = (uVar3 & 0xfffffff0) + (int)puVar1;
    *(undefined4 **)this = puVar1;
  }
  return;
}



// Function: Catch@10009a1f at 10009a1f

void Catch_10009a1f(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 8));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10009a32 at 10009a32

int FUN_10009a32(int param_1,void **param_2)

{
  int iVar1;
  int *local_8;
  
  iVar1 = -0x7fffbffd;
  if (param_2 != (void **)0x0) {
    *param_2 = (void *)0x0;
    iVar1 = FUN_10009755(&local_8);
    if (-1 < iVar1) {
      iVar1 = FUN_1000912e(local_8,*(int **)(param_1 + 4),*(undefined4 **)(param_1 + 8));
      if (-1 < iVar1) {
        local_8[3] = *(int *)(param_1 + 0xc);
        iVar1 = ATL::AtlInternalQueryInterface
                          (local_8,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10011ca8,(_GUID *)&DAT_10011da8,
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



// Function: FUN_10009aa6 at 10009aa6

void __cdecl FUN_10009aa6(undefined4 param_1,void *param_2)

{
  FID_conflict__Tidy(param_2,'\x01',0);
  return;
}



// Function: FUN_10009ab7 at 10009ab7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ** FUN_10009ab7(void)

{
  LPOLESTR pOVar1;
  size_t sVar2;
  undefined4 ***pppuVar3;
  LPOLESTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x10009ac3;
  if ((DAT_10017cc8 & 1) == 0) {
    DAT_10017cc8 = DAT_10017cc8 | 1;
    local_8 = 0;
    DAT_10017cc0 = 7;
    _DAT_10017cbc = 0;
    DAT_10017cac = (undefined4 **)((uint)DAT_10017cac & 0xffff0000);
    _atexit((_func_4879 *)&LAB_1001043b);
    local_8 = 0xffffffff;
  }
  local_14[0] = (wchar_t *)0x0;
  StringFromCLSID((IID *)&DAT_10011464,local_14);
  pOVar1 = local_14[0];
  sVar2 = wcslen(local_14[0]);
  FID_conflict_assign(&DAT_10017cac,(undefined4 *)pOVar1,sVar2);
  CoTaskMemFree(local_14[0]);
  pppuVar3 = (undefined4 ***)DAT_10017cac;
  if (DAT_10017cc0 < 8) {
    pppuVar3 = &DAT_10017cac;
  }
  return pppuVar3;
}



// Function: FUN_10009b49 at 10009b49

void __fastcall FUN_10009b49(undefined4 *param_1)

{
  undefined4 *local_8;
  
  local_8 = param_1;
  FUN_1000995a(param_1,&local_8,(undefined4 *)*param_1,(undefined4 *)param_1[1]);
  return;
}



// Function: FUN_10009b5f at 10009b5f

int * __thiscall FUN_10009b5f(void *this,int *param_1)

{
  int *piVar1;
  int *piVar2;
  void *local_c;
  void *local_8;
  
  piVar2 = param_1;
  local_c = this;
  local_8 = this;
  piVar1 = FUN_10008c4c(this,param_1);
  if ((piVar1 == *(int **)((int)this + 4)) || (*piVar2 < piVar1[3])) {
    local_c = (void *)*piVar2;
    local_8 = (void *)0x0;
    piVar2 = (int *)FUN_100098c9(this,&local_c);
    FUN_100097e3(this,&param_1,piVar1,piVar2);
    piVar1 = param_1;
  }
  return piVar1 + 4;
}



// Function: FUN_10009bae at 10009bae

void __thiscall FUN_10009bae(void *this,int param_1)

{
  uint uVar1;
  uint extraout_EAX;
  IMAGE_DOS_HEADER *pIVar2;
  int extraout_ECX;
  int iVar3;
  
                    /* WARNING: Load size is inaccurate */
  iVar3 = *this;
  uVar1 = *(int *)((int)this + 4) - iVar3 >> 4;
  if (0xfffffffU - param_1 < uVar1) {
    std::_Xlength_error("vector<T> too long");
    uVar1 = extraout_EAX;
    iVar3 = extraout_ECX;
  }
  if ((uint)(*(int *)((int)this + 8) - iVar3 >> 4) < uVar1 + param_1) {
    pIVar2 = (IMAGE_DOS_HEADER *)FUN_10008c20(this,uVar1 + param_1);
    FUN_1000998a(this,pIVar2);
  }
  return;
}



// Function: FUN_10009bf9 at 10009bf9

void __cdecl FUN_10009bf9(void *param_1,void *param_2,undefined4 param_3)

{
  for (; param_1 != param_2; param_1 = (void *)((int)param_1 + 0x1c)) {
    FUN_10009aa6(param_3,param_1);
  }
  return;
}



// Function: FUN_10009c18 at 10009c18

undefined4 FUN_10009c18(int param_1,int param_2,int param_3)

{
  void *this;
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_3 == 0) {
    uVar2 = 0x80004003;
  }
  else {
    param_3 = 0;
    iVar1 = *(int *)(param_1 + 0x98);
    this = (void *)(param_1 + 0x94);
    do {
      piVar3 = (int *)FUN_1000971b(this,&param_1,&param_3);
      if (*piVar3 == iVar1) {
        piVar3 = FUN_10009b5f(this,&param_3);
        *piVar3 = param_2;
        piVar3 = FUN_10009b5f(this,&param_3);
        (**(code **)(*(int *)*piVar3 + 4))((int *)*piVar3);
        return 0;
      }
      param_3 = param_3 + 1;
    } while (param_3 < 0xffff);
    uVar2 = 0x80004005;
  }
  return uVar2;
}



// Function: FUN_10009c8e at 10009c8e

bool FUN_10009c8e(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  bool bVar4;
  
  iVar1 = param_1;
  piVar2 = (int *)FUN_1000971b((void *)(param_1 + 0x94),&param_1,(int *)&stack0x00000008);
  bVar4 = *piVar2 != *(int *)(iVar1 + 0x98);
  if (bVar4) {
    piVar2 = FUN_10009b5f((void *)(iVar1 + 0x94),(int *)&stack0x00000008);
    (**(code **)(*(int *)*piVar2 + 8))((int *)*piVar2);
    puVar3 = (undefined4 *)FUN_1000971b((void *)(iVar1 + 0x94),&param_1,(int *)&stack0x00000008);
    FUN_10005954((void *)(iVar1 + 0x94),(undefined4 *)&stack0x00000008,(int *)*puVar3);
  }
  return !bVar4;
}



// Function: FUN_10009cfb at 10009cfb

void __thiscall FUN_10009cfb(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < puVar1) && (puVar2 = *this, puVar2 <= param_1)) {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_10009bae(this,1);
    }
                    /* WARNING: Load size is inaccurate */
    FUN_10008e71((int)this + 0xc,*(undefined4 **)((int)this + 4),
                 (undefined4 *)(((int)param_1 - (int)puVar2 & 0xfffffff0U) + *this));
  }
  else {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_10009bae(this,1);
    }
    FUN_10008f3f((int)this + 0xc,*(undefined4 **)((int)this + 4),param_1);
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x10;
  return;
}



// Function: FUN_10009d5e at 10009d5e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_10009d5e(int param_1)

{
  int aiStack_30 [5];
  undefined1 *local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10009d6a;
  local_1c = (undefined1 *)aiStack_30;
  aiStack_30[0] = param_1;
  local_18 = param_1;
  FUN_10008ea2(param_1);
  return local_18;
}



// Function: FUN_10009d8a at 10009d8a

void __fastcall FUN_10009d8a(_Container_base0 *param_1)

{
  if (*(int *)param_1 != 0) {
    std::_Container_base0::_Orphan_all(param_1);
    FUN_10009bf9(*(void **)param_1,*(void **)(param_1 + 4),param_1 + 0xc);
    operator_delete(*(void **)param_1);
  }
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: FUN_10009dc5 at 10009dc5

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10009dc5(int *param_1)

{
  int iVar1;
  int *piVar2;
  int local_50 [2];
  undefined4 local_48 [3];
  int local_3c;
  char local_35;
  ushort local_34 [22];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x40;
  local_8 = 0x10009dd1;
  FUN_10006cf9(local_48);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_100093dd((int)(param_1 + -8));
  iVar1 = FUN_1000cc45(param_1 + 0xb,param_1[10]);
  FUN_10007f0f(local_48,iVar1);
  iVar1 = FUN_1000cd5c(param_1 + 0xb);
  FUN_10007f0f(local_48,iVar1);
  FUN_10001bb0(local_34,L"{DC158D95-518B-4D65-BD72-122F96E040E0}");
  local_8._0_1_ = 2;
  piVar2 = FUN_1000c958(param_1 + 0xb,local_50,local_34);
  local_8._0_1_ = 3;
  iVar1 = FUN_10001000(*piVar2);
  local_35 = iVar1 == 3;
  local_8._0_1_ = 2;
  FUN_10008ab5(local_50);
  local_8 = CONCAT31(local_8._1_3_,1);
  FID_conflict__Tidy(local_34,'\x01',0);
  FUN_10007f0f(local_48,(local_35 != '\0') - 1 & 0x80070005);
  FUN_10009433(param_1 + -8);
  if (local_3c < 0) {
    (**(code **)(*param_1 + 0x10))(param_1);
  }
  local_8 = 0xffffffff;
  FUN_1000dc96();
  return;
}



// Function: Catch@10009e9d at 10009e9d

undefined4 Catch_10009e9d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10009e8e;
}



// Function: FUN_10009ea7 at 10009ea7

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10009ea7(int param_1)

{
  int iVar1;
  undefined4 local_24 [3];
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x10009eb3;
  FUN_10006cf9(local_24);
  local_8 = 1;
  FUN_1000961c(param_1 + -0x20);
  iVar1 = FUN_1000ce19((void *)(param_1 + 0x2c));
  FUN_10007f0f(local_24,iVar1);
  FUN_10009672((int *)(param_1 + -0x20));
  return local_18;
}



// Function: Catch@10009efa at 10009efa

undefined4 Catch_10009efa(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10009eeb;
}



// Function: FUN_10009f04 at 10009f04

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10009f04(int param_1,wchar_t *param_2,short param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 local_44 [4];
  OLECHAR local_34 [22];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x10009f10;
  FUN_10006cf9(local_44);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  piVar1 = (int *)(param_1 + -0x20);
  FUN_100093dd((int)piVar1);
  FUN_10001bb0(local_34,param_2);
  local_8._0_1_ = 2;
  iVar2 = FUN_1000c880((void *)(param_1 + 0x2c),local_34,param_3 == -1);
  FUN_10007f0f(local_44,iVar2);
  local_8 = CONCAT31(local_8._1_3_,1);
  FID_conflict__Tidy(local_34,'\x01',0);
  FUN_10009433(piVar1);
  iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1,param_2);
  FUN_10007f0f(local_44,iVar2);
  local_8 = 0xffffffff;
  FUN_1000dc96();
  return;
}



// Function: Catch@10009f98 at 10009f98

undefined4 Catch_10009f98(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10009f89;
}



// Function: FUN_10009fa2 at 10009fa2

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10009fa2(int param_1,wchar_t *param_2,short param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 local_44 [4];
  ushort local_34 [22];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x10009fae;
  FUN_10006cf9(local_44);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  piVar1 = (int *)(param_1 + -0x20);
  FUN_1000961c((int)piVar1);
  FUN_10001bb0(local_34,param_2);
  local_8._0_1_ = 2;
  iVar2 = FUN_1000c92e((void *)(param_1 + 0x2c),local_34,param_3 == -1);
  FUN_10007f0f(local_44,iVar2);
  local_8 = CONCAT31(local_8._1_3_,1);
  FID_conflict__Tidy(local_34,'\x01',0);
  iVar2 = (**(code **)(*piVar1 + 0x1c))(piVar1,param_2);
  FUN_10007f0f(local_44,iVar2);
  FUN_10009672(piVar1);
  local_8 = 0xffffffff;
  FUN_1000dc96();
  return;
}



// Function: Catch@1000a036 at 1000a036

undefined4 Catch_1000a036(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000a027;
}



// Function: FUN_1000a040 at 1000a040

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000a040(int param_1,wchar_t *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 local_58 [4];
  undefined4 local_48;
  int local_44;
  int *local_40;
  int local_3c;
  int local_38;
  undefined4 ***local_34 [5];
  uint local_20;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x48;
  local_8 = 0x1000a04c;
  local_48 = param_3;
  FUN_10006cf9(local_58);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_10001bb0(local_34,param_2);
  local_8._0_1_ = 2;
  if (local_20 < 8) {
    local_34[0] = local_34;
  }
  puVar1 = (undefined4 *)FUN_10008e84(local_34,(int *)&local_40);
  FUN_10008f10(&local_38,(undefined2 *)local_34[0],(undefined2 *)*puVar1,(undefined2 *)local_34[0],
               towupper_exref);
  piVar2 = FUN_10008a60(&local_44,0);
  local_8._0_1_ = 3;
  piVar3 = FUN_1000c958((void *)(param_1 + 0x2c),&local_3c,(ushort *)local_34);
  local_8._0_1_ = 4;
  FUN_10007f0f(local_58,(-(uint)(*piVar3 != *piVar2) & 0x7fffbffb) + 0x80004005);
  local_8._0_1_ = 3;
  FUN_10008ab5(&local_3c);
  local_8._0_1_ = 2;
  FUN_10008ab5(&local_44);
  puVar1 = FUN_1000c958((void *)(param_1 + 0x2c),&local_3c,(ushort *)local_34);
  local_8._0_1_ = 5;
  puVar1 = FUN_10001549((void *)*puVar1,&local_40);
  local_8._0_1_ = 6;
  iVar4 = (*(code *)**(undefined4 **)*puVar1)((undefined4 *)*puVar1,&DAT_10011200,local_48);
  FUN_10007f0f(local_58,iVar4);
  local_8._0_1_ = 5;
  if (local_40 != (int *)0x0) {
    (**(code **)(*local_40 + 8))(local_40);
  }
  local_8._0_1_ = 2;
  FUN_10008ab5(&local_3c);
  local_8 = CONCAT31(local_8._1_3_,1);
  FID_conflict__Tidy(local_34,'\x01',0);
  local_8 = 0xffffffff;
  FUN_1000dc96();
  return;
}



// Function: Catch@1000a18e at 1000a18e

undefined4 Catch_1000a18e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000a177;
}



// Function: FUN_1000a198 at 1000a198

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000a198(int param_1,wchar_t *param_2,undefined4 param_3)

{
  size_t sVar1;
  HRESULT HVar2;
  int iVar3;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50 [4];
  int *local_40;
  int *local_3c;
  wchar_t *local_38;
  WCHAR local_34 [22];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x4c;
  local_8 = 0x1000a1a4;
  local_38 = param_2;
  FUN_10006cf9(local_50);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_100079b0((undefined4 *)(param_1 + 0x9c),local_38);
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_8._0_1_ = 2;
  basic_string<>(local_34,(undefined4 *)(param_1 + 0x9c));
  local_8._0_1_ = 3;
  sVar1 = wcslen(L"\\AddIns");
  FUN_1000190e(local_34,(undefined4 *)L"\\AddIns",sVar1);
  FUN_1000c703((void *)(param_1 + 0x4c),local_34);
  local_38 = (wchar_t *)0x0;
  local_40 = (int *)0x0;
  local_8._0_1_ = 7;
  HVar2 = CoCreateInstance((IID *)&DAT_100120d8,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10011714,&local_40);
  FUN_10007f0f(local_50,HVar2);
  local_3c = (int *)0x0;
  local_8._0_1_ = 9;
  iVar3 = (**(code **)(*local_40 + 0x14))(local_40,param_3,&DAT_10011fa8,&local_3c);
  FUN_10007f0f(local_50,iVar3);
  iVar3 = (**(code **)(*local_3c + 0x10))(local_3c,&local_38);
  FUN_10007f0f(local_50,iVar3);
  iVar3 = (**(code **)(*(int *)(param_1 + 4) + 0x1c))(local_38);
  FUN_10007f0f(local_50,iVar3);
  *(undefined4 *)(param_1 + 0x48) = param_3;
  local_8._0_1_ = 7;
  if (local_3c != (int *)0x0) {
    (**(code **)(*local_3c + 8))(local_3c);
  }
  local_8._0_1_ = 5;
  if (local_40 != (int *)0x0) {
    (**(code **)(*local_40 + 8))(local_40);
  }
  local_8._0_1_ = 3;
  if (local_38 != (wchar_t *)0x0) {
    (**(code **)(*(int *)local_38 + 8))(local_38);
  }
  local_8._0_1_ = 2;
  FID_conflict__Tidy(local_34,'\x01',0);
  local_8 = CONCAT31(local_8._1_3_,1);
  ATL::CRegKey::Close((CRegKey *)&local_5c);
  local_8 = 0xffffffff;
  FUN_1000dc96();
  return;
}



// Function: Catch@1000a304 at 1000a304

undefined4 Catch_1000a304(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000a2f5;
}



// Function: FUN_1000a30e at 1000a30e

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000a30e(int param_1,wchar_t *param_2,wchar_t *param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 local_9c [4];
  int local_8c [2];
  undefined2 local_84 [8];
  int local_74;
  int local_70;
  undefined1 local_6c [28];
  ushort local_50 [14];
  ushort local_34 [22];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x8c;
  local_8 = 0x1000a31d;
  local_74 = param_4;
  FUN_10008dfd(local_9c);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_10007f0f(local_9c,(-(uint)(local_74 != 0) & 0x7fffbffd) + 0x80004003);
  FUN_10001bb0(local_50,param_3);
  local_8._0_1_ = 2;
  FUN_10001bb0(local_34,param_2);
  local_8._0_1_ = 3;
  puVar1 = FUN_1000c958((void *)(param_1 + 0x2c),local_8c,local_34);
  local_8._0_1_ = 4;
  puVar1 = (undefined4 *)FUN_10001c3f((void *)*puVar1,local_6c,local_50);
  local_8._0_1_ = 5;
  if (7 < (uint)puVar1[5]) {
    puVar1 = (undefined4 *)*puVar1;
  }
  if (puVar1 == (undefined4 *)0x0) {
    local_70 = 0;
  }
  else {
    local_70 = Ordinal_2(puVar1);
    if (local_70 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_10001038(0x8007000e);
    }
  }
  local_8._0_1_ = 6;
  local_84[0] = 0;
  FUN_10008b58(local_84,&local_70);
  local_8._0_1_ = 8;
  Ordinal_6(local_70);
  local_8._0_1_ = 9;
  FID_conflict__Tidy(local_6c,'\x01',0);
  local_8._0_1_ = 10;
  FUN_10008ab5(local_8c);
  local_8._0_1_ = 0xb;
  FID_conflict__Tidy(local_34,'\x01',0);
  local_8._0_1_ = 0xc;
  FID_conflict__Tidy(local_50,'\x01',0);
  Ordinal_10(local_74,local_84);
  local_8 = CONCAT31(local_8._1_3_,1);
  Ordinal_9(local_84);
  local_8 = 0xffffffff;
  FUN_1000dc96();
  return;
}



// Function: Catch@1000a467 at 1000a467

undefined4 Catch_1000a467(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000a439;
}



// Function: FUN_1000a476 at 1000a476

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000a476(int param_1,undefined4 *param_2)

{
  undefined4 *this;
  undefined4 *puVar1;
  int iVar2;
  LPCOLESTR lpsz;
  HRESULT HVar3;
  undefined4 local_50 [4];
  int local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 *local_30;
  uint local_2c;
  CLSID local_28 [2];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x40;
  local_8 = 0x1000a482;
  FUN_10006cf9(local_50);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_10007f0f(local_50,(-(uint)(param_2 != (undefined4 *)0x0) & 0x7fffbffd) + 0x80004003);
  this = (undefined4 *)(param_1 + 0x5c);
  FUN_10009b49(this);
  *param_2 = 0;
  local_30 = (undefined4 *)0x0;
  iVar2 = FUN_10009755(&local_30);
  FUN_10007f0f(local_50,iVar2);
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_1000caea((void *)(param_1 + 0x2c),&local_40);
  for (local_2c = 0; puVar1 = local_30, local_2c < (uint)((local_3c - local_40) / 0x1c);
      local_2c = local_2c + 1) {
    lpsz = (LPCOLESTR)(local_2c * 0x1c + local_40);
    if (7 < *(uint *)(lpsz + 10)) {
      lpsz = *(LPCOLESTR *)lpsz;
    }
    HVar3 = CLSIDFromString(lpsz,local_28);
    FUN_10007f0f(local_50,HVar3);
    FUN_10009cfb(this,&local_28[0].Data1);
  }
  iVar2 = FUN_1000912e(local_30,(int *)(param_1 + -0x20),this);
  FUN_10007f0f(local_50,iVar2);
  iVar2 = (**(code **)*puVar1)(puVar1,&DAT_10011c6c,param_2);
  FUN_10007f0f(local_50,iVar2);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10009d8a((_Container_base0 *)&local_40);
  local_8 = 0xffffffff;
  FUN_1000dc96();
  return;
}



// Function: Catch@1000a584 at 1000a584

undefined4 Catch_1000a584(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000a575;
}



// Function: FUN_1000a58e at 1000a58e

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000a58e(int param_1,undefined4 *param_2)

{
  undefined4 *this;
  undefined4 *puVar1;
  int iVar2;
  LPCOLESTR lpsz;
  HRESULT HVar3;
  undefined4 local_50 [4];
  int local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 *local_30;
  uint local_2c;
  CLSID local_28 [2];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x40;
  local_8 = 0x1000a59a;
  FUN_10006cf9(local_50);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_10007f0f(local_50,(-(uint)(param_2 != (undefined4 *)0x0) & 0x7fffbffd) + 0x80004003);
  this = (undefined4 *)(param_1 + 0x6c);
  FUN_10009b49(this);
  *param_2 = 0;
  local_30 = (undefined4 *)0x0;
  iVar2 = FUN_10009755(&local_30);
  FUN_10007f0f(local_50,iVar2);
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_1000cb2d((void *)(param_1 + 0x2c),&local_40);
  for (local_2c = 0; puVar1 = local_30, local_2c < (uint)((local_3c - local_40) / 0x1c);
      local_2c = local_2c + 1) {
    lpsz = (LPCOLESTR)(local_2c * 0x1c + local_40);
    if (7 < *(uint *)(lpsz + 10)) {
      lpsz = *(LPCOLESTR *)lpsz;
    }
    HVar3 = CLSIDFromString(lpsz,local_28);
    FUN_10007f0f(local_50,HVar3);
    FUN_10009cfb(this,&local_28[0].Data1);
  }
  iVar2 = FUN_1000912e(local_30,(int *)(param_1 + -0x20),this);
  FUN_10007f0f(local_50,iVar2);
  iVar2 = (**(code **)*puVar1)(puVar1,&DAT_10011c6c,param_2);
  FUN_10007f0f(local_50,iVar2);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10009d8a((_Container_base0 *)&local_40);
  local_8 = 0xffffffff;
  FUN_1000dc96();
  return;
}



// Function: Catch@1000a69c at 1000a69c

undefined4 Catch_1000a69c(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000a68d;
}



// Function: FUN_1000a6a6 at 1000a6a6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_1000a6a6(void *this,ushort *param_1,undefined4 param_2)

{
  int iVar1;
  ushort *puVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x1000a6b2;
  iVar1 = *(int *)((int)this + 8);
  piVar3 = (int *)FUN_10009919((void *)((int)this + 4),local_14,param_1);
  if (*piVar3 == iVar1) {
    uVar4 = 0x80070057;
  }
  else {
    piVar3 = (int *)FUN_1000816a((void *)((int)this + 4),param_1);
    puVar2 = (ushort *)*piVar3;
    param_1 = puVar2;
    if (puVar2 != (ushort *)0x0) {
      (**(code **)(*(int *)puVar2 + 4))(puVar2);
    }
    local_8 = 2;
    uVar4 = FUN_100089e9(&param_1,param_2,0);
    local_8 = 0xffffffff;
    if (puVar2 != (ushort *)0x0) {
      (**(code **)(*(int *)puVar2 + 8))(puVar2);
    }
  }
  return uVar4;
}



// Function: FUN_1000a718 at 1000a718

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_1000a718(void *this,ushort *param_1,undefined4 param_2)

{
  int iVar1;
  ushort *puVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x1000a724;
  iVar1 = *(int *)((int)this + 8);
  piVar3 = (int *)FUN_10009919((void *)((int)this + 4),local_14,param_1);
  if (*piVar3 == iVar1) {
    uVar4 = 0x80070057;
  }
  else {
    piVar3 = (int *)FUN_1000816a((void *)((int)this + 4),param_1);
    puVar2 = (ushort *)*piVar3;
    param_1 = puVar2;
    if (puVar2 != (ushort *)0x0) {
      (**(code **)(*(int *)puVar2 + 4))(puVar2);
    }
    local_8 = 2;
    uVar4 = FUN_10008a21(&param_1,param_2,&stack0x0000000c,0);
    local_8 = 0xffffffff;
    if (puVar2 != (ushort *)0x0) {
      (**(code **)(*(int *)puVar2 + 8))(puVar2);
    }
  }
  return uVar4;
}



// Function: FUN_1000a78e at 1000a78e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000a78e(int param_1)

{
  int aiStack_30 [5];
  undefined1 *local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000a79a;
  local_1c = (undefined1 *)aiStack_30;
  aiStack_30[0] = param_1;
  local_18 = param_1;
  FUN_10008ed9(param_1);
  return local_18;
}



// Function: FUN_1000a7ba at 1000a7ba

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000a7ba(int param_1)

{
  int iVar1;
  undefined4 local_44 [4];
  ushort local_34 [22];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x1000a7c6;
  FUN_10006cf9(local_44);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_10001bb0(local_34,L"{FB0FF818-0FF9-43AB-BFAE-22CB56E10851}");
  local_8._0_1_ = 2;
  iVar1 = FUN_1000a6a6((void *)(param_1 + 4),local_34,1);
  FUN_10007f0f(local_44,iVar1);
  local_8 = CONCAT31(local_8._1_3_,1);
  FID_conflict__Tidy(local_34,'\x01',0);
  local_8 = 0xffffffff;
  FUN_1000dc96();
  return;
}



// Function: Catch@1000a823 at 1000a823

undefined4 Catch_1000a823(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000a814;
}



// Function: FUN_1000a82d at 1000a82d

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000a82d(int param_1,int param_2)

{
  int iVar1;
  undefined4 local_54 [4];
  undefined4 local_44;
  ushort local_34 [22];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x44;
  local_8 = 0x1000a839;
  FUN_10006cf9(local_54);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_10001bb0(local_34,L"{FB0FF818-0FF9-43AB-BFAE-22CB56E10851}");
  local_8._0_1_ = 2;
  local_44 = (uint)local_44._2_2_ << 0x10;
  FUN_10008ba3(&local_44,param_2);
  local_8._0_1_ = 3;
  iVar1 = FUN_1000a718((void *)(param_1 + 4),local_34,2);
  FUN_10007f0f(local_54,iVar1);
  local_8._0_1_ = 2;
  Ordinal_9(&local_44);
  local_8 = CONCAT31(local_8._1_3_,1);
  FID_conflict__Tidy(local_34,'\x01',0);
  local_8 = 0xffffffff;
  FUN_1000dc96();
  return;
}



// Function: Catch@1000a8c7 at 1000a8c7

undefined4 Catch_1000a8c7(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000a8b8;
}



// Function: FUN_1000a8d1 at 1000a8d1

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000a8d1(int param_1)

{
  int iVar1;
  undefined4 local_44 [4];
  ushort local_34 [22];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x1000a8dd;
  FUN_10006cf9(local_44);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_10001bb0(local_34,L"{FB0FF818-0FF9-43AB-BFAE-22CB56E10851}");
  local_8._0_1_ = 2;
  iVar1 = FUN_1000a6a6((void *)(param_1 + 4),local_34,3);
  FUN_10007f0f(local_44,iVar1);
  local_8 = CONCAT31(local_8._1_3_,1);
  FID_conflict__Tidy(local_34,'\x01',0);
  local_8 = 0xffffffff;
  FUN_1000dc96();
  return;
}



// Function: Catch@1000a93a at 1000a93a

undefined4 Catch_1000a93a(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000a92b;
}



// Function: FUN_1000a944 at 1000a944

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000a944(int param_1,int param_2)

{
  uint local_48 [4];
  undefined4 local_38;
  ushort local_34 [22];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_38 = 0x80004005;
  local_8 = 0;
  local_48[0] = local_48[0] & 0xffff0000;
  FUN_10008ba3(local_48,param_2);
  local_8._0_1_ = 1;
  FUN_10001bb0(local_34,L"{FB0FF818-0FF9-43AB-BFAE-22CB56E10851}");
  local_8._0_1_ = 2;
  local_38 = FUN_1000a718((void *)(param_1 + 4),local_34,4);
  local_8._0_1_ = 1;
  FID_conflict__Tidy(local_34,'\x01',0);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_9(local_48);
  local_8 = 0xffffffff;
  FUN_1000dc96();
  return;
}



// Function: Catch@1000a9cf at 1000a9cf

undefined4 Catch_1000a9cf(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000a9c4;
}



// Function: FUN_1000a9d9 at 1000a9d9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000a9d9(int param_1)

{
  FUN_1000a78e(param_1 + 4);
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined1 *)(param_1 + 0x14) = 0;
  return param_1;
}



// Function: FUN_1000aa12 at 1000aa12

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000aa12(int param_1)

{
  *(undefined4 *)(param_1 + 0x28) = 0;
  FUN_10002b87((void *)(param_1 + 0x2c));
  FUN_1000a9d9(param_1 + 4);
  *(undefined4 *)(param_1 + 0x48) = 0;
  FUN_1000c6a7((void *)(param_1 + 0x4c),(undefined4 *)(param_1 + 200),(undefined4 *)(param_1 + 0xd8)
              );
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 7;
  *(undefined4 *)(param_1 + 0xac) = 0;
  *(undefined2 *)(param_1 + 0x9c) = 0;
  FUN_10009d5e(param_1 + 0xb8);
  *(undefined **)(param_1 + 0xd0) = &DAT_100094a2;
  *(undefined4 *)(param_1 + 200) = CAddInFactory::AddInLoadCallback::vftable;
  *(int *)(param_1 + 0xcc) = param_1;
  *(undefined4 *)(param_1 + 0xd4) = 0;
  *(undefined4 *)(param_1 + 0xd8) = CAddInFactory::AddInLoadCallback::vftable;
  *(int *)(param_1 + 0xdc) = param_1;
  *(undefined **)(param_1 + 0xe0) = &DAT_10009544;
  *(undefined4 *)(param_1 + 0xe4) = 0;
  return param_1;
}



// Function: _wmemset at 1000aafa

/* Library Function - Single Match
    _wmemset
   
   Library: Visual Studio 2010 Release */

wchar_t * __cdecl _wmemset(wchar_t *_S,wchar_t _C,size_t _N)

{
  uint uVar1;
  wchar_t *pwVar2;
  
  if (_N != 0) {
    pwVar2 = _S;
    for (uVar1 = _N >> 1; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(uint *)pwVar2 = CONCAT22(_C,_C);
      pwVar2 = pwVar2 + 2;
    }
    for (uVar1 = (uint)((_N & 1) != 0); uVar1 != 0; uVar1 = uVar1 - 1) {
      *pwVar2 = _C;
      pwVar2 = pwVar2 + 1;
    }
  }
  return _S;
}



// Function: FUN_1000ab24 at 1000ab24

void __fastcall FUN_1000ab24(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if (*(char *)(iVar3 + 0x31) == '\0') {
    piVar1 = *(int **)(iVar3 + 8);
    if (*(char *)((int)*(int **)(iVar3 + 8) + 0x31) == '\0') {
      do {
        piVar2 = piVar1;
        piVar1 = (int *)*piVar2;
      } while (*(char *)((int)piVar1 + 0x31) == '\0');
      *param_1 = (int)piVar2;
      return;
    }
    for (iVar3 = *(int *)(iVar3 + 4);
        (*(char *)(iVar3 + 0x31) == '\0' && (*param_1 == *(int *)(iVar3 + 8)));
        iVar3 = *(int *)(iVar3 + 4)) {
      *param_1 = iVar3;
    }
    *param_1 = iVar3;
  }
  return;
}



// Function: FUN_1000ab5f at 1000ab5f

void __fastcall FUN_1000ab5f(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  
  puVar1 = (undefined4 *)*param_1;
  if (*(char *)((int)puVar1 + 0x31) != '\0') {
    *param_1 = puVar1[2];
    return;
  }
  piVar2 = (int *)*puVar1;
  if (*(char *)((int)*puVar1 + 0x31) == '\0') {
    do {
      piVar3 = piVar2;
      piVar2 = (int *)piVar3[2];
    } while (*(char *)(piVar3[2] + 0x31) == '\0');
  }
  else {
    for (piVar3 = (int *)puVar1[1]; (*(char *)((int)piVar3 + 0x31) == '\0' && (*param_1 == *piVar3))
        ; piVar3 = (int *)piVar3[1]) {
      *param_1 = (int)piVar3;
    }
    if (*(char *)(*param_1 + 0x31) != '\0') {
      return;
    }
  }
  *param_1 = (int)piVar3;
  return;
}



// Function: FID_conflict:_Chassign at 1000aba5

/* Library Function - Multiple Matches With Different Base Names
    public: void __thiscall std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::_Chassign(unsigned int,unsigned int,unsigned
   short)
    public: void __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::_Chassign(unsigned int,unsigned int,wchar_t)
   
   Library: Visual Studio 2010 Release */

void __thiscall FID_conflict__Chassign(void *this,int param_1,size_t param_2,wchar_t param_3)

{
  if (param_2 == 1) {
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      this = *this;
    }
    *(wchar_t *)((int)this + param_1 * 2) = param_3;
  }
  else {
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      this = *this;
    }
    _wmemset((wchar_t *)((int)this + param_1 * 2),param_3,param_2);
  }
  return;
}



// Function: FUN_1000abe4 at 1000abe4

bool FUN_1000abe4(undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  
  pvVar1 = (void *)*param_1;
  if ((pvVar1 == (void *)0xcdcdcdcd) || ((void *)*param_2 == (void *)0xcdcdcdcd)) {
    bVar2 = false;
  }
  else {
    iVar3 = FUN_10001c98((void *)*param_2);
    iVar4 = FUN_10001c98(pvVar1);
    bVar2 = iVar4 < iVar3;
  }
  return bVar2;
}



// Function: FUN_1000ac1f at 1000ac1f

int * __thiscall FUN_1000ac1f(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  piVar2 = (int *)param_1[1];
  if (*(int **)((int)this + 4) != piVar2) {
    FUN_10008ab5((int *)this);
    *(int *)this = iVar1;
    *(int **)((int)this + 4) = piVar2;
    *piVar2 = *piVar2 + 1;
  }
  return (int *)this;
}



// Function: FUN_1000ac49 at 1000ac49

uint __thiscall FUN_1000ac49(void *this,uint param_1)

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



// Function: FUN_1000ac78 at 1000ac78

uint __thiscall FUN_1000ac78(void *this,uint param_1)

{
  uint uVar1;
  
                    /* WARNING: Load size is inaccurate */
  uVar1 = *(int *)((int)this + 8) - *this >> 3;
  if (0x1fffffff - (uVar1 >> 1) < uVar1) {
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



// Function: FUN_1000aca4 at 1000aca4

void __thiscall FUN_1000aca4(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x31) == '\0') {
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



// Function: FUN_1000aceb at 1000aceb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_1000aceb(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000acf7;
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  if ((param_1 < (char *)0x4ec4ec5) &&
     (pvVar1 = operator_new((int)param_1 * 0x34), pvVar1 != (void *)0x0)) {
    return pvVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_1c,&param_1);
  local_1c[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10013448);
}



// Function: FUN_1000ad4a at 1000ad4a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_1000ad4a(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000ad56;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10013448);
}



// Function: FUN_1000ada9 at 1000ada9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_1000ada9(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000adb5;
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  if ((param_1 < (char *)0x20000000) &&
     (pvVar1 = operator_new((int)param_1 << 3), pvVar1 != (void *)0x0)) {
    return pvVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_1c,&param_1);
  local_1c[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10013448);
}



// Function: FUN_1000ae0a at 1000ae0a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __cdecl FUN_1000ae0a(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  
  piVar1 = (int *)&LAB_1000ff82;
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    piVar1 = (int *)param_2[1];
    param_1[1] = piVar1;
    *piVar1 = *piVar1 + 1;
  }
  return piVar1;
}



// Function: FUN_1000ae40 at 1000ae40

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_1000ae40(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  
  piVar1 = (int *)&LAB_1000ff82;
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    piVar1 = (int *)param_2[1];
    param_1[1] = piVar1;
    *piVar1 = *piVar1 + 1;
  }
  return piVar1;
}



// Function: FUN_1000ae75 at 1000ae75

void __cdecl FUN_1000ae75(int param_1,int param_2,int param_3,int *param_4)

{
  bool bVar1;
  int iVar2;
  
  while (iVar2 = (param_2 + -1) / 2, param_3 < param_2) {
    bVar1 = FUN_1000abe4((undefined4 *)(param_1 + iVar2 * 8),param_4);
    if (!bVar1) break;
    FUN_1000ac1f((void *)(param_1 + param_2 * 8),(int *)(param_1 + iVar2 * 8));
    param_2 = iVar2;
  }
  FUN_1000ac1f((void *)(param_1 + param_2 * 8),param_4);
  return;
}



// Function: FUN_1000aecd at 1000aecd

void * __cdecl FUN_1000aecd(int *param_1,int *param_2,void *param_3)

{
  if (param_1 != param_2) {
    do {
      param_3 = (void *)((int)param_3 + -8);
      param_2 = param_2 + -2;
      FUN_1000ac1f(param_3,param_2);
    } while (param_2 != param_1);
  }
  return param_3;
}



// Function: FUN_1000aef4 at 1000aef4

void __thiscall FUN_1000aef4(void *this,int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x31) == '\0') {
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



// Function: FUN_1000af39 at 1000af39

void __cdecl FUN_1000af39(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_3;
  iVar1 = param_2;
  if (param_1 != param_2) {
    do {
      *piVar2 = *piVar2 + 1;
      FUN_1000ab24(&param_1);
    } while (param_1 != iVar1);
  }
  return;
}



// Function: FUN_1000af5c at 1000af5c

void __fastcall FUN_1000af5c(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_1000aceb((char *)0x1);
  *puVar1 = *(undefined4 *)(param_1 + 4);
  puVar1[1] = *(undefined4 *)(param_1 + 4);
  puVar1[2] = *(undefined4 *)(param_1 + 4);
  *(undefined2 *)(puVar1 + 0xc) = 0;
  return;
}



// Function: FUN_1000af83 at 1000af83

void __cdecl FUN_1000af83(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  FUN_1000ae40(param_2,param_3);
  return;
}



// Function: FUN_1000af96 at 1000af96

void __cdecl FUN_1000af96(int param_1,int param_2,int param_3,int *param_4)

{
  undefined4 *puVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_2;
  while( true ) {
    iVar4 = iVar3 * 2 + 2;
    if (param_3 <= iVar4) break;
    puVar1 = (undefined4 *)(param_1 + iVar4 * 8);
    bVar2 = FUN_1000abe4(puVar1,puVar1 + -2);
    if (bVar2) {
      iVar4 = iVar3 * 2 + 1;
    }
    FUN_1000ac1f((void *)(param_1 + iVar3 * 8),(int *)(param_1 + iVar4 * 8));
    iVar3 = iVar4;
  }
  if (iVar4 == param_3) {
    FUN_1000ac1f((void *)(param_1 + iVar3 * 8),(int *)(param_1 + -8 + param_3 * 8));
    iVar3 = param_3 + -1;
  }
  FUN_1000ae75(param_1,iVar3,param_2,param_4);
  return;
}



// Function: FUN_1000b007 at 1000b007

void __cdecl FUN_1000b007(int *param_1,int param_2,void *param_3,int *param_4)

{
  FUN_1000ac1f(param_3,param_1);
  FUN_1000af96((int)param_1,0,param_2 - (int)param_1 >> 3,param_4);
  return;
}



// Function: FUN_1000b034 at 1000b034

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000b034(void *param_1)

{
  FUN_10008ab5((int *)((int)param_1 + 0x1c));
  FID_conflict__Tidy(param_1,'\x01',0);
  return;
}



// Function: FUN_1000b066 at 1000b066

int __fastcall FUN_1000b066(int param_1)

{
  void *pvVar1;
  
  *(undefined4 *)(param_1 + 8) = 0;
  pvVar1 = FUN_1000aceb((char *)0x1);
  *(void **)(param_1 + 4) = pvVar1;
  *(void **)pvVar1 = pvVar1;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x30) = 1;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x31) = 1;
  return param_1;
}



// Function: FUN_1000b09d at 1000b09d

void __cdecl FUN_1000b09d(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  FUN_1000ae0a(param_2,param_3);
  return;
}



// Function: FUN_1000b0af at 1000b0af

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __cdecl FUN_1000b0af(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int local_18;
  int *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  iVar2 = param_2 - param_1 >> 3;
  iVar1 = iVar2 - (param_2 - param_1 >> 0x1f) >> 1;
  while (0 < iVar1) {
    iVar1 = iVar1 + -1;
    local_18 = *(int *)(param_1 + iVar1 * 8);
    local_14 = *(int **)(param_1 + 4 + iVar1 * 8);
    *local_14 = *local_14 + 1;
    local_8 = 0;
    FUN_1000af96(param_1,iVar1,iVar2,&local_18);
    local_8 = 0xffffffff;
    FUN_10008ab5(&local_18);
  }
  return;
}



// Function: FUN_1000b10d at 1000b10d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __cdecl FUN_1000b10d(int *param_1,int *param_2)

{
  int *piVar1;
  bool bVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  if ((param_1 != param_2) && (piVar3 = param_1 + 2, piVar3 != param_2)) {
    local_14 = param_1;
    do {
      local_20 = *piVar3;
      piVar1 = (int *)local_14[3];
      piVar4 = local_14 + 4;
      *piVar1 = *piVar1 + 1;
      local_8 = 0;
      local_1c = piVar1;
      local_18 = piVar3;
      bVar2 = FUN_1000abe4(&local_20,param_1);
      piVar5 = local_14;
      if (bVar2) {
        FUN_1000aecd(param_1,piVar3,piVar4);
        piVar5 = param_1;
      }
      else {
        while (piVar4 = piVar5, bVar2 = FUN_1000abe4(&local_20,piVar4), piVar5 = local_18, bVar2) {
          FUN_1000ac1f(local_18,piVar4);
          piVar5 = piVar4 + -2;
          local_18 = piVar4;
        }
      }
      if ((int *)piVar5[1] != piVar1) {
        FUN_10008ab5(piVar5);
        *piVar5 = local_20;
        piVar5[1] = (int)piVar1;
        *piVar1 = *piVar1 + 1;
      }
      local_8 = 0xffffffff;
      FUN_10008ab5(&local_20);
      local_14 = local_14 + 2;
      piVar3 = piVar3 + 2;
    } while (piVar3 != param_2);
  }
  return;
}



// Function: FUN_1000b1da at 1000b1da

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __cdecl FUN_1000b1da(int *param_1,int param_2)

{
  int *piVar1;
  int local_18;
  int *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  piVar1 = (int *)(param_2 + -8);
  local_18 = *piVar1;
  local_14 = *(int **)(param_2 + -4);
  *local_14 = *local_14 + 1;
  local_8 = 0;
  FUN_1000b007(param_1,(int)piVar1,piVar1,&local_18);
  local_8 = 0xffffffff;
  FUN_10008ab5(&local_18);
  return;
}



// Function: FUN_1000b225 at 1000b225

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000b225(void *param_1)

{
  FUN_1000b034(param_1);
  return;
}



// Function: FUN_1000b243 at 1000b243

void __thiscall FUN_1000b243(void *this,int *param_1,ushort *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *local_8;
  
  puVar4 = *(undefined4 **)((int)this + 4);
  puVar1 = (undefined4 *)puVar4[1];
  local_8 = puVar4;
  while (puVar3 = puVar1, *(char *)((int)puVar3 + 0x31) == '\0') {
    iVar2 = FUN_10001584(puVar3 + 3,param_2);
    if (iVar2 < 0) {
      puVar1 = (undefined4 *)puVar3[2];
    }
    else {
      if (*(char *)((int)puVar4 + 0x31) != '\0') {
        iVar2 = FUN_10001584(param_2,(ushort *)(puVar3 + 3));
        if (iVar2 < 0) {
          puVar4 = puVar3;
        }
      }
      puVar1 = (undefined4 *)*puVar3;
      local_8 = puVar3;
    }
  }
  if (*(char *)((int)puVar4 + 0x31) == '\0') {
    puVar1 = (undefined4 *)*puVar4;
  }
  else {
    puVar1 = *(undefined4 **)(*(int *)((int)this + 4) + 4);
  }
  while (puVar3 = puVar1, *(char *)((int)puVar3 + 0x31) == '\0') {
    iVar2 = FUN_10001584(param_2,(ushort *)(puVar3 + 3));
    if (iVar2 < 0) {
      puVar1 = (undefined4 *)*puVar3;
      puVar4 = puVar3;
    }
    else {
      puVar1 = (undefined4 *)puVar3[2];
    }
  }
  param_1[1] = (int)puVar4;
  *param_1 = (int)local_8;
  return;
}



// Function: FUN_1000b2d3 at 1000b2d3

undefined4 * __thiscall FUN_1000b2d3(void *this,ushort *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)(*(undefined4 **)((int)this + 4))[1];
  puVar4 = *(undefined4 **)((int)this + 4);
  while (puVar3 = puVar1, *(char *)((int)puVar3 + 0x31) == '\0') {
    iVar2 = FUN_10001584(puVar3 + 3,param_1);
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



// Function: FUN_1000b308 at 1000b308

undefined4 * __thiscall FUN_1000b308(void *this,uint param_1,uint param_2,wchar_t param_3)

{
  bool bVar1;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint uVar2;
  void *pvVar3;
  void *pvVar4;
  
  uVar2 = *(uint *)((int)this + 0x10);
  if (uVar2 < param_1) {
    std::_Xout_of_range("invalid string position");
    uVar2 = extraout_EAX;
  }
  if (-uVar2 - 1 <= param_2) {
    std::_Xlength_error("string too long");
    uVar2 = extraout_EAX_00;
  }
  if (param_2 != 0) {
    uVar2 = uVar2 + param_2;
    bVar1 = FUN_100017e1(this,uVar2,'\0');
    if (bVar1) {
      pvVar3 = this;
      pvVar4 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
        pvVar3 = *this;
        pvVar4 = *this;
      }
      memmove((void *)((int)pvVar3 + (param_1 + param_2) * 2),(void *)((int)pvVar4 + param_1 * 2),
              (*(int *)((int)this + 0x10) - param_1) * 2);
      FID_conflict__Chassign(this,param_1,param_2,param_3);
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



// Function: FUN_1000b3b5 at 1000b3b5

void __cdecl FUN_1000b3b5(int param_1,int param_2)

{
  if (8 < (int)(param_2 - param_1 & 0xfffffff8U)) {
    FUN_1000b0af(param_1,param_2);
  }
  return;
}



// Function: FUN_1000b3dd at 1000b3dd

void __cdecl FUN_1000b3dd(undefined4 param_1,int *param_2)

{
  FUN_10008ab5(param_2);
  return;
}



// Function: FUN_1000b3e9 at 1000b3e9

void __cdecl FUN_1000b3e9(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  bool bVar2;
  
  bVar2 = FUN_1000abe4(param_2,param_1);
  if (bVar2) {
    uVar1 = *param_2;
    *param_2 = *param_1;
    *param_1 = uVar1;
    uVar1 = param_2[1];
    param_2[1] = param_1[1];
    param_1[1] = uVar1;
  }
  bVar2 = FUN_1000abe4(param_3,param_2);
  if (bVar2) {
    uVar1 = *param_3;
    *param_3 = *param_2;
    *param_2 = uVar1;
    uVar1 = param_3[1];
    param_3[1] = param_2[1];
    param_2[1] = uVar1;
  }
  bVar2 = FUN_1000abe4(param_2,param_1);
  if (bVar2) {
    uVar1 = *param_2;
    *param_2 = *param_1;
    *param_1 = uVar1;
    uVar1 = param_2[1];
    param_2[1] = param_1[1];
    param_1[1] = uVar1;
  }
  return;
}



// Function: FUN_1000b463 at 1000b463

void __cdecl FUN_1000b463(int *param_1,int *param_2,undefined4 param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 2) {
    FUN_1000b3dd(param_3,param_1);
  }
  return;
}



// Function: FUN_1000b482 at 1000b482

void __thiscall FUN_1000b482(void *this,int *param_1,int param_2,wchar_t param_3)

{
  void *pvVar1;
  uint uVar2;
  
  pvVar1 = this;
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    pvVar1 = *this;
  }
  if (param_2 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = param_2 - (int)pvVar1 >> 1;
  }
  FUN_1000b308(this,uVar2,1,param_3);
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    this = *this;
  }
  *param_1 = (int)((int)this + uVar2 * 2);
  return;
}



// Function: FUN_1000b4c5 at 1000b4c5

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __cdecl
FUN_1000b4c5(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  for (; param_1 != param_2; param_1 = param_1 + 2) {
    FUN_1000af83(param_4,param_3,param_1);
    param_3 = param_3 + 2;
  }
  return param_3;
}



// Function: Catch@1000b509 at 1000b509

void Catch_1000b509(void)

{
  int unaff_EBP;
  int *piVar1;
  
  for (piVar1 = *(int **)(unaff_EBP + -0x14); piVar1 != *(int **)(unaff_EBP + 0x10);
      piVar1 = piVar1 + 2) {
    FUN_1000b3dd(*(undefined4 *)(unaff_EBP + 0x14),piVar1);
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000b52b at 1000b52b

void __cdecl FUN_1000b52b(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = (int)param_3 - (int)param_1 >> 3;
  if (iVar1 < 0x29) {
    FUN_1000b3e9(param_1,param_2,param_3);
  }
  else {
    iVar1 = iVar1 + 1;
    iVar1 = (int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3;
    FUN_1000b3e9(param_1,param_1 + iVar1 * 2,param_1 + iVar1 * 4);
    FUN_1000b3e9(param_2 + iVar1 * -2,param_2,param_2 + iVar1 * 2);
    FUN_1000b3e9(param_3 + iVar1 * -4,param_3 + iVar1 * -2,param_3);
    FUN_1000b3e9(param_1 + iVar1 * 2,param_2,param_3 + iVar1 * -2);
  }
  return;
}



// Function: FUN_1000b5be at 1000b5be

void __cdecl FUN_1000b5be(int *param_1,int param_2)

{
  uint uVar1;
  
  for (uVar1 = param_2 - (int)param_1; 8 < (int)(uVar1 & 0xfffffff8); uVar1 = uVar1 - 8) {
    FUN_1000b1da(param_1,param_2);
    param_2 = param_2 + -8;
  }
  return;
}



// Function: FUN_1000b5fb at 1000b5fb

void __thiscall FUN_1000b5fb(void *this,undefined4 *param_1,ushort *param_2)

{
  int iVar1;
  ushort **ppuVar2;
  ushort *local_8;
  
  local_8 = (ushort *)this;
  local_8 = (ushort *)FUN_1000b2d3(this,param_2);
  if (local_8 != *(ushort **)((int)this + 4)) {
    iVar1 = FUN_10001584(param_2,local_8 + 6);
    if (-1 < iVar1) {
      ppuVar2 = &local_8;
      goto LAB_1000b630;
    }
  }
  ppuVar2 = &param_2;
LAB_1000b630:
  *param_1 = *ppuVar2;
  return;
}



// Function: FUN_1000b63c at 1000b63c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000b63c(void *this,undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  
  basic_string<>(this,param_1);
  *(undefined4 *)((int)this + 0x1c) = *param_2;
  piVar1 = (int *)param_2[1];
  *(int **)((int)this + 0x20) = piVar1;
  *piVar1 = *piVar1 + 1;
  return this;
}



// Function: FUN_1000b677 at 1000b677

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 * FUN_1000b677(void *param_1,undefined4 *param_2)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)&LAB_1000ff82;
  if (param_1 != (void *)0x0) {
    puVar1 = basic_string<>(param_1,param_2);
  }
  return puVar1;
}



// Function: _Uninitialized_move<> at 1000b6a5

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
  FUN_1000b4c5(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000b6c4 at 1000b6c4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 * __cdecl FUN_1000b6c4(void *param_1,undefined4 *param_2)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)&LAB_1000ff82;
  if (param_1 != (void *)0x0) {
    puVar1 = basic_string<>(param_1,param_2);
  }
  return puVar1;
}



// Function: FUN_1000b6f3 at 1000b6f3

undefined4 * __thiscall FUN_1000b6f3(void *this,wchar_t *param_1)

{
  undefined4 *puVar1;
  
                    /* WARNING: Load size is inaccurate */
  puVar1 = (undefined4 *)FUN_1000b482(*this,(int *)&param_1,*(int *)((int)this + 4),*param_1);
  *(undefined4 *)((int)this + 4) = *puVar1;
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 2;
  return (undefined4 *)this;
}



// Function: FUN_1000b71f at 1000b71f

void __cdecl FUN_1000b71f(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  bool bVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *local_c;
  undefined4 *local_8;
  
  puVar2 = param_2 + (((int)param_3 - (int)param_2 >> 3) - ((int)param_3 - (int)param_2 >> 0x1f) >>
                     1) * 2;
  FUN_1000b52b(param_2,puVar2,param_3 + -2);
  puVar6 = puVar2 + 2;
  while (puVar5 = puVar2, param_2 < puVar5) {
    puVar2 = puVar5 + -2;
    bVar3 = FUN_1000abe4(puVar2,puVar5);
    if ((bVar3) || (bVar3 = FUN_1000abe4(puVar5,puVar2), bVar3)) break;
  }
  while ((puVar2 = puVar6, local_8 = puVar5, puVar7 = puVar5, puVar6 < param_3 &&
         ((bVar3 = FUN_1000abe4(puVar6,puVar5), !bVar3 &&
          (bVar3 = FUN_1000abe4(puVar5,puVar6), !bVar3))))) {
    puVar6 = puVar6 + 2;
  }
  do {
    while (puVar4 = puVar5, param_3 <= puVar2) {
joined_r0x1000b7f3:
      while (param_2 < puVar4) {
        local_c = puVar5 + -2;
        bVar3 = FUN_1000abe4(local_c,puVar7);
        if (!bVar3) {
          bVar3 = FUN_1000abe4(puVar7,local_c);
          puVar4 = local_8;
          if (bVar3) break;
          puVar4 = puVar7 + -2;
          uVar1 = *puVar4;
          *puVar4 = *local_c;
          *local_c = uVar1;
          uVar1 = puVar7[-1];
          puVar7[-1] = puVar5[-1];
          puVar5[-1] = uVar1;
          puVar7 = puVar4;
        }
        local_8 = local_8 + -2;
        puVar5 = local_c;
        puVar4 = local_8;
      }
      if (puVar4 == param_2) {
        if (puVar2 == param_3) {
          *param_1 = puVar7;
          param_1[1] = puVar6;
          return;
        }
        if (puVar6 != puVar2) {
          uVar1 = *puVar7;
          *puVar7 = *puVar6;
          *puVar6 = uVar1;
          uVar1 = puVar7[1];
          puVar7[1] = puVar6[1];
          puVar6[1] = uVar1;
        }
        uVar1 = *puVar7;
        *puVar7 = *puVar2;
        *puVar2 = uVar1;
        uVar1 = puVar7[1];
        puVar7[1] = puVar2[1];
        puVar2[1] = uVar1;
        puVar5 = puVar4;
        puVar6 = puVar6 + 2;
        puVar2 = puVar2 + 2;
        puVar7 = puVar7 + 2;
      }
      else {
        puVar5 = puVar4 + -2;
        local_8 = puVar5;
        if (puVar2 == param_3) {
          puVar8 = puVar7 + -2;
          if (puVar5 != puVar8) {
            uVar1 = *puVar5;
            *puVar5 = *puVar8;
            *puVar8 = uVar1;
            uVar1 = puVar4[-1];
            puVar4[-1] = puVar7[-1];
            puVar7[-1] = uVar1;
          }
          uVar1 = *puVar8;
          puVar4 = puVar6 + -2;
          *puVar8 = *puVar4;
          *puVar4 = uVar1;
          uVar1 = puVar7[-1];
          puVar7[-1] = puVar6[-1];
          puVar6[-1] = uVar1;
          puVar6 = puVar4;
          puVar7 = puVar8;
        }
        else {
          uVar1 = *puVar2;
          *puVar2 = *puVar5;
          *puVar5 = uVar1;
          uVar1 = puVar2[1];
          puVar2[1] = puVar4[-1];
          puVar4[-1] = uVar1;
          puVar2 = puVar2 + 2;
        }
      }
    }
    bVar3 = FUN_1000abe4(puVar7,puVar2);
    puVar5 = local_8;
    if (!bVar3) {
      bVar3 = FUN_1000abe4(puVar2,puVar7);
      puVar4 = local_8;
      if (bVar3) goto joined_r0x1000b7f3;
      uVar1 = *puVar6;
      *puVar6 = *puVar2;
      *puVar2 = uVar1;
      uVar1 = puVar6[1];
      puVar6[1] = puVar2[1];
      puVar6 = puVar6 + 2;
      puVar2[1] = uVar1;
    }
    puVar2 = puVar2 + 2;
  } while( true );
}



// Function: FUN_1000b925 at 1000b925

void __cdecl FUN_1000b925(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  FUN_1000b677(param_2,param_3);
  return;
}



// Function: FUN_1000b938 at 1000b938

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __cdecl FUN_1000b938(undefined4 param_1,void *param_2)

{
  FUN_1000b034(param_2);
  return;
}



// Function: FUN_1000b956 at 1000b956

void __thiscall FUN_1000b956(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  _Uninitialized_move<>(param_1,param_2,param_3,(int)this + 0xc);
  return;
}



// Function: FUN_1000b972 at 1000b972

void __thiscall
FUN_1000b972(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  uint extraout_EAX;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  uVar3 = *(uint *)((int)this + 8);
  if (0x71c71c5 < uVar3) {
    this = (void *)((int)this + 0xd);
    FUN_1000b938(this,param_4 + 3);
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
    if (*(char *)(iVar4 + 0x30) != '\0') {
      *(undefined1 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x30) = 1;
      *param_1 = param_4;
      return;
    }
    piVar1 = (int *)piVar5[1];
    piVar2 = (int *)piVar1[1];
    if (piVar1 == (int *)*piVar2) {
      iVar4 = piVar2[2];
      if (*(char *)(iVar4 + 0x30) == '\0') {
LAB_1000ba41:
        *(undefined1 *)(piVar1 + 0xc) = 1;
        *(undefined1 *)(iVar4 + 0x30) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x30) = 0;
        piVar5 = *(int **)(piVar5[1] + 4);
      }
      else {
        if (piVar5 == (int *)piVar1[2]) {
          FUN_1000aef4(this,(int)piVar1);
          piVar5 = piVar1;
        }
        *(undefined1 *)(piVar5[1] + 0x30) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x30) = 0;
        FUN_1000aca4(this,*(int **)(piVar5[1] + 4));
      }
    }
    else {
      iVar4 = *piVar2;
      if (*(char *)(iVar4 + 0x30) == '\0') goto LAB_1000ba41;
      if (piVar5 == (int *)*piVar1) {
        FUN_1000aca4(this,piVar1);
        piVar5 = piVar1;
      }
      *(undefined1 *)(piVar5[1] + 0x30) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x30) = 0;
      FUN_1000aef4(this,*(int *)(piVar5[1] + 4));
    }
    iVar4 = piVar5[1];
  } while( true );
}



// Function: FUN_1000baaa at 1000baaa

void __cdecl
FUN_1000baaa(undefined4 *param_1,undefined2 *param_2,undefined2 *param_3,undefined4 param_4,
            undefined4 param_5,undefined *param_6)

{
  uint uVar1;
  undefined2 *puVar2;
  
  for (puVar2 = param_2; puVar2 != param_3; puVar2 = puVar2 + 1) {
    uVar1 = (*(code *)param_6)(*puVar2);
    param_2 = (undefined2 *)(uVar1 & 0xffff);
    FUN_1000b6f3(&param_4,(wchar_t *)&param_2);
  }
  *param_1 = param_4;
  param_1[1] = param_5;
  return;
}



// Function: FUN_1000bae6 at 1000bae6

void __thiscall FUN_1000bae6(void *this,int *param_1,int *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  void *this_00;
  int *local_c;
  int *local_8;
  
  iVar1 = (int)param_2 - (int)param_1 >> 3;
  local_c = (int *)this;
  local_8 = (int *)this;
  if (0x20 < iVar1) {
    do {
      if (param_3 < 1) break;
      FUN_1000b71f(&local_c,param_1,param_2);
      param_3 = param_3 / 2 + (param_3 / 2) / 2;
      this_00 = (void *)((int)local_c - (int)param_1 & 0xfffffff8);
      if ((int)this_00 < (int)((int)param_2 - (int)local_8 & 0xfffffff8U)) {
        FUN_1000bae6(this_00,param_1,local_c,param_3,param_4);
        param_1 = local_8;
      }
      else {
        FUN_1000bae6(this_00,local_8,param_2,param_3,param_4);
        param_2 = local_c;
      }
      iVar1 = (int)param_2 - (int)param_1 >> 3;
    } while (0x20 < iVar1);
    if (0x20 < iVar1) {
      FUN_1000b3b5((int)param_1,(int)param_2);
      FUN_1000b5be(param_1,(int)param_2);
      return;
    }
  }
  if (1 < iVar1) {
    FUN_1000b10d(param_1,param_2);
  }
  return;
}



// Function: FUN_1000bba4 at 1000bba4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000bba4(void *this,undefined4 *param_1)

{
  FUN_1000b63c(this,param_1,param_1 + 7);
  return this;
}



// Function: FUN_1000bbd2 at 1000bbd2

void __fastcall FUN_1000bbd2(_Container_base0 *param_1)

{
  if (*(int *)param_1 != 0) {
    std::_Container_base0::_Orphan_all(param_1);
    FUN_1000b463(*(int **)param_1,*(int **)(param_1 + 4),param_1 + 0xc);
    operator_delete(*(void **)param_1);
  }
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: FUN_1000bc0d at 1000bc0d

void __thiscall FUN_1000bc0d(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  piVar2 = param_2;
  if (*(char *)((int)param_2 + 0x31) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  FUN_1000ab24((int *)&param_2);
  piVar5 = (int *)*piVar2;
  if (*(char *)((int)piVar5 + 0x31) == '\0') {
    piVar7 = piVar5;
    if ((*(char *)(piVar2[2] + 0x31) != '\0') || (piVar7 = (int *)param_2[2], param_2 == piVar2))
    goto LAB_1000bc57;
    piVar5[1] = (int)param_2;
    *param_2 = *piVar2;
    piVar5 = param_2;
    if (param_2 != (int *)piVar2[2]) {
      piVar5 = (int *)param_2[1];
      if (*(char *)((int)piVar7 + 0x31) == '\0') {
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
    iVar1 = param_2[0xc];
    *(char *)(param_2 + 0xc) = (char)piVar2[0xc];
    *(char *)(piVar2 + 0xc) = (char)iVar1;
  }
  else {
    piVar7 = (int *)piVar2[2];
LAB_1000bc57:
    piVar5 = (int *)piVar2[1];
    if (*(char *)((int)piVar7 + 0x31) == '\0') {
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
      if (*(char *)((int)piVar7 + 0x31) == '\0') {
        piVar3 = (int *)*piVar7;
        piVar6 = piVar7;
        while (piVar4 = piVar3, *(char *)((int)piVar4 + 0x31) == '\0') {
          piVar6 = piVar4;
          piVar3 = (int *)*piVar4;
        }
      }
      **(int **)((int)this + 4) = (int)piVar6;
    }
    if (*(int **)(*(int *)((int)this + 4) + 8) == piVar2) {
      piVar6 = piVar5;
      if (*(char *)((int)piVar7 + 0x31) == '\0') {
        piVar3 = (int *)piVar7[2];
        piVar6 = piVar7;
        while (piVar4 = piVar3, *(char *)((int)piVar4 + 0x31) == '\0') {
          piVar6 = piVar4;
          piVar3 = (int *)piVar4[2];
        }
      }
      *(int **)(*(int *)((int)this + 4) + 8) = piVar6;
    }
  }
  if ((char)piVar2[0xc] != '\x01') {
LAB_1000be34:
    FUN_1000b938((int)this + 0xd,piVar2 + 3);
    operator_delete(piVar2);
    if (*(int *)((int)this + 8) != 0) {
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
    }
    *param_1 = param_2;
    return;
  }
LAB_1000bde8:
  piVar6 = piVar5;
  if ((piVar7 == *(int **)(*(int *)((int)this + 4) + 4)) || ((char)piVar7[0xc] != '\x01'))
  goto LAB_1000be30;
  piVar5 = (int *)*piVar6;
  if (piVar7 == piVar5) {
    piVar5 = (int *)piVar6[2];
    if ((char)piVar5[0xc] == '\0') {
      *(undefined1 *)(piVar5 + 0xc) = 1;
      *(undefined1 *)(piVar6 + 0xc) = 0;
      FUN_1000aef4(this,(int)piVar6);
      piVar5 = (int *)piVar6[2];
    }
    if (*(char *)((int)piVar5 + 0x31) == '\0') {
      if ((*(char *)(*piVar5 + 0x30) != '\x01') || (*(char *)(piVar5[2] + 0x30) != '\x01')) {
        if (*(char *)(piVar5[2] + 0x30) == '\x01') {
          *(undefined1 *)(*piVar5 + 0x30) = 1;
          *(undefined1 *)(piVar5 + 0xc) = 0;
          FUN_1000aca4(this,piVar5);
          piVar5 = (int *)piVar6[2];
        }
        *(char *)(piVar5 + 0xc) = (char)piVar6[0xc];
        *(undefined1 *)(piVar6 + 0xc) = 1;
        *(undefined1 *)(piVar5[2] + 0x30) = 1;
        FUN_1000aef4(this,(int)piVar6);
        goto LAB_1000be30;
      }
LAB_1000bddf:
      *(undefined1 *)(piVar5 + 0xc) = 0;
    }
  }
  else {
    if ((char)piVar5[0xc] == '\0') {
      *(undefined1 *)(piVar5 + 0xc) = 1;
      *(undefined1 *)(piVar6 + 0xc) = 0;
      FUN_1000aca4(this,piVar6);
      piVar5 = (int *)*piVar6;
    }
    if (*(char *)((int)piVar5 + 0x31) == '\0') {
      if ((*(char *)(piVar5[2] + 0x30) == '\x01') && (*(char *)(*piVar5 + 0x30) == '\x01'))
      goto LAB_1000bddf;
      if (*(char *)(*piVar5 + 0x30) == '\x01') {
        *(undefined1 *)(piVar5[2] + 0x30) = 1;
        *(undefined1 *)(piVar5 + 0xc) = 0;
        FUN_1000aef4(this,(int)piVar5);
        piVar5 = (int *)*piVar6;
      }
      *(char *)(piVar5 + 0xc) = (char)piVar6[0xc];
      *(undefined1 *)(piVar6 + 0xc) = 1;
      *(undefined1 *)(*piVar5 + 0x30) = 1;
      FUN_1000aca4(this,piVar6);
LAB_1000be30:
      *(undefined1 *)(piVar7 + 0xc) = 1;
      goto LAB_1000be34;
    }
  }
  piVar5 = (int *)piVar6[1];
  piVar7 = piVar6;
  goto LAB_1000bde8;
}



// Function: FUN_1000be6a at 1000be6a

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_1000be6a(void *this,char *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  if ((char *)0x1fffffff < param_1) {
    std::_Xlength_error("vector<T> too long");
  }
                    /* WARNING: Load size is inaccurate */
  if ((char *)(*(int *)((int)this + 8) - *this >> 3) < param_1) {
    puVar3 = (undefined4 *)FUN_1000ada9(param_1);
                    /* WARNING: Load size is inaccurate */
    FUN_1000b956(this,*this,*(undefined4 **)((int)this + 4),puVar3);
    piVar1 = *(int **)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
    piVar2 = *this;
    if (piVar2 != (int *)0x0) {
      FUN_1000b463(piVar2,piVar1,(int)this + 0xc);
                    /* WARNING: Load size is inaccurate */
      operator_delete(*this);
    }
    std::_Container_base0::_Orphan_all((_Container_base0 *)this);
    *(undefined4 **)((int)this + 8) = puVar3 + (int)param_1 * 2;
    *(undefined4 **)((int)this + 4) = puVar3 + ((int)piVar1 - (int)piVar2 >> 3) * 2;
    *(undefined4 **)this = puVar3;
  }
  return;
}



// Function: Catch@1000bf08 at 1000bf08

void Catch_1000bf08(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000bf1b at 1000bf1b

void __thiscall FUN_1000bf1b(void *this,int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x31);
  while (cVar1 == '\0') {
    FUN_1000bf1b(this,(int *)param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_1000b938((int)this + 0xd,param_1 + 3);
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x31);
  }
  return;
}



// Function: FUN_1000bf5f at 1000bf5f

undefined4 * __cdecl
FUN_1000bf5f(undefined4 *param_1,undefined2 *param_2,undefined2 *param_3,undefined4 param_4,
            undefined4 param_5,undefined *param_6)

{
  if (param_2 != param_3) {
    FUN_1000baaa(param_1,param_2,param_3,param_4,param_5,param_6);
    return param_1;
  }
  *param_1 = param_4;
  param_1[1] = param_5;
  return param_1;
}



// Function: FUN_1000bf97 at 1000bf97

void __thiscall FUN_1000bf97(void *this,int *param_1,int *param_2,undefined4 param_3)

{
  FUN_1000bae6(this,param_1,param_2,(int)param_2 - (int)param_1 >> 3,param_3);
  return;
}



// Function: FUN_1000bfb7 at 1000bfb7

void __cdecl FUN_1000bfb7(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  FUN_1000b6c4(param_2,param_3);
  return;
}



// Function: FUN_1000bfc9 at 1000bfc9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 * FUN_1000bfc9(void *param_1,undefined4 *param_2)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)&LAB_1000ff82;
  if (param_1 != (void *)0x0) {
    puVar1 = basic_string<>(param_1,param_2);
  }
  return puVar1;
}



// Function: FUN_1000bff7 at 1000bff7

void __thiscall FUN_1000bff7(void *this,int *param_1,int *param_2,undefined4 *param_3)

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
  while (*(char *)((int)puVar3 + 0x31) == '\0') {
    if ((char)param_3 == '\0') {
      iVar2 = FUN_10001584(this_00,(ushort *)(puVar3 + 3));
      local_8 = iVar2 < 0;
    }
    else {
      iVar2 = FUN_10001584(puVar3 + 3,this_00);
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
      goto LAB_1000c06d;
    }
    FUN_1000ab5f((int *)&param_3);
  }
  puVar3 = param_3;
  iVar2 = FUN_10001584(param_3 + 3,this_00);
  if (-1 < iVar2) {
    FUN_1000b938((int)this + 0xd,this_00);
    operator_delete(param_2);
    *param_1 = (int)puVar3;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_1000c06d:
  piVar1 = (int *)FUN_1000b972(this,&param_3,local_8,local_c,param_2);
  *param_1 = *piVar1;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}



// Function: FUN_1000c0cd at 1000c0cd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_1000c0cd(void *param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = &LAB_1000ff82;
  if (param_1 != (void *)0x0) {
    puVar1 = (undefined1 *)FUN_1000bba4(param_1,param_2);
  }
  return puVar1;
}



// Function: FUN_1000c100 at 1000c100

void __thiscall FUN_1000c100(void *this,int param_1)

{
  uint uVar1;
  uint extraout_EAX;
  char *pcVar2;
  int extraout_ECX;
  int iVar3;
  
                    /* WARNING: Load size is inaccurate */
  iVar3 = *this;
  uVar1 = *(int *)((int)this + 4) - iVar3 >> 3;
  if (0x1fffffffU - param_1 < uVar1) {
    std::_Xlength_error("vector<T> too long");
    uVar1 = extraout_EAX;
    iVar3 = extraout_ECX;
  }
  if ((uint)(*(int *)((int)this + 8) - iVar3 >> 3) < uVar1 + param_1) {
    pcVar2 = (char *)FUN_1000ac78(this,uVar1 + param_1);
    FUN_1000be6a(this,pcVar2);
  }
  return;
}



// Function: FUN_1000c14b at 1000c14b

void __fastcall FUN_1000c14b(void *param_1)

{
  FUN_1000bf1b(param_1,*(int **)(*(int *)((int)param_1 + 4) + 4));
  *(int *)(*(int *)((int)param_1 + 4) + 4) = *(int *)((int)param_1 + 4);
  *(undefined4 *)*(undefined4 *)((int)param_1 + 4) = *(undefined4 *)((int)param_1 + 4);
  *(int *)(*(int *)((int)param_1 + 4) + 8) = *(int *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 8) = 0;
  return;
}



// Function: FUN_1000c172 at 1000c172

void __cdecl FUN_1000c172(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  FUN_1000bfc9(param_2,param_3);
  return;
}



// Function: FUN_1000c185 at 1000c185

/* WARNING: Variable defined which should be unmapped: param_2 */

undefined4 * __thiscall FUN_1000c185(void *param_1,undefined4 *param_2,int *param_3,int *param_4)

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
      iVar3 = FUN_10001584(this,(ushort *)(param_3 + 3));
      if (-1 < iVar3) goto LAB_1000c295;
      cVar5 = '\x01';
      goto LAB_1000c1a1;
    }
    if (param_3 == piVar1) {
      iVar3 = FUN_10001584((void *)(piVar1[2] + 0xc),this);
      if (-1 < iVar3) goto LAB_1000c295;
      param_3 = *(int **)(*(int *)((int)param_1 + 4) + 8);
      cVar5 = '\0';
      goto LAB_1000c1a1;
    }
    iVar3 = FUN_10001584(this,(ushort *)(param_3 + 3));
    if (iVar3 < 0) {
      param_4 = param_3;
      FUN_1000ab5f((int *)&param_4);
      piVar1 = param_4;
      iVar3 = FUN_10001584(param_4 + 3,this);
      if (-1 < iVar3) goto LAB_1000c244;
      cVar5 = *(char *)(piVar1[2] + 0x31);
      piVar6 = param_3;
    }
    else {
LAB_1000c244:
      iVar3 = FUN_10001584(param_3 + 3,(ushort *)(piVar2 + 3));
      if (-1 < iVar3) {
LAB_1000c295:
        puVar4 = (undefined4 *)FUN_1000bff7(param_1,(int *)&local_c,piVar2,(undefined4 *)0x0);
        *param_2 = *puVar4;
        return param_2;
      }
      param_4 = param_3;
      FUN_1000ab24((int *)&param_4);
      if ((param_4 != *(int **)((int)param_1 + 4)) &&
         (iVar3 = FUN_10001584(piVar2 + 3,(ushort *)(param_4 + 3)), -1 < iVar3)) goto LAB_1000c295;
      cVar5 = *(char *)(param_3[2] + 0x31);
      piVar1 = param_3;
      piVar6 = param_4;
    }
    param_3 = piVar1;
    if (cVar5 != '\0') {
      cVar5 = '\0';
      goto LAB_1000c1a1;
    }
  }
  cVar5 = '\x01';
  param_3 = piVar6;
LAB_1000c1a1:
  FUN_1000b972(param_1,param_2,cVar5,param_3,piVar2);
  return param_2;
}



// Function: FUN_1000c2b1 at 1000c2b1

void __cdecl FUN_1000c2b1(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  FUN_1000c0cd(param_2,param_3);
  return;
}



// Function: FUN_1000c2c4 at 1000c2c4

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl
FUN_1000c2c4(undefined4 *param_1,undefined4 *param_2,void *param_3,undefined4 param_4)

{
  for (; param_1 != param_2; param_1 = param_1 + 7) {
    FUN_1000c172(param_4,param_3,param_1);
    param_3 = (void *)((int)param_3 + 0x1c);
  }
  return param_3;
}



// Function: Catch@1000c308 at 1000c308

void Catch_1000c308(void)

{
  int unaff_EBP;
  void *pvVar1;
  
  for (pvVar1 = *(void **)(unaff_EBP + -0x14); pvVar1 != *(void **)(unaff_EBP + 0x10);
      pvVar1 = (void *)((int)pvVar1 + 0x1c)) {
    FUN_10009aa6(*(undefined4 *)(unaff_EBP + 0x14),pvVar1);
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000c32a at 1000c32a

void __thiscall FUN_1000c32a(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < puVar1) && (puVar2 = *this, puVar2 <= param_1)) {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_1000c100(this,1);
    }
                    /* WARNING: Load size is inaccurate */
    FUN_1000af83((int)this + 0xc,*(undefined4 **)((int)this + 4),
                 (undefined4 *)(*this + ((int)param_1 - (int)puVar2 >> 3) * 8));
  }
  else {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_1000c100(this,1);
    }
    FUN_1000b09d((int)this + 0xc,*(undefined4 **)((int)this + 4),param_1);
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 8;
  return;
}



// Function: FUN_1000c390 at 1000c390

void __thiscall FUN_1000c390(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  void *local_8;
  
  local_8 = this;
  if ((param_2 == (int *)**(int **)((int)this + 4)) && (param_3 == *(int **)((int)this + 4))) {
    FUN_1000c14b(this);
    param_2 = (int *)**(undefined4 **)((int)this + 4);
  }
  else if (param_2 != param_3) {
    do {
      piVar1 = param_2;
      FUN_1000ab24((int *)&param_2);
      FUN_1000bc0d(this,&local_8,piVar1);
    } while (param_2 != param_3);
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_1000c3e3 at 1000c3e3

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_1000c3e3(void *this,undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_1000af5c((int)this);
  FUN_1000c2b1((int)this + 0xd,(void *)(iVar1 + 0xc),param_1);
  return iVar1;
}



// Function: Catch@1000c420 at 1000c420

void Catch_1000c420(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: _Uninitialized_move<> at 1000c433

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
  FUN_1000c2c4(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000c452 at 1000c452

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000c452(void *param_1)

{
  undefined4 local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  local_14 = param_1;
  FUN_1000c390(param_1,&local_18,(int *)**(int **)((int)param_1 + 4),*(int **)((int)param_1 + 4));
  local_8 = 0xffffffff;
  operator_delete(*(void **)((int)param_1 + 4));
  return;
}



// Function: FUN_1000c48c at 1000c48c

int __thiscall FUN_1000c48c(void *this,ushort *param_1)

{
  int *local_c;
  int *local_8;
  
  local_c = (int *)this;
  local_8 = (int *)this;
  FUN_1000b243(this,(int *)&local_c,param_1);
  param_1 = (ushort *)0x0;
  FUN_1000af39((int)local_c,(int)local_8,(int *)&param_1);
  FUN_1000c390(this,&local_8,local_c,local_8);
  return (int)param_1;
}



// Function: FUN_1000c4d2 at 1000c4d2

void __thiscall FUN_1000c4d2(void *this,undefined4 *param_1,undefined4 *param_2,void *param_3)

{
  _Uninitialized_move<>(param_1,param_2,param_3,(int)this + 0xc);
  return;
}



// Function: FUN_1000c4ee at 1000c4ee

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000c4ee(void *param_1)

{
  FUN_1000c452(param_1);
  return;
}



// Function: FUN_1000c50c at 1000c50c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000c50c(undefined4 *param_1)

{
  *param_1 = CAddInManager::vftable;
  FUN_1000c452(param_1 + 1);
  return;
}



// Function: FUN_1000c53a at 1000c53a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000c53a(int param_1)

{
  int aiStack_30 [5];
  undefined1 *local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000c546;
  local_1c = (undefined1 *)aiStack_30;
  aiStack_30[0] = param_1;
  local_18 = param_1;
  FUN_1000b066(param_1);
  return local_18;
}



// Function: FUN_1000c566 at 1000c566

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000c566(void *this,ushort *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int local_44 [2];
  undefined4 local_3c;
  undefined4 local_38 [12];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x1000c572;
  piVar1 = FUN_1000b2d3(this,param_1);
  if (piVar1 != *(int **)((int)this + 4)) {
    iVar2 = FUN_10001584(param_1,(ushort *)(piVar1 + 3));
    if (-1 < iVar2) goto LAB_1000c5e2;
  }
  puVar3 = FUN_10008a60(local_44,0);
  local_8 = 0;
  FUN_1000b63c(local_38,(undefined4 *)param_1,puVar3);
  local_8._0_1_ = 2;
  piVar4 = (int *)FUN_1000c3e3(this,local_38);
  FUN_1000c185(this,&local_3c,piVar1,piVar4);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1000b034(local_38);
  local_8 = 0xffffffff;
  FUN_10008ab5(local_44);
LAB_1000c5e2:
  FUN_1000dc87();
  return;
}



// Function: FUN_1000c5ed at 1000c5ed

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_1000c5ed(void *this,char *param_1)

{
  int iVar1;
  void *pvVar2;
  void *pvVar3;
  
  if ((char *)0x9249249 < param_1) {
    std::_Xlength_error("vector<T> too long");
  }
                    /* WARNING: Load size is inaccurate */
  if ((char *)((*(int *)((int)this + 8) - *this) / 0x1c) < param_1) {
    pvVar3 = FUN_1000ad4a(param_1);
                    /* WARNING: Load size is inaccurate */
    FUN_1000c4d2(this,*this,*(undefined4 **)((int)this + 4),pvVar3);
    iVar1 = *(int *)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
    pvVar2 = *this;
    if (pvVar2 != (void *)0x0) {
      FUN_10009bf9(pvVar2,*(void **)((int)this + 4),(int)this + 0xc);
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



// Function: Catch@1000c694 at 1000c694

void Catch_1000c694(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 8));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000c6a7 at 1000c6a7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000c6a7(void *this,undefined4 param_1,undefined4 param_2)

{
  *(undefined ***)this = CAddInManager::vftable;
  FUN_1000c53a((int)this + 4);
  *(undefined4 *)((int)this + 0x18) = param_1;
  *(undefined4 *)((int)this + 0x1c) = param_2;
  return (undefined4 *)this;
}



// Function: FUN_1000c6e4 at 1000c6e4

undefined4 * __thiscall FUN_1000c6e4(void *this,byte param_1)

{
  FUN_1000c50c((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000c703 at 1000c703

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000c703(void *this,LPCWSTR param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  void *this_00;
  undefined4 *puVar5;
  undefined4 local_6c [2];
  void *local_64;
  int local_60 [2];
  undefined4 local_58;
  undefined1 local_54 [12];
  void *local_48;
  undefined4 *local_44;
  undefined4 *local_40;
  undefined4 local_3c;
  LPCWSTR local_34;
  uint local_30 [4];
  undefined4 local_20;
  undefined4 local_1c;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x5c;
  local_8 = 0x1000c70f;
  local_34 = param_1;
  FUN_1000ceda(&local_58);
  local_8 = 0;
  if (7 < *(uint *)(param_1 + 10)) {
    param_1 = *(LPCWSTR *)param_1;
  }
  iVar1 = Open(local_54,(HKEY)0x80000002,param_1,0x2001f);
  if (iVar1 == 0) {
    local_44 = (undefined4 *)0x0;
    local_40 = (undefined4 *)0x0;
    local_3c = 0;
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar1 = FUN_1000d84f(&local_58,&local_44,'\0');
    if ((iVar1 == 0) && (local_44 != local_40)) {
      local_48 = (void *)((int)this + 4);
      puVar5 = local_44;
      do {
        local_1c = 7;
        local_20 = 0;
        local_30[0] = local_30[0] & 0xffff0000;
        local_8._0_1_ = 2;
        puVar3 = puVar5;
        if (7 < (uint)puVar5[5]) {
          puVar3 = (undefined4 *)*puVar5;
        }
        puVar2 = puVar5;
        if (7 < (uint)puVar5[5]) {
          puVar2 = (undefined4 *)*puVar5;
        }
        FUN_1000bf5f(local_6c,(undefined2 *)puVar2,(undefined2 *)((int)puVar3 + puVar5[4] * 2),
                     local_30,local_30,towupper_exref);
        local_64 = operator_new(0x38);
        local_8._0_1_ = 3;
        if (local_64 == (void *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          puVar3 = FUN_10002809(local_64,local_30,local_34);
        }
        local_8._0_1_ = 2;
        piVar4 = FUN_10008a60(local_60,puVar3);
        local_8._0_1_ = 4;
        this_00 = (void *)FUN_1000c566(local_48,(ushort *)local_30);
        FUN_1000ac1f(this_00,piVar4);
        local_8._0_1_ = 2;
        FUN_10008ab5(local_60);
        local_8 = CONCAT31(local_8._1_3_,1);
        FID_conflict__Tidy(local_30,'\x01',0);
        puVar5 = puVar5 + 7;
      } while (puVar5 != local_40);
    }
    local_8 = local_8 & 0xffffff00;
    FUN_10009d8a((_Container_base0 *)&local_44);
    local_8 = 0xffffffff;
    FUN_1000cf09(&local_58);
  }
  else {
    local_8 = 0xffffffff;
    FUN_1000cf09(&local_58);
  }
  FUN_1000dc87();
  return;
}



// Function: FUN_1000c880 at 1000c880

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000c880(void *this,LPCOLESTR param_1,char param_2)

{
  int *piVar1;
  LPCOLESTR lpsz;
  undefined4 *puVar2;
  int *local_28;
  CLSID local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_28 = (int *)0x0;
  local_8 = 1;
  lpsz = param_1;
  if (7 < *(uint *)(param_1 + 10)) {
    lpsz = *(LPCOLESTR *)param_1;
  }
  CLSIDFromString(lpsz,&local_24);
  CoCreateInstance(&local_24,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10011200,&local_28);
  piVar1 = local_28;
  puVar2 = (undefined4 *)FUN_1000c566((void *)((int)this + 4),(ushort *)param_1);
  FUN_100012a7((void *)*puVar2,piVar1);
  puVar2 = (undefined4 *)FUN_1000c566((void *)((int)this + 4),(ushort *)param_1);
  FUN_100014a8((void *)*puVar2,*(undefined4 *)((int)this + 0x14));
  puVar2 = (undefined4 *)FUN_1000c566((void *)((int)this + 4),(ushort *)param_1);
  FUN_1000287d((void *)*puVar2,param_2);
  (**(code **)**(undefined4 **)((int)this + 0x18))(param_1);
  local_8 = 0xffffffff;
  if (local_28 != (int *)0x0) {
    (**(code **)(*local_28 + 8))(local_28);
  }
  FUN_1000dc87();
  return;
}



// Function: FUN_1000c92e at 1000c92e

void __thiscall FUN_1000c92e(void *this,ushort *param_1,char param_2)

{
  undefined4 *puVar1;
  
  (**(code **)**(undefined4 **)((int)this + 0x1c))(param_1);
  puVar1 = (undefined4 *)FUN_1000c566((void *)((int)this + 4),param_1);
  FUN_1000290c((void *)*puVar1,param_2);
  return;
}



// Function: FUN_1000c958 at 1000c958

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000c958(void *this,undefined4 *param_1,ushort *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x1000c964;
  local_14 = 0;
  iVar1 = *(int *)((int)this + 8);
  piVar2 = (int *)FUN_1000b5fb((void *)((int)this + 4),&local_18,param_2);
  if (*piVar2 == iVar1) {
    FUN_10008a60(param_1,0);
  }
  else {
    puVar3 = (undefined4 *)FUN_1000c566((void *)((int)this + 4),param_2);
    *param_1 = *puVar3;
    piVar2 = (int *)puVar3[1];
    param_1[1] = piVar2;
    *piVar2 = *piVar2 + 1;
  }
  return param_1;
}



// Function: FUN_1000c9c8 at 1000c9c8

void __thiscall FUN_1000c9c8(void *this,int param_1)

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
    pcVar2 = (char *)FUN_1000ac49(this,uVar1);
    FUN_1000c5ed(this,pcVar2);
  }
  return;
}



// Function: FUN_1000ca1d at 1000ca1d

void __thiscall FUN_1000ca1d(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < puVar1) && (puVar2 = *this, puVar2 <= param_1)) {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_1000c9c8(this,1);
    }
                    /* WARNING: Load size is inaccurate */
    param_1 = (undefined4 *)((((int)param_1 - (int)puVar2) / 0x1c) * 0x1c + *this);
  }
  else if (puVar1 == *(undefined4 **)((int)this + 8)) {
    FUN_1000c9c8(this,1);
  }
  FUN_1000c172((int)this + 0xc,*(void **)((int)this + 4),param_1);
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x1c;
  return;
}



// Function: FUN_1000ca7d at 1000ca7d

void __thiscall FUN_1000ca7d(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < puVar1) && (puVar2 = *this, puVar2 <= param_1)) {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_1000c9c8(this,1);
    }
                    /* WARNING: Load size is inaccurate */
    FUN_1000b925((int)this + 0xc,*(void **)((int)this + 4),
                 (undefined4 *)((((int)param_1 - (int)puVar2) / 0x1c) * 0x1c + *this));
  }
  else {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_1000c9c8(this,1);
    }
    FUN_1000bfb7((int)this + 0xc,*(void **)((int)this + 4),param_1);
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x1c;
  return;
}



// Function: FUN_1000caea at 1000caea

void __thiscall FUN_1000caea(void *this,void *param_1)

{
  int iVar1;
  int iVar2;
  int local_8;
  
  local_8 = **(int **)((int)this + 8);
  if ((int *)local_8 != *(int **)((int)this + 8)) {
    do {
      iVar1 = local_8;
      iVar2 = FUN_10001000(*(int *)(local_8 + 0x28));
      if (iVar2 == 3) {
        FUN_1000ca7d(param_1,(undefined4 *)(iVar1 + 0xc));
      }
      FUN_1000ab24(&local_8);
    } while (local_8 != *(int *)((int)this + 8));
  }
  return;
}



// Function: FUN_1000cb2d at 1000cb2d

void __thiscall FUN_1000cb2d(void *this,void *param_1)

{
  int local_8;
  
  local_8 = **(int **)((int)this + 8);
  if ((int *)local_8 != *(int **)((int)this + 8)) {
    do {
      FUN_1000ca7d(param_1,(undefined4 *)(local_8 + 0xc));
      FUN_1000ab24(&local_8);
    } while (local_8 != *(int *)((int)this + 8));
  }
  return;
}



// Function: FUN_1000cb61 at 1000cb61

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000cb61(void *this,void *param_1)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  void *extraout_ECX;
  void *this_00;
  uint uVar4;
  int local_48;
  int *local_44;
  int *local_40;
  undefined4 local_3c;
  void *local_34;
  undefined1 local_30 [40];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_34 = param_1;
  local_44 = (int *)0x0;
  local_40 = (int *)0x0;
  local_3c = 0;
  local_8 = 0;
  local_48 = **(int **)((int)this + 8);
  this_00 = this;
  if ((int *)local_48 != *(int **)((int)this + 8)) {
    do {
      iVar1 = local_48;
      basic_string<>(local_30,(undefined4 *)(local_48 + 0xc));
      local_8 = CONCAT31(local_8._1_3_,1);
      cVar2 = FUN_10001e7f(*(void **)(iVar1 + 0x28));
      if (cVar2 != '\0') {
        FUN_1000c32a(&local_44,(undefined4 *)(iVar1 + 0x28));
      }
      local_8 = local_8 & 0xffffff00;
      FID_conflict__Tidy(local_30,'\x01',0);
      FUN_1000ab24(&local_48);
      this_00 = extraout_ECX;
    } while (local_48 != *(int *)((int)this + 8));
  }
  FUN_1000bf97(this_00,local_44,local_40,local_34);
  uVar4 = 0;
  if ((int)local_40 - (int)local_44 >> 3 != 0) {
    do {
      puVar3 = (undefined4 *)FUN_10001b3d((void *)local_44[uVar4 * 2],local_30);
      local_8._0_1_ = 2;
      FUN_1000ca1d(local_34,puVar3);
      local_8 = (uint)local_8._1_3_ << 8;
      FID_conflict__Tidy(local_30,'\x01',0);
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)((int)local_40 - (int)local_44 >> 3));
  }
  local_8 = 0xffffffff;
  FUN_1000bbd2((_Container_base0 *)&local_44);
  FUN_1000dc87();
  return;
}



// Function: FUN_1000cc45 at 1000cc45

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000cc45(void *this,undefined4 param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int local_48;
  int local_44;
  undefined4 local_40;
  uint local_38;
  int local_34;
  undefined1 local_30 [40];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_8 = 0;
  FUN_1000cb61(this,&local_48);
  local_34 = 0;
  local_38 = 0;
  if ((local_44 - local_48) / 0x1c != 0) {
    iVar4 = 0;
    do {
      if (local_34 < 0) break;
      puVar2 = (undefined4 *)FUN_1000c566((void *)((int)this + 4),(ushort *)(local_48 + iVar4));
      cVar1 = FUN_10001e7f((void *)*puVar2);
      if (cVar1 != '\0') {
        basic_string<>(local_30,(undefined4 *)(local_48 + iVar4));
        local_8 = CONCAT31(local_8._1_3_,1);
        puVar2 = (undefined4 *)FUN_1000c566((void *)((int)this + 4),(ushort *)(local_48 + iVar4));
        iVar3 = FUN_100014a8((void *)*puVar2,param_1);
        if (iVar3 < 0) {
          puVar2 = (undefined4 *)FUN_1000c566((void *)((int)this + 4),(ushort *)(local_48 + iVar4));
          cVar1 = FUN_10001eed((void *)*puVar2);
          local_34 = iVar3;
          if (cVar1 == '\0') {
            local_34 = 1;
          }
        }
        else {
          (**(code **)**(undefined4 **)((int)this + 0x18))(local_48 + iVar4);
        }
        local_8 = local_8 & 0xffffff00;
        FID_conflict__Tidy(local_30,'\x01',0);
      }
      local_38 = local_38 + 1;
      iVar4 = iVar4 + 0x1c;
    } while (local_38 < (uint)((local_44 - local_48) / 0x1c));
  }
  *(undefined4 *)((int)this + 0x14) = param_1;
  local_8 = 0xffffffff;
  FUN_10009d8a((_Container_base0 *)&local_48);
  FUN_1000dc87();
  return;
}



// Function: FUN_1000cd5c at 1000cd5c

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void __fastcall FUN_1000cd5c(void *param_1)

{
  void *pvVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int local_30;
  int local_2c;
  undefined4 local_28;
  void *local_20;
  int local_1c;
  uint local_18;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_1c = 0x80004005;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_8 = 1;
  local_20 = param_1;
  FUN_1000cb61(param_1,&local_30);
  local_1c = 0;
  local_18 = 0;
  while( true ) {
    pvVar1 = local_20;
    if ((uint)((local_2c - local_30) / 0x1c) <= local_18) break;
    iVar5 = local_18 * 0x1c;
    puVar3 = (undefined4 *)FUN_1000c566((void *)((int)local_20 + 4),(ushort *)(iVar5 + local_30));
    iVar4 = FUN_1000287d((void *)*puVar3,'\x01');
    if (iVar4 < 0) {
      puVar3 = (undefined4 *)FUN_1000c566((void *)((int)pvVar1 + 4),(ushort *)(local_30 + iVar5));
      cVar2 = FUN_10001eed((void *)*puVar3);
      local_1c = (-(uint)(cVar2 != '\0') & 0x80004004) + 1;
    }
    local_18 = local_18 + 1;
  }
  local_8 = local_8 & 0xffffff00;
  FUN_10009d8a((_Container_base0 *)&local_30);
  local_8 = 0xffffffff;
  FUN_1000ce11();
  return;
}



// Function: Catch@1000ce04 at 1000ce04

undefined * Catch_1000ce04(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000ce0e;
}



// Function: FUN_1000ce11 at 1000ce11

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000ce11(void)

{
  return;
}



// Function: FUN_1000ce19 at 1000ce19

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __fastcall FUN_1000ce19(void *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int local_2c;
  int local_28;
  undefined4 local_24;
  void *local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_8 = 0;
  local_1c = param_1;
  FUN_1000cb61(param_1,&local_2c);
  iVar1 = (local_28 - local_2c) / 0x1c;
  do {
    iVar1 = iVar1 + -1;
    local_18 = iVar1;
    if (iVar1 < 0) {
      local_8 = 0xffffffff;
      FUN_10009d8a((_Container_base0 *)&local_2c);
      return 0;
    }
    iVar6 = iVar1 * 0x1c;
    piVar2 = (int *)FUN_1000c566((void *)((int)param_1 + 4),(ushort *)(local_2c + iVar6));
    iVar3 = FUN_10001000(*piVar2);
  } while (iVar3 != 3);
  (**(code **)**(undefined4 **)((int)param_1 + 0x1c))(local_2c + iVar6);
  local_8 = CONCAT31(local_8._1_3_,1);
  puVar4 = (undefined4 *)FUN_1000c566((void *)((int)param_1 + 4),(ushort *)(iVar6 + local_2c));
  FUN_1000290c((void *)*puVar4,'\0');
  local_8 = 0;
  uVar5 = FUN_1000ceb2();
  return uVar5;
}



// Function: Catch@1000cea2 at 1000cea2

undefined * Catch_1000cea2(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_1000ceac;
}



// Function: FUN_1000ceb2 at 1000ceb2

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000ceb2(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int unaff_EBX;
  int unaff_EBP;
  int iVar5;
  int unaff_EDI;
  
  FUN_1000c48c((void *)(unaff_EDI + 4),(ushort *)(unaff_EBX * 0x1c + *(int *)(unaff_EBP + -0x28)));
  do {
    unaff_EBX = unaff_EBX + -1;
    *(int *)(unaff_EBP + -0x14) = unaff_EBX;
    if (unaff_EBX < 0) {
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_10009d8a((_Container_base0 *)(unaff_EBP + -0x28));
      return 0;
    }
    iVar5 = unaff_EBX * 0x1c;
    piVar1 = (int *)FUN_1000c566((void *)(unaff_EDI + 4),
                                 (ushort *)(*(int *)(unaff_EBP + -0x28) + iVar5));
    iVar2 = FUN_10001000(*piVar1);
  } while (iVar2 != 3);
  (**(code **)**(undefined4 **)(unaff_EDI + 0x1c))(*(int *)(unaff_EBP + -0x28) + iVar5);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  puVar3 = (undefined4 *)
           FUN_1000c566((void *)(unaff_EDI + 4),(ushort *)(iVar5 + *(int *)(unaff_EBP + -0x28)));
  FUN_1000290c((void *)*puVar3,'\0');
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar4 = FUN_1000ceb2();
  return uVar4;
}



// Function: FUN_1000ceda at 1000ceda

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000ceda(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = CRegKeyEx::vftable;
  return;
}



// Function: FUN_1000cf09 at 1000cf09

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000cf09(undefined4 *param_1)

{
  *param_1 = CRegKeyEx::vftable;
  ATL::CRegKey::Close((CRegKey *)(param_1 + 1));
  return;
}



// Function: FUN_1000cf30 at 1000cf30

undefined4 * __thiscall FUN_1000cf30(void *this,byte param_1)

{
  FUN_1000cf09((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000cf4f at 1000cf4f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000cf4f(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if ((undefined4 *)this != param_1) {
                    /* WARNING: Load size is inaccurate */
    uVar1 = *this;
    uVar2 = *(undefined4 *)((int)this + 4);
    uVar3 = *(undefined4 *)((int)this + 8);
    uVar4 = *(undefined4 *)((int)this + 0xc);
    *(undefined4 *)this = *param_1;
    *(undefined4 *)((int)this + 4) = param_1[1];
    *(undefined4 *)((int)this + 8) = param_1[2];
    *(undefined4 *)((int)this + 0xc) = param_1[3];
    *param_1 = uVar1;
    param_1[1] = uVar2;
    param_1[2] = uVar3;
    param_1[3] = uVar4;
    uVar1 = *(undefined4 *)((int)this + 0x10);
    *(undefined4 *)((int)this + 0x10) = param_1[4];
    param_1[4] = uVar1;
    uVar1 = *(undefined4 *)((int)this + 0x14);
    *(undefined4 *)((int)this + 0x14) = param_1[5];
    param_1[5] = uVar1;
  }
  FUN_1000dc87();
  return;
}



// Function: FUN_1000cf9c at 1000cf9c

void * __cdecl FUN_1000cf9c(undefined4 *param_1,undefined4 *param_2,void *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 7) {
    FUN_10001be2(param_3,param_1);
    param_3 = (void *)((int)param_3 + 0x1c);
  }
  return param_3;
}



// Function: FUN_1000cfc0 at 1000cfc0

void __cdecl FUN_1000cfc0(ushort *param_1,ushort *param_2,void *param_3)

{
  int iVar1;
  
  iVar1 = FUN_10001584(param_2,param_1);
  if (iVar1 < 0) {
    FUN_1000cf4f(param_2,(undefined4 *)param_1);
  }
  iVar1 = FUN_10001584(param_3,param_2);
  if (iVar1 < 0) {
    FUN_1000cf4f(param_3,(undefined4 *)param_2);
  }
  iVar1 = FUN_10001584(param_2,param_1);
  if (iVar1 < 0) {
    FUN_1000cf4f(param_2,(undefined4 *)param_1);
  }
  return;
}



// Function: FUN_1000d00d at 1000d00d

void __cdecl FUN_1000d00d(int param_1,int param_2,int param_3,ushort *param_4)

{
  int iVar1;
  undefined4 *this;
  int iVar2;
  
  if (param_3 < param_2) {
    do {
      iVar2 = (param_2 + -1) / 2;
      this = (undefined4 *)(iVar2 * 0x1c + param_1);
      iVar1 = FUN_10001584(this,param_4);
      if (-1 < iVar1) break;
      FUN_10001be2((void *)(param_2 * 0x1c + param_1),this);
      param_2 = iVar2;
    } while (param_3 < iVar2);
  }
  FUN_10001be2((void *)(param_2 * 0x1c + param_1),(undefined4 *)param_4);
  return;
}



// Function: FUN_1000d06f at 1000d06f

void * __cdecl FUN_1000d06f(undefined4 *param_1,undefined4 *param_2,void *param_3)

{
  if (param_1 != param_2) {
    do {
      param_3 = (void *)((int)param_3 + -0x1c);
      param_2 = param_2 + -7;
      FUN_10001be2(param_3,param_2);
    } while (param_2 != param_1);
  }
  return param_3;
}



// Function: FUN_1000d096 at 1000d096

void __cdecl FUN_1000d096(ushort *param_1,ushort *param_2,void *param_3)

{
  ushort *puVar1;
  int iVar2;
  
  iVar2 = ((int)param_3 - (int)param_1) / 0x1c;
  if (iVar2 < 0x29) {
    FUN_1000cfc0(param_1,param_2,param_3);
  }
  else {
    iVar2 = iVar2 + 1;
    iVar2 = (int)(iVar2 + (iVar2 >> 0x1f & 7U)) >> 3;
    FUN_1000cfc0(param_1,param_1 + iVar2 * 0xe,param_1 + iVar2 * 0x1c);
    FUN_1000cfc0(param_2 + iVar2 * -0xe,param_2,param_2 + iVar2 * 0xe);
    puVar1 = (ushort *)((int)param_3 + iVar2 * -0x1c);
    FUN_1000cfc0((ushort *)((int)param_3 + iVar2 * -0x38),puVar1,param_3);
    FUN_1000cfc0(param_1 + iVar2 * 0xe,param_2,puVar1);
  }
  return;
}



// Function: FUN_1000d11d at 1000d11d

void __cdecl FUN_1000d11d(int param_1,int param_2,int param_3,ushort *param_4)

{
  int iVar1;
  void *this;
  int iVar2;
  int iVar3;
  
  iVar3 = param_2;
  while( true ) {
    iVar2 = iVar3 * 2 + 2;
    if (param_3 <= iVar2) break;
    this = (void *)(iVar2 * 0x1c + param_1);
    iVar1 = FUN_10001584(this,(ushort *)((int)this + -0x1c));
    if (iVar1 < 0) {
      iVar2 = iVar3 * 2 + 1;
    }
    FUN_10001be2((void *)(iVar3 * 0x1c + param_1),(undefined4 *)(iVar2 * 0x1c + param_1));
    iVar3 = iVar2;
  }
  if (iVar2 == param_3) {
    FUN_10001be2((void *)(iVar3 * 0x1c + param_1),(undefined4 *)(param_3 * 0x1c + -0x1c + param_1));
    iVar3 = param_3 + -1;
  }
  FUN_1000d00d(param_1,iVar3,param_2,param_4);
  return;
}



// Function: FUN_1000d198 at 1000d198

void __cdecl FUN_1000d198(undefined4 *param_1,int param_2,void *param_3,ushort *param_4)

{
  FUN_10001be2(param_3,param_1);
  FUN_1000d11d((int)param_1,0,(param_2 - (int)param_1) / 0x1c,param_4);
  return;
}



// Function: FUN_1000d1c5 at 1000d1c5

void __thiscall FUN_1000d1c5(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *pvVar1;
  
  if (param_2 != param_3) {
    pvVar1 = FUN_1000cf9c(param_3,*(undefined4 **)((int)this + 4),param_2);
    FUN_10009bf9(pvVar1,*(void **)((int)this + 4),(int)this + 0xc);
    *(void **)((int)this + 4) = pvVar1;
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_1000d209 at 1000d209

void __cdecl FUN_1000d209(undefined4 *param_1,ushort *param_2,ushort *param_3)

{
  int iVar1;
  ushort *puVar2;
  ushort *this;
  ushort *this_00;
  ushort *puVar3;
  ushort *puVar4;
  ushort *local_c;
  ushort *local_8;
  
  puVar4 = param_2 + (((int)param_3 - (int)param_2) / 0x38) * 0xe;
  FUN_1000d096(param_2,puVar4,param_3 + -0xe);
  this_00 = puVar4 + 0xe;
  while (puVar2 = puVar4, param_2 < puVar2) {
    puVar4 = puVar2 + -0xe;
    iVar1 = FUN_10001584(puVar4,puVar2);
    if ((iVar1 < 0) || (iVar1 = FUN_10001584(puVar2,puVar4), iVar1 < 0)) break;
  }
  while ((puVar4 = this_00, local_8 = puVar2, this_00 < param_3 &&
         ((iVar1 = FUN_10001584(this_00,puVar2), -1 < iVar1 &&
          (iVar1 = FUN_10001584(puVar2,this_00), -1 < iVar1))))) {
    this_00 = this_00 + 0xe;
  }
  do {
    while (this = puVar2, local_c = local_8, param_3 <= this_00) {
joined_r0x1000d2bf:
      for (; param_2 < local_8; local_8 = local_8 + -0xe) {
        local_c = local_c + -0xe;
        iVar1 = FUN_10001584(local_c,this);
        if (-1 < iVar1) {
          iVar1 = FUN_10001584(this,local_c);
          if (iVar1 < 0) break;
          this = this + -0xe;
          FUN_1000cf4f(this,(undefined4 *)local_c);
        }
      }
      if (local_8 == param_2) {
        if (this_00 == param_3) {
          param_1[1] = puVar4;
          *param_1 = this;
          return;
        }
        if (puVar4 != this_00) {
          FUN_1000cf4f(this,(undefined4 *)puVar4);
        }
        puVar4 = puVar4 + 0xe;
        puVar3 = this_00 + 0xe;
        puVar2 = this + 0xe;
      }
      else {
        puVar3 = local_8 + -0xe;
        puVar2 = this_00;
        local_8 = puVar3;
        if (this_00 != param_3) goto LAB_1000d2ac;
        this = this + -0xe;
        if (puVar3 != this) {
          FUN_1000cf4f(puVar3,(undefined4 *)this);
        }
        puVar4 = puVar4 + -0xe;
        puVar3 = this_00;
        puVar2 = this;
        this_00 = puVar4;
      }
      FUN_1000cf4f(this,(undefined4 *)this_00);
      this_00 = puVar3;
    }
    iVar1 = FUN_10001584(puVar2,this_00);
    if (-1 < iVar1) {
      iVar1 = FUN_10001584(this_00,puVar2);
      if (iVar1 < 0) goto joined_r0x1000d2bf;
      puVar2 = puVar4;
      puVar4 = puVar4 + 0xe;
      puVar3 = this_00;
LAB_1000d2ac:
      FUN_1000cf4f(puVar2,(undefined4 *)puVar3);
      puVar2 = this;
    }
    this_00 = this_00 + 0xe;
  } while( true );
}



// Function: FUN_1000d363 at 1000d363

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __cdecl FUN_1000d363(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  ushort local_30 [20];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0x1000d36f;
  iVar1 = (param_2 - param_1) / 0x1c;
  iVar2 = iVar1 / 2;
  if (0 < iVar2) {
    puVar3 = (undefined4 *)(iVar2 * 0x1c + param_1);
    do {
      puVar3 = puVar3 + -7;
      iVar2 = iVar2 + -1;
      basic_string<>(local_30,puVar3);
      local_8 = 0;
      FUN_1000d11d(param_1,iVar2,iVar1,local_30);
      local_8 = 0xffffffff;
      FID_conflict__Tidy(local_30,'\x01',0);
    } while (0 < iVar2);
  }
  FUN_1000dc87();
  return;
}



// Function: FUN_1000d3ce at 1000d3ce

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __cdecl FUN_1000d3ce(ushort *param_1,ushort *param_2)

{
  ushort *puVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  ushort *local_34;
  undefined4 local_30 [10];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x1000d3da;
  if (param_1 != param_2) {
    puVar5 = param_1;
    for (puVar4 = param_1 + 0xe; puVar4 != param_2; puVar4 = puVar4 + 0xe) {
      basic_string<>(local_30,(undefined4 *)puVar4);
      local_8 = 0;
      iVar2 = FUN_10001584(local_30,param_1);
      puVar1 = puVar5;
      local_34 = puVar4;
      if (iVar2 < 0) {
        FUN_1000d06f((undefined4 *)param_1,(undefined4 *)puVar4,puVar5 + 0x1c);
        FUN_10001be2(param_1,local_30);
      }
      else {
        while (puVar3 = puVar1, iVar2 = FUN_10001584(local_30,puVar3), iVar2 < 0) {
          FUN_10001be2(local_34,(undefined4 *)puVar3);
          puVar1 = puVar3 + -0xe;
          local_34 = puVar3;
        }
        FUN_10001be2(local_34,local_30);
      }
      local_8 = 0xffffffff;
      FID_conflict__Tidy(local_30,'\x01',0);
      puVar5 = puVar5 + 0xe;
    }
  }
  FUN_1000dc87();
  return;
}



// Function: FUN_1000d485 at 1000d485

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __cdecl FUN_1000d485(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  ushort local_30 [20];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x1000d491;
  puVar1 = (undefined4 *)(param_2 + -0x1c);
  basic_string<>(local_30,puVar1);
  local_8 = 0;
  FUN_1000d198(param_1,(int)puVar1,puVar1,local_30);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_1000dc87();
  return;
}



// Function: FUN_1000d4ce at 1000d4ce

void __cdecl FUN_1000d4ce(int param_1,int param_2)

{
  if (1 < (param_2 - param_1) / 0x1c) {
    FUN_1000d363(param_1,param_2);
  }
  return;
}



// Function: FUN_1000d4f6 at 1000d4f6

void __cdecl FUN_1000d4f6(undefined4 *param_1,int param_2)

{
  int iVar1;
  
  for (iVar1 = param_2 - (int)param_1; 1 < iVar1 / 0x1c; iVar1 = iVar1 + -0x1c) {
    FUN_1000d485(param_1,param_2);
    param_2 = param_2 + -0x1c;
  }
  return;
}



// Function: FUN_1000d536 at 1000d536

void __thiscall FUN_1000d536(void *this,ushort *param_1,ushort *param_2,int param_3)

{
  int iVar1;
  void *this_00;
  ushort *local_c;
  ushort *local_8;
  
  iVar1 = ((int)param_2 - (int)param_1) / 0x1c;
  local_c = (ushort *)this;
  local_8 = (ushort *)this;
  if (0x20 < iVar1) {
    do {
      if (param_3 < 1) break;
      FUN_1000d209(&local_c,param_1,param_2);
      param_3 = param_3 / 2 + (param_3 / 2) / 2;
      this_00 = (void *)(((int)param_2 - (int)local_8) / 0x1c);
      if (((int)local_c - (int)param_1) / 0x1c < (int)this_00) {
        FUN_1000d536(this_00,param_1,local_c,param_3);
        param_1 = local_8;
      }
      else {
        FUN_1000d536(this_00,local_8,param_2,param_3);
        param_2 = local_c;
      }
      iVar1 = ((int)param_2 - (int)param_1) / 0x1c;
    } while (0x20 < iVar1);
    if (0x20 < iVar1) {
      FUN_1000d4ce((int)param_1,(int)param_2);
      FUN_1000d4f6((undefined4 *)param_1,(int)param_2);
      return;
    }
  }
  if (1 < iVar1) {
    FUN_1000d3ce(param_1,param_2);
  }
  return;
}



// Function: FUN_1000d5fb at 1000d5fb

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000d5fb(void *this,LPCWSTR param_1,void *param_2)

{
  longlong lVar1;
  wchar_t *_Str;
  size_t sVar2;
  DWORD dwIndex;
  _FILETIME local_284;
  DWORD local_27c;
  DWORD local_278;
  DWORD local_274;
  DWORD local_270;
  undefined4 local_26c;
  HKEY local_268 [3];
  DWORD local_25c;
  DWORD local_258 [2];
  void *local_250;
  int local_24c;
  void *local_248;
  uint local_244;
  DWORD local_240;
  DWORD local_23c;
  LSTATUS local_238;
  LPWSTR local_234;
  ushort local_230 [14];
  WCHAR local_214;
  undefined1 local_212 [522];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x274;
  local_8 = 0x1000d60a;
  local_250 = param_2;
  FUN_10002308(param_2);
  FUN_1000ceda(&local_26c);
  local_8 = 0;
  if (7 < *(uint *)(param_1 + 10)) {
    param_1 = *(LPCWSTR *)param_1;
  }
  local_24c = Open(local_268,*(HKEY *)((int)this + 4),param_1,0x2001f);
  if (local_24c == 0) {
    local_214 = L'\0';
    memset(local_212,0,0x1fc);
    local_258[1] = 0xff;
    local_238 = RegQueryInfoKeyW(local_268[0],&local_214,local_258 + 1,(LPDWORD)0x0,&local_27c,
                                 &local_270,&local_274,&local_244,&local_240,&local_23c,&local_278,
                                 &local_284);
    lVar1 = (ulonglong)(local_240 + 1) * 2;
    local_234 = (LPWSTR)FUN_1000db1c(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    lVar1 = (ulonglong)(local_23c + 1) * 2;
    _Str = (wchar_t *)FUN_1000db1c(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    dwIndex = 0;
    if (local_244 != 0) {
      do {
        if ((local_238 != 0xea) && (local_238 != 0)) break;
        local_25c = local_240 + 1;
        local_258[0] = local_23c + 1;
        local_238 = RegEnumValueW(local_268[0],dwIndex,local_234,&local_25c,(LPDWORD)0x0,
                                  (LPDWORD)0x0,(LPBYTE)_Str,local_258);
        FUN_10001bb0(local_230,local_234);
        local_8._0_1_ = 1;
        local_248 = (void *)FUN_10002680(local_250,local_230);
        sVar2 = wcslen(_Str);
        FID_conflict_assign(local_248,(undefined4 *)_Str,sVar2);
        local_8 = (uint)local_8._1_3_ << 8;
        FID_conflict__Tidy(local_230,'\x01',0);
        dwIndex = dwIndex + 1;
      } while (dwIndex < local_244);
    }
    operator_delete__(local_234);
    operator_delete__(_Str);
    ATL::CRegKey::Close((CRegKey *)local_268);
  }
  local_8 = 0xffffffff;
  FUN_1000cf09(&local_26c);
  FUN_1000dc87();
  return;
}



// Function: FUN_1000d82f at 1000d82f

void __cdecl FUN_1000d82f(ushort *param_1,ushort *param_2)

{
  FUN_1000d536((void *)0x1c,param_1,param_2,((int)param_2 - (int)param_1) / 0x1c);
  return;
}



// Function: FUN_1000d84f at 1000d84f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000d84f(void *this,undefined4 *param_1,char param_2)

{
  LSTATUS LVar1;
  _FILETIME local_260;
  DWORD local_258;
  DWORD local_254;
  DWORD local_250;
  DWORD local_24c;
  DWORD local_248 [2];
  uint local_240;
  DWORD local_23c;
  uint local_238;
  LPWSTR local_234;
  undefined4 local_230 [7];
  WCHAR local_214;
  undefined1 local_212 [522];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x250;
  local_8 = 0x1000d85e;
  FUN_1000d1c5(param_1,&local_234,(undefined4 *)*param_1,(undefined4 *)param_1[1]);
  local_214 = L'\0';
  memset(local_212,0,0x1fc);
  local_248[1] = 0xff;
  LVar1 = RegQueryInfoKeyW(*(HKEY *)((int)this + 4),&local_214,local_248 + 1,(LPDWORD)0x0,&local_240
                           ,&local_23c,&local_24c,&local_250,&local_254,local_248,&local_258,
                           &local_260);
  local_23c = local_23c + 1;
  local_234 = (LPWSTR)FUN_1000db1c(-(uint)((int)((ulonglong)local_23c * 2 >> 0x20) != 0) |
                                   (uint)((ulonglong)local_23c * 2));
  local_238 = 0;
  if (local_240 != 0) {
    do {
      if ((LVar1 != 0xea) && (LVar1 != 0)) break;
      LVar1 = RegEnumKeyW(*(HKEY *)((int)this + 4),local_238,local_234,local_23c);
      if (LVar1 == 0) {
        FUN_10001bb0(local_230,local_234);
        local_8 = 0;
        FUN_1000ca7d(param_1,local_230);
        local_8 = 0xffffffff;
        FID_conflict__Tidy(local_230,'\x01',0);
      }
      local_238 = local_238 + 1;
    } while (local_238 < local_240);
  }
  if (local_234 != (LPWSTR)0x0) {
    operator_delete__(local_234);
  }
  if (param_2 == '\x01') {
    FUN_1000d82f((ushort *)*param_1,(ushort *)param_1[1]);
  }
  FUN_1000dc87();
  return;
}



// Function: FUN_1000d9e2 at 1000d9e2

void __fastcall FUN_1000d9e2(int *param_1)

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



// Function: FUN_1000da26 at 1000da26

int __fastcall FUN_1000da26(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_1000da3f at 1000da3f

undefined4 * __fastcall FUN_1000da3f(undefined4 *param_1)

{
  long lVar1;
  
  FUN_1000da26((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &DAT_10015e88;
  param_1[3] = &DAT_10015e88;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (lVar1 < 0) {
    DAT_10017c28 = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: FUN_1000da80 at 1000da80

void __fastcall FUN_1000da80(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_1000da9f at 1000da9f

int __fastcall FUN_1000da9f(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_1000dac4 at 1000dac4

void __fastcall FUN_1000dac4(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  FUN_1000da80((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: FUN_1000dadc at 1000dadc

undefined4 * __fastcall FUN_1000dadc(undefined4 *param_1)

{
  long lVar1;
  
  FUN_1000da9f((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_10012118;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 5));
  if (lVar1 < 0) {
    DAT_10017c28 = 1;
  }
  return param_1;
}



// Function: FUN_1000db1c at 1000db1c

void FUN_1000db1c(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: FID_conflict:`vector_deleting_destructor' at 1000db3a

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



// Function: __security_check_cookie at 1000db8c

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_10017c0c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: __EH_prolog3 at 1000db9b

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10017c0c ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch at 1000dbce

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10017c0c ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_GS at 1000dc04

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10017c0c ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch_GS at 1000dc3a

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10017c0c ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_epilog3 at 1000dc73

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



// Function: FUN_1000dc87 at 1000dc87

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000dc87(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x10) ^ unaff_EBP);
  return;
}



// Function: FUN_1000dc96 at 1000dc96

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000dc96(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: __alloca_probe at 1000dcd0

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



// Function: __ArrayUnwind at 1000dd02

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



// Function: `eh_vector_destructor_iterator' at 1000dd60

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
  FUN_1000ddab();
  return;
}



// Function: FUN_1000ddab at 1000ddab

void FUN_1000ddab(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: `eh_vector_constructor_iterator' at 1000ddca

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
  FUN_1000de17();
  return;
}



// Function: FUN_1000de17 at 1000de17

void FUN_1000de17(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __onexit at 1000de2f

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
  
  local_8 = &DAT_10015e20;
  uStack_c = 0x1000de3b;
  local_20[0] = DecodePointer(DAT_100180dc);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_100180dc);
    local_24 = DecodePointer(DAT_100180d8);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_100180dc = EncodePointer(local_20[0]);
    DAT_100180d8 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_1000dec7();
  }
  return p_Var1;
}



// Function: FUN_1000dec7 at 1000dec7

void FUN_1000dec7(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 1000ded0

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: __CRT_INIT@12 at 1000df38

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
    if (DAT_10017d9c < 1) {
      return 0;
    }
    DAT_10017d9c = DAT_10017d9c + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_100180d0,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_100180cc == 2) {
      param_2 = (int *)DecodePointer(DAT_100180dc);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_100180d8);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_100180dc);
            piVar8 = (int *)DecodePointer(DAT_100180d8);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_100180d8 = (PVOID)encoded_null();
        DAT_100180dc = DAT_100180d8;
      }
      DAT_100180cc = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_100180d0,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_100180d0,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_100180cc == 0) {
      DAT_100180cc = 1;
      iVar5 = initterm_e(&DAT_100111f0,&DAT_100111f8);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_100111cc,&DAT_100111ec);
      DAT_100180cc = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_100180d0,0);
    }
    if ((DAT_100180d4 != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_100180d4), BVar2 != 0)) {
      (*DAT_100180d4)(param_1,2,param_3);
    }
    DAT_10017d9c = DAT_10017d9c + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 1000e142

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x1000e1e2) */
/* WARNING: Removing unreachable block (ram,0x1000e18f) */
/* WARNING: Removing unreachable block (ram,0x1000e20f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HMODULE param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_10017c20 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_10017d9c == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(&param_3->unused,param_2,param_1), local_20 != 0)) {
    local_20 = FUN_10003b2c(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      FUN_10003b2c(param_3,0);
      __CRT_INIT_12(&param_3->unused,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(&param_3->unused,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_1000e24d();
  return local_20;
}



// Function: FUN_1000e24d at 1000e24d

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000e24d(void)

{
  _DAT_10017c20 = 0xffffffff;
  return;
}



// Function: entry at 1000e258

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: ___report_gsfailure at 1000e27b

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
  
  _DAT_10017eb8 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_10017ebc = &stack0x00000004;
  _DAT_10017df8 = 0x10001;
  _DAT_10017da0 = 0xc0000409;
  _DAT_10017da4 = 1;
  local_32c = DAT_10017c0c;
  local_328 = DAT_10017c10;
  _DAT_10017dac = unaff_retaddr;
  _DAT_10017e84 = in_GS;
  _DAT_10017e88 = in_FS;
  _DAT_10017e8c = in_ES;
  _DAT_10017e90 = in_DS;
  _DAT_10017e94 = unaff_EDI;
  _DAT_10017e98 = unaff_ESI;
  _DAT_10017e9c = unaff_EBX;
  _DAT_10017ea0 = in_EDX;
  _DAT_10017ea4 = in_ECX;
  _DAT_10017ea8 = in_EAX;
  _DAT_10017eac = unaff_EBP;
  DAT_10017eb0 = unaff_retaddr;
  _DAT_10017eb4 = in_CS;
  _DAT_10017ec0 = in_SS;
  DAT_10017df0 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_10012134);
  if (DAT_10017df0 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __SEH_prolog4 at 1000e390

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10017c0c ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 1000e3d5

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



// Function: FUN_1000e3e9 at 1000e3e9

void __cdecl
FUN_1000e3e9(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_10017c0c,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: __ValidateImageBase at 1000e480

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



// Function: __FindPESection at 1000e4c0

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



// Function: __IsNonwritableInCurrentImage at 1000e510

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
  
  pcStack_10 = FUN_1000e3e9;
  local_14 = ExceptionList;
  local_c = DAT_10017c0c ^ 0x10015e68;
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



// Function: ___security_init_cookie at 1000e5e4

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
  if ((DAT_10017c0c == 0xbb40e64e) || ((DAT_10017c0c & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_10017c0c = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_10017c0c == 0xbb40e64e) {
      DAT_10017c0c = 0xbb40e64f;
    }
    else if ((DAT_10017c0c & 0xffff0000) == 0) {
      DAT_10017c0c = DAT_10017c0c | (DAT_10017c0c | 0x4711) << 0x10;
    }
    DAT_10017c10 = ~DAT_10017c0c;
  }
  else {
    DAT_10017c10 = ~DAT_10017c0c;
  }
  return;
}



// Function: Unwind@1000e698 at 1000e698

void Unwind_1000e698(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000e69b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e6bc at 1000e6bc

void Unwind_1000e6bc(void)

{
  int unaff_EBP;
  
  FUN_10006fb6(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e6df at 1000e6df

void Unwind_1000e6df(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1000e6e7 at 1000e6e7

void Unwind_1000e6e7(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1000e6ef at 1000e6ef

void Unwind_1000e6ef(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1000e71c at 1000e71c

void Unwind_1000e71c(void)

{
  int unaff_EBP;
  
  FUN_10006fb6(*(int **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000e724 at 1000e724

void Unwind_1000e724(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10001282(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000e773 at 1000e773

void Unwind_1000e773(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e77b at 1000e77b

void Unwind_1000e77b(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@1000e7a1 at 1000e7a1

void Unwind_1000e7a1(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000e7d5 at 1000e7d5

void Unwind_1000e7d5(void)

{
  int unaff_EBP;
  
  FUN_10001774(*(void **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000e7f8 at 1000e7f8

void Unwind_1000e7f8(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e800 at 1000e800

void Unwind_1000e800(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1000e82d at 1000e82d

void Unwind_1000e82d(void)

{
  int unaff_EBP;
  
  FUN_10001774(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e86b at 1000e86b

void Unwind_1000e86b(void)

{
  int unaff_EBP;
  
  FUN_1000251d(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000e88e at 1000e88e

void Unwind_1000e88e(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000e899 at 1000e899

void Unwind_1000e899(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1000e8a4 at 1000e8a4

void Unwind_1000e8a4(void)

{
  int unaff_EBP;
  
  FUN_100025a7((void *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@1000e8af at 1000e8af

void Unwind_1000e8af(void)

{
  int unaff_EBP;
  
  FUN_1000251d(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000e8b7 at 1000e8b7

void Unwind_1000e8b7(void)

{
  int unaff_EBP;
  
  FUN_10006fb6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000e8da at 1000e8da

void Unwind_1000e8da(void)

{
  int unaff_EBP;
  
  FUN_100034a3(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000e8e2 at 1000e8e2

void Unwind_1000e8e2(void)

{
  int unaff_EBP;
  
  FUN_1000251d(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000e905 at 1000e905

void Unwind_1000e905(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e90d at 1000e90d

void Unwind_1000e90d(void)

{
  int unaff_EBP;
  
  FUN_10001774((void *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1000e915 at 1000e915

void Unwind_1000e915(void)

{
  int unaff_EBP;
  
  FUN_100018f0((void *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1000e91d at 1000e91d

void Unwind_1000e91d(void)

{
  int unaff_EBP;
  
  FUN_10001774((void *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1000e94a at 1000e94a

void Unwind_1000e94a(void)

{
  int unaff_EBP;
  
  FUN_1000cf09((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000e952 at 1000e952

void Unwind_1000e952(void)

{
  int unaff_EBP;
  
  FUN_100025a7((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e95a at 1000e95a

void Unwind_1000e95a(void)

{
  int unaff_EBP;
  
  FUN_1000251d((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e962 at 1000e962

void Unwind_1000e962(void)

{
  int unaff_EBP;
  
  FUN_1000251d((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e985 at 1000e985

void Unwind_1000e985(void)

{
  int unaff_EBP;
  
  FUN_10006fb6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000e98d at 1000e98d

void Unwind_1000e98d(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000e998 at 1000e998

void Unwind_1000e998(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1000e9a3 at 1000e9a3

void Unwind_1000e9a3(void)

{
  int unaff_EBP;
  
  FUN_100025a7((void *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@1000e9c9 at 1000e9c9

void Unwind_1000e9c9(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1000e9d1 at 1000e9d1

void Unwind_1000e9d1(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000e9fe at 1000e9fe

void Unwind_1000e9fe(void)

{
  DAT_10017c78 = DAT_10017c78 & 0xfffffffe;
  return;
}



// Function: Unwind@1000ea27 at 1000ea27

void Unwind_1000ea27(void)

{
  int unaff_EBP;
  
  FUN_10002bb5(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ea4a at 1000ea4a

void Unwind_1000ea4a(void)

{
  int unaff_EBP;
  
  FUN_10002b32(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ea6d at 1000ea6d

void Unwind_1000ea6d(void)

{
  int unaff_EBP;
  
  FUN_10003635(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ea90 at 1000ea90

void Unwind_1000ea90(void)

{
  int unaff_EBP;
  
  FUN_1000145a((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000eac3 at 1000eac3

void Unwind_1000eac3(void)

{
  int unaff_EBP;
  
  FUN_1000339b((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@1000eaf6 at 1000eaf6

void Unwind_1000eaf6(void)

{
  int unaff_EBP;
  
  FUN_100033e2((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000eb1c at 1000eb1c

void Unwind_1000eb1c(void)

{
  FUN_100011b4();
  return;
}



// Function: Unwind@1000eb33 at 1000eb33

void Unwind_1000eb33(void)

{
  FUN_100011b4();
  return;
}



// Function: Unwind@1000eb66 at 1000eb66

void Unwind_1000eb66(void)

{
  int unaff_EBP;
  
  FUN_100033e2((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1000eb71 at 1000eb71

void Unwind_1000eb71(void)

{
  int unaff_EBP;
  
  FUN_10003aa0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1000eb97 at 1000eb97

void Unwind_1000eb97(void)

{
  int unaff_EBP;
  
  FUN_10003635(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000eb9f at 1000eb9f

void Unwind_1000eb9f(void)

{
  int unaff_EBP;
  
  FUN_1000363a(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ebc2 at 1000ebc2

void Unwind_1000ebc2(void)

{
  int unaff_EBP;
  
  FUN_1000363a(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ebca at 1000ebca

void Unwind_1000ebca(void)

{
  int unaff_EBP;
  
  FUN_10003635(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ebed at 1000ebed

void Unwind_1000ebed(void)

{
  int unaff_EBP;
  
  FUN_10003a7e(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ec10 at 1000ec10

void Unwind_1000ec10(void)

{
  int unaff_EBP;
  
  FUN_10003d69((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000ec36 at 1000ec36

void Unwind_1000ec36(void)

{
  int unaff_EBP;
  
  FUN_10002ebf(unaff_EBP + -0x6c);
  return;
}



// Function: Unwind@1000ec63 at 1000ec63

void Unwind_1000ec63(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000ec6e at 1000ec6e

void Unwind_1000ec6e(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000ec79 at 1000ec79

void Unwind_1000ec79(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000ec84 at 1000ec84

void Unwind_1000ec84(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000ec8f at 1000ec8f

void Unwind_1000ec8f(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000ec9a at 1000ec9a

void Unwind_1000ec9a(void)

{
  int unaff_EBP;
  
  FUN_1000339b((int *)(unaff_EBP + -0x1c8));
  return;
}



// Function: Unwind@1000eca5 at 1000eca5

void Unwind_1000eca5(void)

{
  int unaff_EBP;
  
  FUN_1000145a((undefined4 *)(unaff_EBP + -0x1c4));
  return;
}



// Function: Unwind@1000ecb0 at 1000ecb0

void Unwind_1000ecb0(void)

{
  int unaff_EBP;
  
  FUN_1000145a((undefined4 *)(unaff_EBP + -0x1b8));
  return;
}



// Function: Unwind@1000ecbb at 1000ecbb

void Unwind_1000ecbb(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000ecc6 at 1000ecc6

void Unwind_1000ecc6(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000ecf9 at 1000ecf9

void Unwind_1000ecf9(void)

{
  int unaff_EBP;
  
  FUN_10002bb5((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000ed01 at 1000ed01

void Unwind_1000ed01(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ed09 at 1000ed09

void Unwind_1000ed09(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ed11 at 1000ed11

void Unwind_1000ed11(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ed19 at 1000ed19

void Unwind_1000ed19(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ed3c at 1000ed3c

void Unwind_1000ed3c(void)

{
  int unaff_EBP;
  
  FUN_10002bb5((undefined4 *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000ed47 at 1000ed47

void Unwind_1000ed47(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000ed52 at 1000ed52

void Unwind_1000ed52(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000ed5d at 1000ed5d

void Unwind_1000ed5d(void)

{
  int unaff_EBP;
  
  FUN_10002bb5((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000ed68 at 1000ed68

void Unwind_1000ed68(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000ed73 at 1000ed73

void Unwind_1000ed73(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000eda6 at 1000eda6

void Unwind_1000eda6(void)

{
  int unaff_EBP;
  
  FUN_10003b15((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000edc9 at 1000edc9

void Unwind_1000edc9(void)

{
  int unaff_EBP;
  
  FUN_10003aa0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1000edd4 at 1000edd4

void Unwind_1000edd4(void)

{
  int unaff_EBP;
  
  FUN_100033e2((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000edfa at 1000edfa

void Unwind_1000edfa(void)

{
  int unaff_EBP;
  
  FUN_10004857(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ee1d at 1000ee1d

void Unwind_1000ee1d(void)

{
  int unaff_EBP;
  
  FUN_10003a83((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000ee25 at 1000ee25

void Unwind_1000ee25(void)

{
  int unaff_EBP;
  
  FUN_10003a83((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000ee48 at 1000ee48

void Unwind_1000ee48(void)

{
  int unaff_EBP;
  
  FUN_10003a93((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@1000ee53 at 1000ee53

void Unwind_1000ee53(void)

{
  int unaff_EBP;
  
  FUN_1000339b((int *)(unaff_EBP + -0x2120));
  return;
}



// Function: Unwind@1000ee5e at 1000ee5e

void Unwind_1000ee5e(void)

{
  int unaff_EBP;
  
  FUN_10003a93((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@1000ee91 at 1000ee91

void Unwind_1000ee91(void)

{
  int unaff_EBP;
  
  FUN_1000145a((undefined4 *)(unaff_EBP + -0x2230));
  return;
}



// Function: Unwind@1000ee9c at 1000ee9c

void Unwind_1000ee9c(void)

{
  int unaff_EBP;
  
  FUN_1000145a((undefined4 *)(unaff_EBP + -0x2240));
  return;
}



// Function: Unwind@1000eea7 at 1000eea7

void Unwind_1000eea7(void)

{
  int unaff_EBP;
  
  FUN_1000145a((undefined4 *)(unaff_EBP + -0x2258));
  return;
}



// Function: Unwind@1000eeb2 at 1000eeb2

void Unwind_1000eeb2(void)

{
  int unaff_EBP;
  
  FUN_1000145a((undefined4 *)(unaff_EBP + -0x2264));
  return;
}



// Function: Unwind@1000eebd at 1000eebd

void Unwind_1000eebd(void)

{
  int unaff_EBP;
  
  FUN_1000145a((undefined4 *)(unaff_EBP + -0x224c));
  return;
}



// Function: Unwind@1000eef0 at 1000eef0

void Unwind_1000eef0(void)

{
  int unaff_EBP;
  
  FUN_10003b15((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000ef13 at 1000ef13

void Unwind_1000ef13(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000ef38 at 1000ef38

void Unwind_1000ef38(void)

{
  int unaff_EBP;
  
  FUN_10004b2b(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ef40 at 1000ef40

void Unwind_1000ef40(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ef63 at 1000ef63

void Unwind_1000ef63(void)

{
  int unaff_EBP;
  
  FUN_1000339b((int *)(unaff_EBP + -0x428));
  return;
}



// Function: Unwind@1000ef6e at 1000ef6e

void Unwind_1000ef6e(void)

{
  int unaff_EBP;
  
  FUN_10003a93((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@1000efa1 at 1000efa1

void Unwind_1000efa1(void)

{
  int unaff_EBP;
  
  FUN_1000339b((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000efc4 at 1000efc4

void Unwind_1000efc4(void)

{
  int unaff_EBP;
  
  FUN_10003a7e(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1000efcf at 1000efcf

void Unwind_1000efcf(void)

{
  int unaff_EBP;
  
  FUN_10003d69((int *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@1000efda at 1000efda

void Unwind_1000efda(void)

{
  int unaff_EBP;
  
  FUN_10003d93((undefined4 *)(unaff_EBP + -0xa5c));
  return;
}



// Function: Unwind@1000efe5 at 1000efe5

void Unwind_1000efe5(void)

{
  int unaff_EBP;
  
  FUN_1000339b((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1000f018 at 1000f018

void Unwind_1000f018(void)

{
  int unaff_EBP;
  
  FUN_10003a7e(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1000f023 at 1000f023

void Unwind_1000f023(void)

{
  int unaff_EBP;
  
  FUN_10003d69((int *)(unaff_EBP + -0xa54));
  return;
}



// Function: Unwind@1000f02e at 1000f02e

void Unwind_1000f02e(void)

{
  int unaff_EBP;
  
  FUN_10003d93((undefined4 *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@1000f039 at 1000f039

void Unwind_1000f039(void)

{
  int unaff_EBP;
  
  FUN_1000339b((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1000f06c at 1000f06c

void Unwind_1000f06c(void)

{
  int unaff_EBP;
  
  FUN_10006569(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000f08f at 1000f08f

void Unwind_1000f08f(void)

{
  int unaff_EBP;
  
  FUN_100034a3(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000f0b2 at 1000f0b2

void Unwind_1000f0b2(void)

{
  int unaff_EBP;
  
  FUN_100068eb(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000f0d5 at 1000f0d5

void Unwind_1000f0d5(void)

{
  int unaff_EBP;
  
  FUN_10006925((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000f0e0 at 1000f0e0

void Unwind_1000f0e0(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@1000f0eb at 1000f0eb

void Unwind_1000f0eb(void)

{
  int unaff_EBP;
  
  FUN_10006fb6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000f0f3 at 1000f0f3

void Unwind_1000f0f3(void)

{
  int unaff_EBP;
  
  FUN_100068eb(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000f116 at 1000f116

void Unwind_1000f116(void)

{
  int unaff_EBP;
  
  FUN_10003aa0(*(int *)(unaff_EBP + -0x10) + 0x28);
  return;
}



// Function: Unwind@1000f121 at 1000f121

void Unwind_1000f121(void)

{
  int unaff_EBP;
  
  FUN_10006943(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1000f12c at 1000f12c

void Unwind_1000f12c(void)

{
  int unaff_EBP;
  
  FUN_1000c50c((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x4c));
  return;
}



// Function: Unwind@1000f137 at 1000f137

void Unwind_1000f137(void)

{
  int unaff_EBP;
  
  FUN_10006564((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x6c));
  return;
}



// Function: Unwind@1000f142 at 1000f142

void Unwind_1000f142(void)

{
  int unaff_EBP;
  
  FUN_10006564((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x7c));
  return;
}



// Function: Unwind@1000f14d at 1000f14d

void Unwind_1000f14d(void)

{
  int unaff_EBP;
  
  FUN_10006564((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x8c));
  return;
}



// Function: Unwind@1000f15b at 1000f15b

void Unwind_1000f15b(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x9c));
  return;
}



// Function: Unwind@1000f169 at 1000f169

void Unwind_1000f169(void)

{
  int unaff_EBP;
  
  FUN_100065b2((void *)(*(int *)(unaff_EBP + -0x10) + 0xb8));
  return;
}



// Function: Unwind@1000f177 at 1000f177

void Unwind_1000f177(void)

{
  int unaff_EBP;
  
  FUN_10006569(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000f17f at 1000f17f

void Unwind_1000f17f(void)

{
  int unaff_EBP;
  
  FUN_100033e2((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1000f1a5 at 1000f1a5

void Unwind_1000f1a5(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000f1ad at 1000f1ad

void Unwind_1000f1ad(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000f1b5 at 1000f1b5

void Unwind_1000f1b5(void)

{
  int unaff_EBP;
  
  FUN_10002bb5((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000f1bd at 1000f1bd

void Unwind_1000f1bd(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000f1e0 at 1000f1e0

void Unwind_1000f1e0(void)

{
  int unaff_EBP;
  
  FUN_10002bb5((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000f203 at 1000f203

void Unwind_1000f203(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000f20b at 1000f20b

void Unwind_1000f20b(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000f213 at 1000f213

void Unwind_1000f213(void)

{
  int unaff_EBP;
  
  FUN_10002bb5((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000f21b at 1000f21b

void Unwind_1000f21b(void)

{
  int unaff_EBP;
  
  FUN_10002bb5((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000f223 at 1000f223

void Unwind_1000f223(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000f246 at 1000f246

void Unwind_1000f246(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000f250 at 1000f250

void Unwind_1000f250(void)

{
  int unaff_EBP;
  
  FUN_10002bb5((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000f273 at 1000f273

void Unwind_1000f273(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000f27b at 1000f27b

void Unwind_1000f27b(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000f283 at 1000f283

void Unwind_1000f283(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000f28b at 1000f28b

void Unwind_1000f28b(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000f293 at 1000f293

void Unwind_1000f293(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000f29b at 1000f29b

void Unwind_1000f29b(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000f2be at 1000f2be

void Unwind_1000f2be(void)

{
  int unaff_EBP;
  
  FUN_10003b15((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000f2e1 at 1000f2e1

void Unwind_1000f2e1(void)

{
  int unaff_EBP;
  
  FUN_10003b15((undefined4 *)(unaff_EBP + -0x238));
  return;
}



// Function: Unwind@1000f2ec at 1000f2ec

void Unwind_1000f2ec(void)

{
  int unaff_EBP;
  
  FUN_1000339b((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000f2f7 at 1000f2f7

void Unwind_1000f2f7(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000f302 at 1000f302

void Unwind_1000f302(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000f30d at 1000f30d

void Unwind_1000f30d(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000f318 at 1000f318

void Unwind_1000f318(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000f323 at 1000f323

void Unwind_1000f323(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000f32e at 1000f32e

void Unwind_1000f32e(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000f339 at 1000f339

void Unwind_1000f339(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000f344 at 1000f344

void Unwind_1000f344(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000f34f at 1000f34f

void Unwind_1000f34f(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000f382 at 1000f382

void Unwind_1000f382(void)

{
  int unaff_EBP;
  
  FUN_10002bb5((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000f3db at 1000f3db

void Unwind_1000f3db(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000f3fe at 1000f3fe

void Unwind_1000f3fe(void)

{
  int unaff_EBP;
  
  FUN_10004b2b(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000f421 at 1000f421

void Unwind_1000f421(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1000f447 at 1000f447

void Unwind_1000f447(void)

{
  int unaff_EBP;
  
  FUN_10006d38((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1000f48f at 1000f48f

void Unwind_1000f48f(void)

{
  int unaff_EBP;
  
  FUN_10006a86((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1000f4b2 at 1000f4b2

void Unwind_1000f4b2(void)

{
  int unaff_EBP;
  
  FUN_10006a86((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000f4ba at 1000f4ba

void Unwind_1000f4ba(void)

{
  int unaff_EBP;
  
  FUN_10002bb5((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000f4dd at 1000f4dd

void Unwind_1000f4dd(void)

{
  int unaff_EBP;
  
  FUN_10006a86((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1000f500 at 1000f500

void Unwind_1000f500(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000f508 at 1000f508

void Unwind_1000f508(void)

{
  int unaff_EBP;
  
  FUN_10004b2b((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000f510 at 1000f510

void Unwind_1000f510(void)

{
  int unaff_EBP;
  
  FUN_10005932((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000f518 at 1000f518

void Unwind_1000f518(void)

{
  int unaff_EBP;
  
  FUN_10004b2b((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000f520 at 1000f520

void Unwind_1000f520(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000f568 at 1000f568

void Unwind_1000f568(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000f595 at 1000f595

void Unwind_1000f595(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000f59d at 1000f59d

void Unwind_1000f59d(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000f5a5 at 1000f5a5

void Unwind_1000f5a5(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000f5ad at 1000f5ad

void Unwind_1000f5ad(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1000f5b5 at 1000f5b5

void Unwind_1000f5b5(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1000f5bd at 1000f5bd

void Unwind_1000f5bd(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000f5c5 at 1000f5c5

void Unwind_1000f5c5(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000f5cd at 1000f5cd

void Unwind_1000f5cd(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1000f5fa at 1000f5fa

void Unwind_1000f5fa(void)

{
  int unaff_EBP;
  
  FUN_10002bb5((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000f602 at 1000f602

void Unwind_1000f602(void)

{
  int unaff_EBP;
  
  FUN_10002bb5((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1000f60a at 1000f60a

void Unwind_1000f60a(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000f637 at 1000f637

void Unwind_1000f637(void)

{
  int unaff_EBP;
  
  FUN_10006987(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000f65a at 1000f65a

void Unwind_1000f65a(void)

{
  int unaff_EBP;
  
  FUN_10006a1f(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1000f680 at 1000f680

void Unwind_1000f680(void)

{
  int unaff_EBP;
  
  FUN_10006a1f(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1000f68b at 1000f68b

void Unwind_1000f68b(void)

{
  int unaff_EBP;
  
  FUN_10006987(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000f6c9 at 1000f6c9

void Unwind_1000f6c9(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000f6ee at 1000f6ee

void Unwind_1000f6ee(void)

{
  FUN_1000363a(0x10017c7c);
  return;
}



// Function: Unwind@1000f6f8 at 1000f6f8

void Unwind_1000f6f8(void)

{
  FUN_10003635(0x10017c7c);
  return;
}



// Function: Unwind@1000f738 at 1000f738

void Unwind_1000f738(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000f743 at 1000f743

void Unwind_1000f743(void)

{
  int unaff_EBP;
  
  FUN_10006fb6(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000f766 at 1000f766

void Unwind_1000f766(void)

{
  int unaff_EBP;
  
  FUN_10001282(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000f76e at 1000f76e

void Unwind_1000f76e(void)

{
  int unaff_EBP;
  
  FUN_10006fb6(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000f791 at 1000f791

void Unwind_1000f791(void)

{
  int unaff_EBP;
  
  FUN_10008bf1(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000f7b4 at 1000f7b4

void Unwind_1000f7b4(void)

{
  int unaff_EBP;
  
  FUN_10006fb6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000f7bc at 1000f7bc

void Unwind_1000f7bc(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000f7c7 at 1000f7c7

void Unwind_1000f7c7(void)

{
  int unaff_EBP;
  
  FUN_10008bf1(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000f805 at 1000f805

void Unwind_1000f805(void)

{
  int unaff_EBP;
  
  FUN_10008ddf(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000f828 at 1000f828

void Unwind_1000f828(void)

{
  int unaff_EBP;
  
  FUN_10008ddf(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000f830 at 1000f830

void Unwind_1000f830(void)

{
  int unaff_EBP;
  
  FUN_10008bf1(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000f86e at 1000f86e

void Unwind_1000f86e(void)

{
  int unaff_EBP;
  
  FUN_10006a86((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1000f891 at 1000f891

void Unwind_1000f891(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008ab5((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000f899 at 1000f899

void Unwind_1000f899(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000f8a1 at 1000f8a1

void Unwind_1000f8a1(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000f8c4 at 1000f8c4

void Unwind_1000f8c4(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008ab5((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000f8cc at 1000f8cc

void Unwind_1000f8cc(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1000f8d4 at 1000f8d4

void Unwind_1000f8d4(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1000f912 at 1000f912

void Unwind_1000f912(void)

{
  int unaff_EBP;
  
  FUN_10006a86((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1000f986 at 1000f986

void Unwind_1000f986(void)

{
  DAT_10017cc8 = DAT_10017cc8 & 0xfffffffe;
  return;
}



// Function: Unwind@1000f9af at 1000f9af

void Unwind_1000f9af(void)

{
  int unaff_EBP;
  
  FUN_100034a3(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000f9b7 at 1000f9b7

void Unwind_1000f9b7(void)

{
  int unaff_EBP;
  
  FUN_10006569(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000f9da at 1000f9da

void Unwind_1000f9da(void)

{
  int unaff_EBP;
  
  FUN_10006a86((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1000f9e2 at 1000f9e2

void Unwind_1000f9e2(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000f9ea at 1000f9ea

void Unwind_1000f9ea(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008ab5((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000fa17 at 1000fa17

void Unwind_1000fa17(void)

{
  int unaff_EBP;
  
  FUN_10006a86((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000fa3a at 1000fa3a

void Unwind_1000fa3a(void)

{
  int unaff_EBP;
  
  FUN_10006a86((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1000fa42 at 1000fa42

void Unwind_1000fa42(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000fa6f at 1000fa6f

void Unwind_1000fa6f(void)

{
  int unaff_EBP;
  
  FUN_10006a86((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1000fa77 at 1000fa77

void Unwind_1000fa77(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000faa4 at 1000faa4

void Unwind_1000faa4(void)

{
  int unaff_EBP;
  
  FUN_10006a86((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1000faac at 1000faac

void Unwind_1000faac(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000fab4 at 1000fab4

void Unwind_1000fab4(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008ab5((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1000fabc at 1000fabc

void Unwind_1000fabc(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008ab5((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1000fac4 at 1000fac4

void Unwind_1000fac4(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008ab5((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1000facc at 1000facc

void Unwind_1000facc(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000fad4 at 1000fad4

void Unwind_1000fad4(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000fb01 at 1000fb01

void Unwind_1000fb01(void)

{
  int unaff_EBP;
  
  FUN_10006a86((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000fb09 at 1000fb09

void Unwind_1000fb09(void)

{
  int unaff_EBP;
  
  FUN_1000145a((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1000fb11 at 1000fb11

void Unwind_1000fb11(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000fb19 at 1000fb19

void Unwind_1000fb19(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1000fb21 at 1000fb21

void Unwind_1000fb21(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1000fb29 at 1000fb29

void Unwind_1000fb29(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000fb31 at 1000fb31

void Unwind_1000fb31(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000fb39 at 1000fb39

void Unwind_1000fb39(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1000fb41 at 1000fb41

void Unwind_1000fb41(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1000fb49 at 1000fb49

void Unwind_1000fb49(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1000fb51 at 1000fb51

void Unwind_1000fb51(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000fb59 at 1000fb59

void Unwind_1000fb59(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1000fb86 at 1000fb86

void Unwind_1000fb86(void)

{
  int unaff_EBP;
  
  FUN_10006a86((undefined4 *)(unaff_EBP + -0x98));
  return;
}



// Function: Unwind@1000fb91 at 1000fb91

void Unwind_1000fb91(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000fb99 at 1000fb99

void Unwind_1000fb99(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000fba1 at 1000fba1

void Unwind_1000fba1(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008ab5((int *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1000fbac at 1000fbac

void Unwind_1000fbac(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1000fbb4 at 1000fbb4

void Unwind_1000fbb4(void)

{
  int unaff_EBP;
  
  FUN_10002bb5((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@1000fbbc at 1000fbbc

void Unwind_1000fbbc(void)

{
  int unaff_EBP;
  
  FUN_10008b50(unaff_EBP + -0x80);
  return;
}



// Function: Unwind@1000fbec at 1000fbec

void Unwind_1000fbec(void)

{
  int unaff_EBP;
  
  FUN_10006a86((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000fbf4 at 1000fbf4

void Unwind_1000fbf4(void)

{
  int unaff_EBP;
  
  thunk_FUN_10009d8a((_Container_base0 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000fc21 at 1000fc21

void Unwind_1000fc21(void)

{
  int unaff_EBP;
  
  FUN_10006a86((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000fc29 at 1000fc29

void Unwind_1000fc29(void)

{
  int unaff_EBP;
  
  thunk_FUN_10009d8a((_Container_base0 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000fc56 at 1000fc56

void Unwind_1000fc56(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000fc5e at 1000fc5e

void Unwind_1000fc5e(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000fc66 at 1000fc66

void Unwind_1000fc66(void)

{
  int unaff_EBP;
  
  FUN_10008dba((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000fc6e at 1000fc6e

void Unwind_1000fc6e(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000fc76 at 1000fc76

void Unwind_1000fc76(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000fc99 at 1000fc99

void Unwind_1000fc99(void)

{
  int unaff_EBP;
  
  FUN_100034a3(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000fca1 at 1000fca1

void Unwind_1000fca1(void)

{
  int unaff_EBP;
  
  FUN_100068eb(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000fcc4 at 1000fcc4

void Unwind_1000fcc4(void)

{
  int unaff_EBP;
  
  FUN_10006a86((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1000fccc at 1000fccc

void Unwind_1000fccc(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000fcf9 at 1000fcf9

void Unwind_1000fcf9(void)

{
  int unaff_EBP;
  
  FUN_10006a86((undefined4 *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1000fd01 at 1000fd01

void Unwind_1000fd01(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000fd09 at 1000fd09

void Unwind_1000fd09(void)

{
  int unaff_EBP;
  
  FUN_10008b50(unaff_EBP + -0x40);
  return;
}



// Function: Unwind@1000fd36 at 1000fd36

void Unwind_1000fd36(void)

{
  int unaff_EBP;
  
  FUN_10006a86((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1000fd3e at 1000fd3e

void Unwind_1000fd3e(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000fd6b at 1000fd6b

void Unwind_1000fd6b(void)

{
  int unaff_EBP;
  
  FUN_10008b50(unaff_EBP + -0x44);
  return;
}



// Function: Unwind@1000fd73 at 1000fd73

void Unwind_1000fd73(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000fda0 at 1000fda0

void Unwind_1000fda0(void)

{
  int unaff_EBP;
  
  FUN_10006925((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000fdab at 1000fdab

void Unwind_1000fdab(void)

{
  int unaff_EBP;
  
  FUN_10006fb6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000fdb3 at 1000fdb3

void Unwind_1000fdb3(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@1000fdd9 at 1000fdd9

void Unwind_1000fdd9(void)

{
  int unaff_EBP;
  
  FUN_100033e2((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1000fde4 at 1000fde4

void Unwind_1000fde4(void)

{
  int unaff_EBP;
  
  FUN_10003aa0(*(int *)(unaff_EBP + -0x10) + 0x28);
  return;
}



// Function: Unwind@1000fdef at 1000fdef

void Unwind_1000fdef(void)

{
  int unaff_EBP;
  
  FUN_10006943(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1000fdfa at 1000fdfa

void Unwind_1000fdfa(void)

{
  int unaff_EBP;
  
  FUN_1000c50c((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x4c));
  return;
}



// Function: Unwind@1000fe05 at 1000fe05

void Unwind_1000fe05(void)

{
  int unaff_EBP;
  
  FUN_10006564((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x6c));
  return;
}



// Function: Unwind@1000fe10 at 1000fe10

void Unwind_1000fe10(void)

{
  int unaff_EBP;
  
  FUN_10006564((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x7c));
  return;
}



// Function: Unwind@1000fe1b at 1000fe1b

void Unwind_1000fe1b(void)

{
  int unaff_EBP;
  
  FUN_10006564((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x8c));
  return;
}



// Function: Unwind@1000fe29 at 1000fe29

void Unwind_1000fe29(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x9c));
  return;
}



// Function: Unwind@1000fe37 at 1000fe37

void Unwind_1000fe37(void)

{
  int unaff_EBP;
  
  FUN_100065b2((void *)(*(int *)(unaff_EBP + -0x10) + 0xb8));
  return;
}



// Function: Unwind@1000fe60 at 1000fe60

void Unwind_1000fe60(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000fe63. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000fe84 at 1000fe84

void Unwind_1000fe84(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000fe8c at 1000fe8c

void Unwind_1000fe8c(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008ab5((int *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@1000feb2 at 1000feb2

void Unwind_1000feb2(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008ab5((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000fed5 at 1000fed5

void Unwind_1000fed5(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008ab5((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000fef8 at 1000fef8

void Unwind_1000fef8(void)

{
  int unaff_EBP;
  
  FUN_1000b034(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ff36 at 1000ff36

void Unwind_1000ff36(void)

{
  int unaff_EBP;
  
  FUN_1000b034(*(void **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000ff74 at 1000ff74

void Unwind_1000ff74(void)

{
  FUN_100011b4();
  return;
}



// Function: Unwind@1000ffd3 at 1000ffd3

void Unwind_1000ffd3(void)

{
  int unaff_EBP;
  
  FUN_1000c452(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000fff6 at 1000fff6

void Unwind_1000fff6(void)

{
  int unaff_EBP;
  
  FUN_1000c4ee((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10010001 at 10010001

void Unwind_10010001(void)

{
  int unaff_EBP;
  
  FUN_1000c452(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010024 at 10010024

void Unwind_10010024(void)

{
  int unaff_EBP;
  
  FUN_100034a3(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001002c at 1001002c

void Unwind_1001002c(void)

{
  int unaff_EBP;
  
  FUN_1000c452(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001004f at 1001004f

void Unwind_1001004f(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008ab5((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10010057 at 10010057

void Unwind_10010057(void)

{
  int unaff_EBP;
  
  FUN_1000b034((void *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001005f at 1001005f

void Unwind_1001005f(void)

{
  int unaff_EBP;
  
  FUN_1000b225((void *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10010067 at 10010067

void Unwind_10010067(void)

{
  int unaff_EBP;
  
  FUN_1000b034((void *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100100af at 100100af

void Unwind_100100af(void)

{
  int unaff_EBP;
  
  FUN_1000c4ee((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100100d5 at 100100d5

void Unwind_100100d5(void)

{
  int unaff_EBP;
  
  FUN_1000cf09((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@100100dd at 100100dd

void Unwind_100100dd(void)

{
  int unaff_EBP;
  
  thunk_FUN_10009d8a((_Container_base0 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100100e5 at 100100e5

void Unwind_100100e5(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@100100ed at 100100ed

void Unwind_100100ed(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@100100f7 at 100100f7

void Unwind_100100f7(void)

{
  int unaff_EBP;
  
  thunk_FUN_10008ab5((int *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@10010124 at 10010124

void Unwind_10010124(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001012c at 1001012c

void Unwind_1001012c(void)

{
  int unaff_EBP;
  
  FUN_10001282((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10010134 at 10010134

void Unwind_10010134(void)

{
  int unaff_EBP;
  
  FUN_10006fb6((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10010161 at 10010161

void Unwind_10010161(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    thunk_FUN_10008ab5(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10010195 at 10010195

void Unwind_10010195(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000bbd2((_Container_base0 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001019d at 1001019d

void Unwind_1001019d(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@100101a5 at 100101a5

void Unwind_100101a5(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@100101d2 at 100101d2

void Unwind_100101d2(void)

{
  int unaff_EBP;
  
  thunk_FUN_10009d8a((_Container_base0 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@100101da at 100101da

void Unwind_100101da(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10010207 at 10010207

void Unwind_10010207(void)

{
  int unaff_EBP;
  
  thunk_FUN_10009d8a((_Container_base0 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001022a at 1001022a

void Unwind_1001022a(void)

{
  int unaff_EBP;
  
  thunk_FUN_10009d8a((_Container_base0 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001024d at 1001024d

void Unwind_1001024d(void)

{
  int unaff_EBP;
  
  FUN_1000145a((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10010298 at 10010298

void Unwind_10010298(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@100102c5 at 100102c5

void Unwind_100102c5(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@100102f2 at 100102f2

void Unwind_100102f2(void)

{
  int unaff_EBP;
  
  FUN_1000cf09((undefined4 *)(unaff_EBP + -0x268));
  return;
}



// Function: Unwind@100102fd at 100102fd

void Unwind_100102fd(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x22c));
  return;
}



// Function: Unwind@10010330 at 10010330

void Unwind_10010330(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x22c));
  return;
}



// Function: FUN_10010411 at 10010411

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10010411(void)

{
  _DAT_10017c7c = ATL::CComModule::vftable;
  FUN_100035fc(0x10017c7c);
  return;
}



// Function: FUN_1001044a at 1001044a

void FUN_1001044a(void)

{
  FID_conflict__Tidy(&DAT_10017d04,'\x01',0);
  return;
}



// Function: FUN_10010459 at 10010459

void FUN_10010459(void)

{
  FID_conflict__Tidy(&DAT_10017ce8,'\x01',0);
  return;
}



// Function: FUN_10010468 at 10010468

void FUN_10010468(void)

{
  FID_conflict__Tidy(&DAT_10017ccc,'\x01',0);
  return;
}



// Function: FUN_10010477 at 10010477

void FUN_10010477(void)

{
  FID_conflict__Tidy(&DAT_10017d20,'\x01',0);
  return;
}



// Function: FUN_10010486 at 10010486

void FUN_10010486(void)

{
  FUN_1000d9e2((int *)&DAT_10017d3c);
  return;
}



// Function: FUN_10010490 at 10010490

void FUN_10010490(void)

{
  FUN_1000dac4(0x10017d64);
  return;
}



