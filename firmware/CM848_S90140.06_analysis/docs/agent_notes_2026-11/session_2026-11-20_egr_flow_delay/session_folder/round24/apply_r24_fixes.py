"""Round 24, after the final review: comment and doc fixes plus the missing leads. Idempotent.
usage: apply_r24_fixes.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
OUT = "firmware/CM848_S90140.06_analysis/output/"


def edit(rel, old, new, count=1):
    p = os.path.join(repo, rel)
    t = open(p).read()
    if new in t and old not in t:
        return
    assert t.count(old) == count, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


G = OUT + "global_variables.csv"
edit(G, "(pedal - it) x 400 / DAT_0005c292,", "(pedal - it) x 400 / accelerator_pedal_throttle_range,")
edit(G, "intake_air_heater_performance_test_loaded_sample_delay_ticks / 00064424 / 00064428 (25 / 30 / 2)",
     "intake_air_heater_performance_test_loaded_sample_delay_ticks / intake_air_heater_performance_test_ring_sample_"
     "delay_ticks / intake_air_heater_performance_test_recovery_sample_delay_ticks (25 / 30 / 2)")
edit(G, "the e2m names every bit). The monitors", "the labelled e2m names 337 of the 800 bits). The monitors")
edit("firmware/CLAUDE.md",
     "The real fuel-demand math (`cm848_fuelDemand*` at 0xdcdc-0x17980) is unrelated and keeps its names.",
     "The real fuel-demand math (`cm848_fuelDemand*` at 0xdcdc-0x17980) is unrelated; its throttle part at "
     "0x1702c-0x17af4 is e2m 1047's commanded throttle (`cm848_selectCommandedThrottle` and its family, PR #53 round 24).")
edit("firmware/CLAUDE.md",
     "`j1939_can_ring_buf._pad16` byte 0 is read as the CAN transmit queue's full flag |",
     "`j1939_can_ring_buf._pad16` byte 0 is the CAN transmit ring's full flag (`mpc555_canTransmitQueuePush` sets it when "
     "its write pointer reaches the read pointer and returns 4 while it is set; `mpc555_manageCan1TransmitBuffer` clears "
     "it), byte 1 the receive ring's (`mpc555_processCanReceiveBuffer` / `mpc555_dispatchCanMessageHandlers`) |")
edit(OUT + "thermal_protection_trigger.md", "## `system_status_flags_t_003fe974` safety-bit map",
     "## `fault_detected_cal` (was `system_status_flags_t_003fe974`) safety-bit map")
T46 = "work/tasks/046-cm848-egr-flow-estimate.md"
edit(T46, "  - `j1939_can_ring_buf._pad16` byte 0 is the CAN transmit queue's full flag (`mpc555_canTransmitQueuePush` returns 4\n"
          "    on it).\n",
     "  - `j1939_can_ring_buf._pad16` byte 0 is the CAN transmit ring's full flag: `mpc555_canTransmitQueuePush` sets it\n"
     "    when its write pointer reaches the read pointer and returns 4 while it is set. Byte 1 is the receive ring's.\n"
     "    Both bytes still render as pieces.\n"
     "  - The `PROTECTION_OVERRIDE` enum (enums.csv, 0x7e / 0x7f named after their ASCII glyphs) is applied nowhere.\n"
     "    `transmission_selected_gear` holds the J1939 SPN 524 coding (0x7E 1st / 0x7F 2nd ...). Since byte enums\n"
     "    render, a `TRANSMISSION_SELECTED_GEAR` enum on it, `transmission_selected_gear_previous` and\n"
     "    `j1939_powertrain_control_state.etc2_transmission_selected_gear` would replace the junk one.\n"
     "  - Four e2m 1966 words have no row: 0x40bdc8-0x40bdce, the fuel and rail pressure sensor values and defaults.\n"
     "    Nothing ties the 'Fuel_Press' value to the fuel delivery pressure channel yet.\n"
     "  - Three dotted alias families keep a stale instance label: `adc_trigger_t_003024f4.*`,\n"
     "    `j1939_cruise_state_t_003fee00.*` and `protection_b_state_t_003feebc.*`. Their base addresses carry flat\n"
     "    names now. Check whether those struct types still exist.\n"
     "  - Stage A read only its REVIEW set. Not read: the 209 hits it kept as history (classified by the words around\n"
     "    them) and 29 left for review, which are dotted names, own-label openings, rename arrows and '#' lines.\n"
     "    `classify_labels.py` reproduces the sets.\n"
     "  - Still named with their Ghidra labels: `diag_buf_a_ctrl_t_0030305a` / `diag_buf_b_ctrl_t_0030304b` (the\n"
     "    kernel response messages), `diag_clear_flags_t_003fedfc`, `scheduler_task_stat_t_0040be6a` and\n"
     "    `toucan_a_mb1_t_00307090` (the TouCAN map). The two `BYTE_` holds stay on purpose.\n"
     "  - Claims checked by the raw lis scan, in permissive mode:\n"
     "    - the reflash transfer state (33 kernel + 9 boot accesses) and the boot SCI session (12 + 28) have no\n"
     "      application access;\n"
     "    - the fault arrays have 718 application accesses and none from boot or kernel code;\n"
     "    - only one instruction forms 0x3fa6fc.\n")
print("fixes applied")
