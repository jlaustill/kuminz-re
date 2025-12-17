# Task 013: J90350.00 vs J90280.05 Firmware Comparison

## Status: [X] Done

**Started:** 2024-12-17
**Completed:** 2024-12-17

## Goal

Compare the two CM550 firmware versions to identify shared code, understand memory layout differences, and document calibration-specific variations.

## Key Findings

### 1. Overall Similarity

| Metric | Value |
|--------|-------|
| Byte-level identical | 20.2% |
| Function match (>80%) | 293 (36.9%) |
| Function similar (60-80%) | 350 (44.1%) |
| Functions not found | 150 (18.9%) |
| **Combined usable** | **81.0%** |

### 2. Memory Layout Differences

The two firmwares have **completely different memory organizations**:

**J90280.05 (Reference):**
```
0x000000-0x004000  16KB  Erased (0xFF)
0x004000-0x006000   8KB  Calibration data
0x006000-0x008000   8KB  Erased (0xFF)
0x008000-0x009000   4KB  Calibration data
0x00a000-0x021000  92KB  Code region 1
0x022000-0x025000  12KB  Compressed data
0x025000-0x036000  68KB  Code region 2
0x036000-0x03b000  20KB  Calibration + data
0x03b000-0x040000  20KB  Erased (0xFF)
```

**J90350.00 (Live ECU):**
```
0x000000-0x003000  12KB  Compressed data
0x003000-0x004000   4KB  Boot code
0x004000-0x00b000  28KB  Calibration data
0x00b000-0x029000 120KB  Code region 1 (main)
0x029000-0x02c000  12KB  Compressed data
0x02d000-0x035000  32KB  Code region 2
0x036000-0x039000  12KB  Calibration data
0x039000-0x040000  28KB  Erased (0xFF)
```

**Key Observation:** J90350.00 has more contiguous code regions and puts compressed data at the start rather than in the middle.

### 3. Function Relocation Analysis

Most common address offsets between matched functions:

| Offset | Count | Meaning |
|--------|-------|---------|
| +0x6618 | 22 | Functions shifted ~26KB forward |
| +0x2368 | 10 | Functions shifted ~9KB forward |
| +0x90ca | 10 | Functions shifted ~37KB forward |
| +0x4f4c | 9 | Functions shifted ~20KB forward |

**Interpretation:** Multiple distinct offsets indicate the code wasn't simply relocated - it was reorganized into different memory regions.

### 4. High-Confidence Function Matches

Core diagnostic and CLIP functions are identical or near-identical:

| Function | J90280.05 | J90350.00 | Confidence |
|----------|-----------|-----------|------------|
| vp44CanMessageDispatcher | 0x01c846 | 0x022e5e | 100% |
| diagMemoryReadResponseBuilder | 0x01bd76 | 0x02238e | 100% |
| sendJ1939MultiFrame | 0x01c10e | 0x022726 | 94% |
| extendedDiagnosticService51 | 0x01ac64 | 0x01fbb0 | 94% |
| vp44FuelTempHandler | 0x01c538 | 0x022b50 | 94% |
| coreSystemControlFunction | 0x01b1b4 | 0x021272 | 92% |
| canBusTimingInit | 0x00e02c | 0x010394 | 91% |

### 5. Functions Not Found (Calibration-Specific)

These functions exist in J90280.05 but have no match in J90350.00:

| Function | Address | Likely Reason |
|----------|---------|---------------|
| messageTypeToChannelMapper | 0x00a5e2 | Different message mapping |
| sensorFaultDebounceMonitor | 0x00a6fa | Different fault logic |
| fuelTableBlendInterpolation | 0x00d7c0 | Different fuel strategy |
| fuelParameterBlendCalculator | 0x00d85e | Calibration-specific |
| initDerateSystem | 0x00eacc | Different derate implementation |
| vp44TimingConditionChecker | 0x00b130 | VP44 timing differences |
| timerSchedulerSetup | 0x01af38 | Task scheduler changes |
| timerBasedTaskScheduler | 0x01b1f4 | Scheduler implementation |

**Hypothesis:** These are calibration-specific functions that vary based on engine configuration (ISB 195hp vs unknown).

### 6. Compressed Regions

Both firmwares contain high-entropy regions suggesting compression:

| Firmware | Location | Size | Entropy |
|----------|----------|------|---------|
| J90280.05 | 0x022000-0x025000 | 12KB | 7.85 |
| J90350.00 | 0x000000-0x003000 | 12KB | 7.86 |
| J90350.00 | 0x029000-0x02c000 | 12KB | 7.82 |

**Note:** J90350.00 has two compressed regions vs one in J90280.05.

## Implications

### For Reverse Engineering

1. **Universal codebase confirmed:** Core functions are identical, proving both firmwares share the same source code
2. **Relocation map enables cross-referencing:** The 643 matched/similar functions can be named in J90350.00 using J90280.05 analysis
3. **Calibration-specific code is isolated:** The 150 unmatched functions represent ISB 195hp-specific logic

### For Future ECU Analysis

1. **Expect different memory layouts:** Each calibration may reorganize code differently
2. **Core functions are stable:** Diagnostic services, VP44 communication, and CAN handlers should match
3. **Focus on unmatched functions:** These reveal calibration-specific behavior

## Files Generated

| File | Description |
|------|-------------|
| `output/relocation_map.csv` | 793 function address mappings |
| `output/function_match_report.md` | Detailed match analysis |
| `output/region_map.md` | Memory region comparison |

## Commands Used

```bash
npm run stats     # Binary statistics
npm run regions   # Memory region identification
npm run match     # Function matching
```

## Related Tasks

- Task 011: RAM dump correlation (completed - informed this analysis)
- Task 014: Import J90350.00 into Ghidra (completed)
- Task 015: Cross-reference function names (completed)
