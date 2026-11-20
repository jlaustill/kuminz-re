"""One-off patch of items_b.py: item 21 plate / evidence."""
path = "/tmp/w14_functions3/items_b.py"
b = open(path).read()
old_start = b.index('"Forces the RAM refresh back on when it is safe to program (J1939 diagnostic service 22): with "')
old_end = b.index('        ),', old_start)
new_plate = (
    '"Forces an exit from development mode when it is safe to program (J1939 diagnostic service 22): with "\n'
    '            "not_safe_to_program_flag clear (engine stopped) it always turns the RAM refresh on (diagnostic_session_state = "\n'
    '            "ACTIVE, e2m 10C7 +0 RAM_Refresh_Enable = 1) and, only if cal_write_mode is 0xea (development mode), also "\n'
    '            "restores cal_write_mode = 0xee and j1939_standby_flag = SESSION_ACTIVE (e2m 1328 +0 Development_Mode = 0); it "\n'
    '            "returns DIAG_ACK. With the engine not stopped it returns DIAG_NACK_PROTECTED and changes nothing. Unlike "\n'
    '            "service 7 (0x21624) it does not require development mode to be on."\n')
b = b[:old_start] + new_plate + b[old_end:]
old = '"mode without requiring it (service 7 requires it). Registered as diagnostic service 22 (0x16). The owner\'s "'
assert old in b
new = (
    '"mode without requiring it (service 7 requires it); the only unconditional store is the refresh enable, so "\n'
    '            "cm848_forceEnableRamRefresh is the alternative name if the owner prefers that half. Registered as diagnostic "\n'
    '            "service 22 (0x16). The owner\'s "')
b = b.replace(old, new)
open(path, "w").write(b)
print("patched")
