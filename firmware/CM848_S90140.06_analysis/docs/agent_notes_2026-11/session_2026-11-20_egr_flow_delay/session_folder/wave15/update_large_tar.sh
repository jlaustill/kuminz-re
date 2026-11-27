#!/bin/bash
# Add the round 4 build / verify logs to the session's large-files tarball (sorted, reproducible) and its listing.
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15
E=/home/linux/.claude/jobs/374b0424/tmp/egr
D=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay
rm -rf "$W/largetar"
mkdir -p "$W/largetar"
tar -xJf "$D/session_folder_large_files.tar.xz" -C "$W/largetar"
cp "$E/build15.log" "$W"/build1[6-9].log "$W/build20.log" "$W/largetar/"
cp "$W/verify15.log" "$W/largetar/verify4.log"
cp "$W/build21.log" "$W/largetar/"
cp "$W/verify16.log" "$W/largetar/verify5.log"
cd "$W/largetar"
ls | sort -V > ../large_order.txt
tar --sort=name -cJf ../large_new.tar.xz -T ../large_order.txt
cp ../large_new.tar.xz "$D/session_folder_large_files.tar.xz"
xargs wc -c < ../large_order.txt | grep -v ' total$' > "$D/session_folder_large_files.txt"
tail -3 "$D/session_folder_large_files.txt"
wc -l < ../large_order.txt
