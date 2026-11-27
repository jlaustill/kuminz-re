"""Round 93 tooling: derive a retry workflow script from the persisted round 93 script, for the batches whose
first-stage agents died on API errors (529 Overloaded): the same prompts and schemas, only the batches passed as the
workflow's args, with a note that the scratch notes of the interrupted run may be reused (each agent only its own
role's folder, so the describer stays independent). usage: make_retry_workflow_r93.py <persisted.js> <out.js>"""
import sys

src, out = sys.argv[1], sys.argv[2]
s = open(src).read()


def rep(old, new):
    global s
    assert s.count(old) == 1, (old[:60], s.count(old))
    s = s.replace(old, new)


rep("name: 'cm550-function-names-round-93',", "name: 'cm550-function-names-round-93-retry',")
rep("description: 'Name CM550 functions from the round 92 evidence (enable bits, fueling states): investigator + independent blind describer + judge per call-graph family',",
    "description: 'Retry of the round 93 function naming batches whose agents died on API errors: investigator + independent describer + judge',")
rep("const results = await pipeline(\n  BATCHES,",
    "const WANTED = Array.isArray(args) && args.length ? args : ['J1']\nconst results = await pipeline(\n  BATCHES.filter((b) => WANTED.includes(b.id)),")
rep("Keep your scratch scripts and notes in ${R}/scratch/${b.id}/investigator/.`,",
    "Keep your scratch scripts and notes in ${R}/scratch/${b.id}/investigator/. An earlier run of this exact task was cut off by a server error before it could answer; whatever it left in that folder is yours to reuse (check it before you rely on it).`,")
rep("Keep your scratch scripts and notes in ${R}/scratch/${b.id}/describer/ and do not read ${R}/scratch/${b.id}/investigator/ or any other agent's folder.`,",
    "Keep your scratch scripts and notes in ${R}/scratch/${b.id}/describer/ and do not read ${R}/scratch/${b.id}/investigator/ or any other agent's folder. An earlier run of this exact task was cut off by a server error before it could answer; whatever it left in your own folder is yours to reuse (check it before you rely on it).`,")
rep("const missing = BATCHES.filter((b, i) => !results[i]).map((b) => b.id)",
    "const missing = BATCHES.filter((b) => WANTED.includes(b.id)).filter((b, i) => !results[i]).map((b) => b.id)")
open(out, "w").write(s)
print("retry script written:", out, len(s), "bytes")
