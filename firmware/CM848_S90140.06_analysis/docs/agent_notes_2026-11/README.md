# Agent notes: the CM848 table-naming campaign and rename waves 1-7 (2026-11-16/17, PR #50)

Read-only agents researched the firmware and returned one JSON object per line. These are their files as they
returned them, the briefs they followed, and mappings of what was applied. `work/tasks/042-table-campaign-rename-leads.md`
quotes the notes cut short; the full text is here. Paths inside the briefs (and a few results) point at the
session's scratch folder, which no longer exists: the files they name are the ones in this folder.

The scripts that gated, applied and proved these renames are in `firmware/scripts/rename_waves/` (see its README).

## Rename waves (`rename_waves/`)

| Wave | Commit | Results (`results/`) | Mappings (`mappings/`) |
|---|---|---|---|
| 1 (todo 042) | 482038a | `result_G1a` / `G1b` / `G2` / `G3` / `G4`, `manual.jsonl` | `mapping_renames.csv` |
| 2 (review of wave 1) | f813725 | - | `mapping_adjust.csv`, `mapping_families.csv`; waves 1-2 together: `mapping_all.csv` |
| 3 | cfd889a, 3f64709, e54732c | `result_W3_*` | `mapping_w3_*` |
| 4 | 14dfd97 | `result_W4_*` | `mapping_w4_*` |
| 5 | 40a41e7 | `result_W5_*` | `mapping_w5_*` (also `_enums`, `_types`) |
| 6 | 1839d0b | `result_W6_*` | `mapping_w6_*` |
| 7 | 4c39da3 | `result_W7_*` | `mapping_w7_*` |

- `briefs/brief.md` is the method every wave followed; `brief_wave3.md` to `brief_wave6.md` are the addenda each later
  wave read on top of it (wave 7 read all of them, plus per-agent leads taken from the wave-6 notes).
- **Result rows:** `kind` is `function`, `global`, `new_global`, `struct_field`, `enum_member`, `enum_type` or `note`;
  `verdict` is `confirmed`, `uncertain` or `rejected`. Other keys: `address`, `old`, `new`, `type` (new rows),
  `struct` (fields), `enum` (members), `plate_comment` (functions), `evidence`, `comment`, `text` (notes).
- **A result's `new` can differ from the applied name.** Names went through `align_results.py` first (`initialize`
  for `init`, prefix decisions such as wave 7's `egr_valve_*` for the proposed `exhaust_gas_recirculation_valve_*`),
  and conflicting rows were dropped (each wave's section in task 042 lists them). The mappings have the applied names.
- **Mapping columns:** `address`, `name` (applied), `old_label` (what the decompiled output showed before), `kind`.
  A wave's `mapping_wN_all.csv` (renames + fields + new rows) is the input of its label-only proof.

## Table-naming campaign (`table_campaign/`)

| File | What it is |
|---|---|
| `lookups.json` | the 238 lookups the agents were given (`L000`...): interpolator, the tables per role with their addresses, current names, readers and contents (breakpoints). Results refer to lookups by these ids |
| `brief.md` | the method |
| `brief_addendum.md` | the main wave's addendum: facts the pilot established, grammar reminders, budget |
| `go_no_go.md` | the pilot's go / no-go rule, written before any result was read (pilot: bin 02 to agents A and B independently, bin 06, bin 09) |
| `results/result_NN.jsonl` | bin NN; `02_a` / `02_b` are the two pilot agents on the same bin, `retry` the bin of tables still unnamed after the main wave (rename wave 3) |
| `mappings/mapping_main.csv` | the names applied in the pilot and main waves (e081b73, 973925d), with role, lookups, bin, confidence and evidence |
| `mappings/mapping_final.csv` | the review's renames (dfef374) |

Each table's outcome (evidence, confidence, skip reason) is in `../table_naming_campaign_2026-11-16.csv`.

## Everything else from the session (kept at the user's request, 2026-11-17)

- **`session_folder/`** holds the session's other scratch files as they were, 456 in all:
  - the one-off scripts: appliers, checks, and the doc and PR-description updaters;
  - the table-campaign producers: `table_census.py`, `table_worklist.py`, `plan_tables.py`, `size_tables.py`,
    `name_tables.py`, `rename_bases.py`, `rename_table_families.py`, `campaign_provenance.py`, `unseen_uses.py`;
  - the intermediate files: `renames/aligned_*.jsonl`, the agents' scratch folders, the bins and proposals.

  Paths inside them point at the scratch folder. The maintained rename-wave scripts are in `firmware/scripts/rename_waves/`.
- **`session_folder_large_files.tar.xz`** (0.6 MB, 142 MB unpacked) holds the 44 `.cpp` snapshots (each proof's
  baselines and reverse-mapped builds) and the 65 build logs. `session_folder_large_files.txt` lists them. Unpack
  with `tar -xJf session_folder_large_files.tar.xz -C session_folder`.
- **`agent_prompts.md`** (and `agent_prompts.jsonl`) has the exact prompt of each of the 74 subagents the session
  started, in order.
- **Not in this public repo:** the session and agent transcripts. They contain the session's private context and are
  kept outside the repo.
