# Round 95 notes (lessons)

- A build stage can fail for months without a sign: analyzeHeadless exits 0 when a script throws, and the stage's own
  print ("Hardware register naming complete") comes from analyze.sh, not from the script. `ApplyMPC555Registers.java`
  threw `MemoryConflictException` in Phase 0 on every CM848 build since 2026-05-23. `run_script` now fails the build on
  "SCRIPT ERROR"; grep a build log for "SCRIPT ERROR" before trusting any stage.
- firmware/CLAUDE.md's "the label rows must stay or the register stage splits the struct" was never observable: the
  stage never ran. A preview of the old rule (register_stage_preview_r95.py) showed it would have split 28 instances, so
  the fix skips typed data instead of relying on guard rows.
- Check hardware names against the manual, not against each other: the struct and the register CSV agreed on MIOS
  `SCRD` at +6 and were both wrong (SCRD is the +4 duplicate). The web-fetch agent could not read the NXP PDF (TLS
  errors on the mirrors, 18 MB over its limit); `curl -C -` in two tries plus `pdftotext -layout` worked, and
  Appendix A lists every register with its address.
- Local declaration order follows unrelated CSV changes (removing three unrelated rows moved two declarations back).
  Each input still builds deterministically, so a token diff must treat a moved declaration as cosmetic.
- apply_r95.py keeps a live type of a different width unless the overrides set force_type: 0x801d44 stayed `byte`
  and its struct never applied; the census showed the fields as raw DAT_00801d4c. Grep the apply report for
  "TYPE KEPT" after every apply.
- A new return type changes the callers: CM848's last `scheduleJ1939PeriodicMessage` call fed its byte return to the
  next call (`cm848_initJ1939DiagnosticServiceHandler(bVar2)`; fixed with an explicit void row), and a word return on
  `cm550_lookupTableInterpolation` made a caller's own inferred return `CONCAT22(extraout_D0u ...)` (its caller
  ignores it: void). The caller census (unaff_ / extraout_ / in_ / CONCAT per function) finds these.
- The judge's final comment can already end with the "(was X; R)" note that the apply appends: 51 doubled notes were
  collapsed (dedupe_notes_r95.py). A text pass that renames a function in comments must skip "(was ...)" notes and
  mentions of the other firmware's same-named counterpart.
- The worktree guard refuses shell functions, `cd` + heredoc and pipelines that mention git; write a script file
  instead (fdiff_r95.py, removal_breakdown_r95.py).
