import subprocess,sys
ROM='/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
T='/home/linux/.claude/jobs/374b0424/tmp/w15/r93/tools/m68k.py'
for a in sys.argv[1:]:
    s=int(a,16)
    out=subprocess.run(['python3',T,ROM,'%x'%s,'%x'%(s+14)],capture_output=True,text=True).stdout.splitlines()
    print(' | '.join(l.split(None,2)[-1] if len(l.split(None,2))>2 else l for l in out[:3]))
