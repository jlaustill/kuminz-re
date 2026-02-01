#!/usr/bin/env python3
"""
CM848 Injector Timing Visualization Tool
Generates plots and reports for dead time and EOI analysis
"""

import json
import sys
from pathlib import Path
import argparse

def generate_ascii_plot(x_values, y_values, title="", x_label="", y_label="", width=60, height=20):
    """Generate simple ASCII art plot"""
    if not x_values or not y_values or len(x_values) != len(y_values):
        return "Invalid data for plotting"
    
    # Normalize values to fit in grid
    x_min, x_max = min(x_values), max(x_values)
    y_min, y_max = min(y_values), max(y_values)
    
    x_range = x_max - x_min if x_max != x_min else 1
    y_range = y_max - y_min if y_max != y_min else 1
    
    # Create grid
    grid = [[' ' for _ in range(width)] for _ in range(height)]
    
    # Plot points
    for x, y in zip(x_values, y_values):
        plot_x = int((x - x_min) / x_range * (width - 1))
        plot_y = height - 1 - int((y - y_min) / y_range * (height - 1))
        if 0 <= plot_x < width and 0 <= plot_y < height:
            grid[plot_y][plot_x] = '*'
    
    # Connect points with lines
    for i in range(len(x_values) - 1):
        x1 = int((x_values[i] - x_min) / x_range * (width - 1))
        x2 = int((x_values[i+1] - x_min) / x_range * (width - 1))
        y1 = height - 1 - int((y_values[i] - y_min) / y_range * (height - 1))
        y2 = height - 1 - int((y_values[i+1] - y_min) / y_range * (height - 1))
        
        if abs(x2 - x1) > abs(y2 - y1):
            for x in range(min(x1, x2), max(x1, x2) + 1):
                if 0 <= x < width:
                    y = y1 + (y2 - y1) * (x - x1) // (x2 - x1) if x2 != x1 else y1
                    if 0 <= y < height:
                        if grid[y][x] == ' ':
                            grid[y][x] = '-'
        else:
            for y in range(min(y1, y2), max(y1, y2) + 1):
                if 0 <= y < height:
                    x = x1 + (x2 - x1) * (y - y1) // (y2 - y1) if y2 != y1 else x1
                    if 0 <= x < width:
                        if grid[y][x] == ' ':
                            grid[y][x] = '|'
    
    # Build output
    output = []
    if title:
        output.append(title.center(width + 10))
        output.append("")
    
    # Y-axis labels
    for i, row in enumerate(grid):
        y_val = y_max - (i / (height - 1)) * y_range
        label = f"{y_val:6.2f} |"
        output.append(label + ''.join(row))
    
    # X-axis
    output.append(" " * 8 + "-" * width)
    
    # X-axis labels
    x_label_line = " " * 8
    for i in range(0, width, 10):
        x_val = x_min + (i / (width - 1)) * x_range
        x_label_line += f"{x_val:>10.1f}"
    output.append(x_label_line)
    
    if x_label:
        output.append(x_label.center(width + 10))
    
    if y_label:
        output.insert(0, "")
        output.insert(0, y_label.center(width + 10))
    
    return '\n'.join(output)

def generate_timing_report(analysis_data):
    """Generate comprehensive timing analysis report"""
    report = []
    report.append("=" * 80)
    report.append("CM848 FUEL INJECTOR TIMING ANALYSIS REPORT")
    report.append("=" * 80)
    report.append("")
    
    # File info
    report.append(f"Source File: {analysis_data['file']}")
    report.append(f"File Size: {analysis_data['file_size']} bytes")
    report.append("")
    
    # Voltage tables
    if 'voltage_tables' in analysis_data and analysis_data['voltage_tables']:
        report.append("-" * 80)
        report.append("VOLTAGE COMPENSATION TABLES")
        report.append("-" * 80)
        report.append("")
        
        for i, table in enumerate(analysis_data['voltage_tables']):
            report.append(f"Table {i+1} (Offset: {table['offset']})")
            report.append("")
            
            voltages = table['voltage_values']
            dead_times = table['dead_time_values']
            
            report.append("  Voltage (V)  |  Dead Time (ms)")
            report.append("  " + "-" * 35)
            
            for v, dt in zip(voltages, dead_times):
                report.append(f"    {v:6.2f}     |     {dt:.4f}")
            
            report.append("")
            
            # Statistics
            report.append("  Statistics:")
            report.append(f"    Voltage Range: {min(voltages):.2f}V - {max(voltages):.2f}V")
            report.append(f"    Dead Time Range: {min(dead_times):.4f}ms - {max(dead_times):.4f}ms")
            
            # Calculate slope
            dv = max(voltages) - min(voltages)
            ddt = max(dead_times) - min(dead_times)
            if dv > 0:
                slope = ddt / dv
                report.append(f"    Compensation Factor: {slope:.4f} ms/V")
                report.append(f"    This means dead time changes by {slope*1000:.2f} µs per volt")
            
            report.append("")
            
            # Generate plot
            plot = generate_ascii_plot(
                voltages, dead_times,
                title=f"Dead Time vs. Voltage - Table {i+1}",
                x_label="Battery Voltage (V)",
                y_label="Dead Time (ms)"
            )
            report.append(plot)
            report.append("")
            report.append("")
    
    # Keyword matches
    if 'keyword_matches' in analysis_data:
        report.append("-" * 80)
        report.append(f"INJECTOR KEYWORD MATCHES: {len(analysis_data['keyword_matches'])}")
        report.append("-" * 80)
        report.append("")
        
        # Group by keyword
        by_keyword = {}
        for match in analysis_data['keyword_matches']:
            kw = match['keyword']
            if kw not in by_keyword:
                by_keyword[kw] = []
            by_keyword[kw].append(match['offset'])
        
        for keyword, offsets in sorted(by_keyword.items()):
            report.append(f"  {keyword}: {len(offsets)} occurrences")
            for offset in offsets[:5]:  # Show first 5
                report.append(f"    - {offset}")
            if len(offsets) > 5:
                report.append(f"    ... and {len(offsets) - 5} more")
            report.append("")
    
    # Table candidates
    if 'table_candidates' in analysis_data:
        report.append("-" * 80)
        report.append(f"POTENTIAL TABLE STRUCTURES: {len(analysis_data['table_candidates'])}")
        report.append("-" * 80)
        report.append("")
        
        for i, candidate in enumerate(analysis_data['table_candidates'][:10]):
            report.append(f"Candidate {i+1}:")
            report.append(f"  Keyword: {candidate['keyword']}")
            report.append(f"  Offset: {candidate['offset']}")
            report.append(f"  Potential Dimensions: {candidate['potential_dims']}")
            report.append("")
    
    report.append("=" * 80)
    report.append("END OF REPORT")
    report.append("=" * 80)
    
    return '\n'.join(report)

def main():
    parser = argparse.ArgumentParser(
        description='Visualize CM848 injector timing analysis results'
    )
    parser.add_argument('json_file', help='JSON file from cm848_injector_analyzer.py')
    parser.add_argument('--output', '-o', help='Output report file (default: stdout)')
    
    args = parser.parse_args()
    
    # Load analysis data
    with open(args.json_file, 'r') as f:
        analysis_data = json.load(f)
    
    # Generate report
    report = generate_timing_report(analysis_data)
    
    if args.output:
        Path(args.output).write_text(report)
        print(f"Report saved to: {args.output}")
    else:
        print(report)
    
    return 0

if __name__ == '__main__':
    sys.exit(main())
