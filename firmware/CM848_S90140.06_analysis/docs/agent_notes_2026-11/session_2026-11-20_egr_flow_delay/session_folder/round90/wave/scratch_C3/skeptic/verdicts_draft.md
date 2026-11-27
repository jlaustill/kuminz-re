# C3 skeptic verdict draft (independent decoder dis68k.py + scanall.py + checkbytes.py)
All 26 e2m records resolve to the proposed addresses (e2m_block_addresses.py --address).
All quoted opcode byte sequences match the ROM (checkbytes.py: bad 0); size bits hand-checked.
All names unique in CM550 global_variables.csv and across other batches' drafts.
CONFIRMED: a930 a93c a958 a976 a9da bad7 bad8 bba6 bcd5 bcd9 bd03 d0cc d0ce d0d0 d288 d334 d664 d714 da28 da54 da68 da6a de3e ded0 ded4
OPEN: d358 JCFSTLFG - CM848 name says not_available, code sends 0xFE = J1939 error indicator (0xFF = not available)
Notes: 0x1ab8e routine (CMSYBKSS==2 -> TPU ch1 HSR) is unreferenced; 0x1ab6a (cam sync ==2 -> ch10) is a callback stored in 0x80d090.
SYNC_STATE enum has no size column -> default 4 bytes in ApplyEnums: keep byte for cam sync states.

## After advisor round
- d358: CONFIRMED (CM848 reuse); 0xFE = J1939 error indicator noted in reason (rename both firmwares if improved).
- a93c: AMENDED type i16: only read (move.w $80a93c,d5 @ 0xcb84) feeds move.w d5,d0 / muls.w (16,a2),d0 @ 0xcff8 (signed). Decompile's asg_state_x6 = ASRSSTX6 is a d5 merge; no store to 0x80a980 in the reset branch.
- a958: AMENDED type i16 with its copy target (same quantity; CM848 twin i16).
- bad8 / bba6: AMENDED suffix _byte_length -> _byte_count (CM848 precedent data_collector_address_table_byte_count_cal 0x3fddc2; no byte_length names in either CSV).
- bcd9: extra writers confirmed: cm550_FUN_00020890 (J1939 multiplexed switch table 0x20108: switch indices 9/10/11/13/14/15 -> byte 1), cm550_FUN_00020e14 (bit 0 from the multiplexed idle switch). cm550_FUN_000206a8 calls (0x36,0x21,0x20) never hit byte 1.
- bd03: cm550_FUN_000206a8 reads driver byte 0 only; cm550_ioControlMaskStateMachine indexes 0x80bd1a priorities (48 outputs) -> bytes 0x80bcf6-0x80bcfb only; never +13.
- bcd5: cm550_FUN_00014872 index < 0x1f from 0x80bca8 (never 0x80bcd5); cm550_faultFlagScannerAndProcessor bit lists (0x807980/a0/c0, calibration) pick +0..+3,+5,+6,+9 in the dump, not +7.
- d0d0: 0x80d2a2/a4/a6 have no e2m record and no writer (all 0); 0x1ab8e unreferenced.
- 0xd0fc (cm550_fuelDeliverySystemInit) has no caller: it's the tail of cm550_diagnosticDataCopyHandler (called from cm550_acceleratorThrottleFaultDetector after clr 0x80a98e).
