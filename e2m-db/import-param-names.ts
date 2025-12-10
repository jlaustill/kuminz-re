#!/usr/bin/env npx tsx

import fs from 'fs';
import path from 'path';
import { Client } from 'pg';

const DB_CONFIG = {
  host: 'localhost',
  port: 5432,
  database: 'e2m',
  user: 'postgres',
  password: 'postgres'
};

async function importParamNames(): Promise<void> {
  const filePath = path.resolve('unique_parameter_names.txt');
  
  if (!fs.existsSync(filePath)) {
    console.error(`File not found: ${filePath}`);
    process.exit(1);
  }

  const client = new Client(DB_CONFIG);
  
  try {
    await client.connect();
    console.log('Connected to PostgreSQL database');

    // Verify param_names table exists
    const tableCheck = await client.query(`
      SELECT table_name 
      FROM information_schema.tables 
      WHERE table_schema = 'public' AND table_name = 'param_names';
    `);

    if (tableCheck.rows.length === 0) {
      console.error('param_names table does not exist. Run create-param-names-table.ts first.');
      process.exit(1);
    }

    // Read the parameter names file
    const fileContent = fs.readFileSync(filePath, 'utf8');
    const paramNames = fileContent
      .split('\n')
      .map(line => line.trim())
      .filter(line => line.length > 0)
      .filter(line => /^[A-Za-z0-9_]+$/.test(line)); // Only alphanumeric and underscore

    console.log(`Found ${paramNames.length} parameter names to import`);

    // Clear existing data (optional)
    await client.query('TRUNCATE TABLE public.param_names;');
    console.log('Cleared existing data from param_names table');

    // Insert parameter names
    let insertedCount = 0;
    let skippedCount = 0;

    for (const paramName of paramNames) {
      try {
        await client.query(
          'INSERT INTO public.param_names (id) VALUES ($1)',
          [paramName]
        );
        insertedCount++;
        
        if (insertedCount % 1000 === 0) {
          console.log(`Inserted ${insertedCount} parameter names...`);
        }
      } catch (error) {
        console.warn(`Failed to insert parameter name "${paramName}":`, error);
        skippedCount++;
      }
    }

    console.log(`\n✓ Import completed:`);
    console.log(`  - Successfully inserted: ${insertedCount} parameter names`);
    console.log(`  - Skipped (errors): ${skippedCount} parameter names`);
    console.log(`  - Total processed: ${paramNames.length} parameter names`);

    // Verify final count
    const countResult = await client.query('SELECT COUNT(*) FROM public.param_names;');
    console.log(`  - Final table count: ${countResult.rows[0].count}`);

  } catch (error) {
    console.error('Error importing parameter names:', error);
    process.exit(1);
  } finally {
    await client.end();
    console.log('Database connection closed');
  }
}

importParamNames().then(() => console.log('Import completed'));