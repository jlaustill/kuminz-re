#!/bin/bash
# Add the round 91 verify logs to the session's large-files tarball and its listing, copy the round 91 scratch (no
# .cpp / .hpp / .log / .diff, no CSV snapshots or re-run copies) into session_folder/round91/, refresh the PR body copy.
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15
D=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay
mkdir -p "$D/session_folder/round91"
(cd "$W/r91" && find . -type f -size -300k | sed 's|^\./||' \
    | grep -vE '\.cpp$|\.hpp$|\.log$|\.diff$|\.err$|__pycache__|/venv/|/proj/|\.rep/|\.gbf$|^snap/|^again/|^refresh_references_new\.py$') \
    > "$W/r91_list.txt"
rsync -a --files-from="$W/r91_list.txt" "$W/r91/" "$D/session_folder/round91/"
rm -rf "$W/largetar"
mkdir -p "$W/largetar"
tar -xJf "$D/session_folder_large_files.tar.xz" -C "$W/largetar"
for log in "$W"/r91/verify_r91*.log; do
    base=$(basename "$log" .log)
    cp "$log" "$W/largetar/${base/verify_r91/verify_round91}.log"
done
cd "$W/largetar"
ls | sort -V > ../large_order.txt
tar --sort=name -cJf ../large_new.tar.xz -T ../large_order.txt
cp ../large_new.tar.xz "$D/session_folder_large_files.tar.xz"
xargs wc -c < ../large_order.txt | grep -v ' total$' > "$D/session_folder_large_files.txt"
cp /home/linux/.claude/jobs/374b0424/tmp/egr/pr_body.md "$D/pr_body.md"
find "$D/session_folder/round91" -type f | wc -l
du -sh "$D/session_folder/round91" | cut -f1
wc -l < ../large_order.txt
