/*
 * Decompiled from: TraceDebug.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001000 at 10001000

int __fastcall FUN_10001000(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001256b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002780((undefined4 *)(param_1 + 0xc));
  local_8 = 0;
  FUN_10002c20(param_1);
  FUN_100029d0(param_1 + 4);
  FUN_100029f0(param_1 + 8);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001070 at 10001070

void __fastcall FUN_10001070(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012591;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  ~_ExceptionPtr_static<>(param_1 + 0xc);
  ExceptionList = local_10;
  return;
}



// Function: CLogger_LogTraceMessage at 100010c0

undefined4 CLogger_LogTraceMessage(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint local_8;
  
  local_8 = 0;
  while( true ) {
    if (1 < local_8) {
      return 1;
    }
    iVar1 = FUN_100035a0((int *)(&PTR_DAT_1001b0b8)[local_8],param_2);
    if (iVar1 != 0) break;
    local_8 = local_8 + 1;
  }
  return 0;
}



// Function: CLogger_LogTraceMessage at 10001110

void CLogger_LogTraceMessage(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  uint uStack_44;
  undefined1 local_18 [4];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100125b4;
  local_10 = ExceptionList;
  uStack_44 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_44;
  ExceptionList = &local_10;
  FUN_1000e1f0(local_18,0);
  local_8 = 0;
  if (DAT_1001b678 != 0) {
    iVar1 = (**(code **)(*param_1 + 0x20))(param_1,param_2,0,0x80000000,param_3,param_4,param_5);
    FUN_1000e660(local_18,iVar1);
  }
  CLogger_LogMessage();
  return;
}



// Function: Catch@10001189 at 10001189

undefined * Catch_10001189(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_100033a0();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x20),"Logger.cpp",0xa5,"CLogger::LogTraceMessage",
                       *puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x1c) = uVar2;
  return &DAT_10001259;
}



// Function: Catch@100011d5 at 100011d5

undefined * Catch_100011d5(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x30),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_100033a0();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x30),"Logger.cpp",0xa5,"CLogger::LogTraceMessage",
                       *puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x10001236;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return &DAT_1000124b;
}



// Function: CLogger_LogMessage at 10001242

void CLogger_LogMessage(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1000e780((undefined4 *)(unaff_EBP + -0x14));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: CLogger_LogMessage at 10001290

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void CLogger_LogMessage(int param_1,undefined4 param_2,int param_3,uint param_4,undefined4 param_5,
                 undefined4 param_6)

{
  uint *puVar1;
  bool bVar2;
  size_t sVar3;
  int iVar4;
  undefined4 uStack_8c;
  uint uStack_84;
  int local_60 [3];
  undefined4 local_54;
  undefined1 *local_50;
  int *local_4c;
  undefined4 local_48 [3];
  int *local_3c;
  undefined1 local_38 [4];
  LPSTR local_34;
  int *local_30;
  int *local_2c;
  LPSTR local_28;
  wchar_t *local_24;
  int local_20;
  undefined4 local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100125ef;
  local_10 = ExceptionList;
  uStack_84 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_84;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_84;
  puVar1 = &uStack_84;
  if (DAT_1001b678 != 0) {
    uStack_8c = 0x100012dd;
    FUN_1000e1f0(local_38,0);
    uStack_8c = 0x100012ec;
    FUN_100029a0(local_60,param_1 + -4);
    local_8._0_1_ = 1;
    FUN_10002b00(&local_1c);
    local_8._0_1_ = 2;
    local_54 = FUN_10003510();
    uStack_8c = 0x10001310;
    bVar2 = FUN_100030d0(&DAT_1001b684,0);
    if (((bVar2) && (DAT_1001b67c <= param_3)) && ((DAT_1001b680 & param_4) != 0)) {
      uStack_8c = param_6;
      local_4c = (int *)CLogger_FormXMLMessageBlock(local_48,param_2,param_3,param_4,param_5);
      local_8._0_1_ = 3;
      local_3c = local_4c;
      FUN_10003030(&local_1c,local_4c);
      local_8._0_1_ = 2;
      FUN_10002e50(local_48);
      local_24 = (wchar_t *)FUN_10003120(&local_1c);
      if (local_24 == (wchar_t *)0x0) {
        local_34 = (LPSTR)0x0;
      }
      else {
        sVar3 = wcslen(local_24);
        local_20 = sVar3 + 1;
        if (local_20 < 0x40000000) {
          iVar4 = local_20 * -2;
          local_50 = (undefined1 *)&uStack_8c;
          local_14 = (undefined1 *)&uStack_8c;
          *(undefined4 *)(&stack0xffffff70 + iVar4) = local_54;
          *(int *)(&stack0xffffff6c + iVar4) = local_20 << 1;
          *(wchar_t **)(&stack0xffffff68 + iVar4) = local_24;
          *(undefined1 **)(&stack0xffffff64 + iVar4) = local_50;
          *(undefined4 *)(&stack0xffffff60 + iVar4) = 0x100013ea;
          local_28 = FUN_10003300(*(LPSTR *)(&stack0xffffff64 + iVar4),
                                  *(LPCWSTR *)(&stack0xffffff68 + iVar4),
                                  *(int *)(&stack0xffffff6c + iVar4),
                                  *(UINT *)(&stack0xffffff70 + iVar4));
        }
        else {
          local_28 = (LPSTR)0x0;
        }
        local_34 = local_28;
      }
      local_2c = (int *)FUN_10003130((undefined4 *)&DAT_1001b684);
      FUN_10003120(&local_1c);
      Ordinal_7();
      iVar4 = (**(code **)(*local_2c + 0x10))();
      FUN_1000e660(local_38,iVar4);
      local_30 = (int *)FUN_10003130((undefined4 *)&DAT_1001b684);
      iVar4 = (**(code **)(*local_30 + 0x20))(local_30,0);
      uStack_8c = 0x10001455;
      FUN_1000e660(local_38,iVar4);
    }
    local_8._0_1_ = 1;
    FUN_10002e50(&local_1c);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_10002de0(local_60);
    puVar1 = (uint *)local_14;
  }
  local_14 = (undefined1 *)puVar1;
  CLogger_put_Enabled();
  return;
}



// Function: Catch@10001472 at 10001472

undefined * Catch_10001472(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_100033a0();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x60),"Logger.cpp",0xc6,"CLogger::LogMessage",*puVar1
                       ,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x40) = uVar2;
  return &DAT_10001542;
}



// Function: Catch@100014be at 100014be

undefined * Catch_100014be(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x70),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  puVar1 = (undefined8 *)FUN_100033a0();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x70),"Logger.cpp",0xc6,"CLogger::LogMessage",*puVar1,
                       puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x3c) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 4;
  uStack0000001c = 0x1000151f;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x70));
  return &DAT_10001534;
}



// Function: CLogger_put_Enabled at 1000152b

/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void CLogger_put_Enabled(void)

{
  uint uVar1;
  uint unaff_EBP;
  
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uVar1 = *(uint *)(unaff_EBP - 0x14);
  *(undefined4 *)(unaff_EBP - 0x74) = 0x1000156b;
  __security_check_cookie(uVar1 ^ unaff_EBP);
  return;
}



// Function: CLogger_put_Enabled at 10001580

void CLogger_put_Enabled(int param_1,undefined4 param_2)

{
  uint uStack_48;
  int local_28 [5];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_10012624;
  local_10 = ExceptionList;
  uStack_48 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_48;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_100029a0(local_28,param_1 + -8);
  DAT_1001b678 = param_2;
  local_8 = local_8 & 0xffffff00;
  FUN_10002de0(local_28);
  CLogger_get_Enabled();
  return;
}



// Function: Catch@100015e0 at 100015e0

undefined * Catch_100015e0(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_100033a0();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x1c),"Logger.cpp",0x96,"CLogger::put_Enabled",
                       *puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
  return &DAT_100016b0;
}



// Function: Catch@1000162c at 1000162c

undefined * Catch_1000162c(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x34),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  puVar1 = (undefined8 *)FUN_100033a0();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x34),"Logger.cpp",0x96,"CLogger::put_Enabled",*puVar1,
                       puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uStack0000001c = 0x1000168d;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return &DAT_100016a2;
}



// Function: CLogger_get_Enabled at 10001699

undefined4 CLogger_get_Enabled(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: CLogger_get_Enabled at 100016e0

void CLogger_get_Enabled(int param_1,undefined4 *param_2)

{
  uint uStack_48;
  int local_28 [5];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001264f;
  local_10 = ExceptionList;
  uStack_48 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_48;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_100029a0(local_28,param_1 + -8);
  local_8._0_1_ = 1;
  if (param_2 == (undefined4 *)0x0) {
    assertFailure((uchar *)"Logger.cpp");
  }
  *param_2 = DAT_1001b678;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10002de0(local_28);
  CLogger_put_Level();
  return;
}



// Function: Catch@10001769 at 10001769

undefined * Catch_10001769(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_100033a0();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x1c),"Logger.cpp",0xd9,"CLogger::get_Enabled",
                       *puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
  return &DAT_10001839;
}



// Function: Catch@100017b5 at 100017b5

undefined * Catch_100017b5(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x34),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  puVar1 = (undefined8 *)FUN_100033a0();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x34),"Logger.cpp",0xd9,"CLogger::get_Enabled",*puVar1,
                       puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uStack0000001c = 0x10001816;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return &DAT_1000182b;
}



// Function: CLogger_put_Level at 10001822

undefined4 CLogger_put_Level(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: CLogger_put_Level at 10001860

void CLogger_put_Level(int param_1,short param_2)

{
  uint *puVar1;
  uint uStack_48;
  int local_28 [5];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001267a;
  local_10 = ExceptionList;
  uStack_48 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_48;
  ExceptionList = &local_10;
  local_8 = 0;
  if (((param_2 == 0) || (param_2 == 1)) || (puVar1 = &uStack_48, param_2 == 2)) {
    FUN_100029a0(local_28,param_1 + -8);
    DAT_1001b67c = (int)param_2;
    local_8 = local_8 & 0xffffff00;
    FUN_10002de0(local_28);
    puVar1 = (uint *)local_14;
  }
  local_14 = (undefined1 *)puVar1;
  CLogger_get_Level();
  return;
}



// Function: Catch@100018db at 100018db

undefined * Catch_100018db(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_100033a0();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x1c),"Logger.cpp",0xe8,"CLogger::put_Level",*puVar1,
                       puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
  return &DAT_100019ab;
}



// Function: Catch@10001927 at 10001927

undefined * Catch_10001927(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x34),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  puVar1 = (undefined8 *)FUN_100033a0();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x34),"Logger.cpp",0xe8,"CLogger::put_Level",*puVar1,
                       puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uStack0000001c = 0x10001988;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return &DAT_1000199d;
}



// Function: CLogger_get_Level at 10001994

undefined4 CLogger_get_Level(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: CLogger_get_Level at 100019d0

void CLogger_get_Level(int param_1,undefined2 *param_2)

{
  uint uStack_48;
  int local_28 [5];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100126a5;
  local_10 = ExceptionList;
  uStack_48 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_48;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_100029a0(local_28,param_1 + -8);
  local_8._0_1_ = 1;
  if (param_2 == (undefined2 *)0x0) {
    assertFailure((uchar *)"Logger.cpp");
  }
  *param_2 = (undefined2)DAT_1001b67c;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10002de0(local_28);
  CLogger_put_Categories();
  return;
}



// Function: Catch@10001a5b at 10001a5b

undefined * Catch_10001a5b(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_100033a0();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x1c),"Logger.cpp",0xfb,"CLogger::get_Level",*puVar1,
                       puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
  return &DAT_10001b2b;
}



// Function: Catch@10001aa7 at 10001aa7

undefined * Catch_10001aa7(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x34),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  puVar1 = (undefined8 *)FUN_100033a0();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x34),"Logger.cpp",0xfb,"CLogger::get_Level",*puVar1,
                       puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uStack0000001c = 0x10001b08;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return &DAT_10001b1d;
}



// Function: CLogger_put_Categories at 10001b14

undefined4 CLogger_put_Categories(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: CLogger_put_Categories at 10001b50

void CLogger_put_Categories(int param_1,undefined4 param_2)

{
  uint uStack_48;
  int local_28 [5];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_100126d0;
  local_10 = ExceptionList;
  uStack_48 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_48;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_100029a0(local_28,param_1 + -8);
  DAT_1001b680 = param_2;
  local_8 = local_8 & 0xffffff00;
  FUN_10002de0(local_28);
  CLogger_get_Categories();
  return;
}



// Function: Catch@10001bb0 at 10001bb0

undefined * Catch_10001bb0(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_100033a0();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x1c),"Logger.cpp",0x107,"CLogger::put_Categories",
                       *puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
  return &DAT_10001c80;
}



// Function: Catch@10001bfc at 10001bfc

undefined * Catch_10001bfc(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x34),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  puVar1 = (undefined8 *)FUN_100033a0();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x34),"Logger.cpp",0x107,"CLogger::put_Categories",
                       *puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uStack0000001c = 0x10001c5d;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return &DAT_10001c72;
}



// Function: CLogger_get_Categories at 10001c69

undefined4 CLogger_get_Categories(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: CLogger_get_Categories at 10001cb0

void CLogger_get_Categories(int param_1,undefined4 *param_2)

{
  uint uStack_48;
  int local_28 [5];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100126fb;
  local_10 = ExceptionList;
  uStack_48 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_48;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_100029a0(local_28,param_1 + -8);
  local_8._0_1_ = 1;
  if (param_2 == (undefined4 *)0x0) {
    assertFailure((uchar *)"Logger.cpp");
  }
  *param_2 = DAT_1001b680;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10002de0(local_28);
  CLogger_SetStream();
  return;
}



// Function: Catch@10001d39 at 10001d39

undefined * Catch_10001d39(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_100033a0();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x1c),"Logger.cpp",0x11a,"CLogger::get_Categories",
                       *puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
  return &DAT_10001e09;
}



// Function: Catch@10001d85 at 10001d85

undefined * Catch_10001d85(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x34),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  puVar1 = (undefined8 *)FUN_100033a0();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x34),"Logger.cpp",0x11a,"CLogger::get_Categories",
                       *puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uStack0000001c = 0x10001de6;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return &DAT_10001dfb;
}



// Function: CLogger_SetStream at 10001df2

undefined4 CLogger_SetStream(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: CLogger_SetStream at 10001e30

void CLogger_SetStream(int param_1,int param_2)

{
  uint uStack_48;
  int local_28 [5];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10012726;
  local_10 = ExceptionList;
  uStack_48 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_48;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_100029a0(local_28,param_1 + -8);
  local_8._0_1_ = 1;
  FUN_10002fa0(&DAT_1001b684,param_2);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10002de0(local_28);
  CLogger_FormXMLMessageBlock();
  return;
}



// Function: Catch@10001e95 at 10001e95

undefined * Catch_10001e95(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_100033a0();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x1c),"Logger.cpp",0x127,"CLogger::SetStream",*puVar1
                       ,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
  return &DAT_10001f65;
}



// Function: Catch@10001ee1 at 10001ee1

undefined * Catch_10001ee1(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x34),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  puVar1 = (undefined8 *)FUN_100033a0();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x34),"Logger.cpp",0x127,"CLogger::SetStream",*puVar1,
                       puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uStack0000001c = 0x10001f42;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return &DAT_10001f57;
}



// Function: CLogger_FormXMLMessageBlock at 10001f4e

undefined4 CLogger_FormXMLMessageBlock(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: CLogger_FormXMLMessageBlock at 10001f90

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Removing unreachable block (ram,0x1000223c) */
/* WARNING: Removing unreachable block (ram,0x100023ae) */
/* WARNING: Removing unreachable block (ram,0x10002010) */
/* WARNING: Removing unreachable block (ram,0x100022f5) */
/* WARNING: Removing unreachable block (ram,0x10002183) */

void CLogger_FormXMLMessageBlock(undefined4 param_1,undefined4 param_2,int param_3,uint param_4,undefined4 param_5)

{
  longlong lVar1;
  UINT UVar2;
  int iVar3;
  int iVar4;
  wchar_t *pwVar5;
  size_t sVar6;
  float10 fVar7;
  undefined4 uStack_b44;
  uint uStack_b3c;
  uint local_ac0;
  CComBSTR local_abc [4];
  wchar_t *local_ab8;
  CComBSTR local_ab4 [4];
  int local_ab0;
  char *local_aac;
  _SYSTEMTIME local_aa8;
  wchar_t local_a98 [1344];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012781;
  local_10 = ExceptionList;
  uStack_b3c = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_b3c;
  ExceptionList = &local_10;
  uStack_b44 = 0x10001fe3;
  local_18 = uStack_b3c;
  ATL::CComBSTR::CComBSTR(local_abc,(wchar_t *)PTR_u_<msg>_1001b008);
  local_8 = 1;
  local_ab8 = (wchar_t *)0x0;
  local_a98[0] = L'\0';
  UVar2 = FUN_10003510();
  local_8._0_1_ = 2;
  FUN_10002b00((undefined4 *)local_ab4);
  local_8 = CONCAT31(local_8._1_3_,3);
  uStack_b44 = 0x1000204e;
  iVar3 = Ordinal_7();
  uStack_b44 = param_5;
  iVar4 = Ordinal_7();
  lVar1 = (ulonglong)(uint)(iVar3 + 0xc0 + iVar4) * 2;
  local_ab8 = (wchar_t *)operator_new__(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1)
  ;
  if (local_ab8 != (wchar_t *)0x0) {
    GetLocalTime(&local_aa8);
    FUN_10003560(local_ab8,(size_t)PTR_u_<text>_s<_text>_<thread>_lu<_thr_1001b010);
    pwVar5 = (wchar_t *)FUN_10003500(local_ab8);
    ATL::CComBSTR::Attach(local_ab4,pwVar5);
    FUN_10003140(local_abc,(undefined4 *)local_ab4);
    ATL::CComBSTR::Empty(local_ab4);
    if (param_3 == 0) {
      local_aac = "CILowLevel";
      sVar6 = strlen("CILowLevel");
      local_ab0 = sVar6 + 1;
      if (local_ab0 < 0x40000000) {
        local_14 = (undefined1 *)&uStack_b44;
        FUN_10003280((LPWSTR)&uStack_b44,local_aac,local_ab0,UVar2);
      }
      FUN_10003560(local_ab8,(size_t)PTR_u_<level>_s<_level>_1001b000);
    }
    else if (param_3 == 1) {
      local_aac = "CIMediumLevel";
      sVar6 = strlen("CIMediumLevel");
      local_ab0 = sVar6 + 1;
      if (local_ab0 < 0x40000000) {
        local_14 = (undefined1 *)&uStack_b44;
        FUN_10003280((LPWSTR)&uStack_b44,local_aac,local_ab0,UVar2);
      }
      FUN_10003560(local_ab8,(size_t)PTR_u_<level>_s<_level>_1001b000);
    }
    else if (param_3 == 2) {
      local_aac = "CIHighLevel";
      sVar6 = strlen("CIHighLevel");
      local_ab0 = sVar6 + 1;
      if (local_ab0 < 0x40000000) {
        local_14 = (undefined1 *)&uStack_b44;
        FUN_10003280((LPWSTR)&uStack_b44,local_aac,local_ab0,UVar2);
      }
      FUN_10003560(local_ab8,(size_t)PTR_u_<level>_s<_level>_1001b000);
    }
    else {
      local_aac = "CILowLevel";
      sVar6 = strlen("CILowLevel");
      local_ab0 = sVar6 + 1;
      if (local_ab0 < 0x40000000) {
        local_14 = (undefined1 *)&uStack_b44;
        FUN_10003280((LPWSTR)&uStack_b44,local_aac,local_ab0,UVar2);
      }
      FUN_10003560(local_ab8,(size_t)PTR_u_<level>_s<_level>_1001b000);
    }
    pwVar5 = (wchar_t *)FUN_10003500(local_ab8);
    ATL::CComBSTR::Attach(local_ab4,pwVar5);
    FUN_10003140(local_abc,(undefined4 *)local_ab4);
    ATL::CComBSTR::Empty(local_ab4);
    for (local_ac0 = 0; (int)local_ac0 < 0x20; local_ac0 = local_ac0 + 1) {
      fVar7 = (float10)FUN_10003540(2.0,local_ac0);
      if (((int)fVar7 & param_4) != 0) {
        FUN_10003560(local_ab8,(size_t)PTR_u_<category>_s<_category>_1001b004);
        wcscat(local_a98,local_ab8);
      }
    }
    pwVar5 = (wchar_t *)FUN_10003500(local_a98);
    ATL::CComBSTR::Attach(local_ab4,pwVar5);
    FUN_10003140(local_abc,(undefined4 *)local_ab4);
    ATL::CComBSTR::Empty(local_ab4);
    pwVar5 = (wchar_t *)FUN_10003500(PTR_u_<_msg>_1001b00c);
    ATL::CComBSTR::Attach(local_ab4,pwVar5);
    FUN_10003140(local_abc,(undefined4 *)local_ab4);
    ATL::CComBSTR::Empty(local_ab4);
    operator_delete__(local_ab8);
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_10002e50((undefined4 *)local_ab4);
  FUN_1000267e();
  return;
}



// Function: Catch@100025bf at 100025bf

undefined * Catch_100025bf(void)

{
  int unaff_EBP;
  
  throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0xb18),"Logger.cpp",0x180,"CLogger::FormXMLMessageBlock",
               0x11d4f07fbb51df37,0x13c599290600b394);
  return &DAT_10002692;
}



// Function: Catch@1000260b at 1000260b

undefined * Catch_1000260b(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0xb28),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  throwExceptionWithFileInfo((void *)(unaff_EBP + -0xb28),"Logger.cpp",0x180,"CLogger::FormXMLMessageBlock",
               0x11d4f07fbb51df37,0x13c599290600b394);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  uStack0000001c = 0x10002678;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0xb28));
  return &DAT_10002687;
}



// Function: FUN_1000267e at 1000267e

/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000267e(void)

{
  uint uVar1;
  uint unaff_EBP;
  
  *(undefined4 *)(unaff_EBP - 4) = 1;
  std::_Timevec::operator=(*(_Timevec **)(unaff_EBP + 8),(_Timevec *)(unaff_EBP - 0xab8));
  *(uint *)(unaff_EBP - 0xadc) = *(uint *)(unaff_EBP - 0xadc) | 1;
  *(undefined1 *)(unaff_EBP - 4) = 0;
  FUN_10002e50((undefined4 *)(unaff_EBP - 0xab8));
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uVar1 = *(uint *)(unaff_EBP - 0x14);
  *(undefined4 *)(unaff_EBP - 0xb2c) = 0x100026e7;
  __security_check_cookie(uVar1 ^ unaff_EBP);
  return;
}



// Function: FUN_100026f0 at 100026f0

float10 __cdecl FUN_100026f0(double param_1,uint param_2)

{
  undefined8 local_18;
  undefined8 local_10;
  undefined4 local_8;
  
  if ((int)param_2 < 0) {
    local_8 = -param_2;
  }
  else {
    local_8 = param_2;
  }
  local_10 = 1.0;
  while( true ) {
    if ((local_8 & 1) != 0) {
      local_10 = local_10 * param_1;
    }
    local_8 = local_8 >> 1;
    if (local_8 == 0) break;
    param_1 = param_1 * param_1;
  }
  if ((int)param_2 < 0) {
    local_18 = 1.0 / local_10;
  }
  else {
    local_18 = local_10;
  }
  return (float10)local_18;
}



// Function: FUN_10002780 at 10002780

undefined4 * __fastcall FUN_10002780(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100127c3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002b40(param_1);
  local_8 = 0;
  FUN_10002a30((CComCriticalSection *)(param_1 + 1));
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100027e0 at 100027e0

void * __thiscall FUN_100027e0(void *this,int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100127e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  CComPtrBase<>(this,param_1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10002840 at 10002840

undefined4 * __fastcall FUN_10002840(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012818;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100028d0(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: CComPtrBase<> at 10002890

/* Library Function - Multiple Matches With Same Base Name
    protected: __thiscall ATL::CComPtrBase<struct IShellItem>::CComPtrBase<struct IShellItem>(struct
   IShellItem *)
    protected: __thiscall ATL::CComPtrBase<struct IUnknown>::CComPtrBase<struct IUnknown>(struct
   IUnknown *)
    protected: __thiscall ATL::CComPtrBase<struct IXMLDOMNode>::CComPtrBase<struct
   IXMLDOMNode>(struct IXMLDOMNode *)
    protected: __thiscall ATL::CComPtrBase<struct IXMLDOMNodeList>::CComPtrBase<struct
   IXMLDOMNodeList>(struct IXMLDOMNodeList *)
   
   Library: Visual Studio 2010 Debug */

int * __thiscall CComPtrBase<>(void *this,int param_1)

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



// Function: FUN_100028d0 at 100028d0

undefined4 * __fastcall FUN_100028d0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_100028f0 at 100028f0

void * __thiscall FUN_100028f0(void *this,int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012848;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100027e0(this,param_1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10002950 at 10002950

undefined4 * __fastcall FUN_10002950(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012878;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002840(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100029a0 at 100029a0

int * __thiscall FUN_100029a0(void *this,int param_1)

{
  *(int *)this = param_1;
  *(undefined1 *)((int)this + 4) = 0;
  FUN_100033d0((int *)this);
  return (int *)this;
}



// Function: FUN_100029d0 at 100029d0

undefined4 __fastcall FUN_100029d0(undefined4 param_1)

{
  FUN_10002bc0(param_1);
  return param_1;
}



// Function: FUN_100029f0 at 100029f0

undefined4 __fastcall FUN_100029f0(undefined4 param_1)

{
  FUN_10002be0(param_1);
  return param_1;
}



// Function: FUN_10002a10 at 10002a10

undefined4 * __thiscall FUN_10002a10(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return (undefined4 *)this;
}



// Function: FUN_10002a30 at 10002a30

CComCriticalSection * __fastcall FUN_10002a30(CComCriticalSection *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100128a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002b60(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: operator= at 10002a80

/* Library Function - Single Match
    public: class std::_Timevec & __thiscall std::_Timevec::operator=(class std::_Timevec const &)
   
   Library: Visual Studio */

_Timevec * __thiscall std::_Timevec::operator=(_Timevec *this,_Timevec *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)param_1 = 0;
  return this;
}



// Function: CComBSTR at 10002ab0

/* Library Function - Single Match
    public: __thiscall ATL::CComBSTR::CComBSTR(wchar_t const *)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

CComBSTR * __thiscall ATL::CComBSTR::CComBSTR(CComBSTR *this,wchar_t *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
  if (param_1 == (wchar_t *)0x0) {
    *(undefined4 *)this = 0;
  }
  else {
    uVar2 = Ordinal_2(param_1);
    *(undefined4 *)this = uVar2;
    bVar1 = FUN_10003070((int *)this);
    if (bVar1) {
      FUN_100032d0(0x8007000e);
    }
  }
  return this;
}



// Function: FUN_10002b00 at 10002b00

undefined4 * __fastcall FUN_10002b00(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: CComCriticalSection at 10002b20

/* Library Function - Single Match
    public: __thiscall ATL::CComCriticalSection::CComCriticalSection(void)
   
   Library: Visual Studio */

CComCriticalSection * __thiscall
ATL::CComCriticalSection::CComCriticalSection(CComCriticalSection *this)

{
  memset(this,0,0x18);
  return this;
}



// Function: FUN_10002b40 at 10002b40

undefined4 * __fastcall FUN_10002b40(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10002b60 at 10002b60

CComCriticalSection * __fastcall FUN_10002b60(CComCriticalSection *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100128d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  ATL::CComCriticalSection::CComCriticalSection(param_1);
  param_1[0x18] = (CComCriticalSection)0x0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10002bc0 at 10002bc0

undefined4 __fastcall FUN_10002bc0(undefined4 param_1)

{
  FUN_10002c00(param_1);
  return param_1;
}



// Function: FUN_10002be0 at 10002be0

undefined4 __fastcall FUN_10002be0(undefined4 param_1)

{
  FUN_10002c00(param_1);
  return param_1;
}



// Function: FUN_10002c00 at 10002c00

undefined4 __fastcall FUN_10002c00(undefined4 param_1)

{
  FUN_10002c40(param_1);
  return param_1;
}



// Function: FUN_10002c20 at 10002c20

undefined4 __fastcall FUN_10002c20(undefined4 param_1)

{
  FUN_10002c40(param_1);
  return param_1;
}



// Function: FUN_10002c40 at 10002c40

undefined4 __fastcall FUN_10002c40(undefined4 param_1)

{
  return param_1;
}



// Function: _com_error at 10002c50

/* Library Function - Single Match
    public: __thiscall _com_error::_com_error(long,struct IErrorInfo *,bool)
   
   Library: Visual Studio 2005 Debug */

_com_error * __thiscall
_com_error::_com_error(_com_error *this,long param_1,IErrorInfo *param_2,bool param_3)

{
  *(undefined ***)this = vftable;
  *(long *)(this + 4) = param_1;
  *(IErrorInfo **)(this + 8) = param_2;
  *(undefined4 *)(this + 0xc) = 0;
  if ((*(int *)(this + 8) != 0) && (param_3)) {
    (**(code **)(**(int **)(this + 8) + 4))(*(undefined4 *)(this + 8));
  }
  return this;
}



// Function: ~_ExceptionPtr_static<> at 10002cb0

/* Library Function - Multiple Matches With Same Base Name
    public: virtual __thiscall `anonymous namespace'::_ExceptionPtr_static<class
   std::bad_alloc>::~_ExceptionPtr_static<class std::bad_alloc>(void)
    public: virtual __thiscall `anonymous namespace'::_ExceptionPtr_static<class
   std::bad_exception>::~_ExceptionPtr_static<class std::bad_exception>(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall ~_ExceptionPtr_static<>(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012913;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FID_conflict__bad_alloc((LPCRITICAL_SECTION)(param_1 + 4));
  local_8 = 0xffffffff;
  FUN_10002e80();
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~bad_alloc at 10002d10

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012938;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10002d60(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002d60 at 10002d60

void __fastcall FUN_10002d60(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FID_conflict:~bad_alloc at 10002d90

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012968;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FID_conflict__bad_alloc(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002de0 at 10002de0

void __fastcall FUN_10002de0(int *param_1)

{
  FUN_100034b0(param_1);
  return;
}



// Function: FID_conflict:~bad_alloc at 10002e00

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012998;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10002e90(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002e50 at 10002e50

void __fastcall FUN_10002e50(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FUN_10002e70 at 10002e70

void FUN_10002e70(void)

{
  return;
}



// Function: FUN_10002e80 at 10002e80

void FUN_10002e80(void)

{
  return;
}



// Function: FUN_10002e90 at 10002e90

void __fastcall FUN_10002e90(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100129c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    FUN_10003470(param_1);
  }
  local_8 = 0xffffffff;
  FUN_10002e70();
  ExceptionList = local_10;
  return;
}



// Function: ~_com_error at 10002f00

/* Library Function - Single Match
    public: virtual __thiscall _com_error::~_com_error(void)
   
   Library: Visual Studio 2005 Debug */

void __thiscall _com_error::~_com_error(_com_error *this)

{
  *(undefined ***)this = vftable;
  if (*(int *)(this + 8) != 0) {
    (**(code **)(**(int **)(this + 8) + 8))(*(undefined4 *)(this + 8));
  }
  if (*(int *)(this + 0xc) != 0) {
    LocalFree(*(HLOCAL *)(this + 0xc));
  }
  return;
}



// Function: FID_conflict:~bad_alloc at 10002f50

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100129f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10002e50(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002fa0 at 10002fa0

void __thiscall FUN_10002fa0(void *this,int param_1)

{
  bool bVar1;
  List<struct_Concurrency::details::ListEntry,class_Concurrency::details::CollectionTypes::NoCount>
  *pLVar2;
  int local_20;
  List<struct_Concurrency::details::ListEntry,class_Concurrency::details::CollectionTypes::NoCount>
  *local_1c;
  List<struct_Concurrency::details::ListEntry,class_Concurrency::details::CollectionTypes::NoCount>
  *local_18;
  List<struct_Concurrency::details::ListEntry,class_Concurrency::details::CollectionTypes::NoCount>
  *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012a28;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (List<struct_Concurrency::details::ListEntry,class_Concurrency::details::CollectionTypes::NoCount>
              *)this;
  bVar1 = FUN_100030d0(this,param_1);
  if (bVar1) {
    pLVar2 = local_14;
    local_1c = (List<struct_Concurrency::details::ListEntry,class_Concurrency::details::CollectionTypes::NoCount>
                *)FUN_100028f0(&local_20,param_1);
    local_8 = 0;
    local_18 = local_1c;
    Concurrency::details::
    List<struct_Concurrency::details::ListEntry,class_Concurrency::details::CollectionTypes::NoCount>
    ::Swap(local_1c,pLVar2);
    local_8 = 0xffffffff;
    FID_conflict__bad_alloc(&local_20);
  }
  FUN_10003110((undefined4 *)local_14);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003030 at 10003030

int * __thiscall FUN_10003030(void *this,int *param_1)

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



// Function: FUN_10003070 at 10003070

bool __fastcall FUN_10003070(int *param_1)

{
  return *param_1 == 0;
}



// Function: FUN_100030a0 at 100030a0

bool __thiscall FUN_100030a0(void *this,int param_1)

{
                    /* WARNING: Load size is inaccurate */
  return *this == param_1;
}



// Function: FUN_100030d0 at 100030d0

bool __thiscall FUN_100030d0(void *this,int param_1)

{
  bool local_8;
  
  local_8 = FUN_100030a0(this,param_1);
  local_8 = !local_8;
  return local_8;
}



// Function: FUN_10003110 at 10003110

undefined4 __fastcall FUN_10003110(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003120 at 10003120

undefined4 __fastcall FUN_10003120(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003130 at 10003130

undefined4 __fastcall FUN_10003130(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003140 at 10003140

void * __thiscall FUN_10003140(void *this,undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_10003220(*param_1);
  if (iVar1 < 0) {
    FUN_100032d0(iVar1);
  }
  return this;
}



// Function: FID_conflict:`vector_deleting_destructor' at 10003180

/* Library Function - Multiple Matches With Different Base Names
    public: void * __thiscall Concurrency::details::GlobalCore::`vector deleting
   destructor'(unsigned int)
    public: void * __thiscall Concurrency::location::`vector deleting destructor'(unsigned int)
   
   Library: Visual Studio 2012 Release */

undefined4 * __thiscall FID_conflict__vector_deleting_destructor_(void *this,uint param_1)

{
  if ((param_1 & 2) == 0) {
    FID_conflict__bad_alloc((undefined4 *)this);
    if ((param_1 & 1) != 0) {
      operator_delete(this);
    }
  }
  else {
    _eh_vector_destructor_iterator_(this,0xc,*(int *)((int)this + -4),FID_conflict__bad_alloc);
    if ((param_1 & 1) != 0) {
      operator_delete__((void *)((int)this + -4));
    }
    this = (void *)((int)this + -4);
  }
  return (undefined4 *)this;
}



// Function: FUN_100031f0 at 100031f0

_com_error * __thiscall FUN_100031f0(void *this,uint param_1)

{
  _com_error::~_com_error((_com_error *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (_com_error *)this;
}



// Function: FUN_10003220 at 10003220

int FUN_10003220(undefined4 param_1)

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



// Function: FUN_10003280 at 10003280

LPWSTR FUN_10003280(LPWSTR param_1,LPCSTR param_2,int param_3,UINT param_4)

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



// Function: FUN_100032d0 at 100032d0

void FUN_100032d0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined1 local_c [4];
  undefined4 local_8;
  
  puVar1 = FUN_10002a10(local_c,param_1);
  local_8 = *puVar1;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_8,(ThrowInfo *)&DAT_10018760);
}



// Function: FUN_10003300 at 10003300

LPSTR FUN_10003300(LPSTR param_1,LPCWSTR param_2,int param_3,UINT param_4)

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



// Function: Attach at 10003350

/* Library Function - Single Match
    public: void __thiscall ATL::CComBSTR::Attach(wchar_t *)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __thiscall ATL::CComBSTR::Attach(CComBSTR *this,wchar_t *param_1)

{
  if (*(wchar_t **)this != param_1) {
    Ordinal_6(*(undefined4 *)this);
    *(wchar_t **)this = param_1;
  }
  return;
}



// Function: Empty at 10003380

/* Library Function - Single Match
    public: void __thiscall ATL::CComBSTR::Empty(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __thiscall ATL::CComBSTR::Empty(CComBSTR *this)

{
  Ordinal_6(*(undefined4 *)this);
  *(undefined4 *)this = 0;
  return;
}



// Function: FUN_100033a0 at 100033a0

undefined * FUN_100033a0(void)

{
  return &DAT_100150f0;
}



// Function: FUN_100033b0 at 100033b0

void __fastcall FUN_100033b0(int param_1)

{
  FUN_10003420((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FUN_100033d0 at 100033d0

void __fastcall FUN_100033d0(int *param_1)

{
  if ((char)param_1[1] == '\0') {
    FUN_100033b0(*param_1 + 0xc);
    *(undefined1 *)(param_1 + 1) = 1;
  }
  return;
}



// Function: FUN_10003400 at 10003400

undefined4 __fastcall FUN_10003400(LPCRITICAL_SECTION param_1)

{
  EnterCriticalSection(param_1);
  return 0;
}



// Function: FUN_10003420 at 10003420

void __fastcall FUN_10003420(LPCRITICAL_SECTION param_1)

{
  FUN_10003400(param_1);
  return;
}



// Function: Swap at 10003440

/* Library Function - Single Match
    public: void __thiscall Concurrency::details::List<struct Concurrency::details::ListEntry,class
   Concurrency::details::CollectionTypes::NoCount>::Swap(class Concurrency::details::List<struct
   Concurrency::details::ListEntry,class Concurrency::details::CollectionTypes::NoCount> *)
   
   Library: Visual Studio 2012 Debug */

void __thiscall
Concurrency::details::
List<struct_Concurrency::details::ListEntry,class_Concurrency::details::CollectionTypes::NoCount>::
Swap(List<struct_Concurrency::details::ListEntry,class_Concurrency::details::CollectionTypes::NoCount>
     *this,List<struct_Concurrency::details::ListEntry,class_Concurrency::details::CollectionTypes::NoCount>
           *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)this;
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)param_1 = uVar1;
  return;
}



// Function: FUN_10003470 at 10003470

undefined4 __fastcall FUN_10003470(LPCRITICAL_SECTION param_1)

{
  DeleteCriticalSection(param_1);
  return 0;
}



// Function: FUN_10003490 at 10003490

void __fastcall FUN_10003490(int param_1)

{
  FUN_100034e0((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FUN_100034b0 at 100034b0

void __fastcall FUN_100034b0(int *param_1)

{
  if ((char)param_1[1] != '\0') {
    FUN_10003490(*param_1 + 0xc);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_100034e0 at 100034e0

undefined4 __fastcall FUN_100034e0(LPCRITICAL_SECTION param_1)

{
  LeaveCriticalSection(param_1);
  return 0;
}



// Function: FUN_10003500 at 10003500

void __cdecl FUN_10003500(undefined4 param_1)

{
  Ordinal_2(param_1);
  return;
}



// Function: FUN_10003510 at 10003510

undefined4 FUN_10003510(void)

{
  return 3;
}



// Function: FUN_10003520 at 10003520

void __cdecl FUN_10003520(LPCRITICAL_SECTION param_1,DWORD param_2)

{
  InitializeCriticalSectionAndSpinCount(param_1,param_2);
  return;
}



// Function: FUN_10003540 at 10003540

void __cdecl FUN_10003540(double param_1,uint param_2)

{
  FUN_100026f0(param_1,param_2);
  return;
}



// Function: FUN_10003560 at 10003560

int __cdecl FUN_10003560(wchar_t *param_1,size_t param_2)

{
  int iVar1;
  va_list in_stack_fffffff4;
  
  iVar1 = _vswprintf(param_1,param_2,(wchar_t *)&stack0x0000000c,in_stack_fffffff4);
  return iVar1;
}



// Function: FUN_100035a0 at 100035a0

undefined4 __cdecl FUN_100035a0(int *param_1,int *param_2)

{
  undefined4 local_8;
  
  if ((((*param_1 == *param_2) && (param_1[1] == param_2[1])) && (param_1[2] == param_2[2])) &&
     (param_1[3] == param_2[3])) {
    local_8 = 1;
  }
  else {
    local_8 = 0;
  }
  return local_8;
}



// Function: FUN_10003640 at 10003640

undefined4 FUN_10003640(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10013402;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    puVar1 = (undefined4 *)FUN_10011c40(0x28);
    local_8._0_1_ = 1;
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10003f00(puVar1);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    uVar2 = FUN_100036e6();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@100036e0 at 100036e0

undefined * Catch_100036e0(void)

{
  return &DAT_100036ef;
}



// Function: FUN_100036e6 at 100036e6

undefined4 FUN_100036e6(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    FUN_1000c5c0(*(void **)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + 8));
    FUN_10009770();
    uVar1 = FUN_1000d890(*(int *)(unaff_EBP + -0x14) + 4);
    *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar1 = FUN_10008830();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar1 = FUN_1000d840();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    FUN_100097a0();
    if (*(int *)(unaff_EBP + -0x18) == 0) {
      uVar1 = (**(code **)**(undefined4 **)(unaff_EBP + -0x14))
                        (*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    if (*(int *)(unaff_EBP + -0x18) != 0) {
      *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x14);
      *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x2c);
      if (*(int *)(unaff_EBP + -0x1c) == 0) {
        *(undefined4 *)(unaff_EBP + -0x30) = 0;
      }
      else {
        uVar1 = (**(code **)(**(int **)(unaff_EBP + -0x1c) + 0x14))(1);
        *(undefined4 *)(unaff_EBP + -0x30) = uVar1;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_100037c0 at 100037c0

undefined4 FUN_100037c0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = FUN_100082f0(0,param_2,param_3);
  }
  else {
    local_8 = FUN_10008170(param_1,param_2,param_3);
  }
  return local_8;
}



// Function: FUN_10003800 at 10003800

undefined4 FUN_10003800(void)

{
  return 0;
}



// Function: FUN_10003810 at 10003810

void FUN_10003810(int param_1)

{
  FUN_1000d6f0((int *)&DAT_1001b6b0,0x67,param_1,(int *)0x0);
  return;
}



// Function: FUN_10003830 at 10003830

void FUN_10003830(void)

{
  return;
}



// Function: FUN_10003840 at 10003840

undefined4 FUN_10003840(void)

{
  return 0;
}



// Function: DllGetClassObject at 10003850

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  
                    /* 0x3850  2  DllGetClassObject */
  iVar1 = FUN_10008a10(&DAT_1001b6b0,(int *)rclsid,riid,(int *)ppv);
  return iVar1;
}



// Function: DllCanUnloadNow at 10003870

HRESULT DllCanUnloadNow(void)

{
  int iVar1;
  uint local_8;
  
                    /* 0x3870  1  DllCanUnloadNow */
  iVar1 = FUN_10008e00(0x1001b6b0);
  local_8 = (uint)(iVar1 != 0);
  return local_8;
}



// Function: DllRegisterServer at 100038a0

void DllRegisterServer(void)

{
                    /* 0x38a0  3  DllRegisterServer */
  FUN_1000b0b0(&DAT_1001b6b0,1,(void *)0x0);
  return;
}



// Function: DllUnregisterServer at 100038c0

void DllUnregisterServer(void)

{
                    /* 0x38c0  4  DllUnregisterServer */
  FUN_1000c960(&DAT_1001b6b0,1,(void *)0x0);
  return;
}



// Function: FUN_100038e0 at 100038e0

LPCSTR __cdecl FUN_100038e0(LPSTR param_1)

{
  LPCSTR local_8;
  
  if (param_1 == (LPSTR)0x0) {
    local_8 = (LPCSTR)0x0;
  }
  else {
    local_8 = (LPCSTR)0x0;
    for (; *param_1 != '\0'; param_1 = CharNextA(param_1)) {
      if (*param_1 == '.') {
        local_8 = param_1;
      }
      else if (*param_1 == '\\') {
        local_8 = (LPCSTR)0x0;
      }
    }
    if (local_8 == (LPCSTR)0x0) {
      local_8 = param_1;
    }
  }
  return local_8;
}



// Function: FUN_10003950 at 10003950

int FUN_10003950(LPWSTR param_1)

{
  WCHAR WVar1;
  int iVar2;
  LPWSTR pWVar3;
  undefined4 local_10;
  undefined4 local_8;
  
  if (param_1 == (LPWSTR)0x0) {
    iVar2 = 0;
  }
  else {
    local_10 = param_1;
    local_8 = param_1;
    while (*local_8 != L'\0') {
      pWVar3 = CharNextW(local_8);
      if (((*local_8 == L'\\') || (*local_8 == L'/')) ||
         (WVar1 = *local_8, local_8 = pWVar3, WVar1 == L':')) {
        local_10 = pWVar3;
        local_8 = pWVar3;
      }
    }
    iVar2 = (int)local_10 - (int)param_1 >> 1;
  }
  return iVar2;
}



// Function: FUN_100039c0 at 100039c0

undefined4 FUN_100039c0(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_100095d0(&DAT_1001b6b0,0x1001b0e0,param_1,(undefined4 *)&DAT_100150c0);
    DisableThreadLibraryCalls(param_1);
  }
  else if (param_2 == 0) {
    FUN_1000c800(0x1001b6b0);
  }
  return 1;
}



// Function: FUN_10003a10 at 10003a10

undefined4 __cdecl FUN_10003a10(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}



// Function: FUN_10003a20 at 10003a20

undefined4 __cdecl FUN_10003a20(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}



// Function: FUN_10003a30 at 10003a30

void FUN_10003a30(void)

{
  return;
}



// Function: FUN_10003a40 at 10003a40

void FUN_10003a40(void)

{
  return;
}



// Function: FUN_10003a50 at 10003a50

void __thiscall FUN_10003a50(void *this,undefined4 *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  
  puVar2 = (undefined4 *)FUN_100050b0(param_1);
  cVar1 = FUN_10009a10(this,puVar2);
  if (cVar1 == '\0') {
    puVar3 = &DAT_10014df8;
    puVar2 = (undefined4 *)FUN_100050b0(param_1);
    FUN_100068b0((int *)this,puVar2,puVar3);
  }
  else {
    FUN_100050c0((undefined4 *)this);
  }
  return;
}



// Function: AtlAdd<> at 10003aa0

/* Library Function - Multiple Matches With Same Base Name
    long __cdecl ATL::AtlAdd<unsigned int>(unsigned int *,unsigned int,unsigned int)
    long __cdecl ATL::AtlAdd<unsigned long>(unsigned long *,unsigned long,unsigned long)
   
   Library: Visual Studio 2010 Debug */

HRESULT __cdecl AtlAdd<>(int *param_1,int param_2,uint param_3)

{
  HRESULT HVar1;
  
  if (-param_2 - 1U < param_3) {
    HVar1 = _HRESULT_FROM_WIN32(0x216);
  }
  else {
    *param_1 = param_2 + param_3;
    HVar1 = 0;
  }
  return HVar1;
}



// Function: AtlAddThrow<unsigned_long> at 10003ad0

/* Library Function - Single Match
    unsigned long __cdecl ATL::AtlAddThrow<unsigned long>(unsigned long,unsigned long)
   
   Library: Visual Studio 2010 Debug */

ulong __cdecl ATL::AtlAddThrow<unsigned_long>(ulong param_1,ulong param_2)

{
  ulong local_c;
  HRESULT local_8;
  
  local_8 = AtlAdd<>((int *)&local_c,param_1,param_2);
  if (local_8 < 0) {
    FUN_100032d0(local_8);
  }
  return local_c;
}



// Function: AtlMultiply<int> at 10003b10

/* Library Function - Single Match
    long __cdecl ATL::AtlMultiply<int>(int *,int,int)
   
   Library: Visual Studio 2010 Debug */

long __cdecl ATL::AtlMultiply<int>(int *param_1,int param_2,int param_3)

{
  long lVar1;
  longlong lVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  lVar2 = __allmul(param_2,param_2 >> 0x1f,param_3,param_3 >> 0x1f);
  local_8 = (uint)((ulonglong)lVar2 >> 0x20);
  if ((((int)local_8 < 1) && ((local_c = (uint)lVar2, lVar2 < 0 || (local_c < 0x80000000)))) &&
     ((local_8 < 0x80000000 || ((-2 < (int)local_8 && (0x7fffffff < local_c)))))) {
    *param_1 = local_c;
    lVar1 = 0;
  }
  else {
    lVar1 = _HRESULT_FROM_WIN32(0x216);
  }
  return lVar1;
}



// Function: AtlMultiply<> at 10003b80

/* Library Function - Multiple Matches With Same Base Name
    long __cdecl ATL::AtlMultiply<unsigned int>(unsigned int *,unsigned int,unsigned int)
    long __cdecl ATL::AtlMultiply<unsigned long>(unsigned long *,unsigned long,unsigned long)
   
   Library: Visual Studio 2012 Debug */

HRESULT __cdecl AtlMultiply<>(undefined4 *param_1,uint param_2,uint param_3)

{
  HRESULT HVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = (int)((ulonglong)param_2 * (ulonglong)param_3 >> 0x20);
  if (local_8 == 0) {
    local_c = (undefined4)((ulonglong)param_2 * (ulonglong)param_3);
    *param_1 = local_c;
    HVar1 = 0;
  }
  else {
    HVar1 = _HRESULT_FROM_WIN32(0x216);
  }
  return HVar1;
}



// Function: AtlMultiply<> at 10003bc0

/* Library Function - Multiple Matches With Same Base Name
    long __cdecl ATL::AtlMultiply<unsigned int>(unsigned int *,unsigned int,unsigned int)
    long __cdecl ATL::AtlMultiply<unsigned long>(unsigned long *,unsigned long,unsigned long)
   
   Library: Visual Studio 2012 Debug */

HRESULT __cdecl AtlMultiply<>(undefined4 *param_1,uint param_2,uint param_3)

{
  HRESULT HVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = (int)((ulonglong)param_2 * (ulonglong)param_3 >> 0x20);
  if (local_8 == 0) {
    local_c = (undefined4)((ulonglong)param_2 * (ulonglong)param_3);
    *param_1 = local_c;
    HVar1 = 0;
  }
  else {
    HVar1 = _HRESULT_FROM_WIN32(0x216);
  }
  return HVar1;
}



// Function: AtlMultiplyThrow<unsigned_int> at 10003c00

/* Library Function - Single Match
    unsigned int __cdecl ATL::AtlMultiplyThrow<unsigned int>(unsigned int,unsigned int)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

uint __cdecl ATL::AtlMultiplyThrow<unsigned_int>(uint param_1,uint param_2)

{
  uint local_c;
  HRESULT local_8;
  
  local_8 = AtlMultiply<>(&local_c,param_1,param_2);
  if (local_8 < 0) {
    FUN_100032d0(local_8);
  }
  return local_c;
}



// Function: QueryInterface<> at 10003c40

/* Library Function - Multiple Matches With Same Base Name
    public: long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface<struct
   IAccessibleProxy>(struct IAccessibleProxy * *)
    public: long __stdcall IUnknown::QueryInterface<struct IAccessor>(struct IAccessor * *)
    public: long __stdcall IUnknown::QueryInterface<struct IColumnsInfo>(struct IColumnsInfo * *)
    public: long __stdcall IUnknown::QueryInterface<struct IHTMLDocument2>(struct IHTMLDocument2 *
   *)
     8 names - too many to list
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void QueryInterface<>(undefined4 *param_1,undefined4 param_2)

{
  (**(code **)*param_1)(param_1,&DAT_10014e10,param_2);
  return;
}



// Function: FUN_10003c60 at 10003c60

int __fastcall FUN_10003c60(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012a58;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10004350(param_1);
  local_8 = 0;
  FUN_100096b0();
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10003cc0 at 10003cc0

undefined4 * __fastcall FUN_10003cc0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10003ce0 at 10003ce0

undefined4 * __fastcall FUN_10003ce0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10003d00 at 10003d00

undefined4 * __fastcall FUN_10003d00(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10003d20 at 10003d20

undefined4 * __thiscall FUN_10003d20(void *this,undefined4 param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012a96;
  local_10 = ExceptionList;
  uVar1 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10002c40(this);
  FUN_10003f60((undefined4 *)((int)this + 4));
  local_8 = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CLogger>::vftable;
  FUN_10003db0((void *)((int)this + 0xc),param_1);
  local_8 = CONCAT31(local_8._1_3_,1);
  (**(code **)(*DAT_1001b648 + 4))(uVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10003db0 at 10003db0

undefined4 * __thiscall FUN_10003db0(void *this,undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012ac8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10001000((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CLogger>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CLogger>::vftable;
  *(undefined ***)((int)this + 8) = ATL::CComContainedObject<class_CLogger>::vftable;
  *(undefined4 *)((int)this + 0xc) = param_1;
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: CComCritSecLock<class_ATL::CComCriticalSection> at 10003e30

/* Library Function - Single Match
    public: __thiscall ATL::CComCritSecLock<class ATL::CComCriticalSection>::CComCritSecLock<class
   ATL::CComCriticalSection>(class ATL::CComCriticalSection &,bool)
   
   Library: Visual Studio 2012 Debug */

CComCritSecLock<class_ATL::CComCriticalSection> * __thiscall
ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
CComCritSecLock<class_ATL::CComCriticalSection>
          (CComCritSecLock<class_ATL::CComCriticalSection> *this,CComCriticalSection *param_1,
          bool param_2)

{
  int iVar1;
  
  *(CComCriticalSection **)this = param_1;
  this[4] = (CComCritSecLock<class_ATL::CComCriticalSection>)0x0;
  if (param_2) {
    iVar1 = FUN_10009dc0((undefined4 *)this);
    if (iVar1 < 0) {
      FUN_100032d0(iVar1);
    }
  }
  return this;
}



// Function: FUN_10003e80 at 10003e80

undefined4 * __fastcall FUN_10003e80(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012af8;
  local_10 = ExceptionList;
  uVar1 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10001000((int)param_1);
  local_8 = 0;
  *param_1 = ATL::CComObject<class_CLogger>::vftable;
  param_1[1] = ATL::CComObject<class_CLogger>::vftable;
  param_1[2] = ATL::CComObject<class_CLogger>::vftable;
  (**(code **)(*DAT_1001b648 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10003f00 at 10003f00

undefined4 * __fastcall FUN_10003f00(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012b28;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10004400(param_1);
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10003f60 at 10003f60

undefined4 * __fastcall FUN_10003f60(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012b58;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002b40(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10003fb0 at 10003fb0

undefined4 * __fastcall FUN_10003fb0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012b88;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100041a0(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10004000 at 10004000

undefined4 * __fastcall FUN_10004000(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012bb8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100041c0(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10004050 at 10004050

void * __thiscall FUN_10004050(void *this,int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012be8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  CComPtrBase<>(this,*param_1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_100040b0 at 100040b0

undefined4 * __fastcall FUN_100040b0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012c18;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10004220(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10004100 at 10004100

undefined4 * __fastcall FUN_10004100(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012c48;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10004240(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10004150 at 10004150

undefined4 * __fastcall FUN_10004150(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012c78;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10004260(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100041a0 at 100041a0

undefined4 * __fastcall FUN_100041a0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_100041c0 at 100041c0

undefined4 * __fastcall FUN_100041c0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: CComPtrBase<> at 100041e0

/* Library Function - Multiple Matches With Same Base Name
    protected: __thiscall ATL::CComPtrBase<struct IShellItem>::CComPtrBase<struct IShellItem>(struct
   IShellItem *)
    protected: __thiscall ATL::CComPtrBase<struct IUnknown>::CComPtrBase<struct IUnknown>(struct
   IUnknown *)
    protected: __thiscall ATL::CComPtrBase<struct IXMLDOMNode>::CComPtrBase<struct
   IXMLDOMNode>(struct IXMLDOMNode *)
    protected: __thiscall ATL::CComPtrBase<struct IXMLDOMNodeList>::CComPtrBase<struct
   IXMLDOMNodeList>(struct IXMLDOMNodeList *)
   
   Library: Visual Studio 2010 Debug */

int * __thiscall CComPtrBase<>(void *this,int param_1)

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



// Function: FUN_10004220 at 10004220

undefined4 * __fastcall FUN_10004220(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10004240 at 10004240

undefined4 * __fastcall FUN_10004240(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10004260 at 10004260

undefined4 * __fastcall FUN_10004260(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10004280 at 10004280

undefined4 * __fastcall FUN_10004280(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}



// Function: FUN_100042b0 at 100042b0

undefined4 * __fastcall FUN_100042b0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_100042d0 at 100042d0

undefined4 * __fastcall FUN_100042d0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_100042f0 at 100042f0

undefined4 * __fastcall FUN_100042f0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10004310 at 10004310

undefined4 * __thiscall FUN_10004310(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  return (undefined4 *)this;
}



// Function: FUN_10004330 at 10004330

undefined4 * __thiscall FUN_10004330(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  return (undefined4 *)this;
}



// Function: FUN_10004350 at 10004350

int __fastcall FUN_10004350(int param_1)

{
  long lVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012cab;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100046c0(param_1 + 4);
  local_8 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_1001b648 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 0x10));
  if (lVar1 < 0) {
    DAT_1001b65c = 1;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x24;
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10004400 at 10004400

undefined4 * __fastcall FUN_10004400(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012cdb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10004680(param_1);
  FUN_10002780(param_1 + 1);
  *param_1 = ATL::CComClassFactory::vftable;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10004470 at 10004470

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_10004470(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012d08;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10003c60((int)param_1);
  *param_1 = ATL::CComModule::vftable;
  _DAT_1001b660 = param_1;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100044d0 at 100044d0

undefined4 * __fastcall FUN_100044d0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012d38;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10004280(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10004520 at 10004520

undefined4 * __thiscall FUN_10004520(void *this,int param_1)

{
  void *pvVar1;
  
  if (param_1 < 100) {
    param_1 = 1000;
  }
  *(undefined4 *)this = 0;
  *(int *)((int)this + 4) = param_1;
  pvVar1 = ATL::AtlCoTaskMemCAlloc(*(ulong *)((int)this + 4),1);
  *(void **)((int)this + 8) = pvVar1;
  if (*(int *)((int)this + 8) != 0) {
    **(undefined1 **)((int)this + 8) = 0;
  }
  return (undefined4 *)this;
}



// Function: CRegKey at 10004580

/* Library Function - Single Match
    public: __thiscall ATL::CRegKey::CRegKey(struct HKEY__ *)
   
   Library: Visual Studio 2010 Debug */

CRegKey * __thiscall ATL::CRegKey::CRegKey(CRegKey *this,HKEY__ *param_1)

{
  *(HKEY__ **)this = param_1;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return this;
}



// Function: CRegKey at 100045b0

/* Library Function - Single Match
    public: __thiscall ATL::CRegKey::CRegKey(class ATL::CAtlTransactionManager *)
   
   Library: Visual Studio 2010 Debug */

CRegKey * __thiscall ATL::CRegKey::CRegKey(CRegKey *this,CAtlTransactionManager *param_1)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(CAtlTransactionManager **)(this + 8) = param_1;
  return this;
}



// Function: FUN_100045e0 at 100045e0

undefined4 * __fastcall FUN_100045e0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012d6b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100046a0(param_1);
  *param_1 = ATL::CRegObject::vftable;
  FUN_100044d0(param_1 + 1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10004650 at 10004650

undefined4 * __thiscall FUN_10004650(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = param_1;
  *(undefined4 *)this = 0;
  return (undefined4 *)this;
}



// Function: FUN_10004680 at 10004680

undefined4 __fastcall FUN_10004680(undefined4 param_1)

{
  FUN_10002c40(param_1);
  return param_1;
}



// Function: FUN_100046a0 at 100046a0

undefined4 __fastcall FUN_100046a0(undefined4 param_1)

{
  FUN_10002c40(param_1);
  return param_1;
}



// Function: FUN_100046c0 at 100046c0

int __fastcall FUN_100046c0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012d9b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  ATL::CComCriticalSection::CComCriticalSection((CComCriticalSection *)(param_1 + 0xc));
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10004720 at 10004720

undefined4 * __fastcall FUN_10004720(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012dc8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002b00(param_1);
  param_1[1] = 0;
  param_1[2] = 0xffffffff;
  ExceptionList = local_10;
  return param_1;
}



// Function: FID_conflict:~bad_alloc at 10004790

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012df8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10004db0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> at 100047e0

/* Library Function - Single Match
    public: __thiscall ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class
   ATL::CCRTAllocator>::~CAtlSafeAllocBufferManager<class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __thiscall
ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
          (CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *this)

{
  void *pvVar1;
  
  while (*(int *)this != 0) {
    pvVar1 = *(void **)this;
    *(undefined4 *)this = **(undefined4 **)this;
    FUN_10008960(pvVar1);
  }
  return;
}



// Function: FUN_10004820 at 10004820

void __fastcall FUN_10004820(undefined4 *param_1)

{
  Free(param_1);
  return;
}



// Function: FUN_10004840 at 10004840

void __fastcall FUN_10004840(undefined4 *param_1)

{
  Free(param_1);
  return;
}



// Function: FUN_10004860 at 10004860

void __fastcall FUN_10004860(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_10012e36;
  local_10 = ExceptionList;
  uVar1 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ATL::CComAggObject<class_CLogger>::vftable;
  local_8 = 1;
  param_1[1] = 0xc0000001;
  FUN_10008860();
  (**(code **)(*DAT_1001b648 + 8))(uVar1);
  local_8 = local_8 & 0xffffff00;
  FID_conflict__bad_alloc((int)(param_1 + 3));
  local_8 = 0xffffffff;
  _anon_026BA49F::_ExceptionPtr_normal::~_ExceptionPtr_normal((_ExceptionPtr_normal *)(param_1 + 1))
  ;
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~bad_alloc at 100048f0

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012e68;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10001070(param_1);
  ExceptionList = local_10;
  return;
}



// Function: ~CComCritSecLock<class_ATL::CComCriticalSection> at 10004940

/* Library Function - Single Match
    public: __thiscall ATL::CComCritSecLock<class ATL::CComCriticalSection>::~CComCritSecLock<class
   ATL::CComCriticalSection>(void)
   
   Library: Visual Studio */

void __thiscall
ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
~CComCritSecLock<class_ATL::CComCriticalSection>
          (CComCritSecLock<class_ATL::CComCriticalSection> *this)

{
  if (this[4] != (CComCritSecLock<class_ATL::CComCriticalSection>)0x0) {
    FUN_1000c8a0((undefined4 *)this);
  }
  return;
}



// Function: FUN_10004960 at 10004960

void __fastcall FUN_10004960(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012e98;
  local_10 = ExceptionList;
  uVar1 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ATL::CComObject<class_CLogger>::vftable;
  param_1[1] = ATL::CComObject<class_CLogger>::vftable;
  param_1[2] = ATL::CComObject<class_CLogger>::vftable;
  local_8 = 0;
  param_1[3] = 0xc0000001;
  FUN_10008890();
  (**(code **)(*DAT_1001b648 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_10001070((int)param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100049f0 at 100049f0

void __fastcall FUN_100049f0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012ec8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  local_8 = 0;
  param_1[1] = 0xc0000001;
  FUN_10008890();
  local_8 = 0xffffffff;
  FUN_10004e10(param_1);
  ExceptionList = local_10;
  return;
}



// Function: ~_ExceptionPtr_normal at 10004a60

/* Library Function - Single Match
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __thiscall
_anon_026BA49F::_ExceptionPtr_normal::~_ExceptionPtr_normal(_ExceptionPtr_normal *this)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012ef8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10002e80();
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~bad_alloc at 10004ab0

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012f28;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10004c40(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~bad_alloc at 10004b00

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012f58;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10004c70(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~bad_alloc at 10004b50

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012f88;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10004ca0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~bad_alloc at 10004ba0

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012fb8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10004cd0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~bad_alloc at 10004bf0

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012fe8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10004d00(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004c40 at 10004c40

void __fastcall FUN_10004c40(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10004c70 at 10004c70

void __fastcall FUN_10004c70(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10004ca0 at 10004ca0

void __fastcall FUN_10004ca0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10004cd0 at 10004cd0

void __fastcall FUN_10004cd0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10004d00 at 10004d00

void __fastcall FUN_10004d00(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10004d30 at 10004d30

void __fastcall FUN_10004d30(int *param_1)

{
  FUN_1000bcc0(param_1);
  return;
}



// Function: ~CTempBuffer<> at 10004d50

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall ATL::CTempBuffer<char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<unsigned char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,10,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,10,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,128,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __fastcall ~CTempBuffer<>(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FreeHeap(param_1);
  }
  return;
}



// Function: ~CTempBuffer<> at 10004d70

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall ATL::CTempBuffer<char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<unsigned char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,10,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,10,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,128,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __fastcall ~CTempBuffer<>(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FreeHeap(param_1);
  }
  return;
}



// Function: ~CTempBuffer<> at 10004d90

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall ATL::CTempBuffer<char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<unsigned char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,10,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,10,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,128,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __fastcall ~CTempBuffer<>(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FreeHeap(param_1);
  }
  return;
}



// Function: FUN_10004db0 at 10004db0

void __fastcall FUN_10004db0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001301b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_1000c780(param_1);
  local_8 = 0xffffffff;
  FUN_10004fd0();
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004e10 at 10004e10

void __fastcall FUN_10004e10(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001304b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CComClassFactory::vftable;
  local_8 = 0xffffffff;
  ~_ExceptionPtr_static<>((int)(param_1 + 1));
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004e70 at 10004e70

void __fastcall FUN_10004e70(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10013078;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CComModule::vftable;
  local_8 = 0xffffffff;
  FID_conflict__bad_alloc((int)param_1);
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~CAtlWinModule at 10004ed0

/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CAtlWinModule::~CAtlWinModule(void)
    public: __thiscall CPaneContainerGC::~CPaneContainerGC(void)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2010 Debug */

void __fastcall FID_conflict__CAtlWinModule(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100130a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10007fb0(param_1);
  local_8 = 0xffffffff;
  FUN_10004d30(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004f30 at 10004f30

void __fastcall FUN_10004f30(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_10004f50 at 10004f50

void __fastcall FUN_10004f50(CRegKey *param_1)

{
  ATL::CRegKey::Close(param_1);
  return;
}



// Function: FUN_10004f70 at 10004f70

void __fastcall FUN_10004f70(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100130db;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CRegObject::vftable;
  local_8 = 0;
  FUN_10008030((int)param_1);
  local_8 = 0xffffffff;
  FID_conflict__CAtlWinModule(param_1 + 1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004fd0 at 10004fd0

void FUN_10004fd0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001310b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10002e70();
  ExceptionList = local_10;
  return;
}



// Function: FUN_10005020 at 10005020

bool __thiscall FUN_10005020(void *this,int param_1)

{
                    /* WARNING: Load size is inaccurate */
  return *this == param_1;
}



// Function: FUN_10005050 at 10005050

void __fastcall FUN_10005050(int *param_1)

{
  FUN_10003070(param_1);
  return;
}



// Function: FUN_10005070 at 10005070

bool __fastcall FUN_10005070(int *param_1)

{
  char cVar1;
  
  cVar1 = FUN_10005050(param_1);
  return cVar1 == '\0';
}



// Function: FUN_100050b0 at 100050b0

undefined4 __fastcall FUN_100050b0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_100050c0 at 100050c0

undefined4 __fastcall FUN_100050c0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_100050d0 at 100050d0

undefined4 __fastcall FUN_100050d0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_100050e0 at 100050e0

undefined4 __fastcall FUN_100050e0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_100050f0 at 100050f0

undefined4 __fastcall FUN_100050f0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10005100 at 10005100

undefined4 __fastcall FUN_10005100(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10005110 at 10005110

undefined4 __fastcall FUN_10005110(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10005120 at 10005120

undefined4 __fastcall FUN_10005120(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10005130 at 10005130

undefined4 __fastcall FUN_10005130(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10005140 at 10005140

undefined4 __fastcall FUN_10005140(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10005150 at 10005150

undefined4 __fastcall FUN_10005150(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10005160 at 10005160

undefined4 __fastcall FUN_10005160(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10005170 at 10005170

undefined4 __fastcall FUN_10005170(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10005180 at 10005180

undefined4 __fastcall FUN_10005180(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10005190 at 10005190

undefined4 __fastcall FUN_10005190(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100051a0 at 100051a0

undefined4 __fastcall FUN_100051a0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100051b0 at 100051b0

undefined4 __fastcall FUN_100051b0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100051c0 at 100051c0

undefined4 * __thiscall FUN_100051c0(void *this,uint param_1)

{
  FUN_10004860((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100051f0 at 100051f0

undefined4 * __thiscall FUN_100051f0(void *this,uint param_1)

{
  FUN_10004960((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10005220 at 10005220

undefined4 * __thiscall FUN_10005220(void *this,uint param_1)

{
  FUN_100049f0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10005250 at 10005250

undefined4 * __thiscall FUN_10005250(void *this,uint param_1)

{
  FUN_10004e10((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10005280 at 10005280

undefined4 * __thiscall FUN_10005280(void *this,uint param_1)

{
  FUN_10004e70((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100052b0 at 100052b0

undefined4 * __thiscall FUN_100052b0(void *this,uint param_1)

{
  FUN_10004f70((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100052e0 at 100052e0

undefined4 __thiscall FUN_100052e0(void *this,undefined4 *param_1,undefined4 *param_2)

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
      FUN_10009840(this,*(int *)((int)this + 8),param_1,param_2);
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      uVar2 = 1;
    }
  }
  return uVar2;
}



// Function: FUN_10005380 at 10005380

undefined4 __thiscall FUN_10005380(void *this,char *param_1,wchar_t *param_2)

{
  undefined4 uVar1;
  size_t sVar2;
  int iVar3;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  void *local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013140;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((param_1 == (char *)0x0) || (param_2 == (wchar_t *)0x0)) {
    uVar1 = 0;
  }
  else {
    local_1c = 0;
    sVar2 = strlen(param_1);
    local_20 = sVar2 + 1;
    local_18 = (void *)0x0;
    local_18 = (void *)FUN_10011c6e(local_20);
    FUN_10003ce0(&local_2c);
    local_8 = 0;
    FUN_10007dd0(&local_2c,local_18);
    sVar2 = FUN_1000db00(param_2);
    local_24 = sVar2 * 2 + 2;
    local_14 = (void *)0x0;
    local_14 = (void *)FUN_10011c6e(-(uint)((int)((ulonglong)local_24 * 2 >> 0x20) != 0) |
                                    (uint)((ulonglong)local_24 * 2));
    FUN_10003d00(&local_28);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_10007df0(&local_28,local_14);
    if ((local_18 == (void *)0x0) || (local_14 == (void *)0x0)) {
      local_1c = -0x7ff8fff2;
    }
    else {
      FUN_1000da80(local_18,local_20,param_1,local_20);
      FUN_1000da80(local_14,local_24,param_2,local_24);
      iVar3 = FUN_100052e0(this,&local_18,&local_14);
      if (iVar3 == 0) {
        local_1c = -0x7ff8fff2;
      }
    }
    if (-1 < local_1c) {
      detach(&local_2c);
      detach(&local_28);
    }
    local_8 = local_8 & 0xffffff00;
    FUN_10004840(&local_28);
    local_8 = 0xffffffff;
    uVar1 = 0x10005521;
    FUN_10004820(&local_2c);
  }
  ExceptionList = local_10;
  return uVar1;
}



// Function: FUN_10005540 at 10005540

void __thiscall FUN_10005540(void *this,LPCSTR param_1)

{
  LPSTR pCVar1;
  
  pCVar1 = CharNextA(param_1);
  FUN_10006340(this,param_1,(int)pCVar1 - (int)param_1);
  return;
}



// Function: FUN_10005570 at 10005570

void FUN_10005570(int *param_1)

{
  undefined **ppuVar1;
  
  ppuVar1 = FUN_10008a00();
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",ppuVar1);
  return;
}



// Function: FUN_100055a0 at 100055a0

void FUN_100055a0(int param_1)

{
  FUN_10009750((LONG *)(param_1 + 4));
  return;
}



// Function: FUN_100055c0 at 100055c0

void FUN_100055c0(int param_1)

{
  FUN_1000a160((undefined4 *)(param_1 + 0xc));
  return;
}



// Function: FUN_100055d2 at 100055d2

void FUN_100055d2(int param_1)

{
  FUN_100055c0(param_1 + -4);
  return;
}



// Function: FUN_100055dc at 100055dc

void FUN_100055dc(int param_1)

{
  FUN_100055c0(param_1 + -8);
  return;
}



// Function: FUN_100055f0 at 100055f0

void FUN_100055f0(int param_1)

{
  FUN_10009730((LONG *)(param_1 + 0xc));
  return;
}



// Function: FUN_10005602 at 10005602

void FUN_10005602(int param_1)

{
  FUN_100055f0(param_1 + -4);
  return;
}



// Function: FUN_1000560c at 1000560c

void FUN_1000560c(int param_1)

{
  FUN_100055f0(param_1 + -8);
  return;
}



// Function: FUN_10005620 at 10005620

int FUN_10005620(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_10009730((LONG *)(param_1 + 4));
  if (iVar1 == 2) {
    (**(code **)(*DAT_1001b648 + 4))();
  }
  return iVar1;
}



// Function: FUN_10005660 at 10005660

undefined4 FUN_10005660(void)

{
  return 1;
}



// Function: FUN_10005670 at 10005670

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_10005670(int param_1,wchar_t *param_2,wchar_t *param_3)

{
  char cVar1;
  size_t sVar2;
  long lVar3;
  uint local_4c;
  undefined4 local_48;
  UINT local_44;
  int local_40;
  undefined4 local_3c;
  undefined1 *local_38;
  undefined4 local_34;
  LPSTR local_30;
  LPSTR local_2c;
  char *local_28;
  char *local_24;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_20 [4];
  wchar_t *local_1c;
  ulong local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013168;
  local_10 = ExceptionList;
  local_4c = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_4c;
  if ((param_2 != (wchar_t *)0x0) && (param_3 != (wchar_t *)0x0)) {
    FUN_10009e20();
    local_44 = FUN_10003510();
    FUN_10003cc0((undefined4 *)local_20);
    local_8 = 0;
    local_1c = param_2;
    if (param_2 == (wchar_t *)0x0) {
      local_28 = (char *)0x0;
    }
    else {
      sVar2 = wcslen(param_2);
      local_18 = sVar2 + 1;
      lVar3 = ATL::AtlMultiply<int>((int *)&local_18,local_18,2);
      if (lVar3 < 0) {
        local_30 = (LPSTR)0x0;
      }
      else {
        if (((int)local_18 < 0x401) && (cVar1 = FUN_1000d8f0(local_18), cVar1 != '\0')) {
          local_38 = (undefined1 *)&local_4c;
          local_2c = (LPSTR)&local_4c;
        }
        else {
          local_2c = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                            CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                      (local_20,local_18);
        }
        local_30 = FUN_10003300(local_2c,local_1c,local_18,local_44);
      }
      local_28 = local_30;
    }
    local_24 = local_28;
    if (local_28 == (char *)0x0) {
      local_3c = 0x8007000e;
      local_8 = 0xffffffff;
      ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
      ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_20);
    }
    else {
      local_40 = FUN_10005380((void *)(param_1 + 4),local_28,param_3);
      FUN_1000c8e0();
      if (local_40 == 0) {
        local_34 = 0x8007000e;
      }
      else {
        local_34 = 0;
      }
      local_48 = local_34;
      local_8 = 0xffffffff;
      ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
      ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_20);
    }
  }
  ExceptionList = local_10;
  local_4c = 0x10005804;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10005810 at 10005810

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __thiscall FUN_10005810(void *this,wchar_t *param_1)

{
  char cVar1;
  long lVar2;
  size_t sVar3;
  uint local_48;
  undefined4 local_44;
  undefined1 *local_40;
  void *local_3c;
  undefined4 local_38;
  UINT local_34;
  char *local_30;
  LPSTR local_2c;
  LPSTR local_28;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_24 [4];
  char *local_20;
  wchar_t *local_1c;
  ulong local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013198;
  local_10 = ExceptionList;
  local_48 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_3c = this;
  local_14 = local_48;
  if (param_1 != (wchar_t *)0x0) {
    local_34 = FUN_10003510();
    FUN_10003cc0((undefined4 *)local_24);
    local_8 = 0;
    local_1c = param_1;
    if (param_1 == (wchar_t *)0x0) {
      local_30 = (char *)0x0;
    }
    else {
      sVar3 = wcslen(param_1);
      local_18 = sVar3 + 1;
      lVar2 = ATL::AtlMultiply<int>((int *)&local_18,local_18,2);
      if (lVar2 < 0) {
        local_28 = (LPSTR)0x0;
      }
      else {
        if (((int)local_18 < 0x401) && (cVar1 = FUN_1000d8f0(local_18), cVar1 != '\0')) {
          local_40 = (undefined1 *)&local_48;
          local_2c = (LPSTR)&local_48;
        }
        else {
          local_2c = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                            CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                      (local_24,local_18);
        }
        local_28 = FUN_10003300(local_2c,local_1c,local_18,local_34);
      }
      local_30 = local_28;
    }
    local_20 = local_30;
    if (local_30 == (char *)0x0) {
      local_38 = 0;
      local_8 = 0xffffffff;
      ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
      ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_24);
    }
    else {
      sVar3 = strlen(local_30);
      local_44 = FUN_10006340(local_3c,local_20,sVar3);
      local_8 = 0xffffffff;
      ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
      ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_24);
    }
  }
  ExceptionList = local_10;
  local_48 = 0x10005972;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10005980 at 10005980

void __thiscall FUN_10005980(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 local_c;
  
  if (this == (void *)0x0) {
    local_c = 0;
  }
  else {
    local_c = (int)this + 4;
  }
  FUN_10007210(local_c,param_1,param_2);
  return;
}



// Function: FUN_100059c0 at 100059c0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __thiscall FUN_100059c0(void *this,void *param_1,LPCSTR param_2,undefined1 *param_3)

{
  char cVar1;
  int iVar2;
  UINT UVar3;
  size_t sVar4;
  long lVar5;
  uint uStack_1298;
  undefined1 auStack_1274 [4];
  LPWSTR pWStack_1270;
  LPWSTR pWStack_1268;
  LPWSTR pWStack_1264;
  LPWSTR pWStack_1260;
  BYTE *pBStack_1258;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> aCStack_1254 [4];
  size_t sStack_1250;
  uint uStack_124c;
  uint local_1248;
  uint local_1244;
  ushort local_1240 [2];
  undefined4 *local_123c;
  ulong local_1234;
  ulong uStack_1230;
  int local_122c;
  undefined4 local_1220 [65];
  undefined4 auStack_111c [65];
  BYTE local_1018 [4096];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100131e1;
  local_10 = ExceptionList;
  uStack_1298 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_1298;
  ExceptionList = &local_10;
  local_1240[0] = 0;
  local_1234 = 0;
  local_123c = (undefined4 *)this;
  local_18 = uStack_1298;
  local_122c = FUN_10009eb0(this,local_1018);
  if (-1 < local_122c) {
    iVar2 = FUN_1000d730((LPCSTR)local_1018,local_1240);
    if (iVar2 == 0) {
      FUN_100089e0();
    }
    else {
      FUN_1000c6b0(local_123c);
      local_122c = FUN_10009eb0(local_123c,local_1018);
      if (-1 < local_122c) {
        local_1244 = (uint)local_1240[0];
        if (local_1244 < 0x14) {
          if (local_1244 == 0x13) {
            UVar3 = FUN_10003510();
            FUN_10003cc0((undefined4 *)aCStack_1254);
            local_8 = 3;
            pBStack_1258 = local_1018;
            if (pBStack_1258 == (BYTE *)0x0) {
              pWStack_1264 = (LPWSTR)0x0;
            }
            else {
              sVar4 = strlen((char *)pBStack_1258);
              uStack_1230 = sVar4 + 1;
              lVar5 = ATL::AtlMultiply<int>((int *)&uStack_1230,uStack_1230,2);
              if (lVar5 < 0) {
                pWStack_1270 = (LPWSTR)0x0;
              }
              else {
                if (((int)uStack_1230 < 0x401) && (cVar1 = FUN_1000d8f0(uStack_1230), cVar1 != '\0')
                   ) {
                  pWStack_1268 = (LPWSTR)&uStack_1298;
                  local_14 = (undefined1 *)&uStack_1298;
                }
                else {
                  pWStack_1268 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                         CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
                                         Allocate(aCStack_1254,uStack_1230);
                }
                pWStack_1270 = FUN_10003280(pWStack_1268,(LPCSTR)pBStack_1258,uStack_1230 >> 1,UVar3
                                           );
              }
              pWStack_1264 = pWStack_1270;
            }
            pWStack_1260 = pWStack_1264;
            if (pWStack_1264 == (LPWSTR)0x0) {
              local_8 = 0xffffffff;
              ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
              ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(aCStack_1254);
              goto LAB_10006093;
            }
            Ordinal_277(pWStack_1264,0,0,auStack_1274);
            local_1234 = FUN_1000c480(param_1,param_2);
            local_8 = 0xffffffff;
            ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
            ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(aCStack_1254);
          }
          else if (local_1244 == 8) {
            local_1234 = FUN_1000c550(param_1,param_2,local_1018,1);
          }
          else if (local_1244 == 0x11) {
            sStack_1250 = strlen((char *)local_1018);
            if ((sStack_1250 & 1) == 0) {
              uStack_124c = (int)sStack_1250 / 2;
              FUN_100042f0(auStack_111c);
              local_8 = 5;
              Allocate(auStack_111c,uStack_124c);
              FUN_10005f12();
              return;
            }
            goto LAB_10006093;
          }
        }
        else if (local_1244 == 0x4008) {
          sVar4 = strlen((char *)local_1018);
          local_1248 = sVar4 + 2;
          FUN_100042b0(local_1220);
          local_8 = 1;
          Allocate(local_1220,local_1248);
          FUN_10005b62();
          return;
        }
        if (local_1234 == 0) {
          local_122c = FUN_10009eb0(local_123c,param_3);
        }
        else {
          FUN_10006a10(local_1234);
        }
      }
    }
  }
LAB_10006093:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10005b5c at 10005b5c

undefined * Catch_10005b5c(void)

{
  return &DAT_10005b6b;
}



// Function: FUN_10005b62 at 10005b62

/* WARNING: Unable to track spacebase fully for stack */

void FUN_10005b62(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  LPSTR pCVar4;
  BOOL BVar5;
  BYTE *pBVar6;
  LSTATUS LVar7;
  uint unaff_EBP;
  
  *(undefined4 *)(unaff_EBP - 4) = 0;
  iVar2 = FUN_100050f0((undefined4 *)(unaff_EBP - 0x121c));
  if (iVar2 == 0) {
    *(undefined4 *)(unaff_EBP - 0x1230) = 0xe;
  }
  else {
    uVar3 = FUN_100050f0((undefined4 *)(unaff_EBP - 0x121c));
    *(undefined4 *)(unaff_EBP - 0x1220) = uVar3;
    *(uint *)(unaff_EBP - 0x1224) = unaff_EBP - 0x1014;
    *(undefined4 *)(unaff_EBP - 0x1244) = 0;
    while (**(char **)(unaff_EBP - 0x1224) != '\0') {
      pCVar4 = CharNextA(*(LPCSTR *)(unaff_EBP - 0x1224));
      *(LPSTR *)(unaff_EBP - 0x1258) = pCVar4;
      if ((**(char **)(unaff_EBP - 0x1224) == '\\') && (**(char **)(unaff_EBP - 0x1258) == '0')) {
        **(undefined1 **)(unaff_EBP - 0x1220) = 0;
        *(int *)(unaff_EBP - 0x1220) = *(int *)(unaff_EBP - 0x1220) + 1;
        pCVar4 = CharNextA(*(LPCSTR *)(unaff_EBP - 0x1258));
        *(LPSTR *)(unaff_EBP - 0x1224) = pCVar4;
      }
      else {
        **(undefined1 **)(unaff_EBP - 0x1220) = **(undefined1 **)(unaff_EBP - 0x1224);
        BVar5 = IsDBCSLeadByte(**(BYTE **)(unaff_EBP - 0x1224));
        if (BVar5 != 0) {
          *(int *)(unaff_EBP - 0x1220) = *(int *)(unaff_EBP - 0x1220) + 1;
          *(int *)(unaff_EBP - 0x1224) = *(int *)(unaff_EBP - 0x1224) + 1;
          if (**(char **)(unaff_EBP - 0x1224) == '\0') break;
          **(undefined1 **)(unaff_EBP - 0x1220) = **(undefined1 **)(unaff_EBP - 0x1224);
        }
        *(int *)(unaff_EBP - 0x1220) = *(int *)(unaff_EBP - 0x1220) + 1;
        *(int *)(unaff_EBP - 0x1224) = *(int *)(unaff_EBP - 0x1224) + 1;
      }
      *(int *)(unaff_EBP - 0x1244) = *(int *)(unaff_EBP - 0x1244) + 1;
    }
    **(undefined1 **)(unaff_EBP - 0x1220) = 0;
    *(int *)(unaff_EBP - 0x1220) = *(int *)(unaff_EBP - 0x1220) + 1;
    **(undefined1 **)(unaff_EBP - 0x1220) = 0;
    pBVar6 = (BYTE *)FUN_100050f0((undefined4 *)(unaff_EBP - 0x121c));
    LVar7 = FUN_1000c4b0(*(void **)(unaff_EBP + 8),*(LPCSTR *)(unaff_EBP + 0xc),pBVar6);
    *(LSTATUS *)(unaff_EBP - 0x1230) = LVar7;
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  ~CTempBuffer<>((int *)(unaff_EBP - 0x121c));
  if (*(int *)(unaff_EBP - 0x1230) == 0) {
    uVar3 = FUN_10009eb0(*(void **)(unaff_EBP - 0x1238),*(undefined1 **)(unaff_EBP + 0x10));
    *(undefined4 *)(unaff_EBP - 0x1228) = uVar3;
  }
  else {
    *(undefined4 *)(unaff_EBP - 0x1280) = 0x204;
    FUN_10006a10(*(ulong *)(unaff_EBP - 0x1230));
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uVar1 = *(uint *)(unaff_EBP - 0x14);
  *(undefined4 *)(unaff_EBP - 0x1288) = 0x100060b1;
  __security_check_cookie(uVar1 ^ unaff_EBP);
  return;
}



// Function: Catch@10005f0c at 10005f0c

undefined * Catch_10005f0c(void)

{
  return &DAT_10005f1b;
}



// Function: FUN_10005f12 at 10005f12

/* WARNING: Unable to track spacebase fully for stack */

void FUN_10005f12(void)

{
  int iVar1;
  void *_Dst;
  uint uVar2;
  BYTE *lpData;
  HKEY hKey;
  LSTATUS LVar3;
  undefined4 uVar4;
  uint unaff_EBP;
  LPCSTR lpValueName;
  DWORD Reserved;
  DWORD dwType;
  size_t _Size;
  DWORD cbData;
  
  *(undefined4 *)(unaff_EBP - 4) = 4;
  iVar1 = FUN_10005110((undefined4 *)(unaff_EBP - 0x1118));
  if (iVar1 == 0) {
    *(undefined4 *)(unaff_EBP - 0x1278) = 0x80004005;
    *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
    ~CTempBuffer<>((int *)(unaff_EBP - 0x1118));
  }
  else {
    _Size = *(size_t *)(unaff_EBP - 0x1248);
    iVar1 = 0;
    _Dst = (void *)FUN_10005110((undefined4 *)(unaff_EBP - 0x1118));
    memset(_Dst,iVar1,_Size);
    *(undefined4 *)(unaff_EBP - 0x1234) = 0;
    while (*(int *)(unaff_EBP - 0x1234) < *(int *)(unaff_EBP - 0x124c)) {
      iVar1 = FUN_10005110((undefined4 *)(unaff_EBP - 0x1118));
      *(int *)(unaff_EBP - 0x1268) = iVar1 + *(int *)(unaff_EBP - 0x1234) / 2;
      uVar2 = FUN_10007e90(*(char *)((unaff_EBP - 0x1014) + *(int *)(unaff_EBP - 0x1234)));
      **(byte **)(unaff_EBP - 0x1268) =
           **(byte **)(unaff_EBP - 0x1268) |
           (byte)((uVar2 & 0xff) <<
                 (('\x01' - ((byte)*(undefined4 *)(unaff_EBP - 0x1234) & 1)) * '\x04' & 0x1f));
      *(int *)(unaff_EBP - 0x1234) = *(int *)(unaff_EBP - 0x1234) + 1;
    }
    cbData = *(DWORD *)(unaff_EBP - 0x1248);
    lpData = (BYTE *)FUN_10005110((undefined4 *)(unaff_EBP - 0x1118));
    dwType = 3;
    Reserved = 0;
    lpValueName = *(LPCSTR *)(unaff_EBP + 0xc);
    hKey = (HKEY)FUN_10005120(*(undefined4 **)(unaff_EBP + 8));
    LVar3 = RegSetValueExA(hKey,lpValueName,Reserved,dwType,lpData,cbData);
    *(LSTATUS *)(unaff_EBP - 0x1230) = LVar3;
    *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
    ~CTempBuffer<>((int *)(unaff_EBP - 0x1118));
    if (*(int *)(unaff_EBP - 0x1230) == 0) {
      uVar4 = FUN_10009eb0(*(void **)(unaff_EBP - 0x1238),*(undefined1 **)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP - 0x1228) = uVar4;
    }
    else {
      *(undefined4 *)(unaff_EBP - 0x1280) = 0x204;
      FUN_10006a10(*(ulong *)(unaff_EBP - 0x1230));
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uVar2 = *(uint *)(unaff_EBP - 0x14);
  *(undefined4 *)(unaff_EBP - 0x1288) = 0x100060b1;
  __security_check_cookie(uVar2 ^ unaff_EBP);
  return;
}



// Function: Allocate at 100060c0

/* Library Function - Single Match
    public: void * __thiscall ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class
   ATL::CCRTAllocator>::Allocate(unsigned long)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void * __thiscall
ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
          (CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *this,ulong param_1)

{
  ulong uVar1;
  CAtlSafeAllocBufferNode *this_00;
  void *pvVar2;
  
  uVar1 = AtlAddThrow<unsigned_long>(param_1,8);
  this_00 = (CAtlSafeAllocBufferNode *)FUN_100061a0(uVar1);
  if (this_00 == (CAtlSafeAllocBufferNode *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
    *(undefined4 *)this_00 = *(undefined4 *)this;
    *(CAtlSafeAllocBufferNode **)this = this_00;
    pvVar2 = CAtlSafeAllocBufferNode::GetData(this_00);
  }
  return pvVar2;
}



// Function: Allocate at 10006110

/* Library Function - Multiple Matches With Same Base Name
    public: char * __thiscall ATL::CTempBuffer<char,128,class ATL::CCRTAllocator>::Allocate(unsigned
   int)
    public: unsigned char * __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::Allocate(unsigned int)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void __thiscall Allocate(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = ATL::AtlMultiplyThrow<unsigned_int>(param_1,1);
  FUN_100061c0(this,uVar1);
  return;
}



// Function: Allocate at 10006140

/* Library Function - Multiple Matches With Same Base Name
    public: char * __thiscall ATL::CTempBuffer<char,128,class ATL::CCRTAllocator>::Allocate(unsigned
   int)
    public: unsigned char * __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::Allocate(unsigned int)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void __thiscall Allocate(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = ATL::AtlMultiplyThrow<unsigned_int>(param_1,1);
  FUN_10006200(this,uVar1);
  return;
}



// Function: Allocate at 10006170

/* Library Function - Multiple Matches With Same Base Name
    public: char * __thiscall ATL::CTempBuffer<char,128,class ATL::CCRTAllocator>::Allocate(unsigned
   int)
    public: unsigned char * __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::Allocate(unsigned int)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void __thiscall Allocate(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = ATL::AtlMultiplyThrow<unsigned_int>(param_1,1);
  FUN_10006240(this,uVar1);
  return;
}



// Function: FUN_100061a0 at 100061a0

void __cdecl FUN_100061a0(size_t param_1)

{
  malloc(param_1);
  return;
}



// Function: FUN_100061c0 at 100061c0

undefined4 __thiscall FUN_100061c0(void *this,uint param_1)

{
  if (param_1 < 0x101) {
    *(int *)this = (int)this + 4;
  }
  else {
    AllocateHeap(this,param_1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10006200 at 10006200

undefined4 __thiscall FUN_10006200(void *this,uint param_1)

{
  if (param_1 < 0x401) {
    *(int *)this = (int)this + 4;
  }
  else {
    AllocateHeap(this,param_1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10006240 at 10006240

undefined4 __thiscall FUN_10006240(void *this,uint param_1)

{
  if (param_1 < 0x101) {
    *(int *)this = (int)this + 4;
  }
  else {
    AllocateHeap(this,param_1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: AllocateHeap at 10006280

/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall ATL::CTempBuffer<char,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<wchar_t,10,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __thiscall AllocateHeap(void *this,size_t param_1)

{
  int iVar1;
  
  iVar1 = FUN_100061a0(param_1);
  if (iVar1 == 0) {
    FUN_100032d0(0x8007000e);
  }
  *(int *)this = iVar1;
  return;
}



// Function: AllocateHeap at 100062c0

/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall ATL::CTempBuffer<char,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<wchar_t,10,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __thiscall AllocateHeap(void *this,size_t param_1)

{
  int iVar1;
  
  iVar1 = FUN_100061a0(param_1);
  if (iVar1 == 0) {
    FUN_100032d0(0x8007000e);
  }
  *(int *)this = iVar1;
  return;
}



// Function: AllocateHeap at 10006300

/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall ATL::CTempBuffer<char,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<wchar_t,10,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __thiscall AllocateHeap(void *this,size_t param_1)

{
  int iVar1;
  
  iVar1 = FUN_100061a0(param_1);
  if (iVar1 == 0) {
    FUN_100032d0(0x8007000e);
  }
  *(int *)this = iVar1;
  return;
}



// Function: FUN_10006340 at 10006340

undefined4 __thiscall FUN_10006340(void *this,void *param_1,rsize_t param_2)

{
  int iVar1;
  undefined4 uVar2;
  LPVOID pvVar3;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = *this + 1 + param_2;
                    /* WARNING: Load size is inaccurate */
  if ((*this < iVar1) && ((int)param_2 < iVar1)) {
    if (*(int *)((int)this + 4) <= iVar1) {
      while (*(int *)((int)this + 4) <= iVar1) {
        if (0x3fffffff < *(int *)((int)this + 4)) {
          return 0;
        }
        *(int *)((int)this + 4) = *(int *)((int)this + 4) << 1;
      }
      pvVar3 = FUN_10006510(*(LPVOID *)((int)this + 8),*(uint *)((int)this + 4),1);
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
      FUN_1000da80((void *)(*(int *)((int)this + 8) + *this),*(int *)((int)this + 4) - *this,param_1
                   ,param_2);
                    /* WARNING: Load size is inaccurate */
      *(rsize_t *)this = *this + param_2;
                    /* WARNING: Load size is inaccurate */
      *(undefined1 *)(*(int *)((int)this + 8) + *this) = 0;
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



// Function: AtlCallTermFunc at 10006460

/* Library Function - Single Match
    void __stdcall ATL::AtlCallTermFunc(struct ATL::_ATL_MODULE70 *)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void ATL::AtlCallTermFunc(_ATL_MODULE70 *param_1)

{
  undefined4 *puVar1;
  undefined4 *local_8;
  
  if (param_1 == (_ATL_MODULE70 *)0x0) {
    _AtlRaiseException(0xc0000005,1);
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



// Function: AtlCoTaskMemCAlloc at 100064d0

/* Library Function - Single Match
    void * __cdecl ATL::AtlCoTaskMemCAlloc(unsigned long,unsigned long)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void * __cdecl ATL::AtlCoTaskMemCAlloc(ulong param_1,ulong param_2)

{
  HRESULT HVar1;
  void *pvVar2;
  SIZE_T local_8;
  
  local_8 = 0;
  HVar1 = AtlMultiply<>(&local_8,param_1,param_2);
  if (HVar1 < 0) {
    pvVar2 = (void *)0x0;
  }
  else {
    pvVar2 = CoTaskMemAlloc(local_8);
  }
  return pvVar2;
}



// Function: FUN_10006510 at 10006510

LPVOID __cdecl FUN_10006510(LPVOID param_1,uint param_2,uint param_3)

{
  HRESULT HVar1;
  LPVOID pvVar2;
  SIZE_T local_8;
  
  local_8 = 0;
  HVar1 = AtlMultiply<>(&local_8,param_2,param_3);
  if (HVar1 < 0) {
    pvVar2 = (LPVOID)0x0;
  }
  else {
    pvVar2 = CoTaskMemRealloc(param_1,local_8);
  }
  return pvVar2;
}



// Function: FUN_10006550 at 10006550

int FUN_10006550(int *param_1,int *param_2,undefined4 param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  PVOID pvVar3;
  CComCritSecLock<class_ATL::CComCriticalSection> local_30 [8];
  PVOID local_28;
  undefined4 *local_24;
  int *local_20;
  undefined4 *local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013218;
  local_10 = ExceptionList;
  uVar1 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
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
           (iVar2 = FUN_100035a0(param_2,(int *)*local_1c), iVar2 != 0)) {
          local_20 = (int *)local_1c[4];
          if (*local_20 == 0) {
            ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
            CComCritSecLock<class_ATL::CComCriticalSection>
                      (local_30,(CComCriticalSection *)(param_1 + 4),false);
            local_8 = 0;
            local_14 = FUN_10009dc0((undefined4 *)local_30);
            if (local_14 < 0) {
              local_8 = 0xffffffff;
              ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
              ~CComCritSecLock<class_ATL::CComCriticalSection>(local_30);
              break;
            }
            if ((*local_20 == 0) &&
               (local_14 = (*(code *)local_1c[2])(local_1c[3],&DAT_10014c54,&local_28,uVar1),
               -1 < local_14)) {
              pvVar3 = EncodePointer(local_28);
              *local_20 = (int)pvVar3;
            }
            local_8 = 0xffffffff;
            ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
            ~CComCritSecLock<class_ATL::CComCriticalSection>(local_30);
          }
          if (*local_20 != 0) {
            local_24 = (undefined4 *)DecodePointer((PVOID)*local_20);
            local_14 = (**(code **)*local_24)(local_24,param_3,param_4);
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



// Function: FUN_10006710 at 10006710

int FUN_10006710(int param_1,int param_2,void *param_3)

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
          (bVar2 = FUN_1000dc20(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar2) != 0)))) {
        local_8 = (*(code *)puVar1[1])(1);
        if (local_8 < 0) break;
        iVar4 = 1;
        piVar3 = (int *)(*(code *)puVar1[6])();
        local_8 = FUN_10007300((GUID *)*puVar1,piVar3,iVar4);
        if (local_8 < 0) break;
      }
    }
    if ((-1 < local_8) && (param_2 != 0)) {
      local_8 = FUN_10007930(*(HMODULE *)(param_1 + 4),(wchar_t *)0x0);
    }
  }
  return local_8;
}



// Function: FUN_100067e0 at 100067e0

int FUN_100067e0(int param_1,int param_2,void *param_3)

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
          (bVar2 = FUN_1000dc20(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar2) != 0)))) {
        iVar4 = 0;
        piVar3 = (int *)(*(code *)puVar1[6])();
        local_8 = FUN_10007300((GUID *)*puVar1,piVar3,iVar4);
        if ((local_8 < 0) || (local_8 = (*(code *)puVar1[1])(0), local_8 < 0)) break;
      }
    }
    if ((-1 < local_8) && (param_2 != 0)) {
      local_8 = FUN_10007c30(*(HMODULE *)(param_1 + 4),(wchar_t *)0x0);
    }
  }
  return local_8;
}



// Function: FUN_100068b0 at 100068b0

int FUN_100068b0(int *param_1,undefined4 *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 != (int *)0x0) {
    piVar1 = (int *)*param_1;
    if ((param_2 == (undefined4 *)0x0) ||
       (iVar2 = (**(code **)*param_2)(param_2,param_3,param_1), iVar2 < 0)) {
      *param_1 = 0;
    }
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    return *param_1;
  }
  return 0;
}



// Function: AtlCrtErrorCheck at 10006910

/* Library Function - Single Match
    int __cdecl ATL::AtlCrtErrorCheck(int)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug, Visual
   Studio 2012 Debug */

int __cdecl ATL::AtlCrtErrorCheck(int param_1)

{
  switch(param_1) {
  case 0:
  case 0x50:
    break;
  default:
    FUN_100032d0(0x80004005);
    break;
  case 0xc:
    FUN_100032d0(0x8007000e);
    break;
  case 0x16:
  case 0x22:
    FUN_100032d0(0x80070057);
  }
  return param_1;
}



// Function: FUN_100069c0 at 100069c0

undefined4 FUN_100069c0(undefined1 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_1 = DAT_1001b66c;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_100069f0 at 100069f0

void FUN_100069f0(void)

{
  DWORD x;
  
  x = GetLastError();
  _HRESULT_FROM_WIN32(x);
  return;
}



// Function: FUN_10006a10 at 10006a10

void __cdecl FUN_10006a10(ulong param_1)

{
  _HRESULT_FROM_WIN32(param_1);
  return;
}



// Function: FUN_10006a30 at 10006a30

int FUN_10006a30(int param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_8;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    local_8 = -0x7ff8ffa9;
  }
  else if (param_4 == (undefined4 *)0x0) {
    local_8 = -0x7fffbffd;
  }
  else {
    iVar1 = FUN_100096c0(param_3);
    if (iVar1 == 0) {
      for (; param_2[2] != 0; param_2 = param_2 + 3) {
        iVar1 = *param_2;
        if ((iVar1 == 0) || (iVar2 = FUN_100035a0((int *)*param_2,param_3), iVar2 != 0)) {
          if (param_2[2] == 1) {
            piVar3 = (int *)(param_1 + param_2[1]);
            (**(code **)(*piVar3 + 4))(piVar3);
            *param_4 = piVar3;
            return 0;
          }
          local_8 = (*(code *)param_2[2])(param_1,param_3,param_4,param_2[1]);
          if (local_8 == 0) {
            return 0;
          }
          if ((iVar1 != 0) && (local_8 < 0)) goto LAB_10006b56;
        }
      }
      local_8 = -0x7fffbffe;
LAB_10006b56:
      *param_4 = 0;
    }
    else {
      piVar3 = (int *)(param_1 + param_2[1]);
      (**(code **)(*piVar3 + 4))(piVar3);
      *param_4 = piVar3;
      local_8 = 0;
    }
  }
  return local_8;
}



// Function: FUN_10006b70 at 10006b70

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_10006b70(HMODULE param_1,wchar_t *param_2,int *param_3,undefined4 *param_4)

{
  char cVar1;
  size_t sVar2;
  long lVar3;
  int iVar4;
  uint local_1b4;
  HRESULT local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined1 *local_1a4;
  int local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined1 *local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined1 *local_184;
  LPSTR local_180;
  LPSTR local_17c;
  size_t local_178;
  LPWSTR local_174;
  LPWSTR local_170;
  LPWSTR local_16c;
  LPWSTR local_168;
  char *local_164;
  LPWSTR local_160;
  LPWSTR local_15c;
  uint local_158;
  char *local_154;
  wchar_t *local_150;
  UINT local_14c;
  LPCSTR local_148;
  int local_144;
  LPWSTR local_140;
  DWORD local_13c;
  char *local_138;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_134 [4];
  ulong local_130;
  CHAR local_12c [272];
  char local_1c [8];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001324b;
  local_10 = ExceptionList;
  local_1b4 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_1b4;
  if ((param_3 != (int *)0x0) && (param_4 != (undefined4 *)0x0)) {
    *param_3 = 0;
    *param_4 = 0;
    local_14c = FUN_10003510();
    FUN_10003cc0((undefined4 *)local_134);
    local_8 = 0;
    local_13c = GetModuleFileNameA(param_1,local_12c,0x104);
    if (local_13c == 0) {
      local_1a8 = FUN_100069f0();
      local_8 = 0xffffffff;
      local_18c = local_1a8;
      ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
      ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_134);
    }
    else if (local_13c == 0x104) {
      local_1b0 = _HRESULT_FROM_WIN32(0x7a);
      local_8 = 0xffffffff;
      ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
      ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_134);
    }
    else {
      local_148 = (LPCSTR)0x0;
      local_148 = FUN_100038e0(local_12c);
      if (param_2 != (wchar_t *)0x0) {
        local_150 = param_2;
        if (param_2 == (wchar_t *)0x0) {
          local_164 = (char *)0x0;
        }
        else {
          sVar2 = wcslen(param_2);
          local_130 = sVar2 + 1;
          lVar3 = ATL::AtlMultiply<int>((int *)&local_130,local_130,2);
          if (lVar3 < 0) {
            local_180 = (LPSTR)0x0;
          }
          else {
            if (((int)local_130 < 0x401) && (cVar1 = FUN_1000d8f0(local_130), cVar1 != '\0')) {
              local_184 = (undefined1 *)&local_1b4;
              local_17c = (LPSTR)&local_1b4;
            }
            else {
              local_17c = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                 CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                           (local_134,local_130);
            }
            local_180 = FUN_10003300(local_17c,local_150,local_130,local_14c);
          }
          local_164 = local_180;
        }
        local_154 = local_164;
        if (local_164 == (char *)0x0) {
          local_1ac = 0x8007000e;
          local_8 = 0xffffffff;
          ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
          ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_134);
          goto LAB_100071ec;
        }
        local_178 = strlen(local_164);
        local_158 = local_13c + local_178;
        if (((local_158 < local_13c) || (local_158 < local_178)) || (0x10d < local_158)) {
          local_194 = 0x80004005;
          local_8 = 0xffffffff;
          ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
          ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_134);
          goto LAB_100071ec;
        }
        FUN_1000db50(local_12c + local_13c,0x10e - local_13c,local_154);
      }
      local_138 = local_12c;
      if (local_138 == (char *)0x0) {
        local_15c = (LPWSTR)0x0;
      }
      else {
        sVar2 = strlen(local_138);
        local_130 = sVar2 + 1;
        lVar3 = ATL::AtlMultiply<int>((int *)&local_130,local_130,2);
        if (lVar3 < 0) {
          local_16c = (LPWSTR)0x0;
        }
        else {
          if (((int)local_130 < 0x401) && (cVar1 = FUN_1000d8f0(local_130), cVar1 != '\0')) {
            local_1a4 = (undefined1 *)&local_1b4;
            local_174 = (LPWSTR)&local_1b4;
          }
          else {
            local_174 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                          (local_134,local_130);
          }
          local_16c = FUN_10003280(local_174,local_138,local_130 >> 1,local_14c);
        }
        local_15c = local_16c;
      }
      local_140 = local_15c;
      if (local_15c == (LPWSTR)0x0) {
        local_19c = 0x8007000e;
        local_8 = 0xffffffff;
        ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
        ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_134);
      }
      else {
        local_144 = Ordinal_161();
        if (local_144 < 0) {
          builtin_strncpy(local_1c,".tlb",5);
          if ((char *)0x104 < local_148 + (5 - (int)local_12c)) {
            local_188 = 0x80004005;
            local_8 = 0xffffffff;
            ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
            ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_134);
            goto LAB_100071ec;
          }
          FUN_1000db50(local_148,0x10e - ((int)local_148 - (int)local_12c),local_1c);
          local_138 = local_12c;
          if (local_138 == (char *)0x0) {
            local_170 = (LPWSTR)0x0;
          }
          else {
            sVar2 = strlen(local_138);
            local_130 = sVar2 + 1;
            lVar3 = ATL::AtlMultiply<int>((int *)&local_130,local_130,2);
            if (lVar3 < 0) {
              local_168 = (LPWSTR)0x0;
            }
            else {
              if (((int)local_130 < 0x401) && (cVar1 = FUN_1000d8f0(local_130), cVar1 != '\0')) {
                local_190 = &stack0xfffffe44;
                local_160 = (LPWSTR)&stack0xfffffe44;
              }
              else {
                local_160 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                    CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                              (local_134,local_130);
              }
              local_168 = FUN_10003280(local_160,local_138,local_130 >> 1,local_14c);
            }
            local_170 = local_168;
          }
          local_140 = local_170;
          if (local_170 == (LPWSTR)0x0) {
            local_198 = 0x8007000e;
            local_8 = 0xffffffff;
            ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
            ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_134);
            goto LAB_100071ec;
          }
          local_144 = Ordinal_161(local_170,param_4);
        }
        if (-1 < local_144) {
          iVar4 = Ordinal_2(local_140);
          *param_3 = iVar4;
          if (*param_3 == 0) {
            local_144 = -0x7ff8fff2;
            (**(code **)(*(int *)*param_4 + 8))(*param_4);
            *param_4 = 0;
          }
        }
        local_1a0 = local_144;
        local_8 = 0xffffffff;
        ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
        ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_134);
      }
    }
  }
LAB_100071ec:
  ExceptionList = local_10;
  local_1b4 = 0x10007207;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10007210 at 10007210

int FUN_10007210(int param_1,undefined4 param_2,undefined4 param_3)

{
  CComCritSecLock<class_ATL::CComCriticalSection> local_28 [8];
  undefined4 *local_20;
  undefined4 *local_1c;
  int local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013288;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 == 0) {
    local_18 = -0x7ff8ffa9;
  }
  else {
    local_18 = 0;
    local_1c = (undefined4 *)FUN_10011c40(0xc);
    if (local_1c == (undefined4 *)0x0) {
      local_18 = -0x7ff8fff2;
    }
    else {
      *local_1c = param_2;
      local_1c[1] = param_3;
      local_14 = local_1c;
      ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
      CComCritSecLock<class_ATL::CComCriticalSection>
                (local_28,(CComCriticalSection *)(param_1 + 0xc),false);
      local_8 = 0;
      local_18 = FUN_10009dc0((undefined4 *)local_28);
      if (local_18 < 0) {
        local_20 = local_14;
        operator_delete(local_14);
      }
      else {
        local_14[2] = *(undefined4 *)(param_1 + 8);
        *(undefined4 **)(param_1 + 8) = local_14;
      }
      local_8 = 0xffffffff;
      ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
      ~CComCritSecLock<class_ATL::CComCriticalSection>(local_28);
    }
  }
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10007300 at 10007300

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_10007300(GUID *param_1,int *param_2,int param_3)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  LPVOID *ppv;
  size_t sVar4;
  long lVar5;
  HKEY pHVar6;
  LPSTR pCVar7;
  LPDWORD pDVar8;
  LPDWORD pDVar9;
  DWORD *pDVar10;
  LPDWORD pDVar11;
  LPDWORD pDVar12;
  LPDWORD pDVar13;
  LPDWORD pDVar14;
  LPDWORD pDVar15;
  char *pcVar16;
  LPDWORD pDVar17;
  REGSAM RVar18;
  PFILETIME p_Var19;
  uint local_19c;
  undefined1 *local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  UINT local_184;
  CRegKey local_180 [12];
  int local_174;
  CRegKey local_170 [12];
  int *local_164;
  int *local_160;
  int *local_15c;
  LPSTR local_158;
  int *local_154;
  LPSTR local_150;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_14c [4];
  LPSTR local_148;
  wchar_t *local_144;
  LPSTR local_140;
  DWORD local_13c;
  int *local_138;
  HRESULT local_134;
  ulong local_130;
  long local_12c;
  int local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  OLECHAR local_114 [64];
  char local_94 [128];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100132dc;
  local_10 = ExceptionList;
  local_19c = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_19c;
  FUN_10003fb0(&local_128);
  local_8 = 0;
  if (param_2 == (int *)0x0) {
    local_190 = 0;
    local_8 = 0xffffffff;
    FID_conflict__bad_alloc(&local_128);
  }
  else {
    iVar3 = FUN_100035a0((int *)param_1,(int *)&DAT_10015d64);
    if (iVar3 == 0) {
      ppv = (LPVOID *)FUN_10005160(&local_128);
      local_134 = CoCreateInstance((IID *)&DAT_10016ab4,(LPUNKNOWN)0x0,1,(IID *)&DAT_10014db8,ppv);
      if (local_134 < 0) {
        local_188 = 0;
        local_8 = 0xffffffff;
        FID_conflict__bad_alloc(&local_128);
      }
      else {
        local_134 = 0;
        for (local_138 = param_2; *local_138 != 0; local_138 = local_138 + 2) {
          puVar1 = (undefined4 *)local_138[1];
          local_124 = *puVar1;
          local_120 = puVar1[1];
          local_11c = puVar1[2];
          local_118 = puVar1[3];
          if (param_3 == 0) {
            if (*local_138 == 1) {
              local_160 = (int *)FUN_10005130(&local_128);
              (**(code **)(*local_160 + 0x18))(local_160,param_1,1,&local_124);
            }
            else {
              local_15c = (int *)FUN_10005130(&local_128);
              (**(code **)(*local_15c + 0x20))(local_15c,param_1,1,&local_124);
            }
          }
          else {
            if (*local_138 == 1) {
              local_154 = (int *)FUN_10005130(&local_128);
              local_134 = (**(code **)(*local_154 + 0x14))(local_154,param_1,1,&local_124);
            }
            else {
              local_164 = (int *)FUN_10005130(&local_128);
              local_134 = (**(code **)(*local_164 + 0x1c))(local_164,param_1,1,&local_124);
            }
            if (local_134 < 0) {
              local_174 = local_134;
              local_8 = 0xffffffff;
              FID_conflict__bad_alloc(&local_128);
              goto LAB_1000790e;
            }
          }
        }
        if (param_3 == 0) {
          StringFromGUID2(param_1,local_114,0x40);
          local_184 = FUN_10003510();
          FUN_10003cc0((undefined4 *)local_14c);
          local_8._0_1_ = 1;
          local_144 = local_114;
          if (local_144 == (wchar_t *)0x0) {
            local_158 = (LPSTR)0x0;
          }
          else {
            sVar4 = wcslen(local_144);
            local_130 = sVar4 + 1;
            lVar5 = ATL::AtlMultiply<int>((int *)&local_130,local_130,2);
            if (lVar5 < 0) {
              local_148 = (LPSTR)0x0;
            }
            else {
              if (((int)local_130 < 0x401) && (cVar2 = FUN_1000d8f0(local_130), cVar2 != '\0')) {
                local_198 = (undefined1 *)&local_19c;
                local_150 = (LPSTR)&local_19c;
              }
              else {
                local_150 = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                   CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                             (local_14c,local_130);
              }
              local_148 = FUN_10003300(local_150,local_144,local_130,local_184);
            }
            local_158 = local_148;
          }
          local_140 = local_158;
          if (local_158 != (LPSTR)0x0) {
            FUN_1000db50(local_94,0x80,"CLSID\\");
            FUN_1000db20(local_94,0x80,local_140);
            FUN_1000db20(local_94,0x80,"\\Required Categories");
            ATL::CRegKey::CRegKey(local_180,(HKEY__ *)0x80000000);
            local_8._0_1_ = 2;
            ATL::CRegKey::CRegKey(local_170,(CAtlTransactionManager *)0x0);
            local_8 = CONCAT31(local_8._1_3_,3);
            local_13c = 0;
            RVar18 = 0x20019;
            pcVar16 = local_94;
            pHVar6 = (HKEY)FUN_10005120((undefined4 *)local_180);
            local_12c = FUN_1000a0d0(local_170,pHVar6,pcVar16,RVar18);
            if (local_12c == 0) {
              p_Var19 = (PFILETIME)0x0;
              pDVar17 = (LPDWORD)0x0;
              pDVar15 = (LPDWORD)0x0;
              pDVar14 = (LPDWORD)0x0;
              pDVar13 = (LPDWORD)0x0;
              pDVar12 = (LPDWORD)0x0;
              pDVar11 = (LPDWORD)0x0;
              pDVar10 = &local_13c;
              pDVar9 = (LPDWORD)0x0;
              pDVar8 = (LPDWORD)0x0;
              pCVar7 = (LPSTR)0x0;
              pHVar6 = (HKEY)FUN_10005120((undefined4 *)local_170);
              local_12c = RegQueryInfoKeyA(pHVar6,pCVar7,pDVar8,pDVar9,pDVar10,pDVar11,pDVar12,
                                           pDVar13,pDVar14,pDVar15,pDVar17,p_Var19);
              ATL::CRegKey::Close(local_170);
              if ((local_12c == 0) && (local_13c == 0)) {
                FUN_10008510(local_180,local_94);
              }
            }
            FUN_1000db50(local_94,0x80,"CLSID\\");
            FUN_1000db20(local_94,0x80,local_140);
            FUN_1000db20(local_94,0x80,"\\Implemented Categories");
            RVar18 = 0x20019;
            pcVar16 = local_94;
            pHVar6 = (HKEY)FUN_10005120((undefined4 *)local_180);
            local_12c = FUN_1000a0d0(local_170,pHVar6,pcVar16,RVar18);
            if (local_12c == 0) {
              p_Var19 = (PFILETIME)0x0;
              pDVar17 = (LPDWORD)0x0;
              pDVar15 = (LPDWORD)0x0;
              pDVar14 = (LPDWORD)0x0;
              pDVar13 = (LPDWORD)0x0;
              pDVar12 = (LPDWORD)0x0;
              pDVar11 = (LPDWORD)0x0;
              pDVar10 = &local_13c;
              pDVar9 = (LPDWORD)0x0;
              pDVar8 = (LPDWORD)0x0;
              pCVar7 = (LPSTR)0x0;
              pHVar6 = (HKEY)FUN_10005120((undefined4 *)local_170);
              local_12c = RegQueryInfoKeyA(pHVar6,pCVar7,pDVar8,pDVar9,pDVar10,pDVar11,pDVar12,
                                           pDVar13,pDVar14,pDVar15,pDVar17,p_Var19);
              ATL::CRegKey::Close(local_170);
              if ((local_12c == 0) && (local_13c == 0)) {
                FUN_10008510(local_180,local_94);
              }
            }
            local_8._0_1_ = 2;
            FUN_10004f50(local_170);
            local_8._0_1_ = 1;
            FUN_10004f50(local_180);
          }
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
          ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_14c);
        }
        local_194 = 0;
        local_8 = 0xffffffff;
        FID_conflict__bad_alloc(&local_128);
      }
    }
    else {
      local_18c = 0;
      local_8 = 0xffffffff;
      FID_conflict__bad_alloc(&local_128);
    }
  }
LAB_1000790e:
  ExceptionList = local_10;
  local_19c = 0x10007929;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10007930 at 10007930

/* WARNING: Removing unreachable block (ram,0x10007a77) */

void FUN_10007930(HMODULE param_1,wchar_t *param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  rsize_t rVar5;
  int iVar6;
  HMODULE hModule;
  undefined4 uVar7;
  wchar_t *local_23c;
  FARPROC local_234;
  undefined4 local_230;
  int local_22c;
  wchar_t *local_228;
  int local_224;
  char local_21d;
  wchar_t local_21c [259];
  undefined2 uStack_16;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013331;
  local_10 = ExceptionList;
  local_14 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10002b00(&local_230);
  local_8 = 0;
  FUN_10004100(&local_22c);
  local_8._0_1_ = 1;
  puVar2 = (undefined4 *)FUN_10005190(&local_22c);
  piVar3 = (int *)FUN_100051b0(&local_230);
  local_224 = FUN_10006b70(param_1,param_2,piVar3,puVar2);
  if (-1 < local_224) {
    local_23c = (wchar_t *)0x0;
    FUN_10002b00(&local_228);
    local_8 = CONCAT31(local_8._1_3_,2);
    piVar3 = (int *)FUN_10005150(&local_22c);
    uVar4 = FUN_100051b0(&local_228);
    local_224 = (**(code **)(*piVar3 + 0x24))(piVar3,0xffffffff,0,0,0,uVar4);
    if ((-1 < local_224) && (bVar1 = FUN_10005070((int *)&local_228), bVar1)) {
      rVar5 = FUN_10009b60(&local_228);
      FUN_1000dbb0(local_21c,0x104,local_228,rVar5);
      uStack_16 = 0;
      iVar6 = FUN_10003950(local_21c);
      if (0x207 < (uint)(iVar6 * 2)) {
        ___report_rangecheckfailure();
      }
      local_21c[iVar6] = L'\0';
      local_23c = local_21c;
    }
    local_234 = (FARPROC)0x0;
    local_21d = '\0';
    local_224 = FUN_100069c0(&local_21d);
    if (local_224 < 0) {
      local_8._0_1_ = 1;
      FUN_10002e50(&local_228);
      local_8 = (uint)local_8._1_3_ << 8;
      FID_conflict__bad_alloc(&local_22c);
      local_8 = 0xffffffff;
      FUN_10002e50(&local_230);
      goto LAB_10007c0a;
    }
    if ((local_21d == '\x01') &&
       (hModule = GetModuleHandleW(L"OLEAUT32.DLL"), hModule != (HMODULE)0x0)) {
      local_234 = GetProcAddress(hModule,"RegisterTypeLibForUser");
    }
    if (local_234 == (FARPROC)0x0) {
      local_234 = Ordinal_163_exref;
    }
    uVar4 = FUN_10003120(&local_230);
    uVar7 = FUN_100050d0(&local_22c);
    local_224 = (*local_234)(uVar7,uVar4,local_23c);
    local_8._0_1_ = 1;
    FUN_10002e50(&local_228);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__bad_alloc(&local_22c);
  local_8 = 0xffffffff;
  FUN_10002e50(&local_230);
LAB_10007c0a:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10007c30 at 10007c30

int FUN_10007c30(HMODULE param_1,wchar_t *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  HMODULE hModule;
  undefined4 local_28;
  FARPROC local_24;
  int local_20;
  int local_1c;
  int local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013370;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002b00(&local_28);
  local_8 = 0;
  FUN_10004100(&local_20);
  local_8._0_1_ = 1;
  puVar1 = (undefined4 *)FUN_10005190(&local_20);
  piVar2 = (int *)FUN_100051b0(&local_28);
  local_18 = FUN_10006b70(param_1,param_2,piVar2,puVar1);
  if (-1 < local_18) {
    piVar2 = (int *)FUN_10005150(&local_20);
    local_18 = (**(code **)(*piVar2 + 0x1c))(piVar2,&local_1c);
    if (-1 < local_18) {
      local_24 = (FARPROC)0x0;
      local_11 = '\0';
      iVar3 = FUN_100069c0(&local_11);
      local_18 = iVar3;
      if (iVar3 < 0) {
        local_8 = (uint)local_8._1_3_ << 8;
        FID_conflict__bad_alloc(&local_20);
        local_8 = 0xffffffff;
        FUN_10002e50(&local_28);
        ExceptionList = local_10;
        return iVar3;
      }
      if ((local_11 == '\x01') &&
         (hModule = GetModuleHandleW(L"OLEAUT32.DLL"), hModule != (HMODULE)0x0)) {
        local_24 = GetProcAddress(hModule,"UnRegisterTypeLibForUser");
      }
      if (local_24 == (FARPROC)0x0) {
        local_24 = Ordinal_186_exref;
      }
      local_18 = (*local_24)(local_1c,(uint)*(ushort *)(local_1c + 0x18),
                             (uint)*(ushort *)(local_1c + 0x1a),*(undefined4 *)(local_1c + 0x10),
                             *(undefined4 *)(local_1c + 0x14));
      piVar2 = (int *)FUN_10005150(&local_20);
      (**(code **)(*piVar2 + 0x30))(piVar2,local_1c);
    }
  }
  iVar3 = local_18;
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__bad_alloc(&local_20);
  local_8 = 0xffffffff;
  FUN_10002e50(&local_28);
  ExceptionList = local_10;
  return iVar3;
}



// Function: FUN_10007dd0 at 10007dd0

void __thiscall FUN_10007dd0(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return;
}



// Function: FUN_10007df0 at 10007df0

void __thiscall FUN_10007df0(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return;
}



// Function: FUN_10007e10 at 10007e10

void __thiscall FUN_10007e10(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  return;
}



// Function: FUN_10007e40 at 10007e40

undefined4 FUN_10007e40(LPCSTR param_1)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0xb < local_8) {
      return 1;
    }
    iVar1 = lstrcmpiA(param_1,(&PTR_s_AppID_10014ea8)[local_8]);
    if (iVar1 == 0) break;
    local_8 = local_8 + 1;
  }
  return 0;
}



// Function: FUN_10007e90 at 10007e90

uint __cdecl FUN_10007e90(char param_1)

{
  uint uVar1;
  
  switch(param_1) {
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
    uVar1 = (int)param_1 - 0x30;
    break;
  default:
    uVar1 = 0;
    break;
  case 'A':
  case 'B':
  case 'C':
  case 'D':
  case 'E':
  case 'F':
    uVar1 = (int)param_1 - 0x37;
    break;
  case 'a':
  case 'b':
  case 'c':
  case 'd':
  case 'e':
  case 'f':
    uVar1 = (int)param_1 - 0x57;
  }
  return uVar1;
}



// Function: FUN_10007f30 at 10007f30

void FUN_10007f30(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      (**(code **)(**(int **)(param_1 + 0xc) + 8))(*(undefined4 *)(param_1 + 0xc));
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (*(void **)(param_1 + 0x14) != (void *)0x0) {
      FID_conflict__vector_deleting_destructor_(*(void **)(param_1 + 0x14),3);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_10007fb0 at 10007fb0

undefined4 __fastcall FUN_10007fb0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_8;
  
  local_8 = 0;
  while( true ) {
    iVar1 = FUN_10008e40((int)param_1);
    if (iVar1 <= local_8) break;
    puVar2 = (undefined4 *)FUN_10008dc0(param_1,local_8);
    operator_delete__((void *)*puVar2);
    puVar2 = (undefined4 *)FUN_10009450(param_1,local_8);
    operator_delete__((void *)*puVar2);
    local_8 = local_8 + 1;
  }
  FUN_1000bcc0(param_1);
  return 0;
}



// Function: FUN_10008030 at 10008030

undefined4 FUN_10008030(int param_1)

{
  undefined4 uVar1;
  
  FUN_10009e20();
  uVar1 = FUN_10007fb0((int *)(param_1 + 4));
  FUN_1000c8e0();
  return uVar1;
}



// Function: Close at 10008070

/* Library Function - Single Match
    public: long __thiscall ATL::CRegKey::Close(void)
   
   Libraries: Visual Studio 2008 Debug, Visual Studio 2010 Debug */

long __thiscall ATL::CRegKey::Close(CRegKey *this)

{
  LSTATUS local_c;
  
  local_c = 0;
  if (*(int *)this != 0) {
    local_c = RegCloseKey(*(HKEY *)this);
    *(undefined4 *)this = 0;
  }
  *(undefined4 *)(this + 4) = 0;
  return local_c;
}



// Function: FUN_100080c0 at 100080c0

long __thiscall
FUN_100080c0(void *this,HKEY param_1,LPCSTR param_2,LPSTR param_3,DWORD param_4,REGSAM param_5,
            LPSECURITY_ATTRIBUTES param_6,DWORD *param_7)

{
  DWORD local_18;
  int local_14;
  long local_10;
  HKEY local_c;
  CRegKey *local_8;
  
  local_c = (HKEY)0x0;
  local_8 = (CRegKey *)this;
  if (*(int *)((int)this + 8) == 0) {
    local_14 = RegCreateKeyExA(param_1,param_2,0,param_3,param_4,param_5,param_6,&local_c,&local_18)
    ;
  }
  else {
    local_14 = FUN_1000a870(*(void **)((int)this + 8),param_1,param_2,0,param_3,param_4,param_5,
                            param_6,&local_c,&local_18);
  }
  local_10 = local_14;
  if (param_7 != (DWORD *)0x0) {
    *param_7 = local_18;
  }
  if (local_14 == 0) {
    local_10 = ATL::CRegKey::Close(local_8);
    *(HKEY *)local_8 = local_c;
  }
  return local_10;
}



// Function: FUN_10008170 at 10008170

undefined4 FUN_10008170(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100133a2;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    this = (void *)FUN_10011c40(0x38);
    local_8._0_1_ = 1;
    if (this != (void *)0x0) {
      FUN_10003d20(this,param_1);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    uVar1 = FUN_10008216();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@10008210 at 10008210

undefined * Catch_10008210(void)

{
  return &DAT_1000821f;
}



// Function: FUN_10008216 at 10008216

undefined4 FUN_10008216(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    FUN_1000c5e0();
    FUN_10009770();
    iVar1 = FUN_1000d850(*(int *)(unaff_EBP + -0x14));
    *(int *)(unaff_EBP + -0x18) = iVar1;
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar2 = FUN_10008800();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
    }
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar2 = FUN_1000d840();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
    }
    FUN_100097a0();
    if (*(int *)(unaff_EBP + -0x18) == 0) {
      uVar2 = (**(code **)**(undefined4 **)(unaff_EBP + -0x14))
                        (*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
    }
    if (*(int *)(unaff_EBP + -0x18) != 0) {
      *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x14);
      *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x2c);
      if (*(int *)(unaff_EBP + -0x1c) == 0) {
        *(undefined4 *)(unaff_EBP + -0x30) = 0;
      }
      else {
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x1c) + 0xc))(1);
        *(undefined4 *)(unaff_EBP + -0x30) = uVar2;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_100082f0 at 100082f0

undefined4 FUN_100082f0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100133d2;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    puVar1 = (undefined4 *)FUN_10011c40(0x2c);
    local_8._0_1_ = 1;
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10003e80(puVar1);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    uVar2 = FUN_10008396();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@10008390 at 10008390

undefined * Catch_10008390(void)

{
  return &DAT_1000839f;
}



// Function: FUN_10008396 at 10008396

undefined4 FUN_10008396(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    FUN_1000c5e0();
    FUN_10009780(*(int *)(unaff_EBP + -0x14));
    uVar1 = FUN_1000d890(*(int *)(unaff_EBP + -0x14) + 0xc);
    *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar1 = FUN_10008830();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar1 = FUN_1000d840();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    FUN_100097b0(*(int *)(unaff_EBP + -0x14));
    if (*(int *)(unaff_EBP + -0x18) == 0) {
      uVar1 = (**(code **)**(undefined4 **)(unaff_EBP + -0x14))
                        (*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    if (*(int *)(unaff_EBP + -0x18) != 0) {
      *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x14);
      *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x2c);
      if (*(int *)(unaff_EBP + -0x1c) == 0) {
        *(undefined4 *)(unaff_EBP + -0x30) = 0;
      }
      else {
        uVar1 = (**(code **)(**(int **)(unaff_EBP + -0x1c) + 0x10))(1);
        *(undefined4 *)(unaff_EBP + -0x30) = uVar1;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10008470 at 10008470

undefined4 FUN_10008470(int param_1,int param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 local_8;
  
  local_8 = 0x80004003;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
    if ((param_2 == 0) || (iVar1 = FUN_100096c0(param_3), iVar1 != 0)) {
      local_8 = (**(code **)(param_1 + 0x24))(param_2,param_3,param_4);
    }
    else {
      local_8 = 0x80040110;
    }
  }
  return local_8;
}



// Function: FUN_100084d0 at 100084d0

void FUN_100084d0(LONG *param_1)

{
  InterlockedDecrement(param_1);
  return;
}



// Function: FUN_100084f0 at 100084f0

void FUN_100084f0(LONG *param_1)

{
  InterlockedDecrement(param_1);
  return;
}



// Function: FUN_10008510 at 10008510

void __thiscall FUN_10008510(void *this,LPCSTR param_1)

{
  if (*(int *)((int)this + 8) == 0) {
                    /* WARNING: Load size is inaccurate */
    RegDeleteKeyA(*this,param_1);
  }
  else {
                    /* WARNING: Load size is inaccurate */
    FUN_1000a930(*(void **)((int)this + 8),*this,param_1);
  }
  return;
}



// Function: FUN_10008560 at 10008560

void __thiscall FUN_10008560(void *this,LPCSTR param_1)

{
                    /* WARNING: Load size is inaccurate */
  RegDeleteValueA(*this,param_1);
  return;
}



// Function: detach at 10008590

/* Library Function - Multiple Matches With Same Base Name
    public: char const * __thiscall __crt_unique_heap_ptr<char const ,struct
   __crt_internal_free_policy>::detach(void)
    public: wchar_t const * __thiscall __crt_unique_heap_ptr<wchar_t const ,struct
   __crt_internal_free_policy>::detach(void)
    public: char * __thiscall __crt_unique_heap_ptr<char,struct
   __crt_internal_free_policy>::detach(void)
    public: char * __thiscall __crt_unique_heap_ptr<char,struct
   __crt_public_free_policy>::detach(void)
     31 names - too many to list
   
   Libraries: Visual Studio 2015 Debug, Visual Studio 2017 Debug, Visual Studio 2019 Debug */

undefined4 __fastcall detach(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = 0;
  return uVar1;
}



// Function: detach at 100085c0

/* Library Function - Multiple Matches With Same Base Name
    public: char const * __thiscall __crt_unique_heap_ptr<char const ,struct
   __crt_internal_free_policy>::detach(void)
    public: wchar_t const * __thiscall __crt_unique_heap_ptr<wchar_t const ,struct
   __crt_internal_free_policy>::detach(void)
    public: char * __thiscall __crt_unique_heap_ptr<char,struct
   __crt_internal_free_policy>::detach(void)
    public: char * __thiscall __crt_unique_heap_ptr<char,struct
   __crt_public_free_policy>::detach(void)
     31 names - too many to list
   
   Libraries: Visual Studio 2015 Debug, Visual Studio 2017 Debug, Visual Studio 2019 Debug */

undefined4 __fastcall detach(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = 0;
  return uVar1;
}



// Function: detach at 100085f0

/* Library Function - Multiple Matches With Same Base Name
    public: char const * __thiscall __crt_unique_heap_ptr<char const ,struct
   __crt_internal_free_policy>::detach(void)
    public: wchar_t const * __thiscall __crt_unique_heap_ptr<wchar_t const ,struct
   __crt_internal_free_policy>::detach(void)
    public: char * __thiscall __crt_unique_heap_ptr<char,struct
   __crt_internal_free_policy>::detach(void)
    public: char * __thiscall __crt_unique_heap_ptr<char,struct
   __crt_public_free_policy>::detach(void)
     31 names - too many to list
   
   Libraries: Visual Studio 2015 Debug, Visual Studio 2017 Debug, Visual Studio 2019 Debug */

undefined4 __fastcall detach(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = 0;
  return uVar1;
}



// Function: detach at 10008620

/* Library Function - Multiple Matches With Same Base Name
    public: char const * __thiscall __crt_unique_heap_ptr<char const ,struct
   __crt_internal_free_policy>::detach(void)
    public: wchar_t const * __thiscall __crt_unique_heap_ptr<wchar_t const ,struct
   __crt_internal_free_policy>::detach(void)
    public: char * __thiscall __crt_unique_heap_ptr<char,struct
   __crt_internal_free_policy>::detach(void)
    public: char * __thiscall __crt_unique_heap_ptr<char,struct
   __crt_public_free_policy>::detach(void)
     31 names - too many to list
   
   Libraries: Visual Studio 2015 Debug, Visual Studio 2017 Debug, Visual Studio 2019 Debug */

undefined4 __fastcall detach(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = 0;
  return uVar1;
}



// Function: FUN_10008650 at 10008650

undefined4 __fastcall FUN_10008650(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = param_1[2];
  param_1[2] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  return uVar1;
}



// Function: FUN_10008690 at 10008690

undefined4 __fastcall FUN_10008690(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return uVar1;
}



// Function: FUN_100086d0 at 100086d0

undefined4 __fastcall FUN_100086d0(undefined4 *param_1)

{
  LPSTR pCVar1;
  
  if ((*(char *)*param_1 == '\'') && (pCVar1 = CharNextA((LPCSTR)*param_1), *pCVar1 != '\'')) {
    return 1;
  }
  return 0;
}



// Function: FUN_10008720 at 10008720

undefined4 __thiscall FUN_10008720(void *this,undefined4 param_1)

{
  undefined4 local_c;
  
  local_c = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    local_c = FUN_10008e60(this,param_1);
  }
  return local_c;
}



// Function: FUN_10008760 at 10008760

void __cdecl FUN_10008760(short *param_1,int param_2,short *param_3)

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



// Function: FUN_10008800 at 10008800

void FUN_10008800(void)

{
  FUN_10008830();
  FUN_10008830();
  return;
}



// Function: FUN_10008830 at 10008830

undefined4 FUN_10008830(void)

{
  return 0;
}



// Function: FUN_10008840 at 10008840

void FUN_10008840(void)

{
  FUN_100095c0();
  return;
}



// Function: FUN_10008860 at 10008860

void FUN_10008860(void)

{
  FUN_10008890();
  FUN_10008890();
  return;
}



// Function: FUN_10008890 at 10008890

void FUN_10008890(void)

{
  return;
}



// Function: FUN_100088a0 at 100088a0

int __thiscall FUN_100088a0(void *this,undefined4 *param_1)

{
  bool bVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (*(int *)((int)this + 8) <= local_8) {
      return -1;
    }
                    /* WARNING: Load size is inaccurate */
    bVar1 = FUN_100099f0(*(LPCSTR *)(*this + local_8 * 4),(LPCSTR)*param_1);
    if (bVar1) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}



// Function: Free at 10008900

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall ATL::CAutoVectorPtr<char>::Free(void)
    public: void __thiscall ATL::CAutoVectorPtr<int>::Free(void)
    public: void __thiscall ATL::CAutoVectorPtr<unsigned long>::Free(void)
    public: void __thiscall ATL::CAutoVectorPtr<void *>::Free(void)
     6 names - too many to list
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __fastcall Free(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: Free at 10008930

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall ATL::CAutoVectorPtr<char>::Free(void)
    public: void __thiscall ATL::CAutoVectorPtr<int>::Free(void)
    public: void __thiscall ATL::CAutoVectorPtr<unsigned long>::Free(void)
    public: void __thiscall ATL::CAutoVectorPtr<void *>::Free(void)
     6 names - too many to list
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __fastcall Free(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_10008960 at 10008960

void __cdecl FUN_10008960(void *param_1)

{
  free(param_1);
  return;
}



// Function: FreeHeap at 10008980

/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall ATL::CTempBuffer<char,128,class ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<wchar_t,10,class ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<wchar_t,128,class ATL::CCRTAllocator>::FreeHeap(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __fastcall FreeHeap(undefined4 *param_1)

{
  FUN_10008960((void *)*param_1);
  return;
}



// Function: FreeHeap at 100089a0

/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall ATL::CTempBuffer<char,128,class ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<wchar_t,10,class ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<wchar_t,128,class ATL::CCRTAllocator>::FreeHeap(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __fastcall FreeHeap(undefined4 *param_1)

{
  FUN_10008960((void *)*param_1);
  return;
}



// Function: FreeHeap at 100089c0

/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall ATL::CTempBuffer<char,128,class ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<wchar_t,10,class ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<wchar_t,128,class ATL::CCRTAllocator>::FreeHeap(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __fastcall FreeHeap(undefined4 *param_1)

{
  FUN_10008960((void *)*param_1);
  return;
}



// Function: FUN_100089e0 at 100089e0

undefined4 FUN_100089e0(void)

{
  return 0x80020009;
}



// Function: FUN_10008a00 at 10008a00

undefined ** FUN_10008a00(void)

{
  return &PTR_10015480;
}



// Function: FUN_10008a10 at 10008a10

int __thiscall FUN_10008a10(void *this,int *param_1,undefined4 param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  CComCritSecLock<class_ATL::CComCriticalSection> local_24 [8];
  void *local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013428;
  local_10 = ExceptionList;
  uVar1 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_3 = 0;
  local_18 = 0;
  local_1c = this;
  if (*(int *)((int)this + 0x2c) != 0) {
    for (local_14 = *(int **)((int)this + 0x2c); *local_14 != 0; local_14 = local_14 + 9) {
      if ((local_14[2] != 0) && (iVar2 = FUN_100035a0(param_1,(int *)*local_14), iVar2 != 0)) {
        if (local_14[4] == 0) {
          ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
          CComCritSecLock<class_ATL::CComCriticalSection>
                    (local_24,(CComCriticalSection *)&DAT_1001b728,false);
          local_8 = 0;
          local_18 = FUN_10009dc0((undefined4 *)local_24);
          if (local_18 < 0) {
            local_8 = 0xffffffff;
            ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
            ~CComCritSecLock<class_ATL::CComCriticalSection>(local_24);
            break;
          }
          if (local_14[4] == 0) {
            local_18 = (*(code *)local_14[2])(local_14[3],&DAT_10014c54,local_14 + 4,uVar1);
          }
          local_8 = 0xffffffff;
          ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
          ~CComCritSecLock<class_ATL::CComCriticalSection>(local_24);
        }
        if (local_14[4] != 0) {
          local_18 = (*(code *)**(undefined4 **)local_14[4])(local_14[4],param_2,param_3);
        }
        break;
      }
    }
  }
  if ((*param_3 == 0) && (local_18 == 0)) {
    local_18 = FUN_10006550((int *)&DAT_1001b718,param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return local_18;
}



// Function: GetData at 10008b80

/* Library Function - Single Match
    public: void * __thiscall ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class
   ATL::CCRTAllocator>::CAtlSafeAllocBufferNode::GetData(void)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void * __thiscall
ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
CAtlSafeAllocBufferNode::GetData(CAtlSafeAllocBufferNode *this)

{
  return this + 8;
}



// Function: FUN_10008ba0 at 10008ba0

int __thiscall FUN_10008ba0(void *this,undefined4 *param_1)

{
  int local_c;
  
  if (param_1 == (undefined4 *)0x0) {
    local_c = -0x7fffbffd;
  }
  else {
    local_c = 0;
    if (*(int *)((int)this + 0x28) == 0) {
      local_c = CoCreateInstance((IID *)&DAT_10015fa4,(LPUNKNOWN)0x0,1,(IID *)&DAT_10014c80,
                                 (LPVOID *)((int)this + 0x28));
    }
    if (-1 < local_c) {
      *param_1 = *(undefined4 *)((int)this + 0x28);
      (**(code **)(**(int **)((int)this + 0x28) + 4))(*(undefined4 *)((int)this + 0x28));
    }
  }
  return local_c;
}



// Function: FUN_10008c20 at 10008c20

void FUN_10008c20(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10008c80(&PTR_DAT_1001b128,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10008c50 at 10008c50

void FUN_10008c50(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10008c80(&PTR_DAT_1001b144,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10008c80 at 10008c80

int __thiscall
FUN_10008c80(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  size_t sVar1;
  void *_Buf1;
  int iVar2;
  size_t _Size;
  void *_Buf2;
  int local_10;
  int local_c;
  
  local_10 = FUN_10008720(this,param_4);
  if (*(int *)((int)this + 0xc) != 0) {
    local_10 = -0x7fffbffb;
    if ((*(int *)((int)this + 0x14) != 0) && (param_3 == 1)) {
      sVar1 = FUN_1000db00((wchar_t *)*param_2);
      local_c = *(int *)((int)this + 0x18);
      do {
        do {
          local_c = local_c + -1;
          if (local_c < 0) goto LAB_10008d82;
        } while (sVar1 != *(size_t *)(*(int *)((int)this + 0x14) + 4 + local_c * 0xc));
        _Size = *(int *)(*(int *)((int)this + 0x14) + 4 + local_c * 0xc) << 1;
        _Buf2 = (void *)*param_2;
        _Buf1 = (void *)FUN_10003120((undefined4 *)(*(int *)((int)this + 0x14) + local_c * 0xc));
        iVar2 = memcmp(_Buf1,_Buf2,_Size);
      } while (iVar2 != 0);
      *param_5 = *(undefined4 *)(*(int *)((int)this + 0x14) + 8 + local_c * 0xc);
      local_10 = 0;
    }
LAB_10008d82:
    if (local_10 < 0) {
      local_10 = (**(code **)(**(int **)((int)this + 0xc) + 0x28))
                           (*(undefined4 *)((int)this + 0xc),param_2,param_3,param_5);
    }
  }
  return local_10;
}



// Function: FUN_10008dc0 at 10008dc0

int __thiscall FUN_10008dc0(void *this,int param_1)

{
  if ((param_1 < 0) || (*(int *)((int)this + 8) <= param_1)) {
    ATL::_AtlRaiseException(0xc000008c,1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this + param_1 * 4;
}



// Function: FUN_10008e00 at 10008e00

undefined4 __fastcall FUN_10008e00(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10008e20 at 10008e20

undefined4 __fastcall FUN_10008e20(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_10008e40 at 10008e40

undefined4 __fastcall FUN_10008e40(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10008e60 at 10008e60

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __thiscall FUN_10008e60(void *this,undefined4 param_1)

{
  char cVar1;
  int iVar2;
  HMODULE hModule;
  size_t sVar3;
  long lVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  CHAR *lpFilename;
  DWORD nSize;
  uint local_170;
  UINT local_16c;
  undefined4 local_168;
  int local_164;
  int local_160;
  undefined1 *local_15c;
  CComCritSecLock<class_ATL::CComCriticalSection> local_158 [8];
  LPWSTR local_150;
  LPWSTR local_14c;
  DWORD local_148;
  LPWSTR local_144;
  LPWSTR local_140;
  char *local_13c;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_138 [4];
  int local_134;
  int local_130;
  int local_12c;
  int *local_128;
  ulong local_124;
  int local_120;
  undefined4 *local_11c;
  CHAR local_118 [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013487;
  local_10 = ExceptionList;
  local_170 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_11c = (undefined4 *)this;
  local_14 = local_170;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
    CComCritSecLock<class_ATL::CComCriticalSection>
              (local_158,(CComCriticalSection *)((int)DAT_1001b648 + 0x10),false);
    local_8 = 0;
    local_120 = FUN_10009dc0((undefined4 *)local_158);
    if (local_120 < 0) {
      local_8 = 0xffffffff;
      local_164 = local_120;
      ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
      ~CComCritSecLock<class_ATL::CComCriticalSection>(local_158);
    }
    else {
      local_120 = -0x7fffbffb;
      if (local_11c[3] == 0) {
        local_128 = (int *)0x0;
        iVar2 = FUN_100035a0((int *)&DAT_1001b64c,(int *)local_11c[1]);
        if (((iVar2 == 0) || (*(short *)(local_11c + 2) != -1)) ||
           (*(short *)((int)local_11c + 10) != -1)) {
          local_120 = Ordinal_162(local_11c[1],*(undefined2 *)(local_11c + 2),
                                  *(undefined2 *)((int)local_11c + 10),param_1,&local_128);
        }
        else {
          nSize = 0x104;
          lpFilename = local_118;
          hModule = (HMODULE)FUN_10008e20(0x1001b6e0);
          local_148 = GetModuleFileNameA(hModule,lpFilename,nSize);
          if ((local_148 != 0) && (local_148 != 0x104)) {
            local_16c = FUN_10003510();
            FUN_10003cc0((undefined4 *)local_138);
            local_8._0_1_ = 1;
            local_13c = local_118;
            if (local_13c == (char *)0x0) {
              local_150 = (LPWSTR)0x0;
            }
            else {
              sVar3 = strlen(local_13c);
              local_124 = sVar3 + 1;
              lVar4 = ATL::AtlMultiply<int>((int *)&local_124,local_124,2);
              if (lVar4 < 0) {
                local_14c = (LPWSTR)0x0;
              }
              else {
                if (((int)local_124 < 0x401) && (cVar1 = FUN_1000d8f0(local_124), cVar1 != '\0')) {
                  local_15c = (undefined1 *)&local_170;
                  local_140 = (LPWSTR)&local_170;
                }
                else {
                  local_140 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                      CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                                (local_138,local_124);
                }
                local_14c = FUN_10003280(local_140,local_13c,local_124 >> 1,local_16c);
              }
              local_150 = local_14c;
            }
            local_144 = local_150;
            if (local_150 == (LPWSTR)0x0) {
              local_168 = 0x8007000e;
              local_8 = (uint)local_8._1_3_ << 8;
              ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
              ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_138);
              local_8 = 0xffffffff;
              ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
              ~CComCritSecLock<class_ATL::CComCriticalSection>(local_158);
              goto LAB_10009301;
            }
            local_120 = Ordinal_161(local_150,&local_128);
            local_8 = (uint)local_8._1_3_ << 8;
            ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
            ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_138);
          }
        }
        if (-1 < local_120) {
          FUN_100040b0(&local_12c);
          local_8._0_1_ = 2;
          uVar5 = FUN_10005180(&local_12c);
          local_120 = (**(code **)(*local_128 + 0x18))(local_128,*local_11c,uVar5);
          if (-1 < local_120) {
            FUN_10004050(&local_134,&local_12c);
            local_8._0_1_ = 3;
            FUN_10004000(&local_130);
            local_8 = CONCAT31(local_8._1_3_,4);
            uVar5 = FUN_10005170(&local_130);
            puVar6 = (undefined4 *)FUN_10005140(&local_12c);
            iVar2 = QueryInterface<>(puVar6,uVar5);
            if (-1 < iVar2) {
              FUN_10003a50(&local_134,&local_130);
            }
            uVar5 = detach(&local_134);
            local_11c[3] = uVar5;
            FUN_10005980(DAT_1001b648,FUN_10007f30,local_11c);
            local_8._0_1_ = 3;
            FID_conflict__bad_alloc(&local_130);
            local_8._0_1_ = 2;
            FID_conflict__bad_alloc(&local_134);
          }
          (**(code **)(*local_128 + 8))(local_128);
          local_8 = (uint)local_8._1_3_ << 8;
          FID_conflict__bad_alloc(&local_12c);
        }
      }
      else {
        local_120 = 0;
      }
      if ((local_11c[3] != 0) && (local_11c[5] == 0)) {
        local_120 = FUN_10009b80((int *)local_11c[3]);
      }
      local_160 = local_120;
      local_8 = 0xffffffff;
      ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
      ~CComCritSecLock<class_ATL::CComCriticalSection>(local_158);
    }
  }
LAB_10009301:
  ExceptionList = local_10;
  local_170 = 0x1000931c;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10009330 at 10009330

undefined4 __thiscall FUN_10009330(void *this,undefined4 param_1,undefined4 *param_2)

{
  undefined4 local_c;
  
  if (param_2 == (undefined4 *)0x0) {
    local_c = 0x80004003;
  }
  else {
    local_c = 0;
    if (*(int *)((int)this + 0xc) == 0) {
      local_c = FUN_10008e60(this,param_1);
    }
    *param_2 = *(undefined4 *)((int)this + 0xc);
    if (*(int *)((int)this + 0xc) != 0) {
      (**(code **)(**(int **)((int)this + 0xc) + 4))(*(undefined4 *)((int)this + 0xc));
      local_c = 0;
    }
  }
  return local_c;
}



// Function: FUN_100093a0 at 100093a0

void FUN_100093a0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  FUN_100093e0(&PTR_DAT_1001b128,param_2,param_3,param_4);
  return;
}



// Function: FUN_100093c0 at 100093c0

void FUN_100093c0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  FUN_100093e0(&PTR_DAT_1001b144,param_2,param_3,param_4);
  return;
}



// Function: FUN_100093e0 at 100093e0

undefined4 __thiscall FUN_100093e0(void *this,int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = FUN_10009330(this,param_2,param_3);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: GetTypeInfoCount at 10009410

/* Library Function - Single Match
    public: virtual long __stdcall CWnd::XAccessible::GetTypeInfoCount(unsigned int *)
   
   Library: Visual Studio */

long CWnd::XAccessible::GetTypeInfoCount(uint *param_1)

{
  long lVar1;
  undefined4 *in_stack_00000008;
  
  if (in_stack_00000008 == (undefined4 *)0x0) {
    lVar1 = -0x7fffbffd;
  }
  else {
    *in_stack_00000008 = 1;
    lVar1 = 0;
  }
  return lVar1;
}



// Function: GetTypeInfoCount at 10009430

/* Library Function - Single Match
    public: virtual long __stdcall CWnd::XAccessible::GetTypeInfoCount(unsigned int *)
   
   Library: Visual Studio */

long CWnd::XAccessible::GetTypeInfoCount(uint *param_1)

{
  long lVar1;
  undefined4 *in_stack_00000008;
  
  if (in_stack_00000008 == (undefined4 *)0x0) {
    lVar1 = -0x7fffbffd;
  }
  else {
    *in_stack_00000008 = 1;
    lVar1 = 0;
  }
  return lVar1;
}



// Function: FUN_10009450 at 10009450

int __thiscall FUN_10009450(void *this,int param_1)

{
  if ((param_1 < 0) || (*(int *)((int)this + 8) <= param_1)) {
    ATL::_AtlRaiseException(0xc000008c,1);
  }
  return *(int *)((int)this + 4) + param_1 * 4;
}



// Function: FUN_10009490 at 10009490

undefined4 __cdecl FUN_10009490(LPCSTR param_1)

{
  int iVar1;
  uint local_8;
  
  local_8 = 0;
  while( true ) {
    if (0xd < local_8) {
      return 0;
    }
    iVar1 = lstrcmpiA(param_1,(&PTR_DAT_100151a0)[local_8 * 2]);
    if (iVar1 == 0) break;
    local_8 = local_8 + 1;
  }
  return *(undefined4 *)(&DAT_100151a4 + local_8 * 8);
}



// Function: FUN_100094e0 at 100094e0

bool FUN_100094e0(HKEY param_1)

{
  LSTATUS LVar1;
  DWORD local_8;
  
  local_8 = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_8,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  return LVar1 == 0 && local_8 != 0;
}



// Function: FUN_10009540 at 10009540

void FUN_10009540(LONG *param_1)

{
  InterlockedIncrement(param_1);
  return;
}



// Function: FUN_10009560 at 10009560

void FUN_10009560(LONG *param_1)

{
  InterlockedIncrement(param_1);
  return;
}



// Function: Init at 10009580

/* Library Function - Single Match
    public: long __thiscall ATL::CComCriticalSection::Init(void)
   
   Library: Visual Studio 2010 Debug */

long __thiscall ATL::CComCriticalSection::Init(CComCriticalSection *this)

{
  BOOL BVar1;
  DWORD x;
  undefined4 local_8;
  
  local_8 = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)this,0);
  if (BVar1 == 0) {
    x = GetLastError();
    local_8 = _HRESULT_FROM_WIN32(x);
  }
  return local_8;
}



// Function: FUN_100095c0 at 100095c0

undefined4 FUN_100095c0(void)

{
  return 0;
}



// Function: FUN_100095d0 at 100095d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_100095d0(void *this,int param_1,undefined4 param_2,undefined4 *param_3)

{
  int *local_c;
  int *local_8;
  
  if (param_3 != (undefined4 *)0x0) {
    _DAT_1001b64c = *param_3;
    _DAT_1001b650 = param_3[1];
    _DAT_1001b654 = param_3[2];
    _DAT_1001b658 = param_3[3];
  }
  if ((param_1 != -1) && (*(int *)((int)this + 0x2c) = param_1, *(int *)((int)this + 0x2c) != 0)) {
    for (local_c = *(int **)((int)this + 0x2c); *local_c != 0; local_c = local_c + 9) {
      (*(code *)local_c[8])(1);
    }
  }
  for (local_8 = DAT_1001b720; local_8 < DAT_1001b724; local_8 = local_8 + 1) {
    if (*local_8 != 0) {
      (**(code **)(*local_8 + 0x1c))(1);
    }
  }
  return 0;
}



// Function: FUN_10009680 at 10009680

long __fastcall FUN_10009680(CComCriticalSection *param_1)

{
  long lVar1;
  
  lVar1 = ATL::CComCriticalSection::Init(param_1);
  if (-1 < lVar1) {
    param_1[0x18] = (CComCriticalSection)0x1;
  }
  return lVar1;
}



// Function: FUN_100096b0 at 100096b0

void FUN_100096b0(void)

{
  return;
}



// Function: FUN_100096c0 at 100096c0

undefined4 FUN_100096c0(int *param_1)

{
  undefined4 local_8;
  
  if ((((*param_1 == 0) && (param_1[1] == 0)) && (param_1[2] == 0xc0)) && (param_1[3] == 0x46000000)
     ) {
    local_8 = 1;
  }
  else {
    local_8 = 0;
  }
  return local_8;
}



// Function: FUN_10009730 at 10009730

void __fastcall FUN_10009730(LONG *param_1)

{
  FUN_10009540(param_1);
  return;
}



// Function: FUN_10009750 at 10009750

void __fastcall FUN_10009750(LONG *param_1)

{
  FUN_10009560(param_1);
  return;
}



// Function: FUN_10009770 at 10009770

void FUN_10009770(void)

{
  return;
}



// Function: FUN_10009780 at 10009780

void __fastcall FUN_10009780(int param_1)

{
  FUN_10009730((LONG *)(param_1 + 0xc));
  return;
}



// Function: FUN_100097a0 at 100097a0

void FUN_100097a0(void)

{
  return;
}



// Function: FUN_100097b0 at 100097b0

void __fastcall FUN_100097b0(int param_1)

{
  FUN_10009800((LONG *)(param_1 + 0xc));
  return;
}



// Function: FUN_100097d0 at 100097d0

int FUN_100097d0(int param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  
  iVar1 = FUN_10006a30(param_1,param_2,param_3,param_4);
  return iVar1;
}



// Function: FUN_10009800 at 10009800

void __fastcall FUN_10009800(LONG *param_1)

{
  FUN_100084d0(param_1);
  return;
}



// Function: FUN_10009820 at 10009820

void __fastcall FUN_10009820(LONG *param_1)

{
  FUN_100084f0(param_1);
  return;
}



// Function: FUN_10009840 at 10009840

void __thiscall FUN_10009840(void *this,int param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100134e3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  pvVar1 = (void *)FUN_10003a10(4,*this + param_1 * 4);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_10004310(pvVar1,param_2);
  }
  local_8 = 0xffffffff;
  pvVar1 = (void *)FUN_10003a20(4,*(int *)((int)this + 4) + param_1 * 4);
  local_8 = 1;
  if (pvVar1 != (void *)0x0) {
    FUN_10004330(pvVar1,param_3);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10009910 at 10009910

void FUN_10009910(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined2 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10009990(&PTR_DAT_1001b128,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10009950 at 10009950

void FUN_10009950(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined2 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10009990(&PTR_DAT_1001b144,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10009990 at 10009990

undefined4 __thiscall
FUN_10009990(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined2 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  undefined4 local_c;
  
  local_c = FUN_10008720(this,param_4);
  if (*(int *)((int)this + 0xc) != 0) {
    local_c = (**(code **)(**(int **)((int)this + 0xc) + 0x2c))
                        (*(undefined4 *)((int)this + 0xc),param_1,param_2,param_5,param_6,param_7,
                         param_8,param_9);
  }
  return local_c;
}



// Function: FUN_100099f0 at 100099f0

bool __cdecl FUN_100099f0(LPCSTR param_1,LPCSTR param_2)

{
  int iVar1;
  
  iVar1 = lstrcmpiA(param_1,param_2);
  return iVar1 == 0;
}



// Function: FUN_10009a10 at 10009a10

undefined1 __thiscall FUN_10009a10(void *this,undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int local_20;
  int local_1c;
  undefined4 *local_18;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013510;
  local_10 = ExceptionList;
  uVar1 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*this == 0) && (param_1 == (undefined4 *)0x0)) {
    local_11 = 1;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if ((*this == 0) || (param_1 == (undefined4 *)0x0)) {
      local_11 = 0;
    }
    else {
      local_18 = (undefined4 *)this;
      FUN_10004150(&local_20);
      local_8 = 0;
      FUN_10004150(&local_1c);
      local_8._0_1_ = 1;
      uVar2 = FUN_100051a0(&local_20);
      (*(code *)**(undefined4 **)*local_18)(*local_18,&DAT_10014c54,uVar2,uVar1);
      uVar2 = FUN_100051a0(&local_1c);
      (**(code **)*param_1)(param_1,&DAT_10014c54,uVar2);
      iVar3 = FUN_100050e0(&local_1c);
      local_11 = FUN_10005020(&local_20,iVar3);
      local_8 = (uint)local_8._1_3_ << 8;
      FID_conflict__bad_alloc(&local_1c);
      local_8 = 0xffffffff;
      FID_conflict__bad_alloc(&local_20);
    }
  }
  ExceptionList = local_10;
  return local_11;
}



// Function: FUN_10009b00 at 10009b00

undefined4 FUN_10009b00(undefined1 param_1)

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



// Function: FUN_10009b60 at 10009b60

void __fastcall FUN_10009b60(undefined4 *param_1)

{
  Ordinal_7(*param_1);
  return;
}



// Function: FUN_10009b80 at 10009b80

undefined4 FUN_10009b80(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t *pwVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint *local_34;
  int local_30;
  undefined4 local_2c;
  uint *local_28;
  uint local_24;
  uint *local_20;
  int local_1c;
  uint *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001354a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = (**(code **)(*param_1 + 0xc))(param_1,&local_30,DAT_1001b638 ^ (uint)&stack0xfffffffc);
  if (-1 < iVar1) {
    local_18 = (uint *)0x0;
    *(uint *)(local_1c + 0x18) = (uint)*(ushort *)(local_30 + 0x2c);
    *(undefined4 *)(local_1c + 0x14) = 0;
    if (*(int *)(local_1c + 0x18) != 0) {
      local_24 = *(uint *)(local_1c + 0x18);
      uVar4 = -(uint)((int)((ulonglong)local_24 * 0xc >> 0x20) != 0) |
              (uint)((ulonglong)local_24 * 0xc);
      local_20 = (uint *)FUN_10011c6e(-(uint)(0xfffffffb < uVar4) | uVar4 + 4);
      local_8 = 0;
      if (local_20 == (uint *)0x0) {
        local_34 = (uint *)0x0;
      }
      else {
        *local_20 = local_24;
        _eh_vector_constructor_iterator_
                  (local_20 + 1,0xc,local_24,FUN_10004720,FID_conflict__bad_alloc);
        local_34 = local_20 + 1;
      }
      local_8 = 0xffffffff;
      local_18 = local_34;
      if (local_34 == (uint *)0x0) {
        (**(code **)(*param_1 + 0x4c))(param_1,local_30);
        ExceptionList = local_10;
        return 0x8007000e;
      }
    }
    for (local_14 = 0; local_14 < *(int *)(local_1c + 0x18); local_14 = local_14 + 1) {
      iVar1 = (**(code **)(*param_1 + 0x14))(param_1,local_14,&local_28);
      if (-1 < iVar1) {
        FUN_10002b00(&local_2c);
        local_8 = 1;
        uVar7 = 0;
        uVar6 = 0;
        uVar5 = 0;
        uVar2 = FUN_100051b0(&local_2c);
        iVar1 = (**(code **)(*param_1 + 0x30))(param_1,*local_28,uVar2,uVar5,uVar6,uVar7);
        if (-1 < iVar1) {
          pwVar3 = (wchar_t *)detach(&local_2c);
          ATL::CComBSTR::Attach((CComBSTR *)(local_18 + local_14 * 3),pwVar3);
          uVar2 = FUN_10003120(local_18 + local_14 * 3);
          uVar4 = Ordinal_7(uVar2);
          local_18[local_14 * 3 + 1] = uVar4;
          local_18[local_14 * 3 + 2] = *local_28;
        }
        (**(code **)(*param_1 + 0x50))(param_1,local_28);
        local_8 = 0xffffffff;
        FUN_10002e50(&local_2c);
      }
    }
    *(uint **)(local_1c + 0x14) = local_18;
    (**(code **)(*param_1 + 0x4c))(param_1,local_30);
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_10009dc0 at 10009dc0

int __fastcall FUN_10009dc0(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_10003400((LPCRITICAL_SECTION)*param_1);
  if (-1 < iVar1) {
    *(undefined1 *)(param_1 + 1) = 1;
    iVar1 = 0;
  }
  return iVar1;
}



// Function: FUN_10009e00 at 10009e00

void __fastcall FUN_10009e00(int param_1)

{
  FUN_10009540((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10009e20 at 10009e20

undefined4 FUN_10009e20(void)

{
  return 0;
}



// Function: FUN_10009e30 at 10009e30

undefined4 FUN_10009e30(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    (**(code **)(*DAT_1001b648 + 8))();
  }
  else {
    (**(code **)(*DAT_1001b648 + 4))();
  }
  return 0;
}



// Function: FUN_10009e70 at 10009e70

undefined4 __thiscall FUN_10009e70(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_100088a0(this,param_1);
  if (iVar1 == -1) {
    uVar2 = 0;
  }
  else {
    puVar3 = (undefined4 *)FUN_10009450(this,iVar1);
    uVar2 = *puVar3;
  }
  return uVar2;
}



// Function: FUN_10009eb0 at 10009eb0

undefined4 __thiscall FUN_10009eb0(void *this,undefined1 *param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  LPSTR pCVar3;
  int iVar4;
  int local_18;
  int local_14;
  undefined1 *local_10;
  undefined1 *local_c;
  
  puVar1 = param_1;
  FUN_1000c6b0((undefined4 *)this);
                    /* WARNING: Load size is inaccurate */
  if (**this == '\0') {
    uVar2 = FUN_100089e0();
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if (**this == '\'') {
                    /* WARNING: Load size is inaccurate */
      pCVar3 = CharNextA(*this);
      *(LPSTR *)this = pCVar3;
                    /* WARNING: Load size is inaccurate */
      while ((**this != '\0' && (iVar4 = FUN_100086d0((undefined4 *)this), iVar4 == 0))) {
                    /* WARNING: Load size is inaccurate */
        if (**this == '\'') {
                    /* WARNING: Load size is inaccurate */
          pCVar3 = CharNextA(*this);
          *(LPSTR *)this = pCVar3;
        }
                    /* WARNING: Load size is inaccurate */
        local_c = *this;
                    /* WARNING: Load size is inaccurate */
        pCVar3 = CharNextA(*this);
        *(LPSTR *)this = pCVar3;
                    /* WARNING: Load size is inaccurate */
        iVar4 = *this - (int)local_c;
        if (puVar1 + 0x1000 <= param_1 + iVar4 + 1) {
          uVar2 = FUN_100089e0();
          return uVar2;
        }
        for (local_14 = 0; local_14 < iVar4; local_14 = local_14 + 1) {
          *param_1 = *local_c;
          param_1 = param_1 + 1;
          local_c = local_c + 1;
        }
      }
                    /* WARNING: Load size is inaccurate */
      if (**this == '\0') {
        uVar2 = FUN_100089e0();
        return uVar2;
      }
      *param_1 = 0;
                    /* WARNING: Load size is inaccurate */
      pCVar3 = CharNextA(*this);
      *(LPSTR *)this = pCVar3;
    }
    else {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      while ((**this != '\0' && (iVar4 = FUN_10009b00(**this), iVar4 == 0))) {
                    /* WARNING: Load size is inaccurate */
        local_10 = *this;
                    /* WARNING: Load size is inaccurate */
        pCVar3 = CharNextA(*this);
        *(LPSTR *)this = pCVar3;
                    /* WARNING: Load size is inaccurate */
        iVar4 = *this - (int)local_10;
        if (puVar1 + 0x1000 <= param_1 + iVar4 + 1) {
          uVar2 = FUN_100089e0();
          return uVar2;
        }
        for (local_18 = 0; local_18 < iVar4; local_18 = local_18 + 1) {
          *param_1 = *local_10;
          param_1 = param_1 + 1;
          local_10 = local_10 + 1;
        }
      }
      *param_1 = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_1000a0d0 at 1000a0d0

long __thiscall FUN_1000a0d0(void *this,HKEY param_1,LPCSTR param_2,REGSAM param_3)

{
  int local_14;
  long local_10;
  HKEY local_c;
  CRegKey *local_8;
  
  local_c = (HKEY)0x0;
  local_8 = (CRegKey *)this;
  if (*(int *)((int)this + 8) == 0) {
    local_14 = RegOpenKeyExA(param_1,param_2,0,param_3,&local_c);
  }
  else {
    local_14 = FUN_1000a9c0(*(void **)((int)this + 8),param_1,param_2,0,param_3,&local_c);
  }
  local_10 = local_14;
  if (local_14 == 0) {
    local_10 = ATL::CRegKey::Close(local_8);
    *(HKEY *)local_8 = local_c;
  }
  return local_10;
}



// Function: FUN_1000a160 at 1000a160

void __fastcall FUN_1000a160(undefined4 *param_1)

{
  (**(code **)(*(int *)*param_1 + 4))(*param_1);
  return;
}



// Function: FUN_1000a180 at 1000a180

void __thiscall FUN_1000a180(void *this,undefined4 param_1,undefined4 param_2)

{
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
  (**(code **)**this)(*this,param_1,param_2);
  return;
}



// Function: FUN_1000a1b0 at 1000a1b0

void __fastcall FUN_1000a1b0(undefined4 *param_1)

{
  (**(code **)(*(int *)*param_1 + 8))(*param_1);
  return;
}



// Function: FUN_1000a1d0 at 1000a1d0

void __thiscall FUN_1000a1d0(void *this,char *param_1,undefined4 *param_2)

{
  size_t sVar1;
  LPSTR pCVar2;
  int iVar3;
  wchar_t *pwVar4;
  undefined4 uVar5;
  undefined4 local_5c [2];
  int local_54;
  char *local_50;
  LPCSTR local_4c;
  int local_48;
  char local_41;
  int local_40;
  char local_3a;
  char local_39;
  int *local_38;
  undefined1 local_34 [32];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013578;
  local_10 = ExceptionList;
  local_14 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = (int *)this;
  if ((param_1 != (char *)0x0) && (param_2 != (undefined4 *)0x0)) {
    *param_2 = 0;
    sVar1 = strlen(param_1);
    FUN_10004520(local_5c,sVar1 << 1);
    local_8 = 0;
    if (local_54 == 0) {
      local_8 = 0xffffffff;
      FUN_10004f30((int)local_5c);
    }
    else {
      *local_38 = (int)param_1;
      local_40 = 0;
      local_41 = '\0';
      local_40 = FUN_100069c0(&local_41);
      if (local_40 < 0) {
        local_8 = 0xffffffff;
        FUN_10004f30((int)local_5c);
      }
      else {
        local_48 = 0;
        local_3a = '\0';
        local_39 = '\0';
        while (*(char *)*local_38 != '\0') {
          if (local_41 == '\x01') {
            if (local_48 == 0) {
              local_50 = (char *)0x0;
              local_50 = _tcschr((char *)*local_38,0x10015210);
              if ((local_50 != (char *)0x0) && (local_50 == (char *)*local_38)) {
                pCVar2 = CharNextA((LPCSTR)*local_38);
                *local_38 = (int)pCVar2;
                pCVar2 = CharNextA((LPCSTR)*local_38);
                *local_38 = (int)pCVar2;
                pCVar2 = CharNextA((LPCSTR)*local_38);
                *local_38 = (int)pCVar2;
                pCVar2 = CharNextA((LPCSTR)*local_38);
                *local_38 = (int)pCVar2;
                iVar3 = FUN_10005810(local_5c,L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses");
                if (iVar3 == 0) {
                  local_40 = -0x7ff8fff2;
                  break;
                }
                local_3a = '\x01';
              }
            }
            if (*(char *)*local_38 == '\'') {
              if (local_39 == '\0') {
                local_39 = '\x01';
              }
              else {
                iVar3 = FUN_100086d0(local_38);
                if (iVar3 == 0) {
                  pCVar2 = CharNextA((LPCSTR)*local_38);
                  *local_38 = (int)pCVar2;
                  iVar3 = FUN_10005540(local_5c,(LPCSTR)*local_38);
                  if (iVar3 == 0) {
                    local_40 = -0x7ff8fff2;
                    break;
                  }
                }
                else {
                  local_39 = '\0';
                }
              }
            }
            if ((local_39 == '\0') && (*(char *)*local_38 == '{')) {
              local_48 = local_48 + 1;
            }
            if ((((local_39 == '\0') && (*(char *)*local_38 == '}')) &&
                (local_48 = local_48 + -1, local_48 == 0)) && (local_3a == '\x01')) {
              iVar3 = FUN_10005810(local_5c,L"\r\n\t}\r\n}\r\n");
              if (iVar3 == 0) {
                local_40 = -0x7ff8fff2;
                break;
              }
              local_3a = '\0';
            }
          }
          if (*(char *)*local_38 == '%') {
            pCVar2 = CharNextA((LPCSTR)*local_38);
            *local_38 = (int)pCVar2;
            if (*(char *)*local_38 == '%') {
              iVar3 = FUN_10005540(local_5c,(LPCSTR)*local_38);
              if (iVar3 == 0) {
                local_40 = -0x7ff8fff2;
                break;
              }
            }
            else {
              local_4c = FUN_1000c6f0((LPSTR)*local_38,'%');
              if (local_4c == (LPCSTR)0x0) {
                local_40 = FUN_100089e0();
                break;
              }
              if (0x1f < (int)local_4c - *local_38) {
                local_40 = -0x7fffbffb;
                break;
              }
              ATL::Checked::memmove_s(local_34,0x20,(void *)*local_38,(int)local_4c - *local_38);
              pwVar4 = (wchar_t *)FUN_1000c740(local_38[1]);
              if (pwVar4 == (wchar_t *)0x0) {
                local_40 = FUN_100089e0();
                break;
              }
              iVar3 = FUN_10005810(local_5c,pwVar4);
              if (iVar3 == 0) {
                local_40 = -0x7ff8fff2;
                break;
              }
              while ((LPCSTR)*local_38 != local_4c) {
                pCVar2 = CharNextA((LPCSTR)*local_38);
                *local_38 = (int)pCVar2;
              }
            }
          }
          else {
            iVar3 = FUN_10005540(local_5c,(LPCSTR)*local_38);
            if (iVar3 == 0) {
              local_40 = -0x7ff8fff2;
              break;
            }
          }
          pCVar2 = CharNextA((LPCSTR)*local_38);
          *local_38 = (int)pCVar2;
        }
        if (-1 < local_40) {
          uVar5 = FUN_10008650(local_5c);
          *param_2 = uVar5;
        }
        local_8 = 0xffffffff;
        FUN_10004f30((int)local_5c);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000a5e0 at 1000a5e0

long FUN_1000a5e0(int *param_1,_GUID *param_2,void **param_3)

{
  int iVar1;
  long local_8;
  
  if (param_3 == (void **)0x0) {
    local_8 = -0x7fffbffd;
  }
  else {
    *param_3 = (void *)0x0;
    local_8 = 0;
    iVar1 = FUN_100096c0((int *)param_2);
    if (iVar1 == 0) {
      local_8 = ATL::CAccessibleProxy::_InternalQueryInterface
                          ((CAccessibleProxy *)(param_1 + 3),param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return local_8;
}



// Function: FUN_1000a650 at 1000a650

void FUN_1000a650(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000a180((void *)(param_1 + 0xc),param_2,param_3);
  return;
}



// Function: FUN_1000a66a at 1000a66a

void FUN_1000a66a(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000a650(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_1000a674 at 1000a674

void FUN_1000a674(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000a650(param_1 + -8,param_2,param_3);
  return;
}



// Function: QueryInterface at 1000a680

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::CAccessibleProxy::_InternalQueryInterface
                    ((CAccessibleProxy *)param_1,(_GUID *)param_2,in_stack_0000000c);
  return lVar1;
}



// Function: FUN_1000a697 at 1000a697

void FUN_1000a697(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_1000a6a1 at 1000a6a1

void FUN_1000a6a1(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -8),param_2);
  return;
}



// Function: QueryInterface at 1000a6b0

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::CAccessibleProxy::_InternalQueryInterface
                    ((CAccessibleProxy *)param_1,(_GUID *)param_2,in_stack_0000000c);
  return lVar1;
}



// Function: FUN_1000a6d0 at 1000a6d0

undefined4 FUN_1000a6d0(void)

{
  return 0x80004001;
}



// Function: FUN_1000a6e0 at 1000a6e0

void FUN_1000a6e0(LPCSTR param_1)

{
  LSTATUS LVar1;
  _FILETIME local_140;
  undefined4 local_138;
  long local_134;
  int local_130;
  HKEY local_12c [3];
  DWORD local_120;
  undefined4 *local_11c;
  long local_118;
  CHAR local_114 [256];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100135ab;
  local_10 = ExceptionList;
  local_14 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  ATL::CRegKey::CRegKey((CRegKey *)local_12c,(CAtlTransactionManager *)0x0);
  local_8 = 0;
  local_118 = FUN_1000a0d0(local_12c,(HKEY)*local_11c,param_1,local_11c[1] | 0x2001f);
  if (local_118 == 0) {
    do {
      local_120 = 0x100;
      LVar1 = RegEnumKeyExA(local_12c[0],0,local_114,&local_120,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0
                            ,&local_140);
      if (LVar1 != 0) {
        ATL::CRegKey::Close((CRegKey *)local_12c);
        local_138 = FUN_10008510(local_11c,param_1);
        local_8 = 0xffffffff;
        FUN_10004f50((CRegKey *)local_12c);
        goto LAB_1000a84b;
      }
      local_118 = FUN_1000a6e0(local_114);
    } while (local_118 == 0);
    local_8 = 0xffffffff;
    local_130 = local_118;
    FUN_10004f50((CRegKey *)local_12c);
  }
  else {
    local_8 = 0xffffffff;
    local_134 = local_118;
    FUN_10004f50((CRegKey *)local_12c);
  }
LAB_1000a84b:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000a870 at 1000a870

LSTATUS __thiscall
FUN_1000a870(void *this,HKEY param_1,LPCSTR param_2,DWORD param_3,LPSTR param_4,DWORD param_5,
            REGSAM param_6,LPSECURITY_ATTRIBUTES param_7,PHKEY param_8,LPDWORD param_9)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
      LVar3 = RegCreateKeyExA(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                              param_9);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleA("Advapi32.dll");
    if (hModule == (HMODULE)0x0) {
      return 1;
    }
    pFVar1 = GetProcAddress(hModule,"RegCreateKeyTransactedA");
    if (pFVar1 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      iVar2 = (*pFVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                        *this,0);
      return iVar2;
    }
  }
  return 1;
}



// Function: FUN_1000a930 at 1000a930

LSTATUS __thiscall FUN_1000a930(void *this,HKEY param_1,LPCSTR param_2)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
      LVar3 = RegDeleteKeyA(param_1,param_2);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleA("Advapi32.dll");
    if (hModule == (HMODULE)0x0) {
      return 1;
    }
    pFVar1 = GetProcAddress(hModule,"RegDeleteKeyTransactedA");
    if (pFVar1 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      iVar2 = (*pFVar1)(param_1,param_2,0,0,*this,0);
      return iVar2;
    }
  }
  return 1;
}



// Function: FUN_1000a9c0 at 1000a9c0

LSTATUS __thiscall
FUN_1000a9c0(void *this,HKEY param_1,LPCSTR param_2,DWORD param_3,REGSAM param_4,PHKEY param_5)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
      LVar3 = RegOpenKeyExA(param_1,param_2,param_3,param_4,param_5);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleA("Advapi32.dll");
    if (hModule == (HMODULE)0x0) {
      return 1;
    }
    pFVar1 = GetProcAddress(hModule,"RegOpenKeyTransactedA");
    if (pFVar1 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      iVar2 = (*pFVar1)(param_1,param_2,param_3,param_4,param_5,*this,0);
      return iVar2;
    }
  }
  return 1;
}



// Function: FUN_1000aa60 at 1000aa60

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_1000aa60(void *this,char *param_1,int param_2)

{
  undefined4 uVar1;
  LPVOID local_1018;
  HKEY local_1014;
  undefined4 *local_1010;
  int local_100c;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  local_100c = 0;
  local_1018 = (LPVOID)0x0;
  local_1010 = (undefined4 *)this;
  local_100c = FUN_1000a1d0(this,param_1,&local_1018);
  if (-1 < local_100c) {
    *local_1010 = local_1018;
    while( true ) {
      if ((*(char *)*local_1010 == '\0') ||
         (local_100c = FUN_10009eb0(local_1010,local_1008), local_100c < 0)) goto LAB_1000ac48;
      local_1014 = (HKEY)FUN_10009490(local_1008);
      if (local_1014 == (HKEY)0x0) break;
      local_100c = FUN_10009eb0(local_1010,local_1008);
      if (local_100c < 0) goto LAB_1000ac48;
      if (local_1008[0] != '{') {
        local_100c = FUN_100089e0();
        goto LAB_1000ac48;
      }
      if (param_2 == 0) {
        local_100c = FUN_1000b160(local_1008,local_1014,0,0);
        if (local_100c < 0) goto LAB_1000ac48;
      }
      else {
        uVar1 = *local_1010;
        local_100c = FUN_1000b160(local_1008,local_1014,param_2,0);
        if (local_100c < 0) {
          *local_1010 = uVar1;
          FUN_1000b160(local_1008,local_1014,0,0);
          goto LAB_1000ac48;
        }
      }
      FUN_1000c6b0(local_1010);
    }
    local_100c = FUN_100089e0();
LAB_1000ac48:
    CoTaskMemFree(local_1018);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000ac70 at 1000ac70

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1000ac70(wchar_t *param_1,LPCSTR param_2,LPCSTR param_3)

{
  char cVar1;
  size_t sVar2;
  long lVar3;
  uint uStack_47c;
  undefined1 local_46c [8];
  undefined4 local_464;
  undefined1 *local_460;
  undefined4 local_45c;
  undefined4 uStack_458;
  HGLOBAL local_454;
  UINT local_450;
  LPCSTR local_44c;
  LPSTR local_448;
  HGLOBAL local_444;
  LPSTR local_440;
  LPCSTR local_43c;
  HRSRC local_438;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_434 [4];
  wchar_t *local_430;
  undefined4 local_42c;
  DWORD local_428;
  ulong local_424;
  HMODULE local_420;
  int local_41c [257];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100135f6;
  local_10 = ExceptionList;
  uStack_47c = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_47c;
  ExceptionList = &local_10;
  local_18 = uStack_47c;
  local_450 = FUN_10003510();
  FUN_10003cc0((undefined4 *)local_434);
  local_8 = 0;
  FUN_10004650(local_46c,local_464);
  FUN_100042d0(local_41c);
  local_8._0_1_ = 1;
  local_430 = param_1;
  if (param_1 == (wchar_t *)0x0) {
    local_44c = (LPCSTR)0x0;
    goto LAB_1000adda;
  }
  sVar2 = wcslen(param_1);
  local_424 = sVar2 + 1;
  lVar3 = ATL::AtlMultiply<int>((int *)&local_424,local_424,2);
  if (lVar3 < 0) {
    local_440 = (LPSTR)0x0;
  }
  else {
    if ((int)local_424 < 0x401) {
      cVar1 = FUN_1000d8f0(local_424);
      if (cVar1 == '\0') goto LAB_1000ad8f;
      local_460 = (undefined1 *)&uStack_47c;
      local_448 = (LPSTR)&uStack_47c;
      local_14 = (undefined1 *)&uStack_47c;
    }
    else {
LAB_1000ad8f:
      local_448 = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                         CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                   (local_434,local_424);
    }
    local_440 = FUN_10003300(local_448,local_430,local_424,local_450);
  }
  local_44c = local_440;
LAB_1000adda:
  local_43c = local_44c;
  if (local_44c == (LPCSTR)0x0) {
    local_45c = 0x8007000e;
    local_8 = (uint)local_8._1_3_ << 8;
    ~CTempBuffer<>(local_41c);
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_434);
  }
  else {
    local_420 = LoadLibraryExA(local_44c,(HANDLE)0x0,0x60);
    if (local_420 == (HMODULE)0x0) {
      local_420 = LoadLibraryExA(local_43c,(HANDLE)0x0,2);
    }
    if (local_420 == (HMODULE)0x0) {
      local_42c = FUN_100069f0();
    }
    else {
      local_438 = FindResourceA(local_420,param_2,param_3);
      if (local_438 == (HRSRC)0x0) {
        local_42c = FUN_100069f0();
      }
      else {
        local_444 = LoadResource(local_420,local_438);
        if (local_444 == (HGLOBAL)0x0) {
          local_42c = FUN_100069f0();
        }
        else {
          local_428 = SizeofResource(local_420,local_438);
          local_454 = local_444;
          if (local_428 <= local_428 + 1) {
            local_8 = CONCAT31(local_8._1_3_,2);
            Allocate(local_41c,local_428 + 1);
            FUN_1000af43();
            return;
          }
          local_42c = 0x8007000e;
        }
      }
    }
    if (local_420 != (HMODULE)0x0) {
      FreeLibrary(local_420);
    }
    uStack_458 = local_42c;
    local_8 = (uint)local_8._1_3_ << 8;
    ~CTempBuffer<>(local_41c);
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_434);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000af3d at 1000af3d

undefined * Catch_1000af3d(void)

{
  return &DAT_1000af4c;
}



// Function: FUN_1000af43 at 1000af43

/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000af43(void)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint unaff_EBP;
  rsize_t rVar6;
  void *pvVar7;
  rsize_t rVar8;
  
  *(undefined4 *)(unaff_EBP - 4) = 1;
  iVar2 = FUN_10005100((undefined4 *)(unaff_EBP - 0x418));
  if (iVar2 == 0) {
    *(undefined4 *)(unaff_EBP - 0x428) = 0x8007000e;
  }
  else {
    rVar8 = *(rsize_t *)(unaff_EBP - 0x424);
    pvVar7 = *(void **)(unaff_EBP - 0x450);
    rVar6 = *(rsize_t *)(unaff_EBP - 0x424);
    pvVar3 = (void *)FUN_10005100((undefined4 *)(unaff_EBP - 0x418));
    FUN_1000da80(pvVar3,rVar6,pvVar7,rVar8);
    iVar2 = FUN_10005100((undefined4 *)(unaff_EBP - 0x418));
    *(undefined1 *)(iVar2 + *(int *)(unaff_EBP - 0x424)) = 0;
    iVar2 = *(int *)(unaff_EBP + 0x14);
    pcVar4 = (char *)FUN_10005100((undefined4 *)(unaff_EBP - 0x418));
    uVar5 = FUN_1000aa60((void *)(unaff_EBP - 0x468),pcVar4,iVar2);
    *(undefined4 *)(unaff_EBP - 0x428) = uVar5;
  }
  if (*(int *)(unaff_EBP - 0x41c) != 0) {
    FreeLibrary(*(HMODULE *)(unaff_EBP - 0x41c));
  }
  *(undefined4 *)(unaff_EBP - 0x454) = *(undefined4 *)(unaff_EBP - 0x428);
  *(undefined1 *)(unaff_EBP - 4) = 0;
  ~CTempBuffer<>((int *)(unaff_EBP - 0x418));
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP - 0x430));
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uVar1 = *(uint *)(unaff_EBP - 0x14);
  *(undefined4 *)(unaff_EBP - 0x46c) = 0x1000b034;
  __security_check_cookie(uVar1 ^ unaff_EBP);
  return;
}



// Function: FUN_1000b040 at 1000b040

int FUN_1000b040(int param_1,void *param_2)

{
  int local_8;
  
  local_8 = FUN_1000b090(&DAT_1001b718,param_1,param_2);
  if ((-1 < local_8) && (DAT_1001b664 != (code *)0x0)) {
    local_8 = (*DAT_1001b664)(DAT_1001b6e4);
  }
  return local_8;
}



// Function: FUN_1000b090 at 1000b090

void __thiscall FUN_1000b090(void *this,int param_1,void *param_2)

{
  FUN_10006710((int)this,param_1,param_2);
  return;
}



// Function: FUN_1000b0b0 at 1000b0b0

int __thiscall FUN_1000b0b0(void *this,int param_1,void *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  int iVar3;
  int local_c;
  int *local_8;
  
  local_c = 0;
  local_8 = *(int **)((int)this + 0x2c);
  if (local_8 != (int *)0x0) {
    for (; *local_8 != 0; local_8 = local_8 + 9) {
      if ((param_2 == (void *)0x0) ||
         (bVar1 = FUN_1000dc20(param_2,(void *)*local_8), CONCAT31(extraout_var,bVar1) != 0)) {
        local_c = (*(code *)local_8[1])(1);
        if (local_c < 0) break;
        iVar3 = 1;
        piVar2 = (int *)(*(code *)local_8[7])();
        local_c = FUN_10007300((GUID *)*local_8,piVar2,iVar3);
        if (local_c < 0) break;
      }
    }
  }
  if (-1 < local_c) {
    local_c = FUN_1000b040(param_1,param_2);
  }
  return local_c;
}



// Function: FUN_1000b160 at 1000b160

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_1000b160(LPCSTR param_1,HKEY param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  LPCSTR pCVar3;
  HKEY pHVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  size_t sVar5;
  CRegKey local_1184 [12];
  int local_1178;
  CRegKey local_1174 [12];
  int local_1168;
  CRegKey local_1164 [12];
  int local_1158;
  undefined4 local_1154;
  undefined4 local_1150;
  undefined4 local_114c;
  uint local_1148;
  CRegKey local_1144 [12];
  uint local_1138;
  int local_1134;
  HKEY local_1130 [3];
  void *local_1124;
  ulong local_1120;
  int local_111c;
  CHAR local_1118 [4096];
  CHAR local_118 [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013657;
  local_10 = ExceptionList;
  local_14 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  ATL::CRegKey::CRegKey((CRegKey *)local_1130,(CAtlTransactionManager *)0x0);
  local_8 = 0;
  local_1134 = 1;
  local_1158 = param_4;
  local_111c = 0;
  local_111c = FUN_10009eb0(local_1124,param_1);
  if (-1 < local_111c) {
LAB_1000b20d:
    if (*param_1 == '}') goto LAB_1000bb04;
    local_1134 = 1;
    iVar2 = lstrcmpiA(param_1,"Delete");
    local_1138 = (uint)(iVar2 == 0);
    local_1148 = local_1138;
    iVar2 = lstrcmpiA(param_1,"ForceRemove");
    if ((iVar2 == 0) || (local_1148 != 0)) {
      local_111c = FUN_10009eb0(local_1124,param_1);
      if (local_111c < 0) goto LAB_1000bb04;
      if (param_3 == 0) goto LAB_1000b3dd;
      ATL::CRegKey::CRegKey(local_1144,(CAtlTransactionManager *)0x0);
      local_8._0_1_ = 1;
      pCVar3 = FUN_1000c6f0(param_1,'\\');
      if (pCVar3 == (LPCSTR)0x0) {
        iVar2 = FUN_10007e40(param_1);
        if (iVar2 != 0) {
          FUN_10007e10(local_1144,param_2);
          FUN_1000a6e0(param_1);
          FUN_10008690((undefined4 *)local_1144);
        }
        if (local_1148 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10004f50(local_1144);
          goto LAB_1000b3dd;
        }
        local_111c = FUN_10009eb0(local_1124,param_1);
        if (local_111c < 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10004f50(local_1144);
        }
        else {
          local_111c = FUN_1000c5f0(local_1124,param_1);
          if (-1 < local_111c) {
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_10004f50(local_1144);
            goto LAB_1000ba90;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10004f50(local_1144);
        }
        goto LAB_1000bb04;
      }
      local_1150 = FUN_100089e0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10004f50(local_1144);
      local_8 = 0xffffffff;
      FUN_10004f50((CRegKey *)local_1130);
      goto LAB_1000bb28;
    }
LAB_1000b3dd:
    iVar2 = lstrcmpiA(param_1,"NoRemove");
    if (iVar2 == 0) {
      local_1134 = 0;
      local_111c = FUN_10009eb0(local_1124,param_1);
      if (local_111c < 0) goto LAB_1000bb04;
    }
    iVar2 = lstrcmpiA(param_1,"Val");
    if (iVar2 == 0) {
      local_111c = FUN_10009eb0(local_1124,local_1118);
      if ((local_111c < 0) || (local_111c = FUN_10009eb0(local_1124,param_1), local_111c < 0))
      goto LAB_1000bb04;
      if (*param_1 != '=') {
        local_1154 = FUN_100089e0();
        local_8 = 0xffffffff;
        FUN_10004f50((CRegKey *)local_1130);
        goto LAB_1000bb28;
      }
      if (param_3 != 0) {
        ATL::CRegKey::CRegKey(local_1164,(CAtlTransactionManager *)0x0);
        local_8._0_1_ = 2;
        FUN_10007e10(local_1164,param_2);
        local_111c = FUN_100059c0(local_1124,local_1164,local_1118,param_1);
        FUN_10008690((undefined4 *)local_1164);
        if (-1 < local_111c) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10004f50(local_1164);
          goto LAB_1000ba90;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_10004f50(local_1164);
        local_8 = 0xffffffff;
        FUN_10004f50((CRegKey *)local_1130);
        goto LAB_1000bb28;
      }
      if ((param_4 == 0) && (local_1134 != 0)) {
        ATL::CRegKey::CRegKey(local_1174,(CAtlTransactionManager *)0x0);
        local_8._0_1_ = 3;
        local_1120 = FUN_1000a0d0(local_1174,param_2,(LPCSTR)0x0,0x20006);
        if (local_1120 != 0) {
          local_111c = FUN_10006a10(local_1120);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10004f50(local_1174);
          goto LAB_1000bb04;
        }
        local_1120 = FUN_10008560(local_1174,local_1118);
        if ((local_1120 != 0) && (local_1120 != 2)) {
          local_111c = FUN_10006a10(local_1120);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10004f50(local_1174);
          goto LAB_1000bb04;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_10004f50(local_1174);
      }
      local_111c = FUN_1000c5f0(local_1124,param_1);
joined_r0x1000b667:
      if (local_111c < 0) goto LAB_1000bb04;
      goto LAB_1000b20d;
    }
    pCVar3 = FUN_1000c6f0(param_1,'\\');
    if (pCVar3 != (LPCSTR)0x0) {
      FUN_100089e0();
      local_8 = 0xffffffff;
      FUN_10004f50((CRegKey *)local_1130);
      goto LAB_1000bb28;
    }
    if (param_3 == 0) {
      if (param_4 == 0) {
        local_1120 = FUN_1000a0d0(local_1130,param_2,param_1,0x20019);
      }
      else {
        local_1120 = 2;
      }
      if (local_1120 != 0) {
        param_4 = 1;
      }
      ATL::Checked::memmove_s(local_118,0x104,param_1,0xffffffff);
      local_111c = FUN_10009eb0(local_1124,param_1);
      if (((local_111c < 0) || (local_111c = FUN_1000c5f0(local_1124,param_1), local_111c < 0)) ||
         (((*param_1 == '{' && (sVar5 = strlen(param_1), sVar5 == 1)) &&
          (((local_111c = FUN_1000b160(param_1,local_1130[0],0,param_4), local_111c < 0 &&
            (param_4 == 0)) || (local_111c = FUN_10009eb0(local_1124,param_1), local_111c < 0))))))
      goto LAB_1000bb04;
      param_4 = local_1158;
      if (local_1120 == 2) goto LAB_1000b20d;
      if (local_1120 != 0) {
        if (local_1158 == 0) goto LAB_1000b918;
        goto LAB_1000b20d;
      }
      if (local_1158 != 0) {
        pHVar4 = (HKEY)FUN_10005120(local_1130);
        bVar1 = FUN_100094e0(pHVar4);
        if (CONCAT31(extraout_var,bVar1) != 0) {
          iVar2 = FUN_10007e40(local_118);
          if ((iVar2 != 0) && (local_1134 != 0)) {
            FUN_1000a6e0(local_118);
          }
          goto LAB_1000b20d;
        }
      }
      pHVar4 = (HKEY)FUN_10005120(local_1130);
      bVar1 = FUN_100094e0(pHVar4);
      local_1168 = CONCAT31(extraout_var_00,bVar1);
      local_1120 = ATL::CRegKey::Close((CRegKey *)local_1130);
      if (local_1120 != 0) {
        FUN_10006a10(local_1120);
        local_8 = 0xffffffff;
        FUN_10004f50((CRegKey *)local_1130);
        goto LAB_1000bb28;
      }
      if ((local_1134 != 0) && (local_1168 == 0)) {
        ATL::CRegKey::CRegKey(local_1184,(CAtlTransactionManager *)0x0);
        local_8._0_1_ = 4;
        FUN_10007e10(local_1184,param_2);
        local_1120 = FUN_10008510(local_1184,local_118);
        FUN_10008690((undefined4 *)local_1184);
        if (local_1120 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10004f50(local_1184);
          goto LAB_1000ba90;
        }
        local_111c = FUN_10006a10(local_1120);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_10004f50(local_1184);
        goto LAB_1000bb04;
      }
    }
    else {
      local_1120 = FUN_1000a0d0(local_1130,param_2,param_1,0x2001f);
      if (((local_1120 != 0) &&
          (local_1120 = FUN_1000a0d0(local_1130,param_2,param_1,0x20019), local_1120 != 0)) &&
         (local_1120 = FUN_100080c0(local_1130,param_2,param_1,(LPSTR)0x0,0,0x2001f,
                                    (LPSECURITY_ATTRIBUTES)0x0,(DWORD *)0x0), local_1120 != 0)) {
        local_114c = FUN_10006a10(local_1120);
        local_8 = 0xffffffff;
        FUN_10004f50((CRegKey *)local_1130);
        goto LAB_1000bb28;
      }
      local_111c = FUN_10009eb0(local_1124,param_1);
      if ((local_111c < 0) ||
         ((*param_1 == '=' &&
          (local_111c = FUN_100059c0(local_1124,local_1130,(LPCSTR)0x0,param_1), local_111c < 0))))
      goto LAB_1000bb04;
    }
LAB_1000ba90:
    if (((param_3 != 0) && (*param_1 == '{')) && (sVar5 = strlen(param_1), sVar5 == 1)) {
      local_111c = FUN_1000b160(param_1,local_1130[0],param_3,0);
      if (-1 < local_111c) {
        local_111c = FUN_10009eb0(local_1124,param_1);
        goto joined_r0x1000b667;
      }
      goto LAB_1000bb04;
    }
    goto LAB_1000b20d;
  }
  local_8 = 0xffffffff;
  local_1178 = local_111c;
  FUN_10004f50((CRegKey *)local_1130);
LAB_1000bb28:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
LAB_1000b918:
  local_111c = FUN_10006a10(local_1120);
LAB_1000bb04:
  local_8 = 0xffffffff;
  FUN_10004f50((CRegKey *)local_1130);
  goto LAB_1000bb28;
}



// Function: Release at 1000bb50

/* Library Function - Single Match
    public: virtual unsigned long __stdcall CMFCComObject<class
   ATL::CAccessibleProxy>::Release(void)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

ulong CMFCComObject<class_ATL::CAccessibleProxy>::Release(void)

{
  ulong uVar1;
  int *in_stack_00000004;
  
  uVar1 = FUN_10009820(in_stack_00000004 + 1);
  if ((uVar1 == 0) && (in_stack_00000004 != (int *)0x0)) {
    (**(code **)(*in_stack_00000004 + 0xc))(1);
  }
  return uVar1;
}



// Function: FUN_1000bba0 at 1000bba0

void FUN_1000bba0(int param_1)

{
  FUN_1000a1b0((undefined4 *)(param_1 + 0xc));
  return;
}



// Function: FUN_1000bbb2 at 1000bbb2

void FUN_1000bbb2(int param_1)

{
  FUN_1000bba0(param_1 + -4);
  return;
}



// Function: FUN_1000bbbc at 1000bbbc

void FUN_1000bbbc(int param_1)

{
  FUN_1000bba0(param_1 + -8);
  return;
}



// Function: Release at 1000bbd0

/* Library Function - Single Match
    public: virtual unsigned long __stdcall CMFCComObject<class
   ATL::CAccessibleProxy>::Release(void)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

ulong CMFCComObject<class_ATL::CAccessibleProxy>::Release(void)

{
  ulong uVar1;
  int *in_stack_00000004;
  
  uVar1 = FUN_10009800(in_stack_00000004 + 3);
  if ((uVar1 == 0) && (in_stack_00000004 != (int *)0x0)) {
    (**(code **)(*in_stack_00000004 + 0x10))(1);
  }
  return uVar1;
}



// Function: FUN_1000bc20 at 1000bc20

void FUN_1000bc20(void)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::Release();
  return;
}



// Function: FUN_1000bc2a at 1000bc2a

void FUN_1000bc2a(void)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::Release();
  return;
}



// Function: FUN_1000bc40 at 1000bc40

int FUN_1000bc40(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_10009800(param_1 + 1);
  if (iVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (iVar1 == 1) {
    (**(code **)(*DAT_1001b648 + 8))();
  }
  return iVar1;
}



// Function: FUN_1000bcb0 at 1000bcb0

undefined4 FUN_1000bcb0(void)

{
  return 0;
}



// Function: FUN_1000bcc0 at 1000bcc0

void __fastcall FUN_1000bcc0(int *param_1)

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



// Function: FUN_1000bd40 at 1000bd40

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1000bd40(undefined4 param_1,wchar_t *param_2,ushort param_3,wchar_t *param_4)

{
  char cVar1;
  size_t sVar2;
  long lVar3;
  uint local_44;
  undefined4 local_40;
  UINT local_3c;
  undefined4 local_38;
  undefined1 *local_34;
  LPCSTR local_30;
  LPSTR local_2c;
  LPSTR local_28;
  LPCSTR local_24;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_20 [4];
  wchar_t *local_1c;
  ulong local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013688;
  local_10 = ExceptionList;
  local_44 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_44;
  local_3c = FUN_10003510();
  FUN_10003cc0((undefined4 *)local_20);
  local_8 = 0;
  local_1c = param_4;
  if (param_4 == (wchar_t *)0x0) {
    local_24 = (LPCSTR)0x0;
    goto LAB_1000be25;
  }
  sVar2 = wcslen(param_4);
  local_18 = sVar2 + 1;
  lVar3 = ATL::AtlMultiply<int>((int *)&local_18,local_18,2);
  if (lVar3 < 0) {
    local_2c = (LPSTR)0x0;
  }
  else {
    if ((int)local_18 < 0x401) {
      cVar1 = FUN_1000d8f0(local_18);
      if (cVar1 == '\0') goto LAB_1000bdf8;
      local_34 = (undefined1 *)&local_44;
      local_28 = (LPSTR)&local_44;
    }
    else {
LAB_1000bdf8:
      local_28 = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                        CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                  (local_20,local_18);
    }
    local_2c = FUN_10003300(local_28,local_1c,local_18,local_3c);
  }
  local_24 = local_2c;
LAB_1000be25:
  local_30 = local_24;
  if (local_24 == (LPCSTR)0x0) {
    local_38 = 0x8007000e;
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_20);
  }
  else {
    local_40 = FUN_1000ac70(param_2,(LPCSTR)(uint)param_3,local_24);
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_20);
  }
  ExceptionList = local_10;
  local_44 = 0x1000be90;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000bea0 at 1000bea0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1000bea0(undefined4 param_1,wchar_t *param_2,wchar_t *param_3,wchar_t *param_4)

{
  char cVar1;
  size_t sVar2;
  long lVar3;
  uint local_5c;
  undefined4 local_58;
  undefined1 *local_54;
  undefined4 local_50;
  undefined1 *local_4c;
  undefined4 local_48;
  LPSTR local_44;
  LPSTR local_40;
  LPSTR local_3c;
  LPCSTR local_38;
  UINT local_34;
  LPSTR local_30;
  LPSTR local_2c;
  LPCSTR local_28;
  LPSTR local_24;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_20 [4];
  wchar_t *local_1c;
  ulong local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100136b8;
  local_10 = ExceptionList;
  local_5c = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_5c;
  local_34 = FUN_10003510();
  FUN_10003cc0((undefined4 *)local_20);
  local_8 = 0;
  if ((param_3 == (wchar_t *)0x0) || (param_4 == (wchar_t *)0x0)) {
    local_48 = 0x80070057;
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_20);
    goto LAB_1000c0b3;
  }
  local_1c = param_3;
  if (param_3 == (wchar_t *)0x0) {
    local_3c = (LPSTR)0x0;
  }
  else {
    sVar2 = wcslen(param_3);
    local_18 = sVar2 + 1;
    lVar3 = ATL::AtlMultiply<int>((int *)&local_18,local_18,2);
    if (lVar3 < 0) {
      local_2c = (LPSTR)0x0;
    }
    else {
      if ((int)local_18 < 0x401) {
        cVar1 = FUN_1000d8f0(local_18);
        if (cVar1 == '\0') goto LAB_1000bf82;
        local_54 = (undefined1 *)&local_5c;
        local_40 = (LPSTR)&local_5c;
      }
      else {
LAB_1000bf82:
        local_40 = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                          CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                    (local_20,local_18);
      }
      local_2c = FUN_10003300(local_40,local_1c,local_18,local_34);
    }
    local_3c = local_2c;
  }
  local_30 = local_3c;
  local_1c = param_4;
  if (param_4 == (wchar_t *)0x0) {
    local_38 = (LPCSTR)0x0;
  }
  else {
    sVar2 = wcslen(param_4);
    local_18 = sVar2 + 1;
    lVar3 = ATL::AtlMultiply<int>((int *)&local_18,local_18,2);
    if (lVar3 < 0) {
      local_24 = (LPSTR)0x0;
    }
    else {
      if ((int)local_18 < 0x401) {
        cVar1 = FUN_1000d8f0(local_18);
        if (cVar1 == '\0') goto LAB_1000c02e;
        local_4c = (undefined1 *)&local_5c;
        local_44 = (LPSTR)&local_5c;
      }
      else {
LAB_1000c02e:
        local_44 = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                          CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                    (local_20,local_18);
      }
      local_24 = FUN_10003300(local_44,local_1c,local_18,local_34);
    }
    local_38 = local_24;
  }
  local_28 = local_38;
  if ((local_30 == (LPCSTR)0x0) || (local_38 == (LPCSTR)0x0)) {
    local_50 = 0x8007000e;
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_20);
  }
  else {
    local_58 = FUN_1000ac70(param_2,local_30,local_38);
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_20);
  }
LAB_1000c0b3:
  ExceptionList = local_10;
  local_5c = 0x1000c0cb;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000c0e0 at 1000c0e0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1000c0e0(undefined4 param_1,wchar_t *param_2,ushort param_3,wchar_t *param_4)

{
  char cVar1;
  size_t sVar2;
  long lVar3;
  uint local_44;
  undefined4 local_40;
  UINT local_3c;
  undefined4 local_38;
  undefined1 *local_34;
  LPCSTR local_30;
  LPSTR local_2c;
  LPSTR local_28;
  LPCSTR local_24;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_20 [4];
  wchar_t *local_1c;
  ulong local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100136e8;
  local_10 = ExceptionList;
  local_44 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_44;
  local_3c = FUN_10003510();
  FUN_10003cc0((undefined4 *)local_20);
  local_8 = 0;
  local_1c = param_4;
  if (param_4 == (wchar_t *)0x0) {
    local_24 = (LPCSTR)0x0;
    goto LAB_1000c1c5;
  }
  sVar2 = wcslen(param_4);
  local_18 = sVar2 + 1;
  lVar3 = ATL::AtlMultiply<int>((int *)&local_18,local_18,2);
  if (lVar3 < 0) {
    local_2c = (LPSTR)0x0;
  }
  else {
    if ((int)local_18 < 0x401) {
      cVar1 = FUN_1000d8f0(local_18);
      if (cVar1 == '\0') goto LAB_1000c198;
      local_34 = (undefined1 *)&local_44;
      local_28 = (LPSTR)&local_44;
    }
    else {
LAB_1000c198:
      local_28 = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                        CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                  (local_20,local_18);
    }
    local_2c = FUN_10003300(local_28,local_1c,local_18,local_3c);
  }
  local_24 = local_2c;
LAB_1000c1c5:
  local_30 = local_24;
  if (local_24 == (LPCSTR)0x0) {
    local_38 = 0x8007000e;
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_20);
  }
  else {
    local_40 = FUN_1000ac70(param_2,(LPCSTR)(uint)param_3,local_24);
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_20);
  }
  ExceptionList = local_10;
  local_44 = 0x1000c230;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000c240 at 1000c240

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1000c240(undefined4 param_1,wchar_t *param_2,wchar_t *param_3,wchar_t *param_4)

{
  char cVar1;
  size_t sVar2;
  long lVar3;
  uint local_5c;
  undefined4 local_58;
  undefined1 *local_54;
  undefined4 local_50;
  undefined1 *local_4c;
  undefined4 local_48;
  LPSTR local_44;
  LPSTR local_40;
  LPSTR local_3c;
  LPCSTR local_38;
  UINT local_34;
  LPSTR local_30;
  LPSTR local_2c;
  LPCSTR local_28;
  LPSTR local_24;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_20 [4];
  wchar_t *local_1c;
  ulong local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013718;
  local_10 = ExceptionList;
  local_5c = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_5c;
  local_34 = FUN_10003510();
  FUN_10003cc0((undefined4 *)local_20);
  local_8 = 0;
  if ((param_3 == (wchar_t *)0x0) || (param_4 == (wchar_t *)0x0)) {
    local_48 = 0x80070057;
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_20);
    goto LAB_1000c453;
  }
  local_1c = param_3;
  if (param_3 == (wchar_t *)0x0) {
    local_3c = (LPSTR)0x0;
  }
  else {
    sVar2 = wcslen(param_3);
    local_18 = sVar2 + 1;
    lVar3 = ATL::AtlMultiply<int>((int *)&local_18,local_18,2);
    if (lVar3 < 0) {
      local_2c = (LPSTR)0x0;
    }
    else {
      if ((int)local_18 < 0x401) {
        cVar1 = FUN_1000d8f0(local_18);
        if (cVar1 == '\0') goto LAB_1000c322;
        local_54 = (undefined1 *)&local_5c;
        local_40 = (LPSTR)&local_5c;
      }
      else {
LAB_1000c322:
        local_40 = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                          CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                    (local_20,local_18);
      }
      local_2c = FUN_10003300(local_40,local_1c,local_18,local_34);
    }
    local_3c = local_2c;
  }
  local_30 = local_3c;
  local_1c = param_4;
  if (param_4 == (wchar_t *)0x0) {
    local_38 = (LPCSTR)0x0;
  }
  else {
    sVar2 = wcslen(param_4);
    local_18 = sVar2 + 1;
    lVar3 = ATL::AtlMultiply<int>((int *)&local_18,local_18,2);
    if (lVar3 < 0) {
      local_24 = (LPSTR)0x0;
    }
    else {
      if ((int)local_18 < 0x401) {
        cVar1 = FUN_1000d8f0(local_18);
        if (cVar1 == '\0') goto LAB_1000c3ce;
        local_4c = (undefined1 *)&local_5c;
        local_44 = (LPSTR)&local_5c;
      }
      else {
LAB_1000c3ce:
        local_44 = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                          CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                    (local_20,local_18);
      }
      local_24 = FUN_10003300(local_44,local_1c,local_18,local_34);
    }
    local_38 = local_24;
  }
  local_28 = local_38;
  if ((local_30 == (LPCSTR)0x0) || (local_38 == (LPCSTR)0x0)) {
    local_50 = 0x8007000e;
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_20);
  }
  else {
    local_58 = FUN_1000ac70(param_2,local_30,local_38);
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_20);
  }
LAB_1000c453:
  ExceptionList = local_10;
  local_5c = 0x1000c46b;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000c480 at 1000c480

void __thiscall FUN_1000c480(void *this,LPCSTR param_1)

{
                    /* WARNING: Load size is inaccurate */
  RegSetValueExA(*this,param_1,0,4,&stack0x00000008,4);
  return;
}



// Function: FUN_1000c4b0 at 1000c4b0

LSTATUS __thiscall FUN_1000c4b0(void *this,LPCSTR param_1,BYTE *param_2)

{
  LSTATUS LVar1;
  size_t sVar2;
  int iVar3;
  DWORD local_10;
  BYTE *local_8;
  
  if (param_2 == (BYTE *)0x0) {
    LVar1 = 0xd;
  }
  else {
    local_10 = 0;
    local_8 = param_2;
    do {
      sVar2 = strlen((char *)local_8);
      iVar3 = sVar2 + 1;
      local_8 = local_8 + iVar3;
      local_10 = local_10 + iVar3;
    } while (iVar3 != 1);
                    /* WARNING: Load size is inaccurate */
    LVar1 = RegSetValueExA(*this,param_1,0,7,param_2,local_10);
  }
  return LVar1;
}



// Function: FUN_1000c550 at 1000c550

LSTATUS __thiscall FUN_1000c550(void *this,LPCSTR param_1,BYTE *param_2,DWORD param_3)

{
  LSTATUS LVar1;
  size_t sVar2;
  
  if (param_2 == (BYTE *)0x0) {
    LVar1 = 0xd;
  }
  else {
    sVar2 = strlen((char *)param_2);
                    /* WARNING: Load size is inaccurate */
    LVar1 = RegSetValueExA(*this,param_1,0,param_3,param_2,sVar2 + 1);
  }
  return LVar1;
}



// Function: FUN_1000c5c0 at 1000c5c0

void __thiscall FUN_1000c5c0(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x24) = param_1;
  return;
}



// Function: FUN_1000c5e0 at 1000c5e0

void FUN_1000c5e0(void)

{
  return;
}



// Function: FUN_1000c5f0 at 1000c5f0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_1000c5f0(void *this,char *param_1)

{
  int iVar1;
  undefined1 local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  if ((*param_1 == '=') && (iVar1 = FUN_10009eb0(this,param_1), -1 < iVar1)) {
    FUN_1000c6b0((undefined4 *)this);
    iVar1 = FUN_10009eb0(this,local_1008);
    if (-1 < iVar1) {
      FUN_10009eb0(this,param_1);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000c6b0 at 1000c6b0

void __fastcall FUN_1000c6b0(undefined4 *param_1)

{
  int iVar1;
  LPSTR pCVar2;
  
  while( true ) {
    iVar1 = FUN_10009b00(*(undefined1 *)*param_1);
    if (iVar1 == 0) break;
    pCVar2 = CharNextA((LPCSTR)*param_1);
    *param_1 = pCVar2;
  }
  return;
}



// Function: FUN_1000c6f0 at 1000c6f0

LPCSTR __cdecl FUN_1000c6f0(LPSTR param_1,char param_2)

{
  LPSTR pCVar1;
  LPCSTR local_8;
  
  local_8 = (LPCSTR)0x0;
  if (param_1 == (LPSTR)0x0) {
    pCVar1 = (LPCSTR)0x0;
  }
  else {
    for (; (pCVar1 = local_8, *param_1 != '\0' && (pCVar1 = param_1, *param_1 != param_2));
        param_1 = CharNextA(param_1)) {
    }
  }
  return pCVar1;
}



// Function: FUN_1000c740 at 1000c740

undefined4 __fastcall FUN_1000c740(int param_1)

{
  undefined4 uVar1;
  
  FUN_10009e20();
  uVar1 = FUN_10009e70((void *)(param_1 + 4),(undefined4 *)&stack0x00000004);
  FUN_1000c8e0();
  return uVar1;
}



// Function: FUN_1000c780 at 1000c780

void __fastcall FUN_1000c780(int param_1)

{
  undefined4 local_c;
  
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      if (param_1 == 0) {
        local_c = (_ATL_MODULE70 *)0x0;
      }
      else {
        local_c = (_ATL_MODULE70 *)(param_1 + 4);
      }
      ATL::AtlCallTermFunc(local_c);
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    if (*(int *)(param_1 + 0x28) != 0) {
      (**(code **)(**(int **)(param_1 + 0x28) + 8))(*(undefined4 *)(param_1 + 0x28));
    }
    FUN_10003470((LPCRITICAL_SECTION)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}



// Function: FUN_1000c800 at 1000c800

void __fastcall FUN_1000c800(int param_1)

{
  int *local_c;
  int *local_8;
  
  if (*(int *)(param_1 + 0x2c) != 0) {
    for (local_8 = *(int **)(param_1 + 0x2c); *local_8 != 0; local_8 = local_8 + 9) {
      if (local_8[4] != 0) {
        (**(code **)(*(int *)local_8[4] + 8))(local_8[4]);
      }
      local_8[4] = 0;
      (*(code *)local_8[8])(0);
    }
  }
  for (local_c = DAT_1001b720; local_c < DAT_1001b724; local_c = local_c + 1) {
    if (*local_c != 0) {
      (**(code **)(*local_c + 0x1c))(0);
    }
  }
  FUN_1000c780(param_1);
  return;
}



// Function: FUN_1000c8a0 at 1000c8a0

void __fastcall FUN_1000c8a0(undefined4 *param_1)

{
  FUN_100034e0((LPCRITICAL_SECTION)*param_1);
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}



// Function: FUN_1000c8c0 at 1000c8c0

void __fastcall FUN_1000c8c0(int param_1)

{
  FUN_100084d0((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_1000c8e0 at 1000c8e0

undefined4 FUN_1000c8e0(void)

{
  return 0;
}



// Function: FUN_1000c8f0 at 1000c8f0

int __thiscall FUN_1000c8f0(void *this,int param_1,void *param_2)

{
  int local_8;
  
  local_8 = 0;
  if (DAT_1001b668 != (code *)0x0) {
    local_8 = (*DAT_1001b668)(this);
  }
  if (-1 < local_8) {
    local_8 = FUN_1000c940(&DAT_1001b718,param_1,param_2);
  }
  return local_8;
}



// Function: FUN_1000c940 at 1000c940

void __thiscall FUN_1000c940(void *this,int param_1,void *param_2)

{
  FUN_100067e0((int)this,param_1,param_2);
  return;
}



// Function: FUN_1000c960 at 1000c960

int __thiscall FUN_1000c960(void *this,int param_1,void *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  int iVar3;
  int local_c;
  int *local_8;
  
  local_c = 0;
  local_8 = *(int **)((int)this + 0x2c);
  if (local_8 != (int *)0x0) {
    for (; *local_8 != 0; local_8 = local_8 + 9) {
      if ((param_2 == (void *)0x0) ||
         (bVar1 = FUN_1000dc20(param_2,(void *)*local_8), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar3 = 0;
        piVar2 = (int *)(*(code *)local_8[7])();
        local_c = FUN_10007300((GUID *)*local_8,piVar2,iVar3);
        if ((local_c < 0) || (local_c = (*(code *)local_8[1])(0), local_c < 0)) break;
      }
    }
  }
  if (-1 < local_c) {
    local_c = FUN_1000c8f0(this,param_1,param_2);
  }
  return local_c;
}



// Function: FUN_1000ca10 at 1000ca10

undefined4 FUN_1000ca10(void)

{
  return 0x80004005;
}



// Function: FUN_1000ca20 at 1000ca20

undefined4 FUN_1000ca20(void)

{
  return 0x80004005;
}



// Function: FUN_1000ca30 at 1000ca30

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1000ca30(int *param_1,ushort param_2,int param_3,int *param_4)

{
  char cVar1;
  bool bVar2;
  UINT UVar3;
  DWORD DVar4;
  long lVar5;
  HMODULE pHVar6;
  size_t sVar7;
  LPWSTR local_990;
  LPWSTR local_988;
  LPWSTR local_980;
  int local_974;
  undefined4 local_970 [5];
  HMODULE local_95c;
  char *local_958;
  LPWSTR local_954;
  int local_950;
  ulong local_94c;
  int local_948;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_944 [4];
  wchar_t local_940 [520];
  wchar_t local_530;
  undefined2 local_52e [523];
  CHAR local_118 [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013756;
  local_10 = ExceptionList;
  local_14 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_100045e0(local_970);
  local_8 = 0;
  local_948 = FUN_10008840();
  if (local_948 < 0) {
    local_8 = 0xffffffff;
    FUN_10004f70(local_970);
  }
  else {
    if (param_4 != (int *)0x0) {
      for (; *param_4 != 0; param_4 = param_4 + 2) {
        FUN_10005670((int)local_970,(wchar_t *)*param_4,(wchar_t *)param_4[1]);
      }
    }
    local_948 = (**(code **)(*param_1 + 0x14))();
    if (local_948 < 0) {
      local_8 = 0xffffffff;
      FUN_10004f70(local_970);
    }
    else {
      UVar3 = FUN_10003510();
      FUN_10003cc0((undefined4 *)local_944);
      local_8._0_1_ = 1;
      local_95c = (HMODULE)FUN_10008e20(0x1001b6e0);
      DVar4 = GetModuleFileNameA(local_95c,local_118,0x104);
      if (DVar4 == 0) {
        FUN_100069f0();
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
        ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_944);
        local_8 = 0xffffffff;
        FUN_10004f70(local_970);
      }
      else if (DVar4 == 0x104) {
        _HRESULT_FROM_WIN32(0x7a);
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
        ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_944);
        local_8 = 0xffffffff;
        FUN_10004f70(local_970);
      }
      else {
        local_954 = (LPWSTR)0x0;
        local_958 = local_118;
        if (local_958 == (char *)0x0) {
          local_990 = (LPWSTR)0x0;
        }
        else {
          sVar7 = strlen(local_958);
          local_94c = sVar7 + 1;
          lVar5 = ATL::AtlMultiply<int>((int *)&local_94c,local_94c,2);
          if (lVar5 < 0) {
            local_988 = (LPWSTR)0x0;
          }
          else {
            if (((int)local_94c < 0x401) && (cVar1 = FUN_1000d8f0(local_94c), cVar1 != '\0')) {
              local_980 = (LPWSTR)&stack0xfffff63c;
            }
            else {
              local_980 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                            (local_944,local_94c);
            }
            local_988 = FUN_10003280(local_980,local_958,local_94c >> 1,UVar3);
          }
          local_990 = local_988;
        }
        local_954 = local_990;
        if (local_990 == (LPWSTR)0x0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
          ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_944);
          local_8 = 0xffffffff;
          FUN_10004f70(local_970);
        }
        else {
          FUN_10008760(local_940,0x208,local_990);
          if ((local_95c == (HMODULE)0x0) ||
             (pHVar6 = GetModuleHandleA((LPCSTR)0x0), local_95c == pHVar6)) {
            local_530 = L'\"';
            bVar2 = FUN_1000dab0(local_52e,0x20b,local_940);
            if (!bVar2) {
              local_8 = (uint)local_8._1_3_ << 8;
              ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
              ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_944);
              local_8 = 0xffffffff;
              FUN_10004f70(local_970);
              goto LAB_1000cfc6;
            }
            sVar7 = FUN_1000db00(&local_530);
            local_52e[sVar7 - 1] = 0x22;
            if (0x417 < sVar7 * 2 + 2) {
              ___report_rangecheckfailure();
            }
            local_52e[sVar7] = 0;
            local_950 = FUN_10005670((int)local_970,L"Module",&local_530);
          }
          else {
            local_950 = FUN_10005670((int)local_970,L"Module",local_940);
          }
          if (local_950 < 0) {
            local_8 = (uint)local_8._1_3_ << 8;
            ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
            ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_944);
            local_8 = 0xffffffff;
            FUN_10004f70(local_970);
          }
          else {
            local_950 = FUN_10005670((int)local_970,L"Module_Raw",local_940);
            if (local_950 < 0) {
              local_8 = (uint)local_8._1_3_ << 8;
              ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
              ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_944);
              local_8 = 0xffffffff;
              FUN_10004f70(local_970);
            }
            else {
              if (param_3 == 0) {
                local_974 = FUN_1000c0e0(local_970,local_954,param_2,L"REGISTRY");
              }
              else {
                local_974 = FUN_1000bd40(local_970,local_954,param_2,L"REGISTRY");
              }
              local_948 = local_974;
              local_8 = (uint)local_8._1_3_ << 8;
              ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
              ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_944);
              local_8 = 0xffffffff;
              FUN_10004f70(local_970);
            }
          }
        }
      }
    }
  }
LAB_1000cfc6:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000cff0 at 1000cff0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1000cff0(int *param_1,char *param_2,int param_3,int *param_4)

{
  bool bVar1;
  char cVar2;
  UINT UVar3;
  DWORD DVar4;
  HMODULE pHVar5;
  size_t sVar6;
  long lVar7;
  LPWSTR local_9a4;
  LPWSTR local_99c;
  LPWSTR local_998;
  LPWSTR local_994;
  LPWSTR local_988;
  int local_984;
  wchar_t *local_978;
  undefined4 local_974 [5];
  HMODULE local_960;
  wchar_t *local_95c;
  LPWSTR local_958;
  int local_954;
  char *local_950;
  int local_94c;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_948 [4];
  ulong local_944;
  wchar_t local_940 [520];
  wchar_t local_530;
  undefined2 local_52e [523];
  CHAR local_118 [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013796;
  local_10 = ExceptionList;
  local_14 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_100045e0(local_974);
  local_8 = 0;
  local_94c = FUN_10008840();
  if (local_94c < 0) {
    local_8 = 0xffffffff;
    FUN_10004f70(local_974);
  }
  else {
    if (param_4 != (int *)0x0) {
      for (; *param_4 != 0; param_4 = param_4 + 2) {
        FUN_10005670((int)local_974,(wchar_t *)*param_4,(wchar_t *)param_4[1]);
      }
    }
    local_94c = (**(code **)(*param_1 + 0x14))();
    if (local_94c < 0) {
      local_8 = 0xffffffff;
      FUN_10004f70(local_974);
    }
    else {
      UVar3 = FUN_10003510();
      FUN_10003cc0((undefined4 *)local_948);
      local_8._0_1_ = 1;
      local_960 = (HMODULE)FUN_10008e20(0x1001b6e0);
      DVar4 = GetModuleFileNameA(local_960,local_118,0x104);
      if (DVar4 == 0) {
        FUN_100069f0();
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
        ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_948);
        local_8 = 0xffffffff;
        FUN_10004f70(local_974);
      }
      else if (DVar4 == 0x104) {
        _HRESULT_FROM_WIN32(0x7a);
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
        ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_948);
        local_8 = 0xffffffff;
        FUN_10004f70(local_974);
      }
      else {
        local_958 = (LPWSTR)0x0;
        local_950 = local_118;
        if (local_950 == (char *)0x0) {
          local_9a4 = (LPWSTR)0x0;
        }
        else {
          sVar6 = strlen(local_950);
          local_944 = sVar6 + 1;
          lVar7 = ATL::AtlMultiply<int>((int *)&local_944,local_944,2);
          if (lVar7 < 0) {
            local_99c = (LPWSTR)0x0;
          }
          else {
            if (((int)local_944 < 0x401) && (cVar2 = FUN_1000d8f0(local_944), cVar2 != '\0')) {
              local_994 = (LPWSTR)&stack0xfffff624;
            }
            else {
              local_994 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                            (local_948,local_944);
            }
            local_99c = FUN_10003280(local_994,local_950,local_944 >> 1,UVar3);
          }
          local_9a4 = local_99c;
        }
        local_958 = local_9a4;
        if (local_9a4 == (LPWSTR)0x0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
          ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_948);
          local_8 = 0xffffffff;
          FUN_10004f70(local_974);
        }
        else {
          FUN_10008760(local_940,0x208,local_9a4);
          if ((local_960 == (HMODULE)0x0) ||
             (pHVar5 = GetModuleHandleA((LPCSTR)0x0), local_960 == pHVar5)) {
            local_530 = L'\"';
            bVar1 = FUN_1000dab0(local_52e,0x20b,local_940);
            if (!bVar1) {
              local_8 = (uint)local_8._1_3_ << 8;
              ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
              ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_948);
              local_8 = 0xffffffff;
              FUN_10004f70(local_974);
              goto LAB_1000d6c9;
            }
            sVar6 = FUN_1000db00(&local_530);
            local_52e[sVar6 - 1] = 0x22;
            if (0x417 < sVar6 * 2 + 2) {
              ___report_rangecheckfailure();
            }
            local_52e[sVar6] = 0;
            local_954 = FUN_10005670((int)local_974,L"Module",&local_530);
          }
          else {
            local_954 = FUN_10005670((int)local_974,L"Module",local_940);
          }
          if (local_954 < 0) {
            local_8 = (uint)local_8._1_3_ << 8;
            ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
            ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_948);
            local_8 = 0xffffffff;
            FUN_10004f70(local_974);
          }
          else {
            local_954 = FUN_10005670((int)local_974,L"Module_Raw",local_940);
            if (local_954 < 0) {
              local_8 = (uint)local_8._1_3_ << 8;
              ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
              ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_948);
              local_8 = 0xffffffff;
              FUN_10004f70(local_974);
            }
            else {
              local_950 = param_2;
              if (param_2 == (char *)0x0) {
                local_978 = (wchar_t *)0x0;
              }
              else {
                sVar6 = strlen(param_2);
                local_944 = sVar6 + 1;
                lVar7 = ATL::AtlMultiply<int>((int *)&local_944,local_944,2);
                if (lVar7 < 0) {
                  local_998 = (LPWSTR)0x0;
                }
                else {
                  if (((int)local_944 < 0x401) && (cVar2 = FUN_1000d8f0(local_944), cVar2 != '\0'))
                  {
                    local_988 = (LPWSTR)&stack0xfffff624;
                  }
                  else {
                    local_988 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                        CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
                                        Allocate(local_948,local_944);
                  }
                  local_998 = FUN_10003280(local_988,local_950,local_944 >> 1,UVar3);
                }
                local_978 = local_998;
              }
              local_95c = local_978;
              if (local_978 == (wchar_t *)0x0) {
                local_8 = (uint)local_8._1_3_ << 8;
                ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
                ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_948);
                local_8 = 0xffffffff;
                FUN_10004f70(local_974);
              }
              else {
                if (param_3 == 0) {
                  local_984 = FUN_1000c240(local_974,local_958,local_978,L"REGISTRY");
                }
                else {
                  local_984 = FUN_1000bea0(local_974,local_958,local_978,L"REGISTRY");
                }
                local_94c = local_984;
                local_8 = (uint)local_8._1_3_ << 8;
                ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
                ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_948);
                local_8 = 0xffffffff;
                FUN_10004f70(local_974);
              }
            }
          }
        }
      }
    }
  }
LAB_1000d6c9:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000d6f0 at 1000d6f0

void FUN_1000d6f0(int *param_1,ushort param_2,int param_3,int *param_4)

{
  FUN_1000ca30(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000d710 at 1000d710

void FUN_1000d710(int *param_1,char *param_2,int param_3,int *param_4)

{
  FUN_1000cff0(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000d730 at 1000d730

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1000d730(LPCSTR param_1,undefined2 *param_2)

{
  int iVar1;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100137ce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_1001b6ac & 1) == 0) {
    DAT_1001b6ac = DAT_1001b6ac | 1;
    _DAT_1001b68c = &DAT_10014bf0;
    _DAT_1001b690 = 8;
    _DAT_1001b694 = &DAT_10014bf4;
    _DAT_1001b698 = 0x4008;
    _DAT_1001b69c = &DAT_10014bf8;
    _DAT_1001b6a0 = 0x13;
    _DAT_1001b6a4 = &DAT_10014bfc;
    _DAT_1001b6a8 = 0x11;
  }
  local_8 = 0xffffffff;
  local_14 = 0;
  while( true ) {
    if (3 < local_14) {
      ExceptionList = local_10;
      return 0;
    }
    iVar1 = lstrcmpiA(param_1,*(LPCSTR *)(&DAT_1001b68c + local_14 * 8));
    if (iVar1 == 0) break;
    local_14 = local_14 + 1;
  }
  *param_2 = *(undefined2 *)(&DAT_1001b690 + local_14 * 8);
  ExceptionList = local_10;
  return 1;
}



// Function: FUN_1000d840 at 1000d840

undefined4 FUN_1000d840(void)

{
  return 0;
}



// Function: FUN_1000d850 at 1000d850

int __fastcall FUN_1000d850(int param_1)

{
  undefined4 local_8;
  
  local_8 = FUN_1000d890(param_1 + 0x18);
  if (-1 < local_8) {
    local_8 = FUN_1000d8b0();
  }
  return local_8;
}



// Function: FUN_1000d890 at 1000d890

void __fastcall FUN_1000d890(int param_1)

{
  FUN_10009680((CComCriticalSection *)(param_1 + 4));
  return;
}



// Function: FUN_1000d8b0 at 1000d8b0

void FUN_1000d8b0(void)

{
  FUN_100095c0();
  return;
}



// Function: _AtlRaiseException at 1000d8d0

/* Library Function - Single Match
    void __cdecl ATL::_AtlRaiseException(unsigned long,unsigned long)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void __cdecl ATL::_AtlRaiseException(ulong param_1,ulong param_2)

{
  RaiseException(param_1,param_2,0,(ULONG_PTR *)0x0);
  return;
}



// Function: FUN_1000d8f0 at 1000d8f0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __cdecl FUN_1000d8f0(int param_1)

{
  HRESULT HVar1;
  uint local_4c;
  int local_28;
  undefined1 local_21;
  uint local_20;
  undefined1 *local_1c;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  pcStack_10 = FUN_10011d3b;
  local_14 = ExceptionList;
  local_c = DAT_1001b638 ^ 0x10018798;
  local_4c = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  local_1c = (undefined1 *)&local_4c;
  ExceptionList = &local_14;
  local_21 = 1;
  local_8 = 0;
  local_28 = 0;
  local_20 = local_4c;
  HVar1 = AtlAdd<>(&local_28,param_1,0x2000);
  if (HVar1 < 0) {
    local_21 = 0;
  }
  else {
    local_1c = (undefined1 *)((int)&local_4c - local_28);
  }
  local_8 = 0xfffffffe;
  ExceptionList = local_14;
  __security_check_cookie(local_20 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: _GetEntries at 1000d9e0

/* Library Function - Single Match
    public: static struct ATL::_ATL_INTMAP_ENTRY const * __stdcall
   ATL::CAccessibleProxy::_GetEntries(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

_ATL_INTMAP_ENTRY * ATL::CAccessibleProxy::_GetEntries(void)

{
  return (_ATL_INTMAP_ENTRY *)&PTR_DAT_10015404;
}



// Function: _GetEntries at 1000d9f0

/* Library Function - Single Match
    public: static struct ATL::_ATL_INTMAP_ENTRY const * __stdcall
   ATL::CAccessibleProxy::_GetEntries(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

_ATL_INTMAP_ENTRY * ATL::CAccessibleProxy::_GetEntries(void)

{
  return (_ATL_INTMAP_ENTRY *)&PTR_DAT_1001541c;
}



// Function: _InternalQueryInterface at 1000da00

/* Library Function - Single Match
    public: long __thiscall ATL::CAccessibleProxy::_InternalQueryInterface(struct _GUID const &,void
   * *)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

long __thiscall
ATL::CAccessibleProxy::_InternalQueryInterface(CAccessibleProxy *this,_GUID *param_1,void **param_2)

{
  _ATL_INTMAP_ENTRY *p_Var1;
  int iVar2;
  
  p_Var1 = _GetEntries();
  iVar2 = FUN_100097d0((int)this,(int *)p_Var1,(int *)param_1,param_2);
  return iVar2;
}



// Function: _InternalQueryInterface at 1000da30

/* Library Function - Single Match
    public: long __thiscall ATL::CAccessibleProxy::_InternalQueryInterface(struct _GUID const &,void
   * *)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

long __thiscall
ATL::CAccessibleProxy::_InternalQueryInterface(CAccessibleProxy *this,_GUID *param_1,void **param_2)

{
  _ATL_INTMAP_ENTRY *p_Var1;
  int iVar2;
  
  p_Var1 = _GetEntries();
  iVar2 = FUN_100097d0((int)this,(int *)p_Var1,(int *)param_1,param_2);
  return iVar2;
}



// Function: _tcschr at 1000da60

/* Library Function - Single Match
    char * __cdecl _tcschr(char *,unsigned int)
   
   Library: Visual Studio 2005 Debug */

char * __cdecl _tcschr(char *param_1,uint param_2)

{
  char *pcVar1;
  
  pcVar1 = (char *)__tcschr((uchar *)param_1,(uchar *)param_2);
  return pcVar1;
}



// Function: FUN_1000da80 at 1000da80

void __cdecl FUN_1000da80(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: FUN_1000dab0 at 1000dab0

bool __cdecl FUN_1000dab0(void *param_1,int param_2,wchar_t *param_3)

{
  size_t sVar1;
  errno_t eVar2;
  
  sVar1 = FUN_1000db00(param_3);
  eVar2 = memcpy_s(param_1,param_2 << 1,param_3,sVar1 * 2 + 2);
  return eVar2 == 0;
}



// Function: FUN_1000db00 at 1000db00

size_t __cdecl FUN_1000db00(wchar_t *param_1)

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



// Function: FUN_1000db20 at 1000db20

void __cdecl FUN_1000db20(char *param_1,rsize_t param_2,char *param_3)

{
  errno_t eVar1;
  
  eVar1 = strcat_s(param_1,param_2,param_3);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: FUN_1000db50 at 1000db50

void __cdecl FUN_1000db50(char *param_1,rsize_t param_2,char *param_3)

{
  errno_t eVar1;
  
  eVar1 = strcpy_s(param_1,param_2,param_3);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: memmove_s at 1000db80

/* Library Function - Single Match
    void __cdecl ATL::Checked::memmove_s(void *,unsigned int,void const *,unsigned int)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug, Visual
   Studio 2012 Debug */

void __cdecl ATL::Checked::memmove_s(void *param_1,uint param_2,void *param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = FUN_1000dc60((uchar *)param_1,param_2,(uchar *)param_3,param_4);
  AtlCrtErrorCheck(iVar1);
  return;
}



// Function: FUN_1000dbb0 at 1000dbb0

void __cdecl FUN_1000dbb0(wchar_t *param_1,rsize_t param_2,wchar_t *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = wcsncpy_s(param_1,param_2,param_3,param_4);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: _HRESULT_FROM_WIN32 at 1000dbe0

/* Library Function - Single Match
    _HRESULT_FROM_WIN32
   
   Library: Visual Studio */

HRESULT __cdecl _HRESULT_FROM_WIN32(ulong x)

{
  undefined4 local_8;
  
  if ((int)x < 1) {
    local_8 = x;
  }
  else {
    local_8 = x & 0xffff | 0x80070000;
  }
  return local_8;
}



// Function: FUN_1000dc20 at 1000dc20

bool __cdecl FUN_1000dc20(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,0x10);
  return iVar1 == 0;
}



// Function: FUN_1000dc60 at 1000dc60

void __cdecl FUN_1000dc60(uchar *param_1,size_t param_2,uchar *param_3,size_t param_4)

{
  _mbsnbcpy_s(param_1,param_2,param_3,param_4);
  return;
}



// Function: __tcschr at 1000dc80

/* Library Function - Single Match
    __tcschr
   
   Library: Visual Studio 2005 Debug */

void __cdecl __tcschr(uchar *param_1,uchar *param_2)

{
  _mbsstr(param_1,param_2);
  return;
}



// Function: FUN_1000dca0 at 1000dca0

undefined4 * __thiscall FUN_1000dca0(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100137f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  local_8 = 0xffffffff;
  iVar1 = FUN_1000de80(this,piVar2);
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000dd20 at 1000dd20

int * __thiscall FUN_1000dd20(void *this,int *param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != param_1) {
    *(int **)this = param_1;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 4))(param_1);
    }
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return (int *)this;
}



// Function: FUN_1000dd50 at 1000dd50

int * __thiscall FUN_1000dd50(void *this,int *param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != param_1) {
    *(int **)this = param_1;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 4))(param_1);
    }
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return (int *)this;
}



// Function: FUN_1000dd80 at 1000dd80

void * __thiscall FUN_1000dd80(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013828;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  local_8 = 0xffffffff;
  iVar1 = FUN_1000de80(this,piVar2);
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1000de00 at 1000de00

void * __thiscall FUN_1000de00(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013858;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  local_8 = 0xffffffff;
  iVar1 = FUN_1000df40(this,piVar2);
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1000de80 at 1000de80

int __thiscall FUN_1000de80(void *this,int *param_1)

{
  uint uVar1;
  int *extraout_EAX;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10013888;
  local_10 = ExceptionList;
  uVar1 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = this;
  if (param_1 == (int *)0x0) {
                    /* WARNING: Load size is inaccurate */
    piVar2 = *this;
    if (piVar2 != (int *)0x0) {
      *(undefined4 *)this = 0;
      (**(code **)(*piVar2 + 8))(piVar2,uVar1);
    }
    iVar3 = -0x7fffbffe;
  }
  else {
    piVar2 = param_1;
    if (param_1 == (int *)0x0) {
      _com_issue_error(-0x7fffbffd);
      piVar2 = extraout_EAX;
    }
    iVar3 = (**(code **)*piVar2)(piVar2,&DAT_10014d24,&local_14);
                    /* WARNING: Load size is inaccurate */
    piVar2 = *this;
    pvVar4 = (void *)0x0;
    if (-1 < iVar3) {
      pvVar4 = local_14;
    }
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    *(void **)this = pvVar4;
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  ExceptionList = local_10;
  return iVar3;
}



// Function: FUN_1000df40 at 1000df40

int __thiscall FUN_1000df40(void *this,int *param_1)

{
  uint uVar1;
  int *extraout_EAX;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100138b8;
  local_10 = ExceptionList;
  uVar1 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = this;
  if (param_1 == (int *)0x0) {
                    /* WARNING: Load size is inaccurate */
    piVar2 = *this;
    if (piVar2 != (int *)0x0) {
      *(undefined4 *)this = 0;
      (**(code **)(*piVar2 + 8))(piVar2,uVar1);
    }
    iVar3 = -0x7fffbffe;
  }
  else {
    piVar2 = param_1;
    if (param_1 == (int *)0x0) {
      _com_issue_error(-0x7fffbffd);
      piVar2 = extraout_EAX;
    }
    iVar3 = (**(code **)*piVar2)(piVar2,&DAT_10015678,&local_14);
                    /* WARNING: Load size is inaccurate */
    piVar2 = *this;
    pvVar4 = (void *)0x0;
    if (-1 < iVar3) {
      pvVar4 = local_14;
    }
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    *(void **)this = pvVar4;
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  ExceptionList = local_10;
  return iVar3;
}



// Function: FUN_1000e000 at 1000e000

undefined4 * __fastcall FUN_1000e000(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1000e050 at 1000e050

undefined4 * __fastcall FUN_1000e050(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1000e0c0 at 1000e0c0

undefined4 * __thiscall FUN_1000e0c0(void *this,IID *param_1,LPUNKNOWN param_2,LPUNKNOWN param_3)

{
  code *pcVar1;
  HRESULT HVar2;
  undefined4 *puVar3;
  
  *(undefined4 *)this = 0;
  HVar2 = FUN_1000fc30(this,param_1,param_2,param_3);
  if ((HVar2 < 0) && (HVar2 != -0x7fffbffe)) {
    _com_issue_error(HVar2);
    pcVar1 = (code *)swi(3);
    puVar3 = (undefined4 *)(*pcVar1)();
    return puVar3;
  }
  return (undefined4 *)this;
}



// Function: FUN_1000e100 at 1000e100

int * __thiscall FUN_1000e100(void *this,int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  *(int **)this = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return (int *)this;
}



// Function: FUN_1000e130 at 1000e130

int * __thiscall FUN_1000e130(void *this,int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  *(int **)this = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return (int *)this;
}



// Function: FUN_1000e150 at 1000e150

undefined4 * __thiscall FUN_1000e150(void *this,int *param_1,char param_2)

{
  *(int **)this = param_1;
  if ((param_2 != '\0') && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 4))(param_1);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000e190 at 1000e190

int * __thiscall FUN_1000e190(void *this,int param_1)

{
  undefined **local_14;
  DWORD local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(int *)this = param_1;
  if (param_1 == 0) {
    local_10 = GetLastError();
    if (0 < (int)local_10) {
      local_10 = local_10 & 0xffff | 0x80070000;
    }
    local_14 = _com_error::vftable;
    local_c = 0;
    local_8 = 0;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_14,(ThrowInfo *)&DAT_1001996c);
  }
  return (int *)this;
}



// Function: FUN_1000e1f0 at 1000e1f0

int * __thiscall FUN_1000e1f0(void *this,int param_1)

{
  undefined **local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(int *)this = param_1;
  if (-1 < param_1) {
    return (int *)this;
  }
  local_10 = param_1;
  local_14 = _com_error::vftable;
  local_c = 0;
  local_8 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_1001996c);
}



// Function: FUN_1000e230 at 1000e230

int * __thiscall FUN_1000e230(void *this,int param_1,char param_2)

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



// Function: FUN_1000e280 at 1000e280

undefined4 * __thiscall FUN_1000e280(void *this,LPCSTR param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 1;
  uVar1 = ConvertStringToBSTR(param_1);
  *(undefined4 *)this = uVar1;
  return (undefined4 *)this;
}



// Function: FUN_1000e2b0 at 1000e2b0

int * __thiscall FUN_1000e2b0(void *this,int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(int *)this = iVar1;
  if (iVar1 != 0) {
    InterlockedIncrement((LONG *)(iVar1 + 8));
  }
  return (int *)this;
}



// Function: FUN_1000e2e0 at 1000e2e0

undefined4 * __thiscall FUN_1000e2e0(void *this,int param_1,char param_2)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001394b;
  local_10 = ExceptionList;
  uVar1 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar2 = (int *)operator_new(0xc);
  local_8 = 0;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    if ((param_2 != '\0') && (param_1 != 0)) {
      uVar3 = Ordinal_149(param_1,uVar1);
      iVar4 = Ordinal_150(param_1,uVar3);
      *piVar2 = iVar4;
      if (iVar4 != 0) goto LAB_1000e362;
      _com_issue_error(-0x7ff8fff2);
    }
    *piVar2 = param_1;
  }
LAB_1000e362:
  local_8 = 0xffffffff;
  *(int **)this = piVar2;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000e390 at 1000e390

undefined4 * __thiscall FUN_1000e390(void *this,LPCSTR param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001397b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)operator_new(0xc);
  local_8 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[1] = 0;
    puVar1[2] = 1;
    uVar2 = ConvertStringToBSTR(param_1);
    *puVar1 = uVar2;
  }
  local_8 = 0xffffffff;
  *(undefined4 **)this = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    _com_issue_error(-0x7ff8fff2);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: _com_error at 1000e430

/* Library Function - Single Match
    public: __thiscall _com_error::_com_error(class _com_error const &)
   
   Library: Visual Studio 2012 Release */

_com_error * __thiscall _com_error::_com_error(_com_error *this,_com_error *param_1)

{
  int *piVar1;
  
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  piVar1 = *(int **)(param_1 + 8);
  *(int **)(this + 8) = piVar1;
  *(undefined4 *)(this + 0xc) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return this;
}



// Function: FUN_1000e470 at 1000e470

void __fastcall FUN_1000e470(int *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100139a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_1001b638 ^ (uint)&stack0xfffffffc,param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000e4c0 at 1000e4c0

void __fastcall FUN_1000e4c0(int *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100139d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_1001b638 ^ (uint)&stack0xfffffffc,param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000e510 at 1000e510

void __fastcall FUN_1000e510(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000e520 at 1000e520

void __fastcall FUN_1000e520(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000e530 at 1000e530

void __fastcall FUN_1000e530(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000e540 at 1000e540

void __fastcall FUN_1000e540(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000e550 at 1000e550

void __fastcall FUN_1000e550(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000e560 at 1000e560

void __fastcall FUN_1000e560(int *param_1)

{
  if (*param_1 != 0) {
    Ordinal_6(*param_1);
    *param_1 = 0;
  }
  if ((void *)param_1[1] != (void *)0x0) {
    operator_delete((void *)param_1[1]);
    param_1[1] = 0;
  }
  return;
}



// Function: FUN_1000e590 at 1000e590

void __fastcall FUN_1000e590(undefined4 *param_1)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    LVar2 = InterlockedDecrement(piVar1 + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
        *piVar1 = 0;
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete((void *)piVar1[1]);
        piVar1[1] = 0;
      }
      operator_delete(piVar1);
    }
    *param_1 = 0;
  }
  return;
}



// Function: FUN_1000e5f0 at 1000e5f0

void __cdecl FUN_1000e5f0(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: FUN_1000e600 at 1000e600

int * __thiscall FUN_1000e600(void *this,int param_1)

{
  undefined **local_14;
  DWORD local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(int *)this = param_1;
  if (param_1 == 0) {
    local_10 = GetLastError();
    if (0 < (int)local_10) {
      local_10 = local_10 & 0xffff | 0x80070000;
    }
    local_14 = _com_error::vftable;
    local_c = 0;
    local_8 = 0;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_14,(ThrowInfo *)&DAT_1001996c);
  }
  return (int *)this;
}



// Function: FUN_1000e660 at 1000e660

int * __thiscall FUN_1000e660(void *this,int param_1)

{
  undefined **local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(int *)this = param_1;
  if (-1 < param_1) {
    return (int *)this;
  }
  local_10 = param_1;
  local_14 = _com_error::vftable;
  local_c = 0;
  local_8 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_1001996c);
}



// Function: FUN_1000e6a0 at 1000e6a0

int * __thiscall FUN_1000e6a0(void *this,int *param_1)

{
  int iVar1;
  
  if ((int *)this != param_1) {
    FUN_100102b0((undefined4 *)this);
    iVar1 = *param_1;
    *(int *)this = iVar1;
    if (iVar1 != 0) {
      InterlockedIncrement((LONG *)(iVar1 + 8));
    }
  }
  return (int *)this;
}



// Function: FUN_1000e6d0 at 1000e6d0

uint __thiscall FUN_1000e6d0(void *this,int param_1)

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



// Function: FUN_1000e6f0 at 1000e6f0

uint __thiscall FUN_1000e6f0(void *this,int param_1)

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



// Function: FUN_1000e710 at 1000e710

uint __thiscall FUN_1000e710(void *this,int param_1)

{
  code *pcVar1;
  uint uVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Load size is inaccurate */
    return (uint)(*this != 0);
  }
  _com_issue_error(-0x7fffbffd);
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



// Function: FUN_1000e730 at 1000e730

uint __thiscall FUN_1000e730(void *this,int param_1)

{
  code *pcVar1;
  uint uVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Load size is inaccurate */
    return (uint)(*this != 0);
  }
  _com_issue_error(-0x7fffbffd);
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



// Function: FUN_1000e780 at 1000e780

undefined4 __fastcall FUN_1000e780(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_1000e7f0 at 1000e7f0

void __fastcall FUN_1000e7f0(int *param_1)

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



// Function: FUN_1000e870 at 1000e870

int * __fastcall FUN_1000e870(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1000e890 at 1000e890

int * __fastcall FUN_1000e890(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1000e8b0 at 1000e8b0

int * __thiscall FUN_1000e8b0(void *this,byte param_1)

{
                    /* WARNING: Load size is inaccurate */
  if (*this != 0) {
    Ordinal_6(*this);
    *(undefined4 *)this = 0;
  }
  if (*(void **)((int)this + 4) != (void *)0x0) {
    operator_delete(*(void **)((int)this + 4));
    *(undefined4 *)((int)this + 4) = 0;
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (int *)this;
}



// Function: FUN_1000e900 at 1000e900

ULONG __fastcall FUN_1000e900(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[8].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_10015614);
  }
  return UVar1;
}



// Function: FUN_1000e940 at 1000e940

void FUN_1000e940(IID *param_1,LPCSTR param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_1000e960(param_1,param_2,0,(LPCSTR)0x0,param_3,param_4);
  return;
}



// Function: FUN_1000e960 at 1000e960

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1000e960(IID *param_1,LPCSTR param_2,int param_3,LPCSTR param_4,undefined4 param_5,
                 undefined4 param_6)

{
  char *pcVar1;
  undefined4 *puVar2;
  uint uVar3;
  char cVar4;
  LPWSTR pWVar5;
  LPWSTR pWVar6;
  long lVar7;
  LPCSTR pCVar8;
  undefined4 *_Memory;
  uint local_30;
  char *local_1c;
  undefined4 *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013a08;
  local_10 = ExceptionList;
  local_30 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_30;
  if (param_2 == (LPCSTR)0x0) goto LAB_1000ead6;
  _Memory = (undefined4 *)0x0;
  local_18 = (undefined4 *)0x0;
  local_8 = 0;
  pCVar8 = param_2;
  do {
    cVar4 = *pCVar8;
    pCVar8 = pCVar8 + 1;
  } while (cVar4 != '\0');
  pcVar1 = pCVar8 + (1 - (int)(param_2 + 1));
  uVar3 = (int)pcVar1 * 2;
  if ((((int)pcVar1 >> 0x1f) << 1 | (uint)pcVar1 >> 0x1f) + (uint)(0x7fffffff < uVar3) == 0) {
    if (((int)uVar3 < 0x401) && (cVar4 = FUN_1000d8f0(uVar3), cVar4 != '\0')) {
      pWVar5 = (LPWSTR)&local_30;
    }
    else {
      pWVar5 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                       CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                 ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)&local_18,
                                  uVar3);
      _Memory = local_18;
    }
    pWVar5 = FUN_10003280(pWVar5,param_2,(uint)pcVar1 & 0x7fffffff,3);
    if (pWVar5 != (LPWSTR)0x0) {
      pWVar6 = (LPWSTR)0x0;
      if (param_4 == (LPCSTR)0x0) {
LAB_1000ea94:
        FUN_1000eb00(param_1,pWVar5,param_3,(int)pWVar6,param_5,param_6,(HINSTANCE)0x0);
      }
      else {
        pCVar8 = param_4;
        do {
          cVar4 = *pCVar8;
          pCVar8 = pCVar8 + 1;
        } while (cVar4 != '\0');
        local_1c = pCVar8 + (1 - (int)(param_4 + 1));
        lVar7 = ATL::AtlMultiply<int>((int *)&local_1c,(int)local_1c,2);
        pcVar1 = local_1c;
        if (-1 < lVar7) {
          if (((int)local_1c < 0x401) && (cVar4 = FUN_1000d8f0((int)local_1c), cVar4 != '\0')) {
            pWVar6 = (LPWSTR)&local_30;
          }
          else {
            pWVar6 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                             CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                       ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)
                                        &local_18,(ulong)pcVar1);
            _Memory = local_18;
          }
          pWVar6 = FUN_10003280(pWVar6,param_4,(uint)pcVar1 >> 1,3);
          if (pWVar6 != (LPWSTR)0x0) goto LAB_1000ea94;
        }
      }
    }
  }
  local_8 = 0xffffffff;
  while (_Memory != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*_Memory;
    local_18 = puVar2;
    free(_Memory);
    _Memory = puVar2;
  }
LAB_1000ead6:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000eb00 at 1000eb00

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1000eb00(IID *param_1,LPWSTR param_2,int param_3,int param_4,undefined4 param_5,int param_6
                 ,HINSTANCE param_7)

{
  undefined4 *puVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  errno_t eVar5;
  LPWSTR pWVar6;
  char *pcVar7;
  undefined4 *_Memory;
  uint local_440;
  LPOLESTR local_424;
  undefined4 *local_420;
  int *local_41c;
  int *local_418;
  CHAR local_414 [1024];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10013a7d;
  local_10 = ExceptionList;
  local_440 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _Memory = (undefined4 *)0x0;
  local_420 = (undefined4 *)0x0;
  local_8 = 0;
  local_414[0] = '\0';
  local_14 = local_440;
  if (((uint)param_2 & 0xffff0000) == 0) {
    local_41c = (int *)((uint)param_2 & 0xffff);
    iVar4 = LoadStringA(param_7,(UINT)local_41c,local_414,0x400);
    if (iVar4 == 0) {
      eVar5 = strcpy_s(local_414,0x400,"Unknown Error");
      ATL::AtlCrtErrorCheck(eVar5);
    }
    pcVar7 = local_414;
    do {
      cVar3 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar3 != '\0');
    pcVar7 = pcVar7 + (1 - (int)(local_414 + 1));
    uVar2 = (int)pcVar7 * 2;
    if ((((int)pcVar7 >> 0x1f) << 1 | (uint)pcVar7 >> 0x1f) + (uint)(0x7fffffff < uVar2) == 0) {
      if (((int)uVar2 < 0x401) && (cVar3 = FUN_1000d8f0(uVar2), cVar3 != '\0')) {
        pWVar6 = (LPWSTR)&local_440;
      }
      else {
        pWVar6 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                         CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                   ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)
                                    &local_420,uVar2);
        _Memory = local_420;
      }
      param_2 = FUN_10003280(pWVar6,local_414,(uint)pcVar7 & 0x7fffffff,3);
      if (param_2 != (LPWSTR)0x0) goto LAB_1000ec5f;
    }
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
              ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)&local_420);
  }
  else {
LAB_1000ec5f:
    local_418 = (int *)0x0;
    local_8._0_1_ = 2;
    iVar4 = Ordinal_202(&local_418);
    if (-1 < iVar4) {
      local_41c = (int *)0x0;
      local_8 = CONCAT31(local_8._1_3_,4);
      (**(code **)(*local_418 + 0xc))(local_418,param_5);
      ProgIDFromCLSID(param_1,&local_424);
      if (local_424 != (LPOLESTR)0x0) {
        (**(code **)(*local_418 + 0x10))(local_418,local_424);
      }
      if ((param_3 != 0) && (param_4 != 0)) {
        (**(code **)(*local_418 + 0x1c))(local_418,param_3);
        (**(code **)(*local_418 + 0x18))(local_418,param_4);
      }
      CoTaskMemFree(local_424);
      (**(code **)(*local_418 + 0x14))(local_418,param_2);
      iVar4 = (**(code **)*local_418)(local_418,&DAT_10014d24,&local_41c);
      if (-1 < iVar4) {
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
    local_8 = 0xffffffff;
    while (_Memory != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*_Memory;
      local_420 = puVar1;
      free(_Memory);
      _Memory = puVar1;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000edd0 at 1000edd0

void __thiscall FUN_1000edd0(void *this,int param_1)

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



// Function: FUN_1000edf0 at 1000edf0

void __thiscall FUN_1000edf0(void *this,int param_1)

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



// Function: throwExceptionWithFileInfo at 1000ee10

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void throwExceptionWithFileInfo(void *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined8 param_5,undefined8 param_6)

{
  int *piVar1;
  undefined1 *puVar2;
  LPSTR pCVar3;
  HRESULT HVar4;
  void *this;
  uint uStack_207c;
  LPUNKNOWN local_2054;
  undefined1 *local_2050;
  int *local_204c;
  undefined4 local_2048;
  undefined4 local_2044;
  undefined4 local_2040;
  void *local_203c;
  undefined8 local_2038;
  undefined8 local_2030;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013b3f;
  local_10 = ExceptionList;
  uStack_207c = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_207c;
  ExceptionList = &local_10;
  local_2044 = param_2;
  local_2048 = param_4;
  local_2038 = param_5;
  local_2030 = param_6;
  local_2040 = *(undefined4 *)((int)param_1 + 4);
  local_18 = uStack_207c;
  FUN_1000fcc0(param_1,&local_204c);
  piVar1 = local_204c;
  local_8 = 0;
  if ((local_204c != (int *)0x0) && (local_204c[1] == 0)) {
    pCVar3 = ConvertBSTRToString((LPCWSTR)*local_204c);
    piVar1[1] = (int)pCVar3;
  }
  local_203c = (void *)0x0;
  HVar4 = CoCreateInstance((IID *)&DAT_10015668,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10014c54,&local_2054
                          );
  if (-1 < HVar4) {
    HVar4 = OleRun(local_2054);
    if (-1 < HVar4) {
      HVar4 = (*local_2054->lpVtbl->QueryInterface)(local_2054,(IID *)&DAT_10015624,&local_203c);
    }
    (*local_2054->lpVtbl->Release)(local_2054);
    if (-1 < HVar4) goto LAB_1000ef42;
  }
  local_203c = (void *)0x0;
  if ((HVar4 < 0) && (HVar4 != -0x7fffbffe)) {
    _com_issue_error(HVar4);
  }
LAB_1000ef42:
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 2;
  local_2050 = &stack0xffffdf80;
  puVar2 = &stack0xffffdf80;
  if (local_204c != (int *)0x0) {
    InterlockedIncrement(local_204c + 2);
    puVar2 = local_2050;
  }
  local_2050 = puVar2;
  local_8._0_1_ = 3;
  this = (void *)FUN_1000e7f0((int *)&local_203c);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_10010340(this,local_204c);
  local_8 = 1;
  FUN_1000f0d5();
  return;
}



// Function: Catch@1000ef95 at 1000ef95

undefined * Catch_1000ef95(void)

{
  IUnknown *extraout_ECX;
  int *extraout_ECX_00;
  void *extraout_ECX_01;
  void *extraout_ECX_02;
  IUnknown *extraout_ECX_03;
  int *extraout_ECX_04;
  void *extraout_ECX_05;
  void *pvVar1;
  IUnknown *extraout_ECX_06;
  IUnknown *pIVar2;
  int unaff_EBP;
  int *piVar3;
  
  pIVar2 = *(IUnknown **)(unaff_EBP + -0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar2 = extraout_ECX;
  }
  FUN_1000e900(pIVar2);
  if (*(LPCSTR *)(unaff_EBP + -0x2058) == (LPCSTR)0x0) {
    *(undefined1 *)(unaff_EBP + -0x2014) = 0;
    piVar3 = (int *)0x1fff;
    memset((void *)(unaff_EBP + -0x2013),0,0x1fff);
    FUN_1000ff50((ushort)*(undefined4 *)(unaff_EBP + -0x203c),(LPSTR)(unaff_EBP + -0x2014));
    *(undefined1 **)(unaff_EBP + -0x204c) = &stack0xfffffffc;
    FUN_1000e390(&stack0xfffffffc,(LPCSTR)(unaff_EBP + -0x2014));
    *(undefined1 *)(unaff_EBP + -4) = 5;
    pvVar1 = *(void **)(unaff_EBP + -0x2038);
    if (pvVar1 == (void *)0x0) {
      _com_issue_error(-0x7fffbffd);
      pvVar1 = extraout_ECX_01;
    }
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_1000ffe0(pvVar1,piVar3);
  }
  else {
    *(undefined1 **)(unaff_EBP + -0x204c) = &stack0xfffffffc;
    piVar3 = extraout_ECX_00;
    FUN_1000e390(&stack0xfffffffc,*(LPCSTR *)(unaff_EBP + -0x2058));
    *(undefined1 *)(unaff_EBP + -4) = 6;
    pvVar1 = *(void **)(unaff_EBP + -0x2038);
    if (pvVar1 == (void *)0x0) {
      _com_issue_error(-0x7fffbffd);
      pvVar1 = extraout_ECX_02;
    }
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_1000ffe0(pvVar1,piVar3);
  }
  pIVar2 = *(IUnknown **)(unaff_EBP + -0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar2 = extraout_ECX_03;
  }
  FUN_100100a0(pIVar2);
  *(undefined1 **)(unaff_EBP + -0x204c) = &stack0xfffffffc;
  piVar3 = extraout_ECX_04;
  FUN_1000e390(&stack0xfffffffc,"");
  *(undefined1 *)(unaff_EBP + -4) = 7;
  pvVar1 = *(void **)(unaff_EBP + -0x2038);
  if (pvVar1 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar1 = extraout_ECX_05;
  }
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_100100d0(pvVar1,piVar3);
  pIVar2 = *(IUnknown **)(unaff_EBP + -0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar2 = extraout_ECX_06;
  }
  FUN_10010190(pIVar2);
  return &DAT_1000f0c2;
}



// Function: FUN_1000f0d5 at 1000f0d5

/* WARNING: Removing unreachable block (ram,0x1000f382) */

void FUN_1000f0d5(void)

{
  int *piVar1;
  IUnknown *pIVar2;
  undefined4 *puVar3;
  uchar *puVar4;
  ULONG UVar5;
  int *extraout_EAX;
  int *piVar6;
  int *piVar7;
  LPSTR pCVar8;
  LPCSTR pCVar9;
  undefined4 uVar10;
  LONG LVar11;
  int *extraout_ECX;
  int *extraout_ECX_00;
  void *extraout_ECX_01;
  int *extraout_ECX_02;
  void *extraout_ECX_03;
  void *extraout_ECX_04;
  void *pvVar12;
  undefined4 uVar13;
  void *extraout_ECX_05;
  uchar *unaff_EBX;
  uint unaff_EBP;
  int unaff_EDI;
  undefined4 uStack00000004;
  
  *(undefined8 *)(unaff_EBP - 0x2024) = 0;
  *(undefined8 *)(unaff_EBP - 0x201c) = 0;
  if (*(int **)(unaff_EDI + 8) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_EDI + 8) + 4))();
  }
  piVar1 = *(int **)(unaff_EDI + 8);
  *(int **)(unaff_EBP - 0x204c) = piVar1;
  *(undefined1 *)(unaff_EBP - 4) = 8;
  if (piVar1 != (int *)0x0) {
    if (piVar1 == (int *)0x0) {
      _com_issue_error(-0x7fffbffd);
    }
    (**(code **)(*piVar1 + 0xc))(piVar1);
  }
  puVar4 = _mbsrchr(unaff_EBX,0x2f);
  if (puVar4 == (uchar *)0x0) {
    puVar4 = _mbsrchr(unaff_EBX,0x5c);
  }
  else {
    puVar4 = puVar4 + 1;
  }
  if (puVar4 != (uchar *)0x0) {
    unaff_EBX = puVar4 + 1;
  }
  pIVar2 = *(IUnknown **)(unaff_EBP - 0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  UVar5 = (*pIVar2->lpVtbl[8].Release)(pIVar2);
  piVar7 = extraout_ECX;
  if ((int)UVar5 < 0) {
    _com_issue_errorex(UVar5,pIVar2,(_GUID *)&DAT_10015614);
    piVar7 = extraout_ECX_00;
  }
  *(undefined1 **)(unaff_EBP - 0x2040) = &stack0xfffffffc;
  FUN_1000e390(&stack0xfffffffc,*(LPCSTR *)(unaff_EBP - 0x2044));
  *(undefined1 *)(unaff_EBP - 4) = 9;
  pvVar12 = *(void **)(unaff_EBP - 0x2038);
  if (pvVar12 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar12 = extraout_ECX_01;
  }
  *(undefined1 *)(unaff_EBP - 4) = 8;
  FUN_1000ffe0(pvVar12,piVar7);
  *(undefined1 **)(unaff_EBP - 0x2040) = &stack0xfffffffc;
  piVar7 = extraout_ECX_02;
  FUN_1000e390(&stack0xfffffffc,(LPCSTR)unaff_EBX);
  *(undefined1 *)(unaff_EBP - 4) = 10;
  pvVar12 = *(void **)(unaff_EBP - 0x2038);
  if (pvVar12 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar12 = extraout_ECX_03;
  }
  *(undefined1 *)(unaff_EBP - 4) = 8;
  FUN_100100d0(pvVar12,piVar7);
  pIVar2 = *(IUnknown **)(unaff_EBP - 0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  UVar5 = (*pIVar2->lpVtbl[4].Release)(pIVar2);
  if ((int)UVar5 < 0) {
    _com_issue_errorex(UVar5,pIVar2,(_GUID *)&DAT_10015614);
  }
  pIVar2 = *(IUnknown **)(unaff_EBP - 0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  uVar10 = *(undefined4 *)(unaff_EBP - 0x203c);
  uVar13 = uVar10;
  UVar5 = (*pIVar2->lpVtbl[5].Release)(pIVar2);
  if ((int)UVar5 < 0) {
    _com_issue_errorex(UVar5,pIVar2,(_GUID *)&DAT_10015614);
  }
  if (*(char *)(unaff_EBP + 0x28) != '\0') {
    *(undefined4 *)(unaff_EBP - 0x203c) = 0;
    *(undefined1 *)(unaff_EBP - 4) = 0xb;
    piVar7 = *(int **)(unaff_EBP - 0x203c);
    if (piVar7 != (int *)0x0) {
      (**(code **)(*piVar7 + 8))(piVar7,uVar13);
    }
    *(undefined4 *)(unaff_EBP - 0x203c) = 0;
    Ordinal_202(unaff_EBP - 0x203c);
    piVar7 = *(int **)(unaff_EBP - 0x203c);
    if (piVar7 == (int *)0x0) {
      _com_issue_error(-0x7fffbffd);
      piVar7 = extraout_EAX;
    }
    (**(code **)(*piVar7 + 0xc))(piVar7,unaff_EBP - 0x2024);
    piVar7 = *(int **)(unaff_EBP - 0x203c);
    if (piVar7 == (int *)0x0) {
      _com_issue_error(-0x7fffbffd);
    }
    pvVar12 = *(void **)(unaff_EBP - 0x2038);
    if (pvVar12 == (void *)0x0) {
      _com_issue_error(-0x7fffbffd);
      pvVar12 = extraout_ECX_04;
    }
    piVar6 = FUN_1000fe30(pvVar12,(undefined4 *)(unaff_EBP - 0x2040));
    *(undefined1 *)(unaff_EBP - 4) = 0xc;
    if ((undefined4 *)*piVar6 == (undefined4 *)0x0) {
      uVar13 = 0;
    }
    else {
      uVar13 = *(undefined4 *)*piVar6;
    }
    (**(code **)(*piVar7 + 0x14))(piVar7,uVar13);
    *(undefined1 *)(unaff_EBP - 4) = 0xb;
    FUN_1000e590((undefined4 *)(unaff_EBP - 0x2040));
    FUN_1000dca0((void *)(unaff_EBP - 0x2040),(int *)(unaff_EBP - 0x203c));
    *(undefined1 *)(unaff_EBP - 4) = 0xd;
    piVar7 = *(int **)(unaff_EBP - 0x2040);
    if (piVar7 != (int *)0x0) {
      if (piVar7 == (int *)0x0) {
        _com_issue_error(-0x7fffbffd);
      }
      (**(code **)(*piVar7 + 4))(piVar7);
      *(undefined ***)(unaff_EBP - 0x2068) = _com_error::vftable;
      *(undefined4 *)(unaff_EBP - 0x2064) = uVar10;
      *(int **)(unaff_EBP - 0x2060) = piVar7;
      *(undefined4 *)(unaff_EBP - 0x205c) = 0;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException((void *)(unaff_EBP - 0x2068),(ThrowInfo *)&DAT_1001996c);
    }
    *(undefined1 *)(unaff_EBP - 4) = 0xb;
    *(undefined1 *)(unaff_EBP - 4) = 8;
    piVar7 = *(int **)(unaff_EBP - 0x203c);
    if (piVar7 != (int *)0x0) {
      (**(code **)(*piVar7 + 8))(piVar7);
    }
  }
  pvVar12 = *(void **)(unaff_EBP - 0x2038);
  if (pvVar12 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar12 = extraout_ECX_05;
  }
  piVar7 = FUN_1000fe30(pvVar12,(undefined4 *)(unaff_EBP - 0x2044));
  *(undefined1 *)(unaff_EBP - 4) = 0xe;
  puVar3 = (undefined4 *)*piVar7;
  if (puVar3 == (undefined4 *)0x0) {
    pCVar9 = (LPCSTR)0x0;
  }
  else {
    if (puVar3[1] == 0) {
      pCVar8 = ConvertBSTRToString((LPCWSTR)*puVar3);
      puVar3[1] = pCVar8;
    }
    pCVar9 = (LPCSTR)puVar3[1];
  }
  uVar10 = FUN_1000e960((IID *)(unaff_EBP - 0x2034),pCVar9,0,(LPCSTR)0x0,unaff_EBP - 0x2024,uVar10);
  *(undefined4 *)(unaff_EBP - 0x2040) = uVar10;
  *(undefined1 *)(unaff_EBP - 4) = 8;
  piVar7 = *(int **)(unaff_EBP - 0x2044);
  if (piVar7 != (int *)0x0) {
    LVar11 = InterlockedDecrement(piVar7 + 2);
    if ((LVar11 == 0) && (piVar7 != (int *)0x0)) {
      if (*piVar7 != 0) {
        Ordinal_6(*piVar7);
        *piVar7 = 0;
      }
      if ((void *)piVar7[1] != (void *)0x0) {
        operator_delete((void *)piVar7[1]);
        piVar7[1] = 0;
      }
      operator_delete(piVar7);
    }
    *(undefined4 *)(unaff_EBP - 0x2044) = 0;
  }
  *(undefined1 *)(unaff_EBP - 4) = 1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined1 *)(unaff_EBP - 4) = 0;
  piVar1 = *(int **)(unaff_EBP - 0x2038);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  piVar1 = *(int **)(unaff_EBP - 0x2048);
  if (piVar1 != (int *)0x0) {
    LVar11 = InterlockedDecrement(piVar1 + 2);
    if ((LVar11 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
        *piVar1 = 0;
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete((void *)piVar1[1]);
        piVar1[1] = 0;
      }
      operator_delete(piVar1);
    }
    *(undefined4 *)(unaff_EBP - 0x2048) = 0;
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack00000004 = 0x1000f4f7;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_1000f500 at 1000f500

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_1000f500(undefined4 param_1,uchar *param_2)

{
  char *in_stack_00000018;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,in_stack_00000018,&stack0x0000001c);
  FUN_1000f740(param_2);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000f570 at 1000f570

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_1000f570(uchar *param_1)

{
  char *in_stack_00000018;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,in_stack_00000018,&stack0x0000001c);
  FUN_1000f740(param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: assertFailure at 1000f5e0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl assertFailure(uchar *param_1)

{
  char *in_stack_00000014;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,in_stack_00000014,&stack0x00000018);
  FUN_1000f740(param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000f650 at 1000f650

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_1000f650(uchar *param_1)

{
  char *in_stack_0000001c;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,in_stack_0000001c,&stack0x00000020);
  FUN_1000f740(param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000f6c0 at 1000f6c0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_1000f6c0(uchar *param_1)

{
  char *in_stack_0000001c;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,in_stack_0000001c,&stack0x00000020);
  FUN_1000f740(param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000f740 at 1000f740

/* WARNING: Removing unreachable block (ram,0x1000f90e) */

void __cdecl FUN_1000f740(uchar *param_1)

{
  byte bVar1;
  IID *pIVar2;
  int *piVar3;
  void **ppvObject;
  HRESULT HVar4;
  uint uVar5;
  int *extraout_EAX;
  IUnknown *extraout_EAX_00;
  int iVar6;
  ULONG UVar7;
  uchar *puVar8;
  undefined4 **ppuVar9;
  IUnknown *extraout_EAX_01;
  IUnknown *pIVar10;
  int *extraout_EAX_02;
  int *extraout_EAX_03;
  int *piVar11;
  byte *pbVar12;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  IUnknown *extraout_ECX_04;
  int *extraout_ECX_05;
  int *extraout_ECX_06;
  IUnknown *extraout_ECX_07;
  IUnknown *extraout_ECX_08;
  undefined4 uVar13;
  undefined4 *puVar14;
  bool bVar15;
  int in_stack_00000014;
  byte *in_stack_00000018;
  undefined4 in_stack_00000020;
  LPCSTR in_stack_00000024;
  undefined **local_3c [2];
  int *local_34;
  undefined4 local_30;
  int *local_2c;
  undefined4 *local_28;
  IID *local_24;
  LPUNKNOWN local_20;
  int *local_1c;
  int *local_18;
  IUnknown *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10013bc3;
  local_10 = ExceptionList;
  ppvObject = (void **)(DAT_1001b638 ^ (uint)&stack0xfffffffc);
  ExceptionList = &local_10;
  local_1c = (int *)0x0;
  local_18 = (int *)0x0;
  local_8 = 1;
  local_14 = (IUnknown *)0x0;
  HVar4 = CoCreateInstance((IID *)&DAT_10015668,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10014c54,&local_20);
  if (HVar4 < 0) {
LAB_1000f7d4:
    local_14 = (IUnknown *)0x0;
    if ((HVar4 < 0) && (HVar4 != -0x7fffbffe)) {
      _com_issue_error(HVar4);
    }
  }
  else {
    HVar4 = OleRun(local_20);
    if (-1 < HVar4) {
      HVar4 = (*local_20->lpVtbl->QueryInterface)(local_20,(IID *)&DAT_10015624,&local_14);
    }
    (*local_20->lpVtbl->Release)(local_20);
    if (HVar4 < 0) goto LAB_1000f7d4;
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  pbVar12 = PTR_s_APPEND_1001b5fc;
  do {
    bVar1 = *in_stack_00000018;
    bVar15 = bVar1 < *pbVar12;
    if (bVar1 != *pbVar12) {
LAB_1000f820:
      uVar5 = -(uint)bVar15 | 1;
      goto LAB_1000f825;
    }
    if (bVar1 == 0) break;
    bVar1 = in_stack_00000018[1];
    bVar15 = bVar1 < pbVar12[1];
    if (bVar1 != pbVar12[1]) goto LAB_1000f820;
    in_stack_00000018 = in_stack_00000018 + 2;
    pbVar12 = pbVar12 + 2;
  } while (bVar1 != 0);
  uVar5 = 0;
LAB_1000f825:
  if (uVar5 == 0) {
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))();
    }
    local_18 = (int *)0x0;
    Ordinal_200(0);
    if (local_18 != (int *)0x0) {
      FUN_1000de00(&local_1c,(int *)&local_18);
      local_24 = (IID *)0x0;
      piVar11 = local_18;
      if (local_18 == (int *)0x0) {
        _com_issue_error(-0x7fffbffd);
        piVar11 = extraout_EAX;
      }
      (**(code **)(*piVar11 + 0x14))(piVar11);
      pIVar2 = local_24;
      if (local_24 != (IID *)0x0) {
        local_2c = (int *)operator_new(0xc);
        local_8._1_3_ = (uint3)((uint)local_8 >> 8);
        if (local_2c == (int *)0x0) {
          local_2c = (int *)0x0;
        }
        else {
          local_2c[1] = 0;
          local_2c[2] = 1;
          *local_2c = (int)pIVar2;
        }
        local_8._0_1_ = 2;
        if (local_2c == (int *)0x0) {
          _com_issue_error(-0x7ff8fff2);
        }
        local_8._0_1_ = 4;
        pIVar10 = local_14;
        if (local_14 == (IUnknown *)0x0) {
          _com_issue_error(-0x7fffbffd);
          pIVar10 = extraout_EAX_00;
        }
        (*pIVar10->lpVtbl[9].QueryInterface)(pIVar10,local_24,ppvObject);
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_1000e590(&local_2c);
      }
    }
  }
  if (local_1c == (int *)0x0) {
    local_1c = (int *)0x0;
    Ordinal_202();
    local_2c = (int *)&stack0xffffffb4;
    piVar11 = local_1c;
    piVar3 = (int *)&stack0xffffffb4;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 4))(local_1c);
      piVar3 = local_2c;
    }
    local_2c = piVar3;
    local_8 = CONCAT31((int3)((uint)local_8 >> 8),2);
    iVar6 = FUN_1000de80(&local_18,piVar11);
    if ((iVar6 < 0) && (iVar6 != -0x7fffbffe)) {
      _com_issue_error(iVar6);
    }
  }
  pIVar10 = local_14;
  if (local_1c == (int *)0x0) {
    local_8._0_1_ = 1;
    if (local_14 != (IUnknown *)0x0) {
      (*local_14->lpVtbl->Release)(local_14);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))();
    }
    local_8 = 0xffffffff;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))();
    }
    ExceptionList = local_10;
    return;
  }
  puVar14 = (undefined4 *)0x0;
  local_28 = (undefined4 *)0x0;
  local_8 = CONCAT31(local_8._1_3_,6);
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  UVar7 = (*pIVar10->lpVtbl[8].Release)(pIVar10);
  piVar11 = extraout_ECX;
  if ((int)UVar7 < 0) {
    _com_issue_errorex(UVar7,pIVar10,(_GUID *)&DAT_10015614);
    piVar11 = extraout_ECX_00;
  }
  pIVar10 = local_14;
  if (in_stack_00000014 == 1) {
    if (local_14 == (IUnknown *)0x0) {
      _com_issue_error(-0x7fffbffd);
    }
    UVar7 = (*pIVar10->lpVtbl[9].Release)(pIVar10);
    piVar11 = extraout_ECX_02;
  }
  else {
    if (in_stack_00000014 != 2) {
      if (in_stack_00000014 != 3) goto LAB_1000fa1f;
      if (local_14 == (IUnknown *)0x0) {
        _com_issue_error(-0x7fffbffd);
      }
      UVar7 = (*pIVar10->lpVtbl[9].Release)(pIVar10);
      if ((int)UVar7 < 0) {
        _com_issue_errorex(UVar7,pIVar10,(_GUID *)&DAT_10015624);
      }
    }
    pIVar10 = local_14;
    if (local_14 == (IUnknown *)0x0) {
      _com_issue_error(-0x7fffbffd);
    }
    UVar7 = (*pIVar10->lpVtbl[10].AddRef)(pIVar10);
    piVar11 = extraout_ECX_01;
  }
  if ((int)UVar7 < 0) {
    _com_issue_errorex(UVar7,pIVar10,(_GUID *)&DAT_10015624);
    piVar11 = extraout_ECX_03;
  }
LAB_1000fa1f:
  local_2c = (int *)&stack0xffffffb4;
  FUN_1000e390(&stack0xffffffb4,in_stack_00000024);
  local_8._0_1_ = 7;
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar10 = extraout_ECX_04;
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_1000ffe0(pIVar10,piVar11);
  puVar8 = _mbsrchr(param_1,0x2f);
  if (puVar8 == (uchar *)0x0) {
    puVar8 = _mbsrchr(param_1,0x5c);
    piVar11 = extraout_ECX_06;
  }
  else {
    puVar8 = puVar8 + 1;
    piVar11 = extraout_ECX_05;
  }
  if (puVar8 != (uchar *)0x0) {
    param_1 = puVar8 + 1;
  }
  local_2c = (int *)&stack0xffffffb4;
  FUN_1000e390(&stack0xffffffb4,(LPCSTR)param_1);
  local_8._0_1_ = 8;
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar10 = extraout_ECX_07;
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_100100d0(pIVar10,piVar11);
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  UVar7 = (*pIVar10->lpVtbl[4].Release)(pIVar10);
  if ((int)UVar7 < 0) {
    _com_issue_errorex(UVar7,pIVar10,(_GUID *)&DAT_10015614);
  }
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  UVar7 = (*pIVar10->lpVtbl[5].Release)(pIVar10);
  if ((int)UVar7 < 0) {
    _com_issue_errorex(UVar7,pIVar10,(_GUID *)&DAT_10015614);
  }
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar10 = extraout_ECX_08;
  }
  ppuVar9 = (undefined4 **)FUN_1000fe30(pIVar10,&local_2c);
  local_8._0_1_ = 9;
  if (&local_28 != ppuVar9) {
    FUN_100102b0(&local_28);
    puVar14 = *ppuVar9;
    local_28 = puVar14;
    if (puVar14 != (undefined4 *)0x0) {
      InterlockedIncrement(puVar14 + 2);
    }
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_1000e590(&local_2c);
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar10 = extraout_EAX_01;
  }
  (*pIVar10->lpVtbl->Release)(pIVar10);
  local_14 = (IUnknown *)0x0;
  piVar11 = local_1c;
  if (local_1c == (int *)0x0) {
    _com_issue_error(-0x7fffbffd);
    piVar11 = extraout_EAX_02;
  }
  (**(code **)(*piVar11 + 0xc))(piVar11,in_stack_00000020);
  piVar11 = local_1c;
  if (local_1c == (int *)0x0) {
    _com_issue_error(-0x7fffbffd);
    piVar11 = extraout_EAX_03;
  }
  if (puVar14 == (undefined4 *)0x0) {
    uVar13 = 0;
  }
  else {
    uVar13 = *puVar14;
  }
  (**(code **)(*piVar11 + 0x14))(piVar11,uVar13);
  Ordinal_201(0,local_18);
  local_3c[0] = _com_error::vftable;
  local_34 = local_18;
  local_30 = 0;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 4))(local_18);
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_3c,(ThrowInfo *)&DAT_1001996c);
}



// Function: FUN_1000fc30 at 1000fc30

HRESULT __thiscall FUN_1000fc30(void *this,IID *param_1,LPUNKNOWN param_2,LPUNKNOWN param_3)

{
  int *piVar1;
  HRESULT HVar2;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if (((uint)param_3 & 0x14) == 0) {
    HVar2 = CoCreateInstance(param_1,param_2,(DWORD)param_3,(IID *)&DAT_10015624,(LPVOID *)this);
  }
  else {
    HVar2 = CoCreateInstance(param_1,param_2,(DWORD)param_3,(IID *)&DAT_10014c54,&param_3);
    if (HVar2 < 0) goto LAB_1000fca9;
    HVar2 = OleRun(param_3);
    if (-1 < HVar2) {
      HVar2 = (*param_3->lpVtbl->QueryInterface)(param_3,(IID *)&DAT_10015624,(void **)this);
    }
    (*param_3->lpVtbl->Release)(param_3);
  }
  if (-1 < HVar2) {
    return HVar2;
  }
LAB_1000fca9:
  *(undefined4 *)this = 0;
  return HVar2;
}



// Function: FUN_1000fcc0 at 1000fcc0

undefined4 * __thiscall FUN_1000fcc0(void *this,undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *extraout_ECX;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013c04;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = *(int **)((int)this + 8);
  local_14 = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x14))(piVar1,&local_14,DAT_1001b638 ^ (uint)&stack0xfffffffc);
  }
  uVar2 = local_14;
  puVar3 = (undefined4 *)operator_new(0xc);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[1] = 0;
    puVar3[2] = 1;
    *puVar3 = uVar2;
  }
  local_8 = 0;
  *param_1 = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    param_1 = extraout_ECX;
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000fd80 at 1000fd80

undefined4 __fastcall FUN_1000fd80(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
    return *(undefined4 *)(param_1 + 8);
  }
  return 0;
}



// Function: FUN_1000fe00 at 1000fe00

undefined4 __fastcall FUN_1000fe00(undefined4 *param_1)

{
  LPSTR pCVar1;
  
  if (param_1[1] == 0) {
    pCVar1 = ConvertBSTRToString((LPCWSTR)*param_1);
    param_1[1] = pCVar1;
  }
  return param_1[1];
}



// Function: FUN_1000fe30 at 1000fe30

undefined4 * __thiscall FUN_1000fe30(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *extraout_ECX;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013c44;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  local_14 = 0;
  iVar2 = (**(code **)(*this + 0x3c))(this,&local_14,DAT_1001b638 ^ (uint)&stack0xfffffffc);
  if (iVar2 < 0) {
    _com_issue_errorex(iVar2,(IUnknown *)this,(_GUID *)&DAT_10015614);
  }
  uVar1 = local_14;
  puVar3 = (undefined4 *)operator_new(0xc);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[1] = 0;
    puVar3[2] = 1;
    *puVar3 = uVar1;
  }
  local_8 = 0;
  *param_1 = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    param_1 = extraout_ECX;
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000fef0 at 1000fef0

uint __cdecl FUN_1000fef0(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FUN_1000ff10 at 1000ff10

uchar * __cdecl FUN_1000ff10(uchar *param_1)

{
  uchar *puVar1;
  
  puVar1 = _mbsrchr(param_1,0x2f);
  if (puVar1 == (uchar *)0x0) {
    puVar1 = _mbsrchr(param_1,0x5c);
  }
  else {
    puVar1 = puVar1 + 1;
  }
  if (puVar1 == (uchar *)0x0) {
    return param_1;
  }
  return puVar1 + 1;
}



// Function: FUN_1000ff50 at 1000ff50

undefined4 __cdecl FUN_1000ff50(ushort param_1,LPSTR param_2)

{
  FormatMessageA(0x1200,(LPCVOID)0x0,(uint)param_1,0x400,param_2,0x2000,(va_list *)0x0);
  return 0;
}



// Function: FUN_1000ff80 at 1000ff80

void __fastcall FUN_1000ff80(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[10].AddRef)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_10015624);
  }
  return;
}



// Function: FUN_1000ffb0 at 1000ffb0

void __fastcall FUN_1000ffb0(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[9].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_10015624);
  }
  return;
}



// Function: FUN_1000ffe0 at 1000ffe0

void __thiscall FUN_1000ffe0(void *this,int *param_1)

{
  int iVar1;
  LONG LVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10013c68;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (param_1 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *param_1;
  }
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0x28))(this,iVar1,DAT_1001b638 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_10015614);
  }
  local_8 = 0xffffffff;
  if (((param_1 != (int *)0x0) && (LVar2 = InterlockedDecrement(param_1 + 2), LVar2 == 0)) &&
     (param_1 != (int *)0x0)) {
    if (*param_1 != 0) {
      Ordinal_6(*param_1);
      *param_1 = 0;
    }
    if ((void *)param_1[1] != (void *)0x0) {
      operator_delete((void *)param_1[1]);
      param_1[1] = 0;
    }
    operator_delete(param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100100a0 at 100100a0

void __fastcall FUN_100100a0(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[5].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_10015614);
  }
  return;
}



// Function: FUN_100100d0 at 100100d0

void __thiscall FUN_100100d0(void *this,int *param_1)

{
  int iVar1;
  LONG LVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10013c98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (param_1 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *param_1;
  }
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0x30))(this,iVar1,DAT_1001b638 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_10015614);
  }
  local_8 = 0xffffffff;
  if (((param_1 != (int *)0x0) && (LVar2 = InterlockedDecrement(param_1 + 2), LVar2 == 0)) &&
     (param_1 != (int *)0x0)) {
    if (*param_1 != 0) {
      Ordinal_6(*param_1);
      *param_1 = 0;
    }
    if ((void *)param_1[1] != (void *)0x0) {
      operator_delete((void *)param_1[1]);
      param_1[1] = 0;
    }
    operator_delete(param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10010190 at 10010190

void __fastcall FUN_10010190(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[4].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_10015614);
  }
  return;
}



// Function: FUN_100101c0 at 100101c0

void __fastcall FUN_100101c0(int *param_1)

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



// Function: FUN_100101f0 at 100101f0

LONG __fastcall FUN_100101f0(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 2);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    if (*param_1 != 0) {
      Ordinal_6(*param_1);
      *param_1 = 0;
    }
    if ((void *)param_1[1] != (void *)0x0) {
      operator_delete((void *)param_1[1]);
      param_1[1] = 0;
    }
    operator_delete(param_1);
  }
  return LVar1;
}



// Function: FUN_10010280 at 10010280

void __fastcall FUN_10010280(int *param_1)

{
  if (*param_1 != 0) {
    Ordinal_6(*param_1);
    *param_1 = 0;
  }
  if ((void *)param_1[1] != (void *)0x0) {
    operator_delete((void *)param_1[1]);
    param_1[1] = 0;
  }
  return;
}



// Function: FUN_100102b0 at 100102b0

void __fastcall FUN_100102b0(undefined4 *param_1)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    LVar2 = InterlockedDecrement(piVar1 + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
        *piVar1 = 0;
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete((void *)piVar1[1]);
        piVar1[1] = 0;
      }
      operator_delete(piVar1);
    }
    *param_1 = 0;
  }
  return;
}



// Function: FUN_10010340 at 10010340

HRESULT __thiscall FUN_10010340(void *this,int *param_1)

{
  int iVar1;
  LONG LVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10013cc8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (param_1 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *param_1;
  }
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0x6c))(this,iVar1,DAT_1001b638 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_10015614);
  }
  local_8 = 0xffffffff;
  if (((param_1 != (int *)0x0) && (LVar2 = InterlockedDecrement(param_1 + 2), LVar2 == 0)) &&
     (param_1 != (int *)0x0)) {
    if (*param_1 != 0) {
      Ordinal_6(*param_1);
      *param_1 = 0;
    }
    if ((void *)param_1[1] != (void *)0x0) {
      operator_delete((void *)param_1[1]);
      param_1[1] = 0;
    }
    operator_delete(param_1);
  }
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_10010410 at 10010410

void __cdecl FUN_10010410(char *param_1,rsize_t param_2,char *param_3)

{
  errno_t eVar1;
  
  eVar1 = strcpy_s(param_1,param_2,param_3);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: FUN_10010430 at 10010430

void FUN_10010430(uchar *param_1,uint param_2)

{
                    /* WARNING: Could not recover jumptable at 0x10010434. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _mbsrchr(param_1,param_2);
  return;
}



// Function: CAtlBaseModule at 100105bd

/* Library Function - Single Match
    public: __thiscall ATL::CAtlBaseModule::CAtlBaseModule(void)
   
   Library: Visual Studio 2012 Release */

CAtlBaseModule * __thiscall ATL::CAtlBaseModule::CAtlBaseModule(CAtlBaseModule *this)

{
  long lVar1;
  
  _ATL_BASE_MODULE70::_ATL_BASE_MODULE70((_ATL_BASE_MODULE70 *)this);
  *(undefined4 *)this = 0x38;
  *(undefined4 *)(this + 8) = 0x10000000;
  *(undefined4 *)(this + 4) = 0x10000000;
  *(undefined4 *)(this + 0xc) = 0xb00;
  *(undefined **)(this + 0x10) = &DAT_100172f4;
  lVar1 = CComCriticalSection::Init((CComCriticalSection *)(this + 0x14));
  if (lVar1 < 0) {
    DAT_1001b65c = 1;
  }
  return this;
}



// Function: FUN_100105fb at 100105fb

undefined4 * __thiscall FUN_100105fb(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  return (undefined4 *)this;
}



// Function: _ATL_BASE_MODULE70 at 1001060b

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



// Function: ~CAtlBaseModule at 10010633

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



// Function: operator[] at 10010651

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



// Function: Add at 1001067b

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
      FUN_100032d0(0x80004005);
      pcVar2 = (code *)swi(3);
      iVar4 = (*pcVar2)();
      return iVar4;
    }
    if (iVar4 == 0) {
      _Count = 1;
LAB_100106b2:
      pvVar3 = _recalloc(_Memory,_Count,4);
      if (pvVar3 != (void *)0x0) {
        *(uint *)(this + 8) = _Count;
        *(void **)this = pvVar3;
        goto LAB_100106c7;
      }
    }
    else {
      _Count = *(int *)(this + 4) * 2;
      if ((-1 < (int)_Count) && (_Count < 0x20000000)) goto LAB_100106b2;
    }
    iVar4 = 0;
  }
  else {
LAB_100106c7:
    puVar1 = (undefined4 *)(*(int *)this + *(int *)(this + 4) * 4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = *param_1;
    }
    *(int *)(this + 4) = *(int *)(this + 4) + 1;
    iVar4 = 1;
  }
  return iVar4;
}



// Function: AddResourceInstance at 100106f3

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



// Function: GetHInstanceAt at 10010726

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



// Function: InternalSetAtIndex at 1001076f

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



// Function: RemoveAll at 10010789

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



// Function: RemoveAt at 100107a6

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



// Function: RemoveResourceInstance at 100107ee

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



// Function: memmove_s at 1001084b

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



// Function: CAtlComModule at 1001086a

/* Library Function - Single Match
    public: __thiscall ATL::CAtlComModule::CAtlComModule(void)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

CAtlComModule * __thiscall ATL::CAtlComModule::CAtlComModule(CAtlComModule *this)

{
  long lVar1;
  
  _ATL_COM_MODULE70::_ATL_COM_MODULE70((_ATL_COM_MODULE70 *)this);
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0x10000000;
  *(undefined **)(this + 8) = &DAT_10019b58;
  *(undefined **)(this + 0xc) = &DAT_10019b58;
  lVar1 = CComCriticalSection::Init((CComCriticalSection *)(this + 0x10));
  if (lVar1 < 0) {
    DAT_1001b65c = 1;
  }
  else {
    *(undefined4 *)this = 0x28;
  }
  return this;
}



// Function: _ATL_COM_MODULE70 at 100108a9

/* Library Function - Single Match
    public: __thiscall ATL::_ATL_COM_MODULE70::_ATL_COM_MODULE70(void)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

_ATL_COM_MODULE70 * __thiscall ATL::_ATL_COM_MODULE70::_ATL_COM_MODULE70(_ATL_COM_MODULE70 *this)

{
  memset(this + 0x10,0,0x18);
  return this;
}



// Function: Term at 100108c6

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



// Function: `vector_constructor_iterator' at 10010910

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



// Function: `vector_destructor_iterator' at 1001092f

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



// Function: _com_dispatch_method at 10010960

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
    (*(code *)PTR_FUN_1001b600)(lVar1,local_8);
  }
  return lVar1;
}



// Function: _com_dispatch_propget at 100109a0

/* Library Function - Single Match
    long __stdcall _com_dispatch_propget(struct IDispatch *,long,unsigned short,void *)
   
   Library: Visual Studio 2012 Release */

long _com_dispatch_propget(IDispatch *param_1,long param_2,ushort param_3,void *param_4)

{
  long lVar1;
  
  lVar1 = _com_dispatch_method(param_1,param_2,2,param_3,param_4,(ushort *)0x0);
  return lVar1;
}



// Function: _com_dispatch_propput at 100109c0

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
    (*(code *)PTR_FUN_1001b600)(lVar2,local_c);
  }
  return lVar2;
}



// Function: _com_issue_error at 10010a20

/* Library Function - Single Match
    void __stdcall _com_issue_error(long)
   
   Library: Visual Studio 2012 Release */

void _com_issue_error(long param_1)

{
  (*(code *)PTR_FUN_1001b600)(param_1,0);
  return;
}



// Function: _com_issue_errorex at 10010a40

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
     (HVar1 = (*param_2->lpVtbl->QueryInterface)(param_2,(IID *)&DAT_10014f00,&param_2),
     ppuVar3 = local_8, -1 < HVar1)) {
    HVar1 = (*param_2->lpVtbl[1].QueryInterface)(param_2,param_3,unaff_ESI);
    (*param_2->lpVtbl->Release)(param_2);
    ppuVar3 = local_8;
    if (HVar1 == 0) {
      local_8 = &local_8;
      iVar2 = Ordinal_200(0);
      local_8 = (undefined4 **)(~-(uint)(iVar2 != 0) & (uint)local_8);
      (*(code *)PTR_FUN_1001b600)(param_1,local_8);
      return;
    }
  }
  local_8 = ppuVar3;
  (*(code *)PTR_FUN_1001b600)(param_1);
  return;
}



// Function: FUN_10010ac0 at 10010ac0

void FUN_10010ac0(undefined *param_1)

{
  PTR_FUN_1001b600 = param_1;
  return;
}



// Function: _variant_t at 10010ad0

/* Library Function - Single Match
    public: __thiscall _variant_t::_variant_t(long,unsigned short)
   
   Library: Visual Studio 2012 Release */

_variant_t * __thiscall _variant_t::_variant_t(_variant_t *this,long param_1,ushort param_2)

{
  code *pcVar1;
  _variant_t *p_Var2;
  
  if (param_2 != 3) {
    if (param_2 == 10) goto LAB_10010aef;
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
LAB_10010aef:
  *(undefined2 *)this = 10;
  *(long *)(this + 8) = param_1;
  return this;
}



// Function: ConvertBSTRToString at 10010b60

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
  puStack_c = &LAB_10013cf0;
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



// Function: Catch_All@10010c63 at 10010c63

undefined * Catch_All_10010c63(void)

{
  return &DAT_10010c69;
}



// Function: ConvertStringToBSTR at 10010c80

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
  pcStack_10 = FUN_10011d3b;
  local_14 = ExceptionList;
  local_c = DAT_1001b638 ^ 0x100199a0;
  uVar1 = DAT_1001b638 ^ (uint)&stack0xfffffffc;
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



// Function: FUN_10010e00 at 10010e00

uint FUN_10010e00(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FUN_10010e20 at 10010e20

void FUN_10010e20(undefined4 param_1,undefined4 param_2)

{
  undefined **local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = param_1;
  local_c = param_2;
  local_14 = _com_error::vftable;
  local_8 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_1001996c);
}



// Function: _com_dispatch_raw_method at 10010e50

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



// Function: _com_dispatch_raw_propget at 10010e90

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



// Function: _com_dispatch_raw_propput at 10010eb0

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



// Function: _com_invoke_helper at 10010f10

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
  pcStack_10 = FUN_10011d3b;
  local_14 = ExceptionList;
  local_c = DAT_1001b638 ^ 0x10019a18;
  local_8c = DAT_1001b638 ^ (uint)&stack0xfffffffc;
  local_1c = (undefined1 *)&local_8c;
  ExceptionList = &local_14;
  local_20 = local_8c;
  puVar15 = &local_8c;
  if (param_1 == (IDispatch *)0x0) goto LAB_10011285;
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
    if (local_3c == 0) goto LAB_10011285;
    local_38 = 1;
    local_40 = &local_54;
  }
  if (local_3c != 0) {
    local_1c = (undefined1 *)&local_8c;
    local_34 = &local_8c;
    local_8 = 0xfffffffe;
    uStack_9c = 0x10010fdc;
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
switchD_10011055_caseD_f:
            puVar15 = (uint *)local_1c;
            if ((uVar1 & 0x2000) == 0) goto LAB_10011285;
          }
switchD_10011055_caseD_3:
          piVar12 = piVar11 + 1;
          piVar7 = piVar7 + 1;
          *piVar14 = *piVar7;
          goto LAB_10011140;
        }
        if (uVar4 == 0x4002) goto switchD_10011055_caseD_3;
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
          goto switchD_10011055_caseD_3;
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
          goto switchD_10011055_caseD_f;
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
LAB_10011140:
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
  iVar13 = (**(code **)(*(int *)param_1 + 0x18))(param_1,param_2,&DAT_10014cdc,0,_param_3,&local_44)
  ;
  if (iVar13 < 0) {
    Ordinal_9(&local_30);
    puVar15 = (uint *)local_1c;
    if (iVar13 == -0x7ffdfff7) {
      _com_handle_excepinfo((tagEXCEPINFO *)&local_78,param_8);
      puVar15 = (uint *)local_1c;
    }
    goto LAB_10011285;
  }
  puVar15 = (uint *)local_1c;
  if ((param_4 == 0) || (param_5 == (void *)0x0)) goto LAB_10011285;
  if ((param_4 != 0xc) &&
     ((param_4 != (ushort)local_30 &&
      (iVar13 = Ordinal_12(&local_30,&local_30,0,_param_4), iVar13 < 0)))) {
    Ordinal_9(&local_30);
    puVar15 = (uint *)local_1c;
    goto LAB_10011285;
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
        goto switchD_1001132f_caseD_3;
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
        goto switchD_1001132f_caseD_f;
      case 0x10:
      case 0x11:
        *(undefined1 *)param_5 = local_28;
      }
      goto LAB_10011285;
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
switchD_1001132f_caseD_f:
      if ((param_4 & 0x2000) == 0) {
        Ordinal_9(&local_30);
        puVar15 = (uint *)local_1c;
        goto LAB_10011285;
      }
    }
  }
switchD_1001132f_caseD_3:
  *(uint *)param_5 = CONCAT22(uStack_26,CONCAT11(uStack_27,local_28));
LAB_10011285:
  local_1c = (undefined1 *)puVar15;
  ExceptionList = local_14;
  lVar3 = __security_check_cookie(local_20 ^ (uint)&stack0xfffffffc);
  return lVar3;
}



// Function: FUN_100114c0 at 100114c0

int FUN_100114c0(ushort param_1)

{
  if (0xfdff < param_1) {
    return -0x7ffb0001;
  }
  return param_1 + 0x80040200;
}



// Function: _com_handle_excepinfo at 100114f0

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
      (**(code **)(*(int *)param_1 + 0xc))(param_1,&DAT_10014c70);
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
      iVar4 = (*(code *)**(undefined4 **)param_1)(param_1,&DAT_10014d24,ppIVar3);
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



// Function: `eh_vector_destructor_iterator' at 100115e6

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
  FUN_10011645();
  return;
}



// Function: FUN_10011645 at 10011645

void FUN_10011645(void)

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



// Function: FUN_10011655 at 10011655

undefined4 __cdecl FUN_10011655(undefined4 *param_1)

{
  undefined4 extraout_EAX;
  
  if (*(int *)*param_1 != -0x1f928c9d) {
    return 0;
  }
  terminate();
  return extraout_EAX;
}



// Function: __ArrayUnwind at 1001166e

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



// Function: __onexit at 10011708

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
  
  local_8 = &DAT_10019a78;
  uStack_c = 0x10011714;
  local_20[0] = DecodePointer(DAT_1001bac0);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_1001bac0);
    local_24 = DecodePointer(DAT_1001babc);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_1001bac0 = EncodePointer(local_20[0]);
    DAT_1001babc = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_100117a4();
  }
  return p_Var1;
}



// Function: FUN_100117a4 at 100117a4

void FUN_100117a4(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 100117ad

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2012 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: ___raise_securityfailure at 100117c2

/* Library Function - Single Match
    ___raise_securityfailure
   
   Library: Visual Studio 2012 Release */

void __cdecl ___raise_securityfailure(EXCEPTION_POINTERS *param_1)

{
  DAT_1001ba9c = IsDebuggerPresent();
  _crt_debugger_hook(1);
  __crtUnhandledException(param_1);
  if (DAT_1001ba9c == 0) {
    _crt_debugger_hook(1);
  }
  __crtTerminateProcess(0xc0000409);
  return;
}



// Function: ___report_gsfailure at 100117ff

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
  _DAT_1001b878 = (undefined4)((ulonglong)uVar9 >> 0x20);
  _DAT_1001b880 = (undefined4)uVar9;
  _DAT_1001b890 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 | (uint)(bVar4 & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_1001b894 = &stack0x00000004;
  _DAT_1001b7d0 = 0x10001;
  _DAT_1001b780 = 0xc0000409;
  _DAT_1001b784 = 1;
  _DAT_1001b790 = 1;
  DAT_1001b794 = 2;
  _DAT_1001b78c = unaff_retaddr;
  _DAT_1001b85c = in_GS;
  _DAT_1001b860 = in_FS;
  _DAT_1001b864 = in_ES;
  _DAT_1001b868 = in_DS;
  _DAT_1001b86c = unaff_EDI;
  _DAT_1001b870 = unaff_ESI;
  _DAT_1001b874 = unaff_EBX;
  _DAT_1001b87c = uVar3;
  _DAT_1001b884 = unaff_EBP;
  DAT_1001b888 = unaff_retaddr;
  _DAT_1001b88c = in_CS;
  _DAT_1001b898 = in_SS;
  ___raise_securityfailure((EXCEPTION_POINTERS *)&PTR_DAT_100173bc);
  return;
}



// Function: ___report_rangecheckfailure at 100118f8

/* Library Function - Single Match
    ___report_rangecheckfailure
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___report_rangecheckfailure(void)

{
  ___report_securityfailure(8);
  return;
}



// Function: ___report_securityfailure at 10011904

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
  _DAT_1001b878 = (undefined4)((ulonglong)uVar9 >> 0x20);
  _DAT_1001b880 = (undefined4)uVar9;
  _DAT_1001b890 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 | (uint)(bVar4 & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_1001b894 = &param_1;
  _DAT_1001b780 = 0xc0000409;
  _DAT_1001b784 = 1;
  _DAT_1001b790 = 1;
  DAT_1001b794 = param_1;
  _DAT_1001b78c = unaff_retaddr;
  _DAT_1001b85c = in_GS;
  _DAT_1001b860 = in_FS;
  _DAT_1001b864 = in_ES;
  _DAT_1001b868 = in_DS;
  _DAT_1001b86c = unaff_EDI;
  _DAT_1001b870 = unaff_ESI;
  _DAT_1001b874 = unaff_EBX;
  _DAT_1001b87c = uVar3;
  _DAT_1001b884 = unaff_EBP;
  DAT_1001b888 = unaff_retaddr;
  _DAT_1001b88c = in_CS;
  _DAT_1001b898 = in_SS;
  ___raise_securityfailure((EXCEPTION_POINTERS *)&PTR_DAT_100173bc);
  return;
}



// Function: ___report_securityfailureEx at 100119d2

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
  _DAT_1001b890 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 | (uint)(bVar4 & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_1001b894 = &param_1;
  _DAT_1001b780 = 0xc0000409;
  _DAT_1001b784 = 1;
  if ((param_2 != 0) && (param_3 == 0)) {
    param_2 = 0;
  }
  if (0xe < param_2) {
    param_2 = param_2 - 1;
  }
  _DAT_1001b790 = param_2 + 1;
  DAT_1001b794 = param_1;
  _DAT_1001b78c = unaff_retaddr;
  _DAT_1001b85c = in_GS;
  _DAT_1001b860 = in_FS;
  _DAT_1001b864 = in_ES;
  _DAT_1001b868 = in_DS;
  _DAT_1001b86c = unaff_EDI;
  _DAT_1001b870 = unaff_ESI;
  _DAT_1001b874 = unaff_EBX;
  _DAT_1001b87c = uVar3;
  _DAT_1001b884 = unaff_EBP;
  DAT_1001b888 = unaff_retaddr;
  _DAT_1001b88c = in_CS;
  _DAT_1001b898 = in_SS;
  for (local_8 = 0; _DAT_1001b878 = (undefined4)((ulonglong)uVar9 >> 0x20),
      _DAT_1001b880 = (undefined4)uVar9, local_8 < param_2; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_1001b798 + local_8 * 4) = *(undefined4 *)(param_3 + local_8 * 4);
    uVar9 = CONCAT44(_DAT_1001b878,_DAT_1001b880);
  }
  ___raise_securityfailure((EXCEPTION_POINTERS *)&PTR_DAT_100173bc);
  return;
}



// Function: __security_check_cookie at 10011b10

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Library: Visual Studio 2012 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_1001b638) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: __alloca_probe_16 at 10011b30

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



// Function: __alloca_probe_8 at 10011b46

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



// Function: FID_conflict:`vector_deleting_destructor' at 10011b6c

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



// Function: `eh_vector_constructor_iterator' at 10011bc0

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
  FUN_10011c18();
  return;
}



// Function: FUN_10011c18 at 10011c18

void FUN_10011c18(void)

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



// Function: FUN_10011c40 at 10011c40

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_10011c40(uint param_1)

{
  operator_new(param_1);
  FUN_10011c68();
  return;
}



// Function: Catch_All@10011c5b at 10011c5b

undefined * Catch_All_10011c5b(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  return &DAT_10011c65;
}



// Function: FUN_10011c68 at 10011c68

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10011c68(void)

{
  return;
}



// Function: FUN_10011c6e at 10011c6e

void FUN_10011c6e(uint param_1)

{
  FUN_10011c40(param_1);
  return;
}



// Function: FUN_10011c77 at 10011c77

void __cdecl FUN_10011c77(void *param_1)

{
  operator_delete(param_1);
  return;
}



// Function: FUN_10011c85 at 10011c85

void __cdecl FUN_10011c85(void *param_1)

{
  operator_delete__(param_1);
  return;
}



// Function: __allmul at 10011cd0

/* Library Function - Single Match
    __allmul
   
   Library: Visual Studio 2010 Debug */

longlong __allmul(uint param_1,int param_2,uint param_3,int param_4)

{
  if (param_4 == 0 && param_2 == 0) {
    return (ulonglong)param_1 * (ulonglong)param_3;
  }
  return CONCAT44((int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20) +
                  param_2 * param_3 + param_1 * param_4,
                  (int)((ulonglong)param_1 * (ulonglong)param_3));
}



// Function: __alloca_probe at 10011d10

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



// Function: FUN_10011d3b at 10011d3b

void __cdecl
FUN_10011d3b(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_1001b638,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: __CRT_INIT@12 at 10011db1

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
    if (DAT_1001baa4 < 1) {
      return 0;
    }
    DAT_1001baa4 = DAT_1001baa4 + -1;
    bVar1 = false;
    do {
      pvVar3 = (void *)0x0;
      LOCK();
      pvVar2 = StackBase;
      if (DAT_1001bab0 != (void *)0x0) {
        pvVar3 = DAT_1001bab0;
        pvVar2 = DAT_1001bab0;
      }
      DAT_1001bab0 = pvVar2;
      UNLOCK();
      if (pvVar3 == (void *)0x0) goto LAB_10011e04;
    } while (pvVar3 != StackBase);
    bVar1 = true;
LAB_10011e04:
    if (DAT_1001bab4 == 2) {
      _Memory = (int *)DecodePointer(DAT_1001bac0);
      if (_Memory != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_1001babc);
        param_1 = piVar4;
        param_2 = _Memory;
        param_3 = _Memory;
        while (piVar4 = piVar4 + -1, _Memory <= piVar4) {
          if ((*piVar4 != 0) && (pvVar5 = EncodePointer((PVOID)0x0), (PVOID)*piVar4 != pvVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            pvVar5 = EncodePointer((PVOID)0x0);
            *piVar4 = (int)pvVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_1001bac0);
            piVar8 = (int *)DecodePointer(DAT_1001babc);
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
        DAT_1001babc = EncodePointer((PVOID)0x0);
        DAT_1001bac0 = DAT_1001babc;
      }
      DAT_1001bab4 = 0;
      if (!bVar1) {
        LOCK();
        DAT_1001bab0 = (void *)0x0;
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
      if (DAT_1001bab0 != (void *)0x0) {
        pvVar3 = DAT_1001bab0;
        pvVar2 = DAT_1001bab0;
      }
      DAT_1001bab0 = pvVar2;
      UNLOCK();
      if (pvVar3 == (void *)0x0) goto LAB_10011f1f;
    } while (pvVar3 != StackBase);
    bVar1 = true;
LAB_10011f1f:
    if (DAT_1001bab4 == 0) {
      DAT_1001bab4 = 1;
      iVar9 = initterm_e(&DAT_10014200,&DAT_1001420c);
      if (iVar9 != 0) {
        return 0;
      }
      initterm(&DAT_100141e4,&DAT_100141fc);
      DAT_1001bab4 = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      LOCK();
      DAT_1001bab0 = (void *)0x0;
      UNLOCK();
    }
    if ((DAT_1001bab8 != (code *)0x0) &&
       (BVar10 = __IsNonwritableInCurrentImage((PBYTE)&DAT_1001bab8), BVar10 != 0)) {
      (*DAT_1001bab8)(param_1,2,param_3);
    }
    DAT_1001baa4 = DAT_1001baa4 + 1;
  }
  return 1;
}



// Function: entry at 10011fa6

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_1,param_2,param_3);
  return;
}



// Function: ___DllMainCRTStartup at 10011fc9

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x1001207a) */
/* WARNING: Removing unreachable block (ram,0x10012010) */
/* WARNING: Removing unreachable block (ram,0x100120ac) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2012 Release */

uint __cdecl ___DllMainCRTStartup(HMODULE param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  
  _DAT_1001b640 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_1001baa4 == 0)) {
    uVar1 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (uVar1 = __CRT_INIT_12(&param_1->unused,param_2,param_3), uVar1 != 0)) {
    uVar1 = FUN_100039c0(param_1,(int)param_2);
    if ((param_2 == (int *)0x1) && (uVar1 == 0)) {
      FUN_100039c0(param_1,0);
      __CRT_INIT_12(&param_1->unused,(int *)0x0,param_3);
    }
    if ((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) {
      iVar2 = __CRT_INIT_12(&param_1->unused,param_2,param_3);
      uVar1 = uVar1 & -(uint)(iVar2 != 0);
    }
  }
  FUN_100120f1();
  return uVar1;
}



// Function: FUN_100120f1 at 100120f1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100120f1(void)

{
  _DAT_1001b640 = 0xffffffff;
  return;
}



// Function: __SEH_prolog4 at 10012120

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1001b638 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 10012165

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



// Function: __EH_epilog3 at 100121aa

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



// Function: __EH_prolog3_catch at 10012245

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1001b638 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __FindPESection at 100122d0

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



// Function: __IsNonwritableInCurrentImage at 10012320

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
  
  pcStack_10 = FUN_10011d3b;
  local_14 = ExceptionList;
  local_c = DAT_1001b638 ^ 0x10019b38;
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



// Function: __ValidateImageBase at 100123e0

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



// Function: ___security_init_cookie at 10012411

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
  if ((DAT_1001b638 == 0xbb40e64e) || ((DAT_1001b638 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_10);
    local_8 = local_10.dwHighDateTime ^ local_10.dwLowDateTime;
    DVar1 = GetCurrentThreadId();
    local_8 = local_8 ^ DVar1;
    DVar1 = GetCurrentProcessId();
    local_8 = local_8 ^ DVar1;
    QueryPerformanceCounter(&local_18);
    DAT_1001b638 = local_18.s.HighPart ^ local_18.s.LowPart ^ local_8 ^ (uint)&local_8;
    if (DAT_1001b638 == 0xbb40e64e) {
      DAT_1001b638 = 0xbb40e64f;
    }
    else if ((DAT_1001b638 & 0xffff0000) == 0) {
      DAT_1001b638 = DAT_1001b638 | (DAT_1001b638 | 0x4711) << 0x10;
    }
    DAT_1001b63c = ~DAT_1001b638;
  }
  else {
    DAT_1001b63c = ~DAT_1001b638;
  }
  return;
}



// Function: FUN_100124b2 at 100124b2

void FUN_100124b2(void)

{
  undefined4 *puVar1;
  
  for (puVar1 = &DAT_10017fbc; puVar1 < &DAT_10017fbc; puVar1 = puVar1 + 1) {
    if ((code *)*puVar1 != (code *)0x0) {
      (*(code *)*puVar1)();
    }
  }
  return;
}



// Function: FUN_100124d2 at 100124d2

void FUN_100124d2(void)

{
  undefined4 *puVar1;
  
  for (puVar1 = &DAT_10017fc4; puVar1 < &DAT_10017fc4; puVar1 = puVar1 + 1) {
    if ((code *)*puVar1 != (code *)0x0) {
      (*(code *)*puVar1)();
    }
  }
  return;
}



// Function: FUN_100124fe at 100124fe

void FUN_100124fe(void)

{
  __clean_type_info_names_internal(&DAT_1001baa8);
  return;
}



// Function: Unwind@10012560 at 10012560

void Unwind_10012560(void)

{
  int unaff_EBP;
  
  ~_ExceptionPtr_static<>(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@10012586 at 10012586

void Unwind_10012586(void)

{
  int unaff_EBP;
  
  ~_ExceptionPtr_static<>(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@100125ac at 100125ac

void Unwind_100125ac(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100125cf at 100125cf

void Unwind_100125cf(void)

{
  int unaff_EBP;
  
  FUN_10002de0((int *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@100125d7 at 100125d7

void Unwind_100125d7(void)

{
  int unaff_EBP;
  
  FUN_10002e50((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100125df at 100125df

void Unwind_100125df(void)

{
  int unaff_EBP;
  
  FUN_10002e50((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@100125e7 at 100125e7

void Unwind_100125e7(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10012614 at 10012614

void Unwind_10012614(void)

{
  int unaff_EBP;
  
  FUN_10002de0((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001261c at 1001261c

void Unwind_1001261c(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001263f at 1001263f

void Unwind_1001263f(void)

{
  int unaff_EBP;
  
  FUN_10002de0((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10012647 at 10012647

void Unwind_10012647(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001266a at 1001266a

void Unwind_1001266a(void)

{
  int unaff_EBP;
  
  FUN_10002de0((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10012672 at 10012672

void Unwind_10012672(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10012695 at 10012695

void Unwind_10012695(void)

{
  int unaff_EBP;
  
  FUN_10002de0((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001269d at 1001269d

void Unwind_1001269d(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100126c0 at 100126c0

void Unwind_100126c0(void)

{
  int unaff_EBP;
  
  FUN_10002de0((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100126c8 at 100126c8

void Unwind_100126c8(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100126eb at 100126eb

void Unwind_100126eb(void)

{
  int unaff_EBP;
  
  FUN_10002de0((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100126f3 at 100126f3

void Unwind_100126f3(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10012716 at 10012716

void Unwind_10012716(void)

{
  int unaff_EBP;
  
  FUN_10002de0((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001271e at 1001271e

void Unwind_1001271e(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10012741 at 10012741

void Unwind_10012741(void)

{
  int unaff_EBP;
  
  FUN_10002e50((undefined4 *)(unaff_EBP + -0xab8));
  return;
}



// Function: Unwind@1001274c at 1001274c

void Unwind_1001274c(void)

{
  int unaff_EBP;
  
  FUN_10002e50((undefined4 *)(unaff_EBP + -0xab0));
  return;
}



// Function: Unwind@10012757 at 10012757

void Unwind_10012757(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0xb28));
  return;
}



// Function: Unwind@10012762 at 10012762

void Unwind_10012762(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xadc) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xadc) = *(uint *)(unaff_EBP + -0xadc) & 0xfffffffe;
    FUN_10002e50(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100127b0 at 100127b0

void Unwind_100127b0(void)

{
  FUN_10002e80();
  return;
}



// Function: Unwind@100127b8 at 100127b8

void Unwind_100127b8(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100127e0 at 100127e0

void Unwind_100127e0(void)

{
  int unaff_EBP;
  
  FUN_10002d60(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012810 at 10012810

void Unwind_10012810(void)

{
  int unaff_EBP;
  
  FUN_10002d60(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012840 at 10012840

void Unwind_10012840(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012870 at 10012870

void Unwind_10012870(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100128a0 at 100128a0

void Unwind_100128a0(void)

{
  int unaff_EBP;
  
  FUN_10002e90(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100128d0 at 100128d0

void Unwind_100128d0(void)

{
  FUN_10002e70();
  return;
}



// Function: Unwind@10012900 at 10012900

void Unwind_10012900(void)

{
  FUN_10002e80();
  return;
}



// Function: Unwind@10012908 at 10012908

void Unwind_10012908(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10012930 at 10012930

void Unwind_10012930(void)

{
  int unaff_EBP;
  
  FUN_10002d60(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012960 at 10012960

void Unwind_10012960(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012990 at 10012990

void Unwind_10012990(void)

{
  int unaff_EBP;
  
  FUN_10002e90(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100129c0 at 100129c0

void Unwind_100129c0(void)

{
  FUN_10002e70();
  return;
}



// Function: Unwind@100129f0 at 100129f0

void Unwind_100129f0(void)

{
  int unaff_EBP;
  
  FUN_10002e50(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012a20 at 10012a20

void Unwind_10012a20(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10012a50 at 10012a50

void Unwind_10012a50(void)

{
  int unaff_EBP;
  
  FUN_10004db0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012a80 at 10012a80

void Unwind_10012a80(void)

{
  int unaff_EBP;
  
  _anon_026BA49F::_ExceptionPtr_normal::~_ExceptionPtr_normal
            ((_ExceptionPtr_normal *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10012a8b at 10012a8b

void Unwind_10012a8b(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@10012ac0 at 10012ac0

void Unwind_10012ac0(void)

{
  int unaff_EBP;
  
  FUN_10001070(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012af0 at 10012af0

void Unwind_10012af0(void)

{
  int unaff_EBP;
  
  FUN_10001070(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012b20 at 10012b20

void Unwind_10012b20(void)

{
  int unaff_EBP;
  
  FUN_10004e10(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012b50 at 10012b50

void Unwind_10012b50(void)

{
  FUN_10002e80();
  return;
}



// Function: Unwind@10012b80 at 10012b80

void Unwind_10012b80(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012bb0 at 10012bb0

void Unwind_10012bb0(void)

{
  int unaff_EBP;
  
  FUN_10004c70(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012be0 at 10012be0

void Unwind_10012be0(void)

{
  int unaff_EBP;
  
  FUN_10004ca0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012c10 at 10012c10

void Unwind_10012c10(void)

{
  int unaff_EBP;
  
  FUN_10004ca0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012c40 at 10012c40

void Unwind_10012c40(void)

{
  int unaff_EBP;
  
  FUN_10004cd0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012c70 at 10012c70

void Unwind_10012c70(void)

{
  int unaff_EBP;
  
  FUN_10004d00(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012ca0 at 10012ca0

void Unwind_10012ca0(void)

{
  FUN_10004fd0();
  return;
}



// Function: Unwind@10012cd0 at 10012cd0

void Unwind_10012cd0(void)

{
  int unaff_EBP;
  
  ~_ExceptionPtr_static<>(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10012d00 at 10012d00

void Unwind_10012d00(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012d30 at 10012d30

void Unwind_10012d30(void)

{
  int unaff_EBP;
  
  FUN_10004d30(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012d60 at 10012d60

void Unwind_10012d60(void)

{
  int unaff_EBP;
  
  FID_conflict__CAtlWinModule((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10012d90 at 10012d90

void Unwind_10012d90(void)

{
  FUN_10002e70();
  return;
}



// Function: Unwind@10012dc0 at 10012dc0

void Unwind_10012dc0(void)

{
  int unaff_EBP;
  
  FUN_10002e50(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012df0 at 10012df0

void Unwind_10012df0(void)

{
  int unaff_EBP;
  
  FUN_10004db0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012e20 at 10012e20

void Unwind_10012e20(void)

{
  int unaff_EBP;
  
  _anon_026BA49F::_ExceptionPtr_normal::~_ExceptionPtr_normal
            ((_ExceptionPtr_normal *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10012e2b at 10012e2b

void Unwind_10012e2b(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@10012e60 at 10012e60

void Unwind_10012e60(void)

{
  int unaff_EBP;
  
  FUN_10001070(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012e90 at 10012e90

void Unwind_10012e90(void)

{
  int unaff_EBP;
  
  FUN_10001070(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012ec0 at 10012ec0

void Unwind_10012ec0(void)

{
  int unaff_EBP;
  
  FUN_10004e10(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012ef0 at 10012ef0

void Unwind_10012ef0(void)

{
  FUN_10002e80();
  return;
}



// Function: Unwind@10012f20 at 10012f20

void Unwind_10012f20(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012f50 at 10012f50

void Unwind_10012f50(void)

{
  int unaff_EBP;
  
  FUN_10004c70(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012f80 at 10012f80

void Unwind_10012f80(void)

{
  int unaff_EBP;
  
  FUN_10004ca0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012fb0 at 10012fb0

void Unwind_10012fb0(void)

{
  int unaff_EBP;
  
  FUN_10004cd0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012fe0 at 10012fe0

void Unwind_10012fe0(void)

{
  int unaff_EBP;
  
  FUN_10004d00(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013010 at 10013010

void Unwind_10013010(void)

{
  FUN_10004fd0();
  return;
}



// Function: Unwind@10013040 at 10013040

void Unwind_10013040(void)

{
  int unaff_EBP;
  
  ~_ExceptionPtr_static<>(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10013070 at 10013070

void Unwind_10013070(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100130a0 at 100130a0

void Unwind_100130a0(void)

{
  int unaff_EBP;
  
  FUN_10004d30(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100130d0 at 100130d0

void Unwind_100130d0(void)

{
  int unaff_EBP;
  
  FID_conflict__CAtlWinModule((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10013100 at 10013100

void Unwind_10013100(void)

{
  FUN_10002e70();
  return;
}



// Function: Unwind@10013130 at 10013130

void Unwind_10013130(void)

{
  int unaff_EBP;
  
  FUN_10004820((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10013138 at 10013138

void Unwind_10013138(void)

{
  int unaff_EBP;
  
  FUN_10004840((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10013160 at 10013160

void Unwind_10013160(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10013190 at 10013190

void Unwind_10013190(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100131c0 at 100131c0

void Unwind_100131c0(void)

{
  int unaff_EBP;
  
  ~CTempBuffer<>((int *)(unaff_EBP + -0x121c));
  return;
}



// Function: Unwind@100131cb at 100131cb

void Unwind_100131cb(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x1250));
  return;
}



// Function: Unwind@100131d6 at 100131d6

void Unwind_100131d6(void)

{
  int unaff_EBP;
  
  ~CTempBuffer<>((int *)(unaff_EBP + -0x1118));
  return;
}



// Function: Unwind@10013210 at 10013210

void Unwind_10013210(void)

{
  int unaff_EBP;
  
  ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
  ~CComCritSecLock<class_ATL::CComCriticalSection>
            ((CComCritSecLock<class_ATL::CComCriticalSection> *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10013240 at 10013240

void Unwind_10013240(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x130));
  return;
}



// Function: Unwind@10013280 at 10013280

void Unwind_10013280(void)

{
  int unaff_EBP;
  
  ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
  ~CComCritSecLock<class_ATL::CComCriticalSection>
            ((CComCritSecLock<class_ATL::CComCriticalSection> *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100132b0 at 100132b0

void Unwind_100132b0(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((int *)(unaff_EBP + -0x124));
  return;
}



// Function: Unwind@100132bb at 100132bb

void Unwind_100132bb(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x148));
  return;
}



// Function: Unwind@100132c6 at 100132c6

void Unwind_100132c6(void)

{
  int unaff_EBP;
  
  FUN_10004f50((CRegKey *)(unaff_EBP + -0x17c));
  return;
}



// Function: Unwind@100132d1 at 100132d1

void Unwind_100132d1(void)

{
  int unaff_EBP;
  
  FUN_10004f50((CRegKey *)(unaff_EBP + -0x16c));
  return;
}



// Function: Unwind@10013310 at 10013310

void Unwind_10013310(void)

{
  int unaff_EBP;
  
  FUN_10002e50((undefined4 *)(unaff_EBP + -0x22c));
  return;
}



// Function: Unwind@1001331b at 1001331b

void Unwind_1001331b(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10013326 at 10013326

void Unwind_10013326(void)

{
  int unaff_EBP;
  
  FUN_10002e50((undefined4 *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10013360 at 10013360

void Unwind_10013360(void)

{
  int unaff_EBP;
  
  FUN_10002e50((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10013368 at 10013368

void Unwind_10013368(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10013390 at 10013390

void Unwind_10013390(void)

{
  int unaff_EBP;
  
  FUN_10011c77(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100133c0 at 100133c0

void Unwind_100133c0(void)

{
  int unaff_EBP;
  
  FUN_10011c77(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100133f0 at 100133f0

void Unwind_100133f0(void)

{
  int unaff_EBP;
  
  FUN_10011c77(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10013420 at 10013420

void Unwind_10013420(void)

{
  int unaff_EBP;
  
  ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
  ~CComCritSecLock<class_ATL::CComCriticalSection>
            ((CComCritSecLock<class_ATL::CComCriticalSection> *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10013450 at 10013450

void Unwind_10013450(void)

{
  int unaff_EBP;
  
  ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
  ~CComCritSecLock<class_ATL::CComCriticalSection>
            ((CComCritSecLock<class_ATL::CComCriticalSection> *)(unaff_EBP + -0x154));
  return;
}



// Function: Unwind@1001345b at 1001345b

void Unwind_1001345b(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x134));
  return;
}



// Function: Unwind@10013466 at 10013466

void Unwind_10013466(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((int *)(unaff_EBP + -0x128));
  return;
}



// Function: Unwind@10013471 at 10013471

void Unwind_10013471(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((int *)(unaff_EBP + -0x130));
  return;
}



// Function: Unwind@1001347c at 1001347c

void Unwind_1001347c(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((int *)(unaff_EBP + -300));
  return;
}



// Function: Unwind@100134b0 at 100134b0

void Unwind_100134b0(void)

{
  FUN_10003a30();
  return;
}



// Function: Unwind@100134c9 at 100134c9

void Unwind_100134c9(void)

{
  FUN_10003a40();
  return;
}



// Function: Unwind@10013500 at 10013500

void Unwind_10013500(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10013508 at 10013508

void Unwind_10013508(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10013530 at 10013530

void Unwind_10013530(void)

{
  int unaff_EBP;
  
  FUN_10011c85(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10013542 at 10013542

void Unwind_10013542(void)

{
  int unaff_EBP;
  
  FUN_10002e50((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10013570 at 10013570

void Unwind_10013570(void)

{
  int unaff_EBP;
  
  FUN_10004f30(unaff_EBP + -0x58);
  return;
}



// Function: Unwind@100135a0 at 100135a0

void Unwind_100135a0(void)

{
  int unaff_EBP;
  
  FUN_10004f50((CRegKey *)(unaff_EBP + -0x128));
  return;
}



// Function: Unwind@100135e0 at 100135e0

void Unwind_100135e0(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x430));
  return;
}



// Function: Unwind@100135eb at 100135eb

void Unwind_100135eb(void)

{
  int unaff_EBP;
  
  ~CTempBuffer<>((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@10013620 at 10013620

void Unwind_10013620(void)

{
  int unaff_EBP;
  
  FUN_10004f50((CRegKey *)(unaff_EBP + -0x112c));
  return;
}



// Function: Unwind@1001362b at 1001362b

void Unwind_1001362b(void)

{
  int unaff_EBP;
  
  FUN_10004f50((CRegKey *)(unaff_EBP + -0x1140));
  return;
}



// Function: Unwind@10013636 at 10013636

void Unwind_10013636(void)

{
  int unaff_EBP;
  
  FUN_10004f50((CRegKey *)(unaff_EBP + -0x1160));
  return;
}



// Function: Unwind@10013641 at 10013641

void Unwind_10013641(void)

{
  int unaff_EBP;
  
  FUN_10004f50((CRegKey *)(unaff_EBP + -0x1170));
  return;
}



// Function: Unwind@1001364c at 1001364c

void Unwind_1001364c(void)

{
  int unaff_EBP;
  
  FUN_10004f50((CRegKey *)(unaff_EBP + -0x1180));
  return;
}



// Function: Unwind@10013680 at 10013680

void Unwind_10013680(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100136b0 at 100136b0

void Unwind_100136b0(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100136e0 at 100136e0

void Unwind_100136e0(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10013710 at 10013710

void Unwind_10013710(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10013740 at 10013740

void Unwind_10013740(void)

{
  int unaff_EBP;
  
  FUN_10004f70((undefined4 *)(unaff_EBP + -0x96c));
  return;
}



// Function: Unwind@1001374b at 1001374b

void Unwind_1001374b(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x940));
  return;
}



// Function: Unwind@10013780 at 10013780

void Unwind_10013780(void)

{
  int unaff_EBP;
  
  FUN_10004f70((undefined4 *)(unaff_EBP + -0x970));
  return;
}



// Function: Unwind@1001378b at 1001378b

void Unwind_1001378b(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x944));
  return;
}



// Function: Unwind@100137c0 at 100137c0

void Unwind_100137c0(void)

{
  DAT_1001b6ac = DAT_1001b6ac & 0xfffffffe;
  return;
}



// Function: Unwind@100137f0 at 100137f0

void Unwind_100137f0(void)

{
  int unaff_EBP;
  
  FUN_1000e540(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013820 at 10013820

void Unwind_10013820(void)

{
  int unaff_EBP;
  
  FUN_1000e540(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013850 at 10013850

void Unwind_10013850(void)

{
  int unaff_EBP;
  
  FUN_1000e550(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013880 at 10013880

void Unwind_10013880(void)

{
  int unaff_EBP;
  
  FUN_1000e540((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100138b0 at 100138b0

void Unwind_100138b0(void)

{
  int unaff_EBP;
  
  FUN_1000e550((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100138e0 at 100138e0

void Unwind_100138e0(void)

{
  int unaff_EBP;
  
  FUN_1000e510(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013910 at 10013910

void Unwind_10013910(void)

{
  int unaff_EBP;
  
  FUN_1000e520(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013940 at 10013940

void Unwind_10013940(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013970 at 10013970

void Unwind_10013970(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100139a0 at 100139a0

void Unwind_100139a0(void)

{
  int unaff_EBP;
  
  FUN_1000e510(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100139d0 at 100139d0

void Unwind_100139d0(void)

{
  int unaff_EBP;
  
  FUN_1000e520(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013a00 at 10013a00

void Unwind_10013a00(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10013a30 at 10013a30

void Unwind_10013a30(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x41c));
  return;
}



// Function: Unwind@10013a3b at 10013a3b

void Unwind_10013a3b(void)

{
  int unaff_EBP;
  
  FUN_1000e510((int *)(unaff_EBP + -0x414));
  return;
}



// Function: Unwind@10013a46 at 10013a46

void Unwind_10013a46(void)

{
  int unaff_EBP;
  
  FUN_1000e470((int *)(unaff_EBP + -0x414));
  return;
}



// Function: Unwind@10013a51 at 10013a51

void Unwind_10013a51(void)

{
  int unaff_EBP;
  
  FUN_1000e520((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@10013a5c at 10013a5c

void Unwind_10013a5c(void)

{
  int unaff_EBP;
  
  FUN_1000e4c0((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@10013a67 at 10013a67

void Unwind_10013a67(void)

{
  int unaff_EBP;
  
  FUN_1000e520((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@10013a72 at 10013a72

void Unwind_10013a72(void)

{
  int unaff_EBP;
  
  FUN_1000e510((int *)(unaff_EBP + -0x414));
  return;
}



// Function: Unwind@10013ab0 at 10013ab0

void Unwind_10013ab0(void)

{
  int unaff_EBP;
  
  FUN_1000e590((undefined4 *)(unaff_EBP + -0x2048));
  return;
}



// Function: Unwind@10013abb at 10013abb

void Unwind_10013abb(void)

{
  int unaff_EBP;
  
  FUN_1000e530((int *)(unaff_EBP + -0x2038));
  return;
}



// Function: Unwind@10013ac6 at 10013ac6

void Unwind_10013ac6(void)

{
  int unaff_EBP;
  
  FUN_1000e590(*(undefined4 **)(unaff_EBP + -0x204c));
  return;
}



// Function: Unwind@10013ad1 at 10013ad1

void Unwind_10013ad1(void)

{
  int unaff_EBP;
  
  FUN_1000e590(*(undefined4 **)(unaff_EBP + -0x204c));
  return;
}



// Function: Unwind@10013adc at 10013adc

void Unwind_10013adc(void)

{
  int unaff_EBP;
  
  FUN_1000e590(*(undefined4 **)(unaff_EBP + -0x204c));
  return;
}



// Function: Unwind@10013ae7 at 10013ae7

void Unwind_10013ae7(void)

{
  int unaff_EBP;
  
  FUN_1000e590(*(undefined4 **)(unaff_EBP + -0x204c));
  return;
}



// Function: Unwind@10013af2 at 10013af2

void Unwind_10013af2(void)

{
  int unaff_EBP;
  
  FUN_1000e550((int *)(unaff_EBP + -0x204c));
  return;
}



// Function: Unwind@10013afd at 10013afd

void Unwind_10013afd(void)

{
  int unaff_EBP;
  
  FUN_1000e590(*(undefined4 **)(unaff_EBP + -0x2040));
  return;
}



// Function: Unwind@10013b08 at 10013b08

void Unwind_10013b08(void)

{
  int unaff_EBP;
  
  FUN_1000e590(*(undefined4 **)(unaff_EBP + -0x2040));
  return;
}



// Function: Unwind@10013b13 at 10013b13

void Unwind_10013b13(void)

{
  int unaff_EBP;
  
  FUN_1000e540((int *)(unaff_EBP + -0x203c));
  return;
}



// Function: Unwind@10013b1e at 10013b1e

void Unwind_10013b1e(void)

{
  int unaff_EBP;
  
  FUN_1000e590((undefined4 *)(unaff_EBP + -0x2040));
  return;
}



// Function: Unwind@10013b29 at 10013b29

void Unwind_10013b29(void)

{
  int unaff_EBP;
  
  FUN_1000e550((int *)(unaff_EBP + -0x2040));
  return;
}



// Function: Unwind@10013b34 at 10013b34

void Unwind_10013b34(void)

{
  int unaff_EBP;
  
  FUN_1000e590((undefined4 *)(unaff_EBP + -0x2044));
  return;
}



// Function: Unwind@10013b70 at 10013b70

void Unwind_10013b70(void)

{
  int unaff_EBP;
  
  FUN_1000e540((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10013b78 at 10013b78

void Unwind_10013b78(void)

{
  int unaff_EBP;
  
  FUN_1000e550((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10013b80 at 10013b80

void Unwind_10013b80(void)

{
  int unaff_EBP;
  
  FUN_1000e530((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013b88 at 10013b88

void Unwind_10013b88(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10013b93 at 10013b93

void Unwind_10013b93(void)

{
  int unaff_EBP;
  
  FUN_1000e590((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10013b9b at 10013b9b

void Unwind_10013b9b(void)

{
  int unaff_EBP;
  
  FUN_1000e540(*(int **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10013ba3 at 10013ba3

void Unwind_10013ba3(void)

{
  int unaff_EBP;
  
  FUN_1000e590((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10013bab at 10013bab

void Unwind_10013bab(void)

{
  int unaff_EBP;
  
  FUN_1000e590(*(undefined4 **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10013bb3 at 10013bb3

void Unwind_10013bb3(void)

{
  int unaff_EBP;
  
  FUN_1000e590(*(undefined4 **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10013bbb at 10013bbb

void Unwind_10013bbb(void)

{
  int unaff_EBP;
  
  FUN_1000e590((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10013be0 at 10013be0

void Unwind_10013be0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10013beb at 10013beb

void Unwind_10013beb(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_1000e590(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10013c20 at 10013c20

void Unwind_10013c20(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10013c2b at 10013c2b

void Unwind_10013c2b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_1000e590(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10013c60 at 10013c60

void Unwind_10013c60(void)

{
  int unaff_EBP;
  
  FUN_1000e590((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10013c90 at 10013c90

void Unwind_10013c90(void)

{
  int unaff_EBP;
  
  FUN_1000e590((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10013cc0 at 10013cc0

void Unwind_10013cc0(void)

{
  int unaff_EBP;
  
  FUN_1000e590((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: FUN_10013d30 at 10013d30

void FUN_10013d30(void)

{
  FUN_10002950((undefined4 *)&DAT_1001b684);
  _atexit(FUN_10013db0);
  return;
}



// Function: FUN_10013d50 at 10013d50

void FUN_10013d50(void)

{
  FUN_10004470((undefined4 *)&DAT_1001b6b0);
  _atexit(FUN_10013dc0);
  return;
}



// Function: FUN_10013db0 at 10013db0

void FUN_10013db0(void)

{
  FID_conflict__bad_alloc((int *)&DAT_1001b684);
  return;
}



// Function: FUN_10013dc0 at 10013dc0

void FUN_10013dc0(void)

{
  FUN_10004e70((undefined4 *)&DAT_1001b6b0);
  return;
}



// Function: FUN_10013dcf at 10013dcf

void FUN_10013dcf(void)

{
  ATL::CAtlBaseModule::~CAtlBaseModule((CAtlBaseModule *)&DAT_1001b6e0);
  return;
}



// Function: FUN_10013dd9 at 10013dd9

void FUN_10013dd9(void)

{
  ATL::CAtlComModule::Term((CAtlComModule *)&DAT_1001b718);
  return;
}



// Function: FUN_10013df0 at 10013df0

void FUN_10013df0(void)

{
  Ordinal_9(&DAT_1001b608);
  return;
}



