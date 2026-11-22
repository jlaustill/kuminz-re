#!/bin/bash
# Add the round 20 build / verify logs to the session's large-files tarball (sorted, reproducible) and its listing,
# copy the round 20 scratch (no .cpp / .log / dry runs / temp diffs) into session_folder/round20/, and refresh the
# session's copy of the PR body.
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15
D=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay
mkdir -p "$D/session_folder/round20"
ls "$W/r20" | grep -vE '\.cpp$|\.log$|_dry|^fold\.txt$|^fnew\.txt$' > "$W/r20_list.txt"
rsync -a --files-from="$W/r20_list.txt" "$W/r20/" "$D/session_folder/round20/"
rm -rf "$W/largetar"
mkdir -p "$W/largetar"
tar -xJf "$D/session_folder_large_files.tar.xz" -C "$W/largetar"
cp "$W"/r20/build_r20*.log "$W/largetar/"
if [ -f "$W/r20/verify_r20.log" ]; then cp "$W/r20/verify_r20.log" "$W/largetar/verify_round20.log"; fi
cd "$W/largetar"
ls | sort -V > ../large_order.txt
tar --sort=name -cJf ../large_new.tar.xz -T ../large_order.txt
cp ../large_new.tar.xz "$D/session_folder_large_files.tar.xz"
xargs wc -c < ../large_order.txt | grep -v ' total$' > "$D/session_folder_large_files.txt"
cp /home/linux/.claude/jobs/374b0424/tmp/egr/pr_body.md "$D/pr_body.md"
ls "$D/session_folder/round20" | wc -l
wc -l < ../large_order.txt
