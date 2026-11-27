"""Round 32 closing: task 046, PR body, README, todo, memory. Idempotent.
usage: apply_r32_closing.py <repo> <pr_body.md> <stage A hash>"""
import os
import sys

repo, pr, ha = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 32 (2026-11-22, same PR): the discrete output read-back checks

A peer relay started the round. Scripts are in `session_folder/round32/`.
- **The finder:** `messy_functions.py` ranks the functions by their unnamed data renders. `cm848_mainLoopMonitor`
  was first, with 55 distinct `DAT_` labels.
- **Stage A ({ha}, labels and types):**
  - The read-back check of 11 discrete outputs: `cm848_checkDiscreteOutputReadBack` /
    `cm848_monitorDiscreteOutputReadBack` / `cm848_initializeDiscreteOutputReadBackChecks`. Before, they were
    `diag_faultMatch_outputCheck_update` / `cm848_mainLoopMonitor` / `cm848_initSensorCalibration`.
  - The check's nine parameters are named.
  - `discrete_output_read_back_counters_t` has 11 instances, and each output has a word retry count.
  - The pass count and the key-off snapshot are named.
  - Faults 146 / 147 are the cruise servo supply driver's (logical output 21, e2m 1577 Cruise_SC_Source_Driver).
  - The time-shared 0x3fd284 / 0x3fd298 are covered by named data, so their boot calls are call overrides and the
    `BYTE_` labels are gone (firmware/CLAUDE.md updated).
- **The proof:** tokens from the map, on copies with wrapped member names joined. Every function matches except the
  check (equal with its parameters renamed) and one local declaration reorder.
- **Leads, the rest of the ranking:**
  - the injection state initializers (`cm848_initializePilotInjectionQuantityState` 25 labels, `...TimingState`
    19, `...AuxiliaryInjectionQuantityState` 17, `cm848_initializeCombustionReferenceMapPointers` 21);
  - `cm848_buildPgn65249RetarderConfigurationMessage` (18; a payload like EC1);
  - `cm848_initPgn65242SoftwareIdHandler` (17), `cm848_processFaultScanLookup` (12), `cm848_sciCommand20Callback`
    (15).

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 32.**\n"
     f"- **Stage A ({ha}, labels and types):** the discrete output read-back checks. The check, its monitor and\n"
     "  initializer are named, the four counters are a struct with 11 instances, each output has a retry word, and faults\n"
     "  146 / 147 are the cruise servo supply's. These were 55 `DAT_` labels.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 31: stage A changes only the two EC1 functions, each access checked.",
     "- [x] Round 32: stage A matches token for token apart from the check's parameter names (verified) and one\n"
     "  declaration reorder.\n- [x] Round 31: stage A changes only the two EC1 functions, each access checked.")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 32: the discrete output read-back checks (`session_folder/round32/`)\n\n"
       "- **Finder:** `messy_functions.py`. **Stage A:** `output_check_calls.py`, `worklist_r32a.py`, `apply_r32a.py`; "
       "the proof `make_tokens_r32a.py`, `flatten_cpp.py`, `check_two_r32a.py`. **Closing:** `apply_r32_closing.py`.\n")
if "## Round 32:" not in t:
    i = t.index("## Round 31:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 31: the J1939 EC1 payload struct - open: the task 046 leads",
     "round 31: the J1939 EC1 payload struct; round 32: the discrete output read-back checks - open: the task 046 "
     "leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = m.replace("(cm848/egr-flow-delay-model, 167 commits)", "(cm848/egr-flow-delay-model, 169 commits)")
old = "(the J1939 EC1 PGN 65251 payload struct, 2 instances); task 046 leads"
new = ("(the J1939 EC1 PGN 65251 payload struct, 2 instances) + round 32 (the discrete output read-back checks, 11 "
       "outputs; messy_functions.py ranks what is left); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = ("  - Round 32 (2026-11-22): cad1457 messy_functions.py (rank functions by DAT_ / ram0x / pieces) -> the discrete "
        "output read-back checks (cm848_checkDiscreteOutputReadBack + 11 discrete_output_read_back_counters_t "
        "instances + retry words; faults 146 / 147 = cruise servo supply). Proof trick: flatten_cpp.py joins member "
        "names wrapped after '.', or token maps miss long names. Next on the ranking: the injection state "
        "initializers, PGN 65249 / 65242 builders.\n")
if "Round 32 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("round 32 closing applied")
