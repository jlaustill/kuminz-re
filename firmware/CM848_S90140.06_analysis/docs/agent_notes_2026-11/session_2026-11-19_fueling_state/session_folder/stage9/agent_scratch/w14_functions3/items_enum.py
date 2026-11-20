"""Wave 14, functions3: the two held enum rows (bin order: 0x40c04a, then 0x40aa9a)."""

ENUM_ROWS = [
    dict(
        address="0x0040c04a",
        old="diagnostic_session_state",
        new="ram_refresh_enable",
        enum_old="DIAG_SESSION_STATE",
        enum_new="RAM_REFRESH_STATE",
        members=[
            dict(
                value=0, old="INACTIVE", new="RAM_REFRESH_DISABLED",
                comment=(
                    "RAM refresh off (development mode); the refresh pass and the EEPROM mirror reload do nothing; "
                    "stored by the reset service and temporarily by cm848_runCylinderContributionTest"
                ),
            ),
            dict(
                value=1, old="ACTIVE", new="RAM_REFRESH_ENABLED",
                comment=(
                    "RAM refresh on (the normal state); stored at start-up and power-down and by the activate services"
                ),
            ),
            dict(
                value=2, old="LOCKED_OUT", new="",
                comment=(
                    "Remove; nothing stores or tests 2 and the e2m record has no value labels"
                ),
            ),
        ],
        comment=(
            "e2m 10C7 +0 RAM_Refresh_Enable '[RREN] ENABLES COMPARE RAM TO EEPROM ALGORITHM' (HEX, word; 1 in the dump; "
            "address from the ECU's parameter ID table). 1 = RAM refresh enabled (the start-up and normal state), 0 = "
            "disabled (development mode). While enabled: the refresh pass cm848_initProtectionModule (the background loop "
            "of cm848_applicationMain) compares the sensor channel calibration block 0x3feed0-0x40a046 with ROM 0x64aea and "
            "rewrites differing words (setting fault 0 = P0606, e2m 1036 +0 RAM_Image_Word_Error, when it had to), the "
            "periodic EEPROM block read (cm848_periodicTaskSet_protection2 -> cm848_startEepromBlockRead) is copied into the "
            "RAM mirror by cm848_onEepromBlockRead, and j1939_writeDiagMemory refuses RAM "
            "writes into 0x3fd480-0x40a046 and queues EEPROM-address writes to the EEPROM. Stored 1 at start-up "
            "(cm848_initEepromDriverAndLoadMirror), by cm848_runPowerDownSequence, uds_session_state_init and the activate "
            "services; stored 0 by the reset service and, while it edits calibration words, by "
            "cm848_runCylinderContributionTest (1 again after). The supervisor chip register 46 read and the periodic "
            "supervisor configuration rewrite run only while it is 0. main_loop's psVar4 < &diagnostic_session_state is a "
            "loop-end address, not a use."
        ),
        evidence=(
            "Stores: 0 (INACTIVE) in the reset service and at the start of cm848_runCylinderContributionTest; 1 (ACTIVE) in "
            "cm848_initEepromDriverAndLoadMirror, the activate and force-activate services, cm848_runPowerDownSequence, "
            "uds_session_state_init and the end of the cylinder test; every compare is == INACTIVE, != INACTIVE or == ACTIVE "
            "and nothing stores or tests 2. e2m 10C7 +0 RAM_Refresh_Enable resolves here through the parameter ID table; dump "
            "(word) 1. Enabled: the refresh pass cm848_initProtectionModule runs, cm848_onEepromBlockRead copies the block "
            "into the mirror only under if (diagnostic_session_state != INACTIVE) (the periodic read: "
            "cm848_periodicTaskSet_protection2 -> cm848_startEepromBlockRead), j1939_writeDiagMemory refuses RAM writes "
            "into the protected window; the supervisor register 46 read and configuration rewrite need == INACTIVE. e2m "
            "fit: RREN 'ENABLES COMPARE RAM TO EEPROM ALGORITHM' is that EEPROM mirror reload; the other half is the "
            "flash block loop cm848_initProtectionModule (RAM 0x3feed0-0x40a046 against ROM 0x64aea, after the mirror end "
            "0x3feec1), whose e2m record is 10C7 +2 Powerdown_Refresh_Enable (sensor_validation_result, set to 1 by "
            "uds_session_state_init, cleared by a successful cm848_commitEepromMirrorToEeprom and read by nothing in the "
            "decompile). "
            "main_loop's psVar4 < &diagnostic_session_state is a loop-end address, not a use. A plain word flag would do "
            "(nothing differs from 0 / 1); the two-member enum keeps the compares readable."
        ),
    ),
    dict(
        address="0x0040aa9a",
        old="j1939_standby_flag",
        new="development_mode",
        enum_old="J1939_STANDBY_STATE",
        enum_new="DEVELOPMENT_MODE_STATE",
        members=[
            dict(
                value=0, old="SESSION_ACTIVE", new="DEVELOPMENT_MODE_OFF",
                comment=(
                    "Normal operation; stored by the activate services and the power-down sequence; "
                    "the register address ranges of the diagnostic memory services are refused"
                ),
            ),
            dict(
                value=1, old="STANDING_BY", new="DEVELOPMENT_MODE_ON",
                comment=(
                    "Development mode; stored only by the reset service together with the RAM refresh disabled; "
                    "the activate service needs it and the register address ranges of the diagnostic memory services open"
                ),
            ),
        ],
        comment=(
            "e2m 1328 +0 Development_Mode '[SSDVMD] RAM Refresh disabled mode indicated by config name RUN_LOC = AAh' "
            "(UNITLESS, word; 0 in the dump; address from the ECU's parameter ID table). 1 = development mode: set by the "
            "reset service (also after a PCI security key is accepted) together with diagnostic_session_state INACTIVE (RAM refresh disabled) and cal_write_mode "
            "(e2m 0010 +0 RUN_LOC) = 0xea - this build uses 0xea, not the 0xaa of the e2m text; 0 = normal: stored by the "
            "activate service, by the force-activate service (only when cal_write_mode was 0xea) and by "
            "cm848_runPowerDownSequence. Tested == STANDING_BY only: the activate service accepts only while it is 1 (else "
            "DIAG_NACK_NOT_READY), and cm848_lookupApplicationMemoryRegionType gives the register ranges 0x2fc000-0x301fff "
            "and 0x303800-0x307fff type 3 (accessible) while it is 1 and type 10 (refused) otherwise (table 0x53a33a). No "
            "J1939 broadcast is gated by it."
        ),
        evidence=(
            "Stores: 1 (STANDING_BY) only in the reset service, together with the refresh disabled and cal_write_mode = "
            "0xea; 0 (SESSION_ACTIVE) in the activate service, in the force-activate service (only when cal_write_mode == "
            "0xea) and in cm848_runPowerDownSequence; compares: the activate gate == STANDING_BY and "
            "cm848_lookupApplicationMemoryRegionType == STANDING_BY. The flash2 table at 0x53a33a (dumped) has type 3 for "
            "the register ranges 0x2fc000-0x301fff and 0x303800-0x307fff in the STANDING_BY column and 10 in the other, all "
            "other regions identical in both: an independent sign that 1 is the development state. Dump (word) 0; e2m 1328 "
            "+0 Development_Mode resolves here through the parameter ID table. e2m mismatch: it says RUN_LOC = AAh, this "
            "build writes 0xea. No J1939 broadcast depends on it, so the old 'J1939 broadcasts suppressed' / 'standing by' "
            "wording has no basis in the code. A plain word flag would do."
        ),
    ),
]
