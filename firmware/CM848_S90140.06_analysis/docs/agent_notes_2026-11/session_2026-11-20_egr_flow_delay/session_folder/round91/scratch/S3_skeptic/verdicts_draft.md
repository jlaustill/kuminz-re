# S3 skeptic - draft verdicts (independent re-check)

Tools: capstone 5.0.7 m68k (scratch venv), scripts in scratch/S3_skeptic/scripts (dis.py, find_const.py,
base_reg_scan.py, branch_targets.py, dump_words.py). Listing: asg.txt (0xc962-0xd0e2, 0 undecoded words).

- struct all_speed_governor_gain_set_t: CONFIRMED. 9 pointer loads; reads +0..+16 words only; signed
  (ext.l / muls.w; +12/+14 cmp.w neutral). 0xcaf0 (a0) is the filter coefficient pointer 0x80a984, not the set.
  e2m 54 records N/2/S. CM848 template 9 x short, same order. short -> ShortDataType.
- 0x807b92 [4]: CONFIRMED. 0x807b92 + 72 = 0x807bda (next row). Index 0x80da66 written only at 0x2f34c
  ((byte 0x801d4c & 0xc) >> 2, inside processEngineTsc1Request) + clears 0x1f5d8 / 0x1f9a6.
- 0x807be0 throttle set: CONFIRMED (add.w is at 0xd450, comment cites 0xd44c for the pair - trivial).
- 0x80a95a application set: CONFIRMED. 0xd0fc has no caller of its own.
- 0x80a9a8 pointer: AMENDED (comment). 12 absolute hits = 9 loads + 3 stores; no base-register access.
  Governor also runs in state 3 (cmpi.w #3 @ 0xc982); no dumped-ROM writer stores 3 to 0x80ded4
  (writers: 0x1e @ d19e, 2 @ d1b8, 7 @ d53c, 8 @ 1c63a, 6 @ 25848, 1 @ 34554, 5 @ 3457c, clr @ 34594, copy-out @ 2dce4).
  Dump: 0x80ded4 = 6, 0x8000fe = 6, 0x80a98e = 7, 0x80a984 coefficient pointer = 0.
- 0x80a93c comment: CONFIRMED (0xcb84 -> d5 in cmpi.w #1,(0x80a9a0) branch; 0xcff8 move.w d5,d0; 0xcffa muls.w (16,a2)).
- 16 rows to remove: CONFIRMED; only 0x807be4 / 0x807be6 have a user (0xd44c / 0xd450 via a5 = 0x807be0), and
  they are the instance's own fields.
