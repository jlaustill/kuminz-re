# CM848 TPU-A / MIOS Channel Map

Derived from firmware behavior (2026-06-06): the CFSR (Channel Function Select) writes assign a
microcode **function number** to each TPU-A channel, and the functions that touch each channel's
param registers reveal its **logical owner**. The physical device on each output pin is **not**
determinable from the binary alone — see "Still blocked" below.

## How this was determined
- **CFSR function number** per channel: from `tpu_a_mcr.CFSRn` writes. CFSR0 covers ch0-3, CFSR1
  ch4-7, CFSR2 ch8-11, CFSR3 ch12-15 — 4 bits per channel. Main configurator is
  `cm848_tpu_interrupt_flag_init` @0x5283xx (assigns ch2/4/5/8/9/11/14/15); `clearModuleSyncFlag`
  sets every channel to 0xf (reset/disable); `mpc555_resetEngineTimingAccumulators` sets ch7/12/13.
- **Logical owner**: the named functions that read/write each channel's `TPUA_CHn_PARAM*`.

## TPU-A channel table

| CH | CFSR fn | Direction | Logical owner / purpose | Confidence |
|----|---------|-----------|-------------------------|------------|
| 0  | (capture) | input | **Crank position sensor** — `engine_injectionTiming_crankSyncDispatch` reads PARAM4 (captured tooth); `mpc555_updateEngineCrankState`, `injectorTimingCalculation`, hpcr sync. 42 refs. | confirmed input |
| 1  | (capture) | input | **Cam / secondary position sensor** input capture — same crank-sync readers | confirmed input |
| 2  | 7 | — | engine status timing — `cm848_updateEngineStatusTimers`, `mpc555_updateEngineStatusWord` | inferred |
| 3  | (capture) | input | sync-pulse input — `hpcr_processEngineSyncPulses`, `mpc555_updateEngineCrankState` | inferred |
| 4  | 0xa | output | cold-start-gated output — `cm848_protection_timer_init` enables/disables CH4 **and CH9** (`TPUA_CH4_PARAM0 |/& 0x8000`) by `cold_start_phase` + a standby QADC sensor check | output, device unknown |
| 5  | 0xa | output | output — `FUN_00528508` | unknown |
| 6  | 9 | output | **INJECTION TIMING** — all three `engine_injectionAngle_{computeLoadCh6,schedule_crankValid,schedule_crankInvalid}` load the angle (tooth+phase) into CH6 PARAM 0x304162 | **CONFIRMED** |
| 7  | 8 | — | engine status timing (pair with CH2) | inferred |
| 8  | 0xa | output | output (CFSR-assigned only) | unknown |
| 9  | 9 | output | injection-related — fn 9 like CH6; `tpu_channel_control` (`tpua_ch9_params_t` @0x304190) toggled with CH4. Possibly a 2nd injection event/pulse | inferred output |
| 10 | 9 | output | configured by `cm848_tpu_configuration_setup` (CH10_PARAM0) + `cm848_sensor_diagnostic_flag_update` (CFSR2) | unknown |
| 11 | 0xb | — | HPCR engine sync/timing — `hpcr_processEngineSyncPulses`, `mpc555_resetEngineTimingAccumulators` | inferred |
| 12 | 0xc | — | HPCR engine timing accumulate — same hpcr/reset owners | inferred |
| 13 | 0xc | — | HPCR engine timing | inferred |
| 14 | 0xb | output | configured from calibration by `cm848_protection_threshold_calib_check` (writes CH14 PARAM + MIOS PWM); also hpcr sync, `mpc555_updateEngineRunState` | output, device unknown |
| 15 | 0xa | output | output (CFSR-assigned only) | unknown |

**Function-number groups:** 7/8 = status timers (CH2,7); **9 = injection** (CH6 confirmed, CH9/10);
0xa = cold-start-gated outputs (CH4,5,8,15); 0xb = HPCR sync (CH11,14); 0xc = timing accumulate (CH12,13).

## MIOS MPWMSM PWM outputs (0x306000)

Four PWM submodules driven by `cm848_miosTimer16/17/18/19*` (set value, scale-by-percent, init
period). `cm848_protection_threshold_calib_check` @0x5289d4 loads all four period/pulse values from
calibration. These are PWM **actuator** outputs (typical diesel: VGT/turbo, EGR, fan, fuel/heater) —
**specific device per submodule unknown** from the binary.

## Mislabeled functions found during this mapping

| Address | Current name | What it actually does |
|---------|--------------|-----------------------|
| 0x5289d4 | `cm848_protection_threshold_calib_check` | does **no check** — loads TPU CH14/CH10 params + MIOS PWM 16-19 from calibration (output config) |
| 0x529068 | `cm848_protection_timer_init` | not a timer init — gates TPU CH4+CH9 output by `cold_start_phase` + standby QADC sensors (could be a cold-start aid, so "protection" is arguable) |
| 0x5283xx | `cm848_tpu_interrupt_flag_init` | sets CIER (so partly right) **and** is the main CFSR channel-function assigner |

(Confirmed correct by this mapping: the injection-timing renames — CH6 is unambiguously the
injection-timing channel.)

## Still blocked (the original reason these were deferred)

Mapping a channel's **microcode function number → physical device** requires the Cummins/Motorola
TPU **mask-ROM function table** (what fn 9/0xa/0xb/0xc do in this ECU's TPU microcode), the wiring
diagram/connector pinout, or a live-bench probe. None is in the firmware image. So CH4/5/8/9/14/15
and the four MIOS PWM outputs can be classified as inputs vs outputs and grouped by function, but
their specific actuator identity stays unresolved until external data is available.
