#!/usr/bin/env tsx

import { readdirSync, writeFileSync } from 'fs';
import { join } from 'path';
import parseE2MFile from '../utils/e2m-parser.js';

const ORIGINALS_DIR = 'originals';
const OUTPUT_FILE = 'docs/differences.e2m';

function findDifferences() {
  console.log('Finding lines that differ between files...');
  
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
  
  // Create map of line -> files that contain it
  const lineToFiles = new Map<string, string[]>();
  
  parsedFiles.forEach(file => {
    file.rows.forEach(row => {
      const line = row.rawLine;
      if (!lineToFiles.has(line)) {
        lineToFiles.set(line, []);
      }
      lineToFiles.get(line)!.push(file.filename);
    });
  });
  
  // Find lines that appear in multiple files but not all files
  const differenceLines: string[] = [];
  
  for (const [line, containingFiles] of lineToFiles) {
    if (containingFiles.length > 1 && containingFiles.length < files.length) {
      differenceLines.push(line);
    }
  }
  
  // Sort by full name (first column) for easier analysis
  differenceLines.sort((a, b) => {
    const nameA = a.split(',')[0] || '';
    const nameB = b.split(',')[0] || '';
    return nameA.localeCompare(nameB);
  });
  
  console.log(`Found ${differenceLines.length} lines that differ between files`);
  
  // Write results with file occurrence info
  const outputLines = [
    `# Lines that appear in some but not all e2m files`,
    `# Generated: ${new Date().toISOString()}`,
    `# Total difference lines: ${differenceLines.length}`,
    `# Sorted by Full Name for pattern analysis`,
    ''
  ];
  
  differenceLines.forEach(line => {
    const containingFiles = lineToFiles.get(line) || [];
    outputLines.push(`# Found in: ${containingFiles.join(', ')}`);
    outputLines.push(line);
    outputLines.push('');
  });
  
  const output = outputLines.join('\n');
  
  writeFileSync(OUTPUT_FILE, output);
  console.log(`Results written to ${OUTPUT_FILE}`);
}

findDifferences();