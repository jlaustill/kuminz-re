#!/usr/bin/env python3
"""Parse the CM550 Ghidra .cpp export: per function, the signature, and every
in_stack_XXXXXXXX / param_N._a_b_ reference (offset from the entry sp, width).

Output: JSON list to stdout (or the path in argv[2]).
"""
import json
import re
import sys

CPP = sys.argv[1]
OUT = sys.argv[2] if len(sys.argv) > 2 else None

FUNC_RE = re.compile(r'^// Function: (\S+) @ 0x([0-9a-fA-F]+)')
IN_STACK_RE = re.compile(r'\b_?in_stack_([0-9a-f]{8})\b')
PARAM_PART_RE = re.compile(r'\b(param_\d+)\._(\d+)_(\d+)_')
DECL_RE = re.compile(r'^\s+([A-Za-z_][\w ]*?[\w*]+)\s+\*?(_?in_stack_[0-9a-f]{8})(\s*\[\d+\])?;')

TYPE_SIZE = {
    'undefined1': 1, 'byte': 1, 'char': 1, 'uchar': 1, 'bool': 1, 'undefined': 1,
    'sbyte': 1, 'uint8_t': 1, 'int8_t': 1,
    'undefined2': 2, 'short': 2, 'ushort': 2, 'word': 2, 'uint16_t': 2, 'int16_t': 2,
    'undefined3': 3,
    'undefined4': 4, 'int': 4, 'uint': 4, 'dword': 4, 'long': 4, 'ulong': 4,
    'float': 4, 'uint32_t': 4, 'int32_t': 4,
    'undefined8': 8, 'longlong': 8, 'ulonglong': 8, 'double': 8, 'qword': 8,
    'undefined5': 5, 'undefined6': 6, 'undefined7': 7,
}


def type_size(t):
    t = t.strip()
    if t.endswith('*'):
        return 4
    t = t.replace('const ', '').replace('volatile ', '').strip()
    if t in TYPE_SIZE:
        return TYPE_SIZE[t]
    return None  # enum / struct: resolve by hand


def parse_signature(sig):
    """'ret name(type a, type b)' -> (ret, name, [(type, pname)])."""
    m = re.match(r'^(.*?)\s*\b(\w+)\((.*)\)\s*$', sig)
    if not m:
        return None, None, []
    ret, name, plist = m.group(1), m.group(2), m.group(3).strip()
    params = []
    if plist and plist != 'void':
        for p in plist.split(','):
            p = p.strip()
            pm = re.match(r'^(.*?)(\w+)$', p)
            if pm:
                params.append((pm.group(1).strip(), pm.group(2)))
            else:
                params.append((p, '?'))
    return ret, name, params


def stack_layout(params):
    """Ghidra __stdcall on 68000: stack pentry offset 4, align 4, right-justified
    (big-endian). Returns {pname: (offset, size)} (offset None when unknown)."""
    layout = {}
    slot_off = 4
    for ptype, pname in params:
        sz = type_size(ptype)
        if sz is None:
            layout[pname] = (None, None, ptype)
            slot_off = None
            continue
        if slot_off is None:
            layout[pname] = (None, sz, ptype)
            continue
        slots = (sz + 3) // 4
        used = slots * 4
        layout[pname] = (slot_off + used - sz, sz, ptype)
        slot_off += used
    return layout


def main():
    lines = open(CPP, encoding='utf-8', errors='replace').read().split('\n')
    funcs = []
    i = 0
    n = len(lines)
    starts = []
    for idx, line in enumerate(lines):
        m = FUNC_RE.match(line)
        if m:
            starts.append((idx, m.group(1), int(m.group(2), 16)))
    for k, (idx, name, addr) in enumerate(starts):
        end = starts[k + 1][0] if k + 1 < len(starts) else n
        body = lines[idx:end]
        # signature: first non-empty line after the '//' header block
        sig = None
        sig_line = None
        in_comment = False
        j = idx + 1
        while j < end:
            s = body[j - idx].strip()
            if in_comment:
                if '*/' in s:
                    in_comment = False
                j += 1
                continue
            if s.startswith('/*'):
                if '*/' not in s:
                    in_comment = True
                j += 1
                continue
            if s == '' or s.startswith('//'):
                j += 1
                continue
            sig = s
            sig_line = j + 1
            while sig.count('(') > sig.count(')') or '(' not in sig:
                j += 1
                if j >= end:
                    break
                sig += ' ' + body[j - idx].strip()
            break
        ret, sname, params = parse_signature(sig or '')
        layout = stack_layout(params)
        named_params = [p for t, p in params if not re.match(r'^param_\d+$', p)]
        in_stack = {}
        partials = {}
        decls = {}
        for j, line in enumerate(body):
            dm = DECL_RE.match(line)
            if dm:
                decls[dm.group(2).lstrip('_')] = dm.group(1).strip() + (dm.group(3) or '')
            for im in IN_STACK_RE.finditer(line):
                key = 'in_stack_' + im.group(1)
                in_stack.setdefault(key, []).append(idx + j + 1)
            for pm in PARAM_PART_RE.finditer(line):
                key = '%s._%s_%s_' % (pm.group(1), pm.group(2), pm.group(3))
                partials.setdefault(key, []).append(idx + j + 1)
            for pname in named_params:
                for pm in re.finditer(r'\b(' + re.escape(pname) + r')\._(\d+)_(\d+)_', line):
                    key = '%s._%s_%s_' % (pm.group(1), pm.group(2), pm.group(3))
                    partials.setdefault(key, []).append(idx + j + 1)
        if not in_stack and not partials:
            continue
        refs = []
        for key, lns in in_stack.items():
            off = int(key[len('in_stack_'):], 16)
            dtype = decls.get(key)
            if dtype and '[' in dtype:
                base, cnt = dtype.split('[')
                cnt = int(cnt.rstrip(']'))
                width = (type_size(base) or 0) * cnt
            else:
                width = type_size(dtype) if dtype else None
            refs.append({'kind': 'in_stack', 'token': key, 'offset': off,
                         'width': width, 'decl_type': dtype,
                         'lines': lns, 'count': len(lns) - (1 if dtype else 0)})
        for key, lns in partials.items():
            pm = re.match(r'^(\w+)\._(\d+)_(\d+)_$', key)
            pname, a, b = pm.group(1), int(pm.group(2)), int(pm.group(3))
            poff, psz, ptype = layout.get(pname, (None, None, None))
            refs.append({'kind': 'partial', 'token': key, 'param': pname,
                         'param_type': ptype, 'param_offset': poff,
                         'offset': (poff + a) if poff is not None else None,
                         'width': b, 'lines': lns, 'count': len(lns)})
        refs.sort(key=lambda r: (r['offset'] if r['offset'] is not None else 999))
        funcs.append({'name': name, 'address': addr, 'signature': sig,
                      'sig_line': sig_line, 'cpp_line': idx + 1,
                      'params': [{'type': t, 'name': p,
                                  'offset': layout[p][0], 'size': layout[p][1]}
                                 for t, p in params],
                      'refs': refs})
    data = json.dumps(funcs, indent=1)
    if OUT:
        open(OUT, 'w').write(data)
    else:
        print(data)
    # all function starts too
    allf = [{'name': nm, 'address': ad, 'cpp_line': ix + 1} for ix, nm, ad in starts]
    if OUT:
        open(OUT.replace('.json', '_all_functions.json'), 'w').write(json.dumps(allf))


if __name__ == '__main__':
    main()
