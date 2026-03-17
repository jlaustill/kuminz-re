#pragma once
#include "firmware_types.hpp"

// Function Forward Declarations (from decompiled output)

void reset_vector(void);  // @ 0x00000100
void keyOnStateMachine(void);  // @ 0x00000184
void copyCalibrationToRam(void);  // @ 0x00000340
void registerStandardDiagServices(void);  // @ 0x0000037c
void eepromProgressNotify(undefined4 param_1,int param_2,undefined4 param_3);  // @ 0x000003ec
void loadEepromCalibration(undefined4 param_1,int param_2);  // @ 0x00000428
undefined4 diagServiceDownloadCalibration(undefined4 param_1);  // @ 0x000008d4
short initEepromTransfer(int param_1);  // @ 0x000008fc
undefined4 diagServiceInitEepromTransfer(undefined4 param_1);  // @ 0x000009e4
uint computeCrcCcitt(undefined4 *param_1,uint param_2);  // @ 0x00000a40
void updateCapabilityFlags(void);  // @ 0x00000b44
void stubFunction1(void);  // @ 0x00000be8
void eepromWriteWords(dword dest_address,word *src_ptr,word word_count);  // @ 0x00000bec
void eepromReadWords(short param_1,undefined2 *param_2,uint param_3);  // @ 0x00000d88
void mainLoopIteration(void);  // @ 0x00000e90
void loadCalibrationFromEeprom(void);  // @ 0x00000ec0
void loadVersionConfigFromEeprom(void);  // @ 0x00000f74
void bootStateMachine(void);  // @ 0x00001008
void generateCrcTable(void);  // @ 0x000010ac
bool flashPollUntilReady(uint param_1,ushort *param_2,uint param_3);  // @ 0x00001110
short flashEraseChip(void);  // @ 0x000011b4
undefined2 flashWriteWord(undefined2 *param_1,undefined2 *param_2);  // @ 0x000012a8
undefined4 flashWriteBlock(int param_1,int param_2,uint param_3);  // @ 0x00001338
void initHardwareConfig(void);  // @ 0x00001454
void initSystemRegisters(void);  // @ 0x000016d0
void stubFunction2(void);  // @ 0x0000183c
char diagService25_executeFunction(int param_1);  // @ 0x00001840
void initService25Handler(void);  // @ 0x0000191c
bool registerPgnResponseHandler(dword pgn,void *handler_func);  // @ 0x00001948
void initDataBasedDiagServices(void);  // @ 0x0000198c
undefined4 diagService65_handler(byte *param_1);  // @ 0x000019e8
void registerService65Handler(void);  // @ 0x00001ad0
void registerMemoryReadServices(void);  // @ 0x00001afc
char diagMemoryReadHandler(dword address,word length,byte *response_ptr);  // @ 0x00001b48
undefined1 diagMemoryReadWithBaseOffset(dword param_1,undefined4 param_2,short param_3,byte *param_4);  // @ 0x00001cf8
undefined1 diagService67_memoryReadOffset(int param_1);  // @ 0x00001d5c
undefined1 diagService74_memoryRead(dword param_1);  // @ 0x00001dc4
undefined1 diagService76_memoryReadExt(dword param_1);  // @ 0x00001e30
void initDiagResponseHandlers(void);  // @ 0x00001e94
void diagSendResponseCode(undefined1 param_1,int param_2);  // @ 0x00001ef8
void processDiagnosticAndEepromRequests(void);  // @ 0x00001fa4
void initDiagnosticCallback(void);  // @ 0x00002148
void processDiagnosticTimeout(void);  // @ 0x00002170
void setDataTransferMode(void);  // @ 0x000021c0
void initDiagnosticSession(void);  // @ 0x000021d0
void eepromValidationCycle(void);  // @ 0x00002310
void busWaitCycles(int param_1);  // @ 0x00002384
bool checkBusHardwareStatus(void);  // @ 0x000023b8
void waitForBusStable(void);  // @ 0x000024a0
void systemInitialization(void);  // @ 0x00002504
void hardwareInitialization(void);  // @ 0x00002694
void initCanController(void);  // @ 0x00002970
void initDiagnosticSubsystem(void);  // @ 0x00002a40
void clearRamRegions(void);  // @ 0x00002b7c
void softReset(void);  // @ 0x00002bc8
bool registerDiagnosticService(undefined1 param_1,undefined4 param_2);  // @ 0x00002c94
void registerPgnEf00Handler(byte sub_id,void *handler_func);  // @ 0x00002cd8
undefined4 * lookupEepromParameterAddress(byte param_1);  // @ 0x00002d08
void handleEepromDiagnosticCallback(void);  // @ 0x00002de4
void registerSchedulerTask(void);  // @ 0x00002e58
void initSchedulerCallback(void);  // @ 0x00002ee8
void initSchedulerTaskTable(void);  // @ 0x00002f18
void spiReceiveHandler(void);  // @ 0x00002f74
void spiTransmitCompleteHandler(void);  // @ 0x00003008
void dispatchSpiHandlerByState(void);  // @ 0x000030ec
void resetEepromStatusPointer(void);  // @ 0x000031a0
void enableSystemInterrupts(void);  // @ 0x000031c0
void enableSpiTransmitInterrupt(void);  // @ 0x00003218
void initDiagnosticResponseCallback(void);  // @ 0x0000323c
void processDiagnosticResponseCallback(void);  // @ 0x0000326c
void generateSerialChecksumResponse(void);  // @ 0x000032dc
void initDiagnosticRequestHandler(void);  // @ 0x000033a4
void decrementDiagnosticTimeout(void);  // @ 0x000033e0
void processDiagnosticRequest(void);  // @ 0x00003408
void initDiagnosticSessionHandler(void);  // @ 0x000035e4
void processDiagnosticSessionFlags(void);  // @ 0x00003614
void sendDiagnosticResponse(void);  // @ 0x0000368c
void resetEepromCalibrationState(void);  // @ 0x000036f8
void beginEepromCalibrationWrite(void);  // @ 0x00003710
void updateEepromMagicAndReload(void);  // @ 0x000037e0
void diagRequestTypeDispatcher(byte service_code,byte *request_ptr);  // @ 0x000038f4
void diagServiceTransferBlock(void);  // @ 0x00003948
void computeSerialChecksum(void);  // @ 0x00003a5c
void restoreDiagnosticHandler(void);  // @ 0x00003ad8
void enableDiagnosticTimer(void);  // @ 0x00003b38
void processTimerInterrupt(void);  // @ 0x00003b48
void saveSchedulerCallbackPointer(void);  // @ 0x00003b58
void initQspiRegisters(void);  // @ 0x00003b6c
undefined1 getDiagnosticServicePriority(int param_1);  // @ 0x00003d54
void canTransmitQueuePush(uint param_1,uint param_2,int param_3,undefined1 *param_4);  // @ 0x00003dac
void transmitCanMessage(undefined4 *param_1);  // @ 0x00003f20
undefined4 lookupTableEntryByKey(uint param_1);  // @ 0x00003f70
undefined4 dataTransferBufferWrite(int param_1,int param_2,uint param_3,int param_4,byte param_5);  // @ 0x00003fcc
void prepareDataTransferBuffer(void);  // @ 0x00004194
void initAdcChannelConfig(void);  // @ 0x000042b0
void configureAdcConversionRegs(void);  // @ 0x00004320
void configureAdcChannelRange(uint param_1);  // @ 0x000043a4
void initDataTransferCopyBuffer(int param_1);  // @ 0x00004500
undefined4 advanceAdcChannelQueue(void);  // @ 0x00004570
int checkDataTransferBufferStatus(void);  // @ 0x00004654
void startAdcConversion(void);  // @ 0x000046dc
void initCanMailboxFilters(void);  // @ 0x00004720
bool initFlashMemoryConfig(uint param_1);  // @ 0x000049d0
void can2MailboxTransmitCompleteWrapper(void);  // @ 0x00004eec
void can2MailboxTransmitRangeWrapper(void);  // @ 0x00004f0c
void writeCan2ControllerTxMailbox(int param_1,int param_2,int param_3);  // @ 0x00004f2c
void can2TransmitInterruptHandler(void);  // @ 0x00004f6c
void manageCan1TransmitBuffer(void);  // @ 0x00005064
void processCanReceiveBuffer(int param_1);  // @ 0x00005134
void dispatchCanMessageHandlers(void);  // @ 0x0000526c
byte processAdcConversionResult(int param_1,uint param_2,uint param_3);  // @ 0x00005400
undefined1 processAdcWithOffset(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4);  // @ 0x00005728
undefined1 processAdcSensorByte(int param_1);  // @ 0x00005798
undefined1 processAdcSensorDword(int param_1);  // @ 0x00005808
undefined1 processAdcSensorDwordExt(int param_1);  // @ 0x00005870
undefined1 processAdcSensorDualDword(int param_1);  // @ 0x000058e8
undefined1 getServiceDataOffset(int param_1);  // @ 0x00005958
undefined4 validateServiceDataLength(int param_1);  // @ 0x0000597c
void multiFrameCanTransmit(uint *param_1);  // @ 0x00005adc
void handleJ1939QueueRequest(byte request_type,byte connection_id);  // @ 0x00005c50
void processAdcChannelGroup(undefined1 param_1,undefined2 param_2);  // @ 0x00005cf4
void sendJ1939DiagnosticMessage(byte dest_address,byte *data_ptr,word data_length);  // @ 0x00005d8c
undefined1 sendDiagAcknowledgeFrame (undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined2 param_4);  // @ 0x00005e38
void handleJ1939DataRequest(undefined4 *param_1);  // @ 0x00005ecc
void handleJ1939DataTransfer(int param_1);  // @ 0x00005fe4
void handleJ1939AbortRequest(int param_1);  // @ 0x00006180
void handleJ1939AbortAcknowledge(int param_1);  // @ 0x000061e8
void j1939DiagMessageDispatcher(int param_1);  // @ 0x0000628c
void processJ1939QueueTransmit(void *queue_entry);  // @ 0x000062fc
void decrementPauseStatusCounter(void);  // @ 0x00006490
void processJ1939QueueStatus(byte connection_id);  // @ 0x000064c4
undefined * initDiagnosticBuffers(int param_1);  // @ 0x00006508
void updateSystemTimers(undefined1 param_1,int param_2);  // @ 0x00006580
void diagnosticSubcommandDispatcher(byte subcommand,byte *data_ptr);  // @ 0x0000662c
void resetSerialReceiveBuffer(void);  // @ 0x00006770
void serialReceiveHandler(void);  // @ 0x000067b0
void resetSerialCommunication(void);  // @ 0x0000685c
void serialTransmitHandler(void);  // @ 0x000068b4
void enableSerialTransmit(void);  // @ 0x00006974
void validateSerialChecksum(void);  // @ 0x000069b0
void initSerialTransmit(void);  // @ 0x00006a5c
void sensorFaultDetection(void);  // @ 0x00006ab8
undefined4 updateSensorDiagnostics(void);  // @ 0x00006b24
void sensorInputProcessing(int param_1,int param_2,int param_3);  // @ 0x00006bac
void processScheduledTasks(void);  // @ 0x00006bdc
void processMainLoop(void);  // @ 0x00006ca4
void dispatchDiagnosticService(byte service_code,byte *data_ptr,word data_length);  // @ 0x00006d24
void sendEepromVersionResponse(void);  // @ 0x00006e1c
void handleEepromDiagnosticResponse(void);  // @ 0x00006eac
void processEepromDataTransfer(void);  // @ 0x00006f54
void scrambleBitPattern(int param_1,int param_2);  // @ 0x000071f8
undefined4 sensorRangeValidation(undefined4 param_1);  // @ 0x00007370
void processSensorFilterChain(byte *param_1,uint param_2);  // @ 0x000074a0
void processSensorWithOverride(undefined4 param_1,undefined2 param_2);  // @ 0x000075dc
void watchdogTimerTick(void);  // @ 0x00007608
void watchdogTimerTick_midEntry(void);  // @ 0x000076b4
char sensorFaultThresholdCheck(uint param_1,int param_2);  // @ 0x000076c8
undefined1 sensorAcquisitionCycle(undefined4 param_1,int param_2,ushort *param_3,int param_4);  // @ 0x00007740
undefined4 validateTransferBlockParams(short *param_1);  // @ 0x00007840
undefined1 processTransferCrc(byte *param_1,uint param_2,int param_3);  // @ 0x000078d0
void systemWatchdogReset(void);  // @ 0x00007974
void initQspiHardware(void);  // @ 0x00007b08
void systemHaltLoop(void);  // @ 0x00007dc4
void keyOnStatusMonitor(void);  // @ 0x0000b44c
void phase_common_processing(void);  // @ 0x0000b76c
void phase_group_a_processing(void);  // @ 0x0000b7b4
void phase_group_b_processing(void);  // @ 0x0000b854
void periodicTaskSet_fuelFinal(void);  // @ 0x0000b8fc
void periodicTaskSet_sensorProcessing(void);  // @ 0x0000b98c
void periodicTaskSet_controlLoop(void);  // @ 0x0000ba08
void periodicTaskSet_auxiliaryControl(void);  // @ 0x0000ba90
void periodicTaskSet_canTx(void);  // @ 0x0000bb18
void periodicTaskSet_diagnostics(void);  // @ 0x0000bb40
void periodicTaskSet_protection(void);  // @ 0x0000bb68
void periodicTaskSet_timing(void);  // @ 0x0000bb90
void periodicTaskSet_outputs(void);  // @ 0x0000bbb8
void periodicTaskSet_sensors(void);  // @ 0x0000bbe0
void periodicTaskSet_monitoring(void);  // @ 0x0000bc08
void periodicTaskSet_communication(void);  // @ 0x0000bc34
void periodicTaskGroup12_calibration1(void);  // @ 0x0000bc5c
void periodicTaskGroup13_calibration2(void);  // @ 0x0000bc80
void periodicTaskGroup14_calibration3(void);  // @ 0x0000bca4
void periodicTaskGroup15_calibration4(void);  // @ 0x0000bcc8
void periodicTaskSet_protection2(void);  // @ 0x0000bce8
void periodicTaskGroup17_calibration5(void);  // @ 0x0000bd08
void periodicTaskGroup18_calibration6(void);  // @ 0x0000bd28
void periodicTaskGroup25_calibration7(void);  // @ 0x0000bd54
void periodicTaskGroup26_calibration8(void);  // @ 0x0000bd80
void periodicTaskGroup27_calibration9(void);  // @ 0x0000bdac
void periodicTaskGroup28_calibration10(void);  // @ 0x0000bdd8
void periodicTaskGroup29_calibration11(void);  // @ 0x0000be04
void periodicTaskGroup30_calibration12(void);  // @ 0x0000be30
void periodicTaskGroup31_calibration13(void);  // @ 0x0000be5c
void periodicTaskGroup32_calibration14(void);  // @ 0x0000be88
void periodicTaskSet_protection3(void);  // @ 0x0000beb4
void schedulerPhaseDispatcher(void);  // @ 0x0000bec8
void periodicTaskSet_auxiliary(void);  // @ 0x0000bee0
void periodicTaskSet_fuelDemand(void);  // @ 0x0000bf08
void periodicTaskGroup36_calibration15(void);  // @ 0x0000bf34
void periodicTaskGroup37_calibration16(void);  // @ 0x0000bf60
void periodicTaskGroup38_calibration17(void);  // @ 0x0000bf88
void periodicTaskSet_diagnostics2(void);  // @ 0x0000bfb0
void periodicTaskGroup20_calibration(void);  // @ 0x0000bfd8
void periodicTaskGroup21_calibration(void);  // @ 0x0000c000
void periodicTaskGroup22_calibration(void);  // @ 0x0000c028
void periodicTaskSet_protection4(void);  // @ 0x0000c050
void periodicTaskSet_outputs2(void);  // @ 0x0000c078
void main_loop(void);  // @ 0x0000c0a0
void initSensorDefaults(void);  // @ 0x0000c874
void sensorChannel0_init(void);  // @ 0x0000c8bc
void sensorChannel0_process(void);  // @ 0x0000c948
void sensorChannel1_init(void);  // @ 0x0000c9d4
void sensorChannel1_process(void);  // @ 0x0000ca60
void sensorChannel2_init(void);  // @ 0x0000caec
void sensorChannel2_process(void);  // @ 0x0000cb78
void sensorChannel3_boostPressureInit(void);  // @ 0x0000cc04
void sensorChannel3_boostPressureProcess(void);  // @ 0x0000cc90
void sensorChannel4_init(void);  // @ 0x0000cd1c
void sensorChannel4_process(void);  // @ 0x0000cda8
void sensorChannel5_init(void);  // @ 0x0000ce34
void sensorChannel5_process(void);  // @ 0x0000cec0
void sensorChannel6_init(void);  // @ 0x0000cf4c
void sensorChannel6_process(void);  // @ 0x0000cfd8
void sensorChannel7_init(void);  // @ 0x0000d064
void sensorChannel7_process(void);  // @ 0x0000d0f0
void sensorChannel8_init(void);  // @ 0x0000d17c
void sensorChannel8_process(void);  // @ 0x0000d208
void sensorChannel9_init(void);  // @ 0x0000d294
void sensorChannel9_process(void);  // @ 0x0000d320
void sensorChannel10_throttleInit(void);  // @ 0x0000d3ac
void sensorChannel10_throttleProcess(void);  // @ 0x0000d438
void sensorChannel11_init(void);  // @ 0x0000d4c4
void sensorChannel11_process(void);  // @ 0x0000d550
void sensorChannel12_init(void);  // @ 0x0000d5dc
void sensorChannel12_process(void);  // @ 0x0000d668
void sensorChannel13_init(void);  // @ 0x0000d6f4
void sensorChannel13_process(void);  // @ 0x0000d780
void sensorChannel14_init(void);  // @ 0x0000d80c
void sensorChannel14_process(void);  // @ 0x0000d898
void sensorChannel15_init(void);  // @ 0x0000d924
void sensorChannel15_process(void);  // @ 0x0000d9b0
void sensorChannel16_init(void);  // @ 0x0000da3c
void sensorChannel16_process(void);  // @ 0x0000db50
void sensorChannel16BProcessOilPressure(void);  // @ 0x0000db88
word oilPressureDeltaCalculation(void);  // @ 0x0000dc64
void fuelDemandBlendCalculator(void);  // @ 0x0000dcdc
void initFuelTableSizes(void);  // @ 0x0000e09c
void trackMinimumFuelDemand(void);  // @ 0x0000e0c4
undefined4 checkPressureFuelState(void);  // @ 0x0000e0f4
int calculateSensorEma(void);  // @ 0x0000e164
undefined4 checkFuelRateCondition(void);  // @ 0x0000e218
undefined4 checkPressureFuelDelayA(void);  // @ 0x0000e248
undefined4 checkPressureFuelDelayB(void);  // @ 0x0000e2cc
int checkPressureHysteresis(void);  // @ 0x0000e360
void processFuelPressureConditions(void);  // @ 0x0000e3a4
void hpcr_calculateFuelTrimOutput(void);  // @ 0x0000e518
void initFuelPressureVariables(void);  // @ 0x0000e748
void temperatureBasedFuelTrim(void);  // @ 0x0000e78c
void initTemperatureTrimTableSizes(void);  // @ 0x0000e8ac
void initTemperatureTrimCoeff(void);  // @ 0x0000e8cc
void fuelTimingRateLimitedBlend(void);  // @ 0x0000e8dc
void fuelTimingCompensation(void);  // @ 0x0000e8f0
void fuelTimingOilPressureModeController(void);  // @ 0x0000ea00
void initFuelDemandVariables(void);  // @ 0x0000fabc
void restoreEngineOperatingMode(void);  // @ 0x0000fb28
void calculateFuelTimingBlend(void);  // @ 0x0000fcd0
void initFuelTimingTableSizes(void);  // @ 0x0000fe3c
void calculateFuelTimingTarget(void);  // @ 0x0000fe5c
void calculateFuelTrimValues(void);  // @ 0x0000ff04
void initEngineOperatingMode(int param_1);  // @ 0x00010110
void initLookupTableParams(void);  // @ 0x00010248
void stubFunction3(void);  // @ 0x00010270
undefined8 timerInterruptHandler(undefined4 param_1,undefined4 param_2);  // @ 0x00010274
void fatalErrorHalt(void);  // @ 0x00010694
void selectTurboModeParameters(void);  // @ 0x000107ec
void updateTurboModeState(void);  // @ 0x0001083c
void selectTemperatureTrimValue(void);  // @ 0x00010874
void calculateTurboRatioA(void);  // @ 0x000108a4
void calculateTurboRatioB(void);  // @ 0x000109c8
void calculateTurboRatios(void);  // @ 0x00010b04
void calculateTurboBlendOutput(void);  // @ 0x00010b28
void calculateTurboRatioWithMode(void);  // @ 0x00010d3c
void initTurboRatioVariables(void);  // @ 0x00010ed0
void calculateLoadBasedAdjustment(void);  // @ 0x00010f68
ushort lookupRpmLoadTable(void);  // @ 0x000110bc
void calculateLoadAdjustmentFactors(void);  // @ 0x00011170
void processLoadAdjustment(void);  // @ 0x00011290
void initLoadAdjustmentTableSizes(void);  // @ 0x00011324
void calculateLoadGainValues(void);  // @ 0x0001134c
void selectLoadAdjustmentLimits(void);  // @ 0x00011410
void calculateLoadCompensation(void);  // @ 0x000114dc
void calculateLoadIntegral(void);  // @ 0x000115cc
void processLoadGainCalculations(void);  // @ 0x000118f8
void initLoadGainVariables(void);  // @ 0x00011924
undefined4 calculateRateLimitedValue(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5);  // @ 0x0001198c
void checkSpeedBandCondition(void);  // @ 0x00011a4c
void calculateTurboCompensation(void);  // @ 0x00011ab4
void turboCompensationWrapper(void);  // @ 0x0001231c
void initTurboCompensationVariables(void);  // @ 0x0001233c
undefined2 circularBufferWriteUnsigned(int param_1,undefined2 param_2,int param_3);  // @ 0x000123dc
int circularBufferWriteSigned(int param_1,undefined2 param_2,int param_3);  // @ 0x00012404
void calculateLoadBasedFuelTrim(void);  // @ 0x0001242c
void calculateRpmBasedFuelTrim(void);  // @ 0x000125f4
undefined4 checkFuelSystemFaultFlags(void);  // @ 0x00012724
undefined4 checkEngineFaultConditions(void);  // @ 0x00012778
void selectFuelTrimMode(void);  // @ 0x000127bc
void throttleBasedFuelCalculation(void);  // @ 0x000128a0
void initFilterCoefficients(void);  // @ 0x00012a58
void boostBasedFuelModifier(void);  // @ 0x00012ad4
void loadBasedFuelAdjustment(void);  // @ 0x00012cf4
void fuelDemandWithLoadCompensation(void);  // @ 0x00012dc4
void initFilterTablePointers(void);  // @ 0x00012e40
void fuelControlMainCalculation(void);  // @ 0x00012e60
void initFuelControlFilterSystem(void);  // @ 0x00012e88
void fuelDemandErrorCalculation(void);  // @ 0x00012eb4
void initFuelDemandBlendPointers(void);  // @ 0x00012f40
void fuelDemandBlendCalculation(void);  // @ 0x00012f60
void initManifoldPressureFilter(void);  // @ 0x000130ac
void calculateBoostPressureOffset(void);  // @ 0x000130dc
void initFuelFilterDefaults(void);  // @ 0x0001327c
void calculateBoostTorqueOffset(void);  // @ 0x00013294
void initFuelDemandFilterState(void);  // @ 0x0001350c
void checkBoostControlCondition(void);  // @ 0x00013564
void processBoostControlState(void);  // @ 0x0001359c
void processBoostProtectionConditions(void);  // @ 0x00013774
void selectLoadNormalizer(void);  // @ 0x0001392c
void processLoadNormalizerSelection(void);  // @ 0x00013a80
void processBoostProtectionMode(undefined4 param_1,int param_2);  // @ 0x00013aec
void initBoostProtectionState(void);  // @ 0x00013ca4
void calculateThrottleDerivative(void);  // @ 0x00013d14
void calculateThrottleFiltered(void);  // @ 0x00013dc8
void initThrottleFilterState(void);  // @ 0x00014080
void calculateRpmLoadTables(void);  // @ 0x0001410c
void selectFuelDemandOverride(void);  // @ 0x0001429c
void selectFuelLimitOverride(void);  // @ 0x000142d0
void setFuelStatusFlags(void);  // @ 0x00014304
void calculateRpmLoadLimit(void);  // @ 0x00014374
void selectFinalLoadLimit(void);  // @ 0x00014430
void setFuelDemandVariable(undefined2 param_1);  // @ 0x0001444c
void setFuelDemandVariable(undefined2 param_1);  // @ 0x00014458
void selectFuelLoadOverride(void);  // @ 0x00014464
void processFuelLimitCalculations(void);  // @ 0x00014498
void initFuelLimitTableSizes(void);  // @ 0x000144d0
undefined4 compareForFuelMapSelection(int param_1,int param_2);  // @ 0x00014508
int filterInputValue(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6, int param_7);  // @ 0x00014528
void calculateFuelDemandMode1(void);  // @ 0x00014610
void calculateFuelDemandMode2(void);  // @ 0x000149a4
void calculateFuelDemandTimingOffset(void);  // @ 0x00014d38
void calculateFuelDemandMode3(void);  // @ 0x000150b0
void calculateFuelDemandBlendTables(void);  // @ 0x00015444
void lookupFuelDemandRpmTables(void);  // @ 0x00015760
void calculateFuelLimitSource(void);  // @ 0x00015a24
void selectFuelLimitWithFiltering(void);  // @ 0x00015bd8
uint fuelDemandFilterUpdate(uint param_1,ushort *param_2,int param_3);  // @ 0x00015d2c
void interpolateFuelMapTable(void *table_ptr,word rpm_input,word load_input);  // @ 0x00015e08
void processFuelMapInterpolation(void);  // @ 0x00015f34
void calculateFuelBlendModeSelection(void);  // @ 0x000160ac
void calculateFuelBlendMode(int param_1);  // @ 0x00016408
void calculateFuelBlendMode(int param_1);  // @ 0x0001640c
void processFuelDemandCalculations(void);  // @ 0x000164ac
undefined2 fuelDemandTableLookup(undefined4 param_1);  // @ 0x000164e4
int fuelDemandRpmCorrection(undefined4 param_1,word param_2);  // @ 0x00016724
void lookupProtectionFuelDemand(void);  // @ 0x00016774
void initFuelDemandTablePointers(void);  // @ 0x00016888
void calculateFuelInjectionTiming(void);  // @ 0x00016a90
void calculateManifoldPressureOffset(void);  // @ 0x00016c40
void calculateFuelDemandDelta(void);  // @ 0x00016cd4
void applyFuelDemandOffset(void);  // @ 0x00016d6c
void processFuelTimingCalculations(void);  // @ 0x00016e90
void storeFuelLimitValues(void);  // @ 0x00016f9c
void initFuelTimingTablePointers(void);  // @ 0x00016ffc
void fuelDemandBaseCalculation(void);  // @ 0x0001702c
void fuelDemandModeSelector(void);  // @ 0x00017150
void fuelDemandEnableChecker(void);  // @ 0x000172b0
void fuelDemandRateLimiterStateMachine(void);  // @ 0x000172e8
void fuelDemandOverrideHandler(void);  // @ 0x000173a8
void fuelDemandSmoothingController(void);  // @ 0x00017560
void fuelDemandFinalCalculation(void);  // @ 0x0001782c
void fuelDemandCoordinator(void);  // @ 0x00017980
void initFuelDemandRateVariables(void);  // @ 0x00017af4
void storeFuelDemandPreviousValues(void);  // @ 0x00017b54
undefined2 calculateFuelFlowRate(void);  // @ 0x00017b84
void selectFuelFlowMode(void);  // @ 0x00017d54
void initFuelFlowRateVariables(void);  // @ 0x00017e54
void calculateOilPressureProtection(void);  // @ 0x00017eb8
void calculateFuelFlowWithMode(void);  // @ 0x00017f50
void emptyStubFunction3(void);  // @ 0x0001806c
int throttlePositionProcessing(word param_1,short param_2);  // @ 0x00018070
void faultSeverityEvaluation(void);  // @ 0x0001811c
void processThrottlePositionLookups(void);  // @ 0x0001820c
void calculateThrottleProtectionLimit(void);  // @ 0x000182e8
void checkProtectionEnableConditions(void);  // @ 0x00018384
void checkFaultConditionThreshold(void);  // @ 0x000184f0
int conditionalFirstOrderFilter(undefined4 param_1,int param_2,int param_3);  // @ 0x000185cc
void processFaultIncrement(short *param_1);  // @ 0x0001860c
void processFaultStateWithFilter(undefined2 *param_1);  // @ 0x00018780
void updateFaultStatusRegisters(void);  // @ 0x00018904
void selectFaultProtectionValue(void);  // @ 0x00018a50
void processFaultProtection(void);  // @ 0x00018ac0
void initFaultProtectionVariables(void);  // @ 0x00018afc
void processSensorProtectionRamp(void);  // @ 0x00018bc0
void processSensorFaultDetection(void);  // @ 0x00018cfc
void initSensorFaultVariables(void);  // @ 0x00018f1c
void calculateSensorDiagnosticValue(void);  // @ 0x00018f8c
void updateSensorDiagnosticFlags(void);  // @ 0x000191a0
void processSensorMonitoringLogic(void);  // @ 0x000191e8
void updateEngineModeFromSensor(void);  // @ 0x00019390
void processSensorValidation(void);  // @ 0x0001956c
void checkSensorRangeConditions(void);  // @ 0x000196a4
void calculateSensorBlendFactor(void);  // @ 0x000197b4
void processSensorBlendState(void);  // @ 0x00019830
void selectSensorBlendOutput(void);  // @ 0x00019900
void initSensorBlendVariables(void);  // @ 0x000199f4
void processSensorBlendCalculation(void);  // @ 0x00019ac0
void sensorMonitoringMainLoop(void);  // @ 0x00019b20
void selectFuelDemandUpperLimit(int param_1);  // @ 0x00019e08
void calculateFuelDemandLimits(void);  // @ 0x00019ea4
void applyFuelDemandProtection(void);  // @ 0x00019fe0
void processFuelDemandLimits(void);  // @ 0x0001a1b4
void processSensorAndFuelDemand(void);  // @ 0x0001a1dc
void initFuelDemandLimitVariables(void);  // @ 0x0001a204
void processConditionTimerA(int param_1);  // @ 0x0001a340
void processConditionTimerB(int param_1);  // @ 0x0001a47c
void processConditionTimerC(void);  // @ 0x0001a608
void processConditionTimerD(void);  // @ 0x0001a754
undefined4 bothConditionsTrue(int param_1,int param_2);  // @ 0x0001a980
void processFuelDemandFaultConditions(void);  // @ 0x0001a9a8
void initFuelDemandFaultVariables(void);  // @ 0x0001ae2c
void processFaultTimingConditions(void);  // @ 0x0001af94
void updateFaultConditionState(void);  // @ 0x0001b120
void initFaultTimingVariables(void);  // @ 0x0001b35c
void processFaultAndFuelDemand(void);  // @ 0x0001b37c
void faultTimerHandler(undefined4 *param_1);  // @ 0x0001b3a0
undefined4 faultCounterDecrement(ushort param_1,int param_2);  // @ 0x0001b624
undefined4 faultCounterIncrement(byte param_1,byte param_2);  // @ 0x0001b69c
void sendFaultTimerMessage(void);  // @ 0x0001b730
void processFaultMessageTiming(void);  // @ 0x0001b778
void initFaultTimerMessage(void);  // @ 0x0001b900
void calculateColdStartFuelAdjust(void);  // @ 0x0001b99c
void initColdStartLimits(void);  // @ 0x0001bb30
void calculateColdStartRpmAdjust(void);  // @ 0x0001bb48
void calculateColdStartFuelOffset(void);  // @ 0x0001bb78
void calculateColdStartTempTable(void);  // @ 0x0001bc30
void selectColdStartRpmLimit(void);  // @ 0x0001bd44
void calculateIntakeAirAdjustment(void);  // @ 0x0001bd74
void checkColdStartConditions(void);  // @ 0x0001be64
void processColdStartAdjustment(void);  // @ 0x0001bf44
void initColdStartTablePointers(void);  // @ 0x0001bfc8
void processColdStartStateMachine(void);  // @ 0x0001c080
void coldStartRpmTableLookup(void);  // @ 0x0001c114
void coldStartFuelFactorLookup(void);  // @ 0x0001c1a4
void selectColdStartFactor(void);  // @ 0x0001c23c
void processColdStartMainLoop(void);  // @ 0x0001c28c
void initCrankingLimits(void);  // @ 0x0001c978
void faultTimeoutHandler(byte param_1);  // @ 0x0001c9a0
void clearFaultFromActiveList(byte param_1);  // @ 0x0001cb94
void activeFaultScanProcessor(void);  // @ 0x0001cd1c
uint faultCodeLookup(uint param_1);  // @ 0x0001cdc0
uint findFaultByTypeAndSeverity(uint param_1,ushort param_2);  // @ 0x0001ce28
void registerFaultInActiveList(uint param_1);  // @ 0x0001cea4
void clearDiagnosticState(void);  // @ 0x0001d01c
void clearAllDiagnosticFaults(void);  // @ 0x0001d11c
void faultTableEntryProcessor(void);  // @ 0x0001d224
void buildFaultConditionMask(void);  // @ 0x0001d8f8
void diagnosticMainStateProcessor(void);  // @ 0x0001d9b8
void initDiagnosticRingBuffer(void);  // @ 0x0001dcdc
void markFaultForReplacement(void);  // @ 0x0001dd10
void updateFaultEntryCounters(uint param_1);  // @ 0x0001de4c
void resetFaultStatus(int param_1);  // @ 0x0001dee0
void setFaultActiveStatus(int param_1,uint param_2);  // @ 0x0001df64
void captureFreezeFrameData(int param_1,uint param_2,int param_3);  // @ 0x0001df88
void processDiagnosticFrame (undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5, int param_6);  // @ 0x0001e158
void selectFuelDemandSource(void);  // @ 0x0001e22c
void clearFuelDemandFlag(void);  // @ 0x0001e4d8
void calculateProtectionRateLimited(void);  // @ 0x0001e4e8
void processProtectionSelection(void);  // @ 0x0001e5a4
void initEngineOperatingState(void);  // @ 0x0001e810
void updateEngineTimingCompensation(void);  // @ 0x0001e830
void processTorqueLimitState(void);  // @ 0x0001e870
void initProtectionTableSizes(void);  // @ 0x0001ea6c
void initFaultSeverityTables(void);  // @ 0x0001ea94
void calculateFuelDemandChangeRate(void);  // @ 0x0001eae8
void processFaultIncrement(short *param_1);  // @ 0x0001ec48
uint calculateDualAxisFuelLimit(void);  // @ 0x0001ec70
void initFuelDemandTracking(void);  // @ 0x0001ef30
void calculateFuelDemandLimitOutput(void);  // @ 0x0001ef88
uint processActiveFaultList(word param_1);  // @ 0x0001f03c
void calculateFuelDemandWithTrim(void);  // @ 0x0001f17c
void initFuelDemandTableDimensions(void);  // @ 0x0001f300
void initProtectionStateWithFuelDemand(void);  // @ 0x0001f318
void calculateTimingCompensation(void);  // @ 0x0001f34c
void processTorqueLimitTiming(void);  // @ 0x0001f40c
void initSensorRawChannels(void);  // @ 0x0001f98c
void selectSensorRawChannels(void);  // @ 0x0001fa20
void selectTorqueLimit(void);  // @ 0x0001fd94
void initTorqueLimitDefaults(void);  // @ 0x00020410
undefined1 getLimitCategoryCode(int param_1);  // @ 0x000204a8
void calculateProtectionActivationDelay(void);  // @ 0x00020500
uint calculateEffectiveFuelLimit(void);  // @ 0x00020554
void selectTorqueLimitStateMachine(void);  // @ 0x00020860
void calculateLoadRateOfChange(void);  // @ 0x000209e8
void calculateLoadToFuelRatio(void);  // @ 0x00020a58
void emptyStubFunction3(void);  // @ 0x00020aec
void calculateOilPressureRateOfChange(void);  // @ 0x00020af0
void updateProtectionParameters(void);  // @ 0x00020b84
void updateProtectionInputs(void);  // @ 0x00020bfc
void initProtectionDefaults(void);  // @ 0x00020c60
void processJ1939RxMessage(int param_1,int param_2);  // @ 0x00020c64
void updateProtectionStateMachine(void);  // @ 0x00020d10
void initProtectionDelayDefaults(void);  // @ 0x000212dc
void calculateSpeedControlError(void);  // @ 0x00021314
void initSpeedControlTableDimensions(void);  // @ 0x0002156c
undefined4 initJ1939MessageBuffers(void);  // @ 0x00021668
undefined4 processJ1939RxQueue(undefined4 param_1,int param_2);  // @ 0x000216fc
undefined1 j1939ProcessRxQueueDefault(void);  // @ 0x000218b0
undefined1 j1939ProcessRxQueueParam(undefined4 param_1);  // @ 0x000218dc
undefined4 validateCalibrationMemory(void);  // @ 0x00021918
void registerJ1939DiagnosticHandlers(void);  // @ 0x00021a24
undefined2 initUdsServiceHandlers(word param_1);  // @ 0x00021ac0
undefined2 applyFuelDemandFilter(undefined2 param_1);  // @ 0x00021b28
uint getHighestPriorityBit(void);  // @ 0x00021bf8
void updateProtectionThresholdsIfLow(void);  // @ 0x00021c3c
void setProtectionThresholdParameters(void);  // @ 0x00021c9c
void updateProtectionDiagnostics(void);  // @ 0x00021cd4
void initJ1939DiagnosticCallback(void);  // @ 0x000220b4
bool processJ1939DiagnosticRequest(undefined1 param_1,undefined4 param_2);  // @ 0x000220e4
void j1939DiagnosticServiceHandler(int param_1);  // @ 0x00022128
void initJ1939DiagnosticServiceHandler(void);  // @ 0x000221f0
void updateGovernorTimers(void);  // @ 0x00022220
void initGovernorDerivativeTerms(void);  // @ 0x00022318
void initGovernorControlHandler(undefined4 param_1,word param_2);  // @ 0x0002232c
void noOperation(void);  // @ 0x0002235c
void processSecurityAccessRequest(int param_1);  // @ 0x0002236c
void clearGovernorDerivativeMode(int param_1);  // @ 0x000223a0
void processGovernorControlMessage(int param_1);  // @ 0x000223f4
void initializeGovernorDerivatives(void);  // @ 0x00022468
void matchSecurityRequest(void);  // @ 0x00022570
void processGovernorSecurityAccessRequest(undefined4 param_1,undefined4 param_2,uint param_3);  // @ 0x00022590
void j1939HandlePgn65228Dm3ClearDiag(undefined4 param_1);  // @ 0x00022674
void initPgn65228Dm3Handler(undefined4 param_1,undefined4 param_2,void *param_3);  // @ 0x00022770
void j1939HandleDm1RequestMessage(int param_1);  // @ 0x000227a0
void initJ1939Dm1RequestHandler(void);  // @ 0x00022840
void j1939ProcessTorqueSpeedControl(int param_1);  // @ 0x00022870
void selectTorqueLimitMode(void);  // @ 0x00022ab8
void initJ1939TorqueSpeedHandler(void);  // @ 0x00022bc4
void initJ1939VehicleSpeedHandler(void);  // @ 0x00022d18
void processTsc1Command(int param_1);  // @ 0x00022d60
void processGovernorSpeedControlRequest(void);  // @ 0x00022e3c
void processGovernorSpeedRequest(void);  // @ 0x00022f90
bool j1939RegisterPgnHandler(byte pgn_byte_0,byte pgn_byte_1,void *handler_func);  // @ 0x00023188
void j1939DispatchPgnHandler(int param_1);  // @ 0x000231cc
void initJ1939ProtocolHandlers(undefined4 param_1,undefined4 param_2,void *param_3);  // @ 0x000232b4
void j1939HandleProprietaryCommand(int param_1);  // @ 0x000233a0
void initJ1939ProprietaryHandler(void);  // @ 0x0002343c
short j1939SetupMultiFrameTransfer(byte param_1);  // @ 0x0002346c
void j1939FormatMultiFrameResponse(void);  // @ 0x000234a4
void routeGovernorHandlerByTable(void);  // @ 0x0002352c
void setGovernorHandlerDefault(void);  // @ 0x000236b4
void j1939ProcessGovernorRequest(int param_1);  // @ 0x000236f0
void j1939DispatchAddressHandler(int param_1);  // @ 0x00023b38
void initJ1939AddressDispatcher(void);  // @ 0x00023bb4
void sendJ1939ProprietaryStatus(void);  // @ 0x00023be0
void initJ1939DmHandlerBuffer(int param_1,int param_2);  // @ 0x00023d14
void sendJ1939AcknowledgeMessage(int param_1,undefined1 param_2);  // @ 0x00023d3c
void sendJ1939NegativeAck(int param_1,undefined1 param_2);  // @ 0x00023dbc
void flushJ1939FrameBuffer(void);  // @ 0x00023e2c
void j1939HandlePgn65269AmbientConditions(void);  // @ 0x00023e8c
void sendJ1939ErrorFrame(void);  // @ 0x00023f4c
void j1939BuildEngineStatusByte(void);  // @ 0x00024028
void prepareAndSendJ1939Frame(byte *param_1,undefined4 param_2,int param_3,byte param_4);  // @ 0x000240b8
void prepareAndSendJ1939Frame(byte *param_1,undefined4 param_2,int param_3,byte param_4);  // @ 0x000240c4
void j1939HandlePgn65265CruiseVehicleSpeed(void);  // @ 0x00024178
void buildPgn65228Dm3ClearInitMessage(void);  // @ 0x00024230
void buildDiagnosticStatusMessage (undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5);  // @ 0x0002439c
void initPgn65265CruiseSpeedHandler(undefined4 param_1,undefined4 param_2,void *param_3);  // @ 0x00024664
void j1939HandlePgn65261CruiseControlSetup(void);  // @ 0x000246fc
void initPgn65261CruiseControlSetupStruct(void);  // @ 0x00024800
void j1939HandlePgn65259ComponentId(void);  // @ 0x00024870
void appendGovernorDroopDataToMessage(void);  // @ 0x000248dc
void initPgn65259ComponentIdHandler(undefined4 param_1,undefined4 param_2,void *param_3);  // @ 0x00024940
void sendJ1939ResponseFrame(byte *param_1,uint param_2);  // @ 0x000249c4
void sendJ1939ExtendedResponse(undefined4 param_1,undefined2 param_2);  // @ 0x00024afc
void j1939HandlePgn65234Dm11ClearActive(void);  // @ 0x00024b28
void initPgn65234Dm11Handler(undefined4 param_1,undefined4 param_2,void *param_3);  // @ 0x00024b64
void j1939HandlePgn65226Dm1ActiveDtc(void);  // @ 0x00024be8
void processDm1FaultBroadcast(void);  // @ 0x00024d78
void initPgn65226Dm1Handler(undefined4 param_1,undefined4 param_2,void *param_3);  // @ 0x00024dd8
void j1939HandlePgn65227Dm2PreviousDtc(void);  // @ 0x00024e78
void initPgn65227Dm2Handler(undefined4 param_1,undefined4 param_2,void *param_3);  // @ 0x00025000
void initPgn65227Dm2ResponseHandler(int param_1,int param_2,void *param_3);  // @ 0x00025050
void initPgn65229Dm4Handler(undefined4 param_1,undefined4 param_2,void *param_3);  // @ 0x00025094
void j1939BuildDm4FreezeFrame(int param_1);  // @ 0x00025110
void j1939HandlePgn65229Dm4FreezeFrame(void);  // @ 0x00025390
void j1939HandlePgn65230Dm5Readiness(void);  // @ 0x00025458
void initPgn65230Dm5Handler(undefined4 param_1,undefined4 param_2,void *param_3);  // @ 0x0002553c
void j1939SendDm1ResponseMessage(byte dest_address,byte fault_count);  // @ 0x000255c0
void j1939BuildEngineControlByte(void);  // @ 0x0002567c
void setEngineControllerStateCode(undefined4 param_1,undefined4 param_2,int param_3);  // @ 0x00025884
void j1939GetEngineStateCode(void);  // @ 0x0002588c
void transmitEngineStatusMessage(int param_1);  // @ 0x00025a9c
void j1939HandlePgn61443Eec2(void);  // @ 0x00025b10
void sendEec2WithDefaultValues(void);  // @ 0x00025d30
void initPgn61443Eec2Handler(undefined4 param_1,undefined4 param_2,void *param_3);  // @ 0x00025d60
void j1939SendOilPressureStatus(void);  // @ 0x00025de8
void j1939HandlePgn65263FluidLevelPressure(void);  // @ 0x00025eb4
void initPgn65263FluidLevelPressureHandler(undefined4 param_1,undefined1 *param_2);  // @ 0x00025fd8
void j1939HandlePgn65262EngineTemp(void);  // @ 0x00026024
void buildEngineTempWithConditionCheck(int param_1);  // @ 0x000260d4
void initPgn65262EngineTempHandler(undefined4 param_1,undefined4 param_2,void *param_3);  // @ 0x0002619c
void emptyStubFunctionJ1939A(void);  // @ 0x0002622c
void j1939BuildVehicleOperatingStatus(void);  // @ 0x00026238
void initJ1939SpeedControlMessage(void);  // @ 0x000263a4
void j1939SendDiagnosticStatusMessage(byte dest_address,byte status_type);  // @ 0x0002641c
void j1939HandlePgn65270InletExhaustConditions(void);  // @ 0x000264d8
void initPgn65270InletExhaustHandler(undefined1 *param_1,int param_2);  // @ 0x0002661c
void j1939BuildProtocolModeStatus(void);  // @ 0x00026650
void buildProtocolModeStatusMessage(int param_1);  // @ 0x000266f8
void initPgn65256VehicleMaintenanceHandler(undefined1 *param_1);  // @ 0x00026850
void j1939HandlePgn65242SoftwareId(void);  // @ 0x00026884
void initPgn65242SoftwareIdHandler(void);  // @ 0x000268ac
void j1939HandlePgn65504ProprietaryA(void);  // @ 0x000269f4
void buildVehicleMaintenanceStatusBits(int param_1);  // @ 0x00026aa4
void j1939HandlePgn65248VehicleDistance(void);  // @ 0x00026bb0
void initPgn65248VehicleDistanceHandler(undefined4 param_1,undefined4 param_2,void *param_3);  // @ 0x00026c6c
void j1939HandlePgn65271VehicleElectrical(void);  // @ 0x00026cf0
void j1939HandlePgn65260VehicleId(void);  // @ 0x00026db4
void emptyStubFunctionJ1939B(void);  // @ 0x00026dd0
void initPgn65260VehicleIdHandler(void);  // @ 0x00026ddc
void j1939SendSafetyStatusMessage(void);  // @ 0x00026e90
void emptyStubFunction4(void);  // @ 0x00026f78
void emptyStubFunction5(void);  // @ 0x00026f7c
void j1939FormatDm1Message(void);  // @ 0x00026f80
void updateGovernorTorqueLimit (undefined2 *param_1,undefined2 *param_2,undefined4 param_3,undefined2 *param_4, int param_5);  // @ 0x00026fb8
void resetGovernorState(void);  // @ 0x00027118
void processGovernorModeTransition(void);  // @ 0x0002715c
void selectTorqueLimitByStateMachine(void);  // @ 0x00027174
void governorDroopCalculation(uint *param_1,int param_2,int param_3);  // @ 0x00027bc4
undefined4 governorSpeedControl(int param_1,uint param_2);  // @ 0x00027cc4
void processSpeedSensorCompensation(void);  // @ 0x00027d38
void updateSpeedProtectionLimits(int param_1);  // @ 0x00027e4c
void processSpeedGovernorControl(void);  // @ 0x00027ff8
void resetSpeedControlTracking(void);  // @ 0x000285e4
void initSpeedProtectionParameters(void);  // @ 0x00028618
void processGovernorLoadCondition(void);  // @ 0x00028670
void clearGovernorTimerCounters(void);  // @ 0x00028994
void resetGovernorLoadState(void);  // @ 0x000289ac
undefined4 selectGovernorSetpointSource(int param_1);  // @ 0x000289d0
void updateGovernorSetpointParameters(void);  // @ 0x00028a14
void initGovernorTimerCountersWrapper(void);  // @ 0x00028abc
void initGovernorLoadStateWrapper(void);  // @ 0x00028adc
undefined4 getGovernorOverrideSource(void);  // @ 0x00028b38
void clearGovernorFilterAccumulators(void);  // @ 0x00028b8c
void calculateSpeedRateLimiting(void);  // @ 0x00028ba4
void setGovernorFilterPointer(void);  // @ 0x00028d30
void updateSpeedLimitFromCoolant(void);  // @ 0x00028d44
void calculateProtectionSpeedLimits(void);  // @ 0x0002906c
void applySpeedLimitConstraints(void);  // @ 0x000298a0
void updateGovernorSpeedLimits(void);  // @ 0x00029afc
void calculateGovernorCompensation(void);  // @ 0x00029b38
void initGovernorStateVariables(void);  // @ 0x00029bf8
void initGovernorLookupDimensions(void);  // @ 0x00029c80
void calculateFuelDemandFilter(void);  // @ 0x00029c98
void initFuelDemandFilterDimensions(void);  // @ 0x00029de0
void initProtectionFilterAccumulators(void);  // @ 0x00029e24
void processEngineConfigSpeedControl(void);  // @ 0x00029e50
uint absoluteValue16(uint param_1);  // @ 0x00029f3c
void checkSensorDeviationFlags(void);  // @ 0x00029f54
void processSensorDeviationOnKeyoff(void);  // @ 0x0002a214
void resetSensorDeviationTracking(void);  // @ 0x0002a2b4
void calculateProtectionRpmFilter(void);  // @ 0x0002a2d0
void calculateProtectionLoadCompensation(void);  // @ 0x0002a4b0
void checkProtectionParamLimit(void);  // @ 0x0002a918
void initProtectionParamCalculation(void);  // @ 0x0002a960
void processProtectionParamDelta(void);  // @ 0x0002ab2c
void initProtectionFilterState(void);  // @ 0x0002abc8
void smoothProtectionParamTransition(void);  // @ 0x0002ac44
void setProtectionParamFromRpm(void);  // @ 0x0002ad28
void initProtectionSmoothingPointer(void);  // @ 0x0002ad48
void evaluateProtectionCondition(void);  // @ 0x0002ad68
void processProtectionControlStateMachine(void);  // @ 0x0002afd0
void updateProtectionPreviousParam(void);  // @ 0x0002ba7c
void initProtectionEvalState(void);  // @ 0x0002bb24
void updateGovernorFromProtection(void);  // @ 0x0002bbe8
void resetProtectionBypass(void);  // @ 0x0002bd38
void j1939HandlePgn65264Pto(void);  // @ 0x0002bd58
void updateFaultOnKeyoff(void);  // @ 0x0002bf44
void calculateRpmLimitsFromProtection(void);  // @ 0x0002bf6c
void emptyStubFunction6(void);  // @ 0x0002c0fc
void initProtectionLimitVariables(void);  // @ 0x0002c100
void updateTorqueLimitFromProtection(void);  // @ 0x0002c114
void updateTorqueLimitFromThreshold(undefined4 param_1,uint param_2);  // @ 0x0002c14c
void trackFuelDemandThreshold(void);  // @ 0x0002c180
void processProtectionLimitActivation(void);  // @ 0x0002c23c
void checkSafetyConditionsForProtection(void);  // @ 0x0002c318
void processProtectionControlLogic(void);  // @ 0x0002c3c8
void updateRpmProtectionLimits(void);  // @ 0x0002c4fc
void updateProtectionEntryConditions(void);  // @ 0x0002c6c4
void processProtectionEntry(void);  // @ 0x0002c764
void initFuelControlModeVariables(void);  // @ 0x0002c9bc
void calculateSpeedControlLimit(void);  // @ 0x0002ca14
void checkSpeedZeroCondition(void);  // @ 0x0002caa0
void selectFuelControlMode(void);  // @ 0x0002cb54
void calculateSpeedControlRampUp(void);  // @ 0x0002cbe8
void calculateSpeedControlRampDown(void);  // @ 0x0002cc90
void updateSpeedControlOutputs(void);  // @ 0x0002cd38
void selectSpeedControlGains(void);  // @ 0x0002cdb4
void processSpeedControlModeLogic(void);  // @ 0x0002ce8c
void calculateSpeedControlFiltered(void);  // @ 0x0002cebc
void selectFuelControlModeOutput(void);  // @ 0x0002d208
void calculateFuelControlLimits(void);  // @ 0x0002d2f8
void processFuelControlProtectionFlags(void);  // @ 0x0002d428
void processFuelControlOutput(void);  // @ 0x0002d5d8
void initProtectionModeDefaults(void);  // @ 0x0002d600
void initFuelControlStateVariables(void);  // @ 0x0002d638
void updateSpeedControlCounter1(int param_1);  // @ 0x0002d7a4
void processSpeedControlFilter1(int param_1);  // @ 0x0002d88c
void updateSpeedControlCounter2(int param_1);  // @ 0x0002d9f4
bool processSpeedControlFilter2(int param_1);  // @ 0x0002dadc
void initProtectionControlState(void);  // @ 0x0002dc40
void clearDiagnosticConditionFlags(void);  // @ 0x0002e02c
void processFaultCounterTimeout(void);  // @ 0x0002e17c
void incrementFaultTimeoutCounter(void);  // @ 0x0002e1f0
void processFaultConditionLogic(void);  // @ 0x0002e250
void calculateFaultThresholdDelta(void);  // @ 0x0002e488
void processFaultThresholdCondition(void);  // @ 0x0002e4cc
void processFaultConditionFlags(void);  // @ 0x0002e74c
void clearFaultStatusCounters(void);  // @ 0x0002e9c8
void processFaultStatusCalculation(void);  // @ 0x0002ea58
void clearFaultStatusValues(void);  // @ 0x0002ed30
void processFaultCondition1(void);  // @ 0x0002edc0
void calculateFaultStatusValue(void);  // @ 0x0002ef34
void processFaultConditionMain(void);  // @ 0x0002efe4
void processFaultCondition2(void);  // @ 0x0002f154
void calculateFaultStatusOffset(void);  // @ 0x0002f2c8
void processFaultStatusWord2(void);  // @ 0x0002f3a0
void calculateFaultRateValue(void);  // @ 0x0002f524
void processFaultStatusMain(void);  // @ 0x0002f5a4
void calculateDiagnosticStatusBits(void);  // @ 0x0002f604
void processFaultStatusFlags(void);  // @ 0x0002f6a0
void initFaultStatusFilterState(void);  // @ 0x0002f784
void protectionNormalHandler(void);  // @ 0x0002f860
void protectionOverloadHandler(void);  // @ 0x0002f920
void protectionCleanupHandler(void);  // @ 0x0002fe48
void protectionShutdownHandler(void);  // @ 0x0003004c
void protectionOutputController(void);  // @ 0x00030194
void protectionFinalizeState(void);  // @ 0x00030ad4
void protectionFuelDemandCheck(void);  // @ 0x00031320
void protectionTimeoutHandler(void);  // @ 0x0003148c
void protectionWarmupHandler(void);  // @ 0x00031584
void protectionStatusFlagHandler(void);  // @ 0x000316cc
void protectionStateTransitionCheck(void);  // @ 0x00031d98
uint protectionScaledLimitCalculation(int param_1);  // @ 0x000320e0
void protectionRateOfChangeCalculation(void);  // @ 0x00032250
void calculateProtectionFuelDemandThreshold(void);  // @ 0x0003241c
void processProtectionStateFlags(void);  // @ 0x0003257c
void protectionThresholdMonitor(void);  // @ 0x00032b00
void protectionStateMachine(void);  // @ 0x00032efc
void initProtectionFilterVariables(void);  // @ 0x000331cc
void evaluateProtectionModeFlags(void);  // @ 0x00033488
void decrementProtectionTimers(void);  // @ 0x000335e4
void calculateProtectionConditions(void);  // @ 0x00033948
void processProtectionFlagConditions(void);  // @ 0x000343ac
void filterProtectionLoadValue(void);  // @ 0x0003491c
void evaluateProtectionFaultCondition(void);  // @ 0x00034a30
void processCalibrationTablesMain(void);  // @ 0x00034abc
void initProtectionSystem(void);  // @ 0x00034b14
void processProtectionFaultSeverity(void);  // @ 0x00034dd4
void processProtectionRateLimitFlags(void);  // @ 0x00034f4c
void calculateProtectionThresholdLimit(void);  // @ 0x00035154
void processProtectionStateMachine(void);  // @ 0x00035328
void updateSensorBufferValues(void);  // @ 0x00035370
void copySensorValuesToBuffer(void);  // @ 0x00035518
void processSensorLookupTable5(void);  // @ 0x00035558
void initSensorLookupTable5(void);  // @ 0x000355e4
void calculateSensorLookupValue(void);  // @ 0x00035670
void updateSensorLookupTable(void);  // @ 0x000356fc
void processSensorLookupTable4(void);  // @ 0x00035788
void initSensorLookupTable4(void);  // @ 0x00035814
void processSensorLookupTable3(void);  // @ 0x000358a0
void initSensorLookupTable3(void);  // @ 0x0003592c
void processSensorLookupTable2(void);  // @ 0x000359b8
void initSensorLookupTable2(void);  // @ 0x00035a44
void processSensorLookupTable0(void);  // @ 0x00035ad0
void initSensorLookupTable1(void);  // @ 0x00035b5c
void processSensorLookupTable1(void);  // @ 0x00035be8
void initSensorLookupTableInit1(void);  // @ 0x00035c74
void processSensorTemperatureData(void);  // @ 0x00035d00
void computeTemperatureDifferential(undefined2 *param_1,int param_2,int param_3);  // @ 0x00035d48
void enableSensorFilterUpdate(void);  // @ 0x00035d70
void processSensorFilterCalibration(void);  // @ 0x00035d80
void initSensorCalibrationTables(void);  // @ 0x00035f14
void processFaultScanLookup(void);  // @ 0x00035fa8
void processMultiAxisInterpolation(void);  // @ 0x00036220
void j1939QueueEngineStatus(void);  // @ 0x000367a4
void j1939SetupTransportSession(void);  // @ 0x0003682c
void j1939QueuePeriodicMessage2(void);  // @ 0x0003686c
void j1939CheckTxTimeouts(void);  // @ 0x0003691c
void j1939UpdateTxTimers(void);  // @ 0x000369cc
void updateJ1939TxTimerCounter(void);  // @ 0x00036b10
void j1939QueueStatusMessage(void);  // @ 0x00036b68
void j1939QueuePeriodicMessage1(void);  // @ 0x00036bd8
void j1939FormatProprietaryStatus(void);  // @ 0x00036c1c
void processJ1939PeriodicMessages(void);  // @ 0x00036cec
void initJ1939TimerBuffers(void);  // @ 0x00036de0
void initJ1939StatusMessages(void);  // @ 0x00036f48
void initPeriodicTimerChannel6(void);  // @ 0x00037130
void initPeriodicTimerChannel5(void);  // @ 0x00037180
void initPeriodicTimerChannel4(void);  // @ 0x000371d0
void initPeriodicTimerChannel1(void);  // @ 0x00037214
void initPeriodicTimerChannel2(void);  // @ 0x00037270
void initPeriodicTimerChannel3(void);  // @ 0x000372c0
void initPeriodicTimerSystem(void);  // @ 0x00037334
void calculateFuelDemandOffsetTrim(void);  // @ 0x000373b0
void initFuelDemandOffsetFilter(void);  // @ 0x0003744c
void j1939PeriodicTimerCallback(void);  // @ 0x00037464
void initJ1939PeriodicConfig(void);  // @ 0x000374b8
void j1939SendPeriodicMessage(void);  // @ 0x00037580
void processProtectionCoolantLookup(void);  // @ 0x000375c8
void processProtectionVoltageOffset(void);  // @ 0x00037658
void dispatchProtectionOutputMode(void);  // @ 0x000376dc
void filterProtectionOutput(void);  // @ 0x00037744
void calculateProtectionOutputDemand(void);  // @ 0x00037a40
void applyProtectionOutputDemand(void);  // @ 0x00037c74
void checkProtectionOutputConditions(void);  // @ 0x00037f28
void processProtectionMode2(void);  // @ 0x00038120
void initProtectionFilterValues(void);  // @ 0x000384d0
void processEngineRpmTarget(void);  // @ 0x0003866c
void processEngineRpmDerivative(void);  // @ 0x00038760
void initEngineRpmFilterPointers(void);  // @ 0x00038824
void setEngineRpmFromCalibration(void);  // @ 0x00038868
void processSafetyConditionProtection(void);  // @ 0x0003889c
void initProtectionFilterLimits(void);  // @ 0x00038a98
void processJ1939DiagnosticMessages(void);  // @ 0x00038ac8
void triggerJ1939TransmitMessage(void);  // @ 0x00038c90
void j1939ProcessPeriodicTx(void);  // @ 0x00038cf0
void processCalibrationChecksumResponse(void);  // @ 0x00039004
void handleJ1939MessageTimeout(void);  // @ 0x00039bc0
void processUdsTransmitBuffer(void);  // @ 0x00039c44
void processCanMessageIndex(void);  // @ 0x00039d18
void j1939TransmitDiagnosticResponse(void);  // @ 0x00039e30
void j1939MessageResponseCallback(void);  // @ 0x00039f54
void clearCanMessageState(void);  // @ 0x0003a058
void resetUdsSessionState(void);  // @ 0x0003a080
void clearJ1939SyncFlags(void);  // @ 0x0003a0cc
void initUdsResponseBuffer(void);  // @ 0x0003a100
undefined4 processJ1939DM1Pending(void);  // @ 0x0003a290
void initJ1939MessageTables(void);  // @ 0x0003a450
void initJ1939BufferValues(void);  // @ 0x0003a9a4
void initJ1939BufferParams(void);  // @ 0x0003aaf0
void clearCanMessageBuffers(void);  // @ 0x0003ab20
void initJ1939TransmitSchedule(void);  // @ 0x0003abc4
void initJ1939CommunicationSystem(void);  // @ 0x0003ad04
void j1939TransmitScheduleCallback(void);  // @ 0x0003ad80
void processJ1939ReceivedMessages(void);  // @ 0x0003adcc
undefined4 calculateSecurityChecksum(uint param_1,uint param_2);  // @ 0x0003afb8
undefined4 validateDataWithChecksumTable(uint param_1,uint param_2,int param_3);  // @ 0x0003afc8
void processUdsSecurityService(void);  // @ 0x0003b030
void processProtectionCounters(void);  // @ 0x0003b910
void decrementProtectionChannelValue(void);  // @ 0x0003b95c
void selectProtectionOverrideMode(void);  // @ 0x0003bb28
void indirectJumpDispatcher(void);  // @ 0x0003bb74
void validateCalibrationAgainstEeprom(void);  // @ 0x0003bd14
void validateCalibratedParameterDelta(undefined4 param_1,int param_2);  // @ 0x0003bd5c
void validateCalibratedParameterChange(undefined4 param_1,int param_2);  // @ 0x0003bd60
void thunk_setByteAtOffset1(int param_1,undefined1 param_2);  // @ 0x0003be7c
void setByteAtOffset1(int param_1,undefined1 param_2);  // @ 0x0003be88
void processProtectionFaultFlags(void);  // @ 0x0003be90
void initProtectionChannelState(void);  // @ 0x0003bedc
void processProtectionChannelConfig(byte *param_1,byte param_2,byte *param_3);  // @ 0x0003c064
void evaluateProtectionChannelInput(byte *param_1,byte param_2,byte *param_3);  // @ 0x0003c090
void selectProtectionChannelMode(void);  // @ 0x0003c18c
void updateProtectionChannelOutput(undefined4 param_1,undefined4 param_2,int param_3,int param_4);  // @ 0x0003c1d4
void finalizeProtectionChannelState(undefined4 param_1,undefined4 param_2,int param_3,int param_4);  // @ 0x0003c1d8
void processEngineRpmMonitoring(void);  // @ 0x0003c26c
void configureOutputChannelFlags(uint param_1,undefined4 param_2,undefined4 param_3,ushort *param_4);  // @ 0x0003c33c
void processProtectionStateChange(void);  // @ 0x0003c5f0
void updateProtectionModeState (undefined2 param_1,undefined2 *param_2,int param_3,undefined2 *param_4, undefined4 param_5,undefined4 param_6,int param_7);  // @ 0x0003c62c
void processProtectionTimingCounter(void);  // @ 0x0003c6b0
void evaluateProtectionTimerThreshold(undefined4 param_1,undefined4 param_2,uint param_3);  // @ 0x0003c6ec
void checkProtectionVoltageInput(undefined2 *param_1,undefined2 param_2,int param_3);  // @ 0x0003c8bc
void validateBatteryVoltageInput(void);  // @ 0x0003c8ec
void processVoltageProtectionState(int param_1);  // @ 0x0003c928
void initFuelDemandFilterPointers(void);  // @ 0x0003ca90
void evaluateVoltageThresholds(byte param_1,ushort *param_2,int param_3);  // @ 0x0003caec
void calculateProtectionUnitConversion(void);  // @ 0x0003cbd4
void storePressureConversionResult(void);  // @ 0x0003cc10
void calculateFuelDemandLimit(void);  // @ 0x0003ccb4
void calculateFuelDemandLimitState(void);  // @ 0x0003ccd4
void trackFuelDemandMinimum(void);  // @ 0x0003cefc
void initFuelDemandTrackingState(void);  // @ 0x0003cf40
void processFaultPendingFlags(void);  // @ 0x0003cf68
void processOperatingModeFlags(void);  // @ 0x0003d070
void processFuelDemandEnableFlag(void);  // @ 0x0003d204
void processCalibration12FuelDemand(void);  // @ 0x0003d3b8
void initFuelDemandLimits(void);  // @ 0x0003d5fc
void j1939InitTransmitBuffer(char param_1);  // @ 0x0003d618
uint configurePeriodicTimer(int param_1,int param_2,int param_3,uint param_4);  // @ 0x0003d68c
void j1939ConfigureMultiFrame(int param_1,int param_2);  // @ 0x0003d904
int j1939QueueTransmitMessage(undefined4 *param_1,int param_2);  // @ 0x0003da60
void j1939ProcessTransmitQueue(void);  // @ 0x0003dbc0
void triggerJ1939TransmitQueueProcess(void);  // @ 0x0003dcf4
void initQsmcmQspiModule(void);  // @ 0x0003dd28
void clearEngineConditionCounter(void);  // @ 0x0003dd88
void processEngineConditionFlags(void);  // @ 0x0003dd98
void calculateFuelDemandValue(void);  // @ 0x0003dfb8
void setFuelDemandActiveFlag(void);  // @ 0x0003e210
void initFuelDemandFilterState(void);  // @ 0x0003e230
void processTorqueLimitConfig(void);  // @ 0x0003e2bc
void initTorqueLimitState(void);  // @ 0x0003e400
void calculateTorqueCurveValue(void);  // @ 0x0003e42c
void initTorqueCurveState(void);  // @ 0x0003e520
void clearFuelDemandState(void);  // @ 0x0003e578
void dispatchFuelDemandCallback(void);  // @ 0x0003e5ac
void registerFuelDemandCallback(void);  // @ 0x0003e5f0
void processFuelDemandCallback(void);  // @ 0x0003e620
void registerFuelDemandCallback2(void);  // @ 0x0003e7c0
void processFuelDemandCallback2(void);  // @ 0x0003e7f0
void processFuelDemandTimeout(void);  // @ 0x0003e8d8
void transitionFuelDemandStateImmediate(void);  // @ 0x0003e914
void processSensorInputFiltering(void);  // @ 0x0003e96c
void calculateTorqueLimitType1(void);  // @ 0x0003e974
void calculateTorqueLimits(void);  // @ 0x0003e984
void calculateTorqueLimitType2(void);  // @ 0x0003e994
void initThermalProtectionFilters(void);  // @ 0x0003eca4
void setThermalProtectionMode5(void);  // @ 0x0003eccc
void evaluateThermalProtectionActive(void);  // @ 0x0003ecdc
void calculateThermalLimitValue(void);  // @ 0x0003eea8
void processThermalDelayTimer(void);  // @ 0x0003f054
void processThermalRecovery(void);  // @ 0x0003f0b8
void processThermalProtectionState(void);  // @ 0x0003f154
void calculateThermalFuelLimit(void);  // @ 0x0003f218
void processThermalProtection(void);  // @ 0x0003f2b0
void applyThermalFuelLimit(void);  // @ 0x0003f35c
void initThermalProtectionState(void);  // @ 0x0003f38c
void processEngineLoadData(void);  // @ 0x0003f3f0
void resetEngineLoadTracker(void);  // @ 0x0003f6fc
void processEngineLoadFilters(void);  // @ 0x0003f734
void initEngineLoadFilterState(void);  // @ 0x0003f9c4
void calculateTimerFrequencyConversion(void);  // @ 0x0003fa5c
void initTpuBConfiguration(void);  // @ 0x0003fad4
void initEngineLoadProtection(void);  // @ 0x0003fba4
void processEngineLoadCalculation(void);  // @ 0x0003fc24
void processFuelRateConfig(void);  // @ 0x000400b8
void dispatchCalibrationBlockHandlers(void);  // @ 0x000402d4
void checkDiagnosticFuelOverride(void);  // @ 0x000403e4
void processProtectionRampControl(void);  // @ 0x0004043c
void initFuelFilterCoefficients(void);  // @ 0x00040828
void calculateFuelRateFromRpm(void);  // @ 0x00040844
uint calculateProtectionFuelLimit(uint param_1,uint param_2);  // @ 0x0004091c
void protectionFuelRateStep(int param_1);  // @ 0x00040938
void protectionFuelRateRamp(int param_1);  // @ 0x00040978
void processTimingTableLookup(void);  // @ 0x000409b0
void initFuelRateFromCapability(void);  // @ 0x00040d40
void validateFuelRateTarget(void);  // @ 0x00040d74
void copyProtectionRampValue(void);  // @ 0x00040dd4
void processTorqueLimitBounded(void);  // @ 0x00040de8
void processGovernorFuelRate(void);  // @ 0x00040e4c
void processProtectionRampTimer(void);  // @ 0x00040f80
void calculateProtectionLevelLimit(void);  // @ 0x000411b0
void processProtectionSystemBit3(void);  // @ 0x00041368
void processProtectionSystemBit4(void);  // @ 0x00041938
void applyMinimumProtectionLimit(void);  // @ 0x00041a10
void processGovernorErrorState(void);  // @ 0x00041a40
void processTemperatureCompensationMode(void);  // @ 0x00041b24
void processTemperatureTrim(void);  // @ 0x00041be4
void processFuelEfficiencyTrim(void);  // @ 0x00041fd4
void processTimingDispatcher(void);  // @ 0x0004218c
void initProtectionEventStates(void);  // @ 0x000421c8
void processSpeedControlLimits(void);  // @ 0x000422c0
void initEngineSpeedTracking(void);  // @ 0x00042438
void processSystemStatusLimits(void);  // @ 0x00042488
void processGovernorSpeedSetpoint(void);  // @ 0x0004256c
void enableProtectionRateLimit(void);  // @ 0x0004271c
void applyProtectionControlLimit(void);  // @ 0x0004272c
void setProtectionControlValue(void);  // @ 0x00042770
void copyProtectionAccumulator(void);  // @ 0x00042784
void applyProtectionTorqueLimit(void);  // @ 0x0004279c
void applySpeedControlProtectionLimit(void);  // @ 0x000427cc
void processProtectionLimits(void);  // @ 0x0004280c
void initProtectionTorqueLimit(void);  // @ 0x0004285c
void setEngineOperatingMode1(void);  // @ 0x00042894
void setEngineOperatingMode5(void);  // @ 0x000428d4
void resetEngineOperatingMode(void);  // @ 0x00042918
void dispatchModeHandlers(void);  // @ 0x00042978
void initProtectionParameter1(void);  // @ 0x000429a0
void processProtectionParameter1(void);  // @ 0x00042a2c
void initProtectionParameter2(void);  // @ 0x00042ab8
void processProtectionParameter2(void);  // @ 0x00042b44
void hpcr_cbdFillAccelerationBuffers(void);  // @ 0x00042bd0
void processLoadThrottle(void);  // @ 0x00042cfc
void hpcr_cbdCalculateCylinderTrims(void);  // @ 0x00042d78
void hpcr_cbdInitFilterState(void);  // @ 0x00043a5c
void processTimingCalibration(void);  // @ 0x00043ac0
void clearTimingCalibrationData(void);  // @ 0x00043d68
void resetEngineTimingAccumulators(void);  // @ 0x00043ddc
void updateSensorDiagnosticFlags(void);  // @ 0x00044374
void setEngineRunState3(void);  // @ 0x00044aa4
void evaluateProtectionThresholds(void);  // @ 0x00044ae0
void initEngineCrankSequence(void);  // @ 0x00044b54
void processProtectionConditions(void);  // @ 0x00044bf4
void setEngineCrankState1(void);  // @ 0x00044cc8
void setEngineRunState1(void);  // @ 0x00044d20
void engineRunState4Handler(void);  // @ 0x00044d70
void engineRunState3Handler(void);  // @ 0x00044dd0
void engineRunState4Conditional(void);  // @ 0x00044e3c
void engineRunState4Handler2(void);  // @ 0x00044eac
void protectionOverrideEvaluator(void);  // @ 0x00044f0c
void processEngineSyncPulses(void);  // @ 0x00044fa8
void updateEngineRunState(void);  // @ 0x00045478
void updateEngineCrankState(void);  // @ 0x000457d0
void calculateFuelDemandWithConditions(void);  // @ 0x00045ecc
void initRpmSetpointFilters(void);  // @ 0x0004665c
void calculateGovernorOutput(void);  // @ 0x000466a8
void initFuelFilterStates(void);  // @ 0x00046cf8
void updateEngineStatusWord(undefined2 *param_1,ushort *param_2);  // @ 0x00046dc8
void clearTimingAccumulators(void);  // @ 0x00046f64
void calculateTimingWithTables(void);  // @ 0x00046f7c
void interpolateFuelTableValue(void);  // @ 0x00046fb4
void calculateEngineTimingInterpolation(void);  // @ 0x00047140
void processDualAxisLookup(void);  // @ 0x00047178
void calculateEngineFaultTiming(int param_1);  // @ 0x00047394
void validateSyncCount(void);  // @ 0x000473cc
void checkEngineSyncPulse(void);  // @ 0x000476d4
void clearTimingDataAndFilters(void);  // @ 0x00047784
int protectionRecoveryHandler(int *param_1,int param_2);  // @ 0x00047838
int protectionModeSelector(int param_1,int *param_2,int param_3,uint param_4);  // @ 0x00047978
int protectionStateHandler(ushort *param_1,uint *param_2,int param_3);  // @ 0x00047a88
void calculateEngineTimingOffset(void);  // @ 0x00047bd0
void advanceSyncPointer(void);  // @ 0x00048fd8
void resetEngineSyncState(void);  // @ 0x00049004
void filterEngineSensorValue(void);  // @ 0x0004922c
void processEnginePositionDiagnostics(void);  // @ 0x00049264
void updateEngineDiagnosticCounters(void);  // @ 0x00049a54
void protectionInputValidator(void);  // @ 0x00049df0
void protectionSensorFaultHandler(void);  // @ 0x00049edc
void checkProtectionFaultConditions(void);  // @ 0x0004a114
void initEngineDiagnosticData(void);  // @ 0x0004a258
void calculateTpuTimingPeriod(void);  // @ 0x0004a2f8
void initTpuTimingInterrupts(void);  // @ 0x0004a37c
void processEnginePositionData(void);  // @ 0x0004a490
void processCommunicationDiagnostic(void);  // @ 0x0004a4c8
void updateEnginePositionErrors(void);  // @ 0x0004a748
void filterEnginePositionDelta(void);  // @ 0x0004a7ac
void initEnginePositionState(void);  // @ 0x0004a858
void updateEnginePosition(void);  // @ 0x0004a8cc
void updateProtectionBitFlags(uint param_1,int param_2);  // @ 0x0004a968
void protectionFaultEvaluator(uint param_1,ushort *param_2,int param_3,int param_4,int param_5);  // @ 0x0004aaac
void evaluateProtectionSyncFaults(void);  // @ 0x0004ac3c
void evaluateProtectionSyncStateConditional(void);  // @ 0x0004ac74
void initTimingFilterStates(void);  // @ 0x0004ad8c
void calculateEngineTimingData(void);  // @ 0x0004ae20
void updateEngineStatusFlags(void);  // @ 0x0004b5b8
void calculateFuel2DTableLookup(void);  // @ 0x0004b6cc
void applyProtectionLimit(void);  // @ 0x0004b9ac
void processMemoryScanValidation(void);  // @ 0x0004ba48
void evaluateConditionDescriptor(void);  // @ 0x0004ba80
void copyRomToRamBuffer(void);  // @ 0x0004bd00
bool protectionEnableCheck(void);  // @ 0x0004bd3c
void protectionConditionMonitor(void);  // @ 0x0004bd5c
void initOutputChannels(void);  // @ 0x0004bd74
void sensorCalibrationCheck(void);  // @ 0x0004be4c
undefined4 validateMemoryBlockChecksum(short param_1,int param_2,uint param_3);  // @ 0x0004bf90
undefined1 validateEepromAddress(short *param_1);  // @ 0x0004bfc8
undefined4 updateProtectionTimers(short param_1,int param_2,uint param_3);  // @ 0x0004c070
undefined1 enqueueToCircularBuffer(undefined4 param_1,short *param_2);  // @ 0x0004c0a8
void protectionConfigSelector(void);  // @ 0x0004c188
void protectionLimitCalculator(void);  // @ 0x0004c2d4
void initProtectionLimitVariables(void);  // @ 0x0004c69c
void initProtectionLimitStateVariant(undefined2 param_1);  // @ 0x0004c6d4
void j1939ProtectionConfigResponse(void);  // @ 0x0004c734
void j1939ProtectionDataResponse(void);  // @ 0x0004c7ec
void validateSensorData(void);  // @ 0x0004c8d8
void initSensorValidationSystem(void);  // @ 0x0004cb64
void configureOutputChannels(void);  // @ 0x0004cb6c
void configureOutputChannelsStateParam(void);  // @ 0x0004cb84
void configureOutputChannelsAltState(void);  // @ 0x0004cb90
int getProtectionSyncState(void);  // @ 0x0004cd50
void initSensorRetryCounters(void);  // @ 0x0004ce78
void miosChannel11Enable(void);  // @ 0x0004ce9c
void miosChannel11ReadStatus(undefined4 param_1);  // @ 0x0004cec4
void miosChannel11SetPwm(undefined4 param_1);  // @ 0x0004cef0
void miosChannel12Enable(void);  // @ 0x0004cf1c
void miosChannel12ReadStatus(undefined4 param_1);  // @ 0x0004cf44
void miosChannel12SetPwm(undefined4 param_1);  // @ 0x0004cf70
void miosChannel13Enable(void);  // @ 0x0004cf9c
void miosChannel13ReadStatus(undefined4 param_1);  // @ 0x0004cfc4
void miosChannel13SetPwm(undefined4 param_1);  // @ 0x0004cff0
void miosChannel14Enable(void);  // @ 0x0004d01c
void miosChannel14ReadStatus(undefined4 param_1);  // @ 0x0004d044
void miosChannel14SetPwm(undefined4 param_1);  // @ 0x0004d070
void miosChannel15Enable(void);  // @ 0x0004d09c
void miosChannel15ReadStatus(undefined4 param_1);  // @ 0x0004d0c4
void miosChannel15SetPwm(undefined4 param_1);  // @ 0x0004d0f0
void miosChannel27Enable(void);  // @ 0x0004d11c
void miosChannel27ReadStatus(undefined4 param_1);  // @ 0x0004d144
void miosChannel27SetPwm(undefined4 param_1);  // @ 0x0004d170
void miosChannel28Enable(void);  // @ 0x0004d19c
void miosChannel28ReadStatus(undefined4 param_1);  // @ 0x0004d1c4
void miosChannel28SetPwm(undefined4 param_1);  // @ 0x0004d1f0
void miosChannel29Enable(void);  // @ 0x0004d21c
void miosChannel29ReadStatus(undefined4 param_1);  // @ 0x0004d244
void miosChannel29SetPwm(undefined4 param_1);  // @ 0x0004d270
void miosChannel30Enable(void);  // @ 0x0004d29c
void miosChannel30ReadStatus(undefined4 param_1);  // @ 0x0004d2c4
void miosChannel30SetPwm(undefined4 param_1);  // @ 0x0004d2f0
void miosChannel31Enable(void);  // @ 0x0004d31c
void miosChannel31ReadStatus(undefined4 param_1);  // @ 0x0004d344
void miosChannel31SetPwm(undefined4 param_1);  // @ 0x0004d370
void miosTimer0InitPeriod(void);  // @ 0x0004d39c
void miosTimer0ScaleByPercent(undefined4 param_1);  // @ 0x0004d3c4
void miosTimer0SetValue(undefined4 param_1);  // @ 0x0004d3f0
void miosTimer1InitPeriod(void);  // @ 0x0004d41c
void miosTimer1ScaleByPercent(undefined4 param_1);  // @ 0x0004d444
void miosTimer1SetValue(undefined4 param_1);  // @ 0x0004d470
void miosTimer2InitPeriod(void);  // @ 0x0004d49c
void miosTimer2ScaleByPercent(undefined4 param_1);  // @ 0x0004d4c4
void miosTimer2SetValue(undefined4 param_1);  // @ 0x0004d4f0
void miosTimer3InitPeriod(void);  // @ 0x0004d51c
void miosTimer3ScaleByPercent(undefined4 param_1);  // @ 0x0004d544
void miosTimer3SetValue(undefined4 param_1);  // @ 0x0004d570
void miosTimer16InitPeriod(void);  // @ 0x0004d59c
void miosTimer16ScaleByPercent(undefined4 param_1);  // @ 0x0004d5c4
void miosTimer16ScaleOutput(void);  // @ 0x0004d5d4
void miosTimer16SetValue(undefined4 param_1);  // @ 0x0004d5f0
void miosTimer16SetOutput(undefined4 param_1);  // @ 0x0004d5fc
void miosTimer17InitPeriod(void);  // @ 0x0004d61c
void miosTimer17InitPeriodAlt(void);  // @ 0x0004d628
void miosTimer17ScaleByPercent(undefined4 param_1);  // @ 0x0004d644
void miosTimer17ScaleDefault(void);  // @ 0x0004d654
void miosTimer17SetValue(undefined4 param_1);  // @ 0x0004d670
void miosTimer17SetValueAlt(undefined4 param_1);  // @ 0x0004d67c
void miosTimer18InitPeriod(void);  // @ 0x0004d69c
void miosTimer18InitPeriodAlt(void);  // @ 0x0004d6a8
void miosTimer18ScaleByPercent(undefined4 param_1);  // @ 0x0004d6c4
void miosTimer18ScaleDefault(void);  // @ 0x0004d6d4
void miosTimer18SetValue(undefined4 param_1);  // @ 0x0004d6f0
void miosTimer18SetValueAlt(undefined4 param_1);  // @ 0x0004d6fc
void miosTimer19InitPeriod(void);  // @ 0x0004d71c
void miosTimer19InitPeriodAlt(void);  // @ 0x0004d728
void miosTimer19ScaleByPercent(undefined4 param_1);  // @ 0x0004d744
void miosTimer19ScaleDefault(void);  // @ 0x0004d754
void miosTimer19SetValue(undefined4 param_1);  // @ 0x0004d770
void miosTimer19SetValueAlt(undefined4 param_1);  // @ 0x0004d77c
void tpuChannel0Reset(void);  // @ 0x0004d79c
void miosTimer20Configure(void);  // @ 0x0004d7a8
void tpuChannel0SetDuty(undefined4 param_1);  // @ 0x0004d7c0
void tpuChannel0Configure(undefined4 param_1);  // @ 0x0004d7e8
void tpuChannel1Reset(void);  // @ 0x0004d810
void tpuChannel1SetDuty(undefined4 param_1);  // @ 0x0004d834
void tpuChannel1Configure(undefined4 param_1);  // @ 0x0004d85c
void tpuChannel2Reset(void);  // @ 0x0004d884
void tpuChannel2SetDuty(undefined4 param_1);  // @ 0x0004d8a8
void tpuChannel2Configure(undefined4 param_1);  // @ 0x0004d8d0
void tpuChannel3Reset(void);  // @ 0x0004d8f8
void tpuChannel3SetDuty(undefined4 param_1);  // @ 0x0004d91c
void tpuChannel3Configure(undefined4 param_1);  // @ 0x0004d944
void tpuChannel4Reset(void);  // @ 0x0004d96c
void tpuChannel4SetDuty(undefined4 param_1);  // @ 0x0004d990
void tpuChannel4Configure(undefined4 param_1);  // @ 0x0004d9b8
void tpuChannel5Reset(void);  // @ 0x0004d9e0
void tpuChannel5SetDuty(undefined4 param_1);  // @ 0x0004da04
void tpuChannel5Configure(undefined4 param_1);  // @ 0x0004da2c
void tpuChannel6Reset(void);  // @ 0x0004da54
void tpuChannel6SetDuty(undefined4 param_1);  // @ 0x0004da78
void tpuChannel6Configure(undefined4 param_1);  // @ 0x0004daa0
void tpuChannel7Reset(void);  // @ 0x0004dac8
void tpuChannel7SetDuty(undefined4 param_1);  // @ 0x0004daec
void tpuChannel7Configure(undefined4 param_1);  // @ 0x0004db14
void tpuChannel8Reset(void);  // @ 0x0004db3c
void tpuChannel8SetDuty(undefined4 param_1);  // @ 0x0004db60
void tpuChannel8Configure(undefined4 param_1);  // @ 0x0004db88
void tpuChannel9Reset(void);  // @ 0x0004dbb0
void tpuChannel9SetDuty(undefined4 param_1);  // @ 0x0004dbd4
void tpuChannel9Configure(undefined4 param_1);  // @ 0x0004dbfc
void tpuChannel10Reset(void);  // @ 0x0004dc24
void tpuChannel10SetDuty(undefined4 param_1);  // @ 0x0004dc48
void tpuChannel10Configure(undefined4 param_1);  // @ 0x0004dc70
void tpuChannel11Reset(void);  // @ 0x0004dc98
void tpuChannel11SetDuty(undefined4 param_1);  // @ 0x0004dcbc
void tpuChannel11Configure(undefined4 param_1);  // @ 0x0004dce4
void tpuChannel12Reset(void);  // @ 0x0004dd0c
void tpuChannel12SetDuty(undefined4 param_1);  // @ 0x0004dd30
void tpuChannel12Configure(undefined4 param_1);  // @ 0x0004dd58
void tpuChannel13Reset(void);  // @ 0x0004dd80
void tpuChannel13SetDuty(undefined4 param_1);  // @ 0x0004dda4
void tpuChannel13Configure(undefined4 param_1);  // @ 0x0004ddcc
void tpuChannel14Reset(void);  // @ 0x0004ddf4
void tpuChannel14SetDuty(undefined4 param_1);  // @ 0x0004de18
void tpuChannel14Configure(undefined4 param_1);  // @ 0x0004de40
void tpuChannel15Reset(void);  // @ 0x0004de68
void tpuChannel15SetDuty(undefined4 param_1);  // @ 0x0004de8c
void tpuChannel15Configure(undefined4 param_1);  // @ 0x0004deb4
void disableMiosResetTpu14_10(void);  // @ 0x0004dedc
undefined2 setMiosDutyCycle14(void);  // @ 0x0004df0c
void configureTpuChannel10Alt(undefined4 param_1);  // @ 0x0004df40
void setTpuDutyWithTrack10(undefined4 param_1);  // @ 0x0004df68
void resetMiosTpuChannel29_11(void);  // @ 0x0004df98
void disableMiosResetTpu11_4(void);  // @ 0x0004e0c0
undefined2 setMiosDutyCycle11(void);  // @ 0x0004e0f0
void configureTpuChannel4Alt(undefined4 param_1);  // @ 0x0004e124
void setTpuDutyWithTrack4(undefined4 param_1);  // @ 0x0004e14c
void disableMiosResetTpu13_6(void);  // @ 0x0004e180
undefined2 setMiosDutyCycle13(void);  // @ 0x0004e1b0
void configureTpuChannel6Alt(undefined4 param_1);  // @ 0x0004e1e4
void setTpuDutyWithTrack6(undefined4 param_1);  // @ 0x0004e20c
void disableMiosResetTpu12_7(void);  // @ 0x0004e240
undefined2 setMiosDutyCycle12(void);  // @ 0x0004e270
void configureTpuChannel7Alt(undefined4 param_1);  // @ 0x0004e2a4
void setTpuDutyWithTrack7(undefined4 param_1);  // @ 0x0004e2cc
void tpuOutput0Enable(void);  // @ 0x0004e300
void tpuOutput0Disable(undefined4 param_1);  // @ 0x0004e324
void tpuOutput0SetPeriod(undefined4 param_1);  // @ 0x0004e34c
void tpuOutput1Enable(void);  // @ 0x0004e374
void tpuOutput1Disable(undefined4 param_1);  // @ 0x0004e398
void tpuOutput1SetPeriod(undefined4 param_1);  // @ 0x0004e3c0
void tpuOutput2Enable(void);  // @ 0x0004e3e8
void tpuOutput2Disable(undefined4 param_1);  // @ 0x0004e40c
void tpuOutput2SetPeriod(undefined4 param_1);  // @ 0x0004e434
void tpuOutput3Enable(void);  // @ 0x0004e45c
void tpuOutput3Disable(undefined4 param_1);  // @ 0x0004e480
void tpuOutput3SetPeriod(undefined4 param_1);  // @ 0x0004e4a8
void tpuOutput4Enable(void);  // @ 0x0004e4d0
void tpuOutput4Disable(undefined4 param_1);  // @ 0x0004e4f4
void tpuOutput4SetPeriod(undefined4 param_1);  // @ 0x0004e51c
void tpuOutput5Enable(void);  // @ 0x0004e544
void tpuOutput5Disable(undefined4 param_1);  // @ 0x0004e568
void tpuOutput5SetPeriod(undefined4 param_1);  // @ 0x0004e590
void tpuOutput6Enable(void);  // @ 0x0004e5b8
void tpuOutput6Disable(undefined4 param_1);  // @ 0x0004e5dc
void tpuOutput6SetPeriod(undefined4 param_1);  // @ 0x0004e604
void tpuOutput7Enable(void);  // @ 0x0004e62c
void tpuOutput7Disable(undefined4 param_1);  // @ 0x0004e650
void tpuOutput7SetPeriod(undefined4 param_1);  // @ 0x0004e678
void tpuOutput8Enable(void);  // @ 0x0004e6a0
void tpuOutput8Disable(undefined4 param_1);  // @ 0x0004e6c4
void tpuOutput8SetPeriod(undefined4 param_1);  // @ 0x0004e6ec
void tpuOutput9Enable(void);  // @ 0x0004e714
void tpuOutput9Disable(undefined4 param_1);  // @ 0x0004e738
void tpuOutput9SetPeriod(undefined4 param_1);  // @ 0x0004e760
void tpuOutput10Enable(void);  // @ 0x0004e788
void tpuOutput10Disable(undefined4 param_1);  // @ 0x0004e7ac
void tpuOutput10SetPeriod(undefined4 param_1);  // @ 0x0004e7d4
void tpuOutput11Enable(void);  // @ 0x0004e7fc
void tpuOutput11Disable(undefined4 param_1);  // @ 0x0004e820
void tpuOutput11SetPeriod(undefined4 param_1);  // @ 0x0004e848
void tpuOutput12Enable(void);  // @ 0x0004e870
void tpuOutput12Disable(undefined4 param_1);  // @ 0x0004e894
void tpuOutput12SetPeriod(undefined4 param_1);  // @ 0x0004e8bc
void tpuOutput13Enable(void);  // @ 0x0004e8e4
void tpuOutput13Disable(undefined4 param_1);  // @ 0x0004e908
void tpuOutput13SetPeriod(undefined4 param_1);  // @ 0x0004e930
void tpuOutput14Enable(void);  // @ 0x0004e958
void tpuOutput14Disable(undefined4 param_1);  // @ 0x0004e97c
void tpuOutput14SetPeriod(undefined4 param_1);  // @ 0x0004e9a4
void tpuOutput15Enable(void);  // @ 0x0004e9cc
void tpuOutput15Disable(undefined4 param_1);  // @ 0x0004e9f0
void tpuOutput15SetPeriod(undefined4 param_1);  // @ 0x0004ea18
void orBitsInArray(undefined4 param_1,undefined4 param_2,byte *param_3);  // @ 0x0004ea78
void clearBitsInArray(undefined4 param_1,undefined4 param_2,byte *param_3);  // @ 0x0004eabc
byte checkProtectionWarningBitState(uint param_1);  // @ 0x0004eac8
byte checkProtectionBitWarningState(undefined4 param_1,byte param_2);  // @ 0x0004eb00
void updateEngineCycleOutputs(void);  // @ 0x0004eb48
void initProtectionAndOutputCycle(void);  // @ 0x0004eeb8
void setEngineProtectionFault(uint param_1,int param_2);  // @ 0x0004ef24
void setBitInArray(int param_1,undefined4 param_2,byte *param_3);  // @ 0x0004ef5c
void clearProtectionFault(uint param_1);  // @ 0x0004ef74
void dispatchSyncUpdateByFlag(void);  // @ 0x0004efac
void triggerProtectionEvent(uint param_1,int param_2);  // @ 0x0004f000
void clearEventFlag(int param_1,undefined4 param_2,byte *param_3);  // @ 0x0004f038
void protectionFlagManager(uint param_1);  // @ 0x0004f050
void conditionalSyncFlagUpdate(void);  // @ 0x0004f088
void checkProtectionModeFlags(void);  // @ 0x0004f0dc
void protectionAlarmHandler(void);  // @ 0x0004f190
void processProtectionFaultsAndTiming(void);  // @ 0x0004f2b0
undefined4 protectionWarningHandler(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4);  // @ 0x0004f2ec
undefined4 evaluateHardwareTimerState(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4);  // @ 0x0004f324
void clearModuleSyncFlag(uint param_1);  // @ 0x0004f6f0
void updateEngineSyncStatus(uint param_1);  // @ 0x00051038
void injectorTimingCalculation(void);  // @ 0x000529b8
void hpcr_injectorPulseWidthCalc(void);  // @ 0x000533e0
void processJ1939TxBufferSend(void);  // @ 0x000535e8
void queueCanReceiveMessage(int param_1);  // @ 0x00053720
void sendJ1939SingleFrame(uint param_1,uint param_2,int param_3,undefined1 *param_4);  // @ 0x00053858
void enqueueCanTransmitFrame(uint param_1,uint param_2,int param_3);  // @ 0x00053890
void sendJ1939MultiFrame(undefined4 *param_1);  // @ 0x000539fc
void validateDiagnosticResponseWrapper(void);  // @ 0x00053a34
undefined4 lookupJ1939SourceAddressIndex(uint param_1);  // @ 0x00053a4c
void handleCanMailboxTransmitComplete(uint param_1);  // @ 0x00053aa8
void handleCanMailboxTransmitRange(int param_1);  // @ 0x00053ae0
void writeCanControllerTxMailbox(int param_1,int param_2,int param_3);  // @ 0x00053b28
void canTransmitInterruptHandler(void);  // @ 0x00053b68
void emptyStub3(void);  // @ 0x00053c60
void emptyStub4(void);  // @ 0x00053c64
undefined4 findJ1939MessageEntry(int param_1,uint param_2,int param_3);  // @ 0x00053c68
undefined4 addCoolantCalEntry(uint param_1,int param_2);  // @ 0x00053cd8
void addCoolantCalEntry(undefined2 param_1,undefined1 param_2,undefined2 param_3);  // @ 0x00053d3c
void setDefaultCalibrationValue(void);  // @ 0x00053d74
void addCoolantCalEntryAlt(undefined1 param_1,undefined2 param_2);  // @ 0x00053d84
void processCoolantCalEntries(void);  // @ 0x00053dc8
void removeCoolantCalEntryByParams(int param_1,uint param_2);  // @ 0x00053fa8
void removeCalibrationListEntry (int param_1,uint param_2,int param_3,byte *param_4,uint param_5,short *param_6);  // @ 0x00053fe0
void removeCoolantCalEntry(uint param_1);  // @ 0x00054064
void miosInterruptDispatcher(void);  // @ 0x00054100
void infiniteLoopHalt(void);  // @ 0x0005419c
void enableSchedulerMiosOutput(void);  // @ 0x000541f4
void emptyStubFunction(void);  // @ 0x00054220
void checkRpmOverspeedProtection(void);  // @ 0x00054224
void systemStartupInitialization(undefined2 param_1);  // @ 0x00054380
void exceptionHandler(void);  // @ 0x000544c4
undefined4 miosSetChannelDutyCycle(int *param_1,int param_2);  // @ 0x00054e10
void miosChannelDisable(int param_1);  // @ 0x00054eac
void miosChannelEnable(int param_1);  // @ 0x00054eb8
void miosReadChannelStatus(undefined4 *param_1,ushort param_2);  // @ 0x00054ec4
void miosSetPwmOutput(undefined4 param_1,uint param_2);  // @ 0x00054f48
void miosInitChannelPeriod(int param_1);  // @ 0x00054f80
void scalePwmByPercent(ushort *param_1,ushort param_2);  // @ 0x00054f8c
void miosSetChannelValue(undefined2 *param_1,uint param_2);  // @ 0x00054fb8
void tpuResetChannel(uint param_1);  // @ 0x00055020
void tpuSetChannelDuty(int param_1,ushort param_2);  // @ 0x00055178
void tpuConfigureChannel(int param_1,uint param_2);  // @ 0x000551e4
void tpuEnableChannelOutput(uint param_1);  // @ 0x00055294
void tpuDisableChannelOutput(int param_1,ushort param_2);  // @ 0x000553ec
void tpuSetChannelPeriod(int param_1,uint param_2);  // @ 0x00055458
void initQadcModule(void);  // @ 0x00055500
void copyDataBuffer(int param_1,int param_2);  // @ 0x000555cc
undefined4 processSecurityCodeConversion(undefined4 param_1);  // @ 0x0005573c
undefined4 validateSecurityCode(void);  // @ 0x0005576c
void processEngineRpmDiagnostic(void);  // @ 0x0005586c
void dispatchCalibrationFunctions(void);  // @ 0x00055a40
void initTpuConfiguration(void);  // @ 0x00055c1c
void tpuBInterruptDispatcher(void);  // @ 0x00055d2c
void tpuAInterruptDispatcher(void);  // @ 0x00055de4
void emptyStubFunction(void);  // @ 0x00055e9c
uint calculateCrc16(int param_1,byte *param_2,uint param_3,int param_4,uint param_5, undefined4 param_6,undefined4 param_7,uint param_8);  // @ 0x00055ed0
uint lookupTableInterpolation(ushort *param_1,uint param_2,ushort *param_3,int param_4,uint param_5);  // @ 0x00055ef4
uint linearInterpolate1D(ushort param_1,short param_2,int param_3,int param_4,uint param_5, ushort *param_6);  // @ 0x00055f24
void extendedDivisionWithRemainder (uint param_1,uint param_2,uint param_3,uint *param_4,int *param_5);  // @ 0x00056184
int signedDivisionWithSaturation(uint param_1,int param_2);  // @ 0x00056260
int clampedDivisionWithBounds(uint param_1,int param_2,int param_3,int param_4);  // @ 0x000562fc
void noOperation2(void);  // @ 0x0005632c
void noOperation2(void);  // @ 0x000563e4
uint saturatingDivision16(uint param_1,uint param_2);  // @ 0x000563e8
int signedFirstOrderFilter(int param_1,undefined4 *param_2);  // @ 0x0005644c
int signedFilterWithWeight (uint param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6);  // @ 0x0005647c
int signedFilterWithWeight (uint param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6);  // @ 0x00056488
int secondOrderFilter(short param_1,undefined4 *param_2);  // @ 0x000564c0
int multiplyAccumulateFixed32(short param_1,int param_2);  // @ 0x000564f0
uint exponentialMovingAverage(uint param_1,undefined4 *param_2);  // @ 0x00056594
uint filterWithWeight(uint param_1,int param_2,int param_3,undefined4 param_4,int param_5, int param_6);  // @ 0x000565c4
uint filterWithWeight(uint param_1,int param_2,int param_3,undefined4 param_4,int param_5, int param_6);  // @ 0x000565d0
undefined4 lookupTableByIndex(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5);  // @ 0x00056638
uint dualAxisTableInterpolation(void *table_descriptor,word x_input,word y_input);  // @ 0x000566cc
uint interpolateWithIndex (ushort *param_1,uint param_2,int param_3,uint param_4,ushort *param_5,int param_6);  // @ 0x000566fc
undefined4 ringBufferWriteByte(int *param_1,undefined1 param_2);  // @ 0x00056c80
void ringBufferInit(int *param_1,int param_2,int param_3);  // @ 0x00056d38
void memcpyBytes(int param_1,int param_2,int param_3);  // @ 0x00056d58
void delayMicroseconds(int param_1);  // @ 0x00056d88
void waitForTimeBaseTicks(int param_1,uint param_2);  // @ 0x00056db8
void delayMicroseconds2(int param_1);  // @ 0x00056e0c
void waitForTimeBaseDelay(int param_1,uint param_2);  // @ 0x00056e3c
void unsignedDivision64by32(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4);  // @ 0x00056e90
void signedDivision32(undefined4 param_1,undefined4 param_2,int param_3,int param_4);  // @ 0x000570f0
void signedDivision64(int param_1,undefined4 param_2,int param_3,int param_4);  // @ 0x00057120
void unsignedDivision32(undefined4 param_1,undefined4 param_2,int param_3,int param_4);  // @ 0x000571b0
void unsignedDivision64Wrapper(void);  // @ 0x000571e0
void mathMultiplyDivide32(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4);  // @ 0x00057204
void conditionalMultiplyDivide(undefined4 param_1,undefined4 param_2,int param_3,int param_4);  // @ 0x00057498
void emptyStubFunction2(void);  // @ 0x00057520
void calibrationTableLookup1D(void);  // @ 0x00057524
void saveRegistersToStack(void);  // @ 0x0005759c
void calibrationTableLookup2D(void);  // @ 0x000575a0
void invalidInstructionData(void);  // @ 0x0006432c
void initCanMailboxFilters_ram(void);  // @ 0x003fa2f0
void initFlashMemoryConfig_ram(void);  // @ 0x003fa5a0
void can2TransmitInterruptHandler_ram(void);  // @ 0x003fab3c
void dispatchCanMessageHandlers_ram(void);  // @ 0x003fae3c
void getServiceDataOffset_ram(void);  // @ 0x003fb528
void validateServiceDataLength_ram(void);  // @ 0x003fb54c
void processJ1939QueueStatus_ram(void);  // @ 0x003fc094
void initDiagnosticBuffers_ram(void);  // @ 0x003fc0d8
void serialReceiveHandler_ram(void);  // @ 0x003fc380
void serialTransmitHandler_ram(void);  // @ 0x003fc484
void validateSerialChecksum_ram(void);  // @ 0x003fc580
void initSerialTransmit_ram(void);  // @ 0x003fc62c
void eepromPollReady(void);  // @ 0x003fc688
void eepromCheckStatus(void);  // @ 0x003fc6f4
void eepromWaitCycle(void);  // @ 0x003fc77c
void processMainLoop_ram(void);  // @ 0x003fc874
void sendEepromVersionResponse_ram(void);  // @ 0x003fc9ec
void handleEepromDiagnosticResponse_ram(void);  // @ 0x003fca7c
void processEepromDataTransfer_ram(void);  // @ 0x003fcb24
void processSensorFilterChain_ram(void);  // @ 0x003fd070
void processSensorWithOverride_ram(void);  // @ 0x003fd1ac
void watchdogTimerTick_ram(void);  // @ 0x003fd1d8
void watchdogTimerTick_midEntry_ram(void);  // @ 0x003fd284
void sensorFaultThresholdCheck_ram(void);  // @ 0x003fd298
void eepromCompleteOperation(void);  // @ 0x003fd544
void initQspiHardware_ram(void);  // @ 0x003fd6d8
void systemHaltLoop_ram(void);  // @ 0x003fd994
void FUN_0040a046(void);  // @ 0x0040a046
void sensorChannel0_init(void);  // @ 0x00500004
void sensorChannel0_process(void);  // @ 0x00500090
void sensorChannel1_init(void);  // @ 0x0050011c
void sensorChannel1_process(void);  // @ 0x005001a8
void sensorChannelConfigInit (int param_1,undefined2 *param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6,int param_7,uint param_8,uint param_9, uint param_10,undefined2 *param_11,undefined2 *param_12,undefined2 *param_13);  // @ 0x00500234
void updateSensorChannelWithConfig (int param_1,undefined2 *param_2,undefined2 *param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6,int *param_7,uint param_8,uint param_9, uint param_10,undefined2 *param_11,undefined2 *param_12,undefined2 *param_13);  // @ 0x00500a4c
void sensorChannelCalibration_init(void);  // @ 0x005011c4
void sensorChannelCalibration_process(void);  // @ 0x00501250
void sensorChannelTypeB_configInit (int param_1,undefined2 *param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6,int param_7,uint param_8,uint param_9, uint param_10,undefined2 *param_11,undefined2 *param_12,undefined2 *param_13);  // @ 0x005012dc
void updateSensorChannelTypeB (int param_1,undefined2 *param_2,undefined2 *param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6,int *param_7,uint param_8,uint param_9, uint param_10,undefined2 *param_11,undefined2 *param_12,undefined2 *param_13);  // @ 0x00501b4c
void evaluateSensorChannelStatus(void);  // @ 0x005022cc
void updateSensorModeState(void);  // @ 0x0050241c
void processSensorInterpolationMode(void);  // @ 0x00502464
void limitFuelDemandValue(void);  // @ 0x00502af4
void clearBufferInitFlag(void);  // @ 0x00502b24
void initSensorBufferValues(void);  // @ 0x00502b34
void filterAndInterpolateSensor(void);  // @ 0x00502b6c
void initAndFilterSensor(void);  // @ 0x00502eb8
void initGovernorModeState(int param_1);  // @ 0x00503074
void clearProtectionModeVariables(void);  // @ 0x005031b4
void evaluateSpeedControlTiming(void);  // @ 0x005033a0
void evaluateSpeedModeConditions(void);  // @ 0x00503604
void evaluateFuelConditionFlags(void);  // @ 0x0050370c
void normalizeSpeedValue(void);  // @ 0x00503790
void resetSpeedControlState(void);  // @ 0x00503960
void processSpeedControlPipeline(void);  // @ 0x00503964
void initSpeedControlSystem(void);  // @ 0x0050398c
void interpolateSpeedControl6Point(void);  // @ 0x005039b4
void initializeSpeedIntegratorStates(void);  // @ 0x00503b2c
void calculateLoadNormalizationDelta(void);  // @ 0x00503b54
void calculateSpeedFilterTerm(void);  // @ 0x00503cbc
void calculateSpeedOffsetTerm(void);  // @ 0x00503ed0
void calculateSpeedFilterCoefficients(void);  // @ 0x00503f60
void interpolateSpeedControlOutput(void);  // @ 0x00503f84
void initializeSpeedControlOutputs(void);  // @ 0x00504110
void calculateFuelTimingGain(void);  // @ 0x00504130
void interpolateFuelTrimPrimary(void);  // @ 0x005041bc
void calculateFuelScaleMultiplier(void);  // @ 0x0050422c
void interpolateFuelTrimSecondary(void);  // @ 0x005043b4
void calculateFuelTrimAdjustments(void);  // @ 0x00504528
void calculatePressureRatio(void);  // @ 0x00504654
void initPressureBufferValues(void);  // @ 0x00504754
void selectMaximumPressureValue(void);  // @ 0x0050477c
void clearPressureAccumulator(void);  // @ 0x00504938
void processFuelControlCoordinator(void);  // @ 0x00504948
void interpolateBoostTrimCalibration(void);  // @ 0x00504994
void interpolateBoostTrimTable(void);  // @ 0x00504b0c
void interpolateFuelTrimTable(void);  // @ 0x00504d38
void interpolateCoolantTrimTable(void);  // @ 0x00504eb0
void processPressureAndTemperatureTrim(void);  // @ 0x005050f4
void packFuelControlStatusFlags(void);  // @ 0x00505260
void calculateFuelBlendMode(void);  // @ 0x0050530c
void clearFuelBlendFactor1(void);  // @ 0x005053d0
void updateFuelTrimAccumulator(void);  // @ 0x005053e0
void clearFuelAccumulatorBuffers(void);  // @ 0x00505574
void validatePressureEnableConditions(void);  // @ 0x005055a0
void evaluateEngineSpeedMode(void);  // @ 0x00505600
void evaluateCoolantTemperatureMode(void);  // @ 0x005056f8
void initPressureBufferPointer(void);  // @ 0x005057dc
void evaluateEngineLoadConditions(void);  // @ 0x005057ec
void calculateFuelConsumptionRate(void);  // @ 0x005058a8
void evaluateThrottleSensorConditions(void);  // @ 0x005059ec
void processThrottlePositionState(void);  // @ 0x00505b3c
void selectSpeedControlFromSensorFlags(void);  // @ 0x00505b84
void updateSpeedControlState(void);  // @ 0x00505bd8
void transferEepromData(void);  // @ 0x00505c20
void initEepromTransferState(void);  // @ 0x00505d94
void processDiagnosticDataTransfer(void);  // @ 0x00505df0
void processProtectionParameterData(int param_1);  // @ 0x00505f98
void processFuelBlendCalculations(void);  // @ 0x0050638c
void incrementFuelAndSpeedCounters(void);  // @ 0x00506780
void restoreFuelAndSpeedCounters(void);  // @ 0x005067bc
void calculateSignedRatioDivision(void);  // @ 0x005067e0
void calculateDivisionWithReset(void);  // @ 0x00506968
void calculateTimingFloorDivision(void);  // @ 0x00506a3c
void calculateTimingFloorDivisionB(void);  // @ 0x00506a64
void calculateTimingOffsetWithFilter(void);  // @ 0x00506ad4
void calculateFuelTimingWithFilter(undefined4 param_1,short param_2);  // @ 0x00506b34
void interpolateFuelTimingWithCheck(void);  // @ 0x00506cd4
void selectFuelTimingSourceByFlag(void);  // @ 0x00506e18
void selectFuelTimingMode(void);  // @ 0x00506e28
void updateFuelTimingInterpolation(void);  // @ 0x00506e64
void filterPressureAdjustmentWithFlags(void);  // @ 0x00506ec0
void evaluatePressureRampConditions(ushort param_1);  // @ 0x00506f68
void processPressureRampControl(void);  // @ 0x00507040
void clearPressureModeFlags(void);  // @ 0x005071b8
void clearPressureModeFlagAtOffset(void);  // @ 0x005071dc
void calculatePressureDeltaAndUpdate(void);  // @ 0x005071f4
void initPressureControlState(void);  // @ 0x00507264
void interpolateLoadNormalizationMap(void);  // @ 0x00507340
void interpolateTemperatureScale(void);  // @ 0x005073f4
void updateLoadAndTemperatureScales(void);  // @ 0x005074a8
void interpolateAuxiliaryParameter(void);  // @ 0x00507504
void interpolateFuelInjectionParam(void);  // @ 0x00507548
void updateFuelInjectionMinimumValues(void);  // @ 0x00507644
void processFuelInjectionControl(void);  // @ 0x005076cc
void calculateInjectionScaledDivision(void);  // @ 0x005077fc
void dispatchMultiPhaseStateMachine(void);  // @ 0x005078f0
ushort calculateRampAdjustment(int param_1,int param_2,ushort *param_3,int param_4);  // @ 0x005079fc
ushort adjustParameterWithRampLimit(int param_1,undefined4 param_2,ushort param_3,int param_4);  // @ 0x00507a20
undefined2 interpolate2DTable(int param_1,int param_2,short param_3);  // @ 0x00507a6c
void initProtectionLimiterState(void);  // @ 0x00507acc
undefined4 evaluateFlagCondition(ushort *param_1,undefined4 *param_2,int param_3,int param_4);  // @ 0x00507b68
void emptyStub_reserved507c1c(void);  // @ 0x00507c1c
undefined4 dispatchByParamMode(int param_1,int param_2,undefined4 param_3,int param_4,uint param_5,int param_6);  // @ 0x00507c44
void evaluateLimitSourceFlags(void);  // @ 0x00507cd8
void evaluatehpcr_CbdSensorActivation(void);  // @ 0x00507ddc
void processLimitPriorityConditions(void);  // @ 0x00507e20
void clearProtectionStatusFlags(void);  // @ 0x00507f9c
void evaluateLimitConditionByFlag(ushort *param_1,undefined4 *param_2,int param_3);  // @ 0x00507fd8
void checkLimitBoundaryCondition(int param_1,int param_2,int param_3);  // @ 0x005080b4
void iterateAndApplyLimitConditions(void);  // @ 0x00508160
void calculateTorqueLimiterRamp(void);  // @ 0x005082b8
void processSensorBitmapConditions(void);  // @ 0x005082f0
void initTorqueLimitState(void);  // @ 0x00508490
void incrementDiagnosticCounters(int param_1,int param_2,int param_3);  // @ 0x005084e0
void processDiagnosticLimitStatus(void);  // @ 0x00508544
void resetFuelEfficiencyTrimState(void);  // @ 0x00508a94
void setFuelEfficiencyTrimFlag(void);  // @ 0x00508b8c
void clearBoostRequestFlag(void);  // @ 0x00508bb8
undefined4 evaluateBoundaryCondition(int param_1,int param_2,uint param_3);  // @ 0x00508bd0
void recordEventToBuffer(int param_1);  // @ 0x00508c10
void captureEventSnapshot(int param_1);  // @ 0x00508da8
void clearSensorChannelFaultBits(void);  // @ 0x00508de8
void updateSensorBitmapAndPointer(void);  // @ 0x00508e78
void calculateSubtractionWithProduct(void);  // @ 0x00508f0c
void handleEventCaptureAndSnapshot(void);  // @ 0x00508f24
void calculatePrimaryFuelAdjustment(void);  // @ 0x005091ec
void initFuelAdjustmentState(void);  // @ 0x005094c0
void evaluateDiagnosticLoadConditions(undefined2 param_1);  // @ 0x00509510
void copyBufferAndUpdateJ1939Addresses (int param_1,int param_2,int param_3,int param_4,uint param_5,int param_6);  // @ 0x00509848
undefined4 updateOutputControlMask(int param_1,int param_2);  // @ 0x00509894
undefined1 updateOutputControlMaskIndex4(undefined4 param_1);  // @ 0x00509990
undefined1 updateOutputControlMaskIndex5(undefined4 param_1);  // @ 0x005099b8
void registerOutputControlOperations(void);  // @ 0x005099e0
void emptyStub_noOp(void);  // @ 0x00509a2c
void clearBitmapFlag(uint param_1);  // @ 0x00509a44
void storeIndirectValue(undefined4 param_1,undefined4 *param_2);  // @ 0x00509a7c
void clearTertiaryBitmapFlag(uint param_1);  // @ 0x00509a84
void clearSecondaryBitmapFlag(uint param_1);  // @ 0x00509ac4
undefined2 isAnyPrimaryFlagSet(void);  // @ 0x00509b04
undefined2 checkTertiaryBitmapFlagStatus(void);  // @ 0x00509b44
int pollUntilConditionMet(int *param_1,short param_2,short param_3);  // @ 0x00509b5c
int searchArrayForNonZero(int param_1,short param_2,uint param_3);  // @ 0x00509b74
undefined2 isAnySecondaryFlagSet(void);  // @ 0x00509b84
void setBitmapFlag(uint param_1);  // @ 0x00509bc4
void setPrimaryBitmapFlag(uint param_1);  // @ 0x00509c00
void setSecondaryBitmapFlag(uint param_1);  // @ 0x00509c3c
void handleIdleSpeedControlFlag(void);  // @ 0x00509c78
void processBoostPressureOffset(void);  // @ 0x00509d78
void updateIdleControlStateAndBitmap(void);  // @ 0x00509e60
void detectEngineStateTransition(void);  // @ 0x00509f78
void evaluateIdleDiagCondition(uint param_1,uint param_2);  // @ 0x0050a14c
void evaluateIdleCondition(int param_1);  // @ 0x0050a228
void processIdleControlLoop(void);  // @ 0x0050a3ac
void resetIdleStateFlags(void);  // @ 0x0050a680
void idleDiagnosticProcessor(void);  // @ 0x0050a854
void idleControlMaster(void);  // @ 0x0050a9c8
void resetGovernorDiagnosticState(undefined2 *param_1);  // @ 0x0050aba8
undefined4 processServiceRequest(int param_1,undefined *param_2,uint param_3);  // @ 0x0050ac04
undefined4 validateServiceRequestAddress(void);  // @ 0x0050ad1c
undefined1 returnZeroStub(undefined4 param_1,undefined1 param_2);  // @ 0x0050ae4c
void emptyStub_reserved50ae5c(void);  // @ 0x0050ae5c
uint readParameterWithOffset(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4);  // @ 0x0050ae64
void emptyStub_phaseGroupA(void);  // @ 0x0050aec0
undefined1 readParameterByteOffset(int param_1);  // @ 0x0050aed4
undefined1 readParameterDwordOffset(int param_1);  // @ 0x0050af44
undefined1 readParameterWordOffset(int param_1);  // @ 0x0050afac
undefined1 readParameterDwordDualOffset(int param_1);  // @ 0x0050b038
undefined1 readParameterDwordImmediate(int param_1);  // @ 0x0050b0b4
undefined1 readParameterDwordImmediateDual(int param_1);  // @ 0x0050b120
void registerReadServiceHandlers(void);  // @ 0x0050b184
undefined4 byteSwap32(undefined4 *param_1);  // @ 0x0050b200
undefined2 byteSwap16(undefined2 *param_1);  // @ 0x0050b238
undefined1 getServiceDataLength(int param_1);  // @ 0x0050b2bc
undefined4 validateDiagnosticServiceRequest(int param_1);  // @ 0x0050b2e0
void processIdleControlStateUpdate(int param_1,undefined4 param_2,int param_3);  // @ 0x0050b554
void extractJ1939MessageFields(int param_1,uint param_2,int param_3);  // @ 0x0050b58c
void updateIdleStateVariables(int param_1,uint param_2,int param_3);  // @ 0x0050b5b4
void emptyStub_reserved50b634(void);  // @ 0x0050b634
void registerDiagnosticDataRecords(void);  // @ 0x0050ba78
void enqueueDiagnosticRecord(int param_1);  // @ 0x0050bb18
void initDiagnosticBuffer(int param_1);  // @ 0x0050bb98
void processDiagnosticStateChanges(void);  // @ 0x0050bca0
undefined4 prepareParameterResponseFrame(byte *param_1);  // @ 0x0050bfc4
undefined4 sendParameterCanResponse(void);  // @ 0x0050bff4
void registerWriteServiceHandlers(void);  // @ 0x0050c0ac
char processResponseFrame(byte *param_1,uint param_2,uint param_3);  // @ 0x0050c0d8
undefined1 writeParameterWithOffset(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4);  // @ 0x0050c27c
undefined1 writeParameterDwordOffset(int param_1);  // @ 0x0050c2ec
undefined1 writeParameterWordOffset(int param_1);  // @ 0x0050c354
undefined1 writeParameterDwordDualOffset(int param_1);  // @ 0x0050c3e0
undefined1 writeParameterDwordImmediate(int param_1);  // @ 0x0050c45c
undefined1 writeParameterDwordImmediateDual(int param_1);  // @ 0x0050c4c8
void registerWriteServiceDispatch(void);  // @ 0x0050c52c
void j1939TransportProtocolRequestHandler(uint *param_1);  // @ 0x0050c598
void j1939TransportContinueTransmit(void);  // @ 0x0050c640
void processJ1939DataBlock(int param_1);  // @ 0x0050c8c4
void validateJ1939PacketBounds(int param_1,int param_2,uint param_3,char *param_4);  // @ 0x0050c8ec
void sendJ1939StatusMessage(undefined1 param_1,undefined2 param_2);  // @ 0x0050c968
void j1939SendStatusMessage(undefined1 param_1,undefined2 param_2);  // @ 0x0050ca00
undefined1 prepareJ1939StatusData(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined2 param_4);  // @ 0x0050caa8
void j1939ProcessIncomingMessage(undefined4 *param_1);  // @ 0x0050cb3c
void j1939ProcessDataContinuation(int param_1);  // @ 0x0050cc54
void j1939ProcessAcknowledge(int param_1);  // @ 0x0050cdf0
void j1939ProcessAbort(int param_1);  // @ 0x0050ce58
void j1939DispatchMessageByType(int param_1);  // @ 0x0050cefc
void processTransmitBufferData(int param_1);  // @ 0x0050cf6c
void j1939TransmitDataFrames(void);  // @ 0x0050d0f0
void j1939DecrementTimeout(void);  // @ 0x0050d284
void j1939ProcessTransmitQueue(void);  // @ 0x0050d2b8
undefined * allocateDiagnosticBuffer(int param_1);  // @ 0x0050d334
void registerJ1939MessageHandlers(void);  // @ 0x0050d3ac
undefined1 getMemoryRegionAccessCode(uint param_1,int param_2);  // @ 0x0050d430
void filterGovernorState(void);  // @ 0x0050d510
void calculateGovernorSpeedFiltered (undefined4 param_1,undefined2 *param_2,undefined4 param_3,undefined2 param_4, ushort *param_5);  // @ 0x0050d60c
void calculateGovernorSpeedOutput(void);  // @ 0x0050d688
void captureCrankPositionState(void);  // @ 0x0050d728
void initiateGovernorMode(int param_1);  // @ 0x0050d758
void checkGovernorModeAndCaptureCrank(int param_1,undefined4 param_2,undefined2 *param_3);  // @ 0x0050d784
void interpolateSpeedParameter(void);  // @ 0x0050d854
void interpolateSpeedProtectionTable(void);  // @ 0x0050d864
void setOperationalModeState(int param_1);  // @ 0x0050da60
void storeOperationalModeValue(void);  // @ 0x0050daac
void calculateSpeedRatio(void);  // @ 0x0050db00
void calculateSpeedRatioComponent(void);  // @ 0x0050db88
void computeSpeedRatioLimit(void);  // @ 0x0050dba8
void calculateAlternateSpeedRatio(void);  // @ 0x0050dcac
void emptyStub_reserved50dd40(void);  // @ 0x0050dd40
void processFaultCountdownTimers(void);  // @ 0x0050dd4c
void processFaultCountdownTimer2(void);  // @ 0x0050de54
void processOperatingConditionFlags(void);  // @ 0x0050e000
void processFuelBlendFaultTimer(void);  // @ 0x0050e0a0
void clearSensorDiagnosticFlag(void);  // @ 0x0050e170
void checkFuelLimitCondition(void);  // @ 0x0050e1e0
void evaluateFaultStatusWord(void);  // @ 0x0050e2bc
void resetFaultStatusWord(void);  // @ 0x0050e414
void calculateFuelDemandScaling(void);  // @ 0x0050e4a0
void calculateFuelDemandScaleFactor(void);  // @ 0x0050e4c4
void calculateSpeedInterpolationResults(undefined4 param_1,undefined4 param_2,int param_3);  // @ 0x0050e610
void interpolateFuelDemandTable(void);  // @ 0x0050e754
void interpolateFuelDemandTable(void);  // @ 0x0050e768
void calculateSpeedInterpolationParams(void);  // @ 0x0050e7f4
void selectFuelDemandMode(void);  // @ 0x0050e938
void evaluateFuelModeSelection(void);  // @ 0x0050e970
void selectFuelModeOutputValue(int param_1,int param_2,uint param_3);  // @ 0x0050ea88
void selectFuelModeOutput(undefined4 param_1,int param_2);  // @ 0x0050eaa8
void processFuelModeSelection(void);  // @ 0x0050eaf0
void calculateFuelLimitAdjustment(void);  // @ 0x0050eb5c
void processFuelLimitAdjustments(ushort param_1);  // @ 0x0050ebf0
void updateFuelFilterCounters(ushort param_1);  // @ 0x0050ec08
void determineFuelLimitMode(void);  // @ 0x0050edbc
void calculateFuelFilterAndPeak(void);  // @ 0x0050ee24
void interpolateFuelLimitValues(void);  // @ 0x0050ee44
void processFuelFilterPeakOutput(void);  // @ 0x0050ee68
void adjustFuelParameter(void);  // @ 0x0050f060
void processFuelCalibration(void);  // @ 0x0050f16c
void initFuelConditionPointers(undefined4 param_1,undefined4 param_2,undefined4 *param_3);  // @ 0x0050f4c0
void evaluateFuelConditionDelta(void);  // @ 0x0050f4e0
void evaluateSpeedThresholdCondition(short param_1,undefined4 param_2,int param_3);  // @ 0x0050f680
void evaluateConditionPair(short param_1,undefined4 param_2,short param_3);  // @ 0x0050f6c4
void calculateFuelCounterState(void);  // @ 0x0050f728
void processFuelFaultMonitoring(void);  // @ 0x0050f8a4
void initializeFuelFaultVariables(void);  // @ 0x0050f938
void updateFaultCounterWithFlag(void);  // @ 0x0050f9ec
void calculateWeightedFuelParameter(void);  // @ 0x0050fb00
void calculateFuelStatusWithFilter(undefined4 param_1,ushort *param_2);  // @ 0x0050fbf8
void processFaultStatusThresholds(void);  // @ 0x0050fc8c
void calculateWeightedFuelValue(void);  // @ 0x0050fd38
void calculateFuelStatusParameters (undefined4 param_1,undefined4 param_2,int param_3,ushort *param_4,int *param_5, int param_6);  // @ 0x0050fe54
void filterAndAccumulatePressureSquared(void);  // @ 0x0050ff28
void evaluateSensorDeviationCondition(void);  // @ 0x00510058
void updateChannelProtectionCondition(void);  // @ 0x005101cc
void evaluateProtectionLatchState(void);  // @ 0x0051027c
void processProtectionEventConditions(void);  // @ 0x005102d4
void evaluateProtectionConditions(undefined4 param_1,short *param_2,int param_3);  // @ 0x005103ac
void updateChannelProtectionStatus(undefined4 param_1,undefined4 param_2,undefined2 param_3);  // @ 0x00510520
void clearSensorStatusFlags(void);  // @ 0x00510624
void auxSensorChannel26_init(void);  // @ 0x00510668
void auxSensorChannel26_process(void);  // @ 0x005106f4
void auxSensorChannel28_init(void);  // @ 0x00510780
void auxSensorChannel28_process(void);  // @ 0x0051080c
void auxSensorChannel29_init(void);  // @ 0x00510898
void auxSensorChannel29_process(void);  // @ 0x00510924
void auxSensor29_process(undefined4 param_1,undefined4 param_2,int param_3);  // @ 0x00510978
void crankshaftSensor_init(void);  // @ 0x005109b0
void crankshaftSensor_initB(void);  // @ 0x005109bc
void crankshaftSensor_process(void);  // @ 0x00510a3c
void crankshaftSensor_processB(void);  // @ 0x00510a48
void auxSensorChannel103_init(void);  // @ 0x00510ac8
void auxSensorChannel103_init(void);  // @ 0x00510ad4
void updateAuxSensorChannelState(void);  // @ 0x00510b54
void auxSensorChannel103_process(void);  // @ 0x00510b60
void initEventFlag26Handler(void);  // @ 0x00510be0
void initEventFlag26State(void);  // @ 0x00510bec
void processEventFlag26Logic(void);  // @ 0x00510c4c
void processEventFlag26Counter(void);  // @ 0x00510c78
void emptyStub_reserved510d04(void);  // @ 0x00510d04
void evaluateSpeedSyncCondition(void);  // @ 0x00510d24
void evaluateMultichannelDemandCondition(void);  // @ 0x00510d90
void evaluateSpeedSyncSystemState(void);  // @ 0x00510e1c
void evaluateMultichannelStateConditions (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5, undefined4 param_6,int param_7);  // @ 0x00510ea8
void processMultichannelRampRate (undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5);  // @ 0x00510f34
void processEventFlag26Dispatcher(void);  // @ 0x005115a4
void updateProtectionLockoutState(void);  // @ 0x005115e8
void updateEngineProtectionMode(void);  // @ 0x00511810
void processProtectionHysteresis(void);  // @ 0x005118f8
void updateProtectionHysteresisCounter(void);  // @ 0x0051193c
void setMultichannelStateTableEntry(void);  // @ 0x00511b64
void updateDiagnosticTorqueLimitState(void);  // @ 0x00511b80
void updateTransmissionTorqueControl(void);  // @ 0x00511ddc
void processDynamicControlState(void);  // @ 0x00511ea8
void processDynamicControlStateB(void);  // @ 0x00511ed4
void incrementDynamicControlCounter(void);  // @ 0x00512130
int protectionModeState2Handler(void);  // @ 0x005122a0
int evaluateEmissionCondition(void);  // @ 0x00512324
undefined4 selectStateCodeByCondition(void);  // @ 0x005123d0
void updateFilteredPressureValue(void);  // @ 0x00512408
void updatePressureDifferenceAccumulator(void);  // @ 0x00512484
int protectionModeState4Handler(void);  // @ 0x00512524
int storeDynamicStateValue(int param_1,short param_2);  // @ 0x00512554
int protectionModeState3Handler(void);  // @ 0x005125c8
int selectNextProtectionModeState(void);  // @ 0x0051265c
int evaluateProtectionModeState(int param_1,undefined4 param_2,undefined4 param_3,int param_4);  // @ 0x00512678
undefined4 checkProtectionModeConditions(void);  // @ 0x0051270c
undefined4 getProtectionControlMode(undefined4 param_1,int param_2);  // @ 0x005129b0
undefined4 detectEngineProtectionThreshold(void);  // @ 0x00512b1c
undefined4 selectAlternateStateCode(void);  // @ 0x00512bc4
void evaluateProtectionMainState(void);  // @ 0x00512ca0
void evaluateProtectionConditionFlags(void);  // @ 0x00512eac
void calculateProtectionIntegrator (short param_1,undefined2 *param_2,undefined2 *param_3,undefined2 *param_4, undefined2 *param_5,short *param_6,undefined2 param_7);  // @ 0x00512ff4
void accumulateGovernorThresholdCounts(void);  // @ 0x005130f4
void emptyStub_reserved513200(void);  // @ 0x00513200
void checkGovernorThresholdCrossing(void);  // @ 0x00513208
void monitorGovernorMultiChannelThresholds(void);  // @ 0x00513348
void setProtectionConditionFlags(void);  // @ 0x005134e8
void evaluateGovernorThresholds(void);  // @ 0x00513548
void calculateGovernorSpeedError(void);  // @ 0x0051356c
void calculateGovernorTorqueLimitAndMode(void);  // @ 0x005135a4
void interpolateGovernorModeLimit(void);  // @ 0x005136dc
void applyCrankPositionHysteresis(void);  // @ 0x00513790
void interpolateGovernorModeByIndex(void);  // @ 0x0051386c
void interpolateBoostPressureLimit(void);  // @ 0x005138f4
void initializeGovernorState(void);  // @ 0x005139f8
void evaluateGovernorMode(void);  // @ 0x00513b48
void updateEventFlagConditional(int param_1,int param_2,int param_3,int param_4);  // @ 0x00513c78
void updateEventFlag11Handler(void);  // @ 0x00513cf4
void updateEventFlag53(void);  // @ 0x00513ddc
void copyByteValuesToShorts(void);  // @ 0x00513f5c
void evaluateSpeedControlDiagnostics(void);  // @ 0x00513fe0
void processSpeedControlCalculation(void);  // @ 0x00514048
void processSpeedControlCalculationB(void);  // @ 0x00514108
void processSpeedControlCalculationC(void);  // @ 0x00514394
void calculateSpeedErrorAccumulator(void);  // @ 0x00514f5c
void evaluateSpeedControlActivationConditions(void);  // @ 0x0051524c
void applySpeedControlOutputLimits(void);  // @ 0x005154e8
void evaluateSpeedControlIntegration(void);  // @ 0x00515798
void initSpeedControlDiagnosticState(void);  // @ 0x005157c0
void evaluateSpeedCorrectionFactor(void);  // @ 0x00515964
void configureTimerChannelA(ushort *param_1);  // @ 0x00515bac
void configureTimerChannelB(ushort *param_1);  // @ 0x00515bd4
void validateSpeedCorrectionFlag(void);  // @ 0x00515d78
void initSpeedControlIntegratorState(void);  // @ 0x00515dac
void evaluateSpeedNormalizationFactor(void);  // @ 0x00515e60
void initOilPressureState(void);  // @ 0x00516014
undefined4 updateOilPressureFilter(void);  // @ 0x00516040
void resetOilPressureDebounce(void);  // @ 0x00516164
void updateOilPressureHysteresis(void);  // @ 0x0051617c
void processOilPressureHysteresis(undefined4 param_1,undefined4 param_2,int param_3);  // @ 0x005161c0
void updateOilPressureOutputFilter(void);  // @ 0x0051626c
void initOilPressureProtection (undefined2 *param_1,byte param_2,undefined4 param_3,int param_4,short param_5);  // @ 0x005162ec
void calculateOilPressureRate(void);  // @ 0x00516338
void resetOilPressureTimeout(void);  // @ 0x00516420
void processOilPressureIntegration(undefined4 param_1,ushort param_2,ushort param_3);  // @ 0x00516430
void resetProtectionRateLimit(void);  // @ 0x005165fc
void initOilPressureStateAndLimits(void);  // @ 0x0051660c
void updateProtectionRateLimitState(void);  // @ 0x00516680
void updateOilPressureCyclicProcess(void);  // @ 0x0051679c
void evaluateBoostPressureBlending(void);  // @ 0x00516804
void clearEventFlag36Handler(void);  // @ 0x005169e4
void initEventFlag54State(void);  // @ 0x00516a20
void initCoolantTemperatureProtectionState(void);  // @ 0x00516a48
void interpolateCoolantProtectionValue(void);  // @ 0x00516b88
void interpolateCoolantTable(void);  // @ 0x00516bb0
void activateCoolantProtectionEvents(void);  // @ 0x00516c18
void updateCoolantEventFlags(void);  // @ 0x00516d0c
void processCoolantEventTransition(void);  // @ 0x00516df8
void clearCoolantProtectionEvents(void);  // @ 0x00516e5c
void processCoolantProtectionEntry(void);  // @ 0x00516f58
void selectCoolantProtectionPath1(void);  // @ 0x0051714c
void selectCoolantProtectionPath2(void);  // @ 0x005171b4
void processProtectionStateTransition(void);  // @ 0x0051730c
void resetProtectionEventFlags(void);  // @ 0x00517648
void executeCoolantProtectionPhase4(void);  // @ 0x0051775c
void evaluateCoolantTemperatureTransition(void);  // @ 0x00517b34
void selectCoolantLoadReference(void);  // @ 0x00517f20
void selectCoolantProtectionReference(undefined4 param_1,int param_2);  // @ 0x00517f48
void updateCoolantTemperatureReference(void);  // @ 0x00517fa0
void processCoolantProtectionCycleState(void);  // @ 0x00518124
void evaluateTemperatureDiagnosticState(void);  // @ 0x0051826c
void processProtectionStateSwitch(void);  // @ 0x00518324
void switchD_005183b0::handleProtectionStateSwitchCase(void);  // @ 0x005183b4
void processDiagnosticModeFlags(void);  // @ 0x00518538
void unsignedDivisionWrap64(void);  // @ 0x005185b4
void convertTemperatureCelsiusToDisplayFormat(void);  // @ 0x005185dc
void divideEngineParameterBy61525(void);  // @ 0x0051862c
void updateControlModeAndBuffer(void);  // @ 0x00518668
void copyProtectionStateBuffer(void);  // @ 0x00518680
void wrapperCallControlMode(void);  // @ 0x005186a8
void convertTemperatureToScale(void);  // @ 0x005186cc
void convertSensorToPercentage(void);  // @ 0x0051871c
void clampAndConvertByteValue(void);  // @ 0x00518744
void useFixedConstantValue(void);  // @ 0x00518760
void convertDiscreteDigitalValue(void);  // @ 0x0051876c
void emptyCommandHandler(void);  // @ 0x00519318
void processDisplayCommandState(void);  // @ 0x0051931c
void processFaultListEntry (int param_1,undefined4 param_2,undefined4 param_3,short *param_4,byte *param_5, byte param_6,undefined4 param_7,int param_8,uint param_9);  // @ 0x005196f0
void processFaultListEntryB (int param_1,undefined4 param_2,byte *param_3,short *param_4,byte *param_5, undefined4 param_6,undefined4 param_7,int param_8,uint param_9);  // @ 0x0051972c
void initOilTemperatureEventFlag35(void);  // @ 0x00519870
void updateOilTemperatureDebounceState(void);  // @ 0x005198b0
void initOilTemperatureProtectionThreshold(void);  // @ 0x00519a18
void initOilTemperatureConditionState(void);  // @ 0x00519c04
void initOilTemperatureState(undefined2 param_1);  // @ 0x00519c64
void storeIndirectValueB(void);  // @ 0x00519c84
void evaluateOilTemperatureLoadCondition(void);  // @ 0x00519c94
void evaluateProtectionStepCondition(void);  // @ 0x00519cc4
void updateProtectionActiveFlag(void);  // @ 0x00519e2c
void processOilTempSensorRange(void);  // @ 0x0051a0a8
void evaluateOilTemperatureSensorDiagnostics(void);  // @ 0x0051a234
void evaluateEmissionControlAdjustment(void);  // @ 0x0051a464
void processEmissionControlState(void);  // @ 0x0051a648
void updateCalibrationPhaseCounter(void);  // @ 0x0051a75c
void updateCalibrationPhaseFlags(void);  // @ 0x0051a878
void evaluateThermalFailsafeConditions(undefined4 param_1);  // @ 0x0051aae4
void evaluateThermalPhaseConditions(undefined4 param_1);  // @ 0x0051ab50
void evaluateThermalPhaseConditionsB(undefined4 param_1);  // @ 0x0051ab70
void evaluateThermalInjectionTimingRange(void);  // @ 0x0051aecc
void monitorThermalProtectionState(undefined4 param_1,undefined4 param_2,undefined2 param_3);  // @ 0x0051aef8
void updateThermalLockoutTimer(void);  // @ 0x0051b158
void setProtectionInhibitFlag(undefined2 param_1);  // @ 0x0051b56c
undefined4 checkAndDispatchCommand(void);  // @ 0x0051b58c
void accumulateWithClamp(void);  // @ 0x0051b608
void computeClampedDelta(void);  // @ 0x0051b658
void evaluateExhaustTemperatureDiagnostics(void);  // @ 0x0051b6a8
void processComplexControlLoop(void);  // @ 0x0051b978
void processComplexControlLoopB(void);  // @ 0x0051babc
void updateProtectionModeAndDispatch(void);  // @ 0x0051bed0
void updateExhaustTemperatureProtectionMode(void);  // @ 0x0051bfc4
void clampProtectionLimit(uint param_1);  // @ 0x0051c278
void calculateWarmupProtectionLimit(void);  // @ 0x0051c2b4
void calculateWarmupProtectionLimitB(void);  // @ 0x0051c2d0
void calculateWarmupProtectionLimitC(void);  // @ 0x0051c3d8
void calculateDeltaWarmupCompensation(void);  // @ 0x0051c534
void processWarmupTimerDecrement(void);  // @ 0x0051c5dc
void updateWarmupProtectionMode(void);  // @ 0x0051c6c0
void initWarmupStateAndTimers(void);  // @ 0x0051c974
undefined * lookupParameterPointer(int param_1,int param_2);  // @ 0x0051ca00
undefined * selectDataPointerByBitFlag(undefined4 param_1,uint param_2);  // @ 0x0051cad4
undefined4 nullParameterHandler(void);  // @ 0x0051cb54
undefined4 getCommandParameterAddress(int param_1,uint param_2);  // @ 0x0051cb60
void dispatchByJumpTable(void);  // @ 0x0051cd88
int addWithMask16(int param_1,uint param_2);  // @ 0x0051d190
void getCommandAddressFromMemory(void);  // @ 0x0051d1a8
uint getActiveQueueFlags(void);  // @ 0x0051d1c8
undefined * lookupParameterByCommandAndOffset(int param_1,int param_2);  // @ 0x0051d224
void executeStateTransitionMode(void);  // @ 0x0051d2f8
void dispatchByCommandCode(void);  // @ 0x0051d36c
void initCommandDispatchMode(void);  // @ 0x0051d3fc
void processProtectionTimerState(void);  // @ 0x0051d42c
void processCommandQueueStep(void);  // @ 0x0051d458
void processCommandQueueStateMachine(void);  // @ 0x0051d58c
void initCommandQueueState(void);  // @ 0x0051d624
void resetModeState(void);  // @ 0x0051d644
void activateCommandQueueExecution(void);  // @ 0x0051d69c
void syncCfgValuesToEeprom(void);  // @ 0x0051d6f8
void syncDiagnosticsTemperatureToEeprom(void);  // @ 0x0051d70c
void initCommandDispatchExecution(void);  // @ 0x0051d7c0
void handleCommandDispatchMode(void);  // @ 0x0051d808
void handleCommandF5toF8(void);  // @ 0x0051d810
void dispatchByOffsetTable(void);  // @ 0x0051d840
void switchD_0051d848::handleCommand253State(void);  // @ 0x0051d86c
void wrapperProcessCommandQueue(void);  // @ 0x0051d8c8
undefined4 validateCommandState(void);  // @ 0x0051d958
undefined4 switchD_0051d994::emptyStateHandler(void);  // @ 0x0051d9a0
void commandStateHandler1(void);  // @ 0x0051d9c0
void commandStateHandler2(void);  // @ 0x0051d9d4
void commandStateHandler3(void);  // @ 0x0051d9dc
void commandStateHandler4(void);  // @ 0x0051d9fc
void commandStateHandler5(void);  // @ 0x0051da10
void commandStateHandler6(void);  // @ 0x0051da24
void commandStateHandler7(void);  // @ 0x0051da38
void resetStateAndDispatch(void);  // @ 0x0051da4c
void initiateCommandDispatch(byte *param_1);  // @ 0x0051da58
undefined4 switchD_0051d994::default(void);  // @ 0x0051da74
undefined4 executeQueuedCommand(void);  // @ 0x0051da7c
void processParameterTableLookup(void);  // @ 0x0051da94
void lookupAndDispatchCommand(int param_1);  // @ 0x0051dad4
void lookupCommandCodeFromTable(uint param_1,int param_2);  // @ 0x0051db0c
void clearFilterStateVariables(void);  // @ 0x0051db98
void buildStatusFlags(void);  // @ 0x0051dbc8
void packFaultCountersToWords(void);  // @ 0x0051dc34
void dispatchByCommandState(uint param_1,uint param_2);  // @ 0x0051dcb0
void dispatchCommand245(void);  // @ 0x0051df70
void dispatchCommand250(void);  // @ 0x0051df9c
void dispatchCommand251(void);  // @ 0x0051dfc8
void dispatchCommand252(void);  // @ 0x0051dff4
void dispatchCommand253(void);  // @ 0x0051e020
void initEventTimerProcessingMode(void);  // @ 0x0051e04c
void cancelEventTimer(short *param_1,int param_2);  // @ 0x0051e07c
void cancelAllEventTimers(void);  // @ 0x0051e100
void tickEventTimer(short *param_1,int param_2);  // @ 0x0051e210
void processEventTimerTick(void);  // @ 0x0051e2cc
void triggerDiagnosticEvent(short *param_1,undefined4 param_2,short param_3);  // @ 0x0051e480
void processEventTimerState(void);  // @ 0x0051e500
void initCommandExecutionMode(void);  // @ 0x0051eadc
char processCommandSwitch(void);  // @ 0x0051eb0c
void executeCommandByState(void);  // @ 0x0051eca4
void processCommandResponseReset(void);  // @ 0x005200e4
void decrementCountdownTimer(void);  // @ 0x00520208
void initCommandSequence(void);  // @ 0x00520240
void resetStateCounters(void);  // @ 0x00520270
void initializeCommandState(void);  // @ 0x005202b0
void initProcessDiagnosticStatus(void);  // @ 0x00520318
void processDiagnosticStatusPackage(void);  // @ 0x00520348
void initProcessResetCommand(void);  // @ 0x005206c4
void processResetCommand(void);  // @ 0x00520700
void initProcessEepromWrite(void);  // @ 0x005212e0
void processEepromWriteCommand(void);  // @ 0x0052131c
void initCommandAndDispatch(undefined4 param_1,undefined4 param_2,int param_3);  // @ 0x00521474
void initProcessParameterRead(void);  // @ 0x005214f4
void processParameterReadCommand(void);  // @ 0x00521530
void initWriteParameterByAddress(void);  // @ 0x0052164c
void writeParameterByLookup(void);  // @ 0x00521688
void processParameterWriteCommand(void);  // @ 0x005216cc
void initReadDiagnosticValue(void);  // @ 0x00521758
void readDiagnosticValue(void);  // @ 0x00521788
void processEngineSpeedResponse(void);  // @ 0x00521928
void initProcessChecksumValidation(void);  // @ 0x005219f0
void decrementTimeout(void);  // @ 0x00521a2c
void processChecksumValidation(void);  // @ 0x00521a54
void initProcessSecurityCommand(void);  // @ 0x00521c30
void completeCommandExecution(void);  // @ 0x00521c60
undefined1 writeEepromWithRetry(uint param_1,undefined4 param_2,int param_3);  // @ 0x00521ca0
void processSecurityCommand(void);  // @ 0x00521d44
void buildParameterValuePacket8(void);  // @ 0x00521e10
void buildParameterValuePacketAA(void);  // @ 0x00521f00
void initReadSensorChannelStatus(void);  // @ 0x00522018
undefined4 lookupParameterTableEntry(undefined2 *param_1,uint param_2);  // @ 0x00522054
undefined4 lookupSensorParameterEntry(undefined2 *param_1,uint param_2,int param_3,uint param_4);  // @ 0x00522074
bool checkSensorActiveStatus(uint param_1);  // @ 0x0052209c
void readSensorChannelStatus(void);  // @ 0x00522118
void validateResponseChecksum(void);  // @ 0x00522260
void updateEngineRunningCounter(void);  // @ 0x00522398
void updateSystemEnableFlag(void);  // @ 0x0052261c
void synchronizeEnableState(void);  // @ 0x0052269c
void updateDiagnosticStateWithFlag (int param_1,uint *param_2,undefined4 param_3,undefined2 *param_4,uint param_5);  // @ 0x00522700
void processOperatingStateTransition(void);  // @ 0x00522750
void conditionalSyncEnableState(void);  // @ 0x00522788
void evaluateOperatingStateConditions(undefined4 param_1,undefined4 param_2,undefined2 *param_3);  // @ 0x005227ac
void updateSystemEnableFlagConditional(void);  // @ 0x005229c0
void clearEnableStateBit10(void);  // @ 0x00522a04
void evaluateOperatingStateTransition(undefined4 param_1,undefined4 param_2,undefined2 *param_3);  // @ 0x00522b64
void updateEngineLoadDiagnostics(void);  // @ 0x00522d34
void updateProtectionErrorFiltered (undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4, uint param_5,undefined4 param_6,int *param_7);  // @ 0x00523068
void calculateProtectionCounterValue(void);  // @ 0x005230f4
void calculateEngineLoadProtection (undefined4 param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4, undefined2 *param_5,undefined2 *param_6);  // @ 0x00523148
void interpolateBoostPressureMap(void);  // @ 0x00523444
void updateEepromConfigBits(void);  // @ 0x005234f8
void toggleEepromDataSource(void);  // @ 0x00523688
void clearTorqueProtectionState(void);  // @ 0x00523748
void initFuelCorrectionState(void);  // @ 0x00523750
void initFuelCorrectionStateB(void);  // @ 0x00523760
char lookupByteFromTable(int param_1);  // @ 0x00523790
char lookupByteFromTableB(undefined4 param_1,uint param_2);  // @ 0x00523798
int computeByteChecksum(uint param_1,uint param_2);  // @ 0x005237b0
void computeAndStoreChecksum(void);  // @ 0x005237ec
void computeProtectionFuelLimit(undefined4 param_1);  // @ 0x00523858
uint generateChecksumWithSeed(void);  // @ 0x00523884
void initializeChecksumStorage(void);  // @ 0x00523924
void applyTorqueLimitProtection(void);  // @ 0x00523a74
void validateEepromDataIntegrity(void);  // @ 0x00523b4c
void processProtectionCounterToggle(void);  // @ 0x00523b5c
void processIdleSpeedControl(void);  // @ 0x00523f4c
void processStateTransitionLogic(void);  // @ 0x00523f60
void calculateFuelInjectionTiming(void);  // @ 0x00524180
void calculateTimingAdjustmentRegion(int param_1);  // @ 0x005242f8
void calculateProtectionAdjustment(undefined2 param_1);  // @ 0x00524360
void calculateProtectionAdjustmentB(int param_1,int param_2,int param_3);  // @ 0x00524594
void updateProtectionLimitsB(void);  // @ 0x005246b0
void updateProtectionLimits(void);  // @ 0x005246d8
void updateProtectionLimitsC(undefined2 *param_1);  // @ 0x005246e0
undefined2 calculateTimingPeriod(int param_1,int param_2);  // @ 0x00524858
void interpolateTableWrapper (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8);  // @ 0x00524920
uint calculateScaledValue(int param_1,uint param_2,uint param_3);  // @ 0x005249bc
void updateFuelDemandCalculation(void);  // @ 0x005249e0
void calculateTimingAdvanceRate(void);  // @ 0x00524cac
int calculateTimingCorrection(void);  // @ 0x00524d20
void initializeTimingState(void);  // @ 0x00524dd0
void initializeTimingStateB(int param_1);  // @ 0x00524df4
void updateInjectionTiming(void);  // @ 0x005250f0
void updateInjectionTimingB(void);  // @ 0x005251e4
void updateInjectionTimingC(void);  // @ 0x00525504
void processGovernorSpeedLimit(void);  // @ 0x00525a40
void processGovernorSpeedLimitB(void);  // @ 0x00525de4
void processGovernorSpeedLimitC(void);  // @ 0x00525e54
void calculateEngineSpeedLimitTorque(void);  // @ 0x00526000
void evaluateSpeedDerateConditions(void);  // @ 0x0052614c
void updateSpeedBandConditions(void);  // @ 0x005262e8
void updateSpeedBandConditionsB(void);  // @ 0x005263a8
void processSpeedWindowComparison(void);  // @ 0x005263e0
void processSpeedWindowComparisonB(void);  // @ 0x00526414
void processSpeedWindowComparisonC(void);  // @ 0x005264d4
void setBoostDiagnosticFlag(void);  // @ 0x00526510
void processTurboBoostDataB(void);  // @ 0x00526560
void processTurboBoostData(void);  // @ 0x005265ac
void processTurboBoostDiagnostic (undefined4 param_1,ushort *param_2,undefined2 *param_3,ushort *param_4);  // @ 0x005266fc
void clearBoostDiagnosticFlag(void);  // @ 0x005267b4
void clearTurboSensorFaultStatus(void);  // @ 0x005267e0
void clearSensorBitmapOnRun(void);  // @ 0x005267f4
void updateEngineSpeedGainCalculation(void);  // @ 0x0052686c
void calculateTimingTrimOffset(void);  // @ 0x005268d0
void processTpuVoltageChannel(void);  // @ 0x005268e8
void processVariableTimingControl(void);  // @ 0x00526c3c
void clearHardwareRegisterBits(void);  // @ 0x00526c80
void initHardwareRegisterSet2(void);  // @ 0x00526cb8
void updatehpcr_CbdDiagnosticState(void);  // @ 0x00526f08
void updatehpcr_CbdDiagnosticStateB (int param_1,undefined4 param_2,short param_3,char param_4,uint param_5);  // @ 0x00527050
void accumulateTimingOffset(void);  // @ 0x00527524
void evaluateTimingModifiers(void);  // @ 0x005275c4
void signedDivision64Wrapper(void);  // @ 0x00527860
void interpolateCbdTable4Point (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);  // @ 0x005278ac
void interpolateWithIndexWrapper(void);  // @ 0x00527958
void interpolateConditionalByMode(void);  // @ 0x0052796c
void interpolateConditionalByMode2(short param_1);  // @ 0x005279d8
void interpolatehpcr_CbdTable(void);  // @ 0x00527c90
void updateVehicleSpeedFilter(void);  // @ 0x00527fbc
void hpcr_initAndProcessCbdState(undefined4 param_1,undefined1 *param_2);  // @ 0x0052801c
void calculatehpcr_CbdAngleOffset(int param_1,int param_2,undefined2 param_3,int param_4);  // @ 0x005280f4
void applyhpcr_CbdCylinderTiming(int param_1);  // @ 0x00528368
void initRamVariable48(void);  // @ 0x00528474
void systemHalt(void);  // @ 0x00528564
void setUpLookupTableAndInterpolate(void);  // @ 0x005285c0
void processThrottlePosition(void);  // @ 0x0052877c
void initHardwareRegisters(void);  // @ 0x005289d4
void initThrottleDiagnosticState(void);  // @ 0x00528b90
void calculateLoadBasedFuelTrim(void);  // @ 0x00528c28
void computehpcr_CbdAngleCorrection(void);  // @ 0x00528e70
void hpcr_adjustCbdAngleForProtection (undefined4 param_1,undefined4 param_2,uint param_3,ushort param_4,undefined4 param_5 ,char *param_6);  // @ 0x0052903c
void hpcr_adjustCbdAngleParams (undefined4 param_1,undefined4 param_2,int param_3,ushort param_4,char param_5, char *param_6);  // @ 0x00529068
void updateTemperatureSensorFilter(void);  // @ 0x0052922c
void processhpcr_CbdStateMachine(void);  // @ 0x00529580
void computehpcr_CbdProtectionAngle(void);  // @ 0x00529908
void initializePressureParams(undefined4 param_1,byte *param_2,byte *param_3);  // @ 0x00529994
void processRailPressureControl(void);  // @ 0x00529b44
void interpolateConditional4Point(void);  // @ 0x00529d1c
void interpolate7PointTable(undefined4 param_1);  // @ 0x00529ea4
void interpolateDiagnosticTable4Point(void);  // @ 0x00529f58
void evaluatePressureLimitConditions(void);  // @ 0x0052a598
void interpolate4PointTable(undefined4 param_1,undefined4 param_2);  // @ 0x0052a910
void interpolateFuelMapBySpeed(void);  // @ 0x0052b2e8
void interpolateFuelMapBySpeedB(void);  // @ 0x0052b998
void interpolateFuelMapBySpeedC(void);  // @ 0x0052ba30
void updateFaultMonitorCounter(void);  // @ 0x0052bca8
void processAdaptiveLoadControl(void);  // @ 0x0052bf74
void evaluateSystemConditions(void);  // @ 0x0052c08c
void evaluateFaultCodeBoundary(void);  // @ 0x0052c210
void updateFaultMonitorState(void);  // @ 0x0052c688
void updateFaultFlagStatus(void);  // @ 0x0052c8cc
void calculateDiagnosticAccumulator(void);  // @ 0x0052c97c
void updateDiagnosticCounter(void);  // @ 0x0052ce04
void updateBoostDeviationAccumulator(void);  // @ 0x0052d140
void updateSpeedReferenceAccumulator(void);  // @ 0x0052d358
void updateProtectionAccumulator(void);  // @ 0x0052d40c
void evaluateDiagnosticModeTransition(void);  // @ 0x0052d514
void processProtectionEngage(void);  // @ 0x0052d650
void evaluateProtectionStateMachine(void);  // @ 0x0052d6a8
void validateCalibrationType(void);  // @ 0x0052daf8
void enqueueNullDataRecord(void);  // @ 0x0052db98
undefined4 enqueueConditionalRecord(void);  // @ 0x0052dcd0
void evaluateSpeedDelta(void);  // @ 0x0052ddb8
void setModeBySpeedComparison(byte param_1,int param_2,uint param_3);  // @ 0x0052de14
undefined4 processSpeedState(void);  // @ 0x0052de94
undefined4 calculateSpeedDerivative(void);  // @ 0x0052dfb0
undefined4 updateSpeedFilters(void);  // @ 0x0052e13c
void setModeAndEnqueueOperation(void);  // @ 0x0052e24c
undefined4 setModeIfFlagSet(void);  // @ 0x0052e29c
undefined4 initSpeedControlState(void);  // @ 0x0052e2d8
void resetSpeedAccumulators(void);  // @ 0x0052e404
undefined4 validateSpeedThresholds(int param_1);  // @ 0x0052e4a0
void prepareStateTransition(int param_1,undefined2 param_2);  // @ 0x0052e4fc
void triggerStateTransitionEvent(ushort param_1);  // @ 0x0052e540
int updatePerformanceMetric(void);  // @ 0x0052e59c
void setOperationalModeByCondition(int param_1);  // @ 0x0052eac8
void setMode2AndEnqueueState(void);  // @ 0x0052eae8
int processProtectionEvent(void);  // @ 0x0052eb30
void evaluateSystemHealthStatus(void);  // @ 0x0052ebc4
void processTimerRecoverySequence(void);  // @ 0x0052ee00
undefined4 validateProtectionStateFlags(void);  // @ 0x0052eedc
void evaluateProtectionDiagnosticState(void);  // @ 0x0052ef90
void updateTimerEventCounter(void);  // @ 0x0052f144
void calculateLimitFactorAdjustment(void);  // @ 0x0052f1b4
void evaluateSafetyConditions(void);  // @ 0x0052f524
void computeAccumulatorProduct(void);  // @ 0x0052f7bc
void checkEngineLimitConditions(void);  // @ 0x0052f870
void processTransmissionStatus(void);  // @ 0x0052fd4c
void validateCommandSequence(void);  // @ 0x0052fed8
void initCommandValidationState (short *param_1,int param_2,undefined4 param_3,short param_4,undefined4 param_5, int param_6,undefined4 param_7,short *param_8);  // @ 0x0053005c
void updateAuxiliaryOutputPort(void);  // @ 0x00530214
void updateSpeedSensorOutputFlag(void);  // @ 0x00530288
void updateSpeedSensorRangeFlag(void);  // @ 0x00530298
void updateSeverityFlags(void);  // @ 0x00530364
void setEngineOperatingFlag(void);  // @ 0x00530428
void processControlModeSwitching(void);  // @ 0x00530468
void buildEngineStatusFlags(void);  // @ 0x005305dc
void buildEngineStatusFlags2(void);  // @ 0x0053064c
void clearOutputCounters(void);  // @ 0x00530878
void evaluateOperatingModeStatus(void);  // @ 0x0053089c
void updateSystemEnableCounter(void);  // @ 0x00530968
void updateDiagnosticStateTimer(void);  // @ 0x00530d70
undefined4 checkProtectionBypassConditions(void);  // @ 0x00530e94
void processDataRecordCapture(void);  // @ 0x00530f80
void initProtectionRampCounter (undefined4 param_1,short *param_2,undefined4 param_3,undefined2 *param_4, undefined2 *param_5);  // @ 0x005311e4
void validateProtectionRampBounds (int param_1,int param_2,int param_3,undefined2 *param_4,undefined2 *param_5);  // @ 0x00531370
void resethpcr_CbdCylinderState(void);  // @ 0x0053164c
void hpcr_initCbdToothState(void);  // @ 0x0053168c
void hpcr_initCbdCylinderArray(void);  // @ 0x005316ac
void calculateFaultDetectionThreshold(void);  // @ 0x00531710
void evaluateActiveFaultConditions(void);  // @ 0x005317a4
void evaluateProtectionEnableCondition(void);  // @ 0x005318e8
void evaluateProtectionConditionFlag(void);  // @ 0x00531900
void countActivehpcr_CbdCylinders(void);  // @ 0x0053195c
void updatehpcr_CbdCylinderTiming(void);  // @ 0x005319e0
void updateSystemDiagnosticData(void);  // @ 0x00531b14
void hpcr_checkCbdResetConditions(void);  // @ 0x00531cf8
void hpcr_checkAndResetCbdState(void);  // @ 0x00531d34
void hpcr_cbdCylinderStateHandler(void);  // @ 0x00531f90
void advancehpcr_CbdFaultState(void);  // @ 0x00531fe8
void evaluatehpcr_CbdCylinderActivation(void);  // @ 0x00532108
void activatehpcr_CbdCylinderMode(void);  // @ 0x005321c8
void hpcr_updateCbdCylinderStatusBitmap(void);  // @ 0x00532208
void hpcr_updateSensorStatusBitmap(void);  // @ 0x0053227c
void deactivatehpcr_CbdCylinderMode(void);  // @ 0x0053236c
void deactivatehpcr_CbdCylinderModeB(ushort *param_1);  // @ 0x00532418
void compareAndSyncFaultFlags(void);  // @ 0x0053247c
void switchD_00531be4::default(void);  // @ 0x00532630
void resetFaultRecordFlags(int param_1);  // @ 0x00532654
void incrementFaultCounters(void);  // @ 0x00532680
void shiftFaultCounters(uint param_1);  // @ 0x005326c4
void resetFaultTimers(void);  // @ 0x005326fc
void removeFromActiveQueue(int param_1);  // @ 0x0053272c
void findFaultByCode(uint param_1);  // @ 0x005327e8
void processDataRecordDispatch(void);  // @ 0x00532a64
void updateFaultQueueState(void);  // @ 0x00532b78
void iterateAndResetFaultFlags(void);  // @ 0x00532ba8
void processFaultQueueEntry(void);  // @ 0x00532d10
undefined4 validateFreezeFrameConditions(uint param_1);  // @ 0x00532db8
void evaluateCalibrationChecksum(void);  // @ 0x00532e90
void scanFaultsForFreezeFrameConditions(void);  // @ 0x00532fac
void processFaultTableEntry(void);  // @ 0x0053307c
void updateMemoryAllocationState(void);  // @ 0x00533098
uint getFaultFlagByCode(uint param_1);  // @ 0x005331ec
void updateFaultTableEntry(int param_1);  // @ 0x00533250
void processEnvironmentalLimits(void);  // @ 0x005332a4
void clearFaultEntryFromList(uint param_1);  // @ 0x005333f8
void calculateOffsetCompensation(void);  // @ 0x005334fc
void setFaultActiveBit(uint param_1);  // @ 0x0053364c
void captureFaultSnapshot(uint param_1);  // @ 0x005336d0
void scanFaultTable(int param_1);  // @ 0x005337d4
void updateCylinderQueueSelection (uint param_1,int param_2,uint param_3,int param_4,int param_5,undefined4 *param_6, int param_7);  // @ 0x00533aec
void updateSensorInputValidation(int param_1,uint param_2);  // @ 0x00533b18
void setFaultTimestampFlags(ushort *param_1);  // @ 0x00533bc4
void setFaultActiveBitmapEntry(ushort param_1);  // @ 0x00533c80
void processStateTransitionGuard(void);  // @ 0x00533cc4
void evaluateTemperatureSlope(void);  // @ 0x00533dd8
void updateFaultBitmapFromStateGuards(uint param_1,uint param_2,uint param_3);  // @ 0x00533df0
void iterateFaultStatusRecords (ushort param_1,ushort param_2,int param_3,int param_4,uint param_5,ushort *param_6);  // @ 0x00533efc
void evaluateFaultConditions(void);  // @ 0x00533f30
void checkFaultCounterThreshold(void);  // @ 0x00534328
void processFaultLampLogic(void);  // @ 0x005343d0
void checkFaultStateTransition(void);  // @ 0x005344cc
void evaluateFuelDemandFaultCondition (ushort *param_1,int param_2,undefined4 param_3,undefined4 param_4,ushort *param_5);  // @ 0x00534530
void updateFaultCounter(void);  // @ 0x005346c0
void evaluateFaultTimingThreshold (undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5, int param_6);  // @ 0x0053473c
void processChannelDiagnostics (int param_1,char *param_2,char *param_3,char *param_4,char *param_5,uint *param_6, short *param_7,byte *param_8,int param_9,uint param_10,uint param_11,uint param_12, int param_13,uint param_14,uint param_15,short *param_16,short *param_17, ushort *param_18,ushort *param_19,int param_20,uint param_21);  // @ 0x0053489c
void evaluateInjectionTimingStability (int param_1,char *param_2,undefined4 param_3,int param_4,undefined4 param_5, int param_6,undefined4 param_7,uint param_8);  // @ 0x00534994
void evaluateSensorChannelStateMatch(void);  // @ 0x00534b68
void synchronizeDiagnosticFlagState(undefined4 param_1,int param_2);  // @ 0x00534c6c
void calculateLoadFactorDynamic(void);  // @ 0x00534db4
void hpcr_processMultiChannelDiagnostics(void);  // @ 0x00534fb0
void incrementCounterOrSetWarmup(void);  // @ 0x0053515c
void updateSystemConditionMetric(void);  // @ 0x00535208
void storeRegisterValue(void);  // @ 0x00535270
void processOutputControlSequence(void);  // @ 0x00535324
void evaluateOutputControlConditions(int param_1);  // @ 0x00535344
void handleEnableStateTransition(void);  // @ 0x00535408
void evaluateTimingAdvanceLimits(void);  // @ 0x005354c0
void clearFaultAccumulator(void);  // @ 0x00535998
void updateFilteredRpmValue(void);  // @ 0x005359b4
void processFuelingRateControl(void);  // @ 0x00535d5c
void calculateDiagnosticThresholdLevel(void);  // @ 0x00535e2c
void updateOutputDriverControl(void);  // @ 0x005360ec
void linearInterpolate1DWrapper(void);  // @ 0x0053624c
void processProtectionRecoveryState(void);  // @ 0x00536540
void buildStatusBitmaskFromTable(void);  // @ 0x00536638
void buildStatusBitmaskSecondary (int param_1,int param_2,ushort *param_3,undefined4 param_4,undefined4 param_5, uint param_6);  // @ 0x0053664c
void buildStatusBitmaskFromPointer (int param_1,int param_2,ushort *param_3,undefined4 param_4,undefined4 param_5, uint param_6);  // @ 0x0053665c
undefined4 getDiagnosticStatus(int param_1);  // @ 0x005366b8
void validateCalibrationLookup (uint param_1,uint param_2,uint param_3,uint param_4,byte *param_5,byte *param_6, byte *param_7,byte *param_8,ushort *param_9);  // @ 0x005367cc
void resetStateVariable(void);  // @ 0x00536958
void evaluateBoostControlAuthority(void);  // @ 0x00536de0
void processBoostDiagnosticFlags(void);  // @ 0x00536e4c
void validateCalibrationParameters(void);  // @ 0x005371f4
void emptyStub_boostControl(void);  // @ 0x0053729c
void updatePressureControlTarget(void);  // @ 0x005372b0
void initPressureControlVariables(void);  // @ 0x005372c4
void initDataBufferPointers(void);  // @ 0x0053752c
void initServiceRequestState (undefined4 param_1,undefined4 param_2,uint *param_3,uint param_4,uint param_5);  // @ 0x00537584
void calculateFuelingMassFlowRate(void);  // @ 0x005375ec
undefined4 enqueueDataRecord(int param_1,undefined2 param_2,int param_3,int param_4,undefined4 param_5);  // @ 0x005377f4
void processProtectionDiagnosticState(void);  // @ 0x005378a4
void executeTimerCallbacks(void);  // @ 0x00537944
void iterateAndExecuteTimerEntries(void);  // @ 0x005379b4
void executeTimerCallbacksViaLR(void);  // @ 0x005379d8
bool enqueueToBuffer17(undefined2 param_1,undefined4 param_2);  // @ 0x00537a18
void updateProtectionLimitFilter(void);  // @ 0x00537a5c
void processJ1939MessageWithFilter(void);  // @ 0x00537acc
void initDiagnosticBufferPointers(void);  // @ 0x00537cf8
void buildBitmapAndSetHwFlag (undefined4 param_1,undefined4 param_2,ushort *param_3,undefined4 param_4, undefined4 param_5,ushort *param_6);  // @ 0x00538278
undefined4 resolveParameterAddress(uint param_1,uint *param_2);  // @ 0x005382d0
void calculatePressureDropOffset(void);  // @ 0x005383d0
void pushToCircularBuffer(void);  // @ 0x005384a0
void processBufferSequence(void);  // @ 0x005385e0
void enqueueToCircularBufferWrapper(void);  // @ 0x00538748
void evaluateFlowRateCondition(void);  // @ 0x00538880
void synchronizeTimebase(void);  // @ 0x00538974
void updateEmissionControlParameter(void);  // @ 0x00538c78
void dispatchFaultTimerHandlers(void);  // @ 0x00538d3c
void dataTable_00538eac(void);  // @ 0x00538eac
void registerJ1939PgnHandler(void);  // @ 0x00538eb0
void dataTable_00538ef4(void);  // @ 0x00538ef4
void dataTable_00539768(void);  // @ 0x00539768
void dataTable_00539868(void);  // @ 0x00539868
void dataTable_00539d18(void);  // @ 0x00539d18
void dataTable_0053a110(void);  // @ 0x0053a110
