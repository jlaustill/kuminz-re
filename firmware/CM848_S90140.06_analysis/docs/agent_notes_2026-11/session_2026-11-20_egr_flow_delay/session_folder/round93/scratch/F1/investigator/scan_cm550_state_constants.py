"""Round 93 F1 (read-only): every word-immediate store and compare of a fueling state number in the CM550 ROM.
Forms scanned (even addresses only):
  move.w #N,(abs).l      33fc 00NN aaaa aaaa
  move.w #N,(An)         3[02468ace]bc 00NN         (dest mode 010)
  move.w #N,(d16,An)     3[13579bdf]7c 00NN dddd    (dest mode 101)
  cmpi.w #N,(abs).l      0c79 00NN aaaa aaaa
  cmpi.w #N,(An)         0c5r 00NN
  cmpi.w #N,(d16,An)     0c6r 00NN dddd
  moveq #N,Dn            7[0-e]NN  (even register nibble) followed within 3 words by move.w Dn,(abs).l (33c0+n aaaa aaaa)
For the (An) forms the base register is resolved from the nearest earlier 'movea.l #imm,An' (2r7c) within 0x80 bytes;
a target in the carrier set is flagged.
usage: scan_cm550_state_constants.py <N> [...]"""
import csv
import struct
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
rom = open(ROM, "rb").read()
CARRIERS = {0x8000fe: "user_fueling_state_previous_pass", 0x80a8f2: "adjusted_user_fueling_state",
            0x80d330: "final_fueling_state", 0x80d334: "requested_fueling_state", 0x80d33c: "final_fueling_state_prev",
            0x80dc32: "power_take_off_or_user_fueling_state", 0x80deca: "torque_derate_fuel_source_code",
            0x80ded0: "fuel_demand_minimum_tracked_state", 0x80ded4: "user_fueling_state",
            0x80d33a: "TQDQTQST (untyped)", 0x80a98e: "ASRFST (untyped)"}
ROWS = []
for row in csv.reader(open("/home/linux/.claude/jobs/374b0424/tmp/w15/r93/frozen/cm550/function_renames.csv", errors="replace")):
    if row and row[0].startswith("0x"):
        try:
            ROWS.append((int(row[0], 16), row[1]))
        except ValueError:
            pass
ROWS.sort()


def owner(a):
    best = None
    for addr, name in ROWS:
        if addr <= a:
            best = (addr, name)
        else:
            break
    return f"{best[1]}@0x{best[0]:x}" if best else "?"


def w16(o):
    return struct.unpack(">H", rom[o:o + 2])[0]


def l32(o):
    return struct.unpack(">I", rom[o:o + 4])[0]


def base_of(reg, at):
    """nearest earlier movea.l #imm,An (opcode 2r7c with r = reg) within 0x100 bytes"""
    op = 0x207C | (reg << 9)
    for p in range(at - 2, max(at - 0x1000, 0), -2):
        if w16(p) == op:
            return l32(p + 2)
    return None


def flag(target):
    if target is None:
        return "base unresolved"
    return f"-> 0x{target:x}" + (f"  <== {CARRIERS[target]}" if target in CARRIERS else "")


for arg in sys.argv[1:]:
    n = int(arg, 0)
    print(f"===== N = {n} (0x{n:x})")
    for o in range(0, len(rom) - 8, 2):
        w = w16(o)
        nxt = w16(o + 2)
        if w == 0x33FC and nxt == n:
            t = l32(o + 4)
            if (t >> 16) in (0x80, 0xFF) or t in CARRIERS:
                print(f"  move.w #{n},(0x{t:x}).l @0x{o:x} [{owner(o)}]" + (f"  <== {CARRIERS[t]}" if t in CARRIERS else ""))
        elif (w & 0xF1FF) == 0x30BC and nxt == n:
            reg = (w >> 9) & 7
            print(f"  move.w #{n},(a{reg}) @0x{o:x} [{owner(o)}] {flag(base_of(reg, o))}")
        elif (w & 0xF1FF) == 0x317C and nxt == n:
            reg = (w >> 9) & 7
            b = base_of(reg, o)
            d = struct.unpack(">h", rom[o + 4:o + 6])[0]
            print(f"  move.w #{n},({d},a{reg}) @0x{o:x} [{owner(o)}] {flag(None if b is None else b + d)}")
        elif w == 0x0C79 and nxt == n:
            t = l32(o + 4)
            if t in CARRIERS:
                print(f"  cmpi.w #{n},(0x{t:x}).l @0x{o:x} [{owner(o)}]  <== {CARRIERS[t]}")
        elif (w & 0xFFF8) == 0x0C50 and nxt == n:
            reg = w & 7
            b = base_of(reg, o)
            if b in CARRIERS:
                print(f"  cmpi.w #{n},(a{reg}) @0x{o:x} [{owner(o)}] {flag(b)}")
        elif (w & 0xFFF8) == 0x0C68 and nxt == n:
            reg = w & 7
            b = base_of(reg, o)
            d = struct.unpack(">h", rom[o + 4:o + 6])[0]
            if b is not None and b + d in CARRIERS:
                print(f"  cmpi.w #{n},({d},a{reg}) @0x{o:x} [{owner(o)}] {flag(b + d)}")
        elif (w & 0xF1FF) == (0x7000 | n) and n < 0x80:
            reg = (w >> 9) & 7
            for k in (2, 4, 6):
                v = w16(o + k)
                if v == (0x33C0 | reg):
                    t = l32(o + k + 2)
                    if t in CARRIERS:
                        print(f"  moveq #{n},d{reg} @0x{o:x} ; move.w d{reg},(0x{t:x}).l @0x{o + k:x} [{owner(o)}]  <== {CARRIERS[t]}")
