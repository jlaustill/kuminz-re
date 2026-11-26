#!/bin/bash
# Round 97 stage F: the whole CSV pipeline from the stage E commit - enum rename, the two function rows, overrides,
# forced types, apply, struct headers, prototypes, doubled-tag fix, hand edits, refresh maps (without the 13 rows
# whose old label is a bare e2m mnemonic) and the refresh. usage: stage_f_pipeline.sh <repo>
set -euo pipefail
cd "$1"
W=/home/linux/.claude/jobs/374b0424/tmp/w15/r97
B="$W/batch_R5.json $W/batch_R6.json $W/batch_R7.json"
python3 $W/rename_enum_r97f.py .
python3 $W/add_rows_r97f.py .
python3 $W/make_overrides_r97_f.py . $W/overrides_r97.json $B > $W/make_overrides_f.log 2>&1
python3 $W/force_types_r97f.py $W/overrides_r97.json
rm -rf $W/apply_f && mkdir -p $W/apply_f
python3 $W/apply_r97.py . $W/apply_f $B > $W/apply_f/apply_log.txt 2>&1
tail -1 $W/apply_f/apply_log.txt
python3 $W/struct_headers_r97f.py . > /dev/null
python3 $W/prototypes_r97f.py . $W/batch_R5.json $W/batch_R6.json
python3 $W/fix_double_tag_r97.py firmware/CM550_J90350.00_analysis/output/*.csv firmware/CM848_S90140.06_analysis/output/*.csv | grep -v " 0$" || true
python3 $W/hand_edits_r97f.py . > /dev/null
rm -rf $W/maps_f && mkdir -p $W/maps_f
printf 'firmware,address,name,old_label\ncm550,,ENGINE_PROTECTION_TASK,PROTECTION_STATE\n' > $W/maps_f/hand_rows_f.csv
python3 $W/filter_maps_r96.py . $W/apply_f/map_r94_cm550.csv $W/apply_f/map_r94_cm848.csv $W/maps_f $W/maps_f/hand_rows_f.csv
python3 $W/drop_mnemonic_rows_r97f.py $W/maps_f
bash /home/linux/.claude/jobs/374b0424/tmp/w15/r93/refresh_r93.sh . $W/maps_f/map_own_cm550.csv $W/maps_f/map_own_cm848.csv > $W/maps_f/refresh_log.txt 2>&1
grep -v "^\s*$" $W/maps_f/refresh_log.txt | grep -c "" || true
python3 $W/post_refresh_r97f.py .
bash /home/linux/.claude/jobs/374b0424/tmp/w15/r93/refresh_r93.sh . $W/maps_e/map_own_cm550.csv $W/maps_e/map_own_cm848.csv > $W/maps_f/refresh_e_again_log.txt 2>&1
# review fixes from the statement-count check (wf_d98cbafa-77a), the repeated history notes, then F2
python3 $W/review_fixes_r97f.py . $W/fd550_head_f.csv
python3 $W/repeated_notes_r97f.py --fix firmware/CM550_J90350.00_analysis/output/*.csv firmware/CM848_S90140.06_analysis/output/*.csv > /dev/null
python3 $W/f2_edits_r97.py .
python3 $W/filter_maps_r96.py . $W/maps_f2/src_cm550.csv $W/maps_f2/src_cm848.csv $W/maps_f2
bash /home/linux/.claude/jobs/374b0424/tmp/w15/r93/refresh_r93.sh . $W/maps_f2/map_own_cm550.csv $W/maps_f2/map_own_cm848.csv > $W/maps_f2/refresh_log.txt 2>&1
