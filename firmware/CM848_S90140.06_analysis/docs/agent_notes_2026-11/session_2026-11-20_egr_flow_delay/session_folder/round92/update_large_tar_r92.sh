#!/bin/bash
# Add the round 92 verify logs and the CM550 audit table to the session's large-files tarball and its listing, copy
# the round 92 scratch (no .cpp / .hpp / .log / .diff, files under 300 KB, no build or environment folders) into
# session_folder/round92/, and refresh the PR body copy.
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15
D=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay
mkdir -p "$D/session_folder/round92"
(cd "$W/r92" && find . -type f -size -300k | sed 's|^\./||' \
    | grep -vE '\.cpp$|\.hpp$|\.log$|\.diff$|\.err$|\.elf$|\.bin$|\.o$|\.so$|__pycache__|/venv/|/proj/|\.rep/|\.gbf$|\.keep$') > "$W/r92_list.txt"
rsync -a --files-from="$W/r92_list.txt" "$W/r92/" "$D/session_folder/round92/"
rm -rf "$W/largetar"
mkdir -p "$W/largetar"
tar -xJf "$D/session_folder_large_files.tar.xz" -C "$W/largetar"
for log in "$W"/r92/verify_r92*.log "$W"/r92/pilot_build.log; do
    base=$(basename "$log" .log)
    cp "$log" "$W/largetar/${base/verify_r92/verify_round92}.log"
done
mv "$W/largetar/pilot_build.log" "$W/largetar/round92_pilot_build.log"
cp "$W/r92/audit_cm550_r92.csv" "$W/largetar/round92_audit_cm550_r92.csv"
cd "$W/largetar"
ls | sort -V > ../large_order.txt
tar --sort=name -cJf ../large_new.tar.xz -T ../large_order.txt
cp ../large_new.tar.xz "$D/session_folder_large_files.tar.xz"
xargs wc -c < ../large_order.txt | grep -v ' total$' > "$D/session_folder_large_files.txt"
cp /home/linux/.claude/jobs/374b0424/tmp/egr/pr_body.md "$D/pr_body.md"
find "$D/session_folder/round92" -type f | wc -l
du -sh "$D/session_folder/round92" | cut -f1
wc -l < ../large_order.txt
