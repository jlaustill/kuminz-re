/*
 * Decompiled from: dpas07.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_6f6a1000 at 6f6a1000

/* WARNING: Type propagation algorithm not settling */

undefined4 __cdecl FUN_6f6a1000(int param_1)

{
  DWORD local_a0 [2];
  _OSVERSIONINFOA local_98;
  
  local_a0[1] = 0x87;
  memset(&local_98,0,0x94);
  local_98.dwOSVersionInfoSize = 0x94;
  GetVersionExA(&local_98);
  if (((local_98.dwPlatformId == 2) && (local_98.dwMajorVersion == 5)) &&
     (local_98.dwMinorVersion != 0)) {
    local_a0[0] = 4;
    DeviceIoControl(*(HANDLE *)(param_1 + 0x53),0x1b009c,local_a0 + 1,4,(LPVOID)0x0,0,local_a0,
                    (LPOVERLAPPED)(param_1 + 0x5f));
  }
  return 0;
}



// Function: FUN_6f6a10d0 at 6f6a10d0

void FUN_6f6a10d0(void)

{
  FUN_6f6a10df();
  FUN_6f6a10ef();
  return;
}



// Function: FUN_6f6a10df at 6f6a10df

void FUN_6f6a10df(void)

{
  std::ios_base::Init::Init((Init *)&DAT_6f6ac198);
  return;
}



// Function: FUN_6f6a10ef at 6f6a10ef

void FUN_6f6a10ef(void)

{
  FUN_6f6aa6c0(FUN_6f6a1101);
  return;
}



// Function: FUN_6f6a1101 at 6f6a1101

void FUN_6f6a1101(void)

{
  std::ios_base::Init::~Init((Init *)&DAT_6f6ac198);
  return;
}



// Function: FUN_6f6a1111 at 6f6a1111

void FUN_6f6a1111(void)

{
  FUN_6f6a1120();
  FUN_6f6a1130();
  return;
}



// Function: FUN_6f6a1120 at 6f6a1120

void FUN_6f6a1120(void)

{
  std::_Winit::_Winit((_Winit *)&DAT_6f6ac194);
  return;
}



// Function: FUN_6f6a1130 at 6f6a1130

void FUN_6f6a1130(void)

{
  FUN_6f6aa6c0(FUN_6f6a1142);
  return;
}



// Function: FUN_6f6a1142 at 6f6a1142

void FUN_6f6a1142(void)

{
  std::_Winit::~_Winit((_Winit *)&DAT_6f6ac194);
  return;
}



// Function: FUN_6f6a1160 at 6f6a1160

void __cdecl FUN_6f6a1160(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = param_2[3];
  param_1[1] = param_2[2];
  param_1[2] = param_2[1];
  param_1[3] = *param_2;
  return;
}



// Function: FUN_6f6a1193 at 6f6a1193

void __cdecl FUN_6f6a1193(ushort *param_1)

{
  char cVar1;
  ushort uVar2;
  
  cVar1 = '\0';
  *(ushort *)((int)param_1 + 0xb) = *param_1 - 2;
  for (uVar2 = 0; uVar2 < *param_1; uVar2 = uVar2 + 1) {
    cVar1 = cVar1 + *(char *)((int)param_1 + uVar2 + 10);
  }
  *(char *)((int)param_1 + uVar2 + 10) = -cVar1;
  *param_1 = *param_1 + 1;
  return;
}



// Function: FUN_6f6a1230 at 6f6a1230

void __cdecl FUN_6f6a1230(int param_1,ushort *param_2)

{
  int iVar1;
  ushort uVar2;
  size_t local_3c;
  short local_38;
  short local_34;
  short local_30;
  short local_2c;
  uint local_8;
  
  uVar2 = param_2[5];
  if (*(int *)(param_1 + 0x333ac) != 0) {
    (**(code **)(param_1 + 0x333ac))(param_2);
  }
  if ((uVar2 & 0xc0) == 0xc0) {
    if ((param_2[7] & 0x80) == 0) {
      switch(*(undefined1 *)((int)param_2 + 0xd)) {
      case 1:
        *(undefined2 *)(param_1 + 0x3333e) = 1;
        break;
      case 4:
        *(undefined2 *)(param_1 + 0x33358) = 1;
        break;
      case 6:
      case 7:
        *(undefined2 *)(param_1 + 0x3335c) = 1;
        break;
      case 10:
        *(undefined2 *)(param_1 + 0x33342) = 1;
        break;
      case 0xb:
        *(undefined2 *)(param_1 + 0x33346) = 1;
        break;
      case 0x12:
        *(undefined2 *)(param_1 + 0x33360) = 1;
        break;
      case 0x13:
        *(undefined2 *)(param_1 + 0x33364) = 1;
        break;
      case 0x14:
        *(undefined2 *)(param_1 + 0x33368) = 1;
        break;
      case 0x15:
        *(undefined2 *)(param_1 + 0x3337e) = 1;
        break;
      case 0x16:
        *(undefined2 *)(param_1 + 0x3336c) = 1;
        break;
      case 0x17:
        *(undefined2 *)(param_1 + 0x33370) = 1;
        break;
      case 0x20:
        *(undefined2 *)(param_1 + 0x3332e) = 1;
        break;
      case 0x21:
        *(undefined2 *)(param_1 + 0x33390) = 1;
        break;
      case 0x22:
        *(undefined2 *)(param_1 + 0x33394) = 1;
        break;
      case 0x23:
        *(undefined2 *)(param_1 + 0x33394) = 1;
        break;
      case 0x24:
        *(undefined2 *)(param_1 + 0x33398) = 1;
        break;
      case 0x25:
        *(undefined2 *)(param_1 + 0x33398) = 1;
        break;
      case 0x30:
        *(undefined2 *)(param_1 + 0x33334) = 1;
        break;
      case 0x31:
        *(undefined2 *)(param_1 + 0x3333a) = 1;
        break;
      case 0x32:
        *(undefined2 *)(param_1 + 0x33374) = 1;
      case 0x40:
        *(undefined2 *)(param_1 + 0x33388) = 1;
        break;
      case 0x42:
      case 0x43:
        *(ushort *)(param_1 + 0x33350) = (ushort)(byte)param_2[7];
        *(ushort *)(param_1 + 0x33352) = (ushort)(byte)param_2[7];
        *(undefined2 *)(param_1 + 0x3334c) = 1;
        break;
      case 0x48:
        *(undefined2 *)(param_1 + 0x3338c) = 1;
        break;
      case 0x49:
        *(undefined2 *)(param_1 + 0x33354) = 1;
      }
    }
    else {
      switch(*(undefined1 *)((int)param_2 + 0xd)) {
      case 1:
        *(undefined2 *)(param_1 + 0x33340) = 1;
        break;
      case 4:
        *(undefined2 *)(param_1 + 0x3335a) = 1;
        break;
      case 6:
      case 7:
        *(undefined2 *)(param_1 + 0x3335e) = 1;
        break;
      case 10:
        *(undefined2 *)(param_1 + 0x33344) = 1;
        break;
      case 0xb:
        *(undefined2 *)(param_1 + 0x33348) = 1;
        break;
      case 0x12:
        *(undefined2 *)(param_1 + 0x33362) = 1;
        break;
      case 0x13:
        *(undefined2 *)(param_1 + 0x33366) = 1;
        break;
      case 0x14:
        *(undefined2 *)(param_1 + 0x3336a) = 1;
        break;
      case 0x15:
        *(undefined2 *)(param_1 + 0x33380) = 1;
        break;
      case 0x16:
        *(undefined2 *)(param_1 + 0x3336e) = 1;
        break;
      case 0x17:
        *(undefined2 *)(param_1 + 0x33372) = 1;
        break;
      case 0x20:
        *(undefined2 *)(param_1 + 0x33330) = 1;
        break;
      case 0x21:
        *(undefined2 *)(param_1 + 0x33392) = 1;
        break;
      case 0x22:
        *(undefined2 *)(param_1 + 0x33396) = 1;
        break;
      case 0x23:
        *(undefined2 *)(param_1 + 0x33396) = 1;
        break;
      case 0x30:
        *(undefined2 *)(param_1 + 0x33336) = 1;
        break;
      case 0x32:
        *(undefined2 *)(param_1 + 0x33376) = 1;
      case 0x40:
        *(undefined2 *)(param_1 + 0x3338a) = 1;
        break;
      case 0x42:
      case 0x43:
        *(undefined2 *)(param_1 + 0x33350) = 0xff;
        *(undefined2 *)(param_1 + 0x33352) = 0xff;
        *(undefined2 *)(param_1 + 0x3334e) = 1;
        break;
      case 0x48:
        *(undefined2 *)(param_1 + 0x3338e) = 1;
        break;
      case 0x49:
        *(undefined2 *)(param_1 + 0x33356) = 1;
      }
    }
    DAT_6f6ac1d0 = 1;
    SetEvent(*(HANDLE *)(param_1 + 0x3331a));
  }
  else if ((uVar2 & 0xc0) == 0x80) {
    switch(*(undefined1 *)((int)param_2 + 0xd)) {
    case 1:
      if (*(int *)(param_1 + 0x319ed) != 0) {
        (**(code **)(param_1 + 0x319ed))(0,param_2 + 7);
      }
      break;
    case 4:
      uVar2 = param_2[7];
      if ((int)(uVar2 & 0xff00) >> 8 != (int)*(short *)(param_1 + 0x33352)) {
        if ((uVar2 & 0xff) == 3) {
          if (((uint)((int)(uVar2 & 0xff00) >> 8) < 0x10) &&
             (iVar1 = param_1 + 9 + ((int)(uVar2 & 0xff00) >> 8) * 0x845,
             *(char *)(iVar1 + 1) != '\0')) {
            local_8 = 6;
            if ((*(char *)(iVar1 + 0x82c) == '\0') || (*(char *)(iVar1 + 0x83a) != '\0')) {
              memcpy((void *)(iVar1 + 0x1b),param_2 + 8,4);
              local_8 = 10;
            }
            if ((*(char *)(iVar1 + 0x82d) == '\0') || (*(char *)(iVar1 + 0x83a) != '\0')) {
              FUN_6f6a1160((undefined1 *)(iVar1 + 6),(undefined1 *)((int)param_2 + local_8 + 10));
              if (*(char *)(iVar1 + 2) == '\x1d') {
                *(uint *)(iVar1 + 6) = *(uint *)(iVar1 + 6) >> 3;
              }
              else {
                *(uint *)(iVar1 + 6) = *(uint *)(iVar1 + 6) >> 0x15;
              }
              local_8 = (uint)(byte)((char)local_8 + 4);
            }
            if ((*(char *)(iVar1 + 0x82e) == '\0') || (*(char *)(iVar1 + 0x83a) != '\0')) {
              memcpy((void *)(iVar1 + 0x29),(void *)((int)param_2 + local_8 + 10),2);
              if (((*(char *)(iVar1 + 0x82f) == '\0') || (*(char *)(iVar1 + 0x83a) != '\0')) &&
                 (*(ushort *)(iVar1 + 0x29) < 0x7d1)) {
                memcpy((void *)(iVar1 + 0x2b),
                       (void *)((int)param_2 + (byte)((char)local_8 + 2) + 10),
                       (uint)*(ushort *)(iVar1 + 0x29));
              }
            }
            else if ((*(char *)(iVar1 + 0x82f) == '\0') || (*(char *)(iVar1 + 0x83a) != '\0')) {
              if (*(ushort *)(iVar1 + 0x29) < 2000) {
                if ((int)((*param_2 - local_8) + -1) < 0x801) {
                  local_2c = (*param_2 - (short)local_8) + -1;
                }
                else {
                  local_2c = 0x800;
                }
                *(short *)(iVar1 + 0x29) = local_2c;
                memcpy((void *)(iVar1 + 0x2b),(void *)((int)param_2 + local_8 + 10),
                       (uint)*(ushort *)(iVar1 + 0x29));
              }
              else {
                *(undefined2 *)(iVar1 + 0x29) = 0;
              }
            }
            else {
              *(undefined2 *)(iVar1 + 0x29) = 0;
            }
            if ((*(char *)(iVar1 + 0x82b) != '\0') && (*(int *)(iVar1 + 0x83d) != 0)) {
              memcpy(*(void **)(iVar1 + 0x83d),(void *)(iVar1 + 0x2b),
                     (uint)*(ushort *)(iVar1 + 0x29));
            }
            if (*(int *)(iVar1 + 0x13) != 0) {
              (**(code **)(iVar1 + 0x13))(iVar1);
            }
            *(undefined1 *)(iVar1 + 0x83c) = 1;
            SetEvent(*(HANDLE *)(param_1 + 0x33326));
          }
        }
        else if ((uVar2 & 0xff) == 2) {
          if (((uint)((int)(uVar2 & 0xff00) >> 8) < 0x10) &&
             (iVar1 = param_1 + 0x21149 + ((int)(uVar2 & 0xff00) >> 8) * 0x845,
             *(char *)(iVar1 + 1) != '\0')) {
            local_8 = 6;
            if ((*(char *)(iVar1 + 0x82c) == '\0') || (*(char *)(iVar1 + 0x83a) != '\0')) {
              memcpy((void *)(iVar1 + 0x1b),param_2 + 8,4);
              local_8 = 10;
            }
            if ((*(char *)(iVar1 + 0x82d) == '\0') || (*(char *)(iVar1 + 0x83a) != '\0')) {
              *(undefined4 *)(iVar1 + 6) = *(undefined4 *)((int)param_2 + local_8 + 10);
              local_8 = (uint)(byte)((char)local_8 + 4);
            }
            if ((*(char *)(iVar1 + 0x82e) == '\0') || (*(char *)(iVar1 + 0x83a) != '\0')) {
              memcpy((void *)(iVar1 + 0x29),(void *)((int)param_2 + local_8 + 10),2);
              if (((*(char *)(iVar1 + 0x82f) == '\0') || (*(char *)(iVar1 + 0x83a) != '\0')) &&
                 (*(ushort *)(iVar1 + 0x29) < 0x7d1)) {
                memcpy((void *)(iVar1 + 0x2b),
                       (void *)((int)param_2 + (byte)((char)local_8 + 2) + 10),
                       (uint)*(ushort *)(iVar1 + 0x29));
              }
            }
            else if ((*(char *)(iVar1 + 0x82f) == '\0') || (*(char *)(iVar1 + 0x83a) != '\0')) {
              if (*(ushort *)(iVar1 + 0x29) < 2000) {
                if ((int)((*param_2 - local_8) + -1) < 0x801) {
                  local_30 = (*param_2 - (short)local_8) + -1;
                }
                else {
                  local_30 = 0x800;
                }
                *(short *)(iVar1 + 0x29) = local_30;
                memcpy((void *)(iVar1 + 0x2b),(void *)((int)param_2 + local_8 + 10),
                       (uint)*(ushort *)(iVar1 + 0x29));
              }
              else {
                *(undefined2 *)(iVar1 + 0x29) = 0;
              }
            }
            else {
              *(undefined2 *)(iVar1 + 0x29) = 0;
            }
            if ((*(char *)(iVar1 + 0x82b) != '\0') && (*(int *)(iVar1 + 0x83d) != 0)) {
              memcpy(*(void **)(iVar1 + 0x83d),(void *)(iVar1 + 0x2b),
                     (uint)*(ushort *)(iVar1 + 0x29));
            }
            if (*(int *)(iVar1 + 0x13) != 0) {
              (**(code **)(iVar1 + 0x13))(iVar1);
            }
            *(undefined1 *)(iVar1 + 0x83c) = 1;
            SetEvent(*(HANDLE *)(param_1 + 0x33326));
          }
        }
        else if ((((uVar2 & 0xff) == 1) && ((uint)((int)(uVar2 & 0xff00) >> 8) < 0x10)) &&
                (iVar1 = param_1 + 0x108a9 + ((int)(uVar2 & 0xff00) >> 8) * 0x845,
                *(char *)(iVar1 + 1) != '\0')) {
          local_8 = 6;
          if ((*(char *)(iVar1 + 0x82c) == '\0') || (*(char *)(iVar1 + 0x83a) != '\0')) {
            memcpy((void *)(iVar1 + 0x1b),param_2 + 8,4);
            local_8 = 10;
          }
          if ((*(char *)(iVar1 + 0x82d) == '\0') || (*(char *)(iVar1 + 0x83a) != '\0')) {
            *(undefined1 *)(iVar1 + 0x833) = *(undefined1 *)((int)param_2 + local_8 + 10);
            local_8 = (uint)(byte)((char)local_8 + 1);
          }
          if ((*(char *)(iVar1 + 0x82d) == '\0') || (*(char *)(iVar1 + 0x83a) != '\0')) {
            *(undefined1 *)(iVar1 + 0x834) = *(undefined1 *)((int)param_2 + local_8 + 10);
            local_8 = (uint)(byte)((char)local_8 + 1);
          }
          if ((*(char *)(iVar1 + 0x82e) == '\0') || (*(char *)(iVar1 + 0x83a) != '\0')) {
            memcpy((void *)(iVar1 + 0x29),(void *)((int)param_2 + local_8 + 10),2);
            if ((*(char *)(iVar1 + 0x82f) == '\0') || (*(char *)(iVar1 + 0x83a) != '\0')) {
              memcpy((void *)(iVar1 + 0x2b),(void *)((int)param_2 + (byte)((char)local_8 + 2) + 10),
                     (uint)*(ushort *)(iVar1 + 0x29));
            }
          }
          else if ((*(char *)(iVar1 + 0x82f) == '\0') || (*(char *)(iVar1 + 0x83a) != '\0')) {
            if ((int)((*param_2 - local_8) + -1) < 0x801) {
              local_34 = (*param_2 - (short)local_8) + -1;
            }
            else {
              local_34 = 0x800;
            }
            *(short *)(iVar1 + 0x29) = local_34;
            memcpy((void *)(iVar1 + 0x2b),(void *)((int)param_2 + local_8 + 10),
                   (uint)*(ushort *)(iVar1 + 0x29));
          }
          else {
            *(undefined2 *)(iVar1 + 0x29) = 0;
          }
          if ((*(char *)(iVar1 + 0x82b) != '\0') && (*(int *)(iVar1 + 0x83d) != 0)) {
            memcpy(*(void **)(iVar1 + 0x83d),(void *)(iVar1 + 0x2b),(uint)*(ushort *)(iVar1 + 0x29))
            ;
          }
          if (*(int *)(iVar1 + 0x13) != 0) {
            (**(code **)(iVar1 + 0x13))(iVar1);
          }
          *(undefined1 *)(iVar1 + 0x83c) = 1;
          SetEvent(*(HANDLE *)(param_1 + 0x33326));
        }
      }
      break;
    case 0xb:
      if (param_2[8] < 0x801) {
        local_3c = (size_t)param_2[8];
      }
      else {
        local_3c = 0x800;
      }
      memcpy((void *)(param_1 + 0x32a95),param_2 + 9,local_3c);
      *(undefined2 *)(param_1 + 0x3334a) = 1;
      SetEvent(*(HANDLE *)(param_1 + 0x33312));
      break;
    case 0xc:
      uVar2 = param_2[7];
      if (((((uVar2 & 0xff) != 3) && ((uVar2 & 0xff) == 1)) &&
          ((uint)((int)(uVar2 & 0xff00) >> 8) < 0x10)) &&
         (iVar1 = param_1 + 0x108a9 + ((int)(uVar2 & 0xff00) >> 8) * 0x845,
         *(char *)(iVar1 + 1) != '\0')) {
        local_8 = 6;
        if ((*(byte *)(iVar1 + 0x83b) & 4) == 4) {
          memcpy((void *)(iVar1 + 0x1b),param_2 + 8,4);
          local_8 = 10;
        }
        if ((*(byte *)(iVar1 + 0x83b) & 2) == 2) {
          *(undefined1 *)(iVar1 + 0x833) = *(undefined1 *)((int)param_2 + local_8 + 10);
          local_8 = (uint)(byte)((char)local_8 + 1);
        }
        if ((*(byte *)(iVar1 + 0x83b) & 2) == 2) {
          *(undefined1 *)(iVar1 + 0x834) = *(undefined1 *)((int)param_2 + local_8 + 10);
          local_8 = (uint)(byte)((char)local_8 + 1);
        }
        if ((*(byte *)(iVar1 + 0x83b) & 0x80) == 0x80) {
          memcpy((void *)(iVar1 + 0x838),(void *)((int)param_2 + local_8 + 10),2);
          local_8 = (uint)(byte)((char)local_8 + 2);
        }
        if ((*(byte *)(iVar1 + 0x83b) & 0x20) == 0x20) {
          memcpy((void *)(iVar1 + 0x29),(void *)((int)param_2 + local_8 + 10),2);
          local_8 = (uint)(byte)((char)local_8 + 2);
        }
        if ((*(byte *)(iVar1 + 0x83b) & 1) == 1) {
          if ((int)((*param_2 - local_8) + -1) < 0x801) {
            local_38 = (*param_2 - (short)local_8) + -1;
          }
          else {
            local_38 = 0x800;
          }
          *(short *)(iVar1 + 0x29) = local_38;
          memcpy((void *)(iVar1 + 0x2b),(void *)((int)param_2 + local_8 + 10),
                 (uint)*(ushort *)(iVar1 + 0x29));
          if ((*(char *)(iVar1 + 0x82b) != '\0') && (*(int *)(iVar1 + 0x83d) != 0)) {
            memcpy(*(void **)(iVar1 + 0x83d),(void *)(iVar1 + 0x2b),(uint)*(ushort *)(iVar1 + 0x29))
            ;
          }
        }
        *(undefined1 *)(iVar1 + 0x83c) = 1;
        SetEvent(*(HANDLE *)(param_1 + 0x33326));
      }
      break;
    case 0x13:
      if (*(int *)(param_1 + 0x319e9) != 0) {
        (**(code **)(param_1 + 0x319e9))(*(undefined4 *)(param_2 + 7));
      }
      break;
    case 0x15:
      *(undefined4 *)(param_1 + 0x33384) = *(undefined4 *)(param_2 + 7);
      *(undefined2 *)(param_1 + 0x33382) = 1;
      SetEvent(*(HANDLE *)(param_1 + 0x33322));
      break;
    case 0x20:
      strcpy((char *)(param_1 + 0x32a1d),(char *)(param_2 + 7));
      *(undefined2 *)(param_1 + 0x33332) = 1;
      SetEvent(*(HANDLE *)(param_1 + 0x33316));
      break;
    case 0x21:
      uVar2 = param_2[7];
      if ((uVar2 & 0xff) == 3) {
        if ((uint)((int)(uVar2 & 0xff00) >> 8) < 0x10) {
          iVar1 = param_1 + 0x8459 + ((int)(uVar2 & 0xff00) >> 8) * 0x845;
          *(undefined1 *)(iVar1 + 1) = 0;
          if (*(int *)(iVar1 + 0x17) != 0) {
            (**(code **)(iVar1 + 0x17))(iVar1);
          }
        }
      }
      else if ((uVar2 & 0xff) == 1) {
        if ((uint)((int)(uVar2 & 0xff00) >> 8) < 0x10) {
          iVar1 = param_1 + 0x18cf9 + ((int)(uVar2 & 0xff00) >> 8) * 0x845;
          *(undefined1 *)(iVar1 + 1) = 0;
          if (*(int *)(iVar1 + 0x17) != 0) {
            (**(code **)(iVar1 + 0x17))(iVar1);
          }
        }
      }
      else if (((uVar2 & 0xff) == 2) && ((uint)((int)(uVar2 & 0xff00) >> 8) < 0x10)) {
        iVar1 = param_1 + 0x29599 + ((int)(uVar2 & 0xff00) >> 8) * 0x845;
        *(undefined1 *)(iVar1 + 1) = 0;
        if (*(int *)(iVar1 + 0x17) != 0) {
          (**(code **)(iVar1 + 0x17))(iVar1);
        }
      }
      break;
    case 0x22:
      uVar2 = param_2[7];
      if ((int)(uVar2 & 0xff00) >> 8 == (int)*(short *)(param_1 + 0x33352)) {
        WaitForSingleObject(*(HANDLE *)(param_1 + 0x3332a),0xfa);
      }
      if (((uVar2 & 0xff) == 3) && ((uint)((int)(uVar2 & 0xff00) >> 8) < 0x10)) {
        iVar1 = param_1 + 0x8459 + ((int)(uVar2 & 0xff00) >> 8) * 0x845;
        if (*(char *)(iVar1 + 0x82c) == '\0') {
          *(undefined4 *)(iVar1 + 0x1f) = *(undefined4 *)(param_2 + 8);
        }
        else {
          *(undefined4 *)(iVar1 + 0x1f) = 0;
        }
        if ((*(int *)(param_1 + 0x319f1) != 0) && (*(char *)(iVar1 + 1) != '\0')) {
          (**(code **)(param_1 + 0x319f1))(iVar1);
        }
        if (*(int *)(iVar1 + 0x13) != 0) {
          (**(code **)(iVar1 + 0x13))(iVar1);
        }
      }
      if ((uVar2 & 0xff) == 2) {
        if ((uint)((int)(uVar2 & 0xff00) >> 8) < 0x10) {
          iVar1 = param_1 + 0x29599 + ((int)(uVar2 & 0xff00) >> 8) * 0x845;
          if (*(char *)(iVar1 + 0x82c) == '\0') {
            *(undefined4 *)(iVar1 + 0x1f) = *(undefined4 *)(param_2 + 8);
          }
          else {
            *(undefined4 *)(iVar1 + 0x1f) = 0;
          }
          if ((*(int *)(param_1 + 0x31a01) != 0) && (*(char *)(iVar1 + 1) != '\0')) {
            (**(code **)(param_1 + 0x31a01))(iVar1);
          }
          if (*(int *)(iVar1 + 0x13) != 0) {
            (**(code **)(iVar1 + 0x13))(iVar1);
          }
        }
      }
      else if (((uVar2 & 0xff) == 1) && ((uint)((int)(uVar2 & 0xff00) >> 8) < 0x10)) {
        iVar1 = param_1 + 0x18cf9 + ((int)(uVar2 & 0xff00) >> 8) * 0x845;
        if (*(char *)(iVar1 + 0x82c) == '\0') {
          *(undefined4 *)(iVar1 + 0x1f) = *(undefined4 *)(param_2 + 8);
        }
        else {
          *(undefined4 *)(iVar1 + 0x1f) = 0;
        }
        if ((*(int *)(param_1 + 0x319f9) != 0) && (*(char *)(iVar1 + 1) != '\0')) {
          (**(code **)(param_1 + 0x319f9))(iVar1);
        }
        if (*(int *)(iVar1 + 0x13) != 0) {
          (**(code **)(iVar1 + 0x13))(iVar1);
        }
      }
      ReleaseMutex(*(HANDLE *)(param_1 + 0x3332a));
      break;
    case 0x24:
      if (*(int *)(param_1 + 0x333a4) != 0) {
        (**(code **)(param_1 + 0x333a4))((char)param_2[7],*(undefined4 *)(param_1 + 0x3339c));
      }
      break;
    case 0x25:
      if (*(int *)(param_1 + 0x333a8) != 0) {
        (**(code **)(param_1 + 0x333a8))((char)param_2[7],*(undefined4 *)(param_1 + 0x333a0));
      }
      break;
    case 0x30:
      strcpy((char *)(param_1 + 0x33295),(char *)(param_2 + 7));
      *(undefined2 *)(param_1 + 0x33338) = 1;
      SetEvent(*(HANDLE *)(param_1 + 0x3330e));
      break;
    case 0x32:
      *(undefined4 *)(param_1 + 0x3337a) = *(undefined4 *)(param_2 + 7);
      *(undefined2 *)(param_1 + 0x33378) = 1;
      SetEvent(*(HANDLE *)(param_1 + 0x3331e));
    }
  }
  return;
}



