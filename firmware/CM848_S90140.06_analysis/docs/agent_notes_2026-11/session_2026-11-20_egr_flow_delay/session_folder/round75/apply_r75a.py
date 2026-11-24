"""Round 75 stage A (CM550): the InSite parameter schedule in vp44_insiteParameterTableIterator (0xeaec) and its
initializer mc68k_FUN_00029130, typed from the code. Idempotent; keeps each CSV's line endings.
- The table at ROM 0x612ee holds 3-byte records {parameter_id, period, first_due_offset}: the initializer sets
  next_due[i] = record[i].first_due_offset (+2) + record[i].period (+1) for up to 30 records (parameter_id 0 ends the
  list); the iterator compares next_due[i] with the tick 0x80ddfe and adds record[i].period (+1) when they are equal.
  cm550_diagnosticMessageTransmissionManager increments the tick after each iterator pass. The table lies past the end
  of the 256 KB ROM dump (contents unknown).
- next_due bytes: 0x80de00-0x80de1d (30, up to the table pointer at 0x80de1e).
- Three address-holding dwords from round 74's leads get pointer types (each is stored once, from (dword)&<buffer>).
usage: apply_r75a.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
R = "PR #53 round 75"


def read(p):
    with open(p, "rb") as fh:
        raw = fh.read().decode()
    return raw, ("\r\n" if "\r\n" in raw else "\n")


def write(p, s):
    with open(p, "wb") as fh:
        fh.write(s.encode())


def edit(p, old, new):
    s, _ = read(p)
    if new in s:
        return
    assert s.count(old) == 1, (os.path.basename(p), old[:90], s.count(old))
    write(p, s.replace(old, new))


def insert_sorted(p, row):
    """Insert a global row before the first data row with a higher address."""
    s, eol = read(p)
    if row.split(",")[0] + "," + row.split(",")[1] + "," in s:
        return
    lines = s.split(eol)
    address = int(row.split(",")[0], 16)
    for i, line in enumerate(lines):
        if line.startswith("0x") and int(line.split(",")[0], 16) > address:
            lines.insert(i, row)
            break
    else:
        raise AssertionError("no insertion point for " + row[:40])
    write(p, eol.join(lines))


S5, G5 = (os.path.join(O5, n) for n in ("structure_definitions.csv", "global_variables.csv"))
s, eol = read(S5)
if "insite_parameter_schedule_entry_t," not in s:
    template = [
        "insite_parameter_schedule_entry_t,,parameter_id,byte,1,The parameter's ID (0 ends the list) - "
        "vp44_insiteParameterTableIterator tests its bit in the 32-byte bitmap at ROM 0x6134a before it calls "
        "cm550_activeParamReadFunction,,verified",
        "insite_parameter_schedule_entry_t,,period,byte,1,Schedule ticks between two sends: the iterator adds it to "
        "the parameter's next due tick each time that tick comes,,verified",
        "insite_parameter_schedule_entry_t,,first_due_offset,byte,1,Ticks added to the period for the first due tick "
        "(the initializer mc68k_FUN_00029130 sets next due = period + this),,verified",
    ]
    anchor = "memory_region_t,,start_address,"
    i = s.index(anchor)
    write(S5, s[:i] + eol.join(template) + eol + s[i:])
insert_sorted(G5, "0x000612ee,insite_parameter_schedule_table,insite_parameter_schedule_entry_t[30],The InSite "
              "parameter schedule: up to 30 3-byte records (parameter_id 0 ends the list) read through "
              "insite_parameter_table_pointer by vp44_insiteParameterTableIterator and mc68k_FUN_00029130 - past the "
              f"end of the 256 KB ROM dump, so the contents are unknown ({R})")
insert_sorted(G5, "0x0080de00,insite_parameter_next_due_ticks,byte[30],One next due schedule tick per "
              "insite_parameter_schedule_table record: set to period + first_due_offset at initialization; when "
              "it equals insite_parameter_schedule_tick the iterator adds the period and reads the parameter "
              f"({R})")
edit(G5, "0x0080ddfe,,byte,PR #53 round 74: typed byte",
     "0x0080ddfe,insite_parameter_schedule_tick,byte,The InSite parameter schedule's tick: "
     "cm550_diagnosticMessageTransmissionManager adds 1 after each vp44_insiteParameterTableIterator pass, which "
     f"compares it with insite_parameter_next_due_ticks ({R}). PR #53 round 74: typed byte")
edit(G5, "0x0080ddfa,insite_parameter_schedule_pointer,dword,",
     "0x0080ddfa,insite_parameter_schedule_pointer,byte *,Points into insite_parameter_next_due_ticks, one byte per "
     f"schedule record (typed byte * - was dword; {R}). ")
edit(G5, "0x0080de1e,insite_parameter_table_pointer,dword,",
     "0x0080de1e,insite_parameter_table_pointer,insite_parameter_schedule_entry_t *,Points at the current "
     f"insite_parameter_schedule_table record (typed insite_parameter_schedule_entry_t * - was dword; {R}). ")
for name in ("j1708_transmit_buffer_2_32_ddc6", "address_of_scratch_pad_directory_0c000h_0f7efh",
             "buffer_used_to_store_secure_write_data_until_the_copy_0c000h_0f7efh"):
    g, _ = read(G5)
    line = [x for x in g.split("\n") if f",{name},dword," in x]
    if line:
        a = line[0].split(",")[0]
        edit(G5, f"{a},{name},dword,", f"{a},{name},byte *,Holds a buffer address (typed byte * - was dword; {R}). ")
print("round 75 stage A applied")
