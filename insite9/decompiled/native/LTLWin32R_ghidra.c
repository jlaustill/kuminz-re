/*
 * Decompiled from: LTLWin32R.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001000 at 10001000

undefined4 FUN_10001000(void)

{
  return 1;
}



// Function: LTLWIN_SetLanguageFile at 10001010

void LTLWIN_SetLanguageFile(undefined *param_1)

{
                    /* 0x1010  3  LTLWIN_SetLanguageFile */
  FUN_100026c0(param_1);
  return;
}



// Function: LTLWIN_GetText at 10001020

void LTLWIN_GetText(void)

{
                    /* 0x1020  1  LTLWIN_GetText */
  FUN_10002520();
  return;
}



// Function: FUN_10001050 at 10001050

void FUN_10001050(void)

{
  return;
}



// Function: FUN_10001060 at 10001060

exception * __thiscall
FUN_10001060(void *this,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_100033f5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  std::exception::exception((exception *)this);
  uStack_4 = 0;
  *(undefined ***)this = std::logic_error::vftable;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             ((int)this + 0xc),param_1);
  ExceptionList = local_c;
  return (exception *)this;
}



// Function: FUN_100010d0 at 100010d0

void __fastcall FUN_100010d0(exception *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_100033f5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)param_1 = std::logic_error::vftable;
  local_4 = 0;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (param_1 + 0xc));
  local_4 = 0xffffffff;
  std::exception::~exception(param_1);
  ExceptionList = local_c;
  return;
}



// Function: FUN_10001130 at 10001130

int __fastcall FUN_10001130(int param_1)

{
  if (0xf < *(uint *)(param_1 + 0x24)) {
    return *(int *)(param_1 + 0x10);
  }
  return param_1 + 0x10;
}



// Function: FUN_10001140 at 10001140

exception * __thiscall FUN_10001140(void *this,byte param_1)

{
  FUN_100010d0((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (exception *)this;
}



// Function: FUN_10001160 at 10001160

undefined4 * __thiscall
FUN_10001160(void *this,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_10003418;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_10001060(this,param_1);
  *(undefined ***)this = std::length_error::vftable;
  ExceptionList = local_c;
  return (undefined4 *)this;
}



// Function: FUN_100011c0 at 100011c0

void __fastcall FUN_100011c0(exception *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_10003448;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)param_1 = std::length_error::vftable;
  local_4 = 0xffffffff;
  FUN_100010d0(param_1);
  ExceptionList = local_c;
  return;
}



// Function: FUN_10001210 at 10001210

exception * __thiscall FUN_10001210(void *this,byte param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_10003418;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = std::length_error::vftable;
  local_4 = 0xffffffff;
  FUN_100010d0((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_c;
  return (exception *)this;
}



// Function: FUN_10001270 at 10001270

undefined4 * __thiscall
FUN_10001270(void *this,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_10003418;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_10001060(this,param_1);
  *(undefined ***)this = std::out_of_range::vftable;
  ExceptionList = local_c;
  return (undefined4 *)this;
}



// Function: FUN_100012d0 at 100012d0

void __fastcall FUN_100012d0(exception *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_10003448;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)param_1 = std::out_of_range::vftable;
  local_4 = 0xffffffff;
  FUN_100010d0(param_1);
  ExceptionList = local_c;
  return;
}



// Function: FUN_10001320 at 10001320

exception * __thiscall FUN_10001320(void *this,byte param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_10003418;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = std::out_of_range::vftable;
  local_4 = 0xffffffff;
  FUN_100010d0((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_c;
  return (exception *)this;
}



// Function: FUN_10001380 at 10001380

void __fastcall
FUN_10001380(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_10003479;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4 = 0xffffffff;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(param_1);
  ExceptionList = local_c;
  return;
}



// Function: FUN_100013d0 at 100013d0

void __fastcall FUN_100013d0(exception *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_100034d1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4._0_1_ = 1;
  local_4._1_3_ = 0;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (param_1 + 0x28));
  local_4 = (uint)local_4._1_3_ << 8;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (param_1 + 0xc));
  local_4 = 0xffffffff;
  std::exception::~exception(param_1);
  ExceptionList = local_c;
  return;
}



// Function: FUN_10001450 at 10001450

uint __cdecl FUN_10001450(long param_1)

{
  uint uStack_4;
  
  std::basic_istream<char,struct_std::char_traits<char>_>::seekg
            ((basic_istream<char,struct_std::char_traits<char>_> *)&DAT_10006110,param_1,0);
  std::basic_istream<char,struct_std::char_traits<char>_>::read
            ((basic_istream<char,struct_std::char_traits<char>_> *)&DAT_10006110,(char *)&uStack_4,4
            );
  return ((uStack_4 >> 8 & 0xff | (int)(char)uStack_4 << 8) << 8 | uStack_4 >> 0x10 & 0xff) << 8 |
         uStack_4 >> 0x18;
}



// Function: FUN_100014a0 at 100014a0

void __thiscall
FUN_100014a0(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4
            ,undefined1 param_5)

{
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 8) = param_3;
  *(undefined4 *)((int)this + 4) = param_2;
  *(undefined4 *)((int)this + 0xc) = *param_4;
  *(undefined4 *)((int)this + 0x10) = param_4[1];
  *(undefined4 *)((int)this + 0x14) = param_4[2];
  *(undefined1 *)((int)this + 0x18) = param_5;
  *(undefined1 *)((int)this + 0x19) = 0;
  return;
}



// Function: FUN_100014e0 at 100014e0

void __cdecl FUN_100014e0(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  cVar1 = *(char *)(iVar2 + 0x19);
  while (cVar1 == '\0') {
    iVar2 = *(int *)(iVar2 + 8);
    cVar1 = *(char *)(iVar2 + 0x19);
  }
  return;
}



// Function: FUN_10001500 at 10001500

void __cdecl FUN_10001500(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  cVar1 = *(char *)((int)piVar2 + 0x19);
  while (cVar1 == '\0') {
    piVar2 = (int *)*piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x19);
  }
  return;
}



// Function: FUN_10001520 at 10001520

undefined4 * __thiscall
FUN_10001520(void *this,char *param_1,undefined4 param_2,char *param_3,int param_4)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_10003598;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_100031c0(this,param_1,param_2,param_3,param_4);
  *(undefined ***)this = ltl::LTLException::vftable;
  ExceptionList = local_c;
  return (undefined4 *)this;
}



// Function: FUN_10001590 at 10001590

void __fastcall FUN_10001590(exception *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_100034f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4 = 0xffffffff;
  FUN_100013d0(param_1);
  ExceptionList = local_c;
  return;
}



