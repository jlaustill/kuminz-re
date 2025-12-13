/*
 * Decompiled from: dpam07.dll
 * Using Ghidra 11.4.1
 */

// Function: InitDPA at 6f681000

int InitDPA(ushort *param_1,undefined2 param_2)

{
  void *this;
  undefined4 local_154;
  undefined1 local_150 [83];
  undefined2 local_fd;
  int local_8;
  
                    /* 0x1000  8  InitDPA */
  local_8 = 0;
  local_fd = param_2;
  local_8 = FUN_6f685640(&local_154,s_DG_DPA32_ini_6f6881a8);
  if (local_8 == 0) {
    switch(local_154) {
    case 0:
      local_8 = FUN_6f68277c(local_150,param_1,local_150);
      break;
    case 1:
      local_8 = InitPCCard(param_1,param_1,local_150);
      break;
    case 2:
      local_8 = InitTCP_IP(this,param_1,local_150);
      break;
    case 3:
      local_8 = 0x29;
      break;
    case 4:
      local_8 = FUN_6f682cc1(local_150,param_1,local_150);
      break;
    default:
      local_8 = 0x28;
    }
  }
  return local_8;
}



// Function: RestoreDPA at 6f6810e5

int RestoreDPA(ushort param_1)

{
  ushort uVar1;
  int iVar2;
  
                    /* 0x10e5  24  RestoreDPA */
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      iVar2 = RestoreCommLink(param_1);
      return iVar2;
    }
    if (uVar1 == 0x8000) {
      iVar2 = RestorePCCard(param_1);
      return iVar2;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      return 0x21;
    }
    if (uVar1 == 0x2000) {
      iVar2 = RestoreTCP_IP(param_1);
      return iVar2;
    }
    if (uVar1 == 0x4000) {
      iVar2 = FUN_6f683807(param_1);
      return iVar2;
    }
  }
  return 0x21;
}



// Function: InitCommLink at 6f681187

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int InitCommLink(ushort *param_1,byte *param_2)

{
  int iVar1;
  void *local_154;
  undefined1 local_150 [83];
  ushort local_fd;
  int local_8;
  
                    /* 0x1187  7  InitCommLink */
  local_fd = (ushort)*param_2;
  local_8 = FUN_6f685640(&local_154,s_DG_DPA32_ini_6f6881a8);
  if (local_8 == 0) {
    switch(local_154) {
    case (void *)0x0:
      iVar1 = FUN_6f68277c(local_154,param_1,local_150);
      return iVar1;
    case (void *)0x1:
      iVar1 = InitPCCard(local_150,param_1,local_150);
      return iVar1;
    case (void *)0x2:
      iVar1 = InitTCP_IP(param_1,param_1,local_150);
      return iVar1;
    case (void *)0x3:
      return 0x29;
    case (void *)0x4:
      iVar1 = FUN_6f682cc1(local_154,param_1,local_150);
      return iVar1;
    default:
      return 0x28;
    }
  }
  if ((DAT_6f689298 == (HMODULE)0x0) && (DAT_6f689520 == 0)) {
    DAT_6f689298 = LoadLibraryA(s_DPAS07_DLL_6f688010);
    if (DAT_6f689298 < (HMODULE)0x21) {
      return 0x29;
    }
    DAT_6f6892b0 = GetProcAddress(DAT_6f689298,s_InitCommLink_6f6881bc);
    DAT_6f6892c0 = GetProcAddress(DAT_6f689298,s_RestoreCommLink_6f6881cc);
    _DAT_6f6892d0 = 0;
    _DAT_6f6892e0 = 0;
    _DAT_6f6892f0 = 0;
    _DAT_6f689300 = 0;
    DAT_6f689310 = GetProcAddress(DAT_6f689298,s_InitDataLink_6f6881dc);
    DAT_6f689320 = GetProcAddress(DAT_6f689298,s_CheckDataLink_6f6881ec);
    DAT_6f689330 = GetProcAddress(DAT_6f689298,s_LoadDPABuffer_6f6881fc);
    DAT_6f689340 = GetProcAddress(DAT_6f689298,s_ReadDPABuffer_6f68820c);
    DAT_6f689350 = GetProcAddress(DAT_6f689298,s_LoadMailBox_6f68821c);
    DAT_6f689360 = GetProcAddress(DAT_6f689298,s_UnloadMailBox_6f688228);
    DAT_6f689370 = GetProcAddress(DAT_6f689298,s_TransmitMailBoxAsync_6f688238);
    DAT_6f689380 = GetProcAddress(DAT_6f689298,s_TransmitMailBox_6f688250);
    DAT_6f689390 = GetProcAddress(DAT_6f689298,s_UpdateTransmitMailBox_6f688260);
    DAT_6f6893a0 = GetProcAddress(DAT_6f689298,s_UpdateTransmitMailBoxAsync_6f688278);
    DAT_6f6893b0 = GetProcAddress(DAT_6f689298,s_UpdateTransMailBoxData_6f688294);
    DAT_6f6893c0 = GetProcAddress(DAT_6f689298,s_UpdateTransMailBoxDataAsync_6f6882ac);
    DAT_6f6893d0 = GetProcAddress(DAT_6f689298,s_UpdateReceiveMailBox_6f6882c8);
    DAT_6f6893e0 = GetProcAddress(DAT_6f689298,s_UpdateReceiveMailBoxAsync_6f6882e0);
    DAT_6f6893f0 = GetProcAddress(DAT_6f689298,s_ReceiveMailBox_6f6882fc);
    DAT_6f689400 = GetProcAddress(DAT_6f689298,s_LoadTimer_6f68830c);
    DAT_6f689410 = GetProcAddress(DAT_6f689298,s_EnableTimerInterrupt_6f688318);
    DAT_6f689420 = GetProcAddress(DAT_6f689298,s_SuspendTimerInterrupt_6f688330);
    DAT_6f689430 = GetProcAddress(DAT_6f689298,s_PauseTimer_6f688348);
    DAT_6f689440 = GetProcAddress(DAT_6f689298,s_ResumeTimer_6f688354);
    DAT_6f689450 = GetProcAddress(DAT_6f689298,s_RequestTimerValue_6f688360);
    DAT_6f689460 = GetProcAddress(DAT_6f689298,s_CheckLock_6f688374);
    DAT_6f689470 = GetProcAddress(DAT_6f689298,s_GoToLoader_6f688380);
    DAT_6f689480 = GetProcAddress(DAT_6f689298,s_ReadDPAChecksum_6f68838c);
    DAT_6f689490 = GetProcAddress(DAT_6f689298,s_ConfigureTransportProtocol_6f68839c);
    DAT_6f6894a0 = GetProcAddress(DAT_6f689298,s_SetBaudRate_6f6883b8);
    DAT_6f6894b0 = GetProcAddress(DAT_6f689298,s_ResetDPA_6f6883c4);
    DAT_6f6894c0 = GetProcAddress(DAT_6f689298,s_GetLockSeed_6f6883d0);
    DAT_6f6894d0 = GetProcAddress(DAT_6f689298,s_InitDisplay_6f6883dc);
    DAT_6f6894e0 = GetProcAddress(DAT_6f689298,s_WriteDisplay_6f6883e8);
    DAT_6f6894f0 = GetProcAddress(DAT_6f689298,s_SendBuffer_6f6883f8);
    DAT_6f689500 = GetProcAddress(DAT_6f689298,s_SetDecodeCallback_6f688404);
    if ((((((DAT_6f6892b0 == (FARPROC)0x0) || (DAT_6f6892c0 == (FARPROC)0x0)) ||
          (DAT_6f689310 == (FARPROC)0x0)) ||
         (((DAT_6f689320 == (FARPROC)0x0 || (DAT_6f689330 == (FARPROC)0x0)) ||
          ((DAT_6f689340 == (FARPROC)0x0 ||
           ((DAT_6f689350 == (FARPROC)0x0 || (DAT_6f689360 == (FARPROC)0x0)))))))) ||
        (DAT_6f689370 == (FARPROC)0x0)) ||
       (((((((DAT_6f689380 == (FARPROC)0x0 || (DAT_6f689390 == (FARPROC)0x0)) ||
            (DAT_6f6893a0 == (FARPROC)0x0)) ||
           ((DAT_6f6893b0 == (FARPROC)0x0 || (DAT_6f6893c0 == (FARPROC)0x0)))) ||
          (DAT_6f6893d0 == (FARPROC)0x0)) ||
         ((((DAT_6f6893e0 == (FARPROC)0x0 || (DAT_6f6893f0 == (FARPROC)0x0)) ||
           (((DAT_6f689400 == (FARPROC)0x0 ||
             (((DAT_6f689410 == (FARPROC)0x0 || (DAT_6f689420 == (FARPROC)0x0)) ||
              (DAT_6f689430 == (FARPROC)0x0)))) ||
            (((DAT_6f689440 == (FARPROC)0x0 || (DAT_6f689450 == (FARPROC)0x0)) ||
             (DAT_6f689460 == (FARPROC)0x0)))))) ||
          ((DAT_6f6894c0 == (FARPROC)0x0 || (DAT_6f689470 == (FARPROC)0x0)))))) ||
        (((DAT_6f689480 == (FARPROC)0x0 ||
          (((DAT_6f6894a0 == (FARPROC)0x0 || (DAT_6f6894b0 == (FARPROC)0x0)) ||
           (DAT_6f6894d0 == (FARPROC)0x0)))) ||
         (((DAT_6f6894e0 == (FARPROC)0x0 || (DAT_6f689490 == (FARPROC)0x0)) ||
          ((DAT_6f6894f0 == (FARPROC)0x0 || (DAT_6f689500 == (FARPROC)0x0)))))))))) {
      FreeLibrary(DAT_6f689298);
      return 0x29;
    }
  }
  if (DAT_6f6892b0 == (FARPROC)0x0) {
    iVar1 = 0x29;
  }
  else {
    iVar1 = (*DAT_6f6892b0)(param_1,param_2);
    if (iVar1 == 0) {
      DAT_6f689520 = DAT_6f689520 + 1;
    }
  }
  return iVar1;
}



// Function: InitPCCard at 6f6817a4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall InitPCCard(void *this,ushort *param_1,undefined4 param_2)

