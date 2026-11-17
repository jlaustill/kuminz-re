# Addendum to brief.md (main wave): facts from the pilot, grammar reminders, budget

## Facts the pilot established (use them; do not re-derive)
Scales (counts -> units):
- engine speed 0.125 rpm; fuel quantity (`fuel_demand_computed` and kin) 0.0679 mm3 per stroke (147 = 10 mm3);
  rail pressure (`fuel_pressure_feedback_filtered`) 0.0488 MPa (1025 = 50 MPa); coolant / intake manifold
  temperature 1/64 deg F (-2560 = -40 F); boost 0.0159 inHg (629 = 10 inHg); injection timing 0.1171875 deg;
  governor demand 4095 = 100 %; multiplier factors are Q12 (4096 = 1.0).

Known misnomers (the code is the truth; do not copy these names into a base):
- `cm848_auxiliary_boundary_condition_eval` computes the timing of the auxiliary (third, post-main) injection;
  its tables are named `injection_timing_auxiliary_*`.
- `engine_camTiming_positionCorrection_calc` is a fuel-metering feedback monitor (rail pressure / fuel quantity
  inputs), not cam timing; its `cam_timing_*` variables are misnamed.
- `torque_limit_fault_snapshot` holds the main injection timing; `engine_timing_reference` holds a fuel quantity;
  `boost_map_index_current` / `_target` are blend table numbers 1..4.

## Grammar reminders
- A table that converts ADC counts for a sensor channel: base `<sensor>_linearization` (or
  `sensor_channel<N>_linearization` when the sensor is not certain).
- Families (several tables selected by an index or mode): one base pattern, the index number the only
  difference (`..._map_1` .. `..._map_4`).
- Keep the composed name (base + `_x_axis` etc.) at most 56 characters.

## Budget
About 50 tool calls in total. Spend them on the evidence rule for your own lookups. Record a misnamed neighbour
in one line of `naming_concern` and move on: do not investigate symbols outside your lookups.
