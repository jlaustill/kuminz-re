# Symbol Evidence Reference

Deep detail for the evidence sweep in `SKILL.md`: the disassembly cheatsheet (validated
invocations), the type-shape signal catalog, and the function-target evidence set.

## Assembly width check — binaries, VMAs, invocations

The variable itself lives in RAM (no code there). You disassemble the **referencing code**
(the function that loads/stores it, found via the `// Function: <name> @ 0x<addr>` comment in the
`.cpp`) and read the load/store width for the target address.

**CM848 shortcut — use the helper, don't do this by hand:**
```bash
python3 firmware/scripts/disasm_func.py <func_name|0xADDR> 0x<DATA_ADDR>
```
It auto-resolves the window (next `// Function:` = stop addr), picks Bank1/Bank2 binary + VMA by the
0x500000 split, tracks register contents (lis/addi/ori/li/mr) to catch ALL three addressing forms —
displacement, `lis;addi;0(rN)` exact, and struct/buffer-member `<offset>(base)` — and prints a WIDTH
verdict (byte/word/dword) to paste into the report. Pass a function NAME or any
`0xADDR` inside it (it snaps to the containing function). Omit the data addr to dump the whole
function. The manual `objdump` recipe below is the fallback / for understanding what it does.

### CM848 — PowerPC, BIG-ENDIAN (reliable)

Tool: `powerpc-linux-gnu-objdump` (NOT `llvm-objdump` — it has no `-b binary`). `-EB` is required;
without it the bytes decode little-endian into garbage.

| Region | Address range | Binary | `--adjust-vma` |
|---|---|---|---|
| Bank1 ROM | 0x00000000–0x0006FFFF | `originals/cm848_rom.bin` | `0x0` |
| Bank2 FLASH2 | 0x00500000–0x0053DFFF | `originals/cm848_flash2_live.bin` | `0x00500000` |

```bash
powerpc-linux-gnu-objdump -D -b binary -m powerpc -EB \
  --adjust-vma=<region_base> --start-address=<fn_addr> --stop-address=<fn_end> <binary>
```
Use a window that spans the whole function (accesses can be hundreds of bytes in).

**Mapping a global to its instruction (turnkey anchor).** RAM globals are accessed as a base
register (`lis rN, <hi>`) plus a signed-16 displacement, and **the displacement's raw bytes equal
the address's low 16 bits**. So the easiest reliable find is to grep the disassembly for the
target's bottom 4 hex digits, byte-spaced, among load/store lines:

