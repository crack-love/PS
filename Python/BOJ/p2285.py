import sys
def input(): return sys.stdin.readline().strip()
n = int(input())
a = [(0,0)]*n
for i in range(int(n)):
    a[i] = tuple(map(int,input().split()))
a.sort()
lps,rps = [0]*n,[0]*n
ldp,rdp = [0]*n, [0]*n
lps[0]=a[0][1]
rps[n-1]=a[n-1][1]
for i in range(n-1):
    lps[i+1] = lps[i] + a[i+1][1]
    ldp[i+1] = ldp[i] + lps[i] * (a[i+1][0]-a[i][0])
    rps[n-i-2] = rps[n-i-1] + a[n-i-2][1]
    rdp[n-i-2] = rdp[n-i-1] + rps[n-i-1] * -(a[n-i-2][0]-a[n-i-1][0])
ansv = ldp[0]+rdp[0]
ansi = 0
for i in range(n):
    if ansv > ldp[i]+rdp[i]:
        ansv = ldp[i]+rdp[i]
        ansi = i
print(a[ansi][0])