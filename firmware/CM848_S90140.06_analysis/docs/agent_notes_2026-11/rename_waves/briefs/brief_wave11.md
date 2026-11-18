# Wave 11 addendum (read after brief.md, brief_wave9.md and brief_wave10.md) - structs, arrays, bitfields

The user's rule (2026-11-18): **anything that can be a struct is a YES**. Structs make the decompiled code read better.
So this wave's main job is TYPE SHAPE, not only names:
- clusters with a shared layout become structs;
- indexed scalars become arrays (of structs where the stride says so);
- masked flag words become bitfields.

The repo root, the read-only rule, the banned words and the result-file rule are as in brief_wave10.md. Your result
file is `/home/linux/.claude/jobs/821efb84/tmp/wave11/result_W11_<group>.jsonl`.

**Exclusion zone - do not propose anything for these bytes.** They are the J1939 transmit descriptors, which are
being typed by hand. Each is 14 bytes from its base (can_id dword @+0 / data length word @+4 / data pointer @+6 /
data end pointer @+10):
- 0x3fa830, 0x3faa8c, 0x3faa9c (and the ACK payload 0x3faaaa-0x3faab1), 0x3faab4, 0x3faad4, 0x3faae4, 0x3faafc;
- 0x3fab14, 0x3fab52, 0x3fab6a, 0x3fabcc, 0x3fac2e;
- 0x3fad48, 0x3fad60, 0x3fad80, 0x3fad98, 0x3fadb0, 0x3fadc8, 0x3fade1, 0x3fadf0;
- 0x3fae10, 0x3fae28, 0x3fae38, 0x3fae63, 0x3fae72, 0x3faeb8, 0x3faec8, 0x3faee0, 0x3faef8;
- 0x3faf24, 0x3faff4.

Payload byte rows next to them are fair game.

**How to prove a shape.**
- **Struct:** give every field's offset and width, quoting the load / store instruction (`disasm_func.py`). Show the
  same layout at every instance: the same consumer, the same stride, or a pointer cast.
- **Array:** give the element type, the stride and the count. The count comes from the loop bound, the consumers'
  index range and the next real symbol; in the copy window the edge rule of `firmware/CLAUDE.md` applies.
- **Bitfield:** declare EVERY bit of each byte you touch, named or `reserved_bit_N`. A partial bitfield renders its
  name for any bit of that byte, which happened with the old `protection_active` field.
- **No proof, no shape:** say `uncertain` and stop.

**Proposal formats** (new kinds; the pipeline cannot apply them, the reviewer applies them by hand, so be exact):
```
{"kind": "struct_proposal", "type": "engine_overspeed_event_t", "size": 8, "fields": [{"offset": 0, "name": "key_on_time", "type": "dword", "evidence": "lwz @ 0x..."}, ...], "instances": [{"address": "0x003fdfde", "name": "engine_overspeed_event_log_cal", "count": 5}], "drop_rows": ["0x003fdfde engine_overspeed_event_log_cal"], "evidence": "..."}
{"kind": "array_proposal", "address": "0x...", "name": "...", "element_type": "word | byte | dword | i16 | <struct>_t", "count": N, "drop_rows": ["0x... name", ...], "evidence": "..."}
{"kind": "bitfield_proposal", "struct": "monitor_enabling_conditions_t", "address": "0x0040b9d0", "name": "...", "storage_bytes": 4, "bits": [{"bit": 0, "name": "...", "evidence": "..."}, ...], "drop_rows": [], "evidence": "..."}
```
- `drop_rows` lists every existing row inside the new shape, which the reviewer must remove or turn into a member
  label.
- Element and field types use the CSV keywords: byte / word / dword / i16 / pointer / an existing struct or enum
  name.
- Ordinary renames still use the `function` / `global` / `new_global` rows of brief.md.

**Struct fields of existing structs:** propose renames as
`{"kind": "struct_field", "struct": "<type>", "old": "<field>", "new": "<field>", "evidence": "..."}`. Propose a split
of one field into several as a `struct_proposal` for the whole type, with every field.

Budget: about 90 tool calls. End with counts per kind and one line per item.
