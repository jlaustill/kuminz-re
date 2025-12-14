# Insite Diagnostic Functions Specification

This document describes the diagnostic function implementations in Insite, reverse engineered from the Insite 9 decompilation.

## Diagnostic Architecture Overview

```
+--------------------------------------------------+
|           UI Layer (Add-Ins)                     |
|   FaultsInformationAddIn, GraphicalMonitoring    |
+--------------------------------------------------+
                        |
+--------------------------------------------------+
|           Service Layer (.NET)                   |
|   MonitorServices, DataServices, MetadataServices|
+--------------------------------------------------+
                        |
+--------------------------------------------------+
|           Data Object Model                      |
|   FaultsDataOM (CFaultSnapshot, CFaultInfo)      |
+--------------------------------------------------+
                        |
+--------------------------------------------------+
|           Protocol Layer                         |
|   CLIP (PCL), J1939 (PJ1939) via PCLSystem.dll   |
+--------------------------------------------------+
                        |
+--------------------------------------------------+
|           Hardware Layer (CAN Bus)               |
+--------------------------------------------------+
```

## 1. Fault Code (DTC) Handling

### 1.1 Fault Information Structure

**Source**: `Cummins.INSITE.Kernel.ECMServicesAPI.cs:533-552`

```csharp
public interface IFaultInformation {
    int FaultCode { get; }           // Cummins fault code
    int ECUType { get; }             // ECU type identifier
    int ResourceId { get; }          // Resource ID for localization
    int SourceIdentifier { get; }    // J1939 SPN (Suspect Parameter Number)
    int ParameterIdentifier { get; } // Parameter ID
    int FailureModeIndicator { get; }  // J1939 FMI (primary)
    int FailureModeIndicator2 { get; } // J1939 FMI (secondary)
    int SuspectParameterName { get; }  // SPN name reference
    string Lamp { get; }             // MIL/Warning lamp status
}
```

### 1.2 J1939 Diagnostic Message Format

Insite follows the SAE J1939 diagnostic message standard:

| Field | Bits | Description |
|-------|------|-------------|
| SPN | 19 | Suspect Parameter Number (identifies the fault) |
| FMI | 5 | Failure Mode Indicator (type of failure) |
| OC | 7 | Occurrence Count |
| CM | 1 | Conversion Method |

**Common FMI Values:**
| FMI | Description |
|-----|-------------|
| 0 | Data Valid But Above Normal Range - Most Severe |
| 1 | Data Valid But Below Normal Range - Most Severe |
| 2 | Data Erratic, Intermittent, or Incorrect |
| 3 | Voltage Above Normal or Shorted High |
| 4 | Voltage Below Normal or Shorted Low |
| 5 | Current Below Normal or Open Circuit |
| 6 | Current Above Normal or Grounded Circuit |
| 7 | Mechanical System Not Responding Properly |
| 8-10 | Abnormal Frequency/Update Rate/Change Rate |
| 11 | Failure Mode Not Identifiable |
| 12 | Bad Intelligent Device or Component |
| 13 | Out of Calibration |
| 14-15 | Special Instructions |
| 16-30 | Reserved for SAE Assignment |
| 31 | Not Available |

### 1.3 Fault Retrieval Flow

**Source**: `Cummins.INSITE.Kernel.MetadataServices.cs`

```
1. UI requests fault information
2. MetadataServices.GetFaultInformation(ecuType, faultCode)
3. Database query via GetFaultInformationQueryFormat
4. Returns IFaultInformation populated from database
5. Help lookup via FaultHelpFileMap.csv for additional context
```

### 1.4 Key DLLs for Fault Handling

| DLL | Size | Purpose |
|-----|------|---------|
| FaultsInformationAddIn_ghidra.c | 4.4 MB | Fault display UI |
| FaultsDataOM_ghidra.c | 994 KB | Fault data object model |
| MuxFaultData_ghidra.c | 1.6 MB | J1939 multiplexed fault data |
| CureCore_libFNP_ghidra.c | 15 MB | Core diagnostic engine |

### 1.5 Fault Help System

**Database Tables** (from INSITEHelp.mdb):
- `FaultHelpFileMap.csv` - Maps SystemType + EFCode + Language to .chm help file
- `HelpTopicMap.csv` - Maps ContextID (GUID) + ModuleID to help page

## 2. Freeze Frame (Snapshot) Data

### 2.1 CFaultSnapshot Class

**Source**: `FaultsDataOM_ghidra.c`

The `CFaultSnapshot` class stores ECU state at the time a fault occurred:

```cpp
class CFaultSnapshot : public IXMLSerializationImpl {
    // Captured parameter values at fault occurrence
    // Timestamp of capture
    // Associated fault code
    // ECU identifier
};
```

### 2.2 Snapshot Retrieval

Freeze frame data is retrieved using J1939 DM messages:
- **DM1** - Active Diagnostic Trouble Codes
- **DM2** - Previously Active Diagnostic Trouble Codes
- **DM4** - Freeze Frame Parameters