{
  int iVar1;
  
                    /* 0x17a4  11  InitPCCard */
  if ((DAT_6f68929c == (HMODULE)0x0) && (DAT_6f689524 == 0)) {
    DAT_6f68929c = LoadLibraryA(s_DPAI32_DLL_6f688060);
    if (DAT_6f68929c < (HMODULE)0x21) {
      return 0x29;
    }
    DAT_6f6892d4 = GetProcAddress(DAT_6f68929c,s_InitPCCard_6f688418);
    DAT_6f6892e4 = GetProcAddress(DAT_6f68929c,s_RestorePCCard_6f688424);
    _DAT_6f6892b4 = 0;
    _DAT_6f6892c4 = 0;
    _DAT_6f6892f4 = 0;
    _DAT_6f689304 = 0;
    DAT_6f689314 = GetProcAddress(DAT_6f68929c,s_InitDataLink_6f688434);
    DAT_6f689324 = GetProcAddress(DAT_6f68929c,s_CheckDataLink_6f688444);
    DAT_6f689334 = GetProcAddress(DAT_6f68929c,s_LoadDPABuffer_6f688454);
    DAT_6f689344 = GetProcAddress(DAT_6f68929c,s_ReadDPABuffer_6f688464);
    DAT_6f689354 = GetProcAddress(DAT_6f68929c,s_LoadMailBox_6f688474);
    DAT_6f689364 = GetProcAddress(DAT_6f68929c,s_UnloadMailBox_6f688480);
    DAT_6f689374 = GetProcAddress(DAT_6f68929c,s_TransmitMailBoxAsync_6f688490);
    DAT_6f689384 = GetProcAddress(DAT_6f68929c,s_TransmitMailBox_6f6884a8);
    DAT_6f689394 = GetProcAddress(DAT_6f68929c,s_UpdateTransmitMailBox_6f6884b8);
    DAT_6f6893a4 = GetProcAddress(DAT_6f68929c,s_UpdateTransmitMailBoxAsync_6f6884d0);
    DAT_6f6893b4 = GetProcAddress(DAT_6f68929c,s_UpdateTransMailBoxData_6f6884ec);
    DAT_6f6893c4 = GetProcAddress(DAT_6f68929c,s_UpdateTransMailBoxDataAsync_6f688504);
    DAT_6f6893d4 = GetProcAddress(DAT_6f68929c,s_UpdateReceiveMailBox_6f688520);
    DAT_6f6893e4 = GetProcAddress(DAT_6f68929c,s_UpdateReceiveMailBoxAsync_6f688538);
    DAT_6f6893f4 = GetProcAddress(DAT_6f68929c,s_ReceiveMailBox_6f688554);
    DAT_6f689404 = GetProcAddress(DAT_6f68929c,s_LoadTimer_6f688564);
    DAT_6f689414 = GetProcAddress(DAT_6f68929c,s_EnableTimerInterrupt_6f688570);
    DAT_6f689424 = GetProcAddress(DAT_6f68929c,s_SuspendTimerInterrupt_6f688588);
    DAT_6f689434 = GetProcAddress(DAT_6f68929c,s_PauseTimer_6f6885a0);
    DAT_6f689444 = GetProcAddress(DAT_6f68929c,s_ResumeTimer_6f6885ac);
    DAT_6f689454 = GetProcAddress(DAT_6f68929c,s_RequestTimerValue_6f6885b8);
    DAT_6f689464 = GetProcAddress(DAT_6f68929c,s_CheckLock_6f6885cc);
    DAT_6f689474 = GetProcAddress(DAT_6f68929c,s_GoToLoader_6f6885d8);
    DAT_6f689484 = GetProcAddress(DAT_6f68929c,s_ReadDPAChecksum_6f6885e4);
    DAT_6f689494 = GetProcAddress(DAT_6f68929c,s_ConfigureTransportProtocol_6f6885f4);
    _DAT_6f6894a4 = 0;
    DAT_6f6894b4 = GetProcAddress(DAT_6f68929c,s_ResetDPA_6f688610);
    DAT_6f6894c4 = GetProcAddress(DAT_6f68929c,s_GetLockSeed_6f68861c);
    DAT_6f6894d4 = GetProcAddress(DAT_6f68929c,s_InitDisplay_6f688628);
    DAT_6f6894e4 = GetProcAddress(DAT_6f68929c,s_WriteDisplay_6f688634);
    DAT_6f6894f4 = GetProcAddress(DAT_6f689298,s_SendBuffer_6f688644);
    if ((((((((DAT_6f6892d4 == (FARPROC)0x0) || (DAT_6f6892e4 == (FARPROC)0x0)) ||
            (DAT_6f689314 == (FARPROC)0x0)) ||
           (((DAT_6f689324 == (FARPROC)0x0 || (DAT_6f689334 == (FARPROC)0x0)) ||
            ((DAT_6f689344 == (FARPROC)0x0 ||
             ((DAT_6f689354 == (FARPROC)0x0 || (DAT_6f689364 == (FARPROC)0x0)))))))) ||
          (DAT_6f689374 == (FARPROC)0x0)) ||
         ((((((DAT_6f689384 == (FARPROC)0x0 || (DAT_6f689394 == (FARPROC)0x0)) ||
             (DAT_6f6893a4 == (FARPROC)0x0)) ||
            ((DAT_6f6893b4 == (FARPROC)0x0 || (DAT_6f6893c4 == (FARPROC)0x0)))) ||
           (DAT_6f6893d4 == (FARPROC)0x0)) ||
          (((DAT_6f6893e4 == (FARPROC)0x0 || (DAT_6f6893f4 == (FARPROC)0x0)) ||
           (((DAT_6f689404 == (FARPROC)0x0 ||
             (((DAT_6f689414 == (FARPROC)0x0 || (DAT_6f689424 == (FARPROC)0x0)) ||
              (DAT_6f689434 == (FARPROC)0x0)))) ||
            (((DAT_6f689444 == (FARPROC)0x0 || (DAT_6f689454 == (FARPROC)0x0)) ||
             (DAT_6f689464 == (FARPROC)0x0)))))))))) ||
        (((DAT_6f6894c4 == (FARPROC)0x0 || (DAT_6f689474 == (FARPROC)0x0)) ||
         ((DAT_6f689484 == (FARPROC)0x0 ||
          (((DAT_6f6894b4 == (FARPROC)0x0 || (DAT_6f6894d4 == (FARPROC)0x0)) ||
           (DAT_6f6894e4 == (FARPROC)0x0)))))))) ||
       ((DAT_6f689494 == (FARPROC)0x0 || (DAT_6f6894f4 == (FARPROC)0x0)))) {
      FreeLibrary(DAT_6f68929c);
      return 0x29;
    }
  }
  if (DAT_6f6892d4 == (FARPROC)0x0) {
    iVar1 = 0x29;
  }
  else {
    iVar1 = (*DAT_6f6892d4)(param_1,param_2,this);
    if (iVar1 == 0) {
      *param_1 = *param_1 | 0x8000;
      DAT_6f689524 = DAT_6f689524 + 1;
    }
  }
  return iVar1;
}



// Function: InitTCP_IP at 6f681cbc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall InitTCP_IP(void *this,ushort *param_1,undefined4 param_2)

{
  int iVar1;
  
                    /* 0x1cbc  12  InitTCP_IP */
  if ((DAT_6f6892a4 == (HMODULE)0x0) && (DAT_6f68952c == 0)) {
    DAT_6f6892a4 = LoadLibraryA(s_DPAT32_DLL_6f688100);
    if (DAT_6f6892a4 < (HMODULE)0x21) {
      return 0x29;
    }
    DAT_6f6892f8 = GetProcAddress(DAT_6f6892a4,s_InitTCP_IP_6f688650);
    DAT_6f689308 = GetProcAddress(DAT_6f6892a4,s_RestoreTCP_IP_6f68865c);
    _DAT_6f6892d8 = 0;
    _DAT_6f6892e8 = 0;
    _DAT_6f6892b8 = 0;
    _DAT_6f6892c8 = 0;
    DAT_6f689318 = GetProcAddress(DAT_6f6892a4,s_InitDataLink_6f68866c);
    DAT_6f689328 = GetProcAddress(DAT_6f6892a4,s_CheckDataLink_6f68867c);
    DAT_6f689338 = GetProcAddress(DAT_6f6892a4,s_LoadDPABuffer_6f68868c);
    DAT_6f689348 = GetProcAddress(DAT_6f6892a4,s_ReadDPABuffer_6f68869c);
    DAT_6f689358 = GetProcAddress(DAT_6f6892a4,s_LoadMailBox_6f6886ac);
    DAT_6f689368 = GetProcAddress(DAT_6f6892a4,s_UnloadMailBox_6f6886b8);
    DAT_6f689378 = GetProcAddress(DAT_6f6892a4,s_TransmitMailBoxAsync_6f6886c8);
    DAT_6f689388 = GetProcAddress(DAT_6f6892a4,s_TransmitMailBox_6f6886e0);
    DAT_6f689398 = GetProcAddress(DAT_6f6892a4,s_UpdateTransmitMailBox_6f6886f0);
    DAT_6f6893a8 = GetProcAddress(DAT_6f6892a4,s_UpdateTransmitMailBoxAsync_6f688708);
    DAT_6f6893b8 = GetProcAddress(DAT_6f6892a4,s_UpdateTransMailBoxData_6f688724);
    DAT_6f6893c8 = GetProcAddress(DAT_6f6892a4,s_UpdateTransMailBoxDataAsync_6f68873c);
    DAT_6f6893d8 = GetProcAddress(DAT_6f6892a4,s_UpdateReceiveMailBox_6f688758);
    DAT_6f6893e8 = GetProcAddress(DAT_6f6892a4,s_UpdateReceiveMailBoxAsync_6f688770);
    DAT_6f6893f8 = GetProcAddress(DAT_6f6892a4,s_ReceiveMailBox_6f68878c);
    DAT_6f689408 = GetProcAddress(DAT_6f6892a4,s_LoadTimer_6f68879c);
    DAT_6f689418 = GetProcAddress(DAT_6f6892a4,s_EnableTimerInterrupt_6f6887a8);
    DAT_6f689428 = GetProcAddress(DAT_6f6892a4,s_SuspendTimerInterrupt_6f6887c0);
    DAT_6f689438 = GetProcAddress(DAT_6f6892a4,s_PauseTimer_6f6887d8);
    DAT_6f689448 = GetProcAddress(DAT_6f6892a4,s_ResumeTimer_6f6887e4);
    DAT_6f689458 = GetProcAddress(DAT_6f6892a4,s_RequestTimerValue_6f6887f0);
    DAT_6f689468 = GetProcAddress(DAT_6f6892a4,s_CheckLock_6f688804);
    DAT_6f689478 = GetProcAddress(DAT_6f6892a4,s_GoToLoader_6f688810);
    DAT_6f689488 = GetProcAddress(DAT_6f6892a4,s_ReadDPAChecksum_6f68881c);
    DAT_6f689498 = GetProcAddress(DAT_6f6892a4,s_ConfigureTransportProtocol_6f68882c);
    DAT_6f6894a8 = 0;
    DAT_6f6894b8 = GetProcAddress(DAT_6f6892a4,s_ResetDPA_6f688848);
    DAT_6f6894c8 = GetProcAddress(DAT_6f6892a4,s_GetLockSeed_6f688854);
    DAT_6f6894d8 = GetProcAddress(DAT_6f6892a4,s_InitDisplay_6f688860);
    DAT_6f6894e8 = GetProcAddress(DAT_6f6892a4,s_WriteDisplay_6f68886c);
    DAT_6f6894f8 = GetProcAddress(DAT_6f6892a4,s_SendBuffer_6f68887c);
    DAT_6f689508 = GetProcAddress(DAT_6f6892a4,s_SetDecodeCallback_6f688888);
    DAT_6f689518 = GetProcAddress(DAT_6f6892a4,s_InitTCP_IPListen_6f68889c);
    if ((((((DAT_6f6892f8 == (FARPROC)0x0) || (DAT_6f689308 == (FARPROC)0x0)) ||
          (DAT_6f689318 == (FARPROC)0x0)) ||
         (((DAT_6f689328 == (FARPROC)0x0 || (DAT_6f689338 == (FARPROC)0x0)) ||
          ((DAT_6f689348 == (FARPROC)0x0 ||
           ((DAT_6f689358 == (FARPROC)0x0 || (DAT_6f689368 == (FARPROC)0x0)))))))) ||
        (DAT_6f689378 == (FARPROC)0x0)) ||
       (((((((DAT_6f689388 == (FARPROC)0x0 || (DAT_6f689398 == (FARPROC)0x0)) ||
            (DAT_6f6893a8 == (FARPROC)0x0)) ||
           ((DAT_6f6893b8 == (FARPROC)0x0 || (DAT_6f6893c8 == (FARPROC)0x0)))) ||
          (DAT_6f6893d8 == (FARPROC)0x0)) ||
         ((((DAT_6f6893e8 == (FARPROC)0x0 || (DAT_6f6893f8 == (FARPROC)0x0)) ||
           (((DAT_6f689408 == (FARPROC)0x0 ||
             (((DAT_6f689418 == (FARPROC)0x0 || (DAT_6f689428 == (FARPROC)0x0)) ||
              (DAT_6f689438 == (FARPROC)0x0)))) ||
            (((DAT_6f689448 == (FARPROC)0x0 || (DAT_6f689458 == (FARPROC)0x0)) ||
             (DAT_6f689468 == (FARPROC)0x0)))))) ||
          ((DAT_6f6894c8 == (FARPROC)0x0 || (DAT_6f689478 == (FARPROC)0x0)))))) ||
        (((DAT_6f689488 == (FARPROC)0x0 ||
          (((DAT_6f6894b8 == (FARPROC)0x0 || (DAT_6f6894d8 == (FARPROC)0x0)) ||
           (DAT_6f6894e8 == (FARPROC)0x0)))) ||
         (((DAT_6f689498 == (FARPROC)0x0 || (DAT_6f6894f8 == (FARPROC)0x0)) ||
          ((DAT_6f689508 == (FARPROC)0x0 || (DAT_6f689518 == (FARPROC)0x0)))))))))) {
      FreeLibrary(DAT_6f6892a4);
      return 0x29;
    }
  }
  if (DAT_6f6892f8 == (FARPROC)0x0) {
    iVar1 = 0x29;
  }
  else {
    iVar1 = (*DAT_6f6892f8)(param_1,param_2,this);
    if (iVar1 == 0) {
      *param_1 = *param_1 | 0x2000;
      DAT_6f68952c = DAT_6f68952c + 1;
    }
  }
  return iVar1;
}



