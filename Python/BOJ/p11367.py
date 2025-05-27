s = [(97,'A+'),(90,'A'),(87,'B+'),(80,'B'),(77,'C+'),
     (70,'C'),(67,'D+'),(60,'D'),(0,'F')]
for _ in range(int(input())):
    a,b = input().split()
    v = int(b)
    for i in range(len(s)):
        if v >= s[i][0]:
            print(a, s[i][1])
            break