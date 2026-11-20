"""Stage 9b: the wave-14 holds, applied (user 2026-11-20: "I don't understand why anything is waiting for me").
- Twins shared with CM550: the alpha functions (CM550 timingProtectionFlagsOrchestrator @ 0xc582 ORs the same five
  condition results under the same enable bits 0x400 / 0x800 / 0x1000 / 0x2000 / 0x8000 and ramps alpha the same way as
  CM848 0xe3a4, so the five condition functions pair one to one; CM550 vp44RpmBasedFaultDetector @ 0xc326 has the same
  LSG / AFC alpha timeouts, ramp call and blend output as CM848 0xe518), the PGN 65251 payload builder (both fill a buffer
  from the engine configuration words) and the EEC1 sender (both build and send PGN 61444). Each pair takes one
  unprefixed shared name (the convergence convention), in both firmwares.
- The three development mode functions (the owner's 2026-05-25 review notes stay verbatim in the plates).
- The two struct fixes: boost_pressure_state_t -> charge_flow_estimate_terms_t (fields named from e2m 177D +2..+C and
  177B +0 / +2), engine_sync_state_t -> fuel_pressure_governor_state_t, 7 bytes (8019 +5 is a word).
Writes map_stage9b_cm848.csv and map_stage9b_cm550.csv (with type / field rows for the proof).
usage: apply_stage9b.py <stage9 dir> <repo> [--dry-run]"""
import json
import os
import re
import subprocess
import sys

here, repo = sys.argv[1:3]
dry = "--dry-run" in sys.argv
O848 = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
O550 = os.path.join(repo, "firmware", "CM550_J90350.00_analysis", "output")
GATE = os.path.join(repo, "firmware", "scripts", "rename_waves", "apply_renames.py")
held = {h["address"]: h for h in json.load(open(os.path.join(here, "held_W14.json")))}


def plates(out):
    d = {}
    for line in open(os.path.join(out, "function_renames.csv"), errors="replace"):
        if line.startswith("0x"):
            p = line.rstrip("\r\n").split(",", 2)
            d[int(p[0], 16)] = (p[1], p[2] if len(p) > 2 else "")
    return d


p848, p550 = plates(O848), plates(O550)
# (CM848 address, new shared name, CM550 address, one-line CM550 plate)
SHARED = [
    (0xe3a4, "calculateAlphaBase", 0xc582, "ORs the five alpha condition results (enable bits 0x400 / 0x800 / 0x1000 /"
     " 0x2000 / 0x8000 of the feature word) and ramps the alpha base (_APAPBA) toward 0x4000 with two rates around a"
     " threshold; 0 when no condition is set"),
    (0xe518, "calculateAlpha", 0xc326, "the alpha source selector: the LSG / AFC alpha timeouts, the call of"
     " calculateAlphaBase and the alpha state / blend factor outputs"),
    (0xe164, "calculateAlphaFuelRateResult", 0xc404, "the alpha fuel rate condition (_APFLRTAP, enable bit 0x1000)"),
    (0xe248, "calculateAlphaLowSpeedGovernorResult", 0xc4b2, "the alpha low speed governor condition (_APLSAP, enable"
     " bit 0x400)"),
    (0xe2cc, "calculateAlphaAirFuelControlResult", 0xc504, "the alpha air fuel control condition (_APAFSS, enable bit"
     " 0x800)"),
    (0xe218, "calculateAlphaOnGovernorResult", 0xc496, "the alpha on-governor condition (_APGVAP, enable bit 0x2000)"),
    (0xe360, "calculateAlphaLowAmbientAirPressureResult", 0xc556, "the alpha low ambient air pressure condition"
     " (_APAAPRSS, enable bit 0x8000)"),
    (0x1b3a0, "buildPgn65251EngineConfiguration1Payload", 0x3320e, "fills the PGN 65251 engine configuration payload"
     " buffer (param_1) from the engine configuration words, starting with the idle point speed"),
    (0x2588c, "sendPgn61444ElectronicEngineController1Message", 0x32c76, "builds EEC1 (the torque mode from the speed"
     " control mode and the fuel limit state, then the engine speed) and sends it with cm550_sendCanMessage"),
]
OWN = [(0x21624, "cm848_exitDevelopmentMode"), (0x21668, "cm848_enterDevelopmentMode"),
       (0x21694, "cm848_forceExitDevelopmentMode")]


def rename_plate(plate, old, extra):
    """The plate with `extra` added and the rename note in the repo order: an existing '(was X)' at the end of the head
    (before any '| earlier note:') becomes '(was <old>, earlier X)'; otherwise '(was <old>)' is appended to the head."""
    head, sep, rest = plate.partition(" | earlier note: ")
    m = re.search(r"\s*\(was ([^)]*)\)\s*$", head)
    if m:
        head = head[:m.start()].rstrip() + f" {extra} (was {old}, earlier {m.group(1)})"
    else:
        head = head.rstrip() + f" {extra} (was {old})"
    return head.strip() + (sep + rest if sep else "")


