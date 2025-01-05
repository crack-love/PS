import sys
def input(): return sys.stdin.readline().strip()
v = input()
ec = v.count("e")
ans = []
ans.append('h')
for _ in range(ec*2):
    ans.append('e')
ans.append('y')
print(*ans, sep='')