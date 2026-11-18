"""Update work/todo.md items 035 / 036 / 039 / 040 and add 041 for the typing-arrays branch."""
import re
import sys

path = sys.argv[1]
text = open(path).read()

def replace_once(old, new):
    global text
    assert text.count(old) == 1, (old[:60], text.count(old))
    text = text.replace(old, new)

replace_once(
    "review hpcr_injectorPulseWidthCalc (0x533e0, a discrete-pin snapshot into j1939_dm1_* globals). Also: fold the per-channel MIOS struct types (mios_mdasm12_t / 15_t / 27_t, mios_mpwmsm1-3_t / 16-19_t, the byte-typed MDASM13 / 14 bases) into mios_mdasm_t / mios_mpwmsm_t markers, then type the eight mpc555_mios* driver pointer parameters as those structs - today the drivers reach the registers through raw offsets (+ 6 / [1] / [3]), which caps six of them at Readability Medium",
    "DONE (branch cm848/typing-arrays): hpcr_injectorPulseWidthCalc (0x533e0) is the discrete input snapshot cm848_refreshInputLineImage; the per-channel MIOS struct types are folded into mios_mdasm_t / mios_mpwmsm_t instances named mios_mdasmN / mios_mpwmsmN (AR + BR = one AR_BR dword), MDASM13 / 14 are instances, and the eight mpc555_mios* drivers take those struct pointers (->SCRD / ->PULR / ->SCR instead of + 6 / [1] / [3])")

replace_once(
    "STILL OPEN: the axis / data globals passed to the lookups are scalars, so most calls cast them with (word *) - declaring them as word arrays (first word = byte length) would size the tables and drop the casts; the sensorChannelTypeB_* functions still take table_interp_args_t *; in cm848_calculateFuelMeteringCommand",
    "DONE (branch cm848/typing-arrays): every lookup table is a word[N] row in global_variables.csv - 919 tables (axes = 1 + length word / 2, monotonic; 1-D data = one value per axis point after its own length word; 2-D grids nx x ny, no header), 560 of them unnamed type-only rows rendering WORD_ARRAY_<address>; the lookup cache words are word / word[2]; sensorChannelTypeB_* and the Type A sensorChannelConfigInit / updateSensorChannelWithConfig take (cached_axis_offset, x_axis, y_data, flags) - the table_interp_args_t struct is gone; (word *)& lines 966 -> 74. STILL OPEN: in cm848_calculateFuelMeteringCommand")
text = re.sub(r"^039 \[ \]", "039 [>]", text, count=1, flags=re.M)

old_040 = re.search(r"^040 \[>\] .*$", text, re.M).group(0)
new_040 = ("040 [X] [firmware] CM848D typing pass — DONE: PR #49 (siu_gpio_data_register_t on SIU_SGPIODT1 / SIU_SGPIODT2 and their "
           "gpio_register_copy stack copies) and branch cm848/typing-arrays: the three discrete line images are discrete_line_image_t "
           "instances (output_line_read_back 0x40c0e4 / input_line_image 0x40c0f8 / output_line_state 0x40c10c - line N = byte N/8 bit N%8; "
           "they replace 31 misnamed j1939_dm1_* / j1939_lamp_status_* / io_pin_status_byte bytes, the output_lines_N_to_M_state names and an "
           "injector_control_t instance), the bulk input snapshot is cm848_refreshInputLineImage, the MIOS port (mios_mpiosm32.data / "
           ".data_direction, was mios1_ext_ctrl) stack copies are mios_port_data_register_t, and the MIOS drivers are typed (see 035). "
           "Follow-ups in 041")
replace_once(old_040, new_040)

old_036 = re.search(r"^036 \[ \] .*$", text, re.M).group(0)
replace_once(old_036, old_036 + " (PARTIAL 2026-11-15, branch cm848/typing-arrays: ImportAnalysis now applies T[N] types through "
             "ScriptUtils.parseArrayType - they used to be dropped silently - and lists every type it cannot map with a WARNING; "
             "the four mappers are still separate copies)")

line_041 = ("041 [ ] [firmware] CM848D follow-ups from the typing-arrays branch: (1) name the 560 unnamed lookup tables (they render "
            "WORD_ARRAY_<address>; each row's comment gives role / size / readers - a naming campaign, and the protection_fuel_limit_* "
            "tables read by the converter lockup and governor pressure code still carry wrong-domain names); (2) the Type A sensor channel "
            "prototype parameters 6-12 (8 / 9 receive fault-bit numbers, 10-12 RAM pointers truncated by a ushort type) and the 74 "
            "remaining (word *)& casts (sensor channel state / raw / fault pointers, EEPROM buffers); (3) BENCH: MIOS port lines 8-23 - "
            "mpc555_driveOutputLineHigh / Low set bit (line mod 16) while cm848_refreshOutputPortsAndReadback and the input image put "
            "lines 8-15 in bits 7-0 (the bytes swapped) - find which matches the harness")
lines = text.split("\n")
idx = next(i for i, l in enumerate(lines) if l.startswith("040 "))
lines.insert(idx + 1, line_041)
open(path, "w").write("\n".join(lines))
print("todo updated")
