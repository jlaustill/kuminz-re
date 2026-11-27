#!/bin/bash
# Add the round 85 verify logs to the session's large-files tarball (sorted, reproducible) and its listing, copy the
# round 85 scratch (no .cpp / .hpp / .log / .diff) into session_folder/round85/, and refresh the session's copy of the PR body.
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15
D=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay
mkdir -p "$D/session_folder/round85"
ls "$W/r85" | grep -vE '\.cpp$|\.hpp$|\.log$|\.diff$|^__pycache__$|^download$|^apdreg\.txt$|^82527ao\.txt$|^probe|^research$|^find_memory_mentions\.sh$|^refresh_transcript_r8[45]\.sh$|^split_memory_index_r8[45]\.py$|^install_rebuilt_memory\.py$' > "$W/r85_list.txt"
rsync -a --files-from="$W/r85_list.txt" "$W/r85/" "$D/session_folder/round85/"
mkdir -p "$D/session_folder/round85/stack_argument_survey"
for f in "$W"/r85/research/stack-args-survey/*.py "$W"/r85/research/stack-args-survey/{classes,handback_table,compact,global}.txt; do
    if [ -f "$f" ]; then cp "$f" "$D/session_folder/round85/stack_argument_survey/"; fi
done
rm -rf "$W/largetar"
mkdir -p "$W/largetar"
tar -xJf "$D/session_folder_large_files.tar.xz" -C "$W/largetar"
for pair in verify_r85a_cm550:verify_round85a_cm550 verify_r85b_cm550:verify_round85b_cm550; do
    if [ -f "$W/r85/${pair%%:*}.log" ]; then cp "$W/r85/${pair%%:*}.log" "$W/largetar/${pair##*:}.log"; fi
done
cd "$W/largetar"
ls | sort -V > ../large_order.txt
tar --sort=name -cJf ../large_new.tar.xz -T ../large_order.txt
cp ../large_new.tar.xz "$D/session_folder_large_files.tar.xz"
xargs wc -c < ../large_order.txt | grep -v ' total$' > "$D/session_folder_large_files.txt"
cp /home/linux/.claude/jobs/374b0424/tmp/egr/pr_body.md "$D/pr_body.md"
ls "$D/session_folder/round85" | wc -l
wc -l < ../large_order.txt
