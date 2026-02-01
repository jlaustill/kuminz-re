# CM848 Fuel Injector Timing Analysis Guide

## Overview

This guide explains how to analyze fuel injector dead time and switch-off to End of Injection (EOI) timing in Cummins CM848 ECUs using the tools provided in the kuminz-re project.

## What We're Analyzing

### Dead Time
The delay between when the ECU commands the injector to open and when fuel actually starts flowing. This includes:
- **Electrical delay**: Solenoid energization time
- **Mechanical delay**: Needle lift time  
- **Hydraulic delay**: Pressure build-up time

Typical range: **0.3 - 1.5 milliseconds**

### Switch-Off to EOI Delay
The delay between when the ECU commands the injector to close and when fuel flow actually stops. This includes:
- **Solenoid de-energization**: Magnetic field collapse
- **Mechanical closing**: Spring return time
- **Hydraulic effects**: Pressure decay

Typical range: **0.3 - 1.0 milliseconds**

### Why This Matters

The actual fuel delivery is:
```
Actual Injection Duration = Commanded Pulse Width - Dead Time + EOI Delay
```

The ECU must compensate for both delays to achieve precise fuel metering, which directly affects:
- Fuel economy
- Power output
- Emissions
- Engine noise
- Combustion quality

## CM848 Specifics

**ECU**: Cummins CM848 (2003-2004.5)  
**Engine**: 5.9L ISB Common Rail  
**Variants**: 
- CM848B (305 HP)
- CM848C (325 HP)

**Injection System**: Bosch Common Rail (1st generation Cummins)
- Rail Pressure Range: 5,000 - 26,000 PSI
- Multiple injections per stroke: Pilot, Main, Post

## Tools Provided

### 1. cm848_injector_analyzer.py
**Purpose**: Parse E2M/ECFG calibration files and extract injector timing tables

**Usage**:
```bash
# Basic analysis - search for keywords
python3 cm848_injector_analyzer.py my_calibration.e2m --search-keywords

# Extract ASCII strings (parameter names)
python3 cm848_injector_analyzer.py my_calibration.e2m --extract-strings

# Find voltage compensation tables
python3 cm848_injector_analyzer.py my_calibration.e2m --find-voltage-tables

# Complete analysis with JSON output
python3 cm848_injector_analyzer.py my_calibration.e2m \
    --search-keywords \
    --find-voltage-tables \
    --output analysis_results.json
```

### 2. cm848_timing_visualizer.py
**Purpose**: Generate reports and ASCII plots from analysis results

**Usage**:
```bash
# Display report to terminal
python3 cm848_timing_visualizer.py analysis_results.json

# Save report to file
python3 cm848_timing_visualizer.py analysis_results.json -o timing_report.txt
```

## Step-by-Step Analysis Workflow

### Step 1: Obtain CM848 Calibration Files

You need either:
- **E2M file** (Electronic Engine Management - contains calibration tables)
- **ECFG file** (Engine Configuration - contains settings)
- Both files together for complete analysis

Sources:
- Downloaded from ECU using Cummins Insite
- Obtained from Cummins QuickServe Online (QSOL)
- Extracted using kuminz-cli tools (see repository)

### Step 2: Initial File Analysis

First, understand the file structure:

```bash
# Extract strings to identify parameter names
python3 cm848_injector_analyzer.py MY_FILE.e2m --extract-strings > strings.txt

# Review the strings for injector-related keywords
grep -i "inj\|dead\|time\|volt" strings.txt
```

### Step 3: Keyword Search

Locate injector timing data in the file:

```bash
python3 cm848_injector_analyzer.py MY_FILE.e2m \
    --search-keywords \
    --output keyword_analysis.json

# Review matches
python3 -m json.tool keyword_analysis.json | less
```

### Step 4: Extract Voltage Compensation Tables

This is the key step - finding dead time vs. voltage curves:

```bash
python3 cm848_injector_analyzer.py MY_FILE.e2m \
    --find-voltage-tables \
    --output voltage_tables.json
```

The tool will search for:
- Arrays of voltage values (10-16V range)
- Corresponding arrays of dead time values (0.3-2.0ms)
- Calculate compensation factors (ms/volt)

