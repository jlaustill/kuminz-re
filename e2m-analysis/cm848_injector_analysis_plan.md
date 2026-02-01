# CM848 Fuel Injector Dead Time & EOI Analysis Plan

## Objective
Analyze and extract fuel injector timing parameters from CM848 ECU calibration files:
- Injector dead time compensation tables
- Switch-off to End of Injection (EOI) delays
- Voltage compensation curves
- Pressure compensation factors
- Individual cylinder trim values

## Background: CM848 ECU
- **Years**: 2003-2004.5 (early common rail)
- **Engines**: 5.9L ISB (305HP CM848B, 325HP CM848C)
- **Injection System**: Bosch common rail (1st generation for Cummins)
- **Calibration Format**: E2M metafiles + ECFG configuration files

## File Structure

### E2M Files (Metafiles)
Electronic Engine Management files containing:
- Calibration tables and maps
- Fuel injection timing parameters
- Turbo control maps
- Emissions control parameters

### ECFG Files (Configuration)
Engine Configuration Files defining:
- ECM operational parameters
- Feature enable/disable flags
- Critical part list (CPL) data
- Individual ECU settings

## Key Parameters to Extract

### 1. Injector Dead Time Tables
**Location in calibration**: Typically stored as 2D/3D tables
- **Primary index**: Battery voltage (11-16V range)
- **Secondary index**: Rail pressure (optional)
- **Values**: Dead time in microseconds or degrees

**Expected data structure**:
```
Dead_Time_Table[voltage_index] = microseconds
or
Dead_Time_Table[voltage_index][pressure_index] = microseconds
```

### 2. Switch-Off Delay (EOI Timing)
**Components**:
- Solenoid de-energization time
- Mechanical closing delay
- Hydraulic delay compensation

**May be combined with or separate from dead time**

### 3. Voltage Compensation
**Parameters**:
- Minimum operating voltage threshold
- Maximum voltage threshold
- Compensation curve (linear or lookup table)
- Default voltage reference (typically 13.5V)

### 4. Rail Pressure Compensation
**For CM848 common rail**:
- Low pressure: ~5,000 PSI (idle)
- Medium: ~15,000 PSI (cruise)
- High: ~23,000-26,000 PSI (max power)

Dead time may vary with pressure

### 5. Individual Cylinder Corrections
**IQA (Injector Quantity Adjustment)**:
- Per-cylinder trim values (-127 to +127 typical)
- Compensates for injector-to-injector variation
- Programmed via Cummins Insite

### 6. Multiple Injection Timing
**CM848 supports**:
- Pilot injection timing and duration
- Main injection timing and duration  
- Post injection timing (if equipped for DPF regen)

Each event has its own dead time compensation

## Analysis Tools Needed

### 1. E2M/ECFG Parser
```python
class CumminsCalibrationParser:
    def __init__(self, e2m_file, ecfg_file):
        self.e2m = self.parse_e2m(e2m_file)
        self.ecfg = self.parse_ecfg(ecfg_file)
    
    def extract_injector_tables(self):
        # Find injector timing tables
        # Parse dead time compensation
        # Extract voltage curves
        pass
    
    def find_table_by_pattern(self, pattern):
        # Search for tables matching naming patterns
        # "INJ_DEAD_TIME", "DEAD_TIME_COMP", etc.
        pass
```

### 2. Binary Structure Analyzer
E2M files are likely binary format with:
- Header section (metadata)
- Table directory/index
- Raw calibration data (tables)
- Checksums/CRCs

Need to reverse engineer format or use existing tools

### 3. Visualization Tools
Generate plots showing:
- Dead time vs. voltage curves
- Dead time vs. pressure curves
- Comparison between stock/modified calibrations
- Individual cylinder trim distribution

## Reverse Engineering Approach

### Phase 1: File Format Analysis
1. Collect sample CM848 E2M/ECFG files
2. Use hex editor to identify structure
3. Look for ASCII strings indicating table names
4. Identify repeating patterns (table headers)
5. Find checksums and validation bytes

### Phase 2: Table Identification
1. Search for known parameter names/IDs
2. Compare multiple calibration files to find differences
3. Identify voltage/pressure axis values
4. Validate table sizes and data ranges

### Phase 3: Extraction & Validation
1. Write parser to extract identified tables
2. Cross-reference with known CM848 specifications
3. Validate extracted values against expected ranges:
   - Dead time: 0.3-1.5ms typical
   - Voltage range: 11-16V
   - Pressure range: 5,000-26,000 PSI

### Phase 4: Documentation
1. Document table structures
2. Create mapping of parameter IDs to names
3. Build reference database of CM848 calibrations
4. Generate comparison tools

## Expected Calibration Table Names
Common naming conventions in Cummins calibrations:
- `INJ_TIMING_*`
- `DEAD_TIME_*`
- `ENERGIZING_TIME_*`
- `VOLTAGE_COMP_*`
- `RAIL_PRESS_*`
- `CYL_CORR_*` or `IQA_*`
- `PILOT_*`, `MAIN_*`, `POST_*`

## Tools from kuminz-re Repository
Based on repository structure, likely existing tools:
- `e2m-analysis/`: E2M file parsing utilities
- `e2m-db/`: Database of known calibration structures
- `kuminz-cli/`: Command-line interface for analysis
- `firmware/`: ECU firmware analysis (for understanding how tables are used)

## Next Steps
1. Examine existing e2m-analysis code in repository
2. Look for existing parsers or file format documentation
3. Collect CM848 sample files for analysis
4. Adapt or create extraction tools
5. Build visualization and comparison utilities

## References
- Cummins CalTerm documentation (if available)
- CM848 ECU technical specifications
- Common rail injection system timing theory
- Existing reverse engineering notes in firmware/docs/
