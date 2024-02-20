// https://www.acmicpc.net/problem/4811

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p4811
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		while (true)
		{
			int n;
			cin >> n;
			if (n == 0)
				break;

			long long d[61][32][32]{}; //day,w,h
			d[0][n][0] = 1;

			for (int i = 1; i <= 2 * n; ++i)
			{
				for2(x, y, n + 1, n + 1)
				{
					if (y > 0)
						d[i][x][y] += d[i - 1][x + 1][y - 1];
					d[i][x][y] += d[i - 1][x][y + 1];
				}
			}

			long long ans = 0;
			for2(i, j, n, n + 1)
			{
				ans += d[2 * n][i][j];
			}
			cout << ans << "\n";
		}

		return 0;
	}
};