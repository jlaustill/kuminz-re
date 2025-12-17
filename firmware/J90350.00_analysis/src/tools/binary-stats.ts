/**
 * Binary Statistics Tool
 *
 * Compares two CM550 ECU firmware binaries and outputs:
 * - File sizes and CRC32 checksums
 * - Entropy analysis (detect compressed/random regions)
 * - Zero/0xFF block counts (erased flash detection)
 * - Byte-level comparison statistics
 */

import * as path from 'path';
import {
  readFirmware,
  crc32,
  calculateEntropy,
  countByteBlocks,
  getByteDistribution,
  calculateSimilarity,
  formatAddress
} from '../utils/binary-reader.js';

// File paths
const J90280_PATH = path.resolve(__dirname, '../../..', 'J90280.05_analysis/firmware/J90280.05.full.bin');
const J90350_PATH = path.resolve(__dirname, '../..', 'firmware/J90350.00.rom.bin');

interface IRegionStats {
  name: string;
  start: number;
  end: number;
  entropy: number;
  similarity: number;
}

function analyzeRegion(buf1: Buffer, buf2: Buffer, start: number, end: number): IRegionStats {
  const region1 = buf1.subarray(start, end);
  const region2 = buf2.subarray(start, end);

  return {
    name: `${formatAddress(start)}-${formatAddress(end)}`,
    start,
    end,
    entropy: calculateEntropy(region2),
    similarity: calculateSimilarity(region1, region2)
  };
}

