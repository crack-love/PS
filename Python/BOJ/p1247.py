ans = []
for _ in range(3):
    n = int(input())
    sum = 0
    for _ in range(n):
        sum += int(input())
    if sum > 0:
        ans.append('+')
    elif sum < 0:
        ans.append('-')
    else:
        ans.append('0')
print(*ans, sep='\n')