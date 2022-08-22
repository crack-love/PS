// https://www.acmicpc.net/problem/17143

#include <bits/stdc++.h>
using namespace std;

struct p17143
{
	const int dx[4] = { -1, 1, 0, 0 };
	const int dy[4] = { 0, 0, 1, -1 };

	struct shark
	{
		int x, y, s, d, z, alive;
	};
	vector<shark> sharks;
	int grid[100][100];
	int R, C, M;
	int answer = 0;

	void moveMan(int col)
	{
		for (int i = 0; i < R; ++i)
		{
			if (grid[i][col])
			{
				shark& s = sharks[grid[i][col]];
				answer += s.z;
				s.alive = 0;
				grid[i][col] = 0;
				break;
			}
		}
	}

	void moveSharks()
	{
		int tgrid[100][100] = {};

		for (int i = 1; i < sharks.size(); ++i)
		{
			shark& s = sharks[i];
			if (!s.alive) continue;

			// switch direction!
			int nx = s.x;
			int ny = s.y;
			int ddx = dx[s.d];
			int ddy = dy[s.d];
			int ss = s.s;
			if (ddx == 1 || ddx == -1)
			{
				int loop = ss / ((R - 1) * 2);
				ss -= loop * (R - 1) * 2;
			}
			else if (ddy == 1 || ddy == -1)
			{
				int loop = ss / ((C - 1) * 2);
				ss -= loop * (C - 1) * 2;
			}

			while (ss > 0)
			{
				if ((nx <= 0 && ddx < 0) || (nx >= R - 1 && ddx > 0))
				{
					ddx *= -1;
				}
				else if ((ny <= 0 && ddy < 0) || (ny >= C - 1 && ddy > 0))
				{
					ddy *= -1;
				}
				nx += ddx;
				ny += ddy;
				ss -= 1;
			}

			if (ddx == 1 || ddx == -1)
			{
				s.d = ddx == -1 ? 0 : 1;
			}
			else
			{
				s.d = ddy == -1 ? 3 : 2;
			}

			if (tgrid[nx][ny])
			{
				if (sharks[tgrid[nx][ny]].z < s.z)
				{
					// kill
					sharks[tgrid[nx][ny]].alive = 0;
				}
				else
				{
					// die
					s.alive = 0;
					continue;
				}
			}
			tgrid[nx][ny] = i;
			s.x = nx;
			s.y = ny;
		}

		copy(&tgrid[0][0], &tgrid[R - 1][C], &grid[0][0]);
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		cin >> R >> C >> M;
		sharks.push_back({});
		for (int i = 1; i <= M; ++i)
		{
			int x, y, s, d, z;
			cin >> x >> y >> s >> d >> z;
			x -= 1; y -= 1; d -= 1;
			sharks.push_back({ x, y, s, d, z, 1 });
			grid[x][y] = i;
		}

		for (int i = 0; i < C; ++i)
		{
			moveMan(i);
			moveSharks();
		}
		cout << answer;
		return 0;
	}
};