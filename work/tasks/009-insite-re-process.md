# 009: Insite Reverse Engineering Process

**Status:** In Progress (Phase 4 Complete - Calibration Handling)
**Subproject:** insite9
**Created:** 2024-12-13
**Updated:** 2024-12-13

## Progress Log

### 2024-12-13: Calibration Handling Analysis Complete
- Analyzed security model: SecurityLevel enum (9 levels) and password types (5 types)
- Documented ECU password operations: GetPasswordState, ValidatePassword, SetPassword, etc.
- Mapped calibration file read/write paths via ImageServices and DownloadLibrary
- Reverse engineered flash update process: DownloadLibrary, DownloadAlgorithm, ReflashStatus
- Created comprehensive documentation: `work/docs/calibration-handling.md`

**Key Calibration Findings:**
| Component | Source File | Key Discovery |
|-----------|-------------|---------------|
| Security Levels | FeaturesAndParameters.cs:651 | Basic→ProPlus (9 levels) |
| Password Types | CONMANAPILib.cs:23 | Master, OEM, Adjustable, Reset, OEM2 |
| Access Levels | SymbolicTreeObj.cs:733 | ReadOnly→FullAccess (7 levels) |
| Download Library | CureCore.cs:6432 | Bosch_DCU and GTIS4_ECU algorithms |
| Reflash Status | ReflashControl.cs:300 | 10 status states for flash process |

**Password Type Enum:**
- `PTE_MASTER_PASSWORD` (1), `PTE_OEM_PASSWORD` (2), `PTE_ADJUSTABLE_PASSWORD` (3)
- `PTE_RESET_PASSWORD` (4), `PTE_OEM_PASSWORD2` (6)

**Documentation Created:** `work/docs/calibration-handling.md`

### 2024-12-13: Diagnostic Functions Analysis Complete
- Analyzed fault code (DTC) handling via IFaultInformation interface
- Documented J1939 SPN+FMI diagnostic message format
- Mapped freeze frame data via CFaultSnapshot class in FaultsDataOM
- Reverse engineered parameter monitoring system (MonitorServices)
- Documented data logging system (DataMonitorLogger API)
- Created comprehensive documentation: `work/docs/diagnostic-functions.md`

**Key Diagnostic Findings:**
| Component | Source File | Key Discovery |
|-----------|-------------|---------------|
| Fault Info | ECMServicesAPI.cs:533 | IFaultInformation with SPN/FMI fields |
| Freeze Frames | FaultsDataOM_ghidra.c | CFaultSnapshot class |
| Monitoring | MonitorServices.cs:203 | Async polling via GetParameterValueAsync |
| Logging | DataMonitorLoggerAPILib | XML log format with IDMLParameter groups |

**TriggerType Enum:**
- `None` (0), `ValueChanged` (1), `Periodic` (2), `Custom` (4), `All` (7)

**CustomTriggerOperator Enum:**
- Equal, LessThan, LessThanOrEqual, GreaterThan, GreaterThanOrEqual, NotEqual

**Documentation Created:** `work/docs/diagnostic-functions.md`

### 2024-12-13: Communication Protocol Analysis Complete
- Analyzed CLIP and J1939 protocol implementations from PCLSystem_ghidra.c
- Documented DPA (Device Protocol Adapter) layer from datalink_ghidra.c
- Created comprehensive protocol specification: `work/docs/clip-protocol-spec.md`

**Key Protocol Findings:**
| Protocol | Default Timeout | Max Write Batch | Auth Method |
|----------|-----------------|-----------------|-------------|
| CLIP (PCL) | 60,000 ms | 256 params | Session-based |
| J1939 (PJ1939) | 60,000 ms | Variable | 6-byte password |

**Protocol Enum (from ECMServicesCommonTypes):**
- `Image` (0) - Calibration file protocol
- `ICL` (1) - Insite Communications Library
- `CC` (2) - Cummins Communications (legacy)
- `PJ1939` (3) - J1939 CAN protocol
- `UDS` (4) - Unified Diagnostic Services
- `PCL` (5) - Protocol Communications Library (CLIP)

