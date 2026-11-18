"""Fold the per-channel MIOS struct types into mios_mdasm_t / mios_mpwmsm_t and type the drivers."""
import sys

OUT = sys.argv[1]
STRUCTS, GLOBALS, FUNCDEFS = f"{OUT}/structure_definitions.csv", f"{OUT}/global_variables.csv", f"{OUT}/function_definitions.csv"

PWM = {0x306008: 1, 0x306010: 2, 0x306018: 3, 0x306080: 16, 0x306088: 17, 0x306090: 18, 0x306098: 19}
DASM = {0x306060: 12, 0x306068: 13, 0x306070: 14, 0x306078: 15, 0x3060d8: 27}
FOLDED_TYPES = {f"mios_mpwmsm{n}_t" for n in PWM.values()} | {"mios_mdasm12_t", "mios_mdasm15_t", "mios_mdasm27_t"}

# structure_definitions.csv: drop the per-channel copies, AR + BR -> AR_BR, add marker rows
out, removed = [], 0
for line in open(STRUCTS).read().split("\n"):
    head = line.split(",", 1)[0]
    if head in FOLDED_TYPES:
        removed += 1; continue
    if line.startswith("mios_mdasm_t,0x00306058,AR,"):
        line = ("mios_mdasm_t,0x00306058,AR_BR,dword,4,A and B registers as one 32-bit pair (AR = high half / "
                "BR = low half): the drivers read and write them with one access - edge captures in input mode "
                "/ the PWM compare pair in output mode,,verified")
    elif line.startswith("mios_mdasm_t,0x00306058,BR,"):
        continue
    out.append(line)
    if line.startswith("mios_mpwmsm_t,0x00306000,SCR,"):
        for a, n in sorted(PWM.items()):
            out.append(f"mios_mpwmsm_t,0x{a:08x},,,,MPWMSM{n} instance - marker only (was mios_mpwmsm{n}_t),,verified")
    if line.startswith("mios_mdasm_t,0x00306058,SCRD,"):
        for a, n in sorted(DASM.items()):
            was = f"was mios_mdasm{n}_t" if f"mios_mdasm{n}_t" in FOLDED_TYPES else "was byte-typed register rows"
            note = " - SCRD 0x405 = enable / 0x205 = mode" if n == 27 else ""
            out.append(f"mios_mdasm_t,0x{a:08x},,,,MDASM{n} instance - marker only ({was}){note},,verified")
open(STRUCTS, "w").write("\n".join(out))
print("struct rows removed:", removed)

# global_variables.csv: instance names + generic types; interior register rows keep only a label
INSTANCE = {0x306000: ("mios_mpwmsm0", "mios_mpwmsm_t")}
INSTANCE.update({a: (f"mios_mpwmsm{n}", "mios_mpwmsm_t") for a, n in PWM.items()})
INSTANCE.update({a: (f"mios_mdasm{n}", "mios_mdasm_t") for a, n in DASM.items()})
INSTANCE[0x306058] = ("mios_mdasm11", "mios_mdasm_t")
INTERIOR_UNTYPE = {0x30606a, 0x30606e, 0x306072, 0x306076}
g_out, renamed = [], []
for line in open(GLOBALS).read().split("\n"):
    p = line.split(",", 3)
    if p[0].startswith("0x"):
        a = int(p[0], 16)
        if a in INSTANCE:
            name, typ = INSTANCE[a]
            comment = p[3] if len(p) > 3 else ""
            if p[1] != name:
                comment = (comment + " " if comment else "") + f"(was {p[1]})"
                renamed.append((p[1], name))
            line = f"{p[0]},{name},{typ},{comment}"
        elif a in INTERIOR_UNTYPE:
            line = f"{p[0]},{p[1]},,{p[3] if len(p) > 3 else ''}"
    g_out.append(line)
open(GLOBALS, "w").write("\n".join(g_out))
print("instances renamed:", renamed)

# function_definitions.csv: driver base pointers
DRIVER_TYPES = {
    "mpc555_miosCheckChannelFeedback": "mios_mdasm_t *", "mpc555_miosSetChannelInputMode": "mios_mdasm_t *",
    "mpc555_miosEnableChannelPwm": "mios_mdasm_t *", "mpc555_miosSetChannelPwmDuty": "mios_mdasm_t *",
    "mpc555_miosSetChannelPwmPeriod": "mios_mdasm_t *", "mpc555_miosEnablePwmSubmodule": "mios_mpwmsm_t *",
    "mpc555_miosSetPwmSubmoduleDuty": "mios_mpwmsm_t *", "mpc555_miosSetPwmSubmodulePeriodMicroseconds": "mios_mpwmsm_t *",
}
f_out, typed = [], 0
for line in open(FUNCDEFS).read().split("\n"):
    p = line.split(",", 5)
    if len(p) >= 5 and p[1] in DRIVER_TYPES and p[2] == "0":
        p[4] = DRIVER_TYPES[p[1]]
        line = ",".join(p); typed += 1
    f_out.append(line)
open(FUNCDEFS, "w").write("\n".join(f_out))
print("driver parameters typed:", typed)