// Function: InitCommLink at 6f6a290a

BOOL InitCommLink(short *param_1,byte *param_2)

{
  HANDLE pvVar1;
  short *local_c;
  int local_8;
  
                    /* 0x290a  10  InitCommLink */
  local_8 = 0;
  if (param_1 == (short *)0x0) {
    local_8 = 0x22;
  }
  else {
    local_8 = FUN_6f6a8c83(&local_c);
    while (local_8 == 0) {
      if (**(byte **)(local_c + 2) == *param_2) {
        if (*(byte *)(*(int *)(local_c + 2) + 1) == param_2[1]) {
          *local_c = *local_c + 1;
          *param_1 = local_c[1];
          return 0;
        }
        return 0x23;
      }
      local_8 = FUN_6f6a8ce6(&local_c,(int)local_c);
    }
    local_c = (short *)malloc(0x333b0);
    if (local_c == (short *)0x0) {
      local_8 = 0x1f;
    }
    else {
      memset(local_c,0,0x333b0);
      local_c[0x199a9] = 0xff;
      local_8 = FUN_6f6a8e57((undefined4 *)(local_c + 2),local_c,param_2);
      if (local_8 == 0) {
        pvVar1 = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,0,(LPCSTR)0x0);
        *(HANDLE *)(local_c + 0x19995) = pvVar1;
        if (*(int *)(local_c + 0x19995) == 0) {
          GetLastError();
          local_8 = 0x1f;
        }
        else {
          pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
          *(HANDLE *)(local_c + 0x19991) = pvVar1;
          if (*(int *)(local_c + 0x19991) == 0) {
            GetLastError();
            local_8 = 0x1f;
          }
          else {
            pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
            *(HANDLE *)(local_c + 0x1998b) = pvVar1;
            if (*(int *)(local_c + 0x1998b) == 0) {
              GetLastError();
              local_8 = 0x1f;
            }
            else {
              pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
              *(HANDLE *)(local_c + 0x1998f) = pvVar1;
              if (*(int *)(local_c + 0x1998f) == 0) {
                GetLastError();
                local_8 = 0x1f;
              }
              else {
                pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
                *(HANDLE *)(local_c + 0x19993) = pvVar1;
                if (*(int *)(local_c + 0x19993) == 0) {
                  GetLastError();
                  local_8 = 0x1f;
                }
                else {
                  pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
                  *(HANDLE *)(local_c + 0x1998d) = pvVar1;
                  if (*(int *)(local_c + 0x1998d) == 0) {
                    GetLastError();
                    local_8 = 0x1f;
                  }
                  else {
                    pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
                    *(HANDLE *)(local_c + 0x19989) = pvVar1;
                    if (*(int *)(local_c + 0x19989) == 0) {
                      GetLastError();
                      local_8 = 0x1f;
                    }
                    else {
                      pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
                      *(HANDLE *)(local_c + 0x19987) = pvVar1;
                      if (*(int *)(local_c + 0x19987) == 0) {
                        GetLastError();
                        local_8 = 0x1f;
                      }
                      else {
                        local_8 = FUN_6f6a8b40(param_1,(int)local_c);
                        local_c[1] = *param_1;
                        *local_c = 1;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return local_8;
}



// Function: InitPCCard at 6f6a2bf2

undefined4 InitPCCard(void)

{
                    /* 0x2bf2  13  InitPCCard */
  return 0x25;
}



// Function: InitTCP_IP at 6f6a2bfe

undefined4 InitTCP_IP(void)

{
                    /* 0x2bfe  14  InitTCP_IP */
  return 0x25;
}



// Function: SetBaudRate at 6f6a2c0a

int SetBaudRate(short param_1,byte *param_2)

{
  undefined4 extraout_ECX;
  char local_68 [4];
  undefined1 *local_64;
  int local_60;
  int local_5c;
  undefined1 local_58 [80];
  ushort *local_8;
  
                    /* 0x2c0a  28  SetBaudRate */
  local_5c = FUN_6f6a8bed(&local_60,param_1);
  if ((local_5c == 0) && (local_5c = FUN_6f6a2d43(param_2), local_5c == 0)) {
    local_8 = (ushort *)(local_60 + 0x31a09);
    local_64 = (undefined1 *)(local_60 + 0x31a13);
    *local_64 = 0x80;
    *(undefined1 *)(local_60 + 0x31a16) = 0x21;
    if (param_2[1] == 5) {
      *(undefined1 *)(local_60 + 0x31a17) = 1;
    }
    else {
      *(undefined1 *)(local_60 + 0x31a17) = 2;
    }
    *local_8 = 5;
    *(undefined4 *)(local_60 + 0x31a0f) = 0;
    FUN_6f6a1193(local_8);
    local_5c = FUN_6f6a89d8(local_60,(short *)(local_60 + 0x33390),
                            (undefined2 *)(local_60 + 0x33392),local_8,(short *)0x0);
    if (local_5c == 0) {
      local_5c = FUN_6f6aa4fd(*(int *)(local_60 + 4),
                              CONCAT31((int3)((uint)extraout_ECX >> 8),*param_2));
      Sleep(1000);
      if ((local_5c == 0) && (local_5c = CheckDataLink(param_1,(int)local_58), local_5c != 0)) {
        local_68[0] = '\x01';
        FUN_6f6aa5b8(*(int *)(local_60 + 4),local_68);
        local_5c = 0x2a;
      }
    }
  }
  return local_5c;
}



// Function: FUN_6f6a2d43 at 6f6a2d43

undefined4 __cdecl FUN_6f6a2d43(byte *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 < 8) {
    if ((param_1[1] < 5) || (6 < param_1[1])) {
      uVar1 = 3;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 3;
  }
  return uVar1;
}



// Function: ResetDPA at 6f6a2d8c

int ResetDPA(short param_1,char *param_2)

{
  int local_c;
  int local_8;
  
                    /* 0x2d8c  23  ResetDPA */
  local_8 = 0;
  local_8 = FUN_6f6a8bed(&local_c,param_1);
  if (local_8 == 0) {
    local_8 = FUN_6f6aa5b8(*(int *)(local_c + 4),param_2);
  }
  return local_8;
}



// Function: InitTCP_IPListen at 6f6a2dd1

undefined4 InitTCP_IPListen(void)

{
                    /* 0x2dd1  1  InitTCP_IPListen */
  return 0x25;
}



// Function: RestorePCCard at 6f6a2ddd

void RestorePCCard(short param_1)

{
                    /* 0x2ddd  25  RestorePCCard */
  RestoreCommLink(param_1);
  return;
}



// Function: RestoreTCP_IP at 6f6a2dee

void RestoreTCP_IP(short param_1)

{
                    /* 0x2dee  26  RestoreTCP_IP */
  RestoreCommLink(param_1);
  return;
}



// Function: RestoreCommLink at 6f6a2dff

int RestoreCommLink(short param_1)

{
  short *local_c;
  int local_8;
  
                    /* 0x2dff  24  RestoreCommLink */
  local_8 = FUN_6f6a8bed(&local_c,param_1);
  if (local_8 == 0) {
    *local_c = *local_c + -1;
    if (*local_c < 1) {
      local_8 = FUN_6f6a8bb2(param_1);
      if (local_8 == 0) {
        FUN_6f6aa222(*(void **)(local_c + 2));
        if (*(int *)(local_c + 0x19995) != 0) {
          CloseHandle(*(HANDLE *)(local_c + 0x19995));
          local_c[0x19995] = 0;
          local_c[0x19996] = 0;
        }
        if (*(int *)(local_c + 0x1998b) != 0) {
          CloseHandle(*(HANDLE *)(local_c + 0x1998b));
          local_c[0x1998b] = 0;
          local_c[0x1998c] = 0;
        }
        if (*(int *)(local_c + 0x1998f) != 0) {
          CloseHandle(*(HANDLE *)(local_c + 0x1998f));
          local_c[0x1998f] = 0;
          local_c[0x19990] = 0;
        }
        if (*(int *)(local_c + 0x19991) != 0) {
          CloseHandle(*(HANDLE *)(local_c + 0x19991));
          local_c[0x19991] = 0;
          local_c[0x19992] = 0;
        }
        if (*(int *)(local_c + 0x19993) != 0) {
          CloseHandle(*(HANDLE *)(local_c + 0x19993));
          local_c[0x19993] = 0;
          local_c[0x19994] = 0;
        }
        if (*(int *)(local_c + 0x1998d) != 0) {
          CloseHandle(*(HANDLE *)(local_c + 0x1998d));
          local_c[0x1998d] = 0;
          local_c[0x1998e] = 0;
        }
        if (*(int *)(local_c + 0x19989) != 0) {
          CloseHandle(*(HANDLE *)(local_c + 0x19989));
          local_c[0x19989] = 0;
          local_c[0x1998a] = 0;
        }
        if (*(int *)(local_c + 0x19987) != 0) {
          CloseHandle(*(HANDLE *)(local_c + 0x19987));
          local_c[0x19987] = 0;
          local_c[0x19988] = 0;
        }
        free(local_c);
        local_8 = 0;
      }
    }
    else {
      local_8 = 0;
    }
  }
  return local_8;
}



// Function: CheckDataLink at 6f6a2fd2

int CheckDataLink(short param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  int local_20;
  int local_1c;
  uint local_14;
  ushort *local_10;
  uint local_c;
  undefined1 *local_8;
  
                    /* 0x2fd2  4  CheckDataLink */
  local_1c = FUN_6f6a8bed(&local_20,param_1);
  if (local_1c == 0) {
    memset((void *)(local_20 + 0x32a1d),0,0x78);
    local_10 = (ushort *)(local_20 + 0x31a09);
    local_8 = (undefined1 *)(local_20 + 0x31a13);
    *local_8 = 0x80;
    *(undefined1 *)(local_20 + 0x31a16) = 0x20;
    *local_10 = 4;
    *(undefined4 *)(local_20 + 0x31a0f) = 0;
    FUN_6f6a1193(local_10);
    *(undefined2 *)(local_20 + 0x33332) = 0;
    ResetEvent(*(HANDLE *)(local_20 + 0x33316));
    local_1c = FUN_6f6a89d8(local_20,(short *)(local_20 + 0x3332e),
                            (undefined2 *)(local_20 + 0x33330),local_10,(short *)0x0);
    if ((local_1c == 0) || (local_1c == 1)) {
      if (*(short *)(local_20 + 0x3332e) == 0) {
        local_1c = 1;
      }
      else {
        WaitForSingleObject(*(HANDLE *)(local_20 + 0x33316),0xfa);
        if ((*(short *)(local_20 + 0x33332) == 0) && (local_1c == 0)) {
          local_1c = 1;
        }
        if (local_1c == 0) {
          local_14 = local_14 & 0xffffff00;
          local_c = local_c & 0xffffff00;
          while ((((local_c & 0xff) < 0x50 &&
                  (*(char *)(local_20 + 0x32a1d + (local_c & 0xff)) != '\0')) &&
                 (*(char *)(local_20 + 0x32a1d + (local_c & 0xff)) != ','))) {
            *(undefined1 *)(param_2 + (local_14 & 0xff)) =
                 *(undefined1 *)(local_20 + 0x32a1d + (local_c & 0xff));
            local_14 = CONCAT31(local_14._1_3_,(char)local_14 + '\x01');
            local_c = CONCAT31(local_c._1_3_,(byte)local_c + '\x01');
          }
          if (*(char *)(local_20 + 0x32a1d + (local_c & 0xff)) == ',') {
            strcpy((char *)(param_2 + (local_14 & 0xff)),s__7_26__6f6ac020);
            local_14 = (uint)(byte)((char)local_14 + 6);
            do {
              bVar2 = (byte)local_c;
              local_c._0_1_ = bVar2 + 1;
              if ((0x4f < (byte)local_c) ||
                 (*(char *)(local_20 + 0x32a1d + (uint)(byte)local_c) == '\0')) goto LAB_6f6a3215;
            } while (*(char *)(local_20 + 0x32a1d + (uint)(byte)local_c) != ',');
            local_c._0_1_ = bVar2 + 2;
LAB_6f6a3215:
            if (*(char *)(local_20 + 0x32a1d + (uint)(byte)local_c) != '\0') {
              for (; ((byte)local_c < 0x50 &&
                     (*(char *)(local_20 + 0x32a1d + (uint)(byte)local_c) != '\0'));
                  local_c._0_1_ = (byte)local_c + 1) {
                *(undefined1 *)(param_2 + local_14) =
                     *(undefined1 *)(local_20 + 0x32a1d + (uint)(byte)local_c);
                local_14 = (uint)(byte)((char)local_14 + 1);
              }
            }
          }
          *(undefined1 *)(param_2 + (local_14 & 0xff)) = 0;
          cVar1 = '\0';
          bVar2 = 0;
          while( true ) {
            if (0x4f < bVar2) {
              return local_1c;
            }
            if (*(char *)(param_2 + (uint)bVar2) == '\0') {
              return local_1c;
            }
            if ((*(char *)(param_2 + (uint)bVar2) == ',') &&
               (cVar1 = cVar1 + '\x01', cVar1 == '\x03')) break;
            bVar2 = bVar2 + 1;
          }
          DAT_6f6ac018 = *(char *)(param_2 + 1 + (uint)bVar2) + -0x30;
          DAT_6f6ac1a4 = *(char *)(param_2 + 3 + (uint)bVar2) + -0x30;
        }
      }
    }
  }
  return local_1c;
}



// Function: FUN_6f6a3345 at 6f6a3345

undefined4 __cdecl FUN_6f6a3345(uint param_1,ushort param_2)

{
  undefined4 uVar1;
  
  if (param_2 < DAT_6f6ac01c) {
    if ((uint)DAT_6f6ac01c < (param_1 & 0xffff) + (uint)param_2) {
      uVar1 = 0x1e;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0x1d;
  }
  return uVar1;
}



// Function: LoadDPABuffer at 6f6a338f

int LoadDPABuffer(short param_1,void *param_2,ushort param_3,ushort param_4)

{
  undefined2 extraout_var;
  size_t local_18;
  int local_14;
  int local_10;
  undefined1 *local_c;
  ushort *local_8;
  
                    /* 0x338f  15  LoadDPABuffer */
  local_10 = FUN_6f6a8bed(&local_14,param_1);
  if (local_10 == 0) {
    if (param_3 < 0x7d1) {
      local_10 = FUN_6f6a3345(CONCAT22(extraout_var,param_3),param_4);
      if (local_10 == 0) {
        local_8 = (ushort *)(local_14 + 0x31a09);
        local_c = (undefined1 *)(local_14 + 0x31a13);
        *local_c = 0x80;
        *(undefined1 *)(local_14 + 0x31a16) = 10;
        *(ushort *)(local_14 + 0x31a17) = param_4;
        *(ushort *)(local_14 + 0x31a19) = param_3;
        if (param_3 < 0x800) {
          local_18 = (size_t)param_3;
        }
        else {
          local_18 = 0x800;
        }
        memcpy((void *)(local_14 + 0x31a1b),param_2,local_18);
        *local_8 = param_3 + 8;
        local_8[3] = 0;
        local_8[4] = 0;
        FUN_6f6a1193(local_8);
        local_10 = FUN_6f6a89d8(local_14,(short *)(local_14 + 0x33342),
                                (undefined2 *)(local_14 + 0x33344),local_8,(short *)0x0);
      }
    }
    else {
      local_10 = 5;
    }
  }
  return local_10;
}



// Function: ReadDPABuffer at 6f6a34c4

int ReadDPABuffer(short param_1,void *param_2,ushort param_3,ushort param_4)

{
  int iVar1;
  BOOL BVar2;
  undefined1 *puVar3;
  size_t local_18;
  int local_10;
  int local_c;
  ushort *local_8;
  
                    /* 0x34c4  19  ReadDPABuffer */
  local_c = FUN_6f6a8bed(&local_10,param_1);
  iVar1 = local_10;
  if (local_c == 0) {
    *(undefined2 *)(local_10 + 0x3334a) = 0;
    local_8 = (ushort *)(local_10 + 0x31a09);
    puVar3 = (undefined1 *)(local_10 + 0x31a13);
    BVar2 = ResetEvent(*(HANDLE *)(local_10 + 0x33312));
    if (param_3 < 0x7d1) {
      local_c = FUN_6f6a3345(CONCAT22((short)((uint)BVar2 >> 0x10),param_3),param_4);
      if (local_c == 0) {
        memset((void *)(local_10 + 0x32a95),0,0x800);
        *puVar3 = 0x80;
        *(undefined1 *)(iVar1 + 0x31a16) = 0xb;
        *(ushort *)(iVar1 + 0x31a17) = param_4;
        *(ushort *)(iVar1 + 0x31a19) = param_3;
        *local_8 = 8;
        local_8[3] = 0;
        local_8[4] = 0;
        FUN_6f6a1193(local_8);
        local_c = FUN_6f6a89d8(local_10,(short *)(local_10 + 0x33346),
                               (undefined2 *)(local_10 + 0x33348),local_8,(short *)0x0);
        if (((local_c == 0) || (local_c == 1)) && (*(short *)(local_10 + 0x33346) != 0)) {
          WaitForSingleObject(*(HANDLE *)(local_10 + 0x33312),0xfa);
          ResetEvent(*(HANDLE *)(local_10 + 0x33312));
          if ((*(short *)(local_10 + 0x3334a) == 0) && (local_c == 0)) {
            local_c = 1;
          }
          if (local_c == 0) {
            if (param_3 < 0x800) {
              local_18 = (size_t)param_3;
            }
            else {
              local_18 = 0x800;
            }
            memcpy(param_2,(void *)(local_10 + 0x32a95),local_18);
          }
        }
      }
    }
    else {
      local_c = 5;
    }
  }
  return local_c;
}



// Function: CheckLock at 6f6a3695

int CheckLock(short param_1,char *param_2,undefined1 *param_3)

{
  char *pcVar1;
  int local_10;
  int local_c;
  ushort *local_8;
  
                    /* 0x3695  5  CheckLock */
  local_c = FUN_6f6a8bed(&local_10,param_1);
  if (local_c == 0) {
    memset((void *)(local_10 + 0x33295),0,0x79);
    *param_3 = 0;
    local_8 = (ushort *)(local_10 + 0x31a09);
    *(undefined1 *)(local_10 + 0x31a13) = 0x80;
    *(undefined1 *)(local_10 + 0x31a16) = 0x30;
    *local_8 = 5;
    *(undefined4 *)(local_10 + 0x31a0f) = 0;
    FUN_6f6a1193(local_8);
    local_c = FUN_6f6a89d8(local_10,(short *)(local_10 + 0x33334),(undefined2 *)(local_10 + 0x33336)
                           ,local_8,(short *)0x0);
    if (((local_c == 0) || (local_c == 1)) && (*(short *)(local_10 + 0x33334) != 0)) {
      WaitForSingleObject(*(HANDLE *)(local_10 + 0x3330e),0xfa);
      if ((*(short *)(local_10 + 0x33338) == 0) && (local_c == 0)) {
        local_c = 1;
      }
      if ((local_c == 0) &&
         (pcVar1 = strstr((char *)(local_10 + 0x33295),param_2), pcVar1 != (char *)0x0)) {
        *param_3 = 1;
      }
    }
  }
  return local_c;
}



// Function: GetLockSeed at 6f6a37c3

int GetLockSeed(short param_1,char *param_2,undefined1 *param_3)

{
  byte abStackY_803c [32748];
  byte local_3c [16];
  int local_2c;
  size_t local_28;
  uint local_24;
  short local_20;
  uint local_1c;
  undefined1 *local_18;
  int local_14;
  int local_10;
  char *local_c;
  ushort *local_8;
  
                    /* 0x37c3  8  GetLockSeed */
  local_c = (char *)0x0;
  local_1c = local_1c & 0xffffff00;
  local_10 = FUN_6f6a8bed(&local_14,param_1);
  if (local_10 == 0) {
    memset((void *)(local_14 + 0x33295),0,0x79);
    local_8 = (ushort *)(local_14 + 0x31a09);
    local_18 = (undefined1 *)(local_14 + 0x31a13);
    *local_18 = 0x80;
    *(undefined1 *)(local_14 + 0x31a16) = 0x30;
    *local_8 = 5;
    *(undefined4 *)(local_14 + 0x31a0f) = 0;
    FUN_6f6a1193(local_8);
    local_10 = FUN_6f6a89d8(local_14,(short *)(local_14 + 0x33334),
                            (undefined2 *)(local_14 + 0x33336),local_8,(short *)0x0);
    if (((local_10 == 0) || (local_10 == 1)) && (*(short *)(local_14 + 0x33334) != 0)) {
      WaitForSingleObject(*(HANDLE *)(local_14 + 0x3330e),0xfa);
      if ((*(short *)(local_14 + 0x33338) == 0) && (local_10 == 0)) {
        local_10 = 1;
      }
      if (local_10 == 0) {
        local_c = strstr((char *)(local_14 + 0x33295),param_2);
        local_1c = local_1c & 0xffffff00;
        while (((local_1c & 0xff) == 0 && (local_c != (char *)0x0))) {
          if ((local_c == (char *)(local_14 + 0x33295)) || (local_c[-1] == '\t')) {
            local_2c = 0;
            local_28 = 0;
            local_24 = local_24 & 0xffffff00;
            local_20 = 0;
            memset(local_3c,0,0xe);
            local_2c = sscanf(local_c,s______s_6f6ac028);
            if (local_2c != 0) {
              local_28 = strlen((char *)local_3c);
              if ((int)local_28 < 5) {
                local_c = strstr(local_c + 1,param_2);
              }
              else {
                local_24 = CONCAT31(local_24._1_3_,1);
                for (local_20 = 0; (int)local_20 < (int)(local_28 - 4); local_20 = local_20 + 1) {
                  if ((uint)local_3c[local_20] != (int)param_2[local_20]) {
                    local_24 = local_24 & 0xffffff00;
                  }
                }
                if ((local_24 & 0xff) == 0) {
                  local_c = strstr(local_c + 1,param_2);
                }
                else {
                  *param_3 = (&stack0xffffffc0)[local_28];
                  param_3[1] = (&stack0xffffffc1)[local_28];
                  param_3[2] = (&stack0xffffffc2)[local_28];
                  param_3[3] = (&stack0xffffffc3)[local_28];
                  local_10 = 0;
                  local_1c = CONCAT31(local_1c._1_3_,1);
                }
              }
            }
          }
          else {
            local_c = strstr(local_c + 1,param_2);
          }
        }
        if ((local_1c & 0xff) == 0) {
          local_10 = 0x2b;
        }
      }
    }
  }
  return local_10;
}



// Function: GoToLoader at 6f6a3a8d

int GoToLoader(short param_1)

{
  int local_10;
  int local_c;
  ushort *local_8;
  
                    /* 0x3a8d  9  GoToLoader */
  local_c = FUN_6f6a8bed(&local_10,param_1);
  if (local_c == 0) {
    local_8 = (ushort *)(local_10 + 0x31a09);
    *(undefined1 *)(local_10 + 0x31a13) = 0x80;
    *(undefined1 *)(local_10 + 0x31a16) = 0x31;
    *local_8 = 4;
    *(undefined4 *)(local_10 + 0x31a0f) = 0;
    FUN_6f6a1193(local_8);
    local_c = FUN_6f6a89d8(local_10,(short *)(local_10 + 0x3333a),(undefined2 *)(local_10 + 0x3333c)
                           ,local_8,(short *)0x0);
  }
  return local_c;
}



// Function: InitDataLink at 6f6a3b20

int InitDataLink(short param_1,byte *param_2)

{
  int iVar1;
  undefined1 *puVar2;
  byte bVar3;
  undefined1 local_64 [84];
  int local_10;
  int local_c;
  ushort *local_8;
  
                    /* 0x3b20  11  InitDataLink */
  local_c = FUN_6f6a8bed(&local_10,param_1);
  iVar1 = local_10;
  if (local_c == 0) {
    local_8 = (ushort *)(local_10 + 0x31a09);
    puVar2 = (undefined1 *)(local_10 + 0x31a13);
    local_c = FUN_6f6a3fd8((uint)*param_2);
    if (local_c == 0) {
      *(undefined4 *)(local_10 + 0x319ed) = 0;
      if (*param_2 == 3) {
        memset((void *)(local_10 + 9),0,0x8450);
        memset((void *)(local_10 + 0x8459),0,0x8450);
        for (bVar3 = 0; bVar3 < 0x10; bVar3 = bVar3 + 1) {
          *(byte *)(local_10 + 0xc + (uint)bVar3 * 0x845) = bVar3;
          *(undefined1 *)(local_10 + 0x19 + (uint)bVar3 * 0x845) = 0;
          *(byte *)(local_10 + 0x845c + (uint)bVar3 * 0x845) = bVar3;
          *(undefined1 *)(local_10 + 0x8469 + (uint)bVar3 * 0x845) = 1;
        }
        *(undefined4 *)(local_10 + 0x319f1) = 0;
        *(undefined4 *)(local_10 + 0x319f5) = 0;
        if (param_2[3] == 3) {
          *(undefined1 *)(local_10 + 8) = 1;
        }
        else {
          *(undefined1 *)(local_10 + 8) = 0;
        }
      }
      else if (*param_2 == 1) {
        memset((void *)(local_10 + 0x108a9),0,0x8450);
        memset((void *)(local_10 + 0x18cf9),0,0x8450);
        for (bVar3 = 0; bVar3 < 0x10; bVar3 = bVar3 + 1) {
          *(byte *)(local_10 + 0x108ac + (uint)bVar3 * 0x845) = bVar3;
          *(undefined1 *)(local_10 + 0x108b9 + (uint)bVar3 * 0x845) = 0;
          *(byte *)(local_10 + 0x18cfc + (uint)bVar3 * 0x845) = bVar3;
          *(undefined1 *)(local_10 + 0x18d09 + (uint)bVar3 * 0x845) = 1;
        }
        *(undefined4 *)(local_10 + 0x319f9) = 0;
        *(undefined4 *)(local_10 + 0x319fd) = 0;
      }
      else if (*param_2 == 2) {
        memset((void *)(local_10 + 0x21149),0,0x8450);
        memset((void *)(local_10 + 0x29599),0,0x8450);
        for (bVar3 = 0; bVar3 < 0x10; bVar3 = bVar3 + 1) {
          *(byte *)(local_10 + 0x2114c + (uint)bVar3 * 0x845) = bVar3;
          *(undefined1 *)(local_10 + 0x21159 + (uint)bVar3 * 0x845) = 0;
          *(byte *)(local_10 + 0x2959c + (uint)bVar3 * 0x845) = bVar3;
          *(undefined1 *)(local_10 + 0x295a9 + (uint)bVar3 * 0x845) = 1;
        }
        *(undefined4 *)(local_10 + 0x31a01) = 0;
        *(undefined4 *)(local_10 + 0x31a05) = 0;
      }
      *puVar2 = 0x80;
      *(undefined1 *)(iVar1 + 0x31a16) = 1;
      *(byte *)(iVar1 + 0x31a17) = *param_2;
      *(byte *)(iVar1 + 0x31a18) = param_2[1];
      *(byte *)(iVar1 + 0x31a19) = param_2[2];
      *(byte *)(iVar1 + 0x31a1a) = param_2[3];
      *(byte *)(iVar1 + 0x31a1b) = param_2[4];
      *(byte *)(iVar1 + 0x31a1c) = param_2[5];
      *local_8 = 10;
      local_8[3] = 0;
      local_8[4] = 0;
      FUN_6f6a1193(local_8);
      if ((*param_2 == 0) || (0x7f < param_2[1])) {
        local_c = FUN_6f6aa406(*(int *)(local_10 + 4),local_8);
        if (local_c == 0) {
          Sleep(500);
        }
      }
      else {
        local_c = FUN_6f6a89d8(local_10,(short *)(local_10 + 0x3333e),
                               (undefined2 *)(local_10 + 0x33340),local_8,(short *)0x0);
        if (((local_c == 0) || (local_c == 1)) && (local_c == 0)) {
          *(undefined4 *)(local_10 + 0x319ed) = *(undefined4 *)(param_2 + 6);
          CheckDataLink(param_1,(int)local_64);
          if (*param_2 == 3) {
            *(undefined4 *)(local_10 + 0x319f1) = *(undefined4 *)(param_2 + 10);
            *(undefined4 *)(local_10 + 0x319f5) = *(undefined4 *)(param_2 + 0xe);
          }
          else if (*param_2 == 1) {
            *(undefined4 *)(local_10 + 0x319f9) = *(undefined4 *)(param_2 + 10);
            *(undefined4 *)(local_10 + 0x319fd) = *(undefined4 *)(param_2 + 0xe);
          }
        }
      }
    }
  }
  return local_c;
}



// Function: FUN_6f6a3fd8 at 6f6a3fd8

undefined4 __cdecl FUN_6f6a3fd8(int param_1)

{
  undefined4 uVar1;
  
  if ((param_1 < 0) || (3 < param_1)) {
    uVar1 = 2;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



// Function: SendBuffer at 6f6a3ffd

int SendBuffer(short param_1,void *param_2)

{
  int local_c;
  int local_8;
  
                    /* 0x3ffd  2  SendBuffer */
  local_8 = 0;
  local_8 = FUN_6f6a8bed(&local_c,param_1);
  if (local_8 == 0) {
    local_8 = FUN_6f6a8d80(*(int *)(local_c + 4),param_2);
  }
  return local_8;
}



// Function: SetDecodeCallback at 6f6a4048

int SetDecodeCallback(short param_1,undefined4 param_2)

{
  int iVar1;
  int local_c [2];
  
                    /* 0x4048  3  SetDecodeCallback */
  local_c[1] = 0;
  iVar1 = FUN_6f6a8bed(local_c,param_1);
  if (iVar1 == 0) {
    *(undefined4 *)(local_c[0] + 0x333ac) = param_2;
  }
  return iVar1;
}



// Function: LoadMailBox at 6f6a4089

int LoadMailBox(short param_1,byte *param_2)

{
  int local_c;
  int local_8;
  
                    /* 0x4089  16  LoadMailBox */
  local_8 = FUN_6f6a8bed(&local_c,param_1);
  if ((((local_8 == 0) && (local_8 = FUN_6f6a3fd8((uint)*param_2), local_8 == 0)) &&
      (local_8 = FUN_6f6a41ce((uint)*param_2,param_2[8]), local_8 == 0)) &&
     ((local_8 = FUN_6f6a421a(local_c,(char *)param_2), local_8 == 0 &&
      ((param_2[0x2a] != 1 ||
       (local_8 = FUN_6f6a3345(CONCAT22((short)((uint)param_2 >> 0x10),
                                        *(undefined2 *)(param_2 + 0x3a)),*(ushort *)(param_2 + 0x2b)
                              ), local_8 == 0)))))) {
    if (*param_2 == 3) {
      local_8 = FUN_6f6a43cc(param_2[6]);
      if (local_8 == 0) {
        local_8 = FUN_6f6a43f5(local_c,param_2);
      }
    }
    else if (*param_2 == 1) {
      local_8 = FUN_6f6a556a(local_c,param_2);
    }
    else if (*param_2 == 2) {
      local_8 = FUN_6f6a4d2a(local_c,param_2);
    }
  }
  return local_8;
}



// Function: FUN_6f6a41ce at 6f6a41ce

undefined4 __cdecl FUN_6f6a41ce(int param_1,char param_2)

{
  if (param_1 == 3) {
    if ((param_2 != '\v') && (param_2 != '\x1d')) {
      return 4;
    }
  }
  else if ((param_1 == 2) && (param_2 != '\x18')) {
    return 4;
  }
  return 0;
}



// Function: FUN_6f6a421a at 6f6a421a

undefined4 __cdecl FUN_6f6a421a(int param_1,char *param_2)

{
  if (*param_2 == '\x03') {
    if (param_2[5] == '\x01') {
      if (((param_2[0x2a] == '\0') || (*(char *)(param_1 + 8) == '\0')) || (param_2[6] == '\x01')) {
        if (8 < *(ushort *)(param_2 + 0x3a)) {
          return 5;
        }
      }
      else {
        if ((param_2[0x17] == '\0') && (2000 < *(ushort *)(param_2 + 0x3a))) {
          return 5;
        }
        if (0x6f9 < *(ushort *)(param_2 + 0x3a)) {
          return 5;
        }
      }
    }
    else if ((param_2[0x2a] == '\0') || (*(char *)(param_1 + 8) == '\0')) {
      if (8 < *(ushort *)(param_2 + 0x3a)) {
        return 5;
      }
    }
    else {
      if ((param_2[0x17] == '\0') && (2000 < *(ushort *)(param_2 + 0x3a))) {
        return 5;
      }
      if (0x6f9 < *(ushort *)(param_2 + 0x3a)) {
        return 5;
      }
    }
  }
  else if (*param_2 == '\x01') {
    if (param_2[0x2a] == '\0') {
      if (0x13 < *(ushort *)(param_2 + 0x3a)) {
        return 5;
      }
    }
    else if (0x800 < *(ushort *)(param_2 + 0x3a)) {
      return 5;
    }
  }
  else if (*param_2 == '\x02') {
    if (param_2[0x2a] == '\0') {
      if (9 < *(ushort *)(param_2 + 0x3a)) {
        return 5;
      }
    }
    else if (0x200 < *(ushort *)(param_2 + 0x3a)) {
      return 5;
    }
  }
  return 0;
}



// Function: FUN_6f6a43cc at 6f6a43cc

undefined4 __cdecl FUN_6f6a43cc(byte param_1)

{
  undefined4 uVar1;
  
  if ((param_1 < 8) && (param_1 != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x1b;
  }
  return uVar1;
}



// Function: FUN_6f6a43f5 at 6f6a43f5

int __cdecl FUN_6f6a43f5(int param_1,undefined1 *param_2)

{
  ushort *puVar1;
  undefined4 local_1c;
  int local_10;
  int local_8;
  
  puVar1 = (ushort *)(param_1 + 0x31a09);
  if (param_2[5] == '\0') {
    memset((undefined1 *)(param_1 + 0x31a13),0,0x15);
    *(undefined1 *)(param_1 + 0x31a13) = 0x80;
    *(undefined1 *)(param_1 + 0x31a16) = 0x42;
    if (((param_2[0x13] != '\0') && (*(int *)(param_2 + 0x3c) != 0)) ||
       (*(int *)(param_2 + 0x2d) != 0)) {
      *(byte *)(param_1 + 0x31a18) = *(byte *)(param_1 + 0x31a18) | 0x10;
      if (param_2[0x14] == '\0') {
        *(byte *)(param_1 + 0x31a18) = *(byte *)(param_1 + 0x31a18) | 0x20;
      }
      if (param_2[0x15] == '\0') {
        *(byte *)(param_1 + 0x31a18) = *(byte *)(param_1 + 0x31a18) | 0x40;
      }
      if (param_2[0x16] == '\0') {
        *(byte *)(param_1 + 0x31a18) = *(byte *)(param_1 + 0x31a18) | 8;
      }
      if (param_2[0x17] == '\0') {
        *(byte *)(param_1 + 0x31a18) = *(byte *)(param_1 + 0x31a18) | 0x80;
      }
    }
    if (param_2[0x12] == '\x01') {
      *(byte *)(param_1 + 0x31a18) = *(byte *)(param_1 + 0x31a18) | 2;
    }
    if (param_2[8] == '\x1d') {
      *(byte *)(param_1 + 0x31a19) = *(byte *)(param_1 + 0x31a19) | 4;
    }
    *(byte *)(param_1 + 0x31a19) = *(byte *)(param_1 + 0x31a19) | param_2[6] << 4;
    *(undefined1 *)(param_1 + 0x31a17) = *param_2;
    if (param_2[8] == '\x1d') {
      local_8 = *(int *)(param_2 + 9) << 3;
    }
    else {
      local_8 = *(int *)(param_2 + 9) << 0x15;
    }
    FUN_6f6a1160((undefined1 *)(param_1 + 0x31a1a),(undefined1 *)&local_8);
    if (param_2[8] == '\x1d') {
      local_8 = *(int *)(param_2 + 0xe) << 3;
    }
    else {
      local_8 = *(int *)(param_2 + 0xe) << 0x15;
    }
    FUN_6f6a1160((undefined1 *)(param_1 + 0x31a1e),(undefined1 *)&local_8);
    *(undefined1 *)(param_1 + 0x31a22) = param_2[0xd];
    *(undefined2 *)(param_1 + 0x31a26) = *(undefined2 *)(param_2 + 0x3a);
    if (param_2[0x2a] == '\x01') {
      if (param_2[0x17] != '\0') {
        *(byte *)(param_1 + 0x31a18) = *(byte *)(param_1 + 0x31a18) & 0x7f;
      }
      *(undefined2 *)(param_1 + 0x31a24) = *(undefined2 *)(param_2 + 0x2b);
    }
    else {
      *(undefined2 *)(param_1 + 0x31a24) = 0xffff;
    }
    *(undefined2 *)(param_1 + 0x31a26) = *(undefined2 *)(param_2 + 0x3a);
    *puVar1 = 0x15;
    *(undefined4 *)(param_1 + 0x31a0f) = 0;
    FUN_6f6a1193(puVar1);
    *(undefined2 *)(param_1 + 0x33352) = 0xff;
    local_10 = FUN_6f6a89d8(param_1,(short *)(param_1 + 0x3334c),(undefined2 *)(param_1 + 0x3334e),
                            puVar1,(short *)(param_1 + 0x33350));
    if (local_10 == 0) {
      if (*(short *)(param_1 + 0x33350) < 0x10) {
        *(int *)(param_2 + 1) = param_1 + 9 + *(short *)(param_1 + 0x33350) * 0x845;
        memset(*(void **)(param_2 + 1),0,0x845);
        *(undefined1 *)(*(int *)(param_2 + 1) + 3) = *(undefined1 *)(param_1 + 0x33350);
        **(undefined1 **)(param_2 + 1) = *param_2;
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x10) = 0;
        *(undefined1 *)(*(int *)(param_2 + 1) + 1) = 1;
        *(undefined1 *)(*(int *)(param_2 + 1) + 2) = param_2[8];
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x13) = *(undefined4 *)(param_2 + 0x2d);
        *(undefined2 *)(*(int *)(param_2 + 1) + 0x29) = 0;
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x82b) = param_2[0x13];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x82c) = param_2[0x14];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x82d) = param_2[0x15];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x82e) = param_2[0x16];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x82f) = param_2[0x17];
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x83d) = *(undefined4 *)(param_2 + 0x3c);
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x841) = *(undefined4 *)(param_2 + 0x36);
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x837) = param_2[0x2a];
        *(undefined2 *)(*(int *)(param_2 + 1) + 0x838) = *(undefined2 *)(param_2 + 0x2b);
        *(undefined4 *)(*(int *)(param_2 + 1) + 6) = *(undefined4 *)(param_2 + 9);
        *(undefined4 *)(*(int *)(param_2 + 1) + 0xb) = *(undefined4 *)(param_2 + 0xe);
        *(undefined1 *)(*(int *)(param_2 + 1) + 10) = param_2[0xd];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0xf) = param_2[0x12];
      }
      else {
        *(undefined4 *)(param_2 + 1) = 0;
        local_10 = 10;
      }
      *(undefined2 *)(param_1 + 0x33352) = 0xff;
    }
    else {
      *(undefined2 *)(param_1 + 0x33352) = 0xff;
    }
  }
  else {
    memset((undefined1 *)(param_1 + 0x31a13),0,0x1c);
    *(undefined1 *)(param_1 + 0x31a13) = 0x80;
    *(undefined1 *)(param_1 + 0x31a16) = 0x43;
    if (param_2[0x18] != '\0') {
      *(byte *)(param_1 + 0x31a1c) = *(byte *)(param_1 + 0x31a1c) | 2;
    }
    if (*(int *)(param_2 + 0x32) != 0) {
      *(byte *)(param_1 + 0x31a1c) = *(byte *)(param_1 + 0x31a1c) | 4;
    }
    if ((*(int *)(param_2 + 0x2d) != 0) &&
       (*(byte *)(param_1 + 0x31a1c) = *(byte *)(param_1 + 0x31a1c) | 0x10, param_2[0x14] == '\0'))
    {
      *(byte *)(param_1 + 0x31a1c) = *(byte *)(param_1 + 0x31a1c) | 0x20;
    }
    if (param_2[7] == '\0') {
      *(byte *)(param_1 + 0x31a1c) = *(byte *)(param_1 + 0x31a1c) | 1;
    }
    if (param_2[8] == '\x1d') {
      *(byte *)(param_1 + 0x31a1d) = *(byte *)(param_1 + 0x31a1d) | 4;
    }
    *(byte *)(param_1 + 0x31a1d) = *(byte *)(param_1 + 0x31a1d) | param_2[6] << 4;
    *(undefined4 *)(param_1 + 0x31a18) = *(undefined4 *)(param_2 + 0x19);
    *(undefined1 *)(param_1 + 0x31a17) = *param_2;
    if (param_2[8] == '\x1d') {
      local_8 = *(int *)(param_2 + 9) << 3;
    }
    else {
      local_8 = *(int *)(param_2 + 9) << 0x15;
    }
    FUN_6f6a1160((undefined1 *)(param_1 + 0x31a1e),(undefined1 *)&local_8);
    *(undefined1 *)(param_1 + 0x31a22) = param_2[0xd];
    if (*(int *)(param_2 + 0x1d) == 0) {
      local_1c = 1;
    }
    else {
      local_1c = *(undefined4 *)(param_2 + 0x1d);
    }
    *(undefined4 *)(param_1 + 0x31a28) = local_1c;
    *(undefined2 *)(param_1 + 0x31a2c) = *(undefined2 *)(param_2 + 0x21);
    *(undefined2 *)(param_1 + 0x31a26) = *(undefined2 *)(param_2 + 0x3a);
    *puVar1 = 0x1b;
    if (param_2[0x2a] == '\0') {
      *(undefined2 *)(param_1 + 0x31a24) = 0xffff;
      *(byte *)(param_1 + 0x31a1d) = *(byte *)(param_1 + 0x31a1d) | 1;
      memcpy((void *)(param_1 + 0x31a2e),*(void **)(param_2 + 0x3c),
             (uint)*(ushort *)(param_2 + 0x3a));
      *puVar1 = *puVar1 + *(short *)(param_2 + 0x3a);
    }
    else {
      *(undefined2 *)(param_1 + 0x31a24) = *(undefined2 *)(param_2 + 0x2b);
      if (param_2[0x17] == '\0') {
        *(byte *)(param_1 + 0x31a1d) = *(byte *)(param_1 + 0x31a1d) | 1;
        memcpy((void *)(param_1 + 0x31a2e),*(void **)(param_2 + 0x3c),
               (uint)*(ushort *)(param_2 + 0x3a));
        *puVar1 = *puVar1 + *(short *)(param_2 + 0x3a);
      }
    }
    *(undefined4 *)(param_1 + 0x31a0f) = 0;
    FUN_6f6a1193(puVar1);
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x3332a),0xfa);
    *(undefined2 *)(param_1 + 0x33352) = 0xff;
    local_10 = FUN_6f6a89d8(param_1,(short *)(param_1 + 0x3334c),(undefined2 *)(param_1 + 0x3334e),
                            puVar1,(short *)(param_1 + 0x33350));
    if (local_10 == 0) {
      if (*(short *)(param_1 + 0x33350) < 0x10) {
        *(int *)(param_2 + 1) = param_1 + 0x8459 + *(short *)(param_1 + 0x33350) * 0x845;
        memset(*(void **)(param_2 + 1),0,0x845);
        *(undefined1 *)(*(int *)(param_2 + 1) + 3) = *(undefined1 *)(param_1 + 0x33350);
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x10) = 1;
        *(undefined1 *)(*(int *)(param_2 + 1) + 1) = 1;
        *(undefined1 *)(*(int *)(param_2 + 1) + 2) = param_2[8];
        *(undefined4 *)(*(int *)(param_2 + 1) + 6) = *(undefined4 *)(param_2 + 9);
        *(undefined4 *)(*(int *)(param_2 + 1) + 0xb) = *(undefined4 *)(param_2 + 0xe);
        *(undefined1 *)(*(int *)(param_2 + 1) + 10) = param_2[0xd];
        **(undefined1 **)(param_2 + 1) = *param_2;
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x12) = param_2[0x18];
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x1b) = *(undefined4 *)(param_2 + 0x19);
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x23) = *(undefined4 *)(param_2 + 0x1d);
        *(undefined2 *)(*(int *)(param_2 + 1) + 0x27) = *(undefined2 *)(param_2 + 0x21);
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x82c) = param_2[0x14];
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x13) = *(undefined4 *)(param_2 + 0x2d);
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x17) = *(undefined4 *)(param_2 + 0x32);
        *(undefined2 *)(*(int *)(param_2 + 1) + 0x29) = *(undefined2 *)(param_2 + 0x3a);
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x83d) = *(undefined4 *)(param_2 + 0x3c);
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x841) = *(undefined4 *)(param_2 + 0x36);
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x837) = param_2[0x2a];
        *(undefined2 *)(*(int *)(param_2 + 1) + 0x838) = *(undefined2 *)(param_2 + 0x2b);
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x82f) = param_2[0x17];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x11) = param_2[6];
        if (param_2[0x2a] == '\0') {
          memcpy((void *)(*(int *)(param_2 + 1) + 0x2b),*(void **)(*(int *)(param_2 + 1) + 0x83d),
                 (uint)*(ushort *)(*(int *)(param_2 + 1) + 0x29));
        }
      }
      else {
        *(undefined4 *)(param_2 + 1) = 0;
        local_10 = 10;
      }
      *(undefined2 *)(param_1 + 0x33352) = 0xff;
      ReleaseMutex(*(HANDLE *)(param_1 + 0x3332a));
    }
    else {
      *(undefined2 *)(param_1 + 0x33352) = 0xff;
      ReleaseMutex(*(HANDLE *)(param_1 + 0x3332a));
    }
  }
  return local_10;
}



