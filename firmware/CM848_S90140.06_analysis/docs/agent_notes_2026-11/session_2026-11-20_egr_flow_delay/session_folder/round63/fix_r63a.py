"""Round 63 stage A fixes from the first build:
- j1939_memory_read_reply_services is 10 bytes (0x43-0x4c): byte[11] reached 0x53a33a, which
  cm848_lookupApplicationMemoryRegionType reads as the start of its memory region table (the boot copy at 0x7f60 is
  10 bytes too);
- the dispatcher's local rows: the struct field's enum type reaches the service local before the local stage runs, so
  the decompiler already calls it JVar1; the importer refuses an empty type, so each row names its type.
Idempotent.  usage: fix_r63a.py <repo>"""
import os
import sys

O = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")


def edit(path, old, new):
    s = open(path).read()
    if new in s:
        return
    assert s.count(old) == 1, (path, old[:80], s.count(old))
    open(path, "w").write(s.replace(old, new))


edit(os.path.join(O, "global_variables.csv"),
     "0x0053a330,j1939_memory_read_reply_services,byte[11],The reply service of each PGN 61184 memory read - indexed by "
     "the read service - 0x43 (cm848_readJ1939DiagnosticMemoryAndRespond): 0x45 / 0x47 / 0x49 / 0x4b / 0x4d for 0x43 / "
     "0x46 / 0x48 / 0x4a / 0x4c and 0 for the write services between.",
     "0x0053a330,j1939_memory_read_reply_services,byte[10],The reply service of each PGN 61184 memory read - indexed by "
     "the read service - 0x43 (cm848_readJ1939DiagnosticMemoryAndRespond): 0x45 / 0x47 / 0x49 / 0x4b / 0x4d for 0x43 / "
     "0x46 / 0x48 / 0x4a / 0x4c and 0 for the write services between. 10 bytes (0x43-0x4c): 0x53a33a starts the memory "
     "region table of cm848_lookupApplicationMemoryRegionType.")
L = os.path.join(O, "local_variables.csv")
D = "0x00022128,cm848_j1939DiagnosticServiceHandler"
edit(L, f"{D},bVar1,service,J1939_DIAGNOSTIC_SERVICE,", f"{D},JVar1,service,J1939_DIAGNOSTIC_SERVICE,")
edit(L, f"{D},bVar2,entry_index,,", f"{D},bVar2,entry_index,byte,")
edit(L, f"{D},pjVar3,entry,,", f"{D},pjVar3,entry,j1939_diagnostic_service_entry_t *,")
edit(L, f"{D},uVar4,result_code,,", f"{D},uVar4,result_code,uint,")
print("stage A fixes applied")
