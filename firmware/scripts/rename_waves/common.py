"""Helpers shared by the rename-wave scripts."""
import re

# Goto-target labels the decompiler numbers by address: LAB_x, switchD_x, switchD_x_default, switchD_x::caseD_y, caseD_y
LABEL = re.compile(r"\b(?:LAB_[0-9a-f]{8}|switchD_[0-9a-f]{8}(?:_default|::caseD_[0-9a-f]+)?|caseD_[0-9a-f]+)\b")


def clip(text, limit=400):
    """Cut text to at most `limit` characters at a word boundary and mark the cut with ' ...'
    (a plain text[:limit] cuts identifiers mid-word)."""
    if len(text) <= limit:
        return text
    cut = text[:limit]
    if not text[limit].isspace():
        space = cut.rfind(" ")
        cut = cut[:space] if space > 0 else cut
    return cut.rstrip(" ,;:(-/") + " ..."


def strip_generated_header(text):
    """Blank the wall-clock '// Generated:' line every build rewrites."""
    return re.sub(r"^// Generated:.*$", "", text, flags=re.M)


def strip_comments(text):
    return re.sub(r"/\*.*?\*/", "", text, flags=re.S)


def canonical_labels(text):
    """Renumber each function's goto labels L0, L1, ... by first appearance (one-to-one per function)."""
    out = []
    for chunk in re.split(r"(?m)^(?=// Function: )", text):
        seen = {}
        out.append(LABEL.sub(lambda m: seen.setdefault(m.group(0), f"L{len(seen)}"), chunk))
    return "".join(out)
