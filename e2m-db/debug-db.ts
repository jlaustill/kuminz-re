#!/usr/bin/env npx tsx

import { Client } from 'pg';

const configs = [
  {
    name: 'postgres database',
    config: {
      host: 'localhost',
      port: 5432,
      database: 'postgres',
      user: 'postgres',
      password: 'postgres'
    }
  },
  {
    name: 'default database connection',
    config: {
      host: 'localhost',
      port: 5432,
      user: 'postgres',
      password: 'postgres'
    }
  }
];

async function testConnection(configName: string, config: any) {
  const client = new Client(config);
  
  try {
    await client.connect();
    console.log(`✓ Connected to ${configName}`);
    
    // List databases
    const dbResult = await client.query('SELECT datname FROM pg_database WHERE datistemplate = false;');
    console.log('Available databases:', dbResult.rows.map(row => row.datname));
    
    // Check for params table
    try {
      const tableResult = await client.query(`
        SELECT table_name 
        FROM information_schema.tables 
        WHERE table_schema = 'public' AND table_name = 'params';
      `);
      
      if (tableResult.rows.length > 0) {
        console.log('✓ Found params table in public schema');
        
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
        console.log('Row count:', countResult.rows[0].count);
      } else {
        console.log('✗ params table not found');
        
        // List all tables in public schema
        const allTablesResult = await client.query(`
          SELECT table_name 
          FROM information_schema.tables 
          WHERE table_schema = 'public';
        `);
        console.log('Available tables in public schema:', allTablesResult.rows.map(row => row.table_name));
      }
    } catch (error) {
      console.log('Error checking table:', error);
    }
    
  } catch (error) {
    console.log(`✗ Failed to connect to ${configName}:`, error);
  } finally {
    await client.end();
  }
}

async function main() {
  for (const { name, config } of configs) {
    console.log(`\n--- Testing ${name} ---`);
    await testConnection(name, config);
  }
}

main();