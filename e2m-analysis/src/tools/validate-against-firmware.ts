#!/usr/bin/env tsx

/**
 * Firmware Validation Tool
 *
 * Validates calculated e2m addresses against known firmware memory regions
 * to ensure they fall within expected memory zones.
 */

import { Client } from 'pg';
import {
  FIRMWARE_MEMORY_REGIONS,
  getMemoryZone,
  findFirmwareRegion,
  isValidFirmwareAddress,
  analyzeAddressDistribution,
  formatAddress,
  type TMemoryZone,
  type IFirmwareMemoryRegion
} from '../utils/firmware-memory-map.js';

const DB_CONFIG = {
  host: 'localhost',
  port: 5432,
  database: 'e2m',
  user: 'postgres',
  password: 'postgres'
};

interface IParameterValidation {
  parameterName: string;
  column3: string;
  column4: string;
  calculatedAddress: number;
  hexAddress: string;
  memoryZone: TMemoryZone;
  firmwareRegion: string | null;
  isValid: boolean;
  type: string;
}

interface IValidationSummary {
  totalParameters: number;
  validAddresses: number;
  invalidAddresses: number;
  zoneDistribution: Record<TMemoryZone, number>;
  regionDistribution: Record<string, number>;
  invalidParameters: IParameterValidation[];
}

