n = int(input())
ans = 0
for i in range(1,n):
    for j in range(1,n): 
        for  k in range(1,n):
            if i+j+k==n and j>=i+2 and k%2==0:
                ans +=1
print(ans)