"""Round 84 stage B2 (CM550). Idempotent; keeps line endings. usage: apply_r84b2.py <repo>
function_definitions.csv had an old prototype row for the Huffman tree builder on the address of its boot block image
copy (0x2C834). Stage B removed that copy as a function, so the build warned "No function at 0x2c834". The row moves to
the original at 0x3640 (same place in the file's Huffman section): cm550_huffmanTreeBuilder's only parameter is the base of the 0xC0C-byte tree node buffer it fills
(it writes tree_buffer + 0xc06), as the row's comment says."""
import os
import sys

repo = os.path.abspath(sys.argv[1])
D5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/function_definitions.csv")
d = open(D5, newline="").read()
old = "0x0002c834,huffmanTreeBuilder,0,tree_buffer,int,Pointer to huffman tree node buffer (3KB)"
new = ("0x00003640,cm550_huffmanTreeBuilder,0,tree_buffer,int,Pointer to huffman tree node buffer (3KB) (was on 0x2C834 - "
       "the boot block image's copy - until PR #53 round 84)")
if new not in d:
    assert d.count(old) == 1, d.count(old)
    d = d.replace(old, new)
    open(D5, "w", newline="").write(d)
print("round 84 stage B2 applied")
