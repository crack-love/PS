// https://www.acmicpc.net/problem/1574
// platinum4

#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

struct p1574
{
	unordered_set<int> edges[301];
	bool visited[301];
	int par[301];

	bool tryLink(int x)
	{
		visited[x] = true;

		for (int e : edges[x])
		{
			int p = par[e];
			if (p == -1 || (!visited[p] && tryLink(p)))
			{
				par[e] = x;
				return true;
			}
		}
		return false;
	}

	int main()
	{
		int grid[301][301] = {};
		int r, c, n;
		cin >> r >> c >> n;
		for (int i = 0; i < n; ++i)
		{
			int x, y;
			cin >> x >> y;
			grid[x][y] = 1; // empty cell
		}

		// ser edge
		for (int i = 1; i <= r; ++i)
		{
			for (int j = 1; j <= c; ++j)
			{
				if (grid[i][j] == 1) continue;
				edges[i].insert(j);
			}
		}

		memset(par, -1, sizeof par);

		int answer = 0;
		for (int i = 1; i <= r; ++i)
		{
			memset(visited, 0, sizeof visited);

			if (tryLink(i))
			{
				++answer;
			}
		}

		cout << answer;
		return 0;
	}
};