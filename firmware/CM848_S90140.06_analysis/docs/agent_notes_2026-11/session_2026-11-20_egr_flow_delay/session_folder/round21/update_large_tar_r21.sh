#!/bin/bash
# Add the round 21 build / verify logs to the session's large-files tarball (sorted, reproducible) and its listing,
# copy the round 21 scratch (no .cpp / .log / dry runs / temp diffs / the copy of the committed importer) into
# session_folder/round21/, and refresh the session's copy of the PR body.
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15
D=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay
mkdir -p "$D/session_folder/round21"
ls "$W/r21" | grep -vE '\.cpp$|\.log$|_dry|^o\.txt$|^n\.txt$|^ApplyStructures\.head\.java$' > "$W/r21_list.txt"
rsync -a --files-from="$W/r21_list.txt" "$W/r21/" "$D/session_folder/round21/"
rm -rf "$W/largetar"
mkdir -p "$W/largetar"
tar -xJf "$D/session_folder_large_files.tar.xz" -C "$W/largetar"
cp "$W"/r21/build_r21*.log "$W"/r21/build_cm550_*.log "$W/largetar/"
if [ -f "$W/r21/verify_r21.log" ]; then cp "$W/r21/verify_r21.log" "$W/largetar/verify_round21.log"; fi
cd "$W/largetar"
ls | sort -V > ../large_order.txt
tar --sort=name -cJf ../large_new.tar.xz -T ../large_order.txt
cp ../large_new.tar.xz "$D/session_folder_large_files.tar.xz"
xargs wc -c < ../large_order.txt | grep -v ' total$' > "$D/session_folder_large_files.txt"
cp /home/linux/.claude/jobs/374b0424/tmp/egr/pr_body.md "$D/pr_body.md"
ls "$D/session_folder/round21" | wc -l
wc -l < ../large_order.txt
