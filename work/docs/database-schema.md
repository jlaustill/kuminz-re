# Insite Database Schema Specification

This document describes the database schemas used by Insite for ECU metadata, parameter definitions, and help content, reverse engineered from the Insite 9 decompilation.

## Database Overview

```
+--------------------------------------------------+
|           Insite Database Layer                  |
+--------------------------------------------------+
         |                    |                    |
+----------------+  +-------------------+  +----------------+
| FnPDatabase    |  | Metadata.accdb    |  | INSITEHelp     |
| (.mdb 13MB)    |  | (.accdb 5.7MB)    |  | (.mdb)         |
+----------------+  +-------------------+  +----------------+
| Features &     |  | Parameter         |  | Fault Help     |
| Parameters by  |  | Definitions       |  | File Mapping   |
| ECU Type       |  | (Access 2007+)    |  | Help Topics    |
+----------------+  +-------------------+  +----------------+
```

## 1. FnPDatabase.mdb (Features and Parameters)

### 1.1 Overview

**File:** `FnPDatabase.mdb` (13MB, Access 97-2003 format)
**Purpose:** Organizes parameters into features and subfeatures by ECU type
**Tables:** 359 total tables (excluding temp)
**Records:** ~3,800 features, ~18,600 parameter mappings

### 1.2 Table Naming Convention

Tables are suffixed with `detectType` (ECU type identifier):
- `FEATURE_N` - Feature definitions for ECU type N
- `PARAMETER_N` - Feature-to-parameter mappings for ECU type N
- `SUBFEATURE_N` - Subfeature definitions for ECU type N

**Known ECU Types (detectType values):**
| detectType | Description |
|------------|-------------|
| 1-6 | Early ECU types |
| 12-23 | Common ECU types |
| 100-135 | CM550 family |
| 290-321 | CM2250/CM2350 family |
| 370-391 | CM2450 family |
| 720-723 | CM2880 family |
| 986-994 | Special/test types |
| 1065-1120 | ISX15/X15 family |
| 2000 | Generic/base type |
| 2921 | Development type |

### 1.3 FEATURE_N Table Schema

```sql
CREATE TABLE [FEATURE_N] (
    [featureID]      Text (8) NOT NULL,    -- Feature identifier
    [featureEnable]  Memo/Hyperlink (255) NOT NULL, -- Resource ID or enable expression
    [featureGTIS]    Text (8) NOT NULL,    -- GTIS token reference
    [SortBy]         Text (8) NOT NULL     -- Sort order (-1 = default)
);
```

**Sample Data (FEATURE_1):**
| featureID | featureEnable | featureGTIS | SortBy |
|-----------|---------------|-------------|--------|
| 1 | 25271 | 25275 | -1 |
| 11 | 20021 | 20025 | -1 |
| 33 | 10030\|20001\| | 0 | -1 |

**featureEnable Field:**
- Single numeric: Resource ID for feature name
- Pipe-delimited: Conditional expression (e.g., "10030|20001|" = either parameter)

### 1.4 PARAMETER_N Table Schema

```sql
CREATE TABLE [PARAMETER_N] (
    [featureID]     Text (8) NOT NULL,   -- Links to FEATURE_N.featureID
    [subFeatureID]  Text (8) NOT NULL,   -- Links to SUBFEATURE_N (0 = none)
    [parameterID]   Text (8) NOT NULL    -- Parameter identifier
);
```

**Sample Data (PARAMETER_1):**
| featureID | subFeatureID | parameterID |
|-----------|--------------|-------------|
| 1 | 0 | 20042 |
| 11 | 0 | 10090 |
| 11 | 0 | 10100 |
| 33 | 0 | 10030 |
| 33 | 0 | 20001 |

**Parameter ID Ranges:**
| Range | Description |
|-------|-------------|
| 1xxx-9xxx | Base system parameters |
| 10xxx-19xxx | Engine control parameters |
| 20xxx-29xxx | Vehicle interface parameters |
| 16xxxxxx | Extended/special parameters |

### 1.5 SUBFEATURE_N Table Schema

```sql
CREATE TABLE [SUBFEATURE_N] (
    [featureID]        Text (8) NOT NULL,   -- Parent feature ID
    [subFeatureID]     Text (8) NOT NULL,   -- Subfeature identifier
    [subFeatureEnable] Memo/Hyperlink (255) NOT NULL, -- Resource ID
    [subFeatureGTIS]   Text (8) NOT NULL    -- GTIS token reference
);
```

