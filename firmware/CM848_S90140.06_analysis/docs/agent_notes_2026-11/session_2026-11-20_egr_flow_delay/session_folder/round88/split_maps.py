"""Split each rename map into <map>_cross.csv (safe to apply across firmwares) and <map>_own.csv (old names the two
firmwares rename differently: commitEepromMirrorToEeprom, emptyStubFunction2 / 3). usage: split_maps.py <map>..."""
import sys

CONFLICT = {"commitEepromMirrorToEeprom", "emptyStubFunction2", "emptyStubFunction3"}
for path in sys.argv[1:]:
    rows = open(path).read().split("\n")
    head, body = rows[0], [r for r in rows[1:] if r]
    cross = [r for r in body if r.split(",")[2] not in CONFLICT]
    own = [r for r in body if r.split(",")[2] in CONFLICT]
    open(path.replace(".csv", "_cross.csv"), "w").write("\n".join([head] + cross) + "\n")
    open(path.replace(".csv", "_own.csv"), "w").write("\n".join([head] + own) + "\n")
    print(path, len(cross), "cross", len(own), "own")
