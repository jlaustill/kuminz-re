"""Batch W2 (round 92): assemble and validate the result for CM550 algorithm enable words 7 8 9 11 12 13 14.
Read-only on the repository; writes result_W2.json next to this script. usage: build_result_v2.py <repo>"""
import csv
import json
import os
import re
import sys

repo = sys.argv[1]
HERE = os.path.dirname(os.path.abspath(__file__))

# ---------------------------------------------------------------- words 7 / 8 / 9: the engine protection channels
CHANNELS = [  # (n, name, stem, config address)
    (0, "coolant_level", "EPCV", 0x807032), (1, "coolant_temperature", "EPCQ", 0x807056),
    (2, "intake_manifold_temperature", "EPIM", 0x80707a), (3, "oil_pressure", "EPO2", 0x80709e),
    (4, "water_in_fuel", "EPWF", 0x8070c2), (5, "boost_pressure", "EPBS", 0x8070e6),
    (6, "engine_sync_fuel_pressure", "EPFP", 0x80710a), (7, "fuel_temperature", "EPFT", 0x80712e),
    (8, "ambient_air_pressure", "EPAA", 0x807152),
]
TEXT = {  # the v64t6_s text; the part in parentheses is cut there and completed from longer copies / siblings
    "EPCVFLEN": "'BIT 0 OF 0-15. ENABLE PARAMETER FOR FUEL LIMITIN(G DUE TO COOLANT LEVEL)'",
    "EPCVRPEN": "'BIT 1 OF 0-15. ENABLE PARAMETER FOR RPM LIMITING (DUE TO COOLANT LEVEL)'",
    "EPCVSOEN": "'BIT 2 OF 0-15. ENABLE SHUTDOWN ON COOLANT LEVEL (ERRORS)'",
    "EPCVRYEN": "'B3. PREVENTS RESTART AT POWERUP WHEN SHUTDN CNT > (MAX SHUTDN CNT DUE TO CLT LEV)'",
    "EPCQFLEN": "'BIT 4 OF 0-15. ENABLE PARAMETER FOR FUEL LIMITIN(G DUE TO COOLANT TEMPERATURE)'",
    "EPCQRPEN": "'BIT 5 OF 5-15. EPF COOLANT TEMPERATURE RPM LIMIT(ING ENABLE)'",
    "EPCQSOEN": "'BIT 6 OF 0-15. ENABLE SHUTDOWN ON COOLANT TEMPER(ATURE ERRORS)'",
    "EPCQRYEN": "'BIT 7 OF 0-15. PREVENTS RESTART AT POWERUP WHEN S(HUTDN CNT > MAX SHUTDN CNT)'",
    "EPIMFLEN": "'BIT 8 OF 0-15 ENABLE FOR TVO LIMITING DUE TO INTA(KE MANIFOLD TEMP)'",
    "EPIMRPEN": "'BIT 9 OF 0-15. ENABLE PARAMETER FOR RPM LIMITING (DUE TO IMT)'",
    "EPIMSOEN": "'BIT 10 OF 0-15. ENABLE SHUTDOWN ON INTAKE MANIFO(LD TEMPERATURE ERRORS)'",
    "EPIMRYEN": "'BIT 11 OF 0-15. PREVENTS RESTART AT POWERUP WHEN (SHUTDN CNT > MAX SHUTDN CNT)'",
    "EPO2FLEN": "'BIT 12 OF 0-15. ENABLE PARAMETER FOR FUEL LIMITI(NG DUE TO OIL PRESSURE)'",
    "EPO2RPEN": "'BIT 13 OF 0-15. EPF OIL PRESSURE FAULT ENABLE PA(RAMETER)' (CM848 label Oil_Pressure_RPM_Limiting_Enable)",
    "EPO2SOEN": "'BIT 14 OF 0-15. ENABLE SHUTDOWN ON OIL PRESSURE (ERRORS)'",
    "EPO2RYEN": "'BIT 15 OF 0-15. PREVENTS RESTART AT POWERUP WHEN (SHUTDN CNT > MAX SHUTDN CNT)'",
    "EPWFFLEN": "S mask 0x1 'ENABLE PARAMETER FOR FAULT LIMITING DUE TO WATER IN( FUEL)'",
    "EPWFRPEN": "S mask 0x2 'ENABLE PARAMETER FOR FAULT RPM LIMITING DUE TO WATE(R IN FUEL)'",
    "EPWFSOEN": "S mask 0x4 'ENABLE SHUTDOWN ON WATER IN FUEL ERRORS'",
    "EPWFRYEN": "S mask 0x8 'PREVENTS RESTRT AT PWR UP WHEN SHUTDN CNT>MAX SHUTD(N CNT)'",
    "EPBSFLEN": "S mask 0x10 'ENABLE PARAMETER FOR FAULT LIMITING DUE TO ENG SYNC' (the text is the engine sync record's; the mnemonic and its three siblings say boost pressure)",
    "EPBSRPEN": "S mask 0x20 'ENABLE PARAMETER FOR FAULT RPM LIMITING DUE TO BOOS(T PRESSURE)'",
    "EPBSSOEN": "S mask 0x40 'ENABLE SHUTDOWN ON BOOST PRESSURE ERRORS'",
    "EPBSRYEN": "S mask 0x80 'PREVENTS RESTRT AT PWR UP WHEN SHUTDN CNT>MAX SHUTD(N CNT)'",
    "EPFPFLEN": "S mask 0x100 'ENABLE PARAMETER FOR FAULT LIMITING DUE TO ENG SYNC( FUEL PRESSURE)'",
    "EPFPRPEN": "S mask 0x200 'ENABLE PARAMETER FOR FAULT RPM LIMITING DUE TO ENG (SYNC FUEL PRESSURE)'",
    "EPFPSOEN": "S mask 0x400 'ENABLE SHUTDOWN ON ENGINE SYNC FUEL PRESSURE ERRORS'",
    "EPFPRYEN": "S mask 0x800 'PREVENTS RESTRT AT PWR UP WHEN SHUTDN CNT>MAX SHUTD(N CNT)'",
    "EPFTFLEN": "'BIT 12 OF 0-15 ENABLES FUEL LIMITING DUE TO FUEL (TEMPERATURE ERRORS)'",
    "EPFTRPEN": "'BIT 13 OF 0-15 ENABLES RPM LIMITING DUE TO FUEL T(EMPERATURE ERRORS)'",
    "EPFTSOEN": "'BIT 14 OF 0-14 ENABLES SHUTDOWN ON FUEL TEMPERATU(RE ERRORS)'",
    "EPFTRYEN": "'BIT 15 OF 0-15 PREVENTS RESTART AT POWERUP WHEN S(HUTDN CNT > MAX SHUTDN CNT)'",
    "EPAAFLEN": "S mask 0x1 'ENABLE PARAMETER FOR FAULT LIMITING DUE TO AMBIENT (AIR PRESSURE)'",
    "EPAARPEN": "S mask 0x2 'ENABLE PARAMETER FOR FAULT RPM LIMITING DUE TO AMBI(ENT AIR PRESSURE)'",
    "EPAASOEN": "S mask 0x4 'ENABLE SHUTDOWN ON AMBIENT AIR PRESSURE ERRORS'",
    "EPAARYEN": "S mask 0x8 'PREVENTS RESTRT AT PWR UP WHEN SHUTDN CNT>MAX SHUTD(N CNT)'",
}
KINDS = [("FLEN", "fueling_limiting_enable"), ("RPEN", "rpm_limiting_enable"), ("SOEN", "shutdown_enable"),
         ("RYEN", "restart_enable")]
EXTRA = {  # (word, bit) -> extra evidence
    (7, 12): "also tested directly: andi.w #0x1000 at 0x1983e (cm550_FUN_00019702) - while set and "
             "oil_pressure_fault_inhibit_timer is below the power-up period 0x807f34 the oil pressure fueling "
             "severity index and the loop maximum are forced to 0x100 (the full derate)",
    (7, 15): "cm550_diagnosticProtectionEvaluator skips channel 3 so only cm550_protectionState1DiagnosticValidator "
             "reads this one",
    (8, 12): "also tested directly: andi.l #0x1000 at 0x1caec (vp44_FUN_0001cad6) - with engine protection enabled "
             "(word 2 bit 4) and this bit or bit 13 set it updates the channel input vp44_fuel_temperature_value",
    (8, 13): "also tested directly: andi.l #0x2000 at 0x1cafa (vp44_FUN_0001cad6) - the second operand of the "
             "fuel temperature input update (see bit 12)",
}


