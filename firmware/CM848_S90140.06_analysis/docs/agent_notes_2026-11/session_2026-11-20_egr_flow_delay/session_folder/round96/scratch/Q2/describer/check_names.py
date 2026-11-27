import sys

FILES = {
    'cm550 functions': '/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/cm550/function_renames.csv',
    'cm848 functions': '/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/cm848/function_renames.csv',
    'cm550 globals': '/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/cm550/global_variables.csv',
    'cm848 globals': '/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/cm848/global_variables.csv',
    'cm550 structs': '/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/cm550/structure_definitions.csv',
    'cm848 structs': '/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/cm848/structure_definitions.csv',
}

names = {}
for label, path in FILES.items():
    with open(path, errors='replace') as handle:
        for line in handle:
            if line.startswith('#') or not line.strip():
                continue
            parts = line.rstrip('\n').split(',')
            if label.endswith('structs'):
                key = parts[0]
            else:
                key = parts[1] if len(parts) > 1 else ''
            names.setdefault(key, []).append(f"{label}: {parts[0]}")

for candidate in sys.argv[1:]:
    hits = names.get(candidate, [])
    status = 'FREE' if not hits else 'TAKEN ' + '; '.join(hits)
    print(f"{candidate}: {status}")
