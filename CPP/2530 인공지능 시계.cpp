// https://www.acmicpc.net/problem/2530

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2530
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int h, m, s, d;
		cin >> h >> m >> s >> d;

		s += m * 60 + h * 3600 + d;
		h = s / 3600;
		s %= 3600;
		m = s / 60;
		s %= 60;
		cout << h % 24 << " " << m << " " << s;

		return 0;
	}
};