// https://www.acmicpc.net/problem/9525
// platinum3

#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_set>
using namespace std;

struct p9525
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
		char grid[100][101] = {};
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> grid[i];
		}

		// set vertex
		int rid[100][100] = {}; // 1~
		int cid[100][100] = {};
		int nextRid = 1;
		int nextCid = 1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (grid[i][j] == 'X') continue;

				if (rid[i][j] == 0)
				{
					int nx = i, ny = j;
					while (ny < n && rid[nx][ny] == 0 &&
						grid[nx][ny] != 'X')
					{
						rid[nx][ny++] = nextRid;
					}
					nextRid += 1;
				}
				if (cid[i][j] == 0)
				{
					int nx = i, ny = j;
					while (nx < n && cid[nx][ny] == 0 &&
						grid[nx][ny] != 'X')
					{
						cid[nx++][ny] = nextCid;
					}
					nextCid += 1;
				}
			}
		}

		// set edge
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (grid[i][j] == 'X') continue;

				int r = rid[i][j];
				int c = cid[i][j];
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