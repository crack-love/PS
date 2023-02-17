// https://www.acmicpc.net/problem/2578

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2578
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		unordered_map<int, pair<int, int>> m;
		int g[5][5];
		for2(i, j, 5, 5)
		{
			cin >> g[i][j];
			m[g[i][j]] = { i,j };
		}

		for2(i, j, 5, 5)
		{
			int v;
			cin >> v;
			pair<int, int> p = m[v];

			if (g[p.first][p.second] != 0)
			{
				g[p.first][p.second] = 0;

				int bcnt = 0;
				bool s1 = true;
				bool s2 = true;
				for (int u = 0; u < 5; ++u)
				{
					bool row = true;
					bool col = true;
					for (int v = 0; v < 5; ++v)
					{
						if (g[u][v] != 0)
						{
							row = false;
						}
						if (g[v][u] != 0)
						{
							col = false;
						}
					}

					if (g[u][u] != 0)
					{
						s1 = false;
					}
					if (g[u][4 - u] != 0)
					{
						s2 = false;
					}

					bcnt += row ? 1 : 0;
					bcnt += col ? 1 : 0;
				}
				bcnt += s1 ? 1 : 0;
				bcnt += s2 ? 1 : 0;

				if (bcnt >= 3)
				{
					cout << i * 5 + j + 1;
					i = 5;
					break;
				}
			}
		}
		return 0;
	}
};