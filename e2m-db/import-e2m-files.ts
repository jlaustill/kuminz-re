#!/usr/bin/env npx tsx

import fs from 'fs';
import path from 'path';
import { Client } from 'pg';

interface E2MRow {
  full_name: string;
  engineering_unit: string;
  memory_block_address: string;
  memory_block_offset: string;
  memory_region_identifier: string;
  type: string;
  access_control: string;
  length: string;
  precision_val: string;
  signed_type: string;
  scale: string;
  minimum_value: string;
  subfile_number: string;
  group_id: string;
  unknown_column: string;
  enum_values: string;
  comment: string;
}

const DB_CONFIG = {
  host: 'localhost',
  port: 5432,
  database: 'e2m',
  user: 'postgres',
  password: 'postgres'
};

function parseE2MFile(filePath: string): E2MRow[] {
  const content = fs.readFileSync(filePath, 'utf8');
  const lines = content.split('\n').filter(line => line.trim() !== '');
  
  // Skip first 2 lines (header rows as mentioned in README)
  const dataLines = lines.slice(2);
  
  const rows: E2MRow[] = [];
  
  for (const line of dataLines) {
    if (line.trim() === '') continue;
    
    // Split on semicolon to separate data from comment
    const parts = line.split(';');
    const comment = parts.slice(1).join(';').trim();
    
    // Parse the data part (CSV format)
    const dataFields = parts[0].split(',');
    
    // Pad with empty strings if fewer than 16 columns
    while (dataFields.length < 16) {
      dataFields.push('');
    }
    
    const row: E2MRow = {
      full_name: dataFields[0] || '',
      engineering_unit: dataFields[1] || '',
      memory_block_address: dataFields[2] || '',
      memory_block_offset: dataFields[3] || '',
      memory_region_identifier: dataFields[4] || '',
      type: dataFields[5] || '',
      access_control: dataFields[6] || '',
      length: dataFields[7] || '',
      precision_val: dataFields[8] || '',
      signed_type: dataFields[9] || '',
      scale: dataFields[10] || '',
      minimum_value: dataFields[11] || '',
      subfile_number: dataFields[12] || '',
      group_id: dataFields[13] || '',
      unknown_column: dataFields[14] || '',
      enum_values: dataFields[15] || '',
      comment: comment
    };
    
    rows.push(row);
  }
  
  return rows;
}

async function createTableIfNotExists(client: Client): Promise<void> {
  const createTableQuery = `
    CREATE TABLE IF NOT EXISTS public.e2m_data (
        id SERIAL PRIMARY KEY,
        file_name VARCHAR(255) NOT NULL,
        full_name VARCHAR(255),
        engineering_unit VARCHAR(50),
        memory_block_address VARCHAR(10),
        memory_block_offset VARCHAR(10),
        memory_region_identifier VARCHAR(10),
        type VARCHAR(10),
        access_control VARCHAR(10),
        length VARCHAR(10),
        precision_val VARCHAR(10),
        signed_type VARCHAR(10),
        scale VARCHAR(20),
        minimum_value VARCHAR(20),
        subfile_number VARCHAR(10),
        group_id VARCHAR(10),
        unknown_column VARCHAR(20),
        enum_values TEXT,
        comment TEXT,
        created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
    );
    
    CREATE INDEX IF NOT EXISTS idx_e2m_data_file_name ON public.e2m_data(file_name);
    CREATE INDEX IF NOT EXISTS idx_e2m_data_full_name ON public.e2m_data(full_name);
    CREATE INDEX IF NOT EXISTS idx_e2m_data_type ON public.e2m_data(type);
  `;
  
  await client.query(createTableQuery);
}

async function importE2MFiles(): Promise<void> {
  const originalsDir = path.join(__dirname, 'originals');
  
  if (!fs.existsSync(originalsDir)) {
    console.error(`Originals directory not found: ${originalsDir}`);
    process.exit(1);
  }
  
  const client = new Client(DB_CONFIG);
  
  try {
    await client.connect();
    console.log('Connected to PostgreSQL database');
    
    // Create table if it doesn't exist
    await createTableIfNotExists(client);
    console.log('Table e2m_data ready');
    
    // Get all .e2m files
    const files = fs.readdirSync(originalsDir)
      .filter(file => file.endsWith('.e2m'))
      .sort();
    
    console.log(`Found ${files.length} e2m files to process`);
    
    let totalInserted = 0;
    
    for (const file of files) {
      console.log(`Processing ${file}...`);
      
      const filePath = path.join(originalsDir, file);
      const rows = parseE2MFile(filePath);
      
      let fileInserted = 0;
      
      for (const row of rows) {
        try {
          await client.query(`
            INSERT INTO public.e2m_data (
              file_name, full_name, engineering_unit, memory_block_address, 
              memory_block_offset, memory_region_identifier, type, access_control,
              length, precision_val, signed_type, scale, minimum_value,
              subfile_number, group_id, unknown_column, enum_values, comment
            ) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12, $13, $14, $15, $16, $17, $18)
          `, [
            file,
            row.full_name,
            row.engineering_unit,
            row.memory_block_address,
            row.memory_block_offset,
            row.memory_region_identifier,
            row.type,
            row.access_control,
            row.length,
            row.precision_val,
            row.signed_type,
            row.scale,
            row.minimum_value,
            row.subfile_number,
            row.group_id,
            row.unknown_column,
            row.enum_values,
            row.comment
          ]);
          
          fileInserted++;
          totalInserted++;
        } catch (error) {
          console.warn(`Failed to insert row from ${file}: ${row.full_name}`, error);
        }
      }
      
      console.log(`  Inserted ${fileInserted} rows from ${file}`);
    }
    
    console.log(`Successfully imported ${totalInserted} total rows from ${files.length} files`);
    
  } catch (error) {
    console.error('Error importing e2m files:', error);
    process.exit(1);
  } finally {
    await client.end();
    console.log('Database connection closed');
  }
}

if (require.main === module) {
  importE2MFiles().then(() => console.log('Import completed'));
}

export default importE2MFiles;