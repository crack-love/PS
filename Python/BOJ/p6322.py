i = 1
while True:
    a, b, c = map(int, input().split())
    if a == 0 and b == 0 and c == 0:
        break
    print(f"Triangle #{i}")
    if a == -1:
        if b >= c:
            print("Impossible.")
        else:
            print(f"a = {(c**2-b**2)**(1/2):.3f}")
    elif b == -1:
        if a >= c:
            print("Impossible.")
        else:
            print(f"b = {(c**2-a**2)**(1/2):.3f}")
    else:
        print(f"c = {(a**2+b**2)**(1/2):.3f}")
    print()
    i += 1