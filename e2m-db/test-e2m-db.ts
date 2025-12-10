#!/usr/bin/env npx tsx

import { Client } from 'pg';

const client = new Client({
  host: 'localhost',
  port: 5432,
  database: 'e2m',  // Using e2m database instead of postgres
  user: 'postgres',
  password: 'postgres'
});

async function testE2MDatabase() {
  try {
    await client.connect();
    console.log('✓ Connected to e2m database');
    
    // Check for params table
    const tableResult = await client.query(`
      SELECT table_name 
      FROM information_schema.tables 
      WHERE table_schema = 'public' AND table_name = 'params';
    `);
    
    if (tableResult.rows.length > 0) {
      console.log('✓ Found params table in e2m database!');
      
      // Check table structure
      const columnsResult = await client.query(`
        SELECT column_name, data_type 
        FROM information_schema.columns 
        WHERE table_schema = 'public' AND table_name = 'params'
        ORDER BY ordinal_position;
      `);
      console.log('Table columns:', columnsResult.rows);
      
      // Check if table has data
      const countResult = await client.query('SELECT COUNT(*) FROM public.params;');
      console.log('Current row count:', countResult.rows[0].count);
    } else {
      console.log('✗ params table still not found in e2m database');
      
      // List all tables
      const allTablesResult = await client.query(`
        SELECT table_name 
        FROM information_schema.tables 
        WHERE table_schema = 'public';
      `);
      console.log('Available tables:', allTablesResult.rows.map(row => row.table_name));
    }
    
  } catch (error) {
    console.log('✗ Failed to connect to e2m database:', error);
  } finally {
    await client.end();
  }
}

testE2MDatabase();