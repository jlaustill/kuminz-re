"""Print the +0 record address of each engine protection e2m block (CM550) and its implied channel."""
import subprocess

FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware'
groups = {
    'configuration 0x807032 / 36': (0x807032, 36, ['10B7', '112B', '112C', '112D', '112E', '112F', '1130', '1131', '1132']),
    'state 0x80d0dc / 46': (0x80d0dc, 46, ['10B0', '114F', '1150', '1151', '1152', '1153', '1154', '1155', '1156']),
    'history 0x8057c0 / 30': (0x8057c0, 30, ['10B2', '1140', '1141', '1142', '1143', '1144', '1145', '1146', '1147']),
}
for label, (base, stride, blocks) in groups.items():
    print(label)
    for n, b in enumerate(blocks):
        out = subprocess.run(['python3', 'scripts/e2m_block_addresses.py', '--firmware', 'cm550', b], cwd=FW,
                             capture_output=True, text=True).stdout.splitlines()
        lengths = {}
        lowest = None
        for line in out:
            parts = line.split()
            off = int(parts[1].lstrip('+'), 16)
            addr = int(parts[parts.index('->') + 1], 16)
            if lowest is None or addr - off < lowest:
                lowest = addr - off
            lengths[off] = parts[2]
        ok = 'OK' if lowest == base + stride * n else 'MISMATCH'
        print(f"  {b}: base 0x{lowest:x} expected 0x{base + stride * n:x} {ok}; {len(out)} records; offsets "
              + ' '.join(f"{o:x}" for o in sorted(lengths)))
