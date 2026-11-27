"""Entry constructors for the bin-5 verdict modules (verdicts_*.py). Each returns a plain dict that emit.py checks and
writes as one JSON line.  rename(address, old, new, evidence, code_quote, comment)."""


def rename(address, old, new, evidence, code_quote, comment):
    return {"kind": "global", "verdict": "confirmed", "address": address, "old": old, "new": new, "evidence": evidence,
            "code_quote": code_quote, "comment": comment}


def keep(address, old, e2m_note):
    return {"kind": "global", "verdict": "keep", "address": address, "old": old, "new": old, "e2m_note": e2m_note}


def drift(address, old, evidence):
    return {"kind": "global", "verdict": "drift", "address": address, "old": old, "evidence": evidence}


def uncertain(address, old, evidence):
    return {"kind": "global", "verdict": "uncertain", "address": address, "old": old, "evidence": evidence}
