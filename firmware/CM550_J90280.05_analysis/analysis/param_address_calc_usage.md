# param_address_calc (0x12afa) Usage Analysis

## Function Call Sites Found

**4 call sites** found for `param_address_calc`:

| Address | Calling Function | Context |
|---------|------------------|---------|
| 0xd618  | 0xd5xx (TBD)    | Complex calculation with Block×256+Offset |
| 0xd682  | 0xd632         | Parameter lookup with limit checking |
| 0xd700  | 0xd69c         | Parameter access with validation |  
| 0xd7a6  | 0xd756         | Parameter retrieval function |

## Calling Pattern Analysis

### Common Pattern in ALL callers:
```assembly
# 1. Calculate complex parameter index
e188    lsll #8,%d0        ; Multiply by 256 (Block calculation)
e588    lsll #2,%d0        ; Multiply by 4 (likely for data type size)
2400    movel %d0,%d2      ; Store calculated index

# 2. Call param_address_calc  
3f03    movew %d3,%sp@-    ; Push offset parameter
2f02    movel %d2,%sp@-    ; Push calculated block index
4eb9 0001 2afa jsr 0x12afa ; Call param_address_calc(block, offset)
5c8f    addql #6,%sp      ; Clean up stack (6 bytes = 4+2)

# 3. Store and validate result
3480    movew %d0,%a2@     ; Store parameter value
0c52 7d00 cmpiw #32000,%a2@ ; Check if value > 32000 (limit check)
6304    blss next          ; Branch if within limits  
34bc 7d00 movew #32000,%a2@ ; Cap at 32000 if too high
```

## Key Insights

### 1. **Parameter Value Capping**
All callers implement **safety limiting** at `32000` (0x7D00). This suggests:
- These are **sensor values** or **control parameters** with defined limits
- The ECU implements **fail-safe parameter bounds**
- Values outside safe range get capped rather than causing faults

### 2. **Consistent Call Convention**
- **Stack-based parameters**: `param_address_calc(calculated_block, offset)`
- **Return value**: Parameter value (16-bit) in `%d0`
- **Always followed by validation**: Limit checking after every call

### 3. **Block Calculation Pattern**
The `lsll #8, lsll #2` pattern suggests:
- `Block × 256 × 4 = Block × 1024` 
- Could be indexing into **1KB parameter blocks**
- Or addressing **32-bit parameters** (4 bytes each)

## Function Entry Points

### 1. Function 0xd632: Parameter Lookup Function
```assembly
d632: moveml %d2-%d3/%a2-%a3,%sp@-  ; Entry point
d636: moveal #0x80cfd6,%a2          ; Load parameter table address
d63c: moveal #0x8086f6,%a3          ; Load reference table  
...calls param_address_calc...
```

### 2. Function 0xd69c: Parameter Access Function  
```assembly
d69c: moveml %d2-%d3/%a2-%a4,%sp@-  ; Entry point
d6a0: moveal #0x80cfda,%a2          ; Different parameter table
...calls param_address_calc...
```

### 3. Function 0xd756: Parameter Retrieval Function
```assembly
d756: moveml %d2-%d3/%a2-%a3,%sp@-  ; Entry point  
d75a: moveal #0x80cfde,%a2          ; Another parameter table
...calls param_address_calc...
```

## Memory Addresses Referenced

The calling functions reference specific memory tables:
- `0x80cfd6` - Parameter table 1
- `0x80cfda` - Parameter table 2  
- `0x80cfde` - Parameter table 3
- `0x8086f6` - Reference/lookup table

These addresses are in the **0x800000+** range we identified earlier as **memory controller space**!

## Next Steps

1. **Examine the parameter tables** at 0x80CFD6, 0x80CFDA, 0x80CFDE
2. **Analyze the reference table** at 0x8086F6  
3. **Find what calls these wrapper functions** to understand the parameter access hierarchy
4. **Map the complete parameter access chain** from high-level requests down to EEPROM reads

## Conclusion

We've found **the complete parameter access system**:
- `param_address_calc` (0x12afa): Core address translation 
- 3 wrapper functions (0xd632, 0xd69c, 0xd756): Parameter lookup with validation
- Memory tables in 0x800000+ space: Parameter definitions and limits

This is **the EEPROM parameter access infrastructure** we've been looking for!