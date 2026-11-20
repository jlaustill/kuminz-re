"""Append rename wave 13 (stage 8) to agent_prompts_and_reports.md: the shared brief, the six agents' exact prompts and
their exact reports (handback messages), and what the main session checked.
usage: append_W13_agent_notes.py <scratch dir>"""
import json
import os
import sys

here = sys.argv[1]
notes = os.path.join(here, "agent_prompts_and_reports.md")
text = open(notes).read()
assert "# Stage 8 agents" not in text, "already appended"
prompts = {json.loads(l)["description"]: json.loads(l)["prompt"] for l in open(os.path.join(here, "agent_prompts.jsonl"))}
usage = {1: "557k tokens, 36 min", 2: "703k tokens, 43 min", 3: "689k tokens, 38 min", 4: "580k tokens, 32 min",
         5: "773k tokens, 42 min", 6: "739k tokens, 42 min"}
brief = open(os.path.join(here, "stage8", "brief_W13.md")).read().strip()
assert "````" not in brief
section = ["", "", "# Stage 8 agents: rename wave 13, the misname review (2026-11-19, PR #52)", "",
           "Six read-only `general-purpose` agents (model sonnet), started in parallel, one bin of 63-64 e2m records each.",
           "Each wrote one JSONL result file in the scratch folder and nothing else.",
           "",
           "The main session built the bins with `stage8/build_context_W13.py`. A record went in when it is a named",
           "scalar / enum / array row whose name shares no word with its table-resolved e2m record, with 3+ code",
           "references and a dump value in range: 381 records, whole blocks per bin. Then:",
           "- `stage8/apply_W13.py` held back 3 rows: two enum-typed rows whose enum members still follow the old reading,",
           "  and a dword to split first. It checked the old names against CM550 and the cross-firmware maps (none",
           "  shared) and ran the repo's apply_renames.py gate on the 218 renames (no PROBLEM line);",
           "- a random sample of 9 renames was spot-checked against the code;",
           "- the main session reconciled one cross-bin name: 0x40b798 became `backup_pulse_period_countdown`, to pair",
           "  with bin 5's `backup_pulse_period_timeout`, because the code reloads it from that timeout;",
           "- old comments stay as earlier notes, except 11 that an agent showed to be wrong. The proved facts of one of",
           "  them (0x3fed94) were restored by hand. 54 rows got the rename note moved to the repo order;",
           "- the 80B9 debounce counters and limits (8 rows) took their bits bytes' new meanings (code pairing checked);",
           "- after the build, the label-only proof was EQUIVALENT, and the build warnings were identical to stage 4.",
           "", "## The shared brief (exact text)", "", "````text", brief, "````"]
for k in range(1, 7):
    description = f"Review e2m names wave 13 bin {k}"
    report = open(os.path.join(here, "stage8", "reports", f"review_e2m_names_wave_13_bin_{k}.md")).read().strip()
    prompt = prompts[description]
    assert "````" not in prompt and "````" not in report
    section += ["", f"## {11 + k}. {description} ({usage[k]})", "", "### Prompt (exact text)", "", "````text", prompt,
                "````", "", "### Report (exact text, the agent's handback message)", "", "````text", report, "````"]
open(notes, "w").write(text.rstrip("\n") + "\n".join(section) + "\n")
print("appended wave 13")
