"""Round 94 task #41, step 2: the local rows of the six functions, re-targeted at each body's own auto-names (read
from the build without their rows: r94/raw_r94f1_<fw>.cpp). Rows match the decompiler's names before any row
applies, so a row aimed at a name from an older decompilation lands nowhere (the 'Variable X not found' warnings) or
on another variable (CM550 unscrambleSecurityKey's backward_write_ptr row named the mask table pointer and its
bit_position row the bit value written). Names are spelled out (src_ptr -> source_pointer ...). A register that
holds unrelated values in turn gets no row (naming it pins its first value): CM550 unscrambleSecurityKey's cVar3 /
pbVar9 / pbVar10 and both temporaries of CM848 mpc555_keyOnStateMachine. Types follow the old rows where they
applied, except key_matches, which is the decompiler's bool (bool rows apply since round 90).
Appends one block per firmware; idempotent. usage: cleanup_step2_r94.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
R = "PR #53 round 94"
ROWS = {
    "CM550": [
        ("0x0002e9ac", "clearWorkingRam", "psVar2", "working_ram_pointer", "dword*", "The next dword to clear (clr.l (a2)+) from 0x800000 up to 0x80def4"),
        ("0x0002e9ac", "clearWorkingRam", "psVar1", "chunk_end", "dword*", "The end of this pass: 256 bytes on or 0x80def4; the loop runs while working_ram_pointer <= chunk_end - inclusive (the CM848 twin's quirk)"),
        ("0x0002fbd8", "unscrambleSecurityKey", "local_10", "working_buffer", "byte[10]", "The 10-byte work buffer: the key's bits are sorted into it from both ends"),
        ("0x0002fbd8", "unscrambleSecurityKey", "local_6", "input_byte_index", "char", "The input byte being sorted (0-9)"),
        # local_5 (the mask byte) gets no row: named, it stays an unused stack slot while the value moves to a register
        ("0x0002fbd8", "unscrambleSecurityKey", "iVar2", "input_byte_offset", "int32_t", "input_byte_index widened to index input_buffer"),
        ("0x0002fbd8", "unscrambleSecurityKey", "bVar1", "input_bit", "byte", "The input bit at input_bit_position moved to bit 7"),
        ("0x0002fbd8", "unscrambleSecurityKey", "bVar6", "input_bit_position", "byte", "The bit of the input byte being sorted (0-7)"),
        ("0x0002fbd8", "unscrambleSecurityKey", "bVar5", "output_bit", "byte", "The bit written: 1 << (7 - the front bit count) at the front / 1 << backward_bit_count at the back"),
        ("0x0002fbd8", "unscrambleSecurityKey", "bVar7", "backward_bit_count", "byte", "The next bit of the back byte (0-7; the back fills from bit 0)"),
        ("0x0002fbd8", "unscrambleSecurityKey", "cVar8", "forward_byte_index", "char", "The front byte being filled (0 up)"),
        ("0x0002fbd8", "unscrambleSecurityKey", "cVar4", "backward_byte_index", "char", "The back byte being filled (9 down)"),
        ("0x0002fbd8", "unscrambleSecurityKey", "pbVar11", "forward_write_pointer", "byte*", "working_buffer + forward_byte_index"),
    ],
    "CM848": [
        ("0x00000340", "cm848_copyBootKernelToRam", "pdVar1", "source_pointer", "dword*", "The next dword of the boot kernel image in ROM (boot_kernel_rom_start up to boot_kernel_rom_end)"),
        ("0x00000340", "cm848_copyBootKernelToRam", "pdVar2", "destination_pointer", "dword*", "The RAM copy's write pointer (pre-incremented from 0x3f97fc: the first dword goes to 0x3f9800)"),
        ("0x000032dc", "mpc555_generateSerialChallenge", "dVar1", "challenge_value", "dword", "Copy of the challenge (crc16_working_value: 0 while unlocked / else the runtime counter with a zero low word made 1)"),
        ("0x000032dc", "mpc555_generateSerialChallenge", "bVar2", "challenge_high_byte", "byte", "Bits 15-8 of the challenge"),
        ("0x000032dc", "mpc555_generateSerialChallenge", "uVar3", "response_write_position", "uint", "The write position in diag_serial_buffer (mod 256)"),
        ("0x00007370", "cm848_validateBootSecurityKey", "param_1", "scrambled_token", "undefined4", "The 10-byte scrambled key from the tool (passed to cm848_unscrambleBootSecurityKey)"),
        ("0x00007370", "cm848_validateBootSecurityKey", "bVar3", "attempt_count", "byte", "eeprom_block_tracking.failed_write_authorization_count read once (17 = locked out: denied)"),
        ("0x00007370", "cm848_validateBootSecurityKey", "dVar2", "current_runtime", "dword", "Snapshot of ecu_power_state_flags.runtime_counter for the timestamp check"),
        ("0x00007370", "cm848_validateBootSecurityKey", "bVar1", "key_matches", "bool", "Whether all six unscrambled key bytes match eeprom_shadow_header.security_master_password"),
        ("0x00007370", "cm848_validateBootSecurityKey", "cVar8", "compare_index", "char", "Loop index of the six-byte key comparison"),
        ("0x00007370", "cm848_validateBootSecurityKey", "bVar7", "copy_count", "byte", "Loop counter of the three-byte timestamp copy"),
        ("0x00007370", "cm848_validateBootSecurityKey", "uVar6", "result", "undefined4", "Return value: 0 = authorized / 1 = denied"),
        ("0x00007370", "cm848_validateBootSecurityKey", "pbVar4", "timestamp_source_pointer", "byte*", "Source of the timestamp byte copy"),
        ("0x00007370", "cm848_validateBootSecurityKey", "pbVar5", "timestamp_destination_pointer", "byte*", "Destination of the timestamp byte copy"),
    ],
}
DIRS = {"CM550": "firmware/CM550_J90350.00_analysis/output", "CM848": "firmware/CM848_S90140.06_analysis/output"}
HEADER = f"# {R}: rows re-targeted at each body's own auto-names (a build without them showed the names)"
for fw, rows in ROWS.items():
    path = os.path.join(repo, DIRS[fw], "local_variables.csv")
    text = open(path, newline="").read()
    if HEADER in text:
        print(fw, "already added")
        continue
    E = "\r\n" if "\r\n" in text else "\n"
    for r in rows:
        assert "," not in r[5], r
    body = E.join([HEADER] + [",".join(r[:5]) + f",{r[5]} ({R})" for r in rows])
    text = text.rstrip("\r\n") + E + body + E
    open(path, "w", newline="").write(text)
    print(fw, len(rows), "rows added")