// Function: InitTCP_IPListen at 6f68221c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall InitTCP_IPListen(void *this,ushort *param_1,undefined4 param_2)

{
  int iVar1;
  
                    /* 0x221c  13  InitTCP_IPListen */
  if ((DAT_6f6892a4 == (HMODULE)0x0) && (DAT_6f68952c == 0)) {
    DAT_6f6892a4 = LoadLibraryA(s_DPAT32_DLL_6f688100);
    if (DAT_6f6892a4 < (HMODULE)0x21) {
      return 0x29;
    }
    DAT_6f6892f8 = GetProcAddress(DAT_6f6892a4,s_InitTCP_IP_6f6888b0);
    DAT_6f689308 = GetProcAddress(DAT_6f6892a4,s_RestoreTCP_IP_6f6888bc);
    _DAT_6f6892d8 = 0;
    _DAT_6f6892e8 = 0;
    _DAT_6f6892b8 = 0;
    _DAT_6f6892c8 = 0;
    DAT_6f689318 = GetProcAddress(DAT_6f6892a4,s_InitDataLink_6f6888cc);
    DAT_6f689328 = GetProcAddress(DAT_6f6892a4,s_CheckDataLink_6f6888dc);
    DAT_6f689338 = GetProcAddress(DAT_6f6892a4,s_LoadDPABuffer_6f6888ec);
    DAT_6f689348 = GetProcAddress(DAT_6f6892a4,s_ReadDPABuffer_6f6888fc);
    DAT_6f689358 = GetProcAddress(DAT_6f6892a4,s_LoadMailBox_6f68890c);
    DAT_6f689368 = GetProcAddress(DAT_6f6892a4,s_UnloadMailBox_6f688918);
    DAT_6f689378 = GetProcAddress(DAT_6f6892a4,s_TransmitMailBoxAsync_6f688928);
    DAT_6f689388 = GetProcAddress(DAT_6f6892a4,s_TransmitMailBox_6f688940);
    DAT_6f689398 = GetProcAddress(DAT_6f6892a4,s_UpdateTransmitMailBox_6f688950);
    DAT_6f6893a8 = GetProcAddress(DAT_6f6892a4,s_UpdateTransmitMailBoxAsync_6f688968);
    DAT_6f6893b8 = GetProcAddress(DAT_6f6892a4,s_UpdateTransMailBoxData_6f688984);
    DAT_6f6893c8 = GetProcAddress(DAT_6f6892a4,s_UpdateTransMailBoxDataAsync_6f68899c);
    DAT_6f6893d8 = GetProcAddress(DAT_6f6892a4,s_UpdateReceiveMailBox_6f6889b8);
    DAT_6f6893e8 = GetProcAddress(DAT_6f6892a4,s_UpdateReceiveMailBoxAsync_6f6889d0);
    DAT_6f6893f8 = GetProcAddress(DAT_6f6892a4,s_ReceiveMailBox_6f6889ec);
    DAT_6f689408 = GetProcAddress(DAT_6f6892a4,s_LoadTimer_6f6889fc);
    DAT_6f689418 = GetProcAddress(DAT_6f6892a4,s_EnableTimerInterrupt_6f688a08);
    DAT_6f689428 = GetProcAddress(DAT_6f6892a4,s_SuspendTimerInterrupt_6f688a20);
    DAT_6f689438 = GetProcAddress(DAT_6f6892a4,s_PauseTimer_6f688a38);
    DAT_6f689448 = GetProcAddress(DAT_6f6892a4,s_ResumeTimer_6f688a44);
    DAT_6f689458 = GetProcAddress(DAT_6f6892a4,s_RequestTimerValue_6f688a50);
    DAT_6f689468 = GetProcAddress(DAT_6f6892a4,s_CheckLock_6f688a64);
    DAT_6f689478 = GetProcAddress(DAT_6f6892a4,s_GoToLoader_6f688a70);
    DAT_6f689488 = GetProcAddress(DAT_6f6892a4,s_ReadDPAChecksum_6f688a7c);
    DAT_6f689498 = GetProcAddress(DAT_6f6892a4,s_ConfigureTransportProtocol_6f688a8c);
    DAT_6f6894a8 = 0;
    DAT_6f6894b8 = GetProcAddress(DAT_6f6892a4,s_ResetDPA_6f688aa8);
    DAT_6f6894c8 = GetProcAddress(DAT_6f6892a4,s_GetLockSeed_6f688ab4);
    DAT_6f6894d8 = GetProcAddress(DAT_6f6892a4,s_InitDisplay_6f688ac0);
    DAT_6f6894e8 = GetProcAddress(DAT_6f6892a4,s_WriteDisplay_6f688acc);
    DAT_6f6894f8 = GetProcAddress(DAT_6f6892a4,s_SendBuffer_6f688adc);
    DAT_6f689508 = GetProcAddress(DAT_6f6892a4,s_SetDecodeCallback_6f688ae8);
    DAT_6f689518 = GetProcAddress(DAT_6f6892a4,s_InitTCP_IPListen_6f688afc);
    if ((((((DAT_6f6892f8 == (FARPROC)0x0) || (DAT_6f689308 == (FARPROC)0x0)) ||
          (DAT_6f689318 == (FARPROC)0x0)) ||
         (((DAT_6f689328 == (FARPROC)0x0 || (DAT_6f689338 == (FARPROC)0x0)) ||
          ((DAT_6f689348 == (FARPROC)0x0 ||
           ((DAT_6f689358 == (FARPROC)0x0 || (DAT_6f689368 == (FARPROC)0x0)))))))) ||
        (DAT_6f689378 == (FARPROC)0x0)) ||
       (((((((DAT_6f689388 == (FARPROC)0x0 || (DAT_6f689398 == (FARPROC)0x0)) ||
            (DAT_6f6893a8 == (FARPROC)0x0)) ||
           ((DAT_6f6893b8 == (FARPROC)0x0 || (DAT_6f6893c8 == (FARPROC)0x0)))) ||
          (DAT_6f6893d8 == (FARPROC)0x0)) ||
         ((((DAT_6f6893e8 == (FARPROC)0x0 || (DAT_6f6893f8 == (FARPROC)0x0)) ||
           (((DAT_6f689408 == (FARPROC)0x0 ||
             (((DAT_6f689418 == (FARPROC)0x0 || (DAT_6f689428 == (FARPROC)0x0)) ||
              (DAT_6f689438 == (FARPROC)0x0)))) ||
            (((DAT_6f689448 == (FARPROC)0x0 || (DAT_6f689458 == (FARPROC)0x0)) ||
             (DAT_6f689468 == (FARPROC)0x0)))))) ||
          ((DAT_6f6894c8 == (FARPROC)0x0 || (DAT_6f689478 == (FARPROC)0x0)))))) ||
        (((DAT_6f689488 == (FARPROC)0x0 ||
          (((DAT_6f6894b8 == (FARPROC)0x0 || (DAT_6f6894d8 == (FARPROC)0x0)) ||
           (DAT_6f6894e8 == (FARPROC)0x0)))) ||
         (((DAT_6f689498 == (FARPROC)0x0 || (DAT_6f6894f8 == (FARPROC)0x0)) ||
          ((DAT_6f689508 == (FARPROC)0x0 || (DAT_6f689518 == (FARPROC)0x0)))))))))) {
      FreeLibrary(DAT_6f6892a4);
      return 0x29;
    }
  }
  if (DAT_6f689518 == (FARPROC)0x0) {
    iVar1 = 0x29;
  }
  else {
    iVar1 = (*DAT_6f689518)(param_1,param_2,this);
    if (iVar1 == 0) {
      *param_1 = *param_1 | 0x2000;
      DAT_6f68952c = DAT_6f68952c + 1;
    }
  }
  return iVar1;
}



