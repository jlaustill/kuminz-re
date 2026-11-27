"""Round 96 stage H, part 2.
1. CM550's serial EEPROM write queue is one family: its two rings are typed (the only ROM references into
   0x80bda8-0x80cca7 are the two bases, 3 users each: the two queue writers and mc68k_runSerialEepromDriverStep),
   the 175 rows inside them go (none renders or is referenced; old guesses such as rpm_filter_buffer_start /
   engine_protection_coolant_ptr_1 / a second 'circular_buffer_*' set), and the index / count rows and the two other
   queue functions take the queue's name. cm550_isEepromWriteQueueEmpty / cm550_queueEepromMirrorByteWrites get a byte
   return (moveq #1 / clr.b d0), which ends their 'in_D0 & 0xffffff00' / 'uVar1 & 0xffffff00' returns.
2. Both firmwares' function_renames.csv carried comment lines above the 'address,name' header; ImportAnalysis skips only
   the first line, so it parsed the header as an address: that was the build's '1 function imports failed'. The header
   moves to line 1.
3. firmware/CLAUDE.md's bullet about that warning is corrected.
Exact-line edits; refuses on a mismatch; keeps line endings. Writes map_r96h2_cm550.csv. usage: stage_h_queue_r96.py <repo>"""
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
C550 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
C848 = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 96"


def load(p):
    t = open(p, newline="").read()
    E = "\r\n" if "\r\n" in t else "\n"
    return t.split(E), E


def save(p, lines, E):
    open(p, "w", newline="").write(E.join(lines))


maprows = []
# 1a. globals
p = os.path.join(C550, "global_variables.csv")
lines, E = load(p)
out, removed, inserted = [], 0, False
RENAME = {0x80cca8: ("eeprom_circular_buffer_read_index", "eeprom_write_queue_read_index"),
          0x80ccaa: ("eeprom_circular_buffer_write_index", "eeprom_write_queue_write_index"),
          0x80ccac: ("circular_buffer_byte_count", "eeprom_write_queue_count"),
          0x80ccb0: ("circular_buffer_last_address_offset", "eeprom_write_queue_last_request_offset")}
RINGS = [f"0x0080bda8,eeprom_write_queue_addresses,word[1280],The serial EEPROM write queue's address ring: entry i is the EEPROM address of the data byte eeprom_write_queue_data_bytes[i]. cm550_queueEepromByteWrites / cm550_queueEepromMirrorByteWrites fill it at eeprom_write_queue_write_index and mc68k_runSerialEepromDriverStep sends it to the EEPROM (QSM_TR4) from eeprom_write_queue_read_index; both indices wrap at 1280. The only ROM references into 0x80bda8-0x80cca7 are this base and the data ring's base (3 users each), so the 175 rows that sat inside the two rings were guesses ({R}).",
         f"0x0080c7a8,eeprom_write_queue_data_bytes,byte[1280],The serial EEPROM write queue's data ring: entry i is written to EEPROM address eeprom_write_queue_addresses[i] (QSM_TR5 in mc68k_runSerialEepromDriverStep); filled by cm550_queueEepromByteWrites / cm550_queueEepromMirrorByteWrites ({R})."]
for line in lines:
    parts = line.split(",", 3)
    if len(parts) > 2 and parts[0].startswith("0x"):
        a = int(parts[0], 16)
        if 0x80bda8 <= a < 0x80cca8:
            removed += 1
            if a in (0x80bda8, 0x80c7a8):
                raise SystemExit(f"a row already sits at a ring base: {line[:60]}")
            continue
        if a >= 0x80bda8 and not inserted:
            out += RINGS
            inserted = True
        if a in RENAME:
            old, new = RENAME[a]
            assert parts[1] == old, (hex(a), parts[1])
            parts[1] = new
            comment = parts[3] if len(parts) > 3 else ""
            if a == 0x80ccb0:
                comment = (f"The EEPROM offset of the first byte of the latest cm550_queueEepromMirrorByteWrites request "
                           f"(mirror address - 0x803b0a; it also seeds the address ring's entry at the write index) "
                           f"(was {old}; {R}) | " + comment)
            else:
                comment = comment + f" (was {old}; {R})"
            line = ",".join(parts[:3]) + "," + comment
            maprows.append((a, new, old))
    out.append(line)
assert inserted and removed == 175, (inserted, removed)
save(p, out, E)

