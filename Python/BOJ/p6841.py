d = {
    "CU": "see you",
    ":-)": "I’m happy",
    ":-(": "I’m unhappy",
    ";-)": "wink",
    ":-P": "stick out my tongue",
    "(~.~)": "sleepy",
    "TA": "totally awesome",
    "CCC": "Canadian Computing Competition",
    "CUZ": "because",
    "TY": "thank-you",
    "YW": "you’re welcome",
    "TTYL": "talk to you later",
}
ans = []
while True:
    s = input()
    if s in d.keys():
        ans.append(d[s])
    else:
        ans.append(s)
    if s == "TTYL":
        break
for x in ans:
    print(x)