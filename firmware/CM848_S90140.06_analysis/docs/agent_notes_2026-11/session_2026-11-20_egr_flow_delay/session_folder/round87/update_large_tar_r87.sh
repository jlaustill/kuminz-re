#!/bin/bash
# Add the round 87 verify logs to the session's large-files tarball (sorted, reproducible) and its listing, copy the
# round 87 scratch (no .cpp / .hpp / .log / .diff) into session_folder/round87/, and refresh the session's copy of the PR body.
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15
D=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay
mkdir -p "$D/session_folder/round87"
ls "$W/r87" | grep -vE '\.cpp$|\.hpp$|\.log$|\.diff$|^__pycache__$|^download$|^apdreg\.txt$|^82527ao\.txt$|^probe|^research$|^frozen$|^work$|^wave2$|^function_definitions_pre_r87\.csv$|^fd_after2\.csv$|^local_variables_backup_r87d\.csv$|^find_memory_mentions\.sh$|^refresh_transcript_r8[45]\.sh$|^split_memory_index_r8[45]\.py$|^install_rebuilt_memory\.py$' > "$W/r87_list.txt"
rsync -a -r --files-from="$W/r87_list.txt" "$W/r87/" "$D/session_folder/round87/"
rm -rf "$W/largetar"
mkdir -p "$W/largetar"
tar -xJf "$D/session_folder_large_files.tar.xz" -C "$W/largetar"
for pair in verify_r87a_cm550:verify_round87a_cm550 verify_r87a_cm848:verify_round87a_cm848 verify_r87b_cm550:verify_round87b_cm550 verify_r87b_cm848:verify_round87b_cm848; do
    if [ -f "$W/r87/${pair%%:*}.log" ]; then cp "$W/r87/${pair%%:*}.log" "$W/largetar/${pair##*:}.log"; fi
done
cd "$W/largetar"
ls | sort -V > ../large_order.txt
tar --sort=name -cJf ../large_new.tar.xz -T ../large_order.txt
cp ../large_new.tar.xz "$D/session_folder_large_files.tar.xz"
xargs wc -c < ../large_order.txt | grep -v ' total$' > "$D/session_folder_large_files.txt"
cp /home/linux/.claude/jobs/374b0424/tmp/egr/pr_body.md "$D/pr_body.md"
ls "$D/session_folder/round87" | wc -l
wc -l < ../large_order.txt
