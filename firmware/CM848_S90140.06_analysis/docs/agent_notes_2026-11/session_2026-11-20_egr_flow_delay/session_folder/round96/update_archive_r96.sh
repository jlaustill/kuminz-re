#!/bin/bash
# Round 96: copy the round 95 scripts, maps, proofs, batch results, the workflow script, the agents' scratch folders and
# the MPC555 manual excerpts into session_folder/round96/, add the round 95 verify logs to the large-files tarball and
# refresh the PR body copy. Left out: .cpp / .hpp / .log / .diff, files of 300 KB and more, binaries, the frozen copies
# the agents read (frozen/), the build-copy snapshots (base_*.cpp / stage_*_build*.cpp are .cpp), the CLAUDE.md
# snapshots, and the MPC555 manual itself (18 MB PDF; its text excerpts are kept).
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15
D=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay
EXCLUDE='\.cpp$|\.hpp$|\.log$|\.diff$|\.err$|\.elf$|\.bin$|\.o$|\.so$|__pycache__|\.pyc$|\.rep/|\.gbf$|\.pdf$'
mkdir -p "$D/session_folder/round96"
(cd "$W/r96" && find . -type f -size -300k | sed 's|^\./||' | grep -vE "$EXCLUDE" \
    | grep -vE '^frozen/|_CLAUDE_before_|^proof_pre/|_head(_g)?\.csv$|_before(_q5)?\.(csv|md)$|^gv_before|^fd550_head') > "$W/r96_list.txt"
rsync -a --files-from="$W/r96_list.txt" "$W/r96/" "$D/session_folder/round96/"
echo "round96: $(wc -l < "$W/r96_list.txt") files"
rm -rf "$W/largetar"
mkdir -p "$W/largetar"
tar -xJf "$D/session_folder_large_files.tar.xz" -C "$W/largetar"
for log in "$W"/r96/verify_r96*.log; do
    base=$(basename "$log" .log)
    cp "$log" "$W/largetar/${base/verify_r96/verify_round96_}.log"
done
# batch results over the 300 KB cap (batch_N2.json, 317 KB: the N2 proposals, roles and verdicts)
for big in "$W"/r96/batch_*.json; do
    if [ "$(stat -c %s "$big")" -ge 307200 ]; then cp "$big" "$W/largetar/round96_$(basename "$big")"; fi
done
cd "$W/largetar"
ls | sort -V > ../large_order.txt
tar --sort=name -cJf ../large_new.tar.xz -T ../large_order.txt
cp ../large_new.tar.xz "$D/session_folder_large_files.tar.xz"
xargs wc -c < ../large_order.txt | grep -v ' total$' > "$D/session_folder_large_files.txt"
cp /home/linux/.claude/jobs/374b0424/tmp/egr/pr_body.md "$D/pr_body.md"
echo "large tarball: $(wc -l < ../large_order.txt) files, $(stat -c %s "$D/session_folder_large_files.tar.xz") bytes"
du -sh "$D/session_folder/round96" | cut -f1
