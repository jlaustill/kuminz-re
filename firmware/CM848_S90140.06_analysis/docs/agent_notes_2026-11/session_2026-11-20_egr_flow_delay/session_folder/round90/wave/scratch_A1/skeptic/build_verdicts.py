#!/usr/bin/env python3
"""Build the batch A1 skeptic verdicts from one table of re-checked facts.

Every fact below was re-derived in this session:
- address -> e2m record: e2m_block_addresses.py --firmware cm550 --address (12E8 +6 = 0x803f9c, slot = offset - 6)
- handler / registration: dis.py on 0x21a5c-0x21ef6 (pea handler; move.w #PGN; jsr (a2) with a2 = 0x21272)
- reference count: absrefs.py (2 absolute references per byte, both in its handler)
- timeout word / receiver byte / data byte and bits: dis.py of each handler block
- 12F6 timer record = EEPROM 0x72a + 2 x slot = RAM 0x803B0A + 0x72A + 2 x slot = 0x804234 + 2 x slot
- 12F7 receiver record: e2m_block_addresses.py --firmware cm550 12F7 (+0 = 0x80d70c)
- CM848 twin: cm848_rom.ghidra.cpp handlers (same slot / byte / bits / reload value)
- dumps: J90350.00.ram.bin and J90350.00.eeprom.bin (EEPROM offset = address - 0x803b0a), all 0xFF
"""
import json
import sys

ROOT = '/home/linux/.claude/jobs/374b0424/tmp/w15/r90/wave/scratch_A1'
loaded = json.load(open(ROOT + '/proposals.json'))
proposals = {'proposals': loaded} if isinstance(loaded, list) else loaded
by_address = {p['address'].lower(): p for p in proposals['proposals']}

HANDLERS = {
    61441: ('0x21a8c', 'cm550_FUN_00021a8c', 'EBC1', 'cm848_receivePgn61441ElectronicBrakeController1Message'),
    61443: ('0x21b88', 'cm550_FUN_00021b88', 'EEC2', 'cm848_receivePgn61443ElectronicEngineController2Message'),
    65264: ('0x21c74', 'cm550_FUN_00021c74', 'PTO', 'cm848_receivePgn65264PowerTakeoffInformationMessage'),
    65265: ('0x21d44', 'cm550_FUN_00021d44', 'CCVS1', 'cm848_receivePgn65265CruiseControlVehicleSpeedMessage'),
}

