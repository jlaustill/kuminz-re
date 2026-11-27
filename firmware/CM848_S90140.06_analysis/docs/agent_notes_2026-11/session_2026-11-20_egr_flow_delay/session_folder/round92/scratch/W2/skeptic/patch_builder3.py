"""Skeptic: shorten the generated reasons of the engine protection bits in build_verdict_W2.py (each old block must
occur exactly once)."""
import os

HERE = os.path.dirname(os.path.abspath(__file__))
p = os.path.join(HERE, "build_verdict_W2.py")
s = open(p).read()


def rep(old, new):
    global s
    assert s.count(old) == 1, (s.count(old), old[:80])
    s = s.replace(old, new)


# word 7
rep('''KREAD = ["k 0: cm550_FUN_00019702 (moveq #112 at 0x19718)",
         "k 1: cm550_calculateFaultDerateEngineSpeedLimit (moveq #113 at 0x18e22)",
         "k 2: processDiagnosticLimitStatus (moveq #114 at 0x1902a) and the +2 tests at 0x18b6c / 0x18d1a",
         "k 3: the +3 tests at 0x18b9a (cm550_diagnosticProtectionEvaluator) and 0x18d46 "
         "(cm550_protectionState1DiagnosticValidator)"]''',
    '''KREAD = ["k 0 = cm550_FUN_00019702 (moveq #112 at 0x19718)",
         "k 1 = cm550_calculateFaultDerateEngineSpeedLimit (moveq #113 at 0x18e22)",
         "k 2 = processDiagnosticLimitStatus (moveq #114 at 0x1902a) and the +2 tests at 0x18b6c / 0x18d1a",
         "k 3 = the +3 tests at 0x18b9a / 0x18d46 (the two restart checks)"]''')
rep('''        reader = ("k 2: processDiagnosticLimitStatus (moveq #114 at 0x1902a) and the +2 test at 0x18d1a "
                  "(cm550_protectionState1DiagnosticValidator)")''',
    '''        reader = "k 2 = processDiagnosticLimitStatus (moveq #114 at 0x1902a) and the validator's +2 test at 0x18d1a"''')
rep('''        reader = "k 3: the +3 test at 0x18d46 (cm550_protectionState1DiagnosticValidator)"''',
    '''        reader = "k 3 = the validator's +3 test at 0x18d46"''')
rep('''    base = (f"{pre}{KSUF[k]}: N record '{token} ...' in v64t6_s and S mask 0x{1 << bit:x} in 34 other files (CM848's "
            f"16 CHR_CC files among them); table bit {112 + bit} = word 7 bit {bit}; {reader}; channel {ch} = {cname} "
            f"(input {inp}); set in 0xffff.")''',
    '''    base = (f"{pre}{KSUF[k]}: N record '{token}' in v64t6_s, S mask 0x{1 << bit:x} in 34 other files (CM848's 16 "
            f"among them); table bit {112 + bit}: {reader}; channel {ch} = {cname}; set.")''')
rep('''        add(f"word 7 bit {bit}", "CONFIRMED", base + " Direct test too: andi.w #0x1000 at 0x1983e (bytes 0240 1000); "
            "while set and 0x80062e < 0x807f34 it writes 0x100 to 0x80581a (= 0x8057c0 + 3 x 30) and to the maximum.")''',
    '''        add(f"word 7 bit {bit}", "CONFIRMED", base + " Direct test too: andi.w #0x1000 at 0x1983e (0240 1000); while "
            "set and 0x80062e < 0x807f34 it writes 0x100 to 0x80581a (= 0x8057c0 + 3 x 30) and to the maximum.")''')
rep('''        add(f"word 7 bit {bit}", "AMENDED", base + " One wording slip: cm550_diagnosticProtectionEvaluator returns at "
            "cmpi.w #3,(0x8058ce) (0x18b0a) before its bit tests, so for channel 3 only the validator reads this bit - "
            "as the comment of bit 15 already says.",''',
    '''        add(f"word 7 bit {bit}", "AMENDED", base + " One wording slip: cm550_diagnosticProtectionEvaluator returns at "
            "cmpi.w #3,(0x8058ce) (0x18b0a) before its bit tests, so of the restart checks only the validator reads "
            "this bit - as the comment of bit 15 already says.",''')
