import { Client } from 'pg';

const DB_CONFIG = {
  host: 'localhost',
  port: 5432,
  database: 'e2m',
  user: 'postgres',
  password: 'postgres'
};

async function exploreParamsTable(): Promise<void> {
  const client = new Client(DB_CONFIG);
  
  try {
    await client.connect();
    console.log('Connected to e2m database');
    
    // Get table structure
    console.log('\n=== PARAMS TABLE STRUCTURE ===');
    const structureQuery = `
      SELECT column_name, data_type, is_nullable, column_default 
      FROM information_schema.columns 
      WHERE table_schema = 'public' AND table_name = 'params'
      ORDER BY ordinal_position;
    `;
    const structure = await client.query(structureQuery);
    console.table(structure.rows);
    
    // Get row count
    console.log('\n=== ROW COUNT ===');
    const countResult = await client.query('SELECT COUNT(*) FROM params');
    console.log(`Total rows: ${countResult.rows[0].count}`);
    
    // Sample first 10 rows
    console.log('\n=== FIRST 10 ROWS SAMPLE ===');
    const sampleResult = await client.query('SELECT * FROM params LIMIT 10');
    console.table(sampleResult.rows);
    
    // Check for memory address related columns
    console.log('\n=== MEMORY ADDRESS ANALYSIS ===');
    const memoryQuery = `
      SELECT 
        COUNT(*) as total_params,
        COUNT(DISTINCT memory_address) as unique_addresses,
        MIN(memory_address) as min_address,
        MAX(memory_address) as max_address
      FROM params 
      WHERE memory_address IS NOT NULL
    `;
    const memoryResult = await client.query(memoryQuery);
    console.table(memoryResult.rows);
    
  } catch (error) {
    console.error('Database error:', error);
  } finally {
    await client.end();
  }
}

// Run if called directly
if (require.main === module) {
  exploreParamsTable();
}

export default exploreParamsTable;