"""Round 93 (CM550): the engine position signal input dispatcher and its configuration byte (found with the switch
case row 0x171aa, which apply_r93_switchcase.py removes).
- 0x17150 cm550_canControllerConfigInit -> cm550_initializeEnginePositionSignalInputs: no CAN register is involved;
  it is a four-way switch on the byte 0x807e9d that calls the TPU set-up of that wheel configuration.
- 0x807e9d speed_measurement_mode -> engine_position_signal_configuration (byte): e2m 11CA +3 EPCMTY
  'ENGINE_POSITION_SIGNAL_CONFIG: defines currently configure(d) wheel'; byte accesses only.
Idempotent. usage: apply_r93_position_inputs.py <repo> <map.csv>"""
import os
import re
import sys

repo, map_out = os.path.abspath(sys.argv[1]), sys.argv[2]
R = "PR #53 round 93"
O = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
FUNCTION = (0x00017150, "cm550_initializeEnginePositionSignalInputs",
            "Sets up the engine position signal inputs for the configured wheel: a switch on engine_position_signal_configuration (0-3; any "
            "other value does nothing) - 0: mc68k_initializeTpuChannel10PrimarySpeedInputDivided and the functions at 0x19ac2 / 0x19aca; 1: "
            "0x19caa, mc68k_initializeTpuChannel0MissingToothInput and 0x19e8e; 2: 0x1a350, 0x1a47c and 0x1a52a; 3: "
            "mc68k_initializeTpuChannel10PrimarySpeedInputIfEnabled, 0x1a89a and 0x1a8a2. Called by mc68k_applicationMain at start-up and by "
            "cm550_calculateEngineSpeed after the primary speed sensor timeout has run out with the word 0x80cd06 set (it clears that word "
            "first). No CAN register is involved")
GLOBAL = (0x00807e9d, "engine_position_signal_configuration", "byte",
          "e2m 11CA +3 EPCMTY 'ENGINE_POSITION_SIGNAL_CONFIG: defines currently configure(d) wheel' (the e2m range says 0 - 1; the code "
          "handles 0-3): cm550_initializeEnginePositionSignalInputs switches on it to set up the TPU inputs of that wheel configuration. "
          "Byte accesses only (7 direct)")
pairs = []
F = os.path.join(O, "function_renames.csv")
t = open(F, newline="").read()
key = f"0x{FUNCTION[0]:08x}"
m = re.search(rf"^{key},([^,\r\n]*)(?:,([^\r\n]*))?$", t, re.M)
assert m, key
if m.group(1) != FUNCTION[1]:
    old = m.group(1)
    earlier = f" | earlier note: {m.group(2)}" if m.group(2) else ""
    t = t[:m.start()] + f"{key},{FUNCTION[1]},{FUNCTION[2]} (was {old}; {R}){earlier}" + t[m.end():]
    open(F, "w", newline="").write(t)
    for k in ("function_definitions.csv", "local_variables.csv"):
        p = os.path.join(O, k)
        c = open(p, newline="").read()
        c2 = re.sub(rf"^({key},){re.escape(old)},", lambda x: x.group(1) + FUNCTION[1] + ",", c, flags=re.M | re.I)
        if c2 != c:
            open(p, "w", newline="").write(c2)
    pairs.append((key, FUNCTION[1], old))
G = os.path.join(O, "global_variables.csv")
lines = open(G, newline="").read().split("\n")
key = f"0x{GLOBAL[0]:08x}"
i = next(k for k, l in enumerate(lines) if l[:10].lower() == key and l[10:11] == ",")
parts = lines[i].split(",", 3)
if parts[1] != GLOBAL[1]:
    old, old_comment = parts[1], (parts[3] if len(parts) > 3 else "")
    lines[i] = f"{key},{GLOBAL[1]},{GLOBAL[2]},{GLOBAL[3]} (was {old}; {R})" + (f" | earlier note: {old_comment}" if old_comment else "")
    open(G, "w", newline="").write("\n".join(lines))
    pairs.append((key, GLOBAL[1], old))
if pairs:
    with open(map_out, "w") as fh:
        fh.write("address,name,old_label,kind,dims\n")
        for k, new, old in pairs:
            fh.write(f"{k},{new},{old},symbol,1\n")
print(len(pairs), "renames")
