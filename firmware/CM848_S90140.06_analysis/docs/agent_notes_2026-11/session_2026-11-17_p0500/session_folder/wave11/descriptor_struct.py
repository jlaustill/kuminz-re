"""Type every CM848 J1939 transmit descriptor as one j1939_tx_msg_t instance.

j1939_tx_msg_t shrinks to the 14-byte descriptor (header = j1939_msg_hdr_t can_id + data_length, data_pointer,
data_end_pointer) and becomes a type-only template; the ACK payload that used to follow it in the type gets its own
template, j1939_acknowledgement_payload_t, with an instance at 0x3faaaa. Every other descriptor (a name the decompile
passes as sendJ1939Message((j1939_tx_msg_t *)&NAME)) gets one row typed j1939_tx_msg_t, and the flat rows inside its
14 bytes go. A ROM-to-RAM thunk or call-override address inside a descriptor (not at +0) keeps a member-label row,
because the thunk stage only spares an address that carries a named label.

Usage: descriptor_struct.py <output dir> <baseline .cpp> <build log> <mapping out dir> [--apply]
Writes map_descriptors.csv (reverse_names.py proof: new name -> old label, default labels taken from the baseline)
and map_descriptors_refresh.csv (old non-default names -> new names, for refresh_references.py)."""
import csv
import os
import re
import sys

out_dir, baseline, build_log, map_dir = sys.argv[1:5]
APPLY = "--apply" in sys.argv
gv_path = os.path.join(out_dir, "global_variables.csv")
sd_path = os.path.join(out_dir, "structure_definitions.csv")
gv_lines = open(gv_path).read().split("\n")
pre = open(baseline).read()

rows = {}
for i, line in enumerate(gv_lines):
    p = line.split(",", 3)
    if p[0].startswith("0x"):
        rows.setdefault(int(p[0], 16), []).append(i)


def row_parts(i):
    p = gv_lines[i].split(",", 3)
    while len(p) < 4:
        p.append("")
    return p


by_name = {row_parts(i)[1]: a for a, idx in rows.items() for i in idx}
thunks = []
for line in open(build_log):
    m = re.search(r"(Thunk|Call override): .*?RAM 0x([0-9a-f]+) -> ROM", line)
    if m:
        thunks.append(int(m.group(2), 16))
names = sorted(set(re.findall(r"sendJ1939Message\(\(j1939_tx_msg_t \*\)&(\w+)\)", pre)))


def instance_name(old):
    for pattern, repl in ((r"^(j1939_pgn\d+)_(tx|can)_header$", r"\1_tx_message"),
                          (r"^(j1939_dm\d+)_tx_header$", r"\1_tx_message"),
                          (r"^j1939_msg_header_working$", "j1939_working_tx_message")):
        if re.match(pattern, old):
            return re.sub(pattern, repl, old)
    raise SystemExit(f"no instance name rule for {old}")


def old_label(address):
    """The baseline .cpp's label for an unnamed address: a token ending in _<address>."""
    m = re.search(rf"\b(?:[A-Za-z]\w*?_)?(?:DAT|PTR\w*|BYTE|WORD|DWORD)_{address:08x}\b", pre)
    return m.group(0) if m else None


FIELDS = [(0, "header.can_id"), (4, "header.data_length"), (6, "data_pointer"), (10, "data_end_pointer")]
mapping, refresh, drop, add = [], [], set(), []
for old in names:
    base = by_name[old]
    new = instance_name(old)
    inside = [(a, i) for a in range(base, base + 14) for i in rows.get(a, [])]
    dropped = [row_parts(i)[1] for _, i in inside]
    earlier = " ".join(row_parts(rows[base][0])[3].split())
    comment = (f"J1939 transmit descriptor sent by sendJ1939Message (j1939_tx_msg_t: header.can_id / "
               f"header.data_length / data_pointer / data_end_pointer). Typed as one struct 2026-11-18 (were the flat "
               f"rows {' / '.join(n for n in dropped if '+' not in n and n)})" + (f" | earlier note: {earlier}" if earlier else ""))
    add.append((base, f"0x{base:08x},{new},j1939_tx_msg_t,{comment}"))
    drop.update(i for _, i in inside)
    for off, field in FIELDS:
        a = base + off
        named = [row_parts(i)[1] for i in rows.get(a, []) if row_parts(i)[1] and "+" not in row_parts(i)[1]]
        label = named[0] if named else old_label(a)
        if label:
            mapping.append((f"0x{a:08x}", f"{new}.{field}", label, "global"))
            if named:
                refresh.append((f"0x{a:08x}", f"{new}.{field}", label, "global"))
    for t in thunks:
        if base < t < base + 14:
            field = dict(FIELDS).get(t - base)
            if field is None:
                raise SystemExit(f"thunk at 0x{t:06x} is +{t - base} inside {new}, not at a field start")
            add.append((t, f"0x{t:08x},{new}.{field},,member label: keeps the thunk stage's call override at this "
                           f"kernel-image address (a boot call lands here) (2026-11-18)"))
