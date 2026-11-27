"""Round 27 closing: task 046, PR body, README, todo. Idempotent.
usage: apply_r27_closing.py <repo> <pr_body.md> <stage A hash> <stage C hash> <stage B hash>"""
import os
import sys

repo, pr, ha, hc, hb = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 27 (2026-11-22, same PR): the sensor channel layer, the J1939 switch inputs, the fault bits

The user approved two open decisions ("approved", read as yes to both questions of the round 26 report): the named
fault bitfields and the firmware/CLAUDE.md J1939 note. Scripts are in `session_folder/round27/`.
- **Stage A ({ha}, label-only): the sensor channel families.**
  - The four base functions run one 13-parameter algorithm. A machine code diff of the two periodic bodies shows Type A
    signed (lookup flags 2, `lha`, `cm848_signedFirstOrderFilter`) and Type B unsigned (flags 0, `lhz`,
    `exponentialMovingAverage`).
  - Type B also skips the threshold faults of three channels: 47 until `cruise_control_switches_learned_flag`, 71 until
    its learned flag, and 10 while `oil_pressure_switch_only_cal` is set.
  - Their names had the periodic / boot roles inverted. Now `cm848_processSignedSensorChannel` /
    `cm848_initializeSignedSensorChannel` / `cm848_processUnsignedSensorChannel` / `cm848_initializeUnsignedSensorChannel`.
  - The 63 wrappers are `cm848_process<Channel>Channel` (periodic) and `cm848_initialize<Channel>Channel` (boot).
  - 91 blocks are named by channel, among them the newly identified channels 29 (`engine_speed_sensor_supply_voltage`,
    e2m 8A1E-8A21; SV = supply voltage), 77 (`boost_pressure_absolute`, 17DB-17DE), 88 (`exhaust_throttle_position`,
    1813-1816) and 75 (`egr_valve_position`, 17CF-17D2). Channels 54 / 55's tables (e2m 81CC-81D1 Booster_Cap) were
    `injector_group_a / b_*`.
  - **Finding:** channel 88's wrapper passes the fuel temperature outputs 0x40bdd0 / 0x40bdd2 / 0x40be3a (the stack
    stores at 0x500128-0x500148). Channel 88 is disabled here (`sensor_channel_enable_bits_cal` word 5 = 0x047f), and its
    disabled path still writes its default 0x2400 and status 0x100 there each main-loop cycle (phase 25). So channels 7
    and 88 write the same three words. The dump holds channel 7's values (0x1200, status 2).
- **Stage C ({hc}, label-only + firmware/CLAUDE.md): the J1939 switch inputs.**
  - The peer session's item 5 checked out. `j1939_input_signal_descriptor_t`'s third field is `logical_switch` (was
    `fault_bit_index`). `cm848_evaluateJ1939InputSignalFault` sets / clears that switch's datalink state bit when its
    datalink-source bit is set and the J1939 priority wins.
  - The table maps the brake switch to 11, the clutch to 15, PTO on to 3, the remote PTO to 19 and the accelerator
    interlock to 26; cruise and the other inputs go to 31, the unwired switch.
  - firmware/CLAUDE.md's consumers bullet now says so: J1939 can drive the brake / clutch / PTO switches, not cruise.
