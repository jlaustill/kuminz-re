"""Round 85 stage B (CM550): the Huffman tree node struct applied; the flash erase result enum. Idempotent; keeps line endings (structure_definitions.csv is
CRLF).  usage: apply_r85b.py <repo>
- cm550_huffmanTreeBuilder fills an array of 6-byte nodes: +0 the weight (a leaf starts with its symbol's count from the
  byte table at ROM 0x12A - the end symbol 0x100 starts at 1 - and an internal node holds the sum of its two children,
  which are then zeroed), +2 and +4 the child node indexes. cm550_huffmanDecompress walks from start_node: on a 0 bit
  it moves to the +2 child, on a 1 bit to the +4 child, until the node index is 0x100 or below (a leaf = the symbol).
  Node 0x201 is the builder's sentinel (weight 0xffff).
- cm550_huffmanDecompressMain clears 513 nodes (0x603 words) of a stack array, builds the tree in it and decodes.
- FLASH_ERASE_RESULT: the erase routine's 0 / 1 / 2 result, which cm550_flashEraseFromRam returns from its RAM copy."""
import os
import sys

repo = os.path.abspath(sys.argv[1])
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
S5, D5, L5 = (os.path.join(O5, n) for n in ("structure_definitions.csv", "function_definitions.csv", "local_variables.csv"))
R = "PR #53 round 85"

# The type already exists (huffman_tree_node_t: frequency / left_child / right_child, and huffman_tree_t, since
# commit 7fc4f336) but nothing used it, so this stage applies it instead of defining a new one.
assert "huffman_tree_node_t,,frequency,word,2," in open(S5, newline="").read()

d = open(D5, newline="").read()
edits = [
    ("0x00003640,cm550_huffmanTreeBuilder,0,tree_buffer,int,",
     "0x00003640,cm550_huffmanTreeBuilder,0,tree_buffer,huffman_tree_node_t*,"),
    ("0x00003792,huffmanDecompress,0,tree_buffer,int,", "0x00003792,cm550_huffmanDecompress,0,tree_buffer,huffman_tree_node_t*,"),
    ("0x00003792,huffmanDecompress,1,start_node,", "0x00003792,cm550_huffmanDecompress,1,start_node,"),
]
for old, new in edits:
    if new not in d:
        assert d.count(old) == 1, (old, d.count(old))
        d = d.replace(old, new)
open(D5, "w", newline="").write(d)

lv = open(L5, newline="").read()
leol = "\r\n" if "\r\n" in lv else "\n"
row = ("0x00003836,cm550_huffmanDecompressMain,local_c0a,tree_nodes,huffman_tree_node_t[513],The tree node array: "
       f"cleared here (513 nodes) - then built by cm550_huffmanTreeBuilder and walked by cm550_huffmanDecompress ({R})")
if "0x00003836,cm550_huffmanDecompressMain,local_c0a," not in lv:
    lv = lv.rstrip("\r\n") + leol + row + leol
    open(L5, "w", newline="").write(lv)
E5 = os.path.join(O5, "enums.csv")
e = open(E5, newline="").read()
if "FLASH_ERASE_RESULT," not in e:
    rows = [
        f"FLASH_ERASE_RESULT,0,FLASH_ERASE_DONE,The block is erased: status bit 7 (ready) without the erase error bit ({R}),4",
        "FLASH_ERASE_RESULT,1,FLASH_ERASE_FAILED,The erase error bit (status bit 5) or no ready bit after 40000 status reads"
        f" ({R}),4",
        "FLASH_ERASE_RESULT,2,FLASH_ERASE_SUSPENDED,Suspended with 0xB0B0: the suspend check is on and the chip select 2"
        f" device's input bit 0 read 1 on 4 consecutive reads ({R}),4",
    ]
    e = e.rstrip("\n") + "\n" + "\n".join(rows) + "\n"
    open(E5, "w", newline="").write(e)
d = open(D5, newline="").read()
old_ret = "0x0001c484,cm550_flashEraseFromRam,return,,int,"
new_ret = "0x0001c484,cm550_flashEraseFromRam,return,,FLASH_ERASE_RESULT,"
if new_ret not in d:
    assert d.count(old_ret) == 1
    d = d.replace(old_ret, new_ret)
row = ("0x0001c31a,mc68k_flashEraseBlock,return,,FLASH_ERASE_RESULT,The erase result - cm550_flashEraseFromRam returns it from "
       f"the RAM copy ({R})")
if "0x0001c31a,mc68k_flashEraseBlock,return," not in d:
    anchor = "0x0001c484,cm550_flashEraseFromRam,0,block_address,"
    assert d.count(anchor) == 1
    d = d.replace(anchor, row + "\n" + anchor)
open(D5, "w", newline="").write(d)
print("round 85 stage B applied")
