"""Check that proposed names are free in both firmwares' function_renames.csv / deleted_functions.csv /
global_variables.csv (case-insensitive), except on the row being renamed."""
import csv

F = "/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/"
functions = {
    "cm550": [
        (0x143b6, "calculateJ1939PercentPeakTorquePoints"),
        (0x1c640, "updateFourDimensionalFueling"),
        (0x19ac2, "cm550_initializeSpeedMeasurementForConfiguration0"),
        (0x1b39a, "mc68k_initializeTpuChannel1SpeedMeasurementResetInput"),
        (0x1af32, "mc68k_tpuChannel1CylinderIdentificationPulseInterruptHandler"),
        (0x1a6e8, "mc68k_tpuChannel0MissingToothSyncErrorInterruptHandlerMode2"),
        (0x17a8e, "cm550_calculateCrankInitialFuelByCoolantTemperature"),
        (0x17b8a, "selectCrankExitSpeed"),
        (0xfa06, "setJ1939TorqueCurvePoint1AtDeratedIdleFueling"),
        (0xfb26, "cm550_updateJ1939EngineConfigurationTorqueCurve"),
        (0x23be8, "cm550_checkLampDriverOutputFaults"),
        (0x15f8c, "cm550_emptyDiscreteInputSamplingStep"),
        (0x19aca, "cm550_emptyEnginePositionSignalConfiguration0ThirdStep"),
        (0x26852, "cm550_emptySerialEepromDriverInitializationFirstStep"),
        (0x30b0e, "cm550_emptyStartupStepAfterSchedulerInitialization"),
        (0x26b82, "cm550_emptyStartupStepAfterLowSpeedGovernorIdleAdjustment"),
    ],
    "cm848": [
        (0x1820c, "calculateJ1939PercentPeakTorquePoints"),
        (0x1e830, "updateFourDimensionalFueling"),
        (0x1bd44, "selectCrankExitSpeed"),
        (0x20b84, "setJ1939TorqueCurvePoint1AtDeratedIdleFueling"),
        (0x54220, "cm848_emptyStartupStepAfterDataCollectorReset"),
        (0x1806c, "cm848_emptyStartupStepAfterCoolantTemperatureSource"),
        (0x26f7c, "cm848_emptyNonJ1939CanReceiveInterruptHook"),
        (0x2c0fc, "cm848_emptyVariableSpeedGovernorSelectionStep"),
        (0x55e9c, "cm848_emptyTpuChannelInterruptHandler"),
        (0x42bd0, "hpcr_fillCylinderBalanceAccelerationBuffers"),
        (0x42d78, "hpcr_calculateCylinderBalanceTrims"),
        (0x43a5c, "hpcr_initializeCylinderBalancing"),
        (0x1d9b8, "cm848_runFaultHandler"),
    ],
}
globals_ = {
    "cm550": [
        (0x8002ac, "cylinder_balance_reference_projections"),
        (0x80a982, "variable_speed_governor_selected_flag"),
        (0x80db04, "low_speed_governor_cold_idle_reference_speed"),
        (0x80d2c2, "cylinder_identification_pulse_timeout_counter"),
        (0x803f8a, "crank_exit_speed_switch_cal"),
        (0x80d0a6, "crank_initial_fuel"),
        (0x807eea, "crank_exit_rpm"),
    ],
    "cm848": [
        (0x408ef6, "cylinder_balance_enable_flag"),
    ],
}


def rows(path):
    out = []
    for row in csv.reader(open(path, errors="replace")):
        if row and row[0].startswith("0x"):
            out.append((int(row[0], 16), row[1]))
    return out


for fw, props in functions.items():
    existing = rows(F + fw + "/function_renames.csv") + rows(F + fw + "/deleted_functions.csv")
    for addr, name in props:
        hits = [(a, n) for a, n in existing if n.lower() == name.lower() and a != addr]
        print(f"{fw} function 0x{addr:x} {name}: {'CLASH ' + str([(hex(a), n) for a, n in hits]) if hits else 'free'}")
for fw, props in globals_.items():
    existing = rows(F + fw + "/global_variables.csv")
    for addr, name in props:
        hits = [(a, n) for a, n in existing if n.lower() == name.lower() and a != addr]
        print(f"{fw} global 0x{addr:x} {name}: {'CLASH ' + str([(hex(a), n) for a, n in hits]) if hits else 'free'}")
# duplicate proposals inside a firmware
for fw, props in functions.items():
    names = [n.lower() for _, n in props]
    dups = {n for n in names if names.count(n) > 1}
    if dups:
        print("duplicate proposals", fw, dups)
