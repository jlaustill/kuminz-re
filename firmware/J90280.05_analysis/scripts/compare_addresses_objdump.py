#!/usr/bin/env python3
"""
Compare memory addresses from memory_defaults.json with working/J90280.05.objdump.asm
to identify which addresses reference zeros vs actual code
"""

import json
import re
import sys
import os

def load_memory_addresses(json_file):
    """Load memory addresses from the analysis JSON file"""
    
    print(f"# Loading memory addresses from: {json_file}")
    print("=" * 50)
    
    try:
        with open(json_file, 'r') as f:
            data = json.load(f)
        
        addresses = []
        for param in data['parameters']:
            addr = param.get('address')
            if addr and addr.startswith('0x'):
                addresses.append({
                    'address': addr,
                    'name': param.get('name', ''),
                    'value': param.get('value', ''),
                    'length': param.get('length', 2),
                    'comment': param.get('comment', '')
                })
        
        print(f"Loaded {len(addresses)} memory addresses")
        return addresses
        
    except Exception as e:
        print(f"❌ Error loading addresses: {e}")
        return []

def search_address_in_objdump(address, objdump_file):
    """Search for an address in the objdump file and analyze the context"""
    
    # Convert address to different formats for searching
    addr_hex = address.upper()  # 0X00060006
    addr_no_prefix = addr_hex[2:]  # 00060006
    addr_lower = address.lower()  # 0x00060006
    
    # For 68k addressing, also check variations
    addr_int = int(address, 16)
    
    patterns = [
        addr_hex,       # 0X00060006
        addr_lower,     # 0x00060006
        addr_no_prefix, # 00060006
        f"#{addr_hex}",  # #0X00060006 (immediate addressing)
        f"#{addr_lower}", # #0x00060006
    ]
    
    results = {
        'found': False,
        'references': [],
        'context_lines': [],
        'is_zero_area': False,
        'has_code_refs': False
    }
    
    try:
        with open(objdump_file, 'r') as f:
            lines = f.readlines()
        
        # Search for address references
        for line_num, line in enumerate(lines):
            line_strip = line.strip()
            
            # Check if any of our patterns appear in this line
            for pattern in patterns:
                if pattern in line_strip:
                    results['found'] = True
                    results['references'].append({
                        'line_num': line_num + 1,
                        'line': line_strip,
                        'pattern': pattern
                    })
                    
                    # Get context (5 lines before and after)
                    start_line = max(0, line_num - 5)
                    end_line = min(len(lines), line_num + 6)
                    context = []
                    for i in range(start_line, end_line):
                        marker = " >>> " if i == line_num else "     "
                        context.append(f"{marker}{i+1:6}: {lines[i].rstrip()}")
                    
                    results['context_lines'].append({
                        'match_line': line_num + 1,
                        'context': context
                    })
        
        # Analyze if this appears to be in a zero/uninitialized area
        if results['found']:
            for ref in results['references']:
                line = ref['line'].lower()
                # Look for patterns that suggest zeros or uninitialized memory
                if any(x in line for x in ['.long 0x0', '.word 0x0', '00 00 00 00', 'ff ff ff ff']):
                    results['is_zero_area'] = True
                # Look for patterns that suggest actual code
                elif any(x in line for x in ['move.', 'lea ', 'cmp.', 'add.', 'sub.', 'jsr ', 'bsr ']):
                    results['has_code_refs'] = True
        
        return results
        
    except Exception as e:
        print(f"Error searching {objdump_file}: {e}")
        return results

def analyze_addresses_in_objdump(addresses, objdump_file):
    """Analyze all addresses against the objdump file"""
    
    print(f"# Analyzing {len(addresses)} addresses in: {objdump_file}")
    print("=" * 60)
    
    if not os.path.exists(objdump_file):
        print(f"❌ Error: {objdump_file} not found")
        return {}
    
    results = {
        'total_addresses': len(addresses),
        'found_in_objdump': 0,
        'zero_areas': 0,
        'code_references': 0,
        'not_found': 0,
        'address_analysis': []
    }
    
    print("Searching addresses (this may take a moment)...")
    
    for i, addr_info in enumerate(addresses):
        if i % 100 == 0:  # Progress indicator
            print(f"  Progress: {i}/{len(addresses)} ({i*100//len(addresses)}%)")
        
        addr = addr_info['address']
        search_result = search_address_in_objdump(addr, objdump_file)
        
        analysis = {
            'address': addr,
            'name': addr_info['name'],
            'value': addr_info['value'],
            'found': search_result['found'],
            'reference_count': len(search_result['references']),
            'is_zero_area': search_result['is_zero_area'],
            'has_code_refs': search_result['has_code_refs'],
            'references': search_result['references'][:3],  # Keep first 3 refs
            'sample_context': search_result['context_lines'][:1] if search_result['context_lines'] else []
        }
        
        results['address_analysis'].append(analysis)
        
        # Update counters
        if search_result['found']:
            results['found_in_objdump'] += 1
            if search_result['is_zero_area']:
                results['zero_areas'] += 1
            if search_result['has_code_refs']:
                results['code_references'] += 1
        else:
            results['not_found'] += 1
    
    return results

