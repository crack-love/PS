import sys
def input(): return sys.stdin.readline().strip()
n = int(input())
d = {}
for x in input().split():
    if x in d.keys():
        d[x] += 1
    else:
        d[x] = 1
v = input()
print(d[v] if v in d.keys() else 0)
