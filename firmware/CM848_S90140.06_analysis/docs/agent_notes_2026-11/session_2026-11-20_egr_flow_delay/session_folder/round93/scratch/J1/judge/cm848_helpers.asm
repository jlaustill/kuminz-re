=== 0x509d98
# cm848_clearJ1939InputDataErrorBit @ 0x509d98..0x509dd8  (cm848_flash2_live.bin)

/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/scripts/../CM848_S90140.06_analysis/originals/cm848_flash2_live.bin:     file format binary


Disassembly of section .data:

00509d98 <.data+0x9d98>:
  509d98:	7c 64 2e 70 	srawi   r4,r3,5
  509d9c:	39 60 00 01 	li      r11,1
  509da0:	7c 60 2e 70 	srawi   r0,r3,5
  509da4:	7c 00 01 94 	addze   r0,r0
  509da8:	1c 00 00 20 	mulli   r0,r0,32
  509dac:	7d 40 18 50 	subf    r10,r0,r3
  509db0:	7d 6b 50 30 	slw     r11,r11,r10
  509db4:	7d 63 58 f8 	not     r3,r11
  509db8:	3d 80 00 40 	lis     r12,64
  509dbc:	39 8c bd 5a 	addi    r12,r12,-17062
  509dc0:	54 8a 13 ba 	rlwinm  r10,r4,2,14,29
  509dc4:	7c 8c 52 14 	add     r4,r12,r10
  509dc8:	81 64 00 00 	lwz     r11,0(r4)
  509dcc:	7c 6b 58 38 	and     r11,r3,r11
  509dd0:	91 64 00 00 	stw     r11,0(r4)
  509dd4:	4e 80 00 20 	blr
=== 0x509dd8
# cm848_clearJ1939PedalInputTimeoutBit @ 0x509dd8..0x509e18  (cm848_flash2_live.bin)

/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/scripts/../CM848_S90140.06_analysis/originals/cm848_flash2_live.bin:     file format binary


Disassembly of section .data:

00509dd8 <.data+0x9dd8>:
  509dd8:	7c 64 2e 70 	srawi   r4,r3,5
  509ddc:	39 60 00 01 	li      r11,1
  509de0:	7c 60 2e 70 	srawi   r0,r3,5
  509de4:	7c 00 01 94 	addze   r0,r0
  509de8:	1c 00 00 20 	mulli   r0,r0,32
  509dec:	7d 40 18 50 	subf    r10,r0,r3
  509df0:	7d 6b 50 30 	slw     r11,r11,r10
  509df4:	7d 63 58 f8 	not     r3,r11
  509df8:	3d 80 00 40 	lis     r12,64
  509dfc:	39 8c bd 62 	addi    r12,r12,-17054
  509e00:	54 8a 13 ba 	rlwinm  r10,r4,2,14,29
  509e04:	7c 8c 52 14 	add     r4,r12,r10
  509e08:	81 64 00 00 	lwz     r11,0(r4)
  509e0c:	7c 6b 58 38 	and     r11,r3,r11
  509e10:	91 64 00 00 	stw     r11,0(r4)
  509e14:	4e 80 00 20 	blr
=== 0x509e18
# cm848_clearJ1939InputTimeoutBit @ 0x509e18..0x509e58  (cm848_flash2_live.bin)

/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/scripts/../CM848_S90140.06_analysis/originals/cm848_flash2_live.bin:     file format binary


Disassembly of section .data:

00509e18 <.data+0x9e18>:
  509e18:	7c 64 2e 70 	srawi   r4,r3,5
  509e1c:	39 60 00 01 	li      r11,1
  509e20:	7c 60 2e 70 	srawi   r0,r3,5
  509e24:	7c 00 01 94 	addze   r0,r0
  509e28:	1c 00 00 20 	mulli   r0,r0,32
  509e2c:	7d 40 18 50 	subf    r10,r0,r3
  509e30:	7d 6b 50 30 	slw     r11,r11,r10
  509e34:	7d 63 58 f8 	not     r3,r11
  509e38:	3d 80 00 40 	lis     r12,64
  509e3c:	39 8c bd 5e 	addi    r12,r12,-17058
  509e40:	54 8a 13 ba 	rlwinm  r10,r4,2,14,29
  509e44:	7c 8c 52 14 	add     r4,r12,r10
  509e48:	81 64 00 00 	lwz     r11,0(r4)
  509e4c:	7c 6b 58 38 	and     r11,r3,r11
  509e50:	91 64 00 00 	stw     r11,0(r4)
  509e54:	4e 80 00 20 	blr
