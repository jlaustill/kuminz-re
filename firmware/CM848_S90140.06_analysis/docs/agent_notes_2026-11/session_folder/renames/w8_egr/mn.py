"""Print every tracked access with its instruction mnemonic (lha / lhz / lbz / lwz ...) for the given addresses."""
import json
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import scan  # noqa: E402

SIZE = {"byte": 1, "word": 2, "dword": 4}
cache = {int(k): v for k, v in json.load(open(scan.CACHE)).items()}
for a in [int(x, 16) for x in sys.argv[1:]]:
    print("=== 0x%06x" % a)
    for ea in range(a - 3, a + 1):
        for (name, start, kind, width, mnem, ln) in cache.get(ea, []):
            if ea + SIZE[width] > a:
                print("   %-6s %-5s %-5s ea=0x%06x %-70s @0x%x" % (kind, width, mnem, ea, name, start))