f848, f550 = [], []
for a848, new, a550, cm550_role in SHARED:
    old, plate = p848[a848]
    h = held.get(f"0x{a848:08x}")
    twin = f" Shared name with CM550 0x{a550:x} (the same function)."
    if h and h.get("plate_comment"):                    # a held wave-14 rename: the agent's plate, the old plate kept
        text = " ".join(h["plate_comment"].split()) + twin
        text = f"{text} (was {old})" + (f" | earlier note: {plate}" if plate and plate[:40] not in text else "")
    else:                                               # an applied cm848_ name: the plate stays, the prefix goes
        text = rename_plate(plate, old, twin.strip())
    f848.append({"kind": "function", "verdict": "confirmed", "address": f"0x{a848:08x}", "old": old, "new": new,
                 "plate_comment": text})
    old550, plate550 = p550[a550]
    text550 = f"Twin of CM848 0x{a848:x} (verified stage 9b): {cm550_role}. (was {old550})"
    if plate550:
        text550 += f" | earlier note: {plate550}"
    f550.append({"kind": "function", "verdict": "confirmed", "address": f"0x{a550:08x}", "old": old550, "new": new,
                 "plate_comment": text550})
for a848, new in OWN:
    old, plate = p848[a848]
    h = held[f"0x{a848:08x}"]
    text = " ".join(h["plate_comment"].split())
    assert "jlaustill review" in text, a848               # the owner's note stays verbatim, after the rename note
    head, sep, note = text.partition(" | jlaustill review")
    text = f"{head} (was {old})" + (f" | jlaustill review{note}" if sep else "")
    assert plate and plate[:40] in text, (a848, plate[:40])
    f848.append({"kind": "function", "verdict": "confirmed", "address": f"0x{a848:08x}", "old": old, "new": new,
                 "plate_comment": text})
for path, rows in (("gate_input_stage9b_cm848.jsonl", f848), ("gate_input_stage9b_cm550.jsonl", f550)):
    with open(os.path.join(here, path), "w") as f:
        f.write("".join(json.dumps(r) + "\n" for r in rows))
# CM550: the gate needs CM848-only inputs (arrays.csv, mpc555_registers.csv), so it checks a temporary copy with empty
# stand-ins; the nine CM550 rows are then written here (none has a function_definitions / local_variables row)
import shutil  # noqa: E402
gate550 = os.path.join(here, "gate9b_cm550")
os.makedirs(gate550, exist_ok=True)
for name in ("function_renames.csv", "global_variables.csv", "function_definitions.csv", "local_variables.csv"):
    shutil.copy(os.path.join(O550, name), os.path.join(gate550, name))
for name in ("arrays.csv", "mpc555_registers.csv"):
    open(os.path.join(gate550, name), "w").write("")
for out, path, apply in ((O848, "gate_input_stage9b_cm848.jsonl", not dry), (gate550, "gate_input_stage9b_cm550.jsonl", False)):
    g = subprocess.run([sys.executable, GATE, out, os.path.join(here, path)] + (["--apply"] if apply else []),
                       capture_output=True, text=True)
    lines = (g.stdout + g.stderr).strip().splitlines()
    print(os.path.basename(os.path.dirname(out)), "|", " / ".join(l for l in lines if "PROBLEM" in l or "renames:" in l
                                                                  or "applied" in l or "follow" in l)[:400])
    assert g.returncode == 0 and not any("PROBLEM" in l for l in lines), g.stderr[-400:]
if dry:
    sys.exit(0)
fpath = os.path.join(O550, "function_renames.csv")
flines = open(fpath, newline="").read().split("\n")
by = {r["address"]: r for r in f550}
for i, line in enumerate(flines):
    a = line.split(",", 1)[0]
    if a in by:
        assert line.split(",")[1].rstrip("\r") == by[a]["old"], (a, line[:60])
        flines[i] = f"{a},{by[a]['new']},{' '.join(by[a]['plate_comment'].split())}"
open(fpath, "w", newline="").write("\n".join(flines))

