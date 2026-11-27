#!/bin/bash
# Add the round 72 verify logs to the session's large-files tarball (sorted, reproducible) and its listing, copy the
# round 72 scratch (no .cpp / .hpp / .log / .diff) into session_folder/round72/, and refresh the session's copy of the PR body.
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15
D=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay
mkdir -p "$D/session_folder/round72"
ls "$W/r72" | grep -vE '\.cpp$|\.hpp$|\.log$|\.diff$|^__pycache__$' > "$W/r72_list.txt"
rsync -a --files-from="$W/r72_list.txt" "$W/r72/" "$D/session_folder/round72/"
rm -rf "$W/largetar"
mkdir -p "$W/largetar"
tar -xJf "$D/session_folder_large_files.tar.xz" -C "$W/largetar"
for pair in build_cm550_base:build_round72_cm550_base build_cm550_r72a:build_round72a_cm550 build_cm550_r72a3:build_round72a3_cm550 verify_cm550_r72a:verify_round72a_cm550 verify_r72a:verify_round72a build_cm550_r72b1:build_round72b1_cm550 build_r72b1:build_round72b1 verify_cm550_r72b:verify_round72b_cm550 verify_r72b:verify_round72b build_cm550_r72b2:build_round72b2_cm550 verify_r72b2:verify_round72b2; do
    if [ -f "$W/r72/${pair%%:*}.log" ]; then cp "$W/r72/${pair%%:*}.log" "$W/largetar/${pair##*:}.log"; fi
done
cd "$W/largetar"
ls | sort -V > ../large_order.txt
tar --sort=name -cJf ../large_new.tar.xz -T ../large_order.txt
cp ../large_new.tar.xz "$D/session_folder_large_files.tar.xz"
xargs wc -c < ../large_order.txt | grep -v ' total$' > "$D/session_folder_large_files.txt"
cp /home/linux/.claude/jobs/374b0424/tmp/egr/pr_body.md "$D/pr_body.md"
ls "$D/session_folder/round72" | wc -l
wc -l < ../large_order.txt
