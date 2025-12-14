# Insite Calibration Handling Specification

This document describes the calibration file handling, ECU flash update process, and security/authentication mechanisms in Insite, reverse engineered from the Insite 9 decompilation.

## Calibration Architecture Overview

```
+--------------------------------------------------+
|           UI Layer                               |
|   ReflashControl, FeaturesAndParameters          |
+--------------------------------------------------+
                        |
+--------------------------------------------------+
|           Service Layer (.NET)                   |
|   ImageServices, DataServices                    |
+--------------------------------------------------+
                        |
+--------------------------------------------------+
|           Core Engine (Native)                   |
|   DownloadLibrary, CureCore.dll                  |
+--------------------------------------------------+
                        |
+--------------------------------------------------+
|           Protocol Layer                         |
|   CLIP (PCL), J1939 via PCLSystem.dll            |
+--------------------------------------------------+
                        |
+--------------------------------------------------+
|           Hardware Layer (CAN Bus)               |
+--------------------------------------------------+
```

## 1. Security Model

### 1.1 Security Levels (Tool License)

**Source**: `Cummins.INSITE.AddIns.FeaturesAndParameters.cs:651-662`

```csharp
public enum SecurityLevel {
    Basic,         // 0 - Read-only for most parameters
    OBDRSGR,       // 1 - OBD + RSGR
    OBD,           // 2 - OBD compliance level
    RSGR,          // 3 - Road Speed Governor & Road Speed Limiter
    RSGRPlus,      // 4 - RSGR with additional parameters
    Lite,          // 5 - Lite tool level (simulators)
    IndustrialPro, // 6 - Industrial equipment
    Pro,           // 7 - Professional level
    ProPlus        // 8 - Full access professional
}
```

### 1.2 ECU Password Types

**Source**: `Interop.CONMANAPILib.cs:23-30`

```csharp
public enum tagCIPasswordTypeEnum {
    PTE_MASTER_PASSWORD = 1,     // Cummins master access
    PTE_OEM_PASSWORD = 2,        // OEM-level access (usage ID 23)
    PTE_ADJUSTABLE_PASSWORD = 3, // Customer-adjustable parameters
    PTE_RESET_PASSWORD = 4,      // Reset locked parameters
    PTE_OEM_PASSWORD2 = 6        // Secondary OEM access (usage ID 34)
}
```

### 1.3 Password States

**Source**: `Interop.CONMANAPILib.cs:31-37`

```csharp
public enum tagCIPasswordStateEnum {
    PSE_NOT_SUPPORTED,  // ECU doesn't support this password
    PSE_DISABLED,       // Password is disabled
    PSE_LOCKED,         // Password is locked (needs validation)
    PSE_UNLOCKED        // Password validated, access granted
}
```

### 1.4 Parameter Access Levels

**Source**: `Interop.SymbolicTreeObj.cs:733-742`

```csharp
public enum tagCIAccessLevel {
    ReadOnly = 0,
    ProductEngineering = 1,
    ServiceEngineering = 2,
    VehiclePerformance = 4,
    EnginePerformance = 16,
    FuelSystemControls = 32,
    FullAccess = -1
}
```

### 1.5 Password Operations

**Source**: `Interop.CONMANAPILib.cs:317-338`

| Method | Description |
|--------|-------------|
| `GetPasswordState()` | Check if password is locked/unlocked |
| `HasRightsToChangePwd()` | Check if tool can modify password |
| `ValidatePassword()` | Validate password with ECU |
| `SetPassword()` | Set new password value |
| `DisablePassword()` | Disable password protection |
| `LockPassword()` | Re-lock password |
| `ResetPasswords()` | Reset all OEM passwords |
| `CheckPasswordsAlignment()` | Verify password sync across ECUs |

### 1.6 OEM Password Structure

**Source**: `Cummins.INSITE.Kernel.ECMServicesAPI.cs`

