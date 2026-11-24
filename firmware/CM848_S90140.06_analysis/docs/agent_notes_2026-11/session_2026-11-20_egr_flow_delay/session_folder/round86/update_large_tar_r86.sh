#!/bin/bash
# Add the round 86 verify logs to the session's large-files tarball (sorted, reproducible) and its listing, copy the
# round 86 scratch (no .cpp / .hpp / .log / .diff) into session_folder/round86/, and refresh the session's copy of the PR body.
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15
D=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay
mkdir -p "$D/session_folder/round86"
ls "$W/r86" | grep -vE '\.cpp$|\.hpp$|\.log$|\.diff$|^__pycache__$|^download$|^apdreg\.txt$|^82527ao\.txt$|^probe|^research$|^frozen$|^wave2$|^function_definitions_pre_r86\.csv$|^fd_after2\.csv$|^find_memory_mentions\.sh$|^refresh_transcript_r8[45]\.sh$|^split_memory_index_r8[45]\.py$|^install_rebuilt_memory\.py$' > "$W/r86_list.txt"
rsync -a -r --files-from="$W/r86_list.txt" "$W/r86/" "$D/session_folder/round86/"
rm -rf "$W/largetar"
mkdir -p "$W/largetar"
tar -xJf "$D/session_folder_large_files.tar.xz" -C "$W/largetar"
for pair in verify_r86a_cm550:verify_round86a_cm550 build_r86a_cm848:build_round86a_cm848 verify_r86c_cm550:verify_round86c_cm550 verify_r86c2_cm550:verify_round86c2_cm550; do
    if [ -f "$W/r86/${pair%%:*}.log" ]; then cp "$W/r86/${pair%%:*}.log" "$W/largetar/${pair##*:}.log"; fi
done
cd "$W/largetar"
ls | sort -V > ../large_order.txt
tar --sort=name -cJf ../large_new.tar.xz -T ../large_order.txt
cp ../large_new.tar.xz "$D/session_folder_large_files.tar.xz"
xargs wc -c < ../large_order.txt | grep -v ' total$' > "$D/session_folder_large_files.txt"
cp /home/linux/.claude/jobs/374b0424/tmp/egr/pr_body.md "$D/pr_body.md"
ls "$D/session_folder/round86" | wc -l
wc -l < ../large_order.txt
