"""Round 73 stage C (the closing review's read of CM550's parameter_id_lookup_table.csv - its param_id is the e2m block
id, as CM848's parameter ID table is): block 000D SAFE2PRG -> 0x80dc92, 0010 RUN_LOC -> 0x80dc90 (stage B's run_location),
10C7 RAM_Refresh_Enable -> 0x80dc6c (stage B's ram_refresh_enable), 1328 Development_Mode -> 0x80de30. Idempotent; keeps
line endings.
- 0x80dc92 -> not_safe_to_program_flag (word: cmpi.w / move.w / clr.w): CM848's name by its block; CM550 also writes 2
  (cm550_fuel_limit_arbitrator: stopped with a switch bit set) - every test is '== 1', so 2 behaves as safe.
- 0x80de30 = development_mode (word: move.w #1 / clr.w / tst.w / cmpi.w #1). A 256-byte j1708_multipacket_msg_t
  instance at 0x80ddc6 covers it (13 e2m blocks map inside that span - the template is misapplied: a lead), so the struct
  field count_106 becomes development_mode (DEVELOPMENT_MODE_STATE), and the row there - 'calibration_write_pending_flag'
  - is renamed too.
- CM550's J90280.05-era notes read 0x80dc6c as a 'calibration bank selector' and commands 0x40 / 0x41 as bank switches,
  and 0x80dc92 as 'calibration_write_protect_state': annotated with the block ids (the enum members render nowhere; their
  renaming is a lead).
usage: apply_r73c.py <repo> <map_cm550.csv>"""
import os
import sys

repo, map5 = os.path.abspath(sys.argv[1]), sys.argv[2]
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
R = "PR #53 round 73"
EOL = {}


def read(p):
    s = open(p, newline="").read()
    EOL[p] = "\r\n" if "\r\n" in s else "\n"
    return s.replace("\r\n", "\n")


def write(p, s):
    open(p, "w", newline="").write(s.replace("\n", EOL[p]))


def edit(p, old, new):
    s = read(p)
    if new in s:
        return
    assert s.count(old) == 1, (os.path.basename(p), old[:90], s.count(old))
    write(p, s.replace(old, new))


G5, S5, E5, F5 = (os.path.join(O5, n) for n in ("global_variables.csv", "structure_definitions.csv", "enums.csv",
                                                 "function_renames.csv"))
edit(G5, "0x0080dc92,diagnostic_session_state,undefined,\n",
     "0x0080dc92,not_safe_to_program_flag,word,e2m block 000D SAFE2PRG (CM550's parameter ID table) - CM848's "
     "not_safe_to_program_flag: 1 = not safe to program - the twins return 7 on it; CM550 also writes 2 "
     "(cm550_fuel_limit_arbitrator: stopped with a switch bit set) which every '== 1' test treats as safe (cmpi.w / "
     f"move.w / clr.w) (was diagnostic_session_state; {R})\n")
edit(G5, "0x0080de30,calibration_write_pending_flag,,\n",
     "0x0080de30,development_mode,,e2m block 1328 Development_Mode (CM550's parameter ID table) - CM848's development_mode; "
     "renders as the j1708_transmit_buffer_2_32_ddc6.development_mode field while that struct instance covers it (was "
     f"calibration_write_pending_flag; {R})\n")
edit(S5, "j1708_multipacket_msg_t,,count_106,word,2,Count field at offset 106,,verified\n",
     "j1708_multipacket_msg_t,,development_mode,DEVELOPMENT_MODE_STATE,2,Development mode at 0x80de30 - e2m block 1328 "
     "Development_Mode by CM550's parameter ID table; set by enterDevelopmentMode / cleared by exitDevelopmentMode and "
     "forceExitDevelopmentMode; the 256-byte template overlays 13 e2m blocks so this field is a global really (was "
     f"count_106 'Count field at offset 106'; {R}),,verified\n")
lines = read(E5).split("\n")
ENUM = [f"# DEVELOPMENT_MODE_STATE - CM848's enum for development_mode (0x80de30 - a word here as in CM848; {R})",
        "DEVELOPMENT_MODE_STATE,0,DEVELOPMENT_MODE_OFF,Normal operation - cleared by exitDevelopmentMode / "
        "forceExitDevelopmentMode and the boot code,2",
        "DEVELOPMENT_MODE_STATE,1,DEVELOPMENT_MODE_ON,Development mode - set by enterDevelopmentMode (J1708 command 3 "
        "subcommand 0x40 after the security key),2"]
