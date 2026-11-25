"""Round 94 tooling: derive the judge workflow from the round 93 self-healing script. The round 93 runs finished the
investigators and describers of F1 / J1 / J2 and the describer of D1, then every judge (and D1's investigator) was
refused by a usage limit. This script keeps every prompt and schema and changes only how finished work comes in:
- args.from_files: { <batch>: ['proposal', 'blind'] }: those results are NOT recomputed; the judge is told to read
  them from <r94>/batch_<batch>.json (they are 50-150 KB each - too big to pass as args);
- a ROUND 93 NOTE in the shared context: what changed in the live CSVs since the frozen copies (the judges keep
  judging against the frozen copies; the apply step reconciles);
- the workflow returns the judges' verdicts and any newly computed proposal / roles.
usage: make_judge_workflow_r94.py <sturdy_r93.js> <out.js>"""
import sys

src, out = sys.argv[1], sys.argv[2]
s = open(src).read()
R94 = "/home/linux/.claude/jobs/374b0424/tmp/w15/r94"


def rep(old, new):
    global s
    assert s.count(old) == 1, (old[:70], s.count(old))
    s = s.replace(old, new)


rep("name: 'cm550-function-names-round-93-sturdy',", "name: 'cm550-function-names-round-94-judges',")
rep("description: 'Round 93 function naming, self-healing: agents that die on API errors are restarted from their notes (investigator + independent describer + judge per family)',",
    "description: 'Round 94: judge the finished round 93 naming proposals (read from files) and finish batch D1 (investigator + judge); agents that die on API errors restart from their notes',")
rep("- ESTABLISHED IN EARLIER ROUNDS (trust these names, they were verified):",
    "- ROUND 93 NOTE: the frozen copies are from before round 93. Since then the live CSVs changed: 52 function rows that sat in the middle of a function were removed (they are listed in the live firmware/CM550_J90350.00_analysis/output/deleted_functions.csv with 'PR #53 round 93'); the 45 executive frame task sets at 0x1b4d0-0x1b875 were named by their schedule slot (cm550_runEvery<N>FramesTaskSetPhase<P>); 1943 global rows were typed; the fault freeze frames became a struct array. Judge every proposal against the FROZEN copies, as the investigator saw them; the apply step reconciles names and types with the live CSVs.\n- ESTABLISHED IN EARLIER ROUNDS (trust these names, they were verified):")
rep("const GIVEN = (b) => (OPTIONS.given && OPTIONS.given[b.id]) || {}",
    "const FILES = (b) => (OPTIONS.from_files && OPTIONS.from_files[b.id]) || []\n"
    f"const FILE = (b) => '{R94}/batch_' + b.id + '.json'")
rep("() => GIVEN(b).proposal ? Promise.resolve(GIVEN(b).proposal) : sturdy((n) => `You are the INVESTIGATOR for batch",
    "() => FILES(b).includes('proposal') ? Promise.resolve({ in_file: true }) : sturdy((n) => `You are the INVESTIGATOR for batch")
rep("() => GIVEN(b).blind ? Promise.resolve(GIVEN(b).blind) : sturdy((n) => `You are an INDEPENDENT DESCRIBER for batch",
    "() => FILES(b).includes('blind') ? Promise.resolve({ in_file: true }) : sturdy((n) => `You are an INDEPENDENT DESCRIBER for batch")
rep("THE INVESTIGATOR'S PROPOSALS\\n${JSON.stringify(pair.proposal, null, 1)}\\n\\nTHE INDEPENDENT DESCRIBER'S ROLES\\n${pair.blind ? JSON.stringify(pair.blind, null, 1) : '(the describer returned nothing: re-derive every role yourself)'}",
    "THE INVESTIGATOR'S PROPOSALS\\n${pair.proposal.in_file ? `Read them from ${FILE(b)} (key \"proposal\"; JSON, long - read it in parts if needed). Give a verdict for every element in it.` : JSON.stringify(pair.proposal, null, 1)}\\n\\n"
    "THE INDEPENDENT DESCRIBER'S ROLES\\n${pair.blind && pair.blind.in_file ? `Read them from ${FILE(b)} (key \"blind\").` : pair.blind ? JSON.stringify(pair.blind, null, 1) : '(the describer returned nothing: re-derive every role yourself)'}")
rep(".then((v) => ({ batch: b.id, proposal: pair.proposal, blind: pair.blind, verdict: v }))",
    ".then((v) => ({ batch: b.id, proposal: pair.proposal.in_file ? 'in_file' : pair.proposal, blind: pair.blind && pair.blind.in_file ? 'in_file' : pair.blind, verdict: v }))")
open(out, "w").write(s)
print("judge workflow written:", out, len(s), "bytes")
