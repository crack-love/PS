s = input()
for i in range(len(s)):
    if s[i] == 'd' or s[i] == 'D':
        if i + 1 < len(s) and s[i+1] == '2':
            print('D2')
            break
else:
    print('unrated')