# The ACK message: the descriptor keeps its row (j1939_ackm_msg) and the label rows inside it; its payload becomes
# its own instance on the existing label row j1939_ack_payload (0x3faaaa), and the stale member-label rows of the
# old combined type (0x3faaab-0x3faab1: j1939_ackm_msg.<field> / j1939_ack_payload.reserved_02...) go.
ACK_FIELDS = ["control_byte", "group_function", "reserved_byte2", "reserved_byte3", "address_acknowledged",
              "pgn_low", "pgn_mid", "pgn_high"]
for f in ACK_FIELDS:
    mapping.append(("0x003faaaa", f"j1939_ack_payload.{f}", f"j1939_ackm_msg.{f}", "global"))
    refresh.append(("0x003faaaa", f"j1939_ack_payload.{f}", f"j1939_ackm_msg.{f}", "global"))
ack_rows = [(a, i) for a in range(0x3faaaa, 0x3faab2) for i in rows.get(a, [])]
assert [row_parts(i)[1] for a, i in ack_rows if a == 0x3faaaa] == ["j1939_ack_payload"], ack_rows
assert all(row_parts(i)[2] == "" for _, i in ack_rows), "a typed row sits inside the ACK payload"
drop.update(i for _, i in ack_rows)
add.append((0x3faaaa, "0x003faaaa,j1939_ack_payload,j1939_acknowledgement_payload_t,The J1939-21 ACKM payload "
                      "(8 bytes) right after j1939_ackm_msg - that descriptor's data_pointer / data_end_pointer point "
                      "at it. Split out of j1939_tx_msg_t 2026-11-18 when the type was cut to the 14-byte descriptor "
                      "(the member-label rows j1939_ackm_msg.<field> at 0x3faaab-0x3faab1 went with it)"))

print(f"descriptors {len(names)}, rows dropped {len(drop)}, rows added {len(add)}, mapping {len(mapping)}, "
      f"refresh {len(refresh)}")
with open(os.path.join(map_dir, "map_descriptors.csv"), "w", newline="") as f:
    w = csv.writer(f)
    w.writerow(["address", "name", "old_label", "kind"])
    w.writerows(mapping)
with open(os.path.join(map_dir, "map_descriptors_refresh.csv"), "w", newline="") as f:
    w = csv.writer(f)
    w.writerow(["address", "name", "old_label", "kind"])
    w.writerows(refresh)
if not APPLY:
    sys.exit(0)

new_gv = [line for i, line in enumerate(gv_lines) if i not in drop]
# insert each added row before the first remaining row with a higher address (the file is mostly address-sorted)
for address, text in sorted(add):
    for k, line in enumerate(new_gv):
        p = line.split(",", 1)
        if p[0].startswith("0x") and int(p[0], 16) > address:
            new_gv.insert(k, text)
            break
    else:
        new_gv.append(text)
open(gv_path, "w").write("\n".join(new_gv))

sd = open(sd_path).read().split("\n")
start = next(i for i, l in enumerate(sd) if l.startswith("# Instance at 0x003faa9c: ACKM"))
end = max(i for i, l in enumerate(sd) if l.startswith("j1939_tx_msg_t,"))
template = [
    "# j1939_tx_msg_t: one J1939 transmit descriptor (14 bytes), the argument of sendJ1939Message - type-only template since 2026-11-18;",
    "# every descriptor is a global row typed with it (j1939_ackm_msg at 0x3faa9c, j1939_pgn<N>_tx_message, ...). header is j1939_msg_hdr_t, so &msg.header is what cm848_transmitCanMessage takes",
    "j1939_tx_msg_t,,header,j1939_msg_hdr_t,6,J1939 TX message header (can_id + data_length),,verified",
    "j1939_tx_msg_t,,data_pointer,pointer,4,Pointer to the first payload byte,,verified",
    "j1939_tx_msg_t,,data_end_pointer,pointer,4,Pointer one past the last payload byte,,verified",
    "# j1939_acknowledgement_payload_t: the J1939-21 ACKM payload (PGN 59392) - j1939_ackm_payload at 0x3faaaa (was the tail of j1939_tx_msg_t)",
    "j1939_acknowledgement_payload_t,,control_byte,J1939_ACK_TYPE,1,J1939-21 ACKM control byte (ACK/NACK/ACCESS_DENIED/CANNOT_RESPOND),,verified",
    "j1939_acknowledgement_payload_t,,group_function,byte,1,Group function value (0xFF = not defined per J1939-21),,verified",
    "j1939_acknowledgement_payload_t,,reserved_byte2,byte,1,Reserved byte 2 (always 0xFF per J1939-21),,verified",
    "j1939_acknowledgement_payload_t,,reserved_byte3,byte,1,Reserved byte 3 (always 0xFF per J1939-21),,verified",
    "j1939_acknowledgement_payload_t,,address_acknowledged,byte,1,Source address of message being acknowledged (0xFF = global),,verified",
    "j1939_acknowledgement_payload_t,,pgn_low,byte,1,Acknowledged PGN low byte (hardcoded 0 for PDU1 requests),,verified",
    "j1939_acknowledgement_payload_t,,pgn_mid,byte,1,Acknowledged PGN mid byte (= pgn_pf of request),,verified",
    "j1939_acknowledgement_payload_t,,pgn_high,byte,1,Acknowledged PGN high byte (= dest_address of request),,verified",
]
open(sd_path, "w").write("\n".join(sd[:start] + template + sd[end + 1:]))
print("applied")
