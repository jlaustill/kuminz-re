"""Append rename wave 14 (stage 9) to agent_prompts_and_reports.md: the shared brief, the seven agents' exact prompts and
their exact reports (handback messages), and what the main session checked.
usage: append_W14_agent_notes.py <scratch dir>"""
import json
import os
import sys

here = sys.argv[1]
notes = os.path.join(here, "agent_prompts_and_reports.md")
text = open(notes).read()
assert "# Stage 9 agents" not in text, "already appended"
prompts = {json.loads(l)["description"]: json.loads(l)["prompt"] for l in open(os.path.join(here, "agent_prompts.jsonl"))}
BINS = [("functions", 1, "603k tokens, 31 min"), ("functions", 2, "642k tokens, 38 min"), ("functions", 3, "687k tokens, 38 min"),
        ("globals", 1, "779k tokens, 41 min"), ("globals", 2, "633k tokens, 33 min"), ("globals", 3, "681k tokens, 41 min"),
        ("globals", 4, "751k tokens, 40 min")]
brief = open(os.path.join(here, "stage9", "brief_W14.md")).read().strip()
assert "````" not in brief
section = ["", "", "# Stage 9 agents: rename wave 14, the function misnames and the sibling rows (2026-11-19, PR #52)", "",
           "Seven read-only `general-purpose` agents (model sonnet), started in parallel: three function bins (83 functions",
           "by family) and four global bins (253 rows by e2m block). Each wrote one JSONL result file and nothing else.",
           "4.78M tokens in all.",
           "",
           "The main session built the worklists:",
           "- the functions are the renames the wave-12 / wave-13 reports proposed (`stage9/extract_function_leads.py`,",
           "  plus 9 by hand);",
           "- the globals are the low-overlap rows of the blocks wave 13 renamed into, the wrong-`_cal` rows, and every row a",
           "  report named. `expand_worklist.py` added the report ranges and family stems;",
           "- `build_context_W14.py` precomputed the CM550 shared-name check, the owner's review notes, and each row's width",
           "  against its records.",
           "",
           "Before dispatch, an advisor review changed the plan: full plates, ranges, bins by family, the width check, and a",
           "`code_quote` the gate checks.",
           "",
           "`stage9/apply_W14.py` then:",
           "- checked every line, the quotes and the name formats, and ran the repo gate;",
           "- held 17 items: 5 CM550-shared functions, 3 functions with the owner's review notes, 7 width / struct items and",
           "  2 enum rows;",
           "- applied 75 function renames and 231 global renames.",
           "",
           "The hand scripts applied the splits, the collector table array and the three enums.",
           "", "## The shared brief (exact text)", "", "````text", brief, "````"]
for n, (kind, k, usage) in enumerate(BINS, 18):
    description = f"Wave 14 {kind} bin {k}"
    report = open(os.path.join(here, "stage9", "reports", f"wave_14_{kind}_bin_{k}.md")).read().strip()
    prompt = prompts[description]
    assert "````" not in prompt and "````" not in report
    section += ["", f"## {n}. {description} ({usage})", "", "### Prompt (exact text)", "", "````text", prompt, "````", "",
                "### Report (exact text, the agent's handback message)", "", "````text", report, "````"]
open(notes, "w").write(text.rstrip("\n") + "\n".join(section) + "\n")
print("appended wave 14")
