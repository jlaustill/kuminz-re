"""Round 21 stage D: ApplyStructures.java learns the signed-word names the other CSVs use (i16 in global_variables.csv,
sword in function_definitions.csv), and says so in the build log when a field type is unknown: getDataType fell back
to byte silently, so a 2-byte i16 field became byte[2] (round 21 stage A). usage: patch_apply_structures.py <java>"""
import sys

p = sys.argv[1]
t = open(p).read()
PAIRS = [
    ('        TYPE_MAP.put("short", "short");\n',
     '        TYPE_MAP.put("short", "short");\n'
     '        // The signed word as global_variables.csv (i16) and function_definitions.csv (sword) write it; before\n'
     '        // these aliases a struct field typed i16 fell back to byte and became byte[2] (PR #53 round 21).\n'
     '        TYPE_MAP.put("i16", "short");\n'
     '        TYPE_MAP.put("sword", "short");\n'),
    ('                    dt = findEnum(typeName);\n'
     '                    if (dt == null) {\n'
     '                        dt = ByteDataType.dataType;\n'
     '                    }\n',
     '                    dt = findEnum(typeName);\n'
     '                    if (dt == null) {\n'
     '                        // Say so: an unknown name used to become byte (an array of them) without a word.\n'
     '                        println("  WARN: unknown field type \'" + typeName + "\' - using byte");\n'
     '                        dt = ByteDataType.dataType;\n'
     '                    }\n'),
]
for old, new in PAIRS:
    assert t.count(old) == 1, old[:60]
    t = t.replace(old, new)
open(p, "w").write(t)
print("ApplyStructures.java: i16 / sword aliases, unknown-type WARN")
