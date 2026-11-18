# Wave 8 addendum (read after brief.md, brief_wave3.md, brief_wave4.md, brief_wave5.md, brief_wave6.md)

Seven waves are done; firmware/CLAUDE.md "Rename waves 1-7" summarises what the code turned out to be. Your leads are
the wave-7 agents' notes and uncertain rows. Read them in FULL from the aligned results file named in your task (one
JSON object per line; take the rows whose "kind" is "note" or whose "verdict" is "uncertain") - the copies in task 042
are cut short. Never re-propose a rename that is done: look a name up with `grep '(was <name>)'` in the CSVs first.

Naming decisions to follow (the user's):
- New names say `initialize`, never `init` (for data, `initial_` or `initialization_` by meaning).
- The EGR valve module is `egr_valve_*`; the VGT module is `variable_geometry_turbocharger_*`.

Same result kinds as wave 5. For an enum (a new type, or members that contradict the code) or a struct change (a
split, new fields, a type rename), give the exact CSV rows in a note - enums.csv: enum_name,value,member_name,comment,size;
structure_definitions.csv: struct_name,address,field_name,type,size,comment,dependency,Status - with the evidence for
every value, and say which globals / locals / struct fields must take the type so the names render.

A type change on a global needs the load / store instruction (`disasm_func.py`): `lha` = signed (`i16`), `lhz` =
unsigned (`word`). Never retype a word in the time-shared windows 0x3F9800-0x3FDB30 or 0x3fee08-0x3fee3d unless the
disassembly proves the width and no boot user (code below 0x7F60) conflicts.

About 100 tool calls. Skip a lead with a one-line note when it is only informational or still cannot be settled.
