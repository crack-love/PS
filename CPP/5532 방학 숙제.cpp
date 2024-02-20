// https://www.acmicpc.net/problem/5532

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p5532
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int l, a, b, c, d;
		cin >> l >> a >> b >> c >> d;
		int math = b / d;
		if (b % d != 0) math += 1;
		int lang = a / c;
		if (a % c != 0) lang += 1;
		cout << l - max(math, lang);

		return 0;
	}
};