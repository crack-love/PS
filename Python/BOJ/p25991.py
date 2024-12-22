import sys
def input(): return sys.stdin.readline().strip()
n = int(input())
a = [*map(float, input().split())]
v = sum(x**3 for x in a)**(1/3)
print(f"{v:.6f}")