// Function: FUN_100015e0 at 100015e0

exception * __thiscall FUN_100015e0(void *this,byte param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_10003598;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4 = 0xffffffff;
  FUN_100013d0((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_c;
  return (exception *)this;
}



// Function: FUN_10001640 at 10001640

void FUN_10001640(void)

{
  undefined4 local_5c;
  undefined1 auStack_58 [76];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_10003528;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_10003320(&local_5c,&DAT_10006108);
  local_4 = 0;
  if (DAT_100060f8 == '\0') {
    std::basic_ifstream<char,struct_std::char_traits<char>_>::open
              ((basic_ifstream<char,struct_std::char_traits<char>_> *)&DAT_10006110,
               PTR_s_language_dat_10006008,0x21,0x40);
    if (DAT_10006164 == 0) {
      FUN_10001520(auStack_58,"Unable to open file",0,".\\Translator.cpp",0x22);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(auStack_58,(ThrowInfo *)&DAT_10004674);
    }
    DAT_100060f8 = '\x01';
  }
  else {
    std::basic_ios<char,struct_std::char_traits<char>_>::clear
              ((basic_ios<char,struct_std::char_traits<char>_> *)
               ((int)&DAT_10006110 + *(int *)(DAT_10006110 + 4)),0,false);
    std::basic_istream<char,struct_std::char_traits<char>_>::seekg
              ((basic_istream<char,struct_std::char_traits<char>_> *)&DAT_10006110,0,0);
  }
  local_4 = 0xffffffff;
  FUN_10003340(&local_5c);
  ExceptionList = local_c;
  return;
}



// Function: FUN_10001720 at 10001720

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
FUN_10001720(void *this,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_10003799;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this,
             param_1);
  ExceptionList = local_c;
  return (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this;
}



// Function: FUN_10001770 at 10001770

exception * __thiscall FUN_10001770(void *this,exception *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_1000356f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  std::exception::exception((exception *)this,param_1);
  uStack_4 = 0;
  *(undefined ***)this = pcl_os::Exception::vftable;
  FUN_10001720((void *)((int)this + 0xc),
               (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (param_1 + 0xc));
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  FUN_10001720((void *)((int)this + 0x28),
               (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (param_1 + 0x28));
  *(undefined4 *)((int)this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)((int)this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  ExceptionList = local_c;
  return (exception *)this;
}



// Function: FUN_10001800 at 10001800

exception * __thiscall FUN_10001800(void *this,byte param_1)

{
  FUN_100013d0((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (exception *)this;
}



// Function: FUN_10001820 at 10001820

undefined4 * __thiscall FUN_10001820(void *this,exception *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_10003598;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_10001770(this,param_1);
  *(undefined ***)this = ltl::LTLException::vftable;
  ExceptionList = local_c;
  return (undefined4 *)this;
}



// Function: FUN_10001880 at 10001880

uint __cdecl FUN_10001880(uint param_1,uint param_2,uint param_3)

{
  uint in_EAX;
  uint uVar1;
  int iVar2;
  
  if (param_2 <= param_3) {
    do {
      uVar1 = param_2 + 8 + param_3 >> 1;
      iVar2 = uVar1 - (uVar1 - param_2 & 7);
      in_EAX = FUN_10001450(iVar2);
      if (param_1 == in_EAX) {
        return CONCAT31((int3)(in_EAX >> 8),1);
      }
      if (param_3 <= param_2) break;
      if (param_1 < in_EAX) {
        param_3 = iVar2 - 8;
      }
      else {
        param_2 = iVar2 + 8;
      }
    } while (param_2 <= param_3);
  }
  return in_EAX & 0xffffff00;
}



// Function: FUN_100018e0 at 100018e0

void __thiscall FUN_100018e0(void *this,int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x19) == '\0') {
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



// Function: FUN_10001930 at 10001930

void __thiscall FUN_10001930(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x19) == '\0') {
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



// Function: FUN_10001990 at 10001990

void __fastcall FUN_10001990(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if (*param_1 == 0) {
    _invalid_parameter_noinfo();
  }
  piVar2 = (int *)param_1[1];
  if (*(char *)((int)piVar2 + 0x19) == '\0') {
    iVar3 = *piVar2;
    if (*(char *)(iVar3 + 0x19) == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x19);
      iVar4 = *(int *)(iVar3 + 8);
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*(int *)(iVar4 + 8) + 0x19);
        iVar3 = iVar4;
        iVar4 = *(int *)(iVar4 + 8);
      }
      param_1[1] = iVar3;
      return;
    }
    piVar2 = (int *)piVar2[1];
    cVar1 = *(char *)((int)piVar2 + 0x19);
    while ((cVar1 == '\0' && (param_1[1] == *piVar2))) {
      param_1[1] = (int)piVar2;
      piVar2 = (int *)piVar2[1];
      cVar1 = *(char *)((int)piVar2 + 0x19);
    }
    if (*(char *)(param_1[1] + 0x19) == '\0') {
      param_1[1] = (int)piVar2;
      return;
    }
  }
  else {
    iVar3 = piVar2[2];
    param_1[1] = iVar3;
    if (*(char *)(iVar3 + 0x19) == '\0') {
      return;
    }
  }
  _invalid_parameter_noinfo();
  return;
}



// Function: FUN_10001a20 at 10001a20

void __fastcall FUN_10001a20(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  if (*param_1 == 0) {
    _invalid_parameter_noinfo();
  }
  iVar2 = param_1[1];
  if (*(char *)(iVar2 + 0x19) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x19) != '\0') {
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x19);
      while ((cVar1 == '\0' && (param_1[1] == *(int *)(iVar2 + 8)))) {
        param_1[1] = iVar2;
        iVar2 = *(int *)(iVar2 + 4);
        cVar1 = *(char *)(iVar2 + 0x19);
      }
      param_1[1] = iVar2;
      return;
    }
    cVar1 = *(char *)(*piVar3 + 0x19);
    piVar4 = (int *)*piVar3;
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*piVar4 + 0x19);
      piVar3 = piVar4;
      piVar4 = (int *)*piVar4;
    }
    param_1[1] = (int)piVar3;
    return;
  }
  _invalid_parameter_noinfo();
  return;
}



// Function: FUN_10001a90 at 10001a90

void FUN_10001a90(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x19);
  while (cVar1 == '\0') {
    FUN_10001a90((int *)param_1[2]);
    piVar2 = (int *)*param_1;
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x19);
  }
  return;
}



// Function: FUN_10001ad0 at 10001ad0

