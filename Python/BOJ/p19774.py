import sys
def input_line(): return sys.stdin.readline().strip()
def input_one(f): return f(input_line())
def input_unpack(f): return map(f, input_line().split())

n = input_one(int)
ans = []
for _ in range(n):
    s = input_line()
    v = (pow(int(s[0:2]), 2)+pow(int(s[2:4]), 2)) % 7
    ans.append("YES" if v == 1 else "NO")
for x in ans:
    print(x)