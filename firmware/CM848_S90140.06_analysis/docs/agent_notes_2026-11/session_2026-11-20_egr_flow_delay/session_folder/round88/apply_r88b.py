"""Round 88 stage B (CM550 + CM848): the round 87 misname audit (workflow wf_e25c53e9-f38: 4 investigators, 4
skeptics), every accepted / amended change plus the skeptics' actions. Idempotent; keeps line endings.
usage: apply_r88b.py <repo> <audit_changes_r88.tsv> <map550.csv> <map848.csv>
- Functions: renames in both firmwares (6 new twin pairs share one unprefixed name; the shared
  commitEepromMirrorToEeprom splits into two counterparts); CM550 0x1b6e2 / 0x1b666 (emptyStubFunction2 / 3) are rts
  tails of other functions with no reference, so their rows go to deleted_functions.csv.
- Globals: renames, types and new rows (the power-down bookkeeping, the J1939 service table, the engine state and
  overspeed words, the RAM refresh, the transmit status bytes, the DM8 payload; CM848's three counterparts).
- CM550 types: j1939_header_t -> CM848's j1939_msg_hdr_t (fields can_id / data_length), j1939_tx_msg_t,
  engine_overspeed_event_t, j1939_diagnostic_service_entry_t; instances replace the rows inside their bytes.
- CM550 enums: ENGINE_STATE (CM848's members) types engine_state; J1939_DIAGNOSTIC_SERVICE members take CM848's names.
- Prototypes: the descriptor pointers become j1939_tx_msg_t *; the transmit / receive handlers' message_object_number."""
import os
import re
import sys

