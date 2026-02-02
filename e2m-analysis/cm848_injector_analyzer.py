#!/usr/bin/env python3
"""
CM848 Fuel Injector Timing Analyzer
Extracts dead time, EOI, and voltage compensation data from Cummins E2M/ECFG calibration files

Part of the kuminz-re project
"""

import struct
import sys
import json
from pathlib import Path
from typing import Dict, List, Tuple, Optional
import argparse

class E2MParser:
    """Parser for Cummins E2M (Electronic Engine Management) calibration files"""
    
    def __init__(self, filepath: str):
        self.filepath = Path(filepath)
        self.data = self.filepath.read_bytes()
        self.tables = {}
        self.header = {}
        
    def find_ascii_strings(self, min_length=4):
        """Extract ASCII strings that might indicate table names"""
        strings = []
        current = []
        
        for byte in self.data:
            if 32 <= byte <= 126:  # Printable ASCII
                current.append(chr(byte))
            else:
                if len(current) >= min_length:
                    strings.append(''.join(current))
                current = []
        
        return strings
    
    def search_injector_keywords(self):
        """Search for injector-related keywords in the file"""
        keywords = [
            b'INJ', b'DEAD', b'TIME', b'ENERGIZING', b'VOLTAGE',
            b'PRESS', b'RAIL', b'COMP', b'CYL', b'CORR', b'IQA',
            b'PILOT', b'MAIN', b'POST', b'SOI', b'EOI', b'SWITCH'
        ]
        
        matches = []
        for keyword in keywords:
            offset = 0
            while True:
                pos = self.data.find(keyword, offset)
                if pos == -1:
                    break
                # Get context around match
                context_start = max(0, pos - 20)
                context_end = min(len(self.data), pos + 50)
                context = self.data[context_start:context_end]
                matches.append({
                    'keyword': keyword.decode('ascii'),
                    'offset': hex(pos),
                    'context': context
                })
                offset = pos + 1
        
        return matches
    
    def extract_table_candidates(self, keyword_matches):
        """Identify potential table structures near keyword matches"""
        candidates = []
        
        for match in keyword_matches:
            offset = int(match['offset'], 16)
            
            # Look for table header patterns
            # Common patterns: size markers, dimension info, etc.
            region = self.data[offset-32:offset+128]
            
            # Try to identify table dimensions
            # Look for small integers (1-20) that could be dimension sizes
            for i in range(0, len(region)-4, 1):
                try:
                    val1 = struct.unpack('<H', region[i:i+2])[0]  # Little endian short
                    val2 = struct.unpack('<H', region[i+2:i+4])[0]
                    
                    # Plausible table dimensions
                    if 1 <= val1 <= 50 and 1 <= val2 <= 50:
                        candidates.append({
                            'keyword': match['keyword'],
                            'offset': hex(offset + i - 32),
                            'potential_dims': (val1, val2),
                            'region': region[i:i+64]
                        })
                except:
                    continue
        
        return candidates
    
    def extract_float_array(self, offset: int, count: int, format='<f'):
        """Extract array of floats from given offset"""
        size = struct.calcsize(format)
        values = []
        
        for i in range(count):
            try:
                pos = offset + (i * size)
                value = struct.unpack(format, self.data[pos:pos+size])[0]
                values.append(value)
            except:
                values.append(None)
        
        return values
    
    def analyze_voltage_tables(self):
        """
        Search for voltage compensation tables
        Expected: arrays with voltage values in range 10-16V
        and corresponding dead time values in range 0.0-2.0ms
        """
        results = []
        
        # Scan for patterns that look like voltage arrays
        for i in range(0, len(self.data) - 40, 4):
            try:
                # Try to read 10 float values
                values = []
                for j in range(10):
                    val = struct.unpack('<f', self.data[i+j*4:i+j*4+4])[0]
                    values.append(val)
                
                # Check if this looks like a voltage array (10-16V range)
                if all(9.0 <= v <= 17.0 for v in values if v is not None):
                    # Found potential voltage axis
                    # Look for corresponding dead time values nearby
                    dead_times = []
                    for j in range(10):
                        dt = struct.unpack('<f', self.data[i+40+j*4:i+44+j*4])[0]
                        dead_times.append(dt)
                    
                    # Dead time typically 0.3-2.0 ms (300-2000 microseconds)
                    if all(0.0 <= dt <= 3.0 for dt in dead_times if dt is not None):
                        results.append({
                            'offset': hex(i),
                            'voltage_values': values,
                            'dead_time_values': dead_times,
                            'type': 'voltage_compensation'
                        })
            except:
                continue
        
        return results

