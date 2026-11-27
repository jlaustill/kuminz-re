"""Round 75 closing checks: the CM848 / CM550 _cal audits and the header compile checks, printed in one place.
usage: closing_checks_r75.py <repo>"""
import os
import subprocess
import sys

firmware = os.path.join(os.path.abspath(sys.argv[1]), "firmware")
for fw, tag in (("CM848_S90140.06_analysis", "cm848"), ("CM550_J90350.00_analysis", "cm550")):
    audit = subprocess.run([sys.executable, "scripts/audit_cal_suffixes.py", f"{fw}/output/global_variables.csv",
                            "--firmware", tag], cwd=firmware, capture_output=True, text=True).stdout
    summary = [line for line in audit.splitlines() if line.startswith("Summary:")]
    gpp = subprocess.run(["g++", "-fsyntax-only", "-std=c++17", "-I", f"{fw}/output",
                          "scripts/rename_waves/hdr_check.cpp"], cwd=firmware, capture_output=True, text=True)
    errors = gpp.stderr.count("error")
    print(f"{tag}: {summary[0] if summary else 'no audit summary'}; header errors {errors}")
