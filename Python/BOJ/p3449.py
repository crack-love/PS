for _ in range(int(input())):
    a = input()
    b = input()
    c = sum(x != y for x,y in zip(a,b))
    print(f"Hamming distance is {c}.")