### 1.6 Supporting Tables

#### ParamDependencyInfo

```sql
CREATE TABLE [ParamDependencyInfo] (
    ParamID      Long Integer,  -- Parameter with dependency
    DepParamID   Long Integer   -- Dependent parameter
);
```

**Sample Data:**
| ParamID | DepParamID |
|---------|------------|
| 16783633 | 1020067 |
| 1020073 | 1020067 |

#### StaticToolTipParameters

```sql
CREATE TABLE [StaticToolTipParameters] (
    StaticToolTipTokenNumber  Long Integer  -- Parameter ID with tooltip
);
```

**Sample Data:** 16824016, 16790207, 16793806, etc.

### 1.7 Database Query Patterns

**Source:** `Cummins.INSITE.Kernel.MetadataServices.cs:149-173`

```csharp
// Get all features for an ECU type
string query = string.Format(GetFeaturesForECUQuery, detectType);
// Results in: SELECT * FROM FEATURE_{detectType}

// Get parameters for a feature
string query = string.Format(GetParametersForFeatureQuery, detectType, featureId);
// Results in: SELECT * FROM PARAMETER_{detectType} WHERE featureID = {featureId}

// Get all records for a parameter
string query = string.Format(GetAllRecordsForParameterQuery, detectType, parameterId);
// Results in: SELECT * FROM PARAMETER_{detectType} WHERE parameterID = {parameterId}
```

## 2. Metadata.accdb (Parameter Definitions)

### 2.1 Overview

**File:** `Metadata.accdb` (5.7MB, Access 2007+ format)
**Purpose:** Full parameter definitions with data types, ranges, units
**Status:** Not extractable with mdbtools (requires Access 2007+ support)

### 2.2 Known Schema (from code analysis)

**Source:** `Cummins.INSITE.Kernel.MetadataServices.cs`

Expected tables based on code references:
- Parameter definitions (name, unit, min, max, precision)
- Array definitions
- Service definitions
- Rule definitions
- Non-standard parameter info

### 2.3 Alternative Access Methods

To extract Metadata.accdb:
1. Use Microsoft Access directly
2. Use `mdb-export` with Access 2007+ support (libmdbtools >= 1.0)
3. Use Python `pyodbc` with Microsoft ACE driver
4. Use `accdb-dump` tool

## 3. INSITEHelp Database

### 3.1 Overview

**Purpose:** Maps fault codes and features to help content
**Tables:** 4 tables + schema
**Records:** ~58,000 help topic mappings

### 3.2 FaultHelpFileMap Table

```sql
CREATE TABLE [FaultHelpFileMap] (
    [SystemType]  Long Integer NOT NULL,  -- ECU system type
    [EFCode]      Long Integer NOT NULL,  -- Engine fault code
    [Language]    Text (50) NOT NULL,     -- Language code (EN, ZH, FR, etc.)
    [HelpFile]    Text (50) NOT NULL      -- Help file name (*.chm)
);
```

**Sample Data:**
| SystemType | EFCode | Language | HelpFile |
|------------|--------|----------|----------|
| 29 | 149 | EN | FIS2883472.chm |
| 1000 | 76 | EN | FIS3666118.chm |
| 1050 | 85 | EN | FIS4021317.chm |
| 1050 | 85 | ZH | FIS3667146.chm |

**SystemType Values:**
| Range | Description |
|-------|-------------|
| 29-51 | Legacy systems |
| 1000-1220 | CM870/ISX family |
| (etc.) | Various ECU families |

### 3.3 HelpTopicMap Table

```sql
CREATE TABLE [HelpTopicMap] (
    [ContextID]  Text (255) NOT NULL,  -- GUID for context
    [ModuleID]   Long Integer NOT NULL, -- Module identifier (-1 = all)
    [HelpPage]   Text (255) NOT NULL,  -- Page path in help file
    [Comment]    Text (255)            -- Description
);
```

**Sample Data:**
| ContextID | ModuleID | HelpPage | Comment |
|-----------|----------|----------|---------|
| 006AF3B7-6A31-11D4-87F5-0010A4D1AEB5 | -1 | html/109-435-001.htm#step_401 | Trip Information |
| 006AF3B7-6A31-11D4-87F5-0010A4D1AEB5 | 1 | html/109-435-001.htm#step_401 | Trip Information |

**ModuleID Values:**
- `-1` = All modules (universal)
- `1-21` = Specific ECU modules

