"""Round 90 closing: task 046, PR body, session README, todo, the memory round log and the parameter ID table memory.
Idempotent (an edit is skipped when its new text is already there). usage: apply_r90_closing.py <repo> <pr_body.md> <count>"""
import os
import re
import sys

repo, pr, count = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p, newline="").read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w", newline="").write(t.replace(old, new))


T46 = """## Done, round 90 (2026-11-24, same PR): CM550's parameter ID table; the CM550 e2m audit; a 162-row naming wave; DM8

Peer relays started and continued the round (13:20, 13:50, 14:20, 14:50, 15:19). The scripts, the wave's batches,
proposals, verdicts (`wave_result_r90.json`) and notes (`wave_notes_r90.txt`) are in `session_folder/round90/`; the
three big audit tables are in the large-files tarball (`round90_*`).
- **Stage A (eef9fc0c), the parameter ID table:** CM550's ROM table is `parameter_id_table` (0x35224,
  `parameter_id_table_entry_t[1806]`), read by `cm550_lookupParameterIdAddress` (0x10e16, was
  `cm550_diagnosticMemoryAddressResolver`; the counterpart of `cm848_lookupParameterIdAddress`). It indexes by id
  range: id for 0x0000-0x002E, id - 0xFD1 for 0x1000-0x1478, id - 0x7B58 for 0x8000-0x8265. Each entry holds the
  address used in development mode (RAM refresh disabled) and the one used otherwise; the two are equal in all 1806.
  - `e2m_block_addresses.py --firmware cm550` decodes it, maps EEPROM entries to the RAM mirror (0x803B0A + offset)
    and resolves e2m records with `v64t6_s.e2m`. `--write-table` rewrote `output/parameter_id_lookup_table.csv`:
    47 rows named an older global, 101 empty rows had one and 36 named no current global. A test fails when the
    committed table is stale.
  - Two stale build messages (CM550's hwregs stage, common.sh's deletions stage) no longer point at removed commands.
- **Stage B (5742ef45), the audit:** `e2m_name_audit.py --firmware cm550`. CM550's 4525 scalar records: 2348 land on
  named rows, 1742 on none, 428 inside typed rows and 7 on unnamed rows; 66 referenced records had no row; 478 named
  rows' words differ from their description.
  - The audit's dump reader now reads by address segment. CM848's RAM dump gap had shifted 6 records' values by 0x80
    bytes since the tool was written; no in-range verdict changed.
- **Stage C (7f344430), the naming wave (workflow wf_69f8159d-0ca, 14 agents):** the 168 candidates (66 referenced
  no-row records, 20 unnamed_data_ rows, 82 bare-mnemonic names) were all verified: 158 confirmed and 10 amended by
  the skeptics, none refuted. They became 162 rows. Examples:
  - the A/D channels' linearization tables (`<channel>_linearization_values`);
  - the J1939 source address filters (CM550's per-signal bytes of CM848's `j1939_input_source_address_filter_cal`);
  - trip / lifetime fuel used, `user_fueling_state` (38 renders) and the other fueling states, the alpha results,
    the duty cycle monitor maps, the TSC1 gain sets.

  Two of the wave's scalars became per-channel arrays (`analog_sensor_override_values` /
  `analog_sensor_raw_override_values`). 87 unreferenced rows inside the new arrays were removed (legacy guesses such
  as `can_controller_2_baud_byte_0` inside the power take-off governor's gain tables). `validateSecurityKey`'s 8 local
  rows all apply now, and `ApplyLocalVariables` maps `bool`. The refresh keeps the Calterm mnemonics in comments.
- **Stage D (de089dd8), CM848's DM8:** `j1939_pgn65232_payload` (`j1939_pgn65232_payload_t`: SPNs 1224-1228).
  `cm848_sendPgn65232NonContinuousMonitorTestResultMessage` takes `(byte test_identifier, ushort test_value)` (it said
  `dest_address` / `fault_count`), so its CONCAT11 and the DM7 handler's `(byte)` casts are gone.
- **firmware/CLAUDE.md:** no edit this round.
- **Leads (round 91):**
  - Structs, and the `(int)&` casts stage C left:
    - the fault count table (0x805a1c, 125 x 10 bytes; +8 / +9 are named);
    - the datalogger data records (6 bytes from 0x803da4) and trigger records (from 0x803d65);
    - the TSC1 gain sets (4 x 9 i16; CM848's twin type).
  - The wave's notes (`wave_notes_r90.txt`):
    - CM550's J1939 receive handlers are CM848's twins: 0x21a8c / 0x21b88 / 0x21c74 / 0x21d44 =
      `cm848_receivePgn61441` / `61443` / `65264` / `65265*`; 0x21edc = `cm848_tickJ1939InputSupervision`; 0x21ef6 =
      `cm848_registerJ1939InputMessageHandlers`.
    - `cm550_canTransmissionController` (0x21272) is the twin of `cm848_registerJ1939ReceiveHandler`, and
      `cm550_diagnosticSessionValidator` (0x31ace) is `cm848_findTsc1SourceConfiguration`.
    - CM848's `j1939_received_accelerator_pedal_position_2` (0x40aaba) is the J1939 wet tank pressure (e2m 12F7 +14).
    - CM550's J1939 input timeout words are 0x804234-0x804264.
  - The audit's 478 named rows that disagree with their description; a fueling state enum for CM550; one type in
    stage C could not be applied (the build log does not say which).
  - Carried: the misnamed PGN builders; `linearization_table_ch15_x_axis` (channel 0's table); 0x803f40 `_cal`;
    ESCMES / ENGRPM; the DIAG enum members 0x42 / 0x52 / 0x54; the descriptor rows 0x801ab6-0x801b0d;
    `cm550_peakTorqueFuelCorrection`; `cm550_j1939TorqueControlMode*`; `cm848_mathMultiplyDivide32`'s fall-through;
    0x80ddd3; the A/D array-end bound render.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "\n**Round 90.**\n"
     "- **Stage A (eef9fc0c):** CM550's parameter ID table (`parameter_id_table`, `cm550_lookupParameterIdAddress`);\n"
     "  `e2m_block_addresses.py` resolves CM550 and rewrites `parameter_id_lookup_table.csv` (with a staleness test).\n"
     "- **Stage B (5742ef45):** `e2m_name_audit.py` audits CM550; its dump reader handles both short dumps.\n"
     "- **Stage C (7f344430):** a skeptic-verified naming wave from that audit: 162 CM550 rows (the A/D linearization\n"
     "  tables, the J1939 source address filters, the fueling states, ...), two per-channel override arrays,\n"
     "  `validateSecurityKey`'s locals.\n"
     "- **Stage D (de089dd8):** CM848's DM8 payload as a struct; its builder's parameters.\n"
     "\n## Test plan\n")
edit(pr, "- **Beyond CM848 (rounds 72-89):**", "- **Beyond CM848 (rounds 72-90):**")
edit(pr, "- [x] Round 89: D: ",
     "- [x] Round 90: D: CM848 verify DETERMINISTIC (3 functions changed: the DM8 builder, its initializer, the DM7 handler); headers 0 g++ errors; _cal HARD 0.\n"
     "- [x] Round 90: C: CM550 verify DETERMINISTIC (0 functions removed / added; 124 changed by the names / types; caller artifacts unchanged; validateSecurityKey's build error and 6 warnings gone); test suites pass; headers 0 g++ errors; _cal HARD 0.\n"
     "- [x] Round 90: B: test_e2m_name_audit passes (the reader across CM848's gap and CM550's shift); the CM848 audit's output changes only in the 5 gap-shifted values.\n"
     "- [x] Round 90: A: CM550 verify DETERMINISTIC (1 function changed: the lookup's table reads); CM848 byte-identical (common.sh message); test_e2m_block_addresses passes (CM550 ranges, mirror, 723 entries, the table CSV current).\n"
     "- [x] Round 89: D: ")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 90: CM550's parameter ID table, the CM550 e2m audit, a naming wave, DM8 (`session_folder/round90/`)\n\n"
       "- **Stage A:** `find_cm550_table_r90.py` / `check_cm550_table_layout_r90.py` (the table's layout, against the CSV),\n"
       "  `apply_r90a.py`, `check_e2m_parameter_rule_r90.py` / `diff_parameter_table_r90.py` / `classify_table_names_r90.py`\n"
       "  (the old CSV columns against the regenerated table). The tool changes are in the commit.\n"
       "- **Stage B:** `cm550_e2m_census_r90.py` (the first census), `gap_effect_r90.py` (the CM848 reader fix's effect).\n"
       "- **Stage C:** `wave_candidates_r90.py` / `make_batches_r90.py` (`wave/`: the candidates and batches, the agents'\n"
       "  scratch), `wave_result_r90.json` / `wave_notes_r90.txt` (the workflow's proposals, verdicts and notes),\n"
       "  `tally_wave_r90.py` / `show_wave_r90.py`, `apply_r90c.py` (with the two array overrides), `extend_map_r90c.py`,\n"
       "  `apply_r90c_vsk.py` (validateSecurityKey), `keep_r90c.txt` (the Calterm names the refresh keeps).\n"
       "- **Stage D:** `apply_r90d.py`.\n"
       "- **Closing:** `apply_r90_closing.py`, `update_large_tar_r90.sh`.\n")
if "## Round 90:" not in t:
    i = t.index("## Round 89:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "with their Calterm names, the CM550 README - open:",
     "with their Calterm names, the CM550 README; round 90: CM550's parameter ID table and e2m audit, a 162-row naming "
     "wave, CM848's DM8 payload - open:")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
for name, pat, rep in (("MEMORY.md", r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)"),
                       ("pr53_egr_flow_delay_rounds.md", r"is still OPEN on 2026-11-24\n\(\d+ commits\)",
                        f"is still OPEN on 2026-11-24\n({count} commits)")):
    p = M + name
    s = open(p).read()
    s2 = re.sub(pat, rep, s)
    assert f"{count} commits" in s2, name
    open(p, "w").write(s2)
log = M + "pr53_egr_flow_delay_rounds.md"
s = open(log).read()
note = ("- Round 90 (CM550's ROM parameter ID table 0x35224 typed + cm550_lookupParameterIdAddress; e2m_block_addresses.py / "
        "e2m_name_audit.py --firmware cm550; parameter_id_lookup_table.csv regenerated + staleness test; a 14-agent "
        "skeptic-verified wave named 162 CM550 rows; refresh_other_csvs.py has no --keep (filter its map); CM848 DM8 "
        "payload struct; round 91 = the fault count / datalogger / TSC1 gain set structs + the wave's twin leads)\n")
if "- Round 90 (" not in s:
    open(log, "w").write(s.rstrip("\n") + "\n" + note)
table = M + "cm848_parameter_id_table.md"
s = open(table).read()
add = ("\n\nCM550 too (PR #53 round 90): ROM `parameter_id_table` @ 0x35224 (8-byte entries, 3 id ranges: 0x0000-0x002E / "
       "0x1000-0x1478 / 0x8000-0x8265), read by `cm550_lookupParameterIdAddress`; EEPROM entries map to the RAM mirror "
       "0x803B0A + offset. Resolve with `e2m_block_addresses.py --firmware cm550` (e2m `v64t6_s.e2m` carries "
       "J90350.00's layout); `--write-table` regenerates `output/parameter_id_lookup_table.csv` (a test fails when it is "
       "stale).\n")
if "CM550 too (PR #53 round 90)" not in s:
    open(table, "w").write(s.rstrip("\n") + add)
idx = M + "MEMORY.md"
s = open(idx).read()
old_line = re.search(r"^- \[CM848 parameter ID table\]\(cm848_parameter_id_table\.md\) — [^\n]*$", s, re.M)
if old_line and "CM550:" not in old_line.group(0):
    s = s.replace(old_line.group(0), old_line.group(0) + "; CM550: ROM 0x35224, `--firmware cm550` (round 90)")
    open(idx, "w").write(s)
print("round 90 closing applied")
