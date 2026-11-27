"""Round 20 closing: the round 20 sections of task 046, the PR body, the session README and the todo line, the stale
open item in the PR body (the switch bytes bitfields shipped in round 16), and the current texts that named round 20's
old names (todo line 32, thermal_protection_trigger.md). Idempotent. usage: apply_r20_closing.py <repo> <pr_body.md>
<stage E hash>"""
import os
import sys

repo, pr, e_hash = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t and t.count(old) <= t.count(new):
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


t46 = "work/tasks/046-cm848-egr-flow-estimate.md"
TASK = f"""## Done, round 20 (2026-11-22, same PR; the relayed "keep going" again): the algorithm enable flags block

Scripts are in `session_folder/round20/`.
- **The block:** e2m 106B (AENBLFLG) is the algorithm enable flags table. It is the 90-byte CRC-guarded EEPROM block
  0x118-0x171 (RAM 0x3fd59a + offset): a length word (+0) and 44 flag words, the e2m's word N at +2+2N.
  - The code reads it three ways. Most reads are masked tests of the named words.
  - The engine protection loops compute bit numbers from word 0: `(&algorithm_enable_flags_0_cal)[bit >> 4] &
    1 << (bit & 15)`, with bit = 128 + 4n + k and 420 + n. They run over one channel in this build (the fuel
    temperature derate channel at 0x597b2; the channel table ends after its 36 bytes). So they read word 8 bits 0-3
    (`Fuel_Temperature_{{Fueling_Limiting, RPM_Limiting, Shutdown, Restart}}_Enable`) and word 26 bit 4
    (`Fuel_Temperature_Data_Noderate_Enable`).
  - `calculateAlpha` reads words 0, 1, 12 and 19 through a pointer to word 0.
  - Nothing of these reaches word 3, so stage B's "no reader" comments and round 19's ANC claim hold.
- **Stage A (7117c24, label-only):** 17 words had guessed names. Word 3 was `j1939_governor_feature_cal`; the others
  were `governor_*`, `j1939_*` and `*_feature_*` guesses. Each is now `algorithm_enable_flags_<N>_cal`, with its e2m
  bits in the comment. The code agrees: word 29 0x100 is DM13, 0x20 / 0x40 the PGN 56832 resets, 0x800 the throttle
  error handler; word 28 0x400 is the J1939 input layer.
- **Stage B (516e3be, types):** `algorithm_enable_flags_3_t`, the PTO / cruise control / road speed governor / set
  speed save enables. Bit 8 has no record; its readers make the road speed governor a hard limit with no droop outside
  top gear.
- **Stage C (9c46007, label-only):**
  - `cold_delta_fuel` (0x40b22a, was `fuel_demand_offset_correction`) is e2m 8A9F `Cold_Delta_Fuel`. Its table
    (8AA0-8AA2, coolant temperature x engine speed) and `cm848_calculateColdDeltaFuel` are renamed with it. Each of
    its nine gated additions sits behind a `*_Cold_Increment_Enable` bit whose record says 'add Cold_Delta_Fuel to
    <that limit>'. This resolves round 18's note on the altitude derate limit.
  - `cm848_calculateInjectionTimingMainMisfireLimit` (was `cm848_processEngineConfigSpeedControl`).
  - The read 'guess (not proven, so reserved)' bits of the wave 11 structs 12 / 18 / 41 take their e2m names. Their
    e2m-named unread bits are named as word 3's are.
  - New rows: the length word `algorithm_enable_flags_table_length_cal` (the CRC scan starts there; it holds 70 in the
    dump, not 90) and words 7 / 8 / 11 / 26.
  - Word 11 bit 3 (`J1939_Communication_Enable`) was an unnamed `DAT_003fd5b2` that gates the J1939 transmit queues and
    the receive dispatch. The label-only proof found it.
- **Stage D (797ec46, types):** 17 more bitfield structs, on words 1, 2, 5, 6, 13, 19, 20, 21, 25, 27, 28, 29, 31, 32,
  40, 42 and 43. 117 bits are named from a matching reader, 50 from a single spelled-out record, and 105 are reserved.
  Word 0 stays a word, because the loops index from it. The cold delta fuel cache is `word[2]`.
  - **Naming tiers (from the advisor):**
    - a read bit takes its record's name when the reader agrees, or its behaviour's name when there is no record;
    - an unread bit takes its record's name only when exactly one record sits on it and the description spells the
      words out;
    - the rest stay `reserved_bit_N`, with the record and the reader in the comment. 'SS', 'CSE', 'VGA', 'QPID',
      'OOG' and 'TVA' are never spelled out.
  - Where two records share a bit (word 19 0x200 / 0x2000), the reader picks.
  - A multi-bit e2m mask goes by its value list. Word 32's `Equivalent_Throttle_Enable` has mask 7 and 4 = ENABLE;
    the code tests 4.
  - Read bits with no record:
    - word 29 0x1000, the fuel delivery pressure byte of PGN 65263;
    - word 40 0x4000 / 0x8000, the retarder fault mask / PTO inhibit;
    - word 42 0x1000, the gear ratio torque management (the e2m's `Torque_Mgmt_GR_Enable` sits on 0x800, which
      nothing reads);
    - word 21 0x8000, kept reserved.
  - The dump fits the truck: word 40 sets `j1850_communication_enable` (the PCI bus), word 43
    `vacuum_throttle_cruise_enable` (the vacuum cruise servo) and `wastegate_solenoid_driver_enable`, and word 6
    `transmission_control_enable` (the 48RE).
- **Stage E ({e_hash}, label-only):** `cm848_initializeColdDeltaFuelLookupCache` (was
  `mpc555_initFuelDemandOffsetFilter`). Stage D's cache typing showed it only presets the lookup cache.
- **Methods:**
  - A "no reader" claim needs three searches:
    - the name's masked tests;
    - unnamed `DAT_` references in the range (the label-only proof found word 11's);
    - the computed and pointer reads (the engine protection loops, `calculateAlpha`).
  - The scratch `refresh_enums_structs.py` replaced a field map row's old name (`reserved_bit_N`) in every struct. It
    now skips field rows, and a generic field name is renamed per struct.
- **Round 20 leads:**
  - `calculateAlpha` keeps the flags base in r4 across `cm848_calculateAlphaAltitudeDerateLatch`; the callee never
    touches r4. Ghidra joins r3:r4 into a `ulonglong` and renders the pointer as the call's result. A locked prototype
    would leave r4 undefined after the call; a fix needs a calling convention that keeps r4.
  - The PGN 65269 ambient air temperature bytes (`DAT_003faac5`) are unnamed.
  - The length word's 70 does not match the block's 90 bytes.

## Leads (not in this PR)
"""
t = open(path(t46)).read()
if "## Done, round 20" not in t:
    assert t.count("## Leads (not in this PR)\n") == 1
    open(path(t46), "w").write(t.replace("## Leads (not in this PR)\n", TASK, 1))
