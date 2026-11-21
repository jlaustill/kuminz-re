"""Round 11 stage B, part 2: the lift pump types. The five calibration words and sci_output_status_word (stage A's
label-only rows) are words (lhz / sth); LIFT_PUMP_RUN_REASON (size 2) types lift_pump_run_reason (cm848_controlLiftPump
stores 2 / 3, cm848_initializeLiftPumpControl 1, and the stop checks compare with 1 / 2 / 3).
usage: apply_r11b_lift_pump.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
gv = os.path.join(out, "global_variables.csv")
lines = open(gv).read().split("\n")
TYPES = {"0x00408976": ("", "word"), "0x00408978": ("", "word"), "0x0040897a": ("", "word"), "0x0040897c": ("", "word"),
         "0x0040897e": ("", "word"), "0x003fcf26": ("", "word"), "0x003fcea6": ("word", "LIFT_PUMP_RUN_REASON")}
done = 0
for i, l in enumerate(lines):
    a = l[:10]
    if a in TYPES:
        addr, name, typ, comment = (l.split(",", 3) + [""])[:4]
        assert typ == TYPES[a][0], (a, typ)
        lines[i] = ",".join([addr, name, TYPES[a][1], comment])
        done += 1
assert done == len(TYPES), done
open(gv, "w").write("\n".join(lines))
en = os.path.join(out, "enums.csv")
text = open(en).read()
assert "\nLIFT_PUMP_RUN_REASON," not in text
rows = [
    'LIFT_PUMP_RUN_REASON,1,LIFT_PUMP_RUN_REASON_KEY_ON,"Key on without starting (cm848_initializeLiftPumpControl): the pump stops after lift_pump_run_time_after_key_on",2',
    'LIFT_PUMP_RUN_REASON,2,LIFT_PUMP_RUN_REASON_ENGINE_RUNNING,"The engine ran (RUNNING or ENGINE_BRAKE): after it stops the pump runs lift_pump_run_time_after_running",2',
    'LIFT_PUMP_RUN_REASON,3,LIFT_PUMP_RUN_REASON_ENGINE_CRANKING,"The engine cranked (CRANKING / REENTRY / JUMP_START): after it stops the pump runs lift_pump_run_time_after_cranking",2',
]
text = text.rstrip("\n") + "\n" + "\n".join(rows) + "\n"
open(en, "w").write(text)
print(done, "rows typed, 3 enum members")
