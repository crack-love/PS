import string
import sys
def input_line(): return sys.stdin.readline().strip()
def input_map(f): return map(f, input_line().split())
s = input_line()
a = {c for c in string.ascii_uppercase}
for c in s:
    a.remove(c)
print(next(iter(a)))