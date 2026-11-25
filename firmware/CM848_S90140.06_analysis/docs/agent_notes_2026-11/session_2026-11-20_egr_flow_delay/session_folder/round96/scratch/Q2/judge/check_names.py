import sys,re
F='/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen'
W='/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware'
files={
 'cm550_fn':[F+'/cm550/function_renames.csv','head_cm550_functions.csv',W+'/CM550_J90350.00_analysis/output/function_renames.csv'],
 'cm848_fn':[F+'/cm848/function_renames.csv','head_cm848_functions.csv',W+'/CM848_S90140.06_analysis/output/function_renames.csv'],
 'cm550_gv':[F+'/cm550/global_variables.csv','head_cm550_globals.csv',W+'/CM550_J90350.00_analysis/output/global_variables.csv'],
 'cm848_gv':[F+'/cm848/global_variables.csv','head_cm848_globals.csv',W+'/CM848_S90140.06_analysis/output/global_variables.csv'],
}
def names(paths):
    out={}
    for p in paths:
        for l in open(p,errors='replace'):
            if l.startswith('0x'):
                parts=l.split(',')
                if len(parts)>1: out.setdefault(parts[1].strip(),set()).add(parts[0].lower())
    return out
N={k:names(v) for k,v in files.items()}
for n in sys.argv[1:]:
    hits=[(k,sorted(N[k][n])) for k in N if n in N[k]]
    print(n, hits if hits else 'FREE')
