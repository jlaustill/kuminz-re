"""Rewrite text files with CRLF line endings (each bare LF becomes CRLF; existing CRLF stays). Prints each file's
line count. usage: to_crlf.py <file>..."""
import sys

for path in sys.argv[1:]:
    data = open(path, "rb").read()
    text = data.replace(b"\r\n", b"\n").replace(b"\n", b"\r\n")
    open(path, "wb").write(text)
    print(path, text.count(b"\r\n"), "lines")
