// Binary file reading utilities for MC68000 firmware analysis
import * as fs from 'fs';
import * as path from 'path';

/**
 * Calculate CRC32 checksum of a buffer
 */
export function crc32(buffer: Buffer): number {
  let crc = 0xFFFFFFFF;
  const table = makeCrc32Table();

  for (let i = 0; i < buffer.length; i++) {
    crc = (crc >>> 8) ^ table[(crc ^ buffer[i]) & 0xFF];
  }

  return (crc ^ 0xFFFFFFFF) >>> 0;
}

function makeCrc32Table(): number[] {
  const table: number[] = [];
  for (let i = 0; i < 256; i++) {
    let c = i;
    for (let j = 0; j < 8; j++) {
      c = (c & 1) ? (0xEDB88320 ^ (c >>> 1)) : (c >>> 1);
    }
    table[i] = c >>> 0;
  }
  return table;
}

/**
 * Calculate Shannon entropy of a buffer (0-8 bits per byte)
 */
export function calculateEntropy(buffer: Buffer): number {
  if (buffer.length === 0) return 0;

  const freq = new Map<number, number>();
  for (let i = 0; i < buffer.length; i++) {
    const byte = buffer[i];
    freq.set(byte, (freq.get(byte) || 0) + 1);
  }

  let entropy = 0;
  for (const count of freq.values()) {
    const p = count / buffer.length;
    if (p > 0) {
      entropy -= p * Math.log2(p);
    }
  }

  return entropy;
}

/**
 * Count blocks of consecutive identical bytes
 */
export function countByteBlocks(buffer: Buffer, byte: number, blockSize: number = 16): number {
  let count = 0;
  for (let i = 0; i < buffer.length; i += blockSize) {
    let isBlock = true;
    for (let j = 0; j < blockSize && i + j < buffer.length; j++) {
      if (buffer[i + j] !== byte) {
        isBlock = false;
        break;
      }
    }
    if (isBlock) count++;
  }
  return count;
}

/**
 * Get byte frequency distribution
 */
export function getByteDistribution(buffer: Buffer): Map<number, number> {
  const dist = new Map<number, number>();
  for (let i = 0; i < buffer.length; i++) {
    const byte = buffer[i];
    dist.set(byte, (dist.get(byte) || 0) + 1);
  }
  return dist;
}

/**
 * Read a firmware binary file
 */
export function readFirmware(filepath: string): Buffer {
  const fullPath = path.resolve(filepath);
  if (!fs.existsSync(fullPath)) {
    throw new Error(`File not found: ${fullPath}`);
  }
  return fs.readFileSync(fullPath);
}

/**
 * Format address as hex string with 0x prefix
 */
export function formatAddress(addr: number): string {
  return '0x' + addr.toString(16).padStart(6, '0');
}

/**
 * Format a buffer as hex string for display
 */
export function formatHex(buffer: Buffer, maxLength: number = 32): string {
  const hex = buffer.subarray(0, Math.min(buffer.length, maxLength))
    .toString('hex')
    .replace(/(.{4})/g, '$1 ')
    .trim();
  return buffer.length > maxLength ? hex + '...' : hex;
}

/**
 * Find all occurrences of a pattern in a buffer
 */
export function findPattern(buffer: Buffer, pattern: Buffer): number[] {
  const matches: number[] = [];
  for (let i = 0; i <= buffer.length - pattern.length; i++) {
    let found = true;
    for (let j = 0; j < pattern.length; j++) {
      if (buffer[i + j] !== pattern[j]) {
        found = false;
        break;
      }
    }
    if (found) {
      matches.push(i);
    }
  }
  return matches;
}

/**
 * Calculate similarity between two buffers (0-100%)
 */
export function calculateSimilarity(buf1: Buffer, buf2: Buffer): number {
  const len = Math.min(buf1.length, buf2.length);
  if (len === 0) return 0;

  let matches = 0;
  for (let i = 0; i < len; i++) {
    if (buf1[i] === buf2[i]) matches++;
  }

  return (matches / len) * 100;
}

export default {
  crc32,
  calculateEntropy,
  countByteBlocks,
  getByteDistribution,
  readFirmware,
  formatAddress,
  formatHex,
  findPattern,
  calculateSimilarity
};