// Function: FUN_6f68277c at 6f68277c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_6f68277c(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((DAT_6f689298 == (HMODULE)0x0) && (DAT_6f689520 == 0)) {
    DAT_6f689298 = LoadLibraryA(s_DPAS07_DLL_6f688010);
    if (DAT_6f689298 < (HMODULE)0x21) {
      return 0x29;
    }
    DAT_6f6892b0 = GetProcAddress(DAT_6f689298,s_InitCommLink_6f688b10);
    DAT_6f6892c0 = GetProcAddress(DAT_6f689298,s_RestoreCommLink_6f688b20);
    _DAT_6f6892d0 = 0;
    _DAT_6f6892e0 = 0;
    _DAT_6f6892f0 = 0;
    _DAT_6f689300 = 0;
    DAT_6f689310 = GetProcAddress(DAT_6f689298,s_InitDataLink_6f688b30);
    DAT_6f689320 = GetProcAddress(DAT_6f689298,s_CheckDataLink_6f688b40);
    DAT_6f689330 = GetProcAddress(DAT_6f689298,s_LoadDPABuffer_6f688b50);
    DAT_6f689340 = GetProcAddress(DAT_6f689298,s_ReadDPABuffer_6f688b60);
    DAT_6f689350 = GetProcAddress(DAT_6f689298,s_LoadMailBox_6f688b70);
    DAT_6f689360 = GetProcAddress(DAT_6f689298,s_UnloadMailBox_6f688b7c);
    DAT_6f689370 = GetProcAddress(DAT_6f689298,s_TransmitMailBoxAsync_6f688b8c);
    DAT_6f689380 = GetProcAddress(DAT_6f689298,s_TransmitMailBox_6f688ba4);
    DAT_6f689390 = GetProcAddress(DAT_6f689298,s_UpdateTransmitMailBox_6f688bb4);
    DAT_6f6893a0 = GetProcAddress(DAT_6f689298,s_UpdateTransmitMailBoxAsync_6f688bcc);
    DAT_6f6893b0 = GetProcAddress(DAT_6f689298,s_UpdateTransMailBoxData_6f688be8);
    DAT_6f6893c0 = GetProcAddress(DAT_6f689298,s_UpdateTransMailBoxDataAsync_6f688c00);
    DAT_6f6893d0 = GetProcAddress(DAT_6f689298,s_UpdateReceiveMailBox_6f688c1c);
    DAT_6f6893e0 = GetProcAddress(DAT_6f689298,s_UpdateReceiveMailBoxAsync_6f688c34);
    DAT_6f6893f0 = GetProcAddress(DAT_6f689298,s_ReceiveMailBox_6f688c50);
    DAT_6f689400 = GetProcAddress(DAT_6f689298,s_LoadTimer_6f688c60);
    DAT_6f689410 = GetProcAddress(DAT_6f689298,s_EnableTimerInterrupt_6f688c6c);
    DAT_6f689420 = GetProcAddress(DAT_6f689298,s_SuspendTimerInterrupt_6f688c84);
    DAT_6f689430 = GetProcAddress(DAT_6f689298,s_PauseTimer_6f688c9c);
    DAT_6f689440 = GetProcAddress(DAT_6f689298,s_ResumeTimer_6f688ca8);
    DAT_6f689450 = GetProcAddress(DAT_6f689298,s_RequestTimerValue_6f688cb4);
    DAT_6f689460 = GetProcAddress(DAT_6f689298,s_CheckLock_6f688cc8);
    DAT_6f689470 = GetProcAddress(DAT_6f689298,s_GoToLoader_6f688cd4);
    DAT_6f689480 = GetProcAddress(DAT_6f689298,s_ReadDPAChecksum_6f688ce0);
    DAT_6f689490 = GetProcAddress(DAT_6f689298,s_ConfigureTransportProtocol_6f688cf0);
    DAT_6f6894a0 = GetProcAddress(DAT_6f689298,s_SetBaudRate_6f688d0c);
    DAT_6f6894b0 = GetProcAddress(DAT_6f689298,s_ResetDPA_6f688d18);
    DAT_6f6894c0 = GetProcAddress(DAT_6f689298,s_GetLockSeed_6f688d24);
    DAT_6f6894d0 = GetProcAddress(DAT_6f689298,s_InitDisplay_6f688d30);
    DAT_6f6894e0 = GetProcAddress(DAT_6f689298,s_WriteDisplay_6f688d3c);
    DAT_6f6894f0 = GetProcAddress(DAT_6f689298,s_SendBuffer_6f688d4c);
    DAT_6f689500 = GetProcAddress(DAT_6f689298,s_SetDecodeCallback_6f688d58);
    if ((((((DAT_6f6892b0 == (FARPROC)0x0) || (DAT_6f6892c0 == (FARPROC)0x0)) ||
          (DAT_6f689310 == (FARPROC)0x0)) ||
         (((DAT_6f689320 == (FARPROC)0x0 || (DAT_6f689330 == (FARPROC)0x0)) ||
          ((DAT_6f689340 == (FARPROC)0x0 ||
           ((DAT_6f689350 == (FARPROC)0x0 || (DAT_6f689360 == (FARPROC)0x0)))))))) ||
        (DAT_6f689370 == (FARPROC)0x0)) ||
       (((((((DAT_6f689380 == (FARPROC)0x0 || (DAT_6f689390 == (FARPROC)0x0)) ||
            (DAT_6f6893a0 == (FARPROC)0x0)) ||
           ((DAT_6f6893b0 == (FARPROC)0x0 || (DAT_6f6893c0 == (FARPROC)0x0)))) ||
          (DAT_6f6893d0 == (FARPROC)0x0)) ||
         ((((DAT_6f6893e0 == (FARPROC)0x0 || (DAT_6f6893f0 == (FARPROC)0x0)) ||
           (((DAT_6f689400 == (FARPROC)0x0 ||
             (((DAT_6f689410 == (FARPROC)0x0 || (DAT_6f689420 == (FARPROC)0x0)) ||
              (DAT_6f689430 == (FARPROC)0x0)))) ||
            (((DAT_6f689440 == (FARPROC)0x0 || (DAT_6f689450 == (FARPROC)0x0)) ||
             (DAT_6f689460 == (FARPROC)0x0)))))) ||
          ((DAT_6f6894c0 == (FARPROC)0x0 || (DAT_6f689470 == (FARPROC)0x0)))))) ||
        (((DAT_6f689480 == (FARPROC)0x0 ||
          (((DAT_6f6894a0 == (FARPROC)0x0 || (DAT_6f6894b0 == (FARPROC)0x0)) ||
           (DAT_6f6894d0 == (FARPROC)0x0)))) ||
         (((DAT_6f6894e0 == (FARPROC)0x0 || (DAT_6f689490 == (FARPROC)0x0)) ||
          ((DAT_6f6894f0 == (FARPROC)0x0 || (DAT_6f689500 == (FARPROC)0x0)))))))))) {
      FreeLibrary(DAT_6f689298);
      return 0x29;
    }
  }
  if (DAT_6f6892b0 == (FARPROC)0x0) {
    iVar1 = 0x29;
  }
  else {
    iVar1 = (*DAT_6f6892b0)(param_1,param_2,this);
    if (iVar1 == 0) {
      DAT_6f689520 = DAT_6f689520 + 1;
    }
  }
  return iVar1;
}



// Function: FUN_6f682cc1 at 6f682cc1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_6f682cc1(void *this,ushort *param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((DAT_6f6892a8 == (HMODULE)0x0) && (DAT_6f689530 == 0)) {
    DAT_6f6892a8 = LoadLibraryA(s_DPAH32_DLL_6f688150);
    if (DAT_6f6892a8 < (HMODULE)0x21) {
      return 0x29;
    }
    DAT_6f6892bc = GetProcAddress(DAT_6f6892a8,s_InitCommLink_6f688d6c);
    DAT_6f6892cc = GetProcAddress(DAT_6f6892a8,s_RestoreCommLink_6f688d7c);
    _DAT_6f6892dc = 0;
    _DAT_6f6892ec = 0;
    _DAT_6f6892fc = 0;
    _DAT_6f68930c = 0;
    DAT_6f68931c = GetProcAddress(DAT_6f6892a8,s_InitDataLink_6f688d8c);
    DAT_6f68932c = GetProcAddress(DAT_6f6892a8,s_CheckDataLink_6f688d9c);
    DAT_6f68933c = GetProcAddress(DAT_6f6892a8,s_LoadDPABuffer_6f688dac);
    DAT_6f68934c = GetProcAddress(DAT_6f6892a8,s_ReadDPABuffer_6f688dbc);
    DAT_6f68935c = GetProcAddress(DAT_6f6892a8,s_LoadMailBox_6f688dcc);
    DAT_6f68936c = GetProcAddress(DAT_6f6892a8,s_UnloadMailBox_6f688dd8);
    DAT_6f68937c = GetProcAddress(DAT_6f6892a8,s_TransmitMailBoxAsync_6f688de8);
    DAT_6f68938c = GetProcAddress(DAT_6f6892a8,s_TransmitMailBox_6f688e00);
    DAT_6f68939c = GetProcAddress(DAT_6f6892a8,s_UpdateTransmitMailBox_6f688e10);
    DAT_6f6893ac = GetProcAddress(DAT_6f6892a8,s_UpdateTransmitMailBoxAsync_6f688e28);
    DAT_6f6893bc = GetProcAddress(DAT_6f6892a8,s_UpdateTransMailBoxData_6f688e44);
    DAT_6f6893cc = GetProcAddress(DAT_6f6892a8,s_UpdateTransMailBoxDataAsync_6f688e5c);
    DAT_6f6893dc = GetProcAddress(DAT_6f6892a8,s_UpdateReceiveMailBox_6f688e78);
    DAT_6f6893ec = GetProcAddress(DAT_6f6892a8,s_UpdateReceiveMailBoxAsync_6f688e90);
    DAT_6f6893fc = GetProcAddress(DAT_6f6892a8,s_ReceiveMailBox_6f688eac);
    DAT_6f68940c = GetProcAddress(DAT_6f6892a8,s_LoadTimer_6f688ebc);
    DAT_6f68941c = GetProcAddress(DAT_6f6892a8,s_EnableTimerInterrupt_6f688ec8);
    DAT_6f68942c = GetProcAddress(DAT_6f6892a8,s_SuspendTimerInterrupt_6f688ee0);
    DAT_6f68943c = GetProcAddress(DAT_6f6892a8,s_PauseTimer_6f688ef8);
    DAT_6f68944c = GetProcAddress(DAT_6f6892a8,s_ResumeTimer_6f688f04);
    DAT_6f68945c = GetProcAddress(DAT_6f6892a8,s_RequestTimerValue_6f688f10);
    DAT_6f68946c = GetProcAddress(DAT_6f6892a8,s_CheckLock_6f688f24);
    DAT_6f68947c = GetProcAddress(DAT_6f6892a8,s_GoToLoader_6f688f30);
    DAT_6f68948c = GetProcAddress(DAT_6f6892a8,s_ReadDPAChecksum_6f688f3c);
    DAT_6f68949c = GetProcAddress(DAT_6f6892a8,s_ConfigureTransportProtocol_6f688f4c);
    DAT_6f6894ac = GetProcAddress(DAT_6f6892a8,s_SetBaudRate_6f688f68);
    DAT_6f6894bc = GetProcAddress(DAT_6f6892a8,s_ResetDPA_6f688f74);
    DAT_6f6894cc = GetProcAddress(DAT_6f6892a8,s_GetLockSeed_6f688f80);
    DAT_6f6894dc = GetProcAddress(DAT_6f6892a8,s_InitDisplay_6f688f8c);
    DAT_6f6894ec = GetProcAddress(DAT_6f6892a8,s_WriteDisplay_6f688f98);
    DAT_6f6894fc = GetProcAddress(DAT_6f6892a8,s_SendBuffer_6f688fa8);
    DAT_6f68950c = GetProcAddress(DAT_6f6892a8,s_SetDecodeCallback_6f688fb4);
    if ((((((DAT_6f6892bc == (FARPROC)0x0) || (DAT_6f6892cc == (FARPROC)0x0)) ||
          (DAT_6f68931c == (FARPROC)0x0)) ||
         (((DAT_6f68932c == (FARPROC)0x0 || (DAT_6f68933c == (FARPROC)0x0)) ||
          ((DAT_6f68934c == (FARPROC)0x0 ||
           ((DAT_6f68935c == (FARPROC)0x0 || (DAT_6f68936c == (FARPROC)0x0)))))))) ||
        (DAT_6f68937c == (FARPROC)0x0)) ||
       (((((((DAT_6f68938c == (FARPROC)0x0 || (DAT_6f68939c == (FARPROC)0x0)) ||
            (DAT_6f6893ac == (FARPROC)0x0)) ||
           ((DAT_6f6893bc == (FARPROC)0x0 || (DAT_6f6893cc == (FARPROC)0x0)))) ||
          (DAT_6f6893dc == (FARPROC)0x0)) ||
         ((((DAT_6f6893ec == (FARPROC)0x0 || (DAT_6f6893fc == (FARPROC)0x0)) ||
           (((DAT_6f68940c == (FARPROC)0x0 ||
             (((DAT_6f68941c == (FARPROC)0x0 || (DAT_6f68942c == (FARPROC)0x0)) ||
              (DAT_6f68943c == (FARPROC)0x0)))) ||
            (((DAT_6f68944c == (FARPROC)0x0 || (DAT_6f68945c == (FARPROC)0x0)) ||
             (DAT_6f68946c == (FARPROC)0x0)))))) ||
          ((DAT_6f6894cc == (FARPROC)0x0 || (DAT_6f68947c == (FARPROC)0x0)))))) ||
        (((DAT_6f68948c == (FARPROC)0x0 ||
          (((DAT_6f6894ac == (FARPROC)0x0 || (DAT_6f6894bc == (FARPROC)0x0)) ||
           (DAT_6f6894dc == (FARPROC)0x0)))) ||
         (((DAT_6f6894ec == (FARPROC)0x0 || (DAT_6f68949c == (FARPROC)0x0)) ||
          ((DAT_6f6894fc == (FARPROC)0x0 || (DAT_6f68950c == (FARPROC)0x0)))))))))) {
      FreeLibrary(DAT_6f6892a8);
      return 0x29;
    }
  }
  if (DAT_6f6892bc == (FARPROC)0x0) {
    iVar1 = 0x29;
  }
  else {
    iVar1 = (*DAT_6f6892bc)(param_1,param_2,this);
    if (iVar1 == 0) {
      *param_1 = *param_1 | 0x4000;
      DAT_6f689530 = DAT_6f689530 + 1;
    }
  }
  return iVar1;
}



