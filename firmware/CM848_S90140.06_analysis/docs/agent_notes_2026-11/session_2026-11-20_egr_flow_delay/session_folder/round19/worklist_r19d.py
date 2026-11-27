"""Round 19 stage D (label-only, after the review): the siblings of stage A's main timing cranking map. Each is a
cranking table or word by its e2m record, placed by the ECU's parameter ID table (the fuel pressure table by its
output 803F +2); they were *_cold_start_*."""
GLOBALS = [
    ("0x00062de6", "injection_timing_pilot_offset_cranking_x_axis",
     "e2m 8078 Pilot_SOI_Cranking_Speed_Axis 'Speed axis for SOI Cranking Map'"),
    ("0x00062dfa", "injection_timing_pilot_offset_cranking_y_axis",
     "e2m 8079 Pilot_SOI_Cranking_Cool_Temp_Axis 'Cool Temp axis for SOI Cranking Map'"),
    ("0x00062e0e", "injection_timing_pilot_offset_cranking_grid",
     "e2m 807A Pilot_SOI_Cranking_SOI_Axis: the pilot timing offset while cranking (engine speed x coolant)"),
    ("0x00062c2c", "injection_quantity_pilot_cranking_x_axis",
     "e2m 8D76 Pilot_Quantity_Crank_Speed_Axis 'Speed axis for Pilot Quantity Crank[ing table]'"),
    ("0x00062c40", "injection_quantity_pilot_cranking_y_axis", "e2m 8D77 Pilot_Quantity_Crank_Temp_Axis"),
    ("0x00062c54", "injection_quantity_pilot_cranking_grid",
     "e2m 8D78 Pilot_Quantity_Crank_Axis: the pilot quantity table while cranking (output "
     "injection_quantity_pilot_cranking_correction)"),
    ("0x00061964", "injection_quantity_pilot_cranking_coolant_factor_axis",
     "e2m 8068 Pilot_Quantity_Corr_Crank_Temp_Axis 'Cool temp axis for [the pilot quantity crank correction factor]'"),
    ("0x00061970", "injection_quantity_pilot_cranking_coolant_factor_values",
     "e2m 8069 Pilot_Quantity_Corr_Crank_Factor_Axis: the pilot quantity crank correction factor by coolant temperature"),
    ("0x0040b95e", "injection_quantity_pilot_cranking_correction",
     "e2m 806A +26 Pilot_Quantity_Crank_Correction 'Output of Pilot Quantity Crank Table'"),
    ("0x00409e6c", "injection_quantity_pilot_cranking_logic_select",
     "e2m 805F +22 Pilot_Quantity_Crank_Logic_Select_N 'Crank pilot quantity adj. logic'"),
    ("0x0040b8b8", "fuel_pressure_setpoint_cranking_value",
     "e2m 803F +2 HPCR_Crank_Fuelpr_Setpoint 'Output of cranking fuel pressure setpoint table'"),
    ("0x00060044", "fuel_pressure_setpoint_cranking_x_axis",
     "The engine speed axis of the cranking fuel pressure setpoint table (its output is fuel_pressure_setpoint_cranking_value, "
     "e2m 803F +2)"),
    ("0x00060058", "fuel_pressure_setpoint_cranking_y_axis", "The y axis of the cranking fuel pressure setpoint table"),
    ("0x00060064", "fuel_pressure_setpoint_cranking_grid", "The cranking fuel pressure setpoint table"),
    ("0x003fd0ce", "fuel_pressure_setpoint_cranking_cached_axis_offsets",
     "Lookup cache (x / y segment offsets) of the cranking fuel pressure setpoint table"),
]
FUNCTIONS = []
