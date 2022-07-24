// https://www.acmicpc.net/problem/13460

#include <iostream>
using namespace std;

struct p13460
{
	int n, m;
	char map[10][11];
	int rx, ry, bx, by;
	const int dx[4] = { 0, 1, 0, -1 };
	const int dy[4] = { 1, 0, -1, 0 };
	int answer = 11;

	bool shiftOne(int& x, int& y, int dx, int dy)
	{
		char src = map[x][y];
		map[x][y] = '.';

		while (true)
		{
			x += dx;
			y += dy;

			if (map[x][y] == 'O')
			{
				x -= dx;
				y -= dy;
				return true;
			}
			else if (map[x][y] != '.')
			{
				x -= dx;
				y -= dy;
				map[x][y] = src;
				return false;
			}
		}
	}

	void shiftAll(int cnt, int lastDir)
	{
		if (cnt >= answer)
		{
			return;
		}

		for (int i = 0; i < 4; ++i)
		{
			if (lastDir != -1)
			{
				if (i == lastDir) continue;
				if (i == (lastDir + 2) % 4) continue;
			}

			int obx = bx;
			int oby = by;
			int orx = rx;
			int ory = ry;
			bool bgoal = false;
			bool rgoal = false;

			bgoal |= shiftOne(bx, by, dx[i], dy[i]);
			rgoal |= shiftOne(rx, ry, dx[i], dy[i]);
			bgoal |= shiftOne(bx, by, dx[i], dy[i]);

			if (!bgoal && !rgoal)
			{
				if (bx == obx && by == oby && rx == orx && ry == ory)
				{
					continue;
				}

				shiftAll(cnt + 1, i);
			}

			map[rx][ry] = '.';
			map[bx][by] = '.';
			map[obx][oby] = 'B';
			map[orx][ory] = 'R';
			rx = orx;
			ry = ory;
			bx = obx;
			by = oby;

			if (rgoal && !bgoal)
			{
				if (cnt + 1 < answer)
				{
					answer = cnt + 1;
				}

				break;
			}
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			cin >> map[i];
			for (int j = 0; j < m; ++j)
			{
				if (map[i][j] == 'R')
				{
					rx = i;
					ry = j;
				}
				else if (map[i][j] == 'B')
				{
					bx = i;
					by = j;
				}
			}
		}

		shiftAll(0, -1);
		cout << (answer == 11 ? -1 : answer);

		return 0;
	}
};