// https://www.acmicpc.net/problem/2887

#include <bits/stdc++.h>
using namespace std;

struct p2887
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		// kruskal
		// 각각 xyz 정렬된 3개의 배열

		typedef pair<int, int> pi;
		const int SIZE = (int)1e5;

		// get input
		pi arr[3][SIZE];
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				int v;
				cin >> v;
				arr[j][i] = { i, v };
			}
		}

		// sort
		for (int j = 0; j < 3; ++j)
		{
			sort(&arr[j][0], &arr[j][n], [](pi& a, pi& b) { return a.second < b.second; });
		}

		// get edge
		vector<pi> edges[SIZE];
		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				int oi = arr[j][i].first;
				int noi = arr[j][i + 1].first;
				int dist = abs(arr[j][i].second - arr[j][i + 1].second);

				edges[oi].push_back({ dist, noi });
				edges[noi].push_back({ dist, oi });
			}
		}

		priority_queue<pi, vector<pi>, greater<pi>> q;
		int visited[SIZE] = {};
		visited[0] = true;
		int visitCnt = 1;
		for (int i = 0; i < edges[0].size(); ++i)
		{
			q.push(edges[0][i]);
		}

		long long answer = 0;
		while (!q.empty())
		{
			int d = q.top().first;
			int i = q.top().second; q.pop();
			if (visited[i]) continue;

			answer += d;
			visited[i] = true;
			visitCnt += 1;
			if (visitCnt == n)
			{
				break;
			}

			for (int j = 0; j < edges[i].size(); ++j)
			{
				q.push(edges[i][j]);
			}
		}

		cout << answer;
		return 0;
	}
};