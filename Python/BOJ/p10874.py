n = int(input())
for i in range(n):
    a = list(map(int,input().split()))
    for j in range(10):
        if a[j] != j%5+1:
            break
    else:
        print(i+1)