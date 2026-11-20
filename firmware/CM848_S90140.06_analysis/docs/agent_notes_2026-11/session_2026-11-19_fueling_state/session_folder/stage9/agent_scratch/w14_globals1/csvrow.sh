#!/bin/bash
# usage: csvrow.sh <regex> : grep global_variables.csv, function_renames.csv, others
D=/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output
for f in global_variables.csv function_renames.csv enums.csv structure_definitions.csv labels.csv arrays.csv constants.csv local_variables.csv function_definitions.csv; do
  grep -n -E "$1" $D/$f 2>/dev/null | sed "s|^|$f:|" | cut -c1-${2:-400}
done
