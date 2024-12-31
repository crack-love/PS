import sys
def input(): return sys.stdin.readline().strip()
ans = []
for _ in range(int(input())):
    t = 0
    for _ in range(int(input())):
        n,c,v = input().split()
        s = float(c)*float(v)
        t += s
    ans.append(t)
for x in ans:
    print(f"${x:.2f}")