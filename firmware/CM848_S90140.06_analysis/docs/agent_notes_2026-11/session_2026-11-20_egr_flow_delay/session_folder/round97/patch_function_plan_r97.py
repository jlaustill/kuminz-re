"""Round 97: corrections to function_spelling_plan_r97.py after the first review (special names, kept names, the R7
batch's hpcr_cbd* functions, names with number-letter parts, case-only changes, the aux / eps words)."""
p = "/home/linux/.claude/jobs/374b0424/tmp/w15/r97/function_spelling_plan_r97.py"
t = open(p).read()
old = '         "proc": "process", "accum": "accumulator", "info": "information", "seq": "sequence"}'
new = ('         "proc": "process", "accum": "accumulator", "info": "information", "seq": "sequence", "aux": "auxiliary",\n'
       '         "eps": "enginePositionSensor"}\n'
       'SPECIAL = {"cm848_diagSendResponseCode": "cm848_sendDiagnosticResponseCode",\n'
       '           "cm550_emptyPlaceholderInit": "cm550_emptyPlaceholderInitialization",\n'
       '           "cm848_continuePciControllerInit": "cm848_continuePciControllerInitialization",\n'
       '           "cm848_sciInitDefaultCallback": "cm848_initializeSciDefaultCallback",\n'
       '           "cm848_sciInitCommandCallback": "cm848_initializeSciCommandCallback",\n'
       '           "cm848_sciInitPort1": "cm848_initializeSciPort1"}\n'
       'KEEP = {"buildPgn65228Dm3ClearInitMessage"}            # no plate says what its Init is')
assert t.count(old) == 1
t = t.replace(old, new)
old = ('def spell(name):\n    prefix = next((p for p in PREFIXES if name.startswith(p)), "")\n    body = name[len(prefix):]\n'
       '    if "_" in body:                                    # snake_case or mixed: leave for review\n        return name')
new = ('def spell(name):\n    if name in SPECIAL:\n        return SPECIAL[name]\n    prefix = next((p for p in PREFIXES if name.startswith(p)), "")\n'
       '    body = name[len(prefix):]\n'
       '    if "_" in body or name in KEEP or name.startswith("hpcr_cbd") or re.search(r"[0-9][a-z]", body):\n'
       '        return name                                    # snake_case / kept / the R7 batch / number-letter parts')
assert t.count(old) == 1
t = t.replace(old, new)
old = '    new = spell(n)\n    if new != n:'
new = '    new = spell(n)\n    if new != n and new.lower() != n.lower():          # case-only changes are not spellings'
assert t.count(old) == 1
t = t.replace(old, new)
open(p, "w").write(t)
print("ok")
