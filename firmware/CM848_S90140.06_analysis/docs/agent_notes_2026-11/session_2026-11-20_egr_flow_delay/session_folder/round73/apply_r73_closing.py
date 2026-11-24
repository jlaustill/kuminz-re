"""Round 73 closing: task 046, PR body, session README, todo, memory. Idempotent (each edit skips when its new text is
already there).  usage: apply_r73_closing.py <repo> <pr_body.md> <hash A0> <hash A> <hash B> <hash C> <count> <proof A> <proof B> <proof C>"""
import os
import re
import sys

repo, pr, ha0, ha, hb, hc, count, proof_a_file, proof_b_file, proof_c_file = os.path.abspath(sys.argv[1]), *sys.argv[2:11]
proof_c = open(proof_c_file).read().strip()
proof_a = open(proof_a_file).read().strip()
proof_b = open(proof_b_file).read().strip()


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 73 (2026-11-23, same PR): CM550's EEPROM mirror, the security key variables, development mode twins

A peer relay started the round; the scripts are in `session_folder/round73/`. These are round 72's leads.
- **Stage A0 ({ha0}):** `audit_cal_suffixes.py` learns CM550's EEPROM RAM mirror, 0x803b0a-0x804155 = EEPROM
  0x0-0x64b.
  - **Evidence:** the memory services translate EEPROM addresses into it by `- 0x7fc4f6`. CM550 0x11a74 stores it back
    in 16-byte chunks, the twin of CM848's `commitEepromMirrorToEeprom`. CM848's EEPROM offsets land on the same roles:
    0x02 the master password and 0x8e the security key word.
  - **The rule** is unchanged (EEPROM-backed = `_cal`); the auditor's CM550 map was incomplete.
  - **The audit:** CM550 goes from 0 / 0 / 0 to MISSING 32, a backlog like CM848's 210. None were renamed.
- **Stage A ({ha}):** the security key variables share names in both firmwares.
  - `security_key_failure_count`: CM848 0x3fb9a8 (was `security_sequence_step`) / CM550 0x801e76.
  - `security_master_password_cal`: e2m 0005 `ECM_PSWD` / `Master_Password`, 6 bytes at EEPROM 0x2. CM848 0x3fd484 /
    CM550 0x803b0c, was `ecu_identity_test_pattern`.
  - `calibration_download_security_key_cal` for CM550 0x803b98: EEPROM 0x8e, a word (`cmpi.w`).
  - **Proof:** {proof_a}
