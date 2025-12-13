/*
 * Decompiled from: datalink.dll
 * Using Ghidra 11.4.1
 */

// Function: InitDPA at 6f621000

int InitDPA(ushort *param_1,undefined2 param_2)

{
  void *this;
  int local_104;
  undefined1 local_100 [3];
  undefined2 local_fd;
  int local_8;
  
                    /* 0x1000  7  InitDPA */
  local_8 = 0;
  local_fd = param_2;
  local_8 = FUN_6f6230e0(&local_104,s_dg121032_ini_6f639124);
  if (local_8 == 0) {
    if (local_104 == 0) {
      local_8 = InitCommLink(param_1,param_1,local_100);
    }
    else if (local_104 == 1) {
      local_8 = InitPCCard(this,param_1,local_100);
    }
    else if (local_104 == 2) {
      local_8 = 0x28;
    }
    else {
      local_8 = 0x28;
    }
  }
  return local_8;
}



// Function: RestoreDPA at 6f6210a4

int RestoreDPA(ushort param_1)

{
  ushort uVar1;
  undefined4 local_8;
  
                    /* 0x10a4  20  RestoreDPA */
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = RestorePCCard(param_1);
  }
  else if (uVar1 == 0) {
    local_8 = RestoreCommLink(param_1);
  }
  else if (uVar1 == 0x4000) {
    local_8 = 0x21;
  }
  else {
    local_8 = 0x21;
  }
  return local_8;
}



// Function: InitCommLink at 6f62110b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall InitCommLink(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
                    /* 0x110b  6  InitCommLink */
  if ((DAT_6f63cc00 == (HMODULE)0x0) && (DAT_6f63cdfc == 0)) {
    DAT_6f63cc00 = LoadLibraryA(s_DPAS32_DLL_6f639030);
    if (DAT_6f63cc00 < (HMODULE)0x21) {
      return 0x29;
    }
    DAT_6f63cc10 = GetProcAddress(DAT_6f63cc00,s_InitCommLink_6f639134);
    DAT_6f63cc20 = GetProcAddress(DAT_6f63cc00,s_RestoreCommLink_6f639144);
    _DAT_6f63cc30 = 0;
    _DAT_6f63cc40 = 0;
    DAT_6f63cc50 = GetProcAddress(DAT_6f63cc00,s_InitDataLink_6f639154);
    DAT_6f63cc60 = GetProcAddress(DAT_6f63cc00,s_CheckDataLink_6f639164);
    DAT_6f63cc70 = GetProcAddress(DAT_6f63cc00,s_LoadDPABuffer_6f639174);
    DAT_6f63cc80 = GetProcAddress(DAT_6f63cc00,s_ReadDPABuffer_6f639184);
    DAT_6f63cc90 = GetProcAddress(DAT_6f63cc00,s_LoadMailBox_6f639194);
    DAT_6f63cca0 = GetProcAddress(DAT_6f63cc00,s_UnloadMailBox_6f6391a0);
    DAT_6f63ccb0 = GetProcAddress(DAT_6f63cc00,s_TransmitMailBoxAsync_6f6391b0);
    DAT_6f63ccc0 = GetProcAddress(DAT_6f63cc00,s_TransmitMailBox_6f6391c8);
    DAT_6f63ccd0 = GetProcAddress(DAT_6f63cc00,s_UpdateTransmitMailBox_6f6391d8);
    DAT_6f63cce0 = GetProcAddress(DAT_6f63cc00,s_UpdateTransmitMailBoxAsync_6f6391f0);
    DAT_6f63ccf0 = GetProcAddress(DAT_6f63cc00,s_UpdateTransMailBoxData_6f63920c);
    DAT_6f63cd00 = GetProcAddress(DAT_6f63cc00,s_UpdateTransMailBoxDataAsync_6f639224);
    DAT_6f63cd10 = GetProcAddress(DAT_6f63cc00,s_UpdateReceiveMailBox_6f639240);
    DAT_6f63cd20 = GetProcAddress(DAT_6f63cc00,s_UpdateReceiveMailBoxAsync_6f639258);
    DAT_6f63cd30 = GetProcAddress(DAT_6f63cc00,s_ReceiveMailBox_6f639274);
    DAT_6f63cd40 = GetProcAddress(DAT_6f63cc00,s_LoadTimer_6f639284);
    DAT_6f63cd50 = GetProcAddress(DAT_6f63cc00,s_EnableTimerInterrupt_6f639290);
    DAT_6f63cd60 = GetProcAddress(DAT_6f63cc00,s_SuspendTimerInterrupt_6f6392a8);
    DAT_6f63cd70 = GetProcAddress(DAT_6f63cc00,s_PauseTimer_6f6392c0);
    DAT_6f63cd80 = GetProcAddress(DAT_6f63cc00,s_ResumeTimer_6f6392cc);
    DAT_6f63cd90 = GetProcAddress(DAT_6f63cc00,s_RequestTimerValue_6f6392d8);
    DAT_6f63cda0 = GetProcAddress(DAT_6f63cc00,s_CheckLock_6f6392ec);
    DAT_6f63cdb0 = GetProcAddress(DAT_6f63cc00,s_GoToLoader_6f6392f8);
    DAT_6f63cdc0 = GetProcAddress(DAT_6f63cc00,s_ReadDPAChecksum_6f639304);
    DAT_6f63cdd0 = GetProcAddress(DAT_6f63cc00,s_ConfigureTransportProtocol_6f639314);
    DAT_6f63cde0 = GetProcAddress(DAT_6f63cc00,s_SetBaudRate_6f639330);
    DAT_6f63cdf0 = GetProcAddress(DAT_6f63cc00,s_ResetDPA_6f63933c);
    if (((((((DAT_6f63cc10 == (FARPROC)0x0) || (DAT_6f63cc20 == (FARPROC)0x0)) ||
           (DAT_6f63cc50 == (FARPROC)0x0)) ||
          ((DAT_6f63cc60 == (FARPROC)0x0 || (DAT_6f63cc70 == (FARPROC)0x0)))) ||
         (DAT_6f63cc80 == (FARPROC)0x0)) ||
        (((((DAT_6f63cc90 == (FARPROC)0x0 || (DAT_6f63cca0 == (FARPROC)0x0)) ||
           ((DAT_6f63ccb0 == (FARPROC)0x0 ||
            (((DAT_6f63ccc0 == (FARPROC)0x0 || (DAT_6f63ccd0 == (FARPROC)0x0)) ||
             (DAT_6f63cce0 == (FARPROC)0x0)))))) ||
          ((DAT_6f63ccf0 == (FARPROC)0x0 || (DAT_6f63cd00 == (FARPROC)0x0)))) ||
         (DAT_6f63cd10 == (FARPROC)0x0)))) ||
       ((((DAT_6f63cd20 == (FARPROC)0x0 || (DAT_6f63cd30 == (FARPROC)0x0)) ||
         ((DAT_6f63cd40 == (FARPROC)0x0 ||
          (((DAT_6f63cd50 == (FARPROC)0x0 || (DAT_6f63cd60 == (FARPROC)0x0)) ||
           (DAT_6f63cd70 == (FARPROC)0x0)))))) ||
        (((DAT_6f63cd80 == (FARPROC)0x0 || (DAT_6f63cd90 == (FARPROC)0x0)) ||
         ((DAT_6f63cda0 == (FARPROC)0x0 ||
          (((DAT_6f63cdb0 == (FARPROC)0x0 || (DAT_6f63cdc0 == (FARPROC)0x0)) ||
           ((DAT_6f63cde0 == (FARPROC)0x0 ||
            ((DAT_6f63cdf0 == (FARPROC)0x0 || (DAT_6f63cdd0 == (FARPROC)0x0)))))))))))))) {
      FreeLibrary(DAT_6f63cc00);
      return 0x29;
    }
  }
  if (DAT_6f63cc10 == (FARPROC)0x0) {
    iVar1 = 0x29;
  }
  else {
    iVar1 = (*DAT_6f63cc10)(param_1,param_2,this);
    if (iVar1 == 0) {
      DAT_6f63cdfc = DAT_6f63cdfc + 1;
    }
  }
  return iVar1;
}



// Function: InitPCCard at 6f621589

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall InitPCCard(void *this,ushort *param_1,undefined4 param_2)

{
  int iVar1;
  
                    /* 0x1589  9  InitPCCard */
  if ((DAT_6f63cc04 == (HMODULE)0x0) && (DAT_6f63ce00 == 0)) {
    DAT_6f63cc04 = LoadLibraryA(s_DPAI32_DLL_6f639080);
    if (DAT_6f63cc04 < (HMODULE)0x21) {
      return 0x29;
    }
    DAT_6f63cc34 = GetProcAddress(DAT_6f63cc04,s_InitPCCard_6f639348);
    DAT_6f63cc44 = GetProcAddress(DAT_6f63cc04,s_RestorePCCard_6f639354);
    _DAT_6f63cc14 = 0;
    _DAT_6f63cc24 = 0;
    DAT_6f63cc54 = GetProcAddress(DAT_6f63cc04,s_InitDataLink_6f639364);
    DAT_6f63cc64 = GetProcAddress(DAT_6f63cc04,s_CheckDataLink_6f639374);
    DAT_6f63cc74 = GetProcAddress(DAT_6f63cc04,s_LoadDPABuffer_6f639384);
    DAT_6f63cc84 = GetProcAddress(DAT_6f63cc04,s_ReadDPABuffer_6f639394);
    DAT_6f63cc94 = GetProcAddress(DAT_6f63cc04,s_LoadMailBox_6f6393a4);
    DAT_6f63cca4 = GetProcAddress(DAT_6f63cc04,s_UnloadMailBox_6f6393b0);
    DAT_6f63ccb4 = GetProcAddress(DAT_6f63cc04,s_TransmitMailBoxAsync_6f6393c0);
    DAT_6f63ccc4 = GetProcAddress(DAT_6f63cc04,s_TransmitMailBox_6f6393d8);
    DAT_6f63ccd4 = GetProcAddress(DAT_6f63cc04,s_UpdateTransmitMailBox_6f6393e8);
    DAT_6f63cce4 = GetProcAddress(DAT_6f63cc04,s_UpdateTransmitMailBoxAsync_6f639400);
    DAT_6f63ccf4 = GetProcAddress(DAT_6f63cc04,s_UpdateTransMailBoxData_6f63941c);
    DAT_6f63cd04 = GetProcAddress(DAT_6f63cc04,s_UpdateTransMailBoxDataAsync_6f639434);
    DAT_6f63cd14 = GetProcAddress(DAT_6f63cc04,s_UpdateReceiveMailBox_6f639450);
    DAT_6f63cd24 = GetProcAddress(DAT_6f63cc04,s_UpdateReceiveMailBoxAsync_6f639468);
    DAT_6f63cd34 = GetProcAddress(DAT_6f63cc04,s_ReceiveMailBox_6f639484);
    DAT_6f63cd44 = GetProcAddress(DAT_6f63cc04,s_LoadTimer_6f639494);
    DAT_6f63cd54 = GetProcAddress(DAT_6f63cc04,s_EnableTimerInterrupt_6f6394a0);
    DAT_6f63cd64 = GetProcAddress(DAT_6f63cc04,s_SuspendTimerInterrupt_6f6394b8);
    DAT_6f63cd74 = GetProcAddress(DAT_6f63cc04,s_PauseTimer_6f6394d0);
    DAT_6f63cd84 = GetProcAddress(DAT_6f63cc04,s_ResumeTimer_6f6394dc);
    DAT_6f63cd94 = GetProcAddress(DAT_6f63cc04,s_RequestTimerValue_6f6394e8);
    DAT_6f63cda4 = GetProcAddress(DAT_6f63cc04,s_CheckLock_6f6394fc);
    DAT_6f63cdb4 = GetProcAddress(DAT_6f63cc04,s_GoToLoader_6f639508);
    DAT_6f63cdc4 = GetProcAddress(DAT_6f63cc04,s_ReadDPAChecksum_6f639514);
    DAT_6f63cdd4 = GetProcAddress(DAT_6f63cc04,s_ConfigureTransportProtocol_6f639524);
    _DAT_6f63cde4 = 0;
    DAT_6f63cdf4 = GetProcAddress(DAT_6f63cc04,s_ResetDPA_6f639540);
    if (((((((DAT_6f63cc34 == (FARPROC)0x0) || (DAT_6f63cc44 == (FARPROC)0x0)) ||
           (DAT_6f63cc54 == (FARPROC)0x0)) ||
          ((DAT_6f63cc64 == (FARPROC)0x0 || (DAT_6f63cc74 == (FARPROC)0x0)))) ||
         (DAT_6f63cc84 == (FARPROC)0x0)) ||
        (((((DAT_6f63cc94 == (FARPROC)0x0 || (DAT_6f63cca4 == (FARPROC)0x0)) ||
           ((DAT_6f63ccb4 == (FARPROC)0x0 ||
            (((DAT_6f63ccc4 == (FARPROC)0x0 || (DAT_6f63ccd4 == (FARPROC)0x0)) ||
             (DAT_6f63cce4 == (FARPROC)0x0)))))) ||
          ((DAT_6f63ccf4 == (FARPROC)0x0 || (DAT_6f63cd04 == (FARPROC)0x0)))) ||
         (DAT_6f63cd14 == (FARPROC)0x0)))) ||
       ((((DAT_6f63cd24 == (FARPROC)0x0 || (DAT_6f63cd34 == (FARPROC)0x0)) ||
         ((DAT_6f63cd44 == (FARPROC)0x0 ||
          (((DAT_6f63cd54 == (FARPROC)0x0 || (DAT_6f63cd64 == (FARPROC)0x0)) ||
           (DAT_6f63cd74 == (FARPROC)0x0)))))) ||
        (((DAT_6f63cd84 == (FARPROC)0x0 || (DAT_6f63cd94 == (FARPROC)0x0)) ||
         ((DAT_6f63cda4 == (FARPROC)0x0 ||
          (((DAT_6f63cdb4 == (FARPROC)0x0 || (DAT_6f63cdc4 == (FARPROC)0x0)) ||
           ((DAT_6f63cdf4 == (FARPROC)0x0 || (DAT_6f63cdd4 == (FARPROC)0x0)))))))))))) {
      FreeLibrary(DAT_6f63cc04);
      return 0x29;
    }
  }
  if (DAT_6f63cc34 == (FARPROC)0x0) {
    iVar1 = 0x29;
  }
  else {
    iVar1 = (*DAT_6f63cc34)(param_1,param_2,this);
    if (iVar1 == 0) {
      *param_1 = *param_1 | 0x8000;
      DAT_6f63ce00 = DAT_6f63ce00 + 1;
    }
  }
  return iVar1;
}



// Function: RestorePCCard at 6f621a00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int RestorePCCard(ushort param_1)

{
  int iVar1;
  
                    /* 0x1a00  21  RestorePCCard */
  if ((param_1 & DAT_6f639120) == 0x8000) {
    DAT_6f63ce00 = DAT_6f63ce00 + -1;
    if (DAT_6f63ce00 < 0) {
      DAT_6f63ce00 = 0;
    }
    if (DAT_6f63cc44 == (code *)0x0) {
      iVar1 = 0x29;
    }
    else {
      iVar1 = (*DAT_6f63cc44)(CONCAT22((short)DAT_6f639120 >> 0xf,param_1) & 0xffff3fff,
                              param_1 & 0x3fff,0);
      if ((iVar1 == 0) && (DAT_6f63ce00 == 0)) {
        FreeLibrary(DAT_6f63cc04);
        DAT_6f63cc04 = (HMODULE)0x0;
        _DAT_6f63cc14 = 0;
        _DAT_6f63cc24 = 0;
        DAT_6f63cc34 = 0;
        DAT_6f63cc44 = (code *)0x0;
        DAT_6f63cc54 = 0;
        DAT_6f63cc64 = 0;
        DAT_6f63cc74 = 0;
        DAT_6f63cc84 = 0;
        DAT_6f63cc94 = 0;
        DAT_6f63cca4 = 0;
        DAT_6f63ccb4 = 0;
        DAT_6f63ccc4 = 0;
        DAT_6f63ccd4 = 0;
        DAT_6f63cce4 = 0;
        DAT_6f63ccf4 = 0;
        DAT_6f63cd04 = 0;
        DAT_6f63cd14 = 0;
        DAT_6f63cd24 = 0;
        DAT_6f63cd34 = 0;
        DAT_6f63cd44 = 0;
        DAT_6f63cd54 = 0;
        DAT_6f63cd64 = 0;
        DAT_6f63cd74 = 0;
        DAT_6f63cd84 = 0;
        DAT_6f63cd94 = 0;
        DAT_6f63cda4 = 0;
        DAT_6f63cdb4 = 0;
        DAT_6f63cdc4 = 0;
        DAT_6f63cdd4 = 0;
      }
    }
  }
  else {
    iVar1 = 0x20;
  }
  return iVar1;
}



// Function: RestoreCommLink at 6f621be2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int RestoreCommLink(ushort param_1)

{
  int iVar1;
  
                    /* 0x1be2  19  RestoreCommLink */
  if ((param_1 & DAT_6f639120) == 0) {
    DAT_6f63cdfc = DAT_6f63cdfc + -1;
    if (DAT_6f63cdfc < 0) {
      DAT_6f63cdfc = 0;
    }
    if (DAT_6f63cc20 == (code *)0x0) {
      iVar1 = 0x29;
    }
    else {
      iVar1 = (*DAT_6f63cc20)(CONCAT22((short)DAT_6f639120 >> 0xf,param_1) & 0xffff3fff,0);
      if ((iVar1 == 0) && (DAT_6f63cdfc == 0)) {
        FreeLibrary(DAT_6f63cc00);
        DAT_6f63cc00 = (HMODULE)0x0;
        DAT_6f63cc10 = 0;
        DAT_6f63cc20 = (code *)0x0;
        _DAT_6f63cc30 = 0;
        _DAT_6f63cc40 = 0;
        DAT_6f63cc50 = 0;
        DAT_6f63cc60 = 0;
        DAT_6f63cc70 = 0;
        DAT_6f63cc80 = 0;
        DAT_6f63cc90 = 0;
        DAT_6f63cca0 = 0;
        DAT_6f63ccb0 = 0;
        DAT_6f63ccc0 = 0;
        DAT_6f63ccd0 = 0;
        DAT_6f63cce0 = 0;
        DAT_6f63ccf0 = 0;
        DAT_6f63cd00 = 0;
        DAT_6f63cd10 = 0;
        DAT_6f63cd20 = 0;
        DAT_6f63cd30 = 0;
        DAT_6f63cd40 = 0;
        DAT_6f63cd50 = 0;
        DAT_6f63cd60 = 0;
        DAT_6f63cd70 = 0;
        DAT_6f63cd80 = 0;
        DAT_6f63cd90 = 0;
        DAT_6f63cda0 = 0;
        DAT_6f63cdb0 = 0;
        DAT_6f63cdc0 = 0;
        DAT_6f63cdd0 = 0;
      }
    }
  }
  else {
    iVar1 = 0x20;
  }
  return iVar1;
}



// Function: CheckDataLink at 6f621dc0

int CheckDataLink(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x1dc0  1  CheckDataLink */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63cc60)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63cc60)[local_8])
                           (CONCAT22((short)DAT_6f639120 >> 0xf,param_1) & 0xffff3fff,param_2);
    }
  }
  return local_10;
}



// Function: LoadDPABuffer at 6f621e71

int LoadDPABuffer(ushort param_1,undefined4 param_2,undefined2 param_3,undefined2 param_4)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x1e71  10  LoadDPABuffer */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63cc70)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63cc70)[local_8])
                           (CONCAT22((short)uVar1 >> 0xf,param_1) & 0xffff3fff,param_2,
                            CONCAT22((short)DAT_6f639120 >> 0xf,param_3),
                            CONCAT22((short)uVar1 >> 0xf,param_4));
    }
  }
  return local_10;
}



// Function: ReadDPABuffer at 6f621f2c

int ReadDPABuffer(ushort param_1,undefined4 param_2,undefined2 param_3,undefined2 param_4)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x1f2c  14  ReadDPABuffer */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63cc80)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63cc80)[local_8])
                           (CONCAT22((short)uVar1 >> 0xf,param_1) & 0xffff3fff,param_2,
                            CONCAT22((short)DAT_6f639120 >> 0xf,param_3),
                            CONCAT22((short)uVar1 >> 0xf,param_4));
    }
  }
  return local_10;
}



// Function: CheckLock at 6f621fe7

int CheckLock(ushort param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x1fe7  2  CheckLock */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63cda0)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63cda0)[local_8])(param_1 & 0x3fff,param_2,param_3);
    }
  }
  return local_10;
}



// Function: GoToLoader at 6f62209c

int GoToLoader(ushort param_1)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x209c  5  GoToLoader */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63cdb0)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63cdb0)[local_8])
                           (CONCAT22((short)uVar1 >> 0xf,param_1) & 0xffff3fff);
    }
  }
  return local_10;
}



// Function: InitDataLink at 6f622149

int InitDataLink(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x2149  8  InitDataLink */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63cc50)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63cc50)[local_8])
                           (CONCAT22((short)DAT_6f639120 >> 0xf,param_1) & 0xffff3fff,param_2);
    }
  }
  return local_10;
}



// Function: LoadMailBox at 6f6221fa

int LoadMailBox(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x21fa  11  LoadMailBox */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63cc90)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63cc90)[local_8])
                           (CONCAT22((short)DAT_6f639120 >> 0xf,param_1) & 0xffff3fff,param_2);
    }
  }
  return local_10;
}



// Function: TransmitMailBoxAsync at 6f6222ab

int TransmitMailBoxAsync(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x22ab  29  TransmitMailBoxAsync */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63ccb0)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63ccb0)[local_8])
                           (CONCAT22((short)DAT_6f639120 >> 0xf,param_1) & 0xffff3fff,param_2);
    }
  }
  return local_10;
}



// Function: TransmitMailBox at 6f62235c

int TransmitMailBox(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x235c  28  TransmitMailBox */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63ccc0)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63ccc0)[local_8])
                           (CONCAT22((short)DAT_6f639120 >> 0xf,param_1) & 0xffff3fff,param_2);
    }
  }
  return local_10;
}



// Function: UpdateTransMailBoxDataAsync at 6f62240d

int UpdateTransMailBoxDataAsync(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x240d  34  UpdateTransMailBoxDataAsync */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63cd00)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63cd00)[local_8])
                           (CONCAT22((short)DAT_6f639120 >> 0xf,param_1) & 0xffff3fff,param_2);
    }
  }
  return local_10;
}



// Function: UpdateTransMailBoxData at 6f6224be

int UpdateTransMailBoxData(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x24be  33  UpdateTransMailBoxData */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63ccf0)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63ccf0)[local_8])
                           (CONCAT22((short)DAT_6f639120 >> 0xf,param_1) & 0xffff3fff,param_2);
    }
  }
  return local_10;
}



// Function: UpdateTransmitMailBoxAsync at 6f62256f

int UpdateTransmitMailBoxAsync(ushort param_1,undefined4 param_2,undefined1 param_3)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x256f  36  UpdateTransmitMailBoxAsync */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63cce0)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63cce0)[local_8])
                           (param_1 & 0x3fff,param_2,CONCAT31((int3)(char)(uVar1 >> 8),param_3));
    }
  }
  return local_10;
}



// Function: UpdateTransmitMailBox at 6f622624

int UpdateTransmitMailBox(ushort param_1,undefined4 param_2,undefined1 param_3)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x2624  35  UpdateTransmitMailBox */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63ccd0)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63ccd0)[local_8])
                           (param_1 & 0x3fff,param_2,CONCAT31((int3)(char)(uVar1 >> 8),param_3));
    }
  }
  return local_10;
}



// Function: UpdateReceiveMailBoxAsync at 6f6226d9

int UpdateReceiveMailBoxAsync(ushort param_1,undefined4 param_2,undefined1 param_3)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x26d9  32  UpdateReceiveMailBoxAsync */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63cd20)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63cd20)[local_8])
                           (param_1 & 0x3fff,param_2,CONCAT31((int3)(char)(uVar1 >> 8),param_3));
    }
  }
  return local_10;
}



// Function: UpdateReceiveMailBox at 6f62278e

int UpdateReceiveMailBox(ushort param_1,undefined4 param_2,undefined1 param_3)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x278e  31  UpdateReceiveMailBox */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63cd10)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63cd10)[local_8])
                           (param_1 & 0x3fff,param_2,CONCAT31((int3)(char)(uVar1 >> 8),param_3));
    }
  }
  return local_10;
}



// Function: ReceiveMailBox at 6f622843

int ReceiveMailBox(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x2843  16  ReceiveMailBox */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63cd30)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63cd30)[local_8])
                           (CONCAT22((short)DAT_6f639120 >> 0xf,param_1) & 0xffff3fff,param_2);
    }
  }
  return local_10;
}



// Function: UnloadMailBox at 6f6228f4

int UnloadMailBox(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x28f4  30  UnloadMailBox */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63cca0)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63cca0)[local_8])
                           (CONCAT22((short)DAT_6f639120 >> 0xf,param_1) & 0xffff3fff,param_2);
    }
  }
  return local_10;
}



// Function: LoadTimer at 6f6229a5

int LoadTimer(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x29a5  12  LoadTimer */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63cd40)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63cd40)[local_8])
                           (CONCAT22((short)DAT_6f639120 >> 0xf,param_1) & 0xffff3fff,param_2);
    }
  }
  return local_10;
}



// Function: EnableTimerInterrupt at 6f622a56

int EnableTimerInterrupt(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x2a56  4  EnableTimerInterrupt */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63cd50)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63cd50)[local_8])
                           (CONCAT22((short)DAT_6f639120 >> 0xf,param_1) & 0xffff3fff,param_2);
    }
  }
  return local_10;
}



// Function: SuspendTimerInterrupt at 6f622b07

int SuspendTimerInterrupt(ushort param_1)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x2b07  27  SuspendTimerInterrupt */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63cd60)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63cd60)[local_8])
                           (CONCAT22((short)uVar1 >> 0xf,param_1) & 0xffff3fff);
    }
  }
  return local_10;
}



// Function: PauseTimer at 6f622bb4

int PauseTimer(ushort param_1)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x2bb4  13  PauseTimer */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63cd70)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63cd70)[local_8])
                           (CONCAT22((short)uVar1 >> 0xf,param_1) & 0xffff3fff);
    }
  }
  return local_10;
}



// Function: ResumeTimer at 6f622c61

int ResumeTimer(ushort param_1)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x2c61  22  ResumeTimer */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63cd80)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63cd80)[local_8])
                           (CONCAT22((short)uVar1 >> 0xf,param_1) & 0xffff3fff);
    }
  }
  return local_10;
}



// Function: RequestTimerValue at 6f622d0e

int RequestTimerValue(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x2d0e  17  RequestTimerValue */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63cd90)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63cd90)[local_8])
                           (CONCAT22((short)DAT_6f639120 >> 0xf,param_1) & 0xffff3fff,param_2);
    }
  }
  return local_10;
}



// Function: ReadDPAChecksum at 6f622dbf

int ReadDPAChecksum(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x2dbf  15  ReadDPAChecksum */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63cdc0)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63cdc0)[local_8])
                           (CONCAT22((short)DAT_6f639120 >> 0xf,param_1) & 0xffff3fff,param_2);
    }
  }
  return local_10;
}



// Function: ConfigureTransportProtocol at 6f622e70

int ConfigureTransportProtocol(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x2e70  3  ConfigureTransportProtocol */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63cdd0)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63cdd0)[local_8])
                           (CONCAT22((short)DAT_6f639120 >> 0xf,param_1) & 0xffff3fff,param_2);
    }
  }
  return local_10;
}



// Function: SetBaudRate at 6f622f21

int SetBaudRate(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x2f21  23  SetBaudRate */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
    local_10 = 0x21;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63cde0)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63cde0)[local_8])
                           (CONCAT22((short)DAT_6f639120 >> 0xf,param_1) & 0xffff3fff,param_2);
    }
  }
  return local_10;
}



// Function: ResetDPA at 6f622fd9

int ResetDPA(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x2fd9  18  ResetDPA */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f639120;
  if (uVar1 == 0x8000) {
    local_8 = 1;
  }
  else if (uVar1 == 0) {
    local_8 = 0;
  }
  else if (uVar1 == 0x4000) {
    local_8 = 2;
    local_10 = 0x21;
  }
  else {
    local_10 = 0x21;
  }
  if (local_10 == 0) {
    if ((&DAT_6f63cdf0)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f63cdf0)[local_8])
                           (CONCAT22((short)DAT_6f639120 >> 0xf,param_1) & 0xffff3fff,param_2);
    }
  }
  return local_10;
}



// Function: _SetSerialDLL@4 at 6f62308a

undefined4 _SetSerialDLL_4(uint *param_1)

{
                    /* 0x308a  25  _SetSerialDLL@4 */
  FUN_6f6235b0((uint *)s_DPAS32_DLL_6f639030,param_1);
  return 0;
}



// Function: _SetIsaDLL@4 at 6f6230a4

undefined4 _SetIsaDLL_4(uint *param_1)

{
                    /* 0x30a4  24  _SetIsaDLL@4 */
  FUN_6f6235b0((uint *)s_DPAI32_DLL_6f639080,param_1);
  return 0;
}



// Function: _SetUsbDLL@4 at 6f6230be

undefined4 _SetUsbDLL_4(uint *param_1)

{
                    /* 0x30be  26  _SetUsbDLL@4 */
  FUN_6f6235b0((uint *)s_DPAU32_DLL_6f6390d0,param_1);
  return 0;
}



// Function: FUN_6f6230e0 at 6f6230e0

undefined4 __cdecl FUN_6f6230e0(undefined4 *param_1,LPCSTR param_2)

{
  int iVar1;
  char *pcVar2;
  char *local_64;
  CHAR local_58 [80];
  undefined2 local_8;
  
  local_8 = 0;
  FUN_6f623870(local_58,(byte *)s_DeviceInformation_d_6f63954c);
  GetPrivateProfileStringA
            (local_58,s_DeviceName_6f63956c,s_INVALID_6f639564,(LPSTR)((int)param_1 + 9),0x50,
             param_2);
  GetPrivateProfileStringA
            (local_58,s_DeviceDescription_6f639580,s_INVALID_6f639578,(LPSTR)((int)param_1 + 0x59),
             0x50,param_2);
  GetPrivateProfileStringA
            (local_58,s_DeviceParams_6f63959c,s_INVALID_6f639594,(LPSTR)((int)param_1 + 0xa9),0x50,
             param_2);
  iVar1 = _strcmp((char *)((int)param_1 + 0xa9),s_INVALID_6f6395ac);
  if (((iVar1 == 0) || (iVar1 = _strcmp((char *)((int)param_1 + 9),s_INVALID_6f6395b4), iVar1 == 0))
     || (iVar1 = _strcmp((char *)((int)param_1 + 0x59),s_INVALID_6f6395bc), iVar1 == 0)) {
    return 0x28;
  }
  pcVar2 = _strstr((char *)((int)param_1 + 0x59),&DAT_6f6395c4);
  if ((pcVar2 == (char *)0x0) &&
     (pcVar2 = _strstr((char *)((int)param_1 + 0xa9),&DAT_6f6395c8), pcVar2 == (char *)0x0)) {
    pcVar2 = _strstr((char *)((int)param_1 + 0x59),&DAT_6f639660);
    if (((pcVar2 != (char *)0x0) ||
        (pcVar2 = _strstr((char *)((int)param_1 + 0xa9),&DAT_6f639664), pcVar2 != (char *)0x0)) ||
       ((pcVar2 = _strstr((char *)((int)param_1 + 0x59),s_PC_CARD_6f639668), pcVar2 != (char *)0x0
        || (pcVar2 = _strstr((char *)((int)param_1 + 0xa9),s_PC_CARD_6f639670),
           pcVar2 != (char *)0x0)))) {
      pcVar2 = _strstr((char *)((int)param_1 + 0xa9),&DAT_6f639678);
      if (pcVar2 == (char *)0x0) {
        return 0x28;
      }
      iVar1 = FUN_6f6236a0(pcVar2 + 2,(byte *)s__hx__c_hd_6f63967c);
      if (iVar1 == 0) {
        return 0x28;
      }
      *param_1 = 1;
      *(undefined2 *)(param_1 + 1) = 0;
      *(undefined1 *)((int)param_1 + 6) = (undefined1)local_8;
    }
  }
  else {
    pcVar2 = _strstr((char *)((int)param_1 + 0x59),&DAT_6f6395cc);
    if (pcVar2 == (char *)0x0) {
      local_64 = (char *)((int)param_1 + 0xa9);
    }
    else {
      local_64 = (char *)((int)param_1 + 0x59);
    }
    pcVar2 = _strstr(local_64,&DAT_6f6395d0);
    if (pcVar2 == (char *)0x0) {
      pcVar2 = _strstr(local_64,&DAT_6f6395d8);
      if (pcVar2 == (char *)0x0) {
        pcVar2 = _strstr(local_64,&DAT_6f6395e0);
        if (pcVar2 == (char *)0x0) {
          pcVar2 = _strstr(local_64,&DAT_6f6395e8);
          if (pcVar2 == (char *)0x0) {
            pcVar2 = _strstr(local_64,&DAT_6f6395f0);
            if (pcVar2 == (char *)0x0) {
              pcVar2 = _strstr(local_64,&DAT_6f6395f8);
              if (pcVar2 == (char *)0x0) {
                pcVar2 = _strstr(local_64,&DAT_6f639600);
                if (pcVar2 == (char *)0x0) {
                  pcVar2 = _strstr(local_64,&DAT_6f639608);
                  if (pcVar2 == (char *)0x0) {
                    pcVar2 = _strstr(local_64,&DAT_6f639610);
                    if (pcVar2 == (char *)0x0) {
                      return 0xf;
                    }
                    *(undefined1 *)(param_1 + 1) = 8;
                  }
                  else {
                    *(undefined1 *)(param_1 + 1) = 7;
                  }
                }
                else {
                  *(undefined1 *)(param_1 + 1) = 6;
                }
              }
              else {
                *(undefined1 *)(param_1 + 1) = 5;
              }
            }
            else {
              *(undefined1 *)(param_1 + 1) = 4;
            }
          }
          else {
            *(undefined1 *)(param_1 + 1) = 3;
          }
        }
        else {
          *(undefined1 *)(param_1 + 1) = 2;
        }
      }
      else {
        *(undefined1 *)(param_1 + 1) = 1;
      }
    }
    else {
      *(undefined1 *)(param_1 + 1) = 0;
    }
    *param_1 = 0;
    pcVar2 = _strstr((char *)((int)param_1 + 0xa9),s_B9600_6f639618);
    if (pcVar2 == (char *)0x0) {
      pcVar2 = _strstr((char *)((int)param_1 + 0xa9),s_B19200_6f639620);
      if (pcVar2 == (char *)0x0) {
        pcVar2 = _strstr((char *)((int)param_1 + 0xa9),s_B28800_6f639628);
        if (pcVar2 == (char *)0x0) {
          pcVar2 = _strstr((char *)((int)param_1 + 0xa9),s_B38400_6f639630);
          if (pcVar2 == (char *)0x0) {
            pcVar2 = _strstr((char *)((int)param_1 + 0xa9),s_B57600_6f639638);
            if (pcVar2 == (char *)0x0) {
              pcVar2 = _strstr((char *)((int)param_1 + 0xa9),s_B115200_6f639640);
              if (pcVar2 == (char *)0x0) {
                pcVar2 = _strstr((char *)((int)param_1 + 0xa9),s_B230400_6f639648);
                if (pcVar2 == (char *)0x0) {
                  pcVar2 = _strstr((char *)((int)param_1 + 0xa9),s_B460800_6f639650);
                  if (pcVar2 == (char *)0x0) {
                    *(undefined1 *)((int)param_1 + 5) = 5;
                  }
                  else {
                    *(undefined1 *)((int)param_1 + 5) = 7;
                  }
                }
                else {
                  *(undefined1 *)((int)param_1 + 5) = 6;
                }
              }
              else {
                *(undefined1 *)((int)param_1 + 5) = 5;
              }
            }
            else {
              *(undefined1 *)((int)param_1 + 5) = 4;
            }
          }
          else {
            *(undefined1 *)((int)param_1 + 5) = 3;
          }
        }
        else {
          *(undefined1 *)((int)param_1 + 5) = 2;
        }
      }
      else {
        *(undefined1 *)((int)param_1 + 5) = 1;
      }
    }
    else {
      *(undefined1 *)((int)param_1 + 5) = 0;
    }
    pcVar2 = _strstr((char *)((int)param_1 + 0xa9),&DAT_6f639658);
    if (pcVar2 == (char *)0x0) {
      *(undefined1 *)((int)param_1 + 6) = 0;
    }
    else {
      *(undefined1 *)((int)param_1 + 6) = 1;
    }
  }
  return 0;
}



// Function: FUN_6f6235b0 at 6f6235b0

uint * __cdecl FUN_6f6235b0(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  uVar3 = (uint)param_2 & 3;
  puVar4 = param_1;
  while (uVar3 != 0) {
    bVar1 = (byte)*param_2;
    uVar3 = (uint)bVar1;
    param_2 = (uint *)((int)param_2 + 1);
    if (bVar1 == 0) goto LAB_6f623698;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
    uVar3 = (uint)param_2 & 3;
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_6f623698:
        *(byte *)puVar4 = (byte)uVar3;
        return param_1;
      }
      if ((char)(uVar3 >> 8) == '\0') {
        *(short *)puVar4 = (short)uVar3;
        return param_1;
      }
      if ((uVar3 & 0xff0000) == 0) {
        *(short *)puVar4 = (short)uVar3;
        *(byte *)((int)puVar4 + 2) = 0;
        return param_1;
      }
      if ((uVar3 & 0xff000000) == 0) {
        *puVar4 = uVar3;
        return param_1;
      }
    }
    *puVar4 = uVar3;
    puVar4 = puVar4 + 1;
  } while( true );
}



// Function: FUN_6f6235c0 at 6f6235c0

uint * __cdecl FUN_6f6235c0(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar4 = (uint)param_1 & 3;
  puVar3 = param_1;
  while (uVar4 != 0) {
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
    if ((byte)uVar4 == 0) goto LAB_6f62360f;
    uVar4 = (uint)puVar3 & 3;
  }
  do {
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto LAB_6f623621;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto LAB_6f623621;
    }
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto LAB_6f623621;
    }
  } while ((uVar4 & 0xff000000) != 0);
LAB_6f62360f:
  puVar5 = (uint *)((int)puVar3 + -1);
LAB_6f623621:
  uVar4 = (uint)param_2 & 3;
  while (uVar4 != 0) {
    bVar1 = (byte)*param_2;
    uVar4 = (uint)bVar1;
    param_2 = (uint *)((int)param_2 + 1);
    if (bVar1 == 0) goto LAB_6f623698;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
    uVar4 = (uint)param_2 & 3;
  }
  do {
    uVar2 = *param_2;
    uVar4 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar4 == '\0') {
LAB_6f623698:
        *(byte *)puVar5 = (byte)uVar4;
        return param_1;
      }
      if ((char)(uVar4 >> 8) == '\0') {
        *(short *)puVar5 = (short)uVar4;
        return param_1;
      }
      if ((uVar4 & 0xff0000) == 0) {
        *(short *)puVar5 = (short)uVar4;
        *(byte *)((int)puVar5 + 2) = 0;
        return param_1;
      }
      if ((uVar4 & 0xff000000) == 0) {
        *puVar5 = uVar4;
        return param_1;
      }
    }
    *puVar5 = uVar4;
    puVar5 = puVar5 + 1;
  } while( true );
}



// Function: FUN_6f6236a0 at 6f6236a0

int __cdecl FUN_6f6236a0(char *param_1,byte *param_2)

{
  code *pcVar1;
  int iVar2;
  char *local_24;
  size_t local_20;
  char *local_1c;
  undefined4 local_18;
  
  if ((param_1 == (char *)0x0) &&
     (iVar2 = FUN_6f625320(2,0x6f637068,0x42,0,(byte *)"string != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  if ((param_2 == (byte *)0x0) &&
     (iVar2 = FUN_6f625320(2,0x6f637068,0x43,0,(byte *)"format != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  local_18 = 0x49;
  local_1c = param_1;
  local_24 = param_1;
  local_20 = _strlen(param_1);
  iVar2 = FUN_6f623c80((int *)&local_24,param_2,(undefined4 *)&stack0x0000000c);
  return iVar2;
}



// Function: _strstr at 6f623760

/* Library Function - Single Match
    _strstr
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strstr(char *_Str,char *_SubStr)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  uint *puVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (*_SubStr == '\0') {
    return _Str;
  }
  if (_SubStr[1] == '\0') {
    puVar4 = FUN_6f6259d6((uint *)_Str);
    return (char *)puVar4;
  }
  do {
    cVar3 = *_Str;
    do {
      while (_Str = _Str + 1, cVar3 != *_SubStr) {
        if (cVar3 == '\0') {
          return (char *)0x0;
        }
        cVar3 = *_Str;
      }
      cVar3 = *_Str;
      pcVar6 = _Str + 1;
      pcVar5 = _SubStr;
    } while (cVar3 != _SubStr[1]);
    do {
      if (pcVar5[2] == '\0') {
LAB_6f6237d3:
        return _Str + -1;
      }
      if (*pcVar6 != pcVar5[2]) break;
      pcVar1 = pcVar5 + 3;
      if (*pcVar1 == '\0') goto LAB_6f6237d3;
      pcVar2 = pcVar6 + 1;
      pcVar5 = pcVar5 + 2;
      pcVar6 = pcVar6 + 2;
    } while (*pcVar1 == *pcVar2);
  } while( true );
}



// Function: _strcmp at 6f6237e0

/* Library Function - Single Match
    _strcmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _strcmp(char *_Str1,char *_Str2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  
  if (((uint)_Str1 & 3) != 0) {
    if (((uint)_Str1 & 1) != 0) {
      bVar4 = *_Str1;
      _Str1 = _Str1 + 1;
      bVar5 = bVar4 < (byte)*_Str2;
      if (bVar4 != *_Str2) goto LAB_6f623824;
      _Str2 = _Str2 + 1;
      if (bVar4 == 0) {
        return 0;
      }
      if (((uint)_Str1 & 2) == 0) goto LAB_6f6237f0;
    }
    uVar1 = *(undefined2 *)_Str1;
    _Str1 = _Str1 + 2;
    bVar4 = (byte)uVar1;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) goto LAB_6f623824;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((ushort)uVar1 >> 8);
    bVar5 = bVar4 < ((byte *)_Str2)[1];
    if (bVar4 != ((byte *)_Str2)[1]) goto LAB_6f623824;
    if (bVar4 == 0) {
      return 0;
    }
    _Str2 = (char *)((byte *)_Str2 + 2);
  }
LAB_6f6237f0:
  while( true ) {
    uVar2 = *(undefined4 *)_Str1;
    bVar4 = (byte)uVar2;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((uint)uVar2 >> 8);
    bVar5 = bVar4 < ((byte *)_Str2)[1];
    if (bVar4 != ((byte *)_Str2)[1]) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((uint)uVar2 >> 0x10);
    bVar5 = bVar4 < ((byte *)_Str2)[2];
    if (bVar4 != ((byte *)_Str2)[2]) break;
    bVar3 = (byte)((uint)uVar2 >> 0x18);
    if (bVar4 == 0) {
      return 0;
    }
    bVar5 = bVar3 < ((byte *)_Str2)[3];
    if (bVar3 != ((byte *)_Str2)[3]) break;
    _Str2 = (char *)((byte *)_Str2 + 4);
    _Str1 = _Str1 + 4;
    if (bVar3 == 0) {
      return 0;
    }
  }
LAB_6f623824:
  return (uint)bVar5 * -2 + 1;
}



// Function: FUN_6f623870 at 6f623870

int __cdecl FUN_6f623870(undefined1 *param_1,byte *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined1 *local_24;
  int local_20;
  undefined1 *local_1c;
  undefined4 local_18;
  
  if ((param_1 == (undefined1 *)0x0) &&
     (iVar2 = FUN_6f625320(2,0x6f637084,0x5d,0,(byte *)"string != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  if ((param_2 == (byte *)0x0) &&
     (iVar2 = FUN_6f625320(2,0x6f637084,0x5e,0,(byte *)"format != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  local_18 = 0x42;
  local_1c = param_1;
  local_24 = param_1;
  local_20 = 0x7fffffff;
  iVar2 = FUN_6f625d10((int *)&local_24,param_2,(undefined4 *)&stack0x0000000c);
  local_20 = local_20 + -1;
  if (local_20 < 0) {
    FUN_6f625a90(0,(int *)&local_24);
  }
  else {
    *local_24 = 0;
  }
  return iVar2;
}



// Function: FUN_6f623970 at 6f623970

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_6f623970(undefined4 param_1,int param_2)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  uint uVar3;
  
  if (param_2 == 1) {
    DAT_6f63ce24 = GetVersion();
    if (DAT_6f63ce18 == 0) {
      if (((DAT_6f63ce24 & 0xff) == 3) && ((int)DAT_6f63ce24 < 0)) {
        FUN_6f62a400(2);
      }
      hModule = GetModuleHandleA("kernel32.dll");
      if ((hModule != (HMODULE)0x0) &&
         (pFVar1 = GetProcAddress(hModule,"IsTNT"), pFVar1 != (FARPROC)0x0)) {
        FUN_6f62a400(1);
      }
    }
    iVar2 = FUN_6f62a310();
    if (iVar2 == 0) {
      return 0;
    }
    _DAT_6f63ce30 = DAT_6f63ce24 >> 8 & 0xff;
    DAT_6f63ce2c = DAT_6f63ce24 & 0xff;
    _DAT_6f63ce28 = DAT_6f63ce2c * 0x100 + _DAT_6f63ce30;
    DAT_6f63ce24 = DAT_6f63ce24 >> 0x10;
    iVar2 = FUN_6f626db0();
    if (iVar2 == 0) {
      FUN_6f62a360();
      return 0;
    }
    DAT_6f63e3f4 = GetCommandLineA();
    DAT_6f63ce0c = FUN_6f62a0f0();
    if ((DAT_6f63e3f4 == (LPSTR)0x0) || (DAT_6f63ce0c == (LPSTR)0x0)) {
      FUN_6f626e40();
      FUN_6f62a360();
      return 0;
    }
    FUN_6f627040();
    FUN_6f629e60();
    FUN_6f6294e0();
    FUN_6f6293a0();
    FUN_6f626bb0();
    DAT_6f63ce08 = DAT_6f63ce08 + 1;
  }
  else if (param_2 == 0) {
    if (DAT_6f63ce08 < 1) {
      return 0;
    }
    DAT_6f63ce08 = DAT_6f63ce08 + -1;
    if (DAT_6f63ce5c == 0) {
      FUN_6f626c30();
    }
    uVar3 = FUN_6f628940(-1);
    if ((uVar3 & 0x20) != 0) {
      FUN_6f629250();
    }
    __ioterm();
    FUN_6f626e40();
    FUN_6f62a360();
  }
  else if (param_2 == 3) {
    FUN_6f626f30((LPVOID)0x0);
  }
  return 1;
}



// Function: entry at 6f623b40

int entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int local_8;
  
  local_8 = 1;
  if ((param_2 == 0) && (DAT_6f63ce08 == 0)) {
    local_8 = 0;
  }
  else {
    if ((param_2 == 1) || (param_2 == 2)) {
      if (DAT_6f63e3f8 != (code *)0x0) {
        local_8 = (*DAT_6f63e3f8)(param_1,param_2,param_3);
      }
      if (local_8 != 0) {
        local_8 = FUN_6f623970(param_1,param_2);
      }
      if (local_8 == 0) {
        return 0;
      }
    }
    local_8 = FUN_6f62a410();
    if ((param_2 == 1) && (local_8 == 0)) {
      FUN_6f623970(param_1,0);
    }
    if ((param_2 == 0) || (param_2 == 3)) {
      iVar1 = FUN_6f623970(param_1,param_2);
      if (iVar1 == 0) {
        local_8 = 0;
      }
      if ((local_8 != 0) && (DAT_6f63e3f8 != (code *)0x0)) {
        local_8 = (*DAT_6f63e3f8)(param_1,param_2,param_3);
      }
    }
  }
  return local_8;
}



// Function: __amsg_exit at 6f623c40

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 2003 Debug */

void __cdecl __amsg_exit(int param_1)

{
  if ((DAT_6f63ce14 == 1) || ((DAT_6f63ce14 == 0 && (DAT_6f63ce18 == 1)))) {
    __FF_MSGBANNER();
  }
  FUN_6f62a470(param_1);
  (*(code *)PTR___exit_6f639690)(0xff);
  return;
}



// Function: FUN_6f623c80 at 6f623c80

int __cdecl FUN_6f623c80(int *param_1,byte *param_2,undefined4 *param_3)

{
  byte bVar1;
  code *pcVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  bool bVar7;
  longlong lVar8;
  int *piVar9;
  int local_228;
  uint local_224;
  uint local_220;
  uint local_21c;
  uint local_218;
  uint local_214;
  uint local_210;
  uint local_20c;
  uint local_200;
  uint local_1fc;
  byte local_1f4;
  undefined1 local_1f3;
  uint local_1f0;
  int local_1ec;
  WCHAR *local_1e8;
  byte *local_1e4;
  int local_1e0;
  uint local_1dc;
  undefined4 *local_1d8;
  byte local_1d4;
  byte local_1d3 [351];
  char local_74;
  int local_70;
  char local_6c;
  char local_68;
  byte local_64 [11];
  undefined1 local_59;
  int local_44;
  WCHAR *local_40;
  char local_3c;
  int local_38;
  undefined8 local_34;
  char local_2c;
  uint local_28;
  int local_24;
  int local_20;
  char local_1c;
  char local_18;
  byte local_14;
  uint local_10;
  uint local_c;
  WCHAR local_8 [2];
  
  if ((param_2 == (byte *)0x0) &&
     (iVar4 = FUN_6f625320(2,0x6f6370b8,0x109,0,(byte *)"format != NULL"), iVar4 == 1)) {
    pcVar2 = (code *)swi(3);
    iVar4 = (*pcVar2)();
    return iVar4;
  }
  if ((param_1 == (int *)0x0) &&
     (iVar4 = FUN_6f625320(2,0x6f6370b8,0x10c,0,(byte *)"stream != NULL"), iVar4 == 1)) {
    pcVar2 = (code *)swi(3);
    iVar4 = (*pcVar2)();
    return iVar4;
  }
  local_2c = '\0';
  local_38 = 0;
  local_24 = local_38;
  do {
    if (*param_2 == 0) {
LAB_6f624f6a:
      if ((local_1dc == 0xffffffff) && ((local_38 == 0 && (local_2c == '\0')))) {
        local_228 = -1;
        local_38 = local_228;
      }
      return local_38;
    }
    if ((int)DAT_6f6398f0 < 2) {
      local_1fc = *(ushort *)(PTR_DAT_6f639900 + (uint)*param_2 * 2) & 8;
    }
    else {
      local_1fc = FUN_6f62acf0((uint)*param_2,8);
    }
    if (local_1fc != 0) {
      local_24 = local_24 + -1;
      piVar9 = param_1;
      uVar5 = __whiteout(&local_24,param_1);
      FUN_6f625130(uVar5,piVar9);
      do {
        param_2 = param_2 + 1;
        uVar5 = FUN_6f62aa60((uint)*param_2);
      } while (uVar5 != 0);
    }
    if (*param_2 == 0x25) {
      local_44 = 0;
      local_c = local_c & 0xffffff00;
      local_70 = 0;
      local_1ec = 0;
      local_20 = 0;
      local_14 = 0;
      local_6c = '\0';
      local_74 = '\0';
      local_1c = '\0';
      local_68 = '\0';
      local_18 = '\0';
      local_3c = '\x01';
      local_1e0 = 0;
LAB_6f623df5:
      if (local_1c == '\0') {
        pbVar6 = param_2 + 1;
        local_10 = (uint)*pbVar6;
        if ((int)DAT_6f6398f0 < 2) {
          local_200 = *(ushort *)(PTR_DAT_6f639900 + local_10 * 2) & 4;
        }
        else {
          local_200 = FUN_6f62acf0(local_10,4);
        }
        if (local_200 == 0) {
          switch(local_10) {
          case 0x2a:
            local_74 = local_74 + '\x01';
            param_2 = pbVar6;
            break;
          case 0x46:
          case 0x4e:
            param_2 = pbVar6;
            break;
          case 0x49:
            if ((param_2[2] == 0x36) && (param_2[3] == 0x34)) {
              local_1e0 = local_1e0 + 1;
              local_34 = 0;
              param_2 = param_2 + 3;
              break;
            }
          default:
            local_1c = local_1c + '\x01';
            param_2 = pbVar6;
            break;
          case 0x4c:
            local_3c = local_3c + '\x01';
            param_2 = pbVar6;
            break;
          case 0x68:
            local_3c = local_3c + -1;
            local_18 = local_18 + -1;
            param_2 = pbVar6;
            break;
          case 0x6c:
            local_3c = local_3c + '\x01';
          case 0x77:
            local_18 = local_18 + '\x01';
            param_2 = pbVar6;
          }
        }
        else {
          local_1ec = local_1ec + 1;
          local_20 = (local_10 - 0x30) + local_20 * 10;
          param_2 = pbVar6;
        }
        goto LAB_6f623df5;
      }
      if (local_74 == '\0') {
        local_1d8 = param_3;
        local_40 = (WCHAR *)*param_3;
        param_3 = param_3 + 1;
      }
      local_1c = '\0';
      if (local_18 == '\0') {
        if ((*param_2 == 0x53) || (*param_2 == 0x43)) {
          local_18 = '\x01';
        }
        else {
          local_18 = -1;
        }
      }
      local_10 = *param_2 | 0x20;
      if (local_10 != 0x6e) {
        if ((local_10 == 99) || (local_10 == 0x7b)) {
          local_24 = local_24 + 1;
          local_1dc = __inc(param_1);
        }
        else {
          local_1dc = __whiteout(&local_24,param_1);
        }
      }
      if ((local_1ec != 0) && (local_20 == 0)) {
        local_24 = local_24 + -1;
        FUN_6f625130(local_1dc,param_1);
        goto LAB_6f624f6a;
      }
      pbVar6 = param_2;
      switch(local_10) {
      case 99:
        if (local_1ec == 0) {
          local_1ec = 1;
          local_20 = local_20 + 1;
        }
        if ('\0' < local_18) {
          local_68 = local_68 + '\x01';
        }
        local_1e4 = &DAT_6f63969c;
        local_14 = local_14 - 1;
        goto LAB_6f624100;
      case 100:
      case 0x6f:
      case 0x75:
        goto switchD_6f624044_caseD_64;
      case 0x65:
      case 0x66:
      case 0x67:
        local_1e4 = &local_1d4;
        if (local_1dc == 0x2d) {
          local_1d4 = 0x2d;
          local_1e4 = local_1d3;
LAB_6f624a2f:
          local_20 = local_20 + -1;
          local_24 = local_24 + 1;
          local_1dc = __inc(param_1);
        }
        else if (local_1dc == 0x2b) goto LAB_6f624a2f;
        if ((local_1ec == 0) || (0x15d < local_20)) {
          local_20 = 0x15d;
        }
        while( true ) {
          if ((int)DAT_6f6398f0 < 2) {
            local_21c = *(ushort *)(PTR_DAT_6f639900 + local_1dc * 2) & 4;
          }
          else {
            local_21c = FUN_6f62acf0(local_1dc,4);
          }
          if ((local_21c == 0) ||
             (iVar4 = local_20 + -1, bVar7 = local_20 == 0, local_20 = iVar4, bVar7)) break;
          local_70 = local_70 + 1;
          *local_1e4 = (byte)local_1dc;
          local_1e4 = local_1e4 + 1;
          local_24 = local_24 + 1;
          local_1dc = __inc(param_1);
        }
        if ((DAT_6f6398f4 == (byte)local_1dc) &&
           (iVar4 = local_20 + -1, bVar7 = local_20 != 0, local_20 = iVar4, bVar7)) {
          local_24 = local_24 + 1;
          local_1dc = __inc(param_1);
          *local_1e4 = DAT_6f6398f4;
          local_1e4 = local_1e4 + 1;
          while( true ) {
            if ((int)DAT_6f6398f0 < 2) {
              local_220 = *(ushort *)(PTR_DAT_6f639900 + local_1dc * 2) & 4;
            }
            else {
              local_220 = FUN_6f62acf0(local_1dc,4);
            }
            if ((local_220 == 0) ||
               (iVar4 = local_20 + -1, bVar7 = local_20 == 0, local_20 = iVar4, bVar7)) break;
            local_70 = local_70 + 1;
            *local_1e4 = (byte)local_1dc;
            local_1e4 = local_1e4 + 1;
            local_24 = local_24 + 1;
            local_1dc = __inc(param_1);
          }
        }
        if ((local_70 != 0) &&
           (((local_1dc == 0x65 || (local_1dc == 0x45)) &&
            (iVar4 = local_20 + -1, bVar7 = local_20 != 0, local_20 = iVar4, bVar7)))) {
          *local_1e4 = 0x65;
          local_1e4 = local_1e4 + 1;
          local_24 = local_24 + 1;
          local_1dc = __inc(param_1);
          if (local_1dc == 0x2d) {
            *local_1e4 = 0x2d;
            local_1e4 = local_1e4 + 1;
LAB_6f624c97:
            if (local_20 != 0) {
              local_24 = local_24 + 1;
              local_20 = local_20 + -1;
              local_1dc = __inc(param_1);
            }
          }
          else if (local_1dc == 0x2b) goto LAB_6f624c97;
          while( true ) {
            if ((int)DAT_6f6398f0 < 2) {
              local_224 = *(ushort *)(PTR_DAT_6f639900 + local_1dc * 2) & 4;
            }
            else {
              local_224 = FUN_6f62acf0(local_1dc,4);
            }
            if ((local_224 == 0) ||
               (iVar4 = local_20 + -1, bVar7 = local_20 == 0, local_20 = iVar4, bVar7)) break;
            local_70 = local_70 + 1;
            *local_1e4 = (byte)local_1dc;
            local_1e4 = local_1e4 + 1;
            local_24 = local_24 + 1;
            local_1dc = __inc(param_1);
          }
        }
        local_24 = local_24 + -1;
        FUN_6f625130(local_1dc,param_1);
        if (local_70 == 0) goto LAB_6f624f6a;
        if (local_74 == '\0') {
          local_38 = local_38 + 1;
          *local_1e4 = 0;
          (*(code *)PTR___fptrap_6f6398e0)(local_3c + -1,local_40,&local_1d4);
        }
        break;
      default:
        if (*param_2 != local_1dc) {
          local_24 = local_24 + -1;
          FUN_6f625130(local_1dc,param_1);
          goto LAB_6f624f6a;
        }
        local_2c = local_2c + -1;
        if (local_74 == '\0') {
          param_3 = local_1d8;
        }
        break;
      case 0x69:
        local_10 = 100;
      case 0x78:
        if (local_1dc == 0x2d) {
          local_6c = local_6c + '\x01';
LAB_6f62449f:
          local_20 = local_20 + -1;
          if ((local_20 == 0) && (local_1ec != 0)) {
            local_1c = local_1c + '\x01';
          }
          else {
            local_24 = local_24 + 1;
            local_1dc = __inc(param_1);
          }
        }
        else if (local_1dc == 0x2b) goto LAB_6f62449f;
        if (local_1dc == 0x30) {
          local_24 = local_24 + 1;
          local_1dc = __inc(param_1);
          if (((byte)local_1dc == 'x') || ((byte)local_1dc == 'X')) {
            local_24 = local_24 + 1;
            local_1dc = __inc(param_1);
            local_10 = 0x78;
          }
          else {
            local_70 = local_70 + 1;
            if (local_10 == 0x78) {
              local_24 = local_24 + -1;
              FUN_6f625130(local_1dc,param_1);
              local_1dc = 0x30;
            }
            else {
              local_10 = 0x6f;
            }
          }
        }
        goto LAB_6f6245de;
      case 0x6e:
        local_44 = local_24;
        if (local_74 != '\0') break;
        goto LAB_6f6249a1;
      case 0x70:
        local_3c = '\x01';
switchD_6f624044_caseD_64:
        if (local_1dc == 0x2d) {
          local_6c = local_6c + '\x01';
LAB_6f6245a1:
          local_20 = local_20 + -1;
          if ((local_20 == 0) && (local_1ec != 0)) {
            local_1c = local_1c + '\x01';
          }
          else {
            local_24 = local_24 + 1;
            local_1dc = __inc(param_1);
          }
        }
        else if (local_1dc == 0x2b) goto LAB_6f6245a1;
LAB_6f6245de:
        if (local_1e0 == 0) {
          while (local_1c == '\0') {
            if ((local_10 == 0x78) || (local_10 == 0x70)) {
              if ((int)DAT_6f6398f0 < 2) {
                local_214 = *(ushort *)(PTR_DAT_6f639900 + local_1dc * 2) & 0x80;
              }
              else {
                local_214 = FUN_6f62acf0(local_1dc,0x80);
              }
              if (local_214 == 0) {
                local_1c = local_1c + '\x01';
              }
              else {
                local_44 = local_44 << 4;
                local_1dc = FUN_6f625070(local_1dc);
              }
            }
            else {
              if ((int)DAT_6f6398f0 < 2) {
                local_218 = *(ushort *)(PTR_DAT_6f639900 + local_1dc * 2) & 4;
              }
              else {
                local_218 = FUN_6f62acf0(local_1dc,4);
              }
              if (local_218 == 0) {
                local_1c = local_1c + '\x01';
              }
              else if (local_10 == 0x6f) {
                if ((int)local_1dc < 0x38) {
                  local_44 = local_44 << 3;
                }
                else {
                  local_1c = local_1c + '\x01';
                }
              }
              else {
                local_44 = local_44 * 10;
              }
            }
            if (local_1c == '\0') {
              local_70 = local_70 + 1;
              local_44 = local_44 + -0x30 + local_1dc;
              if ((local_1ec == 0) || (local_20 = local_20 + -1, local_20 != 0)) {
                local_24 = local_24 + 1;
                local_1dc = __inc(param_1);
              }
              else {
                local_1c = '\x01';
              }
            }
            else {
              local_24 = local_24 + -1;
              FUN_6f625130(local_1dc,param_1);
            }
          }
          if (local_6c != '\0') {
            local_44 = -local_44;
          }
        }
        else {
          while (local_1c == '\0') {
            if (local_10 == 0x78) {
              if ((int)DAT_6f6398f0 < 2) {
                local_20c = *(ushort *)(PTR_DAT_6f639900 + local_1dc * 2) & 0x80;
              }
              else {
                local_20c = FUN_6f62acf0(local_1dc,0x80);
              }
              if (local_20c == 0) {
                local_1c = local_1c + '\x01';
              }
              else {
                local_34 = __allshl(4,local_34._4_4_);
                local_1dc = FUN_6f625070(local_1dc);
              }
            }
            else {
              if ((int)DAT_6f6398f0 < 2) {
                local_210 = *(ushort *)(PTR_DAT_6f639900 + local_1dc * 2) & 4;
              }
              else {
                local_210 = FUN_6f62acf0(local_1dc,4);
              }
              if (local_210 == 0) {
                local_1c = local_1c + '\x01';
              }
              else if (local_10 == 0x6f) {
                if ((int)local_1dc < 0x38) {
                  local_34 = __allshl(3,local_34._4_4_);
                }
                else {
                  local_1c = local_1c + '\x01';
                }
              }
              else {
                lVar8 = __allshl(2,local_34._4_4_);
                local_34 = __allshl(1,(int)((ulonglong)lVar8 >> 0x20) + local_34._4_4_ +
                                      (uint)CARRY4((uint)lVar8,(uint)local_34));
              }
            }
            if (local_1c == '\0') {
              local_70 = local_70 + 1;
              uVar5 = local_1dc - 0x30;
              local_34 = CONCAT44(local_34._4_4_ + ((int)uVar5 >> 0x1f) +
                                  (uint)CARRY4((uint)local_34,uVar5),(uint)local_34 + uVar5);
              if ((local_1ec == 0) || (local_20 = local_20 + -1, local_20 != 0)) {
                local_24 = local_24 + 1;
                local_1dc = __inc(param_1);
              }
              else {
                local_1c = '\x01';
              }
            }
            else {
              local_24 = local_24 + -1;
              FUN_6f625130(local_1dc,param_1);
            }
          }
          if (local_6c != '\0') {
            local_34 = CONCAT44(-(local_34._4_4_ + (uint)((uint)local_34 != 0)),-(uint)local_34);
          }
        }
        if (local_10 == 0x46) {
          local_70 = 0;
        }
        if (local_70 == 0) goto LAB_6f624f6a;
        if (local_74 == '\0') {
          local_38 = local_38 + 1;
LAB_6f6249a1:
          if (local_1e0 == 0) {
            if (local_3c == '\0') {
              *local_40 = (WCHAR)local_44;
            }
            else {
              *(int *)local_40 = local_44;
            }
          }
          else {
            *(uint *)local_40 = (uint)local_34;
            *(int *)(local_40 + 2) = local_34._4_4_;
          }
        }
        break;
      case 0x73:
        if ('\0' < local_18) {
          local_68 = local_68 + '\x01';
        }
        local_1e4 = (byte *)s_____6f639694;
        local_14 = local_14 - 1;
        goto LAB_6f624100;
      case 0x7b:
        if ('\0' < local_18) {
          local_68 = local_68 + '\x01';
        }
        pbVar6 = param_2 + 1;
        local_1e4 = pbVar6;
        if (*pbVar6 == 0x5e) {
          local_1e4 = param_2 + 2;
          local_14 = local_14 - 1;
        }
LAB_6f624100:
        param_2 = pbVar6;
        _memset(local_64,0,0x20);
        if ((local_10 == 0x7b) && (*local_1e4 == 0x5d)) {
          local_c = CONCAT31(local_c._1_3_,0x5d);
          local_59 = 0x20;
          local_1e4 = local_1e4 + 1;
        }
        while (*local_1e4 != 0x5d) {
          bVar1 = *local_1e4;
          local_1f0 = CONCAT31(local_1f0._1_3_,bVar1);
          pbVar6 = local_1e4 + 1;
          if (((bVar1 == 0x2d) && ((local_c & 0xff) != 0)) && (*pbVar6 != 0x5d)) {
            bVar1 = *pbVar6;
            local_1e4 = local_1e4 + 2;
            if ((uint)bVar1 <= (local_c & 0xff)) {
              bVar3 = (byte)local_c;
              local_c = CONCAT31(local_c._1_3_,bVar1);
              bVar1 = bVar3;
            }
            local_28 = CONCAT31(local_28._1_3_,bVar1);
            for (local_1f0 = CONCAT31(local_1f0._1_3_,(byte)local_c);
                (local_1f0 & 0xff) <= (local_28 & 0xff);
                local_1f0 = CONCAT31(local_1f0._1_3_,(byte)local_1f0 + 1)) {
              local_64[(int)(local_1f0 & 0xff) >> 3] =
                   local_64[(int)(local_1f0 & 0xff) >> 3] | (byte)(1 << ((byte)local_1f0 & 7));
            }
            local_c = local_c & 0xffffff00;
          }
          else {
            local_c = CONCAT31(local_c._1_3_,bVar1);
            local_64[(int)(uint)bVar1 >> 3] =
                 local_64[(int)(uint)bVar1 >> 3] | (byte)(1 << (bVar1 & 7));
            local_1e4 = pbVar6;
          }
        }
        if (*local_1e4 == 0) goto LAB_6f624f6a;
        if (local_10 == 0x7b) {
          param_2 = local_1e4;
        }
        local_1e8 = local_40;
        local_24 = local_24 + -1;
        FUN_6f625130(local_1dc,param_1);
        while( true ) {
          if ((local_1ec != 0) &&
             (iVar4 = local_20 + -1, bVar7 = local_20 == 0, local_20 = iVar4, bVar7))
          goto LAB_6f624435;
          local_24 = local_24 + 1;
          local_1dc = __inc(param_1);
          if ((local_1dc == 0xffffffff) ||
             (bVar1 = (byte)local_1dc,
             ((int)(char)(local_64[(int)local_1dc >> 3] ^ local_14) & 1 << (bVar1 & 7)) == 0))
          break;
          if (local_74 == '\0') {
            if (local_68 == '\0') {
              *(byte *)local_40 = bVar1;
              local_40 = (WCHAR *)((int)local_40 + 1);
            }
            else {
              local_1f4 = bVar1;
              if ((*(ushort *)(PTR_DAT_6f639900 + (local_1dc & 0xff) * 2) & 0x8000) != 0) {
                local_24 = local_24 + 1;
                uVar5 = __inc(param_1);
                local_1f3 = (undefined1)uVar5;
              }
              FUN_6f62a6c0(local_8,&local_1f4,DAT_6f6398f0);
              *local_40 = local_8[0];
              local_40 = local_40 + 1;
            }
          }
          else {
            local_1e8 = (WCHAR *)((int)local_1e8 + 1);
          }
        }
        local_24 = local_24 + -1;
        FUN_6f625130(local_1dc,param_1);
LAB_6f624435:
        if (local_1e8 == local_40) goto LAB_6f624f6a;
        if ((local_74 == '\0') && (local_38 = local_38 + 1, local_10 != 99)) {
          if (local_68 == '\0') {
            *(byte *)local_40 = 0;
          }
          else {
            *local_40 = L'\0';
          }
        }
      }
      local_2c = local_2c + '\x01';
      pbVar6 = param_2 + 1;
    }
    else {
      local_24 = local_24 + 1;
      bVar1 = *param_2;
      local_1dc = __inc(param_1);
      if (bVar1 != local_1dc) {
        local_24 = local_24 + -1;
        FUN_6f625130(local_1dc,param_1);
        goto LAB_6f624f6a;
      }
      pbVar6 = param_2 + 1;
      if ((*(ushort *)(PTR_DAT_6f639900 + (local_1dc & 0xff) * 2) & 0x8000) != 0) {
        local_24 = local_24 + 1;
        bVar1 = param_2[1];
        uVar5 = __inc(param_1);
        if (bVar1 == uVar5) {
          local_24 = local_24 + -1;
          pbVar6 = param_2 + 2;
          goto LAB_6f624f41;
        }
        local_24 = local_24 + -1;
        FUN_6f625130(uVar5,param_1);
        local_24 = local_24 + -1;
        FUN_6f625130(local_1dc,param_1);
        goto LAB_6f624f6a;
      }
    }
LAB_6f624f41:
    param_2 = pbVar6;
    if ((local_1dc == 0xffffffff) && ((*param_2 != 0x25 || (param_2[1] != 0x6e))))
    goto LAB_6f624f6a;
  } while( true );
}



// Function: FUN_6f625070 at 6f625070

uint __cdecl FUN_6f625070(uint param_1)

{
  uint local_c;
  uint local_8;
  
  if (DAT_6f6398f0 < 2) {
    local_8 = *(ushort *)(PTR_DAT_6f639900 + param_1 * 2) & 4;
  }
  else {
    local_8 = FUN_6f62acf0(param_1,4);
  }
  if (local_8 == 0) {
    local_c = (param_1 & 0xffffffdf) - 7;
  }
  else {
    local_c = param_1;
  }
  return local_c;
}



// Function: __inc at 6f6250d0

/* Library Function - Single Match
    __inc
   
   Library: Visual Studio 2003 Debug */

uint __cdecl __inc(int *param_1)

{
  uint local_8;
  
  param_1[1] = param_1[1] + -1;
  if (param_1[1] < 0) {
    local_8 = FUN_6f62add0(param_1);
  }
  else {
    local_8 = (uint)*(byte *)*param_1;
    *param_1 = *param_1 + 1;
  }
  return local_8;
}



// Function: FUN_6f625130 at 6f625130

void __cdecl FUN_6f625130(uint param_1,int *param_2)

{
  if (param_1 != 0xffffffff) {
    FUN_6f62b030(param_1,param_2);
  }
  return;
}



// Function: __whiteout at 6f625150

/* Library Function - Single Match
    __whiteout
   
   Library: Visual Studio 2003 Debug */

uint __cdecl __whiteout(int *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  
  do {
    *param_1 = *param_1 + 1;
    uVar1 = __inc(param_2);
    uVar2 = FUN_6f62aa60(uVar1);
  } while (uVar2 != 0);
  return uVar1;
}



// Function: _strlen at 6f625190

/* Library Function - Single Match
    _strlen
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

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
    if ((char)uVar1 == '\0') goto LAB_6f6251e3;
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
LAB_6f6251e3:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
}



// Function: FUN_6f625210 at 6f625210

void FUN_6f625210(void)

{
  DebugBreak();
  return;
}



// Function: FUN_6f625220 at 6f625220

undefined4 __cdecl FUN_6f625220(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((param_1 < 0) || (2 < param_1)) {
    uVar1 = 0xffffffff;
  }
  else if (param_2 == 0xffffffff) {
    uVar1 = *(undefined4 *)(&DAT_6f6396a8 + param_1 * 4);
  }
  else if ((param_2 & 0xfffffff8) == 0) {
    uVar1 = *(undefined4 *)(&DAT_6f6396a8 + param_1 * 4);
    *(uint *)(&DAT_6f6396a8 + param_1 * 4) = param_2;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



// Function: __CrtSetReportFile at 6f625280

/* Library Function - Single Match
    __CrtSetReportFile
   
   Library: Visual Studio 2003 Debug */

undefined4 __cdecl __CrtSetReportFile(int param_1,int param_2)

{
  undefined4 uVar1;
  HANDLE pvVar2;
  
  if ((param_1 < 0) || (2 < param_1)) {
    uVar1 = 0xfffffffe;
  }
  else if (param_2 == -6) {
    uVar1 = *(undefined4 *)(&DAT_6f6396b8 + param_1 * 4);
  }
  else {
    uVar1 = *(undefined4 *)(&DAT_6f6396b8 + param_1 * 4);
    if (param_2 == -4) {
      pvVar2 = GetStdHandle(0xfffffff5);
      *(HANDLE *)(&DAT_6f6396b8 + param_1 * 4) = pvVar2;
    }
    else if (param_2 == -5) {
      pvVar2 = GetStdHandle(0xfffffff4);
      *(HANDLE *)(&DAT_6f6396b8 + param_1 * 4) = pvVar2;
    }
    else {
      *(int *)(&DAT_6f6396b8 + param_1 * 4) = param_2;
    }
  }
  return uVar1;
}



// Function: FUN_6f625300 at 6f625300

undefined4 __cdecl FUN_6f625300(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_6f63e3f0;
  DAT_6f63e3f0 = param_1;
  return uVar1;
}



// Function: FUN_6f625320 at 6f625320

undefined4 __cdecl
FUN_6f625320(int param_1,int param_2,int param_3,undefined4 param_4,byte *param_5)

{
  bool bVar1;
  LONG LVar2;
  size_t nNumberOfBytesToWrite;
  undefined3 extraout_var;
  int iVar3;
  undefined4 *puVar4;
  uint *local_302c;
  char local_3028 [20];
  DWORD local_3014;
  HMODULE local_3010;
  undefined1 local_300c;
  undefined4 local_300b;
  undefined1 local_200c;
  undefined4 local_200b;
  undefined4 local_100c;
  undefined4 *local_1008;
  undefined1 local_1004;
  undefined4 local_1003;
  undefined4 uStackY_24;
  DWORD *lpNumberOfBytesWritten;
  LPOVERLAPPED lpOverlapped;
  
  FUN_6f62b640();
  local_300c = 0;
  puVar4 = &local_300b;
  for (iVar3 = 0x3ff; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined2 *)puVar4 = 0;
  *(undefined1 *)((int)puVar4 + 2) = 0;
  local_200c = '\0';
  puVar4 = &local_200b;
  for (iVar3 = 0x3ff; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined2 *)puVar4 = 0;
  *(undefined1 *)((int)puVar4 + 2) = 0;
  local_1004 = 0;
  puVar4 = &local_1003;
  for (iVar3 = 0x3ff; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined2 *)puVar4 = 0;
  *(undefined1 *)((int)puVar4 + 2) = 0;
  local_1008 = (undefined4 *)&stack0x00000018;
  if ((param_1 < 0) || (2 < param_1)) {
    local_100c = 0xffffffff;
  }
  else if ((param_1 == 2) && (LVar2 = InterlockedIncrement((LONG *)&DAT_6f6396a0), 0 < LVar2)) {
    if ((DAT_6f63ce1c == (FARPROC)0x0) &&
       ((local_3010 = LoadLibraryA("user32.dll"), local_3010 == (HMODULE)0x0 ||
        (DAT_6f63ce1c = GetProcAddress(local_3010,"wsprintfA"), DAT_6f63ce1c == (FARPROC)0x0)))) {
      local_100c = 0xffffffff;
    }
    else {
      (*DAT_6f63ce1c)();
      OutputDebugStringA(&local_200c);
      InterlockedDecrement((LONG *)&DAT_6f6396a0);
      FUN_6f625210();
      local_100c = 0xffffffff;
    }
  }
  else {
    if ((param_5 != (byte *)0x0) &&
       (iVar3 = FUN_6f62b540(&local_1004,0xfed,param_5,local_1008), iVar3 < 0)) {
      FUN_6f6235b0((uint *)&local_1004,(uint *)"_CrtDbgReport: String too long or IO Error");
    }
    if (param_1 == 2) {
      if (param_5 == (byte *)0x0) {
        local_302c = (uint *)0x6f6370f8;
      }
      else {
        local_302c = (uint *)0x6f63710c;
      }
      FUN_6f6235b0((uint *)&local_300c,local_302c);
    }
    FUN_6f6235c0((uint *)&local_300c,(uint *)&local_1004);
    if (param_1 == 2) {
      if ((uRam6f6396b0 & 1) != 0) {
        FUN_6f6235c0((uint *)&local_300c,(uint *)&DAT_6f6370f4);
      }
      FUN_6f6235c0((uint *)&local_300c,(uint *)&DAT_6f6370f0);
    }
    if (param_2 == 0) {
      FUN_6f6235b0((uint *)&local_200c,(uint *)&local_300c);
    }
    else {
      uStackY_24 = 0x6f625535;
      iVar3 = FUN_6f62b440(&local_200c,0x1000,(byte *)"%s(%d) : %s");
      if (iVar3 < 0) {
        FUN_6f6235b0((uint *)&local_200c,(uint *)"_CrtDbgReport: String too long or IO Error");
      }
    }
    if ((DAT_6f63e3f0 == (code *)0x0) || (iVar3 = (*DAT_6f63e3f0)(), iVar3 == 0)) {
      if (((*(uint *)(&DAT_6f6396a8 + param_1 * 4) & 1) != 0) &&
         (*(int *)(&DAT_6f6396b8 + param_1 * 4) != -1)) {
        lpOverlapped = (LPOVERLAPPED)0x0;
        lpNumberOfBytesWritten = &local_3014;
        nNumberOfBytesToWrite = _strlen(&local_200c);
        WriteFile(*(HANDLE *)(&DAT_6f6396b8 + param_1 * 4),&local_200c,nNumberOfBytesToWrite,
                  lpNumberOfBytesWritten,lpOverlapped);
      }
      if ((*(uint *)(&DAT_6f6396a8 + param_1 * 4) & 2) != 0) {
        OutputDebugStringA(&local_200c);
      }
      if ((*(uint *)(&DAT_6f6396a8 + param_1 * 4) & 4) == 0) {
        if (param_1 == 2) {
          InterlockedDecrement((LONG *)&DAT_6f6396a0);
        }
        local_100c = 0;
      }
      else {
        if (param_3 != 0) {
          __itoa(param_3,local_3028,10);
        }
        bVar1 = FUN_6f6256b0();
        local_100c = CONCAT31(extraout_var,bVar1);
        if (param_1 == 2) {
          InterlockedDecrement((LONG *)&DAT_6f6396a0);
        }
      }
    }
    else if (param_1 == 2) {
      InterlockedDecrement((LONG *)&DAT_6f6396a0);
    }
  }
  return local_100c;
}



// Function: FUN_6f6256b0 at 6f6256b0

bool FUN_6f6256b0(void)

{
  int iVar1;
  DWORD DVar2;
  size_t sVar3;
  char *in_stack_00000010;
  int in_stack_00000014;
  uint local_1110 [1024];
  int local_110;
  uint local_10c [50];
  undefined4 uStackY_44;
  uint *_Str;
  
  FUN_6f62b640();
  if ((in_stack_00000014 == 0) &&
     (iVar1 = FUN_6f625320(2,0x6f6372d4,0x1da,0,(byte *)"szUserMessage != NULL"), iVar1 == 1)) {
    FUN_6f625210();
  }
  DVar2 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_10c,0x104);
  if (DVar2 == 0) {
    FUN_6f6235b0(local_10c,(uint *)"<program name unknown>");
  }
  _Str = local_10c;
  sVar3 = _strlen((char *)_Str);
  if (0x40 < sVar3) {
    _strlen((char *)_Str);
    _strncpy((char *)0x3,"...",3);
  }
  if ((in_stack_00000010 != (char *)0x0) && (sVar3 = _strlen(in_stack_00000010), 0x40 < sVar3)) {
    sVar3 = _strlen(in_stack_00000010);
    _strncpy(in_stack_00000010 + (sVar3 - 0x40),"...",3);
  }
  uStackY_44 = 0x6f625952;
  iVar1 = FUN_6f62b440((undefined1 *)local_1110,0x1000,
                       (byte *)
                       "Debug %s!\n\nProgram: %s%s%s%s%s%s%s%s%s%s%s\n\n(Press Retry to debug the application)"
                      );
  if (iVar1 < 0) {
    FUN_6f6235b0(local_1110,(uint *)"_CrtDbgReport: String too long or IO Error");
  }
  local_110 = FUN_6f62bc10(local_1110,"Microsoft Visual C++ Debug Library",0x12012);
  if (local_110 == 3) {
    FUN_6f62b940(0x16);
                    /* WARNING: Subroutine does not return */
    __exit(3);
  }
  return local_110 == 4;
}



// Function: FUN_6f6259d0 at 6f6259d0

uint * FUN_6f6259d0(uint *param_1,char param_2)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar1 = (uint)param_1 & 3;
  while (uVar1 != 0) {
    if ((char)*param_1 == param_2) {
      return param_1;
    }
    if ((char)*param_1 == '\0') {
      return (uint *)0x0;
    }
    uVar1 = (uint)((int)param_1 + 1) & 3;
    param_1 = (uint *)((int)param_1 + 1);
  }
  while( true ) {
    while( true ) {
      uVar1 = *param_1;
      uVar4 = uVar1 ^ CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
      uVar3 = uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff;
      puVar5 = param_1 + 1;
      if (((uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff) & 0x81010100) != 0) break;
      param_1 = puVar5;
      if ((uVar3 & 0x81010100) != 0) {
        if ((uVar3 & 0x1010100) != 0) {
          return (uint *)0x0;
        }
        if ((uVar1 + 0x7efefeff & 0x80000000) == 0) {
          return (uint *)0x0;
        }
      }
    }
    uVar1 = *param_1;
    if ((char)uVar1 == param_2) {
      return param_1;
    }
    if ((char)uVar1 == '\0') {
      return (uint *)0x0;
    }
    cVar2 = (char)(uVar1 >> 8);
    if (cVar2 == param_2) {
      return (uint *)((int)param_1 + 1);
    }
    if (cVar2 == '\0') break;
    cVar2 = (char)(uVar1 >> 0x10);
    if (cVar2 == param_2) {
      return (uint *)((int)param_1 + 2);
    }
    if (cVar2 == '\0') {
      return (uint *)0x0;
    }
    cVar2 = (char)(uVar1 >> 0x18);
    if (cVar2 == param_2) {
      return (uint *)((int)param_1 + 3);
    }
    param_1 = puVar5;
    if (cVar2 == '\0') {
      return (uint *)0x0;
    }
  }
  return (uint *)0x0;
}



// Function: FUN_6f6259d6 at 6f6259d6

uint * __cdecl FUN_6f6259d6(uint *param_1)

{
  uint uVar1;
  char cVar2;
  uint in_EAX;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  char cVar6;
  uint uVar7;
  
  cVar6 = (char)in_EAX;
  uVar7 = (uint)param_1 & 3;
  while (uVar7 != 0) {
    if ((char)*param_1 == cVar6) {
      return param_1;
    }
    if ((char)*param_1 == '\0') {
      return (uint *)0x0;
    }
    uVar7 = (uint)((int)param_1 + 1) & 3;
    param_1 = (uint *)((int)param_1 + 1);
  }
  uVar7 = in_EAX | in_EAX << 8;
  while( true ) {
    while( true ) {
      uVar1 = *param_1;
      uVar4 = uVar1 ^ (uVar7 << 0x10 | uVar7);
      uVar3 = uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff;
      puVar5 = param_1 + 1;
      if (((uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff) & 0x81010100) != 0) break;
      param_1 = puVar5;
      if ((uVar3 & 0x81010100) != 0) {
        if ((uVar3 & 0x1010100) != 0) {
          return (uint *)0x0;
        }
        if ((uVar1 + 0x7efefeff & 0x80000000) == 0) {
          return (uint *)0x0;
        }
      }
    }
    uVar1 = *param_1;
    if ((char)uVar1 == cVar6) {
      return param_1;
    }
    if ((char)uVar1 == '\0') {
      return (uint *)0x0;
    }
    cVar2 = (char)(uVar1 >> 8);
    if (cVar2 == cVar6) {
      return (uint *)((int)param_1 + 1);
    }
    if (cVar2 == '\0') break;
    cVar2 = (char)(uVar1 >> 0x10);
    if (cVar2 == cVar6) {
      return (uint *)((int)param_1 + 2);
    }
    if (cVar2 == '\0') {
      return (uint *)0x0;
    }
    cVar2 = (char)(uVar1 >> 0x18);
    if (cVar2 == cVar6) {
      return (uint *)((int)param_1 + 3);
    }
    param_1 = puVar5;
    if (cVar2 == '\0') {
      return (uint *)0x0;
    }
  }
  return (uint *)0x0;
}



// Function: FUN_6f625a90 at 6f625a90

uint __cdecl FUN_6f625a90(uint param_1,int *param_2)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined *local_18;
  uint local_10;
  uint local_8;
  
  if ((param_2 == (int *)0x0) &&
     (iVar3 = FUN_6f625320(2,0x6f637338,0x69,0,(byte *)"str != NULL"), iVar3 == 1)) {
    pcVar1 = (code *)swi(3);
    uVar4 = (*pcVar1)();
    return uVar4;
  }
  piVar2 = param_2;
  uVar4 = param_2[4];
  if (((param_2[3] & 0x82U) == 0) || ((param_2[3] & 0x40U) != 0)) {
    param_2[3] = param_2[3] | 0x20;
    uVar4 = 0xffffffff;
  }
  else {
    if ((param_2[3] & 1U) != 0) {
      param_2[1] = 0;
      if ((param_2[3] & 0x10U) == 0) {
        param_2[3] = param_2[3] | 0x20;
        return 0xffffffff;
      }
      *param_2 = param_2[2];
      param_2[3] = param_2[3] & 0xfffffffe;
    }
    param_2[3] = param_2[3] | 2;
    param_2[3] = param_2[3] & 0xffffffef;
    param_2[1] = 0;
    local_10 = 0;
    if (((param_2[3] & 0x10cU) == 0) &&
       (((param_2 != (int *)&DAT_6f639b30 && (param_2 != (int *)&DAT_6f639b50)) ||
        (iVar3 = __isatty(uVar4), iVar3 == 0)))) {
      FUN_6f62c230(piVar2);
    }
    if ((piVar2[3] & 0x108U) == 0) {
      local_8 = 1;
      local_10 = FUN_6f62bf20(uVar4,(char *)&param_1,1);
    }
    else {
      if ((*piVar2 - piVar2[2] < 0) &&
         (iVar3 = FUN_6f625320(2,0x6f637338,0xa0,0,
                               (byte *)
                               "(\"inconsistent IOB fields\", stream->_ptr - stream->_base >= 0)"),
         iVar3 == 1)) {
        pcVar1 = (code *)swi(3);
        uVar4 = (*pcVar1)();
        return uVar4;
      }
      local_8 = *piVar2 - piVar2[2];
      *piVar2 = piVar2[2] + 1;
      piVar2[1] = piVar2[6] + -1;
      if ((int)local_8 < 1) {
        if (uVar4 == 0xffffffff) {
          local_18 = &DAT_6f6396f0;
        }
        else {
          local_18 = (undefined *)((&DAT_6f63e2e0)[(int)uVar4 >> 5] + (uVar4 & 0x1f) * 0x24);
        }
        if ((local_18[4] & 0x20) != 0) {
          FUN_6f62bdd0(uVar4,0,2);
        }
      }
      else {
        local_10 = FUN_6f62bf20(uVar4,(char *)piVar2[2],local_8);
      }
      *(undefined1 *)piVar2[2] = (undefined1)param_1;
    }
    if (local_10 == local_8) {
      uVar4 = param_1 & 0xff;
    }
    else {
      piVar2[3] = piVar2[3] | 0x20;
      uVar4 = 0xffffffff;
    }
  }
  return uVar4;
}



// Function: FUN_6f625d10 at 6f625d10

int __cdecl FUN_6f625d10(int *param_1,byte *param_2,undefined4 *param_3)

{
  byte bVar1;
  short sVar2;
  code *pcVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined4 uVar6;
  uint uVar7;
  size_t sVar8;
  int iVar9;
  short *psVar10;
  bool bVar11;
  undefined8 uVar12;
  int local_2a8;
  uint local_294;
  CHAR local_28c [4];
  size_t local_288;
  short *local_284;
  int local_280;
  undefined8 local_27c;
  int local_274;
  undefined8 local_270;
  undefined4 local_268;
  undefined4 local_264;
  int *local_260;
  int local_25c;
  short *local_258;
  short *local_254;
  short *local_250;
  undefined2 local_24c;
  int local_248;
  char local_244;
  char local_243;
  int local_240;
  uint local_23c;
  int local_238;
  int local_234;
  int local_230;
  short local_22c [255];
  undefined2 uStack_2d;
  undefined3 uStack_2b;
  size_t local_28;
  short *local_24;
  int local_20;
  int local_1c;
  undefined2 local_18;
  int local_14;
  uint local_10;
  undefined4 local_c;
  uint local_8;
  
  local_28 = 0;
  local_230 = 0;
  local_1c = 0;
  pbVar5 = param_2;
  do {
    param_2 = pbVar5;
    bVar1 = *param_2;
    stack0xffffffd4 = CONCAT31(uStack_2b,bVar1);
    pbVar5 = param_2 + 1;
    if ((bVar1 == 0) || (local_230 < 0)) {
      return local_230;
    }
    if (((char)bVar1 < ' ') || ('x' < (char)bVar1)) {
      local_294 = 0;
    }
    else {
      local_294 = (int)"(\"inconsistent IOB fields\", stream->_ptr - stream->_base >= 0)"
                       [(char)bVar1 + 0x38] & 0xf;
    }
    local_10 = local_294;
    local_1c = (int)(char)(&DAT_6f637350)[local_294 * 8 + local_1c] >> 4;
    switch(local_1c) {
    case 0:
switchD_6f625dc9_caseD_0:
      local_20 = 0;
      pbVar4 = pbVar5;
      if ((*(ushort *)(PTR_DAT_6f639900 + (uint)bVar1 * 2) & 0x8000) != 0) {
        FUN_6f626a40((int)(char)bVar1,param_1,&local_230);
        stack0xffffffd4 = CONCAT31(uStack_2b,*pbVar5);
        pbVar4 = param_2 + 2;
        if ((*pbVar5 == 0) &&
           (iVar9 = FUN_6f625320(2,0x6f6373c4,0x186,0,(byte *)"ch != _T(\'\\0\')"), iVar9 == 1)) {
          pcVar3 = (code *)swi(3);
          iVar9 = (*pcVar3)();
          return iVar9;
        }
      }
      param_2 = pbVar4;
      FUN_6f626a40((int)uStack_2d._1_1_,param_1,&local_230);
      pbVar5 = param_2;
      break;
    case 1:
      local_c = 0;
      local_240 = 0;
      local_248 = 0;
      local_14 = 0;
      local_8 = 0;
      local_238 = -1;
      local_20 = 0;
      break;
    case 2:
      switch(bVar1) {
      case 0x20:
        local_8 = local_8 | 2;
        break;
      case 0x23:
        local_8 = local_8 | 0x80;
        break;
      case 0x2b:
        local_8 = local_8 | 1;
        break;
      case 0x2d:
        local_8 = local_8 | 4;
        break;
      case 0x30:
        local_8 = local_8 | 8;
      }
      break;
    case 3:
      if (bVar1 == 0x2a) {
        local_248 = FUN_6f626b50((int *)&param_3);
        if (local_248 < 0) {
          local_8 = local_8 | 4;
          local_248 = -local_248;
        }
      }
      else {
        local_248 = local_248 * 10 + -0x30 + (int)(char)bVar1;
      }
      break;
    case 4:
      local_238 = 0;
      break;
    case 5:
      if (bVar1 == 0x2a) {
        local_238 = FUN_6f626b50((int *)&param_3);
        if (local_238 < 0) {
          local_238 = -1;
        }
      }
      else {
        local_238 = local_238 * 10 + -0x30 + (int)(char)bVar1;
      }
      break;
    case 6:
      switch(bVar1) {
      case 0x49:
        if ((*pbVar5 != 0x36) || (param_2[2] != 0x34)) {
          local_1c = 0;
          goto switchD_6f625dc9_caseD_0;
        }
        local_8 = local_8 | 0x8000;
        pbVar5 = param_2 + 3;
        break;
      case 0x68:
        local_8 = local_8 | 0x20;
        break;
      case 0x6c:
        local_8 = local_8 | 0x10;
        break;
      case 0x77:
        local_8 = local_8 | 0x800;
      }
      param_2 = pbVar5;
      pbVar5 = param_2;
      break;
    case 7:
      psVar10 = local_24;
      switch(bVar1) {
      case 0x43:
        if ((local_8 & 0x830) == 0) {
          local_8 = local_8 | 0x800;
        }
      case 99:
        if ((local_8 & 0x810) == 0) {
          uVar6 = FUN_6f626b50((int *)&param_3);
          local_24c._0_1_ = (undefined1)uVar6;
          local_22c[0]._0_1_ = (undefined1)local_24c;
          local_28 = 1;
          local_24c = (short)uVar6;
        }
        else {
          local_18 = FUN_6f626b90((int *)&param_3);
          local_28 = FUN_6f62c490((LPSTR)local_22c,local_18);
          if ((int)local_28 < 0) {
            local_240 = 1;
          }
        }
        psVar10 = local_22c;
        break;
      case 0x45:
      case 0x47:
        local_c = 1;
        stack0xffffffd4 = CONCAT31(uStack_2b,bVar1 + 0x20);
      case 0x65:
      case 0x66:
      case 0x67:
        local_8 = local_8 | 0x40;
        local_24 = local_22c;
        if (local_238 < 0) {
          local_238 = 6;
        }
        else if ((local_238 == 0) && (uStack_2d._1_1_ == 'g')) {
          local_238 = 1;
        }
        local_268 = *param_3;
        local_264 = param_3[1];
        param_3 = param_3 + 2;
        (*(code *)PTR___fptrap_6f6398d8)(&local_268,local_24,(int)uStack_2d._1_1_,local_238,local_c)
        ;
        if (((local_8 & 0x80) != 0) && (local_238 == 0)) {
          (*(code *)PTR___fptrap_6f6398e4)(local_24);
        }
        if ((uStack_2d._1_1_ == 'g') && ((local_8 & 0x80) == 0)) {
          (*(code *)PTR___fptrap_6f6398dc)(local_24);
        }
        if ((char)*local_24 == '-') {
          local_8 = local_8 | 0x100;
          local_24 = (short *)((int)local_24 + 1);
        }
        local_28 = _strlen((char *)local_24);
        psVar10 = local_24;
        break;
      case 0x53:
        if ((local_8 & 0x830) == 0) {
          local_8 = local_8 | 0x800;
        }
      case 0x73:
        if (local_238 == -1) {
          local_2a8 = 0x7fffffff;
        }
        else {
          local_2a8 = local_238;
        }
        local_25c = local_2a8;
        local_24 = (short *)FUN_6f626b50((int *)&param_3);
        if ((local_8 & 0x810) == 0) {
          if (local_24 == (short *)0x0) {
            local_24 = (short *)PTR_DAT_6f6396e0;
          }
          for (local_254 = local_24; (local_25c != 0 && ((char)*local_254 != '\0'));
              local_254 = (short *)((int)local_254 + 1)) {
            local_25c = local_25c + -1;
          }
          local_28 = (int)local_254 - (int)local_24;
          local_25c = local_25c + -1;
          psVar10 = local_24;
        }
        else {
          if (local_24 == (short *)0x0) {
            local_24 = (short *)PTR_DAT_6f6396e4;
          }
          local_20 = 1;
          for (local_258 = local_24; (local_25c != 0 && (*local_258 != 0));
              local_258 = local_258 + 1) {
            local_25c = local_25c + -1;
          }
          local_28 = (int)local_258 - (int)local_24 >> 1;
          local_25c = local_25c + -1;
          psVar10 = local_24;
        }
        break;
      case 0x5a:
        local_250 = (short *)FUN_6f626b50((int *)&param_3);
        if ((local_250 == (short *)0x0) || (*(int *)(local_250 + 2) == 0)) {
          local_24 = (short *)PTR_DAT_6f6396e0;
          local_28 = _strlen(PTR_DAT_6f6396e0);
          psVar10 = local_24;
        }
        else if ((local_8 & 0x800) == 0) {
          local_20 = 0;
          local_28 = (size_t)*local_250;
          psVar10 = *(short **)(local_250 + 2);
        }
        else {
          local_28 = (uint)(int)*local_250 >> 1;
          local_20 = 1;
          psVar10 = *(short **)(local_250 + 2);
        }
        break;
      case 100:
      case 0x69:
        local_8 = local_8 | 0x40;
        local_23c = 10;
        goto LAB_6f6264d5;
      case 0x6e:
        local_260 = (int *)FUN_6f626b50((int *)&param_3);
        if ((local_8 & 0x20) == 0) {
          *local_260 = local_230;
        }
        else {
          *(undefined2 *)local_260 = (undefined2)local_230;
        }
        local_240 = 1;
        psVar10 = local_24;
        break;
      case 0x6f:
        local_23c = 8;
        if ((local_8 & 0x80) != 0) {
          local_8 = local_8 | 0x200;
        }
        goto LAB_6f6264d5;
      case 0x70:
        local_238 = 8;
      case 0x58:
        local_234 = 7;
        goto LAB_6f62647f;
      case 0x75:
        local_23c = 10;
        goto LAB_6f6264d5;
      case 0x78:
        local_234 = 0x27;
LAB_6f62647f:
        local_23c = 0x10;
        if ((local_8 & 0x80) != 0) {
          local_244 = '0';
          local_243 = (char)local_234 + 'Q';
          local_14 = 2;
        }
LAB_6f6264d5:
        if ((local_8 & 0x8000) == 0) {
          if ((local_8 & 0x20) == 0) {
            if ((local_8 & 0x40) == 0) {
              uVar7 = FUN_6f626b50((int *)&param_3);
              local_27c = (ulonglong)uVar7;
            }
            else {
              iVar9 = FUN_6f626b50((int *)&param_3);
              local_27c = (ulonglong)iVar9;
            }
          }
          else if ((local_8 & 0x40) == 0) {
            uVar7 = FUN_6f626b50((int *)&param_3);
            local_27c = (ulonglong)(uVar7 & 0xffff);
          }
          else {
            uVar6 = FUN_6f626b50((int *)&param_3);
            local_27c = (ulonglong)(int)(short)uVar6;
          }
        }
        else {
          local_27c = FUN_6f626b70((int *)&param_3);
        }
        if ((((local_8 & 0x40) == 0) || (0 < local_27c._4_4_)) || (-1 < (longlong)local_27c)) {
          local_270 = local_27c;
        }
        else {
          local_270 = CONCAT44(-(local_27c._4_4_ + (uint)((int)local_27c != 0)),-(int)local_27c);
          local_8 = local_8 | 0x100;
        }
        if ((local_8 & 0x8000) == 0) {
          local_270 = local_270 & 0xffffffff;
        }
        if (local_238 < 0) {
          local_238 = 1;
        }
        else {
          local_8 = local_8 & 0xfffffff7;
        }
        if ((uint)local_270 == 0 && local_270._4_4_ == 0) {
          local_14 = 0;
        }
        local_24 = &uStack_2d;
        while( true ) {
          iVar9 = local_238 + -1;
          if ((local_238 < 1) && ((uint)local_270 == 0 && local_270._4_4_ == 0)) break;
          local_238 = iVar9;
          uVar12 = __aullrem((uint)local_270,local_270._4_4_,local_23c,(int)local_23c >> 0x1f);
          local_274 = (int)uVar12 + 0x30;
          local_270 = __aulldiv((uint)local_270,local_270._4_4_,local_23c,(int)local_23c >> 0x1f);
          if (0x39 < local_274) {
            local_274 = local_274 + local_234;
          }
          *(char *)local_24 = (char)local_274;
          local_24 = (short *)((int)local_24 + -1);
        }
        local_28 = (int)&uStack_2d - (int)local_24;
        psVar10 = (short *)((int)local_24 + 1);
        local_238 = iVar9;
        if (((local_8 & 0x200) != 0) && ((*(char *)psVar10 != '0' || (local_28 == 0)))) {
          *(char *)local_24 = '0';
          local_28 = local_28 + 1;
          psVar10 = local_24;
        }
      }
      local_24 = psVar10;
      if (local_240 == 0) {
        if ((local_8 & 0x40) != 0) {
          if ((local_8 & 0x100) == 0) {
            if ((local_8 & 1) == 0) {
              if ((local_8 & 2) != 0) {
                local_244 = ' ';
                local_14 = 1;
              }
            }
            else {
              local_244 = '+';
              local_14 = 1;
            }
          }
          else {
            local_244 = '-';
            local_14 = 1;
          }
        }
        local_280 = (local_248 - local_28) - local_14;
        if ((local_8 & 0xc) == 0) {
          FUN_6f626ac0(0x20,local_280,param_1,&local_230);
        }
        FUN_6f626b00(&local_244,local_14,param_1,&local_230);
        if (((local_8 & 8) != 0) && ((local_8 & 4) == 0)) {
          FUN_6f626ac0(0x30,local_280,param_1,&local_230);
        }
        if ((local_20 == 0) || ((int)local_28 < 1)) {
          FUN_6f626b00((char *)local_24,local_28,param_1,&local_230);
        }
        else {
          local_284 = local_24;
          local_288 = local_28;
          while (sVar8 = local_288 - 1, bVar11 = local_288 != 0, local_288 = sVar8, bVar11) {
            sVar2 = *local_284;
            local_284 = local_284 + 1;
            iVar9 = FUN_6f62c490(local_28c,sVar2);
            if (iVar9 < 1) break;
            FUN_6f626b00(local_28c,iVar9,param_1,&local_230);
          }
        }
        if ((local_8 & 4) != 0) {
          FUN_6f626ac0(0x20,local_280,param_1,&local_230);
        }
      }
    }
  } while( true );
}



// Function: FUN_6f626a40 at 6f626a40

void __cdecl FUN_6f626a40(uint param_1,int *param_2,int *param_3)

{
  uint local_8;
  
  param_2[1] = param_2[1] + -1;
  if (param_2[1] < 0) {
    local_8 = FUN_6f625a90(param_1,param_2);
  }
  else {
    *(undefined1 *)*param_2 = (undefined1)param_1;
    local_8 = param_1 & 0xff;
    *param_2 = *param_2 + 1;
  }
  if (local_8 == 0xffffffff) {
    *param_3 = -1;
  }
  else {
    *param_3 = *param_3 + 1;
  }
  return;
}



// Function: FUN_6f626ac0 at 6f626ac0

void __cdecl FUN_6f626ac0(uint param_1,int param_2,int *param_3,int *param_4)

{
  do {
    if (param_2 < 1) {
      return;
    }
    FUN_6f626a40(param_1,param_3,param_4);
    param_2 = param_2 + -1;
  } while (*param_4 != -1);
  return;
}



// Function: FUN_6f626b00 at 6f626b00

void __cdecl FUN_6f626b00(char *param_1,int param_2,int *param_3,int *param_4)

{
  char cVar1;
  
  do {
    if (param_2 < 1) {
      return;
    }
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    FUN_6f626a40((int)cVar1,param_3,param_4);
    param_2 = param_2 + -1;
  } while (*param_4 != -1);
  return;
}



// Function: FUN_6f626b50 at 6f626b50

undefined4 __cdecl FUN_6f626b50(int *param_1)

{
  *param_1 = *param_1 + 4;
  return *(undefined4 *)(*param_1 + -4);
}



// Function: FUN_6f626b70 at 6f626b70

undefined8 __cdecl FUN_6f626b70(int *param_1)

{
  *param_1 = *param_1 + 8;
  return *(undefined8 *)(*param_1 + -8);
}



// Function: FUN_6f626b90 at 6f626b90

undefined2 __cdecl FUN_6f626b90(int *param_1)

{
  *param_1 = *param_1 + 4;
  return *(undefined2 *)(*param_1 + -4);
}



// Function: FUN_6f626bb0 at 6f626bb0

void FUN_6f626bb0(void)

{
  if (DAT_6f63e3ec != (code *)0x0) {
    (*DAT_6f63e3ec)();
  }
  __initterm((int *)&DAT_6f639008,(int *)&DAT_6f639010);
  __initterm((int *)&DAT_6f639000,(int *)&DAT_6f639004);
  return;
}



// Function: FUN_6f626bf0 at 6f626bf0

void __cdecl FUN_6f626bf0(UINT param_1)

{
  FUN_6f626c70(param_1,0,0);
  return;
}



// Function: __exit at 6f626c10

/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 2003 Debug */

void __cdecl __exit(int _Code)

{
  FUN_6f626c70(_Code,1,0);
  return;
}



// Function: FUN_6f626c30 at 6f626c30

void FUN_6f626c30(void)

{
  FUN_6f626c70(0,0,1);
  return;
}



// Function: FUN_6f626c50 at 6f626c50

void FUN_6f626c50(void)

{
  FUN_6f626c70(0,1,1);
  return;
}



// Function: FUN_6f626c70 at 6f626c70

void __cdecl FUN_6f626c70(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  uint uVar1;
  UINT uExitCode;
  int *local_8;
  
  FUN_6f626d60();
  if (DAT_6f63ce60 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  DAT_6f63ce5c = 1;
  DAT_6f63ce58 = (undefined1)param_3;
  if (param_2 == 0) {
    if (DAT_6f63e3e8 != (int *)0x0) {
      local_8 = DAT_6f63e3e4;
      while (local_8 = local_8 + -1, DAT_6f63e3e8 <= local_8) {
        if (*local_8 != 0) {
          (*(code *)*local_8)();
        }
      }
    }
    __initterm((int *)&DAT_6f639014,(int *)&DAT_6f63901c);
  }
  __initterm((int *)&DAT_6f639020,(int *)&DAT_6f639024);
  if ((DAT_6f63ce64 == 0) && (uVar1 = FUN_6f628940(-1), (uVar1 & 0x20) != 0)) {
    DAT_6f63ce64 = 1;
    FUN_6f629250();
  }
  if (param_3 == 0) {
    DAT_6f63ce60 = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(param_1);
  }
  FUN_6f626d70();
  return;
}



// Function: FUN_6f626d60 at 6f626d60

void FUN_6f626d60(void)

{
  FUN_6f62c780(0xd);
  return;
}



// Function: FUN_6f626d70 at 6f626d70

void FUN_6f626d70(void)

{
  FUN_6f62c820(0xd);
  return;
}



// Function: __initterm at 6f626d80

/* Library Function - Single Match
    __initterm
   
   Library: Visual Studio 2003 Debug */

void __cdecl __initterm(int *param_1,int *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if (*param_1 != 0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



// Function: FUN_6f626db0 at 6f626db0

undefined4 FUN_6f626db0(void)

{
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  FUN_6f62c6a0();
  DAT_6f6396e8 = TlsAlloc();
  if (((DAT_6f6396e8 != 0xffffffff) &&
      (lpTlsValue = (DWORD *)__calloc_dbg(1,0x74,2,"tidtable.c",0x61), lpTlsValue != (DWORD *)0x0))
     && (BVar1 = TlsSetValue(DAT_6f6396e8,lpTlsValue), BVar1 != 0)) {
    FUN_6f626e70((int)lpTlsValue);
    DVar2 = GetCurrentThreadId();
    *lpTlsValue = DVar2;
    lpTlsValue[1] = 0xffffffff;
    return 1;
  }
  return 0;
}



// Function: FUN_6f626e40 at 6f626e40

void FUN_6f626e40(void)

{
  FUN_6f62c6e0();
  if (DAT_6f6396e8 != 0xffffffff) {
    TlsFree(DAT_6f6396e8);
    DAT_6f6396e8 = 0xffffffff;
  }
  return;
}



// Function: FUN_6f626e70 at 6f626e70

void __cdecl FUN_6f626e70(int param_1)

{
  *(undefined **)(param_1 + 0x50) = &DAT_6f639e50;
  *(undefined4 *)(param_1 + 0x14) = 1;
  return;
}



// Function: FUN_6f626e90 at 6f626e90

DWORD * FUN_6f626e90(void)

{
  DWORD dwErrCode;
  BOOL BVar1;
  DWORD DVar2;
  DWORD *local_8;
  
  dwErrCode = GetLastError();
  local_8 = (DWORD *)TlsGetValue(DAT_6f6396e8);
  if (local_8 == (DWORD *)0x0) {
    local_8 = (DWORD *)__calloc_dbg(1,0x74,2,"tidtable.c",0xe7);
    if (local_8 != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_6f6396e8,local_8);
      if (BVar1 != 0) {
        FUN_6f626e70((int)local_8);
        DVar2 = GetCurrentThreadId();
        *local_8 = DVar2;
        local_8[1] = 0xffffffff;
        goto LAB_6f626f17;
      }
    }
    __amsg_exit(0x10);
  }
LAB_6f626f17:
  SetLastError(dwErrCode);
  return local_8;
}



// Function: FUN_6f626f30 at 6f626f30

void __cdecl FUN_6f626f30(LPVOID param_1)

{
  if (DAT_6f6396e8 != 0xffffffff) {
    if (param_1 == (LPVOID)0x0) {
      param_1 = TlsGetValue(DAT_6f6396e8);
    }
    if (param_1 != (LPVOID)0x0) {
      if (*(int *)((int)param_1 + 0x24) != 0) {
        FUN_6f627ec0(*(void **)((int)param_1 + 0x24),2);
      }
      if (*(int *)((int)param_1 + 0x28) != 0) {
        FUN_6f627ec0(*(void **)((int)param_1 + 0x28),2);
      }
      if (*(int *)((int)param_1 + 0x30) != 0) {
        FUN_6f627ec0(*(void **)((int)param_1 + 0x30),2);
      }
      if (*(int *)((int)param_1 + 0x38) != 0) {
        FUN_6f627ec0(*(void **)((int)param_1 + 0x38),2);
      }
      if (*(int *)((int)param_1 + 0x40) != 0) {
        FUN_6f627ec0(*(void **)((int)param_1 + 0x40),2);
      }
      if (*(int *)((int)param_1 + 0x44) != 0) {
        FUN_6f627ec0(*(void **)((int)param_1 + 0x44),2);
      }
      FUN_6f627ec0(param_1,2);
    }
    TlsSetValue(DAT_6f6396e8,(LPVOID)0x0);
  }
  return;
}



// Function: FUN_6f627020 at 6f627020

void FUN_6f627020(void)

{
  GetCurrentThreadId();
  return;
}



// Function: FUN_6f627030 at 6f627030

void FUN_6f627030(void)

{
  GetCurrentThread();
  return;
}



// Function: FUN_6f627040 at 6f627040

void FUN_6f627040(void)

{
  DWORD DVar1;
  HANDLE hFile;
  undefined4 *puVar2;
  int *piVar3;
  DWORD local_70;
  UINT local_6c;
  UINT local_68;
  byte *local_64;
  int local_60;
  uint local_5c;
  undefined4 *local_54;
  _STARTUPINFOA local_4c;
  byte *local_8;
  
  local_54 = (undefined4 *)FUN_6f627430((void *)0x480,2,0x6f6373ec,0x81);
  if (local_54 == (undefined4 *)0x0) {
    __amsg_exit(0x1b);
  }
  DAT_6f63e3e0 = 0x20;
  DAT_6f63e2e0 = local_54;
  for (; local_54 < DAT_6f63e2e0 + 0x120; local_54 = local_54 + 9) {
    *(undefined1 *)(local_54 + 1) = 0;
    *local_54 = 0xffffffff;
    *(undefined1 *)((int)local_54 + 5) = 10;
    local_54[2] = 0;
  }
  GetStartupInfoA(&local_4c);
  if ((local_4c.cbReserved2 != 0) &&
     (CONCAT22(local_4c.lpReserved2._2_2_,local_4c.lpReserved2._0_2_) != 0)) {
    local_6c = *(UINT *)CONCAT22(local_4c.lpReserved2._2_2_,local_4c.lpReserved2._0_2_);
    local_8 = (byte *)(CONCAT22(local_4c.lpReserved2._2_2_,local_4c.lpReserved2._0_2_) + 4);
    local_64 = local_8 + local_6c;
    if (0x7ff < (int)local_6c) {
      local_6c = 0x800;
    }
    local_68 = local_6c;
    local_60 = 1;
    while ((int)DAT_6f63e3e0 < (int)local_6c) {
      local_54 = (undefined4 *)FUN_6f627430((void *)0x480,2,0x6f6373ec,0xb6);
      if (local_54 == (undefined4 *)0x0) {
        local_68 = DAT_6f63e3e0;
        break;
      }
      (&DAT_6f63e2e0)[local_60] = local_54;
      DAT_6f63e3e0 = DAT_6f63e3e0 + 0x20;
      for (; local_54 < (undefined4 *)((int)(&DAT_6f63e2e0)[local_60] + 0x480);
          local_54 = local_54 + 9) {
        *(undefined1 *)(local_54 + 1) = 0;
        *local_54 = 0xffffffff;
        *(undefined1 *)((int)local_54 + 5) = 10;
        local_54[2] = 0;
      }
      local_60 = local_60 + 1;
    }
    for (local_5c = 0; (int)local_5c < (int)local_68; local_5c = local_5c + 1) {
      if (((*(int *)local_64 != -1) && ((*local_8 & 1) != 0)) &&
         (((*local_8 & 8) != 0 || (DVar1 = GetFileType(*(HANDLE *)local_64), DVar1 != 0)))) {
        puVar2 = (undefined4 *)((int)(&DAT_6f63e2e0)[(int)local_5c >> 5] + (local_5c & 0x1f) * 0x24)
        ;
        *puVar2 = *(undefined4 *)local_64;
        *(byte *)(puVar2 + 1) = *local_8;
      }
      local_8 = local_8 + 1;
      local_64 = local_64 + 4;
    }
  }
  for (local_5c = 0; (int)local_5c < 3; local_5c = local_5c + 1) {
    piVar3 = DAT_6f63e2e0 + local_5c * 9;
    if (*piVar3 == -1) {
      *(undefined1 *)(piVar3 + 1) = 0x81;
      if (local_5c == 0) {
        local_70 = 0xfffffff6;
      }
      else {
        local_70 = 0xfffffff5 - (local_5c != 1);
      }
      hFile = GetStdHandle(local_70);
      if ((hFile == (HANDLE)0xffffffff) || (DVar1 = GetFileType(hFile), DVar1 == 0)) {
        *(byte *)(piVar3 + 1) = *(byte *)(piVar3 + 1) | 0x40;
      }
      else {
        *piVar3 = (int)hFile;
        if ((DVar1 & 0xff) == 2) {
          *(byte *)(piVar3 + 1) = *(byte *)(piVar3 + 1) | 0x40;
        }
        else if ((DVar1 & 0xff) == 3) {
          *(byte *)(piVar3 + 1) = *(byte *)(piVar3 + 1) | 8;
        }
      }
    }
    else {
      *(byte *)(piVar3 + 1) = *(byte *)(piVar3 + 1) | 0x80;
    }
  }
  SetHandleCount(DAT_6f63e3e0);
  return;
}



// Function: __ioterm at 6f627370

/* Library Function - Single Match
    __ioterm
   
   Library: Visual Studio */

void __cdecl __ioterm(void)

{
  int local_c;
  uint local_8;
  
  for (local_c = 0; local_c < 0x40; local_c = local_c + 1) {
    if ((&DAT_6f63e2e0)[local_c] != 0) {
      for (local_8 = (&DAT_6f63e2e0)[local_c]; local_8 < (&DAT_6f63e2e0)[local_c] + 0x480;
          local_8 = local_8 + 0x24) {
        if (*(int *)(local_8 + 8) != 0) {
          DeleteCriticalSection((LPCRITICAL_SECTION)(local_8 + 0xc));
        }
      }
      FUN_6f627ec0((void *)(&DAT_6f63e2e0)[local_c],2);
      (&DAT_6f63e2e0)[local_c] = 0;
    }
  }
  return;
}



// Function: FUN_6f627410 at 6f627410

void __cdecl FUN_6f627410(void *param_1)

{
  FUN_6f627480(param_1,(uint)param_1,DAT_6f63d138,1,0,0);
  return;
}



// Function: FUN_6f627430 at 6f627430

void __cdecl FUN_6f627430(void *param_1,uint param_2,int param_3,int param_4)

{
  FUN_6f627480(param_1,(uint)param_1,DAT_6f63d138,param_2,param_3,param_4);
  return;
}



// Function: FUN_6f627460 at 6f627460

void __cdecl FUN_6f627460(void *param_1,int param_2)

{
  FUN_6f627480(param_1,(uint)param_1,param_2,1,0,0);
  return;
}



// Function: FUN_6f627480 at 6f627480

int * __thiscall
FUN_6f627480(void *this,uint param_1,int param_2,uint param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  
  while( true ) {
    FUN_6f62c780(9);
    piVar1 = FUN_6f627500(param_1,param_3,param_4,param_5);
    FUN_6f62c820(9);
    if (piVar1 != (int *)0x0) {
      return piVar1;
    }
    if (param_2 == 0) break;
    iVar2 = __callnewh(param_1);
    if (iVar2 == 0) {
      return (int *)0x0;
    }
  }
  return (int *)0x0;
}



// Function: FUN_6f6274e0 at 6f6274e0

void __cdecl FUN_6f6274e0(uint param_1)

{
  FUN_6f627500(param_1,1,0,0);
  return;
}



// Function: FUN_6f627500 at 6f627500

int * __cdecl FUN_6f627500(uint param_1,uint param_2,int param_3,int param_4)

{
  code *pcVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  bVar2 = false;
  if ((((DAT_6f639718 & 4) != 0) && (iVar4 = FUN_6f6285d0(), iVar4 == 0)) &&
     (iVar4 = FUN_6f625320(2,0x6f6374d4,0x141,0,(byte *)"_CrtCheckMemory()"), iVar4 == 1)) {
    pcVar1 = (code *)swi(3);
    piVar5 = (int *)(*pcVar1)();
    return piVar5;
  }
  iVar4 = DAT_6f63971c;
  if (DAT_6f63971c == DAT_6f639720) {
    pcVar1 = (code *)swi(3);
    piVar5 = (int *)(*pcVar1)();
    return piVar5;
  }
  iVar6 = (*(code *)PTR_FUN_6f639ed8)(1,0,param_1,param_2,DAT_6f63971c,param_3,param_4);
  if (iVar6 == 0) {
    if (param_3 == 0) {
      iVar4 = FUN_6f625320(0,0,0,0,&DAT_6f637474);
      if (iVar4 == 1) {
        pcVar1 = (code *)swi(3);
        piVar5 = (int *)(*pcVar1)();
        return piVar5;
      }
    }
    else {
      iVar4 = FUN_6f625320(0,0,0,0,(byte *)"Client hook allocation failure at file %hs line %d.\n");
      if (iVar4 == 1) {
        pcVar1 = (code *)swi(3);
        piVar5 = (int *)(*pcVar1)();
        return piVar5;
      }
    }
    piVar5 = (int *)0x0;
  }
  else {
    if (((param_2 & 0xffff) != 2) && ((DAT_6f639718 & 1) == 0)) {
      bVar2 = true;
    }
    if ((param_1 < 0xffffffe1) && (param_1 + 0x24 < 0xffffffe1)) {
      if (((((param_2 & 0xffff) != 4) && (param_2 != 1)) && ((param_2 & 0xffff) != 2)) &&
         ((param_2 != 3 && (iVar6 = FUN_6f625320(1,0,0,0,&DAT_6f637474), iVar6 == 1)))) {
        pcVar1 = (code *)swi(3);
        piVar5 = (int *)(*pcVar1)();
        return piVar5;
      }
      piVar5 = FUN_6f62cc70((void *)(param_1 + 0x24),(int)(param_1 + 0x24));
      if (piVar5 == (int *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        DAT_6f63971c = DAT_6f63971c + 1;
        if (bVar2) {
          *piVar5 = 0;
          piVar5[1] = 0;
          piVar5[2] = 0;
          piVar5[3] = -0x1234544;
          piVar5[4] = param_1;
          piVar5[5] = 3;
          piVar5[6] = 0;
        }
        else {
          DAT_6f63ce6c = DAT_6f63ce6c + param_1;
          DAT_6f63ce74 = DAT_6f63ce74 + param_1;
          if (DAT_6f63ce78 < DAT_6f63ce74) {
            DAT_6f63ce78 = DAT_6f63ce74;
          }
          piVar3 = piVar5;
          if (DAT_6f63ce70 != (int *)0x0) {
            DAT_6f63ce70[1] = (int)piVar5;
            piVar3 = DAT_6f63ce68;
          }
          DAT_6f63ce68 = piVar3;
          *piVar5 = (int)DAT_6f63ce70;
          piVar5[1] = 0;
          piVar5[2] = param_3;
          piVar5[3] = param_4;
          piVar5[4] = param_1;
          piVar5[5] = param_2;
          piVar5[6] = iVar4;
          DAT_6f63ce70 = piVar5;
        }
        _memset(piVar5 + 7,(uint)DAT_6f639724,4);
        _memset((void *)((int)piVar5 + param_1 + 0x20),(uint)DAT_6f639724,4);
        _memset(piVar5 + 8,(uint)DAT_6f63972c,param_1);
        piVar5 = piVar5 + 8;
      }
    }
    else {
      iVar4 = FUN_6f625320(1,0,0,0,(byte *)"Invalid allocation size: %u bytes.\n");
      if (iVar4 == 1) {
        pcVar1 = (code *)swi(3);
        piVar5 = (int *)(*pcVar1)();
        return piVar5;
      }
      piVar5 = (int *)0x0;
    }
  }
  return piVar5;
}



// Function: FUN_6f627820 at 6f627820

void __cdecl FUN_6f627820(int param_1,int param_2)

{
  __calloc_dbg(param_1,param_2,1,0,0);
  return;
}



// Function: __calloc_dbg at 6f627840

/* Library Function - Single Match
    __calloc_dbg
   
   Library: Visual Studio 2003 Debug */

undefined1 * __cdecl __calloc_dbg(int param_1,int param_2,uint param_3,int param_4,int param_5)

{
  undefined1 *puVar1;
  undefined1 *local_10;
  
  puVar1 = (undefined1 *)FUN_6f627430((void *)(param_2 * param_1),param_3,param_4,param_5);
  if (puVar1 != (undefined1 *)0x0) {
    for (local_10 = puVar1; local_10 < puVar1 + param_2 * param_1; local_10 = local_10 + 1) {
      *local_10 = 0;
    }
  }
  return puVar1;
}



// Function: FUN_6f6278a0 at 6f6278a0

void __cdecl FUN_6f6278a0(void *param_1,void *param_2)

{
  FUN_6f6278c0(param_1,param_2,1,0,0);
  return;
}



// Function: FUN_6f6278c0 at 6f6278c0

int * __cdecl FUN_6f6278c0(void *param_1,void *param_2,uint param_3,int param_4,int param_5)

{
  int *piVar1;
  
  FUN_6f62c780(9);
  piVar1 = FUN_6f627900(param_1,param_2,param_3,param_4,param_5,1);
  FUN_6f62c820(9);
  return piVar1;
}



// Function: FUN_6f627900 at 6f627900

int * __cdecl
FUN_6f627900(void *param_1,void *param_2,uint param_3,int param_4,int param_5,int param_6)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  BOOL BVar6;
  bool bVar7;
  int *local_10;
  
  if (param_1 == (void *)0x0) {
    piVar2 = (int *)FUN_6f627430(param_2,param_3,param_4,param_5);
  }
  else if ((param_6 == 0) || (param_2 != (void *)0x0)) {
    if (((DAT_6f639718 & 4) != 0) &&
       ((iVar3 = FUN_6f6285d0(), iVar3 == 0 &&
        (iVar3 = FUN_6f625320(2,0x6f6374d4,0x239,0,(byte *)"_CrtCheckMemory()"), iVar3 == 1)))) {
      pcVar1 = (code *)swi(3);
      piVar4 = (int *)(*pcVar1)();
      return piVar4;
    }
    iVar3 = DAT_6f63971c;
    if (DAT_6f63971c == DAT_6f639720) {
      pcVar1 = (code *)swi(3);
      piVar4 = (int *)(*pcVar1)();
      return piVar4;
    }
    iVar5 = (*(code *)PTR_FUN_6f639ed8)(2,param_1,param_2,param_3,DAT_6f63971c,param_4,param_5);
    if (iVar5 == 0) {
      if (param_4 == 0) {
        iVar3 = FUN_6f625320(0,0,0,0,&DAT_6f637474);
        if (iVar3 == 1) {
          pcVar1 = (code *)swi(3);
          piVar4 = (int *)(*pcVar1)();
          return piVar4;
        }
      }
      else {
        iVar3 = FUN_6f625320(0,0,0,0,(byte *)
                                     "Client hook re-allocation failure at file %hs line %d.\n");
        if (iVar3 == 1) {
          pcVar1 = (code *)swi(3);
          piVar4 = (int *)(*pcVar1)();
          return piVar4;
        }
      }
      piVar2 = (int *)0x0;
    }
    else if (param_2 < (void *)0xffffffdc) {
      if ((((param_3 != 1) && ((param_3 & 0xffff) != 4)) && ((param_3 & 0xffff) != 2)) &&
         (iVar5 = FUN_6f625320(1,0,0,0,&DAT_6f637474), iVar5 == 1)) {
        pcVar1 = (code *)swi(3);
        piVar4 = (int *)(*pcVar1)();
        return piVar4;
      }
      BVar6 = FUN_6f628a30((int)param_1);
      if ((BVar6 == 0) &&
         (iVar5 = FUN_6f625320(2,0x6f6374d4,0x261,0,(byte *)"_CrtIsValidHeapPointer(pUserData)"),
         iVar5 == 1)) {
        pcVar1 = (code *)swi(3);
        piVar4 = (int *)(*pcVar1)();
        return piVar4;
      }
      piVar4 = (int *)((int)param_1 + -0x20);
      bVar7 = *(int *)((int)param_1 + -0xc) == 3;
      if (bVar7) {
        if (((*(int *)((int)param_1 + -0x14) != -0x1234544) || (*(int *)((int)param_1 + -8) != 0))
           && (iVar5 = FUN_6f625320(2,0x6f6374d4,0x26b,0,
                                    (byte *)
                                    "pOldBlock->nLine == IGNORE_LINE && pOldBlock->lRequest == IGNORE_REQ"
                                   ), iVar5 == 1)) {
          pcVar1 = (code *)swi(3);
          piVar4 = (int *)(*pcVar1)();
          return piVar4;
        }
      }
      else {
        if (((*(uint *)((int)param_1 + -0xc) & 0xffff) == 2) && ((param_3 & 0xffff) == 1)) {
          param_3 = 2;
        }
        if (((*(uint *)((int)param_1 + -0xc) & 0xffff) != (param_3 & 0xffff)) &&
           (iVar5 = FUN_6f625320(2,0x6f6374d4,0x272,0,
                                 (byte *)"_BLOCK_TYPE(pOldBlock->nBlockUse)==_BLOCK_TYPE(nBlockUse)"
                                ), iVar5 == 1)) {
          pcVar1 = (code *)swi(3);
          piVar4 = (int *)(*pcVar1)();
          return piVar4;
        }
      }
      if (param_6 == 0) {
        local_10 = (int *)FUN_6f62ccf0((undefined *)piVar4,(int)param_2 + 0x24);
        if (local_10 == (int *)0x0) {
          return (int *)0x0;
        }
      }
      else {
        local_10 = FUN_6f62cdb0(piVar4,(void *)((int)param_2 + 0x24));
        if (local_10 == (int *)0x0) {
          return (int *)0x0;
        }
      }
      DAT_6f63971c = DAT_6f63971c + 1;
      if (!bVar7) {
        DAT_6f63ce6c = (DAT_6f63ce6c - local_10[4]) + (int)param_2;
        DAT_6f63ce74 = (DAT_6f63ce74 - local_10[4]) + (int)param_2;
        if (DAT_6f63ce78 < DAT_6f63ce74) {
          DAT_6f63ce78 = DAT_6f63ce74;
        }
      }
      piVar2 = local_10 + 8;
      if ((void *)local_10[4] < param_2) {
        _memset((void *)((int)piVar2 + local_10[4]),(uint)DAT_6f63972c,(int)param_2 - local_10[4]);
      }
      _memset((void *)((int)piVar2 + (int)param_2),(uint)DAT_6f639724,4);
      if (!bVar7) {
        local_10[2] = param_4;
        local_10[3] = param_5;
        local_10[6] = iVar3;
      }
      local_10[4] = (int)param_2;
      if (((param_6 == 0) && (local_10 != piVar4)) &&
         (iVar3 = FUN_6f625320(2,0x6f6374d4,0x2a8,0,
                               (byte *)"fRealloc || (!fRealloc && pNewBlock == pOldBlock)"),
         iVar3 == 1)) {
        pcVar1 = (code *)swi(3);
        piVar4 = (int *)(*pcVar1)();
        return piVar4;
      }
      if ((local_10 != piVar4) && (!bVar7)) {
        if (*local_10 == 0) {
          if ((DAT_6f63ce68 != piVar4) &&
             (iVar3 = FUN_6f625320(2,0x6f6374d4,0x2b7,0,(byte *)"_pLastBlock == pOldBlock"),
             iVar3 == 1)) {
            pcVar1 = (code *)swi(3);
            piVar4 = (int *)(*pcVar1)();
            return piVar4;
          }
          DAT_6f63ce68 = (int *)local_10[1];
        }
        else {
          *(int *)(*local_10 + 4) = local_10[1];
        }
        if (local_10[1] == 0) {
          if ((DAT_6f63ce70 != piVar4) &&
             (iVar3 = FUN_6f625320(2,0x6f6374d4,0x2c2,0,(byte *)"_pFirstBlock == pOldBlock"),
             iVar3 == 1)) {
            pcVar1 = (code *)swi(3);
            piVar4 = (int *)(*pcVar1)();
            return piVar4;
          }
          DAT_6f63ce70 = (int *)*local_10;
        }
        else {
          *(int *)local_10[1] = *local_10;
        }
        if (DAT_6f63ce70 == (int *)0x0) {
          DAT_6f63ce68 = local_10;
        }
        else {
          DAT_6f63ce70[1] = (int)local_10;
        }
        *local_10 = (int)DAT_6f63ce70;
        local_10[1] = 0;
        DAT_6f63ce70 = local_10;
      }
    }
    else {
      iVar3 = FUN_6f625320(1,0,0,0,(byte *)"Allocation too large or negative: %u bytes.\n");
      if (iVar3 == 1) {
        pcVar1 = (code *)swi(3);
        piVar4 = (int *)(*pcVar1)();
        return piVar4;
      }
      piVar2 = (int *)0x0;
    }
  }
  else {
    FUN_6f627ec0(param_1,param_3);
    piVar2 = (int *)0x0;
  }
  return piVar2;
}



// Function: FUN_6f627e20 at 6f627e20

void __cdecl FUN_6f627e20(void *param_1,void *param_2)

{
  FUN_6f627e40(param_1,param_2,1,0,0);
  return;
}



// Function: FUN_6f627e40 at 6f627e40

int * __cdecl FUN_6f627e40(void *param_1,void *param_2,uint param_3,int param_4,int param_5)

{
  int *piVar1;
  
  FUN_6f62c780(9);
  piVar1 = FUN_6f627900(param_1,param_2,param_3,param_4,param_5,0);
  FUN_6f62c820(9);
  return piVar1;
}



// Function: FUN_6f627e80 at 6f627e80

void __cdecl FUN_6f627e80(void *param_1)

{
  FUN_6f627ec0(param_1,1);
  return;
}



// Function: FUN_6f627ea0 at 6f627ea0

void __cdecl FUN_6f627ea0(void *param_1)

{
  FUN_6f627ef0(param_1,1);
  return;
}



// Function: FUN_6f627ec0 at 6f627ec0

void __cdecl FUN_6f627ec0(void *param_1,int param_2)

{
  FUN_6f62c780(9);
  FUN_6f627ef0(param_1,param_2);
  FUN_6f62c820(9);
  return;
}



// Function: FUN_6f627ef0 at 6f627ef0

void __cdecl FUN_6f627ef0(void *param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  BOOL BVar3;
  int *_Dst;
  
  if ((((DAT_6f639718 & 4) != 0) && (iVar2 = FUN_6f6285d0(), iVar2 == 0)) &&
     (iVar2 = FUN_6f625320(2,0x6f6374d4,0x3e1,0,(byte *)"_CrtCheckMemory()"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if (param_1 != (void *)0x0) {
    iVar2 = (*(code *)PTR_FUN_6f639ed8)(3,param_1,0,param_2,0,0,0);
    if (iVar2 == 0) {
      iVar2 = FUN_6f625320(0,0,0,0,&DAT_6f637474);
      if (iVar2 == 1) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
    }
    else {
      BVar3 = FUN_6f628a30((int)param_1);
      if ((BVar3 == 0) &&
         (iVar2 = FUN_6f625320(2,0x6f6374d4,0x3f3,0,(byte *)"_CrtIsValidHeapPointer(pUserData)"),
         iVar2 == 1)) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _Dst = (int *)((int)param_1 + -0x20);
      if ((((*(uint *)((int)param_1 + -0xc) & 0xffff) != 4) && (*(int *)((int)param_1 + -0xc) != 1))
         && (((*(uint *)((int)param_1 + -0xc) & 0xffff) != 2 &&
             ((*(int *)((int)param_1 + -0xc) != 3 &&
              (iVar2 = FUN_6f625320(2,0x6f6374d4,0x3f9,0,
                                    (byte *)"_BLOCK_TYPE_IS_VALID(pHead->nBlockUse)"), iVar2 == 1)))
             ))) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      if ((DAT_6f639718 & 4) == 0) {
        iVar2 = FUN_6f628540((char *)((int)param_1 + -4),DAT_6f639724,4);
        if ((iVar2 == 0) &&
           (iVar2 = FUN_6f625320(1,0,0,0,(byte *)"DAMAGE: before %hs block (#%d) at 0x%08X.\n"),
           iVar2 == 1)) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        iVar2 = FUN_6f628540((char *)((int)param_1 + *(int *)((int)param_1 + -0x10)),DAT_6f639724,4)
        ;
        if ((iVar2 == 0) &&
           (iVar2 = FUN_6f625320(1,0,0,0,(byte *)"DAMAGE: after %hs block (#%d) at 0x%08X.\n"),
           iVar2 == 1)) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
      }
      if (*(int *)((int)param_1 + -0xc) == 3) {
        if (((*(int *)((int)param_1 + -0x14) != -0x1234544) || (*(int *)((int)param_1 + -8) != 0))
           && (iVar2 = FUN_6f625320(2,0x6f6374d4,0x40e,0,
                                    (byte *)
                                    "pHead->nLine == IGNORE_LINE && pHead->lRequest == IGNORE_REQ"),
              iVar2 == 1)) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        _memset(_Dst,(uint)DAT_6f639728,*(int *)((int)param_1 + -0x10) + 0x24);
        FUN_6f62cfb0((undefined *)_Dst);
      }
      else {
        if ((*(int *)((int)param_1 + -0xc) == 2) && (param_2 == 1)) {
          param_2 = 2;
        }
        if ((*(int *)((int)param_1 + -0xc) != param_2) &&
           (iVar2 = FUN_6f625320(2,0x6f6374d4,0x41b,0,(byte *)"pHead->nBlockUse == nBlockUse"),
           iVar2 == 1)) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        DAT_6f63ce74 = DAT_6f63ce74 - *(int *)((int)param_1 + -0x10);
        if ((DAT_6f639718 & 2) == 0) {
          if (*_Dst == 0) {
            if ((DAT_6f63ce68 != _Dst) &&
               (iVar2 = FUN_6f625320(2,0x6f6374d4,0x42a,0,(byte *)"_pLastBlock == pHead"),
               iVar2 == 1)) {
              pcVar1 = (code *)swi(3);
              (*pcVar1)();
              return;
            }
            DAT_6f63ce68 = *(int **)((int)param_1 + -0x1c);
          }
          else {
            *(undefined4 *)(*_Dst + 4) = *(undefined4 *)((int)param_1 + -0x1c);
          }
          if (*(int *)((int)param_1 + -0x1c) == 0) {
            if ((DAT_6f63ce70 != _Dst) &&
               (iVar2 = FUN_6f625320(2,0x6f6374d4,0x434,0,(byte *)"_pFirstBlock == pHead"),
               iVar2 == 1)) {
              pcVar1 = (code *)swi(3);
              (*pcVar1)();
              return;
            }
            DAT_6f63ce70 = (int *)*_Dst;
          }
          else {
            **(int **)((int)param_1 + -0x1c) = *_Dst;
          }
          _memset(_Dst,(uint)DAT_6f639728,*(int *)((int)param_1 + -0x10) + 0x24);
          FUN_6f62cfb0((undefined *)_Dst);
        }
        else {
          *(undefined4 *)((int)param_1 + -0xc) = 0;
          _memset(param_1,(uint)DAT_6f639728,*(size_t *)((int)param_1 + -0x10));
        }
      }
    }
  }
  return;
}



// Function: FUN_6f6282e0 at 6f6282e0

void __cdecl FUN_6f6282e0(int param_1)

{
  FUN_6f628300(param_1,1);
  return;
}



// Function: FUN_6f628300 at 6f628300

undefined4 __cdecl FUN_6f628300(int param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  BOOL BVar4;
  
  if ((((DAT_6f639718 & 4) != 0) && (iVar2 = FUN_6f6285d0(), iVar2 == 0)) &&
     (iVar2 = FUN_6f625320(2,0x6f6374d4,0x47c,0,(byte *)"_CrtCheckMemory()"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  FUN_6f62c780(9);
  BVar4 = FUN_6f628a30(param_1);
  if ((BVar4 == 0) &&
     (iVar2 = FUN_6f625320(2,0x6f6374d4,0x485,0,(byte *)"_CrtIsValidHeapPointer(pUserData)"),
     iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  if ((((*(uint *)(param_1 + -0xc) & 0xffff) != 4) && (*(int *)(param_1 + -0xc) != 1)) &&
     (((*(uint *)(param_1 + -0xc) & 0xffff) != 2 &&
      ((*(int *)(param_1 + -0xc) != 3 &&
       (iVar2 = FUN_6f625320(2,0x6f6374d4,0x48b,0,(byte *)"_BLOCK_TYPE_IS_VALID(pHead->nBlockUse)"),
       iVar2 == 1)))))) {
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  if ((*(int *)(param_1 + -0xc) == 2) && (param_2 == 1)) {
    param_2 = 2;
  }
  if (((*(int *)(param_1 + -0xc) != 3) && (*(int *)(param_1 + -0xc) != param_2)) &&
     (iVar2 = FUN_6f625320(2,0x6f6374d4,0x492,0,(byte *)"pHead->nBlockUse == nBlockUse"), iVar2 == 1
     )) {
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  uVar3 = *(undefined4 *)(param_1 + -0x10);
  FUN_6f62c820(9);
  return uVar3;
}



// Function: FUN_6f628460 at 6f628460

undefined4 __cdecl FUN_6f628460(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_6f639720;
  DAT_6f639720 = param_1;
  return uVar1;
}



// Function: FUN_6f628480 at 6f628480

void __cdecl FUN_6f628480(int param_1,undefined4 param_2)

{
  code *pcVar1;
  BOOL BVar2;
  int iVar3;
  
  FUN_6f62c780(9);
  BVar2 = FUN_6f628a30(param_1);
  if (BVar2 != 0) {
    if (((((*(uint *)(param_1 + -0xc) & 0xffff) != 4) && (*(int *)(param_1 + -0xc) != 1)) &&
        ((*(uint *)(param_1 + -0xc) & 0xffff) != 2)) &&
       ((*(int *)(param_1 + -0xc) != 3 &&
        (iVar3 = FUN_6f625320(2,0x6f6374d4,0x4d3,0,(byte *)"_BLOCK_TYPE_IS_VALID(pHead->nBlockUse)")
        , iVar3 == 1)))) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    *(undefined4 *)(param_1 + -0xc) = param_2;
  }
  FUN_6f62c820(9);
  return;
}



// Function: FUN_6f628520 at 6f628520

undefined * __cdecl FUN_6f628520(undefined *param_1)

{
  undefined *puVar1;
  
  puVar1 = PTR_FUN_6f639ed8;
  PTR_FUN_6f639ed8 = param_1;
  return puVar1;
}



// Function: FUN_6f628540 at 6f628540

undefined4 __cdecl FUN_6f628540(char *param_1,char param_2,int param_3)

{
  char cVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_8;
  
  local_8 = 1;
  while( true ) {
    do {
      iVar4 = param_3 + -1;
      if (param_3 == 0) {
        return local_8;
      }
      cVar1 = *param_1;
      param_1 = param_1 + 1;
      param_3 = iVar4;
    } while (cVar1 == param_2);
    iVar4 = FUN_6f625320(0,0,0,0,(byte *)
                                 "memory check error at 0x%08X = 0x%02X, should be 0x%02X.\n");
    if (iVar4 == 1) break;
    local_8 = 0;
  }
  pcVar2 = (code *)swi(3);
  uVar3 = (*pcVar2)();
  return uVar3;
}



// Function: FUN_6f6285d0 at 6f6285d0

undefined4 FUN_6f6285d0(void)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *local_c;
  undefined4 local_8;
  
  local_8 = 1;
  if ((DAT_6f639718 & 1) == 0) {
    local_8 = 1;
  }
  else {
    FUN_6f62c780(9);
    iVar3 = FUN_6f62d030();
    if ((iVar3 == -1) || (iVar3 == -2)) {
      for (local_c = DAT_6f63ce70; local_c != (undefined4 *)0x0; local_c = (undefined4 *)*local_c) {
        bVar2 = true;
        iVar3 = FUN_6f628540((char *)(local_c + 7),DAT_6f639724,4);
        if (iVar3 == 0) {
          iVar3 = FUN_6f625320(0,0,0,0,(byte *)"DAMAGE: before %hs block (#%d) at 0x%08X.\n");
          if (iVar3 == 1) {
            pcVar1 = (code *)swi(3);
            uVar4 = (*pcVar1)();
            return uVar4;
          }
          bVar2 = false;
        }
        iVar3 = FUN_6f628540((char *)((int)local_c + local_c[4] + 0x20),DAT_6f639724,4);
        if (iVar3 == 0) {
          iVar3 = FUN_6f625320(0,0,0,0,(byte *)"DAMAGE: after %hs block (#%d) at 0x%08X.\n");
          if (iVar3 == 1) {
            pcVar1 = (code *)swi(3);
            uVar4 = (*pcVar1)();
            return uVar4;
          }
          bVar2 = false;
        }
        if ((local_c[5] == 0) &&
           (iVar3 = FUN_6f628540((char *)(local_c + 8),DAT_6f639728,local_c[4]), iVar3 == 0)) {
          iVar3 = FUN_6f625320(0,0,0,0,(byte *)"DAMAGE: on top of Free block at 0x%08X.\n");
          if (iVar3 == 1) {
            pcVar1 = (code *)swi(3);
            uVar4 = (*pcVar1)();
            return uVar4;
          }
          bVar2 = false;
        }
        if (!bVar2) {
          if ((local_c[2] != 0) &&
             (iVar3 = FUN_6f625320(0,0,0,0,(byte *)"%hs allocated at file %hs(%d).\n"), iVar3 == 1))
          {
            pcVar1 = (code *)swi(3);
            uVar4 = (*pcVar1)();
            return uVar4;
          }
          iVar3 = FUN_6f625320(0,0,0,0,(byte *)"%hs located at 0x%08X is %u bytes long.\n");
          if (iVar3 == 1) {
            pcVar1 = (code *)swi(3);
            uVar4 = (*pcVar1)();
            return uVar4;
          }
          local_8 = 0;
        }
      }
      FUN_6f62c820(9);
    }
    else {
      switch(iVar3) {
      case -6:
        iVar3 = FUN_6f625320(0,0,0,0,&DAT_6f637474);
        if (iVar3 == 1) {
          pcVar1 = (code *)swi(3);
          uVar4 = (*pcVar1)();
          return uVar4;
        }
        break;
      case -5:
        iVar3 = FUN_6f625320(0,0,0,0,&DAT_6f637474);
        if (iVar3 == 1) {
          pcVar1 = (code *)swi(3);
          uVar4 = (*pcVar1)();
          return uVar4;
        }
        break;
      case -4:
        iVar3 = FUN_6f625320(0,0,0,0,&DAT_6f637474);
        if (iVar3 == 1) {
          pcVar1 = (code *)swi(3);
          uVar4 = (*pcVar1)();
          return uVar4;
        }
        break;
      case -3:
        iVar3 = FUN_6f625320(0,0,0,0,&DAT_6f637474);
        if (iVar3 == 1) {
          pcVar1 = (code *)swi(3);
          uVar4 = (*pcVar1)();
          return uVar4;
        }
        break;
      default:
        iVar3 = FUN_6f625320(0,0,0,0,&DAT_6f637474);
        if (iVar3 == 1) {
          pcVar1 = (code *)swi(3);
          uVar4 = (*pcVar1)();
          return uVar4;
        }
      }
      FUN_6f62c820(9);
      local_8 = 0;
    }
  }
  return local_8;
}



// Function: FUN_6f628940 at 6f628940

int __cdecl FUN_6f628940(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_6f639718;
  if (param_1 != -1) {
    DAT_6f639718 = param_1;
  }
  return iVar1;
}



// Function: FUN_6f628970 at 6f628970

void __cdecl FUN_6f628970(undefined *param_1,undefined4 param_2)

{
  undefined4 *local_8;
  
  if ((DAT_6f639718 & 1) != 0) {
    FUN_6f62c780(9);
    for (local_8 = DAT_6f63ce70; local_8 != (undefined4 *)0x0; local_8 = (undefined4 *)*local_8) {
      if ((local_8[5] & 0xffff) == 4) {
        (*(code *)param_1)(local_8 + 8,param_2);
      }
    }
    FUN_6f62c820(9);
  }
  return;
}



// Function: FID_conflict:AtlIsValidAddress at 6f6289e0

/* Library Function - Multiple Matches With Different Base Names
    int __cdecl ATL::AtlIsValidAddress(void const *,unsigned int,int)
    __CrtIsValidPointer
   
   Library: Visual Studio 2003 Debug */

undefined4 __cdecl FID_conflict_AtlIsValidAddress(void *param_1,UINT_PTR param_2,int param_3)

{
  BOOL BVar1;
  
  if (((param_1 != (void *)0x0) && (BVar1 = IsBadReadPtr(param_1,param_2), BVar1 == 0)) &&
     ((param_3 == 0 || (BVar1 = IsBadWritePtr(param_1,param_2), BVar1 == 0)))) {
    return 1;
  }
  return 0;
}



// Function: FUN_6f628a30 at 6f628a30

BOOL __cdecl FUN_6f628a30(int param_1)

{
  BOOL BVar1;
  int iVar2;
  undefined4 local_10;
  char *local_c;
  uint local_8;
  
  if (param_1 == 0) {
    BVar1 = 0;
  }
  else {
    iVar2 = FID_conflict_AtlIsValidAddress((void *)(param_1 + -0x20),0x20,1);
    if (iVar2 == 0) {
      BVar1 = 0;
    }
    else {
      local_c = (char *)FUN_6f62d4c0((undefined *)(param_1 + -0x20),&local_10,&local_8);
      if (local_c == (char *)0x0) {
        if ((DAT_6f63ce24 & 0x8000) == 0) {
          BVar1 = HeapValidate(DAT_6f63e2c4,0,(LPCVOID)(param_1 + -0x20));
        }
        else {
          BVar1 = 1;
        }
      }
      else if (*local_c == '\0') {
        BVar1 = 0;
      }
      else {
        BVar1 = 1;
      }
    }
  }
  return BVar1;
}



// Function: FUN_6f628ac0 at 6f628ac0

undefined4 __cdecl
FUN_6f628ac0(void *param_1,UINT_PTR param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5)

{
  BOOL BVar1;
  int iVar2;
  
  BVar1 = FUN_6f628a30((int)param_1);
  if (BVar1 != 0) {
    FUN_6f62c780(9);
    if ((((((*(uint *)((int)param_1 + -0xc) & 0xffff) == 4) || (*(int *)((int)param_1 + -0xc) == 1))
         || ((*(uint *)((int)param_1 + -0xc) & 0xffff) == 2)) ||
        (*(int *)((int)param_1 + -0xc) == 3)) &&
       (((iVar2 = FID_conflict_AtlIsValidAddress(param_1,param_2,1), iVar2 != 0 &&
         (*(UINT_PTR *)((int)param_1 + -0x10) == param_2)) &&
        (*(int *)((int)param_1 + -8) <= DAT_6f63971c)))) {
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = *(undefined4 *)((int)param_1 + -8);
      }
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = *(undefined4 *)((int)param_1 + -0x18);
      }
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = *(undefined4 *)((int)param_1 + -0x14);
      }
      FUN_6f62c820(9);
      return 1;
    }
    FUN_6f62c820(9);
  }
  return 0;
}



// Function: FUN_6f628bb0 at 6f628bb0

undefined4 __cdecl FUN_6f628bb0(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_6f63e2c8;
  DAT_6f63e2c8 = param_1;
  return uVar1;
}



// Function: FUN_6f628bd0 at 6f628bd0

void __cdecl FUN_6f628bd0(undefined4 *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 *local_c;
  int local_8;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar2 = FUN_6f625320(0,0,0,0,&DAT_6f637474);
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  else {
    FUN_6f62c780(9);
    *param_1 = DAT_6f63ce70;
    for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
      param_1[local_8 + 6] = 0;
      param_1[local_8 + 1] = 0;
    }
    for (local_c = DAT_6f63ce70; local_c != (undefined4 *)0x0; local_c = (undefined4 *)*local_c) {
      if ((local_c[5] & 0xffff) < 5) {
        param_1[(local_c[5] & 0xffff) + 1] = param_1[(local_c[5] & 0xffff) + 1] + 1;
        param_1[(local_c[5] & 0xffff) + 6] = param_1[(local_c[5] & 0xffff) + 6] + local_c[4];
      }
      else {
        iVar2 = FUN_6f625320(0,0,0,0,(byte *)"Bad memory block found at 0x%08X.\n");
        if (iVar2 == 1) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
      }
    }
    param_1[0xb] = DAT_6f63ce78;
    param_1[0xc] = DAT_6f63ce6c;
    FUN_6f62c820(9);
  }
  return;
}



// Function: FUN_6f628d40 at 6f628d40

undefined4 __cdecl FUN_6f628d40(undefined4 *param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  if (((param_1 == (undefined4 *)0x0) || (param_2 == 0)) || (param_3 == 0)) {
    iVar2 = FUN_6f625320(0,0,0,0,&DAT_6f637474);
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    local_c = 0;
  }
  else {
    for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
      param_1[local_8 + 6] =
           *(int *)(param_3 + 0x18 + local_8 * 4) - *(int *)(param_2 + 0x18 + local_8 * 4);
      param_1[local_8 + 1] =
           *(int *)(param_3 + 4 + local_8 * 4) - *(int *)(param_2 + 4 + local_8 * 4);
      if (((param_1[local_8 + 6] != 0) || (param_1[local_8 + 1] != 0)) &&
         ((local_8 != 0 && ((local_8 != 2 || ((DAT_6f639718 & 0x10) != 0)))))) {
        local_c = 1;
      }
    }
    param_1[0xb] = *(int *)(param_3 + 0x2c) - *(int *)(param_2 + 0x2c);
    param_1[0xc] = *(int *)(param_3 + 0x30) - *(int *)(param_2 + 0x30);
    *param_1 = 0;
  }
  return local_c;
}



// Function: FUN_6f628e70 at 6f628e70

void __cdecl FUN_6f628e70(undefined4 *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 *local_c;
  undefined4 *local_8;
  
  local_c = (undefined4 *)0x0;
  FUN_6f62c780(9);
  iVar2 = FUN_6f625320(0,0,0,0,&DAT_6f637474);
  if (iVar2 == 1) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if (param_1 != (undefined4 *)0x0) {
    local_c = (undefined4 *)*param_1;
  }
  local_8 = DAT_6f63ce70;
  do {
    if ((local_8 == (undefined4 *)0x0) || (local_8 == local_c)) {
      FUN_6f62c820(9);
      iVar2 = FUN_6f625320(0,0,0,0,&DAT_6f637474);
      if (iVar2 == 1) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      return;
    }
    if ((((local_8[5] & 0xffff) != 3) && ((local_8[5] & 0xffff) != 0)) &&
       (((local_8[5] & 0xffff) != 2 || ((DAT_6f639718 & 0x10) != 0)))) {
      if (local_8[2] != 0) {
        iVar2 = FID_conflict_AtlIsValidAddress((void *)local_8[2],1,0);
        if (iVar2 == 0) {
          iVar2 = FUN_6f625320(0,0,0,0,(byte *)"#File Error#(%d) : ");
          if (iVar2 == 1) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
          }
        }
        else {
          iVar2 = FUN_6f625320(0,0,0,0,(byte *)"%hs(%d) : ");
          if (iVar2 == 1) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
          }
        }
      }
      iVar2 = FUN_6f625320(0,0,0,0,(byte *)"{%ld} ");
      if (iVar2 == 1) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      if ((local_8[5] & 0xffff) == 4) {
        iVar2 = FUN_6f625320(0,0,0,0,(byte *)"client block at 0x%08X, subtype %x, %u bytes long.\n")
        ;
        if (iVar2 == 1) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        if (DAT_6f63e2c8 == (code *)0x0) {
          FUN_6f629130((int)local_8);
        }
        else {
          (*DAT_6f63e2c8)(local_8 + 8,local_8[4]);
        }
      }
      else if (local_8[5] == 1) {
        iVar2 = FUN_6f625320(0,0,0,0,(byte *)"normal block at 0x%08X, %u bytes long.\n");
        if (iVar2 == 1) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        FUN_6f629130((int)local_8);
      }
      else if ((local_8[5] & 0xffff) == 2) {
        iVar2 = FUN_6f625320(0,0,0,0,(byte *)"crt block at 0x%08X, subtype %x, %u bytes long.\n");
        if (iVar2 == 1) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        FUN_6f629130((int)local_8);
      }
    }
    local_8 = (undefined4 *)*local_8;
  } while( true );
}



// Function: FUN_6f629130 at 6f629130

void __cdecl FUN_6f629130(int param_1)

{
  byte bVar1;
  code *pcVar2;
  int iVar3;
  uint local_5c;
  int local_58;
  int local_50;
  byte local_4c [20];
  undefined1 local_38 [52];
  
  local_50 = 0;
  while( true ) {
    if (*(int *)(param_1 + 0x10) < 0x10) {
      local_58 = *(int *)(param_1 + 0x10);
    }
    else {
      local_58 = 0x10;
    }
    if (local_58 <= local_50) break;
    bVar1 = *(byte *)(param_1 + local_50 + 0x20);
    if (DAT_6f6398f0 < 2) {
      local_5c = *(ushort *)(PTR_DAT_6f639900 + (uint)bVar1 * 2) & 0x157;
    }
    else {
      local_5c = FUN_6f62acf0((uint)bVar1,0x157);
    }
    if (local_5c == 0) {
      bVar1 = 0x20;
    }
    local_4c[local_50] = bVar1;
    FUN_6f623870(local_38 + local_50 * 3,(byte *)"%.2X ");
    local_50 = local_50 + 1;
  }
  local_4c[local_50] = 0;
  iVar3 = FUN_6f625320(0,0,0,0,(byte *)" Data: <%s> %s\n");
  if (iVar3 == 1) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  return;
}



// Function: FUN_6f629250 at 6f629250

undefined4 FUN_6f629250(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_38 [2];
  int local_30;
  int local_2c;
  int local_24;
  
  FUN_6f628bd0(local_38);
  if (((local_24 == 0) && (local_30 == 0)) && (((DAT_6f639718 & 0x10) == 0 || (local_2c == 0)))) {
    uVar3 = 0;
  }
  else {
    iVar2 = FUN_6f625320(0,0,0,0,&DAT_6f637474);
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    FUN_6f628e70((undefined4 *)0x0);
    uVar3 = 1;
  }
  return uVar3;
}



// Function: FUN_6f6292d0 at 6f6292d0

void __cdecl FUN_6f6292d0(int param_1)

{
  code *pcVar1;
  int iVar2;
  int local_8;
  
  if (param_1 != 0) {
    for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
      iVar2 = FUN_6f625320(0,0,0,0,(byte *)"%ld bytes in %ld %hs Blocks.\n");
      if (iVar2 == 1) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
    }
    iVar2 = FUN_6f625320(0,0,0,0,(byte *)"Largest number used: %ld bytes.\n");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    iVar2 = FUN_6f625320(0,0,0,0,(byte *)"Total allocations: %ld bytes.\n");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  return;
}



// Function: FUN_6f6293a0 at 6f6293a0

void FUN_6f6293a0(void)

{
  size_t sVar1;
  int iVar2;
  int *local_10;
  int local_c;
  uint *local_8;
  
  local_c = 0;
  for (local_8 = DAT_6f63ce0c; (char)*local_8 != '\0'; local_8 = (uint *)((int)local_8 + sVar1 + 1))
  {
    if ((char)*local_8 != '=') {
      local_c = local_c + 1;
    }
    sVar1 = _strlen((char *)local_8);
  }
  local_10 = (int *)FUN_6f627430((void *)(local_c * 4 + 4),2,0x6f637b24,0x55);
  DAT_6f63ce40 = local_10;
  if (local_10 == (int *)0x0) {
    __amsg_exit(9);
  }
  for (local_8 = DAT_6f63ce0c; (char)*local_8 != '\0';
      local_8 = (uint *)((int)local_8 + (int)(sVar1 + 1))) {
    sVar1 = _strlen((char *)local_8);
    if ((char)*local_8 != '=') {
      iVar2 = FUN_6f627430((void *)(sVar1 + 1),2,0x6f637b24,0x61);
      *local_10 = iVar2;
      if (*local_10 == 0) {
        __amsg_exit(9);
      }
      FUN_6f6235b0((uint *)*local_10,local_8);
      local_10 = local_10 + 1;
    }
  }
  FUN_6f627ec0(DAT_6f63ce0c,2);
  DAT_6f63ce0c = (uint *)0x0;
  *local_10 = 0;
  return;
}



// Function: FUN_6f6294e0 at 6f6294e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_6f6294e0(void)

{
  byte *local_18;
  int local_10;
  undefined4 *local_c;
  int local_8;
  
  GetModuleFileNameA((HMODULE)0x0,&DAT_6f63ce80,0x104);
  DAT_6f63ce50 = &DAT_6f63ce80;
  if (*DAT_6f63e3f4 == 0) {
    local_18 = &DAT_6f63ce80;
  }
  else {
    local_18 = DAT_6f63e3f4;
  }
  FUN_6f6295b0(local_18,(undefined4 *)0x0,(byte *)0x0,&local_10,&local_8);
  local_c = (undefined4 *)FUN_6f627430((void *)(local_8 + local_10 * 4),2,0x6f637b30,0x75);
  if (local_c == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  FUN_6f6295b0(local_18,local_c,(byte *)(local_c + local_10),&local_10,&local_8);
  _DAT_6f63ce34 = local_10 + -1;
  _DAT_6f63ce38 = local_c;
  return;
}



// Function: FUN_6f6295b0 at 6f6295b0

void __cdecl FUN_6f6295b0(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)

{
  byte bVar1;
  bool bVar2;
  byte *pbVar3;
  bool bVar4;
  uint local_14;
  byte *local_8;
  
  *param_5 = 0;
  *param_4 = 1;
  local_8 = param_1;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_3;
    param_2 = param_2 + 1;
  }
  if (*param_1 == 0x22) {
    while ((pbVar3 = local_8 + 1, *pbVar3 != 0x22 && (*pbVar3 != 0))) {
      if ((((&DAT_6f63cf89)[*pbVar3] & 4) != 0) && (*param_5 = *param_5 + 1, param_3 != (byte *)0x0)
         ) {
        *param_3 = *pbVar3;
        param_3 = param_3 + 1;
        pbVar3 = local_8 + 2;
      }
      local_8 = pbVar3;
      *param_5 = *param_5 + 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = *local_8;
        param_3 = param_3 + 1;
      }
    }
    *param_5 = *param_5 + 1;
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    if (*pbVar3 == 0x22) {
      pbVar3 = local_8 + 2;
    }
  }
  else {
    do {
      *param_5 = *param_5 + 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = *local_8;
        param_3 = param_3 + 1;
      }
      bVar1 = *local_8;
      pbVar3 = local_8 + 1;
      if (((&DAT_6f63cf89)[bVar1] & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = local_8[1];
          param_3 = param_3 + 1;
        }
        pbVar3 = local_8 + 2;
      }
      local_8 = pbVar3;
    } while (((bVar1 != 0x20) && (bVar1 != 0)) && (bVar1 != 9));
    if (bVar1 == 0) {
      pbVar3 = local_8 + -1;
    }
    else {
      pbVar3 = local_8;
      if (param_3 != (byte *)0x0) {
        param_3[-1] = 0;
      }
    }
  }
  local_8 = pbVar3;
  bVar2 = false;
  while( true ) {
    if (*local_8 != 0) {
      for (; (*local_8 == 0x20 || (*local_8 == 9)); local_8 = local_8 + 1) {
      }
    }
    if (*local_8 == 0) break;
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = param_3;
      param_2 = param_2 + 1;
    }
    *param_4 = *param_4 + 1;
    while( true ) {
      bVar4 = true;
      local_14 = 0;
      for (; *local_8 == 0x5c; local_8 = local_8 + 1) {
        local_14 = local_14 + 1;
      }
      if (*local_8 == 0x22) {
        if (local_14 % 2 == 0) {
          if (bVar2) {
            bVar4 = local_8[1] == 0x22;
            if (bVar4) {
              local_8 = local_8 + 1;
            }
          }
          else {
            bVar4 = false;
          }
          bVar2 = !bVar2;
        }
        local_14 = local_14 >> 1;
      }
      while (local_14 != 0) {
        if (param_3 != (byte *)0x0) {
          *param_3 = 0x5c;
          param_3 = param_3 + 1;
        }
        *param_5 = *param_5 + 1;
        local_14 = local_14 - 1;
      }
      if ((*local_8 == 0) || ((!bVar2 && ((*local_8 == 0x20 || (*local_8 == 9)))))) break;
      if (bVar4) {
        if (param_3 == (byte *)0x0) {
          if (((&DAT_6f63cf89)[*local_8] & 4) != 0) {
            local_8 = local_8 + 1;
            *param_5 = *param_5 + 1;
          }
        }
        else {
          if (((&DAT_6f63cf89)[*local_8] & 4) != 0) {
            *param_3 = *local_8;
            param_3 = param_3 + 1;
            local_8 = local_8 + 1;
            *param_5 = *param_5 + 1;
          }
          *param_3 = *local_8;
          param_3 = param_3 + 1;
        }
        *param_5 = *param_5 + 1;
      }
      local_8 = local_8 + 1;
    }
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    *param_5 = *param_5 + 1;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  *param_4 = *param_4 + 1;
  return;
}



// Function: FUN_6f6299e0 at 6f6299e0

undefined4 __cdecl FUN_6f6299e0(UINT param_1)

{
  UINT CodePage;
  undefined4 uVar1;
  BOOL BVar2;
  BYTE *local_2c;
  uint local_28;
  _cpinfo local_24;
  uint local_10;
  byte *local_c;
  uint local_8;
  
  FUN_6f62c780(0x19);
  CodePage = getSystemCP(param_1);
  if (CodePage == DAT_6f63d08c) {
    FUN_6f62c820(0x19);
    uVar1 = 0;
  }
  else if (CodePage == 0) {
    FUN_6f629de0();
    FUN_6f62c820(0x19);
    uVar1 = 0;
  }
  else {
    for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
      if (*(UINT *)(&DAT_6f639750 + local_8 * 0x30) == CodePage) {
        for (local_28 = 0; local_28 < 0x101; local_28 = local_28 + 1) {
          (&DAT_6f63cf88)[local_28] = 0;
        }
        for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
          for (local_c = &DAT_6f639760 + local_10 * 8 + local_8 * 0x30;
              (*local_c != 0 && (local_c[1] != 0)); local_c = local_c + 2) {
            for (local_28 = (uint)*local_c; local_28 <= local_c[1]; local_28 = local_28 + 1) {
              (&DAT_6f63cf89)[local_28] = (&DAT_6f63cf89)[local_28] | (&DAT_6f639748)[local_10];
            }
          }
        }
        DAT_6f63d08c = CodePage;
        DAT_6f63d090 = FUN_6f629d60(CodePage);
        for (local_10 = 0; local_10 < 6; local_10 = local_10 + 1) {
          *(undefined2 *)(&DAT_6f63d098 + local_10 * 2) =
               *(undefined2 *)(&DAT_6f639754 + local_10 * 2 + local_8 * 0x30);
        }
        FUN_6f62c820(0x19);
        return 0;
      }
    }
    BVar2 = GetCPInfo(CodePage,&local_24);
    if (BVar2 == 1) {
      for (local_28 = 0; local_28 < 0x101; local_28 = local_28 + 1) {
        (&DAT_6f63cf88)[local_28] = 0;
      }
      if (local_24.MaxCharSize < 2) {
        DAT_6f63d08c = 0;
        DAT_6f63d090 = 0;
      }
      else {
        for (local_2c = local_24.LeadByte; (*local_2c != 0 && (local_2c[1] != 0));
            local_2c = local_2c + 2) {
          for (local_28 = (uint)*local_2c; local_28 <= local_2c[1]; local_28 = local_28 + 1) {
            (&DAT_6f63cf89)[local_28] = (&DAT_6f63cf89)[local_28] | 4;
          }
        }
        for (local_28 = 1; local_28 < 0xff; local_28 = local_28 + 1) {
          (&DAT_6f63cf89)[local_28] = (&DAT_6f63cf89)[local_28] | 8;
        }
        DAT_6f63d08c = CodePage;
        DAT_6f63d090 = FUN_6f629d60(CodePage);
      }
      for (local_10 = 0; local_10 < 6; local_10 = local_10 + 1) {
        *(undefined2 *)(&DAT_6f63d098 + local_10 * 2) = 0;
      }
      FUN_6f62c820(0x19);
      uVar1 = 0;
    }
    else if (DAT_6f63d0a4 == 0) {
      FUN_6f62c820(0x19);
      uVar1 = 0xffffffff;
    }
    else {
      FUN_6f629de0();
      FUN_6f62c820(0x19);
      uVar1 = 0;
    }
  }
  return uVar1;
}



// Function: getSystemCP at 6f629d00

/* Library Function - Single Match
    _getSystemCP
   
   Library: Visual Studio 2003 Debug */

UINT __cdecl getSystemCP(UINT param_1)

{
  DAT_6f63d0a4 = 0;
  if (param_1 == 0xfffffffe) {
    DAT_6f63d0a4 = 1;
    param_1 = GetOEMCP();
  }
  else if (param_1 == 0xfffffffd) {
    DAT_6f63d0a4 = 1;
    param_1 = GetACP();
  }
  else if (param_1 == 0xfffffffc) {
    DAT_6f63d0a4 = 1;
    param_1 = DAT_6f63d160;
  }
  return param_1;
}



// Function: FUN_6f629d60 at 6f629d60

undefined4 __cdecl FUN_6f629d60(undefined4 param_1)

{
  undefined4 uVar1;
  
  switch(param_1) {
  case 0x3a4:
    uVar1 = 0x411;
    break;
  default:
    uVar1 = 0;
    break;
  case 0x3a8:
    uVar1 = 0x804;
    break;
  case 0x3b5:
    uVar1 = 0x412;
    break;
  case 0x3b6:
    uVar1 = 0x404;
  }
  return uVar1;
}



// Function: FUN_6f629de0 at 6f629de0

void FUN_6f629de0(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 0x101; local_8 = local_8 + 1) {
    (&DAT_6f63cf88)[local_8] = 0;
  }
  DAT_6f63d08c = 0;
  DAT_6f63d090 = 0;
  for (local_8 = 0; local_8 < 6; local_8 = local_8 + 1) {
    *(undefined2 *)(&DAT_6f63d098 + local_8 * 2) = 0;
  }
  return;
}



// Function: FUN_6f629e50 at 6f629e50

undefined4 FUN_6f629e50(void)

{
  return DAT_6f63d08c;
}



// Function: FUN_6f629e60 at 6f629e60

void FUN_6f629e60(void)

{
  FUN_6f6299e0(0xfffffffd);
  return;
}



// Function: FUN_6f629e70 at 6f629e70

void FUN_6f629e70(void)

{
  LPWCH pWVar1;
  undefined4 *puVar2;
  int iVar3;
  size_t sVar4;
  LPWSTR pWVar5;
  void *pvVar6;
  LPWCH local_18;
  LPWCH local_14;
  int local_10;
  LPWCH local_c;
  
  local_18 = (LPWCH)0x0;
  local_10 = 0;
  if (DAT_6f63d0a8 == 0) {
    local_18 = GetEnvironmentStringsW();
    if (local_18 == (LPWCH)0x0) {
      local_18 = (LPWCH)GetEnvironmentStrings();
      if (local_18 == (LPWCH)0x0) {
        return;
      }
      DAT_6f63d0a8 = 2;
    }
    else {
      DAT_6f63d0a8 = 1;
    }
  }
  if (DAT_6f63d0a8 == 1) {
    if ((local_18 != (LPWCH)0x0) || (local_18 = GetEnvironmentStringsW(), local_18 != (LPWCH)0x0)) {
      local_14 = local_18;
      pWVar1 = local_14;
      while (local_14 = pWVar1, *local_14 != L'\0') {
        pWVar1 = local_14 + 1;
        if (local_14[1] == L'\0') {
          pWVar1 = local_14 + 2;
        }
      }
      pvVar6 = (void *)((int)local_14 + (2 - (int)local_18));
      puVar2 = (undefined4 *)FUN_6f627430(pvVar6,2,0x6f637b3c,0x57);
      if (puVar2 == (undefined4 *)0x0) {
        FreeEnvironmentStringsW(local_18);
      }
      else {
        FUN_6f62e010(puVar2,(undefined4 *)local_18,(uint)pvVar6);
        FreeEnvironmentStringsW(local_18);
      }
    }
  }
  else if ((DAT_6f63d0a8 == 2) &&
          ((local_18 != (LPWCH)0x0 ||
           (local_18 = (LPWCH)GetEnvironmentStrings(), local_18 != (LPWCH)0x0)))) {
    for (local_c = local_18; (char)*local_c != '\0'; local_c = (LPWCH)((int)local_c + sVar4 + 1)) {
      iVar3 = MultiByteToWideChar(DAT_6f63d160,1,(LPCSTR)local_c,-1,(LPWSTR)0x0,0);
      if (iVar3 == 0) {
        return;
      }
      local_10 = local_10 + iVar3;
      sVar4 = _strlen((char *)local_c);
    }
    pWVar5 = (LPWSTR)FUN_6f627430((void *)((local_10 + 1) * 2),2,0x6f637b3c,0x87);
    if (pWVar5 == (LPWSTR)0x0) {
      FreeEnvironmentStringsA((LPCH)local_18);
    }
    else {
      local_c = local_18;
      local_14 = pWVar5;
      while ((char)*local_c != '\0') {
        iVar3 = MultiByteToWideChar(DAT_6f63d160,1,(LPCSTR)local_c,-1,local_14,
                                    (local_10 + 1) - ((int)local_14 - (int)pWVar5 >> 1));
        if (iVar3 == 0) {
          FUN_6f627ec0(pWVar5,2);
          FreeEnvironmentStringsA((LPCH)local_18);
          return;
        }
        sVar4 = _strlen((char *)local_c);
        local_c = (LPWCH)((int)local_c + sVar4 + 1);
        iVar3 = FUN_6f62dfe0(local_14);
        local_14 = local_14 + iVar3 + 1;
      }
      *local_14 = L'\0';
      FreeEnvironmentStringsA((LPCH)local_18);
    }
  }
  return;
}



// Function: FUN_6f62a0f0 at 6f62a0f0

LPSTR FUN_6f62a0f0(void)

{
  char *pcVar1;
  LPWCH pWVar2;
  void *cbMultiByte;
  LPSTR pCVar3;
  int iVar4;
  LPCH local_1c;
  LPWCH local_18;
  char *local_10;
  LPWCH local_c;
  
  local_18 = (LPWCH)0x0;
  local_1c = (LPCH)0x0;
  if (DAT_6f63d0ac == 0) {
    local_18 = GetEnvironmentStringsW();
    if (local_18 == (LPWCH)0x0) {
      local_1c = GetEnvironmentStrings();
      if (local_1c == (LPCH)0x0) {
        return (LPSTR)0x0;
      }
      DAT_6f63d0ac = 2;
    }
    else {
      DAT_6f63d0ac = 1;
    }
  }
  if (DAT_6f63d0ac == 1) {
    if ((local_18 == (LPWCH)0x0) && (local_18 = GetEnvironmentStringsW(), local_18 == (LPWCH)0x0)) {
      pCVar3 = (LPSTR)0x0;
    }
    else {
      local_c = local_18;
      pWVar2 = local_c;
      while (local_c = pWVar2, *local_c != L'\0') {
        pWVar2 = local_c + 1;
        if (local_c[1] == L'\0') {
          pWVar2 = local_c + 2;
        }
      }
      iVar4 = ((int)local_c - (int)local_18 >> 1) + 1;
      cbMultiByte = (void *)WideCharToMultiByte(0,0,local_18,iVar4,(LPSTR)0x0,0,(LPCSTR)0x0,
                                                (LPBOOL)0x0);
      if ((cbMultiByte == (void *)0x0) ||
         (local_1c = (LPCH)FUN_6f627430(cbMultiByte,2,0x6f637b3c,0xfb), local_1c == (LPSTR)0x0)) {
        FreeEnvironmentStringsW(local_18);
        pCVar3 = (LPSTR)0x0;
      }
      else {
        iVar4 = WideCharToMultiByte(0,0,local_18,iVar4,local_1c,(int)cbMultiByte,(LPCSTR)0x0,
                                    (LPBOOL)0x0);
        if (iVar4 == 0) {
          FUN_6f627ec0(local_1c,2);
          local_1c = (LPSTR)0x0;
        }
        FreeEnvironmentStringsW(local_18);
        pCVar3 = local_1c;
      }
    }
  }
  else if (DAT_6f63d0ac == 2) {
    if ((local_1c == (LPCH)0x0) && (local_1c = GetEnvironmentStrings(), local_1c == (LPCH)0x0)) {
      pCVar3 = (LPSTR)0x0;
    }
    else {
      local_10 = local_1c;
      pcVar1 = local_10;
      while (local_10 = pcVar1, *local_10 != '\0') {
        pcVar1 = local_10 + 1;
        if (local_10[1] == '\0') {
          pcVar1 = local_10 + 2;
        }
      }
      pCVar3 = (LPSTR)FUN_6f627430(local_10 + (1 - (int)local_1c),2,0x6f637b3c,0x126);
      if (pCVar3 == (LPSTR)0x0) {
        FreeEnvironmentStringsA(local_1c);
        pCVar3 = (LPSTR)0x0;
      }
      else {
        FUN_6f62e010((undefined4 *)pCVar3,(undefined4 *)local_1c,
                     (uint)(local_10 + (1 - (int)local_1c)));
        FreeEnvironmentStringsA(local_1c);
      }
    }
  }
  else {
    pCVar3 = (LPSTR)0x0;
  }
  return pCVar3;
}



// Function: FUN_6f62a310 at 6f62a310

undefined4 FUN_6f62a310(void)

{
  undefined4 uVar1;
  undefined **ppuVar2;
  
  DAT_6f63e2c4 = HeapCreate(0,0x1000,0);
  if (DAT_6f63e2c4 == (HANDLE)0x0) {
    uVar1 = 0;
  }
  else {
    ppuVar2 = FUN_6f62d100();
    if (ppuVar2 == (undefined **)0x0) {
      HeapDestroy(DAT_6f63e2c4);
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}



// Function: FUN_6f62a360 at 6f62a360

void FUN_6f62a360(void)

{
  undefined **local_8;
  
  local_8 = &PTR_LOOP_6f639ee0;
  do {
    if (local_8[4] != (undefined *)0x0) {
      VirtualFree(local_8[4],0,0x8000);
    }
    local_8 = (undefined **)*local_8;
  } while (local_8 != &PTR_LOOP_6f639ee0);
  HeapDestroy(DAT_6f63e2c4);
  return;
}



// Function: __set_error_mode at 6f62a3b0

/* Library Function - Single Match
    __set_error_mode
   
   Library: Visual Studio 2003 Debug */

int __cdecl __set_error_mode(int _Mode)

{
  int iVar1;
  
  if (-1 < _Mode) {
    if (_Mode < 3) {
      iVar1 = DAT_6f63ce14;
      DAT_6f63ce14 = _Mode;
      return iVar1;
    }
    if (_Mode == 3) {
      return DAT_6f63ce14;
    }
  }
  return -1;
}



// Function: FUN_6f62a400 at 6f62a400

void __cdecl FUN_6f62a400(undefined4 param_1)

{
  DAT_6f63ce18 = param_1;
  return;
}



// Function: FUN_6f62a410 at 6f62a410

undefined4 FUN_6f62a410(void)

{
  return 1;
}



// Function: __FF_MSGBANNER at 6f62a420

/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 2003 Debug */

void __cdecl __FF_MSGBANNER(void)

{
  if ((DAT_6f63ce14 == 1) || ((DAT_6f63ce14 == 0 && (DAT_6f63ce18 == 1)))) {
    FUN_6f62a470(0xfc);
    if (DAT_6f63d0b0 != (code *)0x0) {
      (*DAT_6f63d0b0)();
    }
    FUN_6f62a470(0xff);
  }
  return;
}



// Function: FUN_6f62a470 at 6f62a470

void __cdecl FUN_6f62a470(int param_1)

{
  code *pcVar1;
  int iVar2;
  size_t sVar3;
  DWORD DVar4;
  DWORD *lpNumberOfBytesWritten;
  LPOVERLAPPED lpOverlapped;
  HANDLE local_1b8;
  uint local_1b4 [40];
  uint local_114 [65];
  uint *local_10;
  uint local_c;
  DWORD local_8;
  
  for (local_c = 0; (local_c < 0x12 && (param_1 != *(int *)(&DAT_6f639848 + local_c * 8)));
      local_c = local_c + 1) {
  }
  if (param_1 == *(int *)(&DAT_6f639848 + local_c * 8)) {
    if ((param_1 != 0xfc) &&
       (iVar2 = FUN_6f625320(1,0,0,0,(&PTR_s_R6002___floating_point_not_loade_6f63984c)[local_c * 2]
                            ), iVar2 == 1)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if ((DAT_6f63ce14 == 1) || ((DAT_6f63ce14 == 0 && (DAT_6f63ce18 == 1)))) {
      if ((DAT_6f63e2e0 == 0) || (*(int *)(DAT_6f63e2e0 + 0x48) == -1)) {
        local_1b8 = GetStdHandle(0xfffffff4);
      }
      else {
        local_1b8 = *(HANDLE *)(DAT_6f63e2e0 + 0x48);
      }
      lpOverlapped = (LPOVERLAPPED)0x0;
      lpNumberOfBytesWritten = &local_8;
      sVar3 = _strlen((&PTR_s_R6002___floating_point_not_loade_6f63984c)[local_c * 2]);
      WriteFile(local_1b8,(&PTR_s_R6002___floating_point_not_loade_6f63984c)[local_c * 2],sVar3,
                lpNumberOfBytesWritten,lpOverlapped);
    }
    else if (param_1 != 0xfc) {
      DVar4 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_114,0x104);
      if (DVar4 == 0) {
        FUN_6f6235b0(local_114,(uint *)"<program name unknown>");
      }
      local_10 = local_114;
      sVar3 = _strlen((char *)local_10);
      if (0x3c < sVar3 + 1) {
        sVar3 = _strlen((char *)local_114);
        local_10 = (uint *)((int)local_10 + (sVar3 - 0x3b));
        _strncpy((char *)local_10,"...",3);
      }
      FUN_6f6235b0(local_1b4,(uint *)"Runtime Error!\n\nProgram: ");
      FUN_6f6235c0(local_1b4,local_10);
      FUN_6f6235c0(local_1b4,(uint *)&DAT_6f63722c);
      FUN_6f6235c0(local_1b4,(uint *)(&PTR_s_R6002___floating_point_not_loade_6f63984c)[local_c * 2]
                  );
      FUN_6f62bc10(local_1b4,"Microsoft Visual C++ Runtime Library",0x12010);
    }
  }
  return;
}



// Function: __GET_RTERRMSG at 6f62a670

/* Library Function - Single Match
    __GET_RTERRMSG
   
   Library: Visual Studio 2003 Debug */

wchar_t * __cdecl __GET_RTERRMSG(int param_1)

{
  wchar_t *pwVar1;
  uint local_8;
  
  for (local_8 = 0; (local_8 < 0x12 && (param_1 != *(int *)(&DAT_6f639848 + local_8 * 8)));
      local_8 = local_8 + 1) {
  }
  if (param_1 == *(int *)(&DAT_6f639848 + local_8 * 8)) {
    pwVar1 = (wchar_t *)(&PTR_s_R6002___floating_point_not_loade_6f63984c)[local_8 * 2];
  }
  else {
    pwVar1 = (wchar_t *)0x0;
  }
  return pwVar1;
}



// Function: FUN_6f62a6c0 at 6f62a6c0

uint __cdecl FUN_6f62a6c0(LPWSTR param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  bool bVar2;
  
  InterlockedIncrement(&DAT_6f63d2b0);
  bVar2 = DAT_6f63d2ac == 0;
  if (!bVar2) {
    InterlockedDecrement(&DAT_6f63d2b0);
    FUN_6f62c780(0x13);
  }
  uVar1 = FUN_6f62a740(param_1,param_2,param_3);
  if (bVar2) {
    InterlockedDecrement(&DAT_6f63d2b0);
  }
  else {
    FUN_6f62c820(0x13);
  }
  return uVar1;
}



// Function: FUN_6f62a740 at 6f62a740

uint __cdecl FUN_6f62a740(LPWSTR param_1,byte *param_2,uint param_3)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  if (((DAT_6f6398f0 != 1) && (DAT_6f6398f0 != 2)) &&
     (iVar2 = FUN_6f625320(2,0x6f637e18,0x4f,0,(byte *)"MB_CUR_MAX == 1 || MB_CUR_MAX == 2"),
     iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  if ((param_2 == (byte *)0x0) || (param_3 == 0)) {
    uVar3 = 0;
  }
  else if (*param_2 == 0) {
    if (param_1 != (LPWSTR)0x0) {
      *param_1 = L'\0';
    }
    uVar3 = 0;
  }
  else if (DAT_6f63d150 == 0) {
    if (param_1 != (LPWSTR)0x0) {
      *param_1 = (ushort)*param_2;
    }
    uVar3 = 1;
  }
  else if ((*(ushort *)(PTR_DAT_6f639900 + (uint)*param_2 * 2) & 0x8000) == 0) {
    iVar2 = MultiByteToWideChar(DAT_6f63d160,9,(LPCSTR)param_2,1,param_1,
                                (uint)(param_1 != (LPWSTR)0x0));
    if (iVar2 == 0) {
      puVar4 = (undefined4 *)FUN_6f62ee40();
      *puVar4 = 0x2a;
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = 1;
    }
  }
  else if (((((int)DAT_6f6398f0 < 2) || ((int)param_3 < (int)DAT_6f6398f0)) ||
           (iVar2 = MultiByteToWideChar(DAT_6f63d160,9,(LPCSTR)param_2,DAT_6f6398f0,param_1,
                                        (uint)(param_1 != (LPWSTR)0x0)), uVar3 = DAT_6f6398f0,
           iVar2 == 0)) && ((param_3 < DAT_6f6398f0 || (uVar3 = DAT_6f6398f0, param_2[1] == 0)))) {
    puVar4 = (undefined4 *)FUN_6f62ee40();
    *puVar4 = 0x2a;
    uVar3 = 0xffffffff;
  }
  return uVar3;
}



// Function: _memset at 6f62a8a0

/* Library Function - Single Match
    _memset
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

void * __cdecl _memset(void *_Dst,int _Val,size_t _Size)

{
  uint uVar1;
  uint uVar2;
  size_t sVar3;
  uint *puVar4;
  
  if (_Size == 0) {
    return _Dst;
  }
  uVar1 = _Val & 0xff;
  puVar4 = (uint *)_Dst;
  if (3 < _Size) {
    uVar2 = -(int)_Dst & 3;
    sVar3 = _Size;
    if (uVar2 != 0) {
      sVar3 = _Size - uVar2;
      do {
        *(undefined1 *)puVar4 = (undefined1)_Val;
        puVar4 = (uint *)((int)puVar4 + 1);
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    uVar1 = uVar1 * 0x1010101;
    _Size = sVar3 & 3;
    uVar2 = sVar3 >> 2;
    if (uVar2 != 0) {
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
      }
      if (_Size == 0) {
        return _Dst;
      }
    }
  }
  do {
    *(char *)puVar4 = (char)uVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
    _Size = _Size - 1;
  } while (_Size != 0);
  return _Dst;
}



// Function: FUN_6f62a900 at 6f62a900

uint __cdecl FUN_6f62a900(int param_1)

{
  uint local_8;
  
  if (DAT_6f6398f0 < 2) {
    local_8 = *(ushort *)(PTR_DAT_6f639900 + param_1 * 2) & 0x103;
  }
  else {
    local_8 = FUN_6f62acf0(param_1,0x103);
  }
  return local_8;
}



// Function: FUN_6f62a950 at 6f62a950

uint __cdecl FUN_6f62a950(int param_1)

{
  uint local_8;
  
  if (DAT_6f6398f0 < 2) {
    local_8 = *(ushort *)(PTR_DAT_6f639900 + param_1 * 2) & 1;
  }
  else {
    local_8 = FUN_6f62acf0(param_1,1);
  }
  return local_8;
}



// Function: FUN_6f62a990 at 6f62a990

uint __cdecl FUN_6f62a990(int param_1)

{
  uint local_8;
  
  if (DAT_6f6398f0 < 2) {
    local_8 = *(ushort *)(PTR_DAT_6f639900 + param_1 * 2) & 2;
  }
  else {
    local_8 = FUN_6f62acf0(param_1,2);
  }
  return local_8;
}



// Function: FUN_6f62a9d0 at 6f62a9d0

uint __cdecl FUN_6f62a9d0(int param_1)

{
  uint local_8;
  
  if (DAT_6f6398f0 < 2) {
    local_8 = *(ushort *)(PTR_DAT_6f639900 + param_1 * 2) & 4;
  }
  else {
    local_8 = FUN_6f62acf0(param_1,4);
  }
  return local_8;
}



// Function: FUN_6f62aa10 at 6f62aa10

uint __cdecl FUN_6f62aa10(int param_1)

{
  uint local_8;
  
  if (DAT_6f6398f0 < 2) {
    local_8 = *(ushort *)(PTR_DAT_6f639900 + param_1 * 2) & 0x80;
  }
  else {
    local_8 = FUN_6f62acf0(param_1,0x80);
  }
  return local_8;
}



// Function: FUN_6f62aa60 at 6f62aa60

uint __cdecl FUN_6f62aa60(int param_1)

{
  uint local_8;
  
  if (DAT_6f6398f0 < 2) {
    local_8 = *(ushort *)(PTR_DAT_6f639900 + param_1 * 2) & 8;
  }
  else {
    local_8 = FUN_6f62acf0(param_1,8);
  }
  return local_8;
}



// Function: FUN_6f62aaa0 at 6f62aaa0

uint __cdecl FUN_6f62aaa0(int param_1)

{
  uint local_8;
  
  if (DAT_6f6398f0 < 2) {
    local_8 = *(ushort *)(PTR_DAT_6f639900 + param_1 * 2) & 0x10;
  }
  else {
    local_8 = FUN_6f62acf0(param_1,0x10);
  }
  return local_8;
}



// Function: FUN_6f62aae0 at 6f62aae0

uint __cdecl FUN_6f62aae0(int param_1)

{
  uint local_8;
  
  if (DAT_6f6398f0 < 2) {
    local_8 = *(ushort *)(PTR_DAT_6f639900 + param_1 * 2) & 0x107;
  }
  else {
    local_8 = FUN_6f62acf0(param_1,0x107);
  }
  return local_8;
}



// Function: FUN_6f62ab30 at 6f62ab30

uint __cdecl FUN_6f62ab30(int param_1)

{
  uint local_8;
  
  if (DAT_6f6398f0 < 2) {
    local_8 = *(ushort *)(PTR_DAT_6f639900 + param_1 * 2) & 0x157;
  }
  else {
    local_8 = FUN_6f62acf0(param_1,0x157);
  }
  return local_8;
}



// Function: FUN_6f62ab80 at 6f62ab80

uint __cdecl FUN_6f62ab80(int param_1)

{
  uint local_8;
  
  if (DAT_6f6398f0 < 2) {
    local_8 = *(ushort *)(PTR_DAT_6f639900 + param_1 * 2) & 0x117;
  }
  else {
    local_8 = FUN_6f62acf0(param_1,0x117);
  }
  return local_8;
}



// Function: FUN_6f62abd0 at 6f62abd0

uint __cdecl FUN_6f62abd0(int param_1)

{
  uint local_8;
  
  if (DAT_6f6398f0 < 2) {
    local_8 = *(ushort *)(PTR_DAT_6f639900 + param_1 * 2) & 0x20;
  }
  else {
    local_8 = FUN_6f62acf0(param_1,0x20);
  }
  return local_8;
}



// Function: FUN_6f62ac10 at 6f62ac10

bool __cdecl FUN_6f62ac10(uint param_1)

{
  return param_1 < 0x80;
}



// Function: FUN_6f62ac20 at 6f62ac20

uint __cdecl FUN_6f62ac20(uint param_1)

{
  return param_1 & 0x7f;
}



// Function: FUN_6f62ac30 at 6f62ac30

undefined4 __cdecl FUN_6f62ac30(int param_1)

{
  undefined4 local_c;
  uint local_8;
  
  if (DAT_6f6398f0 < 2) {
    local_8 = *(ushort *)(PTR_DAT_6f639900 + param_1 * 2) & 0x103;
  }
  else {
    local_8 = FUN_6f62acf0(param_1,0x103);
  }
  if ((local_8 == 0) && (param_1 != 0x5f)) {
    local_c = 0;
  }
  else {
    local_c = 1;
  }
  return local_c;
}



// Function: FUN_6f62ac90 at 6f62ac90

undefined4 __cdecl FUN_6f62ac90(int param_1)

{
  undefined4 local_c;
  uint local_8;
  
  if (DAT_6f6398f0 < 2) {
    local_8 = *(ushort *)(PTR_DAT_6f639900 + param_1 * 2) & 0x107;
  }
  else {
    local_8 = FUN_6f62acf0(param_1,0x107);
  }
  if ((local_8 == 0) && (param_1 != 0x5f)) {
    local_c = 0;
  }
  else {
    local_c = 1;
  }
  return local_c;
}



// Function: FUN_6f62acf0 at 6f62acf0

uint __cdecl FUN_6f62acf0(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  CHAR local_10;
  CHAR local_f;
  undefined1 local_e;
  int local_c;
  uint local_8;
  
  if (param_1 + 1U < 0x101) {
    uVar1 = *(ushort *)(PTR_DAT_6f639900 + param_1 * 2) & param_2;
  }
  else {
    if ((*(ushort *)(PTR_DAT_6f639900 + (param_1 >> 8 & 0xffU) * 2) & 0x8000) == 0) {
      local_10 = (CHAR)param_1;
      local_f = '\0';
      local_c = 1;
    }
    else {
      local_10 = (CHAR)((uint)param_1 >> 8);
      local_f = (CHAR)param_1;
      local_e = 0;
      local_c = 2;
    }
    iVar2 = FUN_6f62f070(1,&local_10,local_c,(LPWORD)&local_8,0,0);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = local_8 & 0xffff & param_2;
    }
  }
  return uVar1;
}



// Function: __allshl at 6f62adb0

/* Library Function - Single Match
    __allshl
   
   Library: Visual Studio */

longlong __fastcall __allshl(byte param_1,int param_2)

{
  uint in_EAX;
  
  if (0x3f < param_1) {
    return 0;
  }
  if (param_1 < 0x20) {
    return CONCAT44(param_2 << (param_1 & 0x1f) | in_EAX >> 0x20 - (param_1 & 0x1f),
                    in_EAX << (param_1 & 0x1f));
  }
  return (ulonglong)(in_EAX << (param_1 & 0x1f)) << 0x20;
}



// Function: FUN_6f62add0 at 6f62add0

uint __cdecl FUN_6f62add0(int *param_1)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  undefined *local_c;
  
  if ((param_1 == (int *)0x0) &&
     (iVar2 = FUN_6f625320(2,0x6f637e48,0x69,0,(byte *)"str != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  if (((param_1[3] & 0x83U) == 0) || ((param_1[3] & 0x40U) != 0)) {
    uVar3 = 0xffffffff;
  }
  else if ((param_1[3] & 2U) == 0) {
    param_1[3] = param_1[3] | 1;
    if ((param_1[3] & 0x10cU) == 0) {
      FUN_6f62c230(param_1);
    }
    else {
      *param_1 = param_1[2];
    }
    iVar2 = FUN_6f62f1d0(param_1[4],(char *)param_1[2],param_1[6]);
    param_1[1] = iVar2;
    if ((param_1[1] == 0) || (param_1[1] == -1)) {
      param_1[3] = param_1[3] | (-(uint)(param_1[1] != 0) & 0x10) + 0x10;
      param_1[1] = 0;
      uVar3 = 0xffffffff;
    }
    else {
      if ((param_1[3] & 0x82U) == 0) {
        if (param_1[4] == -1) {
          local_c = &DAT_6f6396f0;
        }
        else {
          local_c = (undefined *)((&DAT_6f63e2e0)[param_1[4] >> 5] + (param_1[4] & 0x1fU) * 0x24);
        }
        if (((int)(char)local_c[4] & 0x82U) == 0x82) {
          param_1[3] = param_1[3] | 0x2000;
        }
      }
      if (((param_1[6] == 0x200) && ((param_1[3] & 8U) != 0)) && ((param_1[3] & 0x400U) == 0)) {
        param_1[6] = 0x1000;
      }
      param_1[1] = param_1[1] + -1;
      uVar3 = (uint)*(byte *)*param_1;
      *param_1 = *param_1 + 1;
    }
  }
  else {
    param_1[3] = param_1[3] | 0x20;
    uVar3 = 0xffffffff;
  }
  return uVar3;
}



// Function: FUN_6f62afc0 at 6f62afc0

uint __cdecl FUN_6f62afc0(uint param_1,undefined **param_2)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  
  if ((param_2 == (undefined **)0x0) &&
     (iVar2 = FUN_6f625320(2,0x6f637e54,0x31,0,(byte *)"stream != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  FUN_6f62c840(param_2);
  uVar3 = FUN_6f62b030(param_1,(int *)param_2);
  FUN_6f62c8b0(param_2);
  return uVar3;
}



// Function: FUN_6f62b030 at 6f62b030

uint __cdecl FUN_6f62b030(uint param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  
  if ((param_2 == (int *)0x0) &&
     (iVar2 = FUN_6f625320(2,0x6f637e54,0x60,0,(byte *)"str != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  if ((param_1 == 0xffffffff) ||
     (((param_2[3] & 1U) == 0 && (((param_2[3] & 0x80U) == 0 || ((param_2[3] & 2U) != 0)))))) {
    uVar3 = 0xffffffff;
  }
  else {
    if (param_2[2] == 0) {
      FUN_6f62c230(param_2);
    }
    if (*param_2 == param_2[2]) {
      if (param_2[1] != 0) {
        return 0xffffffff;
      }
      *param_2 = *param_2 + 1;
    }
    if ((param_2[3] & 0x40U) == 0) {
      *param_2 = *param_2 + -1;
      *(char *)*param_2 = (char)param_1;
    }
    else {
      *param_2 = *param_2 + -1;
      if (*(char *)*param_2 != (char)param_1) {
        *param_2 = *param_2 + 1;
        return 0xffffffff;
      }
    }
    param_2[1] = param_2[1] + 1;
    param_2[3] = param_2[3] & 0xffffffef;
    param_2[3] = param_2[3] | 1;
    uVar3 = param_1 & 0xff;
  }
  return uVar3;
}



// Function: __itoa at 6f62b170

/* Library Function - Single Match
    __itoa
   
   Library: Visual Studio 2003 Debug */

char * __cdecl __itoa(int _Value,char *_Dest,int _Radix)

{
  if ((_Radix == 10) && (_Value < 0)) {
    xtoa(_Value,_Dest,10,1);
  }
  else {
    xtoa(_Value,_Dest,_Radix,0);
  }
  return _Dest;
}



// Function: xtoa at 6f62b1c0

/* Library Function - Single Match
    _xtoa
   
   Library: Visual Studio 2003 Debug */

void __cdecl xtoa(uint param_1,char *param_2,uint param_3,int param_4)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  char *local_c;
  char *local_8;
  
  local_8 = param_2;
  if (param_4 != 0) {
    *param_2 = '-';
    local_8 = param_2 + 1;
    param_1 = -param_1;
  }
  local_c = local_8;
  do {
    pcVar2 = local_8;
    uVar3 = param_1 % param_3;
    param_1 = param_1 / param_3;
    cVar1 = (char)uVar3;
    if (uVar3 < 10) {
      *local_8 = cVar1 + '0';
    }
    else {
      *local_8 = cVar1 + 'W';
    }
    local_8 = local_8 + 1;
  } while (param_1 != 0);
  *local_8 = '\0';
  local_8 = pcVar2;
  do {
    cVar1 = *local_8;
    *local_8 = *local_c;
    *local_c = cVar1;
    local_8 = local_8 + -1;
    local_c = local_c + 1;
  } while (local_c < local_8);
  return;
}



// Function: __ltoa at 6f62b290

/* Library Function - Single Match
    __ltoa
   
   Library: Visual Studio 2003 Debug */

char * __cdecl __ltoa(long _Value,char *_Dest,int _Radix)

{
  undefined4 local_8;
  
  if ((_Radix == 10) && (_Value < 0)) {
    local_8 = 1;
  }
  else {
    local_8 = 0;
  }
  xtoa(_Value,_Dest,_Radix,local_8);
  return _Dest;
}



// Function: __ultoa at 6f62b2d0

/* Library Function - Single Match
    __ultoa
   
   Library: Visual Studio 2003 Debug */

char * __cdecl __ultoa(ulong _Value,char *_Dest,int _Radix)

{
  xtoa(_Value,_Dest,_Radix,0);
  return _Dest;
}



// Function: __i64toa at 6f62b2f0

/* Library Function - Single Match
    __i64toa
   
   Library: Visual Studio 2003 Debug */

char * __cdecl __i64toa(longlong _Val,char *_DstBuf,int _Radix)

{
  int local_8;
  
  if (((_Radix == 10) && (_Val < 0x100000000)) && (_Val < 0)) {
    local_8 = 1;
  }
  else {
    local_8 = 0;
  }
  FUN_6f62b340(_Val,_DstBuf,_Radix,local_8);
  return _DstBuf;
}



// Function: FUN_6f62b340 at 6f62b340

void FUN_6f62b340(undefined8 param_1,char *param_2,uint param_3,int param_4)

{
  char cVar1;
  char *pcVar2;
  bool bVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  char *local_c;
  char *local_8;
  
  local_8 = param_2;
  if (param_4 != 0) {
    *param_2 = '-';
    local_8 = param_2 + 1;
  }
  local_c = local_8;
  do {
    pcVar2 = local_8;
    uVar4 = __aullrem((uint)param_1,param_1._4_4_,param_3,0);
    uVar5 = __aulldiv((uint)param_1,param_1._4_4_,param_3,0);
    if ((uint)uVar4 < 10) {
      *local_8 = (char)uVar4 + '0';
    }
    else {
      *local_8 = (char)uVar4 + 'W';
    }
    local_8 = local_8 + 1;
    param_1._4_4_ = (uint)((ulonglong)uVar5 >> 0x20);
    bVar3 = param_1._4_4_ != 0;
    param_1 = uVar5;
  } while ((bVar3) || (param_1._0_4_ = (uint)uVar5, bVar3 = (uint)param_1 != 0, bVar3));
  *local_8 = '\0';
  local_8 = pcVar2;
  do {
    cVar1 = *local_8;
    *local_8 = *local_c;
    *local_c = cVar1;
    local_8 = local_8 + -1;
    local_c = local_c + 1;
  } while (local_c < local_8);
  return;
}



// Function: __ui64toa at 6f62b420

/* Library Function - Single Match
    __ui64toa
   
   Library: Visual Studio 2003 Debug */

char * __cdecl __ui64toa(ulonglong _Val,char *_DstBuf,int _Radix)

{
  FUN_6f62b340(_Val,_DstBuf,_Radix,0);
  return _DstBuf;
}



// Function: FUN_6f62b440 at 6f62b440

int __cdecl FUN_6f62b440(undefined1 *param_1,int param_2,byte *param_3)

{
  code *pcVar1;
  int iVar2;
  undefined1 *local_24;
  int local_20;
  undefined1 *local_1c;
  undefined4 local_18;
  
  if ((param_1 == (undefined1 *)0x0) &&
     (iVar2 = FUN_6f625320(2,0x6f637084,0x5d,0,(byte *)"string != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  if ((param_3 == (byte *)0x0) &&
     (iVar2 = FUN_6f625320(2,0x6f637084,0x5e,0,(byte *)"format != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  local_18 = 0x42;
  local_1c = param_1;
  local_24 = param_1;
  local_20 = param_2;
  iVar2 = FUN_6f625d10((int *)&local_24,param_3,(undefined4 *)&stack0x00000010);
  local_20 = local_20 + -1;
  if (local_20 < 0) {
    FUN_6f625a90(0,(int *)&local_24);
  }
  else {
    *local_24 = 0;
  }
  return iVar2;
}



// Function: FUN_6f62b540 at 6f62b540

int __cdecl FUN_6f62b540(undefined1 *param_1,int param_2,byte *param_3,undefined4 *param_4)

{
  code *pcVar1;
  int iVar2;
  undefined1 *local_24;
  int local_20;
  undefined1 *local_1c;
  undefined4 local_18;
  
  if ((param_1 == (undefined1 *)0x0) &&
     (iVar2 = FUN_6f625320(2,0x6f637e60,0x5a,0,(byte *)"string != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  if ((param_3 == (byte *)0x0) &&
     (iVar2 = FUN_6f625320(2,0x6f637e60,0x5b,0,(byte *)"format != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  local_18 = 0x42;
  local_1c = param_1;
  local_24 = param_1;
  local_20 = param_2;
  iVar2 = FUN_6f625d10((int *)&local_24,param_3,param_4);
  local_20 = local_20 + -1;
  if (local_20 < 0) {
    FUN_6f625a90(0,(int *)&local_24);
  }
  else {
    *local_24 = 0;
  }
  return iVar2;
}



// Function: FUN_6f62b640 at 6f62b640

/* WARNING: Unable to track spacebase fully for stack */

void FUN_6f62b640(void)

{
  uint in_EAX;
  undefined1 *puVar1;
  undefined4 unaff_retaddr;
  
  puVar1 = &stack0x00000004;
  if (0xfff < in_EAX) {
    do {
      puVar1 = puVar1 + -0x1000;
      in_EAX = in_EAX - 0x1000;
    } while (0xfff < in_EAX);
  }
  *(undefined4 *)(puVar1 + (-4 - in_EAX)) = unaff_retaddr;
  return;
}



// Function: FUN_6f62b670 at 6f62b670

int __cdecl FUN_6f62b670(int param_1,int param_2)

{
  int iVar1;
  BOOL BVar2;
  DWORD DVar3;
  DWORD *pDVar4;
  undefined4 *puVar5;
  int local_10;
  uint local_c;
  
  if ((param_2 != 4) && (param_2 != 3)) {
    if ((param_1 == 2) || (((param_1 == 0x15 || (param_1 == 0x16)) || (param_1 == 0xf)))) {
      FUN_6f62c780(1);
      if (((param_1 == 2) || (param_1 == 0x15)) && (DAT_6f63d0c4 == 0)) {
        BVar2 = SetConsoleCtrlHandler(FUN_6f62b8a0,1);
        if (BVar2 != 1) {
          DVar3 = GetLastError();
          pDVar4 = FUN_6f62ee50();
          *pDVar4 = DVar3;
          FUN_6f62c820(1);
          goto LAB_6f62b858;
        }
        DAT_6f63d0c4 = 1;
      }
      switch(param_1) {
      case 2:
        local_10 = DAT_6f63d0b4;
        DAT_6f63d0b4 = param_2;
        break;
      case 0xf:
        local_10 = DAT_6f63d0c0;
        DAT_6f63d0c0 = param_2;
        break;
      case 0x15:
        local_10 = DAT_6f63d0b8;
        DAT_6f63d0b8 = param_2;
        break;
      case 0x16:
        local_10 = DAT_6f63d0bc;
        DAT_6f63d0bc = param_2;
      }
      FUN_6f62c820(1);
      return local_10;
    }
    if (((param_1 == 8) || (param_1 == 4)) || (param_1 == 0xb)) {
      pDVar4 = FUN_6f626e90();
      if ((undefined *)pDVar4[0x14] == &DAT_6f639e50) {
        DVar3 = FUN_6f627430(DAT_6f639ed0,2,0x6f637e6c,0x133);
        pDVar4[0x14] = DVar3;
        if (pDVar4[0x14] == 0) goto LAB_6f62b858;
        FUN_6f62e010((undefined4 *)pDVar4[0x14],(undefined4 *)&DAT_6f639e50,(uint)DAT_6f639ed0);
      }
      local_c = FUN_6f62bb90(param_1,pDVar4[0x14]);
      if (local_c != 0) {
        iVar1 = *(int *)(local_c + 8);
        do {
          if (*(int *)(local_c + 4) != param_1) {
            return iVar1;
          }
          *(int *)(local_c + 8) = param_2;
          local_c = local_c + 0xc;
        } while (local_c < pDVar4[0x14] + DAT_6f639ed4 * 0xc);
        return iVar1;
      }
    }
  }
LAB_6f62b858:
  puVar5 = (undefined4 *)FUN_6f62ee40();
  *puVar5 = 0x16;
  return -1;
}



// Function: FUN_6f62b8a0 at 6f62b8a0

undefined4 FUN_6f62b8a0(int param_1)

{
  undefined4 uVar1;
  code *local_10;
  undefined4 *local_c;
  undefined4 local_8;
  
  FUN_6f62c780(1);
  if (param_1 == 0) {
    local_c = &DAT_6f63d0b4;
    local_10 = DAT_6f63d0b4;
    local_8 = 2;
  }
  else {
    local_c = &DAT_6f63d0b8;
    local_10 = DAT_6f63d0b8;
    local_8 = 0x15;
  }
  if (local_10 == (code *)0x0) {
    FUN_6f62c820(1);
    uVar1 = 0;
  }
  else {
    if (local_10 == (code *)0x1) {
      FUN_6f62c820(1);
    }
    else {
      *local_c = 0;
      FUN_6f62c820(1);
      (*local_10)(local_8);
    }
    uVar1 = 1;
  }
  return uVar1;
}



// Function: FUN_6f62b940 at 6f62b940

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_6f62b940(int param_1)

{
  bool bVar1;
  uint uVar2;
  code *local_20;
  undefined4 *local_1c;
  DWORD local_18;
  int local_14;
  DWORD local_c;
  DWORD *local_8;
  
  bVar1 = false;
  switch(param_1) {
  case 2:
    local_1c = &DAT_6f63d0b4;
    local_20 = DAT_6f63d0b4;
    bVar1 = true;
    break;
  default:
    return 0xffffffff;
  case 4:
  case 8:
  case 0xb:
    local_8 = FUN_6f626e90();
    uVar2 = FUN_6f62bb90(param_1,local_8[0x14]);
    local_1c = (undefined4 *)(uVar2 + 8);
    local_20 = (code *)*local_1c;
    break;
  case 0xf:
    local_1c = &DAT_6f63d0c0;
    local_20 = DAT_6f63d0c0;
    bVar1 = true;
    break;
  case 0x15:
    local_1c = &DAT_6f63d0b8;
    local_20 = DAT_6f63d0b8;
    bVar1 = true;
    break;
  case 0x16:
    local_1c = &DAT_6f63d0bc;
    local_20 = DAT_6f63d0bc;
    bVar1 = true;
  }
  if (bVar1) {
    FUN_6f62c780(1);
  }
  if (local_20 != (code *)0x1) {
    if (local_20 == (code *)0x0) {
      if (bVar1) {
        FUN_6f62c820(1);
      }
                    /* WARNING: Subroutine does not return */
      __exit(3);
    }
    if (((param_1 == 8) || (param_1 == 0xb)) || (param_1 == 4)) {
      local_18 = local_8[0x15];
      local_8[0x15] = 0;
      if (param_1 == 8) {
        local_c = local_8[0x16];
        local_8[0x16] = 0x8c;
      }
    }
    if (param_1 == 8) {
      for (local_14 = DAT_6f639ec8; local_14 < DAT_6f639ec8 + _DAT_6f639ecc; local_14 = local_14 + 1
          ) {
        *(undefined4 *)(local_8[0x14] + 8 + local_14 * 0xc) = 0;
      }
    }
    else {
      *local_1c = 0;
    }
    if (bVar1) {
      FUN_6f62c820(1);
    }
    if (param_1 == 8) {
      (*local_20)(8,local_8[0x16]);
    }
    else {
      (*local_20)(param_1);
      if ((param_1 != 0xb) && (param_1 != 4)) {
        return 0;
      }
    }
    local_8[0x15] = local_18;
    if (param_1 == 8) {
      local_8[0x16] = local_c;
    }
    return 0;
  }
  if (bVar1) {
    FUN_6f62c820(1);
  }
  return 0;
}



// Function: FUN_6f62bb90 at 6f62bb90

uint __cdecl FUN_6f62bb90(int param_1,uint param_2)

{
  uint local_8;
  
  local_8 = param_2;
  do {
    if (*(int *)(local_8 + 4) == param_1) break;
    local_8 = local_8 + 0xc;
  } while (local_8 < param_2 + DAT_6f639ed4 * 0xc);
  if ((param_2 + DAT_6f639ed4 * 0xc <= local_8) || (*(int *)(local_8 + 4) != param_1)) {
    local_8 = 0;
  }
  return local_8;
}



// Function: FUN_6f62bbf0 at 6f62bbf0

DWORD * FUN_6f62bbf0(void)

{
  DWORD *pDVar1;
  
  pDVar1 = FUN_6f626e90();
  return pDVar1 + 0x16;
}



// Function: FUN_6f62bc00 at 6f62bc00

DWORD * FUN_6f62bc00(void)

{
  DWORD *pDVar1;
  
  pDVar1 = FUN_6f626e90();
  return pDVar1 + 0x15;
}



// Function: FUN_6f62bc10 at 6f62bc10

int __cdecl FUN_6f62bc10(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;
  int local_8;
  
  local_8 = 0;
  if (DAT_6f63d0c8 == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_6f63d0c8 = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_6f63d0c8 != (FARPROC)0x0) {
        DAT_6f63d0cc = GetProcAddress(hModule,"GetActiveWindow");
        DAT_6f63d0d0 = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_6f62bc83;
      }
    }
    iVar1 = 0;
  }
  else {
LAB_6f62bc83:
    if (DAT_6f63d0cc != (FARPROC)0x0) {
      local_8 = (*DAT_6f63d0cc)();
    }
    if ((local_8 != 0) && (DAT_6f63d0d0 != (FARPROC)0x0)) {
      local_8 = (*DAT_6f63d0d0)(local_8);
    }
    iVar1 = (*DAT_6f63d0c8)(local_8,param_1,param_2,param_3);
  }
  return iVar1;
}



// Function: _strncpy at 6f62bcd0

/* Library Function - Single Match
    _strncpy
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strncpy(char *_Dest,char *_Source,size_t _Count)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  uint *puVar5;
  
  if (_Count == 0) {
    return _Dest;
  }
  puVar5 = (uint *)_Dest;
  if (((uint)_Source & 3) != 0) {
    while( true ) {
      uVar4 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 1);
      *(char *)puVar5 = (char)uVar4;
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
      if (_Count == 0) {
        return _Dest;
      }
      if ((char)uVar4 == '\0') break;
      if (((uint)_Source & 3) == 0) {
        uVar4 = _Count >> 2;
        goto joined_r0x6f62bd0e;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_6f62bd4b;
        goto LAB_6f62bdb9;
      }
      *(char *)puVar5 = '\0';
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
    } while (_Count != 0);
    return _Dest;
  }
  uVar4 = _Count >> 2;
  if (uVar4 != 0) {
    do {
      uVar1 = *(uint *)_Source;
      uVar2 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 4);
      if (((uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff) & 0x81010100) != 0) {
        if ((char)uVar2 == '\0') {
          *puVar5 = 0;
joined_r0x6f62bdb5:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_6f62bdb9:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_6f62bd4b;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x6f62bdb5;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x6f62bdb5;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x6f62bdb5;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x6f62bd0e:
    } while (uVar4 != 0);
    _Count = _Count & 3;
    if (_Count == 0) {
      return _Dest;
    }
  }
  do {
    cVar3 = (char)*(uint *)_Source;
    _Source = (char *)((int)_Source + 1);
    *(char *)puVar5 = cVar3;
    puVar5 = (uint *)((int)puVar5 + 1);
    if (cVar3 == '\0') {
      while (_Count = _Count - 1, _Count != 0) {
LAB_6f62bd4b:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}



// Function: FUN_6f62bdd0 at 6f62bdd0

DWORD __cdecl FUN_6f62bdd0(uint param_1,LONG param_2,DWORD param_3)

{
  undefined4 *puVar1;
  DWORD *pDVar2;
  DWORD DVar3;
  
  if ((param_1 < DAT_6f63e3e0) &&
     ((*(byte *)((&DAT_6f63e2e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_6f62fba0(param_1);
    DVar3 = FUN_6f62be60(param_1,param_2,param_3);
    __unlock_fhandle(param_1);
  }
  else {
    puVar1 = (undefined4 *)FUN_6f62ee40();
    *puVar1 = 9;
    pDVar2 = FUN_6f62ee50();
    *pDVar2 = 0;
    DVar3 = 0xffffffff;
  }
  return DVar3;
}



// Function: FUN_6f62be60 at 6f62be60

DWORD __cdecl FUN_6f62be60(uint param_1,LONG param_2,DWORD param_3)

{
  HANDLE hFile;
  undefined4 *puVar1;
  DWORD DVar2;
  ulong local_8;
  
  hFile = (HANDLE)FUN_6f62fa40(param_1);
  if (hFile == (HANDLE)0xffffffff) {
    puVar1 = (undefined4 *)FUN_6f62ee40();
    *puVar1 = 9;
    DVar2 = 0xffffffff;
  }
  else {
    DVar2 = SetFilePointer(hFile,param_2,(PLONG)0x0,param_3);
    if (DVar2 == 0xffffffff) {
      local_8 = GetLastError();
    }
    else {
      local_8 = 0;
    }
    if (local_8 == 0) {
      *(byte *)((&DAT_6f63e2e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) =
           *(byte *)((&DAT_6f63e2e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 0xfd;
    }
    else {
      __dosmaperr(local_8);
      DVar2 = 0xffffffff;
    }
  }
  return DVar2;
}



// Function: FUN_6f62bf20 at 6f62bf20

int __cdecl FUN_6f62bf20(uint param_1,char *param_2,uint param_3)

{
  undefined4 *puVar1;
  DWORD *pDVar2;
  int iVar3;
  
  if ((param_1 < DAT_6f63e3e0) &&
     ((*(byte *)((&DAT_6f63e2e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_6f62fba0(param_1);
    iVar3 = FUN_6f62bfb0(param_1,param_2,param_3);
    __unlock_fhandle(param_1);
  }
  else {
    puVar1 = (undefined4 *)FUN_6f62ee40();
    *puVar1 = 9;
    pDVar2 = FUN_6f62ee50();
    *pDVar2 = 0;
    iVar3 = -1;
  }
  return iVar3;
}



// Function: FUN_6f62bfb0 at 6f62bfb0

int __cdecl FUN_6f62bfb0(uint param_1,char *param_2,uint param_3)

{
  char cVar1;
  BOOL BVar2;
  undefined4 *puVar3;
  DWORD *pDVar4;
  int iVar5;
  int local_424;
  DWORD local_41c;
  char local_418 [1028];
  DWORD local_14;
  ulong local_10;
  char *local_c;
  char *local_8;
  
  local_14 = 0;
  local_424 = 0;
  if (param_3 == 0) {
    local_424 = 0;
  }
  else {
    iVar5 = (int)param_1 >> 5;
    if ((*(byte *)((&DAT_6f63e2e0)[iVar5] + 4 + (param_1 & 0x1f) * 0x24) & 0x20) != 0) {
      FUN_6f62be60(param_1,0,2);
    }
    if (((int)*(char *)((&DAT_6f63e2e0)[iVar5] + 4 + (param_1 & 0x1f) * 0x24) & 0x80U) == 0) {
      BVar2 = WriteFile(*(HANDLE *)((&DAT_6f63e2e0)[iVar5] + (param_1 & 0x1f) * 0x24),param_2,
                        param_3,&local_41c,(LPOVERLAPPED)0x0);
      if (BVar2 == 0) {
        local_10 = GetLastError();
      }
      else {
        local_10 = 0;
        local_14 = local_41c;
      }
    }
    else {
      local_8 = param_2;
      local_10 = 0;
      do {
        if (param_3 <= (uint)((int)local_8 - (int)param_2)) break;
        local_c = local_418;
        while (((int)local_c - (int)local_418 < 0x400 &&
               ((uint)((int)local_8 - (int)param_2) < param_3))) {
          cVar1 = *local_8;
          local_8 = local_8 + 1;
          if (cVar1 == '\n') {
            local_424 = local_424 + 1;
            *local_c = '\r';
            local_c = local_c + 1;
          }
          *local_c = cVar1;
          local_c = local_c + 1;
        }
        BVar2 = WriteFile(*(HANDLE *)((&DAT_6f63e2e0)[iVar5] + (param_1 & 0x1f) * 0x24),local_418,
                          (int)local_c - (int)local_418,&local_41c,(LPOVERLAPPED)0x0);
        if (BVar2 == 0) {
          local_10 = GetLastError();
          break;
        }
        local_14 = local_14 + local_41c;
      } while ((int)local_c - (int)local_418 <= (int)local_41c);
    }
    if (local_14 == 0) {
      if (local_10 == 0) {
        if (((*(byte *)((&DAT_6f63e2e0)[iVar5] + 4 + (param_1 & 0x1f) * 0x24) & 0x40) == 0) ||
           (*param_2 != '\x1a')) {
          puVar3 = (undefined4 *)FUN_6f62ee40();
          *puVar3 = 0x1c;
          pDVar4 = FUN_6f62ee50();
          *pDVar4 = 0;
          local_424 = -1;
        }
        else {
          local_424 = 0;
        }
      }
      else {
        if (local_10 == 5) {
          puVar3 = (undefined4 *)FUN_6f62ee40();
          *puVar3 = 9;
          pDVar4 = FUN_6f62ee50();
          *pDVar4 = local_10;
        }
        else {
          __dosmaperr(local_10);
        }
        local_424 = -1;
      }
    }
    else {
      local_424 = local_14 - local_424;
    }
  }
  return local_424;
}



// Function: FUN_6f62c230 at 6f62c230

void __cdecl FUN_6f62c230(undefined4 *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 == (undefined4 *)0x0) &&
     (iVar2 = FUN_6f625320(2,0x6f637ea8,0x2e,0,(byte *)"str != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  DAT_6f63d0d4 = DAT_6f63d0d4 + 1;
  uVar3 = FUN_6f627430((void *)0x1000,2,0x6f637ea8,0x3b);
  param_1[2] = uVar3;
  if (param_1[2] == 0) {
    param_1[3] = param_1[3] | 4;
    param_1[2] = param_1 + 5;
    param_1[6] = 2;
  }
  else {
    param_1[3] = param_1[3] | 8;
    param_1[6] = 0x1000;
  }
  *param_1 = param_1[2];
  param_1[1] = 0;
  return;
}



// Function: __isatty at 6f62c300

/* Library Function - Single Match
    __isatty
   
   Library: Visual Studio 2003 Debug */

int __cdecl __isatty(int _FileHandle)

{
  uint uVar1;
  
  if ((uint)_FileHandle < DAT_6f63e3e0) {
    uVar1 = (int)*(char *)((&DAT_6f63e2e0)[_FileHandle >> 5] + 4 + (_FileHandle & 0x1fU) * 0x24) &
            0x40;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_6f62c340 at 6f62c340

void FUN_6f62c340(void)

{
  uint local_8;
  
  if (DAT_6f63e2c0 == 0) {
    DAT_6f63e2c0 = 0x200;
  }
  else if (DAT_6f63e2c0 < 0x14) {
    DAT_6f63e2c0 = 0x14;
  }
  DAT_6f63d2b4 = __calloc_dbg(DAT_6f63e2c0,4,2,"_file.c",0x84);
  if (DAT_6f63d2b4 == (undefined1 *)0x0) {
    DAT_6f63e2c0 = 0x14;
    DAT_6f63d2b4 = __calloc_dbg(0x14,4,2,"_file.c",0x87);
    if (DAT_6f63d2b4 == (undefined1 *)0x0) {
      __amsg_exit(0x1a);
    }
  }
  for (local_8 = 0; (int)local_8 < 0x14; local_8 = local_8 + 1) {
    *(undefined ***)(DAT_6f63d2b4 + local_8 * 4) = &PTR_DAT_6f639b10 + local_8 * 8;
  }
  for (local_8 = 0; (int)local_8 < 3; local_8 = local_8 + 1) {
    if ((*(int *)((&DAT_6f63e2e0)[(int)local_8 >> 5] + (local_8 & 0x1f) * 0x24) == -1) ||
       (*(int *)((&DAT_6f63e2e0)[(int)local_8 >> 5] + (local_8 & 0x1f) * 0x24) == 0)) {
      *(undefined4 *)(&DAT_6f639b20 + local_8 * 0x20) = 0xffffffff;
    }
  }
  return;
}



// Function: FUN_6f62c470 at 6f62c470

void FUN_6f62c470(void)

{
  FUN_6f62fea0();
  if (DAT_6f63ce58 != '\0') {
    FUN_6f62fc60();
  }
  return;
}



// Function: FUN_6f62c490 at 6f62c490

int __cdecl FUN_6f62c490(LPSTR param_1,undefined2 param_2)

{
  LONG LVar1;
  undefined2 extraout_var;
  undefined2 uVar3;
  int iVar2;
  bool bVar4;
  
  LVar1 = InterlockedIncrement(&DAT_6f63d2b0);
  bVar4 = DAT_6f63d2ac == 0;
  uVar3 = (short)((uint)LVar1 >> 0x10);
  if (!bVar4) {
    InterlockedDecrement(&DAT_6f63d2b0);
    FUN_6f62c780(0x13);
    uVar3 = extraout_var;
  }
  iVar2 = FUN_6f62c510(param_1,CONCAT22(uVar3,param_2));
  if (bVar4) {
    InterlockedDecrement(&DAT_6f63d2b0);
  }
  else {
    FUN_6f62c820(0x13);
  }
  return iVar2;
}



// Function: FUN_6f62c510 at 6f62c510

int __cdecl FUN_6f62c510(LPSTR param_1,uint param_2)

{
  undefined4 *puVar1;
  BOOL local_c;
  int local_8;
  
  if (param_1 == (LPSTR)0x0) {
    local_8 = 0;
  }
  else if (DAT_6f63d150 == 0) {
    if ((param_2 & 0xffff) < 0x100) {
      *param_1 = (CHAR)param_2;
      local_8 = 1;
    }
    else {
      puVar1 = (undefined4 *)FUN_6f62ee40();
      *puVar1 = 0x2a;
      local_8 = -1;
    }
  }
  else {
    local_c = 0;
    local_8 = WideCharToMultiByte(DAT_6f63d160,0x220,(LPCWSTR)&param_2,1,param_1,DAT_6f6398f0,
                                  (LPCSTR)0x0,&local_c);
    if ((local_8 == 0) || (local_c != 0)) {
      puVar1 = (undefined4 *)FUN_6f62ee40();
      *puVar1 = 0x2a;
      local_8 = -1;
    }
  }
  return local_8;
}



// Function: __aulldiv at 6f62c5b0

/* Library Function - Single Match
    __aulldiv
   
   Library: Visual Studio */

undefined8 __aulldiv(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar3 = param_1;
  uVar8 = param_4;
  uVar6 = param_2;
  uVar9 = param_3;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    do {
      uVar5 = uVar8 >> 1;
      uVar9 = uVar9 >> 1 | (uint)((uVar8 & 1) != 0) << 0x1f;
      uVar7 = uVar6 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar6 & 1) != 0) << 0x1f;
      uVar8 = uVar5;
      uVar6 = uVar7;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar7,uVar3) / (ulonglong)uVar9;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar8 = uVar3 + iVar4 * param_4;
    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar8)) ||
       ((param_2 <= uVar8 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  return CONCAT44(uVar3,iVar4);
}



// Function: __aullrem at 6f62c620

/* Library Function - Single Match
    __aullrem
   
   Library: Visual Studio */

undefined8 __aullrem(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  
  uVar3 = param_1;
  uVar4 = param_4;
  uVar9 = param_2;
  uVar10 = param_3;
  if (param_4 == 0) {
    iVar6 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) %
                 (ulonglong)param_3);
    iVar7 = 0;
  }
  else {
    do {
      uVar5 = uVar4 >> 1;
      uVar10 = uVar10 >> 1 | (uint)((uVar4 & 1) != 0) << 0x1f;
      uVar8 = uVar9 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar9 & 1) != 0) << 0x1f;
      uVar4 = uVar5;
      uVar9 = uVar8;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar8,uVar3) / (ulonglong)uVar10;
    uVar3 = (int)uVar1 * param_4;
    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)param_3;
    uVar9 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar4 = (uint)lVar2;
    uVar10 = uVar9 + uVar3;
    if (((CARRY4(uVar9,uVar3)) || (param_2 < uVar10)) || ((param_2 <= uVar10 && (param_1 < uVar4))))
    {
      bVar11 = uVar4 < param_3;
      uVar4 = uVar4 - param_3;
      uVar10 = (uVar10 - param_4) - (uint)bVar11;
    }
    iVar6 = -(uVar4 - param_1);
    iVar7 = -(uint)(uVar4 - param_1 != 0) - ((uVar10 - param_2) - (uint)(uVar4 < param_1));
  }
  return CONCAT44(iVar7,iVar6);
}



// Function: FUN_6f62c6a0 at 6f62c6a0

void FUN_6f62c6a0(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_6f639dd4);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_6f639dc4);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_6f639db4);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_6f639d94);
  return;
}



// Function: FUN_6f62c6e0 at 6f62c6e0

void FUN_6f62c6e0(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 0x30; local_8 = local_8 + 1) {
    if ((((*(int *)(&DAT_6f639d90 + local_8 * 4) != 0) && (local_8 != 0x11)) && (local_8 != 0xd)) &&
       ((local_8 != 9 && (local_8 != 1)))) {
      DeleteCriticalSection(*(LPCRITICAL_SECTION *)(&DAT_6f639d90 + local_8 * 4));
      FUN_6f627ec0(*(void **)(&DAT_6f639d90 + local_8 * 4),2);
    }
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_6f639db4);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_6f639dc4);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_6f639dd4);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_6f639d94);
  return;
}



// Function: FUN_6f62c780 at 6f62c780

void __cdecl FUN_6f62c780(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (*(int *)(&DAT_6f639d90 + param_1 * 4) == 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)FUN_6f627430((void *)0x18,2,0x6f637ebc,0xe1);
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      __amsg_exit(0x11);
    }
    FUN_6f62c780(0x11);
    if (*(int *)(&DAT_6f639d90 + param_1 * 4) == 0) {
      InitializeCriticalSection(lpCriticalSection);
      *(LPCRITICAL_SECTION *)(&DAT_6f639d90 + param_1 * 4) = lpCriticalSection;
    }
    else {
      FUN_6f627ec0(lpCriticalSection,2);
    }
    FUN_6f62c820(0x11);
  }
  EnterCriticalSection(*(LPCRITICAL_SECTION *)(&DAT_6f639d90 + param_1 * 4));
  return;
}



// Function: FUN_6f62c820 at 6f62c820

void __cdecl FUN_6f62c820(int param_1)

{
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)(&DAT_6f639d90 + param_1 * 4));
  return;
}



// Function: FUN_6f62c840 at 6f62c840

void __cdecl FUN_6f62c840(undefined **param_1)

{
  if ((param_1 < &PTR_DAT_6f639b10) || (&DAT_6f639d70 < param_1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  }
  else {
    FUN_6f62c780(((int)(param_1 + -0x1bd8e6c4) >> 5) + 0x1c);
  }
  return;
}



// Function: FUN_6f62c880 at 6f62c880

void __cdecl FUN_6f62c880(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_6f62c780(param_1 + 0x1c);
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  }
  return;
}



// Function: FUN_6f62c8b0 at 6f62c8b0

void __cdecl FUN_6f62c8b0(undefined **param_1)

{
  if ((param_1 < &PTR_DAT_6f639b10) || (&DAT_6f639d70 < param_1)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  }
  else {
    FUN_6f62c820(((int)(param_1 + -0x1bd8e6c4) >> 5) + 0x1c);
  }
  return;
}



// Function: FUN_6f62c8f0 at 6f62c8f0

void __cdecl FUN_6f62c8f0(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_6f62c820(param_1 + 0x1c);
  }
  else {
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  }
  return;
}



// Function: FUN_6f62c920 at 6f62c920

void __cdecl FUN_6f62c920(LPCSTR param_1)

{
  FatalAppExitA(0,param_1);
                    /* WARNING: Subroutine does not return */
  ExitProcess(0xff);
}



// Function: __XcptFilter at 6f62c940

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __XcptFilter
   
   Library: Visual Studio 2003 Debug */

int __cdecl __XcptFilter(ulong _ExceptionNum,_EXCEPTION_POINTERS *_ExceptionPtr)

{
  code *pcVar1;
  DWORD DVar2;
  DWORD DVar3;
  DWORD *pDVar4;
  int *piVar5;
  int iVar6;
  int local_18;
  
  pDVar4 = FUN_6f626e90();
  piVar5 = FUN_6f62cb00(_ExceptionNum,(int *)pDVar4[0x14]);
  if ((piVar5 == (int *)0x0) || (piVar5[2] == 0)) {
    iVar6 = UnhandledExceptionFilter(_ExceptionPtr);
  }
  else if (piVar5[2] == 5) {
    piVar5[2] = 0;
    iVar6 = 1;
  }
  else if (piVar5[2] == 1) {
    iVar6 = -1;
  }
  else {
    pcVar1 = (code *)piVar5[2];
    DVar2 = pDVar4[0x15];
    pDVar4[0x15] = (DWORD)_ExceptionPtr;
    if (piVar5[1] == 8) {
      for (local_18 = DAT_6f639ec8; local_18 < DAT_6f639ec8 + _DAT_6f639ecc; local_18 = local_18 + 1
          ) {
        *(undefined4 *)(pDVar4[0x14] + 8 + local_18 * 0xc) = 0;
      }
      DVar3 = pDVar4[0x16];
      if (*piVar5 == -0x3fffff72) {
        pDVar4[0x16] = 0x83;
      }
      else if (*piVar5 == -0x3fffff70) {
        pDVar4[0x16] = 0x81;
      }
      else if (*piVar5 == -0x3fffff6f) {
        pDVar4[0x16] = 0x84;
      }
      else if (*piVar5 == -0x3fffff6d) {
        pDVar4[0x16] = 0x85;
      }
      else if (*piVar5 == -0x3fffff73) {
        pDVar4[0x16] = 0x82;
      }
      else if (*piVar5 == -0x3fffff71) {
        pDVar4[0x16] = 0x86;
      }
      else if (*piVar5 == -0x3fffff6e) {
        pDVar4[0x16] = 0x8a;
      }
      (*pcVar1)(8,pDVar4[0x16]);
      pDVar4[0x16] = DVar3;
    }
    else {
      piVar5[2] = 0;
      (*pcVar1)(piVar5[1]);
    }
    pDVar4[0x15] = DVar2;
    iVar6 = -1;
  }
  return iVar6;
}



// Function: FUN_6f62cb00 at 6f62cb00

int * __cdecl FUN_6f62cb00(int param_1,int *param_2)

{
  int *local_8;
  
  local_8 = param_2;
  do {
    if (*local_8 == param_1) break;
    local_8 = local_8 + 3;
  } while (local_8 < param_2 + DAT_6f639ed4 * 3);
  if ((param_2 + DAT_6f639ed4 * 3 <= local_8) || (*local_8 != param_1)) {
    local_8 = (int *)0x0;
  }
  return local_8;
}



// Function: _set_new_handler at 6f62cb60

/* Library Function - Single Match
    int (__cdecl*__cdecl _set_new_handler(int (__cdecl*)(unsigned int)))(unsigned int)
   
   Library: Visual Studio 2003 Debug */

_func_int_uint * __cdecl _set_new_handler(_func_int_uint *param_1)

{
  _func_int_uint *p_Var1;
  
  FUN_6f62c780(9);
  p_Var1 = DAT_6f63d13c;
  DAT_6f63d13c = param_1;
  FUN_6f62c820(9);
  return p_Var1;
}



// Function: FUN_6f62cb90 at 6f62cb90

undefined4 FUN_6f62cb90(void)

{
  return DAT_6f63d13c;
}



// Function: __callnewh at 6f62cba0

/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 2003 Debug */

int __cdecl __callnewh(size_t _Size)

{
  int iVar1;
  
  if ((DAT_6f63d13c != (code *)0x0) && (iVar1 = (*DAT_6f63d13c)(_Size), iVar1 != 0)) {
    return 1;
  }
  return 0;
}



// Function: FUN_6f62cbd0 at 6f62cbd0

void __cdecl FUN_6f62cbd0(void *param_1)

{
  FUN_6f62cbf0(param_1,DAT_6f63d138);
  return;
}



// Function: FUN_6f62cbf0 at 6f62cbf0

int * __cdecl FUN_6f62cbf0(void *param_1,int param_2)

{
  int iVar1;
  void *extraout_ECX;
  void *local_c;
  int *local_8;
  
  if (param_1 < (void *)0xffffffe1) {
    if (param_1 == (void *)0x0) {
      local_c = (void *)0x1;
      param_1 = local_c;
    }
    else {
      local_c = param_1;
    }
    do {
      if (local_c < (void *)0xffffffe1) {
        local_8 = FUN_6f62cc70(param_1,(int)local_c);
      }
      else {
        local_8 = (int *)0x0;
      }
      if (local_8 != (int *)0x0) {
        return local_8;
      }
      if (param_2 == 0) {
        return (int *)0x0;
      }
      iVar1 = __callnewh((size_t)local_c);
      param_1 = extraout_ECX;
    } while (iVar1 != 0);
  }
  return (int *)0x0;
}



// Function: FUN_6f62cc70 at 6f62cc70

int * __thiscall FUN_6f62cc70(void *this,int param_1)

{
  uint dwBytes;
  int *piVar1;
  
  dwBytes = param_1 + 0xfU & 0xfffffff0;
  if (dwBytes <= DAT_6f63bf04) {
    FUN_6f62c780(9);
    piVar1 = FUN_6f62d5c0(param_1 + 0xfU >> 4);
    FUN_6f62c820(9);
    if (piVar1 != (int *)0x0) {
      return piVar1;
    }
  }
  piVar1 = (int *)HeapAlloc(DAT_6f63e2c4,0,dwBytes);
  return piVar1;
}



// Function: FUN_6f62cce0 at 6f62cce0

undefined4 FUN_6f62cce0(void)

{
  return 1;
}



// Function: FUN_6f62ccf0 at 6f62ccf0

undefined * __cdecl FUN_6f62ccf0(undefined *param_1,uint param_2)

{
  int iVar1;
  int local_14;
  byte *local_10;
  undefined *local_c;
  uint *local_8;
  
  if (param_2 < 0xffffffe1) {
    if (param_2 == 0) {
      param_2 = 0x10;
    }
    else {
      param_2 = param_2 + 0xf & 0xfffffff0;
    }
    FUN_6f62c780(9);
    local_10 = (byte *)FUN_6f62d4c0(param_1,&local_14,(uint *)&local_8);
    if (local_10 == (byte *)0x0) {
      FUN_6f62c820(9);
      local_c = (undefined *)HeapReAlloc(DAT_6f63e2c4,0x10,param_1,param_2);
    }
    else {
      local_c = (undefined *)0x0;
      if (param_2 <= DAT_6f63bf04) {
        iVar1 = FUN_6f62dc30(local_14,local_8,local_10,param_2 >> 4);
        if (iVar1 != 0) {
          local_c = param_1;
        }
      }
      FUN_6f62c820(9);
    }
  }
  else {
    local_c = (undefined *)0x0;
  }
  return local_c;
}



// Function: FUN_6f62cdb0 at 6f62cdb0

int * __cdecl FUN_6f62cdb0(int *param_1,void *param_2)

{
  int *piVar1;
  int iVar2;
  void *local_20;
  void *local_1c;
  int local_18;
  void *local_14;
  byte *local_10;
  int *local_c;
  uint *local_8;
  
  if (param_1 == (int *)0x0) {
    piVar1 = (int *)FUN_6f62cbd0(param_2);
  }
  else if (param_2 == (void *)0x0) {
    FUN_6f62cfb0((undefined *)param_1);
    piVar1 = (int *)0x0;
  }
  else {
    if (param_2 < (void *)0xffffffe1) {
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x10;
      }
      else {
        param_2 = (void *)((int)param_2 + 0xfU & 0xfffffff0);
      }
    }
    do {
      local_c = (int *)0x0;
      if (param_2 < (void *)0xffffffe1) {
        FUN_6f62c780(9);
        local_10 = (byte *)FUN_6f62d4c0((undefined *)param_1,&local_18,(uint *)&local_8);
        if (local_10 == (byte *)0x0) {
          FUN_6f62c820(9);
          local_c = (int *)HeapReAlloc(DAT_6f63e2c4,0,param_1,(SIZE_T)param_2);
        }
        else {
          if (param_2 < DAT_6f63bf04) {
            iVar2 = FUN_6f62dc30(local_18,local_8,local_10,(uint)param_2 >> 4);
            if (iVar2 == 0) {
              local_c = FUN_6f62d5c0((uint)param_2 >> 4);
              if (local_c != (int *)0x0) {
                local_14 = (void *)((uint)*local_10 << 4);
                local_1c = local_14;
                if (param_2 <= local_14) {
                  local_1c = param_2;
                }
                FUN_6f62e010(local_c,param_1,(uint)local_1c);
                FUN_6f62d550(local_18,(int)local_8,local_10);
              }
            }
            else {
              local_c = param_1;
            }
          }
          if ((local_c == (int *)0x0) &&
             (local_c = (int *)HeapAlloc(DAT_6f63e2c4,0,(SIZE_T)param_2), local_c != (int *)0x0)) {
            local_14 = (void *)((uint)*local_10 << 4);
            local_20 = local_14;
            if (param_2 <= local_14) {
              local_20 = param_2;
            }
            FUN_6f62e010(local_c,param_1,(uint)local_20);
            FUN_6f62d550(local_18,(int)local_8,local_10);
          }
          FUN_6f62c820(9);
        }
      }
      if (local_c != (int *)0x0) {
        return local_c;
      }
      if (DAT_6f63d138 == 0) {
        return (int *)0x0;
      }
      iVar2 = __callnewh((size_t)param_2);
    } while (iVar2 != 0);
    piVar1 = (int *)0x0;
  }
  return piVar1;
}



// Function: FUN_6f62cfb0 at 6f62cfb0

void __cdecl FUN_6f62cfb0(undefined *param_1)

{
  int local_10;
  byte *local_c;
  uint local_8;
  
  if (param_1 != (undefined *)0x0) {
    FUN_6f62c780(9);
    local_c = (byte *)FUN_6f62d4c0(param_1,&local_10,&local_8);
    if (local_c == (byte *)0x0) {
      FUN_6f62c820(9);
      HeapFree(DAT_6f63e2c4,0,param_1);
    }
    else {
      FUN_6f62d550(local_10,local_8,local_c);
      FUN_6f62c820(9);
    }
  }
  return;
}



// Function: FUN_6f62d030 at 6f62d030

undefined4 FUN_6f62d030(void)

{
  int iVar1;
  BOOL BVar2;
  DWORD DVar3;
  DWORD *pDVar4;
  undefined4 *puVar5;
  undefined4 local_8;
  
  local_8 = 0xfffffffe;
  FUN_6f62c780(9);
  iVar1 = FUN_6f62dda0();
  if (iVar1 < 0) {
    local_8 = 0xfffffffc;
  }
  FUN_6f62c820(9);
  BVar2 = HeapValidate(DAT_6f63e2c4,0,(LPCVOID)0x0);
  if (BVar2 == 0) {
    DVar3 = GetLastError();
    if (DVar3 == 0x78) {
      pDVar4 = FUN_6f62ee50();
      *pDVar4 = 0x78;
      puVar5 = (undefined4 *)FUN_6f62ee40();
      *puVar5 = 0x28;
    }
    else {
      local_8 = 0xfffffffc;
    }
  }
  return local_8;
}



// Function: FUN_6f62d0b0 at 6f62d0b0

void FUN_6f62d0b0(void)

{
  FUN_6f62d030();
  return;
}



// Function: FUN_6f62d0c0 at 6f62d0c0

undefined4 FUN_6f62d0c0(void)

{
  return DAT_6f63bf04;
}



// Function: FUN_6f62d0d0 at 6f62d0d0

bool __cdecl FUN_6f62d0d0(int param_1)

{
  uint uVar1;
  
  uVar1 = param_1 + 0xfU & 0xfffffff0;
  if (uVar1 < 0x781) {
    DAT_6f63bf04 = uVar1;
  }
  return uVar1 < 0x781;
}



// Function: FUN_6f62d100 at 6f62d100

undefined ** FUN_6f62d100(void)

{
  LPVOID pvVar1;
  undefined **local_10;
  int local_c;
  undefined4 *local_8;
  
  if (DAT_6f639ef0 == -1) {
    local_10 = &PTR_LOOP_6f639ee0;
  }
  else {
    local_10 = (undefined **)HeapAlloc(DAT_6f63e2c4,0,0x2020);
    if (local_10 == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  local_8 = (undefined4 *)VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (local_8 != (undefined4 *)0x0) {
    pvVar1 = VirtualAlloc(local_8,0x10000,0x1000,4);
    if (pvVar1 != (LPVOID)0x0) {
      if (local_10 == &PTR_LOOP_6f639ee0) {
        if (PTR_LOOP_6f639ee0 == (undefined *)0x0) {
          PTR_LOOP_6f639ee0 = (undefined *)&PTR_LOOP_6f639ee0;
        }
        if (PTR_PTR_LOOP_6f639ee4 == (undefined *)0x0) {
          PTR_PTR_LOOP_6f639ee4 = (undefined *)&PTR_LOOP_6f639ee0;
        }
      }
      else {
        *local_10 = (undefined *)&PTR_LOOP_6f639ee0;
        local_10[1] = PTR_PTR_LOOP_6f639ee4;
        PTR_PTR_LOOP_6f639ee4 = (undefined *)local_10;
        *(undefined ***)local_10[1] = local_10;
      }
      local_10[4] = (undefined *)local_8;
      local_10[5] = (undefined *)(local_8 + 0x100000);
      local_10[2] = (undefined *)(local_10 + 6);
      local_10[3] = (undefined *)(local_10 + 0x26);
      for (local_c = 0; local_c < 0x400; local_c = local_c + 1) {
        if (local_c < 0x10) {
          local_10[local_c * 2 + 6] = (undefined *)0xf0;
        }
        else {
          local_10[local_c * 2 + 6] = (undefined *)0xffffffff;
        }
        local_10[local_c * 2 + 7] = (undefined *)0xf1;
      }
      _memset(local_8,0,0x10000);
      for (; local_8 < local_10[4] + 0x10000; local_8 = local_8 + 0x400) {
        *local_8 = local_8 + 2;
        local_8[1] = 0xf0;
        *(undefined1 *)(local_8 + 0x3e) = 0xff;
      }
      return local_10;
    }
    VirtualFree(local_8,0,0x8000);
  }
  if (local_10 != &PTR_LOOP_6f639ee0) {
    HeapFree(DAT_6f63e2c4,0,local_10);
  }
  return (undefined **)0x0;
}



// Function: FUN_6f62d2e0 at 6f62d2e0

void __cdecl FUN_6f62d2e0(undefined **param_1)

{
  VirtualFree(param_1[4],0,0x8000);
  if ((undefined **)PTR_PTR_LOOP_6f63bf00 == param_1) {
    PTR_PTR_LOOP_6f63bf00 = param_1[1];
  }
  if (param_1 == &PTR_LOOP_6f639ee0) {
    DAT_6f639ef0 = 0xffffffff;
  }
  else {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_6f63e2c4,0,param_1);
  }
  return;
}



// Function: FUN_6f62d360 at 6f62d360

void __cdecl FUN_6f62d360(int param_1)

{
  undefined **ppuVar1;
  BOOL BVar2;
  undefined **local_18;
  int local_14;
  int local_10;
  undefined **local_8;
  
  local_18 = (undefined **)PTR_PTR_LOOP_6f639ee4;
  do {
    ppuVar1 = local_18;
    if (local_18[4] != (undefined *)0xffffffff) {
      local_14 = 0;
      local_8 = local_18 + 0x804;
      for (local_10 = 0x3ff; -1 < local_10; local_10 = local_10 + -1) {
        if ((*local_8 == (undefined *)0xf0) &&
           (BVar2 = VirtualFree(local_18[4] + local_10 * 0x1000,0x1000,0x4000), BVar2 != 0)) {
          *local_8 = (undefined *)0xffffffff;
          DAT_6f63d140 = DAT_6f63d140 + -1;
          if ((local_18[3] == (undefined *)0x0) || (local_8 < local_18[3])) {
            local_18[3] = (undefined *)local_8;
          }
          local_14 = local_14 + 1;
          param_1 = param_1 + -1;
          if (param_1 == 0) break;
        }
        local_8 = local_8 + -2;
      }
      ppuVar1 = (undefined **)local_18[1];
      if ((local_14 != 0) && (local_18[6] == (undefined *)0xffffffff)) {
        local_10 = 1;
        for (local_8 = local_18 + 8; (local_10 < 0x400 && (*local_8 == (undefined *)0xffffffff));
            local_8 = local_8 + 2) {
          local_10 = local_10 + 1;
        }
        if (local_10 == 0x400) {
          FUN_6f62d2e0(local_18);
        }
      }
    }
    local_18 = ppuVar1;
    if ((local_18 == (undefined **)PTR_PTR_LOOP_6f639ee4) || (param_1 < 1)) {
      return;
    }
  } while( true );
}



// Function: FUN_6f62d4c0 at 6f62d4c0

int __cdecl FUN_6f62d4c0(undefined *param_1,undefined4 *param_2,uint *param_3)

{
  uint uVar1;
  undefined **local_c;
  
  local_c = &PTR_LOOP_6f639ee0;
  while ((param_1 <= local_c[4] || (local_c[5] <= param_1))) {
    local_c = (undefined **)*local_c;
    if (local_c == &PTR_LOOP_6f639ee0) {
      return 0;
    }
  }
  if ((((uint)param_1 & 0xf) == 0) && (0xff < ((uint)param_1 & 0xfff))) {
    *param_2 = local_c;
    uVar1 = (uint)param_1 & 0xfffff000;
    *param_3 = uVar1;
    return uVar1 + 8 + ((int)((int)param_1 - (uVar1 + 0x100)) >> 4);
  }
  return 0;
}



// Function: FUN_6f62d550 at 6f62d550

void __cdecl FUN_6f62d550(int param_1,int param_2,byte *param_3)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + 0x18 + (param_2 - *(int *)(param_1 + 0x10) >> 0xc) * 8);
  *piVar1 = *piVar1 + (uint)*param_3;
  *param_3 = 0;
  piVar1[1] = 0xf1;
  if ((*piVar1 == 0xf0) && (DAT_6f63d140 = DAT_6f63d140 + 1, DAT_6f63d140 == 0x20)) {
    FUN_6f62d360(0x10);
  }
  return;
}



// Function: FUN_6f62d5c0 at 6f62d5c0

int * __cdecl FUN_6f62d5c0(uint param_1)

{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  undefined **ppuVar4;
  undefined **local_24;
  int *local_20;
  int local_1c;
  int local_18;
  undefined **local_14;
  int *local_c;
  uint *local_8;
  
  local_24 = (undefined **)PTR_PTR_LOOP_6f63bf00;
  do {
    if (local_24[4] != (undefined *)0xffffffff) {
      local_8 = (uint *)local_24[2];
      local_c = (int *)((int)local_24[4] + ((int)local_8 - (int)(local_24 + 6) >> 3) * 0x1000);
      for (; local_8 < local_24 + 0x806; local_8 = local_8 + 2) {
        if (((int)param_1 <= (int)*local_8) && (param_1 < local_8[1])) {
          piVar2 = (int *)FUN_6f62d980(local_c,*local_8,param_1);
          if (piVar2 != (int *)0x0) {
            PTR_PTR_LOOP_6f63bf00 = (undefined *)local_24;
            *local_8 = *local_8 - param_1;
            local_24[2] = (undefined *)local_8;
            return piVar2;
          }
          local_8[1] = param_1;
        }
        local_c = local_c + 0x400;
      }
      puVar1 = (uint *)local_24[2];
      local_c = (int *)local_24[4];
      for (local_8 = (uint *)(local_24 + 6); local_8 < puVar1; local_8 = local_8 + 2) {
        if (((int)param_1 <= (int)*local_8) && (param_1 < local_8[1])) {
          piVar2 = (int *)FUN_6f62d980(local_c,*local_8,param_1);
          if (piVar2 != (int *)0x0) {
            PTR_PTR_LOOP_6f63bf00 = (undefined *)local_24;
            *local_8 = *local_8 - param_1;
            local_24[2] = (undefined *)local_8;
            return piVar2;
          }
          local_8[1] = param_1;
        }
        local_c = local_c + 0x400;
      }
    }
    local_24 = (undefined **)*local_24;
  } while (local_24 != (undefined **)PTR_PTR_LOOP_6f63bf00);
  local_24 = &PTR_LOOP_6f639ee0;
  while ((local_24[4] == (undefined *)0xffffffff || (local_24[3] == (undefined *)0x0))) {
    local_24 = (undefined **)*local_24;
    if (local_24 == &PTR_LOOP_6f639ee0) {
      ppuVar4 = FUN_6f62d100();
      if (ppuVar4 == (undefined **)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = (int *)ppuVar4[4];
        *(undefined1 *)(piVar2 + 2) = (undefined1)param_1;
        PTR_PTR_LOOP_6f63bf00 = (undefined *)ppuVar4;
        *piVar2 = (int)piVar2 + param_1 + 8;
        piVar2[1] = 0xf0 - param_1;
        ppuVar4[6] = ppuVar4[6] + -(param_1 & 0xff);
        piVar2 = piVar2 + 0x40;
      }
      return piVar2;
    }
  }
  ppuVar4 = (undefined **)local_24[3];
  piVar2 = (int *)(local_24[4] + ((int)ppuVar4 - (int)(local_24 + 6) >> 3) * 0x1000);
  local_14 = ppuVar4;
  for (local_18 = 0; (*local_14 == (undefined *)0xffffffff && (local_18 < 0x10));
      local_18 = local_18 + 1) {
    local_14 = local_14 + 2;
  }
  piVar3 = (int *)VirtualAlloc(piVar2,local_18 << 0xc,0x1000,4);
  if (piVar3 == piVar2) {
    _memset(piVar2,local_18 << 0xc,0);
    local_20 = piVar2;
    local_14 = ppuVar4;
    for (local_1c = 0; local_1c < local_18; local_1c = local_1c + 1) {
      *local_20 = (int)(local_20 + 2);
      local_20[1] = 0xf0;
      *(undefined1 *)(local_20 + 0x3e) = 0xff;
      *local_14 = (undefined *)0xf0;
      local_14[1] = (undefined *)0xf1;
      local_20 = local_20 + 0x400;
      local_14 = local_14 + 2;
    }
    PTR_PTR_LOOP_6f63bf00 = (undefined *)local_24;
    for (; (local_14 < local_24 + 0x806 && (*local_14 != (undefined *)0xffffffff));
        local_14 = local_14 + 2) {
    }
    local_24[3] = (undefined *)(-(uint)(local_14 < local_24 + 0x806) & (uint)local_14);
    *(undefined1 *)(piVar2 + 2) = (undefined1)param_1;
    local_24[2] = (undefined *)ppuVar4;
    *ppuVar4 = *ppuVar4 + -param_1;
    *piVar2 = (int)piVar2 + param_1 + 8;
    piVar2[1] = piVar2[1] - param_1;
    return piVar2 + 0x40;
  }
  return (int *)0x0;
}



// Function: FUN_6f62d980 at 6f62d980

int __cdecl FUN_6f62d980(int *param_1,uint param_2,uint param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  uint local_14;
  byte *local_10;
  byte *local_c;
  
  pbVar1 = (byte *)*param_1;
  pbVar2 = (byte *)(param_1 + 0x3e);
  if ((uint)param_1[1] < param_3) {
    local_c = pbVar1;
    if (pbVar1[param_1[1]] != 0) {
      local_c = pbVar1 + param_1[1];
    }
    while (local_c + param_3 < pbVar2) {
      if (*local_c == 0) {
        local_14 = 1;
        local_10 = local_c;
        while (local_10 = local_10 + 1, *local_10 == 0) {
          local_14 = local_14 + 1;
        }
        if (param_3 <= local_14) {
          if (local_c + param_3 < pbVar2) {
            *param_1 = (int)(local_c + param_3);
            param_1[1] = local_14 - param_3;
          }
          else {
            *param_1 = (int)(param_1 + 2);
            param_1[1] = 0;
          }
          *local_c = (byte)param_3;
          return (int)param_1 * -0xf + (int)local_c * 0x10 + 0x80;
        }
        if (local_c == pbVar1) {
          param_1[1] = local_14;
        }
        else {
          param_2 = param_2 - local_14;
          if (param_2 < param_3) {
            return 0;
          }
        }
        local_c = local_10;
      }
      else {
        local_c = local_c + *local_c;
      }
    }
    local_c = (byte *)(param_1 + 2);
    while ((local_c < pbVar1 && (local_c + param_3 < pbVar2))) {
      if (*local_c == 0) {
        local_14 = 1;
        local_10 = local_c;
        while (local_10 = local_10 + 1, *local_10 == 0) {
          local_14 = local_14 + 1;
        }
        if (param_3 <= local_14) {
          if (local_c + param_3 < pbVar2) {
            *param_1 = (int)(local_c + param_3);
            param_1[1] = local_14 - param_3;
          }
          else {
            *param_1 = (int)(param_1 + 2);
            param_1[1] = 0;
          }
          *local_c = (byte)param_3;
          return (int)param_1 * -0xf + (int)local_c * 0x10 + 0x80;
        }
        param_2 = param_2 - local_14;
        if (param_2 < param_3) {
          return 0;
        }
        local_c = local_10;
      }
      else {
        local_c = local_c + *local_c;
      }
    }
    iVar3 = 0;
  }
  else {
    *pbVar1 = (byte)param_3;
    if (pbVar1 + param_3 < pbVar2) {
      *param_1 = *param_1 + param_3;
      param_1[1] = param_1[1] - param_3;
    }
    else {
      *param_1 = (int)(param_1 + 2);
      param_1[1] = 0;
    }
    iVar3 = (int)param_1 * -0xf + (int)pbVar1 * 0x10 + 0x80;
  }
  return iVar3;
}



// Function: FUN_6f62dc30 at 6f62dc30

undefined4 __cdecl FUN_6f62dc30(int param_1,uint *param_2,byte *param_3,uint param_4)

{
  int *piVar1;
  uint uVar2;
  uint *local_1c;
  undefined4 local_18;
  uint *local_14;
  uint local_c;
  
  local_18 = 0;
  piVar1 = (int *)(param_1 + 0x18 + ((int)param_2 - *(int *)(param_1 + 0x10) >> 0xc) * 8);
  uVar2 = (uint)*param_3;
  if (param_4 < uVar2) {
    *param_3 = (byte)param_4;
    *piVar1 = *piVar1 + (uVar2 - param_4);
    piVar1[1] = 0xf1;
    local_18 = 1;
  }
  else if ((uVar2 < param_4) && (param_3 + param_4 <= param_2 + 0x3e)) {
    local_1c = (uint *)(param_3 + param_4);
    for (local_14 = (uint *)(param_3 + uVar2); (local_14 < local_1c && ((char)*local_14 == '\0'));
        local_14 = (uint *)((int)local_14 + 1)) {
    }
    if (local_14 == local_1c) {
      *param_3 = (byte)param_4;
      if ((param_3 <= (byte *)*param_2) && ((uint *)*param_2 < local_1c)) {
        if (local_1c < param_2 + 0x3e) {
          *param_2 = (uint)local_1c;
          local_c = 0;
          for (; (char)*local_1c == '\0'; local_1c = (uint *)((int)local_1c + 1)) {
            local_c = local_c + 1;
          }
          param_2[1] = local_c;
        }
        else {
          *param_2 = (uint)(param_2 + 2);
          param_2[1] = 0;
        }
      }
      *piVar1 = *piVar1 + (uVar2 - param_4);
      local_18 = 1;
    }
  }
  return local_18;
}



// Function: FUN_6f62dda0 at 6f62dda0

undefined4 FUN_6f62dda0(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int local_2c;
  undefined *local_28;
  int local_24;
  undefined **local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  local_c = 0;
  local_20 = &PTR_LOOP_6f639ee0;
  do {
    if ((undefined **)PTR_PTR_LOOP_6f63bf00 == local_20) {
      local_c = local_c + 1;
    }
    if (local_20[4] != (undefined *)0xffffffff) {
      local_10 = 0;
      local_2c = 0;
      local_8 = (int *)local_20[4];
      for (; local_10 < 0x400; local_10 = local_10 + 1) {
        if (local_20[local_10 * 2 + 6] == (undefined *)0xffffffff) {
          if ((local_2c == 0) && ((undefined **)local_20[3] != local_20 + local_10 * 2 + 6)) {
            return 0xffffffff;
          }
          local_2c = local_2c + 1;
        }
        else {
          if (local_8 + 0x3e <= (int *)*local_8) {
            return 0xfffffffe;
          }
          if ((char)local_8[0x3e] != -1) {
            return 0xfffffffd;
          }
          local_14 = 0;
          local_1c = 0;
          local_28 = (undefined *)0x0;
          local_24 = 0;
          while (local_14 < 0xf0) {
            if ((int)local_8 + local_14 + 8 == *local_8) {
              local_1c = local_1c + 1;
            }
            if (*(char *)((int)local_8 + local_14 + 8) == '\0') {
              local_28 = local_28 + 1;
              local_24 = local_24 + 1;
              local_14 = local_14 + 1;
            }
            else {
              if ((int)local_20[local_10 * 2 + 7] <= local_24) {
                return 0xfffffffc;
              }
              if (local_1c == 1) {
                if (local_24 < local_8[1]) {
                  return 0xfffffffb;
                }
                local_1c = 2;
              }
              local_24 = 0;
              iVar1 = local_14;
              while (local_18 = iVar1 + 1,
                    local_18 < (int)(local_14 + (uint)*(byte *)((int)local_8 + local_14 + 8))) {
                iVar2 = iVar1 + 9;
                iVar1 = local_18;
                if (*(char *)((int)local_8 + iVar2) != '\0') {
                  return 0xfffffffa;
                }
              }
              local_14 = local_18;
            }
          }
          if (local_28 != local_20[local_10 * 2 + 6]) {
            return 0xfffffff9;
          }
          if (local_1c == 0) {
            return 0xfffffff8;
          }
        }
        local_8 = local_8 + 0x400;
      }
    }
    local_20 = (undefined **)*local_20;
    if (local_20 == &PTR_LOOP_6f639ee0) {
      if (local_c == 0) {
        uVar3 = 0xfffffff7;
      }
      else {
        uVar3 = 0;
      }
      return uVar3;
    }
  } while( true );
}



// Function: FUN_6f62dfe0 at 6f62dfe0

int __cdecl FUN_6f62dfe0(short *param_1)

{
  short sVar1;
  short *local_8;
  
  local_8 = param_1;
  do {
    sVar1 = *local_8;
    local_8 = local_8 + 1;
  } while (sVar1 != 0);
  return ((int)local_8 - (int)param_1 >> 1) + -1;
}



// Function: FUN_6f62e010 at 6f62e010

undefined4 * __cdecl FUN_6f62e010(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((param_2 < param_1) && (param_1 < (undefined4 *)(param_3 + (int)param_2))) {
    puVar3 = (undefined4 *)((param_3 - 4) + (int)param_2);
    puVar4 = (undefined4 *)((param_3 - 4) + (int)param_1);
    if (((uint)puVar4 & 3) == 0) {
      uVar1 = param_3 >> 2;
      uVar2 = param_3 & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar2) {
        case 0:
          return param_1;
        case 2:
          goto switchD_6f62e1c7_caseD_2;
        case 3:
          goto switchD_6f62e1c7_caseD_3;
        }
        goto switchD_6f62e1c7_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_6f62e1c7_caseD_0;
      case 1:
        goto switchD_6f62e1c7_caseD_1;
      case 2:
        goto switchD_6f62e1c7_caseD_2;
      case 3:
        goto switchD_6f62e1c7_caseD_3;
      default:
        uVar1 = param_3 - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          puVar3 = (undefined4 *)((int)puVar3 + -1);
          uVar1 = uVar1 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_6f62e1c7_caseD_2;
            case 3:
              goto switchD_6f62e1c7_caseD_3;
            }
            goto switchD_6f62e1c7_caseD_1;
          }
          break;
        case 2:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          puVar3 = (undefined4 *)((int)puVar3 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_6f62e1c7_caseD_2;
            case 3:
              goto switchD_6f62e1c7_caseD_3;
            }
            goto switchD_6f62e1c7_caseD_1;
          }
          break;
        case 3:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_6f62e1c7_caseD_2;
            case 3:
              goto switchD_6f62e1c7_caseD_3;
            }
            goto switchD_6f62e1c7_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar4[7 - uVar1] = puVar3[7 - uVar1];
    case 6:
      puVar4[6 - uVar1] = puVar3[6 - uVar1];
    case 5:
      puVar4[5 - uVar1] = puVar3[5 - uVar1];
    case 4:
      puVar4[4 - uVar1] = puVar3[4 - uVar1];
    case 3:
      puVar4[3 - uVar1] = puVar3[3 - uVar1];
    case 2:
      puVar4[2 - uVar1] = puVar3[2 - uVar1];
    case 1:
      puVar4[1 - uVar1] = puVar3[1 - uVar1];
      puVar3 = puVar3 + -uVar1;
      puVar4 = puVar4 + -uVar1;
    }
    switch(uVar2) {
    case 1:
switchD_6f62e1c7_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_6f62e1c7_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_6f62e1c7_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_6f62e1c7_caseD_0:
    return param_1;
  }
  puVar3 = param_1;
  if (((uint)param_1 & 3) == 0) {
    uVar1 = param_3 >> 2;
    uVar2 = param_3 & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *param_2;
        param_2 = param_2 + 1;
        puVar3 = puVar3 + 1;
      }
      switch(uVar2) {
      case 0:
        return param_1;
      case 2:
        goto switchD_6f62e045_caseD_2;
      case 3:
        goto switchD_6f62e045_caseD_3;
      }
      goto switchD_6f62e045_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_6f62e045_caseD_0;
    case 1:
      goto switchD_6f62e045_caseD_1;
    case 2:
      goto switchD_6f62e045_caseD_2;
    case 3:
      goto switchD_6f62e045_caseD_3;
    default:
      uVar1 = (param_3 - 4) + ((uint)param_1 & 3);
      switch((uint)param_1 & 3) {
      case 1:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);
        param_2 = (undefined4 *)((int)param_2 + 3);
        puVar3 = (undefined4 *)((int)param_1 + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_6f62e045_caseD_2;
          case 3:
            goto switchD_6f62e045_caseD_3;
          }
          goto switchD_6f62e045_caseD_1;
        }
        break;
      case 2:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        param_2 = (undefined4 *)((int)param_2 + 2);
        puVar3 = (undefined4 *)((int)param_1 + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_6f62e045_caseD_2;
          case 3:
            goto switchD_6f62e045_caseD_3;
          }
          goto switchD_6f62e045_caseD_1;
        }
        break;
      case 3:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        puVar3 = (undefined4 *)((int)param_1 + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_6f62e045_caseD_2;
          case 3:
            goto switchD_6f62e045_caseD_3;
          }
          goto switchD_6f62e045_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar3[uVar1 - 7] = param_2[uVar1 - 7];
  case 6:
    puVar3[uVar1 - 6] = param_2[uVar1 - 6];
  case 5:
    puVar3[uVar1 - 5] = param_2[uVar1 - 5];
  case 4:
    puVar3[uVar1 - 4] = param_2[uVar1 - 4];
  case 3:
    puVar3[uVar1 - 3] = param_2[uVar1 - 3];
  case 2:
    puVar3[uVar1 - 2] = param_2[uVar1 - 2];
  case 1:
    puVar3[uVar1 - 1] = param_2[uVar1 - 1];
    param_2 = param_2 + uVar1;
    puVar3 = puVar3 + uVar1;
  }
  switch(uVar2) {
  case 1:
switchD_6f62e045_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_6f62e045_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_6f62e045_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_6f62e045_caseD_0:
  return param_1;
}



// Function: __fptrap at 6f62e350

/* Library Function - Single Match
    __fptrap
   
   Library: Visual Studio 2003 Debug */

void __cdecl __fptrap(void)

{
  __amsg_exit(2);
  return;
}



// Function: FUN_6f62e360 at 6f62e360

uint * __cdecl FUN_6f62e360(int param_1,uint *param_2)

{
  char *pcVar1;
  int iVar2;
  size_t sVar3;
  size_t sVar4;
  uint *local_b4;
  uint *local_b0;
  uint *local_ac;
  uint *local_a0;
  uint local_9c [33];
  int local_18;
  int local_14;
  int local_10;
  uint *local_c;
  int local_8;
  
  if ((param_1 < 0) || (5 < param_1)) {
    local_c = (uint *)0x0;
  }
  else {
    FUN_6f62c780(0x13);
    local_8 = 1;
    DAT_6f63d2ac = DAT_6f63d2ac + 1;
    while (DAT_6f63d2b0 != 0) {
      Sleep(1);
    }
    if (param_1 == 0) {
      local_18 = 1;
      local_10 = 0;
      if (param_2 == (uint *)0x0) {
        local_c = FUN_6f62e8e0();
      }
      else if ((((char)*param_2 == 'L') && (*(char *)((int)param_2 + 1) == 'C')) &&
              (*(char *)((int)param_2 + 2) == '_')) {
        local_a0 = param_2;
        do {
          pcVar1 = _strpbrk((char *)local_a0,"=;");
          if (((pcVar1 == (char *)0x0) || (sVar4 = (int)pcVar1 - (int)local_a0, sVar4 == 0)) ||
             (*pcVar1 == ';')) {
            if (local_8 != 0) {
              FUN_6f62c820(0x13);
              DAT_6f63d2ac = DAT_6f63d2ac + -1;
            }
            return (uint *)0x0;
          }
          local_14 = 1;
          while ((local_14 < 6 &&
                 ((iVar2 = _strncmp(*(char **)(local_14 * 0xc + 0x6f63bf18),(char *)local_a0,sVar4),
                  iVar2 != 0 ||
                  (sVar3 = _strlen(*(char **)(local_14 * 0xc + 0x6f63bf18)), sVar4 != sVar3))))) {
            local_14 = local_14 + 1;
          }
          pcVar1 = pcVar1 + 1;
          sVar4 = _strcspn(pcVar1,";");
          if ((sVar4 == 0) && (*pcVar1 != ';')) {
            if (local_8 != 0) {
              FUN_6f62c820(0x13);
              DAT_6f63d2ac = DAT_6f63d2ac + -1;
            }
            return (uint *)0x0;
          }
          if (local_14 < 6) {
            _strncpy((char *)local_9c,pcVar1,sVar4);
            *(undefined1 *)((int)local_9c + sVar4) = 0;
            iVar2 = FUN_6f62e750(local_14,local_9c);
            if (iVar2 != 0) {
              local_10 = local_10 + 1;
            }
          }
          local_a0 = (uint *)(pcVar1 + sVar4);
          if ((char)*local_a0 != '\0') {
            local_a0 = (uint *)((int)local_a0 + 1);
          }
        } while ((char)*local_a0 != '\0');
        if (local_10 == 0) {
          local_b0 = (uint *)0x0;
        }
        else {
          local_b0 = FUN_6f62e8e0();
        }
        local_c = local_b0;
      }
      else {
        local_c = FUN_6f62e9e0(param_2,local_9c,(undefined4 *)0x0,(undefined4 *)0x0);
        if (local_c != (uint *)0x0) {
          for (local_14 = 0; local_14 < 6; local_14 = local_14 + 1) {
            if (local_14 != 0) {
              iVar2 = _strcmp((char *)local_9c,(char *)(&DAT_6f63bf1c)[local_14 * 3]);
              if (iVar2 == 0) {
                local_10 = local_10 + 1;
              }
              else {
                iVar2 = FUN_6f62e750(local_14,local_9c);
                if (iVar2 == 0) {
                  local_18 = 0;
                }
                else {
                  local_10 = local_10 + 1;
                }
              }
            }
          }
          if (local_18 == 0) {
            if (local_10 == 0) {
              local_b4 = (uint *)0x0;
            }
            else {
              local_b4 = FUN_6f62e8e0();
            }
            local_c = local_b4;
          }
          else {
            local_c = FUN_6f62e8e0();
            FUN_6f627ec0(DAT_6f63bf1c,2);
            DAT_6f63bf1c = (void *)0x0;
          }
        }
      }
    }
    else {
      if (param_2 == (uint *)0x0) {
        local_ac = (uint *)(&DAT_6f63bf1c)[param_1 * 3];
      }
      else {
        local_ac = (uint *)FUN_6f62e750(param_1,param_2);
      }
      local_c = local_ac;
    }
    if (local_8 != 0) {
      FUN_6f62c820(0x13);
      DAT_6f63d2ac = DAT_6f63d2ac + -1;
    }
  }
  return local_c;
}



// Function: FUN_6f62e750 at 6f62e750

undefined4 __cdecl FUN_6f62e750(int param_1,uint *param_2)

{
  uint *puVar1;
  undefined4 uVar2;
  size_t sVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  uint local_ac [2];
  undefined4 local_a4;
  uint local_a0 [33];
  undefined4 local_1c;
  undefined4 local_18 [2];
  undefined *local_10;
  uint *local_c;
  undefined4 local_8;
  
  puVar1 = FUN_6f62e9e0(param_2,local_a0,local_ac,&local_a4);
  if (puVar1 == (uint *)0x0) {
    uVar2 = 0;
  }
  else {
    iVar6 = 0x134;
    pcVar5 = "setlocal.c";
    uVar4 = 2;
    sVar3 = _strlen((char *)local_a0);
    local_c = (uint *)FUN_6f627430((void *)(sVar3 + 1),uVar4,(int)pcVar5,iVar6);
    if (local_c == (uint *)0x0) {
      uVar2 = 0;
    }
    else {
      local_10 = (undefined *)(&DAT_6f63bf1c)[param_1 * 3];
      local_8 = *(undefined4 *)(&DAT_6f63d148 + param_1 * 4);
      FUN_6f62e010(local_18,(undefined4 *)(&DAT_6f63d198 + param_1 * 6),6);
      local_1c = DAT_6f63d160;
      puVar1 = FUN_6f6235b0(local_c,local_a0);
      (&DAT_6f63bf1c)[param_1 * 3] = puVar1;
      *(uint *)(&DAT_6f63d148 + param_1 * 4) = local_ac[0] & 0xffff;
      FUN_6f62e010((undefined4 *)(&DAT_6f63d198 + param_1 * 6),local_ac,6);
      if (param_1 == 2) {
        DAT_6f63d160 = local_a4;
      }
      iVar6 = (**(code **)(&DAT_6f63bf20 + param_1 * 0xc))();
      if (iVar6 == 0) {
        if (local_10 != &DAT_6f63bf10) {
          FUN_6f627ec0(local_10,2);
        }
        uVar2 = (&DAT_6f63bf1c)[param_1 * 3];
      }
      else {
        (&DAT_6f63bf1c)[param_1 * 3] = local_10;
        FUN_6f627ec0(local_c,2);
        *(undefined4 *)(&DAT_6f63d148 + param_1 * 4) = local_8;
        DAT_6f63d160 = local_1c;
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}



// Function: FUN_6f62e8e0 at 6f62e8e0

uint * FUN_6f62e8e0(void)

{
  bool bVar1;
  int iVar2;
  uint *puVar3;
  int local_8;
  
  bVar1 = true;
  if (DAT_6f63bf1c == (uint *)0x0) {
    DAT_6f63bf1c = (uint *)FUN_6f627430((void *)0x351,2,0x6f637f0c,0x166);
  }
  *(undefined1 *)DAT_6f63bf1c = 0;
  for (local_8 = 1; __strcats(DAT_6f63bf1c,3), local_8 < 5; local_8 = local_8 + 1) {
    FUN_6f6235c0(DAT_6f63bf1c,(uint *)&DAT_6f637f04);
    iVar2 = _strcmp((char *)(&DAT_6f63bf1c)[local_8 * 3],(char *)(&DAT_6f63bf1c)[(local_8 + 1) * 3])
    ;
    if (iVar2 != 0) {
      bVar1 = false;
    }
  }
  puVar3 = DAT_6f63bf1c;
  if (bVar1) {
    FUN_6f627ec0(DAT_6f63bf1c,2);
    DAT_6f63bf1c = (uint *)0x0;
    puVar3 = (uint *)PTR_DAT_6f63bf34;
  }
  return puVar3;
}



// Function: FUN_6f62e9e0 at 6f62e9e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * __cdecl FUN_6f62e9e0(uint *param_1,uint *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  uint local_8c [34];
  
  if (param_1 == (uint *)0x0) {
    param_2 = (uint *)0x0;
  }
  else if (((char)*param_1 == 'C') && (*(char *)((int)param_1 + 1) == '\0')) {
    *(undefined1 *)param_2 = 0x43;
    *(undefined1 *)((int)param_2 + 1) = 0;
    if (param_3 != (undefined4 *)0x0) {
      *(undefined2 *)param_3 = 0;
      *(undefined2 *)((int)param_3 + 2) = 0;
      *(undefined2 *)(param_3 + 1) = 0;
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0;
    }
  }
  else {
    iVar1 = _strcmp(&DAT_6f63bfe8,(char *)param_1);
    if ((iVar1 != 0) && (iVar1 = _strcmp(&DAT_6f63bf60,(char *)param_1), iVar1 != 0)) {
      iVar1 = FUN_6f62ebd0((char *)local_8c,(char *)param_1);
      if (iVar1 != 0) {
        return (uint *)0x0;
      }
      iVar1 = FUN_6f631730((byte *)local_8c,(undefined4 *)&DAT_6f63d164,(LPSTR)local_8c);
      if (iVar1 == 0) {
        return (uint *)0x0;
      }
      _DAT_6f63d16c = (uint)DAT_6f63d168;
      ___lc_lctostr((uint *)&DAT_6f63bfe8,local_8c);
      if ((char)*param_1 == '\0') {
        FUN_6f6235b0((uint *)&DAT_6f63bf60,(uint *)&DAT_6f63bfe8);
      }
      else {
        FUN_6f6235b0((uint *)&DAT_6f63bf60,param_1);
      }
    }
    if (param_3 != (undefined4 *)0x0) {
      FUN_6f62e010(param_3,(undefined4 *)&DAT_6f63d164,6);
    }
    if (param_4 != (undefined4 *)0x0) {
      FUN_6f62e010(param_4,(undefined4 *)&DAT_6f63d16c,4);
    }
    FUN_6f6235b0(param_2,(uint *)&DAT_6f63bfe8);
    param_2 = (uint *)&DAT_6f63bfe8;
  }
  return param_2;
}



// Function: FUN_6f62eb70 at 6f62eb70

undefined4 FUN_6f62eb70(void)

{
  return 0;
}



// Function: __strcats at 6f62eb80

/* Library Function - Single Match
    __strcats
   
   Library: Visual Studio 2003 Debug */

void __cdecl __strcats(uint *param_1,int param_2)

{
  int local_c;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)&stack0x0000000c;
  for (local_c = 0; local_c < param_2; local_c = local_c + 1) {
    FUN_6f6235c0(param_1,(uint *)*local_8);
    local_8 = local_8 + 1;
  }
  return;
}



// Function: FUN_6f62ebd0 at 6f62ebd0

undefined4 __cdecl FUN_6f62ebd0(char *param_1,char *param_2)

{
  char cVar1;
  undefined4 uVar2;
  size_t _Count;
  int local_8;
  
  _memset(param_1,0,0x85);
  if (*param_2 == '\0') {
    uVar2 = 0;
  }
  else if ((*param_2 == '.') && (param_2[1] != '\0')) {
    FUN_6f6235b0((uint *)(param_1 + 0x80),(uint *)(param_2 + 1));
    uVar2 = 0;
  }
  else {
    local_8 = 0;
    while (_Count = _strcspn(param_2,"_.,"), _Count != 0) {
      cVar1 = param_2[_Count];
      if (((local_8 == 0) && ((int)_Count < 0x40)) && (cVar1 != '.')) {
        _strncpy(param_1,param_2,_Count);
      }
      else if (((local_8 == 1) && ((int)_Count < 0x40)) && (cVar1 != '_')) {
        _strncpy(param_1 + 0x40,param_2,_Count);
      }
      else {
        if ((local_8 != 2) || ((cVar1 != '\0' && (cVar1 != ',')))) {
          return 0xffffffff;
        }
        _strncpy(param_1 + 0x80,param_2,_Count);
      }
      if ((cVar1 == ',') || (cVar1 == '\0')) {
        return 0;
      }
      param_2 = param_2 + _Count + 1;
      local_8 = local_8 + 1;
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



// Function: ___lc_lctostr at 6f62ed30

/* Library Function - Single Match
    ___lc_lctostr
   
   Library: Visual Studio 2003 Debug */

void __cdecl ___lc_lctostr(uint *param_1,uint *param_2)

{
  FUN_6f6235b0(param_1,param_2);
  if ((char)param_2[0x10] != '\0') {
    __strcats(param_1,2);
  }
  if ((char)param_2[0x20] != '\0') {
    __strcats(param_1,2);
  }
  return;
}



// Function: __dosmaperr at 6f62eda0

/* Library Function - Single Match
    __dosmaperr
   
   Library: Visual Studio 2003 Debug */

void __cdecl __dosmaperr(ulong param_1)

{
  DWORD *pDVar1;
  undefined4 *puVar2;
  uint local_8;
  
  pDVar1 = FUN_6f62ee50();
  *pDVar1 = param_1;
  local_8 = 0;
  while( true ) {
    if (0x2c < local_8) {
      if ((param_1 < 0x13) || (0x24 < param_1)) {
        if ((param_1 < 0xbc) || (0xca < param_1)) {
          puVar2 = (undefined4 *)FUN_6f62ee40();
          *puVar2 = 0x16;
        }
        else {
          puVar2 = (undefined4 *)FUN_6f62ee40();
          *puVar2 = 8;
        }
      }
      else {
        puVar2 = (undefined4 *)FUN_6f62ee40();
        *puVar2 = 0xd;
      }
      return;
    }
    if (param_1 == *(ulong *)(&DAT_6f63c070 + local_8 * 8)) break;
    local_8 = local_8 + 1;
  }
  puVar2 = (undefined4 *)FUN_6f62ee40();
  *puVar2 = *(undefined4 *)(&DAT_6f63c074 + local_8 * 8);
  return;
}



// Function: FUN_6f62ee40 at 6f62ee40

int FUN_6f62ee40(void)

{
  DWORD *pDVar1;
  
  pDVar1 = FUN_6f626e90();
  return (int)(pDVar1 + 2);
}



// Function: FUN_6f62ee50 at 6f62ee50

DWORD * FUN_6f62ee50(void)

{
  DWORD *pDVar1;
  
  pDVar1 = FUN_6f626e90();
  return pDVar1 + 3;
}



// Function: FUN_6f62ee60 at 6f62ee60

void __cdecl
FUN_6f62ee60(DWORD param_1,LPCWSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6)

{
  BOOL BVar1;
  int cbMultiByte;
  LPCSTR lpMultiByteStr;
  int iVar2;
  LPWORD local_10;
  WORD local_8 [2];
  
  if (DAT_6f63d170 == 0) {
    BVar1 = GetStringTypeW(1,L"",1,local_8);
    if (BVar1 == 0) {
      BVar1 = GetStringTypeA(0,1,"",1,local_8);
      if (BVar1 == 0) {
        return;
      }
      DAT_6f63d170 = 2;
    }
    else {
      DAT_6f63d170 = 1;
    }
  }
  if (DAT_6f63d170 == 1) {
    GetStringTypeW(param_1,param_2,param_3,param_4);
  }
  else if (DAT_6f63d170 == 2) {
    local_10 = (LPWORD)0x0;
    if (param_5 == 0) {
      param_5 = DAT_6f63d160;
    }
    cbMultiByte = WideCharToMultiByte(param_5,0x220,param_2,param_3,(LPSTR)0x0,0,(LPCSTR)0x0,
                                      (LPBOOL)0x0);
    if ((cbMultiByte != 0) &&
       (lpMultiByteStr = __calloc_dbg(1,cbMultiByte,2,"aw_str.c",0x76),
       lpMultiByteStr != (LPCSTR)0x0)) {
      iVar2 = WideCharToMultiByte(param_5,0x220,param_2,param_3,lpMultiByteStr,cbMultiByte,
                                  (LPCSTR)0x0,(LPBOOL)0x0);
      if ((iVar2 != 0) &&
         (local_10 = (LPWORD)FUN_6f627430((void *)(cbMultiByte * 2 + 2),2,0x6f637f28,0x80),
         local_10 != (LPWORD)0x0)) {
        if (param_6 == 0) {
          param_6 = DAT_6f63d150;
        }
        local_10[param_3] = 0xffff;
        local_10[param_3 + -1] = 0xffff;
        GetStringTypeA(param_6,param_1,lpMultiByteStr,cbMultiByte,local_10);
        if ((local_10[param_3 + -1] != 0xffff) && (local_10[param_3] == 0xffff)) {
          FUN_6f631dd0((undefined4 *)param_4,(undefined4 *)local_10,param_3 << 1);
        }
      }
      FUN_6f627ec0(lpMultiByteStr,2);
      FUN_6f627ec0(local_10,2);
    }
  }
  return;
}



// Function: FUN_6f62f070 at 6f62f070

void __cdecl
FUN_6f62f070(DWORD param_1,LPCSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6)

{
  BOOL BVar1;
  int iVar2;
  LPCWSTR local_14;
  WORD local_8 [2];
  
  if (DAT_6f63d174 == 0) {
    BVar1 = GetStringTypeA(0,1,"",1,local_8);
    if (BVar1 == 0) {
      BVar1 = GetStringTypeW(1,L"",1,local_8);
      if (BVar1 == 0) {
        return;
      }
      DAT_6f63d174 = 1;
    }
    else {
      DAT_6f63d174 = 2;
    }
  }
  if (DAT_6f63d174 == 2) {
    if (param_6 == 0) {
      param_6 = DAT_6f63d150;
    }
    GetStringTypeA(param_6,param_1,param_2,param_3,param_4);
  }
  else if (DAT_6f63d174 == 1) {
    local_14 = (LPCWSTR)0x0;
    if (param_5 == 0) {
      param_5 = DAT_6f63d160;
    }
    iVar2 = MultiByteToWideChar(param_5,9,param_2,param_3,(LPWSTR)0x0,0);
    if (((iVar2 != 0) &&
        (local_14 = (LPCWSTR)__calloc_dbg(2,iVar2,2,"aw_str.c",0x104), local_14 != (LPCWSTR)0x0)) &&
       (iVar2 = MultiByteToWideChar(param_5,1,param_2,param_3,local_14,iVar2), iVar2 != 0)) {
      GetStringTypeW(param_1,local_14,iVar2,param_4);
    }
    FUN_6f627ec0(local_14,2);
  }
  return;
}



// Function: FUN_6f62f1d0 at 6f62f1d0

int __cdecl FUN_6f62f1d0(uint param_1,char *param_2,DWORD param_3)

{
  undefined4 *puVar1;
  DWORD *pDVar2;
  int iVar3;
  
  if ((param_1 < DAT_6f63e3e0) &&
     ((*(byte *)((&DAT_6f63e2e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_6f62fba0(param_1);
    iVar3 = FUN_6f62f260(param_1,param_2,param_3);
    __unlock_fhandle(param_1);
  }
  else {
    puVar1 = (undefined4 *)FUN_6f62ee40();
    *puVar1 = 9;
    pDVar2 = FUN_6f62ee50();
    *pDVar2 = 0;
    iVar3 = -1;
  }
  return iVar3;
}



// Function: FUN_6f62f260 at 6f62f260

int __cdecl FUN_6f62f260(uint param_1,char *param_2,DWORD param_3)

{
  BOOL BVar1;
  undefined4 *puVar2;
  DWORD *pDVar3;
  int iVar4;
  char local_20 [4];
  int local_1c;
  char *local_18;
  DWORD local_14;
  char *local_10;
  DWORD local_c;
  char *local_8;
  
  local_1c = 0;
  local_18 = param_2;
  if ((param_3 == 0) ||
     (iVar4 = (int)param_1 >> 5,
     (*(byte *)((&DAT_6f63e2e0)[iVar4] + 4 + (param_1 & 0x1f) * 0x24) & 2) != 0)) {
    local_1c = 0;
  }
  else {
    if (((*(byte *)((&DAT_6f63e2e0)[iVar4] + 4 + (param_1 & 0x1f) * 0x24) & 0x48) != 0) &&
       (*(char *)((&DAT_6f63e2e0)[iVar4] + 5 + (param_1 & 0x1f) * 0x24) != '\n')) {
      *param_2 = *(char *)((&DAT_6f63e2e0)[iVar4] + 5 + (param_1 & 0x1f) * 0x24);
      local_18 = param_2 + 1;
      local_1c = 1;
      param_3 = param_3 - 1;
      *(undefined1 *)((&DAT_6f63e2e0)[iVar4] + 5 + (param_1 & 0x1f) * 0x24) = 10;
    }
    BVar1 = ReadFile(*(HANDLE *)((&DAT_6f63e2e0)[iVar4] + (param_1 & 0x1f) * 0x24),local_18,param_3,
                     &local_14,(LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      local_c = GetLastError();
      if (local_c == 5) {
        puVar2 = (undefined4 *)FUN_6f62ee40();
        *puVar2 = 9;
        pDVar3 = FUN_6f62ee50();
        *pDVar3 = local_c;
        local_1c = -1;
      }
      else if (local_c == 0x6d) {
        local_1c = 0;
      }
      else {
        __dosmaperr(local_c);
        local_1c = -1;
      }
    }
    else {
      local_1c = local_1c + local_14;
      if (((int)*(char *)((&DAT_6f63e2e0)[iVar4] + 4 + (param_1 & 0x1f) * 0x24) & 0x80U) != 0) {
        if ((local_14 == 0) || (*param_2 != '\n')) {
          *(byte *)((&DAT_6f63e2e0)[iVar4] + 4 + (param_1 & 0x1f) * 0x24) =
               *(byte *)((&DAT_6f63e2e0)[iVar4] + 4 + (param_1 & 0x1f) * 0x24) & 0xfb;
        }
        else {
          *(byte *)((&DAT_6f63e2e0)[iVar4] + 4 + (param_1 & 0x1f) * 0x24) =
               *(byte *)((&DAT_6f63e2e0)[iVar4] + 4 + (param_1 & 0x1f) * 0x24) | 4;
        }
        local_10 = param_2;
        local_8 = param_2;
        while (local_8 < param_2 + local_1c) {
          if (*local_8 == '\x1a') {
            if ((*(byte *)((&DAT_6f63e2e0)[iVar4] + 4 + (param_1 & 0x1f) * 0x24) & 0x40) == 0) {
              *(byte *)((&DAT_6f63e2e0)[iVar4] + 4 + (param_1 & 0x1f) * 0x24) =
                   *(byte *)((&DAT_6f63e2e0)[iVar4] + 4 + (param_1 & 0x1f) * 0x24) | 2;
            }
            break;
          }
          if (*local_8 == '\r') {
            if (local_8 < param_2 + local_1c + -1) {
              if (local_8[1] == '\n') {
                local_8 = local_8 + 2;
                *local_10 = '\n';
              }
              else {
                *local_10 = *local_8;
                local_8 = local_8 + 1;
              }
              local_10 = local_10 + 1;
            }
            else {
              local_8 = local_8 + 1;
              local_c = 0;
              BVar1 = ReadFile(*(HANDLE *)((&DAT_6f63e2e0)[iVar4] + (param_1 & 0x1f) * 0x24),
                               local_20,1,&local_14,(LPOVERLAPPED)0x0);
              if (BVar1 == 0) {
                local_c = GetLastError();
              }
              if ((local_c == 0) && (local_14 != 0)) {
                if ((*(byte *)((&DAT_6f63e2e0)[iVar4] + 4 + (param_1 & 0x1f) * 0x24) & 0x48) == 0) {
                  if ((local_10 == param_2) && (local_20[0] == '\n')) {
                    *local_10 = '\n';
                    local_10 = local_10 + 1;
                  }
                  else {
                    FUN_6f62be60(param_1,-1,1);
                    if (local_20[0] != '\n') {
                      *local_10 = '\r';
                      local_10 = local_10 + 1;
                    }
                  }
                }
                else {
                  if (local_20[0] == '\n') {
                    *local_10 = '\n';
                  }
                  else {
                    *local_10 = '\r';
                    *(char *)((&DAT_6f63e2e0)[iVar4] + 5 + (param_1 & 0x1f) * 0x24) = local_20[0];
                  }
                  local_10 = local_10 + 1;
                }
              }
              else {
                *local_10 = '\r';
                local_10 = local_10 + 1;
              }
            }
          }
          else {
            *local_10 = *local_8;
            local_10 = local_10 + 1;
            local_8 = local_8 + 1;
          }
        }
        local_1c = (int)local_10 - (int)param_2;
      }
    }
  }
  return local_1c;
}



// Function: FUN_6f62f6b0 at 6f62f6b0

uint FUN_6f62f6b0(void)

{
  int local_10;
  uint local_c;
  undefined4 *local_8;
  
  local_c = 0xffffffff;
  FUN_6f62c780(0x12);
  local_10 = 0;
  do {
    if (0x3f < local_10) {
LAB_6f62f880:
      FUN_6f62c820(0x12);
      return local_c;
    }
    if ((&DAT_6f63e2e0)[local_10] == 0) {
      local_8 = (undefined4 *)FUN_6f627430((void *)0x480,2,0x6f637f3c,0x79);
      if (local_8 != (undefined4 *)0x0) {
        (&DAT_6f63e2e0)[local_10] = local_8;
        DAT_6f63e3e0 = DAT_6f63e3e0 + 0x20;
        for (; local_8 < (undefined4 *)((&DAT_6f63e2e0)[local_10] + 0x480); local_8 = local_8 + 9) {
          *(undefined1 *)(local_8 + 1) = 0;
          *local_8 = 0xffffffff;
          *(undefined1 *)((int)local_8 + 5) = 10;
          local_8[2] = 0;
        }
        local_c = local_10 << 5;
        FUN_6f62fba0(local_c);
      }
      goto LAB_6f62f880;
    }
    for (local_8 = (undefined4 *)(&DAT_6f63e2e0)[local_10];
        local_8 < (undefined4 *)((&DAT_6f63e2e0)[local_10] + 0x480); local_8 = local_8 + 9) {
      if ((*(byte *)(local_8 + 1) & 1) == 0) {
        if (local_8[2] == 0) {
          FUN_6f62c780(0x11);
          if (local_8[2] == 0) {
            InitializeCriticalSection((LPCRITICAL_SECTION)(local_8 + 3));
            local_8[2] = local_8[2] + 1;
          }
          FUN_6f62c820(0x11);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)(local_8 + 3));
        if ((*(byte *)(local_8 + 1) & 1) == 0) {
          *local_8 = 0xffffffff;
          local_c = local_10 * 0x20 + ((int)local_8 - (&DAT_6f63e2e0)[local_10]) / 0x24;
          break;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(local_8 + 3));
      }
    }
    if (local_c != 0xffffffff) goto LAB_6f62f880;
    local_10 = local_10 + 1;
  } while( true );
}



// Function: __set_osfhnd at 6f62f8a0

/* Library Function - Single Match
    __set_osfhnd
   
   Library: Visual Studio 2003 Debug */

int __cdecl __set_osfhnd(int param_1,intptr_t param_2)

{
  int iVar1;
  undefined4 *puVar2;
  DWORD *pDVar3;
  
  if (((uint)param_1 < DAT_6f63e3e0) &&
     (*(int *)((&DAT_6f63e2e0)[param_1 >> 5] + (param_1 & 0x1fU) * 0x24) == -1)) {
    if (DAT_6f63ce18 == 1) {
      if (param_1 == 0) {
        SetStdHandle(0xfffffff6,(HANDLE)param_2);
      }
      else if (param_1 == 1) {
        SetStdHandle(0xfffffff5,(HANDLE)param_2);
      }
      else if (param_1 == 2) {
        SetStdHandle(0xfffffff4,(HANDLE)param_2);
      }
    }
    *(intptr_t *)((&DAT_6f63e2e0)[param_1 >> 5] + (param_1 & 0x1fU) * 0x24) = param_2;
    iVar1 = 0;
  }
  else {
    puVar2 = (undefined4 *)FUN_6f62ee40();
    *puVar2 = 9;
    pDVar3 = FUN_6f62ee50();
    *pDVar3 = 0;
    iVar1 = -1;
  }
  return iVar1;
}



// Function: FUN_6f62f960 at 6f62f960

undefined4 __cdecl FUN_6f62f960(uint param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  DWORD *pDVar3;
  int iVar4;
  
  if (((param_1 < DAT_6f63e3e0) &&
      (iVar4 = (int)param_1 >> 5,
      (*(byte *)((&DAT_6f63e2e0)[iVar4] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) &&
     (*(int *)((&DAT_6f63e2e0)[iVar4] + (param_1 & 0x1f) * 0x24) != -1)) {
    if (DAT_6f63ce18 == 1) {
      if (param_1 == 0) {
        SetStdHandle(0xfffffff6,(HANDLE)0x0);
      }
      else if (param_1 == 1) {
        SetStdHandle(0xfffffff5,(HANDLE)0x0);
      }
      else if (param_1 == 2) {
        SetStdHandle(0xfffffff4,(HANDLE)0x0);
      }
    }
    *(undefined4 *)((&DAT_6f63e2e0)[iVar4] + (param_1 & 0x1f) * 0x24) = 0xffffffff;
    uVar1 = 0;
  }
  else {
    puVar2 = (undefined4 *)FUN_6f62ee40();
    *puVar2 = 9;
    pDVar3 = FUN_6f62ee50();
    *pDVar3 = 0;
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



// Function: FUN_6f62fa40 at 6f62fa40

undefined4 __cdecl FUN_6f62fa40(uint param_1)

{
  undefined4 *puVar1;
  DWORD *pDVar2;
  undefined4 uVar3;
  
  if ((param_1 < DAT_6f63e3e0) &&
     ((*(byte *)((&DAT_6f63e2e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    uVar3 = *(undefined4 *)((&DAT_6f63e2e0)[(int)param_1 >> 5] + (param_1 & 0x1f) * 0x24);
  }
  else {
    puVar1 = (undefined4 *)FUN_6f62ee40();
    *puVar1 = 9;
    pDVar2 = FUN_6f62ee50();
    *pDVar2 = 0;
    uVar3 = 0xffffffff;
  }
  return uVar3;
}



// Function: FUN_6f62fab0 at 6f62fab0

uint __cdecl FUN_6f62fab0(HANDLE param_1,uint param_2)

{
  DWORD DVar1;
  uint _Filehandle;
  undefined4 *puVar2;
  DWORD *pDVar3;
  byte local_10;
  
  local_10 = 0;
  if ((param_2 & 8) != 0) {
    local_10 = 0x20;
  }
  if ((param_2 & 0x4000) != 0) {
    local_10 = local_10 | 0x80;
  }
  DVar1 = GetFileType(param_1);
  if (DVar1 == 0) {
    DVar1 = GetLastError();
    __dosmaperr(DVar1);
    _Filehandle = 0xffffffff;
  }
  else {
    if (DVar1 == 2) {
      local_10 = local_10 | 0x40;
    }
    else if (DVar1 == 3) {
      local_10 = local_10 | 8;
    }
    _Filehandle = FUN_6f62f6b0();
    if (_Filehandle == 0xffffffff) {
      puVar2 = (undefined4 *)FUN_6f62ee40();
      *puVar2 = 0x18;
      pDVar3 = FUN_6f62ee50();
      *pDVar3 = 0;
      _Filehandle = 0xffffffff;
    }
    else {
      __set_osfhnd(_Filehandle,(intptr_t)param_1);
      *(byte *)((&DAT_6f63e2e0)[(int)_Filehandle >> 5] + 4 + (_Filehandle & 0x1f) * 0x24) =
           local_10 | 1;
      __unlock_fhandle(_Filehandle);
    }
  }
  return _Filehandle;
}



// Function: FUN_6f62fba0 at 6f62fba0

void __cdecl FUN_6f62fba0(uint param_1)

{
  int iVar1;
  
  iVar1 = (&DAT_6f63e2e0)[(int)param_1 >> 5] + (param_1 & 0x1f) * 0x24;
  if (*(int *)(iVar1 + 8) == 0) {
    FUN_6f62c780(0x11);
    if (*(int *)(iVar1 + 8) == 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xc));
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
    }
    FUN_6f62c820(0x11);
  }
  EnterCriticalSection
            ((LPCRITICAL_SECTION)
             ((&DAT_6f63e2e0)[(int)param_1 >> 5] + 0xc + (param_1 & 0x1f) * 0x24));
  return;
}



// Function: __unlock_fhandle at 6f62fc30

/* Library Function - Single Match
    __unlock_fhandle
   
   Library: Visual Studio 2003 Debug */

void __cdecl __unlock_fhandle(int _Filehandle)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)
             ((&DAT_6f63e2e0)[_Filehandle >> 5] + 0xc + (_Filehandle & 0x1fU) * 0x24));
  return;
}



// Function: FUN_6f62fc60 at 6f62fc60

int FUN_6f62fc60(void)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  FUN_6f62c780(2);
  for (local_c = 3; local_c < DAT_6f63e2c0; local_c = local_c + 1) {
    if (*(int *)(DAT_6f63d2b4 + local_c * 4) != 0) {
      if ((*(uint *)(*(int *)(DAT_6f63d2b4 + local_c * 4) + 0xc) & 0x83) != 0) {
        iVar1 = FUN_6f632110(*(undefined ***)(DAT_6f63d2b4 + local_c * 4));
        if (iVar1 != -1) {
          local_8 = local_8 + 1;
        }
      }
      if (0x13 < local_c) {
        DeleteCriticalSection((LPCRITICAL_SECTION)(*(int *)(DAT_6f63d2b4 + local_c * 4) + 0x20));
        FUN_6f627ec0(*(void **)(DAT_6f63d2b4 + local_c * 4),2);
        *(undefined4 *)(DAT_6f63d2b4 + local_c * 4) = 0;
      }
    }
  }
  FUN_6f62c820(2);
  return local_8;
}



// Function: FUN_6f62fd40 at 6f62fd40

int __cdecl FUN_6f62fd40(undefined **param_1)

{
  int iVar1;
  
  if (param_1 == (undefined **)0x0) {
    iVar1 = FUN_6f62feb0(0);
  }
  else {
    FUN_6f62c840(param_1);
    iVar1 = FUN_6f62fd90((int *)param_1);
    FUN_6f62c8b0(param_1);
  }
  return iVar1;
}



// Function: FUN_6f62fd90 at 6f62fd90

int __cdecl FUN_6f62fd90(int *param_1)

{
  int iVar1;
  DWORD DVar2;
  
  iVar1 = FUN_6f62fde0(param_1);
  if (iVar1 == 0) {
    if ((param_1[3] & 0x4000U) == 0) {
      iVar1 = 0;
    }
    else {
      DVar2 = FUN_6f632260(param_1[4]);
      iVar1 = -(uint)(DVar2 != 0);
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}



// Function: FUN_6f62fde0 at 6f62fde0

undefined4 __cdecl FUN_6f62fde0(int *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_8;
  
  local_8 = 0;
  if ((((param_1[3] & 3U) == 2) && ((param_1[3] & 0x108U) != 0)) &&
     (uVar2 = *param_1 - param_1[2], 0 < (int)uVar2)) {
    uVar1 = FUN_6f62bf20(param_1[4],(char *)param_1[2],uVar2);
    if (uVar1 == uVar2) {
      if ((param_1[3] & 0x80U) != 0) {
        param_1[3] = param_1[3] & 0xfffffffd;
      }
    }
    else {
      param_1[3] = param_1[3] | 0x20;
      local_8 = 0xffffffff;
    }
  }
  *param_1 = param_1[2];
  param_1[1] = 0;
  return local_8;
}



// Function: FUN_6f62fea0 at 6f62fea0

void FUN_6f62fea0(void)

{
  FUN_6f62feb0(1);
  return;
}



// Function: FUN_6f62feb0 at 6f62feb0

int __cdecl FUN_6f62feb0(int param_1)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  FUN_6f62c780(2);
  for (local_10 = 0; local_10 < DAT_6f63e2c0; local_10 = local_10 + 1) {
    if ((*(int *)(DAT_6f63d2b4 + local_10 * 4) != 0) &&
       ((*(uint *)(*(int *)(DAT_6f63d2b4 + local_10 * 4) + 0xc) & 0x83) != 0)) {
      FUN_6f62c880(local_10,*(int *)(DAT_6f63d2b4 + local_10 * 4));
      if ((*(uint *)(*(int *)(DAT_6f63d2b4 + local_10 * 4) + 0xc) & 0x83) != 0) {
        if (param_1 == 1) {
          iVar1 = FUN_6f62fd90(*(int **)(DAT_6f63d2b4 + local_10 * 4));
          if (iVar1 != -1) {
            local_8 = local_8 + 1;
          }
        }
        else if (((param_1 == 0) &&
                 ((*(uint *)(*(int *)(DAT_6f63d2b4 + local_10 * 4) + 0xc) & 2) != 0)) &&
                (iVar1 = FUN_6f62fd90(*(int **)(DAT_6f63d2b4 + local_10 * 4)), iVar1 == -1)) {
          local_c = -1;
        }
      }
      FUN_6f62c8f0(local_10,*(int *)(DAT_6f63d2b4 + local_10 * 4));
    }
  }
  FUN_6f62c820(2);
  if (param_1 == 1) {
    local_c = local_8;
  }
  return local_c;
}



// Function: ___init_time at 6f62fff0

/* Library Function - Single Match
    ___init_time
   
   Library: Visual Studio 2003 Debug */

int __cdecl ___init_time(threadlocinfo *_LocInfo)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  if (DAT_6f63d15c == 0) {
    PTR_PTR_6f63ca8c = (undefined *)&PTR_DAT_6f63c9e0;
    ___free_lc_time(DAT_6f63d178);
    FUN_6f627ec0(DAT_6f63d178,2);
    DAT_6f63d178 = (int *)0x0;
    iVar2 = 0;
  }
  else {
    piVar1 = (int *)__calloc_dbg(1,0xac,2,"inittime.c",0x4c);
    if (piVar1 == (int *)0x0) {
      iVar2 = 1;
    }
    else {
      uVar3 = FUN_6f6300d0(piVar1);
      if (uVar3 == 0) {
        PTR_PTR_6f63ca8c = (undefined *)piVar1;
        ___free_lc_time(DAT_6f63d178);
        FUN_6f627ec0(DAT_6f63d178,2);
        iVar2 = 0;
        DAT_6f63d178 = piVar1;
      }
      else {
        ___free_lc_time(piVar1);
        FUN_6f627ec0(piVar1,2);
        iVar2 = 1;
      }
    }
  }
  return iVar2;
}



// Function: FUN_6f6300d0 at 6f6300d0

uint __cdecl FUN_6f6300d0(int *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  uint uVar43;
  
  uVar41 = (uint)DAT_6f63d1b6;
  uVar1 = (uint)DAT_6f63d1b8;
  if (param_1 == (int *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar2 = FUN_6f6336e0(1,uVar41,0x31,param_1 + 1);
    uVar3 = FUN_6f6336e0(1,uVar41,0x32,param_1 + 2);
    uVar4 = FUN_6f6336e0(1,uVar41,0x33,param_1 + 3);
    uVar5 = FUN_6f6336e0(1,uVar41,0x34,param_1 + 4);
    uVar6 = FUN_6f6336e0(1,uVar41,0x35,param_1 + 5);
    uVar7 = FUN_6f6336e0(1,uVar41,0x36,param_1 + 6);
    uVar8 = FUN_6f6336e0(1,uVar41,0x37,param_1);
    uVar9 = FUN_6f6336e0(1,uVar41,0x2a,param_1 + 8);
    uVar10 = FUN_6f6336e0(1,uVar41,0x2b,param_1 + 9);
    uVar11 = FUN_6f6336e0(1,uVar41,0x2c,param_1 + 10);
    uVar12 = FUN_6f6336e0(1,uVar41,0x2d,param_1 + 0xb);
    uVar13 = FUN_6f6336e0(1,uVar41,0x2e,param_1 + 0xc);
    uVar14 = FUN_6f6336e0(1,uVar41,0x2f,param_1 + 0xd);
    uVar15 = FUN_6f6336e0(1,uVar41,0x30,param_1 + 7);
    uVar16 = FUN_6f6336e0(1,uVar41,0x44,param_1 + 0xe);
    uVar17 = FUN_6f6336e0(1,uVar41,0x45,param_1 + 0xf);
    uVar18 = FUN_6f6336e0(1,uVar41,0x46,param_1 + 0x10);
    uVar19 = FUN_6f6336e0(1,uVar41,0x47,param_1 + 0x11);
    uVar20 = FUN_6f6336e0(1,uVar41,0x48,param_1 + 0x12);
    uVar21 = FUN_6f6336e0(1,uVar41,0x49,param_1 + 0x13);
    uVar22 = FUN_6f6336e0(1,uVar41,0x4a,param_1 + 0x14);
    uVar23 = FUN_6f6336e0(1,uVar41,0x4b,param_1 + 0x15);
    uVar24 = FUN_6f6336e0(1,uVar41,0x4c,param_1 + 0x16);
    uVar25 = FUN_6f6336e0(1,uVar41,0x4d,param_1 + 0x17);
    uVar26 = FUN_6f6336e0(1,uVar41,0x4e,param_1 + 0x18);
    uVar27 = FUN_6f6336e0(1,uVar41,0x4f,param_1 + 0x19);
    uVar28 = FUN_6f6336e0(1,uVar41,0x38,param_1 + 0x1a);
    uVar29 = FUN_6f6336e0(1,uVar41,0x39,param_1 + 0x1b);
    uVar30 = FUN_6f6336e0(1,uVar41,0x3a,param_1 + 0x1c);
    uVar31 = FUN_6f6336e0(1,uVar41,0x3b,param_1 + 0x1d);
    uVar32 = FUN_6f6336e0(1,uVar41,0x3c,param_1 + 0x1e);
    uVar33 = FUN_6f6336e0(1,uVar41,0x3d,param_1 + 0x1f);
    uVar34 = FUN_6f6336e0(1,uVar41,0x3e,param_1 + 0x20);
    uVar35 = FUN_6f6336e0(1,uVar41,0x3f,param_1 + 0x21);
    uVar36 = FUN_6f6336e0(1,uVar41,0x40,param_1 + 0x22);
    uVar37 = FUN_6f6336e0(1,uVar41,0x41,param_1 + 0x23);
    uVar38 = FUN_6f6336e0(1,uVar41,0x42,param_1 + 0x24);
    uVar39 = FUN_6f6336e0(1,uVar41,0x43,param_1 + 0x25);
    uVar40 = FUN_6f6336e0(1,uVar41,0x28,param_1 + 0x26);
    uVar41 = FUN_6f6336e0(1,uVar41,0x29,param_1 + 0x27);
    uVar42 = FUN_6f6336e0(1,uVar1,0x1f,param_1 + 0x28);
    uVar43 = FUN_6f6336e0(1,uVar1,0x20,param_1 + 0x29);
    uVar1 = FUN_6f630970(uVar1,(int)param_1);
    uVar1 = uVar2 | uVar3 | uVar4 | uVar5 | uVar6 | uVar7 | uVar8 | uVar9 | uVar10 | uVar11 | uVar12
            | uVar13 | uVar14 | uVar15 | uVar16 | uVar17 | uVar18 | uVar19 | uVar20 | uVar21 |
            uVar22 | uVar23 | uVar24 | uVar25 | uVar26 | uVar27 | uVar28 | uVar29 | uVar30 | uVar31
            | uVar32 | uVar33 | uVar34 | uVar35 | uVar36 | uVar37 | uVar38 | uVar39 | uVar40 |
            uVar41 | uVar42 | uVar43 | uVar1;
  }
  return uVar1;
}



// Function: ___free_lc_time at 6f630660

/* Library Function - Single Match
    ___free_lc_time
   
   Library: Visual Studio 2003 Debug */

void __cdecl ___free_lc_time(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    FUN_6f627ec0((void *)param_1[1],2);
    FUN_6f627ec0((void *)param_1[2],2);
    FUN_6f627ec0((void *)param_1[3],2);
    FUN_6f627ec0((void *)param_1[4],2);
    FUN_6f627ec0((void *)param_1[5],2);
    FUN_6f627ec0((void *)param_1[6],2);
    FUN_6f627ec0((void *)*param_1,2);
    FUN_6f627ec0((void *)param_1[8],2);
    FUN_6f627ec0((void *)param_1[9],2);
    FUN_6f627ec0((void *)param_1[10],2);
    FUN_6f627ec0((void *)param_1[0xb],2);
    FUN_6f627ec0((void *)param_1[0xc],2);
    FUN_6f627ec0((void *)param_1[0xd],2);
    FUN_6f627ec0((void *)param_1[7],2);
    FUN_6f627ec0((void *)param_1[0xe],2);
    FUN_6f627ec0((void *)param_1[0xf],2);
    FUN_6f627ec0((void *)param_1[0x10],2);
    FUN_6f627ec0((void *)param_1[0x11],2);
    FUN_6f627ec0((void *)param_1[0x12],2);
    FUN_6f627ec0((void *)param_1[0x13],2);
    FUN_6f627ec0((void *)param_1[0x14],2);
    FUN_6f627ec0((void *)param_1[0x15],2);
    FUN_6f627ec0((void *)param_1[0x16],2);
    FUN_6f627ec0((void *)param_1[0x17],2);
    FUN_6f627ec0((void *)param_1[0x18],2);
    FUN_6f627ec0((void *)param_1[0x19],2);
    FUN_6f627ec0((void *)param_1[0x1a],2);
    FUN_6f627ec0((void *)param_1[0x1b],2);
    FUN_6f627ec0((void *)param_1[0x1c],2);
    FUN_6f627ec0((void *)param_1[0x1d],2);
    FUN_6f627ec0((void *)param_1[0x1e],2);
    FUN_6f627ec0((void *)param_1[0x1f],2);
    FUN_6f627ec0((void *)param_1[0x20],2);
    FUN_6f627ec0((void *)param_1[0x21],2);
    FUN_6f627ec0((void *)param_1[0x22],2);
    FUN_6f627ec0((void *)param_1[0x23],2);
    FUN_6f627ec0((void *)param_1[0x24],2);
    FUN_6f627ec0((void *)param_1[0x25],2);
    FUN_6f627ec0((void *)param_1[0x26],2);
    FUN_6f627ec0((void *)param_1[0x27],2);
    FUN_6f627ec0((void *)param_1[0x28],2);
    FUN_6f627ec0((void *)param_1[0x29],2);
    FUN_6f627ec0((void *)param_1[0x2a],2);
  }
  return;
}



// Function: FUN_6f630970 at 6f630970

uint __cdecl FUN_6f630970(LCID param_1,int param_2)

{
  undefined1 *puVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  char *local_18;
  int local_14;
  char *local_10;
  int local_c;
  char *local_8;
  
  local_c = 0;
  local_14 = 0;
  uVar3 = FUN_6f6336e0(0,param_1,0x23,&local_c);
  uVar4 = FUN_6f6336e0(0,param_1,0x25,&local_14);
  uVar5 = FUN_6f6336e0(1,param_1,0x1e,(int *)&local_10);
  uVar5 = uVar3 | uVar4 | uVar5;
  if (uVar5 == 0) {
    uVar6 = FUN_6f627430((void *)0xd,2,0x6f637f48,0x107);
    *(undefined4 *)(param_2 + 0xa8) = uVar6;
    puVar1 = *(undefined1 **)(param_2 + 0xa8);
    if (local_c == 0) {
      *puVar1 = 0x68;
      local_8 = puVar1 + 1;
      if (local_14 != 0) {
        *local_8 = 'h';
        local_8 = puVar1 + 2;
      }
    }
    else {
      *puVar1 = 0x48;
      local_8 = puVar1 + 1;
      if (local_14 != 0) {
        *local_8 = 'H';
        local_8 = puVar1 + 2;
      }
    }
    for (local_18 = local_10; *local_18 != '\0'; local_18 = local_18 + 1) {
      *local_8 = *local_18;
      local_8 = local_8 + 1;
    }
    *local_8 = 'm';
    pcVar2 = local_8 + 1;
    if (local_14 != 0) {
      local_8[1] = 'm';
      pcVar2 = local_8 + 2;
    }
    local_8 = pcVar2;
    for (local_18 = local_10; *local_18 != '\0'; local_18 = local_18 + 1) {
      *local_8 = *local_18;
      local_8 = local_8 + 1;
    }
    *local_8 = 's';
    local_8[1] = 's';
    local_8 = local_8 + 2;
    *local_8 = '\0';
    FUN_6f627ec0(local_10,2);
  }
  return uVar5;
}



// Function: FUN_6f630b30 at 6f630b30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_6f630b30(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar1 = (uint)DAT_6f63d1b2;
  if (DAT_6f63d158 == 0) {
    FUN_6f627ec0(DAT_6f63d17c,2);
    FUN_6f627ec0(DAT_6f63d180,2);
    FUN_6f627ec0(DAT_6f63d184,2);
    DAT_6f63d17c = (void *)0x0;
    DAT_6f63d180 = (void *)0x0;
    DAT_6f63d184 = (char *)0x0;
    uVar5 = FUN_6f627430((void *)0x2,2,0x6f637f54,0x88);
    *(undefined4 *)PTR_PTR_6f63cac8 = uVar5;
    if (*(int *)PTR_PTR_6f63cac8 == 0) {
      uVar5 = 0xffffffff;
    }
    else {
      FUN_6f6235b0(*(uint **)PTR_PTR_6f63cac8,(uint *)&DAT_6f637f20);
      uVar5 = FUN_6f627430((void *)0x2,2,0x6f637f54,0x8d);
      *(undefined4 *)(PTR_PTR_6f63cac8 + 4) = uVar5;
      if (*(int *)(PTR_PTR_6f63cac8 + 4) == 0) {
        uVar5 = 0xffffffff;
      }
      else {
        **(undefined1 **)(PTR_PTR_6f63cac8 + 4) = 0;
        uVar5 = FUN_6f627430((void *)0x2,2,0x6f637f54,0x92);
        *(undefined4 *)(PTR_PTR_6f63cac8 + 8) = uVar5;
        if (*(int *)(PTR_PTR_6f63cac8 + 8) == 0) {
          uVar5 = 0xffffffff;
        }
        else {
          **(undefined1 **)(PTR_PTR_6f63cac8 + 8) = 0;
          DAT_6f6398f4 = **(undefined1 **)PTR_PTR_6f63cac8;
          _DAT_6f6398f8 = 1;
          uVar5 = 0;
        }
      }
    }
  }
  else {
    iVar2 = FUN_6f6336e0(1,uVar1,0xe,(int *)&DAT_6f63d17c);
    iVar3 = FUN_6f6336e0(1,uVar1,0xf,(int *)&DAT_6f63d180);
    iVar4 = FUN_6f6336e0(1,uVar1,0x10,(int *)&DAT_6f63d184);
    fix_grouping(DAT_6f63d184);
    if ((iVar2 == 0 && iVar3 == 0) && iVar4 == 0) {
      if (*(undefined **)PTR_PTR_6f63cac8 != &DAT_6f63ca90) {
        FUN_6f627ec0(*(void **)PTR_PTR_6f63cac8,2);
        FUN_6f627ec0(*(void **)(PTR_PTR_6f63cac8 + 4),2);
        FUN_6f627ec0(*(void **)(PTR_PTR_6f63cac8 + 8),2);
      }
      *(void **)PTR_PTR_6f63cac8 = DAT_6f63d17c;
      *(void **)(PTR_PTR_6f63cac8 + 4) = DAT_6f63d180;
      *(char **)(PTR_PTR_6f63cac8 + 8) = DAT_6f63d184;
      DAT_6f6398f4 = **(undefined1 **)PTR_PTR_6f63cac8;
      _DAT_6f6398f8 = 1;
      uVar5 = 0;
    }
    else {
      FUN_6f627ec0(DAT_6f63d17c,2);
      FUN_6f627ec0(DAT_6f63d180,2);
      FUN_6f627ec0(DAT_6f63d184,2);
      DAT_6f63d17c = (void *)0x0;
      DAT_6f63d180 = (void *)0x0;
      DAT_6f63d184 = (char *)0x0;
      uVar5 = 0xffffffff;
    }
  }
  return uVar5;
}



// Function: fix_grouping at 6f630de0

/* Library Function - Single Match
    _fix_grouping
   
   Library: Visual Studio */

void __cdecl fix_grouping(char *param_1)

{
  char *local_8;
  
  while (*param_1 != '\0') {
    if ((*param_1 < '0') || ('9' < *param_1)) {
      if (*param_1 == ';') {
        local_8 = param_1;
        do {
          *local_8 = local_8[1];
          local_8 = local_8 + 1;
        } while (*local_8 != '\0');
      }
      else {
        param_1 = param_1 + 1;
      }
    }
    else {
      *param_1 = *param_1 + -0x30;
      param_1 = param_1 + 1;
    }
  }
  return;
}



// Function: FUN_6f630e60 at 6f630e60

undefined4 FUN_6f630e60(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (DAT_6f63d154 == 0) {
    PTR_DAT_6f63ca98 = *(undefined **)PTR_PTR_6f63cac8;
    PTR_DAT_6f63ca9c = *(undefined **)(PTR_PTR_6f63cac8 + 4);
    PTR_DAT_6f63caa0 = *(undefined **)(PTR_PTR_6f63cac8 + 8);
    PTR_PTR_6f63cac8 = (undefined *)&PTR_DAT_6f63ca98;
    FUN_6f631220((int)DAT_6f63d188);
    FUN_6f627ec0(DAT_6f63d188,2);
    DAT_6f63d188 = (undefined4 *)0x0;
    uVar2 = 0;
  }
  else {
    puVar1 = (undefined4 *)__calloc_dbg(1,0x30,2,"initmon.c",0x4a);
    if (puVar1 == (undefined4 *)0x0) {
      uVar2 = 1;
    }
    else {
      uVar3 = FUN_6f630f90((int)puVar1);
      if (uVar3 == 0) {
        *puVar1 = *(undefined4 *)PTR_PTR_6f63cac8;
        puVar1[1] = *(undefined4 *)(PTR_PTR_6f63cac8 + 4);
        puVar1[2] = *(undefined4 *)(PTR_PTR_6f63cac8 + 8);
        PTR_PTR_6f63cac8 = (undefined *)puVar1;
        FUN_6f631220((int)DAT_6f63d188);
        FUN_6f627ec0(DAT_6f63d188,2);
        uVar2 = 0;
        DAT_6f63d188 = puVar1;
      }
      else {
        FUN_6f631220((int)puVar1);
        FUN_6f627ec0(puVar1,2);
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}



// Function: FUN_6f630f90 at 6f630f90

uint __cdecl FUN_6f630f90(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  
  uVar1 = (uint)DAT_6f63d1ac;
  if (param_1 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar2 = FUN_6f6336e0(1,uVar1,0x15,(int *)(param_1 + 0xc));
    uVar3 = FUN_6f6336e0(1,uVar1,0x14,(int *)(param_1 + 0x10));
    uVar4 = FUN_6f6336e0(1,uVar1,0x16,(int *)(param_1 + 0x14));
    uVar5 = FUN_6f6336e0(1,uVar1,0x17,(int *)(param_1 + 0x18));
    uVar6 = FUN_6f6336e0(1,uVar1,0x18,(int *)(param_1 + 0x1c));
    fix_grouping(*(char **)(param_1 + 0x1c));
    uVar7 = FUN_6f6336e0(1,uVar1,0x50,(int *)(param_1 + 0x20));
    uVar8 = FUN_6f6336e0(1,uVar1,0x51,(int *)(param_1 + 0x24));
    uVar9 = FUN_6f6336e0(0,uVar1,0x1a,(int *)(param_1 + 0x28));
    uVar10 = FUN_6f6336e0(0,uVar1,0x19,(int *)(param_1 + 0x29));
    uVar11 = FUN_6f6336e0(0,uVar1,0x54,(int *)(param_1 + 0x2a));
    uVar12 = FUN_6f6336e0(0,uVar1,0x55,(int *)(param_1 + 0x2b));
    uVar13 = FUN_6f6336e0(0,uVar1,0x56,(int *)(param_1 + 0x2c));
    uVar14 = FUN_6f6336e0(0,uVar1,0x57,(int *)(param_1 + 0x2d));
    uVar15 = FUN_6f6336e0(0,uVar1,0x52,(int *)(param_1 + 0x2e));
    uVar1 = FUN_6f6336e0(0,uVar1,0x53,(int *)(param_1 + 0x2f));
    uVar1 = uVar2 | uVar3 | uVar4 | uVar5 | uVar6 | uVar7 | uVar8 | uVar9 | uVar10 | uVar11 | uVar12
            | uVar13 | uVar14 | uVar15 | uVar1;
  }
  return uVar1;
}



// Function: fix_grouping at 6f6311a0

/* Library Function - Single Match
    _fix_grouping
   
   Library: Visual Studio */

void __cdecl fix_grouping(char *param_1)

{
  char *local_8;
  
  while (*param_1 != '\0') {
    if ((*param_1 < '0') || ('9' < *param_1)) {
      if (*param_1 == ';') {
        local_8 = param_1;
        do {
          *local_8 = local_8[1];
          local_8 = local_8 + 1;
        } while (*local_8 != '\0');
      }
      else {
        param_1 = param_1 + 1;
      }
    }
    else {
      *param_1 = *param_1 + -0x30;
      param_1 = param_1 + 1;
    }
  }
  return;
}



// Function: FUN_6f631220 at 6f631220

void __cdecl FUN_6f631220(int param_1)

{
  if ((param_1 != 0) && (*(undefined **)(param_1 + 0xc) != &DAT_6f63d1d0)) {
    FUN_6f627ec0(*(void **)(param_1 + 0xc),2);
    FUN_6f627ec0(*(void **)(param_1 + 0x10),2);
    FUN_6f627ec0(*(void **)(param_1 + 0x14),2);
    FUN_6f627ec0(*(void **)(param_1 + 0x18),2);
    FUN_6f627ec0(*(void **)(param_1 + 0x1c),2);
    FUN_6f627ec0(*(void **)(param_1 + 0x20),2);
    FUN_6f627ec0(*(void **)(param_1 + 0x24),2);
  }
  return;
}



// Function: FUN_6f6312c0 at 6f6312c0

undefined4 FUN_6f6312c0(void)

{
  int iVar1;
  BOOL BVar2;
  undefined4 uVar3;
  undefined2 *local_34;
  LPCSTR local_30;
  LPCWSTR local_2c;
  LPCWSTR local_28;
  uint local_24;
  undefined2 *local_20;
  BYTE *local_1c;
  _cpinfo local_18;
  
  local_30 = (LPCSTR)0x0;
  local_2c = (LPCWSTR)0x0;
  if (DAT_6f63d150 == 0) {
    PTR_DAT_6f639900 = &DAT_6f63990a;
    PTR_DAT_6f639904 = &DAT_6f63990a;
    FUN_6f627ec0(DAT_6f63d18c,2);
    FUN_6f627ec0(DAT_6f63d190,2);
    DAT_6f63d18c = (undefined2 *)0x0;
    DAT_6f63d190 = (undefined2 *)0x0;
    uVar3 = 0;
  }
  else {
    if ((DAT_6f63d160 != 0) ||
       (iVar1 = FUN_6f6336e0(0,(uint)DAT_6f63d1a4,0xb,(int *)&DAT_6f63d160), iVar1 == 0)) {
      local_34 = (undefined2 *)FUN_6f627430((void *)0x202,2,0x6f637f6c,0x5b);
      local_20 = (undefined2 *)FUN_6f627430((void *)0x202,2,0x6f637f6c,0x5d);
      local_30 = (LPCSTR)FUN_6f627430((void *)0x101,2,0x6f637f6c,0x5f);
      local_2c = (LPCWSTR)FUN_6f627430((void *)0x202,2,0x6f637f6c,0x61);
      if ((local_34 != (undefined2 *)0x0) &&
         (((local_20 != (undefined2 *)0x0 && (local_30 != (LPCSTR)0x0)) &&
          (local_2c != (LPCWSTR)0x0)))) {
        local_1c = (BYTE *)local_30;
        for (local_24 = 0; (int)local_24 < 0x100; local_24 = local_24 + 1) {
          *local_1c = (CHAR)local_24;
          local_1c = local_1c + 1;
        }
        BVar2 = GetCPInfo(DAT_6f63d160,&local_18);
        if ((BVar2 != 0) && (local_18.MaxCharSize < 3)) {
          DAT_6f6398f0 = local_18.MaxCharSize & 0xffff;
          if (1 < DAT_6f6398f0) {
            for (local_1c = local_18.LeadByte; (*local_1c != 0 && (local_1c[1] != 0));
                local_1c = local_1c + 2) {
              for (local_24 = (uint)*local_1c; (int)local_24 <= (int)(uint)local_1c[1];
                  local_24 = local_24 + 1) {
                local_30[local_24] = '\0';
              }
            }
          }
          iVar1 = FUN_6f62f070(1,local_30,0x100,local_34 + 1,0,0);
          if (iVar1 != 0) {
            *local_34 = 0;
            local_28 = local_2c;
            for (local_24 = 0; (int)local_24 < 0x100; local_24 = local_24 + 1) {
              *local_28 = (WCHAR)local_24;
              local_28 = local_28 + 1;
            }
            iVar1 = FUN_6f62ee60(1,local_2c,0x100,local_20 + 1,0,0);
            if (iVar1 != 0) {
              *local_20 = 0;
              if (1 < (int)DAT_6f6398f0) {
                for (local_1c = local_18.LeadByte; (*local_1c != 0 && (local_1c[1] != 0));
                    local_1c = local_1c + 2) {
                  for (local_24 = (uint)*local_1c; (int)local_24 <= (int)(uint)local_1c[1];
                      local_24 = local_24 + 1) {
                    local_34[local_24 + 1] = 0x8000;
                  }
                }
              }
              PTR_DAT_6f639900 = (undefined *)(local_34 + 1);
              PTR_DAT_6f639904 = (undefined *)(local_20 + 1);
              if (DAT_6f63d18c != (undefined2 *)0x0) {
                FUN_6f627ec0(DAT_6f63d18c,2);
              }
              DAT_6f63d18c = local_34;
              if (DAT_6f63d190 != (undefined2 *)0x0) {
                FUN_6f627ec0(DAT_6f63d190,2);
              }
              DAT_6f63d190 = local_20;
              FUN_6f627ec0(local_30,2);
              FUN_6f627ec0(local_2c,2);
              return 0;
            }
          }
        }
      }
    }
    FUN_6f627ec0(local_34,2);
    FUN_6f627ec0(local_20,2);
    FUN_6f627ec0(local_30,2);
    FUN_6f627ec0(local_2c,2);
    uVar3 = 1;
  }
  return uVar3;
}



// Function: FUN_6f631660 at 6f631660

undefined4 FUN_6f631660(void)

{
  return 0;
}



// Function: _strcspn at 6f631670

/* Library Function - Single Match
    _strcspn
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

size_t __cdecl _strcspn(char *_Str,char *_Control)

{
  byte bVar1;
  size_t sVar2;
  byte abStack_28 [32];
  
  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    bVar1 = *_Control;
    if (bVar1 == 0) break;
    _Control = (char *)((byte *)_Control + 1);
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  sVar2 = 0xffffffff;
  do {
    sVar2 = sVar2 + 1;
    bVar1 = *_Str;
    if (bVar1 == 0) {
      return sVar2;
    }
    _Str = (char *)((byte *)_Str + 1);
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return sVar2;
}



// Function: _strncmp at 6f6316b0

/* Library Function - Single Match
    _strncmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _strncmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  char cVar1;
  char cVar2;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  
  sVar3 = _MaxCount;
  pcVar6 = _Str1;
  if (_MaxCount != 0) {
    do {
      if (sVar3 == 0) break;
      sVar3 = sVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    iVar4 = _MaxCount - sVar3;
    do {
      pcVar6 = _Str2;
      pcVar7 = _Str1;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar7 = _Str1 + 1;
      pcVar6 = _Str2 + 1;
      cVar2 = *_Str1;
      cVar1 = *_Str2;
      _Str2 = pcVar6;
      _Str1 = pcVar7;
    } while (cVar1 == cVar2);
    uVar5 = 0;
    if ((byte)pcVar6[-1] <= (byte)pcVar7[-1]) {
      if (pcVar6[-1] == pcVar7[-1]) {
        return 0;
      }
      uVar5 = 0xfffffffe;
    }
    _MaxCount = ~uVar5;
  }
  return _MaxCount;
}



// Function: _strpbrk at 6f6316f0

/* Library Function - Single Match
    _strpbrk
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strpbrk(char *_Str,char *_Control)

{
  byte bVar1;
  byte *pbVar2;
  byte abStack_28 [32];
  
  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    bVar1 = *_Control;
    if (bVar1 == 0) break;
    _Control = (char *)((byte *)_Control + 1);
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  do {
    pbVar2 = (byte *)_Str;
    bVar1 = *pbVar2;
    if (bVar1 == 0) {
      return (char *)(uint)bVar1;
    }
    _Str = (char *)(pbVar2 + 1);
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return (char *)pbVar2;
}



// Function: FUN_6f631730 at 6f631730

undefined4 __cdecl FUN_6f631730(byte *param_1,undefined4 *param_2,LPSTR param_3)

{
  ushort extraout_AX;
  undefined4 uVar1;
  int iVar2;
  uint uVar4;
  BOOL BVar5;
  ushort local_94;
  ushort uStack_92;
  ushort local_90;
  LCID local_8c;
  int local_88;
  WCHAR local_84 [64];
  LCID LVar3;
  
  local_88 = 0;
  if ((param_2 == (undefined4 *)0x0) && (param_3 == (LPSTR)0x0)) {
    uVar1 = 0;
  }
  else {
    local_94 = 0;
    uStack_92 = 0;
    local_90 = 0;
    if ((param_1 == (byte *)0x0) ||
       ((*param_1 == 0 || (local_94 = FUN_6f631af0(param_1), local_94 != 0)))) {
      if ((param_1 == (byte *)0xffffffc0) ||
         ((param_1[0x40] == 0 || (uStack_92 = FUN_6f631b80(param_1 + 0x40), uStack_92 != 0)))) {
        if ((param_1 != (byte *)0xffffff80) &&
           ((param_1[0x80] != 0 && (iVar2 = _strcmp((char *)(param_1 + 0x80),"ACP"), iVar2 != 0))))
        {
          iVar2 = _strcmp((char *)(param_1 + 0x80),"OCP");
          if (iVar2 == 0) {
            local_88 = 1;
          }
          else {
            local_90 = FUN_6f6340b0(param_1 + 0x80);
            if (local_90 == 0) {
              return 0;
            }
          }
        }
        if (local_94 == 0) {
          if (uStack_92 == 0) {
            LVar3 = GetUserDefaultLCID();
            extraout_AX = (ushort)LVar3;
            local_94 = extraout_AX;
            uStack_92 = extraout_AX;
            if (local_90 == 0) {
              local_8c = GetUserDefaultLCID();
            }
          }
          else {
            uVar4 = FUN_6f631c10(uStack_92);
            local_94 = (ushort)uVar4;
            uStack_92 = local_94;
            if (local_90 == 0) {
              local_8c = uVar4 & 0xffff;
            }
          }
        }
        else if (uStack_92 == 0) {
          uStack_92 = local_94;
          if (local_90 == 0) {
            local_8c = (LCID)local_94;
          }
        }
        else {
          iVar2 = FUN_6f631cc0(&uStack_92,&local_94);
          if (iVar2 == 0) {
            return 0;
          }
          if (local_90 == 0) {
            local_8c = (LCID)uStack_92;
          }
        }
        if (local_90 == 0) {
          iVar2 = FUN_6f633980(local_8c,(-(uint)(local_88 != 0) & 0xfffff007) + 0x1004,local_84,0x40
                               ,0);
          if (iVar2 == 0) {
            return 0;
          }
          local_90 = FUN_6f633c90((ushort *)local_84,(undefined4 *)0x0,10);
        }
        BVar5 = IsValidCodePage((uint)local_90);
        if (BVar5 == 0) {
          uVar1 = 0;
        }
        else {
          BVar5 = IsValidLocale((uint)local_94,1);
          if (BVar5 == 0) {
            uVar1 = 0;
          }
          else {
            if (param_2 != (undefined4 *)0x0) {
              *param_2 = CONCAT22(uStack_92,local_94);
              *(ushort *)(param_2 + 1) = local_90;
            }
            if (param_3 != (LPSTR)0x0) {
              iVar2 = FUN_6f633b00((uint)local_94,0x1001,param_3,0x40,0);
              if (iVar2 == 0) {
                return 0;
              }
              iVar2 = FUN_6f633b00((uint)uStack_92,0x1002,param_3 + 0x40,0x40,0);
              if (iVar2 == 0) {
                return 0;
              }
              __itoa((uint)local_90,param_3 + 0x80,10);
            }
            uVar1 = 1;
          }
        }
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



// Function: FUN_6f631af0 at 6f631af0

undefined2 __cdecl FUN_6f631af0(byte *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int local_14;
  int local_8;
  
  local_14 = 0;
  local_8 = 99;
  do {
    iVar2 = (local_14 + local_8) / 2;
    uVar3 = FUN_6f634200(param_1,(&PTR_DAT_6f63c1e0)[iVar2 * 2]);
    if (uVar3 == 0) {
      return *(undefined2 *)(&DAT_6f63c1e4 + iVar2 * 8);
    }
    iVar1 = iVar2;
    if ((int)uVar3 < 0) {
      iVar1 = local_14;
      local_8 = iVar2;
    }
    local_14 = iVar1;
  } while (local_14 + 1 != local_8);
  return 0;
}



// Function: FUN_6f631b80 at 6f631b80

undefined2 __cdecl FUN_6f631b80(byte *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int local_14;
  int local_8;
  
  local_14 = 0;
  local_8 = 0x57;
  do {
    iVar2 = (local_14 + local_8) / 2;
    uVar3 = FUN_6f634200(param_1,(&PTR_DAT_6f63c4f8)[iVar2 * 2]);
    if (uVar3 == 0) {
      return *(undefined2 *)(&DAT_6f63c4fc + iVar2 * 8);
    }
    iVar1 = iVar2;
    if ((int)uVar3 < 0) {
      iVar1 = local_14;
      local_8 = iVar2;
    }
    local_14 = iVar1;
  } while (local_14 + 1 != local_8);
  return 0;
}



// Function: FUN_6f631c10 at 6f631c10

uint __cdecl FUN_6f631c10(ushort param_1)

{
  uint uVar1;
  uint local_8;
  
  if (100 < param_1) {
    uVar1 = FUN_6f631c90(param_1);
    local_8 = uVar1 & 0xffff;
    if (local_8 != 0) {
      return uVar1;
    }
  }
  if (param_1 % 100 < 0x5b) {
    uVar1 = (uint)*(ushort *)(&DAT_6f63c7b0 + (uint)(param_1 % 100) * 6);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_6f631c90 at 6f631c90

undefined4 __cdecl FUN_6f631c90(short param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0x354) {
    uVar1 = 0xc04;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_6f631cc0 at 6f631cc0

undefined4 __cdecl FUN_6f631cc0(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  ushort uVar3;
  uint local_10;
  
  uVar3 = *param_1 % 100;
  if (uVar3 < 0x5b) {
    local_10 = 0;
    while ((local_10 < 3 &&
           (uVar1 = *(ushort *)(&DAT_6f63c7b0 + local_10 * 2 + (uint)uVar3 * 6), uVar1 != 0))) {
      if ((uVar1 & 0x3ff) == (*param_2 & 0x3ff)) {
        if ((int)(uint)*param_2 >> 10 == 0) {
          *param_2 = uVar1;
        }
        *param_1 = uVar1;
        return 1;
      }
      local_10 = local_10 + 1;
    }
    *param_1 = *(ushort *)(&DAT_6f63c7b0 + (uint)uVar3 * 6);
    if (*param_1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_6f631dd0 at 6f631dd0

undefined4 * __cdecl FUN_6f631dd0(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((param_2 < param_1) && (param_1 < (undefined4 *)(param_3 + (int)param_2))) {
    puVar3 = (undefined4 *)((param_3 - 4) + (int)param_2);
    puVar4 = (undefined4 *)((param_3 - 4) + (int)param_1);
    if (((uint)puVar4 & 3) == 0) {
      uVar1 = param_3 >> 2;
      uVar2 = param_3 & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar2) {
        case 0:
          return param_1;
        case 2:
          goto switchD_6f631f87_caseD_2;
        case 3:
          goto switchD_6f631f87_caseD_3;
        }
        goto switchD_6f631f87_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_6f631f87_caseD_0;
      case 1:
        goto switchD_6f631f87_caseD_1;
      case 2:
        goto switchD_6f631f87_caseD_2;
      case 3:
        goto switchD_6f631f87_caseD_3;
      default:
        uVar1 = param_3 - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          puVar3 = (undefined4 *)((int)puVar3 + -1);
          uVar1 = uVar1 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_6f631f87_caseD_2;
            case 3:
              goto switchD_6f631f87_caseD_3;
            }
            goto switchD_6f631f87_caseD_1;
          }
          break;
        case 2:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          puVar3 = (undefined4 *)((int)puVar3 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_6f631f87_caseD_2;
            case 3:
              goto switchD_6f631f87_caseD_3;
            }
            goto switchD_6f631f87_caseD_1;
          }
          break;
        case 3:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_6f631f87_caseD_2;
            case 3:
              goto switchD_6f631f87_caseD_3;
            }
            goto switchD_6f631f87_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar4[7 - uVar1] = puVar3[7 - uVar1];
    case 6:
      puVar4[6 - uVar1] = puVar3[6 - uVar1];
    case 5:
      puVar4[5 - uVar1] = puVar3[5 - uVar1];
    case 4:
      puVar4[4 - uVar1] = puVar3[4 - uVar1];
    case 3:
      puVar4[3 - uVar1] = puVar3[3 - uVar1];
    case 2:
      puVar4[2 - uVar1] = puVar3[2 - uVar1];
    case 1:
      puVar4[1 - uVar1] = puVar3[1 - uVar1];
      puVar3 = puVar3 + -uVar1;
      puVar4 = puVar4 + -uVar1;
    }
    switch(uVar2) {
    case 1:
switchD_6f631f87_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_6f631f87_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_6f631f87_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_6f631f87_caseD_0:
    return param_1;
  }
  puVar3 = param_1;
  if (((uint)param_1 & 3) == 0) {
    uVar1 = param_3 >> 2;
    uVar2 = param_3 & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *param_2;
        param_2 = param_2 + 1;
        puVar3 = puVar3 + 1;
      }
      switch(uVar2) {
      case 0:
        return param_1;
      case 2:
        goto switchD_6f631e05_caseD_2;
      case 3:
        goto switchD_6f631e05_caseD_3;
      }
      goto switchD_6f631e05_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_6f631e05_caseD_0;
    case 1:
      goto switchD_6f631e05_caseD_1;
    case 2:
      goto switchD_6f631e05_caseD_2;
    case 3:
      goto switchD_6f631e05_caseD_3;
    default:
      uVar1 = (param_3 - 4) + ((uint)param_1 & 3);
      switch((uint)param_1 & 3) {
      case 1:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);
        param_2 = (undefined4 *)((int)param_2 + 3);
        puVar3 = (undefined4 *)((int)param_1 + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_6f631e05_caseD_2;
          case 3:
            goto switchD_6f631e05_caseD_3;
          }
          goto switchD_6f631e05_caseD_1;
        }
        break;
      case 2:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        param_2 = (undefined4 *)((int)param_2 + 2);
        puVar3 = (undefined4 *)((int)param_1 + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_6f631e05_caseD_2;
          case 3:
            goto switchD_6f631e05_caseD_3;
          }
          goto switchD_6f631e05_caseD_1;
        }
        break;
      case 3:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        puVar3 = (undefined4 *)((int)param_1 + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_6f631e05_caseD_2;
          case 3:
            goto switchD_6f631e05_caseD_3;
          }
          goto switchD_6f631e05_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar3[uVar1 - 7] = param_2[uVar1 - 7];
  case 6:
    puVar3[uVar1 - 6] = param_2[uVar1 - 6];
  case 5:
    puVar3[uVar1 - 5] = param_2[uVar1 - 5];
  case 4:
    puVar3[uVar1 - 4] = param_2[uVar1 - 4];
  case 3:
    puVar3[uVar1 - 3] = param_2[uVar1 - 3];
  case 2:
    puVar3[uVar1 - 2] = param_2[uVar1 - 2];
  case 1:
    puVar3[uVar1 - 1] = param_2[uVar1 - 1];
    param_2 = param_2 + uVar1;
    puVar3 = puVar3 + uVar1;
  }
  switch(uVar2) {
  case 1:
switchD_6f631e05_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_6f631e05_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_6f631e05_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_6f631e05_caseD_0:
  return param_1;
}



// Function: FUN_6f632110 at 6f632110

undefined4 __cdecl FUN_6f632110(undefined **param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  if ((param_1 == (undefined **)0x0) &&
     (iVar2 = FUN_6f625320(2,0x6f638510,0x3a,0,(byte *)"stream != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  if (((uint)param_1[3] & 0x40) == 0) {
    FUN_6f62c840(param_1);
    local_8 = FUN_6f6321a0((int *)param_1);
    FUN_6f62c8b0(param_1);
  }
  else {
    param_1[3] = (undefined *)0x0;
  }
  return local_8;
}



// Function: FUN_6f6321a0 at 6f6321a0

undefined4 __cdecl FUN_6f6321a0(int *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  if ((param_1 == (int *)0x0) &&
     (iVar2 = FUN_6f625320(2,0x6f638510,0x77,0,(byte *)"str != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  if ((param_1[3] & 0x83U) != 0) {
    local_8 = FUN_6f62fde0(param_1);
    FUN_6f634400(param_1);
    iVar2 = FUN_6f6342d0(param_1[4]);
    if (iVar2 < 0) {
      local_8 = 0xffffffff;
    }
    else if (param_1[7] != 0) {
      FUN_6f627ec0((void *)param_1[7],2);
      param_1[7] = 0;
    }
  }
  param_1[3] = 0;
  return local_8;
}



// Function: FUN_6f632260 at 6f632260

DWORD __cdecl FUN_6f632260(uint param_1)

{
  undefined4 *puVar1;
  HANDLE hFile;
  BOOL BVar2;
  DWORD *pDVar3;
  DWORD local_8;
  
  if ((DAT_6f63e3e0 <= param_1) ||
     ((*(byte *)((&DAT_6f63e2e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) == 0)) {
    puVar1 = (undefined4 *)FUN_6f62ee40();
    *puVar1 = 9;
    return 0xffffffff;
  }
  FUN_6f62fba0(param_1);
  if ((*(byte *)((&DAT_6f63e2e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0) {
    hFile = (HANDLE)FUN_6f62fa40(param_1);
    BVar2 = FlushFileBuffers(hFile);
    if (BVar2 == 0) {
      local_8 = GetLastError();
    }
    else {
      local_8 = 0;
    }
    if (local_8 == 0) goto LAB_6f63231f;
    pDVar3 = FUN_6f62ee50();
    *pDVar3 = local_8;
  }
  puVar1 = (undefined4 *)FUN_6f62ee40();
  *puVar1 = 9;
  local_8 = 0xffffffff;
LAB_6f63231f:
  __unlock_fhandle(param_1);
  return local_8;
}



// Function: FUN_6f632340 at 6f632340

undefined1 * FUN_6f632340(void)

{
  undefined *puVar1;
  size_t sVar2;
  size_t sVar3;
  undefined1 *puVar4;
  uint *puVar5;
  uint *_Str;
  undefined1 *puVar6;
  undefined1 *local_18;
  uint local_14;
  int local_c;
  
  puVar1 = PTR_PTR_6f63ca8c;
  local_c = 0;
  for (local_14 = 0; local_14 < 7; local_14 = local_14 + 1) {
    sVar2 = _strlen(*(char **)(puVar1 + local_14 * 4));
    sVar3 = _strlen(*(char **)(puVar1 + local_14 * 4 + 0x1c));
    local_c = sVar3 + local_c + 2 + sVar2;
  }
  puVar4 = (undefined1 *)FUN_6f627410((void *)(local_c + 1));
  if (puVar4 != (undefined1 *)0x0) {
    local_18 = puVar4;
    for (local_14 = 0; local_14 < 7; local_14 = local_14 + 1) {
      *local_18 = 0x3a;
      puVar5 = FUN_6f6235b0((uint *)(local_18 + 1),*(uint **)(puVar1 + local_14 * 4));
      sVar2 = _strlen((char *)puVar5);
      puVar6 = (undefined1 *)((int)(local_18 + 1) + sVar2);
      *puVar6 = 0x3a;
      puVar5 = (uint *)(puVar6 + 1);
      _Str = FUN_6f6235b0(puVar5,*(uint **)(puVar1 + local_14 * 4 + 0x1c));
      sVar2 = _strlen((char *)_Str);
      local_18 = (undefined1 *)((int)puVar5 + sVar2);
    }
    *local_18 = 0;
  }
  return puVar4;
}



// Function: FUN_6f632470 at 6f632470

undefined1 * FUN_6f632470(void)

{
  undefined *puVar1;
  size_t sVar2;
  size_t sVar3;
  undefined1 *puVar4;
  uint *puVar5;
  uint *_Str;
  undefined1 *puVar6;
  undefined1 *local_18;
  uint local_14;
  int local_c;
  
  puVar1 = PTR_PTR_6f63ca8c;
  local_c = 0;
  for (local_14 = 0; local_14 < 0xc; local_14 = local_14 + 1) {
    sVar2 = _strlen(*(char **)(puVar1 + local_14 * 4 + 0x38));
    sVar3 = _strlen(*(char **)(puVar1 + local_14 * 4 + 0x68));
    local_c = sVar3 + local_c + 2 + sVar2;
  }
  puVar4 = (undefined1 *)FUN_6f627410((void *)(local_c + 1));
  if (puVar4 != (undefined1 *)0x0) {
    local_18 = puVar4;
    for (local_14 = 0; local_14 < 0xc; local_14 = local_14 + 1) {
      *local_18 = 0x3a;
      puVar5 = FUN_6f6235b0((uint *)(local_18 + 1),*(uint **)(puVar1 + local_14 * 4 + 0x38));
      sVar2 = _strlen((char *)puVar5);
      puVar6 = (undefined1 *)((int)(local_18 + 1) + sVar2);
      *puVar6 = 0x3a;
      puVar5 = (uint *)(puVar6 + 1);
      _Str = FUN_6f6235b0(puVar5,*(uint **)(puVar1 + local_14 * 4 + 0x68));
      sVar2 = _strlen((char *)_Str);
      local_18 = (undefined1 *)((int)puVar5 + sVar2);
    }
    *local_18 = 0;
  }
  return puVar4;
}



// Function: FUN_6f6325a0 at 6f6325a0

undefined4 * FUN_6f6325a0(void)

{
  undefined *puVar1;
  size_t sVar2;
  size_t sVar3;
  size_t sVar4;
  size_t sVar5;
  size_t sVar6;
  undefined4 *puVar7;
  uint *puVar8;
  uint *local_18;
  uint local_14;
  int local_c;
  
  puVar1 = PTR_PTR_6f63ca8c;
  local_c = 0;
  for (local_14 = 0; local_14 < 7; local_14 = local_14 + 1) {
    sVar2 = _strlen(*(char **)(puVar1 + local_14 * 4));
    sVar3 = _strlen(*(char **)(puVar1 + local_14 * 4 + 0x1c));
    local_c = sVar3 + local_c + 2 + sVar2;
  }
  for (local_14 = 0; local_14 < 0xc; local_14 = local_14 + 1) {
    sVar2 = _strlen(*(char **)(puVar1 + local_14 * 4 + 0x38));
    sVar3 = _strlen(*(char **)(puVar1 + local_14 * 4 + 0x68));
    local_c = sVar3 + local_c + 2 + sVar2;
  }
  sVar2 = _strlen(*(char **)(puVar1 + 0x98));
  sVar3 = _strlen(*(char **)(puVar1 + 0x9c));
  sVar4 = _strlen(*(char **)(puVar1 + 0xa0));
  sVar5 = _strlen(*(char **)(puVar1 + 0xa4));
  sVar6 = _strlen(*(char **)(puVar1 + 0xa8));
  puVar7 = (undefined4 *)
           FUN_6f627410((void *)(sVar3 + local_c + sVar2 + sVar4 + sVar5 + sVar6 + 0xb1));
  if (puVar7 != (undefined4 *)0x0) {
    local_18 = puVar7 + 0x2b;
    FUN_6f62e010(puVar7,(undefined4 *)PTR_PTR_6f63ca8c,0xac);
    for (local_14 = 0; local_14 < 7; local_14 = local_14 + 1) {
      puVar7[local_14] = local_18;
      puVar8 = FUN_6f6235b0(local_18,*(uint **)(puVar1 + local_14 * 4));
      sVar2 = _strlen((char *)puVar8);
      local_18 = (uint *)((int)local_18 + sVar2 + 1);
      puVar7[local_14 + 7] = local_18;
      puVar8 = FUN_6f6235b0(local_18,*(uint **)(puVar1 + local_14 * 4 + 0x1c));
      sVar2 = _strlen((char *)puVar8);
      local_18 = (uint *)((int)local_18 + sVar2 + 1);
    }
    for (local_14 = 0; local_14 < 0xc; local_14 = local_14 + 1) {
      puVar7[local_14 + 0xe] = local_18;
      puVar8 = FUN_6f6235b0(local_18,*(uint **)(puVar1 + local_14 * 4 + 0x38));
      sVar2 = _strlen((char *)puVar8);
      local_18 = (uint *)((int)local_18 + sVar2 + 1);
      puVar7[local_14 + 0x1a] = local_18;
      puVar8 = FUN_6f6235b0(local_18,*(uint **)(puVar1 + local_14 * 4 + 0x68));
      sVar2 = _strlen((char *)puVar8);
      local_18 = (uint *)((int)local_18 + sVar2 + 1);
    }
    puVar7[0x26] = local_18;
    puVar8 = FUN_6f6235b0(local_18,*(uint **)(puVar1 + 0x98));
    sVar2 = _strlen((char *)puVar8);
    local_18 = (uint *)((int)local_18 + sVar2 + 1);
    puVar7[0x27] = local_18;
    puVar8 = FUN_6f6235b0(local_18,*(uint **)(puVar1 + 0x9c));
    sVar2 = _strlen((char *)puVar8);
    local_18 = (uint *)((int)local_18 + sVar2 + 1);
    puVar7[0x28] = local_18;
    puVar8 = FUN_6f6235b0(local_18,*(uint **)(puVar1 + 0xa0));
    sVar2 = _strlen((char *)puVar8);
    local_18 = (uint *)((int)local_18 + sVar2 + 1);
    puVar7[0x29] = local_18;
    puVar8 = FUN_6f6235b0(local_18,*(uint **)(puVar1 + 0xa4));
    sVar2 = _strlen((char *)puVar8);
    puVar7[0x2a] = (int)local_18 + sVar2 + 1;
  }
  return puVar7;
}



// Function: FUN_6f632910 at 6f632910

void __cdecl FUN_6f632910(byte *param_1,uint param_2,byte *param_3,int *param_4)

{
  FUN_6f632930(param_1,param_2,param_3,param_4,(undefined *)0x0);
  return;
}



// Function: FUN_6f632930 at 6f632930

int __cdecl FUN_6f632930(byte *param_1,uint param_2,byte *param_3,int *param_4,undefined *param_5)

{
  byte *pbVar1;
  int iVar2;
  bool bVar3;
  undefined *local_14;
  uint local_10;
  int local_c;
  undefined *local_8;
  
  if (param_5 == (undefined *)0x0) {
    local_14 = PTR_PTR_6f63ca8c;
  }
  else {
    local_14 = param_5;
  }
  local_8 = local_14;
  local_10 = param_2;
  InterlockedIncrement(&DAT_6f63d2b0);
  if (DAT_6f63d2ac == 0) {
    local_c = 0;
  }
  else {
    InterlockedDecrement(&DAT_6f63d2b0);
    FUN_6f62c780(0x13);
    local_c = 1;
  }
  for (; (local_10 != 0 && (*param_3 != 0)); param_3 = param_3 + 1) {
    if (*param_3 == 0x25) {
      bVar3 = param_3[1] == 0x23;
      pbVar1 = param_3 + 1;
      if (bVar3) {
        pbVar1 = param_3 + 2;
      }
      param_3 = pbVar1;
      DAT_6f63d1bc = (uint)bVar3;
      FUN_6f632ac0(*param_3,param_4,(int *)&param_1,&local_10,(int)local_8);
    }
    else {
      if (((*(ushort *)(PTR_DAT_6f639900 + (uint)*param_3 * 2) & 0x8000) != 0) && (1 < local_10)) {
        *param_1 = *param_3;
        param_1 = param_1 + 1;
        param_3 = param_3 + 1;
        local_10 = local_10 - 1;
      }
      *param_1 = *param_3;
      param_1 = param_1 + 1;
      local_10 = local_10 - 1;
    }
  }
  if (local_c == 0) {
    InterlockedDecrement(&DAT_6f63d2b0);
  }
  else {
    FUN_6f62c820(0x13);
  }
  if (local_10 == 0) {
    iVar2 = 0;
  }
  else {
    *param_1 = 0;
    iVar2 = param_2 - local_10;
  }
  return iVar2;
}



// Function: FUN_6f632ac0 at 6f632ac0

void __cdecl FUN_6f632ac0(undefined1 param_1,int *param_2,int *param_3,uint *param_4,int param_5)

{
  int local_c;
  int local_8;
  
  switch(param_1) {
  case 0x25:
    *(undefined1 *)*param_3 = 0x25;
    *param_3 = *param_3 + 1;
    *param_4 = *param_4 - 1;
    break;
  case 0x41:
    FID_conflict__store_str(*(char **)(param_5 + 0x1c + param_2[6] * 4),param_3,(int *)param_4);
    break;
  case 0x42:
    FID_conflict__store_str(*(char **)(param_5 + 0x68 + param_2[4] * 4),param_3,(int *)param_4);
    break;
  case 0x48:
    DAT_6f63d1c0 = DAT_6f63d1bc;
    FUN_6f633140(param_2[2],2,param_3,param_4);
    break;
  case 0x49:
    DAT_6f63d1c0 = DAT_6f63d1bc;
    local_8 = param_2[2] % 0xc;
    if (local_8 == 0) {
      local_8 = 0xc;
    }
    FUN_6f633140(local_8,2,param_3,param_4);
    break;
  case 0x4d:
    DAT_6f63d1c0 = DAT_6f63d1bc;
    FUN_6f633140(param_2[1],2,param_3,param_4);
    break;
  case 0x53:
    DAT_6f63d1c0 = DAT_6f63d1bc;
    FUN_6f633140(*param_2,2,param_3,param_4);
    break;
  case 0x55:
    local_c = param_2[6];
    goto LAB_6f632e6d;
  case 0x57:
    if (param_2[6] == 0) {
      local_c = 6;
    }
    else {
      local_c = param_2[6] + -1;
    }
LAB_6f632e6d:
    DAT_6f63d1c0 = DAT_6f63d1bc;
    if (param_2[7] < local_c) {
      local_8 = 0;
    }
    else {
      local_8 = param_2[7] / 7;
      if (local_c <= param_2[7] % 7) {
        local_8 = local_8 + 1;
      }
    }
    FUN_6f633140(local_8,2,param_3,param_4);
    break;
  case 0x58:
    DAT_6f63d1bc = 0;
    FUN_6f6332a0(*(byte **)(param_5 + 0xa8),param_2,param_3,(int *)param_4,param_5);
    break;
  case 0x59:
    DAT_6f63d1c0 = DAT_6f63d1bc;
    FUN_6f633140((param_2[5] / 100 + 0x13) * 100 + param_2[5] % 100,4,param_3,param_4);
    break;
  case 0x5a:
  case 0x7a:
    FUN_6f6344a0();
    FID_conflict__store_str((&PTR_DAT_6f63cb60)[param_2[8] != 0],param_3,(int *)param_4);
    break;
  case 0x61:
    FID_conflict__store_str(*(char **)(param_5 + param_2[6] * 4),param_3,(int *)param_4);
    break;
  case 0x62:
    FID_conflict__store_str(*(char **)(param_5 + 0x38 + param_2[4] * 4),param_3,(int *)param_4);
    break;
  case 99:
    if (DAT_6f63d1bc == 0) {
      FUN_6f6332a0(*(byte **)(param_5 + 0xa0),param_2,param_3,(int *)param_4,param_5);
      if (*param_4 != 0) {
        *(undefined1 *)*param_3 = 0x20;
        *param_3 = *param_3 + 1;
        *param_4 = *param_4 - 1;
        FUN_6f6332a0(*(byte **)(param_5 + 0xa8),param_2,param_3,(int *)param_4,param_5);
      }
    }
    else {
      DAT_6f63d1bc = 0;
      FUN_6f6332a0(*(byte **)(param_5 + 0xa4),param_2,param_3,(int *)param_4,param_5);
      if (*param_4 != 0) {
        *(undefined1 *)*param_3 = 0x20;
        *param_3 = *param_3 + 1;
        *param_4 = *param_4 - 1;
        FUN_6f6332a0(*(byte **)(param_5 + 0xa8),param_2,param_3,(int *)param_4,param_5);
      }
    }
    break;
  case 100:
    DAT_6f63d1c0 = DAT_6f63d1bc;
    FUN_6f633140(param_2[3],2,param_3,param_4);
    break;
  case 0x6a:
    DAT_6f63d1c0 = DAT_6f63d1bc;
    FUN_6f633140(param_2[7] + 1,3,param_3,param_4);
    break;
  case 0x6d:
    DAT_6f63d1c0 = DAT_6f63d1bc;
    FUN_6f633140(param_2[4] + 1,2,param_3,param_4);
    break;
  case 0x70:
    if (param_2[2] < 0xc) {
      FID_conflict__store_str(*(char **)(param_5 + 0x98),param_3,(int *)param_4);
    }
    else {
      FID_conflict__store_str(*(char **)(param_5 + 0x9c),param_3,(int *)param_4);
    }
    break;
  case 0x77:
    DAT_6f63d1c0 = DAT_6f63d1bc;
    FUN_6f633140(param_2[6],1,param_3,param_4);
    break;
  case 0x78:
    if (DAT_6f63d1bc == 0) {
      FUN_6f6332a0(*(byte **)(param_5 + 0xa0),param_2,param_3,(int *)param_4,param_5);
    }
    else {
      DAT_6f63d1bc = 0;
      FUN_6f6332a0(*(byte **)(param_5 + 0xa4),param_2,param_3,(int *)param_4,param_5);
    }
    break;
  case 0x79:
    DAT_6f63d1c0 = DAT_6f63d1bc;
    FUN_6f633140(param_2[5] % 100,2,param_3,param_4);
  }
  return;
}



// Function: FID_conflict:_store_str at 6f6330f0

/* Library Function - Multiple Matches With Different Base Names
    void __cdecl _store_str(char *,char * *,unsigned int *)
    __store_str
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __cdecl FID_conflict__store_str(char *param_1,int *param_2,int *param_3)

{
  while ((*param_3 != 0 && (*param_1 != '\0'))) {
    *(char *)*param_2 = *param_1;
    *param_2 = *param_2 + 1;
    param_1 = param_1 + 1;
    *param_3 = *param_3 + -1;
  }
  return;
}



// Function: FUN_6f633140 at 6f633140

void __cdecl FUN_6f633140(int param_1,uint param_2,int *param_3,uint *param_4)

{
  undefined4 local_8;
  
  local_8 = 0;
  if (DAT_6f63d1c0 == 0) {
    if (param_2 < *param_4) {
      for (param_2 = param_2 - 1; param_2 != 0xffffffff; param_2 = param_2 - 1) {
        *(char *)(*param_3 + param_2) = (char)(param_1 % 10) + '0';
        param_1 = param_1 / 10;
        local_8 = local_8 + 1;
      }
      *param_3 = *param_3 + local_8;
      *param_4 = *param_4 - local_8;
    }
    else {
      *param_4 = 0;
    }
  }
  else {
    FID_conflict__store_number(param_1,param_3,param_4);
  }
  return;
}



// Function: FID_conflict:_store_number at 6f6331f0

/* Library Function - Multiple Matches With Different Base Names
    void __cdecl _store_number(int,char * *,unsigned int *)
    __store_number
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __cdecl FID_conflict__store_number(int param_1,int *param_2,uint *param_3)

{
  char cVar1;
  uint uVar2;
  char *local_c;
  char *local_8;
  
  local_8 = (char *)*param_2;
  uVar2 = *param_3;
  while (1 < uVar2) {
    *local_8 = (char)(param_1 % 10) + '0';
    local_8 = local_8 + 1;
    *param_3 = *param_3 - 1;
    param_1 = param_1 / 10;
    if (param_1 < 1) break;
    uVar2 = *param_3;
  }
  local_c = (char *)*param_2;
  *param_2 = (int)local_8;
  local_8 = local_8 + -1;
  do {
    cVar1 = *local_8;
    *local_8 = *local_c;
    local_8 = local_8 + -1;
    *local_c = cVar1;
    local_c = local_c + 1;
  } while (local_c < local_8);
  return;
}



// Function: FUN_6f6332a0 at 6f6332a0

void __cdecl FUN_6f6332a0(byte *param_1,int *param_2,int *param_3,int *param_4,int param_5)

{
  uint uVar1;
  uint local_10;
  char local_c;
  byte *local_8;
  
LAB_6f6332a6:
  do {
    if ((*param_1 == 0) || (*param_4 == 0)) {
      return;
    }
    local_c = '\0';
    DAT_6f63d1c0 = 0;
    local_10 = 0;
    local_8 = param_1;
    while (*local_8 == *param_1) {
      local_10 = local_10 + 1;
      local_8 = local_8 + 1;
    }
    switch(*param_1) {
    case 0x27:
      if ((local_10 & 1) == 0) {
        param_1 = param_1 + local_10;
      }
      else {
        param_1 = param_1 + local_10;
        while( true ) {
          if ((*param_1 == 0) || (*param_4 == 0)) goto LAB_6f6332a6;
          if (*param_1 == 0x27) break;
          if ((*(ushort *)(PTR_DAT_6f639900 + (uint)*param_1 * 2) & 0x8000) != 0) {
            *(byte *)*param_3 = *param_1;
            *param_3 = *param_3 + 1;
            param_1 = param_1 + 1;
            *param_4 = *param_4 + -1;
          }
          *(byte *)*param_3 = *param_1;
          *param_3 = *param_3 + 1;
          param_1 = param_1 + 1;
          *param_4 = *param_4 + -1;
        }
        param_1 = param_1 + 1;
      }
      goto LAB_6f6332a6;
    case 0x41:
    case 0x61:
      uVar1 = FUN_6f634200(param_1,(byte *)"am/pm");
      if (uVar1 == 0) {
        local_8 = param_1 + 5;
      }
      else {
        uVar1 = FUN_6f634200(param_1,&DAT_6f638640);
        if (uVar1 == 0) {
          local_8 = param_1 + 3;
        }
      }
      local_c = 'p';
      break;
    case 0x48:
      if (local_10 == 1) {
        DAT_6f63d1c0 = 1;
      }
      else if (local_10 != 2) break;
      local_c = 'H';
      break;
    case 0x4d:
      switch(local_10) {
      case 1:
        DAT_6f63d1c0 = 1;
      case 2:
        local_c = 'm';
        break;
      case 3:
        local_c = 'b';
        break;
      case 4:
        local_c = 'B';
      }
      break;
    case 100:
      switch(local_10) {
      case 1:
        DAT_6f63d1c0 = 1;
      case 2:
        local_c = 'd';
        break;
      case 3:
        local_c = 'a';
        break;
      case 4:
        local_c = 'A';
      }
      break;
    case 0x68:
      if (local_10 == 1) {
        DAT_6f63d1c0 = 1;
      }
      else if (local_10 != 2) break;
      local_c = 'I';
      break;
    case 0x6d:
      if (local_10 == 1) {
        DAT_6f63d1c0 = 1;
      }
      else if (local_10 != 2) break;
      local_c = 'M';
      break;
    case 0x73:
      if (local_10 == 1) {
        DAT_6f63d1c0 = 1;
      }
      else if (local_10 != 2) break;
      local_c = 'S';
      break;
    case 0x79:
      if (local_10 == 2) {
        local_c = 'y';
      }
      else if (local_10 == 4) {
        local_c = 'Y';
      }
    }
    if (local_c == '\0') {
      if ((*(ushort *)(PTR_DAT_6f639900 + (uint)*param_1 * 2) & 0x8000) != 0) {
        *(byte *)*param_3 = *param_1;
        *param_3 = *param_3 + 1;
        param_1 = param_1 + 1;
        *param_4 = *param_4 + -1;
      }
      *(byte *)*param_3 = *param_1;
      *param_3 = *param_3 + 1;
      param_1 = param_1 + 1;
      *param_4 = *param_4 + -1;
    }
    else {
      FUN_6f632ac0(local_c,param_2,param_3,(uint *)param_4,param_5);
      param_1 = local_8;
    }
  } while( true );
}



// Function: FUN_6f6336e0 at 6f6336e0

undefined4 __cdecl FUN_6f6336e0(int param_1,LCID param_2,LCTYPE param_3,int *param_4)

{
  byte bVar1;
  DWORD DVar2;
  void *pvVar3;
  int iVar4;
  uint local_ac;
  int local_a4;
  CHAR local_90 [128];
  LPSTR local_10;
  void *local_c;
  int local_8;
  
  if (param_1 != 1) {
    if (param_1 != 0) {
      return 0xffffffff;
    }
    iVar4 = FUN_6f633980(param_2,param_3,(LPWSTR)&DAT_6f63d1c8,4,0);
    if (iVar4 != 0) {
      *(undefined1 *)param_4 = 0;
      local_a4 = 0;
      while( true ) {
        if (3 < local_a4) {
          return 0;
        }
        if (DAT_6f6398f0 < 2) {
          bVar1 = (&DAT_6f63d1c8)[local_a4 * 2];
          local_ac = *(ushort *)(PTR_DAT_6f639900 + (uint)bVar1 * 2) & 4;
        }
        else {
          bVar1 = (&DAT_6f63d1c8)[local_a4 * 2];
          local_ac = FUN_6f62acf0((uint)bVar1,4);
        }
        if (local_ac == 0) break;
        *(byte *)param_4 = (char)*param_4 * '\n' + -0x30 + bVar1;
        local_a4 = local_a4 + 1;
      }
      return 0;
    }
    return 0xffffffff;
  }
  local_10 = local_90;
  local_8 = 0;
  local_c = (void *)FUN_6f633b00(param_2,param_3,local_10,0x80,0);
  if (local_c == (void *)0x0) {
    DVar2 = GetLastError();
    if (((DVar2 != 0x7a) ||
        (pvVar3 = (void *)FUN_6f633b00(param_2,param_3,(LPSTR)0x0,0,0), pvVar3 == (void *)0x0)) ||
       (local_10 = (LPSTR)FUN_6f627430(pvVar3,2,0x6f63864c,0x58), local_10 == (LPSTR)0x0))
    goto LAB_6f63382d;
    local_8 = 1;
    local_c = (void *)FUN_6f633b00(param_2,param_3,local_10,(int)pvVar3,0);
    if (local_c == (void *)0x0) goto LAB_6f63382d;
  }
  iVar4 = FUN_6f627430(local_c,2,0x6f63864c,99);
  *param_4 = iVar4;
  if (*param_4 != 0) {
    _strncpy((char *)*param_4,local_10,(size_t)local_c);
    if (local_8 != 0) {
      FUN_6f627ec0(local_10,2);
    }
    return 0;
  }
LAB_6f63382d:
  if (local_8 != 0) {
    FUN_6f627ec0(local_10,2);
  }
  return 0xffffffff;
}



// Function: FUN_6f633970 at 6f633970

undefined * FUN_6f633970(void)

{
  return PTR_PTR_6f63cac8;
}



// Function: FUN_6f633980 at 6f633980

void __cdecl FUN_6f633980(LCID param_1,LCTYPE param_2,LPWSTR param_3,int param_4,UINT param_5)

{
  int iVar1;
  void *cchData;
  LPSTR lpLCData;
  
  if (DAT_6f63d1d4 == 0) {
    iVar1 = GetLocaleInfoW(0,1,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = GetLocaleInfoA(0,1,(LPSTR)0x0,0);
      if (iVar1 == 0) {
        return;
      }
      DAT_6f63d1d4 = 2;
    }
    else {
      DAT_6f63d1d4 = 1;
    }
  }
  if (DAT_6f63d1d4 == 1) {
    GetLocaleInfoW(param_1,param_2,param_3,param_4);
  }
  else if (DAT_6f63d1d4 == 2) {
    if (param_5 == 0) {
      param_5 = DAT_6f63d160;
    }
    cchData = (void *)GetLocaleInfoA(param_1,param_2,(LPSTR)0x0,0);
    if ((cchData != (void *)0x0) &&
       (lpLCData = (LPSTR)FUN_6f627430(cchData,2,0x6f638658,100), lpLCData != (LPSTR)0x0)) {
      iVar1 = GetLocaleInfoA(param_1,param_2,lpLCData,(int)cchData);
      if (iVar1 != 0) {
        if (param_4 == 0) {
          iVar1 = MultiByteToWideChar(param_5,1,lpLCData,-1,(LPWSTR)0x0,0);
        }
        else {
          iVar1 = MultiByteToWideChar(param_5,1,lpLCData,-1,param_3,param_4);
        }
        if (iVar1 != 0) {
          FUN_6f627ec0(lpLCData,2);
          return;
        }
      }
      FUN_6f627ec0(lpLCData,2);
    }
  }
  return;
}



// Function: FUN_6f633b00 at 6f633b00

void __cdecl FUN_6f633b00(LCID param_1,LCTYPE param_2,LPSTR param_3,int param_4,UINT param_5)

{
  int iVar1;
  LPWSTR lpLCData;
  
  if (DAT_6f63d1d8 == 0) {
    iVar1 = GetLocaleInfoA(0,1,(LPSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = GetLocaleInfoW(0,1,(LPWSTR)0x0,0);
      if (iVar1 == 0) {
        return;
      }
      DAT_6f63d1d8 = 1;
    }
    else {
      DAT_6f63d1d8 = 2;
    }
  }
  if (DAT_6f63d1d8 == 2) {
    GetLocaleInfoA(param_1,param_2,param_3,param_4);
  }
  else if (DAT_6f63d1d8 == 1) {
    if (param_5 == 0) {
      param_5 = DAT_6f63d160;
    }
    iVar1 = GetLocaleInfoW(param_1,param_2,(LPWSTR)0x0,0);
    if ((iVar1 != 0) &&
       (lpLCData = (LPWSTR)FUN_6f627430((void *)(iVar1 << 1),2,0x6f638658,0xd2),
       lpLCData != (LPWSTR)0x0)) {
      iVar1 = GetLocaleInfoW(param_1,param_2,lpLCData,iVar1);
      if (iVar1 != 0) {
        if (param_4 == 0) {
          iVar1 = WideCharToMultiByte(param_5,0x220,lpLCData,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0
                                     );
        }
        else {
          iVar1 = WideCharToMultiByte(param_5,0x220,lpLCData,-1,param_3,param_4,(LPCSTR)0x0,
                                      (LPBOOL)0x0);
        }
        if (iVar1 != 0) {
          FUN_6f627ec0(lpLCData,2);
          return;
        }
      }
      FUN_6f627ec0(lpLCData,2);
    }
  }
  return;
}



// Function: FUN_6f633c90 at 6f633c90

void __cdecl FUN_6f633c90(ushort *param_1,undefined4 *param_2,uint param_3)

{
  FUN_6f633cb0(param_1,param_2,param_3,0);
  return;
}



// Function: FUN_6f633cb0 at 6f633cb0

ushort * __cdecl FUN_6f633cb0(ushort *param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  ushort uVar1;
  uint uVar2;
  ushort *puVar3;
  ushort *puVar4;
  undefined4 *puVar5;
  undefined2 extraout_var;
  uint local_18;
  ushort *local_10;
  ushort *local_8;
  
  local_10 = (ushort *)0x0;
  uVar1 = *param_1;
  puVar4 = param_1;
  local_8 = param_1 + 1;
  while (uVar2 = FUN_6f634f00(CONCAT22((short)((uint)puVar4 >> 0x10),uVar1),8), uVar2 != 0) {
    uVar1 = *local_8;
    puVar4 = local_8 + 1;
    local_8 = puVar4;
  }
  if (uVar1 == 0x2d) {
    param_4 = param_4 | 2;
    uVar1 = *local_8;
    local_8 = local_8 + 1;
  }
  else if (uVar1 == 0x2b) {
    uVar1 = *local_8;
    local_8 = local_8 + 1;
  }
  if ((((int)param_3 < 0) || (param_3 == 1)) || (0x24 < (int)param_3)) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = param_1;
    }
    return (ushort *)0x0;
  }
  if (param_3 == 0) {
    if (uVar1 == 0x30) {
      if ((*local_8 == 0x78) || (*local_8 == 0x58)) {
        param_3 = 0x10;
      }
      else {
        param_3 = 8;
      }
    }
    else {
      param_3 = 10;
    }
  }
  if (((param_3 == 0x10) && (uVar1 == 0x30)) && ((*local_8 == 0x78 || (*local_8 == 0x58)))) {
    uVar1 = local_8[1];
    local_8 = local_8 + 2;
  }
  puVar3 = (ushort *)(0xffffffff / (ulonglong)param_3);
  puVar4 = puVar3;
  do {
    uVar2 = FUN_6f634f00(CONCAT22((short)((uint)puVar4 >> 0x10),uVar1),4);
    if (uVar2 == 0) {
      uVar2 = FUN_6f634f00(CONCAT22(extraout_var,uVar1),0x103);
      if (uVar2 == 0) {
LAB_6f633ec1:
        local_8 = local_8 + -1;
        if ((param_4 & 8) == 0) {
          if (param_2 != (undefined4 *)0x0) {
            local_8 = param_1;
          }
          local_10 = (ushort *)0x0;
        }
        else if (((param_4 & 4) != 0) ||
                (((param_4 & 1) == 0 &&
                 ((((param_4 & 2) != 0 && ((ushort *)0x80000000 < local_10)) ||
                  (((param_4 & 2) == 0 && ((ushort *)0x7fffffff < local_10)))))))) {
          puVar5 = (undefined4 *)FUN_6f62ee40();
          *puVar5 = 0x22;
          if ((param_4 & 1) == 0) {
            if ((param_4 & 2) == 0) {
              local_10 = (ushort *)0x7fffffff;
            }
            else {
              local_10 = (ushort *)0x80000000;
            }
          }
          else {
            local_10 = (ushort *)0xffffffff;
          }
        }
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = local_8;
        }
        if ((param_4 & 2) == 0) {
          return local_10;
        }
        return (ushort *)-(int)local_10;
      }
      uVar2 = FUN_6f634d90(uVar1);
      local_18 = (uVar2 & 0xffff) - 0x37;
    }
    else {
      local_18 = uVar1 - 0x30;
    }
    if (param_3 <= local_18) goto LAB_6f633ec1;
    if ((local_10 < puVar3) ||
       ((local_10 == puVar3 && (local_18 <= (uint)(0xffffffff % (ulonglong)param_3))))) {
      local_10 = (ushort *)((int)local_10 * param_3 + local_18);
      param_4 = param_4 | 8;
    }
    else {
      param_4 = param_4 | 0xc;
    }
    uVar1 = *local_8;
    puVar4 = local_8 + 1;
    local_8 = puVar4;
  } while( true );
}



// Function: FUN_6f633f90 at 6f633f90

void __cdecl FUN_6f633f90(ushort *param_1,undefined4 *param_2,uint param_3)

{
  FUN_6f633cb0(param_1,param_2,param_3,1);
  return;
}



// Function: FUN_6f633fb0 at 6f633fb0

int __cdecl FUN_6f633fb0(byte *param_1)

{
  byte *pbVar1;
  uint uVar2;
  uint local_18;
  uint local_14;
  int local_c;
  uint local_8;
  
  while( true ) {
    if (DAT_6f6398f0 < 2) {
      local_14 = *(ushort *)(PTR_DAT_6f639900 + (uint)*param_1 * 2) & 8;
    }
    else {
      local_14 = FUN_6f62acf0((uint)*param_1,8);
    }
    if (local_14 == 0) break;
    param_1 = param_1 + 1;
  }
  uVar2 = (uint)*param_1;
  if ((uVar2 == 0x2d) || (pbVar1 = param_1 + 1, local_8 = uVar2, uVar2 == 0x2b)) {
    local_8 = (uint)param_1[1];
    pbVar1 = param_1 + 2;
  }
  param_1 = pbVar1;
  local_c = 0;
  while( true ) {
    if (DAT_6f6398f0 < 2) {
      local_18 = *(ushort *)(PTR_DAT_6f639900 + local_8 * 2) & 4;
    }
    else {
      local_18 = FUN_6f62acf0(local_8,4);
    }
    if (local_18 == 0) break;
    local_c = local_c * 10 + -0x30 + local_8;
    local_8 = (uint)*param_1;
    param_1 = param_1 + 1;
  }
  if (uVar2 == 0x2d) {
    local_c = -local_c;
  }
  return local_c;
}



// Function: FUN_6f6340b0 at 6f6340b0

void __cdecl FUN_6f6340b0(byte *param_1)

{
  FUN_6f633fb0(param_1);
  return;
}



// Function: FUN_6f6340d0 at 6f6340d0

undefined8 __cdecl FUN_6f6340d0(byte *param_1)

{
  byte *pbVar1;
  uint uVar2;
  bool bVar3;
  uint local_1c;
  uint local_18;
  undefined8 local_10;
  uint local_8;
  
  while( true ) {
    if (DAT_6f6398f0 < 2) {
      local_18 = *(ushort *)(PTR_DAT_6f639900 + (uint)*param_1 * 2) & 8;
    }
    else {
      local_18 = FUN_6f62acf0((uint)*param_1,8);
    }
    if (local_18 == 0) break;
    param_1 = param_1 + 1;
  }
  uVar2 = (uint)*param_1;
  if ((uVar2 == 0x2d) || (pbVar1 = param_1 + 1, local_8 = uVar2, uVar2 == 0x2b)) {
    local_8 = (uint)param_1[1];
    pbVar1 = param_1 + 2;
  }
  param_1 = pbVar1;
  local_10 = 0;
  while( true ) {
    if (DAT_6f6398f0 < 2) {
      local_1c = *(ushort *)(PTR_DAT_6f639900 + local_8 * 2) & 4;
    }
    else {
      local_1c = FUN_6f62acf0(local_8,4);
    }
    if (local_1c == 0) break;
    local_10 = __allmul((uint)local_10,local_10._4_4_,10,0);
    local_10 = local_10 + (int)(local_8 - 0x30);
    local_8 = (uint)*param_1;
    param_1 = param_1 + 1;
  }
  if (uVar2 == 0x2d) {
    bVar3 = (uint)local_10 != 0;
    local_10._0_4_ = -(uint)local_10;
    local_10._4_4_ = -(local_10._4_4_ + (uint)bVar3);
  }
  return CONCAT44(local_10._4_4_,(uint)local_10);
}



// Function: FUN_6f634200 at 6f634200

uint __cdecl FUN_6f634200(byte *param_1,byte *param_2)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  iVar2 = DAT_6f63d2b0;
  if (DAT_6f63d150 == 0) {
    bVar5 = 0xff;
    do {
      do {
        if (bVar5 == 0) goto LAB_6f63424e;
        bVar5 = *param_2;
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        param_1 = param_1 + 1;
      } while (bVar4 == bVar5);
      bVar3 = bVar5 + 0xbf + (-((byte)(bVar5 + 0xbf) < 0x1a) & 0x20U) + 0x41;
      bVar4 = bVar4 + 0xbf;
      bVar5 = bVar4 + (-(bVar4 < 0x1a) & 0x20U) + 0x41;
    } while (bVar5 == bVar3);
    bVar5 = (bVar5 < bVar3) * -2 + 1;
LAB_6f63424e:
    uVar6 = (uint)(char)bVar5;
  }
  else {
    LOCK();
    DAT_6f63d2b0 = DAT_6f63d2b0 + 1;
    UNLOCK();
    bVar1 = 0 < DAT_6f63d2ac;
    if (bVar1) {
      LOCK();
      UNLOCK();
      DAT_6f63d2b0 = iVar2;
      FUN_6f62c780(0x13);
    }
    uVar8 = (uint)bVar1;
    uVar6 = 0xff;
    uVar7 = 0;
    do {
      do {
        if ((char)uVar6 == '\0') goto LAB_6f6342af;
        bVar5 = *param_2;
        uVar6 = CONCAT31((int3)(uVar6 >> 8),bVar5);
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        uVar7 = CONCAT31((int3)(uVar7 >> 8),bVar4);
        param_1 = param_1 + 1;
      } while (bVar5 == bVar4);
      uVar7 = FUN_6f635090(uVar7);
      uVar6 = FUN_6f635090(uVar6);
    } while ((byte)uVar7 == (byte)uVar6);
    uVar7 = (uint)((byte)uVar7 < (byte)uVar6);
    uVar6 = (1 - uVar7) - (uint)(uVar7 != 0);
LAB_6f6342af:
    if (uVar8 == 0) {
      LOCK();
      DAT_6f63d2b0 = DAT_6f63d2b0 + -1;
      UNLOCK();
    }
    else {
      FUN_6f62c820(0x13);
    }
  }
  return uVar6;
}



// Function: FUN_6f6342d0 at 6f6342d0

undefined4 __cdecl FUN_6f6342d0(uint param_1)

{
  undefined4 *puVar1;
  DWORD *pDVar2;
  undefined4 uVar3;
  
  if ((param_1 < DAT_6f63e3e0) &&
     ((*(byte *)((&DAT_6f63e2e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_6f62fba0(param_1);
    uVar3 = __close_lk(param_1);
    __unlock_fhandle(param_1);
  }
  else {
    puVar1 = (undefined4 *)FUN_6f62ee40();
    *puVar1 = 9;
    pDVar2 = FUN_6f62ee50();
    *pDVar2 = 0;
    uVar3 = 0xffffffff;
  }
  return uVar3;
}



// Function: __close_lk at 6f634350

/* Library Function - Single Match
    __close_lk
   
   Library: Visual Studio 2003 Debug */

undefined4 __cdecl __close_lk(uint param_1)

{
  int iVar1;
  int iVar2;
  HANDLE hObject;
  BOOL BVar3;
  undefined4 uVar4;
  ulong local_8;
  
  iVar1 = FUN_6f62fa40(param_1);
  if (iVar1 != -1) {
    if ((param_1 == 1) || (param_1 == 2)) {
      iVar1 = FUN_6f62fa40(1);
      iVar2 = FUN_6f62fa40(2);
      if (iVar1 == iVar2) goto LAB_6f6343a3;
    }
    hObject = (HANDLE)FUN_6f62fa40(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      local_8 = GetLastError();
      goto LAB_6f6343b5;
    }
  }
LAB_6f6343a3:
  local_8 = 0;
LAB_6f6343b5:
  FUN_6f62f960(param_1);
  *(undefined1 *)((&DAT_6f63e2e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = 0;
  if (local_8 == 0) {
    uVar4 = 0;
  }
  else {
    __dosmaperr(local_8);
    uVar4 = 0xffffffff;
  }
  return uVar4;
}



// Function: FUN_6f634400 at 6f634400

void __cdecl FUN_6f634400(undefined4 *param_1)

{
  code *pcVar1;
  int iVar2;
  
  if ((param_1 == (undefined4 *)0x0) &&
     (iVar2 = FUN_6f625320(2,0x6f638664,0x30,0,(byte *)"stream != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if (((param_1[3] & 0x83) != 0) && ((param_1[3] & 8) != 0)) {
    FUN_6f627ec0((void *)param_1[2],2);
    param_1[3] = param_1[3] & 0xfffffbf7;
    *param_1 = 0;
    param_1[2] = 0;
    param_1[1] = 0;
  }
  return;
}



// Function: FUN_6f6344a0 at 6f6344a0

void FUN_6f6344a0(void)

{
  if (DAT_6f63d298 == 0) {
    FUN_6f62c780(0xb);
    if (DAT_6f63d298 == 0) {
      FUN_6f634500();
      DAT_6f63d298 = DAT_6f63d298 + 1;
    }
    FUN_6f62c820(0xb);
  }
  return;
}



// Function: FUN_6f6344e0 at 6f6344e0

void FUN_6f6344e0(void)

{
  FUN_6f62c780(0xb);
  FUN_6f634500();
  FUN_6f62c820(0xb);
  return;
}



// Function: FUN_6f634500 at 6f634500

void FUN_6f634500(void)

{
  char cVar1;
  uint *_Str1;
  DWORD DVar2;
  int iVar3;
  size_t sVar4;
  uint uVar5;
  char *pcVar6;
  uint *local_c;
  
  FUN_6f62c780(0xc);
  DAT_6f63d1e0 = 0;
  DAT_6f63cb78 = 0xffffffff;
  DAT_6f63cb68 = 0xffffffff;
  _Str1 = (uint *)FUN_6f6355d0("TZ");
  if (_Str1 == (uint *)0x0) {
    FUN_6f62c820(0xc);
    DVar2 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_6f63d1e8);
    if (DVar2 != 0xffffffff) {
      DAT_6f63d1e0 = 1;
      DAT_6f63cad0 = DAT_6f63d1e8 * 0x3c;
      if (DAT_6f63d22e != 0) {
        DAT_6f63cad0 = DAT_6f63cad0 + DAT_6f63d23c * 0x3c;
      }
      if ((DAT_6f63d282 == 0) || (DAT_6f63d290 == 0)) {
        DAT_6f63cad4 = 0;
        DAT_6f63cad8 = 0;
      }
      else {
        DAT_6f63cad4 = 1;
        DAT_6f63cad8 = (DAT_6f63d290 - DAT_6f63d23c) * 0x3c;
      }
      FUN_6f6351c0(PTR_DAT_6f63cb60,(LPCWSTR)&DAT_6f63d1ec,0x40);
      FUN_6f6351c0(PTR_DAT_6f63cb64,(LPCWSTR)&DAT_6f63d240,0x40);
      PTR_DAT_6f63cb64[0x3f] = 0;
      PTR_DAT_6f63cb60[0x3f] = 0;
    }
  }
  else if (((char)*_Str1 == '\0') ||
          ((DAT_6f63d294 != (uint *)0x0 &&
           (iVar3 = _strcmp((char *)_Str1,(char *)DAT_6f63d294), iVar3 == 0)))) {
    FUN_6f62c820(0xc);
  }
  else {
    FUN_6f627ec0(DAT_6f63d294,2);
    iVar3 = 0xec;
    pcVar6 = "tzset.c";
    uVar5 = 2;
    sVar4 = _strlen((char *)_Str1);
    DAT_6f63d294 = (uint *)FUN_6f627430((void *)(sVar4 + 1),uVar5,(int)pcVar6,iVar3);
    if (DAT_6f63d294 == (uint *)0x0) {
      FUN_6f62c820(0xc);
    }
    else {
      FUN_6f6235b0(DAT_6f63d294,_Str1);
      FUN_6f62c820(0xc);
      _strncpy(PTR_DAT_6f63cb60,(char *)_Str1,3);
      PTR_DAT_6f63cb60[3] = 0;
      local_c = (uint *)((int)_Str1 + 3);
      cVar1 = *(char *)local_c;
      if (cVar1 == '-') {
        local_c = _Str1 + 1;
      }
      iVar3 = FUN_6f633fb0((byte *)local_c);
      DAT_6f63cad0 = iVar3 * 0xe10;
      for (; ((char)*local_c == '+' || (('/' < (char)*local_c && ((char)*local_c < ':'))));
          local_c = (uint *)((int)local_c + 1)) {
      }
      if ((char)*local_c == ':') {
        local_c = (uint *)((int)local_c + 1);
        iVar3 = FUN_6f633fb0((byte *)local_c);
        DAT_6f63cad0 = DAT_6f63cad0 + iVar3 * 0x3c;
        for (; ('/' < (char)*local_c && ((char)*local_c < ':'));
            local_c = (uint *)((int)local_c + 1)) {
        }
        if ((char)*local_c == ':') {
          local_c = (uint *)((int)local_c + 1);
          iVar3 = FUN_6f633fb0((byte *)local_c);
          DAT_6f63cad0 = DAT_6f63cad0 + iVar3;
          for (; ('/' < (char)*local_c && ((char)*local_c < ':'));
              local_c = (uint *)((int)local_c + 1)) {
          }
        }
      }
      if (cVar1 == '-') {
        DAT_6f63cad0 = -DAT_6f63cad0;
      }
      DAT_6f63cad4 = (int)(char)*local_c;
      if (DAT_6f63cad4 == 0) {
        *PTR_DAT_6f63cb64 = 0;
      }
      else {
        _strncpy(PTR_DAT_6f63cb64,(char *)local_c,3);
        PTR_DAT_6f63cb64[3] = 0;
      }
    }
  }
  return;
}



// Function: FUN_6f634860 at 6f634860

undefined4 __cdecl FUN_6f634860(int *param_1)

{
  undefined4 uVar1;
  
  FUN_6f62c780(0xb);
  uVar1 = FUN_6f634890(param_1);
  FUN_6f62c820(0xb);
  return uVar1;
}



// Function: FUN_6f634890 at 6f634890

undefined4 __cdecl FUN_6f634890(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_6f63cad4 == 0) {
    return 0;
  }
  if ((param_1[5] != DAT_6f63cb68) || (param_1[5] != DAT_6f63cb78)) {
    if (DAT_6f63d1e0 == 0) {
      FUN_6f634b90(1,1,param_1[5],4,1,0,0,2,0,0,0);
      FUN_6f634b90(0,1,param_1[5],10,5,0,0,2,0,0,0);
    }
    else {
      if (DAT_6f63d280 == 0) {
        FUN_6f634b90(1,1,param_1[5],(uint)DAT_6f63d282,(uint)DAT_6f63d286,(uint)DAT_6f63d284,0,
                     (uint)DAT_6f63d288,(uint)DAT_6f63d28a,(uint)DAT_6f63d28c,(uint)DAT_6f63d28e);
      }
      else {
        FUN_6f634b90(1,0,param_1[5],(uint)DAT_6f63d282,0,0,(uint)DAT_6f63d286,(uint)DAT_6f63d288,
                     (uint)DAT_6f63d28a,(uint)DAT_6f63d28c,(uint)DAT_6f63d28e);
      }
      if (DAT_6f63d22c == 0) {
        FUN_6f634b90(0,1,param_1[5],(uint)DAT_6f63d22e,(uint)DAT_6f63d232,(uint)DAT_6f63d230,0,
                     (uint)DAT_6f63d234,(uint)DAT_6f63d236,(uint)DAT_6f63d238,(uint)DAT_6f63d23a);
      }
      else {
        FUN_6f634b90(0,0,param_1[5],(uint)DAT_6f63d22e,0,0,(uint)DAT_6f63d232,(uint)DAT_6f63d234,
                     (uint)DAT_6f63d236,(uint)DAT_6f63d238,(uint)DAT_6f63d23a);
      }
    }
  }
  if (DAT_6f63cb6c < DAT_6f63cb7c) {
    if ((param_1[7] < DAT_6f63cb6c) || (DAT_6f63cb7c < param_1[7])) {
      return 0;
    }
    if ((DAT_6f63cb6c < param_1[7]) && (param_1[7] < DAT_6f63cb7c)) {
      return 1;
    }
  }
  else {
    if ((param_1[7] < DAT_6f63cb7c) || (DAT_6f63cb6c < param_1[7])) {
      return 1;
    }
    if ((DAT_6f63cb7c < param_1[7]) && (param_1[7] < DAT_6f63cb6c)) {
      return 0;
    }
  }
  iVar2 = (*param_1 + param_1[1] * 0x3c + param_1[2] * 0xe10) * 1000;
  if (param_1[7] == DAT_6f63cb6c) {
    if (iVar2 < DAT_6f63cb70) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else if (iVar2 < DAT_6f63cb80) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_6f634b90 at 6f634b90

void __cdecl
FUN_6f634b90(int param_1,int param_2,uint param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9,int param_10,int param_11)

{
  int iVar1;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  if (param_2 == 1) {
    if ((param_3 & 3) == 0) {
      local_10 = *(int *)(&DAT_6f63cb8c + param_4 * 4);
    }
    else {
      local_10 = *(int *)(&DAT_6f63cbc4 + param_4 * 4);
    }
    local_10 = local_10 + 1;
    iVar1 = (int)(local_10 + (param_3 - 0x46) * 0x16d + -0xd + ((int)(param_3 - 1) >> 2)) % 7;
    if (iVar1 < param_6) {
      local_c = (param_5 + -1) * 7 + local_10 + (param_6 - iVar1);
    }
    else {
      local_c = param_5 * 7 + local_10 + (param_6 - iVar1);
    }
    if (param_5 == 5) {
      if ((param_3 & 3) == 0) {
        local_14 = *(int *)(&DAT_6f63cb90 + param_4 * 4);
      }
      else {
        local_14 = *(int *)(&DAT_6f63cbc8 + param_4 * 4);
      }
      if (local_14 < local_c) {
        local_c = local_c + -7;
      }
    }
  }
  else {
    if ((param_3 & 3) == 0) {
      local_18 = *(int *)(&DAT_6f63cb8c + param_4 * 4);
    }
    else {
      local_18 = *(int *)(&DAT_6f63cbc4 + param_4 * 4);
    }
    local_c = local_18 + param_7;
  }
  if (param_1 == 1) {
    DAT_6f63cb6c = local_c;
    DAT_6f63cb70 = param_11 + (param_10 + (param_9 + param_8 * 0x3c) * 0x3c) * 1000;
    DAT_6f63cb68 = param_3;
  }
  else {
    DAT_6f63cb7c = local_c;
    DAT_6f63cb80 = param_11 + (param_10 + (param_9 + param_8 * 0x3c) * 0x3c) * 1000 +
                   DAT_6f63cad8 * 1000;
    if (DAT_6f63cb80 < 0) {
      DAT_6f63cb80 = DAT_6f63cb80 + 86399999;
    }
    else if (86399999 < DAT_6f63cb80) {
      DAT_6f63cb80 = DAT_6f63cb80 + -86399999;
    }
    DAT_6f63cb78 = param_3;
  }
  return;
}



// Function: FUN_6f634d90 at 6f634d90

uint __cdecl FUN_6f634d90(ushort param_1)

{
  ushort uVar1;
  LONG LVar2;
  undefined2 extraout_var;
  undefined2 uVar4;
  uint uVar3;
  undefined2 extraout_var_00;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar5;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar6;
  bool bVar7;
  
  uVar1 = param_1;
  _param_1 = (uint)param_1;
  if (DAT_6f63d150 == 0) {
    if ((0x60 < uVar1) && (uVar1 < 0x7b)) {
      _param_1 = (uint)(ushort)(uVar1 - 0x20);
    }
  }
  else {
    LVar2 = InterlockedIncrement(&DAT_6f63d2b0);
    bVar7 = DAT_6f63d2ac == 0;
    uVar5 = extraout_ECX;
    uVar6 = extraout_EDX;
    uVar4 = (short)((uint)LVar2 >> 0x10);
    if (!bVar7) {
      InterlockedDecrement(&DAT_6f63d2b0);
      FUN_6f62c780(0x13);
      uVar5 = extraout_ECX_00;
      uVar6 = extraout_EDX_00;
      uVar4 = extraout_var;
    }
    uVar3 = FUN_6f634e40(uVar5,uVar6,CONCAT22(uVar4,uVar1));
    if (bVar7) {
      LVar2 = InterlockedDecrement(&DAT_6f63d2b0);
      uVar4 = (short)((uint)LVar2 >> 0x10);
    }
    else {
      FUN_6f62c820(0x13);
      uVar4 = extraout_var_00;
    }
    _param_1 = CONCAT22(uVar4,(short)uVar3);
  }
  return _param_1;
}



// Function: FUN_6f634e40 at 6f634e40

uint __fastcall FUN_6f634e40(undefined4 param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined4 local_8;
  
  uVar1 = param_3 & 0xffff;
  if (uVar1 == 0xffff) {
    uVar1 = param_3 & 0xffff;
  }
  else if (DAT_6f63d150 == 0) {
    if ((0x60 < (param_3 & 0xffff)) && ((param_3 & 0xffff) < 0x7b)) {
      uVar1 = (param_3 & 0xffff) - 0x20;
      param_3 = uVar1 & 0xffff;
    }
    uVar1 = CONCAT22((short)(uVar1 >> 0x10),(undefined2)param_3);
  }
  else {
    local_8 = param_1;
    if (((param_3 & 0xffff) < 0x100) &&
       (uVar1 = FUN_6f634f00(CONCAT22((short)((uint)param_2 >> 0x10),(undefined2)param_3),2),
       uVar1 == 0)) {
      return param_3 & 0xffff;
    }
    iVar2 = FUN_6f635690(DAT_6f63d150,0x200,(LPCWSTR)&param_3,1,(LPWSTR)&local_8,(void *)0x1,0);
    uVar3 = (undefined2)((uint)iVar2 >> 0x10);
    if (iVar2 == 0) {
      uVar1 = CONCAT22(uVar3,(undefined2)param_3);
    }
    else {
      uVar1 = CONCAT22(uVar3,(WCHAR)local_8);
    }
  }
  return uVar1;
}



// Function: FUN_6f634f00 at 6f634f00

uint __cdecl FUN_6f634f00(uint param_1,uint param_2)

{
  int iVar1;
  uint local_8;
  
  if ((param_1 & 0xffff) == 0xffff) {
    return 0;
  }
  if ((param_1 & 0xffff) < 0x100) {
    local_8 = (uint)*(ushort *)(PTR_DAT_6f639904 + (param_1 & 0xffff) * 2);
  }
  else if ((DAT_6f63d150 == 0) ||
          (iVar1 = FUN_6f62ee60(1,(LPCWSTR)&param_1,1,(LPWORD)&local_8,0,0), iVar1 == 0)) {
    return 0;
  }
  return local_8 & 0xffff & param_2 & 0xffff;
}



// Function: FUN_6f634f80 at 6f634f80

void __thiscall FUN_6f634f80(void *this,undefined2 param_1,undefined2 param_2)

{
  undefined4 in_EAX;
  
  FUN_6f634f00(CONCAT22((short)((uint)this >> 0x10),param_1),
               CONCAT22((short)((uint)in_EAX >> 0x10),param_2));
  return;
}



// Function: __allmul at 6f634fa0

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



// Function: FUN_6f634fe0 at 6f634fe0

int __cdecl FUN_6f634fe0(int param_1)

{
  return param_1 + 0x20;
}



// Function: FUN_6f634ff0 at 6f634ff0

uint __cdecl FUN_6f634ff0(uint param_1)

{
  bool bVar1;
  
  if (DAT_6f63d150 == 0) {
    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {
      param_1 = param_1 + 0x20;
    }
  }
  else {
    InterlockedIncrement(&DAT_6f63d2b0);
    bVar1 = DAT_6f63d2ac == 0;
    if (!bVar1) {
      InterlockedDecrement(&DAT_6f63d2b0);
      FUN_6f62c780(0x13);
    }
    param_1 = FUN_6f635090(param_1);
    if (bVar1) {
      InterlockedDecrement(&DAT_6f63d2b0);
    }
    else {
      FUN_6f62c820(0x13);
    }
  }
  return param_1;
}



// Function: FUN_6f635090 at 6f635090

uint __cdecl FUN_6f635090(uint param_1)

{
  int iVar1;
  uint local_14;
  uint local_10;
  char local_c;
  char local_b;
  undefined1 local_a;
  int local_8;
  
  if (DAT_6f63d150 == 0) {
    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {
      param_1 = param_1 + 0x20;
    }
  }
  else {
    if ((int)param_1 < 0x100) {
      if (DAT_6f6398f0 < 2) {
        local_14 = *(ushort *)(PTR_DAT_6f639900 + param_1 * 2) & 1;
      }
      else {
        local_14 = FUN_6f62acf0(param_1,1);
      }
      if (local_14 == 0) {
        return param_1;
      }
    }
    if ((*(ushort *)(PTR_DAT_6f639900 + ((int)param_1 >> 8 & 0xffU) * 2) & 0x8000) == 0) {
      local_c = (char)param_1;
      local_b = '\0';
      local_8 = 1;
    }
    else {
      local_c = (char)(param_1 >> 8);
      local_b = (char)param_1;
      local_a = 0;
      local_8 = 2;
    }
    iVar1 = FUN_6f6359a0(DAT_6f63d150,0x100,&local_c,local_8,(LPWSTR)&local_10,3,0);
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        param_1 = local_10 & 0xff;
      }
      else {
        param_1 = local_10 & 0xff | (local_10 >> 8 & 0xff) << 8;
      }
    }
  }
  return param_1;
}



// Function: FUN_6f6351c0 at 6f6351c0

uint __cdecl FUN_6f6351c0(LPSTR param_1,LPCWSTR param_2,uint param_3)

{
  uint uVar1;
  bool bVar2;
  
  InterlockedIncrement(&DAT_6f63d2b0);
  bVar2 = DAT_6f63d2ac == 0;
  if (!bVar2) {
    InterlockedDecrement(&DAT_6f63d2b0);
    FUN_6f62c780(0x13);
  }
  uVar1 = FUN_6f635240(param_1,param_2,param_3);
  if (bVar2) {
    InterlockedDecrement(&DAT_6f63d2b0);
  }
  else {
    FUN_6f62c820(0x13);
  }
  return uVar1;
}



// Function: FUN_6f635240 at 6f635240

uint __cdecl FUN_6f635240(LPSTR param_1,LPCWSTR param_2,uint param_3)

{
  WCHAR WVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  DWORD DVar6;
  BOOL local_18;
  int local_14;
  CHAR local_10 [4];
  int local_c;
  uint local_8;
  
  local_8 = 0;
  local_18 = 0;
  if ((param_1 == (LPSTR)0x0) || (param_3 != 0)) {
    if ((param_2 == (LPCWSTR)0x0) &&
       (iVar3 = FUN_6f625320(2,0x6f6386bc,0x7e,0,(byte *)"pwcs != NULL"), iVar3 == 1)) {
      pcVar2 = (code *)swi(3);
      uVar4 = (*pcVar2)();
      return uVar4;
    }
    if (param_1 == (LPSTR)0x0) {
      if (DAT_6f63d150 == 0) {
        local_8 = FUN_6f62dfe0(param_2);
      }
      else {
        local_8 = WideCharToMultiByte(DAT_6f63d160,0x220,param_2,-1,(LPSTR)0x0,0,(LPCSTR)0x0,
                                      &local_18);
        if ((local_8 == 0) || (local_18 != 0)) {
          puVar5 = (undefined4 *)FUN_6f62ee40();
          *puVar5 = 0x2a;
          local_8 = 0xffffffff;
        }
        else {
          local_8 = local_8 - 1;
        }
      }
    }
    else if (DAT_6f63d150 == 0) {
      for (; local_8 < param_3; local_8 = local_8 + 1) {
        if (0xff < (ushort)*param_2) {
          puVar5 = (undefined4 *)FUN_6f62ee40();
          *puVar5 = 0x2a;
          return 0xffffffff;
        }
        param_1[local_8] = (CHAR)*param_2;
        WVar1 = *param_2;
        param_2 = param_2 + 1;
        if (WVar1 == L'\0') {
          return local_8;
        }
      }
    }
    else if (DAT_6f6398f0 == 1) {
      if (param_3 != 0) {
        param_3 = FUN_6f635530(param_2,param_3);
      }
      local_8 = WideCharToMultiByte(DAT_6f63d160,0x220,param_2,param_3,param_1,param_3,(LPCSTR)0x0,
                                    &local_18);
      if ((local_8 == 0) || (local_18 != 0)) {
        puVar5 = (undefined4 *)FUN_6f62ee40();
        *puVar5 = 0x2a;
        local_8 = 0xffffffff;
      }
      else if (param_1[local_8 - 1] == '\0') {
        local_8 = local_8 - 1;
      }
    }
    else {
      local_8 = WideCharToMultiByte(DAT_6f63d160,0x220,param_2,-1,param_1,param_3,(LPCSTR)0x0,
                                    &local_18);
      if ((local_8 == 0) || (local_18 != 0)) {
        if ((local_18 == 0) && (DVar6 = GetLastError(), DVar6 == 0x7a)) {
          while (local_8 < param_3) {
            local_14 = WideCharToMultiByte(DAT_6f63d160,0,param_2,1,local_10,DAT_6f6398f0,
                                           (LPCSTR)0x0,&local_18);
            if ((local_14 == 0) || (local_18 != 0)) {
              puVar5 = (undefined4 *)FUN_6f62ee40();
              *puVar5 = 0x2a;
              return 0xffffffff;
            }
            if (param_3 < local_8 + local_14) {
              return local_8;
            }
            for (local_c = 0; local_c < local_14; local_c = local_c + 1) {
              param_1[local_8] = local_10[local_c];
              if (param_1[local_8] == '\0') {
                return local_8;
              }
              local_8 = local_8 + 1;
            }
            param_2 = param_2 + 1;
          }
        }
        else {
          puVar5 = (undefined4 *)FUN_6f62ee40();
          *puVar5 = 0x2a;
          local_8 = 0xffffffff;
        }
      }
      else {
        local_8 = local_8 - 1;
      }
    }
  }
  else {
    local_8 = 0;
  }
  return local_8;
}



// Function: FUN_6f635530 at 6f635530

int __cdecl FUN_6f635530(short *param_1,int param_2)

{
  int local_c;
  short *local_8;
  
  local_c = param_2 + 1;
  for (local_8 = param_1; (local_c = local_c + -1, local_c != 0 && (*local_8 != 0));
      local_8 = local_8 + 1) {
  }
  if ((local_c != 0) && (*local_8 == 0)) {
    param_2 = ((int)local_8 - (int)param_1 >> 1) + 1;
  }
  return param_2;
}



// Function: FUN_6f6355a0 at 6f6355a0

int __cdecl FUN_6f6355a0(uchar *param_1)

{
  int iVar1;
  
  FUN_6f62c780(0xc);
  iVar1 = FUN_6f6355d0(param_1);
  FUN_6f62c820(0xc);
  return iVar1;
}



// Function: FUN_6f6355d0 at 6f6355d0

int __cdecl FUN_6f6355d0(uchar *param_1)

{
  int iVar1;
  size_t _MaxCount;
  size_t sVar2;
  int *local_c;
  
  local_c = DAT_6f63ce40;
  if ((DAT_6f63ce40 == (int *)0x0) && (DAT_6f63ce48 != 0)) {
    iVar1 = FUN_6f635d00();
    if (iVar1 != 0) {
      return 0;
    }
    local_c = DAT_6f63ce40;
  }
  DAT_6f63ce40 = local_c;
  if ((local_c != (int *)0x0) && (param_1 != (uchar *)0x0)) {
    _MaxCount = _strlen((char *)param_1);
    for (; *local_c != 0; local_c = local_c + 1) {
      sVar2 = _strlen((char *)*local_c);
      if (((_MaxCount < sVar2) && (*(char *)(*local_c + _MaxCount) == '=')) &&
         (iVar1 = __mbsnbicoll((uchar *)*local_c,param_1,_MaxCount), iVar1 == 0)) {
        return *local_c + 1 + _MaxCount;
      }
    }
  }
  return 0;
}



// Function: FUN_6f635690 at 6f635690

void __cdecl
FUN_6f635690(LCID param_1,uint param_2,LPCWSTR param_3,int param_4,LPWSTR param_5,void *param_6,
            UINT param_7)

{
  int iVar1;
  void *cbMultiByte;
  LPCSTR lpMultiByteStr;
  void *local_1c;
  char *local_10;
  
  if (DAT_6f63d29c == 0) {
    iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
      if (iVar1 == 0) {
        return;
      }
      DAT_6f63d29c = 2;
    }
    else {
      DAT_6f63d29c = 1;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_6f635940(param_3,param_4);
  }
  if (DAT_6f63d29c == 1) {
    LCMapStringW(param_1,param_2,param_3,param_4,param_5,(int)param_6);
    return;
  }
  if (DAT_6f63d29c != 2) {
    return;
  }
  local_10 = (char *)0x0;
  if (param_7 == 0) {
    param_7 = DAT_6f63d160;
  }
  cbMultiByte = (void *)WideCharToMultiByte(param_7,0x220,param_3,param_4,(LPSTR)0x0,0,(LPCSTR)0x0,
                                            (LPBOOL)0x0);
  if (cbMultiByte == (void *)0x0) {
    return;
  }
  lpMultiByteStr = (LPCSTR)FUN_6f627430(cbMultiByte,2,0x6f6386d8,0xcc);
  if (lpMultiByteStr == (LPCSTR)0x0) {
    return;
  }
  iVar1 = WideCharToMultiByte(param_7,0x220,param_3,param_4,lpMultiByteStr,(int)cbMultiByte,
                              (LPCSTR)0x0,(LPBOOL)0x0);
  if ((((iVar1 == 0) ||
       (local_1c = (void *)LCMapStringA(param_1,param_2,lpMultiByteStr,(int)cbMultiByte,(LPSTR)0x0,0
                                       ), local_1c == (void *)0x0)) ||
      (local_10 = (char *)FUN_6f627430(local_1c,2,0x6f6386d8,0xdb), local_10 == (char *)0x0)) ||
     (iVar1 = LCMapStringA(param_1,param_2,lpMultiByteStr,(int)cbMultiByte,local_10,(int)local_1c),
     iVar1 == 0)) {
LAB_6f635915:
    FUN_6f627ec0(lpMultiByteStr,2);
    FUN_6f627ec0(local_10,2);
  }
  else {
    if ((param_2 & 0x400) == 0) {
      if (param_6 == (void *)0x0) {
        iVar1 = MultiByteToWideChar(param_7,1,local_10,(int)local_1c,(LPWSTR)0x0,0);
      }
      else {
        iVar1 = MultiByteToWideChar(param_7,1,local_10,(int)local_1c,param_5,(int)param_6);
      }
      if (iVar1 == 0) goto LAB_6f635915;
    }
    else if (param_6 != (void *)0x0) {
      if ((int)param_6 < (int)local_1c) {
        local_1c = param_6;
      }
      _strncpy((char *)param_5,local_10,(size_t)local_1c);
    }
    FUN_6f627ec0(lpMultiByteStr,2);
    FUN_6f627ec0(local_10,2);
  }
  return;
}



// Function: FUN_6f635940 at 6f635940

int __cdecl FUN_6f635940(short *param_1,int param_2)

{
  int local_c;
  short *local_8;
  
  local_c = param_2;
  for (local_8 = param_1; (local_c != 0 && (*local_8 != 0)); local_8 = local_8 + 1) {
    local_c = local_c + -1;
  }
  if (*local_8 == 0) {
    param_2 = (int)local_8 - (int)param_1 >> 1;
  }
  return param_2;
}



// Function: FUN_6f6359a0 at 6f6359a0

void __cdecl
FUN_6f6359a0(LCID param_1,uint param_2,char *param_3,int param_4,LPWSTR param_5,int param_6,
            UINT param_7)

{
  int iVar1;
  LPCWSTR lpWideCharStr;
  int iVar2;
  LPCWSTR local_c;
  
  if (DAT_6f63d2a0 == 0) {
    iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
      if (iVar1 == 0) {
        return;
      }
      DAT_6f63d2a0 = 1;
    }
    else {
      DAT_6f63d2a0 = 2;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_6f635c60(param_3,param_4);
  }
  if (DAT_6f63d2a0 == 2) {
    LCMapStringA(param_1,param_2,param_3,param_4,(LPSTR)param_5,param_6);
    return;
  }
  if (DAT_6f63d2a0 != 1) {
    return;
  }
  local_c = (LPCWSTR)0x0;
  if (param_7 == 0) {
    param_7 = DAT_6f63d160;
  }
  iVar1 = MultiByteToWideChar(param_7,9,param_3,param_4,(LPWSTR)0x0,0);
  if (iVar1 == 0) {
    return;
  }
  lpWideCharStr = (LPCWSTR)FUN_6f627430((void *)(iVar1 << 1),2,0x6f6386d8,0x16d);
  if (lpWideCharStr == (LPCWSTR)0x0) {
    return;
  }
  iVar2 = MultiByteToWideChar(param_7,1,param_3,param_4,lpWideCharStr,iVar1);
  if ((iVar2 != 0) &&
     (iVar2 = LCMapStringW(param_1,param_2,lpWideCharStr,iVar1,(LPWSTR)0x0,0), iVar2 != 0)) {
    if ((param_2 & 0x400) == 0) {
      local_c = (LPCWSTR)FUN_6f627430((void *)(iVar2 << 1),2,0x6f6386d8,0x191);
      if ((local_c == (LPCWSTR)0x0) ||
         (iVar1 = LCMapStringW(param_1,param_2,lpWideCharStr,iVar1,local_c,iVar2), iVar1 == 0))
      goto LAB_6f635c36;
      if (param_6 == 0) {
        iVar1 = WideCharToMultiByte(param_7,0x220,local_c,iVar2,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0
                                   );
      }
      else {
        iVar1 = WideCharToMultiByte(param_7,0x220,local_c,iVar2,(LPSTR)param_5,param_6,(LPCSTR)0x0,
                                    (LPBOOL)0x0);
      }
    }
    else {
      if (param_6 == 0) goto LAB_6f635c15;
      if (param_6 < iVar2) goto LAB_6f635c36;
      iVar1 = LCMapStringW(param_1,param_2,lpWideCharStr,iVar1,param_5,param_6);
    }
    if (iVar1 != 0) {
LAB_6f635c15:
      FUN_6f627ec0(lpWideCharStr,2);
      FUN_6f627ec0(local_c,2);
      return;
    }
  }
LAB_6f635c36:
  FUN_6f627ec0(lpWideCharStr,2);
  FUN_6f627ec0(local_c,2);
  return;
}



// Function: FUN_6f635c60 at 6f635c60

int __cdecl FUN_6f635c60(char *param_1,int param_2)

{
  int local_c;
  char *local_8;
  
  local_c = param_2;
  for (local_8 = param_1; (local_c != 0 && (*local_8 != '\0')); local_8 = local_8 + 1) {
    local_c = local_c + -1;
  }
  if (*local_8 == '\0') {
    param_2 = (int)local_8 - (int)param_1;
  }
  return param_2;
}



// Function: __mbsnbicoll at 6f635cb0

/* Library Function - Single Match
    __mbsnbicoll
   
   Library: Visual Studio 2003 Debug */

int __cdecl __mbsnbicoll(uchar *_Str1,uchar *_Str2,size_t _MaxCount)

{
  int iVar1;
  
  if (_MaxCount == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_6f6360b0(DAT_6f63d090,1,_Str1,_MaxCount,_Str2,_MaxCount,DAT_6f63d08c);
    if (iVar1 == 0) {
      iVar1 = 0x7fffffff;
    }
    else {
      iVar1 = iVar1 + -2;
    }
  }
  return iVar1;
}



// Function: FUN_6f635d00 at 6f635d00

undefined4 FUN_6f635d00(void)

{
  void *cbMultiByte;
  uint *lpMultiByteStr;
  int iVar1;
  int *local_8;
  
  local_8 = DAT_6f63ce48;
  while( true ) {
    if (*local_8 == 0) {
      return 0;
    }
    cbMultiByte = (void *)WideCharToMultiByte(1,0,(LPCWSTR)*local_8,-1,(LPSTR)0x0,0,(LPCSTR)0x0,
                                              (LPBOOL)0x0);
    if (cbMultiByte == (void *)0x0) {
      return 0xffffffff;
    }
    lpMultiByteStr = (uint *)FUN_6f627430(cbMultiByte,2,0x6f6386e4,0x3d);
    if (lpMultiByteStr == (uint *)0x0) {
      return 0xffffffff;
    }
    iVar1 = WideCharToMultiByte(1,0,(LPCWSTR)*local_8,-1,(LPSTR)lpMultiByteStr,(int)cbMultiByte,
                                (LPCSTR)0x0,(LPBOOL)0x0);
    if (iVar1 == 0) break;
    FUN_6f6364c0(lpMultiByteStr,0);
    local_8 = local_8 + 1;
  }
  return 0xffffffff;
}



// Function: FUN_6f635db0 at 6f635db0

void __cdecl
FUN_6f635db0(LCID param_1,DWORD param_2,PCNZWCH param_3,int param_4,LPCWSTR param_5,int param_6,
            UINT param_7)

{
  int iVar1;
  void *cbMultiByte;
  PCNZCH lpMultiByteStr;
  void *cbMultiByte_00;
  LPSTR local_8;
  
  if (DAT_6f63d2a4 == 0) {
    iVar1 = CompareStringW(0,0,L"",1,L"",1);
    if (iVar1 == 0) {
      iVar1 = CompareStringA(0,0,"",1,"",1);
      if (iVar1 == 0) {
        return;
      }
      DAT_6f63d2a4 = 2;
    }
    else {
      DAT_6f63d2a4 = 1;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_6f636050(param_3,param_4);
  }
  if (0 < param_6) {
    param_6 = FUN_6f636050(param_5,param_6);
  }
  if ((param_4 != 0) && (param_6 != 0)) {
    if (DAT_6f63d2a4 == 1) {
      CompareStringW(param_1,param_2,param_3,param_4,param_5,param_6);
    }
    else if (DAT_6f63d2a4 == 2) {
      local_8 = (LPSTR)0x0;
      if (param_7 == 0) {
        param_7 = DAT_6f63d160;
      }
      cbMultiByte = (void *)WideCharToMultiByte(param_7,0x220,param_3,param_4,(LPSTR)0x0,0,
                                                (LPCSTR)0x0,(LPBOOL)0x0);
      if ((cbMultiByte != (void *)0x0) &&
         (lpMultiByteStr = (PCNZCH)FUN_6f627430(cbMultiByte,2,0x6f6386f0,0xc4),
         lpMultiByteStr != (PCNZCH)0x0)) {
        iVar1 = WideCharToMultiByte(param_7,0x220,param_3,param_4,lpMultiByteStr,(int)cbMultiByte,
                                    (LPCSTR)0x0,(LPBOOL)0x0);
        if ((iVar1 == 0) ||
           (((cbMultiByte_00 =
                   (void *)WideCharToMultiByte(param_7,0x220,param_5,param_6,(LPSTR)0x0,0,
                                               (LPCSTR)0x0,(LPBOOL)0x0),
             cbMultiByte_00 == (void *)0x0 ||
             (local_8 = (LPSTR)FUN_6f627430(cbMultiByte_00,2,0x6f6386f0,0xd5), local_8 == (LPSTR)0x0
             )) || (iVar1 = WideCharToMultiByte(param_7,0x220,param_5,param_6,local_8,
                                                (int)cbMultiByte_00,(LPCSTR)0x0,(LPBOOL)0x0),
                   iVar1 == 0)))) {
          FUN_6f627ec0(lpMultiByteStr,2);
          FUN_6f627ec0(local_8,2);
        }
        else {
          CompareStringA(param_1,param_2,lpMultiByteStr,(int)cbMultiByte,local_8,(int)cbMultiByte_00
                        );
          FUN_6f627ec0(lpMultiByteStr,2);
          FUN_6f627ec0(local_8,2);
        }
      }
    }
  }
  return;
}



// Function: FUN_6f636050 at 6f636050

int __cdecl FUN_6f636050(short *param_1,int param_2)

{
  int local_c;
  short *local_8;
  
  local_c = param_2;
  for (local_8 = param_1; (local_c != 0 && (*local_8 != 0)); local_8 = local_8 + 1) {
    local_c = local_c + -1;
  }
  if (*local_8 == 0) {
    param_2 = (int)local_8 - (int)param_1 >> 1;
  }
  return param_2;
}



// Function: FUN_6f6360b0 at 6f6360b0

void __cdecl
FUN_6f6360b0(LCID param_1,DWORD param_2,byte *param_3,int param_4,byte *param_5,int param_6,
            UINT param_7)

{
  code *pcVar1;
  int iVar2;
  BOOL BVar3;
  BYTE *local_30;
  _cpinfo local_2c;
  int local_18;
  LPWSTR local_14;
  LPWSTR local_10;
  int local_c;
  int local_8;
  
  if (DAT_6f63d2a8 == 0) {
    iVar2 = CompareStringA(0,0,"",1,"",1);
    if (iVar2 == 0) {
      iVar2 = CompareStringW(0,0,L"",1,L"",1);
      if (iVar2 == 0) {
        return;
      }
      DAT_6f63d2a8 = 1;
    }
    else {
      DAT_6f63d2a8 = 2;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_6f636470((char *)param_3,param_4);
  }
  if (0 < param_6) {
    param_6 = FUN_6f636470((char *)param_5,param_6);
  }
  if (DAT_6f63d2a8 == 2) {
    CompareStringA(param_1,param_2,(PCNZCH)param_3,param_4,(PCNZCH)param_5,param_6);
  }
  else if (DAT_6f63d2a8 == 1) {
    local_18 = 0;
    local_8 = 0;
    local_c = 0;
    local_10 = (LPWSTR)0x0;
    local_14 = (LPWSTR)0x0;
    if (param_7 == 0) {
      param_7 = DAT_6f63d160;
    }
    if ((param_4 == 0) || (param_6 == 0)) {
      if (param_4 == param_6) {
        return;
      }
      if (1 < param_6) {
        return;
      }
      if (1 < param_4) {
        return;
      }
      BVar3 = GetCPInfo(param_7,&local_2c);
      if (BVar3 == 0) {
        return;
      }
      if ((((param_4 != 0) || (param_6 != 1)) && ((param_4 != 1 || (param_6 != 0)))) &&
         (iVar2 = FUN_6f625320(2,0x6f6386f0,0x162,0,
                               (byte *)
                               "cchCount1==0 && cchCount2==1 || cchCount1==1 && cchCount2==0"),
         iVar2 == 1)) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      if (0 < param_4) {
        if (local_2c.MaxCharSize < 2) {
          return;
        }
        local_30 = local_2c.LeadByte;
        while( true ) {
          if (*local_30 == 0) {
            return;
          }
          if (local_30[1] == 0) break;
          if ((*local_30 <= *param_3) && (*param_3 <= local_30[1])) {
            return;
          }
          local_30 = local_30 + 2;
        }
        return;
      }
      if (0 < param_6) {
        if (local_2c.MaxCharSize < 2) {
          return;
        }
        local_30 = local_2c.LeadByte;
        while( true ) {
          if (*local_30 == 0) {
            return;
          }
          if (local_30[1] == 0) break;
          if ((*local_30 <= *param_5) && (*param_5 <= local_30[1])) {
            return;
          }
          local_30 = local_30 + 2;
        }
        return;
      }
    }
    local_8 = MultiByteToWideChar(param_7,9,(LPCSTR)param_3,param_4,(LPWSTR)0x0,0);
    if ((local_8 != 0) &&
       (local_10 = (LPWSTR)FUN_6f627430((void *)(local_8 << 1),2,0x6f6386f0,0x18a),
       local_10 != (LPWSTR)0x0)) {
      iVar2 = MultiByteToWideChar(param_7,1,(LPCSTR)param_3,param_4,local_10,local_8);
      if ((iVar2 != 0) &&
         (((local_c = MultiByteToWideChar(param_7,9,(LPCSTR)param_5,param_6,(LPWSTR)0x0,0),
           local_c != 0 &&
           (local_14 = (LPWSTR)FUN_6f627430((void *)(local_c << 1),2,0x6f6386f0,0x199),
           local_14 != (LPWSTR)0x0)) &&
          (iVar2 = MultiByteToWideChar(param_7,1,(LPCSTR)param_5,param_6,local_14,local_c),
          iVar2 != 0)))) {
        local_18 = CompareStringW(param_1,param_2,local_10,local_8,local_14,local_c);
      }
      FUN_6f627ec0(local_10,2);
      FUN_6f627ec0(local_14,2);
    }
  }
  return;
}



// Function: FUN_6f636470 at 6f636470

int __cdecl FUN_6f636470(char *param_1,int param_2)

{
  int local_c;
  char *local_8;
  
  local_c = param_2;
  for (local_8 = param_1; (local_c != 0 && (*local_8 != '\0')); local_8 = local_8 + 1) {
    local_c = local_c + -1;
  }
  if (*local_8 == '\0') {
    param_2 = (int)local_8 - (int)param_1;
  }
  return param_2;
}



// Function: FUN_6f6364c0 at 6f6364c0

undefined4 __cdecl FUN_6f6364c0(uint *param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  size_t sVar4;
  uint *lpName;
  undefined1 *puVar5;
  bool bVar6;
  uint uVar7;
  char *pcVar8;
  int local_c;
  
  if (((param_1 == (uint *)0x0) || (puVar1 = FUN_6f636910(param_1,0x3d), puVar1 == (uint *)0x0)) ||
     (param_1 == puVar1)) {
    return 0xffffffff;
  }
  bVar6 = *(char *)((int)puVar1 + 1) == '\0';
  if (DAT_6f63ce40 == DAT_6f63ce44) {
    DAT_6f63ce40 = copy_environ(DAT_6f63ce40);
  }
  if (DAT_6f63ce40 == (int *)0x0) {
    if ((param_2 == 0) || (DAT_6f63ce48 == (undefined4 *)0x0)) {
      if (bVar6) {
        return 0;
      }
      DAT_6f63ce40 = (int *)FUN_6f627430((void *)0x4,2,0x6f63873c,0x87);
      if (DAT_6f63ce40 == (int *)0x0) {
        return 0xffffffff;
      }
      *DAT_6f63ce40 = 0;
      if (DAT_6f63ce48 == (undefined4 *)0x0) {
        DAT_6f63ce48 = (undefined4 *)FUN_6f627430((void *)0x4,2,0x6f63873c,0x8e);
        if (DAT_6f63ce48 == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        *DAT_6f63ce48 = 0;
      }
    }
    else {
      iVar2 = FUN_6f635d00();
      if (iVar2 != 0) {
        return 0xffffffff;
      }
    }
  }
  piVar3 = DAT_6f63ce40;
  local_c = findenv((uchar *)param_1,(int)puVar1 - (int)param_1);
  if ((local_c < 0) || (*piVar3 == 0)) {
    if (bVar6) {
      return 0;
    }
    if (local_c < 0) {
      local_c = -local_c;
    }
    piVar3 = FUN_6f6278c0(piVar3,(void *)(local_c * 4 + 8),2,0x6f63873c,0xce);
    if (piVar3 == (int *)0x0) {
      return 0xffffffff;
    }
    piVar3[local_c] = (int)param_1;
    piVar3[local_c + 1] = 0;
    DAT_6f63ce40 = piVar3;
  }
  else if (bVar6) {
    FUN_6f627ec0((void *)piVar3[local_c],2);
    for (; piVar3[local_c] != 0; local_c = local_c + 1) {
      piVar3[local_c] = piVar3[local_c + 1];
    }
    piVar3 = FUN_6f6278c0(piVar3,(void *)(local_c << 2),2,0x6f63873c,0xb9);
    if (piVar3 != (int *)0x0) {
      DAT_6f63ce40 = piVar3;
    }
  }
  else {
    piVar3[local_c] = (int)param_1;
  }
  if (param_2 != 0) {
    iVar2 = 0xe5;
    pcVar8 = "setenv.c";
    uVar7 = 2;
    sVar4 = _strlen((char *)param_1);
    lpName = (uint *)FUN_6f627430((void *)(sVar4 + 2),uVar7,(int)pcVar8,iVar2);
    if (lpName != (uint *)0x0) {
      FUN_6f6235b0(lpName,param_1);
      puVar5 = (undefined1 *)((int)lpName + ((int)puVar1 - (int)param_1));
      *puVar5 = 0;
      SetEnvironmentVariableA((LPCSTR)lpName,(LPCSTR)(~-(uint)bVar6 & (uint)(puVar5 + 1)));
      FUN_6f627ec0(lpName,2);
    }
  }
  return 0;
}



// Function: findenv at 6f6367a0

/* Library Function - Single Match
    _findenv
   
   Library: Visual Studio 2003 Debug */

int __cdecl findenv(uchar *param_1,size_t param_2)

{
  int iVar1;
  int *local_8;
  
  local_8 = DAT_6f63ce40;
  while( true ) {
    if (*local_8 == 0) {
      return -((int)local_8 - (int)DAT_6f63ce40 >> 2);
    }
    iVar1 = __mbsnbicoll(param_1,(uchar *)*local_8,param_2);
    if ((iVar1 == 0) &&
       ((*(char *)(*local_8 + param_2) == '=' || (*(char *)(*local_8 + param_2) == '\0')))) break;
    local_8 = local_8 + 1;
  }
  return (int)local_8 - (int)DAT_6f63ce40 >> 2;
}



// Function: copy_environ at 6f636820

/* Library Function - Single Match
    _copy_environ
   
   Library: Visual Studio 2003 Debug */

int * __cdecl copy_environ(int *param_1)

{
  int *piVar1;
  size_t sVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  int local_14;
  int *local_10;
  int *local_c;
  
  local_14 = 0;
  local_10 = param_1;
  if (param_1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    while (iVar5 = *local_10, local_10 = local_10 + 1, iVar5 != 0) {
      local_14 = local_14 + 1;
    }
    piVar1 = (int *)FUN_6f627430((void *)(local_14 * 4 + 4),2,0x6f63873c,0x146);
    if (piVar1 == (int *)0x0) {
      __amsg_exit(9);
    }
    local_c = piVar1;
    for (local_10 = param_1; *local_10 != 0; local_10 = local_10 + 1) {
      iVar5 = 0x14f;
      pcVar4 = "setenv.c";
      uVar3 = 2;
      sVar2 = _strlen((char *)*local_10);
      iVar5 = FUN_6f627430((void *)(sVar2 + 1),uVar3,(int)pcVar4,iVar5);
      *local_c = iVar5;
      if (*local_c != 0) {
        FUN_6f6235b0((uint *)*local_c,(uint *)*local_10);
      }
      local_c = local_c + 1;
    }
    *local_c = 0;
  }
  return piVar1;
}



// Function: FUN_6f636910 at 6f636910

uint * __cdecl FUN_6f636910(uint *param_1,uint param_2)

{
  ushort uVar1;
  uint *puVar2;
  
  if (DAT_6f63d08c == 0) {
    param_1 = FUN_6f6259d0(param_1,(char)param_2);
  }
  else {
    FUN_6f62c780(0x19);
    while( true ) {
      uVar1 = (ushort)(byte)*param_1;
      if (uVar1 == 0) break;
      if (((&DAT_6f63cf89)[uVar1] & 4) == 0) {
        puVar2 = param_1;
        if (param_2 == uVar1) break;
      }
      else {
        puVar2 = (uint *)((int)param_1 + 1);
        if (*(char *)puVar2 == '\0') {
          FUN_6f62c820(0x19);
          return (uint *)0x0;
        }
        if (param_2 == CONCAT11((byte)*param_1,*(char *)puVar2)) {
          FUN_6f62c820(0x19);
          return param_1;
        }
      }
      param_1 = puVar2;
      param_1 = (uint *)((int)param_1 + 1);
    }
    FUN_6f62c820(0x19);
    if (param_2 != uVar1) {
      param_1 = (uint *)0x0;
    }
  }
  return param_1;
}



