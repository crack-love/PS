a = [0]*4
a[0], a[1] = map(int, input().split())
a[3], a[2] = map(int, input().split())
ansv = 0
ansc = 0
for i in range(4):
    v = a[0]/a[3]+a[1]/a[2]
    if v > ansv:
        ansv = v
        ansc = i
    a.insert(0,a.pop())
print(ansc) 