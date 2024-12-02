import sys
def input_line(): return sys.stdin.readline().strip()
def input_map(f): return map(f, input_line().split())
n = int(input_line())
s = input_line()
g = (x.lower() if x.isupper() else x.upper() for x in s)
print("".join(g))