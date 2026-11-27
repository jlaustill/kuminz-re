"""Round 60 stage A: type the parameter ID tables and the SCI command dispatch table (none of the names is in CM550).
- param_id_entry_t -> parameter_id_entry_t ({word parameter_id, dword address}, 6 bytes). Its own comments named its
  home, the boot kernel's 20-entry table at ROM 0x3CDC / RAM 0x3F98AC (IDs 0x0-0x12A9); the application's flash2
  table at 0x53be38 has the same layout (cm848_lookupParameterIdAddress), so one type serves both:
  - boot_parameter_id_table (was param_id_lookup_table, undefined2): parameter_id_entry_t[20], 0x3f98ac-0x3f9923
    (cm848_lookupTableEntryByKey -> cm848_lookupBootParameterIdAddress scans it to 0x3f9924);
  - parameter_id_table: parameter_id_entry_t[1441] at 0x53be38 (the code's bound 0x53ea6c = 1886 records; the dump
    ends after record 1440) and its bucket index parameter_id_table_bucket_start word[1889] at 0x53af76 (ID mod 1889).
- sci_command_dispatch_entry_t (new; {byte command, byte pad, pointer handler}) on sci_command_dispatch_table
  (flash2 0x53a9a0, 19 records, cm848_dispatchSciCommand).
- Type-only pointer rows inside the three arrays go (0x3f98ae / 0x3f98ba / 0x53be3a / 0x53a9a2 / 0x53a9a8).
- j1939_ack_msg_t is deleted: its 8 fields equal j1939_acknowledgement_payload_t's and only an enums.csv comment
  named it (the comment now names the live type).
- ef00_dispatch_entry_t / diag_dispatch_entry_t stay untouched (their documented RAM homes are unverified / time-shared).
Idempotent.  usage: apply_r60a.py <repo> <map.csv>"""
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 60"
sp = os.path.join(O, "structure_definitions.csv")
s = open(sp).read()
if "parameter_id_entry_t" in s:
    print("already applied")
    sys.exit(0)

# --- structure_definitions.csv
old_block = re.search(r"(?:^#[^\n]*\n)*^param_id_entry_t,[^\n]*\n^param_id_entry_t,[^\n]*\n", s, re.M)
assert old_block, "param_id_entry_t block"
new_block = (
    "# Parameter ID tables ({parameter ID, address} records, 6 bytes): the boot kernel's boot_parameter_id_table (ROM 0x3CDC "
    "copied to RAM 0x3F98AC - 20 records - cm848_lookupBootParameterIdAddress) and the application's parameter_id_table "
    "(flash2 0x53be38 - 1886 records, 1441 in the dump - cm848_lookupParameterIdAddress through "
    "parameter_id_table_bucket_start)\n"
    'parameter_id_entry_t,,parameter_id,word,2,"The ID looked up: a boot service parameter (0x0000-0x12A9) in the boot '
    'table, an e2m block ID (e2m column 3, e.g. 0x105E / 0x8A0F) in the flash2 table (lhz) - was param_id (PR #53 '
    'round 60)",,verified\n'
    'parameter_id_entry_t,,address,dword,4,"The resolved address: EEPROM 0x01000000 + offset (the application maps it to '
    'the RAM mirror 0x3fd482 + offset) / ROM / RAM / MPC555 registers (lwz at +2; a dword: as a pointer it would add '
    'about 1460 references)",,verified\n')
s = s[:old_block.start()] + new_block + s[old_block.end():]
ack = re.search(r"(?:^#[^\n]*\n)*(?:^j1939_ack_msg_t,[^\n]*\n)+\n?", s, re.M)
assert ack and ack.group(0).count("j1939_ack_msg_t,") == 8, "j1939_ack_msg_t block"
s = s[:ack.start()] + s[ack.end():]
assert s.endswith("\n")
s += ("\n# SCI command dispatch entry (6 bytes): cm848_dispatchSciCommand compares the received command byte with command "
      "and calls handler (sci_command_dispatch_table, flash2 0x53a9a0, 19 records; PR #53 round 60)\n"
      "sci_command_dispatch_entry_t,,command,byte,1,The SCI command number (18 / 19 / 20 / 23 / 25 ... 53 / 40 / 43 / 44 / "
      "49 in table order),,verified\n"
      "sci_command_dispatch_entry_t,,pad,byte,1,0 in every record,,verified\n"
      "sci_command_dispatch_entry_t,,handler,pointer,4,The command's cm848_sciCommand<N> function,,verified\n")
open(sp, "w").write(s)

# --- enums.csv comment
ep = os.path.join(O, "enums.csv")
e = open(ep).read()
old = "# Used as j1939_ack_msg_t.control_byte and as ack_type parameter"
assert e.count(old) == 1
open(ep, "w").write(e.replace(old, "# Used as j1939_acknowledgement_payload_t.control_byte and as ack_type parameter"))