def channel_fields(word, dump):
    out = []
    for n, name, stem, cfg in CHANNELS:
        for k, (suffix, kind) in enumerate(KINDS):
            table_bit = 0x70 + 4 * n + k
            if table_bit >> 4 != word:
                continue
            bit = table_bit & 15
            mn = stem + suffix
            state = "set" if dump >> bit & 1 else "clear"
            where = f"table bit {table_bit} = 0x70 + 4 x {n} + {k} (channel {n})"
            use = ("read by the fuel limit loop cm550_FUN_00019702",
                   "read by cm550_calculateFaultDerateEngineSpeedLimit",
                   "read by the shutdown loop processDiagnosticLimitStatus and by the restart checks",
                   "read by the restart checks cm550_diagnosticProtectionEvaluator / "
                   "cm550_protectionState1DiagnosticValidator")[k]
            parts = [f"{mn} {TEXT[mn]}", f"{where}: {use}"]
            if (word, bit) in EXTRA:
                parts.append(EXTRA[(word, bit)])
            parts.append(f"{state} in the dumps")
            out.append({"bit": bit, "name": f"{name}_{kind}", "comment": "; ".join(parts)})
    return out


def reserved(bit, comment):
    return {"bit": bit, "name": f"reserved_bit_{bit}", "comment": comment}


W7_DUMP, W8_DUMP, W9_DUMP, W11_DUMP, W12_DUMP, W13_DUMP, W14_DUMP = 0xffff, 0, 0, 0x000b, 0xbb87, 0, 0

word7 = {
    "word": 7, "address": "0x803ca2", "current_name": "(no row; renders _DAT_00803ca2)",
    "proposed_name": "algorithm_enable_flags_7_cal", "proposed_type": "cm550_algorithm_enable_flags_7_t",
    "shared_with_cm848": False,
    "row_comment": (
        "Algorithm enable flags word 7 (EEPROM 0x198; e2m 106B +10): the engine protection enables of channels 0-3 - "
        "coolant level 0x1-0x8 / coolant temperature 0x10-0x80 / intake manifold temperature 0x100-0x800 / oil "
        "pressure 0x1000-0x8000, four bits per channel: fueling limiting / rpm limiting / shutdown / restart "
        "(Calterm EPCV / EPCQ / EPIM / EPO2 + FLEN / RPEN / SOEN / RYEN; channel n = config record 0x807032 + 36 x "
        "n). The protection loops read them as table "
        "bit 0x70 + 4 x channel + k from word 0 (0x803c94): k 0 the fault derate fuel limit loop cm550_FUN_00019702, "
        "k 1 cm550_calculateFaultDerateEngineSpeedLimit, k 2 the shutdown loop processDiagnosticLimitStatus, k 2 and "
        "k 3 the restart checks cm550_diagnosticProtectionEvaluator / cm550_protectionState1DiagnosticValidator. One "
        "direct reader: cm550_FUN_00019702 tests 0x1000 at 0x1983e for the oil pressure start-up inhibit. No store "
        "in the dumped ROM. 0xffff in the EEPROM and RAM dumps (all four channels fully enabled). CM848 twin "
        "algorithm_enable_flags_7_cal (0x3fd5aa) has the same 16 e2m records but stays a plain word (nothing reads "
        "it there). (no row before; PR #53 round 92)"),
    "differences_from_cm848": (
        "No bit differs: CM848's word 7 (0x3fd5aa) has the same 16 e2m records at the same masks (Coolant_Level / "
        "Coolant_Temperature / IMT / Oil_Pressure x Fueling_Limiting / RPM_Limiting / Shutdown / Restart). But CM848 "
        "keeps it a plain word (its engine protection loops start at table bit 128 so nothing reads it) and has no "
        "algorithm_enable_flags_7_t, so there is no CM848 type to share: the type is CM550's own, with field names "
        "spelled from CM848's e2m record names. In CM550 the loops start at table bit 112 and channels 0-3 read "
        "all 16 bits."),
    "code_tests": (
        "Direct: 0x1983e move.w (0x803ca2).l,d0 + andi.w #0x1000 + beq (cm550_FUN_00019702 @ 0x19702) = bit 12. "
        "Indexed from word 0 (movea.l #0x803c94,a0 then move.w (0,a0,dn.w*2): word index = bit / 16, mask = 1 shifted left by bit mod 16): "
        "table bit 0x70 + 4 x channel + k, channels 0-3 = this word. k 0 cm550_FUN_00019702 (moveq #0x70 at "
        "0x19718); k 1 cm550_calculateFaultDerateEngineSpeedLimit (moveq #0x71 at 0x18e22); k 2 "
        "processDiagnosticLimitStatus (moveq #0x72 at 0x1902a); k 2 and k 3 of the recorded shutdown channel in "
        "cm550_diagnosticProtectionEvaluator (addi.w #0x70 at 0x18b64, then +2 / +3) and "
        "cm550_protectionState1DiagnosticValidator (moveq #0x70 at 0x18cf8). What the bits do there: k 0 / k 1 - the "
        "loop computes the channel's fueling / rpm severity only while the bit or the channel's history-only bit "
        "(table bit 0x1a0 + channel = word 26) is set; k 2 - the channel's shutdown timers run only while set "
        "(clear zeroes them); k 3 - with k 2 set and the channel recorded as the shutdown channel, "
        "cm550_diagnosticProtectionEvaluator examines it before cranking once the shutdown count has reached its "
        "maximum (it skips channel 3) and cm550_protectionState1DiagnosticValidator updates its restart severity "
        "indexes. Channel identity from the extended RAM dump: each state record (0x80d0dc + 46 x channel) starts "
        "with the channel's input pointer - channel 0 0x8091e6 (the coolant level low switch input) / 1 0x80a336 "
        "(e2m ADCLTPFT filtered coolant temperature) / 2 0x80a26a (the intake manifold temperature pre-processed "
        "for engine protection) / 3 0x80a30a (ADOLPRFT filtered oil pressure). .cpp: 1 plain test, no value-flow "
        "form."),
    "writes": ("none: the one absolute reference is the move.w read at 0x1983e, the indexed accesses are move.w "
               "reads, and nothing references the odd byte 0x803ca3. Only the generic EEPROM mirror writers can "
               "change it."),
    "fields": channel_fields(7, W7_DUMP),
}

word8 = {
    "word": 8, "address": "0x803ca4", "current_name": "(no row; renders _DAT_00803ca4)",
    "proposed_name": "algorithm_enable_flags_8_cal", "proposed_type": "cm550_algorithm_enable_flags_8_t",
    "shared_with_cm848": False,
    "row_comment": (
        "Algorithm enable flags word 8 (EEPROM 0x19a; e2m 106B +12): the engine protection enables of channels 4-7 - "
        "water in fuel 0x1-0x8 / boost pressure 0x10-0x80 / engine sync fuel pressure 0x100-0x800 / fuel temperature "
        "0x1000-0x8000, four bits per channel: fueling limiting / rpm limiting / shutdown / restart (Calterm EPWF / "
        "EPBS / EPFP / EPFT + FLEN / RPEN / SOEN / RYEN). Read by the protection loops as table bit 0x70 + 4 x "
        "channel + k from word 0 (0x803c94), like word 7. Direct reader: vp44_FUN_0001cad6 tests 0x1000 / 0x2000 "
        "(0x1caec / 0x1cafa) before it updates the fuel temperature channel's input. No store in the dumped ROM. "
        "0x0000 in the EEPROM and RAM dumps (the four channels are unused: their configuration flags are 0 too). "
        "CM848's word 8 has other channels (fuel temperature / compressor outlet temperature / turbine inlet "
        "temperature at bits 0-11). (no row before; PR #53 round 92)"),
    "differences_from_cm848": (
        "Different channels. CM848 word 8 (0x3fd5ac, a plain word): bits 0-3 fuel temperature / 4-7 C_Out "
        "(compressor outlet) temperature / 8-11 T_In (turbine inlet) temperature / 12-15 no record. CM550: bits 0-3 "
        "water in fuel / 4-7 boost pressure / 8-11 engine sync fuel pressure / 12-15 fuel temperature. The fuel "
        "temperature channel is in both, at bits 12-15 here and 0-3 in CM848."),
    "code_tests": (
        "Direct: 0x1caec move.w (0x803ca4).l,d0 + andi.l #0x1000 + bne and 0x1cafa andi.l #0x2000 + beq "
        "(vp44_FUN_0001cad6 @ 0x1cad6) = bits 12 and 13. Indexed from word 0: table bit 0x70 + 4 x channel + k for "
        "channels 4-7 in the same five functions as word 7 (cm550_FUN_00019702 k 0 / "
        "cm550_calculateFaultDerateEngineSpeedLimit k 1 / processDiagnosticLimitStatus k 2 / "
        "cm550_diagnosticProtectionEvaluator and cm550_protectionState1DiagnosticValidator k 2 and k 3). Channel "
        "identity from the extended RAM dump (the input pointer at 0x80d0dc + 46 x channel): channel 4 0x80a46a "
        "(e2m ADWFFT filtered water in fuel) / 5 0x80a320 (ADFTBSPR filtered boost pressure) / 6 0x80a2f4 "
        "(ADSYFPFT the fuel pressure channel) / 7 0x80a254 (vp44_fuel_temperature_value - the value the direct "
        "reader updates). .cpp: 2 tests and both also flow into the function's returned value (uVar1 = the "
        "word masked with 0x1000 at line 18230 / with 0x2000 at 18231)."),
    "writes": ("none: the two absolute references are move.w reads, the indexed accesses are reads, and nothing "
               "references 0x803ca5."),
    "fields": channel_fields(8, W8_DUMP),
}

