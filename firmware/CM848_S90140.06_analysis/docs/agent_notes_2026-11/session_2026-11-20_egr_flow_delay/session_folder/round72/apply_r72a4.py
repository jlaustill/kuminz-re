"""Round 72 stage A4 (from stage A3's CM550 build): the dispatcher's five local rows (0x2148a) were written for an old
render - in the base build none applied (4 'not found', bVar2's 'bool' unknown) - and stage A's retype shifted the
placeholders so that 'uVar4' matched by accident: a stray 'dword memcpy_return' appeared on the wrong variable. They go;
stage B (the dispatcher's prototype) writes rows for its real placeholders. Their meanings, kept for stage B:
  uVar1 calculated_msg_length (operation length + header length) / bVar2 has_auth_payload (the 10-byte key is present) /
  dVar3 region_type_copy (the switch copy of the region type) / cVar5 auth_validation_result (the key check's result,
  0 = pass) / uVar4 memcpy_return.
Idempotent; keeps line endings.  usage: apply_r72a4.py <repo>"""
import os
import sys

P = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM550_J90350.00_analysis/output/local_variables.csv")
s = open(P, newline="").read()
eol = "\r\n" if "\r\n" in s else "\n"
lines = s.split(eol)
stale = [l for l in lines if l.startswith("0x0002148a,memoryOperationDispatcher,")]
assert len(stale) in (0, 5), stale
for l in stale:
    lines.remove(l)
open(P, "w", newline="").write(eol.join(lines))
print(f"round 72 stage A4 applied ({len(stale)} rows removed)")
