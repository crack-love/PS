// https://www.acmicpc.net/problem/14574

#include <bits/stdc++.h>
using namespace std;

struct p14574_prim
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		struct node
		{
			int p, c, i;
		};

		const int SIZE = (int)1e3;
		node nodes[SIZE];
		bool visited[SIZE] = {};
		vector<int> links[SIZE];
		list<node*> notVisited;
		priority_queue<tuple<int, int, int>> pq;

		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> nodes[i].p >> nodes[i].c;
			nodes[i].i = i;
			notVisited.push_back(&nodes[i]);
		}

		visited[0] = true;
		notVisited.erase(notVisited.begin());
		for (int i = 1; i < n; ++i)
		{
			int v = (nodes[0].c + nodes[i].c) / abs(nodes[0].p - nodes[i].p);
			pq.push({ v, 0, i });
		}

		long long answer = 0;
		while (!pq.empty())
		{
			int v, a, b;
			tie(v, a, b) = pq.top(); pq.pop();
			if (visited[a] && visited[b]) continue;
			if (visited[a]) swap(a, b); // a to not visited

			visited[a] = true;
			links[a].push_back(b);
			links[b].push_back(a);
			answer += v;

			list<node*>::iterator ait;
			for (auto it = notVisited.begin(); it != notVisited.end(); ++it)
			{
				node& node = **it;
				if (node.i == a) ait = it;
				if (visited[node.i]) continue;

				int v1 = (nodes[a].c + node.c) / abs(nodes[a].p - node.p);
				pq.push({ v1, a, node.i });
			}
			notVisited.erase(ait);
			if (notVisited.size() <= 0)
			{
				break;
			}
		}

		vector<pair<int, int>> dfs;
		vector<pair<int, int>> dfsTrace;
		dfs.push_back({ 0, 0 });
		while (!dfs.empty())
		{
			int x = dfs.back().first;
			int p = dfs.back().second;
			dfs.pop_back();

			dfsTrace.push_back({ p, x });

			for (int c : links[x])
			{
				if (c == p) continue;
				dfs.push_back({ c, x });
			}
		}

		cout << answer << "\n";
		for (int i = dfsTrace.size() - 1; i >= 1; --i)
		{
			cout << dfsTrace[i].first + 1 << " ";
			cout << dfsTrace[i].second + 1 << "\n";
		}

		return 0;
	}
};