### Step 5: Generate Visual Report

Create a comprehensive report with plots:

```bash
python3 cm848_timing_visualizer.py voltage_tables.json \
    -o CM848_Timing_Report.txt

# View the report
cat CM848_Timing_Report.txt
```

### Step 6: Interpret Results

#### Example Output Interpretation

```
Table 1 (Offset: 0x12a40)

  Voltage (V)  |  Dead Time (ms)
  -------------------------------------
    11.00     |     1.2500
    11.50     |     1.1800
    12.00     |     1.1200
    12.50     |     1.0700
    13.00     |     1.0200
    13.50     |     0.9800  ← Nominal reference
    14.00     |     0.9400
    14.50     |     0.9100
    15.00     |     0.8800
    15.50     |     0.8600

  Statistics:
    Voltage Range: 11.00V - 15.50V
    Dead Time Range: 0.8600ms - 1.2500ms
    Compensation Factor: 0.0867 ms/V
    This means dead time changes by 86.70 µs per volt
```

**What this tells us**:

1. **At 11V (low battery)**: Dead time is 1.25ms  
   - Injector is slower to respond
   - ECU adds more pre-compensation

2. **At 13.5V (nominal)**: Dead time is 0.98ms  
   - Normal operating condition
   - Reference point for calibration

3. **At 15.5V (high battery)**: Dead time is 0.86ms  
   - Faster response
   - Less compensation needed

4. **Compensation slope**: 86.7 µs/V  
   - For every volt drop, add 86.7 µs to command duration
   - For every volt rise, subtract 86.7 µs from command duration

### Step 7: Calculate Actual Injection Timing

Use the extracted data to calculate real injection events:

#### Example: Main Injection at Cruise

**Commanded Parameters**:
- Pulse width: 2.5 ms
- Battery voltage: 13.5V
- Rail pressure: 15,000 PSI

**Dead Time** (from table): 0.98 ms  
**EOI Delay** (estimated): 0.50 ms

**Actual fuel flow**:
```
Start of Injection (SOI) = Command + 0.98ms dead time
End of Injection (EOI) = Command end + 0.50ms switch-off delay

Effective injection duration = 2.5ms (commanded)
Actual fuel delivery period = 2.5 - 0.98 + 0.50 = 2.02ms
```

#### Example: Pilot Injection

**Commanded Parameters**:
- Pulse width: 0.8 ms (very short)
- Battery voltage: 12.0V (morning cold start)
- Rail pressure: 8,000 PSI (low idle)

**Dead Time** (from table): 1.12 ms  
**EOI Delay** (estimated): 0.60 ms (slower at low pressure)

**Analysis**:
```
Commanded duration: 0.8ms
Dead time: 1.12ms  ← PROBLEM!

This pulse is TOO SHORT - the injector won't even fully open!
The pilot injection will fail or deliver minimal fuel.

Minimum pulse width must be > dead_time
Minimum viable = 1.12ms + 0.2ms margin = ~1.3ms
```

This is why short pilot injections fail at low voltage!

## Advanced Analysis

### Finding Individual Cylinder Corrections (IQA)

Look for arrays of 6 values (for 6-cylinder engine):
```bash
# Search for small integer arrays (-127 to +127 range)
# These compensate for injector-to-injector variation
```

Typical IQA values:
- Cyl 1: +3
- Cyl 2: -2
- Cyl 3: +1
- Cyl 4: -4
- Cyl 5: +2
- Cyl 6: -1

These values trim fuel delivery per cylinder to balance power output.

### Finding Multiple Injection Event Tables

CM848 supports:
- **Pilot injection**: Dead time table #1
- **Main injection**: Dead time table #2 (may be same as pilot)
- **Post injection**: Dead time table #3 (if equipped)

Each event may have independent compensation.

### Pressure Compensation

Some calibrations include rail pressure effects on dead time:
```
Dead_Time_Table[voltage][pressure]
```

Higher pressure typically means:
- Faster needle opening (pressure helps)
- Faster needle closing (pressure helps)
- Shorter dead time overall

### Temperature Compensation

