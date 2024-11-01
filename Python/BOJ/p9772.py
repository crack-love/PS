ans = []
while True:
    x, y = map(float, input().split())
    if x == 0 or y == 0:
        ans.append("AXIS")
    elif x > 0:
        if y > 0:
            ans.append("Q1")
        else:
            ans.append("Q4")
    else:#x<0
        if y > 0:
            ans.append("Q2")
        else:
            ans.append("Q3")
    if x == 0 and y == 0:
        break
for x in ans:
    print(x)