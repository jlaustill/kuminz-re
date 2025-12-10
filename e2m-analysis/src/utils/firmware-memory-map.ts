/**
 * Firmware Memory Map Reference
 *
 * Based on reverse engineering of J90280.05 firmware for CM550 ECU (MC68336 microcontroller)
 * Source: https://github.com/jlaustill/J90280.05.analysis
 */

export interface IFirmwareMemoryRegion {
  name: string;
  startAddress: number;
  endAddress: number;
  size: number;
  description: string;
  expectedParameterTypes: string[];
}

export type TMemoryZone =
  | 'Flash'
  | 'External_RAM'
  | 'EEPROM'
  | 'Internal_Registers'
  | 'CalTerm_Parameter_Storage'
  | 'Unknown';

/**
 * CM550 ECU Memory Architecture (MC68336)
 *
 * The ECU uses a memory-mapped architecture with several distinct regions:
 * - Flash Memory: 256KB @ 0x00000000 (firmware and calibration)
 * - External RAM: 1MB @ 0x800000 (runtime data and working copies)
 * - EEPROM: 8KB @ 0x1000000 (dataplate and persistent storage)
 * - Internal Registers: 256B @ 0xFFE000 (hardware configuration)
 */

export const FIRMWARE_MEMORY_REGIONS: IFirmwareMemoryRegion[] = [
  // Flash Memory Regions
  {
    name: 'CoreFirmware',
    startAddress: 0x00000000,
    endAddress: 0x00003FFF,
    size: 16384,
    description: 'Core firmware code (16KB)',
    expectedParameterTypes: []
  },
  {
    name: 'PrimaryCalibrationBlock',
    startAddress: 0x00004000,
    endAddress: 0x00005A41,
    size: 6722,
    description: 'Primary calibration block in flash',
    expectedParameterTypes: ['N', 'S']
  },
  {
    name: 'BackupCalibrationBlock',
    startAddress: 0x00006000,
    endAddress: 0x00007A41,
    size: 6722,
    description: 'Backup calibration block in flash',
    expectedParameterTypes: ['N', 'S']
  },
  {
    name: 'PeripheralInitData',
    startAddress: 0x00028C10,
    endAddress: 0x000293FB,
    size: 652,
    description: 'Peripheral initialization data',
    expectedParameterTypes: []
  },
  {
    name: 'FirmwareParameterLookupTables',
    startAddress: 0x00037EAE,
    endAddress: 0x0003A68D,
    size: 10208,
    description: 'Firmware parameter lookup tables',
    expectedParameterTypes: ['X', 'Y', 'Z']
  },

  // External RAM Regions (0x800000 base)
  {
    name: 'CalibrationWorkingCopy',
    startAddress: 0x00804882,
    endAddress: 0x008062CF,
    size: 6734,
    description: 'Calibration working copies in RAM (copied from flash at boot)',
    expectedParameterTypes: ['N', 'S']
  },
  {
    name: 'FirmwareTablesRuntime',
    startAddress: 0x008062D2,
    endAddress: 0x00808AB1,
    size: 10208,
    description: 'Firmware tables runtime storage',
    expectedParameterTypes: ['X', 'Y', 'Z']
  },
  {
    name: 'ReferenceTables',
    startAddress: 0x008086F6,
    endAddress: 0x0080FFF0,
    size: 30970,
    description: 'Reference tables with scaling factors',
    expectedParameterTypes: ['X', 'Y', 'Z', 'N']
  },
  {
    name: 'ActiveParameterTables',
    startAddress: 0x0080CFD6,
    endAddress: 0x0080CFE6,
    size: 17,
    description: 'Active parameter tables',
    expectedParameterTypes: ['N']
  },
  {
    name: 'ExternalMemoryGeneral',
    startAddress: 0x00800000,
    endAddress: 0x008FFFFF,
    size: 1048576,
    description: 'General external memory region (1MB)',
    expectedParameterTypes: ['N', 'S', 'X', 'Y', 'Z']
  },

  // EEPROM / DataPlate Region (0x1000000 base)
  {
    name: 'EEPROM_DataPlate',
    startAddress: 0x01000000,
    endAddress: 0x01001FFF,
    size: 8192,
    description: 'EEPROM dataplate and persistent storage',
    expectedParameterTypes: ['N', 'S']
  },

  // CalTerm Parameter Storage (0x60000 base)
  {
    name: 'CalTermParameterStorage',
    startAddress: 0x00060000,
    endAddress: 0x0006FFFF,
    size: 65536,
    description: 'CalTerm parameter storage region',
    expectedParameterTypes: ['N', 'S', 'C']
  },

  // Internal Register Space
  {
    name: 'InternalRegisters',
    startAddress: 0x00FFE000,
    endAddress: 0x00FFE68B,
    size: 652,
    description: 'EBI memory controller registers',
    expectedParameterTypes: []
  },
  {
    name: 'CAN1Mailbox',
    startAddress: 0x00FFE700,
    endAddress: 0x00FFE7FE,
    size: 256,
    description: 'CAN1 mailbox configuration',
    expectedParameterTypes: []
  }
];

