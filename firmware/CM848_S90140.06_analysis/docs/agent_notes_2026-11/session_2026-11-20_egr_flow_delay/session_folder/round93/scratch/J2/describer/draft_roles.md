DRAFT (describer J2) - one line per function; filled as verification proceeds

0x1fdc0  cm550_countJ1922ControlMode? -> J1922 monitor counter (bit 0x80): mode 1 speed / 2 torque / 3 limit: total count
         0x804164 + per-mode count 0x804170 / 0x804176 / 0x80416a + stamps (key_on_hour_meter) 0x804172 / 0x804178 /
         0x80416c + 0x804166.  CM848: none (no reader of bits 7 / 8).  Sibling 0x1fd6c clears them (bit 0x100).
0x1ff38  cm550_runJ1939PeriodicTransmitQueues (counterpart of CM848 0x538d3c, which adds the DM13 bits)
0x212b2  mc68k_dispatchJ1939ReceivedMessages (counterpart of CM848 0x538ef4)
0x2142c  endRetarderShiftAssistAboveFuelDemandLimit (twin of CM848 0x50aec0; odd-phase set vs group A)
0x216c6  handleJ1939WriteByParameterIdLongLengthService (twin of CM848 0x50b298) service 0x45
0x21778  handleJ1939WriteByParameterIdLongOffsetService (twin of CM848 0x50b38c) service 0x49
0x21872  registerJ1939MemoryWriteServices (twin of CM848 0x50b4d8)
0x21920  cm550_buildJ1939LampStatusByte (counterpart of CM848 0x50b5b4)
0x21f4e  storeJ1939ControlSessionInHistoryTable (twin of CM848 0x50be6c)
0x21fac  startJ1939ControlSession (twin of CM848 0x50beec)
0x22070  trackJ1939ControlSessions (twin of CM848 0x50bff4)
0x231da  cm550_resetEngineTsc1Request? (counterpart of cm848_runTsc1LostManagement's reset half)
0x23216  resetEngineRetarderTsc1Request (twin of CM848 0x27118)
0x23244  cm550_runJ1939PowertrainControlTimeouts (counterpart of CM848 0x2715c)
helpers: 0x21642 writeJ1939DiagnosticMemoryByParameterId (twin 0x50b1b8); 0x238ac addEngineTsc1IgnoredRequestEntry
         (twin? 5 vs 10); 0x238ec cm550_addRetarderTsc1IgnoredRequestEntry (counterpart: 4-byte entries, 1 argument)
