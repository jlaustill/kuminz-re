"""Stage 5b, part 2: the last name and the prose left over from the old cold start phase reading of engine_state.
- 0x40a5ce fuel_cold_start_phase3_compensation_enable_flag is the condensation count enable: feature_enable_flags_cal
  bit 0x200 and engine_is_active_flag (cm848_updateCondensationProtection); both condensation counts follow their
  step only while it is 1.
- "cold start phase 3" in three condensation plates is engine_is_active_flag != 0.
- combustion_status_flags bits 0x01 / 0x02 / 0x80 named after the AECD flags and the engine state. Bit 0x02 is set
  while neither engine_is_starting_flag nor engine_is_active_flag is 1, so the dump's 0x402 only shows that it was
  taken with the engine stopped (engine_state 1). It does not explain why EGR is off on this truck.
Appends the rename to map_stage5b.csv.
usage: apply_stage5b_prose.py <CM848 output dir>"""
import os
import sys

OUT = sys.argv[1]
here = os.path.dirname(os.path.abspath(__file__))
ADDRESS, OLD, NEW = "0x0040a5ce", "fuel_cold_start_phase3_compensation_enable_flag", "condensation_count_enable_flag"
COMMENT = ("1 while feature_enable_flags_cal bit 0x200 is set and engine_is_active_flag is 1 "
           "(cm848_updateCondensationProtection); cm848_updateIntakeCondensationCount and "
           "cm848_updateEgrCoolerCondensationCount let their counts follow the step only while it is 1 (lhz x 2, sth) "
           "(was fuel_cold_start_phase3_compensation_enable_flag)")
TEXT = [  # (file, exact old text, new text, expected count)
    ("function_renames.csv", "and, in cold start phase 3 with the EGR valve not closed, adds a fifth of it",
     "and, while engine_is_active_flag is set and the EGR valve is not closed, adds a fifth of it", 2),
    ("function_renames.csv", "= feature_enable_flags_cal bit 0x200 and cold start phase 3;",
     "= feature_enable_flags_cal bit 0x200 and engine_is_active_flag;", 1),
    ("global_variables.csv", "/ the cold start bits / DAT_0040656a)", "/ the AECD and engine state bits / DAT_0040656a)", 1),
    ("global_variables.csv", "0x01 cold start phase 2.6 fuel mode (EGR off); 0x02 outside cold start phases 2.6 and 3 "
                             "(EGR off; why EGR is requested off on this truck);",
     "0x01 engine_start_warmup_protection_active_flag (EGR off); 0x02 the engine neither starting nor active "
     "(engine_is_starting_flag and engine_is_active_flag both 0: STOPPED before the crank, or SHUTDOWN) (EGR off; set "
     "in the dump only because the dump was taken with the engine stopped, engine_state 1);", 1),
    ("global_variables.csv", "0x80 cold start phase 3 count met or condensation protection active (EGR off);",
     "0x80 extended_idle_protection_active_flag or condensation_protection_active_flag (EGR off);", 1),
]

path = os.path.join(OUT, "global_variables.csv")
lines = open(path, newline="").read().split("\n")
i = next(k for k, line in enumerate(lines) if line.split(",", 1)[0] == ADDRESS)
address, name, typ, _ = lines[i].split(",", 3)
assert name == OLD and typ == "word", (name, typ)
lines[i] = ",".join([address, NEW, typ, COMMENT])
open(path, "w", newline="").write("\n".join(lines))

for name, old, new, count in TEXT:
    path = os.path.join(OUT, name)
    text = open(path, newline="").read()
    assert text.count(old) == count, (name, old[:50], text.count(old))
    open(path, "w", newline="").write(text.replace(old, new))

with open(os.path.join(here, "map_stage5b.csv"), "a") as f:
    f.write(f"{ADDRESS},{NEW},{OLD},global\n")
print(f"renamed {OLD} -> {NEW}; {len(TEXT)} prose fixes")
