"""Round 63 closing: task 046, PR body, README, todo, memory. Idempotent.
usage: apply_r63_closing.py <repo> <pr_body.md> <hash A> <hash B> <hash C> <count> <proof text file> <unprefixed left>"""
import os
import re
import sys

repo, pr, ha, hb, hc, count, proof_file, left = os.path.abspath(sys.argv[1]), *sys.argv[2:9]
proof = open(proof_file).read().strip()


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 63 (2026-11-23, same PR): the PGN 61184 diagnostic services in both kernels

A peer relay started the round on round 62's lead; the scripts are in `session_folder/round63/`.
- **Stage A ({ha}): the application's service vocabulary.**
  - `EF00_SERVICE_ID` -> `J1939_DIAGNOSTIC_SERVICE`: 24 members named from the handlers the application registers,
    plus 0x0c / 0x0d (the two responses). The old CLIP guesses were wrong for CM848:
    - 0x15 commits the EEPROM mirror;
    - 0x43's 4-byte field is the length;
    - 0x46 is registered, with an offset and a length.
  - The enum types the registrar's `service_id` (all 24 registrations render names), the dispatch table's entry
    field and the dispatcher's `service` local.
  - 23 functions renamed:
    - the 14 handlers on one scheme (`cm848_handleJ1939<member>Service`) and the 4 memory workers;
    - both header-length helpers: `cm848_getJ1939DiagnosticResponseEchoLength` (was `cm848_getLimitCategoryCode`)
      returns how many request bytes a response repeats;
    - `cm848_selectJ1939TransmitBuffer`;
    - service 1, `cm848_requestClearInactiveFaults`: it sets e2m 1080 +2's CLEAR_INACTIVE bit, as DM3 does. The DM3
      handler is renamed too.
  - `j1939_memory_read_reply_services` (0x53a330, 10 bytes). A first build with 11 bytes reached 0x53a33a, the start
    of `cm848_lookupApplicationMemoryRegionType`'s table.
  - `firmware/CLAUDE.md`: the `cm848_lookupParameterIdAddress` callers line listed 3 of the 5 callers.
  - `docs/parameter_by_id_system.md`: a corrections section. Its 20 parameters and handlers are the boot kernel's;
    0x43's bytes 3-6 are the length.
- **Stage B ({hb}): the application's request is a `j1939_rx_msg_t *`** in 20 handlers and workers.
  - 45 casts and 113 placeholder names are gone; one informative cast is added.
  - `parameter_id` is `undefined4`: the lookup hashes all 32 bits, so a halfword type made a CONCAT22.
- **Stage C ({hc}): the boot kernel's twin.**
  - `BOOT_DIAGNOSTIC_SERVICE`, 16 members. It is a separate enum because the boot kernel's 7 downloads a calibration.
  - Wrong prototypes fixed: the read handler's three rows (address / length / response_ptr are the request / the
    address / the length), and the read-by-ID worker's offset and length, which were named reserved and offset.
  - The 12 handlers and workers take the request.
  - 23 functions renamed (`cm848_handleBoot<member>Service` and so on).
  - `boot_kernel_rom_end` is also where the boot read reply table starts.
- **Proof:** {proof}
- **firmware/CLAUDE.md:** two factual edits.
  - Stage A: the callers line.
  - Stage C: the reference refresh updated two renamed boot function names in the kernel flash driver note.
  HARD stays 0 and MISSING 219.
- **Leads:**
  - **Bench:** clip-core's `ECUReader::readParameterService43` sends bytes 3-6 as an offset, and
    `readParameterService46` sends zeros after the ID. On CM848 those bytes are a length (0x43) and an offset plus
    a length (0x46). Check both against the truck before trusting a by-ID read through kuminz-cli.
  - **The two `j1939_tx_msg_t` records** that `cm848_selectJ1939TransmitBuffer` picks are unnamed (0x3fcbc4 single
    frame with data at 0x3fcbd3; 0x3fc4ad transport with data at 0x3fc4bc).
  - **`DIAG_RESPONSE`** could gain the dispatcher's own result codes (2 wrong length / 3 key refused / 8 unknown ID /
    0x18 unknown service / 0x1a key missing) and a spelled-out name.
  - **The dispatcher's `result_code`** splits off a `uVar1` once committed. The importer names locals in one pass,
    so that temp cannot be named.
  - `DAT_003fba10` (round 62's lead) is still open.
  - {left} unprefixed CM848-only functions remain.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 63.**\n"
     f"- **Stage A ({ha}):** the PGN 61184 services are `J1939_DIAGNOSTIC_SERVICE`, named from the handlers the\n"
     "  application registers. The old CLIP guesses were wrong for CM848 (0x43's 4 bytes are the length). The 14\n"
     "  handlers and their workers are named on one scheme, and the read reply table is typed.\n"
     f"- **Stage B ({hb}):** the application's handlers and workers take a `j1939_rx_msg_t *` request (45 casts and\n"
     "  113 placeholder names gone).\n"
     f"- **Stage C ({hc}):** the boot kernel's twin: `BOOT_DIAGNOSTIC_SERVICE`, its wrong read prototypes fixed,\n"
     "  23 functions renamed.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 62:", f"- [x] Round 63: {proof}\n- [x] Round 62:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 63: the PGN 61184 diagnostic services in both kernels (`session_folder/round63/`)\n\n"
       "- **Stage A:** `registrations.py`, `checks_r63a.py`, `service_tables.py`, `apply_r63a.py` (its first draft "
       "`apply_r63a_first_draft.py`), `fix_r63a.py`, `map_r63a.csv`, `params_r63a.csv`. "
       "Checks: `compare_registrations.py`, `leftovers.py`, `check_function_history.py`.\n"
       "- **Stage B:** `signatures.py`, `apply_r63b.py`. Review: `review_typed.py`, `artifacts.py`, `differing.py`.\n"
       "- **Stage C:** `boot_tables.py`, `cm550_names.py`, `apply_r63c.py`, `map_r63c.csv`.\n"
       "- **Proof:** `prove_r63.sh`. **Closing:** `apply_r63_closing.py`, `update_large_tar_r63.sh`.\n")
if "## Round 63:" not in t:
    i = t.index("## Round 62:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md",
     "round 62: the J1939 registration functions and the DM7 test identifier - open: the task 046 leads",
     "round 62: the J1939 registration functions and the DM7 test identifier; round 63: the PGN 61184 diagnostic "
     "services in both kernels - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = ("the J1939 input fault start delay); task 046 leads")
new = ("the J1939 input fault start delay) + round 63 (the PGN 61184 services in both kernels: J1939_DIAGNOSTIC_SERVICE "
       "/ BOOT_DIAGNOSTIC_SERVICE, both handler families named, the request typed; clip-core's 0x43 / 0x46 layouts "
       "disagree with CM848 = a bench lead); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 63 (2026-11-23): {ha} / {hb} / {hc}.\n"
        "    - Typing a request pointer through a closed call chain removed 45 casts.\n"
        "    - A halfword parameter handed whole to a callee that uses all 32 bits gives a CONCAT22. Read the callee's\n"
        "      asm before narrowing.\n"
        "    - A committed local can split a merged variable, and the importer cannot name the split temp.\n"
        "    - Size a table by the code that reads past it.\n")
if "Round 63 (2026-11-23" not in open(f).read():
    open(f, "a").write(note)
print("round 63 closing applied")
