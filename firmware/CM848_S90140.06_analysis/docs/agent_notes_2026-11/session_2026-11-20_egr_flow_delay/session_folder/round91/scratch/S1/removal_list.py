"""Print the 29 rows to remove with their byte offset, record and field inside fault_count_table."""
GLOBALS = ('/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/'
           'CM550_J90350.00_analysis/output/global_variables.csv')
BASE = 0x805a1c
FIELD_AT = {0: 'status_change_time', 4: 'last_countdown_time', 8: 'status', 9: 'occurrence_count'}


def field(offset):
    inside = offset % 10
    start = max(key for key in FIELD_AT if key <= inside)
    name = FIELD_AT[start]
    return name if start == inside else '%s byte %d' % (name, inside - start)


parts_for_comment = []
for line in open(GLOBALS):
    parts = line.rstrip('\n').split(',', 3)
    try:
        address = int(parts[0], 16)
    except ValueError:
        continue
    if not BASE < address < BASE + 1250:
        continue
    offset = address - BASE
    print('0x%08x,%s,+%d = record %d %s' % (address, parts[1], offset, offset // 10, field(offset)))
    parts_for_comment.append('%s at +%d' % (parts[1], offset))
print()
print(' / '.join(parts_for_comment))
