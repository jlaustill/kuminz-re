#!/bin/bash
# Round 97: copy the round 97 scripts, maps, proofs, batch results (and their pre-remap copies), the workflow script and
# the agents' scratch folders into session_folder/round97/, add the round 97 verify logs (and any batch result of 300 KB
# or more) to the large-files tarball and refresh the PR body copy. Left out: .cpp / .hpp / .log / .diff, files of 300 KB
# and more, binaries, the frozen copies the agents read (frozen/), the build-copy snapshots (base_*.cpp are .cpp), the
# CLAUDE.md snapshots, and copies of tracked files (damaged_f/: the stage F CSVs saved to compare two refresh runs;
# gv_head_cm550.csv: the committed globals; pr_body_before*: the PR body before an edit).
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15
D=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay
EXCLUDE='\.cpp$|\.hpp$|\.log$|\.diff$|\.err$|\.elf$|\.bin$|\.o$|\.so$|__pycache__|\.pyc$|\.rep/|\.gbf$|\.pdf$'
mkdir -p "$D/session_folder/round97"
(cd "$W/r97" && find . -type f -size -300k | sed 's|^\./||' | grep -vE "$EXCLUDE" \
    | grep -vE '^frozen/|_CLAUDE_before_|^damaged_f/|^gv_head|^pr_body_before|_head(_g)?\.csv$') > "$W/r97_list.txt"
rsync -a --files-from="$W/r97_list.txt" "$W/r97/" "$D/session_folder/round97/"
echo "round97: $(wc -l < "$W/r97_list.txt") files"
rm -rf "$W/largetar"
mkdir -p "$W/largetar"
tar -xJf "$D/session_folder_large_files.tar.xz" -C "$W/largetar"
for log in "$W"/r97/verify_r97*.log; do
    base=$(basename "$log" .log)
    cp "$log" "$W/largetar/${base/verify_r97/verify_round97_}.log"
done
# batch results over the 300 KB cap (batch_N2.json, 317 KB: the N2 proposals, roles and verdicts)
for big in "$W"/r97/batch_*.json; do
    if [ "$(stat -c %s "$big")" -ge 307200 ]; then cp "$big" "$W/largetar/round97_$(basename "$big")"; fi
done
cd "$W/largetar"
ls | sort -V > ../large_order.txt
tar --sort=name -cJf ../large_new.tar.xz -T ../large_order.txt
cp ../large_new.tar.xz "$D/session_folder_large_files.tar.xz"
xargs wc -c < ../large_order.txt | grep -v ' total$' > "$D/session_folder_large_files.txt"
cp /home/linux/.claude/jobs/374b0424/tmp/egr/pr_body.md "$D/pr_body.md"
echo "large tarball: $(wc -l < ../large_order.txt) files, $(stat -c %s "$D/session_folder_large_files.tar.xz") bytes"
du -sh "$D/session_folder/round97" | cut -f1