/**
 * Determine which memory zone an address belongs to
 */
export function getMemoryZone(address: number): TMemoryZone {
  if (address >= 0x00800000 && address <= 0x008FFFFF) {
    return 'External_RAM';
  }
  if (address >= 0x01000000 && address <= 0x01001FFF) {
    return 'EEPROM';
  }
  if (address >= 0x00060000 && address <= 0x0006FFFF) {
    return 'CalTerm_Parameter_Storage';
  }
  if (address >= 0x00000000 && address <= 0x0003FFFF) {
    return 'Flash';
  }
  if (address >= 0x00FFE000 && address <= 0x00FFE7FF) {
    return 'Internal_Registers';
  }
  return 'Unknown';
}

/**
 * Find the specific firmware region for an address
 */
export function findFirmwareRegion(address: number): IFirmwareMemoryRegion | null {
  // First check specific regions (more precise)
  const specificRegions = FIRMWARE_MEMORY_REGIONS.filter(
    r => r.name !== 'ExternalMemoryGeneral'
  );

  for (const region of specificRegions) {
    if (address >= region.startAddress && address <= region.endAddress) {
      return region;
    }
  }

  // Fall back to general external memory if in that range
  const generalRegion = FIRMWARE_MEMORY_REGIONS.find(
    r => r.name === 'ExternalMemoryGeneral'
  );

  if (
    generalRegion &&
    address >= generalRegion.startAddress &&
    address <= generalRegion.endAddress
  ) {
    return generalRegion;
  }

  return null;
}

/**
 * Validate that an address falls within expected firmware memory
 */
export function isValidFirmwareAddress(address: number): boolean {
  const zone = getMemoryZone(address);
  return zone !== 'Unknown' && zone !== 'Internal_Registers';
}

/**
 * Get memory zone statistics for a set of addresses
 */
export function analyzeAddressDistribution(
  addresses: number[]
): Record<TMemoryZone, number> {
  const distribution: Record<TMemoryZone, number> = {
    Flash: 0,
    External_RAM: 0,
    EEPROM: 0,
    Internal_Registers: 0,
    CalTerm_Parameter_Storage: 0,
    Unknown: 0
  };

  for (const addr of addresses) {
    const zone = getMemoryZone(addr);
    distribution[zone]++;
  }

  return distribution;
}

/**
 * Format an address for display
 */
export function formatAddress(address: number): string {
  return '0x' + address.toString(16).toUpperCase().padStart(8, '0');
}

export default {
  FIRMWARE_MEMORY_REGIONS,
  getMemoryZone,
  findFirmwareRegion,
  isValidFirmwareAddress,
  analyzeAddressDistribution,
  formatAddress
};
