"""Round 51 closing: task 046, PR body, README, todo, memory. No CLAUDE.md edit. Idempotent (guard: new text present).
Stage C (bitfield structs on the two trip information status words) was built and rejected, so the round ships
stages A and B plus this closing commit (which also fixes the single call site's text).
usage: apply_r51_closing.py <repo> <pr_body.md> <hash A> <hash B> <count> <proof>"""
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


T46 = f"""## Done, round 51 (2026-11-22, same PR): the 0x408d38 gap is four blocks, the trip information blocks

A peer relay started the round; the scripts are in `session_folder/round51/`.
- **Round 50's lead, answered:**
  - The 62-byte gap 0x408d38 is four absent blocks back to back: 8B9B 16 + 8C2C 24 + 8BB2 20 + 8B6B 2. No search
    of three blocks or fewer could find it. `split_gap_debug.py` (fix one block, test the rest) and `pair_fill.py`
    found it.
  - The 0x40b592 gap was misread. Its first 22 bytes are 8BB6 (the governor pressure PID, placed in an earlier round
    over 8C34's drifting tail). The rest, 0x40b5a8 +30, has 9816 width-consistent covers of up to three blocks
    (`scored_cover.py`, sign scored instead of rejected), none of them meaningful. A working-RAM span needs a
    semantic anchor, not width alone.
- **Stage A ({ha}, labels and rows):**
  - 8B9B: the transmission temperature defaults and their limp-in delay, in the e2m's vocabulary
    (`transmission_temperature_limp_in_delay_*`, `transmission_temperature_default_during / after_limp_in_delay`,
    the RAM `transmission_temperature_limp_in_delay_timer`).
  - 8C2C (12 records on 12 rows): `transmission_temperature_rationality_maximum_test_time` (was a "minimum driving
    passes"), the start test's transmission limit, and the minimum engine-off time joining the `_rationality_`
    family.
  - 8C2D (RAM 0x40b626): `transmission_temperature_rationality_test_timer`.
  - 8BB2: `transmission_output_speed_minimum` (was `_floor`).
  - 8B6B: a new row, `trip_information_fault_minimum_time`, chosen by its use since 32 blocks fit the 2 bytes.
  - 8B6D (EEPROM mirror 0x3fee58, nine records on nine rows): `trip_information_distance_fault_status_cal` (+C) and
    `trip_information_fault_status_cal` (+E). The e2m's TI_Fault_Period says the delayed fault goes in +E; the code
    puts it in +C.
  - 8B6C (RAM 0x40b638): five rows cited, plus the documentation row `pci_transmit_message_11_fuel_used`.
  - `sensorDiagnosticsConfiguration` -> `cm848_flagTripInformationPowerDownDataLoss`.
  - The stale 8C34 +12 citation at 0x40b58c is dropped. 8C34's +12..+17 records start with CHR_CC 11.25.05.07.
- **Stage B ({hb}, types):**
  - Three i16 rows. They change no rendered line.
  - `TRANSMISSION_TEMPERATURE_RATIONALITY_STATE`: members 0-4 from 8C2D's labels, plus the check's own verdict
    states 5 / 6. The shared `DIAGNOSTIC_MONITOR_STATE` rendered 5 and 6 as `ABORTED|RUNNING` / `ABORTED|PASSED`.
  - A void (void) prototype that removes the 0x30d4 argument the decompiler showed at the call.
- **Bitfield structs: built and rejected (not shipped).**
  - The build changed only the two writer functions and rendered 0 field names on the 14 masks. Every access is a
    whole-word `ori` / `andi` write; nothing tests a bit. Each mask line just gained a
    `(trip_information_*_t)(...)` cast.
  - Both words stay `word`, with every bit spelled out in their row comments.
  - The script is `apply_r51c_bitfield_structs_rejected.py` (log `verify_r51c_bitfield_structs.log`), so the user can
    overrule this in one line.
- **Closing:** the flag function has one call site, a bl at 0x54de0 in `cm848_restartApplicationWithoutReset`
  (`find_branch_callers.py`). `cm848_applicationMain` falls through into that code from 0x54d2c, so both
  decompilations show it. The 0x30d4 is 12500 from `li r3,12500 / mtdec r3`, the decrementer reload. Stage A's plate
  ("cm848_applicationMain twice") and stage B's "two calls" were wrong; the plate and the prototype comment are fixed.
- **Proof:** {proof}
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Leads:**
  - **User call, untested:** a flag enum (power-of-two members) on the two trip information words might render
    `| TRIP_INFORMATION_TRIP_FUEL_USED_OVERFLOW` where the bitfields render nothing. Ghidra already split stage B's
    whole-value constants into member combinations. firmware/CLAUDE.md allows an enum type only for whole-value
    compares, so it was not tried.
  - 0x40b5a8 +30 (vehicle speed state, the rock cycle phase, the road speed governor references, unnamed 0x40b5c0)
    needs a semantic anchor.
  - `initGovernorFlagsAux` only zeroes 0x3fcfba (in the trip counter RAM, never read directly): misnamed, but nothing
    says what the word is.
  - The rest of the transmission RAM 0x40b620-0x40b637 (the OSS period / speed words, 8BB4 / 8BB5?) is untiled.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit("work/tasks/046-cm848-egr-flow-estimate.md",
     "- **Leads:** the two large gaps with unnamed reads (0x408d38 +62, 0x40b592 +52) have no one- or two-block fit; they may\n"
     "  hold three or more blocks.",
     "- **Leads:** the two large gaps with unnamed reads (0x408d38 +62, 0x40b592 +52) have no one- or two-block fit; they may\n"
     "  hold three or more blocks. (Round 51: 0x408d38 is four blocks; 0x40b592 starts with 8BB6.)")
edit(pr, "\n## Test plan\n",
     "**Round 51.**\n"
     f"- **Stage A ({ha}, labels, rows):** the 0x408d38 gap is four e2m blocks: the transmission temperature\n"
     "  defaults and limp-in delay (8B9B), the P0711 rationality calibrations (8C2C), the output shaft speed sensor (8BB2)\n"
     "  and the trip information fault time (8B6B). The same modules' RAM / EEPROM blocks 8C2D / 8B6C / 8B6D are cited\n"
     "  record for record; `sensorDiagnosticsConfiguration` becomes `cm848_flagTripInformationPowerDownDataLoss`.\n"
     f"- **Stage B ({hb}, types):** three i16 rows, `TRANSMISSION_TEMPERATURE_RATIONALITY_STATE` (the shared monitor enum\n"
     "  rendered the check's own states 5 / 6 as OR combinations), and a void prototype.\n"
     "- Bitfield structs for the two trip information status words were built and rejected: every access is a\n"
     "  whole-word mask write, so they rendered no field name and only added a cast to each mask line.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 50:", f"- [x] Round 51: {proof}\n- [x] Round 50:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 51: the 0x408d38 gap is four blocks, the trip information blocks (`session_folder/round51/`)\n\n"
       "- Search: `three_block_fill.py`, `split_gap_debug.py`, `pair_fill.py`, `scored_cover.py` (+ their `.txt` "
       "outputs). **Stage A:** `apply_r51a.py`, `map_r51a.csv`, `prove_r51a.sh`. **Stage B:** `apply_r51b.py`, "
       "`prove_r51b_enum.py`. **Not shipped:** `apply_r51c_bitfield_structs_rejected.py`, "
       "`commit_r51c_bitfield_structs_not_shipped.txt`. `show_function_changes.py` lists the changed lines the type "
       "stages were read by. **Closing:** `find_branch_callers.py`, `apply_r51_call_site_fix.py`, "
       "`apply_r51_closing.py`, `update_large_tar_r51.sh`.\n")
if "## Round 51:" not in t:
    i = t.index("## Round 50:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md",
     "round 50: gaps by access signature (TSC1-lost, throttle) - open: the task 046 leads",
     "round 50: gaps by access signature (TSC1-lost, throttle); round 51: the 0x408d38 gap = four blocks, the trip "
     "information blocks, the P0711 state enum - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "throttle 1585); task 046 leads"
new = ("throttle 1585) + round 51 (the 0x408d38 gap = 4 blocks 8B9B/8C2C/8BB2/8B6B; trip info 8B6B/8B6C/8B6D, "
       "TRANSMISSION_TEMPERATURE_RATIONALITY_STATE; bitfields on mask-only words rejected); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 51 (2026-11-22): {ha} / {hb}. A gap with no fit of three blocks or fewer may hold four: fix the "
        "block whose records match existing rows, then search what is left. Width-only covers of working-RAM spans "
        "are meaningless (9816 for 30 bytes). A shared state enum renders a machine's extra states as OR "
        "combinations; give the machine its own enum. A bitfield struct on a word that is only ever written with "
        "whole-word masks (ori / andi, never tested) renders no field and adds a cast per line: leave it a word.\n")
if "Round 51 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("round 51 closing applied")