Fuel temperature affects viscosity:
- Cold fuel (0°C): Thicker, slower flow, longer dead time
- Hot fuel (80°C): Thinner, faster flow, shorter dead time

Look for temperature-indexed tables or correction factors.

## Comparing Stock vs. Modified Calibrations

### Example Comparison Workflow

```bash
# Analyze stock calibration
python3 cm848_injector_analyzer.py stock.e2m \
    --find-voltage-tables --output stock_analysis.json

# Analyze modified calibration
python3 cm848_injector_analyzer.py modified.e2m \
    --find-voltage-tables --output modified_analysis.json

# Generate comparison reports
python3 cm848_timing_visualizer.py stock_analysis.json -o stock_report.txt
python3 cm848_timing_visualizer.py modified_analysis.json -o modified_report.txt

# Compare side-by-side
diff -y stock_report.txt modified_report.txt
```

### What to Look For

**Red Flags in Modified Calibrations**:
1. **Reduced dead time values** → Injector may not fully open  
2. **Eliminated voltage compensation** → Poor cold-start performance  
3. **Extreme IQA values** (>±20) → Possible injector damage or wear  
4. **Missing pilot injection timing** → Increased noise and emissions

**Performance Modifications**:
1. **Extended main injection duration** → More fuel = more power  
2. **Advanced injection timing** → Earlier combustion = more power  
3. **Eliminated post-injection** → Remove DPF regen (emissions)

## Troubleshooting

### "No voltage tables found"

**Possible causes**:
1. File is encrypted or compressed
2. File is ECFG format (configuration only, no tables)
3. Wrong file type entirely
4. Data structure is different than expected

**Solutions**:
- Try the companion E2M file if you have ECFG
- Extract strings to verify it's a calibration file
- Check file size (too small = probably not calibration data)

### "Found tables but values are out of range"

**Possible causes**:
1. False positive match
2. Values are in different units (degrees, microseconds, etc.)
3. Table is for different parameter

**Solutions**:
- Examine the hex data around the offset manually
- Try different unit conversions (µs vs ms, degrees vs ms)
- Look for nearby metadata describing units

### "Tables look correct but duplicated"

**Possible causes**:
1. Multiple tables for different injection events
2. Backup/shadow copies for redundancy
3. Different calibrations for different operating modes

**Solutions**:
- This is normal - document each table separately
- Look for context clues about which event each table controls

## Integration with kuminz-re

These tools are designed to work within the kuminz-re project structure:

```
kuminz-re/
├── e2m-analysis/
│   ├── cm848_injector_analyzer.py      ← Add here
│   ├── cm848_timing_visualizer.py      ← Add here
│   └── CM848_INJECTOR_ANALYSIS_GUIDE.md ← Add here
├── e2m-db/
│   └── cm848/
│       ├── voltage_tables/             ← Store extracted tables
│       └── timing_analysis/            ← Store analysis results
└── docs/
    └── cm848_injector_timing.md        ← Reference documentation
```

### Workflow in Repository

```bash
cd kuminz-re/e2m-analysis

# Analyze a calibration file
./cm848_injector_analyzer.py ../calibration_files/CM848B_stock.e2m \
    --find-voltage-tables \
    --output ../e2m-db/cm848/voltage_tables/CM848B_stock.json

# Generate report
./cm848_timing_visualizer.py \
    ../e2m-db/cm848/voltage_tables/CM848B_stock.json \
    -o ../e2m-db/cm848/timing_analysis/CM848B_stock_report.txt

# Commit results
git add ../e2m-db/cm848/
git commit -m "Add CM848B stock calibration timing analysis"
```

## References

- **Cummins CalTerm**: Official calibration software
- **Cummins Insite**: Diagnostic and calibration tool
- **Common Rail Technology**: Bosch technical documentation
- **kuminz-re firmware docs**: See firmware/docs/ for ECU internals

## Next Steps

1. **Acquire calibration files** for CM848 variants
2. **Run analysis** on multiple calibrations to build database
3. **Validate findings** against known CM848 behavior
4. **Document patterns** for future reverse engineering
5. **Expand tools** to handle other ECU families (CM850, CM2150, etc.)

---

For questions or contributions, see the main kuminz-re repository README.