### 3.4 HelpFileMap Table

```sql
CREATE TABLE [HelpFileMap] (
    [ModuleID]   Long Integer NOT NULL,
    [Language]   Text (50) NOT NULL,
    [HelpFile]   Text (50) NOT NULL
);
```

### 3.5 LanguagePrefixes Table

```sql
CREATE TABLE [LanguagePrefixes] (
    [Language]  Text (50),   -- Language code (EN, ZH, FR, etc.)
    [Prefix]    Text (50)    -- File prefix for localization
);
```

## 4. Cross-Reference with E2M Files

### 4.1 Parameter ID Correlation

Both FnPDatabase and E2M files use similar parameter ID ranges:

| Source | ID Format | Example |
|--------|-----------|---------|
| FnPDatabase | Integer string | "10090", "20042" |
| E2M Column 14 | Hex (Group ID) | 0x1041, 0x103E |
| E2M Column 3 | Hex (Memory Block) | 0x1040, 0x103F |

**Key Discovery:** FnPDatabase parameterIDs may correspond to E2M Group IDs converted to decimal.

### 4.2 Feature/Group Mapping

| FnPDatabase | E2M Equivalent |
|-------------|----------------|
| featureID | Type G parameter's Column 14 |
| parameterID | Parameter's Column 14 Group ID |
| featureEnable (resource) | Parameter name string |

### 4.3 Memory Addressing

E2M files provide the memory address formula:
```
Memory Address = BaseLookup[Column3] + Column4
```

FnPDatabase provides feature organization but not direct memory addresses. The correlation happens through:
1. E2M parameterID → Column 14 (Group ID)
2. FnPDatabase parameterID → Feature association
3. GTIS tokens → Display strings

## 5. Database Access in Code

### 5.1 OleDb Connection Pattern

**Source:** `Cummins.INSITE.Kernel.MetadataServices.cs`

```csharp
// Connection via OleDbDataReader
OleDbDataReader val = alVnL9uad2[(KrpwUtILsw9WxuIeDB)1].ExecuteQuery(query);
while (((DbDataReader)(object)val).Read())
{
    // Process row
}
```

### 5.2 Key Service Methods

| Method | Purpose |
|--------|---------|
| `GetFeaturesForECU(detectType)` | Get all features for ECU type |
| `GetParametersForFeature(detectType, featureId)` | Get parameters in feature |
| `GetFeatureDefinition(detectType, featureId)` | Get feature metadata |
| `GetDetectTypeForECUType(ECUType)` | Map ECU type to detect type |
| `GetFaultInformation(ecuType, faultCode)` | Get fault help info |

## 6. Implementation Notes for kuminz-ui

### 6.1 Database File Locations

Default Insite installation paths:
- `C:\Program Files (x86)\Cummins\INSITE\Data\FnPDatabase.mdb`
- `C:\Program Files (x86)\Cummins\INSITE\Data\Metadata.accdb`
- `C:\Program Files (x86)\Cummins\INSITE\Help\INSITEHelp.mdb`

### 6.2 Recommended Approach

For kuminz-ui, consider:
1. Extract FnPDatabase tables to SQLite or PostgreSQL
2. Use e2m files directly for parameter definitions
3. Build help system from FaultHelpFileMap + extracted .chm content

### 6.3 ECU Type Detection Flow

```cpp
class ECUTypeMapper {
    int getDetectTypeForECU(int ecuType) {
        // 1. Query ECU for identification
        // 2. Map ECU type to detectType
        // 3. Use detectType for table suffix
        return detectType;
    }

    QStringList getFeaturesForECU(int detectType) {
        // Query FEATURE_{detectType} table
        return features;
    }
};
```

## Source Files Reference

| File | Size | Key Content |
|------|------|-------------|
| `FnPDatabase.mdb` | 13 MB | Feature/Parameter organization |
| `Metadata.accdb` | 5.7 MB | Parameter definitions (Access 2007+) |
| `Cummins.INSITE.Kernel.MetadataServices.cs` | Large | FnPDatabaseQueries, database access |
| `Cummins.INSITE.AddIns.FeaturesAndParameters.cs` | Large | UI integration |
| `Cummins.INSITE.CNL.FeaturesAndParametersDataOM.cs` | Large | Data object model |

## Related Tasks

- Task 002: E2M Analysis (parameter addressing)
- Task 009: Insite Reverse Engineering Process

---
*Generated from Insite 9 decompilation analysis - December 2024*
