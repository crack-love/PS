a = list(map(int,input().split()))
a.sort()
if a[1]-a[0] == a[2]-a[1]:
    print(a[0]-(a[1]-a[0]))
elif a[0] == a[1] - (a[2]-a[1])*2:
    print(a[0]+a[2]-a[1])
else:
    print(a[1]+(a[1]-a[0]))