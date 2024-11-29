import sys
def input_line(): return sys.stdin.readline().strip()
def input_cast(f): return f(input_line())
def input_map(f): return map(f, input_line().split())
s = input_line()
vs = {"a","e","i","o","u"}
c0 = sum(1 for x in s if x in vs)
c1 = s.count("y")
print (c0, c0+c1)