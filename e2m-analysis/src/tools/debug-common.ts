#!/usr/bin/env tsx

import { readdirSync } from 'fs';
import { join } from 'path';
import parseE2MFile from '../utils/e2m-parser.js';

const ORIGINALS_DIR = 'originals';

function debugCommonLines() {
  console.log('Debugging common lines analysis...');
  
  const files = readdirSync(ORIGINALS_DIR)
    .filter(f => f.endsWith('.e2m'))
    .slice(0, 3) // Just first 3 files for debugging
    .map(f => join(ORIGINALS_DIR, f));
  
  console.log(`Processing ${files.length} files: ${files.map(f => f.split('/').pop()).join(', ')}`);
  
  // Parse all files
  const parsedFiles = files.map(parseE2MFile);
  
  // Get first 10 lines from each file
  console.log('\nFirst 10 lines from each file:');
  parsedFiles.forEach((file, i) => {
    console.log(`\n=== ${file.filename} ===`);
    file.rows.slice(0, 5).forEach((row, j) => {
      console.log(`${j+1}: ${row.rawLine}`);
    });
  });
  
  // Check if first line of first file appears in other files
  const firstLine = parsedFiles[0].rows[0].rawLine;
  console.log(`\nLooking for first line across files: "${firstLine}"`);
  
  parsedFiles.forEach((file, i) => {
    const found = file.rows.some(row => row.rawLine === firstLine);
    console.log(`${file.filename}: ${found ? 'FOUND' : 'NOT FOUND'}`);
    
    if (!found) {
      // Show similar lines
      const similar = file.rows.filter(row => 
        row.fullName === parsedFiles[0].rows[0].fullName
      );
      if (similar.length > 0) {
        console.log(`  But found similar by name: "${similar[0].rawLine}"`);
      }
    }
  });
}

debugCommonLines();