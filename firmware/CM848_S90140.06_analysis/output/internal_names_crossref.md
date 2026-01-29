# CM848 Internal Names Cross-Reference Report

Variables from decompiled code matched with e2m internal names.

## Prefix Reference

- **AD**: A/D Converter (sensor inputs, filtering)
- **AS**: Acceleration System
- **CK**: Check / Crank
- **CR**: Crank Control
- **CT**: Control
- **DG**: Diagnostics
- **EP**: Engine Protection
- **ES**: Engine System
- **FS**: Fuel System
- **HS**: High Speed / Horsepower System
- **JC**: J1939 CAN Protocol
- **LS**: Limiting System
- **MX**: Maximum Limits
- **OC**: Output Control
- **PT**: Protection / Power Train
- **SD**: Shutdown
- **SS**: Sensor System
- **TS**: Throttle System
- **VS**: Vehicle Speed

## Suggested Matches

### ADBSPR - Unknown

**DAT_0040a42e**
  - In `FUN_0001242c`: `uVar2 = (uint)_DAT_0040a42e;...`
  - In `FUN_0001242c`: `_DAT_0040a3f8 = (undefined2)(iVar3 / (int)(short)_DAT_0040a4...`

**DAT_0040a7d0**
  - In `FUN_000125f4`: `iVar2 = iVar3 * (uint)_DAT_0040a7d0;...`
  - In `FUN_000125f4`: `if ((iVar3 == 0) || (_DAT_0040a7d0 == 0)) {...`

**DAT_0040a408**
  - In `boostBasedFuelModifier`: `_DAT_0040a408 =...`
  - In `boostBasedFuelModifier`: `uVar4 = (uint)_DAT_0040a408 * (uVar2 & 0xffff);...`

**DAT_00400938**
  - In `boostBasedFuelModifier`: `(0x3fa5de,(uint)_current_engine_rpm * (uint)_DAT_00400938 >>...`

**DAT_0040a406**
  - In `boostBasedFuelModifier`: `uVar1 = lookupTableInterpolation(0x3fa5e0,_DAT_0040a406,0x40...`
  - In `loadBasedFuelAdjustment`: `(uint)_DAT_0040a42e * (uint)_DAT_0040093a,0,(uint)_DAT_0040a...`

**DAT_0040093c**
  - In `boostBasedFuelModifier`: `uVar3 = (uint)_DAT_0040093c * (uint)_DAT_0040093c;...`
  - In `boostBasedFuelModifier`: `uVar3 = (uint)_DAT_0040093c * (uint)_DAT_0040093c;...`

**DAT_0040093e**
  - In `boostBasedFuelModifier`: `uVar2 = (uint)_DAT_0040093e;...`

**DAT_0040a40a**
  - In `boostBasedFuelModifier`: `_DAT_0040a40a = uVar1;...`

**DAT_0040a40c**
  - In `boostBasedFuelModifier`: `_DAT_0040a40c = (undefined2)uVar2;...`

**DAT_00400946**
  - In `boostBasedFuelModifier`: `uVar2 = (uVar3 + _DAT_00400946 & 0xffff) * (-(int)_DAT_00400...`

**DAT_00400944**
  - In `boostBasedFuelModifier`: `uVar2 = (uVar3 + _DAT_00400946 & 0xffff) * (-(int)_DAT_00400...`

**DAT_00400948**
  - In `boostBasedFuelModifier`: `uVar3 = (uint)_DAT_00400948;...`

**DAT_00400942**
  - In `boostBasedFuelModifier`: `_fuel_efficiency_factor = _DAT_00400942;...`
  - In `boostBasedFuelModifier`: `if (((uint)_DAT_00400942 <= (uVar3 & 0xffff)) &&...`

**DAT_00400940**
  - In `boostBasedFuelModifier`: `(_fuel_efficiency_factor = (ushort)uVar3, (uint)_DAT_0040094...`
  - In `boostBasedFuelModifier`: `_fuel_efficiency_factor = _DAT_00400940;...`

### ADCLTP - Unknown

