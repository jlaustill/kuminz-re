#!/usr/bin/env npx tsx

import { Client } from 'pg';

const client = new Client({
  host: 'localhost',
  port: 5432,
  database: 'e2m',
  user: 'postgres',
  password: 'postgres'
});

async function verifyParamNames() {
  try {
    await client.connect();
    console.log('✓ Connected to e2m database');
    
    // Check for param_names table
    const tableResult = await client.query(`
      SELECT table_name 
      FROM information_schema.tables 
      WHERE table_schema = 'public' AND table_name = 'param_names';
    `);
    
    if (tableResult.rows.length > 0) {
      console.log('✓ Found param_names table in e2m database!');
      
      // Check table structure
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
      
      // Check row count
      const countResult = await client.query('SELECT COUNT(*) FROM public.param_names;');
      console.log(`Row count: ${countResult.rows[0].count}`);
      
      // Show first 10 entries
      const sampleResult = await client.query('SELECT id FROM public.param_names ORDER BY id LIMIT 10;');
      console.log('First 10 parameter names:');
      sampleResult.rows.forEach((row, index) => {
        console.log(`  ${index + 1}. ${row.id}`);
      });
      
      // Check for our longest parameter name
      const longestResult = await client.query('SELECT id FROM public.param_names WHERE id = $1;', ['ZVTLMXES']);
      if (longestResult.rows.length > 0) {
        console.log('✓ Found longest parameter name (ZVTLMXES) in table');
      } else {
        console.log('✗ Longest parameter name (ZVTLMXES) not found');
      }
      
    } else {
      console.log('✗ param_names table not found');
    }
    
  } catch (error) {
    console.log('✗ Error:', error);
  } finally {
    await client.end();
  }
}

verifyParamNames();