# address, slot, filter mnemonic, Calterm name, PGN, J1939 position, SPN text ('' = not in the local database),
# timeout reload, timer mnemonic, receiver address, receiver mnemonic, move.b address, cmpi.b address, final name
ROWS = [
    (0x803f9d, 1, 'MXRTSWSA', 'Remote_Throttle_Switch_Source_Address_Enable', 61441, 'byte 4 bits 7-8',
     'SPN 969 Remote Accelerator Enable Switch', 50, 'MXRTSWTR', 0x80d723, 'JCRTSWMU', 0x21a98, 0x21aa2,
     'j1939_remote_accelerator_enable_switch_source_address_filter_cal'),
    (0x803f9e, 2, 'MXAUSHSA', 'Aux_Shutdown_Switch_Source_Address_Enable', 61441, 'byte 4 bits 5-6',
     'SPN 970 Engine Auxiliary Shutdown Switch', 50, 'MXAUSHTR', 0x80d711, 'JCAUSHMU', 0x21aca, 0x21ad4,
     'j1939_engine_auxiliary_shutdown_switch_source_address_filter_cal'),
    (0x803f9f, 3, 'MXTQSWSA', 'Torque_Derate_Switch_Source_Address_Enable', 61441, 'byte 4 bits 3-4',
     'SPN 971 Engine Derate Switch', 50, 'MXTQSWTR', 0x80d725, 'JCTQSWMU', 0x21afc, 0x21b06,
     'j1939_engine_derate_switch_source_address_filter_cal'),
    (0x803fa0, 4, 'MXTHILSA', 'Accel_Interlock_Switch_Source_Address_Enable', 61441, 'byte 4 bits 1-2',
     'SPN 972 Accelerator Interlock Switch', 50, 'MXTHILTR', 0x80d710, 'JCTHILMU', 0x21b2e, 0x21b38,
     'j1939_accelerator_interlock_switch_source_address_filter_cal'),
    (0x803fa1, 5, 'MXEBLVSA', 'EB_Switch_Level_Source_Address_Enable', 61441, 'byte 5',
     'SPN 973 Engine Retarder Selection', 50, 'MXEBLVTR', 0x80d719, 'JCEBSWMU', 0x21b5c, 0x21b66,
     'j1939_engine_retarder_selection_source_address_filter_cal'),
    (0x803fa2, 6, 'MXISSWSA', 'Idle_Switch_Source_Address_Enable', 61443, 'byte 1 bits 1-2',
     'SPN 558 Accelerator Pedal 1 Low Idle Switch', 25, 'MXISSWTR', 0x80d71a, 'JCISSWMU', 0x21b94, 0x21b9e,
     'j1939_accelerator_pedal_1_low_idle_switch_source_address_filter_cal'),
    (0x803fa3, 7, 'MXCMTHSA', 'Commanded_Throttle_Source_Address_Enable', 61443, 'byte 2',
     'SPN 91 Accelerator Pedal Position 1', 25, 'MXCMTHTR', 0x80d714, 'JCCMTHMU', 0x21bc0, 0x21bca,
     'j1939_accelerator_pedal_position_1_source_address_filter_cal'),
    (0x803fa4, 8, 'MXROTHSA', 'Remote_Throttle_Source_Address_Enable', 61443, 'byte 4',
     'SPN 974 Remote Accelerator Pedal Position', 25, 'MXROTHTR', 0x80d722, 'JCRTTHMU', 0x21be8, 0x21bf2,
     'j1939_remote_accelerator_pedal_position_source_address_filter_cal'),
    (0x803fa5, 9, 'MXWTPRSA', 'Wet_Tank_Pressure_Source_Address_Enable', 61443, 'byte 5',
     '', 25, 'MXWTPRTR', 0x80d720, 'JCWTPRMU', 0x21c10, 0x21c1a,
     'j1939_wet_tank_pressure_source_address_filter_cal'),
    (0x803fa7, 11, 'MXRXSWSA', 'Remote_PTO_Switch_Source_Address_Enable', 65264, 'byte 6 bits 3-4',
     '', 50, 'MXRXSWTR', 0x80d721, 'JCRXSWMU', 0x21c80, 0x21c8a,
     'j1939_remote_power_take_off_switch_source_address_filter_cal'),
    (0x803fa8, 12, 'MXPTONSA', 'PTO_On_Switch_Source_Address_Enable', 65264, 'byte 6 bits 1-2',
     '', 50, 'MXPTONTR', 0x80d71d, 'JCPTONMU', 0x21cb2, 0x21cbc,
     'j1939_power_take_off_on_switch_source_address_filter_cal'),
    (0x803fa9, 13, 'MXPTRUSA', 'PTO_Resume_Switch_Source_Address_Enable', 65264, 'byte 7 bits 5-6',
     '', 50, 'MXPTRUTR', 0x80d71e, 'JCPTRUMU', 0x21ce0, 0x21cea,
     'j1939_power_take_off_resume_switch_source_address_filter_cal'),
    (0x803faa, 14, 'MXPTSESA', 'PTO_Set_Switch_Source_Address_Enable', 65264, 'byte 7 bits 1-2',
     '', 50, 'MXPTSETR', 0x80d71f, 'JCPTSEMU', 0x21d12, 0x21d1c,
     'j1939_power_take_off_set_switch_source_address_filter_cal'),
    (0x803fab, 15, 'MXCHSWSA', 'Clutch_Switch_Source_Address_Enable', 65265, 'byte 4 bits 7-8',
     'SPN 598 Clutch Switch', 50, 'MXCHSWTR', 0x80d713, 'JCCHSWMU', 0x21d50, 0x21d5a,
     'j1939_clutch_switch_source_address_filter_cal'),
    (0x803fac, 16, 'MXBRSWSA', 'Brake_Switch_Source_Address_Enable', 65265, 'byte 4 bits 5-6',
     'SPN 597 Brake Switch', 50, 'MXBRSWTR', 0x80d712, 'JCBRSWMU', 0x21d82, 0x21d8c,
     'j1939_brake_switch_source_address_filter_cal'),
    (0x803fad, 17, 'MXCRONSA', 'Cruise_On_Switch_Source_Address_Enable', 65265, 'byte 4 bits 3-4',
     'SPN 596 Cruise Control Enable Switch', 50, 'MXCRONTR', 0x80d715, 'JCCRONMU', 0x21db4, 0x21dbe,
     'j1939_cruise_control_enable_switch_source_address_filter_cal'),
    (0x803fae, 18, 'MXCRRUSA', 'Cruise_Resume_Switch_Source_Address_Enable', 65265, 'byte 5 bits 5-6',
     'SPN 601 Cruise Control Resume Switch', 50, 'MXCRRUTR', 0x80d716, 'JCCRRUMU', 0x21de6, 0x21df0,
     'j1939_cruise_control_resume_switch_source_address_filter_cal'),
    (0x803faf, 19, 'MXCRSESA', 'Cruise_Set_Switch_Source_Address_Enable', 65265, 'byte 5 bits 1-2',
     'SPN 599 Cruise Control Set Switch', 50, 'MXCRSETR', 0x80d717, 'JCCRSEMU', 0x21e18, 0x21e22,
     'j1939_cruise_control_set_switch_source_address_filter_cal'),
    (0x803fb0, 20, 'MXICSWSA', 'Increment_Switch_Source_Address_Enable', 65265, 'byte 8 bits 1-2',
     'SPN 968 Engine Idle Increment Switch', 50, 'MXICSWTR', 0x80d71b, 'JCICSWMU', 0x21e46, 0x21e50,
     'j1939_engine_idle_increment_switch_source_address_filter_cal'),
    (0x803fb1, 21, 'MXDTSWSA', 'Decrement_Switch_Source_Address_Enable', 65265, 'byte 8 bits 3-4',
     'SPN 967 Engine Idle Decrement Switch', 50, 'MXDTSWTR', 0x80d718, 'JCDTSWMU', 0x21e74, 0x21e7e,
     'j1939_engine_idle_decrement_switch_source_address_filter_cal'),
    (0x803fb2, 22, 'MXTESWSA', 'Test_Switch_Source_Address_Enable', 65265, 'byte 8 bits 5-6',
     'SPN 966 Engine Diagnostic Test Mode Switch', 50, 'MXTESWTR', 0x80d724, 'JCTESWMU', 0x21ea6, 0x21eb0,
     'j1939_engine_diagnostic_test_mode_switch_source_address_filter_cal'),
]

