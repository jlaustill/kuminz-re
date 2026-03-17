#pragma once
#include "firmware_types.hpp"

// Function Forward Declarations (from decompiled output)

void mpc555_reset_vector(void);  // @ 0x00000100
void mpc555_keyOnStateMachine(void);  // @ 0x00000184
void cm848_copyCalibrationToRam(void);  // @ 0x00000340
void cm848_registerStandardDiagServices(void);  // @ 0x0000037c
void cm848_eepromProgressNotify(undefined4 param_1,int param_2,undefined4 param_3);  // @ 0x000003ec
void mpc555_loadEepromCalibration(undefined4 param_1,int param_2);  // @ 0x00000428
undefined4 cm848_diagServiceDownloadCalibration(undefined4 param_1);  // @ 0x000008d4
short mpc555_initEepromTransfer(int param_1);  // @ 0x000008fc
undefined4 mpc555_diagServiceInitEepromTransfer(undefined4 param_1);  // @ 0x000009e4
uint cm848_computeCrcCcitt(undefined4 *param_1,uint param_2);  // @ 0x00000a40
void mpc555_updateCapabilityFlags(void);  // @ 0x00000b44
void cm848_stubFunction1(void);  // @ 0x00000be8
void mpc555_eepromWriteWords(dword dest_address,word *src_ptr,word word_count);  // @ 0x00000bec
void mpc555_eepromReadWords(short param_1,undefined2 *param_2,uint param_3);  // @ 0x00000d88
void cm848_mainLoopIteration(void);  // @ 0x00000e90
void cm848_loadCalibrationFromEeprom(void);  // @ 0x00000ec0
void cm848_loadVersionConfigFromEeprom(void);  // @ 0x00000f74
void mpc555_bootStateMachine(void);  // @ 0x00001008
void cm848_generateCrcTable(void);  // @ 0x000010ac
bool cm848_flashPollUntilReady(uint param_1,ushort *param_2,uint param_3);  // @ 0x00001110
short cm848_flashEraseChip(void);  // @ 0x000011b4
undefined2 cm848_flashWriteWord(undefined2 *param_1,undefined2 *param_2);  // @ 0x000012a8
undefined4 cm848_flashWriteBlock(int param_1,int param_2,uint param_3);  // @ 0x00001338
void mpc555_initHardwareConfig(void);  // @ 0x00001454
void mpc555_initSystemRegisters(void);  // @ 0x000016d0
void cm848_stubFunction2(void);  // @ 0x0000183c
char mpc555_diagService25_executeFunction(int param_1);  // @ 0x00001840
void cm848_initService25Handler(void);  // @ 0x0000191c
bool cm848_registerPgnResponseHandler(dword pgn,void *handler_func);  // @ 0x00001948
void cm848_initDataBasedDiagServices(void);  // @ 0x0000198c
undefined4 cm848_diagService65_handler(byte *param_1);  // @ 0x000019e8
void cm848_registerService65Handler(void);  // @ 0x00001ad0
void cm848_registerMemoryReadServices(void);  // @ 0x00001afc
char cm848_diagMemoryReadHandler(dword address,word length,byte *response_ptr);  // @ 0x00001b48
undefined1 cm848_diagMemoryReadWithBaseOffset(dword param_1,undefined4 param_2,short param_3,byte *param_4);  // @ 0x00001cf8
undefined1 cm848_diagService67_memoryReadOffset(int param_1);  // @ 0x00001d5c
undefined1 cm848_diagService74_memoryRead(dword param_1);  // @ 0x00001dc4
undefined1 cm848_diagService76_memoryReadExt(dword param_1);  // @ 0x00001e30
void mpc555_initDiagResponseHandlers(void);  // @ 0x00001e94
void cm848_diagSendResponseCode(undefined1 param_1,int param_2);  // @ 0x00001ef8
void mpc555_processDiagnosticAndEepromRequests(void);  // @ 0x00001fa4
void cm848_initDiagnosticCallback(void);  // @ 0x00002148
void cm848_processDiagnosticTimeout(void);  // @ 0x00002170
void cm848_setDataTransferMode(void);  // @ 0x000021c0
void mpc555_initDiagnosticSession(void);  // @ 0x000021d0
void mpc555_eepromValidationCycle(void);  // @ 0x00002310
void cm848_busWaitCycles(int param_1);  // @ 0x00002384
bool mpc555_checkBusHardwareStatus(void);  // @ 0x000023b8
void cm848_waitForBusStable(void);  // @ 0x000024a0
void mpc555_systemInitialization(void);  // @ 0x00002504
void mpc555_hardwareInitialization(void);  // @ 0x00002694
void mpc555_initCanController(void);  // @ 0x00002970
void mpc555_initDiagnosticSubsystem(void);  // @ 0x00002a40
void cm848_clearRamRegions(void);  // @ 0x00002b7c
void cm848_softReset(void);  // @ 0x00002bc8
bool cm848_registerDiagnosticService(undefined1 param_1,undefined4 param_2);  // @ 0x00002c94
void cm848_registerPgnEf00Handler(byte sub_id,void *handler_func);  // @ 0x00002cd8
undefined4 * cm848_lookupEepromParameterAddress(byte param_1);  // @ 0x00002d08
void cm848_handleEepromDiagnosticCallback(void);  // @ 0x00002de4
void cm848_registerSchedulerTask(void);  // @ 0x00002e58
void cm848_initSchedulerCallback(void);  // @ 0x00002ee8
void mpc555_initSchedulerTaskTable(void);  // @ 0x00002f18
void mpc555_spiReceiveHandler(void);  // @ 0x00002f74
void mpc555_spiTransmitCompleteHandler(void);  // @ 0x00003008
void mpc555_dispatchSpiHandlerByState(void);  // @ 0x000030ec
void cm848_resetEepromStatusPointer(void);  // @ 0x000031a0
void mpc555_enableSystemInterrupts(void);  // @ 0x000031c0
void mpc555_enableSpiTransmitInterrupt(void);  // @ 0x00003218
void cm848_initDiagnosticResponseCallback(void);  // @ 0x0000323c
void cm848_processDiagnosticResponseCallback(void);  // @ 0x0000326c
void mpc555_generateSerialChecksumResponse(void);  // @ 0x000032dc
void cm848_initDiagnosticRequestHandler(void);  // @ 0x000033a4
void cm848_decrementDiagnosticTimeout(void);  // @ 0x000033e0
void cm848_processDiagnosticRequest(void);  // @ 0x00003408
void cm848_initDiagnosticSessionHandler(void);  // @ 0x000035e4
void cm848_processDiagnosticSessionFlags(void);  // @ 0x00003614
void cm848_sendDiagnosticResponse(void);  // @ 0x0000368c
void cm848_resetEepromCalibrationState(void);  // @ 0x000036f8
void cm848_beginEepromCalibrationWrite(void);  // @ 0x00003710
void cm848_updateEepromMagicAndReload(void);  // @ 0x000037e0
void cm848_diagRequestTypeDispatcher(byte service_code,byte *request_ptr);  // @ 0x000038f4
void mpc555_diagServiceTransferBlock(void);  // @ 0x00003948
void cm848_computeSerialChecksum(void);  // @ 0x00003a5c
void cm848_restoreDiagnosticHandler(void);  // @ 0x00003ad8
void cm848_enableDiagnosticTimer(void);  // @ 0x00003b38
void cm848_processTimerInterrupt(void);  // @ 0x00003b48
void cm848_saveSchedulerCallbackPointer(void);  // @ 0x00003b58
void mpc555_initQspiRegisters(void);  // @ 0x00003b6c
undefined1 cm848_getDiagnosticServicePriority(int param_1);  // @ 0x00003d54
void mpc555_canTransmitQueuePush(uint param_1,uint param_2,int param_3,undefined1 *param_4);  // @ 0x00003dac
void cm848_transmitCanMessage(undefined4 *param_1);  // @ 0x00003f20
undefined4 cm848_lookupTableEntryByKey(uint param_1);  // @ 0x00003f70
undefined4 cm848_dataTransferBufferWrite(int param_1,int param_2,uint param_3,int param_4,byte param_5);  // @ 0x00003fcc
void cm848_prepareDataTransferBuffer(void);  // @ 0x00004194
void mpc555_initAdcChannelConfig(void);  // @ 0x000042b0
void mpc555_configureAdcConversionRegs(void);  // @ 0x00004320
void mpc555_configureAdcChannelRange(uint param_1);  // @ 0x000043a4
void cm848_initDataTransferCopyBuffer(int param_1);  // @ 0x00004500
undefined4 cm848_advanceAdcChannelQueue(void);  // @ 0x00004570
int cm848_checkDataTransferBufferStatus(void);  // @ 0x00004654
void cm848_startAdcConversion(void);  // @ 0x000046dc
void cm848_initCanMailboxFilters(void);  // @ 0x00004720
bool mpc555_initFlashMemoryConfig(uint param_1);  // @ 0x000049d0
void cm848_can2MailboxTransmitCompleteWrapper(void);  // @ 0x00004eec
void cm848_can2MailboxTransmitRangeWrapper(void);  // @ 0x00004f0c
void cm848_writeCan2ControllerTxMailbox(int param_1,int param_2,int param_3);  // @ 0x00004f2c
void mpc555_can2TransmitInterruptHandler(void);  // @ 0x00004f6c
void mpc555_manageCan1TransmitBuffer(void);  // @ 0x00005064
void mpc555_processCanReceiveBuffer(int param_1);  // @ 0x00005134
void mpc555_dispatchCanMessageHandlers(void);  // @ 0x0000526c
byte mpc555_processAdcConversionResult(int param_1,uint param_2,uint param_3);  // @ 0x00005400
undefined1 mpc555_processAdcWithOffset(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4);  // @ 0x00005728
undefined1 cm848_processAdcSensorByte(int param_1);  // @ 0x00005798
undefined1 cm848_processAdcSensorDword(int param_1);  // @ 0x00005808
undefined1 mpc555_processAdcSensorDwordExt(int param_1);  // @ 0x00005870
undefined1 mpc555_processAdcSensorDualDword(int param_1);  // @ 0x000058e8
undefined1 cm848_getServiceDataOffset(int param_1);  // @ 0x00005958
undefined4 validateServiceDataLength(int param_1);  // @ 0x0000597c
void mpc555_multiFrameCanTransmit(uint *param_1);  // @ 0x00005adc
void mpc555_handleJ1939QueueRequest(byte request_type,byte connection_id);  // @ 0x00005c50
void mpc555_processAdcChannelGroup(undefined1 param_1,undefined2 param_2);  // @ 0x00005cf4
void mpc555_sendJ1939DiagnosticMessage(byte dest_address,byte *data_ptr,word data_length);  // @ 0x00005d8c
undefined1 mpc555_sendDiagAcknowledgeFrame (undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined2 param_4);  // @ 0x00005e38
void mpc555_handleJ1939DataRequest(undefined4 *param_1);  // @ 0x00005ecc
void mpc555_handleJ1939DataTransfer(int param_1);  // @ 0x00005fe4
void mpc555_handleJ1939AbortRequest(int param_1);  // @ 0x00006180
void mpc555_handleJ1939AbortAcknowledge(int param_1);  // @ 0x000061e8
void cm848_j1939DiagMessageDispatcher(int param_1);  // @ 0x0000628c
void mpc555_processJ1939QueueTransmit(void *queue_entry);  // @ 0x000062fc
void mpc555_decrementPauseStatusCounter(void);  // @ 0x00006490
void cm848_processJ1939QueueStatus(byte connection_id);  // @ 0x000064c4
undefined * mpc555_initDiagnosticBuffers(int param_1);  // @ 0x00006508
void cm848_updateSystemTimers(undefined1 param_1,int param_2);  // @ 0x00006580
void mpc555_diagnosticSubcommandDispatcher(byte subcommand,byte *data_ptr);  // @ 0x0000662c
void cm848_resetSerialReceiveBuffer(void);  // @ 0x00006770
void mpc555_serialReceiveHandler(void);  // @ 0x000067b0
void mpc555_resetSerialCommunication(void);  // @ 0x0000685c
void serialTransmitHandler(void);  // @ 0x000068b4
void mpc555_enableSerialTransmit(void);  // @ 0x00006974
void mpc555_validateSerialChecksum(void);  // @ 0x000069b0
void mpc555_initSerialTransmit(void);  // @ 0x00006a5c
void mpc555_sensorFaultDetection(void);  // @ 0x00006ab8
undefined4 mpc555_updateSensorDiagnostics(void);  // @ 0x00006b24
void cm848_sensorInputProcessing(int param_1,int param_2,int param_3);  // @ 0x00006bac
void mpc555_processScheduledTasks(void);  // @ 0x00006bdc
void cm848_processMainLoop(void);  // @ 0x00006ca4
void cm848_dispatchDiagnosticService(byte service_code,byte *data_ptr,word data_length);  // @ 0x00006d24
void cm848_sendEepromVersionResponse(void);  // @ 0x00006e1c
void mpc555_handleEepromDiagnosticResponse(void);  // @ 0x00006eac
void mpc555_processEepromDataTransfer(void);  // @ 0x00006f54
void cm848_scrambleBitPattern(int param_1,int param_2);  // @ 0x000071f8
undefined4 sensorRangeValidation(undefined4 param_1);  // @ 0x00007370
void cm848_processSensorFilterChain(byte *param_1,uint param_2);  // @ 0x000074a0
void mpc555_processSensorWithOverride(undefined4 param_1,undefined2 param_2);  // @ 0x000075dc
void mpc555_watchdogTimerTick(void);  // @ 0x00007608
void mpc555_watchdogTimerTick_midEntry(void);  // @ 0x000076b4
char cm848_sensorFaultThresholdCheck(uint param_1,int param_2);  // @ 0x000076c8
undefined1 mpc555_sensorAcquisitionCycle(undefined4 param_1,int param_2,ushort *param_3,int param_4);  // @ 0x00007740
undefined4 mpc555_validateTransferBlockParams(short *param_1);  // @ 0x00007840
undefined1 mpc555_processTransferCrc(byte *param_1,uint param_2,int param_3);  // @ 0x000078d0
void mpc555_systemWatchdogReset(void);  // @ 0x00007974
void mpc555_initQspiHardware(void);  // @ 0x00007b08
void mpc555_systemHaltLoop(void);  // @ 0x00007dc4
void cm848_keyOnStatusMonitor(void);  // @ 0x0000b44c
void cm848_phase_common_processing(void);  // @ 0x0000b76c
void cm848_phase_group_a_processing(void);  // @ 0x0000b7b4
void cm848_phase_group_b_processing(void);  // @ 0x0000b854
void hpcr_periodicTaskSet_fuelFinal(void);  // @ 0x0000b8fc
void cm848_periodicTaskSet_sensorProcessing(void);  // @ 0x0000b98c
void cm848_periodicTaskSet_controlLoop(void);  // @ 0x0000ba08
void cm848_periodicTaskSet_auxiliaryControl(void);  // @ 0x0000ba90
void cm848_periodicTaskSet_canTx(void);  // @ 0x0000bb18
void cm848_periodicTaskSet_diagnostics(void);  // @ 0x0000bb40
void cm848_periodicTaskSet_protection(void);  // @ 0x0000bb68
void cm848_periodicTaskSet_timing(void);  // @ 0x0000bb90
void cm848_periodicTaskSet_outputs(void);  // @ 0x0000bbb8
void cm848_periodicTaskSet_sensors(void);  // @ 0x0000bbe0
void cm848_periodicTaskSet_monitoring(void);  // @ 0x0000bc08
void cm848_periodicTaskSet_communication(void);  // @ 0x0000bc34
void cm848_periodicTaskGroup12_calibration1(void);  // @ 0x0000bc5c
void cm848_periodicTaskGroup13_calibration2(void);  // @ 0x0000bc80
void cm848_periodicTaskGroup14_calibration3(void);  // @ 0x0000bca4
void cm848_periodicTaskGroup15_calibration4(void);  // @ 0x0000bcc8
void cm848_periodicTaskSet_protection2(void);  // @ 0x0000bce8
void cm848_periodicTaskGroup17_calibration5(void);  // @ 0x0000bd08
void cm848_periodicTaskGroup18_calibration6(void);  // @ 0x0000bd28
void hpcr_periodicTaskGroup25_calibration7(void);  // @ 0x0000bd54
void cm848_periodicTaskGroup26_calibration8(void);  // @ 0x0000bd80
void cm848_periodicTaskGroup27_calibration9(void);  // @ 0x0000bdac
void cm848_periodicTaskGroup28_calibration10(void);  // @ 0x0000bdd8
void cm848_periodicTaskGroup29_calibration11(void);  // @ 0x0000be04
void cm848_periodicTaskGroup30_calibration12(void);  // @ 0x0000be30
void cm848_periodicTaskGroup31_calibration13(void);  // @ 0x0000be5c
void cm848_periodicTaskGroup32_calibration14(void);  // @ 0x0000be88
void cm848_periodicTaskSet_protection3(void);  // @ 0x0000beb4
void cm848_schedulerPhaseDispatcher(void);  // @ 0x0000bec8
void cm848_periodicTaskSet_auxiliary(void);  // @ 0x0000bee0
void periodicTaskSet_fuelDemand(void);  // @ 0x0000bf08
void hpcr_periodicTaskGroup36_calibration15(void);  // @ 0x0000bf34
void cm848_periodicTaskGroup37_calibration16(void);  // @ 0x0000bf60
void cm848_periodicTaskGroup38_calibration17(void);  // @ 0x0000bf88
void cm848_periodicTaskSet_diagnostics2(void);  // @ 0x0000bfb0
void hpcr_periodicTaskGroup20_calibration(void);  // @ 0x0000bfd8
void cm848_periodicTaskGroup21_calibration(void);  // @ 0x0000c000
void cm848_periodicTaskGroup22_calibration(void);  // @ 0x0000c028
void hpcr_periodicTaskSet_protection4(void);  // @ 0x0000c050
void cm848_periodicTaskSet_outputs2(void);  // @ 0x0000c078
void main_loop(void);  // @ 0x0000c0a0
void cm848_initSensorDefaults(void);  // @ 0x0000c874
void cm848_sensorChannel0_init(void);  // @ 0x0000c8bc
void cm848_sensorChannel0_process(void);  // @ 0x0000c948
void cm848_sensorChannel1_init(void);  // @ 0x0000c9d4
void cm848_sensorChannel1_process(void);  // @ 0x0000ca60
void cm848_sensorChannel2_init(void);  // @ 0x0000caec
void cm848_sensorChannel2_process(void);  // @ 0x0000cb78
void cm848_sensorChannel3_boostPressureInit(void);  // @ 0x0000cc04
void cm848_sensorChannel3_boostPressureProcess(void);  // @ 0x0000cc90
void cm848_sensorChannel4_init(void);  // @ 0x0000cd1c
void cm848_sensorChannel4_process(void);  // @ 0x0000cda8
void cm848_sensorChannel5_init(void);  // @ 0x0000ce34
void cm848_sensorChannel5_process(void);  // @ 0x0000cec0
void cm848_sensorChannel6_init(void);  // @ 0x0000cf4c
void cm848_sensorChannel6_process(void);  // @ 0x0000cfd8
void cm848_sensorChannel7_init(void);  // @ 0x0000d064
void cm848_sensorChannel7_process(void);  // @ 0x0000d0f0
void cm848_sensorChannel8_init(void);  // @ 0x0000d17c
void cm848_sensorChannel8_process(void);  // @ 0x0000d208
void cm848_sensorChannel9_init(void);  // @ 0x0000d294
void cm848_sensorChannel9_process(void);  // @ 0x0000d320
void cm848_sensorChannel10_throttleInit(void);  // @ 0x0000d3ac
void cm848_sensorChannel10_throttleProcess(void);  // @ 0x0000d438
void cm848_sensorChannel11_init(void);  // @ 0x0000d4c4
void cm848_sensorChannel11_process(void);  // @ 0x0000d550
void cm848_sensorChannel12_init(void);  // @ 0x0000d5dc
void cm848_sensorChannel12_process(void);  // @ 0x0000d668
void cm848_sensorChannel13_init(void);  // @ 0x0000d6f4
void cm848_sensorChannel13_process(void);  // @ 0x0000d780
void cm848_sensorChannel14_init(void);  // @ 0x0000d80c
void cm848_sensorChannel14_process(void);  // @ 0x0000d898
void cm848_sensorChannel15_init(void);  // @ 0x0000d924
void cm848_sensorChannel15_process(void);  // @ 0x0000d9b0
void cm848_sensorChannel16_init(void);  // @ 0x0000da3c
void cm848_sensorChannel16_process(void);  // @ 0x0000db50
void cm848_sensorChannel16BProcessOilPressure(void);  // @ 0x0000db88
word cm848_oilPressureDeltaCalculation(void);  // @ 0x0000dc64
void cm848_fuelDemandBlendCalculator(void);  // @ 0x0000dcdc
void cm848_initFuelTableSizes(void);  // @ 0x0000e09c
void cm848_trackMinimumFuelDemand(void);  // @ 0x0000e0c4
undefined4 cm848_checkPressureFuelState(void);  // @ 0x0000e0f4
int cm848_calculateSensorEma(void);  // @ 0x0000e164
undefined4 cm848_checkFuelRateCondition(void);  // @ 0x0000e218
undefined4 cm848_checkPressureFuelDelayA(void);  // @ 0x0000e248
undefined4 cm848_checkPressureFuelDelayB(void);  // @ 0x0000e2cc
int cm848_checkPressureHysteresis(void);  // @ 0x0000e360
void timingProtectionFlagsOrchestrator(void);  // @ 0x0000e3a4
void hpcr_calculateFuelTrimOutput(void);  // @ 0x0000e518
void cm848_initFuelPressureVariables(void);  // @ 0x0000e748
void cm848_temperatureBasedFuelTrim(void);  // @ 0x0000e78c
void cm848_initTemperatureTrimTableSizes(void);  // @ 0x0000e8ac
void cm848_initTemperatureTrimCoeff(void);  // @ 0x0000e8cc
void cm848_fuelTimingRateLimitedBlend(void);  // @ 0x0000e8dc
void cm848_fuelTimingCompensation(void);  // @ 0x0000e8f0
void fuelTimingOilPressureModeController(void);  // @ 0x0000ea00
void cm848_initFuelDemandVariables(void);  // @ 0x0000fabc
void cm848_restoreEngineOperatingMode(void);  // @ 0x0000fb28
void cm848_calculateFuelTimingBlend(void);  // @ 0x0000fcd0
void cm848_initFuelTimingTableSizes(void);  // @ 0x0000fe3c
void cm848_calculateFuelTimingTarget(void);  // @ 0x0000fe5c
void cm848_calculateFuelTrimValues(void);  // @ 0x0000ff04
void cm848_initEngineOperatingMode(int param_1);  // @ 0x00010110
void cm848_initLookupTableParams(void);  // @ 0x00010248
void cm848_stubFunction3(void);  // @ 0x00010270
undefined8 mpc555_timerInterruptHandler(undefined4 param_1,undefined4 param_2);  // @ 0x00010274
void mpc555_fatalErrorHalt(void);  // @ 0x00010694
void cm848_selectTurboModeParameters(void);  // @ 0x000107ec
void cm848_updateTurboModeState(void);  // @ 0x0001083c
void cm848_selectTemperatureTrimValue(void);  // @ 0x00010874
void cm848_calculateTurboRatioA(void);  // @ 0x000108a4
void cm848_calculateTurboRatioB(void);  // @ 0x000109c8
void cm848_calculateTurboRatios(void);  // @ 0x00010b04
void cm848_calculateTurboBlendOutput(void);  // @ 0x00010b28
void cm848_calculateTurboRatioWithMode(void);  // @ 0x00010d3c
void cm848_initTurboRatioVariables(void);  // @ 0x00010ed0
void cm848_calculateLoadBasedAdjustment(void);  // @ 0x00010f68
ushort cm848_lookupRpmLoadTable(void);  // @ 0x000110bc
void cm848_calculateLoadAdjustmentFactors(void);  // @ 0x00011170
void cm848_processLoadAdjustment(void);  // @ 0x00011290
void mpc555_initLoadAdjustmentTableSizes(void);  // @ 0x00011324
void cm848_calculateLoadGainValues(void);  // @ 0x0001134c
void cm848_selectLoadAdjustmentLimits(void);  // @ 0x00011410
void cm848_calculateLoadCompensation(void);  // @ 0x000114dc
void cm848_calculateLoadIntegral(void);  // @ 0x000115cc
void cm848_processLoadGainCalculations(void);  // @ 0x000118f8
void mpc555_initLoadGainVariables(void);  // @ 0x00011924
undefined4 cm848_calculateRateLimitedValue(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5);  // @ 0x0001198c
void cm848_checkSpeedBandCondition(void);  // @ 0x00011a4c
void oilPressureRpmFaultMonitor(void);  // @ 0x00011ab4
void cm848_turboCompensationWrapper(void);  // @ 0x0001231c
void mpc555_initTurboCompensationVariables(void);  // @ 0x0001233c
undefined2 cm848_circularBufferWriteUnsigned(int param_1,undefined2 param_2,int param_3);  // @ 0x000123dc
int cm848_circularBufferWriteSigned(int param_1,undefined2 param_2,int param_3);  // @ 0x00012404
void cm848_calculateLoadBasedFuelTrim(void);  // @ 0x0001242c
void cm848_calculateRpmBasedFuelTrim(void);  // @ 0x000125f4
undefined4 cm848_checkFuelSystemFaultFlags(void);  // @ 0x00012724
undefined4 cm848_checkEngineFaultConditions(void);  // @ 0x00012778
void cm848_selectFuelTrimMode(void);  // @ 0x000127bc
void cm848_throttleBasedFuelCalculation(void);  // @ 0x000128a0
void cm848_initFilterCoefficients(void);  // @ 0x00012a58
void cm848_boostBasedFuelModifier(void);  // @ 0x00012ad4
void cm848_loadBasedFuelAdjustment(void);  // @ 0x00012cf4
void cm848_fuelDemandWithLoadCompensation(void);  // @ 0x00012dc4
void cm848_initFilterTablePointers(void);  // @ 0x00012e40
void cm848_fuelControlMainCalculation(void);  // @ 0x00012e60
void cm848_initFuelControlFilterSystem(void);  // @ 0x00012e88
void cm848_fuelDemandErrorCalculation(void);  // @ 0x00012eb4
void cm848_initFuelDemandBlendPointers(void);  // @ 0x00012f40
void cm848_fuelDemandBlendCalculation(void);  // @ 0x00012f60
void mpc555_initManifoldPressureFilter(void);  // @ 0x000130ac
void cm848_calculateBoostPressureOffset(void);  // @ 0x000130dc
void cm848_initFuelFilterDefaults(void);  // @ 0x0001327c
void cm848_calculateBoostTorqueOffset(void);  // @ 0x00013294
void cm848_initFuelDemandFilterState(void);  // @ 0x0001350c
void cm848_checkBoostControlCondition(void);  // @ 0x00013564
void cm848_processBoostControlState(void);  // @ 0x0001359c
void cm848_processBoostProtectionConditions(void);  // @ 0x00013774
void cm848_selectLoadNormalizer(void);  // @ 0x0001392c
void cm848_processLoadNormalizerSelection(void);  // @ 0x00013a80
void cm848_processBoostProtectionMode(undefined4 param_1,int param_2);  // @ 0x00013aec
void cm848_initBoostProtectionState(void);  // @ 0x00013ca4
void cm848_calculateThrottleDerivative(void);  // @ 0x00013d14
void cm848_calculateThrottleFiltered(void);  // @ 0x00013dc8
void mpc555_initThrottleFilterState(void);  // @ 0x00014080
void cm848_calculateRpmLoadTables(void);  // @ 0x0001410c
void cm848_selectFuelDemandOverride(void);  // @ 0x0001429c
void cm848_selectFuelLimitOverride(void);  // @ 0x000142d0
void cm848_setFuelStatusFlags(void);  // @ 0x00014304
void cm848_calculateRpmLoadLimit(void);  // @ 0x00014374
void cm848_selectFinalLoadLimit(void);  // @ 0x00014430
void cm848_setFuelDemandVariable(undefined2 param_1);  // @ 0x0001444c
void cm848_setFuelDemandVariable(undefined2 param_1);  // @ 0x00014458
void cm848_selectFuelLoadOverride(void);  // @ 0x00014464
void cm848_processFuelLimitCalculations(void);  // @ 0x00014498
void mpc555_initFuelLimitTableSizes(void);  // @ 0x000144d0
undefined4 cm848_compareForFuelMapSelection(int param_1,int param_2);  // @ 0x00014508
int cm848_filterInputValue (int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7);  // @ 0x00014528
void cm848_calculateFuelDemandMode1(void);  // @ 0x00014610
void cm848_calculateFuelDemandMode2(void);  // @ 0x000149a4
void cm848_calculateFuelDemandTimingOffset(void);  // @ 0x00014d38
void cm848_calculateFuelDemandMode3(void);  // @ 0x000150b0
void cm848_calculateFuelDemandBlendTables(void);  // @ 0x00015444
void cm848_lookupFuelDemandRpmTables(void);  // @ 0x00015760
void cm848_calculateFuelLimitSource(void);  // @ 0x00015a24
void cm848_selectFuelLimitWithFiltering(void);  // @ 0x00015bd8
uint cm848_fuelDemandFilterUpdate(uint param_1,ushort *param_2,int param_3);  // @ 0x00015d2c
void cm848_interpolateFuelMapTable(void *table_ptr,word rpm_input,word load_input);  // @ 0x00015e08
void cm848_processFuelMapInterpolation(void);  // @ 0x00015f34
void cm848_calculateFuelBlendModeSelection(void);  // @ 0x000160ac
void cm848_calculateFuelBlendMode(int param_1);  // @ 0x00016408
void cm848_calculateFuelBlendMode(int param_1);  // @ 0x0001640c
void cm848_processFuelDemandCalculations(void);  // @ 0x000164ac
undefined2 cm848_fuelDemandTableLookup(undefined4 param_1);  // @ 0x000164e4
int cm848_fuelDemandRpmCorrection(undefined4 param_1,word param_2);  // @ 0x00016724
void cm848_lookupProtectionFuelDemand(void);  // @ 0x00016774
void mpc555_initFuelDemandTablePointers(void);  // @ 0x00016888
void cm848_calculateFuelInjectionTiming(void);  // @ 0x00016a90
void cm848_calculateManifoldPressureOffset(void);  // @ 0x00016c40
void cm848_calculateFuelDemandDelta(void);  // @ 0x00016cd4
void cm848_applyFuelDemandOffset(void);  // @ 0x00016d6c
void cm848_processFuelTimingCalculations(void);  // @ 0x00016e90
void cm848_storeFuelLimitValues(void);  // @ 0x00016f9c
void mpc555_initFuelTimingTablePointers(void);  // @ 0x00016ffc
void cm848_fuelDemandBaseCalculation(void);  // @ 0x0001702c
void cm848_fuelDemandModeSelector(void);  // @ 0x00017150
void cm848_fuelDemandEnableChecker(void);  // @ 0x000172b0
void cm848_fuelDemandRateLimiterStateMachine(void);  // @ 0x000172e8
void cm848_fuelDemandOverrideHandler(void);  // @ 0x000173a8
void cm848_fuelDemandSmoothingController(void);  // @ 0x00017560
void cm848_fuelDemandFinalCalculation(void);  // @ 0x0001782c
void cm848_fuelDemandCoordinator(void);  // @ 0x00017980
void cm848_initFuelDemandRateVariables(void);  // @ 0x00017af4
void cm848_storeFuelDemandPreviousValues(void);  // @ 0x00017b54
undefined2 cm848_calculateFuelFlowRate(void);  // @ 0x00017b84
void cm848_selectFuelFlowMode(void);  // @ 0x00017d54
void mpc555_initFuelFlowRateVariables(void);  // @ 0x00017e54
void cm848_calculateOilPressureProtection(void);  // @ 0x00017eb8
void cm848_calculateFuelFlowWithMode(void);  // @ 0x00017f50
void emptyStubFunction3(void);  // @ 0x0001806c
int cm848_throttlePositionProcessing(word param_1,short param_2);  // @ 0x00018070
void cm848_faultSeverityEvaluation(void);  // @ 0x0001811c
void cm848_processThrottlePositionLookups(void);  // @ 0x0001820c
void cm848_calculateThrottleProtectionLimit(void);  // @ 0x000182e8
void cm848_checkProtectionEnableConditions(void);  // @ 0x00018384
void cm848_checkFaultConditionThreshold(void);  // @ 0x000184f0
int cm848_conditionalFirstOrderFilter(undefined4 param_1,int param_2,int param_3);  // @ 0x000185cc
void cm848_processFaultIncrement(short *param_1);  // @ 0x0001860c
void cm848_processFaultStateWithFilter(undefined2 *param_1);  // @ 0x00018780
void cm848_updateFaultStatusRegisters(void);  // @ 0x00018904
void cm848_selectFaultProtectionValue(void);  // @ 0x00018a50
void cm848_processFaultProtection(void);  // @ 0x00018ac0
void mpc555_initFaultProtectionVariables(void);  // @ 0x00018afc
void cm848_processSensorProtectionRamp(void);  // @ 0x00018bc0
void cm848_processSensorFaultDetection(void);  // @ 0x00018cfc
void cm848_initSensorFaultVariables(void);  // @ 0x00018f1c
void cm848_calculateSensorDiagnosticValue(void);  // @ 0x00018f8c
void mpc555_updateSensorDiagnosticFlags(void);  // @ 0x000191a0
void cm848_processSensorMonitoringLogic(void);  // @ 0x000191e8
void cm848_updateEngineModeFromSensor(void);  // @ 0x00019390
void mpc555_processSensorValidation(void);  // @ 0x0001956c
void cm848_checkSensorRangeConditions(void);  // @ 0x000196a4
void cm848_calculateSensorBlendFactor(void);  // @ 0x000197b4
void cm848_processSensorBlendState(void);  // @ 0x00019830
void cm848_selectSensorBlendOutput(void);  // @ 0x00019900
void cm848_initSensorBlendVariables(void);  // @ 0x000199f4
void cm848_processSensorBlendCalculation(void);  // @ 0x00019ac0
void cm848_sensorMonitoringMainLoop(void);  // @ 0x00019b20
void cm848_selectFuelDemandUpperLimit(int param_1);  // @ 0x00019e08
void cm848_calculateFuelDemandLimits(void);  // @ 0x00019ea4
void cm848_applyFuelDemandProtection(void);  // @ 0x00019fe0
void cm848_processFuelDemandLimits(void);  // @ 0x0001a1b4
void cm848_processSensorAndFuelDemand(void);  // @ 0x0001a1dc
void cm848_initFuelDemandLimitVariables(void);  // @ 0x0001a204
void cm848_processConditionTimerA(int param_1);  // @ 0x0001a340
void cm848_processConditionTimerB(int param_1);  // @ 0x0001a47c
void cm848_processConditionTimerC(void);  // @ 0x0001a608
void cm848_processConditionTimerD(void);  // @ 0x0001a754
undefined4 cm848_bothConditionsTrue(int param_1,int param_2);  // @ 0x0001a980
void cm848_processFuelDemandFaultConditions(void);  // @ 0x0001a9a8
void cm848_initFuelDemandFaultVariables(void);  // @ 0x0001ae2c
void cm848_processFaultTimingConditions(void);  // @ 0x0001af94
void cm848_updateFaultConditionState(void);  // @ 0x0001b120
void cm848_initFaultTimingVariables(void);  // @ 0x0001b35c
void cm848_processFaultAndFuelDemand(void);  // @ 0x0001b37c
void faultTimerHandler(undefined4 *param_1);  // @ 0x0001b3a0
undefined4 cm848_faultCounterDecrement(ushort param_1,int param_2);  // @ 0x0001b624
undefined4 cm848_faultCounterIncrement(byte param_1,byte param_2);  // @ 0x0001b69c
void cm848_sendFaultTimerMessage(void);  // @ 0x0001b730
void cm848_processFaultMessageTiming(void);  // @ 0x0001b778
void initFaultTimerMessage(void);  // @ 0x0001b900
void cm848_calculateColdStartFuelAdjust(void);  // @ 0x0001b99c
void cm848_initColdStartLimits(void);  // @ 0x0001bb30
void cm848_calculateColdStartRpmAdjust(void);  // @ 0x0001bb48
void cm848_calculateColdStartFuelOffset(void);  // @ 0x0001bb78
void cm848_calculateColdStartTempTable(void);  // @ 0x0001bc30
void cm848_selectColdStartRpmLimit(void);  // @ 0x0001bd44
void cm848_calculateIntakeAirAdjustment(void);  // @ 0x0001bd74
void cm848_checkColdStartConditions(void);  // @ 0x0001be64
void cm848_processColdStartAdjustment(void);  // @ 0x0001bf44
void cm848_initColdStartTablePointers(void);  // @ 0x0001bfc8
void cm848_processColdStartStateMachine(void);  // @ 0x0001c080
void cm848_coldStartRpmTableLookup(void);  // @ 0x0001c114
void cm848_coldStartFuelFactorLookup(void);  // @ 0x0001c1a4
void cm848_selectColdStartFactor(void);  // @ 0x0001c23c
void mpc555_processColdStartMainLoop(void);  // @ 0x0001c28c
void cm848_initCrankingLimits(void);  // @ 0x0001c978
void cm848_faultTimeoutHandler(byte param_1);  // @ 0x0001c9a0
void cm848_clearFaultFromActiveList(byte param_1);  // @ 0x0001cb94
void cm848_activeFaultScanProcessor(void);  // @ 0x0001cd1c
uint cm848_faultCodeLookup(uint param_1);  // @ 0x0001cdc0
uint cm848_findFaultByTypeAndSeverity(uint param_1,ushort param_2);  // @ 0x0001ce28
void cm848_registerFaultInActiveList(uint param_1);  // @ 0x0001cea4
void cm848_clearDiagnosticState(void);  // @ 0x0001d01c
void cm848_clearAllDiagnosticFaults(void);  // @ 0x0001d11c
void cm848_faultTableEntryProcessor(void);  // @ 0x0001d224
void cm848_buildFaultConditionMask(void);  // @ 0x0001d8f8
void diagnosticMainStateProcessor(void);  // @ 0x0001d9b8
void cm848_initDiagnosticRingBuffer(void);  // @ 0x0001dcdc
void cm848_markFaultForReplacement(void);  // @ 0x0001dd10
void cm848_updateFaultEntryCounters(uint param_1);  // @ 0x0001de4c
void cm848_resetFaultStatus(int param_1);  // @ 0x0001dee0
void hpcr_setFaultActiveStatus(int param_1,uint param_2);  // @ 0x0001df64
void hpcr_captureFreezeFrameData(int param_1,uint param_2,int param_3);  // @ 0x0001df88
void hpcr_processDiagnosticFrame (undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5, int param_6);  // @ 0x0001e158
void cm848_selectFuelDemandSource(void);  // @ 0x0001e22c
void cm848_clearFuelDemandFlag(void);  // @ 0x0001e4d8
void cm848_calculateProtectionRateLimited(void);  // @ 0x0001e4e8
void cm848_processProtectionSelection(void);  // @ 0x0001e5a4
void cm848_initEngineOperatingState(void);  // @ 0x0001e810
void cm848_updateEngineTimingCompensation(void);  // @ 0x0001e830
void cm848_processTorqueLimitState(void);  // @ 0x0001e870
void cm848_initProtectionTableSizes(void);  // @ 0x0001ea6c
void cm848_initFaultSeverityTables(void);  // @ 0x0001ea94
void cm848_calculateFuelDemandChangeRate(void);  // @ 0x0001eae8
void cm848_processFaultIncrement(short *param_1);  // @ 0x0001ec48
uint cm848_calculateDualAxisFuelLimit(void);  // @ 0x0001ec70
void cm848_initFuelDemandTracking(void);  // @ 0x0001ef30
void fuelDemandProportionalCalculationSlowCycle40Coordinator(void);  // @ 0x0001ef88
uint cm848_processActiveFaultList(word param_1);  // @ 0x0001f03c
void cm848_calculateFuelDemandWithTrim(void);  // @ 0x0001f17c
void cm848_initFuelDemandTableDimensions(void);  // @ 0x0001f300
void cm848_initProtectionStateWithFuelDemand(void);  // @ 0x0001f318
void cm848_calculateTimingCompensation(void);  // @ 0x0001f34c
void cm848_processTorqueLimitTiming(void);  // @ 0x0001f40c
void cm848_initSensorRawChannels(void);  // @ 0x0001f98c
void selectSensorRawChannels(void);  // @ 0x0001fa20
void cm848_selectTorqueLimit(void);  // @ 0x0001fd94
void cm848_initTorqueLimitDefaults(void);  // @ 0x00020410
undefined1 cm848_getLimitCategoryCode(int param_1);  // @ 0x000204a8
void cm848_calculateProtectionActivationDelay(void);  // @ 0x00020500
uint cm848_calculateEffectiveFuelLimit(void);  // @ 0x00020554
void cm848_selectTorqueLimitStateMachine(void);  // @ 0x00020860
void cm848_calculateLoadRateOfChange(void);  // @ 0x000209e8
void cm848_calculateLoadToFuelRatio(void);  // @ 0x00020a58
void emptyStubFunction3(void);  // @ 0x00020aec
void cm848_calculateOilPressureRateOfChange(void);  // @ 0x00020af0
void cm848_updateProtectionParameters(void);  // @ 0x00020b84
void cm848_updateProtectionInputs(void);  // @ 0x00020bfc
void cm848_initProtectionDefaults(void);  // @ 0x00020c60
void cm848_processJ1939RxMessage(int param_1,int param_2);  // @ 0x00020c64
void cm848_updateProtectionStateMachine(void);  // @ 0x00020d10
void cm848_initProtectionDelayDefaults(void);  // @ 0x000212dc
void cm848_calculateSpeedControlError(void);  // @ 0x00021314
void cm848_initSpeedControlTableDimensions(void);  // @ 0x0002156c
undefined4 cm848_initJ1939MessageBuffers(void);  // @ 0x00021668
undefined4 mpc555_processJ1939RxQueue(undefined4 param_1,int param_2);  // @ 0x000216fc
undefined1 cm848_j1939ProcessRxQueueDefault(void);  // @ 0x000218b0
undefined1 cm848_j1939ProcessRxQueueParam(undefined4 param_1);  // @ 0x000218dc
undefined4 cm848_validateCalibrationMemory(void);  // @ 0x00021918
void cm848_registerJ1939DiagnosticHandlers(void);  // @ 0x00021a24
undefined2 cm848_initUdsServiceHandlers(word param_1);  // @ 0x00021ac0
undefined2 cm848_applyFuelDemandFilter(undefined2 param_1);  // @ 0x00021b28
uint cm848_getHighestPriorityBit(void);  // @ 0x00021bf8
void cm848_updateProtectionThresholdsIfLow(void);  // @ 0x00021c3c
void cm848_setProtectionThresholdParameters(void);  // @ 0x00021c9c
void cm848_updateProtectionDiagnostics(void);  // @ 0x00021cd4
void cm848_initJ1939DiagnosticCallback(void);  // @ 0x000220b4
bool cm848_processJ1939DiagnosticRequest(undefined1 param_1,undefined4 param_2);  // @ 0x000220e4
void cm848_j1939DiagnosticServiceHandler(int param_1);  // @ 0x00022128
void cm848_initJ1939DiagnosticServiceHandler(void);  // @ 0x000221f0
void cm848_updateGovernorTimers(void);  // @ 0x00022220
void cm848_initGovernorDerivativeTerms(void);  // @ 0x00022318
void cm848_initGovernorControlHandler(undefined4 param_1,word param_2);  // @ 0x0002232c
void cm848_noOperation(void);  // @ 0x0002235c
void cm848_processSecurityAccessRequest(int param_1);  // @ 0x0002236c
void cm848_clearGovernorDerivativeMode(int param_1);  // @ 0x000223a0
void cm848_processGovernorControlMessage(int param_1);  // @ 0x000223f4
void cm848_initializeGovernorDerivatives(void);  // @ 0x00022468
void cm848_matchSecurityRequest(void);  // @ 0x00022570
void cm848_processGovernorSecurityAccessRequest(undefined4 param_1,undefined4 param_2,uint param_3);  // @ 0x00022590
void cm848_j1939HandlePgn65228Dm3ClearDiag(undefined4 param_1);  // @ 0x00022674
void cm848_initPgn65228Dm3Handler(undefined4 param_1,undefined4 param_2,void *param_3);  // @ 0x00022770
void cm848_j1939HandleDm1RequestMessage(int param_1);  // @ 0x000227a0
void cm848_initJ1939Dm1RequestHandler(void);  // @ 0x00022840
void cm848_j1939ProcessTorqueSpeedControl(int param_1);  // @ 0x00022870
void cm848_selectTorqueLimitMode(void);  // @ 0x00022ab8
void cm848_initJ1939TorqueSpeedHandler(void);  // @ 0x00022bc4
void cm848_initJ1939VehicleSpeedHandler(void);  // @ 0x00022d18
void torqueControlModeHandler(int param_1);  // @ 0x00022d60
void cm848_processGovernorSpeedControlRequest(void);  // @ 0x00022e3c
void cm848_processGovernorSpeedRequest(void);  // @ 0x00022f90
bool cm848_j1939RegisterPgnHandler(byte pgn_byte_0,byte pgn_byte_1,void *handler_func);  // @ 0x00023188
void cm848_j1939DispatchPgnHandler(int param_1);  // @ 0x000231cc
void cm848_initJ1939ProtocolHandlers(undefined4 param_1,undefined4 param_2,void *param_3);  // @ 0x000232b4
void cm848_j1939HandleProprietaryCommand(int param_1);  // @ 0x000233a0
void cm848_initJ1939ProprietaryHandler(void);  // @ 0x0002343c
short cm848_j1939SetupMultiFrameTransfer(byte param_1);  // @ 0x0002346c
void j1939FormatMultiFrameResponse(void);  // @ 0x000234a4
void cm848_routeGovernorHandlerByTable(void);  // @ 0x0002352c
void cm848_setGovernorHandlerDefault(void);  // @ 0x000236b4
void cm848_j1939ProcessGovernorRequest(int param_1);  // @ 0x000236f0
void cm848_j1939DispatchAddressHandler(int param_1);  // @ 0x00023b38
void cm848_initJ1939AddressDispatcher(void);  // @ 0x00023bb4
void cm848_sendJ1939ProprietaryStatus(void);  // @ 0x00023be0
void cm848_initJ1939DmHandlerBuffer(int param_1,int param_2);  // @ 0x00023d14
void cm848_sendJ1939AcknowledgeMessage(int param_1,undefined1 param_2);  // @ 0x00023d3c
void cm848_sendJ1939NegativeAck(int param_1,undefined1 param_2);  // @ 0x00023dbc
void cm848_flushJ1939FrameBuffer(void);  // @ 0x00023e2c
void cm848_j1939HandlePgn65269AmbientConditions(void);  // @ 0x00023e8c
void cm848_sendJ1939ErrorFrame(void);  // @ 0x00023f4c
void cm848_j1939BuildEngineStatusByte(void);  // @ 0x00024028
void cm848_prepareAndSendJ1939Frame(byte *param_1,undefined4 param_2,int param_3,byte param_4);  // @ 0x000240b8
void cm848_prepareAndSendJ1939Frame(byte *param_1,undefined4 param_2,int param_3,byte param_4);  // @ 0x000240c4
void j1939HandlePgn65265CruiseVehicleSpeed(void);  // @ 0x00024178
void buildPgn65228Dm3ClearInitMessage(void);  // @ 0x00024230
void cm848_buildDiagnosticStatusMessage (undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5);  // @ 0x0002439c
void cm848_initPgn65265CruiseSpeedHandler(undefined4 param_1,undefined4 param_2,void *param_3);  // @ 0x00024664
void j1939HandlePgn65261CruiseControlSetup(void);  // @ 0x000246fc
void initPgn65261CruiseControlSetupStruct(void);  // @ 0x00024800
void cm848_j1939HandlePgn65259ComponentId(void);  // @ 0x00024870
void cm848_appendGovernorDroopDataToMessage(void);  // @ 0x000248dc
void cm848_initPgn65259ComponentIdHandler(undefined4 param_1,undefined4 param_2,void *param_3);  // @ 0x00024940
void cm848_sendJ1939ResponseFrame(byte *param_1,uint param_2);  // @ 0x000249c4
void cm848_sendJ1939ExtendedResponse(undefined4 param_1,undefined2 param_2);  // @ 0x00024afc
void cm848_j1939HandlePgn65234Dm11ClearActive(void);  // @ 0x00024b28
void cm848_initPgn65234Dm11Handler(undefined4 param_1,undefined4 param_2,void *param_3);  // @ 0x00024b64
void j1939HandlePgn65226Dm1ActiveDtc(void);  // @ 0x00024be8
void cm848_processDm1FaultBroadcast(void);  // @ 0x00024d78
void cm848_initPgn65226Dm1Handler(undefined4 param_1,undefined4 param_2,void *param_3);  // @ 0x00024dd8
void cm848_j1939HandlePgn65227Dm2PreviousDtc(void);  // @ 0x00024e78
void cm848_initPgn65227Dm2Handler(undefined4 param_1,undefined4 param_2,void *param_3);  // @ 0x00025000
void cm848_initPgn65227Dm2ResponseHandler(int param_1,int param_2,void *param_3);  // @ 0x00025050
void cm848_initPgn65229Dm4Handler(undefined4 param_1,undefined4 param_2,void *param_3);  // @ 0x00025094
void cm848_j1939BuildDm4FreezeFrame(int param_1);  // @ 0x00025110
void cm848_j1939HandlePgn65229Dm4FreezeFrame(void);  // @ 0x00025390
void cm848_j1939HandlePgn65230Dm5Readiness(void);  // @ 0x00025458
void cm848_initPgn65230Dm5Handler(undefined4 param_1,undefined4 param_2,void *param_3);  // @ 0x0002553c
void cm848_j1939SendDm1ResponseMessage(byte dest_address,byte fault_count);  // @ 0x000255c0
void cm848_j1939BuildEngineControlByte(void);  // @ 0x0002567c
void cm848_setEngineControllerStateCode(undefined4 param_1,undefined4 param_2,int param_3);  // @ 0x00025884
void j1939GetEngineStateCode(void);  // @ 0x0002588c
void cm848_transmitEngineStatusMessage(int param_1);  // @ 0x00025a9c
void j1939HandlePgn61443Eec2(void);  // @ 0x00025b10
void cm848_sendEec2WithDefaultValues(void);  // @ 0x00025d30
void cm848_initPgn61443Eec2Handler(undefined4 param_1,undefined4 param_2,void *param_3);  // @ 0x00025d60
void cm848_j1939SendOilPressureStatus(void);  // @ 0x00025de8
void cm848_j1939HandlePgn65263FluidLevelPressure(void);  // @ 0x00025eb4
void cm848_initPgn65263FluidLevelPressureHandler(undefined4 param_1,undefined1 *param_2);  // @ 0x00025fd8
void cm848_j1939HandlePgn65262EngineTemp(void);  // @ 0x00026024
void cm848_buildEngineTempWithConditionCheck(int param_1);  // @ 0x000260d4
void cm848_initPgn65262EngineTempHandler(undefined4 param_1,undefined4 param_2,void *param_3);  // @ 0x0002619c
void cm848_emptyStubFunctionJ1939A(void);  // @ 0x0002622c
void cm848_j1939BuildVehicleOperatingStatus(void);  // @ 0x00026238
void cm848_initJ1939SpeedControlMessage(void);  // @ 0x000263a4
void cm848_j1939SendDiagnosticStatusMessage(byte dest_address,byte status_type);  // @ 0x0002641c
void cm848_j1939HandlePgn65270InletExhaustConditions(void);  // @ 0x000264d8
void cm848_initPgn65270InletExhaustHandler(undefined1 *param_1,int param_2);  // @ 0x0002661c
void cm848_j1939BuildProtocolModeStatus(void);  // @ 0x00026650
void cm848_buildProtocolModeStatusMessage(int param_1);  // @ 0x000266f8
void cm848_initPgn65256VehicleMaintenanceHandler(undefined1 *param_1);  // @ 0x00026850
void cm848_j1939HandlePgn65242SoftwareId(void);  // @ 0x00026884
void cm848_initPgn65242SoftwareIdHandler(void);  // @ 0x000268ac
void cm848_j1939HandlePgn65504ProprietaryA(void);  // @ 0x000269f4
void cm848_buildVehicleMaintenanceStatusBits(int param_1);  // @ 0x00026aa4
void cm848_j1939HandlePgn65248VehicleDistance(void);  // @ 0x00026bb0
void cm848_initPgn65248VehicleDistanceHandler(undefined4 param_1,undefined4 param_2,void *param_3);  // @ 0x00026c6c
void cm848_j1939HandlePgn65271VehicleElectrical(void);  // @ 0x00026cf0
void cm848_j1939HandlePgn65260VehicleId(void);  // @ 0x00026db4
void cm848_emptyStubFunctionJ1939B(void);  // @ 0x00026dd0
void cm848_initPgn65260VehicleIdHandler(void);  // @ 0x00026ddc
void cm848_j1939SendSafetyStatusMessage(void);  // @ 0x00026e90
void emptyStubFunction4(void);  // @ 0x00026f78
void cm848_emptyStubFunction5(void);  // @ 0x00026f7c
void cm848_j1939FormatDm1Message(void);  // @ 0x00026f80
void cm848_updateGovernorTorqueLimit (undefined2 *param_1,undefined2 *param_2,undefined4 param_3,undefined2 *param_4, int param_5);  // @ 0x00026fb8
void cm848_resetGovernorState(void);  // @ 0x00027118
void cm848_processGovernorModeTransition(void);  // @ 0x0002715c
void cm848_selectTorqueLimitByStateMachine(void);  // @ 0x00027174
void cm848_governorDroopCalculation(uint *param_1,int param_2,int param_3);  // @ 0x00027bc4
undefined4 cm848_governorSpeedControl(int param_1,uint param_2);  // @ 0x00027cc4
void cm848_processSpeedSensorCompensation(void);  // @ 0x00027d38
void cm848_updateSpeedProtectionLimits(int param_1);  // @ 0x00027e4c
void cm848_processSpeedGovernorControl(void);  // @ 0x00027ff8
void cm848_resetSpeedControlTracking(void);  // @ 0x000285e4
void cm848_initSpeedProtectionParameters(void);  // @ 0x00028618
void cm848_processGovernorLoadCondition(void);  // @ 0x00028670
void cm848_clearGovernorTimerCounters(void);  // @ 0x00028994
void cm848_resetGovernorLoadState(void);  // @ 0x000289ac
undefined4 cm848_selectGovernorSetpointSource(int param_1);  // @ 0x000289d0
void cm848_updateGovernorSetpointParameters(void);  // @ 0x00028a14
void cm848_initGovernorTimerCountersWrapper(void);  // @ 0x00028abc
void cm848_initGovernorLoadStateWrapper(void);  // @ 0x00028adc
undefined4 cm848_getGovernorOverrideSource(void);  // @ 0x00028b38
void cm848_clearGovernorFilterAccumulators(void);  // @ 0x00028b8c
void cm848_calculateSpeedRateLimiting(void);  // @ 0x00028ba4
void cm848_setGovernorFilterPointer(void);  // @ 0x00028d30
void cm848_updateSpeedLimitFromCoolant(void);  // @ 0x00028d44
void cm848_calculateProtectionSpeedLimits(void);  // @ 0x0002906c
void cm848_applySpeedLimitConstraints(void);  // @ 0x000298a0
void cm848_updateGovernorSpeedLimits(void);  // @ 0x00029afc
void cm848_calculateGovernorCompensation(void);  // @ 0x00029b38
void cm848_initGovernorStateVariables(void);  // @ 0x00029bf8
void cm848_initGovernorLookupDimensions(void);  // @ 0x00029c80
void cm848_calculateFuelDemandFilter(void);  // @ 0x00029c98
void cm848_initFuelDemandFilterDimensions(void);  // @ 0x00029de0
void cm848_initProtectionFilterAccumulators(void);  // @ 0x00029e24
void cm848_processEngineConfigSpeedControl(void);  // @ 0x00029e50
uint cm848_absoluteValue16(uint param_1);  // @ 0x00029f3c
void cm848_checkSensorDeviationFlags(void);  // @ 0x00029f54
void cm848_processSensorDeviationOnKeyoff(void);  // @ 0x0002a214
void cm848_resetSensorDeviationTracking(void);  // @ 0x0002a2b4
void cm848_calculateProtectionRpmFilter(void);  // @ 0x0002a2d0
void cm848_calculateProtectionLoadCompensation(void);  // @ 0x0002a4b0
void cm848_checkProtectionParamLimit(void);  // @ 0x0002a918
void initProtectionParamCalculation(void);  // @ 0x0002a960
void cm848_processProtectionParamDelta(void);  // @ 0x0002ab2c
void cm848_initProtectionFilterState(void);  // @ 0x0002abc8
void cm848_smoothProtectionParamTransition(void);  // @ 0x0002ac44
void cm848_setProtectionParamFromRpm(void);  // @ 0x0002ad28
void cm848_initProtectionSmoothingPointer(void);  // @ 0x0002ad48
void cm848_evaluateProtectionCondition(void);  // @ 0x0002ad68
void cm848_processProtectionControlStateMachine(void);  // @ 0x0002afd0
void cm848_updateProtectionPreviousParam(void);  // @ 0x0002ba7c
void cm848_initProtectionEvalState(void);  // @ 0x0002bb24
void cm848_updateGovernorFromProtection(void);  // @ 0x0002bbe8
void cm848_resetProtectionBypass(void);  // @ 0x0002bd38
void cm848_j1939HandlePgn65264Pto(void);  // @ 0x0002bd58
void cm848_updateFaultOnKeyoff(void);  // @ 0x0002bf44
void cm848_calculateRpmLimitsFromProtection(void);  // @ 0x0002bf6c
void cm848_emptyStubFunction6(void);  // @ 0x0002c0fc
void cm848_initProtectionLimitVariables(void);  // @ 0x0002c100
void cm848_updateTorqueLimitFromProtection(void);  // @ 0x0002c114
void cm848_updateTorqueLimitFromThreshold(undefined4 param_1,uint param_2);  // @ 0x0002c14c
void cm848_trackFuelDemandThreshold(void);  // @ 0x0002c180
void cm848_processProtectionLimitActivation(void);  // @ 0x0002c23c
void cm848_checkSafetyConditionsForProtection(void);  // @ 0x0002c318
void cm848_processProtectionControlLogic(void);  // @ 0x0002c3c8
void cm848_updateRpmProtectionLimits(void);  // @ 0x0002c4fc
void cm848_updateProtectionEntryConditions(void);  // @ 0x0002c6c4
void cm848_processProtectionEntry(void);  // @ 0x0002c764
void mpc555_initFuelControlModeVariables(void);  // @ 0x0002c9bc
void cm848_calculateSpeedControlLimit(void);  // @ 0x0002ca14
void cm848_checkSpeedZeroCondition(void);  // @ 0x0002caa0
void cm848_selectFuelControlMode(void);  // @ 0x0002cb54
void cm848_calculateSpeedControlRampUp(void);  // @ 0x0002cbe8
void cm848_calculateSpeedControlRampDown(void);  // @ 0x0002cc90
void cm848_updateSpeedControlOutputs(void);  // @ 0x0002cd38
void cm848_selectSpeedControlGains(void);  // @ 0x0002cdb4
void cm848_processSpeedControlModeLogic(void);  // @ 0x0002ce8c
void cm848_calculateSpeedControlFiltered(void);  // @ 0x0002cebc
void cm848_selectFuelControlModeOutput(void);  // @ 0x0002d208
void cm848_calculateFuelControlLimits(void);  // @ 0x0002d2f8
void cm848_processFuelControlProtectionFlags(void);  // @ 0x0002d428
void cm848_processFuelControlOutput(void);  // @ 0x0002d5d8
void cm848_initProtectionModeDefaults(void);  // @ 0x0002d600
void cm848_initFuelControlStateVariables(void);  // @ 0x0002d638
void cm848_updateSpeedControlCounter1(int param_1);  // @ 0x0002d7a4
void cm848_processSpeedControlFilter1(int param_1);  // @ 0x0002d88c
void cm848_updateSpeedControlCounter2(int param_1);  // @ 0x0002d9f4
bool cm848_processSpeedControlFilter2(int param_1);  // @ 0x0002dadc
void cm848_initProtectionControlState(void);  // @ 0x0002dc40
void cm848_clearDiagnosticConditionFlags(void);  // @ 0x0002e02c
void cm848_processFaultCounterTimeout(void);  // @ 0x0002e17c
void cm848_incrementFaultTimeoutCounter(void);  // @ 0x0002e1f0
void cm848_processFaultConditionLogic(void);  // @ 0x0002e250
void cm848_calculateFaultThresholdDelta(void);  // @ 0x0002e488
void cm848_processFaultThresholdCondition(void);  // @ 0x0002e4cc
void cm848_processFaultConditionFlags(void);  // @ 0x0002e74c
void cm848_clearFaultStatusCounters(void);  // @ 0x0002e9c8
void cm848_processFaultStatusCalculation(void);  // @ 0x0002ea58
void cm848_clearFaultStatusValues(void);  // @ 0x0002ed30
void cm848_processFaultCondition1(void);  // @ 0x0002edc0
void cm848_calculateFaultStatusValue(void);  // @ 0x0002ef34
void cm848_processFaultConditionMain(void);  // @ 0x0002efe4
void cm848_processFaultCondition2(void);  // @ 0x0002f154
void cm848_calculateFaultStatusOffset(void);  // @ 0x0002f2c8
void cm848_processFaultStatusWord2(void);  // @ 0x0002f3a0
void cm848_calculateFaultRateValue(void);  // @ 0x0002f524
void cm848_processFaultStatusMain(void);  // @ 0x0002f5a4
void cm848_calculateDiagnosticStatusBits(void);  // @ 0x0002f604
void cm848_processFaultStatusFlags(void);  // @ 0x0002f6a0
void cm848_initFaultStatusFilterState(void);  // @ 0x0002f784
void cm848_protectionNormalHandler(void);  // @ 0x0002f860
void cm848_protectionOverloadHandler(void);  // @ 0x0002f920
void cm848_protectionCleanupHandler(void);  // @ 0x0002fe48
void cm848_protectionShutdownHandler(void);  // @ 0x0003004c
void cm848_protectionOutputController(void);  // @ 0x00030194
void cm848_protectionFinalizeState(void);  // @ 0x00030ad4
void cm848_protectionFuelDemandCheck(void);  // @ 0x00031320
void cm848_protectionTimeoutHandler(void);  // @ 0x0003148c
void cm848_protectionWarmupHandler(void);  // @ 0x00031584
void cm848_protectionStatusFlagHandler(void);  // @ 0x000316cc
void cm848_protectionStateTransitionCheck(void);  // @ 0x00031d98
uint cm848_protectionScaledLimitCalculation(int param_1);  // @ 0x000320e0
void cm848_protectionRateOfChangeCalculation(void);  // @ 0x00032250
void cm848_calculateProtectionFuelDemandThreshold(void);  // @ 0x0003241c
void cm848_processProtectionStateFlags(void);  // @ 0x0003257c
void cm848_protectionThresholdMonitor(void);  // @ 0x00032b00
void cm848_protectionStateMachine(void);  // @ 0x00032efc
void mpc555_initProtectionFilterVariables(void);  // @ 0x000331cc
void cm848_evaluateProtectionModeFlags(void);  // @ 0x00033488
void cm848_decrementProtectionTimers(void);  // @ 0x000335e4
void cm848_calculateProtectionConditions(void);  // @ 0x00033948
void processProtectionFlagConditions(void);  // @ 0x000343ac
void cm848_filterProtectionLoadValue(void);  // @ 0x0003491c
void cm848_evaluateProtectionFaultCondition(void);  // @ 0x00034a30
void cm848_processCalibrationTablesMain(void);  // @ 0x00034abc
void cm848_initProtectionSystem(void);  // @ 0x00034b14
void cm848_processProtectionFaultSeverity(void);  // @ 0x00034dd4
void cm848_processProtectionRateLimitFlags(void);  // @ 0x00034f4c
void cm848_calculateProtectionThresholdLimit(void);  // @ 0x00035154
void cm848_processProtectionStateMachine(void);  // @ 0x00035328
void cm848_updateSensorBufferValues(void);  // @ 0x00035370
void cm848_copySensorValuesToBuffer(void);  // @ 0x00035518
void cm848_processSensorLookupTable5(void);  // @ 0x00035558
void cm848_initSensorLookupTable5(void);  // @ 0x000355e4
void cm848_calculateSensorLookupValue(void);  // @ 0x00035670
void cm848_updateSensorLookupTable(void);  // @ 0x000356fc
void cm848_processSensorLookupTable4(void);  // @ 0x00035788
void cm848_initSensorLookupTable4(void);  // @ 0x00035814
void cm848_processSensorLookupTable3(void);  // @ 0x000358a0
void cm848_initSensorLookupTable3(void);  // @ 0x0003592c
void cm848_processSensorLookupTable2(void);  // @ 0x000359b8
void cm848_initSensorLookupTable2(void);  // @ 0x00035a44
void cm848_processSensorLookupTable0(void);  // @ 0x00035ad0
void cm848_initSensorLookupTable1(void);  // @ 0x00035b5c
void cm848_processSensorLookupTable1(void);  // @ 0x00035be8
void cm848_initSensorLookupTableInit1(void);  // @ 0x00035c74
void cm848_processSensorTemperatureData(void);  // @ 0x00035d00
void cm848_computeTemperatureDifferential(undefined2 *param_1,int param_2,int param_3);  // @ 0x00035d48
void cm848_enableSensorFilterUpdate(void);  // @ 0x00035d70
void cm848_processSensorFilterCalibration(void);  // @ 0x00035d80
void mpc555_initSensorCalibrationTables(void);  // @ 0x00035f14
void cm848_processFaultScanLookup(void);  // @ 0x00035fa8
void cm848_processMultiAxisInterpolation(void);  // @ 0x00036220
void cm848_j1939QueueEngineStatus(void);  // @ 0x000367a4
void cm848_j1939SetupTransportSession(void);  // @ 0x0003682c
void cm848_j1939QueuePeriodicMessage2(void);  // @ 0x0003686c
void cm848_j1939CheckTxTimeouts(void);  // @ 0x0003691c
void cm848_j1939UpdateTxTimers(void);  // @ 0x000369cc
void cm848_updateJ1939TxTimerCounter(void);  // @ 0x00036b10
void cm848_j1939QueueStatusMessage(void);  // @ 0x00036b68
void cm848_j1939QueuePeriodicMessage1(void);  // @ 0x00036bd8
void cm848_j1939FormatProprietaryStatus(void);  // @ 0x00036c1c
void cm848_processJ1939PeriodicMessages(void);  // @ 0x00036cec
void cm848_initJ1939TimerBuffers(void);  // @ 0x00036de0
void cm848_initJ1939StatusMessages(void);  // @ 0x00036f48
void cm848_initPeriodicTimerChannel6(void);  // @ 0x00037130
void cm848_initPeriodicTimerChannel5(void);  // @ 0x00037180
void cm848_initPeriodicTimerChannel4(void);  // @ 0x000371d0
void cm848_initPeriodicTimerChannel1(void);  // @ 0x00037214
void cm848_initPeriodicTimerChannel2(void);  // @ 0x00037270
void cm848_initPeriodicTimerChannel3(void);  // @ 0x000372c0
void cm848_initPeriodicTimerSystem(void);  // @ 0x00037334
void cm848_calculateFuelDemandOffsetTrim(void);  // @ 0x000373b0
void mpc555_initFuelDemandOffsetFilter(void);  // @ 0x0003744c
void cm848_j1939PeriodicTimerCallback(void);  // @ 0x00037464
void cm848_initJ1939PeriodicConfig(void);  // @ 0x000374b8
void cm848_j1939SendPeriodicMessage(void);  // @ 0x00037580
void cm848_processProtectionCoolantLookup(void);  // @ 0x000375c8
void cm848_processProtectionVoltageOffset(void);  // @ 0x00037658
void cm848_dispatchProtectionOutputMode(void);  // @ 0x000376dc
void cm848_filterProtectionOutput(void);  // @ 0x00037744
void cm848_calculateProtectionOutputDemand(void);  // @ 0x00037a40
void cm848_applyProtectionOutputDemand(void);  // @ 0x00037c74
void cm848_checkProtectionOutputConditions(void);  // @ 0x00037f28
void cm848_processProtectionMode2(void);  // @ 0x00038120
void cm848_initProtectionFilterValues(void);  // @ 0x000384d0
void cm848_processEngineRpmTarget(void);  // @ 0x0003866c
void cm848_processEngineRpmDerivative(void);  // @ 0x00038760
void cm848_initEngineRpmFilterPointers(void);  // @ 0x00038824
void cm848_setEngineRpmFromCalibration(void);  // @ 0x00038868
void cm848_processSafetyConditionProtection(void);  // @ 0x0003889c
void cm848_initProtectionFilterLimits(void);  // @ 0x00038a98
void cm848_processJ1939DiagnosticMessages(void);  // @ 0x00038ac8
void mpc555_triggerJ1939TransmitMessage(void);  // @ 0x00038c90
void cm848_j1939ProcessPeriodicTx(void);  // @ 0x00038cf0
void cm848_processCalibrationChecksumResponse(void);  // @ 0x00039004
void cm848_handleJ1939MessageTimeout(void);  // @ 0x00039bc0
void cm848_processUdsTransmitBuffer(void);  // @ 0x00039c44
void cm848_processCanMessageIndex(void);  // @ 0x00039d18
void cm848_j1939TransmitDiagnosticResponse(void);  // @ 0x00039e30
void cm848_j1939MessageResponseCallback(void);  // @ 0x00039f54
void cm848_clearCanMessageState(void);  // @ 0x0003a058
void cm848_resetUdsSessionState(void);  // @ 0x0003a080
void cm848_clearJ1939SyncFlags(void);  // @ 0x0003a0cc
void hpcr_initUdsResponseBuffer(void);  // @ 0x0003a100
undefined4 cm848_processJ1939DM1Pending(void);  // @ 0x0003a290
void hpcr_initJ1939MessageTables(void);  // @ 0x0003a450
void hpcr_initJ1939BufferValues(void);  // @ 0x0003a9a4
void cm848_initJ1939BufferParams(void);  // @ 0x0003aaf0
void cm848_clearCanMessageBuffers(void);  // @ 0x0003ab20
void mpc555_initJ1939TransmitSchedule(void);  // @ 0x0003abc4
void cm848_initJ1939CommunicationSystem(void);  // @ 0x0003ad04
void cm848_j1939TransmitScheduleCallback(void);  // @ 0x0003ad80
void cm848_processJ1939ReceivedMessages(void);  // @ 0x0003adcc
undefined4 cm848_calculateSecurityChecksum(uint param_1,uint param_2);  // @ 0x0003afb8
undefined4 cm848_validateDataWithChecksumTable(uint param_1,uint param_2,int param_3);  // @ 0x0003afc8
void cm848_processUdsSecurityService(void);  // @ 0x0003b030
void cm848_processProtectionCounters(void);  // @ 0x0003b910
void cm848_decrementProtectionChannelValue(void);  // @ 0x0003b95c
void cm848_selectProtectionOverrideMode(void);  // @ 0x0003bb28
void cm848_indirectJumpDispatcher(void);  // @ 0x0003bb74
void cm848_validateCalibrationAgainstEeprom(void);  // @ 0x0003bd14
void cm848_validateCalibratedParameterDelta(undefined4 param_1,int param_2);  // @ 0x0003bd5c
void cm848_validateCalibratedParameterChange(undefined4 param_1,int param_2);  // @ 0x0003bd60
void cm848_thunk_setByteAtOffset1(int param_1,undefined1 param_2);  // @ 0x0003be7c
void cm848_setByteAtOffset1(int param_1,undefined1 param_2);  // @ 0x0003be88
void cm848_processProtectionFaultFlags(void);  // @ 0x0003be90
void cm848_initProtectionChannelState(void);  // @ 0x0003bedc
void cm848_processProtectionChannelConfig(byte *param_1,byte param_2,byte *param_3);  // @ 0x0003c064
void cm848_evaluateProtectionChannelInput(byte *param_1,byte param_2,byte *param_3);  // @ 0x0003c090
void cm848_selectProtectionChannelMode(void);  // @ 0x0003c18c
void cm848_updateProtectionChannelOutput (undefined4 param_1,undefined4 param_2,int param_3,int param_4);  // @ 0x0003c1d4
void cm848_finalizeProtectionChannelState (undefined4 param_1,undefined4 param_2,int param_3,int param_4);  // @ 0x0003c1d8
void cm848_processEngineRpmMonitoring(void);  // @ 0x0003c26c
void cm848_configureOutputChannelFlags (uint param_1,undefined4 param_2,undefined4 param_3,ushort *param_4);  // @ 0x0003c33c
void cm848_processProtectionStateChange(void);  // @ 0x0003c5f0
void cm848_updateProtectionModeState (undefined2 param_1,undefined2 *param_2,int param_3,undefined2 *param_4, undefined4 param_5,undefined4 param_6,int param_7);  // @ 0x0003c62c
void cm848_processProtectionTimingCounter(void);  // @ 0x0003c6b0
void cm848_evaluateProtectionTimerThreshold(undefined4 param_1,undefined4 param_2,uint param_3);  // @ 0x0003c6ec
void cm848_checkProtectionVoltageInput(undefined2 *param_1,undefined2 param_2,int param_3);  // @ 0x0003c8bc
void hpcr_validateBatteryVoltageInput(void);  // @ 0x0003c8ec
void hpcr_processVoltageProtectionState(int param_1);  // @ 0x0003c928
void mpc555_initFuelDemandFilterPointers(void);  // @ 0x0003ca90
void cm848_evaluateVoltageThresholds(byte param_1,ushort *param_2,int param_3);  // @ 0x0003caec
void cm848_calculateProtectionUnitConversion(void);  // @ 0x0003cbd4
void cm848_storePressureConversionResult(void);  // @ 0x0003cc10
void cm848_calculateFuelDemandLimit(void);  // @ 0x0003ccb4
void cm848_calculateFuelDemandLimitState(void);  // @ 0x0003ccd4
void cm848_trackFuelDemandMinimum(void);  // @ 0x0003cefc
void mpc555_initFuelDemandTrackingState(void);  // @ 0x0003cf40
void cm848_processFaultPendingFlags(void);  // @ 0x0003cf68
void cm848_processOperatingModeFlags(void);  // @ 0x0003d070
void cm848_processFuelDemandEnableFlag(void);  // @ 0x0003d204
void cm848_processCalibration12FuelDemand(void);  // @ 0x0003d3b8
void cm848_initFuelDemandLimits(void);  // @ 0x0003d5fc
void mpc555_j1939InitTransmitBuffer(char param_1);  // @ 0x0003d618
uint cm848_configurePeriodicTimer(int param_1,int param_2,int param_3,uint param_4);  // @ 0x0003d68c
void mpc555_j1939ConfigureMultiFrame(int param_1,int param_2);  // @ 0x0003d904
int cm848_j1939QueueTransmitMessage(undefined4 *param_1,int param_2);  // @ 0x0003da60
void cm848_j1939ProcessTransmitQueue(void);  // @ 0x0003dbc0
void cm848_triggerJ1939TransmitQueueProcess(void);  // @ 0x0003dcf4
void mpc555_initQsmcmQspiModule(void);  // @ 0x0003dd28
void cm848_clearEngineConditionCounter(void);  // @ 0x0003dd88
void cm848_processEngineConditionFlags(void);  // @ 0x0003dd98
void cm848_calculateFuelDemandValue(void);  // @ 0x0003dfb8
void cm848_setFuelDemandActiveFlag(void);  // @ 0x0003e210
void cm848_initFuelDemandFilterState(void);  // @ 0x0003e230
void cm848_processTorqueLimitConfig(void);  // @ 0x0003e2bc
void cm848_initTorqueLimitState(void);  // @ 0x0003e400
void cm848_calculateTorqueCurveValue(void);  // @ 0x0003e42c
void cm848_initTorqueCurveState(void);  // @ 0x0003e520
void cm848_clearFuelDemandState(void);  // @ 0x0003e578
void cm848_dispatchFuelDemandCallback(void);  // @ 0x0003e5ac
void cm848_registerFuelDemandCallback(void);  // @ 0x0003e5f0
void cm848_processFuelDemandCallback(void);  // @ 0x0003e620
void cm848_registerFuelDemandCallback2(void);  // @ 0x0003e7c0
void cm848_processFuelDemandCallback2(void);  // @ 0x0003e7f0
void cm848_processFuelDemandTimeout(void);  // @ 0x0003e8d8
void cm848_transitionFuelDemandStateImmediate(void);  // @ 0x0003e914
void cm848_processSensorInputFiltering(void);  // @ 0x0003e96c
void cm848_calculateTorqueLimitType1(void);  // @ 0x0003e974
void cm848_calculateTorqueLimits(void);  // @ 0x0003e984
void cm848_calculateTorqueLimitType2(void);  // @ 0x0003e994
void mpc555_initThermalProtectionFilters(void);  // @ 0x0003eca4
void cm848_setThermalProtectionMode5(void);  // @ 0x0003eccc
void cm848_evaluateThermalProtectionActive(void);  // @ 0x0003ecdc
void cm848_calculateThermalLimitValue(void);  // @ 0x0003eea8
void cm848_processThermalDelayTimer(void);  // @ 0x0003f054
void cm848_processThermalRecovery(void);  // @ 0x0003f0b8
void cm848_processThermalProtectionState(void);  // @ 0x0003f154
void cm848_calculateThermalFuelLimit(void);  // @ 0x0003f218
void cm848_processThermalProtection(void);  // @ 0x0003f2b0
void cm848_applyThermalFuelLimit(void);  // @ 0x0003f35c
void cm848_initThermalProtectionState(void);  // @ 0x0003f38c
void cm848_processEngineLoadData(void);  // @ 0x0003f3f0
void cm848_resetEngineLoadTracker(void);  // @ 0x0003f6fc
void cm848_processEngineLoadFilters(void);  // @ 0x0003f734
void cm848_initEngineLoadFilterState(void);  // @ 0x0003f9c4
void mpc555_calculateTimerFrequencyConversion(void);  // @ 0x0003fa5c
void mpc555_initTpuBConfiguration(void);  // @ 0x0003fad4
void cm848_initEngineLoadProtection(void);  // @ 0x0003fba4
void cm848_processEngineLoadCalculation(void);  // @ 0x0003fc24
void cm848_processFuelRateConfig(void);  // @ 0x000400b8
void cm848_dispatchCalibrationBlockHandlers(void);  // @ 0x000402d4
void cm848_checkDiagnosticFuelOverride(void);  // @ 0x000403e4
void cm848_processProtectionRampControl(void);  // @ 0x0004043c
void cm848_initFuelFilterCoefficients(void);  // @ 0x00040828
void cm848_calculateFuelRateFromRpm(void);  // @ 0x00040844
uint cm848_calculateProtectionFuelLimit(uint param_1,uint param_2);  // @ 0x0004091c
void cm848_protectionFuelRateStep(int param_1);  // @ 0x00040938
void cm848_protectionFuelRateRamp(int param_1);  // @ 0x00040978
void cm848_processTimingTableLookup(void);  // @ 0x000409b0
void cm848_initFuelRateFromCapability(void);  // @ 0x00040d40
void cm848_validateFuelRateTarget(void);  // @ 0x00040d74
void cm848_copyProtectionRampValue(void);  // @ 0x00040dd4
void cm848_processTorqueLimitBounded(void);  // @ 0x00040de8
void cm848_processGovernorFuelRate(void);  // @ 0x00040e4c
void cm848_processProtectionRampTimer(void);  // @ 0x00040f80
void cm848_calculateProtectionLevelLimit(void);  // @ 0x000411b0
void cm848_processProtectionSystemBit3(void);  // @ 0x00041368
void cm848_processProtectionSystemBit4(void);  // @ 0x00041938
void cm848_applyMinimumProtectionLimit(void);  // @ 0x00041a10
void cm848_processGovernorErrorState(void);  // @ 0x00041a40
void cm848_processTemperatureCompensationMode(void);  // @ 0x00041b24
void cm848_processTemperatureTrim(void);  // @ 0x00041be4
void cm848_processFuelEfficiencyTrim(void);  // @ 0x00041fd4
void cm848_processTimingDispatcher(void);  // @ 0x0004218c
void cm848_initProtectionEventStates(void);  // @ 0x000421c8
void cm848_processSpeedControlLimits(void);  // @ 0x000422c0
void cm848_initEngineSpeedTracking(void);  // @ 0x00042438
void cm848_processSystemStatusLimits(void);  // @ 0x00042488
void cm848_processGovernorSpeedSetpoint(void);  // @ 0x0004256c
void cm848_enableProtectionRateLimit(void);  // @ 0x0004271c
void cm848_applyProtectionControlLimit(void);  // @ 0x0004272c
void cm848_setProtectionControlValue(void);  // @ 0x00042770
void cm848_copyProtectionAccumulator(void);  // @ 0x00042784
void cm848_applyProtectionTorqueLimit(void);  // @ 0x0004279c
void cm848_applySpeedControlProtectionLimit(void);  // @ 0x000427cc
void cm848_processProtectionLimits(void);  // @ 0x0004280c
void cm848_initProtectionTorqueLimit(void);  // @ 0x0004285c
void cm848_setEngineOperatingMode1(void);  // @ 0x00042894
void cm848_setEngineOperatingMode5(void);  // @ 0x000428d4
void cm848_resetEngineOperatingMode(void);  // @ 0x00042918
void cm848_dispatchModeHandlers(void);  // @ 0x00042978
void cm848_initProtectionParameter1(void);  // @ 0x000429a0
void cm848_processProtectionParameter1(void);  // @ 0x00042a2c
void cm848_initProtectionParameter2(void);  // @ 0x00042ab8
void cm848_processProtectionParameter2(void);  // @ 0x00042b44
void hpcr_cbdFillAccelerationBuffers(void);  // @ 0x00042bd0
void hpcr_processLoadThrottle(void);  // @ 0x00042cfc
void hpcr_cbdCalculateCylinderTrims(void);  // @ 0x00042d78
void hpcr_cbdInitFilterState(void);  // @ 0x00043a5c
void hpcr_processTimingCalibration(void);  // @ 0x00043ac0
void hpcr_clearTimingCalibrationData(void);  // @ 0x00043d68
void mpc555_resetEngineTimingAccumulators(void);  // @ 0x00043ddc
void mpc555_updateSensorDiagnosticFlags(void);  // @ 0x00044374
void cm848_setEngineRunState3(void);  // @ 0x00044aa4
void mpc555_evaluateProtectionThresholds(void);  // @ 0x00044ae0
void mpc555_initEngineCrankSequence(void);  // @ 0x00044b54
void mpc555_processProtectionConditions(void);  // @ 0x00044bf4
void cm848_setEngineCrankState1(void);  // @ 0x00044cc8
void cm848_setEngineRunState1(void);  // @ 0x00044d20
void cm848_engineRunState4Handler(void);  // @ 0x00044d70
void cm848_engineRunState3Handler(void);  // @ 0x00044dd0
void cm848_engineRunState4Conditional(void);  // @ 0x00044e3c
void cm848_engineRunState4Handler2(void);  // @ 0x00044eac
void cm848_protectionOverrideEvaluator(void);  // @ 0x00044f0c
void hpcr_processEngineSyncPulses(void);  // @ 0x00044fa8
void mpc555_updateEngineRunState(void);  // @ 0x00045478
void mpc555_updateEngineCrankState(void);  // @ 0x000457d0
void cm848_calculateFuelDemandWithConditions(void);  // @ 0x00045ecc
void cm848_initRpmSetpointFilters(void);  // @ 0x0004665c
void cm848_calculateGovernorOutput(void);  // @ 0x000466a8
void mpc555_initFuelFilterStates(void);  // @ 0x00046cf8
void mpc555_updateEngineStatusWord(undefined2 *param_1,ushort *param_2);  // @ 0x00046dc8
void cm848_clearTimingAccumulators(void);  // @ 0x00046f64
void cm848_calculateTimingWithTables(void);  // @ 0x00046f7c
void cm848_interpolateFuelTableValue(void);  // @ 0x00046fb4
void cm848_calculateEngineTimingInterpolation(void);  // @ 0x00047140
void cm848_processDualAxisLookup(void);  // @ 0x00047178
void cm848_calculateEngineFaultTiming(int param_1);  // @ 0x00047394
void cm848_validateSyncCount(void);  // @ 0x000473cc
void cm848_checkEngineSyncPulse(void);  // @ 0x000476d4
void mpc555_clearTimingDataAndFilters(void);  // @ 0x00047784
int cm848_protectionRecoveryHandler(int *param_1,int param_2);  // @ 0x00047838
int cm848_protectionModeSelector(int param_1,int *param_2,int param_3,uint param_4);  // @ 0x00047978
int cm848_protectionStateHandler(ushort *param_1,uint *param_2,int param_3);  // @ 0x00047a88
void cm848_calculateEngineTimingOffset(void);  // @ 0x00047bd0
void cm848_advanceSyncPointer(void);  // @ 0x00048fd8
void cm848_resetEngineSyncState(void);  // @ 0x00049004
void cm848_filterEngineSensorValue(void);  // @ 0x0004922c
void cm848_processEnginePositionDiagnostics(void);  // @ 0x00049264
void cm848_updateEngineDiagnosticCounters(void);  // @ 0x00049a54
void cm848_protectionInputValidator(void);  // @ 0x00049df0
void cm848_protectionSensorFaultHandler(void);  // @ 0x00049edc
void cm848_checkProtectionFaultConditions(void);  // @ 0x0004a114
void cm848_initEngineDiagnosticData(void);  // @ 0x0004a258
void mpc555_calculateTpuTimingPeriod(void);  // @ 0x0004a2f8
void mpc555_initTpuTimingInterrupts(void);  // @ 0x0004a37c
void cm848_processEnginePositionData(void);  // @ 0x0004a490
void cm848_processCommunicationDiagnostic(void);  // @ 0x0004a4c8
void cm848_updateEnginePositionErrors(void);  // @ 0x0004a748
void cm848_filterEnginePositionDelta(void);  // @ 0x0004a7ac
void cm848_initEnginePositionState(void);  // @ 0x0004a858
void cm848_updateEnginePosition(void);  // @ 0x0004a8cc
void cm848_updateProtectionBitFlags(uint param_1,int param_2);  // @ 0x0004a968
void cm848_protectionFaultEvaluator (uint param_1,ushort *param_2,int param_3,int param_4,int param_5);  // @ 0x0004aaac
void mpc555_evaluateProtectionSyncFaults(void);  // @ 0x0004ac3c
void cm848_evaluateProtectionSyncStateConditional(void);  // @ 0x0004ac74
void cm848_initTimingFilterStates(void);  // @ 0x0004ad8c
void cm848_calculateEngineTimingData(void);  // @ 0x0004ae20
void cm848_updateEngineStatusFlags(void);  // @ 0x0004b5b8
void cm848_calculateFuel2DTableLookup(void);  // @ 0x0004b6cc
void cm848_applyProtectionLimit(void);  // @ 0x0004b9ac
void cm848_processMemoryScanValidation(void);  // @ 0x0004ba48
void cm848_evaluateConditionDescriptor(void);  // @ 0x0004ba80
void cm848_copyRomToRamBuffer(void);  // @ 0x0004bd00
bool cm848_protectionEnableCheck(void);  // @ 0x0004bd3c
void cm848_protectionConditionMonitor(void);  // @ 0x0004bd5c
void cm848_initOutputChannels(void);  // @ 0x0004bd74
void cm848_sensorCalibrationCheck(void);  // @ 0x0004be4c
undefined4 cm848_validateMemoryBlockChecksum(short param_1,int param_2,uint param_3);  // @ 0x0004bf90
undefined1 cm848_validateEepromAddress(short *param_1);  // @ 0x0004bfc8
undefined4 cm848_updateProtectionTimers(short param_1,int param_2,uint param_3);  // @ 0x0004c070
undefined1 cm848_enqueueToCircularBuffer(undefined4 param_1,short *param_2);  // @ 0x0004c0a8
void cm848_protectionConfigSelector(void);  // @ 0x0004c188
void cm848_protectionLimitCalculator(void);  // @ 0x0004c2d4
void cm848_initProtectionLimitVariables(void);  // @ 0x0004c69c
void cm848_initProtectionLimitStateVariant(undefined2 param_1);  // @ 0x0004c6d4
void cm848_j1939ProtectionConfigResponse(void);  // @ 0x0004c734
void cm848_j1939ProtectionDataResponse(void);  // @ 0x0004c7ec
void cm848_validateSensorData(void);  // @ 0x0004c8d8
void cm848_initSensorValidationSystem(void);  // @ 0x0004cb64
void cm848_configureOutputChannels(void);  // @ 0x0004cb6c
void cm848_configureOutputChannelsStateParam(void);  // @ 0x0004cb84
void cm848_configureOutputChannelsAltState(void);  // @ 0x0004cb90
int cm848_getProtectionSyncState(void);  // @ 0x0004cd50
void cm848_initSensorRetryCounters(void);  // @ 0x0004ce78
void cm848_miosChannel11Enable(void);  // @ 0x0004ce9c
void cm848_miosChannel11ReadStatus(undefined4 param_1);  // @ 0x0004cec4
void cm848_miosChannel11SetPwm(undefined4 param_1);  // @ 0x0004cef0
void cm848_miosChannel12Enable(void);  // @ 0x0004cf1c
void cm848_miosChannel12ReadStatus(undefined4 param_1);  // @ 0x0004cf44
void cm848_miosChannel12SetPwm(undefined4 param_1);  // @ 0x0004cf70
void cm848_miosChannel13Enable(void);  // @ 0x0004cf9c
void cm848_miosChannel13ReadStatus(undefined4 param_1);  // @ 0x0004cfc4
void cm848_miosChannel13SetPwm(undefined4 param_1);  // @ 0x0004cff0
void cm848_miosChannel14Enable(void);  // @ 0x0004d01c
void cm848_miosChannel14ReadStatus(undefined4 param_1);  // @ 0x0004d044
void cm848_miosChannel14SetPwm(undefined4 param_1);  // @ 0x0004d070
void cm848_miosChannel15Enable(void);  // @ 0x0004d09c
void cm848_miosChannel15ReadStatus(undefined4 param_1);  // @ 0x0004d0c4
void cm848_miosChannel15SetPwm(undefined4 param_1);  // @ 0x0004d0f0
void cm848_miosChannel27Enable(void);  // @ 0x0004d11c
void cm848_miosChannel27ReadStatus(undefined4 param_1);  // @ 0x0004d144
void cm848_miosChannel27SetPwm(undefined4 param_1);  // @ 0x0004d170
void cm848_miosChannel28Enable(void);  // @ 0x0004d19c
void cm848_miosChannel28ReadStatus(undefined4 param_1);  // @ 0x0004d1c4
void cm848_miosChannel28SetPwm(undefined4 param_1);  // @ 0x0004d1f0
void cm848_miosChannel29Enable(void);  // @ 0x0004d21c
void cm848_miosChannel29ReadStatus(undefined4 param_1);  // @ 0x0004d244
void cm848_miosChannel29SetPwm(undefined4 param_1);  // @ 0x0004d270
void cm848_miosChannel30Enable(void);  // @ 0x0004d29c
void cm848_miosChannel30ReadStatus(undefined4 param_1);  // @ 0x0004d2c4
void cm848_miosChannel30SetPwm(undefined4 param_1);  // @ 0x0004d2f0
void cm848_miosChannel31Enable(void);  // @ 0x0004d31c
void cm848_miosChannel31ReadStatus(undefined4 param_1);  // @ 0x0004d344
void cm848_miosChannel31SetPwm(undefined4 param_1);  // @ 0x0004d370
void cm848_miosTimer0InitPeriod(void);  // @ 0x0004d39c
void cm848_miosTimer0ScaleByPercent(undefined4 param_1);  // @ 0x0004d3c4
void cm848_miosTimer0SetValue(undefined4 param_1);  // @ 0x0004d3f0
void cm848_miosTimer1InitPeriod(void);  // @ 0x0004d41c
void cm848_miosTimer1ScaleByPercent(undefined4 param_1);  // @ 0x0004d444
void cm848_miosTimer1SetValue(undefined4 param_1);  // @ 0x0004d470
void cm848_miosTimer2InitPeriod(void);  // @ 0x0004d49c
void cm848_miosTimer2ScaleByPercent(undefined4 param_1);  // @ 0x0004d4c4
void cm848_miosTimer2SetValue(undefined4 param_1);  // @ 0x0004d4f0
void cm848_miosTimer3InitPeriod(void);  // @ 0x0004d51c
void cm848_miosTimer3ScaleByPercent(undefined4 param_1);  // @ 0x0004d544
void cm848_miosTimer3SetValue(undefined4 param_1);  // @ 0x0004d570
void cm848_miosTimer16InitPeriod(void);  // @ 0x0004d59c
void cm848_miosTimer16ScaleByPercent(undefined4 param_1);  // @ 0x0004d5c4
void cm848_miosTimer16ScaleOutput(void);  // @ 0x0004d5d4
void cm848_miosTimer16SetValue(undefined4 param_1);  // @ 0x0004d5f0
void cm848_miosTimer16SetOutput(undefined4 param_1);  // @ 0x0004d5fc
void cm848_miosTimer17InitPeriod(void);  // @ 0x0004d61c
void cm848_miosTimer17InitPeriodAlt(void);  // @ 0x0004d628
void cm848_miosTimer17ScaleByPercent(undefined4 param_1);  // @ 0x0004d644
void cm848_miosTimer17ScaleDefault(void);  // @ 0x0004d654
void cm848_miosTimer17SetValue(undefined4 param_1);  // @ 0x0004d670
void cm848_miosTimer17SetValueAlt(undefined4 param_1);  // @ 0x0004d67c
void cm848_miosTimer18InitPeriod(void);  // @ 0x0004d69c
void cm848_miosTimer18InitPeriodAlt(void);  // @ 0x0004d6a8
void cm848_miosTimer18ScaleByPercent(undefined4 param_1);  // @ 0x0004d6c4
void cm848_miosTimer18ScaleDefault(void);  // @ 0x0004d6d4
void cm848_miosTimer18SetValue(undefined4 param_1);  // @ 0x0004d6f0
void cm848_miosTimer18SetValueAlt(undefined4 param_1);  // @ 0x0004d6fc
void cm848_miosTimer19InitPeriod(void);  // @ 0x0004d71c
void cm848_miosTimer19InitPeriodAlt(void);  // @ 0x0004d728
void cm848_miosTimer19ScaleByPercent(undefined4 param_1);  // @ 0x0004d744
void cm848_miosTimer19ScaleDefault(void);  // @ 0x0004d754
void cm848_miosTimer19SetValue(undefined4 param_1);  // @ 0x0004d770
void cm848_miosTimer19SetValueAlt(undefined4 param_1);  // @ 0x0004d77c
void cm848_tpuChannel0Reset(void);  // @ 0x0004d79c
void cm848_miosTimer20Configure(void);  // @ 0x0004d7a8
void cm848_tpuChannel0SetDuty(undefined4 param_1);  // @ 0x0004d7c0
void cm848_tpuChannel0Configure(undefined4 param_1);  // @ 0x0004d7e8
void cm848_tpuChannel1Reset(void);  // @ 0x0004d810
void cm848_tpuChannel1SetDuty(undefined4 param_1);  // @ 0x0004d834
void cm848_tpuChannel1Configure(undefined4 param_1);  // @ 0x0004d85c
void cm848_tpuChannel2Reset(void);  // @ 0x0004d884
void cm848_tpuChannel2SetDuty(undefined4 param_1);  // @ 0x0004d8a8
void cm848_tpuChannel2Configure(undefined4 param_1);  // @ 0x0004d8d0
void cm848_tpuChannel3Reset(void);  // @ 0x0004d8f8
void cm848_tpuChannel3SetDuty(undefined4 param_1);  // @ 0x0004d91c
void cm848_tpuChannel3Configure(undefined4 param_1);  // @ 0x0004d944
void cm848_tpuChannel4Reset(void);  // @ 0x0004d96c
void cm848_tpuChannel4SetDuty(undefined4 param_1);  // @ 0x0004d990
void cm848_tpuChannel4Configure(undefined4 param_1);  // @ 0x0004d9b8
void cm848_tpuChannel5Reset(void);  // @ 0x0004d9e0
void cm848_tpuChannel5SetDuty(undefined4 param_1);  // @ 0x0004da04
void cm848_tpuChannel5Configure(undefined4 param_1);  // @ 0x0004da2c
void cm848_tpuChannel6Reset(void);  // @ 0x0004da54
void cm848_tpuChannel6SetDuty(undefined4 param_1);  // @ 0x0004da78
void cm848_tpuChannel6Configure(undefined4 param_1);  // @ 0x0004daa0
void cm848_tpuChannel7Reset(void);  // @ 0x0004dac8
void cm848_tpuChannel7SetDuty(undefined4 param_1);  // @ 0x0004daec
void cm848_tpuChannel7Configure(undefined4 param_1);  // @ 0x0004db14
void cm848_tpuChannel8Reset(void);  // @ 0x0004db3c
void cm848_tpuChannel8SetDuty(undefined4 param_1);  // @ 0x0004db60
void cm848_tpuChannel8Configure(undefined4 param_1);  // @ 0x0004db88
void cm848_tpuChannel9Reset(void);  // @ 0x0004dbb0
void cm848_tpuChannel9SetDuty(undefined4 param_1);  // @ 0x0004dbd4
void cm848_tpuChannel9Configure(undefined4 param_1);  // @ 0x0004dbfc
void cm848_tpuChannel10Reset(void);  // @ 0x0004dc24
void cm848_tpuChannel10SetDuty(undefined4 param_1);  // @ 0x0004dc48
void cm848_tpuChannel10Configure(undefined4 param_1);  // @ 0x0004dc70
void cm848_tpuChannel11Reset(void);  // @ 0x0004dc98
void cm848_tpuChannel11SetDuty(undefined4 param_1);  // @ 0x0004dcbc
void cm848_tpuChannel11Configure(undefined4 param_1);  // @ 0x0004dce4
void cm848_tpuChannel12Reset(void);  // @ 0x0004dd0c
void cm848_tpuChannel12SetDuty(undefined4 param_1);  // @ 0x0004dd30
void cm848_tpuChannel12Configure(undefined4 param_1);  // @ 0x0004dd58
void cm848_tpuChannel13Reset(void);  // @ 0x0004dd80
void cm848_tpuChannel13SetDuty(undefined4 param_1);  // @ 0x0004dda4
void cm848_tpuChannel13Configure(undefined4 param_1);  // @ 0x0004ddcc
void cm848_tpuChannel14Reset(void);  // @ 0x0004ddf4
void cm848_tpuChannel14SetDuty(undefined4 param_1);  // @ 0x0004de18
void cm848_tpuChannel14Configure(undefined4 param_1);  // @ 0x0004de40
void cm848_tpuChannel15Reset(void);  // @ 0x0004de68
void cm848_tpuChannel15SetDuty(undefined4 param_1);  // @ 0x0004de8c
void cm848_tpuChannel15Configure(undefined4 param_1);  // @ 0x0004deb4
void cm848_disableMiosResetTpu14_10(void);  // @ 0x0004dedc
undefined2 cm848_setMiosDutyCycle14(void);  // @ 0x0004df0c
void cm848_configureTpuChannel10Alt(undefined4 param_1);  // @ 0x0004df40
void cm848_setTpuDutyWithTrack10(undefined4 param_1);  // @ 0x0004df68
void mpc555_resetMiosTpuChannel29_11(void);  // @ 0x0004df98
void cm848_disableMiosResetTpu11_4(void);  // @ 0x0004e0c0
undefined2 cm848_setMiosDutyCycle11(void);  // @ 0x0004e0f0
void cm848_configureTpuChannel4Alt(undefined4 param_1);  // @ 0x0004e124
void cm848_setTpuDutyWithTrack4(undefined4 param_1);  // @ 0x0004e14c
void cm848_disableMiosResetTpu13_6(void);  // @ 0x0004e180
undefined2 cm848_setMiosDutyCycle13(void);  // @ 0x0004e1b0
void cm848_configureTpuChannel6Alt(undefined4 param_1);  // @ 0x0004e1e4
void cm848_setTpuDutyWithTrack6(undefined4 param_1);  // @ 0x0004e20c
void cm848_disableMiosResetTpu12_7(void);  // @ 0x0004e240
undefined2 cm848_setMiosDutyCycle12(void);  // @ 0x0004e270
void cm848_configureTpuChannel7Alt(undefined4 param_1);  // @ 0x0004e2a4
void cm848_setTpuDutyWithTrack7(undefined4 param_1);  // @ 0x0004e2cc
void cm848_tpuOutput0Enable(void);  // @ 0x0004e300
void cm848_tpuOutput0Disable(undefined4 param_1);  // @ 0x0004e324
void cm848_tpuOutput0SetPeriod(undefined4 param_1);  // @ 0x0004e34c
void cm848_tpuOutput1Enable(void);  // @ 0x0004e374
void cm848_tpuOutput1Disable(undefined4 param_1);  // @ 0x0004e398
void cm848_tpuOutput1SetPeriod(undefined4 param_1);  // @ 0x0004e3c0
void cm848_tpuOutput2Enable(void);  // @ 0x0004e3e8
void cm848_tpuOutput2Disable(undefined4 param_1);  // @ 0x0004e40c
void cm848_tpuOutput2SetPeriod(undefined4 param_1);  // @ 0x0004e434
void cm848_tpuOutput3Enable(void);  // @ 0x0004e45c
void cm848_tpuOutput3Disable(undefined4 param_1);  // @ 0x0004e480
void cm848_tpuOutput3SetPeriod(undefined4 param_1);  // @ 0x0004e4a8
void cm848_tpuOutput4Enable(void);  // @ 0x0004e4d0
void cm848_tpuOutput4Disable(undefined4 param_1);  // @ 0x0004e4f4
void cm848_tpuOutput4SetPeriod(undefined4 param_1);  // @ 0x0004e51c
void cm848_tpuOutput5Enable(void);  // @ 0x0004e544
void cm848_tpuOutput5Disable(undefined4 param_1);  // @ 0x0004e568
void cm848_tpuOutput5SetPeriod(undefined4 param_1);  // @ 0x0004e590
void cm848_tpuOutput6Enable(void);  // @ 0x0004e5b8
void cm848_tpuOutput6Disable(undefined4 param_1);  // @ 0x0004e5dc
void cm848_tpuOutput6SetPeriod(undefined4 param_1);  // @ 0x0004e604
void cm848_tpuOutput7Enable(void);  // @ 0x0004e62c
void cm848_tpuOutput7Disable(undefined4 param_1);  // @ 0x0004e650
void cm848_tpuOutput7SetPeriod(undefined4 param_1);  // @ 0x0004e678
void cm848_tpuOutput8Enable(void);  // @ 0x0004e6a0
void cm848_tpuOutput8Disable(undefined4 param_1);  // @ 0x0004e6c4
void cm848_tpuOutput8SetPeriod(undefined4 param_1);  // @ 0x0004e6ec
void cm848_tpuOutput9Enable(void);  // @ 0x0004e714
void cm848_tpuOutput9Disable(undefined4 param_1);  // @ 0x0004e738
void cm848_tpuOutput9SetPeriod(undefined4 param_1);  // @ 0x0004e760
void cm848_tpuOutput10Enable(void);  // @ 0x0004e788
void cm848_tpuOutput10Disable(undefined4 param_1);  // @ 0x0004e7ac
void cm848_tpuOutput10SetPeriod(undefined4 param_1);  // @ 0x0004e7d4
void cm848_tpuOutput11Enable(void);  // @ 0x0004e7fc
void cm848_tpuOutput11Disable(undefined4 param_1);  // @ 0x0004e820
void cm848_tpuOutput11SetPeriod(undefined4 param_1);  // @ 0x0004e848
void cm848_tpuOutput12Enable(void);  // @ 0x0004e870
void cm848_tpuOutput12Disable(undefined4 param_1);  // @ 0x0004e894
void cm848_tpuOutput12SetPeriod(undefined4 param_1);  // @ 0x0004e8bc
void cm848_tpuOutput13Enable(void);  // @ 0x0004e8e4
void cm848_tpuOutput13Disable(undefined4 param_1);  // @ 0x0004e908
void cm848_tpuOutput13SetPeriod(undefined4 param_1);  // @ 0x0004e930
void cm848_tpuOutput14Enable(void);  // @ 0x0004e958
void cm848_tpuOutput14Disable(undefined4 param_1);  // @ 0x0004e97c
void cm848_tpuOutput14SetPeriod(undefined4 param_1);  // @ 0x0004e9a4
void cm848_tpuOutput15Enable(void);  // @ 0x0004e9cc
void cm848_tpuOutput15Disable(undefined4 param_1);  // @ 0x0004e9f0
void cm848_tpuOutput15SetPeriod(undefined4 param_1);  // @ 0x0004ea18
void cm848_orBitsInArray(undefined4 param_1,undefined4 param_2,byte *param_3);  // @ 0x0004ea78
void cm848_clearBitsInArray(undefined4 param_1,undefined4 param_2,byte *param_3);  // @ 0x0004eabc
byte cm848_checkProtectionWarningBitState(uint param_1);  // @ 0x0004eac8
byte cm848_checkProtectionBitWarningState(undefined4 param_1,byte param_2);  // @ 0x0004eb00
void mpc555_updateEngineCycleOutputs(void);  // @ 0x0004eb48
void hpcr_initProtectionAndOutputCycle(void);  // @ 0x0004eeb8
void cm848_setEngineProtectionFault(uint param_1,int param_2);  // @ 0x0004ef24
void setBitInArray(int param_1,undefined4 param_2,byte *param_3);  // @ 0x0004ef5c
void cm848_clearProtectionFault(uint param_1);  // @ 0x0004ef74
void cm848_dispatchSyncUpdateByFlag(void);  // @ 0x0004efac
void cm848_triggerProtectionEvent(uint param_1,int param_2);  // @ 0x0004f000
void cm848_clearEventFlag(int param_1,undefined4 param_2,byte *param_3);  // @ 0x0004f038
void cm848_protectionFlagManager(uint param_1);  // @ 0x0004f050
void cm848_conditionalSyncFlagUpdate(void);  // @ 0x0004f088
void cm848_checkProtectionModeFlags(void);  // @ 0x0004f0dc
void cm848_protectionAlarmHandler(void);  // @ 0x0004f190
void cm848_processProtectionFaultsAndTiming(void);  // @ 0x0004f2b0
undefined4 hpcr_protectionWarningHandler(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4);  // @ 0x0004f2ec
undefined4 hpcr_evaluateHardwareTimerState(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4);  // @ 0x0004f324
void clearModuleSyncFlag(uint param_1);  // @ 0x0004f6f0
void updateEngineSyncStatus(uint param_1);  // @ 0x00051038
void injectorTimingCalculation(void);  // @ 0x000529b8
void hpcr_injectorPulseWidthCalc(void);  // @ 0x000533e0
void mpc555_processJ1939TxBufferSend(void);  // @ 0x000535e8
void mpc555_queueCanReceiveMessage(int param_1);  // @ 0x00053720
void mpc555_sendJ1939SingleFrame(uint param_1,uint param_2,int param_3,undefined1 *param_4);  // @ 0x00053858
void mpc555_enqueueCanTransmitFrame(uint param_1,uint param_2,int param_3);  // @ 0x00053890
void sendJ1939MultiFrame(undefined4 *param_1);  // @ 0x000539fc
void cm848_validateDiagnosticResponseWrapper(void);  // @ 0x00053a34
undefined4 cm848_lookupJ1939SourceAddressIndex(uint param_1);  // @ 0x00053a4c
void cm848_handleCanMailboxTransmitComplete(uint param_1);  // @ 0x00053aa8
void cm848_handleCanMailboxTransmitRange(int param_1);  // @ 0x00053ae0
void cm848_writeCanControllerTxMailbox(int param_1,int param_2,int param_3);  // @ 0x00053b28
void mpc555_canTransmitInterruptHandler(void);  // @ 0x00053b68
void cm848_emptyStub3(void);  // @ 0x00053c60
void cm848_emptyStub4(void);  // @ 0x00053c64
undefined4 cm848_findJ1939MessageEntry(int param_1,uint param_2,int param_3);  // @ 0x00053c68
undefined4 cm848_addCoolantCalEntry(uint param_1,int param_2);  // @ 0x00053cd8
void cm848_addCoolantCalEntry(undefined2 param_1,undefined1 param_2,undefined2 param_3);  // @ 0x00053d3c
void cm848_setDefaultCalibrationValue(void);  // @ 0x00053d74
void cm848_addCoolantCalEntryAlt(undefined1 param_1,undefined2 param_2);  // @ 0x00053d84
void cm848_processCoolantCalEntries(void);  // @ 0x00053dc8
void cm848_removeCoolantCalEntryByParams(int param_1,uint param_2);  // @ 0x00053fa8
void cm848_removeCalibrationListEntry (int param_1,uint param_2,int param_3,byte *param_4,uint param_5,short *param_6);  // @ 0x00053fe0
void cm848_removeCoolantCalEntry(uint param_1);  // @ 0x00054064
void mpc555_miosInterruptDispatcher(void);  // @ 0x00054100
void mpc555_infiniteLoopHalt(void);  // @ 0x0005419c
void mpc555_enableSchedulerMiosOutput(void);  // @ 0x000541f4
void cm848_emptyStubFunction(void);  // @ 0x00054220
void cm848_checkRpmOverspeedProtection(void);  // @ 0x00054224
void mpc555_systemStartupInitialization(undefined2 param_1);  // @ 0x00054380
void hpcr_exceptionHandler(void);  // @ 0x000544c4
undefined4 cm848_miosSetChannelDutyCycle(int *param_1,int param_2);  // @ 0x00054e10
void cm848_miosChannelDisable(int param_1);  // @ 0x00054eac
void cm848_miosChannelEnable(int param_1);  // @ 0x00054eb8
void mpc555_miosReadChannelStatus(undefined4 *param_1,ushort param_2);  // @ 0x00054ec4
void mpc555_miosSetPwmOutput(undefined4 param_1,uint param_2);  // @ 0x00054f48
void cm848_miosInitChannelPeriod(int param_1);  // @ 0x00054f80
void cm848_scalePwmByPercent(ushort *param_1,ushort param_2);  // @ 0x00054f8c
void cm848_miosSetChannelValue(undefined2 *param_1,uint param_2);  // @ 0x00054fb8
void mpc555_tpuResetChannel(uint param_1);  // @ 0x00055020
void cm848_tpuSetChannelDuty(int param_1,ushort param_2);  // @ 0x00055178
void cm848_tpuConfigureChannel(int param_1,uint param_2);  // @ 0x000551e4
void mpc555_tpuEnableChannelOutput(uint param_1);  // @ 0x00055294
void cm848_tpuDisableChannelOutput(int param_1,ushort param_2);  // @ 0x000553ec
void cm848_tpuSetChannelPeriod(int param_1,uint param_2);  // @ 0x00055458
void initQadcModule(void);  // @ 0x00055500
void cm848_copyDataBuffer(int param_1,int param_2);  // @ 0x000555cc
undefined4 cm848_processSecurityCodeConversion(undefined4 param_1);  // @ 0x0005573c
undefined4 cm848_validateSecurityCode(void);  // @ 0x0005576c
void cm848_processEngineRpmDiagnostic(void);  // @ 0x0005586c
void cm848_dispatchCalibrationFunctions(void);  // @ 0x00055a40
void mpc555_initTpuConfiguration(void);  // @ 0x00055c1c
void mpc555_tpuBInterruptDispatcher(void);  // @ 0x00055d2c
void mpc555_tpuAInterruptDispatcher(void);  // @ 0x00055de4
void cm848_emptyStubFunction(void);  // @ 0x00055e9c
uint cm848_calculateCrc16 (int param_1,byte *param_2,uint param_3,int param_4,uint param_5,undefined4 param_6, undefined4 param_7,uint param_8);  // @ 0x00055ed0
uint lookupTableInterpolation(ushort *param_1,uint param_2,ushort *param_3,int param_4,uint param_5);  // @ 0x00055ef4
uint cm848_linearInterpolate1D (ushort param_1,short param_2,int param_3,int param_4,uint param_5,ushort *param_6);  // @ 0x00055f24
void cm848_extendedDivisionWithRemainder (uint param_1,uint param_2,uint param_3,uint *param_4,int *param_5);  // @ 0x00056184
int cm848_signedDivisionWithSaturation(uint param_1,int param_2);  // @ 0x00056260
int cm848_clampedDivisionWithBounds(uint param_1,int param_2,int param_3,int param_4);  // @ 0x000562fc
void cm848_noOperation2(void);  // @ 0x0005632c
void cm848_noOperation2(void);  // @ 0x000563e4
uint cm848_saturatingDivision16(uint param_1,uint param_2);  // @ 0x000563e8
int cm848_signedFirstOrderFilter(int param_1,undefined4 *param_2);  // @ 0x0005644c
int cm848_signedFilterWithWeight (uint param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6);  // @ 0x0005647c
int cm848_signedFilterWithWeight (uint param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6);  // @ 0x00056488
int cm848_secondOrderFilter(short param_1,undefined4 *param_2);  // @ 0x000564c0
int cm848_multiplyAccumulateFixed32(short param_1,int param_2);  // @ 0x000564f0
uint exponentialMovingAverage(uint param_1,undefined4 *param_2);  // @ 0x00056594
uint cm848_filterWithWeight (uint param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6);  // @ 0x000565c4
uint cm848_filterWithWeight (uint param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6);  // @ 0x000565d0
undefined4 cm848_lookupTableByIndex(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5);  // @ 0x00056638
uint cm848_dualAxisTableInterpolation(void *table_descriptor,word x_input,word y_input);  // @ 0x000566cc
uint cm848_interpolateWithIndex (ushort *param_1,uint param_2,int param_3,uint param_4,ushort *param_5,int param_6);  // @ 0x000566fc
undefined4 cm848_ringBufferWriteByte(int *param_1,undefined1 param_2);  // @ 0x00056c80
void cm848_ringBufferInit(int *param_1,int param_2,int param_3);  // @ 0x00056d38
void cm848_memcpyBytes(int param_1,int param_2,int param_3);  // @ 0x00056d58
void cm848_delayMicroseconds(int param_1);  // @ 0x00056d88
void cm848_waitForTimeBaseTicks(int param_1,uint param_2);  // @ 0x00056db8
void cm848_delayMicroseconds2(int param_1);  // @ 0x00056e0c
void cm848_waitForTimeBaseDelay(int param_1,uint param_2);  // @ 0x00056e3c
void cm848_unsignedDivision64by32(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4);  // @ 0x00056e90
void cm848_signedDivision32(undefined4 param_1,undefined4 param_2,int param_3,int param_4);  // @ 0x000570f0
void cm848_signedDivision64(int param_1,undefined4 param_2,int param_3,int param_4);  // @ 0x00057120
void cm848_unsignedDivision32(undefined4 param_1,undefined4 param_2,int param_3,int param_4);  // @ 0x000571b0
void cm848_unsignedDivision64Wrapper(void);  // @ 0x000571e0
void cm848_mathMultiplyDivide32(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4);  // @ 0x00057204
void cm848_conditionalMultiplyDivide(undefined4 param_1,undefined4 param_2,int param_3,int param_4);  // @ 0x00057498
void emptyStubFunction2(void);  // @ 0x00057520
void cm848_calibrationTableLookup1D(void);  // @ 0x00057524
void cm848_saveRegistersToStack(void);  // @ 0x0005759c
void cm848_calibrationTableLookup2D(void);  // @ 0x000575a0
void cm848_invalidInstructionData(void);  // @ 0x0006432c
void cm848_initCanMailboxFilters_ram(void);  // @ 0x003fa2f0
void cm848_initFlashMemoryConfig_ram(void);  // @ 0x003fa5a0
void cm848_can2TransmitInterruptHandler_ram(void);  // @ 0x003fab3c
void cm848_dispatchCanMessageHandlers_ram(void);  // @ 0x003fae3c
void cm848_getServiceDataOffset_ram(void);  // @ 0x003fb528
void cm848_validateServiceDataLength_ram(void);  // @ 0x003fb54c
void cm848_processJ1939QueueStatus_ram(void);  // @ 0x003fc094
void cm848_initDiagnosticBuffers_ram(void);  // @ 0x003fc0d8
void cm848_serialReceiveHandler_ram(void);  // @ 0x003fc380
void cm848_serialTransmitHandler_ram(void);  // @ 0x003fc484
void cm848_validateSerialChecksum_ram(void);  // @ 0x003fc580
void cm848_initSerialTransmit_ram(void);  // @ 0x003fc62c
void cm848_eepromPollReady(void);  // @ 0x003fc688
void cm848_eepromCheckStatus(void);  // @ 0x003fc6f4
void cm848_eepromWaitCycle(void);  // @ 0x003fc77c
void cm848_processMainLoop_ram(void);  // @ 0x003fc874
void cm848_sendEepromVersionResponse_ram(void);  // @ 0x003fc9ec
void cm848_handleEepromDiagnosticResponse_ram(void);  // @ 0x003fca7c
void cm848_processEepromDataTransfer_ram(void);  // @ 0x003fcb24
void cm848_processSensorFilterChain_ram(void);  // @ 0x003fd070
void cm848_processSensorWithOverride_ram(void);  // @ 0x003fd1ac
void cm848_watchdogTimerTick_ram(void);  // @ 0x003fd1d8
void cm848_watchdogTimerTick_midEntry_ram(void);  // @ 0x003fd284
void cm848_sensorFaultThresholdCheck_ram(void);  // @ 0x003fd298
void cm848_eepromCompleteOperation(void);  // @ 0x003fd544
void cm848_initQspiHardware_ram(void);  // @ 0x003fd6d8
void cm848_systemHaltLoop_ram(void);  // @ 0x003fd994
void cm848_FUN_0040a046(void);  // @ 0x0040a046
void cm848_sensorChannel0_init(void);  // @ 0x00500004
void cm848_sensorChannel0_process(void);  // @ 0x00500090
void cm848_sensorChannel1_init(void);  // @ 0x0050011c
void cm848_sensorChannel1_process(void);  // @ 0x005001a8
void cm848_sensorChannelConfigInit (int param_1,undefined2 *param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6,int param_7,uint param_8,uint param_9, uint param_10,undefined2 *param_11,undefined2 *param_12,undefined2 *param_13);  // @ 0x00500234
void cm848_updateSensorChannelWithConfig (int param_1,undefined2 *param_2,undefined2 *param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6,int *param_7,uint param_8,uint param_9, uint param_10,undefined2 *param_11,undefined2 *param_12,undefined2 *param_13);  // @ 0x00500a4c
void cm848_sensorChannelCalibration_init(void);  // @ 0x005011c4
void cm848_sensorChannelCalibration_process(void);  // @ 0x00501250
void cm848_sensorChannelTypeB_configInit (int param_1,undefined2 *param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6,int param_7,uint param_8,uint param_9, uint param_10,undefined2 *param_11,undefined2 *param_12,undefined2 *param_13);  // @ 0x005012dc
void cm848_updateSensorChannelTypeB (int param_1,undefined2 *param_2,undefined2 *param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6,int *param_7,uint param_8,uint param_9, uint param_10,undefined2 *param_11,undefined2 *param_12,undefined2 *param_13);  // @ 0x00501b4c
void mpc555_evaluateSensorChannelStatus(void);  // @ 0x005022cc
void cm848_updateSensorModeState(void);  // @ 0x0050241c
void cm848_processSensorInterpolationMode(void);  // @ 0x00502464
void cm848_limitFuelDemandValue(void);  // @ 0x00502af4
void cm848_clearBufferInitFlag(void);  // @ 0x00502b24
void mpc555_initSensorBufferValues(void);  // @ 0x00502b34
void cm848_filterAndInterpolateSensor(void);  // @ 0x00502b6c
void cm848_initAndFilterSensor(void);  // @ 0x00502eb8
void cm848_initGovernorModeState(int param_1);  // @ 0x00503074
void cm848_clearProtectionModeVariables(void);  // @ 0x005031b4
void cm848_evaluateSpeedControlTiming(void);  // @ 0x005033a0
void cm848_evaluateSpeedModeConditions(void);  // @ 0x00503604
void cm848_evaluateFuelConditionFlags(void);  // @ 0x0050370c
void cm848_normalizeSpeedValue(void);  // @ 0x00503790
void cm848_resetSpeedControlState(void);  // @ 0x00503960
void cm848_processSpeedControlPipeline(void);  // @ 0x00503964
void cm848_initSpeedControlSystem(void);  // @ 0x0050398c
void cm848_interpolateSpeedControl6Point(void);  // @ 0x005039b4
void cm848_initializeSpeedIntegratorStates(void);  // @ 0x00503b2c
void cm848_calculateLoadNormalizationDelta(void);  // @ 0x00503b54
void cm848_calculateSpeedFilterTerm(void);  // @ 0x00503cbc
void cm848_calculateSpeedOffsetTerm(void);  // @ 0x00503ed0
void cm848_calculateSpeedFilterCoefficients(void);  // @ 0x00503f60
void cm848_interpolateSpeedControlOutput(void);  // @ 0x00503f84
void cm848_initializeSpeedControlOutputs(void);  // @ 0x00504110
void mpc555_calculateFuelTimingGain(void);  // @ 0x00504130
void cm848_interpolateFuelTrimPrimary(void);  // @ 0x005041bc
void cm848_calculateFuelScaleMultiplier(void);  // @ 0x0050422c
void cm848_interpolateFuelTrimSecondary(void);  // @ 0x005043b4
void cm848_calculateFuelTrimAdjustments(void);  // @ 0x00504528
void cm848_calculatePressureRatio(void);  // @ 0x00504654
void mpc555_initPressureBufferValues(void);  // @ 0x00504754
void cm848_selectMaximumPressureValue(void);  // @ 0x0050477c
void cm848_clearPressureAccumulator(void);  // @ 0x00504938
void cm848_processFuelControlCoordinator(void);  // @ 0x00504948
void cm848_interpolateBoostTrimCalibration(void);  // @ 0x00504994
void cm848_interpolateBoostTrimTable(void);  // @ 0x00504b0c
void cm848_interpolateFuelTrimTable(void);  // @ 0x00504d38
void cm848_interpolateCoolantTrimTable(void);  // @ 0x00504eb0
void cm848_processPressureAndTemperatureTrim(void);  // @ 0x005050f4
void cm848_packFuelControlStatusFlags(void);  // @ 0x00505260
void cm848_calculateFuelBlendMode(void);  // @ 0x0050530c
void cm848_clearFuelBlendFactor1(void);  // @ 0x005053d0
void cm848_updateFuelTrimAccumulator(void);  // @ 0x005053e0
void cm848_clearFuelAccumulatorBuffers(void);  // @ 0x00505574
void cm848_validatePressureEnableConditions(void);  // @ 0x005055a0
void cm848_evaluateEngineSpeedMode(void);  // @ 0x00505600
void cm848_evaluateCoolantTemperatureMode(void);  // @ 0x005056f8
void cm848_initPressureBufferPointer(void);  // @ 0x005057dc
void cm848_evaluateEngineLoadConditions(void);  // @ 0x005057ec
void cm848_calculateFuelConsumptionRate(void);  // @ 0x005058a8
void mpc555_evaluateThrottleSensorConditions(void);  // @ 0x005059ec
void cm848_processThrottlePositionState(void);  // @ 0x00505b3c
void cm848_selectSpeedControlFromSensorFlags(void);  // @ 0x00505b84
void cm848_updateSpeedControlState(void);  // @ 0x00505bd8
void cm848_transferEepromData(void);  // @ 0x00505c20
void cm848_initEepromTransferState(void);  // @ 0x00505d94
void cm848_processDiagnosticDataTransfer(void);  // @ 0x00505df0
void cm848_processProtectionParameterData(int param_1);  // @ 0x00505f98
void cm848_processFuelBlendCalculations(void);  // @ 0x0050638c
void cm848_incrementFuelAndSpeedCounters(void);  // @ 0x00506780
void cm848_restoreFuelAndSpeedCounters(void);  // @ 0x005067bc
void cm848_calculateSignedRatioDivision(void);  // @ 0x005067e0
void cm848_calculateDivisionWithReset(void);  // @ 0x00506968
void cm848_calculateTimingFloorDivision(void);  // @ 0x00506a3c
void cm848_calculateTimingFloorDivisionB(void);  // @ 0x00506a64
void cm848_calculateTimingOffsetWithFilter(void);  // @ 0x00506ad4
void cm848_calculateFuelTimingWithFilter(undefined4 param_1,short param_2);  // @ 0x00506b34
void cm848_interpolateFuelTimingWithCheck(void);  // @ 0x00506cd4
void cm848_selectFuelTimingSourceByFlag(void);  // @ 0x00506e18
void cm848_selectFuelTimingMode(void);  // @ 0x00506e28
void cm848_updateFuelTimingInterpolation(void);  // @ 0x00506e64
void cm848_filterPressureAdjustmentWithFlags(void);  // @ 0x00506ec0
void cm848_evaluatePressureRampConditions(ushort param_1);  // @ 0x00506f68
void cm848_processPressureRampControl(void);  // @ 0x00507040
void cm848_clearPressureModeFlags(void);  // @ 0x005071b8
void cm848_clearPressureModeFlagAtOffset(void);  // @ 0x005071dc
void cm848_calculatePressureDeltaAndUpdate(void);  // @ 0x005071f4
void cm848_initPressureControlState(void);  // @ 0x00507264
void cm848_interpolateLoadNormalizationMap(void);  // @ 0x00507340
void cm848_interpolateTemperatureScale(void);  // @ 0x005073f4
void cm848_updateLoadAndTemperatureScales(void);  // @ 0x005074a8
void cm848_interpolateAuxiliaryParameter(void);  // @ 0x00507504
void cm848_interpolateFuelInjectionParam(void);  // @ 0x00507548
void cm848_updateFuelInjectionMinimumValues(void);  // @ 0x00507644
void cm848_processFuelInjectionControl(void);  // @ 0x005076cc
void cm848_calculateInjectionScaledDivision(void);  // @ 0x005077fc
void hpcr_dispatchMultiPhaseStateMachine(void);  // @ 0x005078f0
ushort cm848_calculateRampAdjustment(int param_1,int param_2,ushort *param_3,int param_4);  // @ 0x005079fc
ushort cm848_adjustParameterWithRampLimit(int param_1,undefined4 param_2,ushort param_3,int param_4);  // @ 0x00507a20
undefined2 cm848_interpolate2DTable(int param_1,int param_2,short param_3);  // @ 0x00507a6c
void cm848_initProtectionLimiterState(void);  // @ 0x00507acc
undefined4 cm848_evaluateFlagCondition(ushort *param_1,undefined4 *param_2,int param_3,int param_4);  // @ 0x00507b68
void cm848_emptyStub_reserved507c1c(void);  // @ 0x00507c1c
undefined4 cm848_dispatchByParamMode (int param_1,int param_2,undefined4 param_3,int param_4,uint param_5,int param_6);  // @ 0x00507c44
void protectionState0FaultDurationCounter(void);  // @ 0x00507cd8
void hpcr_evaluatehpcr_CbdSensorActivation(void);  // @ 0x00507ddc
void cm848_processLimitPriorityConditions(void);  // @ 0x00507e20
void cm848_clearProtectionStatusFlags(void);  // @ 0x00507f9c
void cm848_evaluateLimitConditionByFlag(ushort *param_1,undefined4 *param_2,int param_3);  // @ 0x00507fd8
void cm848_checkLimitBoundaryCondition(int param_1,int param_2,int param_3);  // @ 0x005080b4
void cm848_iterateAndApplyLimitConditions(void);  // @ 0x00508160
void cm848_calculateTorqueLimiterRamp(void);  // @ 0x005082b8
void cm848_processSensorBitmapConditions(void);  // @ 0x005082f0
void cm848_initTorqueLimitState(void);  // @ 0x00508490
void incrementDiagnosticCounters(int param_1,int param_2,int param_3);  // @ 0x005084e0
void processDiagnosticLimitStatus(void);  // @ 0x00508544
void cm848_resetFuelEfficiencyTrimState(void);  // @ 0x00508a94
void cm848_setFuelEfficiencyTrimFlag(void);  // @ 0x00508b8c
void cm848_clearBoostRequestFlag(void);  // @ 0x00508bb8
undefined4 cm848_evaluateBoundaryCondition(int param_1,int param_2,uint param_3);  // @ 0x00508bd0
void protectionStateProcessor(int param_1);  // @ 0x00508c10
void protectionStateValidator(int param_1);  // @ 0x00508da8
void cm848_clearSensorChannelFaultBits(void);  // @ 0x00508de8
void cm848_updateSensorBitmapAndPointer(void);  // @ 0x00508e78
void cm848_calculateSubtractionWithProduct(void);  // @ 0x00508f0c
void cm848_handleEventCaptureAndSnapshot(void);  // @ 0x00508f24
void cm848_calculatePrimaryFuelAdjustment(void);  // @ 0x005091ec
void cm848_initFuelAdjustmentState(void);  // @ 0x005094c0
void mpc555_evaluateDiagnosticLoadConditions(undefined2 param_1);  // @ 0x00509510
void cm848_copyBufferAndUpdateJ1939Addresses (int param_1,int param_2,int param_3,int param_4,uint param_5,int param_6);  // @ 0x00509848
undefined4 cm848_updateOutputControlMask(int param_1,int param_2);  // @ 0x00509894
undefined1 cm848_updateOutputControlMaskIndex4(undefined4 param_1);  // @ 0x00509990
undefined1 cm848_updateOutputControlMaskIndex5(undefined4 param_1);  // @ 0x005099b8
void cm848_registerOutputControlOperations(void);  // @ 0x005099e0
void cm848_emptyStub_noOp(void);  // @ 0x00509a2c
void cm848_clearBitmapFlag(uint param_1);  // @ 0x00509a44
void cm848_storeIndirectValue(undefined4 param_1,undefined4 *param_2);  // @ 0x00509a7c
void cm848_clearTertiaryBitmapFlag(uint param_1);  // @ 0x00509a84
void cm848_clearSecondaryBitmapFlag(uint param_1);  // @ 0x00509ac4
undefined2 cm848_isAnyPrimaryFlagSet(void);  // @ 0x00509b04
undefined2 cm848_checkTertiaryBitmapFlagStatus(void);  // @ 0x00509b44
int cm848_pollUntilConditionMet(int *param_1,short param_2,short param_3);  // @ 0x00509b5c
int cm848_searchArrayForNonZero(int param_1,short param_2,uint param_3);  // @ 0x00509b74
undefined2 cm848_isAnySecondaryFlagSet(void);  // @ 0x00509b84
void cm848_setBitmapFlag(uint param_1);  // @ 0x00509bc4
void cm848_setPrimaryBitmapFlag(uint param_1);  // @ 0x00509c00
void cm848_setSecondaryBitmapFlag(uint param_1);  // @ 0x00509c3c
void cm848_handleIdleSpeedControlFlag(void);  // @ 0x00509c78
void cm848_processBoostPressureOffset(void);  // @ 0x00509d78
void cm848_updateIdleControlStateAndBitmap(void);  // @ 0x00509e60
void cm848_detectEngineStateTransition(void);  // @ 0x00509f78
void cm848_evaluateIdleDiagCondition(uint param_1,uint param_2);  // @ 0x0050a14c
void cm848_evaluateIdleCondition(int param_1);  // @ 0x0050a228
void cm848_processIdleControlLoop(void);  // @ 0x0050a3ac
void cm848_resetIdleStateFlags(void);  // @ 0x0050a680
void cm848_idleDiagnosticProcessor(void);  // @ 0x0050a854
void cm848_idleControlMaster(void);  // @ 0x0050a9c8
void cm848_resetGovernorDiagnosticState(undefined2 *param_1);  // @ 0x0050aba8
undefined4 cm848_processServiceRequest(int param_1,undefined *param_2,uint param_3);  // @ 0x0050ac04
undefined4 cm848_validateServiceRequestAddress(void);  // @ 0x0050ad1c
undefined1 cm848_returnZeroStub(undefined4 param_1,undefined1 param_2);  // @ 0x0050ae4c
void cm848_emptyStub_reserved50ae5c(void);  // @ 0x0050ae5c
uint cm848_readParameterWithOffset (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4);  // @ 0x0050ae64
void cm848_emptyStub_phaseGroupA(void);  // @ 0x0050aec0
undefined1 cm848_readParameterByteOffset(int param_1);  // @ 0x0050aed4
undefined1 cm848_readParameterDwordOffset(int param_1);  // @ 0x0050af44
undefined1 cm848_readParameterWordOffset(int param_1);  // @ 0x0050afac
undefined1 cm848_readParameterDwordDualOffset(int param_1);  // @ 0x0050b038
undefined1 cm848_readParameterDwordImmediate(int param_1);  // @ 0x0050b0b4
undefined1 cm848_readParameterDwordImmediateDual(int param_1);  // @ 0x0050b120
void cm848_registerReadServiceHandlers(void);  // @ 0x0050b184
undefined4 byteSwap32(undefined4 *param_1);  // @ 0x0050b200
undefined2 byteSwap16(undefined2 *param_1);  // @ 0x0050b238
undefined1 cm848_getServiceDataLength(int param_1);  // @ 0x0050b2bc
undefined4 cm848_validateDiagnosticServiceRequest(int param_1);  // @ 0x0050b2e0
void mpc555_processIdleControlStateUpdate(int param_1,undefined4 param_2,int param_3);  // @ 0x0050b554
void mpc555_extractJ1939MessageFields(int param_1,uint param_2,int param_3);  // @ 0x0050b58c
void mpc555_updateIdleStateVariables(int param_1,uint param_2,int param_3);  // @ 0x0050b5b4
void cm848_emptyStub_reserved50b634(void);  // @ 0x0050b634
void cm848_registerDiagnosticDataRecords(void);  // @ 0x0050ba78
void cm848_enqueueDiagnosticRecord(int param_1);  // @ 0x0050bb18
void cm848_initDiagnosticBuffer(int param_1);  // @ 0x0050bb98
void cm848_processDiagnosticStateChanges(void);  // @ 0x0050bca0
undefined4 cm848_prepareParameterResponseFrame(byte *param_1);  // @ 0x0050bfc4
undefined4 cm848_sendParameterCanResponse(void);  // @ 0x0050bff4
void cm848_registerWriteServiceHandlers(void);  // @ 0x0050c0ac
char cm848_processResponseFrame(byte *param_1,uint param_2,uint param_3);  // @ 0x0050c0d8
undefined1 cm848_writeParameterWithOffset(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4);  // @ 0x0050c27c
undefined1 cm848_writeParameterDwordOffset(int param_1);  // @ 0x0050c2ec
undefined1 cm848_writeParameterWordOffset(int param_1);  // @ 0x0050c354
undefined1 cm848_writeParameterDwordDualOffset(int param_1);  // @ 0x0050c3e0
undefined1 cm848_writeParameterDwordImmediate(int param_1);  // @ 0x0050c45c
undefined1 cm848_writeParameterDwordImmediateDual(int param_1);  // @ 0x0050c4c8
void cm848_registerWriteServiceDispatch(void);  // @ 0x0050c52c
void cm848_j1939TransportProtocolRequestHandler(uint *param_1);  // @ 0x0050c598
void cm848_j1939TransportContinueTransmit(void);  // @ 0x0050c640
void cm848_processJ1939DataBlock(int param_1);  // @ 0x0050c8c4
void cm848_validateJ1939PacketBounds(int param_1,int param_2,uint param_3,char *param_4);  // @ 0x0050c8ec
void cm848_sendJ1939StatusMessage(undefined1 param_1,undefined2 param_2);  // @ 0x0050c968
void cm848_j1939SendStatusMessage(undefined1 param_1,undefined2 param_2);  // @ 0x0050ca00
undefined1 cm848_prepareJ1939StatusData (undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined2 param_4);  // @ 0x0050caa8
void cm848_j1939ProcessIncomingMessage(undefined4 *param_1);  // @ 0x0050cb3c
void cm848_j1939ProcessDataContinuation(int param_1);  // @ 0x0050cc54
void cm848_j1939ProcessAcknowledge(int param_1);  // @ 0x0050cdf0
void cm848_j1939ProcessAbort(int param_1);  // @ 0x0050ce58
void cm848_j1939DispatchMessageByType(int param_1);  // @ 0x0050cefc
void cm848_processTransmitBufferData(int param_1);  // @ 0x0050cf6c
void cm848_j1939TransmitDataFrames(void);  // @ 0x0050d0f0
void cm848_j1939DecrementTimeout(void);  // @ 0x0050d284
void cm848_j1939ProcessTransmitQueue(void);  // @ 0x0050d2b8
undefined * cm848_allocateDiagnosticBuffer(int param_1);  // @ 0x0050d334
void cm848_registerJ1939MessageHandlers(void);  // @ 0x0050d3ac
undefined1 cm848_getMemoryRegionAccessCode(uint param_1,int param_2);  // @ 0x0050d430
void mpc555_filterGovernorState(void);  // @ 0x0050d510
void cm848_calculateGovernorSpeedFiltered (undefined4 param_1,undefined2 *param_2,undefined4 param_3,undefined2 param_4, ushort *param_5);  // @ 0x0050d60c
void cm848_calculateGovernorSpeedOutput(void);  // @ 0x0050d688
void cm848_captureCrankPositionState(void);  // @ 0x0050d728
void cm848_initiateGovernorMode(int param_1);  // @ 0x0050d758
void cm848_checkGovernorModeAndCaptureCrank(int param_1,undefined4 param_2,undefined2 *param_3);  // @ 0x0050d784
void cm848_interpolateSpeedParameter(void);  // @ 0x0050d854
void cm848_interpolateSpeedProtectionTable(void);  // @ 0x0050d864
void cm848_setOperationalModeState(int param_1);  // @ 0x0050da60
void cm848_storeOperationalModeValue(void);  // @ 0x0050daac
void cm848_calculateSpeedRatio(void);  // @ 0x0050db00
void calculateSpeedRatioComponent(void);  // @ 0x0050db88
void cm848_computeSpeedRatioLimit(void);  // @ 0x0050dba8
void cm848_calculateAlternateSpeedRatio(void);  // @ 0x0050dcac
void cm848_emptyStub_reserved50dd40(void);  // @ 0x0050dd40
void cm848_processFaultCountdownTimers(void);  // @ 0x0050dd4c
void cm848_processFaultCountdownTimer2(void);  // @ 0x0050de54
void cm848_processOperatingConditionFlags(void);  // @ 0x0050e000
void cm848_processFuelBlendFaultTimer(void);  // @ 0x0050e0a0
void cm848_clearSensorDiagnosticFlag(void);  // @ 0x0050e170
void cm848_checkFuelLimitCondition(void);  // @ 0x0050e1e0
void cm848_evaluateFaultStatusWord(void);  // @ 0x0050e2bc
void cm848_resetFaultStatusWord(void);  // @ 0x0050e414
void cm848_calculateFuelDemandScaling(void);  // @ 0x0050e4a0
void cm848_calculateFuelDemandScaleFactor(void);  // @ 0x0050e4c4
void cm848_calculateSpeedInterpolationResults(undefined4 param_1,undefined4 param_2,int param_3);  // @ 0x0050e610
void cm848_interpolateFuelDemandTable(void);  // @ 0x0050e754
void cm848_interpolateFuelDemandTable(void);  // @ 0x0050e768
void cm848_calculateSpeedInterpolationParams(void);  // @ 0x0050e7f4
void cm848_selectFuelDemandMode(void);  // @ 0x0050e938
void cm848_evaluateFuelModeSelection(void);  // @ 0x0050e970
void cm848_selectFuelModeOutputValue(int param_1,int param_2,uint param_3);  // @ 0x0050ea88
void cm848_selectFuelModeOutput(undefined4 param_1,int param_2);  // @ 0x0050eaa8
void cm848_processFuelModeSelection(void);  // @ 0x0050eaf0
void cm848_calculateFuelLimitAdjustment(void);  // @ 0x0050eb5c
void cm848_processFuelLimitAdjustments(ushort param_1);  // @ 0x0050ebf0
void cm848_updateFuelFilterCounters(ushort param_1);  // @ 0x0050ec08
void cm848_determineFuelLimitMode(void);  // @ 0x0050edbc
void cm848_calculateFuelFilterAndPeak(void);  // @ 0x0050ee24
void cm848_interpolateFuelLimitValues(void);  // @ 0x0050ee44
void cm848_processFuelFilterPeakOutput(void);  // @ 0x0050ee68
void cm848_adjustFuelParameter(void);  // @ 0x0050f060
void cm848_processFuelCalibration(void);  // @ 0x0050f16c
void cm848_initFuelConditionPointers(undefined4 param_1,undefined4 param_2,undefined4 *param_3);  // @ 0x0050f4c0
void cm848_evaluateFuelConditionDelta(void);  // @ 0x0050f4e0
void cm848_evaluateSpeedThresholdCondition(short param_1,undefined4 param_2,int param_3);  // @ 0x0050f680
void cm848_evaluateConditionPair(short param_1,undefined4 param_2,short param_3);  // @ 0x0050f6c4
void cm848_calculateFuelCounterState(void);  // @ 0x0050f728
void cm848_processFuelFaultMonitoring(void);  // @ 0x0050f8a4
void cm848_initializeFuelFaultVariables(void);  // @ 0x0050f938
void cm848_updateFaultCounterWithFlag(void);  // @ 0x0050f9ec
void cm848_calculateWeightedFuelParameter(void);  // @ 0x0050fb00
void cm848_calculateFuelStatusWithFilter(undefined4 param_1,ushort *param_2);  // @ 0x0050fbf8
void cm848_processFaultStatusThresholds(void);  // @ 0x0050fc8c
void cm848_calculateWeightedFuelValue(void);  // @ 0x0050fd38
void cm848_calculateFuelStatusParameters (undefined4 param_1,undefined4 param_2,int param_3,ushort *param_4,int *param_5, int param_6);  // @ 0x0050fe54
void cm848_filterAndAccumulatePressureSquared(void);  // @ 0x0050ff28
void cm848_evaluateSensorDeviationCondition(void);  // @ 0x00510058
void cm848_updateChannelProtectionCondition(void);  // @ 0x005101cc
void cm848_evaluateProtectionLatchState(void);  // @ 0x0051027c
void cm848_processProtectionEventConditions(void);  // @ 0x005102d4
void cm848_evaluateProtectionConditions(undefined4 param_1,short *param_2,int param_3);  // @ 0x005103ac
void cm848_updateChannelProtectionStatus(undefined4 param_1,undefined4 param_2,undefined2 param_3);  // @ 0x00510520
void cm848_clearSensorStatusFlags(void);  // @ 0x00510624
void cm848_auxSensorChannel26_init(void);  // @ 0x00510668
void cm848_auxSensorChannel26_process(void);  // @ 0x005106f4
void cm848_auxSensorChannel28_init(void);  // @ 0x00510780
void cm848_auxSensorChannel28_process(void);  // @ 0x0051080c
void cm848_auxSensorChannel29_init(void);  // @ 0x00510898
void cm848_auxSensorChannel29_process(void);  // @ 0x00510924
void cm848_auxSensor29_process(undefined4 param_1,undefined4 param_2,int param_3);  // @ 0x00510978
void cm848_crankshaftSensor_init(void);  // @ 0x005109b0
void cm848_crankshaftSensor_initB(void);  // @ 0x005109bc
void cm848_crankshaftSensor_process(void);  // @ 0x00510a3c
void cm848_crankshaftSensor_processB(void);  // @ 0x00510a48
void cm848_auxSensorChannel103_init(void);  // @ 0x00510ac8
void cm848_auxSensorChannel103_init(void);  // @ 0x00510ad4
void cm848_updateAuxSensorChannelState(void);  // @ 0x00510b54
void cm848_auxSensorChannel103_process(void);  // @ 0x00510b60
void cm848_initEventFlag26Handler(void);  // @ 0x00510be0
void cm848_initEventFlag26State(void);  // @ 0x00510bec
void cm848_processEventFlag26Logic(void);  // @ 0x00510c4c
void cm848_processEventFlag26Counter(void);  // @ 0x00510c78
void cm848_emptyStub_reserved510d04(void);  // @ 0x00510d04
void cm848_evaluateSpeedSyncCondition(void);  // @ 0x00510d24
void cm848_evaluateMultichannelDemandCondition(void);  // @ 0x00510d90
void cm848_evaluateSpeedSyncSystemState(void);  // @ 0x00510e1c
void cm848_evaluateMultichannelStateConditions (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5, undefined4 param_6,int param_7);  // @ 0x00510ea8
void cm848_processMultichannelRampRate (undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5);  // @ 0x00510f34
void cm848_processEventFlag26Dispatcher(void);  // @ 0x005115a4
void cm848_updateProtectionLockoutState(void);  // @ 0x005115e8
void mpc555_updateEngineProtectionMode(void);  // @ 0x00511810
void cm848_processProtectionHysteresis(void);  // @ 0x005118f8
void cm848_updateProtectionHysteresisCounter(void);  // @ 0x0051193c
void cm848_setMultichannelStateTableEntry(void);  // @ 0x00511b64
void cm848_updateDiagnosticTorqueLimitState(void);  // @ 0x00511b80
void cm848_updateTransmissionTorqueControl(void);  // @ 0x00511ddc
void cm848_processDynamicControlState(void);  // @ 0x00511ea8
void cm848_processDynamicControlStateB(void);  // @ 0x00511ed4
void cm848_incrementDynamicControlCounter(void);  // @ 0x00512130
int cm848_protectionModeState2Handler(void);  // @ 0x005122a0
int cm848_evaluateEmissionCondition(void);  // @ 0x00512324
undefined4 cm848_selectStateCodeByCondition(void);  // @ 0x005123d0
void cm848_updateFilteredPressureValue(void);  // @ 0x00512408
void cm848_updatePressureDifferenceAccumulator(void);  // @ 0x00512484
int cm848_protectionModeState4Handler(void);  // @ 0x00512524
int cm848_storeDynamicStateValue(int param_1,short param_2);  // @ 0x00512554
int cm848_protectionModeState3Handler(void);  // @ 0x005125c8
int cm848_selectNextProtectionModeState(void);  // @ 0x0051265c
int cm848_evaluateProtectionModeState(int param_1,undefined4 param_2,undefined4 param_3,int param_4);  // @ 0x00512678
undefined4 cm848_checkProtectionModeConditions(void);  // @ 0x0051270c
undefined4 cm848_getProtectionControlMode(undefined4 param_1,int param_2);  // @ 0x005129b0
undefined4 cm848_detectEngineProtectionThreshold(void);  // @ 0x00512b1c
undefined4 cm848_selectAlternateStateCode(void);  // @ 0x00512bc4
void cm848_evaluateProtectionMainState(void);  // @ 0x00512ca0
void mpc555_evaluateProtectionConditionFlags(void);  // @ 0x00512eac
void cm848_calculateProtectionIntegrator (short param_1,undefined2 *param_2,undefined2 *param_3,undefined2 *param_4, undefined2 *param_5,short *param_6,undefined2 param_7);  // @ 0x00512ff4
void cm848_accumulateGovernorThresholdCounts(void);  // @ 0x005130f4
void cm848_emptyStub_reserved513200(void);  // @ 0x00513200
void cm848_checkGovernorThresholdCrossing(void);  // @ 0x00513208
void cm848_monitorGovernorMultiChannelThresholds(void);  // @ 0x00513348
void cm848_setProtectionConditionFlags(void);  // @ 0x005134e8
void cm848_evaluateGovernorThresholds(void);  // @ 0x00513548
void cm848_calculateGovernorSpeedError(void);  // @ 0x0051356c
void cm848_calculateGovernorTorqueLimitAndMode(void);  // @ 0x005135a4
void cm848_interpolateGovernorModeLimit(void);  // @ 0x005136dc
void cm848_applyCrankPositionHysteresis(void);  // @ 0x00513790
void cm848_interpolateGovernorModeByIndex(void);  // @ 0x0051386c
void cm848_interpolateBoostPressureLimit(void);  // @ 0x005138f4
void cm848_initializeGovernorState(void);  // @ 0x005139f8
void cm848_evaluateGovernorMode(void);  // @ 0x00513b48
void cm848_updateEventFlagConditional(int param_1,int param_2,int param_3,int param_4);  // @ 0x00513c78
void cm848_updateEventFlag11Handler(void);  // @ 0x00513cf4
void cm848_updateEventFlag53(void);  // @ 0x00513ddc
void cm848_copyByteValuesToShorts(void);  // @ 0x00513f5c
void cm848_evaluateSpeedControlDiagnostics(void);  // @ 0x00513fe0
void cm848_processSpeedControlCalculation(void);  // @ 0x00514048
void cm848_processSpeedControlCalculationB(void);  // @ 0x00514108
void cm848_processSpeedControlCalculationC(void);  // @ 0x00514394
void cm848_calculateSpeedErrorAccumulator(void);  // @ 0x00514f5c
void cm848_evaluateSpeedControlActivationConditions(void);  // @ 0x0051524c
void cm848_applySpeedControlOutputLimits(void);  // @ 0x005154e8
void cm848_evaluateSpeedControlIntegration(void);  // @ 0x00515798
void cm848_initSpeedControlDiagnosticState(void);  // @ 0x005157c0
void cm848_evaluateSpeedCorrectionFactor(void);  // @ 0x00515964
void mpc555_configureTimerChannelA(ushort *param_1);  // @ 0x00515bac
void mpc555_configureTimerChannelB(ushort *param_1);  // @ 0x00515bd4
void cm848_validateSpeedCorrectionFlag(void);  // @ 0x00515d78
void cm848_initSpeedControlIntegratorState(void);  // @ 0x00515dac
void mpc555_evaluateSpeedNormalizationFactor(void);  // @ 0x00515e60
void cm848_initOilPressureState(void);  // @ 0x00516014
undefined4 cm848_updateOilPressureFilter(void);  // @ 0x00516040
void cm848_resetOilPressureDebounce(void);  // @ 0x00516164
void cm848_updateOilPressureHysteresis(void);  // @ 0x0051617c
void cm848_processOilPressureHysteresis(undefined4 param_1,undefined4 param_2,int param_3);  // @ 0x005161c0
void cm848_updateOilPressureOutputFilter(void);  // @ 0x0051626c
void cm848_initOilPressureProtection (undefined2 *param_1,byte param_2,undefined4 param_3,int param_4,short param_5);  // @ 0x005162ec
void cm848_calculateOilPressureRate(void);  // @ 0x00516338
void cm848_resetOilPressureTimeout(void);  // @ 0x00516420
void cm848_processOilPressureIntegration(undefined4 param_1,ushort param_2,ushort param_3);  // @ 0x00516430
void cm848_resetProtectionRateLimit(void);  // @ 0x005165fc
void cm848_initOilPressureStateAndLimits(void);  // @ 0x0051660c
void cm848_updateProtectionRateLimitState(void);  // @ 0x00516680
void cm848_updateOilPressureCyclicProcess(void);  // @ 0x0051679c
void cm848_evaluateBoostPressureBlending(void);  // @ 0x00516804
void cm848_clearEventFlag36Handler(void);  // @ 0x005169e4
void cm848_initEventFlag54State(void);  // @ 0x00516a20
void cm848_initCoolantTemperatureProtectionState(void);  // @ 0x00516a48
void cm848_interpolateCoolantProtectionValue(void);  // @ 0x00516b88
void cm848_interpolateCoolantTable(void);  // @ 0x00516bb0
void cm848_activateCoolantProtectionEvents(void);  // @ 0x00516c18
void cm848_updateCoolantEventFlags(void);  // @ 0x00516d0c
void cm848_processCoolantEventTransition(void);  // @ 0x00516df8
void cm848_clearCoolantProtectionEvents(void);  // @ 0x00516e5c
void cm848_processCoolantProtectionEntry(void);  // @ 0x00516f58
void cm848_selectCoolantProtectionPath1(void);  // @ 0x0051714c
void cm848_selectCoolantProtectionPath2(void);  // @ 0x005171b4
void cm848_processProtectionStateTransition(void);  // @ 0x0051730c
void cm848_resetProtectionEventFlags(void);  // @ 0x00517648
void cm848_executeCoolantProtectionPhase4(void);  // @ 0x0051775c
void cm848_evaluateCoolantTemperatureTransition(void);  // @ 0x00517b34
void cm848_selectCoolantLoadReference(void);  // @ 0x00517f20
void cm848_selectCoolantProtectionReference(undefined4 param_1,int param_2);  // @ 0x00517f48
void cm848_updateCoolantTemperatureReference(void);  // @ 0x00517fa0
void cm848_processCoolantProtectionCycleState(void);  // @ 0x00518124
void evaluateTemperatureDiagnosticState(void);  // @ 0x0051826c
void cm848_processProtectionStateSwitch(void);  // @ 0x00518324
void switchD_005183b0::cm848_handleProtectionStateSwitchCase(void);  // @ 0x005183b4
void cm848_processDiagnosticModeFlags(void);  // @ 0x00518538
void cm848_unsignedDivisionWrap64(void);  // @ 0x005185b4
void cm848_convertTemperatureCelsiusToDisplayFormat(void);  // @ 0x005185dc
void cm848_divideEngineParameterBy61525(void);  // @ 0x0051862c
void cm848_updateControlModeAndBuffer(void);  // @ 0x00518668
void cm848_copyProtectionStateBuffer(void);  // @ 0x00518680
void cm848_wrapperCallControlMode(void);  // @ 0x005186a8
void cm848_convertTemperatureToScale(void);  // @ 0x005186cc
void cm848_convertSensorToPercentage(void);  // @ 0x0051871c
void cm848_clampAndConvertByteValue(void);  // @ 0x00518744
void cm848_useFixedConstantValue(void);  // @ 0x00518760
void cm848_convertDiscreteDigitalValue(void);  // @ 0x0051876c
void cm848_emptyCommandHandler(void);  // @ 0x00519318
void cm848_processDisplayCommandState(void);  // @ 0x0051931c
void cm848_processFaultListEntry (int param_1,undefined4 param_2,undefined4 param_3,short *param_4,byte *param_5, byte param_6,undefined4 param_7,int param_8,uint param_9);  // @ 0x005196f0
void cm848_processFaultListEntryB (int param_1,undefined4 param_2,byte *param_3,short *param_4,byte *param_5, undefined4 param_6,undefined4 param_7,int param_8,uint param_9);  // @ 0x0051972c
void cm848_initOilTemperatureEventFlag35(void);  // @ 0x00519870
void cm848_updateOilTemperatureDebounceState(void);  // @ 0x005198b0
void cm848_initOilTemperatureProtectionThreshold(void);  // @ 0x00519a18
void mpc555_initOilTemperatureConditionState(void);  // @ 0x00519c04
void cm848_initOilTemperatureState(undefined2 param_1);  // @ 0x00519c64
void cm848_storeIndirectValueB(void);  // @ 0x00519c84
void cm848_evaluateOilTemperatureLoadCondition(void);  // @ 0x00519c94
void cm848_evaluateProtectionStepCondition(void);  // @ 0x00519cc4
void cm848_updateProtectionActiveFlag(void);  // @ 0x00519e2c
void cm848_processOilTempSensorRange(void);  // @ 0x0051a0a8
void cm848_evaluateOilTemperatureSensorDiagnostics(void);  // @ 0x0051a234
void mpc555_evaluateEmissionControlAdjustment(void);  // @ 0x0051a464
void cm848_processEmissionControlState(void);  // @ 0x0051a648
void cm848_updateCalibrationPhaseCounter(void);  // @ 0x0051a75c
void cm848_updateCalibrationPhaseFlags(void);  // @ 0x0051a878
void cm848_evaluateThermalFailsafeConditions(undefined4 param_1);  // @ 0x0051aae4
void cm848_evaluateThermalPhaseConditions(undefined4 param_1);  // @ 0x0051ab50
void cm848_evaluateThermalPhaseConditionsB(undefined4 param_1);  // @ 0x0051ab70
void cm848_evaluateThermalInjectionTimingRange(void);  // @ 0x0051aecc
void cm848_monitorThermalProtectionState(undefined4 param_1,undefined4 param_2,undefined2 param_3);  // @ 0x0051aef8
void cm848_updateThermalLockoutTimer(void);  // @ 0x0051b158
void cm848_setProtectionInhibitFlag(undefined2 param_1);  // @ 0x0051b56c
undefined4 cm848_checkAndDispatchCommand(void);  // @ 0x0051b58c
void cm848_accumulateWithClamp(void);  // @ 0x0051b608
void cm848_computeClampedDelta(void);  // @ 0x0051b658
void cm848_evaluateExhaustTemperatureDiagnostics(void);  // @ 0x0051b6a8
void cm848_processComplexControlLoop(void);  // @ 0x0051b978
void cm848_processComplexControlLoopB(void);  // @ 0x0051babc
void cm848_updateProtectionModeAndDispatch(void);  // @ 0x0051bed0
void cm848_updateExhaustTemperatureProtectionMode(void);  // @ 0x0051bfc4
void cm848_clampProtectionLimit(uint param_1);  // @ 0x0051c278
void cm848_calculateWarmupProtectionLimit(void);  // @ 0x0051c2b4
void cm848_calculateWarmupProtectionLimitB(void);  // @ 0x0051c2d0
void cm848_calculateWarmupProtectionLimitC(void);  // @ 0x0051c3d8
void cm848_calculateDeltaWarmupCompensation(void);  // @ 0x0051c534
void cm848_processWarmupTimerDecrement(void);  // @ 0x0051c5dc
void cm848_updateWarmupProtectionMode(void);  // @ 0x0051c6c0
void cm848_initWarmupStateAndTimers(void);  // @ 0x0051c974
undefined * cm848_lookupParameterPointer(int param_1,int param_2);  // @ 0x0051ca00
undefined * cm848_selectDataPointerByBitFlag(undefined4 param_1,uint param_2);  // @ 0x0051cad4
undefined4 cm848_nullParameterHandler(void);  // @ 0x0051cb54
undefined4 insiteCommandByteDispatcher(int param_1,uint param_2);  // @ 0x0051cb60
void cm848_dispatchByJumpTable(void);  // @ 0x0051cd88
int cm848_addWithMask16(int param_1,uint param_2);  // @ 0x0051d190
void cm848_getCommandAddressFromMemory(void);  // @ 0x0051d1a8
uint cm848_getActiveQueueFlags(void);  // @ 0x0051d1c8
undefined * cm848_lookupParameterByCommandAndOffset(int param_1,int param_2);  // @ 0x0051d224
void cm848_executeStateTransitionMode(void);  // @ 0x0051d2f8
void cm848_dispatchByCommandCode(void);  // @ 0x0051d36c
void cm848_initCommandDispatchMode(void);  // @ 0x0051d3fc
void cm848_processProtectionTimerState(void);  // @ 0x0051d42c
void mpc555_processCommandQueueStep(void);  // @ 0x0051d458
void mpc555_processCommandQueueStateMachine(void);  // @ 0x0051d58c
void cm848_initCommandQueueState(void);  // @ 0x0051d624
void mpc555_resetModeState(void);  // @ 0x0051d644
void mpc555_activateCommandQueueExecution(void);  // @ 0x0051d69c
void cm848_syncCfgValuesToEeprom(void);  // @ 0x0051d6f8
void cm848_syncDiagnosticsTemperatureToEeprom(void);  // @ 0x0051d70c
void cm848_initCommandDispatchExecution(void);  // @ 0x0051d7c0
void cm848_handleCommandDispatchMode(void);  // @ 0x0051d808
void cm848_handleCommandF5toF8(void);  // @ 0x0051d810
void cm848_dispatchByOffsetTable(void);  // @ 0x0051d840
void switchD_0051d848::cm848_handleCommand253State(void);  // @ 0x0051d86c
void cm848_wrapperProcessCommandQueue(void);  // @ 0x0051d8c8
undefined4 cm848_validateCommandState(void);  // @ 0x0051d958
undefined4 switchD_0051d994::cm848_emptyStateHandler(void);  // @ 0x0051d9a0
void cm848_commandStateHandler1(void);  // @ 0x0051d9c0
void cm848_commandStateHandler2(void);  // @ 0x0051d9d4
void cm848_commandStateHandler3(void);  // @ 0x0051d9dc
void cm848_commandStateHandler4(void);  // @ 0x0051d9fc
void cm848_commandStateHandler5(void);  // @ 0x0051da10
void cm848_commandStateHandler6(void);  // @ 0x0051da24
void cm848_commandStateHandler7(void);  // @ 0x0051da38
void cm848_resetStateAndDispatch(void);  // @ 0x0051da4c
void cm848_initiateCommandDispatch(byte *param_1);  // @ 0x0051da58
undefined4 switchD_0051d994::default(void);  // @ 0x0051da74
undefined4 cm848_executeQueuedCommand(void);  // @ 0x0051da7c
void cm848_processParameterTableLookup(void);  // @ 0x0051da94
void cm848_lookupAndDispatchCommand(int param_1);  // @ 0x0051dad4
void cm848_lookupCommandCodeFromTable(uint param_1,int param_2);  // @ 0x0051db0c
void cm848_clearFilterStateVariables(void);  // @ 0x0051db98
void cm848_buildStatusFlags(void);  // @ 0x0051dbc8
void cm848_packFaultCountersToWords(void);  // @ 0x0051dc34
void cm848_dispatchByCommandState(uint param_1,uint param_2);  // @ 0x0051dcb0
void cm848_dispatchCommand245(void);  // @ 0x0051df70
void cm848_dispatchCommand250(void);  // @ 0x0051df9c
void cm848_dispatchCommand251(void);  // @ 0x0051dfc8
void cm848_dispatchCommand252(void);  // @ 0x0051dff4
void cm848_dispatchCommand253(void);  // @ 0x0051e020
void cm848_initEventTimerProcessingMode(void);  // @ 0x0051e04c
void cm848_cancelEventTimer(short *param_1,int param_2);  // @ 0x0051e07c
void cm848_cancelAllEventTimers(void);  // @ 0x0051e100
void cm848_tickEventTimer(short *param_1,int param_2);  // @ 0x0051e210
void cm848_processEventTimerTick(void);  // @ 0x0051e2cc
void cm848_triggerDiagnosticEvent(short *param_1,undefined4 param_2,short param_3);  // @ 0x0051e480
void cm848_processEventTimerState(void);  // @ 0x0051e500
void cm848_initCommandExecutionMode(void);  // @ 0x0051eadc
char cm848_processCommandSwitch(void);  // @ 0x0051eb0c
void diagnosticCommandDispatcher(void);  // @ 0x0051eca4
void cm848_processCommandResponseReset(void);  // @ 0x005200e4
void cm848_decrementCountdownTimer(void);  // @ 0x00520208
void cm848_initCommandSequence(void);  // @ 0x00520240
void cm848_resetStateCounters(void);  // @ 0x00520270
void cm848_initializeCommandState(void);  // @ 0x005202b0
void cm848_initProcessDiagnosticStatus(void);  // @ 0x00520318
void cm848_processDiagnosticStatusPackage(void);  // @ 0x00520348
void cm848_initProcessResetCommand(void);  // @ 0x005206c4
void hpcr_processResetCommand(void);  // @ 0x00520700
void cm848_initProcessEepromWrite(void);  // @ 0x005212e0
void cm848_processEepromWriteCommand(void);  // @ 0x0052131c
void cm848_initCommandAndDispatch(undefined4 param_1,undefined4 param_2,int param_3);  // @ 0x00521474
void cm848_initProcessParameterRead(void);  // @ 0x005214f4
void cm848_processParameterReadCommand(void);  // @ 0x00521530
void cm848_initWriteParameterByAddress(void);  // @ 0x0052164c
void mpc555_writeParameterByLookup(void);  // @ 0x00521688
void cm848_processParameterWriteCommand(void);  // @ 0x005216cc
void cm848_initReadDiagnosticValue(void);  // @ 0x00521758
void cm848_readDiagnosticValue(void);  // @ 0x00521788
void cm848_processEngineSpeedResponse(void);  // @ 0x00521928
void cm848_initProcessChecksumValidation(void);  // @ 0x005219f0
void cm848_decrementTimeout(void);  // @ 0x00521a2c
void cm848_processChecksumValidation(void);  // @ 0x00521a54
void cm848_initProcessSecurityCommand(void);  // @ 0x00521c30
void cm848_completeCommandExecution(void);  // @ 0x00521c60
undefined1 cm848_writeEepromWithRetry(uint param_1,undefined4 param_2,int param_3);  // @ 0x00521ca0
void cm848_processSecurityCommand(void);  // @ 0x00521d44
void cm848_buildParameterValuePacket8(void);  // @ 0x00521e10
void cm848_buildParameterValuePacketAA(void);  // @ 0x00521f00
void cm848_initReadSensorChannelStatus(void);  // @ 0x00522018
undefined4 cm848_lookupParameterTableEntry(undefined2 *param_1,uint param_2);  // @ 0x00522054
undefined4 cm848_lookupSensorParameterEntry(undefined2 *param_1,uint param_2,int param_3,uint param_4);  // @ 0x00522074
bool cm848_checkSensorActiveStatus(uint param_1);  // @ 0x0052209c
void cm848_readSensorChannelStatus(void);  // @ 0x00522118
void cm848_validateResponseChecksum(void);  // @ 0x00522260
void cm848_updateEngineRunningCounter(void);  // @ 0x00522398
void cm848_updateSystemEnableFlag(void);  // @ 0x0052261c
void cm848_synchronizeEnableState(void);  // @ 0x0052269c
void cm848_updateDiagnosticStateWithFlag (int param_1,uint *param_2,undefined4 param_3,undefined2 *param_4,uint param_5);  // @ 0x00522700
void cm848_processOperatingStateTransition(void);  // @ 0x00522750
void cm848_conditionalSyncEnableState(void);  // @ 0x00522788
void cm848_evaluateOperatingStateConditions (undefined4 param_1,undefined4 param_2,undefined2 *param_3);  // @ 0x005227ac
void cm848_updateSystemEnableFlagConditional(void);  // @ 0x005229c0
void cm848_clearEnableStateBit10(void);  // @ 0x00522a04
void cm848_evaluateOperatingStateTransition (undefined4 param_1,undefined4 param_2,undefined2 *param_3);  // @ 0x00522b64
void cm848_updateEngineLoadDiagnostics(void);  // @ 0x00522d34
void cm848_updateProtectionErrorFiltered (undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4, uint param_5,undefined4 param_6,int *param_7);  // @ 0x00523068
void cm848_calculateProtectionCounterValue(void);  // @ 0x005230f4
void cm848_calculateEngineLoadProtection (undefined4 param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4, undefined2 *param_5,undefined2 *param_6);  // @ 0x00523148
void cm848_interpolateBoostPressureMap(void);  // @ 0x00523444
void cm848_updateEepromConfigBits(void);  // @ 0x005234f8
void cm848_toggleEepromDataSource(void);  // @ 0x00523688
void cm848_clearTorqueProtectionState(void);  // @ 0x00523748
void cm848_initFuelCorrectionState(void);  // @ 0x00523750
void cm848_initFuelCorrectionStateB(void);  // @ 0x00523760
char cm848_lookupByteFromTable(int param_1);  // @ 0x00523790
char cm848_lookupByteFromTableB(undefined4 param_1,uint param_2);  // @ 0x00523798
int cm848_computeByteChecksum(uint param_1,uint param_2);  // @ 0x005237b0
void cm848_computeAndStoreChecksum(void);  // @ 0x005237ec
void cm848_computeProtectionFuelLimit(undefined4 param_1);  // @ 0x00523858
uint cm848_generateChecksumWithSeed(void);  // @ 0x00523884
void cm848_initializeChecksumStorage(void);  // @ 0x00523924
void cm848_applyTorqueLimitProtection(void);  // @ 0x00523a74
void mpc555_validateEepromDataIntegrity(void);  // @ 0x00523b4c
void mpc555_processProtectionCounterToggle(void);  // @ 0x00523b5c
void cm848_processIdleSpeedControl(void);  // @ 0x00523f4c
void cm848_processStateTransitionLogic(void);  // @ 0x00523f60
void cm848_calculateFuelInjectionTiming(void);  // @ 0x00524180
void cm848_calculateTimingAdjustmentRegion(int param_1);  // @ 0x005242f8
void cm848_calculateProtectionAdjustment(undefined2 param_1);  // @ 0x00524360
void cm848_calculateProtectionAdjustmentB(int param_1,int param_2,int param_3);  // @ 0x00524594
void cm848_updateProtectionLimitsB(void);  // @ 0x005246b0
void cm848_updateProtectionLimits(void);  // @ 0x005246d8
void cm848_updateProtectionLimitsC(undefined2 *param_1);  // @ 0x005246e0
undefined2 cm848_calculateTimingPeriod(int param_1,int param_2);  // @ 0x00524858
void cm848_interpolateTableWrapper (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8);  // @ 0x00524920
uint cm848_calculateScaledValue(int param_1,uint param_2,uint param_3);  // @ 0x005249bc
void cm848_updateFuelDemandCalculation(void);  // @ 0x005249e0
void cm848_calculateTimingAdvanceRate(void);  // @ 0x00524cac
int cm848_calculateTimingCorrection(void);  // @ 0x00524d20
void cm848_initializeTimingState(void);  // @ 0x00524dd0
void cm848_initializeTimingStateB(int param_1);  // @ 0x00524df4
void mpc555_updateInjectionTiming(void);  // @ 0x005250f0
void cm848_updateInjectionTimingB(void);  // @ 0x005251e4
void cm848_updateInjectionTimingC(void);  // @ 0x00525504
void cm848_processGovernorSpeedLimit(void);  // @ 0x00525a40
void cm848_processGovernorSpeedLimitB(void);  // @ 0x00525de4
void cm848_processGovernorSpeedLimitC(void);  // @ 0x00525e54
void cm848_calculateEngineSpeedLimitTorque(void);  // @ 0x00526000
void cm848_evaluateSpeedDerateConditions(void);  // @ 0x0052614c
void cm848_updateSpeedBandConditions(void);  // @ 0x005262e8
void cm848_updateSpeedBandConditionsB(void);  // @ 0x005263a8
void cm848_processSpeedWindowComparison(void);  // @ 0x005263e0
void cm848_processSpeedWindowComparisonB(void);  // @ 0x00526414
void cm848_processSpeedWindowComparisonC(void);  // @ 0x005264d4
void cm848_setBoostDiagnosticFlag(void);  // @ 0x00526510
void cm848_processTurboBoostDataB(void);  // @ 0x00526560
void cm848_processTurboBoostData(void);  // @ 0x005265ac
void cm848_processTurboBoostDiagnostic (undefined4 param_1,ushort *param_2,undefined2 *param_3,ushort *param_4);  // @ 0x005266fc
void cm848_clearBoostDiagnosticFlag(void);  // @ 0x005267b4
void cm848_clearTurboSensorFaultStatus(void);  // @ 0x005267e0
void cm848_clearSensorBitmapOnRun(void);  // @ 0x005267f4
void cm848_updateEngineSpeedGainCalculation(void);  // @ 0x0052686c
void mpc555_calculateTimingTrimOffset(void);  // @ 0x005268d0
void mpc555_processTpuVoltageChannel(void);  // @ 0x005268e8
void mpc555_processVariableTimingControl(void);  // @ 0x00526c3c
void mpc555_clearHardwareRegisterBits(void);  // @ 0x00526c80
void mpc555_initHardwareRegisterSet2(void);  // @ 0x00526cb8
void hpcr_updatehpcr_CbdDiagnosticState(void);  // @ 0x00526f08
void hpcr_updatehpcr_CbdDiagnosticStateB (int param_1,undefined4 param_2,short param_3,char param_4,uint param_5);  // @ 0x00527050
void cm848_accumulateTimingOffset(void);  // @ 0x00527524
void cm848_evaluateTimingModifiers(void);  // @ 0x005275c4
void cm848_signedDivision64Wrapper(void);  // @ 0x00527860
void cm848_interpolateCbdTable4Point (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);  // @ 0x005278ac
void cm848_interpolateWithIndexWrapper(void);  // @ 0x00527958
void cm848_interpolateConditionalByMode(void);  // @ 0x0052796c
void cm848_interpolateConditionalByMode2(short param_1);  // @ 0x005279d8
void hpcr_interpolatehpcr_CbdTable(void);  // @ 0x00527c90
void hpcr_updateVehicleSpeedFilter(void);  // @ 0x00527fbc
void hpcr_initAndProcessCbdState(undefined4 param_1,undefined1 *param_2);  // @ 0x0052801c
void hpcr_calculatehpcr_CbdAngleOffset(int param_1,int param_2,undefined2 param_3,int param_4);  // @ 0x005280f4
void hpcr_applyhpcr_CbdCylinderTiming(int param_1);  // @ 0x00528368
void mpc555_initRamVariable48(void);  // @ 0x00528474
void hpcr_systemHalt(void);  // @ 0x00528564
void mpc555_setUpLookupTableAndInterpolate(void);  // @ 0x005285c0
void hpcr_processThrottlePosition(void);  // @ 0x0052877c
void mpc555_initHardwareRegisters(void);  // @ 0x005289d4
void cm848_initThrottleDiagnosticState(void);  // @ 0x00528b90
void cm848_calculateLoadBasedFuelTrim(void);  // @ 0x00528c28
void hpcr_computehpcr_CbdAngleCorrection(void);  // @ 0x00528e70
void hpcr_adjustCbdAngleForProtection (undefined4 param_1,undefined4 param_2,uint param_3,ushort param_4,undefined4 param_5 ,char *param_6);  // @ 0x0052903c
void hpcr_adjustCbdAngleParams (undefined4 param_1,undefined4 param_2,int param_3,ushort param_4,char param_5, char *param_6);  // @ 0x00529068
void hpcr_updateTemperatureSensorFilter(void);  // @ 0x0052922c
void hpcr_processhpcr_CbdStateMachine(void);  // @ 0x00529580
void hpcr_computehpcr_CbdProtectionAngle(void);  // @ 0x00529908
void mpc555_initializePressureParams(undefined4 param_1,byte *param_2,byte *param_3);  // @ 0x00529994
void hpcr_processRailPressureControl(void);  // @ 0x00529b44
void cm848_interpolateConditional4Point(void);  // @ 0x00529d1c
void cm848_interpolate7PointTable(undefined4 param_1);  // @ 0x00529ea4
void cm848_interpolateDiagnosticTable4Point(void);  // @ 0x00529f58
void cm848_evaluatePressureLimitConditions(void);  // @ 0x0052a598
void cm848_interpolate4PointTable(undefined4 param_1,undefined4 param_2);  // @ 0x0052a910
void cm848_interpolateFuelMapBySpeed(void);  // @ 0x0052b2e8
void cm848_interpolateFuelMapBySpeedB(void);  // @ 0x0052b998
void cm848_interpolateFuelMapBySpeedC(void);  // @ 0x0052ba30
void hpcr_updateFaultMonitorCounter(void);  // @ 0x0052bca8
void cm848_processAdaptiveLoadControl(void);  // @ 0x0052bf74
void cm848_evaluateSystemConditions(void);  // @ 0x0052c08c
void cm848_evaluateFaultCodeBoundary(void);  // @ 0x0052c210
void cm848_updateFaultMonitorState(void);  // @ 0x0052c688
void cm848_updateFaultFlagStatus(void);  // @ 0x0052c8cc
void cm848_calculateDiagnosticAccumulator(void);  // @ 0x0052c97c
void cm848_updateDiagnosticCounter(void);  // @ 0x0052ce04
void cm848_updateBoostDeviationAccumulator(void);  // @ 0x0052d140
void cm848_updateSpeedReferenceAccumulator(void);  // @ 0x0052d358
void cm848_updateProtectionAccumulator(void);  // @ 0x0052d40c
void cm848_evaluateDiagnosticModeTransition(void);  // @ 0x0052d514
void hpcr_processProtectionEngage(void);  // @ 0x0052d650
void hpcr_evaluateProtectionStateMachine(void);  // @ 0x0052d6a8
void cm848_validateCalibrationType(void);  // @ 0x0052daf8
void cm848_enqueueNullDataRecord(void);  // @ 0x0052db98
undefined4 cm848_enqueueConditionalRecord(void);  // @ 0x0052dcd0
void cm848_evaluateSpeedDelta(void);  // @ 0x0052ddb8
void cm848_setModeBySpeedComparison(byte param_1,int param_2,uint param_3);  // @ 0x0052de14
undefined4 hpcr_processSpeedState(void);  // @ 0x0052de94
undefined4 cm848_calculateSpeedDerivative(void);  // @ 0x0052dfb0
undefined4 cm848_updateSpeedFilters(void);  // @ 0x0052e13c
void cm848_setModeAndEnqueueOperation(void);  // @ 0x0052e24c
undefined4 cm848_setModeIfFlagSet(void);  // @ 0x0052e29c
undefined4 cm848_initSpeedControlState(void);  // @ 0x0052e2d8
void cm848_resetSpeedAccumulators(void);  // @ 0x0052e404
undefined4 cm848_validateSpeedThresholds(int param_1);  // @ 0x0052e4a0
void cm848_prepareStateTransition(int param_1,undefined2 param_2);  // @ 0x0052e4fc
void cm848_triggerStateTransitionEvent(ushort param_1);  // @ 0x0052e540
int cm848_updatePerformanceMetric(void);  // @ 0x0052e59c
void cm848_setOperationalModeByCondition(int param_1);  // @ 0x0052eac8
void cm848_setMode2AndEnqueueState(void);  // @ 0x0052eae8
int cm848_processProtectionEvent(void);  // @ 0x0052eb30
void cm848_evaluateSystemHealthStatus(void);  // @ 0x0052ebc4
void cm848_processTimerRecoverySequence(void);  // @ 0x0052ee00
undefined4 cm848_validateProtectionStateFlags(void);  // @ 0x0052eedc
void cm848_evaluateProtectionDiagnosticState(void);  // @ 0x0052ef90
void cm848_updateTimerEventCounter(void);  // @ 0x0052f144
void cm848_calculateLimitFactorAdjustment(void);  // @ 0x0052f1b4
void cm848_evaluateSafetyConditions(void);  // @ 0x0052f524
void hpcr_computeAccumulatorProduct(void);  // @ 0x0052f7bc
void hpcr_checkEngineLimitConditions(void);  // @ 0x0052f870
void cm848_processTransmissionStatus(void);  // @ 0x0052fd4c
void cm848_validateCommandSequence(void);  // @ 0x0052fed8
void cm848_initCommandValidationState (short *param_1,int param_2,undefined4 param_3,short param_4,undefined4 param_5, int param_6,undefined4 param_7,short *param_8);  // @ 0x0053005c
void cm848_updateAuxiliaryOutputPort(void);  // @ 0x00530214
void cm848_updateSpeedSensorOutputFlag(void);  // @ 0x00530288
void cm848_updateSpeedSensorRangeFlag(void);  // @ 0x00530298
void cm848_updateSeverityFlags(void);  // @ 0x00530364
void cm848_setEngineOperatingFlag(void);  // @ 0x00530428
void cm848_processControlModeSwitching(void);  // @ 0x00530468
void cm848_buildEngineStatusFlags(void);  // @ 0x005305dc
void cm848_buildEngineStatusFlags2(void);  // @ 0x0053064c
void cm848_clearOutputCounters(void);  // @ 0x00530878
void cm848_evaluateOperatingModeStatus(void);  // @ 0x0053089c
void cm848_updateSystemEnableCounter(void);  // @ 0x00530968
void cm848_updateDiagnosticStateTimer(void);  // @ 0x00530d70
undefined4 cm848_checkProtectionBypassConditions(void);  // @ 0x00530e94
void cm848_processDataRecordCapture(void);  // @ 0x00530f80
void cm848_initProtectionRampCounter (undefined4 param_1,short *param_2,undefined4 param_3,undefined2 *param_4, undefined2 *param_5);  // @ 0x005311e4
void cm848_validateProtectionRampBounds (int param_1,int param_2,int param_3,undefined2 *param_4,undefined2 *param_5);  // @ 0x00531370
void hpcr_resethpcr_CbdCylinderState(void);  // @ 0x0053164c
void hpcr_initCbdToothState(void);  // @ 0x0053168c
void hpcr_initCbdCylinderArray(void);  // @ 0x005316ac
void hpcr_calculateFaultDetectionThreshold(void);  // @ 0x00531710
void cm848_evaluateActiveFaultConditions(void);  // @ 0x005317a4
void cm848_evaluateProtectionEnableCondition(void);  // @ 0x005318e8
void cm848_evaluateProtectionConditionFlag(void);  // @ 0x00531900
void hpcr_countActivehpcr_CbdCylinders(void);  // @ 0x0053195c
void hpcr_updatehpcr_CbdCylinderTiming(void);  // @ 0x005319e0
void hpcr_updateSystemDiagnosticData(void);  // @ 0x00531b14
void hpcr_checkCbdResetConditions(void);  // @ 0x00531cf8
void hpcr_checkAndResetCbdState(void);  // @ 0x00531d34
void hpcr_cbdCylinderStateHandler(void);  // @ 0x00531f90
void hpcr_advancehpcr_CbdFaultState(void);  // @ 0x00531fe8
void hpcr_evaluatehpcr_CbdCylinderActivation(void);  // @ 0x00532108
void hpcr_activatehpcr_CbdCylinderMode(void);  // @ 0x005321c8
void hpcr_updateCbdCylinderStatusBitmap(void);  // @ 0x00532208
void hpcr_updateSensorStatusBitmap(void);  // @ 0x0053227c
void hpcr_deactivatehpcr_CbdCylinderMode(void);  // @ 0x0053236c
void hpcr_deactivatehpcr_CbdCylinderModeB(ushort *param_1);  // @ 0x00532418
void hpcr_compareAndSyncFaultFlags(void);  // @ 0x0053247c
void switchD_00531be4::default(void);  // @ 0x00532630
void cm848_resetFaultRecordFlags(int param_1);  // @ 0x00532654
void cm848_incrementFaultCounters(void);  // @ 0x00532680
void cm848_shiftFaultCounters(uint param_1);  // @ 0x005326c4
void cm848_resetFaultTimers(void);  // @ 0x005326fc
void cm848_removeFromActiveQueue(int param_1);  // @ 0x0053272c
void cm848_findFaultByCode(uint param_1);  // @ 0x005327e8
void cm848_processDataRecordDispatch(void);  // @ 0x00532a64
void cm848_updateFaultQueueState(void);  // @ 0x00532b78
void cm848_iterateAndResetFaultFlags(void);  // @ 0x00532ba8
void cm848_processFaultQueueEntry(void);  // @ 0x00532d10
undefined4 cm848_validateFreezeFrameConditions(uint param_1);  // @ 0x00532db8
void cm848_evaluateCalibrationChecksum(void);  // @ 0x00532e90
void cm848_scanFaultsForFreezeFrameConditions(void);  // @ 0x00532fac
void cm848_processFaultTableEntry(void);  // @ 0x0053307c
void cm848_updateMemoryAllocationState(void);  // @ 0x00533098
uint cm848_getFaultFlagByCode(uint param_1);  // @ 0x005331ec
void cm848_updateFaultTableEntry(int param_1);  // @ 0x00533250
void cm848_processEnvironmentalLimits(void);  // @ 0x005332a4
void cm848_clearFaultEntryFromList(uint param_1);  // @ 0x005333f8
void cm848_calculateOffsetCompensation(void);  // @ 0x005334fc
void cm848_setFaultActiveBit(uint param_1);  // @ 0x0053364c
void cm848_captureFaultSnapshot(uint param_1);  // @ 0x005336d0
void cm848_scanFaultTable(int param_1);  // @ 0x005337d4
void cm848_updateCylinderQueueSelection (uint param_1,int param_2,uint param_3,int param_4,int param_5,undefined4 *param_6, int param_7);  // @ 0x00533aec
void cm848_updateSensorInputValidation(int param_1,uint param_2);  // @ 0x00533b18
void cm848_setFaultTimestampFlags(ushort *param_1);  // @ 0x00533bc4
void cm848_setFaultActiveBitmapEntry(ushort param_1);  // @ 0x00533c80
void cm848_processStateTransitionGuard(void);  // @ 0x00533cc4
void cm848_evaluateTemperatureSlope(void);  // @ 0x00533dd8
void cm848_updateFaultBitmapFromStateGuards(uint param_1,uint param_2,uint param_3);  // @ 0x00533df0
void cm848_iterateFaultStatusRecords (ushort param_1,ushort param_2,int param_3,int param_4,uint param_5,ushort *param_6);  // @ 0x00533efc
void hpcr_evaluateFaultConditions(void);  // @ 0x00533f30
void cm848_checkFaultCounterThreshold(void);  // @ 0x00534328
void cm848_processFaultLampLogic(void);  // @ 0x005343d0
void cm848_checkFaultStateTransition(void);  // @ 0x005344cc
void cm848_evaluateFuelDemandFaultCondition (ushort *param_1,int param_2,undefined4 param_3,undefined4 param_4,ushort *param_5);  // @ 0x00534530
void cm848_updateFaultCounter(void);  // @ 0x005346c0
void cm848_evaluateFaultTimingThreshold (undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5, int param_6);  // @ 0x0053473c
void cm848_processChannelDiagnostics (int param_1,char *param_2,char *param_3,char *param_4,char *param_5,uint *param_6, short *param_7,byte *param_8,int param_9,uint param_10,uint param_11,uint param_12, int param_13,uint param_14,uint param_15,short *param_16,short *param_17, ushort *param_18,ushort *param_19,int param_20,uint param_21);  // @ 0x0053489c
void cm848_evaluateInjectionTimingStability (int param_1,char *param_2,undefined4 param_3,int param_4,undefined4 param_5, int param_6,undefined4 param_7,uint param_8);  // @ 0x00534994
void cm848_evaluateSensorChannelStateMatch(void);  // @ 0x00534b68
void cm848_synchronizeDiagnosticFlagState(undefined4 param_1,int param_2);  // @ 0x00534c6c
void hpcr_calculateLoadFactorDynamic(void);  // @ 0x00534db4
void hpcr_processMultiChannelDiagnostics(void);  // @ 0x00534fb0
void cm848_incrementCounterOrSetWarmup(void);  // @ 0x0053515c
void cm848_updateSystemConditionMetric(void);  // @ 0x00535208
void cm848_storeRegisterValue(void);  // @ 0x00535270
void cm848_processOutputControlSequence(void);  // @ 0x00535324
void cm848_evaluateOutputControlConditions(int param_1);  // @ 0x00535344
void cm848_handleEnableStateTransition(void);  // @ 0x00535408
void cm848_evaluateTimingAdvanceLimits(void);  // @ 0x005354c0
void cm848_clearFaultAccumulator(void);  // @ 0x00535998
void cm848_updateFilteredRpmValue(void);  // @ 0x005359b4
void cm848_processFuelingRateControl(void);  // @ 0x00535d5c
void cm848_calculateDiagnosticThresholdLevel(void);  // @ 0x00535e2c
void cm848_updateOutputDriverControl(void);  // @ 0x005360ec
void cm848_linearInterpolate1DWrapper(void);  // @ 0x0053624c
void cm848_processProtectionRecoveryState(void);  // @ 0x00536540
void cm848_buildStatusBitmaskFromTable(void);  // @ 0x00536638
void cm848_buildStatusBitmaskSecondary (int param_1,int param_2,ushort *param_3,undefined4 param_4,undefined4 param_5, uint param_6);  // @ 0x0053664c
void cm848_buildStatusBitmaskFromPointer (int param_1,int param_2,ushort *param_3,undefined4 param_4,undefined4 param_5, uint param_6);  // @ 0x0053665c
undefined4 cm848_getDiagnosticStatus(int param_1);  // @ 0x005366b8
void cm848_validateCalibrationLookup (uint param_1,uint param_2,uint param_3,uint param_4,byte *param_5,byte *param_6, byte *param_7,byte *param_8,ushort *param_9);  // @ 0x005367cc
void cm848_resetStateVariable(void);  // @ 0x00536958
void vp44Message300FaultFlagProcessor(void);  // @ 0x00536de0
void cm848_processBoostDiagnosticFlags(void);  // @ 0x00536e4c
void cm848_validateCalibrationParameters(void);  // @ 0x005371f4
void cm848_emptyStub_boostControl(void);  // @ 0x0053729c
void cm848_updatePressureControlTarget(void);  // @ 0x005372b0
void cm848_initPressureControlVariables(void);  // @ 0x005372c4
void cm848_initDataBufferPointers(void);  // @ 0x0053752c
void cm848_initServiceRequestState (undefined4 param_1,undefined4 param_2,uint *param_3,uint param_4,uint param_5);  // @ 0x00537584
void cm848_calculateFuelingMassFlowRate(void);  // @ 0x005375ec
undefined4 cm848_enqueueDataRecord(int param_1,undefined2 param_2,int param_3,int param_4,undefined4 param_5);  // @ 0x005377f4
void cm848_processProtectionDiagnosticState(void);  // @ 0x005378a4
void cm848_executeTimerCallbacks(void);  // @ 0x00537944
void cm848_iterateAndExecuteTimerEntries(void);  // @ 0x005379b4
void cm848_executeTimerCallbacksViaLR(void);  // @ 0x005379d8
bool cm848_enqueueToBuffer17(undefined2 param_1,undefined4 param_2);  // @ 0x00537a18
void mpc555_updateProtectionLimitFilter(void);  // @ 0x00537a5c
void mpc555_processJ1939MessageWithFilter(void);  // @ 0x00537acc
void initDiagnosticBufferPointers(void);  // @ 0x00537cf8
void mpc555_buildBitmapAndSetHwFlag (undefined4 param_1,undefined4 param_2,ushort *param_3,undefined4 param_4, undefined4 param_5,ushort *param_6);  // @ 0x00538278
undefined4 cm848_resolveParameterAddress(uint param_1,uint *param_2);  // @ 0x005382d0
void mpc555_calculatePressureDropOffset(void);  // @ 0x005383d0
void cm848_pushToCircularBuffer(void);  // @ 0x005384a0
void mpc555_processBufferSequence(void);  // @ 0x005385e0
void cm848_enqueueToCircularBufferWrapper(void);  // @ 0x00538748
void cm848_evaluateFlowRateCondition(void);  // @ 0x00538880
void cm848_synchronizeTimebase(void);  // @ 0x00538974
void cm848_updateEmissionControlParameter(void);  // @ 0x00538c78
void cm848_dispatchFaultTimerHandlers(void);  // @ 0x00538d3c
void cm848_dataTable_00538eac(void);  // @ 0x00538eac
void cm848_registerJ1939PgnHandler(void);  // @ 0x00538eb0
void cm848_dataTable_00538ef4(void);  // @ 0x00538ef4
void cm848_dataTable_00539768(void);  // @ 0x00539768
void cm848_dataTable_00539868(void);  // @ 0x00539868
void cm848_dataTable_00539d18(void);  // @ 0x00539d18
void cm848_dataTable_0053a110(void);  // @ 0x0053a110
