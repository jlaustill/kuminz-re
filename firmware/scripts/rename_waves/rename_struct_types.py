"""Rename struct types: their structure_definitions.csv rows and every global_variables.csv type column naming
them (also T[N]); optionally name the default-labelled instance (<type>_<address>) and its member-label rows.
Usage: rename_struct_types.py <firmware_output_dir> <mapping_out.csv> OLD_TYPE=NEW_TYPE[@0xADDRESS=INSTANCE]...
Writes a mapping (address,name,old_label,kind) for reverse_names.py: the type as a token, the named instance as a
global, and the default label of every other unnamed instance (<new type>_<address> back to <old type>_<address>)."""
import csv
import re
import sys

SPEC = re.compile(r"([A-Za-z_]\w*)=([A-Za-z_]\w*)(?:@(0x[0-9a-fA-F]+)=([A-Za-z_]\w*))?")


def main():
    out, map_path = sys.argv[1:3]
    renames = []
    for spec in sys.argv[3:]:
        m = SPEC.fullmatch(spec)
        if not m:
            sys.exit(f"bad spec {spec!r}: OLD_TYPE=NEW_TYPE[@0xADDRESS=INSTANCE]")
        renames.append((m.group(1), m.group(2), int(m.group(3), 16) if m.group(3) else None, m.group(4)))
    sd_path, gv_path = f"{out}/structure_definitions.csv", f"{out}/global_variables.csv"
    sd = open(sd_path).read().split("\n")
    gv = open(gv_path).read().split("\n")
    mapping = []
    for old_t, new_t, inst_addr, new_i in renames:
        instance_addresses = set()
        n = 0
        for i, l in enumerate(sd):
            if l.startswith(old_t + ","):
                sd[i] = new_t + l[len(old_t):]
                n += 1
                a = l.split(",")[1]
                if a.startswith("0x"):
                    instance_addresses.add(int(a, 16))
        assert n > 0, f"no structure_definitions.csv rows for {old_t}"
        old_i = f"{old_t}_{inst_addr:08x}" if inst_addr is not None else None
        m = 0
        for i, l in enumerate(gv):
            p = l.split(",", 3)
            if not p[0].startswith("0x"):
                continue
            if old_i and (p[1] == old_i or p[1].startswith(old_i + ".")):
                p[1] = new_i + p[1][len(old_i):]
                m += 1
            if len(p) > 2 and re.fullmatch(rf"{re.escape(old_t)}(\[\d+\])?", p[2]):
                p[2] = new_t + p[2][len(old_t):]
                if not p[1]:
                    instance_addresses.add(int(p[0], 16))
            gv[i] = ",".join(p)
        if old_i:
            assert m >= 1, f"no instance or member-label row {old_i}"
            mapping.append((f"0x{inst_addr:08x}", new_i, old_i, "global"))
            instance_addresses.discard(inst_addr)
        mapping.append(("", new_t, old_t, "token"))
        for a in sorted(instance_addresses):
            mapping.append(("", f"{new_t}_{a:08x}", f"{old_t}_{a:08x}", "token"))
        print(f"{old_t} -> {new_t}: {n} struct rows, {m} instance / member-label rows renamed, "
              f"{len(instance_addresses)} other default-labelled instances mapped")
    open(sd_path, "w").write("\n".join(sd))
    open(gv_path, "w").write("\n".join(gv))
    with open(map_path, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["address", "name", "old_label", "kind"])
        w.writerows(mapping)


if __name__ == "__main__":
    main()
