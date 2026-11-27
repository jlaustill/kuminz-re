#!/bin/bash
# Add the round 88 verify logs to the session's large-files tarball (sorted, reproducible) and its listing, copy the
# round 88 scratch (no .cpp / .hpp / .log / .diff, no frozen copies, agent work folders or C++ build trees) into
# session_folder/round88/, and refresh the session's copy of the PR body.
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15
D=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay
mkdir -p "$D/session_folder/round88"
ls "$W/r88" | grep -vE '\.cpp$|\.hpp$|\.log$|\.diff$|^__pycache__$|^frozen$|^frozen2$|^work$|^work2$|^clip-build$|^cli-build$|^mutation$' > "$W/r88_list.txt"
rsync -a -r --files-from="$W/r88_list.txt" "$W/r88/" "$D/session_folder/round88/"
rm -rf "$W/largetar"
mkdir -p "$W/largetar"
tar -xJf "$D/session_folder_large_files.tar.xz" -C "$W/largetar"
for log in "$W"/r88/verify_r88*.log; do
    base=$(basename "$log" .log)
    cp "$log" "$W/largetar/${base/verify_r88/verify_round88}.log"
done
cd "$W/largetar"
ls | sort -V > ../large_order.txt
tar --sort=name -cJf ../large_new.tar.xz -T ../large_order.txt
cp ../large_new.tar.xz "$D/session_folder_large_files.tar.xz"
xargs wc -c < ../large_order.txt | grep -v ' total$' > "$D/session_folder_large_files.txt"
cp /home/linux/.claude/jobs/374b0424/tmp/egr/pr_body.md "$D/pr_body.md"
ls "$D/session_folder/round88" | wc -l
wc -l < ../large_order.txt