// Function: FUN_6f6a4d2a at 6f6a4d2a

int __cdecl FUN_6f6a4d2a(int param_1,undefined1 *param_2)

{
  ushort *puVar1;
  undefined4 local_18;
  int local_14;
  
  puVar1 = (ushort *)(param_1 + 0x31a09);
  if (param_2[5] == '\0') {
    memset((undefined1 *)(param_1 + 0x31a13),0,0x13);
    *(undefined1 *)(param_1 + 0x31a13) = 0x80;
    *(undefined1 *)(param_1 + 0x31a16) = 0x42;
    if (((param_2[0x13] != '\0') && (*(int *)(param_2 + 0x3c) != 0)) ||
       (*(int *)(param_2 + 0x2d) != 0)) {
      *(byte *)(param_1 + 0x31a18) = *(byte *)(param_1 + 0x31a18) | 0x10;
      if (param_2[0x14] == '\0') {
        *(byte *)(param_1 + 0x31a18) = *(byte *)(param_1 + 0x31a18) | 0x20;
      }
      if (param_2[0x15] == '\0') {
        *(byte *)(param_1 + 0x31a18) = *(byte *)(param_1 + 0x31a18) | 0x40;
      }
      if (param_2[0x16] == '\0') {
        *(byte *)(param_1 + 0x31a18) = *(byte *)(param_1 + 0x31a18) | 8;
      }
      if (param_2[0x17] == '\0') {
        *(byte *)(param_1 + 0x31a18) = *(byte *)(param_1 + 0x31a18) | 0x80;
      }
    }
    if (param_2[0x12] == '\x01') {
      *(byte *)(param_1 + 0x31a18) = *(byte *)(param_1 + 0x31a18) | 2;
    }
    if (param_2[8] == '\x18') {
      *(byte *)(param_1 + 0x31a19) = *(byte *)(param_1 + 0x31a19) | 4;
    }
    *(undefined1 *)(param_1 + 0x31a17) = *param_2;
    *(undefined4 *)(param_1 + 0x31a1a) = *(undefined4 *)(param_2 + 9);
    *(undefined4 *)(param_1 + 0x31a1e) = *(undefined4 *)(param_2 + 0xe);
    *(undefined2 *)(param_1 + 0x31a24) = *(undefined2 *)(param_2 + 0x3a);
    if (param_2[0x2a] == '\x01') {
      if (param_2[0x17] != '\0') {
        *(byte *)(param_1 + 0x31a18) = *(byte *)(param_1 + 0x31a18) & 0x7f;
      }
      *(undefined2 *)(param_1 + 0x31a22) = *(undefined2 *)(param_2 + 0x2b);
    }
    else {
      *(undefined2 *)(param_1 + 0x31a22) = 0xffff;
    }
    *(undefined2 *)(param_1 + 0x31a24) = *(undefined2 *)(param_2 + 0x3a);
    *puVar1 = 0x13;
    *(undefined4 *)(param_1 + 0x31a0f) = 0;
    FUN_6f6a1193(puVar1);
    *(undefined2 *)(param_1 + 0x33352) = 0xff;
    local_14 = FUN_6f6a89d8(param_1,(short *)(param_1 + 0x3334c),(undefined2 *)(param_1 + 0x3334e),
                            puVar1,(short *)(param_1 + 0x33350));
    if (local_14 == 0) {
      if (*(short *)(param_1 + 0x33350) < 0x10) {
        *(int *)(param_2 + 1) = param_1 + 0x21149 + *(short *)(param_1 + 0x33350) * 0x845;
        memset(*(void **)(param_2 + 1),0,0x845);
        *(undefined1 *)(*(int *)(param_2 + 1) + 3) = *(undefined1 *)(param_1 + 0x33350);
        **(undefined1 **)(param_2 + 1) = *param_2;
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x10) = 0;
        *(undefined1 *)(*(int *)(param_2 + 1) + 1) = 1;
        *(undefined1 *)(*(int *)(param_2 + 1) + 2) = param_2[8];
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x13) = *(undefined4 *)(param_2 + 0x2d);
        *(undefined2 *)(*(int *)(param_2 + 1) + 0x29) = 0;
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x82b) = param_2[0x13];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x82c) = param_2[0x14];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x82d) = param_2[0x15];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x82e) = param_2[0x16];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x82f) = param_2[0x17];
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x83d) = *(undefined4 *)(param_2 + 0x3c);
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x841) = *(undefined4 *)(param_2 + 0x36);
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x837) = param_2[0x2a];
        *(undefined2 *)(*(int *)(param_2 + 1) + 0x838) = *(undefined2 *)(param_2 + 0x2b);
        *(undefined4 *)(*(int *)(param_2 + 1) + 6) = *(undefined4 *)(param_2 + 9);
        *(undefined4 *)(*(int *)(param_2 + 1) + 0xb) = *(undefined4 *)(param_2 + 0xe);
        *(undefined1 *)(*(int *)(param_2 + 1) + 0xf) = param_2[0x12];
      }
      else {
        *(undefined4 *)(param_2 + 1) = 0;
        local_14 = 10;
      }
      *(undefined2 *)(param_1 + 0x33352) = 0xff;
    }
    else {
      *(undefined2 *)(param_1 + 0x33352) = 0xff;
    }
  }
  else {
    memset((undefined1 *)(param_1 + 0x31a13),0,0x1a);
    *(undefined1 *)(param_1 + 0x31a13) = 0x80;
    *(undefined1 *)(param_1 + 0x31a16) = 0x43;
    if (param_2[0x18] != '\0') {
      *(byte *)(param_1 + 0x31a1c) = *(byte *)(param_1 + 0x31a1c) | 2;
    }
    if (*(int *)(param_2 + 0x32) != 0) {
      *(byte *)(param_1 + 0x31a1c) = *(byte *)(param_1 + 0x31a1c) | 4;
    }
    if ((*(int *)(param_2 + 0x2d) != 0) &&
       (*(byte *)(param_1 + 0x31a1c) = *(byte *)(param_1 + 0x31a1c) | 0x10, param_2[0x14] == '\0'))
    {
      *(byte *)(param_1 + 0x31a1c) = *(byte *)(param_1 + 0x31a1c) | 0x20;
    }
    if (param_2[7] == '\0') {
      *(byte *)(param_1 + 0x31a1c) = *(byte *)(param_1 + 0x31a1c) | 1;
    }
    if (param_2[8] == '\x18') {
      *(byte *)(param_1 + 0x31a1d) = *(byte *)(param_1 + 0x31a1d) | 4;
    }
    *(undefined4 *)(param_1 + 0x31a18) = *(undefined4 *)(param_2 + 0x19);
    *(undefined1 *)(param_1 + 0x31a17) = *param_2;
    *(undefined4 *)(param_1 + 0x31a1e) = *(undefined4 *)(param_2 + 9);
    if (*(int *)(param_2 + 0x1d) == 0) {
      local_18 = 1;
    }
    else {
      local_18 = *(undefined4 *)(param_2 + 0x1d);
    }
    *(undefined4 *)(param_1 + 0x31a26) = local_18;
    *(undefined2 *)(param_1 + 0x31a2a) = *(undefined2 *)(param_2 + 0x21);
    *(undefined2 *)(param_1 + 0x31a24) = *(undefined2 *)(param_2 + 0x3a);
    *puVar1 = 0x19;
    if (param_2[0x2a] == '\0') {
      *(undefined2 *)(param_1 + 0x31a22) = 0xffff;
      *(byte *)(param_1 + 0x31a1d) = *(byte *)(param_1 + 0x31a1d) | 1;
      memcpy((void *)(param_1 + 0x31a2c),*(void **)(param_2 + 0x3c),
             (uint)*(ushort *)(param_2 + 0x3a));
      *puVar1 = *puVar1 + *(short *)(param_2 + 0x3a);
    }
    else {
      *(undefined2 *)(param_1 + 0x31a22) = *(undefined2 *)(param_2 + 0x2b);
      if (param_2[0x17] == '\0') {
        *(byte *)(param_1 + 0x31a1d) = *(byte *)(param_1 + 0x31a1d) | 1;
        memcpy((void *)(param_1 + 0x31a2c),*(void **)(param_2 + 0x3c),
               (uint)*(ushort *)(param_2 + 0x3a));
        *puVar1 = *puVar1 + *(short *)(param_2 + 0x3a);
      }
    }
    *(undefined4 *)(param_1 + 0x31a0f) = 0;
    FUN_6f6a1193(puVar1);
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x3332a),0xfa);
    *(undefined2 *)(param_1 + 0x33352) = 0xff;
    local_14 = FUN_6f6a89d8(param_1,(short *)(param_1 + 0x3334c),(undefined2 *)(param_1 + 0x3334e),
                            puVar1,(short *)(param_1 + 0x33350));
    if (local_14 == 0) {
      if (*(short *)(param_1 + 0x33350) < 0x10) {
        *(int *)(param_2 + 1) = param_1 + 0x29599 + *(short *)(param_1 + 0x33350) * 0x845;
        memset(*(void **)(param_2 + 1),0,0x845);
        *(undefined1 *)(*(int *)(param_2 + 1) + 3) = *(undefined1 *)(param_1 + 0x33350);
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x10) = 1;
        *(undefined1 *)(*(int *)(param_2 + 1) + 1) = 1;
        *(undefined1 *)(*(int *)(param_2 + 1) + 2) = param_2[8];
        *(undefined4 *)(*(int *)(param_2 + 1) + 6) = *(undefined4 *)(param_2 + 9);
        *(undefined4 *)(*(int *)(param_2 + 1) + 0xb) = *(undefined4 *)(param_2 + 0xe);
        *(undefined1 *)(*(int *)(param_2 + 1) + 10) = param_2[0xd];
        **(undefined1 **)(param_2 + 1) = *param_2;
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x12) = param_2[0x18];
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x1b) = *(undefined4 *)(param_2 + 0x19);
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x23) = *(undefined4 *)(param_2 + 0x1d);
        *(undefined2 *)(*(int *)(param_2 + 1) + 0x27) = *(undefined2 *)(param_2 + 0x21);
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x82c) = param_2[0x14];
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x13) = *(undefined4 *)(param_2 + 0x2d);
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x17) = *(undefined4 *)(param_2 + 0x32);
        *(undefined2 *)(*(int *)(param_2 + 1) + 0x29) = *(undefined2 *)(param_2 + 0x3a);
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x83d) = *(undefined4 *)(param_2 + 0x3c);
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x841) = *(undefined4 *)(param_2 + 0x36);
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x837) = param_2[0x2a];
        *(undefined2 *)(*(int *)(param_2 + 1) + 0x838) = *(undefined2 *)(param_2 + 0x2b);
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x82f) = param_2[0x17];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x11) = param_2[6];
        if (param_2[0x2a] == '\0') {
          memcpy((void *)(*(int *)(param_2 + 1) + 0x2b),*(void **)(*(int *)(param_2 + 1) + 0x83d),
                 (uint)*(ushort *)(*(int *)(param_2 + 1) + 0x29));
        }
      }
      else {
        *(undefined4 *)(param_2 + 1) = 0;
        local_14 = 10;
      }
      *(undefined2 *)(param_1 + 0x33352) = 0xff;
      ReleaseMutex(*(HANDLE *)(param_1 + 0x3332a));
    }
    else {
      *(undefined2 *)(param_1 + 0x33352) = 0xff;
      ReleaseMutex(*(HANDLE *)(param_1 + 0x3332a));
    }
  }
  return local_14;
}