**DAT_003fd59e**
  - In `FUN_0000e518`: `if ((_DAT_003fd59e & 1) == 0) {...`
  - In `temperatureBasedFuelTrim`: `if (((_DAT_003fd59e & 1) == 0) && (_DAT_003ff014 != 0)) {...`

**DAT_0040a168**
  - In `FUN_0000e518`: `_DAT_0040a168 = DAT_0005be6c;...`
  - In `FUN_0000e518`: `_DAT_0040a168 = _DAT_0040a16a;...`

**DAT_003ff014**
  - In `temperatureBasedFuelTrim`: `if (((_DAT_003fd59e & 1) == 0) && (_DAT_003ff014 != 0)) {...`

**DAT_0040a184**
  - In `temperatureBasedFuelTrim`: `_DAT_0040a184 =...`
  - In `temperatureBasedFuelTrim`: `if (_DAT_0040a186 < _DAT_0040a184) {...`

**DAT_003fa0de**
  - In `temperatureBasedFuelTrim`: `lookupTableInterpolation(&DAT_003fa0de,_intake_air_temp_sens...`
  - In `FUN_0000e8ac`: `_DAT_003fa0de = 2;...`

**DAT_0040a186**
  - In `temperatureBasedFuelTrim`: `_DAT_0040a186 = lookupTableInterpolation(&DAT_003fa0e0,_cool...`
  - In `temperatureBasedFuelTrim`: `_DAT_0040a188 = _DAT_0040a186;...`

**DAT_003fa0e0**
  - In `temperatureBasedFuelTrim`: `_DAT_0040a186 = lookupTableInterpolation(&DAT_003fa0e0,_cool...`
  - In `FUN_0000e8ac`: `_DAT_003fa0e0 = 2;...`

**DAT_0040a188**
  - In `temperatureBasedFuelTrim`: `_DAT_0040a188 = _DAT_0040a186;...`
  - In `temperatureBasedFuelTrim`: `_DAT_0040a188 = _DAT_0040a184;...`

**DAT_0040a18a**
  - In `temperatureBasedFuelTrim`: `_DAT_0040a18a = 0;...`
  - In `temperatureBasedFuelTrim`: `_DAT_0040a18a = _DAT_0040a188 + 0xc000;...`

**DAT_003fe976**
  - In `FUN_00013dc8`: `if ((((_DAT_003fe976 & 8) != 0) && ((DAT_003ff073 & 1) != 0)...`
  - In `FUN_00013dc8`: `((uVar4 = _DAT_0040a456, (_DAT_003fe976 & 0x10) != 0 && ((DA...`

**DAT_003fe97a**
  - In `fuelDemandBaseCalculation`: `if ((((_fuel_demand_fault_flag == 0) && ((_DAT_003fe97a & 0x...`
  - In `fuelDemandSmoothingController`: `_DAT_003fe97a = _DAT_003fe97a & 0xbfff;...`

**DAT_0040bafe**
  - In `FUN_0001df64`: `*(undefined2 *)(param_1 + 0x3fe820) = _DAT_0040bafe;...`
  - In `FUN_0001df64`: `*(undefined2 *)(param_1 + 0x3fe6a0) = _DAT_0040bafe;...`

**DAT_003fadfe**
  - In `j1939_handle_pgn_65262_engine_temp`: `DAT_003fadfe = (undefined1)iVar1;...`
  - In `initPgn65262EngineTempHandler`: `_DAT_003fadf6 = &DAT_003fadfe;...`

**DAT_003fe978**
  - In `j1939_handle_pgn_65262_engine_temp`: `if (((_DAT_003fe978 & 0x8000) == 0) && ((_DAT_003fe97a & 1) ...`
  - In `FUN_00041938`: `(((_DAT_003fe978 & 0x400) != 0 || ((_DAT_003fe978 & 0x200) !...`

**DAT_003fadff**
  - In `j1939_handle_pgn_65262_engine_temp`: `DAT_003fadff = (undefined1)iVar1;...`

**DAT_0040bb06**
  - In `j1939_handle_pgn_65262_engine_temp`: `local_8[0] = (short)((_DAT_0040bb06 * 0xa0 + -0x50000) / 0x2...`
  - In `FUN_00041368`: `if (((((_DAT_0040bb06 < _DAT_00408eb4) && (_DAT_00408eb0 < _...`

