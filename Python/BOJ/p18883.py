n, m=map(int,input().split())
for i in range(n):
	print(*(j for j in range(i*m+1, i*m+m+1)), end='\n')