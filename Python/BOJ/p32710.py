import sys
def input_line(): return sys.stdin.readline().strip()
def input_cast(f): return f(input_line())
def input_map(f): return map(f, input_line().split())
s = set()
for x in range(1,10):
    for y in range(1,10):
        s.add(x*y)
n = input_cast(int)
print(1 if n in s else 0)