**DAT_003fae00**
  - In `j1939_handle_pgn_65262_engine_temp`: `_DAT_003fae00 = func_0x0050b58c(local_8);...`
  - In `j1939_handle_pgn_65262_engine_temp`: `_DAT_003fae00 = 0xfefe;...`

**DAT_003fadf0**
  - In `j1939_handle_pgn_65262_engine_temp`: `sendJ1939MultiFrame(&DAT_003fadf0);...`
  - In `initPgn65262EngineTempHandler`: `_DAT_003fadf0 = CONCAT13(((byte)_DAT_003fd85a & 7) << 2,0xfe...`

### ADOLPR - Unknown

**DAT_003feff6**
  - In `oilPressureDeltaCalculation`: `if (_DAT_003feff6 != 0) {...`
  - In `FUN_00033488`: `if (_DAT_003feff6 == 0) {...`

**DAT_003feff4**
  - In `oilPressureDeltaCalculation`: `if (_DAT_003feff4 == 0) {...`
  - In `FUN_00033488`: `if (_DAT_003feff4 == 0) {...`

### ADSATH - Unknown

**DAT_0040bab8**
  - In `FUN_00010b28`: `uVar4 = (uint)_DAT_0040bab8 + iVar3 * -2;...`
  - In `FUN_00011290`: `uVar1 = (uint)_DAT_0040a378 - (uint)_DAT_0040bab8;...`

**DAT_0040a3ec**
  - In `FUN_00011290`: `_DAT_0040a394 = _DAT_0040a37a - _DAT_0040a3ec;...`
  - In `throttleBasedFuelCalculation`: `_DAT_0040a3ec = (short)uVar4;...`

**DAT_004002e8**
  - In `throttleBasedFuelCalculation`: `if (_DAT_004002e8 < 0x2001) {...`
  - In `throttleBasedFuelCalculation`: `uVar1 = (uint)_DAT_004002e8 * 0x78 >> 10;...`

**DAT_0040a3fe**
  - In `throttleBasedFuelCalculation`: `_DAT_0040a3fe = (ushort)uVar4;...`
  - In `throttleBasedFuelCalculation`: `uVar4 = ((uint)_DAT_0040a3fe * (uint)_DAT_004002ee) / 0x7fff...`

**DAT_0040a572**
  - In `throttleBasedFuelCalculation`: `uVar2 = FUN_000123dc(0x3fa1b6,_DAT_0040a572,(uVar4 & 0xffff)...`

**DAT_0040a3ea**
  - In `throttleBasedFuelCalculation`: `_DAT_0040a3ea = exponentialMovingAverage(uVar2,&DAT_003fa5ba...`

**DAT_003fa5ba**
  - In `throttleBasedFuelCalculation`: `_DAT_0040a3ea = exponentialMovingAverage(uVar2,&DAT_003fa5ba...`
  - In `initFilterCoefficients`: `_DAT_003fa5ba = 0x4002e2;...`

**DAT_004002ee**
  - In `throttleBasedFuelCalculation`: `uVar4 = ((uint)_DAT_0040a3fe * (uint)_DAT_004002ee) / 0x7fff...`

**DAT_0040a3f0**
  - In `throttleBasedFuelCalculation`: `_DAT_0040a3f0 = (undefined2)uVar4;...`

**DAT_0040baba**
  - In `throttleBasedFuelCalculation`: `_DAT_0040baba = signedFirstOrderFilter((int)sVar3,&DAT_003fa...`
  - In `throttleBasedFuelCalculation`: `unsignedDivision32(0,(uint)_DAT_0040baba << 0xd,0,_DAT_0040b...`

**DAT_003fa5c2**
  - In `throttleBasedFuelCalculation`: `_DAT_0040baba = signedFirstOrderFilter((int)sVar3,&DAT_003fa...`
  - In `initFilterCoefficients`: `_DAT_003fa5c2 = 0x4002e2;...`

### DG - Diagnostics

