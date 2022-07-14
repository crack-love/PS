// https://www.acmicpc.net/problem/1238

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct p1238
{
	int dijk(int beg, int end, vector<pair<int, int>> edge[], int n)
	{
		int cost[1001];
		fill(cost, cost + n + 1, -1);
		priority_queue<pair<int, int>> q;

		q.push({ 0, beg });
		cost[beg] = 0;

		while (!q.empty())
		{
			int c = -q.top().first;
			int p = q.top().second; q.pop();
			if (cost[p] != c) continue;

			if (p == end) break;

			for (pair<int, int>& pr : edge[p])
			{
				int np = pr.first;
				int nc = pr.second + c;
				if (cost[np] == -1 || nc < cost[np])
				{
					cost[np] = nc;
					q.push({ -nc, np });
				}
			}
		}

		return cost[end];
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		vector<pair<int, int>> edge[1001];

		int n, m, x;
		cin >> n >> m >> x;
		for (int i = 0; i < m; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;
			edge[a].push_back({ b, c });
		}

		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			int t = 0;
			t += dijk(i, x, edge, n);
			t += dijk(x, i, edge, n);
			if (t > ans) ans = t;
		}

		cout << ans;
		return 0;
	}
};