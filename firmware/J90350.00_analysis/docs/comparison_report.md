# CM550 Firmware Comparison Report

## Executive Summary

Comparison of J90280.05 (reference, fully analyzed) vs J90350.00 (live ECU extraction).

**Bottom Line:** The firmwares share the **same codebase** with different memory layouts and calibration. 81% of functions are found with at least partial similarity. A **selective Ghidra approach** is recommended rather than full re-analysis.

## Key Metrics

| Metric | Value | Interpretation |
|--------|-------|----------------|
| Byte-level similarity | 20.2% | Different memory layout |
| Functions matched (>80%) | 293 (36.9%) | High confidence matches |
| Functions similar (60-80%) | 350 (44.1%) | Moderate matches |
| Functions combined | 643 (81.1%) | Usable for analysis |
| Functions not found | 150 (18.9%) | Need individual analysis |

## Memory Layout Comparison

### J90280.05 (Reference)
| Region | Start | End | Size | Type |
|--------|-------|-----|------|------|
| Erased flash | 0x000000 | 0x004000 | 16KB | Empty |
| Calibration | 0x004000 | 0x006000 | 8KB | EEPROM data |
| Code region 1 | 0x00a000 | 0x021000 | 92KB | Executable |
| Compressed | 0x022000 | 0x025000 | 12KB | High entropy |
| Code region 2 | 0x025000 | 0x036000 | 68KB | Executable |
| Data tables | 0x036000 | 0x03a000 | 16KB | Calibration |

### J90350.00 (Live Extraction)
| Region | Start | End | Size | Type |
|--------|-------|-----|------|------|
| Compressed | 0x000000 | 0x003000 | 12KB | High entropy |
| Boot code | 0x003000 | 0x004000 | 4KB | Initialization |
| Calibration | 0x004000 | 0x00b000 | 28KB | EEPROM data |
| Code region 1 | 0x00b000 | 0x029000 | 120KB | Executable |
| Compressed | 0x029000 | 0x02c000 | 12KB | High entropy |
| Code region 2 | 0x02d000 | 0x035000 | 32KB | Executable |
| Erased flash | 0x039000 | 0x040000 | 28KB | Empty |

## Boot Code Analysis

**Critical Finding:** The boot/initialization code is **structurally identical** between firmwares, confirming same codebase.

| Firmware | Boot Code Address | Content |
|----------|------------------|---------|
| J90350.00 | 0x0020 | `33fc 604f 00ff fa00 33fc 7f08...` |
| J90280.05 | 0x25596 | `33fc 604f 00ff fa00 33fc 7f08...` |

Same MC68336 SIM register initialization sequence with only configuration value differences.

## High-Confidence Function Matches

Functions found with 90%+ confidence (same code, relocated):

| J90280 Address | Name | J90350 Address | Confidence |
|----------------|------|----------------|------------|
| 0x01c846 | vp44CanMessageDispatcher | 0x022e5e | 100% |
| 0x01bd76 | diagMemoryReadResponseBuilder | 0x02238e | 100% |
| 0x01c538 | vp44FuelTempHandler | 0x022b50 | 94% |
| 0x01c10e | sendJ1939MultiFrame | 0x022726 | 94% |
| 0x01ac64 | extendedDiagnosticService51 | 0x01fbb0 | 94% |
| 0x00c144 | tpuTimerInitializer | 0x00c760 | 92% |
| 0x01b1b4 | coreSystemControlFunction | 0x021272 | 92% |
| 0x00e02c | canBusTimingInit | 0x010394 | 91% |

## Functions Not Found

150 functions (18.9%) were not matched. These fall into categories:

1. **Functions in unmapped regions** - Some J90280.05 functions may be in regions we're not searching
2. **Significantly modified functions** - Code changes between firmware versions
3. **Removed/reorganized functions** - Different calibration or feature set

Sample unmatched functions:
- `messageTypeToChannelMapper` (0x00a5e2)
- `sensorFaultDebounceMonitor` (0x00a6fa)
- `derate_application_controller` (0x00bf2e)
- `fuelTableBlendInterpolation` (0x00d7c0)

## Relocation Offset Analysis

No single consistent offset - code was **reorganized**, not simply relocated:

| Offset | Functions | Description |
|--------|-----------|-------------|
| +0x6618 | 22 | Largest cluster |
| +0x2368 | 10 | Secondary cluster |
| +0x90ca | 10 | Secondary cluster |
| +0x4f4c | 9 | |
| +0x4f96 | 9 | |

## Recommendations

### Selective Ghidra Approach

Given 81% function matching, **full re-analysis is NOT required**. Recommended workflow:

1. **Import J90350.00 into Ghidra** with MC68336 memory map
2. **Apply matched function names** using the relocation map (293 high-confidence)
3. **Review similar functions** (350) to verify they're correct matches
4. **Manually analyze** the 150 unmatched functions

### Key Functions to Verify First

1. VP44 communication functions (critical for fuel injection)
2. Diagnostic service handlers (0x4A memory read confirmed working)
3. CAN bus initialization (confirmed similar)
4. Parameter system functions

### Calibration Comparison

The EEPROM/calibration regions show ~48% similarity, indicating:
- Same parameter structure
- Different calibration values (ISB 195hp vs reference tune)
- Parameter addresses likely same (verified through live extraction)

## Files Generated

| File | Description |
|------|-------------|
| `output/relocation_map.csv` | Full function relocation mapping |
| `output/function_match_report.md` | Detailed matching statistics |
| `output/region_map.md` | Memory region analysis |

## Conclusion

J90350.00 and J90280.05 are **variations of the same firmware** with:
- Same core code (81% function similarity)
- Different memory organization
- Different calibration values
- Minor code changes in some areas

The extensive J90280.05 analysis can be **leveraged for J90350.00** with a relocation map, saving significant reverse engineering effort.
