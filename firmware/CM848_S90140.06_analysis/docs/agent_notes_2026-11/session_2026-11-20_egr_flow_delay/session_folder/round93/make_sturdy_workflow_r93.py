"""Round 93 tooling: derive a self-healing workflow script from the persisted round 93 script. The first run lost
seven agents to 'API Error: 529 Overloaded' after 10-40 minutes of work each. This version keeps the same prompts
and schemas and adds:
- sturdy(): an agent that returns nothing (it died on an API error) is started again, up to 4 attempts, with a note
  to continue from the notes in its own scratch folder;
- every agent is told to keep a running notes.md of confirmed findings in its scratch folder;
- args = { batches: [...], given: { <batch>: { proposal, blind } } }: only the listed batches run, and a result that
  an earlier run already produced is passed in instead of being worked out again.
usage: make_sturdy_workflow_r93.py <persisted.js> <out.js>"""
import sys

src, out = sys.argv[1], sys.argv[2]
s = open(src).read()


def rep(old, new):
    global s
    assert s.count(old) == 1, (old[:70], s.count(old))
    s = s.replace(old, new)


rep("name: 'cm550-function-names-round-93',", "name: 'cm550-function-names-round-93-sturdy',")
rep("description: 'Name CM550 functions from the round 92 evidence (enable bits, fueling states): investigator + independent blind describer + judge per call-graph family',",
    "description: 'Round 93 function naming, self-healing: agents that die on API errors are restarted from their notes (investigator + independent describer + judge per family)',")
rep("const results = await pipeline(\n  BATCHES,",
    """const OPTIONS = (args && typeof args === 'object' && !Array.isArray(args)) ? args : {}
const WANTED = Array.isArray(OPTIONS.batches) && OPTIONS.batches.length ? OPTIONS.batches : BATCHES.map((b) => b.id)
const GIVEN = (b) => (OPTIONS.given && OPTIONS.given[b.id]) || {}
const TRIES = 4
const NOTE = (n, role, b) => `\\n\\nKEEP NOTES: write each finding you are sure of into ${R}/scratch/${b.id}/${role}/notes.md as soon as you have it (one short entry per function / global / enum member, with its evidence), so the work survives an interruption. ` + (n > 1
  ? `THIS IS ATTEMPT ${n}: the attempt before this one was cut off by a server error. Read ${R}/scratch/${b.id}/${role}/notes.md and the scripts in that folder first and continue from them (re-check what you reuse); do not start over.`
  : `An earlier run of this exact task may have been cut off by a server error: if ${R}/scratch/${b.id}/${role}/ already holds notes or scripts, read them first and continue from them (re-check what you reuse).`)
async function sturdy(makePrompt, opts) {
  for (let n = 1; n <= TRIES; n++) {
    const r = await agent(makePrompt(n), { ...opts, label: n === 1 ? opts.label : `${opts.label} (try ${n})` })
    if (r) return r
    log(`${opts.label}: attempt ${n} returned nothing (API error); ${n < TRIES ? 'starting it again' : 'giving up'}`)
  }
  return null
}
const results = await pipeline(
  BATCHES.filter((b) => WANTED.includes(b.id)),""")
rep("() => agent(`You are the INVESTIGATOR for batch",
    "() => GIVEN(b).proposal ? Promise.resolve(GIVEN(b).proposal) : sturdy((n) => `You are the INVESTIGATOR for batch")
rep("Keep your scratch scripts and notes in ${R}/scratch/${b.id}/investigator/.`,",
    "Keep your scratch scripts and notes in ${R}/scratch/${b.id}/investigator/.${NOTE(n, 'investigator', b)}`,")
rep("() => agent(`You are an INDEPENDENT DESCRIBER for batch",
    "() => GIVEN(b).blind ? Promise.resolve(GIVEN(b).blind) : sturdy((n) => `You are an INDEPENDENT DESCRIBER for batch")
rep("Keep your scratch scripts and notes in ${R}/scratch/${b.id}/describer/ and do not read ${R}/scratch/${b.id}/investigator/ or any other agent's folder.`,",
    "Keep your scratch scripts and notes in ${R}/scratch/${b.id}/describer/ and do not read ${R}/scratch/${b.id}/investigator/ or any other agent's folder.${NOTE(n, 'describer', b)}`,")
rep("(pair, b) => (pair && pair.proposal) ? agent(`You are the JUDGE for batch",
    "(pair, b) => (pair && pair.proposal) ? sturdy((n) => `You are the JUDGE for batch")
rep("Keep your scratch scripts and notes in ${R}/scratch/${b.id}/judge/.`,",
    "Keep your scratch scripts and notes in ${R}/scratch/${b.id}/judge/.${NOTE(n, 'judge', b)}`,")
rep("const missing = BATCHES.filter((b, i) => !results[i]).map((b) => b.id)",
    "const missing = BATCHES.filter((b) => WANTED.includes(b.id)).filter((b, i) => !results[i]).map((b) => b.id)")
open(out, "w").write(s)
print("sturdy script written:", out, len(s), "bytes")
