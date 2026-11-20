"""Append rename wave 12 (stage 7) to agent_prompts_and_reports.md: the shared brief, the six agents' exact prompts and
their exact reports (handback messages), and what the main session checked.
usage: append_W12_agent_notes.py <scratch dir>"""
import json
import os
import sys

here = sys.argv[1]
notes = os.path.join(here, "agent_prompts_and_reports.md")
text = open(notes).read()
assert "# Stage 7 agents" not in text, "already appended"
prompts = {json.loads(l)["description"]: json.loads(l)["prompt"] for l in open(os.path.join(here, "agent_prompts.jsonl"))}
usage = {1: "680k tokens, 39 min", 2: "546k tokens, 36 min", 3: "594k tokens, 38 min", 4: "556k tokens, 37 min",
         5: "473k tokens, 30 min", 6: "583k tokens, 35 min"}
brief = open(os.path.join(here, "stage7", "brief_W12.md")).read().strip()
assert "````" not in brief
section = ["", "", "# Stage 7 agents: rename wave 12 (2026-11-19, PR #52)", "",
           "Six read-only `general-purpose` agents (model sonnet), started in parallel, one bin of 66-67 e2m records each.",
           "Each wrote one JSONL result file in the scratch folder and nothing else.",
           "",
           "The main session built the bins with `stage7/build_context.py`: every scalar e2m record that the parameter ID",
           "table resolves, that has no name yet, that the .cpp uses, and whose dump value is in range. Then:",
           "- `stage7/gate_W12.py` ran the gate. It applies apply_renames.py's rules and adds duplicates across bins,",
           "  collisions, rows already present, and type against size. Only confirmed rows passed: 383 of 398;",
           "- a random sample was spot-checked against the code and the width census;",
           "- after the build, every differing function was classified (`classify_diffs.py`). The one bad render",
           "  (a 4-byte version read bytewise, so `byte[4]`) was fixed.",
           "", "## The shared brief (exact text)", "", "````text", brief, "````"]
for k in range(1, 7):
    description = f"Name e2m records bin {k}"
    report = open(os.path.join(here, "stage7", "reports", f"name_e2m_records_bin_{k}.md")).read().strip()
    prompt = prompts[description]
    assert "````" not in prompt and "````" not in report
    section += ["", f"## {5 + k}. {description} ({usage[k]})", "", "### Prompt (exact text)", "", "````text", prompt, "````",
                "", "### Report (exact text, the agent's handback message)", "", "````text", report, "````"]
open(notes, "w").write(text.rstrip("\n") + "\n".join(section) + "\n")
print("appended wave 12")
