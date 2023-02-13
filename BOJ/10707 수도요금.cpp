// https://www.acmicpc.net/problem/10707

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p10707
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int a, b, c, d, p;
		cin >> a >> b >> c >> d >> p;
		int c0 = p * a;
		int c1 = b;
		if (p > c)
		{
			c1 += (p - c) * d;
		}

		cout << min(c0, c1);

		return 0;
	}
};