// Function: FUN_6f6a556a at 6f6a556a

int __cdecl FUN_6f6a556a(int param_1,undefined1 *param_2)

{
  ushort *puVar1;
  undefined4 local_18;
  int local_10;
  
  puVar1 = (ushort *)(param_1 + 0x31a09);
  if (param_2[5] == '\0') {
    memset((undefined1 *)(param_1 + 0x31a13),0,4);
    *(undefined1 *)(param_1 + 0x31a13) = 0x80;
    *(undefined1 *)(param_1 + 0x31a16) = 0x42;
    *(undefined1 *)(param_1 + 0x31a18) = 0;
    *(undefined1 *)(param_1 + 0x31a19) = 0;
    if (((param_2[0x13] != '\0') && (*(int *)(param_2 + 0x3c) != 0)) ||
       (*(int *)(param_2 + 0x2d) != 0)) {
      *(byte *)(param_1 + 0x31a18) = *(byte *)(param_1 + 0x31a18) | 0x10;
      if (param_2[0x14] == '\0') {
        *(byte *)(param_1 + 0x31a18) = *(byte *)(param_1 + 0x31a18) | 0x20;
      }
      if (param_2[0x15] == '\0') {
        *(byte *)(param_1 + 0x31a18) = *(byte *)(param_1 + 0x31a18) | 0x40;
      }
      if (param_2[0x16] == '\0') {
        *(byte *)(param_1 + 0x31a18) = *(byte *)(param_1 + 0x31a18) | 8;
      }
      if (param_2[0x17] == '\0') {
        *(byte *)(param_1 + 0x31a18) = *(byte *)(param_1 + 0x31a18) | 0x80;
      }
    }
    *(undefined1 *)(param_1 + 0x31a1a) = param_2[0x26];
    *(undefined1 *)(param_1 + 0x31a1c) = param_2[0x28];
    *(undefined1 *)(param_1 + 0x31a1b) = param_2[0x27];
    *(undefined1 *)(param_1 + 0x31a1d) = param_2[0x29];
    *(undefined1 *)(param_1 + 0x31a17) = *param_2;
    if (param_2[0x12] == '\x01') {
      *(byte *)(param_1 + 0x31a18) = *(byte *)(param_1 + 0x31a18) | 2;
    }
    if (param_2[0x2a] == '\0') {
      *(undefined2 *)(param_1 + 0x31a1e) = 0xffff;
      *(undefined2 *)(param_1 + 0x31a20) = *(undefined2 *)(param_2 + 0x3a);
    }
    else {
      *(undefined2 *)(param_1 + 0x31a1e) = *(undefined2 *)(param_2 + 0x2b);
      *(undefined2 *)(param_1 + 0x31a20) = *(undefined2 *)(param_2 + 0x3a);
      if (param_2[0x17] != '\0') {
        *(byte *)(param_1 + 0x31a18) = *(byte *)(param_1 + 0x31a18) & 0x7f;
      }
    }
    *puVar1 = 0xf;
    *(undefined4 *)(param_1 + 0x31a0f) = 0;
    FUN_6f6a1193(puVar1);
    *(undefined2 *)(param_1 + 0x33352) = 0xff;
    local_10 = FUN_6f6a89d8(param_1,(short *)(param_1 + 0x3334c),(undefined2 *)(param_1 + 0x3334e),
                            puVar1,(short *)(param_1 + 0x33350));
    if (local_10 == 0) {
      if (*(short *)(param_1 + 0x33350) < 0x10) {
        *(int *)(param_2 + 1) = param_1 + 0x108a9 + *(short *)(param_1 + 0x33350) * 0x845;
        memset(*(void **)(param_2 + 1),0,0x845);
        *(undefined1 *)(*(int *)(param_2 + 1) + 3) = *(undefined1 *)(param_1 + 0x33350);
        **(undefined1 **)(param_2 + 1) = *param_2;
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x10) = 0;
        *(undefined1 *)(*(int *)(param_2 + 1) + 1) = 1;
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x13) = *(undefined4 *)(param_2 + 0x2d);
        *(undefined2 *)(*(int *)(param_2 + 1) + 0x29) = 0;
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x837) = param_2[0x2a];
        *(undefined2 *)(*(int *)(param_2 + 1) + 0x838) = *(undefined2 *)(param_2 + 0x2b);
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x82b) = param_2[0x13];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x82c) = param_2[0x14];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x82d) = param_2[0x15];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x82e) = param_2[0x16];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x82f) = param_2[0x17];
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x83d) = *(undefined4 *)(param_2 + 0x3c);
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x841) = *(undefined4 *)(param_2 + 0x36);
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x833) = param_2[0x26];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x834) = param_2[0x27];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x835) = param_2[0x28];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x836) = param_2[0x29];
      }
      else {
        *(undefined4 *)(param_2 + 1) = 0;
        local_10 = 10;
      }
      *(undefined2 *)(param_1 + 0x33352) = 0xff;
    }
    else {
      *(undefined2 *)(param_1 + 0x33352) = 0xff;
    }
  }
  else {
    memset((undefined1 *)(param_1 + 0x31a13),0,0x1a);
    *(undefined1 *)(param_1 + 0x31a13) = 0x80;
    *(undefined1 *)(param_1 + 0x31a16) = 0x43;
    *(undefined1 *)(param_1 + 0x31a17) = 1;
    *(undefined4 *)(param_1 + 0x31a18) = *(undefined4 *)(param_2 + 0x19);
    if (*(uint *)(param_2 + 0x1d) < 10) {
      local_18 = 10;
    }
    else {
      local_18 = *(undefined4 *)(param_2 + 0x1d);
    }
    *(undefined4 *)(param_1 + 0x31a26) = local_18;
    *(undefined2 *)(param_1 + 0x31a2a) = *(undefined2 *)(param_2 + 0x21);
    *(undefined1 *)(param_1 + 0x31a1f) = param_2[0x25];
    *(undefined1 *)(param_1 + 0x31a20) = param_2[0x26];
    *(undefined1 *)(param_1 + 0x31a21) = param_2[0x27];
    if ((*(int *)(param_2 + 0x32) != 0) || (param_2[0x31] != '\0')) {
      *(byte *)(param_1 + 0x31a1c) = *(byte *)(param_1 + 0x31a1c) | 4;
    }
    if (param_2[0x18] != '\0') {
      *(byte *)(param_1 + 0x31a1c) = *(byte *)(param_1 + 0x31a1c) | 2;
    }
    if ((*(int *)(param_2 + 0x2d) != 0) &&
       (*(byte *)(param_1 + 0x31a1c) = *(byte *)(param_1 + 0x31a1c) | 0x10, param_2[0x14] == '\0'))
    {
      *(byte *)(param_1 + 0x31a1c) = *(byte *)(param_1 + 0x31a1c) | 0x20;
    }
    if (param_2[7] == '\0') {
      *(byte *)(param_1 + 0x31a1c) = *(byte *)(param_1 + 0x31a1c) | 1;
    }
    if (param_2[0x2a] == '\0') {
      *(undefined2 *)(param_1 + 0x31a22) = 0xffff;
      *(undefined2 *)(param_1 + 0x31a24) = *(undefined2 *)(param_2 + 0x3a);
      memcpy((void *)(param_1 + 0x31a2c),*(void **)(param_2 + 0x3c),
             (uint)*(ushort *)(param_2 + 0x3a));
      *puVar1 = *(short *)(param_2 + 0x3a) + 0x19;
      if ((param_2[0x23] == '\0') || (0xf < (byte)param_2[0x24])) {
        *(undefined1 *)(param_1 + 0x31a1e) = 0xff;
      }
      else {
        if (param_2[0x23] != '\x01') {
          *(byte *)(param_1 + 0x31a1d) = *(byte *)(param_1 + 0x31a1d) | 0x80;
        }
        if (param_2[0x23] == '\x03') {
          *(undefined1 *)(param_1 + 0x31a1e) = 0xff;
        }
        else {
          *(undefined1 *)(param_1 + 0x31a1e) = param_2[0x24];
        }
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x31a1e) = 0xff;
      *(undefined2 *)(param_1 + 0x31a22) = *(undefined2 *)(param_2 + 0x2b);
      *(undefined2 *)(param_1 + 0x31a24) = *(undefined2 *)(param_2 + 0x3a);
      if (param_2[0x17] == '\0') {
        memcpy((void *)(param_1 + 0x31a2c),*(void **)(param_2 + 0x3c),
               (uint)*(ushort *)(param_2 + 0x3a));
        *puVar1 = *(short *)(param_2 + 0x3a) + 0x19;
      }
      else {
        *(byte *)(param_1 + 0x31a1d) = *(byte *)(param_1 + 0x31a1d) | 0x40;
        *puVar1 = 0x19;
      }
    }
    *(undefined4 *)(param_1 + 0x31a0f) = 0;
    FUN_6f6a1193(puVar1);
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x3332a),0xfa);
    *(undefined2 *)(param_1 + 0x33352) = 0xff;
    local_10 = FUN_6f6a89d8(param_1,(short *)(param_1 + 0x3334c),(undefined2 *)(param_1 + 0x3334e),
                            puVar1,(short *)(param_1 + 0x33350));
    if (local_10 == 0) {
      if (*(short *)(param_1 + 0x33350) < 0x10) {
        *(int *)(param_2 + 1) = param_1 + 0x18cf9 + *(short *)(param_1 + 0x33350) * 0x845;
        memset(*(void **)(param_2 + 1),0,0x845);
        *(undefined1 *)(*(int *)(param_2 + 1) + 3) = *(undefined1 *)(param_1 + 0x33350);
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x10) = 1;
        *(undefined1 *)(*(int *)(param_2 + 1) + 1) = 1;
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x82c) = param_2[0x14];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x82d) = param_2[0x15];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x82e) = param_2[0x16];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x82f) = param_2[0x17];
        **(undefined1 **)(param_2 + 1) = *param_2;
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x830) = param_2[0x23];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x831) = param_2[0x24];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x832) = param_2[0x25];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x833) = param_2[0x26];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x834) = param_2[0x27];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x837) = param_2[0x2a];
        *(undefined2 *)(*(int *)(param_2 + 1) + 0x838) = *(undefined2 *)(param_2 + 0x2b);
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x12) = param_2[0x18];
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x1b) = *(undefined4 *)(param_2 + 0x19);
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x23) = *(undefined4 *)(param_2 + 0x1d);
        *(undefined2 *)(*(int *)(param_2 + 1) + 0x27) = *(undefined2 *)(param_2 + 0x21);
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x13) = *(undefined4 *)(param_2 + 0x2d);
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x17) = *(undefined4 *)(param_2 + 0x32);
        *(undefined2 *)(*(int *)(param_2 + 1) + 0x29) = *(undefined2 *)(param_2 + 0x3a);
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x83d) = *(undefined4 *)(param_2 + 0x3c);
        *(undefined4 *)(*(int *)(param_2 + 1) + 0x841) = *(undefined4 *)(param_2 + 0x36);
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x835) = param_2[0x28];
        *(undefined1 *)(*(int *)(param_2 + 1) + 0x836) = param_2[0x29];
        if (param_2[0x2a] == '\0') {
          memcpy((void *)(*(int *)(param_2 + 1) + 0x2b),*(void **)(*(int *)(param_2 + 1) + 0x83d),
                 (uint)*(ushort *)(*(int *)(param_2 + 1) + 0x29));
        }
      }
      else {
        *(undefined4 *)(param_2 + 1) = 0;
        local_10 = 10;
      }
      *(undefined2 *)(param_1 + 0x33352) = 0xff;
      ReleaseMutex(*(HANDLE *)(param_1 + 0x3332a));
    }
    else {
      *(undefined2 *)(param_1 + 0x33352) = 0xff;
      ReleaseMutex(*(HANDLE *)(param_1 + 0x3332a));
    }
  }
  return local_10;
}