// Function: RestorePCCard at 6f683215

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int RestorePCCard(ushort param_1)

{
  int iVar1;
  
                    /* 0x3215  25  RestorePCCard */
  if ((param_1 & DAT_6f6881a0) == 0x8000) {
    DAT_6f689524 = DAT_6f689524 + -1;
    if (DAT_6f689524 < 0) {
      DAT_6f689524 = 0;
    }
    if (DAT_6f6892e4 == (code *)0x0) {
      iVar1 = 0x29;
    }
    else {
      iVar1 = (*DAT_6f6892e4)(CONCAT22((short)DAT_6f6881a0 >> 0xf,param_1) & 0xffff1fff,
                              param_1 & 0x1fff,0);
      if ((iVar1 == 0) && (DAT_6f689524 == 0)) {
        FreeLibrary(DAT_6f68929c);
        DAT_6f68929c = (HMODULE)0x0;
        _DAT_6f6892b4 = 0;
        _DAT_6f6892c4 = 0;
        DAT_6f6892d4 = 0;
        DAT_6f6892e4 = (code *)0x0;
        DAT_6f689314 = 0;
        DAT_6f689324 = 0;
        DAT_6f689334 = 0;
        DAT_6f689344 = 0;
        DAT_6f689354 = 0;
        DAT_6f689364 = 0;
        DAT_6f689374 = 0;
        DAT_6f689384 = 0;
        DAT_6f689394 = 0;
        DAT_6f6893a4 = 0;
        DAT_6f6893b4 = 0;
        DAT_6f6893c4 = 0;
        DAT_6f6893d4 = 0;
        DAT_6f6893e4 = 0;
        DAT_6f6893f4 = 0;
        DAT_6f689404 = 0;
        DAT_6f689414 = 0;
        DAT_6f689424 = 0;
        DAT_6f689434 = 0;
        DAT_6f689444 = 0;
        DAT_6f689454 = 0;
        DAT_6f689464 = 0;
        DAT_6f6894c4 = 0;
        DAT_6f689474 = 0;
        DAT_6f689484 = 0;
        DAT_6f689494 = 0;
        DAT_6f6894f4 = 0;
      }
    }
  }
  else {
    iVar1 = 0x20;
  }
  return iVar1;
}



// Function: RestoreTCP_IP at 6f68340b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int RestoreTCP_IP(ushort param_1)

{
  int iVar1;
  
                    /* 0x340b  26  RestoreTCP_IP */
  if ((param_1 & DAT_6f6881a0) == 0x2000) {
    DAT_6f68952c = DAT_6f68952c + -1;
    if (DAT_6f68952c < 0) {
      DAT_6f68952c = 0;
    }
    if (DAT_6f689308 == (code *)0x0) {
      iVar1 = 0x29;
    }
    else {
      iVar1 = (*DAT_6f689308)(CONCAT22((short)DAT_6f6881a0 >> 0xf,param_1) & 0xffff1fff,0);
      if ((iVar1 == 0) && (DAT_6f68952c == 0)) {
        FreeLibrary(DAT_6f6892a4);
        DAT_6f6892a4 = (HMODULE)0x0;
        _DAT_6f6892b8 = 0;
        _DAT_6f6892c8 = 0;
        _DAT_6f6892d8 = 0;
        _DAT_6f6892e8 = 0;
        DAT_6f6892f8 = 0;
        DAT_6f689308 = (code *)0x0;
        DAT_6f689318 = 0;
        DAT_6f689328 = 0;
        DAT_6f689338 = 0;
        DAT_6f689348 = 0;
        DAT_6f689358 = 0;
        DAT_6f689368 = 0;
        DAT_6f689378 = 0;
        DAT_6f689388 = 0;
        DAT_6f689398 = 0;
        DAT_6f6893a8 = 0;
        DAT_6f6893b8 = 0;
        DAT_6f6893c8 = 0;
        DAT_6f6893d8 = 0;
        DAT_6f6893e8 = 0;
        DAT_6f6893f8 = 0;
        DAT_6f689408 = 0;
        DAT_6f689418 = 0;
        DAT_6f689428 = 0;
        DAT_6f689438 = 0;
        DAT_6f689448 = 0;
        DAT_6f689458 = 0;
        DAT_6f689468 = 0;
        DAT_6f6894c8 = 0;
        DAT_6f689478 = 0;
        DAT_6f689488 = 0;
        DAT_6f689498 = 0;
        DAT_6f6894f8 = 0;
      }
    }
  }
  else {
    iVar1 = 0x20;
  }
  return iVar1;
}



// Function: RestoreCommLink at 6f683615

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int RestoreCommLink(ushort param_1)

{
  int iVar1;
  
                    /* 0x3615  23  RestoreCommLink */
  if ((param_1 & DAT_6f6881a0) == 0) {
    DAT_6f689520 = DAT_6f689520 + -1;
    if (DAT_6f689520 < 0) {
      DAT_6f689520 = 0;
    }
    if (DAT_6f6892c0 == (code *)0x0) {
      iVar1 = 0x29;
    }
    else {
      iVar1 = (*DAT_6f6892c0)(CONCAT22((short)DAT_6f6881a0 >> 0xf,param_1) & 0xffff1fff,0);
      if ((iVar1 == 0) && (DAT_6f689520 == 0)) {
        FreeLibrary(DAT_6f689298);
        DAT_6f689298 = (HMODULE)0x0;
        DAT_6f6892b0 = 0;
        DAT_6f6892c0 = (code *)0x0;
        _DAT_6f6892d0 = 0;
        _DAT_6f6892e0 = 0;
        DAT_6f689310 = 0;
        DAT_6f689320 = 0;
        DAT_6f689330 = 0;
        DAT_6f689340 = 0;
        DAT_6f689350 = 0;
        DAT_6f689360 = 0;
        DAT_6f689370 = 0;
        DAT_6f689380 = 0;
        DAT_6f689390 = 0;
        DAT_6f6893a0 = 0;
        DAT_6f6893b0 = 0;
        DAT_6f6893c0 = 0;
        DAT_6f6893d0 = 0;
        DAT_6f6893e0 = 0;
        DAT_6f6893f0 = 0;
        DAT_6f689400 = 0;
        DAT_6f689410 = 0;
        DAT_6f689420 = 0;
        DAT_6f689430 = 0;
        DAT_6f689440 = 0;
        DAT_6f689450 = 0;
        DAT_6f689460 = 0;
        DAT_6f6894c0 = 0;
        DAT_6f689470 = 0;
        DAT_6f689480 = 0;
        DAT_6f689490 = 0;
        DAT_6f6894f0 = 0;
      }
    }
  }
  else {
    iVar1 = 0x20;
  }
  return iVar1;
}



// Function: FUN_6f683807 at 6f683807

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_6f683807(ushort param_1)

{
  int iVar1;
  
  if ((param_1 & DAT_6f6881a0) == 0x4000) {
    DAT_6f689530 = DAT_6f689530 + -1;
    if (DAT_6f689530 < 0) {
      DAT_6f689530 = 0;
    }
    if (DAT_6f6892cc == (code *)0x0) {
      iVar1 = 0x29;
    }
    else {
      iVar1 = (*DAT_6f6892cc)(CONCAT22((short)DAT_6f6881a0 >> 0xf,param_1) & 0xffff1fff,0);
      if ((iVar1 == 0) && (DAT_6f689530 == 0)) {
        FreeLibrary(DAT_6f6892a8);
        DAT_6f6892a8 = (HMODULE)0x0;
        DAT_6f6892bc = 0;
        DAT_6f6892cc = (code *)0x0;
        _DAT_6f6892dc = 0;
        _DAT_6f6892ec = 0;
        _DAT_6f6892fc = 0;
        _DAT_6f68930c = 0;
        DAT_6f68931c = 0;
        DAT_6f68932c = 0;
        DAT_6f68933c = 0;
        DAT_6f68934c = 0;
        DAT_6f68935c = 0;
        DAT_6f68936c = 0;
        DAT_6f68937c = 0;
        DAT_6f68938c = 0;
        DAT_6f68939c = 0;
        DAT_6f6893ac = 0;
        DAT_6f6893bc = 0;
        DAT_6f6893cc = 0;
        DAT_6f6893dc = 0;
        DAT_6f6893ec = 0;
        DAT_6f6893fc = 0;
        DAT_6f68940c = 0;
        DAT_6f68941c = 0;
        DAT_6f68942c = 0;
        DAT_6f68943c = 0;
        DAT_6f68944c = 0;
        DAT_6f68945c = 0;
        DAT_6f68946c = 0;
        DAT_6f6894cc = 0;
        DAT_6f68947c = 0;
        DAT_6f68948c = 0;
        DAT_6f68949c = 0;
        DAT_6f6894fc = 0;
      }
    }
  }
  else {
    iVar1 = 0x20;
  }
  return iVar1;
}



// Function: CheckDataLink at 6f683a0f

int CheckDataLink(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x3a0f  1  CheckDataLink */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f683aad;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f683aad;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 3;
      local_10 = 0x21;
      goto LAB_6f683aad;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f683aad;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f683aad;
    }
  }
  local_10 = 0x21;
LAB_6f683aad:
  if (local_10 == 0) {
    if ((&DAT_6f689320)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f689320)[local_8])
                           (CONCAT22((short)DAT_6f6881a0 >> 0xf,param_1) & 0xffff1fff,param_2);
    }
  }
  return local_10;
}



// Function: LoadDPABuffer at 6f683aea

int LoadDPABuffer(ushort param_1,undefined4 param_2,undefined2 param_3,undefined2 param_4)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x3aea  14  LoadDPABuffer */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f683b88;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f683b88;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f683b88;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f683b88;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f683b88;
    }
  }
  local_10 = 0x21;
LAB_6f683b88:
  if (local_10 == 0) {
    if ((&DAT_6f689330)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f689330)[local_8])
                           (CONCAT22((short)uVar1 >> 0xf,param_1) & 0xffff1fff,param_2,
                            CONCAT22((short)DAT_6f6881a0 >> 0xf,param_3),
                            CONCAT22((short)uVar1 >> 0xf,param_4));
    }
  }
  return local_10;
}



// Function: ReadDPABuffer at 6f683bcf

int ReadDPABuffer(ushort param_1,undefined4 param_2,undefined2 param_3,undefined2 param_4)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x3bcf  18  ReadDPABuffer */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f683c6d;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f683c6d;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f683c6d;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f683c6d;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f683c6d;
    }
  }
  local_10 = 0x21;
LAB_6f683c6d:
  if (local_10 == 0) {
    if ((&DAT_6f689340)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f689340)[local_8])
                           (CONCAT22((short)uVar1 >> 0xf,param_1) & 0xffff1fff,param_2,
                            CONCAT22((short)DAT_6f6881a0 >> 0xf,param_3),
                            CONCAT22((short)uVar1 >> 0xf,param_4));
    }
  }
  return local_10;
}



// Function: CheckLock at 6f683cb4

int CheckLock(ushort param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x3cb4  2  CheckLock */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f683d52;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f683d52;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f683d52;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f683d52;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f683d52;
    }
  }
  local_10 = 0x21;
