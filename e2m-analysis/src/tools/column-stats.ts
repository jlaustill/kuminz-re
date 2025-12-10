#!/usr/bin/env tsx

import { readdirSync, writeFileSync } from 'fs';
import { join } from 'path';
import parseE2MFile from '../utils/e2m-parser.js';
import { IColumnStats } from '../types/index.js';

const ORIGINALS_DIR = 'originals';
const OUTPUT_FILE = 'docs/column_stats.md';

function generateColumnStats() {
  console.log('Generating column statistics for unknown columns...');
  
  const files = readdirSync(ORIGINALS_DIR)
    .filter(f => f.endsWith('.e2m'))
    .map(f => join(ORIGINALS_DIR, f));
  
  if (files.length === 0) {
    console.error('No e2m files found');
    return;
  }
  
  console.log(`Processing ${files.length} files...`);
  
  // Parse all files
  const parsedFiles = files.map(parseE2MFile);
  
  // Combine all rows
  const allRows = parsedFiles.flatMap(file => file.rows);
  
  // Unknown columns to analyze
  const unknownColumns = [
    { key: 'column3', name: 'Column 3' },
    { key: 'column4', name: 'Column 4' },  
    { key: 'column5', name: 'Column 5' },
    { key: 'column7', name: 'Column 7' },
    { key: 'column14', name: 'Column 14' },
    { key: 'column15', name: 'Column 15' },
    { key: 'column16', name: 'Column 16' }
  ];
  
  const stats: IColumnStats[] = [];
  
  for (const col of unknownColumns) {
    const values = allRows.map(row => (row as any)[col.key] || '').filter(v => v !== undefined);
    const uniqueValues = [...new Set(values)];
    const valueCount: Record<string, number> = {};
    
    values.forEach(value => {
      valueCount[value] = (valueCount[value] || 0) + 1;
    });
    
    const emptyCount = values.filter(v => v === '').length;
    const lengths = values.filter(v => v !== '').map(v => v.length);
    
    // Handle large datasets without stack overflow
    let minLength = 0;
    let maxLength = 0;
    if (lengths.length > 0) {
      minLength = lengths.reduce((min, len) => len < min ? len : min, lengths[0]);
      maxLength = lengths.reduce((max, len) => len > max ? len : max, lengths[0]);
    }
    
    stats.push({
      column: col.name,
      uniqueValues: uniqueValues.sort(),
      valueCount,
      minLength,
      maxLength,
      emptyCount,
      totalCount: values.length
    });
  }
  
  // Generate markdown output
  const output = generateMarkdownReport(stats, allRows.length);
  
  writeFileSync(OUTPUT_FILE, output);
  console.log(`Column statistics written to ${OUTPUT_FILE}`);
}

function generateMarkdownReport(stats: IColumnStats[], totalRows: number): string {
  const lines = [
    '# E2M Column Statistics',
    '',
    `Generated: ${new Date().toISOString()}`,
    `Total rows analyzed: ${totalRows}`,
    '',
    '## Summary',
    ''
  ];
  
  // Summary table
  lines.push('| Column | Unique Values | Empty Count | Min Length | Max Length |');
  lines.push('|--------|---------------|-------------|------------|------------|');
  
  stats.forEach(stat => {
    lines.push(`| ${stat.column} | ${stat.uniqueValues.length} | ${stat.emptyCount} | ${stat.minLength} | ${stat.maxLength} |`);
  });
  
  lines.push('');
  
  // Detailed analysis for each column
  stats.forEach(stat => {
    lines.push(`## ${stat.column}`);
    lines.push('');
    lines.push(`- Total values: ${stat.totalCount}`);
    lines.push(`- Unique values: ${stat.uniqueValues.length}`);
    lines.push(`- Empty values: ${stat.emptyCount}`);
    lines.push(`- Non-empty values: ${stat.totalCount - stat.emptyCount}`);
    lines.push(`- Length range: ${stat.minLength} - ${stat.maxLength}`);
    lines.push('');
    
    // Top 20 most frequent values
    const sortedValues = Object.entries(stat.valueCount)
      .sort(([,a], [,b]) => b - a)
      .slice(0, 20);
    
    if (sortedValues.length > 0) {
      lines.push('### Most Frequent Values');
      lines.push('');
      lines.push('| Value | Count | Percentage |');
      lines.push('|-------|-------|-----------|');
      
      sortedValues.forEach(([value, count]) => {
        const percentage = ((count / stat.totalCount) * 100).toFixed(2);
        const displayValue = value === '' ? '(empty)' : value;
        lines.push(`| ${displayValue} | ${count} | ${percentage}% |`);
      });
      
      lines.push('');
    }
    
    // All unique values if reasonable number
    if (stat.uniqueValues.length <= 50) {
      lines.push('### All Unique Values');
      lines.push('');
      lines.push('```');
      stat.uniqueValues.forEach(value => {
        lines.push(value === '' ? '(empty)' : value);
      });
      lines.push('```');
      lines.push('');
    }
  });
  
  return lines.join('\n');
}

generateColumnStats();