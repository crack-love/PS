import sys
def input(): return sys.stdin.readline().strip()
m,n=map(int,input().split())
print ("satisfactory" if m >= 8 else "unsatisfactory")