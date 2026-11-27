"""Round 72 stage B1 docs: the README's write-path diagram and its table section, and the service 0x4B analysis' name map,
use the shared names (the diagram keeps its widths). Idempotent.  usage: apply_r72b1d.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
R = "PR #53 round 72"


def edit(p, old, new):
    s = open(p).read()
    if new in s:
        return
    assert s.count(old) == 1, (os.path.basename(p), old[:90], s.count(old))
    open(p, "w").write(s.replace(old, new))


README = os.path.join(repo, "README.md")
for old, new in (("│ memoryOperationFromMessageExtended  │", "│ handleJ1939WriteMemoryService       │"),
                 ("│ memoryOperationDispatcher           │", "│ writeJ1939DiagnosticMemory          │"),
                 ("│ hourMeterSecurityValidator   to      (LOGGING_", "│ validateSecurityKey          to      (LOGGING_"),
                 ("│    bitPackingAlgorithm│", "│  unscrambleSecurityKey│")):
    assert len(old) == len(new), (old, new)
    edit(README, old, new)
edit(README,
     "### bitPackingAlgorithm Lookup Tables (ROM @ 0x2fbc4)\n"
     "\n"
     "| Table                  | Address  | Values (hex)                          |\n"
     "|------------------------|----------|---------------------------------------|\n"
     "| SECURITY_MASK_TABLE    | 0x2fbc4  | `46 58 9a 32 70 87 23 99 85 64`       |\n"
     "| SECURITY_XOR_TABLE     | 0x2fbce  | `06 08 01 02 00 07 03 09 05 04`       |\n"
     "| SECURITY_REORDER_TABLE | 0x2fbd7  | (same data, read backwards)           |\n",
     "### unscrambleSecurityKey Lookup Tables (ROM @ 0x2fbc4)\n"
     "\n"
     "| Table                        | Address  | Values (hex)                    |\n"
     "|------------------------------|----------|---------------------------------|\n"
     "| `security_key_scramble_mask` | 0x2fbc4  | `46 58 9a 32 70 87 23 99 85 64` |\n"
     "| `security_key_byte_order`    | 0x2fbce  | `06 08 01 02 00 07 03 09 05 04` - the XOR step reads it forwards, "
     "the reorder step backwards from 0x2fbd7 |\n"
     "\n"
     "CM848 holds the same bytes at 0x5839a / 0x583a4, and its `unscrambleSecurityKey` (0x555cc) is the same function - "
     f"the J1939 memory write path is shared code ({R}).\n")
DOC = os.path.join(repo, "firmware/docs/service_0x4b_analysis.md")
edit(DOC, "its table is `application_memory_region_table` at ROM 0x345dc (5 entries; CM848 has 7).\n",
     "its table is `application_memory_region_table` at ROM 0x345dc (5 entries; CM848 has 7).\n"
     "> The write path's other functions are CM848 twins too, so they share names: `memoryOperationDispatcher` "
     "(0x2148a) = `writeJ1939DiagnosticMemory`, `memoryOperationFromMessageExtended` (0x217de) = "
     "`handleJ1939WriteMemoryService`, `memoryOperationFromMessage8Byte` (0x21826) = "
     "`handleJ1939WriteMemoryLongLengthService` (service 0x4d: its length is 4 bytes - not an 8-byte message), "
     "`addressLookupFunction` (0x21964) = `getJ1939MemoryServiceHeaderLength`, `hourMeterSecurityValidator` (0x2fcdc) = "
     "`validateSecurityKey` and `bitPackingAlgorithm` (0x2fbd8) = `unscrambleSecurityKey`; the tables are "
     "`security_key_scramble_mask` (0x2fbc4), `security_key_byte_order` (0x2fbce) and "
     "`j1939_memory_service_header_lengths` (0x21956), each byte-identical with CM848's.\n")
print("round 72 stage B1 docs applied")
