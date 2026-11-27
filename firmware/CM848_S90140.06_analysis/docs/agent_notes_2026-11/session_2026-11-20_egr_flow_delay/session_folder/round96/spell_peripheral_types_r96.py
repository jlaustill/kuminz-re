"""Round 96 stage A (CM848): the peripheral struct type names spell their words out (the repository's naming rule: no
invented abbreviations; the MPC555 module and submodule names TPU3 / QADC64 / QSMCM / SCI / QSPI / USIU / MIOS1 /
MMCSM are the manual's and stay). None of these types renders in the decompilation, and each appears only in
structure_definitions.csv and global_variables.csv (no history note names one), so a word-boundary rename of both files
is the whole change; the headers follow. Idempotent; keeps line endings. usage: spell_peripheral_types_r96.py <repo>"""
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
OUT = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
MAP = {
    "tpu3_ch_params_t": "tpu3_channel_parameters_t",
    "tpua_ch1_params_t": "tpu_a_channel_1_parameters_t",
    "tpua_ch9_params_t": "tpu_a_channel_9_parameters_t",
    "tpua_ch12_params_t": "tpu_a_channel_12_parameters_t",
    "tpua_ch14_params_t": "tpu_a_channel_14_parameters_t",
    "tpub_ch0_params_t": "tpu_b_channel_0_parameters_t",
    "tpub_ch11_params_t": "tpu_b_channel_11_parameters_t",
    "tpub_ch14_params_t": "tpu_b_channel_14_parameters_t",
    "qadc64_regs_t": "qadc64_registers_t",
    "qsmcm_sci1_regs_t": "qsmcm_sci1_registers_t",
    "qsmcm_qspi_ctrl_t": "qsmcm_qspi_control_registers_t",
    "qsmcm_txram_t": "qsmcm_transmit_ram_t",
    "qsmcm_recram_t": "qsmcm_receive_ram_t",
    "usiu_memc_t": "usiu_memory_controller_t",
    "usiu_pit_t": "usiu_periodic_interrupt_timer_t",
    "usiu_clock_t": "usiu_clocks_and_reset_t",
    "mios_mmcsm_b_t": "mios_mmcsm_t",
    "mios1_isr_t": "mios1_interrupt_registers_t",
    "eeprom_xfer_state_t": "eeprom_transfer_state_t",
}
PATTERN = re.compile(r"(?<![A-Za-z0-9_])(" + "|".join(map(re.escape, MAP)) + r")(?![A-Za-z0-9_])")
for name in ("structure_definitions.csv", "global_variables.csv"):
    p = os.path.join(OUT, name)
    t = open(p, newline="").read()
    n = len(PATTERN.findall(t))
    for new in MAP.values():
        hits = [l for l in t.split("\n") if re.search(rf"(?<![A-Za-z0-9_]){re.escape(new)}(?![A-Za-z0-9_])", l) and not l.startswith("#")]
        assert not hits or n == 0, f"{new} already in {name}"
    if n:
        E = "\r\n" if "\r\n" in t else "\n"
        lines = t.split(E)
        for i, l in enumerate(lines):
            if not any(f"was {old}" in l for old in MAP):          # history notes keep the old name
                lines[i] = PATTERN.sub(lambda m: MAP[m.group(1)], l)
        open(p, "w", newline="").write(E.join(lines))
    print(f"{name}: {n} references")
with open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "map_r96a_types.csv"), "w") as f:
    f.write("address,name,old_label,kind,dims\n")
    for old, new in MAP.items():
        f.write(f"0x00000000,{new},{old},type,1\n")