**Get the window mechanically (don't guess):**
- `fn_addr` = from the `// Function: <name> @ 0x<addr>` comment above the usage.
- `fn_end` = the **next** `// Function:` address after it (use that as `--stop-address`; spanning the
  whole function is essential — accesses are often 1000+ bytes past entry).
- Pick the binary + `--adjust-vma` by `fn_addr`: ≥ `0x00500000` → Bank2 `originals/cm848_flash2_live.bin`
  base `0x00500000`; else Bank1 `originals/cm848_rom.bin` base `0x0`. (`protectionTimeoutControl @
  0x525e54` is **Bank2** — searching `cm848_rom.bin` finds nothing, the common miss.)

```bash
# target 0x00408b78 → low-16 = "8b 78"; fn 0x525e54..0x5263a8 is Bank2
powerpc-linux-gnu-objdump -D -b binary -m powerpc -EB --adjust-vma=0x00500000 \
  --start-address=0x00525e54 --stop-address=0x005263a8 originals/cm848_flash2_live.bin \
  | grep -iE 'l(b|h|w)z|lha|st(b|h|w)' | grep -i '8b 78'
```
If this prints nothing, the access may use the **second addressing form** (below) — or you used the
wrong binary / too-small a window. Fix it before falling back to a context guess.

**Second addressing form — address built in a register.** The compiler sometimes builds the full
address with `lis rN,<hi>; addi rN,rN,<lo>` (or `ori`) and then accesses it via `0(rN)`. Then the
low-16 bytes appear in the **`addi`/`ori`**, not in the load's displacement, so the load/store-filtered
grep above misses it. Drop the filter (`grep -i 'ed 94'` alone), find the `addi rN,rN,<lo>` that
finishes the address, then read the width from the nearby `l{b,h,w}z / st{b,h,w} rX, 0(rN)`.
Validated example — `DAT_003fed94` in `diag_faultRing_writePtr_update @ 0x52d524`:
```
52d5f8:	3c a0 00 40 	lis   r5,64        ; 0x400000
52d5fc:	38 a5 ed 94 	addi  r5,r5,-4716  ; r5 = 0x3FED94  (the "ed 94" is here, not in a load)
52d634:	81 85 00 00 	lwz   r12,0(r5)    ; → lwz = dword
```
Validated example — `protectionTimeoutControl @ 0x525e54` (Bank2):
```
526278:	a1 8c 8b 78 	lhz   r12,-29832(r12)   # base lis r12,65 (0x410000); 0x410000-0x7488 = 0x408b78
```
`lhz` ⇒ **word**. (Displacement `-29832` = `0x8b78` as signed-16; note the bytes `8b 78` = the
address low half.) Use a `--stop-address` that spans the whole function — accesses can be hundreds
of bytes past the entry.

**Third addressing form — buffer/struct member off a base pointer.** For a symbol that is one
member of a buffer/struct, the compiler loads the **base** address once (`lis`+`addi`) and accesses
each member by a small displacement: `stb rX, <member_offset>(rBase)`. The target address never
appears whole — only the **base** does (in the `addi`). So: grep for the *base* low-16 (= the
member's address minus its offset), find `addi rBase,rBase,<lo>`, then read width from the
`l{b,h,w}z / st{b,h,w} rX, <member_offset>(rBase)`. This is the strongest **array/struct-member**
type-shape signal — if you see it, the symbol routes to `arrays.csv` / `structure_definitions.csv`,
not `global_variables.csv`. Validated example — `DAT_003fab0e` (byte 4 of an 8-byte J1939 TX
buffer) in `initPgn65261CruiseControlSetupStruct @ 0x24800`:
```
24830:	3c 60 00 40 	lis   r3,64        ; 0x400000
24834:	38 63 ab 0a 	addi  r3,r3,-21750 ; r3 = 0x3FAB0A  (buffer base; the member's addr never appears whole)
2485c:	98 83 00 04 	stb   r4,4(r3)     ; 0x3FAB0A+4 = 0x3FAB0E := 0xff → stb = byte
```

Width: `lbz/stb` = 1B **byte** · `lhz/lha/sth` = 2B **word** · `lwz/stw` = 4B **dword**.

**Interpreting a leading `_` on the symbol.** A `_`-prefixed global has THREE possible causes — the asm
width check distinguishes them, so don't assume "too narrow":
1. **Type too narrow** — the load is wider than the declared type (e.g. `lwz` on a `word`). Recommend widening.
2. **PowerPC pair-clear** — one `sth`/`stw` writes this var AND its neighbor. Recommend a single wider var/struct.
3. **ROM-to-RAM aliasing** (addr in 0x3F9800–0x3FDB30) — the data global overlaps the RAM image of a ROM
   function (`RAM = 0x3F9800 + (ROM − 0x3C30)`; grep `function_renames.csv` for a function mapping here).
   The `_` is **unavoidable** — report it as aliasing, NOT a width/type defect, and recommend keeping the
   loose global name (widening or struct-typing can't fix it). Validated: `_j1939_pgn65261_tx_header`
   @ 0x3faafc aliases `cm848_writeCan2ControllerTxMailbox` @ ROM 0x4f2c.

### CM550 — m68k, BIG-ENDIAN (best-effort, experimental backend)

GNU objdump has no m68k target; `llvm-objdump` has no `-b binary`. Use `llvm-mc-18` disassembling
extracted hex. The m68k backend decodes prologues and common ops but errors on some 68020
instructions — when the specific access won't decode, fall back to the `.cpp` width signal and SAY SO.

| Region | Base | Binary |
|---|---|---|
| ROM | 0x00000000 | `firmware/J90350.00.rom.bin` |
| RAM | 0x00800000 | `firmware/J90350.00.ram.bin` |
| Extended RAM | 0x008091C2 | `firmware/J90350.00.extended_ram.bin` |
| EEPROM | 0x01000000 | `firmware/J90350.00.eeprom.bin` |

```bash
# off = fn_addr - region_base (decimal); len ~ function size in bytes
xxd -p -s <off> -l <len> <binary> | tr -d '\n' | sed 's/../0x& /g' \
  | llvm-mc-18 --disassemble --triple=m68k
```
Width suffixes: `.b` = 1B **byte** · `.w` = 2B **word** · `.l` = 4B **dword** (e.g. `move.w`, `move.l`).

## Type-shape signal catalog (step 8)

| Shape | Signal in the `.cpp` | Target CSV | Caveat |
|---|---|---|---|
| **flat global** | plain scalar read/write, no pattern below | `global_variables.csv` | width must match the asm load |
| **enum** | compared `== / !=` against a small set of integer constants (whole value) | `enums.csv` | renders only for whole-value compares AND matching width — never for `& MASK` or byte-width vars |
| **bitfield** | tested/set via `& 0xNN` / `\| 0xNN` on specific bits | `structure_definitions.csv` (`bitfield:<sz>@<off>`) | needs Ghidra ≥ 12.1 to render on PPC |
| **struct field** | clustered accesses at a common base + small offsets; base passed as a pointer to the same fn(s) | `structure_definitions.csv` | multi-instance = marker rows |
| **array** | indexed `base[i]` / `*(base + i*stride)` | `arrays.csv` | — |
| **function family** | address sits in a dispatch table, or has siblings with the same prototype/role | `function_renames.csv` (+ `function_definitions.csv`) | — |

A symbol can show more than one signal — report what you see and let the reviewer judge. When in
doubt between flat-global and a richer shape, name the shape as a *possibility* with its evidence
rather than forcing a call.

## Function targets (when the symbol is a FUN_/function)

Evidence set differs from a variable:
- **Callers** — `grep` the name; who calls it and in what context (cite).
- **Callees** — what it calls; a thin wrapper vs. a real computation vs. a dispatcher.
- **Prototype** — params/return. Watch the **r4-return gotcha** (see [[editing-firmware-csvs]] /
  `csv-type-reference.md`): never recommend a return type for an r4-return helper whose r4 isn't a
  parameter.
- **Dispatch membership** — does its address appear in a command/handler table? That often names it.
- **Behavior** — what does it compute or decide, in one line, cited.

Verdict for a function: `NAMEABLE → name + (optional) prototype note`, or `INSUFFICIENT → what's missing`.
Recommend the name only; the reviewer + [[editing-firmware-csvs]] apply it via `function_renames.csv`
(and `function_definitions.csv` for the prototype).
