# Batch D1 investigator - session 2 final decisions (round 93; appendix to notes.md)

- Wrappers: HEAD's schedule slot names (commit 7cf52470). 0x1b754 / 0x1b7f2 / 0x1b70c standalone (their CM848 slot
  mates share no task); 0x1b788 counterpart (its slot mate shares the two percent load calls).
- 0x266da keeps mc68k_runSerialEepromWriteQueue (incomplete, not wrong) with an extended plate comment;
  mc68k_runSerialEepromDriver only as a note.
- Lamp callees re-verified from the disassembly, not the decompiler (which misrendered 0x24858):
  0x24858 addi.w #0xa at 0x2492e on every step, addi.w #0x14 at 0x2495a at the table end, cmpi.b #0x80 / bhi at 0x24884;
  0x249ee cmpi.b #0x78 (120 cycles) at 0x24b22, cmpi.w #0xa / #0x13 at 0x24b02 / 0x24b10;
  0x24b4e phases 0x28 / 0x50 / 0x78 / 0xa0 at 0x24bca / 0x24bee / 0x24c12 / 0x24c36;
  0x25316 cmpi.w #5 (groups) at 0x2532a; 0x25448 cmpi.w #0x8ca0 (36000) at 0x2546a.
- Live CSV re-checked after the two typing commits (31f911b4, bf0c580d): all 56 proposed global rows still carry
  their frozen names (types only changed). Eight stale rows inside the long term map range 0x80546e-0x805539, none
  inside the two processing maps; stale rows inside the two lookup records, the two axis tables and the
  can_buffer_setup_t area are named in the comments / notes of the output.
- PGN 65252 SPN bit positions: the standard SAE layout (the local database has the parameter order only); the
  builder's bytes 2 - 4 agree with that order (SPN 591 by the enable bit, SPN 985 by the A/C switch, SPN 1081 by the
  wait to start lamp output).
- 0x26e2c: counterpart (CM848 0x50e000 adds the 0xff00 clamp); stem calculateEngineLoadLowHorsepowerCurvePercent.
- Output: draft_output.json, built by build_output.py + overrides.py; check_refs.py checks every identifier the
  output mentions; schema_check.py checks the required fields.
