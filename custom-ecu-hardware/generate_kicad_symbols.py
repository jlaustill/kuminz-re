#!/usr/bin/env python3
"""Generate KiCad symbol library files for S32K358 and FS26 from datasheet pin data."""

import re

def kicad_sym_header(lib_name):
    return f"""(kicad_symbol_lib
  (version 20231120)
  (generator "custom_generator")
  (generator_version "1.0")
"""

def kicad_sym_footer():
    return ")\n"

def pin_entry(name, number, x, y, length=200, direction="R", pin_type="bidirectional"):
    """Generate a single KiCad pin entry.
    direction: R=right, L=left, U=up, D=down (direction the pin points)
    pin_type: input, output, bidirectional, passive, power_in, power_out, unspecified
    """
    angles = {"R": 0, "L": 180, "U": 90, "D": 270}
    angle = angles[direction]
    return f"""      (pin {pin_type} line
        (at {x} {y} {angle})
        (length {length})
        (name "{name}"
          (effects (font (size 1.016 1.016)))
        )
        (number "{number}"
          (effects (font (size 1.016 1.016)))
        )
      )
"""


def generate_s32k358():
    """Generate S32K358 HDQFP172-EP symbol with multi-unit layout."""

    # Pin map from BSDL file: signal_name -> (pin_number, direction)
    # direction from BSDL: inout, in, out, linkage
    gpio_pins = {
        # Port A
        "PTA0": (137, "bidir"), "PTA1": (135, "bidir"), "PTA2": (124, "bidir"),
        "PTA3": (123, "bidir"), "PTA4": (170, "input"), "PTA5": (167, "linkage"),
        "PTA6": (102, "bidir"), "PTA7": (100, "bidir"), "PTA8": (172, "bidir"),
        "PTA9": (171, "bidir"), "PTA10": (161, "output"), "PTA11": (160, "bidir"),
        "PTA12": (159, "bidir"), "PTA13": (155, "bidir"), "PTA14": (152, "bidir"),
        "PTA15": (145, "bidir"), "PTA16": (143, "bidir"), "PTA17": (109, "bidir"),
        "PTA18": (1, "bidir"), "PTA19": (2, "bidir"), "PTA20": (3, "bidir"),
        "PTA21": (6, "bidir"), "PTA24": (14, "input"), "PTA25": (15, "input"),
        "PTA28": (30, "bidir"), "PTA29": (32, "bidir"), "PTA30": (33, "bidir"),
        "PTA31": (39, "bidir"),
        # Port B
        "PTB0": (95, "bidir"), "PTB1": (94, "bidir"), "PTB3": (74, "bidir"),
        "PTB4": (48, "bidir"), "PTB5": (47, "bidir"), "PTB8": (133, "bidir"),
        "PTB9": (130, "bidir"), "PTB10": (129, "bidir"), "PTB11": (126, "bidir"),
        "PTB12": (117, "bidir"), "PTB13": (116, "bidir"), "PTB14": (114, "bidir"),
        "PTB15": (113, "bidir"), "PTB16": (112, "bidir"), "PTB17": (110, "bidir"),
        "PTB18": (42, "bidir"), "PTB19": (43, "bidir"), "PTB20": (44, "bidir"),
        "PTB21": (45, "bidir"), "PTB22": (67, "bidir"), "PTB23": (69, "bidir"),
        "PTB24": (70, "bidir"), "PTB25": (72, "bidir"), "PTB26": (73, "bidir"),
        "PTB27": (75, "bidir"), "PTB28": (76, "bidir"), "PTB29": (80, "bidir"),
        # Port C
        "PTC0": (62, "bidir"), "PTC1": (61, "bidir"), "PTC2": (50, "bidir"),
        "PTC3": (49, "bidir"), "PTC4": (166, "input"), "PTC5": (165, "input"),
        "PTC6": (141, "bidir"), "PTC7": (140, "bidir"), "PTC8": (98, "bidir"),
        "PTC9": (97, "bidir"), "PTC10": (92, "bidir"), "PTC11": (90, "bidir"),
        "PTC12": (83, "bidir"), "PTC13": (81, "bidir"), "PTC14": (71, "bidir"),
        "PTC15": (68, "bidir"), "PTC16": (66, "bidir"), "PTC17": (65, "bidir"),
        "PTC18": (82, "bidir"), "PTC19": (84, "bidir"), "PTC20": (85, "bidir"),
        "PTC21": (86, "bidir"), "PTC23": (87, "bidir"), "PTC24": (88, "bidir"),
        "PTC25": (89, "bidir"), "PTC26": (91, "bidir"), "PTC27": (93, "bidir"),
        "PTC28": (96, "bidir"), "PTC29": (99, "bidir"), "PTC30": (101, "bidir"),
        "PTC31": (103, "bidir"),
        # Port D
        "PTD0": (8, "bidir"), "PTD1": (7, "bidir"), "PTD2": (121, "bidir"),
        "PTD3": (120, "bidir"), "PTD4": (119, "bidir"), "PTD5": (53, "bidir"),
        "PTD6": (52, "bidir"), "PTD7": (51, "bidir"), "PTD8": (64, "bidir"),
        "PTD9": (63, "bidir"), "PTD10": (56, "bidir"), "PTD11": (55, "bidir"),
        "PTD12": (54, "bidir"), "PTD13": (41, "bidir"), "PTD14": (40, "bidir"),
        "PTD15": (35, "bidir"), "PTD16": (34, "bidir"), "PTD17": (31, "bidir"),
        "PTD20": (111, "bidir"), "PTD21": (115, "bidir"), "PTD22": (118, "bidir"),
        "PTD23": (122, "bidir"), "PTD24": (125, "bidir"), "PTD26": (131, "bidir"),
        "PTD27": (132, "bidir"), "PTD28": (134, "bidir"), "PTD29": (136, "bidir"),
        "PTD30": (138, "bidir"), "PTD31": (139, "bidir"),
        # Port E
        "PTE0": (163, "bidir"), "PTE1": (162, "bidir"), "PTE2": (147, "bidir"),
        "PTE4": (13, "bidir"), "PTE5": (12, "bidir"), "PTE6": (146, "bidir"),
        "PTE7": (104, "bidir"), "PTE8": (46, "bidir"), "PTE10": (10, "bidir"),
        "PTE11": (9, "bidir"), "PTE12": (29, "bidir"), "PTE13": (11, "bidir"),
        "PTE15": (5, "bidir"), "PTE16": (4, "bidir"), "PTE17": (142, "bidir"),
        "PTE18": (144, "bidir"), "PTE21": (153, "bidir"), "PTE22": (154, "bidir"),
        "PTE23": (156, "bidir"), "PTE24": (157, "bidir"), "PTE25": (158, "bidir"),
        "PTE26": (164, "bidir"),
    }

    # Special function pins with JTAG annotations
    # PTC4 = TCK, PTC5 = TDI, PTA4 = TMS, PTA10 = TDO
    jtag_notes = {"PTC4": "TCK", "PTC5": "TDI", "PTA4": "TMS", "PTA10": "TDO"}

    # Power pins
    power_pins = {
        "VDD_HV_A": [18, 108, 128, 151, 169],
        "VDD_HV_B": [38, 57, 77],
        "V11": [21, 59, 106, 149],
        "V15": [20, 36, 60, 79, 105, 148],
        "V25": [19],
        "VDD_DCDC": [28],
        "VSS": [22, 24, 37, 58, 78, 107, 127, 150, 168],
        "VSS_DCDC": [26],
        "VREFH": [16],
        "VREFL": [17],
        "EP": ["EP"],  # Exposed pad
    }

    special_pins = {
        "EXTAL": (23, "input"),
        "XTAL": (25, "output"),
        "PMOS_CTRL": (27, "output"),
    }

    # Group GPIO by port for multi-unit symbol
    ports = {}
    for name, (pin, direction) in sorted(gpio_pins.items()):
        port = name[:3]  # PTA, PTB, PTC, PTD, PTE
        if port not in ports:
            ports[port] = []
        ports[port].append((name, pin, direction))

    # Sort each port's pins by the numeric suffix
    for port in ports:
        ports[port].sort(key=lambda x: int(re.search(r'\d+', x[0][3:]).group()))

    # Build symbol - single unit for simplicity (multi-unit makes wiring harder in KiCad)
    # We'll make a big symbol with pins grouped by port on the sides

    # Calculate dimensions
    all_left_pins = []  # Ports A, B, C on left
    all_right_pins = []  # Ports D, E, power, special on right

    for name, pin, direction in ports.get("PTA", []):
        label = f"{name}/{'JTAG_'+jtag_notes[name] if name in jtag_notes else name}"
        if name in jtag_notes:
            label = f"{name}/{jtag_notes[name]}"
        else:
            label = name
        all_left_pins.append((label, str(pin), direction))
    all_left_pins.append(("---PORT_B---", None, None))  # Separator
    for name, pin, direction in ports.get("PTB", []):
        all_left_pins.append((name, str(pin), direction))
    all_left_pins.append(("---PORT_C---", None, None))
    for name, pin, direction in ports.get("PTC", []):
        label = name
        if name in jtag_notes:
            label = f"{name}/{jtag_notes[name]}"
        all_left_pins.append((label, str(pin), direction))

    for name, pin, direction in ports.get("PTD", []):
        all_right_pins.append((name, str(pin), direction))
    all_right_pins.append(("---PORT_E---", None, None))
    for name, pin, direction in ports.get("PTE", []):
        all_right_pins.append((name, str(pin), direction))

    # Remove separator entries and just track counts for spacing
    left_pins_clean = [(n, p, d) for n, p, d in all_left_pins if p is not None]
    right_pins_clean = [(n, p, d) for n, p, d in all_right_pins if p is not None]

    # Add special pins to right side
    for name, (pin, direction) in sorted(special_pins.items()):
        right_pins_clean.append((name, str(pin), direction))

    max_pins = max(len(left_pins_clean), len(right_pins_clean))

    # Add power pins at bottom, ground at top
    vdd_pins = []
    vss_pins = []
    for net, pins in power_pins.items():
        for p in pins:
            if "VSS" in net or net == "EP" or net == "VREFL":
                vss_pins.append((net, str(p)))
            else:
                vdd_pins.append((net, str(p)))

    # Symbol dimensions
    pin_spacing = 2.54  # 100mil grid
    box_half_width = 20  # x extent from center
    pin_length = 5.08  # 200mil

    # Total height based on max of left/right side pins
    total_left = len(left_pins_clean)
    total_right = len(right_pins_clean)
    max_side = max(total_left, total_right)
    box_half_height = (max_side * pin_spacing) / 2 + 5.08  # Extra padding

    # Power/ground on top/bottom
    power_width = max(len(vdd_pins), len(vss_pins)) * pin_spacing
    if power_width / 2 > box_half_width:
        box_half_width = power_width / 2 + 5.08

    output = kicad_sym_header("S32K358")

    output += f"""  (symbol "S32K358"
    (pin_names
      (offset 1.016)
    )
    (exclude_from_sim no)
    (in_bom yes)
    (on_board yes)
    (property "Reference" "U"
      (at 0 {box_half_height + 2.54} 0)
      (effects (font (size 1.27 1.27)))
    )
    (property "Value" "S32K358"
      (at 0 {-box_half_height - 2.54} 0)
      (effects (font (size 1.27 1.27)))
    )
    (property "Footprint" "Package_QFP:TQFP-172_24x24mm_P0.5mm"
      (at 0 {-box_half_height - 5.08} 0)
      (effects (font (size 1.27 1.27)) hide)
    )
    (property "Datasheet" "https://www.nxp.com/docs/en/data-sheet/S32K3xx.pdf"
      (at 0 {-box_half_height - 7.62} 0)
      (effects (font (size 1.27 1.27)) hide)
    )
    (property "Description" "S32K358 Arm Cortex-M7 MCU, 8MB Flash, 1152KB RAM, 240MHz, HDQFP172-EP"
      (at 0 0 0)
      (effects (font (size 1.27 1.27)) hide)
    )
    (symbol "S32K358_0_1"
      (rectangle
        (start {-box_half_width} {box_half_height})
        (end {box_half_width} {-box_half_height})
        (stroke (width 0.254) (type default))
        (fill (type background))
      )
    )
    (symbol "S32K358_1_1"
"""

    # Left side pins (pointing right into the box)
    y_start = box_half_height - 5.08
    for i, (name, pin_num, direction) in enumerate(left_pins_clean):
        y = y_start - i * pin_spacing
        pin_type = "bidirectional"
        if direction == "input":
            pin_type = "input"
        elif direction == "output":
            pin_type = "output"
        elif direction == "linkage":
            pin_type = "passive"
        output += f"""      (pin {pin_type} line
        (at {-box_half_width - pin_length} {y:.2f} 0)
        (length {pin_length})
        (name "{name}"
          (effects (font (size 1.016 1.016)))
        )
        (number "{pin_num}"
          (effects (font (size 1.016 1.016)))
        )
      )
"""

    # Right side pins (pointing left into the box)
    y_start_r = box_half_height - 5.08
    for i, (name, pin_num, direction) in enumerate(right_pins_clean):
        y = y_start_r - i * pin_spacing
        pin_type = "bidirectional"
        if direction == "input":
            pin_type = "input"
        elif direction == "output":
            pin_type = "output"
        elif direction == "linkage":
            pin_type = "passive"
        output += f"""      (pin {pin_type} line
        (at {box_half_width + pin_length} {y:.2f} 180)
        (length {pin_length})
        (name "{name}"
          (effects (font (size 1.016 1.016)))
        )
        (number "{pin_num}"
          (effects (font (size 1.016 1.016)))
        )
      )
"""

    # Top pins - VDD power
    x_start_top = -((len(vdd_pins) - 1) * pin_spacing) / 2
    for i, (name, pin_num) in enumerate(vdd_pins):
        x = x_start_top + i * pin_spacing
        output += f"""      (pin power_in line
        (at {x:.2f} {box_half_height + pin_length} 270)
        (length {pin_length})
        (name "{name}"
          (effects (font (size 1.016 1.016)))
        )
        (number "{pin_num}"
          (effects (font (size 1.016 1.016)))
        )
      )
"""

    # Bottom pins - VSS ground
    x_start_bot = -((len(vss_pins) - 1) * pin_spacing) / 2
    for i, (name, pin_num) in enumerate(vss_pins):
        x = x_start_bot + i * pin_spacing
        output += f"""      (pin power_in line
        (at {x:.2f} {-box_half_height - pin_length} 90)
        (length {pin_length})
        (name "{name}"
          (effects (font (size 1.016 1.016)))
        )
        (number "{pin_num}"
          (effects (font (size 1.016 1.016)))
        )
      )
"""

    output += """    )
  )
"""
    output += kicad_sym_footer()
    return output