=== 0x509e58
# cm848_anyJ1939InputDataErrorActive @ 0x509e58..0x509e98  (cm848_flash2_live.bin)

/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/scripts/../CM848_S90140.06_analysis/originals/cm848_flash2_live.bin:     file format binary


Disassembly of section .data:

00509e58 <.data+0x9e58>:
  509e58:	38 80 00 00 	li      r4,0
  509e5c:	38 a0 00 00 	li      r5,0
  509e60:	3c 60 00 40 	lis     r3,64
  509e64:	38 63 bd 5a 	addi    r3,r3,-17062
  509e68:	54 ac 10 3a 	slwi    r12,r5,2
  509e6c:	7d 83 60 2e 	lwzx    r12,r3,r12
  509e70:	2c 0c 00 00 	cmpwi   r12,0
  509e74:	41 82 00 0c 	beq     0x509e80
  509e78:	38 80 00 01 	li      r4,1
  509e7c:	48 00 00 14 	b       0x509e90
  509e80:	39 85 00 01 	addi    r12,r5,1
  509e84:	55 85 04 3e 	clrlwi  r5,r12,16
  509e88:	2c 05 00 00 	cmpwi   r5,0
  509e8c:	40 81 ff dc 	ble     0x509e68
  509e90:	7c 83 07 34 	extsh   r3,r4
  509e94:	4e 80 00 20 	blr
=== 0x509e98
# cm848_anyJ1939PedalInputTimeoutActive @ 0x509e98..0x509ed8  (cm848_flash2_live.bin)

/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/scripts/../CM848_S90140.06_analysis/originals/cm848_flash2_live.bin:     file format binary


Disassembly of section .data:

00509e98 <.data+0x9e98>:
  509e98:	38 80 00 00 	li      r4,0
  509e9c:	38 a0 00 00 	li      r5,0
  509ea0:	3c 60 00 40 	lis     r3,64
  509ea4:	38 63 bd 62 	addi    r3,r3,-17054
  509ea8:	54 ac 10 3a 	slwi    r12,r5,2
  509eac:	7d 83 60 2e 	lwzx    r12,r3,r12
  509eb0:	2c 0c 00 00 	cmpwi   r12,0
  509eb4:	41 82 00 0c 	beq     0x509ec0
  509eb8:	38 80 00 01 	li      r4,1
  509ebc:	48 00 00 14 	b       0x509ed0
  509ec0:	39 85 00 01 	addi    r12,r5,1
  509ec4:	55 85 04 3e 	clrlwi  r5,r12,16
  509ec8:	2c 05 00 00 	cmpwi   r5,0
  509ecc:	40 81 ff dc 	ble     0x509ea8
  509ed0:	7c 83 07 34 	extsh   r3,r4
  509ed4:	4e 80 00 20 	blr
=== 0x509ed8
# cm848_anyJ1939InputTimeoutActive @ 0x509ed8..0x509f18  (cm848_flash2_live.bin)

/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/scripts/../CM848_S90140.06_analysis/originals/cm848_flash2_live.bin:     file format binary


Disassembly of section .data:

00509ed8 <.data+0x9ed8>:
  509ed8:	38 80 00 00 	li      r4,0
  509edc:	38 a0 00 00 	li      r5,0
  509ee0:	3c 60 00 40 	lis     r3,64
  509ee4:	38 63 bd 5e 	addi    r3,r3,-17058
  509ee8:	54 ac 10 3a 	slwi    r12,r5,2
  509eec:	7d 83 60 2e 	lwzx    r12,r3,r12
  509ef0:	2c 0c 00 00 	cmpwi   r12,0
  509ef4:	41 82 00 0c 	beq     0x509f00
  509ef8:	38 80 00 01 	li      r4,1
  509efc:	48 00 00 14 	b       0x509f10
  509f00:	39 85 00 01 	addi    r12,r5,1
  509f04:	55 85 04 3e 	clrlwi  r5,r12,16
  509f08:	2c 05 00 00 	cmpwi   r5,0
  509f0c:	40 81 ff dc 	ble     0x509ee8
  509f10:	7c 83 07 34 	extsh   r3,r4
  509f14:	4e 80 00 20 	blr
