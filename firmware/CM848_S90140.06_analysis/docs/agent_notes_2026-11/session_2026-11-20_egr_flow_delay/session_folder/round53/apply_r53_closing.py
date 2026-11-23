"""Round 53 closing: task 046, PR body, README, todo, memory, and one factual correction in firmware/CLAUDE.md (the
0x5139b8 helpers it still called unidentified are the coolant temperature derate; no new rule). Idempotent.
usage: apply_r53_closing.py <repo> <pr_body.md> <hash A> <hash B> <count> <proof>"""
import os
import re
import sys

repo, pr, ha, hb, count, proof = os.path.abspath(sys.argv[1]), *sys.argv[2:7]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 53 (2026-11-23, same PR): blocks ranked by meaning, the coolant temperature derate module

A peer relay started the round; the scripts are in `session_folder/round53/`.
- **Method:** `semantic_record_matches.py` is round 52's matcher ranked by a meaning score.
  - `semantic_score.py` expands the e2m abbreviations and scores the record name and description against the row name.
  - The score ranks, it does not decide: 8A71's best-scoring base was wrong. The true base, 0x40874e, fits all 16
    records, with every access's width and sign matching its record.
  - `e2m_cite.py` shares the citation helpers the stage scripts used to copy.
- **Stage A ({ha}, labels, rows):** eleven blocks:
  - the fan speed sensor RAM (8B20);
  - the PTO / battery voltage flags and their calibrations (160A / 1609);
  - the sensor-fault substitutes and the in-use values (8B03 / 8B04). The eight substitutes are now named by the fault
    that selects them (`<sensor>_high_fault_substitute`), because the temperature pair went by value;
  - the learned ratio limits (8BB1);
  - the gear ratio margin and the rail-leak limit (8B8A, a new row);
  - the J1850 received data (8A7D, `pci_four_wheel_drive_status_flag`);
  - the brake switch pair (8A86);
  - the vehicle speed words (8ADA), which anchor round 51's 0x40b5a8 lead;
  - the VSS calibrations (8ADB) and the transfer case learning (8B0B).
- **Stage B ({hb}, labels, rows):** the coolant temperature derate module (CT_Derate: 8A71 / 8A7A / 8A79 / 8A72).
  - The minimum derate (fault 390), the aggressive derate (fault 389) with its five level timers, the PI loop, and the
    check gauges / chime requests.
  - About 20 `cold_start_*` / `*bucket*` names became `coolant_overheat_*`, plus 7 new rows and 3 function renames
    (`cm848_monitorCoolantOverheatMinimumDerate` / `...AggressiveDerate`, `cm848_accumulateCoolantOverheatLevelTimers`).
  - `coolant_overheat_temp_threshold` used the banned abbreviation "temp".
- **Proof:** {proof}
- **firmware/CLAUDE.md:** one factual correction, no new rule. The read-back bullet called the 0x5139b8 helpers
  "unidentified"; they are the coolant temperature derate. HARD stays 0 and MISSING 221.
- **Leads:**
  - The lifetime level-timer totals (8A73, EEPROM mirror 0x3fee04 + 4 x level) overlap the boot kernel's
    `eeprom_shadow_header`, so they stay untyped. This is the same time-sharing problem as the trip distance dword.
  - The matcher's other hits read by meaning but not applied: 1497 / 1498 (LSG droop on ASG-named rows), 158D, 8BA4.
  - 8B7C (AFR) exists only in older layouts.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 53.**\n"
     f"- **Stage A ({ha}, labels, rows):** eleven more e2m blocks record for record, found by a meaning-ranked matcher;\n"
     "  the eight sensor-fault substitutes named by the fault that selects them; `pci_four_wheel_drive_status_flag`.\n"
     f"- **Stage B ({hb}, labels, rows):** the coolant temperature derate module (e2m CT_Derate 8A71 / 8A7A / 8A79 / 8A72):\n"
     "  the `cold_start_*` / bucket names were the overheat derate's; 7 new rows and 3 function renames.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 52:", f"- [x] Round 53: {proof}\n- [x] Round 52:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 53: blocks ranked by meaning, the coolant temperature derate module (`session_folder/round53/`)\n\n"
       "- Search: `semantic_record_matches.py` (from round 52's matcher, `patch_matcher.py`), `semantic_score.py`, "
       "`semantic_matches.txt`, `placements.txt`. Shared helpers: `e2m_cite.py`. **Stage A:** `apply_r53a.py` "
       "(`fix_r53a_texts.py`), `map_r53a.csv`. **Stage B:** `apply_r53b.py`, `map_r53b.csv`, "
       "`refresh_dat_mentions_r53.py` (the plates that quoted the new rows' DAT_ labels). Proof: `prove_r53.sh`. "
       "**Closing:** `apply_r53_closing.py`, `update_large_tar_r53.sh`.\n")
if "## Round 53:" not in t:
    i = t.index("## Round 52:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md",
     "round 52: nine more blocks record for record (fan / alternator field / reset capture), five state enums - open: "
     "the task 046 leads",
     "round 52: nine more blocks record for record (fan / alternator field / reset capture), five state enums; round 53: "
     "eleven more blocks by meaning, the coolant temperature derate module - open: the task 046 leads")
edit("firmware/CLAUDE.md",
     "The `fuel_coldStart_*` helpers at 0x5139b8-0x513ba4 and `governor_fuel_limit_*` are unidentified (nothing ties "
     "them to the fan yet)",
     "The `fuel_coldStart_*` helpers at 0x5139b8-0x513ba4 are the coolant temperature derate (e2m CT_Derate, "
     "`coolant_overheat_*`, PR #53 round 53); `governor_fuel_limit_*` is unidentified")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "reset capture 15B4 = SRR0/vector/LR, 5 state enums); task 046 leads"
new = ("reset capture 15B4 = SRR0/vector/LR, 5 state enums) + round 53 (meaning-ranked matcher: 11 blocks, fault-named "
       "substitutes; CT_Derate module 8A71/8A72 = coolant_overheat_*, the cold_start_* names were wrong); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 53 (2026-11-23): {ha} / {hb}. A meaning score (expanded e2m abbreviations vs row tokens) ranks "
        "placements but can pick a wrong base when the rows are misnamed (8A71's true base matched every access's width "
        "and sign; check those for the unrowed records). Name substitutes by the fault that selects them.\n")
if "Round 53 (2026-11-23" not in open(f).read():
    open(f, "a").write(note)
print("round 53 closing applied")
