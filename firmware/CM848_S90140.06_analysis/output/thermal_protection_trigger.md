# CM848 Thermal Protection Trigger — what engages the `fuel_temp_trim_raw` protection loop

**Status:** investigation, 2026-06-03. Medium confidence on the loop structure; lower on the
physical meaning of the modeled quantity (see Caveats).

## Question

`cm848_fuelTrimFromOutputShaftSpeed` computes `fuel_temp_trim_raw` and caps it; the value feeds
`fuel_temperature_trim` (via EMA) which is consumed by the engine-protection system. What
*physically engages* that protection?

## The loop (closed feedback)

```
fuel_temp_trim_raw            per-cycle modeled fuel-temp increment
   │                          (shaft-speed path: (oss*0x3c000)/protection_trim_divisor_*,
   │                           capped at fuel_temp_cap_from_shaft_speed; temperature path:
   │                           fuel_temp_trim_numerator/product in cm848_calculateFuelDemandValue)
   ▼ exponentialMovingAverage
fuel_temperature_trim         running modeled fuel temperature (thermal lag)
   │
   ▼ cm848_fuelDemandSmoothingController  (the trigger)
   │   gate: fuel_temperature_trim > fuel_demand_smoothing_temp_threshold_cal (0x0005c2a0)
   │         while in an active fuel-demand mode, advances a per-mode debounce counter:
   │     • mode 4    increment_a → limit → safety_bits_2 |= 0x10
   │     • mode 5/6  increment_b → limit → safety_bits_1 |= 0x4000
   │     • mode 2/3  increment_c → limit → safety_bits_1 |= 0x8000
   │   limit = fuel_demand_rate_limit_debounce_cal (0x0005c2a4), or
   │           fuel_demand_rate_limit_debounce_low_cal (0x0005c29a) when
   │           fuel_demand_cal_index <= throttle_fuel_demand_adjusted
   ▼
cm848_checkSafetyConditionsForProtection
   │   if (j1939_feature_enable_flags & 0x800)   // feature licensed
   │      AND any gate bit set → protection_mode_enable_flag = 1
   ▼
cm848_processProtectionControlLogic → latches protection_enable_t_0040c050.protection_active (bit 7)
   ▼
feeds back: fuelTrimFromOutputShaftSpeed picks protection_trim_divisor_working (not active)
            vs _cal (active); plus torque/fuel derate and HPCR timing.
```

**Physical trigger:** the *modeled* fuel temperature staying above
`fuel_demand_smoothing_temp_threshold_cal` long enough (per-mode debounce counter saturates)
while actively fueling — a sustained-overtemperature, debounced condition, not a single-sample trip.
The debounce counters act as the software "thermal mass": transients decay (reset path), sustained
heat latches.

## `system_status_flags_t_003fe974` safety-bit map (this firmware)

The protection-engage gate (`checkSafetyConditionsForProtection`) ORs these — but only some are
ever *set* in this calibration:

| Gate bit | Set by | Live? |
|----------|--------|-------|
| `safety_bits_2 & 0x10` | `cm848_fuelDemandSmoothingController` (mode 4) | ✅ the fuel-temp path |
| `safety_bits_1 & 0x4000` | `cm848_fuelDemandSmoothingController` (mode 5/6) | ✅ |
| `safety_bits_1 & 0x8000` | `cm848_fuelDemandSmoothingController` (mode 2/3) | ✅ |
| `safety_bits_1 & 0x10` | (no setter found, any form, either bank) | ❌ dormant/reserved |
| `safety_bits_1 & 0x20` | (no setter found) | ❌ dormant/reserved |
| `enable_state & 0x400` / `0x800` | (no setter found; only 0x20/0x80 are set) | ❌ dormant/reserved |

So **the only live trigger into the thermal-protection gate in this firmware is the fuel-demand
debounce path.** The dormant bits are checked-but-never-set (likely reserved or excluded features).

Other `safety_bits_1` bits exist but feed a *different* path, not this gate:
`0x100` ← `sensor_fault_safety_check`; `0x200/0x400/0x800/0x1000` ← `engine_camSync_*` /
`engine_camTiming_*` (cam-sync/timing integrity), consumed by `protection_fault_latch_update` and
`j1939FaultStateUpdate`.

## Cals named this pass (Bank-2 ROM, `0x0005xxxx`)

| Addr | Name | Role |
|------|------|------|
| `0x0005c2a0` | `fuel_demand_smoothing_temp_threshold_cal` | modeled-fuel-temp gate |
| `0x0005c2a4` | `fuel_demand_rate_limit_debounce_cal` | default debounce count |
| `0x0005c29a` | `fuel_demand_rate_limit_debounce_low_cal` | debounce count when demand ≤ throttle-adjusted |

## Caveats

- **"Fuel temperature" is inferred,** not proven. `fuel_temp_trim_raw` is *modeled* (computed from
  shaft speed or a numerator/product ratio), not read from a sensor. The surrounding cals are all
  named `*_fuel_temp_*`, so the firmware authors treated it as fuel temperature, but it may be a
  broader thermal/injector-duty proxy.
- The dormant gate bits mean "protection engaged" *could* have other causes in other calibrations or
  model variants; in THIS build only the fuel-demand path is live.
- Debounce/threshold cal *values* not read (Bank-2 RAM-loaded); only their roles are established.
