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
void mc68k_hardwareInitializationAndStartup(void);  // @ 0x00003a94
void mc68k_restartBootRomWithoutReset(void);  // @ 0x00003abe
void cm550_ramClearWithWatchdog(void);  // @ 0x00003c20
uint cm550_updateDutyCycleMonitorLoadHistogram(void);  // @ 0x0000ac3c
void cm550_initializeDutyCycleMonitor(void);  // @ 0x0000af70
void cm550_storeDutyCycleMonitorShortTermMaps(void);  // @ 0x0000b130
void calculateFilteredEngineAcceleration(void);  // @ 0x0000b210
void cm550_calculateAccelerationNoiseControlFuelLimit(void);  // @ 0x0000b2aa
void cm550_applyAccelerationNoiseControlFuelLimit(void);  // @ 0x0000b3b2
void cm550_calculateAccelerationNoiseControlTimingLimit(void);  // @ 0x0000b3d0
void cm550_applyAccelerationNoiseControlTimingLimit(void);  // @ 0x0000b4ce
void cm550_calculateAccelerationNoiseControlEngineSpeedLimit(void);  // @ 0x0000b4f2
void initializeEngineAccelerationFilters(void);  // @ 0x0000b5e4
void cm550_initializeAccelerationNoiseControlFuelLimit(void);  // @ 0x0000b614
void cm550_initializeAccelerationNoiseControlTimingLimit(void);  // @ 0x0000b63e
void cm550_initializeAccelerationNoiseControlEngineSpeedLimit(void);  // @ 0x0000b666
byte getJ1939DiagnosticResponseEchoLength(word diagnostic_service);  // @ 0x0000b688
void cm550_diagnosticMessageQueueWrite(word response_type);  // @ 0x0000b6e8
void mc68k_processAnalogSensorChannels(void);  // @ 0x0000b7bc
void cm550_initializeAnalogSensorChannels(void);  // @ 0x0000bcf0
ushort cm550_fuelTimingTransitionStateMachine(void);  // @ 0x0000c180
void cm550_initializeFuelTimingMode(void);  // @ 0x0000c246
void applyAirFuelControlFuelLimit(void);  // @ 0x0000c2a0
void cm550_diagnosticTimingIncrementController(void);  // @ 0x0000c2be
void cm550_addAirFuelControlTimingAdvance(void);  // @ 0x0000c2ee
ushort calculateAlpha(void);  // @ 0x0000c326
word calculateAlphaFuelRateResult(void);  // @ 0x0000c404
uint calculateAlphaOnGovernorResult(void);  // @ 0x0000c496
int calculateAlphaLowSpeedGovernorResult(void);  // @ 0x0000c4b2
int calculateAlphaAirFuelControlResult(void);  // @ 0x0000c504
word calculateAlphaLowAmbientAirPressureResult(void);  // @ 0x0000c556
uint calculateAlphaBase(void);  // @ 0x0000c582
void cm550_phase2_slot_5_handler(void);  // @ 0x0000c658
void cm550_calculateAltitudeDerateFuelLimit(void);  // @ 0x0000c66a
void cm550_fuelParameterPointerSetup(void);  // @ 0x0000c714
void applyAltitudeDerateFuelLimit(void);  // @ 0x0000c742
void mc68k_configureCanCs5MessageObjects(void);  // @ 0x0000c760
void ignoreCanTransmitInterrupt(void);  // @ 0x0000c80c
void vp44_dispatchReceivedPumpMessage(word message_object);  // @ 0x0000c80e
void cm550_emptyPrimarySpeedInterruptStep(void);  // @ 0x0000c87c
void cm550_emptyBackupSpeedInterruptStep(void);  // @ 0x0000c87e
void cm550_initializeSpeedRequestBlendWeightLookup(void);  // @ 0x0000c880
void cm550_calculateGovernorReferenceSpeedBlend(void);  // @ 0x0000c8a0
void cm550_runAllSpeedGovernor(void);  // @ 0x0000c962
void cm550_selectAllSpeedGovernorApplicationReference(void);  // @ 0x0000d0e2
void cm550_selectAllSpeedGovernorApplicationMode(void);  // @ 0x0000d18a
void cm550_selectTsc1SpeedControlMode(word previous_user_fueling_state);  // @ 0x0000d1a4
void cm550_selectTsc1SpeedControlReference(void);  // @ 0x0000d218
void cm550_calculateAllSpeedGovernorNoLoadFuel(void);  // @ 0x0000d23c
void cm550_initializeAllSpeedGovernorNoLoadFuelLookups(void);  // @ 0x0000d280
void cm550_selectAllSpeedGovernorReference(void);  // @ 0x0000d2be
void cm550_initializeAllSpeedGovernorReferenceSpeedSets(void);  // @ 0x0000d3b2
void cm550_calculateAllSpeedGovernorThrottleDroopGains(void);  // @ 0x0000d3e6
void cm550_selectVariableSpeedGovernorMode(word previous_user_fueling_state);  // @ 0x0000d4ae
void cm550_selectVariableSpeedGovernorReference(void);  // @ 0x0000d584
void cm550_initializeAllSpeedGovernorDroopLookups(void);  // @ 0x0000d59e
void cm550_initializeVehicleSpeedAndCruiseState(void);  // @ 0x0000d5e6
void updateEngineSyncStatus(void);  // @ 0x0000d610
void cm550_clearKickdownControlState(void);  // @ 0x0000e780
uint cm550_monitorBoostPressureSensorInRangeHighReading(void);  // @ 0x0000e998
void vp44_insiteParameterTableIterator(void);  // @ 0x0000eaec
uint cm550_diagnosticMessageTransmissionManager(void);  // @ 0x0000eba4
void cm550_activeParameterReadFunction(void);  // @ 0x0000ec1e
byte cm550_diagnosticCodeTableSearch(word fault_index);  // @ 0x0000ed34
void insiteCommandByteDispatcher(void);  // @ 0x0000ed64
undefined * cm550_calculateAllSpeedGovernorDroopFueling(void);  // @ 0x0000f716
void cm550_parameterSystemModeController(void);  // @ 0x0000f796
void cm550_param_lookup_1(void);  // @ 0x0000f8c6
void cm550_param_lookup_3(void);  // @ 0x0000f930
void emptyPgn61443ElectronicEngineController2InitializationStep(void);  // @ 0x0000f99a
void cm550_calculateNominalFrictionPercentTorque(void);  // @ 0x0000f99c
uint setJ1939TorqueCurvePoint1AtDeratedIdleFueling(void);  // @ 0x0000fa06
void setJ1939TorqueCurvePoints1And3AtDeratedFueling(void);  // @ 0x0000fa68
void cm550_setJ1939TorqueCurvePoints2And5AtDroopLineFueling (word fueling,byte point_5_on_droop_line_flag);  // @ 0x0000faa6
void cm550_updateJ1939EngineConfigurationTorqueCurve(void);  // @ 0x0000fb26
ushort initializeJ1939ReferenceEngineFuelingAndTorque(void);  // @ 0x0000ff48
void cm550_ioControlBasedFuelCalculator(void);  // @ 0x0000ff6c
void cm550_initializeEngineRetarderTorqueLookups(void);  // @ 0x000100da
uint cm550_bufferDecreasingPatternCheck(void);  // @ 0x0001011c
uint cm550_bufferThresholdValidator(void);  // @ 0x000101b8
word cm550_detectEngineSpeedSensorSyncPulse(word backup_sensor_flag);  // @ 0x0001025c
void cm550_initializeEngineSpeedSensorSyncPulseThresholds(void);  // @ 0x00010394
void cm550_sendCanSingleFrame(dword can_identifier,word data_length,byte *data,byte *status);  // @ 0x000103ba
void sendJ1939Message(j1939_transmit_message_t *message);  // @ 0x000104e8
short cm550_arrayRangeSum(word *start_pointer,word *end_pointer);  // @ 0x00010520
void cm550_memoryPatchCountDecrement(void);  // @ 0x00010536
uint vp44_rpmDerateCalculationController(void);  // @ 0x00010568
ulonglong vp44_derateThresholdMonitorAndFaultController(void);  // @ 0x00010822
void cm550_initializeThrottleMinimum(void);  // @ 0x00010e06
int cm550_lookupParameterIdAddress(word parameter_id,dword *resolved_address);  // @ 0x00010e16
uint cm550_loadParameterBlock1FromFlash(void);  // @ 0x00010e80
uint cm550_loadParameterBlock2FromFlash(void);  // @ 0x00010f32
int cm550_saveParameterBlock1ToFlash(void);  // @ 0x00010fe0
int cm550_saveParameterBlock2ToFlash(void);  // @ 0x0001125a
void cm550_loadParameterBlockAndUpdatePowerDownCounts(void);  // @ 0x000114d4
void copyCalibrationFromRomToRam(void);  // @ 0x000117ec
byte cm550_requestClearInactiveFaults(void);  // @ 0x0001183e
byte exitDevelopmentMode(void);  // @ 0x0001188c
byte enterDevelopmentMode(void);  // @ 0x000118b2
byte forceExitDevelopmentMode(void);  // @ 0x000118cc
byte commandEngineShutdown(void);  // @ 0x000118fc
byte handleJ1939RestartService(can_standard_receive_descriptor_t *request);  // @ 0x00011908
void cm550_restartThroughBootRomAfterJ1708Request(void);  // @ 0x0001191a
byte restartThroughBootRom(can_standard_receive_descriptor_t *request,word acknowledge_datalink);  // @ 0x0001192a
byte inhibitKeyOffShutdown(void);  // @ 0x00011a68
byte cm550_commitEepromMirrorToEeprom(void);  // @ 0x00011a74
void registerJ1939DiagnosticHandlers(void);  // @ 0x00011b36
word cm550_crc16Calculate(byte *data,word byte_count);  // @ 0x00011da6
undefined4 cm550_memoryPatchCrcCalculate(void);  // @ 0x00011df8
ushort cm550_coldStartFuelControlSlowCycle40Coordinator(void);  // @ 0x00011e5e
void cm550_addCylinderPressureMaintenanceTimingIncrement(void);  // @ 0x00012484
void cm550_initializeLoadTrendingSystem(void);  // @ 0x000124d2
void mc68k_fillCylinderBalanceSpeedBuffers(void);  // @ 0x0001266e
void cm550_fuelSourceMode11CountdownHandler(void);  // @ 0x0001277c
void cm550_calculateCylinderBalanceTrims(void);  // @ 0x000127c2
void cm550_emptyExecutiveFrame5ExtraTask(void);  // @ 0x000133fc
void cm550_initializeCylinderBalancing(void);  // @ 0x000133fe
void cm550_circularBufferWriteWithStatus(void);  // @ 0x0001355e
uint vp44_communication_state_machine(word scheduler_call);  // @ 0x00013616
void vp44_initializeVp44BufferAddresses(void);  // @ 0x000138a0
uint cm550_updateDataloggerTriggers(void);  // @ 0x000138b6
byte * cm550_recordDataloggerSamples(void);  // @ 0x00013a5c
void cm550_initializeDatalogger(void);  // @ 0x00013cc8
undefined4 cm550_selectDataloggerSamplePeriod(void);  // @ 0x00013d42
void cm550_resolveDataloggerTriggerAddresses(void);  // @ 0x00013dbe
void cm550_resolveDataloggerDataParameterAddresses(void);  // @ 0x00013e12
void cm550_findDataloggerTriggerFaultIndexes(void);  // @ 0x00013e64
byte cm550_evaluateDataloggerTrigger(word condition_record_index);  // @ 0x00013ed8
void cm550_copyDataloggerSampleBuffer(undefined1 *param_1,undefined1 *param_2);  // @ 0x00014292
undefined4 lookupJ1939ControlDevice(word configuration_type);  // @ 0x000142a8
void calculateJ1939PercentPeakTorqueAtSpeed(word fuel_table_x_input,word lookup_result_offset);  // @ 0x000142d4
void calculateJ1939FrictionLoadFuelingAtBreakpoints(void);  // @ 0x00014348
void calculateJ1939PercentPeakTorquePoints(void);  // @ 0x000143b6
void cm550_fuelDemandPercentageCalculator(void);  // @ 0x0001444e
void cm550_countDownPreviouslyActiveFault(word code_index);  // @ 0x000144bc
void cm550_countDownPreviouslyActiveFaults(void);  // @ 0x00014670
word cm550_findOldestFreezeFrameEntryByFaultStatus(word fault_status);  // @ 0x000146b4
void cm550_assignFaultFreezeFrameEntry(word code_index);  // @ 0x00014720
void cm550_clearInactiveFaultsOnRequest(void);  // @ 0x00014812
void cm550_processFaultScanGroup(void);  // @ 0x00014872
void cm550_faultFlagScannerAndProcessor(void);  // @ 0x00014dc6
void cm550_insitePidDtcHandler(word spn_byte);  // @ 0x00014f42
void cm550_initializeHourMeterSystem(void);  // @ 0x00014fae
byte mc68k_sampleAndDebounceDiscreteInputs(void);  // @ 0x00014fca
void mc68k_ioDriverStrobeHandler(void);  // @ 0x000159ee
void cm550_initializeDiscreteInputs(void);  // @ 0x00015dd0
void mc68k_initializeDiscreteOutputDrivers(void);  // @ 0x00015df0
void cm550_emptyDiscreteInputSamplingStep(void);  // @ 0x00015f8c
void mc68k_dispatchJ1708ReceivedMessages(void);  // @ 0x00015f8e
int cm550_safeDivideWithClamp(dword dividend,word divisor);  // @ 0x0001645e
uint cm550_clampedDivisionCalculator(dword dividend,division_operand_t divisor,word max_result);  // @ 0x0001651e
word cm550_param_address_calc(dword dividend,word divisor);  // @ 0x000165f2
uint cm550_limitedDivisionCalculator(dword dividend,division_operand_t divisor,word limit_value);  // @ 0x00016628
void cm550_multiPacketTransmitHandler(void);  // @ 0x0001666c
void cm550_multiPacketReceiveHandler(void);  // @ 0x0001686e
byte cm550_isEepromWriteQueueEmpty(void);  // @ 0x00016c2c
byte cm550_queueEepromMirrorByteWrites(dword mirror_address,byte *source,word byte_count);  // @ 0x00016c3c
byte cm550_queueEepromByteWrites(word eeprom_address,byte *source,word byte_count);  // @ 0x00016cd8
void cm550_emptyPlaceholderFunction(void);  // @ 0x00016d4c
void mc68k_startJ1708Transmission(void);  // @ 0x00016d4e
ushort cm550_runEngineWarmupProtection(void);  // @ 0x00016dd4
ushort cm550_initializeEngineWarmupProtection(void);  // @ 0x0001709e
void cm550_applyEngineWarmupProtectionFuelLimit(void);  // @ 0x00017120
void cm550_initializeEnginePositionSignalInputs(void);  // @ 0x00017150
uint cm550_calculateEngineSpeed(void);  // @ 0x000171be
void cm550_initializeEngineSpeedCalculation(void);  // @ 0x000176de
void cm550_rpmBasedFuelLimitCalculator(void);  // @ 0x000177c2
void cm550_governorFuelModeBlendCalculator(void);  // @ 0x000178b0
void cm550_rpmBasedFuelTimingInterpolation(void);  // @ 0x00017a06
uint cm550_calculateCrankInitialFuelByCoolantTemperature(void);  // @ 0x00017a8e
void selectCrankExitSpeed(void);  // @ 0x00017b8a
uint cm550_calculateCrankInitialAdvanceByIntakeManifoldTemperature(void);  // @ 0x00017baa
void updateCrankReentrySpeed(void);  // @ 0x00017ca6
void cm550_engineModeTransitionStateUpdater(void);  // @ 0x00017cf0
void calculateCrankInitialValuesOnCrankEntry(void);  // @ 0x00017d2a
void cm550_ioOutputFlagMappingSlowCycle40Coordinator(void);  // @ 0x00017d6a
void rampCrankExitFuelAdjustment(void);  // @ 0x00017e06
void updateCrankExitAndJumpStartTimers(void);  // @ 0x00017e62
void cm550_frictionalLoadTorqueTransitionHandler(void);  // @ 0x00017eba
void vp44_fuelLimitParameterPointerSetup(void);  // @ 0x00017ef8
void cm550_updateEngineState(void);  // @ 0x00017f7c
void initializeEngineState(void);  // @ 0x00018384
void cm550_initializeBackupSpeedInputForCamSyncType(void);  // @ 0x0001839a
void cm550_applyFaultDerateToJ1939TorqueCurveFuelings(void);  // @ 0x000183cc
void cm550_calculateFaultDerateJ1939TorqueCurveSpeedPoints(void);  // @ 0x000184c6
void initializeFaultDerateJ1939TorqueCurvePriority(void);  // @ 0x000185f0
void cm550_runEngineProtectionScheduler(void);  // @ 0x00018620
word rampEngineProtectionSeverityIndex (engine_protection_channel_configuration_t *configuration, cm550_engine_protection_channel_state_t *state, engine_protection_channel_history_t *history,word is_engine_speed);  // @ 0x000186ae
word cm550_interpolateEngineProtectionSeverity (word input,word minimum_threshold,word maximum_threshold);  // @ 0x00018708
void cm550_initializeEngineProtection(void);  // @ 0x0001873e
word cm550_isEngineProtectionInputPastThreshold (engine_protection_channel_configuration_t *configuration, cm550_engine_protection_channel_state_t *state,word is_engine_speed, word threshold_select);  // @ 0x00018968
void countEngineProtectionOverLimitDurations(void);  // @ 0x00018a26
void cm550_examineEngineProtectionBeforeCranking(void);  // @ 0x00018ac4
void updateEngineProtectionRestartSeverityIndexes (engine_protection_channel_configuration_t *configuration, cm550_engine_protection_channel_state_t *state, engine_protection_channel_history_t *history);  // @ 0x00018c1c
void updateEngineProtectionRestartSeverity(void);  // @ 0x00018cb6
void cm550_updateEngineProtectionRestartLimitationCommands (ENGINE_PROTECTION_CHANNEL channel_index, cm550_engine_protection_channel_state_t *state, engine_protection_channel_configuration_t *configuration);  // @ 0x00018dae
void cm550_calculateFaultDerateEngineSpeedLimit(void);  // @ 0x00018e0c
void initializeFaultDerateEngineSpeedLimit(void);  // @ 0x00018f4c
void countEngineProtectionShutdownTime (engine_protection_channel_configuration_t *configuration, cm550_engine_protection_channel_state_t *state,word is_engine_speed);  // @ 0x00018f86
void cm550_updateEngineProtectionShutdown(void);  // @ 0x00018fcc
void cm550_initializeEngineProtectionShutdownCounting(void);  // @ 0x000192e0
word cm550_isEngineProtectionInputMoreExtreme (word input,word extreme_value,word configuration_flags);  // @ 0x000192f2
void cm550_recordEngineProtectionFaultLogEntry(word is_engine_speed);  // @ 0x00019332
void cm550_closeEngineProtectionFaultLogEntry(word is_engine_speed);  // @ 0x00019436
void logEngineProtectionChannelFaults(void);  // @ 0x0001952c
void applyFaultDerateFuelLimit(void);  // @ 0x000196e4
void cm550_calculateFaultDerateFuelLimit(void);  // @ 0x00019702
void cm550_resetFaultDerateFuelLimit(void);  // @ 0x00019960
word mc68k_initializeTpuChannel10PrimarySpeedInputMode0(void);  // @ 0x0001999c
void cm550_initializeSpeedMeasurementForConfiguration0(void);  // @ 0x00019ac2
void cm550_emptyEnginePositionSignalConfiguration0ThirdStep(void);  // @ 0x00019aca
void mc68k_tpuChannel10PrimarySpeedInterruptHandlerMode0(void);  // @ 0x00019acc
void mc68k_tpuChannel0InterruptHandlerMode0(void);  // @ 0x00019c88
word mc68k_initializeTpuChannel10PrimarySpeedInputMode1(void);  // @ 0x00019caa
void mc68k_initializeTpuChannel0MissingToothInput(void);  // @ 0x00019dd0
void cm550_emptyEnginePositionSignalConfiguration1ThirdStep(void);  // @ 0x00019e8e
void mc68k_tpuChannel10PrimarySpeedInterruptHandlerMode1(void);  // @ 0x00019e90
void mc68k_tpuChannel0MissingToothInterruptHandlerMode1(void);  // @ 0x00019f82
void cm550_checkEnginePositionSensorPhaseOnMainPeriod(void);  // @ 0x0001a1e0
void cm550_checkEnginePositionSensorPhaseOnBackupPeriod(void);  // @ 0x0001a298
void mc68k_initializeTpuChannel10PrimarySpeedInputMode2(void);  // @ 0x0001a350
void mc68k_initializeTpuChannel0MissingToothInputMode2(void);  // @ 0x0001a47c
void cm550_emptyEnginePositionSignalConfiguration2ThirdStep(void);  // @ 0x0001a52a
void mc68k_tpuChannel10PrimarySpeedInterruptHandlerMode2(void);  // @ 0x0001a52c
void mc68k_tpuChannel0MissingToothSyncErrorInterruptHandlerMode2(void);  // @ 0x0001a6e8
dword mc68k_initializeTpuChannel10PrimarySpeedInputIfEnabled(void);  // @ 0x0001a746
void cm550_initializeSpeedMeasurementForConfiguration3(void);  // @ 0x0001a89a
void cm550_emptyEnginePositionSignalConfiguration3ThirdStep(void);  // @ 0x0001a8a2
void mc68k_tpuChannel10PrimarySpeedInterruptHandlerMode3(void);  // @ 0x0001a8a4
dword cm550_processPrimarySpeedPulsePeriodWithSyncPulse(dword pulse_period,word edge_time_stamp);  // @ 0x0001a95a
uint cm550_updateElectronicSmartPowerTau(void);  // @ 0x0001abb2
void cm550_initializeElectronicSmartPower(void);  // @ 0x0001ade8
void mc68k_initializeTpuChannel1BackupSpeedInput(void);  // @ 0x0001ae22
void mc68k_tpuChannel1CylinderIdentificationPulseInterruptHandler(void);  // @ 0x0001af32
uint mc68k_initializeTpuChannel1BackupSpeedPeriodInput(void);  // @ 0x0001b1ea
void mc68k_tpuChannel1BackupSpeedPeriodInterruptHandler(void);  // @ 0x0001b30a
void mc68k_initializeTpuChannel1SpeedMeasurementResetInput(void);  // @ 0x0001b39a
void mc68k_tpuChannel1SpeedMeasurementResetInterruptHandler(void);  // @ 0x0001b4b2
void cm550_runEveryFrameTaskSet(void);  // @ 0x0001b4d0
void cm550_runEvery2FramesTaskSetPhase0(void);  // @ 0x0001b4d8
void cm550_runEvery2FramesTaskSetPhase1(void);  // @ 0x0001b504
void cm550_runEvery4FramesTaskSetPhase0(void);  // @ 0x0001b518
void cm550_runEvery4FramesTaskSetPhase1(void);  // @ 0x0001b572
void cm550_runEvery4FramesTaskSetPhase2(void);  // @ 0x0001b5ce
void cm550_runEvery4FramesTaskSetPhase3(void);  // @ 0x0001b612
void cm550_runEvery8FramesTaskSetPhase0(void);  // @ 0x0001b668
void cm550_runEvery8FramesTaskSetPhase1(void);  // @ 0x0001b66a
void cm550_runEvery8FramesTaskSetPhase2(void);  // @ 0x0001b678
void cm550_runEvery8FramesTaskSetPhase3(void);  // @ 0x0001b686
void cm550_runEvery8FramesTaskSetPhase4(void);  // @ 0x0001b694
void cm550_runEvery8FramesTaskSetPhase5(void);  // @ 0x0001b6a2
void cm550_runEvery8FramesTaskSetPhase6(void);  // @ 0x0001b6aa
void cm550_runEvery8FramesTaskSetPhase7(void);  // @ 0x0001b6b2
void cm550_runEvery10FramesTaskSetPhase0(void);  // @ 0x0001b6b4
void cm550_runEvery10FramesTaskSetPhase1(void);  // @ 0x0001b6c8
void cm550_runEvery10FramesTaskSetPhase2(void);  // @ 0x0001b6d6
void cm550_runEvery10FramesTaskSetPhase3(void);  // @ 0x0001b6e4
void cm550_runEvery10FramesTaskSetPhase4(void);  // @ 0x0001b6f2
void cm550_runEvery10FramesTaskSetPhase5(void);  // @ 0x0001b70c
void cm550_runEvery10FramesTaskSetPhase6(void);  // @ 0x0001b714
void cm550_runEvery10FramesTaskSetPhase7(void);  // @ 0x0001b722
void cm550_runEvery10FramesTaskSetPhase8(void);  // @ 0x0001b72a
void cm550_runEvery10FramesTaskSetPhase9(void);  // @ 0x0001b732
void cm550_runEvery20FramesTaskSetPhase0(void);  // @ 0x0001b73a
void cm550_runEvery20FramesTaskSetPhase1(void);  // @ 0x0001b754
void cm550_runEvery20FramesTaskSetPhase2(void);  // @ 0x0001b768
void cm550_runEvery20FramesTaskSetPhase3(void);  // @ 0x0001b788
void cm550_runEvery20FramesTaskSetPhase4(void);  // @ 0x0001b7a2
void cm550_runEvery20FramesTaskSetPhase5(void);  // @ 0x0001b7b0
void cm550_runEvery20FramesTaskSetPhase6(void);  // @ 0x0001b7ca
void cm550_runEvery20FramesTaskSetPhase7(void);  // @ 0x0001b7d2
void cm550_runEvery20FramesTaskSetPhase8(void);  // @ 0x0001b7e0
void cm550_runEvery20FramesTaskSetPhase9(void);  // @ 0x0001b7e2
void cm550_runEvery20FramesTaskSetPhase10(void);  // @ 0x0001b7ea
void cm550_runEvery20FramesTaskSetPhase11(void);  // @ 0x0001b7f2
void cm550_runEvery20FramesTaskSetPhase12(void);  // @ 0x0001b80c
void cm550_runEvery20FramesTaskSetPhase13(void);  // @ 0x0001b81a
void cm550_runEvery20FramesTaskSetPhase14(void);  // @ 0x0001b828
void cm550_runEvery20FramesTaskSetPhase15(void);  // @ 0x0001b836
void cm550_runEvery20FramesTaskSetPhase16(void);  // @ 0x0001b83e
void cm550_runEvery20FramesTaskSetPhase17(void);  // @ 0x0001b846
void cm550_runEvery20FramesTaskSetPhase18(void);  // @ 0x0001b85a
void cm550_runEvery20FramesTaskSetPhase19(void);  // @ 0x0001b862
undefined8 executiveFrameInterruptHandler(void);  // @ 0x0001b876
void mc68k_scheduler_init(void);  // @ 0x0001bf54
uint cm550_circularBufferPush(dword *buffer_control,byte data_byte);  // @ 0x0001bfa2
uint cm550_circularBufferPop(dword *buffer_control,byte *data_out);  // @ 0x0001bfde
void cm550_initializeCircularBuffer(dword *buffer_control,dword base_address,word buffer_size);  // @ 0x0001c016
void cm550_diagnosticFuelLimitInterpolator(void);  // @ 0x0001c03c
void cm550_convertTorqueDerateTorqueLimitToFuelLimit(void);  // @ 0x0001c0d4
void cm550_selectFinalFueling(void);  // @ 0x0001c152
void cm550_initializeTorqueDerateTorqueLimit(void);  // @ 0x0001c308
FLASH_ERASE_RESULT mc68k_flashEraseBlock(void);  // @ 0x0001c31a
FLASH_ERASE_RESULT cm550_flashEraseFromRam(dword block_address,dword suspend_check_disabled);  // @ 0x0001c484
undefined4 cm550_flashProgramAndVerifyWords(void);  // @ 0x0001c4ba
void cm550_flashProgramFromRam(dword destination_address,dword source_pointer,word byte_count);  // @ 0x0001c5e8
void selectFourDimensionalFuelingModeByDefault(void);  // @ 0x0001c630
void updateFourDimensionalFueling(void);  // @ 0x0001c640
uint cm550_fuelDemandTableBlendCalculator(void);  // @ 0x0001c65e
void cm550_initializeFourDimensionalInjectionTimingLookups(void);  // @ 0x0001c7a8
void cm550_setThrottle100J1939TorqueCurveSpeedPoints(void);  // @ 0x0001c824
ushort cm550_calculateThrottle100J1939TorqueCurveFuelings(void);  // @ 0x0001c8a0
void fuelDemandProportionalCalculationSlowCycle40Coordinator(void);  // @ 0x0001c9d2
ushort cm550_commandFuelShutoffDriver(void);  // @ 0x0001ca54
uint cm550_selectEngineProtectionFuelTemperature(void);  // @ 0x0001cad6
void cm550_initializeEngineProtectionFuelTemperature(void);  // @ 0x0001cb3c
void vp44_convertPumpFuelTemperatureToSensorScale(void);  // @ 0x0001cb48
word cm550_calculateBlendedTableValue(word fuel_table_x_input,word throttle_input);  // @ 0x0001cb76
void cm550_calculateThrottle100Fuelings(void);  // @ 0x0001cc72
void cm550_initializeThrottle100FuelingLookups(void);  // @ 0x0001cdf8
void initializeFuelLimitChains(void);  // @ 0x0001ce58
void runHighSpeedGovernorPid(void);  // @ 0x0001ce7c
void presetHighSpeedGovernorIntegrator(void);  // @ 0x0001d252
void initializeHighSpeedGovernorGainSet(void);  // @ 0x0001d2e4
uint selectHighSpeedGovernorGainSet(void);  // @ 0x0001d392
void selectEngineSpeedLimit(void);  // @ 0x0001d5a0
void initializeEngineSpeedLimitDefaults(void);  // @ 0x0001d94e
uint cm550_runIdleShutdownStateMachine(void);  // @ 0x0001d9b4
void cm550_initializeIdleShutdown(void);  // @ 0x0001db8a
void cm550_initializeInjectorFaultEngineSpeedLimit(void);  // @ 0x0001dbd8
void mc68k_main(void);  // @ 0x0001dbee
void cm550_initializeAlpha(void);  // @ 0x0001dcfc
void cm550_initializeDiagnosticBufferPointer(void);  // @ 0x0001dd2c
void initializeFourDimensionalFuelingAndFrictionFuelLookups(void);  // @ 0x0001ddb4
undefined4 cm550_calculateFourDimensionalFueling(void);  // @ 0x0001de58
void cm550_subtractAndClampValue(word *fuel_value_pointer);  // @ 0x0001e02a
void cm550_initializeFourDimensionalFuelingInterpolationFactor(void);  // @ 0x0001e04c
void handleJ1939CanTransmitInterrupt(word message_object_number);  // @ 0x0001e056
void cm550_handleJ1939CanReceiveInterrupt(word message_object_number);  // @ 0x0001e086
void cm550_transmitCanFrameOnMessageObject (dword controller_base,byte message_object_number,byte *frame);  // @ 0x0001e0bc
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
void cm550_initializeVectorTable(void);  // @ 0x0001e77a
byte cm550_insiteMultiFrameResponseBuilder(word first_frame_byte_count,word frame_byte_count);  // @ 0x0001e79a
void cm550_insiteMultiFrameContinuation(void);  // @ 0x0001e89e
void cm550_processJ1587ReceivedMessage(void);  // @ 0x0001e956
void cm550_responseBufferSpaceCheck(void);  // @ 0x0001eb88
void cm550_responseBufferFinalize(void);  // @ 0x0001ec08
void cm550_diagnosticMemoryWriteHandler(word service_id);  // @ 0x0001ec3c
void cm550_diagnosticMemoryReadHandler(word service_id);  // @ 0x0001edae
void cm550_diagnosticMessage45Builder(void);  // @ 0x0001f0de
void cm550_diagnosticMessage46Builder(void);  // @ 0x0001f2d0
tsc1_source_configuration_t * cm550_processJ1922EngineControlRequestFromSource74(void);  // @ 0x0001f4e8
void cm550_fuelDemandScaleFactorCalculator(void);  // @ 0x0001f84e
tsc1_source_configuration_t * cm550_engineFluidLevelDataBuilder(void);  // @ 0x0001f8bc
void cm550_extendedDiagnosticService51(void);  // @ 0x0001fbb0
void cm550_diagnosticMessage53Builder(void);  // @ 0x0001fbf4
void cm550_diagnosticMessage54Builder(void);  // @ 0x0001fc9c
uint cm550_clearExpiredJ1922ControlOccurrences(void);  // @ 0x0001fd6c
dword cm550_recordJ1922ControlOccurrence(word control_mode);  // @ 0x0001fdc0
void cm550_initializeCanMessageFilter(void);  // @ 0x0001fe40
byte scheduleJ1939PeriodicMessage (J1939_PERIODIC_TRANSMIT_QUEUE queue_index,word pgn_key,word interval_milliseconds, word first_send_offset_milliseconds,j1939_message_builder_function_t *builder);  // @ 0x0001fe84
uint cm550_runJ1939PeriodicTransmitQueues(void);  // @ 0x0001ff38
void cm550_emptyPlaceholderInitialization(void);  // @ 0x0001ffd0
byte handleJ1939NoOperationService(void);  // @ 0x0001ffd2
byte updateJ1939BroadcastEnableMask(can_standard_receive_descriptor_t *request,byte enable);  // @ 0x0001ffd6
byte handleJ1939DisableBroadcastService(can_standard_receive_descriptor_t *request);  // @ 0x000200a4
byte handleJ1939EnableBroadcastService(can_standard_receive_descriptor_t *request);  // @ 0x000200b4
void registerJ1939BroadcastAndNoOperationServices(void);  // @ 0x000200c6
void clearJ1939InputDataErrorBit(word bit_index);  // @ 0x000201d6
void clearJ1939PedalInputTimeoutBit(word bit_index);  // @ 0x00020210
void clearJ1939InputTimeoutBit(word bit_index);  // @ 0x0002024a
uint isAnyJ1939InputDataErrorActive(void);  // @ 0x00020284
uint isAnyJ1939PedalInputTimeoutActive(void);  // @ 0x000202a0
uint isAnyJ1939InputTimeoutActive(void);  // @ 0x000202bc
void setJ1939InputDataErrorBit(word bit_index);  // @ 0x000202d8
void setJ1939PedalInputTimeoutBit(word bit_index);  // @ 0x00020310
void setJ1939InputTimeoutBit(word bit_index);  // @ 0x00020348
uint cm550_processJ1939EngineRetarderSelection(void);  // @ 0x00020380
uint cm550_processJ1939EngineFanRequestedSpeed(void);  // @ 0x0002041c
dword cm550_processJ1939AcceleratorLowIdleSwitch(void);  // @ 0x000204b0
void mc68k_updateIdleSwitchesFromLocalInputs(void);  // @ 0x000205c4
uint cm550_copyOutputBitToSwitchOverrideValue(dword logical_input,dword output_number);  // @ 0x000206a8
uint cm550_processJ1939RemoteAcceleratorPedalPosition(void);  // @ 0x00020784
uint cm550_processJ1939SwitchInput(word input_index);  // @ 0x00020890
uint cm550_processJ1939AcceleratorPedalPosition(void);  // @ 0x00020c98
uint cm550_processJ1939AcceleratorIdleSwitchPair(void);  // @ 0x00020e14
uint cm550_processJ1939WetTankPressure(void);  // @ 0x00020fac
void cm550_processJ1939SwitchAndRequestInputs(void);  // @ 0x00021070
void cm550_processJ1939AcceleratorInputs(void);  // @ 0x00021146
void cm550_initializeJ1939InputProcessing(void);  // @ 0x000211f4
byte registerJ1939ReceiveHandler(word pgn_key,void *handler);  // @ 0x00021272
uint mc68k_dispatchJ1939ReceivedMessages(void);  // @ 0x000212b2
ushort endRetarderShiftAssistAboveFuelDemandLimit(void);  // @ 0x0002142c
byte writeJ1939DiagnosticMemory (can_standard_receive_descriptor_t *request,dword address,dword length);  // @ 0x0002148a
byte writeJ1939DiagnosticMemoryByParameterId (can_standard_receive_descriptor_t *request,word parameter_id,dword offset, dword length);  // @ 0x00021642
byte handleJ1939WriteByParameterIdService(can_standard_receive_descriptor_t *request);  // @ 0x0002167e
byte handleJ1939WriteByParameterIdLongLengthService(can_standard_receive_descriptor_t *request);  // @ 0x000216c6
byte handleJ1939WriteByParameterIdShortOffsetService(can_standard_receive_descriptor_t *request);  // @ 0x00021714
byte handleJ1939WriteByParameterIdLongOffsetService(can_standard_receive_descriptor_t *request);  // @ 0x00021778
byte handleJ1939WriteMemoryService(can_standard_receive_descriptor_t *request);  // @ 0x000217de
byte handleJ1939WriteMemoryLongLengthService(can_standard_receive_descriptor_t *request);  // @ 0x00021826
void registerJ1939MemoryWriteServices(void);  // @ 0x00021872
undefined4 byteSwap32(undefined4 *param_1);  // @ 0x000218ca
undefined2 byteSwap16(undefined2 *param_1);  // @ 0x000218fe
byte cm550_buildJ1939LampStatusByte(void);  // @ 0x00021920
byte getJ1939MemoryServiceHeaderLength(word service_id);  // @ 0x00021964
byte cm550_validateJ1939DiagnosticRequest(can_standard_receive_descriptor_t *request);  // @ 0x00021982
void receivePgn57344CabMessage1(int param_1);  // @ 0x00021a5c
void receivePgn61441ElectronicBrakeController1Message(int param_1);  // @ 0x00021a8c
void receivePgn61443ElectronicEngineController2Message(int param_1);  // @ 0x00021b88
void receivePgn65252ShutdownMessage(int param_1);  // @ 0x00021c3c
void receivePgn65264PowerTakeoffInformationMessage(int param_1);  // @ 0x00021c74
void receivePgn65265CruiseControlVehicleSpeedMessage(int param_1);  // @ 0x00021d44
void cm550_tickJ1939InputSupervision(void);  // @ 0x00021edc
void cm550_registerJ1939InputMessageHandlers(void);  // @ 0x00021ef6
void storeJ1939ControlSessionInHistoryTable(byte session_kind);  // @ 0x00021f4e
void startJ1939ControlSession(byte command_record_index);  // @ 0x00021fac
uint trackJ1939ControlSessions(void);  // @ 0x00022070
byte handleJ1939GetAddressByParameterIdService(can_standard_receive_descriptor_t *request);  // @ 0x000222b4
void registerJ1939GetAddressByParameterIdService(void);  // @ 0x00022370
byte readJ1939DiagnosticMemoryAndRespond (can_standard_receive_descriptor_t *request,dword address,dword length);  // @ 0x0002238e
byte readJ1939DiagnosticMemoryByParameterId (can_standard_receive_descriptor_t *request,word parameter_id,dword offset, dword length);  // @ 0x000224f4
byte handleJ1939ReadByParameterIdLongLengthService(can_standard_receive_descriptor_t *request);  // @ 0x00022530
byte handleJ1939ReadByParameterIdShortOffsetService(can_standard_receive_descriptor_t *request);  // @ 0x0002257c
byte handleJ1939ReadByParameterIdLongOffsetService(can_standard_receive_descriptor_t *request);  // @ 0x000225e0
byte handleJ1939ReadMemoryService(can_standard_receive_descriptor_t *request);  // @ 0x00022646
byte handleJ1939ReadMemoryLongLengthService(can_standard_receive_descriptor_t *request);  // @ 0x0002268e
void registerJ1939MemoryReadServices(void);  // @ 0x000226da
void cm550_startJ1939TransportSession(j1939_transmit_message_t *message);  // @ 0x00022726
void handleJ1939TransportClearToSend(can_standard_receive_descriptor_t *message);  // @ 0x00022956
void sendJ1939TransportAbort(byte destination_address,word pgn);  // @ 0x000229ea
void sendJ1939TransportEndOfMessageAcknowledge(byte destination_address,word pgn);  // @ 0x00022a58
byte sendJ1939TransportClearToSend (byte destination_address,byte next_packet_number,byte packet_count,word pgn);  // @ 0x00022ad8
void handleJ1939TransportRequestToSend(can_standard_receive_descriptor_t *message);  // @ 0x00022b50
void handleJ1939TransportDataPacket(can_standard_receive_descriptor_t *message);  // @ 0x00022c26
void handleJ1939TransportEndOfMessageAcknowledge(can_standard_receive_descriptor_t *message);  // @ 0x00022d8e
void handleJ1939TransportAbort(can_standard_receive_descriptor_t *message);  // @ 0x00022de2
void dispatchJ1939TransportConnectionManagement(can_standard_receive_descriptor_t *message);  // @ 0x00022e5e
void cm550_sendJ1939BroadcastDataPacket(word session_index);  // @ 0x00022ece
void sendJ1939ConnectionModeDataPackets(void);  // @ 0x00022fae
void tickJ1939TransportReceiveTimeout(void);  // @ 0x000230d6
void serviceJ1939TransportSessions(void);  // @ 0x000230ee
j1939_transmit_message_t * selectJ1939TransmitBuffer(word data_length);  // @ 0x00023130
void initializeJ1939Transport(void);  // @ 0x00023186
void cm550_resetEngineTsc1Request(void);  // @ 0x000231da
void resetEngineRetarderTsc1Request(void);  // @ 0x00023216
uint cm550_runJ1939PowertrainControlTimeouts(void);  // @ 0x00023244
word refreshEngineTsc1IgnoredRequestEntry (word network_type,word source_address,word override_control_mode);  // @ 0x00023820
word cm550_refreshRetarderTsc1IgnoredRequestEntry(word source_address);  // @ 0x00023870
void cm550_addEngineTsc1IgnoredRequestEntry (word network_type,byte source_address,word override_control_mode);  // @ 0x000238ac
void cm550_addRetarderTsc1IgnoredRequestEntry(byte source_address);  // @ 0x000238ec
void cm550_processTsc1IgnoredRequestTimeouts(void);  // @ 0x00023920
void removeEngineTsc1IgnoredRequestEntry(word network_type,word source_address);  // @ 0x000239d2
void cm550_removeRetarderTsc1IgnoredRequestEntry(word source_address);  // @ 0x00023a3c
ushort cm550_applyLampRequestsToOutputs(void);  // @ 0x00023a90
void cm550_checkLampDriverOutputFaults(void);  // @ 0x00023be8
void cm550_updateLampOutputsAndCheckLampDriverFaults(void);  // @ 0x00024804
void cm550_iahDisableWaitToStartLamp(void);  // @ 0x00024812
void cm550_startPowerUpLampSequence(void);  // @ 0x0002482e
void cm550_runPowerUpLampSequence(void);  // @ 0x00024858
uint cm550_runStopLampFlashCycle(void);  // @ 0x000249b6
undefined1 cm550_flashShutdownWarningLamps(void);  // @ 0x000249ee
uint cm550_flashFaultCodeDigits(word fault_code);  // @ 0x00024b4e
byte cm550_selectNextFaultToFlash(byte current_fault_index);  // @ 0x00024c5a
byte cm550_selectPreviousFaultToFlash(byte current_fault_index);  // @ 0x00024cd2
int cm550_runFaultCodeFlashOut(void);  // @ 0x00024d40
void cm550_updateActiveFaultLamps(void);  // @ 0x00024f30
void cm550_flashEngineProtectionLampForOilChangeDueAtPowerUp(void);  // @ 0x00025316
void cm550_flashWarningLampForOilChangeMonitorReset(void);  // @ 0x000253b0
void cm550_flashEngineProtectionLampForOilChangeDueWhileRunning(void);  // @ 0x00025448
void cm550_runLampControl(void);  // @ 0x000254b6
void cm550_clearSystemErrorStatus(void);  // @ 0x00025594
void cm550_calculatePedalFaultModeFuelDemand(void);  // @ 0x0002571e
void cm550_selectPedalFaultMode(word previous_user_fueling_state);  // @ 0x00025806
void presetPedalFaultModeFuelDemand(void);  // @ 0x000258b0
void initializePedalFaultModeEngineSpeedFilter(void);  // @ 0x000258d6
void cm550_calculateEngineProtectionOilPressureLimits(void);  // @ 0x000258e8
void cm550_initializeEngineProtectionOilPressureLimitLookups(void);  // @ 0x00025926
void cm550_calculateLowSpeedGovernorReferenceMaximumFuelQuantity(void);  // @ 0x0002595a
void cm550_presetLowSpeedGovernorIntegrator(void);  // @ 0x00025a34
void cm550_runLowSpeedGovernor(void);  // @ 0x00025b1c
void cm550_presetLowSpeedGovernorSpeedError(void);  // @ 0x00025ff2
void cm550_initializeLowSpeedGovernor(void);  // @ 0x00026078
void cm550_updateLowSpeedGovernorAggressiveGainLogic(void);  // @ 0x0002609c
void cm550_resetLowSpeedGovernorSettledCounts(void);  // @ 0x00026252
void cm550_clearLowSpeedGovernorAggressiveGainsUsedFlag(void);  // @ 0x0002626a
word selectLowSpeedGovernorOverrideGainSet(word gain_set_already_selected);  // @ 0x00026272
void cm550_loadLowSpeedGovernorGainSet(void);  // @ 0x0002629e
void cm550_resetLowSpeedGovernorGainLogic(void);  // @ 0x000262fa
void cm550_initializeLowSpeedGovernorGainSelection(void);  // @ 0x00026308
void cm550_selectLowSpeedGovernorGearGainSet(void);  // @ 0x00026340
void cm550_resetLowSpeedGovernorGearGainLogic(void);  // @ 0x00026462
void cm550_updateLowSpeedGovernorIdleAdjustment(void);  // @ 0x00026474
void cm550_initializeLowSpeedGovernorIdleAdjustment(void);  // @ 0x0002658c
word selectLowSpeedGovernorTsc1GainSet(void);  // @ 0x000265e6
void cm550_calculateLowSpeedGovernorColdIdleSpeed(void);  // @ 0x00026616
void cm550_updateLowSpeedGovernorIdleAdjustmentWrapper(void);  // @ 0x000266d2
uint mc68k_runSerialEepromDriverStep(void);  // @ 0x000266da
undefined8 mc68k_serialEepromQspiInterruptHandler(void);  // @ 0x00026834
void cm550_emptySerialEepromDriverInitializationFirstStep(void);  // @ 0x00026852
void mc68k_initializeSerialEepromDriverAndLoadMirror(void);  // @ 0x00026854
void cm550_calculateMaximumTorqueAtCurrentEngineSpeed(void);  // @ 0x000269f2
void cm550_initializeMaximumTorqueAtCurrentEngineSpeed(void);  // @ 0x00026a2e
void cm550_memcpy(byte *destination,byte *source,word byte_count);  // @ 0x00026a64
void cm550_initializeInjectionTimingMisfireLimit(void);  // @ 0x00026a7e
word cm550_calculateInjectionTimingMisfireLimit(void);  // @ 0x00026ab8
ushort cm550_applyMisfireTimingLimit(void);  // @ 0x00026af0
void cm550_calculateNoLoadFuel(void);  // @ 0x00026b3a
void cm550_emptyStartupStepAfterLowSpeedGovernorIdleAdjustment(void);  // @ 0x00026b82
void hpcr_injectorPulseWidthCalculation(void);  // @ 0x00026b88
ushort mc68k_initializePwmOutput(void);  // @ 0x00026c7e
void cm550_calculateEngineLoadPercentages(void);  // @ 0x00026cc8
void cm550_calculateEngineLoadLowHorsepowerCurvePercent(void);  // @ 0x00026e2c
void cm550_initializeEnginePositionPhaseLag(void);  // @ 0x00026e86
void cm550_calculateEnginePositionPhaseLag(void);  // @ 0x00026e8e
void cm550_insiteActiveFaultListBuilder(void);  // @ 0x00026eec
void cm550_insiteFaultDetailBuilder(void);  // @ 0x00026fea
void cm550_insiteVersionInformationBuilder(void);  // @ 0x0002758e
void cm550_insiteCapacityResponseBuilder(void);  // @ 0x00027706
void cm550_buildJ1587Pid243ComponentIdentificationReply(void);  // @ 0x000277e6
void vp44_hourMeterEventLogger(void);  // @ 0x00027998
void restartOnKeyOnDuringPowerDown(void);  // @ 0x00027af0
void mc68k_saveEepromForPowerDown(void);  // @ 0x00027c20
void cm550_savePowerDownDataToFlashBank(byte flash_bank_number);  // @ 0x00027cd0
void mc68k_runPowerDownSequence(void);  // @ 0x00027f9c
void mc68k_applicationMain(void);  // @ 0x000284e8
void cm550_restartApplicationWithoutReset(void);  // @ 0x00028978
void mc68k_initializeDualCanController(void);  // @ 0x00028a04
void mc68k_initializeJ1939Datalink(void);  // @ 0x00028b80
word mc68k_initializeJ1708Datalink(void);  // @ 0x00029130
void cm550_updateBootBlockFromImage(void);  // @ 0x0002ce64
void cm550_FUN_0002cf52(byte *source,word byte_count);  // @ 0x0002cf52
byte cm550_applyJ1708MemoryWriteRecords(word write_record_count);  // @ 0x0002cf7e
void cm550_systemControl64(void);  // @ 0x0002d09e
void cm550_systemControl74(void);  // @ 0x0002d1c2
void cm550_systemControl75(void);  // @ 0x0002d1e0
void cm550_initializeMemoryPatchBuffer(void);  // @ 0x0002d1fe
uint cm550_memoryPatchingSystem(void);  // @ 0x0002d216
void cm550_runPowerTakeOffGovernor(void);  // @ 0x0002d3c6
void applyPowerTakeOffTorqueLimit(void);  // @ 0x0002d9a8
void cm550_presetPowerTakeOffGovernorOnEngagement(void);  // @ 0x0002d9d2
void initializePowerTakeOffGovernorFiltersAndGains(void);  // @ 0x0002db2a
void smoothPowerTakeOffReferenceEngineSpeed(void);  // @ 0x0002dbde
void presetPowerTakeOffSmoothedReferenceEngineSpeed(void);  // @ 0x0002dc8c
void initializePowerTakeOffReferenceFilter(void);  // @ 0x0002dc9e
void cm550_selectPowerTakeOffOrUserFueling(void);  // @ 0x0002dcb0
void initializePowerTakeOffThrottleOverride(void);  // @ 0x0002ddbc
void mc68k_initializeHardwareTimerFlags(void);  // @ 0x0002ddce
uint mc68k_monitorPwmOutputReadBackFaults(void);  // @ 0x0002dde8
ulonglong mc68k_stepPwm3AndPwm4OutputStartUpTest(void);  // @ 0x0002e2f4
undefined8 mc68k_pwmFuelDemandOutputCalculator(void);  // @ 0x0002e5c0
void initializeQadcModule(void);  // @ 0x0002e95e
void clearWorkingRam(void);  // @ 0x0002e9ac
void cm550_initializeRamRefresh(void);  // @ 0x0002e9f8
void cm550_refreshRamCalibration(void);  // @ 0x0002eadc
void cm550_claimRemoteThrottleOverride(void);  // @ 0x0002ec50
void cm550_initializeRemoteThrottle(void);  // @ 0x0002ed62
byte cm550_getJ1587ReceivedParameterLength(void);  // @ 0x0002ed6a
byte cm550_getJ1587ReplyParameterLength(void);  // @ 0x0002edb2
byte registerJ1939DiagnosticService (J1939_DIAGNOSTIC_SERVICE service_id, j1939_diagnostic_service_handler_function_t *handler);  // @ 0x0002ee62
void cm550_dispatchJ1939DiagnosticServiceRequest(can_standard_receive_descriptor_t *request);  // @ 0x0002eea2
void registerJ1939DiagnosticServiceDispatcher(void);  // @ 0x0002ef08
void cm550_j1939HandlePgn65228Dm3ClearInactiveFaults (can_standard_receive_descriptor_t *request_message);  // @ 0x0002ef1c
void registerJ1939Dm3RequestHandler(void);  // @ 0x0002ef36
void cm550_receivePgn58112Dm7CommandNonContinuouslyMonitoredTestMessage (can_standard_receive_descriptor_t *request_message);  // @ 0x0002ef4a
void registerJ1939Dm7Handler(void);  // @ 0x0002efbc
word cm550_receivePgn61442ElectronicTransmissionController1Message(int param_1);  // @ 0x0002efd0
void cm550_registerJ1939ElectronicTransmissionController1Handler(void);  // @ 0x0002f114
void processEngineTsc1Request(int param_1);  // @ 0x0002f128
byte registerJ1939PgnRequestHandler(word pgn,j1939_pgn_request_handler_function_t *handler);  // @ 0x0002f47e
void cm550_dispatchJ1939PgnRequest(can_standard_receive_descriptor_t *received_message);  // @ 0x0002f4be
void cm550_registerJ1939PgnRequestHandlers(void);  // @ 0x0002f538
word decodeRetarderTorqueRequestPercent(word requested_torque);  // @ 0x0002f606
void selectEngineRetarderStagePercent(void);  // @ 0x0002f632
void cm550_processEngineRetarderTsc1Request(int param_1);  // @ 0x0002f7e6
void cm550_initializeEngineRetarderTsc1RequestState(void);  // @ 0x0002faa4
void dispatchTsc1ByDestinationAddress(can_standard_receive_descriptor_t *message);  // @ 0x0002fb70
void registerTsc1DestinationAddressDispatcher(void);  // @ 0x0002fbb2
void unscrambleSecurityKey(byte *input_buffer,byte *output_buffer);  // @ 0x0002fbd8
byte validateSecurityKey(byte *authentication_payload_pointer);  // @ 0x0002fcdc
void cm550_releaseFaultFreezeFrameEntry(word code_index);  // @ 0x0002fd90
void cm550_resetFaultStatus(word code_index);  // @ 0x0002fddc
void cm550_captureFaultFreezeFrame(word snapshot_slot,word code_index);  // @ 0x0002fe38
undefined8 mc68k_j1708BusTimerInterruptHandler(void);  // @ 0x000300d4
void mc68k_engineSpeedIsrRegister(void);  // @ 0x00030274
void mc68k_engineRpmHardwareTimerSetup(void);  // @ 0x00030290
void mc68k_initializeTpuChannel12(void);  // @ 0x00030342
void cm550_emptyInitializationPlaceholder(void);  // @ 0x000303d2
undefined4 cm550_accumulatorWithOverflowCarry(uint *param_1,uint *param_2);  // @ 0x000303d4
void cm550_runTimeCountersUpdate(void);  // @ 0x00030414
void cm550_runTimeCountersUpdateAlt(void);  // @ 0x00030454
byte cm550_countEngineBrakeTime(void);  // @ 0x00030498
void cm550_rpmHistogramAndAveragingStatistics(void);  // @ 0x000304f4
uint cm550_updateTripInformation(void);  // @ 0x000306ca
ushort cm550_flagTripInformationPowerDownDataLoss(void);  // @ 0x00030a5e
void cm550_initializeTripInformation(void);  // @ 0x00030ade
void cm550_emptyInterruptHandler(void);  // @ 0x00030b04
void cm550_emptyStartupStepAfterSchedulerInitialization(void);  // @ 0x00030b0e
void cm550_applyMaximumTimingAdvanceLimit(void);  // @ 0x00030b10
void cm550_runInjectionTimingModificationChain(void);  // @ 0x00030b34
ushort vp44InjectionSystemStateController(void);  // @ 0x00030b62
void applyFuelSystemDerateFuelLimit(void);  // @ 0x00030bf6
void applyTsc1TorqueLimit(void);  // @ 0x00030c14
void cm550_runFuelLimitChains(void);  // @ 0x00030c3c
void cm550_initializeMasterSubsystem(void);  // @ 0x00030c78
void mc68k_loadTpuMicrocode(void);  // @ 0x00031428
ushort cm550_evaluateTrendingTriggers(void);  // @ 0x00031496
void cm550_runTrendingIntervalAndStoreSamples(void);  // @ 0x000315be
ushort cm550_restartTrendingAfterEngineRebuild(void);  // @ 0x00031a68
word findTsc1SourceConfiguration(word data_link,word source_address);  // @ 0x00031ace
void cm550_sendPgn59392AcknowledgementMessage (can_standard_receive_descriptor_t *request,word acknowledgement_type);  // @ 0x00031b22
void cm550_initializePgn59392AcknowledgementBuffer(void);  // @ 0x00031b96
void cm550_buildPgn65269AmbientConditionsMessage(void);  // @ 0x00031bce
void cm550_initializePgn65269AmbientConditionsBuffer(void);  // @ 0x00031c1a
void cm550_buildPgn65265CruiseControlVehicleSpeedMessage(void);  // @ 0x00031c84
void cm550_initializePgn65265CruiseControlVehicleSpeedHandler(void);  // @ 0x00031ed2
void cm550_buildPgn65261CruiseControlVehicleSpeedSetupMessage(void);  // @ 0x00031f30
void initializePgn65261CruiseControlSetupStruct(void);  // @ 0x00031fee
void cm550_buildPgn65259ComponentIdentificationMessage(void);  // @ 0x00032052
void cm550_initializePgn65259ComponentIdentificationHandler(void);  // @ 0x000320f6
void sendJ1939DiagnosticResponsePending(can_standard_receive_descriptor_t *request,word wait_time);  // @ 0x0003214c
void sendJ1939DiagnosticServiceResponse(can_standard_receive_descriptor_t *request,byte result_code);  // @ 0x0003216a
void buildPgn65234Dm10TestIdentifiersSupportMessage(void);  // @ 0x00032222
void initializePgn65234Dm10Handler(void);  // @ 0x00032244
void cm550_broadcastPgn65226Dm1WhileFaultsActive(void);  // @ 0x0003229a
void cm550_buildPgn65226Dm1ActiveDiagnosticTroubleCodesMessage(void);  // @ 0x000322ae
void cm550_initializePgn65226Dm1Handler(void);  // @ 0x000323be
void cm550_buildPgn65227Dm2PreviouslyActiveDiagnosticTroubleCodesMessage(void);  // @ 0x0003241c
void initializePgn65227Dm2Handler(void);  // @ 0x0003252c
void cm550_j1939HandlePgn65229Dm4FreezeFrame(void);  // @ 0x0003258a
void cm550_initializePgn65229Dm4Handler(void);  // @ 0x000329d2
void buildPgn65230Dm5DiagnosticReadiness1Message(void);  // @ 0x00032a42
void initializePgn65230Dm5Handler(void);  // @ 0x00032ae2
void sendPgn65232NonContinuousMonitorTestResultMessage(byte test_identifier,word test_value);  // @ 0x00032b38
void initializePgn65232Dm8Buffer(void);  // @ 0x00032b64
void cm550_buildPgn61441ElectronicBrakeController1Message(void);  // @ 0x00032bbc
void cm550_initializePgn61441ElectronicBrakeController1Buffer(void);  // @ 0x00032c22
void sendPgn61444ElectronicEngineController1Message(void);  // @ 0x00032c76
void initializePgn61444ElectronicEngineController1Buffer(void);  // @ 0x00032e08
void cm550_buildPgn61443ElectronicEngineController2Message(void);  // @ 0x00032e4c
void initializePgn61443ElectronicEngineController2Handler(void);  // @ 0x00033064
void buildPgn65247ElectronicEngineController3Message(void);  // @ 0x000330c4
void initializePgn65247ElectronicEngineController3Buffer(void);  // @ 0x00033120
void cm550_buildPgn65263EngineFluidLevelPressure1Message(void);  // @ 0x00033164
void cm550_initializePgn65263EngineFluidLevelPressure1Buffer(void);  // @ 0x000331ae
void buildPgn65251EngineConfiguration1Payload(undefined4 *param_1);  // @ 0x0003320e
byte cm550_hasWordIncreasedOrDroppedToZero(word previous_value,word current_value);  // @ 0x000333d6
byte cm550_hasByteIncreasedOrDroppedToZero(word previous_value,word current_value);  // @ 0x00033460
void sendPgn65251EngineConfiguration1OnChange(void);  // @ 0x000334ec
void sendPgn65251EngineConfiguration1Message(void);  // @ 0x0003366a
void initializePgn65251EngineConfiguration1Buffer(void);  // @ 0x00033692
void cm550_buildPgn65253EngineHoursRevolutionsMessage(void);  // @ 0x00033716
void cm550_initializePgn65253EngineHoursRevolutionsHandler(void);  // @ 0x00033754
void cm550_buildPgn65262EngineTemperature1Message(void);  // @ 0x000337c4
void initializePgn65262EngineTemperature1Handler(void);  // @ 0x00033880
void cm550_buildPgn61440ElectronicRetarderController1Message(void);  // @ 0x000338ea
void initializePgn61440ElectronicRetarderController1Buffer(void);  // @ 0x000339b0
void cm550_buildPgn65213FanDrive1Message(void);  // @ 0x000339fe
void initializePgn65213FanDrive1Buffer(void);  // @ 0x00033a1e
void cm550_buildPgn65257FuelConsumptionMessage(void);  // @ 0x00033a62
void cm550_initializePgn65257FuelConsumptionHandler(void);  // @ 0x00033aea
void cm550_buildPgn65266FuelEconomyLiquidMessage(void);  // @ 0x00033b40
void cm550_initializePgn65266FuelEconomyLiquidBuffer(void);  // @ 0x00033c28
void cm550_buildPgn65244IdleOperationMessage(void);  // @ 0x00033c6c
void cm550_initializePgn65244IdleOperationHandler(void);  // @ 0x00033ce2
void cm550_buildPgn65252ShutdownMessage(void);  // @ 0x00033d38
void cm550_initializePgn65252ShutdownBuffer(void);  // @ 0x00033dfa
void cm550_buildPgn65270InletExhaustConditions1Message(void);  // @ 0x00033e58
void initializePgn65270InletExhaustConditions1Buffer(void);  // @ 0x00033eee
void cm550_buildPgn65264PowerTakeOffInformationMessage(void);  // @ 0x00033f5a
void initializePgn65264PowerTakeOffInformationBuffer(void);  // @ 0x0003401a
void cm550_buildPgn65249RetarderConfigurationMessage(void);  // @ 0x0003407a
void cm550_initializePgn65249RetarderConfigurationBuffer(void);  // @ 0x000341e6
void cm550_buildPgn65248VehicleDistanceMessage(void);  // @ 0x00034232
void initializePgn65248VehicleDistanceHandler(void);  // @ 0x0003429a
void buildPgn65271VehicleElectricalPower1Message(void);  // @ 0x000342f0
void initializePgn65271VehicleElectricalPower1Buffer(void);  // @ 0x00034334
void cm550_buildPgn65255VehicleHoursMessage(void);  // @ 0x00034394
void cm550_initializePgn65255VehicleHoursHandler(void);  // @ 0x000343d2
void sendPgn65260VehicleIdentificationMessage(void);  // @ 0x00034430
void cm550_initializePgn65260VehicleIdentificationHandler(void);  // @ 0x00034440
void cm550_sendPgn65279WaterInFuelIndicatorMessage(void);  // @ 0x00034496
void cm550_initializePgn65279WaterInFuelIndicatorBuffer(void);  // @ 0x000344ce
void advanceHourMeters(void);  // @ 0x00034512
void loadHourMetersFromEeprom(void);  // @ 0x0003452a
void selectTsc1TorqueControlMode(void);  // @ 0x00034540
void selectUserCommandedFueling(void);  // @ 0x00034564
void selectUserFuelingState(void);  // @ 0x0003458c
void cm550_initializeMultiSystemParameters(void);  // @ 0x000345c8
MEMORY_REGION_TYPE lookupApplicationMemoryRegionType(dword range_start,word range_length);  // @ 0x0003460e
void mc68k_initializeSpeedMeasurementMode0(void);  // @ 0x00034674
void mc68k_resetSpeedMeasurementMode0(void);  // @ 0x0003478c
uint mc68k_setUpTpuChannel3AnglePulseOutput(void);  // @ 0x0003480e
uint mc68k_updateTpuChannel3AnglePulseOutput(void);  // @ 0x0003494a
void mc68k_configureTpuChannelsForSpeedMeasurementMode(void);  // @ 0x00034a82
void mc68k_alignCylinderIndexToCrankRevolution(void);  // @ 0x00034b20
void mc68k_delayTimeBaseTicksWithWatchdogService(word tick_count);  // @ 0x00034bba
void mc68k_delayTimeBaseTicksWithWatchdogService2(word tick_count);  // @ 0x00034bf8
ushort vp44FaultRegisterBit2Monitor(void);  // @ 0x00034c36
void vp44_liftPumpFuelDeliveryController(void);  // @ 0x00034cc4
void cm550_calculateWetStackTimingAdvance(void);  // @ 0x00034d52
void cm550_applyWetStackTimingAdvance(void);  // @ 0x00034dba
word cm550_lookupTableInterpolation(table_lookup_1d_arguments_t *arguments);  // @ 0x00034de0
word cm550_signedFirstOrderFilter(word new_sample,ema_filter_state_t *filter_state);  // @ 0x00034e9a
word cm550_secondOrderFilter(word input,second_order_filter_state_t *filter);  // @ 0x00034f00
word cm550_exponentialMovingAverage(word new_sample,ema_filter_state_t *filter_state);  // @ 0x00034f8a
word cm550_secondOrderFilterUnsigned(word input,second_order_filter_state_t *filter);  // @ 0x00034fe0
undefined4 cm550_scaleByRatio(dword multiplicand,dword multiplier,dword divisor);  // @ 0x00035064
undefined4 cm550_scaleByRatioSigned(dword multiplicand,dword multiplier,dword divisor);  // @ 0x00035076
word cm550_tableLookup2D(table_lookup_2d_arguments_t *lookup);  // @ 0x00035088