# --- global_variables.csv
gp = os.path.join(O, "global_variables.csv")
g = open(gp).read().split("\n")
idx = {l[:10]: k for k, l in enumerate(g) if l.startswith("0x")}
mapping = ["address,name,old_label,kind,dims"]
for a in ("0x003f98ae", "0x003f98ba", "0x0053be3a", "0x0053a9a2", "0x0053a9a8"):
    assert g[idx[a]] == f"{a},,pointer,", g[idx[a]]
k = idx["0x003f98ac"]
assert g[k].startswith("0x003f98ac,param_id_lookup_table,undefined2"), g[k]
old_note = g[k].split(",", 3)[3] if g[k].count(",") >= 3 else ""
g[k] = ("0x003f98ac,boot_parameter_id_table,parameter_id_entry_t[20],The boot kernel's parameter ID table: ROM 0x3CDC "
        "copied to RAM 0x3F98AC at boot - 20 records sorted by ID (0x0 -> EEPROM 0x1000036 ... 0x12a9 -> ROM 0x108); "
        "cm848_lookupBootParameterIdAddress scans it to 0x3f9924 for the boot diagnostic services. In the ROM-to-RAM "
        f"window (was param_id_lookup_table; {R})" + (f" | earlier note: {old_note}" if old_note.strip() else ""))
mapping.append("0x003f98ac,boot_parameter_id_table,param_id_lookup_table,global,1")
drop = {idx[a] for a in ("0x003f98ae", "0x003f98ba", "0x0053be3a", "0x0053a9a2", "0x0053a9a8")}
g = [l for j, l in enumerate(g) if j not in drop]
NEW = [
    ("0x0053af76", "parameter_id_table_bucket_start", "word[1889]",
     "The bucket index of parameter_id_table: bucket = parameter ID mod 1889 (0x761); the word is the bucket's first "
     "record (0xffff = empty) and the next bucket's word - or the table end 0x53ea6c - ends it "
     f"(cm848_lookupParameterIdAddress). 1889 words end where the table starts; largest entry 1885 ({R})",
     "DAT_0053af76"),
    ("0x0053be38", "parameter_id_table", "parameter_id_entry_t[1441]",
     "The application's parameter ID table: e2m block ID -> address (record = table[block] + offset). The code bounds it "
     "at 0x53ea6c = 1886 records; the flash2 dump ends after record 1440, so 1441 are typed. "
     f"firmware/scripts/e2m_block_addresses.py resolves it from the binary ({R})", "DAT_0053be38"),
    ("0x0053a9a0", "sci_command_dispatch_table", "sci_command_dispatch_entry_t[19]",
     "The SCI command table: cm848_dispatchSciCommand compares the received command byte with each record's command "
     "and calls its handler (19 records: commands 18 / 19 / 20 / 23 / 25 / 26 / 35 / 37 / 39 / 41 / 42 / 50 / 51 / 52 / "
     f"53 / 40 / 43 / 44 / 49) ({R})", "DAT_0053a9a0"),
]
for a, name, typ, text, rendered in NEW:
    assert a not in {l[:10] for l in g if l.startswith("0x")}, a
    later = [j for j, l in enumerate(g) if l.startswith("0x") and int(l[:10], 16) > int(a, 16)]
    g.insert(later[0] if later else len(g), f"{a},{name},{typ},{text}")
    mapping.append(f"{a},{name},{rendered},global,1")
open(gp, "w").write("\n".join(g))

# --- the boot lookup's name (function_renames.csv and its function_definitions.csv rows)
fp = os.path.join(O, "function_renames.csv")
f = open(fp).read()
m = re.search(r"^0x00003f70,cm848_lookupTableEntryByKey(,[^\n]*)?$", f, re.M)
assert m
old_plate = (m.group(1) or ",")[1:].strip()
plate = ("Boot kernel: returns the address of a parameter ID from boot_parameter_id_table (20 records sorted by ID - a "
         "linear scan to 0x3f9924) or 0 when absent - the boot twin of cm848_lookupParameterIdAddress. Callers: the boot "
         "diagnostic services cm848_diagService65_handler / cm848_diagMemoryReadWithBaseOffset / "
         "cm848_memoryWriteByParameterId")
assert "," not in plate
f = (f[:m.start()] + f"0x00003f70,cm848_lookupBootParameterIdAddress,{plate} (was cm848_lookupTableEntryByKey; {R})"
     + (f" | earlier note: {old_plate}" if old_plate else "") + f[m.end():])
open(fp, "w").write(f)
mapping.append("0x00003f70,cm848_lookupBootParameterIdAddress,cm848_lookupTableEntryByKey,function,1")
dp = os.path.join(O, "function_definitions.csv")
d = open(dp).read()
n = d.count("0x00003f70,cm848_lookupTableEntryByKey,")
assert n >= 1, n
open(dp, "w").write(d.replace("0x00003f70,cm848_lookupTableEntryByKey,", "0x00003f70,cm848_lookupBootParameterIdAddress,"))
with open(map_path, "w") as fh:
    fh.write("\n".join(mapping) + "\n")
print(f"tables typed, 5 pointer rows dropped, j1939_ack_msg_t removed, function renamed ({n} prototype rows)")
