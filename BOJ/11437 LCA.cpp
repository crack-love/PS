// https://www.acmicpc.net/problem/11437

#include <bits/stdc++.h>
using namespace std;

struct p11437
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		vector<int> edge[50001];

		int n;
		cin >> n;
		for (int i = 0; i < n - 1; ++i)
		{
			int a, b;
			cin >> a >> b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}

		int lvl[50001] = {};
		int par[50001][16] = {}; // 1 2 4 8..2^15
		vector<int> ps;
		ps.push_back(1);
		while (ps.size() > 0)
		{
			int i = ps.back();
			ps.pop_back();

			for (int e : edge[i])
			{
				if (e == par[i][0]) continue;

				par[e][0] = i;
				lvl[e] = lvl[i] + 1;
				ps.push_back(e);
			}
		}

		for (int i = 1; i < 16; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (lvl[j] < (1 << i)) continue;
				int m = par[j][i - 1];
				par[j][i] = par[m][i - 1];
			}
		}

		int m;
		cin >> m;
		for (int i = 0; i < m; ++i)
		{
			int a, b;
			cin >> a >> b;
			if (lvl[a] > lvl[b]) swap(a, b);

			int diff = lvl[b] - lvl[a];
			for (int i = 0; i < 16; ++i)
			{
				if ((1 << i) & diff)
				{
					b = par[b][i];
				}
			}

			if (a != b)
			{
				for (int i = 15; i >= 0; --i)
				{
					if (lvl[a] < (1 << i)) continue;
					if (par[a][i] != par[b][i])
					{
						a = par[a][i];
						b = par[b][i];
					}
				}
				cout << par[a][0] << "\n";
			}
			else
			{
				cout << a << "\n";
			}
		}

		return 0;
	}
};