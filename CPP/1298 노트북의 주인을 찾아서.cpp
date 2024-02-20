// https://www.acmicpc.net/problem/1298
// platinum5

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int p1298()
{
	vector<int> edges[101];

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
	}

	int linkFrom[5001]; // notebook to people
	bool visited[101];

	auto link = [&linkFrom, &edges, &visited](int x, auto& link) -> bool
	{
		if (visited[x]) return false;
		visited[x] = true;

		for (int e : edges[x])
		{
			if (linkFrom[e] == -1 || link(linkFrom[e], link))
			{
				linkFrom[e] = x;
				return true;
			}
		}
		return false;
	};

	int answer = 0;
	memset(linkFrom, -1, sizeof(linkFrom));
	for (int i = 1; i <= n; ++i)
	{
		memset(visited, 0, sizeof(visited));

		if (link(i, link))
		{
			++answer;
		}
	}
	cout << answer << "\n";
	return 0;
}