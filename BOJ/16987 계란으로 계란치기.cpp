// https://www.acmicpc.net/problem/16987

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p16987
{
	int n;
	int w[8];
	int d[8];
	int ans;
	void solve(int i)
	{
		if (i == n)
		{
			int c = 0;
			for1(j, n)
			{
				c += d[j] <= 0 ? 1 : 0;
			}
			ans = max(c, ans);
			return;
		}

		if (d[i] > 0)
		{
			bool smashed = false;
			for (int j = 0; j < n; ++j)
			{
				if (j == i) continue;

				if (d[j] > 0)
				{
					d[j] -= w[i];
					d[i] -= w[j];

					solve(i + 1);

					d[j] += w[i];
					d[i] += w[j];
					smashed = true;
				}
			}

			if (!smashed)
				solve(i + 1);
		}
		else
		{
			solve(i + 1);
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		cin >> n;
		for1(i, n)
		{
			cin >> d[i] >> w[i];
		}

		solve(0);
		cout << ans;
		return 0;
	}
};