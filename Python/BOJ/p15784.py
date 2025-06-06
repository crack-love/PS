n,x,y=map(int,input().split())
x-=1
y-=1
a=[[0]*n]*n
for i in range(n):
    a[i] = list(map(int,input().split()))
ans = 0
for i in range(n):
    if a[x][i] > a[x][y]: 
        ans = 1
    if a[i][y] > a[x][y]:
        ans = 1
print ('ANGRY' if ans == 1 else 'HAPPY')