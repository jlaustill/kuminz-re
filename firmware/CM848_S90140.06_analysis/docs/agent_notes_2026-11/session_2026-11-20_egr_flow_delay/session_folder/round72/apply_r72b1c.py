"""Round 72 stage B1c: firmware/feature_comparison.csv records the shared J1939 memory write service and its version
differences, and the shared security key functions. Idempotent.  usage: apply_r72b1c.py <repo>"""
import os
import sys

P = os.path.join(os.path.abspath(sys.argv[1]), "firmware/feature_comparison.csv")
R = "PR #53 round 72"
s = open(P).read()
OLD = ("auth_security,security,stub,present,present,unknown,unknown,J90280 returns 0 (disabled) - J90350 and CM848D have "
       "full implementation\n")
NEW = ("auth_security,security,stub,present,present,unknown,unknown,J90280 returns 0 (disabled) - J90350 and CM848D have "
       "full implementation: validateSecurityKey / unscrambleSecurityKey are the same functions with byte-identical "
       f"scramble tables in both ({R})\n"
       "j1939_memory_write_service,diagnostics,present,present,present,unknown,unknown,PGN 61184 services 0x4b / 0x4d "
       "through writeJ1939DiagnosticMemory and lookupApplicationMemoryRegionType - shared code (identical header length "
       "table and region codes); method versioning: CM848D returns 0x1a for a region type 3 write without the key (J90350: "
       "3) / refuses (10) type 3 writes into its calibration RAM while RAM refresh is on / adds Bank 2 (region type 2) "
       f"({R})\n")
if NEW not in s:
    assert s.count(OLD) == 1
    open(P, "w").write(s.replace(OLD, NEW))
print("round 72 stage B1c applied")
