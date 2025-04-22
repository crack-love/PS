n = int(input())
s = 0
for i in range(1,n+1):
    s += i if n % i==0 else 0
print(s * 5 - 24)