## 3. Parameter Monitoring System

### 3.1 Monitoring Architecture

**Source**: `Cummins.INSITE.Kernel.MonitorServices.cs`

```
MonitorServices
    └── MonitorService (per connection)
            ├── Monitor
            │       ├── MonitoredParameterManager
            │       │       ├── MonitoredParameter (single param)
            │       │       └── MonitoredGroup (grouped params)
            │       └── ParameterPoller
            │               ├── BeginParameterPolling()
            │               └── BeginGroupPolling()
            └── Logger
                    └── XmlLogfile
```

### 3.2 Polling Mechanism

**Source**: `Cummins.INSITE.Kernel.MonitorServices.cs:203-230`

```csharp
// Single parameter polling
public void BeginParameterPolling(MonitoredParameter parameter) {
    IReader reader = Utilities.Connector.GetReader(connectionId);
    int requestId = reader.GetParameterValueAsync(
        parameter.ParameterObject,
        parameter.SourceAddress,
        parameter.Protocol,
        parameter.SamplingRate,
        parameter.OnReadComplete  // Callback
    );
    parameter.RequestId = requestId;
}

// Group polling (more efficient)
public void BeginGroupPolling(MonitoredGroup group) {
    IReader reader = Utilities.Connector.GetReader(connectionId);
    int requestId = reader.GetParameterValuesAsync(
        group.Parameters,
        group.SourceAddress,
        group.Protocol,
        group.SamplingRate,
        group.OnReadComplete
    );
    group.RequestId = requestId;
}
```

### 3.3 Trigger Types

**Source**: `Cummins.INSITE.Kernel.ECMServicesAPI.cs:564-571`

```csharp
public enum TriggerType {
    None = 0,           // No automatic triggering
    ValueChanged = 1,   // Fire when value changes
    Periodic = 2,       // Fire at regular intervals
    Custom = 4,         // Fire based on custom condition
    All = 7             // All triggers
}
```

### 3.4 Custom Trigger Operators

**Source**: `Cummins.INSITE.Kernel.ECMServicesAPI.cs:691-698`

```csharp
public enum CustomTriggerOperator {
    Equal,
    LessThan,
    LessThanOrEqual,
    GreaterThan,
    GreaterThanOrEqual,
    NotEqual
}

public enum CustomTriggerOperandType {
    Value,      // Compare to static value
    Parameter   // Compare to another parameter
}
```

### 3.5 Monitor Events

| Event | Description |
|-------|-------------|
| DisplayValueUpdated | Formatted display value changed |
| RawValueUpdated | Raw ECU value changed |
| MonitorUpdated | Monitor state changed |

### 3.6 MonitorService Interface

**Source**: `Cummins.INSITE.Kernel.ECMServicesAPI.cs:572+`

```csharp
public interface IMonitorService {
    int Id { get; }
    bool IsActive { get; }
    ILogger Logger { get; }
    IDataService DataService { get; }
    ICustomTriggerManager CustomTriggerManager { get; }

    event EventHandler<DisplayValueUpdatedEventArgs> DisplayValueUpdated;
    event EventHandler<RawValueUpdatedEventArgs> RawValueUpdated;

    void Start();
    void Stop();
    void AddParameter(int ecuId, int parameterId, int samplingRate, TriggerType triggerType);
    void AddGroup(int ecuId, IParameterGroup group, int samplingRate, TriggerType triggerType);
    void RemoveParameter(int ecuId, int parameterId);
}
```

## 4. Data Logging System

### 4.1 DataMonitorLogger API

**Source**: `Interop.DataMonitorLoggerAPILib.cs`

```csharp
// Parameter definition for logging
public interface IDMLParameter {
    string Cookie { get; }           // Unique identifier
    string ModuleID { get; set; }    // ECU module
    string ParameterID { get; set; } // Parameter ID
    string ParameterName { get; set; }
    string ParameterUnit { get; set; }
    string ParameterEnumId { get; set; }  // For enumerated values
}

// Parameter group
public interface IDMLGroup {
    string GroupID { get; set; }
    string GroupName { get; set; }
    DMLGroupTypeEnum GroupType { get; set; }  // Default, Custom
    string ModuleID { get; set; }
    IDMLParameters Parameters { get; }

    void AddParameter(string Cookie);
    void RemoveParameter(string Cookie);
}

// Available groups from metadata
public interface IDMLAvailableGroups {
    IDMLModuleNames ModuleNames { get; }

    IDMLGroup GetAllParametersForModule(string ModuleID);
    IDMLGroups GetGroupsByName(string Name);
    void GetGroupNames(out BSTRCollection names, out LongCollection groupTypes);

    // Group management
    void AddGroup(string Name, BSTRCollection cookies);
    void RemoveGroup(string Name);
    void RenameGroup(string oldName, string newName);
    void EditGroup(string Name, BSTRCollection cookies);

    // Import/Export
    void ExportGroupsToFile(string groupName, string fileName);
    void ImportGroupsFromFile(string fileName);
}
```

