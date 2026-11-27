# R1 describer notes (CM550 low speed governor lsg globals)
Started 2026-11-25. Fresh run (folder was empty).

## Functions in scope
- cm550_runLowSpeedGovernor 0x25b1c
- cm550_presetLowSpeedGovernorIntegrator 0x25a34
- cm550_presetLowSpeedGovernorSpeedError 0x25ff2
- cm550_initializeLowSpeedGovernor 0x26078
- cm550_calculateLowSpeedGovernorColdIdleSpeed 0x26616
- cm550_initializeLowSpeedGovernorIdleAdjustment 0x2658c

## Findings
- 0x80a90e lsg_exit_timer_active_flag -> alpha_low_speed_governor_timer_active_flag (word). No e2m record. calculateAlphaLowSpeedGovernorResult 0xc4b2 (twin of CM848 0xe248): move.w #1,(a0) when final_fueling_state=11 or detected flag=1 (reload timer), cmpi.w #1 + count timer down, clr.w (a0) when timer 0 -> returns 1. calculateAlpha 0xc354 sets 1 while STOPPED/CRANKING/JUMP_START; cm550_initializeAlpha 0x1dd12 clr.w. CM848 alpha_low_speed_governor_timer_active_flag 0x3fa0da (no e2m either).
- 0x80a910 trace_the_time... -> alpha_low_speed_governor_timer (word). e2m 104A +18 APLSTR; CM848 104A +16 [APLSTR] alpha_low_speed_governor_timer 0x40a17e. Reloaded from 0x807aae, subq.w #1 per alpha pass (0xc4f4).
- 0x807aae time_that_must_expire... -> low_speed_governor_alpha_timeout (word). e2m 104B +E APLSTMTR; CM848 104B +14 [APLSTMTR] low_speed_governor_alpha_timeout 0x5be6e. Only readers: 0xc35c (calculateAlpha reload at stop/crank) and 0xc4da (reload in calculateAlphaLowSpeedGovernorResult).
- runLowSpeedGovernor disassembly 0x25b1c-0x25ff0 checked; decompile matches (see body). TSC1: tst.w 0x80da50 (tsc1_override_control_mode) -> LSRF = LSAJRFES = 0x808342 (LSMNRF).
- 0x265e6 cm550_epsRpmTargetModeChecker = TWIN of CM848 0x28b38 cm848_selectLowSpeedGovernorTsc1GainSet: tst.w JCEGMD 0x80da50 (10E8 +4, same record as CM848 0x40adf8), andi.l #0x8000 algorithm_enable_flags_1_cal (LSJCGNEN, CM848 same bit), LSFNGNST(10ED +8)=4, ptr 0x80dada = 0x808334 (10EB +0), return 1; else 0. Called by the gain loader; result feeds the override selector (same as CM848). Shared name selectLowSpeedGovernorTsc1GainSet.
- 0x26272 cm550_epsOverrideChecker = TWIN of CM848 0x289d0 cm848_selectLowSpeedGovernorOverrideGainSet: arg!=0 -> 1; LSOVGNST(10ED +A)==0 -> 0; LSFNGNST=LSOVGNST; ptr=0x80dad0 (10ED +C); 1. Shared name selectLowSpeedGovernorOverrideGainSet.
- 0x2629e cm550_epsControlModeSelector = COUNTERPART of cm848_loadLowSpeedGovernorGainSet 0x28a14: CM550 first jsr 0x2609c (aggressive logic, CM848 runs it as its own task), loads 3 words (P/I/D) from (a2),(2,a2),(4,a2) into 0x80dac4/6/8; CM848 4 words (+jerk). -> cm550_loadLowSpeedGovernorGainSet.
- 0x26308 cm550_epsControlModeInit = COUNTERPART of cm848_initializeLowSpeedGovernorGainSelection: 0x2626a (clr 0x801a76 only; CM848 reset sets 3 vars), clr LSUSGNST, copy 3-word default set 0x808314 -> override set 0x80dad0 (CM848 4 words). -> cm550_initializeLowSpeedGovernorGainSelection.
- 0x2595a cm550_governorFuelPidController: same steps as CM848 0x27d38 (steady lookup if factor!=0 at (LSAJRFES,400) + clamp helper, transient if <0x4000, select 0x4000/0/blend >>14) BUT CM550 blend unsigned + final clamp 0..0x1700 (CM848 none) -> near twin, counterpart by the strict rule: cm550_calculateLowSpeedGovernorReferenceMaximumFuelQuantity.
- gain set: 3 words P/I/D read via pointer 0x80dada (move.l): default 0x808314, aggressive 0x808230 (10EE +12), middle 0x80832c, high 0x808326, J1939 0x808334 (10EB), override 0x80dad0 (10ED +C). 0x80dad6 = requested set pointer (no row; CM848 low_speed_governor_requested_gain_set_pointer).
- 0x803b9e LSBPRFES 0008 +2 = CM848 same block/offset/mnemonic low_speed_governor_base_reference_speed_cal; EEPROM -> keep _cal. users 0x26474 idle adjust, 0x28936 start-up LSRF=it, 0xfb26 torque curve band (identical to CM848 23010).
- 0x80817c LSRFESDC 1104 +1E = CM848 same block/offset low_speed_governor_reference_speed_delta (0x5c366); torque curve band check in 0xfb26 same as CM848.
- 0x807bf2 LSRFOF02 11A3 +0: NO code reader in dumped ROM (only param-ID table 0x360b4; no base+disp access found).

