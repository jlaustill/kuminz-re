# Wave 5 addendum (read after brief.md, brief_wave3.md and brief_wave4.md)

Wave 5 re-domains two clusters. Earlier waves renamed ~128 functions and ~640 globals (comments end `(was <old>)`).
Extra result kinds this wave (besides function / global / new_global / struct_field / note):
{"kind": "enum_member", "enum": "<ENUM_TYPE>", "old": "<MEMBER>", "new": "<MEMBER>", "evidence": "..."}
{"kind": "enum_type", "old": "<ENUM_TYPE>", "new": "<ENUM_TYPE>", "evidence": "..."}
Enum member names are UPPER_SNAKE with a fully spelled domain prefix (no invented abbreviations).
The full combustion-manager lead (block anchors from the e2m parameter list, matched by relative offset) is the first
"note" row of /home/linux/.claude/jobs/d55ae3c6/tmp/renames/aligned_W4_injection.jsonl (task 042 shows it cut short).
e2m block layout is corroboration only: a name needs the code (reads / writes / consumers) to agree, and the evidence
must say which part is code and which part is e2m.
Keep names for the same structure consistent with the existing families (injection_timing_main_*, fuel_pressure_setpoint_*,
...). About 70 tool calls.
