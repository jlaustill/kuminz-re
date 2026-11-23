#!/bin/bash
# Add the round 64 verify logs to the session's large-files tarball (sorted, reproducible) and its listing, copy the
# round 64 scratch (no .cpp / .hpp / .log / .diff) into session_folder/round64/, and refresh the session's copy of the PR body.
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15
D=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay
mkdir -p "$D/session_folder/round64"
ls "$W/r64" | grep -vE '\.cpp$|\.hpp$|\.log$|\.diff$|^__pycache__$' > "$W/r64_list.txt"
rsync -a --files-from="$W/r64_list.txt" "$W/r64/" "$D/session_folder/round64/"
rm -rf "$W/largetar"
mkdir -p "$W/largetar"
tar -xJf "$D/session_folder_large_files.tar.xz" -C "$W/largetar"
for pair in verify_r64a:verify_round64a verify_r64b:verify_round64b verify_r64c:verify_round64c verify_r64c2:verify_round64c2 verify_r64c3:verify_round64c3 verify_r64c4:verify_round64c4 verify_cm550_r64c:verify_round64c_cm550; do
    if [ -f "$W/r64/${pair%%:*}.log" ]; then cp "$W/r64/${pair%%:*}.log" "$W/largetar/${pair##*:}.log"; fi
done
cd "$W/largetar"
ls | sort -V > ../large_order.txt
tar --sort=name -cJf ../large_new.tar.xz -T ../large_order.txt
cp ../large_new.tar.xz "$D/session_folder_large_files.tar.xz"
xargs wc -c < ../large_order.txt | grep -v ' total$' > "$D/session_folder_large_files.txt"
cp /home/linux/.claude/jobs/374b0424/tmp/egr/pr_body.md "$D/pr_body.md"
ls "$D/session_folder/round64" | wc -l
wc -l < ../large_order.txt