w9_fields = channel_fields(9, W9_DUMP)
for b in range(4, 16):
    if b < 8:
        g = ("no record in v64t6_s and not read (the protection loops stop after channel 8 = bit 3); guess: 20 other "
             "ISB e2m files have the OEM pressure channel here (EPOE* masks 0x10-0x80); clear in the dumps")
    elif b < 12:
        g = ("no record in v64t6_s and not read (the protection loops stop after channel 8 = bit 3); guess: 20 other "
             "ISB e2m files have the OEM switch channel here (EPOS* masks 0x100-0x800); clear in the dumps")
    else:
        g = "no record in any e2m file and not read; clear in the dumps"
    w9_fields.append(reserved(b, g))
word9 = {
    "word": 9, "address": "0x803ca6", "current_name": "(no row; no reference by its own address)",
    "proposed_name": "algorithm_enable_flags_9_cal", "proposed_type": "word",
    "shared_with_cm848": False,
    "row_comment": (
        "Algorithm enable flags word 9 (EEPROM 0x19c; e2m 106B +14): the engine protection enables of channel 8, "
        "ambient air pressure - 0x1 EPAAFLEN fueling limiting / 0x2 EPAARPEN rpm limiting / 0x4 EPAASOEN shutdown / "
        "0x8 EPAARYEN restart; bits 4-15 have no record. No direct reader: the protection loops "
        "(cm550_FUN_00019702 / cm550_calculateFaultDerateEngineSpeedLimit / processDiagnosticLimitStatus / "
        "cm550_diagnosticProtectionEvaluator / cm550_protectionState1DiagnosticValidator) read bits 0-3 as table "
        "bits 144-147 = 0x70 + 4 x 8 + k from word 0 (0x803c94), so it stays a plain word like CM848's unread "
        "words. No store in the dumped ROM. 0x0000 in the EEPROM and RAM dumps. CM848 has no row and no e2m record "
        "for word 9. (no row before; PR #53 round 92)"),
    "differences_from_cm848": (
        "CM848 has no row, no e2m record and no reader for word 9 (0x3fd5ae; 0x0000 in its dump): the ambient air "
        "pressure protection channel is CM550's own."),
    "code_tests": (
        "No absolute reference to 0x803ca6 / 0x803ca7 in the dumped ROM. Bits 0-3 are read only as channel 8 of the "
        "indexed protection loops (table bits 144-147 from word 0): k 0 cm550_FUN_00019702, k 1 "
        "cm550_calculateFaultDerateEngineSpeedLimit, k 2 processDiagnosticLimitStatus, k 2 and k 3 "
        "cm550_diagnosticProtectionEvaluator / cm550_protectionState1DiagnosticValidator. The loops stop at "
        "load_breakpoint_table 0x807176 = 9 channels, so bits 4-15 are never read. Channel 8's input pointer in the "
        "extended RAM dump (0x80d24c) is 0x80a3ba = e2m ADAAPRFT filtered ambient air pressure."),
    "writes": "none: no reference at all by its own address.",
    "fields": w9_fields,
}

# ---------------------------------------------------------------- word 11
w11_fields = [
    {"bit": 0, "name": "proprietary_communication_enable", "comment": (
        "JCJPEA 'PARAMETER INDICATING WHETHER DATALINK PROTOCOLS ARE TURNED ON' (an N record with no bit; CM848's "
        "label Proprietary_Communication_Enable has S mask 0x1); andi.w #0x1 at 0x15fe8: "
        "mc68k_dispatchJ1708ReceivedMessages handles the proprietary J1708 messages (message identifier below 8: "
        "the security key / development mode / shutdown / restart commands) only while set; set in the dumps "
        "(0x000b)")},
    {"bit": 1, "name": "j1587_communication_enable", "comment": (
        "JC87CZEA 'BIT 1 OF 0-15 INDICATES WHETHER J1587 COMMUNICATION IS ENABLED'; andi.w #0x2 at 0xebe0 "
        "(cm550_diagnosticMessageTransmissionManager: the periodic J1587 broadcast "
        "vp44_insiteParameterTableIterator) and 0x16396 (mc68k_dispatchJ1708ReceivedMessages: message identifiers "
        "0x80 and up); set")},
    {"bit": 2, "name": "j1922_communication_enable", "comment": (
        "JC22CZEA 'BIT 2 OF 0-15 INDICATES WHETHER J1922 COMMUNICATION IS ENABLED'; andi.w #0x4 at 0xebac "
        "(cm550_diagnosticMessageTransmissionManager: the periodic cm550_diagnosticMessage45Builder / "
        "cm550_diagnosticMessage53Builder) and 0x163be (mc68k_dispatchJ1708ReceivedMessages: message identifiers "
        "0x45-0x56 = 69-86 the J1922 range); clear")},
    {"bit": 3, "name": "j1939_communication_enable", "comment": (
        "JC39CZEA 'BIT 3 OF 0-15 INDICATES WHETHER J1939 COMMUNICATI(ON IS ENABLED)'; andi.w #0x8 at 0x1ff4e "
        "(cm550_engineRunTimeHistogramAccumulator = the J1939 periodic transmit schedule) and 0x212c0 "
        "(mc68k_FUN_000212b2 = the J1939 receive dispatch) - the twins of CM848's two readers; set")},
    reserved(4, "no record in v64t6_s and no reader in the dumped ROM; guess JCRWDXEN 'J1587 TRANSPORT PROTOCOL "
                "ENABLE' (S mask 0x10 in 14 other ISB e2m files); CM848 reserved_bit_4 too; clear in the dumps"),
]
for b in range(5, 16):
    w11_fields.append(reserved(b, "no e2m record and no reader in the dumped ROM; CM848 reserved too; clear in the "
                                  "dumps"))