void * FUN_10001ad0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                   undefined1 param_5)

{
  void *this;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100035d1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this = operator_new(0x1c);
  local_8 = 1;
  if (this != (void *)0x0) {
    FUN_100014a0(this,param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return this;
}



// Function: Catch@10001b58 at 10001b58

void Catch_10001b58(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10001b70 at 10001b70

void FUN_10001b70(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100035f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)operator_new(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 6) = 1;
  *(undefined1 *)((int)puVar1 + 0x19) = 0;
  ExceptionList = local_10;
  return;
}



// Function: Catch@10001c02 at 10001c02

void Catch_10001c02(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10001c20 at 10001c20

void __thiscall
FUN_10001c20(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 *param_4)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];
  undefined1 auStack_34 [40];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_10003619;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(uint *)((int)this + 8) < 0x15555554) {
    piVar5 = (int *)FUN_10001ad0(*(undefined4 *)((int)this + 4),param_3,
                                 *(undefined4 *)((int)this + 4),param_4,0);
    *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
    if (param_3 == *(undefined4 **)((int)this + 4)) {
      (*(undefined4 **)((int)this + 4))[1] = piVar5;
      **(undefined4 **)((int)this + 4) = piVar5;
      *(int **)(*(int *)((int)this + 4) + 8) = piVar5;
    }
    else if (param_2 == '\0') {
      param_3[2] = piVar5;
      if (param_3 == *(undefined4 **)(*(int *)((int)this + 4) + 8)) {
        *(int **)(*(int *)((int)this + 4) + 8) = piVar5;
      }
    }
    else {
      *param_3 = piVar5;
      if (param_3 == (undefined4 *)**(int **)((int)this + 4)) {
        **(int **)((int)this + 4) = (int)piVar5;
      }
    }
    cVar1 = *(char *)(piVar5[1] + 0x18);
    piVar7 = piVar5;
    while (cVar1 == '\0') {
      piVar6 = piVar7 + 1;
      piVar2 = (int *)*piVar6;
      piVar3 = (int *)piVar2[1];
      if (piVar2 == (int *)*piVar3) {
        iVar4 = piVar3[2];
        if (*(char *)(iVar4 + 0x18) == '\0') {
          *(undefined1 *)(piVar2 + 6) = 1;
          *(undefined1 *)(iVar4 + 0x18) = 1;
          *(undefined1 *)(*(int *)(*piVar6 + 4) + 0x18) = 0;
          piVar7 = *(int **)(*piVar6 + 4);
        }
        else {
          if (piVar7 == (int *)piVar2[2]) {
            FUN_100018e0(this,(int)piVar2);
            piVar7 = piVar2;
          }
          *(undefined1 *)(piVar7[1] + 0x18) = 1;
          *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x18) = 0;
          FUN_10001930(this,*(int **)(piVar7[1] + 4));
        }
      }
      else {
        iVar4 = *piVar3;
        if (*(char *)(iVar4 + 0x18) == '\0') {
          *(undefined1 *)(piVar2 + 6) = 1;
          *(undefined1 *)(iVar4 + 0x18) = 1;
          *(undefined1 *)(*(int *)(*piVar6 + 4) + 0x18) = 0;
          piVar7 = *(int **)(*piVar6 + 4);
        }
        else {
          if (piVar7 == (int *)*piVar2) {
            FUN_10001930(this,piVar2);
            piVar7 = piVar2;
          }
          *(undefined1 *)(piVar7[1] + 0x18) = 1;
          *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x18) = 0;
          iVar4 = *(int *)(piVar7[1] + 4);
          piVar2 = *(int **)(iVar4 + 8);
          *(int *)(iVar4 + 8) = *piVar2;
          if (*(char *)(*piVar2 + 0x19) == '\0') {
            *(int *)(*piVar2 + 4) = iVar4;
          }
          piVar2[1] = *(int *)(iVar4 + 4);
          if (iVar4 == *(int *)(*(int *)((int)this + 4) + 4)) {
            *(int **)(*(int *)((int)this + 4) + 4) = piVar2;
          }
          else {
            piVar3 = *(int **)(iVar4 + 4);
            if (iVar4 == *piVar3) {
              *piVar3 = (int)piVar2;
            }
            else {
              piVar3[2] = (int)piVar2;
            }
          }
          *piVar2 = iVar4;
          *(int **)(iVar4 + 4) = piVar2;
        }
      }
      cVar1 = *(char *)(piVar7[1] + 0x18);
    }
    *(undefined1 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x18) = 1;
    param_1[1] = piVar5;
    *param_1 = this;
    ExceptionList = local_c;
    return;
  }
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            (local_50,"map/set<T> too long");
  uStack_4 = 0;
  FUN_10001160(auStack_34,local_50);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(auStack_34,(ThrowInfo *)&DAT_10004818);
}



// Function: FUN_10001e00 at 10001e00

exception * __thiscall FUN_10001e00(void *this,exception *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_10003655;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  std::exception::exception((exception *)this,param_1);
  uStack_4 = 0;
  *(undefined ***)this = std::logic_error::vftable;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             ((int)this + 0xc),
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (param_1 + 0xc));
  ExceptionList = local_c;
  return (exception *)this;
}



// Function: FUN_10001e70 at 10001e70

undefined4 * __thiscall FUN_10001e70(void *this,exception *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_10003418;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_10001e00(this,param_1);
  *(undefined ***)this = std::length_error::vftable;
  ExceptionList = local_c;
  return (undefined4 *)this;
}



// Function: FUN_10001ed0 at 10001ed0