// Function: TransmitMailBoxAsync at 6f6a5e82

void TransmitMailBoxAsync(short param_1,char *param_2)

{
                    /* 0x5e82  31  TransmitMailBoxAsync */
  UpdateTransmitMailBoxAsync(param_1,param_2,0x40);
  return;
}



// Function: TransmitMailBox at 6f6a5ea2

void TransmitMailBox(short param_1,char *param_2)

{
                    /* 0x5ea2  30  TransmitMailBox */
  UpdateTransmitMailBox(param_1,param_2,0x40);
  return;
}



// Function: UpdateTransMailBoxDataAsync at 6f6a5ec2

int UpdateTransMailBoxDataAsync(short param_1,char *param_2)

{
  int iVar1;
  
                    /* 0x5ec2  36  UpdateTransMailBoxDataAsync */
  if (*(ushort *)(param_2 + 0x29) < 0x7d1) {
    iVar1 = UpdateTransmitMailBoxAsync(param_1,param_2,1);
  }
  else {
    iVar1 = 5;
  }
  return iVar1;
}



// Function: UpdateTransMailBoxData at 6f6a5efc

int UpdateTransMailBoxData(short param_1,char *param_2)

{
  int iVar1;
  
                    /* 0x5efc  35  UpdateTransMailBoxData */
  if (*(ushort *)(param_2 + 0x29) < 0x7d1) {
    iVar1 = UpdateTransmitMailBox(param_1,param_2,1);
  }
  else {
    iVar1 = 5;
  }
  return iVar1;
}



// Function: UpdateTransmitMailBoxAsync at 6f6a5f36

int UpdateTransmitMailBoxAsync(short param_1,char *param_2,byte param_3)

{
  int local_20;
  int local_1c;
  ushort *local_18;
  undefined1 *local_14;
  undefined1 *local_10;
  uint local_c;
  int local_8;
  
                    /* 0x5f36  38  UpdateTransmitMailBoxAsync */
  local_c = local_c & 0xffff0000;
  local_1c = FUN_6f6a8bed(&local_20,param_1);
  if (local_1c == 0) {
    local_18 = (ushort *)(local_20 + 0x32213);
    local_14 = (undefined1 *)(local_20 + 0x3221d);
    local_1c = FUN_6f6a661f(local_20,param_2);
    if (local_1c == 0) {
      memset((void *)(local_20 + 0x3221d),0,0x800);
      *local_14 = 0xc0;
      local_14[3] = 0x49;
      local_14[4] = *param_2;
      local_14[5] = param_2[3];
      local_14[6] = param_3;
      local_10 = local_14 + 7;
      if ((param_3 & 0x10) == 0x10) {
        memcpy(local_10 + (local_c & 0xffff),param_2 + 0x23,4);
        local_c = CONCAT22(local_c._2_2_,(short)local_c + 4);
      }
      if ((param_3 & 8) == 8) {
        memcpy(local_10 + (local_c & 0xffff),param_2 + 0x27,2);
        local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
      }
      if ((param_3 & 4) == 4) {
        memcpy(local_10 + (local_c & 0xffff),param_2 + 0x1b,4);
        local_c = CONCAT22(local_c._2_2_,(short)local_c + 4);
      }
      if ((param_3 & 2) == 2) {
        if (*param_2 == '\x01') {
          local_10[local_c & 0xffff] = param_2[0x832];
          local_10[(local_c & 0xffff) + 1] = param_2[0x833];
          local_10[(local_c & 0xffff) + 2] = param_2[0x834];
        }
        else if (*param_2 == '\x03') {
          if (param_2[2] == '\x1d') {
            local_8 = *(int *)(param_2 + 6) << 3;
          }
          else {
            local_8 = *(int *)(param_2 + 6) << 0x15;
          }
          FUN_6f6a1160(local_10 + (local_c & 0xffff),(undefined1 *)&local_8);
        }
        else if (*param_2 == '\x02') {
          *(undefined4 *)(local_10 + (local_c & 0xffff)) = *(undefined4 *)(param_2 + 6);
        }
        local_c = CONCAT22(local_c._2_2_,(short)local_c + 4);
      }
      if (((param_3 & 0x80) == 0x80) &&
         (((*param_2 == '\x01' || (*param_2 == '\x03')) || (*param_2 == '\x02')))) {
        if (param_2[0x837] == '\0') {
          if ((*param_2 == '\x03') && (*(ushort *)(param_2 + 0x29) < 9)) {
            param_2[0x838] = -1;
            param_2[0x839] = -1;
            memcpy(local_10 + (local_c & 0xffff),param_2 + 0x838,2);
            local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
          }
          else if ((*param_2 == '\x01') && (*(ushort *)(param_2 + 0x29) < 0x14)) {
            param_2[0x838] = -1;
            param_2[0x839] = -1;
            memcpy(local_10 + (local_c & 0xffff),param_2 + 0x838,2);
            local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
          }
          else {
            if ((*param_2 != '\x02') || (0xb < *(ushort *)(param_2 + 0x29))) {
              return 5;
            }
            param_2[0x838] = -1;
            param_2[0x839] = -1;
            memcpy(local_10 + (local_c & 0xffff),param_2 + 0x838,2);
            local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
          }
        }
        else {
          memcpy(local_10 + (local_c & 0xffff),param_2 + 0x838,2);
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
        }
      }
      if ((param_3 & 0x20) == 0x20) {
        if (*param_2 == '\x01') {
          if (param_2[0x837] == '\0') {
            if (0x13 < *(ushort *)(param_2 + 0x29)) {
              return 5;
            }
            memcpy(local_10 + (local_c & 0xffff),param_2 + 0x29,2);
          }
          else {
            memcpy(local_10 + (local_c & 0xffff),param_2 + 0x29,2);
          }
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
        }
        else if (*param_2 == '\x03') {
          if (param_2[0x837] == '\0') {
            if (8 < *(ushort *)(param_2 + 0x29)) {
              return 5;
            }
            memcpy(local_10 + (local_c & 0xffff),param_2 + 0x29,2);
          }
          else {
            memcpy(local_10 + (local_c & 0xffff),param_2 + 0x29,2);
          }
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
        }
        else if (*param_2 == '\x02') {
          if (param_2[0x837] == '\0') {
            if (0xb < *(ushort *)(param_2 + 0x29)) {
              return 5;
            }
            memcpy(local_10 + (local_c & 0xffff),param_2 + 0x29,2);
          }
          else {
            memcpy(local_10 + (local_c & 0xffff),param_2 + 0x29,2);
          }
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
        }
      }
      if (((param_3 & 1) == 1) &&
         (((*param_2 == '\x01' || (*param_2 == '\x03')) || (*param_2 == '\x02')))) {
        if (param_2[0x837] == '\0') {
          memcpy(local_10 + (local_c & 0xffff),*(void **)(param_2 + 0x83d),
                 (uint)*(ushort *)(param_2 + 0x29));
          local_c = CONCAT22(local_c._2_2_,(short)local_c + *(short *)(param_2 + 0x29));
          memcpy(param_2 + 0x2b,*(void **)(param_2 + 0x83d),(uint)*(ushort *)(param_2 + 0x29));
        }
        else if (param_2[0x82f] == '\0') {
          memcpy(local_10 + (local_c & 0xffff),*(void **)(param_2 + 0x83d),
                 (uint)*(ushort *)(param_2 + 0x29));
          local_c = CONCAT22(local_c._2_2_,(short)local_c + *(short *)(param_2 + 0x29));
          memcpy(param_2 + 0x2b,*(void **)(param_2 + 0x83d),(uint)*(ushort *)(param_2 + 0x29));
        }
        else {
          local_14[6] = local_14[6] & 0xfe;
        }
      }
      *local_18 = (short)local_c + 7;
      *(char **)(local_18 + 3) = param_2;
      FUN_6f6a1193(local_18);
      local_1c = FUN_6f6aa406(*(int *)(local_20 + 4),local_18);
    }
  }
  return local_1c;
}



// Function: FUN_6f6a661f at 6f6a661f

undefined4 __cdecl FUN_6f6a661f(int param_1,char *param_2)

{
  if (param_2 == (char *)0x0) {
    return 6;
  }
  if (*param_2 == '\x03') {
    if (0xf < (byte)param_2[3]) {
      return 6;
    }
    if (param_2[1] == '\0') {
      return 9;
    }
    if ((param_2[0x10] == '\0') &&
       (param_2 != (char *)(param_1 + 9 + (uint)(byte)param_2[3] * 0x845))) {
      return 6;
    }
    if ((param_2[0x10] == '\x01') &&
       (param_2 != (char *)(param_1 + 0x8459 + (uint)(byte)param_2[3] * 0x845))) {
      return 6;
    }
  }
  else if (*param_2 == '\x01') {
    if (0xf < (byte)param_2[3]) {
      return 6;
    }
    if (param_2[1] == '\0') {
      return 9;
    }
    if ((param_2[0x10] == '\0') &&
       (param_2 != (char *)(param_1 + 0x108a9 + (uint)(byte)param_2[3] * 0x845))) {
      return 6;
    }
    if ((param_2[0x10] == '\x01') &&
       (param_2 != (char *)(param_1 + 0x18cf9 + (uint)(byte)param_2[3] * 0x845))) {
      return 6;
    }
  }
  else if (*param_2 == '\x02') {
    if (0xf < (byte)param_2[3]) {
      return 6;
    }
    if (param_2[1] == '\0') {
      return 9;
    }
    if ((param_2[0x10] == '\0') &&
       (param_2 != (char *)(param_1 + 0x21149 + (uint)(byte)param_2[3] * 0x845))) {
      return 6;
    }
    if ((param_2[0x10] == '\x01') &&
       (param_2 != (char *)(param_1 + 0x29599 + (uint)(byte)param_2[3] * 0x845))) {
      return 6;
    }
  }
  return 0;
}



// Function: UpdateTransmitMailBox at 6f6a681d

int UpdateTransmitMailBox(short param_1,char *param_2,byte param_3)

{
  int local_20;
  int local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  ushort *local_10;
  uint local_c;
  int local_8;
  
                    /* 0x681d  37  UpdateTransmitMailBox */
  local_c = local_c & 0xffff0000;
  local_1c = FUN_6f6a8bed(&local_20,param_1);
  if (local_1c == 0) {
    local_10 = (ushort *)(local_20 + 0x31a09);
    local_18 = (undefined1 *)(local_20 + 0x31a13);
    local_1c = FUN_6f6a661f(local_20,param_2);
    if (local_1c == 0) {
      memset(local_10 + 5,0,0x800);
      *local_18 = 0x80;
      local_18[3] = 0x49;
      local_18[4] = *param_2;
      local_18[5] = param_2[3];
      local_18[6] = param_3;
      local_14 = local_18 + 7;
      if ((param_3 & 0x10) == 0x10) {
        memcpy(local_14 + (local_c & 0xffff),param_2 + 0x23,4);
        local_c = CONCAT22(local_c._2_2_,(short)local_c + 4);
      }
      if ((param_3 & 8) == 8) {
        memcpy(local_14 + (local_c & 0xffff),param_2 + 0x27,2);
        local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
      }
      if ((param_3 & 4) == 4) {
        memcpy(local_14 + (local_c & 0xffff),param_2 + 0x1b,4);
        local_c = CONCAT22(local_c._2_2_,(short)local_c + 4);
      }
      if ((param_3 & 2) == 2) {
        if (*param_2 == '\x01') {
          local_14[local_c & 0xffff] = param_2[0x832];
          local_14[(local_c & 0xffff) + 1] = param_2[0x833];
          local_14[(local_c & 0xffff) + 2] = param_2[0x834];
        }
        else if (*param_2 == '\x03') {
          if (param_2[2] == '\x1d') {
            local_8 = *(int *)(param_2 + 6) << 3;
          }
          else {
            local_8 = *(int *)(param_2 + 6) << 0x15;
          }
          FUN_6f6a1160(local_14 + (local_c & 0xffff),(undefined1 *)&local_8);
        }
        else if (*param_2 == '\x02') {
          *(undefined4 *)(local_14 + (local_c & 0xffff)) = *(undefined4 *)(param_2 + 6);
        }
        local_c = CONCAT22(local_c._2_2_,(short)local_c + 4);
      }
      if (((param_3 & 0x80) == 0x80) &&
         (((*param_2 == '\x01' || (*param_2 == '\x03')) || (*param_2 == '\x02')))) {
        if (param_2[0x837] == '\0') {
          if ((*param_2 == '\x03') && (*(ushort *)(param_2 + 0x29) < 9)) {
            param_2[0x838] = -1;
            param_2[0x839] = -1;
            memcpy(local_14 + (local_c & 0xffff),param_2 + 0x838,2);
            local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
          }
          else if ((*param_2 == '\x01') && (*(ushort *)(param_2 + 0x29) < 0x14)) {
            param_2[0x838] = -1;
            param_2[0x839] = -1;
            memcpy(local_14 + (local_c & 0xffff),param_2 + 0x838,2);
            local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
          }
          else {
            if ((*param_2 != '\x02') || (0xb < *(ushort *)(param_2 + 0x29))) {
              return 5;
            }
            param_2[0x838] = -1;
            param_2[0x839] = -1;
            memcpy(local_14 + (local_c & 0xffff),param_2 + 0x838,2);
            local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
          }
        }
        else {
          memcpy(local_14 + (local_c & 0xffff),param_2 + 0x838,2);
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
        }
      }
      if ((param_3 & 0x20) == 0x20) {
        if (*param_2 == '\x01') {
          if (param_2[0x837] == '\0') {
            if (0x13 < *(ushort *)(param_2 + 0x29)) {
              return 5;
            }
            memcpy(local_14 + (local_c & 0xffff),param_2 + 0x29,2);
          }
          else {
            memcpy(local_14 + (local_c & 0xffff),param_2 + 0x29,2);
          }
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
        }
        else if (*param_2 == '\x03') {
          if (param_2[0x837] == '\0') {
            if (8 < *(ushort *)(param_2 + 0x29)) {
              return 5;
            }
            memcpy(local_14 + (local_c & 0xffff),param_2 + 0x29,2);
          }
          else {
            memcpy(local_14 + (local_c & 0xffff),param_2 + 0x29,2);
          }
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
        }
        else if (*param_2 == '\x02') {
          if (param_2[0x837] == '\0') {
            if (0xb < *(ushort *)(param_2 + 0x29)) {
              return 5;
            }
            memcpy(local_14 + (local_c & 0xffff),param_2 + 0x29,2);
          }
          else {
            memcpy(local_14 + (local_c & 0xffff),param_2 + 0x29,2);
          }
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
        }
      }
      if (((param_3 & 1) == 1) &&
         (((*param_2 == '\x01' || (*param_2 == '\x03')) || (*param_2 == '\x02')))) {
        if (param_2[0x837] == '\0') {
          memcpy(local_14 + (local_c & 0xffff),*(void **)(param_2 + 0x83d),
                 (uint)*(ushort *)(param_2 + 0x29));
          local_c = CONCAT22(local_c._2_2_,(short)local_c + *(short *)(param_2 + 0x29));
          memcpy(param_2 + 0x2b,*(void **)(param_2 + 0x83d),(uint)*(ushort *)(param_2 + 0x29));
        }
        else if (param_2[0x82f] == '\0') {
          memcpy(local_14 + (local_c & 0xffff),*(void **)(param_2 + 0x83d),
                 (uint)*(ushort *)(param_2 + 0x29));
          local_c = CONCAT22(local_c._2_2_,(short)local_c + *(short *)(param_2 + 0x29));
        }
        else {
          local_18[6] = local_18[6] & 0xfe;
        }
      }
      *local_10 = (short)local_c + 7;
      *(char **)(local_10 + 3) = param_2;
      FUN_6f6a1193(local_10);
      local_1c = FUN_6f6a89d8(local_20,(short *)(local_20 + 0x33354),
                              (undefined2 *)(local_20 + 0x33356),local_10,(short *)0x0);
    }
  }
  return local_1c;
}



// Function: UpdateReceiveMailBoxAsync at 6f6a6ef0

int UpdateReceiveMailBoxAsync(short param_1,char *param_2,byte param_3)

{
  int local_20;
  int local_1c;
  ushort *local_18;
  undefined1 *local_14;
  undefined1 *local_10;
  uint local_c;
  int local_8;
  
                    /* 0x6ef0  34  UpdateReceiveMailBoxAsync */
  local_c = local_c & 0xffff0000;
  local_1c = FUN_6f6a8bed(&local_20,param_1);
  if (local_1c == 0) {
    local_18 = (ushort *)(local_20 + 0x32213);
    local_14 = (undefined1 *)(local_20 + 0x3221d);
    local_1c = FUN_6f6a661f(local_20,param_2);
    if (local_1c == 0) {
      memset(local_18 + 5,0,0x800);
      *local_14 = 0xc0;
      local_14[3] = 0x48;
      local_14[4] = *param_2;
      local_14[5] = param_2[3];
      local_14[6] = param_3;
      local_10 = local_14 + 7;
      if ((param_3 & 2) == 2) {
        if (*param_2 == '\x01') {
          local_10[local_c & 0xffff] = param_2[0x833];
          local_14[(local_c & 0xffff) + 8] = param_2[0x834];
        }
        else if (*param_2 == '\x03') {
          if (param_2[2] == '\x1d') {
            local_8 = *(int *)(param_2 + 6) << 3;
          }
          else {
            local_8 = *(int *)(param_2 + 6) << 0x15;
          }
          FUN_6f6a1160(local_10 + (local_c & 0xffff),(undefined1 *)&local_8);
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 4);
        }
        else if (*param_2 == '\x02') {
          *(undefined4 *)(local_10 + (local_c & 0xffff)) = *(undefined4 *)(param_2 + 6);
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 4);
        }
      }
      if ((param_3 & 0x10) == 0x10) {
        if (*param_2 == '\x01') {
          local_10[(local_c & 0xffff) + 2] = param_2[0x835];
          local_10[(local_c & 0xffff) + 3] = param_2[0x836];
        }
        else if (*param_2 == '\x03') {
          if (param_2[2] == '\x1d') {
            local_8 = *(int *)(param_2 + 0xb) << 3;
          }
          else {
            local_8 = *(int *)(param_2 + 0xb) << 0x15;
          }
          FUN_6f6a1160(local_10 + (local_c & 0xffff),(undefined1 *)&local_8);
        }
        else if (*param_2 == '\x02') {
          FUN_6f6a1160(local_10 + (local_c & 0xffff),param_2 + 0xb);
        }
        local_c = CONCAT22(local_c._2_2_,(short)local_c + 4);
      }
      if (((param_3 & 0x80) == 0x80) &&
         (((*param_2 == '\x01' || (*param_2 == '\x03')) || (*param_2 == '\x02')))) {
        if (param_2[0x837] == '\0') {
          if ((*param_2 == '\x03') && (*(ushort *)(param_2 + 0x29) < 9)) {
            param_2[0x838] = -1;
            param_2[0x839] = -1;
            memcpy(local_10 + (local_c & 0xffff),param_2 + 0x838,2);
            local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
          }
          else if ((*param_2 == '\x01') && (*(ushort *)(param_2 + 0x29) < 0x14)) {
            param_2[0x838] = -1;
            param_2[0x839] = -1;
            memcpy(local_10 + (local_c & 0xffff),param_2 + 0x838,2);
            local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
          }
          else {
            if ((*param_2 != '\x02') || (0xb < *(ushort *)(param_2 + 0x29))) {
              return 5;
            }
            param_2[0x838] = -1;
            param_2[0x839] = -1;
            memcpy(local_10 + (local_c & 0xffff),param_2 + 0x838,2);
            local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
          }
        }
        else {
          memcpy(local_10 + (local_c & 0xffff),param_2 + 0x838,2);
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
        }
      }
      if ((param_3 & 0x20) == 0x20) {
        if (*param_2 == '\x01') {
          if (param_2[0x837] == '\0') {
            if (0x13 < *(ushort *)(param_2 + 0x29)) {
              return 5;
            }
            memcpy(local_10 + (local_c & 0xffff),param_2 + 0x29,2);
          }
          else {
            memcpy(local_10 + (local_c & 0xffff),param_2 + 0x29,2);
          }
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
        }
        else if (*param_2 == '\x03') {
          if (param_2[0x837] == '\0') {
            if (8 < *(ushort *)(param_2 + 0x29)) {
              return 5;
            }
            memcpy(local_10 + (local_c & 0xffff),param_2 + 0x29,2);
          }
          else {
            memcpy(local_10 + (local_c & 0xffff),param_2 + 0x29,2);
          }
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
        }
        else if (*param_2 == '\x02') {
          if (param_2[0x837] == '\0') {
            if (0xb < *(ushort *)(param_2 + 0x29)) {
              return 5;
            }
            memcpy(local_10 + (local_c & 0xffff),param_2 + 0x29,2);
          }
          else {
            memcpy(local_10 + (local_c & 0xffff),param_2 + 0x29,2);
          }
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
        }
      }
      *local_18 = (short)local_c + 7;
      *(char **)(local_18 + 3) = param_2;
      FUN_6f6a1193(local_18);
      local_1c = FUN_6f6aa406(*(int *)(local_20 + 4),local_18);
    }
  }
  return local_1c;
}



