#!/bin/sh
# every absolute reference into the three engine protection tables and the fault logs
T=/home/linux/.claude/jobs/374b0424/tmp/w15/r93/tools/abs_refs.py
W=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay
A=""
a=$((0x807032)); while [ $a -lt $((0x807176)) ]; do A="$A $(printf '0x%x' $a)"; a=$((a+2)); done
python3 $T $W $A
A=""
a=$((0x80d0dc)); while [ $a -lt $((0x80d27a)) ]; do A="$A $(printf '0x%x' $a)"; a=$((a+2)); done
python3 $T $W $A
A=""
a=$((0x8057c0)); while [ $a -lt $((0x8058ce)) ]; do A="$A $(printf '0x%x' $a)"; a=$((a+2)); done
python3 $T $W $A
A=""
a=$((0x805562)); while [ $a -lt $((0x8057be)) ]; do A="$A $(printf '0x%x' $a)"; a=$((a+2)); done
python3 $T $W $A
