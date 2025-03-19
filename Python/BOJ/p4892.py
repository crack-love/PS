i = 1
while True:
    n = int(input())
    if n == 0:
        break
    print(f"{i}. {'odd' if n%2==1 else 'even'} {n//2}")
    i+=1
