#!/usr/bin/env tsx

import { readdirSync, writeFileSync } from 'fs';
import { join } from 'path';
import parseE2MFile from '../utils/e2m-parser.js';

const ORIGINALS_DIR = 'originals';
const OUTPUT_FILE = 'docs/common_lines.e2m';

function findCommonLines() {
  console.log('Finding lines common to all e2m files...');
  
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
  
  // Get raw lines from first file (excluding headers)
  const firstFileLines = new Set(parsedFiles[0].rows.map(row => row.rawLine));
  
  // Find lines that exist in all files
  const commonLines: string[] = [];
  
  for (const line of firstFileLines) {
    const isCommon = parsedFiles.every(file => 
      file.rows.some(row => row.rawLine === line)
    );
    
    if (isCommon) {
      commonLines.push(line);
    }
  }
  
  console.log(`Found ${commonLines.length} common lines`);
  
  // Write results
  const output = [
    `# Lines common to all ${files.length} e2m files`,
    `# Generated: ${new Date().toISOString()}`,
    '',
    ...commonLines.sort()
  ].join('\n');
  
  writeFileSync(OUTPUT_FILE, output);
  console.log(`Results written to ${OUTPUT_FILE}`);
}

findCommonLines();