word11 = {
    "word": 11, "address": "0x803caa", "current_name": "diagnostic_subsystem_enable_flags",
    "proposed_name": "algorithm_enable_flags_11_cal", "proposed_type": "algorithm_enable_flags_11_t",
    "shared_with_cm848": True,
    "row_comment": (
        "Algorithm enable flags word 11 (EEPROM 0x1a0; e2m 106B +18): the datalink protocol enables - 0x1 JCJPEA "
        "proprietary / 0x2 JC87CZEA J1587 / 0x4 JC22CZEA J1922 / 0x8 JC39CZEA J1939 communication; bits 4-15 have "
        "no record. 7 single-bit reads and no store in the dumped ROM: mc68k_dispatchJ1708ReceivedMessages gates "
        "the proprietary (message identifier below 8) / J1922 (0x45-0x56) / J1587 (0x80 and up) messages with bits 0 / 2 / "
        "1, cm550_diagnosticMessageTransmissionManager the periodic J1922 and J1587 transmissions with bits 2 / 1, "
        "and bit 3 gates the J1939 periodic transmit schedule (cm550_engineRunTimeHistogramAccumulator) and receive "
        "dispatch (mc68k_FUN_000212b2). 0x000b in the EEPROM and RAM dumps (proprietary + J1587 + J1939), the same "
        "value as the CM848 truck. CM848 twin algorithm_enable_flags_11_cal (0x3fd5b2), the same type. (was "
        "diagnostic_subsystem_enable_flags: it enables the datalink protocols, not a diagnostic subsystem; PR #53 "
        "round 92)"),
    "differences_from_cm848": (
        "None: the same four records at the same bits (proprietary 0 / J1587 1 / J1922 2 / J1939 3) and bits 4-15 "
        "reserved in both, so the word takes CM848's algorithm_enable_flags_11_t with its field names verbatim. "
        "CM848 reads only bit 3; CM550 reads all four, and each reader agrees with its record."),
    "code_tests": (
        "7 reads, all move.w (0x803caa).l,d0 + andi.w + beq: 0xebac #0x4 and 0xebe0 #0x2 "
        "(cm550_diagnosticMessageTransmissionManager @ 0xeba4); 0x15fe8 #0x1 / 0x16396 #0x2 / 0x163be #0x4 "
        "(mc68k_dispatchJ1708ReceivedMessages @ 0x15f8e); 0x1ff4e #0x8 (cm550_engineRunTimeHistogramAccumulator @ "
        "0x1ff38); 0x212c0 #0x8 (mc68k_FUN_000212b2 @ 0x212b2). .cpp: 7 plain tests + 3 CONCAT22(.., word) masked with "
        "0xffff00NN value forms (lines 4041 / 21550 / 22657) that may print as pieces once typed."),
    "writes": "none: all 7 absolute references are move.w reads and nothing references 0x803cab.",
    "fields": w11_fields,
}

# ---------------------------------------------------------------- word 12
w12_fields = [
    {"bit": 0, "name": "idle_speed_save_enable", "comment": (
        "LSISSVEN 'BIT 0 OF 0 - 15 ENABLES SAVE OF LAST IDLE SPEED AT SHUT(DOWN)'; andi.w #0x1 at 0x26546 "
        "(cm550_engineModeTimingAdjuster / vp44_rpm_derate_monitor: set keeps the operator idle adjustment in "
        "rpm_added_to_lsg_reference_300_300 0x805f0a - clear zeroes it) and 0x265a0 "
        "(cm550_fuelDemandLimitSource2Selector / vp44_initVP44StatusFlags: the start-up restore of that "
        "adjustment); CM848 field name; set in the dumps (0xbb87)")},
    {"bit": 1, "name": "overspeed_fuel_shutoff_enable", "comment": (
        "EPOSFSO 'IF T FSO CLOSES WHEN OVRSPD DETECTED BY MAIN MICRO. BI(T 1 OF 0 - 15 OF WORD C)' (FSO = fuel "
        "shut off: e2m DRFSEA 'CONTROLS FUEL SHUT OFF DRIVER'); andi.l #0x2 at 0x1ca9a "
        "(cm550_fuelDemandLimitSelector11 / vp44_canPinVp44StatusController): in ENGINE_STATE_OVERSPEED the fuel "
        "shutoff driver bit 0x20 of fuel_system_output_driver_control is cleared only while set; CM848 "
        "reserved_bit_1 with the same record (rename proposed); set")},
    {"bit": 2, "name": "water_in_fuel_enable", "comment": (
        "WFAGEN 'BIT 2 ENABLE FLAG USED FOR WATER_IN_FUEL ALGORITHM.'; andi.w #0x4 at 0x34c3e "
        "(vp44FaultRegisterBit2Monitor): set = a wet water_in_fuel_sensor_state sets fault status word 4 bit "
        "0x2000 and lamp driver bit 0x10 - clear = that fault bit is cleared; CM848 field name; set")},
    {"bit": 3, "name": "air_fuel_control_override_enable", "comment": (
        "AFENMAN 'BIT 3 OF 0-15 IN WORD C'; andi.w #0x8 at 0xc19c (cm550_fuelTimingTransitionStateMachine): set "
        "takes the derate fuel adjustment from afc_fueling_derate_value_when_afc_override_is_enabled_0_100 instead "
        "of the engine speed x boost pressure table; CM848 field name; clear")},
    {"bit": 4, "name": "electronic_smart_power_enable", "comment": (
        "SPAGEN '0 - DISBALE 1 - ENABLE ESP ALGORITHM BIT 4 OF 0 - 15.' (e2m group ESP_08 'ELECTRONIC SMART POWER "
        "GROUP'); andi #0x10 at 0x1abcc (gates cm550_updateElectronicSmartPowerTau) / 0xc3ea (calculateAlpha "
        "copies the alpha into the timing alpha only while clear) / 0x1cd96 (cm550_FUN_0001cc72: the maximum "
        "fueling without programmable power comes from the low horsepower curve while set); CM848 field name; "
        "clear")},
    {"bit": 5, "name": "reverse_electronic_smart_power_enable", "comment": (
        "SPRVEN '0 - DISBALE 1 - ENABLE ESP LAUNCH APPLICATION ALGORITH(M BIT 5 OF 0 - 15.)' (CM848 label "
        "Reverse_ESP_Enable S mask 0x20); andi.l #0x20 at 0x1ad52: cm550_updateElectronicSmartPowerTau enters ESP "
        "tau source state 1 (e2m 11DC +6 SPTUST lists NORMAL / LAUNCH / STEEP) only while set; CM848 field name; "
        "clear")},
    {"bit": 6, "name": "low_speed_governor_droop_enable", "comment": (
        "LSDPEN 'LSG DROOP ENABLE BIT 6 OF 0 - 15 IN WORD C'; andi.l #0x40 at 0xfa1c (vp44State2TransitionHandler) "
        "and 0x1850e (cm550_FUN_000184c6): set lowers the torque curve speed point 1 by fueling x the selected "
        "droop slope 0x80daf4 (e2m LSDPSE) / 167 - the same droop as CM848's reader; CM848 field name; clear")},
    {"bit": 7, "name": "accelerator_interlock_enable", "comment": (
        "ANEN 'BIT 7 OF 0-15 IN WORD C ACCELERATOR INTERLOCK ENABLE B(IT)'; no reader in the dumped ROM; CM848 "
        "field name; set")},
    {"bit": 8, "name": "vehicle_speed_sensor_signal_loss_enable", "comment": (
        "VSMVEN 'BIT 8 WORD C. ENABLES VSS SENSOR LOST WHILE MOVING( DETECTION)'; no reader in the dumped ROM; "
        "CM848 field name (named there after the detector it gates); set")},
    {"bit": 9, "name": "vehicle_speed_sensor_zero_under_load_enable", "comment": (
        "VSSTEN 'BIT 9 WORD C. ENABLES VSS SENSOR LOST WHILE STOPPE(D DETECTION)'; no reader in the dumped ROM; "
        "CM848 field name (named there after its detector: the sensor reads 0 while the engine is under load); "
        "set")},
    reserved(10, "no record in v64t6_s and no reader in the dumped ROM; guess DGOBFUHN 'INDICATES WHETHER OBDII "
                 "FAULT HANDLER IS ENABLED' (mask 0x400 here in 26 other e2m files; CM848 "
                 "obd_fault_handler_enable); clear in the dumps"),
    {"bit": 11, "name": "power_take_off_brake_override_enable", "comment": (
        "PTBRODEN 'WHEN ENABLED IT ALLOWS THE BRAKE TO CANCEL CAB PTO. WORD C BIT (B)' (v64t6_s cuts the bit "
        "letter: 22 other e2m files give it and every S record has mask 0x800); no reader in the dumped ROM; CM848 "
        "field name; set")},
    {"bit": 12, "name": "power_take_off_clutch_override_enable", "comment": (
        "PTCHODEN 'WHEN ENABLED IT ALLOWS THE CLUTCH TO CANCEL CAB PTO. WORD C BIT( C)' (v64t6_s cuts the bit "
        "letter: 22 other e2m files give it and every S record has mask 0x1000); no reader in the dumped ROM; CM848 "
        "field name; set")},
    {"bit": 13, "name": "oil_change_monitor_enable", "comment": (
        "OCEA 'ENABLES OIL CHANGE MONITOR FEATURE BIT 13 OF 0-15 OF W(ORD C)'; no reader in the dumped ROM; CM848 "
        "field name; set")},
    {"bit": 14, "name": "low_speed_governor_cold_idle_override_enable", "comment": (
        "LSCIIHEN 'ENABLE FOR OVERRIDING THE COLD IDLE ADJUST IN THE LSG' (13 other e2m files go on '- BIT 14'); "
        "andi.w #0x4000 at 0x26646 (cm550_FUN_00026616): the cold idle speed adder raises the idle reference "
        "unless this bit is set and the cold idle override flag 0x80db08 (e2m 1049 +6 LSCIOD 'TRUE INHIBITS COLD "
        "IDLE ADJUSTMEN(T)') is non-zero; CM848 reserved_bit_14 (no record there); clear")},
    {"bit": 15, "name": "engine_data_files_enable", "comment": (
        "EDEN 'BIT 15 OF 0 - 15; ENABLES/DISABLES EDF FEATURE.' in e2m group 12C ENDTFL07 'ENGINE DATA FILES ENABLE "
        "AND POWER-DOWNS' (EDF = engine data files); no reader in the dumped ROM; CM848 reserved_bit_15 (no record "
        "there); set")},
]
word12 = {
    "word": 12, "address": "0x803cac", "current_name": "calibration_feature_enable_flags_word_9",
    "proposed_name": "algorithm_enable_flags_12_cal", "proposed_type": "cm550_algorithm_enable_flags_12_t",
    "shared_with_cm848": False,
    "row_comment": (
        "Algorithm enable flags word 12 (EEPROM 0x1a2; e2m 106B +1A, the records say WORD C): 0x1 LSISSVEN idle "
        "speed save / 0x2 EPOSFSO fuel shutoff on overspeed / 0x4 WFAGEN water in fuel / 0x8 AFENMAN air fuel "
        "control override / 0x10 SPAGEN Electronic Smart Power / 0x20 SPRVEN its launch application / 0x40 LSDPEN "
        "low speed governor droop / 0x80 ANEN accelerator interlock / 0x100 VSMVEN and 0x200 VSSTEN the vehicle "
        "speed sensor lost while moving / stopped detections / 0x800 PTBRODEN and 0x1000 PTCHODEN brake / clutch "
        "cancel the cab power take-off / 0x2000 OCEA oil change monitor / 0x4000 LSCIIHEN cold idle override / "
        "0x8000 EDEN engine data files; 0x400 has no record. 12 single-bit reads (bits 0-6 and 14) and no store in "
        "the dumped ROM; bits 7-9 / 11-13 / 15 are set in the calibration but have no reader there (call targets "
        "at 0x40000+ are not dumped). 0xbb87 in the EEPROM and RAM dumps. CM848 twin algorithm_enable_flags_12_cal "
        "(0x3fd5b4) differs in bits 10 / 14 / 15, so the type is CM550's own. (was "
        "calibration_feature_enable_flags_word_9: the word is number 12, not 9; PR #53 round 92)"),
    "differences_from_cm848": (
        "Bits 0 / 2-9 / 11-13 have CM848's positions and meanings (the same Calterm records), so CM848's field "
        "names are reused. Bit 1 (EPOSFSO) has the same record in CM848's own e2m (Overspeed_FSO_Override 0x2) but "
        "CM848 left it reserved_bit_1: a rename is proposed. Bit 10 is obd_fault_handler_enable in CM848 (DGOBFUHN "
        "0x400); J90350.00 has no record and no reader, so it is reserved here. Bits 14 (LSCIIHEN) and 15 (EDEN) "
        "are CM550's: CM848 keeps reserved_bit_14 / reserved_bit_15 with no record in its own e2m and no reader. "
        "Three bits differ, so the type is cm550_."),
    "code_tests": (
        "12 reads (move.w (0x803cac).l,d0 + andi.w or andi.l): bit 0 0x26546 and 0x265a0; bit 1 0x1ca9a; bit 2 "
        "0x34c3e; bit 3 0xc19c; bit 4 0xc3ea / 0x1abcc / 0x1cd96; bit 5 0x1ad52; bit 6 0xfa1c / 0x1850e; bit 14 "
        "0x26646. No test of bits 7-13 or 15. .cpp: 15 plain tests (the sites 0x1ca9a / 0x26546 / 0x265a0 print "
        "twice because overlapping function entries share the code), of which 5 also flow into an assigned or "
        "returned value (lines 1888 / 4961 / 18162 / 18199 / 37601), + 1 CONCAT22 form (line 15320)."),
    "writes": "none: all 12 absolute references are move.w reads and nothing references 0x803cad.",
    "fields": w12_fields,
}

