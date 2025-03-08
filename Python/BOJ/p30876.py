n = int(input())
my = 10000
mx = 0
for _ in range(n):
    x,y= map(int,input().split())
    if y<my:
        my = y
        mx = x
print(mx, my)