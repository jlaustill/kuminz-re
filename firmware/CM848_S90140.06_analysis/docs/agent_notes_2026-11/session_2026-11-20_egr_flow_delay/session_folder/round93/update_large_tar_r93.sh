#!/bin/bash
# Add the round 93 verify logs and big tables to the session's large-files tarball and its listing, copy the round 93
# scripts, maps and proofs into session_folder/round93/ and refresh the PR body copy.
# Left out of the copy: .cpp / .hpp / .log / .diff, files of 300 KB and more, binaries, the frozen copies the agents
# read (frozen/), the apply test's CSV copies (apply_test/), the copy of a CSV from git history, and the agents'
# scratch folders (scratch/: agents are still writing there; it is archived with the round that applies them).
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15
D=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay
mkdir -p "$D/session_folder/round93"
(cd "$W/r93" && find . -type f -size -300k | sed 's|^\./||' \
    | grep -vE '\.cpp$|\.hpp$|\.log$|\.diff$|\.err$|\.elf$|\.bin$|\.o$|\.so$|\.mjs$|__pycache__|/venv/|/proj/|\.rep/|\.gbf$|\.keep$|\.warnings$' \
    | grep -vE '^frozen/|^apply_test/|^scratch/|^cm848_function_renames_before_r91\.csv$|^snapshot_lines\.txt$|^map_r93sw_rows\.txt$') > "$W/r93_list.txt"
rsync -a --files-from="$W/r93_list.txt" "$W/r93/" "$D/session_folder/round93/"
rm -rf "$W/largetar"
mkdir -p "$W/largetar"
tar -xJf "$D/session_folder_large_files.tar.xz" -C "$W/largetar"
for log in "$W"/r93/verify_r93*.log; do
    base=$(basename "$log" .log)
    cp "$log" "$W/largetar/${base/verify_r93/verify_round93_}.log"
done
for big in untyped_width_scan_r93.tsv call_sites_all_r93.txt token_diff_r93ty_cm550.txt token_diff_r93te_cm550.txt; do
    if [ -f "$W/r93/$big" ] && [ "$(stat -c %s "$W/r93/$big")" -ge 300000 ]; then
        cp "$W/r93/$big" "$W/largetar/round93_$big"
    fi
done
cd "$W/largetar"
ls | sort -V > ../large_order.txt
tar --sort=name -cJf ../large_new.tar.xz -T ../large_order.txt
cp ../large_new.tar.xz "$D/session_folder_large_files.tar.xz"
xargs wc -c < ../large_order.txt | grep -v ' total$' > "$D/session_folder_large_files.txt"
cp /home/linux/.claude/jobs/374b0424/tmp/egr/pr_body.md "$D/pr_body.md"
find "$D/session_folder/round93" -type f | wc -l
du -sh "$D/session_folder/round93" | cut -f1
wc -l < ../large_order.txt
