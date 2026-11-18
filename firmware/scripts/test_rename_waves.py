#!/usr/bin/env python3
"""Tests for the rename-wave toolchain (rename_waves/) on synthetic inputs (no Ghidra, no binaries).

Run: python3 test_rename_waves.py   (exits non-zero on fail)

They pin the shared helpers (common.py) and what the proof relies on: a pure rename (new names, renumbered goto labels, changed comments, reordered
local declarations) is EQUIVALENT and a one-constant change is not; the vocabulary pass turns init into initialize
and applies --swap prefixes; the reference refresh keeps history and leaves names that are still in use; new-row
comments are cut at a word boundary.
"""
import csv
import datetime
import json
import os
import subprocess
import sys
import tempfile

TOOLS = os.path.join(os.path.dirname(os.path.abspath(__file__)), "rename_waves")
sys.path.insert(0, TOOLS)
import common  # noqa: E402

OLD_CPP = """// Generated: 2026-11-17 08:00:00
// Function: cm848_updateLoadProtection @ 0x00001000
/* Old plate comment */
void cm848_updateLoadProtection(void)
{
  word wVar1;
  byte bVar2;
  DAT_00401000 = 1;
  if (protection_counter != 0) goto LAB_00001010;
  cm848_helper();
LAB_00001010:
  sensor_state.old_field = 2;
  return;
}
// Function: cm848_helper @ 0x00001020
void cm848_helper(void)
{
  return;
}
"""
NEW_CPP = """// Generated: 2026-11-17 09:00:00
// Function: cm848_updateValvePosition @ 0x00001000
/* New plate comment, rewritten */
void cm848_updateValvePosition(void)
{
  word wVar1;
  byte bVar2;
  egr_valve_command = 1;
  if (egr_valve_hold_counter != 0) goto LAB_00001014;
  cm848_helper();
LAB_00001014:
  sensor_state.new_field = 2;
  return;
}
// Function: cm848_helper @ 0x00001020
void cm848_helper(void)
{
  return;
}
"""
MAPPING = [("0x00001000", "cm848_updateValvePosition", "cm848_updateLoadProtection", "function"),
           ("0x00401000", "egr_valve_command", "DAT_00401000", "new row"),
           ("0x00401002", "egr_valve_hold_counter", "protection_counter", "global"),
           ("", "new_field", "old_field", "field")]


def run(script, *args):
    p = subprocess.run([sys.executable, os.path.join(TOOLS, script), *args], capture_output=True, text=True)
    return p.returncode, p.stdout + p.stderr


def write(path, text):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    open(path, "w").write(text)


def check_common(_d):
    long_word = "word " * 79 + "identifier_cut_here and more"     # the identifier crosses character 400
    on_space = "x" * 399 + " tail"
    no_space = "y" * 450
    two = ("// Function: a @ 0x1\nvoid a(void)\n{\n  goto LAB_00000010;\nLAB_00000010:\n  goto LAB_00000020;\n"
           "LAB_00000020:\n}\n// Function: b @ 0x2\nvoid b(void)\n{\nLAB_00000030:\n  goto LAB_00000030;\n}\n")
    canon = common.canonical_labels(two)
    return [("common.clip: short text unchanged", common.clip("alpha beta") == "alpha beta"),
            ("common.clip: a cut identifier is dropped",
             common.clip(long_word).endswith("word ...") and "identifier" not in common.clip(long_word)),
            ("common.clip: the word before the cut is kept", common.clip(on_space) == "x" * 399 + " ..."),
            ("common.clip: text without a space is cut hard", common.clip(no_space) == "y" * 400 + " ..."),
            ("common.canonical_labels: per function, by first appearance",
             "goto L0;\nL0:\n  goto L1;\nL1:" in canon and "void b(void)\n{\nL0:\n  goto L0;" in canon)]


