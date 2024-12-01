import sys
def input_line(): return sys.stdin.readline().strip()
def input_cast(f): return f(input_line())
def input_map(f): return map(f, input_line().split())
def solve():
    n = input_cast(int)
    if n==0:
        print("divide by zero")
        return
    a = list(input_map(int))
    s = sum(a)
    if s ==0:
        print("divide by zero")
        return
    print("1.00")
solve()