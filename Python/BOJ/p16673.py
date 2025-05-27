c,k,p = map(int,input().split())
print(sum(k*i+p*i*i for i in range(1,c+1)))
