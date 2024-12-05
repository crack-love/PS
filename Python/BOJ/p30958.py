import collections
import sys
def input_line(): return sys.stdin.readline().strip()
def input_map(f): return map(f, input_line().split())
n = input_line()
s = input_line()
c = collections.defaultdict(int)
for x in s:
    if x.isalpha():
        c[x] += 1
mv = max(c.values())
print(mv)