import sys
def input(): return sys.stdin.readline().strip()
a = int(input())
b = int(input())
a += 7*b
print(1 if a<=30 else 0)