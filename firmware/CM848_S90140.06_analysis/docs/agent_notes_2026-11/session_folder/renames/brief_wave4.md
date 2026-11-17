# Wave 4 addendum (read after brief.md and brief_wave3.md)

Three waves have renamed 80 functions and ~420 globals (CSV comments end with `(was <old>)`), typed 116 new rows and
renamed struct fields. Your leads are the wave-3 agents' leftovers in
`work/tasks/042-table-campaign-rename-leads.md`: the lines tagged with your group in "### Wave 3: left uncertain" and
"### Wave 3: further notes". Names in them may already have changed - look them up with `grep '(was <name>)'`.
Same result kinds as wave 3 (function / global / new_global / struct_field / note). For struct_field also give the
exact struct name from structure_definitions.csv. Do NOT re-propose anything already renamed.
Time-shared RAM (0x3F9800-0x3FDB30, and 0x3fee08-0x3fee3d) has boot-ROM users: before renaming or retyping there, run
xref_addr.py and list any user below 0x7F60 in the evidence; never propose a type change for a time-shared word.