if ENUM[1] not in lines:
    while lines and lines[-1] == "":
        lines.pop()
    lines += ENUM + [""]
    write(E5, "\n".join(lines))
NOTE = (f" [{R}: 0x80dc6c is ram_refresh_enable - e2m block 10C7 RAM_Refresh_Enable in CM550's parameter ID table - and "
        "0x40 / 0x41 are enterDevelopmentMode / forceExitDevelopmentMode (CM848's twins); the 'bank' reading is "
        "J90280.05's]")
edit(E5, "# IMPORTANT: Commands 0x40-0x41 control CALIBRATION BANK SELECTION (factory vs active tuning)\n",
     "# IMPORTANT: Commands 0x40-0x41 control CALIBRATION BANK SELECTION (factory vs active tuning)" + NOTE + "\n")
edit(E5, "# Calibration Bank System - Factory vs Active Tuning\n",
     "# Calibration Bank System - Factory vs Active Tuning" + NOTE + "\n")
edit(E5, "# Calibration Write Protect State - calibration_write_protect_state @ 0x0080dc92\n",
     "# Calibration Write Protect State - calibration_write_protect_state @ 0x0080dc92 [" + R + ": that is "
     "not_safe_to_program_flag - e2m block 000D SAFE2PRG; 1 blocks the EEPROM writes and the mirror commit]\n")
for a5 in ("0x000118b2", "0x0001188c", "0x000118cc", "0x00011a74", "0x0002148a"):
    s = read(F5)
    i = s.index(f"\n{a5},") + 1
    j = s.index("\n", i)
    row = s[i:j]
    new = (row.replace("the development mode flag at 0x80de30 (still rendered as j1708_transmit_buffer_2_32_ddc6."
                       "count_106)", "development_mode (0x80de30 - rendered as the j1708_transmit_buffer_2_32_ddc6 field)")
              .replace("the 0x80dc92 state is 1 (CM848: not safe to program)", "not_safe_to_program_flag is 1")
              .replace("7 while EEPROM writes are blocked", "7 while not safe to program with RAM refresh on"))
    if new != row:
        write(F5, s[:i] + new + s[j:])
with open(map5, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n"
             "0x0080dc92,not_safe_to_program_flag,diagnostic_session_state,global,1\n"
             "0x0080de30,development_mode,calibration_write_pending_flag,global,1\n")
print("round 73 stage C applied")
for old, new in (
        ("EEPROM write refused - the 0x80dc92 state is 1 (CM848: not safe to program) while ram_refresh_enable is on",
         "EEPROM write refused - not_safe_to_program_flag is 1 while ram_refresh_enable is on"),
        ("writeJ1939DiagnosticMemory - the 0x80dc92 state is 1 (CM848: not safe to program) while ram_refresh_enable is on",
         "writeJ1939DiagnosticMemory - not_safe_to_program_flag is 1 while ram_refresh_enable is on")):
    edit(E5, old, new)
print("round 73 stage C (0x07 comments) applied")
DOC = os.path.join(repo, "firmware/docs/service_0x4b_analysis.md")
s = open(DOC).read()
anchor = "`j1939_memory_service_header_lengths` (0x21956), each byte-identical with CM848's.\n"
line = ("> **Round 73:** the 'logging' reading of region type 5 and result 0x07 is the EEPROM path's not-safe check: 7 while "
        "`not_safe_to_program_flag` (0x80dc92, e2m block 000D SAFE2PRG) is 1 with `ram_refresh_enable` (0x80dc6c, block "
        "10C7) on - CM550's own parameter ID table maps those blocks, as CM848's does; type 5 is the EEPROM. The "
        "password is `security_master_password_cal` (e2m Master_Password, EEPROM 0x2) and the security key word "
        "`calibration_download_security_key_cal` (EEPROM 0x8e).\n")
if line not in s:
    assert s.count(anchor) == 1
    open(DOC, "w").write(s.replace(anchor, anchor + line))
print("round 73 stage C (service 0x4b doc) applied")
