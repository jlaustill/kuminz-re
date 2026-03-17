#pragma once
#include "firmware_types.hpp"

// Function Forward Declarations (from decompiled output)

short huffmanTreeBuilder(int param_1);  // @ 0x00003640
void huffmanDecompress(int param_1,undefined4 param_2);  // @ 0x00003792
void huffmanDecompressMain(void);  // @ 0x00003836
void busyWaitDelayLoop(undefined4 param_1);  // @ 0x00003870
byte portPinTestSequence2(void);  // @ 0x0000388a
void FUN_0000395a(void);  // @ 0x0000395a
undefined4 tpuAndQadcVerification(void);  // @ 0x000039a8
void hardwareInitAndStartup(void);  // @ 0x00003a94
void FUN_00003abe(void);  // @ 0x00003abe
void ramClearWithWatchdog(void);  // @ 0x00003c20
uint FUN_0000ac3c(void);  // @ 0x0000ac3c
void FUN_0000af70(void);  // @ 0x0000af70
void writeHourMeterConversionData(void);  // @ 0x0000b130
void outputControlTimingGenerator(void);  // @ 0x0000b210
ushort rpm_system_state_controller(void);  // @ 0x0000b2aa
void shutdownMinimumSelector21(void);  // @ 0x0000b3b2
ushort FUN_0000b3d0(void);  // @ 0x0000b3d0
void fuelDemandLimitMinimumUpdater(void);  // @ 0x0000b4ce
ushort engineStateFuelLimitInterpolator(void);  // @ 0x0000b4f2
void dmaControllerSetup1(void);  // @ 0x0000b5e4
void rpmParameterPointerSetup(void);  // @ 0x0000b614
void dmaDescriptorSetup2(void);  // @ 0x0000b63e
void initFuelSystemOutputDriver(void);  // @ 0x0000b666
undefined1 FUN_0000b688(undefined4 param_1);  // @ 0x0000b688
void diagnosticMessageQueueWrite(undefined4 param_1);  // @ 0x0000b6e8
void FUN_0000b7bc(void);  // @ 0x0000b7bc
void initADCChannelConfiguration(void);  // @ 0x0000bcf0
uint fuelTimingTransitionStateMachine(void);  // @ 0x0000c180
void fuelTimingModeInit(void);  // @ 0x0000c246
void diagnosticDataBufferSetup(void);  // @ 0x0000c24c
void shutdownMinimumSelector16(void);  // @ 0x0000c2a0
void diagnosticTimingIncrementController(void);  // @ 0x0000c2be
void FUN_0000c2ee(void);  // @ 0x0000c2ee
ushort vp44RpmBasedFaultDetector(void);  // @ 0x0000c326
undefined2 FUN_0000c404(void);  // @ 0x0000c404
uint FUN_0000c496(void);  // @ 0x0000c496
int FUN_0000c4b2(void);  // @ 0x0000c4b2
int fuelModeTransitionCountdownHandler(void);  // @ 0x0000c504
undefined2 FUN_0000c556(void);  // @ 0x0000c556
uint timingProtectionFlagsOrchestrator(void);  // @ 0x0000c582
void phase2_slot_5_handler(void);  // @ 0x0000c658
ushort rpmHistogramAndProtectionStatisticsAccumulator(void);  // @ 0x0000c66a
void fuelParameterPointerSetup(void);  // @ 0x0000c714
void shutdownMinimumSelector15(void);  // @ 0x0000c742
void tpuTimerInitializer(void);  // @ 0x0000c760
void emptyStubFunction1(void);  // @ 0x0000c80c
void modeBasedDataDispatcher(undefined4 param_1);  // @ 0x0000c80e
void FUN_0000c87c(void);  // @ 0x0000c87c
void FUN_0000c87e(void);  // @ 0x0000c87e
void FUN_0000c880(void);  // @ 0x0000c880
void dzgTimingAndPressureControlStateMachine(void);  // @ 0x0000c8a0
void engine_speed_governor(void);  // @ 0x0000c962
void diagnosticDataCopyHandler(void);  // @ 0x0000d0e2
void fuelDeliverySystemInit(void);  // @ 0x0000d0fc
void diagnosticStatus30Setter(void);  // @ 0x0000d18a
void diagnosticStatus2Initializer(undefined4 param_1);  // @ 0x0000d1a4
void diagnosticState2Initializer(void);  // @ 0x0000d218
void dualTableLookupSum(void);  // @ 0x0000d23c
void interpolationTableSetup(void);  // @ 0x0000d280
void initAcControlSystem(void);  // @ 0x0000d286
void acceleratorThrottleFaultDetector(void);  // @ 0x0000d2be
void FUN_0000d3b2(void);  // @ 0x0000d3b2
void fuelArbitratorInit(void);  // @ 0x0000d3bc
void initDerateSystemPointers(void);  // @ 0x0000d3c6
void diagnosticMode10FuelController(void);  // @ 0x0000d3e6
uint FUN_0000d4ae(undefined4 param_1);  // @ 0x0000d4ae
void diagnosticState7Setter(void);  // @ 0x0000d584
void fuelBlendTablePointerSetup(void);  // @ 0x0000d59e
void initBoostProtectionSystem(void);  // @ 0x0000d5e6
void FUN_0000d610(void);  // @ 0x0000d610
void clearKickdownControlState(void);  // @ 0x0000e780
void vp44ControlVariablesReset(void);  // @ 0x0000e97e
uint FUN_0000e998(void);  // @ 0x0000e998
void insiteParameterTableIterator(void);  // @ 0x0000eaec
uint diagnosticMessageTransmissionManager(void);  // @ 0x0000eba4
void activeParamReadFunction(void);  // @ 0x0000ec1e
uint diagnosticCodeTableSearch(undefined4 param_1);  // @ 0x0000ed34
void insiteCommandByteDispatcher(void);  // @ 0x0000ed64
undefined * FUN_0000f716(void);  // @ 0x0000f716
void paramSystemModeController(void);  // @ 0x0000f796
void param_lookup_1(void);  // @ 0x0000f8c6
void param_lookup_3(void);  // @ 0x0000f930
void FUN_0000f99a(void);  // @ 0x0000f99a
void FUN_0000f99c(void);  // @ 0x0000f99c
uint vp44State2TransitionHandler(void);  // @ 0x0000fa06
void FUN_0000fa68(void);  // @ 0x0000fa68
void calculateGovernorDroopSpeed(undefined4 param_1);  // @ 0x0000faa6
void fuelLimitExceedanceStatisticsAccumulator(void);  // @ 0x0000fb26
void fuelSourceOilPressureConditionChecker(void);  // @ 0x0000fbe4
ushort FUN_0000ff48(void);  // @ 0x0000ff48
void initFuelArbitratorThreshold5(void);  // @ 0x0000ff56
void ioControlBasedFuelCalculator(void);  // @ 0x0000ff6c
void throttleTablePointerSetup(void);  // @ 0x000100da
uint bufferDecreasingPatternCheck(void);  // @ 0x0001011c
uint bufferThresholdValidator(void);  // @ 0x000101b8
undefined2 retarderModeThresholdCalculator(undefined4 param_1);  // @ 0x0001025c
void canBusTimingInit(void);  // @ 0x00010394
void sendCanMessage(undefined4 *param_1);  // @ 0x000104e8
void sendJ1939MultiFrameWrapper(void);  // @ 0x00010512
short arrayRangeSum(short *param_1,short *param_2);  // @ 0x00010520
void memoryPatchCountDecrement(void);  // @ 0x00010536
uint rpmDerateCalculationController(void);  // @ 0x00010568
ulonglong derateThresholdMonitorAndFaultController(void);  // @ 0x00010822
void FUN_00010e06(void);  // @ 0x00010e06
uint calibrationDataCopyWithChecksum(void);  // @ 0x00010e80
uint calibrationDataCopySecondary(void);  // @ 0x00010f32
undefined4 eepromCalibrationWriteSecondary(void);  // @ 0x00010fe0
undefined4 FUN_0001125a(void);  // @ 0x0001125a
void validateRedundantSensors(void);  // @ 0x000114d4
void firmwareDataCopyToWorkingMemory(void);  // @ 0x000117ec
undefined1 FUN_0001183e(void);  // @ 0x0001183e
undefined1 default(void);  // @ 0x00011880
uint waterInFuelDetectionStateInit(void);  // @ 0x0001188c
undefined1 waterInFuelFaultClear(void);  // @ 0x000118b2
uint FUN_000118cc(void);  // @ 0x000118cc
undefined1 activateHighRpmShutdownFlag(void);  // @ 0x000118fc
void eepromWriteWrapper(undefined4 param_1);  // @ 0x00011908
void triggerDiagnosticSystemReset(void);  // @ 0x0001191a
undefined4 FUN_0001192a(undefined2 param_1,undefined4 param_2);  // @ 0x0001192a
undefined1 FUN_00011a68(void);  // @ 0x00011a68
undefined4 FUN_00011a74(void);  // @ 0x00011a74
void systemFunction8xMaximum(void);  // @ 0x00011b36
undefined4 crc16Calculate(byte *param_1,undefined4 param_2);  // @ 0x00011da6
undefined4 memoryPatchCrcCalculate(void);  // @ 0x00011df8
ushort coldStartFuelControlSlowCycle40Coordinator(void);  // @ 0x00011e5e
void FUN_00012484(void);  // @ 0x00012484
void initLoadTrendingSystem(void);  // @ 0x000124d2
void FUN_0001266e(void);  // @ 0x0001266e
void fuelSourceMode11CountdownHandler(void);  // @ 0x0001277c
void FUN_000127c2(void);  // @ 0x000127c2
void FUN_000133fc(void);  // @ 0x000133fc
void FUN_000133fe(void);  // @ 0x000133fe
void circularBufferWriteWithStatus(void);  // @ 0x0001355e
uint vp44_communication_state_machine(undefined4 param_1);  // @ 0x00013616
void initVp44BufferAddresses(void);  // @ 0x000138a0
uint FUN_000138b6(void);  // @ 0x000138b6
undefined * FUN_00013a5c(void);  // @ 0x00013a5c
void FUN_00013cc8(void);  // @ 0x00013cc8
undefined4 FUN_00013d42(void);  // @ 0x00013d42
void FUN_00013dbe(void);  // @ 0x00013dbe
void FUN_00013e12(void);  // @ 0x00013e12
void FUN_00013e64(void);  // @ 0x00013e64
undefined4 FUN_00013ed8(undefined4 param_1);  // @ 0x00013ed8
void FUN_00014292(undefined1 *param_1,undefined1 *param_2);  // @ 0x00014292
undefined4 canBusConfigTypeSelector(undefined4 param_1);  // @ 0x000142a8
void FUN_000142d4(undefined4 param_1);  // @ 0x000142d4
void FUN_00014348(void);  // @ 0x00014348
void multiSpeedParameterInterpolation(void);  // @ 0x000143b6
void fuelDemandPercentageCalculator(void);  // @ 0x0001444e
void diagnosticCodeDebounceHandler(undefined4 param_1);  // @ 0x000144bc
void phase2_sensor_data_processor(void);  // @ 0x0001452e
void FUN_00014670(void);  // @ 0x00014670
short oldestDiagnosticTimestampSearch(undefined4 param_1);  // @ 0x000146b4
void diagnosticCodeRegistrar(undefined4 param_1);  // @ 0x00014720
void FUN_00014812(void);  // @ 0x00014812
void FUN_00014872(void);  // @ 0x00014872
void faultFlagScannerAndProcessor(void);  // @ 0x00014dc6
void insitePidDtcHandler(undefined4 param_1);  // @ 0x00014f42
void initHourMeterSystem(void);  // @ 0x00014fae
byte sampleDiscreteInputPins(void);  // @ 0x00014fca
void ioDriverStrobeHandler(void);  // @ 0x000159ee
void initVP44StatusMonitoring(void);  // @ 0x00015dd0
void FUN_00015df0(void);  // @ 0x00015df0
void initCANBus(void);  // @ 0x00015e06
void emptyStubFunction4(void);  // @ 0x00015f8c
void diagnosticCommandDispatcher(void);  // @ 0x00015f8e
int safeDivideWithClamp(uint param_1,int param_2);  // @ 0x0001645e
uint clampedDivisionCalculator(uint param_1,uint param_2,int param_3);  // @ 0x0001651e
uint param_address_calc(uint param_1,undefined4 param_2);  // @ 0x000165f2
uint limitedDivisionCalculator(uint param_1,uint param_2,undefined4 param_3);  // @ 0x00016628
void multiPacketTransmitHandler(void);  // @ 0x0001666c
void multiPacketReceiveHandler(void);  // @ 0x0001686e
uint circularBufferEmptyCheck(void);  // @ 0x00016c2c
uint parameterCircularBufferWrite(int param_1,undefined1 *param_2,undefined4 param_3);  // @ 0x00016c3c
void emptyPlaceholderFunction(void);  // @ 0x00016d4c
void tpuTransmissionTrigger(void);  // @ 0x00016d4e
uint highRpmEngineProtectionStateMachine(void);  // @ 0x00016dd4
ushort fuelTemperatureLimitingSecondary(void);  // @ 0x0001709e
void FUN_00017120(void);  // @ 0x00017120
void canControllerConfigInit(void);  // @ 0x00017150
void derateProtectionSlowCycle20Coordinator(void);  // @ 0x0001717a
void caseD_3(void);  // @ 0x000171aa
uint fuel_limit_arbitrator(void);  // @ 0x000171be
void engineRpmSourceInit(void);  // @ 0x000176de
void rpmBasedFuelLimitCalculator(void);  // @ 0x000177c2
void governorFuelModeBlendCalculator(void);  // @ 0x000178b0
void rpmBasedFuelTimingInterpolation(void);  // @ 0x00017a06
uint frictionalLoadTorqueInterpolator(void);  // @ 0x00017a8e
void rpmSourceSelectorForFrictionalLoad(void);  // @ 0x00017b8a
uint FUN_00017baa(void);  // @ 0x00017baa
void peakTorqueFuelCorrection(void);  // @ 0x00017ca6
void engineModeTransitionStateUpdater(void);  // @ 0x00017cf0
void engineModeTransitionHandler(void);  // @ 0x00017d2a
void ioOutputFlagMappingSlowCycle40Coordinator(void);  // @ 0x00017d6a
void frictionalLoadTorqueManagementSlowCycle40Coordinator(void);  // @ 0x00017e06
void engineOperatingModeStateTrackingSlowCycle40Coordinator(void);  // @ 0x00017e62
void frictionalLoadTorqueTransitionHandler(void);  // @ 0x00017eba
void fuelLimitParameterPointerSetup(void);  // @ 0x00017ef8
void vp44TimingFaultMonitor(void);  // @ 0x00017f7c
void FUN_00018384(void);  // @ 0x00018384
void canRpmModeConfigInit(void);  // @ 0x0001839a
ushort FUN_000183cc(void);  // @ 0x000183cc
void FUN_000184c6(void);  // @ 0x000184c6
void FUN_000185f0(void);  // @ 0x000185f0
ushort engineProtectionMultiStateSlowCycle40Coordinator(void);  // @ 0x00018620
ushort protectionThresholdCalculationHelper (int param_1,int param_2,ushort *param_3,undefined4 param_4);  // @ 0x000186ae
undefined4 protectionPercentageCalculator(undefined4 param_1,undefined4 param_2);  // @ 0x00018708
void engineProtectionSystemInit(void);  // @ 0x0001873e
uint protectionConditionEvaluator(ushort *param_1,undefined4 *param_2,undefined4 param_3);  // @ 0x00018968
void protectionState0FaultDurationCounter(void);  // @ 0x00018a26
uint diagnosticProtectionEvaluator(void);  // @ 0x00018ac4
ushort diagnosticProtectionProcessor(ushort *param_1,int param_2,int param_3);  // @ 0x00018c1c
ushort protectionState1DiagnosticValidator(void);  // @ 0x00018cb6
void FUN_00018e0c(void);  // @ 0x00018e0c
void protectionThresholdPointerInit(void);  // @ 0x00018f4c
void protectionStateUpdater(int param_1,int param_2,undefined4 param_3);  // @ 0x00018f86
ushort FUN_00018fcc(void);  // @ 0x00018fcc
void FUN_000192e0(void);  // @ 0x000192e0
uint protectionCalculationHelper(undefined4 param_1,uint param_2);  // @ 0x000192f2
ushort protectionStateProcessor(undefined4 param_1);  // @ 0x00019332
undefined8 protectionStateValidator(undefined4 param_1);  // @ 0x00019436
void protectionState3bRpmMonitor(void);  // @ 0x0001952c
void shutdownMinimumSelector29(void);  // @ 0x000196e4
void FUN_00019702(void);  // @ 0x00019702
void initShutdownLimitVariables(void);  // @ 0x00019960
void can1TimerBufferInitDivided(void);  // @ 0x0001999c
void phase2_slot_0_handler(void);  // @ 0x000199fa
void delayWithWatchdogServiceWrapper2(void);  // @ 0x00019ac2
void emptyStubFunction7(void);  // @ 0x00019aca
undefined8 rpmTimerInterruptHandler2(void);  // @ 0x00019acc
void FUN_00019caa(void);  // @ 0x00019caa
void can1MessageTransmitInit2(void);  // @ 0x00019dd0
void FUN_00019e8e(void);  // @ 0x00019e8e
undefined8 FUN_00019e90(void);  // @ 0x00019e90
void rpmTimingDeltaComparatorWithReturn(void);  // @ 0x0001a1e0
void FUN_0001a298(void);  // @ 0x0001a298
void FUN_0001a350(void);  // @ 0x0001a350
void FUN_0001a47c(void);  // @ 0x0001a47c
void FUN_0001a52a(void);  // @ 0x0001a52a
undefined8 FUN_0001a52c(void);  // @ 0x0001a52c
undefined8 crankFuelAndTimingBufferStore(void);  // @ 0x0001a6e8
uint can1TimerBufferInitConditional(void);  // @ 0x0001a746
void FUN_0001a89a(void);  // @ 0x0001a89a
void FUN_0001a8a2(void);  // @ 0x0001a8a2
undefined8 FUN_0001a8a4(void);  // @ 0x0001a8a4
int throttleTimeAccumulatorProcessor(uint param_1,undefined4 param_2);  // @ 0x0001a95a
int vp44FaultThresholdTablesInit(void);  // @ 0x0001a95e
ushort FUN_0001abb2(void);  // @ 0x0001abb2
void FUN_0001ade8(void);  // @ 0x0001ade8
void initOilPressureModeSystem(void);  // @ 0x0001ae06
void sensorHistoryTablePointerInit(void);  // @ 0x0001ae0c
void dutyCycleMonitorAltCanInit(void);  // @ 0x0001ae22
undefined8 dutyCycleMonitorIsrHandler(void);  // @ 0x0001af32
uint FUN_0001b1ea(void);  // @ 0x0001b1ea
undefined8 FUN_0001b30a(void);  // @ 0x0001b30a
void dutyCycleMonitorBufferInit(void);  // @ 0x0001b39a
void phase2_slot_1_handler(void);  // @ 0x0001b40c
undefined8 FUN_0001b4b2(void);  // @ 0x0001b4b2
undefined8 phase2_slot_8_handler(void);  // @ 0x0001b4c2
void ioDriverStrobeHandlerWrapper(void);  // @ 0x0001b4d0
void evenPhaseSchedulerTaskSet(void);  // @ 0x0001b4d8
void diagnosticMonitoringCoordinator(void);  // @ 0x0001b4ea
void boostPressureControlInit(void);  // @ 0x0001b4f6
void oddPhaseSchedulerTaskSet(void);  // @ 0x0001b504
void vp44_engine_management_system(void);  // @ 0x0001b518
void vp44ControlSystemCoordinator(void);  // @ 0x0001b558
void slowCycle10Coordinator(void);  // @ 0x0001b56a
void periodicTaskSet_governorProtection(void);  // @ 0x0001b572
void engine_control_cycle(void);  // @ 0x0001b57e
void slowCycle20ExtendedCoordinator(void);  // @ 0x0001b5b4
void vp44ExtendedFaultDetectionCoordinator(void);  // @ 0x0001b5ba
void periodicTaskSet_fuelTiming(void);  // @ 0x0001b5ce
void fuelTimingCoordinator(void);  // @ 0x0001b604
void diagnosticDataTransmissionSlowCycle10Coordinator(void);  // @ 0x0001b60a
void periodicTaskSet_fuelDemand(void);  // @ 0x0001b612
void evenPhaseSchedulerTaskSet(void);  // @ 0x0001b62a
void emptyStubFunction3(void);  // @ 0x0001b666
void FUN_0001b668(void);  // @ 0x0001b668
void FUN_0001b66a(void);  // @ 0x0001b66a
void FUN_0001b678(void);  // @ 0x0001b678
void FUN_0001b686(void);  // @ 0x0001b686
void FUN_0001b694(void);  // @ 0x0001b694
void FUN_0001b6a2(void);  // @ 0x0001b6a2
void FUN_0001b6aa(void);  // @ 0x0001b6aa
void FUN_0001b6b2(void);  // @ 0x0001b6b2
void FUN_0001b6b4(void);  // @ 0x0001b6b4
void rpm_control_system(void);  // @ 0x0001b6ba
void emptySlowCycle8PlaceholderCase7(void);  // @ 0x0001b6c6
void FUN_0001b6c8(void);  // @ 0x0001b6c8
void slowCycle20Coordinator(void);  // @ 0x0001b6ce
void empty_debug_hook(void);  // @ 0x0001b6d4
void FUN_0001b6d6(void);  // @ 0x0001b6d6
void emptyStubFunction2(void);  // @ 0x0001b6e2
void FUN_0001b6e4(void);  // @ 0x0001b6e4
void FUN_0001b6f2(void);  // @ 0x0001b6f2
void vp44ProtectionSlowCycle20Coordinator(void);  // @ 0x0001b6f8
void engineModeBasedOutputControlSlowCycle20Coordinator(void);  // @ 0x0001b6fe
void emptySlowCycle20PlaceholderCase15(void);  // @ 0x0001b70a
void dzgTimingAndPressureSlowCycle10Coordinator(void);  // @ 0x0001b70c
void rpmBasedFuelLimiterCoordinator(void);  // @ 0x0001b714
void sensorStatusHistorySlowCycle20Coordinator(void);  // @ 0x0001b71a
void shutdownProtectionSlowCycle10Coordinator(void);  // @ 0x0001b722
void camSyncDiagnosticProcessingSlowCycle20Coordinator(void);  // @ 0x0001b72a
void FUN_0001b732(void);  // @ 0x0001b732
void FUN_0001b73a(void);  // @ 0x0001b73a
void FUN_0001b754(void);  // @ 0x0001b754
void FUN_0001b768(void);  // @ 0x0001b768
void FUN_0001b788(void);  // @ 0x0001b788
void slowCycle8Coordinator(void);  // @ 0x0001b78e
void engineParameterAndBoostControlWrapper(void);  // @ 0x0001b794
void auxiliarySystemControlWrapper(void);  // @ 0x0001b7a2
void FUN_0001b7b0(void);  // @ 0x0001b7b0
void vp44DiagnosticFaultMonitoringSlowCycle20Coordinator(void);  // @ 0x0001b7ca
void FUN_0001b7d2(void);  // @ 0x0001b7d2
void vp44FsoFaultMonitoringSlowCycle20Coordinator(void);  // @ 0x0001b7d8
void FUN_0001b7e0(void);  // @ 0x0001b7e0
void FUN_0001b7e2(void);  // @ 0x0001b7e2
void FUN_0001b7ea(void);  // @ 0x0001b7ea
void FUN_0001b7f2(void);  // @ 0x0001b7f2
void FUN_0001b80c(void);  // @ 0x0001b80c
void FUN_0001b81a(void);  // @ 0x0001b81a
void FUN_0001b828(void);  // @ 0x0001b828
void FUN_0001b836(void);  // @ 0x0001b836
void FUN_0001b83e(void);  // @ 0x0001b83e
void FUN_0001b846(void);  // @ 0x0001b846
void vp44DiagnosticControlSlowCycle20Coordinator(void);  // @ 0x0001b85a
void FUN_0001b862(void);  // @ 0x0001b862
undefined8 FUN_0001b876(void);  // @ 0x0001b876
void scheduler_init(void);  // @ 0x0001bf54
uint circularBufferPush(uint *param_1,undefined4 param_2);  // @ 0x0001bfa2
uint circularBufferPop(uint *param_1,undefined1 *param_2);  // @ 0x0001bfde
void circularBufferInit(undefined4 *param_1,undefined4 param_2,uint param_3);  // @ 0x0001c016
void diagnosticFuelLimitInterpolator(void);  // @ 0x0001c03c
void FUN_0001c0d4(void);  // @ 0x0001c0d4
void fuelTimingOilPressureModeController(void);  // @ 0x0001c152
void FUN_0001c308(void);  // @ 0x0001c308
undefined4 flashEraseWithWatchdog(void);  // @ 0x0001c31a
void FUN_0001c484(undefined4 param_1,undefined4 param_2);  // @ 0x0001c484
undefined4 flashProgramWordWithWatchdog(void);  // @ 0x0001c4ba
void flashProgramFromRam(int param_1,undefined4 param_2,uint param_3);  // @ 0x0001c5e8
void diagnosticStatusDefaultSetter(void);  // @ 0x0001c630
void diagnostic_parameter_handler(void);  // @ 0x0001c640
uint fuelDemandTableBlendCalculator(void);  // @ 0x0001c65e
void FUN_0001c7a8(void);  // @ 0x0001c7a8
void FUN_0001c824(void);  // @ 0x0001c824
ushort FUN_0001c8a0(void);  // @ 0x0001c8a0
void fuelDemandProportionalCalculationSlowCycle40Coordinator(void);  // @ 0x0001c9d2
ushort fuelDemandLimitSelector11(void);  // @ 0x0001ca54
ushort canPinVp44StatusController(void);  // @ 0x0001ca5c
uint FUN_0001cad6(void);  // @ 0x0001cad6
void FUN_0001cb3c(void);  // @ 0x0001cb3c
void FUN_0001cb48(void);  // @ 0x0001cb48
short calculateBlendedTableValue(undefined4 param_1);  // @ 0x0001cb76
void FUN_0001cc72(void);  // @ 0x0001cc72
void FUN_0001cdf8(void);  // @ 0x0001cdf8
void FUN_0001ce58(void);  // @ 0x0001ce58
void initDiagnosticProtocol(void);  // @ 0x0001ce7c
void FUN_0001d252(void);  // @ 0x0001d252
void update_engine_protection_thresholds(void);  // @ 0x0001d2e4
uint FUN_0001d392(void);  // @ 0x0001d392
void FUN_0001d5a0(void);  // @ 0x0001d5a0
void FUN_0001d94e(void);  // @ 0x0001d94e
uint vp44SensorStatusMonitor(void);  // @ 0x0001d9b4
void FUN_0001db8a(void);  // @ 0x0001db8a
void fuelArbitratorVariablesReset(void);  // @ 0x0001db9a
void FUN_0001dbd8(void);  // @ 0x0001dbd8
void main(void);  // @ 0x0001dbee
void vp44ControlStructureInit(void);  // @ 0x0001dcfc
void diagnosticBufferPointerInit(void);  // @ 0x0001dd2c
void FUN_0001ddb4(void);  // @ 0x0001ddb4
undefined4 FUN_0001de58(void);  // @ 0x0001de58
void subtractAndClampValue(short *param_1);  // @ 0x0001e02a
void FUN_0001e04c(void);  // @ 0x0001e04c
void serialNodeAddressChecker(undefined4 param_1);  // @ 0x0001e056
void serialNodeAddressForwarder(undefined4 param_1);  // @ 0x0001e086
undefined8 FUN_0001e0fa(void);  // @ 0x0001e0fa
void canMessageInterruptHandlerSetup(void);  // @ 0x0001e1a0
void emptyStubWrapper1(void);  // @ 0x0001e1ac
void modeBasedDataDispatcherWrapper(void);  // @ 0x0001e1be
undefined8 serialPort2IsrHandler(void);  // @ 0x0001e1d0
void serialCommunicationIsrRegister(void);  // @ 0x0001e25a
void tpuTimerChannelEnable(void);  // @ 0x0001e266
undefined8 epsPositionSensorIsrHandler(void);  // @ 0x0001e288
void tpuChannelIsrRegister(void);  // @ 0x0001e522
uint serialTransmitHandler(void);  // @ 0x0001e52e
void FUN_0001e5f0(undefined4 param_1);  // @ 0x0001e5f0
undefined8 interruptCounter1Increment(void);  // @ 0x0001e734
undefined8 interruptCounter2Increment(void);  // @ 0x0001e76a
void initVectorTable(void);  // @ 0x0001e77a
uint insiteMultiFrameResponseBuilder(undefined4 param_1);  // @ 0x0001e79a
void insiteMultiFrameContinuation(void);  // @ 0x0001e89e
void insiteLiveDataHandler(void);  // @ 0x0001e956
void responseBufferSpaceCheck(void);  // @ 0x0001eb88
void responseBufferFinalize(void);  // @ 0x0001ec08
void diagnosticMemoryWriteHandler(undefined4 param_1);  // @ 0x0001ec3c
void diagnosticMemoryReadHandler(undefined4 param_1);  // @ 0x0001edae
void diagnosticMessage45Builder(void);  // @ 0x0001f0de
void diagnosticMessage46Builder(void);  // @ 0x0001f2d0
uint FUN_0001f4e8(void);  // @ 0x0001f4e8
void fuelDemandScaleFactorCalculator(void);  // @ 0x0001f84e
uint engineFluidLevelDataBuilder(void);  // @ 0x0001f8bc
void extendedDiagnosticService51(void);  // @ 0x0001fbb0
void diagnosticMessage53Builder(void);  // @ 0x0001fbf4
void diagnosticMessage54Builder(void);  // @ 0x0001fc9c
uint j1939TimeoutDataClearHandler(void);  // @ 0x0001fd6c
void crankStateVariablesReset(void);  // @ 0x0001fd8e
uint j1939MessageTypeCounter(undefined4 param_1);  // @ 0x0001fdc0
void canMessageFilterInit(void);  // @ 0x0001fe40
ushort engineRunTimeHistogramAccumulator(void);  // @ 0x0001ff38
void emptyPlaceholderInit(void);  // @ 0x0001ffd0
uint j1939TorqueControlModeParser(int param_1,undefined4 param_2);  // @ 0x0001ffd6
void j1939TorqueControlModeClear(undefined4 param_1);  // @ 0x000200a4
void j1939TorqueControlModeSet(undefined4 param_1);  // @ 0x000200b4
void systemFunction6xParameterized(void);  // @ 0x000200c6
void FUN_000201d6(undefined4 param_1);  // @ 0x000201d6
void FUN_00020210(undefined4 param_1);  // @ 0x00020210
void FUN_0002024a(undefined4 param_1);  // @ 0x0002024a
uint FUN_00020284(void);  // @ 0x00020284
uint FUN_000202a0(void);  // @ 0x000202a0
uint FUN_000202bc(void);  // @ 0x000202bc
void setBitInArray(undefined4 param_1);  // @ 0x000202d8
void FUN_00020310(undefined4 param_1);  // @ 0x00020310
void FUN_00020348(undefined4 param_1);  // @ 0x00020348
uint FUN_00020380(void);  // @ 0x00020380
uint FUN_0002041c(void);  // @ 0x0002041c
uint outputControlState1Handler(void);  // @ 0x000204b0
void FUN_000205c4(void);  // @ 0x000205c4
uint FUN_000206a8(uint param_1,uint param_2);  // @ 0x000206a8
uint FUN_00020784(void);  // @ 0x00020784
uint FUN_00020890(undefined4 param_1);  // @ 0x00020890
uint FUN_00020c98(void);  // @ 0x00020c98
uint FUN_00020e14(void);  // @ 0x00020e14
uint FUN_00020fac(void);  // @ 0x00020fac
void FUN_00021070(void);  // @ 0x00021070
void FUN_00021146(void);  // @ 0x00021146
void FUN_000211f4(void);  // @ 0x000211f4
uint FUN_000212b2(void);  // @ 0x000212b2
ushort FUN_0002142c(void);  // @ 0x0002142c
uint memoryOperationDispatcher(int param_1,short param_2,uint param_3);  // @ 0x0002148a
void j1939DataCopyWrapper2Byte(int param_1);  // @ 0x0002167e
void FUN_000216c6(int param_1);  // @ 0x000216c6
void j1939DataCopyWrapperExtended(int param_1);  // @ 0x00021714
void FUN_00021778(int param_1);  // @ 0x00021778
void memoryOperationFromMessageExtended(int param_1);  // @ 0x000217de
void FUN_00021826(int param_1);  // @ 0x00021826
void FUN_00021872(void);  // @ 0x00021872
undefined4 byteSwap32(undefined4 *param_1);  // @ 0x000218ca
undefined2 byteSwap16(undefined2 *param_1);  // @ 0x000218fe
byte FUN_00021920(void);  // @ 0x00021920
uint addressLookupFunction(undefined4 param_1);  // @ 0x00021964
undefined4 diagnosticServiceSecurityValidator(int param_1);  // @ 0x00021982
void FUN_00021a8c(int param_1);  // @ 0x00021a8c
void FUN_00021b88(int param_1);  // @ 0x00021b88
void FUN_00021c74(int param_1);  // @ 0x00021c74
void FUN_00021d44(int param_1);  // @ 0x00021d44
void FUN_00021edc(void);  // @ 0x00021edc
void FUN_00021ef6(void);  // @ 0x00021ef6
void diagnosticGroupPositionBufferStore(undefined4 param_1);  // @ 0x00021f4e
void diagnosticGroupSnapshotCapture(undefined4 param_1);  // @ 0x00021fac
uint memoryRegisterController(void);  // @ 0x00022070
undefined4 canDiagnosticResponseSender(undefined1 *param_1);  // @ 0x000222b4
void systemFunction1xCaller(void);  // @ 0x00022370
undefined4 diagMemoryReadResponseBuilder(byte *param_1,uint param_2,uint param_3);  // @ 0x0002238e
void FUN_00022530(int param_1);  // @ 0x00022530
void FUN_0002257c(int param_1);  // @ 0x0002257c
void FUN_000225e0(int param_1);  // @ 0x000225e0
void FUN_00022646(int param_1);  // @ 0x00022646
void FUN_0002268e(int param_1);  // @ 0x0002268e
void FUN_000226da(void);  // @ 0x000226da
void sendJ1939MultiFrame(uint *param_1);  // @ 0x00022726
void diagnosticParamRequestHandler(int param_1);  // @ 0x00022956
void messageErrorHandler(undefined4 param_1);  // @ 0x000229ea
void vp44CanFrameBuilder(undefined4 param_1);  // @ 0x00022a58
undefined1 vp44MessageTransmitter(undefined4 param_1,undefined2 param_2);  // @ 0x00022ad8
void vp44FuelTempHandler(undefined4 *param_1);  // @ 0x00022b50
void vp44MultiFrameResponseHandler(int param_1);  // @ 0x00022c26
void diagnosticStatusRequestHandler(int param_1);  // @ 0x00022d8e
void diagnosticErrorHandler(int param_1);  // @ 0x00022de2
void diagnosticServiceByteHandler(void);  // @ 0x00022de6
void vp44CanMessageDispatcher(int param_1);  // @ 0x00022e5e
void diagnosticParamRequestHandlerWrapper(void);  // @ 0x00022e96
void vp44FuelTempHandlerWrapper(void);  // @ 0x00022ea4
void diagnosticStatusRequestHandlerWrapper(void);  // @ 0x00022eb2
void diagnosticErrorHandlerWrapper(void);  // @ 0x00022ec0
void unknownMessageHandler(uint param_1);  // @ 0x00022ece
void diagnosticMessageProcessor(void);  // @ 0x00022fae
void vp44ResponseTimeoutHandler(void);  // @ 0x000230d6
void messageQueueDispatcher(void);  // @ 0x000230ee
undefined4 multiPacketBufferAllocator(undefined4 param_1);  // @ 0x00023130
void vp44DiagnosticBufferPointersInit(void);  // @ 0x00023186
void fuelArbitratorResetHandler(void);  // @ 0x000231da
void FUN_00023216(void);  // @ 0x00023216
void statisticsTrackingFlagsReset(void);  // @ 0x0002322a
uint fuelDemandLimitOrchestrator(void);  // @ 0x00023244
uint diagnosticMessageValidator(undefined4 param_1,undefined4 param_2);  // @ 0x00023820
uint ioControlTimeoutTableLookup(undefined4 param_1);  // @ 0x00023870
void ioControlEntryAdd(undefined4 param_1,undefined4 param_2);  // @ 0x000238ac
void ioControlTimeoutEntryAdd(undefined4 param_1);  // @ 0x000238ec
void phase3_countdown_timer_manager(void);  // @ 0x00023920
void diagnosticStateInitializer(undefined4 param_1);  // @ 0x000239d2
void ioControlEntryRemove(undefined4 param_1);  // @ 0x00023a3c
ushort lampDriverOutputDispatcher(void);  // @ 0x00023a90
void FUN_00023be8(void);  // @ 0x00023be8
void FUN_00024804(void);  // @ 0x00024804
void iahDisableWaitToStartLamp(void);  // @ 0x00024812
void initIoControlRegister(void);  // @ 0x0002481e
void ioControlMaskInit(void);  // @ 0x0002482e
void ioControlMaskStateMachine(void);  // @ 0x00024858
uint ioControlToggleCycle(void);  // @ 0x000249b6
undefined1 ioControlLampStateMachine(void);  // @ 0x000249ee
uint ioControlDigitDisplaySequencer(undefined4 param_1);  // @ 0x00024b4e
byte FUN_00024c5a(undefined4 param_1);  // @ 0x00024c5a
byte FUN_00024cd2(undefined4 param_1);  // @ 0x00024cd2
int faultCodeDisplayController(void);  // @ 0x00024d40
void activeFaultLampStateMachine(void);  // @ 0x00024f30
void faultLampBlinkPatternGenerator(void);  // @ 0x00025316
void FUN_000253b0(void);  // @ 0x000253b0
void periodicLampFlashController(void);  // @ 0x00025448
void FUN_000254b6(void);  // @ 0x000254b6
void clearSystemErrorStatus(void);  // @ 0x00025594
void FUN_0002571e(void);  // @ 0x0002571e
void FUN_00025806(undefined4 param_1);  // @ 0x00025806
void FUN_000258b0(void);  // @ 0x000258b0
void fuelDemandTablePointerInit(void);  // @ 0x000258d6
void epsTimingCalculationSlowCycle40Coordinator(void);  // @ 0x000258e8
void initLookupTablePointers1(void);  // @ 0x00025926
void governorFuelPidController(void);  // @ 0x0002595a
void fuel_delivery_controller(void);  // @ 0x00025a30
void FUN_00025a34(void);  // @ 0x00025a34
void fuel_timing_calculation_with_fault_checking(void);  // @ 0x00025b1c
void fuelRpmDeviationCalculator(void);  // @ 0x00025ff2
void FUN_00026078(void);  // @ 0x00026078
uint epsAccelerationMonitor(void);  // @ 0x0002609c
void epsRpmTrackingInit(void);  // @ 0x00026252
void epsControlModeReset(void);  // @ 0x0002626a
uint epsOverrideChecker(undefined4 param_1);  // @ 0x00026272
void epsControlModeSelector(void);  // @ 0x0002629e
void epsInitializationWrapper(void);  // @ 0x000262fa
void epsControlModeInit(void);  // @ 0x00026308
void epsDiagnosticModeHandler(void);  // @ 0x00026340
void initOilPressureMonitoring(void);  // @ 0x00026462
void engineModeTimingAdjuster(void);  // @ 0x00026474
void vp44_rpm_derate_monitor(void);  // @ 0x00026484
void fuelDemandLimitSource2Selector(void);  // @ 0x0002658c
void initVP44StatusFlags(void);  // @ 0x0002659a
int epsRpmTargetModeChecker(void);  // @ 0x000265e6
void FUN_00026616(void);  // @ 0x00026616
void timingOffsetCalculatorWrapper(void);  // @ 0x000266d2
uint qadcDataCollectionStateMachine(void);  // @ 0x000266da
undefined8 FUN_00026834(void);  // @ 0x00026834
void FUN_00026852(void);  // @ 0x00026852
void FUN_00026854(void);  // @ 0x00026854
void FUN_000269f2(void);  // @ 0x000269f2
void FUN_00026a2e(void);  // @ 0x00026a2e
void memcpy(undefined1 *param_1,undefined1 *param_2,undefined4 param_3);  // @ 0x00026a64
void fuelDemandTablePointersInit(void);  // @ 0x00026a7e
ushort rpmLoadParameterLookup(void);  // @ 0x00026ab8
ushort FUN_00026af0(void);  // @ 0x00026af0
ushort vp44OperatingConditionChecker(void);  // @ 0x00026b00
void FUN_00026b3a(void);  // @ 0x00026b3a
void FUN_00026b82(void);  // @ 0x00026b82
void FUN_00026b88(void);  // @ 0x00026b88
void pwmOutputInit(void);  // @ 0x00026c7e
void fuelSmokeLimiterCalculator(void);  // @ 0x00026cc8
void FUN_00026e2c(void);  // @ 0x00026e2c
void FUN_00026e86(void);  // @ 0x00026e86
void FUN_00026e8e(void);  // @ 0x00026e8e
void insiteActiveFaultListBuilder(void);  // @ 0x00026eec
void insiteFaultDetailBuilder(void);  // @ 0x00026fea
void insiteVersionInfoBuilder(void);  // @ 0x0002758e
void insiteCapacityResponseBuilder(void);  // @ 0x00027706
void FUN_000277e6(void);  // @ 0x000277e6
void hourMeterEventLogger(void);  // @ 0x00027998
void vp44StatusInitAndWait(void);  // @ 0x00027af0
void FUN_00027c20(void);  // @ 0x00027c20
void FUN_00027cd0(undefined4 param_1);  // @ 0x00027cd0
void FUN_00027f9c(void);  // @ 0x00027f9c
void FUN_000284e8(void);  // @ 0x000284e8
void mainSystemInitialization(void);  // @ 0x00028508
void slowCycle4Coordinator(void);  // @ 0x0002874a
void engineDiagnosticSystemCoordinator(void);  // @ 0x00028792
void fuelDemandUpdateOrchestrator(void);  // @ 0x00028816
void advancedEngineProtectionCoordinator(void);  // @ 0x00028828
void shutdownMinimumSelectorOrchestrator(void);  // @ 0x00028936
void FUN_00028978(void);  // @ 0x00028978
void phase4InitSequence(void);  // @ 0x00028990
void dualCanControllerInit(void);  // @ 0x00028a04
void canTransmissionScheduler(void);  // @ 0x00028b80
void mainCanTransmissionLoop(void);  // @ 0x00028e32
undefined2 FUN_00029130(void);  // @ 0x00029130
short FUN_0002c834(int param_1);  // @ 0x0002c834
void FUN_0002c986(int param_1,undefined4 param_2);  // @ 0x0002c986
void FUN_0002ca2a(void);  // @ 0x0002ca2a
void FUN_0002ca64(undefined4 param_1);  // @ 0x0002ca64
byte FUN_0002ca7e(void);  // @ 0x0002ca7e
void FUN_0002cb4e(void);  // @ 0x0002cb4e
undefined4 FUN_0002cb9c(void);  // @ 0x0002cb9c
void FUN_0002cc88(void);  // @ 0x0002cc88
void FUN_0002ce14(void);  // @ 0x0002ce14
void FUN_0002ce64(void);  // @ 0x0002ce64
void FUN_0002cf52(undefined1 *param_1,undefined4 param_2);  // @ 0x0002cf52
uint FUN_0002cf7e(undefined4 param_1);  // @ 0x0002cf7e
void systemControl64(void);  // @ 0x0002d09e
void systemControl74(void);  // @ 0x0002d1c2
void systemControl75(void);  // @ 0x0002d1e0
void memoryPatchBufferInit(void);  // @ 0x0002d1fe
uint memoryPatchingSystem(void);  // @ 0x0002d216
void FUN_0002d3c6(void);  // @ 0x0002d3c6
void FUN_0002d9a8(void);  // @ 0x0002d9a8
void fuelDemandProportionalCalculator(void);  // @ 0x0002d9d2
void FUN_0002db2a(void);  // @ 0x0002db2a
void FUN_0002dbde(void);  // @ 0x0002dbde
void rpmSnapshotCapture(void);  // @ 0x0002dc8c
void FUN_0002dc9e(void);  // @ 0x0002dc9e
uint oil_pressure_shutdown_controller(void);  // @ 0x0002dcb0
void FUN_0002ddbc(void);  // @ 0x0002ddbc
void hardwareTimerFlagsInit(void);  // @ 0x0002ddce
void initDiagnosticModeSystem(void);  // @ 0x0002ddd6
uint oilPressureRpmFaultMonitor(void);  // @ 0x0002dde8
uint waterInFuelDiagnosticHandler(void);  // @ 0x0002e2f4
uint pwmFuelDemandOutputCalculator(void);  // @ 0x0002e5c0
void initQADC(void);  // @ 0x0002e95e
void clearWorkingMemory(void);  // @ 0x0002e9ac
void canMemoryPointerTableInit(void);  // @ 0x0002e9f8
void canMessageMemorySyncController(void);  // @ 0x0002eadc
void FUN_0002ec50(void);  // @ 0x0002ec50
void FUN_0002ed62(void);  // @ 0x0002ed62
char insiteParameterParser(void);  // @ 0x0002ed6a
undefined2 parameterLookupForInsite(void);  // @ 0x0002edb2
void diagnosticServiceDispatcher(int param_1);  // @ 0x0002eea2
void systemControlFunction1(void);  // @ 0x0002ef08
void diagnosticResponseHandler2(undefined4 param_1);  // @ 0x0002ef1c
void canTransmissionTrigger(void);  // @ 0x0002ef36
void FUN_0002ef4a(int param_1);  // @ 0x0002ef4a
void systemControlFunction2(void);  // @ 0x0002efbc
ushort diagnosticServiceDispatcherByPgn(int param_1);  // @ 0x0002efd0
void systemControlFunction3(void);  // @ 0x0002f114
void torqueControlModeHandler(int param_1);  // @ 0x0002f128
void FUN_0002f4be(int param_1);  // @ 0x0002f4be
void diagnosticDataDump(void);  // @ 0x0002f538
uint FUN_0002f606(undefined4 param_1);  // @ 0x0002f606
void FUN_0002f632(void);  // @ 0x0002f632
void retarderControlModeHandler(int param_1);  // @ 0x0002f7e6
void FUN_0002faa4(void);  // @ 0x0002faa4
void initOilPressureProtectionPointers(void);  // @ 0x0002faba
void torqueControlAddressDispatcher(int param_1);  // @ 0x0002fb70
void FUN_0002fbb2(void);  // @ 0x0002fbb2
void FUN_0002fbd8(int param_1,int param_2);  // @ 0x0002fbd8
undefined1 FUN_0002fcdc(undefined4 param_1);  // @ 0x0002fcdc
void FUN_0002fd90(undefined4 param_1);  // @ 0x0002fd90
void diagnosticTableEntryClear(undefined4 param_1);  // @ 0x0002fddc
void diagnosticTableSnapshotCapture(undefined4 param_1);  // @ 0x0002fe38
undefined8 tpuChannelStateMachine(void);  // @ 0x000300d4
void engineSpeedIsrRegister(void);  // @ 0x00030274
void engineRpmHardwareTimerSetup(void);  // @ 0x00030290
void can1ControllerInit(void);  // @ 0x00030342
void emptyStubFunction9(void);  // @ 0x000303c8
void emptyInitPlaceholder(void);  // @ 0x000303d2
undefined4 accumulatorWithOverflowCarry(uint *param_1,uint *param_2);  // @ 0x000303d4
void runTimeCountersUpdate(void);  // @ 0x00030414
void runTimeCountersUpdateAlt(void);  // @ 0x00030454
byte FUN_00030498(void);  // @ 0x00030498
void rpmHistogramAndAveragingStatistics(void);  // @ 0x000304f4
uint fuelLimitRestoreFromCapture(void);  // @ 0x0003061a
ushort FUN_000306ca(void);  // @ 0x000306ca
ushort FUN_00030a5e(void);  // @ 0x00030a5e
ushort protectionFlagAccumulator(void);  // @ 0x00030a64
void FUN_00030ade(void);  // @ 0x00030ade
undefined8 protectionLimitValueInit(void);  // @ 0x00030b04
void FUN_00030b0e(void);  // @ 0x00030b0e
void fuelDemandLimitSelector4(void);  // @ 0x00030b10
void FUN_00030b34(void);  // @ 0x00030b34
ushort vp44InjectionSystemStateController(void);  // @ 0x00030b62
void shutdownMinimumSelector28(void);  // @ 0x00030bf6
void shutdownMinimumSelector20(void);  // @ 0x00030c14
void FUN_00030c3c(void);  // @ 0x00030c3c
void masterSubsystemInit(void);  // @ 0x00030c78
void initInternalRamAndCAN1(void);  // @ 0x00031428
ushort FUN_00031496(void);  // @ 0x00031496
void FUN_000315be(void);  // @ 0x000315be
ushort FUN_00031a68(void);  // @ 0x00031a68
uint diagnosticSessionValidator(undefined4 param_1);  // @ 0x00031ace
void diagnosticCanResponseSender(int param_1,undefined4 param_2);  // @ 0x00031b22
void canBufferSetup1(void);  // @ 0x00031b96
void FUN_00031bce(void);  // @ 0x00031bce
void j1939MessageSetup_PGN_65265(void);  // @ 0x00031c1a
void FUN_00031c84(void);  // @ 0x00031c84
void FUN_00031ed2(void);  // @ 0x00031ed2
void FUN_00031f30(void);  // @ 0x00031f30
void FUN_00031fee(void);  // @ 0x00031fee
void FUN_00032052(void);  // @ 0x00032052
void engineSerialNumberPGN_65259_Builder(void);  // @ 0x000320f6
byte * diagnosticMultiPacketResponseBuilder(byte *param_1,undefined4 param_2);  // @ 0x0003216a
void diagnosticDM11PGN_65234_Builder(void);  // @ 0x00032244
byte activeDtcListBuilder(void);  // @ 0x000322ae
void engineCoolantPGN_65226_Builder(void);  // @ 0x000323be
byte previousDtcListBuilder(void);  // @ 0x0003241c
void diagnosticDM2PGN_65227_Builder(void);  // @ 0x0003252c
byte buildCanMessage(void);  // @ 0x0003258a
void diagnosticDM4PGN_65229_Builder(void);  // @ 0x000329d2
void diagnosticDM5DataBuilder(void);  // @ 0x00032a42
void diagnosticDM5PGN_65230_Builder(void);  // @ 0x00032ae2
void diagnosticByteResponseSender(undefined4 param_1);  // @ 0x00032b38
void diagnosticDM8PGN_65232_Builder(void);  // @ 0x00032b64
void FUN_00032c22(void);  // @ 0x00032c22
void FUN_00032c76(void);  // @ 0x00032c76
void vp44Message300FaultFlagProcessor(void);  // @ 0x00032c7a
void vp44Command0x100Builder(void);  // @ 0x00032e08
void FUN_00032e4c(void);  // @ 0x00032e4c
void cumminsProprietaryDM_983_Builder(void);  // @ 0x00033064
void configParamCanBuilder(void);  // @ 0x000330c4
void secondaryParamPGN_65247_Builder(void);  // @ 0x00033120
void FUN_00033164(void);  // @ 0x00033164
void engineFluidLevelPGN_65263_Builder(void);  // @ 0x000331ae
void FUN_0003320e(undefined4 *param_1);  // @ 0x0003320e
uint FUN_000333d6(uint param_1);  // @ 0x000333d6
uint FUN_00033460(uint param_1);  // @ 0x00033460
void FUN_000334ec(void);  // @ 0x000334ec
byte FUN_0003366a(void);  // @ 0x0003366a
void FUN_00033692(void);  // @ 0x00033692
void FUN_00033716(void);  // @ 0x00033716
void FUN_00033754(void);  // @ 0x00033754
void FUN_000337c4(void);  // @ 0x000337c4
void engineTemperaturePGN_65262_Builder(void);  // @ 0x00033880
void dutyCycleMonitorAltIsrHandler(void);  // @ 0x000338ea
void cumminsProprietaryTSC_PGN_15728640_Builder(void);  // @ 0x000339b0
void FUN_00033a1e(void);  // @ 0x00033a1e
void FUN_00033a62(void);  // @ 0x00033a62
void retarderConfigPGN_65249_Builder(void);  // @ 0x00033aea
void fuelEconomyDataBuilder(void);  // @ 0x00033b40
void fuelEconomyPGN_65266_Builder(void);  // @ 0x00033c28
void ioControlDataBuilder(void);  // @ 0x00033c6c
void ioControlPGN_65244_Builder(void);  // @ 0x00033ce2
void engineHoursPGN_65252_Builder(void);  // @ 0x00033dfa
void FUN_00033e58(void);  // @ 0x00033e58
void intakeManifoldPGN_65526_Builder(void);  // @ 0x00033eee
void FUN_00033f5a(void);  // @ 0x00033f5a
void cruiseControlPGN_65264_Builder(void);  // @ 0x0003401a
byte vp44CanMessage100ResponseBuilder(void);  // @ 0x0003407a
void FUN_000341e6(void);  // @ 0x000341e6
void FUN_00034232(void);  // @ 0x00034232
void vehicleDistancePGN_65248_Builder(void);  // @ 0x0003429a
void retarderDataBuilder(void);  // @ 0x000342f0
void electronicBrakePGN_65527_Builder(void);  // @ 0x00034334
void FUN_00034394(void);  // @ 0x00034394
void vehicleHoursPGN_65255_Builder(void);  // @ 0x000343d2
void FUN_00034440(void);  // @ 0x00034440
void FUN_000344ce(void);  // @ 0x000344ce
void FUN_00034512(void);  // @ 0x00034512
void FUN_0003452a(void);  // @ 0x0003452a
void initLoopCounter(void);  // @ 0x00034534
void setDiagnosticSourceFromFuelArbitrator(void);  // @ 0x00034540
void setDiagnosticSourceFromEngineFlags(void);  // @ 0x00034564
void engine_protection_coordinator(void);  // @ 0x0003458c
void initMultiSystemParameters(void);  // @ 0x000345c8
undefined4 addressRangeValidator(uint param_1,uint param_2);  // @ 0x0003460e
void pwmTimerMode0Init(void);  // @ 0x00034674
void timerCaptureHardwareInit(void);  // @ 0x00034696
void pwmTimerMode0Reset(void);  // @ 0x0003478c
void pwmTimerMode1ChannelSetup(void);  // @ 0x0003480e
void pwmTimerMode1Update(void);  // @ 0x0003494a
void pwmTimerModeDispatcher(void);  // @ 0x00034a82
undefined8 pwmTimerCycleAdvance(void);  // @ 0x00034b20
void watchdogServiceLoop(undefined4 param_1);  // @ 0x00034bba
void FUN_00034bf8(undefined4 param_1);  // @ 0x00034bf8
ushort vp44FaultRegisterBit2Monitor(void);  // @ 0x00034c36
void liftPumpFuelDeliveryController(void);  // @ 0x00034cc4
void FUN_00034d52(void);  // @ 0x00034d52
void FUN_00034dba(void);  // @ 0x00034dba
short lookupTableInterpolation(short *param_1);  // @ 0x00034de0
undefined4 scaleByRatio(uint param_1,uint param_2,uint param_3);  // @ 0x00035064
undefined4 scaleByRatioSigned(int param_1,int param_2,int param_3);  // @ 0x00035076
undefined8 tableLookup2D(short *param_1);  // @ 0x00035088
