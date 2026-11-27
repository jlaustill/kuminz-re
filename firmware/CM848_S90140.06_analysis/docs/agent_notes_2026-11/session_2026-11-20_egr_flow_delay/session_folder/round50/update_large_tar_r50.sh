#!/bin/bash
# Add the round 50 build / verify logs to the session's large-files tarball (sorted, reproducible) and its listing,
# copy the round 50 scratch (no .cpp / .log / the disassembly segment seg.bin) into session_folder/round50/, and
# refresh the session's copy of the PR body.
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15
D=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay
mkdir -p "$D/session_folder/round50"
ls "$W/r50" | grep -vE '\.cpp$|\.log$|^seg\.bin$' > "$W/r50_list.txt"
rsync -a --files-from="$W/r50_list.txt" "$W/r50/" "$D/session_folder/round50/"
rm -rf "$W/largetar"
mkdir -p "$W/largetar"
tar -xJf "$D/session_folder_large_files.tar.xz" -C "$W/largetar"
for f in "$W"/r50/build_r50*.log; do if [ -f "$f" ]; then cp "$f" "$W/largetar/"; fi; done
true
if [ -f "$W/r50/verify_r50a.log" ]; then cp "$W/r50/verify_r50a.log" "$W/largetar/verify_round50.log"; fi
if [ -f "$W/r50/verify_r50a2.log" ]; then cp "$W/r50/verify_r50a2.log" "$W/largetar/verify_round50b.log"; fi
cd "$W/largetar"
ls | sort -V > ../large_order.txt
tar --sort=name -cJf ../large_new.tar.xz -T ../large_order.txt
cp ../large_new.tar.xz "$D/session_folder_large_files.tar.xz"
xargs wc -c < ../large_order.txt | grep -v ' total$' > "$D/session_folder_large_files.txt"
cp /home/linux/.claude/jobs/374b0424/tmp/egr/pr_body.md "$D/pr_body.md"
ls "$D/session_folder/round50" | wc -l
wc -l < ../large_order.txt
