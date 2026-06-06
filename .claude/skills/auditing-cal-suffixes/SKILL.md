---
name: auditing-cal-suffixes
description: Use when naming or reviewing Cummins firmware globals and you suspect `_cal` suffix drift — a `_cal` name sitting in ROM/flash/working-RAM, a missing `_cal` on an EEPROM-backed value, or you want a bulk consistency sweep of a global_variables.csv. Covers CM848 and CM550.
---

# Auditing `_cal` Suffixes

## The rule this enforces

`_cal` marks an **EEPROM-backed** value — Calterm-tunable *without* a reflash. Everything else
is NOT `_cal`, by the **memory map** (never by e2m — e2m uses Calterm virtual addresses, so a
RAM-address grep is blind):

| Region (CM848) | Range | `_cal`? |
|---|---|---|
| EEPROM direct | 0x01000000–0x01000FFF | ✅ |
| EEPROM shadow RAM | 0x003FEExx | ✅ |
| ROM→RAM copy window | 0x003F9800–0x003FDB30 | ❌ |
| Bank1 ROM / Bank2 flash | 0x0–0x6FFFF / 0x500000–0x53DFFF | ❌ |
| Working / computed RAM | 0x0040xxxx, other 0x003Fxxxx | ❌ |

CM550: EEPROM 0x01xxxxxx → `_cal`; ROM/RAM/ext-RAM → no.

## Run it (read-only — edits nothing)

```bash
cd firmware
python3 scripts/audit_cal_suffixes.py <fw>_analysis/output/global_variables.csv [--firmware cm848|cm550]
```

Output groups every contradiction:
- **HARD** — `_cal` on working-RAM / ROM→RAM / HW-reg → almost certainly wrong (strip `_cal`).
- **SOFT** — `_cal` on a Bank1-ROM / Bank2-flash constant → the rule says no, but these are the
  reflash-calibration block; confirm against the e2m data-record region before stripping.
- **MISSING** — an EEPROM-region name *without* `_cal` → probably should have it.

## Known backlog — don't panic at the count

CM848 currently reports **~1352 HARD** contradictions. These are **legacy** names minted during
the 2026-02/05 bulk DAT-naming campaigns *before* the EEPROM-only rule crystallized — not new
bugs. Treat the report as a cleanup backlog, not a blocker. Fix opportunistically: when you touch
a function, strip `_cal` from the working-RAM globals it uses (edit `global_variables.csv`, then
`build` — see [[editing-firmware-csvs]]).

## The mechanical limit (when to escalate to judgment)

Address-range classification answers "is this region EEPROM?" — it does **not** answer "is this
value actually a constant?" A working-RAM global that is genuinely a boot-loaded constant vs one
computed every cycle look identical by address. The real tell is **writes**: a `_cal` name that
is assigned in normal runtime code (`name = ...`, not the boot copy / eepromReadWords) is the
strongest "this isn't a calibration" signal. For that per-symbol call, use
[[investigate-firmware-symbol]] (it runs the read/write + asm sweep), not this bulk auditor.

## Common mistakes

- Stripping `_cal` from a Bank1-ROM constant *because the auditor flagged it SOFT* without checking
  it's outside the e2m calibration data-record block — verify first.
- Adding `_cal` to a 0x0040xxxx value because neighbors have it — neighbors are the legacy backlog;
  gate on the region, not the neighborhood.
- Treating the HARD count as "1352 bugs to fix now" — it's debt, fix opportunistically.
