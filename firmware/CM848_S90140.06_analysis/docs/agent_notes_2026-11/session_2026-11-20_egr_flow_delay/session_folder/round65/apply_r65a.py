"""Round 65 stage A - 37 of the 38 unprefixed CM848-only functions named from their code (+ cm848_countdown_timer_update),
3 globals. initGovernorFlagsAux stays: it only clears the word at 0x3fcfba (between distance_sensor_fault_count and
injected_fuel_remainder in the trip counter block), nothing else is found reading it, and "governor" has no evidence.
A plate of None keeps the function's current plate (a prefix / spelling rename). Idempotent.
usage: apply_r65a.py <repo> <map.csv>"""
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 65"
REG = "Registered with cm848_registerJ1939ReceiveHandler"
FUNCS = [
    # the application's J1939 transport
    ("initiateJ1939TransportProtocol", "cm848_startJ1939TransportSession",
     "Starts sending a message over 8 bytes with the J1939 transport protocol: to one destination (PDU format below "
     "0xf0 and a destination other than 0xff) it opens j1939_transport_transmit_session for a request-to-send / "
     "clear-to-send exchange while j1939_multiframe_tx_active is 0 - else a broadcast session "
     "(j1939_broadcast_transmit_session_t)"),
    ("j1939_transport_timeout_decrement", "cm848_tickJ1939TransportReceiveTimeout",
     "Counts j1939_transport_receive_session.timeout_timer down and closes the receive session (active 0) at 0"),
    ("j1939_transport_handleClearToSend", "cm848_handleJ1939TransportClearToSend", None),
    ("j1939_transport_sendAbort", "cm848_sendJ1939TransportAbort", None),
    ("j1939_transport_sendEndOfMessageAcknowledge", "cm848_sendJ1939TransportEndOfMessageAcknowledge", None),
    ("j1939_transport_sendClearToSend", "cm848_sendJ1939TransportClearToSend", None),
    ("j1939_transport_handleRequestToSend", "cm848_handleJ1939TransportRequestToSend", None),
    ("j1939_transport_handleDataPacket", "cm848_handleJ1939TransportDataPacket", None),
    ("j1939_transport_handleEndOfMessageAcknowledge", "cm848_handleJ1939TransportEndOfMessageAcknowledge", None),
    ("j1939_transport_handleAbort", "cm848_handleJ1939TransportAbort", None),
    ("j1939_transport_dispatchConnectionManagement", "cm848_dispatchJ1939TransportConnectionManagement", None),
    # the J1939 receive handlers (PGN names from the local J1939 database) and their registrar
    ("j1939_receivePgn56576Handler", "cm848_receivePgn56576AntiTheftRequestMessage",
     "J1939 PGN 56576 Anti-theft Request (ATR): with algorithm_enable_flags_27_cal.anti_theft_enable set and no "
     "status reply pending it records the addresses for the PGN 56320 Anti-theft Status reply / unpacks the command "
     "state / desired exit mode / encryption indicator and the password bytes / sets "
     f"j1939_anti_theft_status_transmit_state 2. {REG}"),
    ("j1939_receivePgn57344Handler", "cm848_receivePgn57344CabMessage1",
     "J1939 PGN 57344 Cab Message 1 (CM1): byte 1 (the requested percent fan speed) into "
     "j1939_received_engine_fan_requested_percent_speed when the source passes j1939_input_source_address_filter_cal "
     f"slot 0 (signal timeout 500). {REG}"),
    ("j1939_receivePgn61441Handler", "cm848_receivePgn61441ElectronicBrakeController1Message",
     f"J1939 PGN 61441 Electronic Brake Controller 1 (EBC1): unpacks its signals for the sources that pass "
     f"j1939_input_source_address_filter_cal. {REG}"),
    ("j1939_receivePgn61443Handler", "cm848_receivePgn61443ElectronicEngineController2Message",
     f"J1939 PGN 61443 Electronic Engine Controller 2 (EEC2): unpacks its signals for the sources that pass "
     f"j1939_input_source_address_filter_cal. {REG}"),
    ("j1939_receivePgn65252Handler", "cm848_receivePgn65252ShutdownMessage",
     "J1939 PGN 65252 Shutdown (SHUTDN): byte 3 bits 1-2 (the A/C high pressure fan switch) into "
     "j1939_received_air_conditioner_high_pressure_fan_switch when the source passes "
     f"j1939_input_source_address_filter_cal slot 10 (signal timeout 500). {REG}"),
    ("j1939_receivePgn65264Handler", "cm848_receivePgn65264PowerTakeoffInformationMessage",
     "J1939 PGN 65264 Power Takeoff Information (PTO): the remote PTO / PTO on / resume / set switches for the sources "
     f"that pass j1939_input_source_address_filter_cal slots 11-14 (signal timeout 50). {REG}"),
    ("j1939_receivePgn65265Handler", "cm848_receivePgn65265CruiseControlVehicleSpeedMessage",
     f"J1939 PGN 65265 Cruise Control/Vehicle Speed 1 (CCVS1): unpacks its signals for the sources that pass "
     f"j1939_input_source_address_filter_cal. {REG}"),
    ("j1939_handlerInitializer", "cm848_registerJ1939ReceiveHandler",
     "Appends a PGN and its handler to the J1939 receive handler table at 0x3fd414 (6-byte entries - at most 17; the "
     "count is j1939_receive_handler_count) that cm848_dispatchJ1939ReceivedMessages searches. Returns true when "
     "full. The receive side twin of cm848_j1939RegisterDiagnosticService"),
    # J1939 utilities and two misnamed schedulers
    ("sendJ1939Message", "cm848_sendJ1939Message", None),
    ("j1939_reverseByteOrder32", "cm848_reverseByteOrder32",
     "Returns the dword at the pointer with its bytes reversed - the J1939 byte order for a message builder "
     "(caller: cm848_j1939HandlePgn65248VehicleDistance)"),
    ("j1939_reverseByteOrder16", "cm848_reverseByteOrder16",
     "Returns the word at the pointer with its bytes reversed - the J1939 byte order for the 8 message builders that "
     "call it"),
    ("j1939_buildLampStatusByte", "cm848_buildJ1939LampStatusByte",
     "The DM1 / DM2 lamp status byte: 0x40 malfunction indicator (mil_on_request_flag) / 0x10 red stop "
     "(stop_fault_lamp_flag) / 0x04 amber warning (warning_fault_lamp_flag) / 0x01 protect "
     "(maintenance_fault_lamp_flag)"),
    ("j1939_periodic_processing", "cm848_runCoolingFanControl",
     "One cooling fan pass from cm848_periodicTaskGroup13_calibration2: cm848_selectCoolingFanSpeedTarget / "
     "cm848_selectCoolingFanDutySource / cm848_applyCoolingFanDuty - nothing J1939 in it"),
    ("diag_record_queue_add_entry", "cm848_scheduleJ1939PeriodicMessage",
     "Adds a periodic J1939 broadcast to transmit queue 0 (20 entries at 0x3fd2e2) or 1 (10 entries at 0x3fd3aa): the "
     "PGN / the period (ms - kept in 10 ms ticks) / the first send (the queue's current tick + the offset ms in ticks) "
     "/ the builder. Returns 1 when the queue is full. cm848_j1939_system_init schedules each broadcast (PGN 65265 "
     "every 100 ms from 70 ms ...)"),
    # the injection angle cluster
    ("engine_injectionTiming_crankSyncDispatch", "cm848_dispatchCrankSynchronousInjection", None),
    ("engine_injectionAngle_updateCutoutAndTimingDemand", "cm848_updateCylinderCutoutAndInjectionQuantities", None),
    ("engine_injectionAngle_accumulateInjectedFuel", "cm848_accumulateInjectedFuel", None),
    ("engine_injectionAngle_tpuUpdate", "cm848_armTpuChannel10AtEndOfInjectionLimit",
     "Computes injection_end_limit_angle (the injection_end_limit_base lookup on average_engine_speed plus the fuel "
     "pressure scale and valve delay bias terms - plus the limp home adjustment) and programs TPU-A channel 10 "
     "(TPUA_CH10_PARAM0 and a host service request) from the cylinder's angle + injection_timing_table_offset + that "
     "angle; algorithm_enable_flags_32_cal.end_of_injection_limit_enable takes part. Called by the TPU-A channel 6 "
     "handler and cm848_scheduleInjectionAnglesInSpeedLimpHome"),
    ("engine_injectionAngle_tpuChannel10CylinderEventHandler", "cm848_handleTpuChannel10CylinderEvent", None),
    ("engine_injectionAngle_writeTpuEvent", "cm848_writeInjectionAngleToTpuChannel5", None),
    ("engine_injectionAngle_selectCylinderInjector", "cm848_selectCylinderInjector", None),
    ("engine_injectionAngle_lookupTimingTableOffset", "cm848_lookupInjectionTimingTableOffset", None),
    ("engine_injectionAngle_computeLoadCh6", "cm848_loadInjectionStartAnglesOnTpuChannel6",
     "From the TPU-A channel 6 handler (state 1): the pilot / main / auxiliary start angles (each timing for the "
     "cylinder event x -5) and the wake-up lead (injection_wakeup_duration_* by the speed breakpoint x the tooth "
     "separation / average_pulse_period) give the channel 6 crank position it loads (the cylinder's angle + "
     "injection_timing_table_offset - the lead + the start angle). Its old plate said no caller was found - the "
     "channel 6 handler calls it"),
    ("engine_injectionAngle_tpuChannel6EventHandler", "cm848_handleTpuChannel6InjectionEvent", None),
    # the SCI service timers and the sensor supply state
    ("phaseGroupB_ControlDispatchers", "cm848_updateSciServiceTimers",
     "From cm848_phase_group_b_processing: the SCI service timers - cm848_updateSciOutputTests / "
     "cm848_countDownSciClearDiagnosticsDelay / cm848_expireSciSetEngineSpeedRequest / cm848_sciDecrementKeyRetryDelay"),
    ("cm848_countdown_timer_update", "cm848_countDownSciClearDiagnosticsDelay",
     "Counts sci_clear_diagnostics_delay_count down and sets sci_clear_diagnostics_done_flag when it reaches 0 (the "
     "delay SCI command 0x17 starts)"),
    ("sensorChannelConditionValidator", "cm848_getSensorChannelReferenceSupplyState",
     "For a sensor channel's ratiometric reference (sensor_channel_ratiometric_reference_channel_cal): 2 when that "
     "supply has a voltage high or low fault (the throttle sensor supply / the engine connector sensors supply / "
     "sensor supply 1 ...) - 1 while its reference voltage channel debounces - else 0. Called by the four sensor "
     "channel processors"),
]
fp = os.path.join(O, "function_renames.csv")
f = open(fp).read()
if "cm848_startJ1939TransportSession," in f:
    print("already applied")
    sys.exit(0)
