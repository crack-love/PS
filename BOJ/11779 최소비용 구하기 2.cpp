// https://www.acmicpc.net/problem/11779

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

struct p11779
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		vector<pair<int, int>> edge[1001];

		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;
			edge[a].push_back({ b, c });
		}

		int b, e;
		cin >> b >> e;

		int cost[1001];
		int par[1001];
		priority_queue<pair<int, int>> q;
		fill(cost, cost + n + 1, -1);

		q.push({ 0, b });
		cost[b] = 0;
		par[b] = 0;

		while (!q.empty())
		{
			int x = q.top().second;
			int c = -q.top().first; q.pop();
			if (cost[x] != c) continue;

			if (x == e)
			{
				break;
			}

			for (pair<int, int>& e : edge[x])
			{
				int nx = e.first;
				int nc = c + e.second;
				if (cost[nx] == -1 || nc < cost[nx])
				{
					par[nx] = x;
					cost[nx] = nc;
					q.push({ -nc, nx });
				}
			}
		}

		vector<int> ans;
		int curr = e;
		while (curr != 0)
		{
			ans.push_back(curr);
			curr = par[curr];
		}

		cout << cost[e] << "\n";
		cout << ans.size() << "\n";
		for (int i = ans.size() - 1; i >= 0; --i)
		{
			cout << ans[i] << " ";
		}

		return 0;
	}
};