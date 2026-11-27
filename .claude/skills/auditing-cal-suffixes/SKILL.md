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
| EEPROM RAM mirror | 0x003FD482–0x003FEEC1 (RAM = 0x3FD482 + EEPROM offset) | ✅ |
| ROM→RAM copy window (boot image) | 0x003F9800–0x003FD481 | ❌ |
| Bank1 ROM / Bank2 flash | 0x0–0x6FFFF / 0x500000–0x53DFFF | ❌ |
| Working / computed RAM | 0x0040xxxx, other 0x003Fxxxx | ❌ |

The copy window's top (0x3FD482–0x3FDB2F) overlaps the mirror; the auditor classifies it as the mirror.

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

## Current counts (CM848)

HARD and SOFT are **0** since PR #53 round 39 (2026-11-22). The ~1352 legacy `_cal` names that the
2026-02/05 bulk DAT-naming campaigns minted before the EEPROM-only rule are all fixed. So a new HARD
is a new mistake: fix it in the same change (edit `global_variables.csv`, then `build` — see
[[editing-firmware-csvs]]). MISSING is 221 (PR #53 round 43): mostly documentation rows
(`name[n]` / `name.field`) and rows at addresses the boot kernel shares. `firmware/CLAUDE.md` breaks
it down; do not add `_cal` to those blindly.

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
- Adding `_cal` to a 0x0040xxxx value because neighbors have it — gate on the region, not the
  neighborhood.
- Treating a new HARD as old debt — the legacy backlog is cleared, so any HARD is a fresh mistake.
