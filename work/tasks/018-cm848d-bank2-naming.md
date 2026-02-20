# Task 018: CM848D Bank 2 Function Naming

## Status
[>] In Progress

## Goal
Name the ~180 unnamed BYTE_005xxxxx (Bank 2) functions in CM848D using CM550 equivalents identified through scheduler position analysis.

## Context

The main_loop scheduler analysis revealed that CM550 and CM848D share identical 40-phase cooperative scheduler architecture. This enables naming functions by their position in the scheduler.

## Analysis Results

### Scheduler Architecture Discovery

Both ECUs use:
- 40-phase round-robin scheduler (phases 0x00-0x27)
- Alternating even/odd phase task sets
- Same task group count and structure

### Direct Equivalents Identified

| CM848D Function | CM550 Equivalent | Confidence |
|-----------------|------------------|------------|
| `phase_common_processing` | `ioControlAndCanPinSwitchingWrapper` | High |
| `phase_group_a_processing` | `evenPhaseSchedulerTaskSet` | High |
| `phase_group_b_processing` | `oddPhaseSchedulerTaskSet` | High |
| `periodicTaskGroup7_timing` | `fuelTimingCoordinator` | Direct |
| `periodicTaskGroup10_monitoring` | `slowCycle10Coordinator` | Direct |
| `periodicTaskGroup11_communication` | `diagnosticCommunicationSlowCycle10Coordinator` | Direct |

### Most-Called BYTE_005xxxxx Functions (Priority Targets)

| Address | Calls | Purpose Identified | Suggested Name |
|---------|-------|-------------------|----------------|
| 0x00501b4c | 29 | Sensor channel Type B processing | `updateSensorChannelTypeB` ✓ |
| 0x005012dc | 27 | Sensor channel Type B init | `sensorChannelTypeB_configInit` ✓ |
| 0x00500a4c | 14 | Sensor channel config update | `updateSensorChannelWithConfig` ✓ |
| 0x00500234 | 14 | Sensor channel config init | `sensorChannelConfigInit` ✓ |
| 0x0050b58c | 13 | Unknown - investigate | Check CM550 faultTableEntryProcessor |
| 0x00510520 | 11 | Called in phase_group_a | Compare CM550 memoryRegisterController |

### High-Value Naming Opportunities

#### 1. Phase Group A Functions (0x0000b7b4)

CM848D `phase_group_a_processing` calls 33 subfunctions. Map to CM550 `evenPhaseSchedulerTaskSet`:
- `timerBasedTaskScheduler` → BYTE_00538ef4 (called at same position)
- `systemStatusProcessor` → BYTE_0050bff4
- `memoryRegisterController` → BYTE_0050d60c
- `messageQueueDispatcher` → BYTE_0050bca0

#### 2. Phase Group B Functions (0x0000b854)

CM848D `phase_group_b_processing` has engine position tracking. Map to CM550 patterns:
- `filterEnginePositionDelta` → Already named (good)
- `updateEnginePositionErrors` → Already named (good)
- BYTE_00532fac → Check CM550 `faultTableEntryProcessor`

#### 3. Calibration Groups 12-38

27 calibration groups mostly call BYTE_* functions. Strategy:
- Trace data flows to identify calibration tables accessed
- Cross-reference with e2m parameter names
- Match patterns to CM550 slowCycle* coordinators

### Workflow for Naming

1. **Pick a BYTE_005xxxxx function by call count**
2. **Find its caller context** - which periodicTaskGroup calls it?
3. **Find CM550 equivalent position** - same phase, same call order
4. **Compare function signatures** - parameter count, types
5. **Compare called subfunctions** - similar call tree depth
6. **Apply name with confidence tag** in CSV comment

### Files Updated

- `/docs/cross-firmware-analysis.md` - Added scheduler comparison section
- `/firmware/feature_comparison.csv` - Added CM848D column
- `/firmware/CM848_S90140.06_analysis/output/function_renames.csv` - Added sensor function names + mapping comments

### Next Actions

1. [ ] Name BYTE_00538ef4 (compare to timerBasedTaskScheduler)
2. [ ] Name BYTE_0050bff4 (compare to systemStatusProcessor)
3. [ ] Name BYTE_0050b58c (13 calls - high priority)
4. [ ] Trace calibration group data flows to e2m parameters
5. [ ] Create CM848D→CM550 position-based relocation map

## Key Insight

The 40-phase scheduler is **Cummins' standard architecture** across ECU generations. This means:
- Function naming can be automated by position matching
- RAM variable layouts may be similar
- Calibration table structures likely share patterns
- Future firmwares (CM870, CM2250) probably use same scheduler
