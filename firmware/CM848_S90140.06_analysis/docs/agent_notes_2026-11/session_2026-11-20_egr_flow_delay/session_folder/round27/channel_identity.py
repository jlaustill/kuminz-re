"""Round 27: evidence for each sensor channel's identity.
- the e2m 1036 names of its high / low fault bits (from fault_bit_words_t's field comments, 'b<k> <Name>[ <DTC>]');
- the e2m records at its output / table addresses (firmware/scripts/e2m_block_addresses.py --address).
usage: channel_identity.py <firmware dir> <channel_calls.txt> <channel>..."""
import csv
import re
import subprocess
import sys

fw, calls_file, wanted = sys.argv[1], sys.argv[2], set(sys.argv[3:])
out = f"{fw}/CM848_S90140.06_analysis/output"
bits = {}
with open(f"{out}/structure_definitions.csv", newline="") as fh:
    for row in csv.reader(fh):
        if len(row) > 5 and row[0] == "fault_bit_words_t" and row[2].startswith("faults_"):
            first = int(row[2].split("_")[1])
            for k, name, rest in re.findall(r"\bb(\d+) ([A-Za-z0-9_]+)((?: [PCBU][0-9A-F]{4})?)", row[5]):
                bits[first + int(k)] = name + rest
glob = {}
with open(f"{out}/global_variables.csv", newline="") as fh:
    for row in csv.reader(fh):
        if row and row[0].startswith("0x"):
            glob[row[1]] = row[0] if row[1] else None
            if row[1] == "":
                pass


def address_of(sym):
    sym = sym.lstrip("&")
    m = re.match(r"^(?:WORD_|WORD_ARRAY_|ema_filter_state_t_|sensor_channel_state_t_|sensor_channel_config_t_)([0-9a-f]{8})$", sym)
    if m:
        return "0x" + m.group(1)
    with open(f"{out}/global_variables.csv", newline="") as fh:
        for row in csv.reader(fh):
            if len(row) > 1 and row[1] == sym:
                return row[0]
    return None


def e2m(addr):
    r = subprocess.run(["python3", f"{fw}/scripts/e2m_block_addresses.py", "--address", addr], capture_output=True,
                       text=True)
    line = (r.stdout.strip().splitlines() or [""])[-1]
    return line[:150]


for line in open(calls_file):
    m = re.match(r"ch (\S+) \((\d+)\): (.*)  <- (.*)", line.rstrip("\n"))
    if not m or m.group(2) not in wanted:
        continue
    args = [a.strip() for a in m.group(3).split(" | ")]
    # args: config state cache x y flags filter high low value default status (channel removed)
    high, low = int(args[7], 0), int(args[8], 0)
    print(f"== channel {m.group(2)}: fault bits {high} = {bits.get(high, '-')}, {low} = {bits.get(low, '-')}")
    for role, a in zip(["config", "x_axis", "y_data", "value", "default", "status"],
                       [args[0], args[3], args[4], args[9], args[10], args[11]]):
        addr = address_of(a)
        print(f"   {role:8} {a:62} {addr}  e2m: {e2m(addr) if addr else '-'}")
