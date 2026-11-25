#!/bin/bash
# Round 93: exercise apply_r93.py on a scratch copy of both firmwares' CSVs with a synthetic batch (a counterpart
# rename, a twin rename, a global rename, a new global row, an enum member renamed in both firmwares, a refuted
# element), then check idempotency and the refusals (a prefix on a twin, a duplicate name, a wrong _cal).
# usage: test_apply_r93.sh <repo>
set -euo pipefail
REPO=$(cd "$1" && pwd)
W=/home/linux/.claude/jobs/374b0424/tmp/w15/r93
S=$W/apply_test
rm -rf "$S"
for fw in CM550_J90350.00_analysis CM848_S90140.06_analysis; do
    mkdir -p "$S/repo/firmware/$fw/output"
    cp "$REPO/firmware/$fw/output/"*.csv "$S/repo/firmware/$fw/output/"
done
mkdir -p "$S/out"
cp "$W/apply_r93.py" "$S/apply_r93.py"       # a copy: no overrides file next to it
cat > "$S/batch_T.json" <<'EOF'
{"batch": "T", "proposal": {"batch": "T", "summary": "synthetic", "skipped": [],
 "functions": [
  {"address": "0x201d6", "current_name": "cm550_FUN_000201d6", "proposed_name": "cm550_clearTestBit", "role": "r", "discriminator": "d", "relation": "counterpart", "plate_comment": "Clears a bit, for the test.", "evidence": "e", "confidence": "high"},
  {"address": "0x212b2", "current_name": "mc68k_FUN_000212b2", "proposed_name": "dispatchTestMessages", "role": "r", "discriminator": "d", "relation": "twin", "cm848_address": "0x00538eb0", "cm848_current_name": "registerJ1939ReceiveHandler", "plate_comment": "Twin for the test.", "evidence": "e", "confidence": "high"},
  {"address": "0x2142c", "current_name": "cm550_FUN_0002142c", "proposed_name": "cm550_refutedName", "role": "r", "discriminator": "d", "relation": "standalone", "plate_comment": "x", "evidence": "e", "confidence": "low"}],
 "globals": [
  {"firmware": "CM550", "address": "0x0080d330", "current_name": "final_fueling_state", "proposed_name": "final_fueling_state_test", "proposed_type": "FUELING_STATE", "comment": "renamed, for the test", "evidence": "e", "confidence": "high"},
  {"firmware": "CM550", "address": "0x00800aa0", "current_name": "", "proposed_name": "test_bit_array", "proposed_type": "dword[4]", "comment": "a new row, with a comma", "evidence": "e", "confidence": "high"}],
 "enum_members": [
  {"firmware": "both", "enum_name": "FUELING_STATE", "value": 37, "current_member": "FUELING_STATE_UNIDENTIFIED_37", "proposed_member": "FUELING_STATE_TEST_SPEED", "comment": "a test, with a comma", "evidence": "e", "confidence": "high"}]},
 "verdict": {"batch": "T", "verdicts": [
  {"kind": "function", "firmware": "CM550", "address": "0x000201d6", "verdict": "CONFIRMED", "final_name": "cm550_clearTestBit", "reason": "ok"},
  {"kind": "function", "firmware": "both", "address": "0x212b2", "verdict": "AMENDED", "final_name": "dispatchTestMessagesAmended", "final_relation": "twin", "final_cm848_address": "0x538eb0", "final_comment": "Amended twin comment.", "reason": "ok"},
  {"kind": "function", "firmware": "CM550", "address": "0x2142c", "verdict": "REFUTED", "final_name": "cm550_FUN_0002142c", "reason": "no"},
  {"kind": "global", "firmware": "CM550", "address": "0x80d330", "verdict": "CONFIRMED", "final_name": "final_fueling_state_test", "final_type": "FUELING_STATE", "reason": "ok"},
  {"kind": "global", "firmware": "CM550", "address": "0x800aa0", "verdict": "CONFIRMED", "final_name": "test_bit_array", "final_type": "dword[4]", "reason": "ok"},
  {"kind": "enum_member", "firmware": "both", "address": "FUELING_STATE:37", "verdict": "CONFIRMED", "final_name": "FUELING_STATE_TEST_SPEED", "reason": "ok"}]}}