class InjectorTimingAnalyzer:
    """Analyze extracted calibration data for injector timing parameters"""
    
    def __init__(self):
        self.dead_time_tables = []
        self.voltage_comp_tables = []
        self.pressure_comp_tables = []
        
    def analyze_dead_time_vs_voltage(self, voltage_values, dead_time_values):
        """Analyze dead time compensation curve"""
        if len(voltage_values) != len(dead_time_values):
            return None
        
        analysis = {
            'voltage_range': (min(voltage_values), max(voltage_values)),
            'dead_time_range_ms': (min(dead_time_values), max(dead_time_values)),
            'nominal_voltage': 13.5,  # Typical reference
            'curve_type': 'lookup_table',
            'compensation_factor': None
        }
        
        # Calculate compensation factor (how much dead time changes per volt)
        dv = max(voltage_values) - min(voltage_values)
        ddt = max(dead_time_values) - min(dead_time_values)
        if dv > 0:
            analysis['compensation_factor'] = ddt / dv  # ms per volt
        
        return analysis
    
    def estimate_eoi_delay(self, dead_time_ms, rail_pressure_psi):
        """
        Estimate switch-off to EOI delay based on typical common rail characteristics
        This is an estimation model based on known physics
        """
        # Higher rail pressure = faster closing (pressure helps close the injector)
        # Typical range: 0.3-0.8ms
        base_delay_ms = 0.5
        
        # Pressure effect (normalized to 15,000 PSI reference)
        pressure_factor = 15000 / max(rail_pressure_psi, 5000)
        eoi_delay = base_delay_ms * pressure_factor
        
        # Actual injection duration = commanded - dead_time + eoi_delay
        return {
            'eoi_delay_ms': round(eoi_delay, 3),
            'total_latency_ms': round(dead_time_ms + eoi_delay, 3),
            'note': 'Estimated based on typical common rail physics'
        }

def main():
    parser = argparse.ArgumentParser(
        description='Analyze CM848 ECU calibration files for injector timing parameters'
    )
    parser.add_argument('file', help='Path to E2M or ECFG file')
    parser.add_argument('--output', '-o', help='Output JSON file for results')
    parser.add_argument('--search-keywords', action='store_true',
                       help='Search for injector-related keywords')
    parser.add_argument('--extract-strings', action='store_true',
                       help='Extract all ASCII strings from file')
    parser.add_argument('--find-voltage-tables', action='store_true',
                       help='Attempt to locate voltage compensation tables')
    
    args = parser.parse_args()
    
    if not Path(args.file).exists():
        print(f"Error: File not found: {args.file}")
        return 1
    
    print(f"Analyzing: {args.file}")
    print(f"File size: {Path(args.file).stat().st_size} bytes")
    print()
    
    parser_obj = E2MParser(args.file)
    results = {
        'file': args.file,
        'file_size': len(parser_obj.data),
        'analysis': {}
    }
    
    if args.extract_strings:
        print("Extracting ASCII strings...")
        strings = parser_obj.find_ascii_strings(min_length=5)
        results['ascii_strings'] = strings
        print(f"Found {len(strings)} strings")
        for s in strings[:20]:  # Show first 20
            print(f"  {s}")
        print()
    
    if args.search_keywords:
        print("Searching for injector-related keywords...")
        matches = parser_obj.search_injector_keywords()
        results['keyword_matches'] = matches
        print(f"Found {len(matches)} keyword matches")
        for m in matches[:10]:  # Show first 10
            print(f"  {m['keyword']} at {m['offset']}")
        print()
        
        print("Analyzing table candidates near keywords...")
        candidates = parser_obj.extract_table_candidates(matches)
        results['table_candidates'] = candidates
        print(f"Found {len(candidates)} potential table structures")
        print()
    
    if args.find_voltage_tables:
        print("Searching for voltage compensation tables...")
        voltage_tables = parser_obj.analyze_voltage_tables()
        results['voltage_tables'] = voltage_tables
        print(f"Found {len(voltage_tables)} potential voltage compensation tables")
        
        analyzer = InjectorTimingAnalyzer()
        for i, table in enumerate(voltage_tables):
            print(f"\nTable {i+1} at offset {table['offset']}:")
            print(f"  Voltage range: {min(table['voltage_values']):.2f}V - {max(table['voltage_values']):.2f}V")
            print(f"  Dead time range: {min(table['dead_time_values']):.3f}ms - {max(table['dead_time_values']):.3f}ms")
            
            analysis = analyzer.analyze_dead_time_vs_voltage(
                table['voltage_values'],
                table['dead_time_values']
            )
            
            if analysis:
                print(f"  Compensation: {analysis['compensation_factor']:.4f} ms/V")
                
                # Estimate EOI for typical operating conditions
                mid_dead_time = sum(table['dead_time_values']) / len(table['dead_time_values'])
                eoi_est = analyzer.estimate_eoi_delay(mid_dead_time, 15000)
                print(f"  Estimated EOI delay: {eoi_est['eoi_delay_ms']}ms")
                print(f"  Total latency: {eoi_est['total_latency_ms']}ms")
    
    if args.output:
        with open(args.output, 'w') as f:
            json.dump(results, f, indent=2, default=str)
        print(f"\nResults saved to: {args.output}")
    
    return 0

if __name__ == '__main__':
    sys.exit(main())
