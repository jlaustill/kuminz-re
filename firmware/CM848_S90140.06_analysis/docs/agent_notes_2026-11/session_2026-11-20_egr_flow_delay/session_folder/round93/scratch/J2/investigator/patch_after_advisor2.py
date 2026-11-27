"""J2 investigator run 2: edits after the second advisor review (idempotent).
- digests: CM848's tracker has 4 bl to the store function (one shared by two engine paths) against CM550's 5 bsr;
  CM848's lost management clears the mode / device only outside its ramp;
- 0x238ac is a counterpart for the capacity constant alone;
- the two caller differences of the twins 0x23820 / 0x239d2 are stated in the notes;
- the j1939_control_session_t fields are spelled out with CM550's types;
- e2m quotes that the e2m truncates are marked as such."""
import os

here = os.path.dirname(os.path.abspath(__file__))


def patch(name, pairs):
    p = os.path.join(here, name)
    t = open(p).read()
    n = 0
    for old, new in pairs:
        if new in t:
            continue
        assert t.count(old) == 1, (name, t.count(old), old[:70])
        t = t.replace(old, new)
        n += 1
    open(p, "w").write(t)
    print(name, n)


patch("compact_evidence.py", [
    ("copy 12 words: 0x21f52-0x21fa4 | 0x50be74-0x50bee4. Callers: only the session tracker (5 bsr | 5 calls).",
     "copy 12 words: 0x21f52-0x21fa4 | 0x50be74-0x50bee4. Callers: only the session tracker (5 bsr | 4 bl, one shared by two paths)."),
    ("with the same quirk (the retarder source word compared with the previous byte). One caller each",
     "with the same quirk (the retarder source word compared with the previous byte); CM848 shares one store call between two engine paths (b 0x50c1a0). One caller each"),
    ("CM848 0x26f80 does these resets only outside its TSC1 lost ramp.",
     "CM848 0x26f80 clears the same timers but the mode and device only outside its TSC1 lost ramp."),
])
patch("compact_comments.py", [
    ("JC22LMTM 'ECM TIME OF LAST J1922 LIMIT COMMAND'", "JC22LMTM 'ECM TIME OF LAST J1922 LIMIT COM(MAND)'"),
])
patch("patch_part2_run2.py", [
    ('''    ("(no absolute reference to any of them)",''',
     '''    ("'J1922 LIMIT ENGINE OCC. TIME ECM TIME OF LAST J1922 LIMIT COMMAND'",
     "'J1922 LIMIT ENGINE OCC. TIME ECM TIME OF LAST J1922 LIMIT COM(MAND)'", 1),
    ("'J1922 LIMIT ENGINE MODE COUNT 0 = J1922 HASN'T LIMITED ENGINE'",
     "'J1922 LIMIT ENGINE MODE COUNT 0 = J1922 HASN'T LIMITED ENGI(NE)'", 1),
    ("(no absolute reference to any of them)",'''),
])
patch("patch_part1_run2.py", [
    ('''     " A constant and the callers differ, so a counterpart."),''',
     '''     " One constant differs (5 against 10): a counterpart by this round's rule."),'''),
])
patch("summary_notes_compact.py", [
    ("0x238ac is a counterpart only for the capacity 5 against 10 and CM848's second caller (round 91 shared a 16 \"\n    \"against 17 case); 0x231da",
     "0x238ac is a counterpart for the capacity alone, 5 against 10 (round 91 shared a 16 against 17 case); the twins \"\n    \"0x23820 / 0x239d2 share processEngineTsc1Request as caller, but CM550 adds its J1922 handlers and CM848 adds \"\n    \"cm848_updateParkNeutralFlagAndTsc1Activity for the remover; 0x231da"),
    ("j1939_control_session_t = CM848's 24-byte struct; ",
     "j1939_control_session_t 24 bytes (byte session_kind, byte controlling_source_address, word control_device, word \"\n    \"override_control_mode_count, word[5] override_control_modes, dword start_time, dword duration: CM848's struct \"\n    \"with words for its two enums); "),
])
patch("summary_notes.py", [
    ("0x238ac differs from CM848 only by the capacity (5 against 10) and CM848's second caller: a \"\n    \"counterpart by this round's rule, though round 91 shared registerJ1939ReceiveHandler at 16 against 17. 0x23820 / \"\n    \"0x239d2 have no differing constant; CM550 also calls them from J1922 handlers CM848 lacks.",
     "0x238ac differs from CM848 only by the capacity (5 against 10): a counterpart by this round's rule, though \"\n    \"round 91 shared registerJ1939ReceiveHandler at 16 against 17. 0x23820 / 0x239d2 have no differing constant and \"\n    \"share processEngineTsc1Request as caller; CM550 also calls them from J1922 handlers CM848 lacks, and CM848 calls \"\n    \"the remover from cm848_updateParkNeutralFlagAndTsc1Activity (as it does the appender)."),
])
