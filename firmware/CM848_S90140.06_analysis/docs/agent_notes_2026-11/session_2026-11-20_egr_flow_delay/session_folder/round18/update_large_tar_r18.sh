#!/bin/bash
# Add the round 18 build / verify logs and the e2m audit to the session's large-files tarball (sorted, reproducible)
# and its listing, and copy the round 18 scratch (no .cpp / .log / dry runs / the audit) into session_folder/round18/.
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15
D=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay
mkdir -p "$D/session_folder/round18"
ls "$W/r18" | grep -vE '\.cpp$|\.log$|_dry|\.asm$|^audit_r18b\.csv$' > "$W/r18_list.txt"
rsync -a --files-from="$W/r18_list.txt" "$W/r18/" "$D/session_folder/round18/"
rm -rf "$W/largetar"
mkdir -p "$W/largetar"
tar -xJf "$D/session_folder_large_files.tar.xz" -C "$W/largetar"
cp "$W"/r18/build_r18*.log "$W/largetar/"
cp "$W/r18/audit_r18b.csv" "$W/largetar/e2m_audit_round18b.csv"
if [ -f "$W/r18/verify_r18.log" ]; then cp "$W/r18/verify_r18.log" "$W/largetar/verify_round18.log"; fi
cd "$W/largetar"
ls | sort -V > ../large_order.txt
tar --sort=name -cJf ../large_new.tar.xz -T ../large_order.txt
cp ../large_new.tar.xz "$D/session_folder_large_files.tar.xz"
xargs wc -c < ../large_order.txt | grep -v ' total$' > "$D/session_folder_large_files.txt"
ls "$D/session_folder/round18" | wc -l
wc -l < ../large_order.txt
