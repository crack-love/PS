import sys
def input_line(): return sys.stdin.readline().strip()
def input_cast(f): return f(input_line())
def input_map(f): return map(f, input_line().split())
n,m,k=input_map(int)
print(m*(k+1))