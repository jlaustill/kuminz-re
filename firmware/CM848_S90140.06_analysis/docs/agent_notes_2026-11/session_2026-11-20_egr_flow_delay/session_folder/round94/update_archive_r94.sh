#!/bin/bash
# Round 94: copy the round 94 scripts, maps, proofs, batch results and workflow scripts into session_folder/round94/,
# the agents' scratch folders that this round applied (round 93's F1 / J1 / J2 / D1 -> round93/scratch/, round 94's
# L1-L4 -> round94/scratch/), add the round 94 verify logs to the large-files tarball and refresh the PR body copy.
# Left out: .cpp / .hpp / .log / .diff, files of 300 KB and more (the L4 judge's 9.6 MB objdump cache), binaries, the
# frozen copies the agents read (frozen/), the dry runs' CSV copies (real_dry_run/, leads_dry_run/), and the copies
# of the committed .cpp files (head_*.cpp / post_*.cpp).
set -euo pipefail
W=/home/linux/.claude/jobs/374b0424/tmp/w15
D=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay
EXCLUDE='\.cpp$|\.hpp$|\.log$|\.diff$|\.err$|\.elf$|\.bin$|\.o$|\.so$|__pycache__|\.pyc$|\.rep/|\.gbf$'
mkdir -p "$D/session_folder/round94" "$D/session_folder/round93/scratch"
(cd "$W/r94" && find . -type f -size -300k | sed 's|^\./||' | grep -vE "$EXCLUDE" \
    | grep -vE '^frozen/|^real_dry_run/|^leads_dry_run/|^dry_run/|^apply_test/') > "$W/r94_list.txt"
rsync -a --files-from="$W/r94_list.txt" "$W/r94/" "$D/session_folder/round94/"
(cd "$W/r93/scratch" && find . -type f -size -300k | sed 's|^\./||' | grep -vE "$EXCLUDE") > "$W/r93_scratch_list.txt"
rsync -a --files-from="$W/r93_scratch_list.txt" "$W/r93/scratch/" "$D/session_folder/round93/scratch/"
echo "round94: $(wc -l < "$W/r94_list.txt") files; round93/scratch: $(wc -l < "$W/r93_scratch_list.txt") files"
rm -rf "$W/largetar"
mkdir -p "$W/largetar"
tar -xJf "$D/session_folder_large_files.tar.xz" -C "$W/largetar"
for log in "$W"/r94/verify_r94*.log; do
    base=$(basename "$log" .log)
    cp "$log" "$W/largetar/${base/verify_r94/verify_round94_}.log"
done
cd "$W/largetar"
ls | sort -V > ../large_order.txt
tar --sort=name -cJf ../large_new.tar.xz -T ../large_order.txt
cp ../large_new.tar.xz "$D/session_folder_large_files.tar.xz"
xargs wc -c < ../large_order.txt | grep -v ' total$' > "$D/session_folder_large_files.txt"
cp /home/linux/.claude/jobs/374b0424/tmp/egr/pr_body.md "$D/pr_body.md"
echo "large tarball: $(wc -l < ../large_order.txt) files, $(stat -c %s "$D/session_folder_large_files.tar.xz") bytes"
du -sh "$D/session_folder/round94" "$D/session_folder/round93/scratch" | cut -f1 | tr '\n' ' '; echo
