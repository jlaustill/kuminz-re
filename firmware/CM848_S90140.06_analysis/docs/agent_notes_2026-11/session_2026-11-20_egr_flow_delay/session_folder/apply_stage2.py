"""Stage 2 (shape): the two delay lines as delay_line_t, the helper prototypes, the signed e2m 177F words.
Usage: apply_stage2.py <firmware output dir>
- structure_definitions.csv: a delay_line_t template (word[256] ring + byte write index + spare byte); the six
  e2m 'S' (signed) words of egr_flow_estimate_terms_t become short.
- global_variables.csv: the two instances; the type-only byte row at 0x3fa5a0 (the boot ROM's call target, the RAM
  copy of mpc555_cmfEraseBlocks) is removed because the second delay line covers it.
- function_definitions.csv: full prototypes for cm848_delayUnsignedSample / cm848_delaySignedSample."""
import os
import sys

out = sys.argv[1]
TEMPLATE = [
    "# Delay line: a ring of 256 samples and its write index (cm848_delayUnsignedSample / cm848_delaySignedSample)",
    "# Total size: 514 bytes - instances egr_oxygen_fraction_delay_line (0x003fa1b6) and egr_mass_flow_delay_line "
    "(0x003fa3b8)",
    'delay_line_t,,samples,word,512,"The 256 samples: each call stores its sample at write_index (sthx) and reads '
    'the one written delay_samples calls earlier at (write_index - delay_samples) mod 256",,verified',
    'delay_line_t,,write_index,byte,1,"The slot of the next sample: lbz / stb at +0x200; advanced once per call and '
    'wraps at 256 (191 / 215 in the RAM dump)",,verified',
    'delay_line_t,,spare,byte,1,"Pads the record to 514 bytes (the second line starts at +0x202); no access found; '
    '0 in the RAM dump",,needs_review',
]
SIGNED = {"egr_mass_flow_before_delay", "downstream_egr_mass_flow", "upstream_egr_mass_flow",
          "downstream_egr_corrected_flow", "downstream_egr_pressure_ratio", "upstream_egr_corrected_flow"}

path = os.path.join(out, "structure_definitions.csv")
lines = open(path).read().split("\n")
signed = 0
for i, line in enumerate(lines):
    p = line.split(",", 5)
    if p[0] == "egr_flow_estimate_terms_t" and len(p) > 4 and p[2] in SIGNED:
        assert p[3] == "word", p
        p[3] = "short"
        lines[i] = ",".join(p)
        signed += 1
assert signed == len(SIGNED), signed
anchor = lines.index("# Fuel Blend State - fuel demand blending and mode selection")
lines[anchor:anchor] = TEMPLATE
open(path, "w").write("\n".join(lines))

GLOBALS = {
    0x003fa1b6: "0x003fa1b6,egr_oxygen_fraction_delay_line,delay_line_t,The transport delay line of the residual "
                "oxygen fraction: cm848_calculateDelayedEgrFlowAndFraction writes residual_oxygen_fraction_before_delay "
                "into it every 10 ms (cm848_delayUnsignedSample) and reads back the sample from "
                "egr_flow_estimate_terms.oxygen_flow_delay_milliseconds / 10 passes earlier; that sample is filtered into "
                "egr_flow_estimate_terms.egr_oxygen_fraction (e2m 177F +0 CHP_O2_Frac_EGR). RAM dump: all samples 8192 "
                "(engine stopped), write index 191. Inside the boot kernel's RAM image (0x3f9800-0x3fdb30): the "
                "application reuses this RAM after boot.",
    0x003fa3b8: "0x003fa3b8,egr_mass_flow_delay_line,delay_line_t,The transport delay line of the EGR mass flow: "
                "cm848_calculateDelayedEgrFlowAndFraction writes egr_flow_estimate_terms.egr_mass_flow_before_delay "
                "into it every 10 ms (cm848_delaySignedSample) and reads back the sample from "
                "egr_flow_estimate_terms.egr_flow_delay_milliseconds / 10 passes earlier; that sample is filtered into "
                "egr_mass_flow_delayed_filtered. RAM dump: all samples 0, write index 215. It covers the boot ROM's "
                "call target 0x3fa5a0 (the RAM copy of mpc555_cmfEraseBlocks), so the thunk stage keeps it and points "
                "those boot calls at the ROM function (call overrides).",
}
path = os.path.join(out, "global_variables.csv")
lines = open(path).read().split("\n")
removed = [l for l in lines if l == "0x003fa5a0,,byte,"]
assert len(removed) == 1, removed
lines = [l for l in lines if l != "0x003fa5a0,,byte,"]
for a, row in sorted(GLOBALS.items()):
    assert not any(l.startswith(f"0x{a:08x},") for l in lines), hex(a)
    for i, l in enumerate(lines):
        if l.startswith("0x") and int(l.split(",", 1)[0], 16) > a:
            lines.insert(i, row)
            break
open(path, "w").write("\n".join(lines))

PROTOTYPES = [
    "0x000123dc,cm848_delayUnsignedSample,return,,word,The sample written delay_samples calls earlier (lhzx r3: "
    "zero-extended)",
    "0x000123dc,cm848_delayUnsignedSample,0,delay_line,delay_line_t *,The delay line (r3)",
    "0x000123dc,cm848_delayUnsignedSample,1,sample,word,The new sample (r4) - stored with sthx",
    "0x000123dc,cm848_delayUnsignedSample,2,delay_samples,uint,The delay in calls (r5): the read position is "
    "(write_index - delay_samples) mod 256",
    "0x00012404,cm848_delaySignedSample,return,,sword,The sample written delay_samples calls earlier (lhax r3: "
    "sign-extended)",
    "0x00012404,cm848_delaySignedSample,0,delay_line,delay_line_t *,The delay line (r3)",
    "0x00012404,cm848_delaySignedSample,1,sample,sword,The new sample (r4) - stored with sthx",
    "0x00012404,cm848_delaySignedSample,2,delay_samples,uint,The delay in calls (r5): the read position is "
    "(write_index - delay_samples) mod 256",
]
path = os.path.join(out, "function_definitions.csv")
lines = open(path).read().split("\n")
assert not any(l.startswith(("0x000123dc,", "0x00012404,")) for l in lines)
for i, l in enumerate(lines):
    if l.startswith("0x") and int(l.split(",", 1)[0], 16) > 0x12404:
        lines[i:i] = PROTOTYPES
        break
open(path, "w").write("\n".join(lines))
print(f"signed fields {signed}, template rows {len(TEMPLATE)}, globals {len(GLOBALS)} (removed 0x3fa5a0 byte row), "
      f"prototype rows {len(PROTOTYPES)}")
