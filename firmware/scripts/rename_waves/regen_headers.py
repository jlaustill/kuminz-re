"""Regenerate the three firmware headers with generate_headers.py's generate_* functions (its main() also edits
the .cpp). Usage: regen_headers.py <firmware output dir>...
Check them afterwards: g++ -fsyntax-only -std=c++17 -I <output dir> hdr_check.cpp"""
import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))      # firmware/scripts
import generate_headers as g                                                             # noqa: E402

for output_dir in sys.argv[1:]:
    output_dir = os.path.abspath(output_dir)
    for name, fn in (("firmware_types.hpp", g.generate_types_header),
                     ("firmware_globals.hpp", g.generate_globals_header),
                     ("firmware_functions.hpp", g.generate_functions_header)):
        content, stats = fn(output_dir)
        g.write_file(os.path.join(output_dir, name), content)
        print(os.path.basename(os.path.dirname(output_dir)), name, stats)
