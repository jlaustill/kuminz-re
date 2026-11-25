
## 07:35 - do not read a .cpp while its verify runs
`./analyze.sh verify` builds twice and the second pass rewrites output/<fw>.ghidra.cpp function by function during
its export. A copy taken at 07:29 (post_r94c1_cm550.cpp) held 421 of 704 functions, so the render check and the
underscore-map token diff that read it are void. The 07:22 CM550 proofs read the finished first pass (704 functions,
"removed 0"). Rule: wait for the verify's notification, then copy / prove.

## 09:08 - an idempotent insert must not test "old text absent"
post_apply_r94.py's edit helper skipped an edit when the new text was present and the old one absent. For an
insertion the old text (the table line) is a prefix of the new one, so the old text stays present, and the
idempotence run inserted the clip-protocol-spec.md correction note a second time (committed in stage C, 9b467c63;
removed in stage E). An insert must test for the inserted text itself.
