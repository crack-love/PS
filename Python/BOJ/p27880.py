import sys
def input(): return sys.stdin.readline().strip()
ans = 0
while True:
    ip = input();
    if ip == "":
        break
    t, v = ip.split()
    tf = 21 if t == "Es" else 17
    ans += tf * int(v)
print(ans)