#!/usr/bin/env npx ts-node

/**
 * Generate complete Column3 → Base Address documentation
 */

import { Client } from 'pg';

const DB_CONFIG = {
  host: 'localhost',
  port: 5432,
  database: 'e2m',
  user: 'postgres',
  password: 'postgres',
};

async function generateBaseAddressDocs(): Promise<void> {
  const client = new Client(DB_CONFIG);
  await client.connect();

  try {
    const query = `
      SELECT 
          e.memory_block_address as column3,
          MIN(('x' || p.memory_address)::bit(32)::bigint - ('x' || LPAD(e.memory_block_offset, 4, '0'))::bit(16)::int) as base_address,
          COUNT(*) as parameter_count,
          CASE 
              WHEN MIN(('x' || p.memory_address)::bit(32)::bigint) >= 8388608 AND MIN(('x' || p.memory_address)::bit(32)::bigint) <= 9437183 THEN 'External_Memory'
              WHEN MIN(('x' || p.memory_address)::bit(32)::bigint) >= 16777216 AND MIN(('x' || p.memory_address)::bit(32)::bigint) <= 16785407 THEN 'EEPROM_DataPlate'
              WHEN MIN(('x' || p.memory_address)::bit(32)::bigint) >= 393216 AND MIN(('x' || p.memory_address)::bit(32)::bigint) <= 458751 THEN 'CalTerm_Parameter_Storage'
              ELSE 'Other_Zone'
          END as memory_zone
      FROM e2m_data e
      JOIN params p ON e.full_name = p.name_short
      WHERE e.file_name = '64t6.e2m'
          AND p.memory_address IS NOT NULL
          AND p.memory_address ~ '^[0-9A-Fa-f]+$'
      GROUP BY e.memory_block_address
      ORDER BY memory_zone, base_address;
    `;

    const result = await client.query(query);
    const mappings = result.rows;

    // Group by memory zone
    const zoneGroups: { [key: string]: any[] } = {};
    mappings.forEach(row => {
      if (!zoneGroups[row.memory_zone]) {
        zoneGroups[row.memory_zone] = [];
      }
      zoneGroups[row.memory_zone].push(row);
    });

    console.log('## Complete Column3 → Base Address Lookup Table\n');
    
    Object.entries(zoneGroups).forEach(([zone, entries]) => {
      console.log(`### ${zone} (${entries.length} base addresses)\n`);
      console.log('| Column3 | Base Address | Hex Address | Parameters |');
      console.log('|---------|--------------|-------------|------------|');
      
      entries.forEach(entry => {
        const hexAddr = '0x' + entry.base_address.toString(16).toUpperCase().padStart(6, '0');
        console.log(`| ${entry.column3} | ${entry.base_address} | ${hexAddr} | ${entry.parameter_count} |`);
      });
      console.log('');
    });

    // Summary statistics
    console.log('### Summary Statistics\n');
    Object.entries(zoneGroups).forEach(([zone, entries]) => {
      const totalParams = entries.reduce((sum, entry) => sum + entry.parameter_count, 0);
      console.log(`- **${zone}**: ${entries.length} unique base addresses, ${totalParams} parameters`);
    });

  } finally {
    await client.end();
  }
}

generateBaseAddressDocs().catch(console.error);