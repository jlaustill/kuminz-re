"""Round 96 closing: the PR body master gets the round 96 block (after round 95's), the round 96 test lines (before
round 95's) and the 'Open after round 96' item (first in 'Still open'); the summary's round range moves to 72-96.
Refuses on a missing anchor. usage: pr_body_r96.py <pr_body.md> <stage H sha>"""
import sys

p, sha_h = sys.argv[1], sys.argv[2]
t = open(p).read()
BLOCK = f"""**Round 96.**
- **Types spelled out (8bbdb24c, 7b3c9fd3):** 19 CM848 peripheral struct types (`tpu3_ch_params_t` ->
  `tpu3_channel_parameters_t`, `qadc64_regs_t` -> `qadc64_registers_t`, `usiu_memc_t` -> `usiu_memory_controller_t` ...)
  and the J1939 / CAN types of both firmwares (`j1939_rx_msg_t` -> `j1939_received_message_t`, 91 rendered lines;
  `j1939_tx_msg_t` -> `j1939_transmit_message_t` ...).
- **Every TPU3 channel parameter block is a struct instance (db9bfe59):** 24 more blocks; the speed sensors' period
  accumulators and the TPU-A channel 4 recharge interval get dword layouts. **Seven unnamed EMA filter states (0d4cafee)**
  and the two EGR orifice temperature stages are named.
- **The boot kernel's CMF tables (fb4b434c)** in the time-shared RAM 0x3fdba4-0x3fdc38 are named by their erase / program
  role; the rows the application reads keep their `_cal` names, and firmware/CLAUDE.md's TIME-SHARED caution lists the
  real application reads.
- **The round 96 workflow (07f7a70e, 2be5a272):** five batches (an investigator, an independent describer and a judge
  each); nothing refuted.
  - The J1939 periodic builders of both firmwares, paired by PGN: five twins, twelve counterparts; four CM550 builders
    reached only through the scheduler get function rows.
  - CM550's PGN 59904 request responders: the registrar's prototype makes its 24 calls show the PGN and the handler.
  - CM550's placeholders 0x10e06-0x2dfff: cylinder balancing (its state typed as arrays), four more twins, the J1708
    memory write records, the speed input set-ups.
  - New payload types (RC / DM5 / CCSS in CM550, DM5 in CM848); CM848's `j1939_pgn_dispatch_table` is a 32-entry array
    like its CM550 twin.
- **Seven CM550 functions decompile ({sha_h}):** each had a row but no body, because the decompiler failed ('Cannot
  properly adjust input varnodes') on its 2-byte-slot stack arguments; full prototypes fix all seven, and their callers
  show the arguments (one rendered `registerJ1939DiagnosticService(2,T,T)`). The serial EEPROM write queue is one
  family: its two 1280-entry rings are typed and the 175 never-referenced rows inside them are gone. The build's
  '1 function imports failed' warning was each `function_renames.csv` header sitting below comment lines; it is gone.
- **Cleanups:** 55 plates that named their twin twice; CM848's parameter ID table (its 'MPC555_REG' rows are the DPTRAM
  array, not QADC registers) and CM550's regenerated table; three enum members spelled out.

"""
anchor = "## Test plan"
assert t.count(anchor) == 1
t = t.replace(anchor, BLOCK + anchor, 1)
TESTS = f"""- [x] Round 96: H ({sha_h}): both verify DETERMINISTIC with no import failure and no SCRIPT ERROR; CM848's .cpp is
  identical apart from the Generated line; CM550 713 -> 720 bodies (the seven functions); every caller change is the
  new arguments or a byte return (statement-count changes checked with a temporaries-normalized diff); the one local
  row the renumbering moved (`currentTimerCount`) is retargeted.
- [x] Round 96: G (2be5a272): both verify DETERMINISTIC; CM848 changes only by the six mapped renames; CM550's changes
  outside the map are the array typings, renamed rows that lose their underscore and retyped temporaries; the one
  rendering change (an intermediate store plus add.l to memory shown as one assignment) checked against the machine code.
- [x] Round 96: F (07f7a70e): both verify DETERMINISTIC; CM550 706 -> 713 functions; statement-count changes are
  declarations (checked normalized); 4 new pieces, all honest half-word accesses; the overlap check's one new row is a
  documentation row.
- [x] Round 96: E (fb4b434c): CM848 verify DETERMINISTIC; function set and statement counts equal; pieces 1378 -> 1370.
- [x] Round 96: A-D: label-only (A, C), struct instances (B: pieces 1379 -> 1378), names (D); every build
  DETERMINISTIC.
"""
anchor = "- [x] Round 95: C (the round 95 workflow)"
assert t.count(anchor) == 1
t = t.replace(anchor, TESTS + anchor, 1)
OPEN = """- **Open after round 96** (task 046): the abbreviation sweep, ready to apply (139 parameter / local / field names and 11
  struct types in both firmwares; then ~48 enum types with their members and the ~180 `init` / `diag` / `tx` / `cbd`
  function names); CM550's engine protection cluster 0x18c1c-0x18dae (bare 'protection' names); CM550's J1939 diagnostic
  request chain typed as `can_std_rx_desc_t *`; the cylinder balance projection words; the numbered empty stubs; the
  judges' leads (task 046).
"""
anchor = "- **Open after round 95** (task 046)"
assert t.count(anchor) == 1
t = t.replace(anchor, OPEN + anchor, 1)
old = "**Beyond CM848 (rounds 72-95):**"
assert t.count(old) == 1
t = t.replace(old, "**Beyond CM848 (rounds 72-96):**")
open(p, "w").write(t)
print("ok")
