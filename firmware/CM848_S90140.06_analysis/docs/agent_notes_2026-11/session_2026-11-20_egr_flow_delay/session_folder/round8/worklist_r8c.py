"""Round 8 stage C: the shift logic initializer (types follow in apply_r8c_types.py)."""
GLOBALS = []
FUNCTIONS = [
    ("0x000331cc", "cm848_initializeTransmissionShiftLogic",
     "Initializes the 48RE shift logic: transmission_vehicle_inertia = transmission_vehicle_inertia_default (e2m "
     "RE_Inertia_Default), the predicted post-shift acceleration 0, the anti-hunt and low range shift flags cleared, "
     "fourth_gear_tcc_lockup_boost_input = the intake manifold pressure, and every governor pressure / shift table "
     "lookup cache set to 2 (the first segment)"),
]