```csharp
public struct PasswordsStruct {
    public bool IsOEMAccessible { get; set; }   // Usage ID 23
    public bool IsOEM2Accessible { get; set; }  // Usage ID 34
}

// COM interface version
public struct tagPasswordsStruct {
    public int bIsOEMAccessible;   // 0 = false, non-zero = true
    public int bIsOEM2Accessible;
}
```

## 2. Calibration File Handling

### 2.1 Image/Calibration Interface

**Source**: `Cummins.INSITE.Kernel.INSITEImageReader.cs`

```csharp
public interface IINSITEImage {
    string ImageFilePath { get; }
    bool CanWrite { get; }              // Is image writable
    int ECUType { get; }                // Target ECU type
    int SystemType { get; }             // Engine system type
    string Version { get; }             // Calibration version
    bool RegionalSettingsApplied { get; }
    bool HasOtherDevices { get; }

    IImageParameter GetParameter(string parameterId, int sourceAddress = 0);
    IImageArray GetArray(string arrayId);
}
```

### 2.2 Calibration File Format

**Compression**: Password-protected using `CILCompressionUtilitiesLib`

**Password Source**: `ECMServicesConfiguration.Configuration.GetConfigurationValue()`

**Supported Extensions** (from `DownloadLibrary.getDefaultFileExtension()`):
- `.hex` - Intel HEX format
- `.xcal` - xCal calibration format
- `.*` - All files

### 2.3 File Read Flow

```
1. DownloadLibrary(fileName) constructor
2. loadFile(fileName) - opens file stream
3. verifyLoadedCalibration() - validates format
4. getCalibrationPID() - extracts product ID
5. CoreLicense.Instance.checkPIDLicense() - validates PID license
```

### 2.4 Image Creation Result

**Source**: `Cummins.INSITE.Kernel.ECMServicesAPI.cs`

```csharp
public enum ImageCreationResult {
    Success,
    FileExists,
    MetadataNotFound,
    ErrorCreatingImage,
    InvalidPath,
    Cancelled
}
```

## 3. ECU Flash/Reflash Process

### 3.1 Download Library

**Source**: `CureCore.cs:6432+`

```csharp
public class DownloadLibrary : IDisposable {
    // System management
    public static void startSystem();   // Initialize PCL system
    public static void stopSystem();    // Shutdown PCL system

    // Constructors
    public DownloadLibrary(DownloadAlgorithm algo);  // Algorithm-specific
    public DownloadLibrary(string fileName);          // File-based

    // ECU Discovery
    public Dictionary<uint, ECUInfo> getAvailableECUs(string devicePrefix, int dlaID);

    // Download operations
    public void verifyLoadedCalibration();
    public string getCalibrationVersion();
    public DownloadAlgorithm getDownloadAlgorithm();
}
```

### 3.2 Download Algorithms

**Source**: `CureCore.cs / CureModelController.cs`

```csharp
public enum DownloadAlgorithm {
    Bosch_DCU = 0,   // Bosch DCU-based controllers
    GTIS4_ECU = 1,   // GTIS4/GTIS45 controllers
    UNKNOWN = -1
}
```

### 3.3 Reflash Status Flow

**Source**: `ReflashControl.cs:300-312`

```csharp
public enum ReflashStatus {
    NoEcuDetected,              // No ECU found on network
    FailToReadCalFile,          // Calibration file read error
    CalibrationFileNotCompatible,// File doesn't match ECU
    ReflashStart,               // Download beginning
    ReflashFailNoResponse,      // ECU not responding
    ReflashFailNack,            // ECU rejected data
    ReflashSuccess,             // Download completed
    DriverError,                // Communication driver error
    UnknownError,               // Unspecified error
    NoCompatibleCalFound        // No matching calibration
}
```

### 3.4 Calibration Download Status

**Source**: `Interop.CONMANAPILib.cs:43-47`