function main(): void {
  console.log('='.repeat(70));
  console.log('CM550 Firmware Binary Comparison');
  console.log('='.repeat(70));
  console.log();

  // Load firmware files
  console.log('Loading firmware files...');
  const j90280 = readFirmware(J90280_PATH);
  const j90350 = readFirmware(J90350_PATH);

  console.log();
  console.log('FILE STATISTICS');
  console.log('-'.repeat(70));
  console.log(`J90280.05: ${j90280.length.toLocaleString()} bytes (${(j90280.length / 1024).toFixed(1)} KB)`);
  console.log(`J90350.00: ${j90350.length.toLocaleString()} bytes (${(j90350.length / 1024).toFixed(1)} KB)`);
  console.log();

  // CRC32 checksums
  console.log('CRC32 CHECKSUMS');
  console.log('-'.repeat(70));
  const crc280 = crc32(j90280);
  const crc350 = crc32(j90350);
  console.log(`J90280.05: 0x${crc280.toString(16).toUpperCase().padStart(8, '0')}`);
  console.log(`J90350.00: 0x${crc350.toString(16).toUpperCase().padStart(8, '0')}`);
  console.log();

  // Entropy analysis
  console.log('ENTROPY ANALYSIS (0=uniform, 8=random)');
  console.log('-'.repeat(70));
  const entropy280 = calculateEntropy(j90280);
  const entropy350 = calculateEntropy(j90350);
  console.log(`J90280.05: ${entropy280.toFixed(4)} bits/byte`);
  console.log(`J90350.00: ${entropy350.toFixed(4)} bits/byte`);
  console.log();

  // Block analysis
  console.log('BLOCK ANALYSIS (16-byte blocks)');
  console.log('-'.repeat(70));
  const zeroBlocks280 = countByteBlocks(j90280, 0x00);
  const ffBlocks280 = countByteBlocks(j90280, 0xFF);
  const zeroBlocks350 = countByteBlocks(j90350, 0x00);
  const ffBlocks350 = countByteBlocks(j90350, 0xFF);

  console.log('J90280.05:');
  console.log(`  Zero (0x00) blocks: ${zeroBlocks280} (${(zeroBlocks280 * 16 / j90280.length * 100).toFixed(1)}%)`);
  console.log(`  Erased (0xFF) blocks: ${ffBlocks280} (${(ffBlocks280 * 16 / j90280.length * 100).toFixed(1)}%)`);
  console.log('J90350.00:');
  console.log(`  Zero (0x00) blocks: ${zeroBlocks350} (${(zeroBlocks350 * 16 / j90350.length * 100).toFixed(1)}%)`);
  console.log(`  Erased (0xFF) blocks: ${ffBlocks350} (${(ffBlocks350 * 16 / j90350.length * 100).toFixed(1)}%)`);
  console.log();

  // Byte-level comparison
  console.log('BYTE-LEVEL COMPARISON');
  console.log('-'.repeat(70));
  let identicalBytes = 0;
  let differentBytes = 0;
  for (let i = 0; i < Math.min(j90280.length, j90350.length); i++) {
    if (j90280[i] === j90350[i]) {
      identicalBytes++;
    } else {
      differentBytes++;
    }
  }
  const similarity = (identicalBytes / j90280.length * 100);
  console.log(`Identical bytes: ${identicalBytes.toLocaleString()} (${similarity.toFixed(2)}%)`);
  console.log(`Different bytes: ${differentBytes.toLocaleString()} (${(100 - similarity).toFixed(2)}%)`);
  console.log();

  // Region-by-region analysis
  console.log('REGION ANALYSIS');
  console.log('-'.repeat(70));

  const regions = [
    { name: 'Header/Boot', start: 0x0000, end: 0x0200 },
    { name: 'Early Flash', start: 0x0200, end: 0x4000 },
    { name: 'EEPROM Primary', start: 0x4000, end: 0x5A42 },
    { name: 'EEPROM Backup', start: 0x6000, end: 0x7A42 },
    { name: 'Code Region 1', start: 0xa000, end: 0x10000 },
    { name: 'Code Region 2', start: 0x10000, end: 0x20000 },
    { name: 'Code Region 3', start: 0x20000, end: 0x30000 },
    { name: 'Data/Tables', start: 0x30000, end: 0x3FFFF }
  ];

  console.log('Region                 Start      End       Entropy(350)  Similarity');
  console.log('-'.repeat(70));

  for (const region of regions) {
    const stats = analyzeRegion(j90280, j90350, region.start, Math.min(region.end, j90280.length));
    console.log(
      `${region.name.padEnd(22)} ${formatAddress(region.start).padEnd(10)} ${formatAddress(region.end).padEnd(10)} ` +
      `${stats.entropy.toFixed(3).padStart(8)}      ${stats.similarity.toFixed(1).padStart(5)}%`
    );
  }
  console.log();

  // Top byte values in each firmware
  console.log('TOP 10 MOST COMMON BYTES');
  console.log('-'.repeat(70));

  const dist280 = getByteDistribution(j90280);
  const dist350 = getByteDistribution(j90350);

  const top280 = [...dist280.entries()].sort((a, b) => b[1] - a[1]).slice(0, 10);
  const top350 = [...dist350.entries()].sort((a, b) => b[1] - a[1]).slice(0, 10);

  console.log('J90280.05:');
  for (const [byte, count] of top280) {
    console.log(`  0x${byte.toString(16).padStart(2, '0')}: ${count.toLocaleString().padStart(8)} (${(count / j90280.length * 100).toFixed(2)}%)`);
  }

  console.log('J90350.00:');
  for (const [byte, count] of top350) {
    console.log(`  0x${byte.toString(16).padStart(2, '0')}: ${count.toLocaleString().padStart(8)} (${(count / j90350.length * 100).toFixed(2)}%)`);
  }

  console.log();
  console.log('='.repeat(70));
  console.log('KEY FINDINGS:');
  console.log('-'.repeat(70));
  console.log(`1. Overall similarity at same offset: ${similarity.toFixed(1)}%`);
  console.log(`2. J90280.05 has ${ffBlocks280} erased (0xFF) blocks vs ${ffBlocks350} in J90350.00`);
  console.log(`3. J90350.00 entropy (${entropy350.toFixed(2)}) suggests ${entropy350 > 7 ? 'compressed/encrypted' : 'normal'} data`);

  if (ffBlocks280 > ffBlocks350 * 2) {
    console.log('4. J90280.05 appears to have large erased/unused regions');
  }
  if (entropy350 > 7.5) {
    console.log('4. J90350.00 has high entropy region - likely compressed data at start');
  }
  console.log('='.repeat(70));
}

main();
