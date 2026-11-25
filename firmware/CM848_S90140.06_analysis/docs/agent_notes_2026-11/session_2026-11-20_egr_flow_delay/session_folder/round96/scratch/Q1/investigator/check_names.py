#!/usr/bin/env python3
"""Check proposed global names against a global_variables.csv: report exact matches (collisions) and the
current row at each proposed address.

usage: check_names.py <global_variables.csv> <address>=<name> [...]
"""
import sys


def main():
    path = sys.argv[1]
    by_name = {}
    by_address = {}
    with open(path) as handle:
        for line in handle:
            if line.startswith('#') or not line.strip():
                continue
            parts = line.rstrip('\n').split(',', 3)
            try:
                address = int(parts[0], 16)
            except ValueError:
                continue
            by_name.setdefault(parts[1], []).append(address)
            by_address.setdefault(address, []).append(parts[1])
    proposed = {}
    for spec in sys.argv[2:]:
        address_text, name = spec.split('=')
        address = int(address_text, 16)
        if name in proposed:
            print('DUPLICATE PROPOSAL %s at %#x and %#x' % (name, proposed[name], address))
        proposed[name] = address
        clash = [a for a in by_name.get(name, []) if a != address]
        current = by_address.get(address, [])
        print('%#x %-70s current=%s %s' % (address, name, current or '-', ('COLLIDES with %s' % [hex(a) for a in clash]) if clash else ''))


if __name__ == '__main__':
    main()