# ---------------------------------------------------------------- words 13 / 14: the switch user override enables
sys.path.insert(0, HERE)
from switch_fields_v2 import w13_fields, w14_fields  # noqa: E402

word13 = {
    "word": 13, "address": "0x803cae", "current_name": "switch_override_configuration",
    "proposed_name": "algorithm_enable_flags_13_cal", "proposed_type": "cm550_algorithm_enable_flags_13_t",
    "shared_with_cm848": False,
    "row_comment": (
        "Algorithm enable flags word 13 (EEPROM 0x1a4; e2m 106B +1C DIG_SIG): the user override enables of logical "
        "switches 0-15, bit s = switch s - 0x1 key switch (no record) / 0x2 0x4 0x8 cruise control resume, set and "
        "on/off / 0x10 manual fan / 0x20 powertrain protection / 0x40 high speed governor droop select / 0x80 "
        "idle and 0x100 not idle (the idle validation pair) / 0x200 accelerator interlock / 0x400 clutch / 0x800 "
        "brake / 0x1000 engine brake select 1 / 0x2000 0x4000 idle increment and decrement / 0x8000 diagnostic "
        "test. Set: the switch status bit (0x80bcce + s / 8, bit s % 8) comes from the user value (0x80bcd8 + s / "
        "8) instead of the debounced input; the J1939 multiplexed switches write that value only while the bit is "
        "set (cm550_FUN_00020890, table bit 0xd0 + s from word 0). It is also the first word of the 10-byte e2m "
        "record DSSWUO 'COVERS ALL USER OVERRIDE ENABLES' (words 13-17): cm550_initializeDiscreteInputs stores its "
        "address in discrete_input_override_mask_ptr and mc68k_sampleAndDebounceDiscreteInputs / "
        "mc68k_ioDriverStrobeHandler read bytes [0] (bits 8-15) and [1] (bits 0-7) through it as masks. 6 direct "
        "single-bit reads (0x80 four times, 0x2000, 0x4000) and no store in the dumped ROM. 0x0000 in the EEPROM "
        "and RAM dumps. CM848's word 13 holds unrelated enables. (was switch_override_configuration; PR #53 round "
        "92)"),
    "differences_from_cm848": (
        "Unrelated: CM848's word 13 (0x3fd5b6, algorithm_enable_flags_13_t) is EB_Switch_Level_Override / "
        "Active_Driver_Demand_With_Jcomm / Net_Torque_Derate_Enable / Fuel_Press_Idle_Diag_Enable, and no CHR e2m "
        "has the switch user override records. CM848 keeps its per-switch datalink source bits elsewhere "
        "(switch_input_datalink_source_bits_cal, EEPROM 0x74c, outside this table)."),
    "code_tests": (
        "Direct (move.w (0x803cae).l,d0 + andi + beq): 0x15830 #0x2000 and 0x15850 #0x4000 "
        "(mc68k_sampleAndDebounceDiscreteInputs); 0x204e6 #0x80 (cm550_outputControlState1Handler); 0x20cbe #0x80 "
        "(cm550_FUN_00020c98); 0x20e5a #0x80 (cm550_FUN_00020e14); 0x32ed4 #0x80 (j1939HandlePgn61443Eec2). Address "
        "taken: move.l #0x803cae,(0x80054c).l at 0x15dd2 (cm550_initializeDiscreteInputs) = "
        "discrete_input_override_mask_ptr (0x00803cae in the RAM dump); through it "
        "mc68k_sampleAndDebounceDiscreteInputs and "
        "mc68k_ioDriverStrobeHandler read [0] = 0x803cae (bits 8-15, over status 0x80bccf) and [1] = 0x803caf (bits "
        "0-7, over 0x80bcce) as status = (input AND NOT mask) OR (user value AND mask). Indexed from word 0 (table bit 0xd0 + "
        "logical switch; addi.l #0xd0 at 0x208d4): cm550_FUN_00020890 for the J1939 descriptor entries 6 / 7 / 5 / "
        "1 / 4 / 3 / 9 / 8 / 15 = bits 1 / 2 / 3 / 9 / 10 / 11 / 13 / 14 / 15. .cpp: 6 plain tests, of which 2 "
        "also flow into a returned value (lines 22322 / 22398), + 1 CONCAT22 form (21960) + the address-of at "
        "10575."),
    "writes": ("none: the 6 absolute word references are move.w reads; the pointer users only read the bytes; "
               "nothing references 0x803caf by address."),
    "fields": w13_fields,
}

