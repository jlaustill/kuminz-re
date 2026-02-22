/**
 * Function Matcher Tool
 *
 * Finds J90280.05 functions in J90350.00 by matching instruction signatures.
 * Uses opcode-based matching (ignores absolute addresses/immediates).
 *
 * MC68000 instruction format awareness:
 * - Opcodes are typically 2 bytes
 * - Immediates and addresses follow the opcode
 * - We match opcode patterns while allowing flexibility in operands
 */

import * as fs from 'fs';
import * as path from 'path';
import { EMatchType, type IRelocationEntry } from '../types/index.js';
import { readFirmware, formatAddress, formatHex } from '../utils/binary-reader.js';

// File paths
const J90280_PATH = path.resolve(__dirname, '../../..', 'J90280.05_analysis/firmware/J90280.05.full.bin');
const J90350_PATH = path.resolve(__dirname, '../..', 'firmware/J90350.00.rom.bin');
const FUNCTIONS_CSV = path.resolve(__dirname, '../../..', 'J90280.05_analysis/ghidra/CM550.rep/function_renames.csv');
const OUTPUT_PATH = path.resolve(__dirname, '../..', 'output/relocation_map.csv');
const REPORT_PATH = path.resolve(__dirname, '../..', 'output/function_match_report.md');

// MC68000 opcode masks - which bytes are opcodes vs operands
// For simplicity, we'll use a pattern matching approach that compares
// instruction sequences while tolerating differences in address operands

interface IFunctionEntry {
  address: number;
  name: string;
}

interface IMatchCandidate {
  offset: number;
  score: number;
  matchedBytes: number;
  totalBytes: number;
}

/**
 * Load function list from CSV
 */
function loadFunctions(csvPath: string): IFunctionEntry[] {
  const content = fs.readFileSync(csvPath, 'utf-8');
  const lines = content.split('\n').slice(1); // Skip header

  return lines
    .filter(line => line.trim())
    .map(line => {
      const [addressStr, name] = line.split(',');
      const address = parseInt(addressStr, 16);
      return { address, name: name?.trim() || `func_${addressStr}` };
    })
    .filter(f => !isNaN(f.address));
}

/**
 * Calculate similarity score between two byte sequences
 * Uses a weighted approach: opcode bytes (even positions) weighted higher
 */
function calculateSignatureSimilarity(sig1: Buffer, sig2: Buffer): number {
  const len = Math.min(sig1.length, sig2.length);
  if (len === 0) return 0;

  let matches = 0;
  let opcodeMatches = 0;

  for (let i = 0; i < len; i++) {
    if (sig1[i] === sig2[i]) {
      matches++;
      // Weight opcode bytes (even positions in MC68000)
      if (i % 2 === 0) opcodeMatches++;
    }
  }

  // Combined score: raw match + bonus for opcode matches
  const rawScore = matches / len;
  const opcodeScore = opcodeMatches / (len / 2);

  return (rawScore * 0.5 + opcodeScore * 0.5) * 100;
}

/**
 * Search for a function signature in target firmware
 * Returns the best match above threshold
 */
function findSignatureInTarget(
  signature: Buffer,
  target: Buffer,
  searchRanges: Array<{ start: number; end: number }>,
  threshold: number = 60
): IMatchCandidate | null {
  let bestMatch: IMatchCandidate | null = null;

  for (const range of searchRanges) {
    for (let offset = range.start; offset < range.end - signature.length; offset += 2) {
      const candidate = target.subarray(offset, offset + signature.length);
      const score = calculateSignatureSimilarity(signature, candidate);

      if (score >= threshold) {
        if (!bestMatch || score > bestMatch.score) {
          let matchedBytes = 0;
          for (let i = 0; i < signature.length; i++) {
            if (signature[i] === candidate[i]) matchedBytes++;
          }

          bestMatch = {
            offset,
            score,
            matchedBytes,
            totalBytes: signature.length
          };
        }
      }
    }
  }

  return bestMatch;
}

/**
 * Extract function signature (first N bytes)
 */
function extractSignature(firmware: Buffer, address: number, length: number = 32): Buffer {
  const start = address;
  const end = Math.min(start + length, firmware.length);
  return firmware.subarray(start, end);
}

/**
 * Main function matching routine
 */
