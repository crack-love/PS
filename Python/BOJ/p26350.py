ans = []
n = int(input())
for ni in range(n):
    bad = False
    s = [*map(int,input().split())][1:]
    for i in range(len(s)-1):
        if s[i]*2 > s[i+1]:
            bad = True
            break
    ans.append(' '.join(("Denominations:", *map(str,s))))
    ans.append(('Bad' if bad else 'Good') + ' coin denominations!')
    if ni < n-1:
        ans.append('')
print(*ans, sep='\n')