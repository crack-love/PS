while True:
    a, b, c, d = map(int, input().split())
    if a == 0 == b == c == d:
        break
    ans = 0
    while True:
        if a == b == c == d:
            print(ans)
            break
        a, b, c, d = abs(a-b), abs(b-c), abs(c-d), abs(d-a)
        ans += 1