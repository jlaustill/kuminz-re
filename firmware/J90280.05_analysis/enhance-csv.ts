#!/usr/bin/env node
/**
 * CSV Enhancement Tool for J90280.05 Analysis
 * Enhances global_variables.csv with metadata from Isbp400.csv reference data
 * Uses Papa Parse for robust CSV handling
 */

import * as fs from 'fs';
import * as path from 'path';
import * as glob from 'glob';
import Papa from 'papaparse';

interface IReferenceData {
  name: string;
  comment: string;
  length: number;
  caltermType: number;
  unit: string;
  dataPattern: string;
  source: string; // Track which file this came from
}

interface IGlobalVariable {
  address: string;
  name: string;
  type: string;
  comment: string;
}

interface IEnhancedGlobalVariable extends IGlobalVariable {
  length: number;
  calterm_type: number;
  unit: string;
  data_pattern: string;
}

class CSVEnhancer {
  private referenceData = new Map<string, IReferenceData>();
  
  /**
   * Discover and load all CSV reference files from docs directory
   */
  async loadAllReferenceFiles(docsDir: string): Promise<void> {
    const csvFiles = glob.sync('*.csv', { cwd: docsDir });
    
    if (csvFiles.length === 0) {
      console.log('⚠️  No CSV reference files found in docs directory');
      return;
    }
    
    console.log(`📁 Found ${csvFiles.length} CSV reference file(s):`);
    csvFiles.forEach(file => console.log(`   - ${file}`));
    console.log();
    
    for (const csvFile of csvFiles) {
      const filePath = path.join(docsDir, csvFile);
      await this.loadReferenceData(filePath);
    }
    
    console.log(`📊 Total reference entries loaded: ${this.referenceData.size}\n`);
  }
  
  /**
   * Load and parse a single CSV reference file
   */
  async loadReferenceData(filePath: string): Promise<void> {
    const csvContent = fs.readFileSync(filePath, 'utf-8');
    const parsed = Papa.parse<string[]>(csvContent, { 
      skipEmptyLines: true 
    });
    
    const fileName = path.basename(filePath);
    
    // Check for parsing errors
    if (parsed.errors && parsed.errors.length > 0) {
      console.log(`❌ CSV parsing errors in ${fileName}:`);
      parsed.errors.forEach(error => {
        console.log(`   Line ${error.row}: ${error.message}`);
      });
      console.log(`❌ Rejecting malformed CSV file: ${fileName}`);
      return;
    }
    
    const format = this.detectCSVFormat(parsed.data[0] || []);
    let loadedCount = 0;
    
    if (!format) {
      console.log(`⚠️  Unknown CSV format in ${fileName}, skipping...`);
      return;
    }
    
    console.log(`📖 Loading ${fileName} (${format.name} format)...`);
    
    // Skip header row
    for (let i = 1; i < parsed.data.length; i++) {
      const row = parsed.data[i];
      
      const rawAddress = row[format.addressCol]?.trim();
      if (!rawAddress) continue;
      
      const entry = this.parseRowByFormat(row, format, fileName);
      if (entry) {
        // Validate the entry has clean data
        if (this.validateEntry(entry, rawAddress, fileName)) {
          const address = this.normalizeAddress(rawAddress);
          
          // If address already exists, prefer data with more detail
          const existing = this.referenceData.get(address);
          if (!existing || entry.comment.length > existing.comment.length) {
            this.referenceData.set(address, entry);
          }
          
          loadedCount++;
        }
      }
    }
    
    console.log(`   ✓ Loaded ${loadedCount} entries`);
  }
  
  /**
   * Validate entry data integrity
   */
  private validateEntry(entry: IReferenceData, address: string, fileName: string): boolean {
    // Check for invalid values
    if (isNaN(entry.length) || entry.length < 1 || entry.length > 10000) {
      console.log(`❌ Invalid length in ${fileName} at ${address}: ${entry.length}`);
      return false;
    }
    
    if (isNaN(entry.caltermType) || entry.caltermType < 0) {
      console.log(`❌ Invalid calterm_type in ${fileName} at ${address}: ${entry.caltermType}`);
      return false;
    }
    
    // Check for valid hex address format
    if (!/^[0-9A-Fa-f]+$/.test(address.replace(/^0x/i, ''))) {
      console.log(`❌ Invalid address format in ${fileName}: ${address}`);
      return false;
    }
    
    return true;
  }
  
