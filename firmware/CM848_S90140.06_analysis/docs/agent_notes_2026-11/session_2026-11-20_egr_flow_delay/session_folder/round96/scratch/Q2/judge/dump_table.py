import sys
ram=open('firmware/CM550_J90350.00_analysis/firmware/J90350.00.ram.bin','rb').read()
def r(a,n): return ram[a-0x800000:a-0x800000+n]
cnt=r(0x801e1a,2)
print("count bytes 0x801e1a:", cnt.hex())
for i in range(32):
    e=r(0x801d5a+6*i,6)
    pgn=int.from_bytes(e[:2],'big'); h=int.from_bytes(e[2:],'big')
    print(i, "%5d 0x%04x 0x%06x"%(pgn,pgn,h))
for a,n in [(0x801d3c,2),(0x801e28,2),(0x801f4c,2),(0x803458,8),(0x801efa,8),(0x80da0e,2),(0x8035de,8),(0x804fb4,8),(0x80a9dc,2),(0x804fc6,2),(0x807bf6,2),(0x801c78,2),(0x80d9ee,2),(0x80da01,1),(0x80da0b,1),(0x803cb8,4),(0x8089a4,2)]:
    print(hex(a), r(a,n).hex())
