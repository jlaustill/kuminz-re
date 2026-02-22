#!/usr/bin/env python3
"""
Cross-reference export_test.exp.xml and docs/common_parameters.json
to find memory addresses with non-zero default values for code analysis
"""

import json
import xml.etree.ElementTree as ET
import sys
import os

def parse_xml_parameters(xml_file):
    """Extract parameters from XML export file"""
    
    print(f"# Parsing XML parameters from: {xml_file}")
    print("=" * 50)
    
    try:
        tree = ET.parse(xml_file)
        root = tree.getroot()
        
        # Define namespace mapping
        ns = {'ns': 'Cummins.Calibration.ExportFile.xsd'}
        
        # Find all Parameter elements with Value type (scalar parameters)
        parameters = {}
        param_count = 0
        
        # Search for Parameter elements with proper namespace
        for param in root.findall('.//ns:Parameter', ns):
            # Find child elements - they have xmlns="" (empty namespace)
            name_elem = param.find('Name')
            value_elem = param.find('Value') 
            type_elem = param.find('Type')
            subfile_elem = param.find('SubfileNumber')
            units_elem = param.find('EngineeringUnits')
            
            if name_elem is not None and value_elem is not None and type_elem is not None:
                name = name_elem.text
                value = value_elem.text
                param_type = type_elem.text
                subfile = subfile_elem.text if subfile_elem is not None else "0"
                units = units_elem.text if units_elem is not None else ""
                
                # Only include Value type parameters (not arrays)
                if param_type == "Value" and name:
                    parameters[name] = {
                        'value': value,
                        'subfile': subfile,
                        'type': param_type,
                        'units': units
                    }
                    param_count += 1
        
        print(f"Found {param_count} scalar parameters in XML")
        return parameters
        
    except Exception as e:
        print(f"❌ Error parsing XML: {e}")
        return {}

def load_common_parameters(json_file):
    """Load common parameters from JSON file"""
    
    print(f"# Loading JSON parameters from: {json_file}")
    print("=" * 50)
    
    try:
        with open(json_file, 'r') as f:
            data = json.load(f)
        
        # Create lookup by parameter name
        params = {}
        for param in data.get('parameters', []):
            name = param.get('name')
            if name:
                params[name] = param
        
        print(f"Found {len(params)} parameters in JSON")
        print(f"Total parameters analyzed: {data['metadata']['totalParameters']}")
        print(f"Memory address coverage: {data['metadata']['addressCoverage']}")
        
        return params, data['metadata']
        
    except Exception as e:
        print(f"❌ Error loading JSON: {e}")
        return {}, {}

def cross_reference_parameters(xml_params, json_params):
    """Cross-reference parameters to find memory addresses with non-zero defaults"""
    
    print(f"# Cross-referencing parameters...")
    print("=" * 35)
    
    results = []
    matched = 0
    non_zero_found = 0
    
    for name in xml_params:
        if name in json_params:
            matched += 1
            xml_data = xml_params[name]
            json_data = json_params[name]
            
            # Get values
            xml_value = xml_data.get('value', '0')
            address = json_data.get('calculatedAddress', 'Unknown')
            
            # Check if value is non-zero
            is_non_zero = False
            try:
                float_value = float(xml_value)
                if float_value != 0.0:
                    is_non_zero = True
            except ValueError:
                # Handle non-numeric values
                if xml_value and xml_value not in ['0', '0.0', '0.00', '']:
                    is_non_zero = True
            
            if is_non_zero and address != 'Unknown':
                non_zero_found += 1
                results.append({
                    'name': name,
                    'address': address,
                    'value': xml_value,
                    'subfile': xml_data.get('subfile', '0'),
                    'units': xml_data.get('units', ''),
                    'engineeringUnit': json_data.get('engineeringUnit', ''),
                    'length': json_data.get('length', 0),
                    'scale': json_data.get('scale', 1.0),
                    'signed': json_data.get('signed', False),
                    'comment': json_data.get('comment', ''),
                    'memoryBlockAddress': json_data.get('memoryBlockAddress', ''),
                    'memoryBlockOffset': json_data.get('memoryBlockOffset', ''),
                    'scaled_value': float(xml_value) * json_data.get('scale', 1.0) if xml_value.replace('.', '').replace('-', '').isdigit() else xml_value
                })
    
    print(f"Parameters matched: {matched}")
    print(f"Non-zero defaults found: {non_zero_found}")
    
    # Sort by address, handling None and Unknown values
    return sorted(results, key=lambda x: x['address'] if x.get('address') and x['address'] != 'Unknown' else 'ZZZZZ')