- **Stage B ({hb}):** four more twin pairs, each with one shared name.
  - **The functions:** `enterDevelopmentMode` / `exitDevelopmentMode` / `forceExitDevelopmentMode` (CM550 0x118b2 /
    0x1188c / 0x118cc - its 'water in fuel' names were wrong) and `commitEepromMirrorToEeprom` (0x21918 / 0x11a74).
  - **CM550 globals:** 0x80dc6c becomes `ram_refresh_enable` (`RAM_REFRESH_STATE`) and 0x80dc90 becomes `run_location`
    (`RUN_LOCATION`, words 0xeaea / 0xeeee - CM848's bytes doubled).
  - **README:** result 0x07 is NOT_SAFE, not "logging". The diagram's EEPROM branch follows the code. The type 3
    branch returns 0x03, not 0x1A. The region table is J90350's.
  - **CM550 notes:** both 0x07 comments say the same.
  - **Proof:** {proof_b}
- **Stage C ({hc}), from the closing review:** CM550's own `parameter_id_lookup_table.csv` is indexed by e2m block
  id, as CM848's table is.
  - **Blocks:** 000D SAFE2PRG -> 0x80dc92, 0010 RUN_LOC -> 0x80dc90, 10C7 RAM_Refresh_Enable -> 0x80dc6c and 1328
    Development_Mode -> 0x80de30. That confirms stage B's two names.
  - **0x80dc92** is `not_safe_to_program_flag` after all. CM550's value 2 is an extension that the `== 1` tests
    treat as safe.
  - **0x80de30:** the struct field `count_106` is `development_mode` (`DEVELOPMENT_MODE_STATE`). The row there,
    `calibration_write_pending_flag`, is renamed too.
  - **The old notes:** the J90280.05-era 'calibration bank' notes are annotated.
  - **Proof:** {proof_c}
- **firmware/CLAUDE.md:** lines 915-916, the reference refresh's factual rename of the stage 9b mention
  (`cm848_exitDevelopmentMode` / `cm848_enterDevelopmentMode` / `cm848_forceExitDevelopmentMode` -> the shared names).
- **Leads:**
  - **The `j1708_multipacket_msg_t` instance at 0x80ddc6 (256 bytes) is misapplied.**
    - CM550's parameter ID table maps 13 e2m blocks inside its span: 1127 at +0, 1128 at +4, 1001, 1002, 1328
      (`development_mode`), 0013, 0014, 0015, 116B ...
    - Replacing it with the separate globals changes many renders: 980 field renders of 34 fields in CM550's
      `.cpp`. It is its own stage.
  - **CM550's old enum members:** the 'calibration bank' ones (`DIAG_SERVICE_3_CMD` 0x40 / 0x41, `DIAG_SECURED_SUBFUNC`
    / `DIAG_CONTROL_SUBFUNC`) and `CALIBRATION_WRITE_PROTECT` (0x80dc92's 0 / 1 / 2).
    - They render nowhere. Renaming them after the development mode twins / SAFE2PRG is open.
    - Also open: do CM550's 8-byte parameter table entries (two addresses each) pick an address by
      `ram_refresh_enable`, as the old notes claimed?
  - **A candidate twin inside CM848:** the boot worker calls `cm848_validateWriteAuth` where the application calls
    `validateSecurityKey`.
  - **The CM550 mirror's other 31 names** lack `_cal`, the new backlog. One of them, `lsg_base_reference_speed_calibration`
    at EEPROM 0x94, disagrees with CM848's e2m (`ESP_Override_Alpha` there).
  - **`cm550_circularBufferWrite` (0x16cd8)** is the EEPROM byte write queue by its role in both twin pairs, but it has
    no body in the `.cpp`.
  - **The writers' locals, both firmwares,** and the candidate pair `cm550_diagnosticServiceSecurityValidator` /
    `cm848_validateJ1939DiagnosticRequest` (not read in full).
  - **The skill notes:** `auditing-cal-suffixes` / `editing-firmware-csvs` say CM550 RAM is never `_cal`. The mirror is
    the exception now. That text lives in `.claude/skills` and is not edited here.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 73.**\n"
     f"- **Stage A0 ({ha0}):** `audit_cal_suffixes.py` knows CM550's EEPROM RAM mirror (0x803b0a-0x804155; the\n"
     "  twin store-back proves it); CM550's audit lists the mirror's names without `_cal` as a backlog (32, 31\n"
     "  after stage A).\n"
     f"- **Stage A ({ha}):** the security key variables share names in both firmwares (`security_key_failure_count`,\n"
     "  `security_master_password_cal` = e2m Master_Password, CM550's `calibration_download_security_key_cal`).\n"
     f"- **Stage B ({hb}):** `enterDevelopmentMode` / `exitDevelopmentMode` / `forceExitDevelopmentMode` /\n"
     "  `commitEepromMirrorToEeprom` are twins (CM550's 'water in fuel' names were wrong); CM550's `ram_refresh_enable` /\n"
     "  `run_location` get CM848's names and enums; the README's 0x07 / 0x1A / region table follow the code.\n"
     f"- **Stage C ({hc}):** CM550's own parameter ID table (e2m block ids) makes 0x80dc92 `not_safe_to_program_flag`\n"
     "  and the struct field at 0x80de30 `development_mode`.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 72:", f"- [x] Round 73: A: {proof_a} B: {proof_b} C: {proof_c}\n- [x] Round 72:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 73: CM550's EEPROM mirror, the security key variables, development mode twins "
       "(`session_folder/round73/`)\n\n"
       "- **Stage A0:** `apply_r73a0.py`. **Stage A:** `apply_r73a.py`, `map_r73a_*.csv`, the m68k width scanners "
       "`m68k_abs_access.py` / `m68k_register_ops.py`. **Stage B:** `apply_r73b.py`, `apply_r73b_docs.py`, "
       "`map_r73b_*.csv`. **Stage C:** `apply_r73c.py`, `map_r73c_cm550.csv`.\n"
       "- **Proof:** `prove_r73*.py`, `diff_r73*.py`. **Closing:** `apply_r73_closing.py`, `update_large_tar_r73.sh`.\n")
if "## Round 73:" not in t:
    i = t.index("## Round 72:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 72: the J1939 memory write service shared with CM550 - open: the task 046 leads",
     "round 72: the J1939 memory write service shared with CM550; round 73: CM550's EEPROM mirror, the security key "
     "variables, development mode twins - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "CM550 builds need line-ending care: its structure_definitions.csv is CRLF); task 046 leads"
new = ("CM550 builds need line-ending care: its structure_definitions.csv is CRLF) + round 73 (CM550's EEPROM RAM mirror "
       "0x803b0a-0x804155 confirmed and taught to audit_cal_suffixes.py - 31 CM550 MISSING; the security key variables + "
       "enter/exit/forceExit development mode + commitEepromMirrorToEeprom shared; CM550 m68k widths via "
       "session_folder/round73/m68k_*.py); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
print("round 73 closing applied")