  /**
   * CSV format definitions for different reference file types
   */
  private readonly csvFormats = [
    {
      name: 'Isbp400',
      headers: ['name', 'comment', 'memory_address', 'length', 'type', 'unit'],
      addressCol: 2,
      nameCol: 0,
      commentCol: 1,
      lengthCol: 3,
      typeCol: 4,
      unitCol: 5
    },
    {
      name: 'CalTerm Manual Dump',
      headers: ['parameter', 'description', 'address', 'size', 'format', 'units'],
      addressCol: 2,
      nameCol: 0,
      commentCol: 1,
      lengthCol: 3,
      typeCol: 4,
      unitCol: 5
    },
    {
      name: 'Generic Parameter List',
      headers: ['address', 'name', 'description', 'length', 'type'],
      addressCol: 0,
      nameCol: 1,
      commentCol: 2,
      lengthCol: 3,
      typeCol: 4,
      unitCol: -1
    }
  ];
  
  /**
   * Detect CSV format based on header row
   */
  private detectCSVFormat(headerRow: string[]): typeof this.csvFormats[0] | null {
    if (!headerRow?.length) return null;
    
    const normalizedHeaders = headerRow.map(h => h?.toLowerCase().trim() || '');
    
    for (const format of this.csvFormats) {
      const matches = format.headers.filter(expectedHeader => 
        normalizedHeaders.some(actualHeader => 
          actualHeader.includes(expectedHeader.toLowerCase()) ||
          expectedHeader.toLowerCase().includes(actualHeader)
        )
      );
      
      // Need at least 3 key columns to match
      if (matches.length >= 3) {
        return format;
      }
    }
    
    return null;
  }
  
  /**
   * Parse a row according to detected format
   */
  private parseRowByFormat(row: string[], format: typeof this.csvFormats[0], source: string): IReferenceData | null {
    try {
      const address = row[format.addressCol]?.trim();
      if (!address) return null;
      
      const name = row[format.nameCol]?.trim().replace('ConfigFile.', '') || '';
      const comment = row[format.commentCol]?.trim() || '';
      const length = parseInt(row[format.lengthCol]?.trim()) || 2;
      const caltermType = format.typeCol >= 0 && row[format.typeCol]?.trim() ? 
                         parseInt(row[format.typeCol].trim()) : 0;
      const unit = format.unitCol >= 0 ? (row[format.unitCol]?.trim() || '') : '';
      const dataPattern = this.classifyParameter(comment, name);
      
      return {
        name,
        comment,
        length,
        caltermType,
        unit,
        dataPattern,
        source
      };
    } catch (error) {
      return null;
    }
  }
  
  /**
   * Normalize address format to uppercase hex with 0X prefix
   */
  private normalizeAddress(address: string): string {
    const addr = address.toUpperCase();
    return addr.startsWith('0X') ? addr : `0X${addr}`;
  }
  
  /**
   * Classify parameter based on comment and name patterns
   */
  private classifyParameter(comment: string, name: string): string {
    const commentUpper = comment.toUpperCase();
    const nameUpper = name.toUpperCase();
    
    if (commentUpper.includes('AXIS') || nameUpper.includes('AXIS')) {
      return 'axis';
    } else if (commentUpper.includes('LOOKUP') || commentUpper.includes('LOOK-UP') || commentUpper.includes('TABLE')) {
      return commentUpper.includes('LINEARIZATION') ? 'linearization' : 'lookup';
    } else if (commentUpper.includes('LINEARIZATION')) {
      return 'linearization';
    } else if (commentUpper.includes('FLAG') || commentUpper.includes('ENABLE')) {
      return 'flag';
    } else if (commentUpper.includes('COUNTER') || commentUpper.includes('COUNT')) {
      return 'counter';
    } else if (commentUpper.includes('THRESHOLD') || commentUpper.includes('LIMIT')) {
      return 'threshold';
    } else if (commentUpper.includes('COMMAND')) {
      return 'command';
    } else if (commentUpper.includes('ADDRESS')) {
      return 'address';
    } else if (commentUpper.includes('VALUE') || commentUpper.includes('CALCULATED')) {
      return 'value';
    }
    
    return 'data';
  }
  
  /**
   * Infer data length from existing type string
   */
  private inferLengthFromType(type: string): number {
    const typeLower = type.toLowerCase();
    
    if (typeLower.includes('byte') || typeLower.includes('uint8')) return 1;
    if (typeLower.includes('word') || typeLower.includes('uint16')) return 2;
    if (typeLower.includes('dword') || typeLower.includes('uint32')) return 4;
    if (typeLower.includes('qword') || typeLower.includes('uint64')) return 8;
    
    return 2; // Default to word
  }
  
  /**
   * Convert length to appropriate Ghidra type string
   */
  private getGhidraTypeFromLength(length: number): string {
    switch (length) {
      case 1: return 'byte';
      case 2: return 'word';
      case 4: return 'dword';
      case 8: return 'qword';
      default: 
        // For arrays or large data, create array type
        if (length > 8) {
          return `byte[${length}]`;
        }
        return 'word'; // Default
    }
  }
  