word14 = {
    "word": 14, "address": "0x803cb0", "current_name": "(no row; renders _DAT_00803cb0)",
    "proposed_name": "algorithm_enable_flags_14_cal", "proposed_type": "cm550_algorithm_enable_flags_14_t",
    "shared_with_cm848": False,
    "row_comment": (
        "Algorithm enable flags word 14 (EEPROM 0x1a6; e2m 106B +1E DIG_SIG): the user override enables of logical "
        "switches 16-31, bit n = switch 16 + n - 0x2 air conditioning pressure turnkey / 0x4 rear axle ratio / 0x8 "
        "remote throttle / 0x10 remote power take-off / 0x20 coolant level low / 0x40 user datalogger / 0x80 "
        "parking brake / 0x100 coolant level high / 0x200 switched throttle control governor or all speed governor "
        "droop / 0x2000 air conditioning cycle / 0x4000 air conditioning on/off; 0x1 0x400 0x800 0x1000 0x8000 are "
        "the e2m's switches 17 / 27 / 28 / 23 / 31 with no settled function. Set: the switch status bit (word bits "
        "0-7 = status byte 0x80bcd0, bits 8-15 = 0x80bcd1) comes from the user value (0x80bcda / 0x80bcdb) instead "
        "of the debounced input: mc68k_sampleAndDebounceDiscreteInputs and mc68k_ioDriverStrobeHandler read the word as bytes [2] "
        "(bits 8-15) and [3] (bits 0-7) of discrete_input_override_mask_ptr (the second word of e2m DSSWUO). One "
        "direct reader: cm550_FUN_00020784 tests 0x8 at 0x207d0 (the J1939 remote accelerator); cm550_FUN_00020890 "
        "tests bits 3 / 4 by index for the J1939 remote accelerator enable and remote power take-off switches. No "
        "store in the dumped ROM. 0x0000 in the EEPROM and RAM dumps. CM848 has no row and no record for word 14. "
        "(no row before; PR #53 round 92)"),
    "differences_from_cm848": (
        "CM848 has no row, no e2m record (no CHR e2m has 106B +001E) and no reader for word 14 (0x3fd5b8; 0x0000 in "
        "its dump): no CM848 counterpart."),
    "code_tests": (
        "Direct: 0x207d0 move.w (0x803cb0).l,d0 + andi.l #0x8 + beq (cm550_FUN_00020784 @ 0x20784) = bit 3. "
        "Bytewise through discrete_input_override_mask_ptr: [2] = 0x803cb0 (bits 8-15, over status 0x80bcd1) and "
        "[3] = 0x803cb1 (bits 0-7, over 0x80bcd0) in mc68k_sampleAndDebounceDiscreteInputs and "
        "mc68k_ioDriverStrobeHandler. Indexed from word 0: cm550_FUN_00020890 tests table bits 227 / 228 (bits 3 / "
        "4) for the J1939 descriptor entries 14 / 13. .cpp: 1 test, which also flows into the function's returned "
        "value (line 22137)."),
    "writes": ("none: the one absolute reference is a move.w read; the pointer users only read the bytes; nothing "
               "references 0x803cb1 by address."),
    "fields": w14_fields,
}

result = {
    "batch": "W2",
    "words": [word7, word8, word9, word11, word12, word13, word14],
    "cm848_field_renames": [{
        "type_name": "algorithm_enable_flags_12_t", "bit": 1, "current_field": "reserved_bit_1",
        "proposed_field": "overspeed_fuel_shutoff_enable",
        "evidence": (
            "CM848's own e2m (CHR_CC_11.45.01.07) names the bit: 106B +001A Overspeed_FSO_Override, S mask 0x2, "
            "'[EPOSFSO] If T, FSO closes when ovrspd detected by main micro. Bit 1 of 0 - 15 of Word C' - the "
            "struct comment already cites it. CM848's CSV already spells FSO as fuel shutoff "
            "(fault_bit_words_t.fuel_shutoff_control_error = e2m FSO_Control_Error) and CM550's e2m spells it out "
            "(DRFSEA 'CONTROLS FUEL SHUT OFF DRIVER. ENABLE = FSO ON'; CM848's e2m has the same mnemonic as "
            "FSO_Command). CM848 has no reader in either bank and its .cpp never prints the field, so the rename "
            "is label-only; round 20 named word 12's other unread bits 0 and 5 from their records and left this "
            "one (no reason recorded). CM550 reads the same bit at 0x1ca9a: in ENGINE_STATE_OVERSPEED the fuel "
            "shutoff driver bit is cleared only while it is set. The proposed name equals the CM550 field."),
    }],
}

