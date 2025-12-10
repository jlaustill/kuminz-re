#!/usr/bin/env npx tsx

import { Client } from 'pg';

const DB_CONFIG = {
  host: 'localhost',
  port: 5432,
  database: 'e2m',
  user: 'postgres',
  password: 'postgres'
};

async function createParamNamesTable(): Promise<void> {
  const client = new Client(DB_CONFIG);
  
  try {
    await client.connect();
    console.log('Connected to PostgreSQL database');

    // Create the param_names table
    const createTableQuery = `
      CREATE TABLE IF NOT EXISTS public.param_names (
        id VARCHAR(8) PRIMARY KEY
      );
    `;

    await client.query(createTableQuery);
    console.log('✓ Created param_names table successfully');

    // Check if table was created
    const tableCheck = await client.query(`
      SELECT table_name 
      FROM information_schema.tables 
      WHERE table_schema = 'public' AND table_name = 'param_names';
    `);

    if (tableCheck.rows.length > 0) {
      console.log('✓ Table param_names verified in database');
      
      // Show table structure
      const columnsResult = await client.query(`
        SELECT column_name, data_type, character_maximum_length, is_nullable
        FROM information_schema.columns 
        WHERE table_schema = 'public' AND table_name = 'param_names'
        ORDER BY ordinal_position;
      `);
      console.log('Table structure:');
      columnsResult.rows.forEach(row => {
        console.log(`  - ${row.column_name}: ${row.data_type}(${row.character_maximum_length}) ${row.is_nullable === 'NO' ? 'NOT NULL' : ''}`);
      });
    }

  } catch (error) {
    console.error('Error creating table:', error);
    process.exit(1);
  } finally {
    await client.end();
    console.log('Database connection closed');
  }
}

createParamNamesTable().then(() => console.log('Table creation completed'));