PR_ROUND = f"""**Round 20 (the relayed "keep going" again): the algorithm enable flags block.**
- **Stage A (7117c24, label-only):** the 17 guessed flag words named by their e2m 106B word numbers
  (`algorithm_enable_flags_<N>_cal`; word 3 was `j1939_governor_feature_cal`).
- **Stage B (516e3be, types):** `algorithm_enable_flags_3_t`, the cruise / road speed governor / PTO enables.
- **Stage C (9c46007, label-only):** `cold_delta_fuel` (e2m 8A9F, was `fuel_demand_offset_correction`) and its table,
  the misfire timing limit function, the wave 11 structs' proven guessed bits, and rows for the length word and words
  7 / 8 / 11 / 26.
- **Stage D (797ec46, types):** 17 more flag words as bitfields: 117 bits named from a matching reader, 50 from a
  single spelled-out record, 105 reserved. Plus the cold delta fuel cache.
- **Stage E ({e_hash}, label-only):** the cold delta fuel cache initializer.

## Test plan
"""
edit(pr, "\n## Test plan\n", "\n" + PR_ROUND)
edit(pr, "- [x] Round 19: stages A, C and D are EQUIVALENT;",
     "- [x] Round 20: stages A, C and E are EQUIVALENT; stages B and D pass the mask normalizer (D's count gate: per "
     "word and mask, old masked reads = new field reads; pieces 464 -> 464).\n"
     "- [x] Round 19: stages A, C and D are EQUIVALENT;")
