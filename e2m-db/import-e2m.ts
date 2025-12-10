#!/usr/bin/env npx tsx

import fs from 'fs';
import path from 'path';
import { Client } from 'pg';
import Papa, {ParseResult} from 'papaparse';

interface ParamRow {
  name: string;
  comment: string;
  type: string;
  length: string;
  unit: string;
  memory_address: string;
}

const DB_CONFIG = {
  host: 'localhost',
  port: 5432,
  database: 'e2m',  // Changed to e2m database where the params table exists
  user: 'postgres',
  password: 'postgres'
};

async function parseCSVFile(file: string): Promise<ParseResult<ParamRow>> {
    return new Promise((resolve, reject) => {
        Papa.parse(file, {
            delimiter: ',',
            quoteChar: '"',
            header: true,
            complete: function(results: ParseResult<ParamRow>): void {
                resolve(results);
            },
            error: function(err: any): void {
                reject(err);
            }
        });
    });
}

async function importCSV(filename: string): Promise<void> {
  const filePath = path.resolve(filename);
  
  if (!fs.existsSync(filePath)) {
    console.error(`File not found: ${filePath}`);
    process.exit(1);
  }

  // Extract filename without .csv extension
  const baseFilename = path.basename(filename, '.csv');

  const client = new Client(DB_CONFIG);
  
  try {
    await client.connect();
    console.log('Connected to PostgreSQL database');

    // Read and fix CSV format (header and first row are on same line)
    let csvContent: string = fs.readFileSync(filePath, 'utf8');
    
    const parseResult = await parseCSVFile(csvContent);

    if (parseResult.errors.length > 0) {
      console.warn('CSV parsing errors:', parseResult.errors);
    }

    console.log(`Parsed ${parseResult.data.length} rows from CSV`);

    // Insert data into PostgreSQL
    let insertedCount = 0;
    for (const row of parseResult.data) {
      try {
        await client.query(
          'INSERT INTO public.params (name, comment, type, length, unit, memory_address, filename) VALUES ($1, $2, $3, $4, $5, $6, $7)',
          [row.name, row.comment, row.type, row.length, row.unit, row.memory_address, baseFilename]
        );
        insertedCount++;
      } catch (error) {
        console.warn(`Failed to insert row with name "${row.name}":`, error);
      }
    }

    console.log(`Successfully imported ${insertedCount} out of ${parseResult.data.length} rows`);

  } catch (error) {
    console.error('Error importing CSV:', error);
    process.exit(1);
  } finally {
    await client.end();
    console.log('Database connection closed');
  }
}

// Get filename from command line arguments
const filename = process.argv[2];

if (!filename) {
  console.error('Usage: npx tsx import-e2m.ts <filename.csv>');
  process.exit(1);
}

importCSV(filename).then(() => console.log("Finished"));