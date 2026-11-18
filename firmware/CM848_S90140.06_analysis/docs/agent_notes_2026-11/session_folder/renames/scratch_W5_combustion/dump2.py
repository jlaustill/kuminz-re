import sys
sys.path.insert(0, '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/scratch_W5_combustion')
from peek import *

def stats(name, addr, n=304, signed=False):
    t = table(addr, n, signed)
    mn, mx = min(t), max(t)
    print(f"{name:38s} {hex(addr):9s} n={n} min={mn} max={mx} first={t[:4]} mid={t[n//2-1:n//2+1]}")
    return t

print("== five quantities: (Alpha1=map1, Chi2=map2, Chi3=map3, Chi4=map4, Alpha0=base) 304-word grids")
sets = {
  'SOI (timing offset fn)  scale 0.1171875 deg': (0x40179c, 0x400e1c, 0x40107c, 0x4012dc, 0x40153c, False),
  'MCF (mode 3)            scale 1/128 lb/min': (0x40237c, 0x4019fc, 0x401c5c, 0x401ebc, 0x40211c, False),
  'EGR fraction (blend)    scale 1/8192':        (0x402f5c, 0x4025dc, 0x40283c, 0x402a9c, 0x402cfc, False),
  'charge temp (mode 2)    scale 1/64 F signed': (0x403b3c, 0x4031bc, 0x40341c, 0x40367c, 0x4038dc, True),
  'NOx target (mode 1)     scale 1/2048':        (0x40471c, 0x403d9c, 0x403ffc, 0x40425c, 0x4044bc, False),
}
for k, (a1, c2, c3, c4, a0, sg) in sets.items():
    print('--', k)
    for nm, ad in (('Alpha0(base)', a0), ('Alpha1(map1)', a1), ('Chi2(map2)', c2), ('Chi3(map3)', c3), ('Chi4(map4)', c4)):
        stats(nm, ad, 304, sg)

print("== axes: header word + breakpoints")
for nm, ad in (('fuel_table_rpm_axis_cal (Alpha0 speed)', 0x40499e), ('fuel_table_load_axis_cal (Alpha0 fuel)', 0x40497c),
               ('fuel_demand_rpm_axis_cal (Alpha1 speed)', 0x4049e8), ('fuel_demand_load_axis_cal (Alpha1 fuel)', 0x4049c6),
               ('xaxis_cal_2 (Chi2 speed)', 0x404a32), ('xaxis_cal_1 (Chi2 fuel)', 0x404a10),
               ('xaxis_cal_4 (Chi3 speed)', 0x404a7c), ('xaxis_cal_3 (Chi3 fuel)', 0x404a5a),
               ('xaxis_cal_6 (Chi4 speed)', 0x404ac6), ('xaxis_cal_5 (Chi4 fuel)', 0x404aa4)):
    hdr = w(ad); n = 1 + hdr // 2
    t = table(ad + 2, n - 1)
    print(f"{nm:42s} {hex(ad)} hdr={hdr} breakpoints={n-1} first={t[:3]} last={t[-2:]}")

print("== 1-D max fuel curves (22 words: hdr + 21)")
for nm, ad in (('fuel_map_rpm_axis_cal (speed)', 0x404aee), ('governor_fuel_demand_values_cal (Alpha0)', 0x404b1a),
               ('fuel_rpm_table_boost1_cal (Alpha1)', 0x404b46), ('boost2 (Chi2)', 0x404b72), ('boost3 (Chi3)', 0x404b9e), ('boost4 (Chi4)', 0x404bca)):
    hdr = w(ad); t = table(ad + 2, hdr // 2)
    print(f"{nm:42s} {hex(ad)} hdr={hdr} n={len(t)} first={t[:4]} max={max(t)} last={t[-2:]}")

print("== density-based fuel limit table (CBR) and MCF limit (CBL)")
for nm, ad in (('fuel_load_table_rpm_axis_cal', 0x404bf6), ('fuel_load_table_ystart_cal (density axis)', 0x404c1e)):
    hdr = w(ad); t = table(ad + 2, hdr // 2)
    print(f"{nm:42s} {hex(ad)} hdr={hdr} n={len(t)} first={t[:3]} last={t[-2:]}")
stats('fuel_load_table_yend_cal (fuel limit grid)', 0x404c40, 304)
for nm, ad in (('fuel_demand_load_rate_cap_rpm_axis_cal', 0x405792), ('fuel_demand_load_rate_cap_ystart_cal (density axis)', 0x4057b4)):
    hdr = w(ad); t = table(ad + 2, hdr // 2)
    print(f"{nm:42s} {hex(ad)} hdr={hdr} n={len(t)} first={t[:3]} last={t[-2:]}")
stats('fuel_demand_load_rate_cap_yend_cal (MCF limit)', 0x4057d6, 256)

print("== protective chi tables (determine_chi): density source and coolant source")
for nm, ad, sg in (('fuel_map_load_axis_cal (density axis)', 0x400c84, False), ('fuel_map_load_values_cal (chi value)', 0x400ca6, False),
                   ('fuel_map_load_filter_a_cal (chi axis)', 0x400cc8, False), ('fuel_map_load_filter_b_cal (EL axis)', 0x400cea, False),
                   ('fuel_map_load_filter_c_cal (high table)', 0x400d0c, False), ('fuel_map_load_filter_d_cal (low table)', 0x400d2e, False),
                   ('fuel_map_boost_axis_cal (coolant temp)', 0x400d50, True), ('fuel_map_boost_values_cal (chi value)', 0x400d94, False),
                   ('fuel_map_boost_filter_a_cal (chi axis)', 0x400d72, False), ('fuel_map_boost_filter_b_cal (EL axis)', 0x400db6, False),
                   ('fuel_map_boost_filter_c_cal (high table)', 0x400dd8, False), ('fuel_map_boost_filter_d_cal (low table)', 0x400dfa, False)):
    hdr = w(ad); t = table(ad + 2, hdr // 2, sg)
    print(f"{nm:42s} {hex(ad)} hdr={hdr} n={len(t)} {t}")

print("== CBL SOI limit tables axes")
for nm, ad in (('0x40523e min speed axis', 0x40523e), ('0x405266 min fuel axis', 0x405266), ('0x4054e8 max speed axis', 0x4054e8), ('0x405510 max fuel axis', 0x405510)):
    hdr = w(ad); t = table(ad + 2, hdr // 2)
    print(f"{nm:28s} hdr={hdr} first={t[:3]} last={t[-2:]}")
stats('min SOI limit grid 0x405288', 0x405288, 304, True)
stats('max SOI limit grid 0x405532', 0x405532, 304, True)