```csharp
public enum tagCalibrationDownloadStatus {
    NO_CALDNLD,           // No download in progress
    CALDNLD_IN_PROGRESS   // Download active
}
```

### 3.5 Template Transfer

**Source**: `Cummins.INSITE.Kernel.ECMServicesAPI.cs:100`

```csharp
TemplateTransferResult TransferTemplateToECU(
    string templateFilePath,
    PasswordsStruct Passwords,
    out IParameterGroup unwrittenParameterIds
);
```

### 3.6 Template Transfer Results

**Source**: `Cummins.INSITE.Kernel.ECMServicesAPI.cs`

```csharp
public enum TemplateTransferResult {
    Success,                // Transfer completed
    TemplateNotWriteable,   // Template is read-only
    ECUNotInApplication,    // ECU not in app mode
    TemplateLoadFailure,    // Failed to load template
    UnknownFailure,         // Unspecified error
    EngineSpeedDetected,    // Engine running (safety)
    Interrupted             // User cancelled
}
```

### 3.7 Download Error States

**Source**: `CureModelController.cs:225-252`

| Error Code | State | Error | Recovery |
|------------|-------|-------|----------|
| 0 | PreDownload | GeneralError | ConnectionSetupErrorMessage |
| 1 | PreDownload | CommunicationTimeout | ConnectionSetupErrorMessage |
| 2 | PreDownload | NegRespFromECU | ConnectionSetupErrorMessage |
| 64 | TransferringData | GeneralError | ConnectionSetupErrorMessage |
| 65 | TransferringData | CommunicationTimeout | ConnectionSetupErrorMessage |
| 66 | TransferringData | NegRespFromECU | ConnectionSetupErrorMessage |
| 80 | PostDownload | GeneralError | ConnectionSetupErrorMessage |
| 81 | PostDownload | CommunicationTimeout | ConnectionSetupErrorMessage |
| 82 | PostDownload | NegRespFromECU | ConnectionSetupErrorMessage |

## 4. Parameter Write Operations

### 4.1 Write Flow

**Source**: `Cummins.INSITE.Kernel.CommunicationServices.cs:240-244`

```csharp
// Via CommunicationServices
commImplementor.SetParameterValues(
    connectionId,
    ecuSourceAddress,
    protocol,
    parameterValues,
    out unwrittenParameters
);
```

### 4.2 Write Interface

**Source**: `Cummins.INSITE.Kernel.ECMServicesAPI.cs:640-644`

```csharp
public interface IDataService {
    void WriteParameter<T>(int parameterId, T paramValue,
                           bool valueIsRaw, bool saveChanges);
    void WriteParameter(int parameterId, object paramValue,
                        bool valueIsRaw, bool saveChanges);
    IGroup WriteGroup(IParameterValueGroup groupForWrite,
                      bool valuesAreRaw, bool saveChanges);
}
```

### 4.3 Write Preconditions

**Source**: `Interop.CONMANAPILib.cs:16-20`

```csharp
public enum tagCIMLSPreconditionEnum {
    PCE_SAFETOWRITE,   // Safe to write
    PCE_ENGINESPEED    // Engine speed check (must be 0)
}
```

## 5. Key DLLs for Calibration Handling

| DLL | Type | Size | Purpose |
|-----|------|------|---------|
| CureCore.dll | Native/Managed | 5+ MB | Core download engine |
| caldnld.dll | Native | ~200 KB | CCalibrationDownloadImpl |
| iclb.dll | Native | ~150 KB | ICL protocol layer |
| ImageServices.cs | .NET | 57 KB | Image/calibration services |
| ReflashControl.cs | .NET (WPF) | 30 KB | Reflash UI control |
| CureModelController.cs | .NET | 20 KB | CURE download model |

## 6. Cross-Reference with E2M Analysis

### 6.1 Parameter Addressing

E2M file format (from `e2m-analysis`):
- **Memory Address Formula**: `Base + (Column3 × 256) + Column4`
- **Column 7** determines access control (combines with Type)
- **Column 14** is Group ID for parameter grouping

