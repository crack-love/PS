a, b = map(int, input().split())
c, d = map(int, input().split())
if a > b:
    a, b = b, a
if c > d:
    c, d = d, c
print(b-a+d-c - max(0,min(b,d)-max(a,c)))