// https://www.acmicpc.net/problem/14503

#include <bits/stdc++.h>
using namespace std;

struct p14503
{
	const int dx[4] = { -1, 0, 1, 0 };
	const int dy[4] = { 0, 1, 0, -1 };

	int n, m;
	int g[50][50];
	int answer = 0;

	void movenext(int x, int y, int dir)
	{
		if (g[x][y] == 0)
		{
			g[x][y] = 2;
			answer += 1;
		}

		for (int i = 1; i <= 4; ++i)
		{
			int nd = (dir + 4 - i) % 4;
			int nx = x + dx[nd];
			int ny = y + dy[nd];
			if (nx < 0 || ny < 0 || nx >= n - 1 || ny >= m - 1) continue;
			if (g[nx][ny] > 0) continue;

			movenext(nx, ny, nd);
			return;
		}

		int bx = x - dx[dir];
		int by = y - dy[dir];
		if (bx < 0 || by < 0 || bx >= n - 1 || by >= m - 1) return;
		if (g[bx][by] == 1) return;
		movenext(bx, by, dir);
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		cin >> n >> m;
		int x, y, dir;
		cin >> x >> y >> dir;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> g[i][j];
			}
		}

		movenext(x, y, dir);
		cout << answer;
		return 0;
	}
};