"""Append the wave-3 results to task 042."""
import json
import os
import sys

repo, d = sys.argv[1], sys.argv[2]
notes, uncertain = [], []
for g in ("injection", "rail", "air", "governor", "duplicates"):
    for line in open(os.path.join(d, f"aligned_W3_{g}.jsonl")):
        r = json.loads(line)
        if r.get("kind") == "note" and not r.get("text", "").startswith("DELETE"):
            notes.append(f"- [W3 {g}] " + " ".join(r.get("text", "").split())[:360])
        elif r.get("verdict") == "uncertain":
            uncertain.append(f"- [W3 {g}] `{r.get('old')}` ({r.get('address')}): " + " ".join((r.get("evidence") or "").split())[:240])
text = """
## Wave 3 (2026-11-16, PR #50 commits cfd889a + the new-rows commit)

Six read-only agents verified the further leads above, retried the skipped tables and resolved the duplicate names:
53 function renames (+5 plate refreshes), 183 global renames, 16 struct fields (`fault_entry_t` freeze-frame
fields; `rpm_governor_state_t` -> `wastegate_duty_controller_state_t` / `wastegate_duty_controller_state`, every
field in half-duty counts), 21 duplicate names resolved, 31 junk rows deleted (27 `switchD`, 4 USIU), 5 more tables
named (524 of 564), and 113 new rows for unnamed words (types from the access widths; three retyped after the
first build showed casts: a signed compare -> i16, a stored address -> pointer). Highlights: the speed-limp-home
flag (`crank_position_valid_flag` read backwards -> `engine_speed_limp_home_active_flag`), the ERC1 / TSC1 retarder
chain and the PGN 65213 / 65249 messages, the charging-regulator chain, the P0148 / P1221 rail pressure monitors, the
per-injector diagnostic bitmaps (P0201-P0206 / P2146 / P2149), `all_speed_governor_droop`.

- **Time-shared with the boot ROM - types left as they were:** 0x3fee34-0x3fee3d (the oil change monitor words in
  the EEPROM mirror). mpc555_eepromValidationCycle counts in the dword at 0x3fee34, cm848_lookupEepromParameterAddress
  returns 0x3fee38, cm848_bootSciCheckSecurityKey reads the bytes 0x3fee3a-0x3fee3d; retyping them for the
  application made the boot code worse, so it was reverted (the application keeps
  `_oil_change_monitor_distance_pulses_cal`).

### Wave 3: left uncertain
""" + "\n".join(uncertain or ["- none"]) + """

### Wave 3: further notes
""" + "\n".join(notes) + "\n"
p = os.path.join(repo, "work/tasks/042-table-campaign-rename-leads.md")
open(p, "a").write(text)
print(f"appended: {len(uncertain)} uncertain, {len(notes)} notes")