// Function: UpdateReceiveMailBox at 6f6a74c2

int UpdateReceiveMailBox(short param_1,char *param_2,byte param_3)

{
  int local_20;
  int local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  ushort *local_10;
  uint local_c;
  int local_8;
  
                    /* 0x74c2  33  UpdateReceiveMailBox */
  local_c = local_c & 0xffff0000;
  local_1c = FUN_6f6a8bed(&local_20,param_1);
  if (local_1c == 0) {
    local_10 = (ushort *)(local_20 + 0x31a09);
    local_18 = (undefined1 *)(local_20 + 0x31a13);
    local_1c = FUN_6f6a661f(local_20,param_2);
    if (local_1c == 0) {
      memset(local_10 + 5,0,0x800);
      *local_18 = 0x80;
      local_18[3] = 0x48;
      local_18[4] = *param_2;
      local_18[5] = param_2[3];
      local_18[6] = param_3;
      local_14 = local_18 + 7;
      if ((param_3 & 2) == 2) {
        if (*param_2 == '\x01') {
          local_14[local_c & 0xffff] = param_2[0x833];
          local_18[(local_c & 0xffff) + 8] = param_2[0x834];
        }
        else if (*param_2 == '\x03') {
          if (param_2[2] == '\x1d') {
            local_8 = *(int *)(param_2 + 6) << 3;
          }
          else {
            local_8 = *(int *)(param_2 + 6) << 0x15;
          }
          FUN_6f6a1160(local_14 + (local_c & 0xffff),(undefined1 *)&local_8);
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 4);
        }
        else if (*param_2 == '\x02') {
          *(undefined4 *)(local_14 + (local_c & 0xffff)) = *(undefined4 *)(param_2 + 6);
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 4);
        }
      }
      if ((param_3 & 0x10) == 0x10) {
        if (*param_2 == '\x01') {
          local_14[(local_c & 0xffff) + 2] = param_2[0x835];
          local_14[(local_c & 0xffff) + 3] = param_2[0x836];
        }
        else if (*param_2 == '\x03') {
          if (param_2[2] == '\x1d') {
            local_8 = *(int *)(param_2 + 0xb) << 3;
          }
          else {
            local_8 = *(int *)(param_2 + 0xb) << 0x15;
          }
          FUN_6f6a1160(local_14 + (local_c & 0xffff),(undefined1 *)&local_8);
        }
        else if (*param_2 == '\x02') {
          *(undefined4 *)(local_14 + (local_c & 0xffff)) = *(undefined4 *)(param_2 + 0xb);
        }
        local_c = CONCAT22(local_c._2_2_,(short)local_c + 4);
      }
      if (((param_3 & 0x80) == 0x80) &&
         (((*param_2 == '\x01' || (*param_2 == '\x03')) || (*param_2 == '\x02')))) {
        if (param_2[0x837] == '\0') {
          if ((*param_2 == '\x03') && (*(ushort *)(param_2 + 0x29) < 9)) {
            param_2[0x838] = -1;
            param_2[0x839] = -1;
            memcpy(local_14 + (local_c & 0xffff),param_2 + 0x838,2);
            local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
          }
          else if ((*param_2 == '\x01') && (*(ushort *)(param_2 + 0x29) < 0x14)) {
            param_2[0x838] = -1;
            param_2[0x839] = -1;
            memcpy(local_14 + (local_c & 0xffff),param_2 + 0x838,2);
            local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
          }
          else {
            if ((*param_2 != '\x02') || (0xb < *(ushort *)(param_2 + 0x29))) {
              return 5;
            }
            param_2[0x838] = -1;
            param_2[0x839] = -1;
            memcpy(local_14 + (local_c & 0xffff),param_2 + 0x838,2);
            local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
          }
        }
        else {
          memcpy(local_14 + (local_c & 0xffff),param_2 + 0x838,2);
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
        }
      }
      if ((param_3 & 0x20) == 0x20) {
        if (*param_2 == '\x01') {
          if (param_2[0x837] == '\0') {
            if (0x13 < *(ushort *)(param_2 + 0x29)) {
              return 5;
            }
            memcpy(local_14 + (local_c & 0xffff),param_2 + 0x29,2);
          }
          else {
            memcpy(local_14 + (local_c & 0xffff),param_2 + 0x29,2);
          }
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
        }
        else if (*param_2 == '\x03') {
          if (param_2[0x837] == '\0') {
            if (8 < *(ushort *)(param_2 + 0x29)) {
              return 5;
            }
            memcpy(local_14 + (local_c & 0xffff),param_2 + 0x29,2);
          }
          else {
            memcpy(local_14 + (local_c & 0xffff),param_2 + 0x29,2);
          }
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
        }
        else if (*param_2 == '\x02') {
          if (param_2[0x837] == '\0') {
            if (0xb < *(ushort *)(param_2 + 0x29)) {
              return 5;
            }
            memcpy(local_14 + (local_c & 0xffff),param_2 + 0x29,2);
          }
          else {
            memcpy(local_14 + (local_c & 0xffff),param_2 + 0x29,2);
          }
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 2);
        }
      }
      *local_10 = (short)local_c + 7;
      *(char **)(local_10 + 3) = param_2;
      FUN_6f6a1193(local_10);
      local_1c = FUN_6f6a89d8(local_20,(short *)(local_20 + 0x3338c),
                              (undefined2 *)(local_20 + 0x3338e),local_10,(short *)0x0);
    }
  }
  return local_1c;
}



// Function: ReceiveMailBox at 6f6a7aa4

int ReceiveMailBox(short param_1,char *param_2)

{
  int local_14;
  int local_10;
  undefined1 *local_c;
  ushort *local_8;
  
                    /* 0x7aa4  21  ReceiveMailBox */
  local_10 = FUN_6f6a8bed(&local_14,param_1);
  if (local_10 == 0) {
    local_8 = (ushort *)(local_14 + 0x31a09);
    local_c = (undefined1 *)(local_14 + 0x31a13);
    local_10 = FUN_6f6a661f(local_14,param_2);
    if (local_10 == 0) {
      if (((((param_2[0x82c] == '\0') && (param_2[0x82d] == '\0')) && (param_2[0x82e] == '\0')) &&
          (param_2[0x82f] == '\0')) &&
         ((*(int *)(param_2 + 0x13) != 0 ||
          ((param_2[0x82b] != '\0' && (*(int *)(param_2 + 0x83d) != 0)))))) {
        if ((param_2[0x82b] != '\0') && (*(int *)(param_2 + 0x83d) != 0)) {
          memcpy(*(void **)(param_2 + 0x83d),param_2 + 0x2b,(uint)*(ushort *)(param_2 + 0x29));
        }
        if (*(int *)(param_2 + 0x13) != 0) {
          (**(code **)(param_2 + 0x13))(param_2);
        }
      }
      else {
        *local_c = 0x80;
        local_c[3] = 4;
        *(ushort *)(local_c + 4) = CONCAT11(param_2[3],*param_2);
        local_c[6] = 0;
        if ((param_2[0x82e] == '\0') && (param_2[0x82f] == '\0')) {
          if ((*param_2 == '\x01') && (param_2[0x837] != '\0')) {
            local_c[6] = local_c[6] | 0xa0;
          }
          else {
            local_c[6] = local_c[6] | 1;
          }
        }
        if (param_2[0x82d] == '\0') {
          local_c[6] = local_c[6] | 2;
        }
        if (param_2[0x82c] == '\0') {
          local_c[6] = local_c[6] | 4;
        }
        param_2[0x83b] = local_c[6];
        *local_8 = 7;
        *(char **)(local_8 + 3) = param_2;
        FUN_6f6a1193(local_8);
        param_2[0x83c] = '\0';
        param_2[0x83a] = '\x01';
        ResetEvent(*(HANDLE *)(local_14 + 0x33326));
        local_10 = FUN_6f6a89d8(local_14,(short *)(local_14 + 0x33358),
                                (undefined2 *)(local_14 + 0x3335a),local_8,(short *)0x0);
        if ((local_10 != 0) && (local_10 != 1)) {
          return local_10;
        }
        if (local_10 == 0) {
          WaitForSingleObject(*(HANDLE *)(local_14 + 0x33326),0xfa);
          if ((param_2[0x83c] == '\0') && (local_10 == 0)) {
            local_10 = 1;
          }
          if ((local_10 == 0) && (*(int *)(param_2 + 0x83d) != 0)) {
            memcpy(*(void **)(param_2 + 0x83d),param_2 + 0x2b,(uint)*(ushort *)(param_2 + 0x29));
          }
        }
      }
      param_2[0x83a] = '\0';
    }
  }
  return local_10;
}



// Function: UnloadMailBox at 6f6a7d91

int UnloadMailBox(short param_1,char *param_2)

{
  int iVar1;
  int local_14;
  undefined1 *local_10;
  int local_c;
  ushort *local_8;
  
                    /* 0x7d91  32  UnloadMailBox */
  local_c = FUN_6f6a8bed(&local_14,param_1);
  if (local_c == 0) {
    local_8 = (ushort *)(local_14 + 0x31a09);
    local_10 = (undefined1 *)(local_14 + 0x31a13);
    local_c = FUN_6f6a661f(local_14,param_2);
    if (local_c == 0) {
      if ((*param_2 == '\x01') && ((param_2[0x830] == '\x02' || (param_2[0x830] == '\x03')))) {
        local_c = 0x18;
      }
      else {
        *local_10 = 0x80;
        if (param_2[0x10] == '\0') {
          local_10[3] = 6;
        }
        else {
          local_10[3] = 7;
        }
        *(ushort *)(local_10 + 4) = CONCAT11(param_2[3],*param_2);
        *local_8 = 6;
        *(char **)(local_8 + 3) = param_2;
        FUN_6f6a1193(local_8);
        local_c = FUN_6f6a89d8(local_14,(short *)(local_14 + 0x3335c),
                               (undefined2 *)(local_14 + 0x3335e),local_8,(short *)0x0);
        if (((local_c == 0) || (local_c == 1)) && (local_c == 0)) {
          if (*param_2 == '\x01') {
            param_2[1] = '\0';
            while ((param_2[0x830] != '\0' && ((byte)param_2[3] < 0x10))) {
              param_2 = (char *)(local_14 + 0x18cf9 + (uint)(byte)param_2[3] * 0x845);
              iVar1 = FUN_6f6a661f(local_14,param_2);
              if ((iVar1 != 0) || (param_2[1] = '\0', param_2[0x830] != '\x03')) break;
            }
            if ((param_2[0x830] == '\x02') || (param_2[0x830] == '\x03')) {
              local_c = 0x18;
            }
          }
          else {
            param_2[1] = '\0';
          }
        }
      }
    }
  }
  return local_c;
}



// Function: LoadTimer at 6f6a7f84

int LoadTimer(short param_1,undefined4 param_2)

{
  int local_14;
  int local_10;
  undefined1 *local_c;
  ushort *local_8;
  
                    /* 0x7f84  17  LoadTimer */
  local_10 = FUN_6f6a8bed(&local_14,param_1);
  if (local_10 == 0) {
    local_8 = (ushort *)(local_14 + 0x31a09);
    local_c = (undefined1 *)(local_14 + 0x31a13);
    *local_c = 0x80;
    *(undefined1 *)(local_14 + 0x31a16) = 0x12;
    *(undefined4 *)(local_14 + 0x31a17) = param_2;
    *local_8 = 8;
    *(undefined4 *)(local_14 + 0x31a0f) = 0;
    FUN_6f6a1193(local_8);
    local_10 = FUN_6f6a89d8(local_14,(short *)(local_14 + 0x33360),
                            (undefined2 *)(local_14 + 0x33362),local_8,(short *)0x0);
  }
  return local_10;
}



// Function: EnableTimerInterrupt at 6f6a801f

int EnableTimerInterrupt(short param_1,uint *param_2)

{
  int local_10;
  int local_c;
  ushort *local_8;
  
                    /* 0x801f  7  EnableTimerInterrupt */
  local_c = FUN_6f6a8bed(&local_10,param_1);
  if (local_c == 0) {
    local_8 = (ushort *)(local_10 + 0x31a09);
    if (*param_2 < 0xea61) {
      *(undefined1 *)(local_10 + 0x31a13) = 0x80;
      *(undefined1 *)(local_10 + 0x31a16) = 0x13;
      *(uint *)(local_10 + 0x31a17) = *param_2;
      *local_8 = 8;
      *(undefined4 *)(local_10 + 0x31a0f) = 0;
      FUN_6f6a1193(local_8);
      local_c = FUN_6f6a89d8(local_10,(short *)(local_10 + 0x33364),
                             (undefined2 *)(local_10 + 0x33366),local_8,(short *)0x0);
      if (local_c == 0) {
        *(uint *)(local_10 + 0x319e9) = param_2[1];
      }
    }
    else {
      local_c = 0xc;
    }
  }
  return local_c;
}



// Function: SuspendTimerInterrupt at 6f6a80ec

int SuspendTimerInterrupt(short param_1)

{
  int local_14;
  undefined1 *local_10;
  int local_c;
  ushort *local_8;
  
                    /* 0x80ec  29  SuspendTimerInterrupt */
  local_c = FUN_6f6a8bed(&local_14,param_1);
  if (local_c == 0) {
    local_8 = (ushort *)(local_14 + 0x31a09);
    local_10 = (undefined1 *)(local_14 + 0x31a13);
    *(undefined4 *)(local_14 + 0x319e9) = 0;
    *local_10 = 0x80;
    *(undefined1 *)(local_14 + 0x31a16) = 0x14;
    *local_8 = 4;
    *(undefined4 *)(local_14 + 0x31a0f) = 0;
    FUN_6f6a1193(local_8);
    local_c = FUN_6f6a89d8(local_14,(short *)(local_14 + 0x33368),(undefined2 *)(local_14 + 0x3336a)
                           ,local_8,(short *)0x0);
  }
  return local_c;
}



// Function: PauseTimer at 6f6a818b

int PauseTimer(short param_1)

{
  int local_14;
  undefined1 *local_10;
  int local_c;
  ushort *local_8;
  
                    /* 0x818b  18  PauseTimer */
  local_c = FUN_6f6a8bed(&local_14,param_1);
  if (local_c == 0) {
    local_8 = (ushort *)(local_14 + 0x31a09);
    local_10 = (undefined1 *)(local_14 + 0x31a13);
    *local_10 = 0x80;
    *(undefined1 *)(local_14 + 0x31a16) = 0x16;
    *local_8 = 4;
    *(undefined4 *)(local_14 + 0x31a0f) = 0;
    FUN_6f6a1193(local_8);
    local_c = FUN_6f6a89d8(local_14,(short *)(local_14 + 0x3336c),(undefined2 *)(local_14 + 0x3336e)
                           ,local_8,(short *)0x0);
  }
  return local_c;
}



// Function: ResumeTimer at 6f6a821e

int ResumeTimer(short param_1)

{
  int local_10;
  int local_c;
  ushort *local_8;
  
                    /* 0x821e  27  ResumeTimer */
  local_c = FUN_6f6a8bed(&local_10,param_1);
  if (local_c == 0) {
    local_8 = (ushort *)(local_10 + 0x31a09);
    *(undefined1 *)(local_10 + 0x31a13) = 0x80;
    *(undefined1 *)(local_10 + 0x31a16) = 0x17;
    *local_8 = 4;
    *(undefined4 *)(local_10 + 0x31a0f) = 0;
    FUN_6f6a1193(local_8);
    local_c = FUN_6f6a89d8(local_10,(short *)(local_10 + 0x33370),(undefined2 *)(local_10 + 0x33372)
                           ,local_8,(short *)0x0);
  }
  return local_c;
}



// Function: RequestTimerValue at 6f6a82b1

int RequestTimerValue(short param_1,undefined4 *param_2)

{
  int local_14;
  int local_10;
  undefined1 *local_c;
  ushort *local_8;
  
                    /* 0x82b1  22  RequestTimerValue */
  local_10 = FUN_6f6a8bed(&local_14,param_1);
  if (local_10 == 0) {
    local_8 = (ushort *)(local_14 + 0x31a09);
    local_c = (undefined1 *)(local_14 + 0x31a13);
    *local_c = 0x80;
    *(undefined1 *)(local_14 + 0x31a16) = 0x15;
    *local_8 = 4;
    *(undefined4 *)(local_14 + 0x31a0f) = 0;
    FUN_6f6a1193(local_8);
    *(undefined2 *)(local_14 + 0x33382) = 0;
    ResetEvent(*(HANDLE *)(local_14 + 0x33322));
    local_10 = FUN_6f6a89d8(local_14,(short *)(local_14 + 0x3337e),
                            (undefined2 *)(local_14 + 0x33380),local_8,(short *)0x0);
    if (local_10 == 0) {
      WaitForSingleObject(*(HANDLE *)(local_14 + 0x33322),0xfa);
      if ((*(short *)(local_14 + 0x33382) == 0) && (local_10 == 0)) {
        local_10 = 1;
      }
      if (local_10 == 0) {
        *param_2 = *(undefined4 *)(local_14 + 0x33384);
      }
      else {
        *param_2 = 0;
      }
    }
    else {
      *param_2 = 0;
    }
  }
  return local_10;
}



// Function: ReadDPAChecksum at 6f6a83c9

int ReadDPAChecksum(short param_1,undefined4 *param_2)

{
  int local_14;
  int local_10;
  ushort *local_c;
  undefined1 *local_8;
  
                    /* 0x83c9  20  ReadDPAChecksum */
  local_10 = FUN_6f6a8bed(&local_14,param_1);
  if (local_10 == 0) {
    local_c = (ushort *)(local_14 + 0x31a09);
    local_8 = (undefined1 *)(local_14 + 0x31a13);
    *local_8 = 0x80;
    *(undefined1 *)(local_14 + 0x31a16) = 0x32;
    *local_c = 4;
    *(undefined4 *)(local_14 + 0x31a0f) = 0;
    FUN_6f6a1193(local_c);
    *(undefined2 *)(local_14 + 0x33378) = 0;
    ResetEvent(*(HANDLE *)(local_14 + 0x3331e));
    local_10 = FUN_6f6a89d8(local_14,(short *)(local_14 + 0x33374),
                            (undefined2 *)(local_14 + 0x33376),local_c,(short *)0x0);
    if ((local_10 == 0) || (local_10 == 1)) {
      if (local_10 == 0) {
        WaitForSingleObject(*(HANDLE *)(local_14 + 0x33322),0xfa);
        if ((*(short *)(local_14 + 0x33378) == 0) && (local_10 == 0)) {
          local_10 = 1;
        }
        if (local_10 == 0) {
          *param_2 = *(undefined4 *)(local_14 + 0x3337a);
        }
        else {
          *param_2 = 0;
        }
      }
      else {
        *param_2 = 0;
      }
    }
  }
  return local_10;
}



// Function: ConfigureTransportProtocol at 6f6a84f2

int ConfigureTransportProtocol(short param_1,undefined1 *param_2)

{
  int local_10;
  int local_c;
  ushort *local_8;
  
                    /* 0x84f2  6  ConfigureTransportProtocol */
  local_c = FUN_6f6a8bed(&local_10,param_1);
  if (local_c == 0) {
    local_8 = (ushort *)(local_10 + 0x31a09);
    *(undefined1 *)(local_10 + 0x31a13) = 0x80;
    *(undefined1 *)(local_10 + 0x31a16) = 0x40;
    *(undefined1 *)(local_10 + 0x31a17) = *param_2;
    *local_8 = 0x19;
    *(ushort *)(local_10 + 0x31a18) = *(ushort *)(param_2 + 1) / 10;
    *(undefined2 *)(local_10 + 0x31a1a) = *(undefined2 *)(param_2 + 3);
    *(undefined2 *)(local_10 + 0x31a1c) = *(undefined2 *)(param_2 + 5);
    *(undefined2 *)(local_10 + 0x31a1e) = *(undefined2 *)(param_2 + 7);
    *(undefined2 *)(local_10 + 0x31a20) = *(undefined2 *)(param_2 + 9);
    *(ushort *)(local_10 + 0x31a22) = *(ushort *)(param_2 + 0xb) / 10;
    *(undefined2 *)(local_10 + 0x31a24) = *(undefined2 *)(param_2 + 0xd);
    *(ushort *)(local_10 + 0x31a26) = *(ushort *)(param_2 + 0xf) / 10;
    *(ushort *)(local_10 + 0x31a28) = *(ushort *)(param_2 + 0x11) / 10;
    *(undefined1 *)(local_10 + 0x31a2a) = param_2[0x13];
    *(undefined1 *)(local_10 + 0x31a2b) = param_2[0x14];
    *(undefined4 *)(local_10 + 0x31a0f) = 0;
    FUN_6f6a1193(local_8);
    local_c = FUN_6f6a89d8(local_10,(short *)(local_10 + 0x33388),(undefined2 *)(local_10 + 0x3338a)
                           ,local_8,(short *)0x0);
  }
  return local_c;
}



// Function: WriteDisplay at 6f6a865c

int WriteDisplay(short param_1,char *param_2)

