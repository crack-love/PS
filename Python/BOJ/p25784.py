a = [*map(int,input().split())]
ans = 3;
for i in range(3):
    if a[i] == a[(i+1)%3]+a[(i+2)%3]:
        ans = 1
for i in range(3):
    if a[i] == a[(i+1)%3]*a[(i+2)%3]:
        ans = 2
print(ans)