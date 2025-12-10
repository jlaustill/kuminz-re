# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a reverse engineering project focused on analyzing e2m files used by the Cummins Calterm program in connection with CM550 ECUs. The project is purely analytical/research-based with TypeScript-only tools for data analysis.

## File Structure

- `originals/` - Contains original e2m files (CSV format with 2 header rows, up to 16 columns). **NEVER modify these files**
- `docs/` - Documentation and analysis results
  - `base_addresses.md` - Complete base address mappings with 66.1% coverage
  - `groups.md` - Parameter grouping analysis and Column 14 discovery
  - `memory_addresses.md` - Original manually confirmed memory address mappings
- `src/` - TypeScript analysis tools and utilities

## Data Format Understanding

### E2M File Format
- CSV format with 2 header rows
- Up to 16 columns (many rows have only 15)
- Each line ends with a comment after semicolon
- Column 15 always ends in "99999" (possible padding)

### Known Column Structure
1. Full Name
2. Engineering Unit
3. **Memory Block Address** (4-byte hex, 256-byte page selector)
4. **Memory Block Offset** (2-byte hex, byte offset within page)
5. **Memory Region Identifier** (determines base address via Subfile+Col5)
6. Type (x/y/z axis, n=normal, c=command, g=group)
7. **Access Control** (combines with Type to determine "Available Offline")
8. Length
9. Precision
10. Signed (U | S)
11. Scale
12. Minimum Value
13. Subfile Number
14. **Group ID** (CONFIRMED: hex value linking parameters to Type G group headers)
15. Unknown (padding ending in 99999)
16. **Enum Values** (VALUE=DESCRIPTION format for configurable parameters)

### Major Breakthroughs Achieved

1. **✅ Memory Address Formula**: `Memory Address = Base + (Column3 × 256) + Column4`
   - 15 base addresses confirmed via Calterm testing
   - 66.1% coverage (4,259/6,443 parameters)
   
2. **✅ Grouping Mechanism CONFIRMED**: Column 14 = Group ID  
   - Type G parameters define group names/headers
   - Column 14 links members to their respective groups
   - **Dual Calterm verification**: AFC (5 members) + ALT_LIM (6 members) perfect matches

### Data Analysis Methodology
1. Systematic Calterm verification of memory addresses
2. Statistical analysis of column patterns
3. Cross-reference Type G parameters with Calterm groups
4. Hypothesis testing through formula verification

## Current Research Status

### COMPLETED
1. ✅ File structure analysis (248K+ rows analyzed)
2. ✅ Memory address formula reverse-engineering
3. ✅ Base address mapping (15 confirmed mappings)
4. ✅ Parameter grouping mechanism discovery
5. ✅ Column 3, 4, 5, 7, 14, 16 purposes decoded

### REMAINING TASKS
1. Complete base address mapping (628 combinations remaining)
2. Decode Column 15 (final unknown column - likely version/padding)
3. Cross-file addressing validation

## Key Research Principles

- Manual memory address verification using Calterm lookup
- Statistical analysis of unknown columns
- Methodical hypothesis testing with small changes
- Preservation of original data integrity