p,k= map(int,input().split())
ans = 0
for i in range(2,k):
    if p%i==0:
        ans = i
        break
print('GOOD' if ans == 0 else f'BAD {ans}')