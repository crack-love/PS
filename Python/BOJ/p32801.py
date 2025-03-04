n,a,b=map(int,input().split())
def gcd(a,b):
    if a<b:
        (a,b)=(b,a)
    if b==0:
        return a
    return gcd(b, a%b)
mcm =a*b//gcd(a,b)
fb=n//mcm
print(n//a-fb,n//b-fb,fb)
