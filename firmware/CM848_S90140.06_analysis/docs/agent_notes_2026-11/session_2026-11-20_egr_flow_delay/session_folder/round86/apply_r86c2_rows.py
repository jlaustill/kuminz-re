"""Round 86 stage C2 (CM550 function_definitions.csv): the two chip select 5 message object wrappers. After wave 2 gave
cm550_modeBasedDataDispatcher (0xc80e) its message_object row, its wrapper was the one function left with a stack
token (in_D0w): the wrappers read their own word at +4. ROM 0x1e1ac / 0x1e1be: 32 2f 00 04 (move.w (4,sp),d1) /
10 01 (move.b d1,d0) / 3f 00 (move.w d0,-(sp)) / 4e b9 (jsr 0xc80c / 0xc80e) / 54 8f (addq.l #2,sp) / 4e 75 (rts).
Idempotent. usage: apply_r86c2_rows.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
D5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/function_definitions.csv")
R = "PR #53 round 86"
ROWS = [
    f"0x0001e1ac,cm550_emptyStubWrapper1,0,message_object,ushort,The 82527 message object number - the word at +4 (move.w (4;sp);d1); its low byte is passed on as a word to the empty stub 0xc80c (move.b d1;d0 / move.w d0;-(sp)) ({R})",
    f"0x0001e1be,cm550_modeBasedDataDispatcherWrapper,0,message_object,ushort,The 82527 message object number - the word at +4 (move.w (4;sp);d1); its low byte is passed on as a word to cm550_modeBasedDataDispatcher (move.b d1;d0 / move.w d0;-(sp)) ({R})",
]
t = open(D5, newline="").read()
eol = "\r\n" if "\r\n" in t else "\n"
missing = [r for r in ROWS if r.split(",")[0] + "," not in t]
if missing:
    open(D5, "w", newline="").write(t.rstrip("\r\n") + eol + eol.join(missing) + eol)
print(f"added {len(missing)} rows")