NOTES = """METHOD. Every absolute-long reference to 0x803ca2-0x803cb1 in J90350.00.rom.bin was found and decoded (scratch direct_tests.py): 29 move.w (abs).l,d0 reads, each followed by andi.w / andi.l with a single-bit mask and a branch, plus one address load (move.l #0x803cae,(0x80054c).l at 0x15dd2). No store, no btst, no byte access, no reference to an odd address and none to word 10 (0x803ca8). The indexed accesses use word 0 as their base; I hand-decoded two of them (0x19734-0x19756 and 0x208ce-0x208fc: moveq / addi the bit number, divide or mask by 16, lsl a 1, asr.l #4, move.w (0,a0,dn.w*2)) so table bit i = word i / 16, mask 1 shifted left by i mod 16, and I read the loop constants in the machine code (moveq #0x70 / #0x71 / #0x72, addi.l #0xd0). llvm-objdump-18 and llvm-mc-18 drop many m68k opcodes, so the instruction addresses come from the byte scan and the behaviour from the committed .cpp. The nine protection channels are identified three ways that agree: the 106B records, the e2m names of each channel's own records (configs 0x807032 + 36n, states 0x80d0dc + 46n, severities 0x8057c0 + 30n) and the input pointer at the start of each state record in the extended RAM dump (read at file offset address - 0x809242, the dump being 0x80 short). Dump values: EEPROM 0x198-0x1a7 equals RAM 0x803ca2-0x803cb1 (w7 0xffff, w8 0, w9 0, w10 0, w11 0x000b, w12 0xbb87, w13 0, w14 0).

OLD NAMES AGAINST THE E2M WORD NUMBER. Only calibration_feature_enable_flags_word_9 (0x803cac) is misnumbered: (0x803cac - 0x803c94) / 2 = 12 and its records say WORD C. diagnostic_subsystem_enable_flags (word 11) is a wrong domain: the word enables the datalink protocols. switch_override_configuration (word 13) is right in substance. The e2m writes the word number in hex for word 12 (C) and in decimal for words 13 / 14 ('WORD 13 BIT 9', 'WORD 14 BIT 1'); both fit offset = 2 + 2 x n.

TYPES. Word 11 takes CM848's algorithm_enable_flags_11_t (the only shared type of the batch; check_shared_r92.py prints 'names equal' for it). Words 7 / 8 / 12 / 13 / 14 are cm550_ bitfields: each has direct single-bit tests and no store. Word 9 stays a plain word: nothing reads it by its own address (CM848's rule for its words 7 / 8 / 26), so its fields are for the row comment only.
- Word 7 is the one judgment call on the type: all 16 bits equal CM848's e2m records for its word 7, but CM848 has no algorithm_enable_flags_7_t (a plain word with no reader), so there is nothing to share and I used cm550_algorithm_enable_flags_7_t. If you would rather have one shared type, rename it algorithm_enable_flags_7_t and add the same rows to CM848 (its row can be retyped with no render change, since nothing reads it); the field names already follow CM848's e2m record names.

NAMING CHOICES TO REVIEW.
- Engine protection bits: CHANNEL_fueling_limiting_enable / _rpm_limiting_enable / _shutdown_enable / _restart_enable, after CM848's e2m record names (Coolant_Level_Fueling_Limiting_Enable ... Coolant_Level_Restart_Enable) and algorithm_enable_flags_2_t.engine_protection_restart_enable. The restart bit does not allow a restart: with the shutdown bit it lets the restart checks shut the engine down again ('PREVENTS RESTART AT POWERUP WHEN SHUTDN CNT > MAX SHUTDN CNT'). CHANNEL_restart_limitation_enable would say that more plainly (the e2m and CM848 both call the algorithm the restart limitation); I kept CM848's wording so the twins match. Channel names are the ones W4 used for word 26 (the same nine channels).
- Word 12 bits 8 / 9 take CM848's field names, which describe CM848's detectors; J90350.00 has no reader for them in the dump, only the same VSMVEN / VSSTEN records.
- Word 12 bit 5 keeps CM848's reverse_electronic_smart_power_enable (label Reverse_ESP_Enable); CM550's own text and code say ESP launch application (tau source state 1 of NORMAL / LAUNCH / STEEP).
- Word 12 bit 1 is overspeed_fuel_shutoff_enable in both firmwares (the CM848 rename), parallel to W1's word 0 bit 6 engine_retarder_fuel_shutoff_enable: the two bits gate the same fuel shutoff decision at 0x1ca54.
- Word 13 bit 0 has no 106B record. I named it key_switch_override_enable because the code proves it: the byte mask [1] applies to all eight bits of status byte 0, and bit 0 of that byte is the key switch (000E DSKYSWSS; the engine state and power-down code read it as the key). If a bit needs its own 106B record to be named, make it reserved_bit_0 and keep this as the guess.
- Words 13 / 14: a bit is named for a function when its own 106B record names that function (by text or by a mnemonic that the 000E / 12A8 / 12FC / 1234 records of the same logical switch spell out) or when the code proves it. Where the 106B record gives only a switch number, the name is switch_N_override_enable with the e2m's switch number (word 14 bits 0 / 10 / 12 / 15) and the other blocks' aliases are guesses in the comment. Word 14 bit 11 has two complete alias sets (AC high pressure switch and throttle interlock), so it is switch_28_override_enable.
- Accelerator interlock: the J1939 descriptor table (ROM 0x20108 entry 1 = JCTHILMU, the multiplexed throttle interlock value) drives logical switch 9, so word 13 bit 9 is the accelerator interlock override. The e2m's DSTHILUO (group MUX_PARA) puts it at word 14 bit 11; that group's other 106B record MXLPANEA is also off by one word against the code (W4).
- Word 14 bit 9 has a 76-character name, switched_throttle_control_or_all_speed_governor_droop_switch_override_enable, because the e2m's 'STCG ASG DROOP SWITCH' is one switch with two roles (word 27 bit 3 picks the switched throttle control governor or the all speed governor droop). The shorter switched_throttle_control_governor_droop_switch_override_enable drops the all speed governor half.

SIBLING CONSISTENCY (please reconcile).
- W3's word 16 uses cruise_control_resume_switch_override_enable and cruise_control_set_switch_override_enable for the DECODED cruise status bits (0x80bcd4). Word 13 bits 1 / 2 are the raw switches that the e2m gives exactly those names (DSCRRUUO / DSCRSEUO). Two structs may share a field name, but the two layers should not: I suggest renaming W3's (for example cruise_control_resume_status_override_enable).
- W3 writes air_conditioner_ (word 15 bit 11, word 17 bit 8). I used air_conditioning_, as CM848 (air_conditioning_switch, fan_air_conditioning_pressure_enable), W1 and W4 do.
- Engine brake: W1 / W4 say engine_retarder_ for EB records, W3 says engine_brake_relay_. For the switch I used engine_brake_select_1_ because CM848's own switch record is Engine_Brake_Select_1 (and its switch_input_state_t has engine_brake_driver_1_feedback).
- The row comments call word 0 'word 0 (0x803c94)' because W1 renames it; put the final row name in if you prefer.

E2M TEXT CAVEATS. v64t6_s cuts descriptions at about 50 characters. Completions in parentheses come from longer copies of the same record in other e2m files (42t9_rls, the CHR files) for word 7, EPFT*, EPOSFSO, SPRVEN, PTBRODEN / PTCHODEN (their bit letters B / C), LSCIIHEN (bit 14) and the DS..UO switch records; for EPWF / EPBS / EPFP / EPAA no longer copy exists (33 files, all cut) and the completion comes from the record's SOEN sibling. Texts that contradict their own record: EPBSFLEN (engine sync text on the boost record), DSPRBRUO (manual fan text on the parking brake record), DSAKONUO (the status record's text), EPCQRPEN 'BIT 5 OF 5-15', EPFTSOEN 'BIT 14 OF 0-14'. One counter-witness on the parking brake (word 14 bit 7, logical switch 23): block 12FC lists its default DSDFPRBR at mask 0x80000 (logical switch 19, next to the remote throttle switch) and only 'SWITCH 24' at bit 23, against three records at 23 (000E value DSPRBRUC, 12A8 +17 DSPZPRBR, 1234 DSPRBRIV) and the 106B mnemonic. Quotes are comma-stripped for the CSV. EDF is spelled out by the e2m's own group record 12C (ENDTFL07 'ENGINE DATA FILES ENABLE AND POWER-DOWNS'), ESP by group 43 (ESP_08 'ELECTRONIC SMART POWER GROUP'), PTP by group PTP_07, STCG by STCGASDS.

'NO READER' always means none in the dumped 256 KB (109 call targets above 0x40000 are not dumped). Word 12 has bits 7 / 8 / 9 / 11 / 12 / 13 / 15 set in the calibration with no reader in the dump.

RENDERING RISKS (I could not build). Value-flow forms that may print as pieces once typed: word 8 2 of 2 tests; word 11 3 CONCAT22 forms; word 12 5 assigned / returned values + 1 CONCAT22; word 13 2 + 1 CONCAT22; word 14 1 of 1. Word 7's single test is plain. Word 13's address is stored in discrete_input_override_mask_ptr as the base of byte reads that run through words 13-17 (W3 covers [4] / [5] / [9]); as a 2-byte struct that assignment may print with a cast. The 15 indexed tests print through word 0's symbol and are unaffected as long as word 0 stays a plain word.

STALE CITATIONS OF THE OLD NAMES. firmware/CM550_J90350.00_analysis/output/function_renames.csv line 170 (cm550_initializeDiscreteInputs: 'points discrete_input_override_mask_ptr at switch_override_configuration') and line 257 (cm550_updateElectronicSmartPowerTau: 'runs while calibration_feature_enable_flags_word_9 bit 0x10 is set'); firmware_globals.hpp lines 1456-1458 regenerate. No other live CSV or doc cites the three names (the context_tier1 / context_tier2 folders and the session archives are snapshots).

CM848. One rename: algorithm_enable_flags_12_t bit 1. Nothing else qualifies: bits 14 / 15 of word 12 and bit 4 of word 11 have no record in CM848's own e2m and no CM848 reader (EDF_Enable 0x8000 exists only in the CHR_B2 files, a different module), and words 7 / 8 are plain words there.

LEADS (not renamed here). processDiagnosticLimitStatus = the engine protection shutdown (twin cm848_updateEngineProtectionShutdown); cm550_diagnosticProtectionEvaluator = the examination before cranking (twin cm848_examineEngineProtectionBeforeCranking; it sets 0x80d28a = e2m 10B1 +10 EPPKSO); cm550_protectionState1DiagnosticValidator = twin cm848_updateEngineProtectionRestartSeverity; cm550_FUN_00019702 = twin cm848_calculateFaultDerateFuelLimit; vp44_FUN_0001cad6 = the fuel temperature protection input; cm550_fuelDemandLimitSelector11 / vp44_canPinVp44StatusController = the fuel shutoff driver command; vp44FaultRegisterBit2Monitor = the water in fuel monitor; cm550_FUN_00026616 = the cold idle speed adder (0x80db08 = e2m 1049 +6 LSCIOD, no row); vp44State2TransitionHandler / cm550_FUN_000184c6 = the J1939 torque curve speed points (twin cm848_calculateFaultDerateJ1939TorqueCurveSpeedPoints; 0x80daf4 = LSDPSE the selected low speed governor droop slope, no row); cm550_engineRunTimeHistogramAccumulator = the J1939 periodic transmit schedule; mc68k_FUN_000212b2 = the J1939 receive dispatch; cm550_diagnosticMessageTransmissionManager = the periodic J1922 / J1587 transmissions; cm550_FUN_00020890 = twin cm848_evaluateJ1939InputSignalFault. The four switch status bytes carry one bit's e2m name each (0x80bcce value_used_for_monitoring_switch_data..., 0x80bccf debounced_switch_value_for_switch_16..., 0x80bcd0 debounced_value_for_rear_axle_ratio_switch..., 0x80bcd1 state_of_the_throttle_interlock_switch...): they are switch status bytes 0-3 (logical switches 0-31). high_horsepower_mode_state 0x80d2b6 is e2m SPTUST, the ESP tau source.

ASIDE. Word 20 (0x803cbc) is in no batch but has a direct test: andi.w #0x200 at 0x20fd8 (cm550_FUN_00020fac, the J1939 wet tank pressure into analog_sensor_raw_override_values[0]). v64t6_s has no 106B +2A record; six other ISB e2m files have AD25OD 0x200 'BIT 9 OF 0-15. A/D CHANNEL 25 OVERRIDE' there.

SCRATCH. /home/linux/.claude/jobs/374b0424/tmp/w15/r92/scratch/W2/v2/: direct_tests.py (the reference scan), survey_e2m.py (every e2m file's 106B records per offset) with survey_*.txt, switch_xref.py + switch_xref.txt (logical switches 0-31 over 106B / 000E / 12A8), dump_values.py and channel_inputs.py (the dumps), showfn.py, switch_fields_v2.py + build_result_v2.py which writes result_W2.json (the validated copy of this result). The files one level up are an earlier draft of this batch; every claim here was re-derived."""
result["notes"] = NOTES