# 1b. functions
p = os.path.join(C550, "function_renames.csv")
lines, E = load(p)
FUNCS = {"0x00016c2c": ("cm550_circularBufferEmptyCheck", "cm550_isEepromWriteQueueEmpty",
                        f"Returns 1 when the serial EEPROM write queue is empty (eeprom_write_queue_count is 0), else 0 (moveq #1 / clr.b d0). (was cm550_circularBufferEmptyCheck; {R})"),
         "0x00016c3c": ("cm550_parameterCircularBufferWrite", "cm550_queueEepromMirrorByteWrites",
                        f"cm550_queueEepromByteWrites for an address in the EEPROM mirror: returns 1 and queues nothing when eeprom_write_queue_count + byte_count would pass 1280; otherwise it stores the first byte's EEPROM offset (mirror_address - 0x803b0a) in eeprom_write_queue_last_request_offset and queues each byte with its EEPROM address (the mirror address - 0x803b0a); returns 0. (was cm550_parameterCircularBufferWrite; {R})")}
for a, (old, new, plate) in FUNCS.items():
    hits = [k for k, l in enumerate(lines) if l == f"{a},{old}"]
    assert len(hits) == 1, (a, old)
    lines[hits[0]] = f"{a},{new},{plate}"
    maprows.append((int(a, 16), new, old))
# 2. the header to line 1 (both firmwares)
for d in (C550, C848):
    q = os.path.join(d, "function_renames.csv")
    ls, e = (lines, E) if d == C550 else load(q)
    k = [i for i, l in enumerate(ls) if l.startswith("address,name")]
    assert len(k) == 1, (q, k)
    header = ls.pop(k[0])
    ls.insert(0, header)
    save(q, ls, e)
# 1c. prototypes
p = os.path.join(C550, "function_definitions.csv")
lines, E = load(p)
OLD = ["0x00016c3c,cm550_parameterCircularBufferWrite,0,dest_address,int,Destination EEPROM/RAM address",
       "0x00016c3c,cm550_parameterCircularBufferWrite,1,source_ptr,byte*,Pointer to source data",
       "0x00016c3c,cm550_parameterCircularBufferWrite,2,byte_count,ushort,Number of bytes to write"]
k = lines.index(OLD[0])
assert lines[k:k + 3] == OLD
lines[k:k + 3] = [
    f"0x00016c3c,cm550_queueEepromMirrorByteWrites,return,,byte,1 = the queue cannot take byte_count more entries (nothing queued) / 0 = queued (moveq #1 / clr.b d0) ({R})",
    f"0x00016c3c,cm550_queueEepromMirrorByteWrites,0,mirror_address,dword,The EEPROM mirror address of the first byte (0x803b0a = EEPROM 0): the long at +4 (was dest_address int; {R})",
    f"0x00016c3c,cm550_queueEepromMirrorByteWrites,1,source,byte*,The data bytes: the long at +8 (was source_ptr; {R})",
    f"0x00016c3c,cm550_queueEepromMirrorByteWrites,2,byte_count,ushort,The number of bytes: the word at +12 ({R})"]
lines.insert(k, f"0x00016c2c,cm550_isEepromWriteQueueEmpty,return,,byte,1 = the queue is empty / 0 = entries pending (moveq #1 / clr.b d0; takes no arguments) ({R})")
save(p, lines, E)
# 3. firmware/CLAUDE.md
p = os.path.join(repo, "firmware/CLAUDE.md")
t = open(p, newline="").read()
old = ('- **"1 function import failed" build warning is benign/long-standing** — it is NOT caused by your edit. Verify YOUR '
       'specific CSV additions rendered in the `.cpp` (grep the new names) rather than chasing the warning.')
new = ('- **The old "1 function imports failed" build warning was the CSV header** (PR #53 round 96): both '
       '`function_renames.csv` files had comment lines above their `address,name` header, so `ImportAnalysis` (which '
       'skips only the first line) parsed the header as an address. The header is line 1 now and neither build reports '
       'the warning, so a new one means a row whose address cannot become a function. Still verify your CSV additions '
       'rendered in the `.cpp` (grep the new names).')
assert t.count(old) == 1
open(p, "w", newline="").write(t.replace(old, new))
with open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "map_r96h2_cm550.csv"), "w") as f:
    f.write("address,name,old_label,kind,dims\n")
    for a, new, old in maprows:
        f.write(f"0x{a:08x},{new},{old},symbol,1\n")
print("rows removed", removed, "renames", len(maprows))
