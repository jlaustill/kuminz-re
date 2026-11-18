"""Turn the two read-modify-write flag bytes back into plain byte fields (Ghidra 12.1 prints their `|` / `&` updates
as `._N_1_` pieces of a bitfield unit), keeping every bit's evidence in the byte's comment; and note in the
cm848_latchNewlyActiveFault plate how its history shift is addressed. Usage: fix_rmw_bytes.py <output dir>"""
import os
import re
import sys

out = sys.argv[1]
SD = os.path.join(out, "structure_definitions.csv")
lines = open(SD).read().split("\n")


def collapse(prefix, field, lead):
    rows = [i for i, l in enumerate(lines) if l.startswith(prefix) and ",bitfield:1@" in l]
    assert len(rows) == 8, (prefix, len(rows))
    parts = []
    for i in rows:
        m = re.match(re.escape(prefix) + r'([a-z_0-9]+),bitfield:1@(\d),\d,("(?:[^"]|"")*"|[^,]*),', lines[i])
        name, bit, comment = m.group(1), int(m.group(2)), m.group(3).strip('"').replace('""', '"')
        if comment.startswith("never tested or set"):
            continue
        label = name if not name.startswith("reserved_bit_") else "unnamed"
        parts.append(f"0x{1 << bit:02x} {label}: {comment}")
    text = lead + " | ".join(parts)
    new = f'{prefix}{field},byte,1,"{text.replace(chr(34), chr(39))}",,verified'
    lines[rows[0]:rows[-1] + 1] = [new]


collapse("protection_condition_flags_t,0x0040b0e8,", "fault_state_flags",
         "Fault-active flags byte, updated with | / & masks (so a byte, not a bitfield: Ghidra 12.1 prints those "
         "updates as pieces). Bits: ")
collapse("protection_status_flags_t,0x0040b0f2,", "status_flags",
         "Governor pressure / wide open throttle status byte, updated with | / & masks (so a byte, not a bitfield). "
         "Bits 0x10 / 0x08 are unproven guesses. Bits: ")
open(SD, "w").write("\n".join(lines))

FR = os.path.join(out, "function_renames.csv")
text = open(FR).read()
anchor = "\n0x00534b68,cm848_latchNewlyActiveFault,"
assert text.count(anchor) == 1
start = text.index(anchor) + 1
end = text.index("\n", start)
row = text[start:end]
note = (" Decompiler note: the history shift protection_event_spn_history[i] = [i - 1] addresses [i - 1] from 0x3fedba,"
        " which is the last word of fault_entry_pointer_queue_cal, so it prints as an access to the queue.")
if row.endswith('"'):
    row = row[:-1] + note + '"'
elif "," in row.split(",", 2)[2]:
    row = row.split(",", 2)
    row = f'{row[0]},{row[1]},"{row[2].replace(chr(34), chr(39))}{note}"'
else:
    row = row + note
open(FR, "w").write(text[:start] + row + text[end:])
print("fixed")
