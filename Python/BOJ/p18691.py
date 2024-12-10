import sys
def input_line(): return sys.stdin.readline().strip()
def input_map(f): return map(f, input_line().split())
t = int(input_line())
gtom = {1:1, 2:3, 3:5}
for _ in range(t):
    g,c,e=input_map(int)
    m = gtom[g]
    if c > e:
        print(0)
    else:
        a = (e - c) * m
        print(a)