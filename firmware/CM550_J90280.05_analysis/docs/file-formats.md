# Cummins File Format Analysis

## .enc Files (Calibration Files)

### Format Analysis: J90898.enc
- **File Type**: Password-protected ZIP archive
- **Compression**: Deflate compression method
- **Archive Size**: 408,009 bytes compressed
- **Contents**: Single file `J90898.16` (1,118,893 bytes uncompressed)
- **Protection**: Requires password for extraction

### File Structure
```
J90898.enc (ZIP Archive)
├── Header: PK (ZIP signature)
├── Compression: Deflate method
├── Encryption: Yes (password protected)
└── Contains: J90898.16 (ECM calibration data)
```

### Technical Details
- **ZIP Header**: `50 4b 03 04` (standard ZIP file signature)
- **Encryption Flag**: `14 00 01 00` indicates password protection
- **Internal File**: `.16` extension suggests 16-bit calibration format
- **Compression Ratio**: ~73% (408KB compressed from 1.1MB original)

### Relationship to Other Formats
- **NOT a simple hex-encoded E2M file** - it's a compressed/encrypted archive
- **Likely contains binary calibration data** similar to .cal files
- **May require Cummins tools** (Calterm/INSITE) to decrypt
- **Password protection** suggests proprietary/licensed content

## File Format Comparison

| Format | Extension | Type | Encryption | Tools Required |
|--------|-----------|------|------------|----------------|
| **Intel Hex** | .hex, .05 | ASCII hex | None | Standard hex tools |
| **E2M Config** | .e2m | Binary config | None | Calterm |
| **Calibration** | .cal | Binary cal data | None | Calterm |
| **Encrypted Cal** | .enc | ZIP archive | Password | Cummins tools |
| **Documentation** | .doc.txt | ASCII text | None | Text editor |

## Analysis Notes

### Why .enc Files are Protected
1. **Intellectual Property**: Contains proprietary calibration algorithms
2. **Emissions Compliance**: Prevents unauthorized modifications
3. **Licensing Control**: Restricts access to authorized dealers/technicians
4. **Quality Control**: Ensures calibrations meet specifications

### Potential Content of J90898.16
Based on size and naming convention:
- **Full ECM calibration** for specific application
- **All parameter groups** (timing, fueling, diagnostics)
- **Lookup tables** and maps
- **Error handling algorithms**
- **Possibly related to our J90280.05** (similar numbering scheme)

### Next Steps for .enc Files
1. **Research password recovery** methods for Cummins .enc files
2. **Check if related to J90280.05** firmware we're analyzing
3. **Compare with known calibration structure** if accessible
4. **Document findings** for future reference

## Security Considerations
- These files likely contain **emissions-critical calibrations**
- **Do not attempt to crack passwords** for production use
- **Respect intellectual property** and licensing restrictions
- **Use only for educational/research purposes** on your own equipment

---

*Analysis performed on J90898.enc found on Incal DVD collection*