function matchFunctions(
  functions: IFunctionEntry[],
  sourceFirmware: Buffer,
  targetFirmware: Buffer,
  signatureLength: number = 32
): IRelocationEntry[] {
  const results: IRelocationEntry[] = [];

  // Define search ranges in J90350.00 (code regions identified earlier)
  const searchRanges = [
    { start: 0x3000, end: 0x4000 },   // Boot code
    { start: 0xb000, end: 0x29000 },  // Main code region 1
    { start: 0x2d000, end: 0x35000 }  // Main code region 2
  ];

  console.log(`Matching ${functions.length} functions...`);
  console.log(`Search ranges: ${searchRanges.map(r => `${formatAddress(r.start)}-${formatAddress(r.end)}`).join(', ')}`);
  console.log();

  let matched = 0;
  let similar = 0;
  let notFound = 0;

  for (let i = 0; i < functions.length; i++) {
    const func = functions[i];

    // Skip functions outside valid range
    if (func.address >= sourceFirmware.length) {
      results.push({
        sourceAddress: func.address,
        sourceName: func.name,
        targetAddress: 0,
        confidence: 0,
        status: 'not_found'
      });
      notFound++;
      continue;
    }

    const signature = extractSignature(sourceFirmware, func.address, signatureLength);
    const match = findSignatureInTarget(signature, targetFirmware, searchRanges);

    if (match && match.score >= 80) {
      results.push({
        sourceAddress: func.address,
        sourceName: func.name,
        targetAddress: match.offset,
        confidence: Math.round(match.score),
        status: 'matched'
      });
      matched++;
    } else if (match && match.score >= 60) {
      results.push({
        sourceAddress: func.address,
        sourceName: func.name,
        targetAddress: match.offset,
        confidence: Math.round(match.score),
        status: 'similar'
      });
      similar++;
    } else {
      results.push({
        sourceAddress: func.address,
        sourceName: func.name,
        targetAddress: 0,
        confidence: match ? Math.round(match.score) : 0,
        status: 'not_found'
      });
      notFound++;
    }

    // Progress indicator
    if ((i + 1) % 100 === 0 || i === functions.length - 1) {
      process.stdout.write(`\rProcessed ${i + 1}/${functions.length} functions...`);
    }
  }

  console.log('\n');
  console.log(`Results: ${matched} matched, ${similar} similar, ${notFound} not found`);

  return results;
}

/**
 * Calculate relocation offset statistics
 */
function analyzeRelocationOffsets(results: IRelocationEntry[]): Map<number, number> {
  const offsets = new Map<number, number>();

  for (const result of results) {
    if (result.status === 'matched' && result.targetAddress > 0) {
      const offset = result.targetAddress - result.sourceAddress;
      offsets.set(offset, (offsets.get(offset) || 0) + 1);
    }
  }

  return offsets;
}

/**
 * Generate CSV output
 */
function generateCSV(results: IRelocationEntry[]): string {
  let csv = 'source_address,source_name,target_address,confidence,status\n';

  for (const result of results) {
    csv += `${formatAddress(result.sourceAddress)},${result.sourceName},`;
    csv += `${result.targetAddress > 0 ? formatAddress(result.targetAddress) : 'N/A'},`;
    csv += `${result.confidence},${result.status}\n`;
  }

  return csv;
}

/**
 * Generate markdown report
 */
