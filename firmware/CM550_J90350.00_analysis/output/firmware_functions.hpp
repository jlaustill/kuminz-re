#pragma once
#include "firmware_types.hpp"

// Function Forward Declarations (from decompiled output)

short cm550_huffmanTreeBuilder(huffman_tree_node_t *tree_buffer);  // @ 0x00003640
void cm550_huffmanDecompress(huffman_tree_node_t *tree_buffer,word start_node);  // @ 0x00003792
void cm550_huffmanDecompressMain(void);  // @ 0x00003836
void cm550_busyWaitDelayLoop(word pass_count);  // @ 0x00003870
byte mc68k_portPinTestSequence2(void);  // @ 0x0000388a
void mc68k_waitForChipSelect2InputBit0High(void);  // @ 0x0000395a
undefined4 mc68k_checkSerialEepromSignature(void);  // @ 0x000039a8
void mc68k_hardwareInitAndStartup(void);  // @ 0x00003a94
void mc68k_restartBootRomWithoutReset(void);  // @ 0x00003abe
void cm550_ramClearWithWatchdog(void);  // @ 0x00003c20
uint cm550_FUN_0000ac3c(void);  // @ 0x0000ac3c
void cm550_FUN_0000af70(void);  // @ 0x0000af70
void cm550_writeHourMeterConversionData(void);  // @ 0x0000b130
void calculateFilteredEngineAcceleration(void);  // @ 0x0000b210
ushort cm550_rpm_system_state_controller(void);  // @ 0x0000b2aa
void cm550_shutdownMinimumSelector21(void);  // @ 0x0000b3b2
ushort cm550_FUN_0000b3d0(void);  // @ 0x0000b3d0
void cm550_fuelDemandLimitMinimumUpdater(void);  // @ 0x0000b4ce
ushort cm550_engineStateFuelLimitInterpolator(void);  // @ 0x0000b4f2
void initializeEngineAccelerationFilters(void);  // @ 0x0000b5e4
void cm550_rpmParameterPointerSetup(void);  // @ 0x0000b614
void cm550_dmaDescriptorSetup2(void);  // @ 0x0000b63e
void cm550_initFuelSystemOutputDriver(void);  // @ 0x0000b666
byte getJ1939DiagnosticResponseEchoLength(word diagnostic_service);  // @ 0x0000b688
void cm550_diagnosticMessageQueueWrite(word response_type);  // @ 0x0000b6e8
void mc68k_processAnalogSensorChannels(void);  // @ 0x0000b7bc
void cm550_initializeAnalogSensorChannels(void);  // @ 0x0000bcf0
uint cm550_fuelTimingTransitionStateMachine(void);  // @ 0x0000c180
void cm550_fuelTimingModeInit(void);  // @ 0x0000c246
void cm550_diagnosticDataBufferSetup(void);  // @ 0x0000c24c
void cm550_shutdownMinimumSelector16(void);  // @ 0x0000c2a0
void cm550_diagnosticTimingIncrementController(void);  // @ 0x0000c2be
void cm550_FUN_0000c2ee(void);  // @ 0x0000c2ee
ushort calculateAlpha(void);  // @ 0x0000c326
word calculateAlphaFuelRateResult(void);  // @ 0x0000c404
uint calculateAlphaOnGovernorResult(void);  // @ 0x0000c496
int calculateAlphaLowSpeedGovernorResult(void);  // @ 0x0000c4b2
int calculateAlphaAirFuelControlResult(void);  // @ 0x0000c504
word calculateAlphaLowAmbientAirPressureResult(void);  // @ 0x0000c556
uint calculateAlphaBase(void);  // @ 0x0000c582
void cm550_phase2_slot_5_handler(void);  // @ 0x0000c658
ushort cm550_rpmHistogramAndProtectionStatisticsAccumulator(void);  // @ 0x0000c66a
void cm550_fuelParameterPointerSetup(void);  // @ 0x0000c714
void cm550_shutdownMinimumSelector15(void);  // @ 0x0000c742
void mc68k_configureCanCs5MessageObjects(void);  // @ 0x0000c760
void ignoreCanTransmitInterrupt(void);  // @ 0x0000c80c
void vp44_dispatchReceivedPumpMessage(word message_object);  // @ 0x0000c80e
void cm550_FUN_0000c87c(void);  // @ 0x0000c87c
void cm550_FUN_0000c87e(void);  // @ 0x0000c87e
void cm550_FUN_0000c880(void);  // @ 0x0000c880
void cm550_dzgTimingAndPressureControlStateMachine(void);  // @ 0x0000c8a0
void cm550_runAllSpeedGovernor(void);  // @ 0x0000c962
void cm550_diagnosticDataCopyHandler(void);  // @ 0x0000d0e2
void cm550_fuelDeliverySystemInit(void);  // @ 0x0000d0fc
void cm550_diagnosticStatus30Setter(void);  // @ 0x0000d18a
void cm550_diagnosticStatus2Initializer(word previous_user_fueling_state);  // @ 0x0000d1a4
void cm550_diagnosticState2Initializer(void);  // @ 0x0000d218
void cm550_dualTableLookupSum(void);  // @ 0x0000d23c
void cm550_interpolationTableSetup(void);  // @ 0x0000d280
void cm550_initAcControlSystem(void);  // @ 0x0000d286
void cm550_acceleratorThrottleFaultDetector(void);  // @ 0x0000d2be
void cm550_FUN_0000d3b2(void);  // @ 0x0000d3b2
void cm550_fuelArbitratorInit(void);  // @ 0x0000d3bc
void cm550_initDerateSystemPointers(void);  // @ 0x0000d3c6
void cm550_diagnosticMode10FuelController(void);  // @ 0x0000d3e6
uint cm550_FUN_0000d4ae(word previous_user_fueling_state);  // @ 0x0000d4ae
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
byte cm550_diagnosticCodeTableSearch(word fault_index);  // @ 0x0000ed34
void insiteCommandByteDispatcher(void);  // @ 0x0000ed64
undefined * cm550_FUN_0000f716(void);  // @ 0x0000f716
void cm550_paramSystemModeController(void);  // @ 0x0000f796
void cm550_param_lookup_1(void);  // @ 0x0000f8c6
void cm550_param_lookup_3(void);  // @ 0x0000f930
void cm550_FUN_0000f99a(void);  // @ 0x0000f99a
void cm550_FUN_0000f99c(void);  // @ 0x0000f99c
uint vp44State2TransitionHandler(void);  // @ 0x0000fa06
void vp44_FUN_0000fa68(void);  // @ 0x0000fa68
void cm550_calculateGovernorDroopSpeed(word breakpoint_fueling,byte torque_index);  // @ 0x0000faa6
void vp44_fuelLimitExceedanceStatisticsAccumulator(void);  // @ 0x0000fb26
void vp44_fuelSourceOilPressureConditionChecker(void);  // @ 0x0000fbe4
ushort cm550_FUN_0000ff48(void);  // @ 0x0000ff48
void cm550_initFuelArbitratorThreshold5(void);  // @ 0x0000ff56
void cm550_ioControlBasedFuelCalculator(void);  // @ 0x0000ff6c
void cm550_throttleTablePointerSetup(void);  // @ 0x000100da
uint cm550_bufferDecreasingPatternCheck(void);  // @ 0x0001011c
uint cm550_bufferThresholdValidator(void);  // @ 0x000101b8
word cm550_detectEngineSpeedSensorSyncPulse(word backup_sensor_flag);  // @ 0x0001025c
void cm550_canBusTimingInit(void);  // @ 0x00010394
void cm550_sendCanMessage(j1939_tx_msg_t *msg);  // @ 0x000104e8
void cm550_sendJ1939MultiFrameWrapper(void);  // @ 0x00010512
short cm550_arrayRangeSum(word *start_ptr,word *end_ptr);  // @ 0x00010520
void cm550_memoryPatchCountDecrement(void);  // @ 0x00010536
uint vp44_rpmDerateCalculationController(void);  // @ 0x00010568
ulonglong vp44_derateThresholdMonitorAndFaultController(void);  // @ 0x00010822
void cm550_FUN_00010e06(void);  // @ 0x00010e06
int cm550_lookupParameterIdAddress(word param_id,dword *resolved_address);  // @ 0x00010e16
uint cm550_loadParameterBlock1FromFlash(void);  // @ 0x00010e80
uint cm550_loadParameterBlock2FromFlash(void);  // @ 0x00010f32
int cm550_saveParameterBlock1ToFlash(void);  // @ 0x00010fe0
int cm550_saveParameterBlock2ToFlash(void);  // @ 0x0001125a
void cm550_loadParameterBlockAndUpdatePowerDownCounts(void);  // @ 0x000114d4
void copyCalibrationFromRomToRam(void);  // @ 0x000117ec
undefined1 cm550_requestClearInactiveFaults(void);  // @ 0x0001183e
byte exitDevelopmentMode(void);  // @ 0x0001188c
byte enterDevelopmentMode(void);  // @ 0x000118b2
byte forceExitDevelopmentMode(void);  // @ 0x000118cc
undefined1 commandEngineShutdown(void);  // @ 0x000118fc
void handleJ1939RestartService(dword param_1);  // @ 0x00011908
void cm550_restartThroughBootRomAfterJ1708Request(void);  // @ 0x0001191a
byte restartThroughBootRom(dword request,word acknowledge_datalink);  // @ 0x0001192a
undefined1 inhibitKeyOffShutdown(void);  // @ 0x00011a68
byte cm550_commitEepromMirrorToEeprom(void);  // @ 0x00011a74
void registerJ1939DiagnosticHandlers(void);  // @ 0x00011b36
word cm550_crc16Calculate(byte *data,word byte_count);  // @ 0x00011da6
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
uint vp44_communication_state_machine(word scheduler_call);  // @ 0x00013616
void vp44_initVp44BufferAddresses(void);  // @ 0x000138a0
uint cm550_updateDataloggerTriggers(void);  // @ 0x000138b6
byte * cm550_recordDataloggerSamples(void);  // @ 0x00013a5c
void cm550_initializeDatalogger(void);  // @ 0x00013cc8
undefined4 cm550_selectDataloggerSamplePeriod(void);  // @ 0x00013d42
void cm550_resolveDataloggerTriggerAddresses(void);  // @ 0x00013dbe
void cm550_resolveDataloggerDataParameterAddresses(void);  // @ 0x00013e12
void cm550_findDataloggerTriggerFaultIndexes(void);  // @ 0x00013e64
byte cm550_evaluateDataloggerTrigger(word condition_record_index);  // @ 0x00013ed8
void cm550_copyDataloggerSampleBuffer(undefined1 *param_1,undefined1 *param_2);  // @ 0x00014292
undefined4 cm550_canBusConfigTypeSelector(word config_type);  // @ 0x000142a8
void cm550_FUN_000142d4(word fuel_table_x_input,word lookup_result_offset);  // @ 0x000142d4
void cm550_FUN_00014348(void);  // @ 0x00014348
void cm550_multiSpeedParameterInterpolation(void);  // @ 0x000143b6
void cm550_fuelDemandPercentageCalculator(void);  // @ 0x0001444e
void cm550_countDownPreviouslyActiveFault(word code_index);  // @ 0x000144bc
void cm550_countDownPreviouslyActiveFaults(void);  // @ 0x00014670
word cm550_oldestDiagnosticTimestampSearch(word fault_status);  // @ 0x000146b4
void cm550_diagnosticCodeRegistrar(word code_index);  // @ 0x00014720
void cm550_FUN_00014812(void);  // @ 0x00014812
void cm550_processFaultScanGroup(void);  // @ 0x00014872
void cm550_faultFlagScannerAndProcessor(void);  // @ 0x00014dc6
void cm550_insitePidDtcHandler(word spn_byte);  // @ 0x00014f42
void cm550_initHourMeterSystem(void);  // @ 0x00014fae
byte mc68k_sampleAndDebounceDiscreteInputs(void);  // @ 0x00014fca
void mc68k_ioDriverStrobeHandler(void);  // @ 0x000159ee
void cm550_initializeDiscreteInputs(void);  // @ 0x00015dd0
void mc68k_initializeDiscreteOutputDrivers(void);  // @ 0x00015df0
void cm550_emptyStubFunction4(void);  // @ 0x00015f8c
void mc68k_dispatchJ1708ReceivedMessages(void);  // @ 0x00015f8e
int cm550_safeDivideWithClamp(dword dividend,word divisor);  // @ 0x0001645e
uint cm550_clampedDivisionCalculator(dword dividend,division_operand_t divisor,word max_result);  // @ 0x0001651e
word cm550_param_address_calc(dword dividend,word divisor);  // @ 0x000165f2
uint cm550_limitedDivisionCalculator(dword dividend,division_operand_t divisor,word limit_value);  // @ 0x00016628
void cm550_multiPacketTransmitHandler(void);  // @ 0x0001666c
void cm550_multiPacketReceiveHandler(void);  // @ 0x0001686e
uint cm550_circularBufferEmptyCheck(void);  // @ 0x00016c2c
uint cm550_parameterCircularBufferWrite(dword dest_address,byte *source_ptr,word byte_count);  // @ 0x00016c3c
void cm550_emptyPlaceholderFunction(void);  // @ 0x00016d4c
void mc68k_startJ1708Transmission(void);  // @ 0x00016d4e
uint cm550_highRpmEngineProtectionStateMachine(void);  // @ 0x00016dd4
ushort cm550_fuelTemperatureLimitingSecondary(void);  // @ 0x0001709e
void cm550_FUN_00017120(void);  // @ 0x00017120
void cm550_canControllerConfigInit(void);  // @ 0x00017150
void cm550_derateProtectionSlowCycle20Coordinator(void);  // @ 0x0001717a
void cm550_can1PwmTimerInit(void);  // @ 0x000171aa
uint cm550_calculateEngineSpeed(void);  // @ 0x000171be
void cm550_initializeEngineSpeedCalculation(void);  // @ 0x000176de
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
void cm550_updateEngineState(void);  // @ 0x00017f7c
void initializeEngineState(void);  // @ 0x00018384
void cm550_canRpmModeConfigInit(void);  // @ 0x0001839a
ushort cm550_FUN_000183cc(void);  // @ 0x000183cc
void cm550_FUN_000184c6(void);  // @ 0x000184c6
void cm550_FUN_000185f0(void);  // @ 0x000185f0
uint cm550_engineProtectionMultiStateSlowCycle40Coordinator(void);  // @ 0x00018620
word cm550_protectionThresholdCalculationHelper (word *protection_config,word *protection_state,word *severity_indexes, word derate_selector);  // @ 0x000186ae
word cm550_protectionPercentageCalculator (word sensor_value,word minimum_threshold,word maximum_threshold);  // @ 0x00018708
void vp44_engineProtectionSystemInit(void);  // @ 0x0001873e
uint cm550_protectionConditionEvaluator (word *threshold_ptr,dword *state_ptr,word threshold_set_select,word sensor_value);  // @ 0x00018968
void protectionState0FaultDurationCounter(void);  // @ 0x00018a26
uint cm550_diagnosticProtectionEvaluator(void);  // @ 0x00018ac4
short cm550_diagnosticProtectionProcessor(word *config_ptr,dword state_offset,dword threshold_value);  // @ 0x00018c1c
ushort cm550_protectionState1DiagnosticValidator(void);  // @ 0x00018cb6
void cm550_calculateFaultDerateEngineSpeedLimit(void);  // @ 0x00018e0c
void initializeFaultDerateEngineSpeedLimit(void);  // @ 0x00018f4c
void incrementDiagnosticCounters(dword source_ptr,dword dest_ptr,word condition_flag);  // @ 0x00018f86
ushort processDiagnosticLimitStatus(void);  // @ 0x00018fcc
void cm550_FUN_000192e0(void);  // @ 0x000192e0
word cm550_protectionCalculationHelper(word sensor_value,word extremity_value,word config_flags);  // @ 0x000192f2
ushort protectionStateProcessor(word derate_selector);  // @ 0x00019332
undefined8 protectionStateValidator(word derate_selector);  // @ 0x00019436
void cm550_protectionState3bRpmMonitor(void);  // @ 0x0001952c
void cm550_shutdownMinimumSelector29(void);  // @ 0x000196e4
void cm550_FUN_00019702(void);  // @ 0x00019702
void cm550_initShutdownLimitVariables(void);  // @ 0x00019960
word mc68k_initializeTpuChannel10PrimarySpeedInputDivided(void);  // @ 0x0001999c
word mc68k_phase2_slot_0_handler(void);  // @ 0x000199fa
void cm550_delayWithWatchdogServiceWrapper2(void);  // @ 0x00019ac2
void cm550_emptyStubFunction7(void);  // @ 0x00019aca
undefined8 mc68k_tpuChannel10PrimarySpeedInterruptHandlerMode0(void);  // @ 0x00019acc
word mc68k_FUN_00019caa(void);  // @ 0x00019caa
void mc68k_initializeTpuChannel0MissingToothInput(void);  // @ 0x00019dd0
void cm550_FUN_00019e8e(void);  // @ 0x00019e8e
undefined8 mc68k_tpuChannel10PrimarySpeedInterruptHandlerMode1(void);  // @ 0x00019e90
void cm550_rpmTimingDeltaComparatorWithReturn(void);  // @ 0x0001a1e0
void cm550_FUN_0001a298(void);  // @ 0x0001a298
void mc68k_FUN_0001a350(void);  // @ 0x0001a350
void mc68k_FUN_0001a47c(void);  // @ 0x0001a47c
void cm550_FUN_0001a52a(void);  // @ 0x0001a52a
undefined8 mc68k_tpuChannel10PrimarySpeedInterruptHandlerMode2(void);  // @ 0x0001a52c
undefined8 mc68k_crankFuelAndTimingBufferStore(void);  // @ 0x0001a6e8
uint mc68k_initializeTpuChannel10PrimarySpeedInputIfEnabled(void);  // @ 0x0001a746
void cm550_FUN_0001a89a(void);  // @ 0x0001a89a
void cm550_FUN_0001a8a2(void);  // @ 0x0001a8a2
undefined8 mc68k_tpuChannel10PrimarySpeedInterruptHandlerMode3(void);  // @ 0x0001a8a4
dword cm550_processPrimarySpeedPulsePeriodWithSyncPulse(dword pulse_period,word edge_time_stamp);  // @ 0x0001a95a
int vp44FaultThresholdTablesInit(void);  // @ 0x0001a95e
uint cm550_updateElectronicSmartPowerTau(void);  // @ 0x0001abb2
void cm550_initializeElectronicSmartPower(void);  // @ 0x0001ade8
void mc68k_initializeTpuChannel1BackupSpeedInput(void);  // @ 0x0001ae22
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
undefined8 executiveFrameInterruptHandler(void);  // @ 0x0001b876
void mc68k_scheduler_init(void);  // @ 0x0001bf54
uint cm550_circularBufferPush(dword *buffer_ctrl,byte data_byte);  // @ 0x0001bfa2
uint cm550_circularBufferPop(dword *buffer_ctrl,byte *data_out);  // @ 0x0001bfde
void cm550_circularBufferInit(dword *buffer_ctrl,dword base_address,word buffer_size);  // @ 0x0001c016
void cm550_diagnosticFuelLimitInterpolator(void);  // @ 0x0001c03c
void cm550_FUN_0001c0d4(void);  // @ 0x0001c0d4
void fuelTimingOilPressureModeController(void);  // @ 0x0001c152
void cm550_FUN_0001c308(void);  // @ 0x0001c308
FLASH_ERASE_RESULT mc68k_flashEraseBlock(void);  // @ 0x0001c31a
FLASH_ERASE_RESULT cm550_flashEraseFromRam(dword block_address,dword suspend_check_disabled);  // @ 0x0001c484
undefined4 cm550_flashProgramAndVerifyWords(void);  // @ 0x0001c4ba
void cm550_flashProgramFromRam(dword dest_address,dword source_ptr,word byte_count);  // @ 0x0001c5e8
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
short cm550_calculateBlendedTableValue(word fuel_table_x_input,word throttle_input);  // @ 0x0001cb76
void cm550_FUN_0001cc72(void);  // @ 0x0001cc72
void cm550_FUN_0001cdf8(void);  // @ 0x0001cdf8
void cm550_FUN_0001ce58(void);  // @ 0x0001ce58
void runHighSpeedGovernorPid(void);  // @ 0x0001ce7c
void presetHighSpeedGovernorIntegrator(void);  // @ 0x0001d252
void initializeHighSpeedGovernorGainSet(void);  // @ 0x0001d2e4
uint selectHighSpeedGovernorGainSet(void);  // @ 0x0001d392
void selectEngineSpeedLimit(void);  // @ 0x0001d5a0
void initializeEngineSpeedLimitDefaults(void);  // @ 0x0001d94e
uint vp44SensorStatusMonitor(void);  // @ 0x0001d9b4
void vp44_FUN_0001db8a(void);  // @ 0x0001db8a
void vp44_fuelArbitratorVariablesReset(void);  // @ 0x0001db9a
void cm550_FUN_0001dbd8(void);  // @ 0x0001dbd8
void mc68k_main(void);  // @ 0x0001dbee
void cm550_initializeAlpha(void);  // @ 0x0001dcfc
void cm550_diagnosticBufferPointerInit(void);  // @ 0x0001dd2c
void cm550_FUN_0001ddb4(void);  // @ 0x0001ddb4
undefined4 cm550_FUN_0001de58(void);  // @ 0x0001de58
void cm550_subtractAndClampValue(word *fuel_value_ptr);  // @ 0x0001e02a
void cm550_FUN_0001e04c(void);  // @ 0x0001e04c
void handleJ1939CanTransmitInterrupt(word message_object_number);  // @ 0x0001e056
void cm550_handleJ1939CanReceiveInterrupt(word message_object_number);  // @ 0x0001e086
undefined8 mc68k_canCs4InterruptHandler(void);  // @ 0x0001e0fa
void cm550_canMessageInterruptHandlerSetup(void);  // @ 0x0001e1a0
void vp44_handleCanCs5TransmitInterrupt(word message_object);  // @ 0x0001e1ac
void vp44_handleCanCs5ReceiveInterrupt(word message_object);  // @ 0x0001e1be
undefined8 mc68k_canCs5InterruptHandler(void);  // @ 0x0001e1d0
void cm550_serialCommunicationIsrRegister(void);  // @ 0x0001e25a
void mc68k_armJ1708BusTimer(void);  // @ 0x0001e266
undefined8 mc68k_j1708SciInterruptHandler(void);  // @ 0x0001e288
void cm550_tpuChannelIsrRegister(void);  // @ 0x0001e522
uint mc68k_canCs4TransmitNextFrame(void);  // @ 0x0001e52e
void mc68k_queueCanCs4ReceiveMessage(word message_object);  // @ 0x0001e5f0
undefined8 cm550_interruptCounter1Increment(void);  // @ 0x0001e734
undefined8 cm550_interruptCounter2Increment(void);  // @ 0x0001e76a
void cm550_initVectorTable(void);  // @ 0x0001e77a
byte cm550_insiteMultiFrameResponseBuilder(word first_frame_byte_count,word frame_byte_count);  // @ 0x0001e79a
void cm550_insiteMultiFrameContinuation(void);  // @ 0x0001e89e
void buildPgn65228Dm3ClearInitMessage(void);  // @ 0x0001e956
void cm550_responseBufferSpaceCheck(void);  // @ 0x0001eb88
void cm550_responseBufferFinalize(void);  // @ 0x0001ec08
void cm550_diagnosticMemoryWriteHandler(word service_id);  // @ 0x0001ec3c
void cm550_diagnosticMemoryReadHandler(word service_id);  // @ 0x0001edae
void cm550_diagnosticMessage45Builder(void);  // @ 0x0001f0de
void cm550_diagnosticMessage46Builder(void);  // @ 0x0001f2d0
tsc1_source_configuration_t * cm550_FUN_0001f4e8(void);  // @ 0x0001f4e8
void cm550_fuelDemandScaleFactorCalculator(void);  // @ 0x0001f84e
tsc1_source_configuration_t * cm550_engineFluidLevelDataBuilder(void);  // @ 0x0001f8bc
void cm550_extendedDiagnosticService51(void);  // @ 0x0001fbb0
void cm550_diagnosticMessage53Builder(void);  // @ 0x0001fbf4
void cm550_diagnosticMessage54Builder(void);  // @ 0x0001fc9c
uint cm550_j1939TimeoutDataClearHandler(void);  // @ 0x0001fd6c
void cm550_crankStateVariablesReset(void);  // @ 0x0001fd8e
dword cm550_j1939MessageTypeCounter(word control_mode);  // @ 0x0001fdc0
void cm550_canMessageFilterInit(void);  // @ 0x0001fe40
uint cm550_engineRunTimeHistogramAccumulator(void);  // @ 0x0001ff38
void cm550_emptyPlaceholderInit(void);  // @ 0x0001ffd0
byte cm550_j1939TorqueControlModeParser(can_std_rx_desc_t *request,byte enable);  // @ 0x0001ffd6
void cm550_j1939TorqueControlModeClear(can_std_rx_desc_t *param_1);  // @ 0x000200a4
void cm550_j1939TorqueControlModeSet(can_std_rx_desc_t *param_1);  // @ 0x000200b4
void cm550_systemFunction6xParameterized(void);  // @ 0x000200c6
void cm550_FUN_000201d6(word bit_index);  // @ 0x000201d6
void cm550_FUN_00020210(word bit_index);  // @ 0x00020210
void cm550_FUN_0002024a(word bit_index);  // @ 0x0002024a
uint cm550_FUN_00020284(void);  // @ 0x00020284
uint cm550_FUN_000202a0(void);  // @ 0x000202a0
uint cm550_FUN_000202bc(void);  // @ 0x000202bc
void setBitInArray(word bit_index);  // @ 0x000202d8
void cm550_FUN_00020310(word bit_index);  // @ 0x00020310
void cm550_FUN_00020348(word bit_index);  // @ 0x00020348
uint cm550_FUN_00020380(void);  // @ 0x00020380
uint cm550_FUN_0002041c(void);  // @ 0x0002041c
uint cm550_outputControlState1Handler(void);  // @ 0x000204b0
void cm550_FUN_000205c4(void);  // @ 0x000205c4
uint cm550_FUN_000206a8(dword input_state,dword debounce_mask);  // @ 0x000206a8
uint cm550_FUN_00020784(void);  // @ 0x00020784
uint cm550_FUN_00020890(word input_index);  // @ 0x00020890
uint cm550_FUN_00020c98(void);  // @ 0x00020c98
uint cm550_FUN_00020e14(void);  // @ 0x00020e14
uint cm550_FUN_00020fac(void);  // @ 0x00020fac
void cm550_FUN_00021070(void);  // @ 0x00021070
void cm550_FUN_00021146(void);  // @ 0x00021146
void cm550_FUN_000211f4(void);  // @ 0x000211f4
uint mc68k_FUN_000212b2(void);  // @ 0x000212b2
ushort cm550_FUN_0002142c(void);  // @ 0x0002142c
byte writeJ1939DiagnosticMemory(dword request,dword address,dword length);  // @ 0x0002148a
void cm550_j1939DataCopyWrapper2Byte(int param_1);  // @ 0x0002167e
void cm550_FUN_000216c6(int param_1);  // @ 0x000216c6
void cm550_j1939DataCopyWrapperExtended(int param_1);  // @ 0x00021714
void cm550_FUN_00021778(int param_1);  // @ 0x00021778
void handleJ1939WriteMemoryService(dword request);  // @ 0x000217de
void handleJ1939WriteMemoryLongLengthService(dword request);  // @ 0x00021826
void cm550_FUN_00021872(void);  // @ 0x00021872
undefined4 byteSwap32(undefined4 *param_1);  // @ 0x000218ca
undefined2 byteSwap16(undefined2 *param_1);  // @ 0x000218fe
byte cm550_FUN_00021920(void);  // @ 0x00021920
byte getJ1939MemoryServiceHeaderLength(word service_id);  // @ 0x00021964
undefined4 cm550_diagnosticServiceSecurityValidator(dword msg_ptr);  // @ 0x00021982
void receivePgn57344CabMessage1(int param_1);  // @ 0x00021a5c
void receivePgn61441ElectronicBrakeController1Message(int param_1);  // @ 0x00021a8c
void receivePgn61443ElectronicEngineController2Message(int param_1);  // @ 0x00021b88
void receivePgn65252ShutdownMessage(int param_1);  // @ 0x00021c3c
void receivePgn65264PowerTakeoffInformationMessage(int param_1);  // @ 0x00021c74
void receivePgn65265CruiseControlVehicleSpeedMessage(int param_1);  // @ 0x00021d44
void cm550_tickJ1939InputSupervision(void);  // @ 0x00021edc
void cm550_registerJ1939InputMessageHandlers(void);  // @ 0x00021ef6
void cm550_diagnosticGroupPositionBufferStore(byte session_kind);  // @ 0x00021f4e
void cm550_diagnosticGroupSnapshotCapture(byte command_record_index);  // @ 0x00021fac
uint cm550_memoryRegisterController(void);  // @ 0x00022070
undefined4 cm550_canDiagnosticResponseSender(byte *param_1);  // @ 0x000222b4
void cm550_systemFunction1xCaller(void);  // @ 0x00022370
void cm550_diagMemoryReadResponseBuilder(byte *request_ptr,dword start_address,dword read_length);  // @ 0x0002238e
void cm550_FUN_00022530(int param_1);  // @ 0x00022530
void cm550_FUN_0002257c(int param_1);  // @ 0x0002257c
void cm550_FUN_000225e0(int param_1);  // @ 0x000225e0
void cm550_FUN_00022646(byte *param_1);  // @ 0x00022646
void cm550_FUN_0002268e(byte *param_1);  // @ 0x0002268e
void cm550_FUN_000226da(void);  // @ 0x000226da
void sendJ1939MultiFrame(j1939_tx_msg_t *msg);  // @ 0x00022726
void cm550_diagnosticParamRequestHandler(can_std_rx_desc_t *rx_msg);  // @ 0x00022956
void cm550_messageErrorHandler(byte destination_address,word pgn);  // @ 0x000229ea
void vp44CanFrameBuilder(byte destination_address,word pgn);  // @ 0x00022a58
byte vp44MessageTransmitter (byte destination_address,byte next_packet_number,byte packet_count,word pgn);  // @ 0x00022ad8
void vp44FuelTempHandler(can_std_rx_desc_t *rx_msg);  // @ 0x00022b50
void vp44MultiFrameResponseHandler(int param_1);  // @ 0x00022c26
void cm550_diagnosticStatusRequestHandler(can_std_rx_desc_t *rx_msg);  // @ 0x00022d8e
void vp44_diagnosticErrorHandler(can_std_rx_desc_t *rx_msg);  // @ 0x00022de2
void vp44_diagnosticServiceByteHandler(void);  // @ 0x00022de6
void vp44CanMessageDispatcher(can_std_rx_desc_t *rx_msg);  // @ 0x00022e5e
void cm550_diagnosticParamRequestHandlerWrapper(void);  // @ 0x00022e96
void vp44FuelTempHandlerWrapper(void);  // @ 0x00022ea4
void cm550_diagnosticStatusRequestHandlerWrapper(void);  // @ 0x00022eb2
void cm550_diagnosticErrorHandlerWrapper(void);  // @ 0x00022ec0
void cm550_unknownMessageHandler(uint param_1);  // @ 0x00022ece
void cm550_diagnosticMessageProcessor(void);  // @ 0x00022fae
void vp44ResponseTimeoutHandler(void);  // @ 0x000230d6
void vp44_messageQueueDispatcher(void);  // @ 0x000230ee
j1939_tx_msg_t * cm550_multiPacketBufferAllocator(word data_length);  // @ 0x00023130
void vp44DiagnosticBufferPointersInit(void);  // @ 0x00023186
void cm550_fuelArbitratorResetHandler(void);  // @ 0x000231da
void cm550_FUN_00023216(void);  // @ 0x00023216
void cm550_statisticsTrackingFlagsReset(void);  // @ 0x0002322a
uint cm550_fuelDemandLimitOrchestrator(void);  // @ 0x00023244
word cm550_diagnosticMessageValidator (word network_type,word source_address,word override_control_mode);  // @ 0x00023820
word cm550_ioControlTimeoutTableLookup(word source_address);  // @ 0x00023870
void cm550_ioControlEntryAdd(word network_type,byte source_address,word override_control_mode);  // @ 0x000238ac
void cm550_ioControlTimeoutEntryAdd(byte source_address);  // @ 0x000238ec
void cm550_phase3_countdown_timer_manager(void);  // @ 0x00023920
void cm550_diagnosticStateInitializer(word network_type,word source_address);  // @ 0x000239d2
void cm550_ioControlEntryRemove(word source_address);  // @ 0x00023a3c
ushort processProtectionFlagConditions(void);  // @ 0x00023a90
void diagnosticMainStateProcessor(void);  // @ 0x00023be8
void cm550_FUN_00024804(void);  // @ 0x00024804
void cm550_iahDisableWaitToStartLamp(void);  // @ 0x00024812
void cm550_initIoControlRegister(void);  // @ 0x0002481e
void cm550_ioControlMaskInit(void);  // @ 0x0002482e
void cm550_ioControlMaskStateMachine(void);  // @ 0x00024858
uint cm550_ioControlToggleCycle(void);  // @ 0x000249b6
undefined1 vp44_ioControlLampStateMachine(void);  // @ 0x000249ee
uint cm550_ioControlDigitDisplaySequencer(word fault_code);  // @ 0x00024b4e
byte cm550_FUN_00024c5a(byte current_fault_index);  // @ 0x00024c5a
byte cm550_FUN_00024cd2(byte current_fault_index);  // @ 0x00024cd2
int cm550_faultCodeDisplayController(void);  // @ 0x00024d40
void cm550_activeFaultLampStateMachine(void);  // @ 0x00024f30
void cm550_faultLampBlinkPatternGenerator(void);  // @ 0x00025316
void cm550_FUN_000253b0(void);  // @ 0x000253b0
void cm550_periodicLampFlashController(void);  // @ 0x00025448
void cm550_FUN_000254b6(void);  // @ 0x000254b6
void cm550_clearSystemErrorStatus(void);  // @ 0x00025594
void cm550_calculatePedalFaultModeFuelDemand(void);  // @ 0x0002571e
void cm550_FUN_00025806(word previous_user_fueling_state);  // @ 0x00025806
void presetPedalFaultModeFuelDemand(void);  // @ 0x000258b0
void initializePedalFaultModeEngineSpeedFilter(void);  // @ 0x000258d6
void cm550_epsTimingCalculationSlowCycle40Coordinator(void);  // @ 0x000258e8
void cm550_initLookupTablePointers1(void);  // @ 0x00025926
void cm550_governorFuelPidController(void);  // @ 0x0002595a
void cm550_fuel_delivery_controller(void);  // @ 0x00025a30
void vp44_FUN_00025a34(void);  // @ 0x00025a34
void cm550_runLowSpeedGovernor(void);  // @ 0x00025b1c
void cm550_presetLowSpeedGovernorSpeedError(void);  // @ 0x00025ff2
void cm550_initializeLowSpeedGovernor(void);  // @ 0x00026078
uint cm550_epsAccelerationMonitor(void);  // @ 0x0002609c
void cm550_epsRpmTrackingInit(void);  // @ 0x00026252
void cm550_epsControlModeReset(void);  // @ 0x0002626a
word cm550_epsOverrideChecker(word gain_set_already_selected);  // @ 0x00026272
void cm550_epsControlModeSelector(void);  // @ 0x0002629e
void cm550_epsInitializationWrapper(void);  // @ 0x000262fa
void cm550_epsControlModeInit(void);  // @ 0x00026308
void cm550_epsDiagnosticModeHandler(void);  // @ 0x00026340
void cm550_initOilPressureMonitoring(void);  // @ 0x00026462
void cm550_engineModeTimingAdjuster(void);  // @ 0x00026474
void vp44_rpm_derate_monitor(void);  // @ 0x00026484
void cm550_fuelDemandLimitSource2Selector(void);  // @ 0x0002658c
void vp44_initVP44StatusFlags(void);  // @ 0x0002659a
uint cm550_epsRpmTargetModeChecker(void);  // @ 0x000265e6
void cm550_FUN_00026616(void);  // @ 0x00026616
void cm550_timingOffsetCalculatorWrapper(void);  // @ 0x000266d2
uint mc68k_runSerialEepromWriteQueue(void);  // @ 0x000266da
undefined8 mc68k_FUN_00026834(void);  // @ 0x00026834
void cm550_FUN_00026852(void);  // @ 0x00026852
void mc68k_FUN_00026854(void);  // @ 0x00026854
void cm550_FUN_000269f2(void);  // @ 0x000269f2
void cm550_FUN_00026a2e(void);  // @ 0x00026a2e
void cm550_memcpy(byte *destination,byte *source,word byte_count);  // @ 0x00026a64
void cm550_fuelDemandTablePointersInit(void);  // @ 0x00026a7e
undefined2 cm550_rpmLoadParameterLookup(void);  // @ 0x00026ab8
ushort cm550_FUN_00026af0(void);  // @ 0x00026af0
ushort vp44OperatingConditionChecker(void);  // @ 0x00026b00
void cm550_FUN_00026b3a(void);  // @ 0x00026b3a
void cm550_FUN_00026b82(void);  // @ 0x00026b82
void hpcr_injectorPulseWidthCalc(void);  // @ 0x00026b88
ushort mc68k_pwmOutputInit(void);  // @ 0x00026c7e
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
void restartOnKeyOnDuringPowerDown(void);  // @ 0x00027af0
void vp44_FUN_00027c20(void);  // @ 0x00027c20
void cm550_savePowerDownDataToFlashBank(byte flash_bank_number);  // @ 0x00027cd0
void mc68k_runPowerDownSequence(void);  // @ 0x00027f9c
void mc68k_applicationMain(void);  // @ 0x000284e8
void cm550_restartApplicationWithoutReset(void);  // @ 0x00028978
void mc68k_dualCanControllerInit(void);  // @ 0x00028a04
void mc68k_initializeJ1939Datalink(void);  // @ 0x00028b80
word mc68k_initializeJ1708Datalink(void);  // @ 0x00029130
void cm550_updateBootBlockFromImage(void);  // @ 0x0002ce64
void cm550_FUN_0002cf52(byte *source,word byte_count);  // @ 0x0002cf52
byte cm550_FUN_0002cf7e(word write_record_count);  // @ 0x0002cf7e
void cm550_systemControl64(void);  // @ 0x0002d09e
void cm550_systemControl74(void);  // @ 0x0002d1c2
void cm550_systemControl75(void);  // @ 0x0002d1e0
void cm550_memoryPatchBufferInit(void);  // @ 0x0002d1fe
uint cm550_memoryPatchingSystem(void);  // @ 0x0002d216
void cm550_runPowerTakeOffGovernor(void);  // @ 0x0002d3c6
void cm550_FUN_0002d9a8(void);  // @ 0x0002d9a8
void cm550_presetPowerTakeOffGovernorOnEngagement(void);  // @ 0x0002d9d2
void initializePowerTakeOffGovernorFiltersAndGains(void);  // @ 0x0002db2a
void smoothPowerTakeOffReferenceEngineSpeed(void);  // @ 0x0002dbde
void presetPowerTakeOffSmoothedReferenceEngineSpeed(void);  // @ 0x0002dc8c
void initializePowerTakeOffReferenceFilter(void);  // @ 0x0002dc9e
uint cm550_oil_pressure_shutdown_controller(void);  // @ 0x0002dcb0
void cm550_FUN_0002ddbc(void);  // @ 0x0002ddbc
void mc68k_hardwareTimerFlagsInit(void);  // @ 0x0002ddce
void mc68k_initDiagnosticModeSystem(void);  // @ 0x0002ddd6
uint mc68k_monitorPwmOutputReadBackFaults(void);  // @ 0x0002dde8
ulonglong mc68k_stepPwm3AndPwm4OutputStartUpTest(void);  // @ 0x0002e2f4
undefined8 mc68k_pwmFuelDemandOutputCalculator(void);  // @ 0x0002e5c0
void initQadcModule(void);  // @ 0x0002e95e
void clearWorkingRam(void);  // @ 0x0002e9ac
void cm550_initializeRamRefresh(void);  // @ 0x0002e9f8
void cm550_refreshRamCalibration(void);  // @ 0x0002eadc
void cm550_FUN_0002ec50(void);  // @ 0x0002ec50
void cm550_FUN_0002ed62(void);  // @ 0x0002ed62
char cm550_insiteParameterParser(void);  // @ 0x0002ed6a
undefined2 cm550_parameterLookupForInsite(void);  // @ 0x0002edb2
void cm550_diagnosticServiceDispatcher(dword msg_ptr);  // @ 0x0002eea2
void cm550_systemControlFunction1(void);  // @ 0x0002ef08
void cm550_diagnosticResponseHandler2(can_std_rx_desc_t *param_1);  // @ 0x0002ef1c
void cm550_canTransmissionTrigger(void);  // @ 0x0002ef36
void cm550_FUN_0002ef4a(dword msg_ptr);  // @ 0x0002ef4a
void cm550_systemControlFunction2(void);  // @ 0x0002efbc
ushort cm550_diagnosticServiceDispatcherByPgn(int param_1);  // @ 0x0002efd0
void cm550_systemControlFunction3(void);  // @ 0x0002f114
void processEngineTsc1Request(int param_1);  // @ 0x0002f128
void cm550_FUN_0002f4be(can_std_rx_desc_t *rx_msg);  // @ 0x0002f4be
void cm550_diagnosticDataDump(void);  // @ 0x0002f538
word cm550_FUN_0002f606(word requested_torque);  // @ 0x0002f606
void j1939FormatMultiFrameResponse(void);  // @ 0x0002f632
void cm550_retarderControlModeHandler(int param_1);  // @ 0x0002f7e6
void cm550_FUN_0002faa4(void);  // @ 0x0002faa4
void cm550_initOilPressureProtectionPointers(void);  // @ 0x0002faba
void cm550_torqueControlAddressDispatcher(int param_1);  // @ 0x0002fb70
void cm550_FUN_0002fbb2(void);  // @ 0x0002fbb2
void unscrambleSecurityKey(byte *input_buffer,byte *output_buffer);  // @ 0x0002fbd8
byte validateSecurityKey(byte *auth_payload_ptr);  // @ 0x0002fcdc
void cm550_FUN_0002fd90(word code_index);  // @ 0x0002fd90
void cm550_resetFaultStatus(word code_index);  // @ 0x0002fddc
void cm550_diagnosticTableSnapshotCapture(word snapshot_slot,word code_index);  // @ 0x0002fe38
undefined8 mc68k_j1708BusTimerInterruptHandler(void);  // @ 0x000300d4
void mc68k_engineSpeedIsrRegister(void);  // @ 0x00030274
void mc68k_engineRpmHardwareTimerSetup(void);  // @ 0x00030290
void mc68k_initializeTpuChannel12(void);  // @ 0x00030342
void cm550_emptyStubFunction9(void);  // @ 0x000303c8
void cm550_emptyInitPlaceholder(void);  // @ 0x000303d2
undefined4 cm550_accumulatorWithOverflowCarry(uint *param_1,uint *param_2);  // @ 0x000303d4
void cm550_runTimeCountersUpdate(void);  // @ 0x00030414
void cm550_runTimeCountersUpdateAlt(void);  // @ 0x00030454
byte cm550_FUN_00030498(void);  // @ 0x00030498
void cm550_rpmHistogramAndAveragingStatistics(void);  // @ 0x000304f4
uint cm550_fuelLimitRestoreFromCapture(void);  // @ 0x0003061a
uint cm550_FUN_000306ca(void);  // @ 0x000306ca
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
void mc68k_loadTpuMicrocode(void);  // @ 0x00031428
ushort cm550_FUN_00031496(void);  // @ 0x00031496
void cm550_FUN_000315be(void);  // @ 0x000315be
ushort cm550_FUN_00031a68(void);  // @ 0x00031a68
word findTsc1SourceConfiguration(word data_link,word source_address);  // @ 0x00031ace
void cm550_diagnosticCanResponseSender(can_std_rx_desc_t *request,word acknowledgement_type);  // @ 0x00031b22
void cm550_canBufferSetup1(void);  // @ 0x00031b96
void cm550_FUN_00031bce(void);  // @ 0x00031bce
void cm550_j1939MessageSetup_PGN_65265(void);  // @ 0x00031c1a
void j1939HandlePgn65265CruiseVehicleSpeed(void);  // @ 0x00031c84
void cm550_FUN_00031ed2(void);  // @ 0x00031ed2
void j1939HandlePgn65261CruiseControlSetup(void);  // @ 0x00031f30
void initPgn65261CruiseControlSetupStruct(void);  // @ 0x00031fee
void cm550_FUN_00032052(void);  // @ 0x00032052
void cm550_engineSerialNumberPGN_65259_Builder(void);  // @ 0x000320f6
undefined4 cm550_diagnosticMultiPacketResponseBuilder(can_std_rx_desc_t *request,word result_code);  // @ 0x0003216a
void cm550_diagnosticDM11PGN_65234_Builder(void);  // @ 0x00032244
uint j1939HandlePgn65226Dm1ActiveDtc(void);  // @ 0x000322ae
void cm550_engineCoolantPGN_65226_Builder(void);  // @ 0x000323be
uint cm550_previousDtcListBuilder(void);  // @ 0x0003241c
void cm550_diagnosticDM2PGN_65227_Builder(void);  // @ 0x0003252c
uint evaluateTemperatureDiagnosticState(void);  // @ 0x0003258a
void cm550_diagnosticDM4PGN_65229_Builder(void);  // @ 0x000329d2
void vp44_diagnosticDM5DataBuilder(void);  // @ 0x00032a42
void cm550_diagnosticDM5PGN_65230_Builder(void);  // @ 0x00032ae2
void vp44_diagnosticByteResponseSender(byte first_data_byte,word response_code);  // @ 0x00032b38
void vp44_diagnosticDM8PGN_65232_Builder(void);  // @ 0x00032b64
void vp44_FUN_00032c22(void);  // @ 0x00032c22
void sendPgn61444ElectronicEngineController1Message(void);  // @ 0x00032c76
void vp44Message300FaultFlagProcessor(void);  // @ 0x00032c7a
void vp44Command0x100Builder(void);  // @ 0x00032e08
void j1939HandlePgn61443Eec2(void);  // @ 0x00032e4c
void vp44_cumminsProprietaryDM_983_Builder(void);  // @ 0x00033064
void vp44_configParamCanBuilder(void);  // @ 0x000330c4
void vp44_secondaryParamPGN_65247_Builder(void);  // @ 0x00033120
void vp44_FUN_00033164(void);  // @ 0x00033164
void vp44_engineFluidLevelPGN_65263_Builder(void);  // @ 0x000331ae
void buildPgn65251EngineConfiguration1Payload(undefined4 *param_1);  // @ 0x0003320e
byte cm550_FUN_000333d6(word previous_value,word current_value);  // @ 0x000333d6
byte cm550_FUN_00033460(word previous_value,word current_value);  // @ 0x00033460
void cm550_FUN_000334ec(void);  // @ 0x000334ec
byte cm550_FUN_0003366a(void);  // @ 0x0003366a
void initializePgn65251EngineConfiguration1Buffer(void);  // @ 0x00033692
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
uint vp44CanMessage100ResponseBuilder(void);  // @ 0x0003407a
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
MEMORY_REGION_TYPE lookupApplicationMemoryRegionType(dword range_start,word range_length);  // @ 0x0003460e
uint mc68k_initializeSpeedMeasurementMode0(void);  // @ 0x00034674
uint mc68k_timerCaptureHardwareInit(void);  // @ 0x00034696
void mc68k_resetSpeedMeasurementMode0(void);  // @ 0x0003478c
uint mc68k_setUpTpuChannel3AnglePulseOutput(void);  // @ 0x0003480e
uint mc68k_updateTpuChannel3AnglePulseOutput(void);  // @ 0x0003494a
void mc68k_configureTpuChannelsForSpeedMeasurementMode(void);  // @ 0x00034a82
undefined8 mc68k_alignCylinderIndexToCrankRevolution(void);  // @ 0x00034b20
void mc68k_delayTimeBaseTicksWithWatchdogService(word tick_count);  // @ 0x00034bba
void mc68k_delayTimeBaseTicksWithWatchdogService2(word tick_count);  // @ 0x00034bf8
ushort vp44FaultRegisterBit2Monitor(void);  // @ 0x00034c36
void vp44_liftPumpFuelDeliveryController(void);  // @ 0x00034cc4
void vp44_FUN_00034d52(void);  // @ 0x00034d52
void cm550_FUN_00034dba(void);  // @ 0x00034dba
short lookupTableInterpolation(table_interp_args_t *args);  // @ 0x00034de0
word cm550_signedFirstOrderFilter(word new_sample,ema_filter_state_t *filter_state);  // @ 0x00034e9a
word cm550_secondOrderFilter(word input,second_order_filter_state_t *filter);  // @ 0x00034f00
word cm550_exponentialMovingAverage(word new_sample,ema_filter_state_t *filter_state);  // @ 0x00034f8a
word cm550_secondOrderFilterUnsigned(word input,second_order_filter_state_t *filter);  // @ 0x00034fe0
undefined4 cm550_scaleByRatio(dword multiplicand,dword multiplier,dword divisor);  // @ 0x00035064
undefined4 cm550_scaleByRatioSigned(dword multiplicand,dword multiplier,dword divisor);  // @ 0x00035076
undefined8 cm550_tableLookup2D(word *table_args);  // @ 0x00035088
