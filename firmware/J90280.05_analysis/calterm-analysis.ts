#!/usr/bin/env npx tsx

console.log('🎯 CM550 Calterm Documentation Analysis - Mode 0 Timing Requirements');
console.log('====================================================================\n');

console.log('📋 **Key Findings from Calterm Documentation:**');
console.log('==============================================\n');

console.log('🔧 **CAM_SYNC Group - Critical Timing Parameters:**');
console.log('------------------------------------------------');
console.log('• **CSEN = 1**: Cam synchronization is ENABLED');
console.log('• **CSCDCKTP = 40°F**: Cold crank temperature threshold');
console.log('• **CSCDESTR = 125 RPM**: Engine speed limit for cold crank sync determination');
console.log('• **CSCKES = 300 RPM**: RPM above which engine is considered running (not cranking)');
console.log('• **CSCKSLAJ = 249.5 μsec**: Time constant for pulse slope comparison');
console.log('• **CSCKSLCS = 8142.5 μsec**: Time constant for pulse time comparison');
console.log('• **CSERCUMX = 25**: Max crank sync errors before fault');
console.log('• **CSERFLIH = 36**: Number of sync errors above which fueling is inhibited');
console.log('• **CSXT_1PC = 75.0%**: Value used to detect sync pulse');
console.log('• **CSXT_2PC = 85.2%**: Secondary sync pulse detection value\n');

console.log('🚀 **Engine Speed Sensor Configuration:**');
console.log('========================================');
console.log('• **ENGINE_SPEED_SENSOR_ENABLES (ESSXSNEN) = 0x001F**: Bitwise sensor enables');
console.log('• **MAIN_CONSEC_ERROR_THRESH = 5**: Threshold count at which main ESS is lost');
console.log('• **BACKUP_CONSEC_ERROR_THRESH = 200**: Threshold count at which backup ESS is lost');
console.log('• **EXTERNAL_CONSEC_ERROR_THRESH = 5**: Threshold count at which external ESS is lost');
console.log('• **EST2CY = 6**: Number of cylinders (6-cylinder engine)\n');

console.log('⚙️ **Timing Measurement Parameters:**');
console.log('====================================');
console.log('• **ESPECK01 = 30.00°**: Crank degrees between PRIMARY speed measurements');
console.log('• **ESPECK02 = 720.00°**: Crank degrees between BACKUP speed measurements');
console.log('• **ESPECM01 = 24**: Number of PRIMARY speed pulse periods measured per cam');
console.log('• **ESPECM02 = 1**: Number of BACKUP speed pulse periods measured per cam');
console.log('• **ESPECY01 = 4**: Number of PRIMARY speed pulse periods per average');
console.log('• **ESPECY02 = 1**: Number of BACKUP speed pulse periods per average');
console.log('• **ESTTIP = 3**: Teeth per period measurement\n');

console.log('🔍 **Missing Tooth Detection:**');
console.log('==============================');
console.log('• **MSTTFNEN = DISABLE**: Missing tooth found algorithm is DISABLED');
console.log('• **ESNMTTMS = 1**: Width of missing tooth gap in teeth');
console.log('• **ESNOTTCU = 34**: Correct tooth count at missing tooth');
console.log('• **ESNOTTRA = 1.453**: Tooth spacing ratio at which missing tooth is found');
console.log('• **ESPSCURS = 2**: Reset value at missed tooth for period measurement\n');

console.log('🎯 **Critical Analysis for 5.9 Cummins 60-2 Compatibility:**');
console.log('============================================================\n');

console.log('✅ **POSITIVE INDICATORS:**');
console.log('• **Cam synchronization enabled (CSEN=1)**: System designed to work with cam sensors');
console.log('• **Primary measurement = 30° intervals**: Compatible with cam-speed sensing');
console.log('• **Backup measurement = 720° (full cycle)**: Indicates cam timing capability');
console.log('• **24 pulse periods per cam**: Suggests 60-2 pattern support (58 active + 2 missing)');
console.log('• **Missing tooth detection available**: Algorithm can handle 60-2 gap detection\n');

console.log('⚠️ **CONFIGURATION REQUIREMENTS:**');
console.log('• **Missing tooth algorithm disabled**: May need enabling for 60-2 pattern');
console.log('• **Gap detection configured for 1 tooth**: 60-2 has 2-tooth gap');
console.log('• **Tooth count = 34**: Configured for different pattern, needs 58 for 60-2\n');

console.log('🔧 **Mode 0 Timing Method Assessment:**');
console.log('=====================================');
console.log('Based on firmware analysis + Calterm documentation:\n');
console.log('**Mode 0 Requirements:**');
console.log('• **Primary sensor**: Can accept cam input (30° measurement intervals)');
console.log('• **Tooth pattern**: Supports programmable tooth counts via ESNOTTCU');
console.log('• **Missing teeth**: Configurable via ESNMTTMS and ESNOTTRA');
console.log('• **Sync detection**: Advanced pulse detection (CSXT_1PC/2PC thresholds)');
console.log('• **Error handling**: Robust fault detection and recovery\n');

console.log('🎯 **5.9 Cummins Compatibility Verdict:**');
console.log('========================================');
console.log('**✅ COMPATIBLE** - Your 60-2 camshaft sensor should work with Mode 0 IF:');
console.log('1. **ESNOTTCU changed from 34 to 58** (active teeth count)');
console.log('2. **ESNMTTMS changed from 1 to 2** (missing tooth gap width)');
console.log('3. **MSTTFNEN set to ENABLE** (enable missing tooth detection)');
console.log('4. **ESNOTTRA adjusted for 60-2 pattern** (gap detection ratio)\n');

console.log('📋 **Recommended Calibration Changes:**');
console.log('=====================================');
const recommendations = [
  {
    parameter: 'ESNOTTCU',
    current: '34',
    recommended: '58',
    description: 'Active teeth count for 60-2 pattern'
  },
  {
    parameter: 'ESNMTTMS', 
    current: '1',
    recommended: '2',
    description: 'Missing tooth gap width'
  },
  {
    parameter: 'MSTTFNEN',
    current: 'DISABLE',
    recommended: 'ENABLE', 
    description: 'Enable missing tooth detection'
  },
  {
    parameter: 'ESNOTTRA',
    current: '1.453',
    recommended: '~2.0-2.5',
    description: 'Tooth spacing ratio for gap detection'
  }
];

recommendations.forEach(rec => {
  console.log(`• **${rec.parameter}**: ${rec.current} → ${rec.recommended}`);
  console.log(`  ${rec.description}`);
});

console.log('\n🔍 **Next Steps:**');
console.log('================');
console.log('1. **Backup current calibration** before making changes');
console.log('2. **Test with original cam sensor** to establish baseline');
console.log('3. **Gradually adjust parameters** starting with tooth count');
console.log('4. **Monitor sync errors** (CSERCUMX counter) during testing');
console.log('5. **Verify fueling stability** at various RPM ranges\n');

console.log('💡 **Key Insight:**');
console.log('==================');
console.log('The CM550 firmware contains **extensive 60-2 pattern support** (0x3A constants)');
console.log('and the Calterm documentation shows **configurable timing parameters** that can');
console.log('be adjusted to work with your 5.9 Cummins 60-2 camshaft sensor.');
console.log('**Mode 0 is designed for flexible sensor configurations!** 🎯');