repo, tsv, map550, map848 = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4]
DIRS = {"CM550": os.path.join(repo, "firmware/CM550_J90350.00_analysis/output"),
        "CM848": os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")}
R = "PR #53 round 88"
changes = [l.rstrip("\n").split("\t") for l in open(tsv)]


def read(path):
    return open(path, newline="").read()


def write(path, text):
    open(path, "w", newline="").write(text)


def clean(reason, limit=380):
    r = " ".join(reason.split())
    r = r.replace("COUNTERPART, NOT A TWIN,", "Counterpart, not a twin,").replace("COUNTERPART, NOT A TWIN", "Counterpart, not a twin")
    r = re.sub(r"\bTWIN of\b", "Twin of", r)
    sentences = re.split(r"(?<=[.)])\s+(?=[A-Z(0-9])", r)
    keep = [s for s in sentences if not re.search(r"\.csv:\d|need(s)? the new name|APPLY|Action|Comments that cite|"
                                                  r"this reverses|investigator|proposal|round 8[67]'s", s)]
    out = ""
    for s in keep:
        if out and len(out) + len(s) + 1 > limit:
            break
        out = (out + " " + s).strip()
    return out.rstrip(";, ")


def norm(address):
    return f"0x{int(address, 16):08x}"


TWINS = {}
by_final = {}
for c in changes:
    if c[2] == "function":
        by_final.setdefault(c[5], []).append(c)
for final, cs in by_final.items():
    fws = {c[1]: c for c in cs}
    if set(fws) == {"CM550", "CM848"} and not final.startswith(("cm550_", "cm848_", "mc68k_", "vp44_", "mpc555_")):
        TWINS[("CM550", norm(fws["CM550"][3]))] = f"CM848 0x{int(fws['CM848'][3], 16):x}"
        TWINS[("CM848", norm(fws["CM848"][3]))] = f"CM550 0x{int(fws['CM550'][3], 16):x}"
renames = {"CM550": [], "CM848": []}

# ---------------------------------------------------------------- functions
COMMIT550 = ("Writes the EEPROM mirror 0x803b0a-0x804155 back to the EEPROM (J1939 diagnostic service 21; J1708 command "
             "84): 7 while not_safe_to_program_flag is 1; otherwise 16-byte chunks through cm550_circularBufferWrite (the "
             "EEPROM byte write queue) with up to 16000 waits each, and two failed queue writes end it (11, clearing "
             "0x80ddd3). On success it clears power_down_refresh_enable, arms a deferred J1708 reply (0x80dde4 = 1) and "
             "returns 0xff, so the J1939 dispatcher sends no response frame. Counterpart, not a twin, of CM848's "
             "cm848_commitEepromMirrorToEeprom, which answers the J1939 request (0)")
DELETE550 = {
    "0x0001b6e2": "not a function entry: the closing rts of cm550_FUN_0001b6d6 - 0 references (no pointer in the ROM or "
                  "either RAM dump); the row came from the J90280.05 relocation map",
    "0x0001b666": "not a function entry: the shared closing rts of periodicTaskSet_fuelDemand / its mid-entry 0x1b62a - "
                  "0 references (no pointer in the ROM or either RAM dump); the row came from the J90280.05 relocation map",
}
for fw in ("CM550", "CM848"):
    path = os.path.join(DIRS[fw], "function_renames.csv")
    s = read(path)
    for group, cfw, kind, address, current, final, ftype, fields, verdict, conf, reason in changes:
        if cfw != fw or kind != "function":
            continue
        a = norm(address)
        if fw == "CM550" and a in DELETE550:
            m = re.search(rf"^{a},[^\r\n]*\r?\n", s, re.M)
            if m:
                s = s[:m.start()] + s[m.end():]
                renames[fw].append((a, "", current))
            dpath = os.path.join(DIRS[fw], "deleted_functions.csv")
            d = read(dpath)
            if f"\n{a}," not in d:
                d = d.rstrip("\n") + f"\n{a},{DELETE550[a]} (was {current}, a name shared with CM848; {R})\n"
                write(dpath, d)
            continue
        m = re.search(rf"^{a},([^,\r\n]*)(,[^\r\n]*)?$", s, re.M)
        assert m, (fw, a, current)
        if m.group(1) == final:
            continue
        old_comment = (m.group(2) or "")[1:]
        twin = TWINS.get((fw, a))
        note = f"(was {m.group(1)}; {R}" + (f"; the twin of {twin}: one shared name)" if twin else ")")
        if fw == "CM550" and a == "0x00011a74":
            comment = f"{COMMIT550} (was commitEepromMirrorToEeprom, a name round 73 shared with CM848 0x21918; {R})"
        elif fw == "CM848" and a == "0x00021918":
            comment = (old_comment.replace("The same function as CM550 0x11a74 (shared name; was "
                                           "cm848_commitEepromMirrorToEeprom; PR #53 round 73). ", "")
                       + " | counterpart, not a twin, of CM550 0x11a74: CM848 answers the J1939 request on success "
                       "(result 0); CM550 arms a J1708 reply and returns 0xff (was commitEepromMirrorToEeprom, the name "
                       f"round 73 shared with CM550; {R})")
        elif old_comment:
            comment = f"{old_comment} | {note}"
        else:
            comment = f"{clean(reason)} {note}"
        s = s[:m.start()] + f"{a},{final},{comment}" + s[m.end():]
        renames[fw].append((a, final, m.group(1)))
    write(path, s)

# ---------------------------------------------------------------- CM550 struct types (CRLF)
S5 = os.path.join(DIRS["CM550"], "structure_definitions.csv")
s = read(S5)
EOL = "\r\n" if "\r\n" in s else "\n"
OLD_HDR = ["j1939_header_t,,id,uint32_t,4,CAN identifier containing PGN and addressing info,,verified",
           "j1939_header_t,,length,uint16_t,2,Message data length for single/multi-frame decision,,verified"]
NEW_TYPES = [
    f"j1939_msg_hdr_t,,can_id,dword,4,The CAN identifier: priority / PGN / source address (was j1939_header_t.id; "
    f"CM848's type name; {R}),,verified",
    f"j1939_msg_hdr_t,,data_length,word,2,The payload length in bytes: above 8 goes out as a transport session (was "
    f"j1939_header_t.length; {R}),,verified",
    "j1939_tx_msg_t,,header,j1939_msg_hdr_t,6,The CAN identifier and the payload length,j1939_msg_hdr_t,verified",
    "j1939_tx_msg_t,,data_pointer,pointer,4,Points at the first payload byte,,verified",
    "j1939_tx_msg_t,,status_pointer,pointer,4,Points at the message's status byte j1939_<message>_transmit_status: "
    f"the send result or the transport session code (CM848's layout; {R}),,verified",
    "engine_overspeed_event_t,,start_key_on_hour_meter,dword,4,key_on_hour_meter when the overspeed began,,verified",
    "engine_overspeed_event_t,,engine_speed_at_detection,word,2,engine_rpm_primary on the pass the overspeed latch "
    "set,,verified",
    f"engine_overspeed_event_t,,duration,word,2,The passes the overspeed lasted ({R}),,verified",
    "j1939_diagnostic_service_entry_t,,service_id,J1939_DIAGNOSTIC_SERVICE,1,The PGN 61184 service byte,,verified",
    "j1939_diagnostic_service_entry_t,,pad,byte,1,Unused,,verified",
    "j1939_diagnostic_service_entry_t,,handler,pointer,4,The service handler registerJ1939DiagnosticService stored "
    f"({R}),,verified",
]
if NEW_TYPES[0] not in s:
    old = EOL.join(OLD_HDR)
    assert s.count(old) == 1
    s = s.replace(old, EOL.join(NEW_TYPES))
old141 = "j1939_tx_msg_buffer_t,0x00803036,header,j1939_header_t,6,CAN message header (ID + length),j1939_header_t,verified"
new141 = "j1939_tx_msg_buffer_t,0x00803036,header,j1939_msg_hdr_t,6,CAN message header (ID + length),j1939_msg_hdr_t,verified"
if new141 not in s:
    assert s.count(old141) == 1
    s = s.replace(old141, new141)
write(S5, s)
LA = os.path.join(DIRS["CM550"], "local_variables_actual.csv")
t = read(LA)
write(LA, t.replace("response_header,j1939_header_t *,", "response_header,j1939_msg_hdr_t *,"))

# ---------------------------------------------------------------- globals and struct instances
SIZES = {"j1939_tx_msg_t": 14, "engine_overspeed_event_t": 8, "j1939_diagnostic_service_entry_t": 6}
FIELDS = {"j1939_tx_msg_t": {0: "header.can_id", 4: "header.data_length", 6: "data_pointer", 10: "status_pointer"},
          "engine_overspeed_event_t": {}}


def size_of(t):
    m = re.match(r"^(\w+)\[(\d+)\]$", t)
    return SIZES.get(m.group(1), 0) * int(m.group(2)) if m else SIZES.get(t, 0)


for fw in ("CM550", "CM848"):
    path = os.path.join(DIRS[fw], "global_variables.csv")
    lines = read(path).split("\n")
    index = {int(l.split(",")[0], 16): i for i, l in enumerate(lines) if l.startswith("0x")}
    delete, inserts = set(), []
    for group, cfw, kind, address, current, final, ftype, fields, verdict, conf, reason in changes:
        if cfw != fw or kind not in ("global", "struct_instance"):
            continue
        a = int(address, 16)
        span = size_of(ftype) if kind == "struct_instance" or "[" in ftype else 0
        old_comment = ""
        if a in index:
            parts = lines[index[a]].split(",", 3)
            if parts[1] == final and parts[2] == ftype:
                continue
            old_name = parts[1]
            old_comment = parts[3] if len(parts) > 3 else ""
        else:
            old_name = ""
        covered = []
        for o in range(1, span):
            if a + o in index and index[a + o] not in delete:
                covered.append((o, lines[index[a + o]].split(",")[1]))
                delete.add(index[a + o])
        text = clean(reason)
        were = ([f"{old_name} at +0"] if old_name and span else []) + [f"{n} at +{o}" for o, n in covered]
        if were:
            note = f"(were {' / '.join(were)}; {R})"
        elif old_name and old_name != final and not old_name.startswith(("DAT_", "WORD_", "BYTE_")):
            note = f"(was {old_name}; {R})"
        else:
            note = f"({R})"
        if old_name == final and old_comment:
            row = f"0x{a:08x},{final},{ftype},{old_comment} | typed {ftype}: {text} ({R})"
        else:
            row = f"0x{a:08x},{final},{ftype},{text} {note}"
        if a in index:
            lines[index[a]] = row
        else:
            inserts.append((a, row))
        if old_name and old_name != final:
            renames[fw].append((f"0x{a:08x}", final, old_name))
            renames[fw].append((f"0x{a:08x}", final, "_" + old_name))
        else:
            renames[fw].append((f"0x{a:08x}", final, f"DAT_{a:08x}"))
            renames[fw].append((f"0x{a:08x}", final, f"_DAT_{a:08x}"))
        base = ftype.split("[")[0]
        for o, n in covered:
            field = FIELDS.get(base, {}).get(o)
            if field and "[" not in ftype:
                renames[fw].append((f"0x{a + o:08x}", f"{final}.{field}", n))
    lines = [l for i, l in enumerate(lines) if i not in delete]
    for a, row in sorted(inserts):
        for i, l in enumerate(lines):
            if l.startswith("0x") and int(l.split(",")[0], 16) > a:
                lines.insert(i, row)
                break
    write(path, "\n".join(lines))

# ---------------------------------------------------------------- CM550 enums
E5 = os.path.join(DIRS["CM550"], "enums.csv")
e = read(E5)
eol = "\r\n" if "\r\n" in e else "\n"
engine_rows = []
for group, cfw, kind, address, current, final, ftype, fields, verdict, conf, reason in changes:
    if cfw != "CM550" or kind != "enum_member":
        continue
    enum, old_member = current.split(".", 1)
    if enum == "ENGINE_STATE":
        engine_rows.append(f"ENGINE_STATE,{int(address, 0)},{final},{clean(reason, 200)} ({R}),2")
        continue
    m = re.search(rf"^{enum},{re.escape(address)},{re.escape(old_member)},([^\r\n]*),(\d+)$", e, re.M)
    if not m:
        assert re.search(rf"^{enum},{re.escape(address)},{re.escape(final)},", e, re.M), (enum, address, old_member)
        continue
    e = e[:m.start()] + f"{enum},{address},{final},{clean(reason, 260)} (was {old_member}; {R}),{m.group(2)}" + e[m.end():]
    renames["CM550"].append(("", final, old_member))
if engine_rows and "ENGINE_STATE,0," not in e:
    e = e.rstrip("\r\n") + eol + eol.join(
        [f"# ENGINE_STATE: e2m 1068 +0 FSEGST, the same members as CM848's ({R})"] + engine_rows) + eol
write(E5, e)

# ---------------------------------------------------------------- prototypes and function_definitions name columns
for fw in ("CM550", "CM848"):
    path = os.path.join(DIRS[fw], "function_definitions.csv")
    d = read(path)
    for a, final, old in renames[fw]:
        if not final or not a.startswith("0x0") or int(a, 16) >= 0x800000 and fw == "CM550":
            continue
        d = re.sub(rf"^({a},)[^,\r\n]*,", rf"\g<1>{final},", d, flags=re.M)
    if fw == "CM550":
        d = d.replace("0x000104e8,sendCanMessage,0,msg_header,j1939_header_t*,Pointer to J1939 message header structure",
                      f"0x000104e8,cm550_sendCanMessage,0,msg,j1939_tx_msg_t*,The transmit descriptor: header / data "
                      f"pointer / status pointer ({R})")
        d = re.sub(r"^(0x00023130,cm550_multiPacketBufferAllocator,return,,)j1939_header_t\*,", r"\g<1>j1939_tx_msg_t*,",
                   d, flags=re.M)
        d = re.sub(r"^(0x0001e056,[^,]*,0,)node_address,", r"\g<1>message_object_number,", d, flags=re.M)
        d = re.sub(r"^(0x0001e086,[^,]*,0,)node_address,", r"\g<1>message_object_number,", d, flags=re.M)
        if "0x00022726,sendJ1939MultiFrame," not in d:
            lines = d.split("\n")
            row = (f"0x00022726,sendJ1939MultiFrame,0,msg,j1939_tx_msg_t*,The transmit descriptor - the long at +4 "
                   f"((8;a6) after link a6) ({R})")
            for i, l in enumerate(lines):
                if l.startswith("0x") and int(l.split(",")[0], 16) > 0x22726:
                    lines.insert(i, row)
                    break
            d = "\n".join(lines)
    write(path, d)

for fw, path in (("CM550", map550), ("CM848", map848)):
    with open(path, "w") as fh:
        fh.write("address,name,old_label,kind,dims\n")
        for a, final, old in renames[fw]:
            if final and old:
                fh.write(f"{a},{final},{old},symbol,1\n")
print(f"round 88 stage B applied: CM550 {len(renames['CM550'])} / CM848 {len(renames['CM848'])} map rows")
