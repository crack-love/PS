// https://www.acmicpc.net/problem/2961

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p2961
{
	int n;
	int a[10];
	int b[10];
	int ans = INT_MAX;

	void dfs(int i, int as, int bs, bool use)
	{
		if (i >= n)
		{
			if (!use)
				return;

			ans = min(abs(as - bs), ans);
			return;
		}

		dfs(i + 1, as, bs, use);

		if (!use)
		{
			dfs(i + 1, a[i], b[i], true);
		}
		else
		{
			dfs(i + 1, as * a[i], bs + b[i], true);
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		cin >> n;
		for1(i, n)
		{
			cin >> a[i] >> b[i];
		}

		dfs(0, 0, 0, false);
		cout << ans;

		return 0;
	}
};