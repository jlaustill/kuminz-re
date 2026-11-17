# Wave 9 addendum (read after brief.md, brief_wave3.md, brief_wave4.md, brief_wave5.md, brief_wave6.md, brief_wave8.md)

Eight waves are done; firmware/CLAUDE.md "Rename waves 1-8" summarises them. Your leads are the wave-8 agents' notes and
uncertain rows: read them in FULL from the aligned results file named in your task. MANY wave-8 notes were APPLIED in
commit b66e3a7 - skip them: the engine_speed_limit_arbitration_t split, the droop slope / ramped limit split, the EGR
retypes and split words, the EGR_VALVE_CONTROL_STATE / COMBUSTION_CHI_SOURCE enums, the corrected ENGINE_OPERATING_MODE,
operating_mode_governor_output_t, the i16 retypes of the all-speed governor words, the DELETE notes, and the shared name
selectHighSpeedGovernorGainSet (CM848 0x1fa20 / CM550 0x1d392). Check the current CSVs (and `grep '(was <name>)'`)
before proposing anything.

Things that changed since your briefs were written:
- The ROM-to-RAM thunk stage keeps named data rows (todo 043): a named row in the kernel-image window no longer hides
  or crosses with a boot call. A type change in the time-shared windows still needs the boot-user check.
- Tables that have an `arrays.csv` row need the `arrays.csv` row renamed too: give both rows exactly
  (arrays.csv: address,array_name,element_type,element_count,comment).
- Prototype / local type keywords (function_definitions.csv, local_variables.csv): `int` is UNSIGNED dword, `int32_t`
  is signed 32-bit, `ushort` is a 2-byte unsigned. Do not give a register-passed parameter a 2-byte enum type (it
  renders `CONCAT22(in_register_...)`): type the global / the local instead and keep the parameter `int32_t`.
- A function shared with CM550 (same body) gets ONE unprefixed name in both firmwares: give the CM550
  function_renames.csv row too.
- New names say `initialize`, never `init`; the EGR valve module is `egr_valve_*`.

About 100 tool calls. Skip a lead with a one-line note when it is only informational or still cannot be settled.
