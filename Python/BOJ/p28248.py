import sys
def input_line(): return sys.stdin.readline().strip()
def input_cast(f): return f(input_line())
def input_unpack(f): return map(f, input_line().split())

p =input_cast(int)
c = input_cast(int)
v = 50*p-10*c
v += 500 if p > c else 0
print(v)