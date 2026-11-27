"""Round 11 stage E (label-only): output 54's field, decided from the code after the review.
fuel_shutoff_request (stage D) blurred it with output 30 (e2m 1577 +3 0x40 FSO_Command, which
cm848_processProtectionFaultsAndTiming requests every pass). Every reader of output 54 pairs it with
supervisor_register_36_bit_1_low_held_flag == 0 - the output read-back debounce, the injector diagnostics, the fuel
metering feedback checks and the fault scan stand down while either is set - so it shuts off the output driver ASIC
(e2m ASIC_FS_Shutoff_Driver), the software path next to the supervisor's shutdown line. structure_definitions.csv is
quote-aware. usage: apply_r11e_field.py <repo> <map.csv>"""
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
p = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output", "structure_definitions.csv")
text = open(p).read()
OLD, NEW = "fuel_shutoff_request", "driver_asic_shutoff_request"
m = re.search(r'^logical_output_request_bits_48_to_55_t,,' + OLD + r',bitfield:1@6,0,"([^"]*)",,verified$', text, re.M)
assert m
c = ("output 54 (mask 0x40): e2m 1577 +6 ASIC_FS_Shutoff_Driver (FS is not expanded; not output 30 FSO_Command, which "
     "cm848_processProtectionFaultsAndTiming requests every pass). Shuts off the output driver ASIC: the fuel system "
     "fault reactions request it - fault reaction mask bit 3 (cm848_updateFuelPressureFaultReactionRequests), fuel "
     "pressure too high with fuel_pressure_too_high_logical_output_request_enable "
     "(cm848_applyFuelLimitsForFuelPressureFaults), fault 388 excess fuel demand (fuel_quantity_demand_monitor); "
     "fuel_quantity_demand_initialize clears it. While it or supervisor_register_36_bit_1_low_held_flag is set, the "
     "output read-back debounce, the injector and fuel metering feedback diagnostics and the fault scan stand down "
     "(was " + OLD + ", earlier injector_driver_asic_shutoff_request)")
assert '"' not in c
text = text[:m.start()] + f'logical_output_request_bits_48_to_55_t,,{NEW},bitfield:1@6,0,"{c}",,verified' + text[m.end():]
open(p, "w").write(text)
with open(map_path, "a") as f:
    f.write(f",{NEW},{OLD},field\n")
print("output 54 field renamed")
