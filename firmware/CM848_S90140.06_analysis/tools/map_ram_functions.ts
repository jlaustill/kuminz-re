#!/usr/bin/env npx tsx
/**
 * CM848 RAM Function Mapper
 *
 * Maps unnamed FUN_003fXXXX RAM functions to their ROM source addresses
 * and looks up the corresponding function names.
 *
 * Background:
 * copyCalibrationToRam() copies ROM 0x3C30-0x7F60 (17KB) to RAM 0x3F9800-0x3FDB30 at boot.
 * Functions execute from RAM for MPC555 performance (RAM faster than flash).
 *
 * Formula: ROM_addr = 0x3C30 + (RAM_addr - 0x3F9800)
 *
 * Usage:
 *   npx tsx tools/map_ram_functions.ts              # Analyze and show mappings
 *   npx tsx tools/map_ram_functions.ts --apply      # Append to function_renames.csv
 */

import { readFileSync, appendFileSync, existsSync } from "fs";
import { resolve, dirname } from "path";

// Constants for ROM-to-RAM mapping
const RAM_BASE = 0x3f9800;
const RAM_END = 0x3fdb30;
const ROM_OFFSET = 0x3c30;

// Paths relative to this script
const SCRIPT_DIR = dirname(new URL(import.meta.url).pathname);
const OUTPUT_DIR = resolve(SCRIPT_DIR, "../output");
const DECOMPILATION_FILE = resolve(OUTPUT_DIR, "cm848_rom.ghidra.cpp");
const FUNCTION_RENAMES_FILE = resolve(OUTPUT_DIR, "function_renames.csv");

interface FunctionMapping {
  ramAddr: number;
  romAddr: number;
  romName: string | null;
  suggestedRamName: string;
}

function ramToRom(ramAddr: number): number {
  return ROM_OFFSET + (ramAddr - RAM_BASE);
}

function isInRamRange(addr: number): boolean {
  return addr >= RAM_BASE && addr <= RAM_END;
}

function loadFunctionRenames(): Map<number, string> {
  const content = readFileSync(FUNCTION_RENAMES_FILE, "utf-8");
  const map = new Map<number, string>();

  for (const line of content.split("\n")) {
    // Skip comments and header
    if (line.startsWith("#") || line.startsWith("address,") || !line.trim()) {
      continue;
    }

    const [addrStr, name] = line.split(",");
    if (addrStr && name) {
      const addr = parseInt(addrStr, 16);
      map.set(addr, name.trim());
    }
  }

  return map;
}

function extractRamFunctions(decompilation: string): number[] {
  // Match FUN_003fXXXX patterns (function definitions and calls)
  const pattern = /FUN_003f([0-9a-f]{4})/gi;
  const addresses = new Set<number>();

  let match: RegExpExecArray | null;
  while ((match = pattern.exec(decompilation)) !== null) {
    const addr = parseInt("003f" + match[1], 16);
    if (isInRamRange(addr)) {
      addresses.add(addr);
    }
  }

  return Array.from(addresses).sort((a, b) => a - b);
}

