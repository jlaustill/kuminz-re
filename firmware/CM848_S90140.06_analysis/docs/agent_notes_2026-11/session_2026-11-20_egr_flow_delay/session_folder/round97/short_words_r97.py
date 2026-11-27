"""Round 97: the short words (<= 4 letters, no digits) left in a plan's new names that are not on the allow list, with
one example each. usage: short_words_r97.py <plan.csv> [column]"""
import collections
import csv
import sys

col = sys.argv[2] if len(sys.argv) > 2 else "new"
OK = {"RPM", "J1939", "CAN", "ID", "PGN", "SPN", "DTC", "ECM", "RAM", "ROM", "PWM", "ADC", "TPU", "QADC", "VP44", "ACK",
      "NACK", "OBD", "SCI", "PCI", "CRC", "OK", "NO", "ON", "OFF", "SET", "AND", "OR", "TO", "OF", "IN", "AT", "BY", "FOR",
      "THE", "A", "B", "C", "D", "E", "F", "X", "Y", "Z", "UP", "LOW", "HIGH", "KEY", "BIT", "RUN", "END", "NEW", "OLD",
      "ONE", "TWO", "ALL", "ANY", "MAP", "LAMP", "FAN", "GAP", "IDLE", "FUEL", "BYTE", "WORD", "TYPE", "MODE", "FLAG",
      "TIME", "LOAD", "PEAK", "ZERO", "FULL", "NONE", "FAIL", "PASS", "SEND", "READ", "WAIT", "DATA", "CODE", "SIZE",
      "STEP", "FAST", "SLOW", "MAIN", "BOOT", "TEST", "FIRE", "RATE", "SYNC", "CAM", "BUS", "PIN", "TSC1", "HPCR", "VGT",
      "EGR", "OIL", "AIR", "CRUISE", "BOOST", "BASE", "LAST", "NEXT", "LEFT", "HOLD", "LOCK", "OPEN", "SHUT", "FLOW",
      "LINE", "PORT", "PULL", "PUSH", "PUMP", "RING", "ROAD", "SAVE", "SEED", "SPAN", "TRIP", "UNIT", "USER", "WRITE",
      "LIVE", "SAFE", "EXIT", "BACK", "ONLY", "WITH", "LIST", "MASK", "SAME", "VALID", "EVEN", "ODD", "DONE", "BUSY",
      "IS", "IF", "ITS", "PER", "NOT", "USE", "GET", "PUT", "ADD", "CLEAR", "LOOP", "DROP", "HOT", "COLD", "WARM", "WET",
      "DRY", "TOP", "BIG", "MID", "KEEP", "OVER", "UNDER", "FROM", "INTO", "PART", "SELF", "SIDE", "SLAVE", "ROW", "CELL",
      "EDGE", "MISS", "PULSE", "TOOTH", "CRANK", "PHASE", "FORCE", "RESET", "RETRY", "REPLY"}
words = collections.Counter()
ex = {}
for r in csv.DictReader(open(sys.argv[1])):
    for w in r[col].split("_"):
        if 1 < len(w) <= 4 and not any(ch.isdigit() for ch in w) and w.upper() not in OK:
            words[w] += 1
            ex.setdefault(w, r[col])
print(", ".join(f"{w} {n} ({ex[w]})" for w, n in words.most_common(60)))
