import sys
def input_line(): return sys.stdin.readline().strip()
def input_map(f): return map(f, input_line().split())
n = int(input_line())
ans = []
for _ in range(n):
    a,p=input_map(int)
    r,p2=input_map(int)
    v1 = a/p
    v2 = 3.141592*r*r/p2
    ans.append("Slice of pizza" if v1>v2 else "Whole pizza")
for x in ans:
    print(x)