void __thiscall FUN_10001ed0(void *this,int *param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];
  undefined1 auStack_34 [40];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  piVar2 = param_3;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_10003679;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(char *)((int)param_3 + 0x19) != '\0') {
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
              (local_50,"invalid map/set<T> iterator");
    uStack_4 = 0;
    FUN_10001270(auStack_34,local_50);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(auStack_34,(ThrowInfo *)&DAT_100048d0);
  }
  FUN_10001a20(&param_2);
  piVar5 = (int *)*piVar2;
  if (*(char *)((int)piVar5 + 0x19) == '\0') {
    piVar7 = piVar5;
    if ((*(char *)(piVar2[2] + 0x19) == '\0') && (piVar7 = (int *)param_3[2], param_3 != piVar2)) {
      piVar5[1] = (int)param_3;
      *param_3 = *piVar2;
      piVar5 = param_3;
      if (param_3 != (int *)piVar2[2]) {
        piVar5 = (int *)param_3[1];
        if (*(char *)((int)piVar7 + 0x19) == '\0') {
          piVar7[1] = (int)piVar5;
        }
        *piVar5 = (int)piVar7;
        param_3[2] = piVar2[2];
        *(int **)(piVar2[2] + 4) = param_3;
      }
      if (*(int **)(*(int *)((int)this + 4) + 4) == piVar2) {
        *(int **)(*(int *)((int)this + 4) + 4) = param_3;
      }
      else {
        piVar6 = (int *)piVar2[1];
        if ((int *)*piVar6 == piVar2) {
          *piVar6 = (int)param_3;
        }
        else {
          piVar6[2] = (int)param_3;
        }
      }
      param_3[1] = piVar2[1];
      iVar1 = param_3[6];
      *(char *)(param_3 + 6) = (char)piVar2[6];
      *(char *)(piVar2 + 6) = (char)iVar1;
      goto LAB_1000202d;
    }
  }
  else {
    piVar7 = (int *)piVar2[2];
  }
  piVar5 = (int *)piVar2[1];
  if (*(char *)((int)piVar7 + 0x19) == '\0') {
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
  piVar6 = *(int **)((int)this + 4);
  if ((int *)*piVar6 == piVar2) {
    piVar3 = piVar5;
    if (*(char *)((int)piVar7 + 0x19) == '\0') {
      piVar3 = (int *)FUN_10001500(piVar7);
    }
    *piVar6 = (int)piVar3;
  }
  iVar1 = *(int *)((int)this + 4);
  if (*(int **)(iVar1 + 8) == piVar2) {
    if (*(char *)((int)piVar7 + 0x19) == '\0') {
      uVar4 = FUN_100014e0((int)piVar7);
      *(undefined4 *)(iVar1 + 8) = uVar4;
    }
    else {
      *(int **)(iVar1 + 8) = piVar5;
    }
  }
LAB_1000202d:
  if ((char)piVar2[6] == '\x01') {
    if (piVar7 != *(int **)(*(int *)((int)this + 4) + 4)) {
      do {
        piVar6 = piVar5;
        if ((char)piVar7[6] != '\x01') break;
        piVar5 = (int *)*piVar6;
        if (piVar7 == piVar5) {
          piVar5 = (int *)piVar6[2];
          if ((char)piVar5[6] == '\0') {
            *(undefined1 *)(piVar5 + 6) = 1;
            *(undefined1 *)(piVar6 + 6) = 0;
            FUN_100018e0(this,(int)piVar6);
            piVar5 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar5 + 0x19) == '\0') {
            if ((*(char *)(*piVar5 + 0x18) != '\x01') || (*(char *)(piVar5[2] + 0x18) != '\x01')) {
              if (*(char *)(piVar5[2] + 0x18) == '\x01') {
                *(undefined1 *)(*piVar5 + 0x18) = 1;
                *(undefined1 *)(piVar5 + 6) = 0;
                FUN_10001930(this,piVar5);
                piVar5 = (int *)piVar6[2];
              }
              *(char *)(piVar5 + 6) = (char)piVar6[6];
              *(undefined1 *)(piVar6 + 6) = 1;
              *(undefined1 *)(piVar5[2] + 0x18) = 1;
              FUN_100018e0(this,(int)piVar6);
              break;
            }
LAB_100020ee:
            *(undefined1 *)(piVar5 + 6) = 0;
          }
        }
        else {
          if ((char)piVar5[6] == '\0') {
            *(undefined1 *)(piVar5 + 6) = 1;
            *(undefined1 *)(piVar6 + 6) = 0;
            FUN_10001930(this,piVar6);
            piVar5 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar5 + 0x19) == '\0') {
            if ((*(char *)(piVar5[2] + 0x18) == '\x01') && (*(char *)(*piVar5 + 0x18) == '\x01'))
            goto LAB_100020ee;
            if (*(char *)(*piVar5 + 0x18) == '\x01') {
              *(undefined1 *)(piVar5[2] + 0x18) = 1;
              *(undefined1 *)(piVar5 + 6) = 0;
              FUN_100018e0(this,(int)piVar5);
              piVar5 = (int *)*piVar6;
            }
            *(char *)(piVar5 + 6) = (char)piVar6[6];
            *(undefined1 *)(piVar6 + 6) = 1;
            *(undefined1 *)(*piVar5 + 0x18) = 1;
            FUN_10001930(this,piVar6);
            break;
          }
        }
        piVar5 = (int *)piVar6[1];
        piVar7 = piVar6;
      } while (piVar6 != *(int **)(*(int *)((int)this + 4) + 4));
    }
    *(undefined1 *)(piVar7 + 6) = 1;
  }
  operator_delete(piVar2);
  if (*(int *)((int)this + 8) != 0) {
    *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
  }
  *param_1 = param_2;
  param_1[1] = (int)param_3;
  ExceptionList = local_c;
  return;
}



// Function: FUN_10002180 at 10002180

undefined4 * __thiscall FUN_10002180(void *this,exception *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_10003418;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_10001e00(this,param_1);
  *(undefined ***)this = std::out_of_range::vftable;
  ExceptionList = local_c;
  return (undefined4 *)this;
}



// Function: FUN_100021e0 at 100021e0

void __thiscall FUN_100021e0(void *this,undefined4 *param_1,uint *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  bool local_c;
  void *local_8;
  undefined4 *local_4;
  
  puVar3 = *(undefined4 **)((int)this + 4);
  local_c = true;
  if (*(char *)((int)puVar3[1] + 0x19) == '\0') {
    puVar2 = (undefined4 *)puVar3[1];
    do {
      puVar3 = puVar2;
      local_c = *param_2 < (uint)puVar3[3];
      if (local_c) {
        puVar2 = (undefined4 *)*puVar3;
      }
      else {
        puVar2 = (undefined4 *)puVar3[2];
      }
    } while (*(char *)((int)puVar2 + 0x19) == '\0');
  }
  local_8 = this;
  local_4 = puVar3;
  if (local_c) {
    if (puVar3 == (undefined4 *)**(int **)((int)this + 4)) {
      local_c = true;
      goto LAB_1000223c;
    }
    FUN_10001990((int *)&local_8);
  }
  if (*param_2 <= (uint)local_4[3]) {
    *param_1 = local_8;
    param_1[1] = local_4;
    *(undefined1 *)(param_1 + 2) = 0;
    return;
  }
LAB_1000223c:
  puVar3 = (undefined4 *)FUN_10001c20(this,&local_8,local_c,puVar3,param_2);
  uVar1 = puVar3[1];
  *param_1 = *puVar3;
  param_1[1] = uVar1;
  *(undefined1 *)(param_1 + 2) = 1;
  return;
}



