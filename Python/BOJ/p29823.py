n = int(input())
s = input()
nc = 0
wc = 0
for c in s:
    if c == 'N':
        nc += 1
    elif c == 'S':
        nc -= 1
    elif c == 'W':
        wc += 1
    elif c == 'E':
        wc -= 1
print(abs(nc)+abs(wc))