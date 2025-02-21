b = int(input())
ps = [int(input()) for _ in range(3)]+[0]
ns = ['Watermelon','Pomegranates','Nuts','Nothing']
for i in range(len(ps)):
    if ps[i]<=b:
        print(ns[i])
        break