def generate_comparison_report(results, output_file):
    """Generate detailed comparison report"""
    
    print(f"\n# Address Comparison Analysis")
    print("=" * 40)
    print(f"Total addresses analyzed: {results['total_addresses']}")
    print(f"Found in objdump: {results['found_in_objdump']}")
    print(f"Not found: {results['not_found']}")
    print(f"In zero/uninitialized areas: {results['zero_areas']}")
    print(f"With code references: {results['code_references']}")
    
    # Calculate percentages
    if results['total_addresses'] > 0:
        found_pct = (results['found_in_objdump'] * 100) // results['total_addresses']
        zero_pct = (results['zero_areas'] * 100) // results['total_addresses'] 
        code_pct = (results['code_references'] * 100) // results['total_addresses']
        
        print(f"\nPercentages:")
        print(f"  Found in firmware: {found_pct}%")
        print(f"  In zero areas: {zero_pct}%")
        print(f"  With code references: {code_pct}%")
    
    # Show interesting findings
    print(f"\n# Interesting Findings")
    print("=" * 25)
    
    code_refs = [a for a in results['address_analysis'] if a['has_code_refs']]
    zero_refs = [a for a in results['address_analysis'] if a['is_zero_area']]
    
    print(f"Addresses with actual code references ({len(code_refs)}):")
    for addr in code_refs[:10]:  # Show first 10
        refs = len(addr['references'])
        print(f"  {addr['address']} ({addr['name'][:20]}): {refs} references")
    
    if len(code_refs) > 10:
        print(f"  ... and {len(code_refs) - 10} more")
    
    print(f"\nAddresses in zero/uninitialized areas ({len(zero_refs)}):")
    for addr in zero_refs[:10]:
        print(f"  {addr['address']} ({addr['name'][:20]}): value={addr['value']}")
    
    if len(zero_refs) > 10:
        print(f"  ... and {len(zero_refs) - 10} more")
    
    # Show sample contexts for code references
    print(f"\n# Sample Code References")
    print("=" * 30)
    
    for addr in code_refs[:5]:  # Show context for first 5
        if addr['sample_context']:
            print(f"\n{addr['address']} ({addr['name']}):")
            context = addr['sample_context'][0]['context']
            for line in context:
                print(f"  {line}")
    
    # Save detailed results
    with open(output_file, 'w') as f:
        json.dump(results, f, indent=2)
    
    print(f"\n✅ Detailed analysis saved to: {output_file}")
    
    return results

def main():
    if len(sys.argv) != 1:
        print("Usage: python3 compare_addresses_objdump.py")
        print("")
        print("This script compares memory addresses from analysis/memory_defaults.json")
        print("with working/J90280.05.objdump.asm to identify code vs zero references.")
        return 1
    
    json_file = 'analysis/memory_defaults.json'
    objdump_file = 'working/J90280.05.objdump.asm'
    output_file = 'analysis/address_objdump_comparison.json'
    
    # Check files exist
    if not os.path.exists(json_file):
        print(f"❌ Error: {json_file} not found")
        return 1
    
    if not os.path.exists(objdump_file):
        print(f"❌ Error: {objdump_file} not found")
        return 1
    
    # Create output directory
    os.makedirs(os.path.dirname(output_file), exist_ok=True)
    
    # Load addresses
    addresses = load_memory_addresses(json_file)
    if not addresses:
        print("❌ Failed to load addresses")
        return 1
    
    # Analyze against objdump
    results = analyze_addresses_in_objdump(addresses, objdump_file)
    
    # Generate report
    generate_comparison_report(results, output_file)
    
    # Summary
    if results['code_references'] > 0:
        print(f"\n🎯 Found {results['code_references']} addresses with actual code references!")
        print("   These are likely the most important for reverse engineering")
    
    if results['zero_areas'] > 0:
        print(f"\n⚠️  Found {results['zero_areas']} addresses in zero/uninitialized areas")
        print("   These represent the EEPROM defaults we're trying to replace")
    
    return 0

if __name__ == "__main__":
    sys.exit(main())