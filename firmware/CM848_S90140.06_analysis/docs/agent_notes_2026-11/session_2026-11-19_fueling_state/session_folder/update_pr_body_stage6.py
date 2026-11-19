"""Add stage 6 (6a filter records, 6b parameter ID table / emission manager / power take-off helpers) to pr_body.md.
usage: update_pr_body_stage6.py <pr_body.md>"""
import sys

path = sys.argv[1]
s = open(path).read()


def replace(old, new):
    global s
    assert s.count(old) == 1, old[:70]
    s = s.replace(old, new)


replace("This PR does five stages:", "This PR does six stages:")
replace("and fixed the comments that still used the old engine state words.\n",
        "and fixed the comments that still used the old engine state words.\n"
        "6. **The ECU's own e2m map, and the structures.** The ECU's parameter ID table in flash2 maps every e2m block to "
        "its address, so e2m names no longer rest on offset matching (`firmware/scripts/e2m_block_addresses.py`). It "
        "names the emission manager and the power take-off settings. The 33 `cm848_signedFirstOrderFilter` records are "
        "now `ema_filter_state_t`.\n")
replace("## Checks\n", """## Stage 6: the filter records, the ECU's parameter ID table, the emission manager

- **6a, the signed filter records.**
  - `cm848_signedFirstOrderFilter` reads its record exactly as `exponentialMovingAverage` reads an `ema_filter_state_t`: a pointer to the 16-bit coefficient, then the Q16.16 accumulator.
  - Its 33 global records (39 call sites) are now instances named after what they filter, e.g. `power_take_off_speed_error_filter` (was `protection_filter_state_ptr` + `governor_integrator_working`) and `governor_speed_error_delta_filter` (was `governor_bank2_cal_ptr`).
  - The 23 accumulator rows went away, so `rec.accumulator = 0` replaces `_cam_sync_fuel_filter_accum = 0`. The coefficients are typed `word` (12 were `byte`).
  - The prototype returns `sword`. The `int32_t` attempt put a temp and a cast at all 39 calls.
  - `generate_headers.py` now aliases Ghidra's signed `sbyte` / `sword` / `sdword` / `sqword`.
- **6b, the ECU's parameter ID table.** `cm848_lookupParameterIdAddress` (0x539768) searches a flash2 table of `[e2m block id][address]` records at 0x53be38.
  - An e2m record's address is the table entry plus its offset.
  - It reproduces every block base this PR had proved by matching offsets.
  - `firmware/scripts/e2m_block_addresses.py` resolves blocks or an address with the current CSV names, and has tests.
- **6b, the emission manager (EMO / EMM).** Every e2m identity was resolved with the table.
  - **`emission_level_cap_command`** (was `fuel_demand_min_threshold`, e2m EMM_Cap_EL_Cmd) is the rate-limited maximum of the AECD caps and a scheduled reference. It is a lower bound on the combustion chi, not a fuel demand floor.
  - **`emission_manager_engine_protection_state`** (was `combustion_status_flags`) and the AECD state pack.
  - **The air handling system protection AECD** (e2m 1990-1997) is the only one enabled on this truck.
  - **White smoke and misfire protection** and **general engine protection** (their old names were injection timing / sensor validation guesses).
  - 15 functions in all.
- **6b, the power take-off helpers.** Six functions are named, among them the PGN 65264 power take-off information message.
  - The working words: the gain adjustment multiplier and its e2m 13B2 / 13B3 tables, the PID integrator, the switch state bits, the engagement ramp and the remote switch counts.
  - A `word[6]` remote speed array, read indexed.
  - The e2m 0008 EEPROM settings, and three PGN priority words that were misnamed `_source_address_bits`.
  - Four stage-5 comments the agent found wrong are fixed.
- **How it was done.** Two read-only agents mapped the power take-off helpers and the emission manager. The table claim was checked with an independent parser, and every e2m address both agents gave was re-resolved before applying.

## Checks
""")
replace("- Every `FUELING_STATE_` name in the `.cpp` sits on a carrier.\n",
        "- **Stage 6a.** All 46 names render. After mapping each field access back to the flat form it replaced, 15 functions still differ, all explained:\n"
        "  - the init functions' unnamed +4 bytes now read `.accumulator`;\n"
        "  - the two prototypes;\n"
        "  - local type propagation (the fuel metering function's 2992-token skeleton is identical);\n"
        "  - a division rendered through `ulonglong` (same value);\n"
        "  - a local declaration order;\n"
        "  - an unnamed instance's default label.\n"
        "- **Stage 6b.** All 123 names render. Six functions differ:\n"
        "  - the `word[6]` array in two power take-off functions;\n"
        "  - two `(word)` casts from new rows;\n"
        "  - two local declaration orders.\n"
        "- Every `FUELING_STATE_` name in the `.cpp` sits on a carrier.\n")
replace("- The six power take-off helper functions, including 0x2abc8, which initializes the whole governor.\n"
        "- The power take-off filter record (0x3fafb2 pointer + 0x3fafb6 state).\n"
        "- A shared struct for the 13 global `cm848_signedFirstOrderFilter` records (15 call sites; two pass a pointer through).\n",
        "- An audit of the whole CSV against the parameter ID table. 445 of its 1886 records lie past the end of the flash2 dump.\n"
        "- The rest of the emission manager: two words with no writer, two store-only limits, and the compressor outlet temperature scale.\n")
replace("- The rest of the EMO family: the other inputs of `fuel_demandMin_maxSelect_rateLimit` and its output `fuel_demand_min_threshold`, which look like AECD caps rather than fuel demands.\n",
        "")
open(path, "w").write(s)
print("pr_body.md updated for stage 6")