def generate_fs26():
    """Generate FS26 (MFS2633HMDAJAD) LQFP48 symbol."""

    # Pin data from FS26_SDS.pdf pages 15-16 (Table 3. Pin descriptions)
    # Organized by function for the symbol layout

    # Left side: Power management (supply, pre-reg, LDO, reference)
    left_pins = [
        # Supply inputs
        ("VSUP", "42", "power_in"),       # Supply pin for internal biasing
        ("VSUP_PWR", "41", "power_in"),   # VPRE converter supply pin
        ("BATSENSE", "48", "input"),      # Battery sense terminal
        ("LDOIN", "10", "input"),         # LDO1/LDO2 regulator input voltage supply
        # VPRE buck pre-regulator
        ("VPRE_SW", "40", "passive"),     # VPRE switching node
        ("VPRE_BT", "39", "passive"),     # VPRE boot strap capacitor
        ("VPRE_FB", "37", "input"),       # VPRE feedback node
        # VCORE buck regulator
        ("CORE_IN", "34", "input"),       # VCORE input supply
        ("CORE_SW", "32", "passive"),     # VCORE switching node
        ("CORE_BT", "33", "input"),       # VCORE bootstrap supply
        ("CORE_FB", "30", "input"),       # VCORE feedback node
        # LDO outputs
        ("LDO1OUT", "11", "power_out"),   # LDO1 regulator output
        ("LDO2OUT", "9", "power_out"),    # LDO2 output
        # Reference and trackers
        ("VREF", "8", "power_out"),       # Voltage reference output
        ("TRK1", "4", "power_out"),       # TRK1 regulator output
        ("TRK2", "5", "power_out"),       # TRK2 regulator output
        ("TRKIN", "7", "input"),          # TRK1/TRK2/VREF regulators input
    ]

    # Right side: Digital interface, safety, I/O
    right_pins = [
        # SPI interface
        ("INTB", "24", "output"),         # Interrupt output
        ("MISO", "25", "output"),         # SPI Primary In Secondary out
        ("MOSI", "26", "input"),          # SPI Primary Out Secondary input
        ("SCLK", "27", "input"),          # SPI clock input
        ("CSB", "28", "input"),           # SPI chip select
        # Safety outputs
        ("RSTB", "16", "bidirectional"),  # Reset input/output
        ("FS0B", "13", "output"),         # Safety output #0 (FS02)
        ("FS1B", "12", "output"),         # Safety output #1 (FS01)
        ("FCCU1", "17", "input"),         # FCCU pin 1
        ("FCCU2", "18", "input"),         # FCCU pin 2
        # Monitoring
        ("VMONPRE", "36", "input"),       # VMON_PRE voltage monitoring
        ("VMONCORE", "15", "input"),      # VMON_CORE voltage monitoring
        ("VMONEXT", "14", "input"),       # VMON_EXT voltage monitoring
        ("AMUX", "29", "output"),         # Analog multiplexer output
        # I/O
        ("GPIO1", "3", "bidirectional"),  # General Purpose I/O 1
        ("GPIO2", "6", "bidirectional"),  # General Purpose I/O 2
        ("WAKE1", "47", "input"),         # WAKE1 input pin
        ("WAKE2", "2", "input"),          # WAKE2 input / ERRMON
        ("DEBUG", "31", "input"),         # DEBUG input pin (OTP/debug mode)
        ("VBOS", "35", "passive"),        # Best Of Supply decoupling output
    ]

    # Top: VBST boost, power outputs
    top_pins = [
        ("VBST_PG", "1", "output"),       # Power Good signal of VBST
        ("VBST_ISH", "46", "input"),      # VBST current sense high
        ("VBST_ISL", "44", "input"),      # VBST current sense low
        ("VBST_G", "45", "output"),       # VBST low-side gate drive
        ("VBST_FB", "43", "input"),       # VBST feedback node
        ("VDIG", "21", "power_out"),      # 1.6V digital supply
        ("VDDIO", "23", "power_in"),      # I/O input supply
    ]

    # Bottom: Ground
    bottom_pins = [
        ("GND", "20", "power_in"),        # Ground for main circuitry
        ("GNDFS", "19", "power_in"),      # Ground for fail-safe circuitry
        ("GNDSUB", "22", "power_in"),     # Substrate ground
        ("NC", "38", "passive"),          # Not connected
        ("EP", "49", "power_in"),         # Exposed pad (ground)
    ]

    pin_spacing = 2.54
    pin_length = 5.08
    max_side = max(len(left_pins), len(right_pins))
    box_half_height = (max_side * pin_spacing) / 2 + 2.54
    max_tb = max(len(top_pins), len(bottom_pins))
    box_half_width = (max_tb * pin_spacing) / 2 + 5.08
    if box_half_width < 15:
        box_half_width = 15

    output = kicad_sym_header("FS26")

    output += f"""  (symbol "FS26_SBC"
    (pin_names
      (offset 1.016)
    )
    (exclude_from_sim no)
    (in_bom yes)
    (on_board yes)
    (property "Reference" "U"
      (at 0 {box_half_height + 2.54} 0)
      (effects (font (size 1.27 1.27)))
    )
    (property "Value" "FS26_SBC"
      (at 0 {-box_half_height - 2.54} 0)
      (effects (font (size 1.27 1.27)))
    )
    (property "Footprint" "Package_QFP:LQFP-48_7x7mm_P0.5mm"
      (at 0 {-box_half_height - 5.08} 0)
      (effects (font (size 1.27 1.27)) hide)
    )
    (property "Datasheet" "https://www.nxp.com/docs/en/data-sheet/FS26_SDS.pdf"
      (at 0 {-box_half_height - 7.62} 0)
      (effects (font (size 1.27 1.27)) hide)
    )
    (property "Description" "FS26 Safety System Basis Chip, ASIL D, LQFP48"
      (at 0 0 0)
      (effects (font (size 1.27 1.27)) hide)
    )
    (property "MPN" "MFS2633HMDAJAD"
      (at 0 0 0)
      (effects (font (size 1.27 1.27)) hide)
    )
    (symbol "FS26_SBC_0_1"
      (rectangle
        (start {-box_half_width} {box_half_height})
        (end {box_half_width} {-box_half_height})
        (stroke (width 0.254) (type default))
        (fill (type background))
      )
    )
    (symbol "FS26_SBC_1_1"
"""

    # Left side pins
    y_start = box_half_height - 5.08
    for i, (name, pin_num, pin_type) in enumerate(left_pins):
        y = y_start - i * pin_spacing
        output += f"""      (pin {pin_type} line
        (at {-box_half_width - pin_length} {y:.2f} 0)
        (length {pin_length})
        (name "{name}"
          (effects (font (size 1.016 1.016)))
        )
        (number "{pin_num}"
          (effects (font (size 1.016 1.016)))
        )
      )
"""

    # Right side pins
    y_start_r = box_half_height - 5.08
    for i, (name, pin_num, pin_type) in enumerate(right_pins):
        y = y_start_r - i * pin_spacing
        output += f"""      (pin {pin_type} line
        (at {box_half_width + pin_length} {y:.2f} 180)
        (length {pin_length})
        (name "{name}"
          (effects (font (size 1.016 1.016)))
        )
        (number "{pin_num}"
          (effects (font (size 1.016 1.016)))
        )
      )
"""

    # Top pins
    x_start_top = -((len(top_pins) - 1) * pin_spacing) / 2
    for i, (name, pin_num, pin_type) in enumerate(top_pins):
        x = x_start_top + i * pin_spacing
        output += f"""      (pin {pin_type} line
        (at {x:.2f} {box_half_height + pin_length} 270)
        (length {pin_length})
        (name "{name}"
          (effects (font (size 1.016 1.016)))
        )
        (number "{pin_num}"
          (effects (font (size 1.016 1.016)))
        )
      )
"""

    # Bottom pins
    x_start_bot = -((len(bottom_pins) - 1) * pin_spacing) / 2
    for i, (name, pin_num, pin_type) in enumerate(bottom_pins):
        x = x_start_bot + i * pin_spacing
        output += f"""      (pin {pin_type} line
        (at {x:.2f} {-box_half_height - pin_length} 90)
        (length {pin_length})
        (name "{name}"
          (effects (font (size 1.016 1.016)))
        )
        (number "{pin_num}"
          (effects (font (size 1.016 1.016)))
        )
      )
"""

    output += """    )
  )
"""
    output += kicad_sym_footer()
    return output


