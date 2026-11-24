# C1 skeptic draft verdicts (scratch)

All 28 e2m records resolve to the proposed addresses (e2m_block_addresses.py --address).
No proposed name collides in CM550 global_variables / function_renames / structure_definitions.
No address is in the EEPROM mirror 0x803b0a-0x804155: no _cal anywhere.

AMENDED
- 0x805562 DGCLLVLF -> coolant_level_engine_protection_fault_log word[20]
  coolant level config 0x807032 flags = 0x1151 (bit 0x1000 set): cm550_protectionState3bRpmMonitor
  sends either condition (bVar1 fueling OR bVar2 engine speed) to protectionStateProcessor(0) / Validator(0),
  i.e. the +0x26 log; the +0x2a pointer 0x80d106 is never stored (0 in the dump). CM848 configuration_flags:
  "0x1000 the engine speed fault shares the fueling fault log". The log is the channel's only log for both
  conditions - same reason the proposer dropped the qualifier for DGCLTPLF; e2m wording also matches
  (KEEPS HISTORY OF COOLANT_LEVEL_FAULT INFO vs the 'LOG OF FAULT TO SET FUEL INDEX' records).

CONFIRMED: the other 27 (see the StructuredOutput reasons).

Width checks done: 0xb0ca move.w (0,a0,d0.w*2) base 0x80539e; 0x18766 / 0x1879e / 0x187a6 / 0x18802 / 0x1880a
log pointer stores; 0x14a6e addq.b 0x8058d4, 0x14a74 addq.w 0x805914, 0x14a1a subq.b 0x8058f4, 0x14a20 subq.w 0x805954,
0x14cd6 cmpi.b #31; 0x146fa cmp.l + bls on 0x805a1c; descriptors 0x80a7f4 / 0x80a802 (dump: x 0x806ebe / y 0x806ed0,
x 0x806ee2 / y 0x806ee8); 0x34d18 y ptr 0x80721e; 0x801aba grid ptr 0x80794e (dump), axes 4 + 4 points, 16 words;
0xce3a / 0xce50 cmp.w + blt, ext.l / neg.l, 0xced6 muls.w 0x807ac0; 0xc8dc moveq 0 / move.w / neg.l 0x807ac6;
0xd1be-0xd1d4 mode x 18 + 0x807b92; 0xd1f8 / 0xd202 copies; 0xd560 / 0xd56a copies; 0xacc2 / 0xacd0 cmp.w + bcc.