### 4.2 Group Types

```csharp
public enum DMLGroupTypeEnum {
    GroupTypeUnknown,   // 0
    GroupTypeDefault,   // 1 - Pre-defined from metadata
    GroupTypeCustom     // 2 - User-created
}
```

### 4.3 Logfile Abstract Class

**Source**: `Cummins.INSITE.Kernel.MonitorServices.cs:232-258`

```csharp
internal abstract class Logfile : DisposableObject {
    public abstract event EventHandler LowDiskSpace;

    public abstract void AddHeaderInfo(string itemName, string itemValue);
    public abstract void AddECUInformation(IDictionary<int, int> ecuInfo);
    public abstract void AddSample(int ecuId, int parameterId, object value,
                                   DateTime timestamp, int sourceAddress);
    public abstract void AddLoggingResumedNotification(DateTime lastPausedTime,
                                                        TimeSpan pauseDuration);
    public abstract void AddEvent(int eventId, DateTime timestamp, string description);
    public abstract void AddParameterRemovedNotification(DateTime timestamp,
                                                          int parameterId, int sourceAddress);
    public abstract void Save();
    public abstract void SaveTo(string outputFileName);
}
```

### 4.4 Log File Format

Insite uses XML format via `XmlLogfile` class for data logs:
- Header info (system, ECU details)
- ECU identification
- Parameter samples with timestamps
- Events
- Parameter removal notifications

### 4.5 Log File Converter

```csharp
public interface IDMLLogFileConverter {
    void ConvertLogFile(string sourceFileName, string destinationFileName,
                        string delimitingCharacter);
    void Initialize(object pParameterDefinitions);
}
```

## 5. ECU Module Detection

### 5.1 Module Names Interface

**Source**: `Interop.DataMonitorLoggerAPILib.cs:348-414`

```csharp
public interface IDMLModuleNames {
    int Count { get; }
    string Name { get; }
    string ModuleID { get; }
    int SourceAddress { get; }           // J1939 source address
    string SystemName { get; set; }
    string ServiceECMMarketingName { get; set; }

    void Add(string moduleName, string ModuleID, string detectID, int SourceAddress);
    void Remove(int SourceAddress);
    void Clear();
}
```

### 5.2 Source Address Mapping

In J1939, each ECU has a unique source address (0-253):
| Address | Typical Assignment |
|---------|-------------------|
| 0 | Engine #1 |
| 3 | Transmission |
| 11 | Brakes - System Controller |
| 15 | Retarder - Exhaust |
| 49 | Instrument Cluster |
| 249 | Off-board Diagnostic Tool |

## 6. Implementation Notes for kuminz-ui

### 6.1 Fault Code Display

```cpp
// Pseudo-code for kuminz-ui fault handling
class FaultManager {
    QList<FaultInfo> getActiveFaults() {
        // Request DM1 message
        // Parse SPN, FMI, OC from response
        // Look up fault description from database
        return faults;
    }

    QList<FaultInfo> getStoredFaults() {
        // Request DM2 message
        // Parse historical faults
        return faults;
    }

    void clearFaults() {
        // Send DM11 (Clear Active DTCs)
        // Or DM3 (Clear Previously Active DTCs)
    }
};
```

### 6.2 Parameter Monitoring

```cpp
class ParameterMonitor {
    void addParameter(int parameterId, int samplingRate, TriggerType trigger) {
        // Add to polling list
        // Start async read loop
    }

    void onValueReceived(int parameterId, QVariant value, QDateTime timestamp) {
        // Check trigger conditions
        // Fire valueChanged signal if triggered
        // Log to file if logging enabled
    }
};
```

### 6.3 Recommended Sampling Rates

| Parameter Type | Suggested Rate |
|----------------|----------------|
| Engine Speed | 100-200 ms |
| Temperatures | 500-1000 ms |
| Pressures | 200-500 ms |
| Status/Switches | 500 ms |
| Configuration | On-demand only |

## Source Files Reference

| File | Size | Key Content |
|------|------|-------------|
| `Cummins.INSITE.Kernel.MonitorServices.cs` | 51K tokens | Full monitoring implementation |
| `Cummins.INSITE.Kernel.ECMServicesAPI.cs` | Large | IFaultInformation, TriggerType, IMonitorService |
| `Interop.DataMonitorLoggerAPILib.cs` | 455 lines | DML interfaces for logging |
| `FaultsInformationAddIn_ghidra.c` | 4.4 MB | Fault UI implementation |
| `FaultsDataOM_ghidra.c` | 994 KB | CFaultSnapshot, fault data model |

## Related Tasks

- Task 003: CLIP Protocol Implementation (kuminz-ui)
- Task 009: Insite Reverse Engineering Process

---
*Generated from Insite 9 decompilation analysis - December 2024*
