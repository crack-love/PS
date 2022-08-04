// https://www.acmicpc.net/problem/15480

#include <bits/stdc++.h>
using namespace std;

struct p15480
{
	// 1. uv가 1 좌우에 있을 경우
	// (1) r이 u 아래 있을 경우
	// (2) r이 u 위에 있을 경우
	// 2. uv가 1 좌에 같이 있을 경우
	// (1) r이 uv 위에 있을 경우
	// (2) r이 uv 사이에 있을 경우
	// (3) r이 uv 밑에 있을 경우

	int par[100001][17]; // 0~16
	int lvl[100001];

	int lca(int a, int b)
	{
		if (lvl[a] > lvl[b]) swap(a, b);

		int diff = lvl[b] - lvl[a];
		for (int i = 0; i < 17; ++i)
		{
			if (diff & (1 << i))
			{
				b = par[b][i];
			}
		}

		if (a != b)
		{
			for (int i = 16; i >= 0; --i)
			{
				if (par[a][i] != par[b][i])
				{
					a = par[a][i];
					b = par[b][i];
				}
			}
			a = par[a][0];
		}
		return a;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		vector<int> edge[100001];
		int n;
		cin >> n;
		for (int i = 0; i < n - 1; ++i)
		{
			int a, b;
			cin >> a >> b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}

		vector<int> v;
		v.push_back(1);
		lvl[1] = 0;
		while (!v.empty())
		{
			int x = v.back();
			v.pop_back();

			for (int e : edge[x])
			{
				if (e == par[x][0]) continue;
				par[e][0] = x;
				lvl[e] = lvl[x] + 1;
				v.push_back(e);
			}
		}

		for (int i = 1; i < 17; ++i)
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
		while (m--)
		{
			int r, a, b;
			cin >> r >> a >> b;

			int v0 = lca(r, a);
			int v1 = lca(r, b);
			int v2 = lca(a, b);

			int ans = v0;
			if (lvl[ans] < lvl[v1]) ans = v1;
			if (lvl[ans] < lvl[v2]) ans = v2;
			cout << ans << "\n";
		}

		return 0;
	}
};