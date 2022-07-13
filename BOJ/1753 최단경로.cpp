// https://www.acmicpc.net/problem/1753

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

struct p1753
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		static const int SIZE_V = 20001;
		vector<pair<int, int>> edge[SIZE_V];
		int cost[SIZE_V];
		bool visit[SIZE_V] = {};
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

		int v, e, s;
		cin >> v >> e;
		cin >> s;
		for (int i = 0; i < e; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;
			edge[a].push_back({ b, c });
		}

		fill(cost, cost + v + 1, -1);

		q.push({ 0, s });
		cost[s] = 0;

		while (true)
		{
			// get next node
			int nextNode = -1;
			while (!q.empty())
			{
				int dst = q.top().second;
				int c = q.top().first; q.pop();

				if (cost[dst] != c) continue;

				if (!visit[dst])
				{
					nextNode = dst;
					break;
				}
			}

			if (nextNode == -1) break;

			// visit node
			visit[nextNode] = true;
			for (pair<int, int>& p : edge[nextNode])
			{
				int ncost = cost[nextNode] + p.second;
				if (cost[p.first] == -1 || ncost < cost[p.first])
				{
					cost[p.first] = ncost;
					q.push({ ncost, p.first });
				}
			}
		}

		for (int i = 1; i <= v; ++i)
		{
			if (cost[i] == -1) cout << "INF";
			else cout << cost[i];
			cout << "\n";
		}

		return 0;
	}
};