  /**
   * Enhance existing global_variables.csv with reference data AND add new entries
   */
  async enhanceCSV(inputPath: string, outputPath: string): Promise<void> {
    const csvContent = fs.readFileSync(inputPath, 'utf-8');
    const parsed = Papa.parse<IGlobalVariable>(csvContent, {
      header: true,
      skipEmptyLines: true
    });
    
    let enhancedCount = 0;
    let newEntriesCount = 0;
    const enhancedRows: IEnhancedGlobalVariable[] = [];
    const processedAddresses = new Set<string>();
    
    // First, process existing entries and enhance them
    for (const row of parsed.data) {
      if (!row.address?.trim()) continue;
      
      const address = this.normalizeAddress(row.address);
      processedAddresses.add(address);
      const ref = this.referenceData.get(address);
      
      let enhancedRow: IEnhancedGlobalVariable;
      
      if (ref) {
        // Found reference data - use it to enhance
        enhancedRow = {
          address: row.address,
          name: row.name,
          type: row.type,
          comment: ref.comment.length > row.comment.length ? ref.comment : row.comment,
          length: ref.length,
          calterm_type: ref.caltermType,
          unit: ref.unit,
          data_pattern: ref.dataPattern
        };
        enhancedCount++;
      } else {
        // No reference data - infer what we can
        enhancedRow = {
          address: row.address,
          name: row.name,
          type: row.type,
          comment: row.comment,
          length: this.inferLengthFromType(row.type),
          calterm_type: 0,
          unit: '',
          data_pattern: this.classifyParameter(row.comment, row.name)
        };
      }
      
      enhancedRows.push(enhancedRow);
    }
    
    // Second, add NEW entries from reference data that weren't in the original CSV
    for (const [address, ref] of this.referenceData) {
      if (!processedAddresses.has(address)) {
        const newRow: IEnhancedGlobalVariable = {
          address: address,
          name: ref.name || `param_${address.slice(2).toLowerCase()}`,
          type: this.getGhidraTypeFromLength(ref.length),
          comment: ref.comment,
          length: ref.length,
          calterm_type: ref.caltermType,
          unit: ref.unit,
          data_pattern: ref.dataPattern
        };
        enhancedRows.push(newRow);
        newEntriesCount++;
      }
    }
    
    // Convert back to CSV
    const csvOutput = Papa.unparse(enhancedRows, {
      header: true
    });
    
    fs.writeFileSync(outputPath, csvOutput, 'utf-8');
    
    console.log(`✓ Enhanced ${enhancedCount} existing entries with reference data`);
    console.log(`✓ Added ${newEntriesCount} NEW entries from reference files`);
    console.log(`✓ Total entries in enhanced CSV: ${enhancedRows.length}`);
    console.log(`✓ Enhanced CSV written to: ${outputPath}`);
  }
  
  /**
   * Main enhancement workflow
   */
  async run(): Promise<void> {
    const projectDir = process.cwd();
    
    const docsDir = path.join(projectDir, 'docs');
    const inputFile = path.join(projectDir, 'ghidra', 'CM550.rep', 'global_variables.csv');
    const outputFile = path.join(projectDir, 'ghidra', 'CM550.rep', 'global_variables.csv');
    
    console.log('🚀 Multi-Format CSV Enhancement Tool for J90280.05 Analysis');
    console.log('============================================================');
    
    // Validate directories exist
    if (!fs.existsSync(docsDir)) {
      throw new Error(`Docs directory not found: ${docsDir}`);
    }
    
    if (!fs.existsSync(inputFile)) {
      throw new Error(`Input CSV not found: ${inputFile}`);
    }
    
    // Load all reference data
    console.log('📖 Scanning for reference files...\n');
    await this.loadAllReferenceFiles(docsDir);
    
    // Enhance CSV
    console.log('⚡ Enhancing CSV...');
    await this.enhanceCSV(inputFile, outputFile);
    
    console.log('\n✅ Enhancement complete!');
    console.log('\n📋 Summary:');
    console.log(`   • Reference entries: ${this.referenceData.size}`);
    console.log(`   • Enhanced CSV: ${path.basename(outputFile)}`);
    console.log('\n🔄 Next steps:');
    console.log('1. Review the enhanced CSV file');
    console.log('2. Update BulkVariableCreator.java CSV path if needed');
    console.log('3. Run the enhanced Ghidra script');
    console.log('\n💡 Future reference files:');
    console.log('   Just drop new .csv files in the docs/ directory and re-run!');
  }
}

// Run if called directly
if (require.main === module) {
  const enhancer = new CSVEnhancer();
  enhancer.run().catch(error => {
    console.error('❌ Enhancement failed:', error.message);
    process.exit(1);
  });
}