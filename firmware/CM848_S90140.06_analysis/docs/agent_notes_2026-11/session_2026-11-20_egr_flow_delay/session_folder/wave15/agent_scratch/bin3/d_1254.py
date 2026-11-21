"""Rows 13-32: e2m block 1254 (Jcomm default network priorities), EEPROM mirror 0x3fd83c-0x3fd880. Table driven."""

ROWS = {}

MIRROR_BASE = 0x3FD482

# (address, e2m offset, record, e2m description, old name, pgn, message, function, header constant, dump value, kind)
# kind: "cal" = name only lacked _cal; "bits" = the name also said source_address_bits
TABLE = [
    ("0x003fd83c", "2", "Jcomm_Amb_Cond_Message_Default_Priority", "[JCAAPZ] default network priority for Ambient Conditions message", "j1939_pgn65269_priority", 65269, "Ambient Conditions (AMB)", "cm848_initJ1939AmbientConditionsBuffer", "0xfef500", 6, "cal"),
    ("0x003fd840", "6", "Jcomm_Component_ID_Message_Default_Priority", "[JCIDPZ] default network priority for Component Identification message", "j1939_pgn65259_priority", 65259, "Component Identification (CI)", "cm848_initPgn65259ComponentIdHandler", "0xfeeb00", 6, "cal"),
    ("0x003fd846", "C", "Jcomm_DM4_Message_Default_Priority", "[JCDG04PZ] Default priority for Diagnostic Message 4", "j1939_pgn65229_priority", 65229, "Freeze Frame Parameters (DM4)", "cm848_initPgn65229Dm4Handler", "0xfecd00", 6, "cal"),
    ("0x003fd848", "E", "Jcomm_DM5_Message_Default_Priority", "[JCDG05PZ] Default priority for Diagnostic Message 5", "j1939_pgn65230_priority", 65230, "Diagnostic Readiness 1 (DM5)", "cm848_initPgn65230Dm5Handler", "0xfece00", 6, "cal"),
    ("0x003fd84a", "10", "Jcomm_DM8_Message_Default_Priority", "[JCDG08PZ] Default priority for Diagnostic Message 8", "j1939_pgn65232_priority", 65232, "Test Results for Non-continuously Monitored Systems (DM8)", "cm848_initJ1939EngineControlBuffer", "0xfed000", 6, "cal"),
    ("0x003fd84e", "14", "Jcomm_EEC1_Message_Default_Priority", "[JCEG01PZ] default network priority for EEC1 message", "j1939_pgn61444_priority", 61444, "Electronic Engine Controller 1 (EEC1)", "cm848_initEec1TxDescriptor", "0xf00400", 3, "cal"),
    ("0x003fd850", "16", "Jcomm_EEC2_Message_Default_Priority", "[JCEG02PZ] default network priority for EEC2 message", "j1939_pgn61443_priority", 61443, "Electronic Engine Controller 2 (EEC2)", "cm848_initPgn61443Eec2Handler", "0xf00300", 3, "cal"),
    ("0x003fd852", "18", "Jcomm_EEC3_Message_Default_Priority", "[JCEG03PZ] default network priority for EEC3 message", "j1939_pgn65247_priority", 65247, "Electronic Engine Controller 3 (EEC3)", "cm848_initPgn65247ElectronicEngineController3Buffer", "0xfedf00", 6, "cal"),
    ("0x003fd854", "1A", "Jcomm_Engine_Config_Message_Default_Priority", "[JCEGCGPZ] default network priority for Engine Configuration message", "j1939_pgn65251_priority", 65251, "Engine Configuration 1 (EC1)", "initFaultTimerMessage", "0xfee300", 6, "cal"),
    ("0x003fd856", "1C", "Jcomm_Engine_Fluid_Message_Default_Priority", "[JCEGFDPZ] default network priority for Engine Fluid message", "j1939_pgn65263_priority", 65263, "Engine Fluid Level/Pressure 1 (EFL/P1)", "cm848_initJ1939FluidLevelPressureBuffer", "0xfeef00", 6, "cal"),
    ("0x003fd858", "1E", "Jcomm_ERC1_Message_Default_Priority", "[JCRD01PZ] default network priority for ERC1 message", "j1939_pgn61440_priority", 61440, "Electronic Retarder Controller 1 (ERC1)", "cm848_initializePgn61440ElectronicRetarderController1Buffer", "0xf00000", 6, "cal"),
    ("0x003fd85a", "20", "Jcomm_Engine_Temp_Message_Default_Priority", "[JCEGTPPZ] default network priority for Engine Temperature message", "j1939_pgn65262_source_address_bits", 65262, "Engine Temperature 1 (ET1)", "cm848_initPgn65262EngineTempHandler", "0xfeee00", 6, "bits"),
    ("0x003fd86a", "30", "Jcomm_Vehicle_Dist_Message_Default_Priority", "[JCVHDSPZ] default network priority for Vehicle Distance message", "j1939_pgn65248_source_address_bits", 65248, "Vehicle Distance (VD)", "cm848_initPgn65248VehicleDistanceHandler", "0xfee000", 6, "bits"),
    ("0x003fd86c", "32", "Jcomm_Vehicle_Elect_Power_Message_Default_Priority", "[JCVHPXPZ] default network priority for Vehicle Electrical Power message", "j1939_pgn65271_source_address_bits", 65271, "Vehicle Electrical Power 1 (VEP1)", "cm848_initJ1939VehicleElectricalBuffer", "0xfef700", 6, "bits"),
    ("0x003fd876", "3C", "Jcomm_Vehicle_ID_Number_Message_Default_Priority", "[JCVHIDPZ] Default network priority for Vehicle Identification Message", "j1939_pgn65260_source_address_bits", 65260, "Vehicle Identification (VI)", "cm848_initPgn65260VehicleIdHandler", "0xfeec00", 6, "bits"),
    ("0x003fd878", "3E", "Jcomm_EBC1_Message_Default_Priority", "[JCEBDFPZ] Default network priority for Engine Brake Controller #1 message.", "j1939_pgn61441_source_address_bits", 61441, "Electronic Brake Controller 1 (EBC1)", "cm848_initJ1939Etc1ControlBuffer", "0xf00100", 6, "bits"),
    ("0x003fd87c", "42", "Jcomm_WIFI_Message_Default_Priority", "[JCWFDFPZ] Default network priority for Water In Fuel Indicator Message.", "j1939_pgn65279_source_address_bits", 65279, "Water In Fuel Indicator 1 (WFI)", "cm848_initJ1939SafetyStatusBuffer", "0xfeff00", 6, "bits"),
]

