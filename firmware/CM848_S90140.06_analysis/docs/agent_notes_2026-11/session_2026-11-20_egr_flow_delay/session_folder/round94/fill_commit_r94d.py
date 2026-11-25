"""Round 94: put the stage D proof summary into commit_r94d.txt. usage: fill_commit_r94d.py <commit_r94d.txt>"""
import sys

p = sys.argv[1]
s = open(p).read()
proof = """- Both: the function sets are unchanged (CM550 704, CM848 1968); every token change is in the maps (71 CM550 renames,
  the CM848 array); no function changed its statement count; the caller census shows no rise; no old name is left in
  the code; no row sits newly inside another row's span.
- The _cal audit (with the new window) is 0 hard / 0 soft / 14 missing in CM550 and 0 / 0 / 206 in CM848 - the same as
  before, so every named row in the extended window now carries _cal.
- Headers regenerated (g++ 0 errors); the five Python suites (test_e2m_block_addresses with the new 0x01001000 /
  0x01001489 / 0x0100148A cases) and the 109 JUnit tests pass; kuminz-cli and clip-core build, clip-core's test passes."""
assert "PROOF_PLACEHOLDER" in s
open(p, "w").write(s.replace("PROOF_PLACEHOLDER", proof))
print("filled")
