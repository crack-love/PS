n = int(input())
a,b=(input(),input())
s = sum(1 if a[i] != b[i] else 0 for i in range(n))
print(s)