# the two rows whose old name also carried the wrong PGN number
SPECIAL = [
    ("0x003fd87e", "44", "Jcomm_EPA_Info_Message_Default_Priority", "default network priority for TTS Message", "j1939_pgn57344_source_address_bits", 65504, "Proprietary B (PropB_E0)", "cm848_initJ1939ProprietaryPgn65504Buffer", "0xffe000", 6,
     "the name said PGN 57344 (Cab Message 1), but the header built here is 0xffe000 = PGN 65504 (the function name says Pgn65504; the transmit descriptor j1939_pgn57344_tx_message carries the same wrong number)"),
    ("0x003fd880", "46", "Jcomm_Anti_Theft_Status_Msg_Default_Priority", "default network priority for anti-theft status message", "j1939_pgn56360_source_address_bits", 56320, "Anti-theft Status (ATS)", "cm848_initJ1939ProprietaryStatusBuffer", "0xdc2800", 7,
     "the name said PGN 56360, but the header 0xdc2800 is PF 0xdc = PGN 56320 (Anti-theft Status, destination specific; the 0x28 in the PS byte is a destination address that cm848_sendJ1939ProprietaryStatus overwrites from j1939_prop_status_byte2 at send time); the transmit descriptor j1939_pgn56360_tx_message carries the same wrong number"),
]

