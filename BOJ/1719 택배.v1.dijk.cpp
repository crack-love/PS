// https://www.acmicpc.net/problem/1719

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

void dijk(int beg, int par[], vector<pair<int, int>> edge[])
{
	int cost[201];
	fill(cost, cost + 201, -1);

	priority_queue<pair<int, int>> q;
	q.push({0, beg});
	cost[beg] = 0;

	while (!q.empty())
	{
		int c = -q.top().first;
		int x = q.top().second; q.pop();
		if (cost[x] != c) continue;

		for (pair<int, int>& e : edge[x])
		{
			int nx = e.first;
			int nc = c + e.second;
			if (cost[nx] == -1 || nc < cost[nx])
			{
				cost[nx] = nc;
				par[nx] = par[x] != -1 ? par[x] : nx;
				q.push({-nc, nx});
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<pair<int, int>> edge[201];
	int par[201][201];
	fill(&par[0][0], &par[200][201], -1);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({b, c});
		edge[b].push_back({a, c});
	}

	for (int i = 1; i <= n; ++i)
	{
		dijk(i, par[i], edge);
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i == j) cout << "- ";
			else if (par[i][j] == -1) cout << j << " ";
			else cout << par[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}