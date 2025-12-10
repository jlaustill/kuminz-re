#!/usr/bin/env tsx

import { readFileSync, writeFileSync } from 'fs';
import { readdirSync } from 'fs';

const ORIGINALS_DIR = 'originals';
const OUTPUT_FILE = 'docs/headers_analysis.md';

function analyzeHeaders() {
  console.log('Analyzing headers across all e2m files...');
  
  const files = readdirSync(ORIGINALS_DIR)
    .filter(file => file.endsWith('.e2m'))
    .sort();
  
  console.log(`Found ${files.length} e2m files`);
  
  const headerData = [];
  
  for (const file of files) {
    const content = readFileSync(`${ORIGINALS_DIR}/${file}`, 'utf-8');
    const lines = content.split('\n');
    
    // Get first 2 header rows (skip empty lines)
    const nonEmptyLines = lines.filter(line => line.trim());
    const header1 = nonEmptyLines[0] || '';
    const header2 = nonEmptyLines[1] || '';
    
    // Get file size and row count
    const totalLines = nonEmptyLines.length;
    const dataRows = totalLines - 2; // minus 2 header rows
    
    headerData.push({
      file,
      header1,
      header2,
      totalLines,
      dataRows,
      fileSize: content.length
    });
  }
  
  const lines = [
    '# E2M File Headers Analysis',
    '',
    `Generated: ${new Date().toISOString()}`,
    `Files analyzed: ${files.length}`,
    '',
    '## Header Row Comparison',
    '',
    '### Header Row 1 (Column Names)',
    ''
  ];
  
  // Analyze Header 1 variations
  const header1Variants = new Map<string, string[]>();
  headerData.forEach(data => {
    if (!header1Variants.has(data.header1)) {
      header1Variants.set(data.header1, []);
    }
    header1Variants.get(data.header1)!.push(data.file);
  });
  
  lines.push(`**Unique Header 1 variants**: ${header1Variants.size}`);
  lines.push('');
  
  header1Variants.forEach((files, header, index) => {
    lines.push(`#### Variant ${index + 1} (${files.length} files)`);
    lines.push('');
    lines.push('**Files**: ' + files.join(', '));
    lines.push('');
    lines.push('**Header**:');
    lines.push('```');
    lines.push(header);
    lines.push('```');
    lines.push('');
    
    // Parse columns
    const columns = header.split(',');
    lines.push(`**Column count**: ${columns.length}`);
    lines.push('');
    lines.push('**Columns**:');
    columns.forEach((col, i) => {
      lines.push(`${i + 1}. \`${col.trim()}\``);
    });
    lines.push('');
    lines.push('---');
    lines.push('');
  });
  
  // Analyze Header 2 variations
  lines.push('### Header Row 2 (Column Descriptions/Types)');
  lines.push('');
  
  const header2Variants = new Map<string, string[]>();
  headerData.forEach(data => {
    if (!header2Variants.has(data.header2)) {
      header2Variants.set(data.header2, []);
    }
    header2Variants.get(data.header2)!.push(data.file);
  });
  
  lines.push(`**Unique Header 2 variants**: ${header2Variants.size}`);
  lines.push('');
  
  header2Variants.forEach((files, header, index) => {
    lines.push(`#### Variant ${index + 1} (${files.length} files)`);
    lines.push('');
    lines.push('**Files**: ' + files.join(', '));
    lines.push('');
    lines.push('**Header**:');
    lines.push('```');
    lines.push(header);
    lines.push('```');
    lines.push('');
    
    // Parse columns
    const columns = header.split(',');
    lines.push(`**Column count**: ${columns.length}`);
    lines.push('');
    lines.push('**Columns**:');
    columns.forEach((col, i) => {
      lines.push(`${i + 1}. \`${col.trim()}\``);
    });
    lines.push('');
    lines.push('---');
    lines.push('');
  });
  
  // File statistics
  lines.push('## File Statistics');
  lines.push('');
  lines.push('| File | Size (KB) | Data Rows | Header 1 Variant | Header 2 Variant |');
  lines.push('|------|-----------|-----------|-------------------|-------------------|');
  
  headerData.forEach(data => {
    const sizeKB = (data.fileSize / 1024).toFixed(1);
    const h1Variant = Array.from(header1Variants.keys()).findIndex(h => h === data.header1) + 1;
    const h2Variant = Array.from(header2Variants.keys()).findIndex(h => h === data.header2) + 1;
    lines.push(`| ${data.file} | ${sizeKB} | ${data.dataRows} | Variant ${h1Variant} | Variant ${h2Variant} |`);
  });
  
  // Cross-analysis
  lines.push('');
  lines.push('## Cross-Analysis');
  lines.push('');
  
  // Group files by header combination
  const headerCombinations = new Map<string, string[]>();
  headerData.forEach(data => {
    const key = `H1V${Array.from(header1Variants.keys()).findIndex(h => h === data.header1) + 1}-H2V${Array.from(header2Variants.keys()).findIndex(h => h === data.header2) + 1}`;
    if (!headerCombinations.has(key)) {
      headerCombinations.set(key, []);
    }
    headerCombinations.get(key)!.push(data.file);
  });
  
  lines.push('### Header Combination Groups');
  lines.push('');
  headerCombinations.forEach((files, combo) => {
    lines.push(`**${combo}**: ${files.join(', ')}`);
  });
  
  lines.push('');
  lines.push('## Key Observations');
  lines.push('');
  
  // Generate insights
  const insights = [];
  
  if (header1Variants.size === 1) {
    insights.push('All files use identical Header 1 (column names)');
  } else {
    insights.push(`Header 1 has ${header1Variants.size} variants - indicates format evolution`);
  }
  
  if (header2Variants.size === 1) {
    insights.push('All files use identical Header 2 (column descriptions)');
  } else {
    insights.push(`Header 2 has ${header2Variants.size} variants - may indicate version differences`);
  }
  
  // Analyze file size patterns
  const avgSize = headerData.reduce((sum, d) => sum + d.fileSize, 0) / headerData.length;
  const avgRows = headerData.reduce((sum, d) => sum + d.dataRows, 0) / headerData.length;
  
  insights.push(`Average file size: ${(avgSize / 1024).toFixed(1)} KB`);
  insights.push(`Average data rows: ${avgRows.toFixed(0)}`);
  
  insights.forEach(insight => {
    lines.push(`- ${insight}`);
  });
  
  lines.push('');
  lines.push('## Implications for Column 15');
  lines.push('');
  lines.push('Header analysis may reveal:');
  lines.push('- **Format versioning**: Different header variants = different Column 15 meanings');
  lines.push('- **File evolution**: Newer files may use Column 15 differently');
  lines.push('- **ECU variants**: Different ECU types may have different Column 15 purposes');
  lines.push('- **Padding patterns**: Consistent "99999" endings may be format padding');
  
  const output = lines.join('\n');
  writeFileSync(OUTPUT_FILE, output);
  console.log(`Header analysis written to ${OUTPUT_FILE}`);
  console.log(`Found ${header1Variants.size} Header 1 variants and ${header2Variants.size} Header 2 variants`);
}

analyzeHeaders();