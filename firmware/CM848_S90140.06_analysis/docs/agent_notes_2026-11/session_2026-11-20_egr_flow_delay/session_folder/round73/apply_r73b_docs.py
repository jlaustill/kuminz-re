"""Round 73 stage B docs: with ram_refresh_enable named, result 7 of the EEPROM path has its meaning - 'not safe to program
(the 0x80dc92 state is 1) while RAM refresh is on', CM848's J1939_DIAGNOSTIC_RESULT_NOT_SAFE - where the README and
CM550's notes read it as a 'logging state'. The README's region table also held J90280.05's bounds. Idempotent; keeps
line endings; the diagram keeps its widths.  usage: apply_r73b_docs.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
R = "PR #53 round 73"
EOL = {}


def read(p):
    s = open(p, newline="").read()
    EOL[p] = "\r\n" if "\r\n" in s else "\n"
    return s.replace("\r\n", "\n")


def write(p, s):
    open(p, "w", newline="").write(s.replace("\n", EOL[p]))


def edit(p, old, new, same_width=False):
    s = read(p)
    if new in s:
        return
    assert s.count(old) == 1, (os.path.basename(p), old[:90], s.count(old))
    if same_width:
        assert len(old) == len(new), (old, new)
    write(p, s.replace(old, new))


README = os.path.join(repo, "README.md")
for old, new in (
        ("│LOGGING│", "│EEPROM │"),
        ("0x0A            logging          0x09", "0x0A            not-safe         0x09"),
        ("│ Logging      │", "│ Not safe and │"),
        ("│ state = 1?   │", "│ refresh on?  │"),
        ("YES │ NO                      YES │ NO                         │",
         "YES │ NO                      NO │ YES                         │"),
        ("(LOGGING_                   │", "(NOT_SAFE)                  │"),
        ("EEPROM  STATE_ERROR)                 │", "EEPROM                               │")):
    edit(README, old, new, same_width=True)
edit(README,
     "| Address Range           | Flag   | Behavior                      |\n"
     "|-------------------------|--------|-------------------------------|\n"
     "| 0x000000 - 0x03FFFF     | 0x04   | ROM - Write DENIED            |\n"
     "| 0x800000 - 0x8091C1     | 0x03   | Main RAM - Requires AUTH      |\n"
     "| 0x8091C2 - 0x80FFFF     | 0x00   | Extended RAM - Direct write   |\n"
     "| 0x010000 - 0x010FFF     | 0x05   | EEPROM - Requires logging state |\n",
     "`application_memory_region_table` at ROM 0x345dc (`MEMORY_REGION_TYPE`; the first matching entry wins; the type "
     f"while development mode is on / off - {R}):\n"
     "\n"
     "| Address Range             | Type        | Behavior |\n"
     "|---------------------------|-------------|----------|\n"
     "| 0x000000 - 0x07FFFF       | 0x04        | Main flash - write refused (0x0A) |\n"
     "| 0x800000 - 0x8091DC       | 0x03        | Main RAM - copied after the security key |\n"
     "| 0x8091DC - 0x80FFFF       | 0x00        | Extended RAM - copied without a check |\n"
     "| 0x1000000 - 0x1001FFF     | 0x05        | EEPROM - refused (0x07) while not safe to program with RAM refresh on; "
     "else after the key through the EEPROM byte write queue and the mirror at 0x803B0A |\n"
     "| 0xFFC800 - 0xFFFFFF       | 0x03 / 0x0A | Registers - after the key in development mode, else refused (0x0A) |\n")
edit(README, "| 0x07   | LOGGING_STATE_ERROR    | EEPROM logging not active      |\n",
     "| 0x07   | NOT_SAFE               | EEPROM write refused: not safe to program (the 0x80dc92 state is 1) while RAM "
     "refresh is on - CM848's J1939_DIAGNOSTIC_RESULT_NOT_SAFE |\n")
E5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/enums.csv")
edit(E5, "MEMORY_OP_RESULT,0x07,CALIBRATION_WRITE_BLOCKED,EEPROM write blocked - calibration_write_protect_state==1 and "
         "calibration_bank_selector!=FACTORY,1\n",
     "MEMORY_OP_RESULT,0x07,CALIBRATION_WRITE_BLOCKED,EEPROM write refused - the 0x80dc92 state is 1 (CM848: not safe "
     "to program) while ram_refresh_enable is on (J90280.05 read them as calibration_write_protect_state / "
     f"calibration_bank_selector; {R}),1\n")
edit(E5, "DIAG_ERROR_SOURCE,0x07,CONDITION_NOT_MET,writeJ1939DiagnosticMemory - system_logging_state check failed,1\n",
     "DIAG_ERROR_SOURCE,0x07,CONDITION_NOT_MET,writeJ1939DiagnosticMemory - the 0x80dc92 state is 1 (CM848: not safe to "
     f"program) while ram_refresh_enable is on (was read as a system_logging_state check; {R}),1\n")
print("round 73 stage B docs applied")
# round 72's README lead: the type 3 branch said a missing key returns 0x1A - J90350 returns 3 there (only an EEPROM
# write without the key returns 0x1A; CM848 returns 0x1A for both)
edit(README, "┌────────┐ Return 0x1A         Write   Return 0x07", "┌────────┐ Return 0x03         Write   Return 0x07",
     same_width=True)
edit(README, "| 0x1A   | AUTH_REQUIRED_MISSING  | Secured region, no auth provided |\n",
     "| 0x1A   | AUTH_REQUIRED_MISSING  | EEPROM write without the key (a type 3 write without it returns 0x03 here; "
     f"CM848 returns 0x1A for both - {R}) |\n")
print("round 73 stage B docs (type 3) applied")
