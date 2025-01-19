import sys
def input(): return sys.stdin.readline().strip()
w = int(input())
l = int(input())
h = int(input())
mn = min(w,l)
mx = max(w,l)
print ("good" if mn >= 2 * h and mx <= 2 * mn else "bad")