{
  ushort uVar1;
  ushort uVar2;
  void *pvVar3;
  size_t sVar4;
  int local_14;
  int local_10;
  undefined1 *local_c;
  ushort *local_8;
  
                    /* 0x865c  39  WriteDisplay */
  local_10 = FUN_6f6a8bed(&local_14,param_1);
  if (local_10 == 0) {
    local_8 = (ushort *)(local_14 + 0x31a09);
    local_c = (undefined1 *)(local_14 + 0x31a13);
    *local_c = 0x80;
    if (*param_2 == '\0') {
      *(undefined1 *)(local_14 + 0x31a16) = 0x24;
    }
    else {
      if (*param_2 != '\x01') {
        return 0x2f;
      }
      *(undefined1 *)(local_14 + 0x31a16) = 0x25;
    }
    *local_8 = 5;
    pvVar3 = (void *)(local_14 + 0x31a17);
    sVar4 = strlen(*(char **)(param_2 + 1));
    uVar1 = (short)sVar4 + 1;
    memcpy(pvVar3,*(void **)(param_2 + 1),(uint)uVar1);
    pvVar3 = (void *)((int)pvVar3 + (uint)uVar1);
    *local_8 = *local_8 + uVar1;
    sVar4 = strlen(*(char **)(param_2 + 5));
    uVar1 = (short)sVar4 + 1;
    memcpy(pvVar3,*(void **)(param_2 + 5),(uint)uVar1);
    pvVar3 = (void *)((int)pvVar3 + (uint)uVar1);
    *local_8 = *local_8 + uVar1;
    sVar4 = strlen(*(char **)(param_2 + 9));
    uVar1 = (short)sVar4 + 1;
    memcpy(pvVar3,*(void **)(param_2 + 9),(uint)uVar1);
    *local_8 = *local_8 + uVar1;
    sVar4 = strlen(*(char **)(param_2 + 0xd));
    uVar2 = (short)sVar4 + 1;
    memcpy((void *)((int)pvVar3 + (uint)uVar1),*(void **)(param_2 + 0xd),(uint)uVar2);
    *local_8 = *local_8 + uVar2;
    local_8[3] = 0;
    local_8[4] = 0;
    FUN_6f6a1193(local_8);
    local_10 = FUN_6f6a89d8(local_14,(short *)(local_14 + 0x33398),
                            (undefined2 *)(local_14 + 0x3339a),local_8,(short *)0x0);
  }
  return local_10;
}



// Function: InitDisplay at 6f6a887f

int InitDisplay(short param_1,char *param_2)

{
  int local_10;
  int local_c;
  ushort *local_8;
  
                    /* 0x887f  12  InitDisplay */
  local_c = FUN_6f6a8bed(&local_10,param_1);
  if (local_c == 0) {
    local_8 = (ushort *)(local_10 + 0x31a09);
    *(undefined1 *)(local_10 + 0x31a13) = 0x80;
    if (*param_2 == '\0') {
      *(undefined1 *)(local_10 + 0x31a16) = 0x22;
    }
    else {
      if (*param_2 != '\x01') {
        return 0x2f;
      }
      *(undefined1 *)(local_10 + 0x31a16) = 0x23;
    }
    *local_8 = 4;
    *(undefined4 *)(local_10 + 0x31a0f) = 0;
    FUN_6f6a1193(local_8);
    local_c = FUN_6f6a89d8(local_10,(short *)(local_10 + 0x33394),(undefined2 *)(local_10 + 0x33396)
                           ,local_8,(short *)0x0);
    if (local_c == 0) {
      if (*param_2 == '\0') {
        *(undefined4 *)(local_10 + 0x3339c) = *(undefined4 *)(param_2 + 5);
        *(undefined4 *)(local_10 + 0x333a4) = *(undefined4 *)(param_2 + 1);
      }
      else if (*param_2 == '\x01') {
        *(undefined4 *)(local_10 + 0x333a0) = *(undefined4 *)(param_2 + 5);
        *(undefined4 *)(local_10 + 0x333a8) = *(undefined4 *)(param_2 + 1);
      }
    }
  }
  return local_c;
}



// Function: FUN_6f6a89a0 at 6f6a89a0

undefined4 FUN_6f6a89a0(void)

{
  undefined2 local_8;
  
  for (local_8 = 1; local_8 < 9; local_8 = local_8 + 1) {
    RestoreCommLink(local_8);
  }
  return 1;
}



// Function: FUN_6f6a89d8 at 6f6a89d8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl
FUN_6f6a89d8(int param_1,short *param_2,undefined2 *param_3,void *param_4,short *param_5)

{
  bool bVar1;
  byte bVar2;
  DWORD DVar3;
  int local_10;
  
  bVar1 = false;
  bVar2 = 0;
  WaitForSingleObject(*(HANDLE *)(*(int *)(param_1 + 4) + 0xaf),0xffffffff);
  if (param_5 != (short *)0x0) {
    *param_5 = 0xff;
  }
  do {
    if (param_2 != (short *)0x0) {
      *param_2 = 0;
    }
    if (param_3 != (undefined2 *)0x0) {
      *param_3 = 0;
    }
    ResetEvent(*(HANDLE *)(param_1 + 0x3331a));
    local_10 = FUN_6f6a8d80(*(int *)(param_1 + 4),param_4);
    if ((param_2 == (short *)0x0) || (local_10 != 0)) {
      bVar1 = true;
    }
    else {
      DVar3 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x3331a),0xfa);
      if (DVar3 == 0) {
        if (param_2 == (short *)0x0) {
          bVar1 = true;
        }
        else if (((*param_2 == 1) && (DAT_6f6ac1d0 == '\x01')) &&
                ((param_5 == (short *)0x0 || ((param_5 != (short *)0x0 && (*param_5 != 0xff)))))) {
          bVar1 = true;
        }
      }
      else if ((DVar3 == 0xffffffff) || (DVar3 == 0x102)) {
        _DAT_6f6ac1a0 = GetLastError();
      }
      if ((!bVar1) && (bVar2 = bVar2 + 1, 2 < bVar2)) {
        local_10 = 1;
        bVar1 = true;
      }
    }
  } while (!bVar1);
  ReleaseMutex(*(HANDLE *)(*(int *)(param_1 + 4) + 0xaf));
  return local_10;
}



// Function: FUN_6f6a8b40 at 6f6a8b40

undefined4 __cdecl FUN_6f6a8b40(short *param_1,int param_2)

{
  undefined4 local_c;
  short local_8;
  
  if (param_2 == 0) {
    local_c = 0x20;
  }
  else {
    for (local_8 = 0; local_8 < 8; local_8 = local_8 + 1) {
      if (*(int *)(&DAT_6f6ac1a8 + local_8 * 4) == 0) {
        *(int *)(&DAT_6f6ac1a8 + local_8 * 4) = param_2;
        *param_1 = local_8 + 1;
        break;
      }
    }
    local_c = 0;
  }
  return local_c;
}



// Function: FUN_6f6a8bb2 at 6f6a8bb2

undefined4 __cdecl FUN_6f6a8bb2(short param_1)

{
  undefined4 local_8;
  
  if ((param_1 < 9) && (param_1 != 0)) {
    *(undefined4 *)(&DAT_6f6ac1a4 + param_1 * 4) = 0;
    local_8 = 0;
  }
  else {
    local_8 = 0x21;
  }
  return local_8;
}



// Function: FUN_6f6a8bed at 6f6a8bed

undefined4 __cdecl FUN_6f6a8bed(undefined4 *param_1,short param_2)

{
  undefined4 local_8;
  
  if (((param_2 < 9) && (param_2 != 0)) && (*(int *)(&DAT_6f6ac1a4 + param_2 * 4) != 0)) {
    *param_1 = *(undefined4 *)(&DAT_6f6ac1a4 + param_2 * 4);
    local_8 = 0;
  }
  else {
    local_8 = 0x21;
  }
  return local_8;
}



// Function: FUN_6f6a8c37 at 6f6a8c37

undefined4 __cdecl FUN_6f6a8c37(int param_1)

{
  short local_8;
  
  local_8 = 0;
  while( true ) {
    if (7 < local_8) {
      return 0x21;
    }
    if (*(int *)(&DAT_6f6ac1a8 + local_8 * 4) != param_1) break;
    local_8 = local_8 + 1;
  }
  return 0;
}



// Function: FUN_6f6a8c83 at 6f6a8c83

undefined4 __cdecl FUN_6f6a8c83(undefined4 *param_1)

{
  short local_8;
  
  *param_1 = 0;
  local_8 = 0;
  while( true ) {
    if (7 < local_8) {
      return 0x21;
    }
    if (*(int *)(&DAT_6f6ac1a8 + local_8 * 4) != 0) break;
    local_8 = local_8 + 1;
  }
  *param_1 = *(undefined4 *)(&DAT_6f6ac1a8 + local_8 * 4);
  return 0;
}



// Function: FUN_6f6a8ce6 at 6f6a8ce6

undefined4 __cdecl FUN_6f6a8ce6(undefined4 *param_1,int param_2)

{
  bool bVar1;
  short local_c;
  
  bVar1 = false;
  *param_1 = 0;
  local_c = 0;
  do {
    if (7 < local_c) {
      return 0x21;
    }
    if ((*(int *)(&DAT_6f6ac1a8 + local_c * 4) != param_2) || (bVar1)) {
      if ((*(int *)(&DAT_6f6ac1a8 + local_c * 4) != 0) && (bVar1)) {
        *param_1 = *(undefined4 *)(&DAT_6f6ac1a8 + local_c * 4);
        return 0;
      }
    }
    else {
      bVar1 = true;
    }
    local_c = local_c + 1;
  } while( true );
}



// Function: FUN_6f6a8d80 at 6f6a8d80

undefined4 __cdecl FUN_6f6a8d80(int param_1,void *param_2)

{
  DWORD DVar1;
  
  DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xb7),0xfa);
  if (DVar1 < 0x81) {
    if (DVar1 == 0x80) {
      return 1;
    }
    if (DVar1 == 0) {
      memcpy((void *)(param_1 + 0x8e1),param_2,0x80a);
      EscapeCommFunction(*(HANDLE *)(param_1 + 0x53),4);
      EscapeCommFunction(*(HANDLE *)(param_1 + 0x53),6);
      *(undefined4 *)(param_1 + 0x57) = 1;
      EscapeCommFunction(*(HANDLE *)(param_1 + 0x53),5);
      ReleaseMutex(*(HANDLE *)(param_1 + 0xb7));
      return 0;
    }
  }
  else {
    if (DVar1 == 0x102) {
      return 1;
    }
    if (DVar1 == 0xffffffff) {
      return 1;
    }
  }
  return 0x1c;
}



// Function: FUN_6f6a8e57 at 6f6a8e57

BOOL __cdecl FUN_6f6a8e57(undefined4 *param_1,undefined4 param_2,byte *param_3)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  HANDLE pvVar4;
  BOOL BVar5;
  CHAR local_f0 [16];
  DWORD local_e0;
  _COMMTIMEOUTS local_dc;
  char local_c8 [80];
  CHAR local_78 [80];
  _DCB local_28;
  void *local_c;
  BOOL local_8;
  
  local_8 = 0;
  *param_1 = 0;
  if (param_3[1] < 8) {
    if (DAT_6f6ac1dc == 0) {
      uVar1 = FUN_6f6a9a1f();
      if ((uVar1 & 0xff) == 0) {
        ReleaseMutex(DAT_6f6ac1d4);
        return 0x1f;
      }
    }
    else {
      WaitForSingleObject(DAT_6f6ac1d4,0xffffffff);
    }
    local_c = malloc(0x18f9);
    if (local_c == (void *)0x0) {
      ReleaseMutex(DAT_6f6ac1d4);
      local_8 = 0x1f;
    }
    else {
      DAT_6f6ac1e0 = param_3[2];
      DAT_6f6ac1d8 = local_c;
      memset(local_c,0,0x18f9);
      *(undefined4 *)((int)local_c + 0x18f5) = param_2;
      *(undefined4 *)((int)local_c + 0xc3) = 0;
      *(undefined4 *)((int)local_c + 199) = 2;
      *(undefined4 *)((int)local_c + 0xd3) = 2;
      memcpy(local_c,param_3,0x53);
      uVar1 = FUN_6f6a9776((int)local_c);
      if ((uVar1 & 0xff) == 0) {
        FUN_6f6a983b((int)local_c);
        free(local_c);
        ReleaseMutex(DAT_6f6ac1d4);
        local_8 = 0x11;
      }
      else {
        uVar1 = FUN_6f6a98e4((int)local_c);
        if ((uVar1 & 0xff) == 0) {
          FUN_6f6a983b((int)local_c);
          FUN_6f6a99a8((int)local_c);
          free(local_c);
          ReleaseMutex(DAT_6f6ac1d4);
          local_8 = 0x11;
        }
        else {
          sprintf(local_c8,s_DPAInformation_d_6f6ac0b0,(uint)*param_3);
          GetPrivateProfileStringA
                    (local_c8,s_DPAParams_6f6ac0dc,s_INVALID_6f6ac0d4,local_78,0x50,
                     s_DG_DPA32_ini_6f6ac0c4);
          iVar2 = strcmp(local_78,s_INVALID_6f6ac0e8);
          if (iVar2 != 0) {
            pcVar3 = strstr(local_78,&DAT_6f6ac0f0);
            if (pcVar3 == (char *)0x0) {
              pcVar3 = strstr(local_78,&DAT_6f6ac0f8);
              if (pcVar3 == (char *)0x0) {
                pcVar3 = strstr(local_78,&DAT_6f6ac100);
                if (pcVar3 == (char *)0x0) {
                  pcVar3 = strstr(local_78,&DAT_6f6ac108);
                  if (pcVar3 == (char *)0x0) {
                    pcVar3 = strstr(local_78,&DAT_6f6ac110);
                    if (pcVar3 == (char *)0x0) {
                      pcVar3 = strstr(local_78,&DAT_6f6ac118);
                      if (pcVar3 == (char *)0x0) {
                        pcVar3 = strstr(local_78,&DAT_6f6ac120);
                        if (pcVar3 == (char *)0x0) {
                          pcVar3 = strstr(local_78,&DAT_6f6ac128);
                          if (pcVar3 == (char *)0x0) {
                            pcVar3 = strstr(local_78,&DAT_6f6ac130);
                            if (pcVar3 == (char *)0x0) {
                              return 0xf;
                            }
                            *param_3 = 8;
                          }
                          else {
                            *param_3 = 7;
                          }
                        }
                        else {
                          *param_3 = 6;
                        }
                      }
                      else {
                        *param_3 = 5;
                      }
                    }
                    else {
                      *param_3 = 4;
                    }
                  }
                  else {
                    *param_3 = 3;
                  }
                }
                else {
                  *param_3 = 2;
                }
              }
              else {
                *param_3 = 1;
              }
            }
            else {
              *param_3 = 0;
            }
            pcVar3 = strstr(local_78,s_B9600_6f6ac138);
            if (pcVar3 == (char *)0x0) {
              pcVar3 = strstr(local_78,s_B19200_6f6ac140);
              if (pcVar3 == (char *)0x0) {
                pcVar3 = strstr(local_78,s_B28800_6f6ac148);
                if (pcVar3 == (char *)0x0) {
                  pcVar3 = strstr(local_78,s_B38400_6f6ac150);
                  if (pcVar3 == (char *)0x0) {
                    pcVar3 = strstr(local_78,s_B57600_6f6ac158);
                    if (pcVar3 == (char *)0x0) {
                      pcVar3 = strstr(local_78,s_B115200_6f6ac160);
                      if (pcVar3 == (char *)0x0) {
                        pcVar3 = strstr(local_78,s_B230400_6f6ac168);
                        if (pcVar3 == (char *)0x0) {
                          pcVar3 = strstr(local_78,s_B460800_6f6ac170);
                          if (pcVar3 == (char *)0x0) {
                            param_3[1] = 5;
                          }
                          else {
                            param_3[1] = 7;
                          }
                        }
                        else {
                          param_3[1] = 6;
                        }
                      }
                      else {
                        param_3[1] = 5;
                      }
                    }
                    else {
                      param_3[1] = 4;
                    }
                  }
                  else {
                    param_3[1] = 3;
                  }
                }
                else {
                  param_3[1] = 2;
                }
              }
              else {
                param_3[1] = 1;
              }
            }
            else {
              param_3[1] = 0;
            }
            pcVar3 = strstr(local_78,&DAT_6f6ac178);
            if (pcVar3 == (char *)0x0) {
              param_3[2] = 0;
            }
            else {
              param_3[2] = 1;
            }
          }
          wsprintfA(local_f0,&DAT_6f6ac184,&DAT_6f6ac180,*param_3 + 1);
          if (*(int *)((int)local_c + 0x53) != 0) {
            CloseHandle(*(HANDLE *)((int)local_c + 0x53));
            *(undefined4 *)((int)local_c + 0x53) = 0;
          }
          memset(&local_28,0,0x1c);
          pvVar4 = CreateFileA(local_f0,0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x40000080,
                               (HANDLE)0x0);
          *(HANDLE *)((int)local_c + 0x53) = pvVar4;
          if (*(int *)((int)local_c + 0x53) == -1) {
            local_e0 = GetLastError();
            FUN_6f6a983b((int)local_c);
            FUN_6f6a99a8((int)local_c);
            free(local_c);
            ReleaseMutex(DAT_6f6ac1d4);
            local_8 = 0x11;
          }
          else {
            FUN_6f6a1000((int)local_c);
            SetupComm(*(HANDLE *)((int)local_c + 0x53),0x800,0x800);
            local_dc.ReadIntervalTimeout = 100;
            local_dc.ReadTotalTimeoutMultiplier = 10;
            local_dc.ReadTotalTimeoutConstant = 0xfa;
            local_dc.WriteTotalTimeoutMultiplier = 10;
            local_dc.WriteTotalTimeoutConstant = 10;
            BVar5 = SetCommTimeouts(*(HANDLE *)((int)local_c + 0x53),&local_dc);
            if (BVar5 == 0) {
              local_e0 = GetLastError();
              CloseHandle(*(HANDLE *)((int)local_c + 0x53));
              FUN_6f6a983b((int)local_c);
              FUN_6f6a99a8((int)local_c);
              free(local_c);
              ReleaseMutex(DAT_6f6ac1d4);
              local_8 = 0x11;
            }
            else {
              local_28.DCBlength = 0x1c;
              BVar5 = GetCommState(*(HANDLE *)((int)local_c + 0x53),&local_28);
              if (BVar5 == 0) {
                local_e0 = GetLastError();
                CloseHandle(*(HANDLE *)((int)local_c + 0x53));
                FUN_6f6a983b((int)local_c);
                FUN_6f6a99a8((int)local_c);
                free(local_c);
                ReleaseMutex(DAT_6f6ac1d4);
              }
              else {
                local_28.BaudRate = *(DWORD *)(&DAT_6f6ac090 + (uint)param_3[1] * 4);
                local_28.ByteSize = '\b';
                local_28.Parity = '\0';
                local_28.StopBits = '\0';
                local_28.XonChar = '\x11';
                local_28.XoffChar = '\x13';
                local_28.XonLim = 0x800;
                local_28.XoffLim = 0x800;
                local_28._8_4_ = local_28._8_4_ & 0xffffcc85 | 5;
                local_8 = SetCommState(*(HANDLE *)((int)local_c + 0x53),&local_28);
                if (local_8 == 0) {
                  local_e0 = GetLastError();
                  CloseHandle(*(HANDLE *)((int)local_c + 0x53));
                  FUN_6f6a983b((int)local_c);
                  FUN_6f6a99a8((int)local_c);
                  free(local_c);
                  ReleaseMutex(DAT_6f6ac1d4);
                  local_8 = 0x11;
                }
                else {
                  if (*(int *)((int)local_c + 199) == 2) {
                    ResetEvent(DAT_6f6ac1cc);
                    pvVar4 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0x4000,FUN_6f6a9aa2,(LPVOID)0x0
                                          ,0,(LPDWORD)((int)local_c + 0x8b));
                    *(HANDLE *)((int)local_c + 0x87) = pvVar4;
                    if (*(int *)((int)local_c + 0x87) == 0) {
                      local_e0 = GetLastError();
                      CloseHandle(*(HANDLE *)((int)local_c + 0x53));
                      FUN_6f6a983b((int)local_c);
                      FUN_6f6a99a8((int)local_c);
                      free(local_c);
                      ReleaseMutex(DAT_6f6ac1d4);
                      return 0x1f;
                    }
                    SetThreadPriority(*(HANDLE *)((int)local_c + 0x87),0xf);
                    *(undefined4 *)((int)local_c + 199) = 0;
                    WaitForSingleObject(DAT_6f6ac1cc,0xffffffff);
                  }
                  if (*(int *)((int)local_c + 0xd3) == 2) {
                    ResetEvent(DAT_6f6ac1c8);
                    pvVar4 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0x4000,FUN_6f6aa469,(LPVOID)0x0
                                          ,0,(LPDWORD)((int)local_c + 0xa3));
                    *(HANDLE *)((int)local_c + 0x9f) = pvVar4;
                    if (*(int *)((int)local_c + 0x9f) == 0) {
                      local_e0 = GetLastError();
                      CloseHandle(*(HANDLE *)((int)local_c + 0x53));
                      FUN_6f6a983b((int)local_c);
                      FUN_6f6a99a8((int)local_c);
                      free(local_c);
                      ReleaseMutex(DAT_6f6ac1d4);
                      return 0x1f;
                    }
                    SetThreadPriority(*(HANDLE *)((int)local_c + 0x9f),0xf);
                    *(undefined4 *)((int)local_c + 0xd3) = 0;
                    WaitForSingleObject(DAT_6f6ac1c8,0xffffffff);
                  }
                  if (*(int *)((int)local_c + 0x53) != 0) {
                    *(undefined4 *)((int)local_c + 0xc3) = 1;
                    *param_1 = local_c;
                    DAT_6f6ac1dc = DAT_6f6ac1dc + 1;
                  }
                  ReleaseMutex(DAT_6f6ac1d4);
                  local_8 = 0;
                }
              }
            }
          }
        }
      }
    }
  }
  else {
    local_8 = 0x10;
  }
  return local_8;
}



// Function: FUN_6f6a9776 at 6f6a9776

uint __cdecl FUN_6f6a9776(int param_1)

{
  HANDLE pvVar1;
  DWORD DVar2;
  uint uVar3;
  
  pvVar1 = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,0,(LPCSTR)0x0);
  *(HANDLE *)(param_1 + 0xb7) = pvVar1;
  if (*(int *)(param_1 + 0xb7) == 0) {
    DVar2 = GetLastError();
    uVar3 = DVar2 & 0xffffff00;
  }
  else {
    pvVar1 = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,0,(LPCSTR)0x0);
    *(HANDLE *)(param_1 + 0xa7) = pvVar1;
    if (*(int *)(param_1 + 0xa7) == 0) {
      DVar2 = GetLastError();
      uVar3 = DVar2 & 0xffffff00;
    }
    else {
      pvVar1 = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,0,(LPCSTR)0x0);
      *(HANDLE *)(param_1 + 0xab) = pvVar1;
      if (*(int *)(param_1 + 0xab) == 0) {
        DVar2 = GetLastError();
        uVar3 = DVar2 & 0xffffff00;
      }
      else {
        pvVar1 = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,0,(LPCSTR)0x0);
        *(HANDLE *)(param_1 + 0xaf) = pvVar1;
        if (*(int *)(param_1 + 0xaf) == 0) {
          DVar2 = GetLastError();
          uVar3 = DVar2 & 0xffffff00;
        }
        else {
          uVar3 = CONCAT31((int3)((uint)pvVar1 >> 8),1);
        }
      }
    }
  }
  return uVar3;
}



// Function: FUN_6f6a983b at 6f6a983b

void __cdecl FUN_6f6a983b(int param_1)

{
  if (*(int *)(param_1 + 0xb7) != 0) {
    CloseHandle(*(HANDLE *)(param_1 + 0xb7));
    *(undefined4 *)(param_1 + 0xb7) = 0;
  }
  if (*(int *)(param_1 + 0xa7) != 0) {
    CloseHandle(*(HANDLE *)(param_1 + 0xa7));
    *(undefined4 *)(param_1 + 0xa7) = 0;
  }
  if (*(int *)(param_1 + 0xab) != 0) {
    CloseHandle(*(HANDLE *)(param_1 + 0xab));
    *(undefined4 *)(param_1 + 0xab) = 0;
  }
  if (*(int *)(param_1 + 0xaf) != 0) {
    CloseHandle(*(HANDLE *)(param_1 + 0xaf));
    *(undefined4 *)(param_1 + 0xaf) = 0;
  }
  return;
}



