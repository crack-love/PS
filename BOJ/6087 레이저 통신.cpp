// https://www.acmicpc.net/problem/6087

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

struct p6087
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		char map[100][101];
		int w, h;
		cin >> w >> h;
		for (int i = 0; i < h; ++i)
		{
			cin >> map[i];
		}

		pair<int, int> beg, end;
		int beCnt = 0;
		for (int i = 0; i < h; ++i)
		{
			if (beCnt >= 2) break;

			for (int j = 0; j < w; ++j)
			{
				if (beCnt >= 2) break;

				if (map[i][j] == 'C')
				{
					if (beCnt++ == 0)
					{
						beg = { i, j };
					}
					else
					{
						end = { i, j };
					}
				}
			}
		}

		int cost[100][100][4];
		fill(&cost[0][0][0], &cost[h - 1][w - 1][4], -1);
		priority_queue<tuple<int, int, int, int>> q; // cost, x, y, dir
		for (int i = 0; i < 4; ++i)
		{
			q.push({ 0, beg.first, beg.second, i });
			cost[beg.first][beg.second][i] = 0;
		}

		const int dx[] = { 0, 1, 0, -1 };
		const int dy[] = { 1, 0, -1, 0 };
		while (!q.empty())
		{
			int x, y, c, dir;
			tie(c, x, y, dir) = q.top(); q.pop();
			c *= -1;
			if (cost[x][y][dir] != c) continue;

			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nc = c + (i != dir ? 1 : 0);
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (map[nx][ny] == '*') continue;

				if (cost[nx][ny][i] == -1 || nc < cost[nx][ny][i])
				{
					cost[nx][ny][i] = nc;
					q.push({ -nc, nx, ny, i });
				}
			}
		}

		int ans = 1e9;
		for (int i = 0; i < 4; ++i)
		{
			int c = cost[end.first][end.second][i];
			if (c != -1 && c < ans) ans = c;
		}
		cout << ans;

		return 0;
	}
};