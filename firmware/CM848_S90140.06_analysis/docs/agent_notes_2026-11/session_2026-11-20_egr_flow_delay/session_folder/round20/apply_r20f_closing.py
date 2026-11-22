"""Round 20 stage F closing (the advisor's review): correct the round 20 docs. Covers word 11's value (0x000b, not
0x0000), the e2m tier rule as applied (abbreviations also come from sibling records and the repo's vocabulary; AC is
air compressor in word 18 only), the raw scanner's reach and the ANC .cpp cross-check, and stage F itself; 19 bitfield
structs in all. Idempotent. usage: apply_r20f_closing.py <repo> <pr_body.md> <stage F hash>"""
import os
import sys

repo, pr, f_hash = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t and t.count(old) <= t.count(new):
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


t46 = "work/tasks/046-cm848-egr-flow-estimate.md"
edit(t46, "  - Nothing of these reaches word 3, so stage B's \"no reader\" comments and round 19's ANC claim hold.\n",
     "  - Nothing of these reaches word 3, so stage B's \"no reader\" comments and round 19's ANC claim hold.\n"
     "  - Round 19's raw scanner finds only addresses built with `lis`. Word 3 has 5 such hits, but 10 functions read\n"
     "    it; the others use a base register. So the ANC claim was also checked against the `.cpp`: no named, `DAT_`\n"
     "    or region-loop reference reaches 0x40a04a-0x40a05d. (`sensor_channel_ram_start`, 0x40a046, is the exclusive\n"
     "    end of the copied calibration region.)\n")
edit(t46, "  - Word 11 bit 3 (`J1939_Communication_Enable`) was an unnamed `DAT_003fd5b2` that gates the J1939 transmit queues and\n"
     "    the receive dispatch. The label-only proof found it.\n",
     "  - Word 11 bit 3 (`J1939_Communication_Enable`) was an unnamed `DAT_003fd5b2` that gates the J1939 transmit queues and\n"
     "    the receive dispatch. The label-only proof found it. The word is 0x000b on this truck, so J1939 communication\n"
     "    is enabled. Stage C's comment said 0x0000 without reading the dump; stage F corrected it.\n")
edit(t46, "    - an unread bit takes its record's name only when exactly one record sits on it and the description spells the\n"
     "      words out;\n",
     "    - an unread bit takes its record's name only when exactly one record sits on it, and each abbreviation in it is\n"
     "      spelled out by that record's description, a sibling record or the repo's vocabulary: AC air conditioning\n"
     "      (except word 18's `AC_Smart_Enable`, 'Smart Air Compressor'), IMT intake manifold temperature, EB engine\n"
     "      retarder, WG wastegate, RSG road speed governor, AH air handling, CT coolant temperature;\n")
edit(t46, "- **Stage E (32df48c, label-only):**",
     f"- **Stage F ({f_hash}, types + comments, after the advisor's review):** word 11 is\n"
     "  `algorithm_enable_flags_11_t` (the proprietary / J1587 / J1922 / J1939 communication enables), the one directly\n"
     "  read flags word left untyped. Its comment now gives the dump value 0x000b, and word 19 bit 7's comment no longer\n"
     "  says the reader rules out its second record (the two are one enable under two names). That makes 19 bitfield\n"
     "  structs this round (word 3, the 17 of stage D, word 11).\n"
     "- **Stage E (32df48c, label-only):**")
edit(t46, "    - the computed and pointer reads (the engine protection loops, `calculateAlpha`).\n",
     "    - the computed and pointer reads (the engine protection loops, `calculateAlpha`).\n"
     "  - A dump value goes into a comment only after it is read at the declared width. Word 11's 0x0000 was written from\n"
     "    memory (it is 0x000b).\n")
edit(pr, "- **Stage D (797ec46, types):** 17 more flag words as bitfields: 117 bits named from a matching reader, 50 from a\n"
     "  single spelled-out record, 105 reserved. Plus the cold delta fuel cache.\n",
     "- **Stage D (797ec46, types):** 17 more flag words as bitfields: 117 bits named from a matching reader, 50 from a\n"
     "  single record (each abbreviation expanded by its description, a sibling record or the repo's vocabulary), 105\n"
     "  reserved. Plus the cold delta fuel cache.\n")
edit(pr, "- **Stage E (32df48c, label-only):** the cold delta fuel cache initializer.\n",
     "- **Stage E (32df48c, label-only):** the cold delta fuel cache initializer.\n"
     f"- **Stage F ({f_hash}, after the advisor's review):** word 11 as `algorithm_enable_flags_11_t` (the J1939 / J1587 /\n"
     "  J1922 / proprietary communication enables), its dump value corrected to 0x000b (J1939 communication is enabled),\n"
     "  and word 19 bit 7's comment.\n")
edit(pr, "- [x] Round 20: stages A, C and E are EQUIVALENT; stages B and D pass the mask normalizer (D's count gate: per "
     "word and mask, old masked reads = new field reads; pieces 464 -> 464).",
     "- [x] Round 20: stages A, C and E are EQUIVALENT; stages B, D and F pass the mask normalizer (the count gate: per "
     "word and mask, old masked reads = new field reads; pieces 464 -> 464).")
edit("work/todo.md", "17 words named, 18 bitfield structs, cold_delta_fuel", "17 words named, 19 bitfield structs, cold_delta_fuel")
print("stage F closing edits applied")
