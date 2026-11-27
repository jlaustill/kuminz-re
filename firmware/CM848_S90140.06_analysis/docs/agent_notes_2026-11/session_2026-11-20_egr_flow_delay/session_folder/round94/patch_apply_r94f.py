"""Round 94 tooling: an override with "force_type": true replaces the live type even when the widths differ (the
judge proved the new type, e.g. a 22-byte struct over a row a typing pass made 'word'); the report says so.
Idempotent. usage: patch_apply_r94f.py <apply_r94.py>"""
import sys

p = sys.argv[1]
s = open(p).read()
old = '''        if idx is not None and old_type not in ("", "undefined") and old_type != typ:
            w_old, w_new = type_width(fw, old_type), type_width(fw, typ)'''
new = '''        if idx is not None and old_type not in ("", "undefined") and old_type != typ and ov.get("force_type"):
            report.append(f"{b} TYPE FORCED {fw} {a}: {old_type} -> {typ} ({ov['reason']})")
        elif idx is not None and old_type not in ("", "undefined") and old_type != typ:
            w_old, w_new = type_width(fw, old_type), type_width(fw, typ)'''
if new not in s:
    assert s.count(old) == 1, s.count(old)
    s = s.replace(old, new)
open(p, "w").write(s)
print("patched")