=== 0x509f18
# cm848_setJ1939InputDataErrorBit @ 0x509f18..0x509f54  (cm848_flash2_live.bin)

/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/scripts/../CM848_S90140.06_analysis/originals/cm848_flash2_live.bin:     file format binary


Disassembly of section .data:

00509f18 <.data+0x9f18>:
  509f18:	7c 64 2e 70 	srawi   r4,r3,5
  509f1c:	39 60 00 01 	li      r11,1
  509f20:	7c 60 2e 70 	srawi   r0,r3,5
  509f24:	7c 00 01 94 	addze   r0,r0
  509f28:	1c 00 00 20 	mulli   r0,r0,32
  509f2c:	7d 40 18 50 	subf    r10,r0,r3
  509f30:	7d 63 50 30 	slw     r3,r11,r10
  509f34:	3d 80 00 40 	lis     r12,64
  509f38:	39 8c bd 5a 	addi    r12,r12,-17062
  509f3c:	54 89 13 ba 	rlwinm  r9,r4,2,14,29
  509f40:	7c 8c 4a 14 	add     r4,r12,r9
  509f44:	81 64 00 00 	lwz     r11,0(r4)
  509f48:	7c 6b 5b 78 	or      r11,r3,r11
  509f4c:	91 64 00 00 	stw     r11,0(r4)
  509f50:	4e 80 00 20 	blr
=== 0x509f54
# cm848_setJ1939PedalInputTimeoutBit @ 0x509f54..0x509f90  (cm848_flash2_live.bin)

/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/scripts/../CM848_S90140.06_analysis/originals/cm848_flash2_live.bin:     file format binary


Disassembly of section .data:

00509f54 <.data+0x9f54>:
  509f54:	7c 64 2e 70 	srawi   r4,r3,5
  509f58:	39 60 00 01 	li      r11,1
  509f5c:	7c 60 2e 70 	srawi   r0,r3,5
  509f60:	7c 00 01 94 	addze   r0,r0
  509f64:	1c 00 00 20 	mulli   r0,r0,32
  509f68:	7d 40 18 50 	subf    r10,r0,r3
  509f6c:	7d 63 50 30 	slw     r3,r11,r10
  509f70:	3d 80 00 40 	lis     r12,64
  509f74:	39 8c bd 62 	addi    r12,r12,-17054
  509f78:	54 89 13 ba 	rlwinm  r9,r4,2,14,29
  509f7c:	7c 8c 4a 14 	add     r4,r12,r9
  509f80:	81 64 00 00 	lwz     r11,0(r4)
  509f84:	7c 6b 5b 78 	or      r11,r3,r11
  509f88:	91 64 00 00 	stw     r11,0(r4)
  509f8c:	4e 80 00 20 	blr
=== 0x509f90
# cm848_setJ1939InputTimeoutBit @ 0x509f90..0x509fcc  (cm848_flash2_live.bin)

/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/scripts/../CM848_S90140.06_analysis/originals/cm848_flash2_live.bin:     file format binary


Disassembly of section .data:

00509f90 <.data+0x9f90>:
  509f90:	7c 64 2e 70 	srawi   r4,r3,5
  509f94:	39 60 00 01 	li      r11,1
  509f98:	7c 60 2e 70 	srawi   r0,r3,5
  509f9c:	7c 00 01 94 	addze   r0,r0
  509fa0:	1c 00 00 20 	mulli   r0,r0,32
  509fa4:	7d 40 18 50 	subf    r10,r0,r3
  509fa8:	7d 63 50 30 	slw     r3,r11,r10
  509fac:	3d 80 00 40 	lis     r12,64
  509fb0:	39 8c bd 5e 	addi    r12,r12,-17058
  509fb4:	54 89 13 ba 	rlwinm  r9,r4,2,14,29
  509fb8:	7c 8c 4a 14 	add     r4,r12,r9
  509fbc:	81 64 00 00 	lwz     r11,0(r4)
  509fc0:	7c 6b 5b 78 	or      r11,r3,r11
  509fc4:	91 64 00 00 	stw     r11,0(r4)
  509fc8:	4e 80 00 20 	blr
