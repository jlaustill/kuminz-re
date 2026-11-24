"""Add an --own-only option to r88/refresh_other_csvs.py (a copy of r87's): apply every map to its own firmware
only, for an old name that the two firmwares rename differently. Idempotent. usage: add_own_only.py <script>"""
import sys

p = sys.argv[1]
s = open(p).read()
if "own_only" in s:
    print("already")
    raise SystemExit
s = s.replace('usage: refresh_other_csvs.py <repo> --cm550 <map>... --cm848 <map>..."""',
              'usage: refresh_other_csvs.py <repo> [--own-only] --cm550 <map>... --cm848 <map>...\n'
              '--own-only (round 88): apply every map to its own firmware only - for an old name that two firmwares '
              'rename differently."""')
old = ('repo, maps, current_fw = sys.argv[1], {"cm550": [], "cm848": []}, None\n'
       'for a in sys.argv[2:]:\n'
       '    if a in ("--cm550", "--cm848"):\n')
new = ('repo, maps, current_fw = sys.argv[1], {"cm550": [], "cm848": []}, None\n'
       'own_only = False\n'
       'for a in sys.argv[2:]:\n'
       '    if a == "--own-only":\n'
       '        own_only = True\n'
       '    elif a in ("--cm550", "--cm848"):\n')
assert s.count(old) == 1
s = s.replace(old, new)
old2 = '            targets = ("cm550", "cm848") if is_function(fw, r["address"]) else (fw,)\n'
new2 = '            targets = ("cm550", "cm848") if is_function(fw, r["address"]) and not own_only else (fw,)\n'
assert s.count(old2) == 1
s = s.replace(old2, new2)
open(p, "w").write(s)
print("own-only added")
