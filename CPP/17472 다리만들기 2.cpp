// https://www.acmicpc.net/problem/17472

#include <bits/stdc++.h>
using namespace std;

struct p17472
{
	int n, m;
	int g[100][100];
	vector<tuple<int, int, int>> edge;
	vector<vector<pair<int, int>>> island;
	int par[100];
	const int dx[4] { 0, 0, 1, -1 };
	const int dy[4] { 1, -1, 0, 0 };

	int find(int x)
	{
		return par[x] == -1 ? x : (par[x] = find(par[x]));
	}

	void dfsisland(int x, int y, int num)
	{
		g[x][y] = num + 1;
		island[num].push_back({ x, y });

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (g[nx][ny] == -1)
				{
					dfsisland(nx, ny, num);
				}
			}
		}
	}

	void getedge(int num)
	{
		for (int i = 0; i < island[num].size(); ++i)
		{
			auto [x, y] = island[num][i];

			for (int j = 0; j < 4; ++j)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];
				int d = 1;
				while (nx >= 0 && nx < n && ny >= 0 && ny < m)
				{
					if (g[nx][ny] == 0)
					{
						nx += dx[j];
						ny += dy[j];
						d += 1;
						continue;
					}
					else if (g[nx][ny] == num)
					{
						break;
					}
					else if (g[nx][ny] != num)
					{
						if (d >= 3)
						{
							edge.push_back({ d - 1, num, g[nx][ny] - 1 });
						}
						break;
					}
				}
			}
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> g[i][j];
				if (g[i][j] == 1) g[i][j] = -1;
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (g[i][j] == -1)
				{
					island.push_back({});
					dfsisland(i, j, island.size() - 1);
				}
			}
		}

		for (int i = 0; i < island.size(); ++i)
		{
			getedge(i);
		}

		sort(edge.begin(), edge.end());
		memset(par, -1, sizeof(par));
		int answer = 0;
		int edgeCnt = 0;

		for (int i = 0; i < edge.size(); ++i)
		{
			auto [d, a, b] = edge[i];
			int pa = find(a);
			int pb = find(b);
			if (pa != pb)
			{
				par[pb] = pa;
				answer += d;
				if (++edgeCnt >= island.size() - 1)
				{
					break;
				}
			}
		}

		if (edgeCnt >= island.size() - 1)
		{
			cout << answer;
		}
		else
		{
			cout << "-1";
		}

		return 0;
	}
};