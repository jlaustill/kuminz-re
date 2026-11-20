"""Append the two stage-6 agents (power take-off helpers, emission manager) to agent_prompts_and_reports.md: exact
prompts (agent_prompts.jsonl) and exact reports (their handback messages), and what the main session checked.
usage: append_stage6_agent_notes.py <scratch dir>"""
import json
import os
import sys

here = sys.argv[1]
notes = os.path.join(here, "agent_prompts_and_reports.md")
text = open(notes).read()
assert "# Stage 6 agents" not in text, "already appended"
prompts = {json.loads(l)["description"]: json.loads(l)["prompt"] for l in open(os.path.join(here, "agent_prompts.jsonl"))}
agents = [
    ("Map CM848 PTO helper functions", "map_cm848_pto_helper_functions.md", "567k tokens, 139 tool uses, 31 min"),
    ("Map CM848 EMO emission family", "map_cm848_emo_emission_family.md", "525k tokens, 98 tool uses, 31 min"),
]
section = ["", "", "# Stage 6 agents (2026-11-19, PR #52)", "",
           "Two read-only `general-purpose` agents (model sonnet), started in parallel while the main session typed the",
           "signed filter records (stage 6a). Checked in the main session before anything was applied:",
           "- the emission manager agent's base proof, the ECU's own parameter ID table in flash2 (0x53be38, 6-byte",
           "  [id][address] records): an independent parser (`parameter_id_table.py`, then",
           "  `firmware/scripts/e2m_block_addresses.py`) reproduces every block base proved earlier (105E, 105F, 1032, 10B1,",
           "  1068, 10AA, 109D, 109E, 11B4, 19A1-19B3, 1180, 1254) and every e2m address both agents give;",
           "- the 11B4 words of stage 5 against the table base (0x3fd884: +2..+16 as named);",
           "- the access widths of every new row (width_census.py), `algorithm_enable_flags_20_cal` bit 0x100 in the air",
           "  handling code, the two medium-confidence function names, the three PGN priority words and the cruise switch",
           "  debounce;",
           "- the stage-5 comment contradictions the power take-off agent found (all fixed in stage 6b).",
           "",
           "Not applied: the store-only 0x3fba22 / 0x3fba24, the i16 retypes, the PGN 65264 byte 6 / 7 SPN identities, the",
           "compressor outlet temperature scale question and DAT_003fba26 / DAT_003fba36 (no writer found)."]
for k, (description, report_file, usage) in enumerate(agents, 4):
    prompt = prompts[description]
    report = open(os.path.join(here, report_file)).read().strip()
    assert "````" not in prompt and "````" not in report
    section += ["", f"## {k}. {description} ({usage})", "", "### Prompt (exact text)", "", "````text", prompt, "````", "",
                "### Report (exact text, the agent's handback message)", "", "````text", report, "````"]
open(notes, "w").write(text.rstrip("\n") + "\n".join(section) + "\n")
print("appended", [a[0] for a in agents])
