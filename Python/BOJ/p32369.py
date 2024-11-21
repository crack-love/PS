import sys
def input_line(): return sys.stdin.readline().strip()
def input_one(f): return f(input_line())
def input_unpack(f): return map(f, input_line().split())

n,a,b = input_unpack(int)
av = 1
bv = 1
for _ in range(n):
    av += a
    bv += b
    if av < bv:
        av,bv = bv,av
    elif av == bv:
        bv -= 1
print(av, bv)