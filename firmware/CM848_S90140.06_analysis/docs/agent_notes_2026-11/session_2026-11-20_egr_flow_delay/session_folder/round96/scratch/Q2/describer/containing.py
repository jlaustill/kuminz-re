import sys, bisect

FIRMWARE_ROWS = {
    'cm550': '/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/cm550/function_renames.csv',
    'cm848': '/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/cm848/function_renames.csv',
}

firmware = 'cm550'
arguments = sys.argv[1:]
if arguments and arguments[0] in FIRMWARE_ROWS:
    firmware = arguments[0]
    arguments = arguments[1:]

rows = []
with open(FIRMWARE_ROWS[firmware]) as handle:
    for line in handle:
        if line.startswith('#') or not line.strip():
            continue
        parts = line.rstrip('\n').split(',', 2)
        try:
            address = int(parts[0], 16)
        except ValueError:
            continue
        rows.append((address, parts[1]))
rows.sort()
addresses = [row[0] for row in rows]
for text in arguments:
    value = int(text, 16)
    index = bisect.bisect_right(addresses, value) - 1
    following = rows[index + 1] if index + 1 < len(rows) else (0, '-')
    print(f"{text}: in {rows[index][1]} @ {rows[index][0]:#x} (next {following[1]} @ {following[0]:#x})")