**DAT_0040a64c**
  - In `FUN_0001c28c`: `*(undefined4 *)(uVar1 * 8 + 0x3fdfde) = _DAT_0040a64c;...`
  - In `FUN_0001c28c`: `(short)_DAT_0040a64c - (short)*(undefined4 *)((uint)_DAT_003...`

**DAT_003fe0da**
  - In `faultTimeoutHandler`: `_DAT_003fe0da = _DAT_003fe0da + -1;...`
  - In `faultTimeoutHandler`: `_DAT_003fe0da = _DAT_003fe0da + -1;...`

**DAT_003fe05a**
  - In `clearFaultFromActiveList`: `if (1 < DAT_003fe05a) {...`
  - In `clearFaultFromActiveList`: `if ((&DAT_003fe05a)[uVar2] == param_1) {...`

**DAT_003fe678**
  - In `faultCodeLookup`: `pbVar3 = &DAT_003fe678;...`
  - In `FUN_0001cea4`: `pbVar2 = &DAT_003fe678;...`

### EP - Engine Protection

**DAT_003fedee**
  - In `FUN_00000428`: `DAT_003fedee = 0;...`
  - In `FUN_00000428`: `DAT_003fedee = 0;...`

**DAT_0040af54**
  - In `FUN_0000ea00`: `((_DAT_0040af54 == 0 || ((_DAT_003fd934 == 0 && (_DAT_0040a1...`
  - In `FUN_00027e4c`: `if (((_DAT_0040af54 != 0) && (uVar6 = _DAT_004070bc, _DAT_00...`

**DAT_0040a272**
  - In `fuelDemandSmoothingController`: `(((uint)_DAT_003fddaa <= uVar2 + DAT_0005c294 || (_DAT_0040a...`
  - In `FUN_0001df64`: `*(undefined2 *)(param_1 + 0x3fe7f9) = _DAT_0040a272;...`

**DAT_0040c080**
  - In `FUN_0001d9b8`: `if ((DAT_0040c080 & 0x10) == 0) {...`
  - In `FUN_0004ef24`: `(&DAT_0040c080)[(int)param_1 >> 3] =...`

**DAT_0040a26a**
  - In `j1939_handle_pgn_65265_cruise_vehicle_speed`: `DAT_003faaf7 = (undefined1)((uint)_DAT_0040a26a * 0x19c >> 0...`
  - In `protectionStateTransitionCheck`: `uVar5 = (uint)_DAT_0040a26a + (uint)_DAT_0040785e;...`

**DAT_003fd5a8**
  - In `FUN_0002a214`: `if (((_DAT_003fd5a8 & 0x20) != 0) && (_DAT_003fafaa == 1)) {...`
  - In `FUN_0002c764`: `if (((((_DAT_003fd5a8 & 1) == 0) || (_DAT_0040a430 == 2)) ||...`

**DAT_003fb146**
  - In `protectionNormalHandler`: `uVar1 = lookupTableInterpolation(&DAT_003fb146,_engine_load_...`
  - In `initProtectionFilterVariables`: `_DAT_003fb146 = 2;...`

**DAT_003fb148**
  - In `protectionNormalHandler`: `uVar2 = lookupTableInterpolation(&DAT_003fb148,_engine_load_...`
  - In `initProtectionFilterVariables`: `_DAT_003fb148 = 2;...`

**DAT_0040b0e8**
  - In `protectionNormalHandler`: `DAT_0040b0e8 = DAT_0040b0e8 | bVar3;...`
  - In `protectionNormalHandler`: `DAT_0040b0e8 = DAT_0040b0e8 | bVar3;...`

### FS - Fuel System

**DAT_003fe974**
  - In `FUN_0000dcdc`: `if ((_DAT_003fe974 & 0x40) == 0) {...`
  - In `FUN_0000dcdc`: `_DAT_003fe974 = _DAT_003fe974 | 0x40;...`

**DAT_003fe9d8**
  - In `FUN_0000dcdc`: `_DAT_003fe9d8 = _DAT_003fe9d8 & 0xffbf;...`
  - In `FUN_0000dcdc`: `_DAT_003fe9d8 = _DAT_003fe9d8 & 0xffbf;...`

