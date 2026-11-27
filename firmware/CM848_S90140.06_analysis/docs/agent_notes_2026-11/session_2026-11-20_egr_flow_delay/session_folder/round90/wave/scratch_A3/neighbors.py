import csv,sys
rows=[]
with open(sys.argv[1]) as f:
    r=csv.reader(f); next(r)
    for row in r:
        try: a=int(row[0],16)
        except: continue
        rows.append((a,row))
rows.sort(key=lambda x:x[0])
for t in sys.argv[2:]:
    ta=int(t,16)
    print('=====',t)
    idx=[i for i,(a,_) in enumerate(rows) if a<=ta]
    i=idx[-1] if idx else 0
    for j in range(max(0,i-3),min(len(rows),i+5)):
        a,row=rows[j]
        mark='>>' if a==ta else '  '
        print(mark,'0x%08x'%a,row[1],row[2],(row[3] if len(row)>3 else '')[:150])
