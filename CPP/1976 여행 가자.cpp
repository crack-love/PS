// https://www.acmicpc.net/problem/1976

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1976
{
	vector<int> link[201];
	int group[201];
	void dfs(int x, int g)
	{
		group[x] = g;
		for (int y : link[x])
		{
			if (group[y] == 0)
			{
				dfs(y, g);
			}
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, m;
		cin >> n >> m;
		for2(i, j, n, n)
		{
			int x;
			cin >> x;
			if (x == 1)
			{
				link[i + 1].push_back(j + 1);
			}
		}

		int nextGroup = 1;
		for (int i = 1; i <= n; ++i)
		{
			if (group[i] == 0)
			{
				dfs(i, nextGroup++);
			}
		}

		if (m > 0)
		{
			int x;
			cin >> x;
			int targetGroup = group[x];
			for (int i = 1; i < m; ++i)
			{
				int x;
				cin >> x;
				if (targetGroup != group[x])
				{
					cout << "NO";
					return 0;
				}
			}
		}

		cout << "YES";
		return 0;
	}
};