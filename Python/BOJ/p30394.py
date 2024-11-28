import sys
def input_line(): return sys.stdin.readline().strip()
def input_cast(f): return f(input_line())
def input_map(f): return map(f, input_line().split())
n = input_cast(int)
miny = int(1e9+1)
maxy = int(-1e9-1)
for _ in range(n):
    x,y=input_map(int)
    miny = min(y,miny)
    maxy = max(y, maxy)
print(maxy-miny)