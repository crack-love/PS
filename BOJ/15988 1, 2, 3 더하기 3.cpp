// https://www.acmicpc.net/problem/15988

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p15988
{
	int d[(int)1e6 + 1] = { 1, };
	const int M = (int)1e9 + 9;

	int dp(int x)
	{
		if (x < 0)
			return 0;

		int& r = d[x];
		if (r != 0)
			return r;

		r = dp(x - 1) + dp(x - 2);
		r %= M;
		r += dp(x - 3);
		r %= M;

		return r;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int t;
		cin >> t;
		while (t--)
		{
			int x;
			cin >> x;
			cout << dp(x) << "\n";
		}

		return 0;
	}
};