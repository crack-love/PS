import sys
def input_line(): return sys.stdin.readline().strip()
def input_one(f): return f(input_line())
def input_unpack(f): return map(f, input_line().split())

n = input_one(int)
a = int(input_line().replace(" ", ""))
b = int(input_line().replace(" ", ""))
print(a if a < b else b)