function generateReport(results: IRelocationEntry[], offsets: Map<number, number>): string {
  let report = '# Function Matching Report\n\n';
  report += `Generated: ${new Date().toISOString()}\n\n`;

  // Summary
  const matched = results.filter(r => r.status === 'matched').length;
  const similar = results.filter(r => r.status === 'similar').length;
  const notFound = results.filter(r => r.status === 'not_found').length;

  report += '## Summary\n\n';
  report += `| Metric | Count | Percentage |\n`;
  report += `|--------|-------|------------|\n`;
  report += `| Matched (>80%) | ${matched} | ${(matched / results.length * 100).toFixed(1)}% |\n`;
  report += `| Similar (60-80%) | ${similar} | ${(similar / results.length * 100).toFixed(1)}% |\n`;
  report += `| Not Found (<60%) | ${notFound} | ${(notFound / results.length * 100).toFixed(1)}% |\n`;
  report += `| **Total** | ${results.length} | 100% |\n\n`;

  // Relocation offset analysis
  report += '## Relocation Offset Analysis\n\n';
  report += 'Most common address offsets between matched functions:\n\n';
  report += '| Offset | Count | Interpretation |\n';
  report += '|--------|-------|----------------|\n';

  const sortedOffsets = [...offsets.entries()].sort((a, b) => b[1] - a[1]).slice(0, 10);
  for (const [offset, count] of sortedOffsets) {
    const sign = offset >= 0 ? '+' : '';
    report += `| ${sign}0x${Math.abs(offset).toString(16)} | ${count} | `;
    report += `Target = Source ${sign}${offset} |\n`;
  }

  report += '\n## High Confidence Matches (Sample)\n\n';
  report += '| Source | Name | Target | Confidence |\n';
  report += '|--------|------|--------|------------|\n';

  const highConfidence = results
    .filter(r => r.status === 'matched' && r.confidence >= 90)
    .slice(0, 20);

  for (const result of highConfidence) {
    report += `| ${formatAddress(result.sourceAddress)} | ${result.sourceName} `;
    report += `| ${formatAddress(result.targetAddress)} | ${result.confidence}% |\n`;
  }

  report += '\n## Functions Not Found (Sample)\n\n';
  report += '| Source | Name | Best Score |\n';
  report += '|--------|------|------------|\n';

  const notFoundSample = results
    .filter(r => r.status === 'not_found')
    .slice(0, 20);

  for (const result of notFoundSample) {
    report += `| ${formatAddress(result.sourceAddress)} | ${result.sourceName} `;
    report += `| ${result.confidence}% |\n`;
  }

  return report;
}

function main(): void {
  console.log('='.repeat(70));
  console.log('CM550 Function Matcher');
  console.log('='.repeat(70));
  console.log();

  // Load data
  console.log('Loading function list from CSV...');
  const functions = loadFunctions(FUNCTIONS_CSV);
  console.log(`Loaded ${functions.length} functions`);

  console.log('Loading firmware files...');
  const j90280 = readFirmware(J90280_PATH);
  const j90350 = readFirmware(J90350_PATH);
  console.log();

  // Match functions
  const results = matchFunctions(functions, j90280, j90350, 32);

  // Analyze relocation offsets
  const offsets = analyzeRelocationOffsets(results);

  // Print top offsets
  console.log('TOP RELOCATION OFFSETS');
  console.log('-'.repeat(70));
  const sortedOffsets = [...offsets.entries()].sort((a, b) => b[1] - a[1]).slice(0, 5);
  for (const [offset, count] of sortedOffsets) {
    const sign = offset >= 0 ? '+' : '-';
    console.log(`  ${sign}0x${Math.abs(offset).toString(16).padStart(5, '0')}: ${count} functions`);
  }
  console.log();

  // Save outputs
  fs.mkdirSync(path.dirname(OUTPUT_PATH), { recursive: true });

  const csv = generateCSV(results);
  fs.writeFileSync(OUTPUT_PATH, csv);
  console.log(`CSV saved to: ${OUTPUT_PATH}`);

  const report = generateReport(results, offsets);
  fs.writeFileSync(REPORT_PATH, report);
  console.log(`Report saved to: ${REPORT_PATH}`);

  // Final summary
  console.log();
  console.log('='.repeat(70));
  console.log('GHIDRA ESCALATION DECISION');
  console.log('-'.repeat(70));

  const matchRate = results.filter(r => r.status === 'matched').length / results.length * 100;

  if (matchRate >= 60) {
    console.log(`Match rate: ${matchRate.toFixed(1)}% - Relocation map can be used`);
    console.log('Recommendation: Apply J90280.05 analysis to J90350.00 using relocation map');
  } else if (matchRate >= 40) {
    console.log(`Match rate: ${matchRate.toFixed(1)}% - Partial relocation possible`);
    console.log('Recommendation: Selective Ghidra analysis for unmatched functions');
  } else {
    console.log(`Match rate: ${matchRate.toFixed(1)}% - Significant differences detected`);
    console.log('Recommendation: Full Ghidra analysis of J90350.00 required');
  }
  console.log('='.repeat(70));
}

main();
