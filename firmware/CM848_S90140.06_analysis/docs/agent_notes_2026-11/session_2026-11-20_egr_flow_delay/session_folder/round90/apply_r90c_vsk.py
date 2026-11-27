"""Round 90 stage C side fix (CM550): validateSecurityKey's (0x2fcdc) local rows. 7 of its 10 rows never applied:
'bool' was an unknown local type, and six named temporaries of an older decompilation (key_matches, cVar3, puVar4,
pbVar5, puVar6, extracted_hour_meter). The rows of a function are all matched against one decompilation taken
before any of them commits, in which validation_result is still uVar2, so the later temporaries are numbered one
higher than in the final output. The reused byte pointer (the hour meter bytes, then the key compare) keeps its
auto-name: naming a reused register splits it. Idempotent. usage: apply_r90c_vsk.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
L = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/local_variables.csv")
R = "PR #53 round 90"
lines = open(L, newline="").read().split("\n")
ROWS = [
    "0x0002fcdc,validateSecurityKey,bVar1,all_keys_match,bool,True while every key byte so far matches "
    "security_master_password_cal",
    "0x0002fcdc,validateSecurityKey,uVar2,validation_result,byte,Return value 0 = accepted / 1 = refused",
    f"0x0002fcdc,validateSecurityKey,bVar3,hour_meter_byte_count,byte,Counts the hour meter bytes copied into "
    f"extracted_hour_meter (1-3) ({R})",
    f"0x0002fcdc,validateSecurityKey,cVar4,key_byte_index,char,Loop counter 0-5 for the key comparison ({R})",
    f"0x0002fcdc,validateSecurityKey,puVar5,hour_meter_copy_destination,uint*,Walks extracted_hour_meter byte by "
    f"byte ({R})",
    f"0x0002fcdc,validateSecurityKey,local_12,extracted_hour_meter,uint,The hour meter from the auth payload: its top "
    f"three bytes are compared with key_on_hour_meter's (a difference below 26 is accepted) ({R})",
    "0x0002fcdc,validateSecurityKey,abStack_e,extracted_key,byte[6],6-byte key from auth payload",
    "0x0002fcdc,validateSecurityKey,auStack_8,hour_meter_bytes,byte[4],4-byte hour meter from auth payload",
]
old = [i for i, l in enumerate(lines) if l.startswith("0x0002fcdc,validateSecurityKey,")]
if lines[old[0]:old[0] + len(ROWS)] != ROWS:
    assert old == list(range(old[0], old[0] + len(old))), old
    lines[old[0]:old[-1] + 1] = ROWS
    open(L, "w", newline="").write("\n".join(lines))
print(f"validateSecurityKey: {len(old)} rows -> {len(ROWS)}")