LAB_6f683d52:
  if (local_10 == 0) {
    if ((&DAT_6f689460)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f689460)[local_8])(param_1 & 0x1fff,param_2,param_3);
    }
  }
  return local_10;
}



// Function: GetLockSeed at 6f683d93

int GetLockSeed(ushort param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x3d93  5  GetLockSeed */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f683e31;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f683e31;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f683e31;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f683e31;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f683e31;
    }
  }
  local_10 = 0x21;
LAB_6f683e31:
  if (local_10 == 0) {
    if ((&DAT_6f6894c0)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f6894c0)[local_8])(param_1 & 0x1fff,param_2,param_3);
    }
  }
  return local_10;
}



// Function: GoToLoader at 6f683e72

int GoToLoader(ushort param_1)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x3e72  6  GoToLoader */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f683f10;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f683f10;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f683f10;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f683f10;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f683f10;
    }
  }
  local_10 = 0x21;
LAB_6f683f10:
  if (local_10 == 0) {
    if ((&DAT_6f689470)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f689470)[local_8])
                           (CONCAT22((short)uVar1 >> 0xf,param_1) & 0xffff1fff);
    }
  }
  return local_10;
}



// Function: InitDataLink at 6f683f49

int InitDataLink(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x3f49  9  InitDataLink */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f683fe7;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f683fe7;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f683fe7;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f683fe7;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f683fe7;
    }
  }
  local_10 = 0x21;
LAB_6f683fe7:
  if (local_10 == 0) {
    if ((&DAT_6f689310)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f689310)[local_8])
                           (CONCAT22((short)DAT_6f6881a0 >> 0xf,param_1) & 0xffff1fff,param_2);
    }
  }
  return local_10;
}



// Function: LoadMailBox at 6f684024

int LoadMailBox(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x4024  15  LoadMailBox */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f6840c2;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f6840c2;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f6840c2;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f6840c2;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f6840c2;
    }
  }
  local_10 = 0x21;
LAB_6f6840c2:
  if (local_10 == 0) {
    if ((&DAT_6f689350)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f689350)[local_8])
                           (CONCAT22((short)DAT_6f6881a0 >> 0xf,param_1) & 0xffff1fff,param_2);
    }
  }
  return local_10;
}



// Function: TransmitMailBoxAsync at 6f6840ff

int TransmitMailBoxAsync(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x40ff  39  TransmitMailBoxAsync */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f68419d;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f68419d;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f68419d;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f68419d;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f68419d;
    }
  }
  local_10 = 0x21;
LAB_6f68419d:
  if (local_10 == 0) {
    if ((&DAT_6f689370)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f689370)[local_8])
                           (CONCAT22((short)DAT_6f6881a0 >> 0xf,param_1) & 0xffff1fff,param_2);
    }
  }
  return local_10;
}



// Function: TransmitMailBox at 6f6841da

int TransmitMailBox(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x41da  38  TransmitMailBox */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f684278;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f684278;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f684278;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f684278;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f684278;
    }
  }
  local_10 = 0x21;
LAB_6f684278:
  if (local_10 == 0) {
    if ((&DAT_6f689380)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f689380)[local_8])
                           (CONCAT22((short)DAT_6f6881a0 >> 0xf,param_1) & 0xffff1fff,param_2);
    }
  }
  return local_10;
}



// Function: UpdateTransMailBoxDataAsync at 6f6842b5

int UpdateTransMailBoxDataAsync(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x42b5  44  UpdateTransMailBoxDataAsync */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f684353;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f684353;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f684353;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f684353;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f684353;
    }
  }
  local_10 = 0x21;
LAB_6f684353:
  if (local_10 == 0) {
    if ((&DAT_6f6893c0)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f6893c0)[local_8])
                           (CONCAT22((short)DAT_6f6881a0 >> 0xf,param_1) & 0xffff1fff,param_2);
    }
  }
  return local_10;
}



// Function: UpdateTransMailBoxData at 6f684390

int UpdateTransMailBoxData(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x4390  43  UpdateTransMailBoxData */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f68442e;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f68442e;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f68442e;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f68442e;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f68442e;
    }
  }
  local_10 = 0x21;
LAB_6f68442e:
  if (local_10 == 0) {
    if ((&DAT_6f6893b0)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f6893b0)[local_8])
                           (CONCAT22((short)DAT_6f6881a0 >> 0xf,param_1) & 0xffff1fff,param_2);
    }
  }
  return local_10;
}



// Function: UpdateTransmitMailBoxAsync at 6f68446b

int UpdateTransmitMailBoxAsync(ushort param_1,undefined4 param_2,undefined1 param_3)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x446b  46  UpdateTransmitMailBoxAsync */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f684509;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f684509;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f684509;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f684509;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f684509;
    }
  }
  local_10 = 0x21;
LAB_6f684509:
  if (local_10 == 0) {
    if ((&DAT_6f6893a0)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f6893a0)[local_8])
                           (param_1 & 0x1fff,param_2,CONCAT31((int3)(char)(uVar1 >> 8),param_3));
    }
  }
  return local_10;
}



// Function: UpdateTransmitMailBox at 6f68454a

int UpdateTransmitMailBox(ushort param_1,undefined4 param_2,undefined1 param_3)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x454a  45  UpdateTransmitMailBox */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f6845e8;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f6845e8;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f6845e8;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f6845e8;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f6845e8;
    }
  }
  local_10 = 0x21;
LAB_6f6845e8:
  if (local_10 == 0) {
    if ((&DAT_6f689390)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f689390)[local_8])
                           (param_1 & 0x1fff,param_2,CONCAT31((int3)(char)(uVar1 >> 8),param_3));
    }
  }
  return local_10;
}



// Function: UpdateReceiveMailBoxAsync at 6f684629

int UpdateReceiveMailBoxAsync(ushort param_1,undefined4 param_2,undefined1 param_3)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x4629  42  UpdateReceiveMailBoxAsync */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f6846c7;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f6846c7;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f6846c7;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f6846c7;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f6846c7;
    }
  }
  local_10 = 0x21;
LAB_6f6846c7:
  if (local_10 == 0) {
    if ((&DAT_6f6893e0)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f6893e0)[local_8])
                           (param_1 & 0x1fff,param_2,CONCAT31((int3)(char)(uVar1 >> 8),param_3));
    }
  }
  return local_10;
}



// Function: UpdateReceiveMailBox at 6f684708

int UpdateReceiveMailBox(ushort param_1,undefined4 param_2,undefined1 param_3)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x4708  41  UpdateReceiveMailBox */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f6847a6;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f6847a6;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f6847a6;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f6847a6;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f6847a6;
    }
  }
  local_10 = 0x21;
LAB_6f6847a6:
  if (local_10 == 0) {
    if ((&DAT_6f6893d0)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f6893d0)[local_8])
                           (param_1 & 0x1fff,param_2,CONCAT31((int3)(char)(uVar1 >> 8),param_3));
    }
  }
  return local_10;
}



// Function: ReceiveMailBox at 6f6847e7

int ReceiveMailBox(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x47e7  20  ReceiveMailBox */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f684885;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f684885;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f684885;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f684885;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f684885;
    }
  }
  local_10 = 0x21;
LAB_6f684885:
  if (local_10 == 0) {
    if ((&DAT_6f6893f0)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f6893f0)[local_8])
                           (CONCAT22((short)DAT_6f6881a0 >> 0xf,param_1) & 0xffff1fff,param_2);
    }
  }
  return local_10;
}



// Function: UnloadMailBox at 6f6848c2

int UnloadMailBox(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x48c2  40  UnloadMailBox */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f684960;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f684960;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f684960;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f684960;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f684960;
    }
  }
  local_10 = 0x21;
LAB_6f684960:
  if (local_10 == 0) {
    if ((&DAT_6f689360)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f689360)[local_8])
                           (CONCAT22((short)DAT_6f6881a0 >> 0xf,param_1) & 0xffff1fff,param_2);
    }
  }
  return local_10;
}



// Function: LoadTimer at 6f68499d

int LoadTimer(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x499d  16  LoadTimer */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f684a3b;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f684a3b;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f684a3b;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f684a3b;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f684a3b;
    }
  }
  local_10 = 0x21;
LAB_6f684a3b:
  if (local_10 == 0) {
    if ((&DAT_6f689400)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f689400)[local_8])
                           (CONCAT22((short)DAT_6f6881a0 >> 0xf,param_1) & 0xffff1fff,param_2);
    }
  }
  return local_10;
}



// Function: EnableTimerInterrupt at 6f684a78

int EnableTimerInterrupt(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x4a78  4  EnableTimerInterrupt */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f684b16;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f684b16;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f684b16;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f684b16;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f684b16;
    }
  }
  local_10 = 0x21;
LAB_6f684b16:
  if (local_10 == 0) {
    if ((&DAT_6f689410)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f689410)[local_8])
                           (CONCAT22((short)DAT_6f6881a0 >> 0xf,param_1) & 0xffff1fff,param_2);
    }
  }
  return local_10;
}



// Function: SuspendTimerInterrupt at 6f684b53

int SuspendTimerInterrupt(ushort param_1)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x4b53  37  SuspendTimerInterrupt */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f684bf1;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f684bf1;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f684bf1;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f684bf1;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f684bf1;
    }
  }
  local_10 = 0x21;
LAB_6f684bf1:
  if (local_10 == 0) {
    if ((&DAT_6f689420)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f689420)[local_8])
                           (CONCAT22((short)uVar1 >> 0xf,param_1) & 0xffff1fff);
    }
  }
  return local_10;
}



// Function: PauseTimer at 6f684c2a

int PauseTimer(ushort param_1)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x4c2a  17  PauseTimer */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f684cc8;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f684cc8;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f684cc8;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f684cc8;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f684cc8;
    }
  }
  local_10 = 0x21;
LAB_6f684cc8:
  if (local_10 == 0) {
    if ((&DAT_6f689430)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f689430)[local_8])
                           (CONCAT22((short)uVar1 >> 0xf,param_1) & 0xffff1fff);
    }
  }
  return local_10;
}



// Function: ResumeTimer at 6f684d01

int ResumeTimer(ushort param_1)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x4d01  27  ResumeTimer */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f684d9f;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f684d9f;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f684d9f;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f684d9f;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f684d9f;
    }
  }
  local_10 = 0x21;
LAB_6f684d9f:
  if (local_10 == 0) {
    if ((&DAT_6f689440)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f689440)[local_8])
                           (CONCAT22((short)uVar1 >> 0xf,param_1) & 0xffff1fff);
    }
  }
  return local_10;
}



// Function: RequestTimerValue at 6f684dd8

int RequestTimerValue(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x4dd8  21  RequestTimerValue */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f684e76;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f684e76;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f684e76;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f684e76;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f684e76;
    }
  }
  local_10 = 0x21;
LAB_6f684e76:
  if (local_10 == 0) {
    if ((&DAT_6f689450)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f689450)[local_8])
                           (CONCAT22((short)DAT_6f6881a0 >> 0xf,param_1) & 0xffff1fff,param_2);
    }
  }
  return local_10;
}



// Function: ReadDPAChecksum at 6f684eb3

int ReadDPAChecksum(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x4eb3  19  ReadDPAChecksum */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f684f51;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f684f51;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f684f51;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f684f51;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f684f51;
    }
  }
  local_10 = 0x21;
LAB_6f684f51:
  if (local_10 == 0) {
    if ((&DAT_6f689480)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f689480)[local_8])
                           (CONCAT22((short)DAT_6f6881a0 >> 0xf,param_1) & 0xffff1fff,param_2);
    }
  }
  return local_10;
}



