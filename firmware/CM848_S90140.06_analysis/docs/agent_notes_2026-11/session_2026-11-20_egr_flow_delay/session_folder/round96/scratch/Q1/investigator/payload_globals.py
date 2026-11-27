#!/usr/bin/env python3
"""List the globals of a firmware's global_variables.csv that fall inside given payload ranges.

usage: payload_globals.py <global_variables.csv> <name>=<start hex>:<length> [...]
"""
import sys


def load(path):
    rows = []
    with open(path) as handle:
        for line in handle:
            if line.startswith('#') or not line.strip():
                continue
            parts = line.rstrip('\n').split(',', 3)
            try:
                address = int(parts[0], 16)
            except ValueError:
                continue
            rows.append((address, parts[1], parts[2] if len(parts) > 2 else '', parts[3] if len(parts) > 3 else ''))
    return rows


def main():
    rows = load(sys.argv[1])
    for spec in sys.argv[2:]:
        name, rng = spec.split('=')
        start, length = rng.split(':')
        start = int(start, 16)
        length = int(length, 0)
        print('==', name, hex(start), length)
        for address, symbol, kind, comment in rows:
            if start <= address < start + length:
                print('  ', hex(address), symbol, kind, comment[:220])


if __name__ == '__main__':
    main()
