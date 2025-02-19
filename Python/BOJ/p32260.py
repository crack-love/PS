c = [3, 4, 5]
i = [int(input()) for _ in range(3)]
r = sum(a * b for a, b in zip(c, i))
print(r)