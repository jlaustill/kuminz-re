"""Round 11 stage D (label-only): output 54's field. Stage B named it injector_driver_asic_shutoff_request from its
readers (the injector and fuel pressure diagnostics). Its requesters (output_requesters.py 0x36) are the fuel
pressure fault reactions - cm848_updateFuelPressureFaultReactionRequests, cm848_applyFuelLimitsForFuelPressureFaults
and fuel_quantity_demand_monitor (fuel_quantity_demand_initialize clears it) - so it is a fuel shutoff request (e2m
1577 +6 0x40 ASIC_FS_Shutoff_Driver; FS is not expanded in the e2m). structure_definitions.csv is quote-aware.
usage: apply_r11d_field.py <repo> <map.csv>"""
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
p = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output", "structure_definitions.csv")
text = open(p).read()
OLD, NEW = "injector_driver_asic_shutoff_request", "fuel_shutoff_request"
m = re.search(r'^logical_output_request_bits_48_to_55_t,,' + OLD + r',bitfield:1@6,0,"([^"]*)",,verified$', text, re.M)
assert m
c = ("output 54 (mask 0x40): e2m 1577 +6 ASIC_FS_Shutoff_Driver. The fuel pressure fault reactions request it "
     "(cm848_updateFuelPressureFaultReactionRequests, cm848_applyFuelLimitsForFuelPressureFaults, "
     "fuel_quantity_demand_monitor; fuel_quantity_demand_initialize clears it), and the injector and fuel pressure "
     "diagnostics read it (cm848_evaluateInjectorDiagnostics, "
     "cm848_updateFuelPressureDiagnosticCountersAndCheckFeedbackCircuit) (was " + OLD + ")")
new_row = f'logical_output_request_bits_48_to_55_t,,{NEW},bitfield:1@6,0,"{c}",,verified'
text = text[:m.start()] + new_row + text[m.end():]
open(p, "w").write(text)
with open(map_path, "a") as f:
    f.write("address,name,old_label,kind\n" if os.path.getsize(map_path) == 0 else "")
    f.write(f",{NEW},{OLD},field\n")
print("output 54 field renamed")
