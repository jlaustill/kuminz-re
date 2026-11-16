#!/usr/bin/env python3
"""Tests for lookup_tables.py: synthetic cases for the parsers / sizing / audit rules, then ground
truth from the CM848 dumps and the committed CSVs (which must audit clean).

Usage:
    python3 test_lookup_tables.py        # exit 1 if any check fails
"""
import os
import sys
import tempfile

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lookup_tables as L

CHECKS = []


def check(fn):
    CHECKS.append(fn)
    return fn


def words_reader(table):
    """word_at() over {address: word}."""
    return lambda a: table.get(a)


def axis_words(base, points):
    """{address: word} for an axis at base: byte-length word, then the breakpoints."""
    out = {base: 2 * len(points)}
    out.update({base + 2 * (i + 1): p for i, p in enumerate(points)})
    return out


def state(globals_lines=(), arrays=(), structs=(), functions=()):
    return L.CsvState(["address,name,type,comment\n", *globals_lines], arrays, structs, functions)


# ── synthetic ───────────────────────────────────────────────────────────────────────

@check
def parse_calls_handles_wrapped_and_nested_arguments():
    text = ("//\n// Function: governor_step @ 0x00001000\n//\n"
            "void governor_step(void) {\n"
            "  x = lookupTableInterpolation\n"
            "          (&DAT_003fb11a,rpm,(word *)&axis_cal,\n"
            "           WORD_ARRAY_0005fe88,0);\n"
            "  y = f(lookupTableInterpolation(&cache,g(a,b),&t1,&t2,1));\n}\n")
    calls = L.parse_calls(text, {"lookupTableInterpolation"})
    return (len(calls) == 2
            and calls[0] == ("lookupTableInterpolation",
                             ["&DAT_003fb11a", "rpm", "(word *)&axis_cal", "WORD_ARRAY_0005fe88", "0"],
                             "governor_step")
            and calls[1][1][1] == "g(a,b)" and calls[1][2] == "governor_step")


@check
def resolve_argument_forms():
    s = state(["0x00404aee,fuel_map_rpm_axis_cal,byte,\n",
               "0x00407172,minimum_speed_axis,word[10],\n",
               "0x0040b000,table_pointer,dword,\n",
               "0x00407d92,twice_named_axis,byte,\n", "0x0040853e,twice_named_axis,byte,\n"])
    cases = {
        "(word *)&fuel_map_rpm_axis_cal": 0x404aee,      # address of a scalar-typed table
        "minimum_speed_axis": 0x407172,                  # an array name decays to its address
        "WORD_ARRAY_0005fe88": 0x5fe88,                  # unnamed typed table
        "&DAT_0005a462": 0x5a462,
        "(word *)0x3ff0c4": 0x3ff0c4,
        "table_pointer": None,                           # a scalar passed by value: not the table
        "(word *)&twice_named_axis": None,               # ambiguous name: left to the disassembly
        "param_3": None,
    }
    return all(L.resolve_argument(text, s) == want for text, want in cases.items())


@check
def axis_points_accepts_ascending_axes_only():
    word_at = words_reader({**axis_words(0x100, [0, 10, 20]),               # unsigned ascending
                            **axis_words(0x200, [0xfff6, 0, 10]),           # signed ascending (-10, 0, 10)
                            **axis_words(0x300, [10, 5, 20]),               # not monotonic
                            0x400: 5, 0x402: 1, 0x404: 2,                   # odd byte length
                            0x500: 0})                                      # empty
    return (L.axis_points(word_at, 0x100) == 3 and L.axis_points(word_at, 0x200) == 3
            and L.axis_points(word_at, 0x300) is None and L.axis_points(word_at, 0x400) is None
            and L.axis_points(word_at, 0x500) is None and L.axis_points(word_at, 0x600) is None)


@check
def size_tables_sizes_axis_data_and_grid():
    word_at = words_reader({**axis_words(0x100, [0, 10, 20]), 0x200: 6,     # data header = 3 values
                            **axis_words(0x300, [0, 5]), **axis_words(0x400, [1, 2, 3, 4])})
    calls = [L.Call("cpp", "lookupTableInterpolation", {"x": 0x100, "y": 0x200}, "f1"),
             L.Call("disasm", "cm848_dualAxisTableInterpolation", {"x": 0x300, "y_axis": 0x400, "z": 0x500}, "f2")]
    tables, problems = L.size_tables(calls, word_at)
    return (not problems and max(tables[0x100].counts) == 4 and max(tables[0x200].counts) == 4
            and max(tables[0x500].counts) == 2 * 4 and tables[0x500].roles == {"grid"}
            and tables[0x200].readers == {"f1"})


@check
def size_tables_reports_data_header_mismatch():
    word_at = words_reader({**axis_words(0x100, [0, 10, 20]), 0x200: 4})    # header says 2 values
    _, problems = L.size_tables([L.Call("cpp", "lookupTableInterpolation", {"x": 0x100, "y": 0x200}, "f")], word_at)
    return len(problems) == 1 and "header 4 != axis length 6" in problems[0]