async function validateAgainstFirmware(): Promise<void> {
  const client = new Client(DB_CONFIG);
  await client.connect();

  console.log('====================================================');
  console.log('  FIRMWARE ADDRESS VALIDATION TOOL');
  console.log('====================================================\n');
  console.log('Validating e2m calculated addresses against firmware memory regions\n');

  try {
    // Step 1: Build Column3 -> Base Address lookup table
    console.log('Step 1: Building Column3 -> Base Address lookup table...');

    const column3LookupQuery = `
      SELECT
        e.memory_block_address as column3,
        MIN(('x' || p.memory_address)::bit(32)::bigint - ('x' || LPAD(e.memory_block_offset, 4, '0'))::bit(16)::int) as base_address
      FROM e2m_data e
      JOIN params p ON e.full_name = p.name_short
      WHERE e.file_name = '64t6.e2m'
        AND p.memory_address IS NOT NULL
        AND p.memory_address ~ '^[0-9A-Fa-f]+$'
      GROUP BY e.memory_block_address
    `;

    const lookupResult = await client.query(column3LookupQuery);
    const column3Lookup = new Map<string, number>();

    for (const row of lookupResult.rows) {
      column3Lookup.set(row.column3.toUpperCase(), Number(row.base_address));
    }

    console.log(`   Built lookup table with ${column3Lookup.size} Column3 entries\n`);

    // Step 2: Get ALL e2m parameters (not just those with scraped addresses)
    console.log('Step 2: Fetching all e2m parameters...');

    const allParamsQuery = `
      SELECT
        full_name,
        memory_block_address as column3,
        memory_block_offset as column4,
        type
      FROM e2m_data
      WHERE file_name = '64t6.e2m'
        AND memory_block_address IS NOT NULL
        AND memory_block_offset IS NOT NULL
      ORDER BY full_name
    `;

    const paramsResult = await client.query(allParamsQuery);
    console.log(`   Found ${paramsResult.rows.length} total e2m parameters\n`);

    // Step 3: Calculate addresses and validate against firmware regions
    console.log('Step 3: Validating addresses against firmware memory regions...\n');

    const validations: IParameterValidation[] = [];
    const summary: IValidationSummary = {
      totalParameters: 0,
      validAddresses: 0,
      invalidAddresses: 0,
      zoneDistribution: {
        Flash: 0,
        External_RAM: 0,
        EEPROM: 0,
        Internal_Registers: 0,
        CalTerm_Parameter_Storage: 0,
        Unknown: 0
      },
      regionDistribution: {},
      invalidParameters: []
    };

    for (const row of paramsResult.rows) {
      summary.totalParameters++;

      const col3 = row.column3.toUpperCase();
      const col4 = row.column4.toUpperCase();
      const type = row.type || 'N';

      // Calculate address using NEW formula
      const baseAddress = column3Lookup.get(col3);

      if (baseAddress === undefined) {
        // No base address found - skip (these would need to be derived differently)
        continue;
      }

      const col4Val = parseInt(col4, 16);
      const calculatedAddress = baseAddress + col4Val;

      // Validate against firmware
      const memoryZone = getMemoryZone(calculatedAddress);
      const firmwareRegion = findFirmwareRegion(calculatedAddress);
      const isValid = isValidFirmwareAddress(calculatedAddress);

      const validation: IParameterValidation = {
        parameterName: row.full_name,
        column3: col3,
        column4: col4,
        calculatedAddress,
        hexAddress: formatAddress(calculatedAddress),
        memoryZone,
        firmwareRegion: firmwareRegion?.name || null,
        isValid,
        type
      };

      validations.push(validation);

      // Update statistics
      if (isValid) {
        summary.validAddresses++;
      } else {
        summary.invalidAddresses++;
        summary.invalidParameters.push(validation);
      }

      summary.zoneDistribution[memoryZone]++;

      const regionName = firmwareRegion?.name || 'No_Region';
      summary.regionDistribution[regionName] =
        (summary.regionDistribution[regionName] || 0) + 1;
    }

    // Step 4: Print summary
    console.log('====================================================');
    console.log('  VALIDATION SUMMARY');
    console.log('====================================================\n');

    console.log(`Total Parameters Analyzed: ${validations.length}`);
    console.log(`Valid Addresses:           ${summary.validAddresses} (${((summary.validAddresses / validations.length) * 100).toFixed(2)}%)`);
    console.log(`Invalid/Unknown Addresses: ${summary.invalidAddresses}\n`);

    console.log('MEMORY ZONE DISTRIBUTION:');
    console.log('-------------------------');
    Object.entries(summary.zoneDistribution)
      .filter(([, count]) => count > 0)
      .sort(([, a], [, b]) => b - a)
      .forEach(([zone, count]) => {
        const percentage = ((count / validations.length) * 100).toFixed(2);
        console.log(`  ${zone.padEnd(25)}: ${count.toString().padStart(5)} (${percentage}%)`);
      });

    console.log('\nFIRMWARE REGION DISTRIBUTION:');
    console.log('-----------------------------');
    Object.entries(summary.regionDistribution)
      .sort(([, a], [, b]) => b - a)
      .slice(0, 15) // Top 15 regions
      .forEach(([region, count]) => {
        const percentage = ((count / validations.length) * 100).toFixed(2);
        console.log(`  ${region.padEnd(30)}: ${count.toString().padStart(5)} (${percentage}%)`);
      });

    // Step 5: Show invalid addresses if any
    if (summary.invalidParameters.length > 0) {
      console.log('\n====================================================');
      console.log('  INVALID/UNKNOWN ADDRESSES');
      console.log('====================================================\n');

      console.log('These parameters have addresses outside known firmware regions:\n');
      console.log('Parameter          | Address    | Zone     | Type');
      console.log('-------------------|------------|----------|-----');

      summary.invalidParameters.slice(0, 20).forEach(p => {
        console.log(
          `${p.parameterName.padEnd(18)} | ${p.hexAddress} | ${p.memoryZone.padEnd(8)} | ${p.type}`
        );
      });

      if (summary.invalidParameters.length > 20) {
        console.log(`... and ${summary.invalidParameters.length - 20} more`);
      }
    }

    // Step 6: Validate address ranges per zone
    console.log('\n====================================================');
    console.log('  ADDRESS RANGE ANALYSIS BY ZONE');
    console.log('====================================================\n');

    const zoneAddresses: Record<TMemoryZone, number[]> = {
      Flash: [],
      External_RAM: [],
      EEPROM: [],
      Internal_Registers: [],
      CalTerm_Parameter_Storage: [],
      Unknown: []
    };

    for (const v of validations) {
      zoneAddresses[v.memoryZone].push(v.calculatedAddress);
    }

    for (const [zone, addresses] of Object.entries(zoneAddresses)) {
      if (addresses.length > 0) {
        const sorted = addresses.sort((a, b) => a - b);
        const min = sorted[0];
        const max = sorted[sorted.length - 1];

        console.log(`${zone}:`);
        console.log(`  Count: ${addresses.length}`);
        console.log(`  Range: ${formatAddress(min)} - ${formatAddress(max)}`);
        console.log(`  Span:  ${(max - min).toLocaleString()} bytes\n`);
      }
    }

    // Step 7: Cross-reference with known firmware regions
    console.log('====================================================');
    console.log('  FIRMWARE REGION COVERAGE');
    console.log('====================================================\n');

    console.log('Parameters mapped to specific firmware regions:\n');
    console.log('Region                          | Count | Expected Types | Actual Types');
    console.log('--------------------------------|-------|----------------|-------------');

    for (const region of FIRMWARE_MEMORY_REGIONS) {
      const regionParams = validations.filter(v => v.firmwareRegion === region.name);
      if (regionParams.length > 0) {
        const actualTypes = [...new Set(regionParams.map(p => p.type))].sort().join(',');
        const expectedTypes = region.expectedParameterTypes.join(',') || 'Any';

        console.log(
          `${region.name.padEnd(31)} | ${regionParams.length.toString().padStart(5)} | ${expectedTypes.padEnd(14)} | ${actualTypes}`
        );
      }
    }

    // Conclusion
    console.log('\n====================================================');
    console.log('  CONCLUSION');
    console.log('====================================================\n');

    if (summary.invalidAddresses === 0) {
      console.log('All calculated addresses fall within valid firmware memory regions.');
      console.log('The e2m address mapping is consistent with the CM550 ECU memory architecture.\n');
    } else {
      console.log(`${summary.invalidAddresses} addresses fall outside known firmware regions.`);
      console.log('These may indicate:');
      console.log('  - Additional memory regions not yet documented');
      console.log('  - Mapping errors for specific parameters');
      console.log('  - Special-purpose addresses\n');
    }

  } finally {
    await client.end();
  }
}

// Run if called directly
validateAgainstFirmware().catch(console.error);

export default validateAgainstFirmware;