**DAT_003fd59e**
  - In `FUN_0000e518`: `if ((_DAT_003fd59e & 1) == 0) {...`
  - In `temperatureBasedFuelTrim`: `if (((_DAT_003fd59e & 1) == 0) && (_DAT_003ff014 != 0)) {...`

**DAT_0040a168**
  - In `FUN_0000e518`: `_DAT_0040a168 = DAT_0005be6c;...`
  - In `FUN_0000e518`: `_DAT_0040a168 = _DAT_0040a16a;...`

**DAT_003ff014**
  - In `temperatureBasedFuelTrim`: `if (((_DAT_003fd59e & 1) == 0) && (_DAT_003ff014 != 0)) {...`

**DAT_0040a184**
  - In `temperatureBasedFuelTrim`: `_DAT_0040a184 =...`
  - In `temperatureBasedFuelTrim`: `if (_DAT_0040a186 < _DAT_0040a184) {...`

**DAT_003fa0de**
  - In `temperatureBasedFuelTrim`: `lookupTableInterpolation(&DAT_003fa0de,_intake_air_temp_sens...`
  - In `FUN_0000e8ac`: `_DAT_003fa0de = 2;...`

**DAT_0040a186**
  - In `temperatureBasedFuelTrim`: `_DAT_0040a186 = lookupTableInterpolation(&DAT_003fa0e0,_cool...`
  - In `temperatureBasedFuelTrim`: `_DAT_0040a188 = _DAT_0040a186;...`

**DAT_003fa0e0**
  - In `temperatureBasedFuelTrim`: `_DAT_0040a186 = lookupTableInterpolation(&DAT_003fa0e0,_cool...`
  - In `FUN_0000e8ac`: `_DAT_003fa0e0 = 2;...`

**DAT_0040a188**
  - In `temperatureBasedFuelTrim`: `_DAT_0040a188 = _DAT_0040a186;...`
  - In `temperatureBasedFuelTrim`: `_DAT_0040a188 = _DAT_0040a184;...`

**DAT_0040a18a**
  - In `temperatureBasedFuelTrim`: `_DAT_0040a18a = 0;...`
  - In `temperatureBasedFuelTrim`: `_DAT_0040a18a = _DAT_0040a188 + 0xc000;...`

**DAT_003fa0f0**
  - In `FUN_0000e8cc`: `_DAT_003fa0f0 = 2;...`
  - In `FUN_0000e8dc`: `lookupTableInterpolation(&DAT_003fa0f0,uVar1 & 0xffff,&DAT_0...`

**DAT_003fa102**
  - In `FUN_0000e8dc`: `_DAT_003fa102 = _DAT_003fa106;...`
  - In `FUN_0000e8dc`: `_DAT_003fa102 = uVar1;...`

**DAT_003fa106**
  - In `FUN_0000e8dc`: `_DAT_003fa102 = _DAT_003fa106;...`
  - In `FUN_0000e8dc`: `_DAT_003fa106 = _DAT_0040a24e - _DAT_003fa102;...`

**DAT_003ff68c**
  - In `FUN_0000e8dc`: `uVar2 = (uint)_DAT_003ff68c;...`
  - In `fuelTimingCompensation`: `uVar2 = (uint)_DAT_003ff68c;...`

**DAT_0040a24e**
  - In `FUN_0000e8dc`: `_DAT_003fa106 = _DAT_0040a24e - _DAT_003fa102;...`
  - In `FUN_0000e8dc`: `if ((int)(_DAT_0040a24e - _DAT_003fa102) < (int)-uVar2) {...`

**DAT_003fa0f8**
  - In `FUN_0000e8dc`: `_DAT_003fa0f8 =...`
  - In `FUN_0000e8dc`: `(short)((int)((uint)_DAT_0040a24e * (uint)(ushort)(0x4000 - ...`

**DAT_0040a1f0**
  - In `FUN_0000e8dc`: `_DAT_0040a1f0 =...`
  - In `fuelTimingCompensation`: `_DAT_0040a1f0 =...`


## Statistics

- Total internal names: 2204
- Variables with suggested matches: 283