@check
def disassembly_reads_argument_registers_and_resets_at_branches():
    lines = ["   32ba4:\t3c a0 00 40 \tlis     r5,64",
             "   32ba8:\t38 a5 7d 92 \taddi    r5,r5,32146",
             "   32bac:\t3c c0 00 40 \tlis     r6,64",
             "   32bb0:\t38 c6 7d a0 \taddi    r6,r6,32160",
             "   32bb8:\t48 02 33 3d \tbl      0x55ef4",
             "   32bbc:\t3c a0 00 40 \tlis     r5,64",
             "   32bc0:\t41 82 00 08 \tbeq     0x32bc8",            # a branch: r5 is no longer known
             "   32bc4:\t38 c6 7d a0 \taddi    r6,r6,32160",
             "   32bc8:\t48 02 33 2d \tbl      0x55ef4"]
    calls = L.calls_from_disassembly(lines, lambda a: "cm848_selectGovernorPressureNormal")
    return (len(calls) == 2 and calls[0].roles == {"x": 0x407d92, "y": 0x407da0}
            and calls[1].roles == {} and calls[0].function == "cm848_selectGovernorPressureNormal")


@check
def audit_and_plan_rows_fix_only_conflict_free_findings():
    word_at = words_reader({**axis_words(0x100, [0, 10, 20]), **axis_words(0x200, [0, 1]),
                            **axis_words(0x300, [0, 1]), **axis_words(0x400, [0, 5, 9])})
    calls = [L.Call("cpp", "lookupTableInterpolation", {"x": a}, "reader") for a in (0x100, 0x200, 0x300, 0x400)]
    tables, _ = L.size_tables(calls, word_at)
    s = state(["0x00000100,named_axis,byte,keep me\n",       # untyped named scalar -> retyped, name kept
               "0x00000200,u__00000200,,\n",                 # junk label -> type-only row
               "0x00000300,sized_axis,word[2],\n",           # typed with the wrong size -> reported only
               "0x00000402,element_name,word,\n"])           # a row inside 0x400 -> blocks it
    findings = L.audit(tables, s, {0x600: {("lookupTableInterpolation", 1)}})
    kinds = {(f.kind, f.address) for f in findings}
    changes = L.plan_rows(tables, findings, s, lambda a: None)
    return (("untyped", 0x100) in kinds and ("untyped", 0x200) in kinds and ("wrong size", 0x300) in kinds
            and ("rows inside", 0x400) in kinds and ("cache cast", 0x600) in kinds
            and changes[0x100] == ("named_axis", "word[4]", "keep me")
            and changes[0x200][0:2] == ("", "word[3]")
            and changes[0x600][0:2] == ("", "word")
            and 0x300 not in changes and 0x400 not in changes)


@check
def write_rows_edits_in_place_and_inserts_after_the_lower_neighbour():
    with tempfile.TemporaryDirectory() as tmp:
        path = os.path.join(tmp, "global_variables.csv")
        open(path, "w").write("address,name,type,comment\n0x00000300,c,byte,\n0x00000100,a,byte,\n0x00000400,d,byte,")
        edited, inserted = L.write_rows(path, {0x100: ("a", "word[3]", "x"), 0x380: ("", "word[2]", "new")})
        lines = open(path).read().split("\n")
    # 0x100 is edited where it stands (the file is not sorted); 0x380 goes right after 0x300
    return (edited, inserted) == (1, 1) and lines == [
        "address,name,type,comment", "0x00000300,c,byte,", "0x00000380,,word[2],new",
        "0x00000100,a,word[3],x", "0x00000400,d,byte,"]


# ── ground truth (dumps + committed CSVs) ───────────────────────────────────────────

@check
def dumps_size_the_hand_written_tables_the_same():
    image = L.MemoryImage()
    # arrays.csv cruise_switch_adc_band_table_x is word[21]; governor_minimum_speed_by_vehicle_speed_axis word[10]
    return L.axis_points(image.word, 0x5ab94) == 20 and L.axis_points(image.word, 0x407172) == 9


_COLLECTED = {}


def collected():
    if not _COLLECTED:
        state, image = L.CsvState.load(), L.MemoryImage()
        tables, problems, casts = L.collect(state, image)
        _COLLECTED.update(state=state, image=image, tables=tables, problems=problems, casts=casts)
    return _COLLECTED


@check
def disassembly_pairs_the_twice_named_governor_pressure_axis():
    # protection_fuel_limit_l2_axis_cal used to label 0x407d92 and 0x40853e; the governor pressure
    # lookup really loads 0x407d92 (6 breakpoints) with its 6-value data table at 0x407da0
    t = collected()["tables"]
    return max(t[0x407d92].counts) == 7 and max(t[0x407da0].counts) == 7


@check
def committed_state_audits_clean():
    c = collected()
    findings = L.audit(c["tables"], c["state"], c["casts"], c["image"].region)
    for f in findings[:10]:
        print("     ", f)
    return not findings and not c["problems"] and len(c["tables"]) >= 920


def main():
    fails = 0
    for fn in CHECKS:
        try:
            ok = bool(fn())
        except Exception as e:                      # a crash is a failure, with its reason
            print(f"     {type(e).__name__}: {e}")
            ok = False
        print(f"[{'PASS' if ok else 'FAIL'}] {fn.__name__}")
        fails += not ok
    print(f"\n{'ALL PASS' if fails == 0 else str(fails) + ' FAILED'}")
    sys.exit(1 if fails else 0)


if __name__ == "__main__":
    main()
