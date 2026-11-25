W3 draft (scratch, not a report): words 15 16 17 18 19 22 23 of e2m 106B (CM550 0x803cb2..0x803cc3)

Access census (ROM absolute refs, all move.w abs.l reads; no writes):
- 0x803cb2 (w15) 0 refs; 0x803cb6 (w17) 0 refs; 0x803cba (w19) 0 refs
- 0x803cb4 (w16) 6x move.w + andi.w #0x1000/0x400/0x100/0x10/0x4/0x1 (mc68k_sampleAndDebounceDiscreteInputs 0x15394..0x15648)
- 0x803cb8 (w18) 20x move.w + andi.w/andi.l single bit (0x1 0x2 0x8 0x10 0x20 0x200 0x1000 0x2000)
- 0x803cc0 (w22) / 0x803cc2 (w23) 1x move.w -> d4 each (mc68k_processAnalogSensorChannels loop mask 1<<channel)
Indirect:
- discrete_input_override_mask_ptr = &switch_override_configuration (0x803cae): bytes [4]=0x803cb2 (w15 bits 8-15) [5]=0x803cb3 (w15 bits 0-7) [9]=0x803cb7 (w17 bits 0-7) used as byte masks raw&~m | value&m
- indexed bit tests (base 0x803c94): bit 0xd0+k (cm550_FUN_00020890 J1939 descriptor table; cm550_FUN_000206a8 k=0x20 0x21 0x36)
  -> w15 bit 0 / bit 1 (k 32 33), w16 bit 6 (k 54: J1939 entries 2 aux shutdown + 16 derate), w16 bits 8 10 12 (k 56 58 60 PTO), w17 bit 8 (k 72 A/C pressure)
Logical input k: status byte 0x80bcce + k/8 bit k%8; value 0x80bcd8 + k/8; priority 0x80bd4a + k (e2m 12A8 + k); enable table bit 208 + k.
Dump: w15 0 w16 0 w17 0 w18 0x303a w19 0x00c0 w22 0 w23 0

Decisions: w16 cm550 bitfield; w18 cm550 bitfield (CM848 type differs bits 1 4 5 / 7); w15 w17 w19 w22 w23 plain word.
