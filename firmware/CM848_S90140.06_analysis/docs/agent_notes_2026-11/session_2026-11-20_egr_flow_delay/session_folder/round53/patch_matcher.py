"""Round 53: turn round 52's record_for_record_matches.py (copied as semantic_record_matches.py) into a meaning-ranked
matcher: keep each block's best base by the token-overlap score of semantic_score.py, write every block's line."""
p = "/home/linux/.claude/jobs/374b0424/tmp/w15/r53/semantic_record_matches.py"
t = open(p).read()
if "semantic_score import" in t:
    print("already patched")
    raise SystemExit
t = t.replace('sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r45")',
              'sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r45")\n'
              'sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r53")\n'
              'from semantic_score import score as meaning  # noqa: E402')
old_tail = """                if rw == size:
                    matched += 1
                    mixed |= size != 2
                    names.append(f"{name}={rows[a][0]}")
        lo_k, hi_k = bisect.bisect_left(starts, base), bisect.bisect_left(starts, base + span_end)
        uncovered = sum(1 for a in starts[lo_k:hi_k] if a - base not in recs)
        if not conflict and matched >= need:
            per_block.append((mixed, matched, -uncovered, len(offs), b, base, names))
    per_block.sort(reverse=True)
    results += per_block[:3]
results.sort(key=lambda r: (r[0], r[1] / r[3], r[1]), reverse=True)
for mixed, matched, unc, total, b, base, names in results[:90]:
    print(f"{b:04X} @ {base:#x}: {matched}/{total} matched{' (mixed widths)' if mixed else ''}, {-unc} rows inside "
          "uncovered | " + "; ".join(names[:5])[:250])
print(f"{len(results)} candidate placements (best 3 per block)")"""
new_tail = """                if rw == size:
                    matched += 1
                    mixed |= size != 2
                    names.append(f"{name}={rows[a][0]}")
                    sem.append(meaning(name, desc, rows[a][0]))
        if conflict or matched < need:
            continue
        lo_k, hi_k = bisect.bisect_left(starts, base), bisect.bisect_left(starts, base + span_end)
        uncovered = sum(1 for a in starts[lo_k:hi_k] if a - base not in recs)
        per_block.append((sum(sem) / len(sem), mixed, matched, -uncovered, len(offs), b, base, names))
    per_block.sort(reverse=True)
    results += per_block[:1]
results.sort(reverse=True)
with open(out_path, "w") as fh:
    for sem_score, mixed, matched, unc, total, b, base, names in results:
        fh.write(f"{sem_score:.2f} {b:04X} @ {base:#x}: {matched}/{total} matched{' (mixed)' if mixed else ''}, "
                 f"{-unc} uncovered | " + "; ".join(names) + "\\n")
print(f"{len(results)} blocks with a placement (best meaning score per block)")"""
assert t.count(old_tail) == 1, "tail not found"
t = t.replace(old_tail, new_tail)
old_init = "        matched, mixed, conflict, names = 0, False, False, []\n"
assert t.count(old_init) == 1
t = t.replace(old_init, "        matched, mixed, conflict, names, sem = 0, False, False, [], []\n")
old_args = 'need = int(sys.argv[2]) if len(sys.argv) > 2 else 3\n'
assert t.count(old_args) == 1
t = t.replace(old_args, old_args + "out_path = sys.argv[3]\n")
t = t.replace('usage: record_for_record_matches.py <repo> [min matched]"""',
              "usage: semantic_record_matches.py <repo> <min matched> <output file>\n"
              "Round 53: ranks each block's best base by a token-overlap meaning score (semantic_score.py) instead of by "
              'width alone."""')
open(p, "w").write(t)
print("patched")
