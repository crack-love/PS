import sys
def input(): return sys.stdin.readline().strip()
a = int(input())
print(1/(a/100))
print(1/(1-(a/100)))