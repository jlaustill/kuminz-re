"""Round 43 fix: remove the text the round 39 / 41 fix scripts duplicated in task 046. Their edit guard (`new in t and
old not in t`) let a second run re-apply an edit whose new text contains the old. Idempotent.
usage: dedupe_task046.py <task 046 path>"""
import sys

p = sys.argv[1]
t = open(p).read()
pairs = [
    # round 39 fix: two lead lines added twice
    ("  - `fuel_rpm_compensated_offset_upper_limit` / `_lower_limit` render under `(short)` casts: `i16` candidates.\n"
     "  - `audit_cal_suffixes.py` calls RAM 0x3feed0-0x40a048 WORKING_RAM; it is the ROM copy.\n" * 2,
     "  - `fuel_rpm_compensated_offset_upper_limit` / `_lower_limit` render under `(short)` casts: `i16` candidates.\n"
     "  - `audit_cal_suffixes.py` calls RAM 0x3feed0-0x40a048 WORKING_RAM; it is the ROM copy.\n"),
    # round 41 fix: the proof sentence's second half appended twice
    ("(the index derivation reads the same in both). That proves\n"
     "    statement structure: the canonical form drops the bracket indexes, the index set-up and the temp names, so it\n"
     "    does not check which record or cylinder an access indexes (the index derivation reads the same in both).\n",
     "(the index derivation reads the same in both).\n"),
]
for old, new in pairs:
    if old in t:
        assert t.count(old) == 1, old[:60]
        t = t.replace(old, new)
# round 41 fix: the checks block added twice
start = "- **Checks (fix commit):**\n  - The parameter ID table resolves none of the new rows"
first = t.find(start)
second = t.find(start, first + 1)
if second != -1:
    end = t.find("- **Leads:**", second)
    assert t[first:second] == t[second:end], "the two blocks differ"
    t = t[:second] + t[end:]
# round 41 fix: the whole proof sentence appended twice (the pattern above matched an older garble only)
chunk = (" That proves field identity and\n"
         "    statement structure: the canonical form drops the bracket indexes, the index set-up and the temp names, so it\n"
         "    does not check which record or cylinder an access indexes (the index derivation reads the same in both).")
if t.count(chunk * 2) == 1:
    t = t.replace(chunk * 2, chunk)
open(p, "w").write(t)
print("deduped")
