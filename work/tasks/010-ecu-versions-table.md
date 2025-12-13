# 010: ECU Versions Documentation

**Status:** Todo
**Subproject:** firmware
**Created:** 2024-12-13
**Updated:** 2024-12-13

## Goal

Create a comprehensive reference table documenting Cummins ECU versions, their characteristics, compatibility, and reverse engineering status. This provides context for cross-ECU analysis and helps identify shared code patterns.

## Background

Cummins has produced multiple ECU generations across different engine families. Understanding the relationships between ECU versions helps:
- Identify which discoveries apply across versions
- Plan reverse engineering priorities
- Understand firmware evolution
- Map parameter compatibility

## Deliverables

### 1. ECU Hardware Reference Table
| ECU Model | MCU | Flash | RAM | Years | Engine Family | Status |
|-----------|-----|-------|-----|-------|---------------|--------|
| CM550 | MC68336 | 256KB | 1MB ext | 1998-2004 | ISB/ISC | RE Complete |
| CM570 | ? | ? | ? | ? | ? | Not started |
| CM871 | ? | ? | ? | ? | ISX | Not started |
| CM2350 | ? | ? | ? | ? | ISX15 | Not started |
| ... | | | | | | |

### 2. Firmware Versions Table
| Part Number | ECU | Engine | Version | Calibration | RE Status |
|-------------|-----|--------|---------|-------------|-----------|
| J90280.05 | CM550 | ISB 5.9 | ? | ? | 100% named |
| ... | | | | | |

### 3. Protocol Compatibility Matrix
| ECU | J1939 | CLIP | Insite | Calterm | CAN Speed |
|-----|-------|------|--------|---------|-----------|
| CM550 | Yes | Yes | v3? | III | 250kbps |
| ... | | | | | |

### 4. Parameter Compatibility
Which parameters exist across ECU versions? Track coverage.

## Research Tasks

### Phase 1: Gather Existing Knowledge
- [ ] Extract ECU info from e2m files (metadata headers)
- [ ] Parse Insite Metadata.accdb for ECU definitions
- [ ] Review Calterm configuration files
- [ ] Search firmware for version strings

### Phase 2: Hardware Research
- [ ] Document CM550 hardware (current target)
- [ ] Research CM570/CM871/CM2350 specifications
- [ ] Identify MCU families used across generations
- [ ] Map memory architectures

### Phase 3: Software Research
- [ ] Identify firmware part number patterns
- [ ] Map calibration file compatibility
- [ ] Document protocol version differences
- [ ] Track tooling compatibility (Calterm/Insite versions)

### Phase 4: Cross-Reference
- [ ] Correlate e2m parameters across ECU versions
- [ ] Identify shared code patterns in firmware
- [ ] Map memory address similarities
- [ ] Document evolution of state machines

## Known Information

### CM550 (Current Target)
- **MCU:** Motorola MC68336 (68020 core)
- **Flash:** 256KB internal
- **RAM:** 1MB external
- **CAN:** 250kbps J1939
- **Protocol:** CLIP
- **Firmware:** J90280.05 (fully named)
- **Status:** 793 functions, 6,087 globals named

### Planned Additions
- Dodge 2002/2004 truck ECU firmware (from CLAUDE.md)
- Additional Calterm/Insite versions

## Data Sources

### E2M Files
- Column 15 contains version/build metadata (30 unique values)
- Headers may contain ECU compatibility info

### Insite Databases
- `Metadata.accdb` - ECU definitions
- `FnPDatabase.mdb` - Part number mappings

### Firmware
- Version strings in binary
- Build dates
- Calibration identifiers

## Output Location

Create: `docs/ecu-versions.md` (or similar) at repo root with:
- Hardware reference table
- Firmware version table
- Protocol compatibility matrix
- Links to relevant analysis files

## Key Files

**Current Firmware:**
- `firmware/J90280.05_analysis/` - CM550 firmware analysis

**Data Sources:**
- `e2m-analysis/` - Parameter files with version metadata
- `insite9/Metadata.accdb` - ECU definitions
- `insite9/FnPDatabase.mdb` - Part number database

## Related Tasks

- 002 (E2M Format) - Parameter version metadata in Column 15
- 003 (CLIP Protocol) - Protocol compatibility
- 009 (Insite RE) - ECU detection and compatibility handling