QUOTE_BY_OLD = {
    "j1939_pgn65269_priority": "CONCAT13(((byte)j1939_pgn65269_priority & 7) << 2,0xfef500);",
    "j1939_pgn65259_priority": "CONCAT13(((byte)j1939_pgn65259_priority & 7) << 2,0xfeeb00);",
    "j1939_pgn65229_priority": "CONCAT13(((byte)j1939_pgn65229_priority & 7) << 2,0xfecd00);",
    "j1939_pgn65230_priority": "CONCAT13(((byte)j1939_pgn65230_priority & 7) << 2,0xfece00);",
    "j1939_pgn65232_priority": "CONCAT13(((byte)j1939_pgn65232_priority & 7) << 2,0xfed000);",
    "j1939_pgn61444_priority": "CONCAT13(((byte)j1939_pgn61444_priority & 7) << 2,0xf00400);",
    "j1939_pgn61443_priority": "CONCAT13(((byte)j1939_pgn61443_priority & 7) << 2,0xf00300);",
    "j1939_pgn65247_priority": "CONCAT13(((byte)j1939_pgn65247_priority & 7) << 2,0xfedf00);",
    "j1939_pgn65251_priority": "CONCAT13(((byte)j1939_pgn65251_priority & 7) << 2,0xfee300);",
    "j1939_pgn65263_priority": "CONCAT13(((byte)j1939_pgn65263_priority & 7) << 2,0xfeef00);",
    "j1939_pgn61440_priority": "CONCAT13(((byte)j1939_pgn61440_priority & 7) << 2,0xf00000);",
    "j1939_pgn65262_source_address_bits": "CONCAT13(((byte)j1939_pgn65262_source_address_bits & 7) << 2,0xfeee00);",
    "j1939_pgn65248_source_address_bits": "CONCAT13(((byte)j1939_pgn65248_source_address_bits & 7) << 2,0xfee000);",
    "j1939_pgn65271_source_address_bits": "CONCAT13(((byte)j1939_pgn65271_source_address_bits & 7) << 2,0xfef700);",
    "j1939_pgn65260_source_address_bits": "CONCAT13(((byte)j1939_pgn65260_source_address_bits & 7) << 2,0xfeec00);",
    "j1939_pgn61441_source_address_bits": "CONCAT13(((byte)j1939_pgn61441_source_address_bits & 7) << 2,0xf00100);",
    "j1939_pgn65279_source_address_bits": "CONCAT13(((byte)j1939_pgn65279_source_address_bits & 7) << 2,0xfeff00);",
    "j1939_pgn57344_source_address_bits": "CONCAT13(((byte)j1939_pgn57344_source_address_bits & 7) << 2,0xffe000);",
    "j1939_pgn56360_source_address_bits": "CONCAT13(((byte)j1939_pgn56360_source_address_bits & 7) << 2,0xdc2800);",
}


def add(address, off, record, desc, old, pgn, message, function, header, dump, kind, extra=""):
    eeprom = int(address, 16) - MIRROR_BASE
    new = f"j1939_pgn{pgn}_priority_cal"
    bits_note = "; the old name said source address bits, which this code never uses" if kind == "bits" else ""
    evidence = (
        f"e2m 1254 +{off} {record} (UNITLESS, 0..7; {dump} in the dump): {function} builds the PGN {pgn} ({message}) can_id with (value & 7) << 2 as its top byte, i.e. the 3-bit network priority; "
        f"EEPROM mirror word (EEPROM 0x{eeprom:x}), so the name needs _cal{bits_note}" + (f"; {extra}" if extra else "")
    )
    comment = (
        f"EEPROM 0x{eeprom:x} - e2m 1254 +{off} {record} '{desc}' (address from the ECU's parameter ID table; UNITLESS 0..7; {dump} in the dump): "
        f"{function} uses (value & 7) << 2 as the top byte of the 29-bit CAN id of the {message} message (PGN {pgn}, header {header}), i.e. its 3-bit default network priority"
        + (", not source address bits" if kind == "bits" else "")
        + (f". {extra[0].upper() + extra[1:]}" if extra else "")
        + f". 0x{address[2:].lstrip('0')} is inside the EEPROM mirror (0x3fd482-0x3feec1), so the _cal suffix applies."
    )
    ROWS[address] = {
        "verdict": "confirmed",
        "new": new,
        "evidence": evidence,
        "code_quote": f"{function}: {QUOTE_BY_OLD[old]}",
        "comment": comment,
    }


for row in TABLE:
    add(*row)
for row in SPECIAL:
    add(*row[:-1], "bits", extra=row[-1])

ROWS["0x003fd87a"] = {
    "verdict": "keep",
    "e2m_note": "e2m 1254 +40 Jcomm_Fan_Drive_Message_Default_Priority '[JCFMDFPZ] Default network priority for Fan Drive Message.'",
}
