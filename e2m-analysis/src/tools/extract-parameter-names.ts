import { readdirSync, writeFileSync } from 'fs';
import { join } from 'path';
import parseE2MFile from '../utils/e2m-parser.js';

const ORIGINALS_DIR = 'originals';
const OUTPUT_FILE = 'unique_parameter_names.txt';

function extractParameterNames(): void {
  const parameterNames = new Set<string>();
  
  // Read all .e2m files from originals directory
  const files = readdirSync(ORIGINALS_DIR)
    .filter(file => file.endsWith('.e2m'))
    .sort();
  
  console.log(`Found ${files.length} e2m files to process:`);
  files.forEach(file => console.log(`  - ${file}`));
  console.log();
  
  // Process each file
  for (const file of files) {
    const filePath = join(ORIGINALS_DIR, file);
    console.log(`Processing ${file}...`);
    
    try {
      const e2mFile = parseE2MFile(filePath);
      let addedCount = 0;
      
      // Extract parameter names from each row
      for (const row of e2mFile.rows) {
        if (row.fullName.trim()) {
          const sizeBefore = parameterNames.size;
          parameterNames.add(row.fullName.trim());
          if (parameterNames.size > sizeBefore) {
            addedCount++;
          }
        }
      }
      
      console.log(`  - Added ${addedCount} unique parameters (${e2mFile.rows.length} total rows)`);
      
    } catch (error) {
      console.error(`Error processing ${file}:`, error);
    }
  }
  
  // Convert to sorted array (by length first, then alphabetically)
  const uniqueNames = Array.from(parameterNames).sort((a, b) => {
    if (a.length !== b.length) {
      return a.length - b.length;
    }
    return a.localeCompare(b);
  });
  
  // Write to file
  const content = uniqueNames.join('\n') + '\n';
  writeFileSync(OUTPUT_FILE, content, 'utf-8');
  
  console.log(`\nExtraction complete!`);
  console.log(`Total unique parameter names: ${uniqueNames.length}`);
  console.log(`Output written to: ${OUTPUT_FILE}`);
}

extractParameterNames();

export default extractParameterNames;