// Function: ConfigureTransportProtocol at 6f684f8e

int ConfigureTransportProtocol(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x4f8e  3  ConfigureTransportProtocol */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f68502c;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f68502c;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f68502c;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f68502c;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f68502c;
    }
  }
  local_10 = 0x21;
LAB_6f68502c:
  if (local_10 == 0) {
    if ((&DAT_6f689490)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f689490)[local_8])
                           (CONCAT22((short)DAT_6f6881a0 >> 0xf,param_1) & 0xffff1fff,param_2);
    }
  }
  return local_10;
}



// Function: SetBaudRate at 6f685069

int SetBaudRate(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x5069  29  SetBaudRate */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f68510e;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      local_10 = 0x21;
      goto LAB_6f68510e;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f68510e;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f68510e;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f68510e;
    }
  }
  local_10 = 0x21;
LAB_6f68510e:
  if (local_10 == 0) {
    if ((&DAT_6f6894a0)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f6894a0)[local_8])
                           (CONCAT22((short)DAT_6f6881a0 >> 0xf,param_1) & 0xffff1fff,param_2);
    }
  }
  return local_10;
}



// Function: ResetDPA at 6f68514b

int ResetDPA(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x514b  22  ResetDPA */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f6851e9;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f6851e9;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f6851e9;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f6851e9;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f6851e9;
    }
  }
  local_10 = 0x21;
LAB_6f6851e9:
  if (local_10 == 0) {
    if ((&DAT_6f6894b0)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f6894b0)[local_8])
                           (CONCAT22((short)DAT_6f6881a0 >> 0xf,param_1) & 0xffff1fff,param_2);
    }
  }
  return local_10;
}



// Function: WriteDisplay at 6f685226

int WriteDisplay(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x5226  47  WriteDisplay */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f6852c4;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f6852c4;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f6852c4;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f6852c4;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f6852c4;
    }
  }
  local_10 = 0x21;
LAB_6f6852c4:
  if (local_10 == 0) {
    if ((&DAT_6f6894e0)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f6894e0)[local_8])
                           (CONCAT22((short)DAT_6f6881a0 >> 0xf,param_1) & 0xffff1fff,param_2);
    }
  }
  return local_10;
}



// Function: InitDisplay at 6f685301

int InitDisplay(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x5301  10  InitDisplay */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f68539f;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      goto LAB_6f68539f;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f68539f;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f68539f;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f68539f;
    }
  }
  local_10 = 0x21;
LAB_6f68539f:
  if (local_10 == 0) {
    if ((&DAT_6f6894d0)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f6894d0)[local_8])
                           (CONCAT22((short)DAT_6f6881a0 >> 0xf,param_1) & 0xffff1fff,param_2);
    }
  }
  return local_10;
}



// Function: SendBuffer at 6f6853dc

int SendBuffer(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x53dc  28  SendBuffer */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f685481;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      local_10 = 0x21;
      goto LAB_6f685481;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f685481;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f685481;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f685481;
    }
  }
  local_10 = 0x21;
LAB_6f685481:
  if (local_10 == 0) {
    if ((&DAT_6f6894f0)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f6894f0)[local_8])
                           (CONCAT22((short)DAT_6f6881a0 >> 0xf,param_1) & 0xffff1fff,param_2);
    }
  }
  return local_10;
}



// Function: SetDecodeCallback at 6f6854be

int SetDecodeCallback(ushort param_1,undefined4 param_2)

{
  ushort uVar1;
  int local_10;
  short local_8;
  
                    /* 0x54be  30  SetDecodeCallback */
  local_10 = 0;
  local_8 = 0;
  uVar1 = param_1 & DAT_6f6881a0;
  if ((short)uVar1 < 1) {
    if (uVar1 == 0) {
      local_8 = 0;
      goto LAB_6f685563;
    }
    if (uVar1 == 0x8000) {
      local_8 = 1;
      local_10 = 0x21;
      goto LAB_6f685563;
    }
  }
  else {
    if (uVar1 == 0x1000) {
      local_8 = 2;
      local_10 = 0x21;
      goto LAB_6f685563;
    }
    if (uVar1 == 0x2000) {
      local_8 = 2;
      goto LAB_6f685563;
    }
    if (uVar1 == 0x4000) {
      local_8 = 3;
      goto LAB_6f685563;
    }
  }
  local_10 = 0x21;
LAB_6f685563:
  if (local_10 == 0) {
    if ((&DAT_6f689500)[local_8] == 0) {
      local_10 = 0x13;
    }
    else {
      local_10 = (*(code *)(&DAT_6f689500)[local_8])
                           (CONCAT22((short)DAT_6f6881a0 >> 0xf,param_1) & 0xffff1fff,param_2);
    }
  }
  return local_10;
}



// Function: SetSerialDLL at 6f6855a0

undefined4 SetSerialDLL(char *param_1)

{
                    /* 0x55a0  33  SetSerialDLL */
  strcpy(s_DPAS07_DLL_6f688010,param_1);
  return 0;
}



// Function: SetSerialHDLL at 6f6855ba

undefined4 SetSerialHDLL(char *param_1)

{
                    /* 0x55ba  34  SetSerialHDLL */
  strcpy(s_DPAH32_DLL_6f688150,param_1);
  return 0;
}



// Function: SetIsaDLL at 6f6855d4

undefined4 SetIsaDLL(char *param_1)

{
                    /* 0x55d4  32  SetIsaDLL */
  strcpy(s_DPAI32_DLL_6f688060,param_1);
  return 0;
}



// Function: SetUsbDLL at 6f6855ee

undefined4 SetUsbDLL(char *param_1)

{
                    /* 0x55ee  36  SetUsbDLL */
  strcpy(s_DPAU32_DLL_6f6880b0,param_1);
  return 0;
}



// Function: SetTcp_IpDLL at 6f685608

undefined4 SetTcp_IpDLL(char *param_1)

{
                    /* 0x5608  35  SetTcp_IpDLL */
  strcpy(s_DPAT32_DLL_6f688100,param_1);
  return 0;
}



// Function: SetINIFile at 6f685622

undefined4 SetINIFile(char *param_1)

{
                    /* 0x5622  31  SetINIFile */
  strcpy(s_DG_DPA32_ini_6f6881a8,param_1);
  return 0;
}



// Function: FUN_6f685640 at 6f685640

undefined4 __cdecl FUN_6f685640(undefined4 *param_1,LPCSTR param_2)

