// E2M File Analysis Types

export interface IE2MRow {
  fullName: string;
  engineeringUnit: string;
  column3: string;
  column4: string;
  column5: string;
  type: TE2MType;
  column7: string;
  length: string;
  precision: string;
  signed: 'U' | 'S';
  scale: string;
  minimumValue: string;
  subfileNumber: string;
  column14: string;
  column15: string;
  column16?: string;
  comment: string;
  rawLine: string;
}

export type TE2MType = 'X' | 'Y' | 'Z' | 'N' | 'C' | 'G';

export interface IE2MFile {
  filename: string;
  header1: string;
  header2: string;
  rows: IE2MRow[];
}

export interface IColumnStats {
  column: string;
  uniqueValues: string[];
  valueCount: Record<string, number>;
  minLength: number;
  maxLength: number;
  emptyCount: number;
  totalCount: number;
}

export interface IComparisonResult {
  commonLines: string[];
  uniqueLines: Record<string, string[]>;
  differences: IE2MRow[];
}