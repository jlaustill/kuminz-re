"""Round 18 closing: three current comments that still used the retired 'delivery mode' / 'injection timing offset'
wording for main_injection_timing_selection and the 4D timing. usage: fix_retired_prose_r18.py <output dir>"""
import os
import sys

out = sys.argv[1]
FIX = {
    "global_variables.csv": [
        ("user_commanded_injection_timing_cal in fixed delivery mode 2 by cm848_selectMainInjectionTiming)",
         "user_commanded_injection_timing_cal with main_injection_timing_selection 2 by cm848_selectMainInjectionTiming)")],
    "function_renames.csv": [
        ("and overwrites the injection timing offset map copy stored there earlier by cm848_calculateFourDimensi",
         "and overwrites the 4D timing copy stored there earlier by cm848_calculateFourDimensi"),
        ("working minimum; in delivery mode 3 it adds user_commanded_injection_timing_cal",
         "working minimum; with main_injection_timing_selection 3 it adds user_commanded_injection_timing_cal")],
}
for name, pairs in FIX.items():
    p = os.path.join(out, name)
    t = open(p).read()
    for old, new in pairs:
        if old not in t and new in t:
            continue
        assert t.count(old) == 1, (name, old[:50], t.count(old))
        t = t.replace(old, new)
    open(p, "w").write(t)
print("3 phrases refreshed")