# the signal words in the name, for the comment's first clause
SIGNAL_WORDS = {
    1: 'remote accelerator enable switch', 2: 'engine auxiliary shutdown switch', 3: 'engine derate switch',
    4: 'accelerator interlock switch', 5: 'engine retarder selection', 6: 'accelerator pedal 1 low idle switch',
    7: 'accelerator pedal position 1', 8: 'remote accelerator pedal position', 9: 'wet tank pressure',
    11: 'remote power take-off switch', 12: 'power take-off on switch', 13: 'power take-off resume switch',
    14: 'power take-off set switch', 15: 'clutch switch', 16: 'brake switch', 17: 'cruise control enable switch',
    18: 'cruise control resume switch', 19: 'cruise control set switch', 20: 'engine idle increment switch',
    21: 'engine idle decrement switch', 22: 'engine diagnostic test mode switch',
}

verdicts = []
problems = []
for (address, slot, mnemonic, calterm, pgn, position, spn, reload, timer, receiver, receiver_mnemonic,
     move_address, compare_address, name) in ROWS:
    key = '0x%08x' % address
    p = by_address.get(key)
    if p is None:
        problems.append('%s: not in proposals' % key)
        continue
    if p['proposed_name'] != name or p['proposed_type'] != 'byte':
        problems.append('%s: proposal says %s %s' % (key, p['proposed_name'], p['proposed_type']))
    if address - 0x803f9c != slot:
        problems.append('%s: slot %d does not match the address' % (key, slot))
    offset = slot + 6
    timeout_word = 0x804234 + 2 * slot
    timer_offset = 2 * slot
    receiver_offset = receiver - 0x80d70c
    handler_address, handler_name, acronym, cm848_handler = HANDLERS[pgn]
    eeprom_offset = address - 0x803b0a
    where = 'PGN %d %s %s' % (pgn, acronym, position)
    if spn:
        where += '; %s' % spn
    signal = SIGNAL_WORDS[slot]
    comment = (
        'EEPROM-backed source address that the J1939 %s input (%s) is accepted from (0xFF = any source; 0xFF in '
        'the RAM and EEPROM dumps): e2m 12E8 +%X %s (Calterm %s) = slot %d of the filter bytes 0x803f9c-0x803fb2 '
        '(CM848 j1939_input_source_address_filter_cal[%d] in %s). '
        'The %s receive handler %s (%s; registered for PGN %d by cm550_FUN_00021ef6) compares it with '
        'can_received_source_address and with 0xFF; on a match it reloads timeout word 0x%x with %d '
        '(12F6 +%X %s by slot order) and stores the signal in 0x%x (12F7 +%X %s)'
        % (signal, where, offset, mnemonic, calterm, slot, slot, cm848_handler,
           acronym, handler_name, handler_address, pgn, timeout_word, reload, timer_offset, timer,
           receiver, receiver_offset, receiver_mnemonic))
    if slot == 9:
        comment += (
            '; its one consumer cm550_FUN_00020fac converts it at 5 kPa per bit (x 9282 / 100 = psi x 128; the '
            'pedal inputs use 0.4 %/bit) so the slot is a pressure as the e2m says. That consumer writes 0x80a760 '
            '(12D3 +0 ADIMTPUR) whose intake manifold temperature label is unresolved')
    if ',' in comment:
        problems.append('%s: comment has a comma' % key)
    reason = (
        'Re-checked: resolver 12E8 +%X %s -> 0x%x (slot %d); move.b @ 0x%x and cmpi.b #255 @ 0x%x are the only '
        'two ROM references (byte equality compares); 0x21ef6 registers %s for PGN %d; the handler stores %s '
        'into 0x%x and reloads 0x%x = %d exactly as CM848 slot %d does; name unique; EEPROM mirror (EEPROM '
        '0x%x = 0xFF) so _cal is right.'
        % (offset, mnemonic, address, slot, move_address, compare_address, handler_address, pgn, position,
           receiver, timeout_word, reload, slot, eeprom_offset))
    if slot == 9:
        reason += (
            ' Slot 9 identity: three e2m records agree (MXWTPRSA filter / MXWTPRTR timer = 0x804246 / JCWTPRMU '
            'value = 0x80d720) in both firmwares\' e2m files; the only consumer (cm550_FUN_00020fac: timeout '
            'bit 9 in 0x800aa4 / error bit 9 in 0x800aa0 / enable bit 9 of 0x803cbc) converts at 5 kPa per bit, '
            'which rules out SPN 29 (0.4 %/bit) and an IMT reading (degrees). J1939-71 (local database) lists '
            'EEC2 byte 5 as SPN 29 Accelerator Pedal Position 2 at 0.4 %/bit, and CM848 names its slot 9 '
            'receiver 0x40aaba j1939_received_accelerator_pedal_position_2 from that position only (one writer '
            'in cm848_receivePgn61443ElectronicEngineController2Message and no reader; its own e2m record there '
            'is 12F7 +14 J1939_Mux_Wet_Tank_Pressure), so that name is not reused here. The A/D loop '
            'mc68k_processAnalogSensorChannels uses 0x80a760 + 2 x channel as channel 0\'s raw override, so '
            'that destination label stays a separate open question; it does not change the filter\'s name.')
    if slot == 2:
        reason += (
            ' Flat rows kept for the whole batch: every handler reads its byte at the absolute address (no index '
            'and no pointer walk), so the type follows the access; one byte[23] row at 0x803f9c named like '
            'CM848\'s j1939_input_source_address_filter_cal is the alternative (it would also cover slots 0 and '
            '10) but not clearly better, and no array verdict is added.')
    verdicts.append({
        'address': key,
        'verdict': 'CONFIRMED',
        'final_name': name,
        'final_type': 'byte',
        'comment': comment,
        'reason': reason,
    })

if len(verdicts) != len(proposals['proposals']):
    problems.append('verdict count %d != proposal count %d' % (len(verdicts), len(proposals['proposals'])))
if problems:
    print('\n'.join(problems))
    sys.exit(1)
out = {'batch': 'A1', 'verdicts': verdicts}
json.dump(out, open(ROOT + '/skeptic/verdicts.json', 'w'), indent=1)
print('wrote %d verdicts' % len(verdicts))
