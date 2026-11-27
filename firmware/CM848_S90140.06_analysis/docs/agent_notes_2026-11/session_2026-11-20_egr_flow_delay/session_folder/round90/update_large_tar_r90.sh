#!/bin/bash
# Add the round 90 verify logs and the three big audit tables (regenerable: e2m_name_audit.py / cm550_e2m_census_r90.py)
# to the session's large-files tarball (sorted, reproducible) and its listing, copy the rest of the round 90 scratch
# (no .cpp / .hpp / .log / .diff, no duplicate audit copy) into session_folder/round90/, and refresh the PR body copy.
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15
D=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay
BIG='^(audit_cm550_r90\.csv|audit_cm848_r90\.csv|census_v64t6_r90\.tsv)$'
mkdir -p "$D/session_folder/round90"
(cd "$W/r90" && find . -type f | sed 's|^\./||' | grep -vE '\.cpp$|\.hpp$|\.log$|\.diff$|__pycache__|^audit_cm848_r90b\.csv$|^g848_before_refresh\.csv$|^g550_head\.csv$' \
    | grep -vE "$BIG") > "$W/r90_list.txt"
rsync -a --files-from="$W/r90_list.txt" "$W/r90/" "$D/session_folder/round90/"
rm -rf "$W/largetar"
mkdir -p "$W/largetar"
tar -xJf "$D/session_folder_large_files.tar.xz" -C "$W/largetar"
for log in "$W"/r90/verify_r90*.log; do
    base=$(basename "$log" .log)
    cp "$log" "$W/largetar/${base/verify_r90/verify_round90}.log"
done
for big in audit_cm550_r90.csv audit_cm848_r90.csv census_v64t6_r90.tsv; do
    cp "$W/r90/$big" "$W/largetar/round90_$big"
done
cd "$W/largetar"
ls | sort -V > ../large_order.txt
tar --sort=name -cJf ../large_new.tar.xz -T ../large_order.txt
cp ../large_new.tar.xz "$D/session_folder_large_files.tar.xz"
xargs wc -c < ../large_order.txt | grep -v ' total$' > "$D/session_folder_large_files.txt"
cp /home/linux/.claude/jobs/374b0424/tmp/egr/pr_body.md "$D/pr_body.md"
find "$D/session_folder/round90" -type f | wc -l
wc -l < ../large_order.txt
