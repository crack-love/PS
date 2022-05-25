// https://www.acmicpc.net/problem/1760
// platinum3

#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_set>
using namespace std;

struct p1760
{
	unordered_set<int> edges[5001];
	bool visited[5001];
	int par[5001];

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
		int grid[100][100] = {};
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				// 0 empty, 1 hole, 2 wall
				cin >> grid[i][j];
			}
		}

		// set vertex
		int gidX[100][100] = {}; // 1~
		int gidY[100][100] = {};
		int nextRid = 1;
		int nextCid = 1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (grid[i][j] != 0) continue;

				if (gidX[i][j] == 0)
				{
					int nx = i;
					int ny = j;
					while (ny < m && gidX[nx][ny] == 0)
					{
						if (grid[nx][ny] == 2) break;
						gidX[nx][ny++] = nextRid;
					}
					nextRid += 1;
				}

				if (gidY[i][j] == 0)
				{
					int nx = i;
					int ny = j;
					while (nx < n && gidY[nx][ny] == 0)
					{
						if (grid[nx][ny] == 2) break;
						gidY[nx++][ny] = nextCid;
					}
					nextCid += 1;
				}
			}
		}

		// set edge
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (grid[i][j] != 0) continue;
				int r = gidX[i][j];
				int c = gidY[i][j];
				edges[r].insert(c);
			}
		}

		memset(par, -1, sizeof par);

		int answer = 0;
		for (int i = 1; i < nextRid; ++i)
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

int main()
{
	p1760().main();
}