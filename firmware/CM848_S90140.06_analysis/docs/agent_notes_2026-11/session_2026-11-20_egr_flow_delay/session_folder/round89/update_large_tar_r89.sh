#!/bin/bash
# Add the round 89 verify logs to the session's large-files tarball (sorted, reproducible) and its listing, copy the
# round 89 scratch (no .cpp / .hpp / .log / .diff, no frozen copies or work folders) into session_folder/round89/, and
# refresh the session's copy of the PR body.
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15
D=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay
mkdir -p "$D/session_folder/round89"
ls "$W/r89" | grep -vE '\.cpp$|\.hpp$|\.log$|\.diff$|^__pycache__$|^frozen$|^frozen2$|^work$|^work2$' > "$W/r89_list.txt"
rsync -a -r --files-from="$W/r89_list.txt" "$W/r89/" "$D/session_folder/round89/"
rm -rf "$W/largetar"
mkdir -p "$W/largetar"
tar -xJf "$D/session_folder_large_files.tar.xz" -C "$W/largetar"
for log in "$W"/r89/verify_r89*.log; do
    base=$(basename "$log" .log)
    cp "$log" "$W/largetar/${base/verify_r89/verify_round89}.log"
done
cd "$W/largetar"
ls | sort -V > ../large_order.txt
tar --sort=name -cJf ../large_new.tar.xz -T ../large_order.txt
cp ../large_new.tar.xz "$D/session_folder_large_files.tar.xz"
xargs wc -c < ../large_order.txt | grep -v ' total$' > "$D/session_folder_large_files.txt"
cp /home/linux/.claude/jobs/374b0424/tmp/egr/pr_body.md "$D/pr_body.md"
ls "$D/session_folder/round89" | wc -l
wc -l < ../large_order.txt
