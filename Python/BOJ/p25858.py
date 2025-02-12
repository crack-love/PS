n,p = map(int,input().split())
cs = [int(input()) for _ in range(n)]
csum = sum(cs)
for i in range(n):
    print(int(p/csum*cs[i]))