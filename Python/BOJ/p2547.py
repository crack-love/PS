for _ in range(int(input())):
    input()
    n = int(input())
    s = sum(int(input()) for _ in range(n))
    print('YES' if s % n == 0 else 'NO')