// Function: FUN_100022a0 at 100022a0

void __thiscall FUN_100022a0(void *this,int *param_1,uint *param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void **ppvVar4;
  void *local_10;
  undefined4 *local_c;
  void *local_8;
  undefined4 *local_4;
  
  local_c = *(undefined4 **)((int)this + 4);
  if (*(char *)((int)local_c[1] + 0x19) == '\0') {
    puVar2 = (undefined4 *)local_c[1];
    do {
      if ((uint)puVar2[3] < *param_2) {
        puVar3 = (undefined4 *)puVar2[2];
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
        local_c = puVar2;
      }
      puVar2 = puVar3;
    } while (*(char *)((int)puVar3 + 0x19) == '\0');
  }
  local_10 = this;
  if ((local_c == *(undefined4 **)((int)this + 4)) || (*param_2 < (uint)local_c[3])) {
    local_8 = this;
    local_4 = *(undefined4 **)((int)this + 4);
    ppvVar4 = &local_8;
  }
  else {
    ppvVar4 = &local_10;
  }
  pvVar1 = ppvVar4[1];
  *param_1 = (int)*ppvVar4;
  param_1[1] = (int)pvVar1;
  return;
}



// Function: FUN_10002310 at 10002310

void __thiscall
FUN_10002310(void *this,undefined4 *param_1,void *param_2,int *param_3,void *param_4,int *param_5)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  void *pvVar4;
  int aiStack_8 [2];
  
  pvVar4 = param_2;
  piVar1 = (int *)**(int **)((int)this + 4);
  if ((param_2 == (void *)0x0) || (param_2 != this)) {
    _invalid_parameter_noinfo();
  }
  piVar3 = param_3;
  if (param_3 == piVar1) {
    piVar1 = *(int **)((int)this + 4);
    if ((param_4 == (void *)0x0) || (param_4 != this)) {
      _invalid_parameter_noinfo();
    }
    if (param_5 == piVar1) {
      FUN_10001a90(*(int **)(*(int *)((int)this + 4) + 4));
      *(int *)(*(int *)((int)this + 4) + 4) = *(int *)((int)this + 4);
      *(undefined4 *)((int)this + 8) = 0;
      *(undefined4 *)*(undefined4 *)((int)this + 4) = *(undefined4 *)((int)this + 4);
      *(int *)(*(int *)((int)this + 4) + 8) = *(int *)((int)this + 4);
      uVar2 = **(undefined4 **)((int)this + 4);
      *param_1 = this;
      param_1[1] = uVar2;
      return;
    }
  }
  while( true ) {
    if ((pvVar4 == (void *)0x0) || (pvVar4 != param_4)) {
      _invalid_parameter_noinfo();
    }
    if (piVar3 == param_5) break;
    FUN_10001a20((int *)&param_2);
    FUN_10001ed0(this,aiStack_8,(int)pvVar4,piVar3);
    piVar3 = param_3;
    pvVar4 = param_2;
  }
  *param_1 = pvVar4;
  param_1[1] = piVar3;
  return;
}



// Function: FUN_100023e0 at 100023e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100023e0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined *puVar5;
  int iVar6;
  undefined4 local_18;
  undefined *puStack_14;
  int iStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_100036a8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_10003320(&local_18,&DAT_10006108);
  local_4 = 0;
  if (DAT_100060f8 == '\x01') {
    std::basic_ifstream<char,struct_std::char_traits<char>_>::close
              ((basic_ifstream<char,struct_std::char_traits<char>_> *)&DAT_10006110);
    iStack_10 = *DAT_10006100;
    puStack_14 = &DAT_100060fc;
    while( true ) {
      iVar6 = iStack_10;
      puVar5 = puStack_14;
      iVar2 = *DAT_10006100;
      if ((puStack_14 == (undefined *)0x0) || (puStack_14 != &DAT_100060fc)) {
        _invalid_parameter_noinfo();
      }
      if (iVar6 == iVar2) break;
      if (puVar5 == (undefined *)0x0) {
        _invalid_parameter_noinfo();
      }
      if (iVar6 == *(int *)(puVar5 + 4)) {
        _invalid_parameter_noinfo();
      }
      operator_delete(*(void **)(iVar6 + 0x10));
      FUN_10001a20((int *)&puStack_14);
    }
    cVar1 = *(char *)(DAT_10006100[1] + 0x19);
    piVar4 = (int *)DAT_10006100[1];
    while (cVar1 == '\0') {
      FUN_10001a90((int *)piVar4[2]);
      piVar3 = (int *)*piVar4;
      operator_delete(piVar4);
      piVar4 = piVar3;
      cVar1 = *(char *)((int)piVar3 + 0x19);
    }
    DAT_10006100[1] = (int)DAT_10006100;
    _DAT_10006104 = 0;
    *DAT_10006100 = (int)DAT_10006100;
    DAT_10006100[2] = (int)DAT_10006100;
    DAT_100060f8 = '\0';
  }
  local_4 = 0xffffffff;
  FUN_10003340(&local_18);
  ExceptionList = local_c;
  return;
}



// Function: FUN_10002520 at 10002520

