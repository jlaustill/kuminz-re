#!/bin/bash
# Add the round 79 verify logs to the session's large-files tarball (sorted, reproducible) and its listing, copy the
# round 79 scratch (no .cpp / .hpp / .log / .diff) into session_folder/round79/, and refresh the session's copy of the PR body.
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15
D=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay
mkdir -p "$D/session_folder/round79"
ls "$W/r79" | grep -vE '\.cpp$|\.hpp$|\.log$|\.diff$|^__pycache__$|^download$|^apdreg\.txt$|^82527ao\.txt$|^probe' > "$W/r79_list.txt"
rsync -a --files-from="$W/r79_list.txt" "$W/r79/" "$D/session_folder/round79/"
rm -rf "$W/largetar"
mkdir -p "$W/largetar"
tar -xJf "$D/session_folder_large_files.tar.xz" -C "$W/largetar"
for pair in verify_r79a_cm550:verify_round79a_cm550 verify_r79a2_cm550:verify_round79a2_cm550 verify_r79a3_cm550:verify_round79a3_cm550 build_r79a_cm848_script_check:build_round79a_cm848_script_check; do
    if [ -f "$W/r79/${pair%%:*}.log" ]; then cp "$W/r79/${pair%%:*}.log" "$W/largetar/${pair##*:}.log"; fi
done
cd "$W/largetar"
ls | sort -V > ../large_order.txt
tar --sort=name -cJf ../large_new.tar.xz -T ../large_order.txt
cp ../large_new.tar.xz "$D/session_folder_large_files.tar.xz"
xargs wc -c < ../large_order.txt | grep -v ' total$' > "$D/session_folder_large_files.txt"
cp /home/linux/.claude/jobs/374b0424/tmp/egr/pr_body.md "$D/pr_body.md"
ls "$D/session_folder/round79" | wc -l
wc -l < ../large_order.txt
