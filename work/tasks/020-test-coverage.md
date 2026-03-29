# 020 - Test Coverage Implementation Plan

## Problem Statement

The codebase has zero automated tests across all subprojects. For a reverse engineering project, tests serve a critical role: they **lock in correctness of reverse-engineered knowledge** so that protocol implementations, file format parsers, and algorithm reconstructions don't silently regress.

## Priority Order

Work through these phases iteratively across sessions. Each phase is independent and can be done in any order, but the priority reflects where tests deliver the most value.

---

## Phase 1: clip-core (Catch2) — Highest Priority

The shared CLIP protocol library is the foundation of both kuminz-cli and kuminz-ui. Protocol code is pure logic — highly testable without hardware.

### Setup
- [ ] Add Catch2 (header-only) to clip-core
- [ ] Add `enable_testing()` and test targets to `clip-core/CMakeLists.txt`
- [ ] Create `clip-core/tests/` directory

### Test Cases
- [ ] **CLIPInstructionBuilder** — Packet construction for each service type
  - Service 0x4A (GetDataByAddress) read requests at various sizes
  - Service 0x14 (GetDataByParameterID) command packets
  - Service 0x15 (SetDataByAddress) write packets
  - Verify byte-level correctness of constructed packets
- [ ] **CLIPTransportLayer** — Multi-frame reassembly
  - Single-frame responses (1-2 byte reads)
  - Multi-frame RTS/CTS/DT/EOM sequence reassembly
  - Timeout and error handling for incomplete sequences
  - Out-of-order frame handling
- [ ] **J1939MessageBuilder** — CAN frame formatting
  - PGN encoding correctness (0xEF00 peer-to-peer)
  - Source/destination address fields (0xF9 tool, 0x00 ECU)
  - CAN ID construction (0x18EF00F9, 0x18EFF900)
  - PDU1 vs PDU2 format validation
- [ ] **CLIPSessionManager** — State machine transitions
  - Happy path: disconnect → connect → authenticate → ready
  - Error recovery: timeout during authentication
  - Reconnection after session drop
- [ ] **Mock ICanAdapter** — Create test double for hardware-free testing
  - Record sent frames for assertion
  - Inject scripted response sequences
  - Simulate timeouts and errors

---

## Phase 2: calterm-crc (Catch2) — High Priority

The CRC algorithm was reverse-engineered. Five test files with known-good CRC values already exist in `e2m-analysis/test_files/`. This is the easiest win.

### Setup
- [ ] Add Catch2 to calterm-crc
- [ ] Add test target to Makefile or convert to CMake
- [ ] Create test file(s)

### Test Cases
- [ ] **CRC computation** — Verify computed CRC matches known values for each test e2m file
- [ ] **CRC verification** — `verify` mode correctly accepts valid files, rejects modified files
- [ ] **CRC fix** — `fix` mode produces files that pass verification
- [ ] **Edge cases** — Empty data sections, minimal files, maximum-size records
- [ ] **Regression guard** — Lock in the reverse-engineered algorithm behavior

---

## Phase 3: e2m-analysis (Vitest) — High Priority

The E2M format is 100% decoded. Tests lock in that knowledge permanently.

### Setup
- [ ] Add Vitest as dev dependency
- [ ] Add `test` script to package.json
- [ ] Create `e2m-analysis/tests/` directory or co-locate `*.test.ts` files

### Test Cases
- [ ] **CSV parser** — Header row handling, 16-column records, edge cases
  - Two header rows parsed correctly
  - All 16 columns extracted
  - Handling of missing/empty columns
- [ ] **Address resolution** — `BaseLookup[Column3] + Column4` formula
  - Known parameter → address mappings (use verified data from task 004)
  - All 521 base address lookups
- [ ] **Binary hex dump parser** — `[Data Records]` section
  - Record boundary detection
  - Address extraction from binary records
  - ROM vs FLASH2 vs EEPROM section identification
- [ ] **Firmware address validation** — Known-good address → memory region mappings
  - ROM range: 0x00000000–0x0006FFFF
  - RAM range: 0x00800000 + 37KB
  - Extended RAM: 0x008091C2 + 28KB
  - EEPROM: 0x01000000 + 4KB

---

## Phase 4: Firmware Analysis Tools (Vitest) — Medium Priority

CSV workflow tools that drive Ghidra automation.

### Setup
- [ ] Add Vitest to firmware analysis projects (if not sharing e2m-analysis config)
- [ ] Create test files alongside tools

### Test Cases
- [ ] **CSV format validation** — Catch malformed entries before Ghidra import
  - function_renames.csv: address + name format
  - global_variables.csv: address + type + name format
  - enums.csv: proper enum definition structure
  - Reject duplicate addresses, empty names, invalid hex addresses
- [ ] **Relocation map consistency**
  - All addresses in relocation_map.csv are valid hex
  - Status values are one of: matched, similar, not_found
  - No duplicate source addresses
- [ ] **Cross-firmware comparison** — Feature comparison script correctness
  - Known identical functions produce "matched" status
  - Known different functions produce "similar" status
  - Known absent functions produce "not_found" status

---

## Phase 5: e2m-db (Vitest) — Lower Priority

Database import validation.

### Setup
- [ ] Add Vitest to e2m-db
- [ ] Formalize existing `test-e2m-db.ts` into proper test suite
- [ ] Consider testcontainers for isolated PostgreSQL (optional)

### Test Cases
- [ ] **Import idempotency** — Running import twice doesn't duplicate data
- [ ] **Schema validation** — All expected tables and columns exist after migration
- [ ] **Parameter name extraction** — Known parameters resolve to correct names
- [ ] **Data integrity** — Row counts match expected values from source CSV

---

## Phase 6: kuminz-cli / kuminz-ui — Lower Priority

Thin wrappers over clip-core. Once clip-core is well-tested, these need minimal testing.

### kuminz-cli
- [ ] **Argument parsing** — All `--dump-*` and `--read-addr` flags parsed correctly
- [ ] **Output formatting** — Address/value display format correctness
- [ ] **Error messages** — Missing interface, invalid address, etc.

### kuminz-ui
- [ ] **Widget state management** — EAdapterState and EConnectionState transitions
- [ ] **Device detection** — Mock `/sys/class/net/` and `/dev/serial/by-id/` for CanDeviceManager tests
- [ ] Consider Qt Test framework if Qt-specific behavior needs testing

---

## Notes

- **No CI/CD exists yet.** Once any test phase is complete, adding a GitHub Actions workflow to run tests on push would be a natural follow-up.
- **Catch2 v3** is recommended for C++ (header-only, modern CMake integration, single `#include`).
- **Vitest** is recommended for TypeScript (fast, modern, compatible with existing tsx/ESLint setup).
- **Hardware-free testing** is essential — all protocol tests must use mock CAN adapters, never require a live ECU.
