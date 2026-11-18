"""Regenerate the three firmware headers without generate_headers.main() (which edits the .cpp)."""
import os
import sys

sys.path.insert(0, sys.argv[1])          # firmware/scripts
import generate_headers as g

for output_dir in sys.argv[2:]:
    output_dir = os.path.abspath(output_dir)
    for name, fn in (("firmware_types.hpp", g.generate_types_header),
                     ("firmware_globals.hpp", g.generate_globals_header),
                     ("firmware_functions.hpp", g.generate_functions_header)):
        content, stats = fn(output_dir)
        g.write_file(os.path.join(output_dir, name), content)
        print(os.path.basename(os.path.dirname(output_dir)), name, stats)
