"""Round 20 stage C, part 3 (after the first proof run): the proof found word 11 read as DAT_003fd5b2 (& 8 =
J1939_Communication_Enable, in cm848_runJ1939PeriodicTransmitQueues and cm848_dispatchJ1939ReceivedMessages) - the
'no reader' check had only searched names - and the CRC scan starts at DAT_003fd59a, the e2m 106B +0 table length word.
Fixes word 11's note, adds the 0x3fd59a row, and adds both DAT_ labels to the map. usage: apply_r20c3.py <repo> <map>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
gp = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
lines = open(gp).read().split("\n")
k = [i for i, l in enumerate(lines) if l.startswith("0x003fd5b2,algorithm_enable_flags_11_cal,word,")]
assert len(k) == 1 and lines[k[0]].endswith(". No reader in this build")
lines[k[0]] = lines[k[0]][:-len(" No reader in this build")] + (
    " Bit 3 (0x8 J1939_Communication_Enable) gates the J1939 transmit queues (cm848_runJ1939PeriodicTransmitQueues) "
    "and the receive dispatch (cm848_dispatchJ1939ReceivedMessages); clear on this truck (0x0000 in the dump), the "
    "other bits have no reader")
assert not any(l.startswith("0x003fd59a,") for l in lines)
row = ("0x003fd59a,algorithm_enable_flags_table_length_cal,word,Algorithm enable flags table length (e2m 106B +0 "
       "Software_AENBLFLG '[AENBLFLG] LENGTH_OF_ALG_ENABLE_FLAGS_TABLE', EEPROM 0x118): the first word of the 90-byte "
       "CRC-guarded EEPROM block 0x118-0x171 (this word + flag words 0-43); cm848_verifyCalibrationAndCodeCrc starts "
       "its scan at its address. 0x0046 (70) in the dump, which matches neither the 90 bytes nor the 44 words; no code "
       "reads it as a length")
i = max(j for j, l in enumerate(lines) if l.startswith("0x") and int(l[:10], 16) < 0x3fd59a)
lines.insert(i + 1, row)
open(gp, "w").write("\n".join(lines))
with open(map_path, "a") as fh:
    fh.write("0x003fd5b2,algorithm_enable_flags_11_cal,DAT_003fd5b2,global\n"
             "0x003fd59a,algorithm_enable_flags_table_length_cal,DAT_003fd59a,global\n")
print("word 11 note fixed, 0x3fd59a row added, 2 map rows")
