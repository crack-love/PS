n = input()
a = [*map(int,input().split())]
ans = sum((x+1)//2 for x in a)
print(ans)