edit(pr, "- **Open after round 19:**\n  - the droop word at 0x40aedc and the task 046 leads;",
     "- **Open after round 20:**\n  - the droop word at 0x40aedc and the task 046 leads;")
edit(pr, "  - the switch bytes 0 / 1 / 3 as bitfields (the user's call; see round 11);\n",
     "  - `calculateAlpha`'s r4 alias (a calling convention question) and the PGN 65269 ambient temperature bytes;\n")
edit(pr, "round 14 the low speed governor reference speed chain.",
     "round 14 the low speed governor reference speed chain; round 16 the switch bytes 0 / 1 / 3 bitfields (the user "
     "approved them); round 20 the algorithm enable flags block.")
README = path("firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md")
t = open(README).read().rstrip("\n")
if "## Round 20" not in t:
    t += """

## Round 20: the algorithm enable flags block (`session_folder/round20/`)

- **Stage A:** `worklist_r20a.py`, `make_worklist_r20a2.py` (generates `worklist_r20a2.py`). **Stage B:** `apply_r20b.py`
  + `normalize_r20b.py`. **Stage C:** `worklist_r20c.py`, `apply_r20c2.py` (its structs-only rerun
  `apply_r20c2_structs.py`), `apply_r20c3.py`. **Stage D:** `apply_r20d.py` (the naming table and its checks) +
  `normalize_r20d.py`. **Stage E:** `worklist_r20e.py`. **Closing:** `apply_r20_closing.py`.
- **Evidence:** `flag_word_uses.py` / `bit_readers.txt` (the readers of each bit), `flag_records.txt` /
  `flag_records_typed.txt` (the e2m records with their descriptions), `bit_context.py` (the code around a bit's
  tests).
"""
    open(README, "w").write(t + "\n")
TODO = path("work/todo.md")
lines = open(TODO).read().split("\n")
i = next(k for k, l in enumerate(lines) if l.startswith("046 [>]"))
if "round 20" not in lines[i]:
    old_tail = "the ANC pass-through - open: the task 046 leads"
    assert lines[i].endswith(old_tail), lines[i][-60:]
    lines[i] = lines[i][:-len(" - open: the task 046 leads")] + (
        "; round 20: the algorithm enable flags block (e2m 106B) - 17 words named, 18 bitfield structs, "
        "cold_delta_fuel - open: the task 046 leads")
    open(TODO, "w").write("\n".join(lines))
edit("work/todo.md", "j1939_input_processing_enable_cal 0x400",
     "algorithm_enable_flags_28_cal.j1939_multiplex_enable (0x400)")
edit("firmware/CM848_S90140.06_analysis/output/thermal_protection_trigger.md",
     "`j1939_feature_enable_flags` = `j1939_feature_enable_flags_cal`",
     "`j1939_feature_enable_flags` = `algorithm_enable_flags_29_cal`")
edit("work/tasks/042-table-campaign-rename-leads.md",
     "- `fuel_demand_offset_correction` at 0x0040a550 and 0x0040b22a (bin 13).",
     "- `fuel_demand_offset_correction` at 0x0040a550 and 0x0040b22a (bin 13). (0x40a550 is "
     "injection_timing_torque_to_fuel_adjustment since rename wave 5, PR #50; 0x40b22a is cold_delta_fuel, e2m 8A9F "
     "Cold_Delta_Fuel, since PR #53 round 20.)")
print("closing edits applied")
