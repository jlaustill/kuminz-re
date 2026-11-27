#!/bin/bash
# Round 94: regenerate both firmwares' headers, run the closing checks (headers compile, _cal audit) and the tool
# test suites. usage: closing_r94.sh <repo>
set -uo pipefail
REPO=$(cd "$1" && pwd)
W=/home/linux/.claude/jobs/374b0424/tmp/w15
cd "$REPO"
echo "== headers"
python3 firmware/scripts/rename_waves/regen_headers.py firmware/CM550_J90350.00_analysis/output firmware/CM848_S90140.06_analysis/output 2>&1 | tail -4
echo "== closing checks"
python3 $W/r75/closing_checks_r75.py "$REPO" 2>&1 | tail -8
echo "== tests"
cd "$REPO/firmware/scripts"
for t in test_e2m_block_addresses test_e2m_name_audit test_rename_waves test_lookup_tables test_disasm_tools; do
    f=$(ls $t.py rename_waves/$t.py tests/$t.py 2>/dev/null | head -1)
    if [ -z "$f" ]; then echo "$t: not found"; continue; fi
    r=$(/usr/bin/python3 "$f" 2>&1 | tail -1)
    echo "$t: $r"
done
cd "$REPO"
bash firmware/script_tests/run_tests.sh 2>&1 | tail -2
