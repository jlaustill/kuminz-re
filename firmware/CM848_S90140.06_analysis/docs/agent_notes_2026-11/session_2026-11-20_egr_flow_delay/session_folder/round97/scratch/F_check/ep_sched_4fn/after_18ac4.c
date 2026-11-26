//

/* The engine protection restart examination before cranking (e2m 10B1 +10 EPPKSO 'EPF shutdown
   engine command from restart examine before cranking'), run once at start-up (jsr at 0x28738 in
   mc68k_applicationMain, right after cm550_initializeEngineProtection). It acts when engine
   protection, its shutdown and its restart are enabled (EPEN / EPSOEN / EPRYEN), a shutdown channel
   is recorded (engine_protection_active_fault_index, EPSOAE, not 255 and not 3 = oil pressure), and
   the consecutive shutdown count (EPSOCU) is at or above
   max_number_of_shutdowns_before_restart_is_not_allowed (EPSOMXLM). If that channel's shutdown and
   restart bits (112 + 4n + 2 / + 3) are set and its input is still past the fueling (configuration
   flag 0x1) or engine speed (0x2) threshold, it sets the channel's precrank_error (EP??PKER) and
   engine_protection_precrank_shutdown_command_flag; processDiagnosticLimitStatus turns that into
   the shutdown command. CM848's counterpart runs every scheduler pass while CRANKING and exempts
   channel 4 (was cm550_diagnosticProtectionEvaluator). (was cm550_diagnosticProtectionEvaluator; PR
   #53 round 97) */

void cm550_examineEngineProtectionBeforeCranking(void)

{
  ushort uVar1;
  int iVar2;
  word wVar3;
  engine_protection_channel_configuration_t *configuration;
  
  if (((((algorithm_enable_flags_2_cal.engine_protection_enable != 0) &&
        (algorithm_enable_flags_2_cal.engine_protection_shutdown_enable != 0)) &&
       (algorithm_enable_flags_2_cal.engine_protection_restart_enable != 0)) &&
      ((engine_protection_active_fault_index != 0xff && (engine_protection_active_fault_index != 3))
      )) && (max_number_of_shutdowns_before_restart_is_not_allowed_0_255 <=
             engine_protection_consecutive_shutdown_count)) {
    configuration =
         engine_protection_channel_configuration_table + engine_protection_active_fault_index;
    iVar2 = (int)engine_protection_active_fault_index;
    uVar1 = engine_protection_active_fault_index * 4 + 0x70;
    if ((((uint)(&algorithm_enable_flags_0_cal)[(short)((int)(uVar1 + 2) >> 4)] &
         1 << (uVar1 + 2) % 0x10) != 0) &&
       (((uint)(&algorithm_enable_flags_0_cal)[(short)((int)(uVar1 + 3) >> 4)] &
        1 << (uVar1 + 3) % 0x10) != 0)) {
      uVar1 = configuration->configuration_flags;
      if ((uVar1 & 1) != 0) {
        wVar3 = cm550_isEngineProtectionInputPastThreshold
                          (configuration,engine_protection_channel_state_table + iVar2,0,0);
        if (wVar3 != 0) {
          engine_protection_channel_state_table[iVar2].precrank_error = 1;
          engine_protection_precrank_shutdown_command_flag = 1;
        }
      }
      if ((uVar1 & 2) != 0) {
        wVar3 = cm550_isEngineProtectionInputPastThreshold
                          (configuration,engine_protection_channel_state_table + iVar2,1,0);
        if (wVar3 != 0) {
          engine_protection_channel_state_table[iVar2].precrank_error = 1;
          engine_protection_precrank_shutdown_command_flag = 1;
        }
      }
    }
  }
  return;
}



//
