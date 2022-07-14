// https://www.acmicpc.net/problem/1238

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

struct p1238
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int cost[1001][1001];
		fill(&cost[0][0], &cost[1000][1001], -1);

		int n, m, x;
		cin >> n >> m >> x;
		for (int i = 0; i < m; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;
			cost[a][b] = c;
		}

		for (int i = 1; i <= n; ++i)
		{
			cost[i][i] = 0;
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (cost[j][i] == -1) continue;
				for (int k = 1; k <= n; ++k)
				{
					if (cost[i][k] == -1) continue;

					int nc = cost[j][i] + cost[i][k];
					if (cost[j][k] == -1 || nc < cost[j][k])
					{
						cost[j][k] = nc;
					}
				}
			}
		}

		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			int t = cost[i][x] + cost[x][i];
			if (t > ans) ans = t;
		}
		cout << ans;
		return 0;
	}
};