// https://www.acmicpc.net/problem/11014
// platinum2

// 이분 그래프
// 이분 최대 매칭
// 최소 버텍스 커버
// 최대 독립 셋

#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <cassert>
using namespace std;

struct p11014
{
	const int dx[6] = { -1, -1, 0, 0, 1, 1 };
	const int dy[6] = { -1, 1, -1, 1, -1, 1 };

	char grid[80][81] = {};
	vector<int> edge[6400];
	bool visited[6400];
	int parent[6400];

	bool tryLink(int x)
	{
		visited[x] = true;

		for (int e : edge[x])
		{
			if (visited[e]) continue;

			int ep = parent[e];
			if (ep != -1)
			{
				if (visited[ep]) continue;

				visited[e] = true;
				if (!tryLink(ep))
				{
					visited[e] = false;
					continue;
				}
			}

			parent[e] = x;
			return true;
		}

		return false;
	}

	inline int serial(int x, int y)
	{
		assert(x * 80 + y < 6400);
		return x * 80 + y;
	}

	int main()
	{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		int c;
		cin >> c;
		while (c--)
		{
			int n, m; // [1 80]
			cin >> n >> m;
			for (int i = 0; i < n; ++i)
			{
				cin >> grid[i];
			}

			int space = 0;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < m; ++j)
				{
					int sidx = serial(i, j);
					edge[sidx].clear();

					if (grid[i][j] == 'x') continue;
					else space += 1;

					for (int k = 0; k < 6; ++k)
					{
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (grid[nx][ny] == 'x') continue;

						int nsidx = serial(nx, ny);
						edge[sidx].push_back(nsidx);
					}
				}
			}

			memset(parent, -1, sizeof parent);

			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < m; j += 2)
				{
					memset(visited, 0, sizeof visited);

					if (tryLink(serial(i, j)))
					{
						--space;
					}
				}
			}

			cout << space << "\n";
		}

		return 0;
	}
};