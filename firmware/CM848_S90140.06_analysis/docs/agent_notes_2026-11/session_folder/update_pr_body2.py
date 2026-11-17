"""PR #50 body: auto-label cleanup and the r29 quirk."""
import sys

p = sys.argv[1]
t = open(p).read()
anchor = "## Finding for task 022: the J1939 pedal reaches fueling"
add = ("11. **Ghidra auto-label rows.**\n"
       "    - 120 rows named `BYTE_…` / `PTR_DAT_…` / `PTR_FUN_…` are now type-only, and one untyped string label is gone. Register addresses are left alone.\n"
       "    - Boot-ROM calls into the kernel's RAM copy now show their functions: `mpc555_dispatchCanMessageHandlers()` (was `BYTE_003fae3c()`), `mpc555_serviceJ1939TransportSessions`, `mpc555_cmfEraseBlocks`, `cm848_copyBytes`, `cm848_allocateDiagnosticResponseBuffer`.\n"
       "    - 0x3fd1ac / 0x3fd284 / 0x3fd298 keep a `BYTE_` label on purpose. The application uses them as data, and they'd otherwise render as `cm848_sendDiagResponsePending = 0`.\n"
       "    - 19 functions change, every change a label.\n"
       "12. **Todo 039 closed: a stale-r29 quirk, confirmed in the disassembly.**\n"
       "    - Only governor mode 1 sets r29, the start temperature. In every other mode the integrator-preset lookup at 0x48ba8 reads the caller's r29, which is the `unaff_r29` argument.\n"
       "    - It's likely harmless: it only runs with the engine stopped, and mode 1 recomputes the preset before a start.\n\n")
assert t.count(anchor) == 1
open(p, "w").write(t.replace(anchor, add + anchor))
print("ok")
