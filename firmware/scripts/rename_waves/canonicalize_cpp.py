"""Write the comparison form of a baseline .cpp for the label-only proof: no `// Generated:` line, no /* */
comments, and each function's goto labels (LAB_x / switchD_x[_default | ::caseD_x] / caseD_x) renumbered L0, L1,
... by first appearance - the form `reverse_names.py --ignore-comments --canonical-code-labels` gives the new build.
Usage: canonicalize_cpp.py <old.cpp> <out.cpp>"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import canonical_labels, strip_comments, strip_generated_header  # noqa: E402


def canonical(text):
    return canonical_labels(strip_comments(strip_generated_header(text)))


if __name__ == "__main__":
    old_path, out_path = sys.argv[1:3]
    open(out_path, "w").write(canonical(open(old_path).read()))
