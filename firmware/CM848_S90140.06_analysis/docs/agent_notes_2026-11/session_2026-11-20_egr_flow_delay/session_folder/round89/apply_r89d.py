"""Round 89 stage D (CM550 docs): the README and package.json still described the pre-2026 partial pipeline
(npm run ghidra:full / init / analyze / memmap / ramvars / bootstrap / import / export, ghidra/scripts/*.java), whose
analyze.sh subcommands were removed for the one deterministic build (scripts/common.sh rejects them with "Unknown
command"). Rewrites those sections to the build / verify model of the firmware's own CLAUDE.md, recounts the analysis
state from the CSVs, keeps only the npm scripts that still work (+ build / verify), and points the README and
memory_map.md at docs/analog_sensor_channels.md. Idempotent; keeps CRLF. usage: apply_r89d.py <repo>"""
import csv
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
D = os.path.join(repo, "firmware/CM550_J90350.00_analysis")
O = os.path.join(D, "output")


def read(p):
    return open(p, newline="").read()


def write(p, t):
    open(p, "w", newline="").write(t)


def rows(name):
    return [r for r in csv.reader(open(os.path.join(O, name), newline="")) if r and r[0].startswith("0x")]


functions = len(rows("function_renames.csv"))
globals_ = rows("global_variables.csv")
ram = sum(1 for r in globals_ if 0x800000 <= int(r[0], 16) <= 0x80FFFF)
struct_rows = [r for r in csv.reader(open(os.path.join(O, "structure_definitions.csv"), newline=""))
               if len(r) > 3 and not r[0].startswith("#") and r[0] != "struct_name"]
struct_types = len({r[0] for r in struct_rows})
struct_fields = sum(1 for r in struct_rows if r[2])
cpp_mb = os.path.getsize(os.path.join(O, "J90350.00.ghidra.cpp")) / 1e6

R = os.path.join(D, "README.md")
t = read(R)
E = "\r\n" if "\r\n" in t else "\n"


def section(title, body):
    """Replace the section that starts at `title` (a heading line) up to the next heading of the same or a higher
    level. Lines inside ``` fences are not headings (a bash block's "# By address")."""
    global t
    level = len(title) - len(title.lstrip("#"))
    lines = t.split(E)
    start = lines.index(title)
    end, fence = len(lines), False
    for i in range(start + 1, len(lines)):
        if lines[i].startswith("```"):
            fence = not fence
            continue
        heading = re.match(r"^(#+) ", lines[i])
        if not fence and heading and len(heading.group(1)) <= level:
            end = i
            break
    new = [title, ""] + body.strip("\n").split("\n") + [""]
    t = E.join(lines[:start] + new + lines[end:])


