// https://www.acmicpc.net/problem/

#include <bits/stdc++.h>
using namespace std;

struct p11438
{
	struct node
	{
		int level;
		int par[17] = {}; // 1, 2, 4, 8 ... 2^16
		vector<int> link;
	};

	node nodes[100001];

	void setpar(int i, int level, int par)
	{
		nodes[i].level = level;
		nodes[i].par[0] = par;

		for (int adj : nodes[i].link)
		{
			if (adj == par) continue;

			setpar(adj, level + 1, i);
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int n;
		cin >> n;
		for (int i = 0; i < n - 1; ++i)
		{
			int a, b;
			cin >> a >> b;
			nodes[a].link.push_back(b);
			nodes[b].link.push_back(a);
		}

		setpar(1, 0, 0);

		// set sqr par 
		for (int i = 1; i <= 16; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (nodes[j].level < (1 << i)) continue;

				int m = nodes[j].par[i - 1];
				nodes[j].par[i] = nodes[m].par[i - 1];
			}
		}

		int m;
		cin >> m;
		for (int t = 0; t < m; ++t)
		{
			int a, b;
			cin >> a >> b;

			if (nodes[a].level > nodes[b].level)
			{
				swap(a, b);
			}

			int diff = nodes[b].level - nodes[a].level;
			if (diff > 0)
			{
				for (int i = 0; i <= 16; ++i)
				{
					if (diff & (1 << i))
					{
						b = nodes[b].par[i];
					}
				}
			}

			if (a != b)
			{
				for (int i = 16; i >= 0; --i)
				{
					if (nodes[a].level < (1 << i)) continue;

					if (nodes[a].par[i] != nodes[b].par[i])
					{
						a = nodes[a].par[i];
						b = nodes[b].par[i];
					}
				}
				a = nodes[a].par[0];
			}

			cout << a << "\n";
		}

		return 0;
	}
};