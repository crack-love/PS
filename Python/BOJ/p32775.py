import sys
def input(): return sys.stdin.readline().strip()
s = int(input())
f = int(input())
print("high speed rail" if s<=f else "flight")