char * FUN_10002520(void)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  char *_Size;
  char *pcVar7;
  uint local_34;
  char *local_30;
  char *local_2c;
  char *local_20;
  void *pvStack_1c;
  undefined4 uStack_14;
  void *local_c;
  undefined4 *puStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = (undefined4 *)&LAB_100036d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_10003320(&local_34,&DAT_10006108);
  pcVar7 = (char *)0x0;
  local_4 = 0;
  FUN_10001640();
  _Size = (char *)0x0;
  FUN_100022a0(&DAT_100060fc,(int *)&local_30,(uint *)&stack0x00000004);
  pcVar1 = local_30;
  local_20 = DAT_10006100;
  if ((local_30 == (char *)0x0) || (local_30 != &DAT_100060fc)) {
    _invalid_parameter_noinfo();
  }
  pcVar2 = local_2c;
  if (local_2c == local_20) {
    piVar4 = (int *)std::basic_istream<char,struct_std::char_traits<char>_>::tellg
                              ((basic_istream<char,struct_std::char_traits<char>_> *)&DAT_10006110);
    uVar5 = FUN_10001450(piVar4[2] + *piVar4);
    piVar4 = (int *)std::basic_istream<char,struct_std::char_traits<char>_>::tellg
                              ((basic_istream<char,struct_std::char_traits<char>_> *)&DAT_10006110);
    uVar3 = local_4;
    uVar6 = FUN_10001880(local_4,piVar4[2] + *piVar4,uVar5 * 8 - 4);
    if ((char)uVar6 != '\0') {
      piVar4 = (int *)std::basic_istream<char,struct_std::char_traits<char>_>::tellg
                                ((basic_istream<char,struct_std::char_traits<char>_> *)&DAT_10006110
                                );
      uVar5 = FUN_10001450(piVar4[2] + *piVar4);
      std::basic_istream<char,struct_std::char_traits<char>_>::seekg
                ((basic_istream<char,struct_std::char_traits<char>_> *)&DAT_10006110,uVar5,0);
      piVar4 = (int *)std::basic_istream<char,struct_std::char_traits<char>_>::tellg
                                ((basic_istream<char,struct_std::char_traits<char>_> *)&DAT_10006110
                                );
      _Size = (char *)FUN_10001450(piVar4[2] + *piVar4);
      pcVar7 = (char *)malloc((size_t)_Size);
      std::basic_istream<char,struct_std::char_traits<char>_>::read
                ((basic_istream<char,struct_std::char_traits<char>_> *)&DAT_10006110,pcVar7,
                 (int)_Size);
      local_34 = uVar3;
      local_30 = pcVar7;
      local_2c = _Size;
      FUN_100021e0(&DAT_100060fc,(undefined4 *)&stack0xffffffc0,&local_34);
    }
  }
  else {
    if (pcVar1 == (char *)0x0) {
      _invalid_parameter_noinfo();
    }
    if (pcVar2 == *(char **)(pcVar1 + 4)) {
      _invalid_parameter_noinfo();
    }
    pcVar7 = *(char **)(pcVar2 + 0x10);
    _Size = *(char **)(pcVar2 + 0x14);
  }
  *puStack_8 = _Size;
  uStack_14 = 0xffffffff;
  FUN_10003340((undefined4 *)&stack0xffffffbc);
  ExceptionList = pvStack_1c;
  return pcVar7;
}



// Function: FUN_100026c0 at 100026c0

void __cdecl FUN_100026c0(undefined *param_1)

{
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_10003708;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_10003320(&local_10,&DAT_10006108);
  local_4 = 0;
  FUN_100023e0();
  PTR_s_language_dat_10006008 = param_1;
  FUN_10001640();
  local_4 = 0xffffffff;
  FUN_10003340(&local_10);
  ExceptionList = local_c;
  return;
}



// Function: FUN_10002730 at 10002730

void __fastcall FUN_10002730(void *param_1)

{
  undefined4 local_8 [2];
  
  FUN_10002310(param_1,local_8,param_1,(int *)**(int **)((int)param_1 + 4),param_1,
               *(int **)((int)param_1 + 4));
  operator_delete(*(void **)((int)param_1 + 4));
  *(undefined4 *)((int)param_1 + 4) = 0;
  *(undefined4 *)((int)param_1 + 8) = 0;
  return;
}



// Function: FUN_10002770 at 10002770

void __fastcall FUN_10002770(void *param_1)

{
  void *local_14 [2];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_10003738;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4 = 0xffffffff;
  local_14[0] = param_1;
  FUN_10002310(param_1,local_14,param_1,(int *)**(int **)((int)param_1 + 4),param_1,
               *(int **)((int)param_1 + 4));
  operator_delete(*(void **)((int)param_1 + 4));
  *(undefined4 *)((int)param_1 + 4) = 0;
  *(undefined4 *)((int)param_1 + 8) = 0;
  ExceptionList = local_c;
  return;
}



// Function: FUN_100027e0 at 100027e0

int __fastcall FUN_100027e0(int param_1)

{
  int iVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_10003768;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar1 = FUN_10001b70();
  *(int *)(param_1 + 4) = iVar1;
  *(undefined1 *)(iVar1 + 0x19) = 1;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(undefined4 *)*(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 8) = 0;
  ExceptionList = local_c;
  return param_1;
}



