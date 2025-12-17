/**
 * Region Identification Tool
 *
 * Analyzes firmware binaries to identify different memory regions:
 * - Compressed data (high entropy)
 * - Executable code (MC68000 instruction patterns)
 * - Calibration data (EEPROM content)
 * - Erased flash (0xFF blocks)
 * - Data tables (low entropy structured data)
 */

import * as fs from 'fs';
import * as path from 'path';
import { ERegionType, type IFirmwareRegion } from '../types/index.js';
import {
  readFirmware,
  calculateEntropy,
  formatAddress
} from '../utils/binary-reader.js';

// File paths
const J90280_PATH = path.resolve(__dirname, '../../..', 'J90280.05_analysis/firmware/J90280.05.full.bin');
const J90350_PATH = path.resolve(__dirname, '../..', 'firmware/J90350.00.rom.bin');
const OUTPUT_PATH = path.resolve(__dirname, '../..', 'output/region_map.md');

// MC68000 common opcodes (big-endian)
const MC68000_PATTERNS = {
  RTS: Buffer.from([0x4E, 0x75]),      // Return from subroutine
  JSR_ABS: Buffer.from([0x4E, 0xB9]),  // JSR absolute long
  JMP_ABS: Buffer.from([0x4E, 0xF9]),  // JMP absolute long
  MOVEM_PUSH: Buffer.from([0x48, 0xE7]), // MOVEM.L regs,-(SP)
  MOVEM_POP: Buffer.from([0x4C, 0xDF]),  // MOVEM.L (SP)+,regs
  MOVE_W_IMM: Buffer.from([0x33, 0xFC]), // MOVE.W #imm,addr
  MOVE_B_IMM: Buffer.from([0x13, 0xFC]), // MOVE.B #imm,addr
  CLR_W: Buffer.from([0x42, 0x79]),      // CLR.W addr
  NOP: Buffer.from([0x4E, 0x71])         // NOP
};

/**
 * Count MC68000 instruction patterns in a buffer
 */
function countInstructionPatterns(buffer: Buffer): number {
  let count = 0;
  for (const pattern of Object.values(MC68000_PATTERNS)) {
    for (let i = 0; i < buffer.length - pattern.length; i++) {
      let match = true;
      for (let j = 0; j < pattern.length; j++) {
        if (buffer[i + j] !== pattern[j]) {
          match = false;
          break;
        }
      }
      if (match) count++;
    }
  }
  return count;
}

/**
 * Check if a region is mostly erased (0xFF)
 */
function isErasedRegion(buffer: Buffer): boolean {
  let ffCount = 0;
  for (let i = 0; i < buffer.length; i++) {
    if (buffer[i] === 0xFF) ffCount++;
  }
  return ffCount / buffer.length > 0.95;
}

/**
 * Check if a region is mostly zeros
 */
function isZeroRegion(buffer: Buffer): boolean {
  let zeroCount = 0;
  for (let i = 0; i < buffer.length; i++) {
    if (buffer[i] === 0x00) zeroCount++;
  }
  return zeroCount / buffer.length > 0.9;
}

/**
 * Classify a memory region based on content analysis
 */
function classifyRegion(buffer: Buffer): { type: ERegionType; confidence: number; description: string } {
  const entropy = calculateEntropy(buffer);
  const instructionCount = countInstructionPatterns(buffer);
  const instructionDensity = instructionCount / (buffer.length / 1024); // per KB

  // Check for erased flash
  if (isErasedRegion(buffer)) {
    return {
      type: ERegionType.ERASED,
      confidence: 99,
      description: 'Erased flash (0xFF)'
    };
  }

  // Check for compressed data (high entropy)
  if (entropy > 7.5) {
    return {
      type: ERegionType.COMPRESSED,
      confidence: Math.min(95, (entropy - 7) * 30),
      description: `High entropy (${entropy.toFixed(2)}) - likely compressed/encrypted`
    };
  }

  // Check for executable code (moderate entropy + instruction patterns)
  if (entropy > 4.5 && entropy < 7.0 && instructionDensity > 5) {
    return {
      type: ERegionType.CODE,
      confidence: Math.min(90, instructionDensity * 2),
      description: `Executable code (${instructionCount} instructions detected)`
    };
  }

  // Check for calibration/data (lower entropy, structured)
  if (entropy < 4.5 && !isZeroRegion(buffer)) {
    return {
      type: ERegionType.CALIBRATION,
      confidence: 70,
      description: `Structured data/calibration (entropy ${entropy.toFixed(2)})`
    };
  }

  // Check for data tables
  if (entropy > 2.0 && entropy < 5.0) {
    return {
      type: ERegionType.DATA,
      confidence: 60,
      description: `Data tables (entropy ${entropy.toFixed(2)})`
    };
  }

  return {
    type: ERegionType.UNKNOWN,
    confidence: 30,
    description: `Unknown region (entropy ${entropy.toFixed(2)})`
  };
}

/**
 * Analyze firmware and identify regions
 */
function identifyRegions(firmware: Buffer, blockSize: number = 4096): IFirmwareRegion[] {
  const regions: IFirmwareRegion[] = [];
  let currentRegion: IFirmwareRegion | null = null;

  for (let offset = 0; offset < firmware.length; offset += blockSize) {
    const end = Math.min(offset + blockSize, firmware.length);
    const block = firmware.subarray(offset, end);
    const classification = classifyRegion(block);
    const entropy = calculateEntropy(block);

    // Check if we should start a new region or extend current
    if (!currentRegion || currentRegion.regionType !== classification.type) {
      // Save previous region
      if (currentRegion) {
        regions.push(currentRegion);
      }

      // Start new region
      currentRegion = {
        name: `${classification.type}_${formatAddress(offset)}`,
        startAddress: offset,
        endAddress: end,
        regionType: classification.type,
        description: classification.description,
        entropy: entropy
      };
    } else {
      // Extend current region
      currentRegion.endAddress = end;
      // Update entropy to average
      currentRegion.entropy = (currentRegion.entropy! + entropy) / 2;
    }
  }

  // Don't forget the last region
  if (currentRegion) {
    regions.push(currentRegion);
  }

  return regions;
}

