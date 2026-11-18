"""Apply the discrete line image typing to the CM848 CSVs (one-off edit script)."""
import sys

OUT = sys.argv[1]
GLOBALS = f"{OUT}/global_variables.csv"
STRUCTS = f"{OUT}/structure_definitions.csv"

IMAGES = {
    0x40c0e4: ("output_line_read_back",
               "Output line read-back image (20 bytes = lines 0-159 / byte N/8 bit N%8): "
               "cm848_refreshOutputPortsAndReadback reads each output port back into it before it "
               "rewrites the ports from output_line_state (MIOS port = lines 8-23 / SIU_SGPIODT1-2 = "
               "24-87 / MDASM pins = 120-143 / the previous supervisor output byte = 144-151 / the "
               "serial output driver = 152-159); bytes 0 and 11-14 have no port "
               "(were j1939_dm1_prev_b0..b10 / j1939_lamp_status_byte_a..c / j1939_lamp_status_prev)"),
    0x40c0f8: ("input_line_image",
               "Discrete input line image (20 bytes = lines 0-159 / byte N/8 bit N%8): "
               "cm848_refreshInputLineImage fills every port in one pass and cm848_readDiscreteInputLine "
               "one line (MIOS port = lines 8-23 / SIU_SGPIODT1-2 = 24-87 / MDASM pins = 120-128 / "
               "supervisor chip = 130-151 / serial output driver status = 152-159); bytes 0 and 11-14 "
               "have no source; cm848_scanAndDebounceSwitchInputs reads the switch lines from it "
               "(were j1939_dm1_prev_b11 / j1939_dm1_fault_spn_ext / j1939_dm1_tx_b2..b9 / "
               "io_pin_status_byte / j1939_protection_config_byte / j1939_dm1_parameter_byte / "
               "j1939_fault_occurrence_prev / j1939_periodic_timer_prev)"),
    0x40c10c: ("output_line_state",
               "Output line command shadow (20 bytes = lines 0-159 / byte N/8 bit N%8): "
               "cm848_applyLogicalOutputRequests writes request XOR polarity per line; "
               "mpc555_driveOutputLineHigh / Low keep it; cm848_refreshOutputPortsAndReadback copies it "
               "to the ports (lines 88-119 = TPU channels used as discrete outputs) "
               "(were output_lines_0_to_7_state..output_lines_152_to_159_state and the "
               "injector_control_t instance on lines 88-143)"),
}
REMOVE_RANGES = [(0x40c0e5, 0x40c0f7), (0x40c0f9, 0x40c10b), (0x40c10d, 0x40c11f)]

out_lines, removed = [], []
with open(GLOBALS) as f:
    for line in f:
        parts = line.split(",", 3)
        if parts[0].startswith("0x"):
            a = int(parts[0], 16)
            if any(lo <= a <= hi for lo, hi in REMOVE_RANGES):
                removed.append(parts[1]); continue
            if a in IMAGES:
                removed.append(parts[1])
                continue
            if a == 0x306100:   # MIOS parallel port I/O submodule
                line = "0x00306100,mios_mpiosm32,mios_mpiosm_t,MIOS1 16-bit parallel port I/O submodule (submodule 32 at 0x306000 + 8 x 32): data / data_direction (was mios1_ext_ctrl)\n"
            elif a == 0x306102 and parts[1] == "mios1_ext_ctrl_b":
                removed.append(parts[1]); continue
        out_lines.append(line)
# insert the three images in address order
final = []
inserted = set()
for line in out_lines:
    parts = line.split(",", 1)
    if parts[0].startswith("0x"):
        a = int(parts[0], 16)
        for img in sorted(IMAGES):
            if img not in inserted and a > img:
                name, comment = IMAGES[img]
                final.append(f"0x{img:08x},{name},discrete_line_image_t,{comment}\n")
                inserted.add(img)
    final.append(line)
assert inserted == set(IMAGES), inserted
open(GLOBALS, "w").writelines(final)
print("globals removed:", len(removed), removed)

# structures: drop injector_control_t, rename mios1_ext_ctrl_t, add the templates
template = ["# discrete_line_image_t: one byte per 8 discrete lines (line N = byte N/8 bit N%8); three instances:\n",
            "#   output_line_read_back 0x40c0e4 / input_line_image 0x40c0f8 / output_line_state 0x40c10c\n"]
for i in range(20):
    lo, hi = 8 * i, 8 * i + 7
    template.append(f"discrete_line_image_t,,lines_{lo}_to_{hi},byte,1,Lines {lo}-{hi} (bit = line - {lo}),,verified\n")
template += [
    "# mios_port_data_register_t: byte view of a copy of the MIOS parallel port data register (big-endian)\n",
    "mios_port_data_register_t,,byte_0,byte,1,Bits 15-8 (the byte at the lower address): input lines 16-23,,verified\n",
    "mios_port_data_register_t,,byte_1,byte,1,Bits 7-0: input lines 8-15,,verified\n",
]
s_out, dropped = [], 0
with open(STRUCTS) as f:
    lines = f.readlines()
for line in lines:
    if line.startswith("injector_control_t,"):
        dropped += 1; continue
    if line.startswith("mios1_ext_ctrl_t,0x00306100,ctrl_a,"):
        line = "mios_mpiosm_t,0x00306100,data,word,2,Port data register: pin n = bit n (whole-word read-modify-write by the output line drivers),,verified\n"
    elif line.startswith("mios1_ext_ctrl_t,0x00306100,ctrl_b,"):
        line = "mios_mpiosm_t,0x00306100,data_direction,word,2,Port data direction register: bit n set = pin n is an output (0x2000 at startup / 0x200 / 0x8200 before driving pins 9 and 15),,verified\n"
    s_out.append(line)
    if line.startswith("siu_gpio_data_register_t,,byte_3,"):
        s_out.extend(template)
open(STRUCTS, "w").writelines(s_out)
print("injector_control_t rows dropped:", dropped)