def check_proof(d):
    write(f"{d}/old.cpp", OLD_CPP)
    with open(f"{d}/map.csv", "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["address", "name", "old_label", "kind"])
        w.writerows(MAPPING)
    results = []
    write(f"{d}/same.cpp", NEW_CPP)
    run("canonicalize_cpp.py", f"{d}/old.cpp", f"{d}/old_canon.cpp")
    code, out = run("reverse_names.py", f"{d}/old.cpp", f"{d}/same.cpp", f"{d}/map.csv", "--ignore-comments",
                    "--canonical-code-labels", "--write-reversed", f"{d}/reversed.cpp")
    results.append(("proof: a pure rename is EQUIVALENT", code == 0 and "EQUIVALENT" in out and "NOT" not in out))
    _, out = run("squash_changed.py", f"{d}/old_canon.cpp", f"{d}/reversed.cpp")
    results.append(("proof: the canonical baseline matches the reversed build", "beyond whitespace: 0" in out))
    reordered = NEW_CPP.replace("  word wVar1;\n  byte bVar2;", "  byte bVar2;\n  word wVar1;")
    write(f"{d}/reordered.cpp", reordered)
    code, out = run("reverse_names.py", f"{d}/old.cpp", f"{d}/reordered.cpp", f"{d}/map.csv", "--ignore-comments",
                    "--canonical-code-labels")
    results.append(("proof: reordered local declarations stay EQUIVALENT", code == 0 and "NOT" not in out))
    write(f"{d}/changed.cpp", NEW_CPP.replace("egr_valve_command = 1;", "egr_valve_command = 3;"))
    code, out = run("reverse_names.py", f"{d}/old.cpp", f"{d}/changed.cpp", f"{d}/map.csv", "--ignore-comments",
                    "--canonical-code-labels", "--write-reversed", f"{d}/reversed_changed.cpp")
    results.append(("proof: a changed constant is NOT EQUIVALENT", code == 1 and "NOT EQUIVALENT" in out))
    _, out = run("squash_changed.py", f"{d}/old_canon.cpp", f"{d}/reversed_changed.cpp")
    results.append(("proof: squash_changed names the changed function",
                    "beyond whitespace: 1" in out and "cm848_updateLoadProtection" in out))
    return results


def check_align(d):
    rows = [{"kind": "function", "verdict": "confirmed", "address": "0x1000", "old": "FUN_00001000",
             "new": "cm848_initValveState", "plate_comment": "Sets up the valve; cm848_initValveState runs once."},
            {"kind": "function", "verdict": "confirmed", "address": "0x1100", "old": "FUN_00001100",
             "new": "cm848_calculateInitialFuel"},
            {"kind": "function", "verdict": "confirmed", "address": "0x1200", "old": "FUN_00001200",
             "new": "cm848_valveInitState"},
            {"kind": "global", "verdict": "confirmed", "address": "0x401000", "old": "a_old",
             "new": "exhaust_gas_recirculation_valve_duty", "evidence": "exhaust_gas_recirculation_valve_duty is written"},
            {"kind": "global", "verdict": "confirmed", "address": "0x401002", "old": "b_old+2", "new": "c_new+2"}]
    write(f"{d}/result_T1_a.jsonl", "".join(json.dumps(r) + "\n" for r in rows))
    run("align_results.py", d, "T1", "a", "--swap", "exhaust_gas_recirculation_valve_=egr_valve_")
    out = [json.loads(l) for l in open(f"{d}/aligned_T1_a.jsonl") if l.strip()]
    names = [r["new"] for r in out]
    return [("align: cm848_initX -> cm848_initializeX (and in its plate)",
             "cm848_initializeValveState" in names and "cm848_initializeValveState runs" in out[0]["plate_comment"]),
            ("align: fooInitBar -> fooInitializeBar", "cm848_valveInitializeState" in names),
            ("align: Initial is not touched", "cm848_calculateInitialFuel" in names),
            ("align: --swap applies to names and evidence",
             "egr_valve_duty" in names and out[-1]["evidence"].startswith("egr_valve_duty is")),
            ("align: <name>+N sub-label rows are left out", len(out) == 4)]


def check_refresh(d):
    out = f"{d}/repo/firmware/CM848_S90140.06_analysis/output"
    write(f"{out}/global_variables.csv", "address,name,type,comment\n"
          "0x00401000,new_name,word,set by the loop (was old_name) and old_name is read twice\n"
          "0x00401002,still_used,word,\n")
    write(f"{out}/function_renames.csv", "address,name,plate_comment\n"
          "0x00001000,cm848_fn,reads old_name and still_used; the inputs were old_name / still_used\n")
    write(f"{d}/repo/notes.md", "old_name feeds the loop\n")
    with open(f"{d}/refresh.csv", "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["address", "name", "old_label", "kind"])
        w.writerow(["0x00401000", "new_name", "old_name", "global"])
        w.writerow(["0x00401004", "other_new", "still_used", "global"])    # old label is still a current name
        w.writerow(["0x00401006", "named_now", "DAT_00401006", "new row"])   # DAT_ labels are never refreshed
    run("refresh_references.py", f"{d}/repo", f"{d}/refresh.csv", "--text", "notes.md")
    gv = open(f"{out}/global_variables.csv").read()
    fr = open(f"{out}/function_renames.csv").read()
    notes = open(f"{d}/repo/notes.md").read()
    return [("refresh: history kept, the later mention refreshed",
             "(was old_name) and new_name is read twice" in gv),
            ("refresh: a name that is still in use is left alone", "reads new_name and still_used;" in fr),
            ("refresh: a 'were a / b' list is history", "were old_name / still_used" in fr),
            ("refresh: --text files are refreshed", notes.startswith("new_name feeds"))]


def check_new_row_comment(d):
    out = f"{d}/fw"
    write(f"{out}/global_variables.csv", "address,name,type,comment\n0x00401000,existing,word,\n")
    evidence = "word " * 78 + "cm848_calculateSomethingLong is the reader, plus more words after it"
    row = {"kind": "new_global", "verdict": "confirmed", "address": "0x00401010", "new": "fresh_value", "type": "word",
           "evidence": evidence}
    write(f"{d}/aligned_T2_a.jsonl", json.dumps(row) + "\n")
    run("apply_extras.py", out, f"{d}/newrows.csv", "2", f"{d}/aligned_T2_a.jsonl")
    line = [l for l in open(f"{out}/global_variables.csv").read().split("\n") if l.startswith("0x00401010,")]
    comment = line[0].split(",", 3)[3] if line else ""
    today = datetime.date.today().isoformat()
    return [("new row: comment cut at a word boundary and marked",
             comment.endswith(f"word ... (new row {today})") and "cm848_calc" not in comment and len(comment) < 420)]



def firmware_dir(out, gv_rows, fr_rows=(), sd_rows=()):
    write(f"{out}/global_variables.csv", "address,name,type,comment\n" + "".join(r + "\n" for r in gv_rows))
    write(f"{out}/function_renames.csv", "address,name,plate_comment\n" + "".join(r + "\n" for r in fr_rows))
    write(f"{out}/structure_definitions.csv",
          "struct_name,address,field_name,type,size,comment,dependency,Status\n" + "".join(r + "\n" for r in sd_rows))
    for name, header in (("arrays.csv", "address,array_name,element_type,element_count,comment"),
                         ("mpc555_registers.csv", "address,name,type,comment"),
                         ("function_definitions.csv", "function_address,function_name,param_index,name,type,comment"),
                         ("local_variables.csv", "function_address,function_name,old_name,new_name,type,comment")):
        write(f"{out}/{name}", header + "\n")


def check_gate(d):
    out = f"{d}/fw"
    firmware_dir(out, ["0x00401000,old_global,word,", "0x00401002,old_two,word,", "0x00401004,old_three,word,"],
                 ["0x00001000,cm848_oldName,old plate", "0x00001100,cm848_sharedOld,old plate"])
    rows = [{"kind": "function", "verdict": "confirmed", "address": "0x00001000", "old": "cm848_oldName",
             "new": "cm848_initValve", "plate_comment": "Sets the valve up."},
            {"kind": "global", "verdict": "confirmed", "address": "0x00401000", "old": "old_global",
             "new": "valve_position_command", "evidence": "word " * 78 + "cm848_calculateSomethingLong reads it"},
            {"kind": "global", "verdict": "confirmed", "address": "0x00401002", "old": "old_two", "new": "valve_init_state"},
            {"kind": "global", "verdict": "confirmed", "address": "0x00401004", "old": "old_three", "new": "valve_limit_cal"},
            {"kind": "function", "verdict": "confirmed", "address": "0x00001100", "old": "cm848_sharedOld",
             "new": "sharedValveFunction", "plate_comment": "Shared with the other firmware."}]
    write(f"{d}/aligned.jsonl", "".join(json.dumps(r) + "\n" for r in rows))
    _, gate = run("apply_renames.py", out, f"{d}/aligned.jsonl")
    problems = [l for l in gate.split("\n") if l.startswith("PROBLEM")]
    write(f"{d}/clean.jsonl", json.dumps(rows[1]) + "\n")
    code, _ = run("apply_renames.py", out, f"{d}/clean.jsonl", "--out", f"{d}/map.csv", "--apply")
    row = [l for l in open(f"{out}/global_variables.csv").read().split("\n") if l.startswith("0x00401000,")]
    return [("gate: init is a banned word (function and data names)",
             any("cm848_initValve" in l and "banned" in l for l in problems)
             and any("valve_init_state" in l and "banned" in l for l in problems)),
            ("gate: _cal outside the EEPROM mirror is refused", any("valve_limit_cal" in l and "_cal" in l for l in problems)),
            ("gate: a clean row raises no problem", not any("valve_position_command" in l for l in problems)),
            ("gate: an unprefixed (shared) function name is allowed", not any("sharedValveFunction" in l for l in problems)),
            ("gate: --apply renames the row; its comment is cut at a word boundary + (was old)",
             code == 0 and bool(row) and row[0].startswith("0x00401000,valve_position_command,word,")
             and row[0].endswith("word ... (was old_global)"))]


def check_struct_type_rename(d):
    out = f"{d}/fw"
    firmware_dir(out, ["0x00401100,old_state_t_00401100,old_state_t,", "0x00401200,,old_state_t,"],
                 sd_rows=["old_state_t,0x00401100,a,word,2,first,,verified",
                          "old_state_t,0x00401100,b,word,2,second,,verified",
                          "old_state_t,0x00401200,,,,second instance - marker only,,verified"])
    run("rename_struct_types.py", out, f"{d}/map.csv", "old_state_t=new_state_t@0x00401100=valve_state")
    sd = open(f"{out}/structure_definitions.csv").read()
    gv = open(f"{out}/global_variables.csv").read()
    old_cpp = ("// Function: f @ 0x00001000\nvoid f(void)\n{\n  old_state_t *p;\n  old_state_t_00401100.a = 1;\n"
               "  old_state_t_00401200.b = 2;\n  return;\n}\n")
    new_cpp = ("// Function: f @ 0x00001000\nvoid f(void)\n{\n  new_state_t *p;\n  valve_state.a = 1;\n"
               "  new_state_t_00401200.b = 2;\n  return;\n}\n")
    write(f"{d}/old.cpp", old_cpp)
    write(f"{d}/new.cpp", new_cpp)
    code, proof = run("reverse_names.py", f"{d}/old.cpp", f"{d}/new.cpp", f"{d}/map.csv", "--ignore-comments")
    return [("struct type: every struct row and type column renamed, the instance named",
             "old_state_t" not in sd and sd.count("new_state_t,") == 3
             and "0x00401100,valve_state,new_state_t," in gv and "0x00401200,,new_state_t," in gv),
            ("struct type: its mapping proves the rename (the unnamed instance's default label too)",
             code == 0 and "EQUIVALENT" in proof and "NOT" not in proof)]


def check_extras_stage1(d):
    out = f"{d}/fw"
    firmware_dir(out, ["0x00401300,valve_instance,valve_t,", "0x00401302,valve_instance.old_field,,",
                       "0x00401400,junk_row,word,"],
                 sd_rows=["valve_t,0x00401300,first_field,word,2,one,,verified",
                          "valve_t,0x00401300,old_field,word,2,two,,verified"])
    rows = [{"kind": "struct_field", "verdict": "confirmed", "struct": "valve_t", "old": "old_field", "new": "new_field"},
            {"kind": "note", "text": "DELETE 0x00401400 junk_row: an auto-label with no users"}]
    write(f"{d}/aligned.jsonl", "".join(json.dumps(r) + "\n" for r in rows))
    run("apply_extras.py", out, f"{d}/map.csv", "1", f"{d}/aligned.jsonl")
    sd = open(f"{out}/structure_definitions.csv").read()
    gv = open(f"{out}/global_variables.csv").read()
    kinds = [r["kind"] for r in csv.DictReader(open(f"{d}/map.csv"))] if os.path.exists(f"{d}/map.csv") else []
    return [("extras stage 1: field renamed in the struct and its member-label row",
             "valve_t,0x00401300,new_field,word,2,two" in sd and "valve_instance.new_field" in gv),
            ("extras stage 1: a DELETE note removes the row and is mapped", "junk_row" not in gv and kinds == ["field", "delete"])]

def main():
    fails = 0
    with tempfile.TemporaryDirectory() as d:
        checks = []
        for i, fn in enumerate((check_common, check_proof, check_align, check_refresh, check_new_row_comment, check_gate,
                                 check_struct_type_rename, check_extras_stage1)):
            sub = os.path.join(d, str(i))
            os.makedirs(sub)
            checks += fn(sub)
    for name, ok in checks:
        print(f"[{'PASS' if ok else 'FAIL'}] {name}")
        fails += not ok
    print(f"\n{'ALL PASS' if fails == 0 else str(fails) + ' FAILED'}")
    sys.exit(1 if fails else 0)


if __name__ == "__main__":
    main()
