#pragma once
#include "firmware_types.hpp"

// Function Forward Declarations (from decompiled output)

short mc68k_huffmanTreeBuilder(int param_1);  // @ 0x00003640
void mc68k_huffmanDecompress(int param_1,undefined4 param_2);  // @ 0x00003792
void cm550_huffmanDecompressMain(void);  // @ 0x00003836
void cm550_busyWaitDelayLoop(undefined4 param_1);  // @ 0x00003870
byte mc68k_portPinTestSequence2(void);  // @ 0x0000388a
void mc68k_FUN_0000395a(void);  // @ 0x0000395a
undefined4 mc68k_tpuAndQadcVerification(void);  // @ 0x000039a8
void mc68k_hardwareInitAndStartup(void);  // @ 0x00003a94
void mc68k_FUN_00003abe(void);  // @ 0x00003abe
void mc68k_ramClearWithWatchdog(void);  // @ 0x00003c20
uint cm550_FUN_0000ac3c(void);  // @ 0x0000ac3c
void cm550_FUN_0000af70(void);  // @ 0x0000af70
void cm550_writeHourMeterConversionData(void);  // @ 0x0000b130
void cm550_outputControlTimingGenerator(void);  // @ 0x0000b210
ushort cm550_rpm_system_state_controller(void);  // @ 0x0000b2aa
void cm550_shutdownMinimumSelector21(void);  // @ 0x0000b3b2
ushort cm550_FUN_0000b3d0(void);  // @ 0x0000b3d0
void cm550_fuelDemandLimitMinimumUpdater(void);  // @ 0x0000b4ce
ushort cm550_engineStateFuelLimitInterpolator(void);  // @ 0x0000b4f2
void cm550_dmaControllerSetup1(void);  // @ 0x0000b5e4
void cm550_rpmParameterPointerSetup(void);  // @ 0x0000b614
void cm550_dmaDescriptorSetup2(void);  // @ 0x0000b63e
void cm550_initFuelSystemOutputDriver(void);  // @ 0x0000b666
undefined1 cm550_FUN_0000b688(undefined4 param_1);  // @ 0x0000b688
void cm550_diagnosticMessageQueueWrite(undefined4 param_1);  // @ 0x0000b6e8
void validateServiceDataLength(void);  // @ 0x0000b7bc
void cm550_initADCChannelConfiguration(void);  // @ 0x0000bcf0
uint cm550_fuelTimingTransitionStateMachine(void);  // @ 0x0000c180
void cm550_fuelTimingModeInit(void);  // @ 0x0000c246
void cm550_diagnosticDataBufferSetup(void);  // @ 0x0000c24c
void cm550_shutdownMinimumSelector16(void);  // @ 0x0000c2a0
void cm550_diagnosticTimingIncrementController(void);  // @ 0x0000c2be
void cm550_FUN_0000c2ee(void);  // @ 0x0000c2ee
ushort vp44RpmBasedFaultDetector(void);  // @ 0x0000c326
undefined2 cm550_FUN_0000c404(void);  // @ 0x0000c404
uint cm550_FUN_0000c496(void);  // @ 0x0000c496
int cm550_FUN_0000c4b2(void);  // @ 0x0000c4b2
int cm550_fuelModeTransitionCountdownHandler(void);  // @ 0x0000c504
undefined2 cm550_FUN_0000c556(void);  // @ 0x0000c556
uint timingProtectionFlagsOrchestrator(void);  // @ 0x0000c582
void cm550_phase2_slot_5_handler(void);  // @ 0x0000c658
ushort cm550_rpmHistogramAndProtectionStatisticsAccumulator(void);  // @ 0x0000c66a
void cm550_fuelParameterPointerSetup(void);  // @ 0x0000c714
void cm550_shutdownMinimumSelector15(void);  // @ 0x0000c742
void mc68k_tpuTimerInitializer(void);  // @ 0x0000c760
void cm550_emptyStubFunction1(void);  // @ 0x0000c80c
void cm550_modeBasedDataDispatcher(undefined4 param_1);  // @ 0x0000c80e
void cm550_FUN_0000c87c(void);  // @ 0x0000c87c
void cm550_FUN_0000c87e(void);  // @ 0x0000c87e
void cm550_FUN_0000c880(void);  // @ 0x0000c880
void cm550_dzgTimingAndPressureControlStateMachine(void);  // @ 0x0000c8a0
void cm550_engine_speed_governor(void);  // @ 0x0000c962
void cm550_diagnosticDataCopyHandler(void);  // @ 0x0000d0e2
void cm550_fuelDeliverySystemInit(void);  // @ 0x0000d0fc
void cm550_diagnosticStatus30Setter(void);  // @ 0x0000d18a
void cm550_diagnosticStatus2Initializer(undefined4 param_1);  // @ 0x0000d1a4
void cm550_diagnosticState2Initializer(void);  // @ 0x0000d218
void cm550_dualTableLookupSum(void);  // @ 0x0000d23c
void cm550_interpolationTableSetup(void);  // @ 0x0000d280
void cm550_initAcControlSystem(void);  // @ 0x0000d286
void cm550_acceleratorThrottleFaultDetector(void);  // @ 0x0000d2be
void cm550_FUN_0000d3b2(void);  // @ 0x0000d3b2
void cm550_fuelArbitratorInit(void);  // @ 0x0000d3bc
void cm550_initDerateSystemPointers(void);  // @ 0x0000d3c6
void cm550_diagnosticMode10FuelController(void);  // @ 0x0000d3e6
uint cm550_FUN_0000d4ae(undefined4 param_1);  // @ 0x0000d4ae
void cm550_diagnosticState7Setter(void);  // @ 0x0000d584
void cm550_fuelBlendTablePointerSetup(void);  // @ 0x0000d59e
void cm550_initBoostProtectionSystem(void);  // @ 0x0000d5e6
void updateEngineSyncStatus(void);  // @ 0x0000d610
void cm550_clearKickdownControlState(void);  // @ 0x0000e780
void vp44ControlVariablesReset(void);  // @ 0x0000e97e
uint cm550_FUN_0000e998(void);  // @ 0x0000e998
void vp44_insiteParameterTableIterator(void);  // @ 0x0000eaec
uint cm550_diagnosticMessageTransmissionManager(void);  // @ 0x0000eba4
void cm550_activeParamReadFunction(void);  // @ 0x0000ec1e
uint cm550_diagnosticCodeTableSearch(undefined4 param_1);  // @ 0x0000ed34
void insiteCommandByteDispatcher(void);  // @ 0x0000ed64
undefined * cm550_FUN_0000f716(void);  // @ 0x0000f716
void cm550_paramSystemModeController(void);  // @ 0x0000f796
void cm550_param_lookup_1(void);  // @ 0x0000f8c6
void cm550_param_lookup_3(void);  // @ 0x0000f930
void cm550_FUN_0000f99a(void);  // @ 0x0000f99a
void cm550_FUN_0000f99c(void);  // @ 0x0000f99c
uint vp44State2TransitionHandler(void);  // @ 0x0000fa06
void vp44_FUN_0000fa68(void);  // @ 0x0000fa68
void cm550_calculateGovernorDroopSpeed(undefined4 param_1);  // @ 0x0000faa6
void vp44_fuelLimitExceedanceStatisticsAccumulator(void);  // @ 0x0000fb26
void vp44_fuelSourceOilPressureConditionChecker(void);  // @ 0x0000fbe4
ushort cm550_FUN_0000ff48(void);  // @ 0x0000ff48
void cm550_initFuelArbitratorThreshold5(void);  // @ 0x0000ff56
void cm550_ioControlBasedFuelCalculator(void);  // @ 0x0000ff6c
void cm550_throttleTablePointerSetup(void);  // @ 0x000100da
uint cm550_bufferDecreasingPatternCheck(void);  // @ 0x0001011c
uint cm550_bufferThresholdValidator(void);  // @ 0x000101b8
undefined2 cm550_retarderModeThresholdCalculator(undefined4 param_1);  // @ 0x0001025c
void cm550_canBusTimingInit(void);  // @ 0x00010394
void cm550_sendCanMessage(undefined4 *param_1);  // @ 0x000104e8
void cm550_sendJ1939MultiFrameWrapper(void);  // @ 0x00010512
short cm550_arrayRangeSum(short *param_1,short *param_2);  // @ 0x00010520
void cm550_memoryPatchCountDecrement(void);  // @ 0x00010536
uint vp44_rpmDerateCalculationController(void);  // @ 0x00010568
ulonglong vp44_derateThresholdMonitorAndFaultController(void);  // @ 0x00010822
void cm550_FUN_00010e06(void);  // @ 0x00010e06
uint mc68k_calibrationDataCopyWithChecksum(void);  // @ 0x00010e80
uint mc68k_calibrationDataCopySecondary(void);  // @ 0x00010f32
undefined4 mc68k_eepromCalibrationWriteSecondary(void);  // @ 0x00010fe0
undefined4 mc68k_FUN_0001125a(void);  // @ 0x0001125a
void vp44_validateRedundantSensors(void);  // @ 0x000114d4
void mc68k_firmwareDataCopyToWorkingMemory(void);  // @ 0x000117ec
undefined1 cm550_FUN_0001183e(void);  // @ 0x0001183e
undefined1 default(void);  // @ 0x00011880
uint cm550_waterInFuelDetectionStateInit(void);  // @ 0x0001188c
undefined1 cm550_waterInFuelFaultClear(void);  // @ 0x000118b2
uint cm550_FUN_000118cc(void);  // @ 0x000118cc
undefined1 cm550_activateHighRpmShutdownFlag(void);  // @ 0x000118fc
void cm550_eepromWriteWrapper(undefined4 param_1);  // @ 0x00011908
void cm550_triggerDiagnosticSystemReset(void);  // @ 0x0001191a
undefined4 cm550_FUN_0001192a(undefined2 param_1,undefined4 param_2);  // @ 0x0001192a
undefined1 cm550_FUN_00011a68(void);  // @ 0x00011a68
undefined4 cm550_FUN_00011a74(void);  // @ 0x00011a74
void cm550_systemFunction8xMaximum(void);  // @ 0x00011b36
undefined4 cm550_crc16Calculate(byte *param_1,undefined4 param_2);  // @ 0x00011da6
undefined4 cm550_memoryPatchCrcCalculate(void);  // @ 0x00011df8
ushort cm550_coldStartFuelControlSlowCycle40Coordinator(void);  // @ 0x00011e5e
void cm550_FUN_00012484(void);  // @ 0x00012484
void cm550_initLoadTrendingSystem(void);  // @ 0x000124d2
void mc68k_FUN_0001266e(void);  // @ 0x0001266e
void cm550_fuelSourceMode11CountdownHandler(void);  // @ 0x0001277c
void vp44_FUN_000127c2(void);  // @ 0x000127c2
void cm550_FUN_000133fc(void);  // @ 0x000133fc
void vp44_FUN_000133fe(void);  // @ 0x000133fe
void cm550_circularBufferWriteWithStatus(void);  // @ 0x0001355e
uint vp44_communication_state_machine(undefined4 param_1);  // @ 0x00013616
void vp44_initVp44BufferAddresses(void);  // @ 0x000138a0
uint cm550_FUN_000138b6(void);  // @ 0x000138b6
undefined * cm550_FUN_00013a5c(void);  // @ 0x00013a5c
void cm550_FUN_00013cc8(void);  // @ 0x00013cc8
undefined4 cm550_FUN_00013d42(void);  // @ 0x00013d42
void cm550_FUN_00013dbe(void);  // @ 0x00013dbe
void cm550_FUN_00013e12(void);  // @ 0x00013e12
void cm550_FUN_00013e64(void);  // @ 0x00013e64
undefined4 cm550_FUN_00013ed8(undefined4 param_1);  // @ 0x00013ed8
void cm550_FUN_00014292(undefined1 *param_1,undefined1 *param_2);  // @ 0x00014292
undefined4 cm550_canBusConfigTypeSelector(undefined4 param_1);  // @ 0x000142a8
void cm550_FUN_000142d4(undefined4 param_1);  // @ 0x000142d4
void cm550_FUN_00014348(void);  // @ 0x00014348
void cm550_multiSpeedParameterInterpolation(void);  // @ 0x000143b6
void cm550_fuelDemandPercentageCalculator(void);  // @ 0x0001444e
void cm550_diagnosticCodeDebounceHandler(undefined4 param_1);  // @ 0x000144bc
void cm550_phase2_sensor_data_processor(void);  // @ 0x0001452e
void cm550_FUN_00014670(void);  // @ 0x00014670
short cm550_oldestDiagnosticTimestampSearch(undefined4 param_1);  // @ 0x000146b4
void cm550_diagnosticCodeRegistrar(undefined4 param_1);  // @ 0x00014720
void cm550_FUN_00014812(void);  // @ 0x00014812
void cm550_FUN_00014872(void);  // @ 0x00014872
void cm550_faultFlagScannerAndProcessor(void);  // @ 0x00014dc6
void cm550_insitePidDtcHandler(undefined4 param_1);  // @ 0x00014f42
void cm550_initHourMeterSystem(void);  // @ 0x00014fae
byte injectorTimingCalculation(void);  // @ 0x00014fca
void mc68k_ioDriverStrobeHandler(void);  // @ 0x000159ee
void vp44_initVP44StatusMonitoring(void);  // @ 0x00015dd0
void mc68k_FUN_00015df0(void);  // @ 0x00015df0
void clearModuleSyncFlag(void);  // @ 0x00015e06
void emptyStubFunction4(void);  // @ 0x00015f8c
void diagnosticCommandDispatcher(void);  // @ 0x00015f8e
int cm550_safeDivideWithClamp(uint param_1,int param_2);  // @ 0x0001645e
uint cm550_clampedDivisionCalculator(uint param_1,uint param_2,int param_3);  // @ 0x0001651e
uint cm550_param_address_calc(uint param_1,undefined4 param_2);  // @ 0x000165f2
uint cm550_limitedDivisionCalculator(uint param_1,uint param_2,undefined4 param_3);  // @ 0x00016628
void cm550_multiPacketTransmitHandler(void);  // @ 0x0001666c
void cm550_multiPacketReceiveHandler(void);  // @ 0x0001686e
uint cm550_circularBufferEmptyCheck(void);  // @ 0x00016c2c
uint cm550_parameterCircularBufferWrite(int param_1,undefined1 *param_2,undefined4 param_3);  // @ 0x00016c3c
void cm550_emptyPlaceholderFunction(void);  // @ 0x00016d4c
void mc68k_tpuTransmissionTrigger(void);  // @ 0x00016d4e
uint cm550_highRpmEngineProtectionStateMachine(void);  // @ 0x00016dd4
ushort cm550_fuelTemperatureLimitingSecondary(void);  // @ 0x0001709e
void cm550_FUN_00017120(void);  // @ 0x00017120
void cm550_canControllerConfigInit(void);  // @ 0x00017150
void cm550_derateProtectionSlowCycle20Coordinator(void);  // @ 0x0001717a
void caseD_3(void);  // @ 0x000171aa
uint cm550_fuel_limit_arbitrator(void);  // @ 0x000171be
void cm550_engineRpmSourceInit(void);  // @ 0x000176de
void cm550_rpmBasedFuelLimitCalculator(void);  // @ 0x000177c2
void cm550_governorFuelModeBlendCalculator(void);  // @ 0x000178b0
void cm550_rpmBasedFuelTimingInterpolation(void);  // @ 0x00017a06
uint cm550_frictionalLoadTorqueInterpolator(void);  // @ 0x00017a8e
void cm550_rpmSourceSelectorForFrictionalLoad(void);  // @ 0x00017b8a
uint cm550_FUN_00017baa(void);  // @ 0x00017baa
void cm550_peakTorqueFuelCorrection(void);  // @ 0x00017ca6
void cm550_engineModeTransitionStateUpdater(void);  // @ 0x00017cf0
void cm550_engineModeTransitionHandler(void);  // @ 0x00017d2a
void cm550_ioOutputFlagMappingSlowCycle40Coordinator(void);  // @ 0x00017d6a
void cm550_frictionalLoadTorqueManagementSlowCycle40Coordinator(void);  // @ 0x00017e06
void cm550_engineOperatingModeStateTrackingSlowCycle40Coordinator(void);  // @ 0x00017e62
void cm550_frictionalLoadTorqueTransitionHandler(void);  // @ 0x00017eba
void vp44_fuelLimitParameterPointerSetup(void);  // @ 0x00017ef8
void vp44TimingFaultMonitor(void);  // @ 0x00017f7c
void cm550_FUN_00018384(void);  // @ 0x00018384
void cm550_canRpmModeConfigInit(void);  // @ 0x0001839a
ushort cm550_FUN_000183cc(void);  // @ 0x000183cc
void cm550_FUN_000184c6(void);  // @ 0x000184c6
void cm550_FUN_000185f0(void);  // @ 0x000185f0
ushort cm550_engineProtectionMultiStateSlowCycle40Coordinator(void);  // @ 0x00018620
ushort cm550_protectionThresholdCalculationHelper (int param_1,int param_2,ushort *param_3,undefined4 param_4);  // @ 0x000186ae
undefined4 cm550_protectionPercentageCalculator(undefined4 param_1,undefined4 param_2);  // @ 0x00018708
void vp44_engineProtectionSystemInit(void);  // @ 0x0001873e
uint cm550_protectionConditionEvaluator(ushort *param_1,undefined4 *param_2,undefined4 param_3);  // @ 0x00018968
void protectionState0FaultDurationCounter(void);  // @ 0x00018a26
uint cm550_diagnosticProtectionEvaluator(void);  // @ 0x00018ac4
ushort cm550_diagnosticProtectionProcessor(ushort *param_1,int param_2,int param_3);  // @ 0x00018c1c
ushort cm550_protectionState1DiagnosticValidator(void);  // @ 0x00018cb6
void cm550_FUN_00018e0c(void);  // @ 0x00018e0c
void cm550_protectionThresholdPointerInit(void);  // @ 0x00018f4c
void incrementDiagnosticCounters(int param_1,int param_2,undefined4 param_3);  // @ 0x00018f86
ushort processDiagnosticLimitStatus(void);  // @ 0x00018fcc
void cm550_FUN_000192e0(void);  // @ 0x000192e0
uint cm550_protectionCalculationHelper(undefined4 param_1,uint param_2);  // @ 0x000192f2
ushort protectionStateProcessor(undefined4 param_1);  // @ 0x00019332
undefined8 protectionStateValidator(undefined4 param_1);  // @ 0x00019436
void cm550_protectionState3bRpmMonitor(void);  // @ 0x0001952c
void cm550_shutdownMinimumSelector29(void);  // @ 0x000196e4
void cm550_FUN_00019702(void);  // @ 0x00019702
void cm550_initShutdownLimitVariables(void);  // @ 0x00019960
void mc68k_can1TimerBufferInitDivided(void);  // @ 0x0001999c
void mc68k_phase2_slot_0_handler(void);  // @ 0x000199fa
void cm550_delayWithWatchdogServiceWrapper2(void);  // @ 0x00019ac2
void cm550_emptyStubFunction7(void);  // @ 0x00019aca
undefined8 vp44_rpmTimerInterruptHandler2(void);  // @ 0x00019acc
void mc68k_FUN_00019caa(void);  // @ 0x00019caa
void mc68k_can1MessageTransmitInit2(void);  // @ 0x00019dd0
void cm550_FUN_00019e8e(void);  // @ 0x00019e8e
undefined8 vp44_FUN_00019e90(void);  // @ 0x00019e90
void cm550_rpmTimingDeltaComparatorWithReturn(void);  // @ 0x0001a1e0
void cm550_FUN_0001a298(void);  // @ 0x0001a298
void mc68k_FUN_0001a350(void);  // @ 0x0001a350
void mc68k_FUN_0001a47c(void);  // @ 0x0001a47c
void cm550_FUN_0001a52a(void);  // @ 0x0001a52a
undefined8 vp44_FUN_0001a52c(void);  // @ 0x0001a52c
undefined8 mc68k_crankFuelAndTimingBufferStore(void);  // @ 0x0001a6e8
uint mc68k_can1TimerBufferInitConditional(void);  // @ 0x0001a746
void cm550_FUN_0001a89a(void);  // @ 0x0001a89a
void cm550_FUN_0001a8a2(void);  // @ 0x0001a8a2
undefined8 vp44_FUN_0001a8a4(void);  // @ 0x0001a8a4
int cm550_throttleTimeAccumulatorProcessor(uint param_1,undefined4 param_2);  // @ 0x0001a95a
int vp44FaultThresholdTablesInit(void);  // @ 0x0001a95e
ushort cm550_FUN_0001abb2(void);  // @ 0x0001abb2
void cm550_FUN_0001ade8(void);  // @ 0x0001ade8
void cm550_initOilPressureModeSystem(void);  // @ 0x0001ae06
void cm550_sensorHistoryTablePointerInit(void);  // @ 0x0001ae0c
void mc68k_dutyCycleMonitorAltCanInit(void);  // @ 0x0001ae22
undefined8 mc68k_dutyCycleMonitorIsrHandler(void);  // @ 0x0001af32
uint mc68k_FUN_0001b1ea(void);  // @ 0x0001b1ea
undefined8 mc68k_FUN_0001b30a(void);  // @ 0x0001b30a
void mc68k_dutyCycleMonitorBufferInit(void);  // @ 0x0001b39a
void mc68k_phase2_slot_1_handler(void);  // @ 0x0001b40c
undefined8 mc68k_FUN_0001b4b2(void);  // @ 0x0001b4b2
undefined8 mc68k_phase2_slot_8_handler(void);  // @ 0x0001b4c2
void cm550_ioDriverStrobeHandlerWrapper(void);  // @ 0x0001b4d0
void vp44_evenPhaseSchedulerTaskSet(void);  // @ 0x0001b4d8
void cm550_diagnosticMonitoringCoordinator(void);  // @ 0x0001b4ea
void cm550_boostPressureControlInit(void);  // @ 0x0001b4f6
void cm550_oddPhaseSchedulerTaskSet(void);  // @ 0x0001b504
void vp44_engine_management_system(void);  // @ 0x0001b518
void vp44ControlSystemCoordinator(void);  // @ 0x0001b558
void cm550_slowCycle10Coordinator(void);  // @ 0x0001b56a
void vp44_periodicTaskSet_governorProtection(void);  // @ 0x0001b572
void vp44_engine_control_cycle(void);  // @ 0x0001b57e
void cm550_slowCycle20ExtendedCoordinator(void);  // @ 0x0001b5b4
void vp44ExtendedFaultDetectionCoordinator(void);  // @ 0x0001b5ba
void cm550_periodicTaskSet_fuelTiming(void);  // @ 0x0001b5ce
void cm550_fuelTimingCoordinator(void);  // @ 0x0001b604
void cm550_diagnosticDataTransmissionSlowCycle10Coordinator(void);  // @ 0x0001b60a
void periodicTaskSet_fuelDemand(void);  // @ 0x0001b612
void vp44_evenPhaseSchedulerTaskSet(void);  // @ 0x0001b62a
void emptyStubFunction3(void);  // @ 0x0001b666
void cm550_FUN_0001b668(void);  // @ 0x0001b668
void cm550_FUN_0001b66a(void);  // @ 0x0001b66a
void cm550_FUN_0001b678(void);  // @ 0x0001b678
void cm550_FUN_0001b686(void);  // @ 0x0001b686
void cm550_FUN_0001b694(void);  // @ 0x0001b694
void cm550_FUN_0001b6a2(void);  // @ 0x0001b6a2
void cm550_FUN_0001b6aa(void);  // @ 0x0001b6aa
void cm550_FUN_0001b6b2(void);  // @ 0x0001b6b2
void cm550_FUN_0001b6b4(void);  // @ 0x0001b6b4
void cm550_rpm_control_system(void);  // @ 0x0001b6ba
void cm550_emptySlowCycle8PlaceholderCase7(void);  // @ 0x0001b6c6
void cm550_FUN_0001b6c8(void);  // @ 0x0001b6c8
void cm550_slowCycle20Coordinator(void);  // @ 0x0001b6ce
void cm550_empty_debug_hook(void);  // @ 0x0001b6d4
void cm550_FUN_0001b6d6(void);  // @ 0x0001b6d6
void emptyStubFunction2(void);  // @ 0x0001b6e2
void cm550_FUN_0001b6e4(void);  // @ 0x0001b6e4
void cm550_FUN_0001b6f2(void);  // @ 0x0001b6f2
void vp44ProtectionSlowCycle20Coordinator(void);  // @ 0x0001b6f8
void cm550_engineModeBasedOutputControlSlowCycle20Coordinator(void);  // @ 0x0001b6fe
void cm550_emptySlowCycle20PlaceholderCase15(void);  // @ 0x0001b70a
void cm550_dzgTimingAndPressureSlowCycle10Coordinator(void);  // @ 0x0001b70c
void cm550_rpmBasedFuelLimiterCoordinator(void);  // @ 0x0001b714
void cm550_sensorStatusHistorySlowCycle20Coordinator(void);  // @ 0x0001b71a
void cm550_shutdownProtectionSlowCycle10Coordinator(void);  // @ 0x0001b722
void cm550_camSyncDiagnosticProcessingSlowCycle20Coordinator(void);  // @ 0x0001b72a
void cm550_FUN_0001b732(void);  // @ 0x0001b732
void cm550_FUN_0001b73a(void);  // @ 0x0001b73a
void cm550_FUN_0001b754(void);  // @ 0x0001b754
void cm550_FUN_0001b768(void);  // @ 0x0001b768
void cm550_FUN_0001b788(void);  // @ 0x0001b788
void cm550_slowCycle8Coordinator(void);  // @ 0x0001b78e
void cm550_engineParameterAndBoostControlWrapper(void);  // @ 0x0001b794
void cm550_auxiliarySystemControlWrapper(void);  // @ 0x0001b7a2
void cm550_FUN_0001b7b0(void);  // @ 0x0001b7b0
void vp44DiagnosticFaultMonitoringSlowCycle20Coordinator(void);  // @ 0x0001b7ca
void cm550_FUN_0001b7d2(void);  // @ 0x0001b7d2
void vp44FsoFaultMonitoringSlowCycle20Coordinator(void);  // @ 0x0001b7d8
void cm550_FUN_0001b7e0(void);  // @ 0x0001b7e0
void cm550_FUN_0001b7e2(void);  // @ 0x0001b7e2
void cm550_FUN_0001b7ea(void);  // @ 0x0001b7ea
void vp44_FUN_0001b7f2(void);  // @ 0x0001b7f2
void cm550_FUN_0001b80c(void);  // @ 0x0001b80c
void cm550_FUN_0001b81a(void);  // @ 0x0001b81a
void cm550_FUN_0001b828(void);  // @ 0x0001b828
void cm550_FUN_0001b836(void);  // @ 0x0001b836
void cm550_FUN_0001b83e(void);  // @ 0x0001b83e
void cm550_FUN_0001b846(void);  // @ 0x0001b846
void vp44DiagnosticControlSlowCycle20Coordinator(void);  // @ 0x0001b85a
void cm550_FUN_0001b862(void);  // @ 0x0001b862
undefined8 main_loop(void);  // @ 0x0001b876
void mc68k_scheduler_init(void);  // @ 0x0001bf54
uint cm550_circularBufferPush(uint *param_1,undefined4 param_2);  // @ 0x0001bfa2
uint cm550_circularBufferPop(uint *param_1,undefined1 *param_2);  // @ 0x0001bfde
void cm550_circularBufferInit(undefined4 *param_1,undefined4 param_2,uint param_3);  // @ 0x0001c016
void cm550_diagnosticFuelLimitInterpolator(void);  // @ 0x0001c03c
void cm550_FUN_0001c0d4(void);  // @ 0x0001c0d4
void fuelTimingOilPressureModeController(void);  // @ 0x0001c152
void cm550_FUN_0001c308(void);  // @ 0x0001c308
undefined4 mc68k_flashEraseWithWatchdog(void);  // @ 0x0001c31a
void cm550_FUN_0001c484(undefined4 param_1,undefined4 param_2);  // @ 0x0001c484
undefined4 mc68k_flashProgramWordWithWatchdog(void);  // @ 0x0001c4ba
void cm550_flashProgramFromRam(int param_1,undefined4 param_2,uint param_3);  // @ 0x0001c5e8
void cm550_diagnosticStatusDefaultSetter(void);  // @ 0x0001c630
void cm550_diagnostic_parameter_handler(void);  // @ 0x0001c640
uint cm550_fuelDemandTableBlendCalculator(void);  // @ 0x0001c65e
void cm550_FUN_0001c7a8(void);  // @ 0x0001c7a8
void cm550_FUN_0001c824(void);  // @ 0x0001c824
ushort cm550_FUN_0001c8a0(void);  // @ 0x0001c8a0
void fuelDemandProportionalCalculationSlowCycle40Coordinator(void);  // @ 0x0001c9d2
ushort cm550_fuelDemandLimitSelector11(void);  // @ 0x0001ca54
ushort vp44_canPinVp44StatusController(void);  // @ 0x0001ca5c
uint vp44_FUN_0001cad6(void);  // @ 0x0001cad6
void vp44_FUN_0001cb3c(void);  // @ 0x0001cb3c
void cm550_FUN_0001cb48(void);  // @ 0x0001cb48
short cm550_calculateBlendedTableValue(undefined4 param_1);  // @ 0x0001cb76
void cm550_FUN_0001cc72(void);  // @ 0x0001cc72
void cm550_FUN_0001cdf8(void);  // @ 0x0001cdf8
void cm550_FUN_0001ce58(void);  // @ 0x0001ce58
void cm550_initDiagnosticProtocol(void);  // @ 0x0001ce7c
void cm550_FUN_0001d252(void);  // @ 0x0001d252
void cm550_update_engine_protection_thresholds(void);  // @ 0x0001d2e4
uint selectSensorRawChannels(void);  // @ 0x0001d392
void cm550_FUN_0001d5a0(void);  // @ 0x0001d5a0
void cm550_FUN_0001d94e(void);  // @ 0x0001d94e
uint vp44SensorStatusMonitor(void);  // @ 0x0001d9b4
void vp44_FUN_0001db8a(void);  // @ 0x0001db8a
void vp44_fuelArbitratorVariablesReset(void);  // @ 0x0001db9a
void cm550_FUN_0001dbd8(void);  // @ 0x0001dbd8
void mc68k_main(void);  // @ 0x0001dbee
void vp44ControlStructureInit(void);  // @ 0x0001dcfc
void cm550_diagnosticBufferPointerInit(void);  // @ 0x0001dd2c
void cm550_FUN_0001ddb4(void);  // @ 0x0001ddb4
undefined4 cm550_FUN_0001de58(void);  // @ 0x0001de58
void cm550_subtractAndClampValue(short *param_1);  // @ 0x0001e02a
void cm550_FUN_0001e04c(void);  // @ 0x0001e04c
void cm550_serialNodeAddressChecker(undefined4 param_1);  // @ 0x0001e056
void cm550_serialNodeAddressForwarder(undefined4 param_1);  // @ 0x0001e086
undefined8 mc68k_FUN_0001e0fa(void);  // @ 0x0001e0fa
void cm550_canMessageInterruptHandlerSetup(void);  // @ 0x0001e1a0
void cm550_emptyStubWrapper1(void);  // @ 0x0001e1ac
void cm550_modeBasedDataDispatcherWrapper(void);  // @ 0x0001e1be
undefined8 mc68k_serialPort2IsrHandler(void);  // @ 0x0001e1d0
void cm550_serialCommunicationIsrRegister(void);  // @ 0x0001e25a
void mc68k_tpuTimerChannelEnable(void);  // @ 0x0001e266
undefined8 mc68k_epsPositionSensorIsrHandler(void);  // @ 0x0001e288
void cm550_tpuChannelIsrRegister(void);  // @ 0x0001e522
uint serialTransmitHandler(void);  // @ 0x0001e52e
void mc68k_FUN_0001e5f0(undefined4 param_1);  // @ 0x0001e5f0
undefined8 cm550_interruptCounter1Increment(void);  // @ 0x0001e734
undefined8 cm550_interruptCounter2Increment(void);  // @ 0x0001e76a
void cm550_initVectorTable(void);  // @ 0x0001e77a
uint cm550_insiteMultiFrameResponseBuilder(undefined4 param_1);  // @ 0x0001e79a
void cm550_insiteMultiFrameContinuation(void);  // @ 0x0001e89e
void buildPgn65228Dm3ClearInitMessage(void);  // @ 0x0001e956
void cm550_responseBufferSpaceCheck(void);  // @ 0x0001eb88
void cm550_responseBufferFinalize(void);  // @ 0x0001ec08
void cm550_diagnosticMemoryWriteHandler(undefined4 param_1);  // @ 0x0001ec3c
void cm550_diagnosticMemoryReadHandler(undefined4 param_1);  // @ 0x0001edae
void cm550_diagnosticMessage45Builder(void);  // @ 0x0001f0de
void cm550_diagnosticMessage46Builder(void);  // @ 0x0001f2d0
uint cm550_FUN_0001f4e8(void);  // @ 0x0001f4e8
void cm550_fuelDemandScaleFactorCalculator(void);  // @ 0x0001f84e
uint cm550_engineFluidLevelDataBuilder(void);  // @ 0x0001f8bc
void cm550_extendedDiagnosticService51(void);  // @ 0x0001fbb0
void cm550_diagnosticMessage53Builder(void);  // @ 0x0001fbf4
void cm550_diagnosticMessage54Builder(void);  // @ 0x0001fc9c
uint cm550_j1939TimeoutDataClearHandler(void);  // @ 0x0001fd6c
void cm550_crankStateVariablesReset(void);  // @ 0x0001fd8e
uint cm550_j1939MessageTypeCounter(undefined4 param_1);  // @ 0x0001fdc0
void cm550_canMessageFilterInit(void);  // @ 0x0001fe40
ushort cm550_engineRunTimeHistogramAccumulator(void);  // @ 0x0001ff38
void cm550_emptyPlaceholderInit(void);  // @ 0x0001ffd0
uint cm550_j1939TorqueControlModeParser(int param_1,undefined4 param_2);  // @ 0x0001ffd6
void cm550_j1939TorqueControlModeClear(undefined4 param_1);  // @ 0x000200a4
void cm550_j1939TorqueControlModeSet(undefined4 param_1);  // @ 0x000200b4
void cm550_systemFunction6xParameterized(void);  // @ 0x000200c6
void cm550_FUN_000201d6(undefined4 param_1);  // @ 0x000201d6
void cm550_FUN_00020210(undefined4 param_1);  // @ 0x00020210
void cm550_FUN_0002024a(undefined4 param_1);  // @ 0x0002024a
uint cm550_FUN_00020284(void);  // @ 0x00020284
uint cm550_FUN_000202a0(void);  // @ 0x000202a0
uint cm550_FUN_000202bc(void);  // @ 0x000202bc
void setBitInArray(undefined4 param_1);  // @ 0x000202d8
void cm550_FUN_00020310(undefined4 param_1);  // @ 0x00020310
void cm550_FUN_00020348(undefined4 param_1);  // @ 0x00020348
uint cm550_FUN_00020380(void);  // @ 0x00020380
uint cm550_FUN_0002041c(void);  // @ 0x0002041c
uint cm550_outputControlState1Handler(void);  // @ 0x000204b0
void cm550_FUN_000205c4(void);  // @ 0x000205c4
uint cm550_FUN_000206a8(uint param_1,uint param_2);  // @ 0x000206a8
uint cm550_FUN_00020784(void);  // @ 0x00020784
uint cm550_FUN_00020890(undefined4 param_1);  // @ 0x00020890
uint cm550_FUN_00020c98(void);  // @ 0x00020c98
uint cm550_FUN_00020e14(void);  // @ 0x00020e14
uint cm550_FUN_00020fac(void);  // @ 0x00020fac
void cm550_FUN_00021070(void);  // @ 0x00021070
void cm550_FUN_00021146(void);  // @ 0x00021146
void cm550_FUN_000211f4(void);  // @ 0x000211f4
uint mc68k_FUN_000212b2(void);  // @ 0x000212b2
ushort cm550_FUN_0002142c(void);  // @ 0x0002142c
uint cm550_memoryOperationDispatcher(int param_1,short param_2,uint param_3);  // @ 0x0002148a
void cm550_j1939DataCopyWrapper2Byte(int param_1);  // @ 0x0002167e
void cm550_FUN_000216c6(int param_1);  // @ 0x000216c6
void cm550_j1939DataCopyWrapperExtended(int param_1);  // @ 0x00021714
void cm550_FUN_00021778(int param_1);  // @ 0x00021778
void cm550_memoryOperationFromMessageExtended(int param_1);  // @ 0x000217de
void cm550_FUN_00021826(int param_1);  // @ 0x00021826
void cm550_FUN_00021872(void);  // @ 0x00021872
undefined4 byteSwap32(undefined4 *param_1);  // @ 0x000218ca
undefined2 byteSwap16(undefined2 *param_1);  // @ 0x000218fe
byte cm550_FUN_00021920(void);  // @ 0x00021920
uint cm550_addressLookupFunction(undefined4 param_1);  // @ 0x00021964
undefined4 cm550_diagnosticServiceSecurityValidator(int param_1);  // @ 0x00021982
void cm550_FUN_00021a8c(int param_1);  // @ 0x00021a8c
void cm550_FUN_00021b88(int param_1);  // @ 0x00021b88
void cm550_FUN_00021c74(int param_1);  // @ 0x00021c74
void cm550_FUN_00021d44(int param_1);  // @ 0x00021d44
void cm550_FUN_00021edc(void);  // @ 0x00021edc
void cm550_FUN_00021ef6(void);  // @ 0x00021ef6
void cm550_diagnosticGroupPositionBufferStore(undefined4 param_1);  // @ 0x00021f4e
void cm550_diagnosticGroupSnapshotCapture(undefined4 param_1);  // @ 0x00021fac
uint cm550_memoryRegisterController(void);  // @ 0x00022070
undefined4 cm550_canDiagnosticResponseSender(undefined1 *param_1);  // @ 0x000222b4
void cm550_systemFunction1xCaller(void);  // @ 0x00022370
undefined4 cm550_diagMemoryReadResponseBuilder(byte *param_1,uint param_2,uint param_3);  // @ 0x0002238e
void cm550_FUN_00022530(int param_1);  // @ 0x00022530
void cm550_FUN_0002257c(int param_1);  // @ 0x0002257c
void cm550_FUN_000225e0(int param_1);  // @ 0x000225e0
void cm550_FUN_00022646(int param_1);  // @ 0x00022646
void cm550_FUN_0002268e(int param_1);  // @ 0x0002268e
void cm550_FUN_000226da(void);  // @ 0x000226da
void sendJ1939MultiFrame(uint *param_1);  // @ 0x00022726
void cm550_diagnosticParamRequestHandler(int param_1);  // @ 0x00022956
void cm550_messageErrorHandler(undefined4 param_1);  // @ 0x000229ea
void vp44CanFrameBuilder(undefined4 param_1);  // @ 0x00022a58
undefined1 vp44MessageTransmitter(undefined4 param_1,undefined2 param_2);  // @ 0x00022ad8
void vp44FuelTempHandler(undefined4 *param_1);  // @ 0x00022b50
void vp44MultiFrameResponseHandler(int param_1);  // @ 0x00022c26
void cm550_diagnosticStatusRequestHandler(int param_1);  // @ 0x00022d8e
void vp44_diagnosticErrorHandler(int param_1);  // @ 0x00022de2
void vp44_diagnosticServiceByteHandler(void);  // @ 0x00022de6
void vp44CanMessageDispatcher(int param_1);  // @ 0x00022e5e
void cm550_diagnosticParamRequestHandlerWrapper(void);  // @ 0x00022e96
void vp44FuelTempHandlerWrapper(void);  // @ 0x00022ea4
void cm550_diagnosticStatusRequestHandlerWrapper(void);  // @ 0x00022eb2
void cm550_diagnosticErrorHandlerWrapper(void);  // @ 0x00022ec0
void cm550_unknownMessageHandler(uint param_1);  // @ 0x00022ece
void cm550_diagnosticMessageProcessor(void);  // @ 0x00022fae
void vp44ResponseTimeoutHandler(void);  // @ 0x000230d6
void vp44_messageQueueDispatcher(void);  // @ 0x000230ee
undefined4 cm550_multiPacketBufferAllocator(undefined4 param_1);  // @ 0x00023130
void vp44DiagnosticBufferPointersInit(void);  // @ 0x00023186
void cm550_fuelArbitratorResetHandler(void);  // @ 0x000231da
void cm550_FUN_00023216(void);  // @ 0x00023216
void cm550_statisticsTrackingFlagsReset(void);  // @ 0x0002322a
uint cm550_fuelDemandLimitOrchestrator(void);  // @ 0x00023244
uint cm550_diagnosticMessageValidator(undefined4 param_1,undefined4 param_2);  // @ 0x00023820
uint cm550_ioControlTimeoutTableLookup(undefined4 param_1);  // @ 0x00023870
void cm550_ioControlEntryAdd(undefined4 param_1,undefined4 param_2);  // @ 0x000238ac
void cm550_ioControlTimeoutEntryAdd(undefined4 param_1);  // @ 0x000238ec
void cm550_phase3_countdown_timer_manager(void);  // @ 0x00023920
void cm550_diagnosticStateInitializer(undefined4 param_1);  // @ 0x000239d2
void cm550_ioControlEntryRemove(undefined4 param_1);  // @ 0x00023a3c
ushort processProtectionFlagConditions(void);  // @ 0x00023a90
void diagnosticMainStateProcessor(void);  // @ 0x00023be8
void cm550_FUN_00024804(void);  // @ 0x00024804
void cm550_iahDisableWaitToStartLamp(void);  // @ 0x00024812
void cm550_initIoControlRegister(void);  // @ 0x0002481e
void cm550_ioControlMaskInit(void);  // @ 0x0002482e
void cm550_ioControlMaskStateMachine(void);  // @ 0x00024858
uint cm550_ioControlToggleCycle(void);  // @ 0x000249b6
undefined1 vp44_ioControlLampStateMachine(void);  // @ 0x000249ee
uint cm550_ioControlDigitDisplaySequencer(undefined4 param_1);  // @ 0x00024b4e
byte cm550_FUN_00024c5a(undefined4 param_1);  // @ 0x00024c5a
byte cm550_FUN_00024cd2(undefined4 param_1);  // @ 0x00024cd2
int cm550_faultCodeDisplayController(void);  // @ 0x00024d40
void cm550_activeFaultLampStateMachine(void);  // @ 0x00024f30
void cm550_faultLampBlinkPatternGenerator(void);  // @ 0x00025316
void cm550_FUN_000253b0(void);  // @ 0x000253b0
void cm550_periodicLampFlashController(void);  // @ 0x00025448
void cm550_FUN_000254b6(void);  // @ 0x000254b6
void cm550_clearSystemErrorStatus(void);  // @ 0x00025594
void cm550_FUN_0002571e(void);  // @ 0x0002571e
void cm550_FUN_00025806(undefined4 param_1);  // @ 0x00025806
void cm550_FUN_000258b0(void);  // @ 0x000258b0
void cm550_fuelDemandTablePointerInit(void);  // @ 0x000258d6
void cm550_epsTimingCalculationSlowCycle40Coordinator(void);  // @ 0x000258e8
void cm550_initLookupTablePointers1(void);  // @ 0x00025926
void cm550_governorFuelPidController(void);  // @ 0x0002595a
void cm550_fuel_delivery_controller(void);  // @ 0x00025a30
void vp44_FUN_00025a34(void);  // @ 0x00025a34
void vp44_fuel_timing_calculation_with_fault_checking(void);  // @ 0x00025b1c
void vp44_fuelRpmDeviationCalculator(void);  // @ 0x00025ff2
void cm550_FUN_00026078(void);  // @ 0x00026078
uint cm550_epsAccelerationMonitor(void);  // @ 0x0002609c
void cm550_epsRpmTrackingInit(void);  // @ 0x00026252
void cm550_epsControlModeReset(void);  // @ 0x0002626a
uint cm550_epsOverrideChecker(undefined4 param_1);  // @ 0x00026272
void cm550_epsControlModeSelector(void);  // @ 0x0002629e
void cm550_epsInitializationWrapper(void);  // @ 0x000262fa
void cm550_epsControlModeInit(void);  // @ 0x00026308
void cm550_epsDiagnosticModeHandler(void);  // @ 0x00026340
void cm550_initOilPressureMonitoring(void);  // @ 0x00026462
void cm550_engineModeTimingAdjuster(void);  // @ 0x00026474
void vp44_rpm_derate_monitor(void);  // @ 0x00026484
void cm550_fuelDemandLimitSource2Selector(void);  // @ 0x0002658c
void vp44_initVP44StatusFlags(void);  // @ 0x0002659a
int cm550_epsRpmTargetModeChecker(void);  // @ 0x000265e6
void cm550_FUN_00026616(void);  // @ 0x00026616
void cm550_timingOffsetCalculatorWrapper(void);  // @ 0x000266d2
uint mc68k_qadcDataCollectionStateMachine(void);  // @ 0x000266da
undefined8 mc68k_FUN_00026834(void);  // @ 0x00026834
void cm550_FUN_00026852(void);  // @ 0x00026852
void mc68k_FUN_00026854(void);  // @ 0x00026854
void cm550_FUN_000269f2(void);  // @ 0x000269f2
void cm550_FUN_00026a2e(void);  // @ 0x00026a2e
void cm550_memcpy(undefined1 *param_1,undefined1 *param_2,undefined4 param_3);  // @ 0x00026a64
void cm550_fuelDemandTablePointersInit(void);  // @ 0x00026a7e
ushort cm550_rpmLoadParameterLookup(void);  // @ 0x00026ab8
ushort cm550_FUN_00026af0(void);  // @ 0x00026af0
ushort vp44OperatingConditionChecker(void);  // @ 0x00026b00
void cm550_FUN_00026b3a(void);  // @ 0x00026b3a
void cm550_FUN_00026b82(void);  // @ 0x00026b82
void hpcr_injectorPulseWidthCalc(void);  // @ 0x00026b88
void mc68k_pwmOutputInit(void);  // @ 0x00026c7e
void calculateSpeedRatioComponent(void);  // @ 0x00026cc8
void cm550_FUN_00026e2c(void);  // @ 0x00026e2c
void cm550_FUN_00026e86(void);  // @ 0x00026e86
void cm550_FUN_00026e8e(void);  // @ 0x00026e8e
void cm550_insiteActiveFaultListBuilder(void);  // @ 0x00026eec
void cm550_insiteFaultDetailBuilder(void);  // @ 0x00026fea
void cm550_insiteVersionInfoBuilder(void);  // @ 0x0002758e
void cm550_insiteCapacityResponseBuilder(void);  // @ 0x00027706
void cm550_FUN_000277e6(void);  // @ 0x000277e6
void vp44_hourMeterEventLogger(void);  // @ 0x00027998
void vp44StatusInitAndWait(void);  // @ 0x00027af0
void vp44_FUN_00027c20(void);  // @ 0x00027c20
void vp44_FUN_00027cd0(undefined4 param_1);  // @ 0x00027cd0
void vp44_FUN_00027f9c(void);  // @ 0x00027f9c
void vp44_FUN_000284e8(void);  // @ 0x000284e8
void vp44_mainSystemInitialization(void);  // @ 0x00028508
void vp44_slowCycle4Coordinator(void);  // @ 0x0002874a
void vp44_engineDiagnosticSystemCoordinator(void);  // @ 0x00028792
void cm550_fuelDemandUpdateOrchestrator(void);  // @ 0x00028816
void cm550_advancedEngineProtectionCoordinator(void);  // @ 0x00028828
void cm550_shutdownMinimumSelectorOrchestrator(void);  // @ 0x00028936
void cm550_FUN_00028978(void);  // @ 0x00028978
void cm550_phase4InitSequence(void);  // @ 0x00028990
void mc68k_dualCanControllerInit(void);  // @ 0x00028a04
void initDiagnosticBufferPointers(void);  // @ 0x00028b80
void mc68k_mainCanTransmissionLoop(void);  // @ 0x00028e32
undefined2 mc68k_FUN_00029130(void);  // @ 0x00029130
short mc68k_FUN_0002c834(int param_1);  // @ 0x0002c834
void mc68k_FUN_0002c986(int param_1,undefined4 param_2);  // @ 0x0002c986
void cm550_FUN_0002ca2a(void);  // @ 0x0002ca2a
void cm550_FUN_0002ca64(undefined4 param_1);  // @ 0x0002ca64
byte mc68k_FUN_0002ca7e(void);  // @ 0x0002ca7e
void mc68k_FUN_0002cb4e(void);  // @ 0x0002cb4e
undefined4 mc68k_FUN_0002cb9c(void);  // @ 0x0002cb9c
void mc68k_FUN_0002cc88(void);  // @ 0x0002cc88
void mc68k_FUN_0002ce14(void);  // @ 0x0002ce14
void cm550_FUN_0002ce64(void);  // @ 0x0002ce64
void cm550_FUN_0002cf52(undefined1 *param_1,undefined4 param_2);  // @ 0x0002cf52
uint cm550_FUN_0002cf7e(undefined4 param_1);  // @ 0x0002cf7e
void cm550_systemControl64(void);  // @ 0x0002d09e
void cm550_systemControl74(void);  // @ 0x0002d1c2
void cm550_systemControl75(void);  // @ 0x0002d1e0
void cm550_memoryPatchBufferInit(void);  // @ 0x0002d1fe
uint cm550_memoryPatchingSystem(void);  // @ 0x0002d216
void initProtectionParamCalculation(void);  // @ 0x0002d3c6
void cm550_FUN_0002d9a8(void);  // @ 0x0002d9a8
void cm550_fuelDemandProportionalCalculator(void);  // @ 0x0002d9d2
void cm550_FUN_0002db2a(void);  // @ 0x0002db2a
void cm550_FUN_0002dbde(void);  // @ 0x0002dbde
void cm550_rpmSnapshotCapture(void);  // @ 0x0002dc8c
void cm550_FUN_0002dc9e(void);  // @ 0x0002dc9e
uint cm550_oil_pressure_shutdown_controller(void);  // @ 0x0002dcb0
void cm550_FUN_0002ddbc(void);  // @ 0x0002ddbc
void mc68k_hardwareTimerFlagsInit(void);  // @ 0x0002ddce
void mc68k_initDiagnosticModeSystem(void);  // @ 0x0002ddd6
uint oilPressureRpmFaultMonitor(void);  // @ 0x0002dde8
uint mc68k_waterInFuelDiagnosticHandler(void);  // @ 0x0002e2f4
uint mc68k_pwmFuelDemandOutputCalculator(void);  // @ 0x0002e5c0
void initQadcModule(void);  // @ 0x0002e95e
void mc68k_clearWorkingMemory(void);  // @ 0x0002e9ac
void cm550_canMemoryPointerTableInit(void);  // @ 0x0002e9f8
void cm550_canMessageMemorySyncController(void);  // @ 0x0002eadc
void cm550_FUN_0002ec50(void);  // @ 0x0002ec50
void cm550_FUN_0002ed62(void);  // @ 0x0002ed62
char cm550_insiteParameterParser(void);  // @ 0x0002ed6a
undefined2 cm550_parameterLookupForInsite(void);  // @ 0x0002edb2
void cm550_diagnosticServiceDispatcher(int param_1);  // @ 0x0002eea2
void cm550_systemControlFunction1(void);  // @ 0x0002ef08
void cm550_diagnosticResponseHandler2(undefined4 param_1);  // @ 0x0002ef1c
void cm550_canTransmissionTrigger(void);  // @ 0x0002ef36
void cm550_FUN_0002ef4a(int param_1);  // @ 0x0002ef4a
void cm550_systemControlFunction2(void);  // @ 0x0002efbc
ushort cm550_diagnosticServiceDispatcherByPgn(int param_1);  // @ 0x0002efd0
void cm550_systemControlFunction3(void);  // @ 0x0002f114
void torqueControlModeHandler(int param_1);  // @ 0x0002f128
void cm550_FUN_0002f4be(int param_1);  // @ 0x0002f4be
void cm550_diagnosticDataDump(void);  // @ 0x0002f538
uint cm550_FUN_0002f606(undefined4 param_1);  // @ 0x0002f606
void j1939FormatMultiFrameResponse(void);  // @ 0x0002f632
void cm550_retarderControlModeHandler(int param_1);  // @ 0x0002f7e6
void cm550_FUN_0002faa4(void);  // @ 0x0002faa4
void cm550_initOilPressureProtectionPointers(void);  // @ 0x0002faba
void cm550_torqueControlAddressDispatcher(int param_1);  // @ 0x0002fb70
void cm550_FUN_0002fbb2(void);  // @ 0x0002fbb2
void cm550_FUN_0002fbd8(int param_1,int param_2);  // @ 0x0002fbd8
undefined1 sensorRangeValidation(undefined4 param_1);  // @ 0x0002fcdc
void cm550_FUN_0002fd90(undefined4 param_1);  // @ 0x0002fd90
void cm550_diagnosticTableEntryClear(undefined4 param_1);  // @ 0x0002fddc
void cm550_diagnosticTableSnapshotCapture(undefined4 param_1);  // @ 0x0002fe38
undefined8 mc68k_tpuChannelStateMachine(void);  // @ 0x000300d4
void mc68k_engineSpeedIsrRegister(void);  // @ 0x00030274
void mc68k_engineRpmHardwareTimerSetup(void);  // @ 0x00030290
void mc68k_can1ControllerInit(void);  // @ 0x00030342
void cm550_emptyStubFunction9(void);  // @ 0x000303c8
void cm550_emptyInitPlaceholder(void);  // @ 0x000303d2
undefined4 cm550_accumulatorWithOverflowCarry(uint *param_1,uint *param_2);  // @ 0x000303d4
void cm550_runTimeCountersUpdate(void);  // @ 0x00030414
void cm550_runTimeCountersUpdateAlt(void);  // @ 0x00030454
byte cm550_FUN_00030498(void);  // @ 0x00030498
void cm550_rpmHistogramAndAveragingStatistics(void);  // @ 0x000304f4
uint cm550_fuelLimitRestoreFromCapture(void);  // @ 0x0003061a
ushort cm550_FUN_000306ca(void);  // @ 0x000306ca
ushort cm550_FUN_00030a5e(void);  // @ 0x00030a5e
ushort cm550_protectionFlagAccumulator(void);  // @ 0x00030a64
void cm550_FUN_00030ade(void);  // @ 0x00030ade
undefined8 cm550_protectionLimitValueInit(void);  // @ 0x00030b04
void cm550_FUN_00030b0e(void);  // @ 0x00030b0e
void cm550_fuelDemandLimitSelector4(void);  // @ 0x00030b10
void cm550_FUN_00030b34(void);  // @ 0x00030b34
ushort vp44InjectionSystemStateController(void);  // @ 0x00030b62
void cm550_shutdownMinimumSelector28(void);  // @ 0x00030bf6
void cm550_shutdownMinimumSelector20(void);  // @ 0x00030c14
void cm550_FUN_00030c3c(void);  // @ 0x00030c3c
void cm550_masterSubsystemInit(void);  // @ 0x00030c78
void mc68k_initInternalRamAndCAN1(void);  // @ 0x00031428
ushort cm550_FUN_00031496(void);  // @ 0x00031496
void cm550_FUN_000315be(void);  // @ 0x000315be
ushort cm550_FUN_00031a68(void);  // @ 0x00031a68
uint cm550_diagnosticSessionValidator(undefined4 param_1);  // @ 0x00031ace
void cm550_diagnosticCanResponseSender(int param_1,undefined4 param_2);  // @ 0x00031b22
void cm550_canBufferSetup1(void);  // @ 0x00031b96
void cm550_FUN_00031bce(void);  // @ 0x00031bce
void cm550_j1939MessageSetup_PGN_65265(void);  // @ 0x00031c1a
void j1939HandlePgn65265CruiseVehicleSpeed(void);  // @ 0x00031c84
void cm550_FUN_00031ed2(void);  // @ 0x00031ed2
void j1939HandlePgn65261CruiseControlSetup(void);  // @ 0x00031f30
void initPgn65261CruiseControlSetupStruct(void);  // @ 0x00031fee
void cm550_FUN_00032052(void);  // @ 0x00032052
void cm550_engineSerialNumberPGN_65259_Builder(void);  // @ 0x000320f6
byte * cm550_diagnosticMultiPacketResponseBuilder(byte *param_1,undefined4 param_2);  // @ 0x0003216a
void cm550_diagnosticDM11PGN_65234_Builder(void);  // @ 0x00032244
byte j1939HandlePgn65226Dm1ActiveDtc(void);  // @ 0x000322ae
void cm550_engineCoolantPGN_65226_Builder(void);  // @ 0x000323be
byte cm550_previousDtcListBuilder(void);  // @ 0x0003241c
void cm550_diagnosticDM2PGN_65227_Builder(void);  // @ 0x0003252c
byte evaluateTemperatureDiagnosticState(void);  // @ 0x0003258a
void cm550_diagnosticDM4PGN_65229_Builder(void);  // @ 0x000329d2
void vp44_diagnosticDM5DataBuilder(void);  // @ 0x00032a42
void cm550_diagnosticDM5PGN_65230_Builder(void);  // @ 0x00032ae2
void vp44_diagnosticByteResponseSender(undefined4 param_1);  // @ 0x00032b38
void vp44_diagnosticDM8PGN_65232_Builder(void);  // @ 0x00032b64
void vp44_FUN_00032c22(void);  // @ 0x00032c22
void j1939GetEngineStateCode(void);  // @ 0x00032c76
void vp44Message300FaultFlagProcessor(void);  // @ 0x00032c7a
void vp44Command0x100Builder(void);  // @ 0x00032e08
void j1939HandlePgn61443Eec2(void);  // @ 0x00032e4c
void vp44_cumminsProprietaryDM_983_Builder(void);  // @ 0x00033064
void vp44_configParamCanBuilder(void);  // @ 0x000330c4
void vp44_secondaryParamPGN_65247_Builder(void);  // @ 0x00033120
void vp44_FUN_00033164(void);  // @ 0x00033164
void vp44_engineFluidLevelPGN_65263_Builder(void);  // @ 0x000331ae
void faultTimerHandler(undefined4 *param_1);  // @ 0x0003320e
uint cm550_FUN_000333d6(uint param_1);  // @ 0x000333d6
uint cm550_FUN_00033460(uint param_1);  // @ 0x00033460
void cm550_FUN_000334ec(void);  // @ 0x000334ec
byte cm550_FUN_0003366a(void);  // @ 0x0003366a
void initFaultTimerMessage(void);  // @ 0x00033692
void cm550_FUN_00033716(void);  // @ 0x00033716
void cm550_FUN_00033754(void);  // @ 0x00033754
void cm550_FUN_000337c4(void);  // @ 0x000337c4
void cm550_engineTemperaturePGN_65262_Builder(void);  // @ 0x00033880
void cm550_dutyCycleMonitorAltIsrHandler(void);  // @ 0x000338ea
void cm550_cumminsProprietaryTSC_PGN_15728640_Builder(void);  // @ 0x000339b0
void cm550_FUN_00033a1e(void);  // @ 0x00033a1e
void cm550_FUN_00033a62(void);  // @ 0x00033a62
void cm550_retarderConfigPGN_65249_Builder(void);  // @ 0x00033aea
void cm550_fuelEconomyDataBuilder(void);  // @ 0x00033b40
void cm550_fuelEconomyPGN_65266_Builder(void);  // @ 0x00033c28
void cm550_ioControlDataBuilder(void);  // @ 0x00033c6c
void vp44_ioControlPGN_65244_Builder(void);  // @ 0x00033ce2
void vp44_engineHoursPGN_65252_Builder(void);  // @ 0x00033dfa
void cm550_FUN_00033e58(void);  // @ 0x00033e58
void cm550_intakeManifoldPGN_65526_Builder(void);  // @ 0x00033eee
void cm550_FUN_00033f5a(void);  // @ 0x00033f5a
void cm550_cruiseControlPGN_65264_Builder(void);  // @ 0x0003401a
byte vp44CanMessage100ResponseBuilder(void);  // @ 0x0003407a
void cm550_FUN_000341e6(void);  // @ 0x000341e6
void cm550_FUN_00034232(void);  // @ 0x00034232
void cm550_vehicleDistancePGN_65248_Builder(void);  // @ 0x0003429a
void cm550_retarderDataBuilder(void);  // @ 0x000342f0
void cm550_electronicBrakePGN_65527_Builder(void);  // @ 0x00034334
void cm550_FUN_00034394(void);  // @ 0x00034394
void vp44_vehicleHoursPGN_65255_Builder(void);  // @ 0x000343d2
void cm550_FUN_00034440(void);  // @ 0x00034440
void vp44_FUN_000344ce(void);  // @ 0x000344ce
void cm550_FUN_00034512(void);  // @ 0x00034512
void cm550_FUN_0003452a(void);  // @ 0x0003452a
void cm550_initLoopCounter(void);  // @ 0x00034534
void cm550_setDiagnosticSourceFromFuelArbitrator(void);  // @ 0x00034540
void cm550_setDiagnosticSourceFromEngineFlags(void);  // @ 0x00034564
void cm550_engine_protection_coordinator(void);  // @ 0x0003458c
void cm550_initMultiSystemParameters(void);  // @ 0x000345c8
undefined4 cm550_addressRangeValidator(uint param_1,uint param_2);  // @ 0x0003460e
void mc68k_pwmTimerMode0Init(void);  // @ 0x00034674
void mc68k_timerCaptureHardwareInit(void);  // @ 0x00034696
void mc68k_pwmTimerMode0Reset(void);  // @ 0x0003478c
void mc68k_pwmTimerMode1ChannelSetup(void);  // @ 0x0003480e
void mc68k_pwmTimerMode1Update(void);  // @ 0x0003494a
void mc68k_pwmTimerModeDispatcher(void);  // @ 0x00034a82
undefined8 mc68k_pwmTimerCycleAdvance(void);  // @ 0x00034b20
void mc68k_watchdogServiceLoop(undefined4 param_1);  // @ 0x00034bba
void mc68k_FUN_00034bf8(undefined4 param_1);  // @ 0x00034bf8
ushort vp44FaultRegisterBit2Monitor(void);  // @ 0x00034c36
void vp44_liftPumpFuelDeliveryController(void);  // @ 0x00034cc4
void vp44_FUN_00034d52(void);  // @ 0x00034d52
void cm550_FUN_00034dba(void);  // @ 0x00034dba
short lookupTableInterpolation(short *param_1);  // @ 0x00034de0
undefined4 cm550_scaleByRatio(uint param_1,uint param_2,uint param_3);  // @ 0x00035064
undefined4 cm550_scaleByRatioSigned(int param_1,int param_2,int param_3);  // @ 0x00035076
undefined8 cm550_tableLookup2D(short *param_1);  // @ 0x00035088
