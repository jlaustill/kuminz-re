#!/bin/bash
# Add the round 63 verify logs to the session's large-files tarball (sorted, reproducible) and its listing, copy the
# round 63 scratch (no .cpp / .hpp / .log / .diff) into session_folder/round63/, and refresh the session's copy of the PR body.
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15
D=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay
mkdir -p "$D/session_folder/round63"
ls "$W/r63" | grep -vE '\.cpp$|\.hpp$|\.log$|\.diff$|^__pycache__$' > "$W/r63_list.txt"
rsync -a --files-from="$W/r63_list.txt" "$W/r63/" "$D/session_folder/round63/"
rm -rf "$W/largetar"
mkdir -p "$W/largetar"
tar -xJf "$D/session_folder_large_files.tar.xz" -C "$W/largetar"
for pair in verify_r63a:verify_round63a verify_r63a2:verify_round63a2 verify_r63b:verify_round63b verify_r63b2:verify_round63b2 verify_r63c:verify_round63c verify_r63d:verify_round63d verify_cm550_r63d:verify_round63d_cm550 cm550_base_build:cm550_base_build_round63; do
    if [ -f "$W/r63/${pair%%:*}.log" ]; then cp "$W/r63/${pair%%:*}.log" "$W/largetar/${pair##*:}.log"; fi
done
cd "$W/largetar"
ls | sort -V > ../large_order.txt
tar --sort=name -cJf ../large_new.tar.xz -T ../large_order.txt
cp ../large_new.tar.xz "$D/session_folder_large_files.tar.xz"
xargs wc -c < ../large_order.txt | grep -v ' total$' > "$D/session_folder_large_files.txt"
cp /home/linux/.claude/jobs/374b0424/tmp/egr/pr_body.md "$D/pr_body.md"
ls "$D/session_folder/round63" | wc -l
wc -l < ../large_order.txt
