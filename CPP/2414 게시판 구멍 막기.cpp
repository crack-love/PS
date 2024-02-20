// https://www.acmicpc.net/problem/2414
// platinum3

#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_set>
#include <cassert>
using namespace std;

// 이분 매칭 = 최소 버텍스 커버

struct p2414
{
	unordered_set<int> edge[1260]; // r to c
	bool visited[1260];
	int parent[1260];

	bool tryLink(int x)
	{
		visited[x] = true;

		for (int e : edge[x])
		{
			int p = parent[e];
			if (p == -1 || (!visited[p] && tryLink(p)))
			{
				parent[e] = x;
				return true;
			}
		}
		return false;
	}

	int main()
	{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		// get input
		char grid[50][51] = {};
		int n, m; // [1 50]
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			cin >> grid[i];
		}

		// set vertex
		int gridR[50][50] = {};
		int gridC[50][50] = {};
		int nextR = 1;
		int nextC = 1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (grid[i][j] != '*') continue;

				if (gridR[i][j] == 0)
				{
					int nx = i;
					int ny = j;
					while (ny < m && grid[nx][ny] == '*')
					{
						gridR[nx][ny++] = nextR;
					}
					nextR += 1;
				}

				if (gridC[i][j] == 0)
				{
					int nx = i;
					int ny = j;
					while (nx < n && grid[nx][ny] == '*')
					{
						gridC[nx++][ny] = nextC;
					}
					nextC += 1;
				}
			}
		}

		// set edge
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				int r = gridR[i][j];
				int c = gridC[i][j];
				if (r != 0)
				{
					assert(c != 0);
					edge[r].insert(c);
				}
			}
		}

		// biparite matching
		int answer = 0;
		memset(parent, -1, sizeof parent);
		for (int i = 1; i < nextR; ++i)
		{
			memset(visited, false, sizeof visited);

			if (tryLink(i))
			{
				++answer;
			}
		}

		cout << answer;
		return 0;
	}
};