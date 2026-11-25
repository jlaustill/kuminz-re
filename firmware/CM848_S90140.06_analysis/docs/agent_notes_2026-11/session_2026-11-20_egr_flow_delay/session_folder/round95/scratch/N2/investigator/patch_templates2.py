"""Scratch helper: shorten the table comment / evidence templates of gen_output.py (scratch file only)."""
p = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/scratch/N2/investigator/gen_output.py"
s = open(p).read()
rep = [
    ('''            content = f"the dump holds byte count {t['dump_count']} then {len(pts)} {unit or 'raw'} values ({shown})"''',
     '''            content = f"dump: byte count {t['dump_count']}, {len(pts)} points ({pts[0]} .. {pts[-1]})"'''),
    ('''        content = (f"ROM beyond the 256 KB dump, so no value: word[{words}] from the e2m layout (the next record {nr[0]} starts at {nr[1]})" if nr else "ROM beyond the dump")''',
     '''        content = (f"ROM beyond the dump (no values): word[{words}] by the e2m layout (next record {nr[0]} at {nr[1]})" if nr else "ROM beyond the dump")'''),
    ('''            content += f", as its description says ('{DESC_COUNT[mn]}')"''',
     '''            content += f", as its text says ('{DESC_COUNT[mn]}')"'''),
    ('''    comment = (f"e2m {block} +{off} {mn} '{desc}' ({unit or 'no unit'}; e2m type {typ}): the {role} of {users_txt}; {content}.{cm848}{inside_txt} ({was(cur, a)}; PR #53 round 95)")''',
     '''    comment = (f"e2m {block} +{off} {mn} '{desc}' ({unit or 'no unit'}" + (f"; e2m type {typ}" if mn in ('DPFPTB', 'DPTVOTB', 'CBDDCT', 'CBDI2DCT') else "") + f"): the {role} of {users_txt}; {content}.{cm848}{inside_txt} ({was(cur, a)}; PR #53 round 95)")'''),
    ('''        ev = f"dump word at 0x{a:x} = {t['dump_count']} (byte count) -> word[{words}], ending at the next e2m record {NEXT[a][0]} ({NEXT[a][1]})" + ("; abs_refs.py: 0 references to the rows inside" if t["inside"] else "")''',
     '''        ev = f"dump word 0x{a:x} = {t['dump_count']} -> word[{words}]; next e2m record {NEXT[a][0]} at {NEXT[a][1]}" + ("; abs_refs.py: no reference to the rows inside" if t["inside"] else "")'''),
    ('''        ev = f"ROM above the 0x40000 dump; next_record.py: the next e2m record {NEXT[a][0]} at {NEXT[a][1]} -> {2 * words} bytes = word[{words}]"''',
     '''        ev = f"next_record.py: next e2m record {NEXT[a][0]} at {NEXT[a][1]} -> word[{words}]; above the 0x40000 dump"'''),
]
for old, new in rep:
    if old not in s:
        raise SystemExit("missing: " + old[:80])
    s = s.replace(old, new)
open(p, "w").write(s)
print("patched")
