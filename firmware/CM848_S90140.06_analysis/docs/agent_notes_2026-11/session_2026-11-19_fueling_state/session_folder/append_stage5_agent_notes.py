"""Append the stage 5 agent (the crank routine) to agent_prompts_and_reports.md: its exact prompt (from
agent_prompts.jsonl) and its exact report (crank_agent_report.md, the agent's handback message).
usage: append_stage5_agent_notes.py <scratch dir>"""
import json
import os
import sys

here = sys.argv[1]
notes = os.path.join(here, "agent_prompts_and_reports.md")
text = open(notes).read()
assert "# Stage 5 agent" not in text, "already appended"
rows = [json.loads(line) for line in open(os.path.join(here, "agent_prompts.jsonl"))]
prompt = next(r for r in rows if r["description"] == "Map CM848 crank routine words")["prompt"]
report = open(os.path.join(here, "crank_agent_report.md")).read().strip()
assert "````" not in prompt and "````" not in report

section = f"""

# Stage 5 agent (2026-11-19, PR #52)

One read-only `general-purpose` agent (model sonnet), run in the background while the main session checked the power
take-off words. The main session checked these before anything was applied:
- the e2m 105E / 105F / 1032 / 10B1 record names and offsets in `CHR_CC_11.45.01.07.e2m`;
- the 10B1 anchor (+A `fault_derate_fuel_limit` = Engine_Protection_Derate_Fueling) and the 1032 overspeed words;
- the EEPROM records 1254 +38 (Crank_Exit_Speed_Switch) and 1180 +16 (EB_Driveline_Brake_Type), and the code that
  reads them;
- the two setters (`cm848_setEngineStarting`, `cm848_setColdStartMode2Flag`) and the injection gate of
  `engine_injectionAngle_writeTpuEvent`;
- the RAM-dump values.

Applied: the high-confidence rows. Skipped: the low / medium rows (0x40a79c, 0x40a7a2, 0x40a7b8, 0x3fdfdc), the i16
retypes and the unnamed DAT_0005b1b6-0x5b1bc words.

## 3. Map CM848 crank routine words (137 tool uses, 28 min)

### Prompt (exact text)

````text
{prompt}
````

### Report (exact text, the agent's handback message)

````text
{report}
````
"""
open(notes, "w").write(text.rstrip("\n") + section)
print(f"appended: prompt {len(prompt)} chars, report {len(report)} chars")
