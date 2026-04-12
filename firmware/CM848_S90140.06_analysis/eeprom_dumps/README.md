# HP Tuners EEPROM Flash Diff (2026-04-12)

Three-way EEPROM dump test to identify what HP Tuners wipes when flashing.
Goal: enable post-flash restore of odometer and engine hours for ELD compliance.

## Methodology

1. Dumped full 8KB EEPROM before any flash (`eeprom_before_hpt.bin`)
2. Flashed HP Tuners, dumped again (`eeprom_after_hpt_1.bin`)
3. Flashed HP Tuners *with the same tune*, dumped again (`eeprom_after_hpt_2.bin`)

Three-way comparison classifies every changed byte into:
- **Runtime counter**: non-zero before, zero in BOTH flashes → HPT wipes this
- **HPT variable write**: differs between flash1 and flash2 → checksums/counters
- **HPT deterministic write**: changed from before, but identical in both flashes → HPT writes a fixed value

## Summary

- **339 words** (678 bytes) zeroed by HPT (runtime counters, diagnostic data)
- **55 words** differ between flashes (HPT writes different values each time — checksums, calibration timestamps, flash counter at 0x0100005C)
- **69 words** deterministically overwritten (tune-specific values, odometer)

## Key findings

### Odometer — NOT just zeroed, HPT writes a NEW value

| Address | Before | After flash | Miles |
|---------|--------|-------------|-------|
| 0x01000BD8 (u32) | 0x03736429 | 0x02732900 | 7,236.74 → 5,137.70 |
| 0x01000BF8 (u32) | 0x04723110 | 0x01722900 | 9,324.07 → 3,032.35 |

Both odometer values are deterministically written by HPT (same in both flashes).
The written values likely come from the tune file itself — HPT probably stores
whatever value was in the tune when the user last "read" the ECU.

**Implication:** a restore tool must write the odometer AFTER every flash.
The address 0x01000BD8 is confirmed as the primary odometer (u32, × 0.000125 mi).

### Runtime counter blocks

HPT zeros these EEPROM regions:
- **0x08E8–0x08F6** — small runtime counters (unknown purpose, 4 words)
- **0x09C0–0x0B30** — large diagnostic/histogram block (mostly fault statistics,
  recognizable histogram bucket patterns at 0x0B10-0x0B28)
- **0x0BD8–0x0BFC** — odometer area (u32 values; HPT writes new values, doesn't zero)
- **0x0D00–0x0DC4** — DTC configuration (small values)
- **0x0E68–0x0FC0** — DTC snapshot data (contains 0x0AAE checksum markers)
- **0x1000–0x14BE** — DTC freeze frame records (two parallel sets at 0x1200-0x12FF and 0x1370-0x13FF)
- **0x1500–0x1A14** — adaptive calibration data (fuel trims, sensor adaptations, fault history)

### HPT change counter

`0x01000044` increments by exactly 10 (0x0A) with each flash — this is the
ECU's internal "number of calibration downloads" counter:
- Before:    0x012A (298)
- Flash 1:   0x0134 (308)
- Flash 2:   0x013E (318)

Similarly at 0x010009C4 (mirror) and 0x01000052/54 (flash session markers
incrementing by 1 each flash).

### Calibration checksum

`0x01000032` and related addresses are re-computed checksums — they're
different between flashes because the internal counter changed, so the
checksum of the calibration header changes too.

## Engine Hours — STILL NOT FOUND in EEPROM

Despite finding 339 zeroed words, **no obvious engine hours counter** appeared
in the diff. The values in the 0x09C0-0x0B30 region are too small (most < 1000)
to be lifetime hours, and the pattern of descending values in the 0x0B10-0x0B28
range is consistent with fault histogram buckets, not time accumulators.

Candidates from the diff that COULD be hours (all u32 at 0.667s/count given
the bench-measured 1.5 Hz rate):

| Address | Before raw | Decoded (at 0.667s/cnt) |
|---------|-----------|-------------------------|
| 0x010008F4 | 0x0000D227 (53,799) | **~10.0 hours** |
| 0x01000AB4 | 0x00008651 (34,385) | ~6.4 hours |
| 0x01000AEC | 0x00032AF2 (207,602) | ~38.5 hours |

The ECU odometer showed 7,236 miles of driving since the last flash. At an
average 30 mph, that's ~241 driving hours — none of the candidates match.
It's plausible that **this ECU firmware doesn't persist lifetime engine hours
in EEPROM** at all (consistent with: PGN FEE5 absent from firmware, session
counter at RAM 0x0040B150 visibly resetting on each key cycle, no change to
EEPROM 0x10000D6/0x10000F4 after key cycle in the 2026-04-08 test).

If hours aren't persisted, the ELD restoration strategy shifts: the OCT device
(which already accumulates hours from live RPM readings) becomes the
authoritative hours source, and the restore tool only needs to rewrite the
odometer.

## For the restore tool

1. **Odometer restore**: write desired miles to 0x01000BD8 as u32 big-endian,
   scaled by 0.000125 (i.e., `raw = miles × 8000`). Already implemented in
   `tools/update_odometer.sh`.
2. **Engine hours**: investigation ongoing. If the ECU doesn't persist hours,
   use OCT's own hours accumulator for ELD reporting.

## Source dump files

All three dumps are 8192 bytes (full CM848 EEPROM, 0x01000000–0x01001FFF):

- `eeprom_before_hpt.bin` — baseline with 7,236 mi of post-flash driving
- `eeprom_after_hpt_1.bin` — immediately after first HPT flash
- `eeprom_after_hpt_2.bin` — immediately after second HPT flash (same tune)

Captured using `kuminz-cli slcan0 --cm848-dump-eeprom` over the Teensy
MicroMod SLCAN bridge (`tools/teensy-slcan/`).
