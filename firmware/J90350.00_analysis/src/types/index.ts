// Type definitions for CM550 firmware comparison
// Following CLAUDE.md conventions: I=Interface, E=Enum, T=Type

export enum ERegionType {
  CODE = 'code',
  DATA = 'data',
  CALIBRATION = 'calibration',
  COMPRESSED = 'compressed',
  ERASED = 'erased',
  UNKNOWN = 'unknown'
}

export enum EMatchType {
  EXACT = 'exact',
  SIMILAR = 'similar',
  RELOCATED = 'relocated',
  NOT_FOUND = 'not_found'
}

export interface IFirmwareRegion {
  name: string;
  startAddress: number;
  endAddress: number;
  regionType: ERegionType;
  description: string;
  entropy?: number;
}

export interface IBinaryStats {
  filename: string;
  size: number;
  crc32: number;
  entropy: number;
  zeroBlockCount: number;
  ffBlockCount: number;
  byteDistribution: Map<number, number>;
}

export interface IFunctionSignature {
  address: number;
  name: string;
  prologueBytes: Buffer;
  size: number;
  callSites: number[];
}

export interface IMatchResult {
  sourceAddress: number;
  sourceName: string;
  targetAddress: number | null;
  confidence: number;
  matchType: EMatchType;
  instructionDiff: number;
}

export interface IBlockComparison {
  offset1: number;
  offset2: number;
  size: number;
  similarity: number;
  matchType: 'identical' | 'similar' | 'different';
}

export interface IComparisonReport {
  totalFunctions: number;
  matchedFunctions: number;
  similarFunctions: number;
  notFoundFunctions: number;
  overallSimilarity: number;
  codeRegionSimilarity: number;
  calibrationSimilarity: number;
  recommendGhidra: boolean;
  recommendations: string[];
}

export interface IRelocationEntry {
  sourceAddress: number;
  sourceName: string;
  targetAddress: number;
  confidence: number;
  status: 'matched' | 'similar' | 'not_found';
}

export default {
  ERegionType,
  EMatchType
};
