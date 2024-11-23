import sys
def input_line(): return sys.stdin.readline().strip()
def input_one(f): return f(input_line())
def input_unpack(f): return map(f, input_line().split())
n,m = input_unpack(int) #n=m+14
mds = 28,29,30,31
ans = 0
if m > n:
    for md in mds:
        if n-14+md == m:
            if m+7 > md:
                ans = m+7-md
                break
            else:
                ans = m+7
                break
else:
    ans = n-7
print(ans)