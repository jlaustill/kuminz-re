import csv
import glob
import json
import os
import re
import sys

OUT = '/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/result_W12_bin1.jsonl'
BIN = '/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/bins/bin1.json'
FW = 'firmware/CM848_S90140.06_analysis/output'
CPP = FW + '/cm848_rom.ghidra.cpp'

BANNED = {"temp", "tmp", "press", "pos", "corr", "coef", "coeff", "thresh", "thr", "inj", "qty", "ctrl", "cfg",
          "cmd", "val", "vals", "idx", "cnt", "num", "ref", "spd", "eng", "prot", "lim", "mult", "comp", "adj", "trq",
          "tbl", "lkp", "sw", "calc", "accel", "decel", "pct", "freq", "volt", "amp", "deg", "sec", "diag", "cond", "req",
          "resp", "init", "tmr", "buf", "aux", "arb", "iat", "imt", "proc", "mgr", "util", "info", "stat", "msg"}
ALLOWED_ABBR = {"rpm", "j1939", "pgn", "spn", "dtc", "obd", "ecm", "egr", "nox", "id", "adc", "pwm", "can", "pid", "tpu", "qadc", "vin"}
EEPROM = (0x3fd482, 0x3feec1)


def words(name):
    out = []
    for p in name.split('_'):
        out += [w.lower() for w in re.findall(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+", p)]
    return out


bins = json.load(open(BIN))
rows = [json.loads(l) for l in open(OUT)]
problems = []
if len(rows) != len(bins):
    problems.append("line count %d vs bin %d" % (len(rows), len(bins)))
raw = open(OUT, 'rb').read()
if any(b > 127 for b in raw):
    problems.append("non-ascii bytes in the result file")

names = [r['new'] for r in rows]
if len(set(names)) != len(names):
    problems.append("duplicate names in the bin: %s" % sorted(n for n in set(names) if names.count(n) > 1))
if len({r['address'] for r in rows}) != len(rows):
    problems.append("duplicate addresses")

# whole-token search of every name in all CSVs and the cpp
corpus = {}
for path in glob.glob(FW + '/*.csv') + [CPP, FW + '/firmware_globals.hpp', FW + '/firmware_types.hpp', FW + '/firmware_functions.hpp']:
    corpus[path] = open(path, errors='replace').read()
big = "\n".join(corpus.values())
tokens = set(re.findall(r"[A-Za-z_][A-Za-z0-9_]*", big))
for r in rows:
    if r['new'] in tokens:
        where = [os.path.basename(p) for p, t in corpus.items() if re.search(r"(?<![A-Za-z0-9_])" + re.escape(r['new']) + r"(?![A-Za-z0-9_])", t)]
        problems.append("name already present as a token: %s in %s" % (r['new'], where))

SIZE = {1: 'byte', 2: 'word', 4: 'dword'}
for r, b in zip(rows, bins):
    n = r['new']
    tag = "%s %s" % (r['address'], n)
    if r['address'] != b['address']:
        problems.append("%s: address mismatch with bin %s" % (tag, b['address']))
    if r['kind'] != 'new_global':
        problems.append("%s: kind %s" % (tag, r['kind']))
    if r['verdict'] not in ('confirmed', 'uncertain', 'rejected'):
        problems.append("%s: verdict" % tag)
    if not re.fullmatch(r"[a-z][a-z0-9]*(_[a-z0-9]+)*", n):
        problems.append("%s: name format" % tag)
    bad = sorted(set(words(n)) & BANNED)
    if bad:
        problems.append("%s: banned words %s" % (tag, bad))
    if re.search(r"(?<![a-z])0x|_[0-9a-f]*[a-f][0-9a-f]*\d[0-9a-f]*(_|$)", n):
        problems.append("%s: hex-looking part" % tag)
    a = int(r['address'], 16)
    in_eeprom = EEPROM[0] <= a <= EEPROM[1]
    if n.endswith('_cal') != in_eeprom:
        problems.append("%s: _cal rule (eeprom=%s)" % (tag, in_eeprom))
    size = int(b['size_bytes'])
    t = r['type']
    if t == 'i16':
        if size != 2 or b['signed'] != 'S':
            problems.append("%s: i16 needs a signed 2-byte record" % tag)
    elif t != SIZE[size]:
        problems.append("%s: type %s vs size %d" % (tag, t, size))
    if t == 'i16':
        census = b['access_widths']
        # lha-only census, or the two address-form gaps that were disassembled by hand
        if "'lha'" not in census and r['address'] != '0x0005c7ac':
            problems.append("%s: i16 without an lha census" % tag)
    if b['signed'] == 'S' and size == 2 and t == 'word' and "'lha'" in b['access_widths'] and set(re.findall(r"'(\w+)'", b['access_widths'])) == {'lha'}:
        problems.append("%s: signed lha-only record typed word" % tag)
    for key in ('evidence', 'comment'):
        if '\n' in r[key] or '\r' in r[key]:
            problems.append("%s: newline in %s" % (tag, key))
        if '"' in r[key]:
            problems.append("%s: double quote in %s" % (tag, key))
    if b['record'].lower().replace('_', '') not in (r['evidence'].lower() + r['comment'].lower()).replace('_', ''):
        problems.append("%s: record name %s not cited" % (tag, b['record']))
    # comment must lead with the e2m record (or EEPROM offset then e2m)
    if not (r['comment'].startswith('e2m ') or r['comment'].startswith('EEPROM 0x')):
        problems.append("%s: comment does not lead with e2m" % tag)
    # allowed abbreviations: flag short non-dictionary-looking words for review
    for w in words(n):
        if len(w) <= 3 and w not in ALLOWED_ABBR and w not in {"the", "of", "up", "in", "out", "not", "run", "all", "can", "pgn", "cal", "one", "two"} and not w.isdigit():
            problems.append("REVIEW short word %r in %s" % (w, n))

print("rows:", len(rows), "verdicts:", {v: sum(1 for r in rows if r['verdict'] == v) for v in ('confirmed', 'uncertain', 'rejected')})
print("types:", {t: sum(1 for r in rows if r['type'] == t) for t in sorted({r['type'] for r in rows})})
print("max name length:", max(len(n) for n in names))
for p in problems:
    print("PROBLEM", p)
if not problems:
    print("no problems")
