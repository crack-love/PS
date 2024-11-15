n = int(input())
g = []
for _ in range(n):
    g.append(input())
v = int(input())
if v == 1:
    for x in g:
        print(x)
elif v == 2:
    for x in g:
        print(x[::-1])
elif v ==3:
    for x in g[::-1]:
        print(x)