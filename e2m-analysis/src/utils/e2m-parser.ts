import { readFileSync } from 'fs';
import { IE2MFile, IE2MRow, TE2MType } from '../types/index.js';

export function parseE2MFile(filePath: string): IE2MFile {
  const content = readFileSync(filePath, 'utf-8');
  const lines = content.split('\n').filter(line => line.trim());
  
  if (lines.length < 3) {
    throw new Error(`Invalid e2m file format: ${filePath}`);
  }
  
  const filename = filePath.split('/').pop() || '';
  const header1 = lines[0];
  const header2 = lines[1];
  const dataLines = lines.slice(2);
  
  const rows: IE2MRow[] = dataLines.map(line => parseE2MRow(line));
  
  return {
    filename,
    header1,
    header2,
    rows
  };
}

function parseE2MRow(line: string): IE2MRow {
  // Split by semicolon to separate data from comment
  const [datapart, comment = ''] = line.split(';');
  const columns = datapart.split(',');
  
  // Pad with empty strings if less than 16 columns
  while (columns.length < 16) {
    columns.push('');
  }
  
  return {
    fullName: columns[0] || '',
    engineeringUnit: columns[1] || '',
    column3: columns[2] || '',
    column4: columns[3] || '',
    column5: columns[4] || '',
    type: (columns[5] || '') as TE2MType,
    column7: columns[6] || '',
    length: columns[7] || '',
    precision: columns[8] || '',
    signed: (columns[9] === 'S' ? 'S' : 'U'),
    scale: columns[10] || '',
    minimumValue: columns[11] || '',
    subfileNumber: columns[12] || '',
    column14: columns[13] || '',
    column15: columns[14] || '',
    column16: columns[15] || undefined,
    comment: comment.trim(),
    rawLine: line
  };
}

export default parseE2MFile;