section("## Current Analysis State", f"""
Counted from the CSVs for PR #53 round 89 (2026-11-24):

| Metric | Count |
|--------|-------|
| Named functions | {functions:,} |
| Global variable rows | {len(globals_):,} ({ram:,} in RAM and extended RAM) |
| Structure types | {struct_types} ({struct_fields} fields) |
| Decompiled C code | {cpp_mb:.1f} MB |
| Memory regions | 4 (ROM + RAM + EXT_RAM + EEPROM) |
""")
section("### Analysis Output", """
The CSVs in `output/` are the only source of truth; the build reads them and writes only the decompilation.

| File | Description |
|------|-------------|
| `output/function_renames.csv` | Function names and plate comments |
| `output/global_variables.csv` | Named and typed globals |
| `output/structure_definitions.csv` | Structure types and their instances |
| `output/function_definitions.csv` / `output/local_variables.csv` | Prototypes and local variable names |
| `output/enums.csv` / `labels.csv` / `constants.csv` / `arrays.csv` / `deleted_functions.csv` | The other CSV inputs (see `CLAUDE.md`) |
| `output/relocation_map.csv` | Historical function mapping (J90280.05 removed) |
| `output/J90350.00.ghidra.cpp` | Full decompilation, the build's only output |
| `output/firmware_types.hpp` / `firmware_globals.hpp` / `firmware_functions.hpp` | Headers generated from the CSVs (`../scripts/generate_headers.py`) |
""")
section("### Ghidra Scripts", """
The build's Ghidra scripts are shared with CM848 in `../scripts/` (see `../CLAUDE.md`). Two stages are CM550's own:
`SetupMemoryMap.java` (the RAM, extended RAM and EEPROM blocks, including the extended RAM dump's 0x80-byte shift) and
`ApplyHardwareRegisters.java` (the MC68336 register names, from the 0xFFxxxx rows of `output/global_variables.csv`).
""")
section("## Quick Start", """
```bash
cd ghidra
./analyze.sh build      # fresh binary -> apply every CSV -> output/J90350.00.ghidra.cpp
./analyze.sh verify     # build twice and check that the output is byte-identical
```

The build needs Ghidra 12.2 PUBLIC (the CPU32 language) and JDK 25; `../CLAUDE.md` gives the paths. `npm install`
is only needed for the TypeScript comparison tools below.
""")
section("### Ghidra Headless Analysis", """
```bash
./ghidra/analyze.sh <command>

Commands:
  build                        Fresh binary -> apply every CSV -> decompilation (the only producer)
  verify                       Build twice and assert byte-identical output
  deletefuncs <addr>...        Record spurious function addresses in output/deleted_functions.csv
  status                       Project status (read-only)
  decompile <addr|name>        Decompile one function from the last build (read-only)
  listfuncs <out>              List every function entry address (read-only)
  classifyfuncs <addrs> <out>  Classify addresses by their incoming references (read-only)
```

The partial commands (`init` / `analyze` / `memmap` / `import` / `export` / ...) were removed: edit the CSVs and run
`build`.
""")
section("### On-Demand Decompilation", """
```bash
# By address
./ghidra/analyze.sh decompile 0x22e5e

# By function name
./ghidra/analyze.sh decompile vp44CanMessageDispatcher
```
""")
section("## Iterative Analysis Workflow", """
1. **Make discoveries** - Identify new functions and variables in the decompiled code
2. **Edit CSVs** - `output/function_renames.csv`, `output/global_variables.csv`, ... (the `editing-firmware-csvs` skill has the rules for each file)
3. **Build** - `./ghidra/analyze.sh build` (or `verify`), then check the new names in `output/J90350.00.ghidra.cpp`
4. **Regenerate the headers** after renames (`../CLAUDE.md`)
""")
pointer = ("The 25 A/D channels' configuration and runtime records, with their Calterm names, are in "
           "[docs/analog_sensor_channels.md](docs/analog_sensor_channels.md).")
if pointer not in t:
    t = t.replace("See [docs/memory_map.md](docs/memory_map.md) for full details including peripheral registers.",
                  "See [docs/memory_map.md](docs/memory_map.md) for full details including peripheral registers. "
                  + pointer, 1)
    assert pointer in t
write(R, t)

M = os.path.join(D, "docs/memory_map.md")
m = read(M)
EM = "\r\n" if "\r\n" in m else "\n"
ADD = [("- QADC result storage", "- A/D channel configuration records: 25 `sensor_config_t` from 0x806ae2 (e2m block 1003; "
        "[analog_sensor_channels.md](analog_sensor_channels.md))"),
       ("- Extended parameter storage", "- A/D channel runtime records: 25 `sensor_state_t` from 0x80a2aa (e2m block 1004; "
        "[analog_sensor_channels.md](analog_sensor_channels.md))")]
for after, line in ADD:
    if line not in m:
        assert m.count(after + EM) == 1, after
        m = m.replace(after + EM, after + EM + line + EM, 1)
write(M, m)

P = os.path.join(D, "package.json")
p = read(P)
EP = "\r\n" if "\r\n" in p else "\n"
block = re.search(r'^    "ghidra:init".*?"ghidra:status": "\./ghidra/analyze\.sh status"', p, re.M | re.S)
if block:
    new = EP.join(['    "ghidra:build": "./ghidra/analyze.sh build",',
                   '    "ghidra:verify": "./ghidra/analyze.sh verify",',
                   '    "ghidra:decompile": "./ghidra/analyze.sh decompile",',
                   '    "ghidra:status": "./ghidra/analyze.sh status"'])
    p = p[:block.start()] + new + p[block.end():]
    write(P, p)
print(f"stage D: {functions} functions, {len(globals_)} globals ({ram} RAM), {struct_types} types / "
      f"{struct_fields} fields, {cpp_mb:.1f} MB")
