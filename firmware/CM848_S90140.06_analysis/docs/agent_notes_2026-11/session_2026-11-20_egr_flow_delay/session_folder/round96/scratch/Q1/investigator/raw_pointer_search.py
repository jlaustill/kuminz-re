#!/usr/bin/env python3
"""Find every occurrence of a 4-byte big-endian value in a binary image (any alignment).

usage: raw_pointer_search.py <image.bin> <base hex> <value hex> [...]
"""
import sys


def main():
    data = open(sys.argv[1], 'rb').read()
    base = int(sys.argv[2], 16)
    for value_text in sys.argv[3:]:
        value = int(value_text, 16)
        needle = value.to_bytes(4, 'big')
        hits = []
        start = 0
        while True:
            index = data.find(needle, start)
            if index < 0:
                break
            hits.append(base + index)
            start = index + 1
        print('%#x: %s' % (value, ' '.join('%#x' % h for h in hits) or 'none'))


if __name__ == '__main__':
    main()