- **Stage B ({hb}, types): one bitfield per fault in `fault_bit_words_t` words 1-49.**
  - 316 bits have e2m 1036 names (the uncertain expansions checked against the bits' setters); the others are
    `fault_<n>`.
  - Word 0 stays the plain word `faults_0_to_15`, the base of the 200 indexed accesses.
  - The measured trade: 674 tests and 109 writes now name their fault, against 943 piece tokens. 856 of those are the
    set / clear writes, which Ghidra 12.1 does not fold.
  - A nested type per word was built and rejected (`ZPULL(...)` renders).
  - The mask-exact proof matches 1964 functions; the other 4 differ only structurally and were read by hand.
- **Round 27 leads:**
  - Word 0's seven named bits (RAM image word, fuel shutoff, turbocharger wastegate driver 1, fuel pressure idle,
    HPCR OBD deviation) stay in its comment. The indexed accesses keep it a plain word.
  - The `fault_<n>` bits with unresolved e2m abbreviations: CORS (37 / 38), T2 (206-215), TAS (216 / 217), PP
    (709 / 710), Chry_Dat42 (308), the cruise SC source (146 / 147).
  - Channel 88's writes into the fuel temperature words: a calibration with channel 88 enabled would put the exhaust
    throttle position into `fuel_temperature_sensor_value`.
  - From the earlier rounds: TouCAN B's base, the "Can2" mailbox writer's name, the boot kernel transport's message
    parameter, `diag_clear_flags_t`.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit("work/tasks/046-cm848-egr-flow-estimate.md",
     "  - From round 24: named fault bits (the user's call) and `diag_clear_flags_t`.",
     "  - From round 24: `diag_clear_flags_t` (the named fault bits are done in round 27).")
edit(pr, "\n## Test plan\n",
     "**Round 27 (the user approved the named fault bits and the CLAUDE.md J1939 note).**\n"
     f"- **Stage A ({ha}, label-only):** the sensor channel layer. The inverted periodic / boot names are fixed (four base\n"
     "  functions signed / unsigned, 63 wrappers process / initialize), and 91 blocks are named by channel from e2m. Finding:\n"
     "  disabled channel 88 (exhaust throttle) writes the fuel temperature outputs.\n"
     f"- **Stage C ({hc}, label-only + firmware/CLAUDE.md):** the J1939 descriptor's third field is the logical switch\n"
     "  (brake 11 / clutch 15 / PTO 3 / remote PTO 19 / interlock 26 / cruise and the rest 31); the CLAUDE.md mechanism text\n"
     "  is corrected.\n"
     f"- **Stage B ({hb}, types):** one bitfield per fault in `fault_bit_words_t` words 1-49 (316 e2m names, the rest\n"
     "  `fault_<n>`). 674 tests and 109 writes are named; 943 piece tokens, 856 of them on set / clear writes.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 26: stage A is EQUIVALENT.",
     "- [x] Round 27: stages A and C are EQUIVALENT; stage B passes the mask-exact proof (1964 functions identical, 4\n"
     "  structural differences read by hand).\n- [x] Round 26: stage A is EQUIVALENT.")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 27: the sensor channel layer, the J1939 switch inputs, the fault bits (`session_folder/round27/`)\n\n"
       "- **Stage A:** `channel_calls.py` / `channel_identity.py` / `wrapper_census.py` (the census and the e2m evidence), "
       "`asm_diff.py` (Type A vs Type B), `generate_r27a.py` -> `worklist_r27a.py` + `labels_r27a.tsv`, "
       "`apply_r27a_labels.py`, `refresh_rest_r27a.py`, `derived_ptr_rows.py` (the proof's PTR_ labels).\n"
       "- **Stage C:** `spec_r27c.py`, `apply_r27c.py`.\n"
       "- **Stage B:** `fault_bit_names.py` -> `fault_field_names.py` (the names, the expansions and their evidence), "
       "`fault_setters_r27.py`, `bitfield_words.py` (flat, the layout kept) / `bitfield_words_nested.py` (rejected), "
       "`fault_render_census.py`, `piece_contexts.py`, `per_word_tradeoff.py`, `prove_fault_bitfields.py` + "
       "`diff_function_r27b.py` (the mask-exact proof).\n"
       "- **Closing:** `apply_r27_closing.py`.\n")
if "## Round 27:" not in t:
    i = t.index("## Round 26:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "(a peer cruise review) - open: the task 046 leads",
     "(a peer cruise review); round 27: the sensor channel layer (the inverted names fixed), the J1939 switch inputs, "
     "one bitfield per fault - open: the task 046 leads")
print("round 27 closing applied")
