#!/bin/bash
# For each access to the target, print the next instructions that consume the loaded register.
cd /home/linux/code/kuminz-re/firmware/CM848_S90140.06_analysis
dis() { powerpc-linux-gnu-objdump -D -b binary -m powerpc -EB --adjust-vma=$2 $1 2>/dev/null; }
{ dis originals/cm848_rom.bin 0x0; dis originals/cm848_flash2_live.bin 0x00500000; } > /home/linux/.claude/jobs/f6a06670/tmp/all.dis
for a in 1e628 1f530 20894 2857c 28688 28eb4 28f58 28fd8 29140 29448 4045c 40620 407d0 40b50 40dec 41158 41220 414a0 41694 42574 45f08 51319c 515504 515674 5231fc 524738 52477c 525224 5256e0 525db4 532d40 5331e4; do
  line=$(grep -n "^ *$a:" /home/linux/.claude/jobs/f6a06670/tmp/all.dis | head -1 | cut -d: -f1)
  reg=$(sed -n "${line}p" /home/linux/.claude/jobs/f6a06670/tmp/all.dis | awk '{print $NF}' | cut -d, -f1)
  # show first 6 later instructions that mention the register
  uses=$(sed -n "$((line+1)),$((line+40))p" /home/linux/.claude/jobs/f6a06670/tmp/all.dis | grep -E "[ ,]$reg(,|$|\))" | head -3 | awk -F'\t' '{print $3" "$4}' | tr -s ' ' | paste -sd ';')
  echo "$a $reg -> $uses"
done
