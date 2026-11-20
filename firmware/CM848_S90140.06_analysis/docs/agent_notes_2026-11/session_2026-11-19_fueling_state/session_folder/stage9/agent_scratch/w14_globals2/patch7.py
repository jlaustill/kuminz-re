src = open("/tmp/w14_globals2/spec_data_a.py").read()
old1 = "xref: only these two accesses; it is a fueling quantity, not a timing."
new1 = "xref_addr: 1 read / 1 write, both in cm848_selectFinalFueling; it is a fueling quantity, not a timing."
assert old1 in src
src = src.replace(old1, new1)
old2 = "to build protection_mode_request_bit once and then sets it to 1; no other access."
new2 = "to build protection_mode_request_bit once and then sets it to 1; xref_addr: 1 read / 1 write, both in that function."
assert old2 in src
src = src.replace(old2, new2)
open("/tmp/w14_globals2/spec_data_a.py", "w").write(src)
print("ok")
