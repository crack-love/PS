// https://www.acmicpc.net/problem/1167

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1167
{
	int v;
	vector<pair<int, int>> edge[100001];

	int highPos;
	int highCost;
	bool visited[100001];
	void dfs(int i, int c)
	{
		visited[i] = true;
		if (c > highCost)
		{
			highCost = c;
			highPos = i;
		}

		for (pair<int, int> e : edge[i])
		{
			if (visited[e.first]) continue;
			dfs(e.first, c + e.second);
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		cin >> v;
		for (int i = 0; i < v; ++i)
		{
			int a, b, c;
			cin >> a;
			while (true)
			{
				cin >> b;
				if (b == -1) break;
				cin >> c;
				edge[a].push_back({ b,c });
				edge[b].push_back({ a,c });
			}
		}

		dfs(1, 0);
		memset(visited, 0, sizeof(visited));
		highCost = 0;
		dfs(highPos, 0);
		cout << highCost;
		return 0;
	}
};