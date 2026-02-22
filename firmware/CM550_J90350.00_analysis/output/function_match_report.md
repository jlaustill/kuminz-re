# Function Matching Report

Generated: 2025-12-17T01:47:15.051Z

## Summary

| Metric | Count | Percentage |
|--------|-------|------------|
| Matched (>80%) | 293 | 36.9% |
| Similar (60-80%) | 350 | 44.1% |
| Not Found (<60%) | 150 | 18.9% |
| **Total** | 793 | 100% |

## Relocation Offset Analysis

Most common address offsets between matched functions:

| Offset | Count | Interpretation |
|--------|-------|----------------|
| +0x6618 | 22 | Target = Source +26136 |
| +0x2368 | 10 | Target = Source +9064 |
| +0x90ca | 10 | Target = Source +37066 |
| +0x4f4c | 9 | Target = Source +20300 |
| +0x4f96 | 9 | Target = Source +20374 |
| +0x3af8 | 8 | Target = Source +15096 |
| +0x6684 | 7 | Target = Source +26244 |
| +0x10a6 | 6 | Target = Source +4262 |
| +0x4f54 | 5 | Target = Source +20308 |
| +0x6110 | 5 | Target = Source +24848 |

## High Confidence Matches (Sample)

| Source | Name | Target | Confidence |
|--------|------|--------|------------|
| 0x00c144 | tpuTimerInitializer | 0x00c760 | 92% |
| 0x00e02c | canBusTimingInit | 0x010394 | 91% |
| 0x01c10e | sendJ1939MultiFrame | 0x022726 | 94% |
| 0x01c538 | vp44FuelTempHandler | 0x022b50 | 94% |
| 0x01c846 | vp44CanMessageDispatcher | 0x022e5e | 100% |
| 0x01ac64 | extendedDiagnosticService51 | 0x01fbb0 | 94% |
| 0x01b1b4 | coreSystemControlFunction | 0x021272 | 92% |
| 0x01b07c | emptyPlaceholderInit | 0x01ffd0 | 94% |
| 0x01b7ca | addressLookupFunction | 0x021964 | 92% |
| 0x01bd76 | diagMemoryReadResponseBuilder | 0x02238e | 100% |
| 0x01bedc | diagMemoryReadWithOffsetBuilder | 0x021642 | 92% |
| 0x01bf18 | diagMemoryReadService43Handler | 0x02167e | 92% |
| 0x01bf64 | diagMemoryReadService46Handler | 0x021714 | 92% |
| 0x01bfc8 | diagMemoryReadService48Handler | 0x021714 | 92% |
| 0x01c02e | diagMemoryReadService4aHandler | 0x0217de | 92% |
| 0x01c3d2 | messageErrorHandler | 0x0229ea | 94% |
| 0x01c4c0 | vp44MessageTransmitter | 0x022ad8 | 94% |
| 0x01c8b6 | unknownMessageHandler | 0x022ece | 94% |
| 0x01c33e | diagnosticParamRequestHandler | 0x022956 | 94% |
| 0x01c076 | diagMemoryReadService4cHandler | 0x0217de | 92% |

## Functions Not Found (Sample)

| Source | Name | Best Score |
|--------|------|------------|
| 0x00a5e2 | messageTypeToChannelMapper | 0% |
| 0x00a6fa | sensorFaultDebounceMonitor | 0% |
| 0x00b0fe | fuelAdjustmentWithFlagUpdate | 0% |
| 0x00b27e | fuelTableBlendResultHandler | 0% |
| 0x00b130 | vp44TimingConditionChecker | 0% |
| 0x00bf2e | derate_application_controller | 0% |
| 0x00c084 | diagnosticStatus7Initializer | 0% |
| 0x00d7c0 | fuelTableBlendInterpolation | 0% |
| 0x00d85e | fuelParameterBlendCalculator | 0% |
| 0x00eacc | initDerateSystem | 0% |
| 0x00eb5a | kickdownSignalSlowCycle40Coordinator | 0% |
| 0x00f9e4 | requestSecuredShutdown | 0% |
| 0x00f9f0 | canMessageBufferLogger | 0% |
| 0x01af38 | timerSchedulerSetup | 0% |
| 0x01b1f4 | timerBasedTaskScheduler | 0% |
| 0x01b314 | phase3_retarder_condition_monitor | 0% |
| 0x01d7d2 | ioControlPinSwitchingWrapper | 0% |
| 0x01d7ec | initTimerCounterDefaults | 0% |
| 0x01d40c | ioControlRegisterBitMapper | 0% |
| 0x01e8a6 | intakeTemperatureTablesInit | 0% |
