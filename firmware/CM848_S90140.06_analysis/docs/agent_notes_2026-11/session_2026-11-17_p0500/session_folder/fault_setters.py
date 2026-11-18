"""For every function in a CM848 .cpp, list the fault bits it SETS (fault_detected_bits_A_to_B |= mask)
and the OBD P-code each maps to (ROM 0x5985a slot table -> obd_dtc_code_table @ 0x5b57c)."""
import re, struct, sys
cpp, rom = sys.argv[1], open(sys.argv[2], 'rb').read()
u16 = lambda a: struct.unpack('>H', rom[a:a+2])[0]
def pcode(f):
    s = u16(0x5985a + 2*f)
    return f"P{u16(0x5b57c + 2*s):04x}" if s < 170 else f"slot{s}"
fn_re = re.compile(r'^// Function: (\S+) @ 0x([0-9a-fA-F]+)', re.M)
text = open(cpp, errors='replace').read()
marks = list(fn_re.finditer(text))
set_re = re.compile(r'fault_detected_bits_(\d+)_to_(\d+)\s*=\s*[^;]*?\|\s*(0x[0-9a-fA-F]+|\d+)\s*;')
for i, m in enumerate(marks):
    body = text[m.end(): marks[i+1].start() if i+1 < len(marks) else len(text)]
    body = re.sub(r'/\*.*?\*/', '', body, flags=re.S)          # drop plate comments
    flat = re.sub(r'\s+', ' ', body)
    faults = set()
    for a, b, mask in set_re.findall(flat):
        mv = int(mask, 0)
        for bit in range(16):
            if mv >> bit & 1:
                faults.add(int(a) + bit)
    if faults:
        print(f"{m.group(1)} @0x{m.group(2)}: " + ", ".join(f"{f}={pcode(f)}" for f in sorted(faults)))
