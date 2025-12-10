#!/usr/bin/env tsx

import { readdirSync, writeFileSync } from 'fs';
import { join } from 'path';
import parseE2MFile from '../utils/e2m-parser.js';

const ORIGINALS_DIR = 'originals';
const OUTPUT_FILE = 'docs/unique_lines.e2m';

function findUniqueLines() {
  console.log('Finding lines unique to each e2m file...');
  
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
  
  // Find lines that appear in only one file
  const uniqueLines = new Map<string, string[]>();
  
  for (const [line, containingFiles] of lineToFiles) {
    if (containingFiles.length === 1) {
      const filename = containingFiles[0];
      if (!uniqueLines.has(filename)) {
        uniqueLines.set(filename, []);
      }
      uniqueLines.get(filename)!.push(line);
    }
  }
  
  let totalUnique = 0;
  const outputSections: string[] = [];
  
  // Generate output sections for each file
  for (const [filename, lines] of uniqueLines) {
    totalUnique += lines.length;
    outputSections.push(`# ${filename} (${lines.length} unique lines)`);
    outputSections.push(...lines.sort());
    outputSections.push('');
  }
  
  console.log(`Found ${totalUnique} unique lines across ${uniqueLines.size} files`);
  
  // Write results
  const output = [
    `# Lines unique to individual e2m files`,
    `# Generated: ${new Date().toISOString()}`,
    `# Total unique lines: ${totalUnique}`,
    '',
    ...outputSections
  ].join('\n');
  
  writeFileSync(OUTPUT_FILE, output);
  console.log(`Results written to ${OUTPUT_FILE}`);
}

findUniqueLines();