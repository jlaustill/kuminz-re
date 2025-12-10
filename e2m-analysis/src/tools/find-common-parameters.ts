#!/usr/bin/env tsx

import { readdirSync, writeFileSync } from 'fs';
import { join } from 'path';
import parseE2MFile from '../utils/e2m-parser.js';

const ORIGINALS_DIR = 'originals';
const OUTPUT_FILE = 'docs/common_parameters.e2m';

function findCommonParameters() {
  console.log('Finding parameters common to all e2m files (by Full Name)...');
  
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
  
  // Get all parameter names from first file
  const firstFileParams = new Set(parsedFiles[0].rows.map(row => row.fullName));
  
  // Find parameter names that exist in all files
  const commonParamNames: string[] = [];
  
  for (const paramName of firstFileParams) {
    const existsInAll = parsedFiles.every(file => 
      file.rows.some(row => row.fullName === paramName)
    );
    
    if (existsInAll) {
      commonParamNames.push(paramName);
    }
  }
  
  console.log(`Found ${commonParamNames.length} common parameters`);
  
  // For each common parameter, show the variations across files
  const outputLines = [
    `# Parameters common to all ${files.length} e2m files (by Full Name)`,
    `# Generated: ${new Date().toISOString()}`,
    `# Total common parameters: ${commonParamNames.length}`,
    `# Showing first occurrence from each file to see variations`,
    ''
  ];
  
  commonParamNames.sort().forEach(paramName => {
    outputLines.push(`# Parameter: ${paramName}`);
    
    // Show one example from each file
    parsedFiles.forEach(file => {
      const param = file.rows.find(row => row.fullName === paramName);
      if (param) {
        outputLines.push(`# ${file.filename}: ${param.rawLine}`);
      }
    });
    
    // Show the "canonical" version (from first file)
    const canonicalParam = parsedFiles[0].rows.find(row => row.fullName === paramName);
    if (canonicalParam) {
      outputLines.push(canonicalParam.rawLine);
    }
    
    outputLines.push('');
  });
  
  const output = outputLines.join('\n');
  
  writeFileSync(OUTPUT_FILE, output);
  console.log(`Results written to ${OUTPUT_FILE}`);
}

findCommonParameters();