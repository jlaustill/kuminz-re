"""Round 77 stage A proof (CM550): apply the round's renders to the old .cpp as exact replacements (the struct pieces
-> the globals they really are, the two function renames, the underscore-prefixed J1708 pointers -> their names), drop
casts, renumber temporaries per line, drop local declarations, and list the remaining changed lines per function.
usage: prove_r77a_cm550.py <old.cpp> <new.cpp>"""
import collections
import difflib
import re
import sys

PAIRS = [
    ("(char)j1708_rx_state_t_0080dcaf.buffer_ptr_3", "j1708_bus_timer_armed_flag"),
    ("j1708_rx_state_t_0080dcaf.buffer_ptr_1._1_1_", "j1708_receive_mode_flag"),
    ("j1708_rx_state_t_0080dcaf.buffer_ptr_1._2_1_", "j1708_transmit_byte_count"),
    ("j1708_rx_state_t_0080dcaf.buffer_ptr_2._0_1_", "j1708_message_checksum"),
    ("j1708_rx_state_t_0080dcaf.buffer_ptr_3._3_1_", "j1708_bus_timer_armed_flag"),
    ("j1708_rx_state_t_0080dcaf._7_4_", "j1708_transmit_state"),
    ("j1708_rx_state_t_0080dcaf.buffer_full_flag", "j1708_pending_abort_count"),
    ("j1708_rx_state_t_0080dcaf.buffer_reserved", "BYTE_0080dcbc"),
    ("mc68k_tpuTimerChannelEnable(channel_mask)", "mc68k_armJ1708BusTimer()"),
    ("mc68k_tpuTimerChannelEnable", "mc68k_armJ1708BusTimer"),
    ("mc68k_tpuChannelStateMachine", "mc68k_j1708BusTimerInterruptHandler"),
    ("_j1708_transmit_buffer_0_2_32", "j1708_transmit_buffer_0_2_32"),
    ("_j1708_transmit_buffer_2_32_dc98", "j1708_transmit_buffer_2_32_dc98"),
    ("_j1708_transmit_buffer_2_32_dc9c", "j1708_transmit_buffer_2_32_dc9c"),
    ("_j1708_receive_buffer_pointer_2_32_dca2", "j1708_receive_buffer_pointer_2_32_dca2"),
    ("_j1708_receive_buffer_pointer_2_32_dca6", "j1708_receive_buffer_pointer_2_32_dca6"),
    ("_j1708_receive_buffer_pointer_2_32_dcaa", "j1708_receive_buffer_pointer_2_32_dcaa"),
]
TEMP = re.compile(r"\b(?:[a-z]Var|p[a-z]?Var|in_|unaff_|extraout_)[A-Za-z0-9_]*\b")
CAST = re.compile(r"\((?:short|ushort|int|uint|word|dword|undefined1|undefined2|undefined4|char|uchar|byte)\s*\**\)")
DECL = re.compile(r"^\s*[A-Za-z_][A-Za-z0-9_ ]*\**\s+\**[A-Za-z_][A-Za-z0-9_]*(?:\s*\[\w+\])?;\s*$")


def bodies(path, rename):
    t = open(path, errors="replace").read()
    parts = re.split(r"^// Function: (\S+) @[^\n]*\n", t, flags=re.M)
    out = {}
    for i in range(1, len(parts), 2):
        b = re.sub(r"/\*.*?\*/", "", parts[i + 1], flags=re.S)
        key = parts[i]
        if rename:
            for old, new in PAIRS:
                b = b.replace(old, new)
            key = dict(PAIRS).get(key, key)
        lines = []
        for line in b.split("\n"):
            if not line.strip() or DECL.match(line):
                continue
            lines.append(re.sub(r"\s+", "", CAST.sub("", TEMP.sub("T", line))).replace("'\\x01'", "1")
                         .replace("'\\0'", "0"))
        out[key] = lines
    return out


old_b, new_b = bodies(sys.argv[1], True), bodies(sys.argv[2], False)
kinds = collections.Counter()
example = {}
changed = []
for f in old_b:
    if old_b[f] != new_b.get(f):
        changed.append(f)
        for line in difflib.unified_diff(old_b[f], new_b.get(f, []), lineterm="", n=0):
            if line.startswith(("---", "+++", "@@")):
                continue
            kinds[line] += 1
            example.setdefault(line, f)
print(f"functions {len(old_b)}; differing after the round's renames: {len(changed)}")
for f in changed:
    print(" ", f)
for line, n in kinds.most_common():
    print(f"{n:4} {line[:130]}   [{example[line]}]")
