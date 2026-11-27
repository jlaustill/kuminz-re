"""Save the research workflow's three reports (survey, mechanics, design) as text files.
usage: save_research.py <workflow output file> <out dir>"""
import json
import os
import sys

data = json.load(open(sys.argv[1]))["result"]
for key in ("survey", "mechanics", "design"):
    with open(os.path.join(sys.argv[2], f"research_{key}.txt"), "w") as fh:
        fh.write(data[key])
    print(key, len(data[key]))
