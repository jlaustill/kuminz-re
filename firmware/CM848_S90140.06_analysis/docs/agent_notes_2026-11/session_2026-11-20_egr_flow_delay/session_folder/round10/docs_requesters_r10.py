"""Round 10 closing (2): add the firmware requester of each SCI 0x13 test's output to the firmware/CLAUDE.md table
(the advisor's check: five outputs had only the DRB name). usage: docs_requesters_r10.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
p = os.path.join(repo, "firmware", "CLAUDE.md")
text = open(p).read()
ROWS = [
    ("    | Code | Test | Output |\n    |---|---|---|\n",
     "    | Code | Test | Output | Firmware requester |\n    |---|---|---|---|\n"),
    ("    | 13-09 | A/C clutch relay | 38 |\n",
     "    | 13-09 | A/C clutch relay | 38 | `cm848_controlAirConditioningClutchForBrTruck` / `...ForDrTruck` |\n"),
    ("    | 13-0F | torque converter clutch | 18 |\n",
     "    | 13-0F | torque converter clutch | 18 | `cm848_applyConverterLockupSchedule` |\n"),
    ("    | 13-16 | overdrive solenoid | 17 |\n",
     "    | 13-16 | overdrive solenoid | 17 | `cm848_processOverdriveSwitchAndShift` |\n"),
    ("    | 13-1A / 13-1B | cruise vent / vacuum | 19 / 20 |\n",
     "    | 13-1A / 13-1B | cruise vent / vacuum | 19 / 20 | `cm848_controlCruiseVacuumServo` |\n"),
    ("    | 13-28 / 13-29 | intake heaters | 43 / 44 |\n",
     "    | 13-28 / 13-29 | intake heaters | 43 / 44 | the intake air heater preheat / post-heat functions |\n"),
    ("    | 13-2C | cruise 12 volt feed | 21 |\n",
     "    | 13-2C | cruise 12 volt feed | 21 | `cm848_controlCruiseVacuumServo` |\n"),
    ("    | 13-33 | fuel transfer pump | 53 |\n",
     "    | 13-33 | fuel transfer pump | 53 | `protection_ambient_qualification` (misnamed): on at key-on, while cranking "
     "and running, off after a timeout |\n"),
    ("    | 13-43 | transmission relay | 16 |\n",
     "    | 13-43 | transmission relay | 16 | `cm848_updateTransmissionRelayRequest` |\n"),
    ("    | 13-49 | wait to start lamp | 4 |\n",
     "    | 13-49 | wait to start lamp | 4 | the intake air heater preheat (the lamp is on while preheating) |\n"),
    ("    | 13-5D | exhaust brake | 11 |\n",
     "    | 13-5D | exhaust brake | 11 | `cm848_driveEngineRetarderOutput` |\n"),
    ("    | 13-5E | fuel control | `fuel_control_actuator_test_active_flag` |\n",
     "    | 13-5E | fuel control | `fuel_control_actuator_test_active_flag` | read by "
     "`cm848_calculateFuelMeteringCommand` |\n"),
    ("    | 13-5F | PWM radiator fan | `cooling_fan_actuator_test_active_flag` |\n",
     "    | 13-5F | PWM radiator fan | `cooling_fan_actuator_test_active_flag` | read by "
     "`cm848_selectCoolingFanDutySource` |\n"),
]
for old, new in ROWS:
    assert text.count(old) == 1, old
    text = text.replace(old, new)
open(p, "w").write(text)
print(len(ROWS), "table rows updated")
