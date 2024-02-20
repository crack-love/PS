// https://www.acmicpc.net/problem/16236

#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

struct p16236
{
	int n;
	int map[20][20];

	tuple<int, int, int> getNextPrey(int sx, int sy, int ssize)
	{
		const int dx[] = { 0, 0, 1, -1 };
		const int dy[] = { 1, -1, 0, 0 };
		int visit[20][20] = {};
		queue<tuple<int, int, int>> q;
		q.push({ sx, sy, 0 });
		visit[sx][sy] = 1;

		while (q.size() > 0)
		{
			int x, y, d;
			tie(x, y, d) = q.front(); q.pop();

			if (0 < map[x][y] && map[x][y] < ssize)
			{
				vector<pair<int, int>> preys;
				preys.push_back({ x, y });

				while (q.size() > 0)
				{
					int nx, ny, nd;
					tie(nx, ny, nd) = q.front(); q.pop();
					if (nd > d) break;
					if (0 < map[nx][ny] && map[nx][ny] < ssize)
					{
						preys.push_back({ nx, ny });
					}
				}

				sort(preys.begin(), preys.end());

				return { preys[0].first, preys[0].second, d };
			}

			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (map[nx][ny] > ssize) continue;
				if (visit[nx][ny]) continue;

				q.push({ nx, ny, d + 1 });
				visit[nx][ny] = 1;
			}
		}

		return { -1, -1, -1 };
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int sx = 0, sy = 0;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> map[i][j];
				if (map[i][j] == 9)
				{
					sx = i;
					sy = j;
					map[i][j] = 0;
				}
			}
		}

		int size = 2;
		int preyNeed = 2;
		int duration = 0;
		while (true)
		{
			int px, py, pd;
			tie(px, py, pd) = getNextPrey(sx, sy, size);
			if (px == -1)
			{
				break;
			}

			--preyNeed;
			if (preyNeed == 0)
			{
				size += 1;
				preyNeed = size;
			}
			sx = px;
			sy = py;
			map[px][py] = 0;
			duration += pd;
		}

		cout << duration;
		return 0;
	}
};