rep('''        add(f"word 7 bit {bit}", "CONFIRMED", base + " The evaluator returns at cmpi.w #3,(0x8058ce) (0x18b0a), so "
            "only the validator reads it, as the comment says.")''',
    '''        add(f"word 7 bit {bit}", "CONFIRMED", base + " The evaluator returns at cmpi.w #3,(0x8058ce) (0x18b0a) "
            "first, as the comment says.")''')
# word 8
rep('''KSHORT = ["k 0 (the fuel limit loop cm550_FUN_00019702)", "k 1 (cm550_calculateFaultDerateEngineSpeedLimit)",
          "k 2 (processDiagnosticLimitStatus and the two restart checks)", "k 3 (the two restart checks)"]''',
    '''KSHORT = ["k 0 (fuel limit loop)", "k 1 (speed limit loop)", "k 2 (shutdown loop and restart checks)",
          "k 3 (restart checks)"]''')
rep('''        r = (f"{pre}{KSUF[k]}: S record with mask 0x{1 << bit:x} in v64t6_s itself (and in 26 other ISB files); table "
             f"bit {tb} = word 8 bit {bit}; {KSHORT[k]} of channel {4 + ch} = {cname} (input {inp}); clear.")''',
    '''        r = (f"{pre}{KSUF[k]}: S mask 0x{1 << bit:x} in v64t6_s itself (and 26 other ISB files); table bit {tb}: "
             f"{KSHORT[k]} of channel {4 + ch} = {cname} ({inp}); clear.")''')
rep('''        r = (f"{pre}{KSUF[k]}: N record 'BIT {bit} OF 0-1{'4' if bit == 14 else '5'}' in v64t6_s and 35 other ISB "
             f"files (no S mask in this family; CM848's files put the channel at 0x1-0x8); table bit {tb} = word 8 bit "
             f"{bit}; {KSHORT[k]} of channel 7 = {cname} (input {inp}); clear.")''',
    '''        r = (f"{pre}{KSUF[k]}: N record 'BIT {bit} OF 0-1{'4' if bit == 14 else '5'}' in v64t6_s and 35 other ISB "
             f"files (no S mask in this family); table bit {tb}: {KSHORT[k]} of channel 7 = {cname} ({inp}); clear.")''')
# word 9
rep('''            f"EPAA{KSUF[bit]}: S record with mask 0x{1 << bit:x} in v64t6_s; table bit {144 + bit} = "
            f"{KSHORT[bit]} of channel 8 = ambient air pressure (input 0x80a3ba ADAAPRFT); clear. "
            "Documentation only (the word stays plain).")''',
    '''            f"EPAA{KSUF[bit]}: S mask 0x{1 << bit:x} in v64t6_s; table bit {144 + bit}: {KSHORT[bit]} of channel 8 = "
            "ambient air pressure (0x80a3ba ADAAPRFT); clear. Documentation only (the word stays plain).")''')
rep('''            f"reserved_bit_{bit} is right: no v64t6_s record at mask 0x{1 << bit:x}, the loops stop at bit 3, clear. "
            f"The count in the guess is off: {fam} are in 18 other files (63t10r4, the seven 74be*, 74c0 / 74c5 / 74c6, "
            "74t5 / 74t6, 74te3rls / 74te4rls / 74te5rls, 84t0, Isbp700), not 20.",''',
    '''            f"reserved_bit_{bit} is right: no v64t6_s record at mask 0x{1 << bit:x}, the loops stop at bit 3, clear. "
            f"The count in the guess is off: {fam} are in 18 other files, not 20.",''')
rep('''    "S records (masks 0x1-0x8). CM848 has no row, no record at +0014 and no reference to 0x3fd5ae (0x0000 in its dump).")''',
    '''    "S records (masks 0x1-0x8). CM848 has no row, no record at +0014 and no reference to 0x3fd5ae (0x0000 in its dump). "
    "For bits 4-11: the 18 files with EPOE* / EPOS* are 63t10r4, the seven 74be*, 74c0 / 74c5 / 74c6, 74t5 / 74t6, "
    "74te3rls / 74te4rls / 74te5rls, 84t0 and Isbp700.")''')
open(p, "w").write(s)
print("patched")
