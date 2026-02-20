SBC MFS2633HMDAJAD
    MFS2633HMDC3AD
MCU S32K358GHT1MPCST

S32K358 HDQFP172
MFS2633HMDAJAD (FS26 SBC, pre-configured for S32K358)
Crystal
JTAG header
Decoupling caps per reference design
SPI connection between FS26 and S32K358 (for watchdog and status)
Every remaining pin broken out to 0.1" headers

The SPI link between the FS26 and the MCU is the only "routing matters" connection beyond power — the MCU needs to talk to the SBC for watchdog refresh and to read fault status. Everything else is just power planes and pin-to-header traces.
