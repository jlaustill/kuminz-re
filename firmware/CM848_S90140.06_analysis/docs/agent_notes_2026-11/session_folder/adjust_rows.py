"""Second-pass adjustments after review: a few renames (comments kept, interim names replaced everywhere),
two plate rewrites, two comment notes; writes a mapping (address,name,old_label,kind) for the proof.
Usage: adjust_rows.py <repo> <mapping_out.csv>"""
import csv
import os
import re
import sys

repo, mapping = sys.argv[1:3]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
GLOBALS = {  # address: (interim name, new name, comment note to append)
    0x003fee3e: ("oil_change_monitor_soot_accumulator_cal", "oil_change_monitor_engine_power_accumulator_cal",
                 "Named for the table that feeds it (engine_power_accumulator_increment); 'soot' (the e2m OCM_Soot "
                 "slot) is only by elimination. TIME-SHARED: before the application runs, the boot ROM "
                 "(cm848_restoreDiagnosticHandler / cm848_enableDiagnosticTimer / cm848_processTimerInterrupt, "
                 "0x3ad8-0x3b48) uses byte 0 as its SCI diagnostic timeout counter."),
    0x00409522: ("fuel_pressure_governor_demand_idle_limit", "fuel_pressure_governor_demand_limit_at_governed_speed",
                 "Applies in governor mode 11, the governed-speed mode (probably idle; not proven)."),
    0x00409526: ("fuel_pressure_governor_demand_idle_minimum_coolant_temperature",
                 "fuel_pressure_governor_demand_check_minimum_coolant_temperature",
                 "The check runs in governor mode 11, the governed-speed mode (probably idle; not proven)."),
    0x0040b81c: ("injection_quantity_auxiliary_coolant_map_value", "injection_quantity_auxiliary_coolant_limit", ""),
    0x0040b82a: ("injection_quantity_auxiliary_boost_map_value", "injection_quantity_auxiliary_boost_limit", ""),
    0x0040b816: ("injection_quantity_auxiliary_unscaled", "injection_quantity_auxiliary_limit_unscaled", ""),
    0x0040b8a8: ("fuel_pressure_limp_home_active_flag", "fuel_pressure_limp_home_active_flag",
                 "Triggers (each enabled by a bit of engine_sync_enable_mask), decoded through ROM 0x5985a and "
                 "obd_dtc_code_table: fault 304 P0193 and 305 P0192 (rail pressure sensor high / low), 303 P0088 "
                 "(rail pressure too high), 333 P0251 (CP3 pump regulator), 264 / 265 (no DTC slot), and "
                 "fault_reaction_request_bits bits 0 / 1."),
}
FUNCTIONS = {
    0x000466a8: ("cm848_calculateAuxiliaryInjectionQuantity", "cm848_calculateAuxiliaryInjectionQuantityLimit",
                 ("Computes the auxiliary (third, after-main) injection quantity", "Computes the auxiliary (third, "
                  "after-main) injection quantity LIMIT (the cap of auxiliary_injection_quantity)")),
    0x0000ff04: ("cm848_calculateGovernorPidGains", "cm848_calculateGovernorCompensatorCoefficients",
                 ("Calculates the all-speed governor's integral and proportional gains (Q10, 1024 = 1.0)",
                  "Calculates the all-speed governor's two compensator coefficients (Q10, 1024 = 1.0; the speed "
                  "governor uses them as its integral / proportional pair - their form, a bilinear-transform pole "
                  "a and (a + 1024) / 2, could also be a filter's)")),
}
interim = {g[0]: g[1] for g in GLOBALS.values() if g[0] != g[1]}
interim.update({f[0]: f[1] for f in FUNCTIONS.values()})
pattern = re.compile(r"\b(" + "|".join(re.escape(o) for o in sorted(interim, key=len, reverse=True)) + r")\b")
rows = []
path = os.path.join(out, "global_variables.csv")
lines = open(path).read().split("\n")
hit = set()
for i, l in enumerate(lines):
    p = l.split(",", 3)
    if not p[0].startswith("0x"):
        continue
    a = int(p[0], 16)
    if a in GLOBALS:
        old, new, note = GLOBALS[a]
        assert p[1] == old, (hex(a), p[1])
        p[1] = new
        while len(p) < 4:
            p.append("")
        if note:
            p[3] = note + " " + p[3]
        hit.add(a)
        if old != new:
            rows.append((f"0x{a:08x}", new, old, "global"))
    if len(p) > 3:
        p[3] = pattern.sub(lambda m: interim[m.group(1)], p[3])
    lines[i] = ",".join(p)
assert hit == set(GLOBALS), set(GLOBALS) - hit
open(path, "w").write("\n".join(lines))
path = os.path.join(out, "function_renames.csv")
lines = open(path).read().split("\n")
hit = set()
for i, l in enumerate(lines):
    p = l.split(",", 2)
    if not p[0].startswith("0x"):
        continue
    a = int(p[0], 16)
    if a in FUNCTIONS:
        old, new, (before, after) = FUNCTIONS[a]
        assert p[1] == old and len(p) > 2 and p[2].startswith(before), (hex(a), p[1])
        p[1] = new
        p[2] = after + p[2][len(before):]
        hit.add(a)
        rows.append((f"0x{a:08x}", new, old, "function"))
    if len(p) > 2:
        p[2] = pattern.sub(lambda m: interim[m.group(1)], p[2])
    lines[i] = ",".join(p)
assert hit == set(FUNCTIONS)
open(path, "w").write("\n".join(lines))
for rel in ("firmware/CLAUDE.md", "work/tasks/042-table-campaign-rename-leads.md", "work/todo.md"):
    p = os.path.join(repo, rel)
    t = open(p).read()
    t2, n = pattern.subn(lambda m: interim[m.group(1)], t)
    open(p, "w").write(t2)
    print(f"{rel}: {n} interim names replaced")
with open(mapping, "w", newline="") as f:
    w = csv.writer(f)
    w.writerow(["address", "name", "old_label", "kind"])
    for r in rows:
        w.writerow(r)
print(f"adjusted {len(rows)} names, {len(GLOBALS)} global rows touched")
