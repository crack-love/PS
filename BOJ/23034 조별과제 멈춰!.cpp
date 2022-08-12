// https://www.acmicpc.net/problem/23034

#include <bits/stdc++.h>
using namespace std;

struct p23034
{
	typedef tuple<int, int, int> tp;
	typedef pair<int, int> pi;

	int root[1001];
	int find(int x)
	{
		if (root[x] == x) return x;
		else return root[x] = find(root[x]);
	}

	int makeMst(int n, vector<tp>& edges, vector<pi> link[])
	{
		int sum = 0;

		sort(edges.begin(), edges.end());
		for (int i = 0; i < n; ++i)
		{
			root[i] = i;
		}

		int ecnt = 0;
		for (int i = 0; i < edges.size(); ++i)
		{
			int a, b, c;
			tie(c, a, b) = edges[i];
			if (find(a) == find(b)) continue;

			root[find(a)] = find(b);
			link[a].push_back({ b, c });
			link[b].push_back({ a, c });
			sum += c;

			if (++ecnt >= n - 1)
			{
				break;
			}
		}

		return sum;
	}

	void setBtwCost(int n, vector<pi> link[], int cost[][1001])
	{
		for (int i = 1; i <= n; ++i)
		{
			bool visited[1001] = {};
			queue<int> q;

			q.push({ i });
			cost[i][i] = 0;
			visited[i] = true;

			while (!q.empty())
			{
				int j = q.front(); q.pop();

				for (pi& p : link[j])
				{
					int k = p.first;
					int c = p.second;
					if (visited[k]) continue;

					cost[i][k] = max(cost[i][j], c);
					q.push(k);
					visited[k] = true;
				}
			}
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		vector<tp> edges; // c, a, b
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;
			edges.push_back({ c, a, b });
		}

		vector<pi> link[1001];
		int sum = makeMst(n, edges, link);

		int cost[1001][1001] = {};
		setBtwCost(n, link, cost);

		int q;
		cin >> q;
		while (q--)
		{
			int x, y;
			cin >> x >> y;
			cout << sum - cost[x][y] << "\n";
		}

		return 0;
	}
};