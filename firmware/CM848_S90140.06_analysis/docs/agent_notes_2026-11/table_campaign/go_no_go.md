# Table-naming pilot: go / no-go (written before reading any result)

Pilot: bin 02 (generic reader name) to agents A and B independently, bin 06 (RAM tables), bin 09 (shared axes).

GO for the remaining 15 bins only if all three hold:
1. Agreement, bin 02 A vs B: of the lookups both agents name, >= 70% mean the same thing
   (same output quantity and the same inputs; wording may differ), and no pair names
   different domains (for example timing vs fuel quantity).
2. Hand check of 15 names (5 from each of bins 02 / 06 / 09) against the breakpoints and the
   call: >= 13 plausible and 0 clearly wrong (wrong input, wrong output, wrong domain).
3. The mechanical gates (format, bans, uniqueness, coverage) pass, or every failure is a
   wording fix, not a meaning fix.

NO-GO: tighten the brief on what failed and re-run the pilot on the failing bin.
Skips are fine at any rate; a skip is better than an invented name.
