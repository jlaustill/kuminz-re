// Manual decompilation of FUN_000356f8 based on assembly analysis
// Address: 0x000356f8
// Function: coreTableInterpolation

// Based on assembly pattern and usage throughout codebase
uint coreTableInterpolation(void* table_descriptor, ushort input_value) {
    // Assembly shows this function:
    // 1. Takes table descriptor pointer (contains table metadata)
    // 2. Takes input value for interpolation
    // 3. Performs linear interpolation between table points
    // 4. Returns interpolated result
    
    // From assembly analysis:
    // - Accesses table through pointer indirection
    // - Checks if table size is 0 (returns input value directly)
    // - Performs multiplication-based interpolation
    // - Uses scaling factors and offsets
    // - Returns 32-bit result with proper scaling
    
    // The exact implementation would need to be reconstructed from
    // the MC68K assembly, but the function signature and purpose are clear
    // from usage patterns throughout the engine management system.
    
    // This function is the core table lookup engine used for:
    // - Fuel maps
    // - Timing maps  
    // - Protection thresholds
    // - RPM calculations
    // - All calibration table interpolations
    
    return 0; // Placeholder - actual implementation in assembly
}

// Notes for Ghidra troubleshooting:
// - Function likely failed due to complex MC68K pointer arithmetic
// - May need manual function signature definition in Ghidra
// - Consider defining custom data types for table descriptors
// - Assembly shows clear interpolation algorithm but Ghidra parser struggled