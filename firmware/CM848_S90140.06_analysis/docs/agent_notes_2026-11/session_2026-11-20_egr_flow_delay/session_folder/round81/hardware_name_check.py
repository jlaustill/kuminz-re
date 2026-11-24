"""For each CM550 function, the MC68336 / external register modules it touches (by the round 75-80 register names) next
to the hardware its own name claims; prints the functions whose claimed hardware is not among the touched modules.
usage: hardware_name_check.py <cpp>"""
import collections
import re
import sys

MODULES = [("SCI", r"\bQSM_SC(CR0|CR1|SR|DR)\b"),
           ("QSPI", r"\bQSM_(SPCR[0-3]|SPSR|TR\d+|RR\d+|CR\d+|QSMCR|QILR|QIVR|PORTQS|PQSPAR|DDRQS)\b"),
           ("QADC", r"\bQADC_\w+"), ("CTM4", r"\bCTM4_\w+"), ("TPU", r"\bTPU_\w+"), ("SIM", r"\bSIM_\w+"),
           ("CAN_CS5", r"\bCAN_CS5_\w+"), ("CAN_CS4", r"\bCAN_CS4_\w+"), ("CS2", r"\bCS2_\w+"),
           ("RAM_MODULES", r"\b(SRAM|TPURAM)_\w+")]
CLAIMS = [("TPU", r"tpu"), ("CAN", r"can"), ("SCI", r"sci|serial|j1708"), ("QADC", r"qadc|adc"), ("QSPI", r"qspi|spi"),
          ("CTM4", r"pwm|ctm|dasm|mcsm"), ("SIM", r"watchdog|chipselect|pit")]
text = open(sys.argv[1], errors="replace").read()
parts = re.split(r"^// Function: (\S+) @ (0x[0-9a-f]+)[^\n]*\n", text, flags=re.M)
for i in range(1, len(parts), 3):
    name, address, body = parts[i], parts[i + 1], parts[i + 2]
    body = re.sub(r"/\*.*?\*/", "", body, flags=re.S)
    touched = collections.Counter()
    for module, pattern in MODULES:
        n = len(re.findall(pattern, body))
        if n:
            touched[module] = n
    lowered = name.lower()
    claims = [c for c, p in CLAIMS if re.search(p, lowered)]
    if not claims or not touched:
        continue
    have = set(touched)
    ok = any((c == "CAN" and have & {"CAN_CS5", "CAN_CS4"}) or c in have for c in claims)
    if not ok:
        print(f"{address} {name}: claims {'/'.join(claims)}; touches {dict(touched)}")
