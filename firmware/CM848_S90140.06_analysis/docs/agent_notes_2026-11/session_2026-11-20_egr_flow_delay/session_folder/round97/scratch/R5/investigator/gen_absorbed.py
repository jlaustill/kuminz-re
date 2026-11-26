import json
import re

channels = ['coolant level', 'coolant temperature', 'intake manifold temperature', 'oil pressure',
            'water in fuel', 'boost pressure', 'engine sync fuel pressure', 'fuel temperature',
            'ambient air pressure']
fam = {}
for line in open('/home/linux/.claude/jobs/374b0424/tmp/w15/r97/family_R5.txt'):
    a, n, t = line.split()
    fam[int(a, 16)] = (n, t)
e2m = {}
for line in open('/home/linux/.claude/jobs/374b0424/tmp/w15/r97/scratch/R5/investigator/rows50_e2m.txt'):
    m = re.match(r'(\w+) \+(\w+) (\w+) .*-> (0x[0-9a-f]+) .*?; (.*)$', line.strip())
    if m:
        blk, off, mn, addr, desc = m.groups()
        e2m[int(addr, 16)] = (blk, off, mn, desc)

history = {
    0x02: ('engine_speed_severity_index',
           'word written by cm550_calculateFaultDerateEngineSpeedLimit (move.w d3,(0x2,a2) at 0x18ed4 with a2 = 0x8057c0 + 30n) and read by rampEngineProtectionSeverityIndex (move.w (0x2,a1) at 0x186d4), processDiagnosticLimitStatus (tst.w (0x8057c2 + 30n) at 0x190a6) and logEngineProtectionChannelFaults (tst.w (0x2,a0) at 0x19600)'),
    0x18: ('fueling_fault_log_index',
           'word read by cm550_recordEngineProtectionFaultLogEntry (move.w (0x18,a0),d3 at 0x1934c, a0 = engine_protection_current_history = 0x8057c0 + 30n) as the entry index of the fueling log; cm550_closeEngineProtectionFaultLogEntry takes history + 24 (0x19448) and advances it modulo 5 (addq.w / divsl #5 at 0x19518-0x19524)'),
    0x1c: ('engine_speed_fault_log_index',
           'word read by cm550_recordEngineProtectionFaultLogEntry (move.w (0x1c,a0),d3 at 0x1936c) as the entry index of the engine speed log; cm550_closeEngineProtectionFaultLogEntry takes history + 28 (0x19468) and advances it modulo 5 (0x19518-0x19524)'),
}
config = {
    0x06: ('fueling_ramp_rate',
           'word read by rampEngineProtectionSeverityIndex as the fueling severity step (move.w (0x6,a2),d3 at 0x186ce, a2 = 0x807032 + 36n)'),
    0x08: ('engine_speed_ramp_rate',
           'word read by rampEngineProtectionSeverityIndex as the engine speed severity step (move.w (0x8,a2),d3 at 0x186e0)'),
    0x1a: ('fueling_fault_index',
           'word read as the fueling fault bit number by cm550_recordEngineProtectionFaultLogEntry (move.w (0x1a,a0),d2 at 0x19352, a0 = engine_protection_current_configuration = 0x807032 + 36n; the bit is set in 0x806000 / 0x806040 at 0x193da / 0x193ea) and cm550_closeEngineProtectionFaultLogEntry (0x19452)'),
    0x1c: ('engine_speed_fault_index',
           'word read as the engine speed fault bit number by cm550_recordEngineProtectionFaultLogEntry (move.w (0x1c,a0),d2 at 0x19372) and cm550_closeEngineProtectionFaultLogEntry (0x19472)'),
}
out = []
for a in sorted(fam):
    n, t = fam[a]
    if 0x8057c0 <= a < 0x8058ce:
        base, stride, table, typ, fields = 0x8057c0, 30, 'engine_protection_channel_history_table', 'engine_protection_channel_history_t', history
    elif 0x807032 <= a < 0x807176:
        base, stride, table, typ, fields = 0x807032, 36, 'engine_protection_channel_configuration_table', 'engine_protection_channel_configuration_t', config
    else:
        continue
    idx, off = divmod(a - base, stride)
    fld, proof = fields[off]
    blk, eoff, mn, desc = e2m[a]
    desc = desc.split('~')[0].strip()
    out.append({
        'firmware': 'CM550',
        'address': '0x%08x' % a,
        'current_name': n,
        'proposed_name': '%s[%d].%s' % (table, idx, fld),
        'proposed_type': '(delete the row: a word field of the struct array %s %s[9])' % (table, typ),
        'comment': 'Absorbed by the struct array %s (0x%x, %s[9]): delete this flat row. It is channel %d (%s), field +0x%x %s: e2m %s +%s %s \'%s\'.' % (
            table, base, typ, idx, channels[idx], off, fld, blk, eoff.lstrip('0') or '0', mn, desc),
        'evidence': 'Channel %d record = 0x%x + %d x %d = 0x%x (e2m block %s resolves there); field +0x%x: %s.' % (
            idx, base, stride, idx, base + stride * idx, blk, off, proof),
        'confidence': 'high',
    })
print(json.dumps(out, indent=1))
print(len(out))
