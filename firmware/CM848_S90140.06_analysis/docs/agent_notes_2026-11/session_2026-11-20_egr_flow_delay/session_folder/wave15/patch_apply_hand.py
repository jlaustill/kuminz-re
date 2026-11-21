"""Patch apply_W15.py with the main session's hand adjustments (names, comment fixes, NOT_TWINS, drift markers)."""
import sys

p = sys.argv[1]
s = open(p).read()
old = '''HOLD = set()                 # addresses held after the review (filled from the reports)
WRONG_OLD_COMMENTS = set()   # addresses whose old comment an agent showed to be wrong
RENAMED_BY_HAND = {}         # address -> replacement new name (a fixed abbreviation / collision)'''
new = '''HOLD = set()                 # addresses held after the review (filled from the reports)
WRONG_OLD_COMMENTS = set()   # addresses whose old comment an agent showed to be wrong
# address -> replacement new name, decided in the main session after reading every rename against its quote
RENAMED_BY_HAND = {
    # 68 characters; the record text is "IVS switch status when Throttle_Validation_Process_Error became active"
    "0x003fddac": "idle_validation_switch_state_at_throttle_validation_error_cal",
    # PGN 65249 byte 19 (0x3fae62) is "percent torque at peak torque, point 5"; pairs with ..._peak_torque_speed
    "0x0005c380": "engine_retarder_configuration_peak_torque_percent",
    # the four low speed governor gain sets (4 words P, I, D, jerk, selected by the gain state): named as sets, so
    # the struct stage only changes the type; the agents named the first word (bins 2 / 3) or the set (bin 5)
    "0x004070e6": "low_speed_governor_default_gain_set",
    "0x004070aa": "low_speed_governor_aggressive_gain_set",
    "0x00408eda": "low_speed_governor_middle_gear_gain_set",
    "0x00408ed2": "low_speed_governor_high_gear_gain_set",
}
COMMENT_APPEND = {a: " The row is the first word of a 4-word gain set (proportional, integral, derivative, jerk) that "
                     "the low speed governor gain state selects (0 default, 1 aggressive, 2 middle gear, 3 high gear, "
                     "4 the TSC1 set); cm848_updateGovernorSetpointParameters loads the four words."
                  for a in ("0x004070e6", "0x004070aa", "0x00408eda", "0x00408ed2")}
# text fixes in the agents' comments: bin 3 showed the anti-theft status header 0xdc2800 is the PDU1 PGN 56320
COMMENT_FIXES = [("PGN 56360", "PGN 56320")]
# old names that also exist in CM550 for an unrelated role (not twins): renamed on CM848 alone
NOT_TWINS = {"0x0040b53e"}   # CM550 0x800090 governor_integral_accumulator is a pointer in validateServiceDataLength'''
assert old in s
s = s.replace(old, new)
old2 = '''    if re.search(r"(?<![A-Za-z0-9_])" + re.escape(r["old"]) + r"(?![A-Za-z0-9_])", shared_text):'''
new2 = '''    if r["address"] not in NOT_TWINS and \\
            re.search(r"(?<![A-Za-z0-9_])" + re.escape(r["old"]) + r"(?![A-Za-z0-9_])", shared_text):'''
assert old2 in s
s = s.replace(old2, new2)
old3 = '''    new_comment = " ".join((r.get("comment") or r.get("evidence") or "").split()) + f" (was {r['old']})"'''
new3 = '''    text = " ".join((r.get("comment") or r.get("evidence") or "").split()) + COMMENT_APPEND.get(r["address"], "")
    for before, after in COMMENT_FIXES:
        text = text.replace(before, after)
    new_comment = text + f" (was {r['old']})"'''
assert old3 in s
s = s.replace(old3, new3)
old4 = '''    note = " ".join(r["e2m_note"].split())
    lines[i] = ",".join([a, name, typ, f"{comment} | e2m: {note}" if comment else f"e2m: {note}"])
    noted += 1'''
new4 = '''    note = " ".join(r["e2m_note"].split())
    for before, after in COMMENT_FIXES:
        note = note.replace(before, after)
    lines[i] = ",".join([a, name, typ, f"{comment} | e2m: {note}" if comment else f"e2m: {note}"])
    noted += 1
# drift / uncertain rows: a short reviewed marker, so a later wave does not pick them up again
marked = 0
for r in results:
    if r["verdict"] not in ("drift", "uncertain"):
        continue
    item = bins[(r["_bin"], r["address"])]
    i = index.get(r["address"])
    a, name, typ, comment = (lines[i].split(",", 3) + [""])[:4]
    if name != r["old"] or "| e2m:" in comment:
        continue
    what = ("resolves here but does not match the code (layout drift" if r["verdict"] == "drift"
            else "resolves here; the code does not show the role (uncertain")
    note = f"e2m {item['block']} +{item['offset']} {item['record']} {what}, rename wave 15)"
    lines[i] = ",".join([a, name, typ, f"{comment} | e2m: {note}" if comment else f"e2m: {note}"])
    marked += 1'''
assert old4 in s
s = s.replace(old4, new4)
old5 = '''print(f"applied {len(apply_globals)} global renames, keep notes on {noted} rows")'''
new5 = ('''print(f"applied {len(apply_globals)} global renames, keep notes on {noted} rows, '''
        '''drift / uncertain notes on {marked}")''')
assert old5 in s
s = s.replace(old5, new5)
open(p, "w").write(s)
print("patched")
