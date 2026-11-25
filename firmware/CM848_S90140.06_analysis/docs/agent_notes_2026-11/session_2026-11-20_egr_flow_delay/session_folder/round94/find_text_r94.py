"""Round 94 (read-only): print short contexts around a phrase in a large text file (the session transcript), the last
N matches. usage: find_text_r94.py <file> <phrase> [N] [width]"""
import sys

path, phrase = sys.argv[1], sys.argv[2]
n = int(sys.argv[3]) if len(sys.argv) > 3 else 6
w = int(sys.argv[4]) if len(sys.argv) > 4 else 300
data = open(path, errors="replace").read()
hits, i = [], data.find(phrase)
while i != -1:
    hits.append(i)
    i = data.find(phrase, i + 1)
print(len(hits), "matches")
for i in hits[-n:]:
    print("...", data[max(0, i - w // 3):i + w].replace("\\n", " "), "...")
    print("----")
