"""Round 94 stage C addendum (CM550): the two cm550_tableLookup2D argument records the removed can_buffer_setup_t
instance had covered (D1's judge: '0x801a94 and 0x801aaa are 2D lookup records'), typed and named from the Calterm
tables their pointers point at in the RAM dump, plus those tables. Evidence:
- 0x801a94 = x_axis_offset 2 / x_axis_pointer 0x808346 / y_axis_offset 2 / y_axis_pointer 0x808372 /
  z_values_pointer 0x80837c / flag 0: e2m 140E MTTQMPXA (rpm) / 1447 MTTQMPYA (alpha) / 1460 MTTQMPZA (ft-lb), the
  maximum torque map (CM848: maximum_torque_map_x_axis / _y_axis / _grid); filled by cm550_FUN_00026a2e (movea.l
  #0x801a94,a0 at 0x26a30), looked up by cm550_FUN_000269f2 (movea.l #0x801a94,a3 at 0x269fe);
- 0x801aaa = 2 / 0x80793a / 2 / 0x807944 / 0x80794e / 0: e2m 818F BSTABSXA (boost) / 8190 BSTAESYA (engine speed) /
  8191 BSTATBZA (injection_timing_misfire_limit_grid); filled by cm550_fuelDemandTablePointersInit (0x26a80), looked
  up by cm550_rpmLoadParameterLookup (0x26abc);
- the axis sizes are 1 + byte count / 2 words (42 -> word[22], 8 -> word[5]); the grids nx x ny words with no header.
The rows inside the records and the speed axis are removed (none of them has a reference of its own: they render
only as the record's fields). Idempotent; keeps line endings. usage: apply_r94c_lookups.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
R = "PR #53 round 94"
path = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/global_variables.csv")
text = open(path, newline="").read()
E = "\r\n" if "\r\n" in text else "\n"
lines = text.split(E)
REMOVE = {0x801a95, 0x801a96, 0x801a97, 0x801a98, 0x801a99, 0x801a9a, 0x801a9b, 0x801a9c, 0x801a9e, 0x801aa2, 0x801aa4,
          0x801aa8, 0x801aac, 0x801aad, 0x801aae, 0x801aaf, 0x801ab0, 0x801ab1, 0x801ab2, 0x801ab4, 0x801ab6, 0x801aba,
          0x801abc, 0x807946, 0x807948, 0x80794a, 0x80794c}
ROWS = {
    0x801a94: ("maximum_torque_map_lookup", "table_lookup_2d_arguments_t",
               "The cm550_tableLookup2D argument record of the maximum torque map: e2m 1460 MTTQMPZA 'TABLE WITH MAX TORQUE CORRESP. "
               "TO MTTQMPXA VALUES' (ft-lb) over engine speed (140E MTTQMPXA) and alpha (1447 MTTQMPYA); the RAM dump holds x_axis_pointer "
               "0x808346 / y_axis_pointer 0x808372 / z_values_pointer 0x80837c. cm550_FUN_00026a2e fills it and cm550_FUN_000269f2 looks "
               "it up. The can_buffer_setup_t instance at 0x801a8a had covered it; the rows inside are removed (were 0x801a94 "
               "can_buffer_setup1_data / 0x801a95-0x801a98 can_buffer_1_reserved_0-3 / 0x801a99-0x801a9b diag_can_response_data_0-2 / "
               "0x801a9c can_buffer_setup1_size.data[6] / 0x801a9e ambient_conditions_msg_header / 0x801aa2 ambient_conditions_msg_length / "
               f"0x801aa4 ambient_conditions_data_ptr / 0x801aa8 ambient_conditions_unused_ptr; {R})"),
    0x801aaa: ("injection_timing_misfire_limit_lookup", "table_lookup_2d_arguments_t",
               "The cm550_tableLookup2D argument record of the misfire timing limit: e2m 8191 BSTATBZA 'TABLE FOR DETERMINING MINIMUM "
               "ADVANCE FOR MISFIRE' (injection_timing_misfire_limit_grid) over boost pressure (818F BSTABSXA) and engine speed (8190 "
               "BSTAESYA); the RAM dump holds x_axis_pointer 0x80793a / y_axis_pointer 0x807944 / z_values_pointer 0x80794e. "
               "cm550_fuelDemandTablePointersInit fills it and cm550_rpmLoadParameterLookup looks it up. The rows inside are removed "
               "(were 0x801aac ambient_conditions_data_start / 0x801aad ambient_barometric_pressure / 0x801aae ambient_cab_interior_temp / "
               "0x801aaf ambient_air_temp / 0x801ab0 engine_air_inlet_temp / 0x801ab1 road_surface_temp / 0x801ab2 ambient_conditions_reserved / "
               "0x801ab4 ambient_conditions_buffer_end / 0x801ab6 j1939_pgn_65265_header / 0x801aba j1939_pgn_65265_size / 0x801abc "
               f"j1939_pgn_65265_data_ptr; {R})"),
    0x808346: ("maximum_torque_map_x_axis", "word[22]",
               "e2m 140E +0 MTTQMPXA 'TABLE WITH RPM BREAKPOINTS FOR MTTQMPZA INTERPOLATION' (rpm): the byte count 42 then 21 engine speeds "
               "4800-36000 (600-4500 rpm at 1/8 rpm) in the dump; the x axis of maximum_torque_map_lookup. CM848's maximum_torque_map_x_axis "
               f"({R})"),
    0x808372: ("maximum_torque_map_y_axis", "word[5]",
               "e2m 1447 +0 MTTQMPYA 'TABLE WITH ALPHA BREAKPOINTS FOR MTTQMPZA INTERPOLATION' (0-1): the byte count 8 then 0 / 4915 / "
               "11469 / 16384 (alpha at 1/16384) in the dump; the y axis of maximum_torque_map_lookup. CM848's maximum_torque_map_y_axis "
               f"has 5 points ({R})"),
    0x80837c: ("maximum_torque_map_grid", "word[84]",
               "e2m 1460 +0 MTTQMPZA 'TABLE WITH MAX TORQUE CORRESP. TO MTTQMPXA VALUES' (ft-lb): 21 x 4 values with no header; the z values "
               f"of maximum_torque_map_lookup. CM848's maximum_torque_map_grid is 21 x 5 ({R})"),
    0x80793a: ("injection_timing_misfire_limit_x_axis", "word[5]",
               "e2m 818F +0 BSTABSXA 'BOOST PRESS AXIS FOR MISFIRE LIMIT TABLE' (inHg): the byte count 8 then 377 / 754 / 1572 / 1635 in "
               f"the dump; the x axis of injection_timing_misfire_limit_lookup ({R})"),
    0x807944: ("injection_timing_misfire_limit_y_axis", "word[5]",
               "e2m 8190 +0 BSTAESYA 'SPEED AXIS FOR MISFIRE LIMIT TABLE' (rpm): the byte count 8 then 6800 / 10400 / 16000 / 24000 "
               "(850-3000 rpm at 1/8 rpm) in the dump; the y axis of injection_timing_misfire_limit_lookup. The rows inside are removed "
               "(were 0x807946 fault_persistence_threshold / 0x807948 accel_throttle_fault_delay_threshold / 0x80794a "
               "accel_throttle_fault_count_threshold / 0x80794c accel_throttle_fault_upper_threshold; no reference) (was "
               f"insite_fuel_timing_display; {R})"),
}
out, seen, removed, map_rows = [], set(), [], []
for line in lines:
    p = line.split(",", 3)
    a = int(p[0], 16) if p[0].startswith("0x") else None
    if a in REMOVE:
        removed.append(f"0x{a:x} {p[1]}")
        continue
    if a in ROWS:
        name, typ, comment = ROWS[a]
        if p[1] and p[1] != name:
            map_rows.append((a, name, p[1]))
        out.append(f"0x{a:08x},{name},{typ},{comment}")
        seen.add(a)
        continue
    out.append(line)
for a in sorted(set(ROWS) - seen):        # insert the rows that had none, in address order
    name, typ, comment = ROWS[a]
    idx = next(i for i, l in enumerate(out) if l.startswith("0x") and int(l.split(",")[0], 16) > a)
    out.insert(idx, f"0x{a:08x},{name},{typ},{comment}")
open(path, "w", newline="").write(E.join(out))
print(f"rows written: {len(ROWS)} ({len(seen)} replaced, {len(ROWS) - len(seen)} inserted); removed {len(removed)}: {removed}")
print("renamed:", [(hex(a), o, n) for a, n, o in map_rows])
