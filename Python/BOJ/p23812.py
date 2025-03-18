def p1(n):
    for _ in range(n):
        print('@'*n, ' '*3*n, '@'*n, sep='')
def p2(n):
    for _ in range(n):
        print('@'*n*5)
n = int(input())
p1(n)
p2(n)
p1(n)
p2(n)
p1(n)