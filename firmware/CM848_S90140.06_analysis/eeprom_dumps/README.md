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

## Resolution: OCT as the canonical odometer + hours source

After reviewing the findings, the ELD restoration strategy is:
**stop trying to restore runtime counters in the ECU itself.**
Instead, OCT (the Teensy-based dash device) owns both counters:

- OCT accumulates **engine hours** from live RPM (already implemented,
  see `oct/src/domain/oct-domain.cpp`)
- OCT will iterate toward accumulating **odometer** from J1939 CCVS
  (PGN FEF1 vehicle speed), seeded from the dash cluster's real value
- OCT persists both to the Teensy's internal EEPROM every 30 seconds
- HP Tuners flashes don't touch the Teensy, so the values survive flashes

The ECU-internal odometer at 0x01000BD8 is unreliable anyway — HPT writes
arbitrary values from the tune file during each flash (not zero, not the
real value, just whatever the last ECU "read" captured). The J1939 FEE0
total distance is also not the real odometer — it accumulates from zero
after each flash.

No further ECU-side restore work is needed for the ELD use case.

---

## Using these dumps as RE baselines

The three dumps are valuable beyond the odometer/hours investigation —
they form a **flash-diff baseline**. Future HP Tuners flashes with small,
targeted tune changes let us isolate exactly which EEPROM bytes correspond
to which tune parameter.

### RE workflow for identifying tune parameters

1. **Current baseline: `eeprom_after_hpt_2.bin`** (last known state after
   an unchanged-tune flash on 2026-04-12).
2. In HP Tuners, change **one** parameter by a small amount. Record
   exactly what you changed (parameter name, old value, new value).
3. Flash the ECU.
4. Dump EEPROM:
   `kuminz-cli slcan0 --cm848-dump-eeprom eeprom_after_<descriptive>.bin`
5. Diff against the baseline:
   ```python
   # See the analysis script in git history at commit 7f76567
   # Compare byte-by-byte, look for:
   # - Bytes that changed to values matching your HPT change
   # - Bytes in the "deterministic" category from the 2026-04-12 analysis
   ```
6. Ignore the "always changes" addresses from the HPT-variable list below.
7. The remaining changed bytes are the EEPROM storage for that parameter.

### HPT-variable addresses to IGNORE in future diffs

These 55 addresses change on every flash regardless of tune content
(checksums, flash counter, session markers). Subtract these from any diff
to see the real tune-parameter changes:

```
0x01000032  (calibration header checksum)
0x01000044  (HPT flash counter — increments by 10 each flash)
0x01000052, 0x01000054  (flash session markers, increment by 1)
0x0100005C  (another checksum)
0x010009C4  (mirror of 0x1000044)
0x01000B48  (checksum)
0x01000E6C, 0x01000E6E  (checksum block)
0x0100106C, 0x01001072, 0x01001074  (checksum block)
0x010011F4–0x0100127C  (DTC snapshot records set A — calibration stamps)
0x01001374–0x010013FC  (DTC snapshot records set B — same data, different slot)
0x010019A0  (counter)
```

The regions 0x011F0-0x012FF and 0x01370-0x013FF appear to be two parallel
copies of DTC snapshot metadata — probably a ping-pong buffer. These
change every flash because they contain calibration timestamps/IDs.

### Full list of HPT-deterministic writes (69 addresses)

These are written to fixed values by HPT that don't depend on prior state —
they represent the tune file's actual content at specific EEPROM offsets.
Most of these are what you'll see move when you change tune parameters:

Key areas:
- 0x01000806–0x01000926: small flags/counters (HPT resets to small values)
- 0x010009C2, 0x010009C8, 0x01000B0E, 0x01000B2A, 0x01000B46: calibration markers
- 0x01000BD8–0x01000BFA: **odometer u32 values** (HPT writes tune-file values)
- 0x01000C18–0x01000CA0: DTC config (small integer adjustments)
- 0x01001200–0x010014BE: **DTC freeze frame templates** (big block of tune-specific values)
- 0x0100161E, 0x01001910–0x01001914: adaptive limits
- 0x0100193A–0x0100193C: sensor adaptation anchors
- 0x010019CE, 0x01001A34: more adaptation data

See commit 7f76567 message or run the Python diff script against the three
dump files to reproduce the full list.

## Source dump files

All three dumps are 8192 bytes (full CM848 EEPROM, 0x01000000–0x01001FFF):

| File | Capture | Content |
|------|---------|---------|
| `eeprom_before_hpt.bin` | 2026-04-12, pre-test | 7,236 mi of driving accumulated since prior HPT flash; diagnostic + fault history populated |
| `eeprom_after_hpt_1.bin` | 2026-04-12, post-flash 1 | Same tune as flash 2; odometer overwritten by HPT; runtime data wiped |
| `eeprom_after_hpt_2.bin` | 2026-04-12, post-flash 2 | Same tune re-flashed; differs from flash 1 only in checksums/counters — **USE THIS AS THE CURRENT BASELINE** |

**ECU state for these dumps:**
- Firmware: CM848 S90140.06 (V11.46.06, 1504 2RSAO)
- VIN: 3D3MU48C94G228471
- 2004.5 Dodge Ram 3500 5.9L Cummins
- Calibration: custom HP Tuners tune (unchanged between flashes 1 and 2)
- Bench conditions: key-on, engine on at idle ~750 RPM for first 30 min
  before flash 1; brief key-on only during flash 1 → flash 2 interval

Captured using `kuminz-cli slcan0 --cm848-dump-eeprom` over the Teensy
MicroMod SLCAN bridge (`tools/teensy-slcan/`).

## Adding new dumps to this baseline

When capturing future flash dumps for tune-parameter RE, follow this
naming convention so the baselines stay organized:

```
eeprom_<date>_<tune-description>_<flash-n>.bin
```

Examples:
- `eeprom_20260415_afc_curve_+10pct_1.bin`
- `eeprom_20260415_afc_curve_+10pct_2.bin`  (confirm repeatability)
- `eeprom_20260420_timing_+2deg_1.bin`

Add each new dump's purpose and findings to this README so the baseline
grows into a tune-parameter reference over time.