function main() {
  const applyMode = process.argv.includes("--apply");

  // Verify files exist
  if (!existsSync(DECOMPILATION_FILE)) {
    console.error(`Error: Decompilation not found: ${DECOMPILATION_FILE}`);
    console.error("Run ./analyze.sh export first");
    process.exit(1);
  }

  if (!existsSync(FUNCTION_RENAMES_FILE)) {
    console.error(`Error: function_renames.csv not found: ${FUNCTION_RENAMES_FILE}`);
    process.exit(1);
  }

  console.log("CM848 RAM Function Mapper");
  console.log("=".repeat(60));
  console.log(`RAM range: 0x${RAM_BASE.toString(16)} - 0x${RAM_END.toString(16)}`);
  console.log(`Formula: ROM_addr = 0x${ROM_OFFSET.toString(16)} + (RAM_addr - 0x${RAM_BASE.toString(16)})`);
  console.log("");

  // Load existing function names
  const romFunctions = loadFunctionRenames();
  console.log(`Loaded ${romFunctions.size} function names from CSV`);

  // Check which RAM addresses are already named
  const existingRamNames = new Map<number, string>();
  for (const [addr, name] of romFunctions) {
    if (isInRamRange(addr)) {
      existingRamNames.set(addr, name);
    }
  }
  console.log(`Already named RAM functions: ${existingRamNames.size}`);

  // Extract RAM function references from decompilation
  const decompilation = readFileSync(DECOMPILATION_FILE, "utf-8");
  const ramAddresses = extractRamFunctions(decompilation);
  console.log(`Found ${ramAddresses.length} unique FUN_003fXXXX references`);
  console.log("");

  // Build mappings
  const mappings: FunctionMapping[] = [];
  const unmapped: number[] = [];

  for (const ramAddr of ramAddresses) {
    // Skip if already named in CSV
    if (existingRamNames.has(ramAddr)) {
      continue;
    }

    const romAddr = ramToRom(ramAddr);
    const romName = romFunctions.get(romAddr) ?? null;

    if (romName) {
      mappings.push({
        ramAddr,
        romAddr,
        romName,
        suggestedRamName: `${romName}_ram`,
      });
    } else {
      unmapped.push(ramAddr);
    }
  }

  // Display results
  console.log("MAPPABLE FUNCTIONS (ROM name found)");
  console.log("-".repeat(60));

  if (mappings.length === 0) {
    console.log("No new mappings found - all RAM functions already named!");
  } else {
    console.log(
      `${"RAM Address".padEnd(14)} ${"ROM Address".padEnd(14)} ${"ROM Name".padEnd(35)} Suggested RAM Name`
    );
    for (const m of mappings) {
      console.log(
        `0x${m.ramAddr.toString(16).padStart(8, "0")} 0x${m.romAddr.toString(16).padStart(8, "0")} ${m.romName!.padEnd(35)} ${m.suggestedRamName}`
      );
    }
  }

  console.log("");
  console.log("UNMAPPED FUNCTIONS (no ROM name found)");
  console.log("-".repeat(60));

  if (unmapped.length === 0) {
    console.log("All RAM functions have ROM mappings!");
  } else {
    for (const addr of unmapped) {
      const romAddr = ramToRom(addr);
      console.log(
        `0x${addr.toString(16).padStart(8, "0")} -> ROM 0x${romAddr.toString(16).padStart(8, "0")} (unnamed in ROM)`
      );
    }
  }

  // Summary
  console.log("");
  console.log("SUMMARY");
  console.log("-".repeat(60));
  console.log(`Total RAM FUN_* references: ${ramAddresses.length}`);
  console.log(`Already named:              ${existingRamNames.size}`);
  console.log(`Mappable (ROM name found):  ${mappings.length}`);
  console.log(`Unmapped (ROM also unnamed): ${unmapped.length}`);

  // Apply mode
  if (applyMode && mappings.length > 0) {
    console.log("");
    console.log("APPLYING CHANGES");
    console.log("-".repeat(60));

    const csvLines = mappings.map(
      (m) => `0x${m.ramAddr.toString(16).padStart(8, "0")},${m.suggestedRamName}`
    );

    const header = `\n# RAM copies of ROM functions (auto-generated by map_ram_functions.ts)\n# Formula: ROM_addr = 0x3C30 + (RAM_addr - 0x3F9800)\n`;
    const content = header + csvLines.join("\n") + "\n";

    appendFileSync(FUNCTION_RENAMES_FILE, content);
    console.log(`Appended ${mappings.length} entries to function_renames.csv`);
    console.log("");
    console.log("Next steps:");
    console.log("  1. cd ../ghidra && ./analyze.sh import");
    console.log("  2. ./analyze.sh export");
    console.log("  3. Verify ../output/cm848_rom.ghidra.cpp");
  } else if (!applyMode && mappings.length > 0) {
    console.log("");
    console.log("To apply these mappings, run:");
    console.log("  npx tsx tools/map_ram_functions.ts --apply");
  }
}

main();
