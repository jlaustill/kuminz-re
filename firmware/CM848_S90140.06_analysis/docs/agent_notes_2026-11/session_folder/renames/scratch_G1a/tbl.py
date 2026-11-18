import sys
sys.path.insert(0,'/home/linux/.claude/jobs/d55ae3c6/tmp/renames/scratch_G1a')
from rd import r

def axis(a):
    n=r(a,2,False)//2
    return [r(a+2+2*i,2) for i in range(n)]

def table2(xa,ya,ga,show=True):
    xs=axis(xa); ys=axis(ya)
    nx,ny=len(xs),len(ys)
    g=[[r(ga+2*(j*nx+i),2) for i in range(nx)] for j in range(ny)]
    if show:
        print('x(%d):'%nx,xs)
        print('y(%d):'%ny,ys)
        for j in range(ny):
            print('y=%6d:'%ys[j],g[j])
    return xs,ys,g

def table1(xa,va):
    xs=axis(xa)
    n=r(va,2,False)//2
    vs=[r(va+2+2*i,2) for i in range(n)]
    print('x:',xs)
    print('v:',vs)
    return xs,vs

if __name__=='__main__':
    k=sys.argv[1]
    a=[int(x,16) for x in sys.argv[2:]]
    if k=='2': table2(*a)
    else: table1(*a)