// Function: FUN_10002894 at 10002894

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10002894(undefined4 param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  void *Exchange;
  void *pvVar2;
  int iVar3;
  BOOL BVar4;
  LONG LVar5;
  int *_Memory;
  int *piVar6;
  int iVar7;
  code *pcVar8;
  
  Exchange = StackBase;
  if (param_2 == 0) {
    if (DAT_1000619c < 1) {
      return 0;
    }
    DAT_1000619c = DAT_1000619c + -1;
  }
  _DAT_100064d4 = *(undefined4 *)_adjust_fdiv_exref;
  if (param_2 == 1) {
    bVar1 = false;
    while (pvVar2 = (void *)InterlockedCompareExchange((LONG *)&DAT_100064dc,(LONG)Exchange,0),
          pvVar2 != (void *)0x0) {
      if (pvVar2 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_100064d8 == 0) {
      DAT_100064d8 = 1;
      iVar3 = initterm_e(&DAT_10004114,&DAT_1000411c);
      if (iVar3 != 0) {
        return 0;
      }
      initterm(&DAT_10004100,&DAT_10004110);
      DAT_100064d8 = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_100064dc,0);
    }
    if ((DAT_100064e8 != (code *)0x0) &&
       (BVar4 = __IsNonwritableInCurrentImage((PBYTE)&DAT_100064e8), BVar4 != 0)) {
      (*DAT_100064e8)(param_1,2,param_3);
    }
    DAT_1000619c = DAT_1000619c + 1;
  }
  else if (param_2 == 0) {
    while (LVar5 = InterlockedCompareExchange((LONG *)&DAT_100064dc,1,0), LVar5 != 0) {
      Sleep(1000);
    }
    if (DAT_100064d8 == 2) {
      _Memory = (int *)decode_pointer(DAT_100064e4);
      if (_Memory != (int *)0x0) {
        piVar6 = (int *)decode_pointer(DAT_100064e0);
        while (piVar6 = piVar6 + -1, _Memory <= piVar6) {
          if (*piVar6 != 0) {
            iVar3 = *piVar6;
            iVar7 = encoded_null();
            if (iVar3 != iVar7) {
              pcVar8 = (code *)decode_pointer(iVar3);
              (*pcVar8)();
            }
          }
        }
        free(_Memory);
        DAT_100064e0 = encoded_null();
        DAT_100064e4 = DAT_100064e0;
      }
      DAT_100064d8 = 0;
      InterlockedExchange((LONG *)&DAT_100064dc,0);
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 10002a57

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x10002af7) */
/* WARNING: Removing unreachable block (ram,0x10002aa4) */
/* WARNING: Removing unreachable block (ram,0x10002b24) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2005 Release */

int __fastcall ___DllMainCRTStartup(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_100060e8 = param_2;
  if ((param_2 == 0) && (DAT_1000619c == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != 1) && (param_2 != 2)) ||
          (local_20 = FUN_10002894(param_3,param_2,param_1), local_20 != 0)) {
    local_20 = FUN_10001000();
    if ((param_2 == 1) && (local_20 == 0)) {
      FUN_10001000();
      FUN_10002894(param_3,0,param_1);
    }
    if (((param_2 == 0) || (param_2 == 3)) &&
       (iVar1 = FUN_10002894(param_3,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_10002b62();
  return local_20;
}



// Function: FUN_10002b62 at 10002b62

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10002b62(void)

{
  _DAT_100060e8 = 0xffffffff;
  return;
}



// Function: entry at 10002b6d

void entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: __security_check_cookie at 10002b94

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_100060c8) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: FID_conflict:`vector_deleting_destructor' at 10002ba3

/* Library Function - Multiple Matches With Different Base Names
    public: virtual void * __thiscall exception::`vector deleting destructor'(unsigned int)
    public: virtual void * __thiscall std::exception::`vector deleting destructor'(unsigned int)
    public: virtual void * __thiscall logic_error::`vector deleting destructor'(unsigned int)
    public: virtual void * __thiscall type_info::`vector deleting destructor'(unsigned int)
   
   Library: Visual Studio 2005 Release */

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



// Function: FUN_10002c04 at 10002c04

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

_onexit_t __cdecl FUN_10002c04(_onexit_t param_1)

{
  _onexit_t p_Var1;
  undefined4 uVar2;
  undefined4 local_24;
  int local_20 [5];
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_10004a40;
  uStack_c = 0x10002c10;
  local_20[0] = decode_pointer(DAT_100064e4);
  if (local_20[0] == -1) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = decode_pointer(DAT_100064e4);
    local_24 = decode_pointer(DAT_100064e0);
    uVar2 = _encode_pointer(param_1,local_20,&local_24);
    p_Var1 = (_onexit_t)__dllonexit(uVar2);
    DAT_100064e4 = _encode_pointer(local_20[0]);
    DAT_100064e0 = _encode_pointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_10002ca0();
  }
  return p_Var1;
}



// Function: FUN_10002ca0 at 10002ca0

void FUN_10002ca0(void)

{
  _unlock(8);
  return;
}



// Function: FUN_10002ca9 at 10002ca9

int __cdecl FUN_10002ca9(_onexit_t param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = FUN_10002c04(param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: __ValidateImageBase at 10002d10

/* Library Function - Single Match
    __ValidateImageBase
   
   Library: Visual Studio 2005 Release */

BOOL __cdecl __ValidateImageBase(PBYTE pImageBase)

{
  if ((*(short *)pImageBase == 0x5a4d) &&
     (*(int *)(pImageBase + *(int *)(pImageBase + 0x3c)) == 0x4550)) {
    return (uint)((short)*(int *)((int)(pImageBase + *(int *)(pImageBase + 0x3c)) + 0x18) == 0x10b);
  }
  return 0;
}



// Function: __FindPESection at 10002d40

/* Library Function - Single Match
    __FindPESection
   
   Library: Visual Studio 2005 Release */

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



// Function: __IsNonwritableInCurrentImage at 10002d90

/* Library Function - Single Match
    __IsNonwritableInCurrentImage
   
   Library: Visual Studio */

BOOL __cdecl __IsNonwritableInCurrentImage(PBYTE pTarget)

{
  BOOL BVar1;
  PIMAGE_SECTION_HEADER p_Var2;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  undefined4 local_8;
  
  puStack_10 = &LAB_10002ebd;
  local_14 = ExceptionList;
  local_c = DAT_100060c8 ^ 0x10004a60;
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



// Function: __SEH_prolog4 at 10002e64

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_100060c8 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 10002ea9

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



// Function: ___security_init_cookie at 10002ee0

/* Library Function - Single Match
    ___security_init_cookie
   
   Library: Visual Studio 2005 Release */

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
  if ((DAT_100060c8 == 0xbb40e64e) || ((DAT_100060c8 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_100060c8 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_100060c8 == 0xbb40e64e) {
      DAT_100060c8 = 0xbb40e64f;
    }
    else if ((DAT_100060c8 & 0xffff0000) == 0) {
      DAT_100060c8 = DAT_100060c8 | DAT_100060c8 << 0x10;
    }
    DAT_100060cc = ~DAT_100060c8;
  }
  else {
    DAT_100060cc = ~DAT_100060c8;
  }
  return;
}



// Function: ___report_gsfailure at 10002f74

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
  
  _DAT_100062c8 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_100062cc = &stack0x00000004;
  _DAT_10006208 = 0x10001;
  _DAT_100061b0 = 0xc0000409;
  _DAT_100061b4 = 1;
  local_32c = DAT_100060c8;
  local_328 = DAT_100060cc;
  _DAT_100061bc = unaff_retaddr;
  _DAT_10006294 = in_GS;
  _DAT_10006298 = in_FS;
  _DAT_1000629c = in_ES;
  _DAT_100062a0 = in_DS;
  _DAT_100062a4 = unaff_EDI;
  _DAT_100062a8 = unaff_ESI;
  _DAT_100062ac = unaff_EBX;
  _DAT_100062b0 = in_EDX;
  _DAT_100062b4 = in_ECX;
  _DAT_100062b8 = in_EAX;
  _DAT_100062bc = unaff_EBP;
  DAT_100062c0 = unaff_retaddr;
  _DAT_100062c4 = in_CS;
  _DAT_100062d0 = in_SS;
  DAT_10006200 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_100041fc);
  if (DAT_10006200 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __ArrayUnwind at 10003078

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



// Function: `eh_vector_destructor_iterator' at 100030d6

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    void __stdcall `eh vector destructor iterator'(void *,unsigned int,int,void (__thiscall*)(void
   *))
   
   Library: Visual Studio 2005 Release */

void _eh_vector_destructor_iterator_
               (void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4)

{
  void *in_stack_ffffffd0;
  
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*param_4)(in_stack_ffffffd0);
  }
  FUN_10003121();
  return;
}



// Function: FUN_10003121 at 10003121

void FUN_10003121(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: FUN_10003170 at 10003170

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
FUN_10003170(void *this,char *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_10003799;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this,
             param_1);
  ExceptionList = local_c;
  return (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this;
}



// Function: FUN_100031c0 at 100031c0

void __thiscall FUN_100031c0(void *this,char *param_1,int param_2,char *param_3,int param_4)

{
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this_00;
  char *pcVar1;
  char *local_3c;
  void *local_38;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbStack_34;
  char acStack_30 [32];
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_100037e8;
  local_c = ExceptionList;
  local_10 = DAT_100060c8 ^ (uint)&local_3c;
  ExceptionList = &local_c;
  local_3c = param_1;
  local_38 = this;
  std::exception::exception((exception *)this,&local_3c);
  uStack_4 = 0;
  this_00 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
            ((int)this + 0xc);
  *(undefined ***)this = pcl_os::Exception::vftable;
  pbStack_34 = this_00;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(this_00,"");
  uStack_4._0_1_ = 2;
  FUN_10003170((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               ((int)this + 0x28),param_3);
  uStack_4 = CONCAT31(uStack_4._1_3_,3);
  *(int *)((int)this + 0x44) = param_4;
  *(int *)((int)this + 0x48) = param_2;
  if (param_4 != 0) {
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append
              (this_00,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)((int)this + 0x28));
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append
              (this_00,", L:");
    sprintf(acStack_30,"%u",param_4);
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append
              (this_00,acStack_30);
  }
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append
            (this_00," E:");
  sprintf(acStack_30,"%u",param_2);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append
            (this_00,acStack_30);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append
            (this_00," - ");
  pcVar1 = std::exception::what((exception *)this);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append
            (this_00,pcVar1);
  uStack_4 = 0xffffffff;
  ExceptionList = local_c;
  __security_check_cookie(local_10 ^ (uint)&local_3c);
  return;
}



// Function: FUN_10003310 at 10003310

void __fastcall FUN_10003310(int param_1)

{
  FUN_100033d0(param_1 + 0xc);
  return;
}



// Function: FUN_10003320 at 10003320

undefined4 * __thiscall FUN_10003320(void *this,undefined4 *param_1)

{
  *(undefined4 **)this = param_1;
  if (param_1 != (undefined4 *)0x0) {
    FUN_10003390(param_1);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003340 at 10003340

void __fastcall FUN_10003340(undefined4 *param_1)

{
  if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
    FUN_100033a0((undefined4 *)*param_1);
  }
  *param_1 = 0;
  return;
}



// Function: FUN_10003360 at 10003360

undefined4 * __fastcall FUN_10003360(undefined4 *param_1)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,(LPCWSTR)0x0);
  *param_1 = pvVar1;
  return param_1;
}



// Function: FUN_10003390 at 10003390

void __fastcall FUN_10003390(undefined4 *param_1)

{
  WaitForSingleObject((HANDLE)*param_1,0xffffffff);
  return;
}



// Function: FUN_100033a0 at 100033a0

void __fastcall FUN_100033a0(undefined4 *param_1)

{
  ReleaseMutex((HANDLE)*param_1);
  return;
}



// Function: FUN_100033d0 at 100033d0

int __fastcall FUN_100033d0(int param_1)

{
  if (0xf < *(uint *)(param_1 + 0x18)) {
    return *(int *)(param_1 + 4);
  }
  return param_1 + 4;
}



// Function: Unwind@100033e0 at 100033e0

void Unwind_100033e0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100033e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100033e9 at 100033e9

void Unwind_100033e9(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100033ef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@10003410 at 10003410

void Unwind_10003410(void)

{
  int unaff_EBP;
  
  FUN_100010d0(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10003440 at 10003440

void Unwind_10003440(void)

{
  int unaff_EBP;
  
  FUN_100010d0(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10003470 at 10003470

void Unwind_10003470(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10003473. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            (*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
              (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100034a0 at 100034a0

void Unwind_100034a0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100034a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100034a9 at 100034a9

void Unwind_100034a9(void)

{
  int unaff_EBP;
  
  FUN_10001380((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0xc));
  return;
}



// Function: Unwind@100034b4 at 100034b4

void Unwind_100034b4(void)

{
  int unaff_EBP;
  
  FUN_10001380((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0x28));
  return;
}



// Function: Unwind@100034bf at 100034bf

void Unwind_100034bf(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100034c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            (*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
              (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100034c8 at 100034c8

void Unwind_100034c8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100034cb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            (*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
              (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100034f0 at 100034f0

void Unwind_100034f0(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10003520 at 10003520

void Unwind_10003520(void)

{
  int unaff_EBP;
  
  FUN_10003340((undefined4 *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@10003550 at 10003550

void Unwind_10003550(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10003553. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10003559 at 10003559

void Unwind_10003559(void)

{
  int unaff_EBP;
  
  FUN_10001380((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@10003564 at 10003564

void Unwind_10003564(void)

{
  int unaff_EBP;
  
  FUN_10001380((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@10003590 at 10003590

void Unwind_10003590(void)

{
  int unaff_EBP;
  
  FUN_100013d0(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100035c0 at 100035c0

void Unwind_100035c0(void)

{
  FUN_10001050();
  return;
}



// Function: Unwind@10003610 at 10003610

void Unwind_10003610(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10003613. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10003640 at 10003640

void Unwind_10003640(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10003643. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10003649 at 10003649

void Unwind_10003649(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000364f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@10003670 at 10003670

void Unwind_10003670(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10003673. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (unaff_EBP + -0x50));
  return;
}



// Function: Unwind@100036a0 at 100036a0

void Unwind_100036a0(void)

{
  int unaff_EBP;
  
  FUN_10003340((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100036d0 at 100036d0

void Unwind_100036d0(void)

{
  int unaff_EBP;
  
  FUN_10003340((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10003700 at 10003700

void Unwind_10003700(void)

{
  int unaff_EBP;
  
  FUN_10003340((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10003730 at 10003730

void Unwind_10003730(void)

{
  int unaff_EBP;
  
  FUN_10002730(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10003760 at 10003760

void Unwind_10003760(void)

{
  int unaff_EBP;
  
  FUN_10002730(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10003790 at 10003790

void Unwind_10003790(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10003793. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            (*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
              (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100037c0 at 100037c0

void Unwind_100037c0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100037c3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@100037c9 at 100037c9

void Unwind_100037c9(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100037cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            (*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
              (unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100037d2 at 100037d2

void Unwind_100037d2(void)

{
  int unaff_EBP;
  
  FUN_10001380((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (*(int *)(unaff_EBP + -0x38) + 0xc));
  return;
}



// Function: Unwind@100037dd at 100037dd

void Unwind_100037dd(void)

{
  int unaff_EBP;
  
  FUN_10001380((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (*(int *)(unaff_EBP + -0x38) + 0x28));
  return;
}



