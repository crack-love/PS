// https://www.acmicpc.net/problem/2240

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p2240
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int t, w;
		cin >> t >> w;
		int p[1001];
		for1(i, t)
		{
			cin >> p[i];
			p[i] -= 1;
		}

		int d[1001][31][2]{}; // i sec, j remains, k tree

		// only start at tree 0
		if (t > 0)
		{
			d[1][w][0] = p[0] == 0;

			if (w > 0)
				d[1][w - 1][1] = p[0] == 1;
		}

		for (int i = 1; i < t; ++i)
		{
			for (int j = 0; j <= w; ++j)
			{
				for (int k = 0; k < 2; ++k)
				{
					int kv = p[i] == k ? 1 : 0;
					int k1 = k == 0 ? 1 : 0;

					// stay
					d[i + 1][j][k] =
						max(d[i + 1][j][k], d[i][j][k] + kv);

					// move
					if (j > 0)
					{
						d[i + 1][j - 1][k] =
							max(d[i + 1][j - 1][k], d[i][j][k1] + kv);
					}
				}
			}
		}

		int ans = 0;
		for1(j, 31)
		{
			for1(k, 2)
			{
				ans = max(d[t][j][k], ans);
			}
		}
		cout << ans;

		return 0;
	};
};