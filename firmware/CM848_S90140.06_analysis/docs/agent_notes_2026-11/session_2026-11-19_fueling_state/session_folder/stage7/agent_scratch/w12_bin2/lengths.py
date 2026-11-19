import sys

sys.path.insert(0, "/tmp/w12_bin2")
from records import RECORDS  # noqa: E402

for i, r in enumerate(RECORDS):
    c = len(r["comment"].replace("{raw}", "00000").replace("{eng}", "0.0 mm3"))
    e = len(r["evidence"].replace("{raw}", "00000").replace("{eng}", "0.0 mm3"))
    flag = "  <-- comment over 400" if c > 400 else ""
    print(f"#{i}: comment {c} evidence {e}{flag}")
