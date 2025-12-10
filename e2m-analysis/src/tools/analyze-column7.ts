#!/usr/bin/env tsx

import { writeFileSync } from 'fs';
import parseE2MFile from '../utils/e2m-parser.js';

const E2M_FILES = [
  'originals/v64t6_s.e2m',
  'originals/74c0.e2m',
  'originals/v74t3_t.e2m'
];
const OUTPUT_FILE = 'docs/column7_analysis.md';

function analyzeColumn7() {
  console.log('Analyzing Column 7 patterns across files...');
  
  const allData = [];
  const col7Values = new Set<string>();
  
  // Collect data from multiple files
  for (const file of E2M_FILES) {
    const e2mFile = parseE2MFile(file);
    console.log(`Loaded ${e2mFile.rows.length} rows from ${file}`);
    
    e2mFile.rows.forEach(row => {
      if (row.column7) {
        col7Values.add(row.column7);
        allData.push({
          file: file.replace('originals/', ''),
          ...row
        });
      }
    });
  }
  
  console.log(`Found Column 7 values: ${Array.from(col7Values).sort()}`);
  
  const lines = [
    '# Column 7 Analysis',
    '',
    `Generated: ${new Date().toISOString()}`,
    `Sources: ${E2M_FILES.length} files analyzed`,
    '',
    '## 🎯 Column 7 Value Distribution',
    '',
    `**Total unique values**: ${col7Values.size}`,
    `**Values found**: ${Array.from(col7Values).sort().join(', ')}`,
    ''
  ];
  
  // Analyze each value
  const sortedValues = Array.from(col7Values).sort();
  
  for (const value of sortedValues) {
    const rowsWithValue = allData.filter(row => row.column7 === value);
    const fileDistribution = new Map<string, number>();
    const typeDistribution = new Map<string, number>();
    const subfileDistribution = new Map<string, number>();
    const groupDistribution = new Map<string, number>();
    
    rowsWithValue.forEach(row => {
      // File distribution
      fileDistribution.set(row.file, (fileDistribution.get(row.file) || 0) + 1);
      
      // Type distribution
      typeDistribution.set(row.type, (typeDistribution.get(row.type) || 0) + 1);
      
      // Subfile distribution
      subfileDistribution.set(row.subfileNumber, (subfileDistribution.get(row.subfileNumber) || 0) + 1);
      
      // Group distribution (Column 14)
      if (row.column14) {
        groupDistribution.set(row.column14, (groupDistribution.get(row.column14) || 0) + 1);
      }
    });
    
    lines.push(`### Column 7 = "${value}" (${rowsWithValue.length} parameters)`);
    lines.push('');
    
    // Convert to binary and decimal for analysis
    let binaryRep = '';
    let decimalRep = '';
    try {
      const numValue = parseInt(value, 16);
      binaryRep = numValue.toString(2).padStart(8, '0');
      decimalRep = numValue.toString();
    } catch {
      try {
        const numValue = parseInt(value, 10);
        binaryRep = numValue.toString(2).padStart(8, '0');
        decimalRep = value;
      } catch {
        binaryRep = 'N/A';
        decimalRep = 'N/A';
      }
    }
    
    lines.push(`**Representations:**`);
    lines.push(`- Hex: 0x${value}`);
    lines.push(`- Decimal: ${decimalRep}`);
    lines.push(`- Binary: ${binaryRep}`);
    lines.push('');
    
    lines.push('**Distribution by File:**');
    Array.from(fileDistribution.entries())
      .sort((a, b) => b[1] - a[1])
      .slice(0, 5)
      .forEach(([file, count]) => {
        lines.push(`- ${file}: ${count} parameters`);
      });
    lines.push('');
    
    lines.push('**Distribution by Type:**');
    Array.from(typeDistribution.entries())
      .sort((a, b) => b[1] - a[1])
      .forEach(([type, count]) => {
        lines.push(`- Type ${type}: ${count} parameters`);
      });
    lines.push('');
    
    lines.push('**Distribution by Subfile:**');
    Array.from(subfileDistribution.entries())
      .sort((a, b) => b[1] - a[1])
      .slice(0, 5)
      .forEach(([subfile, count]) => {
        lines.push(`- Subfile ${subfile}: ${count} parameters`);
      });
    lines.push('');
    
    // Show examples
    lines.push('**Example Parameters:**');
    rowsWithValue.slice(0, 5).forEach(row => {
      lines.push(`- ${row.fullName} (Type: ${row.type}, Subfile: ${row.subfileNumber}, Group: ${row.column14})`);
    });
    lines.push('');
    lines.push('---');
    lines.push('');
  }
  
  // Cross-analysis
  lines.push('## Cross-Pattern Analysis');
  lines.push('');
  
  // Check correlation with "Available Offline"
  lines.push('### Potential "Available Offline" Correlation');
  lines.push('');
  lines.push('**Hypothesis**: Column 7 might control parameter availability in offline mode');
  lines.push('');
  
  // Analyze by parameter type patterns
  const typeCol7Matrix = new Map<string, Map<string, number>>();
  allData.forEach(row => {
    if (!typeCol7Matrix.has(row.type)) {
      typeCol7Matrix.set(row.type, new Map());
    }
    const typeMap = typeCol7Matrix.get(row.type)!;
    typeMap.set(row.column7, (typeMap.get(row.column7) || 0) + 1);
  });
  
  lines.push('**Type vs Column 7 Matrix:**');
  lines.push('| Type | ' + sortedValues.join(' | ') + ' |');
  lines.push('|------|' + sortedValues.map(() => '---').join('|') + '|');
  
  for (const [type, col7Map] of typeCol7Matrix.entries()) {
    const row = [type];
    for (const value of sortedValues) {
      row.push((col7Map.get(value) || 0).toString());
    }
    lines.push(`| ${row.join(' | ')} |`);
  }
  
  lines.push('');
  lines.push('## Key Observations');
  lines.push('');
  lines.push(`1. **Limited Values**: Only ${col7Values.size} unique values across all files`);
  lines.push('2. **Most Common**: Value "37" appears to dominate');
  lines.push('3. **Pattern Analysis**: Binary representations may reveal bit flags');
  lines.push('4. **Type Correlation**: Different parameter types may use different Column 7 values');
  lines.push('5. **Next Step**: Correlate with Calterm "Available Offline" setting');
  
  const output = lines.join('\n');
  writeFileSync(OUTPUT_FILE, output);
  console.log(`Column 7 analysis written to ${OUTPUT_FILE}`);
}

analyzeColumn7();