## Row decisions (evidence checked in disassembly)
- 0x803b9e -> low_speed_governor_base_reference_speed_cal word (CM848 0008 +2 same)
- 0x803fca LSMNRFTN 131E +2 -> low_speed_governor_minimum_idle_speed_trim_cal word (EEPROM; bcc unsigned at 0x265ca; lower limit of operator idle adjustment = it - LSBPRFES in 0x26474; raised to >= LSMNRF at start-up 0x2658c). No CM848 record.
- 0x803fcc LSMXRFTN 131E +4 -> low_speed_governor_maximum_idle_speed_trim_cal word (bls at 0x265da; lowered to <= LSMXRF 0x808344).
- 0x805f0a LSICBKRF 1073 +0 -> low_speed_governor_saved_operator_idle_adjustment i16 (outside EEPROM image -> no _cal; 0x26474 stores the operator adjustment when idle_speed_save_enable else 0; start-up restores 0x801a82 from it).
- 0x807aae -> low_speed_governor_alpha_timeout word; 0x80a910 -> alpha_low_speed_governor_timer word; 0x80a90e -> alpha_low_speed_governor_timer_active_flag word
- 0x80817c -> low_speed_governor_reference_speed_delta word
- 0x808236 LSMXFLOF 1064+0 -> low_speed_governor_fueling_clamp_maximum_offset i16 (CM848 1064 +0 same)
- 0x808238 LSMNLMFL 1064+2 -> low_speed_governor_fueling_clamp_minimum word (unsigned cmp.l after moveq #0)
- 0x80823a LSMXPZOF 1064+4 -> low_speed_governor_integrator_preset_maximum_offset i16
- 0x808242 LSFTMX 1064+C -> low_speed_governor_filtered_error_maximum i16 (CM848 14EF +4 [LSFTMX] 0x5c4b2)
- 0x808244 LSFTMN 1064+E -> low_speed_governor_filtered_error_minimum i16 (CM848 14EF +6)
- 0x808246 LSMXITOF 1064+10 -> low_speed_governor_integrator_clamp_maximum_offset i16 (CM848 1064 +8 [LSMXITOF])
- 0x80824c LSITRSES 1064+16 -> low_speed_governor_reset_speed_offset i16 (CM848 1064 +E)
- 0x80824e LSITRSFL 1064+18 -> low_speed_governor_reset_fueling word (bcc unsigned; CM848 1064 +10)
- 0x808250 LSDEITGN / 0x808252 LSDEPPGN 'blank spot after removal of LSG_DB_INT/PROP_GAIN': no code access at all -> record-only names
- 0x808256 LSRFESUL 1064+20 -> low_speed_governor_adjusted_reference_speed_maximum word (bls 0x25b8a; limit of LSAJRFES in the operator path only)
- 0x80825c LSDVFTCF 1064+26 -> low_speed_governor_derivative_filter_coefficient i16 (muls.w 0x25d5c, >>5; CM848 1064 +12 same math)
- 0x80825e/60/62 LSDVAJEN/LSPPAJEN/LSITAJEN: no code access in dumped ROM -> record-only enable names
- 0x808266 LSMXDVFL 1064+30 -> low_speed_governor_derivative_term_maximum i16 (ext.l/neg.l; CM848 1064 +1E LSG_Derivative_Max same role)
- 0x808268 LSPP02GN -> low_speed_governor_proportional_gain_2 i16; 0x80826a LSDV02GN -> low_speed_governor_derivative_gain_2 i16 (no CM848)
- 0x808334/6/8 LSJCPPGN/ITGN/DVGN 10EB -> J1939 (TSC1) gain set, 3 words, only the address is taken (move.l #0x808334 at 0x26604); all signed records (S)
- 0x808340 LSCIRMRT 1066+6 -> low_speed_governor_cold_idle_ramp_rate word (bls 0x266b2)
- 0x808342 LSMNRF 1066+8 -> low_speed_governor_minimum_idle_speed word (CM848 14EE +1E [LSMNRF]); TSC1 reference; start-up floor of trim; PGN 65251 payload byte 0x18 = /80 (0x33344)
- 0x80dac4 LSPPGN -> low_speed_governor_proportional_gain i16
- 0x80daca LSUSGNST -> low_speed_governor_user_gain_state word; 0x80dacc LSFNGNST -> low_speed_governor_final_gain_state word
- 0x80dad0/2/4 LSAPPPGN/ITGN/DVGN 10ED +C.. -> override gain set (3 words; init copy of default set at 0x26324-0x26334)
- 0x80dada -> low_speed_governor_gain_set_pointer (4-byte pointer, move.l)
- 0x80dade LSFL -> low_speed_governor_fueling_working word (CM848 1065 +0 [LSFL]); CM550 has no 11A4 +8 (CM848 low_speed_governor_fueling) record
- 0x80dae0 LSER -> low_speed_governor_filtered_speed_error i16
- 0x80dae4 LSDVFL -> low_speed_governor_derivative_term i16
- 0x80dae8 LSMXLMFL -> low_speed_governor_fueling_clamp_maximum word
- 0x80daea LSMXITFL -> low_speed_governor_integrator_clamp_maximum i16 (ext.l reads)
- 0x80daec LSMXITPZ -> low_speed_governor_integrator_preset_maximum i16 (ext.l 0x25ad6)
- 0x80daee LSAJRFES -> low_speed_governor_adjusted_reference_speed word
- 0x80daf0/2 LSDPGN01/02, 0x80daf8/a/c LSPPAJGN/LSDVAJGN/LSITAJGN: no code access in dumped ROM
- 0x80daf6 LSEXFL -> low_speed_governor_active_flag word
- 0x80dafe LSDV02FL -> low_speed_governor_derivative_term_2 i16; 0x80db00 LSPP02FL -> low_speed_governor_proportional_term_2 i16
- 0x80db02 LSRF -> low_speed_governor_reference_speed word (CM848 struct field low_speed_governor_reference.reference_speed)
- 0x80db06 LSDSRFRP -> low_speed_governor_desired_reference_speed word (CM848 1496 +2 [LSDSRFRP])

## Function verdicts
- 0x25b1c cm550_runLowSpeedGovernor keep (counterpart of cm848_runLowSpeedGovernor + cm848_calculateLowSpeedGovernorErrorTerms)
- 0x25a34 cm550_presetLowSpeedGovernorIntegrator keep (counterpart)
- 0x25ff2 cm550_presetLowSpeedGovernorSpeedError keep; NO caller / pointer in dumped ROM
- 0x26078 cm550_initializeLowSpeedGovernor keep (counterpart of cm848_initializeLowSpeedGovernorParameters)
- 0x26616 cm550_calculateLowSpeedGovernorColdIdleSpeed keep
- 0x2658c cm550_initializeLowSpeedGovernorIdleAdjustment keep
- 0x2595a -> cm550_calculateLowSpeedGovernorReferenceMaximumFuelQuantity (counterpart, near twin)
- 0x2629e -> cm550_loadLowSpeedGovernorGainSet (counterpart)
- 0x265e6 -> selectLowSpeedGovernorTsc1GainSet (TWIN, both rows)
- 0x26272 -> selectLowSpeedGovernorOverrideGainSet (TWIN, both rows)
- 0x26308 -> cm550_initializeLowSpeedGovernorGainSelection (counterpart)
- 0x2609c -> cm550_updateLowSpeedGovernorAggressiveGainLogic (counterpart; CM848 has run timer, coolant, tool-state conditions; CM550 uses rpm - previous rpm (0x801a78) instead of engine acceleration; runs inside the gain loader)
- 0x26340 -> cm550_selectLowSpeedGovernorGearGainSet (counterpart; CM550 adds out-of-gear GROGSS 0x80a9d4 reset, no gain adjustment inhibit flag, no reset outside LSG state)
- 0x2626a -> cm550_resetLowSpeedGovernorAggressiveGainLogic (counterpart; only clr 0x801a76 latch)
- 0x26252 -> cm550_resetLowSpeedGovernorAggressiveGainSettledCounts (0x801a78 = rpm, clr 0x801a7a / 0x801a7c)
- 0x26462 -> cm550_initializeLowSpeedGovernorGearGainLogic (clr gear gain timer 0x801a7e, VSRRAXRA 0x80a9f8 = VSRRAXRL 0x803d40; only other user of 0x80a9f8 is the gear gain logic at 0x263b4) - NOT oil pressure
- 0x262fa -> cm550_resetLowSpeedGovernorGainLogicCounters (calls 0x26252 + 0x26462; only caller 0x25ff2)
- 0x26474 -> cm550_updateLowSpeedGovernorIdleAdjustment (operator idle inc/dec switches 16 bit 0x20/0x40, LSDSRFRP = adjustment + LSBPRFES, LSICBKRF save)

## Gain set struct proposal
- six 3-word P/I/D sets read via pointer 0x80dada (+0/+2/+4): new type cm550_low_speed_governor_gain_set_t (CM848's low_speed_governor_gain_set_t has a 4th jerk word, so it does not fit). 0x808334 -> j1939_low_speed_governor_gain_set, 0x80dad0 -> low_speed_governor_override_gain_set (CM848 names for 10EB +0 / 10ED +C); flat fallback *_proportional_gain / *_integral_gain / *_derivative_gain.
## Dump values (RAM): LSBPRFES 6400, LSMNRFTN 5600, LSMXRFTN 7000, LSICBKRF 600, LSDSRFRP 7000 = LSRF; pointer 0x80dada = 0x00808230 (aggressive set), LSUSGNST = LSFNGNST = 1, LSPPGN 530; LSER 7000 (engine stopped).