def generate_analysis_output(results, metadata, output_file):
    """Generate detailed analysis output"""
    
    print(f"\n# Memory Defaults Analysis")
    print("=" * 35)
    print(f"Non-zero default parameters: {len(results)}")
    
    # Sort by address for organized output
    print(f"\n# Non-Zero Default Parameters")
    print("=" * 40)
    print(f"{'Address':<12} {'Name':<16} {'Value':<12} {'Units':<8} {'Comment'[:30]}")
    print("-" * 90)
    
    address_ranges = {}
    
    for result in results[:20]:  # Show first 20
        name = result['name'][:15]
        value = str(result['value'])[:10]
        units = result['units'][:7] if result['units'] else result['engineeringUnit'][:7]
        comment = result['comment'][:30]
        
        print(f"{result['address']:<12} {name:<16} {value:<12} {units:<8} {comment}")
        
        # Group by memory block for analysis
        mem_block = result.get('memoryBlockAddress', 'Unknown')
        if mem_block not in address_ranges:
            address_ranges[mem_block] = []
        address_ranges[mem_block].append(result)
    
    if len(results) > 20:
        print(f"... and {len(results) - 20} more parameters")
    
    # Memory block analysis
    print(f"\n# Memory Block Analysis")
    print("=" * 30)
    for block, params in sorted(address_ranges.items()):
        if block != 'Unknown':
            print(f"Block {block}: {len(params)} parameters with defaults")
            # Show address range for this block
            addresses = [int(p['address'], 16) for p in params if p['address'] != 'Unknown']
            if addresses:
                print(f"  Address range: 0x{min(addresses):08X} - 0x{max(addresses):08X}")
    
    # Generate code search patterns
    print(f"\n# Code Search Patterns")
    print("=" * 28)
    print("Use these addresses to search for code references:")
    
    unique_addresses = set()
    for result in results:
        addr = result['address']
        if addr and addr != 'Unknown' and isinstance(addr, str) and addr.startswith('0x'):
            unique_addresses.add(addr)
    
    addresses_list = sorted(list(unique_addresses))
    print(f"Total unique addresses: {len(addresses_list)}")
    
    for i, addr in enumerate(addresses_list[:10]):
        # Convert to search patterns
        hex_val = addr[2:].upper()  # Remove 0x
        dec_val = int(addr, 16)
        
        # Generate different format searches
        print(f"  {addr} ({dec_val})")
        print(f"    Hex patterns: {hex_val}, 0x{hex_val}")
        
        # Little-endian patterns for 16-bit values
        if len(hex_val) >= 4:
            le_pattern = hex_val[2:4] + hex_val[0:2] if len(hex_val) == 4 else hex_val
            print(f"    Little-endian: {le_pattern}")
        
        print()
        
        if i >= 9:  # Show first 10
            print(f"    ... and {len(addresses_list) - 10} more addresses")
            break
    
    # Save detailed results
    output_data = {
        'metadata': {
            'total_non_zero_defaults': len(results),
            'analysis_date': metadata.get('generatedAt', 'Unknown'),
            'source_files': {
                'xml_file': 'export_test.exp.xml',
                'json_file': 'docs/common_parameters.json'
            },
            'memory_blocks_with_defaults': len(address_ranges)
        },
        'parameters': results,
        'memory_blocks': {block: len(params) for block, params in address_ranges.items()},
        'search_addresses': addresses_list
    }
    
    with open(output_file, 'w') as f:
        json.dump(output_data, f, indent=2)
    
    print(f"✅ Detailed analysis saved to: {output_file}")
    
    return len(results)

def main():
    if len(sys.argv) != 1:
        print("Usage: python3 cross_reference_defaults.py")
        print("")
        print("This script cross-references export_test.exp.xml and docs/common_parameters.json")
        print("to find memory addresses with non-zero default values.")
        print("")
        print("Files must be in the current directory structure:")
        print("  ./export_test.exp.xml")
        print("  ./docs/common_parameters.json")
        return 1
    
    xml_file = 'export_test.exp.xml'
    json_file = 'docs/common_parameters.json'
    output_file = 'analysis/memory_defaults.json'
    
    # Check files exist
    if not os.path.exists(xml_file):
        print(f"❌ Error: {xml_file} not found")
        return 1
    
    if not os.path.exists(json_file):
        print(f"❌ Error: {json_file} not found") 
        return 1
    
    # Create output directory
    os.makedirs(os.path.dirname(output_file), exist_ok=True)
    
    # Parse files
    xml_params = parse_xml_parameters(xml_file)
    json_params, metadata = load_common_parameters(json_file)
    
    if not xml_params or not json_params:
        print("❌ Failed to parse input files")
        return 1
    
    # Cross-reference
    results = cross_reference_parameters(xml_params, json_params)
    
    # Generate output
    total_defaults = generate_analysis_output(results, metadata, output_file)
    
    if total_defaults > 0:
        print(f"\n🎯 Success! Found {total_defaults} memory addresses with non-zero defaults")
        print(f"   These addresses can be used to search for code references in the firmware")
        print(f"   Check {output_file} for complete analysis")
    else:
        print("\n⚠️  No non-zero defaults found in cross-reference")
    
    return 0

if __name__ == "__main__":
    sys.exit(main())