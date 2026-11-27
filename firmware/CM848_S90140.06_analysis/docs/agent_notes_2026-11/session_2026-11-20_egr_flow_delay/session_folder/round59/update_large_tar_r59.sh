#!/bin/bash
# Add the round 59 verify logs to the session's large-files tarball (sorted, reproducible) and its listing, copy the
# round 59 scratch (no .cpp / .hpp / .log / .diff) into session_folder/round59/, and refresh the session's copy of the PR body.
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15
D=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay
mkdir -p "$D/session_folder/round59"
ls "$W/r59" | grep -vE '\.cpp$|\.hpp$|\.log$|\.diff$|^__pycache__$' > "$W/r59_list.txt"
rsync -a --files-from="$W/r59_list.txt" "$W/r59/" "$D/session_folder/round59/"
rm -rf "$W/largetar"
mkdir -p "$W/largetar"
tar -xJf "$D/session_folder_large_files.tar.xz" -C "$W/largetar"
for pair in verify_r59a:verify_round59a; do
    if [ -f "$W/r59/${pair%%:*}.log" ]; then cp "$W/r59/${pair%%:*}.log" "$W/largetar/${pair##*:}.log"; fi
done
cd "$W/largetar"
ls | sort -V > ../large_order.txt
tar --sort=name -cJf ../large_new.tar.xz -T ../large_order.txt
cp ../large_new.tar.xz "$D/session_folder_large_files.tar.xz"
xargs wc -c < ../large_order.txt | grep -v ' total$' > "$D/session_folder_large_files.txt"
cp /home/linux/.claude/jobs/374b0424/tmp/egr/pr_body.md "$D/pr_body.md"
ls "$D/session_folder/round59" | wc -l
wc -l < ../large_order.txt
