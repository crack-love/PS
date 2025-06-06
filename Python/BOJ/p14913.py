a,d,k=map(int,input().split())
#d*n+a-d=k
#(k+d-a)/d=n
n = (k+d-a)/d
if n % 1 == 0 and n > 0:
    print(int(n))
else:
    print('X')