"""Rename the input snapshot function, refresh stale plate comments, add the port-copy locals."""
import sys

OUT = sys.argv[1]

def edit(path, replacements, appends=()):
    text = open(path).read()
    for old, new in replacements:
        assert text.count(old) == 1, (path, old, text.count(old))
        text = text.replace(old, new)
    if appends:
        if not text.endswith("\n"):
            text += "\n"
        text += "".join(a + "\n" for a in appends)
    open(path, "w").write(text)

text_edits = [
    ("0x000533e0,hpcr_injectorPulseWidthCalc\n",
     "0x000533e0,cm848_refreshInputLineImage,Snapshots every discrete input port into input_line_image in one pass: "
     "the MIOS port data (lines 8-23) / SIU_SGPIODT1-2 (24-87) / the MDASM11-15 and 27-30 pin bits (120-128) / "
     "the supervisor chip lines 130-151 / the serial output driver status byte (152-159); run by "
     "hpcr_periodicTaskSet_fuelFinal and hpcr_initProtectionAndOutputCycle - cm848_readDiscreteInputLine "
     "refreshes a single line. Not injector timing (was hpcr_injectorPulseWidthCalc)\n"),
    ("(read by protection_j1939_control_logic / hpcr_injectorPulseWidthCalc)",
     "(read by protection_j1939_control_logic / cm848_refreshInputLineImage)"),
    ("presets output_lines_152_to_159_state to 0xff", "presets output_line_state.lines_152_to_159 to 0xff"),
    ("into the output_lines_*_state shadow at output_lines_0_to_7_state[line>>3]",
     "into the output_line_state shadow (byte line>>3 / bit line%8)"),
    ("read their line from the input-line image at 0x40c0f8 XOR", "read their line from input_line_image XOR"),
    ("into the input-line image at 0x40c0f8 + N/8 and returns", "into input_line_image (byte N/8) and returns"),
    ("snapshots every output port (j1939_dm1_prev_b0..b10 = previous port states) / reads back MIOS PWM + DASM pin "
     "states into j1939_lamp_status_byte_a..c / forces the DASM outputs from injector_control_t.output_ch0 /",
     "reads every output port back into output_line_read_back (MIOS PWM + DASM pin states into its lines 120-143) / "
     "forces the DASM outputs from output_line_state.lines_120_to_127 /"),
    ("the serial output driver (lines 152-159) from their output_lines_*_state shadows.",
     "the serial output driver (lines 152-159) from output_line_state. Its MIOS port rebuild puts lines 8-15 in "
     "bits 7-0 and lines 16-23 in bits 15-8 - mpc555_driveOutputLineHigh / Low set bit (line mod 16) instead "
     "(the bytes swapped) until the next refresh."),
]
edit(f"{OUT}/function_renames.csv", text_edits)

edit(f"{OUT}/local_variables.csv", [
    ("0x000533e0,hpcr_injectorPulseWidthCalc,local_4,gpio_register_copy,siu_gpio_data_register_t,Stack copy of SIU_SGPIODT1 then SIU_SGPIODT2 - its four bytes are copied out to the j1939_dm1_tx_b2..b9 snapshot bytes",
     "0x000533e0,cm848_refreshInputLineImage,local_4,gpio_register_copy,siu_gpio_data_register_t,Stack copy of SIU_SGPIODT1 then SIU_SGPIODT2 - its four bytes are copied to input_line_image.lines_24_to_31 .. lines_80_to_87"),
], appends=[
    "0x000533e0,cm848_refreshInputLineImage,local_8,mios_port_copy,mios_port_data_register_t,Stack copy of mios_mpiosm32.data - byte_1 (bits 7-0) = input lines 8-15 / byte_0 (bits 15-8) = lines 16-23",
    "0x0004f2ec,cm848_readDiscreteInputLine,local_8,input_port_copy,mios_port_data_register_t,Stack halfword the MIOS port data (lines 8-23) is copied through - its byte_1 also carries the supervisor lines 144-151 byte on the shared store tail",
    "0x000529b8,cm848_refreshOutputPortsAndReadback,local_30,mios_port_copy,mios_port_data_register_t,Stack copy of mios_mpiosm32.data - read back into output_line_read_back then rebuilt from output_line_state (byte_1 = lines 8-15 / byte_0 = lines 16-23)",
])
print("ok")