// Function: FUN_6f6a98e4 at 6f6a98e4

uint __cdecl FUN_6f6a98e4(int param_1)

{
  HANDLE pvVar1;
  DWORD DVar2;
  uint uVar3;
  
  pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
  *(HANDLE *)(param_1 + 0xb3) = pvVar1;
  if (*(int *)(param_1 + 0xb3) == 0) {
    DVar2 = GetLastError();
    uVar3 = DVar2 & 0xffffff00;
  }
  else {
    *(undefined4 *)(param_1 + 0x67) = 0;
    *(undefined4 *)(param_1 + 0x6b) = 0;
    pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
    if (pvVar1 == (HANDLE)0x0) {
      DVar2 = GetLastError();
      uVar3 = DVar2 & 0xffffff00;
    }
    else {
      *(HANDLE *)(param_1 + 0x6f) = pvVar1;
      *(undefined4 *)(param_1 + 0x7b) = 0;
      *(undefined4 *)(param_1 + 0x7f) = 0;
      pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
      if (pvVar1 == (HANDLE)0x0) {
        DVar2 = GetLastError();
        uVar3 = DVar2 & 0xffffff00;
      }
      else {
        *(HANDLE *)(param_1 + 0x83) = pvVar1;
        uVar3 = CONCAT31((int3)((uint)param_1 >> 8),1);
      }
    }
  }
  return uVar3;
}



// Function: FUN_6f6a99a8 at 6f6a99a8

void __cdecl FUN_6f6a99a8(int param_1)

{
  if (*(int *)(param_1 + 0xb3) != 0) {
    CloseHandle(*(HANDLE *)(param_1 + 0xb3));
    *(undefined4 *)(param_1 + 0xb3) = 0;
  }
  if (*(int *)(param_1 + 0x6f) != 0) {
    CloseHandle(*(HANDLE *)(param_1 + 0x6f));
    *(undefined4 *)(param_1 + 0x6f) = 0;
  }
  if (*(int *)(param_1 + 0x83) != 0) {
    CloseHandle(*(HANDLE *)(param_1 + 0x83));
    *(undefined4 *)(param_1 + 0x83) = 0;
  }
  return;
}



// Function: FUN_6f6a9a1f at 6f6a9a1f

uint FUN_6f6a9a1f(void)

{
  DWORD DVar1;
  uint uVar2;
  
  DAT_6f6ac1cc = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
  if (DAT_6f6ac1cc == (HANDLE)0x0) {
    DVar1 = GetLastError();
    uVar2 = DVar1 & 0xffffff00;
  }
  else {
    DAT_6f6ac1c8 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
    if (DAT_6f6ac1c8 == (HANDLE)0x0) {
      DVar1 = GetLastError();
      uVar2 = DVar1 & 0xffffff00;
    }
    else {
      DAT_6f6ac1d4 = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,0,(LPCSTR)0x0);
      if (DAT_6f6ac1d4 == (HANDLE)0x0) {
        DVar1 = GetLastError();
        uVar2 = DVar1 & 0xffffff00;
      }
      else {
        uVar2 = CONCAT31((int3)((uint)DAT_6f6ac1d4 >> 8),1);
      }
    }
  }
  return uVar2;
}



// Function: FUN_6f6a9aa2 at 6f6a9aa2

void FUN_6f6a9aa2(void)

{
  DWORD DVar1;
  DWORD DVar2;
  BOOL BVar3;
  DWORD local_4c;
  uint local_48;
  DWORD local_44;
  uint local_40;
  uint local_3c;
  DWORD local_38;
  DWORD local_34;
  DWORD local_30;
  uint local_2c;
  short *local_28;
  uint local_24;
  int local_20;
  char local_1c [4];
  uint local_18;
  BOOL local_14;
  uint local_10;
  BOOL local_c;
  uint local_8;
  
  local_30 = 0x78;
  local_38 = 0;
  local_20 = DAT_6f6ac1d8;
  local_18 = CONCAT31(local_18._1_3_,DAT_6f6ac1e0);
  local_44 = 0;
  local_4c = 0;
  local_3c = local_3c & 0xffffff00;
  if (DAT_6f6ac1e0 == '\0') {
    SetCommMask(*(HANDLE *)(DAT_6f6ac1d8 + 0x53),0x18);
  }
  SetEvent(DAT_6f6ac1cc);
  while( true ) {
    if (*(int *)(local_20 + 199) == 1) {
      *(undefined4 *)(local_20 + 0x87) = 0;
      *(undefined4 *)(local_20 + 199) = 2;
      return;
    }
    if ((local_18 & 0xff) == 0) {
      local_c = WaitCommEvent(*(HANDLE *)(local_20 + 0x53),&local_34,(LPOVERLAPPED)(local_20 + 0x73)
                             );
      if (local_c == 0) {
        WaitForSingleObject(*(HANDLE *)(local_20 + 0x83),0xffffffff);
      }
    }
    else {
      DVar2 = GetTickCount();
      if (5 < DVar2 - local_44) {
        Sleep(1);
      }
      GetCommModemStatus(*(HANDLE *)(local_20 + 0x53),&local_48);
      while (((local_48 & 0x20) == 0 && ((local_48 & 0x10) == 0))) {
        if (*(int *)(local_20 + 199) == 1) {
          *(undefined4 *)(local_20 + 0x87) = 0;
          *(undefined4 *)(local_20 + 199) = 2;
          return;
        }
        DVar1 = GetTickCount();
        if (4 < DVar1 - DVar2) {
          Sleep(1);
        }
        GetCommModemStatus(*(HANDLE *)(local_20 + 0x53),&local_48);
      }
    }
    GetCommModemStatus(*(HANDLE *)(local_20 + 0x53),&local_48);
    WaitForSingleObject(*(HANDLE *)(local_20 + 0xb7),0xffffffff);
    if (*(int *)(local_20 + 199) == 1) break;
    local_3c = local_3c & 0xffffff00;
    if ((*(int *)(local_20 + 0x57) == 0) && ((local_48 & 0x20) != 0)) {
      PurgeComm(*(HANDLE *)(local_20 + 0x53),8);
      memset((void *)(local_20 + 0xe1),0,0x800);
      local_3c = CONCAT31(local_3c._1_3_,1);
      EscapeCommFunction(*(HANDLE *)(local_20 + 0x53),3);
      *(undefined4 *)(local_20 + 0x67) = 0;
      *(undefined4 *)(local_20 + 0x6b) = 0;
      ResetEvent(*(HANDLE *)(local_20 + 0x6f));
      local_14 = ReadFile(*(HANDLE *)(local_20 + 0x53),(LPVOID)(local_20 + 0xe1),3,&local_30,
                          (LPOVERLAPPED)(local_20 + 0x5f));
      if ((local_14 == 0) && (DVar2 = GetLastError(), DVar2 == 0x3e5)) {
        local_14 = GetOverlappedResult(*(HANDLE *)(local_20 + 0x53),(LPOVERLAPPED)(local_20 + 0x5f),
                                       &local_30,1);
      }
      if (local_30 == 3) {
        local_28 = (short *)(local_20 + 0xe2);
        *(undefined2 *)(local_20 + 0xd7) = 3;
        local_2c = CONCAT22(local_2c._2_2_,3);
        local_24 = CONCAT22(local_24._2_2_,*local_28 + -1);
        local_40 = local_40 & 0xffffff00;
        while (((local_40 & 0xff) < 3 && ((local_24 & 0xffff) != 0))) {
          *(undefined4 *)(local_20 + 0x67) = 0;
          *(undefined4 *)(local_20 + 0x6b) = 0;
          ResetEvent(*(HANDLE *)(local_20 + 0x6f));
          local_14 = ReadFile(*(HANDLE *)(local_20 + 0x53),
                              (LPVOID)(local_20 + 0xe1 + (local_2c & 0xffff)),local_24 & 0xffff,
                              &local_30,(LPOVERLAPPED)(local_20 + 0x5f));
          if ((local_14 == 0) && (DVar2 = GetLastError(), DVar2 == 0x3e5)) {
            GetOverlappedResult(*(HANDLE *)(local_20 + 0x53),(LPOVERLAPPED)(local_20 + 0x5f),
                                &local_30,1);
          }
          local_24 = CONCAT22(local_24._2_2_,(short)local_24 - (short)local_30);
          local_2c = CONCAT22(local_2c._2_2_,(short)local_2c + (short)local_30);
          *(short *)(local_20 + 0xd7) = *(short *)(local_20 + 0xd7) + (short)local_30;
          local_40 = CONCAT31(local_40._1_3_,(char)local_40 + '\x01');
        }
        EscapeCommFunction(*(HANDLE *)(local_20 + 0x53),4);
        local_10 = local_10 & 0xffffff00;
        local_8 = local_8 & 0xffff0000;
        while ((local_8 & 0xffff) < (uint)*(ushort *)(local_20 + 0xd7)) {
          local_10 = CONCAT31(local_10._1_3_,
                              (char)local_10 + *(char *)(local_20 + 0xe1 + (local_8 & 0xffff)));
          local_8 = CONCAT22(local_8._2_2_,(short)local_8 + 1);
        }
        if ((local_10 & 0xff) == 0) {
          if (*(short *)(local_20 + 0xd7) != 0) {
            local_1c[0] = -0x40;
            *(undefined4 *)(local_20 + 0x67) = 0;
            *(undefined4 *)(local_20 + 0x6b) = 0;
            ResetEvent(*(HANDLE *)(local_20 + 0x6f));
            BVar3 = WriteFile(*(HANDLE *)(local_20 + 0x53),local_1c,1,&local_38,
                              (LPOVERLAPPED)(local_20 + 0x5f));
            if ((BVar3 == 0) && (DVar2 = GetLastError(), DVar2 == 0x3e5)) {
              GetOverlappedResult(*(HANDLE *)(local_20 + 0x53),(LPOVERLAPPED)(local_20 + 0x5f),
                                  &local_38,1);
            }
            do {
              GetCommModemStatus(*(HANDLE *)(local_20 + 0x53),&local_4c);
            } while ((local_4c & 0x10) != 0);
            if (*(int *)(*(int *)(local_20 + 0x18f5) + 0x333ac) == 0) {
              FUN_6f6a1230(*(int *)(local_20 + 0x18f5),(ushort *)(local_20 + 0xd7));
            }
            else {
              (**(code **)(*(int *)(local_20 + 0x18f5) + 0x333ac))(local_20 + 0xd7);
            }
            if ((local_18 & 0xff) != 0) {
              local_44 = GetTickCount();
            }
          }
        }
        else {
          local_1c[0] = -0x30;
          *(undefined4 *)(local_20 + 0x67) = 0;
          *(undefined4 *)(local_20 + 0x6b) = 0;
          ResetEvent(*(HANDLE *)(local_20 + 0x6f));
          BVar3 = WriteFile(*(HANDLE *)(local_20 + 0x53),local_1c,1,&local_38,
                            (LPOVERLAPPED)(local_20 + 0x5f));
          if ((BVar3 == 0) && (DVar2 = GetLastError(), DVar2 == 0x3e5)) {
            WaitForSingleObject(*(HANDLE *)(local_20 + 0x6f),0xfa);
          }
          do {
            GetCommModemStatus(*(HANDLE *)(local_20 + 0x53),&local_4c);
          } while ((local_4c & 0x10) != 0);
        }
      }
      else {
        EscapeCommFunction(*(HANDLE *)(local_20 + 0x53),4);
      }
    }
    if ((((local_3c & 0xff) == 0) && (*(int *)(local_20 + 0x57) != 0)) && ((local_48 & 0x10) != 0))
    {
      PurgeComm(*(HANDLE *)(local_20 + 0x53),8);
      *(undefined4 *)(local_20 + 0x67) = 0;
      *(undefined4 *)(local_20 + 0x6b) = 0;
      ResetEvent(*(HANDLE *)(local_20 + 0x6f));
      BVar3 = WriteFile(*(HANDLE *)(local_20 + 0x53),(LPCVOID)(local_20 + 0x8eb),
                        (uint)*(ushort *)(local_20 + 0x8e1),&local_38,
                        (LPOVERLAPPED)(local_20 + 0x5f));
      if ((BVar3 == 0) && (DVar2 = GetLastError(), DVar2 == 0x3e5)) {
        GetOverlappedResult(*(HANDLE *)(local_20 + 0x53),(LPOVERLAPPED)(local_20 + 0x5f),&local_38,1
                           );
      }
      EscapeCommFunction(*(HANDLE *)(local_20 + 0x53),6);
      *(undefined4 *)(local_20 + 0x57) = 0;
      if (local_38 == *(ushort *)(local_20 + 0x8e1)) {
        local_1c[0] = '\0';
        *(undefined4 *)(local_20 + 0x67) = 0;
        *(undefined4 *)(local_20 + 0x6b) = 0;
        ResetEvent(*(HANDLE *)(local_20 + 0x6f));
        BVar3 = ReadFile(*(HANDLE *)(local_20 + 0x53),local_1c,1,&local_30,
                         (LPOVERLAPPED)(local_20 + 0x5f));
        if (BVar3 == 0) {
          GetOverlappedResult(*(HANDLE *)(local_20 + 0x53),(LPOVERLAPPED)(local_20 + 0x5f),&local_30
                              ,1);
        }
        if (((local_30 == 1) && (local_1c[0] == 0xc0)) && (DAT_6f6ac1d0 = 1, (local_18 & 0xff) != 0)
           ) {
          local_44 = GetTickCount();
        }
      }
    }
    ReleaseMutex(*(HANDLE *)(local_20 + 0xb7));
  }
  *(undefined4 *)(local_20 + 0x87) = 0;
  *(undefined4 *)(local_20 + 199) = 2;
  return;
}



// Function: FUN_6f6aa222 at 6f6aa222

undefined4 __cdecl FUN_6f6aa222(void *param_1)

{
  DWORD DVar1;
  DWORD DVar2;
  
  CloseHandle(*(HANDLE *)((int)param_1 + 0x9f));
  CloseHandle(*(HANDLE *)((int)param_1 + 0x87));
  *(undefined4 *)((int)param_1 + 0xd3) = 1;
  *(undefined4 *)((int)param_1 + 199) = 1;
  SetEvent(*(HANDLE *)((int)param_1 + 0xb3));
  SetEvent(*(HANDLE *)((int)param_1 + 0xaf));
  SetEvent(*(HANDLE *)((int)param_1 + 0x83));
  ResumeThread(*(HANDLE *)((int)param_1 + 0x9f));
  ResumeThread(*(HANDLE *)((int)param_1 + 0x87));
  DVar1 = GetTickCount();
  do {
    if ((*(int *)((int)param_1 + 199) != 1) && (*(int *)((int)param_1 + 0xd3) != 1)) break;
    DVar2 = GetTickCount();
  } while (DVar2 - DVar1 < 0xfb);
  if (*(int *)((int)param_1 + 199) != 2) {
    TerminateThread(*(HANDLE *)((int)param_1 + 0x87),0);
    *(undefined4 *)((int)param_1 + 199) = 2;
  }
  if (*(int *)((int)param_1 + 0xd3) != 2) {
    TerminateThread(*(HANDLE *)((int)param_1 + 0x9f),0);
    *(undefined4 *)((int)param_1 + 0xd3) = 2;
  }
  CloseHandle(*(HANDLE *)((int)param_1 + 0x53));
  FUN_6f6a983b((int)param_1);
  FUN_6f6a99a8((int)param_1);
  *(undefined4 *)((int)param_1 + 0xc3) = 0;
  free(param_1);
  DAT_6f6ac1dc = DAT_6f6ac1dc + -1;
  if (DAT_6f6ac1dc == 0) {
    FUN_6f6aa3a2();
  }
  return 0;
}



// Function: FUN_6f6aa3a2 at 6f6aa3a2

void FUN_6f6aa3a2(void)

{
  if (DAT_6f6ac1cc != (HANDLE)0x0) {
    CloseHandle(DAT_6f6ac1cc);
    DAT_6f6ac1cc = (HANDLE)0x0;
  }
  if (DAT_6f6ac1c8 != (HANDLE)0x0) {
    CloseHandle(DAT_6f6ac1c8);
    DAT_6f6ac1c8 = (HANDLE)0x0;
  }
  if (DAT_6f6ac1d4 != (HANDLE)0x0) {
    CloseHandle(DAT_6f6ac1d4);
    DAT_6f6ac1d4 = (HANDLE)0x0;
  }
  return;
}



// Function: FUN_6f6aa406 at 6f6aa406

undefined4 __cdecl FUN_6f6aa406(int param_1,void *param_2)

{
  DWORD DVar1;
  undefined4 uVar2;
  
  DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xab),0);
  if (DVar1 == 0xffffffff) {
    uVar2 = 0x14;
  }
  else {
    memcpy((void *)(param_1 + 0x10eb),param_2,0x80a);
    SetEvent(*(HANDLE *)(param_1 + 0xb3));
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_6f6aa469 at 6f6aa469

void FUN_6f6aa469(void)

{
  int iVar1;
  
  iVar1 = DAT_6f6ac1d8;
  SetEvent(DAT_6f6ac1c8);
  while (WaitForSingleObject(*(HANDLE *)(iVar1 + 0xb3),0xffffffff), *(int *)(iVar1 + 0xd3) != 1) {
    FUN_6f6a89d8(*(int *)(iVar1 + 0x18f5),(short *)0x0,(undefined2 *)0x0,(void *)(iVar1 + 0x10eb),
                 (short *)0x0);
    ReleaseMutex(*(HANDLE *)(iVar1 + 0xab));
  }
  *(undefined4 *)(iVar1 + 0x9f) = 0;
  *(undefined4 *)(iVar1 + 0xd3) = 2;
  return;
}



// Function: FUN_6f6aa4fd at 6f6aa4fd

undefined4 __cdecl FUN_6f6aa4fd(int param_1,uint param_2)

{
  BOOL BVar1;
  undefined4 local_2c;
  _DCB local_28;
  BOOL local_c;
  DWORD local_8;
  
  local_2c = 0;
  local_c = 0;
  local_8 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xb7),0xfa);
  if (local_8 == 0) {
    local_28.DCBlength = 0x1c;
    BVar1 = GetCommState(*(HANDLE *)(param_1 + 0x53),&local_28);
    if (BVar1 == 0) {
      local_2c = 0x1c;
    }
    else {
      local_28.BaudRate = *(DWORD *)(&DAT_6f6ac090 + (param_2 & 0xff) * 4);
      local_c = SetCommState(*(HANDLE *)(param_1 + 0x53),&local_28);
      if (local_c == 0) {
        local_2c = 0x1c;
      }
    }
    ReleaseMutex(*(HANDLE *)(param_1 + 0xb7));
  }
  else {
    local_2c = 1;
  }
  return local_2c;
}



// Function: FUN_6f6aa5b8 at 6f6aa5b8

undefined4 __cdecl FUN_6f6aa5b8(int param_1,char *param_2)

{
  DWORD DVar1;
  undefined4 uVar2;
  
  DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xb7),0xfa);
  if (DVar1 == 0) {
    if (*param_2 == '\0') {
      EscapeCommFunction(*(HANDLE *)(param_1 + 0x53),5);
    }
    else {
      EscapeCommFunction(*(HANDLE *)(param_1 + 0x53),6);
    }
    SetCommBreak(*(HANDLE *)(param_1 + 0x53));
    Sleep(5);
    ClearCommBreak(*(HANDLE *)(param_1 + 0x53));
    Sleep(200);
    EscapeCommFunction(*(HANDLE *)(param_1 + 0x53),6);
    Sleep(0x5dc);
    ReleaseMutex(*(HANDLE *)(param_1 + 0xb7));
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



// Function: FUN_6f6aa690 at 6f6aa690

void __cdecl FUN_6f6aa690(_onexit_t param_1)

{
  if (DAT_6f6ac1f4 == -1) {
    _onexit(param_1);
    return;
  }
  __dllonexit(param_1,&DAT_6f6ac1f4,&DAT_6f6ac1f0);
  return;
}



// Function: FUN_6f6aa6c0 at 6f6aa6c0

int __cdecl FUN_6f6aa6c0(_onexit_t param_1)

{
  int iVar1;
  
  iVar1 = FUN_6f6aa690(param_1);
  return (iVar1 != 0) - 1;
}



// Function: FUN_6f6aa700 at 6f6aa700

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_6f6aa700(undefined4 param_1,int param_2)

{
  undefined4 *_Memory;
  undefined4 *puVar1;
  
  if (param_2 == 0) {
    if (DAT_6f6ac1e4 < 1) {
      return 0;
    }
    DAT_6f6ac1e4 = DAT_6f6ac1e4 + -1;
  }
  _DAT_6f6ac1e8 = *(undefined4 *)_adjust_fdiv_exref;
  if (param_2 == 1) {
    DAT_6f6ac1f4 = (undefined4 *)malloc(0x80);
    if (DAT_6f6ac1f4 == (undefined4 *)0x0) {
      return 0;
    }
    *DAT_6f6ac1f4 = 0;
    DAT_6f6ac1f0 = DAT_6f6ac1f4;
    initterm(&DAT_6f6ac000,&DAT_6f6ac00c);
    DAT_6f6ac1e4 = DAT_6f6ac1e4 + 1;
    return 1;
  }
  if ((param_2 == 0) && (DAT_6f6ac1f4 != (undefined4 *)0x0)) {
    puVar1 = DAT_6f6ac1f0 + -1;
    _Memory = DAT_6f6ac1f4;
    if (DAT_6f6ac1f4 <= puVar1) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
          _Memory = DAT_6f6ac1f4;
        }
        puVar1 = puVar1 + -1;
      } while (_Memory <= puVar1);
    }
    free(_Memory);
    DAT_6f6ac1f4 = (undefined4 *)0x0;
  }
  return 1;
}



// Function: entry at 6f6aa7d0

int entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 1;
  if ((param_2 == 0) && (DAT_6f6ac1e4 == 0)) {
    return 0;
  }
  if ((param_2 != 1) && (param_2 != 2)) {
LAB_6f6aa82e:
    iVar1 = FUN_6f6aa890(param_1,param_2);
    if ((param_2 == 1) && (iVar1 == 0)) {
      FUN_6f6aa700(param_1,0);
    }
    if ((param_2 == 0) || (param_2 == 3)) {
      iVar2 = FUN_6f6aa700(param_1,param_2);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      if ((iVar1 != 0) && (DAT_6f6ac1ec != (code *)0x0)) {
        iVar1 = (*DAT_6f6ac1ec)(param_1,param_2,param_3);
      }
    }
    return iVar1;
  }
  if (DAT_6f6ac1ec != (code *)0x0) {
    iVar1 = (*DAT_6f6ac1ec)(param_1,param_2,param_3);
  }
  if (iVar1 != 0) {
    iVar1 = FUN_6f6aa700(param_1,param_2);
    if (iVar1 != 0) goto LAB_6f6aa82e;
  }
  return 0;
}



// Function: FUN_6f6aa890 at 6f6aa890

undefined4 FUN_6f6aa890(HMODULE param_1,int param_2)

{
  if ((param_2 == 1) && (DAT_6f6ac1ec == 0)) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



