// https://www.acmicpc.net/problem/19236

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define endl "\n"
using namespace std;

struct p19236
{
	int gn[4][4];
	int gd[4][4];
	int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
	int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
	int ans = 0;
	void move(int x, int y, int sum)
	{
		int ogn[4][4];
		int ogd[4][4];
		copy(&gn[0][0], &gn[3][4], &ogn[0][0]);
		copy(&gd[0][0], &gd[3][4], &ogd[0][0]);

		// eat fish
		int num = gn[x][y];
		int dir = gd[x][y];
		gn[x][y] = 0;
		gd[x][y] = 0;
		sum += num;
		ans = max(sum, ans);

		// move fish
		for (int i = 1; i <= 16; ++i)
		{
			int fx = -1, fy = -1;
			for2(u, v, 4, 4)
			{
				if (gn[u][v] == i)
				{
					fx = u, fy = v;
					break;
				}
			}
			if (fx == -1) continue;

			int d = gd[fx][fy] - 1;
			for1(i, 8)
			{
				d = (d + 1) % 8;
				int nfx = fx + dx[d];
				int nfy = fy + dy[d];
				step(nfx, nfy, 4, 4);
				if (nfx == x && nfy == y) continue;
				gd[fx][fy] = d;
				swap(gn[nfx][nfy], gn[fx][fy]);
				swap(gd[nfx][nfy], gd[fx][fy]);
				break;
			}
		}

		// move shark
		int nx = x;
		int ny = y;
		while (true)
		{
			nx = nx + dx[dir];
			ny = ny + dy[dir];
			if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) break;
			if (gn[nx][ny] == 0) continue;
			move(nx, ny, sum);
		}

		copy(&ogn[0][0], &ogn[3][4], &gn[0][0]);
		copy(&ogd[0][0], &ogd[3][4], &gd[0][0]);
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		for2(i, j, 4, 4)
		{
			cin >> gn[i][j] >> gd[i][j];
			gd[i][j] -= 1;
		}

		move(0, 0, 0);
		cout << ans;

		return 0;
	}
};