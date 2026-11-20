"""Stage 5b, part 3: comment prose that still describes engine_state with the old COLD_START_PHASE reading (3 "at the
governor setpoint" = RUNNING, 4 "fuel mode switch" / "engine retarder active" = ENGINE_BRAKE, 5 = OVERSPEED, 7
"setpoint underrun" = REENTRY, "cranking / below-trigger" = STOPPED / CRANKING / JUMP_START / REENTRY). Each was checked
against the engine_state compare in the code before it was replaced.
usage: apply_stage5b_state_prose.py <CM848 output dir>"""
import os
import sys

OUT = sys.argv[1]
TEXT = [  # (file, exact old text, new text)
    ("function_renames.csv", "cm848_calculateFuelMeteringCommand while engine_state is at the governor setpoint and",
     "cm848_calculateFuelMeteringCommand while engine_state is ENGINE_STATE_RUNNING and"),
    ("function_renames.csv", "or engine_state is the fuel mode switch phase: reads QADC",
     "or engine_state is ENGINE_STATE_ENGINE_BRAKE: reads QADC"),
    ("function_renames.csv", "unless engine_state is at the governor setpoint or the fuel mode switch",
     "unless engine_state is ENGINE_STATE_RUNNING or ENGINE_STATE_ENGINE_BRAKE"),
    ("function_renames.csv", "with the vehicle stopped, engine_state at the governor setpoint,",
     "with the vehicle stopped, engine_state ENGINE_STATE_RUNNING,"),
    ("function_renames.csv", "field_mode_register is 5100), engine_state is at the governor setpoint,",
     "field_mode_register is 5100), engine_state is ENGINE_STATE_RUNNING,"),
    ("global_variables.csv", "set when engine_state is at the governor setpoint and the engine is warm",
     "set when engine_state is ENGINE_STATE_RUNNING and the engine is warm"),
    ("global_variables.csv", "passes with the switch fault set while engine_state is at the governor setpoint;",
     "passes with the switch fault set while engine_state is ENGINE_STATE_RUNNING;"),
    ("global_variables.csv", "(resets it to 51200 = 1.0 outside the governor-setpoint cold start phases)",
     "(resets it to 51200 = 1.0 unless engine_state is ENGINE_STATE_RUNNING or ENGINE_STATE_ENGINE_BRAKE)"),
    ("global_variables.csv", "1 while engine_state is 3 (at governor setpoint), 4 (engine retarder active), 5 (engine "
                             "overspeed) or 7 (setpoint underrun), else 0",
     "1 while engine_state is 3 (RUNNING), 4 (ENGINE_BRAKE), 5 (OVERSPEED) or 7 (REENTRY), else 0"),
    ("global_variables.csv", "used in the cranking / below-trigger cold start phases when",
     "used while engine_state is ENGINE_STATE_STOPPED / CRANKING / JUMP_START / REENTRY when"),
]
for name, old, new in TEXT:
    path = os.path.join(OUT, name)
    text = open(path, newline="").read()
    assert text.count(old) == 1, (name, old[:60], text.count(old))
    open(path, "w", newline="").write(text.replace(old, new))
print(f"{len(TEXT)} engine_state prose fixes")
