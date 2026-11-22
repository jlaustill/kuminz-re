"""Round 32: a copy of a .cpp with each function body on one line (whitespace runs -> one space; a member access
wrapped after its '.' joined), the '// Function:' headers kept on their own lines, so token maps match wrapped
long names.  usage: flatten_cpp.py <in.cpp> <out.cpp>"""
import re
import sys

text = open(sys.argv[1], errors="replace").read()
parts = re.split(r"^(// Function: [^\n]*)\n", text, flags=re.M)
out = [re.sub(r"\.\s+(?=[A-Za-z_])", ".", re.sub(r"\s+", " ", parts[0]))]
for i in range(1, len(parts), 2):
    body = re.sub(r"\s+", " ", parts[i + 1])
    out.append(parts[i] + "\n" + re.sub(r"\.\s+(?=[A-Za-z_])", ".", body) + "\n")
open(sys.argv[2], "w").write("\n".join(out))
