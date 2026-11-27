"""Round 70 stage A: the 6 KB dual-port TPU RAM at 0x302000 and what lives in it. Idempotent (each change keys on
its row and skips when the new text is there).
- cm848_clearRamRegions clears 0x302000-0x3037ff: 6 KB, the MPC555's only RAM that size (its SRAM is 0x3f9800 on), so
  the dual-port TPU RAM. The boot kernel keeps most of its RAM variables there (39 named rows: 30 rendered before this
  stage and 33 after, none by the application; others sit in the SRAM, e.g. eeprom_shadow_header); the application's
  mpc555_initTpuConfiguration loads 0x302000-0x302fff from a ROM table before it sets both TPU module configuration
  registers. (Corrected after ae4338bd, whose message says 'all its variables' and '39 named rows'.)
- An early campaign had laid a TPU3 register map over it (30 TPU3_* rows; the TPU3 registers are tpu_a_mcr /
  tpu_b_mcr at 0x304000 / 0x304400). One renders (TPU3_TPUMCR, the clear's start) and one names a struct
  (TPU3_HSQR1 = the receive ring); the other 28 render nowhere and go.
- The CAN rings tile the RAM: 40 18-byte receive records from 0x302016 and 40 12-byte transmit frames from 0x3022e6,
  ending at boot_can_ring_state (0x3024c6). The wrap bounds prove the counts (0x3022d4 / 0x3024ba are the last
  entries), and mpc555_canTransmitQueuePush proves the frame layout (a TouCAN ID image then 8 data bytes).
- Three stale flat rows sit inside ecu_power_state_flags (keyon_flags_t, 20 bytes, 0x302002-0x302015).
- The ROM table (3 variable-length {offset / count / words} records, 0x5862e-0x591f5) and the two 0xa1a1 words that
  bracket checksum_region_table.first_region.
usage: apply_r70a.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 70"


def load(name):
    return open(os.path.join(O, name)).read().split("\n")


def save(name, lines):
    open(os.path.join(O, name), "w").write("\n".join(lines))


def addr_of(line):
    p = line.split(",", 1)[0]
    return int(p, 16) if p.startswith("0x") else None


def index_of(lines, address):
    idx = [i for i, l in enumerate(lines) if l.startswith(f"0x{address:08x},")]
    assert len(idx) == 1, (hex(address), len(idx))
    return idx[0]


# ---- global_variables.csv ----------------------------------------------------------------------------------------------
G = "global_variables.csv"
lines = load(G)
RAM = "dual_port_tpu_ram"
LOAD = ("0x0005862e,dual_port_tpu_ram_load_table,word[1508],Three {offset / word count / words} records - variable "
        "length so a word array - that mpc555_initTpuConfiguration copies to 0x302000 + offset: 994 words to 0x302000 "
        "/ 348 to 0x302800 / 160 to 0x302ec0 (0x302000-0x302fff of the dual-port TPU RAM) before it sets both TPU "
        "module configuration registers - TPU microcode by that use. It overwrites the boot kernel's variables there "
        "(ecu_power_state_flags / both CAN rings / boot_can_ring_state / crc_ccitt_table / eeprom_block_tracking / ...); "
        f"it ends at first_checksum_region_end_marker ({R})")
if LOAD not in lines:
    # the old TPU3 layer: 28 rows go (27 name-only rows that render nowhere and the junk 'TPU3_HSQR1+1'), two are
    # renamed below
    drop = [l for l in lines if addr_of(l) is not None and 0x302000 <= addr_of(l) < 0x302200
            and l.split(",")[1].startswith("TPU3_") and l.split(",")[1] not in ("TPU3_TPUMCR", "TPU3_HSQR1")]
    assert len(drop) == 28, len(drop)
    for l in drop:
        assert l.split(",")[3] == "" or l.split(",")[3] is None, l
        lines.remove(l)
    i = index_of(lines, 0x302000)
    assert lines[i] == "0x00302000,TPU3_TPUMCR,byte,", lines[i]
    lines[i] = (f"0x00302000,{RAM}_start,byte,The 6 KB RAM 0x302000-0x3037ff that cm848_clearRamRegions clears: the "
                "MPC555's only 6 KB RAM - the dual-port TPU RAM (its SRAM is 0x3f9800 on). The boot kernel keeps its "
                "variables in it; the application loads dual_port_tpu_ram_load_table into 0x302000-0x302fff (was "
                "TPU3_TPUMCR in a TPU3 register map laid over this RAM - the TPU3 registers are tpu_a_mcr / tpu_b_mcr "
                f"at 0x304000 / 0x304400; {R})")
    for address, old, field in ((0x302006, "keyon_state_machine_phase", "state"),
                                (0x30200a, "qadc_a_portqa", "transfer_crc"),
                                (0x302012, "ecm_runtime_accumulator", "runtime_counter")):
        i = index_of(lines, address)
        assert lines[i] == f"0x{address:08x},{old},,", lines[i]
        lines[i] = (f"0x{address:08x},ecu_power_state_flags.{field},,(was {old}: a stale flat row inside the struct; "
                    f"{R})")
    i = index_of(lines, 0x302016)
    assert lines[i] == "0x00302016,TPU3_HSQR1,j1939_rx_msg_t,", lines[i]
    lines[i] = ("0x00302016,boot_can_receive_ring,j1939_rx_msg_t[40],The boot kernel's CAN receive ring: 40 18-byte "
                "records 0x302016-0x3022e5 - mpc555_processCanReceiveBuffer fills it and mpc555_dispatchCanMessageHandlers "
                "reads it through boot_can_ring_state; both wrap past 0x3022d4 (the last record) (was TPU3_HSQR1; "
                f"{R})")
    assert "0x00302017,TPU3_HSQR1+1,," not in lines  # the junk '+1' row went with the 27 dead TPU3_ rows above
    lines.insert(index_of(lines, 0x302016) + 1,
                 "0x003022e6,boot_can_transmit_ring,boot_can_transmit_frame_t[40],The boot kernel's CAN transmit ring: "
                 "40 12-byte frames 0x3022e6-0x3024c5 - mpc555_canTransmitQueuePush queues a frame here while the "
                 "mailbox is busy (it wraps past 0x3024ba - the last frame) and mpc555_manageCan1TransmitBuffer sends "
                 f"them ({R})")
    last = max(i for i, l in enumerate(lines) if addr_of(l) is not None and 0x302000 <= addr_of(l) < 0x303800)
    lines.insert(last + 1, f"0x00303800,{RAM}_end,byte,One past the 6 KB dual-port TPU RAM: cm848_clearRamRegions' "
                           f"bound ({R})")
    j = index_of(lines, 0x592a2)
    lines[j:j] = [LOAD,
                  "0x000591f6,first_checksum_region_end_marker,word,0xa1a1: checksum_region_table.first_region's last "
                  "word - right after dual_port_tpu_ram_load_table; 0x1a1a three times and another 0xa1a1 (0x591fe) "
                  f"follow outside the region ({R})"]
    k = index_of(lines, 0xb75e)
    lines.insert(k + 1, "0x0000b76a,first_checksum_region_start_marker,word,0xa1a1: checksum_region_table.first_region's "
                        f"first word - right before the first code (0xb76c) ({R})")
    save(G, lines)

# ---- structure_definitions.csv -----------------------------------------------------------------------------------------
T = "structure_definitions.csv"
lines = load(T)
FRAME = [f"# boot_can_transmit_frame_t - one frame of boot_can_transmit_ring: the 12 bytes mpc555_canTransmitQueuePush "
         f"builds and either queues or hands to cm848_writeBootKernelCanTxMailbox ({R})",
         "boot_can_transmit_frame_t,,toucan_identifier,dword,4,The TouCAN ID_HIGH / ID_LOW image: identifier bits 28-18 "
         "shifted to 31-21 / SRR and IDE (0x180000) / bits 17-0 shifted to 18-1,,verified",
         "boot_can_transmit_frame_t,,data,byte,8,The payload - 0xff past its length,,verified"]
if FRAME[1] not in lines:
    i = [n for n, l in enumerate(lines) if l.startswith("# CAN transmit/receive ring buffer pointers @ 0x3024c6")]
    assert len(i) == 1
    lines[i[0] - 1:i[0] - 1] = FRAME  # before the ====== line that opens the ring state block
    save(T, lines)
lines = load(T)
for field, typ in (("transmit_write_pointer", "boot_can_transmit_frame_t*"),
                   ("transmit_read_pointer", "boot_can_transmit_frame_t*"),
                   ("receive_write_pointer", "j1939_rx_msg_t*"),
                   ("receive_read_pointer", "j1939_rx_msg_t*")):
    i = [n for n, l in enumerate(lines) if l.startswith(f"can_ring_state_t,0x003024c6,{field},")]
    assert len(i) == 1, field
    parts = lines[i[0]].split(",", 4)
    if parts[3] != typ:
        assert parts[3] == "dword", (field, parts[3])
        parts[3] = typ
        lines[i[0]] = ",".join(parts)
for old, new in (("# j1939_tx: J1939 message queue ring buffer (12-byte records, base 0x3022e6)",
                  "# boot_can_transmit_ring: 40 boot_can_transmit_frame_t at 0x3022e6 (round 70)"),
                 ("# can_rx: CAN receive record ring buffer (18-byte records, base 0x302016)",
                  "# boot_can_receive_ring: 40 j1939_rx_msg_t at 0x302016 (round 70)")):
    if new not in lines:
        lines[lines.index(old)] = new
save(T, lines)

# ---- function_renames.csv: plates --------------------------------------------------------------------------------------
F = "function_renames.csv"
lines = load(F)
PLATES = {
    "0x00002b7c,cm848_clearRamRegions": "Boot kernel: clears the SRAM from calibration_ram_start (0x3f9800) up to "
        "0x3fffd0 - that bound renders as wastegate_duty_floor_x_axis + 0x12 because an application table time-shares "
        f"it - and the whole 6 KB dual-port TPU RAM (dual_port_tpu_ram_start to dual_port_tpu_ram_end) ({R})",
    "0x00055c1c,mpc555_initTpuConfiguration": "Unless TPU B's TPUMCR has bit 0x400 set: copies "
        "dual_port_tpu_ram_load_table's records into the dual-port TPU RAM (0x302000-0x302fff) / then sets both TPU "
        f"module configuration registers (0x4430 B / 0x4460 A) and their interrupt registers ({R})",
}
for key, plate in PLATES.items():
    i = [n for n, l in enumerate(lines) if l == key or l.startswith(key + ",")]
    assert len(i) == 1, key
    if lines[i[0]] == key:
        lines[i[0]] = f"{key},{plate}"
save(F, lines)

with open(map_path, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n"
             "0x00302000,dual_port_tpu_ram_start,TPU3_TPUMCR,global,1\n"
             "0x00302016,boot_can_receive_ring,TPU3_HSQR1,global,1\n"
             "0x00302006,ecu_power_state_flags.state,keyon_state_machine_phase,global,1\n"
             "0x0030200a,ecu_power_state_flags.transfer_crc,qadc_a_portqa,global,1\n"
             "0x00302012,ecu_power_state_flags.runtime_counter,ecm_runtime_accumulator,global,1\n")
print("round 70 stage A applied")