EOF
echo "-- apply"; python3 "$S/apply_r93.py" "$S/repo" "$S/out" "$S/batch_T.json"
cp "$S/out/map_r93_cm550.csv" "$S/out/map_keep.csv"
echo "-- second run (idempotent)"; python3 "$S/apply_r93.py" "$S/repo" "$S/out" "$S/batch_T.json" | tail -1
cmp "$S/out/map_r93_cm550.csv" "$S/out/map_keep.csv" && echo "map kept"
echo "-- rows"
grep -n "^0x000201d6,\|^0x000212b2,\|^0x0002142c," "$S/repo/firmware/CM550_J90350.00_analysis/output/function_renames.csv" | cut -c1-200
grep -n "^0x00538eb0," "$S/repo/firmware/CM848_S90140.06_analysis/output/function_renames.csv" | grep -o ".\{120\}$"
grep -n "^0x0080d330,\|^0x00800aa0," "$S/repo/firmware/CM550_J90350.00_analysis/output/global_variables.csv" | cut -c1-230
grep -n "^FUELING_STATE,37," "$S/repo/firmware/CM550_J90350.00_analysis/output/enums.csv" "$S/repo/firmware/CM848_S90140.06_analysis/output/enums.csv" | sed 's|.*/firmware/||' | cut -c1-330
cat "$S/out/map_r93_cm550.csv" "$S/out/map_r93_cm848.csv"
for fw in CM550_J90350.00_analysis CM848_S90140.06_analysis; do
    for f in function_renames.csv global_variables.csv enums.csv function_definitions.csv local_variables.csv; do
        a=$(grep -c . "$REPO/firmware/$fw/output/$f"); b=$(grep -c . "$S/repo/firmware/$fw/output/$f")
        echo "$fw $f lines $a -> $b; changed lines $(diff "$REPO/firmware/$fw/output/$f" "$S/repo/firmware/$fw/output/$f" | grep -c '^>' || true)"
    done
done
echo "-- refusals"
python3 - "$S" <<'EOF'
import copy, json, subprocess, sys
s = sys.argv[1]
base = json.load(open(f"{s}/batch_T.json"))
def run(name, mutate):
    d = copy.deepcopy(base)
    mutate(d)
    json.dump(d, open(f"{s}/batch_bad.json", "w"))
    r = subprocess.run(["python3", f"{s}/apply_r93.py", f"{s}/repo", f"{s}/out_bad", f"{s}/batch_bad.json"], capture_output=True, text=True)
    print(name, "->", "exit", r.returncode, "|", r.stdout.strip().split("\n")[1][:150] if r.returncode else "NOT REFUSED")
import os
os.makedirs(f"{s}/out_bad", exist_ok=True)
def twin_prefix(d): d["verdict"]["verdicts"][1]["final_name"] = "cm550_dispatchTestMessages"
def duplicate(d): d["verdict"]["verdicts"][0]["final_name"] = "cm550_runLowSpeedGovernor"
def bad_cal(d): d["verdict"]["verdicts"][4]["final_name"] = "test_bit_array_cal"
def bad_type(d): d["verdict"]["verdicts"][4]["final_type"] = "no_such_type_t[4]"
def no_prefix(d): d["verdict"]["verdicts"][0]["final_name"] = "clearTestBitTwo"
def instruction(d): d["verdict"]["verdicts"][1]["final_comment"] = "APPEND to the current comment: | the twin"
for n, f in (("twin with a prefix", twin_prefix), ("duplicate function name", duplicate), ("_cal outside the mirror", bad_cal), ("unknown type", bad_type), ("counterpart without a prefix", no_prefix), ("an instruction as a comment", instruction)):
    run(n, f)
EOF
