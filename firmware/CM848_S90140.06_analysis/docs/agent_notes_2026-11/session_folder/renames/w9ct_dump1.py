import sys
sys.path.insert(0, '/home/linux/.claude/jobs/d55ae3c6/tmp/renames')
import w9ct_mem as M

cal = {0x3ff6ec: 'Diag_Count_Limit', 0x3ff6ee: 'Diag_Time', 0x3ff6f0: 'Pressure_Ratio_Thd',
       0x3ff6f2: 'Fault_Clear', 0x3ff6f4: 'Fault_Decrement', 0x3ff6f6: 'Fault_Increment',
       0x3ff6f8: 'Fault_Set', 0x3ff6fa: 'Filter_Constant', 0x3ff6fc: 'Global_Default',
       0x3ff6fe: 'High_Error_Limit', 0x3ff700: 'Low_Error_Limit', 0x3ff702: 'Max_Neg_Rate',
       0x3ff704: 'Max_Pos_Rate', 0x3ff706: 'Pulses_Per_Interrupt', 0x3ff708: 'Pulses_Per_Rev',
       0x3ff70a: 'Timeout', 0x3ff70c: 'Zero_Limit', 0x3ff70e: 'Configuration', 0x3ff710: 'Pad',
       0x3ff712: 'Eng_Spd_Thd', 0x3ff714: 'Rate_Limit_Thd', 0x3ff716: 'Rate_Limit_Value',
       0x3ff718: 'Envelope_Buf', 0x3ff71a: 'Sensor_Installed'}
for a, n in cal.items():
    print(hex(a), n, M.w(a), M.sw(a))
print('--- state')
st = {0x40afe6: 'Filtered_Turbo_Speed', 0x40afe8: 'Raw_Turbo_Speed(Hz)', 0x40afea: 'Fault_Count',
      0x40afec: 'Period(dword)', 0x40aff0: 'Timer', 0x40aff2: 'Unfiltered', 0x40aff4: 'Filtered_Limited',
      0x40aff6: 'Rate_Limited', 0x40aff8: 'Error_Counter', 0x40affa: 'Filtered_Limited_Max',
      0x40affc: 'First_Stage_Output', 0x40afc4: 'Turbo_Speed_Est', 0x40afc6: 'EStat',
      0x40afc8: 'TPE_Corrected_Est', 0x40afca: 'TPE_Scale?', 0x40afcc: 'Lead_unf', 0x40afce: 'Lead',
      0x40afd0: 'Filt_Eng_Spd', 0x40afd2: 'Est_Delta', 0x40afd4: 'TSE_Filtered', 0x40afd6: 'Source',
      0x40afd8: 'State', 0x40afda: 'IR_Cond', 0x40afdc: 'IR_Enable', 0x40afde: 'IR_Fault_Count',
      0x40afe0: 'Comparison', 0x40afe2: 'IR_State', 0x40afe4: 'Disabled', 0x40bdc4: 'Sensor',
      0x40bdc6: 'Default', 0x40be36: 'smoke mode', 0x3fd8ac: 'user ovr en', 0x3fd8ae: 'est test',
      0x3fd8b0: 'Override', 0x3fd8b2: 'Override_Enable', 0x40770c: 'State_Override_Val',
      0x407704: 'IR_Fault_Clear', 0x407706: 'IR_Fault_Dec', 0x407708: 'IR_Fault_Inc',
      0x40770a: 'IR_Fault_Set', 0x407298: 'cal 7298', 0x40729a: 'cal 729a', 0x3fcc06: 'cache',
      0x3fcc04: 'prev target', 0x3fcc1c: 'baro ratio', 0x3fcc00: 'period working(dw)',
      0x3fcc14: 'dw', 0x3fcc18: 'prev stage1'}
for a, n in st.items():
    print(hex(a), n, M.w(a), M.sw(a), 'dword', M.d(a))
print('tbl x', [M.w(0x40770e + 2 * i) for i in range(3)], 'tbl y', [M.w(0x407714 + 2 * i) for i in range(3)])
