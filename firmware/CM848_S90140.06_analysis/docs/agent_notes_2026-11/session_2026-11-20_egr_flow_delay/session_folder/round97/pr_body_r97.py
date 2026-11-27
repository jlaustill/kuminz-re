"""Round 97 closing: the PR body master gets the round 97 block (after round 96's), the round 97 test lines (before
round 96's) and the 'Open after round 97' item (first in 'Still open'; round 96's item is marked done); the summary's
round range moves to 72-97. Refuses on a missing anchor. usage: pr_body_r97.py <pr_body.md> <stage F sha> <stage F proof line>"""
import sys

p, sha_f, f_proof = sys.argv[1], sys.argv[2], sys.argv[3]
t = open(p).read()
BLOCK = f"""**Round 97.**
- **The abbreviation sweep, in both firmwares (6d1058da, 32b7f149, de66d286, e7d6d5f5):**
  - 139 parameter / local / field names (`rx_msg` -> `received_message`, `config_ptr` -> `configuration_pointer`).
  - 51 enum types and 198 members (`DIAG_SERVICE_ID` -> `DIAGNOSTIC_SERVICE_ID`).
  - 162 function names: `init` -> `initialize`, and diag / tx / rx / temp / param / eps are spelled out.
  - The last 11 struct types (`can_std_rx_desc_t` -> `can_standard_receive_descriptor_t`, `sensor_channel_config_t` ->
    `sensor_channel_configuration_t`).
  - History notes keep the old names.
- **The round 97 workflow:** seven batches, each with an investigator, an independent describer and an adversarial
  judge; their proposals were remapped to the new names before the apply.
  - **CM550's governor families (7c65a16f, R1-R4):**
    - 13 functions and 314 globals; 130 rows inside judged spans go.
    - `cm550_low_speed_governor_gain_set_t` (six instances behind the two gain set pointers), and the
      `LOW_SPEED_GOVERNOR_GAIN_STATE` enum in both firmwares.
    - The aggressive gain logic returns void, which removes its gotos and its CONCAT22 return tracking (34 -> 18
      statements, every branch checked against the machine code).
  - **Engine protection, the request chain and the cylinder balance projections ({sha_f}, R5-R7):**
    - Four CM550 engine protection record types and the nine-channel tables; 407 flat rows inside them go.
    - The PGN 61184 request chain is typed as `can_standard_receive_descriptor_t *` through the dispatcher, the
      validator, the handlers and the workers. 0x224f4 exports a body, so its caller shows four arguments.
    - `ENGINE_PROTECTION_TASK` and CM550's `ENGINE_RETARDER_COMMAND_SOURCE`; the cylinder balance projections are one
      i32[6].
    - 25 twins share one name with CM848: 24 from the batches, and `countEngineProtectionShutdownTime`, settled from
      both firmwares' machine code during the review.
- **A proof review by workflow:** five checkers compared every changed statement count with the machine code, with two
  skeptics per finding. It found one real loss, which is fixed: a hand-written prototype had dropped the PGN 59392
  sender's ACK / NACK parameter at its three callers. It also found an older render defect, now a lead.
- **Cleanups:** 382 rows held the same history note twice; 47 doubled round tags are gone; seven CM848 docs cite the
  new names.

"""
anchor = "## Test plan"
assert t.count(anchor) == 1
t = t.replace(anchor, BLOCK + anchor, 1)
TESTS = f"""- [x] Round 97: F ({sha_f}): {f_proof}
- [x] Round 97: E (7c65a16f): both verify DETERMINISTIC; CM848 changes by enum renders only; CM550 77 functions change,
  the three changed statement counts are checked against the machine code; pieces 507 -> 510 (three honest reads of the
  i32 integrator's low word, which were `_DAT_00800718`).
- [x] Round 97: A-D (6d1058da / 32b7f149 / de66d286 / e7d6d5f5): label-only in both firmwares (every rename mapped, no
  other token change, statement counts and pieces equal); every build DETERMINISTIC.
"""
anchor = "- [x] Round 96: H ("
assert t.count(anchor) == 1
t = t.replace(anchor, TESTS + anchor, 1)
OPEN = """- **Open after round 97** (task 046):
  - Engine protection: CM550 0x18fcc against `cm848_updateEngineProtectionShutdown`; 0x19960 and 0x1c630; the 10B3
    words.
  - J1939: CM550's remaining set-ups and its transport layer; the PGN 61184 dispatcher's handler pointer, which needs a
    function-pointer type.
  - The misnamed all speed governor and acceleration noise control functions.
  - `cm550_calculateCylinderBalanceTrims`' six dropped pass-1 stores, a decompiler alias problem.
  - The judges' other leads (task 046).
"""
anchor = "- **Open after round 96** (task 046)"
assert t.count(anchor) == 1
t = t.replace(anchor, OPEN + "- **Open after round 96** (task 046; done in round 97)", 1)
old = "**Beyond CM848 (rounds 72-96):**"
assert t.count(old) == 1
t = t.replace(old, "**Beyond CM848 (rounds 72-97):**")
open(p, "w").write(t)
print("ok")
