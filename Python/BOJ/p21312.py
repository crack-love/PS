a, b, c = map(int, input().split())
ans = 0
def s(x, y):
    if x % 2 == 1 and y % 2 == 0:
        return x
    elif x % 2 == 0 and y % 2 == 1:
        return y
    return max(x, y)
ans = s(a, ans)
ans = s(b, ans)
ans = s(c, ans)
ans = s(a*b, ans)
ans = s(a*c, ans)
ans = s(b*c, ans)
ans = s(a*b*c, ans)
print(ans)