**DPA Device Types:**
- 0x0000 = CommLink (Serial) via DPAS32.DLL
- 0x8000 = PCCard via DPAI32.DLL

**Documentation Created:** `work/docs/clip-protocol-spec.md`

### 2024-12-13: Decompilation 100% Complete
- Created `insite9/scripts/` with batch decompilation tools
- Installed mdbtools for Access database extraction
- **Databases extracted:** 362 tables (358 from FnPDatabase, 4 from INSITEHelp)
- **.NET DLLs decompiled:** 105/105 (16MB readable C# source)
- **Native DLLs decompiled:** 253/253 (269MB C pseudocode) - 0 failures

**Decompilation Summary:**
| Category | Count | Size | Status |
|----------|-------|------|--------|
| .NET DLLs | 105 | 16 MB | Complete |
| Native DLLs | 253 | 269 MB | Complete |
| Database tables | 362 | 8.5 MB | Complete |
| **Total** | **358 DLLs** | **~294 MB** | **100%** |

**Key database findings:**
- FnPDatabase contains FEATURE_*, PARAMETER_*, SUBFEATURE_* tables
- Each feature ID has corresponding parameter and subfeature tables
- INSITEHelp has 56,834 help topics mapped to fault codes

**Notable DLLs:**
- `ToolSecurity_ghidra.c` - 3.2MB (took ~1 hour to decompile due to complexity)
- `WorkOrders_ghidra.c` - 9.0MB (largest output file)
- `CureCore_ghidra.c` - Core diagnostic engine

## Goal

Establish a systematic reverse engineering process for Insite diagnostic software to understand ECU communication protocols, diagnostic workflows, and calibration file handling.

## Background

Insite is Cummins' official diagnostic and calibration software. Understanding how Insite works provides insight into:
- ECU communication protocols (beyond CLIP)
- Diagnostic trouble code handling
- Parameter monitoring and data logging
- Calibration file management
- ECU firmware update processes

## Current Assets

### Binary Archive (344MB in `/insite9/`)
- `Insite.exe` - Main application
- 200+ DLLs (87 .NET, 22+ native)
- `CaltermApplication.dll` - Calterm UI wrapper
- `CureCore.dll` - Core engine (5MB)
- `Metadata.accdb` - Parameter definitions (5.7MB)
- `FnPDatabase.mdb` - Function database (13MB)

### Already Decompiled (from calterm-crc work)
- 83 .NET DLLs → 25MB C# source (readable)
- 22 native DLLs → 56MB C pseudocode (annotated)
- 1,496 functions renamed across native DLLs

## Proposed RE Process

### Phase 1: Inventory & Triage
- [ ] Catalog all DLLs by function area (communication, UI, data, etc.)
- [ ] Identify which DLLs are shared with Calterm III
- [ ] Map dependencies between DLLs
- [ ] Prioritize DLLs by relevance to ECU communication

### Phase 2: Communication Protocol Analysis
- [X] Identify all ECU communication DLLs (PCLSystem.dll, datalink.dll)
- [X] Trace message flow from UI to CAN bus (documented in clip-protocol-spec.md)
- [X] Document protocol layers (application, transport, network)
- [X] Compare with CLIP protocol from kuminz-ui work

### Phase 3: Diagnostic Functions
- [X] Analyze fault code retrieval and display (IFaultInformation, J1939 SPN+FMI)
- [X] Understand snapshot/freeze frame data handling (CFaultSnapshot)
- [X] Document parameter monitoring implementation (MonitorServices, ParameterPoller)
- [X] Trace data logging workflow (DataMonitorLogger, XmlLogfile)

### Phase 4: Calibration Handling
- [X] Map calibration file read/write paths (ImageServices, DownloadLibrary)
- [X] Understand ECU flash update process (DownloadAlgorithm, ReflashStatus)
- [X] Document security/authentication mechanisms (9 SecurityLevels, 5 PasswordTypes)
- [X] Cross-reference with e2m-analysis findings (parameter addressing)

### Phase 5: Database Analysis
- [ ] Analyze Metadata.accdb schema
- [ ] Extract parameter definitions
- [ ] Map FnPDatabase.mdb structure
- [ ] Correlate with e2m parameter mappings

## Key Questions to Answer

1. **Protocol differences:** How does Insite communication differ from Calterm/CLIP?
2. **Security:** What authentication is used for ECU write operations?
3. **Parameter coverage:** Does Insite access more parameters than Calterm?
4. **Firmware updates:** How are ECU firmware updates handled?
5. **Multi-ECU:** How does Insite handle vehicles with multiple ECUs?

## Tools & Approach

### Decompilation Scripts (in `insite9/scripts/`)
```bash
cd insite9

# .NET DLLs - fast (~10 min) - DONE
./scripts/insite-dotnet-batch.sh

# Database extraction - fast (~2 min) - DONE
./scripts/extract-databases.sh

# Native DLLs - slow (~2-4 hours) - run overnight
nohup ./scripts/insite-native-batch.sh > native-decompile.log 2>&1 &
```

### Analysis Commands
```bash
# Search decompiled code
grep -r "J1939" insite9/decompiled/dotnet/
grep -r "CLIP" insite9/decompiled/dotnet/
grep -r "CAN" insite9/decompiled/native/

# View database schema
cat insite9/decompiled/databases/FnPDatabase/schema.sql
```

### Tools Used
- **ILSpy CLI** (`~/.dotnet/tools/ilspycmd`) - .NET → C# source
- **Ghidra Headless** (`/opt/ghidra/support/analyzeHeadless`) - Native → C pseudocode
- **mdbtools** (`mdb-export`, `mdb-schema`) - Access databases → CSV

### Documentation
- Add findings to this task file
- Create separate docs for major subsystems
- Update CLAUDE.md with Insite-specific guidance

## Key DLLs to Investigate

| DLL | Type | Priority | Purpose |
|-----|------|----------|---------|
| CureCore.dll | Native | HIGH | Core diagnostic engine |
| DeviceControl.dll | Native | HIGH | ECU communication |
| DataMonitoring.dll | Native | HIGH | Parameter monitoring |
| CalDataServer.dll | Native | MEDIUM | Calibration data handling |
| ModuleDetection.dll | Native | MEDIUM | ECU discovery |
| MsgHandling.dll | Native | MEDIUM | Message processing |
| Services.dll | .NET | LOW | Heavily obfuscated |

## Key Files

**Binary Archive:**
- `insite9/` - Complete Insite installation (344MB)

**Decompiled Output:**
- `insite9/decompiled/dotnet/` - 105 .NET DLLs as C# (16MB)
- `insite9/decompiled/native/` - 253 Native DLLs as C pseudocode (269MB)
- `insite9/decompiled/databases/` - Extracted CSV + schema (8.5MB)

**Scripts:**
- `insite9/scripts/insite-dotnet-batch.sh` - .NET batch decompiler
- `insite9/scripts/insite-native-batch.sh` - Native batch decompiler
- `insite9/scripts/extract-databases.sh` - Database extractor

**Key Databases (extracted):**
- `insite9/decompiled/databases/FnPDatabase/` - 358 tables (FEATURE_*, PARAMETER_*, etc.)
- `insite9/decompiled/databases/INSITEHelp/` - 4 tables (fault codes, help topics)

**Documentation:**
- `work/docs/clip-protocol-spec.md` - CLIP/J1939 protocol specification
- `work/docs/diagnostic-functions.md` - Fault codes, monitoring, logging
- `work/docs/calibration-handling.md` - Security model, calibration, flash process

## Related Tasks

- 001 (CRC Paradox) - CRC algorithm shared between Calterm/Insite
- 003 (CLIP Protocol) - ECU communication protocol
- 010 (ECU Versions) - ECU compatibility information
