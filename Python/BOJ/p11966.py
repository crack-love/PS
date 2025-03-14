n = int(input())
bcnt = 0
while (n>0):
    if n & 1 == 1:
        bcnt += 1
    n //= 2
print (1 if bcnt == 1 else 0)