# ------------------------------------------------------------------------------------------------ validation
problems = []
BANNED = re.compile(r"(^|_)(pto|afc|egr|ecm|vss|esp|lsg|hsg|ptp|stcg|asg|fso|imt|ac|ak|edf|ocm|init|mux|cc)(_|$)")
cm848 = {}
p = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/structure_definitions.csv")
for row in csv.reader(open(p, newline="")):
    if len(row) > 3 and re.match(r"^algorithm_enable_flags_\d+_t$", row[0]):
        m = re.match(r"^bitfield:1@(\d+)$", row[3])
        if m:
            cm848.setdefault(row[0], {})[int(m.group(1))] = row[2]
cpp = open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/J90350.00.ghidra.cpp"), errors="replace").read()
cpp_ids = set(re.findall(r"[A-Za-z_][A-Za-z0-9_]*", cpp))
globals_550 = {r[1] for r in csv.reader(open(os.path.join(
    repo, "firmware/CM550_J90350.00_analysis/output/global_variables.csv"), newline="")) if len(r) > 1}
for w in result["words"]:
    f = w["fields"]
    bits = sorted(x["bit"] for x in f)
    if bits != list(range(16)):
        problems.append(f"word {w['word']}: bits {bits}")
    names = [x["name"] for x in f]
    if len(set(names)) != 16:
        problems.append(f"word {w['word']}: duplicate field names")
    for x in f:
        n = x["name"]
        if not re.fullmatch(r"[a-z][a-z0-9]*(_[a-z0-9]+)*", n):
            problems.append(f"word {w['word']} bit {x['bit']}: not snake_case: {n}")
        if BANNED.search(n):
            problems.append(f"word {w['word']} bit {x['bit']}: banned token in {n}")
        if re.search(r"0x|[0-9]x[0-9a-f]", n):
            problems.append(f"hex in name {n}")
        if "," in x["comment"]:
            problems.append(f"word {w['word']} bit {x['bit']}: comma in comment")
        if '"' in x["comment"]:
            problems.append(f"word {w['word']} bit {x['bit']}: double quote in comment")
        if n.startswith("reserved_bit_") and n != f"reserved_bit_{x['bit']}":
            problems.append(f"word {w['word']} bit {x['bit']}: reserved name mismatch {n}")
        if n in cpp_ids or n in globals_550:
            problems.append(f"word {w['word']} bit {x['bit']}: {n} is already an identifier in the CM550 .cpp / globals")
    w["fields"] = sorted(f, key=lambda x: x["bit"])
    ref = cm848.get(f"algorithm_enable_flags_{w['word']}_t")
    if w["shared_with_cm848"]:
        if not ref:
            problems.append(f"word {w['word']}: shared but CM848 has no type")
        else:
            for b in range(16):
                if ref[b] != w["fields"][b]["name"]:
                    problems.append(f"word {w['word']} bit {b}: {w['fields'][b]['name']} != CM848 {ref[b]}")
        if w["proposed_type"] != f"algorithm_enable_flags_{w['word']}_t":
            problems.append(f"word {w['word']}: shared type name")
    elif w["proposed_type"] not in ("word", f"cm550_algorithm_enable_flags_{w['word']}_t"):
        problems.append(f"word {w['word']}: type name {w['proposed_type']}")
    if w["proposed_name"] != f"algorithm_enable_flags_{w['word']}_cal":
        problems.append(f"word {w['word']}: row name")
    if int(w["address"], 16) != 0x803c94 + 2 * w["word"]:
        problems.append(f"word {w['word']}: address")
    for key in ("row_comment", "differences_from_cm848", "code_tests", "writes"):
        if '"' in w[key]:
            problems.append(f"word {w['word']}: double quote in {key}")
    # dump state words in the comments against the dump
    dump = {7: W7_DUMP, 8: W8_DUMP, 9: W9_DUMP, 11: W11_DUMP, 12: W12_DUMP, 13: W13_DUMP, 14: W14_DUMP}[w["word"]]
    for x in w["fields"]:
        c = x["comment"]
        tail = c.rsplit(";", 1)[-1]
        said_set = bool(re.search(r"\bset\b", tail)) and "clear" not in tail
        said_clear = "clear" in tail
        actual = bool(dump >> x["bit"] & 1)
        if said_set == said_clear or said_set != actual:
            problems.append(f"word {w['word']} bit {x['bit']}: dump state in comment tail '{tail.strip()}' vs {actual}")
for r in result["cm848_field_renames"]:
    t = cm848.get(r["type_name"], {})
    if t.get(r["bit"]) != r["current_field"]:
        problems.append(f"rename: {r['type_name']} bit {r['bit']} is {t.get(r['bit'])}")
    cm848_cpp = open(os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp"),
                     errors="replace").read()
    if re.search(r"\b" + re.escape(r["proposed_field"]) + r"\b", cm848_cpp):
        problems.append(f"rename target {r['proposed_field']} already in the CM848 .cpp")
    own = [w for w in result["words"] if w["word"] == 12][0]["fields"][r["bit"]]["name"]
    if own != r["proposed_field"]:
        problems.append("rename target differs from the CM550 field")
flat = json.dumps(result, ensure_ascii=False)
bad = sorted({c for c in flat if ord(c) > 127})
if bad:
    problems.append(f"non-ASCII characters: {bad}")
if "&" in flat:
    problems.append("'&' in the result")
if "<" in flat:
    problems.append("'<' in the result")
if "\t" in flat or "\\t" in flat:
    problems.append("tab in the result")
out = os.path.join(HERE, "result_W2.json")
json.dump(result, open(out, "w"), indent=1)
print("written", out, os.path.getsize(out), "bytes")
print("PROBLEMS:" if problems else "validation: 0 problems")
for pr in problems:
    print("  ", pr)
for w in result["words"]:
    named = [x for x in w["fields"] if not x["name"].startswith("reserved_bit")]
    longest = max(len(x["comment"]) for x in w["fields"])
    print(f"word {w['word']:>2} {w['address']} {w['proposed_name']} {w['proposed_type']} shared={w['shared_with_cm848']} "
          f"named={len(named)} longest comment {longest} longest name {max(len(x['name']) for x in w['fields'])}")