original = f
mapping = ["address,name,old_label,kind,dims"]
for cur, new, plate in FUNCS:
    m = re.search(rf"^(0x[0-9a-f]{{8}}),{re.escape(cur)}(,[^\n]*)?$", f, re.M)
    assert m, cur
    assert re.fullmatch(r"cm848_[a-z][A-Za-z0-9]*", new) and not re.search(rf"\b{new}\b", original), new
    old_plate = (m.group(2) or ",")[1:].strip()
    if plate is None:
        assert old_plate, cur
        text = f"{old_plate} (was {cur}; {R})"
    else:
        assert "," not in plate and '"' not in plate, cur
        text = f"{plate} (was {cur}; {R})" + (f" | earlier note: {old_plate}" if old_plate else "")
    f = f[:m.start()] + f"{m.group(1)},{new},{text}" + f[m.end():]
    mapping.append(f"{m.group(1)},{new},{cur},function,1")
open(fp, "w").write(f)

gp = os.path.join(O, "global_variables.csv")
g = open(gp).read()
old = "0x003fd47a,j1939_data_log_handler_count,byte,registered handler count in secondary J1939 PGN table (ROM-aliased)"
assert g.count(old) == 1 and "0x003fcf5c," not in g and "0x003fcf5d," not in g
g = g.replace(old, "0x003fd47a,j1939_receive_handler_count,byte,The number of entries in the J1939 receive handler table "
                   "at 0x3fd414 (at most 17): cm848_registerJ1939ReceiveHandler appends at this index and "
                   f"cm848_dispatchJ1939ReceivedMessages scans that many (was j1939_data_log_handler_count; {R})")
anchor = next(l for l in g.split("\n") if l.startswith("0x003fcf96,"))
g = g.replace(anchor, "\n".join([
    f"0x003fcf5c,sci_clear_diagnostics_delay_count,byte,Passes left after SCI command 0x17 starts a fault clear "
    f"(diagnostic_clear_request_state 3) with the engine stopped: it loads 4 - cm848_countDownSciClearDiagnosticsDelay "
    f"counts it down ({R})",
    f"0x003fcf5d,sci_clear_diagnostics_done_flag,byte,1 when sci_clear_diagnostics_delay_count ran out: the next SCI "
    f"command 0x17 answers e0 e0 e0 and clears it ({R})",
    anchor]))
open(gp, "w").write(g)
mapping.append("0x003fd47a,j1939_receive_handler_count,j1939_data_log_handler_count,global,1")
with open(map_path, "w") as fh:
    fh.write("\n".join(mapping) + "\n")
print(f"{len(FUNCS)} functions / 1 global renamed / 2 globals named")
