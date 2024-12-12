from collections import defaultdict
import sys
def input_line(): return sys.stdin.readline().strip()
def input_map(f): return map(f, input_line().split())
s = defaultdict(int)
for _ in range(7):
    n,c = input_line().split()
    s[n] += int(c)
mv = max(s.values())
ks = [k for k in s.keys() if s[k] == mv]
print(ks[0])