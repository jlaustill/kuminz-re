"""Round 73 stage A: the security key variables, in both firmwares (shared EEPROM offsets, shared names). Idempotent;
keeps line endings.
- security_key_failure_count: CM848 0x3fb9a8 (was security_sequence_step; lbz / stb) / CM550 0x801e76 (cmpi.b #0x11 /
  clr.b / addq.b through a4). Only validateSecurityKey touches it (in both): +1 per miss, cleared on a match; at 0x11
  every key fails.
- security_master_password_cal: e2m 0005 +0 ECM_PSWD / Master_Password 'security master password' (HEX, 6 bytes) =
  EEPROM 0x2: CM848 0x3fd484 (rendered as the string label s_ABCDEF_003fd484 - lbzx) / CM550 0x803b0c (was
  ecu_identity_test_pattern; the mirror + 2). validateSecurityKey compares the unscrambled key's 6 characters with it.
- calibration_download_security_key_cal in CM550: EEPROM 0x8e (mirror + 0x8e), a word (cmpi.w #0xff at all four uses) -
  CM848's e2m 1000 +0 Security_Key at the same offset; 0xff = no key needed.
usage: apply_r73a.py <repo> <map_cm848.csv> <map_cm550.csv>"""
import os
import sys

repo, map8, map5 = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
O8 = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
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


def insert_rows(p, rows):
    lines = read(p).split("\n")
    for row in rows:
        if row in lines:
            continue
        a = int(row.split(",")[0], 16)
        assert not any(l.startswith(row.split(",")[0] + ",") for l in lines), row[:30]
        for i, l in enumerate(lines):
            if l.startswith("0x") and int(l.split(",")[0], 16) > a:
                break
        lines.insert(i, row)
    write(p, "\n".join(lines))


COUNT = ("security_key_failure_count,byte,The consecutive security key misses: validateSecurityKey adds one per miss and "
         "clears it on a match; at 0x11 (17 misses) every key fails")
PASSWORD = ("security_master_password_cal,byte[6],e2m 0005 +0 ECM_PSWD / Master_Password 'security master password' (HEX "
            "6 bytes) = EEPROM 0x2: validateSecurityKey compares the unscrambled key's 6 characters with it")
G8, G5 = os.path.join(O8, "global_variables.csv"), os.path.join(O5, "global_variables.csv")
edit(G8, "0x003fb9a8,security_sequence_step,byte,\n",
     f"0x003fb9a8,{COUNT} (lbz / stb) - the same variable as CM550's 0x801e76 (was security_sequence_step; {R})\n")
insert_rows(G8, [f"0x003fd484,{PASSWORD} (lbzx; the mirror + 2) - CM550 keeps it at the same EEPROM offset ({R})"])
edit(G5, "0x00803b0c,ecu_identity_test_pattern,undefined,\n",
     f"0x00803b0c,{PASSWORD} (the mirror 0x803b0a + 2) - CM848 keeps it at the same EEPROM offset (was "
     f"ecu_identity_test_pattern; {R})\n")
insert_rows(G5, [
    f"0x00801e76,{COUNT} (cmpi.b / clr.b / addq.b through a4) - the same variable as CM848's 0x3fb9a8 ({R})",
    "0x00803b98,calibration_download_security_key_cal,word,EEPROM 0x8e (the mirror 0x803b0a + 0x8e) - CM848's e2m 1000 "
    "+0 Security_Key 'Key which provides access to calibration dl.' at the same offset: 0x00ff = no key needed "
    "(writeJ1939DiagnosticMemory / cm550_diagnosticServiceSecurityValidator / validateSecurityKey - cmpi.w #0xff at all "
    f"four) ({R})",
])

# the two validateSecurityKey plates name the variables now
F8, F5 = os.path.join(O8, "function_renames.csv"), os.path.join(O5, "function_renames.csv")
edit(F8, "1 once security_sequence_step - the failure count - reaches 0x11 (a lockout after 17 misses); else "
         "unscrambleSecurityKey gives 6 characters (compared with the EEPROM string at 0x3fd484)",
     "1 once security_key_failure_count reaches 0x11 (a lockout after 17 misses); else unscrambleSecurityKey gives 6 "
     "characters (compared with security_master_password_cal)")
edit(F5, "0 (pass) when the key byte 0x803b98 is 0xff; 1 once the failure count 0x801e76 reaches 0x11 (a lockout after "
         "17 misses); else unscrambleSecurityKey gives 6 characters (compared with ecu_identity_test_pattern)",
     "0 (pass) when calibration_download_security_key_cal is 0xff; 1 once security_key_failure_count reaches 0x11 (a "
     "lockout after 17 misses); else unscrambleSecurityKey gives 6 characters (compared with "
     "security_master_password_cal)")

with open(map8, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n0x003fb9a8,security_key_failure_count,security_sequence_step,global,1\n")
with open(map5, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n"
             "0x00803b0c,security_master_password_cal,ecu_identity_test_pattern,global,1\n")
print("round 73 stage A applied")
