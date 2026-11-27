#!/usr/bin/env python3
"""Hex dump of a byte range of a firmware image file.

usage: peek.py <image.bin> <image base hex> <address hex> <length>
"""
import sys


def main():
    data = open(sys.argv[1], 'rb').read()
    base = int(sys.argv[2], 16)
    address = int(sys.argv[3], 16)
    length = int(sys.argv[4], 0)
    offset = address - base
    chunk = data[offset:offset + length]
    for row in range(0, len(chunk), 16):
        part = chunk[row:row + 16]
        print('%#08x: %s' % (address + row, ' '.join('%02x' % b for b in part)))


if __name__ == '__main__':
    main()
