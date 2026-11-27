"""Skeptic: wording / count fixes to build_verdict_W2.py (each old string must occur exactly once)."""
import os

HERE = os.path.dirname(os.path.abspath(__file__))
p = os.path.join(HERE, "build_verdict_W2.py")
s = open(p).read()


def rep(old, new):
    global s
    assert s.count(old) == 1, (s.count(old), old)
    s = s.replace(old, new)


rep("The four switch_N names use the e2m's own switch numbers (DS17 / 27 / \"\n    \"28 / 23 / 31SWUO), which differ "
    "from the logical index; the comments say so.",
    "The five switch_N names use the e2m's own switch numbers (DS17 / 27 / \"\n    \"28 / 23 / 31SWUO), which differ "
    "from the logical index for four of them; the comments say so.")
rep("\"count is wrong: DGOBFUHN is an S record with mask 0x400 in 21 other files (16 CHR, 5 ISB) and an N record with no \"\n"
    "    \"bit in 4 more.\",",
    "\"count is wrong: an S record with mask 0x400 sits here in 28 other files (all 23 CHR files - 16 CHR_CC with the \"\n"
    "    \"mnemonic and 7 CHR_B2 under the label OBD_Fault_Handler_Enable - and 5 ISB files: 00V2, v55t16_s, v57t6_x, \"\n"
    "    \"v59t5_t, V59t8_t), and DGOBFUHN is an N record with no bit in 4 more (42t9_rls, 44t9, Isbp400, Phase4).\",")
rep("\"' with '(S mask 0x400 here in 21 other e2m files - 16 \"\n"
    "    \"CHR and 5 ISB - and an N record with no bit in 4 more; CM848 obd_fault_handler_enable)'.\")",
    "\"' with '(S mask 0x400 here in 28 other e2m files - the \"\n"
    "    \"23 CHR files and 5 ISB files - and an N record with no bit in 4 more ISB files; CM848 \"\n"
    "    \"obd_fault_handler_enable)'.\")")
rep("with mask 0x800 (18 ISB, 16 CHR). No test; e2m only. Set.", "with mask 0x800 (18 ISB, 16 CHR_CC). No test; e2m only. Set.")
rep("all 36 ISB and 16 CHR e2m files (survey.py, countfiles.py)", "all 36 ISB and 23 CHR e2m files (survey.py, countfiles.py)")
rep("DGOBFUHN mask 0x400 in 21 not 26 (word 12 bit 10)", "the OBD fault handler mask 0x400 in 28 not 26 (word 12 bit 10)")
rep("\"18 ISB + 16 CHR files carry the mask.", "\"18 ISB + 16 CHR_CC files carry the mask.")
rep("generic SWITCH 17 records; no read of 0x80bcd0 bit 0 anywhere. The name says what is proved. Clear.\",",
    "generic SWITCH 17 records; no read of 0x80bcd0 bit 0 in the .cpp or by absolute address. The name says what is \"\n"
    "       \"proved. Clear.\",")
open(p, "w").write(s)
print("patched")
