#pragma once
#include "firmware_types.hpp"

// Function Forward Declarations (from decompiled output)

void mpc555_reset_vector(void);  // @ 0x00000100
void mpc555_keyOnStateMachine(void);  // @ 0x00000184
void cm848_copyBootKernelToRam(void);  // @ 0x00000340
void cm848_registerStandardDiagServices(void);  // @ 0x0000037c
void cm848_eepromProgressNotify(j1939_rx_msg_t *param_1,int param_2,dword param_3);  // @ 0x000003ec
undefined4 cm848_diagServiceAcknowledgeNoOperation(void);  // @ 0x00000420
void mpc555_loadEepromCalibration(undefined4 param_1,int param_2);  // @ 0x00000428
undefined4 cm848_diagServiceDownloadCalibration(undefined4 param_1);  // @ 0x000008d4
short mpc555_initEepromTransfer(int param_1);  // @ 0x000008fc
undefined4 mpc555_diagServiceInitEepromTransfer(undefined4 param_1);  // @ 0x000009e4
uint cm848_computeCrcCcitt(undefined4 *param_1,uint param_2);  // @ 0x00000a40
void mpc555_updatePowerStateOutputs(void);  // @ 0x00000b44
void cm848_stubFunction1(void);  // @ 0x00000be8
void mpc555_eepromWriteWords(dword dest_address,word *src_ptr,word word_count);  // @ 0x00000bec
void mpc555_eepromReadWords(word param_1,word *param_2,uint param_3);  // @ 0x00000d88
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
void cm848_initClockAndTimers(void);  // @ 0x000016dc
void cm848_stubFunction2(void);  // @ 0x0000183c
char mpc555_diagService25_executeFunction(j1939_rx_msg_t *param_1);  // @ 0x00001840
void cm848_initService25Handler(void);  // @ 0x0000191c
bool cm848_registerPgnResponseHandler(dword pgn,void *handler_func);  // @ 0x00001948
void cm848_initDataBasedDiagServices(void);  // @ 0x0000198c
undefined4 cm848_diagService65_handler(dword request_msg);  // @ 0x000019e8
void cm848_registerService65Handler(void);  // @ 0x00001ad0
void cm848_registerMemoryReadServices(void);  // @ 0x00001afc
char cm848_diagMemoryReadHandler(dword address,word length,byte *response_ptr);  // @ 0x00001b48
undefined1 cm848_diagMemoryReadWithBaseOffset(dword request_msg,word param_id,word reserved,dword offset);  // @ 0x00001cf8
undefined1 cm848_diagService67_memoryReadOffset(dword request_msg);  // @ 0x00001d5c
undefined1 cm848_diagService74_memoryRead(dword request_msg);  // @ 0x00001dc4
undefined1 cm848_diagService76_memoryReadExt(dword request_msg);  // @ 0x00001e30
void mpc555_initDiagResponseHandlers(void);  // @ 0x00001e94
void cm848_diagSendResponseCode(byte response_code,dword negative_response_id);  // @ 0x00001ef8
void mpc555_processDiagnosticAndEepromRequests(void);  // @ 0x00001fa4
void cm848_initDiagnosticCallback(void);  // @ 0x00002148
void cm848_processDiagnosticTimeout(void);  // @ 0x00002170
void cm848_setDataTransferMode(void);  // @ 0x000021c0
void mpc555_initDiagnosticSession(void);  // @ 0x000021d0
void mpc555_eepromValidationCycle(void);  // @ 0x00002310
void cm848_busyWaitDelay(int pass_count);  // @ 0x00002384
bool mpc555_areBootModeStrapPinsHigh(void);  // @ 0x000023b8
void cm848_waitForStableIgnitionKeyOn(void);  // @ 0x000024a0
void mpc555_systemInitialization(void);  // @ 0x00002504
void mpc555_hardwareInitialization(void);  // @ 0x00002694
void mpc555_initCanController(void);  // @ 0x00002970
void mpc555_initDiagnosticSubsystem(void);  // @ 0x00002a40
void cm848_clearRamRegions(void);  // @ 0x00002b7c
void cm848_softReset(void);  // @ 0x00002bc8
bool cm848_registerDiagnosticService(byte service_id,void *handler_ptr);  // @ 0x00002c94
void cm848_registerPgnEf00Handler(byte sub_id,void *handler_func);  // @ 0x00002cd8
undefined * cm848_lookupEepromParameterAddress(byte param_1);  // @ 0x00002d08
void cm848_pumpDiagnosticCallback(void);  // @ 0x00002de4
void cm848_dispatchBootSciDiagnosticCommand(void);  // @ 0x00002e58
void cm848_installBootSciDispatcher(void);  // @ 0x00002ee8
void mpc555_sciBeginUnchecksummedResponseTransmit(void);  // @ 0x00002f18
void mpc555_sciReceiveRequestByte(void);  // @ 0x00002f74
void mpc555_sciTransmitResponseByte(void);  // @ 0x00003008
void mpc555_sciDispatchByTransferPhase(void);  // @ 0x000030ec
void cm848_resetEepromStatusPointer(void);  // @ 0x000031a0
void mpc555_sciResetToReceiveRequest(void);  // @ 0x000031c0
void mpc555_sciEnableTransmitInterrupt(void);  // @ 0x00003218
void cm848_initDiagnosticResponseCallback(void);  // @ 0x0000323c
void cm848_processDiagnosticResponseCallback(void);  // @ 0x0000326c
void mpc555_generateSerialChallenge(void);  // @ 0x000032dc
void cm848_initDiagnosticRequestHandler(void);  // @ 0x000033a4
void cm848_decrementDiagnosticTimeout(void);  // @ 0x000033e0
void cm848_bootSciCheckSecurityKey(void);  // @ 0x00003408
void cm848_initDiagnosticSessionHandler(void);  // @ 0x000035e4
void cm848_processDiagnosticSessionFlags(void);  // @ 0x00003614
void cm848_sendDiagnosticResponse(void);  // @ 0x0000368c
void cm848_resetEepromCalibrationState(void);  // @ 0x000036f8
void cm848_beginEepromCalibrationWrite(void);  // @ 0x00003710
void cm848_updateEepromMagicAndReload(void);  // @ 0x000037e0
void cm848_dispatchEepromWriteRequest(void);  // @ 0x000038f4
void mpc555_diagServiceTransferBlock(void);  // @ 0x00003948
void cm848_verifySerialResponse(void);  // @ 0x00003a5c
void cm848_restoreDiagnosticHandler(void);  // @ 0x00003ad8
void cm848_enableDiagnosticTimer(void);  // @ 0x00003b38
void cm848_processTimerInterrupt(void);  // @ 0x00003b48
void cm848_saveDefaultDiagnosticHandler(void);  // @ 0x00003b58
void mpc555_initQspiRegisters(void);  // @ 0x00003b6c
undefined1 cm848_getDiagnosticResponseEchoLength(int param_1);  // @ 0x00003d54
void mpc555_canTransmitQueuePush(dword can_id,dword data_length,byte *data,byte *result);  // @ 0x00003dac
void cm848_transmitCanMessage(diagnostic_response_message_t *message);  // @ 0x00003f20
undefined4 cm848_lookupTableEntryByKey(word param_id);  // @ 0x00003f70
undefined4 cm848_dataTransferBufferWrite(int param_1,dword param_2,uint param_3,int param_4,byte param_5);  // @ 0x00003fcc
void cm848_fillFlashProgramPageBuffer(void);  // @ 0x00004194
void cm848_completePendingDiagWrite(void);  // @ 0x000042b0
void mpc555_cmfRestoreNormalMode(void);  // @ 0x00004320
void mpc555_cmfSelectBlockAndStartSequence(uint param_1);  // @ 0x000043a4
void mpc555_cmfLoadProgramPage(undefined *param_1);  // @ 0x00004500
undefined4 mpc555_cmfApplyHighVoltagePulse(void);  // @ 0x00004570
int mpc555_cmfScanRangeForNonzeroWords(void);  // @ 0x00004654
void mpc555_cmfEndHighVoltagePulse(void);  // @ 0x000046dc
void cm848_runFlashProgramStateMachine(void);  // @ 0x00004720
bool mpc555_cmfEraseBlocks(uint param_1);  // @ 0x000049d0
void cm848_can2MailboxTransmitCompleteWrapper(void);  // @ 0x00004eec
void cm848_can2MailboxTransmitRangeWrapper(void);  // @ 0x00004f0c
void cm848_writeBootKernelCanTxMailbox(int can_module,dword mailbox_number,word *frame_words);  // @ 0x00004f2c
void mpc555_can2TransmitInterruptHandler(void);  // @ 0x00004f6c
void mpc555_manageCan1TransmitBuffer(void);  // @ 0x00005064
void mpc555_processCanReceiveBuffer(int param_1);  // @ 0x00005134
void mpc555_dispatchCanMessageHandlers(void);  // @ 0x0000526c
byte cm848_writeDiagMemory(dword param_1,uint param_2,uint param_3);  // @ 0x00005400
undefined1 cm848_memoryWriteByParameterId(undefined4 param_1,word param_2,int param_3,undefined4 param_4);  // @ 0x00005728
undefined1 cm848_diagService68_memoryWriteByParameterId(int param_1);  // @ 0x00005798
undefined1 cm848_diagService69_memoryWriteByParameterIdExt(int param_1);  // @ 0x00005808
undefined1 cm848_diagService75_memoryWrite(int param_1);  // @ 0x00005870
undefined1 cm848_diagService77_memoryWriteExt(int param_1);  // @ 0x000058e8
undefined1 cm848_getServiceDataOffset(int param_1);  // @ 0x00005958
undefined4 cm848_validateDiagnosticRequestLengthAndAuthorization(int param_1);  // @ 0x0000597c
void mpc555_sendJ1939TransportRequestToSend(diagnostic_response_message_t *message);  // @ 0x00005adc
void mpc555_handleJ1939TransportClearToSend(byte request_type,byte connection_id);  // @ 0x00005c50
void mpc555_sendJ1939TransportAbort(undefined1 param_1,undefined2 param_2);  // @ 0x00005cf4
void mpc555_sendJ1939TransportEndOfMessageAcknowledge(byte destination_address,word transported_pgn);  // @ 0x00005d8c
byte mpc555_sendJ1939TransportClearToSend (undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined2 param_4);  // @ 0x00005e38
void mpc555_handleJ1939TransportRequestToSend(j1939_rx_msg_t *rx_msg);  // @ 0x00005ecc
void mpc555_handleJ1939TransportDataPacket(j1939_rx_msg_t *rx_msg);  // @ 0x00005fe4
void mpc555_handleJ1939TransportEndOfMessageAcknowledge(j1939_rx_msg_t *rx_msg);  // @ 0x00006180
void mpc555_handleJ1939TransportAbort(int param_1);  // @ 0x000061e8
void mpc555_dispatchJ1939TransportConnectionManagement(j1939_rx_msg_t *rx_msg,byte service_code);  // @ 0x0000628c
void mpc555_sendJ1939TransportDataPackets(void *queue_entry);  // @ 0x000062fc
void mpc555_ageJ1939TransportReceiveTimeout(void);  // @ 0x00006490
void mpc555_serviceJ1939TransportSessions(byte connection_id);  // @ 0x000064c4
diagnostic_response_message_t * cm848_allocateDiagnosticResponseBuffer(int param_1);  // @ 0x00006508
void mpc555_sciSendServiceResponse(byte param_1,int param_2);  // @ 0x00006580
void mpc555_diagnosticSubcommandDispatcher(byte subcommand,byte *data_ptr);  // @ 0x0000662c
void cm848_resetSerialReceiveBuffer(void);  // @ 0x00006770
void mpc555_sciReceiveDataByte(void);  // @ 0x000067b0
void mpc555_sciResetToReceiveData(void);  // @ 0x0000685c
void mpc555_sciTransmitChecksummedByte(void);  // @ 0x000068b4
void mpc555_sciEnableChecksummedTransmit(void);  // @ 0x00006974
void mpc555_sciValidateChecksum(void);  // @ 0x000069b0
void mpc555_sciStartResponseTransmit(void);  // @ 0x00006a5c
void mpc555_sciPollDuringEepromWrite(void);  // @ 0x00006ab8
undefined4 mpc555_runPacedSerialService(void);  // @ 0x00006b24
void cm848_copyBytes(int param_1,int param_2,int param_3);  // @ 0x00006bac
void mpc555_runPeriodicInterruptTimerTick(void);  // @ 0x00006bdc
void cm848_runBootKernelLoop(void);  // @ 0x00006ca4
void cm848_dispatchDiagnosticService(j1939_rx_msg_t *request);  // @ 0x00006d24
void cm848_sendSerialDownloadStatusResponse(void);  // @ 0x00006e1c
void mpc555_sciHandleDownloadStart(void);  // @ 0x00006eac
void mpc555_sciHandleDownloadDataBlock(void);  // @ 0x00006f54
void cm848_descrambleAuthToken(int param_1,int param_2);  // @ 0x000071f8
undefined4 cm848_validateWriteAuth(undefined4 scrambled_token);  // @ 0x00007370
void cm848_sendDiagServiceResponse(j1939_rx_msg_t *request,dword result_code);  // @ 0x000074a0
void cm848_sendDiagResponsePending(j1939_rx_msg_t *param_1,word param_2);  // @ 0x000075dc
void mpc555_tickTransferTimeoutAndRuntimeCounter(void);  // @ 0x00007608
void mpc555_loadRuntimeCounterFromEepromShadow(void);  // @ 0x000076b4
byte cm848_lookupMemoryRegionType(uint param_1,int param_2);  // @ 0x000076c8
undefined1 cm848_trackDownloadBlock(undefined4 param_1,dword param_2,ushort *param_3,int param_4);  // @ 0x00007740
undefined4 cm848_finishDownloadBlock(word *param_1);  // @ 0x00007840
undefined1 cm848_updateDownloadCrc(byte *param_1,uint param_2,int param_3);  // @ 0x000078d0
void cm848_serviceSupervisorWatchdog(void);  // @ 0x00007974
void cm848_initSupervisorWatchdog(void);  // @ 0x00007b08
void cm848_forceSupervisorWatchdogReset(void);  // @ 0x00007dc4
void cm848_keyOnStatusMonitor(void);  // @ 0x0000b44c
void cm848_phase_common_processing(void);  // @ 0x0000b76c
void cm848_phase_group_a_processing(void);  // @ 0x0000b7b4
void cm848_phase_group_b_processing(void);  // @ 0x0000b854
void hpcr_periodicTaskSet_fuelFinal(void);  // @ 0x0000b8fc
void cm848_periodicTaskSet_sensorProcessing(void);  // @ 0x0000b98c
void cm848_periodicTaskSet_controlLoop(void);  // @ 0x0000ba08
void cm848_periodicTaskSet_auxiliaryControl(void);  // @ 0x0000ba90
void cm848_periodicTaskSet_canTx(void);  // @ 0x0000bb18
void cm848_periodicTaskSet_sensors2(void);  // @ 0x0000bb40
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
void cm848_processBarometricPressureChannel(void);  // @ 0x0000c8bc
void cm848_initializeBarometricPressureChannel(void);  // @ 0x0000c948
void cm848_processAmbientAirTemperatureChannel(void);  // @ 0x0000c9d4
void cm848_initializeAmbientAirTemperatureChannel(void);  // @ 0x0000ca60
void cm848_processBatteryVoltageChannel(void);  // @ 0x0000caec
void cm848_initializeBatteryVoltageChannel(void);  // @ 0x0000cb78
void cm848_processBoostPressureChannel(void);  // @ 0x0000cc04
void cm848_initializeBoostPressureChannel(void);  // @ 0x0000cc90
void cm848_processBoostPressureAbsoluteChannel(void);  // @ 0x0000cd1c
void cm848_initializeBoostPressureAbsoluteChannel(void);  // @ 0x0000cda8
void cm848_processEgrDeltaPressureChannel(void);  // @ 0x0000ce34
void cm848_initializeEgrDeltaPressureChannel(void);  // @ 0x0000cec0
void cm848_processEgrOrificeTemperatureChannel(void);  // @ 0x0000cf4c
void cm848_initializeEgrOrificeTemperatureChannel(void);  // @ 0x0000cfd8
void cm848_processEgrValvePositionChannel(void);  // @ 0x0000d064
void cm848_initializeEgrValvePositionChannel(void);  // @ 0x0000d0f0
void cm848_processExhaustPressureChannel(void);  // @ 0x0000d17c
void cm848_initializeExhaustPressureChannel(void);  // @ 0x0000d208
void cm848_processFuelTemperatureChannel(void);  // @ 0x0000d294
void cm848_initializeFuelTemperatureChannel(void);  // @ 0x0000d320
void cm848_processIntakeManifoldTemperatureChannel(void);  // @ 0x0000d3ac
void cm848_initializeIntakeManifoldTemperatureChannel(void);  // @ 0x0000d438
void cm848_processOilPressureChannel(void);  // @ 0x0000d4c4
void cm848_initializeOilPressureChannel(void);  // @ 0x0000d550
void cm848_processRemoteAcceleratorPedalChannel(void);  // @ 0x0000d5dc
void cm848_initializeRemoteAcceleratorPedalChannel(void);  // @ 0x0000d668
void cm848_processAcceleratorPedalChannel(void);  // @ 0x0000d6f4
void cm848_initializeAcceleratorPedalChannel(void);  // @ 0x0000d780
void cm848_processSensorReferenceVoltageAChannel(void);  // @ 0x0000d80c
void cm848_initializeSensorReferenceVoltageAChannel(void);  // @ 0x0000d898
void cm848_processSensorReferenceVoltageCChannel(void);  // @ 0x0000d924
void cm848_initializeSensorReferenceVoltageCChannel(void);  // @ 0x0000d9b0
void cm848_processWaterInFuelChannel(void);  // @ 0x0000da3c
void cm848_initializeWaterInFuelChannel(void);  // @ 0x0000db50
word cm848_calculateBoostPressure(void);  // @ 0x0000dc64
void cm848_calculateAirFuelControlFuelLimit(void);  // @ 0x0000dcdc
void cm848_initFuelTableSizes(void);  // @ 0x0000e09c
void cm848_applyAirFuelControlFuelLimit(void);  // @ 0x0000e0c4
undefined4 cm848_calculateAlphaAltitudeDerateLatch(void);  // @ 0x0000e0f4
int calculateAlphaFuelRateResult(void);  // @ 0x0000e164
undefined4 calculateAlphaOnGovernorResult(void);  // @ 0x0000e218
undefined4 calculateAlphaLowSpeedGovernorResult(void);  // @ 0x0000e248
undefined4 calculateAlphaAirFuelControlResult(void);  // @ 0x0000e2cc
int calculateAlphaLowAmbientAirPressureResult(void);  // @ 0x0000e360
void calculateAlphaBase(void);  // @ 0x0000e3a4
void calculateAlpha(void);  // @ 0x0000e518
void cm848_initializeAlpha(void);  // @ 0x0000e748
void cm848_temperatureBasedFuelTrim(void);  // @ 0x0000e78c
void cm848_initTemperatureTrimTableSizes(void);  // @ 0x0000e8ac
void cm848_initTemperatureTrimCoeff(void);  // @ 0x0000e8cc
void cm848_calculateGovernorReferenceSpeedBlend(void);  // @ 0x0000e8dc
void cm848_runOperatingModeSpeedGovernor(void);  // @ 0x0000ea00
void cm848_initializeAllSpeedGovernorVariables(void);  // @ 0x0000fabc
void cm848_selectAllSpeedGovernorApplicationMode(void);  // @ 0x0000fb28
void cm848_calculateAllSpeedGovernorNoLoadFuel(void);  // @ 0x0000fcd0
void cm848_initFuelTimingTableSizes(void);  // @ 0x0000fe3c
void cm848_calculateAllSpeedGovernorThrottleReference(void);  // @ 0x0000fe5c
void cm848_calculateGovernorCompensatorCoefficients(void);  // @ 0x0000ff04
void cm848_selectVariableSpeedGovernorMode(int previous_engine_operating_mode);  // @ 0x00010110
void cm848_initLookupTableParams(void);  // @ 0x00010248
void cm848_stubFunction3(void);  // @ 0x00010270
undefined8 mpc555_timerInterruptHandler(undefined4 param_1,undefined4 param_2);  // @ 0x00010274
void mpc555_fatalErrorHalt(void);  // @ 0x00010694
void cm848_selectBatteryVoltage(void);  // @ 0x000107ec
void cm848_updateBatteryVoltageSource(void);  // @ 0x0001083c
void cm848_selectChargeManagerMassChargeFlowCommand(void);  // @ 0x00010874
void cm848_calculateChargeFlowCompressorOutletTemperatureDerate(void);  // @ 0x000108a4
void cm848_calculateChargeFlowDeltaPressureDerate(void);  // @ 0x000109c8
void cm848_calculateChargeFlowDerates(void);  // @ 0x00010b04
void cm848_limitChargeManagerCommands(void);  // @ 0x00010b28
void cm848_calculateChargeFlowTurbochargerSpeedDerate(void);  // @ 0x00010d3c
void cm848_initializeChargeManagerLimiters(void);  // @ 0x00010ed0
void cm848_calculateChargeSystemAdjustedMassChargeFlowError(void);  // @ 0x00010f68
word cm848_selectChargeSystemTransformAngle(void);  // @ 0x000110bc
void cm848_transformChargeSystemErrors(void);  // @ 0x00011170
void cm848_calculateChargeSystemErrors(void);  // @ 0x00011290
void cm848_initializeChargeSystemErrorTables(void);  // @ 0x00011324
void cm848_calculateEgrAssistControllerGains(void);  // @ 0x0001134c
void cm848_selectEgrAssistControllerLimits(void);  // @ 0x00011410
void cm848_calculateEgrAssistControllerPreset(void);  // @ 0x000114dc
void cm848_calculateEgrAssistControllerOutput(void);  // @ 0x000115cc
void cm848_runEgrAssistController(void);  // @ 0x000118f8
void cm848_initializeEgrAssistController(void);  // @ 0x00011924
undefined4 cm848_calculateRateLimitedValue(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5);  // @ 0x0001198c
void cm848_updateWastegateDutyIntegratorEnable(void);  // @ 0x00011a4c
void cm848_calculateWastegateDutyRequest(void);  // @ 0x00011ab4
void cm848_runWastegateDutyController(void);  // @ 0x0001231c
void cm848_initializeWastegateDutyController(void);  // @ 0x0001233c
word cm848_delayUnsignedSample(delay_line_t *delay_line,word sample,dword delay_samples);  // @ 0x000123dc
sword cm848_delaySignedSample(delay_line_t *delay_line,sword sample,dword delay_samples);  // @ 0x00012404
void cm848_calculateDownstreamEgrMassFlow(void);  // @ 0x0001242c
void cm848_calculateUpstreamEgrMassFlow(void);  // @ 0x000125f4
word cm848_calculateDownstreamEgrFlowSource(void);  // @ 0x00012724
word cm848_calculateUpstreamEgrFlowSource(void);  // @ 0x00012778
void cm848_calculateEgrMassFlowBeforeDelay(void);  // @ 0x000127bc
void cm848_calculateDelayedEgrFlowAndFraction(void);  // @ 0x000128a0
void cm848_initializeEgrFlowEstimate(void);  // @ 0x00012a58
void cm848_calculateVolumetricEfficiency(void);  // @ 0x00012ad4
void cm848_calculateChargeMassFlow(void);  // @ 0x00012cf4
void cm848_calculateChargeFlowEstimate(void);  // @ 0x00012dc4
void cm848_initializeChargeMassFlowFilter(void);  // @ 0x00012e40
void cm848_calculateChargeFlows(void);  // @ 0x00012e60
void cm848_initializeChargeFlows(void);  // @ 0x00012e88
void cm848_calculateFreshAirMassFlow(void);  // @ 0x00012eb4
void cm848_initializeFreshAirMassFlowFilter(void);  // @ 0x00012f40
void cm848_calculatePredictedIntakeManifoldTemperature(void);  // @ 0x00012f60
void cm848_initializePredictedIntakeManifoldTemperature(void);  // @ 0x000130ac
void cm848_calculatePumpingTorqueAdjustment(void);  // @ 0x000130dc
void cm848_initializePumpingTorqueLookupCache(void);  // @ 0x0001327c
void cm848_estimateChargePressure(void);  // @ 0x00013294
void cm848_initializeChargePressureEstimate(void);  // @ 0x0001350c
void cm848_calculateChargePressureInRangeEnable(void);  // @ 0x00013564
void cm848_updateChargePressureInRangeFaultCount(void);  // @ 0x0001359c
void cm848_monitorChargePressureInRange(void);  // @ 0x00013774
void cm848_selectLoadNormalizer (word selector,word raw_boost,word computed_boost,word filtered_boost);  // @ 0x0001392c
void cm848_processLoadNormalizerSelection (undefined4 param_1,undefined4 param_2,word param_3,word param_4);  // @ 0x00013a80
void cm848_estimateChargeTemperature(undefined4 param_1,int param_2);  // @ 0x00013aec
void cm848_initializeChargeTemperatureEstimate(void);  // @ 0x00013ca4
void cm848_calculateIntakeManifoldTemperatureLeadCompensation(void);  // @ 0x00013d14
void cm848_filterAndSelectIntakeManifoldTemperature(void);  // @ 0x00013dc8
void cm848_initializeIntakeTemperatureFilterStates(void);  // @ 0x00014080
void cm848_applyCombustionTimingLimits(void);  // @ 0x0001410c
void cm848_selectCombustionFuelCommand(void);  // @ 0x0001429c
void cm848_selectMainBaseTimingOverride(void);  // @ 0x000142d0
void cm848_setTimingIncrementFlags(void);  // @ 0x00014304
void cm848_limitMassChargeFlowReference(void);  // @ 0x00014374
void cm848_selectMassChargeFlowCommand(void);  // @ 0x00014430
void cm848_selectEgrFractionCommand(void);  // @ 0x00014464
void cm848_runCombustionLimits(void);  // @ 0x00014498
void cm848_initializeCombustionLimitLookupCaches(void);  // @ 0x000144d0
COMBUSTION_CHI_SOURCE cm848_selectChiSourceCode(int air_density_chi_hundredths,int coolant_temperature_chi_hundredths);  // @ 0x00014508
int cm848_interpolateAlphaChiValue (int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7);  // @ 0x00014528
void cm848_calculateNitrogenOxidesTargetReference(void);  // @ 0x00014610
void cm848_calculateChargeTemperatureReference(void);  // @ 0x000149a4
void cm848_calculateCombustionTimingReference(void);  // @ 0x00014d38
void cm848_calculateMassChargeFlowReference(void);  // @ 0x000150b0
void cm848_calculateEgrFractionReference(void);  // @ 0x00015444
void cm848_calculateCombustionChiMaximumFuel(void);  // @ 0x00015760
void cm848_calculateCombustionGrossFuel(void);  // @ 0x00015a24
void cm848_calculateCombustionFuelReference(void);  // @ 0x00015bd8
word cm848_interpolateTableWithoutCache(dword input,word *x_axis,word *y_data);  // @ 0x00015d2c
void cm848_lookupProtectiveChi (word *result,word input,word *x_axis,word *y_data,word *second_axis, word *second_data,word *third_data,word *fourth_data,dword lookup_signed);  // @ 0x00015e08
void cm848_determineBaseChi(void);  // @ 0x00015f34
void cm848_selectChiAndAlpha(void);  // @ 0x000160ac
void cm848_runCombustionReference(void);  // @ 0x000164ac
undefined2 cm848_lookupChiMaximumFuelAtSpeed(word param_1);  // @ 0x000164e4
int cm848_calculateTorqueFromFuelQuantity(word param_1,word param_2);  // @ 0x00016724
void cm848_calculateChiMaximumFuelAtSpeedPoints(void);  // @ 0x00016774
void cm848_initializeCombustionReferenceMapPointers(void);  // @ 0x00016888
void cm848_calculateOffNominalOxygenFractionAdjustment(void);  // @ 0x00016a90
void cm848_calculateOffNominalChargeTemperatureAdjustment(void);  // @ 0x00016c40
void cm848_calculateTimingReferenceDeltaAdjustment(void);  // @ 0x00016cd4
void cm848_applyOffNominalTimingAdjustment(void);  // @ 0x00016d6c
void cm848_calculateOffNominalCompensation(void);  // @ 0x00016e90
void cm848_runOffNominalCompensation(void);  // @ 0x00016f9c
void cm848_initializeOffNominalCompensationLookupCaches(void);  // @ 0x00016ffc
void cm848_calculateCommandedThrottleFromPedal(void);  // @ 0x0001702c
void cm848_evaluateIdleValidationSwitches(void);  // @ 0x00017150
void cm848_updateOffIdleFromIdleValidation(void);  // @ 0x000172b0
void cm848_updateThrottleTransitionState(void);  // @ 0x000172e8
void cm848_learnAcceleratorPedalAutozero(void);  // @ 0x000173a8
void cm848_monitorAcceleratorPedalIdleValidationFaults(void);  // @ 0x00017560
void cm848_selectCommandedThrottle(void);  // @ 0x0001782c
void cm848_runThrottleValidation(void);  // @ 0x00017980
void cm848_initializeCommandedThrottleState(void);  // @ 0x00017af4
void cm848_passCompensatedTimingToCombustionLimits(void);  // @ 0x00017b54
uint cm848_estimateCompressorOutletTemperature(void);  // @ 0x00017b84
void cm848_selectCompressorOutletTemperature(void);  // @ 0x00017d54
void mpc555_initFuelFlowRateVariables(void);  // @ 0x00017e54
void cm848_calculateEngineOutputTorque(void);  // @ 0x00017eb8
void cm848_calculateEgrDeltaPressures(void);  // @ 0x00017f50
void emptyStubFunction3(void);  // @ 0x0001806c
int cm848_calculateJ1939PercentPeakTorqueAtSpeed(word param_1,short param_2);  // @ 0x00018070
void cm848_calculateJ1939FrictionLoadFuelingAtBreakpoints(void);  // @ 0x0001811c
void cm848_calculateJ1939PercentPeakTorquePoints(void);  // @ 0x0001820c
void cm848_calculateJ1939PercentPeakTorque(void);  // @ 0x000182e8
void cm848_updateEgrDeltaPressureAutozeroConditions(void);  // @ 0x00018384
void cm848_updateEgrDeltaPressureAutozeroCompleteFlag(void);  // @ 0x000184f0
sword cm848_conditionalFirstOrderFilter (int value,int update_enable,ema_filter_state_t *filter_state);  // @ 0x000185cc
void cm848_updateAutozeroErrorCounter(short *param_1);  // @ 0x0001860c
void cm848_updateAutozeroOffset(sword *param_1);  // @ 0x00018780
void cm848_updateEgrDeltaPressureAutozero(void);  // @ 0x00018904
void cm848_selectEgrDeltaPressure(void);  // @ 0x00018a50
void cm848_runEgrDeltaPressureAutozero(void);  // @ 0x00018ac0
void cm848_initializeEgrDeltaPressureAutozero(void);  // @ 0x00018afc
void cm848_updateEgrValveDriverOverCurrentRetryCounter(void);  // @ 0x00018bc0
void cm848_updateEgrValveDriverOverCurrentFault(void);  // @ 0x00018cfc
void cm848_clearEgrValveDriverOverCurrentState(void);  // @ 0x00018f1c
void cm848_estimateEgrValveMotorCurrent(void);  // @ 0x00018f8c
void cm848_updateEgrValveMeanSquaredCurrent(void);  // @ 0x000191a0
void cm848_updateEgrValveOverTemperatureFault(void);  // @ 0x000191e8
void cm848_updateEgrValveMotorTemperature(void);  // @ 0x00019390
void cm848_initializeEgrValveMotorThermalModel(void);  // @ 0x0001956c
void cm848_checkEgrValveClosedHoldCondition(void);  // @ 0x000196a4
void cm848_selectEgrValveControlState(void);  // @ 0x000197b4
void cm848_selectEgrValveGainSet(void);  // @ 0x00019830
void cm848_calculateEgrValveStagedPositionCommand(void);  // @ 0x00019900
void cm848_updateEgrValvePositionCommandAndControlState(void);  // @ 0x000199f4
void cm848_updateEgrValveIntegralEnable(void);  // @ 0x00019ac0
void cm848_calculateEgrValvePidDuty(void);  // @ 0x00019b20
void cm848_selectEgrValveDutyByControlState(int param_1);  // @ 0x00019e08
void cm848_limitEgrValveBatteryCompensatedDuty(void);  // @ 0x00019ea4
void cm848_outputEgrValveDirectionAndDuty(void);  // @ 0x00019fe0
void cm848_driveEgrValveMotor(void);  // @ 0x0001a1b4
void cm848_runEgrValvePositionControlLoop(void);  // @ 0x0001a1dc
void cm848_initializeEgrValvePositionControlLoop(void);  // @ 0x0001a204
void cm848_updateEgrValveHBridgeFaultRetryTimer(int param_1);  // @ 0x0001a340
void cm848_updateEgrValveHBridgeFaultCounter(int param_1);  // @ 0x0001a47c
void cm848_updateEgrValveHBridgeInrushRetryTimer(void);  // @ 0x0001a608
void cm848_updateEgrValveHBridgeInrushFaultCounter(void);  // @ 0x0001a754
undefined4 cm848_bothConditionsTrue(int param_1,int param_2);  // @ 0x0001a980
void cm848_processEgrValveHBridgeFaults(void);  // @ 0x0001a9a8
void cm848_clearEgrValveHBridgeFaultState(void);  // @ 0x0001ae2c
void cm848_updateEgrValveAutozeroConditions(void);  // @ 0x0001af94
void cm848_updateEgrValveEnableAndDiagnosticConditions(void);  // @ 0x0001b120
void cm848_initializeEgrValveAutozeroConditions(void);  // @ 0x0001b35c
void cm848_runEgrValveFaultAndPositionControl(void);  // @ 0x0001b37c
void buildPgn65251EngineConfiguration1Payload(undefined4 *param_1);  // @ 0x0001b3a0
undefined4 cm848_hasWordChangedByTenPercent(ushort param_1,int param_2);  // @ 0x0001b624
undefined4 cm848_hasByteChangedByTenPercent(byte param_1,byte param_2);  // @ 0x0001b69c
void cm848_sendPgn65251EngineConfiguration1Message(void);  // @ 0x0001b730
void cm848_sendPgn65251EngineConfiguration1OnChange(void);  // @ 0x0001b778
void initializePgn65251EngineConfiguration1Buffer(void);  // @ 0x0001b900
void cm848_calculateColdStartFuelAdjust(void);  // @ 0x0001b99c
void cm848_initializeCrankTimingOutputs(void);  // @ 0x0001bb30
void cm848_calculateColdStartRpmAdjust(void);  // @ 0x0001bb48
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
void cm848_updateEngineState(void);  // @ 0x0001c28c
void cm848_initCrankingLimits(void);  // @ 0x0001c978
void cm848_faultTimeoutHandler(byte param_1);  // @ 0x0001c9a0
void cm848_clearFaultFromActiveList(byte param_1);  // @ 0x0001cb94
void cm848_activeFaultScanProcessor(void);  // @ 0x0001cd1c
uint cm848_faultCodeLookup(uint param_1);  // @ 0x0001cdc0
uint cm848_findFaultByTypeAndSeverity(uint param_1,ushort param_2);  // @ 0x0001ce28
void cm848_registerFaultInActiveList(uint param_1);  // @ 0x0001cea4
void cm848_clearDiagnosticState(void);  // @ 0x0001d01c
void cm848_processFaultScanGroup(void);  // @ 0x0001d224
void cm848_buildFaultConditionMask(void);  // @ 0x0001d8f8
void diagnosticMainStateProcessor(void);  // @ 0x0001d9b8
void cm848_initDiagnosticRingBuffer(void);  // @ 0x0001dcdc
void cm848_markFaultForReplacement(void);  // @ 0x0001dd10
void cm848_updateFaultEntryCounters(uint param_1);  // @ 0x0001de4c
void cm848_resetFaultStatus(int param_1);  // @ 0x0001dee0
void hpcr_setFaultActiveStatus(int param_1,uint param_2);  // @ 0x0001df64
void cm848_selectFinalFueling(void);  // @ 0x0001e22c
void cm848_clearFuelDemandFlag(void);  // @ 0x0001e4d8
void cm848_calculateProtectionRateLimited(void);  // @ 0x0001e4e8
void cm848_arbitrateRequestedFueling(void);  // @ 0x0001e5a4
void cm848_initEngineOperatingState(void);  // @ 0x0001e810
void cm848_updateFourDimensionalFueling(void);  // @ 0x0001e830
void cm848_calculateFourDimensionalInjectionTiming(void);  // @ 0x0001e870
void cm848_initProtectionTableSizes(void);  // @ 0x0001ea6c
void cm848_initFaultSeverityTables(void);  // @ 0x0001ea94
void cm848_filterCommandedThrottle(void);  // @ 0x0001eae8
void cm848_clampFuelDemandToValidRange(short *param_1);  // @ 0x0001ec48
uint cm848_calculateDualAxisFuelLimit(void);  // @ 0x0001ec70
void cm848_initFuelDemandTracking(void);  // @ 0x0001ef30
void fuelDemandProportionalCalculationSlowCycle40Coordinator(void);  // @ 0x0001ef88
uint cm848_calculateMaximumFuelCurve(word param_1,word param_2);  // @ 0x0001f03c
void cm848_calculateThrottle100Fuelings(void);  // @ 0x0001f17c
void cm848_initFuelDemandTableDimensions(void);  // @ 0x0001f300
void cm848_initializeFuelLimitChains(void);  // @ 0x0001f318
void presetHighSpeedGovernorIntegrator(void);  // @ 0x0001f34c
void runHighSpeedGovernorPid(void);  // @ 0x0001f40c
void initializeHighSpeedGovernorGainSet(void);  // @ 0x0001f98c
void selectHighSpeedGovernorGainSet(void);  // @ 0x0001fa20
void selectEngineSpeedLimit(void);  // @ 0x0001fd94
void initializeEngineSpeedLimitDefaults(void);  // @ 0x00020410
undefined1 cm848_getLimitCategoryCode(int param_1);  // @ 0x000204a8
void cm848_calculateJ1939ReferenceEngineFueling(void);  // @ 0x00020500
uint cm848_calculateEffectiveFuelLimit(void);  // @ 0x00020554
void cm848_calculateDriverDemandPercentTorque(void);  // @ 0x00020860
void cm848_calculateActualEnginePercentTorque(void);  // @ 0x000209e8
void cm848_calculateEnginePercentLoadAtCurrentSpeed(void);  // @ 0x00020a58
void cm848_emptyStubFunction7(void);  // @ 0x00020aec
void cm848_calculateNominalFrictionPercentTorque(void);  // @ 0x00020af0
void cm848_updateProtectionParameters(void);  // @ 0x00020b84
void cm848_updateProtectionInputs(void);  // @ 0x00020bfc
void cm848_setJ1939TorqueCurvePoints2And5AtDroopLineFueling(j1939_rx_msg_t *rx_msg);  // @ 0x00020c64
void cm848_updateJ1939EngineConfigurationTorqueCurve(void);  // @ 0x00020d10
void cm848_initializeJ1939ReferenceEngineFuelingAndTorque(void);  // @ 0x000212dc
void cm848_calculateEngineRetarderTorque(void);  // @ 0x00021314
void cm848_initializeEngineRetarderTorqueLookupCache(void);  // @ 0x0002156c
DIAG_RESPONSE cm848_advanceDiagnosticActionState(void);  // @ 0x00021584
DIAG_RESPONSE cm848_exitDevelopmentMode(void);  // @ 0x00021624
DIAG_RESPONSE cm848_enterDevelopmentMode(void);  // @ 0x00021668
DIAG_RESPONSE cm848_forceExitDevelopmentMode(void);  // @ 0x00021694
DIAG_RESPONSE cm848_commandEngineShutdown(void);  // @ 0x000216e8
undefined4 cm848_restartThroughBootRom(j1939_rx_msg_t *param_1,int param_2);  // @ 0x000216fc
undefined1 cm848_restartThroughBootRomAfterSciRequest(void);  // @ 0x000218b0
undefined1 cm848_handleJ1939RestartService(undefined4 param_1);  // @ 0x000218dc
DIAG_RESPONSE cm848_inhibitKeyOffShutdown(void);  // @ 0x00021904
DIAG_RESPONSE cm848_commitEepromMirrorToEeprom(void);  // @ 0x00021918
void cm848_registerJ1939DiagnosticHandlers(void);  // @ 0x00021a24
undefined2 cm848_lookupMaximumTorqueAtEngineSpeed(word param_1);  // @ 0x00021ac0
uint cm848_getHighestPriorityBit(void);  // @ 0x00021bf8
void cm848_updateProtectionThresholdsIfLow(void);  // @ 0x00021c3c
void cm848_calculateJ1939TorqueCurveFuelingsAndReferenceFuelings(void);  // @ 0x00021cd4
void j1939_receivePgn56576Handler(int param_1);  // @ 0x00021fc4
void cm848_initJ1939DiagnosticCallback(void);  // @ 0x000220b4
bool cm848_j1939RegisterDiagnosticService(byte service_id,void *handler_ptr);  // @ 0x000220e4
void cm848_j1939DiagnosticServiceHandler(j1939_rx_msg_t *rx_msg);  // @ 0x00022128
void cm848_initJ1939DiagnosticServiceHandler(void);  // @ 0x000221f0
void cm848_tickJ1939Dm13Timers(void);  // @ 0x00022220
void cm848_onJ1939Dm13SeenOnBus(void);  // @ 0x000222f8
void cm848_initJ1939Dm13Handler(void);  // @ 0x00022318
void cm848_clearJ1939Dm13StoppedNetworkBits(int param_1);  // @ 0x0002236c
void cm848_processJ1939Dm13StopStartBroadcast(int param_1);  // @ 0x000223f4
void cm848_j1939HandlePgn65228Dm3ClearDiag(j1939_rx_msg_t *param_1);  // @ 0x00022674
void cm848_initPgn65228Dm3Handler(void);  // @ 0x00022770
void cm848_j1939HandlePgn58112Dm7(j1939_rx_msg_t *request_msg);  // @ 0x000227a0
void cm848_initJ1939Dm1RequestHandler(void);  // @ 0x00022840
void cm848_j1939ProcessPgn61442Etc1(j1939_rx_msg_t *rx_msg);  // @ 0x00022870
void cm848_initJ1939Pgn61442Etc1Handler(void);  // @ 0x00022bc4
void cm848_j1939ProcessPgn61445Etc2(int param_1);  // @ 0x00022c5c
void cm848_initEtc2Handler(void);  // @ 0x00022d18
void processEngineTsc1Request(j1939_rx_msg_t *msg);  // @ 0x00022d60
bool cm848_j1939RegisterPgnHandler(dword pgn,void *handler_func);  // @ 0x00023188
void cm848_j1939DispatchPgnHandler(j1939_rx_msg_t *msg);  // @ 0x000231cc
void cm848_initJ1939ProtocolHandlers(void);  // @ 0x000232b4
void cm848_j1939HandlePgn56832Reset(j1939_rx_msg_t *param_1);  // @ 0x000233a0
void cm848_initJ1939ProprietaryHandler(void);  // @ 0x0002343c
short cm848_decodeRetarderTorqueRequestPercent(byte param_1);  // @ 0x0002346c
void cm848_selectEngineRetarderStagePercent(void);  // @ 0x000234a4
void cm848_processEngineRetarderTsc1Request(j1939_rx_msg_t *msg);  // @ 0x000236f0
void cm848_initGovernorProtectionState(void);  // @ 0x00023a9c
void cm848_dispatchTsc1ByDestinationAddress(j1939_rx_msg_t *msg);  // @ 0x00023b38
void cm848_initJ1939AddressDispatcher(void);  // @ 0x00023bb4
void cm848_sendPgn56320AntiTheftStatus(void);  // @ 0x00023be0
void cm848_initializePgn56320AntiTheftStatusBuffer(void);  // @ 0x00023cd4
void cm848_sendJ1939AcknowledgeMessage(j1939_rx_msg_t *request_msg,J1939_ACK_TYPE ack_type);  // @ 0x00023d3c
void cm848_sendJ1939NegativeAcknowledgement(j1939_rx_msg_t *msg,J1939_ACK_TYPE ack_type);  // @ 0x00023dbc
void cm848_initJ1939AckBuffer(void);  // @ 0x00023e40
void cm848_buildPgn65269AmbientConditionsMessage(void);  // @ 0x00023e8c
void cm848_initJ1939AmbientConditionsBuffer(void);  // @ 0x00023fb8
void cm848_buildPgn65241AuxiliaryInputOutputStatus1Message(void);  // @ 0x00024028
void cm848_initializePgn65241AuxiliaryInputOutputStatus1Buffer(void);  // @ 0x00024124
void cm848_buildPgn65265CruiseControlVehicleSpeedMessage(void);  // @ 0x00024178
void cm848_initPgn65265CruiseSpeedHandler(void);  // @ 0x00024664
void j1939HandlePgn65261CruiseControlSetup(void);  // @ 0x000246fc
void initPgn65261CruiseControlSetupStruct(void);  // @ 0x00024800
void cm848_j1939HandlePgn65259ComponentId(void);  // @ 0x00024870
void cm848_initPgn65259ComponentIdHandler(void);  // @ 0x00024940
void cm848_sendJ1939ResponseFrame(j1939_rx_msg_t *request,dword result_code);  // @ 0x000249c4
void cm848_sendJ1939ExtendedResponse(j1939_rx_msg_t *param_1,word param_2);  // @ 0x00024afc
void cm848_j1939HandlePgn65234Dm10(void);  // @ 0x00024b28
void cm848_initializePgn65234Dm10Handler(void);  // @ 0x00024b64
void j1939HandlePgn65226Dm1ActiveDtc(void);  // @ 0x00024be8
void cm848_processDm1FaultBroadcast(void);  // @ 0x00024d78
void cm848_initPgn65226Dm1Handler(void);  // @ 0x00024dd8
void cm848_j1939HandlePgn65227Dm2PreviousDtc(void);  // @ 0x00024e78
void cm848_initPgn65227Dm2Handler(void);  // @ 0x00025000
void cm848_initPgn65229Dm4Handler(void);  // @ 0x00025094
void cm848_j1939BuildDm4FreezeFrame(int param_1);  // @ 0x00025110
void cm848_j1939HandlePgn65229Dm4FreezeFrame(void);  // @ 0x00025390
void cm848_j1939HandlePgn65230Dm5Readiness(void);  // @ 0x00025458
void cm848_initPgn65230Dm5Handler(void);  // @ 0x0002553c
void cm848_sendPgn65232NonContinuousMonitorTestResultMessage(byte dest_address,byte fault_count);  // @ 0x000255c0
void cm848_initializePgn65232Dm8Buffer(void);  // @ 0x0002560c
void cm848_j1939BuildEngineControlByte(void);  // @ 0x0002567c
void cm848_initializePgn61441ElectronicBrakeController1Buffer(void);  // @ 0x00025824
void sendPgn61444ElectronicEngineController1Message(void);  // @ 0x0002588c
void cm848_initEec1TxDescriptor(void);  // @ 0x00025ab8
void cm848_buildPgn61443ElectronicEngineController2Message(void);  // @ 0x00025b10
void cm848_initPgn61443Eec2Handler(void);  // @ 0x00025d60
void cm848_buildPgn65247ElectronicEngineController3Message(void);  // @ 0x00025de8
void cm848_initPgn65247ElectronicEngineController3Buffer(void);  // @ 0x00025e5c
void cm848_buildPgn65263EngineFluidLevelPressure1Message(void);  // @ 0x00025eb4
void cm848_initJ1939FluidLevelPressureBuffer(void);  // @ 0x00025fb4
void cm848_buildPgn65262EngineTemperature1Message(void);  // @ 0x00026024
void cm848_initPgn65262EngineTempHandler(void);  // @ 0x0002619c
void cm848_buildPgn61440ElectronicRetarderController1Message(void);  // @ 0x00026238
void cm848_initializePgn61440ElectronicRetarderController1Buffer(void);  // @ 0x000263a4
void cm848_buildPgn65213FanDrive1Message(void);  // @ 0x0002641c
void cm848_initializePgn65213FanDrive1Buffer(void);  // @ 0x00026480
void cm848_buildPgn65270InletExhaustConditions1Message(void);  // @ 0x000264d8
void cm848_initJ1939InletExhaustConditionsBuffer(void);  // @ 0x000265d8
void cm848_buildPgn65249RetarderConfigurationMessage(void);  // @ 0x00026650
void cm848_initializePgn65249RetarderConfigurationBuffer(void);  // @ 0x0002682c
void cm848_j1939HandlePgn65242SoftwareId(void);  // @ 0x00026884
void cm848_initPgn65242SoftwareIdHandler(void);  // @ 0x000268ac
void cm848_j1939HandlePgn65504ProprietaryB(void);  // @ 0x000269f4
void cm848_initJ1939ProprietaryPgn65504Buffer(void);  // @ 0x00026b58
void cm848_j1939HandlePgn65248VehicleDistance(void);  // @ 0x00026bb0
void cm848_initPgn65248VehicleDistanceHandler(void);  // @ 0x00026c6c
void cm848_j1939HandlePgn65271VehicleElectrical(void);  // @ 0x00026cf0
void cm848_initJ1939VehicleElectricalBuffer(void);  // @ 0x00026d40
void cm848_j1939HandlePgn65260VehicleId(void);  // @ 0x00026db4
void cm848_initPgn65260VehicleIdHandler(void);  // @ 0x00026ddc
void cm848_sendPgn65279WaterInFuelIndicatorMessage(void);  // @ 0x00026e90
void cm848_initializePgn65279WaterInFuelIndicatorBuffer(void);  // @ 0x00026efc
void emptyStubFunction4(void);  // @ 0x00026f78
void cm848_emptyStubFunction5(void);  // @ 0x00026f7c
void cm848_runTsc1LostManagement(void);  // @ 0x00026f80
void cm848_resetEngineRetarderTsc1Request(void);  // @ 0x00027118
void cm848_runJ1939PowertrainControlTimeouts(void);  // @ 0x0002715c
void cm848_formatNumberAsDecimalText(byte *number,byte *text,int digit_count);  // @ 0x00027bc4
undefined4 cm848_findTsc1SourceConfiguration(int param_1,uint param_2);  // @ 0x00027cc4
void cm848_calculateLowSpeedGovernorReferenceMaximumFuelQuantity(void);  // @ 0x00027d38
void cm848_presetLowSpeedGovernorIntegrator(int param_1);  // @ 0x00027e4c
void cm848_runLowSpeedGovernor(void);  // @ 0x00027ff8
void cm848_resetSpeedControlTracking(void);  // @ 0x000285e4
void cm848_initializeLowSpeedGovernorParameters(void);  // @ 0x00028618
void cm848_updateLowSpeedGovernorAggressiveGainLogic(void);  // @ 0x00028670
void cm848_clearGovernorTimerCounters(void);  // @ 0x00028994
void cm848_resetLowSpeedGovernorAggressiveGainLogic(void);  // @ 0x000289ac
undefined4 cm848_selectLowSpeedGovernorOverrideGainSet(int param_1);  // @ 0x000289d0
void cm848_loadLowSpeedGovernorGainSet(void);  // @ 0x00028a14
void cm848_initGovernorTimerCountersWrapper(void);  // @ 0x00028abc
void cm848_initializeLowSpeedGovernorGainSelection(void);  // @ 0x00028adc
undefined4 cm848_selectLowSpeedGovernorTsc1GainSet(void);  // @ 0x00028b38
void cm848_clearGovernorFilterAccumulators(void);  // @ 0x00028b8c
void cm848_calculateLowSpeedGovernorErrorTerms(void);  // @ 0x00028ba4
void cm848_setGovernorFilterPointer(void);  // @ 0x00028d30
void cm848_calculateLowSpeedGovernorCoolantTemperatureSpeed(void);  // @ 0x00028d44
void cm848_selectLowSpeedGovernorDesiredReferenceSpeed(void);  // @ 0x0002906c
void cm848_slewLowSpeedGovernorReferenceSpeed(void);  // @ 0x000298a0
void cm848_updateLowSpeedGovernorReferenceSpeed(void);  // @ 0x00029afc
void cm848_calculateLowSpeedGovernorNoLoadFuel(void);  // @ 0x00029b38
void cm848_initializeLowSpeedGovernorReferenceSpeed(void);  // @ 0x00029bf8
void cm848_initGovernorLookupDimensions(void);  // @ 0x00029c80
void cm848_calculateFuelDemandFilter(void);  // @ 0x00029c98
void cm848_initFuelDemandFilterDimensions(void);  // @ 0x00029de0
void cm848_initProtectionFilterAccumulators(void);  // @ 0x00029e24
void cm848_calculateInjectionTimingMainMisfireLimit(void);  // @ 0x00029e50
uint cm848_absoluteValue16(uint param_1);  // @ 0x00029f3c
void cm848_checkPressureSensorAgreement(void);  // @ 0x00029f54
void cm848_processSensorDeviationOnKeyoff(void);  // @ 0x0002a214
void cm848_resetSensorDeviationTracking(void);  // @ 0x0002a2b4
void cm848_calculatePowerTakeOffGovernorSpeedError(void);  // @ 0x0002a2d0
void cm848_runPowerTakeOffGovernorPid(void);  // @ 0x0002a4b0
void cm848_applyPowerTakeOffTorqueLimit(void);  // @ 0x0002a918
void cm848_presetPowerTakeOffGovernorOnEngagement(void);  // @ 0x0002a960
void cm848_runPowerTakeOffGovernor(void);  // @ 0x0002ab2c
void cm848_initializePowerTakeOffGovernorFiltersAndGains(void);  // @ 0x0002abc8
void cm848_smoothPowerTakeOffReferenceEngineSpeed(void);  // @ 0x0002ac44
void cm848_presetPowerTakeOffSmoothedReferenceEngineSpeed(void);  // @ 0x0002ad28
void cm848_initializePowerTakeOffReferenceFilter(void);  // @ 0x0002ad48
void cm848_updatePowerTakeOffGovernorJ1939State(void);  // @ 0x0002ad68
void cm848_runPowerTakeOffGovernorStateMachine(void);  // @ 0x0002afd0
void cm848_rampPowerTakeOffReferenceEngineSpeed(void);  // @ 0x0002ba7c
void cm848_initializePowerTakeOffGovernorState(void);  // @ 0x0002bb24
void cm848_selectPowerTakeOffOrUserFueling(void);  // @ 0x0002bbe8
void cm848_initializePowerTakeOffThrottleOverride(void);  // @ 0x0002bd38
void cm848_buildPgn65264PowerTakeOffInformationMessage(void);  // @ 0x0002bd58
void cm848_initializePgn65264PowerTakeOffInformationBuffer(void);  // @ 0x0002bed4
void cm848_updateNotSafeToProgramFlag(void);  // @ 0x0002bf44
void cm848_blendAllSpeedGovernorReferenceSpeeds(void);  // @ 0x0002bf6c
void cm848_emptyStubFunction6(void);  // @ 0x0002c0fc
void cm848_initProtectionLimitVariables(void);  // @ 0x0002c100
void cm848_applySwitchSelectedEngineSpeedLimit(void);  // @ 0x0002c114
void cm848_countAcceleratorPedalPresses(void);  // @ 0x0002c180
void cm848_detectThreeAcceleratorPedalPresses(void);  // @ 0x0002c23c
void cm848_checkAcceleratorPedalSensorFaults(void);  // @ 0x0002c318
void cm848_updateSwitch31FromAcceleratorPedal(void);  // @ 0x0002c3c8
void cm848_checkSwitch31OnTimeFault(void);  // @ 0x0002c4fc
void cm848_updateVariableSpeedGovernorSelection(void);  // @ 0x0002c6c4
void cm848_estimateTurbochargerSpeed(void);  // @ 0x0002c764
void cm848_initializeTurbochargerSpeedEstimate(void);  // @ 0x0002c9bc
void cm848_calculateVariableGeometryTurbochargerPositionCommand(void);  // @ 0x0002ca14
void cm848_checkVariableGeometryTurbochargerHoldOpenCondition(void);  // @ 0x0002caa0
void cm848_selectVariableGeometryTurbochargerControlState(void);  // @ 0x0002cb54
void cm848_calculateVariableGeometryTurbochargerOpenStagedPositionCommand(void);  // @ 0x0002cbe8
void cm848_calculateVariableGeometryTurbochargerClosedStagedPositionCommand(void);  // @ 0x0002cc90
void cm848_updateVariableGeometryTurbochargerStagedPositionCommand(void);  // @ 0x0002cd38
void cm848_selectVariableGeometryTurbochargerGainSet(void);  // @ 0x0002cdb4
void cm848_updateVariableGeometryTurbochargerPositionCommandAndControlState(void);  // @ 0x0002ce8c
void cm848_calculateVariableGeometryTurbochargerPidDuty(void);  // @ 0x0002cebc
void cm848_selectVariableGeometryTurbochargerDutyByControlState(void);  // @ 0x0002d208
void cm848_limitVariableGeometryTurbochargerBatteryCompensatedDuty(void);  // @ 0x0002d2f8
void cm848_outputVariableGeometryTurbochargerDirectionAndDuty(void);  // @ 0x0002d428
void cm848_driveVariableGeometryTurbochargerMotor(void);  // @ 0x0002d5d8
void cm848_runVariableGeometryTurbochargerPositionControlLoop(void);  // @ 0x0002d600
void cm848_initializeVariableGeometryTurbochargerPositionControlLoop(void);  // @ 0x0002d638
void cm848_updateVariableGeometryTurbochargerHBridgeFaultRetryTimer(int param_1);  // @ 0x0002d7a4
void cm848_updateVariableGeometryTurbochargerHBridgeFaultCounter(int param_1);  // @ 0x0002d88c
void cm848_updateVariableGeometryTurbochargerHBridgeInrushRetryTimer(int param_1);  // @ 0x0002d9f4
bool cm848_updateVariableGeometryTurbochargerHBridgeInrushFaultCounter(int param_1);  // @ 0x0002dadc
void cm848_processVariableGeometryTurbochargerHBridgeFaults(void);  // @ 0x0002dc40
void cm848_clearVariableGeometryTurbochargerHBridgeFaultState(void);  // @ 0x0002e02c
void cm848_updateVariableGeometryTurbochargerFaultHoldoff(void);  // @ 0x0002e17c
void cm848_detectVariableGeometryTurbochargerMissionReset(void);  // @ 0x0002e1f0
void cm848_runVariableGeometryTurbochargerClosedStopSeek(void);  // @ 0x0002e250
void cm848_checkVariableGeometryTurbochargerPositionNearOpenStop(void);  // @ 0x0002e488
void cm848_runVariableGeometryTurbochargerOpenStopSeek(void);  // @ 0x0002e4cc
void cm848_sequenceVariableGeometryTurbochargerPositionAdjustment(void);  // @ 0x0002e74c
void cm848_clearVariableGeometryTurbochargerStopSeekState(void);  // @ 0x0002e9c8
void cm848_updateVariableGeometryTurbochargerDriverOverCurrentFault(void);  // @ 0x0002ea58
void cm848_clearVariableGeometryTurbochargerDriverOverCurrentState(void);  // @ 0x0002ed30
void cm848_updateVariableGeometryTurbochargerClosedAdjustmentErrorLatch(void);  // @ 0x0002edc0
void cm848_filterVariableGeometryTurbochargerClosedPosition(void);  // @ 0x0002ef34
void cm848_evaluateVariableGeometryTurbochargerClosedAdjustment(void);  // @ 0x0002efe4
void cm848_updateVariableGeometryTurbochargerSpanAdjustmentErrorLatch(void);  // @ 0x0002f154
void cm848_filterVariableGeometryTurbochargerSpan(void);  // @ 0x0002f2c8
void cm848_evaluateVariableGeometryTurbochargerSpanAdjustment(void);  // @ 0x0002f3a0
void cm848_calculateVariableGeometryTurbochargerAdjustedPosition(void);  // @ 0x0002f524
void cm848_evaluateVariableGeometryTurbochargerPositionAdjustments(void);  // @ 0x0002f5a4
void cm848_selectVariableGeometryTurbochargerPositionSource(void);  // @ 0x0002f604
void cm848_updateVariableGeometryTurbochargerPosition(void);  // @ 0x0002f6a0
void cm848_initializeVariableGeometryTurbochargerAdjustmentFilters(void);  // @ 0x0002f784
void cm848_requestOverdriveShiftsLowRange(void);  // @ 0x0002f860
void cm848_selectGovernorPressureLowRange(void);  // @ 0x0002f920
void cm848_applyConverterLockupScheduleLowRange(void);  // @ 0x0002fe48
void cm848_applyConverterUnlockConditionsLowRange(void);  // @ 0x0003004c
void cm848_applyConverterLockupSchedule(void);  // @ 0x00030194
void cm848_applyConverterUnlockConditions(void);  // @ 0x00030ad4
void cm848_requestOverdriveShiftsNormal(void);  // @ 0x00031320
void cm848_selectGovernorPressureCold(void);  // @ 0x0003148c
void cm848_selectGovernorPressureBaseCurve(void);  // @ 0x00031584
void cm848_selectGovernorPressureWideOpenThrottle(void);  // @ 0x000316cc
void cm848_selectGovernorPressureCruise(void);  // @ 0x00031d98
uint cm848_calculateTransmissionOutputTorqueInGear(int param_1);  // @ 0x000320e0
void cm848_predictPostShiftAcceleration(void);  // @ 0x00032250
void cm848_learnVehicleInertia(void);  // @ 0x0003241c
void cm848_selectGovernorPressureAntiHunt(void);  // @ 0x0003257c
void cm848_selectGovernorPressureNormal(void);  // @ 0x00032b00
void cm848_runTransmissionControl(void);  // @ 0x00032efc
void cm848_initializeTransmissionShiftLogic(void);  // @ 0x000331cc
void cm848_updateTransmissionControlInputs(void);  // @ 0x00033488
void cm848_decrementTransmissionTimers(void);  // @ 0x000335e4
void cm848_determineCurrentGearAndLockupInhibit(void);  // @ 0x00033948
void cm848_updateTransmissionConditionFlags(void);  // @ 0x000343ac
void cm848_calculateOutputShaftAcceleration(void);  // @ 0x0003491c
void cm848_updateTransmissionRelayRequest(void);  // @ 0x00034a30
void cm848_updateTransmissionControlState(void);  // @ 0x00034abc
void cm848_initializeTransmissionControl(void);  // @ 0x00034b14
void cm848_updateTransmissionLimpHomeFlags(void);  // @ 0x00034dd4
void cm848_updateExhaustBrakeInhibitForLockup(void);  // @ 0x00034f4c
void cm848_selectGovernorPressureLockupBoost(void);  // @ 0x00035154
void cm848_runTransmissionControlWhenEnabled(void);  // @ 0x00035328
void cm848_selectSensorValuesInUse(void);  // @ 0x00035370
void cm848_copySensorValuesInUseUnchecked(void);  // @ 0x00035518
void cm848_processAirConditioningPressureChannel(void);  // @ 0x00035558
void cm848_initializeAirConditioningPressureChannel(void);  // @ 0x000355e4
void cm848_processBatteryTemperatureChannel(void);  // @ 0x00035670
void cm848_initializeBatteryTemperatureChannel(void);  // @ 0x000356fc
void cm848_processCruiseSwitchChannel(void);  // @ 0x00035788
void cm848_initializeCruiseSwitchChannel(void);  // @ 0x00035814
void cm848_processAcceleratorPedalPositionSensor1Channel(void);  // @ 0x000358a0
void cm848_initializeAcceleratorPedalPositionSensor1Channel(void);  // @ 0x0003592c
void cm848_processAcceleratorPedalPositionSensor2Channel(void);  // @ 0x000359b8
void cm848_initializeAcceleratorPedalPositionSensor2Channel(void);  // @ 0x00035a44
void cm848_processFourWheelDriveSwitchChannel(void);  // @ 0x00035ad0
void cm848_initializeFourWheelDriveSwitchChannel(void);  // @ 0x00035b5c
void cm848_processGovernorPressureChannel(void);  // @ 0x00035be8
void cm848_initializeGovernorPressureChannel(void);  // @ 0x00035c74
void cm848_processSensorTemperatureData(void);  // @ 0x00035d00
void cm848_enableSensorFilterUpdate(void);  // @ 0x00035d70
void cm848_learnOutputSpeedToVehicleSpeedRatio(void);  // @ 0x00035d80
void cm848_initializeInjectorDriverBoosterCapacitorMonitor(void);  // @ 0x00035f14
void cm848_monitorInjectorDriverBoosterCapacitorVoltage(void);  // @ 0x00035fa8
void cm848_queueSupervisorStatusRead(void);  // @ 0x000367a4
void cm848_onSupervisorStatusRead(void);  // @ 0x000367f0
void cm848_queueSupervisorOutputWrite(void);  // @ 0x0003682c
void cm848_queueSupervisorRegister36Read(void);  // @ 0x0003686c
void cm848_onSupervisorRegister36Read(void);  // @ 0x00036898
void cm848_answerSupervisorWatchdog(void);  // @ 0x0003691c
void cm848_runSupervisorWatchdogCycle(void);  // @ 0x000369cc
void cm848_paceSupervisorWatchdogCycle(void);  // @ 0x00036b10
void cm848_queueSupervisorRegister46Read(void);  // @ 0x00036b68
void cm848_onSupervisorRegister46Read(void);  // @ 0x00036bc4
void cm848_queueSupervisorRegister162Read(void);  // @ 0x00036bd8
void cm848_onSupervisorRegister162Read(void);  // @ 0x00036c04
void cm848_writeSupervisorConfiguration(void);  // @ 0x00036c1c
void cm848_runSupervisorChipSchedule(void);  // @ 0x00036cec
void cm848_configureSupervisorChip(void);  // @ 0x00036de0
void cm848_startSupervisorWatchdog(void);  // @ 0x00036f48
void cm848_initSupervisorRegister36ReadJob(void);  // @ 0x00037130
void cm848_initSupervisorStatusReadJob(void);  // @ 0x00037180
void cm848_initSupervisorOutputWriteJob(void);  // @ 0x000371d0
void cm848_initSupervisorRegister46ReadJob(void);  // @ 0x00037214
void cm848_initSupervisorRegister162ReadJob(void);  // @ 0x00037270
void cm848_initSupervisorConfigurationWriteJob(void);  // @ 0x000372c0
void cm848_initSupervisorChip(void);  // @ 0x00037334
void cm848_calculateColdDeltaFuel(void);  // @ 0x000373b0
void cm848_initializeColdDeltaFuelLookupCache(void);  // @ 0x0003744c
void cm848_onSerialOutputDriverReply(void);  // @ 0x00037464
void cm848_initSerialOutputDriverJob(void);  // @ 0x000374b8
void cm848_queueSerialOutputDriverWrite(void);  // @ 0x00037580
void cm848_calculateChargingVoltageTarget(void);  // @ 0x000375c8
void cm848_calculateChargingVoltageError(void);  // @ 0x00037658
void cm848_updateAlternatorFieldRegulatorState(void);  // @ 0x000376dc
void cm848_calculateAlternatorFieldDutyByRegulatorState(void);  // @ 0x00037744
void cm848_calculateAlternatorFieldDutyByPid(void);  // @ 0x00037a40
void cm848_applyAlternatorFieldDuty(void);  // @ 0x00037c74
void cm848_monitorChargingSystemVoltageHighAndLow(void);  // @ 0x00037f28
void cm848_testAlternatorOutputByCuttingField(void);  // @ 0x00038120
undefined4 cm848_evaluateAlternatorFieldRegulatorIdleState(void);  // @ 0x00038338
undefined4 cm848_evaluateAlternatorFieldRegulatorStartRampState(void);  // @ 0x00038384
undefined4 cm848_evaluateAlternatorFieldRegulatorRegulationState(void);  // @ 0x000383f0
undefined4 cm848_evaluateAlternatorFieldRegulatorLoadResponseState(void);  // @ 0x0003844c
void cm848_initializeAlternatorFieldControl(void);  // @ 0x000384d0
void cm848_calculateMainInjectionEndTiming(void);  // @ 0x0003866c
void cm848_processEngineRpmDerivative(void);  // @ 0x00038760
void cm848_initEngineRpmFilterPointers(void);  // @ 0x00038824
void cm848_setEngineRpmFromCalibration(void);  // @ 0x00038868
void cm848_applyFuelPressureGovernorFaultBlend(void);  // @ 0x0003889c
void cm848_initProtectionFilterLimits(void);  // @ 0x00038a98
void cm848_checkPciMessageTimeouts(void);  // @ 0x00038ac8
void cm848_onPciControllerInterrupt(void);  // @ 0x00038c90
void cm848_matchPciReceiveHeader(void);  // @ 0x00038cf0
void cm848_completePciFrame(void);  // @ 0x00039004
void cm848_handlePciInFrameResponseTimeout(void);  // @ 0x00039bc0
void cm848_sendPciFrameByte(void);  // @ 0x00039c44
void cm848_sendPciInFrameResponseByte(void);  // @ 0x00039d18
void cm848_servicePciTransmit(void);  // @ 0x00039e30
void cm848_onPciControllerReceiveWord(void);  // @ 0x00039f54
void cm848_resetPciReceiveState(void);  // @ 0x0003a058
void cm848_resetPciTransmitState(void);  // @ 0x0003a080
void cm848_pulsePciControllerLine124(void);  // @ 0x0003a0cc
void hpcr_initPciMessageTimers(void);  // @ 0x0003a100
undefined4 cm848_handlePciLinkEvent(void);  // @ 0x0003a290
void cm848_initPciMessagePayloads(void);  // @ 0x0003a450
void cm848_initializePciMessageStatusBytes(void);  // @ 0x0003a9a4
void cm848_initPciInFrameResponseBytes(void);  // @ 0x0003aaf0
void cm848_clearCanMessageBuffers(void);  // @ 0x0003ab20
void cm848_initPciControllerInterface(void);  // @ 0x0003abc4
void cm848_initJ1939CommunicationSystem(void);  // @ 0x0003ad04
void cm848_continuePciControllerInit(void);  // @ 0x0003ad80
void cm848_schedulePciTransmit(void);  // @ 0x0003adcc
void cm848_latchPciIdleSpeedRequest(void);  // @ 0x0003af7c
undefined4 cm848_validatePciSecurityKey(uint param_1,uint param_2);  // @ 0x0003afb8
void cm848_processPciDiagnosticRequest(void);  // @ 0x0003b030
void cm848_diagnoseClusterLampStatusMessage(void);  // @ 0x0003b910
void cm848_updateSelectedGearFromShiftLever(void);  // @ 0x0003bb28
void cm848_emptyStub10(void);  // @ 0x0003bd10
void cm848_latchAndCheckEngineOffTime(void);  // @ 0x0003bd14
void cm848_updateAirConditioningSwitchFromPci(void);  // @ 0x0003be30
void cm848_processPciRemoteFaultStatus(void);  // @ 0x0003be90
void cm848_decodePciReceiveMessage13State(void);  // @ 0x0003c018
void cm848_buildPciTransmitMessage12StatusBits(void);  // @ 0x0003c044
void cm848_buildPciTransmitMessage18TransmissionTemperature(void);  // @ 0x0003c140
void cm848_emptyStub11(void);  // @ 0x0003c188
void cm848_buildPciTransmitMessage4EngineLoadAndStatus(void);  // @ 0x0003c18c
void cm848_buildPciTransmitMessage0EngineSpeedAndVehicleSpeed(void);  // @ 0x0003c26c
void cm848_buildPciTransmitMessage2CruiseControlAndStatusBits(void);  // @ 0x0003c2f0
void cm848_buildPciTransmitMessage5EngineWarningBits(void);  // @ 0x0003c5f0
void cm848_buildPciTransmitMessage11DistanceAndFuelUsed(void);  // @ 0x0003c6b0
void cm848_buildPciTransmitMessage13FuelLevel(void);  // @ 0x0003c880
void cm848_buildPciTransmitMessage14VoltageOilPressureTemperatures(void);  // @ 0x0003c8ec
void mpc555_initFuelDemandFilterPointers(void);  // @ 0x0003ca90
void cm848_buildPciTransmitMessage17FaultBits(void);  // @ 0x0003cab0
void cm848_buildPciTransmitMessage16AirConditioningPressure(void);  // @ 0x0003cbd4
void cm848_buildPciTransmitMessage15DistanceHighByte(void);  // @ 0x0003cc98
void cm848_calculateNetTorqueFuelLimit(void);  // @ 0x0003ccb4
void cm848_applyNetTorqueFuelLimit(void);  // @ 0x0003cefc
void mpc555_initFuelDemandTrackingState(void);  // @ 0x0003cf40
void cm848_updateAcceleratorPedalSensorFaultFlags(void);  // @ 0x0003cf68
void cm848_checkAcceleratorPedalChannelAgreement(void);  // @ 0x0003d070
void cm848_calculateAcceleratorPedalDemandFromChannels(void);  // @ 0x0003d204
void cm848_learnAcceleratorPedalIdlePositions(void);  // @ 0x0003d3b8
void cm848_initializeAcceleratorPedalIdlePositions(void);  // @ 0x0003d5fc
void mpc555_qspiApplyDeviceSlotTiming(byte device_slot);  // @ 0x0003d618
uint cm848_registerQspiDeviceSlot (dword spi_mode,dword clock_khz,dword clock_delay_ns,dword transfer_delay);  // @ 0x0003d68c
void mpc555_qspiStartJob(dword job_index,dword queue_index);  // @ 0x0003d904
int cm848_queueQspiJob(qspi_job_t *job,dword queue_index);  // @ 0x0003da60
void cm848_completeQspiJob(void);  // @ 0x0003dbc0
void cm848_onQspiFinished(void);  // @ 0x0003dcf4
void mpc555_initQsmcmQspiModule(void);  // @ 0x0003dd28
void cm848_initializeTransmissionOutputSpeedSensorMonitor(void);  // @ 0x0003dd88
void cm848_monitorTransmissionOutputSpeedSensor(void);  // @ 0x0003dd98
void cm848_calculateVehicleSpeed(void);  // @ 0x0003dfb8
void cm848_requestPowerDownDelayWhileVehicleMoving(void);  // @ 0x0003e210
void cm848_initVehicleSpeedCalculation(void);  // @ 0x0003e230
void cm848_calculateRockCycleEngineSpeedLimit(void);  // @ 0x0003e2bc
void cm848_initializeRockCycleEngineSpeedLimit(void);  // @ 0x0003e400
void cm848_calculateMaximumRoadSpeeds(void);  // @ 0x0003e42c
void cm848_initializeMaximumRoadSpeeds(void);  // @ 0x0003e520
void cm848_sciResetReceiveState(void);  // @ 0x0003e578
void cm848_dispatchSciInterrupt(void);  // @ 0x0003e5ac
void cm848_sciCommand35Handler(void);  // @ 0x0003e5f0
void cm848_sciCommand35Callback(void);  // @ 0x0003e620
void cm848_sciCommand53Handler(void);  // @ 0x0003e7c0
void cm848_sciCommand53Callback(void);  // @ 0x0003e7f0
void cm848_sciCallbackTimeout(void);  // @ 0x0003e8d8
void cm848_sciStartCallbackTimeout(void);  // @ 0x0003e938
void cm848_sciCancelCallbackTimeout(void);  // @ 0x0003e948
void cm848_sciInitDefaultCallback(void);  // @ 0x0003e958
void cm848_monitorConverterSlipAndEngineSpeedLimit(void);  // @ 0x0003e96c
void cm848_initializeConverterSlipEngineSpeedLimit(void);  // @ 0x0003eca4
void cm848_setThermalProtectionMode5(void);  // @ 0x0003eccc
void cm848_evaluateTorqueManagementRequired(void);  // @ 0x0003ecdc
void cm848_calculateTorqueManagementFuelTableLimit(void);  // @ 0x0003eea8
void cm848_holdTorqueManagementFuelLimitDuringExitDelay(void);  // @ 0x0003f054
void cm848_rampTorqueManagementFuelLimitUpOnExit(void);  // @ 0x0003f0b8
void cm848_rampTorqueManagementFuelLimitDownOnEntry(void);  // @ 0x0003f154
void cm848_selectTorqueManagementFuelLimitOutsideTransitions(void);  // @ 0x0003f218
void cm848_runTorqueManagement(void);  // @ 0x0003f2b0
void cm848_applyTorqueManagementFuelLimit(void);  // @ 0x0003f35c
void cm848_initializeTorqueManagement(void);  // @ 0x0003f38c
void cm848_selectTransmissionTemperatureInUse(void);  // @ 0x0003f3f0
void cm848_resetTransmissionTemperatureValidation(void);  // @ 0x0003f6fc
void cm848_calculateTransmissionOutputSpeed(void);  // @ 0x0003f734
void cm848_initTransmissionOutputSpeedFilters(void);  // @ 0x0003f9c4
void mpc555_updateOutputSpeedSensorPeriod(void);  // @ 0x0003fa5c
void mpc555_initTpuBConfiguration(void);  // @ 0x0003fad4
void cm848_initCruiseServoControl(void);  // @ 0x0003fba4
void cm848_controlCruiseVacuumServo(void);  // @ 0x0003fc24
void cm848_applyWastegateSolenoidDuty(void);  // @ 0x000400b8
void cm848_dispatchCalibrationBlockHandlers(void);  // @ 0x000402d4
void cm848_claimAcceleratorInterlockThrottleOverride(void);  // @ 0x000403e4
void cm848_arbitrateGovernedFueling(void);  // @ 0x0004043c
void cm848_initFuelFilterCoefficients(void);  // @ 0x00040828
void cm848_calculateRiseLimitedVehicleSpeed(void);  // @ 0x00040844
uint cm848_minimumSignedWord(uint param_1,uint param_2);  // @ 0x0004091c
void cm848_decreaseCruiseSpeedCommand(int param_1);  // @ 0x00040938
void cm848_increaseCruiseSpeedCommand(int param_1);  // @ 0x00040978
void cm848_cruiseSpeedCommandStateMachine(void);  // @ 0x000409b0
void cm848_saveCruiseSetSpeedForPowerDown(void);  // @ 0x00040d40
void cm848_restoreSavedCruiseSetSpeed(void);  // @ 0x00040d74
void cm848_snapshotHighSpeedGovernorFueling(void);  // @ 0x00040dd4
void cm848_limitLowSpeedGovernorFueling(void);  // @ 0x00040de8
void cm848_calculateCruiseControlFueling(void);  // @ 0x00040e4c
void cm848_calculateRoadSpeedGovernorFueling(void);  // @ 0x00040f80
void cm848_selectCruiseOrUserFueling(void);  // @ 0x000411b0
void cm848_updateEngineRetarderAllowedState(void);  // @ 0x00041368
void cm848_calculateEngineRetarderSelectionPercent(void);  // @ 0x00041938
void cm848_limitEngineRetarderPercentToOperatorSelection(void);  // @ 0x00041a10
void cm848_applyEngineRetarderTsc1Request(void);  // @ 0x00041a40
void cm848_selectEngineRetarderCommand(void);  // @ 0x00041b24
void cm848_updateEngineRetarderActiveState(void);  // @ 0x00041be4
void cm848_driveEngineRetarderOutput(void);  // @ 0x00041fd4
void cm848_processEngineRetarderRequest(void);  // @ 0x0004218c
void cm848_initializeEngineRetarderRequestState(void);  // @ 0x000421c8
void cm848_calculateHighSpeedGovernorCompensatedEngineSpeed(void);  // @ 0x000422c0
void cm848_initializeHighSpeedGovernorCompensatedEngineSpeed(void);  // @ 0x00042438
void cm848_loadHighSpeedGovernorWorkingGainSet(void);  // @ 0x00042488
void cm848_selectLowSpeedGovernorGearGainSet(void);  // @ 0x0004256c
void cm848_inhibitLowSpeedGovernorAggressiveGains(void);  // @ 0x0004271c
void cm848_selectTwoSpeedRearAxleRatio(void);  // @ 0x0004272c
void cm848_initializeRearAxleRatio(void);  // @ 0x00042770
void cm848_copyMainInjectionTiming(void);  // @ 0x00042784
void cm848_applyFuelPressureFaultFuelLimit(void);  // @ 0x0004279c
void cm848_applyTsc1TorqueLimit(void);  // @ 0x000427cc
void cm848_processProtectionLimits(void);  // @ 0x0004280c
void cm848_initializeFuelDemandAndLimitInterpolationStates(void);  // @ 0x0004285c
void cm848_setEngineOperatingMode1(void);  // @ 0x00042894
void cm848_selectUserCommandedFueling(void);  // @ 0x000428d4
void cm848_resetEngineOperatingMode(void);  // @ 0x00042918
void cm848_dispatchModeHandlers(void);  // @ 0x00042978
void cm848_processInjectorDriverBoosterCapacitor1VoltageChannel(void);  // @ 0x000429a0
void cm848_initializeInjectorDriverBoosterCapacitor1VoltageChannel(void);  // @ 0x00042a2c
void cm848_processInjectorDriverBoosterCapacitor2VoltageChannel(void);  // @ 0x00042ab8
void cm848_initializeInjectorDriverBoosterCapacitor2VoltageChannel(void);  // @ 0x00042b44
void hpcr_cbdFillAccelerationBuffers(void);  // @ 0x00042bd0
void hpcr_filterCylinderBalanceFueling(void);  // @ 0x00042cfc
void hpcr_cbdCalculateCylinderTrims(void);  // @ 0x00042d78
void hpcr_cbdInitFilterState(void);  // @ 0x00043a5c
void cm848_runCylinderContributionTest(void);  // @ 0x00043ac0
void hpcr_clearTimingCalibrationData(void);  // @ 0x00043d68
void mpc555_resetEngineTimingAccumulators(void);  // @ 0x00043ddc
void cm848_updateEngineSpeedFromCrankSignal(void);  // @ 0x00044374
void cm848_setCrankPreliminarySyncFromCam(void);  // @ 0x00044aa4
void cm848_exitSpeedLimpHome(void);  // @ 0x00044ae0
void cm848_enterSpeedLimpHome(void);  // @ 0x00044b54
void engine_injectionTiming_crankSyncDispatch(void);  // @ 0x00044bf4
void cm848_enterCamSyncLost(void);  // @ 0x00044cc8
void cm848_enterCrankSyncLost(void);  // @ 0x00044d20
void cm848_enterCrankInSync(void);  // @ 0x00044d70
void cm848_reenterCrankPreliminarySync(void);  // @ 0x00044dd0
void cm848_setCrankInSyncFromCam(void);  // @ 0x00044e3c
void cm848_enterCrankInSyncFromCam(void);  // @ 0x00044eac
void cm848_enterCrankPreliminarySync(void);  // @ 0x00044f0c
void hpcr_processEngineSyncPulses(void);  // @ 0x00044fa8
void mpc555_updateCrankSyncState(void);  // @ 0x00045478
void mpc555_handleCamSignalInterrupt(void);  // @ 0x000457d0
void cm848_calculateAllSpeedGovernorEquivalentThrottle(void);  // @ 0x00045ecc
void cm848_initRpmSetpointFilters(void);  // @ 0x0004665c
void cm848_calculateAuxiliaryInjectionQuantityLimit(void);  // @ 0x000466a8
void cm848_initializeAuxiliaryInjectionQuantityState(void);  // @ 0x00046cf8
void cm848_monitorInjectionLimitViolationCounters(void);  // @ 0x00046d90
void cm848_clearTimingAccumulators(void);  // @ 0x00046f64
void cm848_calculateMainInjectionPulseWidth(void);  // @ 0x00046f7c
void cm848_calculatePilotInjectionPulseWidth(void);  // @ 0x00047140
void cm848_calculateAuxiliaryInjectionPulseWidth(int param_1);  // @ 0x00047394
void cm848_setMainQuantityAndPulseWidthLimits(void);  // @ 0x0004769c
void mpc555_clearTimingDataAndFilters(void);  // @ 0x00047784
sword cm848_applyPiecewiseLinearGain(piecewise_linear_gain_t *gain,int input);  // @ 0x00047838
sword cm848_integrateWithZoneGain (piecewise_linear_gain_t *gain,q16_fixed_point_t *accumulator,int error,dword step);  // @ 0x00047978
sword cm848_calculateFilteredDerivative (derivative_gain_t *gain,q16_fixed_point_t *filter_state,int input);  // @ 0x00047a88
void cm848_calculateFuelMeteringCommand(void);  // @ 0x00047bd0
void cm848_countFuelPressureGovernorStartRevolutions(void);  // @ 0x00048fa0
void cm848_initializeFuelPressureGovernorState(void);  // @ 0x00049004
void cm848_filterEngineSensorValue(void);  // @ 0x0004922c
void cm848_diagnoseFuelPressureGovernor(void);  // @ 0x00049264
void cm848_updateFuelPressureDiagnosticCountersAndCheckFeedbackCircuit(void);  // @ 0x00049a54
void cm848_updateFuelPressureFaultReactionRequests(void);  // @ 0x00049df0
void cm848_applyFuelLimitsForFuelPressureFaults(void);  // @ 0x00049edc
void cm848_updateFuelPressureLimpHomeActiveFlag(void);  // @ 0x0004a114
void cm848_initializeFuelPressureDiagnosticState(void);  // @ 0x0004a258
void cm848_setFuelMeteringPwm(void);  // @ 0x0004a2f8
void mpc555_initTpuTimingInterrupts(void);  // @ 0x0004a37c
void cm848_processFuelPressureSensor(void);  // @ 0x0004a490
void cm848_countFuelPressureSensorCodeChanges(void);  // @ 0x0004a748
void cm848_filterFuelPressureFeedback(void);  // @ 0x0004a7ac
void cm848_initFuelPressureSensor(void);  // @ 0x0004a858
void cm848_sampleFuelPressureSensor(void);  // @ 0x0004a8cc
void cm848_updateInjectorDiagnosticBits(uint param_1,int param_2);  // @ 0x0004a968
void cm848_evaluateInjectorDiagnosticFault (uint param_1,ushort *param_2,int param_3,int param_4,int param_5);  // @ 0x0004aaac
void cm848_evaluateInjectorDiagnostics(void);  // @ 0x0004ac3c
void cm848_initTimingFilterStates(void);  // @ 0x0004ad8c
void cm848_calculateMainInjectionTiming(void);  // @ 0x0004ae20
void cm848_selectMainInjectionTiming(void);  // @ 0x0004b5b8
void cm848_calculateFuelLimitByRpmAndDemand(void);  // @ 0x0004b6cc
void cm848_applyFuelLimitByRpmAndDemand(void);  // @ 0x0004b9ac
void cm848_evaluateCalibratedMonitorDisableConditions(void);  // @ 0x0004ba48
void cm848_copyRomToRamBuffer(void);  // @ 0x0004bd00
bool cm848_isEepromWriteQueueEmpty(void);  // @ 0x0004bd3c
void cm848_startEepromBlockRead(void);  // @ 0x0004bd5c
void cm848_writeNextQueuedEepromByte(void);  // @ 0x0004be4c
undefined4 cm848_queueEepromByteWrites(word param_1,int param_2,uint param_3);  // @ 0x0004bf90
undefined4 cm848_queueEepromByteWritesAtOffset11134(short param_1,int param_2,uint param_3);  // @ 0x0004c070
void cm848_pollEepromStatus(void);  // @ 0x0004c188
void cm848_runEepromPageWrite(void);  // @ 0x0004c2d4
void cm848_startEepromMirrorSave(void);  // @ 0x0004c69c
void cm848_onEepromStatusRead(void);  // @ 0x0004c734
void cm848_onEepromBlockRead(void);  // @ 0x0004c7ec
void cm848_verifyEepromPageWrite(void);  // @ 0x0004c8d8
bool cm848_isEepromMirrorSaveIdle(void);  // @ 0x0004cb34
word cm848_getEepromVerifyRetryTotal(void);  // @ 0x0004cb4c
word cm848_getEepromMirrorChecksum(void);  // @ 0x0004cb58
void cm848_initEepromDriverAndLoadMirror(void);  // @ 0x0004cb64
int cm848_readInjectorDiagnosticWord(void);  // @ 0x0004cd50
void cm848_initSensorRetryCounters(void);  // @ 0x0004ce78
void cm848_miosChannel11EnablePwm(void);  // @ 0x0004ce9c
void cm848_miosChannel11SetPwmDuty(word param_1);  // @ 0x0004cec4
void cm848_miosChannel11SetPwmPeriod(undefined4 param_1);  // @ 0x0004cef0
void cm848_miosChannel12EnablePwm(void);  // @ 0x0004cf1c
void cm848_miosChannel12SetPwmDuty(word param_1);  // @ 0x0004cf44
void cm848_miosChannel12SetPwmPeriod(undefined4 param_1);  // @ 0x0004cf70
void cm848_miosChannel13EnablePwm(void);  // @ 0x0004cf9c
void cm848_miosChannel13SetPwmDuty(word param_1);  // @ 0x0004cfc4
void cm848_miosChannel13SetPwmPeriod(undefined4 param_1);  // @ 0x0004cff0
void cm848_miosChannel14EnablePwm(void);  // @ 0x0004d01c
void cm848_miosChannel14SetPwmDuty(word param_1);  // @ 0x0004d044
void cm848_miosChannel14SetPwmPeriod(undefined4 param_1);  // @ 0x0004d070
void cm848_miosChannel15EnablePwm(void);  // @ 0x0004d09c
void cm848_miosChannel15SetPwmDuty(word param_1);  // @ 0x0004d0c4
void cm848_miosChannel15SetPwmPeriod(undefined4 param_1);  // @ 0x0004d0f0
void cm848_miosChannel27EnablePwm(void);  // @ 0x0004d11c
void cm848_miosChannel27SetPwmDuty(word param_1);  // @ 0x0004d144
void cm848_miosChannel27SetPwmPeriod(undefined4 param_1);  // @ 0x0004d170
void cm848_miosChannel28EnablePwm(void);  // @ 0x0004d19c
void cm848_miosChannel28SetPwmDuty(word param_1);  // @ 0x0004d1c4
void cm848_miosChannel28SetPwmPeriod(undefined4 param_1);  // @ 0x0004d1f0
void cm848_miosChannel29EnablePwm(void);  // @ 0x0004d21c
void cm848_miosChannel29SetPwmDuty(word param_1);  // @ 0x0004d244
void cm848_miosChannel29SetPwmPeriod(undefined4 param_1);  // @ 0x0004d270
void cm848_miosChannel30EnablePwm(void);  // @ 0x0004d29c
void cm848_miosChannel30SetPwmDuty(word param_1);  // @ 0x0004d2c4
void cm848_miosChannel30SetPwmPeriod(undefined4 param_1);  // @ 0x0004d2f0
void cm848_miosChannel31EnablePwm(void);  // @ 0x0004d31c
void cm848_miosChannel31SetPwmDuty(word param_1);  // @ 0x0004d344
void cm848_miosChannel31SetPwmPeriod(undefined4 param_1);  // @ 0x0004d370
void cm848_miosPwm0Enable(void);  // @ 0x0004d39c
void cm848_miosPwm0SetDuty(word param_1);  // @ 0x0004d3c4
void cm848_miosPwm0SetPeriodMicroseconds(undefined4 param_1);  // @ 0x0004d3f0
void cm848_miosPwm1Enable(void);  // @ 0x0004d41c
void cm848_miosPwm1SetDuty(word param_1);  // @ 0x0004d444
void cm848_miosPwm1SetPeriodMicroseconds(undefined4 param_1);  // @ 0x0004d470
void cm848_miosPwm2Enable(void);  // @ 0x0004d49c
void cm848_miosPwm2SetDuty(word param_1);  // @ 0x0004d4c4
void cm848_miosPwm2SetPeriodMicroseconds(undefined4 param_1);  // @ 0x0004d4f0
void cm848_miosPwm3Enable(void);  // @ 0x0004d51c
void cm848_miosPwm3SetDuty(word param_1);  // @ 0x0004d544
void cm848_miosPwm3SetPeriodMicroseconds(undefined4 param_1);  // @ 0x0004d570
void cm848_miosPwm16Enable(void);  // @ 0x0004d59c
void cm848_miosPwm16SetDuty(word param_1);  // @ 0x0004d5c4
void cm848_miosPwm16SetPeriodMicroseconds(undefined4 param_1);  // @ 0x0004d5f0
void cm848_miosPwm17Enable(void);  // @ 0x0004d61c
void cm848_miosPwm17SetDuty(word param_1);  // @ 0x0004d644
void cm848_miosPwm17SetPeriodMicroseconds(undefined4 param_1);  // @ 0x0004d670
void cm848_miosPwm18Enable(void);  // @ 0x0004d69c
void cm848_miosPwm18SetDuty(word param_1);  // @ 0x0004d6c4
void cm848_miosPwm18SetPeriodMicroseconds(undefined4 param_1);  // @ 0x0004d6f0
void cm848_miosPwm19Enable(void);  // @ 0x0004d71c
void cm848_miosPwm19SetDuty(word param_1);  // @ 0x0004d744
void cm848_miosPwm19SetPeriodMicroseconds(undefined4 param_1);  // @ 0x0004d770
void cm848_tpuBChannel0EnablePwm(void);  // @ 0x0004d79c
void cm848_tpuBChannel0SetPwmDuty(word param_1);  // @ 0x0004d7c0
void cm848_tpuBChannel0SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004d7e8
void cm848_tpuBChannel1EnablePwm(void);  // @ 0x0004d810
void cm848_tpuBChannel1SetPwmDuty(word param_1);  // @ 0x0004d834
void cm848_tpuBChannel1SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004d85c
void cm848_tpuBChannel2EnablePwm(void);  // @ 0x0004d884
void cm848_tpuBChannel2SetPwmDuty(word param_1);  // @ 0x0004d8a8
void cm848_tpuBChannel2SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004d8d0
void cm848_tpuBChannel3EnablePwm(void);  // @ 0x0004d8f8
void cm848_tpuBChannel3SetPwmDuty(word param_1);  // @ 0x0004d91c
void cm848_tpuBChannel3SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004d944
void cm848_tpuBChannel4EnablePwm(void);  // @ 0x0004d96c
void cm848_tpuBChannel4SetPwmDuty(word param_1);  // @ 0x0004d990
void cm848_tpuBChannel4SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004d9b8
void cm848_tpuBChannel5EnablePwm(void);  // @ 0x0004d9e0
void cm848_tpuBChannel5SetPwmDuty(word param_1);  // @ 0x0004da04
void cm848_tpuBChannel5SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004da2c
void cm848_tpuBChannel6EnablePwm(void);  // @ 0x0004da54
void cm848_tpuBChannel6SetPwmDuty(word param_1);  // @ 0x0004da78
void cm848_tpuBChannel6SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004daa0
void cm848_tpuBChannel7EnablePwm(void);  // @ 0x0004dac8
void cm848_tpuBChannel7SetPwmDuty(word param_1);  // @ 0x0004daec
void cm848_tpuBChannel7SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004db14
void cm848_tpuBChannel8EnablePwm(void);  // @ 0x0004db3c
void cm848_tpuBChannel8SetPwmDuty(word param_1);  // @ 0x0004db60
void cm848_tpuBChannel8SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004db88
void cm848_tpuBChannel9EnablePwm(void);  // @ 0x0004dbb0
void cm848_tpuBChannel9SetPwmDuty(word param_1);  // @ 0x0004dbd4
void cm848_tpuBChannel9SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004dbfc
void cm848_tpuBChannel10EnablePwm(void);  // @ 0x0004dc24
void cm848_tpuBChannel10SetPwmDuty(word param_1);  // @ 0x0004dc48
void cm848_tpuBChannel10SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004dc70
void cm848_tpuBChannel11EnablePwm(void);  // @ 0x0004dc98
void cm848_tpuBChannel11SetPwmDuty(word param_1);  // @ 0x0004dcbc
void cm848_tpuBChannel11SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004dce4
void cm848_tpuBChannel12EnablePwm(void);  // @ 0x0004dd0c
void cm848_tpuBChannel12SetPwmDuty(word param_1);  // @ 0x0004dd30
void cm848_tpuBChannel12SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004dd58
void cm848_tpuBChannel13EnablePwm(void);  // @ 0x0004dd80
void cm848_tpuBChannel13SetPwmDuty(word param_1);  // @ 0x0004dda4
void cm848_tpuBChannel13SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004ddcc
void cm848_tpuBChannel14EnablePwm(void);  // @ 0x0004ddf4
void cm848_tpuBChannel14SetPwmDuty(word param_1);  // @ 0x0004de18
void cm848_tpuBChannel14SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004de40
void cm848_tpuBChannel15EnablePwm(void);  // @ 0x0004de68
void cm848_tpuBChannel15SetPwmDuty(word param_1);  // @ 0x0004de8c
void cm848_tpuBChannel15SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004deb4
void cm848_tpuBReadBackChannel10EnablePwm(void);  // @ 0x0004dedc
word cm848_tpuBReadBackChannel10ReadFeedback(void);  // @ 0x0004df0c
void cm848_tpuBReadBackChannel10SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004df40
void cm848_tpuBReadBackChannel10SetPwmDuty(word param_1);  // @ 0x0004df68
void cm848_tpuBReadBackChannel11EnablePwm(void);  // @ 0x0004df98
word cm848_tpuBReadBackChannel11ReadFeedback(void);  // @ 0x0004dfd4
void cm848_tpuBReadBackChannel4EnablePwm(void);  // @ 0x0004e0c0
word cm848_tpuBReadBackChannel4ReadFeedback(void);  // @ 0x0004e0f0
void cm848_tpuBReadBackChannel4SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004e124
void cm848_tpuBReadBackChannel4SetPwmDuty(word param_1);  // @ 0x0004e14c
void cm848_tpuBReadBackChannel6EnablePwm(void);  // @ 0x0004e180
word cm848_tpuBReadBackChannel6ReadFeedback(void);  // @ 0x0004e1b0
void cm848_tpuBReadBackChannel6SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004e1e4
void cm848_tpuBReadBackChannel6SetPwmDuty(word param_1);  // @ 0x0004e20c
void cm848_tpuBReadBackChannel7EnablePwm(void);  // @ 0x0004e240
word cm848_tpuBReadBackChannel7ReadFeedback(void);  // @ 0x0004e270
void cm848_tpuBReadBackChannel7SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004e2a4
void cm848_tpuBReadBackChannel7SetPwmDuty(word param_1);  // @ 0x0004e2cc
void cm848_tpuAChannel0EnablePwm(void);  // @ 0x0004e300
void cm848_tpuAChannel0SetPwmDuty(word param_1);  // @ 0x0004e324
void cm848_tpuAChannel0SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004e34c
void cm848_tpuAChannel1EnablePwm(void);  // @ 0x0004e374
void cm848_tpuAChannel1SetPwmDuty(word param_1);  // @ 0x0004e398
void cm848_tpuAChannel1SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004e3c0
void cm848_tpuAChannel2EnablePwm(void);  // @ 0x0004e3e8
void cm848_tpuAChannel2SetPwmDuty(word param_1);  // @ 0x0004e40c
void cm848_tpuAChannel2SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004e434
void cm848_tpuAChannel3EnablePwm(void);  // @ 0x0004e45c
void cm848_tpuAChannel3SetPwmDuty(word param_1);  // @ 0x0004e480
void cm848_tpuAChannel3SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004e4a8
void cm848_tpuAChannel4EnablePwm(void);  // @ 0x0004e4d0
void cm848_tpuAChannel4SetPwmDuty(word param_1);  // @ 0x0004e4f4
void cm848_tpuAChannel4SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004e51c
void cm848_tpuAChannel5EnablePwm(void);  // @ 0x0004e544
void cm848_tpuAChannel5SetPwmDuty(word param_1);  // @ 0x0004e568
void cm848_tpuAChannel5SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004e590
void cm848_tpuAChannel6EnablePwm(void);  // @ 0x0004e5b8
void cm848_tpuAChannel6SetPwmDuty(word param_1);  // @ 0x0004e5dc
void cm848_tpuAChannel6SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004e604
void cm848_tpuAChannel7EnablePwm(void);  // @ 0x0004e62c
void cm848_tpuAChannel7SetPwmDuty(word param_1);  // @ 0x0004e650
void cm848_tpuAChannel7SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004e678
void cm848_tpuAChannel8EnablePwm(void);  // @ 0x0004e6a0
void cm848_tpuAChannel8SetPwmDuty(word param_1);  // @ 0x0004e6c4
void cm848_tpuAChannel8SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004e6ec
void cm848_tpuAChannel9EnablePwm(void);  // @ 0x0004e714
void cm848_tpuAChannel9SetPwmDuty(word param_1);  // @ 0x0004e738
void cm848_tpuAChannel9SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004e760
void cm848_tpuAChannel10EnablePwm(void);  // @ 0x0004e788
void cm848_tpuAChannel10SetPwmDuty(word param_1);  // @ 0x0004e7ac
void cm848_tpuAChannel10SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004e7d4
void cm848_tpuAChannel11EnablePwm(void);  // @ 0x0004e7fc
void cm848_tpuAChannel11SetPwmDuty(word param_1);  // @ 0x0004e820
void cm848_tpuAChannel11SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004e848
void cm848_tpuAChannel12EnablePwm(void);  // @ 0x0004e870
void cm848_tpuAChannel12SetPwmDuty(word param_1);  // @ 0x0004e894
void cm848_tpuAChannel12SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004e8bc
void cm848_tpuAChannel13EnablePwm(void);  // @ 0x0004e8e4
void cm848_tpuAChannel13SetPwmDuty(word param_1);  // @ 0x0004e908
void cm848_tpuAChannel13SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004e930
void cm848_tpuAChannel14EnablePwm(void);  // @ 0x0004e958
void cm848_tpuAChannel14SetPwmDuty(word param_1);  // @ 0x0004e97c
void cm848_tpuAChannel14SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004e9a4
void cm848_tpuAChannel15EnablePwm(void);  // @ 0x0004e9cc
void cm848_tpuAChannel15SetPwmDuty(word param_1);  // @ 0x0004e9f0
void cm848_tpuAChannel15SetPwmPeriodMicroseconds(undefined4 param_1);  // @ 0x0004ea18
void cm848_setDatalinkSwitchStateIfPriority(uint param_1,int param_2);  // @ 0x0004ea40
void cm848_clearDatalinkSwitchStateIfPriority(uint param_1,int param_2);  // @ 0x0004ea84
byte cm848_readSwitchHardwareInput(uint param_1);  // @ 0x0004eac8
void cm848_scanAndDebounceSwitchInputs(void);  // @ 0x0004eb48
void hpcr_initProtectionAndOutputCycle(void);  // @ 0x0004eeb8
void cm848_setLogicalOutputRequest(uint param_1,int param_2);  // @ 0x0004ef24
void cm848_setLogicalOutputAndDriveLine(uint param_1);  // @ 0x0004ef74
void cm848_clearLogicalOutputRequest(uint param_1,int param_2);  // @ 0x0004f000
void cm848_clearLogicalOutputAndDriveLine(uint param_1);  // @ 0x0004f050
void cm848_mirrorTransmissionSolenoidRequestsToOutputs62And63(void);  // @ 0x0004f0dc
void cm848_applyLogicalOutputRequests(void);  // @ 0x0004f190
void cm848_processProtectionFaultsAndTiming(void);  // @ 0x0004f2b0
undefined4 cm848_readDiscreteInputLine(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4);  // @ 0x0004f2ec
void mpc555_driveOutputLineHigh(uint param_1);  // @ 0x0004f6f0
void mpc555_driveOutputLineLow(uint param_1);  // @ 0x00051038
void cm848_refreshOutputPortsAndReadback(void);  // @ 0x000529b8
void cm848_refreshInputLineImage(void);  // @ 0x000533e0
void mpc555_processJ1939TxBufferSend(void);  // @ 0x000535e8
void mpc555_queueCanReceiveMessage(int param_1);  // @ 0x00053720
void mpc555_sendJ1939SingleFrame(dword can_id,word data_length,byte *data,byte *result);  // @ 0x00053858
void sendJ1939Message(j1939_tx_msg_t *msg);  // @ 0x000539fc
J1939_CONTROL_DEVICE cm848_lookupJ1939ControlDevice(dword source_address);  // @ 0x00053a4c
void cm848_handleCanMailboxTransmitComplete(uint param_1);  // @ 0x00053aa8
void cm848_handleCanMailboxTransmitRange(int param_1);  // @ 0x00053ae0
void cm848_writeCanControllerTxMailbox(int can_module,dword mailbox_number,word *frame_words);  // @ 0x00053b28
void mpc555_canTransmitInterruptHandler(void);  // @ 0x00053b68
void cm848_emptyStub3(void);  // @ 0x00053c60
void cm848_emptyStub4(void);  // @ 0x00053c64
undefined4 cm848_refreshEngineTsc1IgnoredRequestEntry(int param_1,uint param_2,int param_3);  // @ 0x00053c68
undefined4 cm848_refreshRetarderTsc1IgnoredRequestEntry(uint param_1,int param_2);  // @ 0x00053cd8
void cm848_addEngineTsc1IgnoredRequestEntry(word param_1,undefined1 param_2,undefined2 param_3);  // @ 0x00053d3c
void cm848_addRetarderTsc1IgnoredRequestEntry(byte param_1,undefined2 param_2);  // @ 0x00053d84
void cm848_processTsc1IgnoredRequestTimeouts(void);  // @ 0x00053dc8
void cm848_removeEngineTsc1IgnoredRequestEntry(int param_1,uint param_2);  // @ 0x00053fa8
void cm848_removeRetarderTsc1IgnoredRequestEntry(uint param_1);  // @ 0x00054064
void mpc555_miosInterruptDispatcher(void);  // @ 0x00054100
void mpc555_infiniteLoopHalt(void);  // @ 0x0005419c
void mpc555_enableSchedulerMiosOutput(void);  // @ 0x000541f4
void cm848_emptyStubFunction(void);  // @ 0x00054220
void cm848_checkRpmOverspeedProtection(void);  // @ 0x00054224
void mpc555_systemStartupInitialization(word param_1);  // @ 0x00054380
void cm848_applicationMain(void);  // @ 0x000544c4
void cm848_restartApplicationWithoutReset(void);  // @ 0x00054d30
word mpc555_miosCheckChannelFeedback(mios_mdasm_t *channel_registers,int commanded_duty);  // @ 0x00054e10
void mpc555_miosSetChannelInputMode(mios_mdasm_t *channel_registers);  // @ 0x00054eac
void mpc555_miosEnableChannelPwm(mios_mdasm_t *channel_registers);  // @ 0x00054eb8
void mpc555_miosSetChannelPwmDuty(mios_mdasm_t *channel_registers,word duty);  // @ 0x00054ec4
void mpc555_miosSetChannelPwmPeriod(mios_mdasm_t *unused_channel_registers,uint period_setting);  // @ 0x00054f48
void mpc555_miosEnablePwmSubmodule(mios_mpwmsm_t *pwm_registers);  // @ 0x00054f80
void mpc555_miosSetPwmSubmoduleDuty(mios_mpwmsm_t *pwm_registers,word duty);  // @ 0x00054f8c
void mpc555_miosSetPwmSubmodulePeriodMicroseconds (mios_mpwmsm_t *pwm_registers,uint period_microseconds);  // @ 0x00054fb8
void mpc555_tpuBEnablePwmChannel(uint channel);  // @ 0x00055020
void mpc555_tpuBSetPwmDuty(int channel,word duty);  // @ 0x00055178
void mpc555_tpuBSetPwmPeriodMicroseconds(int channel,uint period_microseconds);  // @ 0x000551e4
void mpc555_tpuAEnablePwmChannel(uint channel);  // @ 0x00055294
void mpc555_tpuASetPwmDuty(int channel,word duty);  // @ 0x000553ec
void mpc555_tpuASetPwmPeriodMicroseconds(int channel,uint period_microseconds);  // @ 0x00055458
void initQadcModule(void);  // @ 0x00055500
void cm848_copyDataBuffer(int param_1,int param_2);  // @ 0x000555cc
undefined4 cm848_processSecurityCodeConversion(undefined4 param_1);  // @ 0x0005573c
void cm848_driveTachometerOutputs(void);  // @ 0x0005586c
void cm848_initializeTachometerOutputs(void);  // @ 0x00055a40
void mpc555_initTpuConfiguration(void);  // @ 0x00055c1c
void mpc555_tpuBInterruptDispatcher(void);  // @ 0x00055d2c
void mpc555_tpuAInterruptDispatcher(void);  // @ 0x00055de4
void cm848_emptyStubFunction8(void);  // @ 0x00055e9c
uint cm848_calculateCrc16Simple(uint param_1,int param_2,uint param_3);  // @ 0x00055ea0
word lookupTableInterpolation (word *cached_axis_offset,word input,word *x_axis,word *y_data,dword flags);  // @ 0x00055ef4
void cm848_extendedDivisionWithRemainder (uint param_1,uint param_2,uint param_3,uint *param_4,int *param_5);  // @ 0x00056184
int cm848_signedDivisionWithSaturation(uint param_1,int param_2);  // @ 0x00056260
int cm848_clampedDivisionWithBounds(uint param_1,int param_2,int param_3,int param_4);  // @ 0x000562fc
uint cm848_saturatingDivision16(uint param_1,uint param_2);  // @ 0x000563e8
sword cm848_signedFirstOrderFilter(int value,ema_filter_state_t *filter_state);  // @ 0x0005644c
sword cm848_secondOrderFilter(sword input,second_order_filter_state_t *filter);  // @ 0x000564c0
dword exponentialMovingAverage(dword value,ema_filter_state_t *filter_state);  // @ 0x00056594
word cm848_secondOrderFilterUnsigned(dword input,second_order_filter_state_t *filter);  // @ 0x00056608
word cm848_dualAxisTableInterpolation (word *cached_axis_offsets,word x_input,word *x_axis,word y_input,word *y_axis, word *z_data,dword flags);  // @ 0x000566cc
undefined4 cm848_ringBufferWriteByte(int *param_1,undefined1 param_2);  // @ 0x00056c80
void cm848_ringBufferInit(int *param_1,int param_2,int param_3);  // @ 0x00056d38
void cm848_memcpyBytes(int param_1,int param_2,int param_3);  // @ 0x00056d58
void cm848_delayMicroseconds(int param_1);  // @ 0x00056d88
void cm848_delayMicroseconds2(int param_1);  // @ 0x00056e0c
dword cm848_unsignedDivision64by32 (dword dividend_hi,dword dividend_lo,dword divisor_hi,dword divisor_lo);  // @ 0x00056e90
dword cm848_signedDivision32(dword dividend_hi,dword dividend_lo,dword divisor_hi,dword divisor_lo);  // @ 0x000570f0
dword cm848_unsignedDivision32 (dword dividend_hi,dword dividend_lo,dword divisor_hi,dword divisor_lo);  // @ 0x000571b0
void cm848_mathMultiplyDivide32(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4);  // @ 0x00057204
dword cm848_conditionalMultiplyDivide (dword dividend_hi,dword dividend_lo,dword divisor_hi,dword divisor_lo);  // @ 0x00057498
void emptyStubFunction2(void);  // @ 0x00057520
void cm848_calibrationTableLookup1D(void);  // @ 0x00057524
void cm848_saveRegistersToStack(void);  // @ 0x0005759c
void cm848_calibrationTableLookup2D(void);  // @ 0x000575a0
void cm848_processCoolantTemperatureChannel(void);  // @ 0x00500004
void cm848_initializeCoolantTemperatureChannel(void);  // @ 0x00500090
void cm848_processExhaustThrottlePositionChannel(void);  // @ 0x0050011c
void cm848_initializeExhaustThrottlePositionChannel(void);  // @ 0x005001a8
void cm848_processSignedSensorChannel (sensor_channel_config_t *config_ptr,sensor_channel_state_t *state_ptr, word *cached_axis_offset,word *x_axis,word *y_data,dword flags, ema_filter_state_t *filter_state_ptr,dword channel_index,dword high_fault_bit, dword low_fault_bit,word *value_output_ptr,word *default_value_output_ptr, word *fault_status_output_ptr);  // @ 0x00500234
void cm848_initializeSignedSensorChannel (sensor_channel_config_t *config_ptr,sensor_channel_state_t *state_ptr, word *cached_axis_offset,word *x_axis,word *y_data,dword flags, ema_filter_state_t *filter_state_ptr,dword channel_index,dword high_fault_bit, dword low_fault_bit,word *value_output_ptr,word *default_value_output_ptr, word *fault_status_output_ptr);  // @ 0x00500a4c
void cm848_processVariableGeometryTurbochargerPositionChannel(void);  // @ 0x005011c4
void cm848_initializeVariableGeometryTurbochargerPositionChannel(void);  // @ 0x00501250
void cm848_processUnsignedSensorChannel (sensor_channel_config_t *config_ptr,sensor_channel_state_t *state_ptr, word *cached_axis_offset,word *x_axis,word *y_data,dword flags, ema_filter_state_t *filter_state_ptr,dword channel_index,dword high_fault_bit, dword low_fault_bit,word *value_output_ptr,word *default_value_output_ptr, word *fault_status_output_ptr);  // @ 0x005012dc
void cm848_initializeUnsignedSensorChannel (sensor_channel_config_t *config_ptr,sensor_channel_state_t *state_ptr, word *cached_axis_offset,word *x_axis,word *y_data,dword flags, ema_filter_state_t *filter_state_ptr,dword channel_index,dword high_fault_bit, dword low_fault_bit,word *value_output_ptr,word *default_value_output_ptr, word *fault_status_output_ptr);  // @ 0x00501b4c
void cm848_selectBarometricPressure(void);  // @ 0x005022cc
void cm848_initializeBarometricPressureSelection(void);  // @ 0x0050241c
void cm848_calculateAltitudeDerateFuelLimit(void);  // @ 0x00502464
void cm848_applyAltitudeDerateFuelLimit(void);  // @ 0x00502af4
void cm848_initialization_step_2(void);  // @ 0x00502b24
void cm848_initializeBarometricFuelLimitInterpolationStates(void);  // @ 0x00502b34
void cm848_calculateAmbientAndCompressorInletConditions(void);  // @ 0x00502b6c
void cm848_initializeAmbientConditions(void);  // @ 0x00502eb8
void cm848_selectTsc1SpeedControlMode(int previous_engine_operating_mode);  // @ 0x00503074
void cm848_initializeVehicleSpeedAndCruiseState(void);  // @ 0x005031b4
void cm848_updateEgrCoolerFoulingFaultCounter(void);  // @ 0x005031fc
void cm848_calculateEgrCoolerEfficiency(void);  // @ 0x005033a0
void cm848_updateEgrSystemHealthFlags(void);  // @ 0x00503604
void cm848_fuelDemand_periodic(void);  // @ 0x0050370c
void cm848_calculateAirFuelRatioAndIntakeOxygenFraction(void);  // @ 0x00503790
void cm848_stub_noop_503960(void);  // @ 0x00503960
void cm848_runOxygenFuelLimitTask(void);  // @ 0x00503964
void cm848_initialization_step_4(void);  // @ 0x0050398c
void cm848_calculateNetCombustionTorque(void);  // @ 0x005039b4
void fuel_boostTrim_ramVars_init(void);  // @ 0x00503b2c
void cm848_calculateTemperatureHeadroomFuelCap(void);  // @ 0x00503b54
void cm848_calculateCylinderOxygenMasses(void);  // @ 0x00503cbc
void cm848_calculateResidualOxygenFraction(void);  // @ 0x00503ed0
void cm848_calculateCylinderOxygenBalance(void);  // @ 0x00503f60
void cm848_calculateOxygenFuelLimit(void);  // @ 0x00503f84
void fuel_demandLimit_calPtrs_init(void);  // @ 0x00504110
void cm848_calculateResidualGasMass(void);  // @ 0x00504130
void cm848_checkAirHandlingSystemProtectionHighLoad(void);  // @ 0x005041bc
void cm848_checkAirHandlingSystemProtectionLevelConditions(void);  // @ 0x0050422c
void cm848_checkAirHandlingSystemNearLimits(void);  // @ 0x005043b4
void cm848_updateAirHandlingSystemProtection(void);  // @ 0x00504528
void governor_speedRatio_etcFuelCorrection_calc(void);  // @ 0x00504654
void cm848_initialization_step_5(void);  // @ 0x00504754
void cm848_calculateEmissionLevelCapCommand(void);  // @ 0x0050477c
void cm848_initializeEmissionLevelCapRateLimiter(void);  // @ 0x00504938
void cm848_runEmissionManager(void);  // @ 0x00504948
void cm848_calculateIntakeCondensationMassRate(void);  // @ 0x00504994
void cm848_updateIntakeCondensationCount(void);  // @ 0x00504b0c
void cm848_calculateEgrCoolerCondensationMassRate(void);  // @ 0x00504d38
void cm848_updateEgrCoolerCondensationCount(void);  // @ 0x00504eb0
void cm848_updateCondensationProtection(void);  // @ 0x005050f4
void cm848_packAuxiliaryEmissionControlState(void);  // @ 0x00505260
void cm848_calculateEmissionManagerEngineProtectionState(void);  // @ 0x0050530c
void cm848_initialization_step_7(void);  // @ 0x005053d0
void cm848_updateNotToExceedAverages(void);  // @ 0x005053e0
void cm848_initialization_step_8(void);  // @ 0x00505574
void cm848_updateEngineStartWarmupProtection(void);  // @ 0x005055a0
void cm848_updateExtendedIdleProtection(void);  // @ 0x00505600
void cm848_updateExtremeAmbientOverheatProtection(void);  // @ 0x005056f8
void cm848_initialization_step_9(void);  // @ 0x005057dc
void cm848_updateWhiteSmokeAndMisfireProtection(void);  // @ 0x005057ec
void cm848_calculateCompressorInletDensity(void);  // @ 0x005058a8
void cm848_selectCompressorInletTemperature(void);  // @ 0x005059ec
void cm848_initializeCompressorInletTemperature(void);  // @ 0x00505b3c
void cm848_selectCoolantTemperature(void);  // @ 0x00505b84
void cm848_initializeCoolantTemperatureSource(void);  // @ 0x00505bd8
void cm848_fillDataCollectorRingBuffer(void);  // @ 0x00505c20
void cm848_resetDataCollector(void);  // @ 0x00505d94
void cm848_sendDataCollectorBuffer(void);  // @ 0x00505df0
void cm848_runDataCollector(int param_1);  // @ 0x00505f98
void cm848_updateDutyCycleMonitorLoadHistogram(void);  // @ 0x0050638c
void cm848_advanceHourMeters(void);  // @ 0x00506780
void cm848_loadHourMetersFromEeprom(void);  // @ 0x005067bc
void cm848_updateEgrValveAutozeroActiveFlag(void);  // @ 0x005067e0
void cm848_updateEgrValvePositionAutozero(void);  // @ 0x00506840
void cm848_selectEgrValvePositionSource(void);  // @ 0x00506964
void cm848_updateEgrValvePosition(void);  // @ 0x00506a3c
void cm848_initializeEgrValvePosition(void);  // @ 0x00506a64
void cm848_estimateExhaustPressure(void);  // @ 0x00506b34
void cm848_initializeExhaustPressureEstimate(void);  // @ 0x00506c94
void cm848_calculateCombustionTemperatureRise(void);  // @ 0x00506cbc
void cm848_estimateExhaustTemperature(void);  // @ 0x00506e28
void cm848_initialization_step_13(void);  // @ 0x00506f68
void cm848_calculateEgrOrificeTemperatureLeadCompensation(void);  // @ 0x00506f88
void cm848_filterEgrOrificeTemperature(void);  // @ 0x00507028
void cm848_selectEgrOrificeTemperature(void);  // @ 0x0050716c
void cm848_phase_groupB_calculation_2(void);  // @ 0x005071b8
void cm848_initialization_step_14(void);  // @ 0x005071dc
void cm848_evaluateEgrValvePositionControlDiagnosticConditions(void);  // @ 0x00507214
void cm848_updateEgrValvePositionControlFaultCounter(void);  // @ 0x00507394
void cm848_runEgrValvePositionControlDiagnostic(void);  // @ 0x00507548
void cm848_initializeEgrValvePositionControlDiagnostic(void);  // @ 0x005075b8
void cm848_countEgrValveClosings(void);  // @ 0x00507644
void cm848_initializeEgrValveClosedHoldPreviousFlag(void);  // @ 0x00507684
void cm848_calculateEmissionLevelCapReference(void);  // @ 0x00507694
void cm848_checkNotToExceedZone(void);  // @ 0x00507748
void cm848_updateEmissionLevelCapReference(void);  // @ 0x005077fc
void hpcr_initializeTimerRegisters(void);  // @ 0x00507820
void cm848_applyFaultDerateToJ1939TorqueCurveFuelings(void);  // @ 0x00507858
void cm848_calculateFaultDerateJ1939TorqueCurveSpeedPoints(void);  // @ 0x00507a20
void cm848_initializeFaultDerateJ1939TorqueCurvePriority(void);  // @ 0x00507c1c
void cm848_runFaultDerateScheduler(void);  // @ 0x00507c44
word cm848_rampEngineProtectionSeverityIndex (engine_protection_channel_configuration_t *configuration, engine_protection_channel_state_t *state,engine_protection_channel_history_t *history ,dword is_engine_speed);  // @ 0x00507d50
undefined2 cm848_interpolateEngineProtectionSeverity(int param_1,int param_2,short param_3);  // @ 0x00507dc0
void hpcr_initializeEngineProtection(void);  // @ 0x00507e20
sword cm848_isEngineProtectionInputPastThreshold (engine_protection_channel_configuration_t *configuration, engine_protection_channel_state_t *state,dword is_engine_speed, dword threshold_select);  // @ 0x00507ebc
void cm848_countEngineProtectionOverLimitDurations(void);  // @ 0x0050802c
void cm848_examineEngineProtectionBeforeCranking(void);  // @ 0x00508130
void cm848_resetEngineProtectionPrecrankState(void);  // @ 0x005082f0
void cm848_updateEngineProtectionRestartSeverityIndexes (engine_protection_channel_configuration_t *configuration, engine_protection_channel_state_t *state,engine_protection_channel_history_t *history );  // @ 0x0050832c
void cm848_checkEngineProtectionRestartLimitation (dword channel_index,engine_protection_channel_state_t *state, engine_protection_channel_configuration_t *configuration);  // @ 0x00508408
void cm848_updateEngineProtectionRestartSeverity(void);  // @ 0x005084b4
void cm848_calculateFaultDerateEngineSpeedLimit(void);  // @ 0x0050860c
void cm848_initializeFaultDerateEngineSpeedLimit(void);  // @ 0x005087e4
void cm848_countEngineProtectionShutdownTime (engine_protection_channel_configuration_t *configuration, engine_protection_channel_state_t *state,dword is_engine_speed);  // @ 0x00508834
void cm848_updateEngineProtectionShutdown(void);  // @ 0x00508898
void cm848_resetEngineProtectionShutdownState(void);  // @ 0x00508de8
void cm848_detectEngineProtectionShutdownOverrideRequest(void);  // @ 0x00508e78
void cm848_latchEngineProtectionShutdownOverride(void);  // @ 0x00508ee0
void cm848_resetEngineProtectionShutdownOverrideDetector(void);  // @ 0x00508f0c
undefined4 cm848_isEngineProtectionInputMoreExtreme(int param_1,int param_2,uint param_3);  // @ 0x00508f24
void cm848_recordEngineProtectionFaultLogEntry(int param_1);  // @ 0x00508f64
void cm848_closeEngineProtectionFaultLogEntry(int param_1);  // @ 0x005090fc
void cm848_logEngineProtectionChannelFaults(void);  // @ 0x00509278
void cm848_applyFaultDerateFuelLimit(void);  // @ 0x00509510
void cm848_calculateFaultDerateFuelLimit(void);  // @ 0x00509540
void cm848_resetFaultDerateFuelLimit(void);  // @ 0x00509814
void cm848_calculateExhaustPressure(void);  // @ 0x00509848
void cm848_initializeExhaustPressure(void);  // @ 0x00509a2c
void cm848_updateGeneralEngineProtection(void);  // @ 0x00509a7c
void cm848_initFlowControlStateVariables(void);  // @ 0x00509b5c
void cm848_copyROMCalibrationToRAM(void);  // @ 0x00509b74
undefined4 j1939_diagService15And16Handler(void);  // @ 0x00509be0
undefined4 cm848_updateJ1939BroadcastEnableMask(int param_1,int param_2);  // @ 0x00509be8
undefined1 j1939_diagService4DisableBroadcast(undefined4 param_1);  // @ 0x00509ce4
undefined1 j1939_diagService5EnableBroadcast(undefined4 param_1);  // @ 0x00509d0c
void j1939_diag_request_batch_init(void);  // @ 0x00509d34
void cm848_clearJ1939InputDataErrorBit(uint param_1);  // @ 0x00509d98
void cm848_clearJ1939PedalInputTimeoutBit(uint param_1);  // @ 0x00509dd8
void cm848_clearJ1939InputTimeoutBit(uint param_1);  // @ 0x00509e18
bool cm848_anyJ1939InputDataErrorActive(void);  // @ 0x00509e58
bool cm848_anyJ1939PedalInputTimeoutActive(void);  // @ 0x00509e98
bool cm848_anyJ1939InputTimeoutActive(void);  // @ 0x00509ed8
void cm848_setJ1939InputDataErrorBit(uint param_1);  // @ 0x00509f18
void cm848_setJ1939PedalInputTimeoutBit(uint param_1);  // @ 0x00509f54
void cm848_setJ1939InputTimeoutBit(uint param_1);  // @ 0x00509f90
void cm848_processJ1939EngineRetarderSelection(void);  // @ 0x00509fcc
void cm848_processJ1939EngineFanRequestedSpeed(void);  // @ 0x0050a0cc
void cm848_processJ1939AcceleratorLowIdleSwitch(void);  // @ 0x0050a1b4
void cm848_updateIdleSwitchesFromLocalInputs(void);  // @ 0x0050a2cc
void cm848_copyStatusBitToDatalinkSwitch(uint param_1,uint param_2);  // @ 0x0050a4a0
void cm848_evaluateJ1939InputSignalFault(int param_1);  // @ 0x0050a57c
void cm848_processJ1939AcceleratorPedalPosition(void);  // @ 0x0050a700
void cm848_processJ1939AcceleratorIdleSwitchPair(void);  // @ 0x0050a9d4
void cm848_processJ1939SwitchAndRequestInputs(void);  // @ 0x0050aba8
void cm848_processJ1939AcceleratorInputs(void);  // @ 0x0050ad1c
void cm848_initJ1939InputProcessing(void);  // @ 0x0050ae5c
void cm848_endRetarderShiftAssistAboveFuelDemandLimit(void);  // @ 0x0050aec0
char j1939_writeDiagMemory(int param_1,byte *param_2,uint param_3);  // @ 0x0050af58
undefined1 j1939_writeDiagMemoryByParameterId (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4);  // @ 0x0050b1b8
undefined1 j1939_diagService68_memoryWriteByParameterId(int param_1);  // @ 0x0050b228
undefined1 j1939_diagService69_memoryWriteByParameterIdExt(int param_1);  // @ 0x0050b298
undefined1 j1939_diagService71Handler(int param_1);  // @ 0x0050b300
undefined1 j1939_diagService73_memoryWriteByParameterId(int param_1);  // @ 0x0050b38c
undefined1 j1939_diagService75_memoryWrite(int param_1);  // @ 0x0050b408
undefined1 j1939_diagService77_memoryWriteExt(int param_1);  // @ 0x0050b474
void j1939_diag_request_batch_44to49(void);  // @ 0x0050b4d8
undefined4 j1939_reverseByteOrder32(undefined4 *param_1);  // @ 0x0050b554
undefined2 j1939_reverseByteOrder16(undefined2 *param_1);  // @ 0x0050b58c
uint j1939_buildLampStatusByte(void);  // @ 0x0050b5b4
byte j1939_getDiagServiceDataOffset(int param_1);  // @ 0x0050b610
undefined4 j1939_diagServiceDispatch(j1939_rx_msg_t *rx_msg);  // @ 0x0050b634
void j1939_receivePgn57344Handler(int param_1);  // @ 0x0050b734
void j1939_receivePgn61441Handler(int param_1);  // @ 0x0050b77c
void j1939_receivePgn61443Handler(int param_1);  // @ 0x0050b8a4
void j1939_receivePgn65252Handler(int param_1);  // @ 0x0050b98c
void j1939_receivePgn65264Handler(int param_1);  // @ 0x0050b9d8
void j1939_receivePgn65265Handler(int param_1);  // @ 0x0050bacc
void cm848_tickJ1939InputSupervision(void);  // @ 0x0050bca0
void j1939_pgn_handler_init_batch(void);  // @ 0x0050bdcc
void cm848_storeJ1939ControlSessionInHistoryTable(int session_kind);  // @ 0x0050be6c
void cm848_startJ1939ControlSession(int session_kind);  // @ 0x0050beec
void cm848_trackJ1939ControlSessions(void);  // @ 0x0050bff4
undefined4 j1939_diagService65_getAddressByParameterId(byte *param_1);  // @ 0x0050c318
void j1939_diag_request_41_handler(void);  // @ 0x0050c400
char j1939_readDiagMemoryAndRespond(byte *param_1,uint param_2,uint param_3);  // @ 0x0050c42c
undefined1 j1939_readDiagMemoryByParameterId (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4);  // @ 0x0050c5d0
undefined1 j1939_diagService67_memoryReadByParameterId(int param_1);  // @ 0x0050c640
undefined1 j1939_diagService70Handler(int param_1);  // @ 0x0050c6a8
undefined1 j1939_diagService72_memoryReadByParameterId(int param_1);  // @ 0x0050c734
undefined1 j1939_diagService74_memoryRead(int param_1);  // @ 0x0050c7b0
undefined1 j1939_diagService76_memoryReadExt(int param_1);  // @ 0x0050c81c
void j1939_diag_request_batch_43to48(void);  // @ 0x0050c880
void initiateJ1939TransportProtocol(j1939_tx_msg_t *msg);  // @ 0x0050c8ec
void j1939_transport_handleClearToSend(int param_1);  // @ 0x0050cc18
void j1939_transport_sendAbort(undefined1 param_1,undefined2 param_2);  // @ 0x0050ccbc
void j1939_transport_sendEndOfMessageAcknowledge(undefined1 param_1,undefined2 param_2);  // @ 0x0050cd54
byte j1939_transport_sendClearToSend (undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined2 param_4);  // @ 0x0050cdfc
void j1939_transport_handleRequestToSend(dword *param_1);  // @ 0x0050ce90
void j1939_transport_handleDataPacket(int param_1);  // @ 0x0050cfa8
void j1939_transport_handleEndOfMessageAcknowledge(int param_1);  // @ 0x0050d144
void j1939_transport_handleAbort(int param_1);  // @ 0x0050d1ac
void j1939_transport_dispatchConnectionManagement(int param_1);  // @ 0x0050d250
void cm848_sendJ1939BroadcastDataPacket(int param_1);  // @ 0x0050d2c0
void cm848_sendJ1939ConnectionModeDataPackets(void);  // @ 0x0050d444
void j1939_transport_timeout_decrement(void);  // @ 0x0050d5d8
void cm848_serviceJ1939TransportSessions(void);  // @ 0x0050d60c
undefined * j1939_selectResponseBuffer(int param_1);  // @ 0x0050d688
void cm848_initializeJ1939Transport(void);  // @ 0x0050d700
undefined1 cm848_lookupApplicationMemoryRegionType(uint param_1,int param_2);  // @ 0x0050d784
void cm848_calculatePedalFaultModeFuelDemandAndSpeedLimit(void);  // @ 0x0050d864
void fuel_demand_periodSnapshot_save(void);  // @ 0x0050da7c
void cm848_transitionEngineOperatingMode(int previous_engine_operating_mode);  // @ 0x0050daac
void cm848_initDroopModeStateVariables(void);  // @ 0x0050db88
void cm848_calculateNoLoadFuel(void);  // @ 0x0050dba8
void cm848_initInterpolationStateCounters(void);  // @ 0x0050dd10
void cm848_updateMilOnRequest(void);  // @ 0x0050dd40
void cm848_controlEndOfLineTestMalfunctionIndicatorLampOverride(int param_1);  // @ 0x0050ddb4
void cm848_calculateEngineLoadPercentages(void);  // @ 0x0050de54
void cm848_validateFuelDemandRelativeToTiming(void);  // @ 0x0050e000
void cm848_debounceOutputReadBackFaults(void);  // @ 0x0050e0a0
void cm848_synchronizeProtectionEnableShadowFlags(void);  // @ 0x0050e4c4
void cm848_verifyRemoteThrottleTransition(void);  // @ 0x0050e534
void cm848_claimRemoteThrottleOverride(void);  // @ 0x0050e610
void cm848_initializeRemoteThrottle(void);  // @ 0x0050e768
void cm848_calculateWaterVaporAndSaturationTemperatures(void);  // @ 0x0050e7f4
void cm848_initBoostControlInterpolationState(void);  // @ 0x0050ea88
void cm848_calculateFrictionNoLoadAndNetMachineTorque(void);  // @ 0x0050eaa8
void cm848_initializeFrictionTorqueLookupCache(void);  // @ 0x0050ebf0
void cm848_updateTurbochargerOverspeedImmediateDerate(void);  // @ 0x0050ec08
void cm848_updateTurbochargerSpeedInRangeState(void);  // @ 0x0050ec8c
void cm848_selectTurbochargerSpeedSource(void);  // @ 0x0050ecc4
void cm848_updateTurbochargerSpeedSelection(void);  // @ 0x0050ee44
void cm848_initializeTurbochargerSpeedSource(void);  // @ 0x0050ee68
void cm848_diagnoseTurbochargerSpeedSensorFrequency(void);  // @ 0x0050eeb0
void cm848_selectTurbochargerSpeedSensorSignalMode(void);  // @ 0x0050f110
void cm848_calculateTurbochargerSpeedSensorValue(void);  // @ 0x0050f178
void cm848_diagnoseTurbochargerSpeedSensorRateOfChange(void);  // @ 0x0050f3b4
void cm848_updateTurbochargerSpeedSensor(void);  // @ 0x0050f4c0
void cm848_turbochargerSpeedSensorInterruptHandler(void);  // @ 0x0050f680
void cm848_initializeTurbochargerSpeedSensorChannel(void);  // @ 0x0050f6c4
void cm848_evaluateVariableGeometryTurbochargerPositionControlDiagnosticConditions(void);  // @ 0x0050f834
void cm848_updateVariableGeometryTurbochargerPositionControlFaultCounter(void);  // @ 0x0050fa7c
void cm848_updateVariableGeometryTurbochargerPositionControlErrorFault(void);  // @ 0x0050fbf8
void cm848_initializeVariableGeometryTurbochargerPositionControlDiagnostic(void);  // @ 0x0050fc8c
void cm848_updateVariableGeometryTurbochargerValveOverTemperatureFault(void);  // @ 0x0050fd40
void cm848_updateVariableGeometryTurbochargerMotorTemperature(void);  // @ 0x0050fe54
void cm848_estimateVariableGeometryTurbochargerMotorCurrent(void);  // @ 0x0051008c
void cm848_updateVariableGeometryTurbochargerMeanSquaredCurrent(void);  // @ 0x0051027c
void cm848_initializeVariableGeometryTurbochargerMotorThermalModel(void);  // @ 0x005102d4
void cm848_monitorWaterInFuel(void);  // @ 0x005103ac
void cm848_processOverdriveSwitchAndShift(void);  // @ 0x00510520
void cm848_initializeOverdriveSwitchAndShift(void);  // @ 0x00510978
void cm848_processEcmInternalTemperatureChannel(void);  // @ 0x005109bc
void cm848_initializeEcmInternalTemperatureChannel(void);  // @ 0x00510a48
void cm848_processSensorReferenceVoltageBChannel(void);  // @ 0x00510ad4
void cm848_initializeSensorReferenceVoltageBChannel(void);  // @ 0x00510b60
void cm848_processEngineSpeedSensorSupplyVoltageChannel(void);  // @ 0x00510bec
void cm848_initializeEngineSpeedSensorSupplyVoltageChannel(void);  // @ 0x00510c78
void cm848_processFuelLevelChannel(void);  // @ 0x00510d04
void cm848_initializeFuelLevelChannel(void);  // @ 0x00510d90
void cm848_processTransmissionTemperatureChannel(void);  // @ 0x00510e1c
void cm848_initializeTransmissionTemperatureChannel(void);  // @ 0x00510ea8
void cm848_initializeAirConditioningClutchControl(void);  // @ 0x00510f34
void cm848_controlAirConditioningClutchForBrTruck(void);  // @ 0x00510fa0
void cm848_controlAirConditioningClutchForDrTruck(void);  // @ 0x00511078
void cm848_controlAirConditioningClutch(void);  // @ 0x005118f8
void cm848_updateRockCycleEngineSpeedLimitWindow(void);  // @ 0x0051193c
void cm848_updateParkNeutralFlagAndTsc1Activity(void);  // @ 0x00511b64
void cm848_initializeRockCycleAndTsc1LostManagement(void);  // @ 0x00511ea8
void cm848_deriveSecondBrakeSwitchSignal(void);  // @ 0x00511ed4
void cm848_monitorBrakeSwitchPairAgreement(void);  // @ 0x00512130
void cm848_initializeCruiseControl(void);  // @ 0x00512554
CRUISE_CONTROL_STATE cm848_selectCruiseStateForCoastSwitch(void);  // @ 0x005125f4
int cm848_updateCruiseControlOnOffToggle(void);  // @ 0x00512678
CRUISE_CONTROL_STATE cm848_selectBaseCruiseState(void);  // @ 0x00512724
void cm848_filterCruiseEngineToVehicleSpeedRatio(void);  // @ 0x0051275c
void cm848_integrateCruiseEngineToVehicleSpeedRatioChange(void);  // @ 0x005127d8
CRUISE_CONTROL_STATE cm848_selectCruiseStateForResumeSwitch(void);  // @ 0x00512878
CRUISE_CONTROL_STATE cm848_selectCruiseStateForSetSwitch(void);  // @ 0x0051291c
int cm848_debounceCruiseSwitchRequest(void);  // @ 0x005129b0
undefined4 cm848_updateCruiseControlDeniedStatus(void);  // @ 0x00512a60
undefined4 cm848_checkCruiseSwitchLearnCondition(void);  // @ 0x00512e70
CRUISE_CONTROL_STATE cm848_selectDeniedCruiseState(void);  // @ 0x00512f18
void cm848_cruiseControlPeriodicUpdate(void);  // @ 0x00512ff4
void cm848_updateEngineWarningFlags(void);  // @ 0x00513200
void cm848_initEngineWarningFlags(void);  // @ 0x005134e8
void cm848_accumulateCoolantOverheatLevelTimers(void);  // @ 0x00513508
void cm848_monitorCoolantOverheatMinimumDerate(void);  // @ 0x0051361c
void cm848_monitorCoolantOverheatAggressiveDerate(void);  // @ 0x0051375c
void cm848_runCoolantOverheatDerateMonitors(void);  // @ 0x0051395c
void cm848_calculateCoolantOverheatTemperatureError(void);  // @ 0x00513980
void cm848_calculateCoolantOverheatPiFuelLimit(void);  // @ 0x005139b8
void cm848_selectCoolantOverheatFuelLimit(void);  // @ 0x00513af0
void cm848_rampCoolantOverheatFuelDerate(void);  // @ 0x00513ba4
void cm848_applyCoolantOverheatFuelFloor(void);  // @ 0x00513c80
void cm848_rampCoolantOverheatDerateMinimumInjectionTiming(void);  // @ 0x00513d08
void cm848_applyCoolantOverheatFuelDerate(void);  // @ 0x00513ddc
void cm848_resetCoolantOverheatFuelDerate(void);  // @ 0x00513e0c
void cm848_runCoolantOverheatFuelDerate(void);  // @ 0x00513f5c
void cm848_addCoolantOverheatLevelTimersToTotals(void);  // @ 0x00514048
void cm848_applyDiscreteOutputOverride(int param_1,int param_2,int param_3,int param_4);  // @ 0x0051408c
void cm848_applyDiscreteOutputOverrides(void);  // @ 0x00514108
void cm848_initializeDiscreteOutputOverrides(void);  // @ 0x00514394
void cm848_selectCoolingFanSpeedTarget(void);  // @ 0x005143f4
void cm848_runCoolingFanSpeedPid(void);  // @ 0x00515370
void cm848_selectCoolingFanDutySource(void);  // @ 0x00515660
void cm848_applyCoolingFanDuty(void);  // @ 0x005158fc
void j1939_periodic_processing(void);  // @ 0x00515bac
void cm848_initCoolingFanControl(void);  // @ 0x00515bd4
void cm848_measureRadiatorFanSpeed(void);  // @ 0x00515d78
void cm848_initRadiatorFanSpeedMeasurement(void);  // @ 0x005161c0
void cm848_radiatorFanSpeedInterruptHandler(void);  // @ 0x00516274
void cm848_configureRadiatorFanSpeedInput(void);  // @ 0x005162ec
void cm848_initFuelLevelPowerUpCheck(void);  // @ 0x00516428
undefined4 cm848_qualifyFuelLevelSample(void);  // @ 0x00516454
void cm848_calibBlock1_counters_reset(void);  // @ 0x00516578
void cm848_debounceFuelLevelSensorHighVoltage(void);  // @ 0x00516590
void cm848_checkFuelLevelChangeAtPowerUp(void);  // @ 0x00516680
void cm848_filterFuelLevelFast(void);  // @ 0x0051674c
void cm848_calibBlock1_trimTimer_reset(void);  // @ 0x00516834
void cm848_filterFuelLevelSlow(undefined4 param_1,ushort param_2,word param_3);  // @ 0x00516844
void cm848_calibBlock1_warmupFlag_reset(void);  // @ 0x00516a10
void cm848_initFuelLevelFilter(void);  // @ 0x00516a20
void cm848_substituteFuelLevelOnSensorFault(void);  // @ 0x00516a94
void cm848_updateFuelLevel(void);  // @ 0x00516bb0
void cm848_monitorWatchdogFueling(void);  // @ 0x00516c18
void cm848_initializeWatchdogFueling(void);  // @ 0x00516df8
void cm848_initIntakeAirHeaterControl(void);  // @ 0x00516e5c
void cm848_computeIntakeAirHeaterPreheatDuration(void);  // @ 0x00516f9c
void cm848_countDownIntakeAirHeaterPreheat(void);  // @ 0x00517120
void cm848_updateIntakeAirHeaterCrankPhase(void);  // @ 0x0051736c
void cm848_advanceIntakeAirHeaterLevel(void);  // @ 0x00517560
void cm848_selectIntakeAirHeaterLevelByRpm(void);  // @ 0x005175c8
void cm848_pulseIntakeAirHeaterRelays(void);  // @ 0x00517720
void cm848_shutdownIntakeAirHeater(void);  // @ 0x00517a5c
void cm848_updateIntakeAirHeaterPostheat(void);  // @ 0x00517b70
void cm848_updateIntakeAirHeaterControl(void);  // @ 0x00517f48
void cm848_resetIntakeAirHeaterStartTemperatureCapture(void);  // @ 0x00518324
void cm848_captureIntakeAirHeaterStartTemperature(void);  // @ 0x00518334
void cm848_updateIntakeAirHeaterAmbientTemperature(void);  // @ 0x005183b4
void cm848_runPciMessageHandlers(void);  // @ 0x00518538
void cm848_processPciObdRequest(void);  // @ 0x00518680
void cm848_initializeObdServiceState(void);  // @ 0x005196f0
void hpcr_periodicTaskGroup20_empty_stub(void);  // @ 0x0051972c
void cm848_buildPciTransmitMessage3MilAndDtcDisplay(void);  // @ 0x00519730
void cm848_initPciTransmitMessage3State(void);  // @ 0x00519c64
void cm848_initializeLiftPumpControl(void);  // @ 0x00519c84
void cm848_controlLiftPump(void);  // @ 0x00519cc4
void cm848_limitFuelQuantityOnRailPressureShortfall(void);  // @ 0x00519e2c
void cm848_initializeRailPressureShortfallFuelLimit(void);  // @ 0x00519ffc
void cm848_initializeEngineOilPressureProcessing(void);  // @ 0x0051a018
void cm848_processEngineOilPressure(void);  // @ 0x0051a0a8
void cm848_initializeTransferCaseLowRangeFilters(void);  // @ 0x0051a5f8
void cm848_detectTransferCaseLowRange(void);  // @ 0x0051a648
void cm848_updateOilChangeMonitor(void);  // @ 0x0051a878
void cm848_initializeOilChangeMonitorLookups(void);  // @ 0x0051ab50
void cm848_monitorGovernorPressureSensorOffset(void);  // @ 0x0051ab70
void cm848_initializeGovernorPressureTrackingMonitor(void);  // @ 0x0051aecc
void cm848_monitorGovernorPressureTracking(void);  // @ 0x0051aef8
void cm848_monitorParkNeutralSwitch(void);  // @ 0x0051b56c
void cm848_initParkNeutralSwitchMonitor(void);  // @ 0x0051b978
uint cm848_calculateEngineToOutputSpeedRatio(void);  // @ 0x0051b9a0
void cm848_accumulateConverterClutchRatioDeltaSum(void);  // @ 0x0051ba1c
void cm848_calculateConverterClutchRatioDelta(void);  // @ 0x0051ba6c
void cm848_monitorConverterClutchAndOverdrivePerformance(void);  // @ 0x0051babc
void cm848_initializeConverterClutchRationalityMonitor(void);  // @ 0x0051c2d0
void cm848_learnGovernorPressureSensorOffset(void);  // @ 0x0051c2e4
void cm848_calibrateGovernorPressureSensorOffset(void);  // @ 0x0051c3d8
void cm848_limitGovernorPressureSolenoidDuty(uint param_1);  // @ 0x0051c68c
void cm848_calculateGovernorPressureProportionalTerm(void);  // @ 0x0051c6c8
void cm848_calculateGovernorPressureDerivativeTerm(void);  // @ 0x0051c948
void cm848_applyGovernorPressureIntegralTerm(void);  // @ 0x0051c9f0
void cm848_controlGovernorPressureSolenoid(void);  // @ 0x0051cad4
void cm848_initializeGovernorPressureControl(void);  // @ 0x0051cd88
undefined * cm848_sciLookupTable250Or252Address(int param_1,int param_2);  // @ 0x0051ce14
byte * cm848_sciLookupEepromSettingAddress(int param_1,uint param_2);  // @ 0x0051cf74
void cm848_sciLookupEepromSettingAddressForRead(void);  // @ 0x0051d5bc
uint cm848_sciBuildStatusFlagsByte(void);  // @ 0x0051d5dc
undefined * cm848_sciHighSpeedLookupTableAddress(int param_1,int param_2);  // @ 0x0051d638
void cm848_sciCallbackDispatcher(void);  // @ 0x0051d70c
void cm848_dispatchSciCommand(void);  // @ 0x0051d780
void cm848_sciInitCommandCallback(void);  // @ 0x0051d810
void phaseGroupB_ControlDispatchers(void);  // @ 0x0051d840
void cm848_sciStartTransmit(void);  // @ 0x0051d86c
void cm848_sciReceiveHandler(void);  // @ 0x0051d8c8
void cm848_sciTransmitHandler(void);  // @ 0x0051d9a0
void cm848_sciResetBuffer(void);  // @ 0x0051da38
void cm848_sciEndTransfer(void);  // @ 0x0051da58
void cm848_sciEnableSerialMode(void);  // @ 0x0051dab0
void cm848_sciInitPort1(void);  // @ 0x0051dad4
void cm848_updateEepromCalibrationIdentifier(void);  // @ 0x0051db0c
void cm848_sciCommand18EnterHighSpeedMode(void);  // @ 0x0051dbd4
void cm848_sciHighSpeedTableSelectCallback(void);  // @ 0x0051dc1c
undefined4 cm848_sciHighSpeedHandleTableSelect(void);  // @ 0x0051dd6c
void cm848_sciHighSpeedTable248And249Callback(void);  // @ 0x0051dea8
void cm848_sciHighSpeedClearWordLatch(void);  // @ 0x0051dfac
void cm848_sciPackOutputStatusWord(void);  // @ 0x0051dfdc
void cm848_sciPackEventHistoryWords(void);  // @ 0x0051e048
void cm848_sciHighSpeedReadTableByte(uint param_1,uint param_2);  // @ 0x0051e0c4
void cm848_sciHighSpeedReadTable245Callback(void);  // @ 0x0051e384
void cm848_sciHighSpeedReadTable250Callback(void);  // @ 0x0051e3b0
void cm848_sciHighSpeedReadTable251Callback(void);  // @ 0x0051e3dc
void cm848_sciHighSpeedReadTable252Callback(void);  // @ 0x0051e408
void cm848_sciHighSpeedReadTable253Callback(void);  // @ 0x0051e434
void cm848_sciCommand19StartOutputTest(void);  // @ 0x0051e460
void cm848_stopSciOutputTest(word *timer,dword logical_output);  // @ 0x0051e490
void cm848_stopAllSciOutputTests(void);  // @ 0x0051e514
void cm848_stepSciOutputTest(word *timer,dword logical_output);  // @ 0x0051e624
void cm848_updateSciOutputTests(void);  // @ 0x0051e6e0
void cm848_sciStartTimedOutputTest(word *timer,dword logical_output,word duration);  // @ 0x0051e894
void cm848_sciCommand19OutputTestCallback(void);  // @ 0x0051e914
void cm848_sciCommand20Handler(void);  // @ 0x0051eef0
int cm848_encodeCruiseControlStatusByte(void);  // @ 0x0051ef20
void cm848_sciCommand20Callback(void);  // @ 0x0051f0b8
void cm848_sciCommand23ClearDiagnostics(void);  // @ 0x005204f8
void cm848_countdown_timer_update(void);  // @ 0x0052061c
void cm848_sciCommand25Handler(void);  // @ 0x00520654
void cm848_expireSciSetEngineSpeedRequest(void);  // @ 0x00520684
void cm848_sciCommand25Callback(void);  // @ 0x005206c4
void cm848_sciCommand26Handler(void);  // @ 0x0052072c
void cm848_sciCommand26Callback(void);  // @ 0x0052075c
void cm848_sciCommand37Handler(void);  // @ 0x00520ad8
void cm848_sciCommand37Callback(void);  // @ 0x00520b14
void cm848_expireSciCommand37Tests(void);  // @ 0x00521474
void cm848_initializeSciCommand37TestTimeouts(void);  // @ 0x005216cc
void cm848_sciCommand39WriteEepromSetting(void);  // @ 0x005216f4
void cm848_sciCommand39WriteEepromSettingCallback(void);  // @ 0x00521730
void cm848_sciCommand40ReadEepromSetting(void);  // @ 0x00521908
void cm848_sciCommand40ReadEepromSettingCallback(void);  // @ 0x00521944
void cm848_sciCommand41WriteTableValue(void);  // @ 0x00521a60
void cm848_sciCommand41WriteTableValueCallback(void);  // @ 0x00521a9c
void cm848_sciCommand42Handler(void);  // @ 0x00521b6c
void cm848_sciCommand42Callback(void);  // @ 0x00521b9c
void cm848_sciCommand43RequestSecuritySeed(void);  // @ 0x00521d3c
void cm848_sciCommand44SendSecurityKey(void);  // @ 0x00521e04
void cm848_sciDecrementKeyRetryDelay(void);  // @ 0x00521e40
void cm848_sciCommand44SendSecurityKeyCallback(void);  // @ 0x00521e68
void cm848_sciCommand49Handler(void);  // @ 0x00522044
void cm848_sciTransmitSingleByteOne(void);  // @ 0x00522074
undefined1 cm848_writeEepromBytes(uint param_1,undefined4 param_2,int param_3);  // @ 0x005220b4
void cm848_sciCommand49Callback(void);  // @ 0x00522158
void cm848_sciCommand50ReportProtectionEventDtcs(void);  // @ 0x00522224
void cm848_sciCommand51ReportActiveFaultDtcs(void);  // @ 0x00522314
void cm848_sciCommand52ReportFaultStatusByDtc(void);  // @ 0x0052242c
undefined4 cm848_lookupFaultIndexByDtcCode(undefined2 *param_1,uint param_2);  // @ 0x00522468
bool cm848_isFaultGroupStatusBitSet(uint param_1);  // @ 0x005224b0
void cm848_sciCommand52ReportFaultStatusByDtcCallback(void);  // @ 0x0052252c
void cm848_sciValidateSecurityKey(void);  // @ 0x00522674
void cm848_updateStackHighWaterMark(void);  // @ 0x00522700
void cm848_initializeStackHighWaterMark(void);  // @ 0x00522788
void cm848_monitorFourWheelDriveSwitch(void);  // @ 0x005227ac
void cm848_initializeFourWheelDriveSwitchMonitor(void);  // @ 0x005229c0
void cm848_initializeTransmissionTemperatureSensorPerformanceMonitor(void);  // @ 0x00522a04
void cm848_updateTransmissionTemperatureSensorPerformanceFault(void);  // @ 0x00522a30
void cm848_completeTransmissionTemperatureMonitorReport(void);  // @ 0x00522ab0
void cm848_checkTransmissionTemperatureSensorPerformance(void);  // @ 0x00522b64
void cm848_recordLifetimeDistanceEvery8Miles(void);  // @ 0x00523068
void cm848_initializeLifetimeDistanceRecordIndex(void);  // @ 0x005230f4
void cm848_updateTripAndLifetimeCounters(void);  // @ 0x00523148
void initGovernorFlagsAux(void);  // @ 0x00523750
void cm848_flagTripInformationPowerDownDataLoss(void);  // @ 0x00523760
void cm848_updateTurbochargerSpeedLimiter(void);  // @ 0x00523798
void cm848_startTurbochargerSpeedLimiter(void);  // @ 0x00523858
void cm848_processImmobilizerStatusMessage(void);  // @ 0x0052390c
void cm848_buildPciTransmitMessage9ImmobilizerSecretKey(void);  // @ 0x00523a9c
void cm848_resetImmobilizerHandshake(void);  // @ 0x00523b5c
byte cm848_getVinCharacter(int param_1);  // @ 0x00523ba4
int cm848_immobilizerKeyMixRound(uint param_1,uint param_2);  // @ 0x00523bc4
void cm848_calculateImmobilizerExpectedKey(void);  // @ 0x00523c00
uint cm848_generateImmobilizerSeed(void);  // @ 0x00523c98
void cm848_processImmobilizerSeedAndKey(void);  // @ 0x00523d38
void cm848_storeImmobilizerSecretKey(void);  // @ 0x00523e88
void cm848_runImmobilizerTask(void);  // @ 0x00523f60
void cm848_verifyCalibrationAndCodeCrc(void);  // @ 0x00524360
void cm848_calculateEngineRetarderCruisePermissionPercent(void);  // @ 0x00524594
void cm848_limitEngineRetarderPercentToCruisePermission(void);  // @ 0x005246b0
void cm848_initializeEngineRetarderCruisePermissionFilter(void);  // @ 0x005246e0
void cm848_selectCruiseGovernorGainSet(int param_1);  // @ 0x0052470c
void cm848_updateCruiseAndRoadSpeedGovernorDroops(void);  // @ 0x00524aec
undefined2 cm848_calculateEngineSpeedAtVehicleSpeed(int param_1,int param_2);  // @ 0x00524c6c
uint cm848_calculateTopDroopGain (int param_1,word *param_2,word param_3,word *param_4,word param_5,word *param_6, word *param_7,dword param_8);  // @ 0x00524d34
uint cm848_calculateBottomDroopGain(int param_1,uint param_2,uint param_3);  // @ 0x00524dd0
void cm848_initializeCruiseAndRoadSpeedGovernorDroops(void);  // @ 0x00524df4
void cm848_calculateCruiseGovernorSpeedErrorGain(void);  // @ 0x005250c0
int cm848_calculateCruiseGovernorEngineSpeedError(void);  // @ 0x00525134
void cm848_presetCruiseAndRoadSpeedGovernor(void);  // @ 0x005251e4
void cm848_runCruiseAndRoadSpeedGovernor(void);  // @ 0x00525504
void cm848_initializeCruiseGovernorFilters(void);  // @ 0x00525de4
void cm848_updateDrivetrainRatio(void);  // @ 0x00525e54
void cm848_initializeDrivetrainRatio(void);  // @ 0x005263a8
void cm848_calculateDrivetrainRatioFromGearRatio(void);  // @ 0x00526414
void cm848_applyJ1939OutOfGearToDrivetrainRatio(void);  // @ 0x005264d4
void cm848_calculateDrivetrainRatioFromVehicleSpeed(void);  // @ 0x00526560
void cm848_calculateTransmissionRatioFromOutputShaft(void);  // @ 0x005266fc
void cm848_saveOutputShaftSpeed(void);  // @ 0x005267e0
void cm848_calculateVehicleSpeedFromOutputShaft(void);  // @ 0x005267f4
void cm848_calculateOutputShaftToVehicleSpeedDivisors(void);  // @ 0x005268e8
void cm848_detectVehicleSpeedSensorSignalLoss(void);  // @ 0x00526924
void cm848_detectVehicleSpeedSensorZeroUnderLoad(void);  // @ 0x005269c0
void cm848_clearHealedVehicleSpeedSensorFault(void);  // @ 0x00526bc8
void cm848_runVehicleSpeedSensorMonitors(void);  // @ 0x00526c80
void cm848_initializeVehicleSpeedSensorZeroUnderLoadMonitor(void);  // @ 0x00526cb8
void cm848_vehicleSpeedSensorInterruptHandler(void);  // @ 0x00526ce4
void cm848_initVehicleSpeedSensorChannel(void);  // @ 0x00527050
void engine_injectionAngle_updateCutoutAndTimingDemand(void);  // @ 0x0052731c
void cm848_resetCylinderCutoutState(void);  // @ 0x00527860
void cm848_captureInjectionQuantityAndTimingSnapshots(void);  // @ 0x005278ac
void engine_injectionAngle_accumulateInjectedFuel(void);  // @ 0x00527938
void cm848_timer_state_preservation(void);  // @ 0x00527958
void cm848_main_loop_initialization(void);  // @ 0x0052796c
void cm848_calculateAuxiliaryInjectionTiming(void);  // @ 0x005279d8
void cm848_initializeAuxiliaryInjectionTimingState(void);  // @ 0x0052801c
void engine_injectionAngle_tpuUpdate(void);  // @ 0x005280a4
void engine_injectionAngle_tpuChannel10CylinderEventHandler(void);  // @ 0x005283d0
void cm848_tpu_configuration_setup(void);  // @ 0x00528474
void engine_injectionAngle_writeTpuEvent(int param_1,int param_2,undefined2 param_3,int param_4);  // @ 0x00528508
void engine_injectionAngle_selectCylinderInjector(int param_1);  // @ 0x0052877c
void engine_injectionAngle_lookupTimingTableOffset(void);  // @ 0x00528978
void cm848_loadInjectorDriverCalibration(void);  // @ 0x005289d4
void cm848_initializeInjectionHardware(void);  // @ 0x00528b90
void cm848_initialization_calibration_state(void);  // @ 0x0052903c
void cm848_monitorFuelSystemHardwareShutdown(void);  // @ 0x00529068
void engine_injectionAngle_computeLoadCh6(void);  // @ 0x00529284
void engine_injectionAngle_tpuChannel6EventHandler(void);  // @ 0x00529640
void cm848_scheduleInjectionAnglesInSpeedLimpHome(void);  // @ 0x00529994
void cm848_scheduleInjectionAnglesOnPrimarySpeedInput(void);  // @ 0x00529d1c
void cm848_initializeInjectionAngleScheduler(void);  // @ 0x00529ea4
void cm848_calculateFuelPressureSetpoint(void);  // @ 0x00529f58
void cm848_initializeFuelPressureSetpointState(void);  // @ 0x0052a910
void cm848_checkFuelPressureGovernorDemandAtGovernedSpeed(void);  // @ 0x0052a9ac
void cm848_checkFuelPressureWithoutInjection(void);  // @ 0x0052acfc
void cm848_monitorFuelMeteringFeedbackAgainstGovernorDemand(void);  // @ 0x0052b32c
void cm848_runFuelPressureGovernorMonitors(void);  // @ 0x0052b998
void cm848_initializeFuelPressureGovernorMonitorState(void);  // @ 0x0052b9c0
void cm848_calculatePilotInjectionQuantity(void);  // @ 0x0052ba30
void cm848_initializePilotInjectionQuantityState(void);  // @ 0x0052c688
void cm848_calculatePilotInjectionTimingOffset(void);  // @ 0x0052c780
void cm848_calculatePilotInjectionTiming(void);  // @ 0x0052d140
void cm848_initializePilotInjectionTimingState(void);  // @ 0x0052d358
void cm848_detectBarometricPressureSensorAboveMaximum(void);  // @ 0x0052d40c
void cm848_initializeBarometricPressureSensorAboveMaximumMonitor(void);  // @ 0x0052d514
void cm848_completeBoostPressureMonitorReport(void);  // @ 0x0052d524
void cm848_monitorBoostPressureSensorAndUnderboost(void);  // @ 0x0052d6a8
void cm848_initializeBoostPressureMonitors(void);  // @ 0x0052dcd0
void cm848_initializeCoolantTemperatureSensorPerformanceMonitor(void);  // @ 0x0052dd28
void cm848_completeCoolantTemperatureSensorMonitorReport(void);  // @ 0x0052dd64
void cm848_checkCoolantTemperatureSensorPerformance(void);  // @ 0x0052de14
void cm848_initializeEgrDeltaPressureSensorPerformanceCheck(void);  // @ 0x0052e24c
void cm848_checkEgrDeltaPressureSensorPerformance(void);  // @ 0x0052e29c
void cm848_initializeEgrOrificeTemperatureSensorRationalityMonitor(void);  // @ 0x0052eac8
void cm848_monitorEgrOrificeTemperatureSensorRationality(void);  // @ 0x0052eae8
void cm848_initializeEndOfLineTestSequence(void);  // @ 0x0052ef90
undefined4 cm848_runEndOfLineTestStartStep(void);  // @ 0x0052f030
undefined4 cm848_runEndOfLineIntakeAirHeaterResultStep(void);  // @ 0x0052f250
undefined4 cm848_runEndOfLineMisfireTestStep(void);  // @ 0x0052f32c
undefined4 cm848_checkRadiatorFanSpeedSignalNoise(void);  // @ 0x0052f448
undefined4 cm848_runEndOfLineAlternatorTestStep(void);  // @ 0x0052f5d4
undefined4 cm848_runEndOfLineFinalResultStep(void);  // @ 0x0052f770
void cm848_measureEndOfLineIntakeAirHeaterVoltageDrops(void);  // @ 0x0052f89c
undefined4 cm848_isDtcStoredOtherThanFault(int param_1);  // @ 0x0052f938
void cm848_setEndOfLineTestOutputRequest(int param_1,word param_2);  // @ 0x0052f994
void cm848_clearEndOfLineTestOutputRequest(ushort param_1);  // @ 0x0052f9d8
undefined2 cm848_runEndOfLineOutputTestStep(void);  // @ 0x0052fa34
void cm848_runEndOfLineTestSequence(void);  // @ 0x0053005c
void cm848_initializeRadiatorFanSpeedRationalityCheck(void);  // @ 0x00530288
void cm848_checkRadiatorFanSpeedRationality(void);  // @ 0x00530298
void cm848_initializeFuelTemperatureSensorColdSoakCheck(void);  // @ 0x00530364
undefined4 cm848_completeFuelTemperatureSensorColdSoakCheckReport(void);  // @ 0x00530374
void cm848_checkFuelTemperatureSensorAfterColdSoak(void);  // @ 0x00530428
void cm848_initializeFuelLevelLowDistanceMonitor(void);  // @ 0x005305dc
void cm848_monitorFuelLevelLowDistance(void);  // @ 0x0053064c
void cm848_initializeFuelPressureSensorPlausibilityState(void);  // @ 0x00530968
void cm848_abortFuelPressureSensorPlausibilityOnFaults(void);  // @ 0x005309bc
uint cm848_calculateExpectedFuelDemandAverage(int param_1);  // @ 0x00530c54
void cm848_checkFuelPressureSensorPlausibilityByFuelDemand(void);  // @ 0x00530d08
void cm848_runFuelPressureSensorPlausibilityMonitor(void);  // @ 0x005311e4
void hpcr_checkRailPressureSensorBeforeStart(void);  // @ 0x00531370
void cm848_initialization_group26_state(void);  // @ 0x0053168c
void cm848_updateMonitorEnablingConditionInputs(void);  // @ 0x005316ac
void cm848_initializeBatteryVoltageInRangeFlags(void);  // @ 0x005318e8
void cm848_updateMonitorEnablingConditions(void);  // @ 0x00531900
void cm848_clearMonitorEnablingConditions(void);  // @ 0x00531cf8
void cm848_resetFuelPressureTrackingErrorAccumulators(void);  // @ 0x00531d10
void cm848_monitorFuelPressureTrackingError(void);  // @ 0x00531d34
void cm848_resetFuelPressureTrackingErrorMonitor(void);  // @ 0x00532208
void cm848_armIntakeAirHeaterPerformanceTest(void);  // @ 0x0053227c
undefined4 cm848_abortIntakeAirHeaterPerformanceTestIfConditionsInvalid(void);  // @ 0x0053232c
void cm848_monitorIntakeAirHeaterPerformance(void);  // @ 0x00532418
void cm848_resetMisfireMonitorTest(void);  // @ 0x00532ae4
void cm848_initializeMisfireMonitor(void);  // @ 0x00532ba8
void cm848_checkMisfireMonitorTestConditions(void);  // @ 0x00532c3c
void cm848_countFlaggedMisfireCylinders(void);  // @ 0x00532df4
void cm848_evaluateMisfireMonitorCylinderResponse(void);  // @ 0x00532e78
void cm848_runMisfireMonitor(void);  // @ 0x00532fac
void cm848_clearFaultStatusRecord(int param_1);  // @ 0x00533aec
void cm848_incrementEngineStartCountsSinceFaultLogged(void);  // @ 0x00533b18
void cm848_removeEngineStartCountSinceFaultLogged(uint param_1);  // @ 0x00533b5c
void cm848_shiftEngineStartCountsSinceFaultLogged(void);  // @ 0x00533b94
void cm848_removeFaultFromRecentDtcList(int param_1);  // @ 0x00533bc4
void cm848_removeFaultFreezeFrameEntry(uint param_1);  // @ 0x00533c80
void cm848_clearAllFaultRecords(void);  // @ 0x00533df0
void cm848_clearPreviouslyActiveFaults(void);  // @ 0x00533efc
void cm848_autoClearFaultsAfterWarmUpCycles(void);  // @ 0x00534010
void cm848_monitorWarmUpCycle(void);  // @ 0x005341a8
undefined4 cm848_areConditionsSimilarToFreezeFrame(uint param_1);  // @ 0x00534250
void cm848_mainLoopServiceMonitor(void);  // @ 0x00534328
void cm848_auxiliaryControlTask(void);  // @ 0x00534530
uint cm848_isFaultMonitorGroupComplete(uint param_1);  // @ 0x00534684
void cm848_incrementFaultHealCycleCount(int param_1);  // @ 0x005346e8
void cm848_clearMilForHealedFaults(void);  // @ 0x0053473c
void cm848_removeHealedFault(uint param_1);  // @ 0x00534890
void cm848_removeHealedFaults(void);  // @ 0x00534994
void cm848_countFaultOccurrence(uint param_1);  // @ 0x00534ae4
void cm848_latchNewlyActiveFault(uint param_1);  // @ 0x00534b68
void cm848_queueFaultFreezeFrameEntry(int param_1);  // @ 0x00534c6c
void cm848_recordFaultDetection(int param_1,uint param_2);  // @ 0x00534fb0
void cm848_registerFaultsOfCompletedMonitors(void);  // @ 0x0053515c
void cm848_markFaultsOfCompletedMonitorsHandled(void);  // @ 0x00535270
void cm848_initializeFaultManagement(void);  // @ 0x00535344
void cm848_crossCheckTemperatureSensorsBeforeStart(void);  // @ 0x005353c8
void cm848_confirmIntakeManifoldTemperatureKeyOnRationality(void);  // @ 0x00535868
void cm848_checkBatteryTemperatureKeyOnRationality(void);  // @ 0x00535964
void cm848_checkAmbientAirTemperatureKeyOnRationality(void);  // @ 0x00535b58
void cm848_checkSensorStuckOverDistance (int param_1,byte *param_2,char *param_3,char *param_4,char *param_5,uint *param_6, word *param_7,byte *param_8,int param_9,uint param_10,uint param_11,uint param_12, int param_13,uint param_14,uint param_15,short *param_16,short *param_17, ushort *param_18,ushort *param_19,int param_20,uint param_21);  // @ 0x00535d34
void hpcr_injectPressureDiagnostic(void);  // @ 0x0053624c
void cm848_initCommunication(void);  // @ 0x00536638
void cm848_initMemoryLayout(void);  // @ 0x0053664c
void cm848_initDataStructures(void);  // @ 0x0053665c
void cm848_decideThermostatMonitorAtTargetTemperature(void);  // @ 0x005366a0
void cm848_decideThermostatMonitorBelowTargetTemperature(void);  // @ 0x005367bc
void cm848_completeThermostatMonitorReport(void);  // @ 0x005368a0
void cm848_runThermostatMonitor(void);  // @ 0x00536958
void cm848_resetFuelPressureSetpointNotReachedAccumulator(void);  // @ 0x00536e30
void cm848_monitorFuelPressureSetpointNotReached(void);  // @ 0x00536e4c
void cm848_resetFuelPressureSetpointNotReachedMonitor(void);  // @ 0x005371f4
void cm848_initOverboostMonitor(void);  // @ 0x0053729c
void cm848_monitorOverboostAndHighLoadBoostBand(void);  // @ 0x005372c4
void cm848_monitorWastegateBoostPressure(void);  // @ 0x00537584
void cm848_initAdaptiveControl(void);  // @ 0x00537944
void cm848_initWaterInFuelDistanceMonitor(void);  // @ 0x005379b4
void cm848_monitorWaterInFuelDistance(void);  // @ 0x005379d8
void cm848_mainLoopDispatcher(void);  // @ 0x00537acc
undefined4 sensorChannelConditionValidator(int param_1);  // @ 0x00537b50
void cm848_checkDiscreteOutputReadBack (dword logical_output,dword read_back_line,dword high_fault_bit,dword low_fault_bit, byte *on_mismatch_count,byte *off_mismatch_count,byte *high_fault_recovery_count, byte *low_fault_recovery_count,word *retry_count);  // @ 0x00537c64
void cm848_monitorDiscreteOutputReadBack(void);  // @ 0x00538278
void cm848_initializeDiscreteOutputReadBackChecks(void);  // @ 0x00538748
void cm848_clearWorkingRam(void);  // @ 0x00538974
void cm848_initializeRamRefresh(void);  // @ 0x005389c4
void cm848_refreshRamCalibration(void);  // @ 0x00538a84
undefined4 diag_record_queue_add_entry (int param_1,undefined2 param_2,int param_3,int param_4,undefined4 param_5);  // @ 0x00538c8c
void cm848_runJ1939PeriodicTransmitQueues(void);  // @ 0x00538d3c
void cm848_exceptionHandler(void);  // @ 0x00538eac
bool j1939_handlerInitializer(undefined2 param_1,undefined4 param_2);  // @ 0x00538eb0
void cm848_dispatchJ1939ReceivedMessages(void);  // @ 0x00538ef4
void cm848_j1939_system_init(void);  // @ 0x00539190
undefined4 cm848_lookupParameterIdAddress(uint param_1,uint *param_2);  // @ 0x00539768
void cm848_initCanHardware(void);  // @ 0x00539868
void cm848_restartOnKeyOnDuringPowerDown(void);  // @ 0x00539938
void cm848_saveEepromForPowerDown(void);  // @ 0x00539a78
void cm848_runPowerDownSequence(void);  // @ 0x00539d18
void cm848_outputChannelNoneEnable(void);  // @ 0x0053a0fc
void cm848_outputChannelNoneSetPeriod(void);  // @ 0x0053a100
void cm848_outputChannelNoneSetDuty(void);  // @ 0x0053a104
undefined4 cm848_outputChannelReadFeedbackNone(void);  // @ 0x0053a108
void cm848_updateOutputReadBackFaultBits(void);  // @ 0x0053a110
