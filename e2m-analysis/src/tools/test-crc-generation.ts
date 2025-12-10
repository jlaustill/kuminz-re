#!/usr/bin/env tsx

import { readFileSync, writeFileSync } from 'fs';
import { writeFileSync as writeFile } from 'fs';

const SOURCE_FILE = 'originals/v64t6_s.e2m';
const TEST_DIR = 'test_files';

function testCRCGeneration() {
  console.log('Creating test files to reverse-engineer CRC algorithm...');
  
  // Create test directory
  try {
    const { mkdirSync } = require('fs');
    mkdirSync(TEST_DIR, { recursive: true });
  } catch (e) {
    // Directory might already exist
  }
  
  const content = readFileSync(SOURCE_FILE, 'utf-8');
  const lines = content.split('\n');
  
  const header1 = lines[0]; // Original CRC
  const header2 = lines[1]; // Secondary value
  const dataLines = lines.slice(2).filter(line => line.trim());
  
  console.log(`Original CRC: ${header1}`);
  console.log(`Original file has ${dataLines.length} data rows`);
  
  // Test 1: Remove last parameter
  const test1Lines = [header1, header2, ...dataLines.slice(0, -1)];
  const test1Content = test1Lines.join('\n');
  writeFile(`${TEST_DIR}/test1_remove_last.e2m`, test1Content);
  
  // Test 2: Remove first parameter  
  const test2Lines = [header1, header2, ...dataLines.slice(1)];
  const test2Content = test2Lines.join('\n');
  writeFile(`${TEST_DIR}/test2_remove_first.e2m`, test2Content);
  
  // Test 3: Duplicate first parameter
  const test3Lines = [header1, header2, dataLines[0], ...dataLines];
  const test3Content = test3Lines.join('\n');
  writeFile(`${TEST_DIR}/test3_duplicate_first.e2m`, test3Content);
  
  // Test 4: Modify Column 15 of first parameter
  const firstLine = dataLines[0];
  const parts = firstLine.split(',');
  if (parts.length >= 15) {
    parts[14] = parts[14].replace('8700199999', '8700199998'); // Change last digit
    const modifiedLine = parts.join(',');
    const test4Lines = [header1, header2, modifiedLine, ...dataLines.slice(1)];
    const test4Content = test4Lines.join('\n');
    writeFile(`${TEST_DIR}/test4_modify_col15.e2m`, test4Content);
  }
  
  // Test 5: Empty file (headers only)
  const test5Lines = [header1, header2];
  const test5Content = test5Lines.join('\n');
  writeFile(`${TEST_DIR}/test5_empty.e2m`, test5Content);
  
  // Generate testing instructions
  const instructions = [
    '# CRC Testing Instructions',
    '',
    `Generated: ${new Date().toISOString()}`,
    `Source: ${SOURCE_FILE}`,
    `Original CRC: ${header1} (hex) = ${parseInt(header1, 16)} (decimal)`,
    '',
    '## Test Files Created',
    '',
    '1. **test1_remove_last.e2m** - Removed last parameter',
    '2. **test2_remove_first.e2m** - Removed first parameter', 
    '3. **test3_duplicate_first.e2m** - Duplicated first parameter',
    '4. **test4_modify_col15.e2m** - Changed Column 15 value (8700199999 → 8700199998)',
    '5. **test5_empty.e2m** - Headers only, no data',
    '',
    '## Testing Process',
    '',
    '1. **Load each test file in Calterm**',
    '2. **Note the CRC error message or new CRC value**',
    '3. **Record which files Calterm accepts vs rejects**',
    '4. **Compare CRC changes with file modifications**',
    '',
    '## Expected Results',
    '',
    '- **test1_remove_last**: Should show different CRC (missing parameter)',
    '- **test2_remove_first**: Should show different CRC (missing parameter)',
    '- **test3_duplicate_first**: Should show different CRC (extra parameter)',
    '- **test4_modify_col15**: Should show different CRC (Column 15 is part of CRC)',
    '- **test5_empty**: Should show very different CRC (no data)',
    '',
    '## CRC Algorithm Clues',
    '',
    'Based on test results, we can determine:',
    '- **Parameter order sensitivity**: Compare test1 vs test2 CRC differences',
    '- **Column 15 influence**: Compare original vs test4',
    '- **Data inclusion**: Compare original vs test5',
    '- **Addition vs removal**: Compare test3 pattern',
    '',
    '## Next Steps',
    '',
    '1. Test all files in Calterm',
    '2. Record CRC values or error messages',
    '3. Analyze patterns to reverse-engineer algorithm',
    '4. Implement CRC generation function',
    '5. Validate with known good files'
  ];
  
  writeFile(`${TEST_DIR}/testing_instructions.md`, instructions.join('\n'));
  
  console.log(`\n✅ Created 5 test files in ${TEST_DIR}/`);
  console.log('📋 Testing instructions written to test_files/testing_instructions.md');
  console.log('\n🧪 Next step: Load test files in Calterm to observe CRC behavior');
}

testCRCGeneration();