Insite reads/writes these parameters via:
- CLIP protocol: `requestGetParameterValues()` / `requestSetParameterValues()`
- J1939 protocol: `requestGetValueByAddress()` / `requestSetValueByAddress()`

### 6.2 Access Control Mapping

| E2M Column 7 | Insite Access Level | Description |
|--------------|---------------------|-------------|
| Read-only | ReadOnly | No write access |
| Customer | Adjustment | Customer-adjustable |
| OEM | OEM Password | OEM password required |
| Master | Master Password | Cummins master only |

## 7. Implementation Notes for kuminz-ui

### 7.1 Parameter Write Process

```cpp
class CalibrationManager {
    bool writeParameter(int parameterId, QVariant value) {
        // 1. Check engine is stopped (safety)
        if (!isEngineStopped()) return false;

        // 2. Check password requirements
        AccessLevel required = getRequiredAccessLevel(parameterId);
        if (required > currentAccessLevel) {
            // Prompt for password
            if (!validatePassword(required)) return false;
        }

        // 3. Write via CLIP protocol (max 256 per batch)
        return clipSession.setParameterValue(parameterId, value);
    }
};
```

### 7.2 Flash/Reflash Process

```cpp
class ReflashManager {
    ReflashStatus reflash(const QString& calFile) {
        // 1. Load and verify calibration file
        if (!loadCalibration(calFile))
            return ReflashStatus::FailToReadCalFile;

        // 2. Discover ECU
        auto ecus = discoverECUs();
        if (ecus.isEmpty())
            return ReflashStatus::NoEcuDetected;

        // 3. Check compatibility
        if (!isCompatible(ecus.first()))
            return ReflashStatus::CalibrationFileNotCompatible;

        // 4. Execute download
        emit statusChanged(ReflashStatus::ReflashStart);
        if (!executeDownload())
            return ReflashStatus::ReflashFailNoResponse;

        return ReflashStatus::ReflashSuccess;
    }
};
```

### 7.3 Password Validation Flow

```cpp
class SecurityManager {
    bool validatePassword(PasswordType type, const QString& password) {
        // 1. Check if password is already unlocked
        PasswordState state = getPasswordState(type);
        if (state == PasswordState::Unlocked) return true;
        if (state == PasswordState::NotSupported) return false;

        // 2. Send validation request to ECU
        int responseCode;
        bool success = validateWithECU(type, password, &responseCode);

        // 3. Check response
        return (responseCode == 0);  // 0 = success
    }
};
```

## Source Files Reference

| File | Size | Key Content |
|------|------|-------------|
| `Cummins.INSITE.AddIns.FeaturesAndParameters.cs` | Large | SecurityLevel enum, password handling |
| `Interop.CONMANAPILib.cs` | 15 KB | Password types, states, operations |
| `Cummins.INSITE.Kernel.ECMServicesAPI.cs` | Large | IDataService, PasswordsStruct, TemplateTransferResult |
| `Cummins.INSITE.Kernel.ImageServices.cs` | 57 KB | IINSITEImage, TransferTemplateToECU |
| `Cummins.INSITE.Kernel.INSITEImageReader.cs` | 8 KB | Image file reading |
| `ReflashControl.cs` | 30 KB | Reflash UI, ReflashStatus enum |
| `CureCore.cs` | 100+ KB | DownloadLibrary, DownloadAlgorithm |
| `CureModelController.cs` | 20 KB | CUREUIModel, error handling |
| `caldnld_ghidra.c` | 200 KB | CCalibrationDownloadImpl |

## Related Tasks

- Task 002: E2M Analysis (parameter addressing)
- Task 003: CLIP Protocol Implementation (kuminz-ui)
- Task 009: Insite Reverse Engineering Process

---
*Generated from Insite 9 decompilation analysis - December 2024*