/**
 * Generate markdown report
 */
function generateReport(
  j90280Regions: IFirmwareRegion[],
  j90350Regions: IFirmwareRegion[]
): string {
  let report = '# Firmware Region Analysis\n\n';
  report += `Generated: ${new Date().toISOString()}\n\n`;

  report += '## J90280.05 (Reference Firmware)\n\n';
  report += '| Start | End | Size | Type | Entropy | Description |\n';
  report += '|-------|-----|------|------|---------|-------------|\n';

  for (const region of j90280Regions) {
    const size = region.endAddress - region.startAddress;
    report += `| ${formatAddress(region.startAddress)} | ${formatAddress(region.endAddress)} `;
    report += `| ${(size / 1024).toFixed(1)}KB | ${region.regionType} `;
    report += `| ${region.entropy?.toFixed(2) || 'N/A'} | ${region.description} |\n`;
  }

  report += '\n## J90350.00 (Extracted Firmware)\n\n';
  report += '| Start | End | Size | Type | Entropy | Description |\n';
  report += '|-------|-----|------|------|---------|-------------|\n';

  for (const region of j90350Regions) {
    const size = region.endAddress - region.startAddress;
    report += `| ${formatAddress(region.startAddress)} | ${formatAddress(region.endAddress)} `;
    report += `| ${(size / 1024).toFixed(1)}KB | ${region.regionType} `;
    report += `| ${region.entropy?.toFixed(2) || 'N/A'} | ${region.description} |\n`;
  }

  // Summary
  report += '\n## Summary\n\n';

  const j90280Code = j90280Regions.filter(r => r.regionType === ERegionType.CODE);
  const j90350Code = j90350Regions.filter(r => r.regionType === ERegionType.CODE);
  const j90280Compressed = j90280Regions.filter(r => r.regionType === ERegionType.COMPRESSED);
  const j90350Compressed = j90350Regions.filter(r => r.regionType === ERegionType.COMPRESSED);

  report += '### J90280.05\n';
  report += `- Code regions: ${j90280Code.length} (${j90280Code.reduce((sum, r) => sum + r.endAddress - r.startAddress, 0) / 1024}KB)\n`;
  report += `- Compressed regions: ${j90280Compressed.length}\n`;

  report += '\n### J90350.00\n';
  report += `- Code regions: ${j90350Code.length} (${j90350Code.reduce((sum, r) => sum + r.endAddress - r.startAddress, 0) / 1024}KB)\n`;
  report += `- Compressed regions: ${j90350Compressed.length}\n`;

  report += '\n## Key Observations\n\n';
  report += '1. **Memory Layout Difference**: The two firmwares have different memory organizations\n';
  report += '2. **Code Relocation**: Functions are at different addresses between firmwares\n';
  report += '3. **Compressed Data**: J90350.00 contains compressed data in early memory regions\n';

  return report;
}

function main(): void {
  console.log('='.repeat(70));
  console.log('CM550 Firmware Region Identification');
  console.log('='.repeat(70));
  console.log();

  // Load firmware files
  console.log('Loading firmware files...');
  const j90280 = readFirmware(J90280_PATH);
  const j90350 = readFirmware(J90350_PATH);
  console.log();

  // Identify regions
  console.log('Analyzing J90280.05...');
  const j90280Regions = identifyRegions(j90280);
  console.log(`Found ${j90280Regions.length} distinct regions`);

  console.log('Analyzing J90350.00...');
  const j90350Regions = identifyRegions(j90350);
  console.log(`Found ${j90350Regions.length} distinct regions`);
  console.log();

  // Print results
  console.log('J90280.05 REGIONS');
  console.log('-'.repeat(70));
  console.log('Start      End        Size    Type         Entropy  Description');
  console.log('-'.repeat(70));

  for (const region of j90280Regions) {
    const size = region.endAddress - region.startAddress;
    console.log(
      `${formatAddress(region.startAddress).padEnd(10)} ` +
      `${formatAddress(region.endAddress).padEnd(10)} ` +
      `${(size / 1024).toFixed(1).padStart(5)}KB  ` +
      `${region.regionType.padEnd(12)} ` +
      `${(region.entropy?.toFixed(2) || 'N/A').padStart(6)}  ` +
      `${region.description}`
    );
  }

  console.log();
  console.log('J90350.00 REGIONS');
  console.log('-'.repeat(70));
  console.log('Start      End        Size    Type         Entropy  Description');
  console.log('-'.repeat(70));

  for (const region of j90350Regions) {
    const size = region.endAddress - region.startAddress;
    console.log(
      `${formatAddress(region.startAddress).padEnd(10)} ` +
      `${formatAddress(region.endAddress).padEnd(10)} ` +
      `${(size / 1024).toFixed(1).padStart(5)}KB  ` +
      `${region.regionType.padEnd(12)} ` +
      `${(region.entropy?.toFixed(2) || 'N/A').padStart(6)}  ` +
      `${region.description}`
    );
  }

  // Generate and save report
  const report = generateReport(j90280Regions, j90350Regions);
  fs.mkdirSync(path.dirname(OUTPUT_PATH), { recursive: true });
  fs.writeFileSync(OUTPUT_PATH, report);
  console.log();
  console.log(`Report saved to: ${OUTPUT_PATH}`);
}

main();
