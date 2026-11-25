#!/usr/bin/env python3
"""For each symbol, list the decompiled functions (from '// Function: <name> @ <address>' headers) whose bodies use it.

usage: uses.py <ghidra .cpp> <symbol> [...]
"""
import re
import sys


def main():
    path = sys.argv[1]
    symbols = sys.argv[2:]
    patterns = {s: re.compile(r'\b' + re.escape(s) + r'\b') for s in symbols}
    current = '(file header)'
    found = {s: {} for s in symbols}
    header = re.compile(r'^// Function: (\S+) @ (0x[0-9a-fA-F]+)')
    with open(path, errors='replace') as handle:
        for line in handle:
            match = header.match(line)
            if match:
                current = '%s@%s' % (match.group(1), match.group(2))
                continue
            for symbol, pattern in patterns.items():
                if pattern.search(line):
                    found[symbol][current] = found[symbol].get(current, 0) + 1
    for symbol in symbols:
        users = ', '.join('%s x%d' % (k, v) for k, v in found[symbol].items())
        print('%s: %s' % (symbol, users or 'none'))


if __name__ == '__main__':
    main()
