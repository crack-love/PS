import sys
def input_line(): return sys.stdin.readline().strip()
def input_map(f): return map(f, input_line().split())
a = list(input_map(int))
mv = max(a)
ans = sum(1 for x in a if mv-x <= 1000)-1
print(ans)