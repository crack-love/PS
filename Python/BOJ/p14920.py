v = int(input())
i = 1
while True:
    if v == 1:
        break
    if v % 2 == 0:
        v = v//2
    else:
        v = v*3 + 1
    i += 1
print(i)