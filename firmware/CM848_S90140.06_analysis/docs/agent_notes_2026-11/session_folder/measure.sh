#!/usr/bin/env bash
# measure.sh <old.cpp> <new.cpp>: artifact counts before / after
old=$1; new=$2
for p in '(word \*)&' '(word \*)0x' '(word \*)((int)&' 'table_interp_args_t' 'WARNING' 'u_[A-Za-z0-9#;^]*_000'; do
  printf '%-26s %6s -> %6s\n' "$p" "$(grep -c "$p" "$old")" "$(grep -c "$p" "$new")"
done
printf '%-26s %6s -> %6s\n' "_name globals (distinct)" \
  "$(grep -oE '\b_[a-z][a-z0-9_]{3,}\b' "$old" | sort -u | wc -l)" \
  "$(grep -oE '\b_[a-z][a-z0-9_]{3,}\b' "$new" | sort -u | wc -l)"
echo "new _name globals:"
comm -13 <(grep -oE '\b_[a-z][a-z0-9_]{3,}\b' "$old" | sort -u) <(grep -oE '\b_[a-z][a-z0-9_]{3,}\b' "$new" | sort -u) | head -20
