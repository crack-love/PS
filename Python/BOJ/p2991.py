import sys
def input_line(): return sys.stdin.readline().strip()
def map_line(f): return map(f, input_line().split())

a, b, c, d = map_line(int)
p, m, n = map_line(int)
pmn = p,m,n
f = lambda t: int((t-1) % (a + b) < a) + int((t-1) % (c + d) < c)
for x in map(f,pmn):
    print(x)

#1 2 3 4 : t
#0 1 2 3 : t-1
#~~~    : dog=2
#~~~~~  : dog=3