if __name__ == "__main__":
    import os

    out_dir = os.path.dirname(os.path.abspath(__file__))

    # Generate S32K358 symbol
    s32k_sym = generate_s32k358()
    s32k_path = os.path.join(out_dir, "S32K358.kicad_sym")
    with open(s32k_path, "w") as f:
        f.write(s32k_sym)
    print(f"Generated {s32k_path}")

    # Generate FS26 symbol
    fs26_sym = generate_fs26()
    fs26_path = os.path.join(out_dir, "FS26.kicad_sym")
    with open(fs26_path, "w") as f:
        f.write(fs26_sym)
    print(f"Generated {fs26_path}")

    # Print summary
    print("\nS32K358 HDQFP172-EP pin summary:")
    print(f"  GPIO pins: PTA(28) + PTB(27) + PTC(31) + PTD(29) + PTE(22) = 137")
    print(f"  Special: EXTAL, XTAL, PMOS_CTRL = 3")
    print(f"  Power: VDD_HV_A(5) + VDD_HV_B(3) + V11(4) + V15(6) + V25(1) + VDD_DCDC(1) = 20")
    print(f"  Ground: VSS(9) + VSS_DCDC(1) + VREFH(1) + VREFL(1) + EP(1) = 13")
    print(f"  Total: 137 + 3 + 20 + 13 = 173 (172 pins + EP)")

    print("\nFS26 LQFP48 pin summary:")
    print(f"  Total: 48 pins + EP (49 connections)")
