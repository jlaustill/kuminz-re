"""Round 28 stage A: the five stale name-only rows inside boot_can_ring_state (old QADC guesses; they render nowhere)
become dotted documentation rows of the struct's fields. Idempotent.
usage: dotted_rows_r28a.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
ROWS = {
    "0x003024ca,qadc_a_ccw_2,,": "0x003024ca,boot_can_ring_state.transmit_read_pointer,,",
    "0x003024ce,qadc_a_ccw_4,,": "0x003024ce,boot_can_ring_state.receive_write_pointer,,",
    "0x003024d2,qadc_a_ccw_6,,": "0x003024d2,boot_can_ring_state.receive_read_pointer,,",
    "0x003024d6,qadc_a_queue1_wrap_flag,,": "0x003024d6,boot_can_ring_state.transmit_ring_full_flag,,",
    "0x003024d7,qadc_a_queue2_wrap_flag,,": "0x003024d7,boot_can_ring_state.receive_ring_full_flag,,",
}
lines = open(p).read().split("\n")
n = 0
for i, line in enumerate(lines):
    if line in ROWS:
        lines[i] = ROWS[line]
        n += 1
open(p, "w").write("\n".join(lines))
print(f"{n} rows")
