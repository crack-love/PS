n,m=map(int,input().split())
c=[0]*(n+1)
for i in range(m):
    x,y=map(int,input().split())
    c[x]+=1
    c[y]+=1
print(*c[1:],sep ='\n')
