# Wave 3 addendum (read after brief.md)

The first wave (2026-11-16) already renamed 27 functions and 237 globals (their CSV comments end with
`(was <old>)`), so the decompiled C now reads with names like `main_injection_timing`,
`cm848_calculateFuelPressureSetpoint`, `injection_quantity_pilot_*`. Your leads are the agents' FURTHER notes in
`work/tasks/042-table-campaign-rename-leads.md`, section "Further leads, notes and type issues from the
verification agents" - the lines tagged with your group(s). They mention symbols by the names they had BEFORE the
first wave; look a name up in the CSV comments (`grep '(was <name>)'`) when it no longer exists.

Extra result kinds allowed in this wave (besides function / global / note):
{"kind": "struct_field", "struct": "rpm_governor_state_t", "old": "commanded_rpm", "new": "...", "evidence": "..."}
{"kind": "new_global", "address": "0x0040xxxx", "new": "...", "type": "word", "evidence": "... width: xref_addr.py says word (N reads / M writes)"}
- new_global only for an unnamed DAT_ address with no row in global_variables.csv; the type must be the access
  width xref_addr.py reports (byte / word / dword; i16 / i8 / i32 when the code treats it as signed).
- Skip notes that are only informational, or type issues you cannot settle from the disassembly.
- Budget: about 60 tool calls.