{
  int iVar1;
  char *pcVar2;
  undefined2 local_cc [2];
  char *local_c8;
  char local_c4 [80];
  char *local_74;
  short local_70;
  undefined2 local_6c [2];
  char *local_68;
  char local_64 [80];
  char *local_14;
  char *local_10;
  char *local_c;
  undefined2 local_8 [2];
  
  local_6c[0] = 0;
  local_8[0] = 0;
  local_70 = 0;
  sprintf(local_64,s_DPAInformation_d_6f688fc8,(int)*(short *)((int)param_1 + 0x57));
  GetPrivateProfileStringA
            (local_64,s_DPAParams_6f688fe4,s_INVALID_6f688fdc,(LPSTR)((int)param_1 + 0xf9),0x50,
             param_2);
  iVar1 = strcmp((char *)((int)param_1 + 0xf9),s_INVALID_6f688ff0);
  if (iVar1 == 0) {
    local_cc[0] = 0;
    sprintf(local_64,s_DeviceInformation_d_6f6890dc,(int)*(short *)((int)param_1 + 0x57));
    GetPrivateProfileStringA
              (local_64,s_DeviceName_6f6890fc,s_INVALID_6f6890f4,(LPSTR)((int)param_1 + 0x59),0x50,
               param_2);
    GetPrivateProfileStringA
              (local_64,s_DeviceDescription_6f689110,s_INVALID_6f689108,(LPSTR)((int)param_1 + 0xa9)
               ,0x50,param_2);
    GetPrivateProfileStringA
              (local_64,s_DeviceParams_6f68912c,s_INVALID_6f689124,(LPSTR)((int)param_1 + 0xf9),0x50
               ,param_2);
    iVar1 = strcmp((char *)((int)param_1 + 0xf9),s_INVALID_6f68913c);
    if (((iVar1 == 0) ||
        (iVar1 = strcmp((char *)((int)param_1 + 0x59),s_INVALID_6f689144), iVar1 == 0)) ||
       (iVar1 = strcmp((char *)((int)param_1 + 0xa9),s_INVALID_6f68914c), iVar1 == 0)) {
      return 0x28;
    }
    local_74 = strstr((char *)((int)param_1 + 0xf9),&DAT_6f689154);
    if (local_74 != (char *)0x0) {
      iVar1 = sscanf(local_74 + 2,&DAT_6f689158,local_cc);
      if (iVar1 == 0) {
        sprintf(local_c4,s_DPAInformation_d_6f68915c,(int)*(short *)((int)param_1 + 0x57));
        GetPrivateProfileStringA
                  (local_64,s_DPAParams_6f689188,s_INVALID_6f689180,(LPSTR)((int)param_1 + 0xf9),
                   0x50,s_DG_DPA32_ini_6f689170);
      }
      iVar1 = strcmp((char *)((int)param_1 + 0xf9),s_INVALID_6f689194);
      if (iVar1 == 0) {
        return 0x28;
      }
    }
    pcVar2 = strstr((char *)((int)param_1 + 0xa9),&DAT_6f68919c);
    if ((pcVar2 == (char *)0x0) &&
       (pcVar2 = strstr((char *)((int)param_1 + 0xf9),&DAT_6f6891a0), pcVar2 == (char *)0x0)) {
      pcVar2 = strstr((char *)((int)param_1 + 0xa9),&DAT_6f689240);
      if ((((pcVar2 == (char *)0x0) &&
           (pcVar2 = strstr((char *)((int)param_1 + 0xf9),&DAT_6f689244), pcVar2 == (char *)0x0)) &&
          (pcVar2 = strstr((char *)((int)param_1 + 0xa9),s_PC_CARD_6f689248), pcVar2 == (char *)0x0)
          ) && (pcVar2 = strstr((char *)((int)param_1 + 0xf9),s_PC_CARD_6f689250),
               pcVar2 == (char *)0x0)) {
        pcVar2 = strstr((char *)((int)param_1 + 0xa9),s_TCP_IP_6f689268);
        if ((pcVar2 != (char *)0x0) ||
           (pcVar2 = strstr((char *)((int)param_1 + 0xf9),s_TCP_IP_6f689270), pcVar2 != (char *)0x0)
           ) {
          local_c = strstr((char *)((int)param_1 + 0xf9),&DAT_6f689278);
          if (local_c == (char *)0x0) {
            return 0x28;
          }
          iVar1 = sscanf(local_c + 3,s__d__d__d__d_6f68927c,param_1 + 1,(int)param_1 + 5,
                         (int)param_1 + 6,(int)param_1 + 7);
          if (iVar1 == 0) {
            return 0x28;
          }
          local_10 = strstr((char *)((int)param_1 + 0xf9),s_PORT__6f689288);
          if (local_10 == (char *)0x0) {
            return 0x28;
          }
          iVar1 = sscanf(local_10 + 5,&DAT_6f689290,param_1 + 2);
          if (iVar1 == 0) {
            return 0x28;
          }
          *param_1 = 2;
        }
      }
      else {
        local_68 = strstr((char *)((int)param_1 + 0xf9),&DAT_6f689258);
        if (local_68 == (char *)0x0) {
          return 0x28;
        }
        iVar1 = sscanf(local_68 + 2,s__hx__c_hd_6f68925c,local_6c,local_8);
        if (iVar1 == 0) {
          return 0x28;
        }
        *param_1 = 1;
        *(undefined2 *)(param_1 + 1) = local_6c[0];
        *(undefined1 *)((int)param_1 + 6) = (undefined1)local_8[0];
      }
    }
    else {
      pcVar2 = strstr((char *)((int)param_1 + 0xa9),&DAT_6f6891a4);
      if (pcVar2 == (char *)0x0) {
        local_c8 = (char *)((int)param_1 + 0xf9);
      }
      else {
        local_c8 = (char *)((int)param_1 + 0xa9);
      }
      pcVar2 = strstr(local_c8,&DAT_6f6891a8);
      if (pcVar2 == (char *)0x0) {
        pcVar2 = strstr(local_c8,&DAT_6f6891b0);
        if (pcVar2 == (char *)0x0) {
          pcVar2 = strstr(local_c8,&DAT_6f6891b8);
          if (pcVar2 == (char *)0x0) {
            pcVar2 = strstr(local_c8,&DAT_6f6891c0);
            if (pcVar2 == (char *)0x0) {
              pcVar2 = strstr(local_c8,&DAT_6f6891c8);
              if (pcVar2 == (char *)0x0) {
                pcVar2 = strstr(local_c8,&DAT_6f6891d0);
                if (pcVar2 == (char *)0x0) {
                  pcVar2 = strstr(local_c8,&DAT_6f6891d8);
                  if (pcVar2 == (char *)0x0) {
                    pcVar2 = strstr(local_c8,&DAT_6f6891e0);
                    if (pcVar2 == (char *)0x0) {
                      pcVar2 = strstr(local_c8,&DAT_6f6891e8);
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
      pcVar2 = strstr((char *)((int)param_1 + 0xa9),&DAT_6f6891f0);
      if ((pcVar2 == (char *)0x0) &&
         (pcVar2 = strstr((char *)((int)param_1 + 0xa9),&DAT_6f6891f4), pcVar2 == (char *)0x0)) {
        *param_1 = 0;
      }
      else {
        *param_1 = 4;
      }
      pcVar2 = strstr((char *)((int)param_1 + 0xf9),s_B9600_6f6891f8);
      if (pcVar2 == (char *)0x0) {
        pcVar2 = strstr((char *)((int)param_1 + 0xf9),s_B19200_6f689200);
        if (pcVar2 == (char *)0x0) {
          pcVar2 = strstr((char *)((int)param_1 + 0xf9),s_B28800_6f689208);
          if (pcVar2 == (char *)0x0) {
            pcVar2 = strstr((char *)((int)param_1 + 0xf9),s_B38400_6f689210);
            if (pcVar2 == (char *)0x0) {
              pcVar2 = strstr((char *)((int)param_1 + 0xf9),s_B57600_6f689218);
              if (pcVar2 == (char *)0x0) {
                pcVar2 = strstr((char *)((int)param_1 + 0xf9),s_B115200_6f689220);
                if (pcVar2 == (char *)0x0) {
                  pcVar2 = strstr((char *)((int)param_1 + 0xf9),s_B230400_6f689228);
                  if (pcVar2 == (char *)0x0) {
                    pcVar2 = strstr((char *)((int)param_1 + 0xf9),s_B460800_6f689230);
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
      pcVar2 = strstr((char *)((int)param_1 + 0xf9),&DAT_6f689238);
      if (pcVar2 == (char *)0x0) {
        *(undefined1 *)((int)param_1 + 6) = 0;
      }
      else {
        *(undefined1 *)((int)param_1 + 6) = 1;
      }
    }
  }
  else {
    pcVar2 = strstr((char *)((int)param_1 + 0xf9),&DAT_6f688ff8);
    if (pcVar2 == (char *)0x0) {
      pcVar2 = strstr((char *)((int)param_1 + 0xf9),&DAT_6f68909c);
      if ((pcVar2 == (char *)0x0) &&
         (pcVar2 = strstr((char *)((int)param_1 + 0xf9),s_PC_CARD_6f6890a0), pcVar2 == (char *)0x0))
      {
        pcVar2 = strstr((char *)((int)param_1 + 0xf9),s_TCP_IP_6f6890b8);
        if (pcVar2 != (char *)0x0) {
          local_c = strstr((char *)((int)param_1 + 0xf9),&DAT_6f6890c0);
          if (local_c == (char *)0x0) {
            return 0x28;
          }
          iVar1 = sscanf(local_c + 3,s__d__d__d__d_6f6890c4,param_1 + 1,(int)param_1 + 5,
                         (int)param_1 + 6,(int)param_1 + 7);
          if (iVar1 == 0) {
            return 0x28;
          }
          local_10 = strstr((char *)((int)param_1 + 0xf9),s_PORT__6f6890d0);
          if (local_10 == (char *)0x0) {
            return 0x28;
          }
          iVar1 = sscanf(local_10 + 5,&DAT_6f6890d8,param_1 + 2);
          if (iVar1 == 0) {
            return 0x28;
          }
          *param_1 = 2;
        }
      }
      else {
        local_68 = strstr((char *)((int)param_1 + 0xf9),&DAT_6f6890a8);
        if (local_68 == (char *)0x0) {
          return 0x28;
        }
        iVar1 = sscanf(local_68 + 2,s__hx__c_hd_6f6890ac,local_6c,local_8);
        if (iVar1 == 0) {
          return 0x28;
        }
        *param_1 = 1;
        *(undefined2 *)(param_1 + 1) = local_6c[0];
        *(undefined1 *)((int)param_1 + 6) = (undefined1)local_8[0];
      }
    }
    else {
      pcVar2 = strstr((char *)((int)param_1 + 0xf9),&DAT_6f688ffc);
      if (pcVar2 == (char *)0x0) {
        pcVar2 = strstr((char *)((int)param_1 + 0xf9),&DAT_6f689004);
        if (pcVar2 == (char *)0x0) {
          pcVar2 = strstr((char *)((int)param_1 + 0xf9),&DAT_6f68900c);
          if (pcVar2 == (char *)0x0) {
            pcVar2 = strstr((char *)((int)param_1 + 0xf9),&DAT_6f689014);
            if (pcVar2 == (char *)0x0) {
              pcVar2 = strstr((char *)((int)param_1 + 0xf9),&DAT_6f68901c);
              if (pcVar2 == (char *)0x0) {
                pcVar2 = strstr((char *)((int)param_1 + 0xf9),&DAT_6f689024);
                if (pcVar2 == (char *)0x0) {
                  pcVar2 = strstr((char *)((int)param_1 + 0xf9),&DAT_6f68902c);
                  if (pcVar2 == (char *)0x0) {
                    pcVar2 = strstr((char *)((int)param_1 + 0xf9),&DAT_6f689034);
                    if (pcVar2 == (char *)0x0) {
                      pcVar2 = strstr((char *)((int)param_1 + 0xf9),&DAT_6f68903c);
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
      pcVar2 = strstr((char *)((int)param_1 + 0xf9),&DAT_6f689044);
      if ((pcVar2 == (char *)0x0) &&
         (pcVar2 = strstr((char *)((int)param_1 + 0xf9),&DAT_6f689048), pcVar2 == (char *)0x0)) {
        *param_1 = 0;
      }
      else {
        *param_1 = 4;
        local_14 = strstr((char *)((int)param_1 + 0xf9),s_Modem_6f68904c);
        if (local_14 != (char *)0x0) {
          for (local_70 = 0;
              (((local_14[local_70] != 0x2f72 && (local_14[local_70] != ',')) &&
               (local_14[local_70] != '\0')) && (local_70 < 0x50)); local_70 = local_70 + 1) {
            *(char *)((int)param_1 + local_70 + 7) = local_14[local_70];
          }
        }
      }
      pcVar2 = strstr((char *)((int)param_1 + 0xf9),s_B9600_6f689054);
      if (pcVar2 == (char *)0x0) {
        pcVar2 = strstr((char *)((int)param_1 + 0xf9),s_B19200_6f68905c);
        if (pcVar2 == (char *)0x0) {
          pcVar2 = strstr((char *)((int)param_1 + 0xf9),s_B28800_6f689064);
          if (pcVar2 == (char *)0x0) {
            pcVar2 = strstr((char *)((int)param_1 + 0xf9),s_B38400_6f68906c);
            if (pcVar2 == (char *)0x0) {
              pcVar2 = strstr((char *)((int)param_1 + 0xf9),s_B57600_6f689074);
              if (pcVar2 == (char *)0x0) {
                pcVar2 = strstr((char *)((int)param_1 + 0xf9),s_B115200_6f68907c);
                if (pcVar2 == (char *)0x0) {
                  pcVar2 = strstr((char *)((int)param_1 + 0xf9),s_B230400_6f689084);
                  if (pcVar2 == (char *)0x0) {
                    pcVar2 = strstr((char *)((int)param_1 + 0xf9),s_B460800_6f68908c);
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
      pcVar2 = strstr((char *)((int)param_1 + 0xf9),&DAT_6f689094);
      if (pcVar2 == (char *)0x0) {
        *(undefined1 *)((int)param_1 + 6) = 0;
      }
      else {
        *(undefined1 *)((int)param_1 + 6) = 1;
      }
    }
  }
  return 0;
}



// Function: FUN_6f686320 at 6f686320

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_6f686320(undefined4 param_1,int param_2)

{
  undefined4 *_Memory;
  undefined4 *puVar1;
  
  if (param_2 == 0) {
    if (DAT_6f689534 < 1) {
      return 0;
    }
    DAT_6f689534 = DAT_6f689534 + -1;
  }
  _DAT_6f689538 = *(undefined4 *)_adjust_fdiv_exref;
  if (param_2 == 1) {
    DAT_6f689540 = (undefined4 *)malloc(0x80);
    if (DAT_6f689540 == (undefined4 *)0x0) {
      return 0;
    }
    *DAT_6f689540 = 0;
    DAT_6f68953c = DAT_6f689540;
    initterm(&DAT_6f688000,&DAT_6f688004);
    DAT_6f689534 = DAT_6f689534 + 1;
    return 1;
  }
  if ((param_2 == 0) && (DAT_6f689540 != (undefined4 *)0x0)) {
    puVar1 = DAT_6f68953c + -1;
    _Memory = DAT_6f689540;
    if (DAT_6f689540 <= puVar1) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
          _Memory = DAT_6f689540;
        }
        puVar1 = puVar1 + -1;
      } while (_Memory <= puVar1);
    }
    free(_Memory);
    DAT_6f689540 = (undefined4 *)0x0;
  }
  return 1;
}



// Function: entry at 6f6863f0

int entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 1;
  if ((param_2 == 0) && (DAT_6f689534 == 0)) {
    return 0;
  }
  if ((param_2 != 1) && (param_2 != 2)) {
LAB_6f68644e:
    iVar1 = FUN_6f6864b0(param_1,param_2);
    if ((param_2 == 1) && (iVar1 == 0)) {
      FUN_6f686320(param_1,0);
    }
    if ((param_2 == 0) || (param_2 == 3)) {
      iVar2 = FUN_6f686320(param_1,param_2);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      if ((iVar1 != 0) && (DAT_6f689544 != (code *)0x0)) {
        iVar1 = (*DAT_6f689544)(param_1,param_2,param_3);
      }
    }
    return iVar1;
  }
  if (DAT_6f689544 != (code *)0x0) {
    iVar1 = (*DAT_6f689544)(param_1,param_2,param_3);
  }
  if (iVar1 != 0) {
    iVar1 = FUN_6f686320(param_1,param_2);
    if (iVar1 != 0) goto LAB_6f68644e;
  }
  return 0;
}



// Function: FUN_6f6864b0 at 6f6864b0

undefined4 FUN_6f6864b0(HMODULE param_1,int param_2)

{
  if ((param_2 == 1) && (DAT_6f689544 == 0)) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



