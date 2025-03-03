a = sum(map(int,input().split()))
b = sum(map(int,input().split()))
a1 = (a-1)%4+1
b1 = (a1+b-2)%4+1
print(b1)