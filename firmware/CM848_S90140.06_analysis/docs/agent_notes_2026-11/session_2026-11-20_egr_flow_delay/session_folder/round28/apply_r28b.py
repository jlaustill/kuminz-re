"""Round 28 stage B (types):
- can_ring_state_t._pad16 (a 'Reserved' dword at +0x10) -> transmit_ring_full_flag (byte) / receive_ring_full_flag
  (byte) / reserved_18 (word): the code reads and writes only bytes 0 and 1, as 0 / 1 flags;
- full prototypes for the two CAN transmit mailbox writers: three parameters, so the kernel call site in
  mpc555_manageCan1TransmitBuffer shows its frame pointer (it rendered with two arguments). Idempotent.
usage: apply_r28b.py <repo>"""
import os
import sys

out = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
sd = os.path.join(out, "structure_definitions.csv")
t = open(sd).read()
old = "can_ring_state_t,0x003024c6,_pad16,dword,4,Reserved,,verified"
new = "\n".join([
    "can_ring_state_t,0x003024c6,transmit_ring_full_flag,byte,1,1 = the transmit ring is full: mpc555_canTransmitQueuePush "
    "sets it when its write pointer reaches the read pointer (and returns 4 while it is set); "
    "mpc555_manageCan1TransmitBuffer clears it after sending a frame (was _pad16 byte 0; PR #53 round 28),,verified",
    "can_ring_state_t,0x003024c6,receive_ring_full_flag,byte,1,1 = the receive ring is full: "
    "mpc555_processCanReceiveBuffer sets it when its write pointer reaches the read pointer; "
    "mpc555_dispatchCanMessageHandlers clears it (was _pad16 byte 1; PR #53 round 28),,verified",
    "can_ring_state_t,0x003024c6,reserved_18,word,2,No users (bytes 2-3 of the old _pad16),,verified"])
if new not in t:
    assert t.count(old) == 1, t.count(old)
    open(sd, "w").write(t.replace(old, new))
fd = os.path.join(out, "function_definitions.csv")
lines = open(fd).read().split("\n")
PROTO = []
for address, name, who in (("0x00004f2c", "cm848_writeBootKernelCanTxMailbox", "the boot kernel's copy"),
                           ("0x00053b28", "cm848_writeCanControllerTxMailbox", "the application's copy")):
    PROTO += [
        f"{address},{name},0,can_module,undefined4,The TouCAN module registers (callers pass &toucan_a); buffer n - 1 "
        f"starts at +0x70 + 16 x n ({who}; PR #53 round 28)",
        f"{address},{name},1,mailbox_number,int,The message buffer number + 1 (callers pass their mailbox index & 0xff)",
        f"{address},{name},2,frame_words,word*,The frame: identifier high / low and data bytes 0-7 (6 halfwords)"]
if PROTO[0] not in lines:
    assert not any(l.startswith(("0x00004f2c,", "0x00053b28,")) for l in lines)
    lines += ["# CAN transmit mailbox writers (PR #53 round 28)"] + PROTO
    open(fd, "w").write("\n".join(lines).rstrip("\n") + "\n")
print("stage B applied")