# the structs (CM848)
STRUCTS = {
    "boost_pressure_state_t": ("charge_flow_estimate_terms_t", "0x0040a406", "boost_pressure_state_t_0040a406",
                               "charge_flow_estimate_terms", {
        "load_input": ("intake_manifold_temperature_rankine", "e2m 177D +2 CHP_Intake_Manifold_Tmptr_R: the intake"
                       " manifold temperature in degrees Rankine (intake_manifold_temperature_filtered + 0x7300)"),
        "rpm_modifier": ("volumetric_efficiency_mach", "e2m 177D +4 CHP_Veff_Mach: the volumetric efficiency test point"
                         " based on engine speed and stroke"),
        "lookup_result": ("volumetric_efficiency_square_root", "e2m 177D +6 CHP_Veff_Sqrt: the volumetric efficiency test"
                          " point based only on energy"),
        "computed_value": ("flow_area_constant", "e2m 177D +8 CHP_Flow_Area_Constant"),
        "pressure_ratio": ("pressure_ratio", "e2m 177D +A CHP_Pratio: the charge flow pressure ratio"),
        "reserved_0a": ("charge_flow_source", "e2m 177D +C Charge_Flow_Source: 0 primary / 1 backup"),
        "fresh_air_mass_flow_filtered": ("fresh_air_mass_flow_filtered", "e2m 177B +0 Fresh_Air_Flow: the fresh air"
                                         " flow virtual sensor (lb/min)"),
        "reserved_0e": ("fresh_air_flow_source", "e2m 177B +2 Fresh_Air_Flow_Source: 0 primary / 1 backup"),
    }),
    "engine_sync_state_t": ("fuel_pressure_governor_state_t", "0x0040b87f", "engine_sync_state_t_0040b87f",
                            "fuel_pressure_governor_state", {
        "fuel_pressure_governor_mode": ("fuel_pressure_governor_mode", None),
        "fuel_pressure_governor_demand": ("fuel_pressure_governor_demand", None),
        "fuel_metering_command": ("fuel_metering_command", None),
        "reserved_05": ("filtered_battery_voltage", "e2m 8019 +5 HPCR_Filtered_Battery_Voltage (volts): stored by"
                        " cm848_filterEngineSensorValue (sth) and read by cm848_calculateFuelMeteringCommand for its"
                        " battery voltage compensation (lhz) - a word, so the struct is 7 bytes (was the 1-byte"
                        " reserved_05)"),
    }),
}
INSTANCE_COMMENT = {
    "0x0040a406": "The charge flow estimate terms (e2m 177D +2..+C and 177B +0 / +2, table-resolved): the intake manifold"
                  " temperature in Rankine, the two volumetric efficiency test points, the flow area constant, the"
                  " pressure ratio, the charge flow source, then the fresh air flow and its source (the struct was"
                  " boost_pressure_state_t with guessed boost field names).",
    "0x0040b87f": "The fuel pressure governor state (e2m 8019 +0..+6, table-resolved): the governor mode, the demand,"
                  " the fuel metering command and the filtered battery voltage; 7 bytes (the struct was"
                  " engine_sync_state_t, 6 bytes with a byte reserved_05 over the voltage word).",
}
spath = os.path.join(O848, "structure_definitions.csv")
lines = open(spath, newline="").read().split("\n")
for i, line in enumerate(lines):
    for old_type, (new_type, address, _, _, fields) in STRUCTS.items():
        if line.startswith(old_type + ","):
            parts = line.split(",", 5)
            assert parts[1] == address, (old_type, parts[1])
            new_field, comment = fields[parts[2]]
            parts[0], parts[2] = new_type, new_field
            if old_type == "engine_sync_state_t" and parts[2] == "filtered_battery_voltage":
                parts[3], parts[4] = "word", "2"
            if comment:
                rest = parts[5].split(",")
                # comment column: quote it (this file uses a quote-aware parser); keep dependency / status columns
                tail = parts[5][len(parts[5].rsplit(",", 2)[0]):]
                parts[5] = '"' + comment.replace('"', "'") + '"' + tail
            lines[i] = ",".join(parts)
open(spath, "w", newline="").write("\n".join(lines))
gpath = os.path.join(O848, "global_variables.csv")
g = open(gpath, newline="").read().split("\n")
for i, line in enumerate(g):
    for old_type, (new_type, address, old_instance, new_instance, fields) in STRUCTS.items():
        if line.startswith(address + ","):
            a, name, typ, c = (line.split(",", 3) + [""])[:4]
            assert (name, typ) == (old_instance, old_type), (name, typ)
            g[i] = ",".join([a, new_instance, new_type, INSTANCE_COMMENT[address] + f" (was {old_instance})" +
                             (f" | earlier note: {c}" if c else "")])
        elif "," in line and line.split(",")[1].startswith(old_instance + "."):
            a, name = line.split(",")[:2]
            field = name.split(".", 1)[1]
            g[i] = line.replace(f"{old_instance}.{field}", f"{new_instance}.{fields[field][0]}", 1)
open(gpath, "w", newline="").write("\n".join(g))
with open(os.path.join(here, "map_stage9b_cm848.csv"), "w") as f:
    f.write("address,name,old_label,kind\n")
    for r in f848:
        f.write(f"{r['address']},{r['new']},{r['old']},function\n")
    for old_type, (new_type, address, old_instance, new_instance, fields) in STRUCTS.items():
        f.write(f",{new_type},{old_type},type\n{address},{new_instance},{old_instance},global\n")
        for old_field, (new_field, _) in fields.items():
            if new_field != old_field:
                f.write(f",{new_field},{old_field},field\n")
with open(os.path.join(here, "map_stage9b_cm550.csv"), "w") as f:
    f.write("address,name,old_label,kind\n")
    for r in f550:
        f.write(f"{r['address']},{r['new']},{r['old']},function\n")
print(f"applied {len(f848)} CM848 / {len(f550)} CM550 function renames and the two structs")
